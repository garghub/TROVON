struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 )
F_2 ( & V_3 -> V_5 ) ;
F_3 ( V_3 -> V_6 ) ;
V_3 -> V_7 = 1 ;
return V_3 -> V_6 ;
}
void F_4 ( struct V_2 * V_3 )
{
V_3 -> V_7 = 0 ;
F_5 ( V_3 -> V_6 ) ;
if ( ! V_3 -> V_4 )
F_6 ( & V_3 -> V_5 ) ;
}
