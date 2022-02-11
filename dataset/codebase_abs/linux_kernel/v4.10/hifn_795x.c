static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 [ 0 ] + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 [ 1 ] + V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_5 ( ( V_6 T_1 ) F_6 ( V_5 ) , V_2 -> V_4 [ 0 ] + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_5 ( ( V_6 T_1 ) F_6 ( V_5 ) , V_2 -> V_4 [ 1 ] + V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_8 ;
for ( V_7 = 10000 ; V_7 > 0 ; -- V_7 ) {
V_8 = F_1 ( V_2 , V_9 ) ;
if ( ! ( V_8 & V_10 ) )
break;
F_9 ( 1 ) ;
}
if ( ! V_7 )
F_10 ( & V_2 -> V_11 -> V_2 , L_1 ) ;
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
static T_1 F_15 ( T_1 V_25 , T_2 V_26 )
{
int V_7 ;
T_1 V_27 ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
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
T_3 V_32 ;
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
V_2 -> V_29 . V_39 = V_2 -> V_39 ;
V_2 -> V_29 . V_40 = F_16 ,
V_2 -> V_29 . V_41 = F_21 ,
V_2 -> V_29 . V_31 = ( unsigned long ) V_2 ;
return F_24 ( & V_2 -> V_29 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_29 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_7 ;
F_7 ( V_2 , V_42 , F_3 ( V_2 , V_42 ) |
V_43 ) ;
for ( V_7 = 100 ; V_7 > 0 ; -- V_7 ) {
F_14 ( 1 ) ;
if ( ( F_3 ( V_2 , V_42 ) & V_43 ) == 0 )
break;
}
if ( ! V_7 ) {
F_10 ( & V_2 -> V_11 -> V_2 , L_2 ) ;
} else {
F_7 ( V_2 , V_44 , V_45 ) ;
V_2 -> V_46 |= V_47 ;
F_7 ( V_2 , V_19 , V_2 -> V_46 ) ;
F_28 ( & V_2 -> V_11 -> V_2 , L_3 ) ;
}
F_7 ( V_2 , V_48 ,
F_3 ( V_2 , V_48 ) | V_49 ) ;
F_28 ( & V_2 -> V_11 -> V_2 , L_4 ) ;
#ifdef F_29
F_3 ( V_2 , V_36 ) ;
V_2 -> V_33 = F_19 () ;
#endif
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_50 , V_51 ;
char * V_52 = NULL ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_31 ( V_53 ) ; V_7 ++ ) {
if ( V_53 [ V_7 ] . V_54 == V_2 -> V_11 -> V_55 &&
V_53 [ V_7 ] . V_56 == V_2 -> V_11 -> V_57 ) {
V_52 = V_53 [ V_7 ] . V_58 ;
break;
}
}
if ( ! V_52 ) {
F_10 ( & V_2 -> V_11 -> V_2 , L_5 ) ;
return - V_59 ;
}
V_50 = F_3 ( V_2 , V_21 ) ;
F_7 ( V_2 , V_21 ,
V_60 | V_22 |
V_23 | V_24 ) ;
F_14 ( 1 ) ;
V_51 = F_3 ( V_2 , V_61 ) ;
F_14 ( 1 ) ;
F_7 ( V_2 , V_62 , 0 ) ;
F_14 ( 1 ) ;
for ( V_7 = 0 ; V_7 < 12 ; ++ V_7 ) {
V_51 = F_15 ( V_51 , V_52 [ V_7 ] + 0x101 ) ;
F_7 ( V_2 , V_62 , V_51 ) ;
F_14 ( 1 ) ;
}
F_7 ( V_2 , V_21 , V_50 ) ;
F_28 ( & V_2 -> V_11 -> V_2 , L_6 , V_2 -> V_39 , F_32 ( V_2 -> V_11 ) ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
T_1 V_66 = V_2 -> V_67 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_68 ; ++ V_7 )
V_64 -> V_69 [ V_7 ] . V_70 = F_34 ( V_66 +
F_35 ( struct V_63 , V_71 [ V_7 ] [ 0 ] ) ) ;
for ( V_7 = 0 ; V_7 < V_72 ; ++ V_7 )
V_64 -> V_73 [ V_7 ] . V_70 = F_34 ( V_66 +
F_35 ( struct V_63 , V_74 [ V_7 ] [ 0 ] ) ) ;
V_64 -> V_69 [ V_68 ] . V_70 = F_34 ( V_66 +
F_35 ( struct V_63 , V_69 [ 0 ] ) ) ;
V_64 -> V_75 [ V_76 ] . V_70 = F_34 ( V_66 +
F_35 ( struct V_63 , V_75 [ 0 ] ) ) ;
V_64 -> V_77 [ V_78 ] . V_70 = F_34 ( V_66 +
F_35 ( struct V_63 , V_77 [ 0 ] ) ) ;
V_64 -> V_73 [ V_72 ] . V_70 = F_34 ( V_66 +
F_35 ( struct V_63 , V_73 [ 0 ] ) ) ;
V_64 -> V_79 = V_64 -> V_80 = V_64 -> V_81 = V_64 -> V_82 = 0 ;
V_64 -> V_83 = V_64 -> V_84 = V_64 -> V_85 = V_64 -> V_86 = 0 ;
V_64 -> V_87 = V_64 -> V_88 = V_64 -> V_89 = V_64 -> V_90 = 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
unsigned int V_91 , V_92 ;
T_1 V_93 ;
V_93 = V_94 | V_95 ;
if ( strncmp ( V_96 , L_7 , 3 ) == 0 )
V_93 |= V_97 ;
else
V_93 |= V_98 ;
if ( V_96 [ 3 ] != '\0' )
V_91 = F_37 ( V_96 + 3 , NULL , 10 ) ;
else {
V_91 = 66 ;
F_38 ( & V_2 -> V_11 -> V_2 , L_8 ,
V_91 , V_96 ) ;
}
V_92 = V_99 / V_91 ;
V_93 |= ( V_92 / 2 - 1 ) << V_100 ;
if ( V_92 <= 8 )
V_93 |= V_101 ;
else
V_93 |= V_102 ;
F_7 ( V_2 , V_94 , V_93 |
V_103 | V_104 | V_105 ) ;
F_14 ( 10 ) ;
F_7 ( V_2 , V_94 , V_93 |
V_103 | V_104 ) ;
F_7 ( V_2 , V_94 , V_93 |
V_106 | V_107 ) ;
V_2 -> V_38 = 1000000 * ( V_91 + 1 ) * V_92 / 2 ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_66 = V_2 -> V_67 ;
F_4 ( V_2 , V_9 , V_12 ) ;
F_4 ( V_2 , V_108 , V_109 ) ;
F_4 ( V_2 , V_18 , V_110 ) ;
F_7 ( V_2 , V_111 , V_66 +
F_35 ( struct V_63 , V_69 [ 0 ] ) ) ;
F_7 ( V_2 , V_112 , V_66 +
F_35 ( struct V_63 , V_75 [ 0 ] ) ) ;
F_7 ( V_2 , V_113 , V_66 +
F_35 ( struct V_63 , V_77 [ 0 ] ) ) ;
F_7 ( V_2 , V_114 , V_66 +
F_35 ( struct V_63 , V_73 [ 0 ] ) ) ;
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
V_115 | V_116 |
V_117 | V_118 |
V_119 | V_120 | V_121 |
V_122 | V_123 |
V_124 | V_125 | V_126 |
V_127 | V_128 |
V_129 | V_130 | V_131 |
V_132 |
V_133 | V_134 | V_135 |
V_136 |
V_137 |
V_138 ) ;
#endif
F_3 ( V_2 , V_13 ) ;
V_2 -> V_46 |= V_139 | V_140 |
V_141 | V_142 |
V_143 | V_144 | V_145 |
V_146 ;
V_2 -> V_46 &= ~ V_147 ;
F_7 ( V_2 , V_19 , V_2 -> V_46 ) ;
F_3 ( V_2 , V_19 ) ;
#if 0
hifn_write_0(dev, HIFN_0_PUCNFG, HIFN_PUCNFG_ENCCNFG |
HIFN_PUCNFG_DRFR_128 | HIFN_PUCNFG_TCALLPHASES |
HIFN_PUCNFG_TCDRVTOTEM | HIFN_PUCNFG_BUS32 |
HIFN_PUCNFG_DRAM);
#else
F_4 ( V_2 , V_148 , 0x10342 ) ;
#endif
F_36 ( V_2 ) ;
F_4 ( V_2 , V_149 , V_150 ) ;
F_7 ( V_2 , V_21 , V_22 |
V_23 | V_24 | V_151 |
( ( V_152 << 16 ) & V_153 ) |
( ( V_154 << 8 ) & V_155 ) ) ;
}
static int F_40 ( struct V_1 * V_2 , T_4 * V_156 ,
unsigned V_157 , unsigned V_158 , T_5 V_159 , T_4 V_160 )
{
struct V_161 * V_162 ;
T_4 * V_163 = V_156 ;
V_162 = (struct V_161 * ) V_163 ;
V_162 -> V_164 = F_41 ( V_159 ) ;
V_162 -> V_165 =
F_41 ( V_158 & V_166 ) ;
V_162 -> V_167 =
F_41 ( V_157 & V_166 ) ;
V_157 >>= 16 ;
V_158 >>= 16 ;
V_162 -> V_168 = F_41 ( V_160 |
( ( V_158 << V_169 ) & V_170 ) |
( ( V_157 << V_171 ) & V_172 ) ) ;
return sizeof( struct V_161 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
T_4 * V_156 , unsigned V_157 , unsigned V_158 ,
T_4 * V_173 , int V_174 , T_4 * V_175 , int V_176 , T_5 V_177 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
struct V_178 * V_179 ;
T_4 * V_163 = V_156 ;
T_5 V_180 ;
V_179 = (struct V_178 * ) V_163 ;
V_179 -> V_181 = F_41 ( V_157 & 0xffff ) ;
V_157 >>= 16 ;
V_179 -> V_164 = F_41 ( V_177 |
( ( V_157 << V_182 ) &
V_183 ) ) ;
V_179 -> V_184 = 0 ;
V_179 -> V_185 = 0 ;
V_163 += sizeof( struct V_178 ) ;
V_64 -> V_79 ++ ;
if ( V_64 -> V_79 > 1 ) {
V_2 -> V_46 |= V_147 ;
F_7 ( V_2 , V_19 , V_2 -> V_46 ) ;
}
if ( V_174 ) {
memcpy ( V_163 , V_173 , V_174 ) ;
V_163 += V_174 ;
}
if ( V_176 ) {
memcpy ( V_163 , V_175 , V_176 ) ;
V_163 += V_176 ;
}
V_180 = V_163 - V_156 ;
return V_180 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_186 * V_187 , struct V_188 * V_189 ,
void * V_31 , unsigned int V_190 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_180 , V_191 ;
T_4 * V_156 , * V_163 ;
T_5 V_159 ;
V_191 = V_64 -> V_83 ;
V_163 = V_156 = V_64 -> V_71 [ V_64 -> V_83 ] ;
V_159 = 0 ;
switch ( V_189 -> V_192 ) {
case V_193 :
V_159 = V_194 | V_195 ;
break;
case V_196 :
V_159 = V_194 ;
break;
case V_197 :
V_159 = V_198 ;
break;
default:
goto V_199;
}
V_163 += F_40 ( V_2 , V_163 , V_190 ,
V_190 , V_159 , V_2 -> V_160 ) ;
if ( V_189 -> V_192 == V_196 || V_189 -> V_192 == V_193 ) {
T_5 V_200 = 0 ;
if ( V_187 -> V_201 )
V_200 |= V_202 ;
if ( V_189 -> V_175 && V_189 -> V_177 != V_203 )
V_200 |= V_204 ;
switch ( V_189 -> V_177 ) {
case V_203 :
V_200 |= V_205 ;
break;
case V_206 :
V_200 |= V_207 ;
break;
case V_208 :
V_200 |= V_209 ;
break;
case V_210 :
V_200 |= V_211 ;
break;
default:
goto V_199;
}
switch ( V_189 -> type ) {
case V_212 :
if ( V_187 -> V_201 != 16 )
goto V_199;
V_200 |= V_213 |
V_214 ;
break;
case V_215 :
if ( V_187 -> V_201 != 24 )
goto V_199;
V_200 |= V_216 |
V_214 ;
break;
case V_217 :
if ( V_187 -> V_201 != 32 )
goto V_199;
V_200 |= V_218 |
V_214 ;
break;
case V_219 :
if ( V_187 -> V_201 != 24 )
goto V_199;
V_200 |= V_220 ;
break;
case V_221 :
if ( V_187 -> V_201 != 8 )
goto V_199;
V_200 |= V_222 ;
break;
default:
goto V_199;
}
V_163 += F_42 ( V_2 , V_163 ,
V_190 , V_190 , V_187 -> V_173 , V_187 -> V_201 ,
V_189 -> V_175 , V_189 -> V_176 , V_200 ) ;
}
V_2 -> V_223 [ V_191 ] = V_31 ;
V_2 -> V_224 ++ ;
V_180 = V_163 - V_156 ;
V_64 -> V_69 [ V_64 -> V_83 ] . V_225 = F_34 ( V_180 | V_226 |
V_227 | V_228 ) ;
if ( ++ V_64 -> V_83 == V_68 ) {
V_64 -> V_69 [ V_64 -> V_83 ] . V_225 = F_34 (
V_226 | V_227 |
V_228 | V_229 ) ;
V_64 -> V_83 = 0 ;
} else {
V_64 -> V_69 [ V_64 -> V_83 - 1 ] . V_225 |= F_34 ( V_226 ) ;
}
if ( ! ( V_2 -> V_230 & V_231 ) ) {
F_7 ( V_2 , V_13 , V_115 ) ;
V_2 -> V_230 |= V_231 ;
}
return 0 ;
V_199:
return - V_232 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_233 * V_233 ,
unsigned int V_234 , unsigned int V_235 , int V_236 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_237 ;
T_6 V_51 ;
V_51 = F_45 ( V_2 -> V_11 , V_233 , V_234 , V_235 , V_238 ) ;
V_237 = V_64 -> V_84 ;
V_64 -> V_75 [ V_237 ] . V_70 = F_34 ( V_51 ) ;
V_64 -> V_75 [ V_237 ] . V_225 = F_34 ( V_235 | V_226 |
V_228 | ( V_236 ? V_227 : 0 ) ) ;
if ( ++ V_237 == V_76 ) {
V_64 -> V_75 [ V_237 ] . V_225 = F_34 ( V_226 |
V_229 | V_228 |
( V_236 ? V_227 : 0 ) ) ;
V_237 = 0 ;
}
V_64 -> V_84 = V_237 ;
V_64 -> V_80 ++ ;
if ( ! ( V_2 -> V_230 & V_239 ) ) {
F_7 ( V_2 , V_13 , V_116 ) ;
V_2 -> V_230 |= V_239 ;
}
return V_235 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
V_64 -> V_73 [ V_64 -> V_86 ] . V_225 = F_34 ( V_240 |
V_226 | V_227 ) ;
if ( ++ V_64 -> V_86 == V_72 ) {
V_64 -> V_73 [ V_72 ] . V_225 = F_34 ( V_226 |
V_229 | V_228 | V_227 ) ;
V_64 -> V_86 = 0 ;
}
V_64 -> V_82 ++ ;
if ( ! ( V_2 -> V_230 & V_241 ) ) {
F_7 ( V_2 , V_13 , V_118 ) ;
V_2 -> V_230 |= V_241 ;
}
}
static void F_47 ( struct V_1 * V_2 , struct V_233 * V_233 ,
unsigned V_234 , unsigned V_235 , int V_236 )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_237 ;
T_6 V_51 ;
V_51 = F_45 ( V_2 -> V_11 , V_233 , V_234 , V_235 , V_242 ) ;
V_237 = V_64 -> V_85 ;
V_64 -> V_77 [ V_237 ] . V_70 = F_34 ( V_51 ) ;
V_64 -> V_77 [ V_237 ] . V_225 = F_34 ( V_235 | V_226 |
V_228 | ( V_236 ? V_227 : 0 ) ) ;
if ( ++ V_237 == V_78 ) {
V_64 -> V_77 [ V_237 ] . V_225 = F_34 ( V_226 |
V_229 | V_228 |
( V_236 ? V_227 : 0 ) ) ;
V_237 = 0 ;
}
V_64 -> V_85 = V_237 ;
V_64 -> V_81 ++ ;
if ( ! ( V_2 -> V_230 & V_243 ) ) {
F_7 ( V_2 , V_13 , V_117 ) ;
V_2 -> V_230 |= V_243 ;
}
}
static int F_48 ( struct V_1 * V_2 ,
struct V_186 * V_187 , struct V_188 * V_189 ,
struct V_244 * V_245 , struct V_244 * V_246 ,
unsigned int V_190 , void * V_31 )
{
struct V_244 * V_247 ;
struct V_233 * V_248 , * V_249 ;
unsigned int V_250 , V_251 ;
unsigned int V_252 , V_253 ;
V_252 = V_190 ;
while ( V_252 ) {
V_248 = F_49 ( V_245 ) ;
V_250 = V_245 -> V_234 ;
V_253 = F_50 ( V_245 -> V_254 , V_252 ) ;
F_44 ( V_2 , V_248 , V_250 , V_253 , V_252 - V_253 == 0 ) ;
V_245 ++ ;
V_252 -= V_253 ;
}
V_247 = & V_189 -> V_255 . V_256 [ 0 ] ;
V_252 = V_190 ;
while ( V_252 ) {
if ( V_247 -> V_254 && V_189 -> V_255 . V_230 & V_257 ) {
F_51 ( ! F_49 ( V_247 ) ) ;
V_249 = F_49 ( V_247 ) ;
V_251 = 0 ;
V_253 = V_247 -> V_254 ;
} else {
F_51 ( ! F_49 ( V_246 ) ) ;
V_249 = F_49 ( V_246 ) ;
V_251 = V_246 -> V_234 ;
V_253 = V_246 -> V_254 ;
}
V_253 = F_50 ( V_253 , V_252 ) ;
F_47 ( V_2 , V_249 , V_251 , V_253 , V_252 - V_253 == 0 ) ;
V_246 ++ ;
V_247 ++ ;
V_252 -= V_253 ;
}
F_43 ( V_2 , V_187 , V_189 , V_31 , V_190 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_258 * V_259 ,
int V_260 , T_7 V_261 )
{
int V_7 ;
V_260 = F_50 ( V_262 , V_260 ) ;
F_53 ( V_259 -> V_256 , V_260 ) ;
V_259 -> V_260 = 0 ;
for ( V_7 = 0 ; V_7 < V_260 ; ++ V_7 ) {
struct V_233 * V_233 = F_54 ( V_261 ) ;
struct V_244 * V_263 ;
if ( ! V_233 )
break;
V_263 = & V_259 -> V_256 [ V_7 ] ;
F_55 ( V_263 , V_233 , V_264 , 0 ) ;
V_259 -> V_260 ++ ;
}
return V_7 ;
}
static void F_56 ( struct V_258 * V_259 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_259 -> V_260 ; ++ V_7 ) {
struct V_244 * V_263 = & V_259 -> V_256 [ V_7 ] ;
F_57 ( F_49 ( V_263 ) ) ;
V_263 -> V_254 = 0 ;
}
V_259 -> V_260 = 0 ;
}
static int F_58 ( unsigned int * V_265 , struct V_244 * V_246 ,
unsigned int V_235 , unsigned int * V_266 )
{
unsigned int V_267 , V_268 = * V_265 , V_190 = * V_266 ;
int V_237 = 0 ;
if ( V_268 < V_235 || V_235 > V_190 )
return - V_232 ;
while ( V_235 ) {
V_267 = F_59 ( V_268 , V_235 , V_246 -> V_254 ) ;
V_235 -= V_267 ;
V_268 -= V_267 ;
V_190 -= V_267 ;
F_60 ( L_9 ,
V_269 , V_267 , V_235 , V_268 , V_190 ) ;
V_246 ++ ;
V_237 ++ ;
}
* V_266 = V_190 ;
* V_265 = V_268 ;
return V_237 ;
}
static int V_258 ( struct V_270 * V_271 ,
struct V_258 * V_259 )
{
struct V_244 * V_246 , * V_247 ;
unsigned int V_190 = V_271 -> V_190 , V_234 , V_267 , V_272 ;
int V_237 , V_273 , V_274 ;
V_273 = V_237 = 0 ;
V_234 = 0 ;
while ( V_190 ) {
if ( V_237 >= V_259 -> V_260 && ( V_259 -> V_230 & V_257 ) )
return - V_232 ;
V_246 = & V_271 -> V_246 [ V_237 ] ;
F_60 ( L_10 ,
V_269 , V_246 -> V_254 , V_246 -> V_234 , V_234 , V_190 ) ;
if ( ! F_61 ( V_246 -> V_234 , V_275 ) ||
! F_61 ( V_246 -> V_254 , V_275 ) ||
V_234 ) {
unsigned V_158 = F_50 ( V_246 -> V_254 - V_234 , V_190 ) ;
unsigned V_157 = V_264 ;
V_247 = & V_259 -> V_256 [ V_237 ] ;
V_274 = F_58 ( & V_157 , V_246 , V_158 , & V_190 ) ;
if ( V_274 < 0 )
return V_274 ;
V_237 += V_274 ;
V_267 = V_158 & ~ ( V_275 - 1 ) ;
V_272 = V_158 & ( V_275 - 1 ) ;
if ( V_157 < V_190 ) {
V_190 += V_272 ;
F_62 ( L_11 ,
V_269 , V_157 , V_190 , V_158 , V_234 ) ;
F_62 ( L_12
L_13
L_14
L_15
L_16 , V_269 ) ;
F_63 () ;
} else {
V_267 += V_272 + V_190 ;
V_246 = & V_271 -> V_246 [ V_237 ] ;
V_274 = F_58 ( & V_157 , V_246 , V_190 , & V_190 ) ;
if ( V_274 < 0 )
return V_274 ;
V_237 += V_274 ;
}
V_247 -> V_254 = V_267 ;
V_247 -> V_234 = V_234 ;
} else {
V_190 -= F_50 ( V_246 -> V_254 , V_190 ) ;
V_237 ++ ;
}
V_273 ++ ;
}
return V_273 ;
}
static int F_64 ( struct V_270 * V_271 )
{
struct V_186 * V_187 = F_65 ( V_271 -> V_276 . V_277 ) ;
struct V_188 * V_189 = F_66 ( V_271 ) ;
struct V_1 * V_2 = V_187 -> V_2 ;
unsigned long V_157 , V_230 ;
unsigned int V_190 = V_271 -> V_190 , V_237 = 0 ;
int V_274 = - V_232 , V_278 ;
struct V_244 * V_246 ;
if ( V_189 -> V_175 && ! V_189 -> V_176 && V_189 -> V_177 != V_203 )
goto V_279;
V_189 -> V_255 . V_230 = 0 ;
while ( V_190 ) {
V_246 = & V_271 -> V_246 [ V_237 ] ;
V_157 = F_50 ( V_246 -> V_254 , V_190 ) ;
if ( ! F_61 ( V_246 -> V_234 , V_275 ) ||
! F_61 ( V_157 , V_275 ) )
V_189 -> V_255 . V_230 |= V_257 ;
V_190 -= V_157 ;
V_237 ++ ;
}
if ( V_189 -> V_255 . V_230 & V_257 ) {
V_274 = F_52 ( & V_189 -> V_255 , V_237 , V_280 ) ;
if ( V_274 < 0 )
return V_274 ;
}
V_278 = V_258 ( V_271 , & V_189 -> V_255 ) ;
if ( V_278 < 0 ) {
V_274 = V_278 ;
goto V_279;
}
F_67 ( & V_2 -> V_281 , V_230 ) ;
if ( V_2 -> V_224 + V_278 > V_282 ) {
V_274 = - V_283 ;
goto V_199;
}
V_274 = F_48 ( V_2 , V_187 , V_189 , V_271 -> V_245 , V_271 -> V_246 , V_271 -> V_190 , V_271 ) ;
if ( V_274 )
goto V_199;
V_2 -> V_160 ++ ;
V_2 -> V_284 = V_285 ;
F_68 ( & V_2 -> V_281 , V_230 ) ;
return 0 ;
V_199:
F_68 ( & V_2 -> V_281 , V_230 ) ;
V_279:
if ( V_274 ) {
F_38 ( & V_2 -> V_11 -> V_2 , L_17
L_18 ,
V_189 -> V_175 , V_189 -> V_176 ,
V_187 -> V_173 , V_187 -> V_201 ,
V_189 -> V_177 , V_189 -> V_192 , V_189 -> type , V_274 ) ;
}
return V_274 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_274 ;
V_2 -> V_224 = V_2 -> V_284 = 0 ;
F_13 ( V_2 , 1 ) ;
V_274 = F_30 ( V_2 ) ;
if ( V_274 )
return V_274 ;
F_11 ( V_2 ) ;
F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int F_70 ( void * V_286 , unsigned int * V_287 , unsigned int V_234 ,
struct V_244 * V_246 , unsigned int V_235 , unsigned int * V_266 )
{
unsigned int V_288 = * V_287 , V_190 = * V_266 , V_267 ;
void * V_289 ;
int V_237 = 0 ;
if ( V_288 < V_235 || V_235 > V_190 )
return - V_232 ;
while ( V_235 ) {
V_267 = F_59 ( V_288 , V_246 -> V_254 , V_235 ) ;
V_289 = F_71 ( F_49 ( V_246 ) ) ;
memcpy ( V_289 + V_246 -> V_234 + V_234 , V_286 , V_267 ) ;
F_72 ( V_289 ) ;
V_190 -= V_267 ;
V_235 -= V_267 ;
V_288 -= V_267 ;
V_286 += V_267 ;
V_234 = 0 ;
F_60 ( L_19 ,
V_269 , V_267 , V_235 , V_288 , V_190 ) ;
V_246 ++ ;
V_237 ++ ;
}
* V_266 = V_190 ;
* V_287 = V_288 ;
return V_237 ;
}
static inline void F_73 ( struct V_1 * V_2 , int V_7 )
{
unsigned long V_230 ;
F_67 ( & V_2 -> V_281 , V_230 ) ;
V_2 -> V_223 [ V_7 ] = NULL ;
V_2 -> V_224 -- ;
if ( V_2 -> V_224 < 0 )
F_38 ( & V_2 -> V_11 -> V_2 , L_20 , V_269 ,
V_2 -> V_224 ) ;
F_68 ( & V_2 -> V_281 , V_230 ) ;
F_51 ( V_2 -> V_224 < 0 ) ;
}
static void F_74 ( struct V_270 * V_271 , int error )
{
struct V_188 * V_189 = F_66 ( V_271 ) ;
if ( V_189 -> V_255 . V_230 & V_257 ) {
unsigned int V_190 = V_271 -> V_190 ;
int V_237 = 0 , V_274 ;
struct V_244 * V_246 , * V_247 ;
void * V_286 ;
while ( V_190 ) {
V_247 = & V_189 -> V_255 . V_256 [ V_237 ] ;
V_246 = & V_271 -> V_246 [ V_237 ] ;
F_60 ( L_21
L_22
L_23 ,
V_269 , F_49 ( V_247 ) , V_247 -> V_254 ,
F_49 ( V_246 ) , V_246 -> V_254 , V_190 ) ;
if ( ! V_247 -> V_254 ) {
V_190 -= F_50 ( V_246 -> V_254 , V_190 ) ;
V_237 ++ ;
continue;
}
V_286 = F_71 ( F_49 ( V_247 ) ) ;
V_274 = F_70 ( V_286 , & V_247 -> V_254 , V_247 -> V_234 ,
V_246 , V_190 , & V_190 ) ;
if ( V_274 < 0 ) {
F_72 ( V_286 ) ;
break;
}
V_237 += V_274 ;
F_72 ( V_286 ) ;
}
F_56 ( & V_189 -> V_255 ) ;
}
V_271 -> V_276 . V_290 ( & V_271 -> V_276 , error ) ;
}
static void F_75 ( struct V_1 * V_2 , int error )
{
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_7 , V_291 ;
F_28 ( & V_2 -> V_11 -> V_2 , L_24
L_25 ,
V_64 -> V_83 , V_64 -> V_84 , V_64 -> V_85 , V_64 -> V_86 ,
V_64 -> V_79 , V_64 -> V_80 , V_64 -> V_81 , V_64 -> V_82 ,
V_64 -> V_87 , V_64 -> V_88 , V_64 -> V_89 , V_64 -> V_90 ) ;
V_7 = V_64 -> V_90 ; V_291 = V_64 -> V_82 ;
while ( V_291 != 0 ) {
if ( V_64 -> V_73 [ V_7 ] . V_225 & F_34 ( V_226 ) )
break;
if ( V_2 -> V_223 [ V_7 ] ) {
V_2 -> V_292 ++ ;
V_2 -> V_293 = 0 ;
F_74 ( V_2 -> V_223 [ V_7 ] , error ) ;
F_73 ( V_2 , V_7 ) ;
}
if ( ++ V_7 == V_72 )
V_7 = 0 ;
V_291 -- ;
}
V_64 -> V_90 = V_7 ; V_64 -> V_82 = V_291 ;
V_7 = V_64 -> V_88 ; V_291 = V_64 -> V_80 ;
while ( V_291 != 0 ) {
if ( V_64 -> V_75 [ V_7 ] . V_225 & F_34 ( V_226 ) )
break;
if ( ++ V_7 == V_76 )
V_7 = 0 ;
V_291 -- ;
}
V_64 -> V_88 = V_7 ; V_64 -> V_80 = V_291 ;
V_7 = V_64 -> V_87 ; V_291 = V_64 -> V_79 ;
while ( V_291 != 0 ) {
if ( V_64 -> V_69 [ V_7 ] . V_225 & F_34 ( V_226 ) )
break;
if ( ++ V_7 == V_68 )
V_7 = 0 ;
V_291 -- ;
}
V_64 -> V_87 = V_7 ; V_64 -> V_79 = V_291 ;
V_7 = V_64 -> V_89 ; V_291 = V_64 -> V_81 ;
while ( V_291 != 0 ) {
if ( V_64 -> V_77 [ V_7 ] . V_225 & F_34 ( V_226 ) )
break;
if ( ++ V_7 == V_78 )
V_7 = 0 ;
V_291 -- ;
}
V_64 -> V_89 = V_7 ; V_64 -> V_81 = V_291 ;
F_28 ( & V_2 -> V_11 -> V_2 , L_26
L_25 ,
V_64 -> V_83 , V_64 -> V_84 , V_64 -> V_85 , V_64 -> V_86 ,
V_64 -> V_79 , V_64 -> V_80 , V_64 -> V_81 , V_64 -> V_82 ,
V_64 -> V_87 , V_64 -> V_88 , V_64 -> V_89 , V_64 -> V_90 ) ;
}
static void F_76 ( struct V_294 * V_295 )
{
struct V_296 * V_297 = F_77 ( V_295 ) ;
struct V_1 * V_2 = F_78 ( V_297 , struct V_1 , V_295 ) ;
unsigned long V_230 ;
int V_293 = 0 ;
T_1 V_298 = 0 ;
F_67 ( & V_2 -> V_281 , V_230 ) ;
if ( V_2 -> V_284 == 0 ) {
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
if ( V_64 -> V_79 == 0 && ( V_2 -> V_230 & V_231 ) ) {
V_2 -> V_230 &= ~ V_231 ;
V_298 |= V_17 ;
}
if ( V_64 -> V_80 == 0 && ( V_2 -> V_230 & V_239 ) ) {
V_2 -> V_230 &= ~ V_239 ;
V_298 |= V_16 ;
}
if ( V_64 -> V_81 == 0 && ( V_2 -> V_230 & V_243 ) ) {
V_2 -> V_230 &= ~ V_243 ;
V_298 |= V_14 ;
}
if ( V_64 -> V_82 == 0 && ( V_2 -> V_230 & V_241 ) ) {
V_2 -> V_230 &= ~ V_241 ;
V_298 |= V_15 ;
}
if ( V_298 )
F_7 ( V_2 , V_13 , V_298 ) ;
} else
V_2 -> V_284 -- ;
if ( ( V_2 -> V_299 == V_2 -> V_292 ) && V_2 -> V_224 )
V_293 = 1 ;
V_2 -> V_299 = V_2 -> V_292 ;
F_68 ( & V_2 -> V_281 , V_230 ) ;
if ( V_293 ) {
if ( ++ V_2 -> V_293 >= 5 ) {
int V_7 ;
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
F_38 ( & V_2 -> V_11 -> V_2 ,
L_27
L_28 ,
V_298 , V_2 -> V_284 , V_2 -> V_224 ,
V_2 -> V_292 , V_2 -> V_300 . V_301 , V_2 -> V_300 . V_302 ,
V_293 ) ;
F_38 ( & V_2 -> V_11 -> V_2 , L_29 , V_269 ) ;
for ( V_7 = 0 ; V_7 < V_72 ; ++ V_7 ) {
F_79 ( L_30 , V_64 -> V_73 [ V_7 ] . V_225 , V_2 -> V_223 [ V_7 ] ) ;
if ( V_2 -> V_223 [ V_7 ] ) {
F_74 ( V_2 -> V_223 [ V_7 ] , - V_59 ) ;
F_73 ( V_2 , V_7 ) ;
}
}
F_79 ( L_31 ) ;
F_13 ( V_2 , 1 ) ;
F_12 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_293 = 0 ;
}
F_80 ( & V_2 -> V_303 ) ;
}
F_81 ( & V_2 -> V_295 , V_304 ) ;
}
static T_8 F_82 ( int V_305 , void * V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 ;
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
T_1 V_306 , V_307 ;
V_306 = F_3 ( V_2 , V_13 ) ;
F_28 ( & V_2 -> V_11 -> V_2 , L_32
L_33 ,
V_306 , V_2 -> V_46 , V_306 & V_2 -> V_46 , V_64 -> V_83 ,
V_64 -> V_83 , V_64 -> V_84 , V_64 -> V_85 , V_64 -> V_86 ,
V_64 -> V_79 , V_64 -> V_80 , V_64 -> V_81 , V_64 -> V_82 ) ;
if ( ( V_306 & V_2 -> V_46 ) == 0 )
return V_308 ;
F_7 ( V_2 , V_13 , V_306 & V_2 -> V_46 ) ;
if ( V_306 & V_137 )
F_4 ( V_2 , V_149 , F_1 ( V_2 , V_149 ) ) ;
if ( V_306 & V_138 )
F_7 ( V_2 , V_309 ,
F_3 ( V_2 , V_309 ) | V_310 ) ;
V_307 = V_306 & ( V_128 | V_123 ) ;
if ( V_307 ) {
T_1 V_311 = F_1 ( V_2 , V_149 ) ;
F_83 ( & V_2 -> V_11 -> V_2 , L_34 ,
! ! ( V_306 & V_128 ) ,
! ! ( V_306 & V_123 ) ,
V_311 , ! ! ( V_311 & V_150 ) ) ;
if ( ! ! ( V_311 & V_150 ) )
F_4 ( V_2 , V_149 , V_150 ) ;
F_7 ( V_2 , V_13 , V_306 & ( V_128 |
V_123 ) ) ;
}
V_307 = V_306 & ( V_133 | V_129 |
V_119 | V_124 ) ;
if ( V_307 ) {
F_83 ( & V_2 -> V_11 -> V_2 , L_35 ,
! ! ( V_306 & V_133 ) ,
! ! ( V_306 & V_129 ) ,
! ! ( V_306 & V_119 ) ,
! ! ( V_306 & V_124 ) ) ;
F_13 ( V_2 , 1 ) ;
F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
}
if ( ( V_306 & V_136 ) && ( V_64 -> V_79 == 0 ) ) {
F_28 ( & V_2 -> V_11 -> V_2 , L_36 ) ;
V_2 -> V_46 &= ~ ( V_147 ) ;
F_7 ( V_2 , V_19 , V_2 -> V_46 ) ;
}
F_80 ( & V_2 -> V_303 ) ;
return V_312 ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned long V_230 ;
struct V_313 * V_314 ;
struct V_270 * V_271 ;
struct V_63 * V_64 = (struct V_63 * ) V_2 -> V_65 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_72 ; ++ V_7 ) {
struct V_315 * V_316 = & V_64 -> V_73 [ V_7 ] ;
if ( V_2 -> V_223 [ V_7 ] ) {
F_74 ( V_2 -> V_223 [ V_7 ] ,
( V_316 -> V_225 & F_34 ( V_226 ) ) ? - V_59 : 0 ) ;
F_73 ( V_2 , V_7 ) ;
}
}
F_67 ( & V_2 -> V_281 , V_230 ) ;
while ( ( V_314 = F_85 ( & V_2 -> V_300 ) ) ) {
V_271 = F_86 ( V_314 ) ;
F_68 ( & V_2 -> V_281 , V_230 ) ;
F_74 ( V_271 , - V_59 ) ;
F_67 ( & V_2 -> V_281 , V_230 ) ;
}
F_68 ( & V_2 -> V_281 , V_230 ) ;
}
static int F_87 ( struct V_317 * V_318 , const T_4 * V_173 ,
unsigned int V_253 )
{
struct V_319 * V_277 = F_88 ( V_318 ) ;
struct V_186 * V_187 = F_65 ( V_277 ) ;
struct V_1 * V_2 = V_187 -> V_2 ;
if ( V_253 > V_320 ) {
F_89 ( V_318 , V_321 ) ;
return - 1 ;
}
if ( V_253 == V_322 ) {
T_1 V_323 [ V_324 ] ;
int V_8 = F_90 ( V_323 , V_173 ) ;
if ( F_91 ( V_8 == 0 ) && ( V_277 -> V_325 & V_326 ) ) {
V_277 -> V_325 |= V_327 ;
return - V_232 ;
}
}
V_2 -> V_230 &= ~ V_328 ;
memcpy ( V_187 -> V_173 , V_173 , V_253 ) ;
V_187 -> V_201 = V_253 ;
return 0 ;
}
static int F_92 ( struct V_270 * V_271 )
{
struct V_186 * V_187 = F_65 ( V_271 -> V_276 . V_277 ) ;
struct V_1 * V_2 = V_187 -> V_2 ;
int V_274 = - V_283 ;
if ( V_2 -> V_224 + F_93 ( V_271 -> V_190 , V_264 ) <= V_282 )
V_274 = F_64 ( V_271 ) ;
if ( V_274 == - V_283 ) {
unsigned long V_230 ;
F_67 ( & V_2 -> V_281 , V_230 ) ;
V_274 = F_94 ( & V_2 -> V_300 , V_271 ) ;
F_68 ( & V_2 -> V_281 , V_230 ) ;
}
return V_274 ;
}
static int F_95 ( struct V_270 * V_271 , T_4 V_192 ,
T_4 type , T_4 V_177 )
{
struct V_186 * V_187 = F_65 ( V_271 -> V_276 . V_277 ) ;
struct V_188 * V_189 = F_66 ( V_271 ) ;
unsigned V_176 ;
V_176 = F_96 ( F_97 ( V_271 ) ) ;
if ( V_271 -> V_329 && V_177 != V_203 ) {
if ( type == V_212 )
V_176 = V_330 ;
else if ( type == V_221 )
V_176 = V_322 ;
else if ( type == V_219 )
V_176 = V_331 ;
}
if ( V_187 -> V_201 != 16 && type == V_212 ) {
if ( V_187 -> V_201 == 24 )
type = V_215 ;
else if ( V_187 -> V_201 == 32 )
type = V_217 ;
}
V_189 -> V_192 = V_192 ;
V_189 -> V_177 = V_177 ;
V_189 -> type = type ;
V_189 -> V_175 = V_271 -> V_329 ;
V_189 -> V_176 = V_176 ;
return F_92 ( V_271 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_313 * V_314 , * V_332 ;
struct V_270 * V_271 ;
unsigned long V_230 ;
int V_274 = 0 ;
while ( V_2 -> V_224 < V_282 ) {
F_67 ( & V_2 -> V_281 , V_230 ) ;
V_332 = F_99 ( & V_2 -> V_300 ) ;
V_314 = F_85 ( & V_2 -> V_300 ) ;
F_68 ( & V_2 -> V_281 , V_230 ) ;
if ( ! V_314 )
break;
if ( V_332 )
V_332 -> V_290 ( V_332 , - V_333 ) ;
V_271 = F_86 ( V_314 ) ;
V_274 = F_92 ( V_271 ) ;
if ( V_274 )
break;
}
return V_274 ;
}
static int F_100 ( struct V_270 * V_271 , T_4 V_192 ,
T_4 type , T_4 V_177 )
{
int V_274 ;
struct V_186 * V_187 = F_65 ( V_271 -> V_276 . V_277 ) ;
struct V_1 * V_2 = V_187 -> V_2 ;
V_274 = F_95 ( V_271 , V_192 , type , V_177 ) ;
if ( V_274 )
return V_274 ;
if ( V_2 -> V_224 < V_282 && V_2 -> V_300 . V_301 )
F_98 ( V_2 ) ;
return - V_333 ;
}
static inline int F_101 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_212 , V_203 ) ;
}
static inline int F_102 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_212 , V_206 ) ;
}
static inline int F_103 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_212 , V_208 ) ;
}
static inline int F_104 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_212 , V_210 ) ;
}
static inline int F_105 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_212 , V_203 ) ;
}
static inline int F_106 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_212 , V_206 ) ;
}
static inline int F_107 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_212 , V_208 ) ;
}
static inline int F_108 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_212 , V_210 ) ;
}
static inline int F_109 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_221 , V_203 ) ;
}
static inline int F_110 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_221 , V_206 ) ;
}
static inline int F_111 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_221 , V_208 ) ;
}
static inline int F_112 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_221 , V_210 ) ;
}
static inline int F_113 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_221 , V_203 ) ;
}
static inline int F_114 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_221 , V_206 ) ;
}
static inline int F_115 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_221 , V_208 ) ;
}
static inline int F_116 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_221 , V_210 ) ;
}
static inline int F_117 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_219 , V_203 ) ;
}
static inline int F_118 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_219 , V_206 ) ;
}
static inline int F_119 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_219 , V_208 ) ;
}
static inline int F_120 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_196 ,
V_219 , V_210 ) ;
}
static inline int F_121 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_219 , V_203 ) ;
}
static inline int F_122 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_219 , V_206 ) ;
}
static inline int F_123 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_219 , V_208 ) ;
}
static inline int F_124 ( struct V_270 * V_271 )
{
return F_100 ( V_271 , V_193 ,
V_219 , V_210 ) ;
}
static int F_125 ( struct V_319 * V_277 )
{
struct V_334 * V_335 = V_277 -> V_336 ;
struct V_337 * V_338 = F_126 ( V_335 ) ;
struct V_186 * V_187 = F_65 ( V_277 ) ;
V_187 -> V_2 = V_338 -> V_2 ;
V_277 -> V_339 . V_340 = sizeof( struct V_188 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 , struct V_341 * V_247 )
{
struct V_337 * V_335 ;
int V_274 ;
V_335 = F_128 ( sizeof( * V_335 ) , V_342 ) ;
if ( ! V_335 )
return - V_343 ;
snprintf ( V_335 -> V_335 . V_344 , V_345 , L_37 , V_247 -> V_39 ) ;
snprintf ( V_335 -> V_335 . V_346 , V_345 , L_38 ,
V_247 -> V_347 , V_2 -> V_39 ) ;
V_335 -> V_335 . V_348 = 300 ;
V_335 -> V_335 . V_349 = V_350 |
V_351 | V_352 ;
V_335 -> V_335 . V_353 = V_247 -> V_354 ;
V_335 -> V_335 . V_355 = sizeof( struct V_186 ) ;
V_335 -> V_335 . V_356 = 0 ;
V_335 -> V_335 . V_357 = & V_358 ;
V_335 -> V_335 . V_359 = V_360 ;
V_335 -> V_335 . V_361 . V_362 = V_247 -> V_362 ;
V_335 -> V_335 . V_363 = F_125 ;
V_335 -> V_2 = V_2 ;
F_129 ( & V_335 -> V_364 , & V_2 -> V_365 ) ;
V_274 = F_130 ( & V_335 -> V_335 ) ;
if ( V_274 ) {
F_131 ( & V_335 -> V_364 ) ;
F_132 ( V_335 ) ;
}
return V_274 ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_337 * V_25 , * V_252 ;
F_134 (a, n, &dev->alg_list, entry) {
F_131 ( & V_25 -> V_364 ) ;
F_135 ( & V_25 -> V_335 ) ;
F_132 ( V_25 ) ;
}
}
static int F_136 ( struct V_1 * V_2 )
{
int V_7 , V_274 ;
for ( V_7 = 0 ; V_7 < F_31 ( V_366 ) ; ++ V_7 ) {
V_274 = F_127 ( V_2 , & V_366 [ V_7 ] ) ;
if ( V_274 )
goto V_279;
}
return 0 ;
V_279:
F_133 ( V_2 ) ;
return V_274 ;
}
static void F_137 ( unsigned long V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 ;
F_75 ( V_2 , 0 ) ;
if ( V_2 -> V_224 < V_282 && V_2 -> V_300 . V_301 )
F_98 ( V_2 ) ;
}
static int F_138 ( struct V_367 * V_11 , const struct V_368 * V_369 )
{
int V_274 , V_7 ;
struct V_1 * V_2 ;
char V_39 [ 8 ] ;
V_274 = F_139 ( V_11 ) ;
if ( V_274 )
return V_274 ;
F_140 ( V_11 ) ;
V_274 = F_141 ( V_11 , F_142 ( 32 ) ) ;
if ( V_274 )
goto V_370;
snprintf ( V_39 , sizeof( V_39 ) , L_39 ,
F_143 ( & V_371 ) - 1 ) ;
V_274 = F_144 ( V_11 , V_39 ) ;
if ( V_274 )
goto V_370;
if ( F_145 ( V_11 , 0 ) < V_372 ||
F_145 ( V_11 , 1 ) < V_373 ||
F_145 ( V_11 , 2 ) < V_374 ) {
F_10 ( & V_11 -> V_2 , L_40 ) ;
V_274 = - V_59 ;
goto V_375;
}
V_2 = F_128 ( sizeof( struct V_1 ) + sizeof( struct V_334 ) ,
V_342 ) ;
if ( ! V_2 ) {
V_274 = - V_343 ;
goto V_375;
}
F_146 ( & V_2 -> V_365 ) ;
snprintf ( V_2 -> V_39 , sizeof( V_2 -> V_39 ) , L_37 , V_39 ) ;
F_147 ( & V_2 -> V_281 ) ;
for ( V_7 = 0 ; V_7 < 3 ; ++ V_7 ) {
unsigned long V_51 , V_235 ;
V_51 = F_148 ( V_11 , V_7 ) ;
V_235 = F_145 ( V_11 , V_7 ) ;
V_2 -> V_4 [ V_7 ] = F_149 ( V_51 , V_235 ) ;
if ( ! V_2 -> V_4 [ V_7 ] ) {
V_274 = - V_343 ;
goto V_376;
}
}
V_2 -> V_65 = F_150 ( V_11 , sizeof( struct V_63 ) ,
& V_2 -> V_67 ) ;
if ( ! V_2 -> V_65 ) {
F_10 ( & V_11 -> V_2 , L_41 ) ;
V_274 = - V_343 ;
goto V_376;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_305 = V_11 -> V_305 ;
for ( V_7 = 0 ; V_7 < V_72 ; ++ V_7 )
V_2 -> V_223 [ V_7 ] = NULL ;
F_151 ( V_11 , V_2 ) ;
F_152 ( & V_2 -> V_303 , F_137 , ( unsigned long ) V_2 ) ;
F_153 ( & V_2 -> V_300 , 1 ) ;
V_274 = F_154 ( V_2 -> V_305 , F_82 , V_377 , V_2 -> V_39 , V_2 ) ;
if ( V_274 ) {
F_10 ( & V_11 -> V_2 , L_42 ,
V_2 -> V_305 , V_274 ) ;
V_2 -> V_305 = 0 ;
goto V_378;
}
V_274 = F_69 ( V_2 ) ;
if ( V_274 )
goto V_379;
V_274 = F_22 ( V_2 ) ;
if ( V_274 )
goto V_380;
V_274 = F_136 ( V_2 ) ;
if ( V_274 )
goto V_381;
F_155 ( & V_2 -> V_295 , F_76 ) ;
F_81 ( & V_2 -> V_295 , V_304 ) ;
F_28 ( & V_11 -> V_2 , L_43
L_44 ,
F_32 ( V_11 ) , V_2 -> V_39 ) ;
return 0 ;
V_381:
F_25 ( V_2 ) ;
V_380:
F_13 ( V_2 , 1 ) ;
F_12 ( V_2 ) ;
V_379:
F_156 ( V_2 -> V_305 , V_2 ) ;
F_157 ( & V_2 -> V_303 ) ;
V_378:
F_158 ( V_11 , sizeof( struct V_63 ) ,
V_2 -> V_65 , V_2 -> V_67 ) ;
V_376:
for ( V_7 = 0 ; V_7 < 3 ; ++ V_7 )
if ( V_2 -> V_4 [ V_7 ] )
F_159 ( V_2 -> V_4 [ V_7 ] ) ;
V_375:
F_160 ( V_11 ) ;
V_370:
F_161 ( V_11 ) ;
return V_274 ;
}
static void F_162 ( struct V_367 * V_11 )
{
int V_7 ;
struct V_1 * V_2 ;
V_2 = F_163 ( V_11 ) ;
if ( V_2 ) {
F_164 ( & V_2 -> V_295 ) ;
F_25 ( V_2 ) ;
F_133 ( V_2 ) ;
F_13 ( V_2 , 1 ) ;
F_12 ( V_2 ) ;
F_156 ( V_2 -> V_305 , V_2 ) ;
F_157 ( & V_2 -> V_303 ) ;
F_84 ( V_2 ) ;
F_158 ( V_11 , sizeof( struct V_63 ) ,
V_2 -> V_65 , V_2 -> V_67 ) ;
for ( V_7 = 0 ; V_7 < 3 ; ++ V_7 )
if ( V_2 -> V_4 [ V_7 ] )
F_159 ( V_2 -> V_4 [ V_7 ] ) ;
F_132 ( V_2 ) ;
}
F_160 ( V_11 ) ;
F_161 ( V_11 ) ;
}
static int T_9 F_165 ( void )
{
unsigned int V_91 ;
int V_274 ;
F_166 ( sizeof( T_6 ) != 4 ) ;
if ( strncmp ( V_96 , L_7 , 3 ) &&
strncmp ( V_96 , L_45 , 3 ) ) {
F_62 ( L_46 ) ;
return - V_232 ;
}
if ( V_96 [ 3 ] != '\0' ) {
V_91 = F_37 ( V_96 + 3 , NULL , 10 ) ;
if ( V_91 < 20 || V_91 > 100 ) {
F_62 ( L_47
L_48 ) ;
return - V_232 ;
}
}
V_274 = F_167 ( & V_382 ) ;
if ( V_274 < 0 ) {
F_62 ( L_49 ,
V_382 . V_39 ) ;
return - V_59 ;
}
F_79 ( L_50
L_51 ) ;
return 0 ;
}
static void T_10 F_168 ( void )
{
F_169 ( & V_382 ) ;
F_79 ( L_50
L_52 ) ;
}
