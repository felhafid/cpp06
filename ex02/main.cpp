#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    //return random base* a or b or c
    int x = std::rand();
    if (x % 3 == 0)
        return (new A);
    else if (x % 3 == 1)
        return (new B);
    else
        return (new C);
    
}

void identify(Base* p)
{

}

void identify(Base& p)
{
    
}

int main()
{

}