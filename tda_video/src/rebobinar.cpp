#include "image.h"
#include "video.h"
#include <iostream>

using namespace std;

Video Rebobinar(const Video &V)
{
  int n = V.size();
  Video aux(n);
  for(int i = 0; i < n; i++)
    aux[i] = V[n-1];
  
  return aux;
}

void Error(ostream &os){
  os << "Formato para ejecutar el programa:";
  os << "./programa /directorio_entrada /directorio_salida";
}

int main(int argc, char * argv[]){
  // Control de errores
  if(argc!=3)
    Error(cerr);
  
  if(!(filesystem::is_directory(argv[1]) && 
       filesystem::is_directory(argv[2])))
    Error(cerr);

  const string PREFIJO = "fotograma";
  Video v_e;

  if(v_e.LeerVideo(argv[1]))
  {
    v_e = rebobinar(v_e);
    v_e.EscribirVideo(argv[2], PREFIJO);
  }

  return 0;
}
