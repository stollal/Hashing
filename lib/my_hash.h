#include<string>
#include<iostream>

#ifndef __MY_HASH_H__
#define __MY_HASH_H__

/*
 * constant value for the hash map
 */
const int TABLE_SIZE = 17011;
/*
 *Hash Node Declaration 
 */

class my_hashNode{
	
	public:
		int key;
		int value;
		my_hashNode* next;
		my_hashNode(int key, int value){
			this->key = key;
			this->value = value;
			this->next = NULL;
		}
	};
/*
 * Seperate Chaining Hash Map Declaration from www.sansfoundry.com/cpp-program-hash-tables-singly-linked-list/
 */
class my_hashMapSeperateChaining{
	
	private:
		my_hashNode** htable;
	public:
		my_hashMapSeperateChaining(){
			htable = new my_hashNode*[TABLE_SIZE];
			for(int i = 0; i<TABLE_SIZE; i++){
				htable[i] = NULL;
			}
		~my_hashMap(){
			for(int i = 0; i<TABLE_SIZE; i++){
				my_hashNode* entry = htable[i];
				while(entry != NULL){
					my_hashNode* prev = entry;
					entry = entry->next;
					delete prev;
					}
				}
				delete[] htable;
			}
/*
 *Hash Function
 */
			int HashFunc(int key){
				return key % TABLE_SIZE;
			}
/*
 *Insert an Element at a key
 */
			void Insert(int key, int value){
				int hash_val = HashFunc(key);
				my_hashNode* prev = NULL;
				my_hashNode* entry = htable[hash_val];
				while (entry != NULL){
					prev = entry;
					entry = entry->next;
				}
				if (entry == NULL){
					entry = new my_hashNode(key,value);
					if( prev == NULL){
						htable[hash_val]=entry;
					}
					else{
						prev->next = entry;
					}
				}
				else{
					entry->value = value;
				}
			}
/*
 *Remove an Element at a key
 */
			void Remove(int key){
				int hash_val = HashFunc(key);
				my_hashNode* entry = htable[hash_val];
				my_hashNode* prev = NULL;
				if (entry == NULL || entry->key != key){
					std::cout<<"No Element found at key"<<key<std::endl;
				return;
				}
				while (entry->next != NULL){
					prev = entry;
					entry = entry->next;
				}
				if(prev != NULL){
					prev->next = entry->next;
				}
				delete entry;
				std::cout<<"Element Deleted"<<std::endl;
				}
/*
 * Search an Element at a key
 */
			int Search(int key){
				bool flag = false;
				int hash_val = HashFunc(key);
				my_hashNode* entry = htable[hash_val];
				while(entry != NULL){
					if(entry->key == key){
						std::cout<<entry->value<<" ";
						flag = true;
					}
					entry = entry->next;
				}
				if(!flag)
					return -1;
				}
			};

/*
 *Linear probing hashing function from www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/
 *
 *
 *template for generic typ
 */
template<typename K, typename V>

/*
 *Create Hashmap class 
 */
class my_hashMapLinearProbing{
	//hash element array
	my_hashNode<K,V> **arr;	
	int capacity;
	//current size
	int size;
	//dummy node
	my_hashNode<K,V> *dummy;

	public:
	my_hashMapLinearProbing(){
		//Initial capacity of hash array	
		capacity = TABLE_SIZE;
		size = 0;
		arr = new my_hashNode<K,V>*[capacity];
		
		//Intialize all elements of array as NULL
		for(int i; i < capacity; i++){
			arr[i] = NULL;
		//dummy node with value and key as -1	
		dummy = new my_hashNode<K,V>(-1, -1);
		}
		/*
 		*This implements hash function to find index for a key
 		*/
		int hashCode(K key){
			return key % capacity;
		}
		/*
 		*Function to add key, value pair
 		*/
		void insertNode(K key, V value){
			my_hashNode<K,V> *temp = new my_hashNode<K,V>(key,value);
			//Apply hash function to find index for given key
			int hashIndex = hashCode(key);
			//find next free space
			while(arr[hashIndex] != NULL && arr[hashIndex]->key !=key && arr[hashIndex]->key != -1){
				hashIndex++;
				hashIndex %= capacity;
			}
			//if new node to be inserted increase the current size
			if(arr[hashIndex] == NULL || arr[hashIndex]-> key == -1)				size++;
			arr[hashIndex]= temp;
		}
		/*
 		*Function to delete a key value pair 
 		*/
		V deleteNode(int key){
			//Apply hash function to find index for given key
			int hashIndex = hashCode(key);
			//finding the node with given key
			while(arr[hashIndex] != NULL){
				//if node found
				if(arr[hashIndex]->key == key){
					my_hashNode<K,V> *temp = arr[hashIndex];
					//insert dummy node here for further use
					arr[hashIndex] = dummy;
					//reduce size
					size--;
					return temp->value;
				}
				hashIndex++;
				hashIndex %= capacity;
			}
			//if not found return null
			return NULL;
		}
		/*
 		*Function to search the value for a given key
		*/
		V get(int key){
			//Apply hash function to find index for given key
			int hashIndex = hashCode(key);
			//finding the node with given key
			while(arr[hashIndex] != NULL){
				//if node found return its value
				if(arr[hashIndex]->key == key)
					return arr[hashIndex]->value;
				hashIndex++;
				hashIndex %= capacity;
			}
			//if not found return null
			return NULL;
		}
	};
/*
 *Double Hashing function from wwww.geeksforgeeks.org/double-hashing/
 */
class my_hashDoubleHash{
	//pointer to array containing buckets
	int *hashTable;
	int curr_size;

	public:
		//function to check if the hash table is full
		bool isFull(){
			//if hash reaches max size
			return(curr_size == TABLE_SIZE);
		}
		//function to calculate first hash
		int hash1(int key){
			return (key % TABLE_SIZE);
		}
		//function to calculate second hash
		int hash2(int key){
			return (PRIME - (key % PRIME);
		}
		my_hashDoubleHash(){
			hashTable = new int[TABLE_SIZE];
			curr_size = 0;
			for(int i = 0; i<TABLE_SIZE; i++){
				hashTable[i] = -1;
			}
		}
		//function to insert key into hash table
		void insertHash(key){
			//if hash table is full
			if(isFull())
				return;
			//get index from first hash
			int index = hash1(key);
			//if collision occurs
			if(hashTable[index] != -1){
				//get index2 from second hash
				int index2 = hash2(key);
				int i = 1;
				while(1){
					//get newIndex
					int newIndex = (index + 1*index2)% TABLE_SIZE;
					//if no collision occurs store the key
					if(hashTable[newIndex] == -1){
						hashTable[newIndex = key;
						break;
					}
					i++;
					}	
				}
				//if no collision occurs
				else{
					hashTable[index] = key;
				}
				curr_size++;
			} 
		//funcion to display hash table
		void displayHash(){
			for(int i = 0; i < TABLE_SIZE; i++){
				if(hashTable[i] != -1)
					std::cout <<i << "-->" << hashTable[i] << std::endl;				
				else
					std::cout << i << std::endl;
				}
			}
		};

#endif
