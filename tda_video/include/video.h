/**
 * @file video.h
 * @brief Fichero de cabecera de la clase video
 *
 * Implementación de TDA video *
 */

#ifndef PRACTICA2_VIDEO_H
#define PRACTICA2_VIDEO_H

#include "image.h"
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <cmath>
#include <string>
#include <filesystem>
#include <iostream>

using namespace std;

/**
 * @brief Lee los ficheros de un directorio
 * @param name es el nombre del directorio
 * @param v el vector donde almacena los nombres
 *
 * @post El vector @p v contiene los nombres de los archivos en los directorio @p name
 */
void read_directory(const std::string& name, vector<string>& v);


class Video {
private:
    vector<Image> seq;
public:

    /**
    * @brief constructor por defecto de la clase video que crea un videdo sin imagenes (vacío)
    */
    Video();

    /**
    * @brief Constructor del video con posibilidad de almacenar un número determinado de imagenes
    * @param n el número de imágenes que puede llegar a albergar
    * @pre @p n > 0
    * @post El objeto creado tendrá @p n imágenes, con cada imagen inicializada por defecto
    */
    Video(int n);

    /**
    * @brief Constructor de copia de la clase video
    * @param V es el video a partir del cual se va a crear el nuevo objeto
    *
    * @post El objeto creado contiene las mismas imágenes en el mismo orden que @p V
    */
    Video(const Video &V);

    /**
    * @brief Destructor de la clase video
    * @post El video queda inutilizado hasta que se vuelva a habilitar mediante un constructor
    */
    ~Video();

    /**
    * @brief Sobrecarga del operador = para la clase video
    * @param V es el video que se le quiere asignar al objeto
    *
    * @post el objeto implicito tendrá las mismas imágenes que el video @p V
    */
    Video &operator=(const Video &V);

    /**
    * @brief Metodo de consulta del número de imágenes de un video
    * Query method
    * @return el número que representa el número de imágenes del video
    *
    * @post el número de imágenes número entero no negativo
    */
    int size() const;

    /**
    * @brief Sobrecarga del operador [] para el tipo video, usado para acceder a un fotograma
    * @param foto posición del fotograma al que se desea acceder
    * @return devuelve una referencia a la imagen en la posición @p foto del video
    *
    * @pre 0<= @p foto < size()
    * @post devuelve una referencia a la imagen en la posicióon foto-ésima
    */
    Image &operator[](int foto);

    /**
    * @brief Sobrecarga del operador [] constante para el tipo video, usado para acceder a un fotograma
    * Query method
    * @param foto posición del fotograma al que se desea acceder
    * @return devuelve una referencia constante a la imagen en la posición @p foto del video
    *
    * @pre 0<= @p foto < size()
    * @post devuelve una referencia constante a la imagen en la posicióon foto-ésima
    */
    const Image &operator[](int foto)const;

    /**
    * @brief Inserta una imagen nueva en el video en cierta posición
    * @param k posición en la cual estará la imagen nueva
    * @param I imagen la cual se va a insertar
    *
    * @pre 0<= @p k <= size()
    * @post el video tendrá un elemento más
    */
    void Insertar(int k, const Image &I);

    /**
    * @brief borra una imagen del video en una determinada posición
    * @param k posición de la imagen q se va a eliminar
    *
    * @pre 0 <= @p k < size()
    * @post el video será modificado teniendo un elemento menos
    */
    void Borrar(int k);

    /**
    * @brief lee un video de un disco duro
    * @param path nombre del directorio en el cual se encuentran las imagenes para el video
    * @return true si la lectura fue exitosa, de otra forma false
    *
    * @pre @path ha de contener una secuencia temporal de fotogramas
    */
    bool LeerVideo(const string & path);

    /**
    * @brief escribe un video en el disco
    * @param path nombre del directorio en el cual se almacenarán las imágenes
    * @param prefijo cadena de formateo de los nombres de las imágenes
    * @return true si la escritura fue exitosa, de otra forma false
    *
    * @pre en el directorio path se almacenará la secuencia temporal de fotogramas. Los
    * fotogramas tomarán como nombre <prefijo>_01.pgm .. <prefijo>_0n.pgm siendo n el número de
    * fotogramas
    * @post si se ha devuelto true en el directorio path se encontrarán los archivos
    * <prefijo>_01.pgm .. <prefijo>_0n.pgm siendo n el número de fotogramas
    */
    bool EscribirVideo(const string & path, const string &prefijo)const;
};

#endif //PRACTICA2_VIDEO_H
