#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

template <typename T>
void Print(std::vector<T> vec)
{
	for (T t : vec)
	{
		std::cout << t;
	}
	std::cout << std::endl;
}
struct Point
{
	int x;
	int y;
};
struct Quart
{
	Quart(std::vector<Point> q)
		:
		vec(q)
	{
	}
	std::vector<Point> vec;
};

class DotSpace
{
public:
	DotSpace()
	{
		//Default ctor creates field of 9x9 rectangles
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 10; y++)
			{
				points.emplace_back(Point{ x * 10, y * 10 });
			}
		}
		
		//Initializes the subset vector: fills it with all possible 4-point subsets
		SubSet(std::vector<Point>(0), points);
		
		//Initializes the permutation vector: fills it with all possible 4-point permutations
		//Permute(std::vector<Point>(0), points);
		
		//Performs the calculation of # of rectangles
		CountRect();
	}

	DotSpace(std::vector<Point> p)
		:
		points(p)
	{
		//Permute(std::vector<Point>(0), points);
		SubSet(std::vector<Point>(0), points);
		CountRect();
	}
	void PrintPermQuarts()
	{
		for (Quart& qt : PermQuarts)
		{
			for (Point& p : qt.vec)
			{
				std::cout << "(" << p.x << "," << p.y << "), ";
			}
			std::cout << std::endl;
		}
	}
	void PrintSubsetQuarts()
	{
		for (Quart& qt : SubsetQuarts)
		{
			for (Point& p : qt.vec)
			{
				std::cout << "(" << p.x << "," << p.y << "), ";
			}
			std::cout << std::endl;
		}
	}
	int GetNPoints()
	{
		return int(points.size());
	}

	int GetNSquares()
	{
		return nSquares;
	}
	int GetNSubsets()
	{
		return int(SubsetQuarts.size());
	}
private:
	void CountRect()
	{
		int count = 0;
		for (Quart& q : SubsetQuarts)
		{
			if (IsRect(q))
			{
				count++;
			}
		}
		nSquares = count;
	}
	void Permute(std::vector<Point> sofar, std::vector<Point> rest)
	{
		if (rest.size() == 0) //(sofar.size() == 1)
		{
			PermQuarts.emplace_back(Quart(sofar));
		}
		else
		{
			for (size_t i = 0; i < rest.size(); i++)
			{
				std::vector<Point> next = sofar;
				next.emplace_back(rest[i]);
				std::vector<Point> remaining;
				std::copy(rest.begin(), rest.begin() + i, std::back_inserter(remaining));
				std::copy(rest.begin() + i + 1, rest.end(), std::back_inserter(remaining));
				Permute(next, remaining);
			}
		}
	}
	void SubSet(std::vector<Point> sofar, std::vector<Point> rest)
	{
		//if (rest.size() == 0) 
		if (sofar.size() == 4)
		{
			SubsetQuarts.emplace_back(Quart(sofar));
		}
		else if (rest.size() == 0)
		{
			return;
		}
		else
		{
			//include 1st element, but with test if it makes a potential rectangle
			std::vector<Point> next = sofar;
			/*if (sofar.size() >= 2)
			{
				if (sofar[0].x == sofar[1].x)
				{
					if (rest[0].x != sofar[0].x && ((rest[0].y == sofar[0].y) || (rest[0].y == sofar[1].y)))
					{
						next.emplace_back(rest[0]);
					}
				}
				else if (sofar[0].y == sofar[1].y)
				{
					if (rest[0].y != sofar[0].y && ((rest[0].x == sofar[0].x) || (rest[0].x == sofar[1].x)))
					{
						next.emplace_back(rest[0]);
					}
				}
				else
				{
					if ((rest[0].x == sofar[0].x || rest[0].y == sofar[0].y) &&
						(rest[0].x == sofar[1].x || rest[0].y == sofar[1].y))
					{
						next.emplace_back(rest[0]);
					}
				}
			}
			else*/
			{
				next.emplace_back(rest[0]);
			}
			std::vector<Point> remaining;
			std::copy(rest.begin() + 1, rest.end(), std::back_inserter(remaining));
			SubSet(next, remaining);

			//exclude 1st element
			next = sofar;
			remaining.clear();
			std::copy(rest.begin() + 1, rest.end(), std::back_inserter(remaining));
			SubSet(next, remaining);
		}
	}
	bool IsRect(Quart q)
	{
		//Try to copy two Points of the Quart with (same y-coordinates && different x-coordinates) to a temp vector
		std::vector<Point> temp1;
		int y_coord = q.vec[0].y;
		int x_coord = q.vec[0].x;
		std::copy_if(q.vec.begin(), q.vec.end(), std::back_inserter(temp1), [&y_coord](Point p) {return (p.y == y_coord); });
		if (temp1.size() != 2)
		{
			return false;
		}
		if (temp1[0].x == temp1[1].x)
		{
			return false;
		}
		//check if remaining two elements have the same y-coordinates, different from the first two elements
		std::vector<Point> temp2;
		std::copy_if(q.vec.begin(), q.vec.end(), std::back_inserter(temp2), [&y_coord](Point p) {return (p.y != y_coord); });
		if (temp2.size() != 2)
		{
			return false;
		}
		if (temp2[0].y != temp2[1].y)
		{
			return false;
		}
		// check if x-coordinates of two sets are the same
		if ((temp1[0].x == temp2[0].x && temp1[1].x == temp2[1].x) ||
			(temp1[1].x == temp2[0].x && temp1[0].x == temp2[1].x))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
private:
	std::vector<Point> points;
	std::vector<Quart> PermQuarts;
	std::vector<Quart> SubsetQuarts;
	int nSquares = 0;
};

