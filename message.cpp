#pragma once
#include "message.h"
#include <iostream>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

Message::Message()
{
	std::cout << "Enter text" << std::endl;
	std::cin >> _text;
	std::cout << "Enter sender" << std::endl;
	std::cin >> _sender;
	std::cout << "Enter reciever" << std::endl;
	std::cin >> _receiver;
}

void Message::saveMessage(std::string filename)
{
	std::ofstream file(filename, std::ios::app);
	if (!file.is_open())
	{
		std::cout << "Couldn't open file\n";
		return;
	}
	fs::path p = filename;
	fs::permissions(p, fs::perms::owner_all, fs::perm_options::replace);
	file << *this << std::endl;
}

std::vector<Message> Message::loadMessages(std::string filename)
{
	std::vector<Message> messages;
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cout << "Couldn't open file\n";
		return std::vector<Message>();
	}
	std::string line;
	while(std::getline(file,line))
	{
		std::istringstream iss(line);
		std::string text, sender, receiver;
		if (std::getline(iss, text, '|') &&
		std::getline(iss, sender, '|') &&
		std::getline(iss, receiver))
		{
			messages.emplace_back(text, sender,receiver);
		}
	}
	return messages;
}

std::ostream& operator<<(std::ostream& os, const Message& msg)
{
	os << msg._text << "|" << msg._sender << "|" << msg._receiver << std::endl;
	return os;
}
