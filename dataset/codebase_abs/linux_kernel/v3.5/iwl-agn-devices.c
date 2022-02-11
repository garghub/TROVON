static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 ;
V_2 -> V_3 . V_6 = V_7 ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_8 , V_9 ,
V_10 |
V_11 ) ;
F_4 ( V_2 -> V_8 , V_12 ,
V_13 ,
~ V_14 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 ,
T_2 V_15 )
{
return ( 1 << V_15 ) - 1 ;
}
static inline T_1 F_6 ( struct V_1 * V_2 ,
T_2 V_15 )
{
return ( ( 1 << ( 32 - V_15 ) ) - 1 ) << V_15 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_16 ,
T_1 V_17 )
{
T_1 V_18 ;
T_1 V_19 ;
T_1 V_20 = V_17 * V_21 ;
if ( ! V_20 || ! V_16 )
return 0 ;
V_18 = ( V_16 / V_20 ) &
( F_6 ( V_2 , V_22 ) >>
V_22 ) ;
V_19 = ( V_16 % V_20 ) & F_5 ( V_2 ,
V_22 ) ;
return ( V_18 << V_22 ) + V_19 ;
}
static T_3 F_8 ( struct V_1 * V_2 , T_1 V_23 ,
T_1 V_24 , T_1 V_17 )
{
T_1 V_25 = V_23 & F_5 ( V_2 ,
V_22 ) ;
T_1 V_26 = V_24 & F_5 ( V_2 ,
V_22 ) ;
T_1 V_20 = V_17 * V_21 ;
T_1 V_27 = ( V_23 & F_6 ( V_2 ,
V_22 ) ) +
( V_24 & F_6 ( V_2 ,
V_22 ) ) ;
if ( V_25 > V_26 )
V_27 += V_25 - V_26 ;
else if ( V_25 < V_26 ) {
V_27 += V_20 + V_25 - V_26 ;
V_27 += ( 1 << V_22 ) ;
} else
V_27 += ( 1 << V_22 ) ;
return F_9 ( V_27 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_28 = F_11 ( V_29 ) ;
V_2 -> V_3 . V_30 =
F_12 ( V_2 -> V_3 . V_31 ) ;
if ( V_2 -> V_32 -> V_33 )
V_2 -> V_3 . V_34 = 1 ;
else
V_2 -> V_3 . V_34 =
F_12 ( V_2 -> V_3 . V_35 ) ;
F_1 ( V_2 ) ;
V_2 -> V_3 . V_36 = & V_37 ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_38 ;
V_2 -> V_3 . V_6 = V_7 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
F_3 ( V_2 -> V_8 , V_39 ,
V_40 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_28 = F_11 ( V_29 ) ;
V_2 -> V_3 . V_30 =
F_12 ( V_2 -> V_3 . V_31 ) ;
if ( V_2 -> V_32 -> V_33 )
V_2 -> V_3 . V_34 = 1 ;
else
V_2 -> V_3 . V_34 =
F_12 ( V_2 -> V_3 . V_35 ) ;
F_13 ( V_2 ) ;
V_2 -> V_3 . V_36 = & V_41 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
F_4 ( V_2 -> V_8 , V_42 ,
V_43 ,
~ V_43 ) ;
}
static T_4 F_18 ( struct V_1 * V_2 )
{
T_2 V_44 , V_45 ;
T_5 * V_46 = ( T_5 * ) F_19 ( V_2 ,
V_47 ) ;
V_44 = F_20 ( V_46 [ 0 ] ) ;
V_45 = F_20 ( V_46 [ 1 ] ) ;
return ( T_4 ) ( V_44 -
V_45 / V_48 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
const T_4 V_49 = V_48 ;
T_4 V_50 = ( T_4 ) F_22 ( V_5 ) -
F_18 ( V_2 ) ;
V_2 -> V_3 . V_4 = V_50 * V_49 ;
}
static void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 ;
}
static void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_28 = F_11 ( V_29 ) |
F_11 ( V_51 ) ;
V_2 -> V_3 . V_30 =
F_12 ( V_2 -> V_3 . V_31 ) ;
V_2 -> V_3 . V_34 =
F_12 ( V_2 -> V_3 . V_35 ) ;
F_23 ( V_2 ) ;
V_2 -> V_3 . V_36 = & V_52 ;
}
static void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_28 = F_11 ( V_29 ) |
F_11 ( V_51 ) ;
V_2 -> V_3 . V_30 =
F_12 ( V_2 -> V_3 . V_31 ) ;
V_2 -> V_3 . V_34 =
F_12 ( V_2 -> V_3 . V_35 ) ;
F_21 ( V_2 ) ;
V_2 -> V_3 . V_36 = & V_53 ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_54 = 0 ;
T_4 V_55 = F_18 ( V_2 ) ;
V_54 = F_27 ( V_2 -> V_56 . V_57 . V_44 ) ;
V_54 = V_54 / V_48 + V_55 ;
V_2 -> V_44 = F_28 ( V_54 ) ;
F_29 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = & V_2 -> V_62 [ V_63 ] ;
struct V_64 V_65 ;
const struct V_66 * V_67 ;
T_1 V_68 , V_69 ;
T_2 V_70 ;
T_1 V_71 ;
T_6 V_72 ;
T_2 V_17 = F_20 ( V_61 -> V_73 . V_17 ) ;
struct V_74 * V_75 = V_61 -> V_75 ;
struct V_76 V_77 = {
. V_78 = V_79 ,
. V_80 = { sizeof( V_65 ) , } ,
. V_81 = V_82 ,
. V_83 = { & V_65 , } ,
} ;
V_65 . V_84 = V_2 -> V_84 == V_29 ;
V_70 = V_59 -> V_85 -> V_86 ;
F_31 ( V_2 , L_1 ,
V_61 -> V_87 . V_85 , V_70 ) ;
V_65 . V_85 = F_32 ( V_70 ) ;
V_65 . V_88 = V_61 -> V_89 . V_81 ;
V_65 . V_90 = V_61 -> V_89 . V_91 ;
V_72 = V_59 -> V_92 ;
V_71 = V_59 -> V_93 & 0x0ffffffff ;
if ( ( V_2 -> V_94 > V_71 ) && V_17 ) {
if ( V_72 > ( ( V_2 -> V_94 - V_71 ) /
V_17 ) ) {
V_72 -= ( V_2 -> V_94 -
V_71 ) / V_17 ;
} else
V_72 = 0 ;
}
if ( V_72 <= 1 )
V_65 . V_95 = F_9 ( V_2 -> V_94 ) ;
else {
V_68 =
V_75 -> V_96 . V_97 * V_72 * V_21 ;
V_69 = F_7 ( V_2 ,
V_68 ,
V_17 ) ;
V_65 . V_95 = F_8 ( V_2 ,
V_2 -> V_94 ,
V_69 ,
V_17 ) ;
}
F_31 ( V_2 , L_2 ,
V_65 . V_95 ) ;
V_67 = F_33 ( V_2 , V_2 -> V_84 , V_70 ) ;
if ( V_67 )
V_65 . V_98 = F_34 ( V_67 ) ;
else {
F_35 ( V_2 , L_3 ,
V_61 -> V_87 . V_85 , V_70 ) ;
return - V_99 ;
}
return F_36 ( V_2 , & V_77 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_38 ;
V_2 -> V_3 . V_6 = V_7 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
switch ( V_2 -> V_32 -> V_100 ) {
case V_101 :
case V_102 :
case V_103 :
break;
case V_104 :
F_39 ( V_2 -> V_8 , V_39 ,
V_105 ) ;
break;
case V_106 :
if ( F_40 ( V_2 ) >= 6 )
F_3 ( V_2 -> V_8 , V_39 ,
V_107 ) ;
break;
case V_108 :
if ( F_40 ( V_2 ) >= 6 )
F_3 ( V_2 -> V_8 , V_39 ,
V_107 ) ;
F_3 ( V_2 -> V_8 , V_39 ,
V_109 ) ;
break;
default:
F_41 ( 1 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_28 = F_11 ( V_29 ) |
F_11 ( V_51 ) ;
V_2 -> V_3 . V_30 =
F_12 ( V_2 -> V_3 . V_31 ) ;
if ( V_2 -> V_32 -> V_33 )
V_2 -> V_3 . V_34 = 1 ;
else
V_2 -> V_3 . V_34 =
F_12 ( V_2 -> V_3 . V_35 ) ;
F_37 ( V_2 ) ;
V_2 -> V_3 . V_36 = & V_110 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = & V_2 -> V_62 [ V_63 ] ;
struct V_111 V_65 ;
const struct V_66 * V_67 ;
T_1 V_68 , V_69 ;
T_2 V_70 ;
T_1 V_71 ;
T_6 V_72 ;
T_2 V_17 = F_20 ( V_61 -> V_73 . V_17 ) ;
struct V_74 * V_75 = V_61 -> V_75 ;
struct V_76 V_77 = {
. V_78 = V_79 ,
. V_80 = { sizeof( V_65 ) , } ,
. V_81 = V_82 ,
. V_83 = { & V_65 , } ,
} ;
V_65 . V_84 = V_2 -> V_84 == V_29 ;
V_70 = V_59 -> V_85 -> V_86 ;
F_31 ( V_2 , L_4 ,
V_61 -> V_87 . V_85 , V_70 ) ;
V_65 . V_85 = F_32 ( V_70 ) ;
V_65 . V_88 = V_61 -> V_89 . V_81 ;
V_65 . V_90 = V_61 -> V_89 . V_91 ;
V_72 = V_59 -> V_92 ;
V_71 = V_59 -> V_93 & 0x0ffffffff ;
if ( ( V_2 -> V_94 > V_71 ) && V_17 ) {
if ( V_72 > ( ( V_2 -> V_94 - V_71 ) /
V_17 ) ) {
V_72 -= ( V_2 -> V_94 -
V_71 ) / V_17 ;
} else
V_72 = 0 ;
}
if ( V_72 <= 1 )
V_65 . V_95 = F_9 ( V_2 -> V_94 ) ;
else {
V_68 =
V_75 -> V_96 . V_97 * V_72 * V_21 ;
V_69 = F_7 ( V_2 ,
V_68 ,
V_17 ) ;
V_65 . V_95 = F_8 ( V_2 ,
V_2 -> V_94 ,
V_69 ,
V_17 ) ;
}
F_31 ( V_2 , L_2 ,
V_65 . V_95 ) ;
V_67 = F_33 ( V_2 , V_2 -> V_84 , V_70 ) ;
if ( V_67 )
V_65 . V_98 = F_34 ( V_67 ) ;
else {
F_35 ( V_2 , L_3 ,
V_61 -> V_87 . V_85 , V_70 ) ;
return - V_99 ;
}
return F_36 ( V_2 , & V_77 ) ;
}
