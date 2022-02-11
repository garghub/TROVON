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
static inline void F_3 ( void )
{
struct V_10 * V_11 = & V_12 ;
switch ( F_4 () ) {
case V_13 :
if ( ( V_11 -> V_14 & V_15 ) <= V_16 )
F_5 ( F_6 () | V_17 ) ;
break;
default:
break;
}
}
void T_1 F_7 ( void )
{
F_3 () ;
}
static inline int F_8 ( void )
{
#ifdef F_9
extern unsigned long V_18 ( unsigned long ) ;
unsigned long V_19 , V_20 ;
unsigned long V_21 = F_10 () ;
V_19 = V_18 ( V_22 ) ;
F_11 ( V_21 ^ V_23 ) ;
V_20 = V_18 ( V_22 ) ;
F_11 ( V_21 ) ;
return V_19 != V_20 ;
#else
return 0 ;
#endif
}
static inline void F_12 ( int V_24 , const char * V_25 )
{
if ( V_24 == 0 )
V_26 = V_25 ;
}
static inline unsigned long F_13 ( void )
{
unsigned long V_27 , V_28 ;
V_27 = F_14 () ;
F_15 ( V_29 ) ;
V_28 = F_16 ( V_30 ) ;
F_17 ( V_27 ) ;
return V_28 ;
}
static inline int F_18 ( void )
{
return ( ( F_13 () & V_31 ) != V_32 ) ;
}
static inline unsigned long F_19 ( void )
{
unsigned long V_33 , V_34 , V_35 ;
V_33 = F_14 () ;
F_15 ( V_36 ) ;
V_34 = F_20 () ;
F_21 () ;
V_35 = F_22 () ;
F_23 ( V_34 ) ;
F_17 ( V_33 ) ;
return V_35 ;
}
static inline void F_24 ( struct V_10 * V_11 )
{
#ifdef F_25
F_26 ( 0x3fffffffffffe000ULL ) ;
F_27 () ;
V_11 -> V_37 = F_28 ( F_29 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void F_30 ( struct V_10 * V_11 , unsigned int V_38 )
{
switch ( V_38 ) {
case V_39 :
V_11 -> V_40 |= V_41 | V_39 ;
case V_42 :
V_11 -> V_40 |= V_43 | V_42 ;
case V_44 :
V_11 -> V_40 |= V_44 ;
case V_45 :
V_11 -> V_40 |= V_45 ;
case V_46 :
V_11 -> V_40 |= V_47 | V_46 ;
break;
case V_41 :
V_11 -> V_40 |= V_41 ;
case V_43 :
V_11 -> V_40 |= V_43 ;
case V_47 :
V_11 -> V_40 |= V_47 ;
break;
}
}
static void F_31 ( struct V_10 * V_11 , int V_48 )
{
unsigned int V_49 ;
switch ( V_11 -> V_50 ) {
case V_51 :
case V_52 :
V_49 = F_32 () ;
if ( V_48 )
F_33 ( V_49 | V_53 ) ;
else
F_33 ( V_49 & ~ V_53 ) ;
F_27 () ;
break;
}
}
static inline unsigned int F_34 ( struct V_10 * V_11 )
{
unsigned int V_54 ;
int V_38 ;
V_54 = F_35 () ;
if ( ( ( ( V_54 & V_55 ) >> 7 ) == 1 ) ||
( ( ( V_54 & V_55 ) >> 7 ) == 4 ) )
V_11 -> V_3 |= V_56 ;
V_38 = ( V_54 & V_57 ) >> 13 ;
switch ( V_38 ) {
case 0 :
switch ( ( V_54 & V_58 ) >> 10 ) {
case 0 :
F_30 ( V_11 , V_43 ) ;
break;
case 1 :
F_30 ( V_11 , V_41 ) ;
break;
default:
goto V_59;
}
break;
case 2 :
switch ( ( V_54 & V_58 ) >> 10 ) {
case 0 :
F_30 ( V_11 , V_42 ) ;
break;
case 1 :
F_30 ( V_11 , V_39 ) ;
break;
default:
goto V_59;
}
break;
default:
goto V_59;
}
return V_54 & V_60 ;
V_59:
F_36 ( V_61 , V_54 ) ;
}
static inline unsigned int F_37 ( struct V_10 * V_11 )
{
unsigned int V_62 ;
V_62 = F_38 () ;
if ( V_62 & V_63 )
V_11 -> V_6 |= V_64 ;
if ( V_62 & V_65 )
V_11 -> V_3 |= V_66 ;
if ( V_62 & V_67 )
V_11 -> V_6 |= V_68 ;
if ( V_62 & V_69 )
V_11 -> V_3 |= V_70 ;
if ( V_62 & V_71 ) {
V_11 -> V_3 |= V_4 ;
V_11 -> V_3 |= V_72 ;
}
if ( V_73 ) {
V_11 -> V_74 = ( ( V_62 & V_75 ) >> 25 ) + 1 ;
V_11 -> V_76 = V_11 -> V_74 ;
V_11 -> V_77 = 0 ;
}
return V_62 & V_60 ;
}
static inline unsigned int F_39 ( struct V_10 * V_11 )
{
unsigned int V_78 ;
V_78 = F_40 () ;
if ( V_78 & V_79 )
V_11 -> V_80 . V_81 &= ~ V_82 ;
return V_78 & V_60 ;
}
static inline unsigned int F_41 ( struct V_10 * V_11 )
{
unsigned int V_83 ;
V_83 = F_42 () ;
if ( V_83 & V_84 ) {
V_11 -> V_6 |= V_85 ;
V_11 -> V_3 |= V_86 ;
}
if ( V_83 & V_87 )
V_11 -> V_3 |= V_86 ;
if ( V_83 & V_88 )
V_11 -> V_6 |= V_7 ;
if ( V_83 & V_89 )
V_11 -> V_6 |= V_8 ;
if ( V_83 & V_90 )
V_11 -> V_3 |= V_91 ;
if ( V_83 & V_92 )
V_11 -> V_3 |= V_93 ;
if ( V_83 & V_94 )
V_11 -> V_6 |= V_95 ;
if ( V_83 & V_96 )
V_11 -> V_3 |= V_97 ;
if ( V_83 & V_98 )
V_11 -> V_3 |= V_99 ;
if ( V_83 & V_100 )
V_11 -> V_6 |= V_101 ;
if ( V_83 & V_102 )
V_11 -> V_3 |= V_103 ;
if ( V_83 & V_104 )
V_11 -> V_6 |= V_105 ;
return V_83 & V_60 ;
}
static inline unsigned int F_43 ( struct V_10 * V_11 )
{
unsigned int V_106 ;
unsigned int V_107 ;
unsigned int V_108 ;
unsigned int V_109 = V_110 ;
V_106 = F_44 () ;
if ( V_73 ) {
if ( ( ( V_106 & V_111 ) >> 29 ) == 2 )
V_11 -> V_3 |= V_112 ;
V_108 = V_106 & V_113 ;
switch ( V_108 ) {
case V_114 :
V_11 -> V_74 += ( V_106 & V_115 ) * 0x40 ;
V_11 -> V_76 = V_11 -> V_74 ;
break;
case V_116 :
V_11 -> V_76 +=
( ( V_106 & V_117 ) >>
V_118 ) * 0x40 ;
V_11 -> V_74 = V_11 -> V_76 ;
V_109 = V_119 ;
case V_120 :
V_107 = ( V_106 & ~ V_109 ) |
( F_45 ( V_108 ) <<
V_121 ) ;
F_46 ( V_107 ) ;
F_27 () ;
V_106 = F_44 () ;
if ( V_106 != V_107 ) {
F_47 ( L_1 ,
V_122 , V_106 ) ;
F_31 ( V_11 , 0 ) ;
break;
}
V_11 -> V_77 = 1 <<
( ( V_106 & V_123 ) >>
V_124 ) ;
V_11 -> V_125 = ( ( V_106 & V_126 ) >>
V_127 ) + 2 ;
V_11 -> V_74 += V_11 -> V_125 * V_11 -> V_77 ;
break;
}
}
V_11 -> V_128 = ( V_106 >> 16 ) & 0xff ;
return V_106 & V_60 ;
}
static inline unsigned int F_48 ( struct V_10 * V_11 )
{
unsigned int V_129 ;
V_129 = F_20 () ;
V_129 &= ~ V_130 ;
F_23 ( V_129 ) ;
if ( V_129 & V_131 )
V_11 -> V_3 |= V_132 ;
return V_129 & V_60 ;
}
static void F_49 ( struct V_10 * V_11 )
{
int V_133 ;
V_11 -> V_3 = V_134 | V_135 | V_136 |
V_137 | V_138 | V_139 ;
V_11 -> V_80 . V_81 = V_82 ;
F_31 ( V_11 , 1 ) ;
V_133 = F_34 ( V_11 ) ;
F_50 ( ! V_133 ) ;
if ( V_133 )
V_133 = F_37 ( V_11 ) ;
if ( V_133 )
V_133 = F_39 ( V_11 ) ;
if ( V_133 )
V_133 = F_41 ( V_11 ) ;
if ( V_133 )
V_133 = F_43 ( V_11 ) ;
if ( V_133 )
V_133 = F_48 ( V_11 ) ;
F_51 ( V_11 ) ;
#ifndef F_52
if ( V_140 ) {
V_11 -> V_141 = F_53 () ;
if ( V_142 )
V_11 -> V_141 >>= F_54 ( F_55 () ) - 1 ;
}
#endif
}
static inline void F_56 ( struct V_10 * V_11 , unsigned int V_24 )
{
switch ( V_11 -> V_14 & V_143 ) {
case V_144 :
V_11 -> V_50 = V_145 ;
V_146 [ V_24 ] = L_2 ;
V_11 -> V_3 = V_56 | V_147 |
V_148 ;
if ( F_18 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_74 = 64 ;
break;
case V_149 :
if ( ( V_11 -> V_14 & V_15 ) == V_150 ) {
if ( F_8 () ) {
V_11 -> V_50 = V_151 ;
V_146 [ V_24 ] = L_3 ;
} else {
V_11 -> V_50 = V_152 ;
V_146 [ V_24 ] = L_4 ;
}
} else {
V_11 -> V_50 = V_153 ;
V_146 [ V_24 ] = L_5 ;
}
V_11 -> V_3 = V_56 | V_147 |
V_148 ;
if ( F_18 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_74 = 64 ;
break;
case V_154 :
if ( F_35 () & V_155 ) {
if ( ( V_11 -> V_14 & V_15 ) >=
V_156 ) {
V_11 -> V_50 = V_157 ;
V_146 [ V_24 ] = L_6 ;
} else {
V_11 -> V_50 = V_158 ;
V_146 [ V_24 ] = L_7 ;
}
} else {
int V_159 = F_35 () & V_160 ;
int V_161 ;
switch ( V_159 ) {
case V_162 :
case V_163 :
case V_164 :
V_161 = 1 ;
break;
default:
V_161 = 0 ;
break;
}
if ( ( V_11 -> V_14 & V_15 ) >=
V_156 ) {
V_11 -> V_50 = V_161 ? V_165 : V_166 ;
V_146 [ V_24 ] = V_161 ? L_8 : L_9 ;
} else {
V_11 -> V_50 = V_161 ? V_167 : V_168 ;
V_146 [ V_24 ] = V_161 ? L_10 : L_11 ;
}
}
F_30 ( V_11 , V_46 ) ;
V_11 -> V_3 = V_169 | V_4 | V_72 |
V_66 | V_170 |
V_138 ;
V_11 -> V_74 = 48 ;
break;
case V_171 :
F_30 ( V_11 , V_46 ) ;
V_11 -> V_3 = V_169 ;
V_11 -> V_74 = 32 ;
switch ( V_11 -> V_14 & 0xf0 ) {
case V_172 :
V_11 -> V_50 = V_173 ;
V_146 [ V_24 ] = L_12 ;
break;
case V_174 :
V_11 -> V_50 = V_175 ;
V_146 [ V_24 ] = L_13 ;
break;
case V_176 :
if ( ( V_11 -> V_14 & 0xf ) < 0x3 ) {
V_11 -> V_50 = V_177 ;
V_146 [ V_24 ] = L_14 ;
} else {
V_11 -> V_50 = V_178 ;
V_146 [ V_24 ] = L_15 ;
}
break;
case V_179 :
if ( ( V_11 -> V_14 & 0xf ) < 0x4 ) {
V_11 -> V_50 = V_180 ;
V_146 [ V_24 ] = L_16 ;
} else {
V_11 -> V_50 = V_181 ;
V_11 -> V_3 |= V_138 ;
V_146 [ V_24 ] = L_17 ;
}
break;
default:
F_57 ( V_182 L_18 ) ;
V_11 -> V_50 = V_183 ;
V_146 [ V_24 ] = L_19 ;
break;
}
break;
case V_184 :
V_11 -> V_50 = V_185 ;
V_146 [ V_24 ] = L_20 ;
F_30 ( V_11 , V_46 ) ;
V_11 -> V_3 = V_169 | V_4 | V_72 |
V_138 ;
V_11 -> V_74 = 32 ;
break;
case V_186 :
V_11 -> V_50 = V_187 ;
V_146 [ V_24 ] = L_21 ;
F_30 ( V_11 , V_46 ) ;
V_11 -> V_3 = V_169 | V_4 | V_72 |
V_138 ;
V_11 -> V_74 = 48 ;
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
case V_188 :
V_11 -> V_3 = V_56 | V_189 ;
if ( ( V_11 -> V_14 & 0xf0 ) == ( V_190 & 0xf0 ) ) {
V_11 -> V_50 = V_191 ;
V_146 [ V_24 ] = L_22 ;
V_11 -> V_74 = 64 ;
} else {
switch ( V_11 -> V_14 & V_15 ) {
case V_192 :
V_11 -> V_50 = V_193 ;
V_146 [ V_24 ] = L_23 ;
V_11 -> V_74 = 32 ;
break;
case V_194 :
V_11 -> V_50 = V_195 ;
V_146 [ V_24 ] = L_24 ;
V_11 -> V_74 = 64 ;
break;
}
}
break;
case V_196 :
V_11 -> V_50 = V_197 ;
V_146 [ V_24 ] = L_25 ;
F_30 ( V_11 , V_46 ) ;
V_11 -> V_3 = V_169 | V_4 | V_72 |
V_138 ;
V_11 -> V_74 = 48 ;
break;
case V_198 :
V_11 -> V_50 = V_199 ;
V_146 [ V_24 ] = L_26 ;
F_30 ( V_11 , V_46 ) ;
V_11 -> V_3 = V_169 | V_138 ;
if ( ! ( V_11 -> V_14 & 0x08 ) )
V_11 -> V_3 |= V_4 | V_72 ;
V_11 -> V_74 = 48 ;
break;
case V_200 :
V_11 -> V_50 = V_201 ;
V_146 [ V_24 ] = L_27 ;
F_30 ( V_11 , V_45 ) ;
V_11 -> V_3 = V_169 | V_4 | V_72 |
V_138 ;
V_11 -> V_74 = 48 ;
break;
case V_202 :
V_11 -> V_50 = V_203 ;
V_146 [ V_24 ] = L_28 ;
F_30 ( V_11 , V_45 ) ;
V_11 -> V_3 = V_169 | V_4 | V_72 |
V_66 | V_138 ;
V_11 -> V_74 = 48 ;
break;
case V_204 :
V_11 -> V_50 = V_205 ;
V_146 [ V_24 ] = L_29 ;
F_30 ( V_11 , V_45 ) ;
V_11 -> V_3 = V_169 | V_4 | V_72 |
V_66 | V_138 ;
V_11 -> V_74 = 48 ;
break;
case V_206 :
V_11 -> V_50 = V_207 ;
V_146 [ V_24 ] = L_30 ;
F_30 ( V_11 , V_45 ) ;
V_11 -> V_3 = V_169 | V_4 | V_72 |
V_137 | V_138 ;
V_11 -> V_74 = 48 ;
break;
case V_208 :
V_11 -> V_50 = V_209 ;
V_146 [ V_24 ] = L_31 ;
F_30 ( V_11 , V_47 ) ;
V_11 -> V_3 = V_56 | V_4 |
V_138 ;
V_11 -> V_74 = 32 ;
break;
case V_210 :
V_11 -> V_50 = V_211 ;
V_146 [ V_24 ] = L_32 ;
F_30 ( V_11 , V_47 ) ;
V_11 -> V_3 = V_56 | V_4 |
V_138 ;
V_11 -> V_74 = 32 ;
break;
case V_212 :
V_11 -> V_50 = V_213 ;
V_146 [ V_24 ] = L_33 ;
F_30 ( V_11 , V_45 ) ;
V_11 -> V_3 = V_169 | V_4 | V_72 |
V_138 ;
V_11 -> V_74 = ( F_58 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_214 :
V_11 -> V_50 = V_215 ;
V_146 [ V_24 ] = L_34 ;
F_30 ( V_11 , V_45 ) ;
V_11 -> V_3 = V_56 | V_134 |
V_4 | V_72 |
V_138 ;
V_11 -> V_74 = 384 ;
break;
case V_216 :
V_11 -> V_50 = V_217 ;
V_146 [ V_24 ] = L_35 ;
F_30 ( V_11 , V_45 ) ;
V_11 -> V_3 = V_56 | V_135 | V_134 |
V_4 | V_72 |
V_136 | V_66 |
V_138 ;
V_11 -> V_74 = 64 ;
break;
case V_218 :
V_11 -> V_50 = V_219 ;
V_146 [ V_24 ] = L_36 ;
F_30 ( V_11 , V_45 ) ;
V_11 -> V_3 = V_56 | V_135 | V_134 |
V_4 | V_72 |
V_136 | V_66 |
V_138 ;
V_11 -> V_74 = 64 ;
break;
case V_220 :
V_11 -> V_50 = V_221 ;
V_146 [ V_24 ] = L_37 ;
F_30 ( V_11 , V_45 ) ;
V_11 -> V_3 = V_56 | V_135 | V_134 |
V_4 | V_72 |
V_136 | V_66 |
V_138 ;
V_11 -> V_74 = 64 ;
break;
case V_222 :
switch ( V_11 -> V_14 & V_15 ) {
case V_223 :
V_11 -> V_50 = V_224 ;
V_146 [ V_24 ] = L_38 ;
F_12 ( V_24 , L_39 ) ;
break;
case V_225 :
V_11 -> V_50 = V_224 ;
V_146 [ V_24 ] = L_38 ;
F_12 ( V_24 , L_40 ) ;
break;
case V_226 :
V_11 -> V_50 = V_227 ;
V_146 [ V_24 ] = L_41 ;
F_12 ( V_24 , L_42 ) ;
break;
}
F_30 ( V_11 , V_46 ) ;
V_11 -> V_3 = V_169 |
V_4 | V_138 |
V_72 ;
V_11 -> V_74 = 64 ;
break;
case V_228 :
F_49 ( V_11 ) ;
V_11 -> V_50 = V_229 ;
switch ( V_11 -> V_14 & V_15 ) {
case V_230 :
V_146 [ V_24 ] = L_43 ;
break;
}
break;
}
}
static inline void F_59 ( struct V_10 * V_11 , unsigned int V_24 )
{
switch ( V_11 -> V_14 & V_143 ) {
case V_231 :
V_11 -> V_50 = V_232 ;
V_146 [ V_24 ] = L_44 ;
break;
case V_233 :
case V_234 :
V_11 -> V_50 = V_235 ;
V_146 [ V_24 ] = L_45 ;
break;
case V_236 :
case V_237 :
V_11 -> V_50 = V_238 ;
V_146 [ V_24 ] = L_46 ;
break;
case V_239 :
V_11 -> V_50 = V_240 ;
V_146 [ V_24 ] = L_47 ;
break;
case V_241 :
V_11 -> V_50 = V_242 ;
V_146 [ V_24 ] = L_48 ;
break;
case V_243 :
V_11 -> V_50 = V_244 ;
V_146 [ V_24 ] = L_49 ;
break;
case V_245 :
V_11 -> V_50 = V_246 ;
V_146 [ V_24 ] = L_50 ;
break;
case V_247 :
V_11 -> V_50 = V_246 ;
V_146 [ V_24 ] = L_51 ;
break;
case V_248 :
V_11 -> V_50 = V_249 ;
V_146 [ V_24 ] = L_52 ;
break;
case V_250 :
V_11 -> V_50 = V_13 ;
V_146 [ V_24 ] = L_53 ;
break;
case V_251 :
V_11 -> V_50 = V_252 ;
V_146 [ V_24 ] = L_54 ;
break;
case V_253 :
V_11 -> V_50 = V_254 ;
V_146 [ V_24 ] = L_55 ;
break;
case V_255 :
V_11 -> V_50 = V_256 ;
V_146 [ V_24 ] = L_56 ;
break;
case V_257 :
V_11 -> V_50 = V_258 ;
V_146 [ V_24 ] = L_57 ;
break;
case V_259 :
V_11 -> V_50 = V_260 ;
V_146 [ V_24 ] = L_58 ;
break;
case V_261 :
V_11 -> V_50 = V_262 ;
V_146 [ V_24 ] = L_59 ;
break;
case V_263 :
V_11 -> V_50 = V_262 ;
V_146 [ V_24 ] = L_60 ;
break;
case V_264 :
V_11 -> V_50 = V_51 ;
V_146 [ V_24 ] = L_61 ;
break;
case V_265 :
V_11 -> V_50 = V_51 ;
V_146 [ V_24 ] = L_62 ;
break;
case V_266 :
V_11 -> V_50 = V_52 ;
V_146 [ V_24 ] = L_63 ;
break;
case V_267 :
V_11 -> V_50 = V_268 ;
V_146 [ V_24 ] = L_64 ;
break;
}
F_49 ( V_11 ) ;
F_60 () ;
}
static inline void F_61 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_49 ( V_11 ) ;
switch ( V_11 -> V_14 & V_143 ) {
case V_269 :
case V_270 :
V_11 -> V_50 = V_271 ;
switch ( ( V_11 -> V_14 >> 24 ) & 0xff ) {
case 0 :
V_146 [ V_24 ] = L_65 ;
break;
case 1 :
V_146 [ V_24 ] = L_66 ;
break;
case 2 :
V_146 [ V_24 ] = L_67 ;
break;
case 3 :
V_146 [ V_24 ] = L_68 ;
break;
case 4 :
V_146 [ V_24 ] = L_69 ;
if ( ( V_11 -> V_14 & V_15 ) == 2 )
V_146 [ V_24 ] = L_70 ;
break;
case 5 :
V_146 [ V_24 ] = L_71 ;
break;
default:
V_146 [ V_24 ] = L_72 ;
break;
}
break;
}
}
static inline void F_62 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_49 ( V_11 ) ;
switch ( V_11 -> V_14 & V_143 ) {
case V_272 :
V_11 -> V_50 = V_273 ;
V_146 [ V_24 ] = L_73 ;
if ( ( V_11 -> V_14 & V_15 ) < 0x02 )
V_11 -> V_3 &= ~ ( V_4 | V_72 ) ;
break;
case V_274 :
V_11 -> V_50 = V_275 ;
V_146 [ V_24 ] = L_74 ;
break;
}
}
static inline void F_63 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_49 ( V_11 ) ;
switch ( V_11 -> V_14 & V_143 ) {
case V_276 :
V_11 -> V_50 = V_277 ;
V_146 [ V_24 ] = L_75 ;
V_11 -> V_80 . V_278 = 8 ;
V_11 -> V_74 = 64 ;
break;
}
}
static inline void F_64 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_49 ( V_11 ) ;
switch ( V_11 -> V_14 & V_143 ) {
case V_279 :
V_11 -> V_50 = V_280 ;
V_146 [ V_24 ] = L_76 ;
F_30 ( V_11 , V_43 ) ;
break;
}
}
static inline void F_65 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_49 ( V_11 ) ;
switch ( V_11 -> V_14 & V_143 ) {
case V_281 :
case V_282 :
V_11 -> V_50 = V_283 ;
V_146 [ V_24 ] = L_77 ;
F_12 ( V_24 , L_78 ) ;
break;
case V_284 :
case V_285 :
case V_286 :
V_11 -> V_50 = V_287 ;
V_146 [ V_24 ] = L_79 ;
F_12 ( V_24 , L_80 ) ;
break;
case V_288 : {
int V_289 = V_11 -> V_14 & V_15 ;
if ( V_289 >= V_290 &&
V_289 <= V_291 ) {
V_11 -> V_50 = V_292 ;
V_146 [ V_24 ] = L_81 ;
F_12 ( V_24 , L_82 ) ;
} else {
V_11 -> V_50 = V_293 ;
V_146 [ V_24 ] = L_83 ;
F_12 ( V_24 , L_84 ) ;
}
break;
}
case V_294 :
V_11 -> V_50 = V_295 ;
V_146 [ V_24 ] = L_85 ;
F_12 ( V_24 , L_86 ) ;
V_11 -> V_3 |= V_97 ;
break;
}
}
static inline void F_66 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_49 ( V_11 ) ;
switch ( V_11 -> V_14 & V_143 ) {
case V_296 :
case V_297 :
case V_298 :
V_11 -> V_50 = V_299 ;
V_146 [ V_24 ] = L_87 ;
goto V_300;
case V_301 :
case V_302 :
case V_303 :
case V_304 :
V_11 -> V_50 = V_305 ;
V_146 [ V_24 ] = L_88 ;
V_300:
F_12 ( V_24 , L_89 ) ;
break;
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
V_11 -> V_50 = V_311 ;
V_146 [ V_24 ] = L_90 ;
F_12 ( V_24 , L_91 ) ;
break;
case V_312 :
case V_313 :
V_11 -> V_50 = V_314 ;
V_146 [ V_24 ] = L_92 ;
F_12 ( V_24 , L_93 ) ;
break;
default:
F_57 ( V_182 L_94 ) ;
V_11 -> V_50 = V_315 ;
break;
}
}
static inline void F_67 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_49 ( V_11 ) ;
V_11 -> V_3 &= ~ V_136 ;
F_50 ( ! F_68 ( V_316 ) || V_316 ) ;
switch ( V_11 -> V_14 & V_143 ) {
case V_317 :
V_11 -> V_50 = V_318 ;
V_146 [ V_24 ] = L_95 ;
break;
default:
F_36 ( L_96 ) ;
break;
}
}
static inline void F_69 ( struct V_10 * V_11 , int V_24 )
{
F_49 ( V_11 ) ;
if ( ( V_11 -> V_14 & V_143 ) == V_319 ) {
V_11 -> V_50 = V_271 ;
V_146 [ V_24 ] = L_97 ;
return;
}
V_11 -> V_3 = ( V_56 |
V_134 |
V_136 |
V_137 |
V_66 |
V_70 |
V_138 ) ;
switch ( V_11 -> V_14 & V_143 ) {
case V_320 :
case V_321 :
case V_322 :
V_11 -> V_50 = V_323 ;
V_146 [ V_24 ] = L_98 ;
break;
case V_324 :
case V_325 :
V_11 -> V_50 = V_323 ;
V_146 [ V_24 ] = L_99 ;
break;
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
V_11 -> V_50 = V_334 ;
V_146 [ V_24 ] = L_100 ;
break;
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
V_11 -> V_50 = V_334 ;
V_146 [ V_24 ] = L_101 ;
break;
default:
F_70 ( L_102 ,
V_11 -> V_14 ) ;
V_11 -> V_50 = V_334 ;
break;
}
if ( V_11 -> V_50 == V_323 ) {
F_30 ( V_11 , V_39 ) ;
V_11 -> V_3 |= ( V_4 | V_97 | V_139 ) ;
V_11 -> V_74 = ( ( F_32 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_30 ( V_11 , V_42 ) ;
V_11 -> V_74 = ( ( F_38 () >> 25 ) & 0x3f ) + 1 ;
}
V_11 -> V_128 = 0xf ;
}
void F_71 ( void )
{
struct V_10 * V_11 = & V_12 ;
unsigned int V_24 = F_72 () ;
V_11 -> V_14 = V_348 ;
V_11 -> V_28 = V_32 ;
V_11 -> V_50 = V_315 ;
V_11 -> V_14 = F_73 () ;
switch ( V_11 -> V_14 & V_349 ) {
case V_350 :
F_56 ( V_11 , V_24 ) ;
break;
case V_351 :
F_59 ( V_11 , V_24 ) ;
break;
case V_352 :
F_61 ( V_11 , V_24 ) ;
break;
case V_353 :
F_62 ( V_11 , V_24 ) ;
break;
case V_354 :
F_65 ( V_11 , V_24 ) ;
break;
case V_355 :
F_63 ( V_11 , V_24 ) ;
break;
case V_356 :
F_64 ( V_11 , V_24 ) ;
break;
case V_357 :
F_66 ( V_11 , V_24 ) ;
break;
case V_358 :
F_67 ( V_11 , V_24 ) ;
break;
case V_359 :
F_69 ( V_11 , V_24 ) ;
break;
}
F_50 ( ! V_146 [ V_24 ] ) ;
F_50 ( V_11 -> V_50 == V_315 ) ;
F_50 ( F_4 () != V_11 -> V_50 ) ;
if ( V_5 )
V_11 -> V_3 &= ~ V_4 ;
if ( V_9 )
V_11 -> V_6 &= ~ ( V_7 | V_8 ) ;
if ( V_11 -> V_3 & V_4 ) {
V_11 -> V_28 = F_13 () ;
if ( V_11 -> V_40 & ( V_43 | V_41 |
V_42 | V_39 ) ) {
if ( V_11 -> V_28 & V_360 )
V_11 -> V_6 |= V_361 ;
}
}
if ( V_140 ) {
V_11 -> V_362 = ( ( F_74 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_3 |= V_363 ;
}
else
V_11 -> V_362 = 1 ;
if ( V_364 ) {
V_11 -> V_35 = F_19 () ;
F_75 ( V_11 -> V_35 & V_365 ,
L_103 ) ;
}
F_24 ( V_11 ) ;
#ifdef F_76
if ( V_24 == 0 )
V_366 = ~ ( ( 1ull << V_367 ) - 1 ) ;
#endif
}
void F_77 ( void )
{
struct V_10 * V_11 = & V_12 ;
F_70 ( L_104 ,
F_72 () , V_11 -> V_14 , F_78 () ) ;
if ( V_11 -> V_3 & V_4 )
F_57 ( V_182 L_105 , V_11 -> V_28 ) ;
if ( V_364 )
F_70 ( L_106 , V_11 -> V_35 ) ;
}
