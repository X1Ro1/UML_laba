#include <iostream>
#include <string>
#include <vector>

class Ingredient {
private:
    std::string name;
    std::string type;
    double price;
    std::string description;

public:
    Ingredient(std::string name, std::string type, double price, std::string desc) :
        name(name), type(type), price(price), description(desc) {}

    virtual void prepare() const {
        std::cout << "Подготовка ингредиента: " << name << std::endl;
    }

    std::string getName() const { return name; }
    double getPrice() const { return price; }
};

class Bun : public Ingredient {
public:
    Bun(std::string name, std::string type, double price, std::string desc)
        : Ingredient(name, type, price, desc) {}

    void prepare() const override {
        std::cout << "Подготовка булочки: " << getName() << std::endl;
    }
};

class Patty : public Ingredient {
public:
    Patty(std::string name, std::string type, double price, std::string desc)
        : Ingredient(name, type, price, desc) {}

    void prepare() const override {
        std::cout << "Подготовка котлеты: " << getName() << std::endl;
    }
};

class Burger {
private:
    std::string name;
    std::vector<Ingredient*> ingredients;
    double price;

public:
    Burger(std::string name) : name(name), price(0) {}

    void addIngredient(Ingredient* ingredient) {
        ingredients.push_back(ingredient);
        price += ingredient->getPrice();
    }

    void removeIngredient(const std::string& ingredientName) {
        for (auto it = ingredients.begin(); it != ingredients.end(); ++it) {
            if ((*it)->getName() == ingredientName) {
                price -= (*it)->getPrice();
                ingredients.erase(it);
                break;
            }
        }
    }

    double calculatePrice() const {
        return price;
    }

    void prepareIngredients() const {
        for (const auto& ingredient : ingredients) {
            ingredient->prepare();
        }
    }

    void cook() const {
        std::cout << "Приготовление бургера: " << name << std::endl;
        prepareIngredients();
        std::cout << "Бургер готов!" << std::endl;
    }
};

class Worker {
private:
    std::string name;

public:
    Worker(std::string name) : name(name) {}

    void prepareBurger(Burger& burger) const {
        std::cout << "Работник " << name << " начинает готовить бургер." << std::endl;
        burger.cook();
        std::cout << "Работник " << name << " закончил приготовление бургера." << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Bun bun("Булочка", "Хлеб", 29.99, "Свежая булочка");
    Patty patty("Котлета", "Мясо", 119.99, "Говяжья котлета");

    Burger burger("Супер-чизбургер");
    burger.addIngredient(&bun);
    burger.addIngredient(&patty);

    Worker worker("Артем");
    worker.prepareBurger(burger);

    std::cout << "Цена бургера: " << burger.calculatePrice() << " рублей" << std::endl;

    return 0;
}
