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


//ע�⣬��ֹ������
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

	qsort(arr, startIdx, left - 1); //���еݹ�ʱ����Ҫ�ٰ���ѡ������flag����
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
	//�����꺯���ͽ������Ӷ����Խ��뵽�����merge��
	if (startIdx < endIdx)
	{
		int mid = (startIdx + endIdx) / 2;
		mergesort(arr, startIdx, mid, temp); //��ֻʣһ����ʱ����������������ˡ������ڶ�������������
		mergesort(arr, mid + 1, endIdx, temp);//��һ��Ҳ��ֻʣһ��������������ͻ�������
		mergeArray(arr, startIdx, mid, endIdx, temp); //��һ�ν����������ʱ��������������������������
	}
}
void Sorter::mergeArray(int arr[], int start, int mid, int end, int result[])
{
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end)  //merge���̾��ǣ�����Ƚϣ�˭С�ͷŽ�ȥ��ͬʱ��Ӧ����ż�һ��
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
	int i = count;                               //ֻ������1����Ŀռ䣬data[0]δʹ�á�
	for (; i > 1 && data[i / 2] > n; i /= 2)   //�����һ���½��Ŀսڵ㿪ʼ����ÿһ�����ڵ���n�Ƚϣ����n�Ƚ�С��������͡������������ֱ�������ڶ���ĸ��ڵ㣬�����ڵ㣬����ڳ�λ�ø�n��
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
