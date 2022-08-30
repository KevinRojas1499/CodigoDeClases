#include <bits/stdc++.h>
#define ll long long

using namespace std;

// Multiplicar matrices es O(n^3)

// A[][] 

vector<vector<ll>> A = {{1,1},{1,0}};

pair<ll,ll> multiplicar(vector<vector<ll>> B, pair<ll,ll> fn) {
    // devuelve A*fn
    return {
        B[0][0]*fn.first+B[0][1]*fn.second,B[1][0]*fn.first+B[1][1]*fn.second
    };
}

vector<vector<ll>> multiplicacionDeMatrices(vector<vector<ll>> B, vector<vector<ll>> C) {
    // Implementacion completa de multiplcicar matrices
    return {
        {B[0][0]*C[0][0]+B[0][1]*C[1][0], B[0][0]*C[0][1]+B[0][1]*C[1][1]},
        {B[1][0]*C[0][0]+B[1][1]*C[1][0], B[1][0]*C[0][1]+B[1][1]*C[1][1]}
    };
}

vector<vector<ll>> binaryExponentiation(vector<vector<ll>> B, ll k) {
    if(k == 0) return {{1,0},{0,1}};
    if(k == 1) return B;

    vector<vector<ll>> sqrt = binaryExponentiation(B,k/2);
    vector<vector<ll>> cuadrado = multiplicacionDeMatrices(sqrt,sqrt);
    if(k%2 == 0) return cuadrado;
    else return multiplicacionDeMatrices(cuadrado,B);
}

ll nthFibonacci(ll n) {
    vector<vector<ll>> mat = binaryExponentiation(A,n);
    for(auto row : mat){
        for(auto el : row) {
            cout<<el <<" ";
        }
        cout<<"\n";
    }
    return multiplicar(mat,{0ll,1ll}).first;
}


int main () {
    cout<< nthFibonacci(6)<<"\n";
}