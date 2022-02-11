static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_7 ;
int V_8 ;
T_1 * V_9 ;
V_8 = ( V_2 -> V_10 >= V_11 ) ? 0 : V_11 - V_2 -> V_10 ;
if ( F_3 ( V_2 ) >= V_8 + V_12 ) {
if ( F_4 ( V_2 , V_2 -> V_10 + V_8 , false ) )
return NULL ;
V_7 = V_2 ;
} else {
V_7 = F_5 ( V_13 + V_2 -> V_10 +
V_8 + V_12 , V_14 ) ;
if ( ! V_7 )
return NULL ;
F_6 ( V_7 , V_13 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 ,
F_9 ( V_2 ) - V_2 -> V_15 ) ;
F_10 ( V_7 ,
F_11 ( V_2 ) - V_2 -> V_15 ) ;
F_12 ( V_2 , F_13 ( V_7 , V_2 -> V_10 ) ) ;
if ( F_14 ( V_7 , V_7 -> V_10 + V_8 ) )
return NULL ;
F_15 ( V_2 ) ;
}
V_9 = F_13 ( V_7 , V_12 ) ;
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = 1 << V_6 -> V_16 -> V_17 ;
return V_7 ;
}
static struct V_1 * F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_18 * V_19 ,
struct V_3 * V_20 )
{
struct V_21 * V_22 = V_4 -> V_23 ;
struct V_24 * V_25 = F_17 ( V_22 ) ;
struct V_26 * V_27 = V_25 -> V_27 ;
T_1 * V_9 ;
int V_28 ;
V_9 = F_18 ( V_2 ) - V_29 ;
V_28 = V_9 [ 0 ] & 7 ;
if ( V_28 >= V_27 -> V_30 || ! V_27 -> V_31 [ V_28 ] . V_32 )
return NULL ;
F_19 ( V_2 , V_2 -> V_10 - V_29 ) ;
V_2 -> V_4 = V_27 -> V_31 [ V_28 ] . V_32 ;
return V_2 ;
}
