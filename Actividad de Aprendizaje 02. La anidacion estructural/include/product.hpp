// product.hpp
#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include "date.hpp"

class Product {
 private:
  std::string barcode;
  std::string name;
  float weight;
  Date entryDate;
  float wholesalePrice;
  float retailPrice;
  int currentExistence;

 public:
  Product();
  Product(const std::string&, const std::string&, const float&, const Date&,
          const float&, const float&, const int&);

  void setBarcode(const std::string&);
  std::string getBarcode() const;

  void setName(const std::string&);
  std::string getName() const;

  void setEntryDate(const Date&);
  Date getEntryDate() const;

  void setWeight(const float&);
  float getWeight() const;

  void setWholesalePrice(const float&);
  float getWholesalePrice() const;

  void setRetailPrice(const float&);
  float getRetailPrice() const;

  void setCurrentExistence(const int&);
  int getCurrentExistence() const;

  void addProduct(const int&);
  bool removeProduct(const int&);
  std::string toString() const;

  Product& operator=(const Product&);
};

#endif  // __PRODUCT_H__