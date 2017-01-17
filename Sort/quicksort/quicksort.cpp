
#include <iostream>

void quicksort(int* arr,int startIdx,int endIdx)
{
    if(startIdx == endIdx)
	return;
    int i = startIdx;
    int j = endIdx;
    while(i != j)
    {
	while(j > i)
	{
	    if(arr[startIdx] > arr[j])
		break;
	    else
		j--;
	}
	while(i < j)
	{
	    if(arr[startIdx] < arr[i])
		break;
	    else
		i++;
	}
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
    }	
    int tmp = arr[i];
    arr[i] = arr[startIdx];
    arr[startIdx] = tmp;
    quicksort(arr,startIdx,i);
    quicksort(arr,i+1,endIdx);
}

int main()
{
    int a[] = {2,6,0,8,89,32,24,35,66,200,1,44};
    quicksort(a,0,11);
    for(int i =0; i < 12; i++)
    {
	std::cout<<a[i]<<",";
    }
    std::cout<<std::endl;
    return 0;
}
