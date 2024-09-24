# RoPaSc
Efficient Rock Paper Scissors CLI game

### How to play?
1. Compile the project as described in the section below.
2. Run the `ropasc.exe` executable.
3. Write one of: "rock", "paper", "scissors", and then press Enter. Any other input string is considered invalid.
4. The computer picks one of the options as well and the winner is decided. You are informed of the computer's choice and the winner of the round.
5. The player is prompted again to make a choice. This repeats until the player decides to quit which can be done by entering "q" and pressing Enter.

### How to compile?
1. Clone the repository:
```
git clone https://github.com/RaduLucianR/ropasc.git
```
2. Make a `build` directory in the folder of the repository:
```
cd ropasc
mkdir build
```
3. Initialize the project with `cmake` on Windows by:
```
cd build
cmake -G "Visual Studio 17 2022" ..
```
If you want to compile the test suite as well then do:
```
cd build
cmake -G "Visual Studio 17 2022" -Dtest=ON ..
```
4. Build the project by:
```
cmake --build .
```
5. The executable is placed in:
```
.\build\Debug\ropasc.exe
```

### How to run the test suite?
1. Initialize the project with the `test` variable set to `ON` as described in Step 3.
2. Run the test suite by either running:
```
.\build\Debug\unitTests.exe
```
Or by executing the following in the `build` directory:
```
ctest
```