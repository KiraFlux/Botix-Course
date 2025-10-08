// Функции чтения значения АЦП с датчиков линии

int readL() {
    return analogRead(A1);
}

int readR() {
    return analogRead(A2);
}

void setup() {
    // Инициализируем пины датчиков линии как ВХОД
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);

    // Запускаем последовательный порт (9600 - стандартный baud rate)
    Serial.begin(9600);
}

void loop() {
    // Выводим в порт значения чтения с датчиков линии

    Serial.print(readL());
    Serial.print('\t'); // Табуляция для выравнивания
    Serial.println(readR());

    delay(50); // Для умеренной скорости вывода значений
}
