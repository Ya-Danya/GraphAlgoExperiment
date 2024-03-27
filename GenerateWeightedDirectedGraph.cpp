#include "header.h"

void generateWeightedDirectedGraph(std::vector<std::vector<int>>& graph, int numVertices) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> weightDist(-10, 10); // Диапазон весов

    // Инициализация графа
    graph.clear();
    graph.resize(numVertices, std::vector<int>(numVertices, 0));

    // Заполнение матрицы смежности с весами
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (i != j) {
                // Генерация веса ребра
                int weight = weightDist(gen);
                graph[i][j] = weight;
            }
        }
    }
}