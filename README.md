# ConCol

A small Windows console manipulation library I wrote back in 2001 for a Scrabble game assignment. It wraps the Windows Console API to give you easy colour control, cursor positioning, and screen clearing.

I pulled it out of the Scrabble project so it could be used standalone.

## What it does

- Set foreground and background colours (16 of each)
- Move cursor to any X,Y position
- Clear the screen or a section of it
- Resize the console window
- Get console dimensions

## Usage

Copy `concol.hpp` and `concol.cpp` into your project, include the header, and go:

```cpp
#include "concol.hpp"
#include <iostream>

int main()
{
    concol con;
    con.setForeground(LtGreen);
    con.setBackground(bBlue);
    con.ClearScreen();
    con.goto_XY(30, 10);
    std::cout << "Hello World!";
    con.goto_XY(0, 20);
    return 0;
}
```

Compile with: `g++ -std=c++17 -Wall your_program.cpp concol.cpp -o your_program`

## Colours

**Foreground:** `Black`, `Blue`, `Red`, `Green`, `Cyan`, `Magenta`, `Orange`, `DkGray`, `LtGray`, `LtRed`, `LtGreen`, `LtBlue`, `LtCyan`, `LtMagenta`, `Yellow`, `White`

**Background:** Same names with a `b` prefix — `bBlue`, `bRed`, `bLtCyan`, etc.

## Examples

See the `examples/` folder for a few demos — colour display, a simple menu, and a bouncing ball animation.

## Limitations

- Windows only (uses Windows Console API)
- 16 colours only (standard console palette)
- Output only — use `std::cin` or `_getch()` for input

## License

MIT License (c) C.Brown 2001-2026
