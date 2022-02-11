static void T_1 F_1 ( void )
{
T_2 V_1 ;
F_2 ( 0x3f , V_2 ) ;
V_1 = F_3 ( V_3 ) ;
V_1 &= 0x00ff ;
F_4 ( V_1 , V_3 ) ;
}
static void T_1 F_5 ( void )
{
T_2 V_1 ;
T_3 V_4 ;
V_1 = F_3 ( V_3 ) ;
V_1 |= V_5 | V_6 ;
V_1 |= V_7 | V_8 ;
F_4 ( V_1 , V_3 ) ;
V_4 = F_6 ( V_9 ) ;
V_4 &= ~ 0x0F ;
V_4 |= V_10 |
V_11 ;
F_2 ( V_4 , V_9 ) ;
}
static void T_1 F_7 ( void )
{
T_3 V_12 ;
V_12 = F_6 ( V_13 ) ;
F_2 ( V_12 | 0xf0 , V_13 ) ;
V_12 = F_6 ( V_9 ) ;
F_2 ( V_12 | 0x0f , V_9 ) ;
}
void T_1 F_8 ( char * V_14 , int V_15 )
{
V_16 = V_17 ;
F_5 () ;
F_7 () ;
#if F_9 ( V_18 )
F_1 () ;
#endif
}
