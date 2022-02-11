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
struct V_10 * V_11 ;
V_9 = F_4 ( & V_6 -> V_12 ,
sizeof( struct V_8 ) , V_13 ) ;
* V_9 = V_14 ;
if ( V_7 )
V_9 -> V_15 = V_7 ;
V_11 = F_4 ( & V_6 -> V_12 ,
sizeof( struct V_10 ) , V_13 ) ;
* V_11 = V_16 ;
if ( V_7 )
V_11 -> V_17 = V_7 ;
V_9 -> V_11 = V_11 ;
return F_5 ( & V_6 -> V_12 ,
V_9 ,
V_18 ) ;
}
