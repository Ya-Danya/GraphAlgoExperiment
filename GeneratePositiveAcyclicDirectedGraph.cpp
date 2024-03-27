#include "header.h"
#define N 100000

vector<vector <long long int>> graf(N, vector<long long int>(N));


bool dfs(int v, vector<bool>& visited, vector<bool>& recStack) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < graf.size(); ++i) {
        if (graf[v][i]) {
            if (!visited[i]) {
                if (dfs(i, visited, recStack)) {
                    // Если найден цикл, удаляем текущее ребро и возвращаем true
                    graf[v][i] = 0;
                    return true;
                }
            }
            else if (recStack[i]) {
                // Если найден цикл, удаляем текущее ребро и возвращаем true
                graf[v][i] = 0;
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

void removeCycles() {
    int V = graf.size();
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, visited, recStack);
        }
    }
}


//ed - список ребер

void GenerateRandomGraphs(long long int kol) {
    srand(N);

    vector<vector<long long int>> ed(kol, vector<long long int>(2));
    int i = 0;
    while (i < kol) {
        ed[i][0] = rand() % N + 1;
        ed[i][1] = rand() % N + 1;
        if (ed[i][0] == ed[i][1]) {
            while (ed[i][0] == ed[i][1])
                ed[i][1] = rand() % (N - 1) + 1;
        }
        else if (graf[ed[i][0] - 1][ed[i][1] - 1]) {
            while (graf[ed[i][0] - 1][ed[i][1] - 1])
                ed[i][1] = rand() % (N - 1) + 1;
        }
        //cout << "ed[" << i << "][0] = " << ed[i][0] << endl;
        //cout << "ed[" << i << "][1] = " << ed[i][1] << endl;
        graf[ed[i][0] - 1][ed[i][1] - 1] = rand() % N * N + 1; //заполняю граф 
        i++;
    }

    removeCycles();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << graf[i][j] << " ";
        }
        cout << endl;
    }
}
