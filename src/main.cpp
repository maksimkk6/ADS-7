// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "train.h"

int main() {
    std::srand(time(nullptr));
    std::cout << "n\toff\t\ton\t\trnd\n";
    for (int n = 2; n <= 100; n++) {
        int opOff, opOn, opRnd;
        {
            Train train;
            for (int i = 0; i < n; i++)
                train.addCar(false);
            train.getLength();
            opOff = train.getOpCount();
        }
        {
            Train train;
            for (int i = 0; i < n; i++)
                train.addCar(true);
            train.getLength();
            opOn = train.getOpCount();
        }
        {
            Train train;
            for (int i = 0; i < n; i++)
                train.addCar(std::rand() % 2);
            train.getLength();
            opRnd = train.getOpCount();
        }
        std::cout << n << "\t" << opOff << "\t\t" << opOn << "\t\t" << opRnd << "\n";
    }
    return 0;
}
