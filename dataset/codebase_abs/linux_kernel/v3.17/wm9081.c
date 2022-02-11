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
V_64 -> V_68 . integer . V_68 [ 0 ] = 1 ;
else
V_64 -> V_68 . integer . V_68 [ 0 ] = 0 ;
return 0 ;
}
static int F_8 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_66 = F_6 ( V_62 ) ;
unsigned int V_69 = F_7 ( V_66 , V_14 ) ;
unsigned int V_70 = F_7 ( V_66 , V_13 ) ;
if ( V_64 -> V_68 . integer . V_68 [ 0 ] ==
( ( V_70 & V_67 ) != 0 ) )
return 0 ;
if ( V_69 & V_71 )
return - V_72 ;
if ( V_64 -> V_68 . integer . V_68 [ 0 ] ) {
V_70 &= ~ ( V_73 | V_74 ) ;
V_70 |= V_67 ;
} else {
V_70 |= V_73 | V_74 ;
V_70 &= ~ V_67 ;
}
F_9 ( V_66 , V_13 , V_70 ) ;
return 0 ;
}
static int F_10 ( struct V_75 * V_76 , unsigned int V_77 ,
unsigned int V_78 )
{
T_1 V_79 ;
unsigned int V_80 , V_81 , V_82 , V_83 ;
unsigned int div ;
int V_84 ;
div = 1 ;
while ( ( V_77 / div ) > 13500000 ) {
div *= 2 ;
if ( div > 8 ) {
F_11 ( L_1 ,
V_77 ) ;
return - V_72 ;
}
}
V_76 -> V_85 = div / 2 ;
F_12 ( L_2 , V_77 , V_78 ) ;
V_77 /= div ;
div = 0 ;
V_83 = V_78 * 2 ;
while ( V_83 < 90000000 ) {
div ++ ;
V_83 *= 2 ;
if ( div > 7 ) {
F_11 ( L_3 ,
V_78 ) ;
return - V_72 ;
}
}
V_76 -> V_86 = div ;
F_12 ( L_4 , V_83 ) ;
for ( V_84 = 0 ; V_84 < F_13 ( V_87 ) ; V_84 ++ ) {
if ( V_87 [ V_84 ] . V_88 <= V_77 && V_77 <= V_87 [ V_84 ] . V_89 ) {
V_76 -> V_90 = V_87 [ V_84 ] . V_90 ;
V_83 /= V_87 [ V_84 ] . V_91 ;
break;
}
}
if ( V_84 == F_13 ( V_87 ) ) {
F_11 ( L_5 , V_77 ) ;
return - V_72 ;
}
V_81 = V_83 / V_77 ;
V_76 -> V_92 = V_81 ;
V_82 = V_83 % V_77 ;
F_12 ( L_6 , V_82 ) ;
V_79 = V_93 * ( long long ) V_82 ;
F_14 ( V_79 , V_77 ) ;
V_80 = V_79 & 0xFFFFFFFF ;
if ( ( V_80 % 10 ) >= 5 )
V_80 += 5 ;
V_76 -> V_94 = V_80 / 10 ;
F_12 ( L_7 ,
V_76 -> V_92 , V_76 -> V_94 ,
V_76 -> V_90 , V_76 -> V_86 ,
V_76 -> V_85 ) ;
return 0 ;
}
static int F_15 ( struct V_65 * V_66 , int V_95 ,
unsigned int V_77 , unsigned int V_78 )
{
struct V_96 * V_97 = F_16 ( V_66 ) ;
T_2 V_98 , V_99 , V_100 ;
struct V_75 V_76 ;
int V_101 ;
int V_102 ;
if ( V_77 == V_97 -> V_103 && V_78 == V_97 -> V_104 )
return 0 ;
if ( V_78 == 0 ) {
F_17 ( V_66 -> V_2 , L_8 ) ;
V_97 -> V_103 = 0 ;
V_97 -> V_104 = 0 ;
return 0 ;
}
V_101 = F_10 ( & V_76 , V_77 , V_78 ) ;
if ( V_101 != 0 )
return V_101 ;
V_100 = F_7 ( V_66 , V_22 ) ;
V_100 &= ~ V_105 ;
switch ( V_95 ) {
case V_106 :
V_100 |= 0x1 ;
break;
default:
F_18 ( V_66 -> V_2 , L_9 , V_95 ) ;
return - V_72 ;
}
V_102 = F_7 ( V_66 , V_17 ) ;
if ( V_102 & V_107 )
F_9 ( V_66 , V_17 ,
V_102 & ~ V_107 ) ;
V_98 = F_7 ( V_66 , V_18 ) ;
V_98 &= ~ V_108 ;
F_9 ( V_66 , V_18 , V_98 ) ;
if ( V_76 . V_94 )
V_98 |= V_109 ;
else
V_98 &= ~ V_109 ;
F_9 ( V_66 , V_18 , V_98 ) ;
F_9 ( V_66 , V_19 ,
( V_76 . V_86 << V_110 ) |
( V_76 . V_90 << V_111 ) ) ;
F_9 ( V_66 , V_20 , V_76 . V_94 ) ;
V_99 = F_7 ( V_66 , V_21 ) ;
V_99 &= ~ V_112 ;
V_99 |= V_76 . V_92 << V_113 ;
F_9 ( V_66 , V_21 , V_99 ) ;
V_100 &= ~ V_114 ;
V_100 |= V_76 . V_85 << V_115 ;
F_9 ( V_66 , V_22 , V_100 ) ;
F_19 ( V_66 , V_21 ,
V_116 , 0 ) ;
F_9 ( V_66 , V_18 , V_98 | V_108 ) ;
if ( V_102 & V_107 )
F_9 ( V_66 , V_17 , V_102 ) ;
F_17 ( V_66 -> V_2 , L_10 , V_77 , V_78 ) ;
V_97 -> V_103 = V_77 ;
V_97 -> V_104 = V_78 ;
return 0 ;
}
static int F_20 ( struct V_65 * V_66 )
{
struct V_96 * V_97 = F_16 ( V_66 ) ;
int V_117 , V_84 , V_83 ;
unsigned int V_3 ;
int V_101 = 0 ;
int V_118 = 0 ;
int V_119 = 0 ;
switch ( V_97 -> V_120 ) {
case V_121 :
if ( V_97 -> V_122 > 12225000 ) {
V_118 = 1 ;
V_97 -> V_123 = V_97 -> V_122 / 2 ;
} else {
V_97 -> V_123 = V_97 -> V_122 ;
}
F_15 ( V_66 , V_106 , 0 , 0 ) ;
break;
case V_106 :
if ( V_97 -> V_124 && V_97 -> V_125 ) {
for ( V_84 = 0 ; V_84 < F_13 ( V_126 ) ; V_84 ++ ) {
V_83 = V_97 -> V_127 * V_126 [ V_84 ] . V_91 ;
V_117 = V_83 ;
if ( V_83 >= V_97 -> V_125 &&
V_83 > 3000000 )
break;
}
if ( V_84 == F_13 ( V_126 ) )
return - V_72 ;
} else if ( V_97 -> V_127 ) {
for ( V_84 = 0 ; V_84 < F_13 ( V_126 ) ; V_84 ++ ) {
V_117 = V_126 [ V_84 ] . V_91
* V_97 -> V_127 ;
if ( V_117 > 3000000 )
break;
}
if ( V_84 == F_13 ( V_126 ) )
return - V_72 ;
} else {
V_117 = 12288000 ;
}
V_101 = F_15 ( V_66 , V_106 ,
V_97 -> V_122 , V_117 ) ;
if ( V_101 == 0 ) {
V_97 -> V_123 = V_117 ;
V_119 = 1 ;
} else {
V_97 -> V_123 = V_97 -> V_122 ;
}
break;
default:
return - V_72 ;
}
V_3 = F_7 ( V_66 , V_15 ) ;
if ( V_118 )
V_3 |= V_128 ;
else
V_3 &= ~ V_128 ;
F_9 ( V_66 , V_15 , V_3 ) ;
V_3 = F_7 ( V_66 , V_17 ) ;
if ( V_119 )
V_3 |= V_129 ;
else
V_3 &= ~ V_129 ;
F_9 ( V_66 , V_17 , V_3 ) ;
F_17 ( V_66 -> V_2 , L_11 , V_97 -> V_123 ) ;
return V_101 ;
}
static int F_21 ( struct V_130 * V_131 ,
struct V_61 * V_62 , int V_132 )
{
struct V_65 * V_66 = V_131 -> V_66 ;
struct V_96 * V_97 = F_16 ( V_66 ) ;
switch ( V_97 -> V_120 ) {
case V_121 :
F_17 ( V_66 -> V_2 , L_12 , V_97 -> V_122 ) ;
break;
case V_106 :
F_17 ( V_66 -> V_2 , L_13 ,
V_97 -> V_122 ) ;
break;
default:
F_18 ( V_66 -> V_2 , L_14 ) ;
return - V_72 ;
}
switch ( V_132 ) {
case V_133 :
F_20 ( V_66 ) ;
break;
case V_134 :
F_15 ( V_66 , 0 , 0 , 0 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_65 * V_66 ,
enum V_135 V_136 )
{
struct V_96 * V_97 = F_16 ( V_66 ) ;
switch ( V_136 ) {
case V_137 :
break;
case V_138 :
F_19 ( V_66 , V_8 ,
V_139 , 0x2 ) ;
F_19 ( V_66 , V_9 ,
V_140 , 0 ) ;
break;
case V_141 :
if ( V_66 -> V_142 . V_143 == V_144 ) {
F_23 ( V_97 -> V_59 , false ) ;
F_24 ( V_97 -> V_59 ) ;
F_19 ( V_66 , V_11 ,
V_145 , 0 ) ;
F_19 ( V_66 , V_9 ,
V_146 | V_147 ,
V_146 | V_147 ) ;
F_19 ( V_66 , V_8 ,
V_148 |
V_139 ,
V_148 | 0x6 ) ;
F_25 ( 100 ) ;
F_19 ( V_66 , V_8 ,
V_148 , 0 ) ;
F_19 ( V_66 , V_9 ,
V_146 , 0 ) ;
}
F_19 ( V_66 , V_8 ,
V_139 , 0x04 ) ;
F_19 ( V_66 , V_9 ,
V_140 ,
V_140 ) ;
break;
case V_144 :
F_19 ( V_66 , V_9 ,
V_146 | V_147 ,
V_146 ) ;
F_19 ( V_66 , V_8 ,
V_148 | V_139 ,
V_148 ) ;
F_19 ( V_66 , V_11 ,
V_145 ,
V_145 ) ;
F_23 ( V_97 -> V_59 , true ) ;
break;
}
V_66 -> V_142 . V_143 = V_136 ;
return 0 ;
}
static int F_26 ( struct V_149 * V_150 ,
unsigned int V_151 )
{
struct V_65 * V_66 = V_150 -> V_66 ;
struct V_96 * V_97 = F_16 ( V_66 ) ;
unsigned int V_152 = F_7 ( V_66 , V_24 ) ;
V_152 &= ~ ( V_153 | V_154 |
V_155 | V_156 | V_157 ) ;
switch ( V_151 & V_158 ) {
case V_159 :
V_97 -> V_124 = 0 ;
break;
case V_160 :
V_152 |= V_156 ;
V_97 -> V_124 = 1 ;
break;
case V_161 :
V_152 |= V_155 ;
V_97 -> V_124 = 1 ;
break;
case V_162 :
V_152 |= V_156 | V_155 ;
V_97 -> V_124 = 1 ;
break;
default:
return - V_72 ;
}
switch ( V_151 & V_163 ) {
case V_164 :
V_152 |= V_154 ;
case V_165 :
V_152 |= 0x3 ;
break;
case V_166 :
V_152 |= 0x2 ;
break;
case V_167 :
break;
case V_168 :
V_152 |= 0x1 ;
break;
default:
return - V_72 ;
}
switch ( V_151 & V_163 ) {
case V_165 :
case V_164 :
switch ( V_151 & V_169 ) {
case V_170 :
break;
case V_171 :
V_152 |= V_153 ;
break;
default:
return - V_72 ;
}
break;
case V_166 :
case V_167 :
case V_168 :
switch ( V_151 & V_169 ) {
case V_170 :
break;
case V_172 :
V_152 |= V_153 | V_154 ;
break;
case V_171 :
V_152 |= V_153 ;
break;
case V_173 :
V_152 |= V_154 ;
break;
default:
return - V_72 ;
}
break;
default:
return - V_72 ;
}
F_9 ( V_66 , V_24 , V_152 ) ;
return 0 ;
}
static int F_27 ( struct V_174 * V_175 ,
struct V_176 * V_177 ,
struct V_149 * V_150 )
{
struct V_65 * V_66 = V_150 -> V_66 ;
struct V_96 * V_97 = F_16 ( V_66 ) ;
int V_101 , V_84 , V_178 , V_179 , V_180 ;
unsigned int V_181 , V_182 , V_152 , V_183 , V_184 ;
V_181 = F_7 ( V_66 , V_16 ) ;
V_181 &= ~ ( V_185 | V_186 ) ;
V_182 = F_7 ( V_66 , V_23 ) ;
V_152 = F_7 ( V_66 , V_24 ) ;
V_152 &= ~ V_187 ;
V_183 = F_7 ( V_66 , V_25 ) ;
V_183 &= ~ V_188 ;
V_184 = F_7 ( V_66 , V_26 ) ;
V_184 &= ~ V_189 ;
V_97 -> V_127 = F_28 ( V_177 ) ;
if ( V_97 -> V_190 ) {
int V_191 = ( ( V_182 & V_192 ) >>
V_193 ) + 1 ;
V_97 -> V_125 = V_97 -> V_127 * V_97 -> V_190 * V_191 ;
} else {
V_97 -> V_125 = 2 * V_97 -> V_127 ;
switch ( F_29 ( V_177 ) ) {
case 16 :
V_97 -> V_125 *= 16 ;
break;
case 20 :
V_97 -> V_125 *= 20 ;
V_152 |= 0x4 ;
break;
case 24 :
V_97 -> V_125 *= 24 ;
V_152 |= 0x8 ;
break;
case 32 :
V_97 -> V_125 *= 32 ;
V_152 |= 0xc ;
break;
default:
return - V_72 ;
}
}
F_17 ( V_66 -> V_2 , L_15 , V_97 -> V_125 ) ;
V_101 = F_20 ( V_66 ) ;
if ( V_101 != 0 )
return V_101 ;
V_178 = 0 ;
V_179 = abs ( ( V_97 -> V_123 / V_126 [ 0 ] . V_91 )
- V_97 -> V_127 ) ;
for ( V_84 = 1 ; V_84 < F_13 ( V_126 ) ; V_84 ++ ) {
V_180 = abs ( ( V_97 -> V_123 /
V_126 [ V_84 ] . V_91 ) - V_97 -> V_127 ) ;
if ( V_180 < V_179 ) {
V_178 = V_84 ;
V_179 = V_180 ;
}
}
F_17 ( V_66 -> V_2 , L_16 ,
V_126 [ V_178 ] . V_91 ) ;
V_181 |= ( V_126 [ V_178 ] . V_194
<< V_195 ) ;
V_178 = 0 ;
V_179 = abs ( V_97 -> V_127 - V_196 [ 0 ] . V_197 ) ;
for ( V_84 = 1 ; V_84 < F_13 ( V_196 ) ; V_84 ++ ) {
V_180 = abs ( V_97 -> V_127 - V_196 [ V_84 ] . V_197 ) ;
if ( V_180 < V_179 ) {
V_178 = V_84 ;
V_179 = V_180 ;
}
}
F_17 ( V_66 -> V_2 , L_17 ,
V_196 [ V_178 ] . V_197 ) ;
V_181 |= ( V_196 [ V_178 ] . V_198
<< V_199 ) ;
V_178 = 0 ;
V_179 = V_200 ;
for ( V_84 = 0 ; V_84 < F_13 ( V_201 ) ; V_84 ++ ) {
V_180 = ( ( V_97 -> V_123 * 10 ) / V_201 [ V_84 ] . div )
- V_97 -> V_125 ;
if ( V_180 < 0 )
break;
if ( V_180 < V_179 ) {
V_178 = V_84 ;
V_179 = V_180 ;
}
}
V_97 -> V_125 = ( V_97 -> V_123 * 10 ) / V_201 [ V_178 ] . div ;
F_17 ( V_66 -> V_2 , L_18 ,
V_201 [ V_178 ] . div , V_97 -> V_125 ) ;
V_183 |= V_201 [ V_178 ] . V_202 ;
F_17 ( V_66 -> V_2 , L_19 , V_97 -> V_125 / V_97 -> V_127 ) ;
V_184 |= V_97 -> V_125 / V_97 -> V_127 ;
if ( V_97 -> V_203 . V_204 ) {
struct V_205 * V_203 = & V_97 -> V_203 ;
struct V_206 * V_207 ;
int V_208 ;
V_178 = 0 ;
V_179 = abs ( V_203 -> V_209 [ 0 ] . V_197 - V_97 -> V_127 ) ;
for ( V_84 = 0 ; V_84 < V_203 -> V_204 ; V_84 ++ ) {
V_180 = abs ( V_203 -> V_209 [ V_84 ] . V_197 -
V_97 -> V_127 ) ;
if ( V_180 < V_179 ) {
V_179 = V_180 ;
V_178 = V_84 ;
}
}
V_207 = & V_203 -> V_209 [ V_178 ] ;
F_17 ( V_66 -> V_2 , L_20 ,
V_207 -> V_210 , V_207 -> V_197 ) ;
V_208 = F_7 ( V_66 , V_39 ) & V_211 ;
if ( V_208 & V_211 )
F_9 ( V_66 , V_39 , 0 ) ;
for ( V_84 = 1 ; V_84 < F_13 ( V_207 -> V_212 ) ; V_84 ++ )
F_9 ( V_66 , V_39 + V_84 , V_207 -> V_212 [ V_84 ] ) ;
V_208 |= ( V_207 -> V_212 [ 0 ] & ~ V_211 ) ;
F_9 ( V_66 , V_39 , V_208 ) ;
}
F_9 ( V_66 , V_16 , V_181 ) ;
F_9 ( V_66 , V_24 , V_152 ) ;
F_9 ( V_66 , V_25 , V_183 ) ;
F_9 ( V_66 , V_26 , V_184 ) ;
return 0 ;
}
static int F_30 ( struct V_149 * V_213 , int V_214 )
{
struct V_65 * V_66 = V_213 -> V_66 ;
unsigned int V_3 ;
V_3 = F_7 ( V_66 , V_31 ) ;
if ( V_214 )
V_3 |= V_215 ;
else
V_3 &= ~ V_215 ;
F_9 ( V_66 , V_31 , V_3 ) ;
return 0 ;
}
static int F_31 ( struct V_65 * V_66 , int V_216 ,
int V_217 , unsigned int V_218 , int V_219 )
{
struct V_96 * V_97 = F_16 ( V_66 ) ;
switch ( V_216 ) {
case V_121 :
case V_106 :
V_97 -> V_120 = V_216 ;
V_97 -> V_122 = V_218 ;
break;
default:
return - V_72 ;
}
return 0 ;
}
static int F_32 ( struct V_149 * V_150 ,
unsigned int V_220 , unsigned int V_221 , int V_191 , int V_222 )
{
struct V_65 * V_66 = V_150 -> V_66 ;
struct V_96 * V_97 = F_16 ( V_66 ) ;
unsigned int V_182 = F_7 ( V_66 , V_23 ) ;
V_182 &= ~ ( V_223 | V_192 ) ;
if ( V_191 < 0 || V_191 > 4 )
return - V_72 ;
V_97 -> V_190 = V_222 ;
if ( V_191 == 0 )
V_191 = 1 ;
V_182 |= ( V_191 - 1 ) << V_193 ;
switch ( V_221 ) {
case 1 :
break;
case 2 :
V_182 |= 0x10 ;
break;
case 4 :
V_182 |= 0x20 ;
break;
case 8 :
V_182 |= 0x30 ;
break;
default:
return - V_72 ;
}
F_9 ( V_66 , V_23 , V_182 ) ;
return 0 ;
}
static int F_33 ( struct V_65 * V_66 )
{
struct V_96 * V_97 = F_16 ( V_66 ) ;
F_19 ( V_66 , V_6 ,
V_224 , V_224 ) ;
F_19 ( V_66 , V_7 ,
V_225 , V_225 ) ;
if ( ! V_97 -> V_203 . V_204 ) {
F_17 ( V_66 -> V_2 ,
L_21 ) ;
F_34 ( V_66 , V_226 ,
F_13 ( V_226 ) ) ;
}
return 0 ;
}
static int F_35 ( struct V_65 * V_66 )
{
F_22 ( V_66 , V_144 ) ;
return 0 ;
}
static int F_36 ( struct V_227 * V_228 ,
const struct V_229 * V_230 )
{
struct V_96 * V_97 ;
unsigned int V_3 ;
int V_101 ;
V_97 = F_37 ( & V_228 -> V_2 , sizeof( struct V_96 ) ,
V_231 ) ;
if ( V_97 == NULL )
return - V_232 ;
F_38 ( V_228 , V_97 ) ;
V_97 -> V_59 = F_39 ( V_228 , & V_233 ) ;
if ( F_40 ( V_97 -> V_59 ) ) {
V_101 = F_41 ( V_97 -> V_59 ) ;
F_18 ( & V_228 -> V_2 , L_22 , V_101 ) ;
return V_101 ;
}
V_101 = F_42 ( V_97 -> V_59 , V_4 , & V_3 ) ;
if ( V_101 != 0 ) {
F_18 ( & V_228 -> V_2 , L_23 , V_101 ) ;
return V_101 ;
}
if ( V_3 != 0x9081 ) {
F_18 ( & V_228 -> V_2 , L_24 , V_3 ) ;
return - V_72 ;
}
V_101 = F_3 ( V_97 -> V_59 ) ;
if ( V_101 < 0 ) {
F_18 ( & V_228 -> V_2 , L_25 ) ;
return V_101 ;
}
if ( F_43 ( & V_228 -> V_2 ) )
memcpy ( & V_97 -> V_203 , F_43 ( & V_228 -> V_2 ) ,
sizeof( V_97 -> V_203 ) ) ;
V_3 = 0 ;
if ( V_97 -> V_203 . V_234 )
V_3 |= V_235 ;
if ( ! V_97 -> V_203 . V_236 )
V_3 |= V_237 ;
F_44 ( V_97 -> V_59 , V_29 ,
V_235 | V_237 , V_3 ) ;
F_23 ( V_97 -> V_59 , true ) ;
V_101 = F_45 ( & V_228 -> V_2 ,
& V_238 , & V_239 , 1 ) ;
if ( V_101 < 0 )
return V_101 ;
return 0 ;
}
static int F_46 ( struct V_227 * V_240 )
{
F_47 ( & V_240 -> V_2 ) ;
return 0 ;
}
