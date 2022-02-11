void F_1 ( void )
{
void T_1 * V_1 ;
unsigned long V_2 ;
V_1 = V_3 + 0x1e000 + 0x2c4 ;
V_2 = F_2 ( V_1 ) ;
F_3 ( V_2 | ( 1 << 6 ) , V_1 ) ;
F_3 ( V_2 , V_1 ) ;
}
void T_2 F_4 ( void )
{
F_5 () ;
}
static int T_2 F_6 ( void )
{
if ( F_7 () ) {
#ifdef F_8
F_9 ( 0 ) ;
#endif
F_10 ( V_4 ) ;
F_11 ( V_5 ) ;
F_12 ( V_6 , 16 ) ;
F_13 () ;
}
return 0 ;
}
static void T_2 F_14 ( void )
{
unsigned long V_7 ;
F_3 ( V_8 | V_9 , V_10 ) ;
V_7 = V_8 | V_11 | F_15 ( 1 ) ;
F_3 ( V_7 , V_10 ) ;
F_16 ( V_12 ) ;
}
