#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

// Klasa Icon reprezentuj�ca ikon�
class Icon {
public:
  // Metoda rysuj�ca ikon�
  virtual void draw() = 0;
};

// Klasa ForestIcon reprezentuj�ca ikon� lasu, dziedzicz�ca po klasie Icon
class ForestIcon : public Icon {
public:
  void draw() {
    cout << "Rysowanie ikony lasu." << endl;
  }
};

// Klasa LakeIcon reprezentuj�ca ikon� jeziora, dziedzicz�ca po klasie Icon
class LakeIcon : public Icon {
public:
  void draw() {
    cout << "Rysowanie ikony jeziora." << endl;
  }
};

// Klasa IconFactory odpowiedzialna za utrzymanie i tworzenie obiekt�w ikon
class IconFactory {
private:
  // mapa przechowuj�ca ju� istniej�ce ikony
  unordered_map<string, Icon*> icons;
public:
  // Metoda zwracaj�ca ikon� o podanej nazwie
  Icon* getIcon(string name) {
    // je�li ikona o podanej nazwie nie istnieje, tworzymy now�
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

