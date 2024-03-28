#include <iostream>
#include <vector>
#define Raz 100000

using std::vector;
using std::endl;
using std::cout;

vector<vector <int>> ag(Raz, vector<int>(Raz));

bool dfs(int v, vector<bool>& visited, vector<bool>& rs);

void RC() {
    int V = ag.size();
    vector<bool> visited(V, false);
    vector<bool> rs(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, visited, rs);
        }
    }
}

bool dfs(int v, vector<bool>& visited, vector<bool>& rs) {
    visited[v] = true;
    rs[v] = true;

    for (int i = 0; i < ag.size(); ++i) {
        if (ag[v][i]) {
            if (!visited[i]) {
                if (dfs(i, visited, rs)) {
                    ag[v][i] = 0;
                    return true;
                }
            }
            else if (rs[i]) {
                ag[v][i] = 0;
                return true;
            }
        }
    }

    rs[v] = false;
    return false;
}

void DAGraph(int kol) {
    srand(Raz);

    vector<vector<int>> ed(kol, vector<int>(2));
    int i = 0;
    while (i < kol) {
        ed[i][0] = rand() % Raz + 1;
        ed[i][1] = rand() % Raz + 1;
        if (ed[i][0] == ed[i][1]) {
            while (ed[i][0] == ed[i][1])
                ed[i][1] = rand() % (Raz - 1) + 1;
        }
        else if (ag[ed[i][0] - 1][ed[i][1] - 1]) {
            while (ag[ed[i][0] - 1][ed[i][1] - 1])
                ed[i][1] = rand() % (Raz - 1) + 1;
        }
        ag[ed[i][0] - 1][ed[i][1] - 1] = rand() % Raz * Raz + 1;
        i++;
    }

    RC();

    for (int i = 0; i < Raz; i++) {
        for (int j = 0; j < Raz; j++) {
            cout << ag[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    DAGraph(Raz);
}
