#include <iostream>
#include <string> // c++ string class
#include <cstring> // strcmp
#include <cmath>
#include <cstdlib> // atoi
#include <boost/program_options.hpp> // program_options
#include "palette.h"

using namespace std;
namespace po = boost::program_options;

int main(int argc, char* argv[]) {

  Palette palette; // init w/ default constructor
  // if (argc > 1) {
  //   if (strcmp(argv[1],"-rgb")==0) {
  //     palette.setRGB( atoi(argv[2]), atoi(argv[3]), atoi(argv[4]) );
  //   } else if (strcmp(argv[1],"-raw")==0) {
  //     palette.setColor( atoi(argv[2]) );
  //   }
  // }
  std::vector<int> rgb(0);
  po::options_description desc("Options");
  desc.add_options()
    ("help,h", "provide help message")
    ("version,v", "show version")
    ("rgb", po::value< std::vector<int> >()->multitoken(), "set RGB Values")
  ;
  po::variables_map varMap;
  po::store(po::parse_command_line(argc, argv, desc), varMap);
  po::notify(varMap);
  if (varMap.count("help")) {
    cout<< varMap.count("help") <<endl;
    return 1;
  } else if (!varMap["rgb"].empty() && (rgb = varMap["rgb"].as< std::vector<int> >()).size()==3) {
    palette.setRGB(rgb[0], rgb[1], rgb[2]);
  }

  string input;
  getline(cin, input);
  cout<< input <<endl;
  return 0;
}
