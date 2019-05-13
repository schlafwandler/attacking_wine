#include <windows.h>
#include <stdio.h>

// i686-w64-mingw32-gcc -o printdata.exe printdata.c
// x86_64-w64-mingw32-gcc -o printdata64.exe printdata.c

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    printf("WinMain:\t\t%p\n",WinMain);

    HMODULE kernel32 = LoadLibrary("kernel32.dll");
    printf("kernel32.dll:\t\t%p\n",kernel32);

    printf("GetProcAddress:\t\t%p\n",GetProcAddress);

    HMODULE msvcrt = LoadLibrary("msvcrt.dll");
    printf("msvcrt.dll:\t\t%p\n",msvcrt);    

    HMODULE ntdll = LoadLibrary("ntdll.dll");
    printf("ntdll.dll:\t\t%p\n",ntdll);

    int dummy;
    printf("Stack:\t\t\t%p\n",&dummy);

    void *heap = malloc(128);
    printf("Heap:\t\t\t%p\n",heap);

    getchar();

    return 0;
}
