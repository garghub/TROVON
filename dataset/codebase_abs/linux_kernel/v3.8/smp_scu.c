unsigned int T_1 F_1 ( void T_2 * V_1 )
{
unsigned int V_2 = F_2 ( V_1 + V_3 ) ;
return ( V_2 & 0x03 ) + 1 ;
}
void F_3 ( void T_2 * V_1 )
{
T_3 V_4 ;
#ifdef F_4
if ( ( F_5 ( V_5 ) & 0xff0ffff0 ) == 0x410fc090 ) {
V_4 = F_2 ( V_1 + 0x30 ) ;
if ( ! ( V_4 & 1 ) )
F_6 ( V_4 | 0x1 , V_1 + 0x30 ) ;
}
#endif
V_4 = F_2 ( V_1 + V_6 ) ;
if ( V_4 & 1 )
return;
V_4 |= 1 ;
F_6 ( V_4 , V_1 + V_6 ) ;
F_7 () ;
}
int F_8 ( void T_2 * V_1 , unsigned int V_7 )
{
unsigned int V_8 ;
int V_9 = F_9 ( F_10 ( F_11 () ) , 0 ) ;
if ( V_7 > 3 || V_7 == 1 || V_9 > 3 )
return - V_10 ;
V_8 = F_12 ( V_1 + V_11 + V_9 ) & ~ 0x03 ;
V_8 |= V_7 ;
F_13 ( V_8 , V_1 + V_11 + V_9 ) ;
return 0 ;
}
