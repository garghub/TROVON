static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 , T_1 * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_9 = F_3 ( V_8 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_12 V_13 [] = {
{
. V_14 = V_11 -> V_15 . V_14 ,
. V_16 = 8 ,
. V_4 = 1 ,
} ,
{
. V_17 = V_11 -> V_15 . V_17 ,
. V_16 = 8 ,
. V_4 = V_4 ,
}
} ;
if ( V_4 > 1 )
V_3 |= V_18 ;
V_11 -> V_15 . V_14 [ 0 ] = V_3 | V_19 ;
V_6 = F_5 ( V_8 , V_13 , F_6 ( V_13 ) ) ;
if ( V_6 < 0 )
return V_6 ;
memcpy ( V_5 , V_11 -> V_15 . V_17 , V_4 * sizeof( T_1 ) ) ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , int V_4 , T_1 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_9 = F_3 ( V_8 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_12 V_13 = {
. V_14 = V_11 -> V_15 . V_14 ,
. V_16 = 8 ,
. V_4 = V_4 + 1 ,
} ;
if ( V_4 >= V_20 )
return - V_21 ;
if ( V_4 > 1 )
V_3 |= V_18 ;
V_11 -> V_15 . V_14 [ 0 ] = V_3 ;
memcpy ( & V_11 -> V_15 . V_14 [ 1 ] , V_5 , V_4 ) ;
return F_5 ( V_8 , & V_13 , 1 ) ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_10 * V_11 ;
struct V_9 * V_9 ;
V_9 = F_9 ( & V_8 -> V_2 , sizeof( * V_11 ) ) ;
if ( ! V_9 )
return - V_21 ;
F_10 ( V_8 , V_9 ) ;
V_11 = F_4 ( V_9 ) ;
V_11 -> V_22 = V_8 -> V_23 ;
V_11 -> V_2 = & V_8 -> V_2 ;
V_11 -> V_24 = V_8 -> V_24 ;
V_11 -> V_25 = & V_26 ;
return F_11 ( V_9 ) ;
}
