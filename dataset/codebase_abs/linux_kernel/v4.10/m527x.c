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
#if F_2 ( V_7 )
#if F_3 ( V_2 )
T_3 V_3 ;
V_3 = F_8 ( V_8 ) ;
V_3 |= 0x0f ;
F_4 ( V_3 , V_8 ) ;
#elif F_3 ( V_6 )
T_2 V_3 ;
V_3 = F_5 ( V_8 ) ;
V_3 |= 0x0f ;
F_6 ( V_3 , V_8 ) ;
#endif
#endif
}
static void T_1 F_9 ( void )
{
T_2 V_9 ;
V_9 = F_5 ( V_10 ) ;
V_9 |= V_11 | V_12 | V_13 ;
F_6 ( V_9 , V_10 ) ;
}
static void T_1 F_10 ( void )
{
T_3 V_14 ;
#if F_3 ( V_2 )
V_14 = F_8 ( V_8 ) ;
F_4 ( V_14 | 0xf0 , V_8 ) ;
#else
T_2 V_3 ;
V_3 = F_5 ( V_8 ) ;
F_6 ( V_3 | 0xf00 , V_8 ) ;
V_14 = F_8 ( V_15 ) ;
F_4 ( V_14 | 0xc0 , V_15 ) ;
V_3 = F_5 ( V_8 ) ;
F_6 ( V_3 | 0xa0 , V_8 ) ;
V_14 = F_8 ( V_16 ) ;
F_4 ( V_14 | 0xc0 , V_16 ) ;
#endif
}
void T_1 F_11 ( char * V_17 , int V_18 )
{
V_19 = V_20 ;
F_9 () ;
F_10 () ;
F_1 () ;
F_7 () ;
}
