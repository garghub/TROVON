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
V_6 [ 0 ] . V_10 &= ~ V_11 ;
V_12 = 1 ;
return 1 ;
}
void T_1 F_14 ( void )
{
struct V_13 * V_14 = & V_15 ;
if ( V_5 ) {
F_15 ( L_1 ) ;
return;
}
switch ( V_14 -> V_16 ) {
case V_17 :
case V_18 :
V_19 = F_1 ;
break;
case V_20 :
V_19 = F_4 ;
break;
case V_21 :
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
V_19 = V_46 ;
break;
case V_47 :
V_19 = F_9 ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_19 = V_46 ;
if ( F_16 () & V_52 )
V_19 = F_8 ;
break;
case V_53 :
V_19 = V_46 ;
if ( ( V_14 -> V_54 & 0xff ) >= F_17 ( 2 , 1 , 0 ) )
V_19 = F_8 ;
break;
case V_55 :
V_19 = F_8 ;
break;
case V_56 :
V_19 = F_10 ;
break;
case V_57 :
if ( ( V_14 -> V_54 & 0xff ) <= 0x64 )
break;
break;
case V_58 :
if ( ( V_14 -> V_54 & 0x00ff ) >= 0x40 )
V_19 = V_46 ;
break;
default:
break;
}
}
static inline void F_18 ( void )
{
struct V_13 * V_14 = & V_15 ;
switch ( V_14 -> V_16 ) {
case V_50 :
if ( ( V_14 -> V_54 & V_59 ) <= V_60 )
F_19 ( F_16 () | V_61 ) ;
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
extern unsigned long V_62 ( unsigned long ) ;
unsigned long V_63 , V_64 ;
unsigned long V_1 = F_2 () ;
V_63 = V_62 ( V_65 ) ;
F_3 ( V_1 ^ V_66 ) ;
V_64 = V_62 ( V_65 ) ;
F_3 ( V_1 ) ;
return V_63 != V_64 ;
#else
return 0 ;
#endif
}
static inline void F_23 ( int V_67 , const char * V_68 )
{
if ( V_67 == 0 )
V_69 = V_68 ;
}
static inline unsigned long F_24 ( void )
{
unsigned long V_70 , V_71 ;
V_70 = F_25 () ;
F_26 () ;
V_71 = F_27 ( V_72 ) ;
F_28 ( V_70 ) ;
return V_71 ;
}
static inline int F_29 ( void )
{
return ( ( F_24 () & 0xff00 ) != V_73 ) ;
}
static inline void F_30 ( struct V_13 * V_14 )
{
#ifdef F_31
F_32 ( 0x3fffffffffffe000ULL ) ;
F_33 () ;
V_14 -> V_74 = F_34 ( F_35 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static inline unsigned int F_36 ( struct V_13 * V_14 )
{
unsigned int V_75 ;
int V_76 ;
V_75 = F_37 () ;
if ( ( ( V_75 & V_77 ) >> 7 ) == 1 )
V_14 -> V_7 |= V_78 ;
V_76 = ( V_75 & V_79 ) >> 13 ;
switch ( V_76 ) {
case 0 :
switch ( ( V_75 & V_80 ) >> 10 ) {
case 0 :
V_14 -> V_81 = V_82 ;
break;
case 1 :
V_14 -> V_81 = V_83 ;
break;
default:
goto V_84;
}
break;
case 2 :
switch ( ( V_75 & V_80 ) >> 10 ) {
case 0 :
V_14 -> V_81 = V_85 ;
break;
case 1 :
V_14 -> V_81 = V_86 ;
break;
default:
goto V_84;
}
break;
default:
goto V_84;
}
return V_75 & V_87 ;
V_84:
F_38 ( V_88 , V_75 ) ;
}
static inline unsigned int F_39 ( struct V_13 * V_14 )
{
unsigned int V_89 ;
V_89 = F_40 () ;
if ( V_89 & V_90 )
V_14 -> V_10 |= V_91 ;
if ( V_89 & V_92 )
V_14 -> V_7 |= V_93 ;
if ( V_89 & V_94 )
V_14 -> V_10 |= V_95 ;
if ( V_89 & V_96 )
V_14 -> V_7 |= V_97 ;
if ( V_89 & V_98 ) {
V_14 -> V_7 |= V_8 ;
V_14 -> V_7 |= V_99 ;
}
if ( V_100 )
V_14 -> V_101 = ( ( V_89 & V_102 ) >> 25 ) + 1 ;
return V_89 & V_87 ;
}
static inline unsigned int F_41 ( struct V_13 * V_14 )
{
unsigned int V_103 ;
V_103 = F_42 () ;
if ( V_103 & V_104 )
V_14 -> V_105 . V_106 &= ~ V_107 ;
return V_103 & V_87 ;
}
static inline unsigned int F_43 ( struct V_13 * V_14 )
{
unsigned int V_108 ;
V_108 = F_44 () ;
if ( V_108 & V_109 )
V_14 -> V_10 |= V_110 ;
if ( V_108 & V_111 )
V_14 -> V_10 |= V_11 ;
if ( V_108 & V_112 )
V_14 -> V_7 |= V_113 ;
if ( V_108 & V_114 )
V_14 -> V_7 |= V_115 ;
if ( V_108 & V_116 )
V_14 -> V_10 |= V_117 ;
if ( V_108 & V_118 )
V_14 -> V_7 |= V_119 ;
return V_108 & V_87 ;
}
static inline unsigned int F_45 ( struct V_13 * V_14 )
{
unsigned int V_120 ;
V_120 = F_46 () ;
if ( ( V_120 & V_121 ) == V_122
&& V_100 )
V_14 -> V_101 += ( V_120 & V_123 ) * 0x40 ;
V_14 -> V_124 = ( V_120 >> 16 ) & 0xff ;
return V_120 & V_87 ;
}
static void T_2 F_47 ( struct V_13 * V_14 )
{
int V_125 ;
V_14 -> V_7 = V_126 | V_127 | V_128 |
V_129 | V_130 | V_131 ;
V_14 -> V_105 . V_106 = V_107 ;
V_125 = F_36 ( V_14 ) ;
F_48 ( ! V_125 ) ;
if ( V_125 )
V_125 = F_39 ( V_14 ) ;
if ( V_125 )
V_125 = F_41 ( V_14 ) ;
if ( V_125 )
V_125 = F_43 ( V_14 ) ;
if ( V_125 )
V_125 = F_45 ( V_14 ) ;
F_49 ( V_14 ) ;
if ( V_132 )
V_14 -> V_133 = F_50 () & 0x3ff ;
}
static inline void F_51 ( struct V_13 * V_14 , unsigned int V_67 )
{
switch ( V_14 -> V_54 & 0xff00 ) {
case V_134 :
V_14 -> V_16 = V_135 ;
V_136 [ V_67 ] = L_2 ;
V_14 -> V_81 = V_137 ;
V_14 -> V_7 = V_78 | V_138 |
V_139 ;
if ( F_29 () )
V_14 -> V_7 |= V_8 ;
V_14 -> V_101 = 64 ;
break;
case V_140 :
if ( ( V_14 -> V_54 & 0xff ) == V_141 ) {
if ( F_21 () ) {
V_14 -> V_16 = V_18 ;
V_136 [ V_67 ] = L_3 ;
} else {
V_14 -> V_16 = V_142 ;
V_136 [ V_67 ] = L_4 ;
}
break;
} else {
V_14 -> V_16 = V_143 ;
V_136 [ V_67 ] = L_5 ;
}
V_14 -> V_81 = V_137 ;
V_14 -> V_7 = V_78 | V_138 |
V_139 ;
if ( F_29 () )
V_14 -> V_7 |= V_8 ;
V_14 -> V_101 = 64 ;
break;
case V_144 :
if ( F_37 () & V_145 ) {
if ( ( V_14 -> V_54 & 0xff ) >= V_146 ) {
V_14 -> V_16 = V_147 ;
V_136 [ V_67 ] = L_6 ;
} else {
V_14 -> V_16 = V_148 ;
V_136 [ V_67 ] = L_7 ;
}
} else {
if ( ( V_14 -> V_54 & 0xff ) >= V_146 ) {
V_14 -> V_16 = V_149 ;
V_136 [ V_67 ] = L_8 ;
} else {
V_14 -> V_16 = V_150 ;
V_136 [ V_67 ] = L_9 ;
}
}
V_14 -> V_81 = V_151 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_93 | V_153 |
V_130 ;
V_14 -> V_101 = 48 ;
break;
case V_154 :
switch ( V_14 -> V_54 & 0xf0 ) {
case V_155 :
V_14 -> V_16 = V_156 ;
V_136 [ V_67 ] = L_10 ;
break;
case V_157 :
V_14 -> V_16 = V_158 ;
V_136 [ V_67 ] = L_11 ;
break;
case V_159 :
if ( ( V_14 -> V_54 & 0xf ) < 0x3 ) {
V_14 -> V_16 = V_160 ;
V_136 [ V_67 ] = L_12 ;
} else {
V_14 -> V_16 = V_161 ;
V_136 [ V_67 ] = L_13 ;
}
break;
case V_162 :
if ( ( V_14 -> V_54 & 0xf ) < 0x4 ) {
V_14 -> V_16 = V_163 ;
V_136 [ V_67 ] = L_14 ;
} else {
V_14 -> V_16 = V_164 ;
V_136 [ V_67 ] = L_15 ;
}
break;
default:
F_15 ( V_165 L_16 ) ;
V_14 -> V_16 = V_166 ;
V_136 [ V_67 ] = L_17 ;
break;
}
V_14 -> V_81 = V_151 ;
V_14 -> V_7 = V_152 ;
V_14 -> V_101 = 32 ;
break;
case V_167 :
V_14 -> V_16 = V_168 ;
V_136 [ V_67 ] = L_18 ;
V_14 -> V_81 = V_151 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_130 ;
V_14 -> V_101 = 32 ;
break;
case V_169 :
V_14 -> V_16 = V_22 ;
V_136 [ V_67 ] = L_19 ;
V_14 -> V_81 = V_151 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_130 ;
V_14 -> V_101 = 48 ;
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
case V_170 :
V_14 -> V_81 = V_137 ;
V_14 -> V_7 = V_78 | V_171 ;
if ( ( V_14 -> V_54 & 0xf0 ) == ( V_172 & 0xf0 ) ) {
V_14 -> V_16 = V_20 ;
V_136 [ V_67 ] = L_20 ;
V_14 -> V_101 = 64 ;
} else {
switch ( V_14 -> V_54 & 0xff ) {
case V_173 :
V_14 -> V_16 = V_174 ;
V_136 [ V_67 ] = L_21 ;
V_14 -> V_101 = 32 ;
break;
case V_175 :
V_14 -> V_16 = V_176 ;
V_136 [ V_67 ] = L_22 ;
V_14 -> V_101 = 64 ;
break;
}
}
break;
case V_177 :
V_14 -> V_16 = V_25 ;
V_136 [ V_67 ] = L_23 ;
V_14 -> V_81 = V_151 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_130 ;
V_14 -> V_101 = 48 ;
break;
case V_178 :
V_14 -> V_16 = V_55 ;
V_136 [ V_67 ] = L_24 ;
V_14 -> V_81 = V_151 ;
V_14 -> V_7 = V_152 | V_130 ;
if ( ! ( V_14 -> V_54 & 0x08 ) )
V_14 -> V_7 |= V_8 | V_99 ;
V_14 -> V_101 = 48 ;
break;
case V_179 :
V_14 -> V_16 = V_26 ;
V_136 [ V_67 ] = L_25 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_130 ;
V_14 -> V_101 = 48 ;
break;
case V_181 :
V_14 -> V_16 = V_182 ;
V_136 [ V_67 ] = L_26 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_93 | V_130 ;
V_14 -> V_101 = 48 ;
break;
case V_183 :
V_14 -> V_16 = V_27 ;
V_136 [ V_67 ] = L_27 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_93 | V_130 ;
V_14 -> V_101 = 48 ;
break;
case V_184 :
V_14 -> V_16 = V_28 ;
V_136 [ V_67 ] = L_28 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_129 | V_130 ;
V_14 -> V_101 = 48 ;
break;
case V_185 :
V_14 -> V_16 = V_186 ;
V_136 [ V_67 ] = L_29 ;
V_14 -> V_81 = V_187 ;
V_14 -> V_7 = V_78 | V_8 |
V_130 ;
V_14 -> V_101 = 32 ;
break;
case V_188 :
V_14 -> V_16 = V_189 ;
V_136 [ V_67 ] = L_30 ;
V_14 -> V_81 = V_187 ;
V_14 -> V_7 = V_78 | V_8 |
V_130 ;
V_14 -> V_101 = 32 ;
break;
case V_190 :
V_14 -> V_16 = V_47 ;
V_136 [ V_67 ] = L_31 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_130 ;
V_14 -> V_101 = ( F_52 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_191 :
V_14 -> V_16 = V_58 ;
V_136 [ V_67 ] = L_32 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_152 | V_8 | V_99 |
V_130 ;
V_14 -> V_101 = ( F_52 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_192 :
V_14 -> V_16 = V_193 ;
V_136 [ V_67 ] = L_33 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_78 | V_126 |
V_8 | V_99 |
V_130 ;
V_14 -> V_101 = 384 ;
break;
case V_194 :
V_14 -> V_16 = V_195 ;
V_136 [ V_67 ] = L_34 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_78 | V_127 | V_126 |
V_8 | V_99 |
V_128 | V_93 |
V_130 ;
V_14 -> V_101 = 64 ;
break;
case V_196 :
V_14 -> V_16 = V_197 ;
V_136 [ V_67 ] = L_35 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_78 | V_127 | V_126 |
V_8 | V_99 |
V_128 | V_93 |
V_130 ;
V_14 -> V_101 = 64 ;
break;
case V_198 :
V_14 -> V_16 = V_199 ;
V_136 [ V_67 ] = L_36 ;
V_14 -> V_81 = V_180 ;
V_14 -> V_7 = V_78 | V_127 | V_126 |
V_8 | V_99 |
V_128 | V_93 |
V_130 ;
V_14 -> V_101 = 64 ;
break;
case V_200 :
V_14 -> V_16 = V_201 ;
V_136 [ V_67 ] = L_37 ;
switch ( V_14 -> V_54 & V_59 ) {
case V_202 :
F_23 ( V_67 , L_38 ) ;
break;
case V_203 :
F_23 ( V_67 , L_39 ) ;
break;
}
V_14 -> V_81 = V_151 ;
V_14 -> V_7 = V_152 |
V_8 | V_130 |
V_99 ;
V_14 -> V_101 = 64 ;
break;
case V_204 :
F_47 ( V_14 ) ;
V_14 -> V_16 = V_43 ;
switch ( V_14 -> V_54 & V_59 ) {
case V_205 :
V_136 [ V_67 ] = L_40 ;
break;
}
break;
}
}
static inline void F_53 ( struct V_13 * V_14 , unsigned int V_67 )
{
F_47 ( V_14 ) ;
switch ( V_14 -> V_54 & 0xff00 ) {
case V_206 :
V_14 -> V_16 = V_29 ;
V_136 [ V_67 ] = L_41 ;
break;
case V_207 :
case V_208 :
V_14 -> V_16 = V_30 ;
V_136 [ V_67 ] = L_42 ;
break;
case V_209 :
case V_210 :
V_14 -> V_16 = V_31 ;
V_136 [ V_67 ] = L_43 ;
break;
case V_211 :
V_14 -> V_16 = V_32 ;
V_136 [ V_67 ] = L_44 ;
break;
case V_212 :
V_14 -> V_16 = V_213 ;
V_136 [ V_67 ] = L_45 ;
break;
case V_214 :
V_14 -> V_16 = V_57 ;
V_136 [ V_67 ] = L_46 ;
break;
case V_215 :
case V_216 :
V_14 -> V_16 = V_49 ;
V_136 [ V_67 ] = L_47 ;
break;
case V_217 :
V_14 -> V_16 = V_33 ;
V_136 [ V_67 ] = L_48 ;
break;
case V_218 :
V_14 -> V_16 = V_50 ;
V_136 [ V_67 ] = L_49 ;
break;
case V_219 :
V_14 -> V_16 = V_53 ;
V_136 [ V_67 ] = L_50 ;
break;
case V_220 :
V_14 -> V_16 = V_48 ;
V_136 [ V_67 ] = L_51 ;
break;
case V_221 :
V_14 -> V_16 = V_51 ;
V_136 [ V_67 ] = L_52 ;
break;
}
F_54 () ;
}
static inline void F_55 ( struct V_13 * V_14 , unsigned int V_67 )
{
F_47 ( V_14 ) ;
switch ( V_14 -> V_54 & 0xff00 ) {
case V_222 :
case V_223 :
V_14 -> V_16 = V_56 ;
switch ( ( V_14 -> V_54 >> 24 ) & 0xff ) {
case 0 :
V_136 [ V_67 ] = L_53 ;
break;
case 1 :
V_136 [ V_67 ] = L_54 ;
break;
case 2 :
V_136 [ V_67 ] = L_55 ;
break;
case 3 :
V_136 [ V_67 ] = L_56 ;
break;
case 4 :
V_136 [ V_67 ] = L_57 ;
if ( ( V_14 -> V_54 & 0xff ) == 2 )
V_136 [ V_67 ] = L_58 ;
break;
case 5 :
V_136 [ V_67 ] = L_59 ;
break;
default:
V_136 [ V_67 ] = L_60 ;
break;
}
break;
}
}
static inline void F_56 ( struct V_13 * V_14 , unsigned int V_67 )
{
F_47 ( V_14 ) ;
switch ( V_14 -> V_54 & 0xff00 ) {
case V_224 :
V_14 -> V_16 = V_225 ;
V_136 [ V_67 ] = L_61 ;
if ( ( V_14 -> V_54 & 0xff ) < 0x02 )
V_14 -> V_7 &= ~ ( V_8 | V_99 ) ;
break;
case V_226 :
V_14 -> V_16 = V_227 ;
V_136 [ V_67 ] = L_62 ;
break;
}
}
static inline void F_57 ( struct V_13 * V_14 , unsigned int V_67 )
{
F_47 ( V_14 ) ;
switch ( V_14 -> V_54 & 0xff00 ) {
case V_228 :
V_14 -> V_16 = V_229 ;
V_136 [ V_67 ] = L_63 ;
V_14 -> V_105 . V_230 = 8 ;
V_14 -> V_101 = 64 ;
break;
}
}
static inline void F_58 ( struct V_13 * V_14 , unsigned int V_67 )
{
F_47 ( V_14 ) ;
switch ( V_14 -> V_54 & 0xff00 ) {
case V_231 :
V_14 -> V_16 = V_34 ;
V_136 [ V_67 ] = L_64 ;
V_14 -> V_81 = V_82 ;
break;
}
}
static inline void F_59 ( struct V_13 * V_14 , unsigned int V_67 )
{
F_47 ( V_14 ) ;
switch ( V_14 -> V_54 & 0xff00 ) {
case V_232 :
case V_233 :
V_14 -> V_16 = V_234 ;
V_136 [ V_67 ] = L_65 ;
F_23 ( V_67 , L_66 ) ;
break;
case V_235 :
case V_236 :
case V_237 :
V_14 -> V_16 = V_35 ;
V_136 [ V_67 ] = L_67 ;
F_23 ( V_67 , L_68 ) ;
break;
case V_238 : {
int V_239 = V_14 -> V_54 & 0xff ;
if ( V_239 >= V_240 &&
V_239 <= V_241 ) {
V_14 -> V_16 = V_37 ;
V_136 [ V_67 ] = L_69 ;
F_23 ( V_67 , L_70 ) ;
} else {
V_14 -> V_16 = V_36 ;
V_136 [ V_67 ] = L_71 ;
F_23 ( V_67 , L_72 ) ;
}
break;
}
case V_242 :
V_14 -> V_16 = V_38 ;
V_136 [ V_67 ] = L_73 ;
F_23 ( V_67 , L_74 ) ;
V_14 -> V_7 |= V_119 ;
break;
}
}
static inline void F_60 ( struct V_13 * V_14 , unsigned int V_67 )
{
F_47 ( V_14 ) ;
switch ( V_14 -> V_54 & 0xff00 ) {
case V_243 :
case V_244 :
case V_245 :
V_14 -> V_16 = V_39 ;
V_136 [ V_67 ] = L_75 ;
goto V_246;
case V_247 :
case V_248 :
case V_249 :
case V_250 :
V_14 -> V_16 = V_40 ;
V_136 [ V_67 ] = L_76 ;
V_246:
F_23 ( V_67 , L_77 ) ;
break;
case V_251 :
case V_252 :
case V_253 :
case V_254 :
V_14 -> V_16 = V_41 ;
V_136 [ V_67 ] = L_78 ;
F_23 ( V_67 , L_79 ) ;
break;
default:
F_15 ( V_165 L_80 ) ;
V_14 -> V_16 = V_255 ;
break;
}
}
static inline void F_61 ( struct V_13 * V_14 , unsigned int V_67 )
{
F_47 ( V_14 ) ;
V_14 -> V_7 &= ~ V_128 ;
switch ( V_14 -> V_54 & 0xff00 ) {
case V_256 :
V_14 -> V_16 = V_42 ;
V_136 [ V_67 ] = L_81 ;
break;
default:
F_38 ( L_82 ) ;
break;
}
}
static inline void F_62 ( struct V_13 * V_14 , int V_67 )
{
F_47 ( V_14 ) ;
if ( ( V_14 -> V_54 & 0xff00 ) == V_257 ) {
V_14 -> V_16 = V_56 ;
V_136 [ V_67 ] = L_83 ;
return;
}
V_14 -> V_7 = ( V_78 |
V_126 |
V_128 |
V_129 |
V_93 |
V_97 |
V_130 ) ;
switch ( V_14 -> V_54 & 0xff00 ) {
case V_258 :
case V_259 :
V_14 -> V_16 = V_45 ;
V_136 [ V_67 ] = L_84 ;
break;
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
V_14 -> V_16 = V_44 ;
V_136 [ V_67 ] = L_85 ;
break;
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
V_14 -> V_16 = V_44 ;
V_136 [ V_67 ] = L_86 ;
break;
default:
F_63 ( L_87 ,
V_14 -> V_54 ) ;
V_14 -> V_16 = V_44 ;
break;
}
if ( V_14 -> V_16 == V_45 ) {
V_14 -> V_81 = V_86 ;
V_14 -> V_7 |= ( V_8 | V_119 | V_131 ) ;
V_14 -> V_101 = ( ( F_64 () >> 16 ) & 0xffff ) + 1 ;
} else {
V_14 -> V_81 = V_85 ;
V_14 -> V_101 = ( ( F_40 () >> 25 ) & 0x3f ) + 1 ;
}
}
T_2 void F_65 ( void )
{
struct V_13 * V_14 = & V_15 ;
unsigned int V_67 = F_66 () ;
V_14 -> V_54 = V_281 ;
V_14 -> V_71 = V_73 ;
V_14 -> V_16 = V_255 ;
V_14 -> V_54 = F_67 () ;
switch ( V_14 -> V_54 & 0xff0000 ) {
case V_282 :
F_51 ( V_14 , V_67 ) ;
break;
case V_283 :
F_53 ( V_14 , V_67 ) ;
break;
case V_284 :
F_55 ( V_14 , V_67 ) ;
break;
case V_285 :
F_56 ( V_14 , V_67 ) ;
break;
case V_286 :
F_59 ( V_14 , V_67 ) ;
break;
case V_287 :
F_57 ( V_14 , V_67 ) ;
break;
case V_288 :
F_58 ( V_14 , V_67 ) ;
break;
case V_289 :
F_60 ( V_14 , V_67 ) ;
break;
case V_290 :
F_61 ( V_14 , V_67 ) ;
break;
case V_291 :
F_62 ( V_14 , V_67 ) ;
break;
}
F_48 ( ! V_136 [ V_67 ] ) ;
F_48 ( V_14 -> V_16 == V_255 ) ;
F_48 ( F_68 () != V_14 -> V_16 ) ;
if ( V_9 )
V_14 -> V_7 &= ~ V_8 ;
if ( V_12 )
V_14 -> V_10 &= ~ V_11 ;
if ( V_14 -> V_7 & V_8 ) {
V_14 -> V_71 = F_24 () ;
if ( V_14 -> V_81 == V_82 ||
V_14 -> V_81 == V_83 ||
V_14 -> V_81 == V_85 ||
V_14 -> V_81 == V_86 ) {
if ( V_14 -> V_71 & V_292 )
V_14 -> V_10 |= V_293 ;
}
}
if ( V_132 )
V_14 -> V_294 = ( ( F_69 () >> 26 ) & 0x0f ) + 1 ;
else
V_14 -> V_294 = 1 ;
F_30 ( V_14 ) ;
#ifdef F_70
if ( V_67 == 0 )
V_295 = ~ ( ( 1ull << V_296 ) - 1 ) ;
#endif
}
T_2 void F_71 ( void )
{
struct V_13 * V_14 = & V_15 ;
F_15 ( V_165 L_88 ,
V_14 -> V_54 , F_72 () ) ;
if ( V_14 -> V_7 & V_8 )
F_15 ( V_165 L_89 , V_14 -> V_71 ) ;
}
