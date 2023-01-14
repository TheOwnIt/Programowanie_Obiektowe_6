#include <iostream>
#include <string>
using namespace std;

// Klasa Car reprezentuj¹ca samochód
class Car {
private:
  string brand;   // marka samochodu
  string model;   // model samochodu
  string color;   // kolor samochodu
  int horsepower; // moc silnika

public:
  class Builder;

  // Konstruktor przyjmuj¹cy parametry marki, modelu, koloru i mocy silnika
  Car(string brand, string model, string color, int horsepower) :
    brand(brand), model(model), color(color), horsepower(horsepower) {}

  // Funkcja wyœwietlaj¹ca dane o samochodzie
  void show() {
    cout << "Brand: " << brand << endl
         << "Model: " << model << endl
         << "Color: " << color << endl
         << "Horsepower: " << horsepower << endl;
  }
};

// Klasa Builder dziedzicz¹ca po klasie Car
class Car::Builder {
private:
  string brand;
  string model;
  string color;
  int horsepower;

public:
  Builder() {}

  // Metoda ustawiaj¹ca markê samochodu
Builder& setBrand(string brand) {
	this->brand = brand;
	return *this;
}

// Metoda ustawiaj¹ca model samochodu
Builder& setModel(string model) {
	this->model = model;
	return *this;
}

// Metoda ustawiaj¹ca kolor samochodu
Builder& setColor(string color) {
	this->color = color;
	return *this;
}

// Metoda ustawiaj¹ca moc silnika
Builder& setHorsepower(int horsepower) {
	this->horsepower = horsepower;
	return *this;
}

// Metoda tworz¹ca obiekt klasy Car na podstawie ustawionych parametrów
Car build() {
	return Car(brand, model, color, horsepower);
}
};

int main() {
	Car car = Car::Builder()
	.setBrand("Mercedes")
	.setModel("Benz")
	.setColor("Black")
	.setHorsepower(300)
	.build();

	car.show();
	return 0;
}


