//Ravishka Rathnasuriya
//11988-Broken Keyboard (Beiju Text)
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main(){
string text; 
queue<char> A;
stack<string> store;

while(getline(cin,text)){
    char c = 'N'; //An indicator
    string tmp = ""; //temperary string

    while(!store.empty())
    store.pop(); //clear stack

    while(!A.empty())
    A.pop(); ///clear queue


    for(int i = 0; i < text.length();i++){
        if(text.at(i)=='['){
            c = 'A';  
        }
       //if its a [ and text reaches ] we push the temp string to stack
        if(c == 'A'){
            if(text.at(i)==']'){
                if(tmp !="")
                    store.push(tmp);
                    tmp = "";
                    c='N';
            }
            //if its a [ and text reaches another [ we push the old string to stack
            else{
                if(text.at(i) == '['){
                    if(tmp != "")
                    store.push(tmp);
                    tmp= "";
                    c= 'A';
                }
                else{ //if not we add the temp string till the indicator value changes
                    tmp += text.at(i);
                }
            }
            
        } //if not [ OR ] then add each character to the queue
        else{
            if(text.at(i)!= '[' && text.at(i) != ']')
                A.push(text.at(i));
            }
        

    }
    if(c=='A')
        store.push(tmp);
        tmp = "";
    while(!store.empty()){
        cout << store.top(); //print the stack with the beiju texts
        store.pop();
    }
    //cout << endl;
    while(!A.empty()){
        cout << A.front(); // then queue with remaining characters
        A.pop();
    }
    cout << endl;
    tmp= "";
}

}