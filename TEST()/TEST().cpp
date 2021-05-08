#include <iostream>
using namespace std;

//------------- Абстрактные продукты ---------------
struct Soup { //абстрактный продукт 
    virtual void eat() = 0;
};

struct Dinner { //абстрактный продукт
    virtual void eat() = 0;
};


struct Diet { // абстрактный продукт
    virtual void eat() = 0;
};

//------------- Конкретные продукты-----------------

struct Borsch : Soup {
    virtual void eat()
    {
        cout << "Borsch cook" << endl;
    }
};

struct Pumpkin : Soup {
    virtual void eat()
    {
        cout << "Pumpkin cook" << endl;
    }
};

struct Fried_potato : Dinner {
    virtual void eat()
    {
        cout << "Fried_potato cook" << endl;
    }
};

struct Cutlet : Dinner {
    virtual void eat()
    {
        cout << "Cutlet cook" << endl;
    }
};

//  наследники
struct MeatDiet : Diet {
    virtual void eat()
    {
        cout << "MeatDiet cook" << endl;
    }
};


struct VegetarianDiet : Diet {
    virtual void eat()
    {
        cout << "VegetarianDiet cook" << endl;
    }
};

//------------------ Абстрактная фабрика ----------------------

struct AbstractFactory {
    virtual Soup* createSoup() = 0; //создаем абстрактный продукт
    virtual Dinner* createDinner() = 0; //создаем абстрактный продукт
    //при добавлении нового продукта придется добавить новый метод для его создания
    virtual Diet* createDiet() = 0;
};

// ------------------ Конкретные фабрики ----------------------

struct SillyFactory : AbstractFactory {
    virtual Soup* createSoup() {
        return new Borsch(); //создаем экземпляр конкретного продукта 
    }

    virtual Dinner* createDinner() {
        return new Fried_potato(); //создаем экземпляр конкретного продукта 
    }

    //добавить метод создания его конкретного наследника
    virtual Diet* createDiet() {
        return new MeatDiet(); //создает экземпляр конкретного продукта 
    }
};

struct SmartFactory : AbstractFactory {
    virtual  Soup* createSoup() {
        return new Pumpkin(); //создаем экземпляр конкретного продукта 
    }

    virtual Dinner* createDinner() {
        return new Cutlet(); //создаем экземпляр конкретного продукта 
    }

    //добавить метод создания его конкретного наследника
    virtual Diet* createDiet() {
        return new VegetarianDiet();
    }
};


int main() {

    AbstractFactory* factory = new SillyFactory();

    Soup* m1 = factory->createSoup();
    Soup* m2 = factory->createSoup();
    Dinner* Dinner = factory->createDinner();
    //добавим новый продукт 
    Diet* d = factory->createDiet();

    m1->eat();
    m2->eat();
    Dinner->eat();
    //новый продукт
    d->eat();

    delete factory;
    delete m1;
    delete m2;
    delete Dinner;
    delete d; //освобождаем память 

    factory = new SmartFactory(); 
    m1 = factory->createSoup();
    m2 = factory->createSoup();
    Dinner = factory->createDinner();
    
    d = factory->createDiet();

    cout << "-----------------------" << endl;
    m1->eat();
    m2->eat();
    Dinner->eat();
    //новый продукт
    d->eat();

    delete factory;
    delete m1;
    delete m2;
    delete Dinner;
    delete d;//освободим память

    return 0;
}
