#pragma once
#include <fstream>
#include <string>
#include <vector>
class User
{
private:
	std::string _name;
	std::string _login;
	std::string _pass;
public:
	User();
	User(const std::string& name,const std::string& login, const std::string& pass) : 
	_name(name), _login(login), _pass(pass){}
	void saveUser(std::string filename) ;
	static std::vector<User> loadUsers(std::string filename) ;
	friend std::ostream& operator<<(std::ostream& os, const User& user);
};
