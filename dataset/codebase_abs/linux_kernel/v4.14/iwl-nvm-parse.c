static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , T_2 V_5 )
{
#define F_2 ( T_3 ) \
((flags & NVM_CHANNEL_##x) ? " " #x : "")
if ( ! ( V_5 & V_6 ) ) {
F_3 ( V_2 , V_3 , L_1 ,
V_4 , V_5 ) ;
return;
}
F_3 ( V_2 , V_3 ,
L_2 ,
V_4 , V_5 ,
F_2 ( V_7 ) ,
F_2 ( V_8 ) ,
F_2 ( V_9 ) ,
F_2 ( V_10 ) ,
F_2 ( V_11 ) ,
F_2 ( V_12 ) ,
F_2 ( V_13 ) ,
F_2 ( 20MHZ ) ,
F_2 ( 40MHZ ) ,
F_2 ( 80MHZ ) ,
F_2 ( 160MHZ ) ,
F_2 ( V_14 ) ) ;
#undef F_2
}
static T_1 F_4 ( T_4 V_15 , int V_16 , bool V_17 ,
T_2 V_18 , const struct V_19 * V_20 )
{
T_1 V_5 = V_21 ;
T_1 V_22 = V_23 ;
if ( V_20 -> V_24 == V_25 )
V_22 = V_26 ;
if ( ! V_17 && ( V_18 & V_27 ) ) {
if ( V_15 <= V_28 )
V_5 &= ~ V_29 ;
if ( V_15 >= V_30 )
V_5 &= ~ V_31 ;
} else if ( V_15 <= V_22 && ( V_18 & V_27 ) ) {
if ( ( V_16 - V_32 ) % 2 == 0 )
V_5 &= ~ V_29 ;
else
V_5 &= ~ V_31 ;
}
if ( ! ( V_18 & V_33 ) )
V_5 |= V_34 ;
if ( ! ( V_18 & V_35 ) )
V_5 |= V_36 ;
if ( ! ( V_18 & V_37 ) )
V_5 |= V_38 ;
if ( ! ( V_18 & V_39 ) )
V_5 |= V_38 ;
if ( V_18 & V_40 )
V_5 |= V_41 ;
if ( V_18 & V_42 )
V_5 |= V_43 ;
if ( ( V_18 & V_44 ) &&
( V_5 & V_38 ) )
V_5 |= V_45 ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , const struct V_19 * V_20 ,
struct V_46 * V_47 ,
const T_5 * const V_48 ,
bool V_49 , bool V_50 )
{
int V_16 ;
int V_51 = 0 ;
struct V_52 * V_53 ;
T_2 V_54 ;
int V_55 , V_56 ;
const T_4 * V_57 ;
if ( V_20 -> V_24 != V_25 ) {
V_55 = V_58 ;
V_57 = & V_59 [ 0 ] ;
V_56 = V_32 ;
} else {
V_55 = V_60 ;
V_57 = & V_61 [ 0 ] ;
V_56 = V_62 ;
}
for ( V_16 = 0 ; V_16 < V_55 ; V_16 ++ ) {
bool V_17 = ( V_16 >= V_56 ) ;
V_54 = F_6 ( V_48 + V_16 ) ;
if ( V_17 && ! V_47 -> V_63 )
continue;
if ( V_50 && V_17 ) {
V_54 &= ~ ( V_27 |
V_33 |
V_35 ) ;
}
if ( V_54 & V_35 )
V_47 -> V_64 = true ;
if ( ! V_49 && ! ( V_54 & V_6 ) ) {
F_1 ( V_2 , V_65 ,
V_57 [ V_16 ] , V_54 ) ;
continue;
}
V_53 = & V_47 -> V_66 [ V_51 ] ;
V_51 ++ ;
V_53 -> V_67 = V_57 [ V_16 ] ;
V_53 -> V_68 = V_17 ?
V_69 : V_70 ;
V_53 -> V_71 =
F_7 (
V_53 -> V_67 , V_53 -> V_68 ) ;
V_53 -> V_72 = V_73 ;
if ( ! V_49 )
V_53 -> V_5 = F_4 ( V_57 [ V_16 ] ,
V_16 , V_17 ,
V_54 , V_20 ) ;
else
V_53 -> V_5 = 0 ;
F_1 ( V_2 , V_65 ,
V_53 -> V_67 , V_54 ) ;
F_8 ( V_2 , L_3 ,
V_53 -> V_67 , V_53 -> V_72 ) ;
}
return V_51 ;
}
static void F_9 ( const struct V_19 * V_20 ,
struct V_46 * V_47 ,
struct V_74 * V_75 ,
T_4 V_76 , T_4 V_77 )
{
int V_78 = F_10 ( V_77 ) ;
int V_79 = F_10 ( V_76 ) ;
unsigned int V_80 = ( V_20 -> V_81 ? :
V_82 ) ;
V_75 -> V_83 = true ;
V_75 -> V_84 = V_85 |
V_86 |
V_87 |
3 << V_88 |
V_80 <<
V_89 ;
if ( V_47 -> V_64 )
V_75 -> V_84 |= V_90 |
V_91 ;
if ( V_20 -> V_92 )
V_75 -> V_84 |= V_93 ;
if ( V_20 -> V_94 -> V_95 )
V_75 -> V_84 |= V_96 ;
if ( V_47 -> V_97 ) {
V_78 = 1 ;
V_79 = 1 ;
}
if ( V_79 > 1 )
V_75 -> V_84 |= V_98 ;
else
V_75 -> V_84 |= V_99 ;
switch ( V_100 . V_101 ) {
case V_102 :
if ( V_20 -> V_103 )
V_75 -> V_84 |=
V_104 ;
else
V_75 -> V_84 |= V_105 ;
break;
case V_106 :
V_75 -> V_84 |= V_105 ;
break;
case V_107 :
V_75 -> V_84 |= V_108 ;
break;
case V_109 :
V_75 -> V_84 |= V_104 ;
break;
default:
break;
}
V_75 -> V_110 . V_111 =
F_11 ( V_112 << 0 |
V_112 << 2 |
V_113 << 4 |
V_113 << 6 |
V_113 << 8 |
V_113 << 10 |
V_113 << 12 |
V_113 << 14 ) ;
if ( V_78 == 1 || V_20 -> V_114 ) {
V_75 -> V_84 |= V_115 ;
V_75 -> V_110 . V_111 |=
F_11 ( V_113 << 2 ) ;
}
V_75 -> V_110 . V_116 = V_75 -> V_110 . V_111 ;
}
void F_12 ( struct V_1 * V_2 , const struct V_19 * V_20 ,
struct V_46 * V_47 , const T_5 * V_48 ,
T_4 V_76 , T_4 V_77 , bool V_49 ,
bool V_50 )
{
int V_51 ;
int V_117 = 0 ;
struct V_118 * V_119 ;
V_51 = F_5 ( V_2 , V_20 , V_47 , V_48 ,
V_49 , V_50 ) ;
V_119 = & V_47 -> V_120 [ V_70 ] ;
V_119 -> V_68 = V_70 ;
V_119 -> V_121 = & V_122 [ V_123 ] ;
V_119 -> V_124 = V_125 ;
V_117 += F_13 ( V_47 , V_119 , V_51 ,
V_70 ) ;
F_14 ( V_20 , V_47 , & V_119 -> V_126 , V_70 ,
V_76 , V_77 ) ;
V_119 = & V_47 -> V_120 [ V_69 ] ;
V_119 -> V_68 = V_69 ;
V_119 -> V_121 = & V_122 [ V_127 ] ;
V_119 -> V_124 = V_128 ;
V_117 += F_13 ( V_47 , V_119 , V_51 ,
V_69 ) ;
F_14 ( V_20 , V_47 , & V_119 -> V_126 , V_69 ,
V_76 , V_77 ) ;
if ( V_47 -> V_129 && ! V_100 . V_130 )
F_9 ( V_20 , V_47 , & V_119 -> V_75 ,
V_76 , V_77 ) ;
if ( V_51 != V_117 )
F_15 ( V_2 , L_4 ,
V_117 , V_51 ) ;
}
static int F_16 ( const struct V_19 * V_20 , const T_5 * V_131 ,
const T_5 * V_132 )
{
if ( V_20 -> V_24 != V_25 )
return F_17 ( V_131 + V_133 ) ;
return F_18 ( ( V_134 * ) ( V_132 + V_135 ) ) ;
}
static int F_19 ( const struct V_19 * V_20 , const T_5 * V_131 )
{
if ( V_20 -> V_24 != V_25 )
return F_17 ( V_131 + V_136 ) ;
else
return F_18 ( ( V_134 * ) ( V_131 +
V_137 ) ) ;
}
static int F_20 ( const struct V_19 * V_20 , const T_5 * V_131 ,
const T_5 * V_132 )
{
if ( V_20 -> V_24 != V_25 )
return F_17 ( V_131 + V_138 ) ;
return F_18 ( ( V_134 * ) ( V_132 + V_139 ) ) ;
}
static int F_21 ( const struct V_19 * V_20 , const T_5 * V_131 )
{
int V_140 ;
if ( V_20 -> V_24 != V_25 )
return F_17 ( V_131 + V_141 ) ;
V_140 = F_18 ( ( V_134 * ) ( V_131 + V_142 ) ) ;
return V_140 & V_143 ;
}
static void F_22 ( const struct V_19 * V_20 ,
struct V_46 * V_47 ,
T_1 V_144 )
{
if ( V_20 -> V_24 != V_25 ) {
V_47 -> V_145 = F_23 ( V_144 ) ;
V_47 -> V_146 = F_24 ( V_144 ) ;
V_47 -> V_147 = F_25 ( V_144 ) ;
V_47 -> V_148 = F_26 ( V_144 ) ;
return;
}
V_47 -> V_145 = F_27 ( V_144 ) ;
V_47 -> V_146 = F_28 ( V_144 ) ;
V_47 -> V_147 = F_29 ( V_144 ) ;
V_47 -> V_148 = F_30 ( V_144 ) ;
V_47 -> V_149 = F_31 ( V_144 ) ;
V_47 -> V_150 = F_32 ( V_144 ) ;
}
static void F_33 ( V_134 V_151 , V_134 V_152 , T_4 * V_153 )
{
const T_4 * V_154 ;
V_154 = ( const T_4 * ) & V_151 ;
V_153 [ 0 ] = V_154 [ 3 ] ;
V_153 [ 1 ] = V_154 [ 2 ] ;
V_153 [ 2 ] = V_154 [ 1 ] ;
V_153 [ 3 ] = V_154 [ 0 ] ;
V_154 = ( const T_4 * ) & V_152 ;
V_153 [ 4 ] = V_154 [ 1 ] ;
V_153 [ 5 ] = V_154 [ 0 ] ;
}
void F_34 ( struct V_155 * V_156 ,
struct V_46 * V_47 )
{
V_134 V_151 = F_35 ( F_36 ( V_156 , V_157 ) ) ;
V_134 V_152 = F_35 ( F_36 ( V_156 , V_158 ) ) ;
F_33 ( V_151 , V_152 , V_47 -> V_154 ) ;
if ( F_37 ( V_47 -> V_154 ) )
return;
V_151 = F_35 ( F_36 ( V_156 , V_159 ) ) ;
V_152 = F_35 ( F_36 ( V_156 , V_160 ) ) ;
F_33 ( V_151 , V_152 , V_47 -> V_154 ) ;
}
static void F_38 ( struct V_155 * V_156 ,
const struct V_19 * V_20 ,
struct V_46 * V_47 ,
const T_5 * V_161 ,
const T_6 * V_162 )
{
const T_4 * V_154 ;
if ( V_161 ) {
static const T_4 V_163 [] = {
0x02 , 0xcc , 0xaa , 0xff , 0xee , 0x00
} ;
V_154 = ( const T_4 * ) ( V_161 +
V_164 ) ;
memcpy ( V_47 -> V_154 , V_154 , V_165 ) ;
if ( F_37 ( V_47 -> V_154 ) &&
memcmp ( V_163 , V_154 , V_165 ) != 0 )
return;
F_39 ( V_156 ,
L_5 ) ;
}
if ( V_162 ) {
V_134 V_151 = F_35 ( F_40 ( V_156 ,
V_166 ) ) ;
V_134 V_152 = F_35 ( F_40 ( V_156 ,
V_167 ) ) ;
F_33 ( V_151 , V_152 , V_47 -> V_154 ) ;
return;
}
F_39 ( V_156 , L_6 ) ;
}
static int F_41 ( struct V_155 * V_156 ,
const struct V_19 * V_20 ,
struct V_46 * V_47 , const T_6 * V_162 ,
const T_5 * V_161 )
{
if ( V_20 -> V_168 ) {
F_34 ( V_156 , V_47 ) ;
} else if ( V_20 -> V_24 != V_25 ) {
const T_4 * V_154 = ( const T_4 * ) ( V_162 + V_169 ) ;
V_47 -> V_154 [ 0 ] = V_154 [ 1 ] ;
V_47 -> V_154 [ 1 ] = V_154 [ 0 ] ;
V_47 -> V_154 [ 2 ] = V_154 [ 3 ] ;
V_47 -> V_154 [ 3 ] = V_154 [ 2 ] ;
V_47 -> V_154 [ 4 ] = V_154 [ 5 ] ;
V_47 -> V_154 [ 5 ] = V_154 [ 4 ] ;
} else {
F_38 ( V_156 , V_20 , V_47 ,
V_161 , V_162 ) ;
}
if ( ! F_37 ( V_47 -> V_154 ) ) {
F_39 ( V_156 , L_7 ) ;
return - V_170 ;
}
F_42 ( V_156 , L_8 , V_47 -> V_154 ) ;
return 0 ;
}
static bool
F_43 ( struct V_1 * V_2 , const struct V_19 * V_20 ,
const T_6 * V_162 )
{
if ( V_20 -> V_171 == V_172 ) {
T_2 V_173 = F_44 ( V_162 + V_174 ) ;
T_4 V_175 = ( V_173 & 0x1e ) >> 1 ;
if ( V_175 == 5 || V_175 == 9 ) {
F_8 ( V_2 ,
L_9 ,
V_173 , V_175 ) ;
return true ;
}
}
return false ;
}
struct V_46 *
F_45 ( struct V_155 * V_156 , const struct V_19 * V_20 ,
const T_6 * V_162 , const T_5 * V_131 ,
const T_5 * V_176 , const T_5 * V_177 ,
const T_5 * V_161 , const T_5 * V_132 ,
T_4 V_76 , T_4 V_77 , bool V_178 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
struct V_46 * V_47 ;
bool V_179 ;
bool V_50 = F_43 ( V_2 , V_20 , V_162 ) ;
T_1 V_175 , V_144 ;
T_2 V_180 ;
const T_5 * V_181 ;
if ( V_20 -> V_24 != V_25 )
V_47 = F_46 ( sizeof( * V_47 ) +
sizeof( struct V_52 ) *
V_58 ,
V_182 ) ;
else
V_47 = F_46 ( sizeof( * V_47 ) +
sizeof( struct V_52 ) *
V_60 ,
V_182 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_183 = F_19 ( V_20 , V_131 ) ;
V_144 = F_20 ( V_20 , V_131 , V_132 ) ;
F_22 ( V_20 , V_47 , V_144 ) ;
if ( V_47 -> V_149 )
V_76 &= V_47 -> V_149 ;
if ( V_47 -> V_150 )
V_77 &= V_47 -> V_150 ;
V_175 = F_16 ( V_20 , V_131 , V_132 ) ;
V_47 -> V_184 = V_175 & V_185 ;
V_47 -> V_63 = V_175 & V_186 ;
V_47 -> V_187 = V_175 & V_188 ;
if ( V_100 . V_189 & V_190 )
V_47 -> V_187 = false ;
V_47 -> V_129 = V_47 -> V_187 &&
( V_175 & V_191 ) ;
V_47 -> V_97 = V_175 & V_192 ;
V_47 -> V_193 = F_21 ( V_20 , V_131 ) ;
if ( V_20 -> V_24 != V_25 ) {
if ( ! V_176 ) {
F_39 ( V_156 ,
L_10 ) ;
F_47 ( V_47 ) ;
return NULL ;
}
V_181 = V_20 -> V_24 == V_194 ?
& V_177 [ V_195 ] :
& V_131 [ V_196 ] ;
V_47 -> V_197 [ 0 ] = * ( V_176 + V_198 ) ;
V_47 -> V_197 [ 1 ] = * ( V_176 + V_198 + 1 ) ;
V_179 = true ;
} else {
T_2 V_199 = V_47 -> V_183 < 0xE39 ?
V_200 :
V_201 ;
V_180 = F_17 ( V_177 + V_199 ) ;
V_47 -> V_179 = ! ! ( V_180 &
V_202 ) ;
V_179 = V_47 -> V_179 ;
V_181 = & V_177 [ V_203 ] ;
}
if ( F_41 ( V_156 , V_20 , V_47 , V_162 , V_161 ) ) {
F_47 ( V_47 ) ;
return NULL ;
}
F_12 ( V_2 , V_20 , V_47 , V_181 , V_76 , V_77 ,
V_178 && V_179 , V_50 ) ;
V_47 -> V_204 = 255 ;
return V_47 ;
}
static T_1 F_48 ( const T_4 * V_57 ,
int V_16 , T_2 V_18 ,
const struct V_19 * V_20 )
{
T_1 V_5 = V_205 ;
T_1 V_22 = V_23 ;
if ( V_20 -> V_24 == V_25 )
V_22 = V_26 ;
if ( V_16 < V_32 &&
( V_18 & V_27 ) ) {
if ( V_57 [ V_16 ] <= V_28 )
V_5 &= ~ V_206 ;
if ( V_57 [ V_16 ] >= V_30 )
V_5 &= ~ V_207 ;
} else if ( V_57 [ V_16 ] <= V_22 &&
( V_18 & V_27 ) ) {
if ( ( V_16 - V_32 ) % 2 == 0 )
V_5 &= ~ V_206 ;
else
V_5 &= ~ V_207 ;
}
if ( ! ( V_18 & V_33 ) )
V_5 |= V_208 ;
if ( ! ( V_18 & V_35 ) )
V_5 |= V_209 ;
if ( ! ( V_18 & V_39 ) )
V_5 |= V_210 ;
if ( V_18 & V_40 )
V_5 |= V_211 ;
if ( V_18 & V_42 )
V_5 |= V_212 ;
if ( ( V_18 & V_44 ) &&
( V_5 & V_210 ) )
V_5 |= V_213 ;
return V_5 ;
}
struct V_214 *
F_49 ( struct V_1 * V_2 , const struct V_19 * V_20 ,
int V_55 , V_134 * V_66 , T_2 V_215 )
{
int V_16 ;
T_2 V_54 ;
T_1 V_216 , V_217 = 0 ;
const T_4 * V_57 = V_20 -> V_24 == V_25 ?
V_61 : V_59 ;
struct V_214 * V_218 ;
int V_219 ;
struct V_220 * V_221 ;
enum V_222 V_68 ;
int V_71 , V_223 = 0 ;
int V_224 = 0 ;
bool V_225 ;
int V_226 = V_20 -> V_24 == V_25 ?
V_60 : V_58 ;
if ( F_50 ( V_55 > V_227 ) )
return F_51 ( - V_170 ) ;
if ( F_52 ( V_55 > V_226 ) )
V_55 = V_226 ;
F_3 ( V_2 , V_228 , L_11 ,
V_55 ) ;
V_219 =
sizeof( struct V_214 ) +
V_55 * sizeof( struct V_220 ) ;
V_218 = F_46 ( V_219 , V_182 ) ;
if ( ! V_218 )
return F_51 ( - V_229 ) ;
for ( V_16 = 0 ; V_16 < V_55 ; V_16 ++ ) {
V_54 = ( T_2 ) F_53 ( V_66 + V_16 ) ;
V_68 = ( V_16 < V_32 ) ?
V_70 : V_69 ;
V_71 = F_7 ( V_57 [ V_16 ] ,
V_68 ) ;
V_225 = false ;
if ( ! ( V_54 & V_6 ) ) {
F_1 ( V_2 , V_228 ,
V_57 [ V_16 ] , V_54 ) ;
continue;
}
V_216 = F_48 ( V_57 , V_16 ,
V_54 , V_20 ) ;
if ( V_16 == 0 || V_217 != V_216 ||
V_71 - V_223 > 20 ) {
V_224 ++ ;
V_225 = true ;
}
V_221 = & V_218 -> V_230 [ V_224 - 1 ] ;
if ( V_225 )
V_221 -> V_231 . V_232 =
F_54 ( V_71 - 10 ) ;
V_221 -> V_231 . V_233 = F_54 ( V_71 + 10 ) ;
V_221 -> V_234 . V_235 = F_55 ( 6 ) ;
V_221 -> V_234 . V_236 =
F_56 ( V_73 ) ;
V_221 -> V_5 = V_216 ;
V_221 -> V_5 |= V_237 ;
V_221 -> V_231 . V_238 = 0 ;
V_223 = V_71 ;
V_217 = V_216 ;
F_1 ( V_2 , V_228 ,
V_57 [ V_16 ] , V_54 ) ;
}
V_218 -> V_239 = V_224 ;
V_218 -> V_240 [ 0 ] = V_215 >> 8 ;
V_218 -> V_240 [ 1 ] = V_215 & 0xff ;
return V_218 ;
}
static T_1 F_57 ( struct V_1 * V_2 , union V_241 * V_242 )
{
union V_241 * V_243 , * V_244 , * V_245 ;
T_1 V_246 ;
if ( V_242 -> type != V_247 ||
V_242 -> V_248 . V_249 < 2 ||
V_242 -> V_248 . V_250 [ 0 ] . type != V_251 ||
V_242 -> V_248 . V_250 [ 0 ] . integer . V_252 != 0 ) {
F_8 ( V_2 , L_12 ) ;
return 0 ;
}
for ( V_246 = 1 ; V_246 < V_242 -> V_248 . V_249 ; ++ V_246 ) {
V_243 = & V_242 -> V_248 . V_250 [ V_246 ] ;
if ( V_243 -> type != V_247 ||
V_243 -> V_248 . V_249 < 2 ||
V_243 -> V_248 . V_250 [ 0 ] . type != V_251 ||
V_243 -> V_248 . V_250 [ 1 ] . type != V_251 ) {
V_243 = NULL ;
continue;
}
V_244 = & V_243 -> V_248 . V_250 [ 0 ] ;
if ( V_244 -> integer . V_252 == V_253 )
break;
V_243 = NULL ;
}
if ( V_243 ) {
V_245 = & V_243 -> V_248 . V_250 [ 1 ] ;
return V_245 -> integer . V_252 ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_2 , char * V_254 )
{
T_7 V_255 ;
T_7 V_256 ;
struct V_257 V_242 = { V_258 , NULL } ;
T_8 V_259 ;
T_1 V_260 ;
V_255 = F_59 ( V_2 ) ;
if ( ! V_255 ) {
F_8 ( V_2 ,
L_13 ) ;
return - V_261 ;
}
V_259 = F_60 ( V_255 , ( V_262 ) V_263 ,
& V_256 ) ;
if ( F_61 ( V_259 ) ) {
F_8 ( V_2 , L_14 ) ;
return - V_261 ;
}
V_259 = F_62 ( V_256 , NULL , NULL , & V_242 ) ;
if ( F_61 ( V_259 ) ) {
F_8 ( V_2 , L_15 ,
V_259 ) ;
return - V_261 ;
}
V_260 = F_57 ( V_2 , V_242 . V_264 ) ;
F_47 ( V_242 . V_264 ) ;
if ( ! V_260 )
return - V_261 ;
V_254 [ 0 ] = ( V_260 >> 8 ) & 0xff ;
V_254 [ 1 ] = V_260 & 0xff ;
V_254 [ 2 ] = '\0' ;
return 0 ;
}
