static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 [ 0 ] = F_2 ( V_4 , L_1 ) ;
if ( F_3 ( V_2 -> V_5 [ 0 ] ) && F_4 ( V_2 -> V_5 [ 0 ] ) == - V_6 )
V_2 -> V_5 [ 0 ] = F_5 ( - V_7 ) ;
return F_6 ( V_2 -> V_5 [ 0 ] ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
F_8 ( 0x20 , ( 1 << 11 ) | 0xff , V_9 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 ,
const struct V_12 * V_13 , T_1 * V_14 )
{
struct V_1 * V_2 = V_9 -> V_15 . V_4 -> V_16 ;
struct V_17 * V_17 = V_2 -> V_5 [ 0 ] ;
int V_18 ;
if ( V_9 -> V_19 == 1 )
return - V_20 ;
if ( F_3 ( V_17 ) )
return F_4 ( V_17 ) ;
if ( V_9 -> V_17 != V_17 ) {
V_18 = F_10 ( V_17 ) ;
if ( V_18 )
return V_18 ;
V_9 -> V_17 = V_17 ;
}
if ( V_14 ) {
T_1 V_21 , V_22 , div ;
V_21 = V_13 -> clock * 1000 ;
V_22 = F_11 ( V_17 , V_21 ) ;
div = F_12 ( V_22 , V_21 ) ;
if ( div < 1 )
div = 1 ;
F_13 ( V_17 , V_22 ) ;
* V_14 = div | V_23 ;
}
return 0 ;
}
