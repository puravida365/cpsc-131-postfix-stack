#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>

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
   
int main()
{
int x,y,n,result,size;
STACK <char, 10> A;

string expression;

// clear stack
A.Clear();

// get expression from user
cout << "Enter a postfix expression:";
cin >> expression;
size = expression.length();

char item[size];

for(int i=0; i<size; ++i){
	item[i] = expression[i];
}


for(int j=0; j<size; ++j){

	if(item[j] == '+'){
		x = A.Pop();
		y = A.Pop();
		A.Push(y+x);
	}
	else if( item[j] == '*'){
		x = A.Pop();
		y = A.Pop();
		A.Push(y*x);
	}
	else if( item[j] == '/'){
		x = A.Pop();
		y = A.Pop();
		A.Push(y/x);
	}
	else if( item[j] == '-'){
		x = A.Pop();
		y = A.Pop();
		A.Push(y-x);
	}
	else{    
		n = (item[j]) - (48);
		A.Push(n);
	}

}

// output result
result = A.Pop();    
cout << "Result is " << result << endl;

    return(0);
}