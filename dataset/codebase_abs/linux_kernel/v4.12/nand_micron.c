static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 [ V_7 ] = { V_3 } ;
return V_5 -> V_8 ( V_2 , V_5 , V_9 ,
V_6 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_10 * V_11 = & V_5 -> V_12 ;
struct V_13 * V_14 = ( void * ) V_11 -> V_15 ;
if ( ! V_5 -> V_16 )
return 0 ;
if ( F_4 ( V_11 -> V_17 ) < 1 )
return 0 ;
V_5 -> V_18 = V_14 -> V_19 ;
V_5 -> V_20 = F_1 ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
int V_21 ;
V_21 = F_3 ( V_5 ) ;
if ( V_21 )
return V_21 ;
if ( V_2 -> V_22 == 2048 )
V_5 -> V_23 |= V_24 ;
return 0 ;
}
