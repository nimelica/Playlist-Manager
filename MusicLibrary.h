#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include <string>
#include "Song.h"
#include "HashTable.h"

using namespace std;

class MusicLibrary
{
private:
	int maxBuckets;
	int numSongs;    // number of Songs in library
	HashTable* mySongs;   // hash table storing all Songs

public:
	MusicLibrary(int maxsongs);
	~MusicLibrary();

	bool addSong(string title, string artist, string album, int year, int time);
	bool addSong(Song* song);
	void readSongsFromFile(string filename);

	int getNumSongs() const;
	Song* getSong(string title, int& x, int& y) const;
	void removeSong(string title);
	void cleanupSongs(int playtime);

	static int getNumSongsInFile(string filename);
};
#endif // MUSICLIBRARY_H

