#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Room.hpp"
#include "Utilities.hpp"

class Program
{
public: // initialise public variables
	Program();
	~Program();
	void Run();

private: // initialise private variables
	bool SetupRooms();
	int CreateRoom(string name, string description);
	string HandleUserInput();
	string userInput;
	Room *m_ptrCurrentRoom; // initialise pointer to current room
	vector<Room *> m_rooms; // initialise vector of pointer
	bool m_done;
};

Program::Program()
{
	m_ptrCurrentRoom = nullptr;
	m_done = false;
	SetupRooms();

	bool success = SetupRooms();
	if (!success)
	{
		m_done = true;
	}
}

void Program::Run() // start program with user instructions
{
	cout << "" << endl;
	cout << "[[ Haunted House ]]" << endl;
	cout << "Your Uncle Albert is currently out of town - however you have been asked to find and retrieve an ancient scroll located somewhere in his (creepy and haunted) mansion." << endl;
	cout << "Using the n, s, e, w keys - navigate through each room in the house until you locate the ancient scroll." << endl;

	while (!m_done)
	{
		m_ptrCurrentRoom->OutputRoomInfo();

		cout << endl
			 << endl;

		HandleUserInput();
	}
}

bool Program::SetupRooms() // initialise room objects and dynamic array
{
	/*
    string filename = "rooms.txt";
    Logger::Out( "Function start", "Program::SetupRooms" );
    ifstream input( filename );
    */

	int startRoom = CreateRoom("House Entrance", "Ahead of you sits the entrance to the house - the porch stairs creak noisily beneath you.");
	int car = CreateRoom("Car Park", "You've parked your car here.");
	int foyer = CreateRoom("Foyer", "You're in the foyer of the building. The front door loudly slams shut behind you as a dust cloud gusts from beneath the cracks.");
	int kitchen = CreateRoom("Kitchen", "You're in the kitchen. The foul odour of rotting food looms in the air.");
	int lounge = CreateRoom("Lounge", "You're in the smoker's lounge - Uncle Albert's favourite room. A shadowy figure appears beside the armchair in the corner. ");
	int corridor = CreateRoom("Corridor", "You're in a dark corridor that leads to some stairs. You can hear some creaking coming from behind you.");
	int stairs = CreateRoom("Staircase", "You are at the bottom of a rickety, dusty staircase - you can hear footsteps coming from the East Wing upstairs.");
	int landing = CreateRoom("Landing", "You're at the entrance to the East Wing at the top of the stairs - the footsteps have drawn closer.");
	int drawRoom = CreateRoom("Drawing Room", "You're in the drawing room - legend has it, 100 years ago this was where Shirley Schildt (the local grocer) was last seen alive.");
	int bed2 = CreateRoom("Landing", "You're further down the landing and you can see a shadowy figure quickly appearing in front of you once again.");
	int study = CreateRoom("Study", "You've reached Uncle Albert's study to find the ancient scroll sitting on his desk.");
	int bed3 = CreateRoom("Guest Room", "You're in the guest room. It is empty - slowly the wardrobe door creaks open...");
	int bed1 = CreateRoom("Master", "You're in the master bedroom. You hear a deafening shriek coming from the bottom of the stairs.");

	m_rooms[startRoom]
		->SetNeighbours(
			nullptr,		// North
			m_rooms[foyer], // South
			m_rooms[car],	// East
			nullptr);		// West

	m_rooms[car]
		->SetNeighbours(
			nullptr,		   // North
			nullptr,		   // South
			nullptr,		   // East
			m_rooms[startRoom] // West
		);

	m_rooms[foyer]
		->SetNeighbours(
			m_rooms[startRoom], // North
			m_rooms[corridor],	// South
			nullptr,			// East
			m_rooms[kitchen]	// West
		);

	m_rooms[kitchen]
		->SetNeighbours(
			nullptr,		 // North
			m_rooms[lounge], // South
			m_rooms[foyer],	 // East
			nullptr			 // West
		);

	m_rooms[lounge]
		->SetNeighbours(
			m_rooms[kitchen],  // North
			nullptr,		   // South
			m_rooms[corridor], // East
			nullptr			   // West
		);

	m_rooms[corridor]
		->SetNeighbours(
			m_rooms[foyer],	 // North
			nullptr,		 // South
			m_rooms[stairs], // East
			m_rooms[lounge]	 // West
		);

	m_rooms[stairs]
		->SetNeighbours(
			nullptr,		  // North
			nullptr,		  // South
			m_rooms[landing], // East
			nullptr);		  // West

	m_rooms[landing]
		->SetNeighbours(
			m_rooms[bed2],	   // North
			m_rooms[drawRoom], // South
			nullptr,		   // East
			m_rooms[stairs]	   //West
		);

	m_rooms[drawRoom]
		->SetNeighbours(
			m_rooms[landing], // North
			nullptr,		  // South
			nullptr,		  // East
			nullptr);		  // West

	m_rooms[bed2]
		->SetNeighbours(
			m_rooms[study],	  // North
			m_rooms[landing], // South
			m_rooms[bed3],	  // East
			m_rooms[bed1]);	  // West

	m_rooms[study]
		->SetNeighbours(
			nullptr,		// North
			nullptr,		// South
			nullptr,		// East
			m_rooms[bed2]); // West

	m_rooms[bed3]
		->SetNeighbours(
			nullptr,		// North
			nullptr,		// South
			nullptr,		// East
			m_rooms[bed2]); // West

	m_rooms[bed1]
		->SetNeighbours(
			nullptr,	   // North
			nullptr,	   // South
			m_rooms[bed2], // East
			nullptr);	   // West

	m_ptrCurrentRoom = m_rooms[startRoom]; // pointer to first item in array
	return true;
}

int Program::CreateRoom(string name, string description) // setup new room with each iteration
{
	int index = m_rooms.size();

	Room *room = new Room;
	room->Setup(name, description);
	m_rooms.push_back(room);
	return index;
}

string Program::HandleUserInput() // user input method
{
	string status = "";

	string userInput = Menu::GetStringLine("Now what?"); // user input

	//cout << ( "User entered " + userInput );

	if (userInput == "north" || userInput == "n") // if else conditional statements
	{
		if (m_ptrCurrentRoom->CanGo(NORTH))
		{
			status = "You went NORTH";
			m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourNorth;
		}
		else // error handling
		{
			cout << " - you can't go North this time!" << endl;
			Menu::Pause(); // press enter to continue
		}
	}

	else if (userInput == "south" || userInput == "s")
	{
		if (m_ptrCurrentRoom->CanGo(SOUTH))
		{
			status = "You went SOUTH";
			m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourSouth;
		}
		else
		{
			cout << " - you can't go South this time!" << endl;
			Menu::Pause();
		}
	}

	else if (userInput == "east" || userInput == "e")
	{
		if (m_ptrCurrentRoom->CanGo(EAST))
		{
			cout << ("You went EAST");
			m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourEast;
		}
		else
		{
			cout << " - you can't go East this time!" << endl;
			Menu::Pause();
		}
	}

	else if (userInput == "west" || userInput == "w")
	{
		if (m_ptrCurrentRoom->CanGo(WEST))
		{
			status = "You went WEST";
			m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourWest;
		}
		else
		{
			cout << " - you can't go West this time!" << endl;
			Menu::Pause();
		}
	}
	else
	{
		cout << " - unknown command!" << endl;
		Menu::Pause();
	}

	return status;
}

Program::~Program() // prevent memory leak
{
	cout << "Freeing memory..." << endl;
	for (auto &ptrRoom : m_rooms)
	{
		if (ptrRoom != nullptr)
		{
			delete ptrRoom;
		}
	}
}

#endif