#ifndef _PHONE_INFO_HPP_
#define _PHONE_INFO_HPP_

#include <string>

class PhoneInfo {
private:
	std::string _name;
	std::string _surname;
	std::string _patronymic;
	std::string _homePhoneNumber;
	std::string _mobilePhoneNumber;
	std::string _workPhoneNumber;
	std::string _additionalInfo;

public:
	PhoneInfo() : _name(""), _surname(""), _patronymic(""),
		_homePhoneNumber(""), _mobilePhoneNumber(""),
		_workPhoneNumber(""), _additionalInfo("")
	{}

	PhoneInfo(std::string name, std::string surname, std::string patronymic,
		std::string homePhoneNumber, std::string mobilePhoneNumber,
		std::string workPhoneNumber, std::string additionalInfo) : _name(name), _surname(surname), _patronymic(patronymic),
		_homePhoneNumber(homePhoneNumber), _mobilePhoneNumber(mobilePhoneNumber),
		_workPhoneNumber(workPhoneNumber), _additionalInfo(additionalInfo)
	{}

	std::string GetName() const {
		return _name;
	}

	std::string GetSurname() const {
		return _surname;
	}

	std::string GetPatronimic() const {
		return _patronymic;
	}

	std::string GetHomePhoneNumber() const {
		return _homePhoneNumber;
	}

	std::string GetMobilePhoneNumber() const {
		return _mobilePhoneNumber;
	}

	std::string GetWorkPhoneNumber() const {
		return _workPhoneNumber;
	}

	std::string GetAdditionalInfo() const {
		return _additionalInfo;
	}

	void Print() const;

};

#endif