static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
F_3 ( 0x07 , V_2 ) ;
#endif
}
static void T_1 F_4 ( void )
{
#if F_2 ( V_3 )
T_2 V_4 ;
V_4 = F_5 ( V_5 ) ;
V_4 |= 0xF ;
F_6 ( V_4 , V_5 ) ;
#endif
}
static void T_1 F_7 ( void )
{
T_3 V_6 ;
V_6 = F_8 ( V_7 ) ;
V_6 |= 0x03 | ( 0x03 << 2 ) ;
F_9 ( V_6 , V_7 ) ;
}
static void T_1 F_10 ( void )
{
T_2 V_8 ;
V_8 = F_5 ( V_5 ) ;
F_6 ( V_8 | 0xf00 , V_5 ) ;
F_9 ( 0xc0 , V_9 ) ;
}
void F_11 ( void )
{
F_9 ( 0 , 0x30000007 ) ;
F_9 ( 0x2 , 0x30000007 ) ;
}
void F_12 ( void )
{
F_13 ( V_10 L_1 ) ;
F_6 ( F_5 ( V_11 ) & ~ ( 1 << ( 5 * 2 ) ) , V_11 ) ;
F_9 ( F_8 ( V_12 ) | ( 1 << 5 ) , V_12 ) ;
F_9 ( F_8 ( V_13 ) & ~ ( 1 << 5 ) , V_13 ) ;
F_9 ( F_8 ( V_13 ) | ( 1 << 5 ) , V_13 ) ;
F_13 ( V_14 L_2 ) ;
}
void T_1 F_14 ( char * V_15 , int V_16 )
{
#ifdef F_15
V_17 = F_11 ;
#endif
#ifdef F_16
V_17 = F_12 ;
#endif
V_18 = V_19 ;
F_7 () ;
F_10 () ;
F_1 () ;
F_4 () ;
}
