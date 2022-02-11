unsigned short F_1 ( unsigned int V_1 )
{
unsigned short V_2 , V_3 , V_4 ;
if ( V_1 > 65535 )
V_1 = 65535 ;
V_4 = V_1 ;
V_2 = 7 ;
if ( V_4 < 128 ) {
while ( V_2 > 0 && V_4 < ( 1 << V_2 ) )
V_2 -- ;
} else {
while ( V_4 > 255 ) {
V_4 >>= 1 ;
V_2 ++ ;
}
}
V_3 = V_1 - ( 1 << V_2 ) ;
if ( V_3 > 0 ) {
if ( V_2 > 8 )
V_3 >>= V_2 - 8 ;
else if ( V_2 < 8 )
V_3 <<= 8 - V_2 ;
V_3 &= 255 ;
}
return ( V_2 << 8 ) | V_3 ;
}
unsigned short F_2 ( struct V_5 * V_6 , unsigned int V_7 )
{
V_7 >>= 3 ;
if ( V_7 < 50 )
V_7 = 50 ;
if ( V_7 & 0xf8000000 ) {
V_7 = ~ 0xf8000000 ;
F_3 ( V_8 L_1 , V_7 ) ;
}
return ( ( V_7 << 9 ) + ( V_6 -> V_9 . V_10 >> 1 ) ) / V_6 -> V_9 . V_10 ;
}
