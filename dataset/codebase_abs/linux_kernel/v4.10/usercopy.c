unsigned long
F_1 ( void * V_1 , const void * V_2 , unsigned long V_3 )
{
if ( F_2 ( V_4 , V_1 , V_3 ) )
F_3 ( V_1 , V_2 , V_3 ) ;
return V_3 ;
}
unsigned long
F_4 ( void * V_1 , const void * V_2 , unsigned long V_3 )
{
if ( F_2 ( V_5 , V_2 , V_3 ) )
F_5 ( V_1 , V_2 , V_3 ) ;
else
memset ( V_1 , 0 , V_3 ) ;
return V_3 ;
}
long
F_6 ( char * V_6 , const char * V_7 , long V_8 )
{
long V_9 ;
F_7 ( V_6 , V_7 , V_8 , V_9 ) ;
return V_9 ;
}
long
F_8 ( char * V_6 , const char * V_7 , long V_8 )
{
long V_9 = - V_10 ;
if ( F_2 ( V_5 , V_7 , 1 ) )
F_7 ( V_6 , V_7 , V_8 , V_9 ) ;
return V_9 ;
}
unsigned long
F_9 ( void * V_1 , unsigned long V_3 )
{
F_10 ( V_1 , V_3 ) ;
return V_3 ;
}
unsigned long
F_11 ( void * V_1 , unsigned long V_3 )
{
if ( F_2 ( V_4 , V_1 , V_3 ) )
F_10 ( V_1 , V_3 ) ;
return V_3 ;
}
long F_12 ( const char * V_11 , long V_3 )
{
unsigned long V_9 , V_12 ;
if ( ! F_13 ( V_11 ) )
return 0 ;
if ( V_3 < 0 || V_3 + ( V_13 ) V_11 > F_14 () -> V_14 . V_15 )
V_3 = F_14 () -> V_14 . V_15 - ( V_13 ) V_11 ;
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
return V_9 ;
}
