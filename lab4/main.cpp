#include <iostream>
#include<vector>
#include "my_vector.cpp"

using namespace std;



template<class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function fn)
{
    while (first != last) {
        fn(*first);
        ++first;
    }
    return fn;
}

template <class Cont_out, class Iterator_in, class Iterator_out>
Iterator_out my_copy(Cont_out& cont_out, Iterator_out o_first, Iterator_in first, Iterator_in last) {

        cont_out.insert(o_first, first, last);

    return o_first;
};

template <class Cont_in, class Cont_out, class Iterator_in, class Iterator_out>
Iterator_out my_move(Cont_in& cont_in, Cont_out& cont_out, Iterator_out o_first, Iterator_in first, Iterator_in last) {

    cont_out.insert(o_first, first, last);
    cont_in.erase(first, last);
    return o_first;
};


void show_std_vector() {
    cout << "Std vector" << endl;
    vector<int> v1;
    int n1 = 5;
    cout << "Vector 1 :" << endl;
    for (int i = 0; i < n1; i++)
    {
        v1.push_back((i + 1) * 10);
        cout << "   " << v1[i] << endl;
    }

    vector<int> v2;
    int n2 = 3;
    cout << endl << "Vector 2 :" << endl;
    for (int i = 0; i < n2; i++)
    {
        v2.push_back(i);
        cout << "   " << v2[i] << endl;
    }

    //функция копирования
//    my_copy(v2, v2.begin() + 1, v1.begin() + 1,  v1.begin() + 3);
    my_move(v1, v2, v2.begin() + 1, v1.begin() + 1, v1.begin() + 3);


    cout << endl << "Mod Vector 1 :" << endl;
    for_each(v1.begin(), v1.end(), [](int n)
    {
        cout << "   " << n << endl;
    });
    cout << endl << "Mod Vector 2 :" << endl;
    for_each(v2.begin(), v2.end(), [](int n)
    {
        cout << "   " << n << endl;
    });

}
void show_my_vector() {
    cout << endl << "My vector" << endl;
    my_vector<int> v1;
    int n1 = 5;
    cout << "Vector 1 :" << endl;
    for (int i = 0; i < n1; i++)
    {
        v1.push_back((i + 1) * 10);
        cout << "   " << v1[i] << endl;
    }

    my_vector<int> v2;
    int n2 = 3;
    cout << endl << "Vector 2 :" << endl;
    for (int i = 0; i < n2; i++)
    {
        v2.push_back(i);
        cout << "   " << v2[i] << endl;
    }

    //функция копирования
//    my_copy(v2, v2.begin() + 1, v1.begin() + 1,  v1.begin() + 3);
//    my_move(v1, v2, v2.begin() + 1, v1.begin() + 1, v1.begin() + 3);
    //последовательность накладывается : 
    my_move(v1, v1, v1.begin(), v1.begin() + 2, v1.end());

    cout << endl << "Mod Vector 1 :" << endl;
    for_each(v1.begin(), v1.end(), [](int n)
    {
        cout << "   " << n << endl;
    });
    cout << endl << "Mod Vector 2 :" << endl;
    for_each(v2.begin(), v2.end(), [](int n)
    {
        cout << "   " << n << endl;
    });


}

int main()
{
    show_std_vector();
    show_my_vector();

    return 0;
}
