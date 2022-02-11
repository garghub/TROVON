static void T_1 F_1 ( void )
{
F_2 ( V_1 | V_2 | V_3 ,
V_4 ) ;
F_3 ( V_5 , V_6 ) ;
}
static void T_1 F_4 ( void )
{
T_2 V_7 ;
V_7 = F_5 ( V_8 ) ;
F_6 ( V_7 | 0x40 , V_8 ) ;
V_7 = F_5 ( V_9 ) ;
F_6 ( V_7 | 0x04000000 , V_9 ) ;
}
void T_1 F_7 ( char * V_10 , int V_11 )
{
V_12 = V_13 ;
#ifdef F_8
F_4 () ;
#endif
#if F_9 ( V_14 )
F_1 () ;
#endif
}
static int T_1 F_10 ( void )
{
F_11 ( V_15 , F_12 ( V_15 ) ) ;
return 0 ;
}
