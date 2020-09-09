#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;



struct card{
char val;
char suit;
};

bool compare(card a, card b){
    if(a.val == b.val || a.suit== b.suit)
    return true;
    else
    {
        return false;
    }
    
}

int main(){
string input;
vector<stack<card>> decks;
card c_deck[52];


while(cin >> input && input != "#"){
    c_deck[0].val = input[0];
    c_deck[0].suit = input[1];

    for(int i = 1;i<52;i++){
        cin>>input;
        c_deck[i].val = input[0];
        c_deck[i].suit = input[1];
    }
  //empty the vector
  decks.clear();

    for(int j = 0; j<52;j++){
        stack <card> d;
        d.push(c_deck[j]);
        decks.push_back(d); //putting to the vector

        card temp;

        for(int k = decks.size()-1;k<decks.size();k++){
            temp = decks[k].top(); //top element of the stack
//if the position is greater than 3, we can use the third position to the left
            if(k>=3){
                //if thrid one to the left matches
                if(compare(temp,decks[k-3].top())){
                    //insert to the position
                    decks[k-3].push(temp);
                    //delete top element
                    decks[k].pop();
                    //if empty delete
                    if(decks[k].empty())
                        decks.erase(decks.begin()+k);
                        k= k-4;//go 4 positions to the left
                }
                //if its not a match, we match to the first one on the left
                else{
                    //if its a match
                    if(compare(temp, decks[k-1].top())){
                        //insert to the position
                        decks[k-1].push(temp);
                        //delete the top element
                        decks[k].pop();
                        //if empty, delete
                        if(decks[k].empty())
                        decks.erase(decks.begin()+k);

                        //new position, two to the left
                        k=k-2;
                    }

                }
            }

            //if the cards are 0-3, we compare with one to the left
            else if( k>0 && k<3){
                //compare temp with left. if it matches
                if(compare(temp, decks[k-1].top())){
                        //insert to the position
                        decks[k-1].push(temp);
                        //delete the top element
                        decks[k].pop();
                        //if empty, delete
                        if(decks[k].empty())
                        decks.erase(decks.begin()+k);

                        //new position, two to the left
                        k=k-2;
                }
            }
        }
    }


        int piles = decks.size();
        if(piles == 1){
        cout << "1 pile remaining: ";
        }
        else{
            cout << piles << " piles remaining: ";
        }
        for(int z =0; z<piles;z++){
            cout << decks[z].size();
            if(z != decks.size()-1)
            cout << ' ';
        }
        cout << endl;
}
}