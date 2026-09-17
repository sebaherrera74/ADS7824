# Mediciones 01 — ADS7824

## Condiciones de prueba

ADC: ADS7824P  
Microcontrolador: Arduino Mega 2560  
Velocidad serie: 115200 baudios

## Referencia

REF medida: 2.45 V

CAP medida: 2.485 V

Capacitores utilizados:

- REF: 2.2 µF tantalio
- CAP: 2.2 µF tantalio

## Medición 1 — AIN0 conectado a GND

Lectura ADC:

- aproximadamente -22
- lectura muy estable

Con corrección de offset:

- OFFSET = -26
- código corregido ≈ 4
- tensión calculada ≈ 0.020 V

## Medición 2 — AIN0 = 2.594 V

Tensión medida con multímetro:

2.594 V

Lectura ADC:

aproximadamente 499–500

Lectura corregida:

aproximadamente 525–526

Tensión calculada:

aproximadamente 2.563–2.568 V

## Medición 3 — AIN0 = 4.98 V

Tensión medida con multímetro:

4.98 V

Lectura ADC:

aproximadamente 973–976

Lectura corregida:

aproximadamente 997–1002

Tensión calculada:

aproximadamente 4.868–4.893 V

## Observaciones

Las mediciones muestran una diferencia entre la tensión aplicada
medida con multímetro y la tensión calculada a partir del ADC.

Se requiere continuar verificando alimentación, referencias y masas
del ADS7824 para determinar el origen de la diferencia.