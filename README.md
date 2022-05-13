# :snake: Monty Interpreter

Welcome to the Monty Bytecode Interpreter. This interpreter was built in the C language. It reads Monty bytecode files of any extension (preferably `.m` although it doesn't matter), and interprets the opcodes contained.

Our interpreter can be run as either a stack (LIFO) or queue (FIFO). Mode can be switched mid-script. The interpreter can handle a variety of Monty opcodes, including printing, mathematical operations, and more - all handled opcodes are listed below.

## :computer: Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
fonsy20 ~/monty ±|main ✗|→ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
fonsy20 ~/monty ±|main ✗|→
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
fonsy20 ~/monty ±|main ✗|→ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
fonsy20 ~/monty ±|main ✗|→
```

## :running: Getting Started

* [Ubuntu 14.04 LTS](http://releases.ubuntu.com/14.04/) - Operating system reqd.

* [GCC 4.8.4](https://gcc.gnu.org/gcc-4.8/) - Compiler used
## :arrow_down: Installing and Using

Clone the repository into a new directory:

```
$ git clone https://github.com/ChristianVaras/monty.git
```
Compile with the following:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

Run the interpreter on a file:

```
./monty file.m
```
## :file_folder: FILES
---

| Files | Description                    |
| ------------- | ------------------------------ |
| [main.c](https://github.com/ChristianVaras/monty/blob/main/main.c "main.c")      | Contains the main function that takes in the file and runs the parser. |
| [monty.h](https://github.com/ChristianVaras/monty/blob/main/monty.h "monty.h")      | Functions Prototype header.       |
| [functions_help.c](https://github.com/ChristianVaras/monty/blob/main/functions_help.c "functions_help.c")      | Contains helper functions for stack management and others.|
| [functions_monty1.c](https://github.com/ChristianVaras/monty/blob/main/functions_monty1.c "functions_monty1.c")      | Contains functions like push, pall, pint, swap.|
| [functions_monty1.c](https://github.com/ChristianVaras/monty/blob/main/functions_monty2.c "functions_monty2.c")      |  Contains functions like pop, pchar, pstr.|
| [functions_monty3.c](https://github.com/ChristianVaras/monty/blob/main/functions_monty3.c "functions_monty3.c")      | Contains functions likestack, queue|
| [math_func.c](https://github.com/ChristianVaras/monty/blob/main/math_func.c "math_func.c")      | Contains functions like add, sub, div, mul, mod.
| [errors.c](https://github.com/ChristianVaras/monty/blob/main/errors.c "errors.c")      | Contains error handling functions. |


## :wrench: Monty Opcodes

* **push**
  * Usage: `push <int>`
  * Pushes an element to the stack.
  * The parameter `<int>` must be an integer.

* **pall**
  * Prints all values in the stack/queue, starting from the top.

* **pint**
  * Prints the top value of the stack/queue.

* **pop**
  * Removes the top element of the stack/queue.

* **swap**
  * Swaps the top two elements of the stack/queue.

* **nop**
  * Does not do anything.

* **add**
  * Adds the top two elements of the stack/queue.
  * The result is stored in the second element from the top and the top element is popped.

* **sub**
  * Subtracts the top element of the stack/queue from the second element from the top.
  * The result is stored in the second element from the top and the top element is removed.

* **mul**
  * Multiplies the top two elements of the stack/queue.
  * The result is stored in the second element from the top and the top element is removed.

* **div**
  * Divides the second element from the top of the stack/queue by the top element.
  * The result is stored in the second element from the top and the top element is removed.

* **mod**
  * Computes the modulus of the second element from the top of the stack/queue divided by the top element.
  * The result is stored in the second element from the top and the top element is removed.

* **pchar**
  * Prints the character value of the top element of the stack/queue.
  * The integer at the top is treated as an ASCII value.

* **pstr**
  * Prints the string contained in the stack/queue.
  * Prints characters element by element until the stack/queue is empty, a value is `0`, or an error occurs.

* **rotl**
  * Rotates the top element of the stack/queue to the bottom.

* **rotr**
  * Rotates the bottom element of the stack/queue to the top.

* **stack**
  * Switches a queue to stack mode.

* **queue**
  * Switches a stack to queue mode.

:arrow_forward: Opcodes preceeded by a `#` are treated as comments and the corresponding line is ignored.

:arrow_forward: Lines can be empty and can contain any number of spaces before or after an opcode and its argument (only the first opcode and/or argument is taken into account).

# 🧠​ Brainf*ck script

Brainfuck is an esoteric programming language,the language consists of only eight simple commands, a data pointer and an instruction pointer.Brainfuck simply requires one to break commands into microscopic steps.

The language's name is a reference to the slang term brainfuck, which refers to things so complicated or unusual that they exceed the limits of one's understanding.

[Language design](https://en.wikipedia.org/wiki/Brainfuck)

You can install the bf interpreter to test your code: sudo apt-get install bf

This script is in bf folder.

## :paperclip: Scripts
---

| Files | Description                    |
| ------------- | ------------------------------ |
| [1000-school.bf](https://github.com/ChristianVaras/monty/blob/main/bf/1000-school.bf "1000-school.bf")      | Write a Brainf*ck script that prints School, followed by a new line |
| [1001-add.bf](https://github.com/ChristianVaras/monty/blob/main/bf/1001-add.bf "1001-add.bf")      | Add two digits given by the user.|
| [1002-mul.bf](https://github.com/ChristianVaras/monty/blob/main/bf/1002-mul.bf "1002-mul.bf")      | Multiply two digits given by the user.|
| [1003-mul.bf](https://github.com/ChristianVaras/monty/blob/main/bf/1003-mul.bf "1003-mul.bf")      | Read the two digits from stdin, multiply them, and print the result, followed by a new line.|

## :blue_book: Authors

* **Christian Varas** - [@ChristianVaras](https://github.com/ChristianVaras)

* **Dany Chávez** - [@BigDany1792](https://github.com/BigDany1792)
