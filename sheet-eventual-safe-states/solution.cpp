#include <bits/stdc++.h>
using namespace std;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); i++) os << (i ? ", " : "") << v[i];
    return os << "]";
}

vector<long long> eventualSafeNodes(long long n, vector<vector<long long>> edges) {
    // TODO: write your solution here
    vector<vector<int>> reverse (n);
    vector<int>out(n,0);
    for(auto& e : edges){
        reverse[e[1]].push_back(e[0]);
        out[e[0]]++;
    }
    queue<int>q; 
    for(int i = 0 ; i < n ; i++){
        if(out[i] == 0) q.push(i);
    }
        vector<bool>safe(n,false);
        while(!q.empty()){
            int v = q.front(); 
            q.pop(); 
            safe[v] = true; 
            for(int u : reverse[v]){
                if(--out[u] == 0 ) q.push(u);
            }
        }
    vector<long long>answer; 
    for(int i = 0 ; i < n ; i++){
        if(safe[i]) answer.push_back(i);
        
    }
    return answer;
}

int main() {
    cout << eventualSafeNodes(7, vector<vector<long long>>{vector<long long>{0, 1}, vector<long long>{0, 2}, vector<long long>{1, 2}, vector<long long>{1, 3}, vector<long long>{2, 5}, vector<long long>{3, 0}, vector<long long>{4, 5}}) << endl;
    return 0;
}
