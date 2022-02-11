static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 + V_2 -> V_7 . V_8 * V_9 , V_6 ) ;
}
static void F_3 ( struct V_10 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_1 ( V_2 , V_4 , V_11 ,
V_2 -> V_12 . V_13 [ 0 ] + V_2 -> V_14 [ 0 ] ) ;
F_1 ( V_2 , V_4 , V_15 ,
V_2 -> V_12 . V_13 [ 1 ] + V_2 -> V_14 [ 1 ] ) ;
F_1 ( V_2 , V_4 , V_16 ,
V_2 -> V_12 . V_13 [ 2 ] + V_2 -> V_14 [ 1 ] ) ;
}
static void F_5 ( struct V_10 * V_7 ,
struct V_17 * V_18 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_6 ( & V_7 -> V_19 ) ;
const struct V_20 * V_21 = V_2 -> V_21 ;
const struct V_22 * V_23 = & V_2 -> V_23 ;
const struct V_24 * V_25 ;
const struct V_24 * V_26 ;
const struct V_27 * V_28 ;
unsigned int V_29 = 0 ;
unsigned int V_30 = 0 ;
T_1 V_31 ;
T_1 V_32 ;
V_28 = F_7 ( V_2 , V_2 -> V_7 . V_33 ) ;
F_1 ( V_2 , V_4 , V_34 ,
( V_28 -> V_35 << V_36 ) |
( V_28 -> V_37 << V_38 ) ) ;
F_1 ( V_2 , V_4 , V_39 ,
( V_28 -> V_35 << V_40 ) |
( V_28 -> V_37 << V_41 ) ) ;
V_2 -> V_14 [ 0 ] = V_28 -> V_30 * V_23 -> V_42 [ 0 ] . V_43
+ V_28 -> V_29 * V_21 -> V_44 [ 0 ] / 8 ;
V_31 = V_23 -> V_42 [ 0 ] . V_43
<< V_45 ;
if ( V_23 -> V_46 > 1 ) {
V_2 -> V_14 [ 1 ] = V_28 -> V_30 * V_23 -> V_42 [ 1 ] . V_43
+ V_28 -> V_29 * V_21 -> V_44 [ 1 ] / 8 ;
V_31 |= V_23 -> V_42 [ 1 ] . V_43
<< V_47 ;
} else {
V_2 -> V_14 [ 1 ] = 0 ;
}
F_1 ( V_2 , V_4 , V_48 , V_31 ) ;
V_26 = F_8 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_33 ,
V_49 ) ;
V_25 = F_8 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_33 ,
V_50 ) ;
V_32 = V_51
| ( V_21 -> V_52 << V_53 ) ;
if ( V_21 -> V_54 )
V_32 |= V_55 ;
if ( V_21 -> V_56 )
V_32 |= V_57 ;
if ( V_26 -> V_58 != V_25 -> V_58 )
V_32 |= V_59 ;
F_1 ( V_2 , V_4 , V_60 , V_32 ) ;
F_1 ( V_2 , V_4 , V_61 , V_21 -> V_62 ) ;
if ( V_18 -> V_63 ) {
const struct V_27 * V_64 ;
V_64 = F_9 ( V_18 -> V_63 ,
V_18 -> V_63 -> V_33 ,
V_2 -> V_65 ) ;
V_29 = V_64 -> V_29 ;
V_30 = V_64 -> V_30 ;
}
F_1 ( V_2 , V_4 , V_66 ,
( V_29 << V_67 ) |
( V_30 << V_68 ) ) ;
F_1 ( V_2 , V_4 , V_69 , V_70 |
( V_21 -> V_71 ? V_72
: V_73 ) ) ;
F_1 ( V_2 , V_4 , V_74 ,
V_2 -> V_71 << V_75 ) ;
if ( V_7 -> V_76 -> V_77 -> V_78 == 3 ) {
T_1 V_79 ;
if ( V_21 -> V_71 ) {
bool V_80 = V_23 -> V_81
& V_82 ;
V_79 = V_83
| ( V_80 ?
V_84 :
V_85 )
| ( V_2 -> V_71 << V_86 ) ;
} else {
V_79 = V_87
| V_85 ;
}
F_1 ( V_2 , V_4 , V_88 , V_79 ) ;
}
F_10 ( V_18 , & V_2 -> V_7 , V_4 , V_2 -> V_71 ) ;
F_1 ( V_2 , V_4 , V_89 , 0 ) ;
F_1 ( V_2 , V_4 , V_90 , 0 ) ;
}
struct V_1 * F_11 ( struct V_91 * V_76 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_92 [ 6 ] ;
int V_93 ;
V_2 = F_12 ( V_76 -> V_94 , sizeof( * V_2 ) , V_95 ) ;
if ( V_2 == NULL )
return F_13 ( - V_96 ) ;
V_2 -> V_97 = V_98 ;
V_2 -> V_99 = V_100 ;
V_2 -> V_7 . V_101 = & V_102 ;
V_2 -> V_7 . type = V_103 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_92 , L_1 , V_8 ) ;
V_93 = F_14 ( V_76 , & V_2 -> V_7 , V_92 , 2 , & V_104 ) ;
if ( V_93 < 0 )
return F_13 ( V_93 ) ;
V_93 = F_15 ( V_2 ) ;
if ( V_93 < 0 ) {
F_16 ( V_76 -> V_94 , L_2 ,
V_8 ) ;
goto error;
}
return V_2 ;
error:
F_17 ( & V_2 -> V_7 ) ;
return F_13 ( V_93 ) ;
}
