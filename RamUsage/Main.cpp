#include <windows.h>
#include <string>
using namespace std;
#define WIN32_LEAN_AND_MEAN
#pragma comment(linker, "/EXPORT:usedphysicalmem=_usedphysicalmem@24")
#pragma comment(linker, "/EXPORT:totalphysicalmem=_totalphysicalmem@24")
#pragma comment(linker, "/EXPORT:memoryload=_memoryload@24")

//Writes out title of the song
extern "C" int __stdcall usedphysicalmem(HWND mWnd, HWND aWnd, CHAR * data, char* parms, BOOL show, BOOL nopause)
{
    string info = "0";
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memInfo)) {
        DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
        DWORDLONG totalUsed = physMemUsed / (1024 * 1024);
        info = std::to_string(totalUsed);
    }
    char* cstr = new char[info.size() + 1];
    info.copy(cstr, info.size() + 1);
    cstr[info.size()] = '\0';
    strcpy_s(data, strlen(cstr) + 1, cstr);

    return 3;
}

extern "C" int __stdcall totalphysicalmem(HWND mWnd, HWND aWnd, CHAR * data, char* parms, BOOL show, BOOL nopause)
{
    string info = "0";
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memInfo)) {
        DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
        DWORDLONG totalPhys = totalPhysMem / (1024 * 1024);
        info = std::to_string(totalPhys);
    }
    char* cstr = new char[info.size() + 1];
    info.copy(cstr, info.size() + 1);
    cstr[info.size()] = '\0';
    strcpy_s(data, strlen(cstr) + 1, cstr);

    return 3;
}

extern "C" int __stdcall memoryload(HWND mWnd, HWND aWnd, CHAR * data, char* parms, BOOL show, BOOL nopause)
{
    string info = "0";
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memInfo)) {
        DWORD memoryLoad = memInfo.dwMemoryLoad;
        info = std::to_string(memoryLoad);
    }
    char* cstr = new char[info.size() + 1];
    info.copy(cstr, info.size() + 1);
    cstr[info.size()] = '\0';
    strcpy_s(data, strlen(cstr) + 1, cstr);

    return 3;
}