#include <windows.h>
#include <stdio.h>

// i686-w64-mingw32-gcc -o exec_shellcode.exe exec_shellcode.c

unsigned char win32_messagebox[] = {
  0x55, 0x8b, 0xec, 0x83, 0xec, 0x74, 0x64, 0xa1, 0x30, 0x00, 0x00, 0x00,
  0x53, 0x8b, 0x40, 0x0c, 0xc7, 0x45, 0xc4, 0x2a, 0x2c, 0x00, 0x00, 0x8b,
  0x40, 0x0c, 0xc7, 0x45, 0xc8, 0x50, 0x2a, 0x00, 0x00, 0x8b, 0x00, 0xc7,
  0x45, 0xcc, 0xa4, 0xf1, 0x00, 0x00, 0x8b, 0x00, 0x8b, 0x48, 0x18, 0x8b,
  0x41, 0x3c, 0x8b, 0x44, 0x08, 0x78, 0x03, 0xc1, 0x8b, 0x58, 0x20, 0x8b,
  0x50, 0x18, 0x03, 0xd9, 0x89, 0x55, 0xfc, 0x85, 0xd2, 0x74, 0x5e, 0x8b,
  0x50, 0x1c, 0x56, 0x8b, 0x70, 0x24, 0x57, 0x89, 0x55, 0xf4, 0x03, 0xf1,
  0x0f, 0xb7, 0x06, 0x8b, 0x3b, 0x8d, 0x04, 0x82, 0x03, 0xf9, 0x8b, 0x04,
  0x08, 0x03, 0xc1, 0x8d, 0x5b, 0x04, 0x89, 0x45, 0xf8, 0x33, 0xd2, 0xeb,
  0x0d, 0x6b, 0xd2, 0x1f, 0x0f, 0xb6, 0xc0, 0x66, 0x33, 0xd0, 0x0f, 0xb7,
  0xd2, 0x47, 0x8a, 0x07, 0x84, 0xc0, 0x75, 0xed, 0x0f, 0xb7, 0xfa, 0x8b,
  0x55, 0xf8, 0x33, 0xc0, 0x39, 0x7c, 0x85, 0xc4, 0x75, 0x04, 0x89, 0x54,
  0x85, 0xc4, 0x40, 0x83, 0xf8, 0x03, 0x7c, 0xf0, 0x8b, 0x55, 0xf4, 0x83,
  0xc6, 0x02, 0xff, 0x4d, 0xfc, 0x75, 0xb1, 0x5f, 0x5e, 0x8d, 0x45, 0xe8,
  0x33, 0xdb, 0x50, 0xc7, 0x45, 0xe8, 0x55, 0x73, 0x65, 0x72, 0xc7, 0x45,
  0xec, 0x33, 0x32, 0x2e, 0x64, 0x66, 0xc7, 0x45, 0xf0, 0x6c, 0x6c, 0x88,
  0x5d, 0xf2, 0xff, 0x55, 0xc4, 0x8d, 0x4d, 0xd0, 0x51, 0x50, 0xc7, 0x45,
  0xd0, 0x4d, 0x65, 0x73, 0x73, 0xc7, 0x45, 0xd4, 0x61, 0x67, 0x65, 0x42,
  0xc7, 0x45, 0xd8, 0x6f, 0x78, 0x41, 0x00, 0xff, 0x55, 0xc8, 0x53, 0x8d,
  0x4d, 0xdc, 0x51, 0x8d, 0x4d, 0x8c, 0x51, 0x53, 0xc7, 0x45, 0x8c, 0x54,
  0x68, 0x69, 0x73, 0xc7, 0x45, 0x90, 0x20, 0x4d, 0x65, 0x73, 0xc7, 0x45,
  0x94, 0x73, 0x61, 0x67, 0x65, 0xc7, 0x45, 0x98, 0x42, 0x6f, 0x78, 0x20,
  0xc7, 0x45, 0x9c, 0x77, 0x61, 0x73, 0x20, 0xc7, 0x45, 0xa0, 0x63, 0x72,
  0x65, 0x61, 0xc7, 0x45, 0xa4, 0x74, 0x65, 0x64, 0x20, 0xc7, 0x45, 0xa8,
  0x75, 0x73, 0x69, 0x6e, 0xc7, 0x45, 0xac, 0x67, 0x20, 0x61, 0x20, 0xc7,
  0x45, 0xb0, 0x77, 0x69, 0x6e, 0x64, 0xc7, 0x45, 0xb4, 0x6f, 0x77, 0x73,
  0x20, 0xc7, 0x45, 0xb8, 0x73, 0x68, 0x65, 0x6c, 0xc7, 0x45, 0xbc, 0x6c,
  0x63, 0x6f, 0x64, 0x66, 0xc7, 0x45, 0xc0, 0x65, 0x2e, 0x88, 0x5d, 0xc2,
  0xc7, 0x45, 0xdc, 0x4d, 0x65, 0x73, 0x73, 0xc7, 0x45, 0xe0, 0x61, 0x67,
  0x65, 0x42, 0x66, 0xc7, 0x45, 0xe4, 0x6f, 0x78, 0x88, 0x5d, 0xe6, 0xff,
  0xd0, 0x5b, 0xc9, 0xc3
};

unsigned char linux32_printline[] = {
  0x31, 0xc0, 0x31, 0xdb, 0x31, 0xd2, 0xb0, 0x04, 0xb3, 0x02, 0xeb, 0x06,
  0x59, 0xb2, 0x2f, 0xcd, 0x80, 0xc3, 0xe8, 0xf5, 0xff, 0xff, 0xff, 0x54,
  0x68, 0x69, 0x73, 0x20, 0x6c, 0x69, 0x6e, 0x65, 0x20, 0x77, 0x61, 0x73,
  0x20, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x65, 0x64, 0x20, 0x75, 0x73, 0x69,
  0x6e, 0x67, 0x20, 0x61, 0x73, 0x20, 0x6c, 0x69, 0x6e, 0x75, 0x78, 0x20,
  0x73, 0x68, 0x65, 0x6c, 0x6c, 0x63, 0x6f, 0x64, 0x65, 0x0a
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    LPVOID exec_buffer = VirtualAlloc(NULL,sizeof(win32_messagebox),MEM_COMMIT,PAGE_EXECUTE_READWRITE);
    void (*pcode)() = (void(*)())exec_buffer;

    memcpy(exec_buffer,linux32_printline,sizeof(linux32_printline));
    pcode();

    memcpy(exec_buffer,win32_messagebox,sizeof(win32_messagebox));
    pcode();

    return 0;
}