static bool T_1
F_1 ( const struct V_1 * V_2 )
{
T_2 V_3 = F_2 () ;
if ( ( V_3 & V_4 ) != V_2 -> V_5 )
return false ;
V_3 &= V_6 | V_7 ;
return ( V_3 >= V_2 -> V_8 && V_3 <= V_2 -> V_9 ) ;
}
void F_3 ( void )
{
F_4 ( V_10 , L_1 ) ;
}
