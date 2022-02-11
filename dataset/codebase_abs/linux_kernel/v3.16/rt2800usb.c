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
static int F_31 ( struct V_1 * V_2 )
{
T_2 * V_6 ;
T_1 V_43 ;
V_6 = F_32 ( sizeof( * V_6 ) , V_44 ) ;
if ( V_6 == NULL )
return - V_45 ;
F_33 ( V_2 , V_46 ,
V_47 , 0 , V_48 ,
V_6 , sizeof( * V_6 ) , V_49 ) ;
V_43 = F_34 ( * V_6 ) ;
F_35 ( V_6 ) ;
if ( ( V_43 & 0x00000003 ) == 2 )
return 1 ;
return 0 ;
}
static char * F_36 ( struct V_1 * V_2 )
{
return V_50 ;
}
static int F_37 ( struct V_1 * V_2 ,
const T_3 * V_51 , const T_4 V_52 )
{
int V_53 ;
T_1 V_54 ;
T_1 V_55 ;
int V_56 ;
if ( F_38 ( V_2 , V_57 ) ||
F_38 ( V_2 , V_58 ) ||
F_38 ( V_2 , V_59 ) ) {
V_54 = 0 ;
V_55 = 4096 ;
} else {
V_54 = 4096 ;
V_55 = 4096 ;
}
V_56 = F_31 ( V_2 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 ) {
F_39 ( V_2 ,
L_4 ) ;
} else {
F_40 ( V_2 , V_60 ,
V_51 + V_54 , V_55 ) ;
}
F_5 ( V_2 , V_61 , ~ 0 ) ;
F_5 ( V_2 , V_62 , ~ 0 ) ;
V_53 = F_41 ( V_2 , V_46 ,
0 , V_63 ,
V_49 ) ;
if ( V_53 < 0 ) {
F_42 ( V_2 , L_5 ) ;
return V_53 ;
}
F_43 ( 10 ) ;
F_5 ( V_2 , V_64 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
T_1 V_6 ;
if ( F_45 ( V_2 ) )
return - V_65 ;
F_3 ( V_2 , V_66 , & V_6 ) ;
F_5 ( V_2 , V_66 , V_6 & ~ 0x00002000 ) ;
V_6 = 0 ;
F_4 ( & V_6 , V_67 , 1 ) ;
F_4 ( & V_6 , V_68 , 1 ) ;
F_5 ( V_2 , V_9 , V_6 ) ;
F_5 ( V_2 , V_69 , 0x00000000 ) ;
F_41 ( V_2 , V_46 , 0 ,
V_70 , V_71 ) ;
F_5 ( V_2 , V_9 , 0x00000000 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_1 V_6 ;
if ( F_14 ( F_47 ( V_2 ) ) )
return - V_72 ;
F_3 ( V_2 , V_69 , & V_6 ) ;
F_4 ( & V_6 , V_73 , 0 ) ;
F_4 ( & V_6 , V_74 , 0 ) ;
F_4 ( & V_6 , V_75 , 128 ) ;
F_4 ( & V_6 , V_76 ,
( ( V_2 -> V_77 -> V_78 * V_79 )
/ 1024 ) - 3 ) ;
F_4 ( & V_6 , V_80 , 1 ) ;
F_4 ( & V_6 , V_81 , 1 ) ;
F_5 ( V_2 , V_69 , V_6 ) ;
return F_48 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
enum V_82 V_83 )
{
if ( V_83 == V_84 )
F_53 ( V_2 , V_85 , 0xff , 0 , 2 ) ;
else
F_53 ( V_2 , V_86 , 0xff , 0xff , 2 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
enum V_82 V_83 )
{
int V_56 = 0 ;
switch ( V_83 ) {
case V_87 :
F_52 ( V_2 , V_84 ) ;
F_43 ( 1 ) ;
V_56 = F_46 ( V_2 ) ;
break;
case V_88 :
F_49 ( V_2 ) ;
F_52 ( V_2 , V_89 ) ;
break;
case V_90 :
case V_91 :
break;
case V_92 :
case V_89 :
case V_93 :
case V_84 :
V_56 = F_52 ( V_2 , V_83 ) ;
break;
default:
V_56 = - V_94 ;
break;
}
if ( F_14 ( V_56 ) )
F_42 ( V_2 , L_6 ,
V_83 , V_56 ) ;
return V_56 ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned int V_95 ;
T_1 V_6 ;
F_3 ( V_2 , V_96 , & V_6 ) ;
if ( F_19 ( V_6 , V_97 ) ) {
F_18 ( V_2 , L_7 ) ;
F_5 ( V_2 , V_98 , 0xf40012 ) ;
for ( V_95 = 0 ; V_95 < 10 ; V_95 ++ ) {
F_56 ( 10 ) ;
if ( ! F_19 ( V_6 , V_97 ) )
break;
}
F_5 ( V_2 , V_98 , 0xf40006 ) ;
}
F_3 ( V_2 , V_96 , & V_6 ) ;
if ( F_19 ( V_6 , V_99 ) ) {
F_18 ( V_2 , L_8 ) ;
F_5 ( V_2 , V_98 , 0xf4000a ) ;
for ( V_95 = 0 ; V_95 < 10 ; V_95 ++ ) {
F_56 ( 10 ) ;
if ( ! F_19 ( V_6 , V_99 ) )
break;
}
F_5 ( V_2 , V_98 , 0xf40006 ) ;
}
F_57 ( V_2 ) ;
}
static T_2 * F_58 ( struct V_18 * V_19 )
{
if ( V_19 -> V_5 -> V_7 == V_11 )
return ( T_2 * ) ( V_19 -> V_100 -> V_51 ) ;
else
return ( T_2 * ) ( V_19 -> V_100 -> V_51 + V_101 ) ;
}
static void F_59 ( struct V_18 * V_19 ,
struct V_102 * V_103 )
{
struct V_104 * V_105 = F_60 ( V_19 -> V_100 ) ;
T_2 * V_106 = ( T_2 * ) V_19 -> V_100 -> V_51 ;
T_1 V_107 ;
F_61 ( V_106 , 0 , & V_107 ) ;
F_4 ( & V_107 , V_108 ,
F_62 ( V_19 -> V_100 -> V_52 , 4 ) - V_101 ) ;
F_4 ( & V_107 , V_109 ,
! F_11 ( V_110 , & V_103 -> V_22 ) ) ;
F_4 ( & V_107 , V_111 , 2 ) ;
F_4 ( & V_107 , V_112 , 0 ) ;
F_4 ( & V_107 , V_113 , 0 ) ;
F_4 ( & V_107 , V_114 ,
F_11 ( V_115 , & V_103 -> V_22 ) ) ;
F_63 ( V_106 , 0 , V_107 ) ;
V_105 -> V_22 |= V_116 ;
V_105 -> V_117 = V_106 ;
V_105 -> V_118 = V_101 + V_19 -> V_5 -> V_119 ;
}
static int F_64 ( struct V_18 * V_19 )
{
return F_62 ( V_19 -> V_100 -> V_52 , 4 ) + 4 ;
}
static enum V_120
F_65 ( struct V_18 * V_19 , T_1 V_6 )
{
T_2 * V_121 ;
T_1 V_107 ;
int V_122 , V_123 , V_124 ;
int V_125 , V_126 , V_127 , V_128 ;
if ( F_11 ( V_129 , & V_19 -> V_22 ) )
return V_130 ;
V_122 = F_19 ( V_6 , V_131 ) ;
V_123 = F_19 ( V_6 , V_132 ) ;
V_124 = F_19 ( V_6 , V_133 ) ;
V_128 = F_19 ( V_6 , V_134 ) ;
V_121 = F_58 ( V_19 ) ;
F_61 ( V_121 , 1 , & V_107 ) ;
V_125 = F_19 ( V_107 , V_135 ) ;
V_126 = F_19 ( V_107 , V_136 ) ;
V_127 = F_19 ( V_107 , V_137 ) ;
if ( V_122 != V_125 || V_123 != V_126 || ( ! V_128 && V_124 != V_127 ) ) {
F_15 ( V_19 -> V_5 -> V_2 ,
L_9 ,
V_19 -> V_5 -> V_7 , V_19 -> V_25 ) ;
return V_138 ;
}
return V_139 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
T_1 V_6 ;
T_3 V_7 ;
enum V_120 V_140 ;
while ( F_67 ( & V_2 -> V_31 , & V_6 ) ) {
V_7 = F_19 ( V_6 , V_141 ) ;
V_5 = F_68 ( V_2 , V_7 ) ;
if ( F_14 ( F_69 ( V_5 ) ) ) {
F_15 ( V_2 , L_10 ,
V_7 ) ;
break;
}
V_19 = F_9 ( V_5 , V_17 ) ;
if ( F_14 ( F_11 ( V_142 , & V_19 -> V_22 ) ||
! F_11 ( V_21 , & V_19 -> V_22 ) ) ) {
F_18 ( V_2 , L_11 ,
V_19 -> V_25 , V_7 ) ;
break;
}
V_140 = F_65 ( V_19 , V_6 ) ;
if ( F_70 ( V_140 == V_139 ) )
F_71 ( V_19 , V_6 , F_58 ( V_19 ) ) ;
else
F_72 ( V_19 , V_140 ) ;
}
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
F_8 (rt2x00dev, queue) {
while ( ! F_69 ( V_5 ) ) {
V_19 = F_9 ( V_5 , V_17 ) ;
if ( F_11 ( V_142 , & V_19 -> V_22 ) ||
! F_11 ( V_21 , & V_19 -> V_22 ) )
break;
if ( F_11 ( V_129 , & V_19 -> V_22 ) )
F_72 ( V_19 , V_130 ) ;
else if ( F_10 ( V_19 ) )
F_72 ( V_19 , V_138 ) ;
else
break;
}
}
}
static void F_74 ( struct V_143 * V_144 )
{
struct V_1 * V_2 =
F_29 ( V_144 , struct V_1 , V_33 ) ;
while ( ! F_75 ( & V_2 -> V_31 ) ||
F_16 ( V_2 ) ) {
F_66 ( V_2 ) ;
F_73 ( V_2 ) ;
if ( F_7 ( V_2 ) )
F_26 ( V_2 ) ;
}
}
static void F_76 ( struct V_18 * V_19 ,
struct V_145 * V_146 )
{
struct V_104 * V_105 = F_60 ( V_19 -> V_100 ) ;
T_2 * V_147 = ( T_2 * ) V_19 -> V_100 -> V_51 ;
T_2 * V_148 ;
T_1 V_107 ;
int V_149 ;
memcpy ( V_105 -> V_117 , V_147 , V_105 -> V_118 ) ;
F_61 ( V_147 , 0 , & V_107 ) ;
V_149 = F_19 ( V_107 , V_150 ) ;
F_77 ( V_19 -> V_100 , V_151 ) ;
if ( F_14 ( V_149 == 0 ||
V_149 > V_19 -> V_5 -> V_152 ) ) {
F_42 ( V_19 -> V_5 -> V_2 ,
L_12 , V_149 ) ;
return;
}
V_148 = ( T_2 * ) ( V_19 -> V_100 -> V_51 + V_149 ) ;
F_61 ( V_148 , 0 , & V_107 ) ;
if ( F_19 ( V_107 , V_153 ) )
V_146 -> V_22 |= V_154 ;
V_146 -> V_155 = F_19 ( V_107 , V_156 ) ;
if ( F_19 ( V_107 , V_157 ) ) {
V_146 -> V_22 |= V_158 ;
V_146 -> V_22 |= V_159 ;
if ( V_146 -> V_155 == V_160 )
V_146 -> V_22 |= V_161 ;
else if ( V_146 -> V_155 == V_162 )
V_146 -> V_22 |= V_163 ;
}
if ( F_19 ( V_107 , V_164 ) )
V_146 -> V_165 |= V_166 ;
if ( F_19 ( V_107 , V_167 ) )
V_146 -> V_165 |= V_168 ;
F_78 ( V_19 -> V_100 , V_149 ) ;
F_79 ( V_19 , V_146 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_31 ( V_2 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 )
return 1 ;
return F_81 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_80 ( V_2 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 )
V_56 = F_83 ( V_2 ) ;
else
V_56 = F_84 ( V_2 , V_2 -> V_169 ,
V_170 ) ;
return V_56 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_86 ( V_2 ) ;
if ( V_56 )
return V_56 ;
V_2 -> V_34 . V_171 = F_28 ;
F_87 ( & V_2 -> V_33 , F_74 ) ;
return 0 ;
}
static void F_88 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
unsigned short V_172 , V_173 ;
F_89 ( V_2 , & V_172 , & V_173 ) ;
switch ( V_5 -> V_7 ) {
case V_8 :
V_5 -> V_78 = 128 ;
V_5 -> V_152 = V_174 ;
V_5 -> V_175 = V_151 ;
V_5 -> V_119 = V_173 ;
V_5 -> V_176 = sizeof( struct V_177 ) ;
break;
case V_178 :
case V_179 :
case V_180 :
case V_181 :
V_5 -> V_78 = 16 ;
V_5 -> V_152 = V_174 ;
V_5 -> V_175 = V_101 ;
V_5 -> V_119 = V_172 ;
V_5 -> V_176 = sizeof( struct V_177 ) ;
break;
case V_11 :
V_5 -> V_78 = 8 ;
V_5 -> V_152 = V_182 ;
V_5 -> V_175 = V_101 ;
V_5 -> V_119 = V_172 ;
V_5 -> V_176 = sizeof( struct V_177 ) ;
break;
case V_183 :
default:
F_90 () ;
break;
}
}
static int F_91 ( struct V_184 * V_185 ,
const struct V_186 * V_187 )
{
return F_92 ( V_185 , & V_188 ) ;
}
