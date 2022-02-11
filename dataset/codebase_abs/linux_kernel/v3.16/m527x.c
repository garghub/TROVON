static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
#if F_3 ( V_2 )
T_2 V_3 ;
F_4 ( 0x1f , V_4 ) ;
V_3 = F_5 ( V_5 ) ;
V_3 &= 0x3f3f ;
F_6 ( V_3 , V_5 ) ;
#elif F_3 ( V_6 )
F_6 ( 0x003e , V_4 ) ;
#endif
#endif
}
static void T_1 F_7 ( void )
{
T_2 V_7 ;
V_7 = F_5 ( V_8 ) ;
V_7 |= V_9 | V_10 | V_11 ;
F_6 ( V_7 , V_8 ) ;
}
static void T_1 F_8 ( void )
{
T_2 V_3 ;
T_3 V_12 ;
#if F_3 ( V_2 )
V_12 = F_9 ( V_13 ) ;
F_4 ( V_12 | 0xf0 , V_13 ) ;
#else
V_3 = F_5 ( V_13 ) ;
F_6 ( V_3 | 0xf00 , V_13 ) ;
V_12 = F_9 ( V_14 ) ;
F_4 ( V_12 | 0xc0 , V_14 ) ;
V_3 = F_5 ( V_13 ) ;
F_6 ( V_3 | 0xa0 , V_13 ) ;
V_12 = F_9 ( V_15 ) ;
F_4 ( V_12 | 0xc0 , V_15 ) ;
#endif
}
void T_1 F_10 ( char * V_16 , int V_17 )
{
V_18 = V_19 ;
F_7 () ;
F_8 () ;
F_1 () ;
}
