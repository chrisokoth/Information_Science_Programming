// create a function that returns the perimeter of a rectangle
#include<iostream>
using namespace std;
// declare the function
int perimeter_of_rectangle(int length, int width);
//define the function
int perimeter_of_rectangle(int length, int width){
return 2*(length+width);

}
int main(){
//example usage
int length = 5;
int width = 3;
//calling a function
int perimeter =perimeter_of_rectangle(length, width);
cout<<"The perimeter of the rectangle is: "<<perimeter;
return 0;
}















































