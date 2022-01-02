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
	void Run();

	private:
	void SetupRooms();
	int CreateRoom( string name, string description );
	string HandleUserInput();
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
	string status;

	while ( !m_done )
	{
		m_ptrCurrentRoom->OutputRoomInfo();

		cout << "\t" << status << endl;
		Menu::Pause();
	}
}

void Program::SetupRooms()
{
	int startRoom = CreateRoom( "Cave entrance", "ahead of you sits a cave" );
	int car = CreateRoom( "Car", "you've parked your car here" );
	int caveExit = CreateRoom( "Cave exit", "you're inside a cave, exit here" );

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

	m_rooms[startRoom]->SetNeighbours( nullptr, (m_rooms[caveExit]), nullptr, m_rooms[car] );

	m_ptrCurrentRoom = m_rooms[startRoom];
}

int Program::CreateRoom( string name, string description )
{
	Room* room = new Room;
	room->Setup( name, description );
	m_rooms.push_back( room );
	return m_rooms.size();
}

string Program::HandleUserInput()
{
	string status = "";

	string userInput = Menu::GetStringLine( "Now what?" );

	if (StringUtil::ToLower(userInput) == "north")
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

		else if (StringUtil::ToLower(userInput) == "south")
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

		else if (StringUtil::ToLower(userInput) == "east")
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

		else if (StringUtil::ToLower(userInput) == "west")
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

	return status;
}

#endif