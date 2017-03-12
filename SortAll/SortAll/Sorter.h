#pragma once
#include "ISort.h"
#include <vector>
namespace {
	void swap(int& a, int& b);
}

class Sorter : public ISort
{
public:
	explicit Sorter(SORT_METHOD sm) : mSortMethod(sm) {}
	virtual ~Sorter() {}

public:
	virtual void sort(int* arr, int startIdx, int endIdx) override;

private:
	void qsort(int* arr, int startIdx, int endIdx);
	void heapsort(int* arr, int startIdx, int endIdx);
	void mergesort(int* arr, int startIdx, int endIdx, int* temp);
	void bubblesort(int* arr, int startIdx, int endIdx);
	void mergeArray(int arr1[], int start, int mid, int end, int result[]);

private:
	SORT_METHOD mSortMethod;
};

class PriorityQueue
{
public:
	PriorityQueue() :count(0) {}
	virtual ~PriorityQueue() {}

	void push(int n);
	int pop();
	int top();

private:
	std::vector<int> data;
	int count;
};
