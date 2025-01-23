#include <iostream>
#include <string>
#include <vector>

class Ingredient {
public:
    std::string name;
    std::string type;
    double price;
    std::string description;

    Ingredient(std::string name, std::string type, double price, std::string desc) :
        name(name), type(type), price(price), description(desc) {}

    virtual void prepare() const {
        std::cout << "Подготовка ингредиента: " << name << std::endl;
    }
};

class Bun : public Ingredient {
public:
    Bun(std::string name, std::string type, double price, std::string desc)
        : Ingredient(name, type, price, desc) {}

    void prepare() const override {
        std::cout << "Подготовка булочки: " << name << std::endl;
    }
};

class Patty : public Ingredient {
public:
    Patty(std::string name, std::string type, double price, std::string desc)
        : Ingredient(name, type, price, desc) {}

    void prepare() const override {
        std::cout << "Подготовка котлеты: " << name << std::endl;
    }
};

class Burger {
public:
    std::string name;
    std::vector<Ingredient*> ingredients;
    double price;

    Burger(std::string name) : name(name), price(0) {}

    void addIngredient(Ingredient* ingredient) {
        ingredients.push_back(ingredient);
        price += ingredient->price;
    }

    void removeIngredient(const std::string& ingredientName) {
        for (auto it = ingredients.begin(); it != ingredients.end(); ++it) {
            if ((*it)->name == ingredientName) {
                price -= (*it)->price;
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
};

int main() {
    setlocale(LC_ALL, "ru");

    Bun bun("Булочка", "Хлеб", 29.99, "Свежая булочка");
    Patty patty("Котлета", "Мясо", 119.99, "Говяжья котлета");

    Burger burger("Супер-чизбургер");
    burger.addIngredient(&bun);
    burger.addIngredient(&patty);

    burger.prepareIngredients();

    std::cout << "Цена бургера: " << burger.calculatePrice() << " рублей" << std::endl;

    return 0;
}
