#include "error.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define ERROR_MESSAGE_SIZE 512

// g indecate global variable
static ErrorCode g_lastErrorCode = ERR_OK;
static char g_lastErrorMessage[ERROR_MESSAGE_SIZE] = { 0 };

void SetLastError(ErrorCode code, const char* message) {
	g_lastErrorCode = code;

	if (message)
		strncpy_s(g_lastErrorMessage, ERROR_MESSAGE_SIZE, message, ERROR_MESSAGE_SIZE - 1);
	else
		strncpy_s(g_lastErrorMessage, ERROR_MESSAGE_SIZE, "Unknown error", ERROR_MESSAGE_SIZE - 1);


	g_lastErrorMessage[sizeof(g_lastErrorMessage) - 1] = '\0';
}

void PrintLastError(const char* context)
{
	fprintf(stderr, "[ERROR] %s: (%d) %s\n", context, g_lastErrorCode, g_lastErrorMessage);
}

ErrorCode GetLastErrorCode(void)
{
	return g_lastErrorCode;
}


const char* GetLastErrorMessage(void)
{
	return g_lastErrorMessage;
}
void ClearLastError()
{
	g_lastErrorCode = ERR_OK;
	g_lastErrorMessage[0] = '\0';
}

