
#include "video.h"
//COMPLETAR POR EL ESTUDIANTE

void read_directory(const std::string& name, vector<string>& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {

        v.push_back(dp->d_name);

    }
    closedir(dirp);
}


Video::Video(): seq(0){}
/**************************************************/
Video::Video(int n): seq(n){}
/**************************************************/
Video::Video(const Video &V): seq(V.seq){}
/**************************************************/
Video::~Video(){seq.clear();}
/**************************************************/
Video &Video::operator=(const Video &V){
    if (seq != V.seq) seq = V.seq;
    return *this;
}
/**************************************************/
int Video::size() const{return seq.size();}
/**************************************************/
Image &Video::operator[](int foto){return seq[foto];}

const Image &Video::operator[](int foto)const{return seq[foto];}

void Video::Insertar(int k, const Image &I){seq.insert(seq.begin() + k, I);}

void Video::Borrar(int k){seq.erase( seq.begin() + k );}

bool Video::LeerVideo(const string &path){

    vector<string> v;
    read_directory(path, v);

    seq.clear();


    bool lectura_correcta = true;
    int i=0;
    Image tmp_image;

    while (lectura_correcta && i<size())
    {
        lectura_correcta = tmp_image.Load( v[i].c_str() );
        if (lectura_correcta)
        {
            seq.push_back( tmp_image );
            ++i;
        }
    }

    return lectura_correcta;
}

bool Video::EscribirVideo(const string & path, const string &prefijo)const{

    bool exito=true;
    std::filesystem::path filepath =path;
    bool filepathExists = std::filesystem::is_directory(filepath);

    if (!filepathExists){

        bool created_new_directory= std::filesystem::create_directory(filepath);
        if (!created_new_directory){
            cout<<"No se puede crear el directorio "<<path<<endl;
            return false;
        }
        else{
            cout<<" Se ha creado el directorio "<< path<<endl;
        }
    }

    int i=0;
    string base = "/"+prefijo+"_";
    while (i<size() && exito){
        exito = (*this)[i].Save(path+base+);

        if (exito)
        {
            ++i;
        }

    }

}
