static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
T_2 V_2 ;
F_3 ( 0x1f , V_3 ) ;
V_2 = F_4 ( V_4 ) ;
V_2 &= 0x3f3f ;
F_5 ( V_2 , V_4 ) ;
#elif F_2 ( V_5 )
F_5 ( 0x003e , V_3 ) ;
#endif
}
static void T_1 F_6 ( void )
{
T_2 V_6 ;
V_6 = F_4 ( V_7 ) ;
V_6 |= V_8 | V_9 | V_10 ;
F_5 ( V_6 , V_7 ) ;
}
static void T_1 F_7 ( void )
{
T_2 V_2 ;
T_3 V_11 ;
#if F_2 ( V_1 )
V_11 = F_8 ( V_12 ) ;
F_3 ( V_11 | 0xf0 , V_12 ) ;
#else
V_2 = F_4 ( V_12 ) ;
F_5 ( V_2 | 0xf00 , V_12 ) ;
V_11 = F_8 ( V_13 ) ;
F_3 ( V_11 | 0xc0 , V_13 ) ;
V_2 = F_4 ( V_12 ) ;
F_5 ( V_2 | 0xa0 , V_12 ) ;
V_11 = F_8 ( V_14 ) ;
F_3 ( V_11 | 0xc0 , V_14 ) ;
#endif
}
void T_1 F_9 ( char * V_15 , int V_16 )
{
V_17 = V_18 ;
F_6 () ;
F_7 () ;
#if F_10 ( V_19 )
F_1 () ;
#endif
}
