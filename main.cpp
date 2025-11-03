#include "message.h"
#include "user.h"
#include <vector>
#include <iostream>
#include <pwd.h>
#include <unistd.h>
int main()
{
	struct passwd* pw = getpwnam("timash");
	if (!pw)
	{
		std::cerr << "ERROR: 'timash' not found\n";
		return 1;
	}

	if (setgid(pw->pw_gid) != 0 || setuid(pw->pw_uid) != 0)
	{
		std::cerr << "ERROR: cannot switch to timash\n";
		return 1;
	}

	while(true)
	{
		std::cout << "Enter 1 for save message, 2 for save User, 3 for show all messages, 4 for show all users. 0 - exit" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
			case 1:
			{
			Message m;
			m.saveMessage("messages");
			break;
			}
			case 2:
			{
			User u;
			u.saveUser("users");
			break;
			}
			case 3:
			{
			auto messages = Message::loadMessages("messages");
			for (auto msg : messages)
			{
				std::cout << msg;
			}
			break;
			}
			case 4:
			{
			auto users = User::loadUsers("users");
			for (auto usr : users)
			{
				std::cout << usr;
			}
			break;
			}
			case 0:
			return 0;
			default:
			break;
		}
	}
	return 0;
}
