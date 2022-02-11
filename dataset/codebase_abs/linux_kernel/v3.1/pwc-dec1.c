int F_1 ( struct V_1 * V_2 , int type , int V_3 , void * V_4 )
{
struct V_5 * V_6 ;
if ( V_2 -> V_7 == NULL ) {
V_6 = F_2 ( sizeof( struct V_5 ) , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_2 -> V_7 = V_6 ;
}
V_6 = V_2 -> V_7 ;
return 0 ;
}
