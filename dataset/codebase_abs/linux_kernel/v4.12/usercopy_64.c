unsigned long F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
long V_3 ;
F_2 () ;
F_3 () ;
asm volatile(
" testq %[size8],%[size8]\n"
" jz 4f\n"
"0: movq %[zero],(%[dst])\n"
" addq %[eight],%[dst]\n"
" decl %%ecx ; jnz 0b\n"
"4: movq %[size1],%%rcx\n"
" testl %%ecx,%%ecx\n"
" jz 2f\n"
"1: movb %b[zero],(%[dst])\n"
" incq %[dst]\n"
" decl %%ecx ; jnz 1b\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: lea 0(%[size1],%[size8],8),%[size8]\n"
" jmp 2b\n"
".previous\n"
_ASM_EXTABLE(0b,3b)
_ASM_EXTABLE(1b,2b)
: [size8] "=&c"(size), [dst] "=&D" (__d0)
: [size1] "r"(size & 7), "[size8]" (size / 8), "[dst]"(addr),
[zero] "r" (0UL), [eight] "r" (8UL));
F_4 () ;
return V_2 ;
}
unsigned long F_5 ( void T_1 * V_4 , unsigned long V_5 )
{
if ( F_6 ( V_6 , V_4 , V_5 ) )
return F_1 ( V_4 , V_5 ) ;
return V_5 ;
}
T_2 unsigned long
F_7 ( char * V_4 , char * V_7 , unsigned V_8 )
{
for (; V_8 ; -- V_8 , V_4 ++ ) {
char V_9 ;
if ( F_8 ( V_9 , V_7 ++ , sizeof( char ) ) )
break;
if ( F_9 ( V_9 , V_4 , sizeof( char ) ) )
break;
}
F_4 () ;
return V_8 ;
}
