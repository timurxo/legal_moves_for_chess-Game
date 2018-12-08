 

#include "project2.h"



//function definition:

position readPosition(string s)
{

	row r1(8, "e");
	position p1(8, r1);



	int a, b;
	string c;

	// loop
	for (int i = 0; i < (signed)s.size(); ++i)
	{


		// if vector has something inside of it
		if (s[i] != ' ')
		{
			// a - row
			a = int(s[i + 2]) - int('0') - 1;

			// b - column
			b = int(s[i + 3]) - int('a');

			// c - name of the figure
			c = s.substr(i, 2);

			// position
			p1[a][b] = c;

			i = i + 3;
		}

	}

	return p1;
}


// RESTRICTIONS ON THE FIELD

bool check(position P, color c)
{

	// start looking for the whole board

	char colorKing;
	char oppositeColor;
	bool result = false;


	for (int i = 0; i < 7; i++)			// по горизонтали
	{
		for (int j = 0; j < 7; ++j)		// по вертикали
		{

			int i1 = int('1') + i;
			int j1 = int('a') + j;

			char ci = char(i1);
			char cj = char(j1);

			// find a KING and start work with it
			if (pieceType(ci, cj, P) == "K")
			{

				// fining the colors
				colorKing = pieceColor(ci, cj, P);

				if (colorKing == 'W')
					oppositeColor = 'B';
				else
					oppositeColor = 'W';



				//------------------------------------------------------------------------
				// LOOKING UP FROM POSITION OF THE KING
				{	int t = i + 1;	// index -> rank
					int t1 = int('1') + t;
					char ct = char(t1);
									// while rank is not out of the board
									// & its not occupied by the piece of the same color
									// & not occupied by the piece of opposite color 
				while (t <= 7 && !(occupied(ct, cj, P, colorKing)) && !(occupied(ct, cj, P, oppositeColor)))
				{
					t = t + 1;	// keep going up
				}
				if (t <= 7) {

					if (occupied(ct, cj, P, oppositeColor) && (pieceType(ct, cj, P) == "r" || pieceType(ct, cj, P) == "Q"))
					{
						result = true;
					}
				}
				}

				//------------------------------------------------------------------------

				// LOOKING DOWN FROM POSITION OF THE KING
				{int t = i - 1;
				int t1 = int('1') + t;
				char ct = char(t1);

				while (t >= 0 && !(occupied(ct, cj, P, colorKing)) && !(occupied(ct, cj, P, oppositeColor)))
				{
					t = t - 1;
				}
				if (t >= 0) {

					if (occupied(ct, cj, P, oppositeColor) && (pieceType(ct, cj, P) == "r" || pieceType(ct, cj, P) == "Q"))
					{
						result = true;

					}
				}
				}

				//------------------------------------------------------------------------

				// LOOKING LEFT FROM POSITION OF THE KING
				{	int t = j - 1;
				int t1 = int('a') + t;
				char ct = char(t1);

				while (t >= 0 && !(occupied(ci, ct, P, colorKing)) && !(occupied(ci, ct, P, oppositeColor)))
				{
					t = t - 1;
				}
				if (t >= 0) {

					if (occupied(ct, cj, P, oppositeColor) && (pieceType(ct, cj, P) == "r" || pieceType(ct, cj, P) == "Q"))
					{
						result = true;

					}
				}}

				//------------------------------------------------------------------------

				// LOOKING RIGHT FROM POSITION OF THE KING
				{ int t = j + 1;
				int t1 = int('a') + t;
				char ct = char(t1);

				while (t <= 7 && !(occupied(ct, cj, P, colorKing)) && !(occupied(ct, cj, P, oppositeColor)))
				{
					t = t + 1;
				}
				if (t <= 7) {

					if (occupied(ct, cj, P, oppositeColor) && (pieceType(ct, cj, P) == "r" || pieceType(ct, cj, P) == "Q"))
					{
						result = true;

					}
				}}




				//------------------------------------------------------------------------
				// LOOKING UP & LEFT FROM POSITION OF THE KING
				{int t = i + 1;
				int k = j - 1;

				int t1 = int('1') + t;
				char ct = char(t1);

				int k1 = int('a') + k;
				char ck = char(k1);


				while (((k >= 0) && (t <= 7)) && !(occupied(ct, ck, P, colorKing)) && !(occupied(ct, ck, P, oppositeColor)))
				{
					t = t + 1;
					k = k - 1;
				}
				// if file > 0, and rank < 7
				if ((k >= 0) && (t <= 7)) {

					// if there is a BISHOP or QUEEN 
					if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "b" || pieceType(ct, ck, P) == "Q"))
					{
						//	if (king is white) and pawn is black
						// if the king is blak and pawn is white
						result = true;

					}
				}}

				//------------------------------------------------------------------------

				// LOOKING UP & RIGHT FROM POSITION OF THE KING
				{int t = i + 1;
				int k = j + 1;

				int t1 = int('1') + t;
				char ct = char(t1);

				int k1 = int('a') + k;
				char ck = char(k1);

				while (((k <= 7) && (t <= 7)) && !(occupied(ct, ck, P, colorKing)) && !(occupied(ct, ck, P, oppositeColor)))
				{
					t = t + 1;
					k = k + 1;
				}
				// if file > 0, and rank < 7
				if ((k <= 7) && (t <= 7)) {

					// if there is a BISHOP or QUEEN 
					if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "b" || pieceType(ct, ck, P) == "Q"))
					{
						result = true;

					}
				}}

				//------------------------------------------------------------------------

				// LOOKING DOWN & LEFT FROM POSITION OF THE KING
				{int t = i - 1;
				int k = j - 1;

				int t1 = int('1') + t;
				char ct = char(t1);

				int k1 = int('a') + k;
				char ck = char(k1);

				while (((k >= 0) && (t >= 0)) && !(occupied(ct, ck, P, colorKing)) && !(occupied(ct, ck, P, oppositeColor)))
				{
					t = t - 1;
					k = k - 1;
				}
				// if file > 0, and rank < 7
				if ((k >= 0) && (t >= 0)) {

					// if there is a BISHOP or QUEEN 
					if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "b" || pieceType(ct, ck, P) == "Q"))
					{
						result = true;
					}
				}}

				//------------------------------------------------------------------------

				// LOOKING DOWN & RIGHT FROM POSITION OF THE KING
				{int t = i - 1;
				int k = j + 1;

				int t1 = int('1') + t;
				char ct = char(t1);

				int k1 = int('a') + k;
				char ck = char(k1);

				while (((k <= 7) && (t >= 0)) && !(occupied(ct, ck, P, colorKing)) && !(occupied(ct, ck, P, oppositeColor)))
				{
					t = t - 1;
					k = k + 1;
				}
				// ?????????????????????????????????????
				// if ((k >= 0) && (t >= 0)) {
				if ((k <= 7) && (t >= 0)) {

					// if there is a BISHOP or QUEEN 
					if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "b" || pieceType(ct, ck, P) == "Q"))
					{
						result = true;
					}
				}
				}



				// PAWNS
				//------------------------------------------------------------------------

				// PAWN look UP & LEFT (BLACK PAWNS)
				{
					if (colorKing == 'W')
					{
						int t = i + 1;		// rank
						int k = j - 1;		// file

						int t1 = int('1') + t;
						char ct = char(t1);

						int k1 = int('a') + k;
						char ck = char(k1);

						if ((k >= 0) && (t <= 7)) {
							// if there is a BLACK PAWN
							if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "p"))
							{
								result = true;

							}
						}
					}
				}

				// PAWN look UP & RIGHT (BLACK PAWNS)
				{
					if (colorKing == 'W')
					{
						int t = i + 1;		// rank
						int k = j + 1;		// file

						int t1 = int('1') + t;
						char ct = char(t1);

						int k1 = int('a') + k;
						char ck = char(k1);

						if ((k <= 7) && (t <= 7)) {
							// if there is a BLACK PAWN
							if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "p"))
							{
								result = true;

							}
						}
					}
				}


				// PAWN look DOWN & LEFT (WHITE PAWNS)
				{
					if (colorKing == 'B')
					{
						int t = i - 1;		// rank
						int k = j - 1;		// file

						int t1 = int('1') + t;
						char ct = char(t1);

						int k1 = int('a') + k;
						char ck = char(k1);

						if ((k >= 0) && (t >= 0)) {
							// if there is a WHITE PAWN
							if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "p"))
							{
								result = true;

							}
						}
					}
				}

				// PAWN look DOWN & RIGHT (WHITE PAWNS)
				{
					if (colorKing == 'B')
					{
						int t = i - 1;		// rank
						int k = j + 1;		// file

						int t1 = int('1') + t;
						char ct = char(t1);

						int k1 = int('a') + k;
						char ck = char(k1);

						if ((k <= 7) && (t >= 0)) {
							// if there is a BLACK PAWN
							if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "p"))
							{
								result = true;

							}
						}
					}
				}



				// KNIGHTS
				//------------------------------------------------------------------------

				// 2 UP & RIGHT
				{

					int t = i + 2;		// rank
					int k = j + 1;		// file

					int t1 = int('1') + t;
					char ct = char(t1);

					int k1 = int('a') + k;
					char ck = char(k1);

					if ((k <= 7) && (t <= 7)) {
						// if there is a KNIGHT
						if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "k"))
						{
							result = true;

						}
					}

				}

				// 2 UP & LEFT
				{
					if (colorKing == 'W')
					{
						int t = i + 2;		// rank
						int k = j - 1;		// file

						int t1 = int('1') + t;
						char ct = char(t1);

						int k1 = int('a') + k;
						char ck = char(k1);

						if ((k >= 0) && (t <= 7)) {
							// if there is a KNIGHT
							if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "k"))
							{
								result = true;

							}
						}
					}
				}

				// 2 DOWN & RIGHT
				{

					int t = i - 2;		// rank
					int k = j + 1;		// file

					int t1 = int('1') + t;
					char ct = char(t1);

					int k1 = int('a') + k;
					char ck = char(k1);

					if ((k <= 7) && (t >= 0)) {
						// if there is a KNIGHT
						if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "k"))
						{
							result = true;

						}
					}

				}

				// 2 DOWN & LEFT
				{

					int t = i - 2;		// rank
					int k = j - 1;		// file

					int t1 = int('1') + t;
					char ct = char(t1);

					int k1 = int('a') + k;
					char ck = char(k1);

					if ((k >= 0) && (t >= 0)) {
						// if there is a KNIGHT
						if (occupied(ct, ck, P, oppositeColor) && (pieceType(ct, ck, P) == "k"))
						{
							result = true;

						}
					}

				}

			}
		}
	}



	return result; // ???????????

}

bool checkmate(position P, color c)
{

	position Res, R;
	set<mov> moves = simpMoves(P, c);	// all simple moves



	if (!(check(P, c)))
	{
		return false;
	}

	// all elements of set simpMoves
	for (std::set<mov>::iterator it = moves.begin(); it != moves.end(); ++it)	// goes through all possible moves
	{
		R = result(P, (mov)*it);		// shows all possible moves

		if (!(check(R, c)))
			return false;
	}
	return true;



}

position result(position P, mov m)
{

	int c1, d1, c2, d2;
	position P2 = P;
	string k;

	string a = m.src;		// for ex "3c"
	string b = m.dst;		// for ex "4c"


	// for initial conditions
	c1 = int(a[0]) - int('0') - 1;		// rank		
	d1 = int(a[1]) - int('a');			// file	


	// for final move
	c2 = int(b[0]) - int('0') - 1;		// rank		
	d2 = int(b[1]) - int('a');			// file	



	k = P2[c1][d1];  // for ex k = "WK"


	P2[c1][d1] = "e";	// empty 

	P2[c2][d2] = k; // update new position


	return P2;
}

bool stalemate(position P, color c)
{
	// there is a stalemate in position p on c's move if
	// c is not in check AND
	// c is in check in every simplified successor of p

//	if (c != check(P, c))

	position Res, R;
	set<mov> moves = simpMoves(P, c);	// all simple moves
	bool st = false;


	if (check(P, c))
		return false;


	for (std::set<mov>::iterator it = moves.begin(); it != moves.end(); ++it)
	{
		R = result(P, (mov)*it);

		if (!(check(R, c)))
			return false;
	}

	return true;
}

bool occupied(Rank r, file f, position P, color c)
{
	// 	string s; //(if problem)

	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a') ;				// make f (file) integer ('char' to int)
	//cout << "This is file" << f << endl;

	if (P[a][b][0] == c)				// if some color on the cell
	{
		return true;					// it is occupied
	}
	else
		return false;

	// s = P[a][b]
	// s.substr(1,0) == c;


}





// LEGAL MOVES FOR EACH PIECE 

set<mov> legalMovesKing(Rank r, file f, position P)	// no check, no stalemate 
{

	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorKing;
	char oppositeColor;

	int i1 = int('1') + a;
	int j1 = int('a') + b;

	char ci = char(i1);
	char cj = char(j1);

	colorKing = pieceColor(ci, cj, P);

	if (colorKing == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';

	set<mov> Res;
	mov m;


	// up
	{
		int i1 = int('1') + a + 1;
		int j1 = int('a') + b;

		char ci = char(i1);
		char cj = char(j1);
		
		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKing))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source

			//	cout << x << " ";
				m.dst = y;			// position for destination
			//	cout << y;
				Res.insert(m);		// unite positions

			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKing))
			{

			}
		}
	}

	// down
	{

		int i1 = int('1') + a - 1;
		int j1 = int('a') + b;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKing))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions

			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKing))
			{

			}
		}
	}

	// right
	{

		int i1 = int('1') + a;
		int j1 = int('a') + b + 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKing))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions

			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKing))
			{

			}
		}
	}

	// left
	{

		int i1 = int('1') + a;
		int j1 = int('a') + b - 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKing))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKing))
			{

			}
		}
	}

	// up & right
	{
		int i1 = int('1') + a + 1;
		int j1 = int('a') + b + 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKing))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKing))
			{

			}
		}
	}

	// up & left
	{
		int i1 = int('1') + a + 1;
		int j1 = int('a') + b - 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKing))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions

			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKing))
			{

			}
		}
	}

	// down & left
	{
		int i1 = int('1') + a - 1;
		int j1 = int('a') + b - 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKing))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKing))
			{

			}
		}
	}

	// down & right
	{

		int i1 = int('1') + a - 1;
		int j1 = int('a') + b + 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKing))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKing))
			{

			}
		}
	}

	return Res;
}

set<mov> legalMovesKnight(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorKnight;
	char oppositeColor;


	int i1 = int('1') + a;
	int j1 = int('a') + b;

	char ci = char(i1);
	char cj = char(j1);

	colorKnight = pieceColor(ci, cj, P);

	if (colorKnight == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';


	set<mov> Res;
	mov m;

	// 2 up & right
	{

		int i1 = int('1') + a + 2;
		int j1 = int('a') + b + 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKnight))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination
				//cout << y<<" ";

				Res.insert(m);		// unite positions
			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKnight))
			{

			}
		}
	}

	// 2 down & left
	{
		int i1 = int('1') + a - 2;
		int j1 = int('a') + b - 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKnight))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(r);	// add rank
				y.push_back(f);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKnight))
			{

			}
		}
	}

	// 2 down & right
	{

		int i1 = int('1') + a - 2;
		int j1 = int('a') + b + 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKnight))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}

			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}

			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKnight))
			{

			}
		}
	}

	// 2 up & left
	{

		int i1 = int('1') + a + 2;
		int j1 = int('a') + b - 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			// if not occupied
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorKnight))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by opposite color
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			// if occupied by the same color
			else if (occupied(ci, cj, P, colorKnight))
			{

			}
		}
	}

	return Res;
}

set<mov> legalMovesRook(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorRook;
	char oppositeColor;

	int i1 = int('1') + a;
	int j1 = int('a') + b;

	char ci = char(i1);
	char cj = char(j1);

	colorRook = pieceColor(ci, cj, P);

	if (colorRook == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';


	set<mov> Res;
	mov m;

	// right
	for (int i = b; i <= 7; ++i) {	// a -1 index

		int i1 = int('1') + a;
		int j1 = int('a') + i + 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorRook))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			else if (occupied(ci, cj, P, colorRook))
			{
				break;
			}
		}
	}

	// forward
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index

		int i1 = int('1') + i + 1;
		int j1 = int('a') + b;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorRook))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			else if (occupied(ci, cj, P, colorRook))
			{
				break;
			}
		}
	}

	// left
	for (int i = b - 1; i <= 7; ++i) {	// a - 1 index

		int i1 = int('1') + a;
		int j1 = int('a') + i - 1;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorRook))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			else if (occupied(ci, cj, P, colorRook))
			{
				break;
			}
		}
	}

	// down
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index

		int i1 = int('1') + i - 1;
		int j1 = int('a') + b;

		char ci = char(i1);
		char cj = char(j1);

		if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorRook))) {

				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
			else if (occupied(ci, cj, P, colorRook))
			{
				break;
			}
		}
	}

	return Res;
}

set<mov> legalMovesPawn(Rank r, file f, position P)
{
	bool oc1;	// occupied by opposite color
	bool oc2;	// occupied by the same color

	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorPawn;
	char oppositeColor;

	int i1 = int('1') + a;
	int j1 = int('a') + b;

	char ci = char(i1);
	char cj = char(j1);

	// defining piece color
	colorPawn = pieceColor(ci, cj, P);

	if (colorPawn == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';

	// local variables
	set<mov> Res;
	mov m;


	// for White Pawns
	if (colorPawn == 'W')
	{
		// MOVING FORWARD
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b) && (b <= 7)) {

			int i1 = int('1') + a + 1;
			int j1 = int('a') + b;

			char ci = char(i1);
			char cj = char(j1);

			// occupied by opposite color
			oc1 = !(occupied(ci, cj, P, oppositeColor));
			// occupied by the same color
			oc2 = !(occupied(ci, cj, P, colorPawn));

			// forward by  if not occupied
			if (oc1 && oc2) {
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
		}

		// FORWARD BY 2 if rank=2 & not occupied
		if ((a == 1) && (0 <= b) && (b <= 7)) {

			int i1 = int('1') + 3;
			int j1 = int('a') + b;

			char ci = char(i1);
			char cj = char(j1);

			oc1 = !(occupied(ci, cj, P, oppositeColor));
			oc2 = !(occupied(ci, cj, P, colorPawn));

			// forward to rank=4
			if (oc1 && oc2) {
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
		}

		// ATTACK UP & RIGHT
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b + 1) && (b + 1 <= 7)) {

			int i1 = int('1') + a + 1;
			int j1 = int('a') + b + 1;

			char ci = char(i1);
			char cj = char(j1);

			// occupied by opposite color
			oc1 = (occupied(ci, cj, P, oppositeColor));

			// attack if opposite color
			if (oc1) {
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}

		}

		// ATTACK UP & LEFT
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b + 1) && (b + 1 <= 7)) {

			int i1 = int('1') + a + 1;
			int j1 = int('a') + b - 1;

			char ci = char(i1);
			char cj = char(j1);

			// occupied by opposite color
			oc1 = (occupied(ci, cj, P, oppositeColor));

			// attack if oppsite color
			if (oc1) {
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}

		}

	}


	// for black Pawns
	if (colorPawn == 'B')
	{
		// MOVING DOWN
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b) && (b <= 7)) {


			int i1 = int('1') + a - 1;
			int j1 = int('a') + b;

			char ci = char(i1);
			char cj = char(j1);

			// not occupied by opposite color
			oc1 = !(occupied(ci, cj, P, oppositeColor));
			// not occupied by the same color
			oc2 = !(occupied(ci, cj, P, colorPawn));

			// down if not occupied
			if (oc1 && oc2) {
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
		}

		// DOWN BY 2 if rank=6 & not occupied
		if ((a == 6) && (0 <= b) && (b <= 7)) {

			int i1 = int('1') + 4;
			int j1 = int('a') + b;

			char ci = char(i1);
			char cj = char(j1);

			oc1 = !(occupied(ci, cj, P, oppositeColor));
			oc2 = !(occupied(ci, cj, P, colorPawn));

			// down to rank=3
			if (oc1 && oc2) {
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}
		}

		// ATTACK DOWN & RIGHT
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b + 1) && (b + 1 <= 7)) {

			int i1 = int('1') + a - 1;
			int j1 = int('a') + b + 1;

			char ci = char(i1);
			char cj = char(j1);

			// occupied by opposite color
			oc1 = (occupied(ci, cj, P, oppositeColor));

			// attack if opposite color
			if (oc1) {
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}

		}

		// ATTACK DOWN & LEFT
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b + 1) && (b + 1 <= 7)) {

			int i1 = int('1') + a - 1;
			int j1 = int('a') + b - 1;

			char ci = char(i1);
			char cj = char(j1);

			// occupied by opposite color
			oc1 = (occupied(ci, cj, P, oppositeColor));

			// attack if oppsite color
			if (oc1) {
				string x("");		// start string for "source"
				x.push_back(r);	// add rank
				x.push_back(f);	// add file

				string y("");		// start string for "destination"
				y.push_back(ci);	// add rank
				y.push_back(cj);	// add file

				m.src = x;			// position for source
				m.dst = y;			// position for destination

				Res.insert(m);		// unite positions
			}

		}

	}


	return Res;
}

set<mov> legalMovesBishop(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// index -> make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// index ->  make f (file) integer ('char' to int)

	char colorBishop;
	char oppositeColor;

	int i1 = int('1') + a;
	int j1 = int('a') + b;

	char ci = char(i1);
	char cj = char(j1);

	colorBishop = pieceColor(r, f, P);

	if (colorBishop == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';


	set<mov> Res;
	mov m;


	// forward & right
	for (int i = a; i <= 7; ++i) {	// a -1 index
		for (int j = b; j <= 7; ++j) {

			int i1 = int('1') + i;
			int j1 = int('a') + j;

			char ci = char(i1);
			//cout << ci << " ";
			char cj = char(j1);
			//cout << cj << " ";

			if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorBishop))) {

					string x("");		// start string for "source"
					x.push_back(r);		// add rank
					x.push_back(f);		// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					cout << x << " ";
					m.dst = y;			// position for destination
						cout << y << " ";
					Res.insert(m);		// unite positions


				}
				else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K")) {

					string x("");		// start string for "source"
					x.push_back(r);		// add rank
					x.push_back(f);		// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					//cout << x << " ";
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions


				}

				else if (occupied(ci, cj, P, colorBishop))
				{
					break;
				}
			}
		}
	}


		// forward & left
		for (int i = a + 1; i <= 7; ++i) {	// a -1 index
			for (int j = b + 1; j <= 7; ++j) {	// b-1

				int i1 = int('1') + i;// +1;
				int j1 = int('a') + j;// -1;

				char ci = char(i1);
				char cj = char(j1);

				if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
					if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorBishop))) {

						string x("");		// start string for "source"
						x.push_back(r);	// add rank
						x.push_back(f);	// add file

						string y("");		// start string for "destination"
						y.push_back(ci);	// add rank
						y.push_back(cj);	// add file

						m.src = x;			// position for source
					//	cout << x << " ";
						m.dst = y;			// position for destination

						Res.insert(m);		// unite positions

					}
					else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
					{
						string x("");		// start string for "source"
						x.push_back(r);	// add rank
						x.push_back(f);	// add file

						string y("");		// start string for "destination"
						y.push_back(ci);	// add rank
						y.push_back(cj);	// add file

						m.src = x;			// position for source
						m.dst = y;			// position for destination

						Res.insert(m);		// unite positions
					}
					else if (occupied(ci, cj, P, colorBishop))
					{
						break;
					}
				}
			}
		}


		// down & left 
		for (int i = a + 1; i <= 7; ++i) {	// a -1 index
			for (int j = b + 1; j <= 7; ++j) {	// b - 1 and a - 1

				int i1 = int('1') + i;// -1;
				int j1 = int('a') + j;// -1;

				char ci = char(i1);
				char cj = char(j1);

				if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
					if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorBishop))) {

						string x("");		// start string for "source"
							x.push_back(r);	// add rank
							x.push_back(f);	// add file

							string y("");		// start string for "destination"
							y.push_back(ci);	// add rank
							y.push_back(cj);	// add file

							m.src = x;			// position for source
							m.dst = y;			// position for destination

						Res.insert(m);		// unite positions

					}
					else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
					{
						string x("");		// start string for "source"
						x.push_back(r);	// add rank
						x.push_back(f);	// add file

						string y("");		// start string for "destination"
						y.push_back(ci);	// add rank
						y.push_back(cj);	// add file

						m.src = x;			// position for source
						m.dst = y;			// position for destination

						Res.insert(m);		// unite positions
					}
					else if (occupied(ci, cj, P, colorBishop))
					{
						break;
					}
				}
			}
		}

		// down & right
		for (int i = a + 1; i <= 7; ++i) {	// a -1 index
			for (int j = b + 1; j <= 7; ++j) {

				int i1 = int('1') + i;// -1;
				int j1 = int('a') + j;// +1;

				char ci = char(i1);
				char cj = char(j1);

				if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
					if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorBishop))) {

						string x("");		// start string for "source"
						x.push_back(r);	// add rank
						x.push_back(f);	// add file

						string y("");		// start string for "destination"
						y.push_back(ci);	// add rank
						y.push_back(cj);	// add file

						m.src = x;			// position for source
						m.dst = y;			// position for destination

						Res.insert(m);		// unite positions

					}
					else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
					{
						string x("");		// start string for "source"
						x.push_back(r);	// add rank
						x.push_back(f);	// add file

						string y("");		// start string for "destination"
						y.push_back(ci);	// add rank
						y.push_back(cj);	// add file

						m.src = x;			// position for source
						m.dst = y;			// position for destination

						Res.insert(m);		// unite positions
					}
					else if (occupied(ci, cj, P, colorBishop))
					{
						break;
					}
				}
			}
		}


		return Res;
	
}

set<mov> legalMovesQueen(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorQueen;
	char oppositeColor;

	int i1 = int('1') + a;
	int j1 = int('a') + b;

	char ci = char(i1);
	char cj = char(j1);

	colorQueen = pieceColor(ci, cj, P);

	if (colorQueen == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';


	set<mov> Res;
	mov m;


	// forward & right
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b; j <= 7; ++j) {

			int i1 = int('1') + i + 1;
			int j1 = int('a') + j + 1;

			char ci = char(i1);
			char cj = char(j1);

			if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				// if not occupied by any color
				if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorQueen))) {

					string x("");		// start string for "source"
						x.push_back(r);	// add rank
						x.push_back(f);	// add file

						string y("");		// start string for "destination"
						y.push_back(ci);	// add rank
						y.push_back(cj);	// add file

						m.src = x;			// position for source
						m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by opposite color
				else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
				{
					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by the same color
				else if (occupied(ci, cj, P, colorQueen))
				{
					break;
				}
			}
		}

		return Res;
	}

	// right
	for (int i = a - 1; i <= 7; ++i) {	// a - 1 index
		for (int j = b; j <= 7; ++j) {

			int i1 = int('1') + i;
			int j1 = int('a') + j + 1;

			char ci = char(i1);
			char cj = char(j1);

			if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				// if not occupied by any color
				if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorQueen))) {

					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by opposite color
				else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
				{
					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by the same color
				else if (occupied(ci, cj, P, colorQueen))
				{
					break;
				}
			}
		}
	}

	// forward
	for (int i = a - 1; i <= 7; ++i) {	// a - 1 index
		for (int j = b; j <= 7; ++j) {

			int i1 = int('1') + i + 1;
			int j1 = int('a') + j;

			char ci = char(i1);
			char cj = char(j1);

			if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				// if not occupied by any color
				if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorQueen))) {

					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by opposite color
				else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))
				{
					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by the same color
				else if (occupied(ci, cj, P, colorQueen))
				{
					break;
				}
			}
		}
	}

	// forward & left
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b; j <= 7; ++j) {

			int i1 = int('1') + i + 1;
			int j1 = int('a') + j - 1;

			char ci = char(i1);
			char cj = char(j1);

			if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				// if not occupied
				if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorQueen))) {

					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by opposite color
				else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
				{
					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by the same color
				else if (occupied(ci, cj, P, colorQueen))
				{
					break;
				}
			}
		}
	}

	// left
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b; j <= 7; ++j) {

			int i1 = int('1') + i;
			int j1 = int('a') + j - 1;

			char ci = char(i1);
			char cj = char(j1);

			if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				// if not occupied
				if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorQueen))) {

					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by opposite color
				else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
				{
					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if cooupied by the same color
				else if (occupied(ci, cj, P, colorQueen))
				{
					break;
				}
			}
		}
	}

	// down & left 
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b; j <= 7; ++j) {

			int i1 = int('1') + i - 1;
			int j1 = int('a') + j - 1;

			char ci = char(i1);
			char cj = char(j1);

			if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				// if not occupied
				if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorQueen))) {

					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by opposite color
				else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
				{
					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by the same color
				else if (occupied(ci, cj, P, colorQueen))
				{
					break;
				}
			}
		}
	}

	// down
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b; j <= 7; ++j) {

			int i1 = int('1') + i - 1;
			int j1 = int('a') + j;

			char ci = char(i1);
			char cj = char(j1);

			if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				// if not occupied
				if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorQueen))) {

					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by opposite color
				else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
				{
					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}
				// if occupied by the same color
				else if (occupied(ci, cj, P, colorQueen))
				{
					break;
				}
			}
		}
	}

	// down & right
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b; j <= 7; ++j) {

			int i1 = int('1') + i - 1;
			int j1 = int('a') + j + 1;

			char ci = char(i1);
			char cj = char(j1);

			if (!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				// if not occupied
				if (!occupied(ci, cj, P, oppositeColor) && !(occupied(ci, cj, P, colorQueen))) {

					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}

				// if occupied by opposite color
				else if (occupied(ci, cj, P, oppositeColor) && !(pieceType(ci, cj, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
				{
					string x("");		// start string for "source"
					x.push_back(r);	// add rank
					x.push_back(f);	// add file

					string y("");		// start string for "destination"
					y.push_back(ci);	// add rank
					y.push_back(cj);	// add file

					m.src = x;			// position for source
					m.dst = y;			// position for destination

					Res.insert(m);		// unite positions
				}

				// if occupied by the same color
				else if (occupied(ci, cj, P, colorQueen))
				{
					break;
				}
			}
		}
	}

	return Res;
}



// ready
string pieceType(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	string pT;			// piece type 
	pT = P[a][b][1];	// take second letter from the string
	return pT;
}

// ready
color pieceColor(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char col;			// piece type 
	col = P[a][b][0];	// take second letter from the string
	return col;
}

set<mov> legalMoves(Rank r, file f, position P)
{


	string pT;


	pT = pieceType(r, f, P);



	if (pT == "K")
		return legalMovesKing(r, f, P);

	else if (pT == "b")						 // piece is a bishop
		return legalMovesBishop(r, f, P);

	else if (pT == "k")						 // piece is a knight
		return legalMovesKnight(r, f, P);

	else if (pT == "r")						 // piece is a rook
		return legalMovesRook(r, f, P);

	else if (pT == "Q")					     // piece is a queen
		return legalMovesQueen(r, f, P);

	else if (pT == "p")						 // piece is a pawn
		return legalMovesPawn(r, f, P);


}



// MAJOR FUNCTION
set<mov> simpMoves(position P, color c)
{
	// define sets
	set<mov> Res;
	set<mov> ResOutput;


	for (int i = 0; i <= 7; ++i)
	{
		for (int j = 0; j <= 7; ++j)
		{

			int i1 = int('1') + i;
			int j1 = int('a') + j;

			char ci = char(i1);
			char cj = char(j1);

		//	cout << ci << "   " << cj << endl;

			if (occupied(ci, cj, P, c))
				ResOutput = legalMoves(ci, cj, P);

			Res.insert(ResOutput.begin(), ResOutput.end());		// union of both sets
		}
	}
	return Res;
}

set<mov> legalMoves(position P, color c)
{

	set<mov> Res;
	mov mm;
	position p2;


	if (checkmate(P, c) || (stalemate(P, c)))
		return Res;



	Res = simpMoves(P, c);

	for (std::set<mov>::iterator it = Res.begin(); it != Res.end(); ++it)
	{
		mm = *it;
		p2 = result(P, mm);

		if (check(p2, c) == true)
		{
			Res.erase(it);
		}


	}

	//return Res;
}




