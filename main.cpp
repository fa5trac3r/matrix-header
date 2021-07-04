#include<bits/stdc++.h>
#include"matrix.h"

using namespace std;


int main()
{
    Matrix mat(5,5,100);
    mat.print();
    mat.set(0,0,20);
    auto dia=mat.diagonal();
    for(auto i:dia)
        cout<<i<<" ";
    return 0;
}
