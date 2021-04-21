#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int size) {
	bucketArray = new HashBucket[size];
	maxBuckets = size;
	totalElements = 0;
}

HashTable::~HashTable() {
	delete[]bucketArray;
}

int HashTable::hashFunc(string title) {
	int bias = 0;
	int scale = 1;
	int hashval = 0;
	for (unsigned int i = 0; i < title.size(); i++)
	{
		hashval = hashval + ((char)title[i]);
	}
	hashval = ((hashval * scale) + bias) % maxBuckets;

	return hashval;
}

int HashTable::numElements() {
	return totalElements;
}

void HashTable::addElement(Song* songElement) {
	int hash_index = hashFunc(songElement->getTitle());
	BucketNode* new_node = bucketArray[hash_index].head;
	unsigned node_index = {};

	if (!new_node) { //current bucket is empty
		new_node = new BucketNode;
		new_node->thisSong = songElement;
		bucketArray[hash_index].head = new_node; //head is new node now
		node_index = 0;
	}
	else { //bucket index is occupied
		while (new_node) { // -> we are in the bucket now (traverse through the list)
			new_node = new_node->next;
			node_index++;
		}
		new_node = new BucketNode;
		new_node->thisSong = songElement;
		new_node->prev = bucketArray[hash_index].head;
		bucketArray[hash_index].head->next = new_node;
	}
	totalElements++;
	cout << "Added in bucket " << hash_index << " at node " << node_index << ": ";
	new_node->thisSong->printSong();
}


void HashTable::removeElement(string songName) {
	int hash_index = hashFunc(songName);
	BucketNode* current_node = bucketArray[hash_index].head;
	BucketNode* trail = nullptr;

	if (!current_node) return;
	else {
		while (current_node && current_node->thisSong->getTitle() == songName) {
			trail = current_node;
			current_node = current_node->next;
		}
		if (!current_node) return;
		else {
			if (bucketArray[hash_index].head == current_node && !current_node->next) {
				bucketArray[hash_index].head = nullptr;
			}
			else if (bucketArray[hash_index].head == current_node) {
				bucketArray[hash_index].head = bucketArray[hash_index].head->next;
			}
			else {
				trail->next = current_node->next;
			}
			delete current_node;
			totalElements--;
		}
	}
}

Song* HashTable::getElement(string songName, int& x, int& y) {
	x = hashFunc(songName);
	int bucket_list_size = {};

	if (bucketArray[x].head == nullptr) return nullptr;
	else {
		BucketNode* curr = bucketArray[x].head;
		while (curr) {
			bucket_list_size++;
			curr = curr->next;
		}
		BucketNode* walker = bucketArray[x].head;
		while (walker != nullptr) {
			for (int i = 0; i < bucket_list_size; i++) {
				if (walker->thisSong->getTitle() == songName) {
					y = i;
				}
			}
			walker = walker->next;
		}
		int counter = 0;
		BucketNode* current = bucketArray[x].head;
		while (current->next!= nullptr and counter != y) {
			counter++;
			current = current->next;
		}
		if (current != nullptr and current->thisSong->getTitle() == songName)
			return current->thisSong;
	}
	cout << "Error! Song " << songName << " not found!\n";
	return nullptr;
}

void HashTable::cleanupElements(int t) {
	for (int i = 0; i < maxBuckets; i++) {
		while (bucketArray[i].head && bucketArray[i].head->thisSong->getPlayTime() < t) {
			BucketNode* temp = bucketArray[i].head;
			bucketArray[i].head = bucketArray[i].head->next;
			delete temp;
			totalElements--;
		}
		BucketNode* bucket = bucketArray[i].head;
		for (; bucket != nullptr; bucket = bucket->next) {
			while (bucket->next != nullptr && bucket->next->thisSong->getPlayTime() < t) {
				BucketNode* temp = bucket->next;
				bucket->next = temp->next;
				delete temp;
				totalElements--;
			}
		}
	}
}
