//Ravishka Rathnasuriya
//UVA Judge - 12347 Binary Search Tree

#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

void PostOderTravesal(vector <int> A, int min, int max, int & index){

//entire vector has traversed
if(index == A.size())
return;
//element that is not in the range of the vector 
if(A[index] < min || A[index]>max)
return;

//current value.index increses to find left and right sub trees recursively
int current_value = A[index++];

//left sub tree
PostOderTravesal(A,min, current_value, index);

//right sub tree
PostOderTravesal(A, current_value, max,index);



cout << current_value << '\n';
}

int main(){
    int node_val;
    vector<int>pre_order;
    vector <int> in_order;

    while(cin>>node_val) {
        pre_order.push_back(node_val);
        in_order.push_back(node_val);

    }

    sort(in_order.begin(),in_order.end());
    int min = in_order.front();
    int max = in_order.back();
    int index = 0;
    PostOderTravesal(pre_order, min, max,index);
    
}