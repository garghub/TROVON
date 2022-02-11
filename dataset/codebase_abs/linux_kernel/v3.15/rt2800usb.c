static bool F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_1 V_6 ;
switch ( V_5 -> V_7 ) {
case V_8 :
F_3 ( V_2 , V_9 , & V_6 ) ;
F_4 ( & V_6 , V_10 , 1 ) ;
F_5 ( V_2 , V_9 , V_6 ) ;
break;
case V_11 :
F_3 ( V_2 , V_12 , & V_6 ) ;
F_4 ( & V_6 , V_13 , 1 ) ;
F_4 ( & V_6 , V_14 , 1 ) ;
F_4 ( & V_6 , V_15 , 1 ) ;
F_5 ( V_2 , V_12 , V_6 ) ;
break;
default:
break;
}
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_1 V_6 ;
switch ( V_5 -> V_7 ) {
case V_8 :
F_3 ( V_2 , V_9 , & V_6 ) ;
F_4 ( & V_6 , V_10 , 0 ) ;
F_5 ( V_2 , V_9 , V_6 ) ;
break;
case V_11 :
F_3 ( V_2 , V_12 , & V_6 ) ;
F_4 ( & V_6 , V_13 , 0 ) ;
F_4 ( & V_6 , V_14 , 0 ) ;
F_4 ( & V_6 , V_15 , 0 ) ;
F_5 ( V_2 , V_12 , V_6 ) ;
break;
default:
break;
}
}
static bool F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_8 (rt2x00dev, queue) {
if ( F_9 ( V_5 , V_16 ) !=
F_9 ( V_5 , V_17 ) )
return true ;
}
return false ;
}
static inline bool F_10 ( struct V_18 * V_19 )
{
bool V_20 ;
if ( ! F_11 ( V_21 , & V_19 -> V_22 ) )
return false ;
V_20 = F_12 ( V_23 , V_19 -> V_24 + F_13 ( 100 ) ) ;
if ( F_14 ( V_20 ) )
F_15 ( V_19 -> V_5 -> V_2 ,
L_1 ,
V_19 -> V_25 , V_19 -> V_5 -> V_7 ) ;
return V_20 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
F_8 (rt2x00dev, queue) {
V_19 = F_9 ( V_5 , V_17 ) ;
if ( F_10 ( V_19 ) )
return true ;
}
return false ;
}
static bool F_17 ( struct V_1 * V_2 ,
int V_26 , T_1 V_27 )
{
bool V_28 ;
if ( V_26 ) {
F_18 ( V_2 , L_2 ,
V_26 ) ;
goto V_29;
}
V_28 = F_19 ( V_27 , V_30 ) ;
if ( V_28 ) {
if ( ! F_20 ( & V_2 -> V_31 , V_27 ) )
F_18 ( V_2 , L_3 ) ;
F_21 ( V_2 -> V_32 , & V_2 -> V_33 ) ;
return true ;
}
if ( F_16 ( V_2 ) )
F_21 ( V_2 -> V_32 , & V_2 -> V_33 ) ;
if ( F_7 ( V_2 ) ) {
F_22 ( & V_2 -> V_34 ,
F_23 ( 0 , V_35 ) ,
V_36 ) ;
return false ;
}
V_29:
F_24 ( V_37 , & V_2 -> V_22 ) ;
if ( F_7 ( V_2 ) &&
! F_25 ( V_37 , & V_2 -> V_22 ) )
return true ;
else
return false ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( F_25 ( V_37 , & V_2 -> V_22 ) )
return;
F_22 ( & V_2 -> V_34 ,
F_23 ( 0 , 2 * V_35 ) ,
V_36 ) ;
}
static void F_27 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_5 -> V_2 ;
F_26 ( V_2 ) ;
}
static enum V_38 F_28 ( struct V_39 * V_40 )
{
struct V_1 * V_2 =
F_29 ( V_40 , struct V_1 , V_34 ) ;
F_30 ( V_2 , V_41 ,
F_17 ) ;
return V_42 ;
}
static char * F_31 ( struct V_1 * V_2 )
{
return V_43 ;
}
static int F_32 ( struct V_1 * V_2 ,
const T_2 * V_44 , const T_3 V_45 )
{
int V_46 ;
T_1 V_47 ;
T_1 V_48 ;
if ( F_33 ( V_2 , V_49 ) ||
F_33 ( V_2 , V_50 ) ||
F_33 ( V_2 , V_51 ) ) {
V_47 = 0 ;
V_48 = 4096 ;
} else {
V_47 = 4096 ;
V_48 = 4096 ;
}
F_34 ( V_2 , V_52 ,
V_44 + V_47 , V_48 ) ;
F_5 ( V_2 , V_53 , ~ 0 ) ;
F_5 ( V_2 , V_54 , ~ 0 ) ;
V_46 = F_35 ( V_2 , V_55 ,
0 , V_56 ,
V_57 ) ;
if ( V_46 < 0 ) {
F_36 ( V_2 , L_4 ) ;
return V_46 ;
}
F_37 ( 10 ) ;
F_5 ( V_2 , V_58 , 0 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_6 ;
if ( F_39 ( V_2 ) )
return - V_59 ;
F_3 ( V_2 , V_60 , & V_6 ) ;
F_5 ( V_2 , V_60 , V_6 & ~ 0x00002000 ) ;
V_6 = 0 ;
F_4 ( & V_6 , V_61 , 1 ) ;
F_4 ( & V_6 , V_62 , 1 ) ;
F_5 ( V_2 , V_9 , V_6 ) ;
F_5 ( V_2 , V_63 , 0x00000000 ) ;
F_35 ( V_2 , V_55 , 0 ,
V_64 , V_65 ) ;
F_5 ( V_2 , V_9 , 0x00000000 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_6 ;
if ( F_14 ( F_41 ( V_2 ) ) )
return - V_66 ;
F_3 ( V_2 , V_63 , & V_6 ) ;
F_4 ( & V_6 , V_67 , 0 ) ;
F_4 ( & V_6 , V_68 , 0 ) ;
F_4 ( & V_6 , V_69 , 128 ) ;
F_4 ( & V_6 , V_70 ,
( ( V_2 -> V_71 -> V_72 * V_73 )
/ 1024 ) - 3 ) ;
F_4 ( & V_6 , V_74 , 1 ) ;
F_4 ( & V_6 , V_75 , 1 ) ;
F_5 ( V_2 , V_63 , V_6 ) ;
return F_42 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
enum V_76 V_77 )
{
if ( V_77 == V_78 )
F_47 ( V_2 , V_79 , 0xff , 0 , 2 ) ;
else
F_47 ( V_2 , V_80 , 0xff , 0xff , 2 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
enum V_76 V_77 )
{
int V_81 = 0 ;
switch ( V_77 ) {
case V_82 :
F_46 ( V_2 , V_78 ) ;
F_37 ( 1 ) ;
V_81 = F_40 ( V_2 ) ;
break;
case V_83 :
F_43 ( V_2 ) ;
F_46 ( V_2 , V_84 ) ;
break;
case V_85 :
case V_86 :
break;
case V_87 :
case V_84 :
case V_88 :
case V_78 :
V_81 = F_46 ( V_2 , V_77 ) ;
break;
default:
V_81 = - V_89 ;
break;
}
if ( F_14 ( V_81 ) )
F_36 ( V_2 , L_5 ,
V_77 , V_81 ) ;
return V_81 ;
}
static void F_49 ( struct V_1 * V_2 )
{
unsigned int V_90 ;
T_1 V_6 ;
F_3 ( V_2 , V_91 , & V_6 ) ;
if ( F_19 ( V_6 , V_92 ) ) {
F_18 ( V_2 , L_6 ) ;
F_5 ( V_2 , V_93 , 0xf40012 ) ;
for ( V_90 = 0 ; V_90 < 10 ; V_90 ++ ) {
F_50 ( 10 ) ;
if ( ! F_19 ( V_6 , V_92 ) )
break;
}
F_5 ( V_2 , V_93 , 0xf40006 ) ;
}
F_3 ( V_2 , V_91 , & V_6 ) ;
if ( F_19 ( V_6 , V_94 ) ) {
F_18 ( V_2 , L_7 ) ;
F_5 ( V_2 , V_93 , 0xf4000a ) ;
for ( V_90 = 0 ; V_90 < 10 ; V_90 ++ ) {
F_50 ( 10 ) ;
if ( ! F_19 ( V_6 , V_94 ) )
break;
}
F_5 ( V_2 , V_93 , 0xf40006 ) ;
}
F_51 ( V_2 ) ;
}
static T_4 * F_52 ( struct V_18 * V_19 )
{
if ( V_19 -> V_5 -> V_7 == V_11 )
return ( T_4 * ) ( V_19 -> V_95 -> V_44 ) ;
else
return ( T_4 * ) ( V_19 -> V_95 -> V_44 + V_96 ) ;
}
static void F_53 ( struct V_18 * V_19 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 = F_54 ( V_19 -> V_95 ) ;
T_4 * V_101 = ( T_4 * ) V_19 -> V_95 -> V_44 ;
T_1 V_102 ;
F_55 ( V_101 , 0 , & V_102 ) ;
F_4 ( & V_102 , V_103 ,
F_56 ( V_19 -> V_95 -> V_45 , 4 ) - V_96 ) ;
F_4 ( & V_102 , V_104 ,
! F_11 ( V_105 , & V_98 -> V_22 ) ) ;
F_4 ( & V_102 , V_106 , 2 ) ;
F_4 ( & V_102 , V_107 , 0 ) ;
F_4 ( & V_102 , V_108 , 0 ) ;
F_4 ( & V_102 , V_109 ,
F_11 ( V_110 , & V_98 -> V_22 ) ) ;
F_57 ( V_101 , 0 , V_102 ) ;
V_100 -> V_22 |= V_111 ;
V_100 -> V_112 = V_101 ;
V_100 -> V_113 = V_96 + V_19 -> V_5 -> V_114 ;
}
static int F_58 ( struct V_18 * V_19 )
{
return F_56 ( V_19 -> V_95 -> V_45 , 4 ) + 4 ;
}
static enum V_115
F_59 ( struct V_18 * V_19 , T_1 V_6 )
{
T_4 * V_116 ;
T_1 V_102 ;
int V_117 , V_118 , V_119 ;
int V_120 , V_121 , V_122 , V_123 ;
if ( F_11 ( V_124 , & V_19 -> V_22 ) )
return V_125 ;
V_117 = F_19 ( V_6 , V_126 ) ;
V_118 = F_19 ( V_6 , V_127 ) ;
V_119 = F_19 ( V_6 , V_128 ) ;
V_123 = F_19 ( V_6 , V_129 ) ;
V_116 = F_52 ( V_19 ) ;
F_55 ( V_116 , 1 , & V_102 ) ;
V_120 = F_19 ( V_102 , V_130 ) ;
V_121 = F_19 ( V_102 , V_131 ) ;
V_122 = F_19 ( V_102 , V_132 ) ;
if ( V_117 != V_120 || V_118 != V_121 || ( ! V_123 && V_119 != V_122 ) ) {
F_15 ( V_19 -> V_5 -> V_2 ,
L_8 ,
V_19 -> V_5 -> V_7 , V_19 -> V_25 ) ;
return V_133 ;
}
return V_134 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
T_1 V_6 ;
T_2 V_7 ;
enum V_115 V_135 ;
while ( F_61 ( & V_2 -> V_31 , & V_6 ) ) {
V_7 = F_19 ( V_6 , V_136 ) ;
V_5 = F_62 ( V_2 , V_7 ) ;
if ( F_14 ( F_63 ( V_5 ) ) ) {
F_15 ( V_2 , L_9 ,
V_7 ) ;
break;
}
V_19 = F_9 ( V_5 , V_17 ) ;
if ( F_14 ( F_11 ( V_137 , & V_19 -> V_22 ) ||
! F_11 ( V_21 , & V_19 -> V_22 ) ) ) {
F_18 ( V_2 , L_10 ,
V_19 -> V_25 , V_7 ) ;
break;
}
V_135 = F_59 ( V_19 , V_6 ) ;
if ( F_64 ( V_135 == V_134 ) )
F_65 ( V_19 , V_6 , F_52 ( V_19 ) ) ;
else
F_66 ( V_19 , V_135 ) ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
F_8 (rt2x00dev, queue) {
while ( ! F_63 ( V_5 ) ) {
V_19 = F_9 ( V_5 , V_17 ) ;
if ( F_11 ( V_137 , & V_19 -> V_22 ) ||
! F_11 ( V_21 , & V_19 -> V_22 ) )
break;
if ( F_11 ( V_124 , & V_19 -> V_22 ) )
F_66 ( V_19 , V_125 ) ;
else if ( F_10 ( V_19 ) )
F_66 ( V_19 , V_133 ) ;
else
break;
}
}
}
static void F_68 ( struct V_138 * V_139 )
{
struct V_1 * V_2 =
F_29 ( V_139 , struct V_1 , V_33 ) ;
while ( ! F_69 ( & V_2 -> V_31 ) ||
F_16 ( V_2 ) ) {
F_60 ( V_2 ) ;
F_67 ( V_2 ) ;
if ( F_7 ( V_2 ) )
F_26 ( V_2 ) ;
}
}
static void F_70 ( struct V_18 * V_19 ,
struct V_140 * V_141 )
{
struct V_99 * V_100 = F_54 ( V_19 -> V_95 ) ;
T_4 * V_142 = ( T_4 * ) V_19 -> V_95 -> V_44 ;
T_4 * V_143 ;
T_1 V_102 ;
int V_144 ;
memcpy ( V_100 -> V_112 , V_142 , V_100 -> V_113 ) ;
F_55 ( V_142 , 0 , & V_102 ) ;
V_144 = F_19 ( V_102 , V_145 ) ;
F_71 ( V_19 -> V_95 , V_146 ) ;
if ( F_14 ( V_144 == 0 ||
V_144 > V_19 -> V_5 -> V_147 ) ) {
F_36 ( V_19 -> V_5 -> V_2 ,
L_11 , V_144 ) ;
return;
}
V_143 = ( T_4 * ) ( V_19 -> V_95 -> V_44 + V_144 ) ;
F_55 ( V_143 , 0 , & V_102 ) ;
if ( F_19 ( V_102 , V_148 ) )
V_141 -> V_22 |= V_149 ;
V_141 -> V_150 = F_19 ( V_102 , V_151 ) ;
if ( F_19 ( V_102 , V_152 ) ) {
V_141 -> V_22 |= V_153 ;
V_141 -> V_22 |= V_154 ;
if ( V_141 -> V_150 == V_155 )
V_141 -> V_22 |= V_156 ;
else if ( V_141 -> V_150 == V_157 )
V_141 -> V_22 |= V_158 ;
}
if ( F_19 ( V_102 , V_159 ) )
V_141 -> V_160 |= V_161 ;
if ( F_19 ( V_102 , V_162 ) )
V_141 -> V_160 |= V_163 ;
F_72 ( V_19 -> V_95 , V_144 ) ;
F_73 ( V_19 , V_141 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_81 ;
if ( F_75 ( V_2 ) )
V_81 = F_76 ( V_2 ) ;
else
V_81 = F_77 ( V_2 , V_2 -> V_164 ,
V_165 ) ;
return V_81 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_81 ;
V_81 = F_79 ( V_2 ) ;
if ( V_81 )
return V_81 ;
V_2 -> V_34 . V_166 = F_28 ;
F_80 ( & V_2 -> V_33 , F_68 ) ;
return 0 ;
}
static void F_81 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
unsigned short V_167 , V_168 ;
F_82 ( V_2 , & V_167 , & V_168 ) ;
switch ( V_5 -> V_7 ) {
case V_8 :
V_5 -> V_72 = 128 ;
V_5 -> V_147 = V_169 ;
V_5 -> V_170 = V_146 ;
V_5 -> V_114 = V_168 ;
V_5 -> V_171 = sizeof( struct V_172 ) ;
break;
case V_173 :
case V_174 :
case V_175 :
case V_176 :
V_5 -> V_72 = 16 ;
V_5 -> V_147 = V_169 ;
V_5 -> V_170 = V_96 ;
V_5 -> V_114 = V_167 ;
V_5 -> V_171 = sizeof( struct V_172 ) ;
break;
case V_11 :
V_5 -> V_72 = 8 ;
V_5 -> V_147 = V_177 ;
V_5 -> V_170 = V_96 ;
V_5 -> V_114 = V_167 ;
V_5 -> V_171 = sizeof( struct V_172 ) ;
break;
case V_178 :
default:
F_83 () ;
break;
}
}
static int F_84 ( struct V_179 * V_180 ,
const struct V_181 * V_182 )
{
return F_85 ( V_180 , & V_183 ) ;
}
