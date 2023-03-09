#include "mocha.h"

Mocha::Mocha() : EspressoBased()
{
    name = "Mocha";
    ingredients = vector<Ingredient *>{};
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    ingredients.push_back(new Chocolate(1));
}

Mocha::Mocha(const Mocha &cap)
{
    name = cap.name;
    ingredients = cap.ingredients;
}

Mocha::~Mocha()
{
    for (auto sideItem : side_items)
    {
        delete (sideItem);
    }
    side_items.clear();
}

void Mocha::operator=(const Mocha &cap)
{
    name = cap.name;
    ingredients = cap.ingredients;
}

std::string Mocha::get_name()
{
    return name;
}

double Mocha::price()
{
    double price = 0;
    for (auto ingredient : ingredients)
    {
        price += ingredient->price();
    }
    for (auto sideItem : side_items)
    {
        price += sideItem->price();
    }
    return price;
}

void Mocha::add_side_item(Ingredient *side)
{
    side_items.push_back(side);
}

std::vector<Ingredient *> &Mocha::get_side_items()
{
    return side_items;
}