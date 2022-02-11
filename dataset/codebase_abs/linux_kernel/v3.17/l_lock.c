struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_4 & V_5 ) == 0 )
F_2 ( & V_3 -> V_6 ) ;
F_3 ( V_3 -> V_7 ) ;
V_3 -> V_4 |= V_8 ;
return V_3 -> V_7 ;
}
void F_4 ( struct V_2 * V_3 )
{
V_3 -> V_4 &= ~ V_8 ;
F_5 ( V_3 -> V_7 ) ;
if ( ( V_3 -> V_4 & V_5 ) == 0 )
F_6 ( & V_3 -> V_6 ) ;
}
