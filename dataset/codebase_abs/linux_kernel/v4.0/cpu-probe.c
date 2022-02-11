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
static int T_1 F_6 ( char * V_1 )
{
unsigned int V_13 , V_14 ;
if ( ! V_15 )
return 1 ;
F_7 ( & V_2 [ 0 ] , 0 ) ;
F_8 () ;
V_13 = F_9 () ;
V_14 = V_13 & V_16 ;
if ( V_14 == V_17 ) {
F_10 ( L_1 ) ;
return 1 ;
}
V_18 = 1 ;
V_15 = 0 ;
F_11 ( L_2 ) ;
V_2 [ 0 ] . V_19 -= V_2 [ 0 ] . V_20 *
V_2 [ 0 ] . V_21 ;
V_2 [ 0 ] . V_21 = 0 ;
V_2 [ 0 ] . V_20 = 0 ;
return 1 ;
}
static inline void F_12 ( void )
{
struct V_22 * V_23 = & V_24 ;
switch ( F_13 () ) {
case V_25 :
if ( ( V_23 -> V_26 & V_27 ) <= V_28 )
F_14 ( F_15 () | V_29 ) ;
break;
default:
break;
}
}
void T_1 F_16 ( void )
{
F_12 () ;
}
static inline int F_17 ( void )
{
#ifdef F_18
extern unsigned long V_30 ( unsigned long ) ;
unsigned long V_31 , V_32 ;
unsigned long V_33 = F_19 () ;
V_31 = V_30 ( V_34 ) ;
F_20 ( V_33 ^ V_35 ) ;
V_32 = V_30 ( V_34 ) ;
F_20 ( V_33 ) ;
return V_31 != V_32 ;
#else
return 0 ;
#endif
}
static inline void F_21 ( int V_36 , const char * V_37 )
{
if ( V_36 == 0 )
V_38 = V_37 ;
}
static inline unsigned long F_22 ( void )
{
unsigned long V_39 , V_40 ;
V_39 = F_23 () ;
F_24 ( V_41 ) ;
V_40 = F_25 ( V_42 ) ;
F_26 ( V_39 ) ;
return V_40 ;
}
static inline int F_27 ( void )
{
return ( F_22 () & V_43 ) != V_44 ;
}
static inline unsigned long F_28 ( void )
{
unsigned long V_45 , V_46 ;
V_45 = F_23 () ;
F_24 ( V_47 ) ;
F_29 () ;
V_46 = F_30 () ;
F_31 () ;
F_26 ( V_45 ) ;
return V_46 ;
}
static inline void F_32 ( struct V_22 * V_23 )
{
#ifdef F_33
F_34 ( 0x3fffffffffffe000ULL ) ;
F_8 () ;
V_23 -> V_48 = F_35 ( F_36 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void F_37 ( struct V_22 * V_23 , unsigned int V_49 )
{
switch ( V_49 ) {
case V_50 :
V_23 -> V_51 |= V_52 | V_50 ;
case V_53 :
V_23 -> V_51 |= V_54 | V_53 ;
case V_55 :
V_23 -> V_51 |= V_55 ;
case V_56 :
V_23 -> V_51 |= V_56 ;
case V_57 :
V_23 -> V_51 |= V_58 | V_57 ;
break;
case V_59 :
V_23 -> V_51 |= V_60 | V_59 ;
case V_60 :
V_23 -> V_51 |= V_60 ;
break;
case V_52 :
V_23 -> V_51 |= V_52 ;
case V_54 :
V_23 -> V_51 |= V_54 ;
case V_58 :
V_23 -> V_51 |= V_58 ;
break;
}
}
static unsigned int F_38 ( struct V_22 * V_23 )
{
unsigned int V_61 = V_23 -> V_19 / V_23 -> V_62 ;
if ( V_61 >= 12 )
return 1 ;
else if ( V_61 >= 6 )
return 2 ;
else
return 3 ;
}
static void F_7 ( struct V_22 * V_23 , int V_63 )
{
unsigned int V_64 ;
switch ( V_23 -> V_65 ) {
case V_66 :
case V_67 :
V_64 = F_39 () ;
V_64 &= ~ ( 3 << V_68 ) ;
if ( V_63 )
F_40 ( V_64 |
( F_38 ( V_23 )
<< V_68 )
| V_69 ) ;
else
F_40 ( V_64 & ~ V_69 ) ;
F_8 () ;
break;
}
}
static inline unsigned int F_41 ( struct V_22 * V_23 )
{
unsigned int V_70 ;
int V_49 ;
V_70 = F_42 () ;
if ( ( ( ( V_70 & V_71 ) >> 7 ) == 1 ) ||
( ( ( V_70 & V_71 ) >> 7 ) == 4 ) )
V_23 -> V_3 |= V_72 ;
V_49 = ( V_70 & V_73 ) >> 13 ;
switch ( V_49 ) {
case 0 :
switch ( ( V_70 & V_74 ) >> 10 ) {
case 0 :
F_37 ( V_23 , V_54 ) ;
break;
case 1 :
F_37 ( V_23 , V_52 ) ;
break;
case 2 :
F_37 ( V_23 , V_60 ) ;
break;
default:
goto V_75;
}
break;
case 2 :
switch ( ( V_70 & V_74 ) >> 10 ) {
case 0 :
F_37 ( V_23 , V_53 ) ;
break;
case 1 :
F_37 ( V_23 , V_50 ) ;
break;
case 2 :
F_37 ( V_23 , V_59 ) ;
break;
default:
goto V_75;
}
break;
default:
goto V_75;
}
return V_70 & V_76 ;
V_75:
F_43 ( V_77 , V_70 ) ;
}
static inline unsigned int F_44 ( struct V_22 * V_23 )
{
unsigned int V_78 ;
V_78 = F_45 () ;
if ( V_78 & V_79 )
V_23 -> V_6 |= V_80 ;
if ( V_78 & V_81 )
V_23 -> V_3 |= V_82 ;
if ( V_78 & V_83 )
V_23 -> V_6 |= V_84 ;
if ( V_78 & V_85 )
V_23 -> V_3 |= V_86 ;
if ( V_78 & V_87 ) {
V_23 -> V_3 |= V_4 ;
V_23 -> V_3 |= V_88 ;
}
if ( V_89 ) {
V_23 -> V_19 = ( ( V_78 & V_90 ) >> 25 ) + 1 ;
V_23 -> V_62 = V_23 -> V_19 ;
V_23 -> V_21 = 0 ;
}
return V_78 & V_76 ;
}
static inline unsigned int F_46 ( struct V_22 * V_23 )
{
unsigned int V_91 ;
V_91 = F_47 () ;
if ( V_91 & V_92 )
V_23 -> V_93 . V_94 &= ~ V_95 ;
return V_91 & V_76 ;
}
static inline unsigned int F_48 ( struct V_22 * V_23 )
{
unsigned int V_96 ;
V_96 = F_49 () ;
if ( V_96 & V_97 ) {
V_23 -> V_6 |= V_98 ;
V_23 -> V_3 |= V_99 ;
}
if ( V_96 & V_100 )
V_23 -> V_3 |= V_99 ;
if ( V_96 & V_101 )
V_23 -> V_6 |= V_7 ;
if ( V_96 & V_102 )
V_23 -> V_6 |= V_8 ;
if ( V_96 & V_103 )
V_23 -> V_3 |= V_104 ;
if ( V_96 & V_105 )
V_23 -> V_3 |= V_106 ;
if ( V_96 & V_107 )
V_23 -> V_6 |= V_108 ;
if ( V_96 & V_109 )
V_23 -> V_3 |= V_110 ;
if ( V_96 & V_111 )
V_23 -> V_3 |= V_112 ;
if ( V_96 & V_113 )
V_23 -> V_6 |= V_114 ;
if ( V_96 & V_115 )
V_23 -> V_3 |= V_116 ;
if ( V_96 & V_117 )
V_23 -> V_6 |= V_118 ;
if ( ( V_96 & V_119 ) && F_50 ( V_120 ) ) {
V_23 -> V_121 = 0 ;
V_23 -> V_3 |= V_11 ;
}
return V_96 & V_76 ;
}
static inline unsigned int F_51 ( struct V_22 * V_23 )
{
unsigned int V_13 ;
unsigned int V_122 ;
unsigned int V_14 ;
unsigned int V_123 = V_124 ;
V_13 = F_9 () ;
if ( V_89 ) {
if ( ( ( V_13 & V_125 ) >> 29 ) == 2 )
V_23 -> V_3 |= V_126 ;
V_14 = V_13 & V_16 ;
switch ( V_14 ) {
case V_127 :
V_23 -> V_19 += ( V_13 & V_128 ) * 0x40 ;
V_23 -> V_62 = V_23 -> V_19 ;
break;
case V_129 :
V_23 -> V_62 +=
( ( V_13 & V_130 ) >>
V_131 ) * 0x40 ;
V_23 -> V_19 = V_23 -> V_62 ;
V_123 = V_132 ;
case V_17 :
if ( V_18 )
break;
V_122 = ( V_13 & ~ V_123 ) |
( F_52 ( V_14 ) <<
V_133 ) ;
F_53 ( V_122 ) ;
F_8 () ;
V_13 = F_9 () ;
if ( V_13 != V_122 ) {
F_54 ( L_3 ,
V_134 , V_13 ) ;
F_7 ( V_23 , 0 ) ;
break;
}
V_23 -> V_21 = 1 <<
( ( V_13 & V_135 ) >>
V_136 ) ;
V_23 -> V_20 = ( ( V_13 & V_137 ) >>
V_138 ) + 2 ;
V_23 -> V_19 += V_23 -> V_20 * V_23 -> V_21 ;
V_15 = 1 ;
break;
}
}
V_23 -> V_139 = ( V_13 >> 16 ) & 0xff ;
return V_13 & V_76 ;
}
static inline unsigned int F_55 ( struct V_22 * V_23 )
{
unsigned int V_140 ;
V_140 = F_56 () ;
V_140 &= ~ ( V_141 | V_142 ) ;
F_57 ( V_140 ) ;
if ( V_140 & V_143 )
V_23 -> V_3 |= V_144 ;
if ( V_140 & V_145 )
V_23 -> V_3 |= V_146 ;
if ( V_140 & V_147 )
V_23 -> V_3 |= V_148 ;
return V_140 & V_76 ;
}
static void F_58 ( struct V_22 * V_23 )
{
int V_149 ;
V_23 -> V_3 = V_150 | V_151 | V_152 |
V_153 | V_154 | V_155 ;
V_23 -> V_93 . V_94 = V_95 ;
F_7 ( V_23 , ! V_18 ) ;
V_149 = F_41 ( V_23 ) ;
F_59 ( ! V_149 ) ;
if ( V_149 )
V_149 = F_44 ( V_23 ) ;
if ( V_149 )
V_149 = F_46 ( V_23 ) ;
if ( V_149 )
V_149 = F_48 ( V_23 ) ;
if ( V_149 )
V_149 = F_51 ( V_23 ) ;
if ( V_149 )
V_149 = F_55 ( V_23 ) ;
F_60 ( V_23 ) ;
if ( V_156 ) {
F_61 ( V_157 ) ;
F_8 () ;
if ( F_62 () & V_157 )
V_23 -> V_3 |= V_158 ;
}
#ifndef F_63
if ( V_159 ) {
V_23 -> V_160 = F_64 () ;
if ( V_161 )
V_23 -> V_160 >>= F_65 ( F_66 () ) - 1 ;
}
#endif
}
static inline void F_67 ( struct V_22 * V_23 , unsigned int V_36 )
{
switch ( V_23 -> V_26 & V_162 ) {
case V_163 :
V_23 -> V_65 = V_164 ;
V_165 [ V_36 ] = L_4 ;
V_23 -> V_3 = V_72 | V_166 |
V_167 ;
if ( F_27 () )
V_23 -> V_3 |= V_4 ;
V_23 -> V_19 = 64 ;
break;
case V_168 :
if ( ( V_23 -> V_26 & V_27 ) == V_169 ) {
if ( F_17 () ) {
V_23 -> V_65 = V_170 ;
V_165 [ V_36 ] = L_5 ;
} else {
V_23 -> V_65 = V_171 ;
V_165 [ V_36 ] = L_6 ;
}
} else {
V_23 -> V_65 = V_172 ;
V_165 [ V_36 ] = L_7 ;
}
V_23 -> V_3 = V_72 | V_166 |
V_167 ;
if ( F_27 () )
V_23 -> V_3 |= V_4 ;
V_23 -> V_19 = 64 ;
break;
case V_173 :
if ( F_42 () & V_174 ) {
if ( ( V_23 -> V_26 & V_27 ) >=
V_175 ) {
V_23 -> V_65 = V_176 ;
V_165 [ V_36 ] = L_8 ;
} else {
V_23 -> V_65 = V_177 ;
V_165 [ V_36 ] = L_9 ;
}
} else {
int V_178 = F_42 () & V_179 ;
int V_180 ;
switch ( V_178 ) {
case V_181 :
case V_182 :
case V_183 :
V_180 = 1 ;
break;
default:
V_180 = 0 ;
break;
}
if ( ( V_23 -> V_26 & V_27 ) >=
V_175 ) {
V_23 -> V_65 = V_180 ? V_184 : V_185 ;
V_165 [ V_36 ] = V_180 ? L_10 : L_11 ;
} else {
V_23 -> V_65 = V_180 ? V_186 : V_187 ;
V_165 [ V_36 ] = V_180 ? L_12 : L_13 ;
}
}
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_188 | V_4 | V_88 |
V_82 | V_189 |
V_154 ;
V_23 -> V_19 = 48 ;
break;
case V_190 :
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_188 ;
V_23 -> V_19 = 32 ;
switch ( V_23 -> V_26 & 0xf0 ) {
case V_191 :
V_23 -> V_65 = V_192 ;
V_165 [ V_36 ] = L_14 ;
break;
case V_193 :
V_23 -> V_65 = V_194 ;
V_165 [ V_36 ] = L_15 ;
break;
case V_195 :
if ( ( V_23 -> V_26 & 0xf ) < 0x3 ) {
V_23 -> V_65 = V_196 ;
V_165 [ V_36 ] = L_16 ;
} else {
V_23 -> V_65 = V_197 ;
V_165 [ V_36 ] = L_17 ;
}
break;
case V_198 :
if ( ( V_23 -> V_26 & 0xf ) < 0x4 ) {
V_23 -> V_65 = V_199 ;
V_165 [ V_36 ] = L_18 ;
} else {
V_23 -> V_65 = V_200 ;
V_23 -> V_3 |= V_154 ;
V_165 [ V_36 ] = L_19 ;
}
break;
default:
F_68 ( V_201 L_20 ) ;
V_23 -> V_65 = V_202 ;
V_165 [ V_36 ] = L_21 ;
break;
}
break;
case V_203 :
V_23 -> V_65 = V_204 ;
V_165 [ V_36 ] = L_22 ;
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_188 | V_4 | V_88 |
V_154 ;
V_23 -> V_19 = 32 ;
break;
case V_205 :
V_23 -> V_65 = V_206 ;
V_165 [ V_36 ] = L_23 ;
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_188 | V_4 | V_88 |
V_154 ;
V_23 -> V_19 = 48 ;
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
case V_207 :
V_23 -> V_3 = V_72 | V_208 ;
if ( ( V_23 -> V_26 & 0xf0 ) == ( V_209 & 0xf0 ) ) {
V_23 -> V_65 = V_210 ;
V_165 [ V_36 ] = L_24 ;
V_23 -> V_19 = 64 ;
} else {
switch ( V_23 -> V_26 & V_27 ) {
case V_211 :
V_23 -> V_65 = V_212 ;
V_165 [ V_36 ] = L_25 ;
V_23 -> V_19 = 32 ;
break;
case V_213 :
V_23 -> V_65 = V_214 ;
V_165 [ V_36 ] = L_26 ;
V_23 -> V_19 = 64 ;
break;
}
}
break;
case V_215 :
V_23 -> V_65 = V_216 ;
V_165 [ V_36 ] = L_27 ;
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_188 | V_4 | V_88 |
V_154 ;
V_23 -> V_19 = 48 ;
break;
case V_217 :
V_23 -> V_65 = V_218 ;
V_165 [ V_36 ] = L_28 ;
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_188 | V_154 ;
if ( ! ( V_23 -> V_26 & 0x08 ) )
V_23 -> V_3 |= V_4 | V_88 ;
V_23 -> V_19 = 48 ;
break;
case V_219 :
V_23 -> V_65 = V_220 ;
V_165 [ V_36 ] = L_29 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_188 | V_4 | V_88 |
V_154 ;
V_23 -> V_19 = 48 ;
break;
case V_221 :
V_23 -> V_65 = V_222 ;
V_165 [ V_36 ] = L_30 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_188 | V_4 | V_88 |
V_82 | V_154 ;
V_23 -> V_19 = 48 ;
break;
case V_223 :
V_23 -> V_65 = V_224 ;
V_165 [ V_36 ] = L_31 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_188 | V_4 | V_88 |
V_82 | V_154 ;
V_23 -> V_19 = 48 ;
break;
case V_225 :
V_23 -> V_65 = V_226 ;
V_165 [ V_36 ] = L_32 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_188 | V_4 | V_88 |
V_153 | V_154 ;
V_23 -> V_19 = 48 ;
break;
case V_227 :
V_23 -> V_65 = V_228 ;
V_165 [ V_36 ] = L_33 ;
F_37 ( V_23 , V_58 ) ;
V_23 -> V_3 = V_72 | V_4 |
V_154 ;
V_23 -> V_19 = 32 ;
break;
case V_229 :
V_23 -> V_65 = V_230 ;
V_165 [ V_36 ] = L_34 ;
F_37 ( V_23 , V_58 ) ;
V_23 -> V_3 = V_72 | V_4 |
V_154 ;
V_23 -> V_19 = 32 ;
break;
case V_231 :
V_23 -> V_65 = V_232 ;
V_165 [ V_36 ] = L_35 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_188 | V_4 | V_88 |
V_154 ;
V_23 -> V_19 = ( F_69 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_233 :
V_23 -> V_65 = V_234 ;
V_165 [ V_36 ] = L_36 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_72 | V_150 |
V_4 | V_88 |
V_154 ;
V_23 -> V_19 = 384 ;
break;
case V_235 :
V_23 -> V_65 = V_236 ;
V_165 [ V_36 ] = L_37 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_72 | V_151 | V_150 |
V_4 | V_88 |
V_152 | V_82 |
V_154 ;
V_23 -> V_19 = 64 ;
break;
case V_237 :
V_23 -> V_65 = V_238 ;
V_165 [ V_36 ] = L_38 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_72 | V_151 | V_150 |
V_4 | V_88 |
V_152 | V_82 |
V_154 ;
V_23 -> V_19 = 64 ;
break;
case V_239 :
V_23 -> V_65 = V_240 ;
V_165 [ V_36 ] = L_39 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_72 | V_151 | V_150 |
V_4 | V_88 |
V_152 | V_82 |
V_154 ;
V_23 -> V_19 = 64 ;
break;
case V_241 :
switch ( V_23 -> V_26 & V_27 ) {
case V_242 :
V_23 -> V_65 = V_243 ;
V_165 [ V_36 ] = L_40 ;
F_21 ( V_36 , L_41 ) ;
F_37 ( V_23 , V_57 ) ;
break;
case V_244 :
V_23 -> V_65 = V_243 ;
V_165 [ V_36 ] = L_40 ;
F_21 ( V_36 , L_42 ) ;
F_37 ( V_23 , V_57 ) ;
break;
case V_245 :
V_23 -> V_65 = V_246 ;
V_165 [ V_36 ] = L_43 ;
F_21 ( V_36 , L_44 ) ;
F_37 ( V_23 , V_53 ) ;
break;
case V_247 :
case V_248 :
V_23 -> V_65 = V_246 ;
V_165 [ V_36 ] = L_43 ;
F_21 ( V_36 , L_45 ) ;
F_37 ( V_23 , V_53 ) ;
break;
}
V_23 -> V_3 = V_188 |
V_4 | V_154 |
V_88 ;
V_23 -> V_19 = 64 ;
V_23 -> V_249 = V_250 ;
break;
case V_251 :
F_58 ( V_23 ) ;
V_23 -> V_65 = V_252 ;
switch ( V_23 -> V_26 & V_27 ) {
case V_253 :
V_165 [ V_36 ] = L_46 ;
break;
}
break;
}
}
static inline void F_70 ( struct V_22 * V_23 , unsigned int V_36 )
{
V_23 -> V_249 = V_250 ;
switch ( V_23 -> V_26 & V_162 ) {
case V_254 :
V_23 -> V_249 = V_255 ;
V_23 -> V_65 = V_256 ;
V_165 [ V_36 ] = L_47 ;
break;
case V_257 :
V_23 -> V_65 = V_258 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_48 ;
break;
case V_259 :
case V_260 :
V_23 -> V_65 = V_261 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_49 ;
break;
case V_262 :
case V_263 :
V_23 -> V_65 = V_264 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_50 ;
break;
case V_265 :
V_23 -> V_65 = V_266 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_51 ;
break;
case V_267 :
V_23 -> V_65 = V_268 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_52 ;
break;
case V_269 :
V_23 -> V_65 = V_270 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_53 ;
break;
case V_271 :
V_23 -> V_65 = V_272 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_54 ;
break;
case V_273 :
V_23 -> V_65 = V_272 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_55 ;
break;
case V_274 :
V_23 -> V_65 = V_275 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_56 ;
break;
case V_276 :
V_23 -> V_65 = V_25 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_57 ;
break;
case V_277 :
V_23 -> V_65 = V_278 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_58 ;
break;
case V_279 :
V_23 -> V_65 = V_280 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_59 ;
break;
case V_281 :
V_23 -> V_65 = V_282 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_60 ;
break;
case V_283 :
V_23 -> V_65 = V_284 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_61 ;
break;
case V_285 :
V_23 -> V_65 = V_286 ;
V_23 -> V_249 = V_255 ;
V_165 [ V_36 ] = L_62 ;
break;
case V_287 :
V_23 -> V_65 = V_288 ;
V_165 [ V_36 ] = L_63 ;
break;
case V_289 :
V_23 -> V_65 = V_288 ;
V_165 [ V_36 ] = L_64 ;
break;
case V_290 :
V_23 -> V_65 = V_66 ;
V_165 [ V_36 ] = L_65 ;
break;
case V_291 :
V_23 -> V_65 = V_66 ;
V_165 [ V_36 ] = L_66 ;
break;
case V_292 :
V_23 -> V_65 = V_67 ;
V_165 [ V_36 ] = L_67 ;
break;
case V_293 :
V_23 -> V_65 = V_294 ;
V_165 [ V_36 ] = L_68 ;
break;
}
F_58 ( V_23 ) ;
F_71 () ;
}
static inline void F_72 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_162 ) {
case V_295 :
case V_296 :
V_23 -> V_65 = V_297 ;
switch ( ( V_23 -> V_26 >> 24 ) & 0xff ) {
case 0 :
V_165 [ V_36 ] = L_69 ;
break;
case 1 :
V_165 [ V_36 ] = L_70 ;
break;
case 2 :
V_165 [ V_36 ] = L_71 ;
break;
case 3 :
V_165 [ V_36 ] = L_72 ;
break;
case 4 :
V_165 [ V_36 ] = L_73 ;
if ( ( V_23 -> V_26 & V_27 ) == 2 )
V_165 [ V_36 ] = L_74 ;
break;
case 5 :
V_165 [ V_36 ] = L_75 ;
break;
default:
V_165 [ V_36 ] = L_76 ;
break;
}
break;
}
}
static inline void F_73 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
V_23 -> V_249 = V_250 ;
switch ( V_23 -> V_26 & V_162 ) {
case V_298 :
V_23 -> V_65 = V_299 ;
V_165 [ V_36 ] = L_77 ;
if ( ( V_23 -> V_26 & V_27 ) < 0x02 )
V_23 -> V_3 &= ~ ( V_4 | V_88 ) ;
break;
case V_300 :
V_23 -> V_65 = V_301 ;
V_165 [ V_36 ] = L_78 ;
break;
}
}
static inline void F_74 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_162 ) {
case V_302 :
V_23 -> V_65 = V_303 ;
V_165 [ V_36 ] = L_79 ;
V_23 -> V_93 . V_304 = 8 ;
V_23 -> V_19 = 64 ;
break;
}
}
static inline void F_75 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_162 ) {
case V_305 :
V_23 -> V_65 = V_306 ;
V_165 [ V_36 ] = L_80 ;
F_37 ( V_23 , V_54 ) ;
break;
}
}
static inline void F_76 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_162 ) {
case V_307 :
case V_308 :
V_23 -> V_65 = V_309 ;
V_165 [ V_36 ] = L_81 ;
F_21 ( V_36 , L_82 ) ;
break;
case V_310 :
case V_311 :
case V_312 :
V_23 -> V_65 = V_313 ;
V_165 [ V_36 ] = L_83 ;
F_21 ( V_36 , L_84 ) ;
break;
case V_314 : {
int V_315 = V_23 -> V_26 & V_27 ;
if ( V_315 >= V_316 &&
V_315 <= V_317 ) {
V_23 -> V_65 = V_318 ;
V_165 [ V_36 ] = L_85 ;
F_21 ( V_36 , L_86 ) ;
} else {
V_23 -> V_65 = V_319 ;
V_165 [ V_36 ] = L_87 ;
F_21 ( V_36 , L_88 ) ;
}
break;
}
case V_320 :
case V_321 :
V_23 -> V_65 = V_322 ;
V_165 [ V_36 ] = L_89 ;
F_21 ( V_36 , L_90 ) ;
V_23 -> V_3 |= V_110 ;
break;
}
}
static inline void F_77 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_162 ) {
case V_323 :
case V_324 :
case V_325 :
V_23 -> V_65 = V_326 ;
V_165 [ V_36 ] = L_91 ;
goto V_327;
case V_328 :
case V_329 :
case V_330 :
case V_331 :
V_23 -> V_65 = V_332 ;
V_165 [ V_36 ] = L_92 ;
V_327:
F_21 ( V_36 , L_93 ) ;
break;
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
V_23 -> V_65 = V_338 ;
V_165 [ V_36 ] = L_94 ;
F_21 ( V_36 , L_95 ) ;
break;
case V_339 :
case V_340 :
V_23 -> V_65 = V_341 ;
V_165 [ V_36 ] = L_96 ;
F_21 ( V_36 , L_97 ) ;
break;
default:
F_68 ( V_201 L_98 ) ;
V_23 -> V_65 = V_342 ;
break;
}
}
static inline void F_78 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
V_23 -> V_3 &= ~ V_152 ;
F_59 ( ! F_79 ( V_343 ) || V_343 ) ;
switch ( V_23 -> V_26 & V_162 ) {
case V_344 :
V_23 -> V_65 = V_345 ;
V_23 -> V_249 = V_250 ;
V_165 [ V_36 ] = L_99 ;
break;
default:
F_43 ( L_100 ) ;
break;
}
}
static inline void F_80 ( struct V_22 * V_23 , int V_36 )
{
F_58 ( V_23 ) ;
if ( ( V_23 -> V_26 & V_162 ) == V_346 ) {
V_23 -> V_65 = V_297 ;
V_165 [ V_36 ] = L_101 ;
return;
}
V_23 -> V_3 = ( V_72 |
V_150 |
V_152 |
V_153 |
V_82 |
V_86 |
V_154 ) ;
switch ( V_23 -> V_26 & V_162 ) {
case V_347 :
case V_348 :
case V_349 :
V_23 -> V_65 = V_350 ;
V_165 [ V_36 ] = L_102 ;
break;
case V_351 :
case V_352 :
V_23 -> V_65 = V_350 ;
V_165 [ V_36 ] = L_103 ;
break;
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
V_23 -> V_65 = V_361 ;
V_165 [ V_36 ] = L_104 ;
break;
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
V_23 -> V_65 = V_361 ;
V_165 [ V_36 ] = L_105 ;
break;
default:
F_11 ( L_106 ,
V_23 -> V_26 ) ;
V_23 -> V_65 = V_361 ;
break;
}
if ( V_23 -> V_65 == V_350 ) {
F_37 ( V_23 , V_50 ) ;
V_23 -> V_3 |= ( V_4 | V_110 | V_155 ) ;
V_23 -> V_19 = ( ( F_39 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_37 ( V_23 , V_53 ) ;
V_23 -> V_19 = ( ( F_45 () >> 25 ) & 0x3f ) + 1 ;
}
V_23 -> V_139 = 0xf ;
}
void F_81 ( void )
{
struct V_22 * V_23 = & V_24 ;
unsigned int V_36 = F_82 () ;
V_23 -> V_26 = V_375 ;
V_23 -> V_40 = V_44 ;
V_23 -> V_65 = V_342 ;
V_23 -> V_249 = V_255 ;
V_23 -> V_26 = F_83 () ;
switch ( V_23 -> V_26 & V_376 ) {
case V_377 :
F_67 ( V_23 , V_36 ) ;
break;
case V_378 :
F_70 ( V_23 , V_36 ) ;
break;
case V_379 :
F_72 ( V_23 , V_36 ) ;
break;
case V_380 :
F_73 ( V_23 , V_36 ) ;
break;
case V_381 :
F_76 ( V_23 , V_36 ) ;
break;
case V_382 :
F_74 ( V_23 , V_36 ) ;
break;
case V_383 :
F_75 ( V_23 , V_36 ) ;
break;
case V_384 :
F_77 ( V_23 , V_36 ) ;
break;
case V_385 :
F_78 ( V_23 , V_36 ) ;
break;
case V_386 :
F_80 ( V_23 , V_36 ) ;
break;
}
F_59 ( ! V_165 [ V_36 ] ) ;
F_59 ( V_23 -> V_65 == V_342 ) ;
F_59 ( F_13 () != V_23 -> V_65 ) ;
if ( V_5 )
V_23 -> V_3 &= ~ V_4 ;
if ( V_9 )
V_23 -> V_6 &= ~ ( V_7 | V_8 ) ;
if ( V_10 ) {
V_23 -> V_3 &= ~ V_11 ;
F_4 ( F_5 () &
~ ( 1 << V_12 ) ) ;
}
if ( V_23 -> V_3 & V_4 ) {
V_23 -> V_40 = F_22 () ;
if ( V_23 -> V_51 & V_387 ) {
if ( V_23 -> V_40 & V_388 )
V_23 -> V_6 |= V_389 ;
if ( V_23 -> V_40 & V_390 )
V_23 -> V_3 |= V_391 ;
}
}
if ( V_159 ) {
V_23 -> V_392 = ( ( F_84 () >> 26 ) & 0x0f ) + 1 ;
V_23 -> V_3 |= V_393 ;
}
else
V_23 -> V_392 = 1 ;
if ( V_394 ) {
V_23 -> V_46 = F_28 () ;
F_85 ( V_23 -> V_46 & V_395 ,
L_107 ) ;
}
F_32 ( V_23 ) ;
#ifdef F_86
if ( V_36 == 0 )
V_396 = ~ ( ( 1ull << V_397 ) - 1 ) ;
#endif
}
void F_87 ( void )
{
struct V_22 * V_23 = & V_24 ;
F_11 ( L_108 ,
F_82 () , V_23 -> V_26 , F_88 () ) ;
if ( V_23 -> V_3 & V_4 )
F_68 ( V_201 L_109 , V_23 -> V_40 ) ;
if ( V_394 )
F_11 ( L_110 , V_23 -> V_46 ) ;
}
