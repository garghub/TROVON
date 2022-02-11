static void T_1 F_1 ( void )
{
F_2 ( 0x07 , V_1 ) ;
}
static void T_1 F_3 ( void )
{
T_2 V_2 ;
V_2 = F_4 ( V_3 ) ;
V_2 |= 0x03 | ( 0x03 << 2 ) ;
F_5 ( V_2 , V_4 ) ;
}
static void T_1 F_6 ( void )
{
T_3 V_5 ;
V_5 = F_7 ( V_6 ) ;
F_8 ( V_5 | 0xf00 , V_6 ) ;
F_5 ( 0xc0 , V_7 ) ;
}
void F_9 ( void )
{
F_5 ( 0 , 0x30000007 ) ;
F_5 ( 0x2 , 0x30000007 ) ;
}
void F_10 ( void )
{
F_11 ( V_8 L_1 ) ;
V_9 &= ~ ( 1 << ( 5 * 2 ) ) ;
V_10 |= ( 1 << 5 ) ;
V_11 &= ~ ( 1 << 5 ) ;
V_11 |= ( 1 << 5 ) ;
F_11 ( V_12 L_2 ) ;
}
void T_1 F_12 ( char * V_13 , int V_14 )
{
#ifdef F_13
V_15 = F_9 ;
#endif
#ifdef F_14
V_15 = F_10 ;
#endif
V_16 = V_17 ;
F_3 () ;
F_6 () ;
#if F_15 ( V_18 )
F_1 () ;
#endif
}
