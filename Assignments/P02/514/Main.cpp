//Ravishka Rathnasuriya
//Problem 514-Rails
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    //array of 1000 to store coaches
    vector <int> coaches;
    stack <int> s;
    int coach_id;

    bool correct;
    int index;
    int cases;

    while(cin >> cases){
        if(cases == 0)
        break;

        while(cin >> coach_id){
            if(coach_id==0){
            break;
            }
        
        coaches.push_back(coach_id);
        
            //check if the stack is empty 
            while(!s.empty())
            s.pop();
            //counter and a bool exp
            index =1;
            correct = true;

            for(int i = 1; i<cases;i++){
            cin>> coach_id;
            coaches.push_back(coach_id);
            }
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
        coaches.clear();
    }
    return 0;
}
