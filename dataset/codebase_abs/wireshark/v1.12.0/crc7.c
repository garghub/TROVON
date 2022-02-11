T_1 F_1 ( T_1 V_1 , const unsigned char * V_2 , int V_3 )
{
unsigned int V_4 ;
while ( V_3 -- ) {
V_4 = ( ( V_1 >> 0 ) ^ * V_2 ) & 0xff ;
V_1 = ( V_5 [ V_4 ] ^ ( V_1 << ( 8 - 1 ) ) ) & ( 0x7f << 1 ) ;
V_2 ++ ;
}
return V_1 & ( 0x7f << 1 ) ;
}
