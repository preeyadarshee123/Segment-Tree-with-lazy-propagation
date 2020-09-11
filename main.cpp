#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional>
#define pb                    push_back
#define ll                    long long
#define ss                       second
#define ff                        first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define eps                   0.000000001
#define all(c)               (c).begin(),(c).end()
#define present(c,x)         ((c).find(x) != (c).end())
#define cpresent(c,x)        (find(all(c),x) != (c).end())
//#define pi                   pair<int,int>
#define pll                  pair<ll,ll>
#define endl                 '\n'
#define ull                  unsigned long long
using namespace std;
vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}

#define debug(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}

inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<string>::iterator it) { cerr << endl; }

template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cerr << "; ";
    __evars(++it, args...);
}
//using namespace __gnu_pbds;
//typedef tree<int, null_type, int>, rb_tree_tag,tree_order_statistics_node_update> policy;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef vector< int > vi;
typedef vector< vi > vvi;
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,-1,1,2,-2,2,-2};
vector<int> vis(200010,0),dis(200010,0),par(200010,0),ed(200010,0);
vector<pair<int,int>> adj[200010];
vector<vector<int>> ad;
int myrandom (int i) { return std::rand()%i;}
const int MAX=200010;
const ull inf = 1000000007;
class SegTree{
    public :
    vector<ll> t;
    vector<ll> d;
    void initialize(int sz){
        t.resize(4*sz);
        d.resize(4*sz);
    }
    void build(int v,int l,int r,vector<int> &a){
        if(l==r){
            t[v]=a[l];
            return ;
        }
        int mid=(l+r)/2;
        build(2*v,l,mid,a);
        build(2*v+1,mid+1,r,a);
        t[v]=max(t[2*v],t[2*v+1]);
    }
    void push(int v,int l,int r){
        t[v] += d[v];
        if(l!=r){
            d[2*v] += d[v];
            d[2*v+1] += d[v];
        }
        d[v] = 0;
    }
    void upd(int v,int l,int r,int a,int b){
        push(v,l,r);
        if(l>r||l>b||r<a){
            return ;
        }
        if(l>=a&&r<=b){
            d[v] += 1;
            push(v,l,r);
            return ;
        }
        int mid=(l+r)/2;
        upd(2*v,l,mid,a,b);
        upd(2*v+1,mid+1,r,a,b);
        t[v]= max(t[2*v] , t[2*v+1]);
    }
    ll query(int v,int l,int r,int val){
        push(v,l,r);
        if(l == r){
            return l;
        }
        int mid=(l+r)/2;
        push(2*v+1,mid+1,r);
        push(2*v,l,mid);
        if(t[2*v+1] == val){
            return query(2*v+1, mid+1, r, val);
        }
        else{
            return query(2*v, l, mid, val);
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin;
    //ofstream fout;
    //fin.open("input.txt");
    //fout.open("output.txt");
    //clock_t launch=clock();
    
}
