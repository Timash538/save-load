#include "message.h"
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

	Message m;
	m.saveMessage("new_file");
	auto messages = Message::loadMessages("new_file");
	for (auto msg : messages)
	{
		std::cout << msg;
	}
	return 0;
}
