#include <iostream>
using namespace std;
int power(int, unsigned int);
int main()
{
	cout << power(3, 2);
	return 0;
}

int power(int base, unsigned int pow)
{
	if(pow == 0) return 1;
	else return base * power(base, pow-1);
}
