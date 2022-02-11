static void T_1 F_1 ( void )
{
F_2 ( 0x07 , V_1 ) ;
}
static void T_1 F_3 ( void )
{
T_2 V_2 ;
V_2 = F_4 ( V_3 ) ;
V_2 |= 0x03 | ( 0x03 << 2 ) ;
F_5 ( V_2 , V_3 ) ;
}
static void T_1 F_6 ( void )
{
T_3 V_4 ;
V_4 = F_7 ( V_5 ) ;
F_8 ( V_4 | 0xf00 , V_5 ) ;
F_5 ( 0xc0 , V_6 ) ;
}
void F_9 ( void )
{
F_5 ( 0 , 0x30000007 ) ;
F_5 ( 0x2 , 0x30000007 ) ;
}
void F_10 ( void )
{
F_11 ( V_7 L_1 ) ;
V_8 &= ~ ( 1 << ( 5 * 2 ) ) ;
V_9 |= ( 1 << 5 ) ;
V_10 &= ~ ( 1 << 5 ) ;
V_10 |= ( 1 << 5 ) ;
F_11 ( V_11 L_2 ) ;
}
void T_1 F_12 ( char * V_12 , int V_13 )
{
#ifdef F_13
V_14 = F_9 ;
#endif
#ifdef F_14
V_14 = F_10 ;
#endif
V_15 = V_16 ;
F_3 () ;
F_6 () ;
#if F_15 ( V_17 )
F_1 () ;
#endif
}
