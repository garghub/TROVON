void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
F_2 ( V_2 -> V_5 , L_1 , V_6 ) ;
V_4 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
V_4 = V_4 | V_3 ;
F_4 ( V_4 , & V_2 -> V_7 -> V_8 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
F_2 ( V_2 -> V_5 , L_1 , V_6 ) ;
V_4 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
V_4 = V_4 & ~ V_3 ;
F_4 ( V_4 , & V_2 -> V_7 -> V_8 ) ;
}
bool F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
return ( F_3 ( & V_2 -> V_7 -> V_9 ) & V_3 ) > 0 ;
}
