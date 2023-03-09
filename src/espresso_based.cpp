#include "espresso_based.h"


std::vector<Ingredient*>& EspressoBased::get_ingredients() 
{
    return ingredients;
}

void EspressoBased::brew()
{
    ;
}

EspressoBased::EspressoBased()
{
    ingredients = vector<Ingredient *>{};
    name = string{};
}

EspressoBased::EspressoBased(const EspressoBased& esp)
{
    ingredients = esp.ingredients;
    name = esp.name;
}

void EspressoBased::operator=(const EspressoBased& esp)
{
    ingredients = esp.ingredients;
    name = esp.name;
}

EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
        delete i;
    ingredients.clear();
}