#ifndef DOG_HPP
#define DOG_HPP

class dog : public animal
{
public:
    dog(std::string name);

    void pet() const override;
};

#endif