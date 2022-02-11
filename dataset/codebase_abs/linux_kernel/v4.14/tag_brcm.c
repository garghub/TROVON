static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_7 = F_3 ( V_2 ) ;
T_2 * V_8 ;
if ( F_4 ( V_2 , V_9 ) < 0 )
return NULL ;
F_5 ( V_2 , V_9 ) ;
memmove ( V_2 -> V_10 , V_2 -> V_10 + V_9 , 2 * V_11 ) ;
V_8 = V_2 -> V_10 + 2 * V_11 ;
V_8 [ 0 ] = ( 1 << V_12 ) |
( ( V_7 & V_13 ) << V_14 ) ;
V_8 [ 1 ] = 0 ;
V_8 [ 2 ] = 0 ;
if ( V_6 -> V_15 -> V_16 == 8 )
V_8 [ 2 ] = V_17 ;
V_8 [ 3 ] = ( 1 << V_6 -> V_15 -> V_16 ) & V_18 ;
return V_2 ;
}
static struct V_1 * F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = V_4 -> V_23 ;
struct V_24 * V_25 = F_7 ( V_22 ) ;
struct V_26 * V_27 = V_25 -> V_27 ;
int V_28 ;
T_2 * V_8 ;
if ( F_8 ( ! F_9 ( V_2 , V_9 ) ) )
return NULL ;
V_8 = V_2 -> V_10 - 2 ;
if ( F_8 ( ( V_8 [ 0 ] >> V_12 ) & V_29 ) )
return NULL ;
if ( F_8 ( V_8 [ 2 ] & V_30 ) )
return NULL ;
V_28 = V_8 [ 3 ] & V_31 ;
if ( V_28 >= V_27 -> V_32 || ! V_27 -> V_33 [ V_28 ] . V_34 )
return NULL ;
F_10 ( V_2 , V_9 ) ;
memmove ( V_2 -> V_10 - V_35 ,
V_2 -> V_10 - V_35 - V_9 ,
2 * V_11 ) ;
V_2 -> V_4 = V_27 -> V_33 [ V_28 ] . V_34 ;
return V_2 ;
}
