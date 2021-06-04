#include <iostream>
#include <ctime>
using namespace std;

/*struct Data
{
	string procName;
	unsigned int pLevel;
	string enTime;
*/
#define SIZE  6
class ArrayQueue
{
	public:
		ArrayQueue(){first = last = -1;}
		void enqueue(int);
		int dequeue();
		bool isFull() {return (first == 0 && last == SIZE-1 || first == last + 1);}
		bool isEmpty() {return (first == -1);}
		void printout();
	private:
		int first, last;
		int storage[SIZE];
};

void ArrayQueue::enqueue(int el)
{
	if(!isFull()) if(last == SIZE-1 || last == -1)
	{
		storage[0] = el;
		last = 0;
		if(first == -1) first = 0;
	}
	else storage[++last] = el;
	else cout << "Full Queue.\n";
}

int ArrayQueue::dequeue()
{
	int tmp;
	tmp = storage[first];
	if(!isEmpty())
	{
		int ftmp = first;
		if(first == last) last = first = -1;
		else if(first == SIZE-1) first = 0;
		else first++;
		storage[ftmp] = 0;
		return tmp;
	}
	else
	{
		cout << "Empty Queue.\n";
		return tmp;
	}
}

void ArrayQueue::printout()
{
	for(int i = 0; i < SIZE; i++) cout << "|" << storage[i];
	cout << "|\n---------------------------------\n";
}

int main()
{
	ArrayQueue queue;
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	queue.enqueue(40);
	queue.enqueue(50);
	queue.enqueue(60);
	queue.printout();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.printout();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.enqueue(8);
	cout << queue.dequeue();
	return 0;
}
