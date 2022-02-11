static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
F_3 ( V_2 | V_3 | V_4 ,
V_5 ) ;
F_4 ( V_6 , V_7 ) ;
#endif
}
static void T_1 F_5 ( void )
{
T_2 V_8 ;
V_8 = F_6 ( V_9 ) ;
F_7 ( V_8 | 0x40 , V_9 ) ;
V_8 = F_6 ( V_10 ) ;
F_7 ( V_8 | 0x04000000 , V_10 ) ;
}
void T_1 F_8 ( char * V_11 , int V_12 )
{
V_13 = V_14 ;
#ifdef F_9
F_5 () ;
#endif
F_1 () ;
}
static int T_1 F_10 ( void )
{
F_11 ( V_15 , F_12 ( V_15 ) ) ;
return 0 ;
}
