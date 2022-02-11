static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
F_2 ( V_2 -> V_6 , F_3 ( V_2 ) -> V_5 , V_5 ,
V_4 -> V_7 [ V_5 ] ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_8 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
V_11 -> V_7 [ V_14 ] = V_9 -> V_15 = V_8 ;
if ( V_9 -> V_15 && F_6 ( V_2 -> V_6 ) ) {
V_11 -> V_7 [ V_14 ] = 0x80 ;
V_11 -> V_7 [ V_16 ] = V_9 -> V_15 << 2 ;
F_1 ( V_2 , V_11 , V_16 ) ;
}
F_1 ( V_2 , V_11 , V_14 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_8 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
V_9 -> V_17 = V_8 ;
if ( V_8 < 0 )
V_8 += 0x40 ;
V_11 -> V_18 = V_8 ;
F_8 ( V_2 -> V_6 , V_9 -> V_5 , V_19 , V_11 -> V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_20 * V_21 , int V_22 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct V_25 * V_26 = F_10 ( & V_24 -> V_27 . V_28 ) ;
struct V_29 * V_30 = F_11 ( & V_24 -> V_27 . V_28 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_31 * V_32 = & F_5 ( V_6 ) -> V_12 ;
struct V_3 * V_11 = & V_32 -> V_13 [ V_9 -> V_5 ] ;
struct V_33 * V_34 = & V_11 -> V_35 ;
struct V_36 V_37 ;
if ( F_12 ( V_26 , V_9 -> V_5 ? V_38 : V_39 ,
& V_37 ) )
return;
V_34 -> V_40 = 0 ;
if ( V_24 -> V_27 . V_28 . V_41 . V_42 > 0x40 && V_22 <= ( V_37 . V_43 . V_44 / 2 ) )
memset ( & V_37 . V_45 , 0 , sizeof( V_37 . V_45 ) ) ;
if ( ! V_30 -> V_46 ( V_30 , & V_37 , V_22 , V_34 ) )
return;
V_32 -> V_47 &= V_48 | V_49 | V_50 ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 == V_52 )
V_32 -> V_47 |= V_53 ;
if ( V_24 -> V_27 . V_28 . V_41 . V_42 < 0x41 )
V_32 -> V_47 |= V_54 |
V_55 ;
V_32 -> V_47 |= V_9 -> V_5 ? V_49 : V_48 ;
if ( V_34 -> V_40 )
F_13 ( V_24 , L_1 ,
V_34 -> V_56 , V_34 -> V_57 , V_34 -> V_58 , V_34 -> V_59 , V_34 -> V_60 ) ;
else
F_13 ( V_24 , L_2 ,
V_34 -> V_56 , V_34 -> V_58 , V_34 -> V_60 ) ;
V_9 -> V_61 . V_62 ( V_9 , V_9 -> V_61 . V_63 ) ;
}
static void
F_14 ( struct V_1 * V_2 , int V_21 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
unsigned char V_64 = 0 , V_65 = 0 ;
unsigned char V_66 ;
F_13 ( V_24 , L_3 , V_21 ,
V_9 -> V_5 ) ;
if ( V_9 -> V_67 == V_21 )
return;
V_9 -> V_67 = V_21 ;
if ( F_15 ( V_6 ) )
F_16 ( V_6 , V_9 -> V_5 ) ;
V_66 = F_17 ( V_6 , V_9 -> V_5 ,
V_68 ) & ~ 0xC0 ;
switch ( V_21 ) {
case V_69 :
V_64 = 0x20 ;
V_65 = 0x80 ;
V_66 |= 0x80 ;
break;
case V_70 :
V_64 = 0x20 ;
V_65 = 0x80 ;
V_66 |= 0x40 ;
break;
case V_71 :
V_64 = 0x20 ;
V_65 = 0x00 ;
V_66 |= 0xC0 ;
break;
case V_72 :
default:
V_64 = 0x00 ;
V_65 = 0x80 ;
break;
}
F_18 ( V_6 , V_9 -> V_5 , true ) ;
V_64 |= ( F_19 ( V_6 , V_9 -> V_5 , V_73 ) & ~ 0x20 ) ;
F_20 ( V_6 , V_9 -> V_5 , V_73 , V_64 ) ;
V_65 |= ( F_17 ( V_6 , V_9 -> V_5 , V_74 ) & ~ 0x80 ) ;
F_21 ( 10 ) ;
F_2 ( V_6 , V_9 -> V_5 , V_74 , V_65 ) ;
F_18 ( V_6 , V_9 -> V_5 , false ) ;
F_2 ( V_6 , V_9 -> V_5 , V_68 , V_66 ) ;
}
static void
F_22 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_75 * V_76 = V_2 -> V_77 -> V_76 ;
int V_78 = ( V_21 -> V_79 >> 3 ) - 1 ;
int V_80 = ( V_21 -> V_81 >> 3 ) + 1 ;
int V_82 = ( V_21 -> V_83 >> 3 ) + 1 ;
int V_84 = ( V_21 -> V_85 >> 3 ) - 5 ;
int V_86 = ( V_21 -> V_79 >> 3 ) - 1 ;
int V_87 = ( V_21 -> V_85 >> 3 ) - 1 ;
int V_88 = V_21 -> V_89 - 1 ;
int V_90 = V_21 -> V_91 - 1 ;
int V_92 = V_21 -> V_93 - 1 ;
int V_94 = V_21 -> V_95 - 2 ;
int V_96 = V_21 -> V_89 - 1 ;
int V_97 = V_21 -> V_95 - 1 ;
struct V_98 * V_99 ;
bool V_100 = false ;
F_23 (encoder, &dev->mode_config.encoder_list, head) {
struct V_101 * V_102 = V_101 ( V_99 ) ;
if ( V_99 -> V_2 == V_2 &&
( V_102 -> V_103 -> type == V_104 ||
V_102 -> V_103 -> type == V_105 ) )
V_100 = true ;
}
if ( V_100 ) {
V_90 = V_94 - 3 ;
V_92 = V_94 - 2 ;
V_96 = V_90 ;
V_80 = V_84 - 5 ;
V_82 = V_84 - 2 ;
V_87 = V_84 + 4 ;
#if 0
if (dev->overlayAdaptor && drm->client.device.info.family >= NV_DEVICE_INFO_V0_CELSIUS)
horizTotal += 2;
#endif
}
if ( V_21 -> V_106 & V_107 )
V_94 |= 1 ;
#if 0
ErrorF("horizDisplay: 0x%X \n", horizDisplay);
ErrorF("horizStart: 0x%X \n", horizStart);
ErrorF("horizEnd: 0x%X \n", horizEnd);
ErrorF("horizTotal: 0x%X \n", horizTotal);
ErrorF("horizBlankStart: 0x%X \n", horizBlankStart);
ErrorF("horizBlankEnd: 0x%X \n", horizBlankEnd);
ErrorF("vertDisplay: 0x%X \n", vertDisplay);
ErrorF("vertStart: 0x%X \n", vertStart);
ErrorF("vertEnd: 0x%X \n", vertEnd);
ErrorF("vertTotal: 0x%X \n", vertTotal);
ErrorF("vertBlankStart: 0x%X \n", vertBlankStart);
ErrorF("vertBlankEnd: 0x%X \n", vertBlankEnd);
#endif
if ( ( V_21 -> V_106 & ( V_108 | V_109 ) )
&& ( V_21 -> V_106 & ( V_110 | V_111 ) ) ) {
V_11 -> V_112 = 0x23 ;
if ( V_21 -> V_106 & V_109 )
V_11 -> V_112 |= 0x40 ;
if ( V_21 -> V_106 & V_111 )
V_11 -> V_112 |= 0x80 ;
} else {
int V_113 = V_21 -> V_113 ;
if ( V_21 -> V_106 & V_114 )
V_113 *= 2 ;
if ( V_21 -> V_115 > 1 )
V_113 *= V_21 -> V_115 ;
if ( V_113 < 400 )
V_11 -> V_112 = 0xA3 ;
else if ( V_113 < 480 )
V_11 -> V_112 = 0x63 ;
else if ( V_113 < 768 )
V_11 -> V_112 = 0xE3 ;
else
V_11 -> V_112 = 0x23 ;
}
V_11 -> V_116 [ V_117 ] = 0x00 ;
if ( V_21 -> V_106 & V_118 )
V_11 -> V_116 [ V_73 ] = 0x29 ;
else
V_11 -> V_116 [ V_73 ] = 0x21 ;
V_11 -> V_116 [ V_119 ] = 0x0F ;
V_11 -> V_116 [ V_120 ] = 0x00 ;
V_11 -> V_116 [ V_121 ] = 0x0E ;
V_11 -> V_7 [ V_122 ] = V_84 ;
V_11 -> V_7 [ V_123 ] = V_78 ;
V_11 -> V_7 [ V_124 ] = V_86 ;
V_11 -> V_7 [ V_125 ] = ( 1 << 7 ) |
F_24 ( V_87 , 0 , V_126 ) ;
V_11 -> V_7 [ V_127 ] = V_80 ;
V_11 -> V_7 [ V_128 ] = F_24 ( V_87 , 5 , V_129 ) |
F_24 ( V_82 , 0 , V_130 ) ;
V_11 -> V_7 [ V_131 ] = V_94 ;
V_11 -> V_7 [ V_132 ] = F_24 ( V_90 , 9 , V_133 ) |
F_24 ( V_88 , 9 , V_134 ) |
F_24 ( V_94 , 9 , V_135 ) |
( 1 << 4 ) |
F_24 ( V_96 , 8 , V_136 ) |
F_24 ( V_90 , 8 , V_137 ) |
F_24 ( V_88 , 8 , V_138 ) |
F_24 ( V_94 , 8 , V_139 ) ;
V_11 -> V_7 [ V_140 ] = 0x00 ;
V_11 -> V_7 [ V_141 ] = ( ( V_21 -> V_106 & V_114 ) ? F_25 ( V_142 ) : 0 ) |
1 << 6 |
F_24 ( V_96 , 9 , V_143 ) ;
V_11 -> V_7 [ V_144 ] = 0x00 ;
V_11 -> V_7 [ V_145 ] = 0x00 ;
V_11 -> V_7 [ V_146 ] = 0x00 ;
V_11 -> V_7 [ V_147 ] = 0x00 ;
V_11 -> V_7 [ V_148 ] = 0x00 ;
V_11 -> V_7 [ V_149 ] = 0x00 ;
V_11 -> V_7 [ V_150 ] = V_90 ;
V_11 -> V_7 [ V_151 ] = 1 << 5 | F_24 ( V_92 , 0 , V_152 ) ;
V_11 -> V_7 [ V_153 ] = V_88 ;
V_11 -> V_7 [ V_154 ] = V_76 -> V_155 [ 0 ] / 8 ;
V_11 -> V_7 [ V_156 ] = 0x00 ;
V_11 -> V_7 [ V_157 ] = V_96 ;
V_11 -> V_7 [ V_158 ] = V_97 ;
V_11 -> V_7 [ V_74 ] = 0x43 ;
V_11 -> V_7 [ V_159 ] = 0xff ;
V_11 -> V_7 [ V_160 ] =
F_24 ( V_76 -> V_155 [ 0 ] / 8 , 8 , V_161 ) ;
V_11 -> V_7 [ V_162 ] =
F_24 ( V_76 -> V_155 [ 0 ] / 8 , 11 , V_163 ) ;
V_11 -> V_7 [ V_68 ] = V_21 -> V_79 < 1280 ?
F_25 ( V_164 ) : 0x00 ;
V_11 -> V_7 [ V_165 ] = F_24 ( V_87 , 6 , V_166 ) |
F_24 ( V_96 , 10 , V_167 ) |
F_24 ( V_90 , 10 , V_168 ) |
F_24 ( V_88 , 10 , V_169 ) |
F_24 ( V_94 , 10 , V_170 ) ;
V_11 -> V_7 [ V_171 ] = F_24 ( V_80 , 8 , V_172 ) |
F_24 ( V_86 , 8 , V_173 ) |
F_24 ( V_78 , 8 , V_174 ) |
F_24 ( V_84 , 8 , V_175 ) ;
V_11 -> V_7 [ V_176 ] = F_24 ( V_96 , 11 , V_177 ) |
F_24 ( V_90 , 11 , V_178 ) |
F_24 ( V_88 , 11 , V_179 ) |
F_24 ( V_94 , 11 , V_180 ) ;
if ( V_21 -> V_106 & V_107 ) {
V_84 = ( V_84 >> 1 ) & ~ 1 ;
V_11 -> V_7 [ V_181 ] = V_84 ;
V_11 -> V_7 [ V_171 ] |= F_24 ( V_84 , 8 , V_182 ) ;
} else
V_11 -> V_7 [ V_181 ] = 0xff ;
V_11 -> V_183 [ V_184 ] = 0x00 ;
V_11 -> V_183 [ V_185 ] = 0x00 ;
V_11 -> V_183 [ V_186 ] = 0x00 ;
V_11 -> V_183 [ V_187 ] = 0x00 ;
V_11 -> V_183 [ V_188 ] = 0x00 ;
V_11 -> V_183 [ V_189 ] = 0x40 ;
V_11 -> V_183 [ V_190 ] = 0x05 ;
V_11 -> V_183 [ V_191 ] = 0x0F ;
V_11 -> V_183 [ V_192 ] = 0xFF ;
V_11 -> V_193 [ 0 ] = 0x00 ;
V_11 -> V_193 [ 1 ] = 0x01 ;
V_11 -> V_193 [ 2 ] = 0x02 ;
V_11 -> V_193 [ 3 ] = 0x03 ;
V_11 -> V_193 [ 4 ] = 0x04 ;
V_11 -> V_193 [ 5 ] = 0x05 ;
V_11 -> V_193 [ 6 ] = 0x06 ;
V_11 -> V_193 [ 7 ] = 0x07 ;
V_11 -> V_193 [ 8 ] = 0x08 ;
V_11 -> V_193 [ 9 ] = 0x09 ;
V_11 -> V_193 [ 10 ] = 0x0A ;
V_11 -> V_193 [ 11 ] = 0x0B ;
V_11 -> V_193 [ 12 ] = 0x0C ;
V_11 -> V_193 [ 13 ] = 0x0D ;
V_11 -> V_193 [ 14 ] = 0x0E ;
V_11 -> V_193 [ 15 ] = 0x0F ;
V_11 -> V_193 [ V_194 ] = 0x01 ;
V_11 -> V_193 [ V_195 ] = 0x00 ;
V_11 -> V_193 [ V_196 ] = 0x0F ;
V_11 -> V_193 [ V_197 ] = 0x00 ;
V_11 -> V_193 [ V_198 ] = 0x00 ;
}
static void
F_26 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_3 * V_199 = & F_5 ( V_6 ) -> V_200 . V_13 [ V_9 -> V_5 ] ;
const struct V_75 * V_76 = V_2 -> V_77 -> V_76 ;
struct V_98 * V_99 ;
bool V_201 = false , V_202 = false , V_203 = false ,
V_204 = false ;
F_23 (encoder, &dev->mode_config.encoder_list, head) {
struct V_101 * V_102 = V_101 ( V_99 ) ;
bool V_205 = false ;
if ( V_99 -> V_2 != V_2 )
continue;
if ( V_102 -> V_103 -> type == V_104 )
V_205 = V_201 = true ;
if ( V_102 -> V_103 -> type == V_206 )
V_203 = true ;
if ( V_102 -> V_103 -> type == V_105 )
V_205 = V_202 = true ;
if ( V_102 -> V_103 -> V_207 != V_208 && V_205 )
V_204 = true ;
}
V_11 -> V_7 [ V_209 ] = V_199 -> V_7 [ V_209 ] & ~ ( 1 << 5 ) ;
V_11 -> V_210 = 0 ;
if ( V_9 -> V_5 == 0 )
V_11 -> V_210 |= V_211 ;
#if 0
if (dev->overlayAdaptor) {
NVPortPrivPtr pPriv = GET_OVERLAY_PRIVATE(dev);
if (pPriv->overlayCRTC == nv_crtc->index)
regp->crtc_eng_ctrl |= NV_CRTC_FSEL_OVERLAY;
}
#endif
V_11 -> V_212 = V_213 |
V_214 |
V_215 ;
if ( V_24 -> V_27 . V_28 . V_41 . V_42 >= 0x11 )
V_11 -> V_212 |= V_216 ;
if ( V_21 -> V_106 & V_114 )
V_11 -> V_212 |= V_217 ;
V_11 -> V_7 [ V_218 ] = 0 ;
V_11 -> V_7 [ V_219 ] = 0 ;
if ( V_201 )
V_11 -> V_7 [ V_220 ] = 0x11 ;
else if ( V_202 )
V_11 -> V_7 [ V_220 ] = 0x88 ;
else
V_11 -> V_7 [ V_220 ] = 0x22 ;
V_11 -> V_7 [ V_221 ] = V_199 -> V_7 [ V_221 ] ;
F_4 ( V_2 , V_9 -> V_15 ) ;
if ( V_9 -> V_5 == 0 )
V_11 -> V_7 [ V_222 ] = V_199 -> V_7 [ V_222 ] | 0x80 ;
V_11 -> V_7 [ V_223 ] = F_5 ( V_6 ) -> V_200 . V_13 [ 0 ] . V_7 [ V_223 ] ;
if ( ! V_9 -> V_5 )
V_11 -> V_7 [ V_223 ] += 4 ;
V_11 -> V_7 [ V_224 ] = V_204 ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 >= V_225 )
V_11 -> V_7 [ 0x9f ] = V_204 ? 0x11 : 0x1 ;
V_11 -> V_226 = V_21 -> V_89 - 3 ;
V_11 -> V_227 = V_21 -> V_89 - 1 ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 == V_52 )
V_11 -> V_228 = F_27 ( V_6 , 0 , V_229 ) ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 >= V_225 )
V_11 -> V_230 = F_27 ( V_6 , 0 , V_231 ) ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 >= V_232 )
V_11 -> V_233 = V_234 ;
else
V_11 -> V_233 = V_235 ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 == V_52 ) {
V_11 -> V_7 [ V_236 ] = 0xFF ;
V_11 -> V_7 [ V_237 ] = 0x1 ;
}
V_11 -> V_7 [ V_238 ] = ( V_76 -> V_239 -> V_240 + 1 ) / 8 ;
if ( V_201 || V_202 || V_203 )
V_11 -> V_7 [ V_238 ] |= ( 1 << 7 ) ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 >= V_232 )
V_11 -> V_241 = ( 1 << 25 ) ;
V_11 -> V_242 = V_243 |
V_244 |
V_245 ;
if ( V_76 -> V_239 -> V_240 == 16 )
V_11 -> V_242 |= V_246 ;
if ( V_24 -> V_27 . V_28 . V_41 . V_42 >= 0x11 )
V_11 -> V_242 |= V_247 ;
V_11 -> V_248 = 0 ;
V_11 -> V_249 = 0 ;
F_7 ( V_2 , V_9 -> V_17 ) ;
V_11 -> V_250 = 0x100 ;
V_11 -> V_251 = 0x0 ;
V_11 -> V_252 = 0xfffff ;
V_11 -> V_253 = 0x1 ;
}
static int
F_28 ( struct V_1 * V_2 , struct V_75 * V_254 )
{
struct F_5 * V_255 = F_5 ( V_2 -> V_6 ) ;
struct V_256 * V_257 = V_256 ( V_2 -> V_77 -> V_76 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
int V_258 ;
V_258 = F_29 ( V_257 -> V_259 , V_260 , false ) ;
if ( V_258 == 0 ) {
if ( V_255 -> V_261 [ V_9 -> V_5 ] )
F_30 ( V_255 -> V_261 [ V_9 -> V_5 ] ) ;
F_31 ( V_257 -> V_259 , & V_255 -> V_261 [ V_9 -> V_5 ] ) ;
}
return V_258 ;
}
static int
F_32 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_20 * V_262 ,
int V_263 , int V_264 , struct V_75 * V_254 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
int V_258 ;
F_13 ( V_24 , L_4 , V_9 -> V_5 ) ;
F_33 ( V_262 ) ;
V_258 = F_28 ( V_2 , V_254 ) ;
if ( V_258 )
return V_258 ;
F_34 ( V_6 , V_9 -> V_5 , - 1 ) ;
F_22 ( V_2 , V_262 ) ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 == V_52 )
F_8 ( V_6 , 0 , V_265 , F_5 ( V_6 ) -> V_12 . V_266 ) ;
F_26 ( V_2 , V_262 ) ;
F_9 ( V_2 , V_21 , V_262 -> clock ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_31 * V_32 = & F_5 ( V_6 ) -> V_12 ;
struct V_3 * V_267 = & V_32 -> V_13 [ V_9 -> V_5 ] ;
struct V_31 * V_268 = & F_5 ( V_6 ) -> V_200 ;
struct V_3 * V_269 = & V_268 -> V_13 [ V_9 -> V_5 ] ;
if ( F_15 ( V_2 -> V_6 ) )
F_16 ( V_2 -> V_6 , V_9 -> V_5 ) ;
F_36 ( V_2 -> V_6 , V_9 -> V_5 , V_268 ) ;
V_32 -> V_266 = V_268 -> V_266 & ~ ( 0x5 << 16 ) ;
V_267 -> V_7 [ V_270 ] = V_269 -> V_7 [ V_270 ] ;
V_32 -> V_47 = V_268 -> V_47 & ~ ( V_48 | V_49 | V_50 ) ;
V_267 -> V_230 = V_269 -> V_230 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
int V_271 = V_9 -> V_5 ;
T_1 V_272 = F_5 ( V_6 ) -> V_200 . V_13 [ V_271 ] . V_7 [ V_273 ] ;
if ( F_15 ( V_2 -> V_6 ) )
F_16 ( V_2 -> V_6 , V_271 ) ;
F_38 ( V_2 -> V_6 , V_271 , & F_5 ( V_6 ) -> V_200 ) ;
F_34 ( V_2 -> V_6 , V_271 , V_272 ) ;
V_9 -> V_67 = V_274 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
const struct V_275 * V_276 = V_2 -> V_277 ;
if ( F_15 ( V_6 ) )
F_16 ( V_6 , V_9 -> V_5 ) ;
F_40 ( V_2 ) ;
V_276 -> V_278 ( V_2 , V_71 ) ;
F_41 ( V_6 , V_9 -> V_5 , true ) ;
F_42 ( V_6 , V_9 -> V_5 , V_279 , V_280 ) ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 == V_52 ) {
T_2 V_281 = F_43 ( V_6 , V_9 -> V_5 , V_282 ) ;
F_8 ( V_6 , V_9 -> V_5 , V_282 , V_281 & ~ 0x10000 ) ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
const struct V_275 * V_276 = V_2 -> V_277 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
F_38 ( V_6 , V_9 -> V_5 , & F_5 ( V_6 ) -> V_12 ) ;
F_45 ( V_2 , V_2 -> V_263 , V_2 -> V_264 , NULL ) ;
#ifdef F_46
{
T_1 V_283 = F_17 ( V_6 , V_9 -> V_5 , V_284 ) ;
V_283 |= F_25 ( V_285 ) ;
F_2 ( V_6 , V_9 -> V_5 , V_284 , V_283 ) ;
}
#endif
V_276 -> V_278 ( V_2 , V_72 ) ;
F_47 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct F_5 * V_255 = F_5 ( V_2 -> V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
if ( ! V_9 )
return;
F_49 ( V_2 ) ;
if ( V_255 -> V_261 [ V_9 -> V_5 ] )
F_30 ( V_255 -> V_261 [ V_9 -> V_5 ] ) ;
F_31 ( NULL , & V_255 -> V_261 [ V_9 -> V_5 ] ) ;
F_50 ( V_9 -> V_61 . V_259 ) ;
F_30 ( V_9 -> V_61 . V_259 ) ;
F_31 ( NULL , & V_9 -> V_61 . V_259 ) ;
F_51 ( V_9 ) ;
}
static void
F_52 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_9 -> V_286 . V_6 ;
struct V_287 { T_1 V_288 , V_289 , V_290 ; } V_291 ( ( V_292 ) ) * V_293 ;
T_3 * V_288 , * V_289 , * V_290 ;
int V_294 ;
V_293 = (struct V_287 * ) F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] . V_295 ;
V_288 = V_2 -> V_296 ;
V_289 = V_288 + V_2 -> V_297 ;
V_290 = V_289 + V_2 -> V_297 ;
for ( V_294 = 0 ; V_294 < 256 ; V_294 ++ ) {
V_293 [ V_294 ] . V_288 = * V_288 ++ >> 8 ;
V_293 [ V_294 ] . V_289 = * V_289 ++ >> 8 ;
V_293 [ V_294 ] . V_290 = * V_290 ++ >> 8 ;
}
F_53 ( V_6 , V_9 -> V_5 , & F_5 ( V_6 ) -> V_12 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct F_5 * V_255 = F_5 ( V_2 -> V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
if ( V_255 -> V_261 [ V_9 -> V_5 ] )
F_30 ( V_255 -> V_261 [ V_9 -> V_5 ] ) ;
F_31 ( NULL , & V_255 -> V_261 [ V_9 -> V_5 ] ) ;
}
static int
F_55 ( struct V_1 * V_2 , T_3 * V_288 , T_3 * V_289 , T_3 * V_290 ,
T_2 V_298 ,
struct V_299 * V_300 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
if ( ! V_9 -> V_286 . V_77 -> V_76 ) {
V_9 -> V_301 . V_240 = 0 ;
return 0 ;
}
F_52 ( V_2 ) ;
return 0 ;
}
static int
F_56 ( struct V_1 * V_2 ,
struct V_75 * V_302 ,
int V_263 , int V_264 , bool V_303 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_75 * V_304 ;
struct V_256 * V_76 ;
int V_305 , V_306 ;
F_13 ( V_24 , L_5 , V_9 -> V_5 ) ;
if ( ! V_303 && ! V_2 -> V_77 -> V_76 ) {
F_13 ( V_24 , L_6 ) ;
return 0 ;
}
if ( V_303 ) {
V_304 = V_302 ;
V_76 = V_256 ( V_302 ) ;
} else {
V_304 = V_2 -> V_77 -> V_76 ;
V_76 = V_256 ( V_2 -> V_77 -> V_76 ) ;
}
V_9 -> V_76 . V_63 = V_76 -> V_259 -> V_307 . V_63 ;
if ( V_9 -> V_301 . V_240 != V_304 -> V_239 -> V_240 ) {
V_9 -> V_301 . V_240 = V_304 -> V_239 -> V_240 ;
F_52 ( V_2 ) ;
}
V_11 -> V_7 [ V_238 ] &= ~ 3 ;
V_11 -> V_7 [ V_238 ] |= ( V_304 -> V_239 -> V_240 + 1 ) / 8 ;
V_11 -> V_242 &= ~ V_246 ;
if ( V_304 -> V_239 -> V_240 == 16 )
V_11 -> V_242 |= V_246 ;
F_1 ( V_2 , V_11 , V_238 ) ;
F_8 ( V_6 , V_9 -> V_5 , V_308 ,
V_11 -> V_242 ) ;
V_11 -> V_7 [ V_154 ] = V_304 -> V_155 [ 0 ] >> 3 ;
V_11 -> V_7 [ V_160 ] =
F_24 ( V_304 -> V_155 [ 0 ] >> 3 , 8 , V_161 ) ;
V_11 -> V_7 [ V_162 ] =
F_24 ( V_304 -> V_155 [ 0 ] / 8 , 11 , V_163 ) ;
F_1 ( V_2 , V_11 , V_160 ) ;
F_1 ( V_2 , V_11 , V_154 ) ;
F_1 ( V_2 , V_11 , V_162 ) ;
V_11 -> V_309 = V_9 -> V_76 . V_63 & ~ 3 ;
V_11 -> V_309 += ( V_264 * V_304 -> V_155 [ 0 ] ) + ( V_263 * V_304 -> V_239 -> V_310 [ 0 ] ) ;
F_57 ( V_6 , V_9 -> V_5 , V_11 -> V_309 ) ;
F_58 ( V_6 , V_2 -> V_21 . clock , V_304 -> V_239 -> V_310 [ 0 ] * 8 ,
& V_305 , & V_306 ) ;
V_11 -> V_7 [ V_311 ] = V_305 ;
V_11 -> V_7 [ V_312 ] = V_306 & 0xff ;
F_1 ( V_2 , V_11 , V_311 ) ;
F_1 ( V_2 , V_11 , V_312 ) ;
if ( V_24 -> V_27 . V_28 . V_41 . V_51 >= V_313 ) {
V_11 -> V_7 [ V_314 ] = V_306 >> 8 ;
F_1 ( V_2 , V_11 , V_314 ) ;
}
return 0 ;
}
static int
F_45 ( struct V_1 * V_2 , int V_263 , int V_264 ,
struct V_75 * V_254 )
{
int V_258 = F_28 ( V_2 , V_254 ) ;
if ( V_258 )
return V_258 ;
return F_56 ( V_2 , V_254 , V_263 , V_264 , false ) ;
}
static int
F_59 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
int V_263 , int V_264 , enum V_315 V_32 )
{
struct V_23 * V_24 = V_23 ( V_2 -> V_6 ) ;
struct V_10 * V_6 = V_24 -> V_6 ;
if ( V_32 == V_316 )
F_60 ( V_6 ) ;
else
F_61 ( V_6 ) ;
return F_56 ( V_2 , V_76 , V_263 , V_264 , true ) ;
}
static void F_62 ( struct V_10 * V_6 , struct V_317 * V_318 ,
struct V_317 * V_319 )
{
int V_320 = F_63 ( V_6 ) ;
T_2 V_321 ;
int V_294 , V_322 ;
for ( V_294 = 0 ; V_294 < V_320 ; V_294 ++ ) {
for ( V_322 = 0 ; V_322 < V_320 ; V_322 ++ ) {
V_321 = F_64 ( V_318 , V_294 * 64 + V_322 ) ;
F_65 ( V_319 , V_294 * V_320 + V_322 , ( V_321 & 0x80000000 ) >> 16
| ( V_321 & 0xf80000 ) >> 9
| ( V_321 & 0xf800 ) >> 6
| ( V_321 & 0xf8 ) >> 3 ) ;
}
}
}
static void F_66 ( struct V_10 * V_6 , struct V_317 * V_318 ,
struct V_317 * V_319 )
{
T_2 V_321 ;
int V_323 , V_294 ;
for ( V_294 = 0 ; V_294 < 64 * 64 ; V_294 ++ ) {
V_321 = F_64 ( V_318 , V_294 ) ;
V_323 = V_321 >> 24 ;
if ( V_323 > 0 && V_323 < 255 )
V_321 = ( V_321 & 0x00ffffff ) | ( ( V_323 + 1 ) << 24 ) ;
#ifdef F_46
{
struct V_23 * V_24 = V_23 ( V_6 ) ;
if ( V_24 -> V_27 . V_28 . V_41 . V_42 == 0x11 ) {
V_321 = ( ( V_321 & 0x000000ff ) << 24 ) |
( ( V_321 & 0x0000ff00 ) << 8 ) |
( ( V_321 & 0x00ff0000 ) >> 8 ) |
( ( V_321 & 0xff000000 ) >> 24 ) ;
}
}
#endif
F_67 ( V_319 , V_294 , V_321 ) ;
}
}
static int
F_68 ( struct V_1 * V_2 , struct V_324 * V_325 ,
T_2 V_326 , T_2 V_320 , T_2 V_327 )
{
struct V_23 * V_24 = V_23 ( V_2 -> V_6 ) ;
struct V_10 * V_6 = V_24 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_317 * V_61 = NULL ;
struct V_328 * V_329 ;
int V_258 = 0 ;
if ( ! V_326 ) {
V_9 -> V_61 . V_330 ( V_9 , true ) ;
return 0 ;
}
if ( V_320 != 64 || V_327 != 64 )
return - V_331 ;
V_329 = F_69 ( V_325 , V_326 ) ;
if ( ! V_329 )
return - V_332 ;
V_61 = F_70 ( V_329 ) ;
V_258 = F_71 ( V_61 ) ;
if ( V_258 )
goto V_333;
if ( V_24 -> V_27 . V_28 . V_41 . V_42 >= 0x11 )
F_66 ( V_6 , V_61 , V_9 -> V_61 . V_259 ) ;
else
F_62 ( V_6 , V_61 , V_9 -> V_61 . V_259 ) ;
F_50 ( V_61 ) ;
V_9 -> V_61 . V_63 = V_9 -> V_61 . V_259 -> V_307 . V_63 ;
V_9 -> V_61 . V_62 ( V_9 , V_9 -> V_61 . V_63 ) ;
V_9 -> V_61 . V_334 ( V_9 , true ) ;
V_333:
F_72 ( V_329 ) ;
return V_258 ;
}
static int
F_73 ( struct V_1 * V_2 , int V_263 , int V_264 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
V_9 -> V_61 . V_335 ( V_9 , V_263 , V_264 ) ;
return 0 ;
}
static int
F_74 ( struct V_336 * V_337 ,
struct V_299 * V_300 )
{
struct V_10 * V_6 ;
struct V_23 * V_24 ;
int V_258 ;
struct V_1 * V_2 ;
bool V_338 = false ;
if ( ! V_337 || ! V_337 -> V_2 )
return - V_331 ;
V_6 = V_337 -> V_2 -> V_6 ;
V_258 = F_75 ( V_6 -> V_6 ) ;
if ( V_258 < 0 && V_258 != - V_339 )
return V_258 ;
V_258 = F_76 ( V_337 , V_300 ) ;
V_24 = V_23 ( V_6 ) ;
F_23 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 -> V_340 )
V_338 = true ;
}
F_77 ( V_6 -> V_6 ) ;
if ( V_338 && ! V_24 -> V_341 ) {
V_24 -> V_341 = true ;
return V_258 ;
}
if ( ! V_338 && V_24 -> V_341 ) {
F_78 ( V_6 -> V_6 ) ;
V_24 -> V_341 = false ;
}
F_78 ( V_6 -> V_6 ) ;
return V_258 ;
}
static struct V_342 *
F_79 ( struct V_10 * V_6 )
{
struct V_342 * V_77 ;
int V_258 ;
V_77 = F_80 ( sizeof( * V_77 ) , V_343 ) ;
if ( V_77 == NULL ) {
F_81 ( L_7 ) ;
return NULL ;
}
V_258 = F_82 ( V_6 , V_77 , 0 ,
& V_344 ,
V_345 ,
F_83 ( V_345 ) , NULL ,
V_346 , NULL ) ;
if ( V_258 ) {
F_51 ( V_77 ) ;
V_77 = NULL ;
}
return V_77 ;
}
int
F_84 ( struct V_10 * V_6 , int V_347 )
{
struct F_3 * V_9 ;
int V_258 ;
V_9 = F_80 ( sizeof( * V_9 ) , V_343 ) ;
if ( ! V_9 )
return - V_348 ;
V_9 -> V_301 . V_240 = 0 ;
V_9 -> V_5 = V_347 ;
V_9 -> V_67 = V_274 ;
V_9 -> V_349 = F_35 ;
V_9 -> V_350 = F_37 ;
F_85 ( V_6 , & V_9 -> V_286 ,
F_79 ( V_6 ) , NULL ,
& V_351 , NULL ) ;
F_86 ( & V_9 -> V_286 , & V_352 ) ;
F_87 ( & V_9 -> V_286 , 256 ) ;
V_258 = F_88 ( & V_23 ( V_6 ) -> V_27 , 64 * 64 * 4 , 0x100 ,
V_260 , 0 , 0x0000 , NULL , NULL ,
& V_9 -> V_61 . V_259 ) ;
if ( ! V_258 ) {
V_258 = F_29 ( V_9 -> V_61 . V_259 , V_260 , false ) ;
if ( ! V_258 ) {
V_258 = F_71 ( V_9 -> V_61 . V_259 ) ;
if ( V_258 )
F_30 ( V_9 -> V_61 . V_259 ) ;
}
if ( V_258 )
F_31 ( NULL , & V_9 -> V_61 . V_259 ) ;
}
F_89 ( V_9 ) ;
return 0 ;
}
