#include <iostream>

class Game {
public:
	char startInput = 0;
	std::string playerX;  //Variables
	std::string playerO;
	std::string winningPlayer;

	std::string gameBoard[3][3] = {  // Default Board Layout
		{"a1","a2","a3"},
		{"b1","b2","b3"},
		{"c1","c2","c3"}
	};

	bool startGame(bool output = true) {
		do {
			std::cin >> startInput;
			startInput = std::tolower(startInput);
			if (startInput == 'y') {
				std::cout << "X's go first...\n"; // Shows Starting board after starting the game
				showGameBoard();
				output = false;
			}
			else if (startInput == 'n') {
				std::cout << "\nSee you next time!\n";
				system("pause");
				output = false;
			}
			else {
				std::cout << "\nInvalid input, please type either 'y' or 'n'.";
				output = true;
			}
		} while (startInput != 'y' && startInput != 'n');
		return output;
	}

	bool activeGame(bool output = true, bool oPlayed = false, bool xPlayed = false) {
		while (output == true) {
			do {
				std::cout << "\nPlayer X's turn.\nType the cordinate for where you want to mark. ";
				std::cin >> playerX;
				xPlayed = false;
				for (int i = 0; i < 3; i++) for (int y = 0; y < 3; y++) // Player 'X'
				{
					if (playerX == gameBoard[i][y]) {
						gameBoard[i][y] = 'X'; // 'X' Placement and verification.
						xPlayed = true;
						winningPlayer = 'X';
						showGameBoard();
						output = true;
					}
				}
				if (xPlayed == false) {
					std::cout << "Invalid input, try again.";
				}
			} while (xPlayed == false);
			determineWinType();
			if (determineWinType() == true) {
				output = false;
				break;
			}
			else if (determineWinType() == false) {
					output = true;
			}
			do {
				std::cout << "\nPlayer O's turn.\nType the cordinate for where you want to mark. ";
				std::cin >> playerO;
				oPlayed = false;
				for (int i = 0; i < 3; i++) for (int y = 0; y < 3; y++)  // Player 'O'
				{
					if (playerO == gameBoard[i][y]) {
						gameBoard[i][y] = 'O';
						oPlayed = true;
						winningPlayer = 'O'; // 'O' Placement and verification.
						showGameBoard();
						output = true;
					}
				}
				if (oPlayed == false) {
				std::cout << "Invalid input, try again.";
				}
			} while (oPlayed == false);
			determineWinType();
			if (determineWinType() == true) {
				output = false;
				break;
			}
			else if (determineWinType() == false) {
				output = true;
			}
		}
		std::cout << "Congradulations " << winningPlayer << " Player, You win!\n\n";
		system("pause");
		return output;
	}

	// This ensures you can only win with 3 in a row.
	bool determineWinType(bool topWinner = false, bool centerWinner = false, bool bottomWinner = false, bool crossWinner = false
						, bool vertLeftWinner = false, bool vertCenterWinner = false, bool vertRightWinner = false) const {
		if (topLeft == topMid && topMid == topRight) {
			topWinner = true;
			return topWinner;
		}
		if (centerLeft == centerMid && centerMid == centerRight) {
			centerWinner = true;
			return centerWinner;
		}
		if (bottomLeft == bottomMid && bottomMid == bottomRight) {
			bottomWinner = true;
			return bottomWinner;
		}
		if (topLeft == centerMid && centerMid == bottomRight) {
			crossWinner = true;
			return crossWinner;
		}
		if (topRight == centerMid && centerMid == bottomLeft) {
			crossWinner = true;
			return crossWinner;
		}
		if (topLeft == centerLeft && centerLeft == bottomLeft) {
			vertLeftWinner = true;
			return vertLeftWinner;
		}
		if (topMid == centerMid && centerMid == bottomMid) {
			vertCenterWinner = true;
			return vertCenterWinner;
		}
		if (topRight == centerRight && centerRight == bottomRight) {
			vertRightWinner = true;
			return vertRightWinner;
		}
		else {
			return false;
		}
	}

	std::string &topLeft = gameBoard[0][0];
	std::string &topMid = gameBoard[0][1];
	std::string &topRight = gameBoard[0][2];
	std::string &centerLeft = gameBoard[1][0];
	std::string &centerMid = gameBoard[1][1];
	std::string &centerRight = gameBoard[1][2];
	std::string &bottomLeft = gameBoard[2][0];
	std::string &bottomMid = gameBoard[2][1];
	std::string &bottomRight = gameBoard[2][2];

	void showGameBoard() const{  // A visual representation of the gameboard.
		std::cout << "\n{" << topLeft << "," << topMid << "," << topRight << "}\n"
			<< "{" << centerLeft << "," << centerMid << "," << centerRight << "}\n"
			<< "{" << bottomLeft << "," << bottomMid << "," << bottomRight << "}\n\n";
	}
};

int main() {
	Game ticTacToe;
	std::cout << "Type 'y' to play. Type 'n' to quit.";
	ticTacToe.startGame();
	if (ticTacToe.startInput == 'y') {
		ticTacToe.activeGame();
	}
	return 0;
}