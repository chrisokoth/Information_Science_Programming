/*Create an example of function overloading in C++.
 Define two functions with the same name but different parameter types
 , such as one for integers and one for doubles.
 */
#include <iostream>
using namespace std;

//function declarartion
int calculate_perimeter(int length, int width);// should return perimeter of rectangle
float calculate_perimeter(float radius);// should calculate perimeter of a circle

//function definition for rectangle
int calculate_perimeter(int length, int width){
return 2*(length +width);

}
// function definition for circle
float calculate_perimeter(float radius){
return 2*3.142*radius;
}
// use case
int main(){
int l;
int w;
float r;
cout<<"Enter your desired length: ";
cin>>l;
cout<<"Enter your desired width: ";
cin>>w;
cout<<"Enter your desired radius: ";
cin>>r;
int rec_perimeter= calculate_perimeter(l,w);
float circle_perimeter = calculate_perimeter(r);
cout<<"The perimeter of the rectangle is: "<<rec_perimeter;
cout<<" \nThe perimeter of the circle is: "<<circle_perimeter;
return 0;
}
