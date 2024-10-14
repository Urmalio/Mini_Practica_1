#include "image.h"
#include "video.h"
#include <iostream>
#include <algorithm>

using namespace std;

Video Rebobinar(const Video &V)
{
  int n = v.size();
  Video aux(n);
  for(int i = 0; i < n; i++)
    aux[i] = v[n-1];
  
  return aux;
}

int main(int argc, char * argv[]){
//RELLENAR POR EL ESTUDIANTE
}
