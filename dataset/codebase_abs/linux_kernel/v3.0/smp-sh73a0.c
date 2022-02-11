static void T_1 * F_1 ( void )
{
return ( void T_1 * ) 0xf0000000 ;
}
static void F_2 ( unsigned long V_1 , unsigned long V_2 )
{
void T_1 * V_3 = F_1 () ;
F_3 ( & V_4 ) ;
V_5 = F_4 ( V_3 + 8 ) ;
V_5 &= ~ V_2 ;
V_5 |= V_1 ;
F_5 ( & V_4 ) ;
F_6 ( V_5 , V_3 + 8 ) ;
}
unsigned int T_2 F_7 ( void )
{
void T_1 * V_3 = F_1 () ;
#ifdef F_8
V_6 = ( void T_1 * ) 0xf0000600 ;
#endif
return F_9 ( V_3 ) ;
}
void T_3 F_10 ( unsigned int V_7 )
{
F_11 ( 0 ) ;
}
int T_3 F_12 ( unsigned int V_7 )
{
F_2 ( 0 , 3 << ( V_7 * 8 ) ) ;
if ( ( ( F_13 ( F_14 ( V_8 ) ) >> ( 4 * V_7 ) ) & 3 ) == 3 )
F_6 ( 1 << V_7 , F_14 ( V_9 ) ) ;
else
F_6 ( 1 << V_7 , F_14 ( V_10 ) ) ;
return 0 ;
}
void T_2 F_15 ( void )
{
F_16 ( F_1 () ) ;
F_6 ( 0 , F_14 ( V_11 ) ) ;
F_6 ( F_17 ( V_12 ) , F_14 ( V_13 ) ) ;
F_2 ( 0 , 3 << ( 0 * 8 ) ) ;
}
