#include "header.h"

vector<vector<int>> acyclic_undirected_graph_generate(const int& n) 
{ 
 vector <vector <int>> graph; 
 graph.resize(n); 
 for (int i = 0; i < n; i++) 
 { 
  graph[i].resize(n); 
 } 
 
 srand(time(NULL)); 
 int rare_coef = 7; //больше коэф - реже будут спавниться узлы 
 
 for (int i = 0; i < n; i++) 
 { 
  for (int j = i; j < n; j++) 
  { 
   if (i == j) 
   { 
    graph[i][j] = 0; 
    continue; 
   } 
   int flag = (rand() % 100 + 2) % rare_coef; 
   if (flag == 0) 
   { 
    int tmp = rand() % 100 + 2; 
    graph[i][j] = tmp; 
    graph[j][i] = tmp; 
 
   } 
   else 
   { 
    graph[i][j] = 0; 
    graph[j][i] = 0; 
   } 
  } 
 } 
 return graph; 
}