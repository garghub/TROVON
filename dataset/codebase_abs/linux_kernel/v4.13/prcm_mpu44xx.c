T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( F_3 ( V_1 , V_2 ) ) ;
}
void F_4 ( T_1 V_3 , T_2 V_1 , T_3 V_2 )
{
F_5 ( V_3 , F_3 ( V_1 , V_2 ) ) ;
}
T_1 F_6 ( T_1 V_4 , T_1 V_5 , T_2 V_1 , T_2 V_2 )
{
T_1 V_6 ;
V_6 = F_1 ( V_1 , V_2 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 ;
F_4 ( V_6 , V_1 , V_2 ) ;
return V_6 ;
}
void T_4 F_7 ( void T_5 * V_7 )
{
V_8 . V_9 = V_7 ;
}
