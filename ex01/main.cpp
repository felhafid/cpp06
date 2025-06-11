#include "Serializer.hpp"

int main ()
{
    Data data;
    data.a = 5;
    // Data *ptr = &data;
    uintptr_t x = Serializer::serialize(&data);
    std::cout <<  x << std::endl;
    Data *newptr = Serializer::deserialize(x);
    std::cout << newptr << std::endl;
    if (newptr == &data)
        std::cout << "it work as it expect\n";
    return 0;
}