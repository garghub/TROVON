void T_1 F_1 ( void )
{
F_2 () ;
#ifdef F_3
V_1 . V_2 = V_3 ;
#endif
}
static int T_1 F_4 ( void )
{
if ( F_5 () ) {
#ifdef F_6
F_7 ( 0 ) ;
#endif
F_8 ( V_4 ) ;
F_9 ( V_5 ) ;
F_10 ( V_6 + 0x50000 ,
V_7 + 0x82800 ,
V_6 + 0x15000 ,
V_6 + 0x3b000 ) ;
}
return 0 ;
}
void T_1 F_11 ( void )
{
F_12 ( V_8 | V_9 , V_10 ) ;
F_12 ( V_11 , V_10 ) ;
F_13 ( V_12 ) ;
}
