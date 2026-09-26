# Datos experimentales

| Archivo | Contenido |
|---|---|
| `tabla1_gpio25_teorico.csv` | Etapa 1: voltaje programado por el firmware, valor DAC (8 bits) y voltaje verificado en GPIO25. |
| `tabla2_nodoA_sin_buffer.csv` | Etapa 2: voltaje en el Nodo A (tras R1 = 1 MΩ) medido con multímetro y con osciloscopio. |
| `tabla3_nodoB_con_buffer.csv` | Etapa 3: voltaje en el Nodo B (salida del seguidor) con TL084 y con LM324, medido con multímetro. |
| `lecturas_osciloscopio_nodoB.csv` | Lecturas complementarias (Mean) del osciloscopio en el Nodo B. |
| `resultados_errores.csv` | Generado por `analysis/calculo_errores.py`: errores porcentuales de cada etapa. |

Unidades: voltios (V). Temperatura ambiente de laboratorio. Referencia: GND común de la fuente dual y del ESP32.
