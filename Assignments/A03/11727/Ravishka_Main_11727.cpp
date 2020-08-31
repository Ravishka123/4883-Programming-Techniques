//Ravishka Rathnasuriya
//Dr.Terry Griffin
//11727 - Cost Cutting
//Laying off the employees who get the highest and lowest salaray out of 3. 


#include <iostream>
using namespace std;
int main(){
    int T, EmpA,EmpB,EmpC;
    cin >> T;
    for(int i = 0; i<T; i++){
        cin >> EmpA>> EmpB>> EmpC;
        cout << "Case " << i+1 <<": ";
       
    if((EmpA > EmpB && EmpA< EmpC) || (EmpA <EmpB && EmpA >EmpC))
        cout  << EmpA << '\n';
    else if((EmpB > EmpA && EmpB< EmpC)||(EmpB <EmpA && EmpB> EmpC))
        cout << EmpB << '\n';
    else 
        cout << EmpC <<'\n';
    }
    return 0;
}