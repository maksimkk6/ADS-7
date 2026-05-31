// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "train.h"

int main() {
  std::srand(time(nullptr));
  std::cout << "n\tfalse\t\ttrue\t\trndom\n";
  for (int count = 2; count <= 100; count++) {
    int emptyResult;
    int fullResult;
    int mixedResult;
    {
      Train train;
      for (int idx = 0; idx < count; idx++)
        train.addCar(false);
      train.getLength();
      emptyResult = train.getOpCount();
    }
    {
      Train train;
      for (int idx = 0; idx < count; idx++)
        train.addCar(true);
      train.getLength();
      fullResult = train.getOpCount();
    }
    {
      Train train;
      for (int idx = 0; idx < count; idx++)
        train.addCar(std::rand() % 2);
      train.getLength();
      mixedResult = train.getOpCount();
    }
    std::cout << count << "\t" << emptyResult << "\t\t" << fullResult
              << "\t\t" << mixedResult << "\n";
  }
  return 0;
}
