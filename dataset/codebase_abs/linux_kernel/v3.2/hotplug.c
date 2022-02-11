static inline void F_1 ( void )
{
unsigned int V_1 ;
F_2 () ;
asm volatile(
" mcr p15, 0, %1, c7, c5, 0\n"
" mcr p15, 0, %1, c7, c10, 4\n"
" mrc p15, 0, %0, c1, c0, 1\n"
" bic %0, %0, #0x20\n"
" mcr p15, 0, %0, c1, c0, 1\n"
" mrc p15, 0, %0, c1, c0, 0\n"
" bic %0, %0, %2\n"
" mcr p15, 0, %0, c1, c0, 0\n"
: "=&r" (v)
: "r" (0), "Ir" (CR_C)
: "cc");
}
static inline void F_3 ( void )
{
unsigned int V_1 ;
asm volatile( "mrc p15, 0, %0, c1, c0, 0\n"
" orr %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 0\n"
" mrc p15, 0, %0, c1, c0, 1\n"
" orr %0, %0, #0x20\n"
" mcr p15, 0, %0, c1, c0, 1\n"
: "=&r" (v)
: "Ir" (CR_C)
: "cc");
}
static inline void F_4 ( unsigned int V_2 , int * V_3 )
{
for (; ; ) {
asm(".word 0xe320f003\n"
:
:
: "memory", "cc");
if ( V_4 == F_5 ( V_2 ) ) {
break;
}
( * V_3 ) ++ ;
}
}
int F_6 ( unsigned int V_2 )
{
return 1 ;
}
void F_7 ( unsigned int V_2 )
{
int V_3 = 0 ;
F_1 () ;
F_4 ( V_2 , & V_3 ) ;
F_3 () ;
if ( V_3 )
F_8 ( L_1 , V_2 , V_3 ) ;
}
int F_9 ( unsigned int V_2 )
{
return V_2 == 0 ? - V_5 : 0 ;
}
