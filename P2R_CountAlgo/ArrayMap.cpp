#ifdef _map_h

//#pragma once
//#include "error.h"

static constexpr int INITIAL_CAPACITY = 1;

template <typename KeyType, typename ValueType>
ArrayMap<KeyType, ValueType>::ArrayMap()
	:
	nCapacity(INITIAL_CAPACITY),
	nEntries(0)
{
	entries = new ValuePair[INITIAL_CAPACITY];
}

template <typename KeyType, typename ValueType>
ArrayMap<KeyType, ValueType>::~ArrayMap()
{
	delete entries;
	entries = nullptr;
	nCapacity = 0;
	nEntries = 0;
}

template <typename KeyType, typename ValueType>
int ArrayMap<KeyType, ValueType>::Size() const
{
	return nEntries;
}

template <typename KeyType, typename ValueType>
bool ArrayMap<KeyType, ValueType>::IsEmpty() const
{
	return nEntries == 0;
}

template <typename KeyType, typename ValueType>
void ArrayMap<KeyType, ValueType>::Clear()
{
	nEntries = 0;
}

template <typename KeyType, typename ValueType>
void ArrayMap<KeyType, ValueType>::Put(const KeyType key, const ValueType val)
{
	int index = FindKey(key);
	if ( index == -1 )
	{
		if (nEntries == nCapacity)
		{
			ExpandCapacity();
		}
		entries[nEntries] = { key , val };
		nEntries++;
	}
	else
	{
		//entries[index] = { key , val };
	}
}

template <typename KeyType, typename ValueType>
ValueType ArrayMap<KeyType, ValueType>::Get(const KeyType key) const
{
	int index = FindKey(key);
	if (index == -1)
	{
		std::cout<<"Error, no key present.\n";
	}
	else
	{
		return entries[index].value;
	}
}

template <typename KeyType, typename ValueType>
bool ArrayMap<KeyType, ValueType>::ContainsKey(const KeyType key) const
{
	if (FindKey(key) == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <typename KeyType, typename ValueType>
void ArrayMap<KeyType, ValueType>::ExpandCapacity()
{
	ValuePair* entries_old = entries;
	nCapacity *= 2;
	entries = new ValuePair[nCapacity];
	for (int i = 0; i < nEntries; i++)
	{
		entries[i] = entries_old[i];
	}
	delete entries_old;
	entries_old = nullptr;
}

template <typename KeyType, typename ValueType>
int ArrayMap<KeyType, ValueType>::FindKey(KeyType key) const
{
	for (int i = 0; i < nEntries; i++)
	{
		if (entries[i].key == key)
		{
			return i;
		}
	}
	return -1;
}

#endif