static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
bool V_13 = false ;
int V_14 ;
switch ( V_8 -> type ) {
case V_15 :
switch ( V_8 -> V_16 ) {
case 0 :
break;
default:
V_13 = true ;
break;
}
default:
break;
}
switch ( V_5 ) {
case V_17 :
if ( ! V_12 -> V_18 && V_13 ) {
F_4 ( V_7 , 0x4f5 , 0x25a ) ;
V_12 -> V_19 = true ;
}
break;
case V_20 :
V_14 = F_5 ( V_7 , V_21 ) ;
if ( V_14 & V_22 ) {
F_6 ( V_8 -> V_9 ,
L_1 ) ;
return - V_23 ;
}
F_7 ( V_7 , V_24 ,
1 << V_2 -> V_25 , 1 << V_2 -> V_25 ) ;
if ( V_12 -> V_19 ) {
F_8 ( 75 ) ;
F_4 ( V_7 , 0x4f5 , 0xda ) ;
V_12 -> V_19 = false ;
V_12 -> V_18 ++ ;
}
break;
case V_26 :
if ( V_13 ) {
V_12 -> V_18 -- ;
if ( ! V_12 -> V_18 )
F_4 ( V_7 , 0x4f5 , 0x25a ) ;
}
F_7 ( V_7 , V_24 ,
1 << V_2 -> V_25 , 0 ) ;
break;
case V_27 :
if ( V_13 ) {
if ( ! V_12 -> V_18 )
F_4 ( V_7 , 0x4f5 , 0x0da ) ;
}
break;
}
return 0 ;
}
static T_1 F_9 ( int V_28 , void * V_29 )
{
struct V_8 * V_8 = V_29 ;
unsigned int V_14 ;
int V_30 ;
V_30 = F_10 ( V_8 -> V_31 , V_21 ,
& V_14 ) ;
if ( V_30 != 0 ) {
F_11 ( V_8 -> V_9 , L_2 ,
V_30 ) ;
} else if ( V_14 & V_32 ) {
F_6 ( V_8 -> V_9 , L_3 ) ;
}
return V_33 ;
}
static T_1 F_12 ( int V_28 , void * V_29 )
{
struct V_8 * V_8 = V_29 ;
unsigned int V_14 ;
int V_30 ;
V_30 = F_10 ( V_8 -> V_31 , V_21 ,
& V_14 ) ;
if ( V_30 != 0 ) {
F_11 ( V_8 -> V_9 , L_2 ,
V_30 ) ;
} else if ( V_14 & V_22 ) {
F_6 ( V_8 -> V_9 , L_4 ) ;
V_30 = F_13 ( V_8 -> V_31 ,
V_24 ,
V_34 |
V_35 , 0 ) ;
if ( V_30 != 0 )
F_6 ( V_8 -> V_9 ,
L_5 ,
V_30 ) ;
}
return V_33 ;
}
int F_14 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_30 ;
V_30 = F_15 ( & V_7 -> V_36 , & V_37 , 1 ) ;
if ( V_30 != 0 )
return V_30 ;
V_30 = F_15 ( & V_7 -> V_36 , & V_38 , 1 ) ;
if ( V_30 != 0 )
return V_30 ;
V_30 = F_16 ( V_8 , V_39 ,
L_6 , F_9 ,
V_8 ) ;
if ( V_30 != 0 )
F_11 ( V_8 -> V_9 ,
L_7 ,
V_30 ) ;
V_30 = F_16 ( V_8 , V_40 ,
L_8 , F_12 ,
V_8 ) ;
if ( V_30 != 0 )
F_11 ( V_8 -> V_9 ,
L_9 ,
V_30 ) ;
return 0 ;
}
static void F_17 ( struct V_6 * V_7 , int V_41 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
unsigned int V_14 ;
int V_42 ;
if ( V_41 )
V_14 = V_43 ;
else
V_14 = 0 ;
for ( V_42 = 0 ; V_42 < V_12 -> V_44 ; V_42 ++ )
F_7 ( V_7 ,
V_45 + ( V_42 * 4 ) ,
V_43 , V_14 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_7 ) ;
unsigned int V_46 ;
if ( V_2 -> V_25 % 2 )
V_46 = V_45 + ( ( V_2 -> V_25 / 2 ) * 8 ) ;
else
V_46 = V_47 + ( ( V_2 -> V_25 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_17 :
V_12 -> V_48 ++ ;
break;
case V_20 :
F_7 ( V_2 -> V_7 , V_46 , V_49 , 0 ) ;
V_12 -> V_48 -- ;
if ( V_12 -> V_48 == 0 ) {
F_8 ( 1 ) ;
F_17 ( V_2 -> V_7 , 1 ) ;
}
break;
case V_26 :
F_7 ( V_2 -> V_7 , V_46 ,
V_49 | V_43 ,
V_49 | V_43 ) ;
break;
case V_27 :
V_46 = F_5 ( V_2 -> V_7 , V_50 ) ;
if ( V_46 == 0 )
F_17 ( V_2 -> V_7 , 0 ) ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
switch ( V_5 ) {
case V_20 :
switch ( V_2 -> V_25 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
F_8 ( 17 ) ;
break;
default:
break;
}
break;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_7 ) ;
unsigned int V_57 = 1 << V_2 -> V_25 ;
unsigned int V_14 ;
switch ( V_5 ) {
case V_20 :
V_14 = V_57 ;
break;
case V_26 :
V_14 = 0 ;
break;
default:
return - V_58 ;
}
V_12 -> V_8 -> V_59 &= ~ V_57 ;
V_12 -> V_8 -> V_59 |= V_14 ;
if ( V_12 -> V_8 -> V_60 )
V_14 = 0 ;
F_7 ( V_2 -> V_7 , V_24 , V_57 , V_14 ) ;
return F_19 ( V_2 , V_4 , V_5 ) ;
}
static int F_21 ( struct V_6 * V_7 , unsigned int V_61 ,
unsigned int V_62 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
unsigned int V_46 ;
unsigned int * V_63 ;
int V_64 , div , V_65 ;
switch ( V_61 ) {
case V_66 :
V_46 = V_67 ;
V_65 = V_12 -> V_68 ;
break;
case V_69 :
V_46 = V_70 ;
V_65 = V_12 -> V_71 ;
break;
default:
return - V_58 ;
}
if ( V_65 % 8000 )
V_63 = V_72 ;
else
V_63 = V_73 ;
for ( V_64 = 0 ; V_64 < F_22 ( V_73 ) &&
V_63 [ V_64 ] <= V_65 ; V_64 ++ ) {
div = 1 ;
while ( V_63 [ V_64 ] / div >= V_62 && div < 32 ) {
if ( V_63 [ V_64 ] / div == V_62 ) {
F_23 ( V_7 -> V_9 , L_10 ,
V_62 ) ;
F_7 ( V_7 , V_46 ,
V_74 |
V_75 ,
( div <<
V_76 ) |
V_64 ) ;
return 0 ;
}
div ++ ;
}
}
F_11 ( V_7 -> V_9 , L_11 , V_62 ) ;
return - V_58 ;
}
int F_24 ( struct V_6 * V_7 , int V_77 ,
int V_78 , unsigned int V_62 , int V_79 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
char * V_80 ;
unsigned int V_46 ;
unsigned int V_57 = V_81 | V_82 ;
unsigned int V_14 = V_78 << V_83 ;
unsigned int * V_61 ;
switch ( V_77 ) {
case V_84 :
V_80 = L_12 ;
V_46 = V_85 ;
V_61 = & V_12 -> V_68 ;
V_57 |= V_86 ;
break;
case V_87 :
V_80 = L_13 ;
V_46 = V_88 ;
V_61 = & V_12 -> V_71 ;
break;
case V_66 :
case V_69 :
return F_21 ( V_7 , V_77 , V_62 ) ;
default:
return - V_58 ;
}
switch ( V_62 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_14 |= V_89 << V_90 ;
break;
case 22579200 :
case 24576000 :
V_14 |= V_91 << V_90 ;
break;
case 45158400 :
case 49152000 :
V_14 |= V_92 << V_90 ;
break;
case 67737600 :
case 73728000 :
V_14 |= V_93 << V_90 ;
break;
case 90316800 :
case 98304000 :
V_14 |= V_94 << V_90 ;
break;
case 135475200 :
case 147456000 :
V_14 |= V_95 << V_90 ;
break;
case 0 :
F_23 ( V_8 -> V_9 , L_14 , V_80 ) ;
* V_61 = V_62 ;
return 0 ;
default:
return - V_58 ;
}
* V_61 = V_62 ;
if ( V_62 % 6144000 )
V_14 |= V_86 ;
F_23 ( V_8 -> V_9 , L_15 , V_80 , V_62 ) ;
return F_13 ( V_8 -> V_31 , V_46 , V_57 , V_14 ) ;
}
static int F_25 ( struct V_96 * V_97 , unsigned int V_98 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
int V_99 , V_100 , V_101 , V_102 ;
V_102 = V_97 -> V_103 -> V_102 ;
V_99 = 0 ;
V_100 = 0 ;
switch ( V_98 & V_104 ) {
case V_105 :
V_101 = 0 ;
break;
case V_106 :
V_101 = 2 ;
break;
default:
F_26 ( V_97 , L_16 ,
V_98 & V_104 ) ;
return - V_58 ;
}
switch ( V_98 & V_107 ) {
case V_108 :
break;
case V_109 :
V_99 |= V_110 ;
break;
case V_111 :
V_100 |= V_112 ;
break;
case V_113 :
V_100 |= V_112 ;
V_99 |= V_110 ;
break;
default:
F_26 ( V_97 , L_17 ,
V_98 & V_107 ) ;
return - V_58 ;
}
switch ( V_98 & V_114 ) {
case V_115 :
break;
case V_116 :
V_100 |= V_117 ;
V_99 |= V_118 ;
break;
case V_119 :
V_100 |= V_117 ;
break;
case V_120 :
V_99 |= V_118 ;
break;
default:
return - V_58 ;
}
F_7 ( V_7 , V_102 + V_121 ,
V_117 | V_112 ,
V_100 ) ;
F_7 ( V_7 , V_102 + V_122 ,
V_118 |
V_110 , V_99 ) ;
F_7 ( V_7 , V_102 + V_123 ,
V_124 |
V_125 , V_99 ) ;
F_7 ( V_7 , V_102 + V_126 ,
V_127 , V_101 ) ;
return 0 ;
}
static int F_27 ( struct V_128 * V_129 ,
struct V_96 * V_97 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_130 * V_131 = & V_12 -> V_97 [ V_97 -> V_132 - 1 ] ;
const struct V_133 * V_134 ;
unsigned int V_135 ;
switch ( V_131 -> V_61 ) {
case V_84 :
V_135 = V_12 -> V_68 ;
break;
case V_87 :
V_135 = V_12 -> V_71 ;
break;
default:
return 0 ;
}
if ( V_135 == 0 )
return 0 ;
if ( V_135 % 8000 )
V_134 = & V_136 ;
else
V_134 = & V_137 ;
return V_133 ( V_129 -> V_138 , 0 ,
V_139 ,
V_134 ) ;
}
static int F_28 ( struct V_128 * V_129 ,
struct V_140 * V_141 ,
struct V_96 * V_97 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_130 * V_131 = & V_12 -> V_97 [ V_97 -> V_132 - 1 ] ;
int V_102 = V_97 -> V_103 -> V_102 ;
int V_42 , V_142 ;
for ( V_42 = 0 ; V_42 < F_22 ( V_143 ) ; V_42 ++ )
if ( V_143 [ V_42 ] == F_29 ( V_141 ) )
break;
if ( V_42 == F_22 ( V_143 ) ) {
F_26 ( V_97 , L_18 ,
F_29 ( V_141 ) ) ;
return - V_58 ;
}
V_142 = V_42 ;
switch ( V_131 -> V_61 ) {
case V_84 :
F_7 ( V_7 , V_144 ,
V_145 , V_142 ) ;
if ( V_102 )
F_7 ( V_7 , V_102 + V_146 ,
V_147 , 0 ) ;
break;
case V_87 :
F_7 ( V_7 , V_148 ,
V_149 , V_142 ) ;
if ( V_102 )
F_7 ( V_7 , V_102 + V_146 ,
V_147 ,
8 << V_150 ) ;
break;
default:
F_26 ( V_97 , L_19 , V_131 -> V_61 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_30 ( struct V_128 * V_129 ,
struct V_140 * V_141 ,
struct V_96 * V_97 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_102 = V_97 -> V_103 -> V_102 ;
const int * V_63 ;
int V_42 , V_30 , V_14 ;
int V_151 = V_8 -> V_152 . V_153 [ V_97 -> V_132 - 1 ] ;
int V_100 , V_99 , V_154 , V_155 , V_156 ;
if ( F_29 ( V_141 ) % 8000 )
V_63 = & V_157 [ 0 ] ;
else
V_63 = & V_158 [ 0 ] ;
V_156 = F_31 ( V_141 ) ;
if ( V_151 && V_151 < F_32 ( V_141 ) ) {
F_33 ( V_97 , L_20 , V_151 ) ;
V_156 /= F_32 ( V_141 ) ;
V_156 *= V_151 ;
}
V_14 = F_5 ( V_7 , V_102 + V_126 ) ;
if ( F_32 ( V_141 ) == 1 && ( V_14 & V_127 ) ) {
F_33 ( V_97 , L_21 ) ;
V_156 *= 2 ;
}
for ( V_42 = 0 ; V_42 < F_22 ( V_157 ) ; V_42 ++ ) {
if ( V_63 [ V_42 ] >= V_156 &&
V_63 [ V_42 ] % F_29 ( V_141 ) == 0 ) {
V_100 = V_42 ;
break;
}
}
if ( V_42 == F_22 ( V_157 ) ) {
F_26 ( V_97 , L_18 ,
F_29 ( V_141 ) ) ;
return - V_58 ;
}
V_99 = V_63 [ V_100 ] / F_29 ( V_141 ) ;
F_33 ( V_97 , L_22 ,
V_63 [ V_100 ] , V_63 [ V_100 ] / V_99 ) ;
V_154 = F_34 ( F_35 ( V_141 ) ) ;
V_155 = V_154 << V_159 | V_154 ;
V_30 = F_28 ( V_129 , V_141 , V_97 ) ;
if ( V_30 != 0 )
return V_30 ;
F_7 ( V_7 , V_102 + V_121 ,
V_160 , V_100 ) ;
F_7 ( V_7 , V_102 + V_161 ,
V_162 , V_99 ) ;
F_7 ( V_7 , V_102 + V_163 ,
V_164 , V_99 ) ;
F_7 ( V_7 , V_102 + V_165 ,
V_166 |
V_167 , V_155 ) ;
F_7 ( V_7 , V_102 + V_168 ,
V_169 |
V_170 , V_155 ) ;
return 0 ;
}
static const char * F_36 ( int V_77 )
{
switch ( V_77 ) {
case V_84 :
return L_12 ;
case V_87 :
return L_13 ;
default:
return L_23 ;
}
}
static int F_37 ( struct V_96 * V_97 ,
int V_77 , unsigned int V_62 , int V_79 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_130 * V_131 = & V_12 -> V_97 [ V_97 -> V_132 - 1 ] ;
struct V_171 V_172 [ 2 ] ;
switch ( V_77 ) {
case V_84 :
case V_87 :
break;
default:
return - V_58 ;
}
if ( V_77 == V_131 -> V_61 )
return 0 ;
if ( V_97 -> V_173 ) {
F_11 ( V_7 -> V_9 , L_24 ,
V_97 -> V_132 ) ;
return - V_23 ;
}
F_23 ( V_7 -> V_9 , L_25 , V_97 -> V_132 + 1 ,
F_36 ( V_77 ) ) ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_172 [ 0 ] . V_174 = V_97 -> V_103 -> V_175 . V_176 ;
V_172 [ 1 ] . V_174 = V_97 -> V_103 -> V_177 . V_176 ;
V_172 [ 0 ] . V_78 = F_36 ( V_131 -> V_61 ) ;
V_172 [ 1 ] . V_78 = F_36 ( V_131 -> V_61 ) ;
F_38 ( & V_7 -> V_36 , V_172 , F_22 ( V_172 ) ) ;
V_172 [ 0 ] . V_78 = F_36 ( V_77 ) ;
V_172 [ 1 ] . V_78 = F_36 ( V_77 ) ;
F_39 ( & V_7 -> V_36 , V_172 , F_22 ( V_172 ) ) ;
V_131 -> V_61 = V_77 ;
return F_40 ( & V_7 -> V_36 ) ;
}
static int F_41 ( struct V_96 * V_97 , int V_178 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
int V_102 = V_97 -> V_103 -> V_102 ;
unsigned int V_46 ;
if ( V_178 )
V_46 = V_179 ;
else
V_46 = 0 ;
return F_7 ( V_7 , V_102 + V_146 ,
V_179 , V_46 ) ;
}
int F_42 ( struct V_11 * V_12 , int V_132 )
{
struct V_130 * V_131 = & V_12 -> V_97 [ V_132 ] ;
V_131 -> V_61 = V_84 ;
return 0 ;
}
static T_1 F_43 ( int V_28 , void * V_29 )
{
struct V_180 * V_181 = V_29 ;
F_44 ( V_181 , L_26 ) ;
F_45 ( & V_181 -> V_182 ) ;
return V_33 ;
}
static int F_46 ( struct V_180 * V_181 ,
struct V_183 * V_184 ,
unsigned int V_185 ,
unsigned int V_186 )
{
unsigned int V_187 , div , V_188 ;
int V_42 , V_189 ;
F_44 ( V_181 , L_27 , V_185 , V_186 ) ;
div = 1 ;
V_184 -> V_190 = 0 ;
while ( ( V_185 / div ) > 13500000 ) {
div *= 2 ;
V_184 -> V_190 ++ ;
if ( div > 8 ) {
F_47 ( V_181 ,
L_28 ,
V_185 ) ;
return - V_58 ;
}
}
V_185 /= div ;
div = 1 ;
while ( V_186 * div < 90000000 * V_181 -> V_191 ) {
div ++ ;
if ( div > 7 ) {
F_47 ( V_181 , L_29 ,
V_186 ) ;
return - V_58 ;
}
}
V_187 = V_186 * div / V_181 -> V_191 ;
V_184 -> V_192 = div ;
F_44 ( V_181 , L_30 , V_187 ) ;
for ( V_42 = 0 ; V_42 < F_22 ( V_193 ) ; V_42 ++ ) {
if ( V_193 [ V_42 ] . V_194 <= V_185 && V_185 <= V_193 [ V_42 ] . V_195 ) {
V_184 -> V_196 = V_193 [ V_42 ] . V_196 ;
V_189 = V_193 [ V_42 ] . V_189 ;
break;
}
}
if ( V_42 == F_22 ( V_193 ) ) {
F_47 ( V_181 , L_31 ,
V_185 ) ;
return - V_58 ;
}
for ( V_42 = 0 ; V_42 < F_22 ( V_197 ) ; V_42 ++ ) {
if ( V_197 [ V_42 ] . V_194 <= V_185 && V_185 <= V_197 [ V_42 ] . V_195 ) {
V_184 -> V_198 = V_197 [ V_42 ] . V_198 ;
break;
}
}
if ( V_42 == F_22 ( V_197 ) ) {
F_47 ( V_181 , L_32 ,
V_185 ) ;
return - V_58 ;
}
V_184 -> V_199 = V_187 / ( V_189 * V_185 ) ;
if ( V_187 % ( V_189 * V_185 ) ) {
V_188 = F_48 ( V_187 , V_189 * V_185 ) ;
F_44 ( V_181 , L_33 , V_188 ) ;
V_184 -> V_200 = ( V_187 - ( V_184 -> V_199 * V_189 * V_185 ) )
/ V_188 ;
V_184 -> V_201 = ( V_189 * V_185 ) / V_188 ;
} else {
V_184 -> V_200 = 0 ;
V_184 -> V_201 = 0 ;
}
while ( V_184 -> V_201 >= ( 1 << 16 ) ) {
V_184 -> V_200 >>= 1 ;
V_184 -> V_201 >>= 1 ;
}
F_44 ( V_181 , L_34 ,
V_184 -> V_199 , V_184 -> V_200 , V_184 -> V_201 ) ;
F_44 ( V_181 , L_35 ,
V_184 -> V_196 , V_184 -> V_196 , V_184 -> V_192 , V_184 -> V_190 ) ;
F_44 ( V_181 , L_36 , V_184 -> V_198 ) ;
return 0 ;
}
static void F_49 ( struct V_8 * V_8 , unsigned int V_102 ,
struct V_183 * V_184 , int V_78 ,
bool V_202 )
{
F_13 ( V_8 -> V_31 , V_102 + 3 ,
V_203 , V_184 -> V_200 ) ;
F_13 ( V_8 -> V_31 , V_102 + 4 ,
V_204 , V_184 -> V_201 ) ;
F_13 ( V_8 -> V_31 , V_102 + 5 ,
V_205 ,
V_184 -> V_196 << V_206 ) ;
F_13 ( V_8 -> V_31 , V_102 + 6 ,
V_207 |
V_208 ,
V_184 -> V_190 << V_209 |
V_78 << V_210 ) ;
if ( V_202 )
F_13 ( V_8 -> V_31 , V_102 + 0x7 ,
V_211 ,
V_184 -> V_198 << V_212 ) ;
else
F_13 ( V_8 -> V_31 , V_102 + 0x9 ,
V_211 ,
V_184 -> V_198 << V_212 ) ;
F_13 ( V_8 -> V_31 , V_102 + 2 ,
V_213 | V_214 ,
V_213 | V_184 -> V_199 ) ;
}
static bool F_50 ( struct V_180 * V_181 )
{
struct V_8 * V_8 = V_181 -> V_8 ;
unsigned int V_46 ;
int V_30 ;
V_30 = F_10 ( V_8 -> V_31 , V_181 -> V_102 + 1 , & V_46 ) ;
if ( V_30 != 0 ) {
F_47 ( V_181 , L_37 ,
V_30 ) ;
return V_30 ;
}
return V_46 & V_215 ;
}
static void F_51 ( struct V_180 * V_181 ,
struct V_183 * V_64 ,
struct V_183 * V_202 )
{
struct V_8 * V_8 = V_181 -> V_8 ;
int V_30 ;
if ( V_181 -> V_216 >= 0 && V_181 -> V_216 != V_181 -> V_217 ) {
F_13 ( V_8 -> V_31 , V_181 -> V_102 + 5 ,
V_218 ,
V_64 -> V_192 << V_219 ) ;
F_49 ( V_8 , V_181 -> V_102 , V_64 , V_181 -> V_216 ,
false ) ;
if ( V_181 -> V_217 >= 0 )
F_49 ( V_8 , V_181 -> V_102 + 0x10 , V_202 ,
V_181 -> V_217 , true ) ;
} else if ( V_181 -> V_217 >= 0 ) {
F_13 ( V_8 -> V_31 , V_181 -> V_102 + 5 ,
V_218 ,
V_202 -> V_192 << V_219 ) ;
F_49 ( V_8 , V_181 -> V_102 , V_202 ,
V_181 -> V_217 , false ) ;
F_13 ( V_8 -> V_31 , V_181 -> V_102 + 0x11 ,
V_220 , 0 ) ;
} else {
F_47 ( V_181 , L_38 ) ;
return;
}
if ( V_181 -> V_217 >= 0 && V_181 -> V_221 > 100000 )
F_13 ( V_8 -> V_31 , V_181 -> V_102 + 0x17 ,
V_222 , 0 ) ;
else
F_13 ( V_8 -> V_31 , V_181 -> V_102 + 0x17 ,
V_222 , V_222 ) ;
if ( ! F_50 ( V_181 ) )
F_52 ( V_8 -> V_9 ) ;
F_53 ( & V_181 -> V_182 ) ;
F_13 ( V_8 -> V_31 , V_181 -> V_102 + 1 ,
V_215 , V_215 ) ;
if ( V_181 -> V_216 >= 0 && V_181 -> V_217 >= 0 &&
V_181 -> V_216 != V_181 -> V_217 )
F_13 ( V_8 -> V_31 , V_181 -> V_102 + 0x11 ,
V_220 ,
V_220 ) ;
V_30 = F_54 ( & V_181 -> V_182 ,
F_55 ( 250 ) ) ;
if ( V_30 == 0 )
F_56 ( V_181 , L_39 ) ;
}
static void F_57 ( struct V_180 * V_181 )
{
struct V_8 * V_8 = V_181 -> V_8 ;
bool V_223 ;
F_58 ( V_8 -> V_31 , V_181 -> V_102 + 1 ,
V_215 , 0 , & V_223 ) ;
F_13 ( V_8 -> V_31 , V_181 -> V_102 + 0x11 ,
V_220 , 0 ) ;
if ( V_223 )
F_59 ( V_8 -> V_9 ) ;
}
int F_60 ( struct V_180 * V_181 , int V_78 ,
unsigned int V_185 , unsigned int V_186 )
{
struct V_183 V_64 , V_202 ;
int V_30 ;
if ( V_181 -> V_216 == V_78 && V_181 -> V_224 == V_185 )
return 0 ;
if ( V_181 -> V_225 && V_185 > 0 ) {
V_30 = F_46 ( V_181 , & V_64 , V_185 , V_181 -> V_225 ) ;
if ( V_30 != 0 )
return V_30 ;
if ( V_181 -> V_217 >= 0 ) {
V_30 = F_46 ( V_181 , & V_202 , V_181 -> V_221 ,
V_181 -> V_225 ) ;
if ( V_30 != 0 )
return V_30 ;
}
}
V_181 -> V_216 = V_78 ;
V_181 -> V_224 = V_185 ;
if ( V_181 -> V_225 && V_185 > 0 ) {
F_51 ( V_181 , & V_64 , & V_202 ) ;
}
return 0 ;
}
int F_61 ( struct V_180 * V_181 , int V_78 ,
unsigned int V_185 , unsigned int V_186 )
{
struct V_183 V_64 , V_202 ;
int V_30 ;
if ( V_181 -> V_217 == V_78 &&
V_181 -> V_221 == V_185 && V_181 -> V_225 == V_186 )
return 0 ;
if ( V_186 ) {
if ( V_181 -> V_216 >= 0 ) {
V_30 = F_46 ( V_181 , & V_64 , V_181 -> V_224 ,
V_186 ) ;
if ( V_30 != 0 )
return V_30 ;
}
V_30 = F_46 ( V_181 , & V_202 , V_185 , V_186 ) ;
if ( V_30 != 0 )
return V_30 ;
}
V_181 -> V_217 = V_78 ;
V_181 -> V_221 = V_185 ;
V_181 -> V_225 = V_186 ;
if ( V_186 ) {
F_51 ( V_181 , & V_64 , & V_202 ) ;
} else {
F_57 ( V_181 ) ;
}
return 0 ;
}
int F_62 ( struct V_8 * V_8 , int V_132 , int V_102 , int V_226 ,
int V_227 , struct V_180 * V_181 )
{
int V_30 ;
unsigned int V_14 ;
F_63 ( & V_181 -> V_182 ) ;
V_181 -> V_132 = V_132 ;
V_181 -> V_102 = V_102 ;
V_181 -> V_8 = V_8 ;
V_181 -> V_217 = V_228 ;
F_10 ( V_8 -> V_31 , V_229 , & V_14 ) ;
switch ( V_14 & V_230 ) {
case V_231 :
case V_232 :
V_181 -> V_216 = V_14 & V_230 ;
break;
default:
V_181 -> V_216 = V_228 ;
}
V_181 -> V_224 = 32768 ;
snprintf ( V_181 -> V_233 , sizeof( V_181 -> V_233 ) , L_40 , V_132 ) ;
snprintf ( V_181 -> V_234 , sizeof( V_181 -> V_234 ) ,
L_41 , V_132 ) ;
V_30 = F_16 ( V_8 , V_227 , V_181 -> V_234 ,
F_43 , V_181 ) ;
if ( V_30 != 0 ) {
F_11 ( V_8 -> V_9 , L_42 ,
V_132 , V_30 ) ;
}
F_13 ( V_8 -> V_31 , V_181 -> V_102 + 1 ,
V_235 , 0 ) ;
return 0 ;
}
int F_64 ( struct V_6 * V_7 , int V_236 , bool V_237 )
{
unsigned int V_46 , V_14 ;
if ( V_236 < 1 || V_236 > 6 )
return - V_58 ;
V_46 = V_238 + ( V_236 - 1 ) * 8 ;
if ( V_237 )
V_14 = V_239 ;
else
V_14 = 0 ;
return F_7 ( V_7 , V_46 , V_239 , V_14 ) ;
}
