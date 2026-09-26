# Galería de evidencia experimental

Fotografías del montaje y de las mediciones, ordenadas por etapa. [Volver al README](../README.md)


## Montaje general

<p align="center"><img src="img/montaje/montaje_general_vertical.jpg" width="70%"><br><sub><b>Figura 1.</b> Vista general del montaje con R1 = 1 MΩ intercalada a la salida de GPIO25 del ESP32.</sub></p>

<p align="center"><img src="img/montaje/montaje_tl084.jpg" width="70%"><br><sub><b>Figura 2.</b> Montaje de la Etapa 3 con el TL084 como seguidor, fuente dual ±9 V y capacitores de desacoplo.</sub></p>

<p align="center"><img src="img/montaje/medicion_lm324.jpg" width="70%"><br><sub><b>Figura 3.</b> Medición en el Nodo B usando el LM324 como buffer seguidor.</sub></p>


## Etapa 1 — Señal directa en GPIO25

<p align="center"><img src="img/etapa1/monitor_serial.jpg" width="70%"><br><sub><b>Figura 4.</b> Monitor Serial: pH 4.00, 7.00 y 10.00 con valores DAC 182, 128 y 73.</sub></p>

<p align="center"><img src="img/etapa1/entorno_esp32_usb.jpg" width="70%"><br><sub><b>Figura 5.</b> Entorno de trabajo: ESP32 alimentado por USB, listo para medir GPIO25.</sub></p>

<p align="center"><img src="img/etapa1/gpio25_ph4_multimetro.jpg" width="70%"><br><sub><b>Figura 6.</b> GPIO25, pH 4: 2.29 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa1/gpio25_ph4_osciloscopio.jpg" width="70%"><br><sub><b>Figura 7.</b> GPIO25, pH 4 (osciloscopio).</sub></p>

<p align="center"><img src="img/etapa1/gpio25_ph7_multimetro.jpg" width="70%"><br><sub><b>Figura 8.</b> GPIO25, pH 7: 1.64 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa1/gpio25_ph7_osciloscopio.jpg" width="70%"><br><sub><b>Figura 9.</b> GPIO25, pH 7 (osciloscopio).</sub></p>

<p align="center"><img src="img/etapa1/gpio25_ph10_multimetro.jpg" width="70%"><br><sub><b>Figura 10.</b> GPIO25, pH 10: 0.97 V (multímetro).</sub></p>


## Etapa 2 — Nodo A sin buffer

<p align="center"><img src="img/etapa2/montaje_R1_1M.jpg" width="70%"><br><sub><b>Figura 11.</b> R1 = 1 MΩ en serie con GPIO25 para simular la impedancia del electrodo.</sub></p>

<p align="center"><img src="img/etapa2/nodoA_ph4_multimetro.jpg" width="70%"><br><sub><b>Figura 12.</b> Nodo A, pH 4: 1.17 V (multímetro) — atenuación por carga.</sub></p>

<p align="center"><img src="img/etapa2/nodoA_ph4_osciloscopio.jpg" width="70%"><br><sub><b>Figura 13.</b> Nodo A, pH 4: Mean = 1.06 V (osciloscopio).</sub></p>

<p align="center"><img src="img/etapa2/nodoA_ph7_multimetro.jpg" width="70%"><br><sub><b>Figura 14.</b> Nodo A, pH 7: 0.79 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa2/nodoA_ph7_osciloscopio.jpg" width="70%"><br><sub><b>Figura 15.</b> Nodo A, pH 7: Mean = 0.72 V (osciloscopio).</sub></p>

<p align="center"><img src="img/etapa2/nodoA_ph10_multimetro.jpg" width="70%"><br><sub><b>Figura 16.</b> Nodo A, pH 10: 0.47 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa2/nodoA_ph10_osciloscopio.jpg" width="70%"><br><sub><b>Figura 17.</b> Nodo A, pH 10 (osciloscopio).</sub></p>


## Etapa 3a — Nodo B con TL084 (JFET)

<p align="center"><img src="img/etapa3_tl084/montaje_tl084.jpg" width="70%"><br><sub><b>Figura 18.</b> TL084 en configuración seguidor de voltaje.</sub></p>

<p align="center"><img src="img/etapa3_tl084/nodoB_ph4_multimetro.jpg" width="70%"><br><sub><b>Figura 19.</b> Nodo B, pH 4: 2.31 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa3_tl084/nodoB_ph4_osciloscopio.jpg" width="70%"><br><sub><b>Figura 20.</b> Nodo B, pH 4: Mean = 2.28 V (osciloscopio).</sub></p>

<p align="center"><img src="img/etapa3_tl084/nodoB_ph7_multimetro.jpg" width="70%"><br><sub><b>Figura 21.</b> Nodo B, pH 7: 1.65 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa3_tl084/nodoB_ph7_osciloscopio.jpg" width="70%"><br><sub><b>Figura 22.</b> Nodo B, pH 7: Mean = 1.64 V (osciloscopio).</sub></p>

<p align="center"><img src="img/etapa3_tl084/nodoB_ph10_multimetro.jpg" width="70%"><br><sub><b>Figura 23.</b> Nodo B, pH 10: 0.99 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa3_tl084/nodoB_ph10_osciloscopio.jpg" width="70%"><br><sub><b>Figura 24.</b> Nodo B, pH 10: Mean = 960 mV (osciloscopio).</sub></p>


## Etapa 3b — Nodo B con LM324 (bipolar)

<p align="center"><img src="img/etapa3_lm324/montaje_lm324.jpg" width="70%"><br><sub><b>Figura 25.</b> LM324 sustituyendo al TL084 en el mismo seguidor.</sub></p>

<p align="center"><img src="img/etapa3_lm324/nodoB_ph4_multimetro.jpg" width="70%"><br><sub><b>Figura 26.</b> Nodo B, pH 4: 2.319 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa3_lm324/nodoB_ph4_osciloscopio.jpg" width="70%"><br><sub><b>Figura 27.</b> Nodo B, pH 4: Mean = 2.20 V (osciloscopio).</sub></p>

<p align="center"><img src="img/etapa3_lm324/nodoB_ph7_multimetro.jpg" width="70%"><br><sub><b>Figura 28.</b> Nodo B, pH 7: 1.665 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa3_lm324/nodoB_ph7_osciloscopio.jpg" width="70%"><br><sub><b>Figura 29.</b> Nodo B, pH 7: Mean = 1.42 V (osciloscopio).</sub></p>

<p align="center"><img src="img/etapa3_lm324/nodoB_ph10_multimetro.jpg" width="70%"><br><sub><b>Figura 30.</b> Nodo B, pH 10: 0.994 V (multímetro).</sub></p>

<p align="center"><img src="img/etapa3_lm324/nodoB_ph10_osciloscopio.jpg" width="70%"><br><sub><b>Figura 31.</b> Nodo B, pH 10: Mean = 920 mV (osciloscopio).</sub></p>


## Análisis complementario

<p align="center"><img src="img/resultados/punta_1x_vs_10x.png" width="70%"><br><sub><b>Figura 32.</b> Efecto de carga de la punta 1X vs. 10X sobre un nodo de 1 MΩ: respuesta al escalón y Bode.</sub></p>
