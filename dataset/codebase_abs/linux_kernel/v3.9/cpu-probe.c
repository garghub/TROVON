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
case V_53 :
V_20 = V_47 ;
if ( F_16 () & V_54 )
V_20 = F_8 ;
break;
case V_55 :
V_20 = V_47 ;
if ( ( V_15 -> V_56 & 0xff ) >= F_17 ( 2 , 1 , 0 ) )
V_20 = F_8 ;
break;
case V_57 :
V_20 = F_8 ;
break;
case V_58 :
V_20 = F_10 ;
break;
case V_59 :
if ( ( V_15 -> V_56 & 0xff ) <= 0x64 )
break;
break;
case V_60 :
if ( ( V_15 -> V_56 & 0x00ff ) >= 0x40 )
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
case V_52 :
if ( ( V_15 -> V_56 & V_61 ) <= V_62 )
F_19 ( F_16 () | V_63 ) ;
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
extern unsigned long V_64 ( unsigned long ) ;
unsigned long V_65 , V_66 ;
unsigned long V_1 = F_2 () ;
V_65 = V_64 ( V_67 ) ;
F_3 ( V_1 ^ V_68 ) ;
V_66 = V_64 ( V_67 ) ;
F_3 ( V_1 ) ;
return V_65 != V_66 ;
#else
return 0 ;
#endif
}
static inline void F_23 ( int V_69 , const char * V_70 )
{
if ( V_69 == 0 )
V_71 = V_70 ;
}
static inline unsigned long F_24 ( void )
{
unsigned long V_72 , V_73 ;
V_72 = F_25 () ;
F_26 () ;
V_73 = F_27 ( V_74 ) ;
F_28 ( V_72 ) ;
return V_73 ;
}
static inline int F_29 ( void )
{
return ( ( F_24 () & 0xff00 ) != V_75 ) ;
}
static inline void F_30 ( struct V_14 * V_15 )
{
#ifdef F_31
F_32 ( 0x3fffffffffffe000ULL ) ;
F_33 () ;
V_15 -> V_76 = F_34 ( F_35 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void T_2 F_36 ( struct V_14 * V_15 , unsigned int V_77 )
{
switch ( V_77 ) {
case V_78 :
V_15 -> V_79 |= V_80 | V_78 ;
case V_81 :
V_15 -> V_79 |= V_82 | V_81 ;
case V_83 :
V_15 -> V_79 |= V_83 ;
case V_84 :
V_15 -> V_79 |= V_84 ;
case V_85 :
V_15 -> V_79 |= V_86 | V_87 |
V_85 ;
break;
case V_80 :
V_15 -> V_79 |= V_80 ;
case V_82 :
V_15 -> V_79 |= V_82 ;
case V_87 :
V_15 -> V_79 |= V_87 ;
case V_86 :
V_15 -> V_79 |= V_86 ;
break;
}
}
static inline unsigned int F_37 ( struct V_14 * V_15 )
{
unsigned int V_88 ;
int V_77 ;
V_88 = F_38 () ;
if ( ( ( V_88 & V_89 ) >> 7 ) == 1 )
V_15 -> V_7 |= V_90 ;
V_77 = ( V_88 & V_91 ) >> 13 ;
switch ( V_77 ) {
case 0 :
switch ( ( V_88 & V_92 ) >> 10 ) {
case 0 :
F_36 ( V_15 , V_82 ) ;
break;
case 1 :
F_36 ( V_15 , V_80 ) ;
break;
default:
goto V_93;
}
break;
case 2 :
switch ( ( V_88 & V_92 ) >> 10 ) {
case 0 :
F_36 ( V_15 , V_81 ) ;
break;
case 1 :
F_36 ( V_15 , V_78 ) ;
break;
default:
goto V_93;
}
break;
default:
goto V_93;
}
return V_88 & V_94 ;
V_93:
F_39 ( V_95 , V_88 ) ;
}
static inline unsigned int F_40 ( struct V_14 * V_15 )
{
unsigned int V_96 ;
V_96 = F_41 () ;
if ( V_96 & V_97 )
V_15 -> V_10 |= V_98 ;
if ( V_96 & V_99 )
V_15 -> V_7 |= V_100 ;
if ( V_96 & V_101 )
V_15 -> V_10 |= V_102 ;
if ( V_96 & V_103 )
V_15 -> V_7 |= V_104 ;
if ( V_96 & V_105 ) {
V_15 -> V_7 |= V_8 ;
V_15 -> V_7 |= V_106 ;
}
if ( V_107 )
V_15 -> V_108 = ( ( V_96 & V_109 ) >> 25 ) + 1 ;
return V_96 & V_94 ;
}
static inline unsigned int F_42 ( struct V_14 * V_15 )
{
unsigned int V_110 ;
V_110 = F_43 () ;
if ( V_110 & V_111 )
V_15 -> V_112 . V_113 &= ~ V_114 ;
return V_110 & V_94 ;
}
static inline unsigned int F_44 ( struct V_14 * V_15 )
{
unsigned int V_115 ;
V_115 = F_45 () ;
if ( V_115 & V_116 ) {
V_15 -> V_10 |= V_117 ;
V_15 -> V_7 |= V_118 ;
}
if ( V_115 & V_119 )
V_15 -> V_7 |= V_118 ;
if ( V_115 & V_120 )
V_15 -> V_10 |= V_11 ;
if ( V_115 & V_121 )
V_15 -> V_10 |= V_12 ;
if ( V_115 & V_122 )
V_15 -> V_7 |= V_123 ;
if ( V_115 & V_124 )
V_15 -> V_7 |= V_125 ;
if ( V_115 & V_126 )
V_15 -> V_10 |= V_127 ;
if ( V_115 & V_128 )
V_15 -> V_7 |= V_129 ;
if ( V_115 & V_130 )
V_15 -> V_7 |= V_131 ;
if ( V_115 & V_132 )
V_15 -> V_10 |= V_133 ;
return V_115 & V_94 ;
}
static inline unsigned int F_46 ( struct V_14 * V_15 )
{
unsigned int V_134 ;
V_134 = F_47 () ;
if ( ( V_134 & V_135 ) == V_136
&& V_107 )
V_15 -> V_108 += ( V_134 & V_137 ) * 0x40 ;
V_15 -> V_138 = ( V_134 >> 16 ) & 0xff ;
return V_134 & V_94 ;
}
static void T_2 F_48 ( struct V_14 * V_15 )
{
int V_139 ;
V_15 -> V_7 = V_140 | V_141 | V_142 |
V_143 | V_144 | V_145 ;
V_15 -> V_112 . V_113 = V_114 ;
V_139 = F_37 ( V_15 ) ;
F_49 ( ! V_139 ) ;
if ( V_139 )
V_139 = F_40 ( V_15 ) ;
if ( V_139 )
V_139 = F_42 ( V_15 ) ;
if ( V_139 )
V_139 = F_44 ( V_15 ) ;
if ( V_139 )
V_139 = F_46 ( V_15 ) ;
F_50 ( V_15 ) ;
if ( V_146 )
V_15 -> V_147 = F_51 () & 0x3ff ;
}
static inline void F_52 ( struct V_14 * V_15 , unsigned int V_69 )
{
switch ( V_15 -> V_56 & 0xff00 ) {
case V_148 :
V_15 -> V_17 = V_149 ;
V_150 [ V_69 ] = L_2 ;
F_36 ( V_15 , V_86 ) ;
V_15 -> V_7 = V_90 | V_151 |
V_152 ;
if ( F_29 () )
V_15 -> V_7 |= V_8 ;
V_15 -> V_108 = 64 ;
break;
case V_153 :
if ( ( V_15 -> V_56 & 0xff ) == V_154 ) {
if ( F_21 () ) {
V_15 -> V_17 = V_19 ;
V_150 [ V_69 ] = L_3 ;
} else {
V_15 -> V_17 = V_155 ;
V_150 [ V_69 ] = L_4 ;
}
} else {
V_15 -> V_17 = V_156 ;
V_150 [ V_69 ] = L_5 ;
}
F_36 ( V_15 , V_86 ) ;
V_15 -> V_7 = V_90 | V_151 |
V_152 ;
if ( F_29 () )
V_15 -> V_7 |= V_8 ;
V_15 -> V_108 = 64 ;
break;
case V_157 :
if ( F_38 () & V_158 ) {
if ( ( V_15 -> V_56 & 0xff ) >= V_159 ) {
V_15 -> V_17 = V_160 ;
V_150 [ V_69 ] = L_6 ;
} else {
V_15 -> V_17 = V_161 ;
V_150 [ V_69 ] = L_7 ;
}
} else {
if ( ( V_15 -> V_56 & 0xff ) >= V_159 ) {
V_15 -> V_17 = V_162 ;
V_150 [ V_69 ] = L_8 ;
} else {
V_15 -> V_17 = V_163 ;
V_150 [ V_69 ] = L_9 ;
}
}
F_36 ( V_15 , V_85 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_100 | V_165 |
V_144 ;
V_15 -> V_108 = 48 ;
break;
case V_166 :
F_36 ( V_15 , V_85 ) ;
V_15 -> V_7 = V_164 ;
V_15 -> V_108 = 32 ;
switch ( V_15 -> V_56 & 0xf0 ) {
case V_167 :
V_15 -> V_17 = V_168 ;
V_150 [ V_69 ] = L_10 ;
break;
case V_169 :
V_15 -> V_17 = V_170 ;
V_150 [ V_69 ] = L_11 ;
break;
case V_171 :
if ( ( V_15 -> V_56 & 0xf ) < 0x3 ) {
V_15 -> V_17 = V_172 ;
V_150 [ V_69 ] = L_12 ;
} else {
V_15 -> V_17 = V_173 ;
V_150 [ V_69 ] = L_13 ;
}
break;
case V_174 :
if ( ( V_15 -> V_56 & 0xf ) < 0x4 ) {
V_15 -> V_17 = V_175 ;
V_150 [ V_69 ] = L_14 ;
} else {
V_15 -> V_17 = V_176 ;
V_15 -> V_7 |= V_144 ;
V_150 [ V_69 ] = L_15 ;
}
break;
default:
F_15 ( V_177 L_16 ) ;
V_15 -> V_17 = V_178 ;
V_150 [ V_69 ] = L_17 ;
break;
}
break;
case V_179 :
V_15 -> V_17 = V_180 ;
V_150 [ V_69 ] = L_18 ;
F_36 ( V_15 , V_85 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_144 ;
V_15 -> V_108 = 32 ;
break;
case V_181 :
V_15 -> V_17 = V_23 ;
V_150 [ V_69 ] = L_19 ;
F_36 ( V_15 , V_85 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_144 ;
V_15 -> V_108 = 48 ;
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
case V_182 :
F_36 ( V_15 , V_86 ) ;
V_15 -> V_7 = V_90 | V_183 ;
if ( ( V_15 -> V_56 & 0xf0 ) == ( V_184 & 0xf0 ) ) {
V_15 -> V_17 = V_21 ;
V_150 [ V_69 ] = L_20 ;
V_15 -> V_108 = 64 ;
} else {
switch ( V_15 -> V_56 & 0xff ) {
case V_185 :
V_15 -> V_17 = V_186 ;
V_150 [ V_69 ] = L_21 ;
V_15 -> V_108 = 32 ;
break;
case V_187 :
V_15 -> V_17 = V_188 ;
V_150 [ V_69 ] = L_22 ;
V_15 -> V_108 = 64 ;
break;
}
}
break;
case V_189 :
V_15 -> V_17 = V_26 ;
V_150 [ V_69 ] = L_23 ;
F_36 ( V_15 , V_85 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_144 ;
V_15 -> V_108 = 48 ;
break;
case V_190 :
V_15 -> V_17 = V_57 ;
V_150 [ V_69 ] = L_24 ;
F_36 ( V_15 , V_85 ) ;
V_15 -> V_7 = V_164 | V_144 ;
if ( ! ( V_15 -> V_56 & 0x08 ) )
V_15 -> V_7 |= V_8 | V_106 ;
V_15 -> V_108 = 48 ;
break;
case V_191 :
V_15 -> V_17 = V_27 ;
V_150 [ V_69 ] = L_25 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_144 ;
V_15 -> V_108 = 48 ;
break;
case V_192 :
V_15 -> V_17 = V_193 ;
V_150 [ V_69 ] = L_26 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_100 | V_144 ;
V_15 -> V_108 = 48 ;
break;
case V_194 :
V_15 -> V_17 = V_28 ;
V_150 [ V_69 ] = L_27 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_100 | V_144 ;
V_15 -> V_108 = 48 ;
break;
case V_195 :
V_15 -> V_17 = V_29 ;
V_150 [ V_69 ] = L_28 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_143 | V_144 ;
V_15 -> V_108 = 48 ;
break;
case V_196 :
V_15 -> V_17 = V_197 ;
V_150 [ V_69 ] = L_29 ;
F_36 ( V_15 , V_87 ) ;
V_15 -> V_7 = V_90 | V_8 |
V_144 ;
V_15 -> V_108 = 32 ;
break;
case V_198 :
V_15 -> V_17 = V_199 ;
V_150 [ V_69 ] = L_30 ;
F_36 ( V_15 , V_87 ) ;
V_15 -> V_7 = V_90 | V_8 |
V_144 ;
V_15 -> V_108 = 32 ;
break;
case V_200 :
V_15 -> V_17 = V_48 ;
V_150 [ V_69 ] = L_31 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_144 ;
V_15 -> V_108 = ( F_53 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_201 :
V_15 -> V_17 = V_60 ;
V_150 [ V_69 ] = L_32 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_164 | V_8 | V_106 |
V_144 ;
V_15 -> V_108 = ( F_53 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_202 :
V_15 -> V_17 = V_203 ;
V_150 [ V_69 ] = L_33 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_90 | V_140 |
V_8 | V_106 |
V_144 ;
V_15 -> V_108 = 384 ;
break;
case V_204 :
V_15 -> V_17 = V_205 ;
V_150 [ V_69 ] = L_34 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_90 | V_141 | V_140 |
V_8 | V_106 |
V_142 | V_100 |
V_144 ;
V_15 -> V_108 = 64 ;
break;
case V_206 :
V_15 -> V_17 = V_207 ;
V_150 [ V_69 ] = L_35 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_90 | V_141 | V_140 |
V_8 | V_106 |
V_142 | V_100 |
V_144 ;
V_15 -> V_108 = 64 ;
break;
case V_208 :
V_15 -> V_17 = V_209 ;
V_150 [ V_69 ] = L_36 ;
F_36 ( V_15 , V_84 ) ;
V_15 -> V_7 = V_90 | V_141 | V_140 |
V_8 | V_106 |
V_142 | V_100 |
V_144 ;
V_15 -> V_108 = 64 ;
break;
case V_210 :
V_15 -> V_17 = V_211 ;
V_150 [ V_69 ] = L_37 ;
switch ( V_15 -> V_56 & V_61 ) {
case V_212 :
F_23 ( V_69 , L_38 ) ;
break;
case V_213 :
F_23 ( V_69 , L_39 ) ;
break;
}
F_36 ( V_15 , V_85 ) ;
V_15 -> V_7 = V_164 |
V_8 | V_144 |
V_106 ;
V_15 -> V_108 = 64 ;
break;
case V_214 :
F_48 ( V_15 ) ;
V_15 -> V_17 = V_44 ;
switch ( V_15 -> V_56 & V_61 ) {
case V_215 :
V_150 [ V_69 ] = L_40 ;
break;
}
break;
}
}
static inline void F_54 ( struct V_14 * V_15 , unsigned int V_69 )
{
F_48 ( V_15 ) ;
switch ( V_15 -> V_56 & 0xff00 ) {
case V_216 :
V_15 -> V_17 = V_30 ;
V_150 [ V_69 ] = L_41 ;
break;
case V_217 :
case V_218 :
V_15 -> V_17 = V_31 ;
V_150 [ V_69 ] = L_42 ;
break;
case V_219 :
case V_220 :
V_15 -> V_17 = V_32 ;
V_150 [ V_69 ] = L_43 ;
break;
case V_221 :
V_15 -> V_17 = V_33 ;
V_150 [ V_69 ] = L_44 ;
break;
case V_222 :
V_15 -> V_17 = V_223 ;
V_150 [ V_69 ] = L_45 ;
break;
case V_224 :
V_15 -> V_17 = V_59 ;
V_150 [ V_69 ] = L_46 ;
break;
case V_225 :
V_15 -> V_17 = V_51 ;
V_150 [ V_69 ] = L_47 ;
break;
case V_226 :
V_15 -> V_17 = V_51 ;
V_150 [ V_69 ] = L_48 ;
break;
case V_227 :
V_15 -> V_17 = V_34 ;
V_150 [ V_69 ] = L_49 ;
break;
case V_228 :
V_15 -> V_17 = V_52 ;
V_150 [ V_69 ] = L_50 ;
break;
case V_229 :
V_15 -> V_17 = V_55 ;
V_150 [ V_69 ] = L_51 ;
break;
case V_230 :
V_15 -> V_17 = V_49 ;
V_150 [ V_69 ] = L_52 ;
break;
case V_231 :
V_15 -> V_17 = V_50 ;
V_150 [ V_69 ] = L_53 ;
break;
case V_232 :
V_15 -> V_17 = V_53 ;
V_150 [ V_69 ] = L_54 ;
break;
case V_233 :
V_15 -> V_17 = V_55 ;
V_150 [ V_69 ] = L_55 ;
break;
}
F_55 () ;
}
static inline void F_56 ( struct V_14 * V_15 , unsigned int V_69 )
{
F_48 ( V_15 ) ;
switch ( V_15 -> V_56 & 0xff00 ) {
case V_234 :
case V_235 :
V_15 -> V_17 = V_58 ;
switch ( ( V_15 -> V_56 >> 24 ) & 0xff ) {
case 0 :
V_150 [ V_69 ] = L_56 ;
break;
case 1 :
V_150 [ V_69 ] = L_57 ;
break;
case 2 :
V_150 [ V_69 ] = L_58 ;
break;
case 3 :
V_150 [ V_69 ] = L_59 ;
break;
case 4 :
V_150 [ V_69 ] = L_60 ;
if ( ( V_15 -> V_56 & 0xff ) == 2 )
V_150 [ V_69 ] = L_61 ;
break;
case 5 :
V_150 [ V_69 ] = L_62 ;
break;
default:
V_150 [ V_69 ] = L_63 ;
break;
}
break;
}
}
static inline void F_57 ( struct V_14 * V_15 , unsigned int V_69 )
{
F_48 ( V_15 ) ;
switch ( V_15 -> V_56 & 0xff00 ) {
case V_236 :
V_15 -> V_17 = V_237 ;
V_150 [ V_69 ] = L_64 ;
if ( ( V_15 -> V_56 & 0xff ) < 0x02 )
V_15 -> V_7 &= ~ ( V_8 | V_106 ) ;
break;
case V_238 :
V_15 -> V_17 = V_239 ;
V_150 [ V_69 ] = L_65 ;
break;
}
}
static inline void F_58 ( struct V_14 * V_15 , unsigned int V_69 )
{
F_48 ( V_15 ) ;
switch ( V_15 -> V_56 & 0xff00 ) {
case V_240 :
V_15 -> V_17 = V_241 ;
V_150 [ V_69 ] = L_66 ;
V_15 -> V_112 . V_242 = 8 ;
V_15 -> V_108 = 64 ;
break;
}
}
static inline void F_59 ( struct V_14 * V_15 , unsigned int V_69 )
{
F_48 ( V_15 ) ;
switch ( V_15 -> V_56 & 0xff00 ) {
case V_243 :
V_15 -> V_17 = V_35 ;
V_150 [ V_69 ] = L_67 ;
F_36 ( V_15 , V_82 ) ;
break;
}
}
static inline void F_60 ( struct V_14 * V_15 , unsigned int V_69 )
{
F_48 ( V_15 ) ;
switch ( V_15 -> V_56 & 0xff00 ) {
case V_244 :
case V_245 :
V_15 -> V_17 = V_246 ;
V_150 [ V_69 ] = L_68 ;
F_23 ( V_69 , L_69 ) ;
break;
case V_247 :
case V_248 :
case V_249 :
V_15 -> V_17 = V_36 ;
V_150 [ V_69 ] = L_70 ;
F_23 ( V_69 , L_71 ) ;
break;
case V_250 : {
int V_251 = V_15 -> V_56 & 0xff ;
if ( V_251 >= V_252 &&
V_251 <= V_253 ) {
V_15 -> V_17 = V_38 ;
V_150 [ V_69 ] = L_72 ;
F_23 ( V_69 , L_73 ) ;
} else {
V_15 -> V_17 = V_37 ;
V_150 [ V_69 ] = L_74 ;
F_23 ( V_69 , L_75 ) ;
}
break;
}
case V_254 :
V_15 -> V_17 = V_39 ;
V_150 [ V_69 ] = L_76 ;
F_23 ( V_69 , L_77 ) ;
V_15 -> V_7 |= V_129 ;
break;
}
}
static inline void F_61 ( struct V_14 * V_15 , unsigned int V_69 )
{
F_48 ( V_15 ) ;
switch ( V_15 -> V_56 & 0xff00 ) {
case V_255 :
case V_256 :
case V_257 :
V_15 -> V_17 = V_40 ;
V_150 [ V_69 ] = L_78 ;
goto V_258;
case V_259 :
case V_260 :
case V_261 :
case V_262 :
V_15 -> V_17 = V_41 ;
V_150 [ V_69 ] = L_79 ;
V_258:
F_23 ( V_69 , L_80 ) ;
break;
case V_263 :
case V_264 :
case V_265 :
case V_266 :
V_15 -> V_17 = V_42 ;
V_150 [ V_69 ] = L_81 ;
F_23 ( V_69 , L_82 ) ;
break;
default:
F_15 ( V_177 L_83 ) ;
V_15 -> V_17 = V_267 ;
break;
}
}
static inline void F_62 ( struct V_14 * V_15 , unsigned int V_69 )
{
F_48 ( V_15 ) ;
V_15 -> V_7 &= ~ V_142 ;
switch ( V_15 -> V_56 & 0xff00 ) {
case V_268 :
V_15 -> V_17 = V_43 ;
V_150 [ V_69 ] = L_84 ;
break;
default:
F_39 ( L_85 ) ;
break;
}
}
static inline void F_63 ( struct V_14 * V_15 , int V_69 )
{
F_48 ( V_15 ) ;
if ( ( V_15 -> V_56 & 0xff00 ) == V_269 ) {
V_15 -> V_17 = V_58 ;
V_150 [ V_69 ] = L_86 ;
return;
}
V_15 -> V_7 = ( V_90 |
V_140 |
V_142 |
V_143 |
V_100 |
V_104 |
V_144 ) ;
switch ( V_15 -> V_56 & 0xff00 ) {
case V_270 :
case V_271 :
V_15 -> V_17 = V_46 ;
V_150 [ V_69 ] = L_87 ;
break;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
V_15 -> V_17 = V_45 ;
V_150 [ V_69 ] = L_88 ;
break;
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
V_15 -> V_17 = V_45 ;
V_150 [ V_69 ] = L_89 ;
break;
default:
F_64 ( L_90 ,
V_15 -> V_56 ) ;
V_15 -> V_17 = V_45 ;
break;
}
if ( V_15 -> V_17 == V_46 ) {
F_36 ( V_15 , V_78 ) ;
V_15 -> V_7 |= ( V_8 | V_129 | V_145 ) ;
V_15 -> V_108 = ( ( F_65 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_36 ( V_15 , V_81 ) ;
V_15 -> V_108 = ( ( F_41 () >> 25 ) & 0x3f ) + 1 ;
}
}
T_2 void F_66 ( void )
{
struct V_14 * V_15 = & V_16 ;
unsigned int V_69 = F_67 () ;
V_15 -> V_56 = V_293 ;
V_15 -> V_73 = V_75 ;
V_15 -> V_17 = V_267 ;
V_15 -> V_56 = F_68 () ;
switch ( V_15 -> V_56 & 0xff0000 ) {
case V_294 :
F_52 ( V_15 , V_69 ) ;
break;
case V_295 :
F_54 ( V_15 , V_69 ) ;
break;
case V_296 :
F_56 ( V_15 , V_69 ) ;
break;
case V_297 :
F_57 ( V_15 , V_69 ) ;
break;
case V_298 :
F_60 ( V_15 , V_69 ) ;
break;
case V_299 :
F_58 ( V_15 , V_69 ) ;
break;
case V_300 :
F_59 ( V_15 , V_69 ) ;
break;
case V_301 :
F_61 ( V_15 , V_69 ) ;
break;
case V_302 :
F_62 ( V_15 , V_69 ) ;
break;
case V_303 :
F_63 ( V_15 , V_69 ) ;
break;
}
F_49 ( ! V_150 [ V_69 ] ) ;
F_49 ( V_15 -> V_17 == V_267 ) ;
F_49 ( F_69 () != V_15 -> V_17 ) ;
if ( V_9 )
V_15 -> V_7 &= ~ V_8 ;
if ( V_13 )
V_15 -> V_10 &= ~ ( V_11 | V_12 ) ;
if ( V_15 -> V_7 & V_8 ) {
V_15 -> V_73 = F_24 () ;
if ( V_15 -> V_79 & ( V_82 | V_80 |
V_81 | V_78 ) ) {
if ( V_15 -> V_73 & V_304 )
V_15 -> V_10 |= V_305 ;
}
}
if ( V_146 ) {
V_15 -> V_306 = ( ( F_70 () >> 26 ) & 0x0f ) + 1 ;
V_15 -> V_7 |= V_307 ;
}
else
V_15 -> V_306 = 1 ;
F_30 ( V_15 ) ;
#ifdef F_71
if ( V_69 == 0 )
V_308 = ~ ( ( 1ull << V_309 ) - 1 ) ;
#endif
}
T_2 void F_72 ( void )
{
struct V_14 * V_15 = & V_16 ;
F_15 ( V_177 L_91 ,
V_15 -> V_56 , F_73 () ) ;
if ( V_15 -> V_7 & V_8 )
F_15 ( V_177 L_92 , V_15 -> V_73 ) ;
}
