void setMotors(int L, int R) {
	digitalWrite(4, L < 0);
	digitalWrite(7, R < 0);
	analogWrite(5, constrain(abs(L), 0, 255));
	analogWrite(6, constrain(abs(R), 0, 255));
}

// Функция торможения (duration - длительность торможения в мс)
void fastStop(int duration = 400) {
	// 1. Рассчитываем время окончания торможения
	auto end = millis() + duration;

	// 2. Определим переменную для чередования скорость-направления
	int s = 255;

	// 3. Пока не наступил момент окончания торможения:
	while (millis() < end) {

	    // 4. Устанавливаем моторы в одном направлении
		setMotors(s, s);

		// 5. Ожидаем малый период (обычно от 1 до 10 мс)
		delay(5);

		// 6. Меняем направление моторов сменой знака скорости
		s = -s;
	}

    // 7. Выключаем моторы - торможение завершено.
	setMotors(0, 0);
}

void setup() {
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

    // Тест торможения

    // 1. Полный вперёд! (на 1 секунду)
	setMotors(255, 255);
	delay(1000);

    // 2. Исполняем торможение
	fastStop();
}

void loop() {}
