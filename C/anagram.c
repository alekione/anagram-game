/**
 * This is anagram console game application.
 * It is mainly for educational or entertainment only.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
	char *word = "sleepy";
	int level = 3;
	printf("%s\n",create_word(word, level));
	return 0;
}
