static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! F_2 ( V_2 ) )
return false ;
V_2 -> V_4 = V_3 ;
return true ;
}
int F_3 ( struct V_5 * V_6 )
{
return F_4 ( & V_6 -> V_7 , & V_8 ,
V_9 |
V_10 ) ;
}
void F_5 ( struct V_5 * V_6 )
{
F_6 ( & V_6 -> V_7 ) ;
}
