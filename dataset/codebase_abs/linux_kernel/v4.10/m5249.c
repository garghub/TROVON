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
#if F_2 ( V_8 )
T_2 V_9 ;
F_3 ( V_2 | V_10 | V_4 ,
V_11 ) ;
F_4 ( V_12 , V_13 ) ;
V_9 = F_6 ( F_7 ( V_14 ) ) ;
V_9 &= ~ F_8 ( 0xf , V_14 ) ;
V_9 |= F_8 ( 0x5 , V_14 ) ;
F_9 ( V_9 , F_7 ( V_14 ) ) ;
#endif
}
static void T_1 F_10 ( void )
{
T_2 V_15 ;
V_15 = F_6 ( V_16 ) ;
F_9 ( V_15 | 0x40 , V_16 ) ;
V_15 = F_6 ( V_17 ) ;
F_9 ( V_15 | 0x04000000 , V_17 ) ;
}
void T_1 F_11 ( char * V_18 , int V_19 )
{
V_20 = V_21 ;
#ifdef F_12
F_10 () ;
#endif
F_1 () ;
F_5 () ;
}
static int T_1 F_13 ( void )
{
F_14 ( V_22 , F_15 ( V_22 ) ) ;
return 0 ;
}
