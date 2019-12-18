#include <iostream>
#include <string>
using namespace std;
class Types{
public :
    Types(){};
	virtual int get_key() { return 0; };
	virtual void show() {};
    virtual string get_value_str() { return "0"; };
    virtual double get_value_doub() { return 0; };
    friend istream& operator >>(istream& in, Types& a){return in;}
    friend ostream& operator <<(ostream& on, Types& a){return on;}
};

class  Type_int_str : public Types{
    int key;
    string value;
public :
    Type_int_str() : key(0), value("") {};
    Type_int_str(int x, string s) : key(x), value(s) {};
    Type_int_str(Type_int_str& t) : key(t.key), value(t.value) {};
     int get_key(){
        return key;
    }
    string get_value_str(){
        return value;
    };
    void show(){
		cout << "key = " << key << ", value = " << value << endl;
    }
    friend istream& operator >>(istream& in, Type_int_str& a);
    friend ostream& operator <<(ostream& in, Type_int_str& a);
};

class  Type_int_doub : public Types{
    int key;
    double value;
public :
    Type_int_doub() : key(0), value(0.0) {};
    Type_int_doub(int x, double d) : key(x), value(d) {};
    Type_int_doub(Type_int_doub& t) : key(t.key), value(t.value) {};
    int get_key(){
        return key;
    }
    double get_value_doub(){
        return value;
    };
    void show(){
        cout<<"key = "<<key<<", value = "<<value<<endl;
    }
    friend istream& operator >>(istream& in, Type_int_doub& a);
    friend ostream& operator <<(ostream& in, Type_int_doub& a);
};

class Array{
        Types** a;
        int size;
        void swap(int, int);
public :
    Array() : size(0){};
    Types* operator [](int index){
        return a[index];
    }
    Types* operator [](string s){
        return find(s);
    }
    void insert(int x, string s);
    void insert(int x, double d);
    void remove(int key);
    Types* find(int key);
    Types* find(string s);
    void sort();
    void show();
};