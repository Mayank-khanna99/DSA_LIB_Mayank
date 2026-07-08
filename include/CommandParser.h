#pragma once

#include <string>
#include <sstream>
#include "CommandType.h"

class CommandParser
{
public:

    CommandType parse(const std::string& command) const{
        if(command=="SET") return CommandType::SET;

        if(command=="GET") return CommandType::GET;

        if(command=="DEL") return CommandType::DEL;

        if(command=="EXISTS") return CommandType::EXISTS;

        if(command=="CLEAR") return CommandType::CLEAR;

        if(command=="PRINT") return CommandType::PRINT;

        if(command=="STATS") return CommandType::STATS;

        if(command=="SIZE") return CommandType::SIZE;

        if(command=="KEYS") return CommandType::KEYS;

        if(command=="EXIT") return CommandType::EXIT;

        return CommandType::INVALID;
    }
};