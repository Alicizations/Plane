

console.hpp:9

```
_console = GetStdHandle(STD_OUTPUT_HANDLE);

HANDLE GetStdHandle( DWORD nStdHandle );
```

是一个Windows API函数。它用于从一个特定的标准设备（标准输入、标准输出或标准错误）中取得一个句柄（用来标识不同设备的数值）。

nStdHandle为下列值之一:
STD_INPUT_HANDLE，标准输入的句柄；
STD_OUTPUT_HANDLE，标准输出的句柄；
STD_ERROR_HANDLE，标准错误的句柄。

------

console.hpp:5

`HANDLE _console;`

HANDLE（句柄）是Windows操作系统中的一个概念。
在Windows程序中，有各种各样的资源（窗口、图标、光标等），系统在创建这些资源时会为它们分配内存，并返回标示这些资源的标示号，即句柄。
句柄指的是一个核心对象在某一个进程中的唯一索引，而不是指针。
由于地址空间的限制，句柄所标识的内容对进程是不可见的，只能由操作系统通过进程句柄列表来进行维护。
句柄列表：每个进程都要创建一个句柄列表，这些句柄指向各种系统资源，比如信号量，线程，和文件等，进程中的所有线程都可以访问这些资源。

------

console.hpp:15

`COORD pos = {x, y};`

COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。其定义为：
typedef struct _COORD {
SHORT X; // horizontal coordinate
SHORT Y; // vertical coordinate
} COORD;

------

console.hpp:16

`SetConsoleCursorPosition(_console, pos);`

SetConsoleCursorPosition是API中定位光标位置的函数。

------

console.hpp:22

`DWORD last_written;`

DWORD 就是 Double Word， 每个word为2个字节的长度，DWORD 双字即为4个字节，每个字节是8位，共32位
用来存储(整数?)数据.1

------

console.hpp:27

`CloseHandle(_console);`

关闭一个内核对象。其中包括文件、文件映射、进程、线程、安全和同步对象等。在CreateThread成功之后会返回一个hThread的handle，且内核对象的计数加1，CloseHandle之后，引用计数减1，当变为0时，系统删除内核对象。  

若在线程执行完之后，没有调用CloseHandle，在进程执行期间，将会造成内核对象的泄露，相当于句柄泄露，但不同于内存泄露，这势必会对系统的效率带来一定程度上的负面影响。但当进程结束退出后，系统会自动清理这些资源。  

------

console.hpp:31

`CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);`

声明于wincon.h中，用于创建控制台屏幕缓冲区。

参数1:控制台屏幕缓冲区的权限。值有如下两种：

GENERIC_READ (0x80000000L)
请求控制台屏幕缓冲区的读取权限，使进程可以从缓冲区读取数据。
GENERIC_WRITE (0x40000000L)
请求控制台屏幕缓冲区的写权限，使进程可以从缓冲区写入数据。

其他参数参考:
http://baike.baidu.com/link?url=nz64L3bDsx8U_VmFYG_YQfBrcTzdbzj4ghTEheEU-8Ax_GFY5X8CG8es_XA0wA1N2OxZ0o5tFsoyRnkImUbqwkSbAWWxsNo-_CvwF9mFkQQhjaA69_82nmFHMTwAe0t7

------

console.hpp:36

`SetConsoleActiveScreenBuffer(_console)`

将指定的屏幕缓冲区设置为当前显示的控制台屏幕缓冲区

------

console.hpp:40

`WriteConsole(_console, str, strlen(str), &last_written, NULL);`

它用来从当前光标位置写入一个字符串到屏幕缓冲区。

参数1:控制台屏幕缓冲区的句柄(要有GENERIC_WRITE权限)
参数2:要写入的字符指针
参数3:要写入的字符数
参数4:存储字符数的变量指针
参数5:保留,为NULL

-----

main.cpp:27

`keystate = GetKeyState(0x41);`

该函数检取指定虚拟键的状态。该状态指定此键是UP状态，DOWN状态，还是被触发的（开关每次按下此键时进行切换）。0x41 = 'A'

-----

main.cpp:45

`time(&last_time);`

功能: 获取当前的系统时间，返回的结果是一个time_t类型(long)

-----

main.cpp:47

`Sleep(100);`

延时,单位是ms

-----



