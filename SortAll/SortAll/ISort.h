#pragma once
enum class SORT_METHOD
{
	QUICK_SORT = 0,
	BUBBLE,
	HEAP_SORT,
	MERGE_SORT
};
class ISort abstract
{
public:
	virtual void sort(int* arr,int startIdx,int endIdx) = 0;
};