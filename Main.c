#include<stdio.h>

#define NO_MOVE 0
#define YUKO 1
#define WAZARI 2
#define IPPON 3


//CRTL + F5 to run any selected file.

struct athlete
{
	int throws[3];
	int ginScore;
	int judoMove;
	int lift;
	int totalScore;
};

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void shotPut(int* throwsAthele1, int* throwsAthele2)
{
	srand(time(0));

	//Throw
	for (int i = 0; i < 3; i++)
	{
		throwsAthele1[i] = (rand() % 500) + 1;
		throwsAthele2[i] = (rand() % 500) + 1;
	}

	//Sort Throws
	qsort(throwsAthele1, 3, sizeof(int), compare);

	qsort(throwsAthele2, 3, sizeof(int), compare);

	//Who won??
	if (throwsAthele1[2] == throwsAthele2[2])
	{
		if (throwsAthele1[1] == throwsAthele2[1])
		{
			if (throwsAthele1[0] == throwsAthele2[0])
			{
				printf("Draw!");
			}
			else if (throwsAthele1[0] > throwsAthele2[0])
				printf("Athlete1 wins on Shot Put round!");
			else
				printf("Athlete1 wins on Shot Put round!");
		}
		else if (throwsAthele1[1] > throwsAthele2[1])
			printf("Athlete1 wins on Shot Put round!");
		else
			printf("Athlete1 wins on Shot Put round!");
	}
	else if (throwsAthele1[2] > throwsAthele2[2])
		printf("Athlete1 wins on Shot Put round!");
	else
		printf("Athlete1 wins on Shot Put round!");
}

int artisticGymnastics()
{
	int scores[5];

	srand(time(0));

	//Scores
	for (int i = 0; i < 5; i++)
	{
		scores[i] = (rand() % 10) + 1;
	}

	//Sort scores
	qsort(scores, 5, sizeof(int), compare);

	int totalScore = 0;

	for (int i = 1; i < 5; i++)
	{
		totalScore += scores[i];
	}

	return totalScore;
}

int main()
{
	//Init athletes
	struct athlete athlete1, athlete2;

	athlete1.totalScore = 0;
	athlete1.ginScore = 0;
	athlete1.judoMove = 0;
	athlete1.lift = 0;

	athlete2.totalScore = 0;
	athlete2.ginScore = 0;
	athlete2.judoMove = 0;
	athlete2.lift = 0;

	//Shot Put round
	shotPut(athlete1.throws, athlete2.throws);

	//Calculate ShotPut Total Score
	for (int i = 0; i < 3; i++)
	{
		athlete1.totalScore += athlete1.throws[i];
		athlete2.totalScore += athlete2.throws[i];
	}

	printf("\n");

	//ArtisticGymnastics round
	athlete1.ginScore = artisticGymnastics();
	athlete2.ginScore = artisticGymnastics();

	if (athlete1.ginScore > athlete2.ginScore)
		printf("Athlete1 wins on Artistic Gymnastics round!");
	else if (athlete1.ginScore < athlete2.ginScore)
		printf("Athlete2 wins on Artistic Gymnastics round!");
	else
		printf("Draw!");

	athlete1.totalScore += athlete1.ginScore;
	athlete2.totalScore += athlete2.ginScore;

	printf("\n");

	//Judo round
	srand(time(0));

	athlete1.judoMove = (rand() % IPPON) + NO_MOVE;
	athlete2.judoMove = (rand() % IPPON) + NO_MOVE;

	if (athlete1.judoMove > athlete2.judoMove)
		printf("Athlete1 wins on Judo round!");
	else if (athlete1.judoMove < athlete2.judoMove)
		printf("Athlete2 wins on Judo round!");
	else
		printf("Draw!");

	athlete1.totalScore += athlete1.judoMove;
	athlete2.totalScore += athlete2.judoMove;

	printf("\n");

	//Weightlifting round
	athlete1.lift = (rand() % 500) + 1;
	athlete2.lift = (rand() % 500) + 1;

	if (athlete1.lift > athlete2.lift)
		printf("Athlete1 wins on Weightlifting round!");
	else if (athlete1.lift < athlete2.lift)
		printf("Athlete2 wins on Weightlifting round!");
	else
		printf("Draw!");

	athlete1.totalScore += athlete1.lift;
	athlete2.totalScore += athlete2.lift;

	printf("\n");

	if (athlete1.totalScore > athlete2.totalScore)
		printf("Athlete1 win!");
	else if (athlete1.totalScore < athlete2.totalScore)
		printf("Athlete2 win!");
	else
		printf("Draw!");

	return 0;
}
