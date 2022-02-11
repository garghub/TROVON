int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( V_4 ) {
V_2 -> V_5 = V_4 -> V_4 ;
return 1 ;
}
return 0 ;
}
