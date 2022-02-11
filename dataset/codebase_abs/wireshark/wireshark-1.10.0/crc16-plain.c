long F_1 ( long V_1 , T_1 V_2 )
{
unsigned int V_3 ;
long V_4 ;
V_4 = V_1 & 0x01 ;
for ( V_3 = 1 ; V_3 < V_2 ; V_3 ++ )
{
V_1 >>= 1 ;
V_4 = ( V_4 << 1 ) | ( V_1 & 0x01 ) ;
}
return V_4 ;
}
T_2 F_2 ( T_2 V_5 , const unsigned char * V_1 , T_1 V_2 )
{
unsigned int V_6 ;
while ( V_2 -- ) {
V_6 = ( V_5 ^ * V_1 ) & 0xff ;
V_5 = ( V_7 [ V_6 ] ^ ( V_5 >> 8 ) ) & 0xffff ;
V_1 ++ ;
}
return V_5 & 0xffff ;
}
T_3 F_3 ( const T_4 * V_1 , T_5 V_2 )
{
T_6 V_6 ;
T_3 V_5 = 0 ;
while ( V_2 -- ) {
V_6 = ( ( V_5 >> 8 ) ^ * V_1 ) & 0xff ;
V_5 = ( V_8 [ V_6 ] ^ ( V_5 << 8 ) ) & 0xffff ;
V_1 ++ ;
}
return V_5 & 0xffff ;
}
