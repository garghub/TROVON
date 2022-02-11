static int T_1 F_1 ( char * V_1 )
{
V_2 [ 0 ] . V_3 &= ~ V_4 ;
V_5 = 1 ;
return 1 ;
}
static int T_1 F_2 ( char * V_1 )
{
V_2 [ 0 ] . V_6 &= ~ ( V_7 | V_8 ) ;
V_9 = 1 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
V_10 = 1 ;
V_2 [ 0 ] . V_3 &= ~ V_11 ;
F_4 ( F_5 () &
~ ( 1 << V_12 ) ) ;
return 1 ;
}
static inline void F_6 ( void )
{
struct V_13 * V_14 = & V_15 ;
switch ( F_7 () ) {
case V_16 :
if ( ( V_14 -> V_17 & V_18 ) <= V_19 )
F_8 ( F_9 () | V_20 ) ;
break;
default:
break;
}
}
void T_1 F_10 ( void )
{
F_6 () ;
}
static inline int F_11 ( void )
{
#ifdef F_12
extern unsigned long V_21 ( unsigned long ) ;
unsigned long V_22 , V_23 ;
unsigned long V_24 = F_13 () ;
V_22 = V_21 ( V_25 ) ;
F_14 ( V_24 ^ V_26 ) ;
V_23 = V_21 ( V_25 ) ;
F_14 ( V_24 ) ;
return V_22 != V_23 ;
#else
return 0 ;
#endif
}
static inline void F_15 ( int V_27 , const char * V_28 )
{
if ( V_27 == 0 )
V_29 = V_28 ;
}
static inline unsigned long F_16 ( void )
{
unsigned long V_30 , V_31 ;
V_30 = F_17 () ;
F_18 ( V_32 ) ;
V_31 = F_19 ( V_33 ) ;
F_20 ( V_30 ) ;
return V_31 ;
}
static inline int F_21 ( void )
{
return ( ( F_16 () & V_34 ) != V_35 ) ;
}
static inline unsigned long F_22 ( void )
{
unsigned long V_36 , V_37 ;
V_36 = F_17 () ;
F_18 ( V_38 ) ;
F_23 () ;
V_37 = F_24 () ;
F_25 () ;
F_20 ( V_36 ) ;
return V_37 ;
}
static inline void F_26 ( struct V_13 * V_14 )
{
#ifdef F_27
F_28 ( 0x3fffffffffffe000ULL ) ;
F_29 () ;
V_14 -> V_39 = F_30 ( F_31 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void F_32 ( struct V_13 * V_14 , unsigned int V_40 )
{
switch ( V_40 ) {
case V_41 :
V_14 -> V_42 |= V_43 | V_41 ;
case V_44 :
V_14 -> V_42 |= V_45 | V_44 ;
case V_46 :
V_14 -> V_42 |= V_46 ;
case V_47 :
V_14 -> V_42 |= V_47 ;
case V_48 :
V_14 -> V_42 |= V_49 | V_48 ;
break;
case V_43 :
V_14 -> V_42 |= V_43 ;
case V_45 :
V_14 -> V_42 |= V_45 ;
case V_49 :
V_14 -> V_42 |= V_49 ;
break;
}
}
static void F_33 ( struct V_13 * V_14 , int V_50 )
{
unsigned int V_51 ;
switch ( V_14 -> V_52 ) {
case V_53 :
case V_54 :
V_51 = F_34 () ;
if ( V_50 )
F_35 ( V_51 | V_55 ) ;
else
F_35 ( V_51 & ~ V_55 ) ;
F_29 () ;
break;
}
}
static inline unsigned int F_36 ( struct V_13 * V_14 )
{
unsigned int V_56 ;
int V_40 ;
V_56 = F_37 () ;
if ( ( ( ( V_56 & V_57 ) >> 7 ) == 1 ) ||
( ( ( V_56 & V_57 ) >> 7 ) == 4 ) )
V_14 -> V_3 |= V_58 ;
V_40 = ( V_56 & V_59 ) >> 13 ;
switch ( V_40 ) {
case 0 :
switch ( ( V_56 & V_60 ) >> 10 ) {
case 0 :
F_32 ( V_14 , V_45 ) ;
break;
case 1 :
F_32 ( V_14 , V_43 ) ;
break;
default:
goto V_61;
}
break;
case 2 :
switch ( ( V_56 & V_60 ) >> 10 ) {
case 0 :
F_32 ( V_14 , V_44 ) ;
break;
case 1 :
F_32 ( V_14 , V_41 ) ;
break;
default:
goto V_61;
}
break;
default:
goto V_61;
}
return V_56 & V_62 ;
V_61:
F_38 ( V_63 , V_56 ) ;
}
static inline unsigned int F_39 ( struct V_13 * V_14 )
{
unsigned int V_64 ;
V_64 = F_40 () ;
if ( V_64 & V_65 )
V_14 -> V_6 |= V_66 ;
if ( V_64 & V_67 )
V_14 -> V_3 |= V_68 ;
if ( V_64 & V_69 )
V_14 -> V_6 |= V_70 ;
if ( V_64 & V_71 )
V_14 -> V_3 |= V_72 ;
if ( V_64 & V_73 ) {
V_14 -> V_3 |= V_4 ;
V_14 -> V_3 |= V_74 ;
}
if ( V_75 ) {
V_14 -> V_76 = ( ( V_64 & V_77 ) >> 25 ) + 1 ;
V_14 -> V_78 = V_14 -> V_76 ;
V_14 -> V_79 = 0 ;
}
return V_64 & V_62 ;
}
static inline unsigned int F_41 ( struct V_13 * V_14 )
{
unsigned int V_80 ;
V_80 = F_42 () ;
if ( V_80 & V_81 )
V_14 -> V_82 . V_83 &= ~ V_84 ;
return V_80 & V_62 ;
}
static inline unsigned int F_43 ( struct V_13 * V_14 )
{
unsigned int V_85 ;
V_85 = F_44 () ;
if ( V_85 & V_86 ) {
V_14 -> V_6 |= V_87 ;
V_14 -> V_3 |= V_88 ;
}
if ( V_85 & V_89 )
V_14 -> V_3 |= V_88 ;
if ( V_85 & V_90 )
V_14 -> V_6 |= V_7 ;
if ( V_85 & V_91 )
V_14 -> V_6 |= V_8 ;
if ( V_85 & V_92 )
V_14 -> V_3 |= V_93 ;
if ( V_85 & V_94 )
V_14 -> V_3 |= V_95 ;
if ( V_85 & V_96 )
V_14 -> V_6 |= V_97 ;
if ( V_85 & V_98 )
V_14 -> V_3 |= V_99 ;
if ( V_85 & V_100 )
V_14 -> V_3 |= V_101 ;
if ( V_85 & V_102 )
V_14 -> V_6 |= V_103 ;
if ( V_85 & V_104 )
V_14 -> V_3 |= V_105 ;
if ( V_85 & V_106 )
V_14 -> V_6 |= V_107 ;
if ( ( V_85 & V_108 ) && F_45 ( V_109 ) )
V_14 -> V_3 |= V_11 ;
return V_85 & V_62 ;
}
static inline unsigned int F_46 ( struct V_13 * V_14 )
{
unsigned int V_110 ;
unsigned int V_111 ;
unsigned int V_112 ;
unsigned int V_113 = V_114 ;
V_110 = F_47 () ;
if ( V_75 ) {
if ( ( ( V_110 & V_115 ) >> 29 ) == 2 )
V_14 -> V_3 |= V_116 ;
V_112 = V_110 & V_117 ;
switch ( V_112 ) {
case V_118 :
V_14 -> V_76 += ( V_110 & V_119 ) * 0x40 ;
V_14 -> V_78 = V_14 -> V_76 ;
break;
case V_120 :
V_14 -> V_78 +=
( ( V_110 & V_121 ) >>
V_122 ) * 0x40 ;
V_14 -> V_76 = V_14 -> V_78 ;
V_113 = V_123 ;
case V_124 :
V_111 = ( V_110 & ~ V_113 ) |
( F_48 ( V_112 ) <<
V_125 ) ;
F_49 ( V_111 ) ;
F_29 () ;
V_110 = F_47 () ;
if ( V_110 != V_111 ) {
F_50 ( L_1 ,
V_126 , V_110 ) ;
F_33 ( V_14 , 0 ) ;
break;
}
V_14 -> V_79 = 1 <<
( ( V_110 & V_127 ) >>
V_128 ) ;
V_14 -> V_129 = ( ( V_110 & V_130 ) >>
V_131 ) + 2 ;
V_14 -> V_76 += V_14 -> V_129 * V_14 -> V_79 ;
break;
}
}
V_14 -> V_132 = ( V_110 >> 16 ) & 0xff ;
return V_110 & V_62 ;
}
static inline unsigned int F_51 ( struct V_13 * V_14 )
{
unsigned int V_133 ;
V_133 = F_52 () ;
V_133 &= ~ V_134 ;
F_53 ( V_133 ) ;
if ( V_133 & V_135 )
V_14 -> V_3 |= V_136 ;
if ( V_133 & V_137 )
V_14 -> V_3 |= V_138 ;
return V_133 & V_62 ;
}
static void F_54 ( struct V_13 * V_14 )
{
int V_139 ;
V_14 -> V_3 = V_140 | V_141 | V_142 |
V_143 | V_144 | V_145 ;
V_14 -> V_82 . V_83 = V_84 ;
F_33 ( V_14 , 1 ) ;
V_139 = F_36 ( V_14 ) ;
F_55 ( ! V_139 ) ;
if ( V_139 )
V_139 = F_39 ( V_14 ) ;
if ( V_139 )
V_139 = F_41 ( V_14 ) ;
if ( V_139 )
V_139 = F_43 ( V_14 ) ;
if ( V_139 )
V_139 = F_46 ( V_14 ) ;
if ( V_139 )
V_139 = F_51 ( V_14 ) ;
F_56 ( V_14 ) ;
if ( V_146 ) {
F_57 ( F_58 () | V_147 ) ;
F_29 () ;
if ( F_58 () & V_147 )
V_14 -> V_3 |= V_148 ;
}
#ifndef F_59
if ( V_149 ) {
V_14 -> V_150 = F_60 () ;
if ( V_151 )
V_14 -> V_150 >>= F_61 ( F_62 () ) - 1 ;
}
#endif
}
static inline void F_63 ( struct V_13 * V_14 , unsigned int V_27 )
{
switch ( V_14 -> V_17 & V_152 ) {
case V_153 :
V_14 -> V_52 = V_154 ;
V_155 [ V_27 ] = L_2 ;
V_14 -> V_3 = V_58 | V_156 |
V_157 ;
if ( F_21 () )
V_14 -> V_3 |= V_4 ;
V_14 -> V_76 = 64 ;
break;
case V_158 :
if ( ( V_14 -> V_17 & V_18 ) == V_159 ) {
if ( F_11 () ) {
V_14 -> V_52 = V_160 ;
V_155 [ V_27 ] = L_3 ;
} else {
V_14 -> V_52 = V_161 ;
V_155 [ V_27 ] = L_4 ;
}
} else {
V_14 -> V_52 = V_162 ;
V_155 [ V_27 ] = L_5 ;
}
V_14 -> V_3 = V_58 | V_156 |
V_157 ;
if ( F_21 () )
V_14 -> V_3 |= V_4 ;
V_14 -> V_76 = 64 ;
break;
case V_163 :
if ( F_37 () & V_164 ) {
if ( ( V_14 -> V_17 & V_18 ) >=
V_165 ) {
V_14 -> V_52 = V_166 ;
V_155 [ V_27 ] = L_6 ;
} else {
V_14 -> V_52 = V_167 ;
V_155 [ V_27 ] = L_7 ;
}
} else {
int V_168 = F_37 () & V_169 ;
int V_170 ;
switch ( V_168 ) {
case V_171 :
case V_172 :
case V_173 :
V_170 = 1 ;
break;
default:
V_170 = 0 ;
break;
}
if ( ( V_14 -> V_17 & V_18 ) >=
V_165 ) {
V_14 -> V_52 = V_170 ? V_174 : V_175 ;
V_155 [ V_27 ] = V_170 ? L_8 : L_9 ;
} else {
V_14 -> V_52 = V_170 ? V_176 : V_177 ;
V_155 [ V_27 ] = V_170 ? L_10 : L_11 ;
}
}
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_178 | V_4 | V_74 |
V_68 | V_179 |
V_144 ;
V_14 -> V_76 = 48 ;
break;
case V_180 :
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_178 ;
V_14 -> V_76 = 32 ;
switch ( V_14 -> V_17 & 0xf0 ) {
case V_181 :
V_14 -> V_52 = V_182 ;
V_155 [ V_27 ] = L_12 ;
break;
case V_183 :
V_14 -> V_52 = V_184 ;
V_155 [ V_27 ] = L_13 ;
break;
case V_185 :
if ( ( V_14 -> V_17 & 0xf ) < 0x3 ) {
V_14 -> V_52 = V_186 ;
V_155 [ V_27 ] = L_14 ;
} else {
V_14 -> V_52 = V_187 ;
V_155 [ V_27 ] = L_15 ;
}
break;
case V_188 :
if ( ( V_14 -> V_17 & 0xf ) < 0x4 ) {
V_14 -> V_52 = V_189 ;
V_155 [ V_27 ] = L_16 ;
} else {
V_14 -> V_52 = V_190 ;
V_14 -> V_3 |= V_144 ;
V_155 [ V_27 ] = L_17 ;
}
break;
default:
F_64 ( V_191 L_18 ) ;
V_14 -> V_52 = V_192 ;
V_155 [ V_27 ] = L_19 ;
break;
}
break;
case V_193 :
V_14 -> V_52 = V_194 ;
V_155 [ V_27 ] = L_20 ;
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_178 | V_4 | V_74 |
V_144 ;
V_14 -> V_76 = 32 ;
break;
case V_195 :
V_14 -> V_52 = V_196 ;
V_155 [ V_27 ] = L_21 ;
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_178 | V_4 | V_74 |
V_144 ;
V_14 -> V_76 = 48 ;
break;
#if 0
case PRID_IMP_R4650:
c->cputype = CPU_R4650;
__cpu_name[cpu] = "R4650";
set_isa(c, MIPS_CPU_ISA_III);
c->options = R4K_OPTS | MIPS_CPU_FPU | MIPS_CPU_LLSC;
c->tlbsize = 48;
break;
#endif
case V_197 :
V_14 -> V_3 = V_58 | V_198 ;
if ( ( V_14 -> V_17 & 0xf0 ) == ( V_199 & 0xf0 ) ) {
V_14 -> V_52 = V_200 ;
V_155 [ V_27 ] = L_22 ;
V_14 -> V_76 = 64 ;
} else {
switch ( V_14 -> V_17 & V_18 ) {
case V_201 :
V_14 -> V_52 = V_202 ;
V_155 [ V_27 ] = L_23 ;
V_14 -> V_76 = 32 ;
break;
case V_203 :
V_14 -> V_52 = V_204 ;
V_155 [ V_27 ] = L_24 ;
V_14 -> V_76 = 64 ;
break;
}
}
break;
case V_205 :
V_14 -> V_52 = V_206 ;
V_155 [ V_27 ] = L_25 ;
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_178 | V_4 | V_74 |
V_144 ;
V_14 -> V_76 = 48 ;
break;
case V_207 :
V_14 -> V_52 = V_208 ;
V_155 [ V_27 ] = L_26 ;
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_178 | V_144 ;
if ( ! ( V_14 -> V_17 & 0x08 ) )
V_14 -> V_3 |= V_4 | V_74 ;
V_14 -> V_76 = 48 ;
break;
case V_209 :
V_14 -> V_52 = V_210 ;
V_155 [ V_27 ] = L_27 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_178 | V_4 | V_74 |
V_144 ;
V_14 -> V_76 = 48 ;
break;
case V_211 :
V_14 -> V_52 = V_212 ;
V_155 [ V_27 ] = L_28 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_178 | V_4 | V_74 |
V_68 | V_144 ;
V_14 -> V_76 = 48 ;
break;
case V_213 :
V_14 -> V_52 = V_214 ;
V_155 [ V_27 ] = L_29 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_178 | V_4 | V_74 |
V_68 | V_144 ;
V_14 -> V_76 = 48 ;
break;
case V_215 :
V_14 -> V_52 = V_216 ;
V_155 [ V_27 ] = L_30 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_178 | V_4 | V_74 |
V_143 | V_144 ;
V_14 -> V_76 = 48 ;
break;
case V_217 :
V_14 -> V_52 = V_218 ;
V_155 [ V_27 ] = L_31 ;
F_32 ( V_14 , V_49 ) ;
V_14 -> V_3 = V_58 | V_4 |
V_144 ;
V_14 -> V_76 = 32 ;
break;
case V_219 :
V_14 -> V_52 = V_220 ;
V_155 [ V_27 ] = L_32 ;
F_32 ( V_14 , V_49 ) ;
V_14 -> V_3 = V_58 | V_4 |
V_144 ;
V_14 -> V_76 = 32 ;
break;
case V_221 :
V_14 -> V_52 = V_222 ;
V_155 [ V_27 ] = L_33 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_178 | V_4 | V_74 |
V_144 ;
V_14 -> V_76 = ( F_65 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_223 :
V_14 -> V_52 = V_224 ;
V_155 [ V_27 ] = L_34 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_58 | V_140 |
V_4 | V_74 |
V_144 ;
V_14 -> V_76 = 384 ;
break;
case V_225 :
V_14 -> V_52 = V_226 ;
V_155 [ V_27 ] = L_35 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_58 | V_141 | V_140 |
V_4 | V_74 |
V_142 | V_68 |
V_144 ;
V_14 -> V_76 = 64 ;
break;
case V_227 :
V_14 -> V_52 = V_228 ;
V_155 [ V_27 ] = L_36 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_58 | V_141 | V_140 |
V_4 | V_74 |
V_142 | V_68 |
V_144 ;
V_14 -> V_76 = 64 ;
break;
case V_229 :
V_14 -> V_52 = V_230 ;
V_155 [ V_27 ] = L_37 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_58 | V_141 | V_140 |
V_4 | V_74 |
V_142 | V_68 |
V_144 ;
V_14 -> V_76 = 64 ;
break;
case V_231 :
switch ( V_14 -> V_17 & V_18 ) {
case V_232 :
V_14 -> V_52 = V_233 ;
V_155 [ V_27 ] = L_38 ;
F_15 ( V_27 , L_39 ) ;
break;
case V_234 :
V_14 -> V_52 = V_233 ;
V_155 [ V_27 ] = L_38 ;
F_15 ( V_27 , L_40 ) ;
break;
case V_235 :
V_14 -> V_52 = V_236 ;
V_155 [ V_27 ] = L_41 ;
F_15 ( V_27 , L_42 ) ;
break;
case V_237 :
case V_238 :
V_14 -> V_52 = V_236 ;
V_155 [ V_27 ] = L_41 ;
F_15 ( V_27 , L_43 ) ;
break;
}
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_178 |
V_4 | V_144 |
V_74 ;
V_14 -> V_76 = 64 ;
break;
case V_239 :
F_54 ( V_14 ) ;
V_14 -> V_52 = V_240 ;
switch ( V_14 -> V_17 & V_18 ) {
case V_241 :
V_155 [ V_27 ] = L_44 ;
break;
}
break;
}
}
static inline void F_66 ( struct V_13 * V_14 , unsigned int V_27 )
{
switch ( V_14 -> V_17 & V_152 ) {
case V_242 :
V_14 -> V_52 = V_243 ;
V_155 [ V_27 ] = L_45 ;
break;
case V_244 :
case V_245 :
V_14 -> V_52 = V_246 ;
V_155 [ V_27 ] = L_46 ;
break;
case V_247 :
case V_248 :
V_14 -> V_52 = V_249 ;
V_155 [ V_27 ] = L_47 ;
break;
case V_250 :
V_14 -> V_52 = V_251 ;
V_155 [ V_27 ] = L_48 ;
break;
case V_252 :
V_14 -> V_52 = V_253 ;
V_155 [ V_27 ] = L_49 ;
break;
case V_254 :
V_14 -> V_52 = V_255 ;
V_155 [ V_27 ] = L_50 ;
break;
case V_256 :
V_14 -> V_52 = V_257 ;
V_155 [ V_27 ] = L_51 ;
break;
case V_258 :
V_14 -> V_52 = V_257 ;
V_155 [ V_27 ] = L_52 ;
break;
case V_259 :
V_14 -> V_52 = V_260 ;
V_155 [ V_27 ] = L_53 ;
break;
case V_261 :
V_14 -> V_52 = V_16 ;
V_155 [ V_27 ] = L_54 ;
break;
case V_262 :
V_14 -> V_52 = V_263 ;
V_155 [ V_27 ] = L_55 ;
break;
case V_264 :
V_14 -> V_52 = V_265 ;
V_155 [ V_27 ] = L_56 ;
break;
case V_266 :
V_14 -> V_52 = V_267 ;
V_155 [ V_27 ] = L_57 ;
break;
case V_268 :
V_14 -> V_52 = V_269 ;
V_155 [ V_27 ] = L_58 ;
break;
case V_270 :
V_14 -> V_52 = V_271 ;
V_155 [ V_27 ] = L_59 ;
break;
case V_272 :
V_14 -> V_52 = V_273 ;
V_155 [ V_27 ] = L_60 ;
break;
case V_274 :
V_14 -> V_52 = V_273 ;
V_155 [ V_27 ] = L_61 ;
break;
case V_275 :
V_14 -> V_52 = V_53 ;
V_155 [ V_27 ] = L_62 ;
break;
case V_276 :
V_14 -> V_52 = V_53 ;
V_155 [ V_27 ] = L_63 ;
break;
case V_277 :
V_14 -> V_52 = V_54 ;
V_155 [ V_27 ] = L_64 ;
break;
case V_278 :
V_14 -> V_52 = V_279 ;
V_155 [ V_27 ] = L_65 ;
break;
}
F_54 ( V_14 ) ;
F_67 () ;
}
static inline void F_68 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_54 ( V_14 ) ;
switch ( V_14 -> V_17 & V_152 ) {
case V_280 :
case V_281 :
V_14 -> V_52 = V_282 ;
switch ( ( V_14 -> V_17 >> 24 ) & 0xff ) {
case 0 :
V_155 [ V_27 ] = L_66 ;
break;
case 1 :
V_155 [ V_27 ] = L_67 ;
break;
case 2 :
V_155 [ V_27 ] = L_68 ;
break;
case 3 :
V_155 [ V_27 ] = L_69 ;
break;
case 4 :
V_155 [ V_27 ] = L_70 ;
if ( ( V_14 -> V_17 & V_18 ) == 2 )
V_155 [ V_27 ] = L_71 ;
break;
case 5 :
V_155 [ V_27 ] = L_72 ;
break;
default:
V_155 [ V_27 ] = L_73 ;
break;
}
break;
}
}
static inline void F_69 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_54 ( V_14 ) ;
switch ( V_14 -> V_17 & V_152 ) {
case V_283 :
V_14 -> V_52 = V_284 ;
V_155 [ V_27 ] = L_74 ;
if ( ( V_14 -> V_17 & V_18 ) < 0x02 )
V_14 -> V_3 &= ~ ( V_4 | V_74 ) ;
break;
case V_285 :
V_14 -> V_52 = V_286 ;
V_155 [ V_27 ] = L_75 ;
break;
}
}
static inline void F_70 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_54 ( V_14 ) ;
switch ( V_14 -> V_17 & V_152 ) {
case V_287 :
V_14 -> V_52 = V_288 ;
V_155 [ V_27 ] = L_76 ;
V_14 -> V_82 . V_289 = 8 ;
V_14 -> V_76 = 64 ;
break;
}
}
static inline void F_71 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_54 ( V_14 ) ;
switch ( V_14 -> V_17 & V_152 ) {
case V_290 :
V_14 -> V_52 = V_291 ;
V_155 [ V_27 ] = L_77 ;
F_32 ( V_14 , V_45 ) ;
break;
}
}
static inline void F_72 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_54 ( V_14 ) ;
switch ( V_14 -> V_17 & V_152 ) {
case V_292 :
case V_293 :
V_14 -> V_52 = V_294 ;
V_155 [ V_27 ] = L_78 ;
F_15 ( V_27 , L_79 ) ;
break;
case V_295 :
case V_296 :
case V_297 :
V_14 -> V_52 = V_298 ;
V_155 [ V_27 ] = L_80 ;
F_15 ( V_27 , L_81 ) ;
break;
case V_299 : {
int V_300 = V_14 -> V_17 & V_18 ;
if ( V_300 >= V_301 &&
V_300 <= V_302 ) {
V_14 -> V_52 = V_303 ;
V_155 [ V_27 ] = L_82 ;
F_15 ( V_27 , L_83 ) ;
} else {
V_14 -> V_52 = V_304 ;
V_155 [ V_27 ] = L_84 ;
F_15 ( V_27 , L_85 ) ;
}
break;
}
case V_305 :
V_14 -> V_52 = V_306 ;
V_155 [ V_27 ] = L_86 ;
F_15 ( V_27 , L_87 ) ;
V_14 -> V_3 |= V_99 ;
break;
}
}
static inline void F_73 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_54 ( V_14 ) ;
switch ( V_14 -> V_17 & V_152 ) {
case V_307 :
case V_308 :
case V_309 :
V_14 -> V_52 = V_310 ;
V_155 [ V_27 ] = L_88 ;
goto V_311;
case V_312 :
case V_313 :
case V_314 :
case V_315 :
V_14 -> V_52 = V_316 ;
V_155 [ V_27 ] = L_89 ;
V_311:
F_15 ( V_27 , L_90 ) ;
break;
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
V_14 -> V_52 = V_322 ;
V_155 [ V_27 ] = L_91 ;
F_15 ( V_27 , L_92 ) ;
break;
case V_323 :
case V_324 :
V_14 -> V_52 = V_325 ;
V_155 [ V_27 ] = L_93 ;
F_15 ( V_27 , L_94 ) ;
break;
default:
F_64 ( V_191 L_95 ) ;
V_14 -> V_52 = V_326 ;
break;
}
}
static inline void F_74 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_54 ( V_14 ) ;
V_14 -> V_3 &= ~ V_142 ;
F_55 ( ! F_75 ( V_327 ) || V_327 ) ;
switch ( V_14 -> V_17 & V_152 ) {
case V_328 :
V_14 -> V_52 = V_329 ;
V_155 [ V_27 ] = L_96 ;
break;
default:
F_38 ( L_97 ) ;
break;
}
}
static inline void F_76 ( struct V_13 * V_14 , int V_27 )
{
F_54 ( V_14 ) ;
if ( ( V_14 -> V_17 & V_152 ) == V_330 ) {
V_14 -> V_52 = V_282 ;
V_155 [ V_27 ] = L_98 ;
return;
}
V_14 -> V_3 = ( V_58 |
V_140 |
V_142 |
V_143 |
V_68 |
V_72 |
V_144 ) ;
switch ( V_14 -> V_17 & V_152 ) {
case V_331 :
case V_332 :
case V_333 :
V_14 -> V_52 = V_334 ;
V_155 [ V_27 ] = L_99 ;
break;
case V_335 :
case V_336 :
V_14 -> V_52 = V_334 ;
V_155 [ V_27 ] = L_100 ;
break;
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
V_14 -> V_52 = V_345 ;
V_155 [ V_27 ] = L_101 ;
break;
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
V_14 -> V_52 = V_345 ;
V_155 [ V_27 ] = L_102 ;
break;
default:
F_77 ( L_103 ,
V_14 -> V_17 ) ;
V_14 -> V_52 = V_345 ;
break;
}
if ( V_14 -> V_52 == V_334 ) {
F_32 ( V_14 , V_41 ) ;
V_14 -> V_3 |= ( V_4 | V_99 | V_145 ) ;
V_14 -> V_76 = ( ( F_34 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_32 ( V_14 , V_44 ) ;
V_14 -> V_76 = ( ( F_40 () >> 25 ) & 0x3f ) + 1 ;
}
V_14 -> V_132 = 0xf ;
}
void F_78 ( void )
{
struct V_13 * V_14 = & V_15 ;
unsigned int V_27 = F_79 () ;
V_14 -> V_17 = V_359 ;
V_14 -> V_31 = V_35 ;
V_14 -> V_52 = V_326 ;
V_14 -> V_17 = F_80 () ;
switch ( V_14 -> V_17 & V_360 ) {
case V_361 :
F_63 ( V_14 , V_27 ) ;
break;
case V_362 :
F_66 ( V_14 , V_27 ) ;
break;
case V_363 :
F_68 ( V_14 , V_27 ) ;
break;
case V_364 :
F_69 ( V_14 , V_27 ) ;
break;
case V_365 :
F_72 ( V_14 , V_27 ) ;
break;
case V_366 :
F_70 ( V_14 , V_27 ) ;
break;
case V_367 :
F_71 ( V_14 , V_27 ) ;
break;
case V_368 :
F_73 ( V_14 , V_27 ) ;
break;
case V_369 :
F_74 ( V_14 , V_27 ) ;
break;
case V_370 :
F_76 ( V_14 , V_27 ) ;
break;
}
F_55 ( ! V_155 [ V_27 ] ) ;
F_55 ( V_14 -> V_52 == V_326 ) ;
F_55 ( F_7 () != V_14 -> V_52 ) ;
if ( V_5 )
V_14 -> V_3 &= ~ V_4 ;
if ( V_9 )
V_14 -> V_6 &= ~ ( V_7 | V_8 ) ;
if ( V_10 ) {
V_14 -> V_3 &= ~ V_11 ;
F_4 ( F_5 () &
~ ( 1 << V_12 ) ) ;
}
if ( V_14 -> V_3 & V_4 ) {
V_14 -> V_31 = F_16 () ;
if ( V_14 -> V_42 & ( V_45 | V_43 |
V_44 | V_41 ) ) {
if ( V_14 -> V_31 & V_371 )
V_14 -> V_6 |= V_372 ;
}
}
if ( V_149 ) {
V_14 -> V_373 = ( ( F_81 () >> 26 ) & 0x0f ) + 1 ;
V_14 -> V_3 |= V_374 ;
}
else
V_14 -> V_373 = 1 ;
if ( V_375 ) {
V_14 -> V_37 = F_22 () ;
F_82 ( V_14 -> V_37 & V_376 ,
L_104 ) ;
}
F_26 ( V_14 ) ;
#ifdef F_83
if ( V_27 == 0 )
V_377 = ~ ( ( 1ull << V_378 ) - 1 ) ;
#endif
}
void F_84 ( void )
{
struct V_13 * V_14 = & V_15 ;
F_77 ( L_105 ,
F_79 () , V_14 -> V_17 , F_85 () ) ;
if ( V_14 -> V_3 & V_4 )
F_64 ( V_191 L_106 , V_14 -> V_31 ) ;
if ( V_375 )
F_77 ( L_107 , V_14 -> V_37 ) ;
}
