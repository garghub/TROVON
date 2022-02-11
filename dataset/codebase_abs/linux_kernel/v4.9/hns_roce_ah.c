struct V_1 * F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_3 -> V_8 ) ;
struct V_8 * V_9 = & V_7 -> V_10 -> V_9 ;
struct V_11 V_12 ;
struct V_13 * V_14 ;
T_1 V_15 = 0xffff ;
struct V_16 V_17 ;
union V_18 V_19 ;
int V_20 ;
V_14 = F_3 ( sizeof( * V_14 ) , V_21 ) ;
if ( ! V_14 )
return F_4 ( - V_22 ) ;
memcpy ( & V_17 , V_5 -> V_23 . V_24 . V_25 , sizeof( V_5 -> V_23 . V_24 . V_25 ) ) ;
if ( F_5 ( & V_17 ) )
F_6 ( & V_17 , V_14 -> V_26 . V_27 ) ;
else
memcpy ( V_14 -> V_26 . V_27 , V_5 -> V_28 , sizeof( V_5 -> V_28 ) ) ;
V_20 = F_7 ( V_3 -> V_8 , V_5 -> V_29 ,
V_5 -> V_23 . V_30 , & V_19 , & V_12 ) ;
if ( V_20 ) {
F_8 ( V_9 , L_1 , V_20 ) ;
F_9 ( V_14 ) ;
return F_4 ( V_20 ) ;
}
if ( V_12 . V_31 ) {
if ( F_10 ( V_12 . V_31 ) )
V_15 = F_11 ( V_12 . V_31 ) ;
F_12 ( V_12 . V_31 ) ;
}
if ( V_15 < 0x1000 )
V_15 |= ( V_5 -> V_32 & V_33 ) <<
V_34 ;
V_14 -> V_26 . V_35 = F_13 ( F_14 ( V_3 ) -> V_36 | ( V_5 -> V_29 <<
V_37 ) ) ;
V_14 -> V_26 . V_38 = V_5 -> V_23 . V_30 ;
V_14 -> V_26 . V_39 = F_15 ( V_15 ) ;
F_16 ( V_9 , L_2 , V_14 -> V_26 . V_38 ,
V_14 -> V_26 . V_39 ) ;
if ( V_5 -> V_40 )
V_14 -> V_26 . V_41 = V_42 ;
memcpy ( V_14 -> V_26 . V_24 , V_5 -> V_23 . V_24 . V_25 , V_43 ) ;
V_14 -> V_26 . V_44 = F_17 ( V_5 -> V_32 <<
V_45 ) ;
return & V_14 -> V_46 ;
}
int F_18 ( struct V_1 * V_46 , struct V_4 * V_5 )
{
struct V_13 * V_14 = F_19 ( V_46 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_32 = F_20 ( V_14 -> V_26 . V_44 ) >>
V_45 ;
V_5 -> V_29 = F_20 ( V_14 -> V_26 . V_35 ) >>
V_37 ;
V_5 -> V_40 = V_14 -> V_26 . V_41 ;
V_5 -> V_47 = V_48 ;
V_5 -> V_23 . V_49 = F_20 ( V_14 -> V_26 . V_44 ) >>
V_50 ;
V_5 -> V_23 . V_51 = F_20 ( V_14 -> V_26 . V_44 ) &
V_52 ;
V_5 -> V_23 . V_53 = V_14 -> V_26 . V_53 ;
V_5 -> V_23 . V_30 = V_14 -> V_26 . V_38 ;
memcpy ( V_5 -> V_23 . V_24 . V_25 , V_14 -> V_26 . V_24 , V_43 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_14 )
{
F_9 ( F_19 ( V_14 ) ) ;
return 0 ;
}
