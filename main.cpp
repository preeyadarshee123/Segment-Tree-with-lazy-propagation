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
