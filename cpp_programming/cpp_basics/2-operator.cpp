#include <iostream>
using namespace std;

int main(){
//define varibles
char grade = 'B';
int absences = 5;

//Use OR to check for the codition called eligibility
bool eligbleForScholarship = (grade == 'A') || (absences<=3);

//check and display the results
if (eligbleForScholarship){
cout<<"Congratulations ";
}else{
cout<<"Unfortunately, you are not eligible.";
return 0;
}

}
