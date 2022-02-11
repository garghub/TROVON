static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 )
{
T_3 * V_4 = ( T_3 * ) * V_2 ;
if( V_1 == V_5 ) {
V_4 -> V_6 = F_2 () ;
if( ! V_4 -> V_6 ) return 0 ;
}
return 1 ;
}
