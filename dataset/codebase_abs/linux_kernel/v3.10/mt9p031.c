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
V_1 -> V_38 = F_12 ( & V_6 -> V_39 , NULL ) ;
if ( F_13 ( V_1 -> V_38 ) )
return F_14 ( V_1 -> V_38 ) ;
F_15 ( V_1 -> V_38 , V_37 -> V_40 ) ;
V_1 -> V_41 . V_42 = V_37 -> V_40 ;
V_1 -> V_41 . V_43 = V_37 -> V_44 ;
return F_16 ( & V_6 -> V_39 , & V_22 , & V_1 -> V_41 ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
V_13 = F_5 ( V_6 , V_45 ,
V_46 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_47 ,
( V_1 -> V_41 . V_48 << 8 ) | ( V_1 -> V_41 . V_49 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_50 , V_1 -> V_41 . V_51 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
F_18 ( 1000 , 2000 ) ;
V_13 = F_5 ( V_6 , V_45 ,
V_46 |
V_52 ) ;
return V_13 ;
}
static inline int F_19 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
return F_5 ( V_6 , V_45 ,
V_53 ) ;
}
static int F_20 ( struct V_1 * V_1 )
{
if ( V_1 -> V_54 != - 1 ) {
F_21 ( V_1 -> V_54 , 0 ) ;
F_18 ( 1000 , 2000 ) ;
}
F_22 ( V_1 -> V_55 ) ;
F_22 ( V_1 -> V_56 ) ;
F_22 ( V_1 -> V_57 ) ;
if ( V_1 -> V_38 )
F_23 ( V_1 -> V_38 ) ;
if ( V_1 -> V_54 != - 1 ) {
F_21 ( V_1 -> V_54 , 1 ) ;
F_18 ( 1000 , 2000 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_1 )
{
if ( V_1 -> V_54 != - 1 ) {
F_21 ( V_1 -> V_54 , 0 ) ;
F_18 ( 1000 , 2000 ) ;
}
F_25 ( V_1 -> V_57 ) ;
F_25 ( V_1 -> V_56 ) ;
F_25 ( V_1 -> V_55 ) ;
if ( V_1 -> V_38 )
F_26 ( V_1 -> V_38 ) ;
}
static int F_27 ( struct V_1 * V_1 , bool V_58 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
if ( ! V_58 ) {
F_24 ( V_1 ) ;
return 0 ;
}
V_13 = F_20 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_10 ( V_1 ) ;
if ( V_13 < 0 ) {
F_28 ( & V_6 -> V_39 , L_1 ) ;
return V_13 ;
}
return F_29 ( & V_1 -> V_59 ) ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
struct V_60 * V_61 = & V_1 -> V_61 ;
const struct V_62 * V_63 = & V_1 -> V_63 ;
unsigned int V_64 ;
unsigned int V_65 ;
unsigned int V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
int V_13 ;
V_13 = F_5 ( V_6 , V_70 , V_63 -> V_71 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_72 , V_63 -> V_73 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_74 , V_63 -> V_75 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_76 , V_63 -> V_77 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_66 = F_31 ( V_63 -> V_75 , V_61 -> V_75 ) ;
V_67 = F_31 ( V_63 -> V_77 , V_61 -> V_77 ) ;
V_68 = 1 << ( F_32 ( V_66 ) - 1 ) ;
V_69 = 1 << ( F_32 ( V_67 ) - 1 ) ;
V_13 = F_5 ( V_6 , V_78 ,
( ( V_68 - 1 ) << 4 ) | ( V_66 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_79 ,
( ( V_69 - 1 ) << 4 ) | ( V_67 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_64 = 346 * V_69 + 64 + ( 80 >> F_33 (unsigned int, xbin, 3 ) ) ;
V_65 = V_80 ;
V_13 = F_5 ( V_6 , V_81 , V_64 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_82 , V_65 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_13 ;
}
static int F_34 ( struct V_2 * V_4 , int V_83 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 ;
if ( ! V_83 ) {
V_13 = F_7 ( V_1 ,
V_20 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_19 ( V_1 ) ;
}
V_13 = F_30 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_7 ( V_1 , 0 ,
V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_17 ( V_1 ) ;
}
static int F_35 ( struct V_2 * V_4 ,
struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_87 -> V_88 || V_87 -> V_89 )
return - V_90 ;
V_87 -> V_87 = V_1 -> V_61 . V_87 ;
return 0 ;
}
static int F_36 ( struct V_2 * V_4 ,
struct V_84 * V_85 ,
struct V_91 * V_92 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_92 -> V_89 >= 8 || V_92 -> V_87 != V_1 -> V_61 . V_87 )
return - V_90 ;
V_92 -> V_93 = V_94
/ F_33 (unsigned int, 7 , fse->index + 1 ) ;
V_92 -> V_95 = V_92 -> V_93 ;
V_92 -> V_96 = V_97 / ( V_92 -> V_89 + 1 ) ;
V_92 -> V_98 = V_92 -> V_96 ;
return 0 ;
}
static struct V_60 *
F_37 ( struct V_1 * V_1 , struct V_84 * V_85 ,
unsigned int V_88 , T_3 V_99 )
{
switch ( V_99 ) {
case V_100 :
return F_38 ( V_85 , V_88 ) ;
case V_101 :
return & V_1 -> V_61 ;
default:
return NULL ;
}
}
static struct V_62 *
F_39 ( struct V_1 * V_1 , struct V_84 * V_85 ,
unsigned int V_88 , T_3 V_99 )
{
switch ( V_99 ) {
case V_100 :
return F_40 ( V_85 , V_88 ) ;
case V_101 :
return & V_1 -> V_63 ;
default:
return NULL ;
}
}
static int F_41 ( struct V_2 * V_4 ,
struct V_84 * V_85 ,
struct V_102 * V_103 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_103 -> V_61 = * F_37 ( V_1 , V_85 , V_103 -> V_88 ,
V_103 -> V_99 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_4 ,
struct V_84 * V_85 ,
struct V_102 * V_61 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_60 * V_104 ;
struct V_62 * V_105 ;
unsigned int V_75 ;
unsigned int V_77 ;
unsigned int V_106 ;
unsigned int V_107 ;
V_105 = F_39 ( V_1 , V_85 , V_61 -> V_88 ,
V_61 -> V_99 ) ;
V_75 = F_43 (unsigned int, ALIGN(format->format.width, 2),
max(__crop->width / 7, MT9P031_WINDOW_WIDTH_MIN),
__crop->width) ;
V_77 = F_43 (unsigned int, ALIGN(format->format.height, 2),
max(__crop->height / 8, MT9P031_WINDOW_HEIGHT_MIN),
__crop->height) ;
V_106 = F_31 ( V_105 -> V_75 , V_75 ) ;
V_107 = F_31 ( V_105 -> V_77 , V_77 ) ;
V_104 = F_37 ( V_1 , V_85 , V_61 -> V_88 ,
V_61 -> V_99 ) ;
V_104 -> V_75 = V_105 -> V_75 / V_106 ;
V_104 -> V_77 = V_105 -> V_77 / V_107 ;
V_61 -> V_61 = * V_104 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_4 ,
struct V_84 * V_85 ,
struct V_108 * V_63 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_63 -> V_109 = * F_39 ( V_1 , V_85 , V_63 -> V_88 ,
V_63 -> V_99 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_4 ,
struct V_84 * V_85 ,
struct V_108 * V_63 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_60 * V_104 ;
struct V_62 * V_105 ;
struct V_62 V_109 ;
V_109 . V_71 = F_46 ( F_47 ( V_63 -> V_109 . V_71 , 2 ) , V_110 ,
V_111 ) ;
V_109 . V_73 = F_46 ( F_47 ( V_63 -> V_109 . V_73 , 2 ) , V_112 ,
V_113 ) ;
V_109 . V_75 = F_46 ( F_47 ( V_63 -> V_109 . V_75 , 2 ) ,
V_114 ,
V_115 ) ;
V_109 . V_77 = F_46 ( F_47 ( V_63 -> V_109 . V_77 , 2 ) ,
V_116 ,
V_117 ) ;
V_109 . V_75 = F_48 ( V_109 . V_75 , V_118 - V_109 . V_71 ) ;
V_109 . V_77 = F_48 ( V_109 . V_77 , V_119 - V_109 . V_73 ) ;
V_105 = F_39 ( V_1 , V_85 , V_63 -> V_88 , V_63 -> V_99 ) ;
if ( V_109 . V_75 != V_105 -> V_75 || V_109 . V_77 != V_105 -> V_77 ) {
V_104 = F_37 ( V_1 , V_85 , V_63 -> V_88 ,
V_63 -> V_99 ) ;
V_104 -> V_75 = V_109 . V_75 ;
V_104 -> V_77 = V_109 . V_77 ;
}
* V_105 = V_109 ;
V_63 -> V_109 = V_109 ;
return 0 ;
}
static int F_49 ( struct V_120 * V_121 )
{
struct V_1 * V_1 =
F_2 ( V_121 -> V_122 , struct V_1 , V_59 ) ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
T_2 V_8 ;
int V_13 ;
switch ( V_121 -> V_123 ) {
case V_124 :
V_13 = F_5 ( V_6 , V_125 ,
( V_121 -> V_126 >> 16 ) & 0xffff ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_127 ,
V_121 -> V_126 & 0xffff ) ;
case V_128 :
if ( V_121 -> V_126 <= 32 ) {
V_8 = V_121 -> V_126 ;
} else if ( V_121 -> V_126 <= 64 ) {
V_121 -> V_126 &= ~ 1 ;
V_8 = ( 1 << 6 ) | ( V_121 -> V_126 >> 1 ) ;
} else {
V_121 -> V_126 &= ~ 7 ;
V_8 = ( ( V_121 -> V_126 - 64 ) << 5 ) | ( 1 << 6 ) | 32 ;
}
return F_5 ( V_6 , V_129 , V_8 ) ;
case V_130 :
if ( V_121 -> V_126 )
return F_9 ( V_1 ,
0 , V_131 ) ;
else
return F_9 ( V_1 ,
V_131 , 0 ) ;
case V_132 :
if ( V_121 -> V_126 )
return F_9 ( V_1 ,
0 , V_133 ) ;
else
return F_9 ( V_1 ,
V_133 , 0 ) ;
case V_134 :
if ( ! V_121 -> V_126 ) {
if ( V_1 -> V_135 -> V_136 . V_126 != 0 ) {
V_13 = F_49 ( V_1 -> V_135 ) ;
if ( V_13 < 0 )
return V_13 ;
}
if ( V_1 -> V_137 -> V_136 . V_126 != 0 ) {
V_13 = F_49 ( V_1 -> V_137 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return F_5 ( V_6 , V_138 ,
V_139 ) ;
}
V_13 = F_5 ( V_6 , V_140 , 0x05a0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_141 , 0x0a50 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_142 , 0x0aa0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_1 , V_143 ,
0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_144 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_138 ,
( ( V_121 -> V_126 - 1 ) << V_145 )
| V_146 ) ;
case V_147 :
V_13 = F_9 ( V_1 ,
V_121 -> V_126 ? 0 : V_143 ,
V_121 -> V_126 ? V_143 : 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_148 ,
V_121 -> V_126 ? 0 : V_149 ) ;
case V_150 :
return F_5 ( V_6 , V_151 ,
V_121 -> V_126 ) ;
case V_152 :
V_8 = V_121 -> V_126 & ( ( 1 << 9 ) - 1 ) ;
V_13 = F_5 ( V_6 , V_153 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_154 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_155 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_156 , V_8 ) ;
case V_157 :
return F_5 ( V_6 , V_144 ,
V_121 -> V_126 & ( ( 1 << 12 ) - 1 ) ) ;
}
return 0 ;
}
static int F_50 ( struct V_2 * V_4 , int V_58 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 = 0 ;
F_51 ( & V_1 -> V_158 ) ;
if ( V_1 -> V_159 == ! V_58 ) {
V_13 = F_27 ( V_1 , ! ! V_58 ) ;
if ( V_13 < 0 )
goto V_160;
}
V_1 -> V_159 += V_58 ? 1 : - 1 ;
F_52 ( V_1 -> V_159 < 0 ) ;
V_160:
F_53 ( & V_1 -> V_158 ) ;
return V_13 ;
}
static int F_54 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_8 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_4 V_8 ;
int V_13 ;
V_13 = F_20 ( V_1 ) ;
if ( V_13 < 0 ) {
F_28 ( & V_6 -> V_39 , L_2 ) ;
return V_13 ;
}
V_8 = F_3 ( V_6 , V_161 ) ;
if ( V_8 != V_162 ) {
F_28 ( & V_6 -> V_39 , L_3
L_4 , V_8 ) ;
return - V_163 ;
}
F_24 ( V_1 ) ;
F_55 ( & V_6 -> V_39 , L_5 ,
V_6 -> V_164 ) ;
return V_13 ;
}
static int F_56 ( struct V_2 * V_4 , struct V_84 * V_85 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
V_63 = F_40 ( V_85 , 0 ) ;
V_63 -> V_71 = V_165 ;
V_63 -> V_73 = V_166 ;
V_63 -> V_75 = V_94 ;
V_63 -> V_77 = V_97 ;
V_61 = F_38 ( V_85 , 0 ) ;
if ( V_1 -> V_167 == V_168 )
V_61 -> V_87 = V_169 ;
else
V_61 -> V_87 = V_170 ;
V_61 -> V_75 = V_94 ;
V_61 -> V_77 = V_97 ;
V_61 -> V_171 = V_172 ;
V_61 -> V_173 = V_174 ;
return F_50 ( V_4 , 1 ) ;
}
static int F_57 ( struct V_2 * V_4 , struct V_84 * V_85 )
{
return F_50 ( V_4 , 0 ) ;
}
static int F_58 ( struct V_5 * V_6 ,
const struct V_175 * V_176 )
{
struct V_36 * V_37 = V_6 -> V_39 . V_177 ;
struct V_178 * V_179 = F_59 ( V_6 -> V_39 . V_180 ) ;
struct V_1 * V_1 ;
unsigned int V_181 ;
int V_13 ;
if ( V_37 == NULL ) {
F_28 ( & V_6 -> V_39 , L_6 ) ;
return - V_90 ;
}
if ( ! F_60 ( V_179 , V_182 ) ) {
F_61 ( & V_6 -> V_39 ,
L_7 ) ;
return - V_183 ;
}
V_1 = F_62 ( & V_6 -> V_39 , sizeof( * V_1 ) , V_184 ) ;
if ( V_1 == NULL )
return - V_185 ;
V_1 -> V_37 = V_37 ;
V_1 -> V_12 = V_186 ;
V_1 -> V_15 = V_143 ;
V_1 -> V_167 = V_176 -> V_187 ;
V_1 -> V_54 = - 1 ;
V_1 -> V_57 = F_63 ( & V_6 -> V_39 , L_8 ) ;
V_1 -> V_55 = F_63 ( & V_6 -> V_39 , L_9 ) ;
V_1 -> V_56 = F_63 ( & V_6 -> V_39 , L_10 ) ;
if ( F_13 ( V_1 -> V_57 ) || F_13 ( V_1 -> V_55 ) ||
F_13 ( V_1 -> V_56 ) ) {
F_28 ( & V_6 -> V_39 , L_11 ) ;
return - V_163 ;
}
F_64 ( & V_1 -> V_59 , F_65 ( V_188 ) + 6 ) ;
F_66 ( & V_1 -> V_59 , & V_189 ,
V_124 , V_190 ,
V_191 , 1 ,
V_192 ) ;
F_66 ( & V_1 -> V_59 , & V_189 ,
V_128 , V_193 ,
V_194 , 1 , V_195 ) ;
F_66 ( & V_1 -> V_59 , & V_189 ,
V_130 , 0 , 1 , 1 , 0 ) ;
F_66 ( & V_1 -> V_59 , & V_189 ,
V_132 , 0 , 1 , 1 , 0 ) ;
F_66 ( & V_1 -> V_59 , & V_189 ,
V_196 , V_37 -> V_44 ,
V_37 -> V_44 , 1 , V_37 -> V_44 ) ;
F_67 ( & V_1 -> V_59 , & V_189 ,
V_134 ,
F_65 ( V_197 ) - 1 , 0 ,
0 , V_197 ) ;
for ( V_181 = 0 ; V_181 < F_65 ( V_188 ) ; ++ V_181 )
F_68 ( & V_1 -> V_59 , & V_188 [ V_181 ] , NULL ) ;
V_1 -> V_4 . V_198 = & V_1 -> V_59 ;
if ( V_1 -> V_59 . error ) {
F_69 ( V_199 L_12 ,
V_200 , V_1 -> V_59 . error ) ;
V_13 = V_1 -> V_59 . error ;
goto V_201;
}
V_1 -> V_135 = F_70 ( & V_1 -> V_59 , V_147 ) ;
V_1 -> V_137 = F_70 ( & V_1 -> V_59 ,
V_157 ) ;
F_71 ( & V_1 -> V_158 ) ;
F_72 ( & V_1 -> V_4 , V_6 , & V_202 ) ;
V_1 -> V_4 . V_203 = & V_204 ;
V_1 -> V_88 . V_205 = V_206 ;
V_13 = F_73 ( & V_1 -> V_4 . V_207 , 1 , & V_1 -> V_88 , 0 ) ;
if ( V_13 < 0 )
goto V_201;
V_1 -> V_4 . V_205 |= V_208 ;
V_1 -> V_63 . V_75 = V_94 ;
V_1 -> V_63 . V_77 = V_97 ;
V_1 -> V_63 . V_71 = V_165 ;
V_1 -> V_63 . V_73 = V_166 ;
if ( V_1 -> V_167 == V_168 )
V_1 -> V_61 . V_87 = V_169 ;
else
V_1 -> V_61 . V_87 = V_170 ;
V_1 -> V_61 . V_75 = V_94 ;
V_1 -> V_61 . V_77 = V_97 ;
V_1 -> V_61 . V_171 = V_172 ;
V_1 -> V_61 . V_173 = V_174 ;
if ( V_37 -> V_54 != - 1 ) {
V_13 = F_74 ( & V_6 -> V_39 , V_37 -> V_54 ,
V_209 , L_13 ) ;
if ( V_13 < 0 )
goto V_201;
V_1 -> V_54 = V_37 -> V_54 ;
}
V_13 = F_11 ( V_1 ) ;
V_201:
if ( V_13 < 0 ) {
F_75 ( & V_1 -> V_59 ) ;
F_76 ( & V_1 -> V_4 . V_207 ) ;
}
return V_13 ;
}
static int F_77 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_78 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_75 ( & V_1 -> V_59 ) ;
F_79 ( V_4 ) ;
F_76 ( & V_4 -> V_207 ) ;
return 0 ;
}
