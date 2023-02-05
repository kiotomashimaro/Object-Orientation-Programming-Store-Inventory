// collection.cpp
#include "collection.hpp"

Collection::Collection() {}

void Collection::setNewItem(const Product& newProduct) {
  inventory[currentPos] = newProduct;
  currentPos++;
}

Product* Collection::getMyItem(const std::string& bcode) {
  for (size_t i = 0; i < currentPos; i++) {
    if (bcode == inventory[i].getBarcode()) {
      itemPtr = &inventory[i];
      return itemPtr;
    }
  }
  printf("%s", "El elemento no existe");
  itemPtr = &inventory[-1];
  return itemPtr;
}

void Collection::setCurrentPos(const int& newPos) { currentPos = newPos; }

int Collection::getCurrentPos() const { return currentPos; }

std::string Collection::toString() const {
  std::string temp;
  for (size_t i = 0; i < currentPos; i++) {
    temp += inventory[i].toString();
    temp += "\n";
  }
  return temp;
}
