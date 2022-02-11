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
F_15 ( V_2 , L_2 ,
V_26 ) ;
goto V_29;
}
V_28 = F_18 ( V_27 , V_30 ) ;
if ( V_28 ) {
if ( ! F_19 ( & V_2 -> V_31 , & V_27 ) )
F_15 ( V_2 , L_3 ) ;
F_20 ( V_2 -> V_32 , & V_2 -> V_33 ) ;
return true ;
}
if ( F_16 ( V_2 ) )
F_20 ( V_2 -> V_32 , & V_2 -> V_33 ) ;
if ( F_7 ( V_2 ) ) {
F_21 ( & V_2 -> V_34 , F_22 ( 0 , 250000 ) ,
V_35 ) ;
return false ;
}
V_29:
F_23 ( V_36 , & V_2 -> V_22 ) ;
if ( F_7 ( V_2 ) &&
! F_24 ( V_36 , & V_2 -> V_22 ) )
return true ;
else
return false ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( F_24 ( V_36 , & V_2 -> V_22 ) )
return;
F_21 ( & V_2 -> V_34 , F_22 ( 0 , 500000 ) ,
V_35 ) ;
}
static void F_26 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_5 -> V_2 ;
F_25 ( V_2 ) ;
}
static enum V_37 F_27 ( struct V_38 * V_39 )
{
struct V_1 * V_2 =
F_28 ( V_39 , struct V_1 , V_34 ) ;
F_29 ( V_2 , V_40 ,
F_17 ) ;
return V_41 ;
}
static char * F_30 ( struct V_1 * V_2 )
{
return V_42 ;
}
static int F_31 ( struct V_1 * V_2 ,
const T_2 * V_43 , const T_3 V_44 )
{
int V_45 ;
T_1 V_46 ;
T_1 V_47 ;
if ( F_32 ( V_2 , V_48 ) ||
F_32 ( V_2 , V_49 ) ||
F_32 ( V_2 , V_50 ) ) {
V_46 = 0 ;
V_47 = 4096 ;
} else {
V_46 = 4096 ;
V_47 = 4096 ;
}
F_33 ( V_2 , V_51 ,
V_43 + V_46 , V_47 ) ;
F_5 ( V_2 , V_52 , ~ 0 ) ;
F_5 ( V_2 , V_53 , ~ 0 ) ;
V_45 = F_34 ( V_2 , V_54 ,
0 , V_55 ,
V_56 ) ;
if ( V_45 < 0 ) {
F_35 ( V_2 , L_4 ) ;
return V_45 ;
}
F_36 ( 10 ) ;
F_5 ( V_2 , V_57 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_1 V_6 ;
if ( F_38 ( V_2 ) )
return - V_58 ;
F_3 ( V_2 , V_59 , & V_6 ) ;
F_5 ( V_2 , V_59 , V_6 & ~ 0x00002000 ) ;
V_6 = 0 ;
F_4 ( & V_6 , V_60 , 1 ) ;
F_4 ( & V_6 , V_61 , 1 ) ;
F_5 ( V_2 , V_9 , V_6 ) ;
F_5 ( V_2 , V_62 , 0x00000000 ) ;
F_34 ( V_2 , V_54 , 0 ,
V_63 , V_64 ) ;
F_5 ( V_2 , V_9 , 0x00000000 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
T_1 V_6 ;
if ( F_14 ( F_40 ( V_2 ) ) )
return - V_65 ;
F_3 ( V_2 , V_62 , & V_6 ) ;
F_4 ( & V_6 , V_66 , 0 ) ;
F_4 ( & V_6 , V_67 , 0 ) ;
F_4 ( & V_6 , V_68 , 128 ) ;
F_4 ( & V_6 , V_69 ,
( ( V_2 -> V_70 -> V_71 * V_72 )
/ 1024 ) - 3 ) ;
F_4 ( & V_6 , V_73 , 1 ) ;
F_4 ( & V_6 , V_74 , 1 ) ;
F_5 ( V_2 , V_62 , V_6 ) ;
return F_41 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
enum V_75 V_76 )
{
if ( V_76 == V_77 )
F_46 ( V_2 , V_78 , 0xff , 0 , 2 ) ;
else
F_46 ( V_2 , V_79 , 0xff , 0xff , 2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
enum V_75 V_76 )
{
int V_80 = 0 ;
switch ( V_76 ) {
case V_81 :
F_45 ( V_2 , V_77 ) ;
F_36 ( 1 ) ;
V_80 = F_39 ( V_2 ) ;
break;
case V_82 :
F_42 ( V_2 ) ;
F_45 ( V_2 , V_83 ) ;
break;
case V_84 :
case V_85 :
break;
case V_86 :
case V_83 :
case V_87 :
case V_77 :
V_80 = F_45 ( V_2 , V_76 ) ;
break;
default:
V_80 = - V_88 ;
break;
}
if ( F_14 ( V_80 ) )
F_35 ( V_2 , L_5 ,
V_76 , V_80 ) ;
return V_80 ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned int V_89 ;
T_1 V_6 ;
F_3 ( V_2 , V_90 , & V_6 ) ;
if ( F_18 ( V_6 , V_91 ) ) {
F_15 ( V_2 , L_6 ) ;
F_5 ( V_2 , V_92 , 0xf40012 ) ;
for ( V_89 = 0 ; V_89 < 10 ; V_89 ++ ) {
F_49 ( 10 ) ;
if ( ! F_18 ( V_6 , V_91 ) )
break;
}
F_5 ( V_2 , V_92 , 0xf40006 ) ;
}
F_3 ( V_2 , V_90 , & V_6 ) ;
if ( F_18 ( V_6 , V_93 ) ) {
F_15 ( V_2 , L_7 ) ;
F_5 ( V_2 , V_92 , 0xf4000a ) ;
for ( V_89 = 0 ; V_89 < 10 ; V_89 ++ ) {
F_49 ( 10 ) ;
if ( ! F_18 ( V_6 , V_93 ) )
break;
}
F_5 ( V_2 , V_92 , 0xf40006 ) ;
}
F_50 ( V_2 ) ;
}
static T_4 * F_51 ( struct V_18 * V_19 )
{
if ( V_19 -> V_5 -> V_7 == V_11 )
return ( T_4 * ) ( V_19 -> V_94 -> V_43 ) ;
else
return ( T_4 * ) ( V_19 -> V_94 -> V_43 + V_95 ) ;
}
static void F_52 ( struct V_18 * V_19 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = F_53 ( V_19 -> V_94 ) ;
T_4 * V_100 = ( T_4 * ) V_19 -> V_94 -> V_43 ;
T_1 V_101 ;
F_54 ( V_100 , 0 , & V_101 ) ;
F_4 ( & V_101 , V_102 ,
F_55 ( V_19 -> V_94 -> V_44 , 4 ) - V_95 ) ;
F_4 ( & V_101 , V_103 ,
! F_11 ( V_104 , & V_97 -> V_22 ) ) ;
F_4 ( & V_101 , V_105 , 2 ) ;
F_4 ( & V_101 , V_106 , 0 ) ;
F_4 ( & V_101 , V_107 , 0 ) ;
F_4 ( & V_101 , V_108 ,
F_11 ( V_109 , & V_97 -> V_22 ) ) ;
F_56 ( V_100 , 0 , V_101 ) ;
V_99 -> V_22 |= V_110 ;
V_99 -> V_111 = V_100 ;
V_99 -> V_112 = V_95 + V_19 -> V_5 -> V_113 ;
}
static int F_57 ( struct V_18 * V_19 )
{
return F_55 ( V_19 -> V_94 -> V_44 , 4 ) + 4 ;
}
static enum V_114
F_58 ( struct V_18 * V_19 , T_1 V_6 )
{
T_4 * V_115 ;
T_1 V_101 ;
int V_116 , V_117 , V_118 ;
int V_119 , V_120 , V_121 , V_122 ;
if ( F_11 ( V_123 , & V_19 -> V_22 ) )
return V_124 ;
V_116 = F_18 ( V_6 , V_125 ) ;
V_117 = F_18 ( V_6 , V_126 ) ;
V_118 = F_18 ( V_6 , V_127 ) ;
V_122 = F_18 ( V_6 , V_128 ) ;
V_115 = F_51 ( V_19 ) ;
F_54 ( V_115 , 1 , & V_101 ) ;
V_119 = F_18 ( V_101 , V_129 ) ;
V_120 = F_18 ( V_101 , V_130 ) ;
V_121 = F_18 ( V_101 , V_131 ) ;
if ( V_116 != V_119 || V_117 != V_120 || ( ! V_122 && V_118 != V_121 ) ) {
F_59 ( V_19 -> V_5 -> V_2 ,
L_8 ,
V_19 -> V_5 -> V_7 , V_19 -> V_25 ) ;
return V_132 ;
}
return V_133 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
T_1 V_6 ;
T_2 V_7 ;
enum V_114 V_134 ;
while ( F_61 ( & V_2 -> V_31 , & V_6 ) ) {
V_7 = F_18 ( V_6 , V_135 ) ;
V_5 = F_62 ( V_2 , V_7 ) ;
if ( F_14 ( F_63 ( V_5 ) ) ) {
F_15 ( V_2 , L_9 ,
V_7 ) ;
break;
}
V_19 = F_9 ( V_5 , V_17 ) ;
if ( F_14 ( F_11 ( V_136 , & V_19 -> V_22 ) ||
! F_11 ( V_21 , & V_19 -> V_22 ) ) ) {
F_15 ( V_2 , L_10 ,
V_19 -> V_25 , V_7 ) ;
break;
}
V_134 = F_58 ( V_19 , V_6 ) ;
if ( F_64 ( V_134 == V_133 ) )
F_65 ( V_19 , V_6 , F_51 ( V_19 ) ) ;
else
F_66 ( V_19 , V_134 ) ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
F_8 (rt2x00dev, queue) {
while ( ! F_63 ( V_5 ) ) {
V_19 = F_9 ( V_5 , V_17 ) ;
if ( F_11 ( V_136 , & V_19 -> V_22 ) ||
! F_11 ( V_21 , & V_19 -> V_22 ) )
break;
if ( F_11 ( V_123 , & V_19 -> V_22 ) )
F_66 ( V_19 , V_124 ) ;
else if ( F_10 ( V_19 ) )
F_66 ( V_19 , V_132 ) ;
else
break;
}
}
}
static void F_68 ( struct V_137 * V_138 )
{
struct V_1 * V_2 =
F_28 ( V_138 , struct V_1 , V_33 ) ;
while ( ! F_69 ( & V_2 -> V_31 ) ||
F_16 ( V_2 ) ) {
F_60 ( V_2 ) ;
F_67 ( V_2 ) ;
if ( F_7 ( V_2 ) )
F_25 ( V_2 ) ;
}
}
static void F_70 ( struct V_18 * V_19 ,
struct V_139 * V_140 )
{
struct V_98 * V_99 = F_53 ( V_19 -> V_94 ) ;
T_4 * V_141 = ( T_4 * ) V_19 -> V_94 -> V_43 ;
T_4 * V_142 ;
T_1 V_101 ;
int V_143 ;
memcpy ( V_99 -> V_111 , V_141 , V_99 -> V_112 ) ;
F_54 ( V_141 , 0 , & V_101 ) ;
V_143 = F_18 ( V_101 , V_144 ) ;
F_71 ( V_19 -> V_94 , V_145 ) ;
if ( F_14 ( V_143 == 0 ||
V_143 > V_19 -> V_5 -> V_146 ) ) {
F_35 ( V_19 -> V_5 -> V_2 ,
L_11 , V_143 ) ;
return;
}
V_142 = ( T_4 * ) ( V_19 -> V_94 -> V_43 + V_143 ) ;
F_54 ( V_142 , 0 , & V_101 ) ;
if ( F_18 ( V_101 , V_147 ) )
V_140 -> V_22 |= V_148 ;
V_140 -> V_149 = F_18 ( V_101 , V_150 ) ;
if ( F_18 ( V_101 , V_151 ) ) {
V_140 -> V_22 |= V_152 ;
V_140 -> V_22 |= V_153 ;
if ( V_140 -> V_149 == V_154 )
V_140 -> V_22 |= V_155 ;
else if ( V_140 -> V_149 == V_156 )
V_140 -> V_22 |= V_157 ;
}
if ( F_18 ( V_101 , V_158 ) )
V_140 -> V_159 |= V_160 ;
if ( F_18 ( V_101 , V_161 ) )
V_140 -> V_159 |= V_162 ;
F_72 ( V_19 -> V_94 , V_143 ) ;
F_73 ( V_19 , V_140 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_80 ;
if ( F_75 ( V_2 ) )
V_80 = F_76 ( V_2 ) ;
else
V_80 = F_77 ( V_2 , V_2 -> V_163 ,
V_164 ) ;
return V_80 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_80 ;
V_80 = F_79 ( V_2 ) ;
if ( V_80 )
return V_80 ;
V_2 -> V_34 . V_165 = F_27 ;
F_80 ( & V_2 -> V_33 , F_68 ) ;
return 0 ;
}
static void F_81 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
unsigned short V_166 , V_167 ;
F_82 ( V_2 , & V_166 , & V_167 ) ;
switch ( V_5 -> V_7 ) {
case V_8 :
V_5 -> V_71 = 128 ;
V_5 -> V_146 = V_168 ;
V_5 -> V_169 = V_145 ;
V_5 -> V_113 = V_167 ;
V_5 -> V_170 = sizeof( struct V_171 ) ;
break;
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_5 -> V_71 = 16 ;
V_5 -> V_146 = V_168 ;
V_5 -> V_169 = V_95 ;
V_5 -> V_113 = V_166 ;
V_5 -> V_170 = sizeof( struct V_171 ) ;
break;
case V_11 :
V_5 -> V_71 = 8 ;
V_5 -> V_146 = V_176 ;
V_5 -> V_169 = V_95 ;
V_5 -> V_113 = V_166 ;
V_5 -> V_170 = sizeof( struct V_171 ) ;
break;
case V_177 :
default:
F_83 () ;
break;
}
}
static int F_84 ( struct V_178 * V_179 ,
const struct V_180 * V_181 )
{
return F_85 ( V_179 , & V_182 ) ;
}
