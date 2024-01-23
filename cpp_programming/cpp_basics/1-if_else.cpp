// A program that prompts the user for the current weather and uses the if statement to return the condition status

#include <iostream>
using namespace std;

int main(){
int temp;
cout<<"Enter the current temperature: ";
cin>>temp;
if (temp> 25){
cout<<"It\'s hot wear sunscreen";
}else if(temp <14){
cout<<"It\'s cold wear a jacket";
}else{
cout<<"Enjoy the weather";
}
return 0;
}
