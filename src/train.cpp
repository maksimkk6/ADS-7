// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

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
    Car* newCar = new Car{light, nullptr, nullptr};
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
}

int Train::getOpCount() const {
    return countOp;
}

int Train::getLength() {
    if (!first) return 0;
    Car* current = first;
    current->light = false;
    countOp = 0;
    int steps = 0;
    while (true) {
        current = current->next;
        countOp++;
        steps++;
        if (!current->light) {
            break;
        }
    }
    while (steps > 0) {
        current = current->prev;
        countOp++;
        steps--;
        current->light = true;
    }
    int length = 1;
    current = first->next;
    countOp++;
    while (current->light) {
        length++;
        current = current->next;
        countOp++;
    }
    return length;
}
