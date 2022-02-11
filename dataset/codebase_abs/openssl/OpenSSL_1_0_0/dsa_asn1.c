static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
if( V_1 == V_5 ) {
T_3 * V_6 ;
V_6 = F_2 ( sizeof( T_3 ) ) ;
if ( ! V_6 )
{
F_3 ( V_7 , V_8 ) ;
return 0 ;
}
V_6 -> V_9 = NULL ;
V_6 -> V_10 = NULL ;
* V_2 = ( T_1 * ) V_6 ;
return 2 ;
}
return 1 ;
}
