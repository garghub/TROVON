T_1 F_1 ( T_1 V_1 )
{
return ( F_2 ( V_1 & 0xff ) << 8 ) | F_2 ( V_1 >> 8 ) ;
}
T_2 F_3 ( T_2 V_1 )
{
return ( F_1 ( V_1 & 0xffff ) << 16 ) | F_1 ( V_1 >> 16 ) ;
}
