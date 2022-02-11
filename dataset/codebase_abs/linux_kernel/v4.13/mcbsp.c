static int F_1 ( struct V_1 * V_1 , bool V_2 )
{
if ( ! V_1 )
return 0 ;
if ( V_2 )
return F_2 ( V_1 ) ;
else
return F_3 ( V_1 ) ;
}
void T_1 F_4 (
struct V_3 * V_4 )
{
if ( ! V_4 )
return;
V_4 -> V_5 = F_1 ;
}
