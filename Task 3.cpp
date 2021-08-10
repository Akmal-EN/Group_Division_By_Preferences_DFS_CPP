#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

class Graph
{
public:
    int numofnodes;
    map<int, bool> visited;
    map<int, list<int>> adj;
    bool *group;

    Graph(int numofnods)
    {
        numofnodes = numofnods;
        group = new bool[numofnodes];
        for (int i = 0; i < numofnodes; i++)
        {
            group[i] = false;
        }
    }
    ~Graph()
    {
        delete group;
    }
    // function to add an edge to graph
    void addDislike(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v, bool &toggle)
    {
        if (!visited[v])
        {
            visited[v] = true;
            group[v] = toggle;
            if (toggle)
            {
                toggle = false;
            }
            else
            {
                toggle = true;
            }

            list<int>::iterator i;

            for (i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if (!visited[*i])
                {
                    DFS(*i, toggle);
                }
            }
        }
    }
};

int main()
{
    vector<int> group1, group2;
    int numberofguests = 15;
    //initializing the guests graph
    Graph guests(numberofguests);
    guests.addDislike(1, 2);
    guests.addDislike(2, 3);
    guests.addDislike(4, 5);
    guests.addDislike(7, 9);
    guests.addDislike(6, 8);
    guests.addDislike(10, 11);
    guests.addDislike(10, 12);
    guests.addDislike(13, 14);

    bool toggler = true;
    //dividing the guests by their preferences using DFS
    for (int i = 0; i < numberofguests; i++)
    {
        guests.DFS(i, toggler);
    }
    //adding to specific group for printing out later
    for (int i = 0; i < numberofguests; i++)
    {
        if (guests.group[i])
            group1.push_back(i);
        else
            group2.push_back(i);
    }
    //printing out
    std::cout << "Seating arrangement:\nTable1: ";
    for (int i = 0; i < group1.size(); i++)
    {
        std::cout << group1[i] + 1 << ", ";
    }
    std::cout << "\nTable2: ";
    for (int i = 0; i < group2.size(); i++)
    {
        std::cout << group2[i] + 1 << ", ";
    }
    std::cout << "\n";
}
