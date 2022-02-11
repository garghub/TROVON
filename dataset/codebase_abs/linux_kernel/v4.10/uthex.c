char F_1 ( T_1 integer , T_2 V_1 )
{
return ( V_2 [ ( integer >> V_1 ) & 0xF ] ) ;
}
T_3 F_2 ( char * V_3 , T_4 * V_4 )
{
if ( ! isxdigit ( ( int ) V_3 [ 0 ] ) ||
! isxdigit ( ( int ) V_3 [ 1 ] ) ) {
return ( V_5 ) ;
}
* V_4 =
F_3 ( V_3 [ 1 ] ) |
( F_3 ( V_3 [ 0 ] ) << 4 ) ;
return ( V_6 ) ;
}
T_4 F_3 ( int V_7 )
{
if ( V_7 <= '9' ) {
return ( ( T_4 ) ( V_7 - '0' ) ) ;
}
if ( V_7 <= 'F' ) {
return ( ( T_4 ) ( V_7 - 0x37 ) ) ;
}
return ( ( T_4 ) ( V_7 - 0x57 ) ) ;
}
