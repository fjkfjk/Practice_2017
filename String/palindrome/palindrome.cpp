/**
 * @file palindrome.cpp
 * @brief palindrome string
 * @author fangjk
 * @version 0.0.0.0
 * @date 2017-01-13
 */

#include <iostream>
#include <string>

/**
 * @brief
 *
 * @param s
 *
 * @return
 */
bool IsPalindrome(std::string s)
{
  if(s.empty())
    return true;

  int rit = s.size() - 1;

  for(int lit = 0; lit < rit; lit++)
  {
    if(s[lit] != s[rit])
      return false;
    else
      rit--;
  }

  return true;
}

int main()
{
  std::cout<<"input a string ,output if it is a palindrome.\ninput q to quit.\n";

  char s[256];
  while(*s != 'q')
  {
    std::cin.getline(s,256);
    if(IsPalindrome(std::string(s)))
    {
      std::cout<<s<<" is a palindrome."<<std::endl;
    }
    else
    {
      std::cout<<s<<" isn't a palindrome."<<std::endl;
    }
  }

  return 0;
}
