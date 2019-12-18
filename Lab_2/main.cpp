#include <iostream>

#include "array.h"
using namespace std;

void dialoge(int& choose)
{
	cout << "1. Insert pair to array(int, string) " << endl;
	cout << "2. Insert pair to array(int, double) " << endl;
	cout << "3. Remove pair by key " << endl;
	cout << "4. Show result map	" << endl;
	cout << "5. Sort array by key " << endl;
	cout << "6. Exit " << endl;
	cin >> choose;
}



int main(int argc, char **argv)
{
	Array r;
	int x;
	double d;
	string s;
	int choose = 0;
	do {
		dialoge(choose);
		switch (choose)
		{
		case 1:
		{
			cin >> x >> s;
			r.insert(x, s);
			break;
		}
		case 2:
		{
			cin >> x >> d;
			r.insert(x, d);
			break;
		}
		case 3:
		{
			cin >> x;
			r.remove(x);
			break;
		}
		case 4:
		{
			r.show();
			break;
		}
		case 5:
		{
			r.sort();
			break;
		}
		case 6:
		{
			break;
		}
		default: {

			cout << "Incorrect number" << endl;
			break;
		}
		}
	} while (choose != 6);
	return 0;
}