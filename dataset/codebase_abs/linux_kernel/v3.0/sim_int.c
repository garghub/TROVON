static inline int F_1 ( unsigned long V_1 )
{
__asm__(
" .set push \n"
" .set mips32 \n"
" clz %0, %1 \n"
" .set pop \n"
: "=r" (x)
: "r" (x));
return V_1 ;
}
static inline unsigned int F_2 ( unsigned int V_2 )
{
#if F_3 ( V_3 ) || F_3 ( V_4 )
return - F_1 ( V_2 ) + 31 - V_5 ;
#else
unsigned int V_6 = 7 ;
unsigned int V_7 ;
V_7 = V_8 & 0xf000 ;
V_7 = V_7 < 1 ;
V_7 = V_7 << 2 ;
V_6 = V_6 - V_7 ;
V_8 = V_8 << V_7 ;
V_7 = V_8 & 0xc000 ;
V_7 = V_7 < 1 ;
V_7 = V_7 << 1 ;
V_6 = V_6 - V_7 ;
V_8 = V_8 << V_7 ;
V_7 = V_8 & 0x8000 ;
V_7 = V_7 < 1 ;
V_6 = V_6 - V_7 ;
return V_6 ;
#endif
}
T_1 void F_4 ( void )
{
unsigned int V_2 = F_5 () & F_6 () & V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 ) ;
if ( V_10 > 0 )
F_7 ( V_11 + V_10 ) ;
else
F_8 () ;
}
void T_2 F_9 ( void )
{
F_10 () ;
}
