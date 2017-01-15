
#include <vector>
#include <iostream>

namespace CHECK
{
  class No { bool b[2]; };
  template<typename T, typename Arg> No operator== (const T&, const Arg&);

  bool Check (...);
  No& Check (const No&);

  template <typename T, typename Arg = T>
  struct EqualExists
  {
    enum { value = (sizeof(Check(*(T*)(0) == *(Arg*)(0))) != sizeof(No)) };
  };
}

template<class T>
int RemoveElement(std::vector<T>& vec,const T& ele)
{
  if((int)CHECK::EqualExists<T>::value == 0)
    return -1;
  for(auto it = vec.begin(); it != vec.end();)
  {
    if(*it == ele)
      it = vec.erase(it);
    else
      it++;
  }
  return vec.size();
}

int main()
{
  std::vector<int> vec = {0,1,1,1,3,2,0};
  int l = RemoveElement(vec,1);
  std::cout<<"the new length is "<<l<<std::endl;
  return 0;
}
