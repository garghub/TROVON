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
static void F_21 ( struct V_39 * V_7 ,
struct V_41 * V_42 ,
struct V_3 * V_4 ,
enum V_43 V_44 )
{
struct V_1 * V_2 = F_15 ( & V_7 -> V_36 ) ;
struct V_24 * V_25 = V_2 -> V_7 . V_25 ;
const struct V_45 * V_46 ;
const struct V_45 * V_47 ;
unsigned int V_14 ;
T_1 V_48 = 0 ;
T_1 V_49 = 0 ;
if ( V_44 == V_50 ) {
const unsigned int V_51 = F_5 ( V_31 )
| F_5 ( V_33 ) ;
unsigned long V_52 ;
F_22 ( & V_2 -> V_15 . V_21 , V_52 ) ;
V_2 -> V_15 . V_53 = ( V_2 -> V_15 . V_53 & ~ V_51 )
| ( V_2 -> V_15 . V_22 & V_51 ) ;
F_23 ( & V_2 -> V_15 . V_21 , V_52 ) ;
V_48 = ( V_2 -> V_54 << V_55 ) | V_2 -> V_48 ;
if ( V_2 -> V_15 . V_53 & F_5 ( V_31 ) )
V_48 |= V_56 ;
if ( V_2 -> V_15 . V_53 & F_5 ( V_33 ) )
V_48 |= V_57 ;
F_1 ( V_2 , V_4 , V_58 , V_48 ) ;
return;
}
V_47 = F_24 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_59 ,
V_60 ) ;
V_46 = F_24 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_59 ,
V_61 ) ;
if ( V_44 == V_62 ) {
const struct V_63 * V_64 = & V_2 -> V_64 ;
struct V_65 V_66 = V_2 -> V_66 ;
unsigned int V_15 = V_2 -> V_15 . V_53 ;
unsigned int V_67 = V_46 -> V_67 ;
unsigned int V_68 = V_46 -> V_68 ;
unsigned int V_69 ;
if ( V_42 -> V_70 > 1 )
V_67 = V_42 -> V_71 . V_67 ;
F_1 ( V_2 , V_4 , V_72 , V_73 |
( 0 << V_74 ) |
( V_67 << V_75 ) ) ;
F_1 ( V_2 , V_4 , V_76 , V_73 |
( 0 << V_74 ) |
( V_68 << V_75 ) ) ;
if ( V_42 -> V_77 )
return;
if ( V_42 -> V_70 > 1 ) {
const struct V_78 * V_79 = V_2 -> V_79 ;
if ( V_15 & F_5 ( V_33 ) )
V_69 = V_64 -> V_67 - V_42 -> V_71 . V_80
- V_42 -> V_71 . V_67 ;
else
V_69 = V_42 -> V_71 . V_80 ;
V_66 . V_81 [ 0 ] += V_69 * V_79 -> V_82 [ 0 ] / 8 ;
if ( V_64 -> V_83 > 1 ) {
V_66 . V_81 [ 1 ] += V_69 / V_79 -> V_84
* V_79 -> V_82 [ 1 ] / 8 ;
V_66 . V_81 [ 2 ] += V_69 / V_79 -> V_84
* V_79 -> V_82 [ 2 ] / 8 ;
}
}
if ( V_15 & F_5 ( V_31 ) ) {
V_66 . V_81 [ 0 ] += ( V_64 -> V_68 - 1 )
* V_64 -> V_85 [ 0 ] . V_86 ;
if ( V_64 -> V_83 > 1 ) {
V_69 = ( V_64 -> V_68 / V_2 -> V_79 -> V_87 - 1 )
* V_64 -> V_85 [ 1 ] . V_86 ;
V_66 . V_81 [ 1 ] += V_69 ;
V_66 . V_81 [ 2 ] += V_69 ;
}
}
F_1 ( V_2 , V_4 , V_88 , V_66 . V_81 [ 0 ] ) ;
F_1 ( V_2 , V_4 , V_89 , V_66 . V_81 [ 1 ] ) ;
F_1 ( V_2 , V_4 , V_90 , V_66 . V_81 [ 2 ] ) ;
return;
}
if ( ! V_42 -> V_77 ) {
const struct V_63 * V_64 = & V_2 -> V_64 ;
const struct V_78 * V_79 = V_2 -> V_79 ;
V_48 = V_79 -> V_91 << V_92 ;
if ( V_79 -> V_54 )
V_48 |= V_93 ;
if ( V_79 -> V_94 )
V_48 |= V_95 ;
if ( V_79 -> V_96 )
V_48 |= V_97 ;
F_1 ( V_2 , V_4 , V_98 ,
V_64 -> V_85 [ 0 ] . V_86 ) ;
if ( V_64 -> V_83 > 1 )
F_1 ( V_2 , V_4 , V_99 ,
V_64 -> V_85 [ 1 ] . V_86 ) ;
F_1 ( V_2 , V_4 , V_100 , V_79 -> V_101 ) ;
if ( V_25 -> V_27 -> V_28 & V_29 &&
V_2 -> V_7 . V_8 == 0 )
F_1 ( V_2 , V_4 , V_102 ,
V_103 |
( 256 << V_104 ) ) ;
}
if ( V_47 -> V_105 != V_46 -> V_105 )
V_48 |= V_106 ;
V_2 -> V_48 = V_48 ;
F_2 ( V_4 , F_25 ( V_2 -> V_7 . V_8 ) ,
V_107 ) ;
F_2 ( V_4 , V_108 , 0 ) ;
for ( V_14 = 0 ; V_14 < V_25 -> V_27 -> V_109 ; ++ V_14 ) {
struct V_1 * V_110 = V_42 -> V_111 [ V_14 ] ;
if ( ! V_110 )
continue;
V_49 |= ( ! V_42 -> V_112 && V_42 -> V_113 == 1 )
? F_26 ( V_110 -> V_7 . V_8 )
: F_27 ( V_110 -> V_7 . V_8 ) ;
}
if ( V_42 -> V_112 || V_42 -> V_113 > 1 )
V_49 |= V_114 ;
F_1 ( V_2 , V_4 , V_38 , V_49 ) ;
F_2 ( V_4 , F_28 ( V_2 -> V_7 . V_8 ) , 0 ) ;
F_2 ( V_4 , F_17 ( V_2 -> V_7 . V_8 ) ,
V_115 ) ;
}
struct V_1 * F_29 ( struct V_24 * V_25 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_116 [ 6 ] ;
int V_117 ;
V_2 = F_30 ( V_25 -> V_34 , sizeof( * V_2 ) , V_118 ) ;
if ( V_2 == NULL )
return F_31 ( - V_119 ) ;
if ( V_25 -> V_27 -> V_120 == 2 ) {
V_2 -> V_121 = V_122 ;
V_2 -> V_123 = V_124 ;
} else {
V_2 -> V_121 = V_125 ;
V_2 -> V_123 = V_126 ;
}
V_2 -> V_7 . V_127 = & V_128 ;
V_2 -> V_7 . type = V_129 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_116 , L_2 , V_8 ) ;
V_117 = F_32 ( V_25 , & V_2 -> V_7 , V_116 , 2 , & V_130 ,
V_131 ) ;
if ( V_117 < 0 )
return F_31 ( V_117 ) ;
V_2 -> V_40 = F_33 ( V_25 , V_8 , 64 ) ;
if ( ! V_2 -> V_40 ) {
V_117 = - V_119 ;
goto error;
}
V_117 = F_8 ( V_2 ) ;
if ( V_117 < 0 ) {
F_13 ( V_25 -> V_34 , L_1 ,
V_8 ) ;
goto error;
}
F_34 ( & V_2 -> V_13 ) ;
return V_2 ;
error:
F_35 ( & V_2 -> V_7 ) ;
return F_31 ( V_117 ) ;
}
