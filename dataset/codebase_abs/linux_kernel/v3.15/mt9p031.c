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
V_13 = F_5 ( V_6 , V_20 ,
F_11 ( V_1 -> V_21 ) ) ;
if ( V_13 < 0 )
return V_13 ;
return F_7 ( V_1 , V_22 ,
0 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
static const struct V_23 V_24 = {
. V_25 = 6000000 ,
. V_26 = 27000000 ,
. V_27 = 2000000 ,
. V_28 = 13500000 ,
. V_29 = 180000000 ,
. V_30 = 360000000 ,
. V_31 = 96000000 ,
. V_32 = 1 ,
. V_33 = 64 ,
. V_34 = 16 ,
. V_35 = 255 ,
. V_36 = 1 ,
. V_37 = 128 ,
} ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
struct V_38 * V_39 = V_1 -> V_39 ;
int V_13 ;
V_1 -> V_40 = F_13 ( & V_6 -> V_41 , NULL ) ;
if ( F_14 ( V_1 -> V_40 ) )
return F_15 ( V_1 -> V_40 ) ;
V_13 = F_16 ( V_1 -> V_40 , V_39 -> V_42 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_39 -> V_42 > V_24 . V_26 ) {
unsigned int div ;
div = F_17 ( V_39 -> V_42 , V_39 -> V_43 ) ;
div = F_18 ( div ) / 2 ;
V_1 -> V_21 = F_19 (unsigned int, div, 64 ) ;
V_1 -> V_44 = false ;
return 0 ;
}
V_1 -> V_45 . V_46 = V_39 -> V_42 ;
V_1 -> V_45 . V_47 = V_39 -> V_43 ;
V_1 -> V_44 = true ;
return F_20 ( & V_6 -> V_41 , & V_24 , & V_1 -> V_45 ) ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
if ( ! V_1 -> V_44 )
return 0 ;
V_13 = F_5 ( V_6 , V_48 ,
V_49 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_50 ,
( V_1 -> V_45 . V_51 << 8 ) | ( V_1 -> V_45 . V_52 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_53 , V_1 -> V_45 . V_54 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
F_22 ( 1000 , 2000 ) ;
V_13 = F_5 ( V_6 , V_48 ,
V_49 |
V_55 ) ;
return V_13 ;
}
static inline int F_23 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
if ( ! V_1 -> V_44 )
return 0 ;
return F_5 ( V_6 , V_48 ,
V_56 ) ;
}
static int F_24 ( struct V_1 * V_1 )
{
int V_13 ;
if ( F_25 ( V_1 -> V_57 ) ) {
F_26 ( V_1 -> V_57 , 0 ) ;
F_22 ( 1000 , 2000 ) ;
}
V_13 = F_27 ( F_28 ( V_1 -> V_58 ) ,
V_1 -> V_58 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_1 -> V_40 ) {
V_13 = F_29 ( V_1 -> V_40 ) ;
if ( V_13 ) {
F_30 ( F_28 ( V_1 -> V_58 ) ,
V_1 -> V_58 ) ;
return V_13 ;
}
}
if ( F_25 ( V_1 -> V_57 ) ) {
F_26 ( V_1 -> V_57 , 1 ) ;
F_22 ( 1000 , 2000 ) ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_1 )
{
if ( F_25 ( V_1 -> V_57 ) ) {
F_26 ( V_1 -> V_57 , 0 ) ;
F_22 ( 1000 , 2000 ) ;
}
F_30 ( F_28 ( V_1 -> V_58 ) ,
V_1 -> V_58 ) ;
if ( V_1 -> V_40 )
F_32 ( V_1 -> V_40 ) ;
}
static int F_33 ( struct V_1 * V_1 , bool V_59 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
if ( ! V_59 ) {
F_31 ( V_1 ) ;
return 0 ;
}
V_13 = F_24 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_10 ( V_1 ) ;
if ( V_13 < 0 ) {
F_34 ( & V_6 -> V_41 , L_1 ) ;
return V_13 ;
}
return F_35 ( & V_1 -> V_60 ) ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
struct V_61 * V_62 = & V_1 -> V_62 ;
const struct V_63 * V_64 = & V_1 -> V_64 ;
unsigned int V_65 ;
unsigned int V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
unsigned int V_70 ;
int V_13 ;
V_13 = F_5 ( V_6 , V_71 , V_64 -> V_72 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_73 , V_64 -> V_74 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_75 , V_64 -> V_76 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_77 , V_64 -> V_78 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_67 = F_37 ( V_64 -> V_76 , V_62 -> V_76 ) ;
V_68 = F_37 ( V_64 -> V_78 , V_62 -> V_78 ) ;
V_69 = 1 << ( F_38 ( V_67 ) - 1 ) ;
V_70 = 1 << ( F_38 ( V_68 ) - 1 ) ;
V_13 = F_5 ( V_6 , V_79 ,
( ( V_69 - 1 ) << 4 ) | ( V_67 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_80 ,
( ( V_70 - 1 ) << 4 ) | ( V_68 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_65 = 346 * V_70 + 64 + ( 80 >> F_39 (unsigned int, xbin, 3 ) ) ;
V_66 = V_81 ;
V_13 = F_5 ( V_6 , V_82 , V_65 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_83 , V_66 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_13 ;
}
static int F_40 ( struct V_2 * V_4 , int V_84 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 ;
if ( ! V_84 ) {
V_13 = F_7 ( V_1 ,
V_22 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_23 ( V_1 ) ;
}
V_13 = F_36 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_7 ( V_1 , 0 ,
V_22 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_21 ( V_1 ) ;
}
static int F_41 ( struct V_2 * V_4 ,
struct V_85 * V_86 ,
struct V_87 * V_88 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_88 -> V_89 || V_88 -> V_90 )
return - V_91 ;
V_88 -> V_88 = V_1 -> V_62 . V_88 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_4 ,
struct V_85 * V_86 ,
struct V_92 * V_93 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_93 -> V_90 >= 8 || V_93 -> V_88 != V_1 -> V_62 . V_88 )
return - V_91 ;
V_93 -> V_94 = V_95
/ F_39 (unsigned int, 7 , fse->index + 1 ) ;
V_93 -> V_96 = V_93 -> V_94 ;
V_93 -> V_97 = V_98 / ( V_93 -> V_90 + 1 ) ;
V_93 -> V_99 = V_93 -> V_97 ;
return 0 ;
}
static struct V_61 *
F_43 ( struct V_1 * V_1 , struct V_85 * V_86 ,
unsigned int V_89 , T_3 V_100 )
{
switch ( V_100 ) {
case V_101 :
return F_44 ( V_86 , V_89 ) ;
case V_102 :
return & V_1 -> V_62 ;
default:
return NULL ;
}
}
static struct V_63 *
F_45 ( struct V_1 * V_1 , struct V_85 * V_86 ,
unsigned int V_89 , T_3 V_100 )
{
switch ( V_100 ) {
case V_101 :
return F_46 ( V_86 , V_89 ) ;
case V_102 :
return & V_1 -> V_64 ;
default:
return NULL ;
}
}
static int F_47 ( struct V_2 * V_4 ,
struct V_85 * V_86 ,
struct V_103 * V_104 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_104 -> V_62 = * F_43 ( V_1 , V_86 , V_104 -> V_89 ,
V_104 -> V_100 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_4 ,
struct V_85 * V_86 ,
struct V_103 * V_62 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_61 * V_105 ;
struct V_63 * V_106 ;
unsigned int V_76 ;
unsigned int V_78 ;
unsigned int V_107 ;
unsigned int V_108 ;
V_106 = F_45 ( V_1 , V_86 , V_62 -> V_89 ,
V_62 -> V_100 ) ;
V_76 = F_49 (unsigned int, ALIGN(format->format.width, 2),
max_t(unsigned int, __crop->width / 7,
MT9P031_WINDOW_WIDTH_MIN),
__crop->width) ;
V_78 = F_49 (unsigned int, ALIGN(format->format.height, 2),
max_t(unsigned int, __crop->height / 8,
MT9P031_WINDOW_HEIGHT_MIN),
__crop->height) ;
V_107 = F_37 ( V_106 -> V_76 , V_76 ) ;
V_108 = F_37 ( V_106 -> V_78 , V_78 ) ;
V_105 = F_43 ( V_1 , V_86 , V_62 -> V_89 ,
V_62 -> V_100 ) ;
V_105 -> V_76 = V_106 -> V_76 / V_107 ;
V_105 -> V_78 = V_106 -> V_78 / V_108 ;
V_62 -> V_62 = * V_105 ;
return 0 ;
}
static int F_50 ( struct V_2 * V_4 ,
struct V_85 * V_86 ,
struct V_109 * V_64 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_64 -> V_110 = * F_45 ( V_1 , V_86 , V_64 -> V_89 ,
V_64 -> V_100 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_4 ,
struct V_85 * V_86 ,
struct V_109 * V_64 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_61 * V_105 ;
struct V_63 * V_106 ;
struct V_63 V_110 ;
V_110 . V_72 = F_52 ( F_53 ( V_64 -> V_110 . V_72 , 2 ) , V_111 ,
V_112 ) ;
V_110 . V_74 = F_52 ( F_53 ( V_64 -> V_110 . V_74 , 2 ) , V_113 ,
V_114 ) ;
V_110 . V_76 = F_49 (unsigned int, ALIGN(crop->rect.width, 2),
MT9P031_WINDOW_WIDTH_MIN,
MT9P031_WINDOW_WIDTH_MAX) ;
V_110 . V_78 = F_49 (unsigned int, ALIGN(crop->rect.height, 2),
MT9P031_WINDOW_HEIGHT_MIN,
MT9P031_WINDOW_HEIGHT_MAX) ;
V_110 . V_76 = F_39 (unsigned int, rect.width,
MT9P031_PIXEL_ARRAY_WIDTH - rect.left) ;
V_110 . V_78 = F_39 (unsigned int, rect.height,
MT9P031_PIXEL_ARRAY_HEIGHT - rect.top) ;
V_106 = F_45 ( V_1 , V_86 , V_64 -> V_89 , V_64 -> V_100 ) ;
if ( V_110 . V_76 != V_106 -> V_76 || V_110 . V_78 != V_106 -> V_78 ) {
V_105 = F_43 ( V_1 , V_86 , V_64 -> V_89 ,
V_64 -> V_100 ) ;
V_105 -> V_76 = V_110 . V_76 ;
V_105 -> V_78 = V_110 . V_78 ;
}
* V_106 = V_110 ;
V_64 -> V_110 = V_110 ;
return 0 ;
}
static int F_54 ( struct V_115 * V_116 )
{
struct V_1 * V_1 =
F_2 ( V_116 -> V_117 , struct V_1 , V_60 ) ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
T_2 V_8 ;
int V_13 ;
switch ( V_116 -> V_118 ) {
case V_119 :
V_13 = F_5 ( V_6 , V_120 ,
( V_116 -> V_121 >> 16 ) & 0xffff ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_122 ,
V_116 -> V_121 & 0xffff ) ;
case V_123 :
if ( V_116 -> V_121 <= 32 ) {
V_8 = V_116 -> V_121 ;
} else if ( V_116 -> V_121 <= 64 ) {
V_116 -> V_121 &= ~ 1 ;
V_8 = ( 1 << 6 ) | ( V_116 -> V_121 >> 1 ) ;
} else {
V_116 -> V_121 &= ~ 7 ;
V_8 = ( ( V_116 -> V_121 - 64 ) << 5 ) | ( 1 << 6 ) | 32 ;
}
return F_5 ( V_6 , V_124 , V_8 ) ;
case V_125 :
if ( V_116 -> V_121 )
return F_9 ( V_1 ,
0 , V_126 ) ;
else
return F_9 ( V_1 ,
V_126 , 0 ) ;
case V_127 :
if ( V_116 -> V_121 )
return F_9 ( V_1 ,
0 , V_128 ) ;
else
return F_9 ( V_1 ,
V_128 , 0 ) ;
case V_129 :
if ( ! V_116 -> V_121 ) {
if ( V_1 -> V_130 -> V_131 . V_121 != 0 ) {
V_13 = F_54 ( V_1 -> V_130 ) ;
if ( V_13 < 0 )
return V_13 ;
}
if ( V_1 -> V_132 -> V_131 . V_121 != 0 ) {
V_13 = F_54 ( V_1 -> V_132 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return F_5 ( V_6 , V_133 ,
V_134 ) ;
}
V_13 = F_5 ( V_6 , V_135 , 0x05a0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_136 , 0x0a50 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_137 , 0x0aa0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_1 , V_138 ,
0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_139 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_133 ,
( ( V_116 -> V_121 - 1 ) << V_140 )
| V_141 ) ;
case V_142 :
V_13 = F_9 ( V_1 ,
V_116 -> V_121 ? 0 : V_138 ,
V_116 -> V_121 ? V_138 : 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_143 ,
V_116 -> V_121 ? 0 : V_144 ) ;
case V_145 :
return F_5 ( V_6 , V_146 ,
V_116 -> V_121 ) ;
case V_147 :
V_8 = V_116 -> V_121 & ( ( 1 << 9 ) - 1 ) ;
V_13 = F_5 ( V_6 , V_148 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_149 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_150 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_151 , V_8 ) ;
case V_152 :
return F_5 ( V_6 , V_139 ,
V_116 -> V_121 & ( ( 1 << 12 ) - 1 ) ) ;
}
return 0 ;
}
static int F_55 ( struct V_2 * V_4 , int V_59 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 = 0 ;
F_56 ( & V_1 -> V_153 ) ;
if ( V_1 -> V_154 == ! V_59 ) {
V_13 = F_33 ( V_1 , ! ! V_59 ) ;
if ( V_13 < 0 )
goto V_155;
}
V_1 -> V_154 += V_59 ? 1 : - 1 ;
F_57 ( V_1 -> V_154 < 0 ) ;
V_155:
F_58 ( & V_1 -> V_153 ) ;
return V_13 ;
}
static int F_59 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_8 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_4 V_8 ;
int V_13 ;
V_13 = F_24 ( V_1 ) ;
if ( V_13 < 0 ) {
F_34 ( & V_6 -> V_41 , L_2 ) ;
return V_13 ;
}
V_8 = F_3 ( V_6 , V_156 ) ;
F_31 ( V_1 ) ;
if ( V_8 != V_157 ) {
F_34 ( & V_6 -> V_41 , L_3
L_4 , V_8 ) ;
return - V_158 ;
}
F_60 ( & V_6 -> V_41 , L_5 ,
V_6 -> V_159 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_4 , struct V_85 * V_86 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
V_64 = F_46 ( V_86 , 0 ) ;
V_64 -> V_72 = V_160 ;
V_64 -> V_74 = V_161 ;
V_64 -> V_76 = V_95 ;
V_64 -> V_78 = V_98 ;
V_62 = F_44 ( V_86 , 0 ) ;
if ( V_1 -> V_162 == V_163 )
V_62 -> V_88 = V_164 ;
else
V_62 -> V_88 = V_165 ;
V_62 -> V_76 = V_95 ;
V_62 -> V_78 = V_98 ;
V_62 -> V_166 = V_167 ;
V_62 -> V_168 = V_169 ;
return F_55 ( V_4 , 1 ) ;
}
static int F_62 ( struct V_2 * V_4 , struct V_85 * V_86 )
{
return F_55 ( V_4 , 0 ) ;
}
static struct V_38 *
F_63 ( struct V_5 * V_6 )
{
struct V_38 * V_39 ;
struct V_170 * V_171 ;
if ( ! F_64 ( V_172 ) || ! V_6 -> V_41 . V_173 )
return V_6 -> V_41 . V_174 ;
V_171 = F_65 ( V_6 -> V_41 . V_173 , NULL ) ;
if ( ! V_171 )
return NULL ;
V_39 = F_66 ( & V_6 -> V_41 , sizeof( * V_39 ) , V_175 ) ;
if ( ! V_39 )
goto V_176;
V_39 -> V_57 = F_67 ( V_6 -> V_41 . V_173 , L_6 , 0 ) ;
F_68 ( V_171 , L_7 , & V_39 -> V_42 ) ;
F_68 ( V_171 , L_8 , & V_39 -> V_43 ) ;
V_176:
F_69 ( V_171 ) ;
return V_39 ;
}
static int F_70 ( struct V_5 * V_6 ,
const struct V_177 * V_178 )
{
struct V_38 * V_39 = F_63 ( V_6 ) ;
struct V_179 * V_180 = F_71 ( V_6 -> V_41 . V_181 ) ;
struct V_1 * V_1 ;
unsigned int V_182 ;
int V_13 ;
if ( V_39 == NULL ) {
F_34 ( & V_6 -> V_41 , L_9 ) ;
return - V_91 ;
}
if ( ! F_72 ( V_180 , V_183 ) ) {
F_73 ( & V_6 -> V_41 ,
L_10 ) ;
return - V_184 ;
}
V_1 = F_66 ( & V_6 -> V_41 , sizeof( * V_1 ) , V_175 ) ;
if ( V_1 == NULL )
return - V_185 ;
V_1 -> V_39 = V_39 ;
V_1 -> V_12 = V_186 ;
V_1 -> V_15 = V_138 ;
V_1 -> V_162 = V_178 -> V_187 ;
V_1 -> V_57 = - 1 ;
V_1 -> V_58 [ 0 ] . V_188 = L_11 ;
V_1 -> V_58 [ 1 ] . V_188 = L_12 ;
V_1 -> V_58 [ 2 ] . V_188 = L_13 ;
V_13 = F_74 ( & V_6 -> V_41 , 3 , V_1 -> V_58 ) ;
if ( V_13 < 0 ) {
F_34 ( & V_6 -> V_41 , L_14 ) ;
return V_13 ;
}
F_75 ( & V_1 -> V_60 , F_28 ( V_189 ) + 6 ) ;
F_76 ( & V_1 -> V_60 , & V_190 ,
V_119 , V_191 ,
V_192 , 1 ,
V_193 ) ;
F_76 ( & V_1 -> V_60 , & V_190 ,
V_123 , V_194 ,
V_195 , 1 , V_196 ) ;
F_76 ( & V_1 -> V_60 , & V_190 ,
V_125 , 0 , 1 , 1 , 0 ) ;
F_76 ( & V_1 -> V_60 , & V_190 ,
V_127 , 0 , 1 , 1 , 0 ) ;
F_76 ( & V_1 -> V_60 , & V_190 ,
V_197 , V_39 -> V_43 ,
V_39 -> V_43 , 1 , V_39 -> V_43 ) ;
F_77 ( & V_1 -> V_60 , & V_190 ,
V_129 ,
F_28 ( V_198 ) - 1 , 0 ,
0 , V_198 ) ;
for ( V_182 = 0 ; V_182 < F_28 ( V_189 ) ; ++ V_182 )
F_78 ( & V_1 -> V_60 , & V_189 [ V_182 ] , NULL ) ;
V_1 -> V_4 . V_199 = & V_1 -> V_60 ;
if ( V_1 -> V_60 . error ) {
F_79 ( V_200 L_15 ,
V_201 , V_1 -> V_60 . error ) ;
V_13 = V_1 -> V_60 . error ;
goto V_176;
}
V_1 -> V_130 = F_80 ( & V_1 -> V_60 , V_142 ) ;
V_1 -> V_132 = F_80 ( & V_1 -> V_60 ,
V_152 ) ;
F_81 ( & V_1 -> V_153 ) ;
F_82 ( & V_1 -> V_4 , V_6 , & V_202 ) ;
V_1 -> V_4 . V_203 = & V_204 ;
V_1 -> V_89 . V_205 = V_206 ;
V_13 = F_83 ( & V_1 -> V_4 . V_207 , 1 , & V_1 -> V_89 , 0 ) ;
if ( V_13 < 0 )
goto V_176;
V_1 -> V_4 . V_205 |= V_208 ;
V_1 -> V_64 . V_76 = V_95 ;
V_1 -> V_64 . V_78 = V_98 ;
V_1 -> V_64 . V_72 = V_160 ;
V_1 -> V_64 . V_74 = V_161 ;
if ( V_1 -> V_162 == V_163 )
V_1 -> V_62 . V_88 = V_164 ;
else
V_1 -> V_62 . V_88 = V_165 ;
V_1 -> V_62 . V_76 = V_95 ;
V_1 -> V_62 . V_78 = V_98 ;
V_1 -> V_62 . V_166 = V_167 ;
V_1 -> V_62 . V_168 = V_169 ;
if ( F_25 ( V_39 -> V_57 ) ) {
V_13 = F_84 ( & V_6 -> V_41 , V_39 -> V_57 ,
V_209 , L_16 ) ;
if ( V_13 < 0 )
goto V_176;
V_1 -> V_57 = V_39 -> V_57 ;
}
V_13 = F_12 ( V_1 ) ;
V_176:
if ( V_13 < 0 ) {
F_85 ( & V_1 -> V_60 ) ;
F_86 ( & V_1 -> V_4 . V_207 ) ;
}
return V_13 ;
}
static int F_87 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_88 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_85 ( & V_1 -> V_60 ) ;
F_89 ( V_4 ) ;
F_86 ( & V_4 -> V_207 ) ;
return 0 ;
}
