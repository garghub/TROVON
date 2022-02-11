int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
unsigned int V_6 ;
if ( V_2 -> V_7 % 2 )
V_6 = V_8 + ( ( V_2 -> V_7 / 2 ) * 8 ) ;
else
V_6 = V_9 + ( ( V_2 -> V_7 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_10 :
F_2 ( V_2 -> V_11 , V_6 , V_12 , 0 ) ;
break;
case V_13 :
F_2 ( V_2 -> V_11 , V_6 , V_12 ,
V_12 ) ;
break;
}
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
return 0 ;
}
static int F_4 ( struct V_14 * V_11 , unsigned int V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = F_5 ( V_11 ) ;
unsigned int V_6 ;
unsigned int * V_19 ;
int V_20 , div , V_21 ;
switch ( V_15 ) {
case V_22 :
V_6 = V_23 ;
V_21 = V_18 -> V_24 ;
break;
case V_25 :
V_6 = V_26 ;
V_21 = V_18 -> V_27 ;
break;
default:
return - V_28 ;
}
if ( V_21 % 8000 )
V_19 = V_29 ;
else
V_19 = V_30 ;
for ( V_20 = 0 ; V_20 < F_6 ( V_30 ) &&
V_19 [ V_20 ] <= V_21 ; V_20 ++ ) {
div = 1 ;
while ( V_19 [ V_20 ] / div >= V_16 && div < 32 ) {
if ( V_19 [ V_20 ] / div == V_16 ) {
F_7 ( V_11 -> V_31 , L_1 ,
V_16 ) ;
F_2 ( V_11 , V_6 ,
V_32 |
V_33 ,
( div <<
V_34 ) |
V_20 ) ;
return 0 ;
}
div ++ ;
}
}
F_8 ( V_11 -> V_31 , L_2 , V_16 ) ;
return - V_28 ;
}
int F_9 ( struct V_14 * V_11 , int V_35 ,
int V_36 , unsigned int V_16 , int V_37 )
{
struct V_17 * V_18 = F_5 ( V_11 ) ;
struct V_38 * V_38 = V_18 -> V_38 ;
char * V_39 ;
unsigned int V_6 ;
unsigned int V_40 = V_41 | V_42 ;
unsigned int V_43 = V_36 << V_44 ;
unsigned int * V_15 ;
switch ( V_35 ) {
case V_45 :
V_39 = L_3 ;
V_6 = V_46 ;
V_15 = & V_18 -> V_24 ;
V_40 |= V_47 ;
break;
case V_48 :
V_39 = L_4 ;
V_6 = V_49 ;
V_15 = & V_18 -> V_27 ;
break;
case V_22 :
case V_25 :
return F_4 ( V_11 , V_35 , V_16 ) ;
default:
return - V_28 ;
}
switch ( V_16 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_43 |= 1 << V_50 ;
break;
case 22579200 :
case 24576000 :
V_43 |= 2 << V_50 ;
break;
case 45158400 :
case 49152000 :
V_43 |= 3 << V_50 ;
break;
case 67737600 :
case 73728000 :
V_43 |= 4 << V_50 ;
break;
case 90316800 :
case 98304000 :
V_43 |= 5 << V_50 ;
break;
case 135475200 :
case 147456000 :
V_43 |= 6 << V_50 ;
break;
case 0 :
F_7 ( V_38 -> V_31 , L_5 , V_39 ) ;
* V_15 = V_16 ;
return 0 ;
default:
return - V_28 ;
}
* V_15 = V_16 ;
if ( V_16 % 6144000 )
V_43 |= V_47 ;
F_7 ( V_38 -> V_31 , L_6 , V_39 , V_16 ) ;
return F_10 ( V_38 -> V_51 , V_6 , V_40 , V_43 ) ;
}
static int F_11 ( struct V_52 * V_53 , unsigned int V_54 )
{
struct V_14 * V_11 = V_53 -> V_11 ;
int V_55 , V_56 , V_57 , V_58 ;
V_58 = V_53 -> V_59 -> V_58 ;
V_55 = 0 ;
V_56 = 0 ;
switch ( V_54 & V_60 ) {
case V_61 :
V_57 = 0 ;
break;
case V_62 :
V_57 = 2 ;
break;
default:
F_12 ( V_53 , L_7 ,
V_54 & V_60 ) ;
return - V_28 ;
}
switch ( V_54 & V_63 ) {
case V_64 :
break;
case V_65 :
V_55 |= V_66 ;
break;
case V_67 :
V_56 |= V_68 ;
break;
case V_69 :
V_56 |= V_68 ;
V_55 |= V_66 ;
break;
default:
F_12 ( V_53 , L_8 ,
V_54 & V_63 ) ;
return - V_28 ;
}
switch ( V_54 & V_70 ) {
case V_71 :
break;
case V_72 :
V_56 |= V_73 ;
V_55 |= V_74 ;
break;
case V_75 :
V_56 |= V_73 ;
break;
case V_76 :
V_55 |= V_74 ;
break;
default:
return - V_28 ;
}
F_2 ( V_11 , V_58 + V_77 ,
V_73 | V_68 ,
V_56 ) ;
F_2 ( V_11 , V_58 + V_78 ,
V_74 |
V_66 , V_55 ) ;
F_2 ( V_11 , V_58 + V_79 ,
V_80 |
V_81 , V_55 ) ;
F_2 ( V_11 , V_58 + V_82 ,
V_83 , V_57 ) ;
return 0 ;
}
static int F_13 ( struct V_84 * V_85 ,
struct V_52 * V_53 )
{
struct V_14 * V_11 = V_53 -> V_11 ;
struct V_17 * V_18 = F_5 ( V_11 ) ;
struct V_86 * V_87 = & V_18 -> V_53 [ V_53 -> V_88 - 1 ] ;
const struct V_89 * V_90 ;
unsigned int V_91 ;
switch ( V_87 -> V_15 ) {
case V_45 :
V_91 = V_18 -> V_24 ;
break;
case V_48 :
V_91 = V_18 -> V_27 ;
break;
default:
return 0 ;
}
if ( V_91 == 0 )
return 0 ;
if ( V_91 % 8000 )
V_90 = & V_92 ;
else
V_90 = & V_93 ;
return V_89 ( V_85 -> V_94 , 0 ,
V_95 ,
V_90 ) ;
}
static int F_14 ( struct V_84 * V_85 ,
struct V_96 * V_97 ,
struct V_52 * V_53 )
{
struct V_14 * V_11 = V_53 -> V_11 ;
struct V_17 * V_18 = F_5 ( V_11 ) ;
struct V_86 * V_87 = & V_18 -> V_53 [ V_53 -> V_88 - 1 ] ;
int V_58 = V_53 -> V_59 -> V_58 ;
int V_98 , V_99 ;
for ( V_98 = 0 ; V_98 < F_6 ( V_100 ) ; V_98 ++ )
if ( V_100 [ V_98 ] == F_15 ( V_97 ) )
break;
if ( V_98 == F_6 ( V_100 ) ) {
F_12 ( V_53 , L_9 ,
F_15 ( V_97 ) ) ;
return - V_28 ;
}
V_99 = V_98 ;
switch ( V_87 -> V_15 ) {
case V_45 :
F_2 ( V_11 , V_101 ,
V_102 , V_99 ) ;
if ( V_58 )
F_2 ( V_11 , V_58 + V_103 ,
V_104 , 0 ) ;
break;
case V_48 :
F_2 ( V_11 , V_105 ,
V_106 , V_99 ) ;
if ( V_58 )
F_2 ( V_11 , V_58 + V_103 ,
V_104 ,
8 << V_107 ) ;
break;
default:
F_12 ( V_53 , L_10 , V_87 -> V_15 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_16 ( struct V_84 * V_85 ,
struct V_96 * V_97 ,
struct V_52 * V_53 )
{
struct V_14 * V_11 = V_53 -> V_11 ;
struct V_17 * V_18 = F_5 ( V_11 ) ;
struct V_38 * V_38 = V_18 -> V_38 ;
int V_58 = V_53 -> V_59 -> V_58 ;
const int * V_19 ;
int V_98 , V_108 ;
int V_109 = V_38 -> V_110 . V_111 [ V_53 -> V_88 - 1 ] ;
int V_56 , V_55 , V_112 , V_113 , V_114 ;
if ( F_15 ( V_97 ) % 8000 )
V_19 = & V_115 [ 0 ] ;
else
V_19 = & V_116 [ 0 ] ;
V_114 = F_17 ( V_97 ) ;
if ( V_109 && V_109 < F_18 ( V_97 ) ) {
F_19 ( V_53 , L_11 , V_109 ) ;
V_114 /= F_18 ( V_97 ) ;
V_114 *= V_109 ;
}
for ( V_98 = 0 ; V_98 < F_6 ( V_115 ) ; V_98 ++ ) {
if ( V_19 [ V_98 ] >= V_114 &&
V_19 [ V_98 ] % F_15 ( V_97 ) == 0 ) {
V_56 = V_98 ;
break;
}
}
if ( V_98 == F_6 ( V_115 ) ) {
F_12 ( V_53 , L_9 ,
F_15 ( V_97 ) ) ;
return - V_28 ;
}
V_55 = V_19 [ V_56 ] / F_15 ( V_97 ) ;
F_19 ( V_53 , L_12 ,
V_19 [ V_56 ] , V_19 [ V_56 ] / V_55 ) ;
V_112 = F_20 ( F_21 ( V_97 ) ) ;
V_113 = V_112 << V_117 | V_112 ;
V_108 = F_14 ( V_85 , V_97 , V_53 ) ;
if ( V_108 != 0 )
return V_108 ;
F_2 ( V_11 , V_58 + V_77 ,
V_118 , V_56 ) ;
F_2 ( V_11 , V_58 + V_119 ,
V_120 , V_55 ) ;
F_2 ( V_11 , V_58 + V_121 ,
V_122 , V_55 ) ;
F_2 ( V_11 , V_58 + V_123 ,
V_124 |
V_125 , V_113 ) ;
F_2 ( V_11 , V_58 + V_126 ,
V_127 |
V_128 , V_113 ) ;
return 0 ;
}
static const char * F_22 ( int V_35 )
{
switch ( V_35 ) {
case V_45 :
return L_3 ;
case V_48 :
return L_4 ;
default:
return L_13 ;
}
}
static int F_23 ( struct V_52 * V_53 ,
int V_35 , unsigned int V_16 , int V_37 )
{
struct V_14 * V_11 = V_53 -> V_11 ;
struct V_17 * V_18 = F_5 ( V_11 ) ;
struct V_86 * V_87 = & V_18 -> V_53 [ V_53 -> V_88 - 1 ] ;
struct V_129 V_130 [ 2 ] ;
switch ( V_35 ) {
case V_45 :
case V_48 :
break;
default:
return - V_28 ;
}
if ( V_35 == V_87 -> V_15 )
return 0 ;
if ( V_53 -> V_131 ) {
F_8 ( V_11 -> V_31 , L_14 ,
V_53 -> V_88 ) ;
return - V_132 ;
}
F_7 ( V_11 -> V_31 , L_15 , V_53 -> V_88 + 1 ,
F_22 ( V_35 ) ) ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_130 [ 0 ] . V_133 = V_53 -> V_59 -> V_134 . V_135 ;
V_130 [ 1 ] . V_133 = V_53 -> V_59 -> V_136 . V_135 ;
V_130 [ 0 ] . V_36 = F_22 ( V_87 -> V_15 ) ;
V_130 [ 1 ] . V_36 = F_22 ( V_87 -> V_15 ) ;
F_24 ( & V_11 -> V_137 , V_130 , F_6 ( V_130 ) ) ;
V_130 [ 0 ] . V_36 = F_22 ( V_35 ) ;
V_130 [ 1 ] . V_36 = F_22 ( V_35 ) ;
F_25 ( & V_11 -> V_137 , V_130 , F_6 ( V_130 ) ) ;
V_87 -> V_15 = V_35 ;
return F_26 ( & V_11 -> V_137 ) ;
}
static int F_27 ( struct V_52 * V_53 , int V_138 )
{
struct V_14 * V_11 = V_53 -> V_11 ;
int V_58 = V_53 -> V_59 -> V_58 ;
unsigned int V_6 ;
if ( V_138 )
V_6 = V_139 ;
else
V_6 = 0 ;
return F_2 ( V_11 , V_58 + V_103 ,
V_139 , V_6 ) ;
}
int F_28 ( struct V_17 * V_18 , int V_88 )
{
struct V_86 * V_87 = & V_18 -> V_53 [ V_88 ] ;
V_87 -> V_15 = V_45 ;
return 0 ;
}
static T_1 F_29 ( int V_140 , void * V_141 )
{
struct V_142 * V_143 = V_141 ;
F_30 ( V_143 , L_16 ) ;
F_31 ( & V_143 -> V_144 ) ;
return V_145 ;
}
static int F_32 ( struct V_142 * V_143 ,
struct V_146 * V_147 ,
unsigned int V_148 ,
unsigned int V_149 )
{
unsigned int V_150 , div , V_151 ;
int V_98 , V_152 ;
F_30 ( V_143 , L_17 , V_148 , V_149 ) ;
div = 1 ;
V_147 -> V_153 = 0 ;
while ( ( V_148 / div ) > 13500000 ) {
div *= 2 ;
V_147 -> V_153 ++ ;
if ( div > 8 ) {
F_33 ( V_143 ,
L_18 ,
V_148 ) ;
return - V_28 ;
}
}
V_148 /= div ;
div = 1 ;
while ( V_149 * div < 90000000 * V_143 -> V_154 ) {
div ++ ;
if ( div > 7 ) {
F_33 ( V_143 , L_19 ,
V_149 ) ;
return - V_28 ;
}
}
V_150 = V_149 * div / V_143 -> V_154 ;
V_147 -> V_155 = div ;
F_30 ( V_143 , L_20 , V_150 ) ;
for ( V_98 = 0 ; V_98 < F_6 ( V_156 ) ; V_98 ++ ) {
if ( V_156 [ V_98 ] . V_157 <= V_148 && V_148 <= V_156 [ V_98 ] . V_158 ) {
V_147 -> V_159 = V_156 [ V_98 ] . V_159 ;
V_152 = V_156 [ V_98 ] . V_152 ;
break;
}
}
if ( V_98 == F_6 ( V_156 ) ) {
F_33 ( V_143 , L_21 ,
V_148 ) ;
return - V_28 ;
}
V_147 -> V_160 = V_150 / ( V_152 * V_148 ) ;
if ( V_150 % ( V_152 * V_148 ) ) {
V_151 = F_34 ( V_150 , V_152 * V_148 ) ;
F_30 ( V_143 , L_22 , V_151 ) ;
V_147 -> V_161 = ( V_150 - ( V_147 -> V_160 * V_152 * V_148 ) )
/ V_151 ;
V_147 -> V_162 = ( V_152 * V_148 ) / V_151 ;
} else {
V_147 -> V_161 = 0 ;
V_147 -> V_162 = 0 ;
}
while ( V_147 -> V_162 >= ( 1 << 16 ) ) {
V_147 -> V_161 >>= 1 ;
V_147 -> V_162 >>= 1 ;
}
F_30 ( V_143 , L_23 ,
V_147 -> V_160 , V_147 -> V_161 , V_147 -> V_162 ) ;
F_30 ( V_143 , L_24 ,
V_147 -> V_159 , V_147 -> V_159 , V_147 -> V_155 , V_147 -> V_153 ) ;
return 0 ;
}
static void F_35 ( struct V_38 * V_38 , unsigned int V_58 ,
struct V_146 * V_147 , int V_36 )
{
F_10 ( V_38 -> V_51 , V_58 + 3 ,
V_163 , V_147 -> V_161 ) ;
F_10 ( V_38 -> V_51 , V_58 + 4 ,
V_164 , V_147 -> V_162 ) ;
F_10 ( V_38 -> V_51 , V_58 + 5 ,
V_165 ,
V_147 -> V_159 << V_166 ) ;
F_10 ( V_38 -> V_51 , V_58 + 6 ,
V_167 |
V_168 ,
V_147 -> V_153 << V_169 |
V_36 << V_170 ) ;
F_10 ( V_38 -> V_51 , V_58 + 2 ,
V_171 | V_172 ,
V_171 | V_147 -> V_160 ) ;
}
int F_36 ( struct V_142 * V_143 , int V_36 ,
unsigned int V_148 , unsigned int V_149 )
{
struct V_38 * V_38 = V_143 -> V_38 ;
struct V_146 V_147 , V_173 ;
unsigned int V_6 , V_43 ;
int V_174 ;
bool V_175 ;
int V_108 ;
if ( V_143 -> V_176 == V_148 && V_143 -> V_177 == V_149 )
return 0 ;
V_108 = F_37 ( V_38 -> V_51 , V_143 -> V_58 + 1 , & V_6 ) ;
if ( V_108 != 0 ) {
F_33 ( V_143 , L_25 ,
V_108 ) ;
return V_108 ;
}
V_175 = V_6 & V_178 ;
if ( V_149 ) {
F_37 ( V_38 -> V_51 , V_179 , & V_43 ) ;
switch ( V_43 & V_180 ) {
case V_181 :
case V_182 :
V_174 = V_43 & V_180 ;
break;
default:
V_174 = - 1 ;
}
if ( V_36 == V_174 )
V_174 = - 1 ;
if ( V_174 >= 0 ) {
V_108 = F_32 ( V_143 , & V_173 , V_148 , V_149 ) ;
if ( V_108 != 0 )
return V_108 ;
V_108 = F_32 ( V_143 , & V_147 , 32768 , V_149 ) ;
if ( V_108 != 0 )
return V_108 ;
} else {
V_108 = F_32 ( V_143 , & V_147 , V_148 , V_149 ) ;
if ( V_108 != 0 )
return V_108 ;
}
} else {
F_10 ( V_38 -> V_51 , V_143 -> V_58 + 1 ,
V_178 , 0 ) ;
F_10 ( V_38 -> V_51 , V_143 -> V_58 + 0x11 ,
V_183 , 0 ) ;
if ( V_175 )
F_38 ( V_38 -> V_31 ) ;
V_143 -> V_176 = V_148 ;
V_143 -> V_177 = V_149 ;
return 0 ;
}
F_10 ( V_38 -> V_51 , V_143 -> V_58 + 5 ,
V_184 ,
V_147 . V_155 << V_185 ) ;
if ( V_174 >= 0 ) {
F_35 ( V_38 , V_143 -> V_58 , & V_147 , V_174 ) ;
F_35 ( V_38 , V_143 -> V_58 + 0x10 , & V_173 , V_36 ) ;
} else {
F_35 ( V_38 , V_143 -> V_58 , & V_147 , V_36 ) ;
}
if ( ! V_175 )
F_39 ( V_38 -> V_31 ) ;
F_40 ( & V_143 -> V_144 ) ;
F_10 ( V_38 -> V_51 , V_143 -> V_58 + 1 ,
V_178 , V_178 ) ;
if ( V_174 >= 0 )
F_10 ( V_38 -> V_51 , V_143 -> V_58 + 0x11 ,
V_183 ,
V_183 ) ;
V_108 = F_41 ( & V_143 -> V_144 ,
F_42 ( 250 ) ) ;
if ( V_108 == 0 )
F_43 ( V_143 , L_26 ) ;
V_143 -> V_176 = V_148 ;
V_143 -> V_177 = V_149 ;
return 0 ;
}
int F_44 ( struct V_38 * V_38 , int V_88 , int V_58 , int V_186 ,
int V_187 , struct V_142 * V_143 )
{
int V_108 ;
F_45 ( & V_143 -> V_144 ) ;
V_143 -> V_88 = V_88 ;
V_143 -> V_58 = V_58 ;
V_143 -> V_38 = V_38 ;
snprintf ( V_143 -> V_188 , sizeof( V_143 -> V_188 ) , L_27 , V_88 ) ;
snprintf ( V_143 -> V_189 , sizeof( V_143 -> V_189 ) ,
L_28 , V_88 ) ;
V_108 = F_46 ( V_38 , V_187 , V_143 -> V_189 ,
F_29 , V_143 ) ;
if ( V_108 != 0 ) {
F_8 ( V_38 -> V_31 , L_29 ,
V_88 , V_108 ) ;
}
F_10 ( V_38 -> V_51 , V_143 -> V_58 + 1 ,
V_190 , 0 ) ;
return 0 ;
}
int F_47 ( struct V_14 * V_11 , int V_191 , bool V_192 )
{
unsigned int V_6 , V_43 ;
if ( V_191 < 1 || V_191 > 6 )
return - V_28 ;
V_6 = V_193 + ( V_191 - 1 ) * 8 ;
if ( V_192 )
V_43 = V_194 ;
else
V_43 = 0 ;
return F_2 ( V_11 , V_6 , V_194 , V_43 ) ;
}
