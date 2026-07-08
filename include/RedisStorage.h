#pragma once

#include <string>
#include "HashMap.h"

class RedisStorage
{
private:

    HashMap<std::string, std::string> database;

public:

    bool set(const std::string& key, const std::string& value){
        database.put(key, value);
        return true;
    }

    std::string* get(const std::string& key){
        if (!database.containsKey(key)){
            return nullptr;
        }

        return &database.get(key);
    }

    bool del(const std::string& key){
        return database.remove(key);
    }

    bool exists(const std::string& key){
        return database.containsKey(key);
    }

    void clear(){
        database.clear();
    }

    void print(){
        database.print();
    }

    size_t size() const{
        return database.get_size();
    }

    size_t capacity() const{
        return database.get_capacity();
    }
};