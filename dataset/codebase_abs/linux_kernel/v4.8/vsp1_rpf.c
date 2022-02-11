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
struct V_3 * V_4 , bool V_19 )
{
struct V_1 * V_2 = F_6 ( & V_7 -> V_20 ) ;
const struct V_21 * V_22 = V_2 -> V_22 ;
const struct V_23 * V_24 = & V_2 -> V_24 ;
const struct V_25 * V_26 ;
const struct V_25 * V_27 ;
const struct V_28 * V_29 ;
unsigned int V_30 = 0 ;
unsigned int V_31 = 0 ;
T_1 V_32 ;
T_1 V_33 ;
if ( ! V_19 ) {
F_1 ( V_2 , V_4 , V_34 ,
V_2 -> V_35 << V_36 ) ;
F_1 ( V_2 , V_4 , V_37 , V_2 -> V_38 |
( V_2 -> V_35 << V_39 ) ) ;
F_7 ( V_18 , V_4 , V_2 -> V_35 ) ;
return;
}
V_29 = F_8 ( V_2 , V_2 -> V_7 . V_40 ) ;
F_1 ( V_2 , V_4 , V_41 ,
( V_29 -> V_42 << V_43 ) |
( V_29 -> V_44 << V_45 ) ) ;
F_1 ( V_2 , V_4 , V_46 ,
( V_29 -> V_42 << V_47 ) |
( V_29 -> V_44 << V_48 ) ) ;
V_2 -> V_14 [ 0 ] = V_29 -> V_31 * V_24 -> V_49 [ 0 ] . V_50
+ V_29 -> V_30 * V_22 -> V_51 [ 0 ] / 8 ;
V_32 = V_24 -> V_49 [ 0 ] . V_50
<< V_52 ;
if ( V_24 -> V_53 > 1 ) {
V_2 -> V_14 [ 1 ] = V_29 -> V_31 * V_24 -> V_49 [ 1 ] . V_50
+ V_29 -> V_30 * V_22 -> V_51 [ 1 ] / 8 ;
V_32 |= V_24 -> V_49 [ 1 ] . V_50
<< V_54 ;
} else {
V_2 -> V_14 [ 1 ] = 0 ;
}
F_1 ( V_2 , V_4 , V_55 , V_32 ) ;
V_27 = F_9 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_40 ,
V_56 ) ;
V_26 = F_9 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_40 ,
V_57 ) ;
V_33 = V_58
| ( V_22 -> V_59 << V_60 ) ;
if ( V_22 -> V_61 )
V_33 |= V_62 ;
if ( V_22 -> V_63 )
V_33 |= V_64 ;
if ( V_27 -> V_65 != V_26 -> V_65 )
V_33 |= V_66 ;
F_1 ( V_2 , V_4 , V_67 , V_33 ) ;
F_1 ( V_2 , V_4 , V_68 , V_22 -> V_69 ) ;
if ( V_18 -> V_70 ) {
const struct V_28 * V_71 ;
V_71 = F_10 ( V_18 -> V_70 ,
V_18 -> V_70 -> V_40 ,
V_2 -> V_72 ,
V_73 ) ;
V_30 = V_71 -> V_30 ;
V_31 = V_71 -> V_31 ;
}
F_1 ( V_2 , V_4 , V_74 ,
( V_30 << V_75 ) |
( V_31 << V_76 ) ) ;
F_1 ( V_2 , V_4 , V_77 , V_78 |
( V_22 -> V_35 ? V_79
: V_80 ) ) ;
if ( V_7 -> V_81 -> V_82 -> V_83 == 3 ) {
T_1 V_84 ;
if ( V_22 -> V_35 ) {
bool V_85 = V_24 -> V_86
& V_87 ;
V_84 = V_88
| ( V_85 ?
V_89 :
V_90 ) ;
} else {
V_84 = V_91
| V_90 ;
}
V_2 -> V_38 = V_84 ;
}
F_1 ( V_2 , V_4 , V_92 , 0 ) ;
F_1 ( V_2 , V_4 , V_93 , 0 ) ;
}
struct V_1 * F_11 ( struct V_94 * V_81 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_95 [ 6 ] ;
int V_96 ;
V_2 = F_12 ( V_81 -> V_97 , sizeof( * V_2 ) , V_98 ) ;
if ( V_2 == NULL )
return F_13 ( - V_99 ) ;
V_2 -> V_100 = V_101 ;
V_2 -> V_102 = V_103 ;
V_2 -> V_7 . V_104 = & V_105 ;
V_2 -> V_7 . type = V_106 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_95 , L_1 , V_8 ) ;
V_96 = F_14 ( V_81 , & V_2 -> V_7 , V_95 , 2 , & V_107 ,
V_108 ) ;
if ( V_96 < 0 )
return F_13 ( V_96 ) ;
V_96 = F_15 ( V_2 , 0 ) ;
if ( V_96 < 0 ) {
F_16 ( V_81 -> V_97 , L_2 ,
V_8 ) ;
goto error;
}
F_17 ( & V_2 -> V_109 ) ;
return V_2 ;
error:
F_18 ( & V_2 -> V_7 ) ;
return F_13 ( V_96 ) ;
}
