static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 = 0 ;
unsigned int V_11 ;
int V_12 ;
if ( V_8 < 8 )
V_11 = 0x000000ff ;
else if ( V_8 < 16 )
V_11 = 0x0000ff00 ;
else if ( V_8 < 24 )
V_11 = 0x00ff0000 ;
else
V_11 = 0xff000000 ;
V_12 = F_3 ( V_2 , V_4 , V_6 , V_7 , V_11 ) ;
if ( V_12 )
return V_12 ;
if ( V_4 -> V_13 & 0x000000ff )
V_10 |= 0x1 ;
if ( V_4 -> V_13 & 0x0000ff00 )
V_10 |= 0x2 ;
if ( V_4 -> V_13 & 0x00ff0000 )
V_10 |= 0x4 ;
if ( V_4 -> V_13 & 0xff000000 )
V_10 |= 0x8 ;
F_4 ( V_10 , V_2 -> V_14 + V_15 ) ;
return V_6 -> V_16 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_17 ;
if ( V_7 [ 0 ] ) {
V_17 = V_4 -> V_18 ;
V_4 -> V_18 &= ~ V_7 [ 0 ] ;
V_4 -> V_18 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
V_17 ^= V_4 -> V_18 ;
V_17 &= V_4 -> V_13 ;
if ( V_17 & 0x000000ff )
F_4 ( V_4 -> V_18 & 0xff , V_2 -> V_14 + V_19 + 0 ) ;
if ( V_17 & 0x0000ff00 )
F_4 ( ( V_4 -> V_18 >> 8 ) & 0xff ,
V_2 -> V_14 + V_19 + 1 ) ;
if ( V_17 & 0x00ff0000 )
F_4 ( ( V_4 -> V_18 >> 16 ) & 0xff ,
V_2 -> V_14 + V_19 + 2 ) ;
if ( V_17 & 0xff000000 )
F_4 ( ( V_4 -> V_18 >> 24 ) & 0xff ,
V_2 -> V_14 + V_19 + 3 ) ;
}
V_7 [ 1 ] = F_6 ( V_2 -> V_14 + V_19 + 0 ) ;
V_7 [ 1 ] |= ( F_6 ( V_2 -> V_14 + V_19 + 1 ) << 8 ) ;
V_7 [ 1 ] |= ( F_6 ( V_2 -> V_14 + V_19 + 2 ) << 16 ) ;
V_7 [ 1 ] |= ( F_6 ( V_2 -> V_14 + V_19 + 3 ) << 24 ) ;
return V_6 -> V_16 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_12 ;
struct V_3 * V_4 ;
V_12 = F_8 ( V_2 , V_21 -> V_22 [ 0 ] , V_23 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_9 ( V_2 , 1 ) ;
if ( V_12 )
return V_12 ;
V_4 = & V_2 -> V_24 [ 0 ] ;
V_4 -> V_25 = 32 ;
V_4 -> type = V_26 ;
V_4 -> V_27 = V_28 | V_29 ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_32 = 1 ;
V_4 -> V_33 = F_5 ;
V_4 -> V_34 = F_1 ;
V_4 -> V_18 = 0 ;
F_4 ( 0 , V_2 -> V_14 + V_15 ) ;
return 0 ;
}
