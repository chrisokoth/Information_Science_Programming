/*Design a C++ function that calculates the volume of a box.
Include default values for length, width, and height.
Demonstrate calling the function with and without providing specific values.

n C++, default arguments allow you to specify default values for parameters
 in a function. When the function is called, if an argument for a particular
  parameter is not provided, the default value is used
*/
#include <iostream>
using namespace std;
//function declarartion
int volume_of_box(int length= 25, int width = 20, int height = 30){
return length *width *height;

}
int main(){
cout<<"Volume is: "<<volume_of_box(100,80,250);
cout<<"\nVolume is: "<<volume_of_box();
return 0;

}

