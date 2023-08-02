#pragma once
#define SHOW_CONSOLE
#include <graphics.h>
#include <iostream>
#include <vector>


using namespace std;
struct Position
{
	short x;
	short y;
};

struct TreadPosition
{
	Position begPos;
	Position endPos;
};

//棋盘大小
const short boardHeight = 10;
const short boardWideth = 9;

class function
{
public:
	//棋盘设置
	short windowWideth = 750; //窗口大小
	short windowHeight = 825;
	short pointStep = 75; //步频
	short boardX = 0; //棋盘位置
	short boardY = 0;
	short sizeOfPiece = 70; //棋子大小
	short board[boardHeight][boardWideth] = {
   {-5, -4, -3, -2, -1, -2, -3, -4, -5},
   { 0,  0,  0,  0,  0,  0,  0,  0,  0},
   { 0, -6,  0,  0,  0,  0,  0, -6,  0},
   {-7,  0, -7,  0, -7,  0, -7,  0, -7},
   { 0,  0,  0,  0,  0,  0,  0,  0,  0},
   { 0,  0,  0,  0,  0,  0,  0,  0,  0},
   { 7,  0,  7,  0,  7,  0,  7,  0,  7},
   { 0,  6,  0,  0,  0,  0,  0,  6,  0},
   { 0,  0,  0,  0,  0,  0,  0,  0,  0},
   { 5,  4,  3,  2,  1,  2,  3,  4,  5}
	}; //棋盘

	//棋子设置
	const short Red_King = 1; //红帅
	const short Black_King = -1; //黑将

	const short Red_Guard = 2; //红仕
	const short Black_Guard = -2; //黑士

	const short Red_Eleph = 3; //红相
	const short Black_Eleph = -3; //黑象

	const short Red_Horse = 4; //红马
	const short Black_Horse = -4; //黑马

	const short Red_Rook = 5; //红车
	const short Black_Rook = -5; //黑车

	const short Red_Cannon = 6; //红炮
	const short Black_Cannon = -6; //黑炮

	const short Red_Pawn = 7; //红兵
	const short Black_Pawn = -7; //黑卒

	//其他设置
	short side; //下棋方
	const short Red = 1; //红方
	const short Black = -1; //黑方
	const short EMPTY = 0; //空位
	const short Same = 1; //同类棋子
	const short Different = -1; //异类棋子
	const short Out = 99;
	const short YES = 1;
	const short NO = -1;

	//搜索算法设置
	const double Infinity = 1000000;
	const short depth = 1; //搜索深度

public:
	//初始化
	function();

	//图形界面
	Position genMousePosition(); //获取鼠标点击位置
	void draw(short board[boardHeight][boardWideth]); //画棋盘
	void draw(vector<Position> pos); //画棋盘
	void draw(short board[boardHeight][boardWideth], vector<Position> pos);


	//输出函数
	void print(short board[boardHeight][boardWideth]);
	void print(vector<int> vec);
	void print(vector<Position> vec);
	void print(vector<TreadPosition> vec);

	//辅助函数
	short countSpacesLeft(short board[boardHeight][boardWideth], int x, int y); //计算左侧空格数
	short countSpacesRight(short board[boardHeight][boardWideth], int x, int y); //计算右侧空格数
	short countSpacesUp(short board[boardHeight][boardWideth], int x, int y); //计算上侧空格数
	short countSpacesDown(short board[boardHeight][boardWideth], int x, int y); //计算下侧空格数
	short pointInVector(vector<Position> vec, short x, short y); //判断该点是否在向量中
	vector<Position> combineVector(vector<Position> vec1, vector<Position> vec2); //合并两个向量

	//走法生成
	vector<Position> horseMove(short board[boardHeight][boardWideth], short x, short y); //马的走法
	vector<Position> cannonMove(short board[boardHeight][boardWideth], short x, short y); //炮的走法
	vector<Position> rookMove(short board[boardHeight][boardWideth], short x, short y); //车的走法
	vector<Position> pawnMove(short board[boardHeight][boardWideth], short x, short y); //兵（卒）的走法
	vector<Position> elephMove(short board[boardHeight][boardWideth], short x, short y); //相（象）的走法
	vector<Position> guardMove(short board[boardHeight][boardWideth], short x, short y); //仕（士）的走法
	vector<Position> kingMove(short board[boardHeight][boardWideth], short x, short y); //帅（将）的走法


	//调试
	void checkHorseMove();
	void checkCannonMove();
	void checkRookMove();
	void checkPawnMove();
	void checkElephMove();
};

