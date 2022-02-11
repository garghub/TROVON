static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 ;
unsigned int V_9 ;
V_8 = F_2 ( V_4 , V_7 ) ;
if ( V_8 ) {
F_3 ( V_10 , V_11 ) ;
F_3 ( V_4 -> V_12 & 0xff , V_13 ) ;
F_3 ( V_14 , V_11 ) ;
F_3 ( ( V_4 -> V_12 >> 8 ) & 0xff , V_13 ) ;
F_3 ( V_15 , V_11 ) ;
V_9 = F_4 ( V_13 ) & 0x0f ;
F_3 ( ( ( V_4 -> V_12 >> 12 ) & 0xf0 ) | V_9 , V_13 ) ;
}
F_3 ( V_10 , V_11 ) ;
V_9 = F_4 ( V_13 ) ;
F_3 ( V_14 , V_11 ) ;
V_9 |= ( F_4 ( V_13 ) << 8 ) ;
F_3 ( V_15 , V_11 ) ;
V_9 |= ( ( F_4 ( V_13 ) & 0xf0 ) << 12 ) ;
V_7 [ 1 ] = V_9 ;
return V_6 -> V_16 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_17 = F_6 ( V_6 -> V_18 ) ;
unsigned int V_8 ;
unsigned int V_9 ;
int V_19 ;
V_19 = F_7 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_19 )
return V_19 ;
if ( V_17 < 8 ) {
V_8 = 1 << V_17 ;
F_3 ( V_20 , V_11 ) ;
} else if ( V_17 < 16 ) {
V_8 = 1 << ( V_17 - 8 ) ;
F_3 ( V_21 , V_11 ) ;
} else {
V_8 = 1 << ( ( V_17 - 16 ) * 2 ) ;
F_3 ( V_22 , V_11 ) ;
}
V_9 = F_4 ( V_13 ) ;
if ( V_7 [ 0 ] == V_23 )
V_9 |= V_8 ;
else
V_9 &= ~ V_8 ;
F_3 ( V_9 , V_13 ) ;
return V_6 -> V_16 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_9 ( V_2 , 1 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_26 [ 0 ] ;
V_4 -> type = V_27 ;
V_4 -> V_28 = V_29 | V_30 ;
V_4 -> V_31 = 20 ;
V_4 -> V_32 = 1 ;
V_4 -> V_33 = & V_34 ;
V_4 -> V_35 = F_1 ;
V_4 -> V_36 = F_5 ;
F_3 ( V_20 , V_11 ) ;
F_3 ( 0x00 , V_13 ) ;
F_3 ( V_21 , V_11 ) ;
F_3 ( 0x00 , V_13 ) ;
F_3 ( V_22 , V_11 ) ;
F_3 ( ( F_4 ( V_13 ) & 0xAA ) , V_13 ) ;
F_10 ( V_2 -> V_37 , L_1 , V_2 -> V_38 ) ;
return 1 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_3 ( V_20 , V_11 ) ;
F_3 ( 0x00 , V_13 ) ;
F_3 ( V_21 , V_11 ) ;
F_3 ( 0x00 , V_13 ) ;
F_3 ( V_22 , V_11 ) ;
F_3 ( ( F_4 ( V_13 ) & 0xAA ) , V_13 ) ;
}
