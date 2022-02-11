T_1 strlen ( const char * V_1 )
{
const T_2 V_2 = ( T_2 ) V_1 ;
const T_3 * V_3 = ( const T_3 * ) ( V_2 & - 4 ) ;
T_3 V_4 = * V_3 | ( ( 1 << ( V_2 << 3 ) ) - 1 ) ;
T_3 V_5 ;
while ( ( V_5 = F_1 ( V_4 , 0 ) ) == 0 )
V_4 = * ++ V_3 ;
return ( ( const char * ) V_3 ) + ( F_2 ( V_5 ) >> 3 ) - V_1 ;
}
