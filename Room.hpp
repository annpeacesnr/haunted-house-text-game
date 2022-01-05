#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>
using namespace std;

#include "Utilities.hpp"

enum Direction
{
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3
};

struct Room
{
    Room();
    Room(string name, string description);
    void SetNeighbours(Room *ptrNorth, Room *ptrSouth, Room *ptrEast, Room *ptrWest);
    void Setup(string name = "", string description = "");

    void OutputRoomInfo();
    void OutputNeighbours();
    bool CanGo(Direction direction);

    string name;             // room name
    string description;      // room description
    Room *ptrNeighbourNorth; // pointers to neighbouring rooms
    Room *ptrNeighbourSouth;
    Room *ptrNeighbourEast;
    Room *ptrNeighbourWest;
};

Room::Room()
{
    Setup();
}

Room::Room(string name, string description) // constructor
{
    Setup(name, description);
}

void Room::Setup(string name /*= ""*/, string description /*= ""*/)
{
    this->name = name;
    this->description = description;

    ptrNeighbourNorth = nullptr; // null pointers showing initial empty values
    ptrNeighbourSouth = nullptr;
    ptrNeighbourEast = nullptr;
    ptrNeighbourWest = nullptr;
}

void Room::SetNeighbours(Room *ptrNorth, Room *ptrSouth, Room *ptrEast, Room *ptrWest)
{
    ptrNeighbourNorth = ptrNorth; // initialise string variables to neighbour pointers
    ptrNeighbourSouth = ptrSouth;
    ptrNeighbourEast = ptrEast;
    ptrNeighbourWest = ptrWest;
}

void Room::OutputRoomInfo() // output room interface
{
    /*cout << "-------------------------------------------------------------" << endl
            << name << endl
            << description << endl
            << "-------------------------------------------------------------"
            << endl;
        cout << "-------------------------------------------------------------" << endl << endl;*/

    Menu::Header(name); // room header
    cout << description << endl
         << endl; // room description

    OutputNeighbours();
}

void Room::OutputNeighbours() // output room neighbours
{
    cout << "You can go: ";

    if (ptrNeighbourNorth != nullptr)
    {
        cout << "(N)orth ";
    }
    if (ptrNeighbourSouth != nullptr)
    {
        cout << "(S)outh ";
    }
    if (ptrNeighbourEast != nullptr)
    {
        cout << "(E)ast ";
    }
    if (ptrNeighbourWest != nullptr)
    {
        cout << "(W)est ";
    }

    cout << endl;
}

bool Room::CanGo(Direction direction) // null pointer conditional check for directions
{
    if (direction == NORTH && ptrNeighbourNorth != nullptr)
    {
        return true;
    }
    else if (direction == SOUTH && ptrNeighbourSouth != nullptr)
    {
        return true;
    }
    else if (direction == EAST && ptrNeighbourEast != nullptr)
    {
        return true;
    }
    else if (direction == WEST && ptrNeighbourWest != nullptr)
    {
        return true;
    }

    return false;
}

#endif