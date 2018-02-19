#include "palette.h"

Palette::Palette() {
  int pat1[16] = {0,128,128,128,128,128,128,192,128,255,255,255,255,255,255,255};
  int pat2[6] = {0,95,135,175,215,255};
  short t=0, j=0, k=0;
  int gray = 8;
  // for (short i = 0; i < 256; i++) {
  //   if (i < 16) {
  //     switch (i%8) {
  //       case 0: rgb_table[i] = new int [3]{pat1[i],pat1[i],pat1[i]};
  //       case 1: rgb_table[i] = new int [3]{pat1[i],0,0};
  //       case 2: rgb_table[i] = new int [3]{0,pat1[i],0};
  //       case 3: rgb_table[i] = new int [3]{pat1[i],pat1[i],0};
  //       case 4: rgb_table[i] = new int [3]{0,0,pat1[i]};
  //       case 5: rgb_table[i] = new int [3]{pat1[i],0,pat1[i]};
  //       case 6: rgb_table[i] = new int [3]{0,pat1[i],pat1[i]};
  //       case 7: rgb_table[i] = new int [3]{pat1[i],pat1[i],pat1[i]};
  //     }
  //   } else if (i>=16 && i<=231) {
  //     t = i - 16;
  //     rgb_table[i] = new int [3]{pat2[k],pat2[j],pat2[t]};
  //     if (t%6==5) {
  //       j += j;
  //     } else if (j%6==5) {
  //       k += k;
  //     }
  //   } else  {
  //     rgb_table[i] = new int [3]{gray,gray,gray};
  //     gray += 10;
  //   }
  // }

  // vector version
  rgb_table.resize(256, std::vector<int>(3,0)); // 256x3 w/ value 0
  int rgb[] = {0,0,0};
  for (short i = 0; i < 256; i++) {
    if (i < 16) { // system colors
      switch (i%8) {
        case 0: rgb[0] = pat1[i]; rgb[1] = pat1[i]; rgb[2] = pat1[i];
        case 1: rgb[0] = pat1[i]; rgb[1] = 0; rgb[2] = 0;
        case 2: rgb[0] = 0; rgb[1] = pat1[i]; rgb[2] = 0;
        case 3: rgb[0] = pat1[i]; rgb[1] = pat1[i]; rgb[2] = 0;
        case 4: rgb[0] = 0; rgb[1] = 0; rgb[2] = pat1[i];
        case 5: rgb[0] = pat1[i]; rgb[1] = 0; rgb[2] = pat1[i];
        case 6: rgb[0] = 0; rgb[1] = pat1[i]; rgb[2] = pat1[i];
        case 7: rgb[0] = pat1[i]; rgb[1] = pat1[i]; rgb[2] = pat1[i];
      }
    } else if (i>=16 && i<=231) { // extra colors
        t = i - 16;
        rgb[0] = pat2[k]; rgb[1] = pat2[j]; rgb[2] = pat2[t];
        if (t%6==5) {
          j += j;
        } else if (j%6==5) {
          k += k;
        }
    } else { // black-white gradient
      rgb[0] = gray; rgb[1] = gray; rgb[2] = gray;
      gray += 10;
    }
    rgb_table[i].assign(rgb,rgb+3);
  }

}

Palette::~Palette() {
  // for (short i = 0; i < 256; i++) {
  //   delete [] rgb_table[i];
  // }
  // delete [] rgb_table;
}

void Palette::setRGB (int r, int g, int b) {
  int xterm_code = rgb2xterm(r,g,b);
  char command[16] = "tput sgr0";
  sprintf(command,"tput setaf %d", xterm_code);

  system(command);
}

int Palette::rgb2xterm(int r, int g, int b) {
  std::vector<float> d; // (squared) distance between input & table
  for (short i = 0; i < 256; i++) {
    int r_temp = rgb_table[i][0] - r;
    int g_temp = rgb_table[i][1] - g;
    int b_temp = rgb_table[i][2] - b;
    d.push_back(std::pow(r_temp,2) + std::pow(g_temp,2) + std::pow(b_temp,2));
  }
  int color_code = std::distance(d.begin(), std::min_element(d.begin(), d.end()));

  return color_code;
}

void Palette::hsl2rgb(float hue, float sat, float light) {
  // `abs` is a function in <cstdlib> which only takes int values
  // `std::abs` is the versatile one
  float chroma = (1 - std::abs(2*light-1))*sat;
  int h = floor(hue/60);
  float x = chroma*(1 - std::abs(h%2-1));
  float r1, g1, b1; // not ready
  switch (h) {
    case 0: r1=chroma, g1=x, b1=0;
    case 1: r1=x, g1=chroma, b1=0;
    case 2: r1=0, g1=chroma, b1=x;
    case 3: r1=0, g1=x, b1=chroma;
    case 4: r1=x, g1=0, b1=chroma;
    case 5: r1=chroma, g1=0, b1=x;
    default: r1=0, g1=0, b1=0;
  }
  float m = light - 0.5*chroma;
  int r = round(r1+m), g= round(g1+m), b = round(b1+m);

}
