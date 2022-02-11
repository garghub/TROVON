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
V_145 == V_158 ) {
if ( V_147 == V_159 ||
V_147 == V_160 ||
V_147 == V_161 ||
V_147 == V_162 )
return V_154 ;
else if ( V_147 == V_163 ||
V_147 == V_164 )
return V_165 ;
else
return V_166 ;
}
return V_166 ;
}
static unsigned int F_47 ( int V_167 )
{
if ( V_167 == 100 )
return V_168 ;
if ( V_167 == 1000 )
return V_169 ;
if ( V_167 == 10000 )
return V_170 ;
if ( V_167 == 25000 )
return V_171 ;
if ( V_167 == 40000 )
return V_172 ;
if ( V_167 == 100000 )
return V_173 ;
return 0 ;
}
static void F_48 ( enum V_144 V_145 ,
unsigned int V_174 ,
unsigned long * V_175 )
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
F_49 ( V_176 ) ;
F_50 ( V_177 , 100baseT_Full ) ;
F_50 ( V_178 , 1000baseT_Full ) ;
F_50 ( V_179 , 10000baseT_Full ) ;
break;
case V_180 :
case V_181 :
F_49 ( V_182 ) ;
F_50 ( V_178 , 1000baseKX_Full ) ;
F_50 ( V_179 , 10000baseKX4_Full ) ;
break;
case V_183 :
F_49 ( V_182 ) ;
F_49 ( 10000baseKR_Full ) ;
break;
case V_184 :
F_49 ( V_182 ) ;
F_49 ( 10000baseR_FEC ) ;
F_49 ( 10000baseKR_Full ) ;
F_49 ( 1000baseKX_Full ) ;
break;
case V_185 :
F_49 ( V_182 ) ;
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
F_49 ( V_186 ) ;
F_50 ( V_178 , 1000baseT_Full ) ;
F_50 ( V_179 , 10000baseT_Full ) ;
break;
case V_187 :
case V_158 :
F_49 ( V_186 ) ;
F_49 ( 40000baseSR4_Full ) ;
break;
case V_188 :
case V_189 :
F_49 ( V_186 ) ;
F_49 ( 25000baseCR_Full ) ;
break;
case V_190 :
case V_191 :
F_49 ( V_186 ) ;
F_49 ( 100000baseCR4_Full ) ;
break;
default:
break;
}
F_50 ( V_192 , V_193 ) ;
F_50 ( 802_3_PAUSE , V_194 ) ;
F_50 ( 802_3_ASM_DIR , V_195 ) ;
#undef F_50
#undef F_49
}
static unsigned int F_51 ( const unsigned long * V_175 )
{
unsigned int V_174 = 0 ;
#define F_52 ( T_5 , T_6 ) \
do { \
if (test_bit(ETHTOOL_LINK_MODE_ ## __lmm_name ## _BIT, \
link_mode_mask)) \
fw_caps |= FW_PORT_CAP_ ## __fw_name; \
} while (0)
F_52 ( 100baseT_Full , V_177 ) ;
F_52 ( 1000baseT_Full , V_178 ) ;
F_52 ( 10000baseT_Full , V_179 ) ;
F_52 ( 40000baseSR4_Full , V_196 ) ;
F_52 ( 25000baseCR_Full , V_197 ) ;
F_52 ( 100000baseCR4_Full , V_198 ) ;
#undef F_52
return V_174 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_199 * V_200 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_201 * V_202 = & V_200 -> V_202 ;
F_54 ( V_200 , V_203 ) ;
F_54 ( V_200 , V_204 ) ;
F_54 ( V_200 , V_205 ) ;
V_202 -> V_206 = F_46 ( V_122 -> V_145 , V_122 -> V_147 ) ;
if ( V_122 -> V_207 >= 0 ) {
V_202 -> V_208 = V_122 -> V_207 ;
V_202 -> V_209 = ( V_122 -> V_145 == V_148
? V_210
: V_211 ) ;
} else {
V_202 -> V_208 = 255 ;
V_202 -> V_209 = 0 ;
}
F_48 ( V_122 -> V_145 , V_122 -> V_134 . V_203 ,
V_200 -> V_212 . V_203 ) ;
F_48 ( V_122 -> V_145 , V_122 -> V_134 . V_204 ,
V_200 -> V_212 . V_204 ) ;
F_48 ( V_122 -> V_145 , V_122 -> V_134 . V_205 ,
V_200 -> V_212 . V_205 ) ;
if ( F_55 ( V_2 ) ) {
V_202 -> V_167 = V_122 -> V_134 . V_167 ;
V_202 -> V_213 = V_214 ;
} else {
V_202 -> V_167 = V_215 ;
V_202 -> V_213 = V_216 ;
}
V_202 -> V_135 = V_122 -> V_134 . V_135 ;
if ( V_122 -> V_134 . V_203 & V_217 )
F_56 ( V_200 ,
V_203 , V_193 ) ;
if ( V_122 -> V_134 . V_135 )
F_56 ( V_200 ,
V_204 , V_193 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
const struct V_199
* V_200 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_218 * V_219 = & V_122 -> V_134 ;
const struct V_201 * V_202 = & V_200 -> V_202 ;
struct V_218 V_220 ;
unsigned int V_174 ;
int V_221 = 0 ;
if ( V_202 -> V_213 != V_214 )
return - V_137 ;
if ( ! ( V_219 -> V_203 & V_217 ) ) {
if ( V_202 -> V_135 == V_222 &&
( V_219 -> V_203 & F_47 ( V_202 -> V_167 ) ) )
return 0 ;
return - V_137 ;
}
V_220 = * V_219 ;
if ( V_202 -> V_135 == V_222 ) {
V_174 = F_47 ( V_202 -> V_167 ) ;
if ( ! ( V_219 -> V_203 & V_174 ) )
return - V_137 ;
V_219 -> V_223 = V_174 ;
V_219 -> V_204 = 0 ;
} else {
V_174 =
F_51 ( V_200 -> V_212 . V_204 ) ;
if ( ! ( V_219 -> V_203 & V_174 ) )
return - V_137 ;
V_219 -> V_223 = 0 ;
V_219 -> V_204 = V_174 | V_217 ;
}
V_219 -> V_135 = V_202 -> V_135 ;
V_221 = F_58 ( V_122 -> V_12 , V_122 -> V_12 -> V_224 , V_122 -> V_125 , V_219 ) ;
if ( V_221 )
* V_219 = V_220 ;
return V_221 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_225 * V_226 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
V_226 -> V_135 = ( V_33 -> V_134 . V_227 & V_228 ) != 0 ;
V_226 -> V_229 = ( V_33 -> V_134 . V_230 & V_231 ) != 0 ;
V_226 -> V_232 = ( V_33 -> V_134 . V_230 & V_233 ) != 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_225 * V_226 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
struct V_218 * V_219 = & V_33 -> V_134 ;
if ( V_226 -> V_135 == V_222 )
V_219 -> V_227 = 0 ;
else if ( V_219 -> V_203 & V_217 )
V_219 -> V_227 = V_228 ;
else
return - V_137 ;
if ( V_226 -> V_229 )
V_219 -> V_227 |= V_231 ;
if ( V_226 -> V_232 )
V_219 -> V_227 |= V_233 ;
if ( F_41 ( V_2 ) )
return F_58 ( V_33 -> V_12 , V_33 -> V_12 -> V_224 , V_33 -> V_125 ,
V_219 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_234 * V_235 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
const struct V_39 * V_35 = & V_122 -> V_12 -> V_39 ;
V_235 -> V_236 = V_237 ;
V_235 -> V_238 = V_239 ;
V_235 -> V_240 = 0 ;
V_235 -> V_241 = V_242 ;
V_235 -> V_243 = V_35 -> V_44 [ V_122 -> V_41 ] . V_244 . V_245 - 8 ;
V_235 -> V_246 = V_35 -> V_44 [ V_122 -> V_41 ] . V_247 . V_245 ;
V_235 -> V_248 = 0 ;
V_235 -> V_249 = V_35 -> V_40 [ V_122 -> V_41 ] . V_250 . V_245 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_234 * V_235 )
{
int V_36 ;
const struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_122 -> V_12 ;
struct V_39 * V_35 = & V_12 -> V_39 ;
if ( V_235 -> V_243 > V_237 || V_235 -> V_248 ||
V_235 -> V_249 > V_242 ||
V_235 -> V_246 > V_239 ||
V_235 -> V_246 < V_251 ||
V_235 -> V_243 < V_252 || V_235 -> V_249 < V_253 )
return - V_137 ;
if ( V_12 -> V_254 & V_255 )
return - V_256 ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; ++ V_36 ) {
V_35 -> V_40 [ V_122 -> V_41 + V_36 ] . V_250 . V_245 = V_235 -> V_249 ;
V_35 -> V_44 [ V_122 -> V_41 + V_36 ] . V_244 . V_245 = V_235 -> V_243 + 8 ;
V_35 -> V_44 [ V_122 -> V_41 + V_36 ] . V_247 . V_245 = V_235 -> V_246 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
unsigned int V_257 , unsigned int V_258 )
{
int V_36 , V_259 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_250 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; V_36 ++ , V_250 ++ ) {
V_259 = F_64 ( & V_250 -> V_247 , V_257 , V_258 ) ;
if ( V_259 )
return V_259 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , int V_260 )
{
int V_36 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_250 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; V_36 ++ , V_250 ++ )
V_250 -> V_247 . V_260 = V_260 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_250 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
return V_250 -> V_247 . V_260 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_261 * V_262 )
{
F_65 ( V_2 , V_262 -> V_263 ) ;
return F_63 ( V_2 , V_262 -> V_264 ,
V_262 -> V_265 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_261 * V_262 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
const struct V_12 * V_13 = V_122 -> V_12 ;
const struct V_266 * V_267 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] . V_247 ;
V_262 -> V_264 = F_69 ( V_13 , V_267 ) ;
V_262 -> V_265 = ( V_267 -> V_268 & V_269 ) ?
V_13 -> V_39 . V_270 [ V_267 -> V_271 ] : 0 ;
V_262 -> V_263 = F_66 ( V_2 ) ;
return 0 ;
}
static int F_70 ( unsigned int V_272 , unsigned int V_273 , unsigned int V_274 )
{
V_273 *= V_274 ;
if ( V_272 < 1024 )
return V_272 + ( 31 << 10 ) ;
if ( V_272 < 1024 + V_273 )
return 31744 - V_273 + V_272 - 1024 ;
if ( V_272 < V_14 )
return V_272 - 1024 - V_273 ;
return - V_137 ;
}
static int F_71 ( struct V_12 * V_13 , unsigned int V_272 , T_1 * V_95 )
{
int V_275 = F_70 ( V_272 , V_13 -> V_138 , V_276 ) ;
if ( V_275 >= 0 )
V_275 = F_72 ( V_13 -> V_23 , V_275 , sizeof( T_1 ) , V_95 ) ;
return V_275 < 0 ? V_275 : 0 ;
}
static int F_73 ( struct V_12 * V_13 , unsigned int V_272 , T_1 V_95 )
{
int V_275 = F_70 ( V_272 , V_13 -> V_138 , V_276 ) ;
if ( V_275 >= 0 )
V_275 = F_74 ( V_13 -> V_23 , V_275 , sizeof( T_1 ) , & V_95 ) ;
return V_275 < 0 ? V_275 : 0 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_277 * V_235 ,
T_2 * V_31 )
{
int V_36 , V_259 = 0 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
T_2 * V_131 = F_76 ( V_14 , V_278 ) ;
if ( ! V_131 )
return - V_279 ;
V_235 -> V_280 = V_281 ;
for ( V_36 = V_235 -> V_282 & ~ 3 ; ! V_259 && V_36 < V_235 -> V_282 + V_235 -> V_283 ; V_36 += 4 )
V_259 = F_71 ( V_12 , V_36 , ( T_1 * ) & V_131 [ V_36 ] ) ;
if ( ! V_259 )
memcpy ( V_31 , V_131 + V_235 -> V_282 , V_235 -> V_283 ) ;
F_77 ( V_131 ) ;
return V_259 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_277 * V_284 ,
T_2 * V_31 )
{
T_2 * V_131 ;
int V_259 = 0 ;
T_1 V_285 , V_286 , * V_33 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
if ( V_284 -> V_280 != V_281 )
return - V_137 ;
V_285 = V_284 -> V_282 & ~ 3 ;
V_286 = ( V_284 -> V_283 + ( V_284 -> V_282 & 3 ) + 3 ) & ~ 3 ;
if ( V_12 -> V_138 > 0 ) {
T_1 V_287 = 1024 + V_12 -> V_138 * V_276 ;
if ( V_285 < V_287 ||
V_285 + V_286 > V_287 + V_276 )
return - V_288 ;
}
if ( V_285 != V_284 -> V_282 || V_286 != V_284 -> V_283 ) {
V_131 = F_76 ( V_286 , V_278 ) ;
if ( ! V_131 )
return - V_279 ;
V_259 = F_71 ( V_12 , V_285 , ( T_1 * ) V_131 ) ;
if ( ! V_259 && V_286 > 4 )
V_259 = F_71 ( V_12 ,
V_285 + V_286 - 4 ,
( T_1 * ) & V_131 [ V_286 - 4 ] ) ;
if ( V_259 )
goto V_289;
memcpy ( V_131 + ( V_284 -> V_282 & 3 ) , V_31 , V_284 -> V_283 ) ;
} else {
V_131 = V_31 ;
}
V_259 = F_79 ( V_12 , false ) ;
if ( V_259 )
goto V_289;
for ( V_33 = ( T_1 * ) V_131 ; ! V_259 && V_286 ; V_286 -= 4 , V_33 ++ ) {
V_259 = F_73 ( V_12 , V_285 , * V_33 ) ;
V_285 += 4 ;
}
if ( ! V_259 )
V_259 = F_79 ( V_12 , true ) ;
V_289:
if ( V_131 != V_31 )
F_77 ( V_131 ) ;
return V_259 ;
}
static int F_80 ( struct V_1 * V_290 , struct V_291 * V_292 )
{
int V_221 ;
const struct V_293 * V_294 ;
struct V_12 * V_13 = F_2 ( V_290 ) ;
unsigned int V_224 = V_295 + 1 ;
T_1 V_296 ;
unsigned int V_297 ;
T_2 V_298 = 0 ;
V_296 = F_28 ( V_13 , V_299 ) ;
V_297 = F_81 ( V_296 ) ;
if ( V_296 & V_300 )
V_298 = 1 ;
if ( V_298 && ( V_297 != V_13 -> V_138 ) ) {
F_82 ( V_13 -> V_301 ,
L_4 ) ;
return - V_11 ;
}
V_292 -> V_31 [ sizeof( V_292 -> V_31 ) - 1 ] = '\0' ;
V_221 = F_83 ( & V_294 , V_292 -> V_31 , V_13 -> V_301 ) ;
if ( V_221 < 0 )
return V_221 ;
if ( V_13 -> V_254 & V_255 )
V_224 = V_13 -> V_224 ;
V_221 = F_84 ( V_13 , V_224 , V_294 -> V_31 , V_294 -> V_245 , 1 ) ;
F_85 ( V_294 ) ;
if ( ! V_221 )
F_86 ( V_13 -> V_301 ,
L_5 , V_292 -> V_31 ) ;
return V_221 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_302 * V_303 )
{
V_303 -> V_304 = V_305 |
V_306 |
V_307 ;
V_303 -> V_304 |= V_308 |
V_309 ;
V_303 -> V_310 = - 1 ;
return 0 ;
}
static T_1 F_88 ( struct V_1 * V_2 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
return V_122 -> V_311 ;
}
static int F_89 ( struct V_1 * V_2 , T_1 * V_33 , T_2 * V_312 , T_2 * V_313 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
unsigned int V_314 = V_122 -> V_311 ;
if ( V_313 )
* V_313 = V_315 ;
if ( ! V_33 )
return 0 ;
while ( V_314 -- )
V_33 [ V_314 ] = V_122 -> V_316 [ V_314 ] ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , const T_1 * V_33 , const T_2 * V_312 ,
const T_2 V_313 )
{
unsigned int V_36 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
if ( V_312 ||
( V_313 != V_317 && V_313 != V_315 ) )
return - V_11 ;
if ( ! V_33 )
return 0 ;
if ( V_122 -> V_12 -> V_254 & V_255 ) {
for ( V_36 = 0 ; V_36 < V_122 -> V_311 ; V_36 ++ )
V_122 -> V_316 [ V_36 ] = V_33 [ V_36 ] ;
return F_91 ( V_122 , V_122 -> V_316 ) ;
}
return - V_288 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_318 * V_16 ,
T_1 * V_319 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
switch ( V_16 -> V_320 ) {
case V_321 : {
unsigned int V_95 = V_122 -> V_322 ;
V_16 -> V_31 = 0 ;
switch ( V_16 -> V_323 ) {
case V_324 :
if ( V_95 & V_325 )
V_16 -> V_31 = V_326 | V_327 |
V_328 | V_329 ;
else if ( V_95 & V_330 )
V_16 -> V_31 = V_326 | V_327 ;
break;
case V_331 :
if ( ( V_95 & V_325 ) &&
( V_95 & V_332 ) )
V_16 -> V_31 = V_326 | V_327 |
V_328 | V_329 ;
else if ( V_95 & V_330 )
V_16 -> V_31 = V_326 | V_327 ;
break;
case V_333 :
case V_334 :
case V_335 :
if ( V_95 & V_330 )
V_16 -> V_31 = V_326 | V_327 ;
break;
case V_336 :
if ( V_95 & V_337 )
V_16 -> V_31 = V_326 | V_327 |
V_328 | V_329 ;
else if ( V_95 & V_338 )
V_16 -> V_31 = V_326 | V_327 ;
break;
case V_339 :
if ( ( V_95 & V_337 ) &&
( V_95 & V_332 ) )
V_16 -> V_31 = V_326 | V_327 |
V_328 | V_329 ;
else if ( V_95 & V_338 )
V_16 -> V_31 = V_326 | V_327 ;
break;
case V_340 :
case V_341 :
case V_342 :
if ( V_95 & V_338 )
V_16 -> V_31 = V_326 | V_327 ;
break;
}
return 0 ;
}
case V_343 :
V_16 -> V_31 = V_122 -> V_45 ;
return 0 ;
}
return - V_11 ;
}
void F_93 ( struct V_1 * V_290 )
{
V_290 -> V_344 = & V_345 ;
}
