static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , const T_2 V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static T_3 F_5 ( struct V_5 * V_6 , unsigned int V_7 )
{
unsigned int V_8 ;
T_3 V_9 ;
V_8 = V_7 + 716 ;
V_9 = F_6 ( 1000000000ULL * V_8 , V_6 -> V_10 ) ;
F_7 ( F_8 ( V_6 ) , L_1 , V_9 ) ;
return V_9 ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
struct V_14 * V_15 = & V_6 -> V_15 ;
unsigned int V_16 ;
unsigned int V_17 ;
T_3 V_18 ;
if ( ! V_12 )
V_12 = & V_6 -> V_19 ;
V_18 = F_5 ( V_6 , V_15 -> V_7 ) ;
V_17 = F_6 ( 1000000000ULL * V_12 -> V_20 ,
( V_21 ) V_18 * V_12 -> V_22 )
- V_15 -> V_23 ;
if ( V_17 > V_24 ) {
V_12 -> V_22 = 1000 ;
V_12 -> V_20 =
F_6 ( ( V_15 -> V_23 + V_24 ) *
( V_21 ) V_18 * V_12 -> V_22 ,
1000000000ULL ) ;
V_17 = F_6 ( 1000000000ULL * V_12 -> V_20 ,
( V_21 ) V_18 * V_12 -> V_22 )
- V_15 -> V_23 ;
}
V_16 = 1600000 / V_18 ;
V_17 = F_11 (unsigned int, vblank, min_vblank, MT9M032_VBLANK_MAX) ;
return F_3 ( V_2 , V_25 , V_17 ) ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_26 ;
V_26 = F_3 ( V_2 , V_27 ,
V_6 -> V_15 . V_7 - 1 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_28 ,
V_6 -> V_15 . V_23 - 1 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_29 ,
V_6 -> V_15 . V_30 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_31 ,
V_6 -> V_15 . V_32 ) ;
if ( ! V_26 )
V_26 = F_9 ( V_6 , NULL ) ;
return V_26 ;
}
static int F_13 ( struct V_5 * V_6 , bool V_33 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
T_2 V_34 = V_35
| 0x0070 ;
if ( V_33 )
V_34 |= V_36 ;
return F_3 ( V_2 , V_37 , V_34 ) ;
}
static int F_14 ( struct V_5 * V_6 )
{
static const struct V_38 V_39 = {
. V_40 = 8000000 ,
. V_41 = 16500000 ,
. V_42 = 2000000 ,
. V_43 = 24000000 ,
. V_44 = 322000000 ,
. V_45 = 693000000 ,
. V_46 = 99000000 ,
. V_47 = 1 ,
. V_48 = 64 ,
. V_49 = 16 ,
. V_50 = 255 ,
. V_51 = 6 ,
. V_52 = 7 ,
} ;
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
struct V_53 * V_54 = V_6 -> V_54 ;
struct V_55 V_56 ;
T_2 V_34 ;
int V_26 ;
V_56 . V_57 = V_54 -> V_57 ;
V_56 . V_10 = V_54 -> V_10 ;
V_26 = F_15 ( & V_2 -> V_58 , & V_39 , & V_56 ) ;
if ( V_26 < 0 )
return V_26 ;
V_6 -> V_10 = V_54 -> V_10 ;
V_26 = F_3 ( V_2 , V_59 ,
( V_56 . V_60 << V_61 ) |
( ( V_56 . V_62 - 1 ) & V_63 ) ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_64 ,
V_65 |
V_66 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_67 , 0x8000 |
V_68 |
V_69 ) ;
if ( ! V_26 ) {
V_34 = ( V_56 . V_70 == 6 ? V_71 : 0 )
| V_72 | 0x001e ;
V_26 = F_3 ( V_2 , V_73 , V_34 ) ;
}
return V_26 ;
}
static int F_16 ( struct V_74 * V_13 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
if ( V_78 -> V_79 != 0 )
return - V_80 ;
V_78 -> V_78 = V_81 ;
return 0 ;
}
static int F_17 ( struct V_74 * V_13 ,
struct V_75 * V_76 ,
struct V_82 * V_83 )
{
if ( V_83 -> V_79 != 0 || V_83 -> V_78 != V_81 )
return - V_80 ;
V_83 -> V_84 = V_85 ;
V_83 -> V_86 = V_85 ;
V_83 -> V_87 = V_88 ;
V_83 -> V_89 = V_88 ;
return 0 ;
}
static struct V_14 *
F_18 ( struct V_5 * V_6 , struct V_75 * V_76 ,
enum V_90 V_91 )
{
switch ( V_91 ) {
case V_92 :
return F_19 ( V_76 , 0 ) ;
case V_93 :
return & V_6 -> V_15 ;
default:
return NULL ;
}
}
static struct V_94 *
F_20 ( struct V_5 * V_6 , struct V_75 * V_76 ,
enum V_90 V_91 )
{
switch ( V_91 ) {
case V_92 :
return F_21 ( V_76 , 0 ) ;
case V_93 :
return & V_6 -> V_95 ;
default:
return NULL ;
}
}
static int F_22 ( struct V_74 * V_13 ,
struct V_75 * V_76 ,
struct V_96 * V_97 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
F_24 ( & V_6 -> V_98 ) ;
V_97 -> V_95 = * F_20 ( V_6 , V_76 , V_97 -> V_91 ) ;
F_25 ( & V_6 -> V_98 ) ;
return 0 ;
}
static int F_26 ( struct V_74 * V_13 ,
struct V_75 * V_76 ,
struct V_96 * V_97 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
int V_26 ;
F_24 ( & V_6 -> V_98 ) ;
if ( V_6 -> V_33 && V_97 -> V_91 == V_93 ) {
V_26 = - V_99 ;
goto V_100;
}
V_97 -> V_95 = * F_20 ( V_6 , V_76 , V_97 -> V_91 ) ;
V_26 = 0 ;
V_100:
F_25 ( & V_6 -> V_98 ) ;
return V_26 ;
}
static int F_27 ( struct V_74 * V_13 ,
struct V_75 * V_76 ,
struct V_101 * V_15 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
F_24 ( & V_6 -> V_98 ) ;
V_15 -> V_102 = * F_18 ( V_6 , V_76 , V_15 -> V_91 ) ;
F_25 ( & V_6 -> V_98 ) ;
return 0 ;
}
static int F_28 ( struct V_74 * V_13 ,
struct V_75 * V_76 ,
struct V_101 * V_15 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
struct V_94 * V_95 ;
struct V_14 * V_103 ;
struct V_14 V_102 ;
int V_26 = 0 ;
F_24 ( & V_6 -> V_98 ) ;
if ( V_6 -> V_33 && V_15 -> V_91 == V_93 ) {
V_26 = - V_99 ;
goto V_100;
}
V_102 . V_30 = F_29 ( F_30 ( V_15 -> V_102 . V_30 , 2 ) , V_104 ,
V_105 ) ;
V_102 . V_32 = F_29 ( F_30 ( V_15 -> V_102 . V_32 , 2 ) , V_106 ,
V_107 ) ;
V_102 . V_7 = F_11 (unsigned int, ALIGN(crop->rect.width, 2),
MT9M032_COLUMN_SIZE_MIN, MT9M032_COLUMN_SIZE_MAX) ;
V_102 . V_23 = F_11 (unsigned int, ALIGN(crop->rect.height, 2),
MT9M032_ROW_SIZE_MIN, MT9M032_ROW_SIZE_MAX) ;
V_102 . V_7 = F_31 (unsigned int, rect.width,
MT9M032_PIXEL_ARRAY_WIDTH - rect.left) ;
V_102 . V_23 = F_31 (unsigned int, rect.height,
MT9M032_PIXEL_ARRAY_HEIGHT - rect.top) ;
V_103 = F_18 ( V_6 , V_76 , V_15 -> V_91 ) ;
if ( V_102 . V_7 != V_103 -> V_7 || V_102 . V_23 != V_103 -> V_23 ) {
V_95 = F_20 ( V_6 , V_76 , V_15 -> V_91 ) ;
V_95 -> V_7 = V_102 . V_7 ;
V_95 -> V_23 = V_102 . V_23 ;
}
* V_103 = V_102 ;
V_15 -> V_102 = V_102 ;
if ( V_15 -> V_91 == V_93 )
V_26 = F_12 ( V_6 ) ;
V_100:
F_25 ( & V_6 -> V_98 ) ;
return V_26 ;
}
static int F_32 ( struct V_74 * V_13 ,
struct V_108 * V_109 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
F_24 ( & V_6 -> V_98 ) ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_12 = V_6 -> V_19 ;
F_25 ( & V_6 -> V_98 ) ;
return 0 ;
}
static int F_33 ( struct V_74 * V_13 ,
struct V_108 * V_109 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
int V_26 ;
F_24 ( & V_6 -> V_98 ) ;
if ( V_6 -> V_33 ) {
V_26 = - V_99 ;
goto V_100;
}
if ( V_109 -> V_12 . V_22 == 0 )
V_109 -> V_12 . V_22 = 1 ;
V_26 = F_9 ( V_6 , & V_109 -> V_12 ) ;
if ( ! V_26 )
V_6 -> V_19 = V_109 -> V_12 ;
V_100:
F_25 ( & V_6 -> V_98 ) ;
return V_26 ;
}
static int F_34 ( struct V_74 * V_13 , int V_33 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
int V_26 ;
F_24 ( & V_6 -> V_98 ) ;
V_26 = F_13 ( V_6 , V_33 ) ;
if ( ! V_26 )
V_6 -> V_33 = V_33 ;
F_25 ( & V_6 -> V_98 ) ;
return V_26 ;
}
static int F_35 ( struct V_74 * V_110 ,
struct V_111 * V_3 )
{
struct V_5 * V_6 = F_23 ( V_110 ) ;
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_112 ;
if ( V_3 -> V_3 > 0xff )
return - V_80 ;
V_112 = F_1 ( V_2 , V_3 -> V_3 ) ;
if ( V_112 < 0 )
return - V_113 ;
V_3 -> V_114 = 2 ;
V_3 -> V_112 = V_112 ;
return 0 ;
}
static int F_36 ( struct V_74 * V_110 ,
const struct V_111 * V_3 )
{
struct V_5 * V_6 = F_23 ( V_110 ) ;
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
if ( V_3 -> V_3 > 0xff )
return - V_80 ;
return F_3 ( V_2 , V_3 -> V_3 , V_3 -> V_112 ) ;
}
static int F_37 ( struct V_5 * V_6 , bool V_115 , bool V_116 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_34 = ( V_115 << V_117 )
| ( V_116 << V_118 )
| V_119
| 0x0007 ;
return F_3 ( V_2 , V_120 , V_34 ) ;
}
static int F_38 ( struct V_5 * V_6 , T_4 V_112 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_121 ;
int V_122 ;
int V_123 ;
T_2 V_34 ;
V_121 = 51 ;
if ( V_112 < 63 ) {
V_122 = 0 ;
V_123 = V_112 ;
} else {
V_122 = 1 ;
V_123 = V_112 / 2 ;
}
V_34 = ( ( V_121 & V_124 )
<< V_125 )
| ( ( V_122 & 1 ) << V_126 )
| ( V_123 & V_127 ) ;
return F_3 ( V_2 , V_128 , V_34 ) ;
}
static int F_39 ( struct V_129 * V_130 )
{
if ( V_130 -> V_131 == V_132 && V_130 -> V_112 >= 63 ) {
V_130 -> V_112 &= ~ 1 ;
}
return 0 ;
}
static int F_40 ( struct V_129 * V_130 )
{
struct V_5 * V_6 =
F_41 ( V_130 -> V_133 , struct V_5 , V_134 ) ;
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_26 ;
switch ( V_130 -> V_131 ) {
case V_132 :
return F_38 ( V_6 , V_130 -> V_112 ) ;
case V_135 :
return F_37 ( V_6 , V_6 -> V_115 -> V_112 ,
V_6 -> V_116 -> V_112 ) ;
case V_136 :
V_26 = F_3 ( V_2 , V_137 ,
( V_130 -> V_112 >> 16 ) & 0xffff ) ;
if ( V_26 < 0 )
return V_26 ;
return F_3 ( V_2 , V_138 ,
V_130 -> V_112 & 0xffff ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_139 * V_140 )
{
struct V_53 * V_54 = V_2 -> V_58 . V_141 ;
struct V_142 * V_143 = V_2 -> V_143 ;
struct V_5 * V_6 ;
int V_144 ;
int V_26 ;
if ( V_54 == NULL ) {
F_43 ( & V_2 -> V_58 , L_2 ) ;
return - V_80 ;
}
if ( ! F_44 ( V_143 , V_145 ) ) {
F_45 ( & V_2 -> V_58 ,
L_3 ) ;
return - V_113 ;
}
if ( ! V_2 -> V_58 . V_141 )
return - V_146 ;
V_6 = F_46 ( & V_2 -> V_58 , sizeof( * V_6 ) , V_147 ) ;
if ( V_6 == NULL )
return - V_148 ;
F_47 ( & V_6 -> V_98 ) ;
V_6 -> V_54 = V_54 ;
F_48 ( & V_6 -> V_13 , V_2 , & V_149 ) ;
V_6 -> V_13 . V_150 |= V_151 ;
V_144 = F_1 ( V_2 , V_152 ) ;
if ( V_144 != V_153 ) {
F_43 ( & V_2 -> V_58 , L_4
L_5 , V_144 ) ;
V_26 = - V_146 ;
goto V_154;
}
F_49 ( & V_2 -> V_58 , L_6 ,
V_2 -> V_155 ) ;
V_6 -> V_19 . V_20 = 1 ;
V_6 -> V_19 . V_22 = 30 ;
V_6 -> V_15 . V_30 = V_156 ;
V_6 -> V_15 . V_32 = V_157 ;
V_6 -> V_15 . V_7 = V_85 ;
V_6 -> V_15 . V_23 = V_88 ;
V_6 -> V_95 . V_7 = V_6 -> V_15 . V_7 ;
V_6 -> V_95 . V_23 = V_6 -> V_15 . V_23 ;
V_6 -> V_95 . V_78 = V_81 ;
V_6 -> V_95 . V_158 = V_159 ;
V_6 -> V_95 . V_160 = V_161 ;
F_50 ( & V_6 -> V_134 , 5 ) ;
F_51 ( & V_6 -> V_134 , & V_162 ,
V_132 , 0 , 127 , 1 , 64 ) ;
V_6 -> V_116 = F_51 ( & V_6 -> V_134 ,
& V_162 ,
V_135 , 0 , 1 , 1 , 0 ) ;
V_6 -> V_115 = F_51 ( & V_6 -> V_134 ,
& V_162 ,
V_163 , 0 , 1 , 1 , 0 ) ;
F_51 ( & V_6 -> V_134 , & V_162 ,
V_136 , V_164 ,
V_165 , 1 ,
V_166 ) ;
F_51 ( & V_6 -> V_134 , & V_162 ,
V_167 , V_54 -> V_10 ,
V_54 -> V_10 , 1 , V_54 -> V_10 ) ;
if ( V_6 -> V_134 . error ) {
V_26 = V_6 -> V_134 . error ;
F_43 ( & V_2 -> V_58 , L_7 , V_26 ) ;
goto V_168;
}
F_52 ( 2 , & V_6 -> V_116 ) ;
V_6 -> V_13 . V_169 = & V_6 -> V_134 ;
V_6 -> V_170 . V_150 = V_171 ;
V_26 = F_53 ( & V_6 -> V_13 . V_172 , 1 , & V_6 -> V_170 , 0 ) ;
if ( V_26 < 0 )
goto V_168;
V_26 = F_3 ( V_2 , V_173 , 1 ) ;
if ( V_26 < 0 )
goto V_174;
V_26 = F_3 ( V_2 , V_173 , 0 ) ;
if ( V_26 < 0 )
goto V_174;
V_26 = F_14 ( V_6 ) ;
if ( V_26 < 0 )
goto V_174;
F_54 ( 10000 , 11000 ) ;
V_26 = F_55 ( & V_6 -> V_134 ) ;
if ( V_26 < 0 )
goto V_174;
V_26 = F_12 ( V_6 ) ;
if ( V_26 < 0 )
goto V_174;
V_26 = F_3 ( V_2 , 0x41 , 0x0000 ) ;
if ( V_26 < 0 )
goto V_174;
V_26 = F_3 ( V_2 , 0x42 , 0x0003 ) ;
if ( V_26 < 0 )
goto V_174;
V_26 = F_3 ( V_2 , 0x43 , 0x0003 ) ;
if ( V_26 < 0 )
goto V_174;
V_26 = F_3 ( V_2 , 0x7f , 0x0000 ) ;
if ( V_26 < 0 )
goto V_174;
if ( V_6 -> V_54 -> V_175 ) {
V_26 = F_3 ( V_2 , V_176 ,
V_177 ) ;
if ( V_26 < 0 )
goto V_174;
}
V_26 = F_3 ( V_2 , V_178 , 1 ) ;
if ( V_26 < 0 )
goto V_174;
F_56 ( 100 ) ;
V_26 = F_3 ( V_2 , V_178 , 0 ) ;
if ( V_26 < 0 )
goto V_174;
F_56 ( 100 ) ;
V_26 = F_13 ( V_6 , false ) ;
if ( V_26 < 0 )
goto V_174;
return V_26 ;
V_174:
F_57 ( & V_6 -> V_13 . V_172 ) ;
V_168:
F_58 ( & V_6 -> V_134 ) ;
V_154:
F_59 ( & V_6 -> V_98 ) ;
return V_26 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_74 * V_13 = F_61 ( V_2 ) ;
struct V_5 * V_6 = F_23 ( V_13 ) ;
F_62 ( V_13 ) ;
F_58 ( & V_6 -> V_134 ) ;
F_57 ( & V_13 -> V_172 ) ;
F_59 ( & V_6 -> V_98 ) ;
return 0 ;
}
