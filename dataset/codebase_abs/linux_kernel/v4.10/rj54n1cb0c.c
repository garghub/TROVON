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
static int F_19 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_36 * V_37 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_38 * V_39 = & V_37 -> V_40 ;
int V_41 = 0 , V_42 , V_43 ,
V_44 = V_39 -> V_33 , V_45 = V_39 -> V_34 ;
int V_11 ;
if ( V_37 -> V_46 != V_47 ||
V_37 -> V_48 != V_49 )
return - V_27 ;
F_20 ( & V_41 , & V_44 ,
V_50 , 8 , V_51 ) ;
F_20 ( & V_41 , & V_45 ,
V_52 , 8 , V_53 ) ;
V_42 = ( V_44 * 1024 + V_6 -> V_54 / 2 ) / V_6 -> V_54 ;
V_43 = ( V_45 * 1024 + V_6 -> V_54 / 2 ) / V_6 -> V_54 ;
F_6 ( & V_8 -> V_13 , L_2 ,
V_44 , V_45 , V_6 -> V_54 , V_42 , V_43 ) ;
V_11 = F_21 ( V_20 , & V_44 , & V_45 , & V_42 , & V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_33 = V_42 ;
V_6 -> V_34 = V_43 ;
V_6 -> V_54 = V_11 ;
V_6 -> V_39 . V_33 = V_44 ;
V_6 -> V_39 . V_34 = V_45 ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_36 * V_37 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
if ( V_37 -> V_46 != V_47 )
return - V_27 ;
switch ( V_37 -> V_48 ) {
case V_55 :
case V_56 :
V_37 -> V_40 . V_57 = V_50 ;
V_37 -> V_40 . V_58 = V_52 ;
V_37 -> V_40 . V_33 = V_51 ;
V_37 -> V_40 . V_34 = V_53 ;
return 0 ;
case V_49 :
V_37 -> V_40 = V_6 -> V_39 ;
return 0 ;
default:
return - V_27 ;
}
}
static int F_23 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = & V_60 -> V_60 ;
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
if ( V_60 -> V_24 )
return - V_27 ;
V_62 -> V_2 = V_6 -> V_3 -> V_2 ;
V_62 -> V_63 = V_6 -> V_3 -> V_63 ;
V_62 -> V_64 = V_65 ;
V_62 -> V_33 = V_6 -> V_33 ;
V_62 -> V_34 = V_6 -> V_34 ;
return 0 ;
}
static int F_21 ( struct V_19 * V_20 , T_4 * V_66 , T_4 * V_67 ,
T_4 * V_68 , T_4 * V_69 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
unsigned int V_70 , V_54 , V_44 = * V_66 , V_45 = * V_67 ,
V_42 = * V_68 , V_43 = * V_69 ;
T_2 V_71 , V_72 , V_73 , V_74 , V_75 , V_76 ;
unsigned int V_77 , V_78 , V_79 ;
int V_11 ;
if ( V_42 > F_24 ( 512U , V_44 / 2 ) ) {
if ( 2 * V_42 > V_51 ) {
V_44 = V_51 ;
V_42 = V_51 / 2 ;
} else {
V_44 = V_42 * 2 ;
}
F_6 ( & V_8 -> V_13 , L_3 ,
V_44 , V_42 ) ;
}
if ( V_43 > F_24 ( 384U , V_45 / 2 ) ) {
if ( 2 * V_43 > V_53 ) {
V_45 = V_53 ;
V_43 = V_53 / 2 ;
} else {
V_45 = V_43 * 2 ;
}
F_6 ( & V_8 -> V_13 , L_4 ,
V_45 , V_43 ) ;
}
V_11 = F_16 ( V_8 , V_80 ,
V_81 ,
V_82 , V_42 , V_43 ) ;
if ( ! V_11 )
V_11 = F_16 ( V_8 , V_83 ,
V_84 ,
V_85 , V_42 , V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_42 > V_44 && V_43 > V_45 ) {
V_44 = V_42 ;
V_45 = V_43 ;
V_54 = 1024 ;
} else {
unsigned int V_86 , V_87 ;
V_86 = ( V_44 * 1024 + V_42 / 2 ) / V_42 ;
V_87 = ( V_45 * 1024 + V_43 / 2 ) / V_43 ;
if ( V_86 > V_87 &&
( V_43 * V_86 + 512 ) / 1024 > V_53 )
V_54 = ( V_53 * 1024 + V_43 / 2 ) /
V_43 ;
else if ( V_87 > V_86 &&
( V_42 * V_87 + 512 ) / 1024 > V_51 )
V_54 = ( V_51 * 1024 + V_42 / 2 ) /
V_42 ;
else
V_54 = F_24 ( V_86 , V_87 ) ;
switch ( V_54 ) {
case 2040 ... 2047 :
V_54 = 2039 ;
break;
case 4080 ... 4095 :
V_54 = 4079 ;
break;
case 8160 ... 8191 :
V_54 = 8159 ;
break;
case 16320 ... 16384 :
V_54 = 16319 ;
}
}
V_11 = F_9 ( V_8 , V_88 , V_54 & 0xff ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_89 , V_54 >> 8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_70 = F_25 ( V_54 / 1024 , 15U ) ;
V_71 = 1 << V_70 ;
if ( V_71 <= 2 )
V_71 = 0xc ;
else if ( V_54 & 1023 && V_70 < 15 )
V_71 |= 1 << ( V_70 + 1 ) ;
V_11 = F_9 ( V_8 , V_90 , V_71 & 0xfc ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_91 , V_71 >> 8 ) ;
if ( ! V_6 -> V_92 ) {
V_73 = V_42 / 16 ;
V_74 = ( 3 * V_42 / 4 - 3 ) / 4 ;
V_75 = V_43 / 16 ;
V_76 = ( 3 * V_43 / 4 - 3 ) / 4 ;
V_72 = ( ( V_73 >> 2 ) & 0x40 ) | ( ( V_75 >> 4 ) & 0x10 ) |
( ( V_74 >> 6 ) & 4 ) | ( ( V_76 >> 8 ) & 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_93 , V_72 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_94 , V_73 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_95 , V_75 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_96 , V_74 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_97 , V_76 ) ;
}
V_77 = 12 * V_51 * ( 1 << 14 ) * V_54 / V_6 -> V_98 /
10000 ;
V_78 = V_77 / 6 ;
V_79 = V_77 / 5 ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_99 ,
( ( V_78 >> 4 ) & 0xf0 ) | ( V_79 >> 8 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_100 , V_78 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_101 , V_79 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_102 , V_77 / 150 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_103 ,
V_104 | V_105 | 1 ) ;
if ( V_11 < 0 )
return V_11 ;
F_18 ( 230 ) ;
V_11 = F_9 ( V_8 , V_103 , V_104 | 1 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_66 = ( V_42 * V_54 + 512 ) / 1024 ;
* V_67 = ( V_43 * V_54 + 512 ) / 1024 ;
* V_68 = V_42 ;
* V_69 = V_43 ;
F_6 ( & V_8 -> V_13 , L_5 ,
* V_66 , * V_67 , V_54 , V_42 , V_43 , V_70 ) ;
return V_54 ;
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_11 ;
V_11 = F_9 ( V_8 , V_106 , V_107 | V_108 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_106 , V_107 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_109 , V_110 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_111 , V_112 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_113 ,
V_6 -> V_114 . V_115 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_116 ,
V_6 -> V_114 . V_117 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_118 ,
V_6 -> V_114 . V_119 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_120 , 3 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_121 , 0 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_122 ,
V_6 -> V_114 . V_123 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_124 ,
V_6 -> V_114 . V_125 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_126 , 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_127 , 2 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_106 ,
V_107 | V_128 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_129 , 1 ) ;
F_18 ( 10 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_130 , 1 ) ;
if ( ! V_11 )
V_11 = F_5 ( V_8 , V_130 ) ;
if ( V_11 != 1 ) {
F_27 ( & V_8 -> V_13 ,
L_6 , V_11 ) ;
return - V_131 ;
}
V_11 = F_10 ( V_8 , V_121 , 1 , 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_126 , 1 ) ;
return V_11 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_11 = F_26 ( V_8 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_132 , F_13 ( V_132 ) ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_133 , F_13 ( V_133 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_134 , 3 | ( 7 << 4 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_135 , 0xf ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_103 ,
V_104 | 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_136 , 0x84 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_137 , 0x27 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_138 , F_13 ( V_138 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_139 , 0x80 ) ;
if ( ! V_11 )
V_11 = F_5 ( V_8 , V_140 ) ;
if ( V_11 >= 0 ) {
V_6 -> V_92 = V_11 & 0x80 ;
V_11 = F_11 ( V_8 , V_141 , F_13 ( V_141 ) ) ;
}
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_142 , F_13 ( V_142 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_106 ,
V_107 | V_143 | V_128 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_106 ,
V_107 | V_143 | V_144 | V_128 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_145 , 2 ) ;
F_18 ( 700 ) ;
return V_11 ;
}
static int F_29 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = & V_60 -> V_60 ;
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_1 * V_3 ;
int V_42 , V_43 , V_146 , V_147 ,
V_44 = V_6 -> V_39 . V_33 , V_45 = V_6 -> V_39 . V_34 ;
int V_148 = V_62 -> V_2 == V_149 ||
V_62 -> V_2 == V_150 ||
V_62 -> V_2 == V_151 ||
V_62 -> V_2 == V_152 ||
V_62 -> V_2 == V_153 ;
int V_11 ;
if ( V_60 -> V_24 )
return - V_27 ;
F_6 ( & V_8 -> V_13 , L_7 ,
V_154 , V_62 -> V_2 , V_62 -> V_33 , V_62 -> V_34 ) ;
V_3 = F_1 ( V_62 -> V_2 , V_26 ,
F_13 ( V_26 ) ) ;
if ( ! V_3 ) {
V_3 = V_6 -> V_3 ;
V_62 -> V_2 = V_3 -> V_2 ;
}
V_62 -> V_64 = V_65 ;
V_62 -> V_63 = V_3 -> V_63 ;
F_30 ( & V_62 -> V_33 , 112 , V_51 , V_148 ,
& V_62 -> V_34 , 84 , V_53 , V_148 , 0 ) ;
if ( V_60 -> V_46 == V_155 ) {
V_22 -> V_156 = * V_62 ;
return 0 ;
}
V_11 = F_5 ( V_8 , V_106 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! ( V_11 & V_107 ) ) {
V_11 = F_28 ( V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
}
switch ( V_62 -> V_2 ) {
case V_157 :
V_11 = F_9 ( V_8 , V_158 , 0 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_159 , 8 , 8 ) ;
break;
case V_160 :
V_11 = F_9 ( V_8 , V_158 , 0 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_159 , 0 , 8 ) ;
break;
case V_161 :
V_11 = F_9 ( V_8 , V_158 , 0x11 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_159 , 8 , 8 ) ;
break;
case V_162 :
V_11 = F_9 ( V_8 , V_158 , 0x11 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_159 , 0 , 8 ) ;
break;
case V_153 :
V_11 = F_9 ( V_8 , V_158 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_159 , 8 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_163 , 0 ) ;
break;
case V_152 :
V_11 = F_9 ( V_8 , V_158 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_159 , 8 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_163 , 8 ) ;
break;
case V_151 :
V_11 = F_9 ( V_8 , V_158 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_159 , 0 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_163 , 0 ) ;
break;
case V_150 :
V_11 = F_9 ( V_8 , V_158 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_159 , 0 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_163 , 8 ) ;
break;
case V_149 :
V_11 = F_9 ( V_8 , V_158 , 5 ) ;
break;
default:
V_11 = - V_27 ;
}
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_126 ,
( V_62 -> V_2 == V_149 ) << 1 , 2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_146 = V_62 -> V_33 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_44 > V_146 )
V_44 = V_146 ;
V_147 = V_62 -> V_34 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_45 > V_147 )
V_45 = V_147 ;
V_42 = V_62 -> V_33 ;
V_43 = V_62 -> V_34 ;
V_11 = F_21 ( V_20 , & V_44 , & V_45 , & V_42 , & V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
V_3 = F_1 ( V_62 -> V_2 , V_26 ,
F_13 ( V_26 ) ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_54 = V_11 ;
V_6 -> V_39 . V_33 = V_44 ;
V_6 -> V_39 . V_34 = V_45 ;
V_6 -> V_33 = V_42 ;
V_6 -> V_34 = V_43 ;
V_62 -> V_33 = V_42 ;
V_62 -> V_34 = V_43 ;
V_62 -> V_64 = V_65 ;
V_62 -> V_63 = V_3 -> V_63 ;
return 0 ;
}
static int F_31 ( struct V_19 * V_20 ,
struct V_164 * V_10 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
if ( V_10 -> V_10 < 0x400 || V_10 -> V_10 > 0x1fff )
return - V_27 ;
V_10 -> V_165 = 1 ;
V_10 -> V_18 = F_5 ( V_8 , V_10 -> V_10 ) ;
if ( V_10 -> V_18 > 0xff )
return - V_131 ;
return 0 ;
}
static int F_32 ( struct V_19 * V_20 ,
const struct V_164 * V_10 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
if ( V_10 -> V_10 < 0x400 || V_10 -> V_10 > 0x1fff )
return - V_27 ;
if ( F_9 ( V_8 , V_10 -> V_10 , V_10 -> V_18 ) < 0 )
return - V_131 ;
return 0 ;
}
static int F_33 ( struct V_19 * V_20 , int V_166 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_167 * V_168 = F_34 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
return F_35 ( & V_8 -> V_13 , V_168 , V_6 -> V_169 , V_166 ) ;
}
static int F_36 ( struct V_170 * V_171 )
{
struct V_6 * V_6 = F_3 ( V_171 -> V_172 , struct V_6 , V_173 ) ;
struct V_19 * V_20 = & V_6 -> V_9 ;
struct V_7 * V_8 = F_15 ( V_20 ) ;
int V_14 ;
switch ( V_171 -> V_174 ) {
case V_175 :
if ( V_171 -> V_18 )
V_14 = F_10 ( V_8 , V_137 , 0 , 1 ) ;
else
V_14 = F_10 ( V_8 , V_137 , 1 , 1 ) ;
if ( V_14 < 0 )
return - V_131 ;
return 0 ;
case V_176 :
if ( V_171 -> V_18 )
V_14 = F_10 ( V_8 , V_137 , 0 , 2 ) ;
else
V_14 = F_10 ( V_8 , V_137 , 2 , 2 ) ;
if ( V_14 < 0 )
return - V_131 ;
return 0 ;
case V_177 :
if ( F_9 ( V_8 , V_136 , V_171 -> V_18 * 2 ) < 0 )
return - V_131 ;
return 0 ;
case V_178 :
if ( F_10 ( V_8 , V_140 , V_171 -> V_18 << 7 ,
0x80 ) < 0 )
return - V_131 ;
V_6 -> V_92 = V_171 -> V_18 ;
return 0 ;
}
return - V_27 ;
}
static int F_37 ( struct V_19 * V_20 ,
struct V_179 * V_22 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_167 * V_168 = F_34 ( V_8 ) ;
V_22 -> V_180 =
V_181 | V_182 |
V_183 | V_184 |
V_185 | V_186 ;
V_22 -> type = V_187 ;
V_22 -> V_180 = F_38 ( V_168 , V_22 ) ;
return 0 ;
}
static int F_39 ( struct V_19 * V_20 ,
const struct V_179 * V_22 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_167 * V_168 = F_34 ( V_8 ) ;
if ( F_38 ( V_168 , V_22 ) &
V_181 )
return F_9 ( V_8 , V_188 , 1 << 4 ) ;
else
return F_9 ( V_8 , V_188 , 0 ) ;
}
static int F_40 ( struct V_7 * V_8 ,
struct V_189 * V_190 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_191 , V_192 ;
int V_11 ;
V_11 = F_33 ( & V_6 -> V_9 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_191 = F_5 ( V_8 , V_193 ) ;
V_192 = F_5 ( V_8 , V_194 ) ;
if ( V_191 != 0x51 || V_192 != 0x10 ) {
V_11 = - V_195 ;
F_41 ( & V_8 -> V_13 , L_8 ,
V_191 , V_192 ) ;
goto V_196;
}
V_11 = F_9 ( V_8 , V_197 , V_190 -> V_198 << 7 ) ;
if ( V_11 < 0 )
goto V_196;
F_41 ( & V_8 -> V_13 , L_9 ,
V_191 , V_192 ) ;
V_11 = F_42 ( & V_6 -> V_173 ) ;
V_196:
F_33 ( & V_6 -> V_9 , 0 ) ;
return V_11 ;
}
static int F_43 ( struct V_7 * V_8 ,
const struct V_199 * V_200 )
{
struct V_6 * V_6 ;
struct V_167 * V_168 = F_34 ( V_8 ) ;
struct V_201 * V_202 = F_44 ( V_8 -> V_13 . V_203 ) ;
struct V_189 * V_204 ;
int V_11 ;
if ( ! V_168 || ! V_168 -> V_205 ) {
F_27 ( & V_8 -> V_13 , L_10 ) ;
return - V_27 ;
}
V_204 = V_168 -> V_205 ;
if ( ! F_45 ( V_202 , V_206 ) ) {
F_46 ( & V_202 -> V_13 ,
L_11 ) ;
return - V_131 ;
}
V_6 = F_47 ( & V_8 -> V_13 , sizeof( struct V_6 ) , V_207 ) ;
if ( ! V_6 )
return - V_208 ;
F_48 ( & V_6 -> V_9 , V_8 , & V_209 ) ;
F_49 ( & V_6 -> V_173 , 4 ) ;
F_50 ( & V_6 -> V_173 , & V_210 ,
V_175 , 0 , 1 , 1 , 0 ) ;
F_50 ( & V_6 -> V_173 , & V_210 ,
V_176 , 0 , 1 , 1 , 0 ) ;
F_50 ( & V_6 -> V_173 , & V_210 ,
V_177 , 0 , 127 , 1 , 66 ) ;
F_50 ( & V_6 -> V_173 , & V_210 ,
V_178 , 0 , 1 , 1 , 1 ) ;
V_6 -> V_9 . V_211 = & V_6 -> V_173 ;
if ( V_6 -> V_173 . error )
return V_6 -> V_173 . error ;
V_6 -> V_114 = V_114 ;
V_6 -> V_39 . V_57 = V_50 ;
V_6 -> V_39 . V_58 = V_52 ;
V_6 -> V_39 . V_33 = V_51 ;
V_6 -> V_39 . V_34 = V_53 ;
V_6 -> V_33 = V_51 ;
V_6 -> V_34 = V_53 ;
V_6 -> V_3 = & V_26 [ 0 ] ;
V_6 -> V_54 = 1024 ;
V_6 -> V_98 = ( V_204 -> V_212 / V_110 * V_112 ) /
( V_114 . V_115 + 1 ) / ( V_114 . V_117 + 1 ) ;
V_6 -> V_169 = F_51 ( & V_8 -> V_13 , L_12 ) ;
if ( F_52 ( V_6 -> V_169 ) ) {
V_11 = F_53 ( V_6 -> V_169 ) ;
goto V_213;
}
V_11 = F_40 ( V_8 , V_204 ) ;
if ( V_11 < 0 ) {
F_54 ( V_6 -> V_169 ) ;
V_213:
F_55 ( & V_6 -> V_173 ) ;
}
return V_11 ;
}
static int F_56 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_167 * V_168 = F_34 ( V_8 ) ;
F_54 ( V_6 -> V_169 ) ;
F_57 ( & V_6 -> V_9 ) ;
if ( V_168 -> V_214 )
V_168 -> V_214 ( V_168 ) ;
F_55 ( & V_6 -> V_173 ) ;
return 0 ;
}
