# Firmware — Simulador de electrodo de pH (ESP32)

Sketch: [`simulador_ph_esp32/simulador_ph_esp32.ino`](simulador_ph_esp32/simulador_ph_esp32.ino)

## Modelo implementado

```
E(pH) = E0 - 0.05916 · (pH - 7)          Ecuación de Nernst a 25 °C (E0 = 0 V)
Vout  = 1.65 V + K · E(pH)               K = 4 (factor de escala para el osciloscopio)
DAC   = round(Vout / 3.3 · 255)          DAC1 de 8 bits en GPIO25
```

> El offset de 1.65 V y el factor K = 4 existen solo para mantener la señal dentro del rango 0–3.3 V del DAC. Un electrodo real produce ≈ 0 V a pH 7 y ≈ ±59 mV por unidad de pH.

## Carga y uso

1. Arduino IDE 2.x + paquete **esp32 by Espressif Systems** (versión 2.x o 3.x).
2. Placa: `ESP32 Dev Module` · Puerto: el COM/ttyUSB del ESP32.
3. Subir el sketch y abrir el **Monitor Serial** a **115200 baudios** con fin de línea **“Nueva línea”**.
4. Escribir el pH (`4`, `7`, `10` o decimales como `7.4`) y presionar Enter.

Salida típica:

```
pH ingresado = 4.00  ->  Voltaje entregado (GPIO25) = 2.3599 V   (valor DAC = 182)
pH ingresado = 7.00  ->  Voltaje entregado (GPIO25) = 1.6500 V   (valor DAC = 128)
pH ingresado = 10.00 ->  Voltaje entregado (GPIO25) = 0.9401 V   (valor DAC = 73)
```

| pH | V programado | DAC (0–255) | Sensibilidad simulada |
|:--:|:--:|:--:|:--:|
| 4 | 2.360 V | 182 | −236.6 mV/pH |
| 7 | 1.650 V | 128 | (4 × 59.16 mV/pH) |
| 10 | 0.940 V | 73 | |

Entradas fuera de 0–14 o no numéricas se rechazan sin modificar el DAC.
