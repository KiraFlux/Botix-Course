void setMotors(int L, int R) {
	digitalWrite(4, L < 0);
	digitalWrite(7, R < 0);
	analogWrite(5, constrain(abs(L), 0, 255));
	analogWrite(6, constrain(abs(R), 0, 255));
}

void setup() {
    // Установка пинов драйвера моторов как ВЫХОД
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

	// Тест моторов

	delay(1000);

    // 1. Проверка левого мотора

    // Включаем левый мотор вперёд..
    setMotors(255, 0);
    delay(2000);

    // Включаем левый мотор назад..
    setMotors(-255, 0);
    delay(2000);

    // Выключаем левый мотор
    setMotors(0, 0);

    // 2. Пауза между тестированиями

    delay(2000)

    // 3. Проверка правого мотора

    // Включаем правый мотор вперёд..
    setMotors(255, 0);
    delay(2000);

    // Включаем правый мотор назад..
    setMotors(-255, 0);
    delay(2000);

    // Выключаем правый мотор
    setMotors(0, 0);
}

void loop() {}
