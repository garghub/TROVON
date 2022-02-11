static void T_1 F_1 ( void )
{
F_2 ( V_1 | V_2 | V_3 ,
V_4 + V_5 ) ;
F_3 ( V_6 , V_7 ) ;
}
static void T_1 F_4 ( void )
{
T_2 V_8 ;
V_8 = F_5 ( V_9 + V_10 ) ;
F_6 ( V_8 | 0x40 , V_9 + V_10 ) ;
V_8 = F_5 ( V_9 + V_11 ) ;
F_6 ( V_8 | 0x04000000 , V_9 + V_11 ) ;
}
void T_1 F_7 ( char * V_12 , int V_13 )
{
V_14 = V_15 ;
#ifdef F_8
F_4 () ;
#endif
#if F_9 ( V_16 )
F_1 () ;
#endif
}
static int T_1 F_10 ( void )
{
F_11 ( V_17 , F_12 ( V_17 ) ) ;
return 0 ;
}
