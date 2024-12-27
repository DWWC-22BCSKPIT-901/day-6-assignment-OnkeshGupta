#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int node, int mask, vector<vector<int>>& tree, unordered_map<int, int>& freq, string& s, long long& result) {
    result += freq[mask]; 

    for (int i = 0; i < 26; ++i) {
        int toggledMask = mask ^ (1 << i);
        result += freq[toggledMask];
    }

    freq[mask]++;

    for (int child : tree[node]) {
        int newMask = mask ^ (1 << (s[child] - 'a'));
        dfs(child, newMask, tree, freq, s, result);
    }

    freq[mask]--;
}

long long countPalindromePaths(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<int>> tree(n);

    for (int i = 1; i < n; ++i) {
        tree[parent[i]].push_back(i);
    }

    unordered_map<int, int> freq;
    freq[0] = 1;

    long long result = 0;
    dfs(0, 0, tree, freq, s, result);

    return result;
}

int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "abacbe";

    cout << countPalindromePaths(parent, s) << endl;

    return 0;
}