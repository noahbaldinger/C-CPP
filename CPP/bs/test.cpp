#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


struct test {
  int testNum;
  string testStr;
};


int main() {
  // Shorthand if statements
  int time = 22;
  cout << ((time < 12) ? "Good Day" : (time < 18) ? "Good Afternoon" : "Good Night") << "\n";

  //size and length of array
  int myNumbers[5] = {10, 20, 30, 40, 50};
  cout << "Number of items in array: " <<  (sizeof(myNumbers) / sizeof(myNumbers[0]));

  //structs
  test MyTest1;
  MyTest1.testNum = 15;
  MyTest1.testStr = "Test";
  cout << "\n" << MyTest1.testNum;
  return 0;
}