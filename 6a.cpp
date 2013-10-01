#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

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
int x,y,n;
STACK <char, 10> A;
char item[10];

// clear stack
A.Clear();

// get expression from user
cout << "Enter a postfix expression with $ at the end: ";
cin.getline(item,10);

// process data
while(strcmp(item, "$") != 0)
{
   if(strcmp(item, "+") == 0)
   {
   	x = A.Pop();
   	y = A.Pop();
   	A.Push(y+x);
   }
   else if(strcmp(item, "*") == 0)
   {
   	x = A.Pop();
   	y = A.Pop();
   	A.Push(y*x);
   }
   else if(strcmp(item, "/") == 0)
   {
   	x = A.Pop();
   	y = A.Pop();
   	A.Push(y/x);
   }
   else if(strcmp(item, "-") == 0)
   {
   	x = A.Pop();
   	y = A.Pop();
   	A.Push(y-x);
   }
   // if its a number
   else
   {    
   	n = atoi(item);
   	A.Push(n);

   }
}

    int r = A.Pop();
    // output result
    cout << "Result is " << r << endl;
    return(0);
}