#include <iostream>
using namespace std;

int calculate_sum(int x, int y);

int main(){
int num1,num2;
cout<<"Enter the values of num1: ";
cin>>num1;
cout<<"Enter the value of num2: ";
cin>>num2;

//calling the function
int total = calculate_sum(num1, num2);
cout<<" The sum of "<< num1 << "and the sum of "<< num2 << " is " << total;
return 0;
}

//function declaration
int calculate_sum(int x, int y){
int sumValue = (x+y);
return sumValue;
}
