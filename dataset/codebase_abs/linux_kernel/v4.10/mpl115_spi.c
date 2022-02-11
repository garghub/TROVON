static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
V_6 = F_3 ( V_2 , sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
F_4 ( V_4 , V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_6 ( V_4 ) ;
struct V_10 V_11 = {
. V_12 = V_6 -> V_13 ,
. V_14 = V_6 -> V_15 ,
. V_16 = 4 ,
} ;
int V_17 ;
V_6 -> V_13 [ 0 ] = F_7 ( V_9 ) ;
V_6 -> V_13 [ 2 ] = F_7 ( V_9 + 1 ) ;
V_17 = F_8 ( V_4 , & V_11 , 1 ) ;
if ( V_17 )
return V_17 ;
return ( V_6 -> V_15 [ 1 ] << 8 ) | V_6 -> V_15 [ 3 ] ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_6 ( V_4 ) ;
struct V_10 V_11 = {
. V_12 = V_6 -> V_13 ,
. V_16 = 2 ,
} ;
V_6 -> V_13 [ 0 ] = F_10 ( V_9 ) ;
V_6 -> V_13 [ 1 ] = V_18 ;
return F_8 ( V_4 , & V_11 , 1 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
const struct V_19 * V_20 = F_12 ( V_4 ) ;
return F_13 ( & V_4 -> V_2 , V_20 -> V_21 , & V_22 ) ;
}
