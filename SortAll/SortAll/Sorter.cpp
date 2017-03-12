#include "stdafx.h"
#include "Sorter.h"
#include <exception>

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
		mergesort(arr, startIdx, endIdx,temp);
		delete[] temp;
		temp = nullptr;
		break;
	//default:
	//	throw new std::exception("Not support!");
	}
}

void Sorter::swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
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

}
void Sorter::mergesort(int* arr, int startIdx, int endIdx,int* temp)
{
	//�����꺯���ͽ������Ӷ����Խ��뵽�����merge��
	if (startIdx < endIdx)
	{
		int mid = (startIdx + endIdx) / 2;
		mergesort(arr, startIdx, mid,temp); //��ֻʣһ����ʱ����������������ˡ������ڶ�������������
		mergesort(arr, mid + 1, endIdx,temp);//��һ��Ҳ��ֻʣһ��������������ͻ�������
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
