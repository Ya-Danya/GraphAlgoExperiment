#include "GraphAlgorithms.h"


void dijkstra_algorithm(vector<vector<int>> &W, const int &start, const int &end_node) {
    const bool &mode_default=1;
    setlocale(LC_ALL, "russian");
    int d[SIZE]; //distance - длина пути до кнокретной вершины, например для выбранной начальной будет 0.
    bool v[SIZE]; //visited - массив, где будем следить за тем, посетили мы тот или иной узел или нет.
    int path_memory[SIZE]; // - массив для запоминания пройденного пути, чтобы его потом возпроизвести

    // исходная матрица, если надо раскоментите
    /*cout << "      ";
    for (int i = 0; i < SIZE; i++)
        cout << setw(6) << i;
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(6) << i;
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(6) << W[i][j];
        }
        cout << endl;
    }
    cout << endl;*/


    for (int i = 0; i < SIZE; i++)
    {
        d[i] = INF;
        v[i] = 0;
        path_memory[i]=-2;
    }

    const int start_node = start; //индекс начальной вершины

    // Переменная в которой будет храниться индекс узла,
    // через который мы будем просматривать остальные вершины и укорачивать путь до них, если это возможно
    int curr = -1;

    path_memory[start_node] = -1; //помечаем начальную вершину
    d[start_node] = 0;

    //основная часть алгоритма
    for (int p = 0; p < SIZE - 1; p++)
    {
        int minim = INF;
        int minim_ind = -1;
        for (int i = 0; i < SIZE; i++) //поиск ближайшей вершины к текущему узлу
        {
            if (d[i] < minim && !v[i])
            {
                minim = d[i];
                minim_ind = i;
                path_memory[i] = -2;
            }
        }
        curr = minim_ind; //нашли, положим в эту переменную

        v[curr] = 1; //отмечаем узел посещенным

        if (curr != INF) {
            for (int i = 0; i < SIZE; i++) //проверяем расстояния через эту вершину и если через нее короче, то меняем на меньшее
            {
                if (W[curr][i] && W[curr][i] + d[curr] < d[i])
                {
                    d[i] = W[curr][i] + d[curr];
                    path_memory[i] = curr; //запоминаем потенциальную вершину

                }
            }
        }
    }

    if (!mode_default) {//вывод расстояний до всех вершин с путями до них, для этого 0 укажите в параметр ф-ии
        for (unsigned i = 0; i < SIZE; ++i)
        {
            if (d[i] != INF)
            {
                cout << "Вес: " << start_node << " ~> " << i << " = " << setw(6) << left << d[i] << "\t";

                unsigned end = i;
                unsigned weight = d[end];
                string way = to_string(end) + " >~ ";

                while (end != start_node)
                {
                    for (unsigned j = 0; j < SIZE; ++j)
                    {
                        if (W[j][end])
                        {
                            int temp = weight - W[j][end];

                            if (temp == d[j])
                            {
                                end = j;
                                weight = temp;
                                way += to_string(j) + " >~ ";
                            }
                        }
                    }
                }
                cout << "Путь: ";
                for (int j = way.length() - 5; j >= 0; --j)
                    cout << way[j];

                cout << endl;
            }
            else
                cout << "Вес: " << start_node << " ~ " << i << " = " << "маршрут недоступен" << endl;
        }
    }
    else //вывод как по условию
    {
        cout << "Расстояние " << start_node << " ~> " << end_node << " = " << d[end_node] << endl;
        cout << "Путь:\n";
        std::string way_r = "";
        for (int i = end_node; i != -1;)
        {
            if (path_memory[i] == -2)
            {
                cout << "Нет пути такого...\n";
                return;
            }
            if (path_memory[i] == -1)
                way_r += to_string(i);
            else
                way_r += to_string(i) + " >~ ";

            i = path_memory[i];
        }
        string way = "";
        for (int i = way_r.length() - 1; i >= 0; i--)
        {
            way.push_back(way_r[i]);
        }
        cout << way << endl;
    }
}

void greedyColoring(vector <vector <int>> &W)
{
  setlocale(LC_ALL, "russian");
  int i, j;

  vector<vector<int> > graph;
  vector<int> color;

  color.resize(SIZE);
  graph.resize(SIZE);

  //меняем формат входных данных
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (i < j) {
        if (W[i][j] != 0) {
          graph[i].push_back(j);
          graph[j].push_back(i);
        }
      }
    }
  }

  color[0] = 0;
  for (i = 1; i < SIZE; i++)
    color[i] = -1;

  bool* unused = new bool[SIZE];

  for (i = 0; i < SIZE; i++)
    unused[i] = 0;

  for (i = 1; i < SIZE; i++)
  {
    for (j = 0; j < graph[i].size(); j++)
      if (color[graph[i][j]] != -1)
        unused[color[graph[i][j]]] = true;
    int cr;
    for (cr = 0; cr < SIZE; cr++)
      if (unused[cr] == false)
        break;

    color[i] = cr;

    for (j = 0; j < graph[i].size(); j++)
      if (color[graph[i][j]] != -1)
        unused[color[graph[i][j]]] = false;
  }
  set<int> res;
  for (i = 0; i < SIZE; i++)
  {
    res.insert(color[i]);
  }
  cout << "Количество цветов: " << res.size() << endl;


  //можно раскоментить
  /*cout << endl;
  cout << "Номер вершины: ";
  for (int i = 0; i < SIZE; i++)
  {
    cout << setw(6) << i;
  }
  cout << endl;
  cout << "Номер цвета:   ";
  for (i = 0; i < SIZE; i++)
  {
    cout << setw(6) <<color[i];
  }
  cout << endl<<endl;*/

  //вывод исходной матрицы, тоже можно раскоментить
  /*cout << "      ";
  for (int i = 0; i < SIZE; i++)
    cout << setw(6) << i;
  cout << endl;
  for (int i = 0; i < SIZE; i++)
  {
    cout << setw(6) << i;
    for (int j = 0; j < SIZE; j++)
    {
      cout << setw(6) << W[i][j];
    }
    cout << endl;
  }
  cout << endl;*/
}

vector<vector<int>> Prim(vector<vector<int>> &W) {
    setlocale(LC_ALL, "russian");
    vector <vector <int>> W_RES;
    W_RES.resize(SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        W_RES[i].resize(SIZE);
        for (int j = 0; j < SIZE; j++)
        {
            W[i][j] = 0;
        }
    }

    int no_edge;
    int selected[SIZE];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    int x;
    int y;

    cout << endl;
    while (no_edge < SIZE - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < SIZE; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < SIZE; j++) {
                    if (!selected[j] && W[i][j])
                    {
                        if (min > W[i][j]) {
                            min = W[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        W_RES[x][y] = W[x][y];
        selected[y] = true;
        no_edge++;
    }

    //Можно закоментить
    cout << "Матрица остовного дерева:" << endl;
    //вывод получившегося остовного дерева минимального веса
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << W_RES[i][j] << " ";
        }
        cout << endl;
    }
    return W_RES;
}



void Kruskal(vector<vector<int>> &edges, int V) {
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int v = 0; v < V; ++v)
        parent[v] = v;

    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    vector<vector<int>> result;
    int e = 0;
    int i = 0;
    while (e < V - 1 && i < edges.size()) {
        vector<int> next_edge = edges[i++];
        int x = find(parent, next_edge[0]);
        int y = find(parent, next_edge[1]);

        if (x != y) {
            result.push_back(next_edge);
            Union(parent, rank, x, y);
            e++;
        }
    }

    cout << "Минимальное остовное дерево (рёбра и их веса):" << endl;
    for (i = 0; i < result.size(); ++i)
        cout << result[i][0] << " - " << result[i][1] << ": " << result[i][2] << endl;
}

vector<vector<int>> graphToEdges(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<vector<int>> edges;

    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    return edges;
}

void Union(vector<int> &parent, vector<int> &rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Функция для нахождения корня подмножества (для оптимизации)
int find(vector<int> &parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void floydWarshall(vector<vector<int>> &graph) {
    int V = graph.size();

    // Инициализация матрицы расстояний
    vector<vector<int>> dist(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i)
        dist[i][i] = 0;

    // Обновление расстояний
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Вывод кратчайших расстояний
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void Boruvka(vector<pair<pair<int, int>, int>> &edges, int V) {
    vector<int> parent(V);
    vector<int> cheapest(V);

    // Инициализация каждой вершины как отдельной компоненты
    for (int v = 0; v < V; ++v) {
        parent[v] = v;
        cheapest[v] = -1;
    }

    vector<pair<pair<int, int>, int>> result;
    int numTrees = V;
    int minCost = 0;

    // Пока количество компонент связности больше 1
    while (numTrees > 1) {
        // Обновляем cheapest[] для каждой компоненты
        for (int i = 0; i < edges.size(); ++i) {
            int set1 = find(parent, edges[i].first.first);
            int set2 = find(parent, edges[i].first.second);

            if (set1 == set2)
                continue;

            if (cheapest[set1] == -1 || edges[cheapest[set1]].second > edges[i].second)
                cheapest[set1] = i;

            if (cheapest[set2] == -1 || edges[cheapest[set2]].second > edges[i].second)
                cheapest[set2] = i;
        }

        // Добавляем минимальные рёбра в остовное дерево и объединяем компоненты
        for (int i = 0; i < V; ++i) {
            if (cheapest[i] != -1) {
                int set1 = find(parent, edges[cheapest[i]].first.first);
                int set2 = find(parent, edges[cheapest[i]].first.second);

                if (set1 == set2)
                    continue;

                result.push_back(edges[cheapest[i]]);
                minCost += edges[cheapest[i]].second;
                parent[set1] = set2;
                numTrees--;
            }
        }

        // Сброс cheapest для следующей итерации
        for (int i = 0; i < V; ++i)
            cheapest[i] = -1;
    }

    cout << "Минимальное остовное дерево (рёбра и их веса):" << endl;
    for (int i = 0; i < result.size(); ++i)
        cout << result[i].first.first << " - " << result[i].first.second << ": " << result[i].second << endl;
    cout << "Общий вес остовного дерева: " << minCost << endl;
}