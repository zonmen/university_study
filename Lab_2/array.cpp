#include <iostream>
#include <string>
#include "array.h"
using namespace std;


istream& operator >>(istream& in, Type_int_str& a){
    return in>>a.key>>a.value;
}
ostream& operator <<(ostream& out, Type_int_str& a){
    return out<<a.key<<"  "<<a.value<<endl;
}


istream& operator >>(istream& in, Type_int_doub& a){
    return in>>a.key>>a.value;
}
ostream& operator <<(ostream& out, Type_int_doub& a){
    return out<<a.key<<"  "<<a.value<<endl;
}


//Array
void Array ::  insert(int x, string s){
        size++;
        Types** copy = new Types* [size];
        for(int i = 0; i<size-1; i++)
        {
            copy[i] = a[i];
        }
        copy[size-1] = new Type_int_str(x,s);
        a = copy;
    }
void Array ::  insert(int x, double d){
        size++;
        Types** copy = new Types* [size];
        for(int i = 0; i<size-1; i++)
        {
            copy[i] = a[i];
        }
        copy[size-1] = new Type_int_doub(x,d);
        a = copy;
    }
void Array ::  show(){
    if(size>0){
        for(int i = 0; i<size; i++)
        {
            cout<<"Element "<<i+1<<" : ";
            a[i]->show();
        }
    } else 
        cout<<"There are no elements"<<endl;
}
Types* Array ::  find(int key){
        for(int i = 0; i<size; i++)
        {
            if(a[i]->get_key() == key) 
                return a[i];
        }
        cout<<"Element not found "<<endl;
        return (new Types());
    }
    
Types* Array :: find(string s){
    for(int i = 0; i<size; i++)
        {
            if(a[i]->get_value_str() == s) 
                return a[i];
        }
        cout<<"Element not found "<<endl;
        return (new Types());
}
    
void Array ::  remove(int key){
        Types* a2 = find(key);
         if(a2->get_key() == key){
         int i = 0;
         size--;
         Types** copy = new Types* [size];
         for( int j = 0; i<=size; i++)
        {
            if(a[i] != a2){
                copy[j] = a[i];
                j++;
            }
        }
        a = copy;
    }
}
void Array :: swap(int index1,int index2){
    Types* temporary = a[index1];
    a[index1] = a[index2];
    a[index2] = temporary;
}
void Array :: sort(){
    if(size > 0){
    int flag = 0;
    Types* t1 = a[0];
    Types* t2 = a[1];
    for(int j = 0; j<size-1; j++){
    for(int i = 0; i <(size-1) - j; i++){
        t1 = a[i];
        t2 = a[i+1];
        if(t1->get_key()>t2->get_key()){
            swap(i,i+1);
            flag++;
        }
    }
    if(flag == 0) 
            j = size;
    }
    
    } else
                cout<<"There are no elements"<<endl;
}
