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
static int F_3 ( struct V_6 * V_7 , unsigned int V_8 ,
unsigned int V_9 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned int V_12 ;
unsigned int * V_13 ;
int V_14 , div , V_15 ;
switch ( V_8 ) {
case V_16 :
V_12 = V_17 ;
V_15 = V_11 -> V_18 ;
break;
case V_19 :
V_12 = V_20 ;
V_15 = V_11 -> V_21 ;
break;
default:
return - V_22 ;
}
if ( V_15 % 8000 )
V_13 = V_23 ;
else
V_13 = V_24 ;
for ( V_14 = 0 ; V_14 < F_5 ( V_24 ) &&
V_13 [ V_14 ] <= V_15 ; V_14 ++ ) {
div = 1 ;
while ( V_13 [ V_14 ] / div >= V_9 && div < 32 ) {
if ( V_13 [ V_14 ] / div == V_9 ) {
F_6 ( V_7 -> V_25 , L_1 ,
V_9 ) ;
F_7 ( V_7 , V_12 ,
V_26 |
V_27 ,
( div <<
V_28 ) |
V_14 ) ;
return 0 ;
}
div ++ ;
}
}
F_8 ( V_7 -> V_25 , L_2 , V_9 ) ;
return - V_22 ;
}
int F_9 ( struct V_6 * V_7 , int V_29 ,
int V_30 , unsigned int V_9 , int V_31 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_32 * V_32 = V_11 -> V_32 ;
char * V_33 ;
unsigned int V_12 ;
unsigned int V_34 = V_35 | V_36 ;
unsigned int V_37 = V_30 << V_38 ;
unsigned int * V_8 ;
switch ( V_29 ) {
case V_39 :
V_33 = L_3 ;
V_12 = V_40 ;
V_8 = & V_11 -> V_18 ;
V_34 |= V_41 ;
break;
case V_42 :
V_33 = L_4 ;
V_12 = V_43 ;
V_8 = & V_11 -> V_21 ;
break;
case V_16 :
case V_19 :
return F_3 ( V_7 , V_29 , V_9 ) ;
default:
return - V_22 ;
}
switch ( V_9 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_37 |= 1 << V_44 ;
break;
case 22579200 :
case 24576000 :
V_37 |= 2 << V_44 ;
break;
case 45158400 :
case 49152000 :
V_37 |= 3 << V_44 ;
break;
default:
return - V_22 ;
}
* V_8 = V_9 ;
if ( V_9 % 6144000 )
V_37 |= V_41 ;
F_6 ( V_32 -> V_25 , L_5 , V_33 , V_9 ) ;
return F_10 ( V_32 -> V_45 , V_12 , V_34 , V_37 ) ;
}
static int F_11 ( struct V_46 * V_47 , unsigned int V_48 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
int V_49 , V_50 , V_51 , V_52 ;
V_52 = V_47 -> V_53 -> V_52 ;
V_49 = 0 ;
V_50 = 0 ;
switch ( V_48 & V_54 ) {
case V_55 :
V_51 = 0 ;
break;
case V_56 :
V_51 = 1 ;
break;
case V_57 :
V_51 = 2 ;
break;
case V_58 :
V_51 = 3 ;
break;
default:
F_12 ( V_47 , L_6 ,
V_48 & V_54 ) ;
return - V_22 ;
}
switch ( V_48 & V_59 ) {
case V_60 :
break;
case V_61 :
V_49 |= V_62 ;
break;
case V_63 :
V_50 |= V_64 ;
break;
case V_65 :
V_50 |= V_64 ;
V_49 |= V_62 ;
break;
default:
F_12 ( V_47 , L_7 ,
V_48 & V_59 ) ;
return - V_22 ;
}
switch ( V_48 & V_66 ) {
case V_67 :
break;
case V_68 :
V_50 |= V_69 ;
V_49 |= V_70 ;
break;
case V_71 :
V_50 |= V_69 ;
break;
case V_72 :
V_49 |= V_70 ;
break;
default:
return - V_22 ;
}
F_7 ( V_7 , V_52 + V_73 ,
V_69 | V_64 ,
V_50 ) ;
F_7 ( V_7 , V_52 + V_74 ,
V_70 |
V_62 , V_49 ) ;
F_7 ( V_7 , V_52 + V_75 ,
V_76 |
V_77 , V_49 ) ;
F_7 ( V_7 , V_52 + V_78 ,
V_79 , V_51 ) ;
return 0 ;
}
static int F_13 ( struct V_80 * V_81 ,
struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_82 * V_83 = & V_11 -> V_47 [ V_47 -> V_84 - 1 ] ;
const struct V_85 * V_86 ;
unsigned int V_87 ;
switch ( V_83 -> V_8 ) {
case V_39 :
V_87 = V_11 -> V_18 ;
break;
case V_42 :
V_87 = V_11 -> V_21 ;
break;
default:
return 0 ;
}
if ( V_87 % 8000 )
V_86 = & V_88 ;
else
V_86 = & V_89 ;
return V_85 ( V_81 -> V_90 , 0 ,
V_91 ,
V_86 ) ;
}
static int F_14 ( struct V_80 * V_81 ,
struct V_92 * V_93 ,
struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_82 * V_83 = & V_11 -> V_47 [ V_47 -> V_84 - 1 ] ;
int V_52 = V_47 -> V_53 -> V_52 ;
const int * V_13 ;
int V_94 ;
int V_50 , V_49 , V_95 , V_96 , V_97 ;
if ( F_15 ( V_93 ) % 8000 )
V_13 = & V_98 [ 0 ] ;
else
V_13 = & V_99 [ 0 ] ;
for ( V_94 = 0 ; V_94 < F_5 ( V_98 ) ; V_94 ++ ) {
if ( V_13 [ V_94 ] >= F_16 ( V_93 ) &&
V_13 [ V_94 ] % F_15 ( V_93 ) == 0 ) {
V_50 = V_94 ;
break;
}
}
if ( V_94 == F_5 ( V_98 ) ) {
F_12 ( V_47 , L_8 ,
F_15 ( V_93 ) ) ;
return - V_22 ;
}
for ( V_94 = 0 ; V_94 < F_5 ( V_100 ) ; V_94 ++ )
if ( V_100 [ V_94 ] == F_15 ( V_93 ) )
break;
if ( V_94 == F_5 ( V_100 ) ) {
F_12 ( V_47 , L_8 ,
F_15 ( V_93 ) ) ;
return - V_22 ;
}
V_97 = V_94 ;
V_49 = F_16 ( V_93 ) / F_15 ( V_93 ) ;
F_17 ( V_47 , L_9 ,
V_13 [ V_50 ] , V_13 [ V_50 ] / V_49 ) ;
V_95 = F_18 ( F_19 ( V_93 ) ) ;
V_96 = V_95 << V_101 | V_95 ;
switch ( V_83 -> V_8 ) {
case V_39 :
F_7 ( V_7 , V_102 ,
V_103 , V_97 ) ;
F_7 ( V_7 , V_52 + V_104 ,
V_105 , 0 ) ;
break;
case V_42 :
F_7 ( V_7 , V_106 ,
V_107 , V_97 ) ;
F_7 ( V_7 , V_52 + V_104 ,
V_105 , 8 ) ;
break;
default:
F_12 ( V_47 , L_10 , V_83 -> V_8 ) ;
return - V_22 ;
}
F_7 ( V_7 , V_52 + V_73 ,
V_108 , V_50 ) ;
F_7 ( V_7 , V_52 + V_109 ,
V_110 , V_49 ) ;
F_7 ( V_7 , V_52 + V_111 ,
V_112 , V_49 ) ;
F_7 ( V_7 , V_52 + V_113 ,
V_114 |
V_115 , V_96 ) ;
F_7 ( V_7 , V_52 + V_116 ,
V_117 |
V_118 , V_96 ) ;
return 0 ;
}
static const char * F_20 ( int V_29 )
{
switch ( V_29 ) {
case V_39 :
return L_3 ;
case V_42 :
return L_4 ;
default:
return L_11 ;
}
}
static int F_21 ( struct V_46 * V_47 ,
int V_29 , unsigned int V_9 , int V_31 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_82 * V_83 = & V_11 -> V_47 [ V_47 -> V_84 - 1 ] ;
struct V_119 V_120 [ 2 ] ;
switch ( V_29 ) {
case V_39 :
case V_42 :
break;
default:
return - V_22 ;
}
if ( V_29 == V_83 -> V_8 )
return 0 ;
if ( V_47 -> V_121 ) {
F_8 ( V_7 -> V_25 , L_12 ,
V_47 -> V_84 ) ;
return - V_122 ;
}
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 [ 0 ] . V_123 = V_47 -> V_53 -> V_124 . V_125 ;
V_120 [ 1 ] . V_123 = V_47 -> V_53 -> V_126 . V_125 ;
V_120 [ 0 ] . V_30 = F_20 ( V_83 -> V_8 ) ;
V_120 [ 1 ] . V_30 = F_20 ( V_83 -> V_8 ) ;
F_22 ( & V_7 -> V_127 , V_120 , F_5 ( V_120 ) ) ;
V_120 [ 0 ] . V_30 = F_20 ( V_29 ) ;
V_120 [ 1 ] . V_30 = F_20 ( V_29 ) ;
F_23 ( & V_7 -> V_127 , V_120 , F_5 ( V_120 ) ) ;
return F_24 ( & V_7 -> V_127 ) ;
}
int F_25 ( struct V_10 * V_11 , int V_84 )
{
struct V_82 * V_83 = & V_11 -> V_47 [ V_84 ] ;
V_83 -> V_8 = V_39 ;
return 0 ;
}
static T_1 F_26 ( int V_128 , void * V_129 )
{
struct V_130 * V_131 = V_129 ;
F_27 ( V_131 , L_13 ) ;
F_28 ( & V_131 -> V_132 ) ;
return V_133 ;
}
static T_1 F_29 ( int V_128 , void * V_129 )
{
struct V_130 * V_131 = V_129 ;
F_27 ( V_131 , L_14 ) ;
F_28 ( & V_131 -> V_134 ) ;
return V_133 ;
}
static int F_30 ( struct V_130 * V_131 ,
struct V_135 * V_136 ,
unsigned int V_137 ,
unsigned int V_138 )
{
unsigned int V_139 , div , V_140 ;
int V_94 , V_141 ;
F_27 ( V_131 , L_15 , V_137 , V_138 ) ;
div = 1 ;
V_136 -> V_142 = 0 ;
while ( ( V_137 / div ) > 13500000 ) {
div *= 2 ;
V_136 -> V_142 ++ ;
if ( div > 8 ) {
F_31 ( V_131 ,
L_16 ,
V_137 ) ;
return - V_22 ;
}
}
V_137 /= div ;
div = 1 ;
while ( V_138 * div < 90000000 * V_131 -> V_143 ) {
div ++ ;
if ( div > 7 ) {
F_31 ( V_131 , L_17 ,
V_138 ) ;
return - V_22 ;
}
}
V_139 = V_138 * div / V_131 -> V_143 ;
V_136 -> V_144 = div ;
F_27 ( V_131 , L_18 , V_139 ) ;
for ( V_94 = 0 ; V_94 < F_5 ( V_145 ) ; V_94 ++ ) {
if ( V_145 [ V_94 ] . V_146 <= V_137 && V_137 <= V_145 [ V_94 ] . V_147 ) {
V_136 -> V_148 = V_145 [ V_94 ] . V_148 ;
V_141 = V_145 [ V_94 ] . V_141 ;
break;
}
}
if ( V_94 == F_5 ( V_145 ) ) {
F_31 ( V_131 , L_19 ,
V_137 ) ;
return - V_22 ;
}
V_136 -> V_149 = V_139 / ( V_141 * V_137 ) ;
if ( V_139 % V_137 ) {
V_140 = F_32 ( V_139 , V_141 * V_137 ) ;
F_27 ( V_131 , L_20 , V_140 ) ;
V_136 -> V_150 = ( V_139 - ( V_136 -> V_149 * V_141 * V_137 ) )
/ V_140 ;
V_136 -> V_151 = ( V_141 * V_137 ) / V_140 ;
} else {
V_136 -> V_150 = 0 ;
V_136 -> V_151 = 0 ;
}
F_27 ( V_131 , L_21 ,
V_136 -> V_149 , V_136 -> V_150 , V_136 -> V_151 ) ;
F_27 ( V_131 , L_22 ,
V_136 -> V_148 , V_136 -> V_148 , V_136 -> V_144 , V_136 -> V_142 ) ;
return 0 ;
}
static void F_33 ( struct V_32 * V_32 , unsigned int V_52 ,
struct V_135 * V_136 , int V_30 )
{
F_10 ( V_32 -> V_45 , V_52 + 3 ,
V_152 , V_136 -> V_150 ) ;
F_10 ( V_32 -> V_45 , V_52 + 4 ,
V_153 , V_136 -> V_151 ) ;
F_10 ( V_32 -> V_45 , V_52 + 5 ,
V_154 ,
V_136 -> V_148 << V_155 ) ;
F_10 ( V_32 -> V_45 , V_52 + 6 ,
V_156 |
V_157 ,
V_136 -> V_142 << V_158 |
V_30 << V_159 ) ;
F_10 ( V_32 -> V_45 , V_52 + 2 ,
V_160 | V_161 ,
V_160 | V_136 -> V_149 ) ;
}
int F_34 ( struct V_130 * V_131 , int V_30 ,
unsigned int V_137 , unsigned int V_138 )
{
struct V_32 * V_32 = V_131 -> V_32 ;
struct V_135 V_136 , V_162 ;
unsigned int V_12 , V_37 ;
int V_163 ;
bool V_164 ;
int V_165 ;
V_165 = F_35 ( V_32 -> V_45 , V_131 -> V_52 + 1 , & V_12 ) ;
if ( V_165 != 0 ) {
F_31 ( V_131 , L_23 ,
V_165 ) ;
return V_165 ;
}
V_164 = V_12 & V_166 ;
if ( V_138 ) {
F_35 ( V_32 -> V_45 , V_167 , & V_37 ) ;
switch ( V_37 & V_168 ) {
case V_169 :
case V_170 :
V_163 = V_37 & V_168 ;
break;
default:
V_163 = - 1 ;
}
if ( V_30 == V_163 )
V_163 = - 1 ;
if ( V_163 >= 0 ) {
V_165 = F_30 ( V_131 , & V_162 , V_137 , V_138 ) ;
if ( V_165 != 0 )
return V_165 ;
V_165 = F_30 ( V_131 , & V_136 , 32768 , V_138 ) ;
if ( V_165 != 0 )
return V_165 ;
} else {
V_165 = F_30 ( V_131 , & V_136 , V_137 , V_138 ) ;
if ( V_165 != 0 )
return V_165 ;
}
} else {
F_10 ( V_32 -> V_45 , V_131 -> V_52 + 1 ,
V_166 , 0 ) ;
F_10 ( V_32 -> V_45 , V_131 -> V_52 + 0x11 ,
V_171 , 0 ) ;
if ( V_164 )
F_36 ( V_32 -> V_25 ) ;
return 0 ;
}
F_10 ( V_32 -> V_45 , V_131 -> V_52 + 5 ,
V_172 ,
V_136 . V_144 << V_173 ) ;
if ( V_163 >= 0 ) {
F_33 ( V_32 , V_131 -> V_52 , & V_136 , V_163 ) ;
F_33 ( V_32 , V_131 -> V_52 + 0x10 , & V_162 , V_30 ) ;
} else {
F_33 ( V_32 , V_131 -> V_52 , & V_136 , V_30 ) ;
}
if ( ! V_164 )
F_37 ( V_32 -> V_25 ) ;
F_38 ( & V_131 -> V_134 ) ;
F_10 ( V_32 -> V_45 , V_131 -> V_52 + 1 ,
V_166 , V_166 ) ;
if ( V_163 >= 0 )
F_10 ( V_32 -> V_45 , V_131 -> V_52 + 0x11 ,
V_171 ,
V_171 ) ;
V_165 = F_39 ( & V_131 -> V_134 ,
F_40 ( 25 ) ) ;
if ( V_165 == 0 )
F_41 ( V_131 , L_24 ) ;
return 0 ;
}
int F_42 ( struct V_32 * V_32 , int V_84 , int V_52 , int V_174 ,
int V_175 , struct V_130 * V_131 )
{
int V_165 ;
F_43 ( & V_131 -> V_132 ) ;
F_43 ( & V_131 -> V_134 ) ;
V_131 -> V_84 = V_84 ;
V_131 -> V_52 = V_52 ;
V_131 -> V_32 = V_32 ;
snprintf ( V_131 -> V_176 , sizeof( V_131 -> V_176 ) , L_25 , V_84 ) ;
snprintf ( V_131 -> V_177 , sizeof( V_131 -> V_177 ) ,
L_26 , V_84 ) ;
V_165 = F_44 ( V_32 , V_174 , V_131 -> V_176 ,
F_26 , V_131 ) ;
if ( V_165 != 0 ) {
F_8 ( V_32 -> V_25 , L_27 ,
V_84 , V_165 ) ;
}
V_165 = F_44 ( V_32 , V_175 , V_131 -> V_177 ,
F_29 , V_131 ) ;
if ( V_165 != 0 ) {
F_8 ( V_32 -> V_25 , L_28 ,
V_84 , V_165 ) ;
}
return 0 ;
}
