static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 ;
V_5 = F_2 ( V_4 , L_1 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) == - V_6 ? - V_7 : F_4 ( V_5 ) ;
V_2 -> V_8 [ 0 ] = V_5 ;
F_5 ( 0x20 , ( 1 << 11 ) | 0xff , V_2 -> V_9 + V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_11 * V_12 , T_1 * V_13 )
{
struct V_5 * V_5 = V_2 -> V_8 [ 0 ] ;
int V_14 ;
if ( V_2 -> V_15 == 1 )
return - V_16 ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
if ( V_2 -> V_5 != V_5 ) {
V_14 = F_7 ( V_5 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_5 = V_5 ;
}
if ( V_13 ) {
T_1 V_17 , V_18 , div ;
V_17 = V_12 -> clock * 1000 ;
V_18 = F_8 ( V_5 , V_17 ) ;
div = F_9 ( V_18 , V_17 ) ;
if ( div < 1 )
div = 1 ;
F_10 ( V_5 , V_18 ) ;
* V_13 = div | V_19 ;
}
return 0 ;
}
