unsigned int T_1 F_1 ( void T_2 * V_1 )
{
unsigned int V_2 = F_2 ( V_1 + V_3 ) ;
return ( V_2 & 0x03 ) + 1 ;
}
void T_1 F_3 ( void T_2 * V_1 )
{
T_3 V_4 ;
V_4 = F_2 ( V_1 + V_5 ) ;
if ( V_4 & 1 )
return;
V_4 |= 1 ;
F_4 ( V_4 , V_1 + V_5 ) ;
F_5 () ;
}
int F_6 ( void T_2 * V_1 , unsigned int V_6 )
{
unsigned int V_7 ;
int V_8 = F_7 () ;
if ( V_6 > 3 || V_6 == 1 || V_8 > 3 )
return - V_9 ;
V_7 = F_8 ( V_1 + V_10 + V_8 ) & ~ 0x03 ;
V_7 |= V_6 ;
F_9 ( V_7 , V_1 + V_10 + V_8 ) ;
return 0 ;
}
