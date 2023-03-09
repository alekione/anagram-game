/**
 * This is anagram console game application.
 * It is mainly for educational or entertainment only.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>

/**
 *
 * create_word - used for creating word for user guessing
 * @word: correct word used for creating user guess word
 * @level: user/current game level
 * Return: word for user to guess
 */
char *create_word(char *word, int level)
{
	char *ret = strdup(word);
	unsigned int rand_num[4];
	unsigned int num, i, j;

	srand(time(0));
	if (level == 1)
	{
		num = rand() % strlen(word);
		ret[num] = '_';
	}
	if (level == 2)
	{
		for (i = 0; i < 2; i++)
			rand_num[i] = (unsigned int)(rand() % strlen(word));
		for (i = 0; i < strlen(word); i++)
		{
			for (j = 0; j < 2; j++)
				if (rand_num[j] == i)
					ret[i] = '_';
		}
	}
	if (level == 3)
	{
		for (i = 0; i < 3; i++)
			rand_num[i] = (unsigned int)(rand() % strlen(word));
		for (i = 0; i < strlen(word); i++)
		{
			for (j = 0; j < 3; j++)
				if (rand_num[j] == i)
					ret[i] = '_';
		}
	}
	return(ret);
}

int main()
{
	FILE *file;
	int level, i;
	char *words[100];

	if (access("words.txt", R_OK) != 0)
	{
		perror("words.txt");
		exit(errno);
	}

	file = fopen("words.txt", "r");
	if (file == NULL)
	{
		perror("open");
		exit(1);
	}
	fseek(file, 0, SEEK_END);
	if (ftell(file) == 0)
	{
		printf("File is empty\n");
		fclose(file);
		exit(1);
	}
	fseek(file, 0, SEEK_SET);
	while (true)
	{
		printf("Please select your prefered level\n1 - easy\n2 - medium\n3 - hard\n");
		scanf("%d", &level);
		if (level == 1 || level == 2 || level == 3)
				break;
		printf("Invalid argument\n\n");
	}
	return 0;
}
