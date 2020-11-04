#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

#define size 100
int inputMatrix[size][size];
int sumArr[size];

int KadaneAlgo(int ite){
    int end, currentMax, Max = INT_MIN;

    for(int i = 0 ; i < ite; i++ ){

        memset(sumArr, 0, ite*sizeof(int));

        for(int k = i; k < ite; k++){
            end = 0; 
            currentMax = INT_MIN;

            for(int m = 0; m < ite; m++){
                sumArr[m] += inputMatrix[k][m];
                end = max(0,end+ sumArr[m]);
                currentMax = max(currentMax,end);
            }
            Max = max(Max,currentMax);
        }
    }
    return Max;
}

int main(){
    int num;
    cin >> num;

    for(int i = 0; i < num ; i++){
        for(int j = 0; j < num ; j++){
            cin >> inputMatrix[i][j];
        }
    }
    cout << KadaneAlgo(num);
    cout << endl;
    return 0;
}