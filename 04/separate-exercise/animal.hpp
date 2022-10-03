#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class animal
{
protected:
    std::string name;

public:
    animal(std::string name);

    virtual void pet() const = 0;
};

#endif