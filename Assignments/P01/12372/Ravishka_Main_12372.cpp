//Ravishka Rathnasuriya
//Dr.Terry Griffin
//12372 - Packing for holiday
// Helping Mr. Bean to pack his suitcase for holiday ;)


#include <iostream>
using namespace std;

int main(){
    int T, L,W,H;
    cin >> T;
    for(int i = 0; i< T; i++){
        cin >> L >> W>>H;
        cout << "Case " << i+1 << ": ";
        if(L <=20 && W <=20 && H<=20)
        cout << "good\n";
        else
        cout << "bad\n";
        
    }
   return 0;
}