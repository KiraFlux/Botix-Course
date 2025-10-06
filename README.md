# Botix-курс

Курс по работе с мобильным роботом [Botix](https://github.com/KiraFlux/Botix) для интенсива 548 школы в Видном

---

# План курса:

## Моторы

1 Работа с моторами. Функция `setMotors(int L, int R)`
2 Проверка моторов. Скетч `checkMotors`
3 Движение по времени. Функции `goTime(long t)`, `turnLTime(long t)`, `turnRTime(long t)`
4 Резкая остановка. Функция `fastStop()`

## Датчики линии

5 Чтение датчиков линии. Функции `readL()`, `readR()`
6 Нормирование. Функции `lineL()`, `lineR()`

## Движение по линии

7 Пропорциональный регулятор движения по линии. Функция `goLine(int speed, float kP)`. Подбор коэффициента kP
8 Движение по линии до перекрёстка. Функция `goLineNCross(int n, int speed, float kP)`
9 Повороты на перекрёстке по линии. Функции `turnL(int n)`, `turnR(int n)`
10 Движение по линии по времени. Функция `goLineTime(long t, int speed, float kP)`

## Зачётное задание на движение по линии П-регулятором и работу с датчиком линии

11 Использование штрих-кода при построении маршрута
12 Использование штрих-кода, кодирующего положение объекта. *(Вытолкнуть объект и вернуться на исходную)*

## Более сложные регуляторы

13 ПД-регулятор. Сложные траектории (Поле ЮИ). Функция `goLine(int speed, float kP, float kD)`
14 Движение до n-го перекрёстка по ПД-регулятору
15 Прохождение маршрута *(на примере поля "ОЦПМ. Путь")*

## Датчик расстояния (ИК)

16 Чтение ИК-датчика расстояния. *Вывод в Serial-монитор.* Функция `dist()`
17 Движение вдоль стены на расстоянии d по ИК-датчику *(П-регулятор)*. Функция `goWall(int d, int speed, float kP)`
18 Движение между двух стен по линии. Функция `goLineToWall(int d, int speed, float kP)`

## Энкодеры

19 Подключение энкодеров. Модификатор `volatile`. ISR. Обработка прерываний. *Вывод значений в Serial-port.* Функции `resetEnc()`, `printEnc()`
20 Движение прямо по энкодерам *(П-регулятор)*. Функция `goEnc(int speed, float kP)`
21 Движение прямо на n тиков. Функция `goEncTick(long n, int speed, float kP)`
22 Движение прямо на n сантиметров. Функция `goEncCM(long n, int speed, float kP)`
23 Поворот на n тиков. Функция `turnEncTick(long n, int speed, float kT)`
24 Поворот на n градусов. Функция `turnEncDegree(float n, int speed, float kT)`
25 Маршруты по энкодерам

## Комплексные задания

26 Автоматическая калибровка *(поворот по энкодерам)*
27 Поле Заключительного этапа 2025. Проезд вокруг поля по линии и энкодерам

---

## Набор функций по итогу сборов:

```cpp
// Управление моторами через ШИМ
void setMotors(int L, int R);

// Движение по таймеру
void goTime(long t);
void turnLTime(long t);
void turnRTime(long t);

// быстрая остановка
void fastStop();

// Чтение значений АЦП с аналоговых датчиков линий
int readL();
int readR();

// Чтение нормированных значений датчиков линии
int lineL();
int lineR();

// Движение по линии
void goLine(int speed, float kP, float kD); 
void goLine(int speed, float kP); 
void goLineNCross(int n, int speed, float kP);
void turnL(int n);
void turnR(int n);
void goLineTime(long t, int speed, float kP);

// Чтение Инфракрасного датчика расстояния
int dist();
void goWall(int d, int speed, float kP); 
void goLineToWall(int d, int speed, float kP); 

// Работа с энкодерами
void printEnc();
void resetEnc();
void goEnc(int speed, float kP);
void goEncTick(long n, int speed, float kP);
void goEncCM(long n, int speed, float kP);
void turnEncTick(long n, int speed, float kT);
void turnEncDegree(float n, int speed, float kT);
```