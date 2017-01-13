#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::string> GroupStr(std::vector<std::string>& strs)
{
  std::unordered_map<std::string,int> map;

  for(auto& x : strs)
  {
    auto tmp = x;
    sort(tmp.begin(),tmp.end());
    map[tmp]++;
  }

  std::vector<std::string> res;
  for(auto& x : strs)
  {
    auto tmp = x;
    sort(tmp.begin(),tmp.end());
    if(map[tmp] > 1)
    {
      res.push_back(x);
    }
  }

  return std::move(res);
}

int main()
{
  std::vector<std::string> s1 = {"abc","bca","acb","bcd","cdb","edf"};
  auto res = GroupStr(s1);
  for(auto& x : res)
  {
    std::cout<<x<<",";
  }
  std::cout<<std::endl;
  return 0;
}
