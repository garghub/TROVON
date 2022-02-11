static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
int V_9 ;
int V_10 = 0 ;
if ( V_6 -> V_11 != 1 )
return - V_12 ;
V_9 = F_2 ( V_6 -> V_13 ) ;
if ( V_9 < 8 )
V_8 = 0xff ;
else if ( V_9 < 16 )
V_8 = 0xff00 ;
else if ( V_9 < 24 )
V_8 = 0xff0000 ;
else
V_8 = 0xff000000 ;
if ( V_7 [ 0 ] )
V_4 -> V_14 |= V_8 ;
else
V_4 -> V_14 &= ~ V_8 ;
if ( V_4 -> V_14 & 0x000000ff )
V_10 |= 0x1 ;
if ( V_4 -> V_14 & 0x0000ff00 )
V_10 |= 0x2 ;
if ( V_4 -> V_14 & 0x00ff0000 )
V_10 |= 0x4 ;
if ( V_4 -> V_14 & 0xff000000 )
V_10 |= 0x8 ;
F_3 ( V_10 , V_2 -> V_15 + V_16 ) ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_17 ;
if ( V_7 [ 0 ] ) {
V_17 = V_4 -> V_18 ;
V_4 -> V_18 &= ~ V_7 [ 0 ] ;
V_4 -> V_18 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
V_17 ^= V_4 -> V_18 ;
V_17 &= V_4 -> V_14 ;
if ( V_17 & 0x000000ff )
F_3 ( V_4 -> V_18 & 0xff , V_2 -> V_15 + V_19 + 0 ) ;
if ( V_17 & 0x0000ff00 )
F_3 ( ( V_4 -> V_18 >> 8 ) & 0xff ,
V_2 -> V_15 + V_19 + 1 ) ;
if ( V_17 & 0x00ff0000 )
F_3 ( ( V_4 -> V_18 >> 16 ) & 0xff ,
V_2 -> V_15 + V_19 + 2 ) ;
if ( V_17 & 0xff000000 )
F_3 ( ( V_4 -> V_18 >> 24 ) & 0xff ,
V_2 -> V_15 + V_19 + 3 ) ;
}
V_7 [ 1 ] = F_5 ( V_2 -> V_15 + V_19 + 0 ) ;
V_7 [ 1 ] |= ( F_5 ( V_2 -> V_15 + V_19 + 1 ) << 8 ) ;
V_7 [ 1 ] |= ( F_5 ( V_2 -> V_15 + V_19 + 2 ) << 16 ) ;
V_7 [ 1 ] |= ( F_5 ( V_2 -> V_15 + V_19 + 3 ) << 24 ) ;
return 2 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_22 ;
struct V_3 * V_4 ;
unsigned long V_15 ;
V_15 = V_21 -> V_23 [ 0 ] ;
F_7 ( V_24 L_1 , V_2 -> V_25 , V_15 ) ;
if ( ! F_8 ( V_15 , V_26 , L_2 ) ) {
F_7 ( L_3 ) ;
return - V_27 ;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_28 = L_2 ;
V_22 = F_9 ( V_2 , 1 ) ;
if ( V_22 < 0 )
return V_22 ;
V_4 = V_2 -> V_29 + 0 ;
V_4 -> V_30 = 32 ;
V_4 -> type = V_31 ;
V_4 -> V_32 = V_33 | V_34 ;
V_4 -> V_35 = & V_36 ;
V_4 -> V_37 = 1 ;
V_4 -> V_38 = F_4 ;
V_4 -> V_39 = F_1 ;
V_4 -> V_18 = 0 ;
F_3 ( 0 , V_2 -> V_15 + V_16 ) ;
F_7 ( V_24 L_4 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 )
F_11 ( V_2 -> V_15 , V_26 ) ;
}
