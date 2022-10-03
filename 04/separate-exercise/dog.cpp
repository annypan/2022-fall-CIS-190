#include "dog.hpp"
#include "animal.hpp"
using std::istream, std::ostream, std::string;

dog::dog(string name) : animal {name}
{}

void dog::pet() const override
{
  cout << name << " wags its tail.";
}