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

void loop() {
  Serial.print(readL());
  Serial.print(" ");
  Serial.println(readR());

  delay(10);
}
