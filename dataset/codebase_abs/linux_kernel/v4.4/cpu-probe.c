static inline unsigned long F_1 ( void )
{
unsigned long V_1 , V_2 ;
V_1 = F_2 () ;
F_3 ( V_3 ) ;
V_2 = F_4 ( V_4 ) ;
F_5 ( V_1 ) ;
return V_2 ;
}
static inline int F_6 ( void )
{
return ( F_1 () & V_5 ) != V_6 ;
}
static inline unsigned long F_7 ( void )
{
unsigned long V_7 , V_8 ;
V_7 = F_2 () ;
F_3 ( V_9 ) ;
F_8 () ;
V_8 = F_9 () ;
F_10 () ;
F_5 ( V_7 ) ;
return V_8 ;
}
static inline void F_11 ( struct V_10 * V_11 )
{
unsigned long V_12 , V_13 , V_14 , V_15 , V_16 ;
V_14 = V_11 -> V_17 ;
V_13 = V_18 | V_19 | V_20 | V_21 ;
V_12 = F_2 () ;
F_3 ( V_3 ) ;
V_15 = V_14 & V_13 ;
F_12 ( V_22 , V_15 ) ;
V_15 = F_4 ( V_22 ) ;
V_16 = V_14 | ~ V_13 ;
F_12 ( V_22 , V_16 ) ;
V_16 = F_4 ( V_22 ) ;
F_12 ( V_22 , V_14 ) ;
F_5 ( V_12 ) ;
V_11 -> V_23 = ~ ( V_15 ^ V_16 ) & ~ V_13 ;
}
static void F_13 ( struct V_10 * V_11 )
{
T_1 V_24 ;
V_24 = 0 ;
if ( V_11 -> V_25 & ( V_26 | V_27 |
V_28 | V_29 |
V_30 | V_31 ) )
V_24 |= V_32 | V_33 ;
if ( V_11 -> V_25 & ( V_28 | V_29 |
V_30 | V_31 ) )
V_24 |= V_34 | V_35 | V_36 ;
V_11 -> V_2 = V_24 ;
}
static void F_14 ( struct V_10 * V_11 )
{
V_11 -> V_2 = F_1 () ;
V_37 = V_11 -> V_23 ;
if ( V_11 -> V_25 & ( V_26 | V_27 |
V_28 | V_29 |
V_30 | V_31 ) ) {
if ( V_11 -> V_2 & V_38 )
V_11 -> V_39 |= V_40 ;
if ( V_11 -> V_2 & V_41 )
V_11 -> V_42 |= V_43 ;
}
F_11 ( V_11 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
V_11 -> V_42 &= ~ V_44 ;
V_11 -> V_23 = V_37 ;
F_13 ( V_11 ) ;
}
static int T_2 F_16 ( char * V_45 )
{
F_15 ( & V_46 ) ;
V_47 = 1 ;
return 1 ;
}
static int T_2 F_17 ( char * V_45 )
{
V_48 [ 0 ] . V_39 &= ~ ( V_49 | V_50 ) ;
V_51 = 1 ;
return 1 ;
}
static int T_2 F_18 ( char * V_45 )
{
V_52 = 1 ;
V_48 [ 0 ] . V_42 &= ~ V_53 ;
F_19 ( F_20 () &
~ ( 1 << V_54 ) ) ;
return 1 ;
}
static int T_2 F_21 ( char * V_45 )
{
unsigned int V_55 , V_56 ;
if ( ! V_57 )
return 1 ;
if ( F_22 ( & V_48 [ 0 ] , 0 ) ) {
F_23 ( L_1 ) ;
return 1 ;
}
F_24 () ;
V_55 = F_25 () ;
V_56 = V_55 & V_58 ;
if ( V_56 == V_59 ) {
F_23 ( L_2 ) ;
return 1 ;
}
V_60 = 1 ;
V_57 = 0 ;
F_26 ( L_3 ) ;
V_48 [ 0 ] . V_61 -= V_48 [ 0 ] . V_62 *
V_48 [ 0 ] . V_63 ;
V_48 [ 0 ] . V_63 = 0 ;
V_48 [ 0 ] . V_62 = 0 ;
return 1 ;
}
static inline void F_27 ( void )
{
struct V_10 * V_11 = & V_64 ;
switch ( F_28 () ) {
case V_65 :
if ( ( V_11 -> V_66 & V_67 ) <= V_68 )
F_29 ( F_30 () | V_69 ) ;
break;
default:
break;
}
}
void T_2 F_31 ( void )
{
F_27 () ;
}
static inline int F_32 ( void )
{
#ifdef F_33
extern unsigned long V_70 ( unsigned long ) ;
unsigned long V_71 , V_72 ;
unsigned long V_73 = F_34 () ;
V_71 = V_70 ( V_74 ) ;
F_35 ( V_73 ^ V_75 ) ;
V_72 = V_70 ( V_74 ) ;
F_35 ( V_73 ) ;
return V_71 != V_72 ;
#else
return 0 ;
#endif
}
static inline void F_36 ( int V_76 , const char * V_77 )
{
if ( V_76 == 0 )
V_78 = V_77 ;
}
static inline void F_37 ( struct V_10 * V_11 )
{
#ifdef F_38
F_39 ( 0x3fffffffffffe000ULL ) ;
F_24 () ;
V_11 -> V_79 = F_40 ( F_41 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void F_42 ( struct V_10 * V_11 , unsigned int V_80 )
{
switch ( V_80 ) {
case V_29 :
V_11 -> V_25 |= V_28 | V_29 ;
case V_27 :
V_11 -> V_25 |= V_26 | V_27 ;
case V_81 :
V_11 -> V_25 |= V_81 ;
case V_82 :
V_11 -> V_25 |= V_82 ;
case V_83 :
V_11 -> V_25 |= V_84 | V_83 ;
break;
case V_31 :
V_11 -> V_25 |= V_30 | V_31 ;
case V_30 :
V_11 -> V_25 |= V_30 ;
break;
case V_28 :
V_11 -> V_25 |= V_28 ;
case V_26 :
V_11 -> V_25 |= V_26 ;
case V_84 :
V_11 -> V_25 |= V_84 ;
break;
}
}
static unsigned int F_43 ( struct V_10 * V_11 )
{
unsigned int V_85 = V_11 -> V_61 / V_11 -> V_86 ;
if ( V_85 >= 12 )
return 1 ;
else if ( V_85 >= 6 )
return 2 ;
else
return 3 ;
}
static int F_22 ( struct V_10 * V_11 , int V_87 )
{
unsigned int V_88 ;
switch ( V_11 -> V_89 ) {
case V_90 :
case V_91 :
V_88 = F_44 () ;
V_88 &= ~ ( 3 << V_92 ) ;
if ( V_87 )
F_45 ( V_88 |
( F_43 ( V_11 )
<< V_92 )
| V_93 ) ;
else
F_45 ( V_88 & ~ V_93 ) ;
break;
case V_94 :
V_88 = F_30 () ;
V_88 &= ~ ( 3 << V_95 ) ;
F_29 ( V_88 | ( F_43 ( V_11 )
<< V_95 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static inline unsigned int F_46 ( struct V_10 * V_11 )
{
unsigned int V_96 ;
int V_80 , V_97 ;
V_96 = F_47 () ;
V_97 = V_96 & V_98 ;
if ( V_97 == V_99 )
V_11 -> V_42 |= V_100 ;
else if ( V_97 == V_101 )
V_11 -> V_42 |= V_100 | V_102 ;
V_80 = ( V_96 & V_103 ) >> 13 ;
switch ( V_80 ) {
case 0 :
switch ( ( V_96 & V_104 ) >> 10 ) {
case 0 :
F_42 ( V_11 , V_26 ) ;
break;
case 1 :
F_42 ( V_11 , V_28 ) ;
break;
case 2 :
F_42 ( V_11 , V_30 ) ;
break;
default:
goto V_105;
}
break;
case 2 :
switch ( ( V_96 & V_104 ) >> 10 ) {
case 0 :
F_42 ( V_11 , V_27 ) ;
break;
case 1 :
F_42 ( V_11 , V_29 ) ;
break;
case 2 :
F_42 ( V_11 , V_31 ) ;
break;
default:
goto V_105;
}
break;
default:
goto V_105;
}
return V_96 & V_106 ;
V_105:
F_48 ( V_107 , V_96 ) ;
}
static inline unsigned int F_49 ( struct V_10 * V_11 )
{
unsigned int V_108 ;
V_108 = F_50 () ;
if ( V_108 & V_109 )
V_11 -> V_39 |= V_110 ;
if ( V_108 & V_111 )
V_11 -> V_42 |= V_112 ;
if ( V_108 & V_113 )
V_11 -> V_39 |= V_114 ;
if ( V_108 & V_115 )
V_11 -> V_42 |= V_116 ;
if ( V_108 & V_117 ) {
V_11 -> V_42 |= V_44 ;
V_11 -> V_42 |= V_118 ;
}
if ( V_119 ) {
V_11 -> V_61 = ( ( V_108 & V_120 ) >> 25 ) + 1 ;
V_11 -> V_86 = V_11 -> V_61 ;
V_11 -> V_63 = 0 ;
}
return V_108 & V_106 ;
}
static inline unsigned int F_51 ( struct V_10 * V_11 )
{
unsigned int V_121 ;
V_121 = F_52 () ;
if ( V_121 & V_122 )
V_11 -> V_123 . V_124 &= ~ V_125 ;
return V_121 & V_106 ;
}
static inline unsigned int F_53 ( struct V_10 * V_11 )
{
unsigned int V_126 ;
V_126 = F_54 () ;
if ( V_126 & V_127 ) {
V_11 -> V_39 |= V_128 ;
V_11 -> V_42 |= V_129 ;
}
if ( V_126 & V_130 )
V_11 -> V_42 |= V_129 ;
if ( V_126 & V_131 )
V_11 -> V_39 |= V_49 ;
if ( V_126 & V_132 )
V_11 -> V_39 |= V_50 ;
if ( V_126 & V_133 )
V_11 -> V_42 |= V_134 ;
if ( V_126 & V_135 )
V_11 -> V_42 |= V_136 ;
if ( V_126 & V_137 )
V_11 -> V_39 |= V_138 ;
if ( V_126 & V_139 )
V_11 -> V_42 |= V_140 ;
if ( V_126 & V_141 )
V_11 -> V_42 |= V_142 ;
if ( V_126 & V_143 )
V_11 -> V_39 |= V_144 ;
if ( V_126 & V_145 )
V_11 -> V_42 |= V_146 ;
if ( V_126 & V_147 )
V_11 -> V_39 |= V_148 ;
if ( V_126 & V_149 ) {
V_11 -> V_150 = 0 ;
V_11 -> V_42 |= V_53 ;
}
if ( V_126 & V_151 )
V_11 -> V_42 |= V_152 ;
if ( V_126 & V_153 )
V_11 -> V_42 |= V_154 ;
return V_126 & V_106 ;
}
static inline unsigned int F_55 ( struct V_10 * V_11 )
{
unsigned int V_55 ;
unsigned int V_155 ;
unsigned int V_56 ;
unsigned int V_156 = V_157 ;
V_55 = F_25 () ;
if ( V_119 ) {
if ( ( ( V_55 & V_158 ) >> 29 ) == 2 )
V_11 -> V_42 |= V_159 ;
if ( ! V_160 )
V_56 = V_55 & V_58 ;
else if ( V_161 )
V_56 = V_162 ;
else
V_56 = 0 ;
switch ( V_56 ) {
case V_163 :
V_11 -> V_61 += ( V_55 & V_164 ) * 0x40 ;
V_11 -> V_86 = V_11 -> V_61 ;
break;
case V_162 :
V_11 -> V_86 +=
( ( V_55 & V_165 ) >>
V_166 ) * 0x40 ;
V_11 -> V_61 = V_11 -> V_86 ;
V_156 = V_167 ;
case V_59 :
if ( V_60 )
break;
V_155 = ( V_55 & ~ V_156 ) |
( F_56 ( V_56 ) <<
V_168 ) ;
F_57 ( V_155 ) ;
F_24 () ;
V_55 = F_25 () ;
if ( V_55 != V_155 ) {
F_58 ( L_4 ,
V_169 , V_55 ) ;
F_22 ( V_11 , 0 ) ;
break;
}
V_11 -> V_63 = 1 <<
( ( V_55 & V_170 ) >>
V_171 ) ;
V_11 -> V_62 = ( ( V_55 & V_172 ) >>
V_173 ) + 2 ;
V_11 -> V_61 += V_11 -> V_62 * V_11 -> V_63 ;
V_57 = 1 ;
break;
}
}
V_11 -> V_174 = ( V_55 >> 16 ) & 0xff ;
return V_55 & V_106 ;
}
static inline unsigned int F_59 ( struct V_10 * V_11 )
{
unsigned int V_175 ;
V_175 = F_60 () ;
V_175 &= ~ ( V_176 | V_177 ) ;
F_61 ( V_175 ) ;
if ( V_175 & V_178 )
V_11 -> V_42 |= V_179 ;
if ( V_175 & V_180 )
V_11 -> V_42 |= V_181 ;
if ( V_175 & V_182 )
V_11 -> V_42 |= V_183 ;
#ifdef F_62
if ( V_175 & V_184 )
V_11 -> V_42 |= V_185 ;
#endif
return V_175 & V_106 ;
}
static void F_63 ( struct V_10 * V_11 )
{
int V_186 ;
V_11 -> V_42 = V_187 | V_188 | V_189 |
V_190 | V_191 | V_192 ;
V_11 -> V_123 . V_124 = V_125 ;
F_22 ( V_11 , ! V_60 ) ;
V_186 = F_46 ( V_11 ) ;
F_64 ( ! V_186 ) ;
if ( V_186 )
V_186 = F_49 ( V_11 ) ;
if ( V_186 )
V_186 = F_51 ( V_11 ) ;
if ( V_186 )
V_186 = F_53 ( V_11 ) ;
if ( V_186 )
V_186 = F_55 ( V_11 ) ;
if ( V_186 )
V_186 = F_59 ( V_11 ) ;
F_65 ( V_11 ) ;
if ( V_193 ) {
F_66 ( V_194 ) ;
F_24 () ;
if ( F_67 () & V_194 )
V_11 -> V_42 |= V_195 ;
}
#ifndef F_68
if ( V_196 ) {
V_11 -> V_197 = F_69 () ;
if ( V_198 )
V_11 -> V_197 >>= F_70 ( F_71 () ) - 1 ;
}
#endif
}
static inline void F_72 ( struct V_10 * V_11 , unsigned int V_76 )
{
switch ( V_11 -> V_66 & V_199 ) {
case V_200 :
V_11 -> V_89 = V_201 ;
V_202 [ V_76 ] = L_5 ;
V_11 -> V_23 |= V_203 | V_204 ;
V_11 -> V_42 = V_100 | V_205 |
V_206 ;
if ( F_6 () )
V_11 -> V_42 |= V_44 ;
V_11 -> V_61 = 64 ;
break;
case V_207 :
if ( ( V_11 -> V_66 & V_67 ) == V_208 ) {
if ( F_32 () ) {
V_11 -> V_89 = V_209 ;
V_202 [ V_76 ] = L_6 ;
} else {
V_11 -> V_89 = V_210 ;
V_202 [ V_76 ] = L_7 ;
}
} else {
V_11 -> V_89 = V_211 ;
V_202 [ V_76 ] = L_8 ;
}
V_11 -> V_23 |= V_203 | V_204 ;
V_11 -> V_42 = V_100 | V_205 |
V_206 ;
if ( F_6 () )
V_11 -> V_42 |= V_44 ;
V_11 -> V_61 = 64 ;
break;
case V_212 :
if ( F_47 () & V_213 ) {
if ( ( V_11 -> V_66 & V_67 ) >=
V_214 ) {
V_11 -> V_89 = V_215 ;
V_202 [ V_76 ] = L_9 ;
} else {
V_11 -> V_89 = V_216 ;
V_202 [ V_76 ] = L_10 ;
}
} else {
int V_217 = F_47 () & V_218 ;
int V_219 ;
switch ( V_217 ) {
case V_220 :
case V_221 :
case V_222 :
V_219 = 1 ;
break;
default:
V_219 = 0 ;
break;
}
if ( ( V_11 -> V_66 & V_67 ) >=
V_214 ) {
V_11 -> V_89 = V_219 ? V_223 : V_224 ;
V_202 [ V_76 ] = V_219 ? L_11 : L_12 ;
} else {
V_11 -> V_89 = V_219 ? V_225 : V_226 ;
V_202 [ V_76 ] = V_219 ? L_13 : L_14 ;
}
}
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_203 ;
V_11 -> V_42 = V_227 | V_44 | V_118 |
V_112 | V_228 |
V_191 ;
V_11 -> V_61 = 48 ;
break;
case V_229 :
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_203 ;
V_11 -> V_42 = V_227 ;
V_11 -> V_61 = 32 ;
switch ( V_11 -> V_66 & 0xf0 ) {
case V_230 :
V_11 -> V_89 = V_231 ;
V_202 [ V_76 ] = L_15 ;
break;
case V_232 :
V_11 -> V_89 = V_233 ;
V_202 [ V_76 ] = L_16 ;
break;
case V_234 :
if ( ( V_11 -> V_66 & 0xf ) < 0x3 ) {
V_11 -> V_89 = V_235 ;
V_202 [ V_76 ] = L_17 ;
} else {
V_11 -> V_89 = V_236 ;
V_202 [ V_76 ] = L_18 ;
}
break;
case V_237 :
if ( ( V_11 -> V_66 & 0xf ) < 0x4 ) {
V_11 -> V_89 = V_238 ;
V_202 [ V_76 ] = L_19 ;
} else {
V_11 -> V_89 = V_239 ;
V_11 -> V_42 |= V_191 ;
V_202 [ V_76 ] = L_20 ;
}
break;
default:
F_73 ( V_240 L_21 ) ;
V_11 -> V_89 = V_241 ;
V_202 [ V_76 ] = L_22 ;
break;
}
break;
case V_242 :
V_11 -> V_89 = V_243 ;
V_202 [ V_76 ] = L_23 ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_203 ;
V_11 -> V_42 = V_227 | V_44 | V_118 |
V_191 ;
V_11 -> V_61 = 32 ;
break;
case V_244 :
V_11 -> V_89 = V_245 ;
V_202 [ V_76 ] = L_24 ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_203 ;
V_11 -> V_42 = V_227 | V_44 | V_118 |
V_191 ;
V_11 -> V_61 = 48 ;
break;
#if 0
case PRID_IMP_R4650:
c->cputype = CPU_R4650;
__cpu_name[cpu] = "R4650";
set_isa(c, MIPS_CPU_ISA_III);
c->fpu_msk31 |= FPU_CSR_CONDX;
c->options = R4K_OPTS | MIPS_CPU_FPU | MIPS_CPU_LLSC;
c->tlbsize = 48;
break;
#endif
case V_246 :
V_11 -> V_23 |= V_203 | V_204 ;
V_11 -> V_42 = V_100 | V_247 ;
if ( ( V_11 -> V_66 & 0xf0 ) == ( V_248 & 0xf0 ) ) {
V_11 -> V_89 = V_249 ;
V_202 [ V_76 ] = L_25 ;
V_11 -> V_61 = 64 ;
} else {
switch ( V_11 -> V_66 & V_67 ) {
case V_250 :
V_11 -> V_89 = V_251 ;
V_202 [ V_76 ] = L_26 ;
V_11 -> V_61 = 32 ;
break;
case V_252 :
V_11 -> V_89 = V_253 ;
V_202 [ V_76 ] = L_27 ;
V_11 -> V_61 = 64 ;
break;
}
}
break;
case V_254 :
V_11 -> V_89 = V_255 ;
V_202 [ V_76 ] = L_28 ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_203 ;
V_11 -> V_42 = V_227 | V_44 | V_118 |
V_191 ;
V_11 -> V_61 = 48 ;
break;
case V_256 :
V_11 -> V_89 = V_257 ;
V_202 [ V_76 ] = L_29 ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_203 ;
V_11 -> V_42 = V_227 | V_191 ;
if ( ! ( V_11 -> V_66 & 0x08 ) )
V_11 -> V_42 |= V_44 | V_118 ;
V_11 -> V_61 = 48 ;
break;
case V_258 :
V_11 -> V_89 = V_259 ;
V_202 [ V_76 ] = L_30 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_227 | V_44 | V_118 |
V_191 ;
V_11 -> V_61 = 48 ;
break;
case V_260 :
V_11 -> V_89 = V_261 ;
V_202 [ V_76 ] = L_31 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_227 | V_44 | V_118 |
V_112 | V_191 ;
V_11 -> V_61 = 48 ;
break;
case V_262 :
V_11 -> V_89 = V_263 ;
V_202 [ V_76 ] = L_32 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_227 | V_44 | V_118 |
V_112 | V_191 ;
V_11 -> V_61 = 48 ;
break;
case V_264 :
V_11 -> V_89 = V_265 ;
V_202 [ V_76 ] = L_33 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_227 | V_44 | V_118 |
V_190 | V_191 ;
V_11 -> V_61 = 48 ;
break;
case V_266 :
V_11 -> V_89 = V_267 ;
V_202 [ V_76 ] = L_34 ;
F_42 ( V_11 , V_84 ) ;
V_11 -> V_23 |= V_203 | V_204 ;
V_11 -> V_42 = V_100 | V_44 |
V_191 ;
V_11 -> V_61 = 32 ;
break;
case V_268 :
V_11 -> V_89 = V_269 ;
V_202 [ V_76 ] = L_35 ;
F_42 ( V_11 , V_84 ) ;
V_11 -> V_23 |= V_203 | V_204 ;
V_11 -> V_42 = V_100 | V_44 |
V_191 ;
V_11 -> V_61 = 32 ;
break;
case V_270 :
V_11 -> V_89 = V_271 ;
V_202 [ V_76 ] = L_36 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_227 | V_44 | V_118 |
V_191 ;
V_11 -> V_61 = ( F_74 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_272 :
V_11 -> V_89 = V_273 ;
V_202 [ V_76 ] = L_37 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_100 | V_187 |
V_44 | V_118 |
V_191 ;
V_11 -> V_61 = 384 ;
break;
case V_274 :
V_11 -> V_89 = V_275 ;
V_202 [ V_76 ] = L_38 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_100 | V_188 | V_187 |
V_44 | V_118 |
V_189 | V_112 |
V_191 ;
V_11 -> V_61 = 64 ;
break;
case V_276 :
V_11 -> V_89 = V_277 ;
V_202 [ V_76 ] = L_39 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_100 | V_188 | V_187 |
V_44 | V_118 |
V_189 | V_112 |
V_191 | V_278 ;
V_11 -> V_61 = 64 ;
break;
case V_279 :
if ( ( ( V_11 -> V_66 >> 4 ) & 0x0f ) > 2 ) {
V_11 -> V_89 = V_280 ;
V_202 [ V_76 ] = L_40 ;
} else {
V_11 -> V_89 = V_281 ;
V_202 [ V_76 ] = L_41 ;
}
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_100 | V_188 | V_187 |
V_44 | V_118 |
V_189 | V_112 |
V_191 | V_278 ;
V_11 -> V_61 = 64 ;
break;
case V_282 :
switch ( V_11 -> V_66 & V_67 ) {
case V_283 :
V_11 -> V_89 = V_284 ;
V_202 [ V_76 ] = L_42 ;
F_36 ( V_76 , L_43 ) ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_203 ;
break;
case V_285 :
V_11 -> V_89 = V_284 ;
V_202 [ V_76 ] = L_42 ;
F_36 ( V_76 , L_44 ) ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_203 ;
break;
case V_286 :
V_11 -> V_89 = V_287 ;
V_202 [ V_76 ] = L_45 ;
F_36 ( V_76 , L_46 ) ;
F_42 ( V_11 , V_27 ) ;
break;
case V_288 :
case V_289 :
V_11 -> V_89 = V_287 ;
V_202 [ V_76 ] = L_45 ;
F_36 ( V_76 , L_47 ) ;
F_42 ( V_11 , V_27 ) ;
break;
}
V_11 -> V_42 = V_227 |
V_44 | V_191 |
V_118 ;
V_11 -> V_61 = 64 ;
V_11 -> V_290 = V_291 ;
break;
case V_292 :
F_63 ( V_11 ) ;
V_11 -> V_89 = V_293 ;
switch ( V_11 -> V_66 & V_67 ) {
case V_294 :
V_202 [ V_76 ] = L_48 ;
break;
}
break;
}
}
static inline void F_75 ( struct V_10 * V_11 , unsigned int V_76 )
{
V_11 -> V_290 = V_291 ;
switch ( V_11 -> V_66 & V_199 ) {
case V_295 :
V_11 -> V_290 = V_296 ;
V_11 -> V_89 = V_297 ;
V_202 [ V_76 ] = L_49 ;
break;
case V_298 :
V_11 -> V_89 = V_299 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_50 ;
break;
case V_300 :
case V_301 :
V_11 -> V_89 = V_302 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_51 ;
break;
case V_303 :
case V_304 :
V_11 -> V_89 = V_305 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_52 ;
break;
case V_306 :
V_11 -> V_89 = V_307 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_53 ;
break;
case V_308 :
V_11 -> V_89 = V_309 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_54 ;
break;
case V_310 :
V_11 -> V_89 = V_311 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_55 ;
break;
case V_312 :
V_11 -> V_89 = V_313 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_56 ;
break;
case V_314 :
V_11 -> V_89 = V_313 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_57 ;
break;
case V_315 :
V_11 -> V_89 = V_316 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_58 ;
break;
case V_317 :
V_11 -> V_89 = V_65 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_59 ;
break;
case V_318 :
V_11 -> V_89 = V_319 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_60 ;
break;
case V_320 :
V_11 -> V_89 = V_321 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_61 ;
break;
case V_322 :
V_11 -> V_89 = V_323 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_62 ;
break;
case V_324 :
V_11 -> V_89 = V_325 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_63 ;
break;
case V_326 :
V_11 -> V_89 = V_327 ;
V_11 -> V_290 = V_296 ;
V_202 [ V_76 ] = L_64 ;
break;
case V_328 :
V_11 -> V_89 = V_329 ;
V_202 [ V_76 ] = L_65 ;
break;
case V_330 :
V_11 -> V_89 = V_329 ;
V_202 [ V_76 ] = L_66 ;
break;
case V_331 :
V_11 -> V_89 = V_90 ;
V_202 [ V_76 ] = L_67 ;
break;
case V_332 :
V_11 -> V_89 = V_90 ;
V_202 [ V_76 ] = L_68 ;
break;
case V_333 :
V_11 -> V_89 = V_91 ;
V_202 [ V_76 ] = L_69 ;
break;
case V_334 :
V_11 -> V_89 = V_94 ;
V_202 [ V_76 ] = L_70 ;
break;
case V_335 :
V_11 -> V_89 = V_336 ;
V_202 [ V_76 ] = L_71 ;
break;
}
F_63 ( V_11 ) ;
F_76 () ;
}
static inline void F_77 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_63 ( V_11 ) ;
switch ( V_11 -> V_66 & V_199 ) {
case V_337 :
case V_338 :
V_11 -> V_89 = V_339 ;
switch ( ( V_11 -> V_66 >> 24 ) & 0xff ) {
case 0 :
V_202 [ V_76 ] = L_72 ;
break;
case 1 :
V_202 [ V_76 ] = L_73 ;
break;
case 2 :
V_202 [ V_76 ] = L_74 ;
break;
case 3 :
V_202 [ V_76 ] = L_75 ;
break;
case 4 :
V_202 [ V_76 ] = L_76 ;
if ( ( V_11 -> V_66 & V_67 ) == 2 )
V_202 [ V_76 ] = L_77 ;
break;
case 5 :
V_202 [ V_76 ] = L_78 ;
break;
default:
V_202 [ V_76 ] = L_79 ;
break;
}
break;
}
}
static inline void F_78 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_63 ( V_11 ) ;
V_11 -> V_290 = V_291 ;
switch ( V_11 -> V_66 & V_199 ) {
case V_340 :
V_11 -> V_89 = V_341 ;
V_202 [ V_76 ] = L_80 ;
if ( ( V_11 -> V_66 & V_67 ) < 0x02 )
V_11 -> V_42 &= ~ ( V_44 | V_118 ) ;
break;
case V_342 :
V_11 -> V_89 = V_343 ;
V_202 [ V_76 ] = L_81 ;
break;
}
}
static inline void F_79 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_63 ( V_11 ) ;
switch ( V_11 -> V_66 & V_199 ) {
case V_344 :
V_11 -> V_89 = V_345 ;
V_202 [ V_76 ] = L_82 ;
V_11 -> V_123 . V_346 = 8 ;
V_11 -> V_61 = 64 ;
break;
}
}
static inline void F_80 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_63 ( V_11 ) ;
switch ( V_11 -> V_66 & V_199 ) {
case V_347 :
V_11 -> V_89 = V_348 ;
V_202 [ V_76 ] = L_83 ;
F_42 ( V_11 , V_26 ) ;
break;
}
}
static inline void F_81 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_63 ( V_11 ) ;
switch ( V_11 -> V_66 & V_199 ) {
case V_349 :
case V_350 :
V_11 -> V_89 = V_351 ;
V_202 [ V_76 ] = L_84 ;
F_36 ( V_76 , L_85 ) ;
break;
case V_352 :
case V_353 :
case V_354 :
V_11 -> V_89 = V_355 ;
V_202 [ V_76 ] = L_86 ;
F_36 ( V_76 , L_87 ) ;
break;
case V_356 : {
int V_357 = V_11 -> V_66 & V_67 ;
if ( V_357 >= V_358 &&
V_357 <= V_359 ) {
V_11 -> V_89 = V_360 ;
V_202 [ V_76 ] = L_88 ;
F_36 ( V_76 , L_89 ) ;
} else {
V_11 -> V_89 = V_361 ;
V_202 [ V_76 ] = L_90 ;
F_36 ( V_76 , L_91 ) ;
}
break;
}
case V_362 :
case V_363 :
V_11 -> V_89 = V_364 ;
V_202 [ V_76 ] = L_92 ;
F_36 ( V_76 , L_93 ) ;
V_11 -> V_42 |= V_140 ;
break;
}
}
static inline void F_82 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_63 ( V_11 ) ;
switch ( V_11 -> V_66 & V_199 ) {
case V_365 :
case V_366 :
case V_367 :
V_11 -> V_89 = V_368 ;
V_202 [ V_76 ] = L_94 ;
goto V_369;
case V_370 :
case V_371 :
case V_372 :
case V_373 :
V_11 -> V_89 = V_374 ;
V_202 [ V_76 ] = L_95 ;
V_369:
F_36 ( V_76 , L_96 ) ;
break;
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
V_11 -> V_89 = V_380 ;
V_202 [ V_76 ] = L_97 ;
F_36 ( V_76 , L_98 ) ;
break;
case V_381 :
case V_382 :
V_11 -> V_89 = V_383 ;
V_202 [ V_76 ] = L_99 ;
F_36 ( V_76 , L_100 ) ;
break;
default:
F_73 ( V_240 L_101 ) ;
V_11 -> V_89 = V_384 ;
break;
}
}
static inline void F_83 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_63 ( V_11 ) ;
V_11 -> V_42 &= ~ V_189 ;
F_64 ( ! F_84 ( V_385 ) || V_385 ) ;
switch ( V_11 -> V_66 & V_199 ) {
case V_386 :
V_11 -> V_89 = V_387 ;
V_11 -> V_290 = V_291 ;
V_202 [ V_76 ] = L_102 ;
break;
default:
F_48 ( L_103 ) ;
break;
}
}
static inline void F_85 ( struct V_10 * V_11 , int V_76 )
{
F_63 ( V_11 ) ;
if ( ( V_11 -> V_66 & V_199 ) == V_388 ) {
V_11 -> V_89 = V_339 ;
V_202 [ V_76 ] = L_104 ;
return;
}
V_11 -> V_42 = ( V_100 |
V_187 |
V_189 |
V_190 |
V_112 |
V_116 |
V_191 ) ;
switch ( V_11 -> V_66 & V_199 ) {
case V_389 :
case V_390 :
case V_391 :
V_11 -> V_89 = V_392 ;
V_202 [ V_76 ] = L_105 ;
break;
case V_393 :
case V_394 :
V_11 -> V_89 = V_392 ;
V_202 [ V_76 ] = L_106 ;
break;
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
V_11 -> V_89 = V_403 ;
V_202 [ V_76 ] = L_107 ;
break;
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
V_11 -> V_89 = V_403 ;
V_202 [ V_76 ] = L_108 ;
break;
default:
F_26 ( L_109 ,
V_11 -> V_66 ) ;
V_11 -> V_89 = V_403 ;
break;
}
if ( V_11 -> V_89 == V_392 ) {
F_42 ( V_11 , V_29 ) ;
V_11 -> V_42 |= ( V_44 | V_140 | V_192 ) ;
V_11 -> V_61 = ( ( F_44 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_42 ( V_11 , V_27 ) ;
V_11 -> V_61 = ( ( F_50 () >> 25 ) & 0x3f ) + 1 ;
}
V_11 -> V_174 = 0xf ;
}
void F_86 ( void )
{
struct V_10 * V_11 = & V_64 ;
unsigned int V_76 = F_87 () ;
V_11 -> V_66 = V_417 ;
V_11 -> V_2 = V_6 ;
V_11 -> V_89 = V_384 ;
V_11 -> V_290 = V_296 ;
V_11 -> V_17 = V_418 ;
V_11 -> V_23 = V_419 | V_420 | V_421 ;
V_11 -> V_66 = F_88 () ;
switch ( V_11 -> V_66 & V_422 ) {
case V_423 :
F_72 ( V_11 , V_76 ) ;
break;
case V_424 :
F_75 ( V_11 , V_76 ) ;
break;
case V_425 :
F_77 ( V_11 , V_76 ) ;
break;
case V_426 :
F_78 ( V_11 , V_76 ) ;
break;
case V_427 :
F_81 ( V_11 , V_76 ) ;
break;
case V_428 :
F_79 ( V_11 , V_76 ) ;
break;
case V_429 :
F_80 ( V_11 , V_76 ) ;
break;
case V_430 :
F_82 ( V_11 , V_76 ) ;
break;
case V_431 :
case V_432 :
case V_433 :
F_83 ( V_11 , V_76 ) ;
break;
case V_434 :
F_85 ( V_11 , V_76 ) ;
break;
}
F_64 ( ! V_202 [ V_76 ] ) ;
F_64 ( V_11 -> V_89 == V_384 ) ;
F_64 ( F_28 () != V_11 -> V_89 ) ;
if ( V_47 )
V_11 -> V_42 &= ~ V_44 ;
if ( V_51 )
V_11 -> V_39 &= ~ ( V_49 | V_50 ) ;
if ( V_52 ) {
V_11 -> V_42 &= ~ V_53 ;
F_19 ( F_20 () &
~ ( 1 << V_54 ) ) ;
}
if ( V_11 -> V_42 & V_44 )
F_14 ( V_11 ) ;
else
F_15 ( V_11 ) ;
if ( V_435 )
F_89 ( F_90 () |
V_436 ) ;
if ( V_196 ) {
V_11 -> V_437 = ( ( F_91 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_42 |= V_438 ;
}
else
V_11 -> V_437 = 1 ;
if ( V_160 )
V_439 |= V_440 ;
if ( V_441 ) {
V_11 -> V_8 = F_7 () ;
F_92 ( V_11 -> V_8 & V_442 ,
L_110 ) ;
V_439 |= V_443 ;
}
F_37 ( V_11 ) ;
#ifdef F_93
if ( V_76 == 0 )
V_444 = ~ ( ( 1ull << V_445 ) - 1 ) ;
#endif
}
void F_94 ( void )
{
struct V_10 * V_11 = & V_64 ;
F_26 ( L_111 ,
F_87 () , V_11 -> V_66 , F_95 () ) ;
if ( V_11 -> V_42 & V_44 )
F_73 ( V_240 L_112 , V_11 -> V_2 ) ;
if ( V_441 )
F_26 ( L_113 , V_11 -> V_8 ) ;
}
