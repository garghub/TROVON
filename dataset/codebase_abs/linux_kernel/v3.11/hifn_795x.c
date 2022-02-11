static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 [ 0 ] + V_3 ) ;
return V_4 ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 [ 1 ] + V_3 ) ;
return V_4 ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_5 ( ( V_7 T_1 ) F_6 ( V_6 ) , V_2 -> V_5 [ 0 ] + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_5 ( ( V_7 T_1 ) F_6 ( V_6 ) , V_2 -> V_5 [ 1 ] + V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_4 ;
for ( V_8 = 10000 ; V_8 > 0 ; -- V_8 ) {
V_4 = F_1 ( V_2 , V_9 ) ;
if ( ! ( V_4 & V_10 ) )
break;
F_9 ( 1 ) ;
}
if ( ! V_8 )
F_10 ( L_1 , V_2 -> V_11 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_9 , V_12 ) ;
F_8 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_13 ,
V_14 | V_15 |
V_16 | V_17 ) ;
F_4 ( V_2 , V_18 , 0 ) ;
F_7 ( V_2 , V_19 , 0 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_20 )
{
F_12 ( V_2 ) ;
F_7 ( V_2 , V_21 , V_22 |
V_23 | V_24 ) ;
F_14 ( 1 ) ;
if ( V_20 ) {
F_7 ( V_2 , V_21 , V_24 ) ;
F_14 ( 1 ) ;
} else {
F_7 ( V_2 , V_21 , V_24 |
V_22 ) ;
F_11 ( V_2 ) ;
}
F_7 ( V_2 , V_21 , V_22 |
V_23 | V_24 ) ;
F_11 ( V_2 ) ;
}
static T_1 F_15 ( T_2 V_25 , T_3 V_26 )
{
int V_8 ;
T_1 V_27 ;
for ( V_8 = 0 ; V_8 < V_26 ; V_8 ++ ) {
V_27 = V_25 & 0x80080125 ;
V_27 ^= V_27 >> 16 ;
V_27 ^= V_27 >> 8 ;
V_27 ^= V_27 >> 4 ;
V_27 ^= V_27 >> 2 ;
V_27 ^= V_27 >> 1 ;
V_25 = ( V_27 & 1 ) ^ ( V_25 << 1 ) ;
}
return V_25 ;
}
static int F_16 ( struct V_28 * V_29 , int V_30 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 -> V_31 ;
T_4 V_32 ;
V_32 = F_17 ( F_18 ( F_19 () , V_2 -> V_33 ) ) ;
V_32 -= V_2 -> V_34 ;
if ( V_32 <= 0 )
return 1 ;
if ( ! V_30 )
return 0 ;
F_20 ( V_32 ) ;
return 1 ;
}
static int F_21 ( struct V_28 * V_29 , T_1 * V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 -> V_31 ;
* V_35 = F_3 ( V_2 , V_36 ) ;
V_2 -> V_33 = F_19 () ;
return 4 ;
}
static int F_22 ( struct V_1 * V_2 )
{
V_2 -> V_34 = F_23 ( V_37 ,
V_2 -> V_38 ) * 256 ;
V_2 -> V_29 . V_11 = V_2 -> V_11 ;
V_2 -> V_29 . V_39 = F_16 ,
V_2 -> V_29 . V_40 = F_21 ,
V_2 -> V_29 . V_31 = ( unsigned long ) V_2 ;
return F_24 ( & V_2 -> V_29 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_29 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_8 ;
F_7 ( V_2 , V_41 , F_3 ( V_2 , V_41 ) |
V_42 ) ;
for ( V_8 = 100 ; V_8 > 0 ; -- V_8 ) {
F_14 ( 1 ) ;
if ( ( F_3 ( V_2 , V_41 ) & V_42 ) == 0 )
break;
}
if ( ! V_8 )
F_10 ( L_2 ,
V_2 -> V_11 ) ;
else {
F_7 ( V_2 , V_43 , V_44 ) ;
V_2 -> V_45 |= V_46 ;
F_7 ( V_2 , V_19 , V_2 -> V_45 ) ;
F_10 ( L_3
L_4 , V_2 -> V_11 ) ;
}
F_7 ( V_2 , V_47 ,
F_3 ( V_2 , V_47 ) | V_48 ) ;
F_10 ( L_5 ,
V_2 -> V_11 ) ;
#ifdef F_28
F_3 ( V_2 , V_36 ) ;
V_2 -> V_33 = F_19 () ;
#endif
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_49 , V_50 ;
char * V_51 = NULL ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_30 ( V_52 ) ; V_8 ++ ) {
if ( V_52 [ V_8 ] . V_53 == V_2 -> V_54 -> V_55 &&
V_52 [ V_8 ] . V_56 == V_2 -> V_54 -> V_57 ) {
V_51 = V_52 [ V_8 ] . V_58 ;
break;
}
}
if ( V_51 == NULL ) {
F_10 ( L_6 , V_2 -> V_11 ) ;
return - V_59 ;
}
V_49 = F_3 ( V_2 , V_21 ) ;
F_7 ( V_2 , V_21 ,
V_60 | V_22 |
V_23 | V_24 ) ;
F_14 ( 1 ) ;
V_50 = F_3 ( V_2 , V_61 ) ;
F_14 ( 1 ) ;
F_7 ( V_2 , V_62 , 0 ) ;
F_14 ( 1 ) ;
for ( V_8 = 0 ; V_8 < 12 ; ++ V_8 ) {
V_50 = F_15 ( V_50 , V_51 [ V_8 ] + 0x101 ) ;
F_7 ( V_2 , V_62 , V_50 ) ;
F_14 ( 1 ) ;
}
F_7 ( V_2 , V_21 , V_49 ) ;
F_10 ( L_7 , V_2 -> V_11 , F_31 ( V_2 -> V_54 ) ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
T_1 V_66 = V_2 -> V_67 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_68 ; ++ V_8 )
V_64 -> V_69 [ V_8 ] . V_70 = F_33 ( V_66 +
F_34 ( struct V_63 , V_71 [ V_8 ] [ 0 ] ) ) ;
for ( V_8 = 0 ; V_8 < V_72 ; ++ V_8 )
V_64 -> V_73 [ V_8 ] . V_70 = F_33 ( V_66 +
F_34 ( struct V_63 , V_74 [ V_8 ] [ 0 ] ) ) ;
V_64 -> V_69 [ V_68 ] . V_70 = F_33 ( V_66 +
F_34 ( struct V_63 , V_69 [ 0 ] ) ) ;
V_64 -> V_75 [ V_76 ] . V_70 = F_33 ( V_66 +
F_34 ( struct V_63 , V_75 [ 0 ] ) ) ;
V_64 -> V_77 [ V_78 ] . V_70 = F_33 ( V_66 +
F_34 ( struct V_63 , V_77 [ 0 ] ) ) ;
V_64 -> V_73 [ V_72 ] . V_70 = F_33 ( V_66 +
F_34 ( struct V_63 , V_73 [ 0 ] ) ) ;
V_64 -> V_79 = V_64 -> V_80 = V_64 -> V_81 = V_64 -> V_82 = 0 ;
V_64 -> V_83 = V_64 -> V_84 = V_64 -> V_85 = V_64 -> V_86 = 0 ;
V_64 -> V_87 = V_64 -> V_88 = V_64 -> V_89 = V_64 -> V_90 = 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
unsigned int V_91 , V_92 ;
T_1 V_93 ;
V_93 = V_94 | V_95 ;
if ( strncmp ( V_96 , L_8 , 3 ) == 0 )
V_93 |= V_97 ;
else
V_93 |= V_98 ;
if ( V_96 [ 3 ] != '\0' )
V_91 = F_36 ( V_96 + 3 , NULL , 10 ) ;
else {
V_91 = 66 ;
F_37 ( V_99 L_9
L_10 ,
V_91 , V_96 ) ;
}
V_92 = V_100 / V_91 ;
V_93 |= ( V_92 / 2 - 1 ) << V_101 ;
if ( V_92 <= 8 )
V_93 |= V_102 ;
else
V_93 |= V_103 ;
F_7 ( V_2 , V_94 , V_93 |
V_104 | V_105 | V_106 ) ;
F_14 ( 10 ) ;
F_7 ( V_2 , V_94 , V_93 |
V_104 | V_105 ) ;
F_7 ( V_2 , V_94 , V_93 |
V_107 | V_108 ) ;
V_2 -> V_38 = 1000000 * ( V_91 + 1 ) * V_92 / 2 ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_66 = V_2 -> V_67 ;
F_4 ( V_2 , V_9 , V_12 ) ;
F_4 ( V_2 , V_109 , V_110 ) ;
F_4 ( V_2 , V_18 , V_111 ) ;
F_7 ( V_2 , V_112 , V_66 +
F_34 ( struct V_63 , V_69 [ 0 ] ) ) ;
F_7 ( V_2 , V_113 , V_66 +
F_34 ( struct V_63 , V_75 [ 0 ] ) ) ;
F_7 ( V_2 , V_114 , V_66 +
F_34 ( struct V_63 , V_77 [ 0 ] ) ) ;
F_7 ( V_2 , V_115 , V_66 +
F_34 ( struct V_63 , V_73 [ 0 ] ) ) ;
F_14 ( 2 ) ;
#if 0
hifn_write_1(dev, HIFN_1_DMA_CSR,
HIFN_DMACSR_D_CTRL_DIS | HIFN_DMACSR_R_CTRL_DIS |
HIFN_DMACSR_S_CTRL_DIS | HIFN_DMACSR_C_CTRL_DIS |
HIFN_DMACSR_D_ABORT | HIFN_DMACSR_D_DONE | HIFN_DMACSR_D_LAST |
HIFN_DMACSR_D_WAIT | HIFN_DMACSR_D_OVER |
HIFN_DMACSR_R_ABORT | HIFN_DMACSR_R_DONE | HIFN_DMACSR_R_LAST |
HIFN_DMACSR_R_WAIT | HIFN_DMACSR_R_OVER |
HIFN_DMACSR_S_ABORT | HIFN_DMACSR_S_DONE | HIFN_DMACSR_S_LAST |
HIFN_DMACSR_S_WAIT |
HIFN_DMACSR_C_ABORT | HIFN_DMACSR_C_DONE | HIFN_DMACSR_C_LAST |
HIFN_DMACSR_C_WAIT |
HIFN_DMACSR_ENGINE |
HIFN_DMACSR_PUBDONE);
#else
F_7 ( V_2 , V_13 ,
V_116 | V_117 |
V_118 | V_119 |
V_120 | V_121 | V_122 |
V_123 | V_124 |
V_125 | V_126 | V_127 |
V_128 | V_129 |
V_130 | V_131 | V_132 |
V_133 |
V_134 | V_135 | V_136 |
V_137 |
V_138 |
V_139 ) ;
#endif
F_3 ( V_2 , V_13 ) ;
V_2 -> V_45 |= V_140 | V_141 |
V_142 | V_143 |
V_144 | V_145 | V_146 |
V_147 ;
V_2 -> V_45 &= ~ V_148 ;
F_7 ( V_2 , V_19 , V_2 -> V_45 ) ;
F_3 ( V_2 , V_19 ) ;
#if 0
hifn_write_0(dev, HIFN_0_PUCNFG, HIFN_PUCNFG_ENCCNFG |
HIFN_PUCNFG_DRFR_128 | HIFN_PUCNFG_TCALLPHASES |
HIFN_PUCNFG_TCDRVTOTEM | HIFN_PUCNFG_BUS32 |
HIFN_PUCNFG_DRAM);
#else
F_4 ( V_2 , V_149 , 0x10342 ) ;
#endif
F_35 ( V_2 ) ;
F_4 ( V_2 , V_150 , V_151 ) ;
F_7 ( V_2 , V_21 , V_22 |
V_23 | V_24 | V_152 |
( ( V_153 << 16 ) & V_154 ) |
( ( V_155 << 8 ) & V_156 ) ) ;
}
static int F_39 ( struct V_1 * V_2 , T_5 * V_157 ,
unsigned V_158 , unsigned V_159 , T_6 V_160 , T_5 V_161 )
{
struct V_162 * V_163 ;
T_5 * V_164 = V_157 ;
V_163 = (struct V_162 * ) V_164 ;
V_163 -> V_165 = F_40 ( V_160 ) ;
V_163 -> V_166 =
F_40 ( V_159 & V_167 ) ;
V_163 -> V_168 =
F_40 ( V_158 & V_167 ) ;
V_158 >>= 16 ;
V_159 >>= 16 ;
V_163 -> V_169 = F_40 ( V_161 |
( ( V_159 << V_170 ) & V_171 ) |
( ( V_158 << V_172 ) & V_173 ) ) ;
return sizeof( struct V_162 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
T_5 * V_157 , unsigned V_158 , unsigned V_159 ,
T_5 * V_174 , int V_175 , T_5 * V_176 , int V_177 , T_6 V_178 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
struct V_179 * V_180 ;
T_5 * V_164 = V_157 ;
T_6 V_181 ;
V_180 = (struct V_179 * ) V_164 ;
V_180 -> V_182 = F_40 ( V_158 & 0xffff ) ;
V_158 >>= 16 ;
V_180 -> V_165 = F_40 ( V_178 |
( ( V_158 << V_183 ) &
V_184 ) ) ;
V_180 -> V_185 = 0 ;
V_180 -> V_186 = 0 ;
V_164 += sizeof( struct V_179 ) ;
V_64 -> V_79 ++ ;
if ( V_64 -> V_79 > 1 ) {
V_2 -> V_45 |= V_148 ;
F_7 ( V_2 , V_19 , V_2 -> V_45 ) ;
}
if ( V_175 ) {
memcpy ( V_164 , V_174 , V_175 ) ;
V_164 += V_175 ;
}
if ( V_177 ) {
memcpy ( V_164 , V_176 , V_177 ) ;
V_164 += V_177 ;
}
V_181 = V_164 - V_157 ;
return V_181 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_187 * V_188 , struct V_189 * V_190 ,
void * V_31 , unsigned int V_191 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_181 , V_192 ;
T_5 * V_157 , * V_164 ;
T_6 V_160 ;
V_192 = V_64 -> V_83 ;
V_164 = V_157 = V_64 -> V_71 [ V_64 -> V_83 ] ;
V_160 = 0 ;
switch ( V_190 -> V_193 ) {
case V_194 :
V_160 = V_195 | V_196 ;
break;
case V_197 :
V_160 = V_195 ;
break;
case V_198 :
V_160 = V_199 ;
break;
default:
goto V_200;
}
V_164 += F_39 ( V_2 , V_164 , V_191 ,
V_191 , V_160 , V_2 -> V_161 ) ;
if ( V_190 -> V_193 == V_197 || V_190 -> V_193 == V_194 ) {
T_6 V_201 = 0 ;
if ( V_188 -> V_202 )
V_201 |= V_203 ;
if ( V_190 -> V_176 && V_190 -> V_178 != V_204 )
V_201 |= V_205 ;
switch ( V_190 -> V_178 ) {
case V_204 :
V_201 |= V_206 ;
break;
case V_207 :
V_201 |= V_208 ;
break;
case V_209 :
V_201 |= V_210 ;
break;
case V_211 :
V_201 |= V_212 ;
break;
default:
goto V_200;
}
switch ( V_190 -> type ) {
case V_213 :
if ( V_188 -> V_202 != 16 )
goto V_200;
V_201 |= V_214 |
V_215 ;
break;
case V_216 :
if ( V_188 -> V_202 != 24 )
goto V_200;
V_201 |= V_217 |
V_215 ;
break;
case V_218 :
if ( V_188 -> V_202 != 32 )
goto V_200;
V_201 |= V_219 |
V_215 ;
break;
case V_220 :
if ( V_188 -> V_202 != 24 )
goto V_200;
V_201 |= V_221 ;
break;
case V_222 :
if ( V_188 -> V_202 != 8 )
goto V_200;
V_201 |= V_223 ;
break;
default:
goto V_200;
}
V_164 += F_41 ( V_2 , V_164 ,
V_191 , V_191 , V_188 -> V_174 , V_188 -> V_202 ,
V_190 -> V_176 , V_190 -> V_177 , V_201 ) ;
}
V_2 -> V_224 [ V_192 ] = V_31 ;
V_2 -> V_225 ++ ;
V_181 = V_164 - V_157 ;
V_64 -> V_69 [ V_64 -> V_83 ] . V_226 = F_33 ( V_181 | V_227 |
V_228 | V_229 ) ;
if ( ++ V_64 -> V_83 == V_68 ) {
V_64 -> V_69 [ V_64 -> V_83 ] . V_226 = F_33 (
V_227 | V_228 |
V_229 | V_230 ) ;
V_64 -> V_83 = 0 ;
} else
V_64 -> V_69 [ V_64 -> V_83 - 1 ] . V_226 |= F_33 ( V_227 ) ;
if ( ! ( V_2 -> V_231 & V_232 ) ) {
F_7 ( V_2 , V_13 , V_116 ) ;
V_2 -> V_231 |= V_232 ;
}
return 0 ;
V_200:
return - V_233 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_234 * V_234 ,
unsigned int V_235 , unsigned int V_236 , int V_237 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_238 ;
T_7 V_50 ;
V_50 = F_44 ( V_2 -> V_54 , V_234 , V_235 , V_236 , V_239 ) ;
V_238 = V_64 -> V_84 ;
V_64 -> V_75 [ V_238 ] . V_70 = F_33 ( V_50 ) ;
V_64 -> V_75 [ V_238 ] . V_226 = F_33 ( V_236 | V_227 |
V_229 | ( V_237 ? V_228 : 0 ) ) ;
if ( ++ V_238 == V_76 ) {
V_64 -> V_75 [ V_238 ] . V_226 = F_33 ( V_227 |
V_230 | V_229 |
( V_237 ? V_228 : 0 ) ) ;
V_238 = 0 ;
}
V_64 -> V_84 = V_238 ;
V_64 -> V_80 ++ ;
if ( ! ( V_2 -> V_231 & V_240 ) ) {
F_7 ( V_2 , V_13 , V_117 ) ;
V_2 -> V_231 |= V_240 ;
}
return V_236 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
V_64 -> V_73 [ V_64 -> V_86 ] . V_226 = F_33 ( V_241 |
V_227 | V_228 ) ;
if ( ++ V_64 -> V_86 == V_72 ) {
V_64 -> V_73 [ V_72 ] . V_226 = F_33 ( V_227 |
V_230 | V_229 | V_228 ) ;
V_64 -> V_86 = 0 ;
}
V_64 -> V_82 ++ ;
if ( ! ( V_2 -> V_231 & V_242 ) ) {
F_7 ( V_2 , V_13 , V_119 ) ;
V_2 -> V_231 |= V_242 ;
}
}
static void F_46 ( struct V_1 * V_2 , struct V_234 * V_234 ,
unsigned V_235 , unsigned V_236 , int V_237 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_238 ;
T_7 V_50 ;
V_50 = F_44 ( V_2 -> V_54 , V_234 , V_235 , V_236 , V_243 ) ;
V_238 = V_64 -> V_85 ;
V_64 -> V_77 [ V_238 ] . V_70 = F_33 ( V_50 ) ;
V_64 -> V_77 [ V_238 ] . V_226 = F_33 ( V_236 | V_227 |
V_229 | ( V_237 ? V_228 : 0 ) ) ;
if ( ++ V_238 == V_78 ) {
V_64 -> V_77 [ V_238 ] . V_226 = F_33 ( V_227 |
V_230 | V_229 |
( V_237 ? V_228 : 0 ) ) ;
V_238 = 0 ;
}
V_64 -> V_85 = V_238 ;
V_64 -> V_81 ++ ;
if ( ! ( V_2 -> V_231 & V_244 ) ) {
F_7 ( V_2 , V_13 , V_118 ) ;
V_2 -> V_231 |= V_244 ;
}
}
static int F_47 ( struct V_1 * V_2 ,
struct V_187 * V_188 , struct V_189 * V_190 ,
struct V_245 * V_246 , struct V_245 * V_247 ,
unsigned int V_191 , void * V_31 )
{
struct V_245 * V_248 ;
struct V_234 * V_249 , * V_250 ;
unsigned int V_251 , V_252 ;
unsigned int V_253 , V_254 ;
V_253 = V_191 ;
while ( V_253 ) {
V_249 = F_48 ( V_246 ) ;
V_251 = V_246 -> V_235 ;
V_254 = F_49 ( V_246 -> V_255 , V_253 ) ;
F_43 ( V_2 , V_249 , V_251 , V_254 , V_253 - V_254 == 0 ) ;
V_246 ++ ;
V_253 -= V_254 ;
}
V_248 = & V_190 -> V_256 . V_257 [ 0 ] ;
V_253 = V_191 ;
while ( V_253 ) {
if ( V_248 -> V_255 && V_190 -> V_256 . V_231 & V_258 ) {
F_50 ( ! F_48 ( V_248 ) ) ;
V_250 = F_48 ( V_248 ) ;
V_252 = 0 ;
V_254 = V_248 -> V_255 ;
} else {
F_50 ( ! F_48 ( V_247 ) ) ;
V_250 = F_48 ( V_247 ) ;
V_252 = V_247 -> V_235 ;
V_254 = V_247 -> V_255 ;
}
V_254 = F_49 ( V_254 , V_253 ) ;
F_46 ( V_2 , V_250 , V_252 , V_254 , V_253 - V_254 == 0 ) ;
V_247 ++ ;
V_248 ++ ;
V_253 -= V_254 ;
}
F_42 ( V_2 , V_188 , V_190 , V_31 , V_191 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_259 * V_260 ,
int V_261 , T_8 V_262 )
{
int V_8 ;
V_261 = F_49 ( V_263 , V_261 ) ;
F_52 ( V_260 -> V_257 , V_261 ) ;
V_260 -> V_261 = 0 ;
for ( V_8 = 0 ; V_8 < V_261 ; ++ V_8 ) {
struct V_234 * V_234 = F_53 ( V_262 ) ;
struct V_245 * V_264 ;
if ( ! V_234 )
break;
V_264 = & V_260 -> V_257 [ V_8 ] ;
F_54 ( V_264 , V_234 , V_265 , 0 ) ;
V_260 -> V_261 ++ ;
}
return V_8 ;
}
static void F_55 ( struct V_259 * V_260 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_260 -> V_261 ; ++ V_8 ) {
struct V_245 * V_264 = & V_260 -> V_257 [ V_8 ] ;
F_56 ( F_48 ( V_264 ) ) ;
V_264 -> V_255 = 0 ;
}
V_260 -> V_261 = 0 ;
}
static int F_57 ( unsigned int * V_266 , struct V_245 * V_247 ,
unsigned int V_236 , unsigned int * V_267 )
{
unsigned int V_268 , V_269 = * V_266 , V_191 = * V_267 ;
int V_238 = 0 ;
if ( V_269 < V_236 || V_236 > V_191 )
return - V_233 ;
while ( V_236 ) {
V_268 = F_58 ( V_269 , V_236 , V_247 -> V_255 ) ;
V_236 -= V_268 ;
V_269 -= V_268 ;
V_191 -= V_268 ;
F_10 ( L_11 ,
V_270 , V_268 , V_236 , V_269 , V_191 ) ;
V_247 ++ ;
V_238 ++ ;
}
* V_267 = V_191 ;
* V_266 = V_269 ;
return V_238 ;
}
static int V_259 ( struct V_271 * V_272 ,
struct V_259 * V_260 )
{
struct V_245 * V_247 , * V_248 ;
unsigned int V_191 = V_272 -> V_191 , V_235 , V_268 , V_273 ;
int V_238 , V_274 , V_275 ;
V_274 = V_238 = 0 ;
V_235 = 0 ;
while ( V_191 ) {
if ( V_238 >= V_260 -> V_261 && ( V_260 -> V_231 & V_258 ) )
return - V_233 ;
V_247 = & V_272 -> V_247 [ V_238 ] ;
F_10 ( L_12 ,
V_270 , V_247 -> V_255 , V_247 -> V_235 , V_235 , V_191 ) ;
if ( ! F_59 ( V_247 -> V_235 , V_276 ) ||
! F_59 ( V_247 -> V_255 , V_276 ) ||
V_235 ) {
unsigned V_159 = F_49 ( V_247 -> V_255 - V_235 , V_191 ) ;
unsigned V_158 = V_265 ;
V_248 = & V_260 -> V_257 [ V_238 ] ;
V_275 = F_57 ( & V_158 , V_247 , V_159 , & V_191 ) ;
if ( V_275 < 0 )
return V_275 ;
V_238 += V_275 ;
V_268 = V_159 & ~ ( V_276 - 1 ) ;
V_273 = V_159 & ( V_276 - 1 ) ;
if ( V_158 < V_191 ) {
V_191 += V_273 ;
F_37 ( V_277 L_13
L_14 ,
V_270 , V_158 , V_191 , V_159 , V_235 ) ;
F_37 ( V_277 L_15
L_16
L_17
L_18
L_19 , V_270 ) ;
F_60 () ;
} else {
V_268 += V_273 + V_191 ;
V_247 = & V_272 -> V_247 [ V_238 ] ;
V_275 = F_57 ( & V_158 , V_247 , V_191 , & V_191 ) ;
if ( V_275 < 0 )
return V_275 ;
V_238 += V_275 ;
}
V_248 -> V_255 = V_268 ;
V_248 -> V_235 = V_235 ;
} else {
V_191 -= F_49 ( V_247 -> V_255 , V_191 ) ;
V_238 ++ ;
}
V_274 ++ ;
}
return V_274 ;
}
static int F_61 ( struct V_271 * V_272 )
{
struct V_187 * V_188 = F_62 ( V_272 -> V_278 . V_279 ) ;
struct V_189 * V_190 = F_63 ( V_272 ) ;
struct V_1 * V_2 = V_188 -> V_2 ;
unsigned long V_158 , V_231 ;
unsigned int V_191 = V_272 -> V_191 , V_238 = 0 ;
int V_275 = - V_233 , V_280 ;
struct V_245 * V_247 ;
if ( V_190 -> V_176 && ! V_190 -> V_177 && V_190 -> V_178 != V_204 )
goto V_281;
V_190 -> V_256 . V_231 = 0 ;
while ( V_191 ) {
V_247 = & V_272 -> V_247 [ V_238 ] ;
V_158 = F_49 ( V_247 -> V_255 , V_191 ) ;
if ( ! F_59 ( V_247 -> V_235 , V_276 ) ||
! F_59 ( V_158 , V_276 ) )
V_190 -> V_256 . V_231 |= V_258 ;
V_191 -= V_158 ;
V_238 ++ ;
}
if ( V_190 -> V_256 . V_231 & V_258 ) {
V_275 = F_51 ( & V_190 -> V_256 , V_238 , V_282 ) ;
if ( V_275 < 0 )
return V_275 ;
}
V_280 = V_259 ( V_272 , & V_190 -> V_256 ) ;
if ( V_280 < 0 ) {
V_275 = V_280 ;
goto V_281;
}
F_64 ( & V_2 -> V_283 , V_231 ) ;
if ( V_2 -> V_225 + V_280 > V_284 ) {
V_275 = - V_285 ;
goto V_200;
}
V_275 = F_47 ( V_2 , V_188 , V_190 , V_272 -> V_246 , V_272 -> V_247 , V_272 -> V_191 , V_272 ) ;
if ( V_275 )
goto V_200;
V_2 -> V_161 ++ ;
V_2 -> V_286 = V_287 ;
F_65 ( & V_2 -> V_283 , V_231 ) ;
return 0 ;
V_200:
F_65 ( & V_2 -> V_283 , V_231 ) ;
V_281:
if ( V_275 ) {
F_37 ( L_20
L_21 ,
V_2 -> V_11 , V_190 -> V_176 , V_190 -> V_177 ,
V_188 -> V_174 , V_188 -> V_202 ,
V_190 -> V_178 , V_190 -> V_193 , V_190 -> type , V_275 ) ;
}
return V_275 ;
}
static int F_66 ( struct V_1 * V_2 , int V_288 , T_5 V_161 )
{
int V_253 , V_275 ;
T_5 V_246 [ 16 ] ;
struct V_187 V_188 ;
struct V_189 V_190 ;
T_5 V_289 [ 16 ] = {
0x66 , 0xE9 , 0x4B , 0xD4 ,
0xEF , 0x8A , 0x2C , 0x3B ,
0x88 , 0x4C , 0xFA , 0x59 ,
0xCA , 0x34 , 0x2B , 0x2E } ;
struct V_245 V_290 ;
memset ( V_246 , 0 , sizeof( V_246 ) ) ;
memset ( V_188 . V_174 , 0 , sizeof( V_188 . V_174 ) ) ;
V_188 . V_2 = V_2 ;
V_188 . V_202 = 16 ;
V_190 . V_177 = 0 ;
V_190 . V_176 = NULL ;
V_190 . V_193 = ( V_288 ) ? V_197 : V_194 ;
V_190 . V_178 = V_204 ;
V_190 . type = V_213 ;
V_190 . V_256 . V_257 [ 0 ] . V_255 = 0 ;
F_67 ( & V_290 , & V_246 , sizeof( V_246 ) ) ;
V_275 = F_47 ( V_2 , & V_188 , & V_190 , & V_290 , & V_290 , sizeof( V_246 ) , NULL ) ;
if ( V_275 )
goto V_200;
V_2 -> V_225 = 0 ;
F_68 ( 200 ) ;
F_10 ( L_22 , V_2 -> V_11 ) ;
for ( V_253 = 0 ; V_253 < sizeof( V_246 ) ; ++ V_253 )
F_10 ( L_23 , V_246 [ V_253 ] ) ;
F_10 ( L_24 ) ;
F_10 ( L_25 , V_2 -> V_11 ) ;
for ( V_253 = 0 ; V_253 < sizeof( V_289 ) ; ++ V_253 )
F_10 ( L_23 , V_289 [ V_253 ] ) ;
F_10 ( L_24 ) ;
if ( ! memcmp ( V_246 , V_289 , sizeof( V_289 ) ) ) {
F_37 ( V_99 L_26
L_27 , V_2 -> V_11 ) ;
return 0 ;
}
V_200:
F_37 ( V_99 L_28 , V_2 -> V_11 ) ;
return - 1 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_275 ;
V_2 -> V_225 = V_2 -> V_286 = 0 ;
F_13 ( V_2 , 1 ) ;
V_275 = F_29 ( V_2 ) ;
if ( V_275 )
return V_275 ;
F_11 ( V_2 ) ;
F_32 ( V_2 ) ;
F_38 ( V_2 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int F_70 ( void * V_291 , unsigned int * V_292 , unsigned int V_235 ,
struct V_245 * V_247 , unsigned int V_236 , unsigned int * V_267 )
{
unsigned int V_293 = * V_292 , V_191 = * V_267 , V_268 ;
void * V_294 ;
int V_238 = 0 ;
if ( V_293 < V_236 || V_236 > V_191 )
return - V_233 ;
while ( V_236 ) {
V_268 = F_58 ( V_293 , V_247 -> V_255 , V_236 ) ;
V_294 = F_71 ( F_48 ( V_247 ) ) ;
memcpy ( V_294 + V_247 -> V_235 + V_235 , V_291 , V_268 ) ;
F_72 ( V_294 ) ;
V_191 -= V_268 ;
V_236 -= V_268 ;
V_293 -= V_268 ;
V_291 += V_268 ;
V_235 = 0 ;
F_10 ( L_29 ,
V_270 , V_268 , V_236 , V_293 , V_191 ) ;
V_247 ++ ;
V_238 ++ ;
}
* V_267 = V_191 ;
* V_292 = V_293 ;
return V_238 ;
}
static inline void F_73 ( struct V_1 * V_2 , int V_8 )
{
unsigned long V_231 ;
F_64 ( & V_2 -> V_283 , V_231 ) ;
V_2 -> V_224 [ V_8 ] = NULL ;
V_2 -> V_225 -- ;
if ( V_2 -> V_225 < 0 )
F_37 ( L_30 , V_270 , V_2 -> V_225 ) ;
F_65 ( & V_2 -> V_283 , V_231 ) ;
F_50 ( V_2 -> V_225 < 0 ) ;
}
static void F_74 ( struct V_271 * V_272 , int error )
{
struct V_189 * V_190 = F_63 ( V_272 ) ;
if ( V_190 -> V_256 . V_231 & V_258 ) {
unsigned int V_191 = V_272 -> V_191 ;
int V_238 = 0 , V_275 ;
struct V_245 * V_247 , * V_248 ;
void * V_291 ;
while ( V_191 ) {
V_248 = & V_190 -> V_256 . V_257 [ V_238 ] ;
V_247 = & V_272 -> V_247 [ V_238 ] ;
F_10 ( L_31
L_32
L_33 ,
V_270 , F_48 ( V_248 ) , V_248 -> V_255 ,
F_48 ( V_247 ) , V_247 -> V_255 , V_191 ) ;
if ( ! V_248 -> V_255 ) {
V_191 -= F_49 ( V_247 -> V_255 , V_191 ) ;
V_238 ++ ;
continue;
}
V_291 = F_71 ( F_48 ( V_248 ) ) ;
V_275 = F_70 ( V_291 , & V_248 -> V_255 , V_248 -> V_235 ,
V_247 , V_191 , & V_191 ) ;
if ( V_275 < 0 ) {
F_72 ( V_291 ) ;
break;
}
V_238 += V_275 ;
F_72 ( V_291 ) ;
}
F_55 ( & V_190 -> V_256 ) ;
}
V_272 -> V_278 . V_295 ( & V_272 -> V_278 , error ) ;
}
static void F_75 ( struct V_1 * V_2 , int error )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_8 , V_296 ;
F_10 ( L_34
L_35 ,
V_2 -> V_11 ,
V_64 -> V_83 , V_64 -> V_84 , V_64 -> V_85 , V_64 -> V_86 ,
V_64 -> V_79 , V_64 -> V_80 , V_64 -> V_81 , V_64 -> V_82 ,
V_64 -> V_87 , V_64 -> V_88 , V_64 -> V_89 , V_64 -> V_90 ) ;
V_8 = V_64 -> V_90 ; V_296 = V_64 -> V_82 ;
while ( V_296 != 0 ) {
if ( V_64 -> V_73 [ V_8 ] . V_226 & F_33 ( V_227 ) )
break;
if ( V_2 -> V_224 [ V_8 ] ) {
V_2 -> V_297 ++ ;
V_2 -> V_298 = 0 ;
F_74 ( V_2 -> V_224 [ V_8 ] , error ) ;
F_73 ( V_2 , V_8 ) ;
}
if ( ++ V_8 == V_72 )
V_8 = 0 ;
V_296 -- ;
}
V_64 -> V_90 = V_8 ; V_64 -> V_82 = V_296 ;
V_8 = V_64 -> V_88 ; V_296 = V_64 -> V_80 ;
while ( V_296 != 0 ) {
if ( V_64 -> V_75 [ V_8 ] . V_226 & F_33 ( V_227 ) )
break;
if ( ++ V_8 == V_76 )
V_8 = 0 ;
V_296 -- ;
}
V_64 -> V_88 = V_8 ; V_64 -> V_80 = V_296 ;
V_8 = V_64 -> V_87 ; V_296 = V_64 -> V_79 ;
while ( V_296 != 0 ) {
if ( V_64 -> V_69 [ V_8 ] . V_226 & F_33 ( V_227 ) )
break;
if ( ++ V_8 == V_68 )
V_8 = 0 ;
V_296 -- ;
}
V_64 -> V_87 = V_8 ; V_64 -> V_79 = V_296 ;
V_8 = V_64 -> V_89 ; V_296 = V_64 -> V_81 ;
while ( V_296 != 0 ) {
if ( V_64 -> V_77 [ V_8 ] . V_226 & F_33 ( V_227 ) )
break;
if ( ++ V_8 == V_78 )
V_8 = 0 ;
V_296 -- ;
}
V_64 -> V_89 = V_8 ; V_64 -> V_81 = V_296 ;
F_10 ( L_36
L_35 ,
V_2 -> V_11 ,
V_64 -> V_83 , V_64 -> V_84 , V_64 -> V_85 , V_64 -> V_86 ,
V_64 -> V_79 , V_64 -> V_80 , V_64 -> V_81 , V_64 -> V_82 ,
V_64 -> V_87 , V_64 -> V_88 , V_64 -> V_89 , V_64 -> V_90 ) ;
}
static void F_76 ( struct V_299 * V_300 )
{
struct V_301 * V_302 = F_77 ( V_300 ) ;
struct V_1 * V_2 = F_78 ( V_302 , struct V_1 , V_300 ) ;
unsigned long V_231 ;
int V_298 = 0 ;
T_1 V_303 = 0 ;
F_64 ( & V_2 -> V_283 , V_231 ) ;
if ( V_2 -> V_286 == 0 ) {
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
if ( V_64 -> V_79 == 0 && ( V_2 -> V_231 & V_232 ) ) {
V_2 -> V_231 &= ~ V_232 ;
V_303 |= V_17 ;
}
if ( V_64 -> V_80 == 0 && ( V_2 -> V_231 & V_240 ) ) {
V_2 -> V_231 &= ~ V_240 ;
V_303 |= V_16 ;
}
if ( V_64 -> V_81 == 0 && ( V_2 -> V_231 & V_244 ) ) {
V_2 -> V_231 &= ~ V_244 ;
V_303 |= V_14 ;
}
if ( V_64 -> V_82 == 0 && ( V_2 -> V_231 & V_242 ) ) {
V_2 -> V_231 &= ~ V_242 ;
V_303 |= V_15 ;
}
if ( V_303 )
F_7 ( V_2 , V_13 , V_303 ) ;
} else
V_2 -> V_286 -- ;
if ( ( V_2 -> V_304 == V_2 -> V_297 ) && V_2 -> V_225 )
V_298 = 1 ;
V_2 -> V_304 = V_2 -> V_297 ;
F_65 ( & V_2 -> V_283 , V_231 ) ;
if ( V_298 ) {
if ( ++ V_2 -> V_298 >= 5 ) {
int V_8 ;
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
F_37 ( L_37
L_38 ,
V_2 -> V_11 , V_303 , V_2 -> V_286 , V_2 -> V_225 ,
V_2 -> V_297 , V_2 -> V_305 . V_306 , V_2 -> V_305 . V_307 ,
V_298 ) ;
F_37 ( L_39 , V_270 ) ;
for ( V_8 = 0 ; V_8 < V_72 ; ++ V_8 ) {
F_37 ( L_40 , V_64 -> V_73 [ V_8 ] . V_226 , V_2 -> V_224 [ V_8 ] ) ;
if ( V_2 -> V_224 [ V_8 ] ) {
F_74 ( V_2 -> V_224 [ V_8 ] , - V_59 ) ;
F_73 ( V_2 , V_8 ) ;
}
}
F_37 ( L_24 ) ;
F_13 ( V_2 , 1 ) ;
F_12 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_298 = 0 ;
}
F_79 ( & V_2 -> V_308 ) ;
}
F_80 ( & V_2 -> V_300 , V_309 ) ;
}
static T_9 F_81 ( int V_310 , void * V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 ;
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
T_1 V_311 , V_312 ;
V_311 = F_3 ( V_2 , V_13 ) ;
F_10 ( L_41
L_42 ,
V_2 -> V_11 , V_311 , V_2 -> V_45 , V_311 & V_2 -> V_45 , V_64 -> V_83 ,
V_64 -> V_83 , V_64 -> V_84 , V_64 -> V_85 , V_64 -> V_86 ,
V_64 -> V_79 , V_64 -> V_80 , V_64 -> V_81 , V_64 -> V_82 ) ;
if ( ( V_311 & V_2 -> V_45 ) == 0 )
return V_313 ;
F_7 ( V_2 , V_13 , V_311 & V_2 -> V_45 ) ;
if ( V_311 & V_138 )
F_4 ( V_2 , V_150 , F_1 ( V_2 , V_150 ) ) ;
if ( V_311 & V_139 )
F_7 ( V_2 , V_314 ,
F_3 ( V_2 , V_314 ) | V_315 ) ;
V_312 = V_311 & ( V_129 | V_124 ) ;
if ( V_312 ) {
T_1 V_316 = F_1 ( V_2 , V_150 ) ;
F_37 ( V_317 L_43 ,
V_2 -> V_11 , ! ! ( V_311 & V_129 ) ,
! ! ( V_311 & V_124 ) ,
V_316 , ! ! ( V_316 & V_151 ) ) ;
if ( ! ! ( V_316 & V_151 ) )
F_4 ( V_2 , V_150 , V_151 ) ;
F_7 ( V_2 , V_13 , V_311 & ( V_129 |
V_124 ) ) ;
}
V_312 = V_311 & ( V_134 | V_130 |
V_120 | V_125 ) ;
if ( V_312 ) {
F_37 ( V_317 L_44 ,
V_2 -> V_11 , ! ! ( V_311 & V_134 ) ,
! ! ( V_311 & V_130 ) ,
! ! ( V_311 & V_120 ) ,
! ! ( V_311 & V_125 ) ) ;
F_13 ( V_2 , 1 ) ;
F_32 ( V_2 ) ;
F_38 ( V_2 ) ;
}
if ( ( V_311 & V_137 ) && ( V_64 -> V_79 == 0 ) ) {
F_10 ( L_45 , V_2 -> V_11 ) ;
V_2 -> V_45 &= ~ ( V_148 ) ;
F_7 ( V_2 , V_19 , V_2 -> V_45 ) ;
}
F_79 ( & V_2 -> V_308 ) ;
return V_318 ;
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned long V_231 ;
struct V_319 * V_320 ;
struct V_271 * V_272 ;
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_72 ; ++ V_8 ) {
struct V_321 * V_322 = & V_64 -> V_73 [ V_8 ] ;
if ( V_2 -> V_224 [ V_8 ] ) {
F_74 ( V_2 -> V_224 [ V_8 ] ,
( V_322 -> V_226 & F_33 ( V_227 ) ) ? - V_59 : 0 ) ;
F_73 ( V_2 , V_8 ) ;
}
}
F_64 ( & V_2 -> V_283 , V_231 ) ;
while ( ( V_320 = F_83 ( & V_2 -> V_305 ) ) ) {
V_272 = F_78 ( V_320 , struct V_271 , V_278 ) ;
F_65 ( & V_2 -> V_283 , V_231 ) ;
F_74 ( V_272 , - V_59 ) ;
F_64 ( & V_2 -> V_283 , V_231 ) ;
}
F_65 ( & V_2 -> V_283 , V_231 ) ;
}
static int F_84 ( struct V_323 * V_324 , const T_5 * V_174 ,
unsigned int V_254 )
{
struct V_325 * V_279 = F_85 ( V_324 ) ;
struct V_187 * V_188 = F_62 ( V_279 ) ;
struct V_1 * V_2 = V_188 -> V_2 ;
if ( V_254 > V_326 ) {
F_86 ( V_324 , V_327 ) ;
return - 1 ;
}
if ( V_254 == V_328 ) {
T_1 V_329 [ V_330 ] ;
int V_4 = F_87 ( V_329 , V_174 ) ;
if ( F_88 ( V_4 == 0 ) && ( V_279 -> V_331 & V_332 ) ) {
V_279 -> V_331 |= V_333 ;
return - V_233 ;
}
}
V_2 -> V_231 &= ~ V_334 ;
memcpy ( V_188 -> V_174 , V_174 , V_254 ) ;
V_188 -> V_202 = V_254 ;
return 0 ;
}
static int F_89 ( struct V_271 * V_272 )
{
struct V_187 * V_188 = F_62 ( V_272 -> V_278 . V_279 ) ;
struct V_1 * V_2 = V_188 -> V_2 ;
int V_275 = - V_285 ;
if ( V_2 -> V_225 + F_90 ( V_272 -> V_191 , V_265 ) <= V_284 )
V_275 = F_61 ( V_272 ) ;
if ( V_275 == - V_285 ) {
unsigned long V_231 ;
F_64 ( & V_2 -> V_283 , V_231 ) ;
V_275 = F_91 ( & V_2 -> V_305 , V_272 ) ;
F_65 ( & V_2 -> V_283 , V_231 ) ;
}
return V_275 ;
}
static int F_92 ( struct V_271 * V_272 , T_5 V_193 ,
T_5 type , T_5 V_178 )
{
struct V_187 * V_188 = F_62 ( V_272 -> V_278 . V_279 ) ;
struct V_189 * V_190 = F_63 ( V_272 ) ;
unsigned V_177 ;
V_177 = F_93 ( F_94 ( V_272 ) ) ;
if ( V_272 -> V_335 && V_178 != V_204 ) {
if ( type == V_213 )
V_177 = V_336 ;
else if ( type == V_222 )
V_177 = V_328 ;
else if ( type == V_220 )
V_177 = V_337 ;
}
if ( V_188 -> V_202 != 16 && type == V_213 ) {
if ( V_188 -> V_202 == 24 )
type = V_216 ;
else if ( V_188 -> V_202 == 32 )
type = V_218 ;
}
V_190 -> V_193 = V_193 ;
V_190 -> V_178 = V_178 ;
V_190 -> type = type ;
V_190 -> V_176 = V_272 -> V_335 ;
V_190 -> V_177 = V_177 ;
return F_89 ( V_272 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_319 * V_320 , * V_338 ;
struct V_271 * V_272 ;
unsigned long V_231 ;
int V_275 = 0 ;
while ( V_2 -> V_225 < V_284 ) {
F_64 ( & V_2 -> V_283 , V_231 ) ;
V_338 = F_96 ( & V_2 -> V_305 ) ;
V_320 = F_83 ( & V_2 -> V_305 ) ;
F_65 ( & V_2 -> V_283 , V_231 ) ;
if ( ! V_320 )
break;
if ( V_338 )
V_338 -> V_295 ( V_338 , - V_339 ) ;
V_272 = F_78 ( V_320 , struct V_271 , V_278 ) ;
V_275 = F_89 ( V_272 ) ;
if ( V_275 )
break;
}
return V_275 ;
}
static int F_97 ( struct V_271 * V_272 , T_5 V_193 ,
T_5 type , T_5 V_178 )
{
int V_275 ;
struct V_187 * V_188 = F_62 ( V_272 -> V_278 . V_279 ) ;
struct V_1 * V_2 = V_188 -> V_2 ;
V_275 = F_92 ( V_272 , V_193 , type , V_178 ) ;
if ( V_275 )
return V_275 ;
if ( V_2 -> V_225 < V_284 && V_2 -> V_305 . V_306 )
F_95 ( V_2 ) ;
return - V_339 ;
}
static inline int F_98 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_213 , V_204 ) ;
}
static inline int F_99 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_213 , V_207 ) ;
}
static inline int F_100 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_213 , V_209 ) ;
}
static inline int F_101 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_213 , V_211 ) ;
}
static inline int F_102 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_213 , V_204 ) ;
}
static inline int F_103 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_213 , V_207 ) ;
}
static inline int F_104 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_213 , V_209 ) ;
}
static inline int F_105 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_213 , V_211 ) ;
}
static inline int F_106 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_222 , V_204 ) ;
}
static inline int F_107 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_222 , V_207 ) ;
}
static inline int F_108 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_222 , V_209 ) ;
}
static inline int F_109 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_222 , V_211 ) ;
}
static inline int F_110 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_222 , V_204 ) ;
}
static inline int F_111 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_222 , V_207 ) ;
}
static inline int F_112 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_222 , V_209 ) ;
}
static inline int F_113 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_222 , V_211 ) ;
}
static inline int F_114 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_220 , V_204 ) ;
}
static inline int F_115 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_220 , V_207 ) ;
}
static inline int F_116 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_220 , V_209 ) ;
}
static inline int F_117 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_197 ,
V_220 , V_211 ) ;
}
static inline int F_118 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_220 , V_204 ) ;
}
static inline int F_119 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_220 , V_207 ) ;
}
static inline int F_120 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_220 , V_209 ) ;
}
static inline int F_121 ( struct V_271 * V_272 )
{
return F_97 ( V_272 , V_194 ,
V_220 , V_211 ) ;
}
static int F_122 ( struct V_325 * V_279 )
{
struct V_340 * V_341 = V_279 -> V_342 ;
struct V_343 * V_344 = F_123 ( V_341 ) ;
struct V_187 * V_188 = F_62 ( V_279 ) ;
V_188 -> V_2 = V_344 -> V_2 ;
V_279 -> V_345 . V_346 = sizeof( struct V_189 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , struct V_347 * V_248 )
{
struct V_343 * V_341 ;
int V_275 ;
V_341 = F_125 ( sizeof( struct V_343 ) , V_348 ) ;
if ( ! V_341 )
return - V_349 ;
snprintf ( V_341 -> V_341 . V_350 , V_351 , L_46 , V_248 -> V_11 ) ;
snprintf ( V_341 -> V_341 . V_352 , V_351 , L_47 ,
V_248 -> V_353 , V_2 -> V_11 ) ;
V_341 -> V_341 . V_354 = 300 ;
V_341 -> V_341 . V_355 = V_356 |
V_357 | V_358 ;
V_341 -> V_341 . V_359 = V_248 -> V_360 ;
V_341 -> V_341 . V_361 = sizeof( struct V_187 ) ;
V_341 -> V_341 . V_362 = 0 ;
V_341 -> V_341 . V_363 = & V_364 ;
V_341 -> V_341 . V_365 = V_366 ;
V_341 -> V_341 . V_367 . V_368 = V_248 -> V_368 ;
V_341 -> V_341 . V_369 = F_122 ;
V_341 -> V_2 = V_2 ;
F_126 ( & V_341 -> V_370 , & V_2 -> V_371 ) ;
V_275 = F_127 ( & V_341 -> V_341 ) ;
if ( V_275 ) {
F_128 ( & V_341 -> V_370 ) ;
F_129 ( V_341 ) ;
}
return V_275 ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_343 * V_25 , * V_253 ;
F_131 (a, n, &dev->alg_list, entry) {
F_128 ( & V_25 -> V_370 ) ;
F_132 ( & V_25 -> V_341 ) ;
F_129 ( V_25 ) ;
}
}
static int F_133 ( struct V_1 * V_2 )
{
int V_8 , V_275 ;
for ( V_8 = 0 ; V_8 < F_30 ( V_372 ) ; ++ V_8 ) {
V_275 = F_124 ( V_2 , & V_372 [ V_8 ] ) ;
if ( V_275 )
goto V_281;
}
return 0 ;
V_281:
F_130 ( V_2 ) ;
return V_275 ;
}
static void F_134 ( unsigned long V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 ;
F_75 ( V_2 , 0 ) ;
if ( V_2 -> V_225 < V_284 && V_2 -> V_305 . V_306 )
F_95 ( V_2 ) ;
}
static int F_135 ( struct V_373 * V_54 , const struct V_374 * V_375 )
{
int V_275 , V_8 ;
struct V_1 * V_2 ;
char V_11 [ 8 ] ;
V_275 = F_136 ( V_54 ) ;
if ( V_275 )
return V_275 ;
F_137 ( V_54 ) ;
V_275 = F_138 ( V_54 , F_139 ( 32 ) ) ;
if ( V_275 )
goto V_376;
snprintf ( V_11 , sizeof( V_11 ) , L_48 ,
F_140 ( & V_377 ) - 1 ) ;
V_275 = F_141 ( V_54 , V_11 ) ;
if ( V_275 )
goto V_376;
if ( F_142 ( V_54 , 0 ) < V_378 ||
F_142 ( V_54 , 1 ) < V_379 ||
F_142 ( V_54 , 2 ) < V_380 ) {
F_10 ( L_49 ,
F_31 ( V_54 ) ) ;
V_275 = - V_59 ;
goto V_381;
}
V_2 = F_125 ( sizeof( struct V_1 ) + sizeof( struct V_340 ) ,
V_348 ) ;
if ( ! V_2 ) {
V_275 = - V_349 ;
goto V_381;
}
F_143 ( & V_2 -> V_371 ) ;
snprintf ( V_2 -> V_11 , sizeof( V_2 -> V_11 ) , L_46 , V_11 ) ;
F_144 ( & V_2 -> V_283 ) ;
for ( V_8 = 0 ; V_8 < 3 ; ++ V_8 ) {
unsigned long V_50 , V_236 ;
V_50 = F_145 ( V_54 , V_8 ) ;
V_236 = F_142 ( V_54 , V_8 ) ;
V_2 -> V_5 [ V_8 ] = F_146 ( V_50 , V_236 ) ;
if ( ! V_2 -> V_5 [ V_8 ] ) {
V_275 = - V_349 ;
goto V_382;
}
}
V_2 -> V_65 = F_147 ( V_54 , sizeof( struct V_63 ) ,
& V_2 -> V_67 ) ;
if ( ! V_2 -> V_65 ) {
F_10 ( L_50 ) ;
V_275 = - V_349 ;
goto V_382;
}
memset ( V_2 -> V_65 , 0 , sizeof( struct V_63 ) ) ;
V_2 -> V_54 = V_54 ;
V_2 -> V_310 = V_54 -> V_310 ;
for ( V_8 = 0 ; V_8 < V_72 ; ++ V_8 )
V_2 -> V_224 [ V_8 ] = NULL ;
F_148 ( V_54 , V_2 ) ;
F_149 ( & V_2 -> V_308 , F_134 , ( unsigned long ) V_2 ) ;
F_150 ( & V_2 -> V_305 , 1 ) ;
V_275 = F_151 ( V_2 -> V_310 , F_81 , V_383 , V_2 -> V_11 , V_2 ) ;
if ( V_275 ) {
F_10 ( L_51 , V_2 -> V_310 , V_275 ) ;
V_2 -> V_310 = 0 ;
goto V_384;
}
V_275 = F_69 ( V_2 ) ;
if ( V_275 )
goto V_385;
V_275 = F_66 ( V_2 , 1 , 0 ) ;
if ( V_275 )
goto V_386;
V_275 = F_22 ( V_2 ) ;
if ( V_275 )
goto V_386;
V_275 = F_133 ( V_2 ) ;
if ( V_275 )
goto V_387;
F_152 ( & V_2 -> V_300 , F_76 ) ;
F_80 ( & V_2 -> V_300 , V_309 ) ;
F_10 ( L_52
L_53 ,
F_31 ( V_54 ) , V_2 -> V_11 ) ;
return 0 ;
V_387:
F_25 ( V_2 ) ;
V_386:
F_13 ( V_2 , 1 ) ;
F_12 ( V_2 ) ;
V_385:
F_153 ( V_2 -> V_310 , V_2 ) ;
F_154 ( & V_2 -> V_308 ) ;
V_384:
F_155 ( V_54 , sizeof( struct V_63 ) ,
V_2 -> V_65 , V_2 -> V_67 ) ;
V_382:
for ( V_8 = 0 ; V_8 < 3 ; ++ V_8 )
if ( V_2 -> V_5 [ V_8 ] )
F_156 ( V_2 -> V_5 [ V_8 ] ) ;
V_381:
F_157 ( V_54 ) ;
V_376:
F_158 ( V_54 ) ;
return V_275 ;
}
static void F_159 ( struct V_373 * V_54 )
{
int V_8 ;
struct V_1 * V_2 ;
V_2 = F_160 ( V_54 ) ;
if ( V_2 ) {
F_161 ( & V_2 -> V_300 ) ;
F_25 ( V_2 ) ;
F_130 ( V_2 ) ;
F_13 ( V_2 , 1 ) ;
F_12 ( V_2 ) ;
F_153 ( V_2 -> V_310 , V_2 ) ;
F_154 ( & V_2 -> V_308 ) ;
F_82 ( V_2 ) ;
F_155 ( V_54 , sizeof( struct V_63 ) ,
V_2 -> V_65 , V_2 -> V_67 ) ;
for ( V_8 = 0 ; V_8 < 3 ; ++ V_8 )
if ( V_2 -> V_5 [ V_8 ] )
F_156 ( V_2 -> V_5 [ V_8 ] ) ;
F_129 ( V_2 ) ;
}
F_157 ( V_54 ) ;
F_158 ( V_54 ) ;
}
static int T_10 F_162 ( void )
{
unsigned int V_91 ;
int V_275 ;
F_163 ( sizeof( T_7 ) != 4 ) ;
if ( strncmp ( V_96 , L_8 , 3 ) &&
strncmp ( V_96 , L_54 , 3 ) ) {
F_37 ( V_277 L_55
L_56 ) ;
return - V_233 ;
}
if ( V_96 [ 3 ] != '\0' ) {
V_91 = F_36 ( V_96 + 3 , NULL , 10 ) ;
if ( V_91 < 20 || V_91 > 100 ) {
F_37 ( V_277 L_57
L_58
L_59 ) ;
return - V_233 ;
}
}
V_275 = F_164 ( & V_388 ) ;
if ( V_275 < 0 ) {
F_10 ( L_60 ,
V_388 . V_11 ) ;
return - V_59 ;
}
F_37 ( V_99 L_61
L_62 ) ;
return 0 ;
}
static void T_11 F_165 ( void )
{
F_166 ( & V_388 ) ;
F_37 ( V_99 L_61
L_63 ) ;
}
