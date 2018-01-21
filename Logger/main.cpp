#pragma once

#include <Windows.h>
#include <tchar.h>
#include <fstream>
#include <string>

#define alog 1
#define atry 1

void write_log(const std::string file, const std::string &text)
{
	std::ofstream log_file(file, std::ios_base::out | std::ios_base::app);
	log_file << text;
}

void log(const char* text, ...)
{
	std::string log;
	log.append("[");
	log.append(__DATE__);
	log.append("]");
	log.append(" ");
	log.append("[");
	log.append(__TIME__);
	log.append("]");
	log.append(" ");
	log.append(text);
	log.append("\n");
	write_log("alog.txt" , log.c_str());
}

int main()
{
#if alog
	log("main -> ...");
#endif
#if atry
	__try {
		int *p = 0;
		*p = 0;
}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		log("exception -> ...");
	}
#endif

	return 0;
}
