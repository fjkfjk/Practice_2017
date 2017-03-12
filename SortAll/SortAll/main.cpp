#include "stdafx.h"
#include "Sorter.h"
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
	ISort* sorter = new Sorter(SORT_METHOD::MERGE_SORT);
	int arr[7]{ 2,5,8,1,-5,9,6 };
	sorter->sort(arr,0,6);
	for (int& x : arr)
	{
		std::cout << x << " ";
	}
	std::this_thread::sleep_for(std::chrono::seconds(4));
	return 0;
}