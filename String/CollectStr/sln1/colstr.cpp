#include <string>
#include <vector>
#include <unordered_map>
#include <stdio.h>

typedef std::unordered_map<char,int> HashMap;

bool IsBrotherStr(std::string s1,std::string s2)
{
  if(s1.empty() || s2.empty())
    return false;
  if(s1.length() != s2.length())
    return false;

  HashMap map;

  for(auto& x : s1)
  {
    if(map.count(x) == 0)
      map.emplace(x,1);
    else
      map[x]++;
  }

  for(char& x : s2)
  {
    if(map.count(x) == 0)
      return false;
    else
      map[x]--;
  }

  for(std::pair<const char,int>& x : map)
  {
    if(x.second != 0)
      return false;
  }

  return true;
}

std::vector<std::string> GroupStr(std::vector<std::string>& strs)
{
  if(strs.size() < 2)
    return strs;

  typedef std::pair<std::string,bool> StrBool;

  std::vector<StrBool> strsFlag;

  for(auto& x : strs)
  {
    strsFlag.push_back(std::make_pair(x,false));
  }

  for(int i = 0; i < strsFlag.size(); i++)
  {
    for(int j = i + 1; j < strsFlag.size(); j++)
    {
      if(IsBrotherStr(strsFlag[i].first,strsFlag[j].first))
      {
        strsFlag[i].second = strsFlag[j].second = true;
      }
    }
  }

  std::vector<std::string> res;
  for(auto& x : strsFlag)
  {
    if(x.second)
      res.push_back(x.first);
  }

  return std::move(res);
}

int main()
{
  std::vector<std::string> s1 = {"abc","bca","acb","bcd","cdb","edf"};
  auto res = GroupStr(s1);
  for(auto& x : res)
  {
    printf("%s, ",x.c_str());
  }
  printf("\n");
  return 0;
}
