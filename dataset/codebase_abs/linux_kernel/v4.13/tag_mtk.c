static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 ;
if ( F_3 ( V_2 , V_8 ) < 0 )
return NULL ;
F_4 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_9 , V_2 -> V_9 + V_8 , 2 * V_10 ) ;
V_7 = V_2 -> V_9 + 2 * V_10 ;
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = ( 1 << V_6 -> V_11 -> V_12 ) & V_13 ;
V_7 [ 2 ] = 0 ;
V_7 [ 3 ] = 0 ;
return V_2 ;
}
static struct V_1 * F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 ,
struct V_3 * V_16 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
struct V_20 * V_21 ;
int V_22 ;
T_2 * V_23 , V_24 ;
if ( F_6 ( ! F_7 ( V_2 , V_8 ) ) )
return NULL ;
V_23 = ( T_2 * ) ( V_2 -> V_9 - 2 ) ;
V_24 = F_8 ( * V_23 ) ;
F_9 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_9 - V_25 ,
V_2 -> V_9 - V_25 - V_8 ,
2 * V_10 ) ;
V_21 = V_18 -> V_21 [ 0 ] ;
if ( ! V_21 )
return NULL ;
V_22 = ( V_24 & V_26 ) ;
if ( ! V_21 -> V_27 [ V_22 ] . V_28 )
return NULL ;
V_2 -> V_4 = V_21 -> V_27 [ V_22 ] . V_28 ;
return V_2 ;
}
