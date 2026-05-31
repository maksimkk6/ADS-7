// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "train.h"

int main() {
  std::srand(time(nullptr));

  std::cout << "n\tfalse\t\ttrue\t\trandom\n";

  for (int wagonCount = 2; wagonCount <= 100; wagonCount++) {
    int operationsFalse;
    int operationsTrue;
    int operationsRandom;

    {
      Train train;

      for (int i = 0; i < wagonCount; i++)
        train.addCar(false);

      train.getLength();
      operationsFalse = train.getOpCount();
    }

    {
      Train train;

      for (int i = 0; i < wagonCount; i++)
        train.addCar(true);

      train.getLength();
      operationsTrue = train.getOpCount();
    }

    {
      Train train;

      for (int i = 0; i < wagonCount; i++)
        train.addCar(std::rand() % 2);

      train.getLength();
      operationsRandom = train.getOpCount();
    }

    std::cout << wagonCount << "\t" << operationsFalse << "\t\t" 
              << operationsTrue << "\t\t" << operationsRandom << "\n";
  }

  return 0;
}
