
#include <string>
#include <vector>
#include <math.h>
using namespace std;
const int diameter = 50;
const int radius = diameter / 2;
vector<int> bfs(int start_node_idx, int end_node_idx);
bool validNode();
struct Node
{
  int id, pos_x, pos_y;
  int used_edge1 = -1;
  int used_edge2 = -1;
  bool green = 0;
  vector<pair<int, int>> adjacent;
  string station_name;
};
vector<Node> metro_stations;
int main()
{

  return 0;
}

bool validNode(Node node)
{
  // ensure that nodes didnot exist
  bool exists = false;
  bool collide = false;
  for (int i = 0; i < metro_stations.size(); i++)
  {
    if (node.pos_x == metro_stations[i].pos_x && node.pos_y == metro_stations[i].pos_y)
    {
      exists = true;
      break;
    }
    // ensure no collision
    double distance = pow(metro_stations[i].pos_x - node.pos_x, 2) + pow(metro_stations[i].pos_y - node.pos_y, 2);

    if (distance <= pow(diameter + 10, 2))
    {
      collide = true;
      break;
    }
  }

  if (collide || exists)
    return false;
  else
    return true;
}