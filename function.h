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

//���̴�С
const short boardHeight = 10;
const short boardWideth = 9;

class function
{
public:
	//��������
	short windowWideth = 750; //���ڴ�С
	short windowHeight = 825;
	short pointStep = 75; //��Ƶ
	short boardX = 0; //����λ��
	short boardY = 0;
	short sizeOfPiece = 70; //���Ӵ�С
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
	}; //����

	//��������
	const short Red_King = 1; //��˧
	const short Black_King = -1; //�ڽ�

	const short Red_Guard = 2; //����
	const short Black_Guard = -2; //��ʿ

	const short Red_Eleph = 3; //����
	const short Black_Eleph = -3; //����

	const short Red_Horse = 4; //����
	const short Black_Horse = -4; //����

	const short Red_Rook = 5; //�쳵
	const short Black_Rook = -5; //�ڳ�

	const short Red_Cannon = 6; //����
	const short Black_Cannon = -6; //����

	const short Red_Pawn = 7; //���
	const short Black_Pawn = -7; //����

	//��������
	short side; //���巽
	const short Red = 1; //�췽
	const short Black = -1; //�ڷ�
	const short EMPTY = 0; //��λ
	const short Same = 1; //ͬ������
	const short Different = -1; //��������
	const short Out = 99;
	const short YES = 1;
	const short NO = -1;

	//�����㷨����
	const double Infinity = 1000000;
	const short depth = 1; //�������

public:
	//��ʼ��
	function();

	//ͼ�ν���
	Position genMousePosition(); //��ȡ�����λ��
	void draw(short board[boardHeight][boardWideth]); //������
	void draw(vector<Position> pos); //������
	void draw(short board[boardHeight][boardWideth], vector<Position> pos);


	//�������
	void print(short board[boardHeight][boardWideth]);
	void print(vector<int> vec);
	void print(vector<Position> vec);
	void print(vector<TreadPosition> vec);

	//��������
	short countSpacesLeft(short board[boardHeight][boardWideth], int x, int y); //�������ո���
	short countSpacesRight(short board[boardHeight][boardWideth], int x, int y); //�����Ҳ�ո���
	short countSpacesUp(short board[boardHeight][boardWideth], int x, int y); //�����ϲ�ո���
	short countSpacesDown(short board[boardHeight][boardWideth], int x, int y); //�����²�ո���
	short pointInVector(vector<Position> vec, short x, short y); //�жϸõ��Ƿ���������
	vector<Position> combineVector(vector<Position> vec1, vector<Position> vec2); //�ϲ���������

	//�߷�����
	vector<Position> horseMove(short board[boardHeight][boardWideth], short x, short y); //����߷�
	vector<Position> cannonMove(short board[boardHeight][boardWideth], short x, short y); //�ڵ��߷�
	vector<Position> rookMove(short board[boardHeight][boardWideth], short x, short y); //�����߷�
	vector<Position> pawnMove(short board[boardHeight][boardWideth], short x, short y); //�����䣩���߷�
	vector<Position> elephMove(short board[boardHeight][boardWideth], short x, short y); //�ࣨ�󣩵��߷�
	vector<Position> guardMove(short board[boardHeight][boardWideth], short x, short y); //�ˣ�ʿ�����߷�
	vector<Position> kingMove(short board[boardHeight][boardWideth], short x, short y); //˧���������߷�


	//����
	void checkHorseMove();
	void checkCannonMove();
	void checkRookMove();
	void checkPawnMove();
	void checkElephMove();
};

