#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10
void Init(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			show_map[MAX_ROW][MAX_COL] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			mine_map[MAX_ROW][MAX_COL] = '0';
		}
	}//��mine_map������ҳ�10��λ����Ϊ����
	int mine_count = MINE_COUNT;
	while (mine_count > 0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] = '1'){
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;

	}
}

void PrintMap(char map[MAX_ROW][MAX_COL]){
	printf("    |");
	for (int col = 0; col < MAX_COL; col++){
		printf("%d", col);
	}
	printf("\n");
	for (int col = 0; col < MAX_COL - 2; col++){
		printf("---");
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf(" %d|", row);
		for (int col = 0; col < MAX_COL; col++){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShowMap(int row, int col,
	char mine_map[MAX_ROW][MAX_COL],
	char show_map[MAX_ROW][MAX_COL]){
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 && mine_map[row - 1][col - 1] == '1'){
		++count;
	}
	if (row - 1 >= 0 && mine_map[row - 1][col] == '1'){
		++count;
	}
	if (row - 1 >= 0 && mine_map[row - 1][col + 1] == '1'){
		++count;
	}
	if (col + 1 < MAX_COL&& mine_map[row][col - 1] == '1'){
		++count;
	}
	if (col + 1 < MAX_COL && mine_map[row][col + 1] == '1'){
		++count;
	}
	if (row + 1 < MAX_ROW && col - 1 >= 0 && mine_map[row + 1][col - 1] == '1'){
		++count;
	}
	if (row + 1 < MAX_ROW && mine_map[row + 1][col] == '1'){
		++count;
	}
	if (row + 1 <MAX_ROW && col + 1 < MAX_COL && mine_map[row + 1][col + 1] == '1'){
		++count;
	}

	show_map[row][col] = count + '0';
}
//Game��ʾһ����Ϸ
void Game(){
	//1.����������ά������Ϊ��ͼ��
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//2.��������ͼ��ʼ��
	Init(show_map, mine_map);
	int blank_count = 0;
	while (1){
		//3.��ӡ��ͼ
		PrintMap(show_map);
		printf("������Ҫ������λ��(row,col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("���������Ƿ���\n");
			continue;
		}
		if (show_map[row][col] != '*'){
			printf("����������Ѿ�������\n");
			continue;
		}//5.�ж��Ƿ����
		if (mine_map[row][col] == '1'){
			printf("���ź���������~\n");
			return;
		}
		++blank_count;
		//6.�ж���Ϸ�Ƿ�ʤ��
		if (blank_count == MAX_ROW*MAX_COL - MINE_COUNT){
			printf("��ϲ�㣬ɨ�׳ɹ�\n");
			return;

		}
		//7.������ҵ�ǰλ���м�����
		UpdateShowMap(row, col, mine_map, show_map);
	}
}
int Menu(){
	printf("==================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("==================\n");
	printf("����������ѡ��");
	int choice = 0;
	scanf("%d ", &choice);
	return choice;
}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}
		else if (choice == 0){
			printf("goodbye\n");
			break;
		}
		else{
			printf("������������\n");
		}
	}
	system("pause");
}