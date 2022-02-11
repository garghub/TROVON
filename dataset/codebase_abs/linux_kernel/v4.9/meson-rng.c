static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
* ( V_8 * ) V_3 = F_3 ( V_7 -> V_9 + V_10 ) ;
return sizeof( V_8 ) ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_6 * V_7 ;
struct V_15 * V_16 ;
V_7 = F_5 ( V_14 , sizeof( * V_7 ) , V_17 ) ;
if ( ! V_7 )
return - V_18 ;
V_7 -> V_12 = V_12 ;
V_16 = F_6 ( V_12 , V_19 , 0 ) ;
V_7 -> V_9 = F_7 ( V_14 , V_16 ) ;
if ( F_8 ( V_7 -> V_9 ) )
return F_9 ( V_7 -> V_9 ) ;
V_7 -> V_2 . V_20 = V_12 -> V_20 ;
V_7 -> V_2 . V_21 = F_1 ;
F_10 ( V_12 , V_7 ) ;
return F_11 ( V_14 , & V_7 -> V_2 ) ;
}
