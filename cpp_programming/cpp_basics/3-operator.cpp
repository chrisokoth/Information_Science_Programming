#include <iostream>
using namespace std;

int main(){
//decalre the variable
bool isSunny=false;
//use NOT to reverse false value
bool isRainny = !isSunny;

//display the result
if (isRainny){
cout<<"Dont forget your umbrella!";
}else{
cout<<"Perfect day to go for outing";
}
return 0;

}
