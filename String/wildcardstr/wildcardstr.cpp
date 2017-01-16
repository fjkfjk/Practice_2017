/**
 * @file wildcardstr.cpp
 * @brief wildcard 2 strings
 * for example,
 * abc,a*, return true;
 * abc,ab?,return true;
 * abc,a?*,return true;
 * abc,c*,return false;
 * @author fangjk
 * @version 0.0.0.0
 * @date 2017-01-14
 */


#include <string>
#include <iostream>

bool IsMatched(const std::string& s,int si,const std::string& p,int pi)
{
  if(si == s.size() || pi == p.size())
  {
    if(si == s.size() && pi == p.size())
    {
      return true;
    }
  }
  if(s[si] == p[pi] || p[pi] == '?')
  {
    return IsMatched(s,si + 1,p,pi + 1);
  }
  if(p[pi] == '*')
  {
    if(pi + 1 == p.size())
    {
      return true;
    }
    else
    {
      if(IsMatched(s,si + 1,p,pi + 1))
      {
        return true;
      }
      else
      {
        return IsMatched(s,si + 1,p,pi);
      }
    }
  }
}

std::string Distinct(const std::string& s)
{
  std::string st = s;
  for(auto it = st.begin() + 1; it != st.end();)
  {
    if(*it == '*' && *(it-1) == '*')
    {
      it = st.erase(it);
    }
    else
    {
      it++;
    }
  }
  return std::move(st);
}

bool IsMatched(const std::string& s,const std::string& p)
{
  std::string pt = Distinct(p);
  return IsMatched(s,0,p,0);
}

int main()
{
  std::string s1 = "abcdef";
  std::string s2 = "a**?*f";
  if(IsMatched(s1,s2))
  {
    std::cout<<"wildcard matches success!"<<std::endl;
  }
  else
  {
    std::cout<<"wildcard matches failed!"<<std::endl;
  }
  return 0;
}
