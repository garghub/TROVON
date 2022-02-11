static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_6 -> V_12 ) ;
V_7 [ 0 ] = V_9 -> V_13 [ V_11 ] ;
return 1 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 ;
int V_11 ;
int V_15 ;
V_11 = F_2 ( V_6 -> V_12 ) ;
V_9 -> V_13 [ V_11 ] = V_7 [ 0 ] ;
V_15 = V_7 [ 0 ] ;
#ifdef F_4
if ( ( F_5 ( V_6 -> V_12 ) & 0x2 ) == 0 )
V_15 = ~ V_15 ;
#endif
V_14 = ( V_15 << 4 ) & 0xf0 ;
F_6 ( V_14 , V_2 -> V_16 + F_7 ( V_11 ) ) ;
V_14 = ( V_15 >> 4 ) & 0xff ;
F_6 ( V_14 , V_2 -> V_16 + F_8 ( V_11 ) ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
const struct V_19 * V_20 = F_10 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_21 ;
V_21 = F_11 ( V_2 , V_18 -> V_22 [ 0 ] , V_20 -> V_23 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , 1 ) ;
if ( V_21 )
return V_21 ;
V_9 = F_13 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_24 ;
V_4 = & V_2 -> V_25 [ 0 ] ;
V_4 -> type = V_20 -> type ;
V_4 -> V_26 = V_20 -> V_26 ;
V_4 -> V_27 = ( 1 << V_20 -> V_28 ) - 1 ;
V_4 -> V_29 = V_20 -> V_30 ;
V_4 -> V_31 = V_20 -> V_32 ;
V_4 -> V_33 = V_20 -> V_34 ;
V_4 -> V_35 = V_20 -> V_36 ;
if ( V_4 -> type == V_37 || V_4 -> type == V_38 )
V_4 -> V_39 = V_40 ;
return 0 ;
}
