# Connecting-cities
This project implements a solution to find the **Minimum Spanning Tree (MST)** for a network of cities connected by roads. Using **Kruskal's Algorithm** and the **Union-Find data structure** (also known as Disjoint Set), the program calculates the minimum cost required to connect all cities in the network without forming cycles.

### Key Components:
1. **CityNetwork Class**: Represents a network of cities and stores roads connecting them.
2. **Road Class**: Stores the endpoints (cities) and cost of each road.
3. **Union-Find Structure**: Helps manage connected components and detect cycles in the MST construction process.
4. **Kruskal’s Algorithm**: Finds the MST by sorting all roads by cost and adding them sequentially, provided they do not form cycles.

### Program Flow:
1. **Adding Roads**: Roads with specific costs are added to the network.
2. **Sorting Roads**: Roads are sorted in ascending order of cost.
3. **Building MST**: The program selects the lowest-cost roads to connect cities, ensuring all cities are connected with minimal total cost.

Finally, the program outputs the minimum cost to connect all cities and lists the selected roads that form the MST. This project demonstrates the efficient use of algorithms and data structures for optimizing connectivity in networks.
