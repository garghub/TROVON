long
F_1 ( char * V_1 , const char * V_2 , long V_3 )
{
long V_4 ;
F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_4 ;
}
long
F_3 ( char * V_1 , const char * V_2 , long V_3 )
{
long V_4 = - V_5 ;
if ( F_4 ( V_6 , V_2 , 1 ) )
F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_4 ;
}
unsigned long
F_5 ( void * V_7 , unsigned long V_8 )
{
F_6 ( V_7 , V_8 ) ;
return V_8 ;
}
unsigned long
F_7 ( void * V_7 , unsigned long V_8 )
{
if ( F_4 ( V_9 , V_7 , V_8 ) )
F_6 ( V_7 , V_8 ) ;
return V_8 ;
}
long F_8 ( const char * V_10 , long V_8 )
{
unsigned long V_4 , V_11 ;
if ( ! F_9 ( V_10 ) )
return 0 ;
if ( V_8 < 0 || V_8 + ( V_12 ) V_10 > F_10 () -> V_13 . V_14 )
V_8 = F_10 () -> V_13 . V_14 - ( V_12 ) V_10 ;
asm volatile(
"0: cmp %4,%0\n"
" beq 2f\n"
"1: movbu (%0,%3),%1\n"
" inc %0\n"
" cmp 0,%1\n"
" beq 3f\n"
" bra 0b\n"
"2: clr %0\n"
"3:\n"
".section .fixup,\"ax\"\n"
"4: jmp 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .balign 4\n"
" .long 1b,4b\n"
".previous\n"
:"=d"(res), "=&r"(w)
:"0"(0), "a"(s), "r"(n)
: "memory", "cc");
return V_4 ;
}
