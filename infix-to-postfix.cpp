#include <iostream>
#include <string>
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

bool prcd (char charAtTop, char symb)
{
          if (charAtTop == '(' || symb  == '(')
                   return false;
          if (symb == ')')
                   return true;
          if (symb == '^')
                   return false;
          if (charAtTop == '^')
                   return true;
          if ((charAtTop== '*' ||charAtTop == '/' ||charAtTop == '%') && ( symb== '*' || symb == '/' || symb == '%'))
                   return true;
          if (symb == '+' ||symb == '-')
                   return true;
          else
                   return false;
}

};

int main()
{
    cout<<"\n\n\nNOTE: The operands that you can enter are: alphabet (A-Z || a-z) or integers (0-9)"<<endl;
    S obj;
    string expression;
    string postfixExp;

    cout<<"\n\nEnter infix expreesion: ";
    cin>>expression;
    int i = 0 ;
    while(i<expression.length()){
        char symb = expression[i];
        //if(symb is an operand) , operands are alphabet A-Z or a-z or int 0-9
        if((symb >='A'&& symb <='Z')||(symb >='a'&& symb <='z')||(symb >='0'&& symb <='9'))
            postfixExp.append(1,symb);//add symb to the postfix string
        else //if symb is operation
        {
            while(!obj.isEmpty()&& obj.prcd(obj.peek(),symb)){
                char topsymb=obj.pop();
                postfixExp.append(1,topsymb);//add symb to the postfix string
            }//end while
            if(obj.isEmpty() || symb!=')')
                obj.push(symb);
            else
                obj.pop();
        }//end else

    i++;
    }//end while

    // output any remaining operators
    while(!obj.isEmpty()){
        char topsymb=obj.pop();
        postfixExp.append(1,topsymb);//add symb to the postfix string
    }
    cout<< "Postfix Expreesion is "<< postfixExp;
    return 0;
}
