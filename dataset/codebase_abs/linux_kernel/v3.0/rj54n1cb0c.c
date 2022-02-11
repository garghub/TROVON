static const struct V_1 * F_1 (
enum V_2 V_3 , const struct V_1 * V_4 ,
int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( V_4 [ V_6 ] . V_3 == V_3 )
return V_4 + V_6 ;
return NULL ;
}
static struct V_7 * F_2 ( const struct V_8 * V_9 )
{
return F_3 ( F_4 ( V_9 ) , struct V_7 , V_10 ) ;
}
static int F_5 ( struct V_8 * V_9 , const T_1 V_11 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
if ( V_7 -> V_13 != V_11 >> 8 ) {
F_6 ( & V_9 -> V_14 , L_1 , 0xff , V_11 >> 8 ) ;
V_12 = F_7 ( V_9 , 0xff , V_11 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_7 -> V_13 = V_11 >> 8 ;
}
return F_8 ( V_9 , V_11 & 0xff ) ;
}
static int F_9 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_2 V_15 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
if ( V_7 -> V_13 != V_11 >> 8 ) {
F_6 ( & V_9 -> V_14 , L_1 , 0xff , V_11 >> 8 ) ;
V_12 = F_7 ( V_9 , 0xff , V_11 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_7 -> V_13 = V_11 >> 8 ;
}
F_6 ( & V_9 -> V_14 , L_1 , V_11 & 0xff , V_15 ) ;
return F_7 ( V_9 , V_11 & 0xff , V_15 ) ;
}
static int F_10 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_2 V_15 , const T_2 V_16 )
{
int V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_9 ( V_9 , V_11 , ( V_12 & ~ V_16 ) | ( V_15 & V_16 ) ) ;
}
static int F_11 ( struct V_8 * V_9 ,
const struct V_17 * V_18 , const int V_5 )
{
int V_6 , V_12 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_12 = F_9 ( V_9 , V_18 -> V_11 , V_18 -> V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
V_18 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_20 * V_21 , unsigned int V_22 ,
enum V_2 * V_3 )
{
if ( V_22 >= F_13 ( V_23 ) )
return - V_24 ;
* V_3 = V_23 [ V_22 ] . V_3 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 , int V_25 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
return F_10 ( V_9 , V_26 , ( ! V_25 ) << 7 , 0x80 ) ;
}
static int F_16 ( struct V_27 * V_28 ,
unsigned long V_29 )
{
struct V_20 * V_21 = F_17 ( V_28 ) ;
struct V_8 * V_9 = F_15 ( V_21 ) ;
if ( V_29 & V_30 )
return F_9 ( V_9 , V_31 , 1 << 4 ) ;
else
return F_9 ( V_9 , V_31 , 0 ) ;
}
static unsigned long F_18 ( struct V_27 * V_28 )
{
struct V_32 * V_33 = F_19 ( V_28 ) ;
const unsigned long V_29 =
V_30 | V_34 |
V_35 | V_36 |
V_37 | V_38 |
V_39 ;
return F_20 ( V_33 , V_29 ) ;
}
static int F_21 ( struct V_8 * V_9 ,
T_1 V_40 , T_1 V_41 , T_1 V_42 ,
T_3 V_43 , T_3 V_44 )
{
int V_12 ;
V_12 = F_9 ( V_9 , V_42 ,
( ( V_43 >> 4 ) & 0x70 ) |
( ( V_44 >> 8 ) & 7 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_40 , V_43 & 0xff ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_41 , V_44 & 0xff ) ;
return V_12 ;
}
static int F_22 ( struct V_8 * V_9 )
{
int V_12 = F_9 ( V_9 , V_45 , 1 ) ;
F_23 ( 10 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_45 , 0 ) ;
return V_12 ;
}
static int F_24 ( struct V_20 * V_21 , struct V_46 * V_47 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_48 * V_49 = & V_47 -> V_50 ;
int V_51 = 0 , V_52 , V_53 ,
V_54 = V_49 -> V_43 , V_55 = V_49 -> V_44 ;
int V_12 ;
F_25 ( & V_51 , & V_54 ,
V_56 , 8 , V_57 ) ;
F_25 ( & V_51 , & V_55 ,
V_58 , 8 , V_59 ) ;
V_52 = ( V_54 * 1024 + V_7 -> V_60 / 2 ) / V_7 -> V_60 ;
V_53 = ( V_55 * 1024 + V_7 -> V_60 / 2 ) / V_7 -> V_60 ;
F_6 ( & V_9 -> V_14 , L_2 ,
V_54 , V_55 , V_7 -> V_60 , V_52 , V_53 ) ;
V_12 = F_26 ( V_21 , & V_54 , & V_55 , & V_52 , & V_53 ) ;
if ( V_12 < 0 )
return V_12 ;
V_7 -> V_43 = V_52 ;
V_7 -> V_44 = V_53 ;
V_7 -> V_60 = V_12 ;
V_7 -> V_49 . V_43 = V_54 ;
V_7 -> V_49 . V_44 = V_55 ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 , struct V_46 * V_47 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_47 -> V_50 = V_7 -> V_49 ;
V_47 -> type = V_61 ;
return 0 ;
}
static int F_28 ( struct V_20 * V_21 , struct V_62 * V_47 )
{
V_47 -> V_63 . V_64 = V_56 ;
V_47 -> V_63 . V_65 = V_58 ;
V_47 -> V_63 . V_43 = V_57 ;
V_47 -> V_63 . V_44 = V_59 ;
V_47 -> V_66 = V_47 -> V_63 ;
V_47 -> type = V_61 ;
V_47 -> V_67 . V_68 = 1 ;
V_47 -> V_67 . V_69 = 1 ;
return 0 ;
}
static int F_29 ( struct V_20 * V_21 ,
struct V_70 * V_71 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_71 -> V_3 = V_7 -> V_4 -> V_3 ;
V_71 -> V_72 = V_7 -> V_4 -> V_72 ;
V_71 -> V_73 = V_74 ;
V_71 -> V_43 = V_7 -> V_43 ;
V_71 -> V_44 = V_7 -> V_44 ;
return 0 ;
}
static int F_26 ( struct V_20 * V_21 , T_4 * V_75 , T_4 * V_76 ,
T_4 * V_77 , T_4 * V_78 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
unsigned int V_79 , V_60 , V_54 = * V_75 , V_55 = * V_76 ,
V_52 = * V_77 , V_53 = * V_78 ;
T_1 V_80 , V_81 , V_82 , V_83 , V_84 , V_85 ;
unsigned int V_86 , V_87 , V_88 ;
int V_12 ;
if ( V_52 > F_30 ( 512U , V_54 / 2 ) ) {
if ( 2 * V_52 > V_57 ) {
V_54 = V_57 ;
V_52 = V_57 / 2 ;
} else {
V_54 = V_52 * 2 ;
}
F_6 ( & V_9 -> V_14 , L_3 ,
V_54 , V_52 ) ;
}
if ( V_53 > F_30 ( 384U , V_55 / 2 ) ) {
if ( 2 * V_53 > V_59 ) {
V_55 = V_59 ;
V_53 = V_59 / 2 ;
} else {
V_55 = V_53 * 2 ;
}
F_6 ( & V_9 -> V_14 , L_4 ,
V_55 , V_53 ) ;
}
V_12 = F_21 ( V_9 , V_89 ,
V_90 ,
V_91 , V_52 , V_53 ) ;
if ( ! V_12 )
V_12 = F_21 ( V_9 , V_92 ,
V_93 ,
V_94 , V_52 , V_53 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_52 > V_54 && V_53 > V_55 ) {
V_54 = V_52 ;
V_55 = V_53 ;
V_60 = 1024 ;
} else {
unsigned int V_95 , V_96 ;
V_95 = ( V_54 * 1024 + V_52 / 2 ) / V_52 ;
V_96 = ( V_55 * 1024 + V_53 / 2 ) / V_53 ;
if ( V_95 > V_96 &&
( V_53 * V_95 + 512 ) / 1024 > V_59 )
V_60 = ( V_59 * 1024 + V_53 / 2 ) /
V_53 ;
else if ( V_96 > V_95 &&
( V_52 * V_96 + 512 ) / 1024 > V_57 )
V_60 = ( V_57 * 1024 + V_52 / 2 ) /
V_52 ;
else
V_60 = F_30 ( V_95 , V_96 ) ;
switch ( V_60 ) {
case 2040 ... 2047 :
V_60 = 2039 ;
break;
case 4080 ... 4095 :
V_60 = 4079 ;
break;
case 8160 ... 8191 :
V_60 = 8159 ;
break;
case 16320 ... 16384 :
V_60 = 16319 ;
}
}
V_12 = F_9 ( V_9 , V_97 , V_60 & 0xff ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_98 , V_60 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_79 = F_31 ( V_60 / 1024 , 15U ) ;
V_80 = 1 << V_79 ;
if ( V_80 <= 2 )
V_80 = 0xc ;
else if ( V_60 & 1023 && V_79 < 15 )
V_80 |= 1 << ( V_79 + 1 ) ;
V_12 = F_9 ( V_9 , V_99 , V_80 & 0xfc ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_100 , V_80 >> 8 ) ;
if ( ! V_7 -> V_101 ) {
V_82 = V_52 / 16 ;
V_83 = ( 3 * V_52 / 4 - 3 ) / 4 ;
V_84 = V_53 / 16 ;
V_85 = ( 3 * V_53 / 4 - 3 ) / 4 ;
V_81 = ( ( V_82 >> 2 ) & 0x40 ) | ( ( V_84 >> 4 ) & 0x10 ) |
( ( V_83 >> 6 ) & 4 ) | ( ( V_85 >> 8 ) & 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_102 , V_81 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_103 , V_82 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_104 , V_84 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_105 , V_83 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_106 , V_85 ) ;
}
V_86 = 12 * V_57 * ( 1 << 14 ) * V_60 / V_7 -> V_107 /
10000 ;
V_87 = V_86 / 6 ;
V_88 = V_86 / 5 ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_108 ,
( ( V_87 >> 4 ) & 0xf0 ) | ( V_88 >> 8 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_109 , V_87 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_110 , V_88 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_111 , V_86 / 150 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_112 ,
V_113 | V_114 | 1 ) ;
if ( V_12 < 0 )
return V_12 ;
F_23 ( 230 ) ;
V_12 = F_9 ( V_9 , V_112 , V_113 | 1 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_75 = ( V_52 * V_60 + 512 ) / 1024 ;
* V_76 = ( V_53 * V_60 + 512 ) / 1024 ;
* V_77 = V_52 ;
* V_78 = V_53 ;
F_6 ( & V_9 -> V_14 , L_5 ,
* V_75 , * V_76 , V_60 , V_52 , V_53 , V_79 ) ;
return V_60 ;
}
static int F_32 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
V_12 = F_9 ( V_9 , V_115 , V_116 | V_117 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_115 , V_116 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_118 , V_119 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_120 , V_121 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_122 ,
V_7 -> V_123 . V_124 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_125 ,
V_7 -> V_123 . V_126 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_127 ,
V_7 -> V_123 . V_128 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_129 , 3 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_130 , 0 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_131 ,
V_7 -> V_123 . V_132 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_133 ,
V_7 -> V_123 . V_134 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_135 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_136 , 2 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_115 ,
V_116 | V_137 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_138 , 1 ) ;
F_23 ( 10 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_139 , 1 ) ;
if ( ! V_12 )
V_12 = F_5 ( V_9 , V_139 ) ;
if ( V_12 != 1 ) {
F_33 ( & V_9 -> V_14 ,
L_6 , V_12 ) ;
return - V_140 ;
}
V_12 = F_10 ( V_9 , V_130 , 1 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_135 , 1 ) ;
return V_12 ;
}
static int F_34 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 = F_32 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_141 , F_13 ( V_141 ) ) ;
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_142 , F_13 ( V_142 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_143 , 3 | ( 7 << 4 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_144 , 0xf ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_112 ,
V_113 | 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_145 , 0x84 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_146 , 0x27 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_147 , F_13 ( V_147 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_148 , 0x80 ) ;
if ( ! V_12 )
V_12 = F_5 ( V_9 , V_149 ) ;
if ( V_12 >= 0 ) {
V_7 -> V_101 = V_12 & 0x80 ;
V_12 = F_11 ( V_9 , V_150 , F_13 ( V_150 ) ) ;
}
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_151 , F_13 ( V_151 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_115 ,
V_116 | V_152 | V_137 ) ;
if ( ! V_12 )
V_12 = F_22 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_115 ,
V_116 | V_152 | V_153 | V_137 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_154 , 2 ) ;
F_23 ( 700 ) ;
return V_12 ;
}
static int F_35 ( struct V_20 * V_21 ,
struct V_70 * V_71 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
int V_155 = V_71 -> V_3 == V_156 ||
V_71 -> V_3 == V_157 ||
V_71 -> V_3 == V_158 ||
V_71 -> V_3 == V_159 ||
V_71 -> V_3 == V_160 ;
F_6 ( & V_9 -> V_14 , L_7 ,
V_161 , V_71 -> V_3 , V_71 -> V_43 , V_71 -> V_44 ) ;
V_4 = F_1 ( V_71 -> V_3 , V_23 ,
F_13 ( V_23 ) ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_71 -> V_3 = V_4 -> V_3 ;
}
V_71 -> V_73 = V_74 ;
V_71 -> V_72 = V_4 -> V_72 ;
F_36 ( & V_71 -> V_43 , 112 , V_57 , V_155 ,
& V_71 -> V_44 , 84 , V_59 , V_155 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_20 * V_21 ,
struct V_70 * V_71 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
int V_52 , V_53 , V_162 , V_163 ,
V_54 = V_7 -> V_49 . V_43 , V_55 = V_7 -> V_49 . V_44 ;
int V_12 ;
F_35 ( V_21 , V_71 ) ;
V_12 = F_5 ( V_9 , V_115 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & V_116 ) ) {
V_12 = F_34 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
}
F_6 ( & V_9 -> V_14 , L_7 ,
V_161 , V_71 -> V_3 , V_71 -> V_43 , V_71 -> V_44 ) ;
switch ( V_71 -> V_3 ) {
case V_164 :
V_12 = F_9 ( V_9 , V_165 , 0 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_166 , 8 , 8 ) ;
break;
case V_167 :
V_12 = F_9 ( V_9 , V_165 , 0 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_166 , 0 , 8 ) ;
break;
case V_168 :
V_12 = F_9 ( V_9 , V_165 , 0x11 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_166 , 8 , 8 ) ;
break;
case V_169 :
V_12 = F_9 ( V_9 , V_165 , 0x11 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_166 , 0 , 8 ) ;
break;
case V_160 :
V_12 = F_9 ( V_9 , V_165 , 4 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_166 , 8 , 8 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_170 , 0 ) ;
break;
case V_159 :
V_12 = F_9 ( V_9 , V_165 , 4 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_166 , 8 , 8 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_170 , 8 ) ;
break;
case V_158 :
V_12 = F_9 ( V_9 , V_165 , 4 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_166 , 0 , 8 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_170 , 0 ) ;
break;
case V_157 :
V_12 = F_9 ( V_9 , V_165 , 4 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_166 , 0 , 8 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_170 , 8 ) ;
break;
case V_156 :
V_12 = F_9 ( V_9 , V_165 , 5 ) ;
break;
default:
V_12 = - V_24 ;
}
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_135 ,
( V_71 -> V_3 == V_156 ) << 1 , 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_162 = V_71 -> V_43 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_54 > V_162 )
V_54 = V_162 ;
V_163 = V_71 -> V_44 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_55 > V_163 )
V_55 = V_163 ;
V_52 = V_71 -> V_43 ;
V_53 = V_71 -> V_44 ;
V_12 = F_26 ( V_21 , & V_54 , & V_55 , & V_52 , & V_53 ) ;
if ( V_12 < 0 )
return V_12 ;
V_4 = F_1 ( V_71 -> V_3 , V_23 ,
F_13 ( V_23 ) ) ;
V_7 -> V_4 = V_4 ;
V_7 -> V_60 = V_12 ;
V_7 -> V_49 . V_43 = V_54 ;
V_7 -> V_49 . V_44 = V_55 ;
V_7 -> V_43 = V_52 ;
V_7 -> V_44 = V_53 ;
V_71 -> V_43 = V_52 ;
V_71 -> V_44 = V_53 ;
V_71 -> V_73 = V_74 ;
V_71 -> V_72 = V_4 -> V_72 ;
return 0 ;
}
static int F_38 ( struct V_20 * V_21 ,
struct V_171 * V_172 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
if ( V_172 -> V_173 . type != V_174 )
return - V_24 ;
if ( V_172 -> V_173 . V_175 != V_9 -> V_175 )
return - V_176 ;
V_172 -> V_177 = V_178 ;
V_172 -> V_179 = 0 ;
return 0 ;
}
static int F_39 ( struct V_20 * V_21 ,
struct V_180 * V_11 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
if ( V_11 -> V_173 . type != V_174 ||
V_11 -> V_11 < 0x400 || V_11 -> V_11 > 0x1fff )
return - V_24 ;
if ( V_11 -> V_173 . V_175 != V_9 -> V_175 )
return - V_176 ;
V_11 -> V_181 = 1 ;
V_11 -> V_19 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_19 > 0xff )
return - V_140 ;
return 0 ;
}
static int F_40 ( struct V_20 * V_21 ,
struct V_180 * V_11 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
if ( V_11 -> V_173 . type != V_174 ||
V_11 -> V_11 < 0x400 || V_11 -> V_11 > 0x1fff )
return - V_24 ;
if ( V_11 -> V_173 . V_175 != V_9 -> V_175 )
return - V_176 ;
if ( F_9 ( V_9 , V_11 -> V_11 , V_11 -> V_19 ) < 0 )
return - V_140 ;
return 0 ;
}
static int F_41 ( struct V_20 * V_21 , struct V_182 * V_183 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_15 ;
switch ( V_183 -> V_172 ) {
case V_184 :
V_15 = F_5 ( V_9 , V_146 ) ;
if ( V_15 < 0 )
return - V_140 ;
V_183 -> V_185 = ! ( V_15 & 1 ) ;
break;
case V_186 :
V_15 = F_5 ( V_9 , V_146 ) ;
if ( V_15 < 0 )
return - V_140 ;
V_183 -> V_185 = ! ( V_15 & 2 ) ;
break;
case V_187 :
V_15 = F_5 ( V_9 , V_145 ) ;
if ( V_15 < 0 )
return - V_140 ;
V_183 -> V_185 = V_15 / 2 ;
break;
case V_188 :
V_183 -> V_185 = V_7 -> V_101 ;
break;
}
return 0 ;
}
static int F_42 ( struct V_20 * V_21 , struct V_182 * V_183 )
{
int V_15 ;
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_189 * V_190 ;
V_190 = F_43 ( & V_191 , V_183 -> V_172 ) ;
if ( ! V_190 )
return - V_24 ;
switch ( V_183 -> V_172 ) {
case V_184 :
if ( V_183 -> V_185 )
V_15 = F_10 ( V_9 , V_146 , 0 , 1 ) ;
else
V_15 = F_10 ( V_9 , V_146 , 1 , 1 ) ;
if ( V_15 < 0 )
return - V_140 ;
break;
case V_186 :
if ( V_183 -> V_185 )
V_15 = F_10 ( V_9 , V_146 , 0 , 2 ) ;
else
V_15 = F_10 ( V_9 , V_146 , 2 , 2 ) ;
if ( V_15 < 0 )
return - V_140 ;
break;
case V_187 :
if ( V_183 -> V_185 > V_190 -> V_192 ||
V_183 -> V_185 < V_190 -> V_193 )
return - V_24 ;
else if ( F_9 ( V_9 , V_145 , V_183 -> V_185 * 2 ) < 0 )
return - V_140 ;
break;
case V_188 :
if ( F_10 ( V_9 , V_149 , V_183 -> V_185 << 7 ,
0x80 ) < 0 )
return - V_140 ;
V_7 -> V_101 = V_183 -> V_185 ;
break;
}
return 0 ;
}
static int F_44 ( struct V_27 * V_28 ,
struct V_8 * V_9 ,
struct V_194 * V_195 )
{
int V_196 , V_197 ;
int V_12 ;
if ( ! V_28 -> V_14 . V_198 ||
F_45 ( V_28 -> V_14 . V_198 ) -> V_199 != V_28 -> V_200 )
return - V_176 ;
V_196 = F_5 ( V_9 , V_201 ) ;
V_197 = F_5 ( V_9 , V_202 ) ;
if ( V_196 != 0x51 || V_197 != 0x10 ) {
V_12 = - V_176 ;
F_46 ( & V_9 -> V_14 , L_8 ,
V_196 , V_197 ) ;
goto V_203;
}
V_12 = F_9 ( V_9 , V_204 , V_195 -> V_205 << 7 ) ;
if ( V_12 < 0 )
goto V_203;
F_46 ( & V_9 -> V_14 , L_9 ,
V_196 , V_197 ) ;
V_203:
return V_12 ;
}
static int F_47 ( struct V_8 * V_9 ,
const struct V_206 * V_207 )
{
struct V_7 * V_7 ;
struct V_27 * V_28 = V_9 -> V_14 . V_208 ;
struct V_209 * V_210 = F_48 ( V_9 -> V_14 . V_198 ) ;
struct V_32 * V_33 ;
struct V_194 * V_211 ;
int V_12 ;
if ( ! V_28 ) {
F_33 ( & V_9 -> V_14 , L_10 ) ;
return - V_24 ;
}
V_33 = F_19 ( V_28 ) ;
if ( ! V_33 || ! V_33 -> V_195 ) {
F_33 ( & V_9 -> V_14 , L_11 ) ;
return - V_24 ;
}
V_211 = V_33 -> V_195 ;
if ( ! F_49 ( V_210 , V_212 ) ) {
F_50 ( & V_210 -> V_14 ,
L_12 ) ;
return - V_140 ;
}
V_7 = F_51 ( sizeof( struct V_7 ) , V_213 ) ;
if ( ! V_7 )
return - V_214 ;
F_52 ( & V_7 -> V_10 , V_9 , & V_215 ) ;
V_28 -> V_216 = & V_191 ;
V_7 -> V_123 = V_123 ;
V_7 -> V_49 . V_64 = V_56 ;
V_7 -> V_49 . V_65 = V_58 ;
V_7 -> V_49 . V_43 = V_57 ;
V_7 -> V_49 . V_44 = V_59 ;
V_7 -> V_43 = V_57 ;
V_7 -> V_44 = V_59 ;
V_7 -> V_4 = & V_23 [ 0 ] ;
V_7 -> V_60 = 1024 ;
V_7 -> V_107 = ( V_211 -> V_217 / V_119 * V_121 ) /
( V_123 . V_124 + 1 ) / ( V_123 . V_126 + 1 ) ;
V_12 = F_44 ( V_28 , V_9 , V_211 ) ;
if ( V_12 < 0 ) {
V_28 -> V_216 = NULL ;
F_53 ( V_7 ) ;
return V_12 ;
}
return V_12 ;
}
static int F_54 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_27 * V_28 = V_9 -> V_14 . V_208 ;
struct V_32 * V_33 = F_19 ( V_28 ) ;
V_28 -> V_216 = NULL ;
if ( V_33 -> V_218 )
V_33 -> V_218 ( V_33 ) ;
F_53 ( V_7 ) ;
return 0 ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_219 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_219 ) ;
}
