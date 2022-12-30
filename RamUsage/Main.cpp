#include <windows.h>
#include <string>
using namespace std;
#define WIN32_LEAN_AND_MEAN
#pragma comment(linker, "/EXPORT:mem=_mem@24")

//Writes out title of the song
extern "C" int __stdcall mem(HWND mWnd, HWND aWnd, CHAR * data, char* parms, BOOL show, BOOL nopause)
{
    string info = "0";
    if (string(data) == "memused") {
        MEMORYSTATUSEX memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        if (GlobalMemoryStatusEx(&memInfo)) {
            DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
            DWORDLONG totalUsed = physMemUsed / (1024 * 1024);
            info = to_string(totalUsed);
        }
    }
    else if (string(data) == "memtotal") {
        MEMORYSTATUSEX memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        if (GlobalMemoryStatusEx(&memInfo)) {
            DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
            DWORDLONG totalPhys = totalPhysMem / (1024 * 1024);
            info = to_string(totalPhys);
        }
    }
    else if (string(data) == "memload") {
        MEMORYSTATUSEX memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        if (GlobalMemoryStatusEx(&memInfo)) {
            DWORD memoryLoad = memInfo.dwMemoryLoad;
            info = to_string(memoryLoad);
        }
    }
    strcpy_s(data, info.size() + 1, info.c_str());

    return 3;
}