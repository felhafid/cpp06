#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

    #include <iostream>

    typedef struct {
        int a;
    }Data;

    class Serializer
    {
        private:
            Serializer();
            ~Serializer();
            Serializer(const Serializer &org);
            Serializer& operator=(const Serializer &org);
        public:
           static uintptr_t serialize(Data* ptr);
           static Data* deserialize(uintptr_t raw);

    };

#endif