A UNIX shell with extended functionality in the form of sub-shells:

the main shell called "Standard-shell" has all the basic functionality of a shell with support for up to 3 arguments given per command in addition to 3 commands to initiate teh sub-shells:
Math - calls the math shell
String - calls the String shell
Logic - calls the logic shell (mostly does base conversions and "on" bits in a number)

each sub-shell has the following commands while not being able to execute default commands.

Math:
1) Power - gets 2 arguments and raises the first argument to the power of the second argument
2) Sqrt - gets an argumnent and prints its square root
3) Solve - gets 3 parameters that represent the coefficients of a quadratic formula and prints the possible solutions
4) exit - exits the shell and returns to the Standard-shell

Logic:
1) DectoBin - converts a decimal number to binary
2) DectoHex - converts a decimal number to hexadecimal
3) Highbit - prints the number of '1' bits in a number
4) exit - exits the shell and returns to the Standard-shell

String:
1) Find - gets a string argument and finds a given substring and prints "True" if successful (and "False otherwise)
2) PrintFile - gets a file address as an argument and prints the file
3) Replace - gets 2 strings and an index and replaces the first string with the second string from the given index.
4) exit - exits the shell and returns to the Standard-shell

in addition, all the shells have a custom history command that prints the history to a file when used.
