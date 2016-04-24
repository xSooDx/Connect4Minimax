#include "Human.h"
#include <iostream>

using namespace std;

Human::Human(char c)
{
    color=c;
}

void Human::makeMove(Board* b)
{
    int m;

    cout<<"Enter Move(1-7)";
    cin>>m;
    m=m-1;
    if(b->isLegal(m))
        b->place(m,color);

}

Human::~Human()
{
    //dtor
}
