void setup() {
    // Установка пинов драйвера моторов как ВЫХОД
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
}

void setMotors(int L, int R) {
	// 1. Сначала устанавливаем направления (Определяем по знаку скорости)
	digitalWrite(4, L < 0);
	digitalWrite(7, R < 0);

	// 2. Берём модуль (абсолютное значение) скоростей (ШИМ)
	L = abs(L);
	R = abs(R);

	// 3. Ограничиваем значения ШИМ
	L = constrain(L, 0, 255);
	R = constrain(R, 0, 255);

    // 4. Подаём ШИМ на пины драйвера для установки скорости моторов
	analogWrite(5, L);
	analogWrite(6, R);
}

void loop() {}
