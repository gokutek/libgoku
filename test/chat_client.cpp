#include <assert.h>
#include <iostream>
#include <string>
#include "chat_client.h"

NS_GOKU_BEG

ChatClient::ChatClient(Loop *loop)
	: client_(loop)
{
	client_.SetOnConnectCallback(std::bind(&ChatClient::OnConnect, this, std::placeholders::_1));
	client_.SetOnReadCallback(std::bind(&ChatClient::OnRead, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	client_.SetOnCloseCallback(std::bind(&ChatClient::OnClose, this, std::placeholders::_1));
}


ChatClient::~ChatClient()
{
}


int ChatClient::Start()
{
	int ret = client_.Connect("127.0.0.1", 9005);
	assert(!ret);
	return 0;
}


void ChatClient::OnRead(uint64_t, void *data, size_t sz)
{
	std::string const str((char const*)data, (char const*)data + sz);
	std::cout << str << std::endl;
	if (str == "quit") {
		client_.Disconnect();
	}
}


void ChatClient::OnClose(uint64_t)
{
	std::cout << "Lost connection to the server" << std::endl;
}


void ChatClient::OnConnect(int status)
{
	std::cout << "Connect to server finish, errno = " << status << std::endl;
}

NS_GOKU_END
