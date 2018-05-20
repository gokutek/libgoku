﻿#include "goku/loop.h"
#include "uv.h"

NS_GOKU_BEG

Loop::Loop()
{
	loop_ = new uv_loop_s();
	uv_loop_init(loop_);
}


Loop::~Loop()
{
	delete loop_;
}


 Loop::operator uv_loop_s*()
{
	return loop_;
}


int Loop::Run(LoopRunMode mode)
{
	int const ret = uv_run(loop_, (uv_run_mode)mode);
	return ret;
}


void Loop::Diagnose()
{
	if (loop_) {
		uv_print_all_handles(loop_, stdout);
		uv_print_active_handles(loop_, stdout);
	}
}


int Loop::Close()
{
	int const ret = uv_loop_close(loop_);
	if (!ret) {
		delete loop_;
		loop_ = NULL;
	}
	return ret;
}

NS_GOKU_END