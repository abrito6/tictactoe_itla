#include <cstdlib>
using namespace std;

char tablero[3][3]; //Possible values are X, O and _ (for blank positions)
char jugadoractual = 'X';

bool isAvailable(int row, int column)
{
	//TODO: Implement this code so that it tells the user whether or not he can play in the selected cell
	
	//horizontal
	 char jugadorEncontrado = tablero[0][0];
     for(int i =0 ; i < 3; i++){
             for(int j = 0 ; j < 3 ; j++){
                     if(tablero[i][j] == '_'){
                          break; break;
                     }
                     if(jugadorEncontrado != tablero[i][j]){
                          break; break;
                                        
                     }
                     jugadorEncontrado = tablero[i][j];
                     if(j == 2){
                          printf("EXELENTE HA GANADO %c", jugadorEncontrado);
                


	return true;
}
}
}

     //vertical
     jugadorEncontrado = tablero[0][0];
     for(int i =0 ; i < 3; i++){
             for(int j = 0 ; j < 3 ; j++){
                     if(tablero[j][i] == '_'){
                          break; break;
                     }
                     if(jugadorEncontrado != tablero[j][i]){
                          break; break;                                                 
                                        
                     }
                     jugadorEncontrado = tablero[j][i];
                     if(j == 2){
                          printf("EXELENTE HA GANADO %c", jugadorEncontrado);
                          return true;                          
                     }
              }             
             
     }
     
     //diagonal de izquierda a derecha
     jugadorEncontrado = tablero[0][0];
     for(int i = 0 ; i < 3; i++){
           if(tablero[i][i] == '_'){
                 break; 
             }
             if(jugadorEncontrado != tablero[i][i]){
                   break;                                               
                                        
             }
             jugadorEncontrado = tablero[i][i];
             if(i == 2){
                    printf("EXELENTE HA GANADO %c", jugadorEncontrado);
                    return true;                          
             }                 
             
     }

     //diagonal de derecha a izquierda
     jugadorEncontrado = tablero[0][2];
     for(int i = 2 ; i >= 0; i--){
           if(tablero[2-i][i] == '_'){
                 break; 
             }
             if(jugadorEncontrado != tablero[2-i][i]){
                   break;                                               
                                        
             }
             jugadorEncontrado = tablero[2-i][i];
             if(i == 0){
                    printf("EXELENTE HA GANADO %c", jugadorEncontrado);
                    return true;                          
             }                 
             
     }

     return false;
     
     
}

//Give initial values to the board matrix
void init()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			tablero[i][j] = '_';
		}
	}
}

void clearScreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

bool validate(int number)
{
	if(number >= 1 && number <= 3)
	{
		return true;
	}else
	{
		cout << "Please pick a value between 1 and 3" << endl;
		return  false;
	}
}

bool gameover()
{
	//TODO: Implement this method,verify if any player has won the match of it's being a tie.
	//Return true if the game is over. Print message informing the user about what just happened.
	
for(int i = 0 ; i < 3; i++){
             for(int j = 0; j < 3; j++){
                  if(tablero[i][j] == '_'){
                      return false;                
                  }
             }             
             
     }

bool isValidInput(istream& in){
	if(in.fail())
	{
		cout <<"Only numbers are accepted" << endl;
	    in.clear();
	    in.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
	    return false;
	}else
	{
		return true;
	}
}

void showBoard()
{
	while(!gameover())
	{
		clearScreen();
		int row = 0;
		int column = 0;

		cout << "It's " << player << "'s turn" << endl;
		//printing column numbers
		cout << "\t";
		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
		}
		cout << endl;

		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
			for(int j = 0 ; j < 3 ; j++)
			{
				cout << board[i][j] << "\t";
			}
			cout << endl;
		}
		do
		{
			cout << "In what row would you like to play? =>";
			cin >> row;
		}while(!isValidInput(cin) && !validate(row));
		do
		{
			cout << "In what column would you like to play? => ";
			cin >> column;
		}while(!isValidInput(cin) && !validate(column));

		if(isAvailable(row,column))
		{
			board[row - 1][column - 1] = player;
			player = player == 'X' ? 'O' : 'X';
		}else
		{
			cout << "The cell " << row << " , " << column << " is not available" << endl;
		}
	}
}