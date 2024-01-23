/*
A program that prompts the user
To enter ther name
Their year of birth
calculates the age
And returns their name and age
Utilises the use of the getline function in strings
and the cin variable
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
string name;
const int CurrentYear = 2023;
int YOB;
//Prompt the user to enter their name
cout<<"Please enter your name: ";
getline(cin,name);
//prompt user to enter their year of birth
cout<<"Enter your year of birth: ";
cin>>YOB;
//Calculate thier age based on YOB and Current year
int age = CurrentYear-YOB;
//Output name and age
cout<<"Hello, your name is "<<name<<" and you are "<<age<<" years old";
return 0;
}
