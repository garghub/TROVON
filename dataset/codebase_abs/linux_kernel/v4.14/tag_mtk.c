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
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_4 -> V_18 ;
struct V_19 * V_20 ;
int V_21 ;
T_2 * V_22 , V_23 ;
if ( F_6 ( ! F_7 ( V_2 , V_8 ) ) )
return NULL ;
V_22 = ( T_2 * ) ( V_2 -> V_9 - 2 ) ;
V_23 = F_8 ( * V_22 ) ;
F_9 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_9 - V_24 ,
V_2 -> V_9 - V_24 - V_8 ,
2 * V_10 ) ;
V_20 = V_17 -> V_20 [ 0 ] ;
if ( ! V_20 )
return NULL ;
V_21 = ( V_23 & V_25 ) ;
if ( ! V_20 -> V_26 [ V_21 ] . V_27 )
return NULL ;
V_2 -> V_4 = V_20 -> V_26 [ V_21 ] . V_27 ;
return V_2 ;
}
static int F_10 ( const struct V_1 * V_2 , T_2 * V_28 ,
int * V_29 )
{
* V_29 = 4 ;
* V_28 = ( ( T_2 * ) V_2 -> V_9 ) [ 1 ] ;
return 0 ;
}
