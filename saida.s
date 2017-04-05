
.data
a: .word 0

_newline: .asciiz "\n"
.text
.globl main

main:
lw $t1, 0($sp)
addiu $sp, $sp, 4
lw $a0, 0($sp)
addiu $sp, $sp, 4
add $a0, $a0, $t1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $v0, 4
la $a0, _newline
syscall

li $v0, 10
syscall
