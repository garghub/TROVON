char F_1 ( T_1 integer , T_2 V_1 )
{
return ( V_2 [ ( integer >> V_1 ) & 0xF ] ) ;
}
T_3 F_2 ( int V_3 )
{
if ( V_3 <= 0x39 ) {
return ( ( T_3 ) ( V_3 - 0x30 ) ) ;
}
if ( V_3 <= 0x46 ) {
return ( ( T_3 ) ( V_3 - 0x37 ) ) ;
}
return ( ( T_3 ) ( V_3 - 0x57 ) ) ;
}
