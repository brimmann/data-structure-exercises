#include <iostream>
#include <string>
using namespace std;
int factorial(int);
int product(int, int);
int feb(int);
int main()
{	
	//cout << factorial(4);
	//cout << product(8, 3);
	int w = 13;
	int i = 0;
	while(i < w)
	{
		cout << feb(i) << " ";
		i++;
	}
}

int factorial(int n)
{
	if(n == 0) return 1;
	else return n * factorial(n-1);
}

int product(int a, int b)
{
	if(b == 1) return a;
	else return product(a, b-1) + a;
}

int feb(int n)
{
	if(n == 0 || n == 1) return n;
	else return (feb(n-2) + feb(n-1));
}
