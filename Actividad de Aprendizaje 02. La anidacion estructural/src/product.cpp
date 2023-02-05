// product.cpp
#include "product.hpp"

Product::Product() {
  barcode = "";
  name = "";
  weight = 0.0;
  wholesalePrice = 0.0;
  retailPrice = 0.0;
  currentExistence = 0;
}

Product::Product(const std::string& bcode, const std::string& n, const float& w,
                 const Date& date, const float& wp, const float& rp,
                 const int& ce)
    : barcode(bcode),
      name(n),
      weight(w),
      entryDate(date),
      wholesalePrice(wp),
      retailPrice(rp),
      currentExistence(ce) {}

void Product::setBarcode(const std::string& bcode) { barcode = bcode; }

std::string Product::getBarcode() const { return barcode; }

void Product::setName(const std::string& n) { name = n; }

std::string Product::getName() const { return name; }

void Product::setEntryDate(const Date& d) { entryDate = d; }

Date Product::getEntryDate() const { return entryDate; }

void Product::setWeight(const float& w) { weight = w; }

float Product::getWeight() const { return weight; }

void Product::setWholesalePrice(const float& wp) { wholesalePrice = wp; }

float Product::getWholesalePrice() const { return wholesalePrice; }

void Product::setRetailPrice(const float& rp) { retailPrice = rp; }

float Product::getRetailPrice() const { return retailPrice; }

void Product::setCurrentExistence(const int& ce) { currentExistence = ce; }

int Product::getCurrentExistence() const { return currentExistence; }

void Product::addProduct(const int& add) { currentExistence += add; }

bool Product::removeProduct(const int& rem) {
  if (rem > currentExistence) {
    return true;
  } else {
    currentExistence -= rem;
    return false;
  }
}

std::string Product::toString() const {
  std::string temp;
  char output[50];
  temp += " | ";
  temp += barcode;
  temp += " | ";
  temp += name;
  temp.resize(30, ' ');
  temp += " | ";
  sprintf(output, "%.2f", weight);
  temp += output;
  temp += "Gr";
  temp += " | ";
  temp += entryDate.toString();
  temp += " | ";
  sprintf(output, "%.2f", wholesalePrice);
  temp += "$";
  temp += output;
  temp += " | ";
  sprintf(output, "%.2f", retailPrice);
  temp += "$";
  temp += output;
  temp += " | ";
  sprintf(output, "%d", currentExistence);
  temp += output;
  temp += " | ";
  return temp;
}

Product& Product::operator=(const Product& other) {
  this->barcode = other.barcode;
  this->name = other.name;
  this->weight = other.weight;
  this->entryDate = other.entryDate;
  this->wholesalePrice = other.wholesalePrice;
  this->retailPrice = other.retailPrice;
  this->currentExistence = other.currentExistence;

  return *this;
}
