static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 , T_1 * V_5 )
{
struct V_6 V_7 [ 2 ] ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_4 > 1 )
V_3 |= V_10 ;
V_7 [ 0 ] . V_3 = V_9 -> V_3 ;
V_7 [ 0 ] . V_11 = V_9 -> V_11 ;
V_7 [ 0 ] . V_4 = 1 ;
V_7 [ 0 ] . V_12 = & V_3 ;
V_7 [ 1 ] . V_3 = V_9 -> V_3 ;
V_7 [ 1 ] . V_11 = V_9 -> V_11 | V_13 ;
V_7 [ 1 ] . V_4 = V_4 ;
V_7 [ 1 ] . V_12 = V_5 ;
return F_3 ( V_9 -> V_14 , V_7 , 2 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , int V_4 , T_1 * V_5 )
{
T_1 V_15 [ V_4 + 1 ] ;
struct V_6 V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_4 > 1 )
V_3 |= V_10 ;
V_15 [ 0 ] = V_3 ;
memcpy ( & V_15 [ 1 ] , V_5 , V_4 * sizeof( T_1 ) ) ;
V_7 . V_3 = V_9 -> V_3 ;
V_7 . V_11 = V_9 -> V_11 ;
V_7 . V_4 = V_4 + 1 ;
V_7 . V_12 = V_15 ;
return F_3 ( V_9 -> V_14 , & V_7 , 1 ) ;
}
static int F_5 ( struct V_8 * V_9 ,
const struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_20 ;
V_20 = F_6 ( & V_9 -> V_2 , sizeof( * V_19 ) ) ;
if ( ! V_20 )
return - V_21 ;
F_7 ( V_9 , V_20 ) ;
V_19 = F_8 ( V_20 ) ;
V_19 -> V_22 = V_9 -> V_22 ;
V_19 -> V_2 = & V_9 -> V_2 ;
V_19 -> V_23 = V_9 -> V_23 ;
V_19 -> V_24 = & V_25 ;
return F_9 ( V_20 ) ;
}
