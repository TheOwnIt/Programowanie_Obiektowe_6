#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

// Klasa Icon reprezentuj¹ca ikonê
class Icon {
public:
  // Metoda rysuj¹ca ikonê
  virtual void draw() = 0;
};

// Klasa ForestIcon reprezentuj¹ca ikonê lasu, dziedzicz¹ca po klasie Icon
class ForestIcon : public Icon {
public:
  void draw() {
    cout << "Rysowanie ikony lasu." << endl;
  }
};

// Klasa LakeIcon reprezentuj¹ca ikonê jeziora, dziedzicz¹ca po klasie Icon
class LakeIcon : public Icon {
public:
  void draw() {
    cout << "Rysowanie ikony jeziora." << endl;
  }
};

// Klasa IconFactory odpowiedzialna za utrzymanie i tworzenie obiektów ikon
class IconFactory {
private:
  // mapa przechowuj¹ca ju¿ istniej¹ce ikony
  unordered_map<string, Icon*> icons;
public:
  // Metoda zwracaj¹ca ikonê o podanej nazwie
  Icon* getIcon(string name) {
    // jeœli ikona o podanej nazwie nie istnieje, tworzymy now¹
    if (icons.find(name) == icons.end()) {
      if (name == "forest")
        icons[name] = new ForestIcon();
      else if (name == "lake")
        icons[name] = new LakeIcon();
    }
    return icons[name];
  }
};

int main() {
  IconFactory factory;
  Icon* forest = factory.getIcon("forest");
  forest->draw();
  Icon* lake = factory.getIcon("lake");
  lake->draw();
  return 0;
}

