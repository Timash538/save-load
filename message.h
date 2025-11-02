#pragma once
#include <fstream>
#include <string>
#include <vector>
class Message
{
private:
	std::string _text;
	std::string _sender;
	std::string _receiver;
public:
	Message();
	Message(const std::string& text,const std::string& sender, const std::string& receiver) : 
	_text(text), _sender(sender), _receiver(receiver){}
	void saveMessage(std::string filename);
	static std::vector<Message> loadMessages(std::string filename);
	friend std::ostream& operator<<(std::ostream& os, const Message& msg);
};
