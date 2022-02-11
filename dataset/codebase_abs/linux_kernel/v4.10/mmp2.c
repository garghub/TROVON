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
#ifdef F_6
V_4 . V_5 = V_6 ;
#endif
}
static int T_2 F_7 ( void )
{
if ( F_8 () ) {
#ifdef F_9
F_10 ( 0 ) ;
#endif
F_11 ( V_7 ) ;
F_12 ( V_8 ) ;
F_13 ( V_9 + 0x50000 ,
V_10 + 0x82800 ,
V_9 + 0x15000 ) ;
}
return 0 ;
}
void T_2 F_14 ( void )
{
unsigned long V_11 ;
F_3 ( V_12 | V_13 , V_14 ) ;
V_11 = V_12 | V_15 | F_15 ( 1 ) ;
F_3 ( V_11 , V_14 ) ;
F_16 ( V_16 ) ;
}
