#include "phone_info.hpp"


void PhoneInfo::Print() const {
	std::cout << _surname << ' ' << _name << ' ' << _patronymic << std::endl;
	std::cout << "Домашний телефон: " << _homePhoneNumber << std::endl;
	std::cout << "Рабочий телефон: " << _workPhoneNumber << std::endl;
	std::cout << "Мобильный телефон: " << _mobilePhoneNumber << std::endl;
	std::cout << "Дополнительная информация: " << _additionalInfo << "\n\n";
}