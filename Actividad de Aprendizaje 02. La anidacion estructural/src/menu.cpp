// menu.hpp
#include "menu.hpp"

using namespace std;

Menu::Menu() {}

Menu::Menu(Collection recivePtr) { inventoryPtr = &recivePtr; }

void Menu::setInventoryPtr(Collection* recivePtr) { inventoryPtr = recivePtr; }

Collection* Menu::getInventoryPtr() const { return inventoryPtr; }

void Menu::execute() const {
  bool flag = true;
  do {
    int option;
    cout << "---MENU PRINCIPAL---\n" << endl;
    cout << "[1]Agregar producto al inventario\n"
         << "[2]Agregar cantidad de un producto\n"
         << "[3]Eliminar cantidad de un producto\n"
         << "[4]Mostrar Inventario\n"
         << "[5]Salir\n";
    cout << "Elige una opcion: ";
    cin >> option;
    cin.ignore();
    system("cls");
    switch (option) {
      case 1:
        cout << "---NUEVO PRODUCTO---\n";
        this->addNewItem();
        system("cls");
        break;
      case 2:
        cout << "---AGREGAR PRODUCTO---\n";
        this->addAmountItem();
        system("cls");
        break;
      case 3:
        cout << "---REMOVER PRODUCTO---\n";
        this->removeAmountItem();
        system("cls");
        break;
      case 4:
        cout << "---INVENTARIO---\n";
        this->showInventory();
        system("cls");
        break;
      case 5:
        flag = this->exit();
        system("cls");
        break;
      default:
        break;
    }
  } while (flag);
}

void Menu::addNewItem() const {
  string barcode;
  string name;
  float weight, wholesalePrice, retailPrice;
  int d, m, y, currentExistence;
  char option = 's';
  do {
    cout << "Introduce el codigo de barras: " << endl;
    getline(cin, barcode);
    cout << "Introduce el nombre del producto: " << endl;
    getline(cin, name);
    cout << "Introduce el peso en Gr del producto: " << endl;
    cin >> weight;
    cout << "Introduce el dia: " << endl;
    cin >> d;
    cout << "Introduce el mes: " << endl;
    cin >> m;
    cout << "Introduce el anio: " << endl;
    cin >> y;
    cout << "Introduce el precio a mayoreo del producto: " << endl;
    cin >> wholesalePrice;
    cout << "Introduce el precio a menudeo del producto: " << endl;
    cin >> retailPrice;
    cout << "Introduce la existencia acutal del producto: " << endl;
    cin >> currentExistence;
    Date newDate(d, m, y);
    Product newProduct(barcode, name, weight, newDate, wholesalePrice,
                       retailPrice, currentExistence);
    inventoryPtr->setNewItem(newProduct);
    cout << "Desea ingrsar otro articulo? [s/n]: " << endl;
    cin >> option;
    cin.ignore();

  } while (option == 's');
}

void Menu::addAmountItem() const {
  int quantity = 0;
  string barcode;
  cout << "Ingresa el codigo de barras: " << endl;
  getline(cin, barcode);
  cout << "Ingresa la cantidad para agregar: " << endl;
  cin >> quantity;
  inventoryPtr->getMyItem(barcode)->addProduct(quantity);
}

void Menu::removeAmountItem() const {
  int quantity = 0;
  bool succes;
  string barcode;
  cout << "Ingresa el codigo de barras: " << endl;
  getline(cin, barcode);
  cout << "Ingresa la cantidad para retirar: " << endl;
  cin >> quantity;
  succes = inventoryPtr->getMyItem(barcode)->removeProduct(quantity);
  if (succes) {
    cout << "La cantidad excede que hay en existencia" << endl;
  }
  system("pause");
}

void Menu::showInventory() const {
  string top;
  top =
      " | Codigo | Nombre | Peso | Fecha | Mayoreo | Menudeo | Existencia | \n";
  cout << top << endl;
  cout << inventoryPtr->toString();
  system("pause");
}

bool Menu::exit() const { return false; }
