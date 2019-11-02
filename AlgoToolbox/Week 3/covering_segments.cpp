#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct Segment
{
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  auto compare = [](auto a, auto b) { return a.start < b.start; };
  sort(segments.begin(),segments.end(),compare);
  priority_queue<Segment, vector<Segment>, function<bool(Segment, Segment)>> pq(compare);
  for (auto i : segments)
  {
    if (pq.empty() || pq.top().end < i.start)
    {
      pq.emplace(i);
    }
    else
    {
      auto t = pq.top();
      pq.pop();
      Segment s;
      s.start = max(i.start, t.start);
      s.end = min(i.end, t.end);
      pq.emplace(s);
    }
  }
  while (!pq.empty())
  {
    points.emplace_back(pq.top().end);
    pq.pop();
  }
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
