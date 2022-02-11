static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_3 &= V_6 ;
if ( V_3 != V_7 &&
V_3 != V_8 ) {
F_2 ( V_5 -> V_9 , L_1 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_1 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_5 ;
struct V_16 * V_17 = F_4 ( V_5 ) ;
if ( F_5 ( V_17 -> V_18 ) )
F_6 ( V_17 -> V_18 , 1 ) ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_1 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_5 ;
struct V_16 * V_17 = F_4 ( V_5 ) ;
if ( F_5 ( V_17 -> V_18 ) )
F_6 ( V_17 -> V_18 , 0 ) ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_9 = & V_20 -> V_9 ;
struct V_16 * V_17 ;
V_17 = F_9 ( V_9 , sizeof( * V_17 ) , V_22 ) ;
if ( ! V_17 )
return - V_23 ;
V_17 -> V_18 = - V_10 ;
F_10 ( V_9 , V_17 ) ;
if ( F_11 ( F_12 ( V_24 ) , V_9 ) )
V_17 -> V_18 = F_13 ( V_9 -> V_25 ,
L_2 , 0 ) ;
if ( F_5 ( V_17 -> V_18 ) )
if ( F_14 ( V_9 , V_17 -> V_18 ,
V_26 ,
L_3 ) )
V_17 -> V_18 = - V_10 ;
return F_15 ( V_9 , & V_27 ,
& V_28 , 1 ) ;
}
static int F_16 ( struct V_19 * V_20 )
{
F_17 ( & V_20 -> V_9 ) ;
return 0 ;
}
