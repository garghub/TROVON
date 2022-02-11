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
if ( V_4 & 1 )
return;
V_4 |= 1 ;
F_6 ( V_4 , V_1 + V_5 ) ;
F_7 () ;
}
int F_8 ( void T_2 * V_1 , unsigned int V_6 )
{
unsigned int V_7 ;
int V_8 = F_9 ( F_10 ( F_11 () ) , 0 ) ;
if ( V_6 > 3 || V_6 == 1 || V_8 > 3 )
return - V_9 ;
V_7 = F_12 ( V_1 + V_10 + V_8 ) & ~ 0x03 ;
V_7 |= V_6 ;
F_13 ( V_7 , V_1 + V_10 + V_8 ) ;
return 0 ;
}
