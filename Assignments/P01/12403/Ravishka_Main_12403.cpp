//Ravishka Rathnasuriya
//Dr.Terry Griffin
//12403 - Save Setu
// Helping Setu to save his life. Donate money and report the total. 


#include <iostream>
#include <string>
using namespace std;

int main(){
    int Total = 0, T, K; 
    string operation;
    cin >> T;
    for(int i = 0; i< T; i++){
        cin >> operation;
        if(operation == "donate"){
            cin >> K;
            Total += K;
        }
        else if (operation =="report"){
            cout << Total << '\n';
        }
        else{
            cout << "Either donate or report\n";
        }
    }

}