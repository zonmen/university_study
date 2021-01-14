#include <iostream>

template<typename T>

class my_vector

{
    T* iterator;
    int capacity;
    int current;

public:

    my_vector()

    {


        iterator = new T[1];
        capacity = 1;
        current = 0;

    }

    my_vector(int n)

    {

        iterator = new T[n];
        capacity = n;
        current = 0;

    }

    void push_back(T data)

    {

        if (current == capacity)

        {

            int* temp = new int[2 * capacity];

            for (int i = 0; i < capacity; i++)

            {

                temp[i] = iterator[i];

            }

            delete[] iterator;

            capacity *= 2;

            iterator = temp;

        }

        iterator[current++] = data;

    }

    T& operator[] (const int index)
    {
        return iterator[index];
    }

    T* get_iterator(int index)

    {

        return (iterator + index);

    }


    void insert(T* it, T value) {
        T* temp = new T[current + 1];
        int i = 0;
        for (; i <= current; i++) {
            if (it == (iterator + i)) {
                temp[i] = value;
                break;
            }
            else
                temp[i] = iterator[i];
        }
        if (current == 0)
            i = 1;
        for (; i <= current; i++) {
            temp[i + 1] = iterator[i];
        }
        delete[] iterator;
        iterator = temp;
        current++;
        capacity++;
    }

    void insert(T* it, T* first, T* last) {
        int n = last - first;
        T* temp = new T[(current + 1) + n];

        int j = 0;
        for (int i = 0; i <= current; i++) {
            if (it == (iterator + i)) {
                for (; j < n; j++)
                {
                    temp[i + j] = *first;
                    first++;
                }
            }
                temp[i+j] = iterator[i];
        }

        delete[] iterator;
        iterator = temp;
        current += n;
        capacity += n + 1;
    }


    void erase(T* first, T* last) {
        int n = last - first;
        bool condition = false;

        for (int i = 0; i <= current - n; i++) {
            if ((first == (iterator + i)) || condition) {
                condition = true;
                iterator[i] = iterator[i + n];
            }
        }

        current -= n;
    }

    void pop_back()

    {

        current--;

    }

    T* begin() {
        return iterator;
    }

    T* end() {
        return (iterator + current);
    }

    int size()

    {

        return current;

    }

    int get_capacity()

    {

        return capacity;

    }

    int get_current()

    {

        return current;

    }


};
