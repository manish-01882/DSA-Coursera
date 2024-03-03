/* You are responsible for collecting signatures from all tenants of a certain build-
ing. For each tenant, you know a period of time when he or she is at home.
You would like to collect all signatures by visiting the building as few times as
possible.
 Given a set of n segments {[a0, b0 ], [a1 , b1 ], . . . , [an−1 , bn−1]} with integer coordinates on a line, find
the minimum number m of points such that each segment contains at least one point. That is, find a
set of integers X of the minimum size such that for any segment [ai , bi ] there is a point x ∈ X such
that ai ≤ x ≤ bi.
 */

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};
bool compareSegment(Segment i1, Segment i2){
    return (i1.end < i2.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  sort(segments.begin(), segments.end(), compareSegment);

  for(size_t j=0; j<= segments.size(); ++j){
    for(int i=1+j; i<=segments.size();++i){
        if(segments[i].start <= segments[j].end && segments[i].end >= segments[j].end){
            segments.erase(segments.begin() + i);
        }
    }
  }


  auto size = segments.size();
  for (size_t i = 0; i < segments.size(); ++i) {
    //points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}
