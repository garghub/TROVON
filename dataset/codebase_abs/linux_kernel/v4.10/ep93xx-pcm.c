static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_6 == F_2 ( V_2 ) ) {
V_2 -> V_7 = V_5 ;
return true ;
}
return false ;
}
int F_3 ( struct V_8 * V_9 )
{
return F_4 ( V_9 ,
& V_10 ,
V_11 |
V_12 ) ;
}
