#include <windows.h>
#include <string.h>

class CursorController {
  HANDLE _console;

 public:
  CursorController() {
    _console = GetStdHandle(STD_OUTPUT_HANDLE);
  }

  CursorController(HANDLE console) : _console(console) {}

  void Gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(_console, pos);
  }
};

class Console {
  HANDLE _console;
  DWORD last_written;
 public:
  CursorController *cursorctl;

  ~Console() {
    CloseHandle(_console);
  }

  Console() {
    _console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    cursorctl = new CursorController(_console);
  }

  BOOL SetSelfActive() {
    return SetConsoleActiveScreenBuffer(_console);
  }

  BOOL Write(const char* str) {
    return WriteConsole(_console, str, strlen(str), &last_written, NULL);
  }

  BOOL Writeln(const char* str) {
    BOOL ret = (WriteConsole(_console, str, strlen(str), &last_written, NULL) && WriteConsole(_console, "\n", 1, &last_written, NULL));
    last_written++;
    return ret;
  }

};
