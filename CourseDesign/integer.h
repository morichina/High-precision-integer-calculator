#ifndef INTEGER_H
#define INTEGER_H
#include <string>

using namespace std;

class Integer
{
    public:
        Integer();
        void input(string);
        void print();
        int compare(Integer);
        void add(Integer);
        void subtract(Integer);
        Integer multiply(Integer);
        Integer divide(Integer);
        int  sub(Integer, int, int, int);
        int check();
        int isZero();

        int length;
        int num[101];
};

#endif // INTEGER_H
