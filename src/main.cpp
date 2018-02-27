#include <iostream>
#include <string> // c++ string class
#include <cstring> // strcmp
#include <cmath>
#include <cstdlib> // atoi
#include <boost/program_options.hpp> // program_options
#include "palette.h"

using namespace std;
namespace po = boost::program_options;

// example is heaven
void conflicting_options(const po::variables_map& vm,
  const char* opt1, const char* opt2) {
  if (vm.count(opt1) && !vm[opt1].defaulted()
    && vm.count(opt2) && !vm[opt2].defaulted())
    throw logic_error(
      string("Conflicting options '") + opt1 + "' and '" + opt2 + "'."
    );
}

int main(int argc, char* argv[]) {

  Palette palette; // init w/ default constructor
  // if (argc > 1) {
  //   if (strcmp(argv[1],"-rgb")==0) {
  //     palette.setRGB( atoi(argv[2]), atoi(argv[3]), atoi(argv[4]) );
  //   } else if (strcmp(argv[1],"-raw")==0) {
  //     palette.setColor( atoi(argv[2]) );
  //   }
  // }
  std::vector<int> rgb(3,0);
  std::vector<float> hsl(3,0);
  po::options_description desc("Options");
  desc.add_options()
    ("help,h", "provide help message")
    ("version,v", "show version")
    ("rgb", po::value< std::vector<int> >(&rgb)->multitoken(), "set RGB Values")
    ("hsl", po::value< std::vector<float> >(&hsl)->multitoken(), "set HSL Values")
  ;
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  conflicting_options(vm, "rgb","hsl");

  if (vm.count("help")) {
    cout<< desc <<endl;
    return 1;
  } else if (vm.count("rgb")) {
    if (rgb.size() == 3) {
      palette.setRGB(rgb);
    } else {
      cout<<"rgb must be 3 values seperated by white spaces"<<endl;
      return 2;
    }
  } else if (vm.count("hsl")) {
    if (hsl.size() == 3) {
      palette.setHSL(hsl);
    } else {
      cout<<"hsl must be 3 values seperated by white spaces"<<endl;
      return 2;
    }
  }

  string input;
  getline(cin, input);
  cout<< input <<endl;
  return 0;
}
