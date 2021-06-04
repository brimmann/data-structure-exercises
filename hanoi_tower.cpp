#include <iostream>
using namespace std;
void tower(char, char, char, int, int*);

int main()
{
	int num;
	int c = 0;
	int* p_c = &c;
	//int count; int* p_cout = &count;
	cout << "number of disks: "; cin >> num;
	tower('A', 'C', 'D', num, p_c);
	cout << "steps: " << c;
	return 0;
}
void tower(char source, char destination, char intermediate, int n, int* cnt)
{
	if(n==1) cout << "D1 from " << source << " to " << destination << endl;
	else
	{
		tower(source, intermediate, destination, n-1, cnt);
		cout << "D" << n << " from " << source << " to " << destination << endl;
		tower(intermediate, destination, source, n-1, cnt);
	} 
	(*cnt)++;
}
