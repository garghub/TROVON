unsigned int F_1 ( T_1 V_1 )
{
unsigned int V_2 ;
unsigned int V_3 ;
unsigned int V_4 ;
unsigned int V_5 ;
if ( F_2 ( V_1 == 0 ) ) {
F_3 ( 1 ) ;
return 0 ;
}
V_2 = F_4 ( V_1 ) - 1 ;
V_4 = V_1 << ( 31 - V_2 ) ;
V_3 = ( V_4 >> 23 ) & 0xff ;
V_5 = ( ( V_4 & 0x7fffff ) *
( ( V_6 [ ( V_3 + 1 ) & 0xff ] -
V_6 [ V_3 ] ) & 0xffff ) ) >> 15 ;
return ( ( V_2 << 24 ) + ( V_6 [ V_3 ] << 8 ) + V_5 ) ;
}
unsigned int F_5 ( T_1 V_1 )
{
T_2 log ;
if ( F_2 ( V_1 == 0 ) ) {
F_3 ( 1 ) ;
return 0 ;
}
log = F_1 ( V_1 ) ;
return ( log * 646456993 ) >> 31 ;
}
