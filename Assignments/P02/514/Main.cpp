//Ravishka Rathnasuriya
//Problem 514-Rails
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    //array of 1000 to store coaches
    int coaches[1000];
    stack <int> s;

    bool correct;
    int index;
    int cases;

    while(cin >> cases){
        if(cases == 0)
        break;

        while(cin >>coaches[0]){
            if(coaches[0]==0)
            break;
            //check if the stack is empty 
            while(!s.empty())
            s.pop();
            //counter and a bool exp
            index =1;
            correct = true;

            for(int i = 1; i<cases;i++)
            cin>> coaches[i];
            //if the counter and the coach is equal
            for(int j=0;j<cases;j++){
                if(coaches[j]==index){
                    index++;
                    continue;
                //if coach is greater than counter
                }else if(coaches[j]>index){
                    while(coaches[j]!=index){
                        //enter the counter value to stack(push)
                        s.push(index);
                        index++;
                    }
                    index++;
                    continue;
                    //if coach is less than counter
                }else if(coaches[j]<index){
                    //check for stack size
                    if(s.size()>0){
                        //if top element is equal to coach, we pop
                        if(s.top()==coaches[j]){
                            s.pop();
                            continue;
                        }
                    }
                    //if not its a wrong permutation
                    correct =false;
                    break;
                }
                
                
            }
            if(correct){
                cout << "Yes\n";
            }else
            {
                cout << "No\n";
            }
            

        }
        cout << endl;
    }
    return 0;
}