struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_3 -> V_10 ) ;
struct V_10 * V_11 = & V_9 -> V_12 -> V_11 ;
struct V_13 V_14 ;
struct V_15 * V_16 ;
T_1 V_17 = 0xffff ;
struct V_18 V_19 ;
const struct V_20 * V_21 = F_3 ( V_5 ) ;
union V_22 V_23 ;
int V_24 ;
V_16 = F_4 ( sizeof( * V_16 ) , V_25 ) ;
if ( ! V_16 )
return F_5 ( - V_26 ) ;
memcpy ( & V_19 , V_21 -> V_27 . V_28 , sizeof( V_21 -> V_27 . V_28 ) ) ;
if ( F_6 ( & V_19 ) ) {
F_7 ( & V_19 , V_16 -> V_29 . V_30 ) ;
} else {
T_2 * V_31 = F_8 ( V_5 ) ;
if ( ! V_31 )
return F_5 ( - V_32 ) ;
memcpy ( V_16 -> V_29 . V_30 , V_31 , V_33 ) ;
}
V_24 = F_9 ( V_3 -> V_10 , F_10 ( V_5 ) ,
V_21 -> V_34 , & V_23 , & V_14 ) ;
if ( V_24 ) {
F_11 ( V_11 , L_1 , V_24 ) ;
F_12 ( V_16 ) ;
return F_5 ( V_24 ) ;
}
if ( V_14 . V_35 ) {
if ( F_13 ( V_14 . V_35 ) )
V_17 = F_14 ( V_14 . V_35 ) ;
F_15 ( V_14 . V_35 ) ;
}
if ( V_17 < 0x1000 )
V_17 |= ( F_16 ( V_5 ) &
V_36 ) <<
V_37 ;
V_16 -> V_29 . V_38 = F_17 ( F_18 ( V_3 ) -> V_39 |
( F_10 ( V_5 ) <<
V_40 ) ) ;
V_16 -> V_29 . V_41 = V_21 -> V_34 ;
V_16 -> V_29 . V_42 = F_19 ( V_17 ) ;
F_20 ( V_11 , L_2 , V_16 -> V_29 . V_41 ,
V_16 -> V_29 . V_42 ) ;
if ( F_21 ( V_5 ) )
V_16 -> V_29 . V_43 = V_44 ;
memcpy ( V_16 -> V_29 . V_27 , V_21 -> V_27 . V_28 , V_45 ) ;
V_16 -> V_29 . V_46 = F_22 ( F_16 ( V_5 ) <<
V_47 ) ;
return & V_16 -> V_48 ;
}
int F_23 ( struct V_1 * V_48 , struct V_4 * V_5 )
{
struct V_15 * V_16 = F_24 ( V_48 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_25 ( V_5 , ( F_26 ( V_16 -> V_29 . V_46 ) >>
V_47 ) ) ;
F_27 ( V_5 , ( F_26 ( V_16 -> V_29 . V_38 ) >>
V_40 ) ) ;
F_28 ( V_5 , V_16 -> V_29 . V_43 ) ;
F_29 ( V_5 , NULL ,
( F_26 ( V_16 -> V_29 . V_46 ) &
V_49 ) , V_16 -> V_29 . V_41 ,
V_16 -> V_29 . V_50 ,
( F_26 ( V_16 -> V_29 . V_46 ) >>
V_51 ) ) ;
F_30 ( V_5 , V_16 -> V_29 . V_27 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_16 )
{
F_12 ( F_24 ( V_16 ) ) ;
return 0 ;
}
