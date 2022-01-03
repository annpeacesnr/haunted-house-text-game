#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Room.hpp"

class Program
{
	public:
	Program();
  ~Program();
	void Run();

	private:
	void SetupRooms();
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
}

void Program::Run()
{
	string userInput;
  
  string status = "";

	while ( !m_done )
	{
		m_ptrCurrentRoom->OutputRoomInfo();

    status = HandleUserInput();

		cout << "Now what?" << endl;
		cout << "> ";
		std::getline( cin, userInput );
	}
}

void Program::SetupRooms()
{
	//int startRoom = CreateRoom( "Cave entrance", "ahead of you sits a cave" );
	//int car = CreateRoom( "Car", "you've parked your car here" );
	//int caveExit = CreateRoom( "Cave exit", "you're inside a cave, exit here" );

  int startRoom = 	CreateRoom( "Cave entrance", "ahead of you sits a cave" );
	int car = 			CreateRoom( "Car", "you've parked your car here" );
	int caveExit = 		CreateRoom( "Cave exit N", "you're inside a cave, exit here" );
	int caveLoop3 = 	CreateRoom( "Cave loop N", "you're in a narrow cave path that only goes forward" );
	int caveLoop4 = 	CreateRoom( "Cave loop S", "you're in a narrow cave path that only goes forward" );
	int cave5 = 		CreateRoom( "Cave exit S", "you're in a cave exit leading to the forest" );
	int forestCave = 	CreateRoom( "Blocked cave entrance", "You are in a forest. The cave to the west has been blocked!" );
	int forest7 = 		CreateRoom( "Cave exit S", "you're in a cave exit leading to the forest" );
	int forest8 = 		CreateRoom( "Cave exit S", "you're in a cave exit leading to the forest" );
	int ruins9 = 		CreateRoom( "Cave exit S", "you're in a cave exit leading to the forest" );
	int ruins10 = 		CreateRoom( "Cave exit S", "you're in a cave exit leading to the forest" );
	int ruins11 = 		CreateRoom( "Cave exit S", "you're in a cave exit leading to the forest" );
	int ruins12 = 		CreateRoom( "Cave exit S", "you're in a cave exit leading to the forest" );

	/*m_rooms[0].Setup( "Room0", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[1].Setup( "Room1", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[2].Setup( "Room2", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[3].Setup( "Room3", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[4].Setup( "Room4", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[5].Setup( "Room5", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[6].Setup( "Room6", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[7].Setup( "Room7", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[8].Setup( "Room8", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[9].Setup( "Room9", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[10].Setup( "Room10", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[11].Setup( "Room11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );
	m_rooms[12].Setup( "Room12", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ornare viverra pulvinar." );*/

	/*m_rooms[startRoom]->SetNeighbours( nullptr, (m_rooms[caveExit]), nullptr, m_rooms[car] );*/

  m_rooms[startRoom]
		->SetNeighbours( 
			nullptr, 				// North
			m_rooms[caveExit], 		// South
			m_rooms[car], 			// East
			nullptr );				// West

	m_rooms[car]
		->SetNeighbours( 
			nullptr, 				// North
			nullptr, 				// South
			nullptr, 				// East
			m_rooms[startRoom]  	// West
			);

	m_rooms[caveExit]
		->SetNeighbours( 
			m_rooms[startRoom], 	// North
			m_rooms[cave5], 		// South
			nullptr, 				// East
			m_rooms[caveLoop3] 		// West
			);

	m_rooms[caveLoop3]
		->SetNeighbours( 
			nullptr, 				// North
			m_rooms[caveLoop4], 	// South
			m_rooms[caveExit], 		// East
			nullptr 				// West
			);

	m_rooms[caveLoop4]
		->SetNeighbours( 
			m_rooms[caveLoop3], 	// North
			nullptr, 				// South
			m_rooms[cave5], 		// East
			nullptr 				// West
			);

	m_rooms[cave5]
		->SetNeighbours( 
			m_rooms[caveExit], 		// North
			nullptr, 				// South
			m_rooms[forestCave], 	// East
			m_rooms[caveLoop4]  	// West
			);

	m_ptrCurrentRoom = m_rooms[startRoom];
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

  //std::string line;
  //std::getline( cin, userInput );
	//string userInput = getline( "Now what?" );

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
			m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourNorth;
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
			status = "You went EAST";
			m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourNorth;
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
			m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourNorth;
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