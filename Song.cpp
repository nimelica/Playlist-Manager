#include <iostream>
#include "Song.h"


Song::Song()
{
    Year = 0;
    PlayTime = 0;
}

Song::Song(string title, string artist, string album, int year, int time) : Title(title), Artist(artist), Album(album), Year(year), PlayTime(time)
{}

string Song::getTitle() const
{
    return Title;
}
void Song::setTitle(const string title)
{
    Title = title;
}

string Song::getArtist() const
{
    return Artist;
}
void Song::setArtist(const string artist)
{
    Artist = artist;
}

string Song::getAlbum() const
{
    return Album;
}
void Song::setAlbum(const string album)
{
    Album = album;
}

int Song::getYear() const
{
    return Year;
}
void Song::setYear(const int year)
{
    Year = year;
}

int Song::getPlayTime() const
{
    return PlayTime;
}
void Song::setPlayTime(const int time)
{
    PlayTime = time;
}

void Song::printSong() const
{
    cout << "Song: " << Title << ", " << Artist << ", " << Album << ", " << Year << endl;
}
