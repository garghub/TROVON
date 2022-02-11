int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
return 0 ;
}
int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
return 0 ;
}
int F_3 ( struct V_6 * V_7 , int V_8 ,
int V_9 , unsigned int V_10 , int V_11 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_14 * V_14 = V_13 -> V_14 ;
char * V_15 ;
unsigned int V_16 ;
unsigned int V_17 = V_18 | V_19 ;
unsigned int V_20 = V_9 << V_21 ;
unsigned int * V_22 ;
switch ( V_8 ) {
case V_23 :
V_15 = L_1 ;
V_16 = V_24 ;
V_22 = & V_13 -> V_25 ;
V_17 |= V_26 ;
break;
case V_27 :
V_15 = L_2 ;
V_16 = V_28 ;
V_22 = & V_13 -> V_29 ;
break;
default:
return - V_30 ;
}
switch ( V_10 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_20 |= 1 << V_31 ;
break;
case 22579200 :
case 24576000 :
V_20 |= 2 << V_31 ;
break;
case 45158400 :
case 49152000 :
V_20 |= 3 << V_31 ;
break;
default:
return - V_30 ;
}
* V_22 = V_10 ;
if ( V_10 % 6144000 )
V_20 |= V_26 ;
F_5 ( V_14 -> V_32 , L_3 , V_15 , V_10 ) ;
return F_6 ( V_14 -> V_33 , V_16 , V_17 , V_20 ) ;
}
static int F_7 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_6 * V_7 = V_35 -> V_7 ;
int V_37 , V_38 , V_39 , V_40 ;
V_40 = V_35 -> V_41 -> V_40 ;
V_37 = 0 ;
V_38 = 0 ;
switch ( V_36 & V_42 ) {
case V_43 :
V_39 = 0 ;
break;
case V_44 :
V_39 = 1 ;
break;
case V_45 :
V_39 = 2 ;
break;
case V_46 :
V_39 = 3 ;
break;
default:
F_8 ( V_35 , L_4 ,
V_36 & V_42 ) ;
return - V_30 ;
}
switch ( V_36 & V_47 ) {
case V_48 :
break;
case V_49 :
V_37 |= V_50 ;
break;
case V_51 :
V_38 |= V_52 ;
break;
case V_53 :
V_38 |= V_52 ;
V_37 |= V_50 ;
break;
default:
F_8 ( V_35 , L_5 ,
V_36 & V_47 ) ;
return - V_30 ;
}
switch ( V_36 & V_54 ) {
case V_55 :
break;
case V_56 :
V_38 |= V_57 ;
V_37 |= V_58 ;
break;
case V_59 :
V_38 |= V_57 ;
break;
case V_60 :
V_37 |= V_58 ;
break;
default:
return - V_30 ;
}
F_9 ( V_7 , V_40 + V_61 ,
V_57 | V_52 ,
V_38 ) ;
F_9 ( V_7 , V_40 + V_62 ,
V_58 |
V_50 , V_37 ) ;
F_9 ( V_7 , V_40 + V_63 ,
V_64 |
V_65 , V_37 ) ;
F_9 ( V_7 , V_40 + V_66 ,
V_67 , V_39 ) ;
return 0 ;
}
static int F_10 ( struct V_68 * V_69 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = V_35 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_70 * V_71 = & V_13 -> V_35 [ V_35 -> V_72 - 1 ] ;
const struct V_73 * V_74 ;
unsigned int V_75 ;
switch ( V_71 -> V_22 ) {
case V_23 :
V_75 = V_13 -> V_25 ;
break;
case V_27 :
V_75 = V_13 -> V_29 ;
break;
default:
return 0 ;
}
if ( V_75 % 8000 )
V_74 = & V_76 ;
else
V_74 = & V_77 ;
return V_73 ( V_69 -> V_78 , 0 ,
V_79 ,
V_74 ) ;
}
static int F_11 ( struct V_68 * V_69 ,
struct V_80 * V_81 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = V_35 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_70 * V_71 = & V_13 -> V_35 [ V_35 -> V_72 - 1 ] ;
int V_40 = V_35 -> V_41 -> V_40 ;
const int * V_82 ;
int V_83 ;
int V_38 , V_37 , V_84 , V_85 , V_86 ;
if ( F_12 ( V_81 ) % 8000 )
V_82 = & V_87 [ 0 ] ;
else
V_82 = & V_88 [ 0 ] ;
for ( V_83 = 0 ; V_83 < F_13 ( V_87 ) ; V_83 ++ ) {
if ( V_82 [ V_83 ] >= F_14 ( V_81 ) &&
V_82 [ V_83 ] % F_12 ( V_81 ) == 0 ) {
V_38 = V_83 ;
break;
}
}
if ( V_83 == F_13 ( V_87 ) ) {
F_8 ( V_35 , L_6 ,
F_12 ( V_81 ) ) ;
return - V_30 ;
}
for ( V_83 = 0 ; V_83 < F_13 ( V_89 ) ; V_83 ++ )
if ( V_89 [ V_83 ] == F_12 ( V_81 ) )
break;
if ( V_83 == F_13 ( V_89 ) ) {
F_8 ( V_35 , L_6 ,
F_12 ( V_81 ) ) ;
return - V_30 ;
}
V_86 = V_83 ;
V_37 = F_14 ( V_81 ) / F_12 ( V_81 ) ;
F_15 ( V_35 , L_7 ,
V_82 [ V_38 ] , V_82 [ V_38 ] / V_37 ) ;
V_84 = F_16 ( F_17 ( V_81 ) ) ;
V_85 = V_84 << V_90 | V_84 ;
switch ( V_71 -> V_22 ) {
case V_23 :
F_9 ( V_7 , V_91 ,
V_92 , V_86 ) ;
F_9 ( V_7 , V_40 + V_93 ,
V_94 , 0 ) ;
break;
case V_27 :
F_9 ( V_7 , V_95 ,
V_96 , V_86 ) ;
F_9 ( V_7 , V_40 + V_93 ,
V_94 , 8 ) ;
break;
default:
F_8 ( V_35 , L_8 , V_71 -> V_22 ) ;
return - V_30 ;
}
F_9 ( V_7 , V_40 + V_61 ,
V_97 , V_38 ) ;
F_9 ( V_7 , V_40 + V_98 ,
V_99 , V_37 ) ;
F_9 ( V_7 , V_40 + V_100 ,
V_101 , V_37 ) ;
F_9 ( V_7 , V_40 + V_102 ,
V_103 |
V_104 , V_85 ) ;
F_9 ( V_7 , V_40 + V_105 ,
V_106 |
V_107 , V_85 ) ;
return 0 ;
}
static const char * F_18 ( int V_8 )
{
switch ( V_8 ) {
case V_23 :
return L_1 ;
case V_27 :
return L_2 ;
default:
return L_9 ;
}
}
static int F_19 ( struct V_34 * V_35 ,
int V_8 , unsigned int V_10 , int V_11 )
{
struct V_6 * V_7 = V_35 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_70 * V_71 = & V_13 -> V_35 [ V_35 -> V_72 - 1 ] ;
struct V_108 V_109 [ 2 ] ;
switch ( V_8 ) {
case V_23 :
case V_27 :
break;
default:
return - V_30 ;
}
if ( V_8 == V_71 -> V_22 )
return 0 ;
if ( V_35 -> V_110 ) {
F_20 ( V_7 -> V_32 , L_10 ,
V_35 -> V_72 ) ;
return - V_111 ;
}
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 [ 0 ] . V_112 = V_35 -> V_41 -> V_113 . V_114 ;
V_109 [ 1 ] . V_112 = V_35 -> V_41 -> V_115 . V_114 ;
V_109 [ 0 ] . V_9 = F_18 ( V_71 -> V_22 ) ;
V_109 [ 1 ] . V_9 = F_18 ( V_71 -> V_22 ) ;
F_21 ( & V_7 -> V_116 , V_109 , F_13 ( V_109 ) ) ;
V_109 [ 0 ] . V_9 = F_18 ( V_8 ) ;
V_109 [ 1 ] . V_9 = F_18 ( V_8 ) ;
F_22 ( & V_7 -> V_116 , V_109 , F_13 ( V_109 ) ) ;
return F_23 ( & V_7 -> V_116 ) ;
}
int F_24 ( struct V_12 * V_13 , int V_72 )
{
struct V_70 * V_71 = & V_13 -> V_35 [ V_72 ] ;
V_71 -> V_22 = V_23 ;
return 0 ;
}
static T_1 F_25 ( int V_117 , void * V_118 )
{
struct V_119 * V_120 = V_118 ;
F_26 ( V_120 , L_11 ) ;
F_27 ( & V_120 -> V_121 ) ;
return V_122 ;
}
static T_1 F_28 ( int V_117 , void * V_118 )
{
struct V_119 * V_120 = V_118 ;
F_26 ( V_120 , L_12 ) ;
F_27 ( & V_120 -> V_123 ) ;
return V_122 ;
}
static int F_29 ( struct V_119 * V_120 ,
struct V_124 * V_125 ,
unsigned int V_126 ,
unsigned int V_127 )
{
unsigned int V_128 , div , V_129 ;
int V_83 , V_130 ;
F_26 ( V_120 , L_13 , V_126 , V_127 ) ;
div = 1 ;
V_125 -> V_131 = 0 ;
while ( ( V_126 / div ) > 13500000 ) {
div *= 2 ;
V_125 -> V_131 ++ ;
if ( div > 8 ) {
F_30 ( V_120 ,
L_14 ,
V_126 ) ;
return - V_30 ;
}
}
V_126 /= div ;
div = 1 ;
while ( V_127 * div < 90000000 * V_120 -> V_132 ) {
div ++ ;
if ( div > 7 ) {
F_30 ( V_120 , L_15 ,
V_127 ) ;
return - V_30 ;
}
}
V_128 = V_127 * div / V_120 -> V_132 ;
V_125 -> V_133 = div ;
F_26 ( V_120 , L_16 , V_128 ) ;
for ( V_83 = 0 ; V_83 < F_13 ( V_134 ) ; V_83 ++ ) {
if ( V_134 [ V_83 ] . V_135 <= V_126 && V_126 <= V_134 [ V_83 ] . V_136 ) {
V_125 -> V_137 = V_134 [ V_83 ] . V_137 ;
V_130 = V_134 [ V_83 ] . V_130 ;
break;
}
}
if ( V_83 == F_13 ( V_134 ) ) {
F_30 ( V_120 , L_17 ,
V_126 ) ;
return - V_30 ;
}
V_125 -> V_138 = V_128 / ( V_130 * V_126 ) ;
if ( V_128 % V_126 ) {
V_129 = F_31 ( V_128 , V_130 * V_126 ) ;
F_26 ( V_120 , L_18 , V_129 ) ;
V_125 -> V_139 = ( V_128 - ( V_125 -> V_138 * V_130 * V_126 ) )
/ V_129 ;
V_125 -> V_140 = ( V_130 * V_126 ) / V_129 ;
} else {
V_125 -> V_139 = 0 ;
V_125 -> V_140 = 0 ;
}
F_26 ( V_120 , L_19 ,
V_125 -> V_138 , V_125 -> V_139 , V_125 -> V_140 ) ;
F_26 ( V_120 , L_20 ,
V_125 -> V_137 , V_125 -> V_137 , V_125 -> V_133 , V_125 -> V_131 ) ;
return 0 ;
}
static void F_32 ( struct V_14 * V_14 , unsigned int V_40 ,
struct V_124 * V_125 , int V_9 )
{
F_6 ( V_14 -> V_33 , V_40 + 3 ,
V_141 , V_125 -> V_139 ) ;
F_6 ( V_14 -> V_33 , V_40 + 4 ,
V_142 , V_125 -> V_140 ) ;
F_6 ( V_14 -> V_33 , V_40 + 5 ,
V_143 ,
V_125 -> V_137 << V_144 ) ;
F_6 ( V_14 -> V_33 , V_40 + 6 ,
V_145 |
V_146 ,
V_125 -> V_131 << V_147 |
V_9 << V_148 ) ;
F_6 ( V_14 -> V_33 , V_40 + 2 ,
V_149 | V_150 ,
V_149 | V_125 -> V_138 ) ;
}
int F_33 ( struct V_119 * V_120 , int V_9 ,
unsigned int V_126 , unsigned int V_127 )
{
struct V_14 * V_14 = V_120 -> V_14 ;
struct V_124 V_125 , V_151 ;
unsigned int V_16 , V_20 ;
int V_152 ;
bool V_153 ;
int V_154 ;
V_154 = F_34 ( V_14 -> V_33 , V_120 -> V_40 + 1 , & V_16 ) ;
if ( V_154 != 0 ) {
F_30 ( V_120 , L_21 ,
V_154 ) ;
return V_154 ;
}
V_153 = V_16 & V_155 ;
if ( V_127 ) {
F_34 ( V_14 -> V_33 , V_156 , & V_20 ) ;
switch ( V_20 & V_157 ) {
case V_158 :
case V_159 :
V_152 = V_20 & V_157 ;
break;
default:
V_152 = - 1 ;
}
if ( V_9 == V_152 )
V_152 = - 1 ;
if ( V_152 >= 0 ) {
V_154 = F_29 ( V_120 , & V_151 , V_126 , V_127 ) ;
if ( V_154 != 0 )
return V_154 ;
V_154 = F_29 ( V_120 , & V_125 , 32768 , V_127 ) ;
if ( V_154 != 0 )
return V_154 ;
} else {
V_154 = F_29 ( V_120 , & V_125 , V_126 , V_127 ) ;
if ( V_154 != 0 )
return V_154 ;
}
} else {
F_6 ( V_14 -> V_33 , V_120 -> V_40 + 1 ,
V_155 , 0 ) ;
F_6 ( V_14 -> V_33 , V_120 -> V_40 + 0x11 ,
V_160 , 0 ) ;
if ( V_153 )
F_35 ( V_14 -> V_32 ) ;
return 0 ;
}
F_6 ( V_14 -> V_33 , V_120 -> V_40 + 5 ,
V_161 ,
V_125 . V_133 << V_162 ) ;
if ( V_152 >= 0 ) {
F_32 ( V_14 , V_120 -> V_40 , & V_125 , V_152 ) ;
F_32 ( V_14 , V_120 -> V_40 + 0x10 , & V_151 , V_9 ) ;
} else {
F_32 ( V_14 , V_120 -> V_40 , & V_125 , V_9 ) ;
}
if ( ! V_153 )
F_36 ( V_14 -> V_32 ) ;
F_37 ( & V_120 -> V_123 ) ;
F_6 ( V_14 -> V_33 , V_120 -> V_40 + 1 ,
V_155 , V_155 ) ;
if ( V_152 >= 0 )
F_6 ( V_14 -> V_33 , V_120 -> V_40 + 0x11 ,
V_160 ,
V_160 ) ;
V_154 = F_38 ( & V_120 -> V_123 ,
F_39 ( 25 ) ) ;
if ( V_154 == 0 )
F_40 ( V_120 , L_22 ) ;
return 0 ;
}
int F_41 ( struct V_14 * V_14 , int V_72 , int V_40 , int V_163 ,
int V_164 , struct V_119 * V_120 )
{
int V_154 ;
F_42 ( & V_120 -> V_121 ) ;
F_42 ( & V_120 -> V_123 ) ;
V_120 -> V_72 = V_72 ;
V_120 -> V_40 = V_40 ;
V_120 -> V_14 = V_14 ;
snprintf ( V_120 -> V_165 , sizeof( V_120 -> V_165 ) , L_23 , V_72 ) ;
snprintf ( V_120 -> V_166 , sizeof( V_120 -> V_166 ) ,
L_24 , V_72 ) ;
V_154 = F_43 ( V_14 , V_163 , V_120 -> V_165 ,
F_25 , V_120 ) ;
if ( V_154 != 0 ) {
F_20 ( V_14 -> V_32 , L_25 ,
V_72 , V_154 ) ;
}
V_154 = F_43 ( V_14 , V_164 , V_120 -> V_166 ,
F_28 , V_120 ) ;
if ( V_154 != 0 ) {
F_20 ( V_14 -> V_32 , L_26 ,
V_72 , V_154 ) ;
}
return 0 ;
}
