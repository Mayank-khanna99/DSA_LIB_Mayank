#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "RedisStorage.h"
#include "CommandParser.h"
#include "RedisStats.h"

class RedisLite
{
private:

    RedisStorage storage;
    CommandParser parser;
    RedisStats stats;


    void handleSet(std::stringstream&);

    void handleGet(std::stringstream&);

    void handleDelete(std::stringstream&);

    void handleExists(std::stringstream&);

    void handlePrint();

    void handleClear();

    void handleStats();

public:
    void run();
};