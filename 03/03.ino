void setMotors(int L, int R) {
	digitalWrite(4, L < 0);
	digitalWrite(7, R < 0);
	analogWrite(5, constrain(abs(L), 0, 255));
	analogWrite(6, constrain(abs(R), 0, 255));
}

// Функция прямолинейного движения по таймеру
void goTime(long t, int speed = 255) {
    // 1. Устанавливаем одинаковые скорости моторов
	setMotors(speed, speed);

	// 2. Ожидаем t миллисекунд (Моторы в этой время вращаются и перемещают робота)
	delay(t);

	// 3. Останавливаем моторы - движение окончено.
	setMotors(0, 0);
}

// Аналогично - повороты

void turnLTime(long t, int speed = 255) {
	// Левый мотор имеет направление противоположное правому - это будет танковый разворот
	setMotors(-speed, speed);
	delay(t);
	setMotors(0, 0);
}

void turnRTime(long t, int speed = 255) {
	setMotors(speed, -speed);
	delay(t);
	setMotors(0, 0);
}

void setup() {
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

	delay(2000);

	goTime(1000);

	turnLTime(500);

	turnRTime(500, 120);

	goTime(1000, -120);
}

void loop() {}
