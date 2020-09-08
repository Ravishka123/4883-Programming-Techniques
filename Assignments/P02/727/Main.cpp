#include <iostream>
#include <stack>

using namespace std;
//function that compares the precedence
bool Precedence(char str1, char str2){
    return(str1 == '*' || str1 == '/')>=(str2=='*' || str2 == '/');
}


int main(){
    int cases;
    char str;
    stack <char> ch;
    //num of cases
    cin>> cases;
    cin.ignore(10,'\n'); //ignore line

    while(cases--){
        cin.ignore(10,'\n');//ignoe the line

//while the next line is not blank or reach -1 
        while(cin.peek()!='\n' && cin.peek()!= -1){
            //read the char
            cin>> str;
            cin.ignore(10,'\n');

//if the operator is ( we push into the stack
        if(str=='('){
            ch.push(str);
        }

        //if the operator is ) , while the top of stack is (
            //we pop the stack. then pop (
        else if(str== ')'){
            while(ch.top()!='('){
                cout << ch.top();
                ch.pop();
            }
            ch.pop();
        }

        // if the char is +,-, *, or /
        //if stack is empty we push
        else if(str=='+'|| str=='-'||str=='*'|| str =='/'){
            if(ch.empty()){
                ch.push(str);

                //we check for precedence,

            }else{
                while(!ch.empty()&& ch.top() != '(' ){
                    //if precedence is high, we pop else we do nothing and push the element to the stack
                    if(Precedence(ch.top(),str)){

                        cout << ch.top();
                        ch.pop();
                    }else{
                        break;
                    }
                }
                ch.push(str);
            }
            //if its a number, we just write to it out
        }else{
            cout<< str;
        }
        // we pop the stack until its empty
        }
        while(!ch.empty()){
            cout<<ch.top();
            ch.pop();
        }
        cout<< endl;

      if(cases)
        cout << endl;
    }
    return 0;
}