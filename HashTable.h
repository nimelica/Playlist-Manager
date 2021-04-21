#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Song.h"
#include "HashBucket.h"
#include <string>

class HashTable
{
private:
    int maxBuckets;
    int totalElements;
    HashBucket* bucketArray;
public:
    HashTable(int size);
    ~HashTable();

    int hashFunc(string title);
    int numElements();
    void addElement(Song* songELement);
    Song* getElement(string songName, int& x, int& y);
    void cleanupElements(int t);
    void removeElement(string songName);

};

#endif // HASHTABLE

