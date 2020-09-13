//Ravishka Rathnasuriya
//UVa Judge 540 -team queue
#include <iostream>
#include<string>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int cases;
    int group_size;
    int members;
    string str;
    int scn= 1;
    int memID;
   

    cin>> cases;

    while(cases != 0){
    vector <int> group_num(1000000); //group num of each mem is stored in the index
    queue<int> groups; //to store group nums in order
    vector<queue<int>> grp_members(1000); //group members in groups are stored in order

        
        for(int i = 0; i <cases; i++){
            cin >> group_size;
            for(int k = 0; k <group_size;k++){
                cin >> members;
                group_num[members] = i;   //grp num is stored;
            }
        
        }

        cout << "Scenario #" << scn++ << endl;
        cin >> str;
        while (str != "STOP"){
            if(str == "ENQUEUE"){
                cin >> memID;
                if(grp_members[group_num[memID]].empty()){
                    groups.push(group_num[memID]);//push the team to the queue
                }
                grp_members[group_num[memID]].push(memID);//put the member to the vector of queue[team number]
            }

           if(str == "DEQUEUE")
           {  //get the frint element of the front element of the vector
                cout<< grp_members[groups.front()].front() << endl;
                grp_members[groups.front()].pop();

                if(grp_members[groups.front()].empty()){
                    groups.pop();//pop the queue so next team is in front
                }
            }
            cin >> str;
        }

        cout << endl;
        //grp_members.clear();
        //group_num.clear();
        cin>> cases;

    }
    return 0;
}