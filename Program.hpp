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
	public:
	Program();
  ~Program();
	void Run();

	private:
	bool SetupRooms();
	int CreateRoom( string name, string description );
  string HandleUserInput();
  string userInput;
	Room* m_ptrCurrentRoom;
	vector<Room*> m_rooms;
	bool m_done;
};

Program::Program()
{
	m_ptrCurrentRoom = nullptr;
	m_done = false;
	SetupRooms();

bool success = SetupRooms();
    if ( !success )
    {
        m_done = true;
    }
}

void Program::Run()
{
	while ( !m_done )
	{
	m_ptrCurrentRoom->OutputRoomInfo();

    cout << endl << endl;

    HandleUserInput();

	}
}

bool Program::SetupRooms()
{

  int startRoom = 	CreateRoom( "House entrance", "Ahead of you sits the entrance." );
	int car = 			CreateRoom( "Curbside", "You've parked your car here." );
	int foyer = 		CreateRoom( "Foyer", "You're in the foyer of the building." );
	int kitchen = 	CreateRoom( "Kitchen", "You're in the kitchen." );
	int lounge = 	CreateRoom( "Lounge", "You're in the lounge." );
	int corridor = 		CreateRoom( "Corridor", "You're in a corridor that leads to some stairs." );
	int stairs = 	CreateRoom( "Staircase", "You are at the bottom of a staircase." );
	int landing = 		CreateRoom( "Landing", "You're at the top of the landing." );
	int drawRoom = 		CreateRoom( "Drawing Room", "You're in the drawing room." );
	int bed2 = 		CreateRoom( "Landing", "You're further down the landing." );
	int study = 		CreateRoom( "Study", "You've reached Albert's study." );
	int bed3 = 		CreateRoom( "Guest Room", "You're in the guest room." );
	int bed1 = 		CreateRoom( "Master", "You're in the master bedroom." );

  m_rooms[startRoom]
		->SetNeighbours( 
			nullptr, 				// North
			m_rooms[foyer], 		// South
			m_rooms[car], 			// East
			nullptr );				// West

	m_rooms[car]
		->SetNeighbours( 
			nullptr, 				// North
			nullptr, 				// South
			nullptr, 				// East
			m_rooms[startRoom]  	// West
			);

	m_rooms[foyer]
		->SetNeighbours( 
			m_rooms[startRoom], 	// North
			m_rooms[corridor], 		// South
			nullptr, 				// East
			m_rooms[kitchen] 		// West
			);

	m_rooms[kitchen]
		->SetNeighbours( 
			nullptr, 				// North
			m_rooms[lounge], 	// South
			m_rooms[foyer], 		// East
			nullptr 				// West
			);

	m_rooms[lounge]
		->SetNeighbours( 
			m_rooms[kitchen], 	// North
			nullptr, 				// South
			m_rooms[corridor], 		// East
			nullptr 				// West
			);

	m_rooms[corridor]
		->SetNeighbours( 
			m_rooms[foyer], 		// North
			nullptr, 				// South
			m_rooms[stairs], 	// East
			m_rooms[lounge]  	// West
			);

    m_rooms[stairs]
		->SetNeighbours( 
			nullptr, 				// North
			nullptr, 		// South
			m_rooms[landing], 			// East
			nullptr );				// West

        m_rooms[landing]
		->SetNeighbours( 
			m_rooms[bed2], 				// North
			m_rooms[drawRoom], 		// South
			nullptr, 			// East
			m_rooms[stairs]     //West
      );				

        m_rooms[drawRoom]
		->SetNeighbours( 
			m_rooms[landing], 				// North
			nullptr, 		// South
			nullptr, 			// East
			nullptr 
      );				      // West

        m_rooms[bed2]
		->SetNeighbours( 
			m_rooms[study], 				// North
			m_rooms[landing], 		// South
			m_rooms[bed3], 			// East
			m_rooms[bed1] 
      );				        // West

        m_rooms[study]
		->SetNeighbours( 
			nullptr, 				// North
			nullptr, 		// South
			nullptr, 			// East
			m_rooms[bed2]         
      );				// West

        m_rooms[bed3]
		->SetNeighbours( 
			nullptr, 				// North
			nullptr, 		// South
			nullptr, 			// East
			m_rooms[bed2] );				// West

        m_rooms[bed1]
		->SetNeighbours( 
			nullptr, 				// North
			nullptr, 		// South
			m_rooms[bed2], 			// East
			nullptr 
      );				// West

	m_ptrCurrentRoom = m_rooms[startRoom];
  return true;
}

int Program::CreateRoom( string name, string description )
{
  int index = m_rooms.size();

	Room* room = new Room;
	room->Setup( name, description );
	m_rooms.push_back( room );
	return index;
}

string Program::HandleUserInput()
{
	string status = "";

  string userInput = Menu::GetStringLine( "Now what?" );

  cout << ( "User entered " + userInput );

	if (userInput == "north" || userInput == "n")
	{
		if (m_ptrCurrentRoom->CanGo(NORTH))
		{
			status = "You went NORTH";
			m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourNorth;
		}
		else
		{
			status = "You can't go here!";
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
			status = "You can't go here!";
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
			status = "You can't go here!";
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
			status = "You can't go here!";
		}
	}
	else
	{
		status = "Unknown command";
	}

	return status;
}

Program::~Program()
{
	cout << "Freeing memory..." << endl;
	for ( auto& ptrRoom : m_rooms )
	{
		if ( ptrRoom != nullptr )
		{
			delete ptrRoom;
		}
	}
}

#endif 