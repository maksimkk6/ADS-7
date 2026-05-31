// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : entryPoint(nullptr), stepCount(0) {}

int Train::getOpCount() { return stepCount; }

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;

    if (entryPoint == nullptr) {
        entryPoint = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
        return;
    }

    Car* lastCar = entryPoint->prev;
    newCar->next = entryPoint;
    newCar->prev = lastCar;

    lastCar->next = newCar;
    entryPoint->prev = newCar;
}

int Train::getLength() {
    Car* currentCar = entryPoint;
    currentCar->light = true;

    while (true) {
        int forwardSteps = 0;

        do {
            currentCar = currentCar->next;
            stepCount++;
            forwardSteps++;
        } while (!currentCar->light);

        currentCar->light = false;

        for (int i = 0; i < forwardSteps; i++) {
            currentCar = currentCar->prev;
            stepCount++;
        }

        if (!currentCar->light) {
            return forwardSteps;
        }
    }
}
