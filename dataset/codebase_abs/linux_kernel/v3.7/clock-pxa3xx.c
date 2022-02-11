unsigned int F_1 ( int V_1 )
{
unsigned long V_2 , V_3 ;
unsigned int V_4 , V_5 , V_6 , V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
V_4 = V_3 & 0x1 ;
V_2 = V_13 ;
V_5 = V_2 & 0x1f ;
V_6 = ( V_2 >> 8 ) & 0x7 ;
V_7 = ( V_2 >> 14 ) & 0x3 ;
V_9 = V_5 * V_14 ;
V_10 = V_6 * V_9 ;
V_8 = V_2 & V_15 ;
V_11 = ( V_8 ) ? V_16 : ( ( V_4 ) ? V_10 : V_9 ) ;
V_12 = ( V_8 ) ? V_16 : V_17 [ V_7 ] * V_14 ;
if ( V_1 ) {
F_2 ( L_1 ,
V_16 / 1000000 , ( V_16 % 1000000 ) / 10000 ,
( V_8 ) ? L_2 : L_3 ) ;
F_2 ( L_4 ,
V_9 / 1000000 , ( V_9 % 1000000 ) / 10000 , V_5 ) ;
F_2 ( L_5 ,
V_10 / 1000000 , ( V_10 % 1000000 ) / 10000 , V_6 ,
( V_4 ) ? L_2 : L_3 ) ;
F_2 ( L_6 ,
V_12 / 1000000 , ( V_12 % 1000000 ) / 10000 ) ;
}
return V_11 / 1000 ;
}
static unsigned long F_3 ( struct V_18 * V_18 )
{
unsigned long V_19 = 312000000 ;
unsigned long V_20 ;
V_20 = V_21 ;
V_19 /= ( V_20 >> 12 ) & 0x7fff ;
V_19 *= ( V_20 & 0xfff ) ;
return V_19 ;
}
static unsigned long F_4 ( struct V_18 * V_18 )
{
unsigned long V_2 ;
unsigned int V_7 , V_22 ;
V_2 = V_13 ;
V_7 = ( V_2 >> 14 ) & 0x3 ;
V_22 = ( V_2 & V_15 ) ? V_16 : V_17 [ V_7 ] * V_14 ;
return V_22 ;
}
static unsigned long F_5 ( struct V_18 * V_18 )
{
unsigned long V_2 = V_13 ;
unsigned long V_23 = F_6 ( V_24 ) ;
return V_14 * V_25 [ ( V_2 >> 23 ) & 0x7 ] /
V_26 [ ( V_23 >> 16 ) & 0x3 ] ;
}
void F_7 ( struct V_18 * V_18 )
{
unsigned long V_27 = 1ul << ( V_18 -> V_28 & 0x1f ) ;
if ( V_18 -> V_28 < 32 )
V_29 |= V_27 ;
else if ( V_18 -> V_28 < 64 )
V_30 |= V_27 ;
else
V_31 |= V_27 ;
}
void F_8 ( struct V_18 * V_18 )
{
unsigned long V_27 = 1ul << ( V_18 -> V_28 & 0x1f ) ;
if ( V_18 -> V_28 < 32 )
V_29 &= ~ V_27 ;
else if ( V_18 -> V_28 < 64 )
V_30 &= ~ V_27 ;
else
V_31 &= ~ V_27 ;
}
static void F_9 ( struct V_18 * V_18 )
{
V_32 |= V_33 ;
}
static void F_10 ( struct V_18 * V_18 )
{
V_32 &= ~ V_33 ;
}
static int F_11 ( void )
{
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_30 ;
V_34 = V_35 ;
return 0 ;
}
static void F_12 ( void )
{
V_35 = V_34 ;
V_29 = V_28 [ 0 ] ;
V_30 = V_28 [ 1 ] ;
}
