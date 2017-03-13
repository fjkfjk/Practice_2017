#include "stdafx.h"
#include "Sorter.h"
#include <exception>

namespace {

	void swap(int& a, int& b)
	{
		int t = a;
		a = b;
		b = t;
	}

}

void Sorter::sort(int* arr, int startIdx, int endIdx)
{
	switch (mSortMethod)
	{
	case SORT_METHOD::BUBBLE:
		bubblesort(arr, startIdx, endIdx);
		break;
	case SORT_METHOD::HEAP_SORT:
		heapsort(arr, startIdx, endIdx);
		break;
	case SORT_METHOD::QUICK_SORT:
		qsort(arr, startIdx, endIdx);
		break;
	case SORT_METHOD::MERGE_SORT:
		int* temp = new int[endIdx - startIdx + 1];
		mergesort(arr, startIdx, endIdx, temp);
		delete[] temp;
		temp = nullptr;
		break;
		//default:
		//	throw new std::exception("Not support!");
	}
}


//注意，终止条件。
void Sorter::qsort(int* arr, int startIdx, int endIdx)
{
	if (startIdx > endIdx)
		return;

	int flag = arr[startIdx];

	int left = startIdx;
	int right = endIdx;

	while (left < right)
	{
		while (left < right && arr[right] >= flag)
		{
			--right;
		}
		while (left < right && arr[left] <= flag)
		{
			++left;
		}
		if (left < right)
			swap(arr[left], arr[right]);
	}

	swap(arr[startIdx], arr[left]);

	qsort(arr, startIdx, left - 1); //进行递归时不需要再包括选出来的flag数字
	qsort(arr, right + 1, endIdx);
}

void Sorter::bubblesort(int* arr, int startIdx, int endIdx)
{
	for (int i = startIdx; i < endIdx; i++)
	{
		for (int j = 0; j < endIdx - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void Sorter::heapsort(int* arr, int startIdx, int endIdx)
{
	PriorityQueue pq;
	for (int i = 0; i <= endIdx; i++)
	{
		pq.push(arr[i]);
	}
	for (int i = 0; i <= endIdx; i++)
	{
		arr[i] = pq.pop();
	}
}
void Sorter::mergesort(int* arr, int startIdx, int endIdx, int* temp)
{
	//分治完函数就结束。从而可以进入到下面的merge。
	if (startIdx < endIdx)
	{
		int mid = (startIdx + endIdx) / 2;
		mergesort(arr, startIdx, mid, temp); //当只剩一个数时，这个函数就跳出了。倒数第二步是两个数。
		mergesort(arr, mid + 1, endIdx, temp);//这一步也是只剩一个数，这个函数就会跳出。
		mergeArray(arr, startIdx, mid, endIdx, temp); //第一次进入这个函数时，是两个数，上面那两个数。
	}
}
void Sorter::mergeArray(int arr[], int start, int mid, int end, int result[])
{
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end)  //merge过程就是，逐个比较，谁小就放进去，同时对应的序号加一。
	{
		if (arr[i] < arr[j])
		{
			result[k] = arr[i];
			++i;
			++k;
		}
		else
		{
			result[k] = arr[j];
			++j;
			++k;
		}
	}
	while (i <= mid)
	{
		result[k++] = arr[i++];
	}
	while (j <= end)
	{
		result[k++] = arr[j++];
	}
	for (int n = start; n <= end; n++)
	{
		arr[n] = result[n];
	}
}

//priority queue

void PriorityQueue::push(int n)
{
	++count;
	if (count >= (int)data.size())
	{
		data.resize(count * 2);
	}
	int i = count;                               //只是用了1往后的空间，data[0]未使用。
	for (; i > 1 && data[i / 2] > n; i /= 2)   //从最后一个新建的空节点开始，对每一个父节点与n比较，如果n比较小，这个数就“下来”，最多直到倒数第二层的父节点，即根节点，最后腾出位置给n。
	{
		data[i] = data[i / 2];
	}
	data[i] = n;
}

int PriorityQueue::pop()
{
	int min = data[1];

	int x = data[1] = data[count--];
	int i = 1;
	for (; i * 2 < count; i *= 2)
	{
		int child = i * 2;
		if (data[child] > data[child + 1])
		{
			child++;
		}
		if (data[i] > data[child])
		{
			swap(data[i], data[child]);
		}
		else
		{
			break;
		}
	}
	if (i * 2 == count)
	{
		if (data[i * 2] < data[i])
		{
			swap(data[i], data[2 * 1]);
		}
	}
	return min;
}

int PriorityQueue::top()
{
	return data[1];
}
