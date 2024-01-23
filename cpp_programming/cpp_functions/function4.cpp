
#include <iostream>
using namespace std;

int calculate_square(int x);

int main(){
int num1;
cout<<" Enter the number you want to find its square: ";
cin>>num1;

//call the function
int squareValue = calculate_square(num1);
cout<<"The square value of "<< num1 << " is:" << squareValue;
return 0;

}
//function definition
int calculate_square(int x){
int square_value= x*x;
return square_value;
}
