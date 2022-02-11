static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
T_2 V_2 = F_3 ( V_3 ) ;
V_2 |= ( 1 << V_4 ) | ( 1 << V_5 ) | ( 1 << V_6 ) ;
F_4 ( V_2 , V_3 ) ;
F_5 ( V_7 | V_8 | V_9 ,
V_10 + V_11 ) ;
F_6 ( V_12 , V_13 ) ;
#endif
}
static void T_1 F_7 ( void )
{
#if F_2 ( V_14 )
T_2 V_15 ;
F_5 ( V_7 | V_16 | V_9 ,
V_10 + V_17 ) ;
F_6 ( V_18 , V_19 ) ;
V_15 = F_3 ( F_8 ( V_20 ) ) ;
V_15 &= ~ F_9 ( 0xf , V_20 ) ;
V_15 |= F_9 ( 0x5 , V_20 ) ;
F_4 ( V_15 , F_8 ( V_20 ) ) ;
#endif
}
void T_1 F_10 ( char * V_21 , int V_22 )
{
V_23 = V_24 ;
F_1 () ;
F_7 () ;
}
