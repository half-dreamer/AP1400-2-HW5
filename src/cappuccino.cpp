#include "cappuccino.h"



Cappuccino::Cappuccino() : EspressoBased()
{
    name = "Cappuccino";
    ingredients = vector<Ingredient *>{};
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
}


Cappuccino::Cappuccino(const Cappuccino &cap)
{
    name = cap.name;
    // should execute deep copy in the member variable
    this->ingredients.clear();
    for (auto ingredient : cap.ingredients)
    {
        ingredients.push_back(ingredient->copy());
    }
    side_items.clear();
    for (auto sideItem : cap.side_items)
    {
        side_items.push_back(sideItem->copy());
    }
}

void Cappuccino::operator=(const Cappuccino &cap)
{
    // check for self-assignment
    if (this == &cap) {
        return;
    }
    name = cap.name;
    // should execute deep copy in the member variable
    this->ingredients.clear();
    for (auto ingredient : cap.ingredients)
    {
        ingredients.push_back(ingredient->copy());
    }
    side_items.clear();
    for (auto sideItem : cap.side_items)
    {
        side_items.push_back(sideItem->copy());
    }
}

std::string Cappuccino::get_name()
{
    return name;
}

double Cappuccino::price()
{
    double price = 0;
    for (auto ingredient : ingredients) {
        price += ingredient->price();
    }
    for (auto sideItem : side_items) {
        price += sideItem->price();
    }
    return price;
}


void Cappuccino::add_side_item(Ingredient *side)
{
    side_items.push_back(side);
}


std::vector<Ingredient *> &Cappuccino::get_side_items()
{
    return side_items;
}

Cappuccino::~Cappuccino()
{
    for (auto sideItem : side_items)
    {
        delete (sideItem);
    }
    side_items.clear();
}