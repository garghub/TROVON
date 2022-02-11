static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 [ 2 ] ;
V_9 [ 0 ] . V_3 = V_7 -> V_3 ;
V_9 [ 0 ] . V_10 = V_7 -> V_10 ;
V_9 [ 0 ] . V_4 = 1 ;
V_9 [ 0 ] . V_11 = & V_3 ;
V_9 [ 1 ] . V_3 = V_7 -> V_3 ;
V_9 [ 1 ] . V_10 = V_7 -> V_10 | V_12 ;
V_9 [ 1 ] . V_4 = V_4 ;
V_9 [ 1 ] . V_11 = V_5 ;
return F_3 ( V_7 -> V_13 , V_9 , 2 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , int V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 ;
T_1 V_14 [ V_4 + 1 ] ;
V_14 [ 0 ] = V_3 ;
memcpy ( & V_14 [ 1 ] , V_5 , V_4 * sizeof( T_1 ) ) ;
V_9 . V_3 = V_7 -> V_3 ;
V_9 . V_10 = V_7 -> V_10 ;
V_9 . V_4 = V_4 + 1 ;
V_9 . V_11 = V_14 ;
return F_3 ( V_7 -> V_13 , & V_9 , 1 ) ;
}
static int F_5 ( struct V_6 * V_7 ,
const struct V_15 * V_16 )
{
return F_6 ( & V_7 -> V_2 , V_7 -> V_17 ,
( int ) V_16 -> V_18 , V_16 -> V_19 ,
& V_20 ) ;
}
