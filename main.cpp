#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> initAlphabeticalMap()
{
   map<char, int> c;
   int a = 'a';
   int b = 'A';
   while (a <= 'z')
   {
      c[a] = 0;
      c[b] = 0;
      ++a;
      ++b;
   }
   return c;
}

string hasPalindromicPermutation(string s)
{
   map<char, int> c = initAlphabeticalMap();
   int total = 0;
   for (int i = 0; i < s.size(); i++)
   {
      char x = s[i];
      if (x != ' ')
      {
         if (c[x] > 0)
         {
            --c[x];
            --total;
         }
         else
         {
            ++c[x];
            ++total;
         }
      }
   }

   if (total > 1)
      return " is not palindromic-permutable";

   return " is palindromic-permutable";
}

int main()
{
   int testCase;
   string s;

   cin >> testCase;
   cin.ignore(256, '\n');

   for (int i = 0; i < testCase; i++)
   {
      getline(cin, s);
      cout << s << hasPalindromicPermutation(s) << endl;
   }

   return 0;
}