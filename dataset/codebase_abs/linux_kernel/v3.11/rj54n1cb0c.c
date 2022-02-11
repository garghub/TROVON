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
static int F_16 ( struct V_8 * V_9 ,
T_1 V_27 , T_1 V_28 , T_1 V_29 ,
T_3 V_30 , T_3 V_31 )
{
int V_12 ;
V_12 = F_9 ( V_9 , V_29 ,
( ( V_30 >> 4 ) & 0x70 ) |
( ( V_31 >> 8 ) & 7 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_27 , V_30 & 0xff ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_28 , V_31 & 0xff ) ;
return V_12 ;
}
static int F_17 ( struct V_8 * V_9 )
{
int V_12 = F_9 ( V_9 , V_32 , 1 ) ;
F_18 ( 10 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_32 , 0 ) ;
return V_12 ;
}
static int F_19 ( struct V_20 * V_21 , const struct V_33 * V_34 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_35 * V_36 = & V_34 -> V_37 ;
int V_38 = 0 , V_39 , V_40 ,
V_41 = V_36 -> V_30 , V_42 = V_36 -> V_31 ;
int V_12 ;
F_20 ( & V_38 , & V_41 ,
V_43 , 8 , V_44 ) ;
F_20 ( & V_38 , & V_42 ,
V_45 , 8 , V_46 ) ;
V_39 = ( V_41 * 1024 + V_7 -> V_47 / 2 ) / V_7 -> V_47 ;
V_40 = ( V_42 * 1024 + V_7 -> V_47 / 2 ) / V_7 -> V_47 ;
F_6 ( & V_9 -> V_14 , L_2 ,
V_41 , V_42 , V_7 -> V_47 , V_39 , V_40 ) ;
V_12 = F_21 ( V_21 , & V_41 , & V_42 , & V_39 , & V_40 ) ;
if ( V_12 < 0 )
return V_12 ;
V_7 -> V_30 = V_39 ;
V_7 -> V_31 = V_40 ;
V_7 -> V_47 = V_12 ;
V_7 -> V_36 . V_30 = V_41 ;
V_7 -> V_36 . V_31 = V_42 ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 , struct V_33 * V_34 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_34 -> V_37 = V_7 -> V_36 ;
V_34 -> type = V_48 ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 , struct V_49 * V_34 )
{
V_34 -> V_50 . V_51 = V_43 ;
V_34 -> V_50 . V_52 = V_45 ;
V_34 -> V_50 . V_30 = V_44 ;
V_34 -> V_50 . V_31 = V_46 ;
V_34 -> V_53 = V_34 -> V_50 ;
V_34 -> type = V_48 ;
V_34 -> V_54 . V_55 = 1 ;
V_34 -> V_54 . V_56 = 1 ;
return 0 ;
}
static int F_24 ( struct V_20 * V_21 ,
struct V_57 * V_58 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_58 -> V_3 = V_7 -> V_4 -> V_3 ;
V_58 -> V_59 = V_7 -> V_4 -> V_59 ;
V_58 -> V_60 = V_61 ;
V_58 -> V_30 = V_7 -> V_30 ;
V_58 -> V_31 = V_7 -> V_31 ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 , T_4 * V_62 , T_4 * V_63 ,
T_4 * V_64 , T_4 * V_65 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
unsigned int V_66 , V_47 , V_41 = * V_62 , V_42 = * V_63 ,
V_39 = * V_64 , V_40 = * V_65 ;
T_1 V_67 , V_68 , V_69 , V_70 , V_71 , V_72 ;
unsigned int V_73 , V_74 , V_75 ;
int V_12 ;
if ( V_39 > F_25 ( 512U , V_41 / 2 ) ) {
if ( 2 * V_39 > V_44 ) {
V_41 = V_44 ;
V_39 = V_44 / 2 ;
} else {
V_41 = V_39 * 2 ;
}
F_6 ( & V_9 -> V_14 , L_3 ,
V_41 , V_39 ) ;
}
if ( V_40 > F_25 ( 384U , V_42 / 2 ) ) {
if ( 2 * V_40 > V_46 ) {
V_42 = V_46 ;
V_40 = V_46 / 2 ;
} else {
V_42 = V_40 * 2 ;
}
F_6 ( & V_9 -> V_14 , L_4 ,
V_42 , V_40 ) ;
}
V_12 = F_16 ( V_9 , V_76 ,
V_77 ,
V_78 , V_39 , V_40 ) ;
if ( ! V_12 )
V_12 = F_16 ( V_9 , V_79 ,
V_80 ,
V_81 , V_39 , V_40 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_39 > V_41 && V_40 > V_42 ) {
V_41 = V_39 ;
V_42 = V_40 ;
V_47 = 1024 ;
} else {
unsigned int V_82 , V_83 ;
V_82 = ( V_41 * 1024 + V_39 / 2 ) / V_39 ;
V_83 = ( V_42 * 1024 + V_40 / 2 ) / V_40 ;
if ( V_82 > V_83 &&
( V_40 * V_82 + 512 ) / 1024 > V_46 )
V_47 = ( V_46 * 1024 + V_40 / 2 ) /
V_40 ;
else if ( V_83 > V_82 &&
( V_39 * V_83 + 512 ) / 1024 > V_44 )
V_47 = ( V_44 * 1024 + V_39 / 2 ) /
V_39 ;
else
V_47 = F_25 ( V_82 , V_83 ) ;
switch ( V_47 ) {
case 2040 ... 2047 :
V_47 = 2039 ;
break;
case 4080 ... 4095 :
V_47 = 4079 ;
break;
case 8160 ... 8191 :
V_47 = 8159 ;
break;
case 16320 ... 16384 :
V_47 = 16319 ;
}
}
V_12 = F_9 ( V_9 , V_84 , V_47 & 0xff ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_85 , V_47 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_66 = F_26 ( V_47 / 1024 , 15U ) ;
V_67 = 1 << V_66 ;
if ( V_67 <= 2 )
V_67 = 0xc ;
else if ( V_47 & 1023 && V_66 < 15 )
V_67 |= 1 << ( V_66 + 1 ) ;
V_12 = F_9 ( V_9 , V_86 , V_67 & 0xfc ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_87 , V_67 >> 8 ) ;
if ( ! V_7 -> V_88 ) {
V_69 = V_39 / 16 ;
V_70 = ( 3 * V_39 / 4 - 3 ) / 4 ;
V_71 = V_40 / 16 ;
V_72 = ( 3 * V_40 / 4 - 3 ) / 4 ;
V_68 = ( ( V_69 >> 2 ) & 0x40 ) | ( ( V_71 >> 4 ) & 0x10 ) |
( ( V_70 >> 6 ) & 4 ) | ( ( V_72 >> 8 ) & 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_89 , V_68 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_90 , V_69 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_91 , V_71 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_92 , V_70 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_93 , V_72 ) ;
}
V_73 = 12 * V_44 * ( 1 << 14 ) * V_47 / V_7 -> V_94 /
10000 ;
V_74 = V_73 / 6 ;
V_75 = V_73 / 5 ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_95 ,
( ( V_74 >> 4 ) & 0xf0 ) | ( V_75 >> 8 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_96 , V_74 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_97 , V_75 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_98 , V_73 / 150 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_99 ,
V_100 | V_101 | 1 ) ;
if ( V_12 < 0 )
return V_12 ;
F_18 ( 230 ) ;
V_12 = F_9 ( V_9 , V_99 , V_100 | 1 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_62 = ( V_39 * V_47 + 512 ) / 1024 ;
* V_63 = ( V_40 * V_47 + 512 ) / 1024 ;
* V_64 = V_39 ;
* V_65 = V_40 ;
F_6 ( & V_9 -> V_14 , L_5 ,
* V_62 , * V_63 , V_47 , V_39 , V_40 , V_66 ) ;
return V_47 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
V_12 = F_9 ( V_9 , V_102 , V_103 | V_104 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_102 , V_103 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_105 , V_106 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_107 , V_108 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_109 ,
V_7 -> V_110 . V_111 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_112 ,
V_7 -> V_110 . V_113 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_114 ,
V_7 -> V_110 . V_115 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_116 , 3 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_117 , 0 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_118 ,
V_7 -> V_110 . V_119 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_120 ,
V_7 -> V_110 . V_121 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_122 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_123 , 2 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_102 ,
V_103 | V_124 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_125 , 1 ) ;
F_18 ( 10 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_126 , 1 ) ;
if ( ! V_12 )
V_12 = F_5 ( V_9 , V_126 ) ;
if ( V_12 != 1 ) {
F_28 ( & V_9 -> V_14 ,
L_6 , V_12 ) ;
return - V_127 ;
}
V_12 = F_10 ( V_9 , V_117 , 1 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_122 , 1 ) ;
return V_12 ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 = F_27 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_128 , F_13 ( V_128 ) ) ;
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_129 , F_13 ( V_129 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_130 , 3 | ( 7 << 4 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_131 , 0xf ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_99 ,
V_100 | 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_132 , 0x84 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_133 , 0x27 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_134 , F_13 ( V_134 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_135 , 0x80 ) ;
if ( ! V_12 )
V_12 = F_5 ( V_9 , V_136 ) ;
if ( V_12 >= 0 ) {
V_7 -> V_88 = V_12 & 0x80 ;
V_12 = F_11 ( V_9 , V_137 , F_13 ( V_137 ) ) ;
}
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_138 , F_13 ( V_138 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_102 ,
V_103 | V_139 | V_124 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_102 ,
V_103 | V_139 | V_140 | V_124 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_141 , 2 ) ;
F_18 ( 700 ) ;
return V_12 ;
}
static int F_30 ( struct V_20 * V_21 ,
struct V_57 * V_58 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
int V_142 = V_58 -> V_3 == V_143 ||
V_58 -> V_3 == V_144 ||
V_58 -> V_3 == V_145 ||
V_58 -> V_3 == V_146 ||
V_58 -> V_3 == V_147 ;
F_6 ( & V_9 -> V_14 , L_7 ,
V_148 , V_58 -> V_3 , V_58 -> V_30 , V_58 -> V_31 ) ;
V_4 = F_1 ( V_58 -> V_3 , V_23 ,
F_13 ( V_23 ) ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_58 -> V_3 = V_4 -> V_3 ;
}
V_58 -> V_60 = V_61 ;
V_58 -> V_59 = V_4 -> V_59 ;
F_31 ( & V_58 -> V_30 , 112 , V_44 , V_142 ,
& V_58 -> V_31 , 84 , V_46 , V_142 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_20 * V_21 ,
struct V_57 * V_58 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
int V_39 , V_40 , V_149 , V_150 ,
V_41 = V_7 -> V_36 . V_30 , V_42 = V_7 -> V_36 . V_31 ;
int V_12 ;
F_30 ( V_21 , V_58 ) ;
V_12 = F_5 ( V_9 , V_102 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & V_103 ) ) {
V_12 = F_29 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
}
F_6 ( & V_9 -> V_14 , L_7 ,
V_148 , V_58 -> V_3 , V_58 -> V_30 , V_58 -> V_31 ) ;
switch ( V_58 -> V_3 ) {
case V_151 :
V_12 = F_9 ( V_9 , V_152 , 0 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_153 , 8 , 8 ) ;
break;
case V_154 :
V_12 = F_9 ( V_9 , V_152 , 0 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_153 , 0 , 8 ) ;
break;
case V_155 :
V_12 = F_9 ( V_9 , V_152 , 0x11 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_153 , 8 , 8 ) ;
break;
case V_156 :
V_12 = F_9 ( V_9 , V_152 , 0x11 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_153 , 0 , 8 ) ;
break;
case V_147 :
V_12 = F_9 ( V_9 , V_152 , 4 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_153 , 8 , 8 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_157 , 0 ) ;
break;
case V_146 :
V_12 = F_9 ( V_9 , V_152 , 4 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_153 , 8 , 8 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_157 , 8 ) ;
break;
case V_145 :
V_12 = F_9 ( V_9 , V_152 , 4 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_153 , 0 , 8 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_157 , 0 ) ;
break;
case V_144 :
V_12 = F_9 ( V_9 , V_152 , 4 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_153 , 0 , 8 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_157 , 8 ) ;
break;
case V_143 :
V_12 = F_9 ( V_9 , V_152 , 5 ) ;
break;
default:
V_12 = - V_24 ;
}
if ( ! V_12 )
V_12 = F_10 ( V_9 , V_122 ,
( V_58 -> V_3 == V_143 ) << 1 , 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_149 = V_58 -> V_30 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_41 > V_149 )
V_41 = V_149 ;
V_150 = V_58 -> V_31 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_42 > V_150 )
V_42 = V_150 ;
V_39 = V_58 -> V_30 ;
V_40 = V_58 -> V_31 ;
V_12 = F_21 ( V_21 , & V_41 , & V_42 , & V_39 , & V_40 ) ;
if ( V_12 < 0 )
return V_12 ;
V_4 = F_1 ( V_58 -> V_3 , V_23 ,
F_13 ( V_23 ) ) ;
V_7 -> V_4 = V_4 ;
V_7 -> V_47 = V_12 ;
V_7 -> V_36 . V_30 = V_41 ;
V_7 -> V_36 . V_31 = V_42 ;
V_7 -> V_30 = V_39 ;
V_7 -> V_31 = V_40 ;
V_58 -> V_30 = V_39 ;
V_58 -> V_31 = V_40 ;
V_58 -> V_60 = V_61 ;
V_58 -> V_59 = V_4 -> V_59 ;
return 0 ;
}
static int F_33 ( struct V_20 * V_21 ,
struct V_158 * V_11 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
if ( V_11 -> V_11 < 0x400 || V_11 -> V_11 > 0x1fff )
return - V_24 ;
V_11 -> V_159 = 1 ;
V_11 -> V_19 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_19 > 0xff )
return - V_127 ;
return 0 ;
}
static int F_34 ( struct V_20 * V_21 ,
const struct V_158 * V_11 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
if ( V_11 -> V_11 < 0x400 || V_11 -> V_11 > 0x1fff )
return - V_24 ;
if ( F_9 ( V_9 , V_11 -> V_11 , V_11 -> V_19 ) < 0 )
return - V_127 ;
return 0 ;
}
static int F_35 ( struct V_20 * V_21 , int V_160 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_161 * V_162 = F_36 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
return F_37 ( & V_9 -> V_14 , V_162 , V_7 -> V_163 , V_160 ) ;
}
static int F_38 ( struct V_164 * V_165 )
{
struct V_7 * V_7 = F_3 ( V_165 -> V_166 , struct V_7 , V_167 ) ;
struct V_20 * V_21 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_15 ( V_21 ) ;
int V_15 ;
switch ( V_165 -> V_168 ) {
case V_169 :
if ( V_165 -> V_19 )
V_15 = F_10 ( V_9 , V_133 , 0 , 1 ) ;
else
V_15 = F_10 ( V_9 , V_133 , 1 , 1 ) ;
if ( V_15 < 0 )
return - V_127 ;
return 0 ;
case V_170 :
if ( V_165 -> V_19 )
V_15 = F_10 ( V_9 , V_133 , 0 , 2 ) ;
else
V_15 = F_10 ( V_9 , V_133 , 2 , 2 ) ;
if ( V_15 < 0 )
return - V_127 ;
return 0 ;
case V_171 :
if ( F_9 ( V_9 , V_132 , V_165 -> V_19 * 2 ) < 0 )
return - V_127 ;
return 0 ;
case V_172 :
if ( F_10 ( V_9 , V_136 , V_165 -> V_19 << 7 ,
0x80 ) < 0 )
return - V_127 ;
V_7 -> V_88 = V_165 -> V_19 ;
return 0 ;
}
return - V_24 ;
}
static int F_39 ( struct V_20 * V_21 ,
struct V_173 * V_174 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_161 * V_162 = F_36 ( V_9 ) ;
V_174 -> V_175 =
V_176 | V_177 |
V_178 | V_179 |
V_180 | V_181 ;
V_174 -> type = V_182 ;
V_174 -> V_175 = F_40 ( V_162 , V_174 ) ;
return 0 ;
}
static int F_41 ( struct V_20 * V_21 ,
const struct V_173 * V_174 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_161 * V_162 = F_36 ( V_9 ) ;
if ( F_40 ( V_162 , V_174 ) &
V_176 )
return F_9 ( V_9 , V_183 , 1 << 4 ) ;
else
return F_9 ( V_9 , V_183 , 0 ) ;
}
static int F_42 ( struct V_8 * V_9 ,
struct V_184 * V_185 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_186 , V_187 ;
int V_12 ;
V_12 = F_35 ( & V_7 -> V_10 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_186 = F_5 ( V_9 , V_188 ) ;
V_187 = F_5 ( V_9 , V_189 ) ;
if ( V_186 != 0x51 || V_187 != 0x10 ) {
V_12 = - V_190 ;
F_43 ( & V_9 -> V_14 , L_8 ,
V_186 , V_187 ) ;
goto V_191;
}
V_12 = F_9 ( V_9 , V_192 , V_185 -> V_193 << 7 ) ;
if ( V_12 < 0 )
goto V_191;
F_43 ( & V_9 -> V_14 , L_9 ,
V_186 , V_187 ) ;
V_12 = F_44 ( & V_7 -> V_167 ) ;
V_191:
F_35 ( & V_7 -> V_10 , 0 ) ;
return V_12 ;
}
static int F_45 ( struct V_8 * V_9 ,
const struct V_194 * V_195 )
{
struct V_7 * V_7 ;
struct V_161 * V_162 = F_36 ( V_9 ) ;
struct V_196 * V_197 = F_46 ( V_9 -> V_14 . V_198 ) ;
struct V_184 * V_199 ;
int V_12 ;
if ( ! V_162 || ! V_162 -> V_200 ) {
F_28 ( & V_9 -> V_14 , L_10 ) ;
return - V_24 ;
}
V_199 = V_162 -> V_200 ;
if ( ! F_47 ( V_197 , V_201 ) ) {
F_48 ( & V_197 -> V_14 ,
L_11 ) ;
return - V_127 ;
}
V_7 = F_49 ( & V_9 -> V_14 , sizeof( struct V_7 ) , V_202 ) ;
if ( ! V_7 )
return - V_203 ;
F_50 ( & V_7 -> V_10 , V_9 , & V_204 ) ;
F_51 ( & V_7 -> V_167 , 4 ) ;
F_52 ( & V_7 -> V_167 , & V_205 ,
V_169 , 0 , 1 , 1 , 0 ) ;
F_52 ( & V_7 -> V_167 , & V_205 ,
V_170 , 0 , 1 , 1 , 0 ) ;
F_52 ( & V_7 -> V_167 , & V_205 ,
V_171 , 0 , 127 , 1 , 66 ) ;
F_52 ( & V_7 -> V_167 , & V_205 ,
V_172 , 0 , 1 , 1 , 1 ) ;
V_7 -> V_10 . V_206 = & V_7 -> V_167 ;
if ( V_7 -> V_167 . error )
return V_7 -> V_167 . error ;
V_7 -> V_110 = V_110 ;
V_7 -> V_36 . V_51 = V_43 ;
V_7 -> V_36 . V_52 = V_45 ;
V_7 -> V_36 . V_30 = V_44 ;
V_7 -> V_36 . V_31 = V_46 ;
V_7 -> V_30 = V_44 ;
V_7 -> V_31 = V_46 ;
V_7 -> V_4 = & V_23 [ 0 ] ;
V_7 -> V_47 = 1024 ;
V_7 -> V_94 = ( V_199 -> V_207 / V_106 * V_108 ) /
( V_110 . V_111 + 1 ) / ( V_110 . V_113 + 1 ) ;
V_7 -> V_163 = F_53 ( & V_9 -> V_14 , L_12 ) ;
if ( F_54 ( V_7 -> V_163 ) ) {
V_12 = F_55 ( V_7 -> V_163 ) ;
goto V_208;
}
V_12 = F_42 ( V_9 , V_199 ) ;
if ( V_12 < 0 ) {
F_56 ( V_7 -> V_163 ) ;
V_208:
F_57 ( & V_7 -> V_167 ) ;
}
return V_12 ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_161 * V_162 = F_36 ( V_9 ) ;
F_56 ( V_7 -> V_163 ) ;
F_59 ( & V_7 -> V_10 ) ;
if ( V_162 -> V_209 )
V_162 -> V_209 ( V_162 ) ;
F_57 ( & V_7 -> V_167 ) ;
return 0 ;
}
