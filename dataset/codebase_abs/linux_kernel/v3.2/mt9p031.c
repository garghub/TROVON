static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , T_1 V_7 )
{
T_2 V_8 = F_4 ( V_6 , V_7 ) ;
return V_8 < 0 ? V_8 : F_5 ( V_8 ) ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_7 , T_3 V_8 )
{
return F_7 ( V_6 , V_7 , F_8 ( V_8 ) ) ;
}
static int F_9 ( struct V_1 * V_1 , T_3 V_9 ,
T_3 V_10 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
T_3 V_11 = ( V_1 -> V_12 & ~ V_9 ) | V_10 ;
int V_13 ;
V_13 = F_6 ( V_6 , V_14 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_12 = V_11 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , T_3 V_9 , T_3 V_10 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
T_3 V_11 = ( V_1 -> V_15 & ~ V_9 ) | V_10 ;
int V_13 ;
V_13 = F_6 ( V_6 , V_16 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_15 = V_11 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
int V_13 ;
V_13 = F_6 ( V_6 , V_17 , V_18 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_17 , V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_9 ( V_1 , V_20 ,
0 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_14 ( V_22 ) ; V_21 ++ ) {
if ( V_22 [ V_21 ] . V_23 == V_1 -> V_24 -> V_23 &&
V_22 [ V_21 ] . V_25 == V_1 -> V_24 -> V_25 ) {
V_1 -> V_26 = & V_22 [ V_21 ] ;
return 0 ;
}
}
F_15 ( & V_6 -> V_27 , L_1
L_2 , V_1 -> V_24 -> V_23 ,
V_1 -> V_24 -> V_25 ) ;
return - V_28 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
int V_13 ;
V_13 = F_6 ( V_6 , V_29 ,
V_30 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_31 ,
( V_1 -> V_26 -> V_32 << 8 ) | ( V_1 -> V_26 -> V_33 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_34 , V_1 -> V_26 -> V_35 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
F_17 ( 1000 , 2000 ) ;
V_13 = F_6 ( V_6 , V_29 ,
V_30 |
V_36 ) ;
return V_13 ;
}
static inline int F_18 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
return F_6 ( V_6 , V_29 ,
V_37 ) ;
}
static int F_19 ( struct V_1 * V_1 )
{
if ( V_1 -> V_24 -> V_38 ) {
V_1 -> V_24 -> V_38 ( & V_1 -> V_4 , 1 ) ;
F_17 ( 1000 , 2000 ) ;
}
if ( V_1 -> V_24 -> V_39 )
V_1 -> V_24 -> V_39 ( & V_1 -> V_4 ,
V_1 -> V_24 -> V_23 ) ;
if ( V_1 -> V_24 -> V_38 ) {
V_1 -> V_24 -> V_38 ( & V_1 -> V_4 , 0 ) ;
F_17 ( 1000 , 2000 ) ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_1 )
{
if ( V_1 -> V_24 -> V_38 ) {
V_1 -> V_24 -> V_38 ( & V_1 -> V_4 , 1 ) ;
F_17 ( 1000 , 2000 ) ;
}
if ( V_1 -> V_24 -> V_39 )
V_1 -> V_24 -> V_39 ( & V_1 -> V_4 , 0 ) ;
}
static int F_21 ( struct V_1 * V_1 , bool V_40 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
int V_13 ;
if ( ! V_40 ) {
F_20 ( V_1 ) ;
return 0 ;
}
V_13 = F_19 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_12 ( V_1 ) ;
if ( V_13 < 0 ) {
F_15 ( & V_6 -> V_27 , L_3 ) ;
return V_13 ;
}
return F_22 ( & V_1 -> V_41 ) ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
struct V_42 * V_43 = & V_1 -> V_43 ;
const struct V_44 * V_45 = & V_1 -> V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
unsigned int V_51 ;
int V_13 ;
V_13 = F_6 ( V_6 , V_52 , V_45 -> V_53 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_54 , V_45 -> V_55 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_56 , V_45 -> V_57 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_58 , V_45 -> V_59 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_48 = F_24 ( V_45 -> V_57 , V_43 -> V_57 ) ;
V_49 = F_24 ( V_45 -> V_59 , V_43 -> V_59 ) ;
V_50 = 1 << ( F_25 ( V_48 ) - 1 ) ;
V_51 = 1 << ( F_25 ( V_49 ) - 1 ) ;
V_13 = F_6 ( V_6 , V_60 ,
( ( V_50 - 1 ) << 4 ) | ( V_48 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_61 ,
( ( V_51 - 1 ) << 4 ) | ( V_49 - 1 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_46 = 346 * V_51 + 64 + ( 80 >> F_26 (unsigned int, xbin, 3 ) ) ;
V_47 = V_62 ;
V_13 = F_6 ( V_6 , V_63 , V_46 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_64 , V_47 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_13 ;
}
static int F_27 ( struct V_2 * V_4 , int V_65 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 ;
if ( ! V_65 ) {
V_13 = F_9 ( V_1 ,
V_20 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_18 ( V_1 ) ;
}
V_13 = F_23 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_1 , 0 ,
V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_16 ( V_1 ) ;
}
static int F_28 ( struct V_2 * V_4 ,
struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_69 -> V_70 || V_69 -> V_71 )
return - V_28 ;
V_69 -> V_69 = V_1 -> V_43 . V_69 ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 ,
struct V_66 * V_67 ,
struct V_72 * V_73 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_73 -> V_71 >= 8 || V_73 -> V_69 != V_1 -> V_43 . V_69 )
return - V_28 ;
V_73 -> V_74 = V_75
/ F_30 (unsigned int, 7 , fse->index + 1 ) ;
V_73 -> V_76 = V_73 -> V_74 ;
V_73 -> V_77 = V_78 / ( V_73 -> V_71 + 1 ) ;
V_73 -> V_79 = V_73 -> V_77 ;
return 0 ;
}
static struct V_42 *
F_31 ( struct V_1 * V_1 , struct V_66 * V_67 ,
unsigned int V_70 , T_4 V_80 )
{
switch ( V_80 ) {
case V_81 :
return F_32 ( V_67 , V_70 ) ;
case V_82 :
return & V_1 -> V_43 ;
default:
return NULL ;
}
}
static struct V_44 *
F_33 ( struct V_1 * V_1 , struct V_66 * V_67 ,
unsigned int V_70 , T_4 V_80 )
{
switch ( V_80 ) {
case V_81 :
return F_34 ( V_67 , V_70 ) ;
case V_82 :
return & V_1 -> V_45 ;
default:
return NULL ;
}
}
static int F_35 ( struct V_2 * V_4 ,
struct V_66 * V_67 ,
struct V_83 * V_84 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_84 -> V_43 = * F_31 ( V_1 , V_67 , V_84 -> V_70 ,
V_84 -> V_80 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_4 ,
struct V_66 * V_67 ,
struct V_83 * V_43 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_42 * V_85 ;
struct V_44 * V_86 ;
unsigned int V_57 ;
unsigned int V_59 ;
unsigned int V_87 ;
unsigned int V_88 ;
V_86 = F_33 ( V_1 , V_67 , V_43 -> V_70 ,
V_43 -> V_80 ) ;
V_57 = F_37 (unsigned int, ALIGN(format->format.width, 2),
max(__crop->width / 7, MT9P031_WINDOW_WIDTH_MIN),
__crop->width) ;
V_59 = F_37 (unsigned int, ALIGN(format->format.height, 2),
max(__crop->height / 8, MT9P031_WINDOW_HEIGHT_MIN),
__crop->height) ;
V_87 = F_24 ( V_86 -> V_57 , V_57 ) ;
V_88 = F_24 ( V_86 -> V_59 , V_59 ) ;
V_85 = F_31 ( V_1 , V_67 , V_43 -> V_70 ,
V_43 -> V_80 ) ;
V_85 -> V_57 = V_86 -> V_57 / V_87 ;
V_85 -> V_59 = V_86 -> V_59 / V_88 ;
V_43 -> V_43 = * V_85 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_4 ,
struct V_66 * V_67 ,
struct V_89 * V_45 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_45 -> V_90 = * F_33 ( V_1 , V_67 , V_45 -> V_70 ,
V_45 -> V_80 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_4 ,
struct V_66 * V_67 ,
struct V_89 * V_45 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_42 * V_85 ;
struct V_44 * V_86 ;
struct V_44 V_90 ;
V_90 . V_53 = F_40 ( F_41 ( V_45 -> V_90 . V_53 , 2 ) , V_91 ,
V_92 ) ;
V_90 . V_55 = F_40 ( F_41 ( V_45 -> V_90 . V_55 , 2 ) , V_93 ,
V_94 ) ;
V_90 . V_57 = F_40 ( F_41 ( V_45 -> V_90 . V_57 , 2 ) ,
V_95 ,
V_96 ) ;
V_90 . V_59 = F_40 ( F_41 ( V_45 -> V_90 . V_59 , 2 ) ,
V_97 ,
V_98 ) ;
V_90 . V_57 = F_42 ( V_90 . V_57 , V_99 - V_90 . V_53 ) ;
V_90 . V_59 = F_42 ( V_90 . V_59 , V_100 - V_90 . V_55 ) ;
V_86 = F_33 ( V_1 , V_67 , V_45 -> V_70 , V_45 -> V_80 ) ;
if ( V_90 . V_57 != V_86 -> V_57 || V_90 . V_59 != V_86 -> V_59 ) {
V_85 = F_31 ( V_1 , V_67 , V_45 -> V_70 ,
V_45 -> V_80 ) ;
V_85 -> V_57 = V_90 . V_57 ;
V_85 -> V_59 = V_90 . V_59 ;
}
* V_86 = V_90 ;
V_45 -> V_90 = V_90 ;
return 0 ;
}
static int F_43 ( struct V_101 * V_102 )
{
struct V_1 * V_1 =
F_2 ( V_102 -> V_103 , struct V_1 , V_41 ) ;
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
T_3 V_8 ;
int V_13 ;
switch ( V_102 -> V_104 ) {
case V_105 :
V_13 = F_6 ( V_6 , V_106 ,
( V_102 -> V_107 >> 16 ) & 0xffff ) ;
if ( V_13 < 0 )
return V_13 ;
return F_6 ( V_6 , V_108 ,
V_102 -> V_107 & 0xffff ) ;
case V_109 :
if ( V_102 -> V_107 <= 32 ) {
V_8 = V_102 -> V_107 ;
} else if ( V_102 -> V_107 <= 64 ) {
V_102 -> V_107 &= ~ 1 ;
V_8 = ( 1 << 6 ) | ( V_102 -> V_107 >> 1 ) ;
} else {
V_102 -> V_107 &= ~ 7 ;
V_8 = ( ( V_102 -> V_107 - 64 ) << 5 ) | ( 1 << 6 ) | 32 ;
}
return F_6 ( V_6 , V_110 , V_8 ) ;
case V_111 :
if ( V_102 -> V_107 )
return F_11 ( V_1 ,
0 , V_112 ) ;
else
return F_11 ( V_1 ,
V_112 , 0 ) ;
case V_113 :
if ( V_102 -> V_107 )
return F_11 ( V_1 ,
0 , V_114 ) ;
else
return F_11 ( V_1 ,
V_114 , 0 ) ;
case V_115 :
if ( ! V_102 -> V_107 ) {
V_13 = F_11 ( V_1 ,
0 , V_116 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_6 ( V_6 , V_117 ,
V_118 ) ;
}
V_13 = F_6 ( V_6 , V_119 , 0x05a0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_120 , 0x0a50 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_121 , 0x0aa0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_11 ( V_1 , V_116 ,
0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_6 , V_122 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_6 ( V_6 , V_117 ,
( ( V_102 -> V_107 - 1 ) << V_123 )
| V_124 ) ;
}
return 0 ;
}
static int F_44 ( struct V_2 * V_4 , int V_40 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 = 0 ;
F_45 ( & V_1 -> V_125 ) ;
if ( V_1 -> V_126 == ! V_40 ) {
V_13 = F_21 ( V_1 , ! ! V_40 ) ;
if ( V_13 < 0 )
goto V_127;
}
V_1 -> V_126 += V_40 ? 1 : - 1 ;
F_46 ( V_1 -> V_126 < 0 ) ;
V_127:
F_47 ( & V_1 -> V_125 ) ;
return V_13 ;
}
static int F_48 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_10 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_2 V_8 ;
int V_13 ;
V_13 = F_19 ( V_1 ) ;
if ( V_13 < 0 ) {
F_15 ( & V_6 -> V_27 , L_4 ) ;
return V_13 ;
}
V_8 = F_3 ( V_6 , V_128 ) ;
if ( V_8 != V_129 ) {
F_15 ( & V_6 -> V_27 , L_5
L_6 , V_8 ) ;
return - V_130 ;
}
F_20 ( V_1 ) ;
F_49 ( & V_6 -> V_27 , L_7 ,
V_6 -> V_131 ) ;
return V_13 ;
}
static int F_50 ( struct V_2 * V_4 , struct V_66 * V_67 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
V_45 = F_34 ( V_67 , 0 ) ;
V_45 -> V_53 = V_132 ;
V_45 -> V_55 = V_133 ;
V_45 -> V_57 = V_75 ;
V_45 -> V_59 = V_78 ;
V_43 = F_32 ( V_67 , 0 ) ;
if ( V_1 -> V_24 -> V_134 == V_135 )
V_43 -> V_69 = V_136 ;
else
V_43 -> V_69 = V_137 ;
V_43 -> V_57 = V_75 ;
V_43 -> V_59 = V_78 ;
V_43 -> V_138 = V_139 ;
V_43 -> V_140 = V_141 ;
V_1 -> V_48 = 1 ;
V_1 -> V_49 = 1 ;
return F_44 ( V_4 , 1 ) ;
}
static int F_51 ( struct V_2 * V_4 , struct V_66 * V_67 )
{
return F_44 ( V_4 , 0 ) ;
}
static int F_52 ( struct V_5 * V_6 ,
const struct V_142 * V_143 )
{
struct V_144 * V_24 = V_6 -> V_27 . V_145 ;
struct V_146 * V_147 = F_53 ( V_6 -> V_27 . V_148 ) ;
struct V_1 * V_1 ;
unsigned int V_21 ;
int V_13 ;
if ( V_24 == NULL ) {
F_15 ( & V_6 -> V_27 , L_8 ) ;
return - V_28 ;
}
if ( ! F_54 ( V_147 , V_149 ) ) {
F_55 ( & V_6 -> V_27 ,
L_9 ) ;
return - V_150 ;
}
V_1 = F_56 ( sizeof( * V_1 ) , V_151 ) ;
if ( V_1 == NULL )
return - V_152 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_12 = V_153 ;
V_1 -> V_15 = V_116 ;
F_57 ( & V_1 -> V_41 , F_14 ( V_154 ) + 4 ) ;
F_58 ( & V_1 -> V_41 , & V_155 ,
V_105 , V_156 ,
V_157 , 1 ,
V_158 ) ;
F_58 ( & V_1 -> V_41 , & V_155 ,
V_109 , V_159 ,
V_160 , 1 , V_161 ) ;
F_58 ( & V_1 -> V_41 , & V_155 ,
V_111 , 0 , 1 , 1 , 0 ) ;
F_58 ( & V_1 -> V_41 , & V_155 ,
V_113 , 0 , 1 , 1 , 0 ) ;
for ( V_21 = 0 ; V_21 < F_14 ( V_154 ) ; ++ V_21 )
F_59 ( & V_1 -> V_41 , & V_154 [ V_21 ] , NULL ) ;
V_1 -> V_4 . V_162 = & V_1 -> V_41 ;
if ( V_1 -> V_41 . error )
F_60 ( V_163 L_10 ,
V_164 , V_1 -> V_41 . error ) ;
F_61 ( & V_1 -> V_125 ) ;
F_62 ( & V_1 -> V_4 , V_6 , & V_165 ) ;
V_1 -> V_4 . V_166 = & V_167 ;
V_1 -> V_70 . V_168 = V_169 ;
V_13 = F_63 ( & V_1 -> V_4 . V_170 , 1 , & V_1 -> V_70 , 0 ) ;
if ( V_13 < 0 )
goto V_171;
V_1 -> V_4 . V_168 |= V_172 ;
V_1 -> V_45 . V_57 = V_75 ;
V_1 -> V_45 . V_59 = V_78 ;
V_1 -> V_45 . V_53 = V_132 ;
V_1 -> V_45 . V_55 = V_133 ;
if ( V_1 -> V_24 -> V_134 == V_135 )
V_1 -> V_43 . V_69 = V_136 ;
else
V_1 -> V_43 . V_69 = V_137 ;
V_1 -> V_43 . V_57 = V_75 ;
V_1 -> V_43 . V_59 = V_78 ;
V_1 -> V_43 . V_138 = V_139 ;
V_1 -> V_43 . V_140 = V_141 ;
V_13 = F_13 ( V_1 ) ;
V_171:
if ( V_13 < 0 ) {
F_64 ( & V_1 -> V_41 ) ;
F_65 ( & V_1 -> V_4 . V_170 ) ;
F_66 ( V_1 ) ;
}
return V_13 ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_68 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_64 ( & V_1 -> V_41 ) ;
F_69 ( V_4 ) ;
F_65 ( & V_4 -> V_170 ) ;
F_66 ( V_1 ) ;
return 0 ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_173 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_173 ) ;
}
