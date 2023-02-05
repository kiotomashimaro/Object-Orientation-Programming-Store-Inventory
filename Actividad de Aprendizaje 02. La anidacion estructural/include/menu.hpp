// menu.hpp
#ifndef __MENU_H__
#define __MENU_H__
#include "collection.hpp"

class Menu {
 private:
  Collection* inventoryPtr;

 public:
  Menu();
  Menu(Collection);

  void setInventoryPtr(Collection*);
  Collection* getInventoryPtr() const;

  void execute() const;
  void addNewItem() const;
  void addAmountItem() const;
  void removeAmountItem() const;
  void showInventory() const;
  bool exit() const;
};

#endif  // __MENU_H__