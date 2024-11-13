#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Road {
public:
    int city1, city2, cost;
    Road(int city1, int city2, int cost) : city1(city1), city2(city2), cost(cost) {}
};

// Comparator to sort roads by cost
bool compareRoads(const Road &road1, const Road &road2) {
    return road1.cost < road2.cost;
}

// Union-Find (Disjoint Set) for cycle detection
class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int numCities) {
        parent.resize(numCities);
        rank.resize(numCities, 0);
        for (int i = 0; i < numCities; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int city) {
        if (parent[city] != city)
            parent[city] = find(parent[city]);
        return parent[city];
    }

    // Union by rank
    void unionCities(int city1, int city2) {
        int root1 = find(city1);
        int root2 = find(city2);

        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};

class CityNetwork {
public:
    int numCities;
    vector<Road> roads;

    CityNetwork(int numCities) : numCities(numCities) {}

    // Add a road between two cities with a specific cost
    void addRoad(int city1, int city2, int cost) {
        roads.push_back(Road(city1, city2, cost));
    }

    // Find MST using Kruskal's algorithm
    void findMinimumCostNetwork() {
        // Sort all roads by cost
        sort(roads.begin(), roads.end(), compareRoads);

        UnionFind uf(numCities);
        vector<Road> mstRoads;
        int totalCost = 0;

        // Iterate through all sorted roads
        for (Road &road : roads) {
            // Check if adding this road creates a cycle
            if (uf.find(road.city1) != uf.find(road.city2)) {
                uf.unionCities(road.city1, road.city2);
                mstRoads.push_back(road);
                totalCost += road.cost;
            }
        }

        // Display the result
        cout << "Minimum Cost to Connect All Cities: " << totalCost << endl;
        cout << "Roads included in the Minimum Cost Network:" << endl;
        for (Road &road : mstRoads) {
            cout << "City " << road.city1 << " - City " << road.city2 << " (Cost: " << road.cost << ")" << endl;
        }
    }
};

int main() {
    int numCities = 7;
    CityNetwork cityNetwork(numCities);

    // Add roads (city1, city2, cost)
    cityNetwork.addRoad(0, 1, 7);
    cityNetwork.addRoad(0, 2, 5);
    cityNetwork.addRoad(1, 2, 8);
    cityNetwork.addRoad(1, 3, 7);
    cityNetwork.addRoad(2, 4, 6);
    cityNetwork.addRoad(3, 4, 3);
    cityNetwork.addRoad(3, 5, 4);
    cityNetwork.addRoad(4, 5, 2);
    cityNetwork.addRoad(4, 6, 5);
    cityNetwork.addRoad(5, 6, 6);

    cityNetwork.findMinimumCostNetwork();

    return 0;
}
