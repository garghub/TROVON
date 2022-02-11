static void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 = V_2 -> V_9 - V_6 -> V_10 . V_11 -> V_12 ;
return V_6 -> V_10 . V_13 [ V_8 ] + ( ( V_3 << 8 ) | V_4 ) ;
}
static void T_1 * F_2 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 = V_2 -> V_9 - V_6 -> V_10 . V_11 -> V_12 ;
return V_6 -> V_10 . V_13 [ V_8 ] + ( ( V_3 << 12 ) | V_4 ) ;
}
static int F_3 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
const struct V_18 * V_19 ;
struct V_5 * V_6 = F_4 ( V_17 , sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
return - V_21 ;
V_19 = F_5 ( V_22 , V_17 -> V_23 ) ;
V_6 -> V_10 . V_24 = (struct V_25 * ) V_19 -> V_26 ;
return F_6 ( V_15 , V_6 ) ;
}
