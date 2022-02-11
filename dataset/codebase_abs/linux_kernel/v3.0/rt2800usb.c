static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
switch ( V_2 -> V_6 ) {
case V_7 :
F_2 ( V_4 , V_8 , & V_5 ) ;
F_3 ( & V_5 , V_9 , 1 ) ;
F_4 ( V_4 , V_8 , V_5 ) ;
break;
case V_10 :
F_2 ( V_4 , V_11 , & V_5 ) ;
F_3 ( & V_5 , V_12 , 1 ) ;
F_3 ( & V_5 , V_13 , 1 ) ;
F_3 ( & V_5 , V_14 , 1 ) ;
F_4 ( V_4 , V_11 , V_5 ) ;
break;
default:
break;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
switch ( V_2 -> V_6 ) {
case V_7 :
F_2 ( V_4 , V_8 , & V_5 ) ;
F_3 ( & V_5 , V_9 , 0 ) ;
F_4 ( V_4 , V_8 , V_5 ) ;
break;
case V_10 :
F_2 ( V_4 , V_11 , & V_5 ) ;
F_3 ( & V_5 , V_12 , 0 ) ;
F_3 ( & V_5 , V_13 , 0 ) ;
F_3 ( & V_5 , V_14 , 0 ) ;
F_4 ( V_4 , V_11 , V_5 ) ;
break;
default:
break;
}
}
static bool F_6 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 (rt2x00dev, queue) {
if ( F_8 ( V_2 , V_15 ) !=
F_8 ( V_2 , V_16 ) )
return true ;
}
return false ;
}
static bool F_9 ( struct V_3 * V_4 ,
int V_17 , T_1 V_18 )
{
if ( V_17 ) {
F_10 ( V_4 , L_1 , V_17 ) ;
return false ;
}
if ( F_11 ( V_18 , V_19 ) ) {
if ( ! F_12 ( & V_4 -> V_20 , & V_18 ) ) {
F_10 ( V_4 , L_2
L_3 ) ;
F_13 ( V_4 -> V_21 , & V_4 -> V_22 ) ;
} else
return true ;
} else if ( ! F_14 ( & V_4 -> V_20 ) ) {
F_13 ( V_4 -> V_21 , & V_4 -> V_22 ) ;
} else if ( F_6 ( V_4 ) ) {
F_15 ( & V_4 -> V_23 , V_24 + F_16 ( 2 ) ) ;
}
return false ;
}
static void F_17 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = V_26 -> V_2 -> V_4 ;
F_18 ( V_4 , V_27 ,
F_9 ) ;
}
static void F_19 ( unsigned long V_28 )
{
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
F_18 ( V_4 , V_27 ,
F_9 ) ;
}
static char * F_20 ( struct V_3 * V_4 )
{
return V_29 ;
}
static int F_21 ( struct V_3 * V_4 ,
const T_2 * V_28 , const T_3 V_30 )
{
int V_31 ;
T_1 V_32 ;
T_1 V_33 ;
if ( F_22 ( V_4 , V_34 ) ||
F_22 ( V_4 , V_35 ) ||
F_22 ( V_4 , V_36 ) ) {
V_32 = 0 ;
V_33 = 4096 ;
} else {
V_32 = 4096 ;
V_33 = 4096 ;
}
F_23 ( V_4 , V_37 ,
V_28 + V_32 , V_33 ) ;
F_4 ( V_4 , V_38 , ~ 0 ) ;
F_4 ( V_4 , V_39 , ~ 0 ) ;
V_31 = F_24 ( V_4 , V_40 ,
0 , V_41 ,
V_42 ) ;
if ( V_31 < 0 ) {
ERROR ( V_4 , L_4 ) ;
return V_31 ;
}
F_25 ( 10 ) ;
F_4 ( V_4 , V_43 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 )
{
T_1 V_5 ;
if ( F_27 ( V_4 ) )
return - V_44 ;
F_2 ( V_4 , V_45 , & V_5 ) ;
F_4 ( V_4 , V_45 , V_5 & ~ 0x00002000 ) ;
F_4 ( V_4 , V_46 , 0x00000003 ) ;
F_2 ( V_4 , V_8 , & V_5 ) ;
F_3 ( & V_5 , V_47 , 1 ) ;
F_3 ( & V_5 , V_48 , 1 ) ;
F_4 ( V_4 , V_8 , V_5 ) ;
F_4 ( V_4 , V_49 , 0x00000000 ) ;
F_24 ( V_4 , V_40 , 0 ,
V_50 , V_51 ) ;
F_4 ( V_4 , V_8 , 0x00000000 ) ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 )
{
T_1 V_5 ;
if ( F_29 ( F_30 ( V_4 ) ) )
return - V_52 ;
F_2 ( V_4 , V_49 , & V_5 ) ;
F_3 ( & V_5 , V_53 , 0 ) ;
F_3 ( & V_5 , V_54 , 0 ) ;
F_3 ( & V_5 , V_55 , 128 ) ;
F_3 ( & V_5 , V_56 ,
( ( V_4 -> V_57 -> V_58 -> V_59 * V_60 )
/ 1024 ) - 3 ) ;
F_3 ( & V_5 , V_61 , 1 ) ;
F_3 ( & V_5 , V_62 , 1 ) ;
F_4 ( V_4 , V_49 , V_5 ) ;
return F_31 ( V_4 ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
F_33 ( V_4 ) ;
F_34 ( V_4 ) ;
}
static int F_35 ( struct V_3 * V_4 ,
enum V_63 V_64 )
{
if ( V_64 == V_65 )
F_36 ( V_4 , V_66 , 0xff , 0 , 2 ) ;
else
F_36 ( V_4 , V_67 , 0xff , 0xff , 2 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
enum V_63 V_64 )
{
int V_68 = 0 ;
switch ( V_64 ) {
case V_69 :
F_35 ( V_4 , V_65 ) ;
F_25 ( 1 ) ;
V_68 = F_28 ( V_4 ) ;
break;
case V_70 :
F_32 ( V_4 ) ;
F_35 ( V_4 , V_71 ) ;
break;
case V_72 :
case V_73 :
break;
case V_74 :
case V_71 :
case V_75 :
case V_65 :
V_68 = F_35 ( V_4 , V_64 ) ;
break;
default:
V_68 = - V_76 ;
break;
}
if ( F_29 ( V_68 ) )
ERROR ( V_4 , L_5 ,
V_64 , V_68 ) ;
return V_68 ;
}
static void F_38 ( struct V_3 * V_4 )
{
unsigned int V_77 ;
T_1 V_5 ;
F_2 ( V_4 , V_78 , & V_5 ) ;
if ( F_11 ( V_5 , V_79 ) ) {
F_10 ( V_4 , L_6
L_7 ) ;
F_4 ( V_4 , V_80 , 0xf40012 ) ;
for ( V_77 = 0 ; V_77 < 10 ; V_77 ++ ) {
F_39 ( 10 ) ;
if ( ! F_11 ( V_5 , V_79 ) )
break;
}
F_4 ( V_4 , V_80 , 0xf40006 ) ;
}
F_2 ( V_4 , V_78 , & V_5 ) ;
if ( F_11 ( V_5 , V_81 ) ) {
F_10 ( V_4 , L_8
L_7 ) ;
F_4 ( V_4 , V_80 , 0xf4000a ) ;
for ( V_77 = 0 ; V_77 < 10 ; V_77 ++ ) {
F_39 ( 10 ) ;
if ( ! F_11 ( V_5 , V_81 ) )
break;
}
F_4 ( V_4 , V_80 , 0xf40006 ) ;
}
F_40 ( V_4 ) ;
}
static T_4 * F_41 ( struct V_25 * V_26 )
{
if ( V_26 -> V_2 -> V_6 == V_10 )
return ( T_4 * ) ( V_26 -> V_82 -> V_28 ) ;
else
return ( T_4 * ) ( V_26 -> V_82 -> V_28 + V_83 ) ;
}
static void F_42 ( struct V_25 * V_26 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 = F_43 ( V_26 -> V_82 ) ;
T_4 * V_88 = ( T_4 * ) V_26 -> V_82 -> V_28 ;
T_1 V_89 ;
F_44 ( V_88 , 0 , & V_89 ) ;
F_3 ( & V_89 , V_90 ,
V_26 -> V_82 -> V_30 - V_83 - 4 ) ;
F_3 ( & V_89 , V_91 ,
! F_45 ( V_92 , & V_85 -> V_93 ) ) ;
F_3 ( & V_89 , V_94 , 2 ) ;
F_3 ( & V_89 , V_95 , 0 ) ;
F_3 ( & V_89 , V_96 , 0 ) ;
F_3 ( & V_89 , V_97 ,
F_45 ( V_98 , & V_85 -> V_93 ) ) ;
F_46 ( V_88 , 0 , V_89 ) ;
V_87 -> V_93 |= V_99 ;
V_87 -> V_100 = V_88 ;
V_87 -> V_101 = V_83 + V_102 ;
}
static void F_47 ( struct V_25 * V_26 ,
struct V_84 * V_85 )
{
unsigned int V_30 ;
int V_103 ;
F_48 ( V_26 , V_85 ) ;
V_30 = F_49 ( V_26 -> V_82 -> V_30 , 4 ) + 4 ;
V_103 = F_50 ( V_26 -> V_82 , V_30 ) ;
if ( F_29 ( V_103 ) ) {
F_10 ( V_26 -> V_2 -> V_4 , L_9 ) ;
return;
}
V_26 -> V_82 -> V_30 = V_30 ;
}
static int F_51 ( struct V_25 * V_26 )
{
return V_26 -> V_82 -> V_30 ;
}
static void F_52 ( struct V_104 * V_105 )
{
struct V_3 * V_4 =
F_53 ( V_105 , struct V_3 , V_22 ) ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
F_54 ( V_4 ) ;
F_7 (rt2x00dev, queue) {
while ( ! F_55 ( V_2 ) ) {
V_26 = F_8 ( V_2 , V_16 ) ;
if ( F_45 ( V_106 , & V_26 -> V_93 ) )
break;
if ( F_45 ( V_107 , & V_26 -> V_93 ) )
F_56 ( V_26 , V_108 ) ;
else if ( F_57 ( V_26 ) )
F_56 ( V_26 , V_109 ) ;
else
break;
}
}
if ( F_6 ( V_4 ) )
F_15 ( & V_4 -> V_23 , V_24 + F_16 ( 2 ) ) ;
}
static void F_58 ( struct V_25 * V_26 ,
struct V_110 * V_111 )
{
struct V_86 * V_87 = F_43 ( V_26 -> V_82 ) ;
T_4 * V_112 = ( T_4 * ) V_26 -> V_82 -> V_28 ;
T_4 * V_113 ;
T_1 V_89 ;
int V_114 ;
memcpy ( V_87 -> V_100 , V_112 , V_87 -> V_101 ) ;
F_44 ( V_112 , 0 , & V_89 ) ;
V_114 = F_11 ( V_89 , V_115 ) ;
F_59 ( V_26 -> V_82 , V_116 ) ;
V_113 = ( T_4 * ) ( V_26 -> V_82 -> V_28 + V_114 ) ;
F_44 ( V_113 , 0 , & V_89 ) ;
if ( F_11 ( V_89 , V_117 ) )
V_111 -> V_93 |= V_118 ;
V_111 -> V_119 = F_11 ( V_89 , V_120 ) ;
if ( F_11 ( V_89 , V_121 ) ) {
V_111 -> V_93 |= V_122 ;
V_111 -> V_93 |= V_123 ;
if ( V_111 -> V_119 == V_124 )
V_111 -> V_93 |= V_125 ;
else if ( V_111 -> V_119 == V_126 )
V_111 -> V_93 |= V_127 ;
}
if ( F_11 ( V_89 , V_128 ) )
V_111 -> V_129 |= V_130 ;
if ( F_11 ( V_89 , V_131 ) )
V_111 -> V_129 |= V_132 ;
F_60 ( V_26 -> V_82 , V_114 ) ;
F_61 ( V_26 , V_111 ) ;
}
static int F_62 ( struct V_3 * V_4 )
{
if ( F_63 ( V_4 ) )
F_64 ( V_4 ) ;
else
F_65 ( V_4 , V_4 -> V_133 ,
V_134 ) ;
return F_66 ( V_4 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
int V_68 ;
V_68 = F_62 ( V_4 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_68 ( V_4 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_69 ( V_4 ) ;
if ( V_68 )
return V_68 ;
F_70 ( V_135 , & V_4 -> V_136 ) ;
F_70 ( V_137 , & V_4 -> V_136 ) ;
F_70 ( V_138 , & V_4 -> V_136 ) ;
F_70 ( V_139 , & V_4 -> V_136 ) ;
if ( ! V_140 )
F_70 ( V_141 , & V_4 -> V_136 ) ;
F_70 ( V_142 , & V_4 -> V_136 ) ;
F_70 ( V_143 , & V_4 -> V_136 ) ;
F_70 ( V_144 , & V_4 -> V_136 ) ;
F_70 ( V_145 , & V_4 -> V_136 ) ;
F_71 ( & V_4 -> V_23 ,
F_19 ,
( unsigned long ) V_4 ) ;
V_4 -> V_146 = V_147 ;
F_72 ( & V_4 -> V_22 , F_52 ) ;
return 0 ;
}
static int F_73 ( struct V_148 * V_149 ,
const struct V_150 * V_151 )
{
return F_74 ( V_149 , & V_152 ) ;
}
static int T_5 F_75 ( void )
{
return F_76 ( & V_153 ) ;
}
static void T_6 F_77 ( void )
{
F_78 ( & V_153 ) ;
}
