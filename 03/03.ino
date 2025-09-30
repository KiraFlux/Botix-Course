void setup() {
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
}

void setMotors(int L, int R) {
	L = constrain(L, -255, 255);
	R = constrain(R, -255, 255);

	digitalWrite(4, L < 0);
	analogWrite(5, abs(L));
	analogWrite(6, abs(R));
	digitalWrite(7, R < 0);
}

void goTime(long t) {
	long start = millis();

	while (millis() - start <= t)
		setMotors(255, 255);

	setMotors(0, 0);
}

void turnLTime(long t) {
	long start = millis();

	while (millis() - start <= t) 
		setMotors(-255, 255);

	setMotors(0, 0);
}

void turnRTime(long t) {
	long start = millis();

	while (millis() - start <= t)
		setMotors(255, -255);

	setMotors(0, 0);
}

void loop() {
	goTime(1000);
	turnLTime(500);
	turnRTime(500);
	goTime(1000);
	exit(0);
}
