#include <vector>
#include <ctime>		// keep this line if you want to generate different random objects for each run
#include "stuff.h"
#include "sort.h"

int main()
{
   srand(time(0));		// keep this line if you want to generate different random objects for each run
   vector<Stuff> vec;
   for (int set = 0; set < 100; set++) {

   
   for (int i = 0; i < 1000; i++)
	{
	   Stuff s;
	   vec.push_back(s);
	}

   // for (int i = 0; i < 10; i++)
	// {
	//    cout << vec[i] << endl;
	// }

   // cout << "-----\n";

   ShellSort(vec, 1);


   // for (int i = 0; i < 10; i++)
	// {
	//    cout << vec[i] << endl;
	// }

   // cout << (vec[0] < vec[1]) << endl;
   // cout << "set " << set << " ,compareCount : " << Stuff::compareCount << endl;
   cout << Stuff::compareCount << endl;
           // bool Allright = true;
           // for (int i = 0; i < vec.size() - 1; i++) {
           //    if (vec[i]<vec[i+1]) {
           //       Allright = false;
           //    }
           // }

           // cout << "Allright: " << Allright << endl;

           Stuff::compareCount = 0;
   vec.clear();
   }
   return 0;
}
