#ifndef BUCKETNODE_H
#define BUCKETNODE_H

#include "Song.h"

class BucketNode
{
public:

    BucketNode* next;
    BucketNode* prev;
    Song* thisSong;

    BucketNode()
    {
        next = nullptr;
        prev = nullptr;
        thisSong = nullptr;
    }
};

#endif // BUCKETNODE
