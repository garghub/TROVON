static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_4 -> V_5 , V_3 ) ;
F_4 ( F_5 ( V_2 ) , V_6 ,
V_7 ,
~ V_7 ) ;
F_6 ( & V_2 -> V_4 -> V_5 , V_3 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
T_2 V_8 , V_9 ;
T_3 * V_10 = ( T_3 * ) F_8 ( V_2 ,
V_11 ) ;
V_8 = F_9 ( V_10 [ 0 ] ) ;
V_9 = F_9 ( V_10 [ 1 ] ) ;
return ( T_1 ) ( V_8 - V_9 / V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
const T_1 V_13 = V_12 ;
T_1 V_14 = ( T_1 ) F_11 ( V_15 ) -
F_7 ( V_2 ) ;
F_12 ( V_2 ) . V_16 = V_14 * V_13 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) . V_16 = V_15 ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( V_17 . V_18 >= V_19 &&
V_17 . V_18 <= V_20 )
V_2 -> V_21 -> V_22 -> V_18 =
V_17 . V_18 ;
F_12 ( V_2 ) . V_23 = V_2 -> V_21 -> V_22 -> V_18 ;
V_2 -> V_24 [ V_25 ] . V_26 = V_27 ;
F_12 ( V_2 ) . V_28 = V_29 ;
F_12 ( V_2 ) . V_30 = V_31 ;
F_12 ( V_2 ) . V_32 = F_15 ( V_33 ) |
F_15 ( V_34 ) ;
F_12 ( V_2 ) . V_35 = F_16 ( V_2 -> V_21 -> V_36 ) ;
F_12 ( V_2 ) . V_37 = F_16 ( V_2 -> V_21 -> V_38 ) ;
F_12 ( V_2 ) . V_36 = V_2 -> V_21 -> V_36 ;
F_12 ( V_2 ) . V_38 = V_2 -> V_21 -> V_38 ;
F_13 ( V_2 ) ;
F_12 ( V_2 ) . V_39 = & V_40 ;
F_12 ( V_2 ) . V_41 =
F_15 ( V_42 ) |
F_15 ( V_43 ) |
F_15 ( V_44 ) |
F_15 ( V_45 ) |
F_15 ( V_46 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
if ( V_17 . V_18 >= V_19 &&
V_17 . V_18 <= V_20 )
V_2 -> V_21 -> V_22 -> V_18 =
V_17 . V_18 ;
F_12 ( V_2 ) . V_23 = V_2 -> V_21 -> V_22 -> V_18 ;
V_2 -> V_24 [ V_25 ] . V_26 = V_27 ;
F_12 ( V_2 ) . V_28 = V_29 ;
F_12 ( V_2 ) . V_30 = V_31 ;
F_12 ( V_2 ) . V_32 = F_15 ( V_33 ) |
F_15 ( V_34 ) ;
F_12 ( V_2 ) . V_35 = F_16 ( V_2 -> V_21 -> V_36 ) ;
F_12 ( V_2 ) . V_37 = F_16 ( V_2 -> V_21 -> V_38 ) ;
F_12 ( V_2 ) . V_36 = V_2 -> V_21 -> V_36 ;
F_12 ( V_2 ) . V_38 = V_2 -> V_21 -> V_38 ;
F_10 ( V_2 ) ;
F_12 ( V_2 ) . V_39 = & V_47 ;
F_12 ( V_2 ) . V_41 =
F_15 ( V_43 ) |
F_15 ( V_44 ) |
F_15 ( V_46 ) ;
if ( V_2 -> V_21 -> V_48 )
F_12 ( V_2 ) . V_41 |= F_15 ( V_49 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_4 V_50 = 0 ;
T_1 V_51 = F_7 ( V_2 ) ;
V_50 = F_19 ( V_2 -> V_52 . V_53 . V_8 ) ;
V_50 = V_50 / V_12 + V_51 ;
V_2 -> V_8 = F_20 ( V_50 ) ;
F_21 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 = & V_2 -> V_24 [ V_25 ] ;
struct V_58 V_59 ;
const struct V_60 * V_61 ;
T_4 V_62 , V_63 ;
T_2 V_64 ;
T_4 V_65 ;
T_5 V_66 ;
T_2 V_67 = F_9 ( V_57 -> V_68 . V_67 ) ;
struct V_69 * V_70 = V_57 -> V_70 ;
struct V_71 V_72 = {
. V_73 = V_74 ,
. V_75 = { sizeof( V_59 ) , } ,
. V_3 = V_76 ,
. V_77 = { & V_59 , } ,
} ;
V_59 . V_78 = V_2 -> V_78 == V_33 ;
V_64 = V_55 -> V_79 -> V_80 ;
F_23 ( V_2 , L_1 ,
V_57 -> V_81 . V_79 , V_64 ) ;
V_59 . V_79 = F_24 ( V_64 ) ;
V_59 . V_82 = V_57 -> V_83 . V_3 ;
V_59 . V_84 = V_57 -> V_83 . V_85 ;
V_66 = V_55 -> V_86 ;
V_65 = V_55 -> V_87 & 0x0ffffffff ;
if ( ( V_2 -> V_88 > V_65 ) && V_67 ) {
if ( V_66 > ( ( V_2 -> V_88 - V_65 ) /
V_67 ) ) {
V_66 -= ( V_2 -> V_88 -
V_65 ) / V_67 ;
} else
V_66 = 0 ;
}
if ( V_66 <= 1 )
V_59 . V_89 = F_25 ( V_2 -> V_88 ) ;
else {
V_62 =
V_70 -> V_90 . V_91 * V_66 * V_92 ;
V_63 = F_26 ( V_2 ,
V_62 ,
V_67 ) ;
V_59 . V_89 = F_27 ( V_2 ,
V_2 -> V_88 ,
V_63 ,
V_67 ) ;
}
F_23 ( V_2 , L_2 ,
V_59 . V_89 ) ;
V_61 = F_28 ( V_2 , V_2 -> V_78 , V_64 ) ;
if ( V_61 )
V_59 . V_93 = F_29 ( V_61 ) ;
else {
F_30 ( V_2 , L_3 ,
V_57 -> V_81 . V_79 , V_64 ) ;
return - V_94 ;
}
return F_31 ( F_32 ( V_2 ) , & V_72 ) ;
}
