#pragma once
#include "ISort.h"

class Sorter : public ISort
{
public:
	explicit Sorter(SORT_METHOD sm) : mSortMethod(sm) {}
	virtual ~Sorter() {}

public:
	virtual void sort(int* arr,int startIdx,int endIdx) override;

private:
	void qsort(int* arr,int startIdx,int endIdx);
	void heapsort(int* arr,int startIdx, int endIdx);
	void mergesort(int* arr,int startIdx, int endIdx,int* temp);
	void bubblesort(int* arr,int startIdx, int endIdx);
	void swap(int& a, int& b);
	void mergeArray(int arr1[], int start,int mid,int end,int result[]);

private:
	SORT_METHOD mSortMethod;
};