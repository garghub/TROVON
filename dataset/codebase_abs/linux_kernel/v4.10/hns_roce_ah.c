struct V_1 * F_1 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_3 -> V_10 ) ;
struct V_10 * V_11 = & V_9 -> V_12 -> V_11 ;
struct V_13 V_14 ;
struct V_15 * V_16 ;
T_1 V_17 = 0xffff ;
struct V_18 V_19 ;
union V_20 V_21 ;
int V_22 ;
V_16 = F_3 ( sizeof( * V_16 ) , V_23 ) ;
if ( ! V_16 )
return F_4 ( - V_24 ) ;
memcpy ( & V_19 , V_5 -> V_25 . V_26 . V_27 , sizeof( V_5 -> V_25 . V_26 . V_27 ) ) ;
if ( F_5 ( & V_19 ) )
F_6 ( & V_19 , V_16 -> V_28 . V_29 ) ;
else
memcpy ( V_16 -> V_28 . V_29 , V_5 -> V_30 , sizeof( V_5 -> V_30 ) ) ;
V_22 = F_7 ( V_3 -> V_10 , V_5 -> V_31 ,
V_5 -> V_25 . V_32 , & V_21 , & V_14 ) ;
if ( V_22 ) {
F_8 ( V_11 , L_1 , V_22 ) ;
F_9 ( V_16 ) ;
return F_4 ( V_22 ) ;
}
if ( V_14 . V_33 ) {
if ( F_10 ( V_14 . V_33 ) )
V_17 = F_11 ( V_14 . V_33 ) ;
F_12 ( V_14 . V_33 ) ;
}
if ( V_17 < 0x1000 )
V_17 |= ( V_5 -> V_34 & V_35 ) <<
V_36 ;
V_16 -> V_28 . V_37 = F_13 ( F_14 ( V_3 ) -> V_38 | ( V_5 -> V_31 <<
V_39 ) ) ;
V_16 -> V_28 . V_40 = V_5 -> V_25 . V_32 ;
V_16 -> V_28 . V_41 = F_15 ( V_17 ) ;
F_16 ( V_11 , L_2 , V_16 -> V_28 . V_40 ,
V_16 -> V_28 . V_41 ) ;
if ( V_5 -> V_42 )
V_16 -> V_28 . V_43 = V_44 ;
memcpy ( V_16 -> V_28 . V_26 , V_5 -> V_25 . V_26 . V_27 , V_45 ) ;
V_16 -> V_28 . V_46 = F_17 ( V_5 -> V_34 <<
V_47 ) ;
return & V_16 -> V_48 ;
}
int F_18 ( struct V_1 * V_48 , struct V_4 * V_5 )
{
struct V_15 * V_16 = F_19 ( V_48 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_34 = F_20 ( V_16 -> V_28 . V_46 ) >>
V_47 ;
V_5 -> V_31 = F_20 ( V_16 -> V_28 . V_37 ) >>
V_39 ;
V_5 -> V_42 = V_16 -> V_28 . V_43 ;
V_5 -> V_49 = V_50 ;
V_5 -> V_25 . V_51 = F_20 ( V_16 -> V_28 . V_46 ) >>
V_52 ;
V_5 -> V_25 . V_53 = F_20 ( V_16 -> V_28 . V_46 ) &
V_54 ;
V_5 -> V_25 . V_55 = V_16 -> V_28 . V_55 ;
V_5 -> V_25 . V_32 = V_16 -> V_28 . V_40 ;
memcpy ( V_5 -> V_25 . V_26 . V_27 , V_16 -> V_28 . V_26 , V_45 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_16 )
{
F_9 ( F_19 ( V_16 ) ) ;
return 0 ;
}
