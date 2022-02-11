struct V_1 * F_1 ( struct V_2 * V_3 )
{
F_2 ( & V_3 -> V_4 ) ;
F_3 ( V_3 -> V_5 ) ;
V_3 -> V_6 |= V_7 ;
return V_3 -> V_5 ;
}
void F_4 ( struct V_2 * V_3 )
{
V_3 -> V_6 &= ~ V_7 ;
F_5 ( V_3 -> V_5 ) ;
F_6 ( & V_3 -> V_4 ) ;
}
