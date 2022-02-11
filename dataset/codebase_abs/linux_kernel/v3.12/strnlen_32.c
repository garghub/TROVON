T_1 F_1 ( const char * V_1 , T_1 V_2 )
{
const T_2 V_3 = ( T_2 ) V_1 ;
const T_3 * V_4 = ( const T_3 * ) ( V_3 & - 4 ) ;
T_1 V_5 = sizeof( * V_4 ) - ( V_3 & ( sizeof( * V_4 ) - 1 ) ) ;
T_1 V_6 ;
T_3 V_7 , V_8 ;
if ( V_2 == 0 )
return 0 ;
V_7 = * V_4 | ( ( 1 << ( ( V_3 << 3 ) & 31 ) ) - 1 ) ;
while ( ( V_8 = F_2 ( V_7 , 0 ) ) == 0 ) {
if ( V_5 >= V_2 ) {
return V_2 ;
}
V_7 = * ++ V_4 ;
V_5 += sizeof( V_7 ) ;
}
V_6 = ( ( const char * ) V_4 ) + ( F_3 ( V_8 ) >> 3 ) - V_1 ;
return ( V_6 < V_2 ? V_6 : V_2 ) ;
}
