/****************************************************************************************
*   This is the skeleton code for text-based Wordle Game assigned to BCE-3A as their 2nd
*   mini-project. The program presents a menu to the user/player to start the game. The
*   game-play requires the player to guess a 5-letter word in 6 tries. A try is valid if
*   the user enters a 5 letter word that is present in the dictionary. After the user has
*   entered a valid word, it needs to be compared against the solution. All the letters
*   that are in their correct place (compared to solution) are replaced by a '*' and all
*   the letters that are present in the solution but are out of place are replaced by a
*   '?'. A letter that is not present in the solution is replaced with a hyphen '-'.
*
*   Example word = Zonal (solution) not Case Sensitive
*   User Try 1:     break
*   program output: ---*-
*   User Try 2:     rolax
*   program output: -*?*-
*   User Try 3:     sonar
*   program output: -***-
*   User Try 4:     zonal
*   program output: *****   Correct! You Win!!
*
*   Skeleton Code developed by: Dr. Omar Ahmad
*   Dated: 12/06/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_SOLUTIONS   2315

char random_solution[6];
int printMenuReturnChoice(void);
bool setup(FILE ** fptDic, FILE ** fptSol);
void readWordFromFile(unsigned int index, char * resWord, FILE * fpt);
void printInstructions(void);
void gamePlay(FILE * fptDict, FILE * fptSol);
void toLowerCase(char * str);

int main()
{
    FILE * fptDictionary = NULL;
    FILE * fptSolutions = NULL;
    setup(&fptDictionary, &fptSolutions);
    int userChoice = 2;

    do
    {
        userChoice = printMenuReturnChoice();

        switch(userChoice)
        {
            case 1:
                gamePlay(fptDictionary, fptSolutions);
                break;
            case 2:
                printInstructions();
                break;
            case 3:
                printf("Exiting the game!\n");
                return(0);
            break;
            default:
                printf("\nEnter a valid choice!\n");
        }
    }
    while(userChoice != 3);
    printf("Exiting the game!\n");
    char testWord[6] = {0};
    for(int i=0; i<100; i++)
    {
        readWordFromFile(i, testWord,fptDictionary);
        printf("The word at index %d is: ", i);
        puts(testWord);
    }


    return 0;
}

void gamePlay(FILE * fptDict, FILE * fptSol)
{
    char solutionWord[6];
    char playerGuess[10];
    /** Get a random index into the solutions file */
    unsigned int solIdx = rand()% NUM_SOLUTIONS;
    readWordFromFile(solIdx, solutionWord,fptSol);
    //printf("The word at index %d is: ", solIdx);
    //puts(solutionWord);

    /********************* Insert your Code here ********************/
    /** Get input from the player **/
    printf("Try 1: ");
    gets(playerGuess);
    toLowerCase(playerGuess);




    /****************************************************************/

    //printf("Player entered the word: ");
    //puts(playerGuess);
}

bool setup(FILE ** fptDic, FILE ** fptSol)
{
    srand(time(0));
    if((*fptDic = fopen("data\\dictionary.txt", "r")) == NULL)
    {
        printf("Failed to open the dictionary file!\n");
        return (false);
    }

    if((*fptSol = fopen("data\\solutions.txt", "r")) == NULL)
    {
        printf("Failed to open the solutions file!\n");
        return (false);
    }
    return(true);
}

int printMenuReturnChoice(void)
{
    printf("****************************************************************\n");
    printf("Welcome to text based Wordle game.\n\n");
    printf("Enter your choice:\n\n");
    printf("1. New game.\n");
    printf("2. Instructions.\n");
    printf("3. Exit.\n");
    int choice;
    scanf("%d", &choice);
    fflush(stdin);
    printf("\n\n");
    return(choice);
}
void printInstructions(void)
{
    printf("\n");
    printf("*************************************************************************\n");
    printf(" The Wordle game-play requires the player to guess a Five-letter word in\n");
    printf(" six tries. A try is valid if the user enters a 5 letter word that is\n");
    printf(" present in the dictionary. All the letters that are in their\n");
    printf(" correct place (compared to solution) are replaced by a '*' and all the\n");
    printf(" letters that are present in the solution but are out of place are replaced by\n");
    printf(" a '?'. A letter that is absent in the solution is replaced with a hyphen '-'.\n\n");
    printf(" Example word = Zonal (solution) not Case Sensitive.\n");
    printf(" User Try 1:     break\n");
    printf(" program output: ---*-\n");
    printf(" User Try 2:     rolax\n");
    printf(" program output: -*?*-\n");
    printf(" User Try 3:     sonar\n");
    printf(" program output: -***-\n");
    printf(" User Try 4:     zonal\n");
    printf(" program output: *****   Correct! You Win!!\n");

}

void readWordFromFile(unsigned int index, char * resWord, FILE * fpt)
{
    unsigned int offset = (index * 7);
    fseek(fpt, offset, SEEK_SET);
    fgets(resWord, 6, fpt);
}

void toLowerCase(char * str)
{
    int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
        {
			str[i] += 32; //Convert to lowercase
		}
		i += 1;
	}
}
