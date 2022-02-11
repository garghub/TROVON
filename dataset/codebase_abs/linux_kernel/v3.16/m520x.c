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
T_2 V_5 ;
T_3 V_8 ;
V_5 = F_8 ( V_7 ) ;
V_5 |= V_9 | V_10 ;
V_5 |= V_11 | V_12 ;
F_9 ( V_5 , V_7 ) ;
V_8 = F_11 ( V_13 ) ;
V_8 &= ~ 0x0F ;
V_8 |= V_14 |
V_15 ;
F_7 ( V_8 , V_13 ) ;
}
static void T_1 F_12 ( void )
{
T_3 V_16 ;
V_16 = F_11 ( V_17 ) ;
F_7 ( V_16 | 0xf0 , V_17 ) ;
V_16 = F_11 ( V_13 ) ;
F_7 ( V_16 | 0x0f , V_13 ) ;
}
void T_1 F_13 ( char * V_18 , int V_19 )
{
V_20 = V_21 ;
F_1 () ;
F_10 () ;
F_12 () ;
F_5 () ;
}
