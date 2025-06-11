#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

    #include <string>
    #include <iostream>

    class ScalarConverter{
        private:
            ScalarConverter();
            ~ScalarConverter();
            ScalarConverter(const ScalarConverter &org);
            ScalarConverter& operator=(const ScalarConverter &org);
        public:
            static void convert(std::string s);
    };
#endif