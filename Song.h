#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
private:
    string Title;
    string Artist;
    string Album;
    int Year;
    int PlayTime;

public:
    Song();
    Song(string title, string artist, string album, int year, int time);

    string getTitle() const;
    void setTitle(const string title);

    string getArtist() const;
    void setArtist(const string artist);

    string getAlbum() const;
    void setAlbum(const string album);

    int getYear() const;
    void setYear(const int year);

    int getPlayTime() const;
    void setPlayTime(const int time);

    void printSong() const;
};
#endif // SONG_H

