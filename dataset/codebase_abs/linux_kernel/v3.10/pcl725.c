static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_4 -> V_8 , V_2 -> V_9 + V_10 ) ;
}
V_7 [ 1 ] = V_4 -> V_8 ;
return V_6 -> V_11 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_9 + V_12 ) ;
return V_6 -> V_11 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_6 ( V_2 , V_14 -> V_16 [ 0 ] , V_17 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_7 ( V_2 , 2 ) ;
if ( V_15 )
return V_15 ;
V_4 = & V_2 -> V_18 [ 0 ] ;
V_4 -> type = V_19 ;
V_4 -> V_20 = V_21 ;
V_4 -> V_22 = 1 ;
V_4 -> V_23 = 8 ;
V_4 -> V_24 = F_1 ;
V_4 -> V_25 = & V_26 ;
V_4 = & V_2 -> V_18 [ 1 ] ;
V_4 -> type = V_27 ;
V_4 -> V_20 = V_28 ;
V_4 -> V_22 = 1 ;
V_4 -> V_23 = 8 ;
V_4 -> V_24 = F_3 ;
V_4 -> V_25 = & V_26 ;
F_8 ( V_29 L_1 ) ;
return 0 ;
}
