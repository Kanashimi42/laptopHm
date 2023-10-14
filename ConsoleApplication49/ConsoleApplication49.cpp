#include <iostream>
#include "Laptop.h"
#include "FlashDrive.h"
#include "ComputerMouse.h"

using namespace std;

int main() {
	FlashDrive flashDrive("Logo", "Halpa", "Type-C", 32, 400, 500, 1000);
	ComputerMouse computerMouse("Logitech", "G102", "USB-3.0", 3, 0.5, 1000, true);

	Laptop laptop("AMD", "RYZEN9", "A700", 8, 15000,
		"Nvidia", "GTX 1060", "PCIex3", 16, 50000,
		"Kingston", "KF560C", "DDR5", 16, 4777, 5000, true,
		"Kingston FURY", "2280", "2230", "M.2", 256, 400, 500, 6000,
		"Acer", "AN515-57-54VT", "Gray", 11, 8, 5000,
		"Samsung", "SamLap-98", "OLED", 16, 90, 5000,
		"Acer", "KeyLen-01", 0.7, 1000, true,
		&flashDrive,
		&computerMouse,
		"Acer", "Nitro", "Gray");

	cout << "\nOLD LAPTOP: " << endl;
	laptop.FullPrint();

	Laptop laptop1 = laptop;
	cout << "\nNEW LAPTOP: " << endl;
	laptop1.FullPrint();

	return 0;
}