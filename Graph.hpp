#include <iostream>
#include <vector>
#include <stdexcept>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    int numEdges() const {

        int count = 0;
        //Pretty simple logic, just iterate over the matrix nxn times and if its a one, it means there is an edge.

        for(int i = 0; i < numVertices; i++)
        {
            for(int j = 0; j < numVertices; j++)
            {
                if(adjMatrix[i][j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }

    // Completa esta función
    // Devuelve el in-degree de un vertice
    int inDegree(int u) const {

        int degree_n = 0;

        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        else{
              for(int i = 0; i <numVertices; i++)
              {
                if(adjMatrix[i][u] == 1)
                {
                    degree_n++;
                }
              }
            }
        
        return degree_n;
    }
        

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) const  {

    std::pair<int,int> list_tracker; 
    int max;

    if (u < 0 || u >= numVertices)
    {
        throw std::out_of_range("Vertice fuera de rango");
    }
    else
    {
        
        for(int i = 0; i < numVertices; i++)
        {
            max = 0; //Just to keep track of the max ones in everyt iteration
            for(int j = 0; j < numVertices; j++)
            {
                if(adjMatrix[j][i] == 1)
                    max++; //update as I find the ones
            }

            if(max > list_tracker.second) //keep track of the highest and put it in the pair
            {
                list_tracker.first = i;
                list_tracker.second = max;
            }
        }
        return list_tracker.first == u; //check if the first number of the pair, which is the index, is equal to the node requested.
    }
}

};

