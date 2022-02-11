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
unsigned int V_59 = V_23 -> V_19 / V_23 -> V_60 ;
if ( V_59 >= 12 )
return 1 ;
else if ( V_59 >= 6 )
return 2 ;
else
return 3 ;
}
static void F_7 ( struct V_22 * V_23 , int V_61 )
{
unsigned int V_62 ;
switch ( V_23 -> V_63 ) {
case V_64 :
case V_65 :
V_62 = F_39 () ;
V_62 &= ~ ( 3 << V_66 ) ;
if ( V_61 )
F_40 ( V_62 |
( F_38 ( V_23 )
<< V_66 )
| V_67 ) ;
else
F_40 ( V_62 & ~ V_67 ) ;
F_8 () ;
break;
}
}
static inline unsigned int F_41 ( struct V_22 * V_23 )
{
unsigned int V_68 ;
int V_49 ;
V_68 = F_42 () ;
if ( ( ( ( V_68 & V_69 ) >> 7 ) == 1 ) ||
( ( ( V_68 & V_69 ) >> 7 ) == 4 ) )
V_23 -> V_3 |= V_70 ;
V_49 = ( V_68 & V_71 ) >> 13 ;
switch ( V_49 ) {
case 0 :
switch ( ( V_68 & V_72 ) >> 10 ) {
case 0 :
F_37 ( V_23 , V_54 ) ;
break;
case 1 :
F_37 ( V_23 , V_52 ) ;
break;
default:
goto V_73;
}
break;
case 2 :
switch ( ( V_68 & V_72 ) >> 10 ) {
case 0 :
F_37 ( V_23 , V_53 ) ;
break;
case 1 :
F_37 ( V_23 , V_50 ) ;
break;
default:
goto V_73;
}
break;
default:
goto V_73;
}
return V_68 & V_74 ;
V_73:
F_43 ( V_75 , V_68 ) ;
}
static inline unsigned int F_44 ( struct V_22 * V_23 )
{
unsigned int V_76 ;
V_76 = F_45 () ;
if ( V_76 & V_77 )
V_23 -> V_6 |= V_78 ;
if ( V_76 & V_79 )
V_23 -> V_3 |= V_80 ;
if ( V_76 & V_81 )
V_23 -> V_6 |= V_82 ;
if ( V_76 & V_83 )
V_23 -> V_3 |= V_84 ;
if ( V_76 & V_85 ) {
V_23 -> V_3 |= V_4 ;
V_23 -> V_3 |= V_86 ;
}
if ( V_87 ) {
V_23 -> V_19 = ( ( V_76 & V_88 ) >> 25 ) + 1 ;
V_23 -> V_60 = V_23 -> V_19 ;
V_23 -> V_21 = 0 ;
}
return V_76 & V_74 ;
}
static inline unsigned int F_46 ( struct V_22 * V_23 )
{
unsigned int V_89 ;
V_89 = F_47 () ;
if ( V_89 & V_90 )
V_23 -> V_91 . V_92 &= ~ V_93 ;
return V_89 & V_74 ;
}
static inline unsigned int F_48 ( struct V_22 * V_23 )
{
unsigned int V_94 ;
V_94 = F_49 () ;
if ( V_94 & V_95 ) {
V_23 -> V_6 |= V_96 ;
V_23 -> V_3 |= V_97 ;
}
if ( V_94 & V_98 )
V_23 -> V_3 |= V_97 ;
if ( V_94 & V_99 )
V_23 -> V_6 |= V_7 ;
if ( V_94 & V_100 )
V_23 -> V_6 |= V_8 ;
if ( V_94 & V_101 )
V_23 -> V_3 |= V_102 ;
if ( V_94 & V_103 )
V_23 -> V_3 |= V_104 ;
if ( V_94 & V_105 )
V_23 -> V_6 |= V_106 ;
if ( V_94 & V_107 )
V_23 -> V_3 |= V_108 ;
if ( V_94 & V_109 )
V_23 -> V_3 |= V_110 ;
if ( V_94 & V_111 )
V_23 -> V_6 |= V_112 ;
if ( V_94 & V_113 )
V_23 -> V_3 |= V_114 ;
if ( V_94 & V_115 )
V_23 -> V_6 |= V_116 ;
if ( ( V_94 & V_117 ) && F_50 ( V_118 ) )
V_23 -> V_3 |= V_11 ;
return V_94 & V_74 ;
}
static inline unsigned int F_51 ( struct V_22 * V_23 )
{
unsigned int V_13 ;
unsigned int V_119 ;
unsigned int V_14 ;
unsigned int V_120 = V_121 ;
V_13 = F_9 () ;
if ( V_87 ) {
if ( ( ( V_13 & V_122 ) >> 29 ) == 2 )
V_23 -> V_3 |= V_123 ;
V_14 = V_13 & V_16 ;
switch ( V_14 ) {
case V_124 :
V_23 -> V_19 += ( V_13 & V_125 ) * 0x40 ;
V_23 -> V_60 = V_23 -> V_19 ;
break;
case V_126 :
V_23 -> V_60 +=
( ( V_13 & V_127 ) >>
V_128 ) * 0x40 ;
V_23 -> V_19 = V_23 -> V_60 ;
V_120 = V_129 ;
case V_17 :
if ( V_18 )
break;
V_119 = ( V_13 & ~ V_120 ) |
( F_52 ( V_14 ) <<
V_130 ) ;
F_53 ( V_119 ) ;
F_8 () ;
V_13 = F_9 () ;
if ( V_13 != V_119 ) {
F_54 ( L_3 ,
V_131 , V_13 ) ;
F_7 ( V_23 , 0 ) ;
break;
}
V_23 -> V_21 = 1 <<
( ( V_13 & V_132 ) >>
V_133 ) ;
V_23 -> V_20 = ( ( V_13 & V_134 ) >>
V_135 ) + 2 ;
V_23 -> V_19 += V_23 -> V_20 * V_23 -> V_21 ;
V_15 = 1 ;
break;
}
}
V_23 -> V_136 = ( V_13 >> 16 ) & 0xff ;
return V_13 & V_74 ;
}
static inline unsigned int F_55 ( struct V_22 * V_23 )
{
unsigned int V_137 ;
V_137 = F_56 () ;
V_137 &= ~ ( V_138 | V_139 ) ;
F_57 ( V_137 ) ;
if ( V_137 & V_140 )
V_23 -> V_3 |= V_141 ;
if ( V_137 & V_142 )
V_23 -> V_3 |= V_143 ;
return V_137 & V_74 ;
}
static void F_58 ( struct V_22 * V_23 )
{
int V_144 ;
V_23 -> V_3 = V_145 | V_146 | V_147 |
V_148 | V_149 | V_150 ;
V_23 -> V_91 . V_92 = V_93 ;
F_7 ( V_23 , ! V_18 ) ;
V_144 = F_41 ( V_23 ) ;
F_59 ( ! V_144 ) ;
if ( V_144 )
V_144 = F_44 ( V_23 ) ;
if ( V_144 )
V_144 = F_46 ( V_23 ) ;
if ( V_144 )
V_144 = F_48 ( V_23 ) ;
if ( V_144 )
V_144 = F_51 ( V_23 ) ;
if ( V_144 )
V_144 = F_55 ( V_23 ) ;
F_60 ( V_23 ) ;
if ( V_151 ) {
F_61 ( F_62 () | V_152 ) ;
F_8 () ;
if ( F_62 () & V_152 )
V_23 -> V_3 |= V_153 ;
}
#ifndef F_63
if ( V_154 ) {
V_23 -> V_155 = F_64 () ;
if ( V_156 )
V_23 -> V_155 >>= F_65 ( F_66 () ) - 1 ;
}
#endif
}
static inline void F_67 ( struct V_22 * V_23 , unsigned int V_36 )
{
switch ( V_23 -> V_26 & V_157 ) {
case V_158 :
V_23 -> V_63 = V_159 ;
V_160 [ V_36 ] = L_4 ;
V_23 -> V_3 = V_70 | V_161 |
V_162 ;
if ( F_27 () )
V_23 -> V_3 |= V_4 ;
V_23 -> V_19 = 64 ;
break;
case V_163 :
if ( ( V_23 -> V_26 & V_27 ) == V_164 ) {
if ( F_17 () ) {
V_23 -> V_63 = V_165 ;
V_160 [ V_36 ] = L_5 ;
} else {
V_23 -> V_63 = V_166 ;
V_160 [ V_36 ] = L_6 ;
}
} else {
V_23 -> V_63 = V_167 ;
V_160 [ V_36 ] = L_7 ;
}
V_23 -> V_3 = V_70 | V_161 |
V_162 ;
if ( F_27 () )
V_23 -> V_3 |= V_4 ;
V_23 -> V_19 = 64 ;
break;
case V_168 :
if ( F_42 () & V_169 ) {
if ( ( V_23 -> V_26 & V_27 ) >=
V_170 ) {
V_23 -> V_63 = V_171 ;
V_160 [ V_36 ] = L_8 ;
} else {
V_23 -> V_63 = V_172 ;
V_160 [ V_36 ] = L_9 ;
}
} else {
int V_173 = F_42 () & V_174 ;
int V_175 ;
switch ( V_173 ) {
case V_176 :
case V_177 :
case V_178 :
V_175 = 1 ;
break;
default:
V_175 = 0 ;
break;
}
if ( ( V_23 -> V_26 & V_27 ) >=
V_170 ) {
V_23 -> V_63 = V_175 ? V_179 : V_180 ;
V_160 [ V_36 ] = V_175 ? L_10 : L_11 ;
} else {
V_23 -> V_63 = V_175 ? V_181 : V_182 ;
V_160 [ V_36 ] = V_175 ? L_12 : L_13 ;
}
}
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_183 | V_4 | V_86 |
V_80 | V_184 |
V_149 ;
V_23 -> V_19 = 48 ;
break;
case V_185 :
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_183 ;
V_23 -> V_19 = 32 ;
switch ( V_23 -> V_26 & 0xf0 ) {
case V_186 :
V_23 -> V_63 = V_187 ;
V_160 [ V_36 ] = L_14 ;
break;
case V_188 :
V_23 -> V_63 = V_189 ;
V_160 [ V_36 ] = L_15 ;
break;
case V_190 :
if ( ( V_23 -> V_26 & 0xf ) < 0x3 ) {
V_23 -> V_63 = V_191 ;
V_160 [ V_36 ] = L_16 ;
} else {
V_23 -> V_63 = V_192 ;
V_160 [ V_36 ] = L_17 ;
}
break;
case V_193 :
if ( ( V_23 -> V_26 & 0xf ) < 0x4 ) {
V_23 -> V_63 = V_194 ;
V_160 [ V_36 ] = L_18 ;
} else {
V_23 -> V_63 = V_195 ;
V_23 -> V_3 |= V_149 ;
V_160 [ V_36 ] = L_19 ;
}
break;
default:
F_68 ( V_196 L_20 ) ;
V_23 -> V_63 = V_197 ;
V_160 [ V_36 ] = L_21 ;
break;
}
break;
case V_198 :
V_23 -> V_63 = V_199 ;
V_160 [ V_36 ] = L_22 ;
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_183 | V_4 | V_86 |
V_149 ;
V_23 -> V_19 = 32 ;
break;
case V_200 :
V_23 -> V_63 = V_201 ;
V_160 [ V_36 ] = L_23 ;
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_183 | V_4 | V_86 |
V_149 ;
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
case V_202 :
V_23 -> V_3 = V_70 | V_203 ;
if ( ( V_23 -> V_26 & 0xf0 ) == ( V_204 & 0xf0 ) ) {
V_23 -> V_63 = V_205 ;
V_160 [ V_36 ] = L_24 ;
V_23 -> V_19 = 64 ;
} else {
switch ( V_23 -> V_26 & V_27 ) {
case V_206 :
V_23 -> V_63 = V_207 ;
V_160 [ V_36 ] = L_25 ;
V_23 -> V_19 = 32 ;
break;
case V_208 :
V_23 -> V_63 = V_209 ;
V_160 [ V_36 ] = L_26 ;
V_23 -> V_19 = 64 ;
break;
}
}
break;
case V_210 :
V_23 -> V_63 = V_211 ;
V_160 [ V_36 ] = L_27 ;
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_183 | V_4 | V_86 |
V_149 ;
V_23 -> V_19 = 48 ;
break;
case V_212 :
V_23 -> V_63 = V_213 ;
V_160 [ V_36 ] = L_28 ;
F_37 ( V_23 , V_57 ) ;
V_23 -> V_3 = V_183 | V_149 ;
if ( ! ( V_23 -> V_26 & 0x08 ) )
V_23 -> V_3 |= V_4 | V_86 ;
V_23 -> V_19 = 48 ;
break;
case V_214 :
V_23 -> V_63 = V_215 ;
V_160 [ V_36 ] = L_29 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_183 | V_4 | V_86 |
V_149 ;
V_23 -> V_19 = 48 ;
break;
case V_216 :
V_23 -> V_63 = V_217 ;
V_160 [ V_36 ] = L_30 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_183 | V_4 | V_86 |
V_80 | V_149 ;
V_23 -> V_19 = 48 ;
break;
case V_218 :
V_23 -> V_63 = V_219 ;
V_160 [ V_36 ] = L_31 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_183 | V_4 | V_86 |
V_80 | V_149 ;
V_23 -> V_19 = 48 ;
break;
case V_220 :
V_23 -> V_63 = V_221 ;
V_160 [ V_36 ] = L_32 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_183 | V_4 | V_86 |
V_148 | V_149 ;
V_23 -> V_19 = 48 ;
break;
case V_222 :
V_23 -> V_63 = V_223 ;
V_160 [ V_36 ] = L_33 ;
F_37 ( V_23 , V_58 ) ;
V_23 -> V_3 = V_70 | V_4 |
V_149 ;
V_23 -> V_19 = 32 ;
break;
case V_224 :
V_23 -> V_63 = V_225 ;
V_160 [ V_36 ] = L_34 ;
F_37 ( V_23 , V_58 ) ;
V_23 -> V_3 = V_70 | V_4 |
V_149 ;
V_23 -> V_19 = 32 ;
break;
case V_226 :
V_23 -> V_63 = V_227 ;
V_160 [ V_36 ] = L_35 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_183 | V_4 | V_86 |
V_149 ;
V_23 -> V_19 = ( F_69 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_228 :
V_23 -> V_63 = V_229 ;
V_160 [ V_36 ] = L_36 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_70 | V_145 |
V_4 | V_86 |
V_149 ;
V_23 -> V_19 = 384 ;
break;
case V_230 :
V_23 -> V_63 = V_231 ;
V_160 [ V_36 ] = L_37 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_70 | V_146 | V_145 |
V_4 | V_86 |
V_147 | V_80 |
V_149 ;
V_23 -> V_19 = 64 ;
break;
case V_232 :
V_23 -> V_63 = V_233 ;
V_160 [ V_36 ] = L_38 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_70 | V_146 | V_145 |
V_4 | V_86 |
V_147 | V_80 |
V_149 ;
V_23 -> V_19 = 64 ;
break;
case V_234 :
V_23 -> V_63 = V_235 ;
V_160 [ V_36 ] = L_39 ;
F_37 ( V_23 , V_56 ) ;
V_23 -> V_3 = V_70 | V_146 | V_145 |
V_4 | V_86 |
V_147 | V_80 |
V_149 ;
V_23 -> V_19 = 64 ;
break;
case V_236 :
switch ( V_23 -> V_26 & V_27 ) {
case V_237 :
V_23 -> V_63 = V_238 ;
V_160 [ V_36 ] = L_40 ;
F_21 ( V_36 , L_41 ) ;
F_37 ( V_23 , V_57 ) ;
break;
case V_239 :
V_23 -> V_63 = V_238 ;
V_160 [ V_36 ] = L_40 ;
F_21 ( V_36 , L_42 ) ;
F_37 ( V_23 , V_57 ) ;
break;
case V_240 :
V_23 -> V_63 = V_241 ;
V_160 [ V_36 ] = L_43 ;
F_21 ( V_36 , L_44 ) ;
F_37 ( V_23 , V_53 ) ;
break;
case V_242 :
case V_243 :
V_23 -> V_63 = V_241 ;
V_160 [ V_36 ] = L_43 ;
F_21 ( V_36 , L_45 ) ;
F_37 ( V_23 , V_53 ) ;
break;
}
V_23 -> V_3 = V_183 |
V_4 | V_149 |
V_86 ;
V_23 -> V_19 = 64 ;
V_23 -> V_244 = V_245 ;
break;
case V_246 :
F_58 ( V_23 ) ;
V_23 -> V_63 = V_247 ;
switch ( V_23 -> V_26 & V_27 ) {
case V_248 :
V_160 [ V_36 ] = L_46 ;
break;
}
break;
}
}
static inline void F_70 ( struct V_22 * V_23 , unsigned int V_36 )
{
V_23 -> V_244 = V_245 ;
switch ( V_23 -> V_26 & V_157 ) {
case V_249 :
V_23 -> V_63 = V_250 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_47 ;
break;
case V_252 :
case V_253 :
V_23 -> V_63 = V_254 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_48 ;
break;
case V_255 :
case V_256 :
V_23 -> V_63 = V_257 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_49 ;
break;
case V_258 :
V_23 -> V_63 = V_259 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_50 ;
break;
case V_260 :
V_23 -> V_63 = V_261 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_51 ;
break;
case V_262 :
V_23 -> V_63 = V_263 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_52 ;
break;
case V_264 :
V_23 -> V_63 = V_265 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_53 ;
break;
case V_266 :
V_23 -> V_63 = V_265 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_54 ;
break;
case V_267 :
V_23 -> V_63 = V_268 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_55 ;
break;
case V_269 :
V_23 -> V_63 = V_25 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_56 ;
break;
case V_270 :
V_23 -> V_63 = V_271 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_57 ;
break;
case V_272 :
V_23 -> V_63 = V_273 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_58 ;
break;
case V_274 :
V_23 -> V_63 = V_275 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_59 ;
break;
case V_276 :
V_23 -> V_63 = V_277 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_60 ;
break;
case V_278 :
V_23 -> V_63 = V_279 ;
V_23 -> V_244 = V_251 ;
V_160 [ V_36 ] = L_61 ;
break;
case V_280 :
V_23 -> V_63 = V_281 ;
V_160 [ V_36 ] = L_62 ;
break;
case V_282 :
V_23 -> V_63 = V_281 ;
V_160 [ V_36 ] = L_63 ;
break;
case V_283 :
V_23 -> V_63 = V_64 ;
V_160 [ V_36 ] = L_64 ;
break;
case V_284 :
V_23 -> V_63 = V_64 ;
V_160 [ V_36 ] = L_65 ;
break;
case V_285 :
V_23 -> V_63 = V_65 ;
V_160 [ V_36 ] = L_66 ;
break;
case V_286 :
V_23 -> V_63 = V_287 ;
V_160 [ V_36 ] = L_67 ;
break;
}
F_58 ( V_23 ) ;
F_71 () ;
}
static inline void F_72 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_157 ) {
case V_288 :
case V_289 :
V_23 -> V_63 = V_290 ;
switch ( ( V_23 -> V_26 >> 24 ) & 0xff ) {
case 0 :
V_160 [ V_36 ] = L_68 ;
break;
case 1 :
V_160 [ V_36 ] = L_69 ;
break;
case 2 :
V_160 [ V_36 ] = L_70 ;
break;
case 3 :
V_160 [ V_36 ] = L_71 ;
break;
case 4 :
V_160 [ V_36 ] = L_72 ;
if ( ( V_23 -> V_26 & V_27 ) == 2 )
V_160 [ V_36 ] = L_73 ;
break;
case 5 :
V_160 [ V_36 ] = L_74 ;
break;
default:
V_160 [ V_36 ] = L_75 ;
break;
}
break;
}
}
static inline void F_73 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
V_23 -> V_244 = V_245 ;
switch ( V_23 -> V_26 & V_157 ) {
case V_291 :
V_23 -> V_63 = V_292 ;
V_160 [ V_36 ] = L_76 ;
if ( ( V_23 -> V_26 & V_27 ) < 0x02 )
V_23 -> V_3 &= ~ ( V_4 | V_86 ) ;
break;
case V_293 :
V_23 -> V_63 = V_294 ;
V_160 [ V_36 ] = L_77 ;
break;
}
}
static inline void F_74 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_157 ) {
case V_295 :
V_23 -> V_63 = V_296 ;
V_160 [ V_36 ] = L_78 ;
V_23 -> V_91 . V_297 = 8 ;
V_23 -> V_19 = 64 ;
break;
}
}
static inline void F_75 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_157 ) {
case V_298 :
V_23 -> V_63 = V_299 ;
V_160 [ V_36 ] = L_79 ;
F_37 ( V_23 , V_54 ) ;
break;
}
}
static inline void F_76 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_157 ) {
case V_300 :
case V_301 :
V_23 -> V_63 = V_302 ;
V_160 [ V_36 ] = L_80 ;
F_21 ( V_36 , L_81 ) ;
break;
case V_303 :
case V_304 :
case V_305 :
V_23 -> V_63 = V_306 ;
V_160 [ V_36 ] = L_82 ;
F_21 ( V_36 , L_83 ) ;
break;
case V_307 : {
int V_308 = V_23 -> V_26 & V_27 ;
if ( V_308 >= V_309 &&
V_308 <= V_310 ) {
V_23 -> V_63 = V_311 ;
V_160 [ V_36 ] = L_84 ;
F_21 ( V_36 , L_85 ) ;
} else {
V_23 -> V_63 = V_312 ;
V_160 [ V_36 ] = L_86 ;
F_21 ( V_36 , L_87 ) ;
}
break;
}
case V_313 :
case V_314 :
V_23 -> V_63 = V_315 ;
V_160 [ V_36 ] = L_88 ;
F_21 ( V_36 , L_89 ) ;
V_23 -> V_3 |= V_108 ;
break;
}
}
static inline void F_77 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
switch ( V_23 -> V_26 & V_157 ) {
case V_316 :
case V_317 :
case V_318 :
V_23 -> V_63 = V_319 ;
V_160 [ V_36 ] = L_90 ;
goto V_320;
case V_321 :
case V_322 :
case V_323 :
case V_324 :
V_23 -> V_63 = V_325 ;
V_160 [ V_36 ] = L_91 ;
V_320:
F_21 ( V_36 , L_92 ) ;
break;
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
V_23 -> V_63 = V_331 ;
V_160 [ V_36 ] = L_93 ;
F_21 ( V_36 , L_94 ) ;
break;
case V_332 :
case V_333 :
V_23 -> V_63 = V_334 ;
V_160 [ V_36 ] = L_95 ;
F_21 ( V_36 , L_96 ) ;
break;
default:
F_68 ( V_196 L_97 ) ;
V_23 -> V_63 = V_335 ;
break;
}
}
static inline void F_78 ( struct V_22 * V_23 , unsigned int V_36 )
{
F_58 ( V_23 ) ;
V_23 -> V_3 &= ~ V_147 ;
F_59 ( ! F_79 ( V_336 ) || V_336 ) ;
switch ( V_23 -> V_26 & V_157 ) {
case V_337 :
V_23 -> V_63 = V_338 ;
V_23 -> V_244 = V_245 ;
V_160 [ V_36 ] = L_98 ;
break;
default:
F_43 ( L_99 ) ;
break;
}
}
static inline void F_80 ( struct V_22 * V_23 , int V_36 )
{
F_58 ( V_23 ) ;
if ( ( V_23 -> V_26 & V_157 ) == V_339 ) {
V_23 -> V_63 = V_290 ;
V_160 [ V_36 ] = L_100 ;
return;
}
V_23 -> V_3 = ( V_70 |
V_145 |
V_147 |
V_148 |
V_80 |
V_84 |
V_149 ) ;
switch ( V_23 -> V_26 & V_157 ) {
case V_340 :
case V_341 :
case V_342 :
V_23 -> V_63 = V_343 ;
V_160 [ V_36 ] = L_101 ;
break;
case V_344 :
case V_345 :
V_23 -> V_63 = V_343 ;
V_160 [ V_36 ] = L_102 ;
break;
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
V_23 -> V_63 = V_354 ;
V_160 [ V_36 ] = L_103 ;
break;
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
V_23 -> V_63 = V_354 ;
V_160 [ V_36 ] = L_104 ;
break;
default:
F_11 ( L_105 ,
V_23 -> V_26 ) ;
V_23 -> V_63 = V_354 ;
break;
}
if ( V_23 -> V_63 == V_343 ) {
F_37 ( V_23 , V_50 ) ;
V_23 -> V_3 |= ( V_4 | V_108 | V_150 ) ;
V_23 -> V_19 = ( ( F_39 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_37 ( V_23 , V_53 ) ;
V_23 -> V_19 = ( ( F_45 () >> 25 ) & 0x3f ) + 1 ;
}
V_23 -> V_136 = 0xf ;
}
void F_81 ( void )
{
struct V_22 * V_23 = & V_24 ;
unsigned int V_36 = F_82 () ;
V_23 -> V_26 = V_368 ;
V_23 -> V_40 = V_44 ;
V_23 -> V_63 = V_335 ;
V_23 -> V_244 = V_251 ;
V_23 -> V_26 = F_83 () ;
switch ( V_23 -> V_26 & V_369 ) {
case V_370 :
F_67 ( V_23 , V_36 ) ;
break;
case V_371 :
F_70 ( V_23 , V_36 ) ;
break;
case V_372 :
F_72 ( V_23 , V_36 ) ;
break;
case V_373 :
F_73 ( V_23 , V_36 ) ;
break;
case V_374 :
F_76 ( V_23 , V_36 ) ;
break;
case V_375 :
F_74 ( V_23 , V_36 ) ;
break;
case V_376 :
F_75 ( V_23 , V_36 ) ;
break;
case V_377 :
F_77 ( V_23 , V_36 ) ;
break;
case V_378 :
F_78 ( V_23 , V_36 ) ;
break;
case V_379 :
F_80 ( V_23 , V_36 ) ;
break;
}
F_59 ( ! V_160 [ V_36 ] ) ;
F_59 ( V_23 -> V_63 == V_335 ) ;
F_59 ( F_13 () != V_23 -> V_63 ) ;
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
if ( V_23 -> V_51 & ( V_54 | V_52 |
V_53 | V_50 ) ) {
if ( V_23 -> V_40 & V_380 )
V_23 -> V_6 |= V_381 ;
if ( V_23 -> V_40 & V_382 )
V_23 -> V_3 |= V_383 ;
}
}
if ( V_154 ) {
V_23 -> V_384 = ( ( F_84 () >> 26 ) & 0x0f ) + 1 ;
V_23 -> V_3 |= V_385 ;
}
else
V_23 -> V_384 = 1 ;
if ( V_386 ) {
V_23 -> V_46 = F_28 () ;
F_85 ( V_23 -> V_46 & V_387 ,
L_106 ) ;
}
F_32 ( V_23 ) ;
#ifdef F_86
if ( V_36 == 0 )
V_388 = ~ ( ( 1ull << V_389 ) - 1 ) ;
#endif
}
void F_87 ( void )
{
struct V_22 * V_23 = & V_24 ;
F_11 ( L_107 ,
F_82 () , V_23 -> V_26 , F_88 () ) ;
if ( V_23 -> V_3 & V_4 )
F_68 ( V_196 L_108 , V_23 -> V_40 ) ;
if ( V_386 )
F_11 ( L_109 , V_23 -> V_46 ) ;
}
