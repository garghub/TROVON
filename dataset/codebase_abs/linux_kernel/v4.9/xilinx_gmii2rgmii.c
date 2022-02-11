static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 = 0 ;
V_4 -> V_6 -> V_7 ( V_2 ) ;
V_5 = F_2 ( V_2 -> V_8 . V_9 , V_4 -> V_10 , V_11 ) ;
V_5 &= V_12 ;
if ( V_2 -> V_13 == V_14 )
V_5 |= V_15 ;
else if ( V_2 -> V_13 == V_16 )
V_5 |= V_17 ;
else
V_5 |= V_18 ;
F_3 ( V_2 -> V_8 . V_9 , V_4 -> V_10 , V_11 , V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_20 -> V_22 ;
struct V_23 * V_24 = V_22 -> V_25 , * V_26 ;
struct V_3 * V_4 ;
V_4 = F_5 ( V_22 , sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
V_26 = F_6 ( V_24 , L_1 , 0 ) ;
if ( ! V_26 ) {
F_7 ( V_22 , L_2 ) ;
return - V_29 ;
}
V_4 -> V_30 = F_8 ( V_26 ) ;
F_9 ( V_26 ) ;
if ( ! V_4 -> V_30 ) {
F_10 ( V_22 , L_3 ) ;
return - V_31 ;
}
V_4 -> V_10 = V_20 -> V_10 ;
V_4 -> V_6 = V_4 -> V_30 -> V_32 ;
memcpy ( & V_4 -> V_33 , V_4 -> V_30 -> V_32 ,
sizeof( struct V_34 ) ) ;
V_4 -> V_33 . V_7 = F_1 ;
V_4 -> V_30 -> V_4 = V_4 ;
V_4 -> V_30 -> V_32 = & V_4 -> V_33 ;
return 0 ;
}
