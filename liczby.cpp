#include <iostream>

using namespace std;

int main()
{
  const int n = 12;
  int Los_liczby[n];
  
  int x;
  cout << "Podaj x: ";
  cin >> x;
  int y;
  cout << "Podaj y: ";
  cin >> y;
  for(int i = 0; i < n; i++){
      int losy = rand() % x + y;
      Los_liczby[i] = losy;
      cout << Los_liczby[i] << "  ";
  }
}