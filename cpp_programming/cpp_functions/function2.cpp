
#include <iostream>
using namespace std;

//Function declaration
int sum(int x, int y);//Declare a function called sum that takes two integer arguments

int main(){
int num1 =10;
int num2 = 20;

//cxall the function and store the result
int total = sum(num1, num2); //calls the sum function with values of num1 and num2
cout<<"The sum of "<< num1 << " and " << num2 << " is " << total;
return 0;

}
//Function definition
int sum(int x, int y){//defines the function sum with its implementation
int sumValue = x+y;
return sumValue;

}
