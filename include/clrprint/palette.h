#include <cmath> // floor round std::abs
#include <algorithm> // std::min_element
#include <vector> // use stl instead of dynamic array
#include <iterator> // std::distance
#include <cstdlib> // system
#include <cstdio> // sprintf

class Palette {
private:
  // int rgb_table[3][256] = { {  0,  0,  0}, {128,  0,  0}, {  0,128,  0},
  //                           {128,128,  0}, {  0,  0,128}, {128,  0,128},
  //                           {  0,128,128}, {192,192,192}, {128,128,128},
  //                           {255,  0,  0}, {  0,255,  0}, {255,255,  0},
  //                           {  0,  0,255}, {255,  0,255}, {  0,255,255},
  //                           {255,255,255}
  //                         };
  std::vector< std::vector<int> > rgb_table;

public:
  Palette ();
  virtual ~Palette ();

  void setRGB (int r, int g, int b);
  void setColor (int c);
  int rgb2xterm (int r, int g, int b);
  void hsl2rgb (float hue, float sat, float light);
};
