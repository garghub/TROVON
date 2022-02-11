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
V_35 ,
V_36 ) ;
return false ;
}
V_29:
F_23 ( V_37 , & V_2 -> V_22 ) ;
if ( F_7 ( V_2 ) &&
! F_24 ( V_37 , & V_2 -> V_22 ) )
return true ;
else
return false ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( F_24 ( V_37 , & V_2 -> V_22 ) )
return;
F_22 ( & V_2 -> V_34 ,
2 * V_35 ,
V_36 ) ;
}
static void F_26 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_5 -> V_2 ;
F_25 ( V_2 ) ;
}
static enum V_38 F_27 ( struct V_39 * V_40 )
{
struct V_1 * V_2 =
F_28 ( V_40 , struct V_1 , V_34 ) ;
F_29 ( V_2 , V_41 ,
F_17 ) ;
return V_42 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_2 * V_6 ;
T_1 V_43 ;
int V_44 ;
V_6 = F_31 ( sizeof( * V_6 ) , V_45 ) ;
if ( V_6 == NULL )
return - V_46 ;
V_44 = F_32 ( V_2 , V_47 ,
V_48 , 0 ,
V_49 , V_6 , sizeof( * V_6 ) ,
V_50 ) ;
V_43 = F_33 ( * V_6 ) ;
F_34 ( V_6 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( ( V_43 & 0x00000003 ) == 2 )
return 1 ;
return 0 ;
}
static char * F_35 ( struct V_1 * V_2 )
{
return V_51 ;
}
static int F_36 ( struct V_1 * V_2 ,
const T_3 * V_52 , const T_4 V_53 )
{
int V_54 ;
T_1 V_55 ;
T_1 V_56 ;
int V_57 ;
if ( F_37 ( V_2 , V_58 ) ||
F_37 ( V_2 , V_59 ) ||
F_37 ( V_2 , V_60 ) ) {
V_55 = 0 ;
V_56 = 4096 ;
} else {
V_55 = 4096 ;
V_56 = 4096 ;
}
V_57 = F_30 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 ) {
F_38 ( V_2 ,
L_4 ) ;
F_39 ( V_61 , & V_2 -> V_62 ) ;
} else {
F_40 ( V_2 , V_63 ,
V_52 + V_55 , V_56 ) ;
}
F_5 ( V_2 , V_64 , ~ 0 ) ;
F_5 ( V_2 , V_65 , ~ 0 ) ;
V_54 = F_41 ( V_2 , V_47 ,
0 , V_66 ,
V_50 ) ;
if ( V_54 < 0 ) {
F_42 ( V_2 , L_5 ) ;
return V_54 ;
}
F_43 ( 10 ) ;
F_5 ( V_2 , V_67 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
T_1 V_6 ;
if ( F_45 ( V_2 ) )
return - V_68 ;
F_3 ( V_2 , V_69 , & V_6 ) ;
F_5 ( V_2 , V_69 , V_6 & ~ 0x00002000 ) ;
V_6 = 0 ;
F_4 ( & V_6 , V_70 , 1 ) ;
F_4 ( & V_6 , V_71 , 1 ) ;
F_5 ( V_2 , V_9 , V_6 ) ;
F_41 ( V_2 , V_47 , 0 ,
V_72 , V_73 ) ;
F_5 ( V_2 , V_9 , 0x00000000 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_1 V_6 = 0 ;
if ( F_14 ( F_47 ( V_2 ) ) )
return - V_74 ;
F_4 ( & V_6 , V_75 , 0 ) ;
F_4 ( & V_6 , V_76 , 0 ) ;
F_4 ( & V_6 , V_77 , 128 ) ;
F_4 ( & V_6 , V_78 ,
( ( V_2 -> V_79 -> V_80 * V_81 )
/ 1024 ) - 3 ) ;
F_4 ( & V_6 , V_82 , 1 ) ;
F_4 ( & V_6 , V_83 , 1 ) ;
F_5 ( V_2 , V_84 , V_6 ) ;
return F_48 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_85 V_86 )
{
if ( V_86 == V_87 )
F_52 ( V_2 , V_88 , 0xff , 0 , 2 ) ;
else
F_52 ( V_2 , V_89 , 0xff , 0xff , 2 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
enum V_85 V_86 )
{
int V_57 = 0 ;
switch ( V_86 ) {
case V_90 :
F_51 ( V_2 , V_87 ) ;
F_43 ( 1 ) ;
V_57 = F_46 ( V_2 ) ;
break;
case V_91 :
F_49 ( V_2 ) ;
F_51 ( V_2 , V_92 ) ;
break;
case V_93 :
case V_94 :
break;
case V_95 :
case V_92 :
case V_96 :
case V_87 :
V_57 = F_51 ( V_2 , V_86 ) ;
break;
default:
V_57 = - V_97 ;
break;
}
if ( F_14 ( V_57 ) )
F_42 ( V_2 , L_6 ,
V_86 , V_57 ) ;
return V_57 ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned int V_98 ;
T_1 V_6 ;
F_3 ( V_2 , V_99 , & V_6 ) ;
if ( F_19 ( V_6 , V_100 ) ) {
F_18 ( V_2 , L_7 ) ;
F_5 ( V_2 , V_101 , 0xf40012 ) ;
for ( V_98 = 0 ; V_98 < 10 ; V_98 ++ ) {
F_55 ( 10 ) ;
if ( ! F_19 ( V_6 , V_100 ) )
break;
}
F_5 ( V_2 , V_101 , 0xf40006 ) ;
}
F_3 ( V_2 , V_99 , & V_6 ) ;
if ( F_19 ( V_6 , V_102 ) ) {
F_18 ( V_2 , L_8 ) ;
F_5 ( V_2 , V_101 , 0xf4000a ) ;
for ( V_98 = 0 ; V_98 < 10 ; V_98 ++ ) {
F_55 ( 10 ) ;
if ( ! F_19 ( V_6 , V_102 ) )
break;
}
F_5 ( V_2 , V_101 , 0xf40006 ) ;
}
F_56 ( V_2 ) ;
}
static T_2 * F_57 ( struct V_18 * V_19 )
{
if ( V_19 -> V_5 -> V_7 == V_11 )
return ( T_2 * ) ( V_19 -> V_103 -> V_52 ) ;
else
return ( T_2 * ) ( V_19 -> V_103 -> V_52 + V_104 ) ;
}
static void F_58 ( struct V_18 * V_19 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 = F_59 ( V_19 -> V_103 ) ;
T_2 * V_109 = ( T_2 * ) V_19 -> V_103 -> V_52 ;
T_1 V_110 ;
F_60 ( V_109 , 0 , & V_110 ) ;
F_4 ( & V_110 , V_111 ,
F_61 ( V_19 -> V_103 -> V_53 , 4 ) - V_104 ) ;
F_4 ( & V_110 , V_112 ,
! F_11 ( V_113 , & V_106 -> V_22 ) ) ;
F_4 ( & V_110 , V_114 , 2 ) ;
F_4 ( & V_110 , V_115 , 0 ) ;
F_4 ( & V_110 , V_116 , 0 ) ;
F_4 ( & V_110 , V_117 ,
F_11 ( V_118 , & V_106 -> V_22 ) ) ;
F_62 ( V_109 , 0 , V_110 ) ;
V_108 -> V_22 |= V_119 ;
V_108 -> V_120 = V_109 ;
V_108 -> V_121 = V_104 + V_19 -> V_5 -> V_122 ;
}
static int F_63 ( struct V_18 * V_19 )
{
return F_61 ( V_19 -> V_103 -> V_53 , 4 ) + 4 ;
}
static enum V_123
F_64 ( struct V_18 * V_19 , T_1 V_6 )
{
T_2 * V_124 ;
T_1 V_110 ;
int V_125 , V_126 , V_127 ;
int V_128 , V_129 , V_130 , V_131 ;
if ( F_11 ( V_132 , & V_19 -> V_22 ) )
return V_133 ;
V_125 = F_19 ( V_6 , V_134 ) ;
V_126 = F_19 ( V_6 , V_135 ) ;
V_127 = F_19 ( V_6 , V_136 ) ;
V_131 = F_19 ( V_6 , V_137 ) ;
V_124 = F_57 ( V_19 ) ;
F_60 ( V_124 , 1 , & V_110 ) ;
V_128 = F_19 ( V_110 , V_138 ) ;
V_129 = F_19 ( V_110 , V_139 ) ;
V_130 = F_19 ( V_110 , V_140 ) ;
if ( V_125 != V_128 || V_126 != V_129 || ( ! V_131 && V_127 != V_130 ) ) {
F_15 ( V_19 -> V_5 -> V_2 ,
L_9 ,
V_19 -> V_5 -> V_7 , V_19 -> V_25 ) ;
return V_141 ;
}
return V_142 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
T_1 V_6 ;
T_3 V_7 ;
enum V_123 V_143 ;
while ( F_66 ( & V_2 -> V_31 , & V_6 ) ) {
V_7 = F_19 ( V_6 , V_144 ) ;
V_5 = F_67 ( V_2 , V_7 ) ;
if ( F_14 ( F_68 ( V_5 ) ) ) {
F_15 ( V_2 , L_10 ,
V_7 ) ;
break;
}
V_19 = F_9 ( V_5 , V_17 ) ;
if ( F_14 ( F_11 ( V_145 , & V_19 -> V_22 ) ||
! F_11 ( V_21 , & V_19 -> V_22 ) ) ) {
F_18 ( V_2 , L_11 ,
V_19 -> V_25 , V_7 ) ;
break;
}
V_143 = F_64 ( V_19 , V_6 ) ;
if ( F_69 ( V_143 == V_142 ) )
F_70 ( V_19 , V_6 , F_57 ( V_19 ) ) ;
else
F_71 ( V_19 , V_143 ) ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
F_8 (rt2x00dev, queue) {
while ( ! F_68 ( V_5 ) ) {
V_19 = F_9 ( V_5 , V_17 ) ;
if ( F_11 ( V_145 , & V_19 -> V_22 ) ||
! F_11 ( V_21 , & V_19 -> V_22 ) )
break;
if ( F_11 ( V_132 , & V_19 -> V_22 ) )
F_71 ( V_19 , V_133 ) ;
else if ( F_10 ( V_19 ) )
F_71 ( V_19 , V_141 ) ;
else
break;
}
}
}
static void F_73 ( struct V_146 * V_147 )
{
struct V_1 * V_2 =
F_28 ( V_147 , struct V_1 , V_33 ) ;
while ( ! F_74 ( & V_2 -> V_31 ) ||
F_16 ( V_2 ) ) {
F_65 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( F_7 ( V_2 ) )
F_25 ( V_2 ) ;
}
}
static void F_75 ( struct V_18 * V_19 ,
struct V_148 * V_149 )
{
struct V_107 * V_108 = F_59 ( V_19 -> V_103 ) ;
T_2 * V_150 = ( T_2 * ) V_19 -> V_103 -> V_52 ;
T_2 * V_151 ;
T_1 V_110 ;
int V_152 ;
memcpy ( V_108 -> V_120 , V_150 , V_108 -> V_121 ) ;
F_60 ( V_150 , 0 , & V_110 ) ;
V_152 = F_19 ( V_110 , V_153 ) ;
F_76 ( V_19 -> V_103 , V_154 ) ;
if ( F_14 ( V_152 == 0 ||
V_152 > V_19 -> V_5 -> V_155 ) ) {
F_42 ( V_19 -> V_5 -> V_2 ,
L_12 , V_152 ) ;
return;
}
V_151 = ( T_2 * ) ( V_19 -> V_103 -> V_52 + V_152 ) ;
F_60 ( V_151 , 0 , & V_110 ) ;
if ( F_19 ( V_110 , V_156 ) )
V_149 -> V_22 |= V_157 ;
V_149 -> V_158 = F_19 ( V_110 , V_159 ) ;
if ( F_19 ( V_110 , V_160 ) ) {
V_149 -> V_22 |= V_161 ;
V_149 -> V_22 |= V_162 ;
if ( V_149 -> V_158 == V_163 )
V_149 -> V_22 |= V_164 ;
else if ( V_149 -> V_158 == V_165 )
V_149 -> V_22 |= V_166 ;
}
if ( F_19 ( V_110 , V_167 ) )
V_149 -> V_168 |= V_169 ;
if ( F_19 ( V_110 , V_170 ) )
V_149 -> V_168 |= V_171 ;
F_77 ( V_19 -> V_103 , V_152 ) ;
F_78 ( V_19 , V_149 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_30 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 )
return 1 ;
return F_80 ( V_2 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_79 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 )
V_57 = F_82 ( V_2 ) ;
else
V_57 = F_83 ( V_2 , V_2 -> V_172 ,
V_173 ) ;
return V_57 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_85 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_34 . V_174 = F_27 ;
F_86 ( & V_2 -> V_33 , F_73 ) ;
return 0 ;
}
static void F_87 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
unsigned short V_175 , V_176 ;
F_88 ( V_2 , & V_175 , & V_176 ) ;
switch ( V_5 -> V_7 ) {
case V_8 :
V_5 -> V_80 = 128 ;
V_5 -> V_155 = V_177 ;
V_5 -> V_178 = V_154 ;
V_5 -> V_122 = V_176 ;
V_5 -> V_179 = sizeof( struct V_180 ) ;
break;
case V_181 :
case V_182 :
case V_183 :
case V_184 :
V_5 -> V_80 = 16 ;
V_5 -> V_155 = V_177 ;
V_5 -> V_178 = V_104 ;
V_5 -> V_122 = V_175 ;
V_5 -> V_179 = sizeof( struct V_180 ) ;
break;
case V_11 :
V_5 -> V_80 = 8 ;
V_5 -> V_155 = V_185 ;
V_5 -> V_178 = V_104 ;
V_5 -> V_122 = V_175 ;
V_5 -> V_179 = sizeof( struct V_180 ) ;
break;
case V_186 :
default:
F_89 () ;
break;
}
}
static int F_90 ( struct V_187 * V_188 ,
const struct V_189 * V_190 )
{
return F_91 ( V_188 , & V_191 ) ;
}
