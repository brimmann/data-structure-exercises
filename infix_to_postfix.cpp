#include <iostream>
#include <string>
using namespace std;

#define SIZE  100
string toPostFix(string);
int priority(char);
string reverse(string);
class Stack
{
	private:
		int top;
		char a[SIZE];
	public:
		Stack() { top = -1; }
		bool push(char);
		char pop();
		char peek();
		bool isEmpty();
};

int main()
{
	/*string strInfix = "a+b*(c^d-e)^(f+g*h)-i";
	string strPostfix = infixToPostFix(strInfix);
	cout << "Infixed Form: " << strInfix << "\nPostfixed Form: " << strPostfix;*/
	
	string strInfix = "(a+b)+(a-b)";
	string rev_str = reverse(strInfix);
	string post_str = toPostFix(rev_str);
	string infix = reverse(post_str);
	cout << infix;
	return 0;
}

bool Stack::push(char x)
{
	if(top >= (SIZE-1))
	{
		cout << "Stack Overeflow";
		return false;
	}
	else
	{
		a[++top] = x;
		//cout << x << " pushed into stack\n";
		return true;
	}
}

char Stack::pop()
{
	if (top < 0)
	{
		cout << "Stack Underflow";
		return 0;
	}
	else
	{
		int x = a[top--];
		return x;
	}
}

char Stack::peek()
{
	if(top < 0)
	{
		cout << "Stack is Empty\n";
		return 0;
	}
	else
	{
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

int priority(char c)
{
	if(c == '+') return 1;
	else if(c == '-') return 1;
	else if(c == '*') return 2;
	else if(c == '/') return 2;
	else if(c == '^') return 3;
	else if(c == '(') return -1;
}
string toPostFix(string str)
{
	Stack stack;
	string postFixed = "";
	char beingChecked;
	int currentPriority;
	int s, poped;
	for(int i = 0; i < str.length(); i++)
	{
		if(stack.isEmpty())
		{
			if(str[i] >= 'a' && str[i] <= 'z') postFixed += str[i];
			else stack.push(str[i]);
		}
		else
		{
			if(str[i] >= 'a' && str[i] <= 'z') 
			{
				postFixed += str[i]; 
			}
			else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '(')
			{
				if(priority(str[i]) > priority(stack.peek()) || priority(str[i]) == -1) stack.push(str[i]);
				else 
				{
					while(1)
					{
						postFixed += stack.pop();
						if(stack.isEmpty() == true ) break;f
						if(priority(str[i]) > priority(stack.peek()) || str[i] == '(') break;
					}
					stack.push(str[i]);
				}
			}
			else if(str[i] == ')') while(1)
			{
				poped = stack.pop();
				if(poped == '(') break;
				postFixed += poped;
			}
		}
		
	}
	while(stack.isEmpty() != true) postFixed += stack.pop();
	return postFixed;
	
}

string reverse(string input)
{
	int inputLen = input.length()-1;
	char reInput[inputLen];
	string reInputStr;
	for(int i = 0; i <= inputLen; i++)
	{
		if(input[inputLen-i] == ')') 
		{
			reInput[i] = '(';
		}
		else if(input[inputLen-i] == '(') reInput[i] = ')';
		else 
		{
			reInput[i] = input[inputLen-i];
			//cout << "index: " << reInput[i] << " ";
		}
	}
	//cout << reInput;
	for(int i = 0; i < inputLen+1;  i++)  reInputStr += reInput[i];
	return reInputStr;
}
