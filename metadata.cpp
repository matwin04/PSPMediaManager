#include "metadata.h"
#include <taglib/fileref.h>
#include <taglib/tag.h>

// Constructor
metadata::metadata(const std::string& filename)
    : fileName(fileName) {}

// Destructor
metadata::~metadata() {}

// Member function to get the title
std::string metadata::getTitle() const {
    TagLib::FileRef file(fileName.c_str());
    TagLib::Tag* tag = file.tag();
    return tag->title().toCString(true);
}

// Member function to get the artist
std::string metadata::getArtist() const {
    TagLib::FileRef file(fileName.c_str());
    TagLib::Tag* tag = file.tag();
    return tag->artist().toCString(true);
}

// Member function to get the album
std::string metadata::getAlbum() const {
    TagLib::FileRef file(fileName.c_str());
    TagLib::Tag* tag = file.tag();
    return tag->album().toCString(true);
}
