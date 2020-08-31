//Ravishka Rathnasuriya
//Dr.Terry Griffin
//11498 - Division of Nlogonia
//Dividing the land into 4 independent territories.

#include <iostream>

using namespace std;

int main(){
    int K, N, M, X,Y;

    cin>> K;
    while(K!=0){
        cin >> N>>M;
        for(int i = 0; i < K; i++){
            cin >>X>>Y;

            if(X>N && Y>M)
            cout << "NE\n";
            else if (X<N && Y>M)
            cout << "NO\n";
            else if(X>N && Y<M)
            cout << "SE\n";
            else if(X<N && Y<M)
            cout << "SO\n";
            else
            cout << "divisa\n";
            
        }
        cin >> K;
    }
    return 0;
}
