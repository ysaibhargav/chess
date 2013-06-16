#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "pieces.hpp"

main(){	
	init();
	while(!end()){
		moveCount++;
		cout << "C++ CHESS GAME\nVersion 0.85\nCreated and developed by Sai Bhargav\n";
		disp(chessBoard);
		getInput();
		//AIResponse();
		disp(chessBoard);
		if(wCount == 1 || bCount == 1)
			--count;
		if(count == 0){
			cout << "Draw!\n";
			break;
		}
	}
	disp(chessBoard);
	return 0;
}

void init(){
	for(int i=2; i<6; i++){
		for(int j=0; j<8; j++){
			chessBoard[i][j] = &def;
		}
	}
}

void getInput(){
	cout << "Enter coordinates of piece you wish to select" << endl;
	pair<int, int> ip;
	cin >> ip.first >> ip.second;
	if(chessBoard[ip.first][ip.second]->value == 0){
		cout << "Invalid choice!" << endl;
		getInput();
	}
	else{
		cout << "Select final position" << endl;
		pair<int, int> fp;
		cin >> fp.first >> fp.second;
		if(!isMoveValid(ip, fp)){
			cout << "Invalid choice!" << endl;
			getInput();
		}
	}
}
	
bool isMoveValid(pair<int, int> ip, pair<int, int> fp){
	/*if(chessBoard[ip.first][ip.second]->value == 0)
		return 0;
	else{*/
		if(isKingCheck(chessBoard[ip.first][ip.second]->isBlack).first){
			if(!wCheck || !bCheck)
				if(chessBoard[ip.first][ip.second]->isBlack){
					if(!bCheck)	bCheck = 1;
				}
				else{	
					if(!wCheck)	wCheck = 1;
				}
			Piece* temp = chessBoard[fp.first][fp.second];
			move(ip, fp);
			if(isKingCheck(chessBoard[fp.first][fp.second]->isBlack).first){
				move(fp, ip);
				chessBoard[fp.first][fp.second] = temp;
				return 0;
			}
			move(fp, ip);
			chessBoard[fp.first][fp.second] = temp;
		}
		int n = 0, dx = (fp.first-ip.first > 0)?(fp.first-ip.first):(ip.first-fp.first);
		int dy = (fp.second-ip.second > 0)?(fp.second-ip.second):(ip.second-fp.second);
		switch(chessBoard[ip.first][ip.second]->value){
			case 100: n = chessBoard[ip.first][ip.second]->isBlack?(-1):1;
				if((fp.first-ip.first == n || (fp.first-ip.first == 2*n && chessBoard[ip.first+n][ip.second]->value == 0)) && (fp.second == ip.second) && (chessBoard[fp.first][fp.second]->value == 0)){
					Piece* temp = chessBoard[fp.first][fp.second];
					move(ip, fp);
					if(isKingCheck(chessBoard[fp.first][fp.second]->isBlack).first){
						move(fp, ip);
						chessBoard[fp.first][fp.second] = temp;
						cout << "Watch your king!\n";
						return 0;
					}
					else
						return 1;
				}
				else if((fp.first-ip.first == n) && (fp.second - ip.second == -1) && chessBoard[fp.first][fp.second]->value > 0 && (isAllowed(ip, fp, 100))){
					Piece* temp = chessBoard[fp.first][fp.second];
					move(ip, fp);
					if(isKingCheck(chessBoard[fp.first][fp.second]->isBlack).first){
						move(fp, ip);
						chessBoard[fp.first][fp.second] = temp;
						cout << "Watch your king!\n";
						return 0;
					}
					else
						return 1;
				}
				else if((fp.first-ip.first == n) && (fp.second - ip.second == 1) && chessBoard[fp.first][fp.second]->value > 0 &&(isAllowed(ip, fp, 100))){
					Piece* temp = chessBoard[fp.first][fp.second];
					move(ip, fp);
					if(isKingCheck(chessBoard[fp.first][fp.second]->isBlack).first){
						move(fp, ip);
						chessBoard[fp.first][fp.second] = temp;
						cout << "Watch your king!\n";
						return 0;
					}
					else
						return 1;
				}
				else return 0;
				break;
			case 300: if(dx == dy && isAllowed(ip, fp, 300)){
					Piece* temp = chessBoard[fp.first][fp.second];
					move(ip, fp);
					if(isKingCheck(chessBoard[fp.first][fp.second]->isBlack).first){
						move(fp, ip);
						chessBoard[fp.first][fp.second] = temp;
						cout << "Watch your king!\n";
						return 0;
					}
					else
						return 1;
				}					
				else return 0;
				break;
			case 301: if((((dx == 2)&&(dy == 1))||((dy == 2)&&(dx == 1))) && isAllowed(ip, fp, 301)){
					Piece* temp = chessBoard[fp.first][fp.second];
					move(ip, fp);
					if(isKingCheck(chessBoard[fp.first][fp.second]->isBlack).first){
						move(fp, ip);
						chessBoard[fp.first][fp.second] = temp;
						cout << "Watch your king!\n";
						return 0;
					}
					else
						return 1;
				}					
				else return 0;
				break;
			case 500: if((dx == 0 || dy == 0) && isAllowed(ip, fp, 500)){
					Piece* temp = chessBoard[fp.first][fp.second];
					move(ip, fp);
					if(isKingCheck(chessBoard[fp.first][fp.second]->isBlack).first){
						move(fp, ip);
						chessBoard[fp.first][fp.second] = temp;
						cout << "Watch your king!\n";
						return 0;
					}
					else
						return 1;
				}					
				else return 0;
				break;
			case 900: if((dx == 0 || dy == 0 || dx == dy) && isAllowed(ip, fp, 900)){
					Piece* temp = chessBoard[fp.first][fp.second];
					move(ip, fp);
					if(isKingCheck(chessBoard[fp.first][fp.second]->isBlack).first){
						move(fp, ip);
						chessBoard[fp.first][fp.second] = temp;
						cout << "Watch your king!\n";
						return 0;
					}
					else
						return 1;
				}					
				else return 0;
				break;
			case 1000000: if(dx<= 1 && dy <= 1 && isAllowed(ip, fp, 1000000)){
						Piece* temp = chessBoard[fp.first][fp.second];
						move(ip, fp);
						if(isKingCheck(chessBoard[fp.first][fp.second]->isBlack).first){
							move(fp, ip);
							chessBoard[fp.first][fp.second] = temp;
							cout << "Watch your king!\n";
							return 0;
						}
						else{
							if(chessBoard[ip.first][ip.second]->isBlack)	bKMove = 1;
							else wKMove = 1;
							return 1;
						}
					 }
					 else if(chessBoard[ip.first][ip.second]->isBlack?(!bKMove && !bCheck):(!wKMove && !wCheck)){
						 if(fp.second == 2 && chessBoard[ip.first][ip.second]->isBlack?(chessBoard[7][0]->value == 500):(chessBoard[0][0]->value == 500) || fp.second == 6 && chessBoard[ip.first][ip.second]->isBlack?(chessBoard[7][7]->value == 500):(chessBoard[0][7]->value == 500)){
						 if(chessBoard[ip.first][ip.second]->isBlack){
							 if(fp.second == 2 && chessBoard[7][1]->value > 0)	return 0;
							 int yLimit = (fp.second - 4) > 0?(fp.second - 4):(4 - fp.second);
							 for(int dy = 1; dy <= yLimit; dy++){
							 	int fy = (fp.second - 4) > 0?(4 + dy):(4 - dy);
								if(chessBoard[7][fy]->value > 0)	return 0;
								Piece* temp = chessBoard[7][fy];
								move(make_pair(7, 4), make_pair(7, fy));
								if(isKingCheck(1).first){
									move(make_pair(7, fy), make_pair(7, 4));
									chessBoard[7][fy] = temp;
									return 0;
								}
								move(make_pair(7, fy), make_pair(7, 4));
								chessBoard[7][fy] = temp;
							 }
							 move(make_pair(7, 4), make_pair(7, fp.second));
							 move(make_pair(7, (fp.second == 2)?0:7), make_pair(7, (fp.second == 2)?3:5));
							 return 1;
						 }
						 else{
							 if(fp.second == 2 && chessBoard[0][1]->value > 0)	return 0;
							 int yLimit = (fp.second - 4) > 0?(fp.second - 4):(4 - fp.second);
							 for(int dy = 1; dy <= yLimit ; dy++){
							 	int fy = (fp.second - 4) > 0?(4 + dy):(4 - dy);
								if(chessBoard[0][fy]->value > 0)	return 0;
								Piece* temp = chessBoard[0][fy];
								move(make_pair(0, 4), make_pair(0, fy));
								if(isKingCheck(0).first){
									move(make_pair(0, fy), make_pair(0, 4));
									chessBoard[0][fy] = temp;
									return 0; 
								}
								move(make_pair(0, fy), make_pair(0, 4));
								chessBoard[0][fy] = temp;
							 }
							 move(make_pair(0, 4), make_pair(0, fp.second));
							 move(make_pair(0, (fp.second == 2)?0:7), make_pair(0, (fp.second == 2)?3:5));
							 return 1;
						 }
					 }
					 else return 0;
					 break;
		}
	}
}
	
void move(pair<int, int> ip, pair<int, int> fp){
	if(chessBoard[fp.first][fp.second]->value > 0 && (fp.first != ip.first || fp.second != ip.second)){
		chessBoard[fp.first][fp.second]->isBlack?(--bCount):(--wCount);
		chessBoard[fp.first][fp.second]->isDead = 1;
	}
	chessBoard[fp.first][fp.second] = chessBoard[ip.first][ip.second];
	chessBoard[ip.first][ip.second] = &def;
	chessBoard[fp.first][fp.second]->pos = fp;
	/*if(chessBoard[fp.first][fp.second]->isBlack && chessBoard[fp.first][fp.second]->value == 100 && fp.first == 0){
		cout << "Promote black pawn to:\n100->Black pawn\n300->Black bishop\n301->Black knight\n500->Black rook\n900->Black queen\n";
		int n;
		cin >> n;
		if(n == 100 || n == 300 || n == 301 || n == 500 || n == 900){
			 chessBoard[fp.first][fp.second]->value = n;
		}
		else{
			cout << "Invalid choice!\n";
			move(fp, fp);
		}
	}
	else if(!chessBoard[fp.first][fp.second]->isBlack && chessBoard[fp.first][fp.second]->value == 100 && fp.first == 7){
		cout << "Promote white pawn to:\n100->White pawn\n300->White bishop\n301->White knight\n500->White rook\n900->White queen\n";
		int n;
		cin >> n;
		if(n == 100 || n == 300 || n == 301 || n == 500 || n == 900){
			 chessBoard[fp.first][fp.second]->value = n;
		}
		else{
			cout << "Invalid choice!\n";
			move(fp, fp);
		}
	}*/
}

bool isAllowed(pair<int, int> ip, pair<int, int> fp, int v){
	bool result = 1;
	bool isColorSame = (chessBoard[fp.first][fp.second]->isBlack == chessBoard[ip.first][ip.second]->isBlack);
	bool isPiecePresent = (chessBoard[fp.first][fp.second]->value > 0);
	bool isKingPresent = chessBoard[fp.first][fp.second]->value == 1000000;
	if((isColorSame && isPiecePresent) || isKingPresent)
		result = 0;
	else{
		bool isXPos = (fp.first - ip.first > 0);
		bool isYPos = (fp.second - ip.second > 0);
		switch(v){
			case 900:
			case 300: for(int dr = 1; dr < (isXPos?(fp.first - ip.first):(ip.first - fp.first)); dr++){
					if(fp.first - ip.first != 0 && fp.second - ip.second != 0){
						int x = (isXPos?(ip.first + dr):(ip.first - dr));
						int y = (isYPos?(ip.second + dr):(ip.second - dr));
						if(chessBoard[x][y]->value > 0){
							cout << "Cannot jump!\n";
							result = 0;			
							break;
						}
					}
				}
				if(v != 900)	break;
			case 500: if(fp.first - ip.first == 0){
					for(int dy = 1; dy < (isYPos?(fp.second - ip.second):(ip.second - fp.second)); dy++){
						int x = ip.first; 
						int y = (isYPos?(ip.second + dy):(ip.second - dy));
						if(chessBoard[x][y]->value > 0){
							cout << "Cannot jump!\n";
							result = 0;			
							break;
						}
					}
				}
				else if(fp.second - ip.second == 0){
					for(int dx = 1; dx < (isXPos?(fp.first - ip.first):(ip.first - fp.first)); dx++){
						int y = ip.second; 
						int x = (isXPos?(ip.first + dx):(ip.first - dx));
						if(chessBoard[x][y]->value > 0){
							cout << "Cannot jump!\n";
							result = 0;			
							break;
						}
					}
				}
				break;
		}
	}
	
	return result;
}
	

void disp(Piece* chessBoard[][8]){
	for(int i=7; i>=0; i--){
		cout << i << "   ";
		for(int j=0; j<8; j++){
			switch(chessBoard[i][j]->value){
				case 0: cout << "-   ";
					break;
				case 100: if(chessBoard[i][j]->isBlack) {cout << "BP  ";}
					else {cout << "WP  ";}
					break;
				case 300: if(chessBoard[i][j]->isBlack) {cout << "BB  ";}
					else {cout << "WB  ";}
					break;
				case 301: if(chessBoard[i][j]->isBlack) {cout << "BKn ";}
					else {cout << "WKn ";}
					break;
				case 500: if(chessBoard[i][j]->isBlack) {cout << "BR  ";}
					else {cout << "WR  ";}
					break;
				case 900: if(chessBoard[i][j]->isBlack) {cout << "BQ  ";}
					else {cout << "WQ  ";}
					break;
				default: if(chessBoard[i][j]->isBlack) {cout << "BK  ";}
					else {cout << "WK  ";}
					break;
			};
		}
		cout << endl;
		cout << endl;
		if(i == 0){
			cout <<"    0   1   2   3   4   5   6   7\n";	
		}
	}
}

pair<bool, pair<int, int> > isKingCheck(bool color){
	int x, y;
	if(color){
		x = bKing.pos.first;
		y = bKing.pos.second;
	}
	else{
		x = wKing.pos.first;
		y = wKing.pos.second;	
	}
	//Checked by a pawn
	if(color){
		if(x > 1){
			if((chessBoard[x-1][y-1]->value == 100 && chessBoard[x-1][y-1]->isBlack != color) || (chessBoard[x-1][y+1]->value == 100 && chessBoard[x-1][y+1]->isBlack != color))
				return make_pair(1, chessBoard[x-1][y-1]->value == 100?make_pair(x-1, y-1):make_pair(x-1, y+1));
		}
	}
	else{	
		if(x < 6){
			if((chessBoard[x+1][y-1]->value == 100 && chessBoard[x+1][y-1]->isBlack != color) || (chessBoard[x+1][y+1]->value == 100 && chessBoard[x+1][y+1]->isBlack != color))
				return make_pair(1, chessBoard[x+1][y-1]->value == 100?make_pair(x+1, y-1):make_pair(x+1, y+1));
		}
	}
	//Checked by a knight
	bool q11 = 0, q12 = 0, q21 = 0, q22 = 0, q31 = 0, q32 = 0, q41 = 0, q42 = 0;
	if(x < 7 && y < 6) q11 = chessBoard[x+1][y+2]->value == 301 && chessBoard[x+1][y+2]->isBlack != color;
	if(q11)	return make_pair(1, make_pair(x+1, y+2));
	if(y < 7 && x < 6) q12 = chessBoard[x+2][y+1]->value == 301 && chessBoard[x+2][y+1]->isBlack != color;
	if(q12)	return make_pair(1, make_pair(x+2, y+1));
	if(x < 6 && y > 0) q21 = chessBoard[x+2][y-1]->value == 301 && chessBoard[x+2][y-1]->isBlack != color;
	if(q21)	return make_pair(1, make_pair(x+2, y-1));
	if(x < 7 && y > 1) q22 = chessBoard[x+1][y-2]->value == 301 && chessBoard[x+1][y-2]->isBlack != color;
	if(q22)	return make_pair(1, make_pair(x+1, y-2));
	if(x > 0 && y > 1) q31 = chessBoard[x-1][y-2]->value == 301 && chessBoard[x-1][y-2]->isBlack != color;
	if(q31)	return make_pair(1, make_pair(x-1, y-2));
	if(x > 1 && y > 0) q32 = chessBoard[x-2][y-1]->value == 301 && chessBoard[x-2][y-1]->isBlack != color;
	if(q32)	return make_pair(1, make_pair(x-2, y-1));
	if(x > 1 && y < 7) q41 = chessBoard[x-2][y+1]->value == 301 && chessBoard[x-2][y+1]->isBlack != color;
	if(q41)	return make_pair(1, make_pair(x-2, y+1));
	if(x > 0 && y < 6) q22 = chessBoard[x-1][y+2]->value == 301 && chessBoard[x-1][y+2]->isBlack != color;
	if(q42)	return make_pair(1, make_pair(x-1, y+2));
	//Checked by a bishop or a queen(diagnolly)
	for(int dr = 1; ; dr++){
		if(x + dr > 7 || y + dr > 7)
			break;
		if(chessBoard[x+dr][y+dr]->value > 0){
			if((chessBoard[x+dr][y+dr]->value == 300 || chessBoard[x+dr][y+dr]->value == 900) && chessBoard[x+dr][y+dr]->isBlack != color)
				return make_pair(1, make_pair(x+dr, y+dr));
			else 
				break;
		}
	}
	for(int dr = 1; ; dr++){
		if(x + dr > 7 || y - dr < 0)
			break;
		if(chessBoard[x+dr][y-dr]->value > 0){
			if((chessBoard[x+dr][y-dr]->value == 300 || chessBoard[x+dr][y-dr]->value == 900) && chessBoard[x+dr][y-dr]->isBlack != color)
				return make_pair(1, make_pair(x+dr, y-dr));
			else 
				break;
		}
	}
	for(int dr = 1; ; dr++){
		if(x - dr < 0 || y - dr < 0)
			break;
		if(chessBoard[x-dr][y-dr]->value > 0){
			if((chessBoard[x-dr][y-dr]->value == 300 || chessBoard[x-dr][y-dr]->value == 900) && chessBoard[x-dr][y-dr]->isBlack != color)
				return make_pair(1, make_pair(x-dr, y-dr));
			else 
				break;
		}
	}
	for(int dr = 1; ; dr++){
		if(x - dr < 0 || y + dr > 7)
			break;
		if(chessBoard[x-dr][y+dr]->value > 0){
			if((chessBoard[x-dr][y+dr]->value == 300 || chessBoard[x-dr][y+dr]->value == 900) && chessBoard[x-dr][y+dr]->isBlack != color)
				return make_pair(1, make_pair(x-dr, y+dr));
			else 
				break;
		}
	}
	//Checked by a rook or a queen(vertically or horizontally)
	for(int dx = 1; ; dx++){
		if(x + dx > 7)
			break;
		if(chessBoard[x+dx][y]->value > 0){
			if((chessBoard[x+dx][y]->value == 500 || chessBoard[x+dx][y]->value == 900) && chessBoard[x+dx][y]->isBlack != color)
				return make_pair(1, make_pair(x+dx, y));
			else 
				break;
		}
	}
	for(int dx = 1; ; dx++){
		if(x - dx < 0)
			break;
		if(chessBoard[x-dx][y]->value > 0){
			if((chessBoard[x-dx][y]->value == 500 || chessBoard[x-dx][y]->value == 900) && chessBoard[x-dx][y]->isBlack != color)
				return make_pair(1, make_pair(x-dx, y));
			else 
				break;
		}
	}
	for(int dy = 1; ; dy++){
		if(y + dy > 7)
			break;
		if(chessBoard[x][y+dy]->value > 0){
			if((chessBoard[x][y+dy]->value == 500 || chessBoard[x][y+dy]->value == 900) && chessBoard[x][y+dy]->isBlack != color)
				return make_pair(1, make_pair(x, y+dy));
			else 
				break;
		}
	}	
	for(int dy = 1; ; dy++){
		if(y - dy < 0)
			break;
		if(chessBoard[x][y-dy]->value > 0){
			if((chessBoard[x][y-dy]->value == 500 || chessBoard[x][y-dy]->value == 900) && chessBoard[x][y-dy]->isBlack != color)
				return make_pair(1, make_pair(x, y-dy));
			else 
				break;
		}
	}
	return make_pair(0, make_pair(-1, -1));
}

bool end(){	
	if(checkmate(0) || checkmate(1))
		return 1;
	else	return 0;				
}

bool checkmate(bool color){
	int x, y;
	if(color){
		x = bKing.pos.first;
		y = bKing.pos.second;
	}
	else{
		x = wKing.pos.first;
		y = wKing.pos.second;	
	}
	bool isKingUnderCheck = isKingCheck(color).first;
	pair<int, int> pos = isKingCheck(color).second;
	if(isKingUnderCheck){
		for(int dx = -1; dx < 2; dx++){
			for(int dy = -1; dy < 2; dy++){
				if(x + dx > -1 && x + dx < 8 && y + dy > -1 && y + dy < 8){
					if(chessBoard[x+dx][y+dy]->value == 0){
						move(make_pair(x, y), make_pair(x+dx, y+dy));
						if(!isKingCheck(color).first){
							move(make_pair(x+dx, y+dy), make_pair(x, y));
							return 0;
						}
						move(make_pair(x+dx, y+dy), make_pair(x, y));
					}
					else if(chessBoard[x+dx][y+dy]->isBlack != color && chessBoard[x+dx][y+dy]->value > 0){
						Piece* temp = chessBoard[x+dx][y+dy];
						if(isMoveValid(make_pair(x, y), make_pair(x+dx, y+dy))){
							move(make_pair(x+dx, y+dy), make_pair(x, y));
							chessBoard[x+dx][y+dy] = temp;
							return 0;
						}
					}
				}
			}
		}
		int dx = (x - pos.first > 0)?(x - pos.first):(pos.first - x);
		int dy = (y - pos.second > 0)?(y - pos.second):(pos.second - y);
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				if(chessBoard[i][j]->isBlack == color && chessBoard[i][j]->value != 1000000){
					if(dx == dy){
						for(int dr = 1; dr <= dx; dr++){
							bool isXBounded, isYBounded;
							int fx = (x - pos.first > 0)?(i + dr):(i - dr);
							int fy = (y - pos.second > 0)?(j + dr):(j - dr);
							if(x - pos.first > 0)	isXBounded = fx <= pos.first;
							else	isXBounded = fx >= pos.first;
							if(y - pos.second > 0)	isYBounded = fy <= pos.second;
							else	isYBounded = fy >= pos.second;
							Piece* temp = chessBoard[fx][fy];
							if(isXBounded && isYBounded)
								if(isMoveValid(make_pair(i, j), make_pair(fx, fy))){
									move(make_pair(fx, fy), make_pair(i, j));
									chessBoard[fx][fy] = temp;
									return 0;
								}
						}
					}
					else if(dx == 0){
						for(int dr = 1; dr <= dy; dr++){
							bool isXBounded, isYBounded;
							int fx = x;
							int fy = (y - pos.second > 0)?(j + dr):(j - dr);
							if(y - pos.second > 0)	isYBounded = fy <= pos.second;
							else	isYBounded = fy >= pos.second;
							Piece* temp = chessBoard[fx][fy];
							if(isYBounded)
								if(isMoveValid(make_pair(i, j), make_pair(fx, fy))){
									move(make_pair(fx, fy), make_pair(i, j));
									chessBoard[fx][fy] = temp;
									return 0;
								}
						}
					}
					else if(dy == 0){
						for(int dr = 1; dr <= dx; dr++){
							bool isXBounded, isYBounded;
							int fy = y;
							int fx = (x - pos.first > 0)?(i + dr):(i - dr);
							if(x - pos.first > 0)	isXBounded = fx <= pos.first;
							else	isXBounded = fx >= pos.first;
							Piece* temp = chessBoard[fx][fy];
							if(isXBounded)
								if(isMoveValid(make_pair(i, j), make_pair(fx, fy))){
									move(make_pair(fx, fy), make_pair(i, j));
									chessBoard[fx][fy] = temp;
									return 0;
								}
						}
					}
					else if((dx == 2 && dy == 1) || (dx == 1 && dy == 2)){
						Piece* temp = chessBoard[pos.first][pos.second];
						if(isMoveValid(make_pair(i, j), pos)){
							move(pos, make_pair(i, j));
							chessBoard[pos.first][pos.second] = temp;
							return 0;
						}
					}
				}
			}
		}
	string c = !color?"Black":"White";
	cout << c << " wins!\n";
	return 1;	
	}
	else	return 0;
}

void AIResponse(){
	if(moveCount < 2){
		srand(time(NULL));
		int io = rand()%2 + 6;
		int jo = rand()%8;
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				if(io != i || jo != j){
					if(isMoveValid(make_pair(io, jo), make_pair(i, j))){
						return;
					}
				}
			}
		}
		AIResponse();
	}
	else{	
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				_chessBoard[i][j] = chessBoard[i][j];
			}
		}		
		maxi(3);
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				chessBoard[i][j] = _chessBoard[i][j];
			}
		}
		move(ini, fin);		
	}		
}

int maxi(int depth){
	int max = 0x80000000, score;
	if(depth == 0)	return evaluate();
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(chessBoard[i][j]->isBlack){
				for(int ix = 0; ix < 8; ix++){
					for(int jx = 0; jx < 8; jx++){
						Piece* tempFin = chessBoard[ix][jx];
						if(isMoveValid(make_pair(i, j), make_pair(ix, jx))){
							score = mini(depth-1);
							if(score > max){
								max = score;
								ini = make_pair(i, j);
								fin = make_pair(ix, jx);
							}
							move(make_pair(ix, jx), make_pair(i, j));
							chessBoard[ix][jx] = tempFin;
							if(chessBoard[ix][jx]->value > 0)	chessBoard[ix][jx]->isDead = 0;
						}
					}
				}
			}
		}
	}
	return max;
}

int mini(int depth){
	int min = 0x7fffffff, score;
	if(depth == 0)	return evaluate();
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(!chessBoard[i][j]->isBlack){
				for(int ix = 0; ix < 8; ix++){
					for(int jx = 0; jx < 8; jx++){
						Piece* tempFin = chessBoard[ix][jx];
						if(isMoveValid(make_pair(i, j), make_pair(ix, jx))){
							score = maxi(depth-1);
							if(score < min){
								min = score;
								ini = make_pair(i, j);
								fin = make_pair(ix, jx);
							}
							move(make_pair(ix, jx), make_pair(i, j));
							chessBoard[ix][jx] = tempFin;
							if(chessBoard[ix][jx]->value > 0)	chessBoard[ix][jx]->isDead = 0;
						}
					}
				}
			}
		}
	}
	return min;
}	

int evaluate(){
	int score = 0;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			score += _chessBoard[i][j]->isBlack?(-_chessBoard[i][j]->value):(_chessBoard[i][j]->value) + chessBoard[i][j]->isBlack?(chessBoard[i][j]->value):(-chessBoard[i][j]->value);
		}
	}
	return score;
}
	
