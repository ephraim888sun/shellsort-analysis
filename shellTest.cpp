#include <vector>
#include <ctime>		// keep this line if you want to generate different random objects for each run
#include "stuff.h"
#include "ShellSort.h"

int main()
{
   srand(time(0));		// keep this line if you want to generate different random objects for each run
   vector<Stuff> vec;
   for (int set = 0; set < 100; set++) {

      for (int i = 0; i < 15000; i++)
      {
         Stuff s;
         vec.push_back(s);
      }

      ShellSort(vec, 4);

      cout << Stuff::compareCount << endl;

      Stuff::compareCount = 0;
      vec.clear();
   }
   return 0;
}
