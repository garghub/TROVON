static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! F_2 ( V_2 ) )
return false ;
V_2 -> V_4 = V_3 ;
return true ;
}
int F_3 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 ;
V_9 = F_4 ( & V_6 -> V_10 ,
sizeof( struct V_8 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
* V_9 = V_13 ;
return F_5 ( & V_6 -> V_10 ,
V_9 ,
V_14 ) ;
}
