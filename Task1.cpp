#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int user = 0;
    int computer = 0;
    cout<<"Stone paper scissor Game"<<endl;
    cout<< "1) Rock"<<endl;
    cout<< "2) Paper"<<endl;
    cout<< "3) Scissor"<<endl;
    cin >> user;

    if(user == 1)
    {
        cout<< "You choose Rock "<<endl;
    }
    else if(user == 2)
    {
        cout<< "You choose paper"<<endl;
    }
    else
    {
        cout<< "you choose scissor"<<endl;
    }

    computer = rand()%3+1;
    if(computer == 1)
    {
        cout<< "computer chooses Rock"<<endl;
    }

    else if(computer == 2)
    {
        cout<<"computer chooses paper"<<endl;
    }
    else
    {
        cout<<"computer chooses scissor"<<endl;
    }
    //match
    if(user == computer){
        cout<< "match file"<<endl;

}
//user -->rock
else if(user==1)
{
    if(computer == 2)
    {
        cout << "you lose!"<<endl;
    }
    if(computer ==3){
    cout << "you win!"<<endl;
    }
}
//user-->paper
else if(user ==2){
    if(computer == 1){
        cout<<"you win!"<<endl;
    }
    if(computer == 3){
        cout << "you lose!"<<endl;
    }
}
//user -->Scissor
else if (user == 3){
    if(computer == 1){
        cout << "you lose!" <<endl;
    }
    if( computer == 2){
        cout << "you win!"<< endl;
    }
}
return 0;
}
