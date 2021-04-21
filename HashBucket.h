#ifndef HASHBUCKET_H
#define HASHBUCKET_H

#include "Song.h"
#include "BucketNode.h"

class HashBucket
{
public:
    BucketNode* head;

    HashBucket()
    {
        head = nullptr;
    }
};

#endif // HASHBUCKET
