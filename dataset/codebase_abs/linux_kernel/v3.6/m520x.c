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
T_2 V_4 ;
F_6 ( 0x3f , V_5 ) ;
V_4 = F_7 ( V_6 ) ;
V_4 &= 0x00ff ;
F_8 ( V_4 , V_6 ) ;
}
static void T_1 F_9 ( void )
{
T_2 V_4 ;
T_3 V_7 ;
V_4 = F_7 ( V_6 ) ;
V_4 |= V_8 | V_9 ;
V_4 |= V_10 | V_11 ;
F_8 ( V_4 , V_6 ) ;
V_7 = F_10 ( V_12 ) ;
V_7 &= ~ 0x0F ;
V_7 |= V_13 |
V_14 ;
F_6 ( V_7 , V_12 ) ;
}
static void T_1 F_11 ( void )
{
T_3 V_15 ;
V_15 = F_10 ( V_16 ) ;
F_6 ( V_15 | 0xf0 , V_16 ) ;
V_15 = F_10 ( V_12 ) ;
F_6 ( V_15 | 0x0f , V_12 ) ;
}
void T_1 F_12 ( char * V_17 , int V_18 )
{
V_19 = V_20 ;
F_1 () ;
F_9 () ;
F_11 () ;
#if F_13 ( V_21 )
F_5 () ;
#endif
}
