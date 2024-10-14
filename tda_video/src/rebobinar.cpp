#include "image.h"
#include "video.h"
#include <iostream>

using namespace std;

Video Rebobinar(const Video &V)
{
  int n = v.size();
  Video aux(n);
  for(int i = 0; i < n; i++)
    aux[i] = v[n-1];
  
  return aux;
}

void Error(ostream *os){
  os << "Formato para ejecutar el programa:";
  os << "./programa /directorio_entrada /directorio_salida";
}

int main(int argc, char * argv[]){
  if(argc!=3)
    Error(cerr);
  
  bool is_directory = filesystem::is_directory(argv[1]) && 
                      filesystem::is_directory(argv[2]);
  if(!is_directory)
    Error(cerr);

  const string PREFIJO = "fotograma";
  Video v_e,v_s;

  if(v_e.LeerVideo(argv[1]))
    v_s = rebobinar(v_e);

  v_s.EscribirVideo(argv[2], PREFIJO);

  return 0;
}
