#include <iostream>
#include "stack.h"
using namespace std;

struct Student{//описание структуры студент
    char* FIO;
    unsigned int num;
    friend ostream &operator << (ostream &out, Student &tmp)//перегрузка << для корректного вызова функции print в стеке
        {
            out << tmp.FIO<<" "<<tmp.num<<endl;
            return out;
        }
};

int main(int argc, char *argv[])
{
Student tmp;
tmp.FIO="Ivanov Alexey Vyacheslavovich";
tmp.num=151;
Stack<Student> v;
v.push(tmp);
tmp.FIO="Pert Petrovich";
tmp.num=150;
v.push(tmp);
tmp.FIO="Ivan Obramovich";
tmp.num=153;
v.push(tmp);
tmp.FIO="Kamil Valeev";
tmp.num=154;
v.push(tmp);
v.printStack();
cout<<"Size of STECK"<<v.getStackSize()<<endl;
cout<<"Заняты "<<v.getTop()<<endl;
v.pop();
v.pop();
v.pop();
v.printStack();
cout<<"Size of STECK"<<v.getStackSize()<<endl;
cout<<"Заняты "<<v.getTop()<<endl;


}
