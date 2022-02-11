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
static inline void F_19 ( struct V_10 * V_11 )
{
#ifdef F_20
F_21 ( 0x3fffffffffffe000ULL ) ;
F_22 () ;
V_11 -> V_33 = F_23 ( F_24 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void F_25 ( struct V_10 * V_11 , unsigned int V_34 )
{
switch ( V_34 ) {
case V_35 :
V_11 -> V_36 |= V_37 | V_35 ;
case V_38 :
V_11 -> V_36 |= V_39 | V_38 ;
case V_40 :
V_11 -> V_36 |= V_40 ;
case V_41 :
V_11 -> V_36 |= V_41 ;
case V_42 :
V_11 -> V_36 |= V_43 | V_42 ;
break;
case V_37 :
V_11 -> V_36 |= V_37 ;
case V_39 :
V_11 -> V_36 |= V_39 ;
case V_43 :
V_11 -> V_36 |= V_43 ;
break;
}
}
static void F_26 ( struct V_10 * V_11 , int V_44 )
{
unsigned int V_45 ;
if ( V_11 -> V_46 == V_47 ) {
V_45 = F_27 () ;
if ( V_44 )
F_28 ( V_45 | V_48 ) ;
else
F_28 ( V_45 & ~ V_48 ) ;
F_22 () ;
}
}
static inline unsigned int F_29 ( struct V_10 * V_11 )
{
unsigned int V_49 ;
int V_34 ;
V_49 = F_30 () ;
if ( ( ( ( V_49 & V_50 ) >> 7 ) == 1 ) ||
( ( ( V_49 & V_50 ) >> 7 ) == 4 ) )
V_11 -> V_3 |= V_51 ;
V_34 = ( V_49 & V_52 ) >> 13 ;
switch ( V_34 ) {
case 0 :
switch ( ( V_49 & V_53 ) >> 10 ) {
case 0 :
F_25 ( V_11 , V_39 ) ;
break;
case 1 :
F_25 ( V_11 , V_37 ) ;
break;
default:
goto V_54;
}
break;
case 2 :
switch ( ( V_49 & V_53 ) >> 10 ) {
case 0 :
F_25 ( V_11 , V_38 ) ;
break;
case 1 :
F_25 ( V_11 , V_35 ) ;
break;
default:
goto V_54;
}
break;
default:
goto V_54;
}
return V_49 & V_55 ;
V_54:
F_31 ( V_56 , V_49 ) ;
}
static inline unsigned int F_32 ( struct V_10 * V_11 )
{
unsigned int V_57 ;
V_57 = F_33 () ;
if ( V_57 & V_58 )
V_11 -> V_6 |= V_59 ;
if ( V_57 & V_60 )
V_11 -> V_3 |= V_61 ;
if ( V_57 & V_62 )
V_11 -> V_6 |= V_63 ;
if ( V_57 & V_64 )
V_11 -> V_3 |= V_65 ;
if ( V_57 & V_66 ) {
V_11 -> V_3 |= V_4 ;
V_11 -> V_3 |= V_67 ;
}
if ( V_68 ) {
V_11 -> V_69 = ( ( V_57 & V_70 ) >> 25 ) + 1 ;
V_11 -> V_71 = V_11 -> V_69 ;
V_11 -> V_72 = 0 ;
}
return V_57 & V_55 ;
}
static inline unsigned int F_34 ( struct V_10 * V_11 )
{
unsigned int V_73 ;
V_73 = F_35 () ;
if ( V_73 & V_74 )
V_11 -> V_75 . V_76 &= ~ V_77 ;
return V_73 & V_55 ;
}
static inline unsigned int F_36 ( struct V_10 * V_11 )
{
unsigned int V_78 ;
V_78 = F_37 () ;
if ( V_78 & V_79 ) {
V_11 -> V_6 |= V_80 ;
V_11 -> V_3 |= V_81 ;
}
if ( V_78 & V_82 )
V_11 -> V_3 |= V_81 ;
if ( V_78 & V_83 )
V_11 -> V_6 |= V_7 ;
if ( V_78 & V_84 )
V_11 -> V_6 |= V_8 ;
if ( V_78 & V_85 )
V_11 -> V_3 |= V_86 ;
if ( V_78 & V_87 )
V_11 -> V_3 |= V_88 ;
if ( V_78 & V_89 )
V_11 -> V_6 |= V_90 ;
if ( V_78 & V_91 )
V_11 -> V_3 |= V_92 ;
if ( V_78 & V_93 )
V_11 -> V_3 |= V_94 ;
if ( V_78 & V_95 )
V_11 -> V_6 |= V_96 ;
if ( V_78 & V_97 )
V_11 -> V_3 |= V_98 ;
return V_78 & V_55 ;
}
static inline unsigned int F_38 ( struct V_10 * V_11 )
{
unsigned int V_99 ;
unsigned int V_100 ;
unsigned int V_101 ;
unsigned int V_102 = V_103 ;
V_99 = F_39 () ;
if ( V_68 ) {
if ( ( ( V_99 & V_104 ) >> 29 ) == 2 )
V_11 -> V_3 |= V_105 ;
V_101 = V_99 & V_106 ;
switch ( V_101 ) {
case V_107 :
V_11 -> V_69 += ( V_99 & V_108 ) * 0x40 ;
V_11 -> V_71 = V_11 -> V_69 ;
break;
case V_109 :
V_11 -> V_71 +=
( ( V_99 & V_110 ) >>
V_111 ) * 0x40 ;
V_11 -> V_69 = V_11 -> V_71 ;
V_102 = V_112 ;
case V_113 :
V_100 = ( V_99 & ~ V_102 ) |
( F_40 ( V_101 ) <<
V_114 ) ;
F_41 ( V_100 ) ;
F_22 () ;
V_99 = F_39 () ;
if ( V_99 != V_100 ) {
F_42 ( L_1 ,
V_115 , V_99 ) ;
F_26 ( V_11 , 0 ) ;
break;
}
V_11 -> V_72 = 1 <<
( ( V_99 & V_116 ) >>
V_117 ) ;
V_11 -> V_118 = ( ( V_99 & V_119 ) >>
V_120 ) + 2 ;
V_11 -> V_69 += V_11 -> V_118 * V_11 -> V_72 ;
break;
}
}
V_11 -> V_121 = ( V_99 >> 16 ) & 0xff ;
return V_99 & V_55 ;
}
static inline unsigned int F_43 ( struct V_10 * V_11 )
{
unsigned int V_122 ;
V_122 = F_44 () ;
V_122 &= ~ V_123 ;
F_45 ( V_122 ) ;
return V_122 & V_55 ;
}
static void F_46 ( struct V_10 * V_11 )
{
int V_124 ;
V_11 -> V_3 = V_125 | V_126 | V_127 |
V_128 | V_129 | V_130 ;
V_11 -> V_75 . V_76 = V_77 ;
F_26 ( V_11 , 1 ) ;
V_124 = F_29 ( V_11 ) ;
F_47 ( ! V_124 ) ;
if ( V_124 )
V_124 = F_32 ( V_11 ) ;
if ( V_124 )
V_124 = F_34 ( V_11 ) ;
if ( V_124 )
V_124 = F_36 ( V_11 ) ;
if ( V_124 )
V_124 = F_38 ( V_11 ) ;
if ( V_124 )
V_124 = F_43 ( V_11 ) ;
F_48 ( V_11 ) ;
if ( V_131 )
V_11 -> V_132 = F_49 () & 0x3ff ;
}
static inline void F_50 ( struct V_10 * V_11 , unsigned int V_24 )
{
switch ( V_11 -> V_14 & V_133 ) {
case V_134 :
V_11 -> V_46 = V_135 ;
V_136 [ V_24 ] = L_2 ;
V_11 -> V_3 = V_51 | V_137 |
V_138 ;
if ( F_18 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_69 = 64 ;
break;
case V_139 :
if ( ( V_11 -> V_14 & V_15 ) == V_140 ) {
if ( F_8 () ) {
V_11 -> V_46 = V_141 ;
V_136 [ V_24 ] = L_3 ;
} else {
V_11 -> V_46 = V_142 ;
V_136 [ V_24 ] = L_4 ;
}
} else {
V_11 -> V_46 = V_143 ;
V_136 [ V_24 ] = L_5 ;
}
V_11 -> V_3 = V_51 | V_137 |
V_138 ;
if ( F_18 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_69 = 64 ;
break;
case V_144 :
if ( F_30 () & V_145 ) {
if ( ( V_11 -> V_14 & V_15 ) >=
V_146 ) {
V_11 -> V_46 = V_147 ;
V_136 [ V_24 ] = L_6 ;
} else {
V_11 -> V_46 = V_148 ;
V_136 [ V_24 ] = L_7 ;
}
} else {
int V_149 = F_30 () & V_150 ;
int V_151 ;
switch ( V_149 ) {
case V_152 :
case V_153 :
case V_154 :
V_151 = 1 ;
break;
default:
V_151 = 0 ;
break;
}
if ( ( V_11 -> V_14 & V_15 ) >=
V_146 ) {
V_11 -> V_46 = V_151 ? V_155 : V_156 ;
V_136 [ V_24 ] = V_151 ? L_8 : L_9 ;
} else {
V_11 -> V_46 = V_151 ? V_157 : V_158 ;
V_136 [ V_24 ] = V_151 ? L_10 : L_11 ;
}
}
F_25 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_61 | V_160 |
V_129 ;
V_11 -> V_69 = 48 ;
break;
case V_161 :
F_25 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_159 ;
V_11 -> V_69 = 32 ;
switch ( V_11 -> V_14 & 0xf0 ) {
case V_162 :
V_11 -> V_46 = V_163 ;
V_136 [ V_24 ] = L_12 ;
break;
case V_164 :
V_11 -> V_46 = V_165 ;
V_136 [ V_24 ] = L_13 ;
break;
case V_166 :
if ( ( V_11 -> V_14 & 0xf ) < 0x3 ) {
V_11 -> V_46 = V_167 ;
V_136 [ V_24 ] = L_14 ;
} else {
V_11 -> V_46 = V_168 ;
V_136 [ V_24 ] = L_15 ;
}
break;
case V_169 :
if ( ( V_11 -> V_14 & 0xf ) < 0x4 ) {
V_11 -> V_46 = V_170 ;
V_136 [ V_24 ] = L_16 ;
} else {
V_11 -> V_46 = V_171 ;
V_11 -> V_3 |= V_129 ;
V_136 [ V_24 ] = L_17 ;
}
break;
default:
F_51 ( V_172 L_18 ) ;
V_11 -> V_46 = V_173 ;
V_136 [ V_24 ] = L_19 ;
break;
}
break;
case V_174 :
V_11 -> V_46 = V_175 ;
V_136 [ V_24 ] = L_20 ;
F_25 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_129 ;
V_11 -> V_69 = 32 ;
break;
case V_176 :
V_11 -> V_46 = V_177 ;
V_136 [ V_24 ] = L_21 ;
F_25 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_129 ;
V_11 -> V_69 = 48 ;
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
case V_178 :
V_11 -> V_3 = V_51 | V_179 ;
if ( ( V_11 -> V_14 & 0xf0 ) == ( V_180 & 0xf0 ) ) {
V_11 -> V_46 = V_181 ;
V_136 [ V_24 ] = L_22 ;
V_11 -> V_69 = 64 ;
} else {
switch ( V_11 -> V_14 & V_15 ) {
case V_182 :
V_11 -> V_46 = V_183 ;
V_136 [ V_24 ] = L_23 ;
V_11 -> V_69 = 32 ;
break;
case V_184 :
V_11 -> V_46 = V_185 ;
V_136 [ V_24 ] = L_24 ;
V_11 -> V_69 = 64 ;
break;
}
}
break;
case V_186 :
V_11 -> V_46 = V_187 ;
V_136 [ V_24 ] = L_25 ;
F_25 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_129 ;
V_11 -> V_69 = 48 ;
break;
case V_188 :
V_11 -> V_46 = V_189 ;
V_136 [ V_24 ] = L_26 ;
F_25 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_159 | V_129 ;
if ( ! ( V_11 -> V_14 & 0x08 ) )
V_11 -> V_3 |= V_4 | V_67 ;
V_11 -> V_69 = 48 ;
break;
case V_190 :
V_11 -> V_46 = V_191 ;
V_136 [ V_24 ] = L_27 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_129 ;
V_11 -> V_69 = 48 ;
break;
case V_192 :
V_11 -> V_46 = V_193 ;
V_136 [ V_24 ] = L_28 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_61 | V_129 ;
V_11 -> V_69 = 48 ;
break;
case V_194 :
V_11 -> V_46 = V_195 ;
V_136 [ V_24 ] = L_29 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_61 | V_129 ;
V_11 -> V_69 = 48 ;
break;
case V_196 :
V_11 -> V_46 = V_197 ;
V_136 [ V_24 ] = L_30 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_128 | V_129 ;
V_11 -> V_69 = 48 ;
break;
case V_198 :
V_11 -> V_46 = V_199 ;
V_136 [ V_24 ] = L_31 ;
F_25 ( V_11 , V_43 ) ;
V_11 -> V_3 = V_51 | V_4 |
V_129 ;
V_11 -> V_69 = 32 ;
break;
case V_200 :
V_11 -> V_46 = V_201 ;
V_136 [ V_24 ] = L_32 ;
F_25 ( V_11 , V_43 ) ;
V_11 -> V_3 = V_51 | V_4 |
V_129 ;
V_11 -> V_69 = 32 ;
break;
case V_202 :
V_11 -> V_46 = V_203 ;
V_136 [ V_24 ] = L_33 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_129 ;
V_11 -> V_69 = ( F_52 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_204 :
V_11 -> V_46 = V_205 ;
V_136 [ V_24 ] = L_34 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_159 | V_4 | V_67 |
V_129 ;
V_11 -> V_69 = ( F_52 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_206 :
V_11 -> V_46 = V_207 ;
V_136 [ V_24 ] = L_35 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_51 | V_125 |
V_4 | V_67 |
V_129 ;
V_11 -> V_69 = 384 ;
break;
case V_208 :
V_11 -> V_46 = V_209 ;
V_136 [ V_24 ] = L_36 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_51 | V_126 | V_125 |
V_4 | V_67 |
V_127 | V_61 |
V_129 ;
V_11 -> V_69 = 64 ;
break;
case V_210 :
V_11 -> V_46 = V_211 ;
V_136 [ V_24 ] = L_37 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_51 | V_126 | V_125 |
V_4 | V_67 |
V_127 | V_61 |
V_129 ;
V_11 -> V_69 = 64 ;
break;
case V_212 :
V_11 -> V_46 = V_213 ;
V_136 [ V_24 ] = L_38 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_51 | V_126 | V_125 |
V_4 | V_67 |
V_127 | V_61 |
V_129 ;
V_11 -> V_69 = 64 ;
break;
case V_214 :
V_11 -> V_46 = V_215 ;
V_136 [ V_24 ] = L_39 ;
switch ( V_11 -> V_14 & V_15 ) {
case V_216 :
F_12 ( V_24 , L_40 ) ;
break;
case V_217 :
F_12 ( V_24 , L_41 ) ;
break;
}
F_25 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_159 |
V_4 | V_129 |
V_67 ;
V_11 -> V_69 = 64 ;
break;
case V_218 :
F_46 ( V_11 ) ;
V_11 -> V_46 = V_219 ;
switch ( V_11 -> V_14 & V_15 ) {
case V_220 :
V_136 [ V_24 ] = L_42 ;
break;
}
break;
}
}
static inline void F_53 ( struct V_10 * V_11 , unsigned int V_24 )
{
switch ( V_11 -> V_14 & V_133 ) {
case V_221 :
V_11 -> V_46 = V_222 ;
V_136 [ V_24 ] = L_43 ;
break;
case V_223 :
case V_224 :
V_11 -> V_46 = V_225 ;
V_136 [ V_24 ] = L_44 ;
break;
case V_226 :
case V_227 :
V_11 -> V_46 = V_228 ;
V_136 [ V_24 ] = L_45 ;
break;
case V_229 :
V_11 -> V_46 = V_230 ;
V_136 [ V_24 ] = L_46 ;
break;
case V_231 :
V_11 -> V_46 = V_232 ;
V_136 [ V_24 ] = L_47 ;
break;
case V_233 :
V_11 -> V_46 = V_234 ;
V_136 [ V_24 ] = L_48 ;
break;
case V_235 :
V_11 -> V_46 = V_236 ;
V_136 [ V_24 ] = L_49 ;
break;
case V_237 :
V_11 -> V_46 = V_236 ;
V_136 [ V_24 ] = L_50 ;
break;
case V_238 :
V_11 -> V_46 = V_239 ;
V_136 [ V_24 ] = L_51 ;
break;
case V_240 :
V_11 -> V_46 = V_13 ;
V_136 [ V_24 ] = L_52 ;
break;
case V_241 :
V_11 -> V_46 = V_242 ;
V_136 [ V_24 ] = L_53 ;
break;
case V_243 :
V_11 -> V_46 = V_244 ;
V_136 [ V_24 ] = L_54 ;
break;
case V_245 :
V_11 -> V_46 = V_246 ;
V_136 [ V_24 ] = L_55 ;
break;
case V_247 :
V_11 -> V_46 = V_248 ;
V_136 [ V_24 ] = L_56 ;
break;
case V_249 :
V_11 -> V_46 = V_242 ;
V_136 [ V_24 ] = L_57 ;
break;
case V_250 :
V_11 -> V_46 = V_251 ;
V_136 [ V_24 ] = L_58 ;
break;
case V_252 :
V_11 -> V_46 = V_251 ;
V_136 [ V_24 ] = L_59 ;
break;
case V_253 :
V_11 -> V_46 = V_47 ;
V_136 [ V_24 ] = L_60 ;
break;
case V_254 :
V_11 -> V_46 = V_47 ;
V_136 [ V_24 ] = L_61 ;
break;
}
F_46 ( V_11 ) ;
F_54 () ;
}
static inline void F_55 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_46 ( V_11 ) ;
switch ( V_11 -> V_14 & V_133 ) {
case V_255 :
case V_256 :
V_11 -> V_46 = V_257 ;
switch ( ( V_11 -> V_14 >> 24 ) & 0xff ) {
case 0 :
V_136 [ V_24 ] = L_62 ;
break;
case 1 :
V_136 [ V_24 ] = L_63 ;
break;
case 2 :
V_136 [ V_24 ] = L_64 ;
break;
case 3 :
V_136 [ V_24 ] = L_65 ;
break;
case 4 :
V_136 [ V_24 ] = L_66 ;
if ( ( V_11 -> V_14 & V_15 ) == 2 )
V_136 [ V_24 ] = L_67 ;
break;
case 5 :
V_136 [ V_24 ] = L_68 ;
break;
default:
V_136 [ V_24 ] = L_69 ;
break;
}
break;
}
}
static inline void F_56 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_46 ( V_11 ) ;
switch ( V_11 -> V_14 & V_133 ) {
case V_258 :
V_11 -> V_46 = V_259 ;
V_136 [ V_24 ] = L_70 ;
if ( ( V_11 -> V_14 & V_15 ) < 0x02 )
V_11 -> V_3 &= ~ ( V_4 | V_67 ) ;
break;
case V_260 :
V_11 -> V_46 = V_261 ;
V_136 [ V_24 ] = L_71 ;
break;
}
}
static inline void F_57 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_46 ( V_11 ) ;
switch ( V_11 -> V_14 & V_133 ) {
case V_262 :
V_11 -> V_46 = V_263 ;
V_136 [ V_24 ] = L_72 ;
V_11 -> V_75 . V_264 = 8 ;
V_11 -> V_69 = 64 ;
break;
}
}
static inline void F_58 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_46 ( V_11 ) ;
switch ( V_11 -> V_14 & V_133 ) {
case V_265 :
V_11 -> V_46 = V_266 ;
V_136 [ V_24 ] = L_73 ;
F_25 ( V_11 , V_39 ) ;
break;
}
}
static inline void F_59 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_46 ( V_11 ) ;
switch ( V_11 -> V_14 & V_133 ) {
case V_267 :
case V_268 :
V_11 -> V_46 = V_269 ;
V_136 [ V_24 ] = L_74 ;
F_12 ( V_24 , L_75 ) ;
break;
case V_270 :
case V_271 :
case V_272 :
V_11 -> V_46 = V_273 ;
V_136 [ V_24 ] = L_76 ;
F_12 ( V_24 , L_77 ) ;
break;
case V_274 : {
int V_275 = V_11 -> V_14 & V_15 ;
if ( V_275 >= V_276 &&
V_275 <= V_277 ) {
V_11 -> V_46 = V_278 ;
V_136 [ V_24 ] = L_78 ;
F_12 ( V_24 , L_79 ) ;
} else {
V_11 -> V_46 = V_279 ;
V_136 [ V_24 ] = L_80 ;
F_12 ( V_24 , L_81 ) ;
}
break;
}
case V_280 :
V_11 -> V_46 = V_281 ;
V_136 [ V_24 ] = L_82 ;
F_12 ( V_24 , L_83 ) ;
V_11 -> V_3 |= V_92 ;
break;
}
}
static inline void F_60 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_46 ( V_11 ) ;
switch ( V_11 -> V_14 & V_133 ) {
case V_282 :
case V_283 :
case V_284 :
V_11 -> V_46 = V_285 ;
V_136 [ V_24 ] = L_84 ;
goto V_286;
case V_287 :
case V_288 :
case V_289 :
case V_290 :
V_11 -> V_46 = V_291 ;
V_136 [ V_24 ] = L_85 ;
V_286:
F_12 ( V_24 , L_86 ) ;
break;
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
V_11 -> V_46 = V_297 ;
V_136 [ V_24 ] = L_87 ;
F_12 ( V_24 , L_88 ) ;
break;
case V_298 :
case V_299 :
V_11 -> V_46 = V_300 ;
V_136 [ V_24 ] = L_89 ;
F_12 ( V_24 , L_90 ) ;
break;
default:
F_51 ( V_172 L_91 ) ;
V_11 -> V_46 = V_301 ;
break;
}
}
static inline void F_61 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_46 ( V_11 ) ;
V_11 -> V_3 &= ~ V_127 ;
switch ( V_11 -> V_14 & V_133 ) {
case V_302 :
V_11 -> V_46 = V_303 ;
V_136 [ V_24 ] = L_92 ;
break;
default:
F_31 ( L_93 ) ;
break;
}
}
static inline void F_62 ( struct V_10 * V_11 , int V_24 )
{
F_46 ( V_11 ) ;
if ( ( V_11 -> V_14 & V_133 ) == V_304 ) {
V_11 -> V_46 = V_257 ;
V_136 [ V_24 ] = L_94 ;
return;
}
V_11 -> V_3 = ( V_51 |
V_125 |
V_127 |
V_128 |
V_61 |
V_65 |
V_129 ) ;
switch ( V_11 -> V_14 & V_133 ) {
case V_305 :
case V_306 :
V_11 -> V_46 = V_307 ;
V_136 [ V_24 ] = L_95 ;
break;
case V_308 :
case V_309 :
V_11 -> V_46 = V_307 ;
V_136 [ V_24 ] = L_96 ;
break;
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
V_11 -> V_46 = V_318 ;
V_136 [ V_24 ] = L_97 ;
break;
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
V_11 -> V_46 = V_318 ;
V_136 [ V_24 ] = L_98 ;
break;
default:
F_63 ( L_99 ,
V_11 -> V_14 ) ;
V_11 -> V_46 = V_318 ;
break;
}
if ( V_11 -> V_46 == V_307 ) {
F_25 ( V_11 , V_35 ) ;
V_11 -> V_3 |= ( V_4 | V_92 | V_130 ) ;
V_11 -> V_69 = ( ( F_27 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_25 ( V_11 , V_38 ) ;
V_11 -> V_69 = ( ( F_33 () >> 25 ) & 0x3f ) + 1 ;
}
V_11 -> V_121 = 0xf ;
}
void F_64 ( void )
{
struct V_10 * V_11 = & V_12 ;
unsigned int V_24 = F_65 () ;
V_11 -> V_14 = V_332 ;
V_11 -> V_28 = V_32 ;
V_11 -> V_46 = V_301 ;
V_11 -> V_14 = F_66 () ;
switch ( V_11 -> V_14 & V_333 ) {
case V_334 :
F_50 ( V_11 , V_24 ) ;
break;
case V_335 :
F_53 ( V_11 , V_24 ) ;
break;
case V_336 :
F_55 ( V_11 , V_24 ) ;
break;
case V_337 :
F_56 ( V_11 , V_24 ) ;
break;
case V_338 :
F_59 ( V_11 , V_24 ) ;
break;
case V_339 :
F_57 ( V_11 , V_24 ) ;
break;
case V_340 :
F_58 ( V_11 , V_24 ) ;
break;
case V_341 :
F_60 ( V_11 , V_24 ) ;
break;
case V_342 :
F_61 ( V_11 , V_24 ) ;
break;
case V_343 :
F_62 ( V_11 , V_24 ) ;
break;
}
F_47 ( ! V_136 [ V_24 ] ) ;
F_47 ( V_11 -> V_46 == V_301 ) ;
F_47 ( F_4 () != V_11 -> V_46 ) ;
if ( V_5 )
V_11 -> V_3 &= ~ V_4 ;
if ( V_9 )
V_11 -> V_6 &= ~ ( V_7 | V_8 ) ;
if ( V_11 -> V_3 & V_4 ) {
V_11 -> V_28 = F_13 () ;
if ( V_11 -> V_36 & ( V_39 | V_37 |
V_38 | V_35 ) ) {
if ( V_11 -> V_28 & V_344 )
V_11 -> V_6 |= V_345 ;
}
}
if ( V_131 ) {
V_11 -> V_346 = ( ( F_67 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_3 |= V_347 ;
}
else
V_11 -> V_346 = 1 ;
F_19 ( V_11 ) ;
#ifdef F_68
if ( V_24 == 0 )
V_348 = ~ ( ( 1ull << V_349 ) - 1 ) ;
#endif
}
void F_69 ( void )
{
struct V_10 * V_11 = & V_12 ;
F_63 ( L_100 ,
F_65 () , V_11 -> V_14 , F_70 () ) ;
if ( V_11 -> V_3 & V_4 )
F_51 ( V_172 L_101 , V_11 -> V_28 ) ;
}
