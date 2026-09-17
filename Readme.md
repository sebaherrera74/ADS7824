# ADS7824 con Arduino Mega

Prueba experimental de un conversor analógico-digital ADS7824 utilizando
un Arduino Mega 2560 mediante su interfaz de datos paralela.

## Objetivo

Probar la adquisición de señales analógicas mediante el ADS7824 y
verificar su comunicación con un Arduino Mega 2560.

El experimento busca evaluar:

- Lectura de los 12 bits del ADC.
- Comunicación mediante la interfaz paralela.
- Inicio de conversión mediante la señal R/C.
- Lectura de los datos mediante la señal BYTE.
- Estabilidad de la conversión.
- Comportamiento del ADC frente a diferentes tensiones de entrada.
- Offset y escala de la conversión.

## Hardware

### ADC

- Conversor: ADS7824
- Resolución: 12 bits
- Canales analógicos: 4
- Arquitectura: SAR
- Interfaz utilizada: paralela
- Rango de entrada utilizado en esta prueba: positivo
- Alimentación: aproximadamente 5 V

El ADS7824 es un ADC SAR de 12 bits y cuatro canales multiplexados.
El dispositivo admite interfaz paralela y un rango de entrada de hasta
±10 V. El fabricante especifica una alimentación de 4,75 V a 5,25 V.
  
Referencia:
https://www.ti.com/product/ADS7824

## Microcontrolador

- Placa: Arduino Mega 2560
- Microcontrolador: ATmega2560
- Comunicación con el ADC: bus paralelo de 8 bits

## Conexiones digitales

El bus de datos del ADS7824 se conecta al puerto A del ATmega2560:

| ADS7824 | Arduino Mega |
|---------|--------------|
| D0      | D22          |
| D1      | D23          |
| D2      | D24          |
| D3      | D25          |
| D4      | D26          |
| D5      | D27          |
| D6      | D28          |
| D7      | D29          |
| R/C     | D30          |
| BYTE    | D31          |

Los pines D22 a D29 corresponden al PORTA del ATmega2560, permitiendo
leer los ocho bits simultáneamente mediante el registro PINA.

## Software

El programa utilizado en la primera prueba se encuentra en:

```text
codigo/
└── ADS7824/
    └── ADS7824.ino