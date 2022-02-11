static const struct V_1 * F_1 (
T_1 V_2 , const struct V_1 * V_3 ,
int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
if ( V_3 [ V_5 ] . V_2 == V_2 )
return V_3 + V_5 ;
return NULL ;
}
static struct V_6 * F_2 ( const struct V_7 * V_8 )
{
return F_3 ( F_4 ( V_8 ) , struct V_6 , V_9 ) ;
}
static int F_5 ( struct V_7 * V_8 , const T_2 V_10 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_11 ;
if ( V_6 -> V_12 != V_10 >> 8 ) {
F_6 ( & V_8 -> V_13 , L_1 , 0xff , V_10 >> 8 ) ;
V_11 = F_7 ( V_8 , 0xff , V_10 >> 8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_12 = V_10 >> 8 ;
}
return F_8 ( V_8 , V_10 & 0xff ) ;
}
static int F_9 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_3 V_14 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_11 ;
if ( V_6 -> V_12 != V_10 >> 8 ) {
F_6 ( & V_8 -> V_13 , L_1 , 0xff , V_10 >> 8 ) ;
V_11 = F_7 ( V_8 , 0xff , V_10 >> 8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_12 = V_10 >> 8 ;
}
F_6 ( & V_8 -> V_13 , L_1 , V_10 & 0xff , V_14 ) ;
return F_7 ( V_8 , V_10 & 0xff , V_14 ) ;
}
static int F_10 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_3 V_14 , const T_3 V_15 )
{
int V_11 ;
V_11 = F_5 ( V_8 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_9 ( V_8 , V_10 , ( V_11 & ~ V_15 ) | ( V_14 & V_15 ) ) ;
}
static int F_11 ( struct V_7 * V_8 ,
const struct V_16 * V_17 , const int V_4 )
{
int V_5 , V_11 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
V_11 = F_9 ( V_8 , V_17 -> V_10 , V_17 -> V_18 ) ;
if ( V_11 < 0 )
return V_11 ;
V_17 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_2 )
{
if ( V_2 -> V_24 || V_2 -> V_25 >= F_13 ( V_26 ) )
return - V_27 ;
V_2 -> V_2 = V_26 [ V_2 -> V_25 ] . V_2 ;
return 0 ;
}
static int F_14 ( struct V_19 * V_20 , int V_28 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
return F_10 ( V_8 , V_29 , ( ! V_28 ) << 7 , 0x80 ) ;
}
static int F_16 ( struct V_7 * V_8 ,
T_2 V_30 , T_2 V_31 , T_2 V_32 ,
T_1 V_33 , T_1 V_34 )
{
int V_11 ;
V_11 = F_9 ( V_8 , V_32 ,
( ( V_33 >> 4 ) & 0x70 ) |
( ( V_34 >> 8 ) & 7 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_30 , V_33 & 0xff ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_31 , V_34 & 0xff ) ;
return V_11 ;
}
static int F_17 ( struct V_7 * V_8 )
{
int V_11 = F_9 ( V_8 , V_35 , 1 ) ;
F_18 ( 10 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_35 , 0 ) ;
return V_11 ;
}
static int F_19 ( struct V_19 * V_20 , const struct V_36 * V_37 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_38 * V_39 = & V_37 -> V_40 ;
int V_41 = 0 , V_42 , V_43 ,
V_44 = V_39 -> V_33 , V_45 = V_39 -> V_34 ;
int V_11 ;
F_20 ( & V_41 , & V_44 ,
V_46 , 8 , V_47 ) ;
F_20 ( & V_41 , & V_45 ,
V_48 , 8 , V_49 ) ;
V_42 = ( V_44 * 1024 + V_6 -> V_50 / 2 ) / V_6 -> V_50 ;
V_43 = ( V_45 * 1024 + V_6 -> V_50 / 2 ) / V_6 -> V_50 ;
F_6 ( & V_8 -> V_13 , L_2 ,
V_44 , V_45 , V_6 -> V_50 , V_42 , V_43 ) ;
V_11 = F_21 ( V_20 , & V_44 , & V_45 , & V_42 , & V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_33 = V_42 ;
V_6 -> V_34 = V_43 ;
V_6 -> V_50 = V_11 ;
V_6 -> V_39 . V_33 = V_44 ;
V_6 -> V_39 . V_34 = V_45 ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 , struct V_36 * V_37 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
V_37 -> V_40 = V_6 -> V_39 ;
V_37 -> type = V_51 ;
return 0 ;
}
static int F_23 ( struct V_19 * V_20 , struct V_52 * V_37 )
{
V_37 -> V_53 . V_54 = V_46 ;
V_37 -> V_53 . V_55 = V_48 ;
V_37 -> V_53 . V_33 = V_47 ;
V_37 -> V_53 . V_34 = V_49 ;
V_37 -> V_56 = V_37 -> V_53 ;
V_37 -> type = V_51 ;
V_37 -> V_57 . V_58 = 1 ;
V_37 -> V_57 . V_59 = 1 ;
return 0 ;
}
static int F_24 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = & V_61 -> V_61 ;
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
if ( V_61 -> V_24 )
return - V_27 ;
V_63 -> V_2 = V_6 -> V_3 -> V_2 ;
V_63 -> V_64 = V_6 -> V_3 -> V_64 ;
V_63 -> V_65 = V_66 ;
V_63 -> V_33 = V_6 -> V_33 ;
V_63 -> V_34 = V_6 -> V_34 ;
return 0 ;
}
static int F_21 ( struct V_19 * V_20 , T_4 * V_67 , T_4 * V_68 ,
T_4 * V_69 , T_4 * V_70 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
unsigned int V_71 , V_50 , V_44 = * V_67 , V_45 = * V_68 ,
V_42 = * V_69 , V_43 = * V_70 ;
T_2 V_72 , V_73 , V_74 , V_75 , V_76 , V_77 ;
unsigned int V_78 , V_79 , V_80 ;
int V_11 ;
if ( V_42 > F_25 ( 512U , V_44 / 2 ) ) {
if ( 2 * V_42 > V_47 ) {
V_44 = V_47 ;
V_42 = V_47 / 2 ;
} else {
V_44 = V_42 * 2 ;
}
F_6 ( & V_8 -> V_13 , L_3 ,
V_44 , V_42 ) ;
}
if ( V_43 > F_25 ( 384U , V_45 / 2 ) ) {
if ( 2 * V_43 > V_49 ) {
V_45 = V_49 ;
V_43 = V_49 / 2 ;
} else {
V_45 = V_43 * 2 ;
}
F_6 ( & V_8 -> V_13 , L_4 ,
V_45 , V_43 ) ;
}
V_11 = F_16 ( V_8 , V_81 ,
V_82 ,
V_83 , V_42 , V_43 ) ;
if ( ! V_11 )
V_11 = F_16 ( V_8 , V_84 ,
V_85 ,
V_86 , V_42 , V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_42 > V_44 && V_43 > V_45 ) {
V_44 = V_42 ;
V_45 = V_43 ;
V_50 = 1024 ;
} else {
unsigned int V_87 , V_88 ;
V_87 = ( V_44 * 1024 + V_42 / 2 ) / V_42 ;
V_88 = ( V_45 * 1024 + V_43 / 2 ) / V_43 ;
if ( V_87 > V_88 &&
( V_43 * V_87 + 512 ) / 1024 > V_49 )
V_50 = ( V_49 * 1024 + V_43 / 2 ) /
V_43 ;
else if ( V_88 > V_87 &&
( V_42 * V_88 + 512 ) / 1024 > V_47 )
V_50 = ( V_47 * 1024 + V_42 / 2 ) /
V_42 ;
else
V_50 = F_25 ( V_87 , V_88 ) ;
switch ( V_50 ) {
case 2040 ... 2047 :
V_50 = 2039 ;
break;
case 4080 ... 4095 :
V_50 = 4079 ;
break;
case 8160 ... 8191 :
V_50 = 8159 ;
break;
case 16320 ... 16384 :
V_50 = 16319 ;
}
}
V_11 = F_9 ( V_8 , V_89 , V_50 & 0xff ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_90 , V_50 >> 8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_71 = F_26 ( V_50 / 1024 , 15U ) ;
V_72 = 1 << V_71 ;
if ( V_72 <= 2 )
V_72 = 0xc ;
else if ( V_50 & 1023 && V_71 < 15 )
V_72 |= 1 << ( V_71 + 1 ) ;
V_11 = F_9 ( V_8 , V_91 , V_72 & 0xfc ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_92 , V_72 >> 8 ) ;
if ( ! V_6 -> V_93 ) {
V_74 = V_42 / 16 ;
V_75 = ( 3 * V_42 / 4 - 3 ) / 4 ;
V_76 = V_43 / 16 ;
V_77 = ( 3 * V_43 / 4 - 3 ) / 4 ;
V_73 = ( ( V_74 >> 2 ) & 0x40 ) | ( ( V_76 >> 4 ) & 0x10 ) |
( ( V_75 >> 6 ) & 4 ) | ( ( V_77 >> 8 ) & 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_94 , V_73 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_95 , V_74 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_96 , V_76 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_97 , V_75 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_98 , V_77 ) ;
}
V_78 = 12 * V_47 * ( 1 << 14 ) * V_50 / V_6 -> V_99 /
10000 ;
V_79 = V_78 / 6 ;
V_80 = V_78 / 5 ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_100 ,
( ( V_79 >> 4 ) & 0xf0 ) | ( V_80 >> 8 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_101 , V_79 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_102 , V_80 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_103 , V_78 / 150 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_104 ,
V_105 | V_106 | 1 ) ;
if ( V_11 < 0 )
return V_11 ;
F_18 ( 230 ) ;
V_11 = F_9 ( V_8 , V_104 , V_105 | 1 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_67 = ( V_42 * V_50 + 512 ) / 1024 ;
* V_68 = ( V_43 * V_50 + 512 ) / 1024 ;
* V_69 = V_42 ;
* V_70 = V_43 ;
F_6 ( & V_8 -> V_13 , L_5 ,
* V_67 , * V_68 , V_50 , V_42 , V_43 , V_71 ) ;
return V_50 ;
}
static int F_27 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_11 ;
V_11 = F_9 ( V_8 , V_107 , V_108 | V_109 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_107 , V_108 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_110 , V_111 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_112 , V_113 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_114 ,
V_6 -> V_115 . V_116 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_117 ,
V_6 -> V_115 . V_118 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_119 ,
V_6 -> V_115 . V_120 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_121 , 3 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_122 , 0 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_123 ,
V_6 -> V_115 . V_124 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_125 ,
V_6 -> V_115 . V_126 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_127 , 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_128 , 2 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_107 ,
V_108 | V_129 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_130 , 1 ) ;
F_18 ( 10 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_131 , 1 ) ;
if ( ! V_11 )
V_11 = F_5 ( V_8 , V_131 ) ;
if ( V_11 != 1 ) {
F_28 ( & V_8 -> V_13 ,
L_6 , V_11 ) ;
return - V_132 ;
}
V_11 = F_10 ( V_8 , V_122 , 1 , 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_127 , 1 ) ;
return V_11 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_11 = F_27 ( V_8 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_133 , F_13 ( V_133 ) ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_134 , F_13 ( V_134 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_135 , 3 | ( 7 << 4 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_136 , 0xf ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_104 ,
V_105 | 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_137 , 0x84 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_138 , 0x27 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_139 , F_13 ( V_139 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_140 , 0x80 ) ;
if ( ! V_11 )
V_11 = F_5 ( V_8 , V_141 ) ;
if ( V_11 >= 0 ) {
V_6 -> V_93 = V_11 & 0x80 ;
V_11 = F_11 ( V_8 , V_142 , F_13 ( V_142 ) ) ;
}
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_143 , F_13 ( V_143 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_107 ,
V_108 | V_144 | V_129 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_107 ,
V_108 | V_144 | V_145 | V_129 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_146 , 2 ) ;
F_18 ( 700 ) ;
return V_11 ;
}
static int F_30 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = & V_61 -> V_61 ;
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_1 * V_3 ;
int V_42 , V_43 , V_147 , V_148 ,
V_44 = V_6 -> V_39 . V_33 , V_45 = V_6 -> V_39 . V_34 ;
int V_149 = V_63 -> V_2 == V_150 ||
V_63 -> V_2 == V_151 ||
V_63 -> V_2 == V_152 ||
V_63 -> V_2 == V_153 ||
V_63 -> V_2 == V_154 ;
int V_11 ;
if ( V_61 -> V_24 )
return - V_27 ;
F_6 ( & V_8 -> V_13 , L_7 ,
V_155 , V_63 -> V_2 , V_63 -> V_33 , V_63 -> V_34 ) ;
V_3 = F_1 ( V_63 -> V_2 , V_26 ,
F_13 ( V_26 ) ) ;
if ( ! V_3 ) {
V_3 = V_6 -> V_3 ;
V_63 -> V_2 = V_3 -> V_2 ;
}
V_63 -> V_65 = V_66 ;
V_63 -> V_64 = V_3 -> V_64 ;
F_31 ( & V_63 -> V_33 , 112 , V_47 , V_149 ,
& V_63 -> V_34 , 84 , V_49 , V_149 , 0 ) ;
if ( V_61 -> V_156 == V_157 ) {
V_22 -> V_158 = * V_63 ;
return 0 ;
}
V_11 = F_5 ( V_8 , V_107 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! ( V_11 & V_108 ) ) {
V_11 = F_29 ( V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
}
switch ( V_63 -> V_2 ) {
case V_159 :
V_11 = F_9 ( V_8 , V_160 , 0 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_161 , 8 , 8 ) ;
break;
case V_162 :
V_11 = F_9 ( V_8 , V_160 , 0 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_161 , 0 , 8 ) ;
break;
case V_163 :
V_11 = F_9 ( V_8 , V_160 , 0x11 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_161 , 8 , 8 ) ;
break;
case V_164 :
V_11 = F_9 ( V_8 , V_160 , 0x11 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_161 , 0 , 8 ) ;
break;
case V_154 :
V_11 = F_9 ( V_8 , V_160 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_161 , 8 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_165 , 0 ) ;
break;
case V_153 :
V_11 = F_9 ( V_8 , V_160 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_161 , 8 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_165 , 8 ) ;
break;
case V_152 :
V_11 = F_9 ( V_8 , V_160 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_161 , 0 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_165 , 0 ) ;
break;
case V_151 :
V_11 = F_9 ( V_8 , V_160 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_161 , 0 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_165 , 8 ) ;
break;
case V_150 :
V_11 = F_9 ( V_8 , V_160 , 5 ) ;
break;
default:
V_11 = - V_27 ;
}
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_127 ,
( V_63 -> V_2 == V_150 ) << 1 , 2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_147 = V_63 -> V_33 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_44 > V_147 )
V_44 = V_147 ;
V_148 = V_63 -> V_34 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_45 > V_148 )
V_45 = V_148 ;
V_42 = V_63 -> V_33 ;
V_43 = V_63 -> V_34 ;
V_11 = F_21 ( V_20 , & V_44 , & V_45 , & V_42 , & V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
V_3 = F_1 ( V_63 -> V_2 , V_26 ,
F_13 ( V_26 ) ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_50 = V_11 ;
V_6 -> V_39 . V_33 = V_44 ;
V_6 -> V_39 . V_34 = V_45 ;
V_6 -> V_33 = V_42 ;
V_6 -> V_34 = V_43 ;
V_63 -> V_33 = V_42 ;
V_63 -> V_34 = V_43 ;
V_63 -> V_65 = V_66 ;
V_63 -> V_64 = V_3 -> V_64 ;
return 0 ;
}
static int F_32 ( struct V_19 * V_20 ,
struct V_166 * V_10 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
if ( V_10 -> V_10 < 0x400 || V_10 -> V_10 > 0x1fff )
return - V_27 ;
V_10 -> V_167 = 1 ;
V_10 -> V_18 = F_5 ( V_8 , V_10 -> V_10 ) ;
if ( V_10 -> V_18 > 0xff )
return - V_132 ;
return 0 ;
}
static int F_33 ( struct V_19 * V_20 ,
const struct V_166 * V_10 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
if ( V_10 -> V_10 < 0x400 || V_10 -> V_10 > 0x1fff )
return - V_27 ;
if ( F_9 ( V_8 , V_10 -> V_10 , V_10 -> V_18 ) < 0 )
return - V_132 ;
return 0 ;
}
static int F_34 ( struct V_19 * V_20 , int V_168 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_169 * V_170 = F_35 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
return F_36 ( & V_8 -> V_13 , V_170 , V_6 -> V_171 , V_168 ) ;
}
static int F_37 ( struct V_172 * V_173 )
{
struct V_6 * V_6 = F_3 ( V_173 -> V_174 , struct V_6 , V_175 ) ;
struct V_19 * V_20 = & V_6 -> V_9 ;
struct V_7 * V_8 = F_15 ( V_20 ) ;
int V_14 ;
switch ( V_173 -> V_176 ) {
case V_177 :
if ( V_173 -> V_18 )
V_14 = F_10 ( V_8 , V_138 , 0 , 1 ) ;
else
V_14 = F_10 ( V_8 , V_138 , 1 , 1 ) ;
if ( V_14 < 0 )
return - V_132 ;
return 0 ;
case V_178 :
if ( V_173 -> V_18 )
V_14 = F_10 ( V_8 , V_138 , 0 , 2 ) ;
else
V_14 = F_10 ( V_8 , V_138 , 2 , 2 ) ;
if ( V_14 < 0 )
return - V_132 ;
return 0 ;
case V_179 :
if ( F_9 ( V_8 , V_137 , V_173 -> V_18 * 2 ) < 0 )
return - V_132 ;
return 0 ;
case V_180 :
if ( F_10 ( V_8 , V_141 , V_173 -> V_18 << 7 ,
0x80 ) < 0 )
return - V_132 ;
V_6 -> V_93 = V_173 -> V_18 ;
return 0 ;
}
return - V_27 ;
}
static int F_38 ( struct V_19 * V_20 ,
struct V_181 * V_22 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_169 * V_170 = F_35 ( V_8 ) ;
V_22 -> V_182 =
V_183 | V_184 |
V_185 | V_186 |
V_187 | V_188 ;
V_22 -> type = V_189 ;
V_22 -> V_182 = F_39 ( V_170 , V_22 ) ;
return 0 ;
}
static int F_40 ( struct V_19 * V_20 ,
const struct V_181 * V_22 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_169 * V_170 = F_35 ( V_8 ) ;
if ( F_39 ( V_170 , V_22 ) &
V_183 )
return F_9 ( V_8 , V_190 , 1 << 4 ) ;
else
return F_9 ( V_8 , V_190 , 0 ) ;
}
static int F_41 ( struct V_7 * V_8 ,
struct V_191 * V_192 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_193 , V_194 ;
int V_11 ;
V_11 = F_34 ( & V_6 -> V_9 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_193 = F_5 ( V_8 , V_195 ) ;
V_194 = F_5 ( V_8 , V_196 ) ;
if ( V_193 != 0x51 || V_194 != 0x10 ) {
V_11 = - V_197 ;
F_42 ( & V_8 -> V_13 , L_8 ,
V_193 , V_194 ) ;
goto V_198;
}
V_11 = F_9 ( V_8 , V_199 , V_192 -> V_200 << 7 ) ;
if ( V_11 < 0 )
goto V_198;
F_42 ( & V_8 -> V_13 , L_9 ,
V_193 , V_194 ) ;
V_11 = F_43 ( & V_6 -> V_175 ) ;
V_198:
F_34 ( & V_6 -> V_9 , 0 ) ;
return V_11 ;
}
static int F_44 ( struct V_7 * V_8 ,
const struct V_201 * V_202 )
{
struct V_6 * V_6 ;
struct V_169 * V_170 = F_35 ( V_8 ) ;
struct V_203 * V_204 = F_45 ( V_8 -> V_13 . V_205 ) ;
struct V_191 * V_206 ;
int V_11 ;
if ( ! V_170 || ! V_170 -> V_207 ) {
F_28 ( & V_8 -> V_13 , L_10 ) ;
return - V_27 ;
}
V_206 = V_170 -> V_207 ;
if ( ! F_46 ( V_204 , V_208 ) ) {
F_47 ( & V_204 -> V_13 ,
L_11 ) ;
return - V_132 ;
}
V_6 = F_48 ( & V_8 -> V_13 , sizeof( struct V_6 ) , V_209 ) ;
if ( ! V_6 )
return - V_210 ;
F_49 ( & V_6 -> V_9 , V_8 , & V_211 ) ;
F_50 ( & V_6 -> V_175 , 4 ) ;
F_51 ( & V_6 -> V_175 , & V_212 ,
V_177 , 0 , 1 , 1 , 0 ) ;
F_51 ( & V_6 -> V_175 , & V_212 ,
V_178 , 0 , 1 , 1 , 0 ) ;
F_51 ( & V_6 -> V_175 , & V_212 ,
V_179 , 0 , 127 , 1 , 66 ) ;
F_51 ( & V_6 -> V_175 , & V_212 ,
V_180 , 0 , 1 , 1 , 1 ) ;
V_6 -> V_9 . V_213 = & V_6 -> V_175 ;
if ( V_6 -> V_175 . error )
return V_6 -> V_175 . error ;
V_6 -> V_115 = V_115 ;
V_6 -> V_39 . V_54 = V_46 ;
V_6 -> V_39 . V_55 = V_48 ;
V_6 -> V_39 . V_33 = V_47 ;
V_6 -> V_39 . V_34 = V_49 ;
V_6 -> V_33 = V_47 ;
V_6 -> V_34 = V_49 ;
V_6 -> V_3 = & V_26 [ 0 ] ;
V_6 -> V_50 = 1024 ;
V_6 -> V_99 = ( V_206 -> V_214 / V_111 * V_113 ) /
( V_115 . V_116 + 1 ) / ( V_115 . V_118 + 1 ) ;
V_6 -> V_171 = F_52 ( & V_8 -> V_13 , L_12 ) ;
if ( F_53 ( V_6 -> V_171 ) ) {
V_11 = F_54 ( V_6 -> V_171 ) ;
goto V_215;
}
V_11 = F_41 ( V_8 , V_206 ) ;
if ( V_11 < 0 ) {
F_55 ( V_6 -> V_171 ) ;
V_215:
F_56 ( & V_6 -> V_175 ) ;
}
return V_11 ;
}
static int F_57 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_169 * V_170 = F_35 ( V_8 ) ;
F_55 ( V_6 -> V_171 ) ;
F_58 ( & V_6 -> V_9 ) ;
if ( V_170 -> V_216 )
V_170 -> V_216 ( V_170 ) ;
F_56 ( & V_6 -> V_175 ) ;
return 0 ;
}
