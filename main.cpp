
#include <iostream>

struct BoardField
{
    char value ;
    bool isAvailable;
    BoardField(){value = '0';isAvailable = true;}
};

void draw(BoardField b[][3]){
    for(int i =0; i <3; i++){
        for(int j = 0; j <3; j++){
            std::cout << b[i][j].value << "   ";
        }
        std::cout << std::endl;
    }
}
void init(BoardField b[][3]){
    int counter = 1;
    for(int i =0; i <3; i++){
        for(int j = 0; j <3; j++){
            b[i][j].value = static_cast<char>(counter + '0');
            b[i][j].isAvailable = true;
            counter++;
        }
    }
}
void mainDisplayMenue(){
    std::cout << "Welcome to Tic-Tac-Toe game!\n";
    std::cout << "Player 1 will start first with: x\n";
    std::cout << "Player 2 will play next with: o\n";
    std::cout << "Have Fun!\n";
}
void updateBoard(BoardField b[][3], char targetValue, char playerID){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (b[i][j].value == targetValue)
            {
                b[i][j].value = playerID;
                b[i][j].isAvailable = false;
            }
            
        }
    }
}
bool isPosAvailable(BoardField b[][3], int pos){
    char charPos = static_cast<char>(pos + '0');
    int counter = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((char)counter+'0' == pos)
            {
                if(b[i][j].isAvailable){
                    return true;
                }
            }
            counter++;
        }
        
    }
    
    return false;
}
bool isGameFinished(BoardField b[][3]){
    //int allVisited = true;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (b[i][j].isAvailable == true)
            {
                return false;
            }
        }
    }
    return true;
}
bool isWinableMove(BoardField b[][3]){
 // check all cases of winning: 8 cases

if ( b[0][0].value == b[0][1].value && b[0][0].value == b[0][2].value ) // case 1 (row 1):
    {
        return true;
    }
else if ( b[1][0].value == b[1][1].value && b[1][0].value == b[1][2].value ) // case 2 (row 2):
    {
        return true;
    }
else if ( b[2][0].value == b[2][1].value && b[2][0].value == b[2][2].value ) // case 3 (row 3):
    {
        return true;
    }
else if ( b[0][0].value == b[1][0].value && b[0][0].value == b[2][0].value ) // case 4 (col 1):
    {
        return true;
    }
else if ( b[0][1].value == b[1][1].value && b[0][1].value == b[2][0].value ) // case 5 (col 2):
    {
        return true;
    }
else if ( b[0][2].value == b[1][2].value && b[0][2].value == b[2][2].value ) // case 6 (col 3):
    {
        return true;
    }
else if ( b[0][0].value == b[1][1].value && b[0][0].value == b[2][2].value ) // case 7 (diag 1):
    {
        return true;
    }
else if ( b[0][2].value == b[1][1].value && b[0][2].value == b[2][0].value ) // case 8 (diag 2):
    {
        return true;
    }
else {
    return false;
} 
return false;
}

int main(){

    // main initialization:
    BoardField board[3][3];
    char targetPos;
    bool isPlayerOneTurn = true;
    bool isGFinished = false;
    BoardField f;

    
    //main menu display:
    mainDisplayMenue();
    //init board:
    init(board);
    //Draw Boared:
    draw(board);
    while (!isGFinished)
    {
       if (isPlayerOneTurn)
       {
        std::cout << "Player 1 turn:\t";
        
        while (true)
        {
            std::cin >> targetPos;
            if(isPosAvailable(board,targetPos)){
                updateBoard(board,targetPos,'x');
                break;
            }
        else{
                std::cout << "Position is not available. Pick another position: ";
            }
        }
        isPlayerOneTurn = false;
       }
       else{
        std::cout << "Player 2 turn:\t";
        while (true)
        {
            std::cin >> targetPos;
            if(isPosAvailable(board,targetPos)){
                updateBoard(board,targetPos,'o');
                break;
            }
            else{
                std::cout << "Position is not available. Pick another position: ";
            }  
        }
        isPlayerOneTurn = true;
       }

       if(isWinableMove(board)){
        draw(board);
        char player = (isPlayerOneTurn) ? '2':'1';
        std::cout << "Game is Finished: Player " << player << " Won the game\n\n\n";
            break;
       }
        if(isGameFinished(board)){
            draw(board);
            isGFinished = true;
            std::cout << "Game is Finished: Tie Game!\n\n\n";
            break;
        }
        draw(board);

    }
    return 0;
}