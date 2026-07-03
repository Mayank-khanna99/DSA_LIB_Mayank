#pragma once

#include"./LinkedList.h"
#include"./Allocator.h"

template<typename K, typename V>
class HashMap{
    private:
        class Entry{
            public:
                K key;
                V value;
                Entry(const K& k, const V& v){
                    key=k;
                    value=v;
                }   
        };
        LinkedList<Entry>* buckets;
        size_t currentSize;
        size_t currentCapacity;
        double MAX_LOAD_FACTOR = 0.75;
        MyAllocator<LinkedList<Entry>> allocator;

        double loadFactor(){
            return (static_cast<double>(currentSize)/currentCapacity);
        }

        size_t bucketIndex(const K& key){
            return key%currentCapacity;
        }

        Entry* findEntry(const K&  key){
            size_t index=bucketIndex(key);
            for(auto it = buckets[index].begin(); it != buckets[index].end(); ++it){
                if((*it).key == key)
                {
                    return &(*it);
                }
            }
            return nullptr;
        }
        const Entry* findEntry(const K& key)const{
            size_t index=bucketIndex(key);
            for(auto it = buckets[index].begin(); it != buckets[index].end(); ++it){
                if((*it).key == key)
                {
                    return &(*it);
                }
            }
            return nullptr;
        }

        void rehash(){
            // Save old data
            LinkedList<Entry>* oldBuckets = buckets;
            size_t oldCapacity = currentCapacity;

            // Double capacity
            currentCapacity *= 2;

            // Allocate new buckets
            buckets = allocator.Allocate(currentCapacity);

            for(size_t i = 0; i < currentCapacity; i++)
            {
                allocator.Construct(&buckets[i]);
            }

            // Reset size
            currentSize = 0;

            // Move every entry to new buckets
            for(size_t i = 0; i < oldCapacity; i++)
            {
                for(auto it = oldBuckets[i].begin(); it != oldBuckets[i].end(); ++it)
                {
                    insert((*it).key, (*it).value);
                }
            }

            // Destroy old buckets
            for(size_t i = 0; i < oldCapacity; i++)
            {
                allocator.Destroy(&oldBuckets[i]);
            }

            allocator.Deallocate(oldBuckets);
        }
        
        public:
            HashMap(){
                currentCapacity=8;
                currentSize=0;
                buckets = allocator.Allocate(currentCapacity);
                for (size_t i = 0; i < currentCapacity; i++){
                    allocator.Construct(&buckets[i]);
                }
            }
            void insert(const K& key, const V& value){
                Entry* existing = findEntry(key);

                if(existing != nullptr)
                {
                    existing->value = value;
                    return;
                }

                size_t index = bucketIndex(key);

                Entry entry(key, value);

                buckets[index].push_back(entry);

                currentSize++;

                if(loadFactor() > MAX_LOAD_FACTOR)
                {
                    rehash();
                }
            }
            ~HashMap(){
                for (size_t i = 0; i < currentCapacity; i++){
                    allocator.Destroy(&buckets[i]);
                }

                allocator.Deallocate(buckets);
            }
};
