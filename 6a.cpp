#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

template <class T, int n>
class STACK
{
   private:
   	T elem[n];
   	int counter;
   public:
   	void Clear(){ counter = 0; }
   	bool Full(){ if (counter == n) return true; else return false;}
   	bool Empty(){ if (counter == 0) return true; else return false;}
   	T Pop(){ counter--; return elem[counter];}
   	void Push(T x){ elem[counter] = x; counter++;}
};

int main(){

// declare variables and structures
int x,y,n, size, result;
STACK <char, 10> A;
char expression[10];

// get expression from user
cout << "Enter a postfix expression with $ at the end: ";

size = expression.length();
char input[size];


// process expression and insert into stack
do{
	if(strcmp(input, "+") == 0){
		x = A.Pop();
		y = A.Pop();
		A.Push(y+x);
	}
	else if(strcmp(input, "*") == 0){
		x = A.Pop();
		y = A.Pop();
		A.Push(y*x);
	}
	else if(strcmp(input, "/") == 0){
		x = A.Pop();
		y = A.Pop();
		A.Push(y/x);
	}
	else if(strcmp(input, "-") == 0){
		x = A.Pop();
		y = A.Pop();
		A.Push(y-x);
	}
	// if its a number
	else{    
		n = atoi(input);
		A.Push(n);
	}
	cin.getline (expression, 10);
}
	
}while(strcmp(input, "$") != 0);


return(0);
}