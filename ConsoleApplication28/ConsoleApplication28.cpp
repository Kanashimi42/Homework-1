#include <iostream>
#include "Laptop.h"

using namespace std;

int main() {

	Laptop laptop("AMD", "Ryzen 7 5700U", "EliteBook", 16, 18000,
		"Nvidia", "GTX 3050", "PCIex8", 16, 60000,
		"Samsung", "EVO 980", "DDR4", 32, 5999, 5200, true,
		"Crucial", "P5", "2280", "M.2", 512, 450, 550, 7500,
		"Dell", "XPS", "Silver");

	cout << "\nOLD LAPTOP: " << endl;
	laptop.FullPrint();

	Laptop laptop1 = laptop;
	cout << "\nNEW LAPTOP: " << endl;
	laptop1.FullPrint();

	return 0;
}
