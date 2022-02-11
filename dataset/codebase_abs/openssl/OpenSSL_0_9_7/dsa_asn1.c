static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 )
{
if( V_1 == V_4 ) {
T_3 * V_5 ;
V_5 = F_2 ( sizeof( T_3 ) ) ;
V_5 -> V_6 = NULL ;
V_5 -> V_7 = NULL ;
* V_2 = ( T_1 * ) V_5 ;
if( V_5 ) return 2 ;
F_3 ( V_8 , V_9 ) ;
return 0 ;
}
return 1 ;
}
