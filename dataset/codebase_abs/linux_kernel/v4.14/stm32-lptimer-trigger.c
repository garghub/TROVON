static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_5 & V_6 )
return 0 ;
return - V_7 ;
}
bool F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_8 == & V_9 ) ;
}
static int F_3 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_11 -> V_12 , L_1 , V_11 -> V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_2 -> V_12 . V_15 = V_11 -> V_12 -> V_15 ;
V_2 -> V_8 = & V_9 ;
F_5 ( V_2 , V_11 ) ;
return F_6 ( V_11 -> V_12 , V_2 ) ;
}
static int F_7 ( struct V_16 * V_17 )
{
struct V_10 * V_11 ;
T_1 V_18 ;
int V_19 ;
V_11 = F_8 ( & V_17 -> V_12 , sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 )
return - V_14 ;
if ( F_9 ( V_17 -> V_12 . V_21 , L_2 , & V_18 ) )
return - V_7 ;
if ( V_18 >= F_10 ( V_22 ) )
return - V_7 ;
V_11 -> V_12 = & V_17 -> V_12 ;
V_11 -> V_13 = V_22 [ V_18 ] ;
V_19 = F_3 ( V_11 ) ;
if ( V_19 )
return V_19 ;
F_11 ( V_17 , V_11 ) ;
return 0 ;
}
