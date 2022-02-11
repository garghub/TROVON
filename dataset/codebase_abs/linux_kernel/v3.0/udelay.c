void
F_1 ( int V_1 )
{
int V_2 ;
__asm__ __volatile__(
" rpcc %0\n"
" addl %1,%0,%1\n"
"1: rpcc %0\n"
" subl %1,%0,%0\n"
" bgt %0,1b"
: "=&r" (tmp), "=r" (loops) : "1"(loops));
}
void
F_2 ( unsigned long V_3 )
{
V_3 *= ( ( ( unsigned long ) V_4 << 32 ) / 1000000 ) * V_5 ;
F_1 ( ( long ) V_3 >> 32 ) ;
}
void
F_3 ( unsigned long V_6 )
{
V_6 *= ( ( ( unsigned long ) V_4 << 32 ) / 1000000000 ) * V_5 ;
F_1 ( ( long ) V_6 >> 32 ) ;
}
