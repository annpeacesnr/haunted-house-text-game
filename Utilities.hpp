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


#endif
