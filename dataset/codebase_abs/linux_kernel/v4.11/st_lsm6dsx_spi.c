static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
struct V_11 V_12 [] = {
{
. V_13 = V_9 -> V_14 . V_13 ,
. V_15 = 8 ,
. V_4 = 1 ,
} ,
{
. V_16 = V_9 -> V_14 . V_16 ,
. V_15 = 8 ,
. V_4 = V_4 ,
}
} ;
V_9 -> V_14 . V_13 [ 0 ] = V_3 | V_17 ;
V_10 = F_4 ( V_7 , V_12 , F_5 ( V_12 ) ) ;
if ( V_10 < 0 )
return V_10 ;
memcpy ( V_5 , V_9 -> V_14 . V_16 , V_4 * sizeof( T_1 ) ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
T_1 * V_5 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
if ( V_4 >= V_18 )
return - V_19 ;
V_7 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_7 ) ;
V_9 -> V_14 . V_13 [ 0 ] = V_3 ;
memcpy ( & V_9 -> V_14 . V_13 [ 1 ] , V_5 , V_4 ) ;
return F_7 ( V_7 , V_9 -> V_14 . V_13 , V_4 + 1 ) ;
}
static int F_8 ( struct V_6 * V_7 )
{
const struct V_20 * V_21 = F_9 ( V_7 ) ;
return F_10 ( & V_7 -> V_2 , V_7 -> V_22 ,
( int ) V_21 -> V_23 ,
& V_24 ) ;
}
