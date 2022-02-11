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
struct V_25 * V_26 = V_25 ( V_24 -> V_27 ) ;
struct V_28 * V_29 = V_28 ( V_24 -> V_27 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_30 * V_31 = & F_5 ( V_6 ) -> V_12 ;
struct V_3 * V_11 = & V_31 -> V_13 [ V_9 -> V_5 ] ;
struct V_32 * V_33 = & V_11 -> V_34 ;
struct V_35 V_36 ;
if ( F_10 ( V_26 , V_9 -> V_5 ? V_37 : V_38 ,
& V_36 ) )
return;
V_33 -> V_39 = 0 ;
if ( F_11 ( V_24 -> V_27 ) -> V_40 > 0x40 && V_22 <= ( V_36 . V_41 . V_42 / 2 ) )
memset ( & V_36 . V_43 , 0 , sizeof( V_36 . V_43 ) ) ;
if ( ! V_29 -> V_44 ( V_29 , & V_36 , V_22 , V_33 ) )
return;
V_31 -> V_45 &= V_46 | V_47 | V_48 ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 == V_50 )
V_31 -> V_45 |= V_51 ;
if ( F_11 ( V_24 -> V_27 ) -> V_40 < 0x41 )
V_31 -> V_45 |= V_52 |
V_53 ;
V_31 -> V_45 |= V_9 -> V_5 ? V_47 : V_46 ;
if ( V_33 -> V_39 )
F_12 ( V_24 , L_1 ,
V_33 -> V_54 , V_33 -> V_55 , V_33 -> V_56 , V_33 -> V_57 , V_33 -> V_58 ) ;
else
F_12 ( V_24 , L_2 ,
V_33 -> V_54 , V_33 -> V_56 , V_33 -> V_58 ) ;
V_9 -> V_59 . V_60 ( V_9 , V_9 -> V_59 . V_61 ) ;
}
static void
F_13 ( struct V_1 * V_2 , int V_21 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
unsigned char V_62 = 0 , V_63 = 0 ;
unsigned char V_64 ;
F_12 ( V_24 , L_3 , V_21 ,
V_9 -> V_5 ) ;
if ( V_9 -> V_65 == V_21 )
return;
V_9 -> V_65 = V_21 ;
if ( F_14 ( V_6 ) )
F_15 ( V_6 , V_9 -> V_5 ) ;
V_64 = F_16 ( V_6 , V_9 -> V_5 ,
V_66 ) & ~ 0xC0 ;
switch ( V_21 ) {
case V_67 :
V_62 = 0x20 ;
V_63 = 0x80 ;
V_64 |= 0x80 ;
break;
case V_68 :
V_62 = 0x20 ;
V_63 = 0x80 ;
V_64 |= 0x40 ;
break;
case V_69 :
V_62 = 0x20 ;
V_63 = 0x00 ;
V_64 |= 0xC0 ;
break;
case V_70 :
default:
V_62 = 0x00 ;
V_63 = 0x80 ;
break;
}
F_17 ( V_6 , V_9 -> V_5 , true ) ;
V_62 |= ( F_18 ( V_6 , V_9 -> V_5 , V_71 ) & ~ 0x20 ) ;
F_19 ( V_6 , V_9 -> V_5 , V_71 , V_62 ) ;
V_63 |= ( F_16 ( V_6 , V_9 -> V_5 , V_72 ) & ~ 0x80 ) ;
F_20 ( 10 ) ;
F_2 ( V_6 , V_9 -> V_5 , V_72 , V_63 ) ;
F_17 ( V_6 , V_9 -> V_5 , false ) ;
F_2 ( V_6 , V_9 -> V_5 , V_66 , V_64 ) ;
}
static bool
F_21 ( struct V_1 * V_2 , const struct V_20 * V_21 ,
struct V_20 * V_73 )
{
return true ;
}
static void
F_22 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_74 * V_75 = V_2 -> V_75 ;
int V_76 = ( V_21 -> V_77 >> 3 ) - 1 ;
int V_78 = ( V_21 -> V_79 >> 3 ) + 1 ;
int V_80 = ( V_21 -> V_81 >> 3 ) + 1 ;
int V_82 = ( V_21 -> V_83 >> 3 ) - 5 ;
int V_84 = ( V_21 -> V_77 >> 3 ) - 1 ;
int V_85 = ( V_21 -> V_83 >> 3 ) - 1 ;
int V_86 = V_21 -> V_87 - 1 ;
int V_88 = V_21 -> V_89 - 1 ;
int V_90 = V_21 -> V_91 - 1 ;
int V_92 = V_21 -> V_93 - 2 ;
int V_94 = V_21 -> V_87 - 1 ;
int V_95 = V_21 -> V_93 - 1 ;
struct V_96 * V_97 ;
bool V_98 = false ;
F_23 (encoder, &dev->mode_config.encoder_list, head) {
struct V_99 * V_100 = V_99 ( V_97 ) ;
if ( V_97 -> V_2 == V_2 &&
( V_100 -> V_101 -> type == V_102 ||
V_100 -> V_101 -> type == V_103 ) )
V_98 = true ;
}
if ( V_98 ) {
V_88 = V_92 - 3 ;
V_90 = V_92 - 2 ;
V_94 = V_88 ;
V_78 = V_82 - 5 ;
V_80 = V_82 - 2 ;
V_85 = V_82 + 4 ;
#if 0
if (dev->overlayAdaptor && nv_device(drm->device)->card_type >= NV_10)
horizTotal += 2;
#endif
}
if ( V_21 -> V_104 & V_105 )
V_92 |= 1 ;
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
if ( ( V_21 -> V_104 & ( V_106 | V_107 ) )
&& ( V_21 -> V_104 & ( V_108 | V_109 ) ) ) {
V_11 -> V_110 = 0x23 ;
if ( V_21 -> V_104 & V_107 )
V_11 -> V_110 |= 0x40 ;
if ( V_21 -> V_104 & V_109 )
V_11 -> V_110 |= 0x80 ;
} else {
int V_111 = V_21 -> V_111 ;
if ( V_21 -> V_104 & V_112 )
V_111 *= 2 ;
if ( V_21 -> V_113 > 1 )
V_111 *= V_21 -> V_113 ;
if ( V_111 < 400 )
V_11 -> V_110 = 0xA3 ;
else if ( V_111 < 480 )
V_11 -> V_110 = 0x63 ;
else if ( V_111 < 768 )
V_11 -> V_110 = 0xE3 ;
else
V_11 -> V_110 = 0x23 ;
}
V_11 -> V_110 |= ( V_21 -> V_114 & 0x03 ) << 2 ;
V_11 -> V_115 [ V_116 ] = 0x00 ;
if ( V_21 -> V_104 & V_117 )
V_11 -> V_115 [ V_71 ] = 0x29 ;
else
V_11 -> V_115 [ V_71 ] = 0x21 ;
V_11 -> V_115 [ V_118 ] = 0x0F ;
V_11 -> V_115 [ V_119 ] = 0x00 ;
V_11 -> V_115 [ V_120 ] = 0x0E ;
V_11 -> V_7 [ V_121 ] = V_82 ;
V_11 -> V_7 [ V_122 ] = V_76 ;
V_11 -> V_7 [ V_123 ] = V_84 ;
V_11 -> V_7 [ V_124 ] = ( 1 << 7 ) |
F_24 ( V_85 , 0 , V_125 ) ;
V_11 -> V_7 [ V_126 ] = V_78 ;
V_11 -> V_7 [ V_127 ] = F_24 ( V_85 , 5 , V_128 ) |
F_24 ( V_80 , 0 , V_129 ) ;
V_11 -> V_7 [ V_130 ] = V_92 ;
V_11 -> V_7 [ V_131 ] = F_24 ( V_88 , 9 , V_132 ) |
F_24 ( V_86 , 9 , V_133 ) |
F_24 ( V_92 , 9 , V_134 ) |
( 1 << 4 ) |
F_24 ( V_94 , 8 , V_135 ) |
F_24 ( V_88 , 8 , V_136 ) |
F_24 ( V_86 , 8 , V_137 ) |
F_24 ( V_92 , 8 , V_138 ) ;
V_11 -> V_7 [ V_139 ] = 0x00 ;
V_11 -> V_7 [ V_140 ] = ( ( V_21 -> V_104 & V_112 ) ? F_25 ( V_141 ) : 0 ) |
1 << 6 |
F_24 ( V_94 , 9 , V_142 ) ;
V_11 -> V_7 [ V_143 ] = 0x00 ;
V_11 -> V_7 [ V_144 ] = 0x00 ;
V_11 -> V_7 [ V_145 ] = 0x00 ;
V_11 -> V_7 [ V_146 ] = 0x00 ;
V_11 -> V_7 [ V_147 ] = 0x00 ;
V_11 -> V_7 [ V_148 ] = 0x00 ;
V_11 -> V_7 [ V_149 ] = V_88 ;
V_11 -> V_7 [ V_150 ] = 1 << 5 | F_24 ( V_90 , 0 , V_151 ) ;
V_11 -> V_7 [ V_152 ] = V_86 ;
V_11 -> V_7 [ V_153 ] = V_75 -> V_154 [ 0 ] / 8 ;
V_11 -> V_7 [ V_155 ] = 0x00 ;
V_11 -> V_7 [ V_156 ] = V_94 ;
V_11 -> V_7 [ V_157 ] = V_95 ;
V_11 -> V_7 [ V_72 ] = 0x43 ;
V_11 -> V_7 [ V_158 ] = 0xff ;
V_11 -> V_7 [ V_159 ] =
F_24 ( V_75 -> V_154 [ 0 ] / 8 , 8 , V_160 ) ;
V_11 -> V_7 [ V_161 ] =
F_24 ( V_75 -> V_154 [ 0 ] / 8 , 11 , V_162 ) ;
V_11 -> V_7 [ V_66 ] = V_21 -> V_77 < 1280 ?
F_25 ( V_163 ) : 0x00 ;
V_11 -> V_7 [ V_164 ] = F_24 ( V_85 , 6 , V_165 ) |
F_24 ( V_94 , 10 , V_166 ) |
F_24 ( V_88 , 10 , V_167 ) |
F_24 ( V_86 , 10 , V_168 ) |
F_24 ( V_92 , 10 , V_169 ) ;
V_11 -> V_7 [ V_170 ] = F_24 ( V_78 , 8 , V_171 ) |
F_24 ( V_84 , 8 , V_172 ) |
F_24 ( V_76 , 8 , V_173 ) |
F_24 ( V_82 , 8 , V_174 ) ;
V_11 -> V_7 [ V_175 ] = F_24 ( V_94 , 11 , V_176 ) |
F_24 ( V_88 , 11 , V_177 ) |
F_24 ( V_86 , 11 , V_178 ) |
F_24 ( V_92 , 11 , V_179 ) ;
if ( V_21 -> V_104 & V_105 ) {
V_82 = ( V_82 >> 1 ) & ~ 1 ;
V_11 -> V_7 [ V_180 ] = V_82 ;
V_11 -> V_7 [ V_170 ] |= F_24 ( V_82 , 8 , V_181 ) ;
} else
V_11 -> V_7 [ V_180 ] = 0xff ;
V_11 -> V_182 [ V_183 ] = 0x00 ;
V_11 -> V_182 [ V_184 ] = 0x00 ;
V_11 -> V_182 [ V_185 ] = 0x00 ;
V_11 -> V_182 [ V_186 ] = 0x00 ;
V_11 -> V_182 [ V_187 ] = 0x00 ;
V_11 -> V_182 [ V_188 ] = 0x40 ;
V_11 -> V_182 [ V_189 ] = 0x05 ;
V_11 -> V_182 [ V_190 ] = 0x0F ;
V_11 -> V_182 [ V_191 ] = 0xFF ;
V_11 -> V_192 [ 0 ] = 0x00 ;
V_11 -> V_192 [ 1 ] = 0x01 ;
V_11 -> V_192 [ 2 ] = 0x02 ;
V_11 -> V_192 [ 3 ] = 0x03 ;
V_11 -> V_192 [ 4 ] = 0x04 ;
V_11 -> V_192 [ 5 ] = 0x05 ;
V_11 -> V_192 [ 6 ] = 0x06 ;
V_11 -> V_192 [ 7 ] = 0x07 ;
V_11 -> V_192 [ 8 ] = 0x08 ;
V_11 -> V_192 [ 9 ] = 0x09 ;
V_11 -> V_192 [ 10 ] = 0x0A ;
V_11 -> V_192 [ 11 ] = 0x0B ;
V_11 -> V_192 [ 12 ] = 0x0C ;
V_11 -> V_192 [ 13 ] = 0x0D ;
V_11 -> V_192 [ 14 ] = 0x0E ;
V_11 -> V_192 [ 15 ] = 0x0F ;
V_11 -> V_192 [ V_193 ] = 0x01 ;
V_11 -> V_192 [ V_194 ] = 0x00 ;
V_11 -> V_192 [ V_195 ] = 0x0F ;
V_11 -> V_192 [ V_196 ] = 0x00 ;
V_11 -> V_192 [ V_197 ] = 0x00 ;
}
static void
F_26 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_3 * V_198 = & F_5 ( V_6 ) -> V_199 . V_13 [ V_9 -> V_5 ] ;
struct V_96 * V_97 ;
bool V_200 = false , V_201 = false , V_202 = false ,
V_203 = false ;
F_23 (encoder, &dev->mode_config.encoder_list, head) {
struct V_99 * V_100 = V_99 ( V_97 ) ;
bool V_204 = false ;
if ( V_97 -> V_2 != V_2 )
continue;
if ( V_100 -> V_101 -> type == V_102 )
V_204 = V_200 = true ;
if ( V_100 -> V_101 -> type == V_205 )
V_202 = true ;
if ( V_100 -> V_101 -> type == V_103 )
V_204 = V_201 = true ;
if ( V_100 -> V_101 -> V_206 != V_207 && V_204 )
V_203 = true ;
}
V_11 -> V_7 [ V_208 ] = V_198 -> V_7 [ V_208 ] & ~ ( 1 << 5 ) ;
V_11 -> V_209 = 0 ;
if ( V_9 -> V_5 == 0 )
V_11 -> V_209 |= V_210 ;
#if 0
if (dev->overlayAdaptor) {
NVPortPrivPtr pPriv = GET_OVERLAY_PRIVATE(dev);
if (pPriv->overlayCRTC == nv_crtc->index)
regp->crtc_eng_ctrl |= NV_CRTC_FSEL_OVERLAY;
}
#endif
V_11 -> V_211 = V_212 |
V_213 |
V_214 ;
if ( F_11 ( V_24 -> V_27 ) -> V_40 >= 0x11 )
V_11 -> V_211 |= V_215 ;
if ( V_21 -> V_104 & V_112 )
V_11 -> V_211 |= V_216 ;
V_11 -> V_7 [ V_217 ] = 0 ;
V_11 -> V_7 [ V_218 ] = 0 ;
if ( V_200 )
V_11 -> V_7 [ V_219 ] = 0x11 ;
else if ( V_201 )
V_11 -> V_7 [ V_219 ] = 0x88 ;
else
V_11 -> V_7 [ V_219 ] = 0x22 ;
V_11 -> V_7 [ V_220 ] = V_198 -> V_7 [ V_220 ] ;
F_4 ( V_2 , V_9 -> V_15 ) ;
if ( V_9 -> V_5 == 0 )
V_11 -> V_7 [ V_221 ] = V_198 -> V_7 [ V_221 ] | 0x80 ;
V_11 -> V_7 [ V_222 ] = F_5 ( V_6 ) -> V_199 . V_13 [ 0 ] . V_7 [ V_222 ] ;
if ( ! V_9 -> V_5 )
V_11 -> V_7 [ V_222 ] += 4 ;
V_11 -> V_7 [ V_223 ] = V_203 ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_224 )
V_11 -> V_7 [ 0x9f ] = V_203 ? 0x11 : 0x1 ;
V_11 -> V_225 = V_21 -> V_87 - 3 ;
V_11 -> V_226 = V_21 -> V_87 - 1 ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 == V_50 )
V_11 -> V_227 = F_27 ( V_6 , 0 , V_228 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_224 )
V_11 -> V_229 = F_27 ( V_6 , 0 , V_230 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_231 )
V_11 -> V_232 = V_233 ;
else
V_11 -> V_232 = V_234 ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 == V_50 ) {
V_11 -> V_7 [ V_235 ] = 0xFF ;
V_11 -> V_7 [ V_236 ] = 0x1 ;
}
V_11 -> V_7 [ V_237 ] = ( V_2 -> V_75 -> V_238 + 1 ) / 8 ;
if ( V_200 || V_201 || V_202 )
V_11 -> V_7 [ V_237 ] |= ( 1 << 7 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_231 )
V_11 -> V_239 = ( 1 << 25 ) ;
V_11 -> V_240 = V_241 |
V_242 |
V_243 ;
if ( V_2 -> V_75 -> V_238 == 16 )
V_11 -> V_240 |= V_244 ;
if ( F_11 ( V_24 -> V_27 ) -> V_40 >= 0x11 )
V_11 -> V_240 |= V_245 ;
V_11 -> V_246 = 0 ;
V_11 -> V_247 = 0 ;
F_7 ( V_2 , V_9 -> V_17 ) ;
V_11 -> V_248 = 0x100 ;
V_11 -> V_249 = 0x0 ;
V_11 -> V_250 = 0xfffff ;
V_11 -> V_251 = 0x1 ;
}
static int
F_28 ( struct V_1 * V_2 , struct V_74 * V_252 )
{
struct F_5 * V_253 = F_5 ( V_2 -> V_6 ) ;
struct V_254 * V_255 = V_254 ( V_2 -> V_75 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
int V_256 ;
V_256 = F_29 ( V_255 -> V_257 , V_258 ) ;
if ( V_256 == 0 ) {
if ( V_253 -> V_259 [ V_9 -> V_5 ] )
F_30 ( V_253 -> V_259 [ V_9 -> V_5 ] ) ;
F_31 ( V_255 -> V_257 , & V_253 -> V_259 [ V_9 -> V_5 ] ) ;
}
return V_256 ;
}
static int
F_32 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_20 * V_73 ,
int V_260 , int V_261 , struct V_74 * V_252 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
int V_256 ;
F_12 ( V_24 , L_4 , V_9 -> V_5 ) ;
F_33 ( V_73 ) ;
V_256 = F_28 ( V_2 , V_252 ) ;
if ( V_256 )
return V_256 ;
F_34 ( V_6 , V_9 -> V_5 , - 1 ) ;
F_22 ( V_2 , V_73 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 == V_50 )
F_8 ( V_6 , 0 , V_262 , F_5 ( V_6 ) -> V_12 . V_263 ) ;
F_26 ( V_2 , V_73 ) ;
F_9 ( V_2 , V_21 , V_73 -> clock ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_30 * V_31 = & F_5 ( V_6 ) -> V_12 ;
struct V_3 * V_264 = & V_31 -> V_13 [ V_9 -> V_5 ] ;
struct V_30 * V_265 = & F_5 ( V_6 ) -> V_199 ;
struct V_3 * V_266 = & V_265 -> V_13 [ V_9 -> V_5 ] ;
if ( F_14 ( V_2 -> V_6 ) )
F_15 ( V_2 -> V_6 , V_9 -> V_5 ) ;
F_36 ( V_2 -> V_6 , V_9 -> V_5 , V_265 ) ;
V_31 -> V_263 = V_265 -> V_263 & ~ ( 0x5 << 16 ) ;
V_264 -> V_7 [ V_267 ] = V_266 -> V_7 [ V_267 ] ;
V_31 -> V_45 = V_265 -> V_45 & ~ ( V_46 | V_47 | V_48 ) ;
V_264 -> V_229 = V_266 -> V_229 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
int V_268 = V_9 -> V_5 ;
T_1 V_269 = F_5 ( V_6 ) -> V_199 . V_13 [ V_268 ] . V_7 [ V_270 ] ;
if ( F_14 ( V_2 -> V_6 ) )
F_15 ( V_2 -> V_6 , V_268 ) ;
F_38 ( V_2 -> V_6 , V_268 , & F_5 ( V_6 ) -> V_199 ) ;
F_34 ( V_2 -> V_6 , V_268 , V_269 ) ;
V_9 -> V_65 = V_271 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_272 * V_273 = V_2 -> V_274 ;
if ( F_14 ( V_6 ) )
F_15 ( V_6 , V_9 -> V_5 ) ;
F_40 ( V_6 , V_9 -> V_5 ) ;
V_273 -> V_275 ( V_2 , V_69 ) ;
F_41 ( V_6 , V_9 -> V_5 , true ) ;
F_42 ( V_6 , V_9 -> V_5 , V_276 , V_277 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 == V_50 ) {
T_2 V_278 = F_43 ( V_6 , V_9 -> V_5 , V_279 ) ;
F_8 ( V_6 , V_9 -> V_5 , V_279 , V_278 & ~ 0x10000 ) ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_272 * V_273 = V_2 -> V_274 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
F_38 ( V_6 , V_9 -> V_5 , & F_5 ( V_6 ) -> V_12 ) ;
F_45 ( V_2 , V_2 -> V_260 , V_2 -> V_261 , NULL ) ;
#ifdef F_46
{
T_1 V_280 = F_16 ( V_6 , V_9 -> V_5 , V_281 ) ;
V_280 |= F_25 ( V_282 ) ;
F_2 ( V_6 , V_9 -> V_5 , V_281 , V_280 ) ;
}
#endif
V_273 -> V_275 ( V_2 , V_70 ) ;
F_47 ( V_6 , V_9 -> V_5 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct F_5 * V_253 = F_5 ( V_2 -> V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
if ( ! V_9 )
return;
F_49 ( V_2 ) ;
if ( V_253 -> V_259 [ V_9 -> V_5 ] )
F_30 ( V_253 -> V_259 [ V_9 -> V_5 ] ) ;
F_31 ( NULL , & V_253 -> V_259 [ V_9 -> V_5 ] ) ;
F_50 ( V_9 -> V_59 . V_257 ) ;
F_30 ( V_9 -> V_59 . V_257 ) ;
F_31 ( NULL , & V_9 -> V_59 . V_257 ) ;
F_51 ( V_9 ) ;
}
static void
F_52 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_9 -> V_283 . V_6 ;
struct V_284 { T_1 V_285 , V_286 , V_287 ; } V_288 ( ( V_289 ) ) * V_290 ;
int V_291 ;
V_290 = (struct V_284 * ) F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] . V_292 ;
for ( V_291 = 0 ; V_291 < 256 ; V_291 ++ ) {
V_290 [ V_291 ] . V_285 = V_9 -> V_293 . V_285 [ V_291 ] >> 8 ;
V_290 [ V_291 ] . V_286 = V_9 -> V_293 . V_286 [ V_291 ] >> 8 ;
V_290 [ V_291 ] . V_287 = V_9 -> V_293 . V_287 [ V_291 ] >> 8 ;
}
F_53 ( V_6 , V_9 -> V_5 , & F_5 ( V_6 ) -> V_12 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct F_5 * V_253 = F_5 ( V_2 -> V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
if ( V_253 -> V_259 [ V_9 -> V_5 ] )
F_30 ( V_253 -> V_259 [ V_9 -> V_5 ] ) ;
F_31 ( NULL , & V_253 -> V_259 [ V_9 -> V_5 ] ) ;
}
static void
F_55 ( struct V_1 * V_2 , T_3 * V_285 , T_3 * V_286 , T_3 * V_287 , T_2 V_294 ,
T_2 V_295 )
{
int V_296 = ( V_294 + V_295 > 256 ) ? 256 : V_294 + V_295 , V_291 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
for ( V_291 = V_294 ; V_291 < V_296 ; V_291 ++ ) {
V_9 -> V_293 . V_285 [ V_291 ] = V_285 [ V_291 ] ;
V_9 -> V_293 . V_286 [ V_291 ] = V_286 [ V_291 ] ;
V_9 -> V_293 . V_287 [ V_291 ] = V_287 [ V_291 ] ;
}
if ( ! V_9 -> V_283 . V_75 ) {
V_9 -> V_293 . V_238 = 0 ;
return;
}
F_52 ( V_2 ) ;
}
static int
F_56 ( struct V_1 * V_2 ,
struct V_74 * V_297 ,
int V_260 , int V_261 , bool V_298 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_74 * V_299 ;
struct V_254 * V_75 ;
int V_300 , V_301 ;
F_12 ( V_24 , L_5 , V_9 -> V_5 ) ;
if ( ! V_298 && ! V_2 -> V_75 ) {
F_12 ( V_24 , L_6 ) ;
return 0 ;
}
if ( V_298 ) {
V_299 = V_297 ;
V_75 = V_254 ( V_297 ) ;
} else {
V_299 = V_2 -> V_75 ;
V_75 = V_254 ( V_2 -> V_75 ) ;
}
V_9 -> V_75 . V_61 = V_75 -> V_257 -> V_302 . V_61 ;
if ( V_9 -> V_293 . V_238 != V_299 -> V_238 ) {
V_9 -> V_293 . V_238 = V_299 -> V_238 ;
F_52 ( V_2 ) ;
}
V_11 -> V_7 [ V_237 ] &= ~ 3 ;
V_11 -> V_7 [ V_237 ] |= ( V_2 -> V_75 -> V_238 + 1 ) / 8 ;
V_11 -> V_240 &= ~ V_244 ;
if ( V_2 -> V_75 -> V_238 == 16 )
V_11 -> V_240 |= V_244 ;
F_1 ( V_2 , V_11 , V_237 ) ;
F_8 ( V_6 , V_9 -> V_5 , V_303 ,
V_11 -> V_240 ) ;
V_11 -> V_7 [ V_153 ] = V_299 -> V_154 [ 0 ] >> 3 ;
V_11 -> V_7 [ V_159 ] =
F_24 ( V_299 -> V_154 [ 0 ] >> 3 , 8 , V_160 ) ;
V_11 -> V_7 [ V_161 ] =
F_24 ( V_299 -> V_154 [ 0 ] / 8 , 11 , V_162 ) ;
F_1 ( V_2 , V_11 , V_159 ) ;
F_1 ( V_2 , V_11 , V_153 ) ;
F_1 ( V_2 , V_11 , V_161 ) ;
V_11 -> V_304 = V_9 -> V_75 . V_61 & ~ 3 ;
V_11 -> V_304 += ( V_261 * V_299 -> V_154 [ 0 ] ) + ( V_260 * V_299 -> V_305 / 8 ) ;
F_57 ( V_6 , V_9 -> V_5 , V_11 -> V_304 ) ;
F_58 ( V_6 , V_2 -> V_21 . clock , V_299 -> V_305 ,
& V_300 , & V_301 ) ;
V_11 -> V_7 [ V_306 ] = V_300 ;
V_11 -> V_7 [ V_307 ] = V_301 & 0xff ;
F_1 ( V_2 , V_11 , V_306 ) ;
F_1 ( V_2 , V_11 , V_307 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_308 ) {
V_11 -> V_7 [ V_309 ] = V_301 >> 8 ;
F_1 ( V_2 , V_11 , V_309 ) ;
}
return 0 ;
}
static int
F_45 ( struct V_1 * V_2 , int V_260 , int V_261 ,
struct V_74 * V_252 )
{
int V_256 = F_28 ( V_2 , V_252 ) ;
if ( V_256 )
return V_256 ;
return F_56 ( V_2 , V_252 , V_260 , V_261 , false ) ;
}
static int
F_59 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
int V_260 , int V_261 , enum V_310 V_31 )
{
struct V_23 * V_24 = V_23 ( V_2 -> V_6 ) ;
struct V_10 * V_6 = V_24 -> V_6 ;
if ( V_31 == V_311 )
F_60 ( V_6 ) ;
else
F_61 ( V_6 ) ;
return F_56 ( V_2 , V_75 , V_260 , V_261 , true ) ;
}
static void F_62 ( struct V_10 * V_6 , struct V_312 * V_313 ,
struct V_312 * V_314 )
{
int V_315 = F_63 ( V_6 ) ;
T_2 V_316 ;
int V_291 , V_317 ;
for ( V_291 = 0 ; V_291 < V_315 ; V_291 ++ ) {
for ( V_317 = 0 ; V_317 < V_315 ; V_317 ++ ) {
V_316 = F_64 ( V_313 , V_291 * 64 + V_317 ) ;
F_65 ( V_314 , V_291 * V_315 + V_317 , ( V_316 & 0x80000000 ) >> 16
| ( V_316 & 0xf80000 ) >> 9
| ( V_316 & 0xf800 ) >> 6
| ( V_316 & 0xf8 ) >> 3 ) ;
}
}
}
static void F_66 ( struct V_10 * V_6 , struct V_312 * V_313 ,
struct V_312 * V_314 )
{
T_2 V_316 ;
int V_318 , V_291 ;
for ( V_291 = 0 ; V_291 < 64 * 64 ; V_291 ++ ) {
V_316 = F_64 ( V_313 , V_291 ) ;
V_318 = V_316 >> 24 ;
if ( V_318 > 0 && V_318 < 255 )
V_316 = ( V_316 & 0x00ffffff ) | ( ( V_318 + 1 ) << 24 ) ;
#ifdef F_46
{
struct V_23 * V_24 = V_23 ( V_6 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_40 == 0x11 ) {
V_316 = ( ( V_316 & 0x000000ff ) << 24 ) |
( ( V_316 & 0x0000ff00 ) << 8 ) |
( ( V_316 & 0x00ff0000 ) >> 8 ) |
( ( V_316 & 0xff000000 ) >> 24 ) ;
}
}
#endif
F_67 ( V_314 , V_291 , V_316 ) ;
}
}
static int
F_68 ( struct V_1 * V_2 , struct V_319 * V_320 ,
T_2 V_321 , T_2 V_315 , T_2 V_322 )
{
struct V_23 * V_24 = V_23 ( V_2 -> V_6 ) ;
struct V_10 * V_6 = V_24 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_312 * V_59 = NULL ;
struct V_323 * V_324 ;
int V_256 = 0 ;
if ( ! V_321 ) {
V_9 -> V_59 . V_325 ( V_9 , true ) ;
return 0 ;
}
if ( V_315 != 64 || V_322 != 64 )
return - V_326 ;
V_324 = F_69 ( V_6 , V_320 , V_321 ) ;
if ( ! V_324 )
return - V_327 ;
V_59 = F_70 ( V_324 ) ;
V_256 = F_71 ( V_59 ) ;
if ( V_256 )
goto V_328;
if ( F_11 ( V_24 -> V_27 ) -> V_40 >= 0x11 )
F_66 ( V_6 , V_59 , V_9 -> V_59 . V_257 ) ;
else
F_62 ( V_6 , V_59 , V_9 -> V_59 . V_257 ) ;
F_50 ( V_59 ) ;
V_9 -> V_59 . V_61 = V_9 -> V_59 . V_257 -> V_302 . V_61 ;
V_9 -> V_59 . V_60 ( V_9 , V_9 -> V_59 . V_61 ) ;
V_9 -> V_59 . V_329 ( V_9 , true ) ;
V_328:
F_72 ( V_324 ) ;
return V_256 ;
}
static int
F_73 ( struct V_1 * V_2 , int V_260 , int V_261 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
V_9 -> V_59 . V_330 ( V_9 , V_260 , V_261 ) ;
return 0 ;
}
int
F_74 ( struct V_331 * V_332 )
{
struct V_10 * V_6 ;
struct V_23 * V_24 ;
int V_256 ;
struct V_1 * V_2 ;
bool V_333 = false ;
if ( ! V_332 || ! V_332 -> V_2 )
return - V_326 ;
V_6 = V_332 -> V_2 -> V_6 ;
V_256 = F_75 ( V_6 -> V_6 ) ;
if ( V_256 < 0 )
return V_256 ;
V_256 = F_76 ( V_332 ) ;
V_24 = V_23 ( V_6 ) ;
F_23 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 -> V_334 )
V_333 = true ;
}
F_77 ( V_6 -> V_6 ) ;
if ( V_333 && ! V_24 -> V_335 ) {
V_24 -> V_335 = true ;
return V_256 ;
}
if ( ! V_333 && V_24 -> V_335 ) {
F_78 ( V_6 -> V_6 ) ;
V_24 -> V_335 = false ;
}
F_78 ( V_6 -> V_6 ) ;
return V_256 ;
}
int
F_79 ( struct V_10 * V_6 , int V_336 )
{
struct F_3 * V_9 ;
int V_256 , V_291 ;
V_9 = F_80 ( sizeof( * V_9 ) , V_337 ) ;
if ( ! V_9 )
return - V_338 ;
for ( V_291 = 0 ; V_291 < 256 ; V_291 ++ ) {
V_9 -> V_293 . V_285 [ V_291 ] = V_291 << 8 ;
V_9 -> V_293 . V_286 [ V_291 ] = V_291 << 8 ;
V_9 -> V_293 . V_287 [ V_291 ] = V_291 << 8 ;
}
V_9 -> V_293 . V_238 = 0 ;
V_9 -> V_5 = V_336 ;
V_9 -> V_65 = V_271 ;
F_81 ( V_6 , & V_9 -> V_283 , & V_339 ) ;
F_82 ( & V_9 -> V_283 , & V_340 ) ;
F_83 ( & V_9 -> V_283 , 256 ) ;
V_256 = F_84 ( V_6 , 64 * 64 * 4 , 0x100 , V_258 ,
0 , 0x0000 , NULL , & V_9 -> V_59 . V_257 ) ;
if ( ! V_256 ) {
V_256 = F_29 ( V_9 -> V_59 . V_257 , V_258 ) ;
if ( ! V_256 ) {
V_256 = F_71 ( V_9 -> V_59 . V_257 ) ;
if ( V_256 )
F_30 ( V_9 -> V_59 . V_257 ) ;
}
if ( V_256 )
F_31 ( NULL , & V_9 -> V_59 . V_257 ) ;
}
F_85 ( V_9 ) ;
return 0 ;
}
