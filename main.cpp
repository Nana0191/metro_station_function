
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

bool isEdgeSafe(int start_node_idx, int target_node_idx) {
    int x1 = metro_stations[start_node_idx].pos_x;
    int y1 = metro_stations[start_node_idx].pos_y;
    int x2 = metro_stations[target_node_idx].pos_x;
    int y2 = metro_stations[target_node_idx].pos_y;

    for (auto const& existing_edge : metro_stations[start_node_idx].adjacent) {
        if (existing_edge.first == target_node_idx) {
            return false;
        }
    }

    for (int i = 0; i < metro_stations.size(); i++) {
        for (auto const& edge : metro_stations[i].adjacent) {

            int x3 = metro_stations[i].pos_x;
            int y3 = metro_stations[i].pos_y;
            int x4 = metro_stations[edge.first].pos_x;
            int y4 = metro_stations[edge.first].pos_y;

            if ((i == start_node_idx && edge.first == target_node_idx) ||
                (i == target_node_idx && edge.first == start_node_idx)) continue;

            long long v1 = (long long)(y2 - y1) * (x3 - x2) - (long long)(x2 - x1) * (y3 - y2);
            long long v2 = (long long)(y2 - y1) * (x4 - x2) - (long long)(x2 - x1) * (y4 - y2);
            long long v3 = (long long)(y4 - y3) * (x1 - x4) - (long long)(x4 - x3) * (y1 - y4);
            long long v4 = (long long)(y4 - y3) * (x2 - x4) - (long long)(x4 - x3) * (y2 - y4);

            if (((v1 > 0 && v2 < 0) || (v1 < 0 && v2 > 0)) &&
                ((v3 > 0 && v4 < 0) || (v3 < 0 && v4 > 0))) {
                return false;
            }
        }
    }
    return true;
}
