#define RC_PIN    30
#define BYTE_PIN  31

// Offset medido con AIN0 conectado a GND
const int OFFSET = -26;

void setup() {
  Serial.begin(115200);

  // ADS7824 D0..D7 -> Mega D22..D29
  for (int pin = 22; pin <= 29; pin++) {
    pinMode(pin, INPUT);
  }

  pinMode(RC_PIN, OUTPUT);
  pinMode(BYTE_PIN, OUTPUT);

  digitalWrite(RC_PIN, HIGH);
  digitalWrite(BYTE_PIN, LOW);

  delay(100);
}

void loop() {

  // =========================
  // INICIAR CONVERSION
  // =========================

  digitalWrite(BYTE_PIN, LOW);

  digitalWrite(RC_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(RC_PIN, HIGH);

  // Conversión ADS7824
  delayMicroseconds(30);

  // =========================
  // BYTE LOW
  // =========================

  digitalWrite(BYTE_PIN, LOW);
  delayMicroseconds(2);

  byte highByte = PINA;

  // =========================
  // BYTE HIGH
  // =========================

  digitalWrite(BYTE_PIN, HIGH);
  delayMicroseconds(2);

  byte lowByte = PINA;

  // =========================
  // RECONSTRUIR 12 BITS
  // =========================

  int codigo = ((int)highByte << 4) |
               ((lowByte >> 4) & 0x0F);

  int16_t signedCode = codigo;

  if (signedCode & 0x800) {
    signedCode -= 4096;
  }

  // =========================
  // CORREGIR OFFSET
  // =========================

  int codigoCorregido = signedCode - OFFSET;

  // Evitar valores negativos residuales
  if (codigoCorregido < 0) {
    codigoCorregido = 0;
  }

  // =========================
  // VOLTAJE
  // =========================

  float voltaje = (codigoCorregido * 10.0) / 2048.0;

  // =========================
  // MOSTRAR
  // =========================

  Serial.print("ADC = ");
  Serial.print(signedCode);

  Serial.print("   CORREGIDO = ");
  Serial.print(codigoCorregido);

  Serial.print("   VOLTAJE = ");
  Serial.print(voltaje, 3);

  Serial.println(" V");

  delay(100);
}
