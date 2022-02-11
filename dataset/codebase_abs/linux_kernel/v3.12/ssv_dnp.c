static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
F_2 ( V_8 , V_9 ) ;
F_2 ( ( F_3 ( V_10 )
& ~ ( V_11 ) ( V_7 [ 0 ] & 0x0000FF ) )
| ( V_11 ) ( V_7 [ 1 ] & 0x0000FF ) , V_10 ) ;
F_2 ( V_12 , V_9 ) ;
F_2 ( ( F_3 ( V_10 )
& ~ ( V_11 ) ( ( V_7 [ 0 ] & 0x00FF00 ) >> 8 ) )
| ( V_11 ) ( ( V_7 [ 1 ] & 0x00FF00 ) >> 8 ) , V_10 ) ;
F_2 ( V_13 , V_9 ) ;
F_2 ( ( F_3 ( V_10 )
& ~ ( V_11 ) ( ( V_7 [ 0 ] & 0x0F0000 ) >> 12 ) )
| ( V_11 ) ( ( V_7 [ 1 ] & 0x0F0000 ) >> 12 ) , V_10 ) ;
}
F_2 ( V_8 , V_9 ) ;
V_7 [ 0 ] = F_3 ( V_10 ) ;
F_2 ( V_12 , V_9 ) ;
V_7 [ 0 ] += F_3 ( V_10 ) << 8 ;
F_2 ( V_13 , V_9 ) ;
V_7 [ 0 ] += ( ( F_3 ( V_10 ) & 0xF0 ) << 12 ) ;
return V_6 -> V_14 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_15 = F_5 ( V_6 -> V_16 ) ;
unsigned int V_17 ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_6 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_19 )
return V_19 ;
if ( V_15 < 8 ) {
V_17 = 1 << V_15 ;
F_2 ( V_20 , V_9 ) ;
} else if ( V_15 < 16 ) {
V_17 = 1 << ( V_15 - 8 ) ;
F_2 ( V_21 , V_9 ) ;
} else {
V_17 = 1 << ( ( V_15 - 16 ) * 2 ) ;
F_2 ( V_22 , V_9 ) ;
}
V_18 = F_3 ( V_10 ) ;
if ( V_7 [ 0 ] == V_23 )
V_18 |= V_17 ;
else
V_18 &= ~ V_17 ;
F_2 ( V_18 , V_10 ) ;
return V_6 -> V_14 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_8 ( V_2 , 1 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_26 [ 0 ] ;
V_4 -> type = V_27 ;
V_4 -> V_28 = V_29 | V_30 ;
V_4 -> V_31 = 20 ;
V_4 -> V_32 = 1 ;
V_4 -> V_33 = & V_34 ;
V_4 -> V_35 = F_1 ;
V_4 -> V_36 = F_4 ;
F_2 ( V_20 , V_9 ) ;
F_2 ( 0x00 , V_10 ) ;
F_2 ( V_21 , V_9 ) ;
F_2 ( 0x00 , V_10 ) ;
F_2 ( V_22 , V_9 ) ;
F_2 ( ( F_3 ( V_10 ) & 0xAA ) , V_10 ) ;
F_9 ( V_2 -> V_37 , L_1 , V_2 -> V_38 ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_2 ( V_20 , V_9 ) ;
F_2 ( 0x00 , V_10 ) ;
F_2 ( V_21 , V_9 ) ;
F_2 ( 0x00 , V_10 ) ;
F_2 ( V_22 , V_9 ) ;
F_2 ( ( F_3 ( V_10 ) & 0xAA ) , V_10 ) ;
}
