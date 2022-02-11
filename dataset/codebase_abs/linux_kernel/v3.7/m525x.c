static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
T_2 V_2 = F_3 ( V_3 ) ;
V_2 |= ( 1 << V_4 ) | ( 1 << V_5 ) | ( 1 << V_6 ) ;
F_4 ( V_2 , V_3 ) ;
F_5 ( V_7 | V_8 | V_9 ,
V_10 ) ;
F_6 ( V_11 , V_12 ) ;
#endif
}
static void T_1 F_7 ( void )
{
#if F_2 ( V_13 )
T_2 V_14 ;
F_5 ( V_7 | V_15 | V_9 ,
V_16 ) ;
F_6 ( V_17 , V_18 ) ;
V_14 = F_3 ( F_8 ( V_19 ) ) ;
V_14 &= ~ F_9 ( 0xf , V_19 ) ;
V_14 |= F_9 ( 0x5 , V_19 ) ;
F_4 ( V_14 , F_8 ( V_19 ) ) ;
#endif
}
void T_1 F_10 ( char * V_20 , int V_21 )
{
V_22 = V_23 ;
F_1 () ;
F_7 () ;
}
