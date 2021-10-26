#include <bits/stdc++.h>
// лист бумаги n*n ч/б
//  распознать буквы 0-белый 1-черный N

using namespace std;

bool is_n(vector<vector<int>> q){
//    cout << endl;
//    for(auto &p:q) {
//        for (auto &s: p)
//            cout << s << " ";
//        cout << endl;
//    }
//    cout << endl;
    for(int i = 0; i< q.size(); i++)
        for(int j = 0; j < q.size();j++) {
            if (q[i][0] == 1 && q[i][q.size() - 1] == 1) {
                if (q[i][i] != 1)
                    return false;
            }
            else
                    return false;
            if (q[i][j] == 1 && j > 0 && i != j && j != q.size()-1)
                return false;
        }
    return true;
}


int main() {
    int n;
    cin >> n;
    int numb = 0;
    vector<vector<int>> list (n,vector<int>(n));
    for(auto &p:list)
        for(auto &q :p)
            cin >> q;
//    for(auto &p:list) {
//        for (auto &q: p)
//            cout << q << " ";
//        cout << endl;
//    }
//    cout << endl;
    int orig_s = 4;
    while(orig_s <= n){
        for(int i = 0; i <= n - orig_s; i++){
            for(int j = 0; j <= n - orig_s;j++) {
                vector<vector<int>> cop(orig_s,vector<int>(orig_s));
                for (int z = i; z < orig_s+i;z++)
                    for(int x =  j; x < orig_s+j;x++)
                        cop[z-i][x-j] = list[z][x];
                if(is_n(cop))
                    numb++;
            }
        }
        orig_s++;
    }
    cout << numb;
    return 0;
}
/*
4
1 0 0 1
1 1 0 1
1 0 1 1
1 0 0 1
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
9
1 0 0 0 0 0 0 0 1
1 1 0 0 0 0 0 0 1
1 0 1 0 0 0 0 0 1
1 0 0 1 0 0 0 0 1
1 0 0 0 1 0 0 0 1
1 0 0 0 0 1 0 0 1
1 0 0 0 0 0 1 0 1
1 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 1
8
1 0 0 1 1 0 0 1
1 1 0 1 1 1 0 1
1 0 1 1 1 0 1 1
1 0 0 1 1 0 0 1
1 0 0 1 1 0 0 1
1 1 0 1 1 1 0 1
1 0 1 1 1 0 1 1
1 0 0 1 1 0 0 1
 */