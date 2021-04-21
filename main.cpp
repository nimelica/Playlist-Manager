#include <iostream>
#include <string>
#include <cstdlib>

#include "Song.h"
#include <cstdlib>
#include <stdlib.h>
#include "MusicLibrary.h"

using namespace std;

int main(int argc, char** argv){
    string filename = ("songs-long.txt");
    int buckets, x = 0, y = 0;
    Song* song;

    buckets = 9; //small number of buckets to cause collisions

    MusicLibrary mylibrary(buckets);

    mylibrary.readSongsFromFile(filename);

    cout << endl << "  START DEBUGGING-> " << endl << endl;

    int size_now = mylibrary.getNumSongs();
    cout << size_now << " \n\n";

   mylibrary.cleanupSongs(300);
   int size_then = mylibrary.getNumSongs();
    cout << size_then << " \n\n";


    return 0;
}

