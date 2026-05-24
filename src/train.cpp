// Copyright 2021 NNTU-CS
#include "train.h"
#include <cstdlib>
Train::Train() : countOp(0), first(nullptr), length(0) {}
Train::~Train() {
    if (!first) return;    
    Car* current = first;
    Car* nextCar = nullptr;
    do {
        nextCar = current->next;
        delete current;
        current = nextCar;
    } while (current != first);
}
void Train::addCar(bool light) {
    Car* newCar = new Car(light);
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
    length++;
}
int Train::getLength() {
    if (!first) return 0;
    Car* current = first;
    countOp = 0;
    current->light = true;
    int steps = 0;
    bool found = false;
    while (!found) {
        current = current->next;
        countOp++;
        steps++;
        if (!current->light) {
            current->light = true;
            for (int i = 0; i < steps; i++) {
                current = current->prev;
                countOp++;
            }
            current->light = false;
            steps = 0;
        } 
        else {
            Car* temp = current;
            bool allLightOn = true;
            
            for (int i = 0; i < steps; i++) {
                temp = temp->prev;
                countOp++;
                if (!temp->light) {
                    allLightOn = false;
                    break;
                }
            }
            if (allLightOn && steps > 0) {
                found = true;
                return steps;
            }
            steps = 0;
        }
    }
    return 0;
}
int Train::getOpCount() {
    return countOp;
}
void Train::resetOpCount() {
    countOp = 0;
}
int Train::getTrainLength() {
    return length;
}
