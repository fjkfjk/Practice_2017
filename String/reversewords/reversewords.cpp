#include <string>
#include <iostream>
#include <vector>

std::string ReverseWords(const std::string& s)
{
  if(s.empty())
    return s;
  std::vector<std::string> vecs;
  std::string tmp;
  for(auto& x : s)
  {
    if(x != ' ')
    {
      tmp.push_back(x);
    }
    else if(!tmp.empty())
    {
      auto t = tmp;
      vecs.push_back(t);
      tmp.clear();
    }
  }
  if(!tmp.empty())
    tmp += " ";
  for(auto it = vecs.rbegin(); it != vecs.rend(); it++)
  {
    tmp += *it;
    tmp += " ";
  }
  tmp.pop_back();
  return std::move(tmp);
}

int main()
{
  std::string s = " the sky is mine";
  auto x = ReverseWords(s);
  std::cout<<x<<std::endl;
  return 0;
}
