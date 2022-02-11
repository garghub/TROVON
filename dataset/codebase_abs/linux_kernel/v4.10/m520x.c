static void T_1 F_1 ( void )
{
unsigned V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; ++ V_1 )
F_3 ( V_2 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < F_2 ( V_3 ) ; ++ V_1 )
F_4 ( V_3 [ V_1 ] ) ;
}
static void T_1 F_5 ( void )
{
#if F_6 ( V_4 )
T_2 V_5 ;
F_7 ( 0x3f , V_6 ) ;
V_5 = F_8 ( V_7 ) ;
V_5 &= 0x00ff ;
F_9 ( V_5 , V_7 ) ;
#endif
}
static void T_1 F_10 ( void )
{
#if F_6 ( V_8 )
T_3 V_5 ;
V_5 = F_11 ( V_9 ) ;
V_5 |= 0x0f ;
F_7 ( V_5 , V_9 ) ;
#endif
}
static void T_1 F_12 ( void )
{
T_2 V_5 ;
T_3 V_10 ;
V_5 = F_8 ( V_7 ) ;
V_5 |= V_11 | V_12 ;
V_5 |= V_13 | V_14 ;
F_9 ( V_5 , V_7 ) ;
V_10 = F_11 ( V_9 ) ;
V_10 &= ~ 0x0F ;
V_10 |= V_15 |
V_16 ;
F_7 ( V_10 , V_9 ) ;
}
static void T_1 F_13 ( void )
{
T_3 V_17 ;
V_17 = F_11 ( V_18 ) ;
F_7 ( V_17 | 0xf0 , V_18 ) ;
V_17 = F_11 ( V_9 ) ;
F_7 ( V_17 | 0x0f , V_9 ) ;
}
void T_1 F_14 ( char * V_19 , int V_20 )
{
V_21 = V_22 ;
F_1 () ;
F_12 () ;
F_13 () ;
F_5 () ;
F_10 () ;
}
