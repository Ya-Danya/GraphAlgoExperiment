cmake_minimum_required(VERSION 3.23)
project(GraphAlgoExperiment)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphExperiment main.cpp GraphAlgorithms.cpp GraphAlgorithms.h header.h GeneratePositiveAcyclicDirectedGraph.cpp GeneratePositiveAcyclicUndirectedGraph.cpp GenerateWeightedDirectedGraph.cpp GenerateWeightedGraph.cpp GenerateWeightedNotDirectedGraph.cpp GenerateAcyclicUndirectedGraph.cpp)