static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_4 ( V_6 , V_7 ) ;
}
static int F_5 ( struct V_5 * V_6 , T_1 V_7 , T_2 V_8 )
{
return F_6 ( V_6 , V_7 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_1 , T_2 V_9 ,
T_2 V_10 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
T_2 V_11 = ( V_1 -> V_12 & ~ V_9 ) | V_10 ;
int V_13 ;
V_13 = F_5 ( V_6 , V_14 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_12 = V_11 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , T_2 V_9 , T_2 V_10 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
T_2 V_11 = ( V_1 -> V_15 & ~ V_9 ) | V_10 ;
int V_13 ;
V_13 = F_5 ( V_6 , V_16 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_15 = V_11 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
V_13 = F_5 ( V_6 , V_17 , V_18 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_17 , V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_7 ( V_1 , V_20 ,
0 ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
static const struct V_21 V_22 = {
. V_23 = 6000000 ,
. V_24 = 27000000 ,
. V_25 = 2000000 ,
. V_26 = 13500000 ,
. V_27 = 180000000 ,
. V_28 = 360000000 ,
. V_29 = 96000000 ,
. V_30 = 1 ,
. V_31 = 64 ,
. V_32 = 16 ,
. V_33 = 255 ,
. V_34 = 1 ,
. V_35 = 128 ,
} ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
struct V_36 * V_37 = V_1 -> V_37 ;
V_1 -> V_38 . V_39 = V_37 -> V_40 ;
V_1 -> V_38 . V_41 = V_37 -> V_42 ;
return F_12 ( & V_6 -> V_43 , & V_22 , & V_1 -> V_38 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
V_13 = F_5 ( V_6 , V_44 ,
V_45 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_46 ,
( V_1 -> V_38 . V_47 << 8 ) | ( V_1 -> V_38 . V_48 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_49 , V_1 -> V_38 . V_50 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
F_14 ( 1000 , 2000 ) ;
V_13 = F_5 ( V_6 , V_44 ,
V_45 |
V_51 ) ;
return V_13 ;
}
static inline int F_15 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
return F_5 ( V_6 , V_44 ,
V_52 ) ;
}
static int F_16 ( struct V_1 * V_1 )
{
if ( V_1 -> V_53 != - 1 ) {
F_17 ( V_1 -> V_53 , 0 ) ;
F_14 ( 1000 , 2000 ) ;
}
if ( V_1 -> V_37 -> V_54 )
V_1 -> V_37 -> V_54 ( & V_1 -> V_4 ,
V_1 -> V_37 -> V_40 ) ;
if ( V_1 -> V_53 != - 1 ) {
F_17 ( V_1 -> V_53 , 1 ) ;
F_14 ( 1000 , 2000 ) ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_1 )
{
if ( V_1 -> V_53 != - 1 ) {
F_17 ( V_1 -> V_53 , 0 ) ;
F_14 ( 1000 , 2000 ) ;
}
if ( V_1 -> V_37 -> V_54 )
V_1 -> V_37 -> V_54 ( & V_1 -> V_4 , 0 ) ;
}
static int F_19 ( struct V_1 * V_1 , bool V_55 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
if ( ! V_55 ) {
F_18 ( V_1 ) ;
return 0 ;
}
V_13 = F_16 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_10 ( V_1 ) ;
if ( V_13 < 0 ) {
F_20 ( & V_6 -> V_43 , L_1 ) ;
return V_13 ;
}
return F_21 ( & V_1 -> V_56 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
struct V_57 * V_58 = & V_1 -> V_58 ;
const struct V_59 * V_60 = & V_1 -> V_60 ;
unsigned int V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
unsigned int V_64 ;
unsigned int V_65 ;
unsigned int V_66 ;
int V_13 ;
V_13 = F_5 ( V_6 , V_67 , V_60 -> V_68 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_69 , V_60 -> V_70 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_71 , V_60 -> V_72 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_73 , V_60 -> V_74 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_63 = F_23 ( V_60 -> V_72 , V_58 -> V_72 ) ;
V_64 = F_23 ( V_60 -> V_74 , V_58 -> V_74 ) ;
V_65 = 1 << ( F_24 ( V_63 ) - 1 ) ;
V_66 = 1 << ( F_24 ( V_64 ) - 1 ) ;
V_13 = F_5 ( V_6 , V_75 ,
( ( V_65 - 1 ) << 4 ) | ( V_63 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_76 ,
( ( V_66 - 1 ) << 4 ) | ( V_64 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_61 = 346 * V_66 + 64 + ( 80 >> F_25 (unsigned int, xbin, 3 ) ) ;
V_62 = V_77 ;
V_13 = F_5 ( V_6 , V_78 , V_61 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_79 , V_62 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_13 ;
}
static int F_26 ( struct V_2 * V_4 , int V_80 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 ;
if ( ! V_80 ) {
V_13 = F_7 ( V_1 ,
V_20 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_15 ( V_1 ) ;
}
V_13 = F_22 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_7 ( V_1 , 0 ,
V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_13 ( V_1 ) ;
}
static int F_27 ( struct V_2 * V_4 ,
struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_84 -> V_85 || V_84 -> V_86 )
return - V_87 ;
V_84 -> V_84 = V_1 -> V_58 . V_84 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_4 ,
struct V_81 * V_82 ,
struct V_88 * V_89 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_89 -> V_86 >= 8 || V_89 -> V_84 != V_1 -> V_58 . V_84 )
return - V_87 ;
V_89 -> V_90 = V_91
/ F_29 (unsigned int, 7 , fse->index + 1 ) ;
V_89 -> V_92 = V_89 -> V_90 ;
V_89 -> V_93 = V_94 / ( V_89 -> V_86 + 1 ) ;
V_89 -> V_95 = V_89 -> V_93 ;
return 0 ;
}
static struct V_57 *
F_30 ( struct V_1 * V_1 , struct V_81 * V_82 ,
unsigned int V_85 , T_3 V_96 )
{
switch ( V_96 ) {
case V_97 :
return F_31 ( V_82 , V_85 ) ;
case V_98 :
return & V_1 -> V_58 ;
default:
return NULL ;
}
}
static struct V_59 *
F_32 ( struct V_1 * V_1 , struct V_81 * V_82 ,
unsigned int V_85 , T_3 V_96 )
{
switch ( V_96 ) {
case V_97 :
return F_33 ( V_82 , V_85 ) ;
case V_98 :
return & V_1 -> V_60 ;
default:
return NULL ;
}
}
static int F_34 ( struct V_2 * V_4 ,
struct V_81 * V_82 ,
struct V_99 * V_100 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_100 -> V_58 = * F_30 ( V_1 , V_82 , V_100 -> V_85 ,
V_100 -> V_96 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_4 ,
struct V_81 * V_82 ,
struct V_99 * V_58 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_57 * V_101 ;
struct V_59 * V_102 ;
unsigned int V_72 ;
unsigned int V_74 ;
unsigned int V_103 ;
unsigned int V_104 ;
V_102 = F_32 ( V_1 , V_82 , V_58 -> V_85 ,
V_58 -> V_96 ) ;
V_72 = F_36 (unsigned int, ALIGN(format->format.width, 2),
max(__crop->width / 7, MT9P031_WINDOW_WIDTH_MIN),
__crop->width) ;
V_74 = F_36 (unsigned int, ALIGN(format->format.height, 2),
max(__crop->height / 8, MT9P031_WINDOW_HEIGHT_MIN),
__crop->height) ;
V_103 = F_23 ( V_102 -> V_72 , V_72 ) ;
V_104 = F_23 ( V_102 -> V_74 , V_74 ) ;
V_101 = F_30 ( V_1 , V_82 , V_58 -> V_85 ,
V_58 -> V_96 ) ;
V_101 -> V_72 = V_102 -> V_72 / V_103 ;
V_101 -> V_74 = V_102 -> V_74 / V_104 ;
V_58 -> V_58 = * V_101 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_4 ,
struct V_81 * V_82 ,
struct V_105 * V_60 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_60 -> V_106 = * F_32 ( V_1 , V_82 , V_60 -> V_85 ,
V_60 -> V_96 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_4 ,
struct V_81 * V_82 ,
struct V_105 * V_60 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_57 * V_101 ;
struct V_59 * V_102 ;
struct V_59 V_106 ;
V_106 . V_68 = F_39 ( F_40 ( V_60 -> V_106 . V_68 , 2 ) , V_107 ,
V_108 ) ;
V_106 . V_70 = F_39 ( F_40 ( V_60 -> V_106 . V_70 , 2 ) , V_109 ,
V_110 ) ;
V_106 . V_72 = F_39 ( F_40 ( V_60 -> V_106 . V_72 , 2 ) ,
V_111 ,
V_112 ) ;
V_106 . V_74 = F_39 ( F_40 ( V_60 -> V_106 . V_74 , 2 ) ,
V_113 ,
V_114 ) ;
V_106 . V_72 = F_41 ( V_106 . V_72 , V_115 - V_106 . V_68 ) ;
V_106 . V_74 = F_41 ( V_106 . V_74 , V_116 - V_106 . V_70 ) ;
V_102 = F_32 ( V_1 , V_82 , V_60 -> V_85 , V_60 -> V_96 ) ;
if ( V_106 . V_72 != V_102 -> V_72 || V_106 . V_74 != V_102 -> V_74 ) {
V_101 = F_30 ( V_1 , V_82 , V_60 -> V_85 ,
V_60 -> V_96 ) ;
V_101 -> V_72 = V_106 . V_72 ;
V_101 -> V_74 = V_106 . V_74 ;
}
* V_102 = V_106 ;
V_60 -> V_106 = V_106 ;
return 0 ;
}
static int F_42 ( struct V_117 * V_118 )
{
struct V_1 * V_1 =
F_2 ( V_118 -> V_119 , struct V_1 , V_56 ) ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
T_2 V_8 ;
int V_13 ;
switch ( V_118 -> V_120 ) {
case V_121 :
V_13 = F_5 ( V_6 , V_122 ,
( V_118 -> V_123 >> 16 ) & 0xffff ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_124 ,
V_118 -> V_123 & 0xffff ) ;
case V_125 :
if ( V_118 -> V_123 <= 32 ) {
V_8 = V_118 -> V_123 ;
} else if ( V_118 -> V_123 <= 64 ) {
V_118 -> V_123 &= ~ 1 ;
V_8 = ( 1 << 6 ) | ( V_118 -> V_123 >> 1 ) ;
} else {
V_118 -> V_123 &= ~ 7 ;
V_8 = ( ( V_118 -> V_123 - 64 ) << 5 ) | ( 1 << 6 ) | 32 ;
}
return F_5 ( V_6 , V_126 , V_8 ) ;
case V_127 :
if ( V_118 -> V_123 )
return F_9 ( V_1 ,
0 , V_128 ) ;
else
return F_9 ( V_1 ,
V_128 , 0 ) ;
case V_129 :
if ( V_118 -> V_123 )
return F_9 ( V_1 ,
0 , V_130 ) ;
else
return F_9 ( V_1 ,
V_130 , 0 ) ;
case V_131 :
if ( ! V_118 -> V_123 ) {
if ( V_1 -> V_132 -> V_133 . V_123 != 0 ) {
V_13 = F_42 ( V_1 -> V_132 ) ;
if ( V_13 < 0 )
return V_13 ;
}
if ( V_1 -> V_134 -> V_133 . V_123 != 0 ) {
V_13 = F_42 ( V_1 -> V_134 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return F_5 ( V_6 , V_135 ,
V_136 ) ;
}
V_13 = F_5 ( V_6 , V_137 , 0x05a0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_138 , 0x0a50 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_139 , 0x0aa0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_1 , V_140 ,
0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_141 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_135 ,
( ( V_118 -> V_123 - 1 ) << V_142 )
| V_143 ) ;
case V_144 :
V_13 = F_9 ( V_1 ,
V_118 -> V_123 ? 0 : V_140 ,
V_118 -> V_123 ? V_140 : 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_145 ,
V_118 -> V_123 ? 0 : V_146 ) ;
case V_147 :
return F_5 ( V_6 , V_148 ,
V_118 -> V_123 ) ;
case V_149 :
V_8 = V_118 -> V_123 & ( ( 1 << 9 ) - 1 ) ;
V_13 = F_5 ( V_6 , V_150 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_151 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_152 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_153 , V_8 ) ;
case V_154 :
return F_5 ( V_6 , V_141 ,
V_118 -> V_123 & ( ( 1 << 12 ) - 1 ) ) ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_4 , int V_55 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 = 0 ;
F_44 ( & V_1 -> V_155 ) ;
if ( V_1 -> V_156 == ! V_55 ) {
V_13 = F_19 ( V_1 , ! ! V_55 ) ;
if ( V_13 < 0 )
goto V_157;
}
V_1 -> V_156 += V_55 ? 1 : - 1 ;
F_45 ( V_1 -> V_156 < 0 ) ;
V_157:
F_46 ( & V_1 -> V_155 ) ;
return V_13 ;
}
static int F_47 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_8 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_4 V_8 ;
int V_13 ;
V_13 = F_16 ( V_1 ) ;
if ( V_13 < 0 ) {
F_20 ( & V_6 -> V_43 , L_2 ) ;
return V_13 ;
}
V_8 = F_3 ( V_6 , V_158 ) ;
if ( V_8 != V_159 ) {
F_20 ( & V_6 -> V_43 , L_3
L_4 , V_8 ) ;
return - V_160 ;
}
F_18 ( V_1 ) ;
F_48 ( & V_6 -> V_43 , L_5 ,
V_6 -> V_161 ) ;
return V_13 ;
}
static int F_49 ( struct V_2 * V_4 , struct V_81 * V_82 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
V_60 = F_33 ( V_82 , 0 ) ;
V_60 -> V_68 = V_162 ;
V_60 -> V_70 = V_163 ;
V_60 -> V_72 = V_91 ;
V_60 -> V_74 = V_94 ;
V_58 = F_31 ( V_82 , 0 ) ;
if ( V_1 -> V_164 == V_165 )
V_58 -> V_84 = V_166 ;
else
V_58 -> V_84 = V_167 ;
V_58 -> V_72 = V_91 ;
V_58 -> V_74 = V_94 ;
V_58 -> V_168 = V_169 ;
V_58 -> V_170 = V_171 ;
return F_43 ( V_4 , 1 ) ;
}
static int F_50 ( struct V_2 * V_4 , struct V_81 * V_82 )
{
return F_43 ( V_4 , 0 ) ;
}
static int F_51 ( struct V_5 * V_6 ,
const struct V_172 * V_173 )
{
struct V_36 * V_37 = V_6 -> V_43 . V_174 ;
struct V_175 * V_176 = F_52 ( V_6 -> V_43 . V_177 ) ;
struct V_1 * V_1 ;
unsigned int V_178 ;
int V_13 ;
if ( V_37 == NULL ) {
F_20 ( & V_6 -> V_43 , L_6 ) ;
return - V_87 ;
}
if ( ! F_53 ( V_176 , V_179 ) ) {
F_54 ( & V_6 -> V_43 ,
L_7 ) ;
return - V_180 ;
}
V_1 = F_55 ( sizeof( * V_1 ) , V_181 ) ;
if ( V_1 == NULL )
return - V_182 ;
V_1 -> V_37 = V_37 ;
V_1 -> V_12 = V_183 ;
V_1 -> V_15 = V_140 ;
V_1 -> V_164 = V_173 -> V_184 ;
V_1 -> V_53 = - 1 ;
F_56 ( & V_1 -> V_56 , F_57 ( V_185 ) + 4 ) ;
F_58 ( & V_1 -> V_56 , & V_186 ,
V_121 , V_187 ,
V_188 , 1 ,
V_189 ) ;
F_58 ( & V_1 -> V_56 , & V_186 ,
V_125 , V_190 ,
V_191 , 1 , V_192 ) ;
F_58 ( & V_1 -> V_56 , & V_186 ,
V_127 , 0 , 1 , 1 , 0 ) ;
F_58 ( & V_1 -> V_56 , & V_186 ,
V_129 , 0 , 1 , 1 , 0 ) ;
for ( V_178 = 0 ; V_178 < F_57 ( V_185 ) ; ++ V_178 )
F_59 ( & V_1 -> V_56 , & V_185 [ V_178 ] , NULL ) ;
V_1 -> V_4 . V_193 = & V_1 -> V_56 ;
if ( V_1 -> V_56 . error ) {
F_60 ( V_194 L_8 ,
V_195 , V_1 -> V_56 . error ) ;
V_13 = V_1 -> V_56 . error ;
goto V_196;
}
V_1 -> V_132 = F_61 ( & V_1 -> V_56 , V_144 ) ;
V_1 -> V_134 = F_61 ( & V_1 -> V_56 ,
V_154 ) ;
F_62 ( & V_1 -> V_155 ) ;
F_63 ( & V_1 -> V_4 , V_6 , & V_197 ) ;
V_1 -> V_4 . V_198 = & V_199 ;
V_1 -> V_85 . V_200 = V_201 ;
V_13 = F_64 ( & V_1 -> V_4 . V_202 , 1 , & V_1 -> V_85 , 0 ) ;
if ( V_13 < 0 )
goto V_196;
V_1 -> V_4 . V_200 |= V_203 ;
V_1 -> V_60 . V_72 = V_91 ;
V_1 -> V_60 . V_74 = V_94 ;
V_1 -> V_60 . V_68 = V_162 ;
V_1 -> V_60 . V_70 = V_163 ;
if ( V_1 -> V_164 == V_165 )
V_1 -> V_58 . V_84 = V_166 ;
else
V_1 -> V_58 . V_84 = V_167 ;
V_1 -> V_58 . V_72 = V_91 ;
V_1 -> V_58 . V_74 = V_94 ;
V_1 -> V_58 . V_168 = V_169 ;
V_1 -> V_58 . V_170 = V_171 ;
if ( V_37 -> V_53 != - 1 ) {
V_13 = F_65 ( V_37 -> V_53 , V_204 ,
L_9 ) ;
if ( V_13 < 0 )
goto V_196;
V_1 -> V_53 = V_37 -> V_53 ;
}
V_13 = F_11 ( V_1 ) ;
V_196:
if ( V_13 < 0 ) {
if ( V_1 -> V_53 != - 1 )
F_66 ( V_1 -> V_53 ) ;
F_67 ( & V_1 -> V_56 ) ;
F_68 ( & V_1 -> V_4 . V_202 ) ;
F_69 ( V_1 ) ;
}
return V_13 ;
}
static int F_70 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_71 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_67 ( & V_1 -> V_56 ) ;
F_72 ( V_4 ) ;
F_68 ( & V_4 -> V_202 ) ;
if ( V_1 -> V_53 != - 1 )
F_66 ( V_1 -> V_53 ) ;
F_69 ( V_1 ) ;
return 0 ;
}
