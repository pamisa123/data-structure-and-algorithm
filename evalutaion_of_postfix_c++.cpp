

#include<iostream>
using namespace std;
#include<conio.h>
class stackk
{
	private:
		int tos,mystack[5];
	public:
		stackk()
		{
			tos=-1;
		}
		int push(int value)
		{
			if(tos==4)
			{
				cout<<"stack overflow"<<endl;
			}
			else
			{

				return mystack[++tos]=value;
			}
		}
		void pop()
		{
			if(tos==-1)
			{
				cout<<"stack underflow"<<endl;
			}
			else
			{
				return (mystack[tos--]);
			}
		}
		int top()
		{
			if(tos==-1)
			{
				cout<<"stack is empty"<<endl;
				return -1
			}
			else
			{
				return mystack[tos];
			}
		}
}s;
int operation(int a,int b,char op)
{
	switch(op)
	{
		case '+':return a+b;
			break;
		case '-':return a-b;
			break;
		case'*':return a*b;
			break;
		case '/':return a/b;
			break;
		case '^':return a^b;
			break;
	}
}
void evaluate(string postfix)
{
	stackk s;
	for( int i=0;i<=postfix[i]!=0;i++)
	{
		char oper=postfix[i];
		if(isalnum(oper))
		{
			s.push(oper -'0');
		}
		else
		{
			int op1=s.tos();
			s.pop();
			int op2=s.tos();
			s.pop();
			int result=operation(op1,op2,oper);
			s.push(result);
		}
	}
	int answer=s.tos();
	s.pop();
	return answer;
}
int main()
{
	int postfix;
	cout<<"enter the postfix expression:\n"<<endl;
	cin>>postfix;
	int result=evaluate(postfix);
	cout<<"the evaluation is:"<<result<<endl;
	return 0;

}
