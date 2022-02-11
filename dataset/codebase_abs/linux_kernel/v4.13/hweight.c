unsigned int F_1 ( unsigned int V_1 )
{
#ifdef F_2
V_1 -= ( V_1 >> 1 ) & 0x55555555 ;
V_1 = ( V_1 & 0x33333333 ) + ( ( V_1 >> 2 ) & 0x33333333 ) ;
V_1 = ( V_1 + ( V_1 >> 4 ) ) & 0x0f0f0f0f ;
return ( V_1 * 0x01010101 ) >> 24 ;
#else
unsigned int V_2 = V_1 - ( ( V_1 >> 1 ) & 0x55555555 ) ;
V_2 = ( V_2 & 0x33333333 ) + ( ( V_2 >> 2 ) & 0x33333333 ) ;
V_2 = ( V_2 + ( V_2 >> 4 ) ) & 0x0F0F0F0F ;
V_2 = V_2 + ( V_2 >> 8 ) ;
return ( V_2 + ( V_2 >> 16 ) ) & 0x000000FF ;
#endif
}
unsigned int F_3 ( unsigned int V_1 )
{
unsigned int V_2 = V_1 - ( ( V_1 >> 1 ) & 0x5555 ) ;
V_2 = ( V_2 & 0x3333 ) + ( ( V_2 >> 2 ) & 0x3333 ) ;
V_2 = ( V_2 + ( V_2 >> 4 ) ) & 0x0F0F ;
return ( V_2 + ( V_2 >> 8 ) ) & 0x00FF ;
}
unsigned int F_4 ( unsigned int V_1 )
{
unsigned int V_2 = V_1 - ( ( V_1 >> 1 ) & 0x55 ) ;
V_2 = ( V_2 & 0x33 ) + ( ( V_2 >> 2 ) & 0x33 ) ;
return ( V_2 + ( V_2 >> 4 ) ) & 0x0F ;
}
unsigned long F_5 ( T_1 V_1 )
{
#if V_3 == 32
return F_1 ( ( unsigned int ) ( V_1 >> 32 ) ) +
F_1 ( ( unsigned int ) V_1 ) ;
#elif V_3 == 64
#ifdef F_2
V_1 -= ( V_1 >> 1 ) & 0x5555555555555555ul ;
V_1 = ( V_1 & 0x3333333333333333ul ) + ( ( V_1 >> 2 ) & 0x3333333333333333ul ) ;
V_1 = ( V_1 + ( V_1 >> 4 ) ) & 0x0f0f0f0f0f0f0f0ful ;
return ( V_1 * 0x0101010101010101ul ) >> 56 ;
#else
T_1 V_2 = V_1 - ( ( V_1 >> 1 ) & 0x5555555555555555ul ) ;
V_2 = ( V_2 & 0x3333333333333333ul ) + ( ( V_2 >> 2 ) & 0x3333333333333333ul ) ;
V_2 = ( V_2 + ( V_2 >> 4 ) ) & 0x0F0F0F0F0F0F0F0Ful ;
V_2 = V_2 + ( V_2 >> 8 ) ;
V_2 = V_2 + ( V_2 >> 16 ) ;
return ( V_2 + ( V_2 >> 32 ) ) & 0x00000000000000FFul ;
#endif
#endif
}
