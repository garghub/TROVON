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
static unsigned int F_33 ( struct V_13 * V_14 )
{
unsigned int V_50 = V_14 -> V_51 / V_14 -> V_52 ;
if ( V_50 >= 12 )
return 1 ;
else if ( V_50 >= 6 )
return 2 ;
else
return 3 ;
}
static void F_34 ( struct V_13 * V_14 , int V_53 )
{
unsigned int V_54 ;
switch ( V_14 -> V_55 ) {
case V_56 :
case V_57 :
V_54 = F_35 () ;
V_54 &= ~ ( 3 << V_58 ) ;
if ( V_53 )
F_36 ( V_54 |
( F_33 ( V_14 )
<< V_58 )
| V_59 ) ;
else
F_36 ( V_54 & ~ V_59 ) ;
F_29 () ;
break;
}
}
static inline unsigned int F_37 ( struct V_13 * V_14 )
{
unsigned int V_60 ;
int V_40 ;
V_60 = F_38 () ;
if ( ( ( ( V_60 & V_61 ) >> 7 ) == 1 ) ||
( ( ( V_60 & V_61 ) >> 7 ) == 4 ) )
V_14 -> V_3 |= V_62 ;
V_40 = ( V_60 & V_63 ) >> 13 ;
switch ( V_40 ) {
case 0 :
switch ( ( V_60 & V_64 ) >> 10 ) {
case 0 :
F_32 ( V_14 , V_45 ) ;
break;
case 1 :
F_32 ( V_14 , V_43 ) ;
break;
default:
goto V_65;
}
break;
case 2 :
switch ( ( V_60 & V_64 ) >> 10 ) {
case 0 :
F_32 ( V_14 , V_44 ) ;
break;
case 1 :
F_32 ( V_14 , V_41 ) ;
break;
default:
goto V_65;
}
break;
default:
goto V_65;
}
return V_60 & V_66 ;
V_65:
F_39 ( V_67 , V_60 ) ;
}
static inline unsigned int F_40 ( struct V_13 * V_14 )
{
unsigned int V_68 ;
V_68 = F_41 () ;
if ( V_68 & V_69 )
V_14 -> V_6 |= V_70 ;
if ( V_68 & V_71 )
V_14 -> V_3 |= V_72 ;
if ( V_68 & V_73 )
V_14 -> V_6 |= V_74 ;
if ( V_68 & V_75 )
V_14 -> V_3 |= V_76 ;
if ( V_68 & V_77 ) {
V_14 -> V_3 |= V_4 ;
V_14 -> V_3 |= V_78 ;
}
if ( V_79 ) {
V_14 -> V_51 = ( ( V_68 & V_80 ) >> 25 ) + 1 ;
V_14 -> V_52 = V_14 -> V_51 ;
V_14 -> V_81 = 0 ;
}
return V_68 & V_66 ;
}
static inline unsigned int F_42 ( struct V_13 * V_14 )
{
unsigned int V_82 ;
V_82 = F_43 () ;
if ( V_82 & V_83 )
V_14 -> V_84 . V_85 &= ~ V_86 ;
return V_82 & V_66 ;
}
static inline unsigned int F_44 ( struct V_13 * V_14 )
{
unsigned int V_87 ;
V_87 = F_45 () ;
if ( V_87 & V_88 ) {
V_14 -> V_6 |= V_89 ;
V_14 -> V_3 |= V_90 ;
}
if ( V_87 & V_91 )
V_14 -> V_3 |= V_90 ;
if ( V_87 & V_92 )
V_14 -> V_6 |= V_7 ;
if ( V_87 & V_93 )
V_14 -> V_6 |= V_8 ;
if ( V_87 & V_94 )
V_14 -> V_3 |= V_95 ;
if ( V_87 & V_96 )
V_14 -> V_3 |= V_97 ;
if ( V_87 & V_98 )
V_14 -> V_6 |= V_99 ;
if ( V_87 & V_100 )
V_14 -> V_3 |= V_101 ;
if ( V_87 & V_102 )
V_14 -> V_3 |= V_103 ;
if ( V_87 & V_104 )
V_14 -> V_6 |= V_105 ;
if ( V_87 & V_106 )
V_14 -> V_3 |= V_107 ;
if ( V_87 & V_108 )
V_14 -> V_6 |= V_109 ;
if ( ( V_87 & V_110 ) && F_46 ( V_111 ) )
V_14 -> V_3 |= V_11 ;
return V_87 & V_66 ;
}
static inline unsigned int F_47 ( struct V_13 * V_14 )
{
unsigned int V_112 ;
unsigned int V_113 ;
unsigned int V_114 ;
unsigned int V_115 = V_116 ;
V_112 = F_48 () ;
if ( V_79 ) {
if ( ( ( V_112 & V_117 ) >> 29 ) == 2 )
V_14 -> V_3 |= V_118 ;
V_114 = V_112 & V_119 ;
switch ( V_114 ) {
case V_120 :
V_14 -> V_51 += ( V_112 & V_121 ) * 0x40 ;
V_14 -> V_52 = V_14 -> V_51 ;
break;
case V_122 :
V_14 -> V_52 +=
( ( V_112 & V_123 ) >>
V_124 ) * 0x40 ;
V_14 -> V_51 = V_14 -> V_52 ;
V_115 = V_125 ;
case V_126 :
V_113 = ( V_112 & ~ V_115 ) |
( F_49 ( V_114 ) <<
V_127 ) ;
F_50 ( V_113 ) ;
F_29 () ;
V_112 = F_48 () ;
if ( V_112 != V_113 ) {
F_51 ( L_1 ,
V_128 , V_112 ) ;
F_34 ( V_14 , 0 ) ;
break;
}
V_14 -> V_81 = 1 <<
( ( V_112 & V_129 ) >>
V_130 ) ;
V_14 -> V_131 = ( ( V_112 & V_132 ) >>
V_133 ) + 2 ;
V_14 -> V_51 += V_14 -> V_131 * V_14 -> V_81 ;
break;
}
}
V_14 -> V_134 = ( V_112 >> 16 ) & 0xff ;
return V_112 & V_66 ;
}
static inline unsigned int F_52 ( struct V_13 * V_14 )
{
unsigned int V_135 ;
V_135 = F_53 () ;
V_135 &= ~ V_136 ;
F_54 ( V_135 ) ;
if ( V_135 & V_137 )
V_14 -> V_3 |= V_138 ;
if ( V_135 & V_139 )
V_14 -> V_3 |= V_140 ;
return V_135 & V_66 ;
}
static void F_55 ( struct V_13 * V_14 )
{
int V_141 ;
V_14 -> V_3 = V_142 | V_143 | V_144 |
V_145 | V_146 | V_147 ;
V_14 -> V_84 . V_85 = V_86 ;
F_34 ( V_14 , 1 ) ;
V_141 = F_37 ( V_14 ) ;
F_56 ( ! V_141 ) ;
if ( V_141 )
V_141 = F_40 ( V_14 ) ;
if ( V_141 )
V_141 = F_42 ( V_14 ) ;
if ( V_141 )
V_141 = F_44 ( V_14 ) ;
if ( V_141 )
V_141 = F_47 ( V_14 ) ;
if ( V_141 )
V_141 = F_52 ( V_14 ) ;
F_57 ( V_14 ) ;
if ( V_148 ) {
F_58 ( F_59 () | V_149 ) ;
F_29 () ;
if ( F_59 () & V_149 )
V_14 -> V_3 |= V_150 ;
}
#ifndef F_60
if ( V_151 ) {
V_14 -> V_152 = F_61 () ;
if ( V_153 )
V_14 -> V_152 >>= F_62 ( F_63 () ) - 1 ;
}
#endif
}
static inline void F_64 ( struct V_13 * V_14 , unsigned int V_27 )
{
switch ( V_14 -> V_17 & V_154 ) {
case V_155 :
V_14 -> V_55 = V_156 ;
V_157 [ V_27 ] = L_2 ;
V_14 -> V_3 = V_62 | V_158 |
V_159 ;
if ( F_21 () )
V_14 -> V_3 |= V_4 ;
V_14 -> V_51 = 64 ;
break;
case V_160 :
if ( ( V_14 -> V_17 & V_18 ) == V_161 ) {
if ( F_11 () ) {
V_14 -> V_55 = V_162 ;
V_157 [ V_27 ] = L_3 ;
} else {
V_14 -> V_55 = V_163 ;
V_157 [ V_27 ] = L_4 ;
}
} else {
V_14 -> V_55 = V_164 ;
V_157 [ V_27 ] = L_5 ;
}
V_14 -> V_3 = V_62 | V_158 |
V_159 ;
if ( F_21 () )
V_14 -> V_3 |= V_4 ;
V_14 -> V_51 = 64 ;
break;
case V_165 :
if ( F_38 () & V_166 ) {
if ( ( V_14 -> V_17 & V_18 ) >=
V_167 ) {
V_14 -> V_55 = V_168 ;
V_157 [ V_27 ] = L_6 ;
} else {
V_14 -> V_55 = V_169 ;
V_157 [ V_27 ] = L_7 ;
}
} else {
int V_170 = F_38 () & V_171 ;
int V_172 ;
switch ( V_170 ) {
case V_173 :
case V_174 :
case V_175 :
V_172 = 1 ;
break;
default:
V_172 = 0 ;
break;
}
if ( ( V_14 -> V_17 & V_18 ) >=
V_167 ) {
V_14 -> V_55 = V_172 ? V_176 : V_177 ;
V_157 [ V_27 ] = V_172 ? L_8 : L_9 ;
} else {
V_14 -> V_55 = V_172 ? V_178 : V_179 ;
V_157 [ V_27 ] = V_172 ? L_10 : L_11 ;
}
}
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_180 | V_4 | V_78 |
V_72 | V_181 |
V_146 ;
V_14 -> V_51 = 48 ;
break;
case V_182 :
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_180 ;
V_14 -> V_51 = 32 ;
switch ( V_14 -> V_17 & 0xf0 ) {
case V_183 :
V_14 -> V_55 = V_184 ;
V_157 [ V_27 ] = L_12 ;
break;
case V_185 :
V_14 -> V_55 = V_186 ;
V_157 [ V_27 ] = L_13 ;
break;
case V_187 :
if ( ( V_14 -> V_17 & 0xf ) < 0x3 ) {
V_14 -> V_55 = V_188 ;
V_157 [ V_27 ] = L_14 ;
} else {
V_14 -> V_55 = V_189 ;
V_157 [ V_27 ] = L_15 ;
}
break;
case V_190 :
if ( ( V_14 -> V_17 & 0xf ) < 0x4 ) {
V_14 -> V_55 = V_191 ;
V_157 [ V_27 ] = L_16 ;
} else {
V_14 -> V_55 = V_192 ;
V_14 -> V_3 |= V_146 ;
V_157 [ V_27 ] = L_17 ;
}
break;
default:
F_65 ( V_193 L_18 ) ;
V_14 -> V_55 = V_194 ;
V_157 [ V_27 ] = L_19 ;
break;
}
break;
case V_195 :
V_14 -> V_55 = V_196 ;
V_157 [ V_27 ] = L_20 ;
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_180 | V_4 | V_78 |
V_146 ;
V_14 -> V_51 = 32 ;
break;
case V_197 :
V_14 -> V_55 = V_198 ;
V_157 [ V_27 ] = L_21 ;
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_180 | V_4 | V_78 |
V_146 ;
V_14 -> V_51 = 48 ;
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
case V_199 :
V_14 -> V_3 = V_62 | V_200 ;
if ( ( V_14 -> V_17 & 0xf0 ) == ( V_201 & 0xf0 ) ) {
V_14 -> V_55 = V_202 ;
V_157 [ V_27 ] = L_22 ;
V_14 -> V_51 = 64 ;
} else {
switch ( V_14 -> V_17 & V_18 ) {
case V_203 :
V_14 -> V_55 = V_204 ;
V_157 [ V_27 ] = L_23 ;
V_14 -> V_51 = 32 ;
break;
case V_205 :
V_14 -> V_55 = V_206 ;
V_157 [ V_27 ] = L_24 ;
V_14 -> V_51 = 64 ;
break;
}
}
break;
case V_207 :
V_14 -> V_55 = V_208 ;
V_157 [ V_27 ] = L_25 ;
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_180 | V_4 | V_78 |
V_146 ;
V_14 -> V_51 = 48 ;
break;
case V_209 :
V_14 -> V_55 = V_210 ;
V_157 [ V_27 ] = L_26 ;
F_32 ( V_14 , V_48 ) ;
V_14 -> V_3 = V_180 | V_146 ;
if ( ! ( V_14 -> V_17 & 0x08 ) )
V_14 -> V_3 |= V_4 | V_78 ;
V_14 -> V_51 = 48 ;
break;
case V_211 :
V_14 -> V_55 = V_212 ;
V_157 [ V_27 ] = L_27 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_180 | V_4 | V_78 |
V_146 ;
V_14 -> V_51 = 48 ;
break;
case V_213 :
V_14 -> V_55 = V_214 ;
V_157 [ V_27 ] = L_28 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_180 | V_4 | V_78 |
V_72 | V_146 ;
V_14 -> V_51 = 48 ;
break;
case V_215 :
V_14 -> V_55 = V_216 ;
V_157 [ V_27 ] = L_29 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_180 | V_4 | V_78 |
V_72 | V_146 ;
V_14 -> V_51 = 48 ;
break;
case V_217 :
V_14 -> V_55 = V_218 ;
V_157 [ V_27 ] = L_30 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_180 | V_4 | V_78 |
V_145 | V_146 ;
V_14 -> V_51 = 48 ;
break;
case V_219 :
V_14 -> V_55 = V_220 ;
V_157 [ V_27 ] = L_31 ;
F_32 ( V_14 , V_49 ) ;
V_14 -> V_3 = V_62 | V_4 |
V_146 ;
V_14 -> V_51 = 32 ;
break;
case V_221 :
V_14 -> V_55 = V_222 ;
V_157 [ V_27 ] = L_32 ;
F_32 ( V_14 , V_49 ) ;
V_14 -> V_3 = V_62 | V_4 |
V_146 ;
V_14 -> V_51 = 32 ;
break;
case V_223 :
V_14 -> V_55 = V_224 ;
V_157 [ V_27 ] = L_33 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_180 | V_4 | V_78 |
V_146 ;
V_14 -> V_51 = ( F_66 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_225 :
V_14 -> V_55 = V_226 ;
V_157 [ V_27 ] = L_34 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_62 | V_142 |
V_4 | V_78 |
V_146 ;
V_14 -> V_51 = 384 ;
break;
case V_227 :
V_14 -> V_55 = V_228 ;
V_157 [ V_27 ] = L_35 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_62 | V_143 | V_142 |
V_4 | V_78 |
V_144 | V_72 |
V_146 ;
V_14 -> V_51 = 64 ;
break;
case V_229 :
V_14 -> V_55 = V_230 ;
V_157 [ V_27 ] = L_36 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_62 | V_143 | V_142 |
V_4 | V_78 |
V_144 | V_72 |
V_146 ;
V_14 -> V_51 = 64 ;
break;
case V_231 :
V_14 -> V_55 = V_232 ;
V_157 [ V_27 ] = L_37 ;
F_32 ( V_14 , V_47 ) ;
V_14 -> V_3 = V_62 | V_143 | V_142 |
V_4 | V_78 |
V_144 | V_72 |
V_146 ;
V_14 -> V_51 = 64 ;
break;
case V_233 :
switch ( V_14 -> V_17 & V_18 ) {
case V_234 :
V_14 -> V_55 = V_235 ;
V_157 [ V_27 ] = L_38 ;
F_15 ( V_27 , L_39 ) ;
F_32 ( V_14 , V_48 ) ;
break;
case V_236 :
V_14 -> V_55 = V_235 ;
V_157 [ V_27 ] = L_38 ;
F_15 ( V_27 , L_40 ) ;
F_32 ( V_14 , V_48 ) ;
break;
case V_237 :
V_14 -> V_55 = V_238 ;
V_157 [ V_27 ] = L_41 ;
F_15 ( V_27 , L_42 ) ;
F_32 ( V_14 , V_44 ) ;
break;
case V_239 :
case V_240 :
V_14 -> V_55 = V_238 ;
V_157 [ V_27 ] = L_41 ;
F_15 ( V_27 , L_43 ) ;
F_32 ( V_14 , V_44 ) ;
break;
}
V_14 -> V_3 = V_180 |
V_4 | V_146 |
V_78 ;
V_14 -> V_51 = 64 ;
V_14 -> V_241 = V_242 ;
break;
case V_243 :
F_55 ( V_14 ) ;
V_14 -> V_55 = V_244 ;
switch ( V_14 -> V_17 & V_18 ) {
case V_245 :
V_157 [ V_27 ] = L_44 ;
break;
}
break;
}
}
static inline void F_67 ( struct V_13 * V_14 , unsigned int V_27 )
{
V_14 -> V_241 = V_242 ;
switch ( V_14 -> V_17 & V_154 ) {
case V_246 :
V_14 -> V_55 = V_247 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_45 ;
break;
case V_249 :
case V_250 :
V_14 -> V_55 = V_251 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_46 ;
break;
case V_252 :
case V_253 :
V_14 -> V_55 = V_254 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_47 ;
break;
case V_255 :
V_14 -> V_55 = V_256 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_48 ;
break;
case V_257 :
V_14 -> V_55 = V_258 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_49 ;
break;
case V_259 :
V_14 -> V_55 = V_260 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_50 ;
break;
case V_261 :
V_14 -> V_55 = V_262 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_51 ;
break;
case V_263 :
V_14 -> V_55 = V_262 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_52 ;
break;
case V_264 :
V_14 -> V_55 = V_265 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_53 ;
break;
case V_266 :
V_14 -> V_55 = V_16 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_54 ;
break;
case V_267 :
V_14 -> V_55 = V_268 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_55 ;
break;
case V_269 :
V_14 -> V_55 = V_270 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_56 ;
break;
case V_271 :
V_14 -> V_55 = V_272 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_57 ;
break;
case V_273 :
V_14 -> V_55 = V_274 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_58 ;
break;
case V_275 :
V_14 -> V_55 = V_276 ;
V_14 -> V_241 = V_248 ;
V_157 [ V_27 ] = L_59 ;
break;
case V_277 :
V_14 -> V_55 = V_278 ;
V_157 [ V_27 ] = L_60 ;
break;
case V_279 :
V_14 -> V_55 = V_278 ;
V_157 [ V_27 ] = L_61 ;
break;
case V_280 :
V_14 -> V_55 = V_56 ;
V_157 [ V_27 ] = L_62 ;
break;
case V_281 :
V_14 -> V_55 = V_56 ;
V_157 [ V_27 ] = L_63 ;
break;
case V_282 :
V_14 -> V_55 = V_57 ;
V_157 [ V_27 ] = L_64 ;
break;
case V_283 :
V_14 -> V_55 = V_284 ;
V_157 [ V_27 ] = L_65 ;
break;
}
F_55 ( V_14 ) ;
F_68 () ;
}
static inline void F_69 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_55 ( V_14 ) ;
switch ( V_14 -> V_17 & V_154 ) {
case V_285 :
case V_286 :
V_14 -> V_55 = V_287 ;
switch ( ( V_14 -> V_17 >> 24 ) & 0xff ) {
case 0 :
V_157 [ V_27 ] = L_66 ;
break;
case 1 :
V_157 [ V_27 ] = L_67 ;
break;
case 2 :
V_157 [ V_27 ] = L_68 ;
break;
case 3 :
V_157 [ V_27 ] = L_69 ;
break;
case 4 :
V_157 [ V_27 ] = L_70 ;
if ( ( V_14 -> V_17 & V_18 ) == 2 )
V_157 [ V_27 ] = L_71 ;
break;
case 5 :
V_157 [ V_27 ] = L_72 ;
break;
default:
V_157 [ V_27 ] = L_73 ;
break;
}
break;
}
}
static inline void F_70 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_55 ( V_14 ) ;
V_14 -> V_241 = V_242 ;
switch ( V_14 -> V_17 & V_154 ) {
case V_288 :
V_14 -> V_55 = V_289 ;
V_157 [ V_27 ] = L_74 ;
if ( ( V_14 -> V_17 & V_18 ) < 0x02 )
V_14 -> V_3 &= ~ ( V_4 | V_78 ) ;
break;
case V_290 :
V_14 -> V_55 = V_291 ;
V_157 [ V_27 ] = L_75 ;
break;
}
}
static inline void F_71 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_55 ( V_14 ) ;
switch ( V_14 -> V_17 & V_154 ) {
case V_292 :
V_14 -> V_55 = V_293 ;
V_157 [ V_27 ] = L_76 ;
V_14 -> V_84 . V_294 = 8 ;
V_14 -> V_51 = 64 ;
break;
}
}
static inline void F_72 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_55 ( V_14 ) ;
switch ( V_14 -> V_17 & V_154 ) {
case V_295 :
V_14 -> V_55 = V_296 ;
V_157 [ V_27 ] = L_77 ;
F_32 ( V_14 , V_45 ) ;
break;
}
}
static inline void F_73 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_55 ( V_14 ) ;
switch ( V_14 -> V_17 & V_154 ) {
case V_297 :
case V_298 :
V_14 -> V_55 = V_299 ;
V_157 [ V_27 ] = L_78 ;
F_15 ( V_27 , L_79 ) ;
break;
case V_300 :
case V_301 :
case V_302 :
V_14 -> V_55 = V_303 ;
V_157 [ V_27 ] = L_80 ;
F_15 ( V_27 , L_81 ) ;
break;
case V_304 : {
int V_305 = V_14 -> V_17 & V_18 ;
if ( V_305 >= V_306 &&
V_305 <= V_307 ) {
V_14 -> V_55 = V_308 ;
V_157 [ V_27 ] = L_82 ;
F_15 ( V_27 , L_83 ) ;
} else {
V_14 -> V_55 = V_309 ;
V_157 [ V_27 ] = L_84 ;
F_15 ( V_27 , L_85 ) ;
}
break;
}
case V_310 :
V_14 -> V_55 = V_311 ;
V_157 [ V_27 ] = L_86 ;
F_15 ( V_27 , L_87 ) ;
V_14 -> V_3 |= V_101 ;
break;
}
}
static inline void F_74 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_55 ( V_14 ) ;
switch ( V_14 -> V_17 & V_154 ) {
case V_312 :
case V_313 :
case V_314 :
V_14 -> V_55 = V_315 ;
V_157 [ V_27 ] = L_88 ;
goto V_316;
case V_317 :
case V_318 :
case V_319 :
case V_320 :
V_14 -> V_55 = V_321 ;
V_157 [ V_27 ] = L_89 ;
V_316:
F_15 ( V_27 , L_90 ) ;
break;
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
V_14 -> V_55 = V_327 ;
V_157 [ V_27 ] = L_91 ;
F_15 ( V_27 , L_92 ) ;
break;
case V_328 :
case V_329 :
V_14 -> V_55 = V_330 ;
V_157 [ V_27 ] = L_93 ;
F_15 ( V_27 , L_94 ) ;
break;
default:
F_65 ( V_193 L_95 ) ;
V_14 -> V_55 = V_331 ;
break;
}
}
static inline void F_75 ( struct V_13 * V_14 , unsigned int V_27 )
{
F_55 ( V_14 ) ;
V_14 -> V_3 &= ~ V_144 ;
F_56 ( ! F_76 ( V_332 ) || V_332 ) ;
switch ( V_14 -> V_17 & V_154 ) {
case V_333 :
V_14 -> V_55 = V_334 ;
V_14 -> V_241 = V_242 ;
V_157 [ V_27 ] = L_96 ;
break;
default:
F_39 ( L_97 ) ;
break;
}
}
static inline void F_77 ( struct V_13 * V_14 , int V_27 )
{
F_55 ( V_14 ) ;
if ( ( V_14 -> V_17 & V_154 ) == V_335 ) {
V_14 -> V_55 = V_287 ;
V_157 [ V_27 ] = L_98 ;
return;
}
V_14 -> V_3 = ( V_62 |
V_142 |
V_144 |
V_145 |
V_72 |
V_76 |
V_146 ) ;
switch ( V_14 -> V_17 & V_154 ) {
case V_336 :
case V_337 :
case V_338 :
V_14 -> V_55 = V_339 ;
V_157 [ V_27 ] = L_99 ;
break;
case V_340 :
case V_341 :
V_14 -> V_55 = V_339 ;
V_157 [ V_27 ] = L_100 ;
break;
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
V_14 -> V_55 = V_350 ;
V_157 [ V_27 ] = L_101 ;
break;
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
V_14 -> V_55 = V_350 ;
V_157 [ V_27 ] = L_102 ;
break;
default:
F_78 ( L_103 ,
V_14 -> V_17 ) ;
V_14 -> V_55 = V_350 ;
break;
}
if ( V_14 -> V_55 == V_339 ) {
F_32 ( V_14 , V_41 ) ;
V_14 -> V_3 |= ( V_4 | V_101 | V_147 ) ;
V_14 -> V_51 = ( ( F_35 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_32 ( V_14 , V_44 ) ;
V_14 -> V_51 = ( ( F_41 () >> 25 ) & 0x3f ) + 1 ;
}
V_14 -> V_134 = 0xf ;
}
void F_79 ( void )
{
struct V_13 * V_14 = & V_15 ;
unsigned int V_27 = F_80 () ;
V_14 -> V_17 = V_364 ;
V_14 -> V_31 = V_35 ;
V_14 -> V_55 = V_331 ;
V_14 -> V_241 = V_248 ;
V_14 -> V_17 = F_81 () ;
switch ( V_14 -> V_17 & V_365 ) {
case V_366 :
F_64 ( V_14 , V_27 ) ;
break;
case V_367 :
F_67 ( V_14 , V_27 ) ;
break;
case V_368 :
F_69 ( V_14 , V_27 ) ;
break;
case V_369 :
F_70 ( V_14 , V_27 ) ;
break;
case V_370 :
F_73 ( V_14 , V_27 ) ;
break;
case V_371 :
F_71 ( V_14 , V_27 ) ;
break;
case V_372 :
F_72 ( V_14 , V_27 ) ;
break;
case V_373 :
F_74 ( V_14 , V_27 ) ;
break;
case V_374 :
F_75 ( V_14 , V_27 ) ;
break;
case V_375 :
F_77 ( V_14 , V_27 ) ;
break;
}
F_56 ( ! V_157 [ V_27 ] ) ;
F_56 ( V_14 -> V_55 == V_331 ) ;
F_56 ( F_7 () != V_14 -> V_55 ) ;
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
if ( V_14 -> V_31 & V_376 )
V_14 -> V_6 |= V_377 ;
}
}
if ( V_151 ) {
V_14 -> V_378 = ( ( F_82 () >> 26 ) & 0x0f ) + 1 ;
V_14 -> V_3 |= V_379 ;
}
else
V_14 -> V_378 = 1 ;
if ( V_380 ) {
V_14 -> V_37 = F_22 () ;
F_83 ( V_14 -> V_37 & V_381 ,
L_104 ) ;
}
F_26 ( V_14 ) ;
#ifdef F_84
if ( V_27 == 0 )
V_382 = ~ ( ( 1ull << V_383 ) - 1 ) ;
#endif
}
void F_85 ( void )
{
struct V_13 * V_14 = & V_15 ;
F_78 ( L_105 ,
F_80 () , V_14 -> V_17 , F_86 () ) ;
if ( V_14 -> V_3 & V_4 )
F_65 ( V_193 L_106 , V_14 -> V_31 ) ;
if ( V_380 )
F_78 ( L_107 , V_14 -> V_37 ) ;
}
