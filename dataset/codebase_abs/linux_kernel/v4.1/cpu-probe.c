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
F_22 ( & V_48 [ 0 ] , 0 ) ;
F_23 () ;
V_55 = F_24 () ;
V_56 = V_55 & V_58 ;
if ( V_56 == V_59 ) {
F_25 ( L_1 ) ;
return 1 ;
}
V_60 = 1 ;
V_57 = 0 ;
F_26 ( L_2 ) ;
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
F_23 () ;
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
static void F_22 ( struct V_10 * V_11 , int V_87 )
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
F_23 () ;
break;
}
}
static inline unsigned int F_46 ( struct V_10 * V_11 )
{
unsigned int V_94 ;
int V_80 ;
V_94 = F_47 () ;
if ( ( ( ( V_94 & V_95 ) >> 7 ) == 1 ) ||
( ( ( V_94 & V_95 ) >> 7 ) == 4 ) )
V_11 -> V_42 |= V_96 ;
V_80 = ( V_94 & V_97 ) >> 13 ;
switch ( V_80 ) {
case 0 :
switch ( ( V_94 & V_98 ) >> 10 ) {
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
goto V_99;
}
break;
case 2 :
switch ( ( V_94 & V_98 ) >> 10 ) {
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
goto V_99;
}
break;
default:
goto V_99;
}
return V_94 & V_100 ;
V_99:
F_48 ( V_101 , V_94 ) ;
}
static inline unsigned int F_49 ( struct V_10 * V_11 )
{
unsigned int V_102 ;
V_102 = F_50 () ;
if ( V_102 & V_103 )
V_11 -> V_39 |= V_104 ;
if ( V_102 & V_105 )
V_11 -> V_42 |= V_106 ;
if ( V_102 & V_107 )
V_11 -> V_39 |= V_108 ;
if ( V_102 & V_109 )
V_11 -> V_42 |= V_110 ;
if ( V_102 & V_111 ) {
V_11 -> V_42 |= V_44 ;
V_11 -> V_42 |= V_112 ;
}
if ( V_113 ) {
V_11 -> V_61 = ( ( V_102 & V_114 ) >> 25 ) + 1 ;
V_11 -> V_86 = V_11 -> V_61 ;
V_11 -> V_63 = 0 ;
}
return V_102 & V_100 ;
}
static inline unsigned int F_51 ( struct V_10 * V_11 )
{
unsigned int V_115 ;
V_115 = F_52 () ;
if ( V_115 & V_116 )
V_11 -> V_117 . V_118 &= ~ V_119 ;
return V_115 & V_100 ;
}
static inline unsigned int F_53 ( struct V_10 * V_11 )
{
unsigned int V_120 ;
V_120 = F_54 () ;
if ( V_120 & V_121 ) {
V_11 -> V_39 |= V_122 ;
V_11 -> V_42 |= V_123 ;
}
if ( V_120 & V_124 )
V_11 -> V_42 |= V_123 ;
if ( V_120 & V_125 )
V_11 -> V_39 |= V_49 ;
if ( V_120 & V_126 )
V_11 -> V_39 |= V_50 ;
if ( V_120 & V_127 )
V_11 -> V_42 |= V_128 ;
if ( V_120 & V_129 )
V_11 -> V_42 |= V_130 ;
if ( V_120 & V_131 )
V_11 -> V_39 |= V_132 ;
if ( V_120 & V_133 )
V_11 -> V_42 |= V_134 ;
if ( V_120 & V_135 )
V_11 -> V_42 |= V_136 ;
if ( V_120 & V_137 )
V_11 -> V_39 |= V_138 ;
if ( V_120 & V_139 )
V_11 -> V_42 |= V_140 ;
if ( V_120 & V_141 )
V_11 -> V_39 |= V_142 ;
if ( ( V_120 & V_143 ) && F_55 ( V_144 ) ) {
V_11 -> V_145 = 0 ;
V_11 -> V_42 |= V_53 ;
}
if ( V_120 & V_146 )
V_11 -> V_42 |= V_147 ;
return V_120 & V_100 ;
}
static inline unsigned int F_56 ( struct V_10 * V_11 )
{
unsigned int V_55 ;
unsigned int V_148 ;
unsigned int V_56 ;
unsigned int V_149 = V_150 ;
V_55 = F_24 () ;
if ( V_113 ) {
if ( ( ( V_55 & V_151 ) >> 29 ) == 2 )
V_11 -> V_42 |= V_152 ;
V_56 = V_55 & V_58 ;
switch ( V_56 ) {
case V_153 :
V_11 -> V_61 += ( V_55 & V_154 ) * 0x40 ;
V_11 -> V_86 = V_11 -> V_61 ;
break;
case V_155 :
V_11 -> V_86 +=
( ( V_55 & V_156 ) >>
V_157 ) * 0x40 ;
V_11 -> V_61 = V_11 -> V_86 ;
V_149 = V_158 ;
case V_59 :
if ( V_60 )
break;
V_148 = ( V_55 & ~ V_149 ) |
( F_57 ( V_56 ) <<
V_159 ) ;
F_58 ( V_148 ) ;
F_23 () ;
V_55 = F_24 () ;
if ( V_55 != V_148 ) {
F_59 ( L_3 ,
V_160 , V_55 ) ;
F_22 ( V_11 , 0 ) ;
break;
}
V_11 -> V_63 = 1 <<
( ( V_55 & V_161 ) >>
V_162 ) ;
V_11 -> V_62 = ( ( V_55 & V_163 ) >>
V_164 ) + 2 ;
V_11 -> V_61 += V_11 -> V_62 * V_11 -> V_63 ;
V_57 = 1 ;
break;
}
}
V_11 -> V_165 = ( V_55 >> 16 ) & 0xff ;
return V_55 & V_100 ;
}
static inline unsigned int F_60 ( struct V_10 * V_11 )
{
unsigned int V_166 ;
V_166 = F_61 () ;
V_166 &= ~ ( V_167 | V_168 ) ;
F_62 ( V_166 ) ;
if ( V_166 & V_169 )
V_11 -> V_42 |= V_170 ;
if ( V_166 & V_171 )
V_11 -> V_42 |= V_172 ;
if ( V_166 & V_173 )
V_11 -> V_42 |= V_174 ;
#ifdef F_63
if ( V_166 & V_175 )
V_11 -> V_42 |= V_176 ;
#endif
return V_166 & V_100 ;
}
static void F_64 ( struct V_10 * V_11 )
{
int V_177 ;
V_11 -> V_42 = V_178 | V_179 | V_180 |
V_181 | V_182 | V_183 ;
V_11 -> V_117 . V_118 = V_119 ;
F_22 ( V_11 , ! V_60 ) ;
V_177 = F_46 ( V_11 ) ;
F_65 ( ! V_177 ) ;
if ( V_177 )
V_177 = F_49 ( V_11 ) ;
if ( V_177 )
V_177 = F_51 ( V_11 ) ;
if ( V_177 )
V_177 = F_53 ( V_11 ) ;
if ( V_177 )
V_177 = F_56 ( V_11 ) ;
if ( V_177 )
V_177 = F_60 ( V_11 ) ;
F_66 ( V_11 ) ;
if ( V_184 ) {
F_67 ( V_185 ) ;
F_23 () ;
if ( F_68 () & V_185 )
V_11 -> V_42 |= V_186 ;
}
#ifndef F_69
if ( V_187 ) {
V_11 -> V_188 = F_70 () ;
if ( V_189 )
V_11 -> V_188 >>= F_71 ( F_72 () ) - 1 ;
}
#endif
}
static inline void F_73 ( struct V_10 * V_11 , unsigned int V_76 )
{
switch ( V_11 -> V_66 & V_190 ) {
case V_191 :
V_11 -> V_89 = V_192 ;
V_193 [ V_76 ] = L_4 ;
V_11 -> V_23 |= V_194 | V_195 ;
V_11 -> V_42 = V_96 | V_196 |
V_197 ;
if ( F_6 () )
V_11 -> V_42 |= V_44 ;
V_11 -> V_61 = 64 ;
break;
case V_198 :
if ( ( V_11 -> V_66 & V_67 ) == V_199 ) {
if ( F_32 () ) {
V_11 -> V_89 = V_200 ;
V_193 [ V_76 ] = L_5 ;
} else {
V_11 -> V_89 = V_201 ;
V_193 [ V_76 ] = L_6 ;
}
} else {
V_11 -> V_89 = V_202 ;
V_193 [ V_76 ] = L_7 ;
}
V_11 -> V_23 |= V_194 | V_195 ;
V_11 -> V_42 = V_96 | V_196 |
V_197 ;
if ( F_6 () )
V_11 -> V_42 |= V_44 ;
V_11 -> V_61 = 64 ;
break;
case V_203 :
if ( F_47 () & V_204 ) {
if ( ( V_11 -> V_66 & V_67 ) >=
V_205 ) {
V_11 -> V_89 = V_206 ;
V_193 [ V_76 ] = L_8 ;
} else {
V_11 -> V_89 = V_207 ;
V_193 [ V_76 ] = L_9 ;
}
} else {
int V_208 = F_47 () & V_209 ;
int V_210 ;
switch ( V_208 ) {
case V_211 :
case V_212 :
case V_213 :
V_210 = 1 ;
break;
default:
V_210 = 0 ;
break;
}
if ( ( V_11 -> V_66 & V_67 ) >=
V_205 ) {
V_11 -> V_89 = V_210 ? V_214 : V_215 ;
V_193 [ V_76 ] = V_210 ? L_10 : L_11 ;
} else {
V_11 -> V_89 = V_210 ? V_216 : V_217 ;
V_193 [ V_76 ] = V_210 ? L_12 : L_13 ;
}
}
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_194 ;
V_11 -> V_42 = V_218 | V_44 | V_112 |
V_106 | V_219 |
V_182 ;
V_11 -> V_61 = 48 ;
break;
case V_220 :
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_194 ;
V_11 -> V_42 = V_218 ;
V_11 -> V_61 = 32 ;
switch ( V_11 -> V_66 & 0xf0 ) {
case V_221 :
V_11 -> V_89 = V_222 ;
V_193 [ V_76 ] = L_14 ;
break;
case V_223 :
V_11 -> V_89 = V_224 ;
V_193 [ V_76 ] = L_15 ;
break;
case V_225 :
if ( ( V_11 -> V_66 & 0xf ) < 0x3 ) {
V_11 -> V_89 = V_226 ;
V_193 [ V_76 ] = L_16 ;
} else {
V_11 -> V_89 = V_227 ;
V_193 [ V_76 ] = L_17 ;
}
break;
case V_228 :
if ( ( V_11 -> V_66 & 0xf ) < 0x4 ) {
V_11 -> V_89 = V_229 ;
V_193 [ V_76 ] = L_18 ;
} else {
V_11 -> V_89 = V_230 ;
V_11 -> V_42 |= V_182 ;
V_193 [ V_76 ] = L_19 ;
}
break;
default:
F_74 ( V_231 L_20 ) ;
V_11 -> V_89 = V_232 ;
V_193 [ V_76 ] = L_21 ;
break;
}
break;
case V_233 :
V_11 -> V_89 = V_234 ;
V_193 [ V_76 ] = L_22 ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_194 ;
V_11 -> V_42 = V_218 | V_44 | V_112 |
V_182 ;
V_11 -> V_61 = 32 ;
break;
case V_235 :
V_11 -> V_89 = V_236 ;
V_193 [ V_76 ] = L_23 ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_194 ;
V_11 -> V_42 = V_218 | V_44 | V_112 |
V_182 ;
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
case V_237 :
V_11 -> V_23 |= V_194 | V_195 ;
V_11 -> V_42 = V_96 | V_238 ;
if ( ( V_11 -> V_66 & 0xf0 ) == ( V_239 & 0xf0 ) ) {
V_11 -> V_89 = V_240 ;
V_193 [ V_76 ] = L_24 ;
V_11 -> V_61 = 64 ;
} else {
switch ( V_11 -> V_66 & V_67 ) {
case V_241 :
V_11 -> V_89 = V_242 ;
V_193 [ V_76 ] = L_25 ;
V_11 -> V_61 = 32 ;
break;
case V_243 :
V_11 -> V_89 = V_244 ;
V_193 [ V_76 ] = L_26 ;
V_11 -> V_61 = 64 ;
break;
}
}
break;
case V_245 :
V_11 -> V_89 = V_246 ;
V_193 [ V_76 ] = L_27 ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_194 ;
V_11 -> V_42 = V_218 | V_44 | V_112 |
V_182 ;
V_11 -> V_61 = 48 ;
break;
case V_247 :
V_11 -> V_89 = V_248 ;
V_193 [ V_76 ] = L_28 ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_194 ;
V_11 -> V_42 = V_218 | V_182 ;
if ( ! ( V_11 -> V_66 & 0x08 ) )
V_11 -> V_42 |= V_44 | V_112 ;
V_11 -> V_61 = 48 ;
break;
case V_249 :
V_11 -> V_89 = V_250 ;
V_193 [ V_76 ] = L_29 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_218 | V_44 | V_112 |
V_182 ;
V_11 -> V_61 = 48 ;
break;
case V_251 :
V_11 -> V_89 = V_252 ;
V_193 [ V_76 ] = L_30 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_218 | V_44 | V_112 |
V_106 | V_182 ;
V_11 -> V_61 = 48 ;
break;
case V_253 :
V_11 -> V_89 = V_254 ;
V_193 [ V_76 ] = L_31 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_218 | V_44 | V_112 |
V_106 | V_182 ;
V_11 -> V_61 = 48 ;
break;
case V_255 :
V_11 -> V_89 = V_256 ;
V_193 [ V_76 ] = L_32 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_218 | V_44 | V_112 |
V_181 | V_182 ;
V_11 -> V_61 = 48 ;
break;
case V_257 :
V_11 -> V_89 = V_258 ;
V_193 [ V_76 ] = L_33 ;
F_42 ( V_11 , V_84 ) ;
V_11 -> V_23 |= V_194 | V_195 ;
V_11 -> V_42 = V_96 | V_44 |
V_182 ;
V_11 -> V_61 = 32 ;
break;
case V_259 :
V_11 -> V_89 = V_260 ;
V_193 [ V_76 ] = L_34 ;
F_42 ( V_11 , V_84 ) ;
V_11 -> V_23 |= V_194 | V_195 ;
V_11 -> V_42 = V_96 | V_44 |
V_182 ;
V_11 -> V_61 = 32 ;
break;
case V_261 :
V_11 -> V_89 = V_262 ;
V_193 [ V_76 ] = L_35 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_218 | V_44 | V_112 |
V_182 ;
V_11 -> V_61 = ( F_75 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_263 :
V_11 -> V_89 = V_264 ;
V_193 [ V_76 ] = L_36 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_96 | V_178 |
V_44 | V_112 |
V_182 ;
V_11 -> V_61 = 384 ;
break;
case V_265 :
V_11 -> V_89 = V_266 ;
V_193 [ V_76 ] = L_37 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_96 | V_179 | V_178 |
V_44 | V_112 |
V_180 | V_106 |
V_182 ;
V_11 -> V_61 = 64 ;
break;
case V_267 :
V_11 -> V_89 = V_268 ;
V_193 [ V_76 ] = L_38 ;
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_96 | V_179 | V_178 |
V_44 | V_112 |
V_180 | V_106 |
V_182 ;
V_11 -> V_61 = 64 ;
break;
case V_269 :
if ( ( ( V_11 -> V_66 >> 4 ) & 0x0f ) > 2 ) {
V_11 -> V_89 = V_270 ;
V_193 [ V_76 ] = L_39 ;
} else {
V_11 -> V_89 = V_271 ;
V_193 [ V_76 ] = L_40 ;
}
F_42 ( V_11 , V_82 ) ;
V_11 -> V_42 = V_96 | V_179 | V_178 |
V_44 | V_112 |
V_180 | V_106 |
V_182 ;
V_11 -> V_61 = 64 ;
break;
case V_272 :
switch ( V_11 -> V_66 & V_67 ) {
case V_273 :
V_11 -> V_89 = V_274 ;
V_193 [ V_76 ] = L_41 ;
F_36 ( V_76 , L_42 ) ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_194 ;
break;
case V_275 :
V_11 -> V_89 = V_274 ;
V_193 [ V_76 ] = L_41 ;
F_36 ( V_76 , L_43 ) ;
F_42 ( V_11 , V_83 ) ;
V_11 -> V_23 |= V_194 ;
break;
case V_276 :
V_11 -> V_89 = V_277 ;
V_193 [ V_76 ] = L_44 ;
F_36 ( V_76 , L_45 ) ;
F_42 ( V_11 , V_27 ) ;
break;
case V_278 :
case V_279 :
V_11 -> V_89 = V_277 ;
V_193 [ V_76 ] = L_44 ;
F_36 ( V_76 , L_46 ) ;
F_42 ( V_11 , V_27 ) ;
break;
}
V_11 -> V_42 = V_218 |
V_44 | V_182 |
V_112 ;
V_11 -> V_61 = 64 ;
V_11 -> V_280 = V_281 ;
break;
case V_282 :
F_64 ( V_11 ) ;
V_11 -> V_89 = V_283 ;
switch ( V_11 -> V_66 & V_67 ) {
case V_284 :
V_193 [ V_76 ] = L_47 ;
break;
}
break;
}
}
static inline void F_76 ( struct V_10 * V_11 , unsigned int V_76 )
{
V_11 -> V_280 = V_281 ;
switch ( V_11 -> V_66 & V_190 ) {
case V_285 :
V_11 -> V_280 = V_286 ;
V_11 -> V_89 = V_287 ;
V_193 [ V_76 ] = L_48 ;
break;
case V_288 :
V_11 -> V_89 = V_289 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_49 ;
break;
case V_290 :
case V_291 :
V_11 -> V_89 = V_292 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_50 ;
break;
case V_293 :
case V_294 :
V_11 -> V_89 = V_295 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_51 ;
break;
case V_296 :
V_11 -> V_89 = V_297 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_52 ;
break;
case V_298 :
V_11 -> V_89 = V_299 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_53 ;
break;
case V_300 :
V_11 -> V_89 = V_301 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_54 ;
break;
case V_302 :
V_11 -> V_89 = V_303 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_55 ;
break;
case V_304 :
V_11 -> V_89 = V_303 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_56 ;
break;
case V_305 :
V_11 -> V_89 = V_306 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_57 ;
break;
case V_307 :
V_11 -> V_89 = V_65 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_58 ;
break;
case V_308 :
V_11 -> V_89 = V_309 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_59 ;
break;
case V_310 :
V_11 -> V_89 = V_311 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_60 ;
break;
case V_312 :
V_11 -> V_89 = V_313 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_61 ;
break;
case V_314 :
V_11 -> V_89 = V_315 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_62 ;
break;
case V_316 :
V_11 -> V_89 = V_317 ;
V_11 -> V_280 = V_286 ;
V_193 [ V_76 ] = L_63 ;
break;
case V_318 :
V_11 -> V_89 = V_319 ;
V_193 [ V_76 ] = L_64 ;
break;
case V_320 :
V_11 -> V_89 = V_319 ;
V_193 [ V_76 ] = L_65 ;
break;
case V_321 :
V_11 -> V_89 = V_90 ;
V_193 [ V_76 ] = L_66 ;
break;
case V_322 :
V_11 -> V_89 = V_90 ;
V_193 [ V_76 ] = L_67 ;
break;
case V_323 :
V_11 -> V_89 = V_91 ;
V_193 [ V_76 ] = L_68 ;
break;
case V_324 :
V_11 -> V_89 = V_325 ;
V_193 [ V_76 ] = L_69 ;
break;
}
F_64 ( V_11 ) ;
F_77 () ;
}
static inline void F_78 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_64 ( V_11 ) ;
switch ( V_11 -> V_66 & V_190 ) {
case V_326 :
case V_327 :
V_11 -> V_89 = V_328 ;
switch ( ( V_11 -> V_66 >> 24 ) & 0xff ) {
case 0 :
V_193 [ V_76 ] = L_70 ;
break;
case 1 :
V_193 [ V_76 ] = L_71 ;
break;
case 2 :
V_193 [ V_76 ] = L_72 ;
break;
case 3 :
V_193 [ V_76 ] = L_73 ;
break;
case 4 :
V_193 [ V_76 ] = L_74 ;
if ( ( V_11 -> V_66 & V_67 ) == 2 )
V_193 [ V_76 ] = L_75 ;
break;
case 5 :
V_193 [ V_76 ] = L_76 ;
break;
default:
V_193 [ V_76 ] = L_77 ;
break;
}
break;
}
}
static inline void F_79 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_64 ( V_11 ) ;
V_11 -> V_280 = V_281 ;
switch ( V_11 -> V_66 & V_190 ) {
case V_329 :
V_11 -> V_89 = V_330 ;
V_193 [ V_76 ] = L_78 ;
if ( ( V_11 -> V_66 & V_67 ) < 0x02 )
V_11 -> V_42 &= ~ ( V_44 | V_112 ) ;
break;
case V_331 :
V_11 -> V_89 = V_332 ;
V_193 [ V_76 ] = L_79 ;
break;
}
}
static inline void F_80 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_64 ( V_11 ) ;
switch ( V_11 -> V_66 & V_190 ) {
case V_333 :
V_11 -> V_89 = V_334 ;
V_193 [ V_76 ] = L_80 ;
V_11 -> V_117 . V_335 = 8 ;
V_11 -> V_61 = 64 ;
break;
}
}
static inline void F_81 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_64 ( V_11 ) ;
switch ( V_11 -> V_66 & V_190 ) {
case V_336 :
V_11 -> V_89 = V_337 ;
V_193 [ V_76 ] = L_81 ;
F_42 ( V_11 , V_26 ) ;
break;
}
}
static inline void F_82 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_64 ( V_11 ) ;
switch ( V_11 -> V_66 & V_190 ) {
case V_338 :
case V_339 :
V_11 -> V_89 = V_340 ;
V_193 [ V_76 ] = L_82 ;
F_36 ( V_76 , L_83 ) ;
break;
case V_341 :
case V_342 :
case V_343 :
V_11 -> V_89 = V_344 ;
V_193 [ V_76 ] = L_84 ;
F_36 ( V_76 , L_85 ) ;
break;
case V_345 : {
int V_346 = V_11 -> V_66 & V_67 ;
if ( V_346 >= V_347 &&
V_346 <= V_348 ) {
V_11 -> V_89 = V_349 ;
V_193 [ V_76 ] = L_86 ;
F_36 ( V_76 , L_87 ) ;
} else {
V_11 -> V_89 = V_350 ;
V_193 [ V_76 ] = L_88 ;
F_36 ( V_76 , L_89 ) ;
}
break;
}
case V_351 :
case V_352 :
V_11 -> V_89 = V_353 ;
V_193 [ V_76 ] = L_90 ;
F_36 ( V_76 , L_91 ) ;
V_11 -> V_42 |= V_134 ;
break;
}
}
static inline void F_83 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_64 ( V_11 ) ;
switch ( V_11 -> V_66 & V_190 ) {
case V_354 :
case V_355 :
case V_356 :
V_11 -> V_89 = V_357 ;
V_193 [ V_76 ] = L_92 ;
goto V_358;
case V_359 :
case V_360 :
case V_361 :
case V_362 :
V_11 -> V_89 = V_363 ;
V_193 [ V_76 ] = L_93 ;
V_358:
F_36 ( V_76 , L_94 ) ;
break;
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
V_11 -> V_89 = V_369 ;
V_193 [ V_76 ] = L_95 ;
F_36 ( V_76 , L_96 ) ;
break;
case V_370 :
case V_371 :
V_11 -> V_89 = V_372 ;
V_193 [ V_76 ] = L_97 ;
F_36 ( V_76 , L_98 ) ;
break;
default:
F_74 ( V_231 L_99 ) ;
V_11 -> V_89 = V_373 ;
break;
}
}
static inline void F_84 ( struct V_10 * V_11 , unsigned int V_76 )
{
F_64 ( V_11 ) ;
V_11 -> V_42 &= ~ V_180 ;
F_65 ( ! F_85 ( V_374 ) || V_374 ) ;
switch ( V_11 -> V_66 & V_190 ) {
case V_375 :
V_11 -> V_89 = V_376 ;
V_11 -> V_280 = V_281 ;
V_193 [ V_76 ] = L_100 ;
break;
default:
F_48 ( L_101 ) ;
break;
}
}
static inline void F_86 ( struct V_10 * V_11 , int V_76 )
{
F_64 ( V_11 ) ;
if ( ( V_11 -> V_66 & V_190 ) == V_377 ) {
V_11 -> V_89 = V_328 ;
V_193 [ V_76 ] = L_102 ;
return;
}
V_11 -> V_42 = ( V_96 |
V_178 |
V_180 |
V_181 |
V_106 |
V_110 |
V_182 ) ;
switch ( V_11 -> V_66 & V_190 ) {
case V_378 :
case V_379 :
case V_380 :
V_11 -> V_89 = V_381 ;
V_193 [ V_76 ] = L_103 ;
break;
case V_382 :
case V_383 :
V_11 -> V_89 = V_381 ;
V_193 [ V_76 ] = L_104 ;
break;
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
V_11 -> V_89 = V_392 ;
V_193 [ V_76 ] = L_105 ;
break;
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
V_11 -> V_89 = V_392 ;
V_193 [ V_76 ] = L_106 ;
break;
default:
F_26 ( L_107 ,
V_11 -> V_66 ) ;
V_11 -> V_89 = V_392 ;
break;
}
if ( V_11 -> V_89 == V_381 ) {
F_42 ( V_11 , V_29 ) ;
V_11 -> V_42 |= ( V_44 | V_134 | V_183 ) ;
V_11 -> V_61 = ( ( F_44 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_42 ( V_11 , V_27 ) ;
V_11 -> V_61 = ( ( F_50 () >> 25 ) & 0x3f ) + 1 ;
}
V_11 -> V_165 = 0xf ;
}
void F_87 ( void )
{
struct V_10 * V_11 = & V_64 ;
unsigned int V_76 = F_88 () ;
V_11 -> V_66 = V_406 ;
V_11 -> V_2 = V_6 ;
V_11 -> V_89 = V_373 ;
V_11 -> V_280 = V_286 ;
V_11 -> V_17 = V_407 ;
V_11 -> V_23 = V_408 | V_409 | V_410 ;
V_11 -> V_66 = F_89 () ;
switch ( V_11 -> V_66 & V_411 ) {
case V_412 :
F_73 ( V_11 , V_76 ) ;
break;
case V_413 :
F_76 ( V_11 , V_76 ) ;
break;
case V_414 :
F_78 ( V_11 , V_76 ) ;
break;
case V_415 :
F_79 ( V_11 , V_76 ) ;
break;
case V_416 :
F_82 ( V_11 , V_76 ) ;
break;
case V_417 :
F_80 ( V_11 , V_76 ) ;
break;
case V_418 :
F_81 ( V_11 , V_76 ) ;
break;
case V_419 :
F_83 ( V_11 , V_76 ) ;
break;
case V_420 :
F_84 ( V_11 , V_76 ) ;
break;
case V_421 :
F_86 ( V_11 , V_76 ) ;
break;
}
F_65 ( ! V_193 [ V_76 ] ) ;
F_65 ( V_11 -> V_89 == V_373 ) ;
F_65 ( F_28 () != V_11 -> V_89 ) ;
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
if ( V_187 ) {
V_11 -> V_422 = ( ( F_90 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_42 |= V_423 ;
}
else
V_11 -> V_422 = 1 ;
if ( V_424 ) {
V_11 -> V_8 = F_7 () ;
F_91 ( V_11 -> V_8 & V_425 ,
L_108 ) ;
}
F_37 ( V_11 ) ;
#ifdef F_92
if ( V_76 == 0 )
V_426 = ~ ( ( 1ull << V_427 ) - 1 ) ;
#endif
}
void F_93 ( void )
{
struct V_10 * V_11 = & V_64 ;
F_26 ( L_109 ,
F_88 () , V_11 -> V_66 , F_94 () ) ;
if ( V_11 -> V_42 & V_44 )
F_74 ( V_231 L_110 , V_11 -> V_2 ) ;
if ( V_424 )
F_26 ( L_111 , V_11 -> V_8 ) ;
}
