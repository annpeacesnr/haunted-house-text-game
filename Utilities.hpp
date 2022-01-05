#ifndef _UTILITIES_HPP
#define _UTILITIES_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include <sstream>
using namespace std;

class Menu
{
    public:
    static void Header( const string& header );
    static void DrawHorizontalBar( int width, char symbol = '-' );
    static string GetStringLine( const string& message = "" );
    static void Pause();
};

void Menu::Header( const string& header )                           // output menu corner title header
{
    DrawHorizontalBar( 80 );
    string head = "| " + header + " |";
    cout << " " << head << endl << " ";
    DrawHorizontalBar( head.size() );
    cout << endl;
}

void Menu::DrawHorizontalBar( int width, char symbol )              // draw horizontal menu bar
{
    for ( int i = 0; i < width; i++ )
    {
        cout << symbol;
    }
    cout << endl;
}

string Menu::GetStringLine( const string& message )                 // receive user input
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }
    string choice;
    cout << endl << " >> ";
    getline( cin, choice );
    cout << endl;
    return choice;
}

void Menu::Pause()                                                  // pause and press enter to continue
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "pause" );
    #else
        cout << endl << "Press ENTER to continue..." << endl;
        cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
    #endif
}

/*
string StringUtil::ToLower( const string& val )
{
    string upper = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        upper += tolower( val[i] );
    }
    return upper;
}
*/

#endif
