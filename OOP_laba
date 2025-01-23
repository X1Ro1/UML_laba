#include <iostream>
#include <string>
#include <vector>

class Ingredient {
public:
    std::string name;
    std::string type;
    double price;
    std::string description;

    Ingredient(std::string name, std::string type, double price, std::string desc): 
        name(name), type(type), price(price), description(desc) {}
};

class Burger {
public:
    std::string name;
    std::vector<Ingredient> ingredients;
    double price;

    Burger(std::string name) : name(name), price(0) {}

    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
        price += ingredient.price;
    }

    void removeIngredient(const std::string& ingredientName) {
        for (auto it = ingredients.begin(); it != ingredients.end(); ++it) {
            if (it->name == ingredientName) {
                price -= it->price;
                ingredients.erase(it);
                break;
            }
        }
    }

    double calculatePrice() const {
        return price;
    }
};

class Menu {
public:
    std::vector<Burger> burgerList;

    Burger selectBurger(const std::string& name) {
        for (auto& burger : burgerList) {
            if (burger.name == name) {
                return burger;
            }
        }
        throw std::runtime_error("Бургер не найден");
    }
};

class BurgerBuilder {
public:
    Burger currentBurger;

    BurgerBuilder(std::string name) : currentBurger(name) {}

    void addBun(const Ingredient& bun) {
        currentBurger.addIngredient(bun);
    }

    void addSauce(const Ingredient& sauce) {
        currentBurger.addIngredient(sauce);
    }

    void addFilling(const Ingredient& filling) {
        currentBurger.addIngredient(filling);
    }

    Burger getBurger() {
        return currentBurger;
    }
};

class Worker {
public:
    void prepareBurger(const Burger& burger) {
        std::cout << "Подготовка бургера: " << burger.name << std::endl;
    }

    double serveCustomer(const Burger& burger) {
        return burger.calculatePrice();
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Ingredient bun("Булочка", "Хлеб", 29.99, "Свежая булочка");
    Ingredient patty("Котлета", "Мясо", 119.99, "Говяжья котлета");
    Ingredient cheese("Сыр", "Молочный", 49.89, "Чеддер");

    BurgerBuilder builder("Супер-чизбургер");
    builder.addBun(bun);
    builder.addSauce(patty);
    builder.addFilling(cheese);

    Burger cheeseburger = builder.getBurger();

    Worker worker;
    worker.prepareBurger(cheeseburger);
    double price = worker.serveCustomer(cheeseburger);

    std::cout << "Цена бургера: " << price << " рублей" << std::endl;

    return 0;
}
