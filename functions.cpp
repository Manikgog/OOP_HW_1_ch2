#include "functions.hpp"


int menu() {
	static int n;
	do {
		system("cls");
		std::cout << "��������� \"���������� �����\"\n";
		std::cout << "1. �������� ������ � ���������� �����.\n";
		std::cout << "2. ������� ���������� ����� �� �����.\n";
		std::cout << "3. ������� ������.\n";
		std::cout << "4. ����� ������.\n";
		std::cout << "5. ����� �� ���������.\n";
		std::cout << "������� ����� -> ";
		std::cin >> n;
	} while (n < 1 || n > 5);
	return n;
}
