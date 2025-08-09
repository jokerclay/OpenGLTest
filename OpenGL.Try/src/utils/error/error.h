#ifndef ERROR_H
#define ERROR_H
#endif // !ERROR_H


typedef enum {
	ERR_OK = 0,
	ERR_GLFW_INIT_FAILED,
	ERR_WINDOWS_CREATION_FAILED,
	EPRR_GLEW_INIT_ERROR_FAILED,
	ERR_SHADER_COMPILATION_FAILED,
	ERR_SHADER_LINK_FAILED,

	ERR_UNKNOWN
}ErrorCode;


void SetLastError(ErrorCode code, const char* message);

void PrintLastError(const char * context);

ErrorCode GetLastErrorCode(void);

const char * GetLastErrorMessage(void);

void ClearLastError(void);