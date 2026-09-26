/*
  Simulador de electrodo de pH con ESP32 (DAC interno, GPIO25)

  Requisitos cumplidos:
  - Lee un valor de pH (0-14) desde el Monitor Serial.
  - Calcula el voltaje con la ecuación de Nernst, con un factor de escala (K)
    que hace visible la variación en el osciloscopio (~236.6 mV por unidad de pH).
  - Limita el voltaje al rango válido del DAC (0-3.3 V).
  - Entrega el voltaje en GPIO25 mediante el DAC interno de 8 bits.
  - Muestra en el Monitor Serial el pH ingresado y el voltaje entregado.

  Modelo usado:
    E(pH)  = E0 - 0.05916 * (pH - 7)      [Ecuación de Nernst, E0 = 0 V de referencia]
    Vout   = Vcentro + K * E(pH)          [Vcentro = 1.65 V, K = 4 -> ganancia de escala]
    Vout se satura entre 0 y 3.3 V antes de escribirse en el DAC.

  Con estos valores:
    pH  4 -> ~2.36 V
    pH  7 -> ~1.65 V
    pH 10 -> ~0.94 V
*/

const int DAC_PIN = 25;          // GPIO25 = canal DAC1 del ESP32
const float VREF = 3.3;          // Rango máximo del DAC del ESP32
const float VCENTRO = VREF / 2;  // 1.65 V, punto medio (equivalente a pH 7)
const float PENDIENTE_NERNST = 0.05916; // V/unidad de pH a 25 °C
const float E0 = 0.0;            // Offset de referencia del electrodo simulado
const float K = 4.0;             // Factor de escala para hacer visible la señal

void setup() {
  Serial.begin(115200);
  delay(300);
  pinMode(DAC_PIN, ANALOG); // No estrictamente necesario, pero explícito
  Serial.println();
  Serial.println(F("=== Simulador de electrodo de pH (ESP32 DAC - GPIO25) ==="));
  Serial.println(F("Ingrese un valor de pH entre 0 y 14 y presione Enter:"));
}

float calcularVoltaje(float pH) {
  float E = E0 - PENDIENTE_NERNST * (pH - 7.0);
  float vOut = VCENTRO + K * E;
  if (vOut < 0.0) vOut = 0.0;
  if (vOut > VREF) vOut = VREF;
  return vOut;
}

void loop() {
  if (Serial.available() > 0) {
    String entrada = Serial.readStringUntil('\n');
    entrada.trim();

    if (entrada.length() == 0) return;

    float pH = entrada.toFloat();

    // toFloat() devuelve 0.0 si no puede convertir; validamos también el texto "0"
    bool esNumero = (entrada == "0") || (pH != 0.0);
    if (!esNumero) {
      Serial.println(F(">> Entrada inválida. Ingrese un número entre 0 y 14."));
      return;
    }

    if (pH < 0.0 || pH > 14.0) {
      Serial.println(F(">> Fuera de rango. El pH debe estar entre 0 y 14."));
      return;
    }

    float vOut = calcularVoltaje(pH);
    int dacValor = (int)round((vOut / VREF) * 255.0);
    dacValor = constrain(dacValor, 0, 255);

    dacWrite(DAC_PIN, dacValor);

    Serial.print(F("pH ingresado = "));
    Serial.print(pH, 2);
    Serial.print(F("  ->  Voltaje entregado (GPIO25) = "));
    Serial.print(vOut, 4);
    Serial.print(F(" V   (valor DAC = "));
    Serial.print(dacValor);
    Serial.println(F(")"));
  }
}