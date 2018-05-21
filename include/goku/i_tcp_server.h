﻿#ifndef GOKU_I_TCP_SERVER_H
#define GOKU_I_TCP_SERVER_H

#include "define.h"

NS_GOKU_BEG

/*
===============================================================================
===============================================================================
*/
class ITcpServer
{
public:
	virtual ~ITcpServer() = default;

	// 开始监听
	virtual int StartListen(char const *ip, int port) = 0;

	// 停止监听
	virtual int StopListen() = 0;

	// 收到客户端连接
	virtual void SetOnConnectionCallback(on_connection_cb_t const cb) = 0;

	// 收到客户端数据
	virtual void SetOnReadCallback(on_read_cb_t const &cb) = 0;

	// 客户端连接断开
	virtual void SetOnCloseCallback(on_close_cb_t const &cb) = 0;

	// 向客户端发送数据
	virtual int Send(peer_t peer, void const *data, size_t sz) = 0;

	// 断开与客户端的连接
	virtual int Disconnect(peer_t peer) = 0;
};

NS_GOKU_END

#endif // GOKU_I_TCP_SERVER_H
