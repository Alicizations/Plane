#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#include "console.hpp"

char map[32][33] = {
  "--------------------------------",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "|                              |",
  "--------------------------------",
};

Console *console;

void MainLoop() {
  map[1][1] = ' ';
  SHORT keystate;
  keystate = GetKeyState(0x41);
  if (keystate & 0x8000) {
    map[1][1] = 'A';
  }

  console->cursorctl->Gotoxy(0, 0);
  DWORD n;
  for (int i = 0; i < 32; ++i) {
    console->Writeln(map[i]);
  }
}

time_t last_time;

int main() {
  console = new Console();
  console->SetSelfActive();
  while (1) {
    time(&last_time);
    MainLoop();
    Sleep(100);
  }
  delete console;
  return 0;
}
