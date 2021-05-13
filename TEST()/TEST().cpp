#include <iostream>
using namespace std;

//------------- Абстрактные продукты ---------------
struct Soup { //абстрактный продукт 
    virtual void eat() = 0;
};

struct Dinner { //абстрактный продукт
    virtual void eat() = 0;
};


struct Diet { // абстрактный продукт - вообще это должна была быть фабрика
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
struct MeatDiet : Diet { //вот это тоже должна была быть фабрика
    virtual void eat()
    {
        cout << "MeatDiet cook" << endl;
    }
};


struct VegetarianDiet : Diet { // и это тоже подразумевалось фабрикой
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
    virtual Diet* createDiet() = 0; // т.к. диета подразумевалась фабрикой, то тут ее не надо было создавать
};

// ------------------ Конкретные фабрики ----------------------

struct SillyFactory : AbstractFactory { //вот это должна была быть фабрика МяснаяДиета
    virtual Soup* createSoup() {
        return new Borsch(); //создаем экземпляр конкретного продукта 
    }

    virtual Dinner* createDinner() {
        return new Fried_potato(); //создаем экземпляр конкретного продукта  - т.к. диета мясная, то создавать надо было котлетку
    }

    //добавить метод создания его конкретного наследника
    virtual Diet* createDiet() {
        return new MeatDiet(); //создает экземпляр конкретного продукта  - т.к. диета - это фабрика, а тут создается продукт, то ее не надо было
    }
};

struct SmartFactory : AbstractFactory { // вот это должна быть фабрика ВегетарианскаяДиета
    virtual  Soup* createSoup() {
        return new Pumpkin(); //создаем экземпляр конкретного продукта 
    }

    virtual Dinner* createDinner() {
        return new Cutlet(); //создаем экземпляр конкретного продукта  - т.к. диета вегетарианская, то тут надо было создавать жареную картошку
    }

    //добавить метод создания его конкретного наследника
    virtual Diet* createDiet() { //т.к. диета - это фабрика, а создавать тут надо продукт, то этого метода тут быть не должно
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
