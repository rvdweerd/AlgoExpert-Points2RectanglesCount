#ifndef _map_h
#define _map_h

template <typename KeyType, typename ValueType>
class ArrayMap
{
public:
	ArrayMap();
	~ArrayMap();
	int Size() const;
	bool IsEmpty() const;
	void Clear();
	void Put(const KeyType key, const ValueType val);
	ValueType Get(const KeyType key) const;
	bool ContainsKey(const KeyType key) const;
	ValueType& operator[](const KeyType& key)
	{
		//ValueType val = entries[FindKey(key)].value;
		//Put(key, ValueType(0) );
		//return val;
		return entries[FindKey(key)].value;
	}

private:
	void ExpandCapacity();
	int FindKey(KeyType key) const;

	// To be added:
	// 1. Removing existing map entries
	// 2. Deep copying
	// 3. Selection using square brackets
	// 4. Iterators

private:
	struct ValuePair
	{
		KeyType key;
		ValueType value;
	};
	int nCapacity;
	int nEntries;
	ValuePair* entries;
};

#include "ArrayMap.cpp"

#endif