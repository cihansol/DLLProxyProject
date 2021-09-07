#pragma warning( disable : 6031 )
#include "DLLMain.h"


VOID Initialise(PVOID lpParameter)
{
    printf("Sleeping for 4secs.. \n");
    Sleep(4000);
    printf("Slept for 4secs. \n");
    printf("Exiting thread.");
    return;
}


BOOL WINAPI DllMain(HMODULE hModule,
                    DWORD  ul_reason_for_call,
                    LPVOID lpReserved
                   )
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            DisableThreadLibraryCalls(hModule);
            AllocConsole();
            SetConsoleTitleW(L"DLLProxyProject");
            freopen("CONOUT$", "w", stdout);
            freopen("CONOUT$", "w", stderr);
            printf("DLLProxyProject Loaded! \n");

            CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Initialise), (PVOID)hModule, NULL, NULL);
            break;
        }
        case DLL_PROCESS_DETACH:
        {
            printf("AnonPresence Unloaded! \n");
            FreeConsole();
            break;
        }
    }

    return TRUE;
}