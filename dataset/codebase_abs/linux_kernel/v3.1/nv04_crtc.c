static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
F_2 ( V_2 -> V_6 , F_3 ( V_2 ) -> V_5 , V_5 ,
V_4 -> V_7 [ V_5 ] ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_8 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_6 -> V_12 ;
struct V_3 * V_13 = & V_11 -> V_14 . V_15 [ V_9 -> V_5 ] ;
V_13 -> V_7 [ V_16 ] = V_9 -> V_17 = V_8 ;
if ( V_9 -> V_17 && F_5 ( V_2 -> V_6 ) ) {
V_13 -> V_7 [ V_16 ] = 0x80 ;
V_13 -> V_7 [ V_18 ] = V_9 -> V_17 << 2 ;
F_1 ( V_2 , V_13 , V_18 ) ;
}
F_1 ( V_2 , V_13 , V_16 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_8 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_6 -> V_12 ;
struct V_3 * V_13 = & V_11 -> V_14 . V_15 [ V_9 -> V_5 ] ;
V_9 -> V_19 = V_8 ;
if ( V_8 < 0 )
V_8 += 0x40 ;
V_13 -> V_20 = V_8 ;
F_7 ( V_2 -> V_6 , V_9 -> V_5 , V_21 , V_13 -> V_20 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_6 = V_2 -> V_6 ;
struct V_10 * V_11 = V_6 -> V_12 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_26 * V_27 = & V_11 -> V_14 ;
struct V_3 * V_13 = & V_27 -> V_15 [ V_9 -> V_5 ] ;
struct V_28 * V_29 = & V_13 -> V_30 ;
struct V_31 V_32 ;
if ( F_9 ( V_6 , V_9 -> V_5 ? V_33 : V_34 , & V_32 ) )
return;
V_29 -> V_35 = 0 ;
if ( V_11 -> V_36 > 0x40 && V_24 <= ( V_32 . V_37 . V_38 / 2 ) )
memset ( & V_32 . V_39 , 0 , sizeof( V_32 . V_39 ) ) ;
if ( ! F_10 ( V_6 , & V_32 , V_24 , V_29 ) )
return;
V_27 -> V_40 &= V_41 | V_42 | V_43 ;
if ( V_11 -> V_44 == V_45 )
V_27 -> V_40 |= V_46 ;
if ( V_11 -> V_36 < 0x41 )
V_27 -> V_40 |= V_47 |
V_48 ;
V_27 -> V_40 |= V_9 -> V_5 ? V_42 : V_41 ;
if ( V_29 -> V_35 )
F_11 ( V_6 , L_1 ,
V_29 -> V_49 , V_29 -> V_50 , V_29 -> V_51 , V_29 -> V_52 , V_29 -> V_53 ) ;
else
F_11 ( V_6 , L_2 ,
V_29 -> V_49 , V_29 -> V_51 , V_29 -> V_53 ) ;
V_9 -> V_54 . V_55 ( V_9 , V_9 -> V_54 . V_56 ) ;
}
static void
F_12 ( struct V_1 * V_2 , int V_23 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_25 * V_6 = V_2 -> V_6 ;
unsigned char V_57 = 0 , V_58 = 0 ;
unsigned char V_59 ;
F_11 ( V_6 , L_3 , V_23 ,
V_9 -> V_5 ) ;
if ( V_9 -> V_60 == V_23 )
return;
V_9 -> V_60 = V_23 ;
if ( F_13 ( V_6 ) )
F_14 ( V_6 , V_9 -> V_5 ) ;
V_59 = F_15 ( V_6 , V_9 -> V_5 ,
V_61 ) & ~ 0xC0 ;
switch ( V_23 ) {
case V_62 :
V_57 = 0x20 ;
V_58 = 0x80 ;
V_59 |= 0x80 ;
break;
case V_63 :
V_57 = 0x20 ;
V_58 = 0x80 ;
V_59 |= 0x40 ;
break;
case V_64 :
V_57 = 0x20 ;
V_58 = 0x00 ;
V_59 |= 0xC0 ;
break;
case V_65 :
default:
V_57 = 0x00 ;
V_58 = 0x80 ;
break;
}
F_16 ( V_6 , V_9 -> V_5 , true ) ;
V_57 |= ( F_17 ( V_6 , V_9 -> V_5 , V_66 ) & ~ 0x20 ) ;
F_18 ( V_6 , V_9 -> V_5 , V_66 , V_57 ) ;
V_58 |= ( F_15 ( V_6 , V_9 -> V_5 , V_67 ) & ~ 0x80 ) ;
F_19 ( 10 ) ;
F_2 ( V_6 , V_9 -> V_5 , V_67 , V_58 ) ;
F_16 ( V_6 , V_9 -> V_5 , false ) ;
F_2 ( V_6 , V_9 -> V_5 , V_61 , V_59 ) ;
}
static bool
F_20 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_22 * V_68 )
{
return true ;
}
static void
F_21 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_25 * V_6 = V_2 -> V_6 ;
struct V_10 * V_11 = V_6 -> V_12 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_3 * V_13 = & V_11 -> V_14 . V_15 [ V_9 -> V_5 ] ;
struct V_69 * V_70 = V_2 -> V_70 ;
int V_71 = ( V_23 -> V_72 >> 3 ) - 1 ;
int V_73 = ( V_23 -> V_74 >> 3 ) + 1 ;
int V_75 = ( V_23 -> V_76 >> 3 ) + 1 ;
int V_77 = ( V_23 -> V_78 >> 3 ) - 5 ;
int V_79 = ( V_23 -> V_72 >> 3 ) - 1 ;
int V_80 = ( V_23 -> V_78 >> 3 ) - 1 ;
int V_81 = V_23 -> V_82 - 1 ;
int V_83 = V_23 -> V_84 - 1 ;
int V_85 = V_23 -> V_86 - 1 ;
int V_87 = V_23 -> V_88 - 2 ;
int V_89 = V_23 -> V_82 - 1 ;
int V_90 = V_23 -> V_88 - 1 ;
struct V_91 * V_92 ;
bool V_93 = false ;
F_22 (encoder, &dev->mode_config.encoder_list, head) {
struct V_94 * V_95 = V_94 ( V_92 ) ;
if ( V_92 -> V_2 == V_2 &&
( V_95 -> V_96 -> type == V_97 ||
V_95 -> V_96 -> type == V_98 ) )
V_93 = true ;
}
if ( V_93 ) {
V_83 = V_87 - 3 ;
V_85 = V_87 - 2 ;
V_89 = V_83 ;
V_73 = V_77 - 5 ;
V_75 = V_77 - 2 ;
V_80 = V_77 + 4 ;
#if 0
if (dev->overlayAdaptor && dev_priv->card_type >= NV_10)
horizTotal += 2;
#endif
}
if ( V_23 -> V_99 & V_100 )
V_87 |= 1 ;
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
if ( ( V_23 -> V_99 & ( V_101 | V_102 ) )
&& ( V_23 -> V_99 & ( V_103 | V_104 ) ) ) {
V_13 -> V_105 = 0x23 ;
if ( V_23 -> V_99 & V_102 )
V_13 -> V_105 |= 0x40 ;
if ( V_23 -> V_99 & V_104 )
V_13 -> V_105 |= 0x80 ;
} else {
int V_106 = V_23 -> V_106 ;
if ( V_23 -> V_99 & V_107 )
V_106 *= 2 ;
if ( V_23 -> V_108 > 1 )
V_106 *= V_23 -> V_108 ;
if ( V_106 < 400 )
V_13 -> V_105 = 0xA3 ;
else if ( V_106 < 480 )
V_13 -> V_105 = 0x63 ;
else if ( V_106 < 768 )
V_13 -> V_105 = 0xE3 ;
else
V_13 -> V_105 = 0x23 ;
}
V_13 -> V_105 |= ( V_23 -> V_109 & 0x03 ) << 2 ;
V_13 -> V_110 [ V_111 ] = 0x00 ;
if ( V_23 -> V_99 & V_112 )
V_13 -> V_110 [ V_66 ] = 0x29 ;
else
V_13 -> V_110 [ V_66 ] = 0x21 ;
V_13 -> V_110 [ V_113 ] = 0x0F ;
V_13 -> V_110 [ V_114 ] = 0x00 ;
V_13 -> V_110 [ V_115 ] = 0x0E ;
V_13 -> V_7 [ V_116 ] = V_77 ;
V_13 -> V_7 [ V_117 ] = V_71 ;
V_13 -> V_7 [ V_118 ] = V_79 ;
V_13 -> V_7 [ V_119 ] = ( 1 << 7 ) |
F_23 ( V_80 , 0 , V_120 ) ;
V_13 -> V_7 [ V_121 ] = V_73 ;
V_13 -> V_7 [ V_122 ] = F_23 ( V_80 , 5 , V_123 ) |
F_23 ( V_75 , 0 , V_124 ) ;
V_13 -> V_7 [ V_125 ] = V_87 ;
V_13 -> V_7 [ V_126 ] = F_23 ( V_83 , 9 , V_127 ) |
F_23 ( V_81 , 9 , V_128 ) |
F_23 ( V_87 , 9 , V_129 ) |
( 1 << 4 ) |
F_23 ( V_89 , 8 , V_130 ) |
F_23 ( V_83 , 8 , V_131 ) |
F_23 ( V_81 , 8 , V_132 ) |
F_23 ( V_87 , 8 , V_133 ) ;
V_13 -> V_7 [ V_134 ] = 0x00 ;
V_13 -> V_7 [ V_135 ] = ( ( V_23 -> V_99 & V_107 ) ? F_24 ( V_136 ) : 0 ) |
1 << 6 |
F_23 ( V_89 , 9 , V_137 ) ;
V_13 -> V_7 [ V_138 ] = 0x00 ;
V_13 -> V_7 [ V_139 ] = 0x00 ;
V_13 -> V_7 [ V_140 ] = 0x00 ;
V_13 -> V_7 [ V_141 ] = 0x00 ;
V_13 -> V_7 [ V_142 ] = 0x00 ;
V_13 -> V_7 [ V_143 ] = 0x00 ;
V_13 -> V_7 [ V_144 ] = V_83 ;
V_13 -> V_7 [ V_145 ] = 1 << 5 | F_23 ( V_85 , 0 , V_146 ) ;
V_13 -> V_7 [ V_147 ] = V_81 ;
V_13 -> V_7 [ V_148 ] = V_70 -> V_149 / 8 ;
V_13 -> V_7 [ V_150 ] = 0x00 ;
V_13 -> V_7 [ V_151 ] = V_89 ;
V_13 -> V_7 [ V_152 ] = V_90 ;
V_13 -> V_7 [ V_67 ] = 0x43 ;
V_13 -> V_7 [ V_153 ] = 0xff ;
V_13 -> V_7 [ V_154 ] =
F_23 ( V_70 -> V_149 / 8 , 8 , V_155 ) ;
V_13 -> V_7 [ V_156 ] =
F_23 ( V_70 -> V_149 / 8 , 11 , V_157 ) ;
V_13 -> V_7 [ V_61 ] = V_23 -> V_72 < 1280 ?
F_24 ( V_158 ) : 0x00 ;
V_13 -> V_7 [ V_159 ] = F_23 ( V_80 , 6 , V_160 ) |
F_23 ( V_89 , 10 , V_161 ) |
F_23 ( V_83 , 10 , V_162 ) |
F_23 ( V_81 , 10 , V_163 ) |
F_23 ( V_87 , 10 , V_164 ) ;
V_13 -> V_7 [ V_165 ] = F_23 ( V_73 , 8 , V_166 ) |
F_23 ( V_79 , 8 , V_167 ) |
F_23 ( V_71 , 8 , V_168 ) |
F_23 ( V_77 , 8 , V_169 ) ;
V_13 -> V_7 [ V_170 ] = F_23 ( V_89 , 11 , V_171 ) |
F_23 ( V_83 , 11 , V_172 ) |
F_23 ( V_81 , 11 , V_173 ) |
F_23 ( V_87 , 11 , V_174 ) ;
if ( V_23 -> V_99 & V_100 ) {
V_77 = ( V_77 >> 1 ) & ~ 1 ;
V_13 -> V_7 [ V_175 ] = V_77 ;
V_13 -> V_7 [ V_165 ] |= F_23 ( V_77 , 8 , V_176 ) ;
} else
V_13 -> V_7 [ V_175 ] = 0xff ;
V_13 -> V_177 [ V_178 ] = 0x00 ;
V_13 -> V_177 [ V_179 ] = 0x00 ;
V_13 -> V_177 [ V_180 ] = 0x00 ;
V_13 -> V_177 [ V_181 ] = 0x00 ;
V_13 -> V_177 [ V_182 ] = 0x00 ;
V_13 -> V_177 [ V_183 ] = 0x40 ;
V_13 -> V_177 [ V_184 ] = 0x05 ;
V_13 -> V_177 [ V_185 ] = 0x0F ;
V_13 -> V_177 [ V_186 ] = 0xFF ;
V_13 -> V_187 [ 0 ] = 0x00 ;
V_13 -> V_187 [ 1 ] = 0x01 ;
V_13 -> V_187 [ 2 ] = 0x02 ;
V_13 -> V_187 [ 3 ] = 0x03 ;
V_13 -> V_187 [ 4 ] = 0x04 ;
V_13 -> V_187 [ 5 ] = 0x05 ;
V_13 -> V_187 [ 6 ] = 0x06 ;
V_13 -> V_187 [ 7 ] = 0x07 ;
V_13 -> V_187 [ 8 ] = 0x08 ;
V_13 -> V_187 [ 9 ] = 0x09 ;
V_13 -> V_187 [ 10 ] = 0x0A ;
V_13 -> V_187 [ 11 ] = 0x0B ;
V_13 -> V_187 [ 12 ] = 0x0C ;
V_13 -> V_187 [ 13 ] = 0x0D ;
V_13 -> V_187 [ 14 ] = 0x0E ;
V_13 -> V_187 [ 15 ] = 0x0F ;
V_13 -> V_187 [ V_188 ] = 0x01 ;
V_13 -> V_187 [ V_189 ] = 0x00 ;
V_13 -> V_187 [ V_190 ] = 0x0F ;
V_13 -> V_187 [ V_191 ] = 0x00 ;
V_13 -> V_187 [ V_192 ] = 0x00 ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_25 * V_6 = V_2 -> V_6 ;
struct V_10 * V_11 = V_6 -> V_12 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_3 * V_13 = & V_11 -> V_14 . V_15 [ V_9 -> V_5 ] ;
struct V_3 * V_193 = & V_11 -> V_194 . V_15 [ V_9 -> V_5 ] ;
struct V_91 * V_92 ;
bool V_195 = false , V_196 = false , V_197 = false ,
V_198 = false ;
F_22 (encoder, &dev->mode_config.encoder_list, head) {
struct V_94 * V_95 = V_94 ( V_92 ) ;
bool V_199 = false ;
if ( V_92 -> V_2 != V_2 )
continue;
if ( V_95 -> V_96 -> type == V_97 )
V_199 = V_195 = true ;
if ( V_95 -> V_96 -> type == V_200 )
V_197 = true ;
if ( V_95 -> V_96 -> type == V_98 )
V_199 = V_196 = true ;
if ( V_95 -> V_96 -> V_201 != V_202 && V_199 )
V_198 = true ;
}
V_13 -> V_7 [ V_203 ] = V_193 -> V_7 [ V_203 ] & ~ ( 1 << 5 ) ;
V_13 -> V_204 = 0 ;
if ( V_9 -> V_5 == 0 )
V_13 -> V_204 |= V_205 ;
#if 0
if (dev->overlayAdaptor) {
NVPortPrivPtr pPriv = GET_OVERLAY_PRIVATE(dev);
if (pPriv->overlayCRTC == nv_crtc->index)
regp->crtc_eng_ctrl |= NV_CRTC_FSEL_OVERLAY;
}
#endif
V_13 -> V_206 = V_207 |
V_208 |
V_209 ;
if ( V_11 -> V_36 >= 0x11 )
V_13 -> V_206 |= V_210 ;
if ( V_23 -> V_99 & V_107 )
V_13 -> V_206 |= V_211 ;
V_13 -> V_7 [ V_212 ] = 0 ;
V_13 -> V_7 [ V_213 ] = 0 ;
if ( V_195 )
V_13 -> V_7 [ V_214 ] = 0x11 ;
else if ( V_196 )
V_13 -> V_7 [ V_214 ] = 0x88 ;
else
V_13 -> V_7 [ V_214 ] = 0x22 ;
V_13 -> V_7 [ V_215 ] = V_193 -> V_7 [ V_215 ] ;
F_4 ( V_2 , V_9 -> V_17 ) ;
if ( V_9 -> V_5 == 0 )
V_13 -> V_7 [ V_216 ] = V_193 -> V_7 [ V_216 ] | 0x80 ;
V_13 -> V_7 [ V_217 ] = V_11 -> V_194 . V_15 [ 0 ] . V_7 [ V_217 ] ;
if ( ! V_9 -> V_5 )
V_13 -> V_7 [ V_217 ] += 4 ;
V_13 -> V_7 [ V_218 ] = V_198 ;
if ( V_11 -> V_44 >= V_219 )
V_13 -> V_7 [ 0x9f ] = V_198 ? 0x11 : 0x1 ;
V_13 -> V_220 = V_23 -> V_82 - 3 ;
V_13 -> V_221 = V_23 -> V_82 - 1 ;
if ( V_11 -> V_44 == V_45 )
V_13 -> V_222 = F_26 ( V_6 , 0 , V_223 ) ;
if ( V_11 -> V_44 >= V_219 )
V_13 -> V_224 = F_26 ( V_6 , 0 , V_225 ) ;
if ( V_11 -> V_44 >= V_226 )
V_13 -> V_227 = V_228 ;
else
V_13 -> V_227 = V_229 ;
if ( V_11 -> V_44 == V_45 ) {
V_13 -> V_7 [ V_230 ] = 0xFF ;
V_13 -> V_7 [ V_231 ] = 0x1 ;
}
V_13 -> V_7 [ V_232 ] = ( V_2 -> V_70 -> V_233 + 1 ) / 8 ;
if ( V_195 || V_196 || V_197 )
V_13 -> V_7 [ V_232 ] |= ( 1 << 7 ) ;
if ( V_11 -> V_44 >= V_226 )
V_13 -> V_234 = ( 1 << 25 ) ;
V_13 -> V_235 = V_236 |
V_237 |
V_238 ;
if ( V_2 -> V_70 -> V_233 == 16 )
V_13 -> V_235 |= V_239 ;
if ( V_11 -> V_36 >= 0x11 )
V_13 -> V_235 |= V_240 ;
V_13 -> V_241 = 0 ;
V_13 -> V_242 = 0 ;
F_6 ( V_2 , V_9 -> V_19 ) ;
V_13 -> V_243 = 0x100 ;
V_13 -> V_244 = 0x0 ;
V_13 -> V_245 = 0xfffff ;
V_13 -> V_246 = 0x1 ;
}
static int
F_27 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_22 * V_68 ,
int V_247 , int V_248 , struct V_69 * V_249 )
{
struct V_25 * V_6 = V_2 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_6 -> V_12 ;
F_11 ( V_6 , L_4 , V_9 -> V_5 ) ;
F_28 ( V_68 ) ;
F_29 ( V_6 , V_9 -> V_5 , - 1 ) ;
F_21 ( V_2 , V_68 ) ;
if ( V_11 -> V_44 == V_45 )
F_7 ( V_6 , 0 , V_250 , V_11 -> V_14 . V_251 ) ;
F_25 ( V_2 , V_68 ) ;
F_8 ( V_2 , V_23 , V_68 -> clock ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_6 -> V_12 ;
struct V_26 * V_27 = & V_11 -> V_14 ;
struct V_3 * V_252 = & V_27 -> V_15 [ V_9 -> V_5 ] ;
struct V_26 * V_253 = & V_11 -> V_194 ;
struct V_3 * V_254 = & V_253 -> V_15 [ V_9 -> V_5 ] ;
if ( F_13 ( V_2 -> V_6 ) )
F_14 ( V_2 -> V_6 , V_9 -> V_5 ) ;
F_31 ( V_2 -> V_6 , V_9 -> V_5 , V_253 ) ;
V_27 -> V_251 = V_253 -> V_251 & ~ ( 0x5 << 16 ) ;
V_252 -> V_7 [ V_255 ] = V_254 -> V_7 [ V_255 ] ;
V_27 -> V_40 = V_253 -> V_40 & ~ ( V_41 | V_42 | V_43 ) ;
V_252 -> V_224 = V_254 -> V_224 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_6 -> V_12 ;
int V_256 = V_9 -> V_5 ;
T_1 V_257 = V_11 -> V_194 . V_15 [ V_256 ] . V_7 [ V_258 ] ;
if ( F_13 ( V_2 -> V_6 ) )
F_14 ( V_2 -> V_6 , V_256 ) ;
F_33 ( V_2 -> V_6 , V_256 , & V_11 -> V_194 ) ;
F_29 ( V_2 -> V_6 , V_256 , V_257 ) ;
V_9 -> V_60 = V_259 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_25 * V_6 = V_2 -> V_6 ;
struct V_10 * V_11 = V_6 -> V_12 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_260 * V_261 = V_2 -> V_262 ;
if ( F_13 ( V_6 ) )
F_14 ( V_6 , V_9 -> V_5 ) ;
F_35 ( V_6 , V_9 -> V_5 ) ;
V_261 -> V_263 ( V_2 , V_64 ) ;
F_36 ( V_6 , V_9 -> V_5 , true ) ;
F_37 ( V_6 , V_9 -> V_5 , V_264 , V_265 ) ;
if ( V_11 -> V_44 == V_45 ) {
T_2 V_266 = F_38 ( V_6 , V_9 -> V_5 , V_267 ) ;
F_7 ( V_6 , V_9 -> V_5 , V_267 , V_266 & ~ 0x10000 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_25 * V_6 = V_2 -> V_6 ;
struct V_260 * V_261 = V_2 -> V_262 ;
struct V_10 * V_11 = V_2 -> V_6 -> V_12 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
F_33 ( V_6 , V_9 -> V_5 , & V_11 -> V_14 ) ;
F_40 ( V_2 , V_2 -> V_247 , V_2 -> V_248 , NULL ) ;
#ifdef F_41
{
T_1 V_268 = F_15 ( V_6 , V_9 -> V_5 , V_269 ) ;
V_268 |= F_24 ( V_270 ) ;
F_2 ( V_6 , V_9 -> V_5 , V_269 , V_268 ) ;
}
#endif
V_261 -> V_263 ( V_2 , V_65 ) ;
F_42 ( V_6 , V_9 -> V_5 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
F_11 ( V_2 -> V_6 , L_5 ) ;
if ( ! V_9 )
return;
F_44 ( V_2 ) ;
F_45 ( V_9 -> V_54 . V_271 ) ;
F_46 ( NULL , & V_9 -> V_54 . V_271 ) ;
F_47 ( V_9 ) ;
}
static void
F_48 ( struct V_1 * V_2 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_25 * V_6 = V_9 -> V_272 . V_6 ;
struct V_10 * V_11 = V_6 -> V_12 ;
struct V_273 { T_1 V_274 , V_275 , V_276 ; } V_277 ( ( V_278 ) ) * V_279 ;
int V_280 ;
V_279 = (struct V_273 * ) V_11 -> V_14 . V_15 [ V_9 -> V_5 ] . V_281 ;
for ( V_280 = 0 ; V_280 < 256 ; V_280 ++ ) {
V_279 [ V_280 ] . V_274 = V_9 -> V_282 . V_274 [ V_280 ] >> 8 ;
V_279 [ V_280 ] . V_275 = V_9 -> V_282 . V_275 [ V_280 ] >> 8 ;
V_279 [ V_280 ] . V_276 = V_9 -> V_282 . V_276 [ V_280 ] >> 8 ;
}
F_49 ( V_6 , V_9 -> V_5 , & V_11 -> V_14 ) ;
}
static void
F_50 ( struct V_1 * V_2 , T_3 * V_274 , T_3 * V_275 , T_3 * V_276 , T_2 V_283 ,
T_2 V_284 )
{
int V_285 = ( V_283 + V_284 > 256 ) ? 256 : V_283 + V_284 , V_280 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
for ( V_280 = V_283 ; V_280 < V_285 ; V_280 ++ ) {
V_9 -> V_282 . V_274 [ V_280 ] = V_274 [ V_280 ] ;
V_9 -> V_282 . V_275 [ V_280 ] = V_275 [ V_280 ] ;
V_9 -> V_282 . V_276 [ V_280 ] = V_276 [ V_280 ] ;
}
if ( ! V_9 -> V_272 . V_70 ) {
V_9 -> V_282 . V_233 = 0 ;
return;
}
F_48 ( V_2 ) ;
}
static int
F_51 ( struct V_1 * V_2 ,
struct V_69 * V_286 ,
int V_247 , int V_248 , bool V_287 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_25 * V_6 = V_2 -> V_6 ;
struct V_10 * V_11 = V_6 -> V_12 ;
struct V_3 * V_13 = & V_11 -> V_14 . V_15 [ V_9 -> V_5 ] ;
struct V_69 * V_288 ;
struct V_289 * V_70 ;
int V_290 , V_291 ;
int V_292 ;
F_11 ( V_6 , L_6 , V_9 -> V_5 ) ;
if ( ! V_287 && ! V_2 -> V_70 ) {
F_11 ( V_6 , L_7 ) ;
return 0 ;
}
if ( V_287 ) {
V_288 = V_286 ;
V_70 = V_289 ( V_286 ) ;
} else {
V_288 = V_2 -> V_70 ;
V_70 = V_289 ( V_2 -> V_70 ) ;
V_292 = F_52 ( V_70 -> V_271 , V_293 ) ;
if ( V_292 )
return V_292 ;
if ( V_286 ) {
struct V_289 * V_294 = V_289 ( V_286 ) ;
F_53 ( V_294 -> V_271 ) ;
}
}
V_9 -> V_70 . V_56 = V_70 -> V_271 -> V_295 . V_56 ;
if ( V_9 -> V_282 . V_233 != V_288 -> V_233 ) {
V_9 -> V_282 . V_233 = V_288 -> V_233 ;
F_48 ( V_2 ) ;
}
V_13 -> V_7 [ V_232 ] &= ~ 3 ;
V_13 -> V_7 [ V_232 ] |= ( V_2 -> V_70 -> V_233 + 1 ) / 8 ;
V_13 -> V_235 &= ~ V_239 ;
if ( V_2 -> V_70 -> V_233 == 16 )
V_13 -> V_235 |= V_239 ;
F_1 ( V_2 , V_13 , V_232 ) ;
F_7 ( V_6 , V_9 -> V_5 , V_296 ,
V_13 -> V_235 ) ;
V_13 -> V_7 [ V_148 ] = V_288 -> V_149 >> 3 ;
V_13 -> V_7 [ V_154 ] =
F_23 ( V_288 -> V_149 >> 3 , 8 , V_155 ) ;
V_13 -> V_7 [ V_156 ] =
F_23 ( V_288 -> V_149 / 8 , 11 , V_157 ) ;
F_1 ( V_2 , V_13 , V_154 ) ;
F_1 ( V_2 , V_13 , V_148 ) ;
F_1 ( V_2 , V_13 , V_156 ) ;
V_13 -> V_297 = V_9 -> V_70 . V_56 & ~ 3 ;
V_13 -> V_297 += ( V_248 * V_288 -> V_149 ) + ( V_247 * V_288 -> V_298 / 8 ) ;
F_54 ( V_6 , V_9 -> V_5 , V_13 -> V_297 ) ;
F_55 ( V_6 , V_2 -> V_23 . clock , V_288 -> V_298 ,
& V_290 , & V_291 ) ;
V_13 -> V_7 [ V_299 ] = V_290 ;
V_13 -> V_7 [ V_300 ] = V_291 & 0xff ;
F_1 ( V_2 , V_13 , V_299 ) ;
F_1 ( V_2 , V_13 , V_300 ) ;
if ( V_11 -> V_44 >= V_301 ) {
V_13 -> V_7 [ V_302 ] = V_291 >> 8 ;
F_1 ( V_2 , V_13 , V_302 ) ;
}
return 0 ;
}
static int
F_40 ( struct V_1 * V_2 , int V_247 , int V_248 ,
struct V_69 * V_249 )
{
return F_51 ( V_2 , V_249 , V_247 , V_248 , false ) ;
}
static int
F_56 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
int V_247 , int V_248 , enum V_303 V_27 )
{
struct V_10 * V_11 = V_2 -> V_6 -> V_12 ;
struct V_25 * V_6 = V_11 -> V_6 ;
if ( V_27 == V_304 )
F_57 ( V_6 ) ;
else
F_58 ( V_6 ) ;
return F_51 ( V_2 , V_70 , V_247 , V_248 , true ) ;
}
static void F_59 ( struct V_25 * V_6 , struct V_305 * V_306 ,
struct V_305 * V_307 )
{
int V_308 = F_60 ( V_6 ) ;
T_2 V_309 ;
int V_280 , V_310 ;
for ( V_280 = 0 ; V_280 < V_308 ; V_280 ++ ) {
for ( V_310 = 0 ; V_310 < V_308 ; V_310 ++ ) {
V_309 = F_61 ( V_306 , V_280 * 64 + V_310 ) ;
F_62 ( V_307 , V_280 * V_308 + V_310 , ( V_309 & 0x80000000 ) >> 16
| ( V_309 & 0xf80000 ) >> 9
| ( V_309 & 0xf800 ) >> 6
| ( V_309 & 0xf8 ) >> 3 ) ;
}
}
}
static void F_63 ( struct V_25 * V_6 , struct V_305 * V_306 ,
struct V_305 * V_307 )
{
T_2 V_309 ;
int V_311 , V_280 ;
for ( V_280 = 0 ; V_280 < 64 * 64 ; V_280 ++ ) {
V_309 = F_61 ( V_306 , V_280 ) ;
V_311 = V_309 >> 24 ;
if ( V_311 > 0 && V_311 < 255 )
V_309 = ( V_309 & 0x00ffffff ) | ( ( V_311 + 1 ) << 24 ) ;
#ifdef F_41
{
struct V_10 * V_11 = V_6 -> V_12 ;
if ( V_11 -> V_36 == 0x11 ) {
V_309 = ( ( V_309 & 0x000000ff ) << 24 ) |
( ( V_309 & 0x0000ff00 ) << 8 ) |
( ( V_309 & 0x00ff0000 ) >> 8 ) |
( ( V_309 & 0xff000000 ) >> 24 ) ;
}
}
#endif
F_64 ( V_307 , V_280 , V_309 ) ;
}
}
static int
F_65 ( struct V_1 * V_2 , struct V_312 * V_313 ,
T_2 V_314 , T_2 V_308 , T_2 V_315 )
{
struct V_10 * V_11 = V_2 -> V_6 -> V_12 ;
struct V_25 * V_6 = V_11 -> V_6 ;
struct F_3 * V_9 = F_3 ( V_2 ) ;
struct V_305 * V_54 = NULL ;
struct V_316 * V_317 ;
int V_292 = 0 ;
if ( ! V_314 ) {
V_9 -> V_54 . V_318 ( V_9 , true ) ;
return 0 ;
}
if ( V_308 != 64 || V_315 != 64 )
return - V_319 ;
V_317 = F_66 ( V_6 , V_313 , V_314 ) ;
if ( ! V_317 )
return - V_320 ;
V_54 = F_67 ( V_317 ) ;
V_292 = F_68 ( V_54 ) ;
if ( V_292 )
goto V_321;
if ( V_11 -> V_36 >= 0x11 )
F_63 ( V_6 , V_54 , V_9 -> V_54 . V_271 ) ;
else
F_59 ( V_6 , V_54 , V_9 -> V_54 . V_271 ) ;
F_45 ( V_54 ) ;
V_9 -> V_54 . V_56 = V_9 -> V_54 . V_271 -> V_295 . V_56 ;
V_9 -> V_54 . V_55 ( V_9 , V_9 -> V_54 . V_56 ) ;
V_9 -> V_54 . V_322 ( V_9 , true ) ;
V_321:
F_69 ( V_317 ) ;
return V_292 ;
}
static int
F_70 ( struct V_1 * V_2 , int V_247 , int V_248 )
{
struct F_3 * V_9 = F_3 ( V_2 ) ;
V_9 -> V_54 . V_323 ( V_9 , V_247 , V_248 ) ;
return 0 ;
}
int
F_71 ( struct V_25 * V_6 , int V_324 )
{
struct F_3 * V_9 ;
int V_292 , V_280 ;
V_9 = F_72 ( sizeof( * V_9 ) , V_325 ) ;
if ( ! V_9 )
return - V_326 ;
for ( V_280 = 0 ; V_280 < 256 ; V_280 ++ ) {
V_9 -> V_282 . V_274 [ V_280 ] = V_280 << 8 ;
V_9 -> V_282 . V_275 [ V_280 ] = V_280 << 8 ;
V_9 -> V_282 . V_276 [ V_280 ] = V_280 << 8 ;
}
V_9 -> V_282 . V_233 = 0 ;
V_9 -> V_5 = V_324 ;
V_9 -> V_60 = V_259 ;
F_73 ( V_6 , & V_9 -> V_272 , & V_327 ) ;
F_74 ( & V_9 -> V_272 , & V_328 ) ;
F_75 ( & V_9 -> V_272 , 256 ) ;
V_292 = F_76 ( V_6 , 64 * 64 * 4 , 0x100 , V_293 ,
0 , 0x0000 , & V_9 -> V_54 . V_271 ) ;
if ( ! V_292 ) {
V_292 = F_52 ( V_9 -> V_54 . V_271 , V_293 ) ;
if ( ! V_292 )
V_292 = F_68 ( V_9 -> V_54 . V_271 ) ;
if ( V_292 )
F_46 ( NULL , & V_9 -> V_54 . V_271 ) ;
}
F_77 ( V_9 ) ;
return 0 ;
}
