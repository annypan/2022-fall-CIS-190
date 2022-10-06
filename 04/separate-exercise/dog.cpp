#include "dog.hpp"
#include <iostream>

dog::dog(string name) : animal {name}
{}

void dog::pet() const override
{
  cout << name << " wags its tail.";
}