// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_
class Train {
private:
    struct Car {
        bool light;     // состояние лампочки
        Car* next;
        Car* prev;
        Car(bool lightState) : light(lightState), next(nullptr), prev(nullptr) {}
    };
    int countOp;        // счетчик шагов (число переходов из вагона в вагон)
    Car* first;         // точка входа в поезд (первый вагон)
    int length;
public:
    Train();
    ~Train();
    void addCar(bool light);    // добавить вагон с начальным состоянием лампочки
    int getLength();             // вычислить длину поезда (алгоритм решения задачи)
    int getOpCount();            // вернуть число переходов
    void resetOpCount();         // сбросить счетчик операций
    int getTrainLength();        // получить реальную длину поезда (для проверки)
};
#endif  // INCLUDE_TRAIN_H_
