#!/bin/bash
read -p "Output name: " out
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c test/*.c -o "$out"
