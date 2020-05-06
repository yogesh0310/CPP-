#include <iostream>

#include <string.h>

using namespace std;

class Postfix

{

public:

	int top,stack[30];	Postfix()

	{

		top=-1;

	}

	void push(int);

	int pop();

	int full();

	int empty();

};

int Postfix::full()

{

	if(top==29)

	{

		return 1;

	}

	else

	{

		return 0;

	}

}

int Postfix::empty()

{

	if(top==-1)

	{

		return -1;

	}

	else

	{

		return 0;

	}

}

void Postfix::push(int n)

{

	if(full())

	{

		cout<<"Stack is full";

	}

	else

	{

		stack[++top]=n;

	}

}

int Postfix::pop()

{

	int a;

	if(empty())

	{

		cout<<"Stack is empty";

	}

	else

	{

		a=stack[top];

		top--;

		return a;

	}

}

int evaluate(string s)

{

	Postfix p;

	for(int i=0;i<s.length();i++)

	{

		if((s[i]==' ')&&(s[i]==','))

		{

			continue;

		}

		else if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/'))

		{

			int n1,n2,n3;

			n1=p.pop();

			n2=p.pop();

			switch (s[i]) {

				case '+' :

					n3=n2+n1;

					p.push(n3);

					break;

				case '-':

					n3=n2-n1;

					p.push(n3);

					break;

				case '*':

					n3=n2*n1;

					p.push(n3);

					break;

				case '/':

					n3=n2/n1;

					p.push(n3);

					break;

				default:

					cout<<"Unidentified operator";

					break;

			}

		}

		else if(isdigit(s[i]))

		{

			int a=0;

			while(i<s.length() && isdigit(s[i]))

			{

				a=s[i]-'0';

				i++;

			}

			p.push(a);

		}

		return p.pop();

	}

}

int main() {

	string s;

	int a;

	cout<<"Enter proper expression";

	getline(cin,s);

	a=evaluate(s);

	cout<<"Result is:"<<a;

	return 0;

}
