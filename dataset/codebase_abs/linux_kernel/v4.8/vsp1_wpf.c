static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 + V_2 -> V_7 . V_8 * V_9 , V_6 ) ;
}
static int F_3 ( struct V_10 * V_11 )
{
struct V_1 * V_2 =
F_4 ( V_11 -> V_12 , struct V_1 , V_13 ) ;
unsigned int V_14 ;
T_1 V_15 = 0 ;
switch ( V_11 -> V_16 ) {
case V_17 :
case V_18 :
for ( V_14 = 0 ; V_14 < V_19 ; ++ V_14 ) {
if ( V_2 -> V_15 . V_13 [ V_14 ] )
V_15 |= V_2 -> V_15 . V_13 [ V_14 ] -> V_20 ? F_5 ( V_14 ) : 0 ;
}
F_6 ( & V_2 -> V_15 . V_21 ) ;
V_2 -> V_15 . V_22 = V_15 ;
F_7 ( & V_2 -> V_15 . V_21 ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_7 . V_25 ;
unsigned int V_26 ;
F_9 ( & V_2 -> V_15 . V_21 ) ;
if ( V_2 -> V_7 . V_8 != 0 ) {
V_26 = 0 ;
} else if ( V_25 -> V_27 -> V_28 & V_29 ) {
V_26 = 2 ;
} else if ( V_25 -> V_27 -> V_28 & V_30 ) {
V_26 = 1 ;
} else {
V_26 = 0 ;
}
F_10 ( V_2 , V_26 ) ;
if ( V_26 >= 1 ) {
V_2 -> V_15 . V_13 [ V_31 ] =
F_11 ( & V_2 -> V_13 , & V_32 ,
V_18 , 0 , 1 , 1 , 0 ) ;
}
if ( V_26 == 2 ) {
V_2 -> V_15 . V_13 [ V_33 ] =
F_11 ( & V_2 -> V_13 , & V_32 ,
V_17 , 0 , 1 , 1 , 0 ) ;
F_12 ( 2 , V_2 -> V_15 . V_13 ) ;
}
if ( V_2 -> V_13 . error ) {
F_13 ( V_25 -> V_34 , L_1 ,
V_2 -> V_7 . V_8 ) ;
return V_2 -> V_13 . error ;
}
return 0 ;
}
static int F_14 ( struct V_35 * V_36 , int V_37 )
{
struct V_1 * V_2 = F_15 ( V_36 ) ;
struct V_24 * V_25 = V_2 -> V_7 . V_25 ;
if ( V_37 )
return 0 ;
F_16 ( V_25 , F_17 ( V_2 -> V_7 . V_8 ) , 0 ) ;
F_16 ( V_25 , V_2 -> V_7 . V_8 * V_9 +
V_38 , 0 ) ;
return 0 ;
}
static void F_18 ( struct V_39 * V_7 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
F_20 ( V_2 -> V_40 ) ;
}
static void F_21 ( struct V_39 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
const struct V_41 * V_42 = & V_2 -> V_42 ;
struct V_43 V_44 = V_2 -> V_44 ;
unsigned int V_15 = V_2 -> V_15 . V_45 ;
unsigned int V_46 ;
if ( V_15 & F_5 ( V_31 ) ) {
V_44 . V_47 [ 0 ] += ( V_42 -> V_48 - 1 )
* V_42 -> V_49 [ 0 ] . V_50 ;
if ( V_42 -> V_51 > 1 ) {
V_46 = ( V_42 -> V_48 / V_2 -> V_52 -> V_53 - 1 )
* V_42 -> V_49 [ 1 ] . V_50 ;
V_44 . V_47 [ 1 ] += V_46 ;
V_44 . V_47 [ 2 ] += V_46 ;
}
}
F_1 ( V_2 , V_4 , V_54 , V_44 . V_47 [ 0 ] ) ;
F_1 ( V_2 , V_4 , V_55 , V_44 . V_47 [ 1 ] ) ;
F_1 ( V_2 , V_4 , V_56 , V_44 . V_47 [ 2 ] ) ;
}
static void F_22 ( struct V_39 * V_7 ,
struct V_57 * V_58 ,
struct V_3 * V_4 , bool V_59 )
{
struct V_1 * V_2 = F_15 ( & V_7 -> V_36 ) ;
struct V_24 * V_25 = V_2 -> V_7 . V_25 ;
const struct V_60 * V_61 ;
const struct V_60 * V_62 ;
const struct V_63 * V_64 ;
unsigned int V_14 ;
T_1 V_65 = 0 ;
T_1 V_66 = 0 ;
if ( ! V_59 ) {
const unsigned int V_67 = F_5 ( V_31 )
| F_5 ( V_33 ) ;
F_23 ( & V_2 -> V_15 . V_21 ) ;
V_2 -> V_15 . V_45 = ( V_2 -> V_15 . V_45 & ~ V_67 )
| ( V_2 -> V_15 . V_22 & V_67 ) ;
F_24 ( & V_2 -> V_15 . V_21 ) ;
V_65 = ( V_2 -> V_68 << V_69 ) | V_2 -> V_65 ;
if ( V_2 -> V_15 . V_45 & F_5 ( V_31 ) )
V_65 |= V_70 ;
if ( V_2 -> V_15 . V_45 & F_5 ( V_33 ) )
V_65 |= V_71 ;
F_1 ( V_2 , V_4 , V_72 , V_65 ) ;
return;
}
V_64 = F_25 ( V_2 , V_2 -> V_7 . V_73 ) ;
F_1 ( V_2 , V_4 , V_74 , V_75 |
( V_64 -> V_76 << V_77 ) |
( V_64 -> V_78 << V_79 ) ) ;
F_1 ( V_2 , V_4 , V_80 , V_75 |
( V_64 -> V_81 << V_77 ) |
( V_64 -> V_48 << V_79 ) ) ;
V_62 = F_26 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_73 ,
V_82 ) ;
V_61 = F_26 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_73 ,
V_83 ) ;
if ( ! V_58 -> V_84 ) {
const struct V_41 * V_42 = & V_2 -> V_42 ;
const struct V_85 * V_52 = V_2 -> V_52 ;
V_65 = V_52 -> V_86 << V_87 ;
if ( V_52 -> V_68 )
V_65 |= V_88 ;
if ( V_52 -> V_89 )
V_65 |= V_90 ;
if ( V_52 -> V_91 )
V_65 |= V_92 ;
F_1 ( V_2 , V_4 , V_93 ,
V_42 -> V_49 [ 0 ] . V_50 ) ;
if ( V_42 -> V_51 > 1 )
F_1 ( V_2 , V_4 , V_94 ,
V_42 -> V_49 [ 1 ] . V_50 ) ;
F_1 ( V_2 , V_4 , V_95 , V_52 -> V_96 ) ;
if ( V_25 -> V_27 -> V_28 & V_29 &&
V_2 -> V_7 . V_8 == 0 )
F_1 ( V_2 , V_4 , V_97 ,
V_98 |
( 256 << V_99 ) ) ;
}
if ( V_62 -> V_100 != V_61 -> V_100 )
V_65 |= V_101 ;
V_2 -> V_65 = V_65 ;
F_2 ( V_4 , F_27 ( V_2 -> V_7 . V_8 ) ,
V_102 ) ;
F_2 ( V_4 , V_103 , 0 ) ;
for ( V_14 = 0 ; V_14 < V_25 -> V_27 -> V_104 ; ++ V_14 ) {
struct V_1 * V_105 = V_58 -> V_106 [ V_14 ] ;
if ( ! V_105 )
continue;
V_66 |= ( ! V_58 -> V_107 && V_58 -> V_108 == 1 )
? F_28 ( V_105 -> V_7 . V_8 )
: F_29 ( V_105 -> V_7 . V_8 ) ;
}
if ( V_58 -> V_107 || V_58 -> V_108 > 1 )
V_66 |= V_109 ;
F_1 ( V_2 , V_4 , V_38 , V_66 ) ;
F_2 ( V_4 , F_30 ( V_2 -> V_7 . V_8 ) , 0 ) ;
F_2 ( V_4 , F_17 ( V_2 -> V_7 . V_8 ) ,
V_110 ) ;
}
struct V_1 * F_31 ( struct V_24 * V_25 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_111 [ 6 ] ;
int V_112 ;
V_2 = F_32 ( V_25 -> V_34 , sizeof( * V_2 ) , V_113 ) ;
if ( V_2 == NULL )
return F_33 ( - V_114 ) ;
if ( V_25 -> V_27 -> V_115 == 2 ) {
V_2 -> V_116 = V_117 ;
V_2 -> V_118 = V_119 ;
} else {
V_2 -> V_116 = V_120 ;
V_2 -> V_118 = V_121 ;
}
V_2 -> V_7 . V_122 = & V_123 ;
V_2 -> V_7 . type = V_124 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_111 , L_2 , V_8 ) ;
V_112 = F_34 ( V_25 , & V_2 -> V_7 , V_111 , 2 , & V_125 ,
V_126 ) ;
if ( V_112 < 0 )
return F_33 ( V_112 ) ;
V_2 -> V_40 = F_35 ( V_25 , V_8 , 4 ) ;
if ( ! V_2 -> V_40 ) {
V_112 = - V_114 ;
goto error;
}
V_112 = F_8 ( V_2 ) ;
if ( V_112 < 0 ) {
F_13 ( V_25 -> V_34 , L_1 ,
V_8 ) ;
goto error;
}
F_36 ( & V_2 -> V_13 ) ;
return V_2 ;
error:
F_37 ( & V_2 -> V_7 ) ;
return F_33 ( V_112 ) ;
}
