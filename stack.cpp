#include <iostream>

using namespace std;

#define MAX 10
template <class T>
class Stack
{
	private:
		int top;
		T a[MAX];
	public:
		Stack() { top = -1; }
		bool push(T x);
		T pop();
		T peek();
		bool isEmpty();
};

template <class T>
bool Stack<T>::push(T x)
{
	if(top >= (MAX-1))
	{
		cout << "Stack Overeflow";
		return false;
	}
	else
	{
		a[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

template <class T>
T Stack<T>::pop()
{
	if (top < 0)
	{
		cout << "Stack Underflow";
		return 0;
	}
	else
	{
		T x = a[top--];
		return x;
	}
}


int main()
{
	Stack<int> sInts;
	sInts.push(10);
	sInts.push(20);
	sInts.push(30);
	cout << sInts.pop() << " Popped from stack\n";
	cout << sInts.pop() << " Popped from stack\n";
	cout << sInts.pop() << " Popped from stack\n";
	cout << sInts.pop() << " Popped from stack\n";
	
	Stack<float> sFloats;
	sFloats.push(10.8);
	sFloats.push(20.22);
	sFloats.push(30.1);
	cout << sFloats.pop() << " Popped from stack\n";
	cout << sFloats.pop() << " Popped from stack\n";
	cout << sFloats.pop() << " Popped from stack\n";
	cout << sFloats.pop() << " Popped from stack\n";
	return 0;
}
