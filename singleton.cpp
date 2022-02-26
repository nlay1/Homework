#include "singleton.h"
#include<iostream>

Singleton* Singleton ::  instance = 0; 

Singleton* Singleton :: getInstance()
{
    if(!instance)
    {
        instance = new Singleton();
        std:: cout << "instance created\n";
    }
    return instance; 
}

Singleton :: ~Singleton()
{
    delete instance;
}

int Singleton :: getValue() const 
{
    return m_value;
}

void Singleton :: setValue(const int val)
{
m_value = val;
}

int main()
{
    Singleton* ptr = Singleton :: getInstance();
    ptr->setValue(5);

    Singleton* ptr2 = Singleton :: getInstance();
    std:: cout << ptr2->getValue();

    std::cout << std::endl;
}