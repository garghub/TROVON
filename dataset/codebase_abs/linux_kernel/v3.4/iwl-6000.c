static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) . V_3 = V_4 ;
F_2 ( V_2 ) . V_5 = V_6 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 -> V_7 ) >= 6 )
F_5 ( F_6 ( V_2 ) , V_8 ,
V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 -> V_7 ) >= 6 )
F_5 ( F_6 ( V_2 ) , V_8 ,
V_9 ) ;
F_5 ( F_6 ( V_2 ) , V_8 ,
V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( F_6 ( V_2 ) , V_8 ,
V_11 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
if ( F_12 ( V_2 ) -> V_12 )
F_12 ( V_2 ) -> V_12 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) . V_13 = F_14 ( V_14 ) |
F_14 ( V_15 ) ;
F_2 ( V_2 ) . V_16 =
F_15 ( F_2 ( V_2 ) . V_17 ) ;
if ( F_12 ( V_2 ) -> V_18 )
F_2 ( V_2 ) . V_19 = 1 ;
else
F_2 ( V_2 ) . V_19 =
F_15 ( F_2 ( V_2 ) . V_20 ) ;
F_1 ( V_2 ) ;
F_2 ( V_2 ) . V_21 = & V_22 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_27 [ V_28 ] ;
struct V_29 V_30 ;
const struct V_31 * V_32 ;
T_1 V_33 , V_34 ;
T_2 V_35 ;
T_1 V_36 ;
T_3 V_37 ;
T_2 V_38 = F_17 ( V_26 -> V_39 . V_38 ) ;
struct V_40 * V_41 = V_26 -> V_41 ;
struct V_42 V_43 = {
. V_44 = V_45 ,
. V_46 = { sizeof( V_30 ) , } ,
. V_47 = V_48 ,
. V_49 = { & V_30 , } ,
} ;
V_30 . V_50 = V_2 -> V_50 == V_14 ;
V_35 = V_24 -> V_51 -> V_52 ;
F_18 ( V_2 , L_1 ,
V_26 -> V_53 . V_51 , V_35 ) ;
V_30 . V_51 = F_19 ( V_35 ) ;
V_30 . V_54 = V_26 -> V_55 . V_47 ;
V_30 . V_56 = V_26 -> V_55 . V_57 ;
V_37 = V_24 -> V_58 ;
V_36 = V_24 -> V_59 & 0x0ffffffff ;
if ( ( V_2 -> V_60 > V_36 ) && V_38 ) {
if ( V_37 > ( ( V_2 -> V_60 - V_36 ) /
V_38 ) ) {
V_37 -= ( V_2 -> V_60 -
V_36 ) / V_38 ;
} else
V_37 = 0 ;
}
if ( V_37 <= 1 )
V_30 . V_61 = F_20 ( V_2 -> V_60 ) ;
else {
V_33 =
V_41 -> V_62 . V_63 * V_37 * V_64 ;
V_34 = F_21 ( V_2 ,
V_33 ,
V_38 ) ;
V_30 . V_61 = F_22 ( V_2 ,
V_2 -> V_60 ,
V_34 ,
V_38 ) ;
}
F_18 ( V_2 , L_2 ,
V_30 . V_61 ) ;
V_32 = F_23 ( V_2 , V_2 -> V_50 , V_35 ) ;
if ( V_32 )
V_30 . V_65 = F_24 ( V_32 ) ;
else {
F_25 ( V_2 , L_3 ,
V_26 -> V_53 . V_51 , V_35 ) ;
return - V_66 ;
}
return F_26 ( V_2 , & V_43 ) ;
}
