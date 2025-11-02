#include "message.h"
#include <vector>
#include <iostream>

int main()
{
	Message m;
	m.saveMessage("new_file");
	auto messages = Message::loadMessages("new_file");
	for (auto msg : messages)
	{
		std::cout << msg;
	}
	return 0;
}
