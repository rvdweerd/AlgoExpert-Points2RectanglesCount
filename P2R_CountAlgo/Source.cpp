#include <iostream>
#include <vector>
#include <algorithm>
#include "FrameTimer.h"
#include "DotSpace.h"


int main()
{
	
	FrameTimer ft;
	DotSpace d;// (std::vector<Point>{ { 0, 0 }, { 10,0 }, { 10,10 }, { 0,10 }, { 30,0 }, { 30,10 }, { 10,30 }, { 30,30 }, { 0,30 }});
	float dt = ft.Mark();
	std::cout << "Nummber of rectangles: " << d.GetNSquares() << std::endl;
	std::cout << "Number of subsets: " << d.GetNSubsets() << std::endl;
	std::cout << "Time elapsed (s): " << dt << std::endl;
	

	

	std::cin.get();
}