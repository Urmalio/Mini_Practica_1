#include "image.h"
#include "video.h"
#include <iostream>

using namespace std;
/**
* @brief Función que rebobina video
* @param V el video original que va a servir de referencia para rebobinar
* @post El objeto creado tendrá las mismas imágenes de V pero al revés
*/
Video Rebobinar(const Video &V)
{
  int n = v.size();
  Video aux(n);
  for(int i = 0; i < n; i++)
    aux[i] = v[n-1];
  
  return aux;
}

/**
* @brief Función que muestra mensaje error
* @param os El flujo de salida que se usará
* @post Muestra el formato correcto que se debe escribir para ejecutar el programa
*/
void Error(ostream &os){
  os << "Formato para ejecutar el programa:";
  os << "./programa /directorio_entrada /directorio_salida";
}

// Main
int main(int argc, char * argv[]){
  // Comprobar números de argumentos
  if(argc!=3)
    Error(cerr);

  if(!(filesystem::is_directory(argv[1]) && 
      filesystem::is_directory(argv[2])))
    Error(cerr);

  const string PREFIJO = "fotograma";
  Video v_e;

  // Si se pudo hacer la lectura correctamente
  if(v_e.LeerVideo(argv[1]))
  {
    v_e = rebobinar(v_e);
    v_e.EscribirVideo(argv[2], PREFIJO);
  }

  return 0;
}
