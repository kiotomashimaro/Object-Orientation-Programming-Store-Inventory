// main.cpp
#include "collection.hpp"
#include "date.hpp"
#include "menu.hpp"
#include "product.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  Collection myInventory;
  Menu mainMenu(myInventory);

  mainMenu.execute();
}