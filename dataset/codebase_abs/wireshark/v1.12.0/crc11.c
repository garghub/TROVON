T_1 F_1 ( const T_2 * V_1 , T_3 V_2 )
{
T_1 V_3 = 0 ;
T_4 V_4 ;
while ( V_2 -- ) {
V_4 = ( ( V_3 >> 3 ) ^ * V_1 ) & 0xff ;
V_3 = ( V_5 [ V_4 ] ^ ( V_3 << 8 ) ) & 0x7ff ;
V_1 ++ ;
}
return V_3 & 0x7ff ;
}
