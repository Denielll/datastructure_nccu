#include <stdio.h>
#include <time.h>
#include <math.h>
#define SIZEX 10000 
#define SIZEY 10000

struct student {
	int id;
	double score;
};

struct t {
	int M[SIZEX][SIZEY];
};
typedef struct t T;

typedef struct student S;
typedef double D;

double AVG(int score[5]) {
	double sum = 0;

	for (int i = 0; i < 5; i++) {
		sum = sum + score[i]; // sum += score[i]
	}

	return sum / 5.0;
}

double AVG2(int score[5]) {
	double currentAVG = 0;

	for (double i = 0; i < 5; i++) {
		currentAVG = currentAVG * (i / (i + 1))
			+ (double)(score[(int)i]) / (i + 1);
	}

	return currentAVG;
}


// n: height of the board
void PrintBoard(int board[][4], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

void Sum1(int M[SIZEX][SIZEY]) {
	double sum = 0;

	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEY; j++) {
			sum += M[i][j];
		}
	}

	return;
}

void Sum2(int M[SIZEX][SIZEY]) {
	double sum = 0;

	for (int j = 0; j < SIZEY; j++) {
		for (int i = 0; i < SIZEX; i++) {
			sum += M[i][j];
		}
	}

	return;
}

//compute the average of the first n elements in arr
void Modify(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = 10.0 * sqrt(arr[i]);
	}
}

void PrintStudent(S s) { //int i
	printf("id: %d, score: %f\n", s.id, s.score);
}

void f1(T t) {
	return;
}

void f2(int M[SIZEX][SIZEY]) {
	return;
}

void PrintCube(int cube[][3][3], int height) {

}

int main() {
	int cube[3][3][3];


	clock_t start1, start2, end1, end2, totalTime1 = 0, totalTime2 = 0;
	int M2[SIZEX][SIZEY];
	T t;
	for (int i = 0; i < 100; i++) {
		start1 = clock();
		f1(t);
		end1 = clock();
		totalTime1 += end1 - start1;

		start2 = clock();
		f2(M2);
		end2 = clock();
		totalTime2 += end2 - start2;
	}
	printf("f1: %f, f2: %f\n", (float)totalTime1 / CLOCKS_PER_SEC,
		(float)totalTime2 / CLOCKS_PER_SEC);
	getchar();




	D d = 3.0;

	S Peter, Jane;
	S studentList[100];
	struct student SL[100];
	for (int i = 0; i < 100; i++) {
		studentList[i].id = i;
		SL[i].id = i;
	}

	Peter.id = 100;
	Peter.score = 90;
	PrintStudent(Peter);
//	PrintStudent(Jane);
	getchar();




	int s[5] = { 36, 36, 36, 36, 60 };
	printf("Before: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");

	Modify(s, 5);
	printf("After: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");
	getchar();

	//int M2[SIZEX][SIZEY];
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEY; j++) {
			M2[i][j] = i + j;
		}
	}

	//clock_t start1, start2, end1, end2, totalTime1 = 0, totalTime2 = 0;
	for (int i = 0; i < 100; i++) {
		start1 = clock();
		Sum1(M2);
		end1 = clock();
		totalTime1 += end1 - start1;

		start2 = clock();
		Sum2(M2);
		end2 = clock();
		totalTime2 += end2 - start2;
	}
	printf("sum1: %f, sum2: %f\n", (float)totalTime1 / CLOCKS_PER_SEC,
		(float)totalTime2 / CLOCKS_PER_SEC);
	getchar();

	//clock_t start = clock();
	/*Do something*/
	/*clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;*/



	int M[4][4] = { { 1,2,3,4 },
	{ 5,6,7,8 },
	{ 9,10,11,12 },
	{ 13,14,15,16 } };

	PrintBoard(M, 4);
	getchar();


	int score[5] = { 60, 70, 80, 90, 100 };
	//score[0] == 60

	for (int i = 0; i < 5; i++ /*i = i+1*/) {
		printf("score[%d] = %d\n", i, score[i]);
	}

	printf("AVG = %f\n", AVG2(score));
	getchar();
	return 0;
}