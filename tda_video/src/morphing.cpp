#include "image.h"
#include "video.h"
#include <iostream>
#include <cassert>
using namespace std;
Video Morphing(const Image &I1,const Image &I2,int nf){
    // Comprobar que I1 e I2 tienen la misma dimension
    if (I1.get_rows() != I2.get_rows() || I1.get_cols() != I2.get_cols()) {
        throw invalid_argument("Las iamgenes tienen que tener
										"la misma dimension");
    }

    Video video_morphing(nf);  // Crear un video con nf fotogramas

    // Generar los fotogramas intermedios
    for (int i = 0; i < nf; i++) {
        Image foto_aux = I1; 

        // Recorrer cada pixel de foto aux asignandole el valor que le 
        // corresponde (calculado en base a I1 e I2)
        for (int j = 0; j < I1.get_rows(); j++) {
            for (int k = 0; k < I1.get_cols(); k++) {
                unsigned char pixel_I1 = I1.get_pixel(j, k);
                unsigned char pixel_I2 = I2.get_pixel(j, k);

                // Calcular y asignar el valor del pixel intermedio en cada caso
                unsigned char pixel_aux = 
						unsigned char((pixel_I1*(nf-i))/nf+(pixel_I2*i)/nf);
                foto_aux.set_pixel(j, k, pixel_aux);
            }
        }
        // Guardar el fotograma dentro de video_morphing
        video_morphing[i] = foto_aux;
    }

    return video_morphing;
}

int main(int argc, char * argv[]){
    if (argc != 5) {
		cerr<<"Error, numero de parametros incorrectos";
        return 1;
    }

    int nf = stoi(argv[4]);

    // Cargar las dos imagenes, y en caso de fallo salir de la ejecución
    Image I1, I2;
    if (!I1.Load(argv[1])) {
        cerr << "Error al cargar la imagen inicial: " << argv[1] << endl;
        return 1;
    }

    if (!I2.Load(argv[2])) {
        cerr << "Error al cargar la imagen final: " << argv[2] << endl;
        return 1;
    }

    // Generar el video morphing de I1 a I2
    Video video_morphing = Morphing(I1, I2, nf);

    if (!video_morphing.EscribirVideo(argv[3], "morph")) {
        cerr << "Error al guardar el video morphing en " << argv[3] << endl;
        return 1;
    }
	
	// Si se ha generado correctamente, guardarlo
    cout << "Video morphing guardado correctamente en " << argv[3] ;
	cout << endl;
	
    return 0;
}
