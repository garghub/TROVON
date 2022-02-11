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
V_11 -> V_114 [ V_115 ] = 0x00 ;
if ( V_21 -> V_104 & V_116 )
V_11 -> V_114 [ V_71 ] = 0x29 ;
else
V_11 -> V_114 [ V_71 ] = 0x21 ;
V_11 -> V_114 [ V_117 ] = 0x0F ;
V_11 -> V_114 [ V_118 ] = 0x00 ;
V_11 -> V_114 [ V_119 ] = 0x0E ;
V_11 -> V_7 [ V_120 ] = V_82 ;
V_11 -> V_7 [ V_121 ] = V_76 ;
V_11 -> V_7 [ V_122 ] = V_84 ;
V_11 -> V_7 [ V_123 ] = ( 1 << 7 ) |
F_24 ( V_85 , 0 , V_124 ) ;
V_11 -> V_7 [ V_125 ] = V_78 ;
V_11 -> V_7 [ V_126 ] = F_24 ( V_85 , 5 , V_127 ) |
F_24 ( V_80 , 0 , V_128 ) ;
V_11 -> V_7 [ V_129 ] = V_92 ;
V_11 -> V_7 [ V_130 ] = F_24 ( V_88 , 9 , V_131 ) |
F_24 ( V_86 , 9 , V_132 ) |
F_24 ( V_92 , 9 , V_133 ) |
( 1 << 4 ) |
F_24 ( V_94 , 8 , V_134 ) |
F_24 ( V_88 , 8 , V_135 ) |
F_24 ( V_86 , 8 , V_136 ) |
F_24 ( V_92 , 8 , V_137 ) ;
V_11 -> V_7 [ V_138 ] = 0x00 ;
V_11 -> V_7 [ V_139 ] = ( ( V_21 -> V_104 & V_112 ) ? F_25 ( V_140 ) : 0 ) |
1 << 6 |
F_24 ( V_94 , 9 , V_141 ) ;
V_11 -> V_7 [ V_142 ] = 0x00 ;
V_11 -> V_7 [ V_143 ] = 0x00 ;
V_11 -> V_7 [ V_144 ] = 0x00 ;
V_11 -> V_7 [ V_145 ] = 0x00 ;
V_11 -> V_7 [ V_146 ] = 0x00 ;
V_11 -> V_7 [ V_147 ] = 0x00 ;
V_11 -> V_7 [ V_148 ] = V_88 ;
V_11 -> V_7 [ V_149 ] = 1 << 5 | F_24 ( V_90 , 0 , V_150 ) ;
V_11 -> V_7 [ V_151 ] = V_86 ;
V_11 -> V_7 [ V_152 ] = V_75 -> V_153 [ 0 ] / 8 ;
V_11 -> V_7 [ V_154 ] = 0x00 ;
V_11 -> V_7 [ V_155 ] = V_94 ;
V_11 -> V_7 [ V_156 ] = V_95 ;
V_11 -> V_7 [ V_72 ] = 0x43 ;
V_11 -> V_7 [ V_157 ] = 0xff ;
V_11 -> V_7 [ V_158 ] =
F_24 ( V_75 -> V_153 [ 0 ] / 8 , 8 , V_159 ) ;
V_11 -> V_7 [ V_160 ] =
F_24 ( V_75 -> V_153 [ 0 ] / 8 , 11 , V_161 ) ;
V_11 -> V_7 [ V_66 ] = V_21 -> V_77 < 1280 ?
F_25 ( V_162 ) : 0x00 ;
V_11 -> V_7 [ V_163 ] = F_24 ( V_85 , 6 , V_164 ) |
F_24 ( V_94 , 10 , V_165 ) |
F_24 ( V_88 , 10 , V_166 ) |
F_24 ( V_86 , 10 , V_167 ) |
F_24 ( V_92 , 10 , V_168 ) ;
V_11 -> V_7 [ V_169 ] = F_24 ( V_78 , 8 , V_170 ) |
F_24 ( V_84 , 8 , V_171 ) |
F_24 ( V_76 , 8 , V_172 ) |
F_24 ( V_82 , 8 , V_173 ) ;
V_11 -> V_7 [ V_174 ] = F_24 ( V_94 , 11 , V_175 ) |
F_24 ( V_88 , 11 , V_176 ) |
F_24 ( V_86 , 11 , V_177 ) |
F_24 ( V_92 , 11 , V_178 ) ;
if ( V_21 -> V_104 & V_105 ) {
V_82 = ( V_82 >> 1 ) & ~ 1 ;
V_11 -> V_7 [ V_179 ] = V_82 ;
V_11 -> V_7 [ V_169 ] |= F_24 ( V_82 , 8 , V_180 ) ;
} else
V_11 -> V_7 [ V_179 ] = 0xff ;
V_11 -> V_181 [ V_182 ] = 0x00 ;
V_11 -> V_181 [ V_183 ] = 0x00 ;
V_11 -> V_181 [ V_184 ] = 0x00 ;
V_11 -> V_181 [ V_185 ] = 0x00 ;
V_11 -> V_181 [ V_186 ] = 0x00 ;
V_11 -> V_181 [ V_187 ] = 0x40 ;
V_11 -> V_181 [ V_188 ] = 0x05 ;
V_11 -> V_181 [ V_189 ] = 0x0F ;
V_11 -> V_181 [ V_190 ] = 0xFF ;
V_11 -> V_191 [ 0 ] = 0x00 ;
V_11 -> V_191 [ 1 ] = 0x01 ;
V_11 -> V_191 [ 2 ] = 0x02 ;
V_11 -> V_191 [ 3 ] = 0x03 ;
V_11 -> V_191 [ 4 ] = 0x04 ;
V_11 -> V_191 [ 5 ] = 0x05 ;
V_11 -> V_191 [ 6 ] = 0x06 ;
V_11 -> V_191 [ 7 ] = 0x07 ;
V_11 -> V_191 [ 8 ] = 0x08 ;
V_11 -> V_191 [ 9 ] = 0x09 ;
V_11 -> V_191 [ 10 ] = 0x0A ;
V_11 -> V_191 [ 11 ] = 0x0B ;
V_11 -> V_191 [ 12 ] = 0x0C ;
V_11 -> V_191 [ 13 ] = 0x0D ;
V_11 -> V_191 [ 14 ] = 0x0E ;
V_11 -> V_191 [ 15 ] = 0x0F ;
V_11 -> V_191 [ V_192 ] = 0x01 ;
V_11 -> V_191 [ V_193 ] = 0x00 ;
V_11 -> V_191 [ V_194 ] = 0x0F ;
V_11 -> V_191 [ V_195 ] = 0x00 ;
V_11 -> V_191 [ V_196 ] = 0x00 ;
}
static void
F_26 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_3 * V_197 = & F_5 ( V_6 ) -> V_198 . V_13 [ V_9 -> V_5 ] ;
struct V_96 * V_97 ;
bool V_199 = false , V_200 = false , V_201 = false ,
V_202 = false ;
F_23 (encoder, &dev->mode_config.encoder_list, head) {
struct V_99 * V_100 = V_99 ( V_97 ) ;
bool V_203 = false ;
if ( V_97 -> V_2 != V_2 )
continue;
if ( V_100 -> V_101 -> type == V_102 )
V_203 = V_199 = true ;
if ( V_100 -> V_101 -> type == V_204 )
V_201 = true ;
if ( V_100 -> V_101 -> type == V_103 )
V_203 = V_200 = true ;
if ( V_100 -> V_101 -> V_205 != V_206 && V_203 )
V_202 = true ;
}
V_11 -> V_7 [ V_207 ] = V_197 -> V_7 [ V_207 ] & ~ ( 1 << 5 ) ;
V_11 -> V_208 = 0 ;
if ( V_9 -> V_5 == 0 )
V_11 -> V_208 |= V_209 ;
#if 0
if (dev->overlayAdaptor) {
NVPortPrivPtr pPriv = GET_OVERLAY_PRIVATE(dev);
if (pPriv->overlayCRTC == nv_crtc->index)
regp->crtc_eng_ctrl |= NV_CRTC_FSEL_OVERLAY;
}
#endif
V_11 -> V_210 = V_211 |
V_212 |
V_213 ;
if ( F_11 ( V_24 -> V_27 ) -> V_40 >= 0x11 )
V_11 -> V_210 |= V_214 ;
if ( V_21 -> V_104 & V_112 )
V_11 -> V_210 |= V_215 ;
V_11 -> V_7 [ V_216 ] = 0 ;
V_11 -> V_7 [ V_217 ] = 0 ;
if ( V_199 )
V_11 -> V_7 [ V_218 ] = 0x11 ;
else if ( V_200 )
V_11 -> V_7 [ V_218 ] = 0x88 ;
else
V_11 -> V_7 [ V_218 ] = 0x22 ;
V_11 -> V_7 [ V_219 ] = V_197 -> V_7 [ V_219 ] ;
F_4 ( V_2 , V_9 -> V_15 ) ;
if ( V_9 -> V_5 == 0 )
V_11 -> V_7 [ V_220 ] = V_197 -> V_7 [ V_220 ] | 0x80 ;
V_11 -> V_7 [ V_221 ] = F_5 ( V_6 ) -> V_198 . V_13 [ 0 ] . V_7 [ V_221 ] ;
if ( ! V_9 -> V_5 )
V_11 -> V_7 [ V_221 ] += 4 ;
V_11 -> V_7 [ V_222 ] = V_202 ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_223 )
V_11 -> V_7 [ 0x9f ] = V_202 ? 0x11 : 0x1 ;
V_11 -> V_224 = V_21 -> V_87 - 3 ;
V_11 -> V_225 = V_21 -> V_87 - 1 ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 == V_50 )
V_11 -> V_226 = F_27 ( V_6 , 0 , V_227 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_223 )
V_11 -> V_228 = F_27 ( V_6 , 0 , V_229 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_230 )
V_11 -> V_231 = V_232 ;
else
V_11 -> V_231 = V_233 ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 == V_50 ) {
V_11 -> V_7 [ V_234 ] = 0xFF ;
V_11 -> V_7 [ V_235 ] = 0x1 ;
}
V_11 -> V_7 [ V_236 ] = ( V_2 -> V_75 -> V_237 + 1 ) / 8 ;
if ( V_199 || V_200 || V_201 )
V_11 -> V_7 [ V_236 ] |= ( 1 << 7 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_230 )
V_11 -> V_238 = ( 1 << 25 ) ;
V_11 -> V_239 = V_240 |
V_241 |
V_242 ;
if ( V_2 -> V_75 -> V_237 == 16 )
V_11 -> V_239 |= V_243 ;
if ( F_11 ( V_24 -> V_27 ) -> V_40 >= 0x11 )
V_11 -> V_239 |= V_244 ;
V_11 -> V_245 = 0 ;
V_11 -> V_246 = 0 ;
F_7 ( V_2 , V_9 -> V_17 ) ;
V_11 -> V_247 = 0x100 ;
V_11 -> V_248 = 0x0 ;
V_11 -> V_249 = 0xfffff ;
V_11 -> V_250 = 0x1 ;
}
static int
F_28 ( struct V_1 * V_2 , struct V_74 * V_251 )
{
struct F_5 * V_252 = F_5 ( V_2 -> V_6 ) ;
struct V_253 * V_254 = V_253 ( V_2 -> V_75 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
int V_255 ;
V_255 = F_29 ( V_254 -> V_256 , V_257 ) ;
if ( V_255 == 0 ) {
if ( V_252 -> V_258 [ V_9 -> V_5 ] )
F_30 ( V_252 -> V_258 [ V_9 -> V_5 ] ) ;
F_31 ( V_254 -> V_256 , & V_252 -> V_258 [ V_9 -> V_5 ] ) ;
}
return V_255 ;
}
static int
F_32 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_20 * V_73 ,
int V_259 , int V_260 , struct V_74 * V_251 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
int V_255 ;
F_12 ( V_24 , L_4 , V_9 -> V_5 ) ;
F_33 ( V_73 ) ;
V_255 = F_28 ( V_2 , V_251 ) ;
if ( V_255 )
return V_255 ;
F_34 ( V_6 , V_9 -> V_5 , - 1 ) ;
F_22 ( V_2 , V_73 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 == V_50 )
F_8 ( V_6 , 0 , V_261 , F_5 ( V_6 ) -> V_12 . V_262 ) ;
F_26 ( V_2 , V_73 ) ;
F_9 ( V_2 , V_21 , V_73 -> clock ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_30 * V_31 = & F_5 ( V_6 ) -> V_12 ;
struct V_3 * V_263 = & V_31 -> V_13 [ V_9 -> V_5 ] ;
struct V_30 * V_264 = & F_5 ( V_6 ) -> V_198 ;
struct V_3 * V_265 = & V_264 -> V_13 [ V_9 -> V_5 ] ;
if ( F_14 ( V_2 -> V_6 ) )
F_15 ( V_2 -> V_6 , V_9 -> V_5 ) ;
F_36 ( V_2 -> V_6 , V_9 -> V_5 , V_264 ) ;
V_31 -> V_262 = V_264 -> V_262 & ~ ( 0x5 << 16 ) ;
V_263 -> V_7 [ V_266 ] = V_265 -> V_7 [ V_266 ] ;
V_31 -> V_45 = V_264 -> V_45 & ~ ( V_46 | V_47 | V_48 ) ;
V_263 -> V_228 = V_265 -> V_228 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
int V_267 = V_9 -> V_5 ;
T_1 V_268 = F_5 ( V_6 ) -> V_198 . V_13 [ V_267 ] . V_7 [ V_269 ] ;
if ( F_14 ( V_2 -> V_6 ) )
F_15 ( V_2 -> V_6 , V_267 ) ;
F_38 ( V_2 -> V_6 , V_267 , & F_5 ( V_6 ) -> V_198 ) ;
F_34 ( V_2 -> V_6 , V_267 , V_268 ) ;
V_9 -> V_65 = V_270 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_271 * V_272 = V_2 -> V_273 ;
if ( F_14 ( V_6 ) )
F_15 ( V_6 , V_9 -> V_5 ) ;
F_40 ( V_6 , V_9 -> V_5 ) ;
V_272 -> V_274 ( V_2 , V_69 ) ;
F_41 ( V_6 , V_9 -> V_5 , true ) ;
F_42 ( V_6 , V_9 -> V_5 , V_275 , V_276 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 == V_50 ) {
T_2 V_277 = F_43 ( V_6 , V_9 -> V_5 , V_278 ) ;
F_8 ( V_6 , V_9 -> V_5 , V_278 , V_277 & ~ 0x10000 ) ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_271 * V_272 = V_2 -> V_273 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
F_38 ( V_6 , V_9 -> V_5 , & F_5 ( V_6 ) -> V_12 ) ;
F_45 ( V_2 , V_2 -> V_259 , V_2 -> V_260 , NULL ) ;
#ifdef F_46
{
T_1 V_279 = F_16 ( V_6 , V_9 -> V_5 , V_280 ) ;
V_279 |= F_25 ( V_281 ) ;
F_2 ( V_6 , V_9 -> V_5 , V_280 , V_279 ) ;
}
#endif
V_272 -> V_274 ( V_2 , V_70 ) ;
F_47 ( V_6 , V_9 -> V_5 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct F_5 * V_252 = F_5 ( V_2 -> V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
if ( ! V_9 )
return;
F_49 ( V_2 ) ;
if ( V_252 -> V_258 [ V_9 -> V_5 ] )
F_30 ( V_252 -> V_258 [ V_9 -> V_5 ] ) ;
F_31 ( NULL , & V_252 -> V_258 [ V_9 -> V_5 ] ) ;
F_50 ( V_9 -> V_59 . V_256 ) ;
F_30 ( V_9 -> V_59 . V_256 ) ;
F_31 ( NULL , & V_9 -> V_59 . V_256 ) ;
F_51 ( V_9 ) ;
}
static void
F_52 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_9 -> V_282 . V_6 ;
struct V_283 { T_1 V_284 , V_285 , V_286 ; } V_287 ( ( V_288 ) ) * V_289 ;
int V_290 ;
V_289 = (struct V_283 * ) F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] . V_291 ;
for ( V_290 = 0 ; V_290 < 256 ; V_290 ++ ) {
V_289 [ V_290 ] . V_284 = V_9 -> V_292 . V_284 [ V_290 ] >> 8 ;
V_289 [ V_290 ] . V_285 = V_9 -> V_292 . V_285 [ V_290 ] >> 8 ;
V_289 [ V_290 ] . V_286 = V_9 -> V_292 . V_286 [ V_290 ] >> 8 ;
}
F_53 ( V_6 , V_9 -> V_5 , & F_5 ( V_6 ) -> V_12 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct F_5 * V_252 = F_5 ( V_2 -> V_6 ) ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
if ( V_252 -> V_258 [ V_9 -> V_5 ] )
F_30 ( V_252 -> V_258 [ V_9 -> V_5 ] ) ;
F_31 ( NULL , & V_252 -> V_258 [ V_9 -> V_5 ] ) ;
}
static void
F_55 ( struct V_1 * V_2 , T_3 * V_284 , T_3 * V_285 , T_3 * V_286 , T_2 V_293 ,
T_2 V_294 )
{
int V_295 = ( V_293 + V_294 > 256 ) ? 256 : V_293 + V_294 , V_290 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
for ( V_290 = V_293 ; V_290 < V_295 ; V_290 ++ ) {
V_9 -> V_292 . V_284 [ V_290 ] = V_284 [ V_290 ] ;
V_9 -> V_292 . V_285 [ V_290 ] = V_285 [ V_290 ] ;
V_9 -> V_292 . V_286 [ V_290 ] = V_286 [ V_290 ] ;
}
if ( ! V_9 -> V_282 . V_75 ) {
V_9 -> V_292 . V_237 = 0 ;
return;
}
F_52 ( V_2 ) ;
}
static int
F_56 ( struct V_1 * V_2 ,
struct V_74 * V_296 ,
int V_259 , int V_260 , bool V_297 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_23 * V_24 = V_23 ( V_6 ) ;
struct V_3 * V_11 = & F_5 ( V_6 ) -> V_12 . V_13 [ V_9 -> V_5 ] ;
struct V_74 * V_298 ;
struct V_253 * V_75 ;
int V_299 , V_300 ;
F_12 ( V_24 , L_5 , V_9 -> V_5 ) ;
if ( ! V_297 && ! V_2 -> V_75 ) {
F_12 ( V_24 , L_6 ) ;
return 0 ;
}
if ( V_297 ) {
V_298 = V_296 ;
V_75 = V_253 ( V_296 ) ;
} else {
V_298 = V_2 -> V_75 ;
V_75 = V_253 ( V_2 -> V_75 ) ;
}
V_9 -> V_75 . V_61 = V_75 -> V_256 -> V_301 . V_61 ;
if ( V_9 -> V_292 . V_237 != V_298 -> V_237 ) {
V_9 -> V_292 . V_237 = V_298 -> V_237 ;
F_52 ( V_2 ) ;
}
V_11 -> V_7 [ V_236 ] &= ~ 3 ;
V_11 -> V_7 [ V_236 ] |= ( V_2 -> V_75 -> V_237 + 1 ) / 8 ;
V_11 -> V_239 &= ~ V_243 ;
if ( V_2 -> V_75 -> V_237 == 16 )
V_11 -> V_239 |= V_243 ;
F_1 ( V_2 , V_11 , V_236 ) ;
F_8 ( V_6 , V_9 -> V_5 , V_302 ,
V_11 -> V_239 ) ;
V_11 -> V_7 [ V_152 ] = V_298 -> V_153 [ 0 ] >> 3 ;
V_11 -> V_7 [ V_158 ] =
F_24 ( V_298 -> V_153 [ 0 ] >> 3 , 8 , V_159 ) ;
V_11 -> V_7 [ V_160 ] =
F_24 ( V_298 -> V_153 [ 0 ] / 8 , 11 , V_161 ) ;
F_1 ( V_2 , V_11 , V_158 ) ;
F_1 ( V_2 , V_11 , V_152 ) ;
F_1 ( V_2 , V_11 , V_160 ) ;
V_11 -> V_303 = V_9 -> V_75 . V_61 & ~ 3 ;
V_11 -> V_303 += ( V_260 * V_298 -> V_153 [ 0 ] ) + ( V_259 * V_298 -> V_304 / 8 ) ;
F_57 ( V_6 , V_9 -> V_5 , V_11 -> V_303 ) ;
F_58 ( V_6 , V_2 -> V_21 . clock , V_298 -> V_304 ,
& V_299 , & V_300 ) ;
V_11 -> V_7 [ V_305 ] = V_299 ;
V_11 -> V_7 [ V_306 ] = V_300 & 0xff ;
F_1 ( V_2 , V_11 , V_305 ) ;
F_1 ( V_2 , V_11 , V_306 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_49 >= V_307 ) {
V_11 -> V_7 [ V_308 ] = V_300 >> 8 ;
F_1 ( V_2 , V_11 , V_308 ) ;
}
return 0 ;
}
static int
F_45 ( struct V_1 * V_2 , int V_259 , int V_260 ,
struct V_74 * V_251 )
{
int V_255 = F_28 ( V_2 , V_251 ) ;
if ( V_255 )
return V_255 ;
return F_56 ( V_2 , V_251 , V_259 , V_260 , false ) ;
}
static int
F_59 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
int V_259 , int V_260 , enum V_309 V_31 )
{
struct V_23 * V_24 = V_23 ( V_2 -> V_6 ) ;
struct V_10 * V_6 = V_24 -> V_6 ;
if ( V_31 == V_310 )
F_60 ( V_6 ) ;
else
F_61 ( V_6 ) ;
return F_56 ( V_2 , V_75 , V_259 , V_260 , true ) ;
}
static void F_62 ( struct V_10 * V_6 , struct V_311 * V_312 ,
struct V_311 * V_313 )
{
int V_314 = F_63 ( V_6 ) ;
T_2 V_315 ;
int V_290 , V_316 ;
for ( V_290 = 0 ; V_290 < V_314 ; V_290 ++ ) {
for ( V_316 = 0 ; V_316 < V_314 ; V_316 ++ ) {
V_315 = F_64 ( V_312 , V_290 * 64 + V_316 ) ;
F_65 ( V_313 , V_290 * V_314 + V_316 , ( V_315 & 0x80000000 ) >> 16
| ( V_315 & 0xf80000 ) >> 9
| ( V_315 & 0xf800 ) >> 6
| ( V_315 & 0xf8 ) >> 3 ) ;
}
}
}
static void F_66 ( struct V_10 * V_6 , struct V_311 * V_312 ,
struct V_311 * V_313 )
{
T_2 V_315 ;
int V_317 , V_290 ;
for ( V_290 = 0 ; V_290 < 64 * 64 ; V_290 ++ ) {
V_315 = F_64 ( V_312 , V_290 ) ;
V_317 = V_315 >> 24 ;
if ( V_317 > 0 && V_317 < 255 )
V_315 = ( V_315 & 0x00ffffff ) | ( ( V_317 + 1 ) << 24 ) ;
#ifdef F_46
{
struct V_23 * V_24 = V_23 ( V_6 ) ;
if ( F_11 ( V_24 -> V_27 ) -> V_40 == 0x11 ) {
V_315 = ( ( V_315 & 0x000000ff ) << 24 ) |
( ( V_315 & 0x0000ff00 ) << 8 ) |
( ( V_315 & 0x00ff0000 ) >> 8 ) |
( ( V_315 & 0xff000000 ) >> 24 ) ;
}
}
#endif
F_67 ( V_313 , V_290 , V_315 ) ;
}
}
static int
F_68 ( struct V_1 * V_2 , struct V_318 * V_319 ,
T_2 V_320 , T_2 V_314 , T_2 V_321 )
{
struct V_23 * V_24 = V_23 ( V_2 -> V_6 ) ;
struct V_10 * V_6 = V_24 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_311 * V_59 = NULL ;
struct V_322 * V_323 ;
int V_255 = 0 ;
if ( ! V_320 ) {
V_9 -> V_59 . V_324 ( V_9 , true ) ;
return 0 ;
}
if ( V_314 != 64 || V_321 != 64 )
return - V_325 ;
V_323 = F_69 ( V_6 , V_319 , V_320 ) ;
if ( ! V_323 )
return - V_326 ;
V_59 = F_70 ( V_323 ) ;
V_255 = F_71 ( V_59 ) ;
if ( V_255 )
goto V_327;
if ( F_11 ( V_24 -> V_27 ) -> V_40 >= 0x11 )
F_66 ( V_6 , V_59 , V_9 -> V_59 . V_256 ) ;
else
F_62 ( V_6 , V_59 , V_9 -> V_59 . V_256 ) ;
F_50 ( V_59 ) ;
V_9 -> V_59 . V_61 = V_9 -> V_59 . V_256 -> V_301 . V_61 ;
V_9 -> V_59 . V_60 ( V_9 , V_9 -> V_59 . V_61 ) ;
V_9 -> V_59 . V_328 ( V_9 , true ) ;
V_327:
F_72 ( V_323 ) ;
return V_255 ;
}
static int
F_73 ( struct V_1 * V_2 , int V_259 , int V_260 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
V_9 -> V_59 . V_329 ( V_9 , V_259 , V_260 ) ;
return 0 ;
}
int
F_74 ( struct V_330 * V_331 )
{
struct V_10 * V_6 ;
struct V_23 * V_24 ;
int V_255 ;
struct V_1 * V_2 ;
bool V_332 = false ;
if ( ! V_331 || ! V_331 -> V_2 )
return - V_325 ;
V_6 = V_331 -> V_2 -> V_6 ;
V_255 = F_75 ( V_6 -> V_6 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_76 ( V_331 ) ;
V_24 = V_23 ( V_6 ) ;
F_23 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 -> V_333 )
V_332 = true ;
}
F_77 ( V_6 -> V_6 ) ;
if ( V_332 && ! V_24 -> V_334 ) {
V_24 -> V_334 = true ;
return V_255 ;
}
if ( ! V_332 && V_24 -> V_334 ) {
F_78 ( V_6 -> V_6 ) ;
V_24 -> V_334 = false ;
}
F_78 ( V_6 -> V_6 ) ;
return V_255 ;
}
int
F_79 ( struct V_10 * V_6 , int V_335 )
{
struct F_3 * V_9 ;
int V_255 , V_290 ;
V_9 = F_80 ( sizeof( * V_9 ) , V_336 ) ;
if ( ! V_9 )
return - V_337 ;
for ( V_290 = 0 ; V_290 < 256 ; V_290 ++ ) {
V_9 -> V_292 . V_284 [ V_290 ] = V_290 << 8 ;
V_9 -> V_292 . V_285 [ V_290 ] = V_290 << 8 ;
V_9 -> V_292 . V_286 [ V_290 ] = V_290 << 8 ;
}
V_9 -> V_292 . V_237 = 0 ;
V_9 -> V_5 = V_335 ;
V_9 -> V_65 = V_270 ;
F_81 ( V_6 , & V_9 -> V_282 , & V_338 ) ;
F_82 ( & V_9 -> V_282 , & V_339 ) ;
F_83 ( & V_9 -> V_282 , 256 ) ;
V_255 = F_84 ( V_6 , 64 * 64 * 4 , 0x100 , V_257 ,
0 , 0x0000 , NULL , & V_9 -> V_59 . V_256 ) ;
if ( ! V_255 ) {
V_255 = F_29 ( V_9 -> V_59 . V_256 , V_257 ) ;
if ( ! V_255 ) {
V_255 = F_71 ( V_9 -> V_59 . V_256 ) ;
if ( V_255 )
F_30 ( V_9 -> V_59 . V_256 ) ;
}
if ( V_255 )
F_31 ( NULL , & V_9 -> V_59 . V_256 ) ;
}
F_85 ( V_9 ) ;
return 0 ;
}
