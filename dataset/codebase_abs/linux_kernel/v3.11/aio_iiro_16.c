static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_2 ( V_4 -> V_8 & 0xff , V_2 -> V_9 + V_10 ) ;
F_2 ( ( V_4 -> V_8 >> 8 ) & 0xff ,
V_2 -> V_9 + V_11 ) ;
}
V_7 [ 1 ] = V_4 -> V_8 ;
return V_6 -> V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = 0 ;
V_7 [ 1 ] |= F_4 ( V_2 -> V_9 + V_13 ) ;
V_7 [ 1 ] |= F_4 ( V_2 -> V_9 + V_14 ) << 8 ;
return V_6 -> V_12 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_6 ( V_2 , V_16 -> V_18 [ 0 ] , V_19 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
V_4 = & V_2 -> V_20 [ 0 ] ;
V_4 -> type = V_21 ;
V_4 -> V_22 = V_23 ;
V_4 -> V_24 = 16 ;
V_4 -> V_25 = 1 ;
V_4 -> V_26 = & V_27 ;
V_4 -> V_28 = F_1 ;
V_4 = & V_2 -> V_20 [ 1 ] ;
V_4 -> type = V_21 ;
V_4 -> V_22 = V_29 ;
V_4 -> V_24 = 16 ;
V_4 -> V_25 = 1 ;
V_4 -> V_26 = & V_27 ;
V_4 -> V_28 = F_3 ;
return 1 ;
}
