#include <iostream>

void drawHitBoard (char hitboard[3][3]);

int main()
{
    bool shipboard[][3] = 
    {
        {false, false, true},
        {false, false, true},
        {true, true, false}
    };

    
    char hitboard[3][3];
    
    //begin introduction dialogue
    std::string name, reply;
    
    std::cout << "What is your name? ";
    getline (std::cin, name);
    std::cout << "Hello, " << name << ".  Shall we play a game?  Please say 'yes' because that would be fun! ";
    getline (std::cin, reply);
    
    if (reply == "yes")
        std::cout << "Great!  Let's play Minisub!  It\'s like Battleship, but smaller.  I don\'t know Battleship yet, but maybe someday.  Ready?" << std::endl;
        std::cout << std::endl;
        
        
    //intro game and draw beginning board
    std::cout << "I have 2 mini subs hiding somewhere.  You have 6 missiles to sink them or I win!" << std::endl;
    std::cout << "Fire each missile by typing in row number and column number (separated by a space) when I ask for the target." << std::endl;
    
    for (int i=0; i < 3; i++)
    {
        for (int j=0; j < 3; j++)
        {
            std::cout << "X ";
            hitboard[i][j] = 'X';
        }
        std::cout << std::endl;
    }
    
    //guesses
    int row, col;
    int missiles = 6;
    bool alive = true;
    
    
    // while there are missiles and any part of subs left
    while ((missiles > 0) and (alive == true))
    {   
      //  std::cout << std::boolalpha;
      //  std::cout << "test misslies and alive = " << ((missiles > 0) and (alive = true)) << std::endl;
        
        // asks for target 
        std::cout << "You have " << missiles << " missile(s) left.  What is the target? (row column) ";
        std::cin >> row >> col;
        missiles = missiles-1;

        // checks if hit or miss
        if (shipboard[row-1][col-1] == true) // if hit then change hitboard and shipboard
        {
            hitboard[row-1][col-1] = '*';
            shipboard[row-1][col-1] = false;
            std::cout << "It's a hit!" << std::endl;
            drawHitBoard(hitboard);
        }
        else // if missed
        {
            std::cout << "You missed!" << std::endl;
        }
        
        //check if any part of any sub not hit
        alive = false;
        for (int i=0; i < 3; i++)
        {
            for (int j=0; j < 3; j++)
            {
                if (shipboard[i][j] == true)
                    {
                        alive = true;
                    }
            }
        }
            
     //   std::cout << std::boolalpha;
     //   std::cout << "test alive = " << alive << std::endl;
    }
    
    // if not alive
    if (alive == false)
        std::cout << "Congratulations! You've sunk my submarines! You win!" << std::endl;
    
    // if alive
    if (alive == true)
        std::cout << "I win!  But you'll do better next time!";
    return 0;
}



void drawHitBoard (char hitboard[3][3])
{
    for (int i=0; i < 3; i++)
    {
        for (int j=0; j < 3; j++)
        {
            std::cout << hitboard[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
