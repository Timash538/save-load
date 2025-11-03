#pragma once
#include "user.h"
#include <iostream>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

User::User()
{
	std::cout << "Enter name" << std::endl;
	std::cin >> _name;
	std::cout << "Enter login" << std::endl;
	std::cin >> _login;
	std::cout << "Enter reciever" << std::endl;
	std::cin >> _pass;
}

void User::saveUser(std::string filename)
{
	std::ofstream file(filename, std::ios::app);
	if (!file.is_open())
	{
		std::cout << "Couldn't open file\n";
		return;
	}
	fs::path p = filename;
	fs::permissions(p, fs::perms::owner_all, fs::perm_options::replace);
	file << *this;
}

std::vector<User> User::loadUsers(std::string filename)
{
	std::vector<User> users;
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cout << "Couldn't open file\n";
		return std::vector<User>();
	}
	std::string line;
	while(std::getline(file,line))
	{
		std::istringstream iss(line);
		std::string name, login, pass;
		if (std::getline(iss, name, '|') &&
		std::getline(iss, login, '|') &&
		std::getline(iss, pass))
		{
			users.emplace_back(name, login,pass);
		}
	}
	return users;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	os << user._name << "|" << user._login << "|" << user._pass << std::endl;
	return os;
}
