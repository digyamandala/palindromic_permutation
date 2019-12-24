#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*
   Based on hand-computational trial (*hah wkwk)
   every letter in palindromic string 
   will cancel out each other
   and will only return 0 OR 1 character left
   at the end
   (more like a stack LOL)

   So, i initialize map with every letter as the key
   and each value to be 0

   and for every letter in S,
   if the value of the letter in the map is still 0,
      we increment the value of the letter in the map by 1,
      and also increment the total by 1
   else, 
      we decrement the value of map by 1,
      and also decrement the total by 1

   if the total is more than 1,
      it means that there are more than 1 chars that dont have pair
      hence, there are no permutation of S which is palindromic.

   This might be the best solution so far:
      Time complexity: O(S)
      Space complexity: O(1)
*/

int *initAlphabeticalMap()
{
   //ignoring characters except alphabetical
   //..well for now

   int *c = (int *)malloc(256 * sizeof(int));
   int a = 'a', b = 'A';
   while (a <= 'z')
   {
      c[a] = 0;
      c[b] = 0;
      ++a;
      ++b;
   }
   //but we may loop through all ascii if all chars are considered
   return c;
}

string hasPalindromicPermutation(string s)
{
   int *c = initAlphabeticalMap();
   int total = 0;
   for (int i = 0; i < s.size(); i++)
   {
      int x = (int)s[i];
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
      cout << "'" << s << "'" << hasPalindromicPermutation(s) << endl;
   }

   return 0;
}