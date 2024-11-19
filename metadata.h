#pragma once;

#include <string>
using namespace std;

class metadata{
    private:
        string fileName;
    public:
        metadata(const string& fileName);
        ~metadata();
        //Get Title
        string getTitle() const;
        string getArtist() const;
        string getAlbum() const;
    

};