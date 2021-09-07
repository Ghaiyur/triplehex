//!!!!! to build just do cl filename.cpp /EHsc the /EHsc prevents warnings and run the .exe
// preproc directive -> instruction to the compiler, include basically
// includes
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
int len = sizeof(alphanum) - 1;

char GenRandom() { // Random string generator function.
   return alphanum[rand() % len];
}

void PrintIntroduction(int Difficulty)
{
    // Random Lord Gen
    std::string lord="Lord ";
    srand(time(NULL));
    int n = 10;
    for(int z = 0; z < n; z++) //generate string of length n
    {  
      lord += GenRandom(); //get random character from the given list
    }

    // Random Region
    std::string region="Kingdom of ";
    srand(time(NULL));
    n = 5;
    for(int z = 0; z < n; z++) //generate string of length n
    {  
      region += GenRandom(); //get random character from the given list
    }

    std::cout << "\n\nYou are a thief from the Guild trying to break into the safe of "<< lord << "\nOf the " << region << std::endl ; // :: is a scope op ,std is the namespace
    std::cout << "This Kingdom Guards have the difficulty of " << Difficulty << std::endl;
    std::cout << "Use your mastery over the crypto machine lock...\n\n";
} 

bool PlayGame(int Difficulty)
{
    srand(time(NULL));

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+* There are 3 number in the code\n";
    std::cout << "+ The codes add-up to: " << CodeSum <<std::endl;
    std::cout << "* The codes multiple to give: " << CodeProduct <<std::endl;

    int GuessA,GuessB,GuessC;
    std::cout << "Enter the code : ";
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "you have entered: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Win scenario check
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "*** You have unlocked the safe, we must move to the next kingdom ***";
        return true;
    }
    else
    {
        std::cout << "*** Be careful thief, the Guild is not that forgiving, try again ***";
        return false;
    }
}


int main() // returns an integer
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    int MaxLevel;

    std::cout << "\nChoose your difficulty, thief(1-how much you dare?)\n";
    std::cin >> MaxLevel;


    while(LevelDifficulty <= MaxLevel) // Game loop

    {
        PrintIntroduction(LevelDifficulty);

        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear(); //Clears any erros
        std::cin.ignore(); // Discards any errors

        if (bLevelComplete)
        {
            // Increase 
            ++LevelDifficulty;
        }
    }
    std::cout << "\n*** You have played your part thief, the Guild pledges to protect you *** \n";
    return 0;
}
