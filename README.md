# AlgoExpert-Points2RectanglesCount
Algo challenge - dots on 2d; calculate number of rectangles

(Own O(N^3)) solution implemented</br>
* Creates a class DotSpace
* DotSpace::SubSet() recursively fills vector SubsetQuarts with all possible 4-point combinations (using struct Quart, which holds a vector of Points)
* DotSpace::CountRect() loops all Subset elements to count the # rectangles using DotSpace::IsRect() [needs major improvement]

(AlgoExpert's O(NlogN)) solution implemented</br>
* Creates a map<pair<int,int>,int> (own array-based map class implementation) of unique 2-point vertical lines
* 2x looping through all points. While filling the map, cumulattive count of rectangles
