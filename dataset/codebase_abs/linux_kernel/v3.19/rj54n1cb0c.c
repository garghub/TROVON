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
static int F_12 ( struct V_19 * V_20 , unsigned int V_21 ,
T_1 * V_2 )
{
if ( V_21 >= F_13 ( V_22 ) )
return - V_23 ;
* V_2 = V_22 [ V_21 ] . V_2 ;
return 0 ;
}
static int F_14 ( struct V_19 * V_20 , int V_24 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
return F_10 ( V_8 , V_25 , ( ! V_24 ) << 7 , 0x80 ) ;
}
static int F_16 ( struct V_7 * V_8 ,
T_2 V_26 , T_2 V_27 , T_2 V_28 ,
T_1 V_29 , T_1 V_30 )
{
int V_11 ;
V_11 = F_9 ( V_8 , V_28 ,
( ( V_29 >> 4 ) & 0x70 ) |
( ( V_30 >> 8 ) & 7 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_26 , V_29 & 0xff ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_27 , V_30 & 0xff ) ;
return V_11 ;
}
static int F_17 ( struct V_7 * V_8 )
{
int V_11 = F_9 ( V_8 , V_31 , 1 ) ;
F_18 ( 10 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_31 , 0 ) ;
return V_11 ;
}
static int F_19 ( struct V_19 * V_20 , const struct V_32 * V_33 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_34 * V_35 = & V_33 -> V_36 ;
int V_37 = 0 , V_38 , V_39 ,
V_40 = V_35 -> V_29 , V_41 = V_35 -> V_30 ;
int V_11 ;
F_20 ( & V_37 , & V_40 ,
V_42 , 8 , V_43 ) ;
F_20 ( & V_37 , & V_41 ,
V_44 , 8 , V_45 ) ;
V_38 = ( V_40 * 1024 + V_6 -> V_46 / 2 ) / V_6 -> V_46 ;
V_39 = ( V_41 * 1024 + V_6 -> V_46 / 2 ) / V_6 -> V_46 ;
F_6 ( & V_8 -> V_13 , L_2 ,
V_40 , V_41 , V_6 -> V_46 , V_38 , V_39 ) ;
V_11 = F_21 ( V_20 , & V_40 , & V_41 , & V_38 , & V_39 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_29 = V_38 ;
V_6 -> V_30 = V_39 ;
V_6 -> V_46 = V_11 ;
V_6 -> V_35 . V_29 = V_40 ;
V_6 -> V_35 . V_30 = V_41 ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 , struct V_32 * V_33 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
V_33 -> V_36 = V_6 -> V_35 ;
V_33 -> type = V_47 ;
return 0 ;
}
static int F_23 ( struct V_19 * V_20 , struct V_48 * V_33 )
{
V_33 -> V_49 . V_50 = V_42 ;
V_33 -> V_49 . V_51 = V_44 ;
V_33 -> V_49 . V_29 = V_43 ;
V_33 -> V_49 . V_30 = V_45 ;
V_33 -> V_52 = V_33 -> V_49 ;
V_33 -> type = V_47 ;
V_33 -> V_53 . V_54 = 1 ;
V_33 -> V_53 . V_55 = 1 ;
return 0 ;
}
static int F_24 ( struct V_19 * V_20 ,
struct V_56 * V_57 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
V_57 -> V_2 = V_6 -> V_3 -> V_2 ;
V_57 -> V_58 = V_6 -> V_3 -> V_58 ;
V_57 -> V_59 = V_60 ;
V_57 -> V_29 = V_6 -> V_29 ;
V_57 -> V_30 = V_6 -> V_30 ;
return 0 ;
}
static int F_21 ( struct V_19 * V_20 , T_4 * V_61 , T_4 * V_62 ,
T_4 * V_63 , T_4 * V_64 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
unsigned int V_65 , V_46 , V_40 = * V_61 , V_41 = * V_62 ,
V_38 = * V_63 , V_39 = * V_64 ;
T_2 V_66 , V_67 , V_68 , V_69 , V_70 , V_71 ;
unsigned int V_72 , V_73 , V_74 ;
int V_11 ;
if ( V_38 > F_25 ( 512U , V_40 / 2 ) ) {
if ( 2 * V_38 > V_43 ) {
V_40 = V_43 ;
V_38 = V_43 / 2 ;
} else {
V_40 = V_38 * 2 ;
}
F_6 ( & V_8 -> V_13 , L_3 ,
V_40 , V_38 ) ;
}
if ( V_39 > F_25 ( 384U , V_41 / 2 ) ) {
if ( 2 * V_39 > V_45 ) {
V_41 = V_45 ;
V_39 = V_45 / 2 ;
} else {
V_41 = V_39 * 2 ;
}
F_6 ( & V_8 -> V_13 , L_4 ,
V_41 , V_39 ) ;
}
V_11 = F_16 ( V_8 , V_75 ,
V_76 ,
V_77 , V_38 , V_39 ) ;
if ( ! V_11 )
V_11 = F_16 ( V_8 , V_78 ,
V_79 ,
V_80 , V_38 , V_39 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_38 > V_40 && V_39 > V_41 ) {
V_40 = V_38 ;
V_41 = V_39 ;
V_46 = 1024 ;
} else {
unsigned int V_81 , V_82 ;
V_81 = ( V_40 * 1024 + V_38 / 2 ) / V_38 ;
V_82 = ( V_41 * 1024 + V_39 / 2 ) / V_39 ;
if ( V_81 > V_82 &&
( V_39 * V_81 + 512 ) / 1024 > V_45 )
V_46 = ( V_45 * 1024 + V_39 / 2 ) /
V_39 ;
else if ( V_82 > V_81 &&
( V_38 * V_82 + 512 ) / 1024 > V_43 )
V_46 = ( V_43 * 1024 + V_38 / 2 ) /
V_38 ;
else
V_46 = F_25 ( V_81 , V_82 ) ;
switch ( V_46 ) {
case 2040 ... 2047 :
V_46 = 2039 ;
break;
case 4080 ... 4095 :
V_46 = 4079 ;
break;
case 8160 ... 8191 :
V_46 = 8159 ;
break;
case 16320 ... 16384 :
V_46 = 16319 ;
}
}
V_11 = F_9 ( V_8 , V_83 , V_46 & 0xff ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_84 , V_46 >> 8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_65 = F_26 ( V_46 / 1024 , 15U ) ;
V_66 = 1 << V_65 ;
if ( V_66 <= 2 )
V_66 = 0xc ;
else if ( V_46 & 1023 && V_65 < 15 )
V_66 |= 1 << ( V_65 + 1 ) ;
V_11 = F_9 ( V_8 , V_85 , V_66 & 0xfc ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_86 , V_66 >> 8 ) ;
if ( ! V_6 -> V_87 ) {
V_68 = V_38 / 16 ;
V_69 = ( 3 * V_38 / 4 - 3 ) / 4 ;
V_70 = V_39 / 16 ;
V_71 = ( 3 * V_39 / 4 - 3 ) / 4 ;
V_67 = ( ( V_68 >> 2 ) & 0x40 ) | ( ( V_70 >> 4 ) & 0x10 ) |
( ( V_69 >> 6 ) & 4 ) | ( ( V_71 >> 8 ) & 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_88 , V_67 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_89 , V_68 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_90 , V_70 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_91 , V_69 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_92 , V_71 ) ;
}
V_72 = 12 * V_43 * ( 1 << 14 ) * V_46 / V_6 -> V_93 /
10000 ;
V_73 = V_72 / 6 ;
V_74 = V_72 / 5 ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_94 ,
( ( V_73 >> 4 ) & 0xf0 ) | ( V_74 >> 8 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_95 , V_73 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_96 , V_74 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_97 , V_72 / 150 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_98 ,
V_99 | V_100 | 1 ) ;
if ( V_11 < 0 )
return V_11 ;
F_18 ( 230 ) ;
V_11 = F_9 ( V_8 , V_98 , V_99 | 1 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_61 = ( V_38 * V_46 + 512 ) / 1024 ;
* V_62 = ( V_39 * V_46 + 512 ) / 1024 ;
* V_63 = V_38 ;
* V_64 = V_39 ;
F_6 ( & V_8 -> V_13 , L_5 ,
* V_61 , * V_62 , V_46 , V_38 , V_39 , V_65 ) ;
return V_46 ;
}
static int F_27 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_11 ;
V_11 = F_9 ( V_8 , V_101 , V_102 | V_103 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_101 , V_102 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_104 , V_105 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_106 , V_107 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_108 ,
V_6 -> V_109 . V_110 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_111 ,
V_6 -> V_109 . V_112 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_113 ,
V_6 -> V_109 . V_114 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_115 , 3 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_116 , 0 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_117 ,
V_6 -> V_109 . V_118 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_119 ,
V_6 -> V_109 . V_120 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_121 , 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_122 , 2 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_101 ,
V_102 | V_123 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_124 , 1 ) ;
F_18 ( 10 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_125 , 1 ) ;
if ( ! V_11 )
V_11 = F_5 ( V_8 , V_125 ) ;
if ( V_11 != 1 ) {
F_28 ( & V_8 -> V_13 ,
L_6 , V_11 ) ;
return - V_126 ;
}
V_11 = F_10 ( V_8 , V_116 , 1 , 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_121 , 1 ) ;
return V_11 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_11 = F_27 ( V_8 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_127 , F_13 ( V_127 ) ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_128 , F_13 ( V_128 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_129 , 3 | ( 7 << 4 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_130 , 0xf ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_98 ,
V_99 | 1 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_131 , 0x84 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_132 , 0x27 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_133 , F_13 ( V_133 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_134 , 0x80 ) ;
if ( ! V_11 )
V_11 = F_5 ( V_8 , V_135 ) ;
if ( V_11 >= 0 ) {
V_6 -> V_87 = V_11 & 0x80 ;
V_11 = F_11 ( V_8 , V_136 , F_13 ( V_136 ) ) ;
}
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_137 , F_13 ( V_137 ) ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_101 ,
V_102 | V_138 | V_123 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_101 ,
V_102 | V_138 | V_139 | V_123 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_140 , 2 ) ;
F_18 ( 700 ) ;
return V_11 ;
}
static int F_30 ( struct V_19 * V_20 ,
struct V_56 * V_57 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_1 * V_3 ;
int V_141 = V_57 -> V_2 == V_142 ||
V_57 -> V_2 == V_143 ||
V_57 -> V_2 == V_144 ||
V_57 -> V_2 == V_145 ||
V_57 -> V_2 == V_146 ;
F_6 ( & V_8 -> V_13 , L_7 ,
V_147 , V_57 -> V_2 , V_57 -> V_29 , V_57 -> V_30 ) ;
V_3 = F_1 ( V_57 -> V_2 , V_22 ,
F_13 ( V_22 ) ) ;
if ( ! V_3 ) {
V_3 = V_6 -> V_3 ;
V_57 -> V_2 = V_3 -> V_2 ;
}
V_57 -> V_59 = V_60 ;
V_57 -> V_58 = V_3 -> V_58 ;
F_31 ( & V_57 -> V_29 , 112 , V_43 , V_141 ,
& V_57 -> V_30 , 84 , V_45 , V_141 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_19 * V_20 ,
struct V_56 * V_57 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_1 * V_3 ;
int V_38 , V_39 , V_148 , V_149 ,
V_40 = V_6 -> V_35 . V_29 , V_41 = V_6 -> V_35 . V_30 ;
int V_11 ;
F_30 ( V_20 , V_57 ) ;
V_11 = F_5 ( V_8 , V_101 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! ( V_11 & V_102 ) ) {
V_11 = F_29 ( V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
}
F_6 ( & V_8 -> V_13 , L_7 ,
V_147 , V_57 -> V_2 , V_57 -> V_29 , V_57 -> V_30 ) ;
switch ( V_57 -> V_2 ) {
case V_150 :
V_11 = F_9 ( V_8 , V_151 , 0 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_152 , 8 , 8 ) ;
break;
case V_153 :
V_11 = F_9 ( V_8 , V_151 , 0 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_152 , 0 , 8 ) ;
break;
case V_154 :
V_11 = F_9 ( V_8 , V_151 , 0x11 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_152 , 8 , 8 ) ;
break;
case V_155 :
V_11 = F_9 ( V_8 , V_151 , 0x11 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_152 , 0 , 8 ) ;
break;
case V_146 :
V_11 = F_9 ( V_8 , V_151 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_152 , 8 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_156 , 0 ) ;
break;
case V_145 :
V_11 = F_9 ( V_8 , V_151 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_152 , 8 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_156 , 8 ) ;
break;
case V_144 :
V_11 = F_9 ( V_8 , V_151 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_152 , 0 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_156 , 0 ) ;
break;
case V_143 :
V_11 = F_9 ( V_8 , V_151 , 4 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_152 , 0 , 8 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_156 , 8 ) ;
break;
case V_142 :
V_11 = F_9 ( V_8 , V_151 , 5 ) ;
break;
default:
V_11 = - V_23 ;
}
if ( ! V_11 )
V_11 = F_10 ( V_8 , V_121 ,
( V_57 -> V_2 == V_142 ) << 1 , 2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_148 = V_57 -> V_29 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_40 > V_148 )
V_40 = V_148 ;
V_149 = V_57 -> V_30 * ( 16 * 1024 - 1 ) / 1024 ;
if ( V_41 > V_149 )
V_41 = V_149 ;
V_38 = V_57 -> V_29 ;
V_39 = V_57 -> V_30 ;
V_11 = F_21 ( V_20 , & V_40 , & V_41 , & V_38 , & V_39 ) ;
if ( V_11 < 0 )
return V_11 ;
V_3 = F_1 ( V_57 -> V_2 , V_22 ,
F_13 ( V_22 ) ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_46 = V_11 ;
V_6 -> V_35 . V_29 = V_40 ;
V_6 -> V_35 . V_30 = V_41 ;
V_6 -> V_29 = V_38 ;
V_6 -> V_30 = V_39 ;
V_57 -> V_29 = V_38 ;
V_57 -> V_30 = V_39 ;
V_57 -> V_59 = V_60 ;
V_57 -> V_58 = V_3 -> V_58 ;
return 0 ;
}
static int F_33 ( struct V_19 * V_20 ,
struct V_157 * V_10 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
if ( V_10 -> V_10 < 0x400 || V_10 -> V_10 > 0x1fff )
return - V_23 ;
V_10 -> V_158 = 1 ;
V_10 -> V_18 = F_5 ( V_8 , V_10 -> V_10 ) ;
if ( V_10 -> V_18 > 0xff )
return - V_126 ;
return 0 ;
}
static int F_34 ( struct V_19 * V_20 ,
const struct V_157 * V_10 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
if ( V_10 -> V_10 < 0x400 || V_10 -> V_10 > 0x1fff )
return - V_23 ;
if ( F_9 ( V_8 , V_10 -> V_10 , V_10 -> V_18 ) < 0 )
return - V_126 ;
return 0 ;
}
static int F_35 ( struct V_19 * V_20 , int V_159 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_160 * V_161 = F_36 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
return F_37 ( & V_8 -> V_13 , V_161 , V_6 -> V_162 , V_159 ) ;
}
static int F_38 ( struct V_163 * V_164 )
{
struct V_6 * V_6 = F_3 ( V_164 -> V_165 , struct V_6 , V_166 ) ;
struct V_19 * V_20 = & V_6 -> V_9 ;
struct V_7 * V_8 = F_15 ( V_20 ) ;
int V_14 ;
switch ( V_164 -> V_167 ) {
case V_168 :
if ( V_164 -> V_18 )
V_14 = F_10 ( V_8 , V_132 , 0 , 1 ) ;
else
V_14 = F_10 ( V_8 , V_132 , 1 , 1 ) ;
if ( V_14 < 0 )
return - V_126 ;
return 0 ;
case V_169 :
if ( V_164 -> V_18 )
V_14 = F_10 ( V_8 , V_132 , 0 , 2 ) ;
else
V_14 = F_10 ( V_8 , V_132 , 2 , 2 ) ;
if ( V_14 < 0 )
return - V_126 ;
return 0 ;
case V_170 :
if ( F_9 ( V_8 , V_131 , V_164 -> V_18 * 2 ) < 0 )
return - V_126 ;
return 0 ;
case V_171 :
if ( F_10 ( V_8 , V_135 , V_164 -> V_18 << 7 ,
0x80 ) < 0 )
return - V_126 ;
V_6 -> V_87 = V_164 -> V_18 ;
return 0 ;
}
return - V_23 ;
}
static int F_39 ( struct V_19 * V_20 ,
struct V_172 * V_173 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_160 * V_161 = F_36 ( V_8 ) ;
V_173 -> V_174 =
V_175 | V_176 |
V_177 | V_178 |
V_179 | V_180 ;
V_173 -> type = V_181 ;
V_173 -> V_174 = F_40 ( V_161 , V_173 ) ;
return 0 ;
}
static int F_41 ( struct V_19 * V_20 ,
const struct V_172 * V_173 )
{
struct V_7 * V_8 = F_15 ( V_20 ) ;
struct V_160 * V_161 = F_36 ( V_8 ) ;
if ( F_40 ( V_161 , V_173 ) &
V_175 )
return F_9 ( V_8 , V_182 , 1 << 4 ) ;
else
return F_9 ( V_8 , V_182 , 0 ) ;
}
static int F_42 ( struct V_7 * V_8 ,
struct V_183 * V_184 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_185 , V_186 ;
int V_11 ;
V_11 = F_35 ( & V_6 -> V_9 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_185 = F_5 ( V_8 , V_187 ) ;
V_186 = F_5 ( V_8 , V_188 ) ;
if ( V_185 != 0x51 || V_186 != 0x10 ) {
V_11 = - V_189 ;
F_43 ( & V_8 -> V_13 , L_8 ,
V_185 , V_186 ) ;
goto V_190;
}
V_11 = F_9 ( V_8 , V_191 , V_184 -> V_192 << 7 ) ;
if ( V_11 < 0 )
goto V_190;
F_43 ( & V_8 -> V_13 , L_9 ,
V_185 , V_186 ) ;
V_11 = F_44 ( & V_6 -> V_166 ) ;
V_190:
F_35 ( & V_6 -> V_9 , 0 ) ;
return V_11 ;
}
static int F_45 ( struct V_7 * V_8 ,
const struct V_193 * V_194 )
{
struct V_6 * V_6 ;
struct V_160 * V_161 = F_36 ( V_8 ) ;
struct V_195 * V_196 = F_46 ( V_8 -> V_13 . V_197 ) ;
struct V_183 * V_198 ;
int V_11 ;
if ( ! V_161 || ! V_161 -> V_199 ) {
F_28 ( & V_8 -> V_13 , L_10 ) ;
return - V_23 ;
}
V_198 = V_161 -> V_199 ;
if ( ! F_47 ( V_196 , V_200 ) ) {
F_48 ( & V_196 -> V_13 ,
L_11 ) ;
return - V_126 ;
}
V_6 = F_49 ( & V_8 -> V_13 , sizeof( struct V_6 ) , V_201 ) ;
if ( ! V_6 )
return - V_202 ;
F_50 ( & V_6 -> V_9 , V_8 , & V_203 ) ;
F_51 ( & V_6 -> V_166 , 4 ) ;
F_52 ( & V_6 -> V_166 , & V_204 ,
V_168 , 0 , 1 , 1 , 0 ) ;
F_52 ( & V_6 -> V_166 , & V_204 ,
V_169 , 0 , 1 , 1 , 0 ) ;
F_52 ( & V_6 -> V_166 , & V_204 ,
V_170 , 0 , 127 , 1 , 66 ) ;
F_52 ( & V_6 -> V_166 , & V_204 ,
V_171 , 0 , 1 , 1 , 1 ) ;
V_6 -> V_9 . V_205 = & V_6 -> V_166 ;
if ( V_6 -> V_166 . error )
return V_6 -> V_166 . error ;
V_6 -> V_109 = V_109 ;
V_6 -> V_35 . V_50 = V_42 ;
V_6 -> V_35 . V_51 = V_44 ;
V_6 -> V_35 . V_29 = V_43 ;
V_6 -> V_35 . V_30 = V_45 ;
V_6 -> V_29 = V_43 ;
V_6 -> V_30 = V_45 ;
V_6 -> V_3 = & V_22 [ 0 ] ;
V_6 -> V_46 = 1024 ;
V_6 -> V_93 = ( V_198 -> V_206 / V_105 * V_107 ) /
( V_109 . V_110 + 1 ) / ( V_109 . V_112 + 1 ) ;
V_6 -> V_162 = F_53 ( & V_8 -> V_13 , L_12 ) ;
if ( F_54 ( V_6 -> V_162 ) ) {
V_11 = F_55 ( V_6 -> V_162 ) ;
goto V_207;
}
V_11 = F_42 ( V_8 , V_198 ) ;
if ( V_11 < 0 ) {
F_56 ( V_6 -> V_162 ) ;
V_207:
F_57 ( & V_6 -> V_166 ) ;
}
return V_11 ;
}
static int F_58 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_160 * V_161 = F_36 ( V_8 ) ;
F_56 ( V_6 -> V_162 ) ;
F_59 ( & V_6 -> V_9 ) ;
if ( V_161 -> V_208 )
V_161 -> V_208 ( V_161 ) ;
F_57 ( & V_6 -> V_166 ) ;
return 0 ;
}
