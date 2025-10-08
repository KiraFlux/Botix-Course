// Границы на левым датчике
int minL = 0, maxL = 1023;

// Границы на правом датчике
int minR = 0, maxR = 1023;

// Границы нормированного значения
int minNorm = 100, maxNorm = 900;

// Функции чтения значения АЦП с датчиков линии

int readL() {
    return analogRead(A1);
}

int readR() {
    return analogRead(A2);
}

// Функции чтения нормированных значений датчиков линии

int lineL() {
    return map(readL(), minL, maxL, minNorm, maxNorm);
}

int lineR() {
    return map(readR(), minR, maxR, minNorm, maxNorm);
}

void setup() {
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);

    Serial.begin(9600);
}

void loop() {
    Serial.print("L: ");
    Serial.print(readL());
    Serial.print('\t');
    Serial.print(lineL());
    Serial.print("\tR: ");
    Serial.print(readR());
    Serial.print('\t');
    Serial.println(lineR());

    delay(50);
}
