#include <string>
#include <stdio.h>

int GetLengthOfLongestCommonSubstr(std::string s1,std::string s2)
{
  if(s1.empty() || s2.empty())
    return 0;

  int maxLength = 0;

  for(int i = 0; i < s1.size(); i++)
  {
    int tmp = i;
    int lth = 0;
    for(int j = 0; j < s2.size(); j++)
    {
      if(s1[i] == s2[j] && i < s1.size())
      {
        i++;
        lth++;
      }
    }
    if(maxLength < lth)
      maxLength = lth;
    i = tmp;
  }

  return maxLength;
}

int main()
{
  std::string s1 = "ABCDE";
  std::string s2 = "CDEF";
  int s = GetLengthOfLongestCommonSubstr(s1,s2);
  printf("the length of longest common sub str is %d\n",s);
  return 0;
}
