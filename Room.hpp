#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>
using namespace std;

#include "Utilities.hpp"

enum Direction { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3};

struct Room
{
    Room();
    Room( string name, string description);
    void SetNeighbours( Room* ptrNorth, Room* ptrSouth, Room* ptrEast, Room* ptrWest );
    void Setup( string name = "", string description = "" );

    void OutputRoomInfo();
    void OutputNeighbours();
    bool CanGo( Direction direction );

    string name;
    string description;
    Room* ptrNeighbourNorth;
    Room* ptrNeighbourSouth;
    Room* ptrNeighbourEast;
    Room* ptrNeighbourWest;
};

    Room::Room() 
    {
        Setup();
    }

    Room::Room( string name, string description )
    {
        Setup ( name, description );
    }


    void Room::Setup( string name /*= ""*/, string description /*= ""*/ )
    {
        this->name = name;
        this->description = description;

        ptrNeighbourNorth = nullptr;
        ptrNeighbourSouth = nullptr;
        ptrNeighbourEast = nullptr;
        ptrNeighbourWest = nullptr;
    }

    void Room::SetNeighbours( Room* ptrNorth, Room* ptrSouth, Room* ptrEast, Room* ptrWest )
    {
        ptrNeighbourNorth = ptrNorth;
        ptrNeighbourSouth = ptrSouth;
        ptrNeighbourEast = ptrEast;
        ptrNeighbourWest = ptrWest;
    }

    void Room::OutputRoomInfo()
    {
        Menu::ClearScreen();
        Menu::Header( name );
        cout << "\t" << description << endl;
        OutputNeighbours();

        cout << endl << endl;
    }

    void Room::OutputNeighbours()
    {
        cout << " \t You can go: ";

        if ( ptrNeighbourNorth != nullptr ) { cout << "(N)orth "; }
        if ( ptrNeighbourSouth != nullptr ) { cout << "(S)outh "; }
        if ( ptrNeighbourEast != nullptr ) { cout << "(E)ast "; }
        if ( ptrNeighbourWest != nullptr ) { cout << "(W)est "; }

        cout << endl;
    }

    bool Room::CanGo( Direction direction )
    {
        if ( direction == NORTH && ptrNeighbourNorth != nullptr )
        {
            return true;
        }
        else if ( direction == SOUTH && ptrNeighbourSouth != nullptr )
        {
            return true;
        }
        else if ( direction == EAST && ptrNeighbourEast != nullptr )
        {
            return true;
        }
        else if ( direction == WEST && ptrNeighbourWest != nullptr )
        {
            return true;
        }

        return false;
    }


#endif