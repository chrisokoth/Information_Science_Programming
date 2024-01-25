/*Write a simple C++ function that takes
 two integer parameters and returns their sum.
 Demonstrate its usage in the main function.
*/
#include <iostream>
using namespace std;

//function declaration
int calculate_sum(int a, int b);

//function definition
int calculate_sum(int a, int b){
return a+b;
}

//usage in main function
int main(){
int num1;
int num2;
cout<<" Enter the first number: ";
cin>>num1;
cout<<"Enter the second number: ";
cin>>num2;
//call the function
int total = calculate_sum(num1, num2);
cout<<" The sum of num1 and num2 is: "<<total;
return 0;
}
