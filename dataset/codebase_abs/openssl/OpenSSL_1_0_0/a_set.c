static int F_1 ( const void * V_1 , const void * V_2 )
{
const T_1 * V_3 = ( const T_1 * ) V_1 ;
const T_1 * V_4 = ( const T_1 * ) V_2 ;
int V_5 ;
V_5 = memcmp ( V_3 -> V_6 , V_4 -> V_6 ,
V_3 -> V_7 < V_4 -> V_7 ? V_3 -> V_7 : V_4 -> V_7 ) ;
if( V_5 != 0 )
return V_5 ;
return V_3 -> V_7 - V_4 -> V_7 ;
}
