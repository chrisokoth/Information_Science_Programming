#include <iostream>
using namespace std;
int main(){
// declare a variable of intger type called value
int value;
//declare an array capable of holding up to 128 ints
int valueArray[128];
//define an index used to access subsequent member of the array
for (int i=0; i<128; i++){
cin>>value;
//exit the loop when the user enters a negatve number
if(value <0){
break;
}
valueArray[1] = value;
}

}
