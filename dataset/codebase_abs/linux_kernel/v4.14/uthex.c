char F_1 ( T_1 integer , T_2 V_1 )
{
T_1 V_2 ;
F_2 ( integer , V_1 , & V_2 ) ;
return ( V_3 [ V_2 & 0xF ] ) ;
}
T_3 F_3 ( char * V_4 , T_4 * V_5 )
{
if ( ! isxdigit ( ( int ) V_4 [ 0 ] ) ||
! isxdigit ( ( int ) V_4 [ 1 ] ) ) {
return ( V_6 ) ;
}
* V_5 =
F_4 ( V_4 [ 1 ] ) |
( F_4 ( V_4 [ 0 ] ) << 4 ) ;
return ( V_7 ) ;
}
T_4 F_4 ( int V_8 )
{
if ( V_8 <= '9' ) {
return ( ( T_4 ) ( V_8 - '0' ) ) ;
}
if ( V_8 <= 'F' ) {
return ( ( T_4 ) ( V_8 - 0x37 ) ) ;
}
return ( ( T_4 ) ( V_8 - 0x57 ) ) ;
}
