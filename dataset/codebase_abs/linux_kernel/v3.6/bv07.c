static void F_1 ( void )
{
F_2 () ;
F_3 ( 5 , V_1 ) ;
asm("mcr%? p15, 0, %0, c7, c0, 4" : : "r" (0));
}
void T_1 F_4 ( void )
{
#ifdef F_5
void T_2 * V_2 = F_6 ( V_3 + 0x200 , 4 ) ;
if ( V_2 ) {
F_7 ( F_8 ( V_2 ) | 1 , V_2 ) ;
F_9 ( V_2 ) ;
} else {
F_10 ( V_4 L_1 ) ;
}
#endif
V_1 = F_6 ( V_5 + 0x12 , 2 ) ;
if ( V_1 )
V_6 = & F_1 ;
else
F_10 ( V_4 L_2 ) ;
F_11 () ;
F_12 () ;
F_13 ( V_7 , F_14 ( V_7 ) ) ;
F_15 () ;
}
