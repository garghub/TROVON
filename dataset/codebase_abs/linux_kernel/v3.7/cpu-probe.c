static void F_1 ( void )
{
unsigned long V_1 = F_2 () ;
F_3 ( V_1 | V_2 ) ;
}
static void F_4 ( void )
{
F_5 () ;
if ( ! F_6 () )
F_3 ( F_2 () | V_3 ) ;
F_7 () ;
}
void F_8 ( void )
{
F_5 () ;
if ( ! F_6 () )
__asm__(" .set push \n"
" .set mips3 \n"
" wait \n"
" .set pop \n");
F_7 () ;
__asm__(" .globl __pastwait \n"
"__pastwait: \n");
}
static void F_9 ( void )
{
F_5 () ;
if ( ! F_6 () )
__asm__(
" .set push \n"
" .set mips3 \n"
" .set noat \n"
" mfc0 $1, $12 \n"
" sync \n"
" mtc0 $1, $12 # stalls until W stage \n"
" wait \n"
" mtc0 $1, $12 # stalls until W stage \n"
" .set pop \n");
F_7 () ;
}
static void F_10 ( void )
{
__asm__(" .set mips3 \n"
" cache 0x14, 0(%0) \n"
" cache 0x14, 32(%0) \n"
" sync \n"
" nop \n"
" wait \n"
" nop \n"
" nop \n"
" nop \n"
" nop \n"
" .set mips0 \n"
: : "r" (au1k_wait));
}
static int T_1 F_11 ( char * V_4 )
{
V_5 = 1 ;
return 1 ;
}
static int T_1 F_12 ( char * V_4 )
{
V_6 [ 0 ] . V_7 &= ~ V_8 ;
V_9 = 1 ;
return 1 ;
}
static int T_1 F_13 ( char * V_4 )
{
V_6 [ 0 ] . V_10 &= ~ ( V_11 | V_12 ) ;
V_13 = 1 ;
return 1 ;
}
void T_1 F_14 ( void )
{
struct V_14 * V_15 = & V_16 ;
if ( V_5 ) {
F_15 ( L_1 ) ;
return;
}
switch ( V_15 -> V_17 ) {
case V_18 :
case V_19 :
V_20 = F_1 ;
break;
case V_21 :
V_20 = F_4 ;
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
V_20 = V_47 ;
break;
case V_48 :
V_20 = F_9 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
V_20 = V_47 ;
if ( F_16 () & V_53 )
V_20 = F_8 ;
break;
case V_54 :
V_20 = V_47 ;
if ( ( V_15 -> V_55 & 0xff ) >= F_17 ( 2 , 1 , 0 ) )
V_20 = F_8 ;
break;
case V_56 :
V_20 = F_8 ;
break;
case V_57 :
V_20 = F_10 ;
break;
case V_58 :
if ( ( V_15 -> V_55 & 0xff ) <= 0x64 )
break;
break;
case V_59 :
if ( ( V_15 -> V_55 & 0x00ff ) >= 0x40 )
V_20 = V_47 ;
break;
default:
break;
}
}
static inline void F_18 ( void )
{
struct V_14 * V_15 = & V_16 ;
switch ( V_15 -> V_17 ) {
case V_51 :
if ( ( V_15 -> V_55 & V_60 ) <= V_61 )
F_19 ( F_16 () | V_62 ) ;
break;
default:
break;
}
}
void T_1 F_20 ( void )
{
F_18 () ;
}
static inline int F_21 ( void )
{
#ifdef F_22
extern unsigned long V_63 ( unsigned long ) ;
unsigned long V_64 , V_65 ;
unsigned long V_1 = F_2 () ;
V_64 = V_63 ( V_66 ) ;
F_3 ( V_1 ^ V_67 ) ;
V_65 = V_63 ( V_66 ) ;
F_3 ( V_1 ) ;
return V_64 != V_65 ;
#else
return 0 ;
#endif
}
static inline void F_23 ( int V_68 , const char * V_69 )
{
if ( V_68 == 0 )
V_70 = V_69 ;
}
static inline unsigned long F_24 ( void )
{
unsigned long V_71 , V_72 ;
V_71 = F_25 () ;
F_26 () ;
V_72 = F_27 ( V_73 ) ;
F_28 ( V_71 ) ;
return V_72 ;
}
static inline int F_29 ( void )
{
return ( ( F_24 () & 0xff00 ) != V_74 ) ;
}
static inline void F_30 ( struct V_14 * V_15 )
{
#ifdef F_31
F_32 ( 0x3fffffffffffe000ULL ) ;
F_33 () ;
V_15 -> V_75 = F_34 ( F_35 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static inline unsigned int F_36 ( struct V_14 * V_15 )
{
unsigned int V_76 ;
int V_77 ;
V_76 = F_37 () ;
if ( ( ( V_76 & V_78 ) >> 7 ) == 1 )
V_15 -> V_7 |= V_79 ;
V_77 = ( V_76 & V_80 ) >> 13 ;
switch ( V_77 ) {
case 0 :
switch ( ( V_76 & V_81 ) >> 10 ) {
case 0 :
V_15 -> V_82 = V_83 ;
break;
case 1 :
V_15 -> V_82 = V_84 ;
break;
default:
goto V_85;
}
break;
case 2 :
switch ( ( V_76 & V_81 ) >> 10 ) {
case 0 :
V_15 -> V_82 = V_86 ;
break;
case 1 :
V_15 -> V_82 = V_87 ;
break;
default:
goto V_85;
}
break;
default:
goto V_85;
}
return V_76 & V_88 ;
V_85:
F_38 ( V_89 , V_76 ) ;
}
static inline unsigned int F_39 ( struct V_14 * V_15 )
{
unsigned int V_90 ;
V_90 = F_40 () ;
if ( V_90 & V_91 )
V_15 -> V_10 |= V_92 ;
if ( V_90 & V_93 )
V_15 -> V_7 |= V_94 ;
if ( V_90 & V_95 )
V_15 -> V_10 |= V_96 ;
if ( V_90 & V_97 )
V_15 -> V_7 |= V_98 ;
if ( V_90 & V_99 ) {
V_15 -> V_7 |= V_8 ;
V_15 -> V_7 |= V_100 ;
}
if ( V_101 )
V_15 -> V_102 = ( ( V_90 & V_103 ) >> 25 ) + 1 ;
return V_90 & V_88 ;
}
static inline unsigned int F_41 ( struct V_14 * V_15 )
{
unsigned int V_104 ;
V_104 = F_42 () ;
if ( V_104 & V_105 )
V_15 -> V_106 . V_107 &= ~ V_108 ;
return V_104 & V_88 ;
}
static inline unsigned int F_43 ( struct V_14 * V_15 )
{
unsigned int V_109 ;
V_109 = F_44 () ;
if ( V_109 & V_110 ) {
V_15 -> V_10 |= V_111 ;
V_15 -> V_7 |= V_112 ;
}
if ( V_109 & V_113 )
V_15 -> V_7 |= V_112 ;
if ( V_109 & V_114 )
V_15 -> V_10 |= V_11 ;
if ( V_109 & V_115 )
V_15 -> V_10 |= V_12 ;
if ( V_109 & V_116 )
V_15 -> V_7 |= V_117 ;
if ( V_109 & V_118 )
V_15 -> V_7 |= V_119 ;
if ( V_109 & V_120 )
V_15 -> V_10 |= V_121 ;
if ( V_109 & V_122 )
V_15 -> V_7 |= V_123 ;
return V_109 & V_88 ;
}
static inline unsigned int F_45 ( struct V_14 * V_15 )
{
unsigned int V_124 ;
V_124 = F_46 () ;
if ( ( V_124 & V_125 ) == V_126
&& V_101 )
V_15 -> V_102 += ( V_124 & V_127 ) * 0x40 ;
V_15 -> V_128 = ( V_124 >> 16 ) & 0xff ;
return V_124 & V_88 ;
}
static void T_2 F_47 ( struct V_14 * V_15 )
{
int V_129 ;
V_15 -> V_7 = V_130 | V_131 | V_132 |
V_133 | V_134 | V_135 ;
V_15 -> V_106 . V_107 = V_108 ;
V_129 = F_36 ( V_15 ) ;
F_48 ( ! V_129 ) ;
if ( V_129 )
V_129 = F_39 ( V_15 ) ;
if ( V_129 )
V_129 = F_41 ( V_15 ) ;
if ( V_129 )
V_129 = F_43 ( V_15 ) ;
if ( V_129 )
V_129 = F_45 ( V_15 ) ;
F_49 ( V_15 ) ;
if ( V_136 )
V_15 -> V_137 = F_50 () & 0x3ff ;
}
static inline void F_51 ( struct V_14 * V_15 , unsigned int V_68 )
{
switch ( V_15 -> V_55 & 0xff00 ) {
case V_138 :
V_15 -> V_17 = V_139 ;
V_140 [ V_68 ] = L_2 ;
V_15 -> V_82 = V_141 ;
V_15 -> V_7 = V_79 | V_142 |
V_143 ;
if ( F_29 () )
V_15 -> V_7 |= V_8 ;
V_15 -> V_102 = 64 ;
break;
case V_144 :
if ( ( V_15 -> V_55 & 0xff ) == V_145 ) {
if ( F_21 () ) {
V_15 -> V_17 = V_19 ;
V_140 [ V_68 ] = L_3 ;
} else {
V_15 -> V_17 = V_146 ;
V_140 [ V_68 ] = L_4 ;
}
} else {
V_15 -> V_17 = V_147 ;
V_140 [ V_68 ] = L_5 ;
}
V_15 -> V_82 = V_141 ;
V_15 -> V_7 = V_79 | V_142 |
V_143 ;
if ( F_29 () )
V_15 -> V_7 |= V_8 ;
V_15 -> V_102 = 64 ;
break;
case V_148 :
if ( F_37 () & V_149 ) {
if ( ( V_15 -> V_55 & 0xff ) >= V_150 ) {
V_15 -> V_17 = V_151 ;
V_140 [ V_68 ] = L_6 ;
} else {
V_15 -> V_17 = V_152 ;
V_140 [ V_68 ] = L_7 ;
}
} else {
if ( ( V_15 -> V_55 & 0xff ) >= V_150 ) {
V_15 -> V_17 = V_153 ;
V_140 [ V_68 ] = L_8 ;
} else {
V_15 -> V_17 = V_154 ;
V_140 [ V_68 ] = L_9 ;
}
}
V_15 -> V_82 = V_155 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_94 | V_157 |
V_134 ;
V_15 -> V_102 = 48 ;
break;
case V_158 :
switch ( V_15 -> V_55 & 0xf0 ) {
case V_159 :
V_15 -> V_17 = V_160 ;
V_140 [ V_68 ] = L_10 ;
break;
case V_161 :
V_15 -> V_17 = V_162 ;
V_140 [ V_68 ] = L_11 ;
break;
case V_163 :
if ( ( V_15 -> V_55 & 0xf ) < 0x3 ) {
V_15 -> V_17 = V_164 ;
V_140 [ V_68 ] = L_12 ;
} else {
V_15 -> V_17 = V_165 ;
V_140 [ V_68 ] = L_13 ;
}
break;
case V_166 :
if ( ( V_15 -> V_55 & 0xf ) < 0x4 ) {
V_15 -> V_17 = V_167 ;
V_140 [ V_68 ] = L_14 ;
} else {
V_15 -> V_17 = V_168 ;
V_140 [ V_68 ] = L_15 ;
}
break;
default:
F_15 ( V_169 L_16 ) ;
V_15 -> V_17 = V_170 ;
V_140 [ V_68 ] = L_17 ;
break;
}
V_15 -> V_82 = V_155 ;
V_15 -> V_7 = V_156 ;
V_15 -> V_102 = 32 ;
break;
case V_171 :
V_15 -> V_17 = V_172 ;
V_140 [ V_68 ] = L_18 ;
V_15 -> V_82 = V_155 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_134 ;
V_15 -> V_102 = 32 ;
break;
case V_173 :
V_15 -> V_17 = V_23 ;
V_140 [ V_68 ] = L_19 ;
V_15 -> V_82 = V_155 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_134 ;
V_15 -> V_102 = 48 ;
break;
#if 0
case PRID_IMP_R4650:
c->cputype = CPU_R4650;
__cpu_name[cpu] = "R4650";
c->isa_level = MIPS_CPU_ISA_III;
c->options = R4K_OPTS | MIPS_CPU_FPU | MIPS_CPU_LLSC;
c->tlbsize = 48;
break;
#endif
case V_174 :
V_15 -> V_82 = V_141 ;
V_15 -> V_7 = V_79 | V_175 ;
if ( ( V_15 -> V_55 & 0xf0 ) == ( V_176 & 0xf0 ) ) {
V_15 -> V_17 = V_21 ;
V_140 [ V_68 ] = L_20 ;
V_15 -> V_102 = 64 ;
} else {
switch ( V_15 -> V_55 & 0xff ) {
case V_177 :
V_15 -> V_17 = V_178 ;
V_140 [ V_68 ] = L_21 ;
V_15 -> V_102 = 32 ;
break;
case V_179 :
V_15 -> V_17 = V_180 ;
V_140 [ V_68 ] = L_22 ;
V_15 -> V_102 = 64 ;
break;
}
}
break;
case V_181 :
V_15 -> V_17 = V_26 ;
V_140 [ V_68 ] = L_23 ;
V_15 -> V_82 = V_155 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_134 ;
V_15 -> V_102 = 48 ;
break;
case V_182 :
V_15 -> V_17 = V_56 ;
V_140 [ V_68 ] = L_24 ;
V_15 -> V_82 = V_155 ;
V_15 -> V_7 = V_156 | V_134 ;
if ( ! ( V_15 -> V_55 & 0x08 ) )
V_15 -> V_7 |= V_8 | V_100 ;
V_15 -> V_102 = 48 ;
break;
case V_183 :
V_15 -> V_17 = V_27 ;
V_140 [ V_68 ] = L_25 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_134 ;
V_15 -> V_102 = 48 ;
break;
case V_185 :
V_15 -> V_17 = V_186 ;
V_140 [ V_68 ] = L_26 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_94 | V_134 ;
V_15 -> V_102 = 48 ;
break;
case V_187 :
V_15 -> V_17 = V_28 ;
V_140 [ V_68 ] = L_27 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_94 | V_134 ;
V_15 -> V_102 = 48 ;
break;
case V_188 :
V_15 -> V_17 = V_29 ;
V_140 [ V_68 ] = L_28 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_133 | V_134 ;
V_15 -> V_102 = 48 ;
break;
case V_189 :
V_15 -> V_17 = V_190 ;
V_140 [ V_68 ] = L_29 ;
V_15 -> V_82 = V_191 ;
V_15 -> V_7 = V_79 | V_8 |
V_134 ;
V_15 -> V_102 = 32 ;
break;
case V_192 :
V_15 -> V_17 = V_193 ;
V_140 [ V_68 ] = L_30 ;
V_15 -> V_82 = V_191 ;
V_15 -> V_7 = V_79 | V_8 |
V_134 ;
V_15 -> V_102 = 32 ;
break;
case V_194 :
V_15 -> V_17 = V_48 ;
V_140 [ V_68 ] = L_31 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_134 ;
V_15 -> V_102 = ( F_52 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_195 :
V_15 -> V_17 = V_59 ;
V_140 [ V_68 ] = L_32 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_156 | V_8 | V_100 |
V_134 ;
V_15 -> V_102 = ( F_52 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_196 :
V_15 -> V_17 = V_197 ;
V_140 [ V_68 ] = L_33 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_79 | V_130 |
V_8 | V_100 |
V_134 ;
V_15 -> V_102 = 384 ;
break;
case V_198 :
V_15 -> V_17 = V_199 ;
V_140 [ V_68 ] = L_34 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_79 | V_131 | V_130 |
V_8 | V_100 |
V_132 | V_94 |
V_134 ;
V_15 -> V_102 = 64 ;
break;
case V_200 :
V_15 -> V_17 = V_201 ;
V_140 [ V_68 ] = L_35 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_79 | V_131 | V_130 |
V_8 | V_100 |
V_132 | V_94 |
V_134 ;
V_15 -> V_102 = 64 ;
break;
case V_202 :
V_15 -> V_17 = V_203 ;
V_140 [ V_68 ] = L_36 ;
V_15 -> V_82 = V_184 ;
V_15 -> V_7 = V_79 | V_131 | V_130 |
V_8 | V_100 |
V_132 | V_94 |
V_134 ;
V_15 -> V_102 = 64 ;
break;
case V_204 :
V_15 -> V_17 = V_205 ;
V_140 [ V_68 ] = L_37 ;
switch ( V_15 -> V_55 & V_60 ) {
case V_206 :
F_23 ( V_68 , L_38 ) ;
break;
case V_207 :
F_23 ( V_68 , L_39 ) ;
break;
}
V_15 -> V_82 = V_155 ;
V_15 -> V_7 = V_156 |
V_8 | V_134 |
V_100 ;
V_15 -> V_102 = 64 ;
break;
case V_208 :
F_47 ( V_15 ) ;
V_15 -> V_17 = V_44 ;
switch ( V_15 -> V_55 & V_60 ) {
case V_209 :
V_140 [ V_68 ] = L_40 ;
break;
}
break;
}
}
static inline void F_53 ( struct V_14 * V_15 , unsigned int V_68 )
{
F_47 ( V_15 ) ;
switch ( V_15 -> V_55 & 0xff00 ) {
case V_210 :
V_15 -> V_17 = V_30 ;
V_140 [ V_68 ] = L_41 ;
break;
case V_211 :
case V_212 :
V_15 -> V_17 = V_31 ;
V_140 [ V_68 ] = L_42 ;
break;
case V_213 :
case V_214 :
V_15 -> V_17 = V_32 ;
V_140 [ V_68 ] = L_43 ;
break;
case V_215 :
V_15 -> V_17 = V_33 ;
V_140 [ V_68 ] = L_44 ;
break;
case V_216 :
V_15 -> V_17 = V_217 ;
V_140 [ V_68 ] = L_45 ;
break;
case V_218 :
V_15 -> V_17 = V_58 ;
V_140 [ V_68 ] = L_46 ;
break;
case V_219 :
case V_220 :
V_15 -> V_17 = V_50 ;
V_140 [ V_68 ] = L_47 ;
break;
case V_221 :
V_15 -> V_17 = V_34 ;
V_140 [ V_68 ] = L_48 ;
break;
case V_222 :
V_15 -> V_17 = V_51 ;
V_140 [ V_68 ] = L_49 ;
break;
case V_223 :
V_15 -> V_17 = V_54 ;
V_140 [ V_68 ] = L_50 ;
break;
case V_224 :
V_15 -> V_17 = V_49 ;
V_140 [ V_68 ] = L_51 ;
break;
case V_225 :
V_15 -> V_17 = V_52 ;
V_140 [ V_68 ] = L_52 ;
break;
case V_226 :
V_15 -> V_17 = V_54 ;
V_140 [ V_68 ] = L_53 ;
break;
}
F_54 () ;
}
static inline void F_55 ( struct V_14 * V_15 , unsigned int V_68 )
{
F_47 ( V_15 ) ;
switch ( V_15 -> V_55 & 0xff00 ) {
case V_227 :
case V_228 :
V_15 -> V_17 = V_57 ;
switch ( ( V_15 -> V_55 >> 24 ) & 0xff ) {
case 0 :
V_140 [ V_68 ] = L_54 ;
break;
case 1 :
V_140 [ V_68 ] = L_55 ;
break;
case 2 :
V_140 [ V_68 ] = L_56 ;
break;
case 3 :
V_140 [ V_68 ] = L_57 ;
break;
case 4 :
V_140 [ V_68 ] = L_58 ;
if ( ( V_15 -> V_55 & 0xff ) == 2 )
V_140 [ V_68 ] = L_59 ;
break;
case 5 :
V_140 [ V_68 ] = L_60 ;
break;
default:
V_140 [ V_68 ] = L_61 ;
break;
}
break;
}
}
static inline void F_56 ( struct V_14 * V_15 , unsigned int V_68 )
{
F_47 ( V_15 ) ;
switch ( V_15 -> V_55 & 0xff00 ) {
case V_229 :
V_15 -> V_17 = V_230 ;
V_140 [ V_68 ] = L_62 ;
if ( ( V_15 -> V_55 & 0xff ) < 0x02 )
V_15 -> V_7 &= ~ ( V_8 | V_100 ) ;
break;
case V_231 :
V_15 -> V_17 = V_232 ;
V_140 [ V_68 ] = L_63 ;
break;
}
}
static inline void F_57 ( struct V_14 * V_15 , unsigned int V_68 )
{
F_47 ( V_15 ) ;
switch ( V_15 -> V_55 & 0xff00 ) {
case V_233 :
V_15 -> V_17 = V_234 ;
V_140 [ V_68 ] = L_64 ;
V_15 -> V_106 . V_235 = 8 ;
V_15 -> V_102 = 64 ;
break;
}
}
static inline void F_58 ( struct V_14 * V_15 , unsigned int V_68 )
{
F_47 ( V_15 ) ;
switch ( V_15 -> V_55 & 0xff00 ) {
case V_236 :
V_15 -> V_17 = V_35 ;
V_140 [ V_68 ] = L_65 ;
V_15 -> V_82 = V_83 ;
break;
}
}
static inline void F_59 ( struct V_14 * V_15 , unsigned int V_68 )
{
F_47 ( V_15 ) ;
switch ( V_15 -> V_55 & 0xff00 ) {
case V_237 :
case V_238 :
V_15 -> V_17 = V_239 ;
V_140 [ V_68 ] = L_66 ;
F_23 ( V_68 , L_67 ) ;
break;
case V_240 :
case V_241 :
case V_242 :
V_15 -> V_17 = V_36 ;
V_140 [ V_68 ] = L_68 ;
F_23 ( V_68 , L_69 ) ;
break;
case V_243 : {
int V_244 = V_15 -> V_55 & 0xff ;
if ( V_244 >= V_245 &&
V_244 <= V_246 ) {
V_15 -> V_17 = V_38 ;
V_140 [ V_68 ] = L_70 ;
F_23 ( V_68 , L_71 ) ;
} else {
V_15 -> V_17 = V_37 ;
V_140 [ V_68 ] = L_72 ;
F_23 ( V_68 , L_73 ) ;
}
break;
}
case V_247 :
V_15 -> V_17 = V_39 ;
V_140 [ V_68 ] = L_74 ;
F_23 ( V_68 , L_75 ) ;
V_15 -> V_7 |= V_123 ;
break;
}
}
static inline void F_60 ( struct V_14 * V_15 , unsigned int V_68 )
{
F_47 ( V_15 ) ;
switch ( V_15 -> V_55 & 0xff00 ) {
case V_248 :
case V_249 :
case V_250 :
V_15 -> V_17 = V_40 ;
V_140 [ V_68 ] = L_76 ;
goto V_251;
case V_252 :
case V_253 :
case V_254 :
case V_255 :
V_15 -> V_17 = V_41 ;
V_140 [ V_68 ] = L_77 ;
V_251:
F_23 ( V_68 , L_78 ) ;
break;
case V_256 :
case V_257 :
case V_258 :
case V_259 :
V_15 -> V_17 = V_42 ;
V_140 [ V_68 ] = L_79 ;
F_23 ( V_68 , L_80 ) ;
break;
default:
F_15 ( V_169 L_81 ) ;
V_15 -> V_17 = V_260 ;
break;
}
}
static inline void F_61 ( struct V_14 * V_15 , unsigned int V_68 )
{
F_47 ( V_15 ) ;
V_15 -> V_7 &= ~ V_132 ;
switch ( V_15 -> V_55 & 0xff00 ) {
case V_261 :
V_15 -> V_17 = V_43 ;
V_140 [ V_68 ] = L_82 ;
break;
default:
F_38 ( L_83 ) ;
break;
}
}
static inline void F_62 ( struct V_14 * V_15 , int V_68 )
{
F_47 ( V_15 ) ;
if ( ( V_15 -> V_55 & 0xff00 ) == V_262 ) {
V_15 -> V_17 = V_57 ;
V_140 [ V_68 ] = L_84 ;
return;
}
V_15 -> V_7 = ( V_79 |
V_130 |
V_132 |
V_133 |
V_94 |
V_98 |
V_134 ) ;
switch ( V_15 -> V_55 & 0xff00 ) {
case V_263 :
case V_264 :
V_15 -> V_17 = V_46 ;
V_140 [ V_68 ] = L_85 ;
break;
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
V_15 -> V_17 = V_45 ;
V_140 [ V_68 ] = L_86 ;
break;
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
V_15 -> V_17 = V_45 ;
V_140 [ V_68 ] = L_87 ;
break;
default:
F_63 ( L_88 ,
V_15 -> V_55 ) ;
V_15 -> V_17 = V_45 ;
break;
}
if ( V_15 -> V_17 == V_46 ) {
V_15 -> V_82 = V_87 ;
V_15 -> V_7 |= ( V_8 | V_123 | V_135 ) ;
V_15 -> V_102 = ( ( F_64 () >> 16 ) & 0xffff ) + 1 ;
} else {
V_15 -> V_82 = V_86 ;
V_15 -> V_102 = ( ( F_40 () >> 25 ) & 0x3f ) + 1 ;
}
}
T_2 void F_65 ( void )
{
struct V_14 * V_15 = & V_16 ;
unsigned int V_68 = F_66 () ;
V_15 -> V_55 = V_286 ;
V_15 -> V_72 = V_74 ;
V_15 -> V_17 = V_260 ;
V_15 -> V_55 = F_67 () ;
switch ( V_15 -> V_55 & 0xff0000 ) {
case V_287 :
F_51 ( V_15 , V_68 ) ;
break;
case V_288 :
F_53 ( V_15 , V_68 ) ;
break;
case V_289 :
F_55 ( V_15 , V_68 ) ;
break;
case V_290 :
F_56 ( V_15 , V_68 ) ;
break;
case V_291 :
F_59 ( V_15 , V_68 ) ;
break;
case V_292 :
F_57 ( V_15 , V_68 ) ;
break;
case V_293 :
F_58 ( V_15 , V_68 ) ;
break;
case V_294 :
F_60 ( V_15 , V_68 ) ;
break;
case V_295 :
F_61 ( V_15 , V_68 ) ;
break;
case V_296 :
F_62 ( V_15 , V_68 ) ;
break;
}
F_48 ( ! V_140 [ V_68 ] ) ;
F_48 ( V_15 -> V_17 == V_260 ) ;
F_48 ( F_68 () != V_15 -> V_17 ) ;
if ( V_9 )
V_15 -> V_7 &= ~ V_8 ;
if ( V_13 )
V_15 -> V_10 &= ~ ( V_11 | V_12 ) ;
if ( V_15 -> V_7 & V_8 ) {
V_15 -> V_72 = F_24 () ;
if ( V_15 -> V_82 == V_83 ||
V_15 -> V_82 == V_84 ||
V_15 -> V_82 == V_86 ||
V_15 -> V_82 == V_87 ) {
if ( V_15 -> V_72 & V_297 )
V_15 -> V_10 |= V_298 ;
}
}
if ( V_136 ) {
V_15 -> V_299 = ( ( F_69 () >> 26 ) & 0x0f ) + 1 ;
V_15 -> V_7 |= V_300 ;
}
else
V_15 -> V_299 = 1 ;
F_30 ( V_15 ) ;
#ifdef F_70
if ( V_68 == 0 )
V_301 = ~ ( ( 1ull << V_302 ) - 1 ) ;
#endif
}
T_2 void F_71 ( void )
{
struct V_14 * V_15 = & V_16 ;
F_15 ( V_169 L_89 ,
V_15 -> V_55 , F_72 () ) ;
if ( V_15 -> V_7 & V_8 )
F_15 ( V_169 L_90 , V_15 -> V_72 ) ;
}
