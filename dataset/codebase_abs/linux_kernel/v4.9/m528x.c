static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
F_3 ( 0x07 , V_2 ) ;
#endif
}
static void T_1 F_4 ( void )
{
T_2 V_3 ;
V_3 = F_5 ( V_4 ) ;
V_3 |= 0x03 | ( 0x03 << 2 ) ;
F_6 ( V_3 , V_4 ) ;
}
static void T_1 F_7 ( void )
{
T_3 V_5 ;
V_5 = F_8 ( V_6 ) ;
F_9 ( V_5 | 0xf00 , V_6 ) ;
F_6 ( 0xc0 , V_7 ) ;
}
void F_10 ( void )
{
F_6 ( 0 , 0x30000007 ) ;
F_6 ( 0x2 , 0x30000007 ) ;
}
void F_11 ( void )
{
F_12 ( V_8 L_1 ) ;
F_9 ( F_8 ( V_9 ) & ~ ( 1 << ( 5 * 2 ) ) , V_9 ) ;
F_6 ( F_5 ( V_10 ) | ( 1 << 5 ) , V_10 ) ;
F_6 ( F_5 ( V_11 ) & ~ ( 1 << 5 ) , V_11 ) ;
F_6 ( F_5 ( V_11 ) | ( 1 << 5 ) , V_11 ) ;
F_12 ( V_12 L_2 ) ;
}
void T_1 F_13 ( char * V_13 , int V_14 )
{
#ifdef F_14
V_15 = F_10 ;
#endif
#ifdef F_15
V_15 = F_11 ;
#endif
V_16 = V_17 ;
F_4 () ;
F_7 () ;
F_1 () ;
}
