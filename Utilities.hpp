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
    // OUTPUT
    static void Header( const string& header );
    static void DrawHorizontalBar( int width, char symbol = '-' );

    // MENUS and INPUT/OUTPUT
    static void ShowMenu( const vector<string> options, bool vertical = true );
    static int ShowIntMenuWithPrompt( const vector<string> options, bool vertical = true );
    static string ShowStringMenuWithPrompt( const vector<string> options, bool vertical = true );
    static int GetValidChoice( int min, int max, const string& message = "" );
    static string GetStringChoice( const string& message = "" );
    static string GetStringLine( const string& message = "" );
    static int GetIntChoice( const string& message = "" );

    // HANDY TRICKS
    static void ClearScreen();
    static void Pause();
    static void PrintPwd();
};

class StringUtil
{
    public:
    template <typename T>
    static string ToString( const T& value );
    static int StringToInt( const string& str );
    static string ToUpper( const string& val );
    static string ToLower( const string& val );
    static string ColumnText( int colWidth, const string& text );
};


template <typename T>
string StringUtil::ToString( const T& value )
{
    stringstream ss;
    ss << value;
    return ss.str();
}

// OUTPUT
void Menu::Header( const string& header )
{
    DrawHorizontalBar( 80 );
    string head = "| " + header + " |";
    cout << " " << head << endl << " ";
    DrawHorizontalBar( head.size() );
    cout << endl;
}

void Menu::DrawHorizontalBar( int width, char symbol )
{
    for ( int i = 0; i < width; i++ )
    {
        cout << symbol;
    }
    cout << endl;
}

// MENUS and INPUT/OUTPUT
void Menu::ShowMenu( const vector<string> options, bool vertical )
{
    if ( vertical )
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ".\t" << options[i] << endl;
        }
    }
    else
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ". " << options[i] << "\t";
        }
        cout << endl;
    }
}

int Menu::ShowIntMenuWithPrompt( const vector<string> options, bool vertical )
{
    ShowMenu( options, vertical );
    int choice = GetValidChoice( 1, options.size() );
    return choice;
}

string Menu::ShowStringMenuWithPrompt( const vector<string> options, bool vertical )
{
    ShowMenu( options, vertical );
    int choice = GetValidChoice( 1, options.size() );
    string value = options[ choice-1 ];
    return value;
}

int Menu::GetValidChoice( int min, int max, const string& message )
{
    if ( message != "" )
    {
        cout << endl;
        DrawHorizontalBar( message.size() + 2 );
        cout << " " << message << endl;
    }

    int choice = GetIntChoice();

    while ( choice < min || choice > max )
    {
        cout << "Invalid selection. Try again." << endl;
        choice = GetIntChoice();
    }

    return choice;
}

string Menu::GetStringChoice( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }

    cout << endl << " >> ";
    string choice;
    cin >> choice;
    cin.ignore();
    cout << endl;
    return choice;
}

string Menu::GetStringLine( const string& message )
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

int Menu::GetIntChoice( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }
    cout << endl << " >> ";
    int choice;
    cin >> choice;
    cin.ignore();
    cout << endl;
    return choice;
}

// HANDY TRICKS
void Menu::ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

void Menu::Pause()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "pause" );
    #else
        cout << endl << " Press ENTER to continue..." << endl;
        cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
    #endif
}

void Menu::PrintPwd()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "echo %cd%" );
    #else
        system( "pwd" );
    #endif
}


int StringUtil::StringToInt( const string& str )
{
    istringstream ss( str );
    int val;
    ss >> val;
    return val;
}

string StringUtil::ToUpper( const string& val )
{
    string upper = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        upper += toupper( val[i] );
    }
    return upper;
}

string StringUtil::ToLower( const string& val )
{
    string upper = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        upper += tolower( val[i] );
    }
    return upper;
}

string StringUtil::ColumnText( int colWidth, const string& text )
{
    string adjusted = text;
    for ( int i = 0; i < colWidth - text.size(); i++ )
    {
        adjusted += " ";
    }
    return adjusted;
}



#endif
