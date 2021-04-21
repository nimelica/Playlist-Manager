#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <algorithm>
#include <cstdlib>
#include "MusicLibrary.h"


MusicLibrary::MusicLibrary(int maxbuckets)
{
	maxBuckets = maxbuckets;
	numSongs = 0;
	mySongs = new HashTable(maxBuckets);
}

MusicLibrary::~MusicLibrary()
{
	delete mySongs;
}

int MusicLibrary::getNumSongs() const
{
	return mySongs->numElements();
}

Song* MusicLibrary::getSong(string title, int& x, int& y) const
{
	return mySongs->getElement(title, x, y);
}

void MusicLibrary::removeSong(string title)
{
	mySongs->removeElement(title);
}


bool MusicLibrary::addSong(string title, string artist, string album, int year, int time)
{
	Song* newSong = new Song(title, artist, album, year, time);
	mySongs->addElement(newSong);
	return true;
}

bool MusicLibrary::addSong(Song* song)
{
	mySongs->addElement(song);

	return true;
}

void MusicLibrary::readSongsFromFile(string filename)
{
	ifstream input;
	input.open(filename);

	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			string title, artist, album;
			string s_year, s_time;
			int year;
			int time;
			istringstream inSS(line);

			getline(inSS, title, ',');
			getline(inSS, artist, ',');
			getline(inSS, album, ',');
			getline(inSS, s_year, ',');
			getline(inSS, s_time);

			// Trim whitespaces
			artist.erase(artist.begin(), std::find_if(artist.begin(), artist.end(),
				[](char ch) {return !isspace(ch); }));
			album.erase(album.begin(), std::find_if(album.begin(), album.end(),
				[](char ch) {return !isspace(ch); }));

			year = stoi(s_year);
			time = stoi(s_time);
			addSong(title, artist, album, year, time);
		};
		input.close();
	}
	else {
		cout << "Could not open file " << filename << std::endl;
		exit(-1);
	}
}

int MusicLibrary::getNumSongsInFile(string filename)
{
	ifstream input;
	int lines;
	string line;

	input.open(filename);
	if (input.is_open()) {
		for (lines = 0; getline(input, line); lines++);
		input.close();
	}
	else {
		cout << "Could not open file " << filename << std::endl;
		exit(-1);
	}
	input.close();

	return lines;
}


void MusicLibrary::cleanupSongs(int playtime)
{
	mySongs->cleanupElements(playtime);
}
