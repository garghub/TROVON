static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! F_2 ( V_2 ) )
return false ;
V_2 -> V_6 = V_5 -> V_7 ;
return true ;
}
int F_3 ( struct V_8 * V_9 )
{
return F_4 ( & V_9 -> V_10 , & V_11 ,
V_12 |
V_13 |
V_14 ) ;
}
void F_5 ( struct V_8 * V_9 )
{
F_6 ( & V_9 -> V_10 ) ;
}
