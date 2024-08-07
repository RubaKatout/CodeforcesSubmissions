#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << '[' << #x << " is: " << x << "] " << endl;
#define imod(a , n) (a % n + n ) % n

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define inF freopen("ladder.in","r",stdin );
#define outF freopen("ladder.out" , "w" , stdout ) ;
#define sor(v) sort(v.begin() , v.end());
#define print(v) for(auto f : v ) cout << f << " " ;
#define rsor(v) sort(v.rbegin() , v.rend());
#define rev(v) reverse(v.begin() , v.end());
#define scan(v) for(auto &it : v)cin >> it ;

#define logar(x , y) log(x) / log(y)
#define __sum(n) n * (n + 1) / 2
#define __lcm(a , b) a / __gcd(a , b) * b
#define pii pair<int , int >
#define ll long long
#define int ll
#define matrix vector<vector<ll>>
#define pii pair<int , int >
const int N = 1e6 + 5 , M = N * 4;
int mod = 1e9 + 7 ;
int n ;
int arr[N];

int32_t main()

{

    fastio;


    int n ;
    cin >> n ;
    vector<deque<int> > v ;
    int ans = 0 ;
    vector<pair<int , int > > toPrint;

    priority_queue<pii,vector<pii> , greater<pii> > pq ;
    for(int i = 0 ; i < n ; i ++){

        int k , a0 , x , y , m ;
        cin >> k >> a0 >> x >> y >> m ;
        v.push_back({a0});
        pq.push({a0 , i});
        while(--k){
            v.back().push_back((v.back().back() * (x % m)  + y) % m);

        }


    }

    queue<pii> tmp ;
    while(1){int pos = pq.top().second ;
            toPrint.push_back({pq.top().first , pq.top().second + 1 });
            pq.pop();
            v[pos].pop_front();
            if(v[pos].size())pq.push({v[pos][0] , pos});

        while(pq.size()){


            auto tp = pq.top();
            pq.pop();


            if( tp.first < toPrint.back().first){
                tmp.push(tp);

            }
            else {
                toPrint.push_back({tp.first , tp.second + 1});
                int pos = tp.second ;
                v[pos].pop_front();

                if(v[pos].size())pq.push({v[pos][0] , pos});

                }


        }


        if(tmp.empty())
            break;
        while(tmp.size()){
            ans ++ ;
            pq.push(tmp.front());
            tmp.pop();
        }
    }
    cout << ans << '\n';
    for(auto f : toPrint)cout << f.first << " " << f.second << '\n';

}
