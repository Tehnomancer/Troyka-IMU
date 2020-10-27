// Библиотека для работы с модулями IMU
#include <TroykaIMU.h>

// Создаём объект для работы с магнитометром/компасом
Compass compass;

// Калибровочные значения, полученные в калибровочной матрице
// из примера compassCalibration
const float compassCalibrationBias[3] = { 567.893, -825.35, 1061.436 };

const float compassCalibrationMatrix[3][3] = { { 1.909, 0.082, 0.004 },
                                               { 0.049, 1.942, -0.235 },
                                               { -0.003, 0.008, 1.944} };

void setup() {
    // Открываем последовательный порт
    Serial.begin(9600);
    // Выводим сообщение о начале инициализации
    Serial.println("Compass begin");
    // Инициализируем компас
    compass.begin();
    // Устанавливаем калибровочные данные
    compass.setCalibrateMatrix(compassCalibrationMatrix,
                               compassCalibrationBias);
    // Выводим сообщение об удачной инициализации
    Serial.println("Initialization completed");
}

void loop() {
    // Выводим азимут относительно оси Z
    Serial.print(compass.readAzimut());
    Serial.println(" Degrees");
    delay(100);
}
