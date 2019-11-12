#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "FrameTimer.h"
#include "DotSpace.h"
#include <set>
#include "ArrayMap.h"

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{
		return lhs < rhs;
	}
};

//template<typename Map>
void print_map(std::map<std::pair<int, int>, int>& m)
{
	//std::cout << '{';
	for (auto& p : m)
		std::cout << "("<<p.first.first<<","<<p.first.second<<") " << ':' << p.second << "\n";
	std::cout << "\n";
}

struct Point_ { double x, y; };
struct PointCmp {
	bool operator()(const Point_& lhs, const Point_& rhs) const {
		return lhs.x < rhs.x; // NB. intentionally ignores y
	}
};

int main()
{
	
	FrameTimer ft;
	DotSpace d;
	float dt1 = ft.Mark();
	// METHOD 1: (inefficient): create subset of all combinations of 4 points and check each for IsRectangle
	std::cout << "METHOD 1\n";
	std::cout << "========\n";
	std::cout << "Nummber of points: " << d.GetNPoints() << std::endl;
	std::cout << "Nummber of rectangles: " << d.GetNSquares() << std::endl;
	std::cout << "Number of subsets: " << d.GetNSubsets() << std::endl;
	std::cout << "Time elapsed (s): " << dt1 << std::endl;
	

	// METHOD 2: (efficient): create a map of distinct verticals and track their occurrances along the horizontal axis
	ft.Mark();
	std::set<std::pair<int, int>> points;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			points.emplace(std::pair<int,int>( x * 10, y * 10 ));
		}
	}

	//std::map<std::pair<int, int>, int> map;
	ArrayMap<std::pair<int, int>, int> map;
	int count = 0;

	for (auto p_top : points)
	{
		for (auto p_bottom : points)
		{
			if (p_top != p_bottom)
			{
				if (p_top.first == p_bottom.first && p_top.second < p_bottom.second)
				{
					// //map.insert({ { p_top.second, p_bottom.second }, 0 });
					//std::pair<int, int> pair_y = { p_top.second, p_bottom.second };
					//count += map[pair_y];
					// //count += map.at(pair_y);
					//map[pair_y] += 1;
					std::pair<int, int> pair_y = { p_top.second, p_bottom.second };
					map.Put( pair_y, 0 );
					count += map[pair_y];
					map[pair_y] += 1;
				}
			}
		}
	}
	float dt2 = ft.Mark();
	std::cout << "\nMETHOD 2\n";
	std::cout << "========\n";
	std::cout << "Number of points: " << points.size() << std::endl;
	std::cout << "Number of rectangles: " << count << std::endl;
	//std::cout << "Map: \n"; print_map(map);
	std::cout << "Time elapsed (s): " << dt2 << std::endl;

	std::cout << "\nDIFFERENCE IN PERFORMANCE\n";
	std::cout << "dt1/dt2 = " << dt1/dt2 << std::endl;
	   
	std::cin.get();
	return 0;
}