struct SparseTable{
    //Modificar f con la funcion asociativa e idempotente buscada
    vector<vector<ll>> st;
    vector<ll> lg;
    ll N,K; //K = log_2(N)
    void build(vector<ll> a) {
        N = a.size(), K = 25;
        st.resize(N+5,vector<ll> (K));
        lg.resize(K+5);
        for (int i = 0; i < N; i++)
            st[i][0] = f(a[i]);
            
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = f(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

        lg[1] = 0;
        for (int i = 2; i <= N; i++)
            lg[i] = lg[i/2] + 1;
    }
    ll get(ll L, ll R) { //para minimo
        int j = lg[R - L + 1];
        return f(st[L][j], st[R - (1 << j) + 1][j]);
    }
};
