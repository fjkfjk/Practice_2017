/**
 * @file findmidnum.cpp
 * @brief find the middle numer of an array
 * For example:
 * (1,5,3,6,8,4),return 4
 *
 * @author fangjk
 * @version 0.0.0.0
 * @date 2017-01-17
 */

#include <iostream>

int quickSort(int arr[],int left,int right)
{
  if(left == right)
    return arr[left];

  int i =left;
  int j= right;

  while(i != j)
  {
    while(i < j)
    {
      if(arr[left] < arr[j])
        break;
      else
        j--;
    }
    while(i < j)
    {
      if(arr[left] > arr[i])
        break;
      else
        i++;
    }
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
  }
  int k = arr[left];
  arr[left] = arr[i];
  arr[i] = k;
  if(i == (right - left + 1) / 2)
  {
    return arr[i];
  }
  return quickSort(arr,left,i);
  return quickSort(arr,i+1,right);
}

int findMidNum(int arr[],int length)
{
  if(length < 3)
    return arr[0];
  return quickSort(arr,0,length - 1);
}

int main()
{
  int arr[] = {2,7,19,47,6,-3,28,99,66};
  std::cout<<"The array is: ";
  for(int i = 0; i < 9; i++)
  {
    std::cout<<arr[i]<<",";
  }
  std::cout<<std::endl;
  std::cout<<"The middle number of the array is "<<findMidNum(arr,9)<<std::endl;
  return 0;
}
