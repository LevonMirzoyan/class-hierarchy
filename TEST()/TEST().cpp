#include <iostream>
using namespace std;

//------------- Абстрактные продукты ---------------
struct Soup { //абстрактный продукт 
    virtual void eat() = 0;
};

struct Dinner { //абстрактный продукт
    virtual void eat() = 0;
};


//struct Diet { // абстрактный продукт - вообще это должна была быть фабрика
 //   virtual void eat() = 0;
//};

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



//------------------ Абстрактная фабрика ----------------------

struct Diet {
    virtual Soup* createSoup() = 0; //создаем абстрактный продукт
    virtual Dinner* createDinner() = 0; //создаем абстрактный продукт
    //при добавлении нового продукта придется добавить новый метод для его создания
  //  virtual Diet* createDiet() = 0; // т.к. диета подразумевалась фабрикой, то тут ее не надо было создавать
};

// ------------------ Конкретные фабрики ----------------------

struct MeatDiet : Diet { 
    virtual Soup* createSoup() {
        return new Borsch(); //создаем экземпляр конкретного продукта 
    }
    
    virtual Dinner* createDinner() {
        return new Cutlet(); //создаем экземпляр конкретного продукта 
    }

};

struct VegetarianDiet : Diet { // вот это должна быть фабрика ВегетарианскаяДиета
    virtual  Soup* createSoup() {
        return new Pumpkin(); //создаем экземпляр конкретного продукта 
    }
    virtual Dinner* createDinner() {
        return new Fried_potato(); //создаем экземпляр конкретного продукта  
    }

   

};


int main() {

    Diet* factory = new MeatDiet(); 

    Soup* m1 = factory->createSoup();
    
    Dinner* Dinner = factory->createDinner();
    
    cout << '\n' << "MeatDiet :"  << endl;

    m1->eat();
    
    Dinner->eat();
    

    delete factory;
    delete m1;
    delete Dinner;
   

    factory = new VegetarianDiet();
    m1 = factory->createSoup();
    
    Dinner = factory->createDinner();

 

    cout << '\n' << "VegetarianDiet: "  << endl;
    m1->eat();
    
    Dinner->eat();
   

    delete factory;
    delete m1;
    
    delete Dinner;
 

    return 0;
}
