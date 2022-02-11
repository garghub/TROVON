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
int V_13 ;
if ( F_21 ( V_1 -> V_54 ) ) {
F_22 ( V_1 -> V_54 , 0 ) ;
F_18 ( 1000 , 2000 ) ;
}
V_13 = F_23 ( F_24 ( V_1 -> V_55 ) ,
V_1 -> V_55 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_1 -> V_38 )
F_25 ( V_1 -> V_38 ) ;
if ( F_21 ( V_1 -> V_54 ) ) {
F_22 ( V_1 -> V_54 , 1 ) ;
F_18 ( 1000 , 2000 ) ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_1 )
{
if ( F_21 ( V_1 -> V_54 ) ) {
F_22 ( V_1 -> V_54 , 0 ) ;
F_18 ( 1000 , 2000 ) ;
}
F_27 ( F_24 ( V_1 -> V_55 ) ,
V_1 -> V_55 ) ;
if ( V_1 -> V_38 )
F_28 ( V_1 -> V_38 ) ;
}
static int F_29 ( struct V_1 * V_1 , bool V_56 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
if ( ! V_56 ) {
F_26 ( V_1 ) ;
return 0 ;
}
V_13 = F_20 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_10 ( V_1 ) ;
if ( V_13 < 0 ) {
F_30 ( & V_6 -> V_39 , L_1 ) ;
return V_13 ;
}
return F_31 ( & V_1 -> V_57 ) ;
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
struct V_58 * V_59 = & V_1 -> V_59 ;
const struct V_60 * V_61 = & V_1 -> V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
unsigned int V_64 ;
unsigned int V_65 ;
unsigned int V_66 ;
unsigned int V_67 ;
int V_13 ;
V_13 = F_5 ( V_6 , V_68 , V_61 -> V_69 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_70 , V_61 -> V_71 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_72 , V_61 -> V_73 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_74 , V_61 -> V_75 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_64 = F_33 ( V_61 -> V_73 , V_59 -> V_73 ) ;
V_65 = F_33 ( V_61 -> V_75 , V_59 -> V_75 ) ;
V_66 = 1 << ( F_34 ( V_64 ) - 1 ) ;
V_67 = 1 << ( F_34 ( V_65 ) - 1 ) ;
V_13 = F_5 ( V_6 , V_76 ,
( ( V_66 - 1 ) << 4 ) | ( V_64 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_77 ,
( ( V_67 - 1 ) << 4 ) | ( V_65 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_62 = 346 * V_67 + 64 + ( 80 >> F_35 (unsigned int, xbin, 3 ) ) ;
V_63 = V_78 ;
V_13 = F_5 ( V_6 , V_79 , V_62 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_80 , V_63 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_13 ;
}
static int F_36 ( struct V_2 * V_4 , int V_81 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 ;
if ( ! V_81 ) {
V_13 = F_7 ( V_1 ,
V_20 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_19 ( V_1 ) ;
}
V_13 = F_32 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_7 ( V_1 , 0 ,
V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_17 ( V_1 ) ;
}
static int F_37 ( struct V_2 * V_4 ,
struct V_82 * V_83 ,
struct V_84 * V_85 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_85 -> V_86 || V_85 -> V_87 )
return - V_88 ;
V_85 -> V_85 = V_1 -> V_59 . V_85 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_4 ,
struct V_82 * V_83 ,
struct V_89 * V_90 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_90 -> V_87 >= 8 || V_90 -> V_85 != V_1 -> V_59 . V_85 )
return - V_88 ;
V_90 -> V_91 = V_92
/ F_35 (unsigned int, 7 , fse->index + 1 ) ;
V_90 -> V_93 = V_90 -> V_91 ;
V_90 -> V_94 = V_95 / ( V_90 -> V_87 + 1 ) ;
V_90 -> V_96 = V_90 -> V_94 ;
return 0 ;
}
static struct V_58 *
F_39 ( struct V_1 * V_1 , struct V_82 * V_83 ,
unsigned int V_86 , T_3 V_97 )
{
switch ( V_97 ) {
case V_98 :
return F_40 ( V_83 , V_86 ) ;
case V_99 :
return & V_1 -> V_59 ;
default:
return NULL ;
}
}
static struct V_60 *
F_41 ( struct V_1 * V_1 , struct V_82 * V_83 ,
unsigned int V_86 , T_3 V_97 )
{
switch ( V_97 ) {
case V_98 :
return F_42 ( V_83 , V_86 ) ;
case V_99 :
return & V_1 -> V_61 ;
default:
return NULL ;
}
}
static int F_43 ( struct V_2 * V_4 ,
struct V_82 * V_83 ,
struct V_100 * V_101 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_101 -> V_59 = * F_39 ( V_1 , V_83 , V_101 -> V_86 ,
V_101 -> V_97 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_4 ,
struct V_82 * V_83 ,
struct V_100 * V_59 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_58 * V_102 ;
struct V_60 * V_103 ;
unsigned int V_73 ;
unsigned int V_75 ;
unsigned int V_104 ;
unsigned int V_105 ;
V_103 = F_41 ( V_1 , V_83 , V_59 -> V_86 ,
V_59 -> V_97 ) ;
V_73 = F_45 (unsigned int, ALIGN(format->format.width, 2),
max(__crop->width / 7, MT9P031_WINDOW_WIDTH_MIN),
__crop->width) ;
V_75 = F_45 (unsigned int, ALIGN(format->format.height, 2),
max(__crop->height / 8, MT9P031_WINDOW_HEIGHT_MIN),
__crop->height) ;
V_104 = F_33 ( V_103 -> V_73 , V_73 ) ;
V_105 = F_33 ( V_103 -> V_75 , V_75 ) ;
V_102 = F_39 ( V_1 , V_83 , V_59 -> V_86 ,
V_59 -> V_97 ) ;
V_102 -> V_73 = V_103 -> V_73 / V_104 ;
V_102 -> V_75 = V_103 -> V_75 / V_105 ;
V_59 -> V_59 = * V_102 ;
return 0 ;
}
static int F_46 ( struct V_2 * V_4 ,
struct V_82 * V_83 ,
struct V_106 * V_61 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_61 -> V_107 = * F_41 ( V_1 , V_83 , V_61 -> V_86 ,
V_61 -> V_97 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_4 ,
struct V_82 * V_83 ,
struct V_106 * V_61 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_58 * V_102 ;
struct V_60 * V_103 ;
struct V_60 V_107 ;
V_107 . V_69 = F_48 ( F_49 ( V_61 -> V_107 . V_69 , 2 ) , V_108 ,
V_109 ) ;
V_107 . V_71 = F_48 ( F_49 ( V_61 -> V_107 . V_71 , 2 ) , V_110 ,
V_111 ) ;
V_107 . V_73 = F_48 ( F_49 ( V_61 -> V_107 . V_73 , 2 ) ,
V_112 ,
V_113 ) ;
V_107 . V_75 = F_48 ( F_49 ( V_61 -> V_107 . V_75 , 2 ) ,
V_114 ,
V_115 ) ;
V_107 . V_73 = F_50 ( V_107 . V_73 , V_116 - V_107 . V_69 ) ;
V_107 . V_75 = F_50 ( V_107 . V_75 , V_117 - V_107 . V_71 ) ;
V_103 = F_41 ( V_1 , V_83 , V_61 -> V_86 , V_61 -> V_97 ) ;
if ( V_107 . V_73 != V_103 -> V_73 || V_107 . V_75 != V_103 -> V_75 ) {
V_102 = F_39 ( V_1 , V_83 , V_61 -> V_86 ,
V_61 -> V_97 ) ;
V_102 -> V_73 = V_107 . V_73 ;
V_102 -> V_75 = V_107 . V_75 ;
}
* V_103 = V_107 ;
V_61 -> V_107 = V_107 ;
return 0 ;
}
static int F_51 ( struct V_118 * V_119 )
{
struct V_1 * V_1 =
F_2 ( V_119 -> V_120 , struct V_1 , V_57 ) ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
T_2 V_8 ;
int V_13 ;
switch ( V_119 -> V_121 ) {
case V_122 :
V_13 = F_5 ( V_6 , V_123 ,
( V_119 -> V_124 >> 16 ) & 0xffff ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_125 ,
V_119 -> V_124 & 0xffff ) ;
case V_126 :
if ( V_119 -> V_124 <= 32 ) {
V_8 = V_119 -> V_124 ;
} else if ( V_119 -> V_124 <= 64 ) {
V_119 -> V_124 &= ~ 1 ;
V_8 = ( 1 << 6 ) | ( V_119 -> V_124 >> 1 ) ;
} else {
V_119 -> V_124 &= ~ 7 ;
V_8 = ( ( V_119 -> V_124 - 64 ) << 5 ) | ( 1 << 6 ) | 32 ;
}
return F_5 ( V_6 , V_127 , V_8 ) ;
case V_128 :
if ( V_119 -> V_124 )
return F_9 ( V_1 ,
0 , V_129 ) ;
else
return F_9 ( V_1 ,
V_129 , 0 ) ;
case V_130 :
if ( V_119 -> V_124 )
return F_9 ( V_1 ,
0 , V_131 ) ;
else
return F_9 ( V_1 ,
V_131 , 0 ) ;
case V_132 :
if ( ! V_119 -> V_124 ) {
if ( V_1 -> V_133 -> V_134 . V_124 != 0 ) {
V_13 = F_51 ( V_1 -> V_133 ) ;
if ( V_13 < 0 )
return V_13 ;
}
if ( V_1 -> V_135 -> V_134 . V_124 != 0 ) {
V_13 = F_51 ( V_1 -> V_135 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return F_5 ( V_6 , V_136 ,
V_137 ) ;
}
V_13 = F_5 ( V_6 , V_138 , 0x05a0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_139 , 0x0a50 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_140 , 0x0aa0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_1 , V_141 ,
0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_142 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_136 ,
( ( V_119 -> V_124 - 1 ) << V_143 )
| V_144 ) ;
case V_145 :
V_13 = F_9 ( V_1 ,
V_119 -> V_124 ? 0 : V_141 ,
V_119 -> V_124 ? V_141 : 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_146 ,
V_119 -> V_124 ? 0 : V_147 ) ;
case V_148 :
return F_5 ( V_6 , V_149 ,
V_119 -> V_124 ) ;
case V_150 :
V_8 = V_119 -> V_124 & ( ( 1 << 9 ) - 1 ) ;
V_13 = F_5 ( V_6 , V_151 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_152 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_153 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_154 , V_8 ) ;
case V_155 :
return F_5 ( V_6 , V_142 ,
V_119 -> V_124 & ( ( 1 << 12 ) - 1 ) ) ;
}
return 0 ;
}
static int F_52 ( struct V_2 * V_4 , int V_56 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 = 0 ;
F_53 ( & V_1 -> V_156 ) ;
if ( V_1 -> V_157 == ! V_56 ) {
V_13 = F_29 ( V_1 , ! ! V_56 ) ;
if ( V_13 < 0 )
goto V_158;
}
V_1 -> V_157 += V_56 ? 1 : - 1 ;
F_54 ( V_1 -> V_157 < 0 ) ;
V_158:
F_55 ( & V_1 -> V_156 ) ;
return V_13 ;
}
static int F_56 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_8 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_4 V_8 ;
int V_13 ;
V_13 = F_20 ( V_1 ) ;
if ( V_13 < 0 ) {
F_30 ( & V_6 -> V_39 , L_2 ) ;
return V_13 ;
}
V_8 = F_3 ( V_6 , V_159 ) ;
F_26 ( V_1 ) ;
if ( V_8 != V_160 ) {
F_30 ( & V_6 -> V_39 , L_3
L_4 , V_8 ) ;
return - V_161 ;
}
F_57 ( & V_6 -> V_39 , L_5 ,
V_6 -> V_162 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_4 , struct V_82 * V_83 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
V_61 = F_42 ( V_83 , 0 ) ;
V_61 -> V_69 = V_163 ;
V_61 -> V_71 = V_164 ;
V_61 -> V_73 = V_92 ;
V_61 -> V_75 = V_95 ;
V_59 = F_40 ( V_83 , 0 ) ;
if ( V_1 -> V_165 == V_166 )
V_59 -> V_85 = V_167 ;
else
V_59 -> V_85 = V_168 ;
V_59 -> V_73 = V_92 ;
V_59 -> V_75 = V_95 ;
V_59 -> V_169 = V_170 ;
V_59 -> V_171 = V_172 ;
return F_52 ( V_4 , 1 ) ;
}
static int F_59 ( struct V_2 * V_4 , struct V_82 * V_83 )
{
return F_52 ( V_4 , 0 ) ;
}
static struct V_36 *
F_60 ( struct V_5 * V_6 )
{
struct V_36 * V_37 ;
struct V_173 * V_174 ;
if ( ! F_61 ( V_175 ) || ! V_6 -> V_39 . V_176 )
return V_6 -> V_39 . V_177 ;
V_174 = F_62 ( V_6 -> V_39 . V_176 , NULL ) ;
if ( ! V_174 )
return NULL ;
V_37 = F_63 ( & V_6 -> V_39 , sizeof( * V_37 ) , V_178 ) ;
if ( ! V_37 )
goto V_179;
V_37 -> V_54 = F_64 ( V_6 -> V_39 . V_176 , L_6 , 0 ) ;
F_65 ( V_174 , L_7 , & V_37 -> V_40 ) ;
F_65 ( V_174 , L_8 , & V_37 -> V_44 ) ;
V_179:
F_66 ( V_174 ) ;
return V_37 ;
}
static int F_67 ( struct V_5 * V_6 ,
const struct V_180 * V_181 )
{
struct V_36 * V_37 = F_60 ( V_6 ) ;
struct V_182 * V_183 = F_68 ( V_6 -> V_39 . V_184 ) ;
struct V_1 * V_1 ;
unsigned int V_185 ;
int V_13 ;
if ( V_37 == NULL ) {
F_30 ( & V_6 -> V_39 , L_9 ) ;
return - V_88 ;
}
if ( ! F_69 ( V_183 , V_186 ) ) {
F_70 ( & V_6 -> V_39 ,
L_10 ) ;
return - V_187 ;
}
V_1 = F_63 ( & V_6 -> V_39 , sizeof( * V_1 ) , V_178 ) ;
if ( V_1 == NULL )
return - V_188 ;
V_1 -> V_37 = V_37 ;
V_1 -> V_12 = V_189 ;
V_1 -> V_15 = V_141 ;
V_1 -> V_165 = V_181 -> V_190 ;
V_1 -> V_54 = - 1 ;
V_1 -> V_55 [ 0 ] . V_191 = L_11 ;
V_1 -> V_55 [ 1 ] . V_191 = L_12 ;
V_1 -> V_55 [ 2 ] . V_191 = L_13 ;
V_13 = F_71 ( & V_6 -> V_39 , 3 , V_1 -> V_55 ) ;
if ( V_13 < 0 ) {
F_30 ( & V_6 -> V_39 , L_14 ) ;
return V_13 ;
}
F_72 ( & V_1 -> V_57 , F_24 ( V_192 ) + 6 ) ;
F_73 ( & V_1 -> V_57 , & V_193 ,
V_122 , V_194 ,
V_195 , 1 ,
V_196 ) ;
F_73 ( & V_1 -> V_57 , & V_193 ,
V_126 , V_197 ,
V_198 , 1 , V_199 ) ;
F_73 ( & V_1 -> V_57 , & V_193 ,
V_128 , 0 , 1 , 1 , 0 ) ;
F_73 ( & V_1 -> V_57 , & V_193 ,
V_130 , 0 , 1 , 1 , 0 ) ;
F_73 ( & V_1 -> V_57 , & V_193 ,
V_200 , V_37 -> V_44 ,
V_37 -> V_44 , 1 , V_37 -> V_44 ) ;
F_74 ( & V_1 -> V_57 , & V_193 ,
V_132 ,
F_24 ( V_201 ) - 1 , 0 ,
0 , V_201 ) ;
for ( V_185 = 0 ; V_185 < F_24 ( V_192 ) ; ++ V_185 )
F_75 ( & V_1 -> V_57 , & V_192 [ V_185 ] , NULL ) ;
V_1 -> V_4 . V_202 = & V_1 -> V_57 ;
if ( V_1 -> V_57 . error ) {
F_76 ( V_203 L_15 ,
V_204 , V_1 -> V_57 . error ) ;
V_13 = V_1 -> V_57 . error ;
goto V_179;
}
V_1 -> V_133 = F_77 ( & V_1 -> V_57 , V_145 ) ;
V_1 -> V_135 = F_77 ( & V_1 -> V_57 ,
V_155 ) ;
F_78 ( & V_1 -> V_156 ) ;
F_79 ( & V_1 -> V_4 , V_6 , & V_205 ) ;
V_1 -> V_4 . V_206 = & V_207 ;
V_1 -> V_86 . V_208 = V_209 ;
V_13 = F_80 ( & V_1 -> V_4 . V_210 , 1 , & V_1 -> V_86 , 0 ) ;
if ( V_13 < 0 )
goto V_179;
V_1 -> V_4 . V_208 |= V_211 ;
V_1 -> V_61 . V_73 = V_92 ;
V_1 -> V_61 . V_75 = V_95 ;
V_1 -> V_61 . V_69 = V_163 ;
V_1 -> V_61 . V_71 = V_164 ;
if ( V_1 -> V_165 == V_166 )
V_1 -> V_59 . V_85 = V_167 ;
else
V_1 -> V_59 . V_85 = V_168 ;
V_1 -> V_59 . V_73 = V_92 ;
V_1 -> V_59 . V_75 = V_95 ;
V_1 -> V_59 . V_169 = V_170 ;
V_1 -> V_59 . V_171 = V_172 ;
if ( F_21 ( V_37 -> V_54 ) ) {
V_13 = F_81 ( & V_6 -> V_39 , V_37 -> V_54 ,
V_212 , L_16 ) ;
if ( V_13 < 0 )
goto V_179;
V_1 -> V_54 = V_37 -> V_54 ;
}
V_13 = F_11 ( V_1 ) ;
V_179:
if ( V_13 < 0 ) {
F_82 ( & V_1 -> V_57 ) ;
F_83 ( & V_1 -> V_4 . V_210 ) ;
}
return V_13 ;
}
static int F_84 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_85 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_82 ( & V_1 -> V_57 ) ;
F_86 ( V_4 ) ;
F_83 ( & V_4 -> V_210 ) ;
return 0 ;
}
