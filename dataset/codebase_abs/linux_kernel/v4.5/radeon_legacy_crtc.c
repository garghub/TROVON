static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_2 ) ;
F_3 ( V_11 + V_10 -> V_12 , 0 ) ;
F_3 ( V_13 + V_10 -> V_12 , 0 ) ;
F_3 ( V_14 + V_10 -> V_12 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_2 ) ;
int V_15 = V_4 -> V_16 ;
int V_17 = V_4 -> V_18 ;
bool V_19 = true , V_20 = true ;
int V_21 ;
int V_22 ;
int V_23 ;
int V_24 ;
T_1 V_25 , V_26 , V_27 ;
T_1 V_28 , V_29 , V_30 ;
T_1 V_31 , V_32 ;
T_1 V_33 , V_34 ;
struct V_3 * V_35 = & V_10 -> V_35 ;
V_29 = F_5 ( V_36 ) &
( V_37 |
V_38 ) ;
V_28 = F_5 ( V_39 ) &
( V_40 |
V_41 ) ;
V_27 = 0 ;
if ( ( V_8 -> V_42 == V_43 ) ||
( V_8 -> V_42 == V_44 ) ) {
V_27 |= V_45 ;
}
V_32 = ( ( ( ( V_4 -> V_46 / 8 ) - 1 ) & 0x3ff )
| ( ( ( ( V_4 -> V_47 / 8 ) - 1 ) & 0x1ff ) << 16 ) ) ;
V_21 = ( V_4 -> V_48 - V_4 -> V_49 ) / 8 ;
if ( ! V_21 )
V_21 = 1 ;
V_23 = V_4 -> V_49 - 8 ;
V_31 = ( ( V_23 & 0x1fff )
| ( ( V_21 & 0x3f ) << 16 )
| ( ( V_4 -> V_50 & V_51 )
? V_52
: 0 ) ) ;
V_34 = ( ( ( V_4 -> V_53 - 1 ) & 0xffff )
| ( ( V_4 -> V_54 - 1 ) << 16 ) ) ;
V_22 = V_4 -> V_55 - V_4 -> V_56 ;
if ( ! V_22 )
V_22 = 1 ;
V_33 = ( ( ( V_4 -> V_56 - 1 ) & 0xfff )
| ( ( V_22 & 0x1f ) << 16 )
| ( ( V_4 -> V_50 & V_57 )
? V_58
: 0 ) ) ;
V_30 = 0 ;
if ( V_35 -> V_16 == 0 ||
V_35 -> V_18 == 0 ) {
V_19 = false ;
V_20 = false ;
} else {
if ( V_15 > V_35 -> V_16 )
V_15 = V_35 -> V_16 ;
if ( V_17 > V_35 -> V_18 )
V_17 = V_35 -> V_18 ;
if ( V_15 == V_35 -> V_16 )
V_19 = false ;
if ( V_17 == V_35 -> V_18 )
V_20 = false ;
}
switch ( V_10 -> V_59 ) {
case V_60 :
case V_61 :
if ( ! V_19 )
V_28 |= ( ( V_15 / 8 - 1 ) << 16 ) ;
else {
V_26 = ( V_28 & V_41 ) ? 1 : 0 ;
V_25 = ( ( V_15 + V_26 ) * V_62 )
/ V_35 -> V_16 + 1 ;
V_28 |= ( ( ( V_25 ) & V_63 ) |
V_64 |
V_65 |
( ( V_35 -> V_16 / 8 - 1 ) << 16 ) ) ;
}
if ( ! V_20 )
V_29 |= ( ( V_17 - 1 ) << 12 ) ;
else {
V_26 = ( V_29 & V_38 ) ? 1 : 0 ;
V_25 = ( ( V_17 + V_26 ) * V_66 )
/ V_35 -> V_18 + 1 ;
V_29 |= ( ( ( V_25 ) & V_67 ) |
V_68 |
V_69 |
( ( V_35 -> V_18 - 1 ) << 12 ) ) ;
}
break;
case V_70 :
V_28 |= ( ( V_15 / 8 - 1 ) << 16 ) ;
V_29 |= ( ( V_17 - 1 ) << 12 ) ;
V_27 |= ( V_71 |
V_72 ) ;
V_24 = ( V_4 -> V_73 - V_4 -> V_74 ) / 8 ;
if ( V_24 > 110 )
V_24 = 110 ;
V_32 = ( ( ( V_24 ) & 0x3ff )
| ( ( ( ( V_4 -> V_47 / 8 ) - 1 ) & 0x1ff ) << 16 ) ) ;
V_21 = ( V_4 -> V_48 - V_4 -> V_49 ) / 8 ;
if ( ! V_21 )
V_21 = 1 ;
V_31 = ( ( ( ( V_4 -> V_49 - V_4 -> V_74 ) / 8 ) & 0x1fff )
| ( ( V_21 & 0x3f ) << 16 )
| ( ( V_4 -> V_50 & V_51 )
? V_52
: 0 ) ) ;
V_34 = ( ( ( V_4 -> V_75 - V_4 -> V_76 ) & 0xffff )
| ( ( V_4 -> V_54 - 1 ) << 16 ) ) ;
V_22 = V_4 -> V_55 - V_4 -> V_56 ;
if ( ! V_22 )
V_22 = 1 ;
V_33 = ( ( ( ( V_4 -> V_56 - V_4 -> V_76 ) & 0xfff )
| ( ( V_22 & 0x1f ) << 16 )
| ( ( V_4 -> V_50 & V_57 )
? V_58
: 0 ) ) ) ;
V_30 = ( ( ( V_35 -> V_18 ) & 0xfff ) |
( ( ( V_35 -> V_16 / 8 ) & 0x1ff ) << 16 ) ) ;
break;
case V_77 :
default:
V_28 |= ( ( V_15 / 8 - 1 ) << 16 ) ;
V_29 |= ( ( V_17 - 1 ) << 12 ) ;
break;
}
F_3 ( V_39 , V_28 ) ;
F_3 ( V_36 , V_29 ) ;
F_3 ( V_78 , V_27 ) ;
F_3 ( V_79 , V_30 ) ;
F_3 ( V_80 , V_31 ) ;
F_3 ( V_81 , V_33 ) ;
F_3 ( V_82 , V_32 ) ;
F_3 ( V_83 , V_34 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
int V_84 = 0 ;
for ( V_84 = 0 ;
( V_84 < 10000 &&
F_7 ( V_85 ) & V_86 ) ;
V_84 ++ ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
while ( F_7 ( V_85 ) & V_86 ) ;
F_9 ( V_85 ,
V_87 ,
~ ( V_87 ) ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
int V_84 = 0 ;
for ( V_84 = 0 ;
( V_84 < 10000 &&
F_7 ( V_88 ) & V_89 ) ;
V_84 ++ ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
while ( F_7 ( V_88 ) & V_89 ) ;
F_9 ( V_88 ,
V_90 ,
~ ( V_90 ) ) ;
}
static T_2 F_12 ( T_3 V_91 , T_3 V_92 ,
T_3 V_93 )
{
unsigned int V_94 ;
if ( ! V_92 )
return 1 ;
V_94 = ( ( unsigned ) V_91 * V_93 ) / V_92 ;
if ( V_94 >= 30000 )
return 7 ;
else if ( V_94 >= 18000 )
return 4 ;
else
return 1 ;
}
static void F_13 ( struct V_1 * V_2 , int V_4 )
{
struct V_10 * V_10 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
T_4 V_95 = 0 ;
T_4 V_96 ;
if ( V_10 -> V_97 )
V_96 = ( V_98 |
V_99 |
V_100 |
V_101 ) ;
else
V_96 = ( V_102 |
V_103 |
V_104 ) ;
if ( V_8 -> V_50 & V_105 )
V_95 = V_106 ;
switch ( V_4 ) {
case V_107 :
V_10 -> V_108 = true ;
F_14 ( V_8 ) ;
if ( V_10 -> V_97 )
F_15 ( V_109 , V_110 , ~ ( V_110 | V_96 ) ) ;
else {
F_15 ( V_111 , V_112 , ~ ( V_112 |
V_113 ) ) ;
F_15 ( V_114 , V_95 , ~ ( V_96 | V_95 ) ) ;
}
F_16 ( V_6 , V_10 -> V_97 ) ;
F_17 ( V_2 ) ;
break;
case V_115 :
case V_116 :
case V_117 :
F_18 ( V_6 , V_10 -> V_97 ) ;
if ( V_10 -> V_97 )
F_15 ( V_109 , V_96 , ~ ( V_110 | V_96 ) ) ;
else {
F_15 ( V_111 , V_113 , ~ ( V_112 |
V_113 ) ) ;
F_15 ( V_114 , V_96 , ~ ( V_96 | V_95 ) ) ;
}
V_10 -> V_108 = false ;
F_14 ( V_8 ) ;
break;
}
}
int F_19 ( struct V_1 * V_2 , int V_118 , int V_119 ,
struct V_120 * V_121 )
{
return F_20 ( V_2 , V_121 , V_118 , V_119 , 0 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_120 * V_122 ,
int V_118 , int V_119 , enum V_123 V_124 )
{
return F_20 ( V_2 , V_122 , V_118 , V_119 , 1 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_120 * V_122 ,
int V_118 , int V_119 , int V_125 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_2 ) ;
struct V_126 * V_127 ;
struct V_120 * V_128 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
T_5 V_133 ;
T_4 V_12 , V_134 , V_135 = 0 ;
T_4 V_136 , V_137 ;
T_4 V_138 ;
int V_139 ;
T_4 V_140 , V_141 ;
int V_142 ;
F_22 ( L_1 ) ;
if ( ! V_125 && ! V_2 -> V_143 -> V_122 ) {
F_22 ( L_2 ) ;
return 0 ;
}
if ( V_125 ) {
V_127 = F_23 ( V_122 ) ;
V_128 = V_122 ;
}
else {
V_127 = F_23 ( V_2 -> V_143 -> V_122 ) ;
V_128 = V_2 -> V_143 -> V_122 ;
}
switch ( V_128 -> V_144 ) {
case 8 :
V_139 = 2 ;
break;
case 15 :
V_139 = 3 ;
break;
case 16 :
V_139 = 4 ;
break;
case 24 :
V_139 = 5 ;
break;
case 32 :
V_139 = 6 ;
break;
default:
return false ;
}
V_130 = V_127 -> V_130 ;
V_132 = F_24 ( V_130 ) ;
V_145:
V_142 = F_25 ( V_132 , false ) ;
if ( F_26 ( V_142 != 0 ) )
return V_142 ;
V_142 = F_27 ( V_132 , V_146 , 1 << 27 ,
& V_133 ) ;
if ( F_26 ( V_142 != 0 ) ) {
F_28 ( V_132 ) ;
if ( ! V_125 && V_122 && V_122 != V_2 -> V_143 -> V_122 ) {
struct V_131 * V_147 ;
unsigned long V_148 , V_149 ;
V_147 = F_24 ( F_23 ( V_122 ) -> V_130 ) ;
V_149 = F_29 ( V_147 ) ;
V_148 = F_29 ( V_132 ) ;
if ( V_148 <= V_149 && ! F_25 ( V_147 , false ) ) {
F_30 ( V_147 ) ;
F_28 ( V_147 ) ;
V_122 = NULL ;
goto V_145;
}
}
return - V_150 ;
}
F_31 ( V_132 , & V_138 , NULL ) ;
F_28 ( V_132 ) ;
if ( V_138 & V_151 )
F_32 ( L_3 ) ;
V_10 -> V_152 = V_8 -> V_153 . V_154 ;
V_133 -= V_10 -> V_152 ;
V_134 = 0 ;
V_137 = V_128 -> V_155 [ 0 ] / ( V_128 -> V_144 / 8 ) ;
V_136 = ( ( ( V_137 * V_128 -> V_144 ) +
( ( V_128 -> V_144 * 8 ) - 1 ) ) /
( V_128 -> V_144 * 8 ) ) ;
V_136 |= V_136 << 16 ;
V_134 |= V_156 ;
if ( V_138 & V_157 ) {
if ( F_33 ( V_8 ) )
V_134 |= ( V_158 |
V_159 |
V_160 ) ;
else
V_134 |= V_161 ;
} else {
if ( F_33 ( V_8 ) )
V_134 &= ~ ( V_158 |
V_159 |
V_160 ) ;
else
V_134 &= ~ V_161 ;
}
if ( V_138 & V_157 ) {
if ( F_33 ( V_8 ) ) {
V_135 = V_118 | ( V_119 << 16 ) ;
V_133 &= ~ 0x7ff ;
} else {
int V_162 = V_128 -> V_144 >> 4 ;
int V_163 = ( ( ( V_119 >> 3 ) * V_137 + V_118 ) >> ( 8 - V_162 ) ) << 11 ;
V_133 += V_163 + ( ( V_118 << V_162 ) % 256 ) + ( ( V_119 % 8 ) << 8 ) ;
V_134 |= ( V_119 % 16 ) ;
}
} else {
int V_164 = V_119 * V_137 + V_118 ;
switch ( V_128 -> V_144 ) {
case 8 :
V_164 *= 1 ;
break;
case 15 :
case 16 :
V_164 *= 2 ;
break;
case 24 :
V_164 *= 3 ;
break;
case 32 :
V_164 *= 4 ;
break;
default:
return false ;
}
V_133 += V_164 ;
}
V_133 &= ~ 7 ;
if ( V_10 -> V_97 == 1 )
V_140 = V_109 ;
else
V_140 = V_111 ;
V_141 = F_5 ( V_140 ) ;
V_141 &= ~ ( 0xf << 8 ) ;
V_141 |= ( V_139 << 8 ) ;
V_141 &= ~ V_165 ;
F_3 ( V_140 , V_141 ) ;
V_12 = ( T_1 ) V_133 ;
F_3 ( V_166 + V_10 -> V_12 , V_10 -> V_152 ) ;
if ( F_33 ( V_8 ) ) {
if ( V_10 -> V_97 )
F_3 ( V_167 , V_135 ) ;
else
F_3 ( V_168 , V_135 ) ;
}
F_3 ( V_169 + V_10 -> V_12 , V_134 ) ;
F_3 ( V_170 + V_10 -> V_12 , V_12 ) ;
F_3 ( V_171 + V_10 -> V_12 , V_136 ) ;
if ( ! V_125 && V_122 && V_122 != V_2 -> V_143 -> V_122 ) {
V_127 = F_23 ( V_122 ) ;
V_132 = F_24 ( V_127 -> V_130 ) ;
V_142 = F_25 ( V_132 , false ) ;
if ( F_26 ( V_142 != 0 ) )
return V_142 ;
F_30 ( V_132 ) ;
F_28 ( V_132 ) ;
}
F_34 ( V_8 ) ;
return 0 ;
}
static bool F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_2 ) ;
struct V_172 * V_173 ;
int V_139 ;
int V_23 ;
int V_21 ;
int V_22 ;
T_4 V_174 ;
T_4 V_175 ;
T_4 V_176 ;
T_4 V_177 ;
bool V_178 = false ;
F_22 ( L_1 ) ;
F_36 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_173 -> V_2 == V_2 ) {
struct V_179 * V_179 = F_37 ( V_173 ) ;
if ( V_179 -> V_180 & V_181 ) {
V_178 = true ;
F_38 ( L_4 , V_10 -> V_97 ) ;
break;
}
}
}
switch ( V_2 -> V_143 -> V_122 -> V_144 ) {
case 8 :
V_139 = 2 ;
break;
case 15 :
V_139 = 3 ;
break;
case 16 :
V_139 = 4 ;
break;
case 24 :
V_139 = 5 ;
break;
case 32 :
V_139 = 6 ;
break;
default:
return false ;
}
V_174 = ( ( ( ( V_4 -> V_46 / 8 ) - 1 ) & 0x3ff )
| ( ( ( ( V_4 -> V_47 / 8 ) - 1 ) & 0x1ff ) << 16 ) ) ;
V_21 = ( V_4 -> V_48 - V_4 -> V_49 ) / 8 ;
if ( ! V_21 )
V_21 = 1 ;
V_23 = V_4 -> V_49 - 8 ;
V_175 = ( ( V_23 & 0x1fff )
| ( ( V_21 & 0x3f ) << 16 )
| ( ( V_4 -> V_50 & V_51 )
? V_52
: 0 ) ) ;
V_176 = ( ( ( V_4 -> V_53 - 1 ) & 0xffff )
| ( ( V_4 -> V_54 - 1 ) << 16 ) ) ;
V_22 = V_4 -> V_55 - V_4 -> V_56 ;
if ( ! V_22 )
V_22 = 1 ;
V_177 = ( ( ( V_4 -> V_56 - 1 ) & 0xfff )
| ( ( V_22 & 0x1f ) << 16 )
| ( ( V_4 -> V_50 & V_57 )
? V_58
: 0 ) ) ;
if ( V_10 -> V_97 ) {
T_4 V_182 ;
T_4 V_183 ;
V_182 = F_5 ( V_109 ) & 0x00718080 ;
V_182 |= ( ( V_139 << 8 )
| V_99
| V_100
| V_98
| V_101
| ( ( V_4 -> V_50 & V_184 )
? V_185
: 0 )
| ( ( V_4 -> V_50 & V_186 )
? V_187
: 0 )
| ( ( V_4 -> V_50 & V_188 )
? V_189
: 0 ) ) ;
if ( ( V_8 -> V_42 == V_190 ) || ( V_8 -> V_42 == V_191 ) )
V_182 |= V_110 ;
V_183 = F_5 ( V_192 ) ;
V_183 &= ~ V_193 ;
F_3 ( V_192 , V_183 ) ;
F_3 ( V_109 , V_182 ) ;
F_3 ( V_194 , V_175 ) ;
F_3 ( V_195 , V_177 ) ;
} else {
T_4 V_196 ;
T_4 V_95 ;
T_4 V_197 ;
V_196 = F_5 ( V_111 ) & 0x00718000 ;
V_196 |= ( V_198
| ( V_139 << 8 )
| V_113
| ( ( V_4 -> V_50 & V_184 )
? V_199
: 0 )
| ( ( V_4 -> V_50 & V_186 )
? V_200
: 0 )
| ( ( V_4 -> V_50 & V_188 )
? V_201
: 0 ) ) ;
if ( ( V_8 -> V_42 == V_190 ) || ( V_8 -> V_42 == V_191 ) )
V_196 |= V_112 ;
V_95 = F_5 ( V_114 ) ;
V_95 |= ( V_202 |
V_103 |
V_104 |
V_102 ) ;
V_197 = F_5 ( V_203 ) ;
V_197 &= ~ V_204 ;
F_3 ( V_203 , V_197 ) ;
F_3 ( V_111 , V_196 ) ;
F_3 ( V_114 , V_95 ) ;
}
if ( V_178 )
F_39 ( V_173 , & V_174 ,
& V_175 , & V_176 ,
& V_177 ) ;
F_3 ( V_205 + V_10 -> V_12 , V_174 ) ;
F_3 ( V_206 + V_10 -> V_12 , V_175 ) ;
F_3 ( V_207 + V_10 -> V_12 , V_176 ) ;
F_3 ( V_208 + V_10 -> V_12 , V_177 ) ;
return true ;
}
static void F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_2 ) ;
struct V_172 * V_173 ;
T_4 V_209 = 0 ;
T_4 V_210 = 0 ;
T_4 V_211 = 0 ;
T_4 V_212 = 0 ;
T_4 V_213 = 0 ;
T_2 V_214 ;
bool V_215 = false ;
T_4 V_216 = 0 ;
T_4 V_217 = 0 ;
T_4 V_218 = 0 ;
bool V_178 = false ;
struct V_219 * V_220 ;
struct {
int V_221 ;
int V_222 ;
} * V_223 , V_224 [] = {
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 4 , 2 } ,
{ 8 , 3 } ,
{ 3 , 4 } ,
{ 16 , 5 } ,
{ 6 , 6 } ,
{ 12 , 7 } ,
{ 0 , 0 }
} ;
if ( V_10 -> V_97 )
V_220 = & V_8 -> clock . V_225 ;
else
V_220 = & V_8 -> clock . V_226 ;
V_220 -> V_50 = V_227 ;
if ( V_4 -> clock > 200000 )
V_220 -> V_50 |= V_228 ;
else
V_220 -> V_50 |= V_229 ;
F_36 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_173 -> V_2 == V_2 ) {
struct V_179 * V_179 = F_37 ( V_173 ) ;
if ( V_179 -> V_180 & V_181 ) {
V_178 = true ;
break;
}
if ( V_173 -> V_230 != V_231 )
V_220 -> V_50 |= V_232 ;
if ( V_173 -> V_230 == V_233 ) {
if ( ! V_8 -> V_234 ) {
struct V_179 * V_179 = F_37 ( V_173 ) ;
struct V_235 * V_236 = (struct V_235 * ) V_179 -> V_237 ;
if ( V_236 ) {
if ( V_236 -> V_238 ) {
V_216 = V_236 -> V_239 ;
V_217 = ( V_236 -> V_240 |
( V_236 -> V_241 << 16 ) ) ;
V_218 = 0 ;
V_215 = true ;
}
}
}
V_220 -> V_50 |= V_242 ;
}
}
}
F_22 ( L_1 ) ;
if ( ! V_215 ) {
F_41 ( V_220 , V_4 -> clock ,
& V_213 , & V_209 , & V_210 ,
& V_211 , & V_212 ) ;
for ( V_223 = & V_224 [ 0 ] ; V_223 -> V_221 ; ++ V_223 ) {
if ( V_223 -> V_221 == V_212 )
break;
}
if ( ! V_223 -> V_221 )
V_223 = & V_224 [ 0 ] ;
F_22 ( L_5 ,
( unsigned ) V_213 ,
V_209 ,
V_211 ,
V_212 ) ;
V_216 = V_211 ;
#if F_42 ( V_243 ) && ( 0 )
if ( V_244 -> V_245 == V_246 )
V_217 = 0x000600ad ;
else
#endif
V_217 = ( V_209 | ( V_223 -> V_222 << 16 ) ) ;
V_218 = V_4 -> V_247 & 0x7 ;
}
V_214 = F_12 ( V_220 -> V_248 ,
V_216 & 0x3ff ,
V_217 & 0x7ff ) ;
if ( V_10 -> V_97 ) {
T_4 V_249 = ( ( F_7 ( V_250 ) &
~ ( V_251 ) ) |
V_252 ) ;
if ( V_178 ) {
F_43 ( V_173 , & V_218 ,
& V_216 , & V_217 ,
& V_249 ) ;
}
F_9 ( V_250 ,
V_253 ,
~ ( V_251 ) ) ;
F_9 ( V_254 ,
V_255
| V_256
| ( ( T_4 ) V_214 << V_257 ) ,
~ ( V_255
| V_256
| V_258 ) ) ;
F_9 ( V_88 ,
V_216 ,
~ V_259 ) ;
F_9 ( V_260 ,
V_217 ,
~ V_261 ) ;
F_9 ( V_260 ,
V_217 ,
~ V_262 ) ;
F_11 ( V_6 ) ;
F_10 ( V_6 ) ;
F_44 ( V_263 , V_218 ) ;
F_9 ( V_254 ,
0 ,
~ ( V_255
| V_264
| V_256 ) ) ;
F_22 ( L_6 ,
( unsigned ) V_216 ,
( unsigned ) V_217 ,
( unsigned ) V_218 ,
F_7 ( V_254 ) ) ;
F_22 ( L_7 ,
( unsigned ) V_216 & V_259 ,
( unsigned ) V_217 & V_261 ,
( unsigned ) ( ( V_217 &
V_262 ) >> 16 ) ) ;
F_45 ( 50 ) ;
F_9 ( V_250 ,
V_252 ,
~ ( V_251 ) ) ;
F_44 ( V_250 , V_249 ) ;
} else {
T_4 V_249 ;
if ( V_178 ) {
V_249 = F_7 ( V_250 ) ;
F_46 ( V_173 , & V_218 , & V_216 ,
& V_217 , & V_249 ) ;
}
if ( V_8 -> V_50 & V_265 ) {
if ( ( V_216 == ( F_7 ( V_85 ) & V_266 ) ) &&
( V_217 == ( F_7 ( V_267 ) &
( V_268 | V_269 ) ) ) ) {
F_15 ( V_270 ,
V_271 ,
~ ( V_271 ) ) ;
F_47 ( V_8 ) ;
return;
}
}
F_9 ( V_272 ,
V_273 ,
~ ( V_274 ) ) ;
F_9 ( V_275 ,
V_276
| V_277
| V_278
| ( ( T_4 ) V_214 << V_279 ) ,
~ ( V_276
| V_277
| V_278
| V_280 ) ) ;
F_15 ( V_270 ,
V_271 ,
~ ( V_271 ) ) ;
F_47 ( V_8 ) ;
if ( F_33 ( V_8 ) ||
( V_8 -> V_42 == V_281 ) ||
( V_8 -> V_42 == V_190 ) ||
( V_8 -> V_42 == V_191 ) ) {
if ( V_216 & V_282 ) {
F_9 ( V_85 ,
V_216 ,
0 ) ;
} else {
F_9 ( V_85 ,
( V_216 << V_283 ) ,
~ V_282 ) ;
}
} else
F_9 ( V_85 ,
V_216 ,
~ V_266 ) ;
F_9 ( V_267 ,
V_217 ,
~ V_269 ) ;
F_9 ( V_267 ,
V_217 ,
~ V_268 ) ;
F_8 ( V_6 ) ;
F_6 ( V_6 ) ;
F_44 ( V_284 , V_218 ) ;
F_9 ( V_275 ,
0 ,
~ ( V_276
| V_285
| V_277
| V_278 ) ) ;
F_22 ( L_8 ,
V_216 ,
V_217 ,
( unsigned ) V_218 ,
F_7 ( V_275 ) ) ;
F_22 ( L_9 ,
V_216 & V_266 ,
V_217 & V_269 ,
( V_217 & V_268 ) >> 16 ) ;
F_45 ( 50 ) ;
F_9 ( V_272 ,
V_286 ,
~ ( V_274 ) ) ;
if ( V_178 )
F_44 ( V_250 , V_249 ) ;
}
}
static bool F_48 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_287 )
{
if ( ! F_49 ( V_2 , V_4 , V_287 ) )
return false ;
return true ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_287 ,
int V_118 , int V_119 , struct V_120 * V_121 )
{
struct V_10 * V_10 = F_2 ( V_2 ) ;
F_19 ( V_2 , V_118 , V_119 , V_121 ) ;
F_35 ( V_2 , V_287 ) ;
F_40 ( V_2 , V_287 ) ;
F_1 ( V_2 , V_287 ) ;
if ( V_10 -> V_97 == 0 ) {
F_4 ( V_2 , V_287 ) ;
} else {
if ( V_10 -> V_59 != V_77 ) {
F_32 ( L_10 ) ;
}
}
F_51 ( V_2 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_1 * V_288 ;
F_36 (crtci, &dev->mode_config.crtc_list, head)
F_13 ( V_288 , V_117 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_1 * V_288 ;
F_36 (crtci, &dev->mode_config.crtc_list, head) {
if ( V_288 -> V_108 )
F_13 ( V_288 , V_107 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_117 ) ;
if ( V_2 -> V_143 -> V_122 ) {
int V_142 ;
struct V_126 * V_127 ;
struct V_131 * V_132 ;
V_127 = F_23 ( V_2 -> V_143 -> V_122 ) ;
V_132 = F_24 ( V_127 -> V_130 ) ;
V_142 = F_25 ( V_132 , false ) ;
if ( F_26 ( V_142 ) )
F_32 ( L_11 ) ;
else {
F_30 ( V_132 ) ;
F_28 ( V_132 ) ;
}
}
}
void F_55 ( struct V_5 * V_6 ,
struct V_10 * V_10 )
{
if ( V_10 -> V_97 == 1 )
V_10 -> V_12 = V_289 - V_205 ;
F_56 ( & V_10 -> V_133 , & V_290 ) ;
}
