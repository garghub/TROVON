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
static inline bool F_9 ( struct V_17 * V_18 )
{
bool V_19 ;
if ( ! F_10 ( V_20 , & V_18 -> V_21 ) )
return false ;
V_19 = F_11 ( V_22 , V_18 -> V_23 + F_12 ( 100 ) ) ;
if ( F_13 ( V_19 ) )
F_14 ( V_18 -> V_2 -> V_4 ,
L_1 ,
V_18 -> V_24 , V_18 -> V_2 -> V_6 ) ;
return V_19 ;
}
static bool F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 ;
F_7 (rt2x00dev, queue) {
V_18 = F_8 ( V_2 , V_16 ) ;
if ( F_9 ( V_18 ) )
return true ;
}
return false ;
}
static bool F_16 ( struct V_3 * V_4 ,
int V_25 , T_1 V_26 )
{
bool V_27 ;
if ( V_25 ) {
F_14 ( V_4 , L_2 , V_25 ) ;
goto V_28;
}
V_27 = F_17 ( V_26 , V_29 ) ;
if ( V_27 ) {
if ( ! F_18 ( & V_4 -> V_30 , & V_26 ) )
F_14 ( V_4 , L_3 ) ;
F_19 ( V_4 -> V_31 , & V_4 -> V_32 ) ;
return true ;
}
if ( F_15 ( V_4 ) )
F_19 ( V_4 -> V_31 , & V_4 -> V_32 ) ;
if ( F_6 ( V_4 ) ) {
F_20 ( & V_4 -> V_33 , F_21 ( 0 , 250000 ) ,
V_34 ) ;
return false ;
}
V_28:
F_22 ( V_35 , & V_4 -> V_21 ) ;
if ( F_6 ( V_4 ) &&
! F_23 ( V_35 , & V_4 -> V_21 ) )
return true ;
else
return false ;
}
static void F_24 ( struct V_3 * V_4 )
{
if ( F_23 ( V_35 , & V_4 -> V_21 ) )
return;
F_20 ( & V_4 -> V_33 , F_21 ( 0 , 500000 ) ,
V_34 ) ;
}
static void F_25 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_2 -> V_4 ;
F_24 ( V_4 ) ;
}
static enum V_36 F_26 ( struct V_37 * V_38 )
{
struct V_3 * V_4 =
F_27 ( V_38 , struct V_3 , V_33 ) ;
F_28 ( V_4 , V_39 ,
F_16 ) ;
return V_40 ;
}
static char * F_29 ( struct V_3 * V_4 )
{
return V_41 ;
}
static int F_30 ( struct V_3 * V_4 ,
const T_2 * V_42 , const T_3 V_43 )
{
int V_44 ;
T_1 V_45 ;
T_1 V_46 ;
if ( F_31 ( V_4 , V_47 ) ||
F_31 ( V_4 , V_48 ) ||
F_31 ( V_4 , V_49 ) ) {
V_45 = 0 ;
V_46 = 4096 ;
} else {
V_45 = 4096 ;
V_46 = 4096 ;
}
F_32 ( V_4 , V_50 ,
V_42 + V_45 , V_46 ) ;
F_4 ( V_4 , V_51 , ~ 0 ) ;
F_4 ( V_4 , V_52 , ~ 0 ) ;
V_44 = F_33 ( V_4 , V_53 ,
0 , V_54 ,
V_55 ) ;
if ( V_44 < 0 ) {
ERROR ( V_4 , L_4 ) ;
return V_44 ;
}
F_34 ( 10 ) ;
F_4 ( V_4 , V_56 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
T_1 V_5 ;
if ( F_36 ( V_4 ) )
return - V_57 ;
F_2 ( V_4 , V_58 , & V_5 ) ;
F_4 ( V_4 , V_58 , V_5 & ~ 0x00002000 ) ;
V_5 = 0 ;
F_3 ( & V_5 , V_59 , 1 ) ;
F_3 ( & V_5 , V_60 , 1 ) ;
F_4 ( V_4 , V_8 , V_5 ) ;
F_4 ( V_4 , V_61 , 0x00000000 ) ;
F_33 ( V_4 , V_53 , 0 ,
V_62 , V_63 ) ;
F_4 ( V_4 , V_8 , 0x00000000 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 )
{
T_1 V_5 ;
if ( F_13 ( F_38 ( V_4 ) ) )
return - V_64 ;
F_2 ( V_4 , V_61 , & V_5 ) ;
F_3 ( & V_5 , V_65 , 0 ) ;
F_3 ( & V_5 , V_66 , 0 ) ;
F_3 ( & V_5 , V_67 , 128 ) ;
F_3 ( & V_5 , V_68 ,
( ( V_4 -> V_69 -> V_70 -> V_71 * V_72 )
/ 1024 ) - 3 ) ;
F_3 ( & V_5 , V_73 , 1 ) ;
F_3 ( & V_5 , V_74 , 1 ) ;
F_4 ( V_4 , V_61 , V_5 ) ;
return F_39 ( V_4 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
F_41 ( V_4 ) ;
F_42 ( V_4 ) ;
}
static int F_43 ( struct V_3 * V_4 ,
enum V_75 V_76 )
{
if ( V_76 == V_77 )
F_44 ( V_4 , V_78 , 0xff , 0 , 2 ) ;
else
F_44 ( V_4 , V_79 , 0xff , 0xff , 2 ) ;
return 0 ;
}
static int F_45 ( struct V_3 * V_4 ,
enum V_75 V_76 )
{
int V_80 = 0 ;
switch ( V_76 ) {
case V_81 :
F_43 ( V_4 , V_77 ) ;
F_34 ( 1 ) ;
V_80 = F_37 ( V_4 ) ;
break;
case V_82 :
F_40 ( V_4 ) ;
F_43 ( V_4 , V_83 ) ;
break;
case V_84 :
case V_85 :
break;
case V_86 :
case V_83 :
case V_87 :
case V_77 :
V_80 = F_43 ( V_4 , V_76 ) ;
break;
default:
V_80 = - V_88 ;
break;
}
if ( F_13 ( V_80 ) )
ERROR ( V_4 , L_5 ,
V_76 , V_80 ) ;
return V_80 ;
}
static void F_46 ( struct V_3 * V_4 )
{
unsigned int V_89 ;
T_1 V_5 ;
F_2 ( V_4 , V_90 , & V_5 ) ;
if ( F_17 ( V_5 , V_91 ) ) {
F_14 ( V_4 , L_6
L_7 ) ;
F_4 ( V_4 , V_92 , 0xf40012 ) ;
for ( V_89 = 0 ; V_89 < 10 ; V_89 ++ ) {
F_47 ( 10 ) ;
if ( ! F_17 ( V_5 , V_91 ) )
break;
}
F_4 ( V_4 , V_92 , 0xf40006 ) ;
}
F_2 ( V_4 , V_90 , & V_5 ) ;
if ( F_17 ( V_5 , V_93 ) ) {
F_14 ( V_4 , L_8
L_7 ) ;
F_4 ( V_4 , V_92 , 0xf4000a ) ;
for ( V_89 = 0 ; V_89 < 10 ; V_89 ++ ) {
F_47 ( 10 ) ;
if ( ! F_17 ( V_5 , V_93 ) )
break;
}
F_4 ( V_4 , V_92 , 0xf40006 ) ;
}
F_48 ( V_4 ) ;
}
static T_4 * F_49 ( struct V_17 * V_18 )
{
if ( V_18 -> V_2 -> V_6 == V_10 )
return ( T_4 * ) ( V_18 -> V_94 -> V_42 ) ;
else
return ( T_4 * ) ( V_18 -> V_94 -> V_42 + V_95 ) ;
}
static void F_50 ( struct V_17 * V_18 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = F_51 ( V_18 -> V_94 ) ;
T_4 * V_100 = ( T_4 * ) V_18 -> V_94 -> V_42 ;
T_1 V_101 ;
F_52 ( V_100 , 0 , & V_101 ) ;
F_3 ( & V_101 , V_102 ,
F_53 ( V_18 -> V_94 -> V_43 , 4 ) - V_95 ) ;
F_3 ( & V_101 , V_103 ,
! F_10 ( V_104 , & V_97 -> V_21 ) ) ;
F_3 ( & V_101 , V_105 , 2 ) ;
F_3 ( & V_101 , V_106 , 0 ) ;
F_3 ( & V_101 , V_107 , 0 ) ;
F_3 ( & V_101 , V_108 ,
F_10 ( V_109 , & V_97 -> V_21 ) ) ;
F_54 ( V_100 , 0 , V_101 ) ;
V_99 -> V_21 |= V_110 ;
V_99 -> V_111 = V_100 ;
V_99 -> V_112 = V_95 + V_113 ;
}
static int F_55 ( struct V_17 * V_18 )
{
return F_53 ( V_18 -> V_94 -> V_43 , 4 ) + 4 ;
}
static enum V_114
F_56 ( struct V_17 * V_18 , T_1 V_5 )
{
T_4 * V_115 ;
T_1 V_101 ;
int V_116 , V_117 , V_118 ;
int V_119 , V_120 , V_121 , V_122 ;
if ( F_10 ( V_123 , & V_18 -> V_21 ) )
return V_124 ;
V_116 = F_17 ( V_5 , V_125 ) ;
V_117 = F_17 ( V_5 , V_126 ) ;
V_118 = F_17 ( V_5 , V_127 ) ;
V_122 = F_17 ( V_5 , V_128 ) ;
V_115 = F_49 ( V_18 ) ;
F_52 ( V_115 , 1 , & V_101 ) ;
V_119 = F_17 ( V_101 , V_129 ) ;
V_120 = F_17 ( V_101 , V_130 ) ;
V_121 = F_17 ( V_101 , V_131 ) ;
if ( V_116 != V_119 || V_117 != V_120 || ( ! V_122 && V_118 != V_121 ) ) {
F_14 ( V_18 -> V_2 -> V_4 ,
L_9 ,
V_18 -> V_2 -> V_6 , V_18 -> V_24 ) ;
return V_132 ;
}
return V_133 ;
}
static void F_57 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_1 V_5 ;
T_2 V_6 ;
enum V_114 V_134 ;
while ( F_58 ( & V_4 -> V_30 , & V_5 ) ) {
V_6 = F_17 ( V_5 , V_135 ) ;
V_2 = F_59 ( V_4 , V_6 ) ;
if ( F_13 ( F_60 ( V_2 ) ) ) {
F_14 ( V_4 , L_10
L_11 , V_6 ) ;
break;
}
V_18 = F_8 ( V_2 , V_16 ) ;
if ( F_13 ( F_10 ( V_136 , & V_18 -> V_21 ) ||
! F_10 ( V_20 , & V_18 -> V_21 ) ) ) {
F_14 ( V_4 , L_12
L_13 , V_18 -> V_24 , V_6 ) ;
break;
}
V_134 = F_56 ( V_18 , V_5 ) ;
if ( F_61 ( V_134 == V_133 ) )
F_62 ( V_18 , V_5 , F_49 ( V_18 ) ) ;
else
F_63 ( V_18 , V_134 ) ;
}
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 ;
F_7 (rt2x00dev, queue) {
while ( ! F_60 ( V_2 ) ) {
V_18 = F_8 ( V_2 , V_16 ) ;
if ( F_10 ( V_136 , & V_18 -> V_21 ) ||
! F_10 ( V_20 , & V_18 -> V_21 ) )
break;
if ( F_10 ( V_123 , & V_18 -> V_21 ) )
F_63 ( V_18 , V_124 ) ;
else if ( F_9 ( V_18 ) )
F_63 ( V_18 , V_132 ) ;
else
break;
}
}
}
static void F_65 ( struct V_137 * V_138 )
{
struct V_3 * V_4 =
F_27 ( V_138 , struct V_3 , V_32 ) ;
while ( ! F_66 ( & V_4 -> V_30 ) ||
F_15 ( V_4 ) ) {
F_57 ( V_4 ) ;
F_64 ( V_4 ) ;
if ( F_6 ( V_4 ) )
F_24 ( V_4 ) ;
}
}
static void F_67 ( struct V_17 * V_18 ,
struct V_139 * V_140 )
{
struct V_98 * V_99 = F_51 ( V_18 -> V_94 ) ;
T_4 * V_141 = ( T_4 * ) V_18 -> V_94 -> V_42 ;
T_4 * V_142 ;
T_1 V_101 ;
int V_143 ;
memcpy ( V_99 -> V_111 , V_141 , V_99 -> V_112 ) ;
F_52 ( V_141 , 0 , & V_101 ) ;
V_143 = F_17 ( V_101 , V_144 ) ;
F_68 ( V_18 -> V_94 , V_145 ) ;
V_142 = ( T_4 * ) ( V_18 -> V_94 -> V_42 + V_143 ) ;
F_52 ( V_142 , 0 , & V_101 ) ;
if ( F_17 ( V_101 , V_146 ) )
V_140 -> V_21 |= V_147 ;
V_140 -> V_148 = F_17 ( V_101 , V_149 ) ;
if ( F_17 ( V_101 , V_150 ) ) {
V_140 -> V_21 |= V_151 ;
V_140 -> V_21 |= V_152 ;
if ( V_140 -> V_148 == V_153 )
V_140 -> V_21 |= V_154 ;
else if ( V_140 -> V_148 == V_155 )
V_140 -> V_21 |= V_156 ;
}
if ( F_17 ( V_101 , V_157 ) )
V_140 -> V_158 |= V_159 ;
if ( F_17 ( V_101 , V_160 ) )
V_140 -> V_158 |= V_161 ;
F_69 ( V_18 -> V_94 , V_143 ) ;
F_70 ( V_18 , V_140 ) ;
}
static int F_71 ( struct V_3 * V_4 )
{
if ( F_72 ( V_4 ) )
F_73 ( V_4 ) ;
else
F_74 ( V_4 , V_4 -> V_162 ,
V_163 ) ;
return F_75 ( V_4 ) ;
}
static int F_76 ( struct V_3 * V_4 )
{
int V_80 ;
V_80 = F_71 ( V_4 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_77 ( V_4 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_78 ( V_4 ) ;
if ( V_80 )
return V_80 ;
F_79 ( V_164 , & V_4 -> V_165 ) ;
F_79 ( V_166 , & V_4 -> V_165 ) ;
F_79 ( V_167 , & V_4 -> V_165 ) ;
F_79 ( V_168 , & V_4 -> V_165 ) ;
if ( ! V_169 )
F_79 ( V_170 , & V_4 -> V_165 ) ;
F_79 ( V_171 , & V_4 -> V_165 ) ;
F_79 ( V_172 , & V_4 -> V_165 ) ;
F_79 ( V_173 , & V_4 -> V_165 ) ;
F_79 ( V_174 , & V_4 -> V_165 ) ;
V_4 -> V_33 . V_175 = F_26 ,
V_4 -> V_176 = V_177 ;
F_80 ( & V_4 -> V_32 , F_65 ) ;
return 0 ;
}
static int F_81 ( struct V_178 * V_179 ,
const struct V_180 * V_181 )
{
return F_82 ( V_179 , & V_182 ) ;
}
