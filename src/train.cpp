// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool islight) {
    Car* newCar = new Car{islight, nullptr, nullptr};

    if (!first) {
        first = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
    } else {
        Car* lastCar = first->prev;
        newCar->next = first;
        newCar->prev = lastCar;
        first->prev = newCar;
        lastCar->next = newCar;
        first = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;
    if (first->next == first) return 1;

    countOp = 0;
    Car* curCar = first;
    int carAmount = 1;

    if (!curCar->islight) {
        curCar->islight = true;
    }

    curCar = curCar->next;
    countOp += 2;

    while (!curCar->islight) {
        curCar = curCar->next;
        countOp += 2;
        carAmount++;
    }
    curCar->islight = false;

    if (!first->islight) {
        return carAmount;
    }

    while (true) {
        curCar = first;
        carAmount = 1;

        if (!curCar->islight) {
            curCar->islight = true;
        }

        curCar = curCar->next;
        countOp += 2;

        while (!curCar->islight) {
            curCar = curCar->next;
            countOp += 2;
            carAmount++;
        }

        curCar->islight = false;

        if (!first->islight) {
            return carAmount;
        }
    }
}

int Train::getOpCount() {
        return countOp;
}

Train::~Train() {
    if (!first) return;
    if (first->next == first) {
      delete first;
      first = nullptr;
      return;
    }
    Car* curCar = first->next;
    while (curCar != first) {
      Car* tmp = curCar;
      curCar = curCar->next;
      delete tmp;
    }
    delete first;
    first = nullptr;
}
