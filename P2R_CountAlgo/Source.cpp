#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "FrameTimer.h"
#include "DotSpace.h"
#include <set>

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{
		return lhs < rhs;
	}
};

template<typename Map>
void print_map(Map& m)
{
	std::cout << '{';
	for (auto& p : m)
		std::cout << p.first << ':' << p.second << ' ';
	std::cout << "}\n";
}

struct Point_ { double x, y; };
struct PointCmp {
	bool operator()(const Point_& lhs, const Point_& rhs) const {
		return lhs.x < rhs.x; // NB. intentionally ignores y
	}
};

int main()
{
	/*
	FrameTimer ft;
	DotSpace d;// (std::vector<Point>{ { 0, 0 }, { 10,0 }, { 10,10 }, { 0,10 }, { 30,0 }, { 30,10 }, { 10,30 }, { 30,30 }, { 0,30 }});
	float dt = ft.Mark();
	std::cout << "Nummber of rectangles: " << d.GetNSquares() << std::endl;
	std::cout << "Number of subsets: " << d.GetNSubsets() << std::endl;
	std::cout << "Time elapsed (s): " << dt << std::endl;
	*/
	/*
	std::map<char, int> first;
	first['b'] = 30;
	first['a'] = 50;
	first['c'] = 10;
	first['d'] = 70;
	std::map<char, int, classcomp> second(first.begin(), first.end());                 // class as Compare
	bool(*fn_pt)(char, char) = fncomp;
	std::map<char, int, bool(*)(char, char)> fifth(fn_pt); // function pointer as Compare
	fifth.insert(std::pair<char,int>( 's',2 ));
	fifth.insert({ 'p', 5 });
	fifth.insert({ 'p', 15 });
	fifth['p'] = 20;
	
	std::map<std::string, int> map1;
	map1["something"] = 69;
	map1["anything"] = 199;
	map1["that thing"] = 50;
	std::cout << "map1 = "; print_map(map1);
	*/

	std::set<std::pair<int, int>> points = { { 0, 0 }, { 0,10 },{ 0, 0 }, { 0,10 },{ 0, 0 }, { 0,10 } }; //{ 10,10 }, { 0,10 }, { 30,0 }, { 30,10 }, { 10,30 }, { 30,30 }, { 0,30 } };
	//for (int x = 0; x < 9; x++)
	//{
	//	for (int y = 0; y < 9; y++)
	//	{
	//		points.emplace_back(std::pair<int,int>( x * 10, y * 10 ));
	//	}
	//}
	std::map<std::pair<int, int>, int> map;
	int count = 0;

	for (auto p_top : points)
	{
		for (auto p_bottom : points)
		{
			if (p_top != p_bottom)
			{
				if (p_top.first == p_bottom.first && p_top.second < p_bottom.second)
				{
					//map.insert({ { p_top.second, p_bottom.second }, 0 });
					std::pair<int, int> pair_y = { p_top.second, p_bottom.second };
					count += map[pair_y];
					//count += map.at(pair_y);
					map[pair_y] += 1;
				}
			}
		}
	}
	true;
	
	
	
	std::cin.get();
	return 0;
}