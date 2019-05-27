#include <windows.h>
#include <stdio.h>

// i686-w64-mingw32-gcc -o setforceexec_test.exe setforceexec_test.c
// x86_64-w64-mingw32-gcc -o setforceexec_test64.exe setforceexec_test.c

typedef (*pVIRTUAL_SetForceExec)(
    unsigned long enable
    );

#define VIRTUAL_SetForceExec_32 0x7bca1270
#define VIRTUAL_SetForceExec_64 0x7bcbbb90

#if _WIN64 || __amd64__
#define VIRTUAL_SetForceExec_ptr VIRTUAL_SetForceExec_64
#else
#define VIRTUAL_SetForceExec_ptr VIRTUAL_SetForceExec_32
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    pVIRTUAL_SetForceExec VIRTUAL_SetForceExec = (pVIRTUAL_SetForceExec) VIRTUAL_SetForceExec_ptr;

    printf("Press any key to get many RWX pages!\n");
    getchar();

    VIRTUAL_SetForceExec(-1);

    printf("There should be lots of executable+writeable memory now.\n");
    getchar();

    return 0;
}