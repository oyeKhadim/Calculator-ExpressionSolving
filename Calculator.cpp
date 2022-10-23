#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
class Solution
{
public:
	int calculate(vector<string>postfix)
	{
		//Solving Postfix Notation
		stack<int> result;
		int size = postfix.size();
		for (int i = 0; i < size; i++)
		{
			//Check it is Number or Operator
			if (checkDigit(postfix[i]))
			{
				//if it is number push it into stack
				int b = stoi(postfix[i]);
				result.push(b);
			}
			else
			{
				//if it is operator pop 2 numbers from stack and apply operator
				//And push the result in Stack again
				string oper = postfix[i];
				int num1 = result.top();
				result.pop();
				int num2 = result.top();
				result.pop();
				int num3 = calculateResult(num2, num1, oper);
				result.push(num3);
			}
		}

		//Top most element of stack will be the result
		if (result.size() >= 1) {
			return result.top();
		}
		return 0;
	}
	int calculateResult(int a, int b, string op)
	{
		if (op == "+")
		{
			return a + b;
		}
		else if (op == "-")
		{
			return a - b;
		}
		else if (op == "*")
		{
			return a * b;
		}
		else if (op == "/")
		{
			return a / b;
		}
		else
		{
			return -1;
		}
	}
	bool checkDigit(string line)
	{
		for (int i = 0; line[i] != '\0'; i++)
		{
			if (!isdigit(line[i]))
			{
				return false;
			}
		}
		return true;
	}
	vector<string>makePostfix(string infix) {
		//This fution will convert infix notation to postfix notation

		vector<string> postfix;
		vector<string> operations;
		string a = "";
		//Converting Infix Notation to Postfix
		for (int i = 0; infix[i] != '\0'; i++)
		{
			if (infix[i] == '+')
			{
				if (a != "")
				{
					postfix.push_back(a);
				}
				int size = operations.size();
				if (size >= 1)
				{
					if (operations[size - 1] == "*" || operations[size - 1] == "/")
					{
						for (int j = size - 1; j >= 0; j--)
						{
							postfix.push_back(operations[j]);
							operations.pop_back();
						}
					}
				}
				operations.push_back("+");
				a = "";
			}
			else if (infix[i] == '-')
			{
				if (a != "")
				{
					postfix.push_back(a);
				}
				int size = operations.size();
				if (size >= 1)
				{

					if (operations[size - 1] == "*" || operations[size - 1] == "/")
					{
						for (int j = size - 1; j >= 0; j--)
						{
							postfix.push_back(operations[j]);
							operations.pop_back();
						}
					}
				}
				operations.push_back("-");
				a = "";
			}
			else if (infix[i] == '*')
			{
				if (a != "")
				{
					postfix.push_back(a);
				}
				operations.push_back("*");
				a = "";
			}
			else if (infix[i] == '/')
			{
				if (a != "")
				{
					postfix.push_back(a);
				}
				operations.push_back("/");
				a = "";
			}
			else if (infix[i] == ' ')
			{
			}
			else if (infix[i] == '(')
			{
				if (a != "")
				{
					postfix.push_back(a);
				}
				operations.push_back("(");
				a = "";
			}
			else if (infix[i] == ')')
			{
				if (a != "")
				{
					postfix.push_back(a);
				}
				a = "";
				int size = operations.size();
				for (int j = size - 1; operations[j] != "("; j--)
				{
					postfix.push_back(operations[j]);
					operations.pop_back();
				}
				operations.pop_back();
			}
			else
			{
				a += infix[i];
			}
		}
		if (a != "")
		{
			postfix.push_back(a);
			a = "";
		}
		int size = operations.size();
		for (int i = size - 1; i >= 0; i--)
		{
			postfix.push_back(operations[i]);
			operations.pop_back();
		}
		return postfix;
	}

};

int main()
{
	
	Solution s;
	string str="5+3*2"; 							//store any expression here   
	vector<string> postfix=s.makePostfix(str);
	cout << s.calculate(postfix);					//calculates the result of postfix notation stored in t.traversal

}
