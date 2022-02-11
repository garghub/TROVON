static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_5 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_59 * V_60 )
{
return F_4 ( V_60 , V_4 , 0x9081 ) ;
}
static int F_5 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_66 = F_6 ( V_62 ) ;
unsigned int V_3 ;
V_3 = F_7 ( V_66 , V_13 ) ;
if ( V_3 & V_67 )
V_64 -> V_68 . V_69 . V_70 [ 0 ] = 1 ;
else
V_64 -> V_68 . V_69 . V_70 [ 0 ] = 0 ;
return 0 ;
}
static int F_8 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_66 = F_6 ( V_62 ) ;
unsigned int V_71 = F_7 ( V_66 , V_14 ) ;
unsigned int V_72 = F_7 ( V_66 , V_13 ) ;
if ( V_64 -> V_68 . V_69 . V_70 [ 0 ] ==
( ( V_72 & V_67 ) != 0 ) )
return 0 ;
if ( V_71 & V_73 )
return - V_74 ;
if ( V_64 -> V_68 . V_69 . V_70 [ 0 ] ) {
V_72 &= ~ ( V_75 | V_76 ) ;
V_72 |= V_67 ;
} else {
V_72 |= V_75 | V_76 ;
V_72 &= ~ V_67 ;
}
F_9 ( V_66 , V_13 , V_72 ) ;
return 0 ;
}
static int F_10 ( struct V_77 * V_78 , unsigned int V_79 ,
unsigned int V_80 )
{
T_1 V_81 ;
unsigned int V_82 , V_83 , V_84 , V_85 ;
unsigned int div ;
int V_86 ;
div = 1 ;
while ( ( V_79 / div ) > 13500000 ) {
div *= 2 ;
if ( div > 8 ) {
F_11 ( L_1 ,
V_79 ) ;
return - V_74 ;
}
}
V_78 -> V_87 = div / 2 ;
F_12 ( L_2 , V_79 , V_80 ) ;
V_79 /= div ;
div = 0 ;
V_85 = V_80 * 2 ;
while ( V_85 < 90000000 ) {
div ++ ;
V_85 *= 2 ;
if ( div > 7 ) {
F_11 ( L_3 ,
V_80 ) ;
return - V_74 ;
}
}
V_78 -> V_88 = div ;
F_12 ( L_4 , V_85 ) ;
for ( V_86 = 0 ; V_86 < F_13 ( V_89 ) ; V_86 ++ ) {
if ( V_89 [ V_86 ] . V_90 <= V_79 && V_79 <= V_89 [ V_86 ] . V_91 ) {
V_78 -> V_92 = V_89 [ V_86 ] . V_92 ;
V_85 /= V_89 [ V_86 ] . V_93 ;
break;
}
}
if ( V_86 == F_13 ( V_89 ) ) {
F_11 ( L_5 , V_79 ) ;
return - V_74 ;
}
V_83 = V_85 / V_79 ;
V_78 -> V_94 = V_83 ;
V_84 = V_85 % V_79 ;
F_12 ( L_6 , V_84 ) ;
V_81 = V_95 * ( long long ) V_84 ;
F_14 ( V_81 , V_79 ) ;
V_82 = V_81 & 0xFFFFFFFF ;
if ( ( V_82 % 10 ) >= 5 )
V_82 += 5 ;
V_78 -> V_96 = V_82 / 10 ;
F_12 ( L_7 ,
V_78 -> V_94 , V_78 -> V_96 ,
V_78 -> V_92 , V_78 -> V_88 ,
V_78 -> V_87 ) ;
return 0 ;
}
static int F_15 ( struct V_65 * V_66 , int V_97 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_98 * V_99 = F_16 ( V_66 ) ;
T_2 V_100 , V_101 , V_102 ;
struct V_77 V_78 ;
int V_103 ;
int V_104 ;
if ( V_79 == V_99 -> V_105 && V_80 == V_99 -> V_106 )
return 0 ;
if ( V_80 == 0 ) {
F_17 ( V_66 -> V_2 , L_8 ) ;
V_99 -> V_105 = 0 ;
V_99 -> V_106 = 0 ;
return 0 ;
}
V_103 = F_10 ( & V_78 , V_79 , V_80 ) ;
if ( V_103 != 0 )
return V_103 ;
V_102 = F_7 ( V_66 , V_22 ) ;
V_102 &= ~ V_107 ;
switch ( V_97 ) {
case V_108 :
V_102 |= 0x1 ;
break;
default:
F_18 ( V_66 -> V_2 , L_9 , V_97 ) ;
return - V_74 ;
}
V_104 = F_7 ( V_66 , V_17 ) ;
if ( V_104 & V_109 )
F_9 ( V_66 , V_17 ,
V_104 & ~ V_109 ) ;
V_100 = F_7 ( V_66 , V_18 ) ;
V_100 &= ~ V_110 ;
F_9 ( V_66 , V_18 , V_100 ) ;
if ( V_78 . V_96 )
V_100 |= V_111 ;
else
V_100 &= ~ V_111 ;
F_9 ( V_66 , V_18 , V_100 ) ;
F_9 ( V_66 , V_19 ,
( V_78 . V_88 << V_112 ) |
( V_78 . V_92 << V_113 ) ) ;
F_9 ( V_66 , V_20 , V_78 . V_96 ) ;
V_101 = F_7 ( V_66 , V_21 ) ;
V_101 &= ~ V_114 ;
V_101 |= V_78 . V_94 << V_115 ;
F_9 ( V_66 , V_21 , V_101 ) ;
V_102 &= ~ V_116 ;
V_102 |= V_78 . V_87 << V_117 ;
F_9 ( V_66 , V_22 , V_102 ) ;
F_19 ( V_66 , V_21 ,
V_118 , 0 ) ;
F_9 ( V_66 , V_18 , V_100 | V_110 ) ;
if ( V_104 & V_109 )
F_9 ( V_66 , V_17 , V_104 ) ;
F_17 ( V_66 -> V_2 , L_10 , V_79 , V_80 ) ;
V_99 -> V_105 = V_79 ;
V_99 -> V_106 = V_80 ;
return 0 ;
}
static int F_20 ( struct V_65 * V_66 )
{
struct V_98 * V_99 = F_16 ( V_66 ) ;
int V_119 , V_86 , V_85 ;
unsigned int V_3 ;
int V_103 = 0 ;
int V_120 = 0 ;
int V_121 = 0 ;
switch ( V_99 -> V_122 ) {
case V_123 :
if ( V_99 -> V_124 > 12225000 ) {
V_120 = 1 ;
V_99 -> V_125 = V_99 -> V_124 / 2 ;
} else {
V_99 -> V_125 = V_99 -> V_124 ;
}
F_15 ( V_66 , V_108 , 0 , 0 ) ;
break;
case V_108 :
if ( V_99 -> V_126 && V_99 -> V_127 ) {
for ( V_86 = 0 ; V_86 < F_13 ( V_128 ) ; V_86 ++ ) {
V_85 = V_99 -> V_129 * V_128 [ V_86 ] . V_93 ;
V_119 = V_85 ;
if ( V_85 >= V_99 -> V_127 &&
V_85 > 3000000 )
break;
}
if ( V_86 == F_13 ( V_128 ) )
return - V_74 ;
} else if ( V_99 -> V_129 ) {
for ( V_86 = 0 ; V_86 < F_13 ( V_128 ) ; V_86 ++ ) {
V_119 = V_128 [ V_86 ] . V_93
* V_99 -> V_129 ;
if ( V_119 > 3000000 )
break;
}
if ( V_86 == F_13 ( V_128 ) )
return - V_74 ;
} else {
V_119 = 12288000 ;
}
V_103 = F_15 ( V_66 , V_108 ,
V_99 -> V_124 , V_119 ) ;
if ( V_103 == 0 ) {
V_99 -> V_125 = V_119 ;
V_121 = 1 ;
} else {
V_99 -> V_125 = V_99 -> V_124 ;
}
break;
default:
return - V_74 ;
}
V_3 = F_7 ( V_66 , V_15 ) ;
if ( V_120 )
V_3 |= V_130 ;
else
V_3 &= ~ V_130 ;
F_9 ( V_66 , V_15 , V_3 ) ;
V_3 = F_7 ( V_66 , V_17 ) ;
if ( V_121 )
V_3 |= V_131 ;
else
V_3 &= ~ V_131 ;
F_9 ( V_66 , V_17 , V_3 ) ;
F_17 ( V_66 -> V_2 , L_11 , V_99 -> V_125 ) ;
return V_103 ;
}
static int F_21 ( struct V_132 * V_133 ,
struct V_61 * V_62 , int V_134 )
{
struct V_65 * V_66 = F_22 ( V_133 -> V_135 ) ;
struct V_98 * V_99 = F_16 ( V_66 ) ;
switch ( V_99 -> V_122 ) {
case V_123 :
F_17 ( V_66 -> V_2 , L_12 , V_99 -> V_124 ) ;
break;
case V_108 :
F_17 ( V_66 -> V_2 , L_13 ,
V_99 -> V_124 ) ;
break;
default:
F_18 ( V_66 -> V_2 , L_14 ) ;
return - V_74 ;
}
switch ( V_134 ) {
case V_136 :
F_20 ( V_66 ) ;
break;
case V_137 :
F_15 ( V_66 , 0 , 0 , 0 ) ;
break;
}
return 0 ;
}
static int F_23 ( struct V_65 * V_66 ,
enum V_138 V_139 )
{
struct V_98 * V_99 = F_16 ( V_66 ) ;
switch ( V_139 ) {
case V_140 :
break;
case V_141 :
F_19 ( V_66 , V_8 ,
V_142 , 0x2 ) ;
F_19 ( V_66 , V_9 ,
V_143 , 0 ) ;
break;
case V_144 :
if ( F_24 ( V_66 ) == V_145 ) {
F_25 ( V_99 -> V_59 , false ) ;
F_26 ( V_99 -> V_59 ) ;
F_19 ( V_66 , V_11 ,
V_146 , 0 ) ;
F_19 ( V_66 , V_9 ,
V_147 | V_148 ,
V_147 | V_148 ) ;
F_19 ( V_66 , V_8 ,
V_149 |
V_142 ,
V_149 | 0x6 ) ;
F_27 ( 100 ) ;
F_19 ( V_66 , V_8 ,
V_149 , 0 ) ;
F_19 ( V_66 , V_9 ,
V_147 , 0 ) ;
}
F_19 ( V_66 , V_8 ,
V_142 , 0x04 ) ;
F_19 ( V_66 , V_9 ,
V_143 ,
V_143 ) ;
break;
case V_145 :
F_19 ( V_66 , V_9 ,
V_147 | V_148 ,
V_147 ) ;
F_19 ( V_66 , V_8 ,
V_149 | V_142 ,
V_149 ) ;
F_19 ( V_66 , V_11 ,
V_146 ,
V_146 ) ;
F_25 ( V_99 -> V_59 , true ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_150 * V_151 ,
unsigned int V_152 )
{
struct V_65 * V_66 = V_151 -> V_66 ;
struct V_98 * V_99 = F_16 ( V_66 ) ;
unsigned int V_153 = F_7 ( V_66 , V_24 ) ;
V_153 &= ~ ( V_154 | V_155 |
V_156 | V_157 | V_158 ) ;
switch ( V_152 & V_159 ) {
case V_160 :
V_99 -> V_126 = 0 ;
break;
case V_161 :
V_153 |= V_157 ;
V_99 -> V_126 = 1 ;
break;
case V_162 :
V_153 |= V_156 ;
V_99 -> V_126 = 1 ;
break;
case V_163 :
V_153 |= V_157 | V_156 ;
V_99 -> V_126 = 1 ;
break;
default:
return - V_74 ;
}
switch ( V_152 & V_164 ) {
case V_165 :
V_153 |= V_155 ;
case V_166 :
V_153 |= 0x3 ;
break;
case V_167 :
V_153 |= 0x2 ;
break;
case V_168 :
break;
case V_169 :
V_153 |= 0x1 ;
break;
default:
return - V_74 ;
}
switch ( V_152 & V_164 ) {
case V_166 :
case V_165 :
switch ( V_152 & V_170 ) {
case V_171 :
break;
case V_172 :
V_153 |= V_154 ;
break;
default:
return - V_74 ;
}
break;
case V_167 :
case V_168 :
case V_169 :
switch ( V_152 & V_170 ) {
case V_171 :
break;
case V_173 :
V_153 |= V_154 | V_155 ;
break;
case V_172 :
V_153 |= V_154 ;
break;
case V_174 :
V_153 |= V_155 ;
break;
default:
return - V_74 ;
}
break;
default:
return - V_74 ;
}
F_9 ( V_66 , V_24 , V_153 ) ;
return 0 ;
}
static int F_29 ( struct V_175 * V_176 ,
struct V_177 * V_178 ,
struct V_150 * V_151 )
{
struct V_65 * V_66 = V_151 -> V_66 ;
struct V_98 * V_99 = F_16 ( V_66 ) ;
int V_103 , V_86 , V_179 , V_180 , V_181 ;
unsigned int V_182 , V_183 , V_153 , V_184 , V_185 ;
V_182 = F_7 ( V_66 , V_16 ) ;
V_182 &= ~ ( V_186 | V_187 ) ;
V_183 = F_7 ( V_66 , V_23 ) ;
V_153 = F_7 ( V_66 , V_24 ) ;
V_153 &= ~ V_188 ;
V_184 = F_7 ( V_66 , V_25 ) ;
V_184 &= ~ V_189 ;
V_185 = F_7 ( V_66 , V_26 ) ;
V_185 &= ~ V_190 ;
V_99 -> V_129 = F_30 ( V_178 ) ;
if ( V_99 -> V_191 ) {
int V_192 = ( ( V_183 & V_193 ) >>
V_194 ) + 1 ;
V_99 -> V_127 = V_99 -> V_129 * V_99 -> V_191 * V_192 ;
} else {
V_99 -> V_127 = 2 * V_99 -> V_129 ;
switch ( F_31 ( V_178 ) ) {
case 16 :
V_99 -> V_127 *= 16 ;
break;
case 20 :
V_99 -> V_127 *= 20 ;
V_153 |= 0x4 ;
break;
case 24 :
V_99 -> V_127 *= 24 ;
V_153 |= 0x8 ;
break;
case 32 :
V_99 -> V_127 *= 32 ;
V_153 |= 0xc ;
break;
default:
return - V_74 ;
}
}
F_17 ( V_66 -> V_2 , L_15 , V_99 -> V_127 ) ;
V_103 = F_20 ( V_66 ) ;
if ( V_103 != 0 )
return V_103 ;
V_179 = 0 ;
V_180 = abs ( ( V_99 -> V_125 / V_128 [ 0 ] . V_93 )
- V_99 -> V_129 ) ;
for ( V_86 = 1 ; V_86 < F_13 ( V_128 ) ; V_86 ++ ) {
V_181 = abs ( ( V_99 -> V_125 /
V_128 [ V_86 ] . V_93 ) - V_99 -> V_129 ) ;
if ( V_181 < V_180 ) {
V_179 = V_86 ;
V_180 = V_181 ;
}
}
F_17 ( V_66 -> V_2 , L_16 ,
V_128 [ V_179 ] . V_93 ) ;
V_182 |= ( V_128 [ V_179 ] . V_195
<< V_196 ) ;
V_179 = 0 ;
V_180 = abs ( V_99 -> V_129 - V_197 [ 0 ] . V_198 ) ;
for ( V_86 = 1 ; V_86 < F_13 ( V_197 ) ; V_86 ++ ) {
V_181 = abs ( V_99 -> V_129 - V_197 [ V_86 ] . V_198 ) ;
if ( V_181 < V_180 ) {
V_179 = V_86 ;
V_180 = V_181 ;
}
}
F_17 ( V_66 -> V_2 , L_17 ,
V_197 [ V_179 ] . V_198 ) ;
V_182 |= ( V_197 [ V_179 ] . V_199
<< V_200 ) ;
V_179 = 0 ;
V_180 = V_201 ;
for ( V_86 = 0 ; V_86 < F_13 ( V_202 ) ; V_86 ++ ) {
V_181 = ( ( V_99 -> V_125 * 10 ) / V_202 [ V_86 ] . div )
- V_99 -> V_127 ;
if ( V_181 < 0 )
break;
if ( V_181 < V_180 ) {
V_179 = V_86 ;
V_180 = V_181 ;
}
}
V_99 -> V_127 = ( V_99 -> V_125 * 10 ) / V_202 [ V_179 ] . div ;
F_17 ( V_66 -> V_2 , L_18 ,
V_202 [ V_179 ] . div , V_99 -> V_127 ) ;
V_184 |= V_202 [ V_179 ] . V_203 ;
F_17 ( V_66 -> V_2 , L_19 , V_99 -> V_127 / V_99 -> V_129 ) ;
V_185 |= V_99 -> V_127 / V_99 -> V_129 ;
if ( V_99 -> V_204 . V_205 ) {
struct V_206 * V_204 = & V_99 -> V_204 ;
struct V_207 * V_208 ;
int V_209 ;
V_179 = 0 ;
V_180 = abs ( V_204 -> V_210 [ 0 ] . V_198 - V_99 -> V_129 ) ;
for ( V_86 = 0 ; V_86 < V_204 -> V_205 ; V_86 ++ ) {
V_181 = abs ( V_204 -> V_210 [ V_86 ] . V_198 -
V_99 -> V_129 ) ;
if ( V_181 < V_180 ) {
V_180 = V_181 ;
V_179 = V_86 ;
}
}
V_208 = & V_204 -> V_210 [ V_179 ] ;
F_17 ( V_66 -> V_2 , L_20 ,
V_208 -> V_211 , V_208 -> V_198 ) ;
V_209 = F_7 ( V_66 , V_39 ) & V_212 ;
if ( V_209 & V_212 )
F_9 ( V_66 , V_39 , 0 ) ;
for ( V_86 = 1 ; V_86 < F_13 ( V_208 -> V_213 ) ; V_86 ++ )
F_9 ( V_66 , V_39 + V_86 , V_208 -> V_213 [ V_86 ] ) ;
V_209 |= ( V_208 -> V_213 [ 0 ] & ~ V_212 ) ;
F_9 ( V_66 , V_39 , V_209 ) ;
}
F_9 ( V_66 , V_16 , V_182 ) ;
F_9 ( V_66 , V_24 , V_153 ) ;
F_9 ( V_66 , V_25 , V_184 ) ;
F_9 ( V_66 , V_26 , V_185 ) ;
return 0 ;
}
static int F_32 ( struct V_150 * V_214 , int V_215 )
{
struct V_65 * V_66 = V_214 -> V_66 ;
unsigned int V_3 ;
V_3 = F_7 ( V_66 , V_31 ) ;
if ( V_215 )
V_3 |= V_216 ;
else
V_3 &= ~ V_216 ;
F_9 ( V_66 , V_31 , V_3 ) ;
return 0 ;
}
static int F_33 ( struct V_65 * V_66 , int V_217 ,
int V_218 , unsigned int V_219 , int V_220 )
{
struct V_98 * V_99 = F_16 ( V_66 ) ;
switch ( V_217 ) {
case V_123 :
case V_108 :
V_99 -> V_122 = V_217 ;
V_99 -> V_124 = V_219 ;
break;
default:
return - V_74 ;
}
return 0 ;
}
static int F_34 ( struct V_150 * V_151 ,
unsigned int V_221 , unsigned int V_222 , int V_192 , int V_223 )
{
struct V_65 * V_66 = V_151 -> V_66 ;
struct V_98 * V_99 = F_16 ( V_66 ) ;
unsigned int V_183 = F_7 ( V_66 , V_23 ) ;
V_183 &= ~ ( V_224 | V_193 ) ;
if ( V_192 < 0 || V_192 > 4 )
return - V_74 ;
V_99 -> V_191 = V_223 ;
if ( V_192 == 0 )
V_192 = 1 ;
V_183 |= ( V_192 - 1 ) << V_194 ;
switch ( V_222 ) {
case 1 :
break;
case 2 :
V_183 |= 0x10 ;
break;
case 4 :
V_183 |= 0x20 ;
break;
case 8 :
V_183 |= 0x30 ;
break;
default:
return - V_74 ;
}
F_9 ( V_66 , V_23 , V_183 ) ;
return 0 ;
}
static int F_35 ( struct V_65 * V_66 )
{
struct V_98 * V_99 = F_16 ( V_66 ) ;
F_19 ( V_66 , V_6 ,
V_225 , V_225 ) ;
F_19 ( V_66 , V_7 ,
V_226 , V_226 ) ;
if ( ! V_99 -> V_204 . V_205 ) {
F_17 ( V_66 -> V_2 ,
L_21 ) ;
F_36 ( V_66 , V_227 ,
F_13 ( V_227 ) ) ;
}
return 0 ;
}
static int F_37 ( struct V_228 * V_229 ,
const struct V_230 * V_231 )
{
struct V_98 * V_99 ;
unsigned int V_3 ;
int V_103 ;
V_99 = F_38 ( & V_229 -> V_2 , sizeof( struct V_98 ) ,
V_232 ) ;
if ( V_99 == NULL )
return - V_233 ;
F_39 ( V_229 , V_99 ) ;
V_99 -> V_59 = F_40 ( V_229 , & V_234 ) ;
if ( F_41 ( V_99 -> V_59 ) ) {
V_103 = F_42 ( V_99 -> V_59 ) ;
F_18 ( & V_229 -> V_2 , L_22 , V_103 ) ;
return V_103 ;
}
V_103 = F_43 ( V_99 -> V_59 , V_4 , & V_3 ) ;
if ( V_103 != 0 ) {
F_18 ( & V_229 -> V_2 , L_23 , V_103 ) ;
return V_103 ;
}
if ( V_3 != 0x9081 ) {
F_18 ( & V_229 -> V_2 , L_24 , V_3 ) ;
return - V_74 ;
}
V_103 = F_3 ( V_99 -> V_59 ) ;
if ( V_103 < 0 ) {
F_18 ( & V_229 -> V_2 , L_25 ) ;
return V_103 ;
}
if ( F_44 ( & V_229 -> V_2 ) )
memcpy ( & V_99 -> V_204 , F_44 ( & V_229 -> V_2 ) ,
sizeof( V_99 -> V_204 ) ) ;
V_3 = 0 ;
if ( V_99 -> V_204 . V_235 )
V_3 |= V_236 ;
if ( ! V_99 -> V_204 . V_237 )
V_3 |= V_238 ;
F_45 ( V_99 -> V_59 , V_29 ,
V_236 | V_238 , V_3 ) ;
F_25 ( V_99 -> V_59 , true ) ;
V_103 = F_46 ( & V_229 -> V_2 ,
& V_239 , & V_240 , 1 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
static int F_47 ( struct V_228 * V_241 )
{
F_48 ( & V_241 -> V_2 ) ;
return 0 ;
}
