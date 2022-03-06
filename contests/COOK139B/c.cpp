#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>		// uncomment before submission
//#include <ext/pb_ds/tree_policy.hpp>			// uncomment before submission
//using namespace __gnu_pbds;					// uncomment before submission
using namespace std;
//<---------------------------------------------------Template----------------------------------------------------------->
#define int long long
#define ll long long
#define ld long double
const int INF = 1e18 + 7;
const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;                  // Vector of long long
typedef vector<vi> vvi;                 // Vector of vi
typedef vector<ii> vii;                 // Vector of pairs
typedef vector<vii> vvii;               // Vector of Vector of pairs
typedef vector<bool> vb;                // Vector of bool
#define pq priority_queue               // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                        // For pairs
#define ss second                       // For pairs
#define pb push_back                    // Push back to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define endl "\n"                       // Changes endl to \n
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
#define range(c, r) (c).begin(), (c).begin() + (r)                // Mainly used in sorting
#define present(c, x) ((c).find(x) != (c).end())                  // for sets, maps, multi-maps
#define cpresent(c, x) (find(all(c),x) != (c).end())              // for vectors
#define testcases(T) int (T); cin>>(T); while((T)--)              // inputing testcases
#define run(x, c) for((x)=(c).begin(); (x)!=(c).end(); (x)++)     // Mainly used by me for range based loops
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//<----------------------------------------------------------------------------------------------------------------------->

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vi a(n);
        for (int &i: a)
            cin >> i;
    
        // sort(all(a));
        vector<pair<int, pair<int, int> > > arr; 
        for (int i = 0; i < min((int)50, (int)a.size()); i++)
        {
            for (int j = 0; j < min((int)50, (int)a.size()); j++)
            {
                if (i != j)
                    arr.pb({__builtin_popcount(a[i] ^ a[j]), {i, j}});
            }
        }
        sort(all(arr));

        // for (auto i : arr)  cout << i.ff << ", ";
        // cout << endl;

        bool flag = false;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i].ff == arr[i + 1].ff)
            {
                if (arr[i].ss.ff == arr[i + 1].ss.ff
                    or arr[i].ss.ff == arr[i].ss.ss
                    or arr[i].ss.ff == arr[i + 1].ss.ss
                    or arr[i + 1].ss.ff == arr[i].ss.ss
                    or arr[i + 1].ss.ff == arr[i + 1].ss.ss
                    or arr[i].ss.ss == arr[i + 1].ss.ss
                )
                    continue;
                cout << arr[i].ss.ff + 1 << " " << arr[i].ss.ss + 1 << " " << arr[i + 1].ss.ff + 1 << " " << arr[i + 1].ss.ss + 1 << endl;
                flag = true;
                break;
            }
        }

        if (!flag)
            cout << "-1" << endl;
    }
    return 0;
}
