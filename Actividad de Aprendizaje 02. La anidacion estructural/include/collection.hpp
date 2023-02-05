// collection.hpp
#ifndef __COLLECTION_H__
#define __COLLECTION_H__

#include "product.hpp"

class Collection {
 private:
  Product inventory[500];
  int currentPos = 0;
  Product* itemPtr;

 public:
  Collection();

  void setNewItem(const Product&);
  Product* getMyItem(const std::string&);

  void setCurrentPos(const int&);
  int getCurrentPos() const;

  std::string toString() const;
};

#endif  // __COLLECTION_H__