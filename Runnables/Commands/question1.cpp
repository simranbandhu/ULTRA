#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <ctime> 

#include "../../DataStructures/Graph/Graph.h"
#include "../../Algorithms/Dijkstra/Dijkstra.h"

int main() { 
    clock_t start_time, end_time; 
    start_time = clock(); 
    for (int i = 0; i < 200; ++i) 
    { 
        int sourceNode = std::rand() % Graph.Vertices();
        int targetNode = std::rand() % Graph.Vertices();
        
        dijkstra.run(sourceNode, targetNode); 

    } 
    end_time = clock(); 
    double runtime = double(end_time - start_time) / CLOCKS_PER_SEC; 
    std::cout << "Total runtime in seconds for 200 random Dijkstra: " << runtime << std::endl; 
    return 0; 
}