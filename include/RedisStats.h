#pragma once
#include<iostream>
using namespace std;
class RedisStats{
    private:
        int setCount=0;
        int getCount=0;
        int existCount=0;
        int delCount=0;
    public:
        void incrementSet(){
            setCount++;
        }

        void incrementDel(){
            delCount++;
        }

        void incrementGet(){
            getCount++;
        }

        void incrementExists(){
            existCount++;
        }

        void print(){
            cout<<"Set command: "<<setCount<<endl;
            cout<<"Get command: "<<getCount<<endl;
            cout<<"Del command: "<<delCount<<endl;
            cout<<"Exists command: "<<existCount<<endl;
        }
};