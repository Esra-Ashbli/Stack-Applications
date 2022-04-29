
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define size 60

class S{
private:
    int Top=-1;
    char Stack[size];//char *Stack;
    //int size=60;
public:
    /*S(){
        Stack = new char[size];
        Top = -1;
    }*/

bool isEmpty(){
    if(Top==-1)
        return true;
    else
        return false;
}

bool isFull(){
    if (Top ==size)
        return true;
    else
        return false ;
}

void push(char item){
    if(isFull())
        cout<<"Overflow\n";
    else
        Stack[++Top]=item;
}


char pop(){
    if (isEmpty()){
        cout <<"Underflow\n";
        return 0;
        }
    else
        return Stack[Top--];
}
/*
char peek(){
    if (isEmpty())
        cout << "stack underflow";
    else{
        return Stack[Top];
    }
}

void traverse (){
    if(isEmpty())
        cout <<"The stack is Empty \n";
    else
        for(int i=0;i<=Top;i++)
            cout<<Stack[i]<<" ";
    cout<<endl;
}
*/

};
int result(int operand1,int operand2,char symb){

    switch(symb){
    case '+':
        return operand1+operand2;
        break;
    case '-':
        return operand1-operand2;
        break;
    case '*':
        return operand1*operand2;
        break;
    case '/':
        return operand1/operand2;
        break;
    case '^':
        return pow(operand1,operand2);
        break;
    case '%':
        return operand1%operand2;
        break;
    }
}

int main()
{
    cout<<"\n\nNOTE: the operands you can use they are just integers (0-9), because we will evaluate it \n\n\n";
    S obj;
    int operand1, operand2, value;
    string postfixExpression;
    cout<<"Enter the Postfix Expression:  ";
    cin>>postfixExpression;
    int i = 0 ;
    while(i<postfixExpression.length()){
        char symb = postfixExpression[i];
        if(symb >= '0' && symb <= '9')//if symb is an operand, push it and convert it to int
            //to convert char into int (a - '0')
            obj.push(symb-'0');
        else{
            //if symb is an operator
            operand2=obj.pop();
            operand1=obj.pop();
            value=result(operand1,operand2,symb);
            obj.push(value);

        }//end else


        i++;
    }//end while

    return (obj.pop());

}
