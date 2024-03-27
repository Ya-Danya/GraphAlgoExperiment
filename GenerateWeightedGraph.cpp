#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

#define N 10000 // количество вершин в графе
#define edge_probability 0.001 // вероятность появления ребра

using namespace std;
using namespace std::chrono;

class WeightedGraph {
public:
    vector<vector<int>> adjacencyList; // Список смежности
    int V; // Количество вершин
    WeightedGraph(int vertices) : V(vertices) {
        adjacencyList.resize(V);
    }

    // Добавление ребра
    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest); // Добавляем смежную вершину
        adjacencyList[dest].push_back(src); // Для неориентированного графа добавляем ребро в обе стороны
    }

    // Создание графа
    static vector<vector<int>> CreateGraph() {
        WeightedGraph graph(N);
        srand(time(0)); // Инициализация генератора случайных чисел

        // Добавление случайных рёбер
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                double random_value = (double)rand() / RAND_MAX;
                if (random_value < edge_probability) { // Вероятность появления ребра в %
                    graph.addEdge(i, j);
                }
            }
        }
        return graph.adjacencyList;
    }
};