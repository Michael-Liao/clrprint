#include <iostream>
#include <string> // c++ string class
#include <cstring> // strcmp
#include <cmath>
#include <cstdlib> // atoi
#include "palette.h"

using namespace std;

int main(int argc, char* argv[]) {

  Palette palette; // init w/ default constructor
  // cout<< atoi(argv[1]) <<endl;
  // handle user input (basic)
  // learn boost program options API later
  if (argc > 1) {
    if (strcmp(argv[1],"-rgb")==0) {
      palette.setRGB( atoi(argv[2]), atoi(argv[3]), atoi(argv[4]) );
    }
  }

  string input;
  getline(cin, input);
  cout<< input <<endl;
  return 0;
}
