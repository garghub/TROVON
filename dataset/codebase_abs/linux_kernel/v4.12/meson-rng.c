static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
* ( V_8 * ) V_3 = F_3 ( V_7 -> V_9 + V_10 ) ;
return sizeof( V_8 ) ;
}
static void F_4 ( void * V_7 )
{
F_5 ( V_7 ) ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_6 * V_7 ;
struct V_15 * V_16 ;
int V_17 ;
V_7 = F_7 ( V_14 , sizeof( * V_7 ) , V_18 ) ;
if ( ! V_7 )
return - V_19 ;
V_7 -> V_12 = V_12 ;
V_16 = F_8 ( V_12 , V_20 , 0 ) ;
V_7 -> V_9 = F_9 ( V_14 , V_16 ) ;
if ( F_10 ( V_7 -> V_9 ) )
return F_11 ( V_7 -> V_9 ) ;
V_7 -> V_21 = F_12 ( V_14 , L_1 ) ;
if ( F_10 ( V_7 -> V_21 ) )
V_7 -> V_21 = NULL ;
if ( V_7 -> V_21 ) {
V_17 = F_13 ( V_7 -> V_21 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_14 ( V_14 , F_4 ,
V_7 -> V_21 ) ;
if ( V_17 )
return V_17 ;
}
V_7 -> V_2 . V_22 = V_12 -> V_22 ;
V_7 -> V_2 . V_23 = F_1 ;
F_15 ( V_12 , V_7 ) ;
return F_16 ( V_14 , & V_7 -> V_2 ) ;
}
