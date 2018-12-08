

#ifndef  PROJECT2
#define PROJECT2

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;
typedef vector<string> row;
typedef vector<row> position;
typedef string square;
typedef char color;



typedef char Rank;
typedef char file;

//typedef string color; if you defined color as a string, use this line and remove the line above

struct mov {
	square src;
	square dst;
	// compare for order.     
	bool operator <(const mov& mv) const
	{

		return (src < mv.src) || ((!(mv.src < src)) && (dst < mv.dst));
	}
};




//#endif

//#pragma once


//_________________________________________________________________________
// Function declaration
position readPosition(string s);
set<mov> simpMoves(position P, color c);

bool check(position P, color c);
bool checkmate(position P, color c);
position result(position P, mov m);
bool occupied(Rank r, file f, position P, color c);



set<mov> legalMovesKing(Rank r, file f, position P);
set<mov> legalMovesQueen(Rank r, file f, position P);
set<mov> legalMovesKnight(Rank r, file f, position P);
set<mov> legalMovesRook(Rank r, file f, position P);
set<mov> legalMovesBishop(Rank r, file f, position P);
set<mov> legalMovesPawn(Rank r, file f, position P);
set<mov> legalMoves(position P, color c);

string pieceType(Rank r, file f, position P);
char pieceColor(Rank r, file f, position P);
set<mov> legalMoves(Rank r, file f, position P);


#endif

#pragma once

//_________________________________________________________________________
