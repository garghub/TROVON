static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static enum V_3
F_2 ( struct V_1 * V_2 , bool V_4 )
{
return V_5 ;
}
int F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_14 ;
V_13 = F_5 ( V_7 -> V_15 , sizeof( * V_13 ) , V_16 ) ;
if ( V_13 == NULL )
return - V_17 ;
V_2 = & V_13 -> V_2 ;
V_2 -> V_18 . V_19 = 0 ;
V_2 -> V_18 . V_20 = 0 ;
V_2 -> V_21 = true ;
V_14 = F_6 ( V_7 -> V_22 , V_2 , & V_23 ,
V_24 ) ;
if ( V_14 < 0 )
return V_14 ;
F_7 ( V_2 , & V_25 ) ;
V_2 -> V_26 = V_27 ;
F_8 ( & V_2 -> V_28 ,
V_7 -> V_22 -> V_29 . V_30 , V_27 ) ;
V_14 = F_9 ( V_2 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
