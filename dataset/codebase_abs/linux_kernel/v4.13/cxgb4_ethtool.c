static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
F_2 ( V_2 ) -> V_3 = V_4 ;
}
static int F_4 ( struct V_1 * V_2 , int V_5 )
{
switch ( V_5 ) {
case V_6 :
return F_5 ( V_7 ) +
F_5 ( V_8 ) +
F_5 ( V_9 ) +
F_5 ( V_10 ) ;
default:
return - V_11 ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_2 ( V_2 ) ;
return F_7 ( V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return V_14 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_12 * V_12 = F_2 ( V_2 ) ;
T_1 V_17 ;
F_10 ( V_16 -> V_18 , V_19 , sizeof( V_16 -> V_18 ) ) ;
F_10 ( V_16 -> V_20 , V_21 ,
sizeof( V_16 -> V_20 ) ) ;
F_10 ( V_16 -> V_22 , F_11 ( V_12 -> V_23 ) ,
sizeof( V_16 -> V_22 ) ) ;
V_16 -> V_24 = F_6 ( V_2 ) ;
if ( ! V_12 -> V_25 . V_26 )
strcpy ( V_16 -> V_27 , L_1 ) ;
else
snprintf ( V_16 -> V_27 , sizeof( V_16 -> V_27 ) ,
L_2 ,
F_12 ( V_12 -> V_25 . V_26 ) ,
F_13 ( V_12 -> V_25 . V_26 ) ,
F_14 ( V_12 -> V_25 . V_26 ) ,
F_15 ( V_12 -> V_25 . V_26 ) ,
F_12 ( V_12 -> V_25 . V_28 ) ,
F_13 ( V_12 -> V_25 . V_28 ) ,
F_14 ( V_12 -> V_25 . V_28 ) ,
F_15 ( V_12 -> V_25 . V_28 ) ) ;
if ( ! F_16 ( V_12 , & V_17 ) )
snprintf ( V_16 -> V_29 , sizeof( V_16 -> V_29 ) ,
L_3 ,
F_12 ( V_17 ) ,
F_13 ( V_17 ) ,
F_14 ( V_17 ) ,
F_15 ( V_17 ) ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_30 , T_2 * V_31 )
{
if ( V_30 == V_6 ) {
memcpy ( V_31 , V_7 , sizeof( V_7 ) ) ;
V_31 += sizeof( V_7 ) ;
memcpy ( V_31 , V_8 ,
sizeof( V_8 ) ) ;
V_31 += sizeof( V_8 ) ;
memcpy ( V_31 , V_9 ,
sizeof( V_9 ) ) ;
V_31 += sizeof( V_9 ) ;
memcpy ( V_31 , V_10 ,
sizeof( V_10 ) ) ;
}
}
static void F_18 ( const struct V_12 * V_13 ,
const struct V_32 * V_33 ,
struct V_34 * V_35 )
{
int V_36 ;
const struct V_37 * V_38 = & V_13 -> V_39 . V_40 [ V_33 -> V_41 ] ;
const struct V_42 * V_43 = & V_13 -> V_39 . V_44 [ V_33 -> V_41 ] ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
for ( V_36 = 0 ; V_36 < V_33 -> V_45 ; V_36 ++ , V_43 ++ , V_38 ++ ) {
V_35 -> V_46 += V_38 -> V_46 ;
V_35 -> V_47 += V_38 -> V_48 ;
V_35 -> V_49 += V_43 -> V_50 . V_51 ;
V_35 -> V_52 += V_43 -> V_50 . V_52 ;
V_35 -> V_53 += V_38 -> V_53 ;
V_35 -> V_54 += V_43 -> V_50 . V_55 ;
V_35 -> V_56 += V_43 -> V_50 . V_57 ;
}
}
static void F_19 ( struct V_12 * V_13 , struct V_58 * V_35 )
{
struct V_59 V_60 , V_61 ;
struct V_62 V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
T_3 V_68 , V_69 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
F_20 ( & V_13 -> V_70 ) ;
F_21 ( V_13 , & V_60 , & V_61 ) ;
F_22 ( V_13 , & V_63 ) ;
F_23 ( V_13 , & V_67 ) ;
F_24 ( V_13 , & V_65 ) ;
F_25 ( & V_13 -> V_70 ) ;
V_35 -> V_71 = V_13 -> V_72 . V_71 ;
V_35 -> V_73 = V_13 -> V_72 . V_73 ;
V_35 -> V_74 = V_13 -> V_72 . V_74 ;
V_35 -> V_75 = V_60 . V_76 ;
V_35 -> V_77 = V_60 . V_78 ;
V_35 -> V_79 = V_60 . V_80 ;
V_35 -> V_81 = V_60 . V_82 ;
V_35 -> V_83 = V_61 . V_76 ;
V_35 -> V_84 = V_61 . V_78 ;
V_35 -> V_85 = V_61 . V_80 ;
V_35 -> V_86 = V_61 . V_82 ;
if ( F_26 ( V_13 ) ) {
V_35 -> V_87 = V_67 . V_87 ;
V_35 -> V_88 = V_67 . V_88 ;
V_35 -> V_89 = V_67 . V_89 ;
V_35 -> V_90 = V_63 . V_90 ;
V_35 -> V_91 = V_63 . V_91 ;
}
V_35 -> V_92 = V_65 . V_92 ;
V_35 -> V_93 = V_65 . V_93 ;
if ( ! F_27 ( V_13 -> V_25 . V_94 ) ) {
int V_95 ;
V_95 = F_28 ( V_13 , V_96 ) ;
if ( F_29 ( V_95 ) == 7 ) {
V_69 = F_28 ( V_13 , V_97 ) ;
V_68 = F_28 ( V_13 , V_98 ) ;
V_35 -> V_99 = V_68 - V_69 ;
V_35 -> V_100 = V_69 ;
}
}
}
static void F_30 ( struct V_12 * V_13 , struct V_101 * V_35 ,
T_2 V_36 )
{
struct V_102 V_103 ;
struct V_64 V_65 ;
struct V_104 V_105 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
F_20 ( & V_13 -> V_70 ) ;
F_31 ( V_13 , & V_103 ) ;
F_24 ( V_13 , & V_65 ) ;
F_32 ( V_13 , V_36 , & V_105 ) ;
F_25 ( & V_13 -> V_70 ) ;
V_35 -> V_106 = V_103 . V_107 [ V_36 ] ;
V_35 -> V_108 = V_103 . V_109 [ V_36 ] ;
V_35 -> V_110 = V_65 . V_110 [ V_36 ] ;
V_35 -> V_111 = V_65 . V_111 [ V_36 ] ;
V_35 -> V_112 = V_65 . V_112 [ V_36 ] ;
V_35 -> V_113 = V_65 . V_113 [ V_36 ] ;
V_35 -> V_114 = V_65 . V_114 [ V_36 ] ;
V_35 -> V_115 = V_65 . V_115 [ V_36 ] ;
V_35 -> V_116 = V_65 . V_116 [ V_36 ] ;
V_35 -> V_117 = V_65 . V_117 [ V_36 ] ;
V_35 -> V_118 = V_105 . V_118 ;
V_35 -> V_119 = V_105 . V_119 ;
V_35 -> V_120 = V_105 . V_120 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_121 * V_50 ,
T_3 * V_31 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_122 -> V_12 ;
struct V_123 V_35 ;
int V_36 ;
T_3 * V_124 ;
F_35 ( V_12 , V_122 -> V_125 ,
(struct V_126 * ) V_31 ,
& V_122 -> V_127 ) ;
V_31 += sizeof( struct V_126 ) / sizeof( T_3 ) ;
F_18 ( V_12 , V_122 , (struct V_34 * ) V_31 ) ;
V_31 += sizeof( struct V_34 ) / sizeof( T_3 ) ;
F_19 ( V_12 , (struct V_58 * ) V_31 ) ;
V_31 += sizeof( struct V_58 ) / sizeof( T_3 ) ;
* V_31 ++ = ( T_3 ) V_122 -> V_128 ;
F_30 ( V_12 , (struct V_101 * ) V_31 ,
V_122 -> V_128 ) ;
V_31 += sizeof( struct V_101 ) / sizeof( T_3 ) ;
* V_31 ++ = ( T_3 ) V_122 -> V_128 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
F_36 ( V_12 , V_122 -> V_128 , & V_35 ) ;
V_124 = & V_35 . V_88 ;
for ( V_36 = 0 ; V_36 < F_5 ( V_10 ) - 1 ; V_36 ++ )
* V_31 ++ = ( unsigned long long ) * V_124 ++ ;
}
static void F_37 ( struct V_1 * V_2 , struct V_129 * V_130 ,
void * V_131 )
{
struct V_12 * V_13 = F_2 ( V_2 ) ;
T_4 V_132 ;
V_132 = F_7 ( V_13 ) ;
V_130 -> V_20 = F_38 ( V_13 ) ;
F_39 ( V_13 , V_131 , V_132 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
if ( ! F_41 ( V_2 ) )
return - V_133 ;
if ( V_33 -> V_134 . V_135 != V_136 )
return - V_137 ;
F_42 ( V_33 -> V_12 , V_33 -> V_12 -> V_138 , V_33 -> V_125 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
enum V_139 V_140 )
{
unsigned int V_4 ;
struct V_12 * V_13 = F_2 ( V_2 ) ;
if ( V_140 == V_141 )
V_4 = 0xffff ;
else if ( V_140 == V_142 )
V_4 = 0 ;
else
return - V_137 ;
return F_44 ( V_13 , V_13 -> V_138 , F_45 ( V_2 ) -> V_143 , V_4 ) ;
}
static int F_46 ( enum V_144 V_145 ,
enum V_146 V_147 )
{
if ( V_145 == V_148 ||
V_145 == V_149 ||
V_145 == V_150 ) {
return V_151 ;
} else if ( V_145 == V_152 ||
V_145 == V_153 ) {
return V_154 ;
} else if ( V_145 == V_155 ||
V_145 == V_156 ||
V_145 == V_157 ||
V_145 == V_158 ||
V_145 == V_159 ||
V_145 == V_160 ||
V_145 == V_161 ||
V_145 == V_162 ) {
if ( V_147 == V_163 ||
V_147 == V_164 ||
V_147 == V_165 ||
V_147 == V_166 )
return V_154 ;
else if ( V_147 == V_167 ||
V_147 == V_168 )
return V_169 ;
else
return V_170 ;
} else if ( V_145 == V_171 ||
V_145 == V_172 ) {
return V_173 ;
}
return V_170 ;
}
static unsigned int F_47 ( int V_174 )
{
if ( V_174 == 100 )
return V_175 ;
if ( V_174 == 1000 )
return V_176 ;
if ( V_174 == 10000 )
return V_177 ;
if ( V_174 == 25000 )
return V_178 ;
if ( V_174 == 40000 )
return V_179 ;
if ( V_174 == 100000 )
return V_180 ;
return 0 ;
}
static void F_48 ( enum V_144 V_145 ,
unsigned int V_181 ,
unsigned long * V_182 )
{
#define F_49 ( T_5 ) __set_bit(ETHTOOL_LINK_MODE_ ## __lmm_name \
## _BIT, link_mode_mask)
#define F_50 ( T_6 , T_5 ) \
do { \
if (fw_caps & FW_PORT_CAP_ ## __fw_name) \
SET_LMM(__lmm_name); \
} while (0)
switch ( V_145 ) {
case V_148 :
case V_149 :
case V_150 :
F_49 ( V_183 ) ;
F_50 ( V_184 , 100baseT_Full ) ;
F_50 ( V_185 , 1000baseT_Full ) ;
F_50 ( V_186 , 10000baseT_Full ) ;
break;
case V_187 :
case V_188 :
F_49 ( V_189 ) ;
F_50 ( V_185 , 1000baseKX_Full ) ;
F_50 ( V_186 , 10000baseKX4_Full ) ;
break;
case V_190 :
F_49 ( V_189 ) ;
F_49 ( 10000baseKR_Full ) ;
break;
case V_191 :
F_49 ( V_189 ) ;
F_49 ( 10000baseR_FEC ) ;
F_49 ( 10000baseKR_Full ) ;
F_49 ( 1000baseKX_Full ) ;
break;
case V_192 :
F_49 ( V_189 ) ;
F_49 ( 10000baseR_FEC ) ;
F_49 ( 10000baseKR_Full ) ;
F_49 ( 1000baseKX_Full ) ;
F_49 ( 10000baseKX4_Full ) ;
break;
case V_152 :
case V_153 :
case V_155 :
case V_156 :
case V_157 :
F_49 ( V_193 ) ;
F_50 ( V_185 , 1000baseT_Full ) ;
F_50 ( V_186 , 10000baseT_Full ) ;
break;
case V_194 :
case V_158 :
F_49 ( V_193 ) ;
F_49 ( 40000baseSR4_Full ) ;
break;
case V_160 :
case V_162 :
F_49 ( V_193 ) ;
F_50 ( V_185 , 1000baseT_Full ) ;
F_50 ( V_186 , 10000baseT_Full ) ;
F_50 ( V_195 , 25000baseCR_Full ) ;
break;
case V_172 :
F_49 ( V_189 ) ;
F_50 ( V_185 , 1000baseT_Full ) ;
F_50 ( V_186 , 10000baseKR_Full ) ;
F_50 ( V_195 , 25000baseKR_Full ) ;
break;
case V_161 :
F_49 ( V_193 ) ;
F_49 ( 50000baseSR2_Full ) ;
break;
case V_171 :
case V_159 :
F_49 ( V_193 ) ;
F_49 ( 100000baseCR4_Full ) ;
break;
default:
break;
}
F_50 ( V_196 , V_197 ) ;
F_50 ( 802_3_PAUSE , V_198 ) ;
F_50 ( 802_3_ASM_DIR , V_199 ) ;
#undef F_50
#undef F_49
}
static unsigned int F_51 ( const unsigned long * V_182 )
{
unsigned int V_181 = 0 ;
#define F_52 ( T_5 , T_6 ) \
do { \
if (test_bit(ETHTOOL_LINK_MODE_ ## __lmm_name ## _BIT, \
link_mode_mask)) \
fw_caps |= FW_PORT_CAP_ ## __fw_name; \
} while (0)
F_52 ( 100baseT_Full , V_184 ) ;
F_52 ( 1000baseT_Full , V_185 ) ;
F_52 ( 10000baseT_Full , V_186 ) ;
F_52 ( 40000baseSR4_Full , V_200 ) ;
F_52 ( 25000baseCR_Full , V_195 ) ;
F_52 ( 100000baseCR4_Full , V_201 ) ;
#undef F_52
return V_181 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_202 * V_203 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_204 * V_205 = & V_203 -> V_205 ;
F_54 ( V_203 , V_206 ) ;
F_54 ( V_203 , V_207 ) ;
F_54 ( V_203 , V_208 ) ;
if ( ! F_41 ( V_2 ) )
( void ) F_55 ( V_122 ) ;
V_205 -> V_209 = F_46 ( V_122 -> V_145 , V_122 -> V_147 ) ;
if ( V_122 -> V_210 >= 0 ) {
V_205 -> V_211 = V_122 -> V_210 ;
V_205 -> V_212 = ( V_122 -> V_145 == V_148
? V_213
: V_214 ) ;
} else {
V_205 -> V_211 = 255 ;
V_205 -> V_212 = 0 ;
}
F_48 ( V_122 -> V_145 , V_122 -> V_134 . V_206 ,
V_203 -> V_215 . V_206 ) ;
F_48 ( V_122 -> V_145 , V_122 -> V_134 . V_207 ,
V_203 -> V_215 . V_207 ) ;
F_48 ( V_122 -> V_145 , V_122 -> V_134 . V_208 ,
V_203 -> V_215 . V_208 ) ;
if ( F_56 ( V_2 ) ) {
V_205 -> V_174 = V_122 -> V_134 . V_174 ;
V_205 -> V_216 = V_217 ;
} else {
V_205 -> V_174 = V_218 ;
V_205 -> V_216 = V_219 ;
}
V_205 -> V_135 = V_122 -> V_134 . V_135 ;
if ( V_122 -> V_134 . V_206 & V_220 )
F_57 ( V_203 ,
V_206 , V_197 ) ;
if ( V_122 -> V_134 . V_135 )
F_57 ( V_203 ,
V_207 , V_197 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
const struct V_202
* V_203 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_221 * V_222 = & V_122 -> V_134 ;
const struct V_204 * V_205 = & V_203 -> V_205 ;
struct V_221 V_223 ;
unsigned int V_181 ;
int V_224 = 0 ;
if ( V_205 -> V_216 != V_217 )
return - V_137 ;
if ( ! ( V_222 -> V_206 & V_220 ) ) {
if ( V_205 -> V_135 == V_225 &&
( V_222 -> V_206 & F_47 ( V_205 -> V_174 ) ) )
return 0 ;
return - V_137 ;
}
V_223 = * V_222 ;
if ( V_205 -> V_135 == V_225 ) {
V_181 = F_47 ( V_205 -> V_174 ) ;
if ( ! ( V_222 -> V_206 & V_181 ) )
return - V_137 ;
V_222 -> V_226 = V_181 ;
V_222 -> V_207 = 0 ;
} else {
V_181 =
F_51 ( V_203 -> V_215 . V_207 ) ;
if ( ! ( V_222 -> V_206 & V_181 ) )
return - V_137 ;
V_222 -> V_226 = 0 ;
V_222 -> V_207 = V_181 | V_220 ;
}
V_222 -> V_135 = V_205 -> V_135 ;
V_224 = F_59 ( V_122 -> V_12 , V_122 -> V_12 -> V_227 , V_122 -> V_125 , V_222 ) ;
if ( V_224 )
* V_222 = V_223 ;
return V_224 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_228 * V_229 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
V_229 -> V_135 = ( V_33 -> V_134 . V_230 & V_231 ) != 0 ;
V_229 -> V_232 = ( V_33 -> V_134 . V_233 & V_234 ) != 0 ;
V_229 -> V_235 = ( V_33 -> V_134 . V_233 & V_236 ) != 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_228 * V_229 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
struct V_221 * V_222 = & V_33 -> V_134 ;
if ( V_229 -> V_135 == V_225 )
V_222 -> V_230 = 0 ;
else if ( V_222 -> V_206 & V_220 )
V_222 -> V_230 = V_231 ;
else
return - V_137 ;
if ( V_229 -> V_232 )
V_222 -> V_230 |= V_234 ;
if ( V_229 -> V_235 )
V_222 -> V_230 |= V_236 ;
if ( F_41 ( V_2 ) )
return F_59 ( V_33 -> V_12 , V_33 -> V_12 -> V_227 , V_33 -> V_125 ,
V_222 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 , struct V_237 * V_238 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
const struct V_39 * V_35 = & V_122 -> V_12 -> V_39 ;
V_238 -> V_239 = V_240 ;
V_238 -> V_241 = V_242 ;
V_238 -> V_243 = 0 ;
V_238 -> V_244 = V_245 ;
V_238 -> V_246 = V_35 -> V_44 [ V_122 -> V_41 ] . V_247 . V_248 - 8 ;
V_238 -> V_249 = V_35 -> V_44 [ V_122 -> V_41 ] . V_250 . V_248 ;
V_238 -> V_251 = 0 ;
V_238 -> V_252 = V_35 -> V_40 [ V_122 -> V_41 ] . V_253 . V_248 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_237 * V_238 )
{
int V_36 ;
const struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_122 -> V_12 ;
struct V_39 * V_35 = & V_12 -> V_39 ;
if ( V_238 -> V_246 > V_240 || V_238 -> V_251 ||
V_238 -> V_252 > V_245 ||
V_238 -> V_249 > V_242 ||
V_238 -> V_249 < V_254 ||
V_238 -> V_246 < V_255 || V_238 -> V_252 < V_256 )
return - V_137 ;
if ( V_12 -> V_257 & V_258 )
return - V_259 ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; ++ V_36 ) {
V_35 -> V_40 [ V_122 -> V_41 + V_36 ] . V_253 . V_248 = V_238 -> V_252 ;
V_35 -> V_44 [ V_122 -> V_41 + V_36 ] . V_247 . V_248 = V_238 -> V_246 + 8 ;
V_35 -> V_44 [ V_122 -> V_41 + V_36 ] . V_250 . V_248 = V_238 -> V_249 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
unsigned int V_260 , unsigned int V_261 )
{
int V_36 , V_262 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_253 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; V_36 ++ , V_253 ++ ) {
V_262 = F_65 ( & V_253 -> V_250 , V_260 , V_261 ) ;
if ( V_262 )
return V_262 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , int V_263 )
{
int V_36 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_253 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; V_36 ++ , V_253 ++ )
V_253 -> V_250 . V_263 = V_263 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_253 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
return V_253 -> V_250 . V_263 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_264 * V_265 )
{
F_66 ( V_2 , V_265 -> V_266 ) ;
return F_64 ( V_2 , V_265 -> V_267 ,
V_265 -> V_268 ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_264 * V_265 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
const struct V_12 * V_13 = V_122 -> V_12 ;
const struct V_269 * V_270 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] . V_250 ;
V_265 -> V_267 = F_70 ( V_13 , V_270 ) ;
V_265 -> V_268 = ( V_270 -> V_271 & V_272 ) ?
V_13 -> V_39 . V_273 [ V_270 -> V_274 ] : 0 ;
V_265 -> V_266 = F_67 ( V_2 ) ;
return 0 ;
}
static int F_71 ( unsigned int V_275 , unsigned int V_276 , unsigned int V_277 )
{
V_276 *= V_277 ;
if ( V_275 < 1024 )
return V_275 + ( 31 << 10 ) ;
if ( V_275 < 1024 + V_276 )
return 31744 - V_276 + V_275 - 1024 ;
if ( V_275 < V_14 )
return V_275 - 1024 - V_276 ;
return - V_137 ;
}
static int F_72 ( struct V_12 * V_13 , unsigned int V_275 , T_1 * V_95 )
{
int V_278 = F_71 ( V_275 , V_13 -> V_138 , V_279 ) ;
if ( V_278 >= 0 )
V_278 = F_73 ( V_13 -> V_23 , V_278 , sizeof( T_1 ) , V_95 ) ;
return V_278 < 0 ? V_278 : 0 ;
}
static int F_74 ( struct V_12 * V_13 , unsigned int V_275 , T_1 V_95 )
{
int V_278 = F_71 ( V_275 , V_13 -> V_138 , V_279 ) ;
if ( V_278 >= 0 )
V_278 = F_75 ( V_13 -> V_23 , V_278 , sizeof( T_1 ) , & V_95 ) ;
return V_278 < 0 ? V_278 : 0 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_280 * V_238 ,
T_2 * V_31 )
{
int V_36 , V_262 = 0 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
T_2 * V_131 = F_77 ( V_14 , V_281 ) ;
if ( ! V_131 )
return - V_282 ;
V_238 -> V_283 = V_284 ;
for ( V_36 = V_238 -> V_285 & ~ 3 ; ! V_262 && V_36 < V_238 -> V_285 + V_238 -> V_286 ; V_36 += 4 )
V_262 = F_72 ( V_12 , V_36 , ( T_1 * ) & V_131 [ V_36 ] ) ;
if ( ! V_262 )
memcpy ( V_31 , V_131 + V_238 -> V_285 , V_238 -> V_286 ) ;
F_78 ( V_131 ) ;
return V_262 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_280 * V_287 ,
T_2 * V_31 )
{
T_2 * V_131 ;
int V_262 = 0 ;
T_1 V_288 , V_289 , * V_33 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
if ( V_287 -> V_283 != V_284 )
return - V_137 ;
V_288 = V_287 -> V_285 & ~ 3 ;
V_289 = ( V_287 -> V_286 + ( V_287 -> V_285 & 3 ) + 3 ) & ~ 3 ;
if ( V_12 -> V_138 > 0 ) {
T_1 V_290 = 1024 + V_12 -> V_138 * V_279 ;
if ( V_288 < V_290 ||
V_288 + V_289 > V_290 + V_279 )
return - V_291 ;
}
if ( V_288 != V_287 -> V_285 || V_289 != V_287 -> V_286 ) {
V_131 = F_77 ( V_289 , V_281 ) ;
if ( ! V_131 )
return - V_282 ;
V_262 = F_72 ( V_12 , V_288 , ( T_1 * ) V_131 ) ;
if ( ! V_262 && V_289 > 4 )
V_262 = F_72 ( V_12 ,
V_288 + V_289 - 4 ,
( T_1 * ) & V_131 [ V_289 - 4 ] ) ;
if ( V_262 )
goto V_292;
memcpy ( V_131 + ( V_287 -> V_285 & 3 ) , V_31 , V_287 -> V_286 ) ;
} else {
V_131 = V_31 ;
}
V_262 = F_80 ( V_12 , false ) ;
if ( V_262 )
goto V_292;
for ( V_33 = ( T_1 * ) V_131 ; ! V_262 && V_289 ; V_289 -= 4 , V_33 ++ ) {
V_262 = F_74 ( V_12 , V_288 , * V_33 ) ;
V_288 += 4 ;
}
if ( ! V_262 )
V_262 = F_80 ( V_12 , true ) ;
V_292:
if ( V_131 != V_31 )
F_78 ( V_131 ) ;
return V_262 ;
}
static int F_81 ( struct V_1 * V_293 , struct V_294 * V_295 )
{
int V_224 ;
const struct V_296 * V_297 ;
struct V_12 * V_13 = F_2 ( V_293 ) ;
unsigned int V_227 = V_298 + 1 ;
T_1 V_299 ;
unsigned int V_300 ;
T_2 V_301 = 0 ;
V_299 = F_28 ( V_13 , V_302 ) ;
V_300 = F_82 ( V_299 ) ;
if ( V_299 & V_303 )
V_301 = 1 ;
if ( V_301 && ( V_300 != V_13 -> V_138 ) ) {
F_83 ( V_13 -> V_304 ,
L_4 ) ;
return - V_11 ;
}
V_295 -> V_31 [ sizeof( V_295 -> V_31 ) - 1 ] = '\0' ;
V_224 = F_84 ( & V_297 , V_295 -> V_31 , V_13 -> V_304 ) ;
if ( V_224 < 0 )
return V_224 ;
if ( V_13 -> V_257 & V_258 )
V_227 = V_13 -> V_227 ;
V_224 = F_85 ( V_13 , V_227 , V_297 -> V_31 , V_297 -> V_248 , 1 ) ;
F_86 ( V_297 ) ;
if ( ! V_224 )
F_87 ( V_13 -> V_304 ,
L_5 , V_295 -> V_31 ) ;
return V_224 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_305 * V_306 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_122 -> V_12 ;
V_306 -> V_307 = V_308 |
V_309 |
V_310 ;
V_306 -> V_307 |= V_311 |
V_312 |
V_313 ;
V_306 -> V_314 = ( 1 << V_315 ) |
( 1 << V_316 ) ;
V_306 -> V_317 = ( 1 << V_318 ) |
( 1 << V_319 ) |
( 1 << V_320 ) |
( 1 << V_321 ) |
( 1 << V_322 ) |
( 1 << V_323 ) ;
if ( V_12 -> V_324 )
V_306 -> V_325 = F_89 ( V_12 -> V_324 ) ;
else
V_306 -> V_325 = - 1 ;
return 0 ;
}
static T_1 F_90 ( struct V_1 * V_2 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
return V_122 -> V_326 ;
}
static int F_91 ( struct V_1 * V_2 , T_1 * V_33 , T_2 * V_327 , T_2 * V_328 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
unsigned int V_329 = V_122 -> V_326 ;
if ( V_328 )
* V_328 = V_330 ;
if ( ! V_33 )
return 0 ;
while ( V_329 -- )
V_33 [ V_329 ] = V_122 -> V_331 [ V_329 ] ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , const T_1 * V_33 , const T_2 * V_327 ,
const T_2 V_328 )
{
unsigned int V_36 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
if ( V_327 ||
( V_328 != V_332 && V_328 != V_330 ) )
return - V_11 ;
if ( ! V_33 )
return 0 ;
if ( V_122 -> V_12 -> V_257 & V_258 ) {
for ( V_36 = 0 ; V_36 < V_122 -> V_326 ; V_36 ++ )
V_122 -> V_331 [ V_36 ] = V_33 [ V_36 ] ;
return F_93 ( V_122 , V_122 -> V_331 ) ;
}
return - V_291 ;
}
static int F_94 ( struct V_1 * V_2 , struct V_333 * V_16 ,
T_1 * V_334 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
switch ( V_16 -> V_335 ) {
case V_336 : {
unsigned int V_95 = V_122 -> V_337 ;
V_16 -> V_31 = 0 ;
switch ( V_16 -> V_338 ) {
case V_339 :
if ( V_95 & V_340 )
V_16 -> V_31 = V_341 | V_342 |
V_343 | V_344 ;
else if ( V_95 & V_345 )
V_16 -> V_31 = V_341 | V_342 ;
break;
case V_346 :
if ( ( V_95 & V_340 ) &&
( V_95 & V_347 ) )
V_16 -> V_31 = V_341 | V_342 |
V_343 | V_344 ;
else if ( V_95 & V_345 )
V_16 -> V_31 = V_341 | V_342 ;
break;
case V_348 :
case V_349 :
case V_350 :
if ( V_95 & V_345 )
V_16 -> V_31 = V_341 | V_342 ;
break;
case V_351 :
if ( V_95 & V_352 )
V_16 -> V_31 = V_341 | V_342 |
V_343 | V_344 ;
else if ( V_95 & V_353 )
V_16 -> V_31 = V_341 | V_342 ;
break;
case V_354 :
if ( ( V_95 & V_352 ) &&
( V_95 & V_347 ) )
V_16 -> V_31 = V_341 | V_342 |
V_343 | V_344 ;
else if ( V_95 & V_353 )
V_16 -> V_31 = V_341 | V_342 ;
break;
case V_355 :
case V_356 :
case V_357 :
if ( V_95 & V_353 )
V_16 -> V_31 = V_341 | V_342 ;
break;
}
return 0 ;
}
case V_358 :
V_16 -> V_31 = V_122 -> V_45 ;
return 0 ;
}
return - V_11 ;
}
void F_95 ( struct V_1 * V_293 )
{
V_293 -> V_359 = & V_360 ;
}
