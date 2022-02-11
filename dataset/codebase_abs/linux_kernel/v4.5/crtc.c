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
struct V_25 * V_26 = F_10 ( & V_24 -> V_27 ) ;
struct V_28 * V_29 = F_11 ( & V_24 -> V_27 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_30 * V_31 = & F_5 ( V_6 ) -> V_12 ;
struct V_3 * V_11 = & V_31 -> V_13 [ V_9 -> V_5 ] ;
struct V_32 * V_33 = & V_11 -> V_34 ;
struct V_35 V_36 ;
if ( F_12 ( V_26 , V_9 -> V_5 ? V_37 : V_38 ,
& V_36 ) )
return;
V_33 -> V_39 = 0 ;
if ( V_24 -> V_27 . V_40 . V_41 > 0x40 && V_22 <= ( V_36 . V_42 . V_43 / 2 ) )
memset ( & V_36 . V_44 , 0 , sizeof( V_36 . V_44 ) ) ;
if ( ! V_29 -> V_45 ( V_29 , & V_36 , V_22 , V_33 ) )
return;
V_31 -> V_46 &= V_47 | V_48 | V_49 ;
if ( V_24 -> V_27 . V_40 . V_50 == V_51 )
V_31 -> V_46 |= V_52 ;
if ( V_24 -> V_27 . V_40 . V_41 < 0x41 )
V_31 -> V_46 |= V_53 |
V_54 ;
V_31 -> V_46 |= V_9 -> V_5 ? V_48 : V_47 ;
if ( V_33 -> V_39 )
F_13 ( V_24 , L_1 ,
V_33 -> V_55 , V_33 -> V_56 , V_33 -> V_57 , V_33 -> V_58 , V_33 -> V_59 ) ;
else
F_13 ( V_24 , L_2 ,
V_33 -> V_55 , V_33 -> V_57 , V_33 -> V_59 ) ;
V_9 -> V_60 . V_61 ( V_9 , V_9 -> V_60 . V_62 ) ;
}
static void
F_14 ( struct V_1 * V_2 , int V_21 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
unsigned char V_63 = 0 , V_64 = 0 ;
unsigned char V_65 ;
F_13 ( V_24 , L_3 , V_21 ,
V_9 -> V_5 ) ;
if ( V_9 -> V_66 == V_21 )
return;
V_9 -> V_66 = V_21 ;
if ( F_15 ( V_6 ) )
F_16 ( V_6 , V_9 -> V_5 ) ;
V_65 = F_17 ( V_6 , V_9 -> V_5 ,
V_67 ) & ~ 0xC0 ;
switch ( V_21 ) {
case V_68 :
V_63 = 0x20 ;
V_64 = 0x80 ;
V_65 |= 0x80 ;
break;
case V_69 :
V_63 = 0x20 ;
V_64 = 0x80 ;
V_65 |= 0x40 ;
break;
case V_70 :
V_63 = 0x20 ;
V_64 = 0x00 ;
V_65 |= 0xC0 ;
break;
case V_71 :
default:
V_63 = 0x00 ;
V_64 = 0x80 ;
break;
}
F_18 ( V_6 , V_9 -> V_5 , true ) ;
V_63 |= ( F_19 ( V_6 , V_9 -> V_5 , V_72 ) & ~ 0x20 ) ;
F_20 ( V_6 , V_9 -> V_5 , V_72 , V_63 ) ;
V_64 |= ( F_17 ( V_6 , V_9 -> V_5 , V_73 ) & ~ 0x80 ) ;
F_21 ( 10 ) ;
F_2 ( V_6 , V_9 -> V_5 , V_73 , V_64 ) ;
F_18 ( V_6 , V_9 -> V_5 , false ) ;
F_2 ( V_6 , V_9 -> V_5 , V_67 , V_65 ) ;
}
static bool
F_22 ( struct V_1 * V_2 , const struct V_20 * V_21 ,
struct V_20 * V_74 )
{
return true ;
}
static void
F_23 ( struct V_1 * V_2 , struct V_20 * V_21 )
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
F_24 (encoder, &dev->mode_config.encoder_list, head) {
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
if (dev->overlayAdaptor && drm->device.info.family >= NV_DEVICE_INFO_V0_CELSIUS)
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
V_11 -> V_116 [ V_72 ] = 0x29 ;
else
V_11 -> V_116 [ V_72 ] = 0x21 ;
V_11 -> V_116 [ V_119 ] = 0x0F ;
V_11 -> V_116 [ V_120 ] = 0x00 ;
V_11 -> V_116 [ V_121 ] = 0x0E ;
V_11 -> V_7 [ V_122 ] = V_84 ;
V_11 -> V_7 [ V_123 ] = V_78 ;
V_11 -> V_7 [ V_124 ] = V_86 ;
V_11 -> V_7 [ V_125 ] = ( 1 << 7 ) |
F_25 ( V_87 , 0 , V_126 ) ;
V_11 -> V_7 [ V_127 ] = V_80 ;
V_11 -> V_7 [ V_128 ] = F_25 ( V_87 , 5 , V_129 ) |
F_25 ( V_82 , 0 , V_130 ) ;
V_11 -> V_7 [ V_131 ] = V_94 ;
V_11 -> V_7 [ V_132 ] = F_25 ( V_90 , 9 , V_133 ) |
F_25 ( V_88 , 9 , V_134 ) |
F_25 ( V_94 , 9 , V_135 ) |
( 1 << 4 ) |
F_25 ( V_96 , 8 , V_136 ) |
F_25 ( V_90 , 8 , V_137 ) |
F_25 ( V_88 , 8 , V_138 ) |
F_25 ( V_94 , 8 , V_139 ) ;
V_11 -> V_7 [ V_140 ] = 0x00 ;
V_11 -> V_7 [ V_141 ] = ( ( V_21 -> V_106 & V_114 ) ? F_26 ( V_142 ) : 0 ) |
1 << 6 |
F_25 ( V_96 , 9 , V_143 ) ;
V_11 -> V_7 [ V_144 ] = 0x00 ;
V_11 -> V_7 [ V_145 ] = 0x00 ;
V_11 -> V_7 [ V_146 ] = 0x00 ;
V_11 -> V_7 [ V_147 ] = 0x00 ;
V_11 -> V_7 [ V_148 ] = 0x00 ;
V_11 -> V_7 [ V_149 ] = 0x00 ;
V_11 -> V_7 [ V_150 ] = V_90 ;
V_11 -> V_7 [ V_151 ] = 1 << 5 | F_25 ( V_92 , 0 , V_152 ) ;
V_11 -> V_7 [ V_153 ] = V_88 ;
V_11 -> V_7 [ V_154 ] = V_76 -> V_155 [ 0 ] / 8 ;
V_11 -> V_7 [ V_156 ] = 0x00 ;
V_11 -> V_7 [ V_157 ] = V_96 ;
V_11 -> V_7 [ V_158 ] = V_97 ;
V_11 -> V_7 [ V_73 ] = 0x43 ;
V_11 -> V_7 [ V_159 ] = 0xff ;
V_11 -> V_7 [ V_160 ] =
F_25 ( V_76 -> V_155 [ 0 ] / 8 , 8 , V_161 ) ;
V_11 -> V_7 [ V_162 ] =
F_25 ( V_76 -> V_155 [ 0 ] / 8 , 11 , V_163 ) ;
V_11 -> V_7 [ V_67 ] = V_21 -> V_79 < 1280 ?
F_26 ( V_164 ) : 0x00 ;
V_11 -> V_7 [ V_165 ] = F_25 ( V_87 , 6 , V_166 ) |
F_25 ( V_96 , 10 , V_167 ) |
F_25 ( V_90 , 10 , V_168 ) |
F_25 ( V_88 , 10 , V_169 ) |
F_25 ( V_94 , 10 , V_170 ) ;
V_11 -> V_7 [ V_171 ] = F_25 ( V_80 , 8 , V_172 ) |
F_25 ( V_86 , 8 , V_173 ) |
F_25 ( V_78 , 8 , V_174 ) |
F_25 ( V_84 , 8 , V_175 ) ;
V_11 -> V_7 [ V_176 ] = F_25 ( V_96 , 11 , V_177 ) |
F_25 ( V_90 , 11 , V_178 ) |
F_25 ( V_88 , 11 , V_179 ) |
F_25 ( V_94 , 11 , V_180 ) ;
if ( V_21 -> V_106 & V_107 ) {
V_84 = ( V_84 >> 1 ) & ~ 1 ;
V_11 -> V_7 [ V_181 ] = V_84 ;
V_11 -> V_7 [ V_171 ] |= F_25 ( V_84 , 8 , V_182 ) ;
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
F_27 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_3 * V_199 = & F_5 ( V_6 ) -> V_200 . V_13 [ V_9 -> V_5 ] ;
struct V_98 * V_99 ;
bool V_201 = false , V_202 = false , V_203 = false ,
V_204 = false ;
F_24 (encoder, &dev->mode_config.encoder_list, head) {
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
if ( V_24 -> V_27 . V_40 . V_41 >= 0x11 )
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
if ( V_24 -> V_27 . V_40 . V_50 >= V_225 )
V_11 -> V_7 [ 0x9f ] = V_204 ? 0x11 : 0x1 ;
V_11 -> V_226 = V_21 -> V_89 - 3 ;
V_11 -> V_227 = V_21 -> V_89 - 1 ;
if ( V_24 -> V_27 . V_40 . V_50 == V_51 )
V_11 -> V_228 = F_28 ( V_6 , 0 , V_229 ) ;
if ( V_24 -> V_27 . V_40 . V_50 >= V_225 )
V_11 -> V_230 = F_28 ( V_6 , 0 , V_231 ) ;
if ( V_24 -> V_27 . V_40 . V_50 >= V_232 )
V_11 -> V_233 = V_234 ;
else
V_11 -> V_233 = V_235 ;
if ( V_24 -> V_27 . V_40 . V_50 == V_51 ) {
V_11 -> V_7 [ V_236 ] = 0xFF ;
V_11 -> V_7 [ V_237 ] = 0x1 ;
}
V_11 -> V_7 [ V_238 ] = ( V_2 -> V_77 -> V_76 -> V_239 + 1 ) / 8 ;
if ( V_201 || V_202 || V_203 )
V_11 -> V_7 [ V_238 ] |= ( 1 << 7 ) ;
if ( V_24 -> V_27 . V_40 . V_50 >= V_232 )
V_11 -> V_240 = ( 1 << 25 ) ;
V_11 -> V_241 = V_242 |
V_243 |
V_244 ;
if ( V_2 -> V_77 -> V_76 -> V_239 == 16 )
V_11 -> V_241 |= V_245 ;
if ( V_24 -> V_27 . V_40 . V_41 >= 0x11 )
V_11 -> V_241 |= V_246 ;
V_11 -> V_247 = 0 ;
V_11 -> V_248 = 0 ;
F_7 ( V_2 , V_9 -> V_17 ) ;
V_11 -> V_249 = 0x100 ;
V_11 -> V_250 = 0x0 ;
V_11 -> V_251 = 0xfffff ;
V_11 -> V_252 = 0x1 ;
}
static int
F_29 ( struct V_1 * V_2 , struct V_75 * V_253 )
{
struct F_5 * V_254 = F_5 ( V_2 -> V_6 ) ;
struct V_255 * V_256 = V_255 ( V_2 -> V_77 -> V_76 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
int V_257 ;
V_257 = F_30 ( V_256 -> V_258 , V_259 , false ) ;
if ( V_257 == 0 ) {
if ( V_254 -> V_260 [ V_9 -> V_5 ] )
F_31 ( V_254 -> V_260 [ V_9 -> V_5 ] ) ;
F_32 ( V_256 -> V_258 , & V_254 -> V_260 [ V_9 -> V_5 ] ) ;
}
return V_257 ;
}
static int
F_33 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_20 * V_74 ,
int V_261 , int V_262 , struct V_75 * V_253 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
int V_257 ;
F_13 ( V_24 , L_4 , V_9 -> V_5 ) ;
F_34 ( V_74 ) ;
V_257 = F_29 ( V_2 , V_253 ) ;
if ( V_257 )
return V_257 ;
F_35 ( V_6 , V_9 -> V_5 , - 1 ) ;
F_23 ( V_2 , V_74 ) ;
if ( V_24 -> V_27 . V_40 . V_50 == V_51 )
F_8 ( V_6 , 0 , V_263 , F_5 ( V_6 ) -> V_12 . V_264 ) ;
F_27 ( V_2 , V_74 ) ;
F_9 ( V_2 , V_21 , V_74 -> clock ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_30 * V_31 = & F_5 ( V_6 ) -> V_12 ;
struct V_3 * V_265 = & V_31 -> V_13 [ V_9 -> V_5 ] ;
struct V_30 * V_266 = & F_5 ( V_6 ) -> V_200 ;
struct V_3 * V_267 = & V_266 -> V_13 [ V_9 -> V_5 ] ;
if ( F_15 ( V_2 -> V_6 ) )
F_16 ( V_2 -> V_6 , V_9 -> V_5 ) ;
F_37 ( V_2 -> V_6 , V_9 -> V_5 , V_266 ) ;
V_31 -> V_264 = V_266 -> V_264 & ~ ( 0x5 << 16 ) ;
V_265 -> V_7 [ V_268 ] = V_267 -> V_7 [ V_268 ] ;
V_31 -> V_46 = V_266 -> V_46 & ~ ( V_47 | V_48 | V_49 ) ;
V_265 -> V_230 = V_267 -> V_230 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
int V_269 = V_9 -> V_5 ;
T_1 V_270 = F_5 ( V_6 ) -> V_200 . V_13 [ V_269 ] . V_7 [ V_271 ] ;
if ( F_15 ( V_2 -> V_6 ) )
F_16 ( V_2 -> V_6 , V_269 ) ;
F_39 ( V_2 -> V_6 , V_269 , & F_5 ( V_6 ) -> V_200 ) ;
F_35 ( V_2 -> V_6 , V_269 , V_270 ) ;
V_9 -> V_66 = V_272 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
const struct V_273 * V_274 = V_2 -> V_275 ;
if ( F_15 ( V_6 ) )
F_16 ( V_6 , V_9 -> V_5 ) ;
F_41 ( V_6 , V_9 -> V_5 ) ;
V_274 -> V_276 ( V_2 , V_70 ) ;
F_42 ( V_6 , V_9 -> V_5 , true ) ;
F_43 ( V_6 , V_9 -> V_5 , V_277 , V_278 ) ;
if ( V_24 -> V_27 . V_40 . V_50 == V_51 ) {
T_2 V_279 = F_44 ( V_6 , V_9 -> V_5 , V_280 ) ;
F_8 ( V_6 , V_9 -> V_5 , V_280 , V_279 & ~ 0x10000 ) ;
}
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
const struct V_273 * V_274 = V_2 -> V_275 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
F_39 ( V_6 , V_9 -> V_5 , & F_5 ( V_6 ) -> V_12 ) ;
F_46 ( V_2 , V_2 -> V_261 , V_2 -> V_262 , NULL ) ;
#ifdef F_47
{
T_1 V_281 = F_17 ( V_6 , V_9 -> V_5 , V_282 ) ;
V_281 |= F_26 ( V_283 ) ;
F_2 ( V_6 , V_9 -> V_5 , V_282 , V_281 ) ;
}
#endif
V_274 -> V_276 ( V_2 , V_71 ) ;
F_48 ( V_6 , V_9 -> V_5 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct F_5 * V_254 = F_5 ( V_2 -> V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
if ( ! V_9 )
return;
F_50 ( V_2 ) ;
if ( V_254 -> V_260 [ V_9 -> V_5 ] )
F_31 ( V_254 -> V_260 [ V_9 -> V_5 ] ) ;
F_32 ( NULL , & V_254 -> V_260 [ V_9 -> V_5 ] ) ;
F_51 ( V_9 -> V_60 . V_258 ) ;
F_31 ( V_9 -> V_60 . V_258 ) ;
F_32 ( NULL , & V_9 -> V_60 . V_258 ) ;
F_52 ( V_9 ) ;
}
static void
F_53 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_9 -> V_284 . V_6 ;
struct V_285 { T_1 V_286 , V_287 , V_288 ; } V_289 ( ( V_290 ) ) * V_291 ;
int V_292 ;
V_291 = (struct V_285 * ) F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] . V_293 ;
for ( V_292 = 0 ; V_292 < 256 ; V_292 ++ ) {
V_291 [ V_292 ] . V_286 = V_9 -> V_294 . V_286 [ V_292 ] >> 8 ;
V_291 [ V_292 ] . V_287 = V_9 -> V_294 . V_287 [ V_292 ] >> 8 ;
V_291 [ V_292 ] . V_288 = V_9 -> V_294 . V_288 [ V_292 ] >> 8 ;
}
F_54 ( V_6 , V_9 -> V_5 , & F_5 ( V_6 ) -> V_12 ) ;
}
static void
F_55 ( struct V_1 * V_2 )
{
struct F_5 * V_254 = F_5 ( V_2 -> V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
if ( V_254 -> V_260 [ V_9 -> V_5 ] )
F_31 ( V_254 -> V_260 [ V_9 -> V_5 ] ) ;
F_32 ( NULL , & V_254 -> V_260 [ V_9 -> V_5 ] ) ;
}
static void
F_56 ( struct V_1 * V_2 , T_3 * V_286 , T_3 * V_287 , T_3 * V_288 , T_2 V_295 ,
T_2 V_296 )
{
int V_297 = ( V_295 + V_296 > 256 ) ? 256 : V_295 + V_296 , V_292 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
for ( V_292 = V_295 ; V_292 < V_297 ; V_292 ++ ) {
V_9 -> V_294 . V_286 [ V_292 ] = V_286 [ V_292 ] ;
V_9 -> V_294 . V_287 [ V_292 ] = V_287 [ V_292 ] ;
V_9 -> V_294 . V_288 [ V_292 ] = V_288 [ V_292 ] ;
}
if ( ! V_9 -> V_284 . V_77 -> V_76 ) {
V_9 -> V_294 . V_239 = 0 ;
return;
}
F_53 ( V_2 ) ;
}
static int
F_57 ( struct V_1 * V_2 ,
struct V_75 * V_298 ,
int V_261 , int V_262 , bool V_299 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_75 * V_300 ;
struct V_255 * V_76 ;
int V_301 , V_302 ;
F_13 ( V_24 , L_5 , V_9 -> V_5 ) ;
if ( ! V_299 && ! V_2 -> V_77 -> V_76 ) {
F_13 ( V_24 , L_6 ) ;
return 0 ;
}
if ( V_299 ) {
V_300 = V_298 ;
V_76 = V_255 ( V_298 ) ;
} else {
V_300 = V_2 -> V_77 -> V_76 ;
V_76 = V_255 ( V_2 -> V_77 -> V_76 ) ;
}
V_9 -> V_76 . V_62 = V_76 -> V_258 -> V_303 . V_62 ;
if ( V_9 -> V_294 . V_239 != V_300 -> V_239 ) {
V_9 -> V_294 . V_239 = V_300 -> V_239 ;
F_53 ( V_2 ) ;
}
V_11 -> V_7 [ V_238 ] &= ~ 3 ;
V_11 -> V_7 [ V_238 ] |= ( V_2 -> V_77 -> V_76 -> V_239 + 1 ) / 8 ;
V_11 -> V_241 &= ~ V_245 ;
if ( V_2 -> V_77 -> V_76 -> V_239 == 16 )
V_11 -> V_241 |= V_245 ;
F_1 ( V_2 , V_11 , V_238 ) ;
F_8 ( V_6 , V_9 -> V_5 , V_304 ,
V_11 -> V_241 ) ;
V_11 -> V_7 [ V_154 ] = V_300 -> V_155 [ 0 ] >> 3 ;
V_11 -> V_7 [ V_160 ] =
F_25 ( V_300 -> V_155 [ 0 ] >> 3 , 8 , V_161 ) ;
V_11 -> V_7 [ V_162 ] =
F_25 ( V_300 -> V_155 [ 0 ] / 8 , 11 , V_163 ) ;
F_1 ( V_2 , V_11 , V_160 ) ;
F_1 ( V_2 , V_11 , V_154 ) ;
F_1 ( V_2 , V_11 , V_162 ) ;
V_11 -> V_305 = V_9 -> V_76 . V_62 & ~ 3 ;
V_11 -> V_305 += ( V_262 * V_300 -> V_155 [ 0 ] ) + ( V_261 * V_300 -> V_306 / 8 ) ;
F_58 ( V_6 , V_9 -> V_5 , V_11 -> V_305 ) ;
F_59 ( V_6 , V_2 -> V_21 . clock , V_300 -> V_306 ,
& V_301 , & V_302 ) ;
V_11 -> V_7 [ V_307 ] = V_301 ;
V_11 -> V_7 [ V_308 ] = V_302 & 0xff ;
F_1 ( V_2 , V_11 , V_307 ) ;
F_1 ( V_2 , V_11 , V_308 ) ;
if ( V_24 -> V_27 . V_40 . V_50 >= V_309 ) {
V_11 -> V_7 [ V_310 ] = V_302 >> 8 ;
F_1 ( V_2 , V_11 , V_310 ) ;
}
return 0 ;
}
static int
F_46 ( struct V_1 * V_2 , int V_261 , int V_262 ,
struct V_75 * V_253 )
{
int V_257 = F_29 ( V_2 , V_253 ) ;
if ( V_257 )
return V_257 ;
return F_57 ( V_2 , V_253 , V_261 , V_262 , false ) ;
}
static int
F_60 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
int V_261 , int V_262 , enum V_311 V_31 )
{
struct V_23 * V_24 = V_23 ( V_2 -> V_6 ) ;
struct V_10 * V_6 = V_24 -> V_6 ;
if ( V_31 == V_312 )
F_61 ( V_6 ) ;
else
F_62 ( V_6 ) ;
return F_57 ( V_2 , V_76 , V_261 , V_262 , true ) ;
}
static void F_63 ( struct V_10 * V_6 , struct V_313 * V_314 ,
struct V_313 * V_315 )
{
int V_316 = F_64 ( V_6 ) ;
T_2 V_317 ;
int V_292 , V_318 ;
for ( V_292 = 0 ; V_292 < V_316 ; V_292 ++ ) {
for ( V_318 = 0 ; V_318 < V_316 ; V_318 ++ ) {
V_317 = F_65 ( V_314 , V_292 * 64 + V_318 ) ;
F_66 ( V_315 , V_292 * V_316 + V_318 , ( V_317 & 0x80000000 ) >> 16
| ( V_317 & 0xf80000 ) >> 9
| ( V_317 & 0xf800 ) >> 6
| ( V_317 & 0xf8 ) >> 3 ) ;
}
}
}
static void F_67 ( struct V_10 * V_6 , struct V_313 * V_314 ,
struct V_313 * V_315 )
{
T_2 V_317 ;
int V_319 , V_292 ;
for ( V_292 = 0 ; V_292 < 64 * 64 ; V_292 ++ ) {
V_317 = F_65 ( V_314 , V_292 ) ;
V_319 = V_317 >> 24 ;
if ( V_319 > 0 && V_319 < 255 )
V_317 = ( V_317 & 0x00ffffff ) | ( ( V_319 + 1 ) << 24 ) ;
#ifdef F_47
{
struct V_23 * V_24 = V_23 ( V_6 ) ;
if ( V_24 -> V_27 . V_40 . V_41 == 0x11 ) {
V_317 = ( ( V_317 & 0x000000ff ) << 24 ) |
( ( V_317 & 0x0000ff00 ) << 8 ) |
( ( V_317 & 0x00ff0000 ) >> 8 ) |
( ( V_317 & 0xff000000 ) >> 24 ) ;
}
}
#endif
F_68 ( V_315 , V_292 , V_317 ) ;
}
}
static int
F_69 ( struct V_1 * V_2 , struct V_320 * V_321 ,
T_2 V_322 , T_2 V_316 , T_2 V_323 )
{
struct V_23 * V_24 = V_23 ( V_2 -> V_6 ) ;
struct V_10 * V_6 = V_24 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_313 * V_60 = NULL ;
struct V_324 * V_325 ;
int V_257 = 0 ;
if ( ! V_322 ) {
V_9 -> V_60 . V_326 ( V_9 , true ) ;
return 0 ;
}
if ( V_316 != 64 || V_323 != 64 )
return - V_327 ;
V_325 = F_70 ( V_6 , V_321 , V_322 ) ;
if ( ! V_325 )
return - V_328 ;
V_60 = F_71 ( V_325 ) ;
V_257 = F_72 ( V_60 ) ;
if ( V_257 )
goto V_329;
if ( V_24 -> V_27 . V_40 . V_41 >= 0x11 )
F_67 ( V_6 , V_60 , V_9 -> V_60 . V_258 ) ;
else
F_63 ( V_6 , V_60 , V_9 -> V_60 . V_258 ) ;
F_51 ( V_60 ) ;
V_9 -> V_60 . V_62 = V_9 -> V_60 . V_258 -> V_303 . V_62 ;
V_9 -> V_60 . V_61 ( V_9 , V_9 -> V_60 . V_62 ) ;
V_9 -> V_60 . V_330 ( V_9 , true ) ;
V_329:
F_73 ( V_325 ) ;
return V_257 ;
}
static int
F_74 ( struct V_1 * V_2 , int V_261 , int V_262 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
V_9 -> V_60 . V_331 ( V_9 , V_261 , V_262 ) ;
return 0 ;
}
int
F_75 ( struct V_332 * V_333 )
{
struct V_10 * V_6 ;
struct V_23 * V_24 ;
int V_257 ;
struct V_1 * V_2 ;
bool V_334 = false ;
if ( ! V_333 || ! V_333 -> V_2 )
return - V_327 ;
V_6 = V_333 -> V_2 -> V_6 ;
V_257 = F_76 ( V_6 -> V_6 ) ;
if ( V_257 < 0 && V_257 != - V_335 )
return V_257 ;
V_257 = F_77 ( V_333 ) ;
V_24 = V_23 ( V_6 ) ;
F_24 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 -> V_336 )
V_334 = true ;
}
F_78 ( V_6 -> V_6 ) ;
if ( V_334 && ! V_24 -> V_337 ) {
V_24 -> V_337 = true ;
return V_257 ;
}
if ( ! V_334 && V_24 -> V_337 ) {
F_79 ( V_6 -> V_6 ) ;
V_24 -> V_337 = false ;
}
F_79 ( V_6 -> V_6 ) ;
return V_257 ;
}
int
F_80 ( struct V_10 * V_6 , int V_338 )
{
struct F_3 * V_9 ;
int V_257 , V_292 ;
V_9 = F_81 ( sizeof( * V_9 ) , V_339 ) ;
if ( ! V_9 )
return - V_340 ;
for ( V_292 = 0 ; V_292 < 256 ; V_292 ++ ) {
V_9 -> V_294 . V_286 [ V_292 ] = V_292 << 8 ;
V_9 -> V_294 . V_287 [ V_292 ] = V_292 << 8 ;
V_9 -> V_294 . V_288 [ V_292 ] = V_292 << 8 ;
}
V_9 -> V_294 . V_239 = 0 ;
V_9 -> V_5 = V_338 ;
V_9 -> V_66 = V_272 ;
V_9 -> V_341 = F_36 ;
V_9 -> V_342 = F_38 ;
F_82 ( V_6 , & V_9 -> V_284 , & V_343 ) ;
F_83 ( & V_9 -> V_284 , & V_344 ) ;
F_84 ( & V_9 -> V_284 , 256 ) ;
V_257 = F_85 ( V_6 , 64 * 64 * 4 , 0x100 , V_259 ,
0 , 0x0000 , NULL , NULL , & V_9 -> V_60 . V_258 ) ;
if ( ! V_257 ) {
V_257 = F_30 ( V_9 -> V_60 . V_258 , V_259 , false ) ;
if ( ! V_257 ) {
V_257 = F_72 ( V_9 -> V_60 . V_258 ) ;
if ( V_257 )
F_31 ( V_9 -> V_60 . V_258 ) ;
}
if ( V_257 )
F_32 ( NULL , & V_9 -> V_60 . V_258 ) ;
}
F_86 ( V_9 ) ;
return 0 ;
}
