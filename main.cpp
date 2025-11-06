#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(10);
  G.addEdge(0,9);
  G.addEdge(4, 2);
  G.addEdge(9, 2);
  G.addEdge(3, 2);
  G.addEdge(1,2);


  G.print();
  cout << "\nThe number of edges in this graph is: " << G.numEdges() << "\n";

  cout << "Count of in degrees: " << G.inDegree(2) << "\n"; //Returns 4 correctly

  cout << "RESULT: " << G.isInfluencer(1); //check with a number that is NOT the highest node lmao
  cout << "\n";
  cout << "RESULT: " << G.isInfluencer(2);//check with the highest node



}
