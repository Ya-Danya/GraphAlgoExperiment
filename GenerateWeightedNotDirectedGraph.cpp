#include "header.h"

#define N 100000 // количество вершин в графе
#define edge_probability 0.001 //вероятность появления ребра

class WeightedGraph {
public:
    vector<vector<int>> adjacencyList; // Список смежности
    int V; // Количество вершин
    WeightedGraph(int vertices) : V(vertices) {
        adjacencyList.resize(V);
    }

    // Добавление ребра с весом
    void addEdge(int src, int dest, int weight) {
        adjacencyList[src].push_back(dest); // Добавляем смежную вершину
        adjacencyList[src].push_back(weight); // Добавляем вес
        adjacencyList[dest].push_back(src); // Для неориентированного графа добавляем ребро в обе стороны
        adjacencyList[dest].push_back(weight); // Добавляем вес
    }

    // Вывод графа
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "Смежные вершины с вершиной " << v << ":\n";
            for (size_t i = 0; i < adjacencyList[v].size(); i += 2) { // Шагаем по вершинам и весам
                int neighbor = adjacencyList[v][i];
                int weight = adjacencyList[v][i + 1];
                cout << " -> " << neighbor << " (вес " << weight << ")\n";
            }
            cout << endl;
        }
    }
    static WeightedGraph Create_graph(WeightedGraph graph) {
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                double random_value = (double) rand() / RAND_MAX;
                if (random_value < edge_probability) { //вероятность появления вершины в % - edge_probability * 100
                    int weight = rand() % 1000 + 1;
                    graph.addEdge(i, j, weight);
                }
            }
        }
        return graph;
    }
};