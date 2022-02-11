T_1 int F_1 ( int T_2 * V_1 )
{
int V_2 ;
if ( ! F_2 ( V_3 , V_1 , sizeof ( int ) ) )
return - V_4 ;
__asm__ __volatile__ (
DCACHE_CLEAR("%0", "r4", "%1")
" .fillinsn\n"
"1:\n"
" lock %0, @%1 -> unlock %2, @%1\n"
"2:\n"
".section .fixup,\"ax\"\n"
" .balign 4\n"
"3: ldi %0, #%3\n"
" seth r14, #high(2b)\n"
" or3 r14, r14, #low(2b)\n"
" jmp r14\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .balign 4\n"
" .long 1b,3b\n"
".previous\n"
: "=&r" (oldval)
: "r" (addr), "r" (1), "i"(-EFAULT)
: "r14", "memory"
#ifdef F_3
, "r4"
#endif
);
return V_2 ;
}
T_1 int F_4 ( void * V_1 , int V_5 , int V_6 )
{
F_5 () ;
return 0 ;
}
T_1 int F_6 ( char * V_1 , int V_7 , int V_8 )
{
return - V_9 ;
}
