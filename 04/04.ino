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

void fastStop() {
	for (int i = 0, s = 255; i < 30; ++i, s = -s) {
		setMotors(s, s);
		delay(5);
	} setMotors(0, 0);
}

void loop() {
	setMotors(255, 255);
	delay(1000);

	fastStop();
	exit(0);
}
