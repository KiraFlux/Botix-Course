void setup() {
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  Serial.begin(9600);
}

int readL() {
  return analogRead(A1);
}

int readR() {
  return analogRead(A2);
}

int minL, maxL, minR, maxR, minM = 100, maxM = 900;

int lineL() {
  return map(readL(), minL, maxL, minM, maxM);
}

int lineR() {
  return map(readR(), minR, maxR, minM, maxM);
}

void loop() {
  Serial.print(readL());
  Serial.print(" ");
  Serial.print(lineL());
  Serial.print(" ");
  Serial.print(readR());
  Serial.print(" ");
  Serial.println(lineR());

  delay(10);
}
