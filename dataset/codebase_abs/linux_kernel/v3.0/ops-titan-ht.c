static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , T_1 * V_5 )
{
volatile T_2 V_6 ;
int V_7 ;
V_7 = V_2 -> V_8 ;
V_6 = ( V_7 << 16 ) | ( V_3 << 8 ) | ( V_4 & 0xfc ) | 0x80000000 ;
if ( V_7 != 0 )
V_6 |= 1 ;
* ( volatile V_9 * ) 0xfb0000f0 |= 0x2 ;
F_2 ( 30 ) ;
* ( volatile V_9 * ) 0xfb0006f8 = V_6 ;
* ( V_5 ) = * ( volatile V_9 * ) 0xfb0006fc ;
F_2 ( 30 ) ;
* ( volatile V_9 * ) 0xfb0000f0 |= 0x2 ;
return V_10 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_11 , T_1 * V_5 )
{
T_2 V_12 ;
F_1 ( V_2 , V_3 , V_4 , & V_12 ) ;
V_12 >>= ( ( V_4 & 3 ) << 3 ) ;
V_12 &= ( 0xffffffffU >> ( ( 4 - V_11 ) << 8 ) ) ;
return V_10 ;
}
static inline int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 , T_1 V_5 )
{
volatile T_2 V_6 ;
int V_7 ;
V_7 = V_2 -> V_8 ;
V_6 = ( V_7 << 16 ) | ( V_3 << 8 ) | ( V_4 & 0xfc ) | 0x80000000 ;
if ( V_7 != 0 )
V_6 |= 1 ;
* ( volatile V_9 * ) 0xfb0000f0 |= 0x2 ;
F_2 ( 30 ) ;
* ( volatile V_9 * ) 0xfb0006f8 = V_6 ;
* ( volatile V_9 * ) 0xfb0006fc = V_5 ;
F_2 ( 30 ) ;
* ( volatile V_9 * ) 0xfb0000f0 |= 0x2 ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_11 , T_1 V_5 )
{
T_2 V_13 , V_14 , V_15 ;
F_1 ( V_2 , V_3 , V_4 , & V_14 ) ;
V_13 = V_5 << ( ( V_4 & 3 ) << 3 ) ;
V_15 = ~ ( 0xffffffffU >> ( ( 4 - V_11 ) << 8 ) ) ;
V_14 &= ~ ( V_15 << ( ( V_4 & 3 ) << 8 ) ) ;
F_4 ( V_2 , V_3 , V_4 , V_13 | V_14 ) ;
return V_10 ;
}
