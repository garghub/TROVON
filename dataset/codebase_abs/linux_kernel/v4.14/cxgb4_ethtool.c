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
if ( V_174 == 50000 )
return V_180 ;
if ( V_174 == 100000 )
return V_181 ;
if ( V_174 == 200000 )
return V_182 ;
if ( V_174 == 400000 )
return V_183 ;
return 0 ;
}
static void F_48 ( enum V_144 V_145 ,
unsigned int V_184 ,
unsigned long * V_185 )
{
#define F_49 ( T_5 ) \
__set_bit(ETHTOOL_LINK_MODE_ ## __lmm_name ## _BIT, \
link_mode_mask)
#define F_50 ( T_6 , T_5 ) \
do { \
if (fw_caps & FW_PORT_CAP32_ ## __fw_name) \
SET_LMM(__lmm_name); \
} while (0)
switch ( V_145 ) {
case V_148 :
case V_149 :
case V_150 :
F_49 ( V_186 ) ;
F_50 ( V_187 , 100baseT_Full ) ;
F_50 ( V_188 , 1000baseT_Full ) ;
F_50 ( V_189 , 10000baseT_Full ) ;
break;
case V_190 :
case V_191 :
F_49 ( V_192 ) ;
F_50 ( V_188 , 1000baseKX_Full ) ;
F_50 ( V_189 , 10000baseKX4_Full ) ;
break;
case V_193 :
F_49 ( V_192 ) ;
F_49 ( 10000baseKR_Full ) ;
break;
case V_194 :
F_49 ( V_192 ) ;
F_49 ( 10000baseR_FEC ) ;
F_49 ( 10000baseKR_Full ) ;
F_49 ( 1000baseKX_Full ) ;
break;
case V_195 :
F_49 ( V_192 ) ;
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
F_49 ( V_196 ) ;
F_50 ( V_188 , 1000baseT_Full ) ;
F_50 ( V_189 , 10000baseT_Full ) ;
break;
case V_197 :
case V_158 :
F_49 ( V_196 ) ;
F_49 ( 40000baseSR4_Full ) ;
break;
case V_160 :
case V_162 :
F_49 ( V_196 ) ;
F_50 ( V_188 , 1000baseT_Full ) ;
F_50 ( V_189 , 10000baseT_Full ) ;
F_50 ( V_198 , 25000baseCR_Full ) ;
break;
case V_172 :
F_49 ( V_192 ) ;
F_50 ( V_188 , 1000baseT_Full ) ;
F_50 ( V_189 , 10000baseKR_Full ) ;
F_50 ( V_198 , 25000baseKR_Full ) ;
break;
case V_161 :
F_49 ( V_196 ) ;
F_49 ( 50000baseSR2_Full ) ;
break;
case V_171 :
case V_159 :
F_49 ( V_196 ) ;
F_50 ( V_199 , 40000baseSR4_Full ) ;
F_50 ( V_198 , 25000baseCR_Full ) ;
F_50 ( V_200 , 50000baseCR2_Full ) ;
F_50 ( V_201 , 100000baseCR4_Full ) ;
break;
default:
break;
}
F_50 ( V_202 , V_203 ) ;
F_50 ( 802_3_PAUSE , V_204 ) ;
F_50 ( 802_3_ASM_DIR , V_205 ) ;
#undef F_50
#undef F_49
}
static unsigned int F_51 ( const unsigned long * V_185 )
{
unsigned int V_184 = 0 ;
#define F_52 ( T_5 , T_6 ) \
do { \
if (test_bit(ETHTOOL_LINK_MODE_ ## __lmm_name ## _BIT, \
link_mode_mask)) \
fw_caps |= FW_PORT_CAP32_ ## __fw_name; \
} while (0)
F_52 ( 100baseT_Full , V_187 ) ;
F_52 ( 1000baseT_Full , V_188 ) ;
F_52 ( 10000baseT_Full , V_189 ) ;
F_52 ( 40000baseSR4_Full , V_199 ) ;
F_52 ( 25000baseCR_Full , V_198 ) ;
F_52 ( 50000baseCR2_Full , V_200 ) ;
F_52 ( 100000baseCR4_Full , V_201 ) ;
#undef F_52
return V_184 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_206 * V_207 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_208 * V_209 = & V_207 -> V_209 ;
if ( ! F_41 ( V_2 ) )
( void ) F_54 ( V_122 ) ;
F_55 ( V_207 , V_210 ) ;
F_55 ( V_207 , V_211 ) ;
F_55 ( V_207 , V_212 ) ;
V_209 -> V_213 = F_46 ( V_122 -> V_145 , V_122 -> V_147 ) ;
if ( V_122 -> V_214 >= 0 ) {
V_209 -> V_215 = V_122 -> V_214 ;
V_209 -> V_216 = ( V_122 -> V_145 == V_148
? V_217
: V_218 ) ;
} else {
V_209 -> V_215 = 255 ;
V_209 -> V_216 = 0 ;
}
F_48 ( V_122 -> V_145 , V_122 -> V_134 . V_219 ,
V_207 -> V_220 . V_210 ) ;
F_48 ( V_122 -> V_145 , V_122 -> V_134 . V_221 ,
V_207 -> V_220 . V_211 ) ;
F_48 ( V_122 -> V_145 , V_122 -> V_134 . V_222 ,
V_207 -> V_220 . V_212 ) ;
if ( F_56 ( V_2 ) ) {
V_209 -> V_174 = V_122 -> V_134 . V_174 ;
V_209 -> V_223 = V_224 ;
} else {
V_209 -> V_174 = V_225 ;
V_209 -> V_223 = V_226 ;
}
if ( V_122 -> V_134 . V_227 & V_228 ) {
if ( V_122 -> V_134 . V_227 & V_229 ) {
F_57 ( V_207 ,
V_211 ,
V_204 ) ;
} else {
F_57 ( V_207 ,
V_211 ,
V_205 ) ;
}
} else if ( V_122 -> V_134 . V_227 & V_229 ) {
F_57 ( V_207 ,
V_211 ,
V_205 ) ;
}
V_209 -> V_135 = V_122 -> V_134 . V_135 ;
if ( V_122 -> V_134 . V_219 & V_230 )
F_57 ( V_207 ,
V_210 , V_203 ) ;
if ( V_122 -> V_134 . V_135 )
F_57 ( V_207 ,
V_211 , V_203 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
const struct V_206 * V_207 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_231 * V_232 = & V_122 -> V_134 ;
const struct V_208 * V_209 = & V_207 -> V_209 ;
struct V_231 V_233 ;
unsigned int V_184 ;
int V_234 = 0 ;
if ( V_209 -> V_223 != V_224 )
return - V_137 ;
if ( ! ( V_232 -> V_219 & V_230 ) ) {
if ( V_209 -> V_135 == V_235 &&
( V_232 -> V_219 & F_47 ( V_209 -> V_174 ) ) )
return 0 ;
return - V_137 ;
}
V_233 = * V_232 ;
if ( V_209 -> V_135 == V_235 ) {
V_184 = F_47 ( V_209 -> V_174 ) ;
if ( ! ( V_232 -> V_219 & V_184 ) )
return - V_137 ;
V_232 -> V_236 = V_184 ;
V_232 -> V_221 = 0 ;
} else {
V_184 =
F_51 ( V_207 -> V_220 . V_211 ) ;
if ( ! ( V_232 -> V_219 & V_184 ) )
return - V_137 ;
V_232 -> V_236 = 0 ;
V_232 -> V_221 = V_184 | V_230 ;
}
V_232 -> V_135 = V_209 -> V_135 ;
V_234 = F_59 ( V_122 -> V_12 , V_122 -> V_12 -> V_237 , V_122 -> V_125 , V_232 ) ;
if ( V_234 )
* V_232 = V_233 ;
return V_234 ;
}
static inline unsigned int F_60 ( unsigned int V_238 )
{
unsigned int V_239 = 0 ;
if ( V_238 & V_240 )
V_239 |= V_241 ;
if ( V_238 & V_242 )
V_239 |= V_243 ;
if ( ! V_239 )
V_239 = V_244 ;
return V_239 ;
}
static inline unsigned int F_61 ( unsigned int V_245 )
{
unsigned int V_239 = 0 ;
if ( V_245 & V_246 )
V_239 |= V_247 ;
if ( V_245 & V_248 )
V_239 |= V_241 ;
if ( V_245 & V_249 )
V_239 |= V_243 ;
if ( ! V_239 )
V_239 = V_244 ;
return V_239 ;
}
static inline unsigned int F_62 ( unsigned int V_239 )
{
unsigned int V_245 = 0 ;
if ( V_239 & V_244 )
return V_245 ;
if ( V_239 & V_247 )
V_245 |= V_246 ;
if ( V_239 & V_241 )
V_245 |= V_248 ;
if ( V_239 & V_243 )
V_245 |= V_249 ;
return V_245 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_250 * V_251 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
const struct V_231 * V_232 = & V_122 -> V_134 ;
V_251 -> V_251 = F_60 ( V_232 -> V_219 ) ;
if ( V_251 -> V_251 != V_244 )
V_251 -> V_251 |= V_247 ;
V_251 -> V_252 = F_61 ( V_232 -> V_251 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_250 * V_251 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_231 * V_232 = & V_122 -> V_134 ;
struct V_231 V_233 ;
int V_234 ;
V_233 = * V_232 ;
V_232 -> V_253 = F_62 ( V_251 -> V_251 ) ;
V_234 = F_59 ( V_122 -> V_12 , V_122 -> V_12 -> V_237 ,
V_122 -> V_125 , V_232 ) ;
if ( V_234 )
* V_232 = V_233 ;
return V_234 ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_254 * V_255 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
V_255 -> V_135 = ( V_33 -> V_134 . V_256 & V_257 ) != 0 ;
V_255 -> V_258 = ( V_33 -> V_134 . V_227 & V_228 ) != 0 ;
V_255 -> V_259 = ( V_33 -> V_134 . V_227 & V_229 ) != 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_254 * V_255 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
struct V_231 * V_232 = & V_33 -> V_134 ;
if ( V_255 -> V_135 == V_235 )
V_232 -> V_256 = 0 ;
else if ( V_232 -> V_219 & V_230 )
V_232 -> V_256 = V_257 ;
else
return - V_137 ;
if ( V_255 -> V_258 )
V_232 -> V_256 |= V_228 ;
if ( V_255 -> V_259 )
V_232 -> V_256 |= V_229 ;
if ( F_41 ( V_2 ) )
return F_59 ( V_33 -> V_12 , V_33 -> V_12 -> V_237 , V_33 -> V_125 ,
V_232 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 , struct V_260 * V_261 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
const struct V_39 * V_35 = & V_122 -> V_12 -> V_39 ;
V_261 -> V_262 = V_263 ;
V_261 -> V_264 = V_265 ;
V_261 -> V_266 = 0 ;
V_261 -> V_267 = V_268 ;
V_261 -> V_269 = V_35 -> V_44 [ V_122 -> V_41 ] . V_270 . V_271 - 8 ;
V_261 -> V_272 = V_35 -> V_44 [ V_122 -> V_41 ] . V_273 . V_271 ;
V_261 -> V_274 = 0 ;
V_261 -> V_275 = V_35 -> V_40 [ V_122 -> V_41 ] . V_276 . V_271 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_260 * V_261 )
{
int V_36 ;
const struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_122 -> V_12 ;
struct V_39 * V_35 = & V_12 -> V_39 ;
if ( V_261 -> V_269 > V_263 || V_261 -> V_274 ||
V_261 -> V_275 > V_268 ||
V_261 -> V_272 > V_265 ||
V_261 -> V_272 < V_277 ||
V_261 -> V_269 < V_278 || V_261 -> V_275 < V_279 )
return - V_137 ;
if ( V_12 -> V_280 & V_281 )
return - V_282 ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; ++ V_36 ) {
V_35 -> V_40 [ V_122 -> V_41 + V_36 ] . V_276 . V_271 = V_261 -> V_275 ;
V_35 -> V_44 [ V_122 -> V_41 + V_36 ] . V_270 . V_271 = V_261 -> V_269 + 8 ;
V_35 -> V_44 [ V_122 -> V_41 + V_36 ] . V_273 . V_271 = V_261 -> V_272 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
unsigned int V_283 , unsigned int V_284 )
{
int V_36 , V_285 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_276 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; V_36 ++ , V_276 ++ ) {
V_285 = F_70 ( & V_276 -> V_273 , V_283 , V_284 ) ;
if ( V_285 )
return V_285 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , int V_286 )
{
int V_36 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_276 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; V_36 ++ , V_276 ++ )
V_276 -> V_273 . V_286 = V_286 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_276 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
return V_276 -> V_273 . V_286 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_287 * V_288 )
{
F_71 ( V_2 , V_288 -> V_289 ) ;
return F_69 ( V_2 , V_288 -> V_290 ,
V_288 -> V_291 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_287 * V_288 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
const struct V_12 * V_13 = V_122 -> V_12 ;
const struct V_292 * V_293 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] . V_273 ;
V_288 -> V_290 = F_75 ( V_13 , V_293 ) ;
V_288 -> V_291 = ( V_293 -> V_294 & V_295 ) ?
V_13 -> V_39 . V_296 [ V_293 -> V_297 ] : 0 ;
V_288 -> V_289 = F_72 ( V_2 ) ;
return 0 ;
}
static int F_76 ( unsigned int V_298 , unsigned int V_299 , unsigned int V_300 )
{
V_299 *= V_300 ;
if ( V_298 < 1024 )
return V_298 + ( 31 << 10 ) ;
if ( V_298 < 1024 + V_299 )
return 31744 - V_299 + V_298 - 1024 ;
if ( V_298 < V_14 )
return V_298 - 1024 - V_299 ;
return - V_137 ;
}
static int F_77 ( struct V_12 * V_13 , unsigned int V_298 , T_1 * V_95 )
{
int V_301 = F_76 ( V_298 , V_13 -> V_138 , V_302 ) ;
if ( V_301 >= 0 )
V_301 = F_78 ( V_13 -> V_23 , V_301 , sizeof( T_1 ) , V_95 ) ;
return V_301 < 0 ? V_301 : 0 ;
}
static int F_79 ( struct V_12 * V_13 , unsigned int V_298 , T_1 V_95 )
{
int V_301 = F_76 ( V_298 , V_13 -> V_138 , V_302 ) ;
if ( V_301 >= 0 )
V_301 = F_80 ( V_13 -> V_23 , V_301 , sizeof( T_1 ) , & V_95 ) ;
return V_301 < 0 ? V_301 : 0 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_303 * V_261 ,
T_2 * V_31 )
{
int V_36 , V_285 = 0 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
T_2 * V_131 = F_82 ( V_14 , V_304 ) ;
if ( ! V_131 )
return - V_305 ;
V_261 -> V_306 = V_307 ;
for ( V_36 = V_261 -> V_308 & ~ 3 ; ! V_285 && V_36 < V_261 -> V_308 + V_261 -> V_309 ; V_36 += 4 )
V_285 = F_77 ( V_12 , V_36 , ( T_1 * ) & V_131 [ V_36 ] ) ;
if ( ! V_285 )
memcpy ( V_31 , V_131 + V_261 -> V_308 , V_261 -> V_309 ) ;
F_83 ( V_131 ) ;
return V_285 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_303 * V_310 ,
T_2 * V_31 )
{
T_2 * V_131 ;
int V_285 = 0 ;
T_1 V_311 , V_312 , * V_33 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
if ( V_310 -> V_306 != V_307 )
return - V_137 ;
V_311 = V_310 -> V_308 & ~ 3 ;
V_312 = ( V_310 -> V_309 + ( V_310 -> V_308 & 3 ) + 3 ) & ~ 3 ;
if ( V_12 -> V_138 > 0 ) {
T_1 V_313 = 1024 + V_12 -> V_138 * V_302 ;
if ( V_311 < V_313 ||
V_311 + V_312 > V_313 + V_302 )
return - V_314 ;
}
if ( V_311 != V_310 -> V_308 || V_312 != V_310 -> V_309 ) {
V_131 = F_82 ( V_312 , V_304 ) ;
if ( ! V_131 )
return - V_305 ;
V_285 = F_77 ( V_12 , V_311 , ( T_1 * ) V_131 ) ;
if ( ! V_285 && V_312 > 4 )
V_285 = F_77 ( V_12 ,
V_311 + V_312 - 4 ,
( T_1 * ) & V_131 [ V_312 - 4 ] ) ;
if ( V_285 )
goto V_315;
memcpy ( V_131 + ( V_310 -> V_308 & 3 ) , V_31 , V_310 -> V_309 ) ;
} else {
V_131 = V_31 ;
}
V_285 = F_85 ( V_12 , false ) ;
if ( V_285 )
goto V_315;
for ( V_33 = ( T_1 * ) V_131 ; ! V_285 && V_312 ; V_312 -= 4 , V_33 ++ ) {
V_285 = F_79 ( V_12 , V_311 , * V_33 ) ;
V_311 += 4 ;
}
if ( ! V_285 )
V_285 = F_85 ( V_12 , true ) ;
V_315:
if ( V_131 != V_31 )
F_83 ( V_131 ) ;
return V_285 ;
}
static int F_86 ( struct V_1 * V_316 , struct V_317 * V_318 )
{
int V_234 ;
const struct V_319 * V_320 ;
struct V_12 * V_13 = F_2 ( V_316 ) ;
unsigned int V_237 = V_321 + 1 ;
T_1 V_322 ;
unsigned int V_323 ;
T_2 V_324 = 0 ;
V_322 = F_28 ( V_13 , V_325 ) ;
V_323 = F_87 ( V_322 ) ;
if ( V_322 & V_326 )
V_324 = 1 ;
if ( V_324 && ( V_323 != V_13 -> V_138 ) ) {
F_88 ( V_13 -> V_327 ,
L_4 ) ;
return - V_11 ;
}
V_318 -> V_31 [ sizeof( V_318 -> V_31 ) - 1 ] = '\0' ;
V_234 = F_89 ( & V_320 , V_318 -> V_31 , V_13 -> V_327 ) ;
if ( V_234 < 0 )
return V_234 ;
if ( V_13 -> V_280 & V_281 )
V_237 = V_13 -> V_237 ;
V_234 = F_90 ( V_13 , V_237 , V_320 -> V_31 , V_320 -> V_271 , 1 ) ;
F_91 ( V_320 ) ;
if ( ! V_234 )
F_92 ( V_13 -> V_327 ,
L_5 , V_318 -> V_31 ) ;
return V_234 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_328 * V_329 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_122 -> V_12 ;
V_329 -> V_330 = V_331 |
V_332 |
V_333 ;
V_329 -> V_330 |= V_334 |
V_335 |
V_336 ;
V_329 -> V_337 = ( 1 << V_338 ) |
( 1 << V_339 ) ;
V_329 -> V_340 = ( 1 << V_341 ) |
( 1 << V_342 ) |
( 1 << V_343 ) |
( 1 << V_344 ) |
( 1 << V_345 ) |
( 1 << V_346 ) ;
if ( V_12 -> V_347 )
V_329 -> V_348 = F_94 ( V_12 -> V_347 ) ;
else
V_329 -> V_348 = - 1 ;
return 0 ;
}
static T_1 F_95 ( struct V_1 * V_2 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
return V_122 -> V_349 ;
}
static int F_96 ( struct V_1 * V_2 , T_1 * V_33 , T_2 * V_350 , T_2 * V_351 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
unsigned int V_352 = V_122 -> V_349 ;
if ( V_351 )
* V_351 = V_353 ;
if ( ! V_33 )
return 0 ;
while ( V_352 -- )
V_33 [ V_352 ] = V_122 -> V_354 [ V_352 ] ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , const T_1 * V_33 , const T_2 * V_350 ,
const T_2 V_351 )
{
unsigned int V_36 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
if ( V_350 ||
( V_351 != V_355 && V_351 != V_353 ) )
return - V_11 ;
if ( ! V_33 )
return 0 ;
if ( V_122 -> V_12 -> V_280 & V_281 ) {
for ( V_36 = 0 ; V_36 < V_122 -> V_349 ; V_36 ++ )
V_122 -> V_354 [ V_36 ] = V_33 [ V_36 ] ;
return F_98 ( V_122 , V_122 -> V_354 ) ;
}
return - V_314 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_356 * V_16 ,
T_1 * V_357 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
switch ( V_16 -> V_358 ) {
case V_359 : {
unsigned int V_95 = V_122 -> V_360 ;
V_16 -> V_31 = 0 ;
switch ( V_16 -> V_361 ) {
case V_362 :
if ( V_95 & V_363 )
V_16 -> V_31 = V_364 | V_365 |
V_366 | V_367 ;
else if ( V_95 & V_368 )
V_16 -> V_31 = V_364 | V_365 ;
break;
case V_369 :
if ( ( V_95 & V_363 ) &&
( V_95 & V_370 ) )
V_16 -> V_31 = V_364 | V_365 |
V_366 | V_367 ;
else if ( V_95 & V_368 )
V_16 -> V_31 = V_364 | V_365 ;
break;
case V_371 :
case V_372 :
case V_373 :
if ( V_95 & V_368 )
V_16 -> V_31 = V_364 | V_365 ;
break;
case V_374 :
if ( V_95 & V_375 )
V_16 -> V_31 = V_364 | V_365 |
V_366 | V_367 ;
else if ( V_95 & V_376 )
V_16 -> V_31 = V_364 | V_365 ;
break;
case V_377 :
if ( ( V_95 & V_375 ) &&
( V_95 & V_370 ) )
V_16 -> V_31 = V_364 | V_365 |
V_366 | V_367 ;
else if ( V_95 & V_376 )
V_16 -> V_31 = V_364 | V_365 ;
break;
case V_378 :
case V_379 :
case V_380 :
if ( V_95 & V_376 )
V_16 -> V_31 = V_364 | V_365 ;
break;
}
return 0 ;
}
case V_381 :
V_16 -> V_31 = V_122 -> V_45 ;
return 0 ;
}
return - V_11 ;
}
void F_100 ( struct V_1 * V_316 )
{
V_316 -> V_382 = & V_383 ;
}
