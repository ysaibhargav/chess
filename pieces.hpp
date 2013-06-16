#ifndef PIECES_H_
	#define PIECES_H_

	using namespace std;

	class Piece{
		private:
		public:
			const bool isBlack;
			int value;		
			bool isDead;
			pair<int, int> pos;
			Piece():isBlack(0){
				value = 0;
			}
			Piece(bool iB, int v, pair<int, int> p, Piece* Board[8][8], Piece* piece):isBlack(iB){
				isDead = 0;	
				value = v;
				Board[p.first][p.second] = piece;
				pos = p;
			}
			~Piece(){
			}
	};
	Piece* chessBoard[8][8];
	Piece* _chessBoard[8][8];
	Piece wRook1(0, 500, make_pair(0,0), chessBoard, &wRook1);
	Piece wKnight1(0, 301, make_pair(0,1), chessBoard, &wKnight1);
	Piece wBishop1(0, 300, make_pair(0,2), chessBoard, &wBishop1);
	Piece wQueen(0, 900, make_pair(0,3), chessBoard, &wQueen);
	Piece wKing(0, 1000000, make_pair(0,4), chessBoard, &wKing);
	Piece wBishop2(0, 300, make_pair(0,5), chessBoard, &wBishop2);
	Piece wKnight2(0, 301, make_pair(0,6), chessBoard, &wKnight2);
	Piece wRook2(0, 500, make_pair(0,7), chessBoard, &wRook2);
	Piece wPawn1(0, 100, make_pair(1,0), chessBoard, &wPawn1);
	Piece wPawn2(0, 100, make_pair(1,1), chessBoard, &wPawn2);
	Piece wPawn3(0, 100, make_pair(1,2), chessBoard, &wPawn3);
	Piece wPawn4(0, 100, make_pair(1,3), chessBoard, &wPawn4);
	Piece wPawn5(0, 100, make_pair(1,4), chessBoard, &wPawn5);
	Piece wPawn6(0, 100, make_pair(1,5), chessBoard, &wPawn6);
	Piece wPawn7(0, 100, make_pair(1,6), chessBoard, &wPawn7);
	Piece wPawn8(0, 100, make_pair(1,7), chessBoard, &wPawn8);
	
	Piece bRook1(1, 500, make_pair(7,0), chessBoard, &bRook1);
	Piece bKnight1(1, 301, make_pair(7,1), chessBoard, &bKnight1);
	Piece bBishop1(1, 300, make_pair(7,2), chessBoard, &bBishop1);
	Piece bQueen(1, 900, make_pair(7,3), chessBoard, &bQueen);
	Piece bKing(1, 1000000, make_pair(7,4), chessBoard, &bKing);
	Piece bBishop2(1, 300, make_pair(7,5), chessBoard, &bBishop2);
	Piece bKnight2(1, 301, make_pair(7,6), chessBoard, &bKnight2);
	Piece bRook2(1, 500, make_pair(7,7), chessBoard, &bRook2);
	Piece bPawn1(1, 100, make_pair(6,0), chessBoard, &bPawn1);
	Piece bPawn2(1, 100, make_pair(6,1), chessBoard, &bPawn2);
	Piece bPawn3(1, 100, make_pair(6,2), chessBoard, &bPawn3);
	Piece bPawn4(1, 100, make_pair(6,3), chessBoard, &bPawn4);
	Piece bPawn5(1, 100, make_pair(6,4), chessBoard, &bPawn5);
	Piece bPawn6(1, 100, make_pair(6,5), chessBoard, &bPawn6);
	Piece bPawn7(1, 100, make_pair(6,6), chessBoard, &bPawn7);
	Piece bPawn8(1, 100, make_pair(6,7), chessBoard, &bPawn8);

	Piece def;

	int wCount = 16, bCount = 16, count = 16, moveCount = 0;

	bool wCheck = 0, bCheck = 0, wKMove = 0, bKMove = 0;

	pair<int, int> ini, fin;
	
	void init();

	void disp(Piece* chessBoard[][8]);
	
	bool end();

	void getInput();
	
	void move(pair<int, int> ip, pair<int, int> fp);

	bool isMoveValid(pair<int, int> ip, pair<int, int> fp);

	bool isAllowed(pair<int, int> ip, pair<int, int> fp, int v);

	pair<bool, pair<int, int> > isKingCheck(bool color);

	bool checkmate(bool color);

	void AIResponse();

	int maxi(int depth);

	int mini(int depth);

	int evaluate();
#endif
