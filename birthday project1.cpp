#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <windows.h>

// function to enable ANSI colors in windows VS console
void enableANSI() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
}

void clearScreen() {
std::cout << "\033[H"; // move cursor to top left
}
int main() {
	enableANSI();

	//Define colors
	std::string pink = "\033[38;5;211m";
	std::string lightPink = "\033[38;5;224m";
	std::string purple = "\033[38;5;141m";
	std::string yellow = "\033[38;5;226m";
	std::string white = "\033[38;5;255m";
	std::string green = "\033[38;5;46m";
	std::string brown = "\033[38;5;94m";
	std::string reset = "\033[0m";

	bool flameState = true;

	while (true) {
		clearScreen();

		// 1. Animated Candles
		std::string flame = flameState ? " ( ) " : "  )  ";
		std::cout << "\n\n";
		std::cout << yellow << "       " << flame << "     " << flame << "     " << flame << reset << "\n";
		std::cout << white << "        | |       | |       | |    " << reset << "\n";

		// 2. The Cake Top (Purple Icing & Strawberries)
		std::cout << purple << "    _________________________________" << reset << "\n";
		std::cout << purple << "   / " << pink << "o" << reset << "  " << green << "," << reset << "     " << pink << "o" << reset << "  " << green << "," << reset << "     " << pink << "o" << reset << "  " << green << "," << reset << "   \\" << reset << "\n";
		std::cout << purple << "  |___________________________________|" << reset << "\n";

		// 3. The Drip and Layers
		std::cout << pink << "  |vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv|" << reset << "\n";
		std::cout << lightPink << "  |                                   |" << reset << "\n";
		std::cout << white << "  |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << reset << "\n";
		std::cout << lightPink << "  |                                   |" << reset << "\n";
		std::cout << brown << "  |___________________________________|" << reset << "\n";

		// 4. The Doily / Plate
		std::cout << white << "   (  (  (  (  (  (  (  (  (  (  (  )  )" << reset << "\n";

		// 5. The Birthday Message
		std::cout << "\n\n";
		std::cout << pink << "     * * * HAPPY 1YEAR ANNIVERSARY IG * * *" << reset << "\n\n";

		// Toggle animation state and sleep
		flameState = !flameState;
		std::this_thread::sleep_for(std::chrono::milliseconds(400));
	}

	return 0;
}