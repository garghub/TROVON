unsigned int T_1 F_1 ( void T_2 * V_1 )
{
unsigned int V_2 = F_2 ( V_1 + V_3 ) ;
return ( V_2 & 0x03 ) + 1 ;
}
void F_3 ( void T_2 * V_1 )
{
T_3 V_4 ;
#ifdef F_4
if ( ( F_5 () & 0xff0ffff0 ) == 0x410fc090 ) {
V_4 = F_2 ( V_1 + 0x30 ) ;
if ( ! ( V_4 & 1 ) )
F_6 ( V_4 | 0x1 , V_1 + 0x30 ) ;
}
#endif
V_4 = F_2 ( V_1 + V_5 ) ;
if ( V_4 & V_6 )
return;
V_4 |= V_6 ;
if ( ( F_5 () & 0xff0ffff0 ) == 0x410fc090 &&
( F_5 () & 0x00f0000f ) >= 0x00200000 )
V_4 |= V_7 ;
F_6 ( V_4 , V_1 + V_5 ) ;
F_7 () ;
}
int F_8 ( void T_2 * V_1 , unsigned int V_8 )
{
unsigned int V_9 ;
int V_10 = F_9 ( F_10 ( F_11 () ) , 0 ) ;
if ( V_8 > 3 || V_8 == 1 || V_10 > 3 )
return - V_11 ;
V_9 = F_12 ( V_1 + V_12 + V_10 ) & ~ 0x03 ;
V_9 |= V_8 ;
F_13 ( V_9 , V_1 + V_12 + V_10 ) ;
return 0 ;
}
