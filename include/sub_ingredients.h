#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include <ingredient.h>
#define DEFCLASS(Myclass, pricePerUnit)                                  \
    class Myclass : public Ingredient                                    \
    {                                                                    \
        public: \
        Myclass(size_t units) : Ingredient{pricePerUnit, units} \
        {                                                       \
            this->name = #Myclass;                              \
        }                                                       \
                                                                \
        virtual Ingredient *copy()                              \
        {                                                       \
            return new Myclass(units);                    \
        };                                                      \
        virtual std::string get_name()                          \
        {                                                       \
            return this->name;                                  \
        }                                                       \
    };

DEFCLASS(Cinnamon, 5);

// class Cinnamon : public Ingredient
// {
// public:
//     Cinnamon(size_t units) : Ingredient{5, units}
//     {
//         this->name = "Cinnamon";
//     }

//     virtual Ingredient *copy() { return new Cinnamon(units);}
//     virtual std::string get_name() {return this->name;}
// };

class Chocolate : public Ingredient
{
public:
    Chocolate(size_t units) : Ingredient{5, units}
    {
        this->name = "Chocolate";
    }

    virtual Ingredient *copy() { return new Chocolate(units);}
    virtual std::string get_name() {return this->name;}
};

class Sugar : public Ingredient
{
public:
    Sugar(size_t units) : Ingredient{1, units}
    {
        this->name = "Sugar";
    }

    virtual Ingredient *copy() { return new Sugar(units);}
    virtual std::string get_name() {return this->name;}
};
class Cookie : public Ingredient
{
public:
    Cookie(size_t units) : Ingredient{10, units}
    {
        this->name = "Cookie";
    }
    virtual Ingredient *copy() { return new Cookie(units);}
    virtual std::string get_name() {return this->name;}
};

class Espresso : public Ingredient
{
public:
    Espresso(size_t units) : Ingredient{15, units}
    {
        this->name = "Espresso";
    }

    virtual Ingredient *copy() { return new Espresso(units);}
    virtual std::string get_name() {return this->name;}
};

class Milk : public Ingredient
{
public:
    Milk(size_t units) : Ingredient{10, units}
    {
        this->name = "Milk";
    }

    virtual Ingredient *copy() { return new Milk(units);}
    virtual std::string get_name() {return this->name;}
};

class MilkFoam : public Ingredient
{
public:
    MilkFoam(size_t units) : Ingredient{5, units}
    {
        this->name = "MilkFoam";
    }

    virtual Ingredient *copy() { return new MilkFoam(units);}
    virtual std::string get_name() {return this->name;}
};

class Water : public Ingredient
{
public:
    Water(size_t units) : Ingredient{1, units}
    {
        this->name = "Water";
    }

    virtual Ingredient *copy() { return new Water(units);}
    virtual std::string get_name() {return this->name;}
};

#endif // SUB_INGREDIENTS_H