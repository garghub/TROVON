void F_1 ( void T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
T_3 V_4 = F_2 ( V_1 , V_2 ) ;
V_4 |= V_3 ;
F_3 ( V_4 , V_1 , V_2 ) ;
}
void F_4 ( void T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
T_3 V_4 = F_2 ( V_1 , V_2 ) ;
V_4 &= ~ V_3 ;
F_3 ( V_4 , V_1 , V_2 ) ;
}
int F_5 ( void T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
T_3 V_4 = F_2 ( V_1 , V_2 ) ;
return ( V_4 & V_3 ) ? 1 : 0 ;
}
int F_6 ( void T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
T_3 V_4 = F_2 ( V_1 , V_2 ) ;
return ( V_4 & V_3 ) ? 0 : 1 ;
}
