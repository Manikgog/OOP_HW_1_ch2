#include "phone_info.hpp"


void PhoneInfo::Print() const {
	std::cout << _surname << ' ' << _name << ' ' << _patronymic << std::endl;
	std::cout << "�������� �������: " << _homePhoneNumber << std::endl;
	std::cout << "������� �������: " << _workPhoneNumber << std::endl;
	std::cout << "��������� �������: " << _mobilePhoneNumber << std::endl;
	std::cout << "�������������� ����������: " << _additionalInfo << "\n\n";
}