static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 ;
if ( F_3 ( V_2 , V_8 ) < 0 )
return NULL ;
F_4 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_9 , V_2 -> V_9 + V_8 , 2 * V_10 ) ;
V_7 = V_2 -> V_9 + 2 * V_10 ;
V_7 [ 0 ] = ( 1 << V_11 ) |
( ( V_2 -> V_12 << V_13 ) & V_14 ) ;
V_7 [ 1 ] = 0 ;
V_7 [ 2 ] = 0 ;
if ( V_6 -> V_15 -> V_16 == 8 )
V_7 [ 2 ] = V_17 ;
V_7 [ 3 ] = ( 1 << V_6 -> V_15 -> V_16 ) & V_18 ;
return V_2 ;
}
static struct V_1 * F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_19 * V_20 ,
struct V_3 * V_21 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_25 * V_26 = F_6 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_29 ;
T_1 * V_7 ;
if ( F_7 ( ! F_8 ( V_2 , V_8 ) ) )
return NULL ;
V_7 = V_2 -> V_9 - 2 ;
if ( F_7 ( ( V_7 [ 0 ] >> V_11 ) & V_30 ) )
return NULL ;
if ( F_7 ( V_7 [ 2 ] & V_31 ) )
return NULL ;
V_29 = V_7 [ 3 ] & V_32 ;
if ( V_29 >= V_28 -> V_33 || ! V_28 -> V_34 [ V_29 ] . V_35 )
return NULL ;
F_9 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_9 - V_36 ,
V_2 -> V_9 - V_36 - V_8 ,
2 * V_10 ) ;
V_2 -> V_4 = V_28 -> V_34 [ V_29 ] . V_35 ;
return V_2 ;
}
