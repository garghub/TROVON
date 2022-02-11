static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 + V_2 -> V_7 . V_8 * V_9 , V_6 ) ;
}
static void F_3 ( struct V_10 * V_7 ,
struct V_11 * V_12 ,
struct V_3 * V_4 ,
enum V_13 V_14 )
{
struct V_1 * V_2 = F_4 ( & V_7 -> V_15 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
const struct V_18 * V_19 = & V_2 -> V_19 ;
const struct V_20 * V_21 ;
const struct V_20 * V_22 ;
unsigned int V_23 = 0 ;
unsigned int V_24 = 0 ;
T_1 V_25 ;
T_1 V_26 ;
if ( V_14 == V_27 ) {
F_1 ( V_2 , V_4 , V_28 ,
V_2 -> V_29 << V_30 ) ;
F_1 ( V_2 , V_4 , V_31 , V_2 -> V_32 |
( V_2 -> V_29 << V_33 ) ) ;
F_5 ( V_12 , V_4 , V_2 -> V_29 ) ;
return;
}
if ( V_14 == V_34 ) {
struct V_35 * V_36 = V_2 -> V_7 . V_36 ;
struct V_37 V_38 = V_2 -> V_38 ;
struct V_39 V_40 ;
V_40 = * F_6 ( V_2 , V_2 -> V_7 . V_41 ) ;
if ( V_12 -> V_42 > 1 ) {
V_40 . V_43 = V_12 -> V_44 -> V_2 . V_43 ;
V_40 . V_23 += V_12 -> V_44 -> V_2 . V_23 ;
}
F_1 ( V_2 , V_4 , V_45 ,
( V_40 . V_43 << V_46 ) |
( V_40 . V_47 << V_48 ) ) ;
F_1 ( V_2 , V_4 , V_49 ,
( V_40 . V_43 << V_50 ) |
( V_40 . V_47 << V_51 ) ) ;
V_38 . V_52 [ 0 ] += V_40 . V_24 * V_19 -> V_53 [ 0 ] . V_54
+ V_40 . V_23 * V_17 -> V_55 [ 0 ] / 8 ;
if ( V_19 -> V_56 > 1 ) {
unsigned int V_57 ;
V_57 = V_40 . V_24 * V_19 -> V_53 [ 1 ] . V_54
+ V_40 . V_23 / V_17 -> V_58
* V_17 -> V_55 [ 1 ] / 8 ;
V_38 . V_52 [ 1 ] += V_57 ;
V_38 . V_52 [ 2 ] += V_57 ;
}
if ( V_36 -> V_59 -> V_60 == 3 && V_19 -> V_56 == 3 &&
V_17 -> V_61 )
F_7 ( V_38 . V_52 [ 1 ] , V_38 . V_52 [ 2 ] ) ;
F_1 ( V_2 , V_4 , V_62 , V_38 . V_52 [ 0 ] ) ;
F_1 ( V_2 , V_4 , V_63 , V_38 . V_52 [ 1 ] ) ;
F_1 ( V_2 , V_4 , V_64 , V_38 . V_52 [ 2 ] ) ;
return;
}
V_25 = V_19 -> V_53 [ 0 ] . V_54
<< V_65 ;
if ( V_19 -> V_56 > 1 )
V_25 |= V_19 -> V_53 [ 1 ] . V_54
<< V_66 ;
F_1 ( V_2 , V_4 , V_67 , V_25 ) ;
V_22 = F_8 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_41 ,
V_68 ) ;
V_21 = F_8 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_41 ,
V_69 ) ;
V_26 = V_70
| ( V_17 -> V_71 << V_72 ) ;
if ( V_17 -> V_73 )
V_26 |= V_74 ;
if ( V_17 -> V_61 )
V_26 |= V_75 ;
if ( V_22 -> V_76 != V_21 -> V_76 )
V_26 |= V_77 ;
F_1 ( V_2 , V_4 , V_78 , V_26 ) ;
F_1 ( V_2 , V_4 , V_79 , V_17 -> F_7 ) ;
if ( V_12 -> V_80 ) {
const struct V_39 * V_81 ;
V_81 = F_9 ( V_12 -> V_80 ,
V_12 -> V_80 -> V_41 ,
V_2 -> V_82 ,
V_83 ) ;
V_23 = V_81 -> V_23 ;
V_24 = V_81 -> V_24 ;
}
F_1 ( V_2 , V_4 , V_84 ,
( V_23 << V_85 ) |
( V_24 << V_86 ) ) ;
F_1 ( V_2 , V_4 , V_87 , V_88 |
( V_17 -> V_29 ? V_89
: V_90 ) ) ;
if ( V_7 -> V_36 -> V_59 -> V_60 == 3 ) {
T_1 V_91 ;
if ( V_17 -> V_29 ) {
bool V_92 = V_19 -> V_93
& V_94 ;
V_91 = V_95
| ( V_92 ?
V_96 :
V_97 ) ;
} else {
V_91 = V_98
| V_97 ;
}
V_2 -> V_32 = V_91 ;
}
F_1 ( V_2 , V_4 , V_99 , 0 ) ;
F_1 ( V_2 , V_4 , V_100 , 0 ) ;
}
static void F_10 ( struct V_10 * V_7 ,
struct V_11 * V_12 ,
struct V_101 * V_44 ,
unsigned int V_102 ,
struct V_103 * V_104 )
{
V_44 -> V_2 = * V_104 ;
}
struct V_1 * F_11 ( struct V_35 * V_36 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_105 [ 6 ] ;
int V_106 ;
V_2 = F_12 ( V_36 -> V_107 , sizeof( * V_2 ) , V_108 ) ;
if ( V_2 == NULL )
return F_13 ( - V_109 ) ;
V_2 -> V_110 = V_111 ;
V_2 -> V_112 = V_113 ;
V_2 -> V_7 . V_114 = & V_115 ;
V_2 -> V_7 . type = V_116 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_105 , L_1 , V_8 ) ;
V_106 = F_14 ( V_36 , & V_2 -> V_7 , V_105 , 2 , & V_117 ,
V_118 ) ;
if ( V_106 < 0 )
return F_13 ( V_106 ) ;
V_106 = F_15 ( V_2 , 0 ) ;
if ( V_106 < 0 ) {
F_16 ( V_36 -> V_107 , L_2 ,
V_8 ) ;
goto error;
}
F_17 ( & V_2 -> V_119 ) ;
return V_2 ;
error:
F_18 ( & V_2 -> V_7 ) ;
return F_13 ( V_106 ) ;
}
