#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> per;
struct dominoT {
    int leftDots;
    int rightDots;
};
void permutations (vector<pair<int , int>> pieces) {
    do {
        per.push_back(pieces);
    } while (next_permutation(pieces.begin(), pieces.end()));
}
bool formsDominoChain () {
    for (auto & i : per) {
        bool flag = true;
        for (int j = 0; j < i.size() - 1; j++) {
            if (i[j].second != i[j + 1].first) {
                flag = false;
                break;
            }
            if (flag) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    vector<pair<int,int>> g {{1,2},{2,3},{3,4},{6,5},{4,6}};
    permutations(g);
    cout<<formsDominoChain()<<endl;

    return 0;
}