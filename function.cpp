#include "function.h"


function::function()
{
	initgraph(windowWideth, windowHeight);
}

Position function::genMousePosition()
{
	Position mousePosition; //��Ӧ����������
	for (; is_run(); delay_fps(90))
	{
		while (mousemsg())
		{
			mouse_msg  msg = getmouse();
			//�����������
			if (msg.x > pointStep - sizeOfPiece / 2 \
				&& msg.x < pointStep * 9 + sizeOfPiece / 2\
				&& msg.y > pointStep - sizeOfPiece / 2 \
				&& msg.y < pointStep * 10 + sizeOfPiece / 2)
			{

				for (int i = 0; i < boardWideth; i++)
				{
					for (int j = 0; j < boardHeight; j++)
					{
						if (msg.y > pointStep * (j + 1) - sizeOfPiece / 2 \
							&& msg.y < pointStep * (j + 1) + sizeOfPiece / 2\
							&& msg.x > pointStep * (i + 1) - sizeOfPiece / 2 \
							&& msg.x < pointStep * (i + 1) + sizeOfPiece / 2) //��������
						{
							if (msg.y > pointStep * (j + 1) - sizeOfPiece / 2 \
								&& msg.y < pointStep * (j + 1) + sizeOfPiece / 2)
							{
								mousePosition.x = j;
							}
							if (msg.x > pointStep * (i + 1) - sizeOfPiece / 2 \
								&& msg.x < pointStep * (i + 1) + sizeOfPiece / 2)
							{
								mousePosition.y = i;
							}
							if (msg.is_down() && msg.is_left())
							{
								return mousePosition;
							}
						}


					}
				}

			}
		}
	}
}

void function::draw(short board[boardHeight][boardWideth])
{
	//������
	PIMAGE imgBoard = newimage();
	getimage(imgBoard, "picture/board.png");
	putimage(boardX, boardY, imgBoard);

	//����������
	setcolor(BLACK);						//���ֵ���ɫ
	setbkmode(TRANSPARENT);					//�������ֱ���ɫΪ͸��	
	int height = 40;						//���ָ߶�
	setfont(height, 0, "����");				//�������ֿ�Ⱥ�����
	settextjustify(LEFT_TEXT, TOP_TEXT);	//ˮƽ����룬��ֱ��������
	for (int i = 0; i < 10; i++)
	{
		xyprintf(20, pointStep * i + sizeOfPiece - height / 2, "%d", i);
		xyprintf(windowWideth - 40, pointStep * i + sizeOfPiece - height / 2, "%d", i);

	}
	for (int i = 0; i < 9; i++)
	{
		xyprintf(pointStep * i + sizeOfPiece, 5, "%d", i);
		xyprintf(pointStep * i + sizeOfPiece, windowHeight - 40, "%d", i);
	}


	//������
	PIMAGE img[14];
	char fileName[20];
	for (int i = 0; i < 14; i++)
	{
		sprintf(fileName, "picture/%d.png", i);
		img[i] = newimage();
		getimage(img[i], fileName);
	}

	for (int x = 0; x < boardHeight; x++)
	{
		for (int y = 0; y < boardWideth; y++)
		{
			int i = y, j = x;
			if (board[x][y] == Red_King)
			{
				putimage_withalpha(NULL, img[0], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}

			else if (board[x][y] == Black_King)
			{
				putimage_withalpha(NULL, img[7], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Guard)
			{
				putimage_withalpha(NULL, img[1], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Guard)
			{
				putimage_withalpha(NULL, img[8], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Eleph)
			{
				putimage_withalpha(NULL, img[2], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Eleph)
			{
				putimage_withalpha(NULL, img[9], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Horse)
			{
				putimage_withalpha(NULL, img[3], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Horse)
			{
				putimage_withalpha(NULL, img[10], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Rook)
			{
				putimage_withalpha(NULL, img[4], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Rook)
			{
				putimage_withalpha(NULL, img[11], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Cannon)
			{
				putimage_withalpha(NULL, img[5], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Cannon)
			{
				putimage_withalpha(NULL, img[12], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Pawn)
			{
				putimage_withalpha(NULL, img[6], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Pawn)
			{
				putimage_withalpha(NULL, img[13], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
		}
	}
	delimage(imgBoard);
	for (int i = 0; i < 14; i++)
	{
		delimage(img[i]);
		img[i] = NULL;
	}
}

void function::draw(vector<Position> pos)
{
	int x, y;
	setcolor(RED);
	setlinewidth(6);
	for (int i = 0; i < (int)pos.size(); i++)
	{
		y = pos[i].x;
		x = pos[i].y;
		circle(pointStep * (x + 1), pointStep * (y + 1), int(sizeOfPiece / 3.25));
	}
}

void function::draw(short board[boardHeight][boardWideth], vector<Position> pos)
{
	//������
	PIMAGE imgBoard = newimage();
	getimage(imgBoard, "picture/board.png");
	putimage(boardX, boardY, imgBoard);

	//����������
	setcolor(BLACK);						//���ֵ���ɫ
	setbkmode(TRANSPARENT);					//�������ֱ���ɫΪ͸��	
	int height = 40;						//���ָ߶�
	setfont(height, 0, "����");				//�������ֿ�Ⱥ�����
	settextjustify(LEFT_TEXT, TOP_TEXT);	//ˮƽ����룬��ֱ��������
	for (int i = 0; i < 10; i++)
	{
		xyprintf(20, pointStep * i + sizeOfPiece - height / 2, "%d", i);
		xyprintf(windowWideth - 40, pointStep * i + sizeOfPiece - height / 2, "%d", i);

	}
	for (int i = 0; i < 9; i++)
	{
		xyprintf(pointStep * i + sizeOfPiece, 5, "%d", i);
		xyprintf(pointStep * i + sizeOfPiece, windowHeight - 40, "%d", i);
	}


	//������
	PIMAGE img[14];
	char fileName[20];
	for (int i = 0; i < 14; i++)
	{
		sprintf(fileName, "picture/%d.png", i);
		img[i] = newimage();
		getimage(img[i], fileName);
	}

	for (int x = 0; x < boardHeight; x++)
	{
		for (int y = 0; y < boardWideth; y++)
		{
			int i = y, j = x;
			if (board[x][y] == Red_King)
			{
				putimage_withalpha(NULL, img[0], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}

			else if (board[x][y] == Black_King)
			{
				putimage_withalpha(NULL, img[7], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Guard)
			{
				putimage_withalpha(NULL, img[1], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Guard)
			{
				putimage_withalpha(NULL, img[8], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Eleph)
			{
				putimage_withalpha(NULL, img[2], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Eleph)
			{
				putimage_withalpha(NULL, img[9], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Horse)
			{
				putimage_withalpha(NULL, img[3], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Horse)
			{
				putimage_withalpha(NULL, img[10], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Rook)
			{
				putimage_withalpha(NULL, img[4], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Rook)
			{
				putimage_withalpha(NULL, img[11], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Cannon)
			{
				putimage_withalpha(NULL, img[5], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Cannon)
			{
				putimage_withalpha(NULL, img[12], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Red_Pawn)
			{
				putimage_withalpha(NULL, img[6], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
			else if (board[x][y] == Black_Pawn)
			{
				putimage_withalpha(NULL, img[13], pointStep * (i + 1) - sizeOfPiece / 2, pointStep * (j + 1) - sizeOfPiece / 2);
			}
		}
	}

	int x, y;
	setcolor(RED);
	setlinewidth(6);
	for (int i = 0; i < (int)pos.size(); i++)
	{
		y = pos[i].x;
		x = pos[i].y;
		circle(pointStep * (x + 1), pointStep * (y + 1), int(sizeOfPiece / 3.25));
	}


	delimage(imgBoard);
	for (int i = 0; i < 14; i++)
	{
		delimage(img[i]);
		img[i] = NULL;
	}


}

void function::print(short board[boardHeight][boardWideth])
{
	printf("\n");
	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j < boardWideth; j++)
		{
			printf("%3d", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void function::print(vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		printf("(%d)\n", vec[i]);
	}
}

void function::print(vector<Position> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		printf("(%d, %d)\n", vec[i].x, vec[i].y);
	}
}

void function::print(vector<TreadPosition> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		printf("(%d, %d) -> (%d, %d)\n", vec[i].begPos.x, vec[i].begPos.y, vec[i].endPos.x, vec[i].endPos.y);
	}
}

short function::countSpacesLeft(short board[boardHeight][boardWideth], int x, int y)
{
	int n = 0;
	for (int i = 1; y - i >= 0; i++)
	{
		if (board[x][y - i] == EMPTY)
		{
			n++;
		}
		else
		{
			break;
		}
	}
	return n;
}

short function::countSpacesRight(short board[boardHeight][boardWideth], int x, int y)
{
	int n = 0;
	for (int i = 1; y + i < boardWideth; i++)
	{
		if (board[x][y + i] == EMPTY)
		{
			n++;
		}
		else
		{
			break;
		}
	}
	return n;
}

short function::countSpacesUp(short board[boardHeight][boardWideth], int x, int y)
{
	int n = 0;
	for (int i = 1; x - i >= 0; i++)
	{
		if (board[x - i][y] == EMPTY)
		{
			n++;
		}
		else
		{
			break;
		}
	}
	return n;
}

short function::countSpacesDown(short board[boardHeight][boardWideth], int x, int y)
{
	int n = 0;
	for (int i = 1; x + i < boardHeight; i++)
	{
		if (board[x + i][y] == EMPTY)
		{
			n++;
		}
		else
		{
			break;
		}
	}
	return n;
}

short function::pointInVector(vector<Position> vec, short x, short y)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (x == vec[i].x && y == vec[i].y)
		{
			return i;
		}
	}
	return -1;
}

vector<Position> function::combineVector(vector<Position> vec1, vector<Position> vec2)
{
	vector<Position> vec3;
	Position pos;

	for (int i = 0; i < (int)vec1.size(); i++)
	{
		pos.x = vec1[i].x;
		pos.y = vec1[i].y;
		vec3.push_back(pos);
	}
	for (int i = 0; i < (int)vec2.size(); i++)
	{
		pos.x = vec2[i].x;
		pos.y = vec2[i].y;
		vec3.push_back(pos);
	}
	return vec3;
}

vector<Position> function::horseMove(short board[boardHeight][boardWideth], short x, short y)
{
	vector<Position> horsePosition;
	Position pos;

	short kind = board[x][y];
	//��
	if (board[x - 1][y] == EMPTY) //������
	{
		if (kind * board[x - 2][y - 1] <= 0 && x - 2 >= 0 && y - 1 >= 0) //û��ͬ�࣬û��Խ��
		{
			pos.x = x - 2;
			pos.y = y - 1;
			horsePosition.push_back(pos);
		}
		if (kind * board[x - 2][y + 1] <= 0 && x - 2 >= 0 && y + 1 < boardWideth)
		{
			pos.x = x - 2;
			pos.y = y + 1;
			horsePosition.push_back(pos);
		}

	}

	//��
	if (board[x + 1][y] == EMPTY)
	{
		if (kind * board[x + 2][y + 1] <= 0 && x + 2 < boardHeight && y - 1 >= 0)
		{
			pos.x = x + 2;
			pos.y = y - 1;
			horsePosition.push_back(pos);
		}
		if (kind * board[x + 2][y + 1] <= 0 && x + 2 < boardHeight && y + 1 < boardWideth)
		{
			pos.x = x + 2;
			pos.y = y + 1;
			horsePosition.push_back(pos);
		}

	}

	//��
	if (board[x][y - 1] == EMPTY)
	{
		if (kind * board[x - 1][y - 2] <= 0 && x - 1 >= 0 && y - 2 >= 0)
		{
			pos.x = x - 1;
			pos.y = y - 2;
			horsePosition.push_back(pos);
		}
		if (kind * board[x + 1][y - 2] <= 0 && x + 1 < boardHeight && y - 2 >= 0)
		{
			pos.x = x + 1;
			pos.y = y - 2;
			horsePosition.push_back(pos);
		}

	}

	//��
	if (board[x][y + 1] == EMPTY)
	{
		if (kind * board[x - 1][y + 2] <= 0 && x - 1 >= 0 && y + 2 < boardWideth)
		{
			pos.x = x - 1;
			pos.y = y + 2;
			horsePosition.push_back(pos);
		}
		if (kind * board[x + 1][y + 2] <= 0 && x + 1 < boardHeight && y + 2 < boardWideth)
		{
			pos.x = x + 1;
			pos.y = y + 2;
			horsePosition.push_back(pos);
		}

	}
	return horsePosition;
}

vector<Position> function::cannonMove(short board[boardHeight][boardWideth], short x, short y)
{
	vector<Position> cannonPosition;
	Position pos;

	//�ڲ����ӵ��߷�
	//��
	for (int i = 1; i <= countSpacesLeft(board, x, y); i++) //�ո�����
	{
		pos.x = x;
		pos.y = y - i;
		cannonPosition.push_back(pos);
	}
	//��
	for (int i = 1; i <= countSpacesRight(board, x, y); i++)
	{
		pos.x = x;
		pos.y = y + i;
		cannonPosition.push_back(pos);
	}
	//��
	for (int i = 1; i <= countSpacesUp(board, x, y); i++)
	{
		pos.x = x - i;
		pos.y = y;
		cannonPosition.push_back(pos);
	}
	//��
	for (int i = 1; i <= countSpacesDown(board, x, y); i++)
	{
		pos.x = x + i;
		pos.y = y;
		cannonPosition.push_back(pos);
	}
	//�ڳ��ӵ��߷�
	//��
	int leftLast = y - countSpacesLeft(board, x, y); //�����󲻳��ӵ����һ��
	if (leftLast - 1 >= 0) //�ϰ��ﲻԽ��
	{
		int leftLeftLast = (leftLast - 1) - countSpacesLeft(board, x, leftLast - 1); //�ϰ����������һ���ո�
		if (leftLeftLast - 1 >= 0) //�����Ӳ�Խ��
		{
			if (board[x][y] * board[x][leftLeftLast - 1] < 0) //�����������������λ����
			{
				pos.x = x;
				pos.y = leftLeftLast - 1;
				cannonPosition.push_back(pos);
			}
		}
	}
	//��
	int rightLast = y + countSpacesRight(board, x, y);
	if (rightLast + 1 < boardWideth)
	{
		int rightRightLast = (rightLast + 1) + countSpacesRight(board, x, rightLast + 1);
		if (rightRightLast + 1 < boardWideth)
		{
			if (board[x][y] * board[x][rightRightLast + 1] < 0)
			{
				pos.x = x;
				pos.y = rightRightLast + 1;
				cannonPosition.push_back(pos);
			}
		}
	}


	//��
	int upLast = x - countSpacesUp(board, x, y);
	if (upLast - 1 >= 0)
	{
		int upUpLast = (upLast - 1) - countSpacesUp(board, upLast - 1, y);
		if (upUpLast - 1 >= 0)
		{
			if (board[x][y] * board[upUpLast - 1][y] < 0)
			{
				pos.x = upUpLast - 1;
				pos.y = y;
				cannonPosition.push_back(pos);
			}
		}
	}
	//��
	int downLast = x + countSpacesDown(board, x, y);
	if (downLast + 1 < boardHeight)
	{
		int downDownLast = (downLast + 1) + countSpacesDown(board, downLast + 1, y);
		if (downDownLast + 1 < boardHeight)
		{
			if (board[x][y] * board[downDownLast + 1][y] < 0)
			{
				pos.x = downDownLast + 1;
				pos.y = y;
				cannonPosition.push_back(pos);
			}
		}
	}
	return cannonPosition;
}

vector<Position> function::rookMove(short board[boardHeight][boardWideth], short x, short y)
{
	vector<Position> rookPosition;
	Position pos;

	//���������߷�
	//��
	for (int i = 1; i <= countSpacesLeft(board, x, y); i++) //�ո�����
	{
		pos.x = x;
		pos.y = y - i;
		rookPosition.push_back(pos);
	}
	//��
	for (int i = 1; i <= countSpacesRight(board, x, y); i++)
	{
		pos.x = x;
		pos.y = y + i;
		rookPosition.push_back(pos);
	}
	//��
	for (int i = 1; i <= countSpacesUp(board, x, y); i++)
	{
		pos.x = x - i;
		pos.y = y;
		rookPosition.push_back(pos);
	}
	//��
	for (int i = 1; i <= countSpacesDown(board, x, y); i++)
	{
		pos.x = x + i;
		pos.y = y;
		rookPosition.push_back(pos);
	}

	//���������߷�
	//��
	int leftLast = y - countSpacesLeft(board, x, y); //���󲻳��ӵ����һ��
	if (leftLast - 1 >= 0)
	{
		int leftLeftLast = leftLast - 1; //�ϰ���
		if (board[x][y] * board[x][leftLeftLast] < 0)
		{
			pos.x = x;
			pos.y = leftLeftLast;
			rookPosition.push_back(pos);
		}
	}
	//��
	int rightLast = y + countSpacesRight(board, x, y);

	if (rightLast + 1 < boardWideth)
	{
		int rightRightLast = rightLast + 1;
		if (board[x][y] * board[x][rightRightLast] < 0)
		{
			pos.x = x;
			pos.y = rightRightLast;
			rookPosition.push_back(pos);
		}
	}
	//��
	int upLast = x - countSpacesUp(board, x, y);
	if (upLast - 1 >= 0)
	{
		int upUpLast = upLast - 1;
		if (board[x][y] * board[upUpLast][y] < 0)
		{
			pos.x = upUpLast;
			pos.y = y;
			rookPosition.push_back(pos);
		}
	}
	//��
	int downLast = x + countSpacesDown(board, x, y);
	if (downLast + 1 < boardHeight)
	{
		int downDownLast = downLast + 1;
		if (board[x][y] * board[downDownLast][y] < 0)
		{
			pos.x = downDownLast;
			pos.y = y;
			rookPosition.push_back(pos);
		}
	}

	return rookPosition;
}

vector<Position> function::pawnMove(short board[boardHeight][boardWideth], short x, short y)
{
	vector<Position> pawnPosition;
	Position pos;

	//���
	if (board[x][y] > 0)
	{
		//û�й���
		if (x >= 5)
		{
			//��
			if (board[x][y] * board[x - 1][y] <= 0 && x - 1 >= 0) //û��ͬ��
			{
				pos.x = x - 1;
				pos.y = y;
				pawnPosition.push_back(pos);
			}
		}
		//����
		else
		{
			//��
			if (board[x][y] * board[x][y - 1] <= 0 && y - 1 >= 0) //û��Խ�磬û��ͬ��
			{
				pos.x = x;
				pos.y = y - 1;
				pawnPosition.push_back(pos);
			}
			//��
			if (board[x][y] * board[x][y + 1] <= 0 && y + 1 < boardWideth)
			{
				pos.x = x;
				pos.y = y + 1;
				pawnPosition.push_back(pos);
			}
			//��
			if (board[x][y] * board[x - 1][y] <= 0 && x - 1 >= 0)
			{
				pos.x = x - 1;
				pos.y = y;
				pawnPosition.push_back(pos);
			}
		}
	}
	//����
	else if (board[x][y] < 0)
	{
		//û�й���
		if (x < 5)
		{
			//��
			if (board[x][y] * board[x + 1][y] <= 0 && x + 1 < boardHeight)
			{
				pos.x = x + 1;
				pos.y = y;
				pawnPosition.push_back(pos);
			}
		}
		//����
		else
		{
			//��
			if (board[x][y] * board[x][y - 1] <= 0 && y - 1 >= 0)
			{
				pos.x = x;
				pos.y = y - 1;
				pawnPosition.push_back(pos);
			}
			//��
			if (board[x][y] * board[x][y + 1] <= 0 && y + 1 < boardWideth)
			{
				pos.x = x;
				pos.y = y + 1;
				pawnPosition.push_back(pos);
			}
			//��
			if (board[x][y] * board[x + 1][y] <= 0 && x + 1 < boardHeight)
			{
				pos.x = x + 1;
				pos.y = y;
				pawnPosition.push_back(pos);
			}
		}
	}
	return pawnPosition;
}

vector<Position> function::elephMove(short board[boardHeight][boardWideth], short x, short y)
{
	vector<Position> elephPosition;
	Position pos;

	//����
	if (board[x][y] > 0)
	{
		//����
		if (x - 2 >= 5 && y - 2 >= 0\
			&& board[x - 1][y - 1] == EMPTY\
			&& board[x][y] * board[x - 2][y - 2] <= 0) //û��Խ�磬�м�Ϊ�գ�û��ͬ��
		{
			pos.x = x - 2;
			pos.y = y - 2;
			elephPosition.push_back(pos);
		}

		//����
		if (x - 2 >= 5 && y + 2 < boardWideth\
			&& board[x - 1][y + 1] == EMPTY\
			&& board[x][y] * board[x - 2][y - 2] <= 0)
		{
			pos.x = x - 2;
			pos.y = y + 2;
			elephPosition.push_back(pos);
		}
		//����
		if (x + 2 < boardHeight && y - 2 >= 0\
			&& board[x + 1][y - 1] == EMPTY\
			&& board[x][y] * board[x + 2][y - 2] <= 0)
		{
			pos.x = x + 2;
			pos.y = y - 2;
			elephPosition.push_back(pos);
		}
		//����
		if (x + 2 < boardHeight && y + 2 < boardWideth\
			&& board[x + 1][y + 1] == EMPTY\
			&& board[x][y] * board[x + 2][+-2] <= 0)
		{
			pos.x = x + 2;
			pos.y = y + 2;
			elephPosition.push_back(pos);
		}
	}
	else if (board[x][y] < 0)
	{
		//����
		if (x - 2 >= 0 && y - 2 >= 0\
			&& board[x - 1][y - 1] == EMPTY\
			&& board[x][y] * board[x - 2][y - 2] <= 0)
		{
			pos.x = x - 2;
			pos.y = y - 2;
			elephPosition.push_back(pos);
		}

		//����
		if (x - 2 >= 0 && y + 2 < boardWideth\
			&& board[x - 1][y + 1] == EMPTY\
			&& board[x][y] * board[x - 2][y + 2] <= 0)
		{
			pos.x = x - 2;
			pos.y = y + 2;
			elephPosition.push_back(pos);
		}
		//����
		if (x + 2 < 5 && y - 2 >= 0\
			&& board[x + 1][y - 1] == EMPTY\
			&& board[x][y] * board[x + 2][y - 2] <= 0)
		{
			pos.x = x + 2;
			pos.y = y - 2;
			elephPosition.push_back(pos);
		}
		//����
		if (x + 2 < 5 && y + 2 < boardWideth\
			&& board[x + 1][y + 1] == EMPTY\
			&& board[x][y] * board[x + 2][y + 2] <= 0)
		{
			pos.x = x + 2;
			pos.y = y + 2;
			elephPosition.push_back(pos);
		}
	}
	return elephPosition;
}

vector<Position> function::guardMove(short board[boardHeight][boardWideth], short x, short y)
{
	vector<Position> guardPosition;
	Position pos;

	//����
	if (board[x][y] > 0)
	{
		//����
		if (x - 1 >= 7 && y - 1 >= 3\
			&& board[x][y] * board[x - 1][y - 1] <= 0) //û��Խ�磬û��ͬ��
		{
			pos.x = x - 1;
			pos.y = y - 1;
			guardPosition.push_back(pos);
		}
		//����
		if (x - 1 >= 7 && y + 1 <= 5\
			&& board[x][y] * board[x - 1][y + 1] <= 0)
		{
			pos.x = x - 1;
			pos.y = y + 1;
			guardPosition.push_back(pos);
		}
		//����
		if (x + 1 < boardHeight && y - 1 >= 3\
			&& board[x][y] * board[x + 1][y - 1] <= 0)
		{
			pos.x = x + 1;
			pos.y = y - 1;
			guardPosition.push_back(pos);
		}
		//����
		if (x + 1 < boardHeight && y + 1 <= 5\
			&& board[x][y] * board[x + 1][y + 1] <= 0)
		{
			pos.x = x + 1;
			pos.y = y + 1;
			guardPosition.push_back(pos);
		}
	}
	//��ʿ
	else if (board[x][y] < 0)
	{
		//����
		if (x - 1 >= 0 && y - 1 >= 3\
			&& board[x][y] * board[x - 1][y - 1] <= 0)
		{
			pos.x = x - 1;
			pos.y = y - 1;
			guardPosition.push_back(pos);
		}
		//����
		if (x - 1 >= 0 && y + 1 <= 5\
			&& board[x][y] * board[x - 1][y + 1] <= 0)
		{
			pos.x = x - 1;
			pos.y = y + 1;
			guardPosition.push_back(pos);
		}
		//����
		if (x + 1 <= 2 && y - 1 >= 3\
			&& board[x][y] * board[x + 1][y - 1] <= 0)
		{
			pos.x = x + 1;
			pos.y = y - 1;
			guardPosition.push_back(pos);
		}
		//����
		if (x + 1 <= 2 && y + 1 <= 5\
			&& board[x][y] * board[x + 1][y + 1] <= 0)
		{
			pos.x = x + 1;
			pos.y = y + 1;
			guardPosition.push_back(pos);
		}
	}

	return guardPosition;
}

void function::checkHorseMove()
{
	short board0[boardHeight][boardWideth] = { 0 };
	board0[0][0] = Red_Horse;
	board0[1][6] = Red_Horse;
	board0[6][4] = Red_Horse;
	board0[2][4] = Red_Horse;
	board0[3][2] = Black_Horse;
	board0[3][4] = Black_Horse;
	board0[9][0] = Red_Horse;
	board0[9][8] = Red_Horse;

	draw(board0);
	while (1)
	{
		Position mousePos = genMousePosition();
		printf("Mouse(%d, %d)\n", mousePos.x, mousePos.y);
		if (board0[mousePos.x][mousePos.y] == Red_Horse || board0[mousePos.x][mousePos.y] == Black_Horse)
		{
			vector<Position> horseStep = horseMove(board0, mousePos.x, mousePos.y);
			cleardevice();
			draw(board0, horseStep);
			print(horseStep);
		}
	}
}

void function::checkCannonMove()
{
	short board0[boardHeight][boardWideth] = { 0 };
	board0[2][2] = Red_Cannon;
	board0[1][1] = Red_Horse;
	board0[3][2] = Black_Cannon;
	board0[2][7] = Black_Horse;
	board0[3][0] = Black_Pawn;
	board0[2][4] = Black_Horse;
	board0[9][4] = Red_Horse;
	board0[3][5] = Red_Cannon;
	board0[3][8] = Black_Eleph;

	draw(board0);
	while (1)
	{
		Position mousePos = genMousePosition();
		printf("MOUSE(%d , %d)\n", mousePos.x, mousePos.y);
		if (board0[mousePos.x][mousePos.y] == Red_Cannon || board0[mousePos.x][mousePos.y] == Black_Cannon)
		{
			vector<Position> cannonStep = cannonMove(board0, mousePos.x, mousePos.y);
			cleardevice();
			draw(board0, cannonStep);
			print(cannonStep);
		}

	}
}

void function::checkRookMove()
{
	short board0[boardHeight][boardWideth] = { 0 };
	board0[3][4] = Red_Rook;
	board0[3][2] = Black_Rook;
	board0[3][0] = Black_Rook;
	board0[2][4] = Black_Rook;
	board0[0][4] = Black_Horse;
	board0[4][4] = Black_Horse;
	board0[9][4] = Black_Horse;
	board0[3][5] = Red_Horse;
	board0[3][8] = Black_Eleph;
	draw(board0);
	while (1)
	{
		Position mousePos = genMousePosition();
		printf("MOUSE(%d , %d)\n", mousePos.x, mousePos.y);
		if (board0[mousePos.x][mousePos.y] == Red_Rook || board0[mousePos.x][mousePos.y] == Black_Rook)
		{
			vector<Position> rookStep = rookMove(board0, mousePos.x, mousePos.y);
			cleardevice();
			draw(board0, rookStep);
			print(rookStep);
		}

	}
}

void function::checkPawnMove()
{
	short board0[boardHeight][boardWideth] = { 0 };
	board0[3][4] = Red_Rook;
	board0[3][2] = Black_Pawn;
	board0[3][0] = Black_Pawn;
	board0[2][4] = Black_Pawn;
	board0[0][4] = Black_Pawn;
	board0[4][4] = Black_Pawn;
	board0[9][4] = Black_Pawn;
	board0[3][5] = Red_Pawn;
	board0[3][8] = Black_Pawn;
	draw(board0);
	while (1)
	{
		Position mousePos = genMousePosition();
		printf("MOUSE(%d , %d)\n", mousePos.x, mousePos.y);
		if (board0[mousePos.x][mousePos.y] == Red_Pawn || board0[mousePos.x][mousePos.y] == Black_Pawn)
		{
			vector<Position> pawnStep = pawnMove(board0, mousePos.x, mousePos.y);
			cleardevice();
			draw(board0, pawnStep);
			print(pawnStep);
		}
	}
}

void function::checkElephMove()
{
	short board0[boardHeight][boardWideth] = { 0 };
	board0[8][3] = Red_Eleph;
	board0[4][2] = Black_Eleph;
	board0[8][8] = Red_Eleph;
	board0[2][4] = Black_Eleph;
	board0[5][8] = Red_Eleph;

	board0[3][3] = Red_Cannon;
	board0[0][2] = Red_Rook;
	board0[6][7] = Red_Pawn;
	board0[6][6] = Red_Horse;
	draw(board0);
	while (1)
	{
		Position mousePos = genMousePosition();
		printf("MOUSE(%d , %d)\n", mousePos.x, mousePos.y);
		if (board0[mousePos.x][mousePos.y] == Red_Eleph || board0[mousePos.x][mousePos.y] == Black_Eleph)
		{
			vector<Position> elephStep = elephMove(board0, mousePos.x, mousePos.y);
			cleardevice();
			draw(board0, elephStep);
			print(elephStep);
		}
	}
}

