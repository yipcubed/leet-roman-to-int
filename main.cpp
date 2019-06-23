#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// makes code faster but larger
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution {
public:
    
    int romanToInt(char c) {
        switch(c) {
          case 'I' : return 1;
          case 'V' : return 5;
          case 'X' : return 10;
          case 'L' : return 50;
          case 'C' : return 100;
          case 'D' : return 500;
          case 'M' : return 1000;
          default: return 0;
        }
    }

    // Time: O(n), Space: O(1)
    int romanToInt(string s) {
        int total = 0;
        int prev = 0;
        int curr = 0;
        for (char c : s) {
          curr = romanToInt(c);
          total += curr;
          // decreasing order, need to subtract
          if (curr > prev) {
            // prev * 2 using bit shift
            total -= (prev << 1);
          }
          prev = curr;
        }
        return total;
    }
};

void test1() {
  Solution S;
  cout << "3? " << S.romanToInt("III") << endl;
  cout << "1758? " << S.romanToInt("MDCCLVIII") << endl;
  cout << "4? " << S.romanToInt("IV") << endl;
  cout << "9? " << S.romanToInt("IX") << endl;
  cout << "1994? " << S.romanToInt("MCMXCIV") << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}
