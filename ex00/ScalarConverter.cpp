#include "ScalarConverter.hpp"

#define ERROR  0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define COMP 5

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &org)
{
    (void) org;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &org)
{
    (void) org;
    return (*this);
}

int check_errors(std::string &s)
{
    int i = 0;
    if (s == "-inff" || s == "+inff" || s == "nanf"
         || s == "inff" || s == "-inf" || s == "+inf"
            || s == "nan" || s == "inf")
        return COMP;
    if (((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && s.length() == 1)
        return CHAR;
    if (s.length() == 3 && s[0] == 39 && s[2] == 39 && 
        ((s[1] >= 'a' && s[1] <= 'z') || (s[1] >= 'A' && s[1] <= 'Z')))
        return CHAR;
    if ((s[i] == '+' || s[i] == '-' ))
    {
        i++;
        if  (!(s[i] >= '0' && s[i] <= '9'))
            return ERROR;
    }    
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9') && s[i] != 'f' && s[i] != '.')
            return ERROR;
        i++;
    }
    return 234;
}

int check_type(std::string &s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == '.' || s[i] == 'f')
            break ;
        if (s[i + 1] == '\0')
            return INT;
        i++;
    }
    while (s[i])
    {
        if (s[i] == '.')
        {
            i++;
            if (!(s[i] >= '0' && s[i] <= '9'))
                return ERROR;
            while (s[i] && ((s[i] >= '0' && s[i] <= '9') || s[i] == 'f'))
            {
                if (s[i] == 'f' && s[i + 1] == '\0')
                    return FLOAT;
                if (s[i] == 'f' && s[i + 1] != 0)
                    return ERROR;
                i++;
            }
            if (s[i])
                return ERROR;
        }
        else if (!(s[i] >= '0' && s[i] <= '9'))
            return ERROR;
        i++;
    }
    return DOUBLE;
}

void    to_char(std::string s)
{
    int a = static_cast<int>(atol(s.c_str()));
    if (a > 32 && a < 127)
        std::cout << "char: '" << static_cast<char>(atol(s.c_str())) << "'" << std::endl;
    else if (a >= 0 && a <= 127)
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << "Impossible" << std::endl;
}

void print_char(std::string s, int type)
{
    if (type == CHAR)
    {
        if (s.length() == 3)
            std::cout << "char : '" << s[1] << "'" <<std::endl;
        else
            std::cout << "char : '" << s[0] << "'" <<std::endl;
    }
    else
    {
        if (type == COMP)
            std::cout << "char : impossible" << std::endl;
        else
            to_char(s); 
    }
}

void    print_int(std::string s, int type)
{
    if (type == CHAR)
    {
        if (s.length() == 3)
            std::cout << "int: " << static_cast<int>(s[1]) << std::endl;
        else
            std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
    }
    else
    {
        if (type == COMP)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(atol(s.c_str())) << std::endl;
    }
    
}

void    to_float(std::string s, int a)
{
    std::cout << "float: ";
    if (a == INT)
        std::cout << static_cast<float>(atol(s.c_str())) << ".0f" << std::endl;
    else
    {
        if (a == COMP && s[0] == '+')
            std::cout << s[0];
        if (s.find(".0") != std::string::npos && (s.find('.') == s.length() - 3 || s.find('.') == s.length() - 2))
            std::cout << static_cast<float>(atof(s.c_str())) << ".0f" << std::endl;
        else
            std::cout << static_cast<float>(atof(s.c_str())) << "f" << std::endl;
    }
        
}

void    print_float(std::string s, int type)
{
    if (type == CHAR)
    {
        if (s.length() == 3)
            std::cout << "float: " << static_cast<float>(s[1]) << ".0f" <<std::endl;
        else
            std::cout << "float: " << static_cast<float>(s[0]) << ".0f" <<std::endl;     
    }
    else
    {
        to_float(s, type);
    }
        
}

void    to_double(std::string s, int type)
{
    std::cout << "double: ";
    if (type == INT)
        std::cout << static_cast<double>(atol(s.c_str())) << ".0" << std::endl;
    else
    {
        if (type == COMP && s[0] == '+')
            std::cout << s[0];
        if (s.find(".0") != std::string::npos && (s.find('.') == s.length() - 3 || s.find('.') == s.length() - 2))
            std::cout << static_cast<double>(atof(s.c_str()))  << ".0"<< std::endl;
        else
            std::cout << static_cast<double>(atof(s.c_str())) << std::endl;
    }
    
}

void    print_double(std::string s, int a)
{
    if (a == CHAR)
    {
        if (s.length() == 3)
            std::cout << "double: " << static_cast<double>(s[1]) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(s[0]) << ".0" << std::endl;     
    }
    else
        to_double(s, a);
}

void ScalarConverter::convert(std::string s)
{
    int type;
    type = check_errors(s);
    if (type == ERROR)
    {
        std::cerr << "INVALID" << std::endl;
        return ;
    }
    if (type == 234)
        type = check_type(s);
    if (type == ERROR)
        std::cerr << "INVALID" << std::endl;
    else
    {
        print_char(s, type);
        print_int(s, type);
        print_float(s, type);
        print_double(s, type);
    }
    
}
