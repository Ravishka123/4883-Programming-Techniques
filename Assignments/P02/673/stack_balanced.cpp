//Ravishka Rathnasuriya
//Problem 673-Balance paranthesis
#include <iostream>
#include <stack>
#include <string>

using namespace std;
//function return true if it accepts empty string or the paranthesis are balanced.
//if not it returns false
bool balanceParanthesis(string A){
stack<char> s;
if(A == ""){
    return true;
}
else{
for(int i = 0; i <A.size();i++){
        if(A[i]=='('|| A[i] == '['){
            s.push(A[i]);
        }
        else{
            if(s.empty()){
            return false;
            
            }
            else if(A[i]==')'){
                if(s.top()=='('){
                    s.pop();

                }
                else {
                    return false;
                }
            }
             else if(A[i]==']'){
                if(s.top()=='['){
                    s.pop();

                }
                else {
                    return false;
                }
            }
        }
    
        
    }

    return s.empty();
 }
}
//Main
int main(){

    int cases;
    string A;
    cin >>cases;
    //getline for empty string. if not answer is wrong
    getline(cin,A);
    for(int j=0;j<cases;j++){
    
    getline(cin,A);
    if(balanceParanthesis(A))
    cout <<"Yes\n";
    else
    cout <<"No\n";
    }
    return 0;   
}