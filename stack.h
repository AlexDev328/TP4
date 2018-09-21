#ifndef STACK_H
#define STACK_H

#include <cassert> // для assert
#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
    T *stackPtr;                      // указатель на стек
    int size;                         // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека(количество занятых элементов)
public:
    Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
    ~Stack();                         // деструктор

    inline void push(const T & );     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека
    inline void printStack();         // вывод стека на экран
    inline int getStackSize() const;  // получить размер стека
    inline int getTop() const;        // получить номер текущего элемента в стеке
};


// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) : size(maxSize) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под стек
    top = 0; // инициализируем текущий элемент нулем;
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
    // проверяем размер стека
    if(top<size)
    {
        stackPtr[top++] = value; // помещаем элемент в стек
    }
    else
    {
        size*=2;
        T *temp=new T[size];
        for(int i=0;i<top+1;i++)
        {
            temp[i]=stackPtr[i];
        }
        delete[] stackPtr;
        stackPtr=temp;
        stackPtr[top++] = value;
    }


}

// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
    // проверяем размер стека
    assert(top > 0);  // номер текущего элемента должен быть больше 0 иначе выводим ошибку
    stackPtr[--top];
    // удаляем элемент из стека
if(size/2==top-1)//Проверяем возможность сокращения размера стека
    {
        size/=2;
        T *temp=new T[size];
        for(int i=0;i<top+1;i++)
        {
            temp[i]=stackPtr[i];
        }
        delete[] stackPtr;
        stackPtr=temp;
    }

}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
    for (int ix = top - 1; ix >= 0; ix--)
        cout <<stackPtr[ix] << endl;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getTop() const
{
    return top;
}

#endif // STACK_H
