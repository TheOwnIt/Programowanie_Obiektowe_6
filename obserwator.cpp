#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Observer {
public:
virtual void update(string name, double value) = 0;
};

class Currency {
private:
  string name;
  double value;
  vector<class Observer*> observers;
public:
  Currency(string name, double value) {
    this->name = name;
    this->value = value;
  }
  void attach(Observer* observer) {
    observers.push_back(observer);
  }
  void detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
  }
  void notify() {
    for (auto observer : observers) {
      observer->update(name, value);
    }
  }
  void setValue(double value) {
    this->value = value;
    notify();
  }
};



class CurrencyTracker : public Observer {
private:
string name;
public:
CurrencyTracker(string name) {
this->name = name;
}
void update(string name, double value) {
if (name == this->name) {
cout << "Currency " << name << " has changed to " << value << endl;
}
}
};

int main() {
Currency USD("USD", 1.0);
Currency EUR("EUR", 0.9);

CurrencyTracker USDTracker("USD");
CurrencyTracker EURTracker("EUR");

USD.attach(&USDTracker);
EUR.attach(&EURTracker);

USD.setValue(1.1);
EUR.setValue(0.8);

return 0;
}
