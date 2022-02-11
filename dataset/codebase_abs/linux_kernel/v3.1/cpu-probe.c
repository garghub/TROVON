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
V_19 = V_43 ;
break;
case V_44 :
V_19 = F_9 ;
break;
case V_45 :
case V_46 :
case V_47 :
V_19 = V_43 ;
if ( F_16 () & V_48 )
V_19 = F_8 ;
break;
case V_49 :
V_19 = V_43 ;
if ( ( V_14 -> V_50 & 0xff ) >= F_17 ( 2 , 1 , 0 ) )
V_19 = F_8 ;
break;
case V_51 :
V_19 = F_8 ;
break;
case V_52 :
V_19 = F_10 ;
break;
case V_53 :
if ( ( V_14 -> V_50 & 0xff ) <= 0x64 )
break;
break;
case V_54 :
if ( ( V_14 -> V_50 & 0x00ff ) >= 0x40 )
V_19 = V_43 ;
break;
default:
break;
}
}
static inline void F_18 ( void )
{
struct V_13 * V_14 = & V_15 ;
switch ( V_14 -> V_16 ) {
case V_46 :
if ( ( V_14 -> V_50 & V_55 ) <= V_56 )
F_19 ( F_16 () | V_57 ) ;
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
extern unsigned long V_58 ( unsigned long ) ;
unsigned long V_59 , V_60 ;
unsigned long V_1 = F_2 () ;
V_59 = V_58 ( V_61 ) ;
F_3 ( V_1 ^ V_62 ) ;
V_60 = V_58 ( V_61 ) ;
F_3 ( V_1 ) ;
return V_59 != V_60 ;
#else
return 0 ;
#endif
}
static inline void F_23 ( int V_63 , const char * V_64 )
{
if ( V_63 == 0 )
V_65 = V_64 ;
}
static inline unsigned long F_24 ( void )
{
unsigned long V_66 , V_67 ;
V_66 = F_25 () ;
F_26 () ;
V_67 = F_27 ( V_68 ) ;
F_28 ( V_66 ) ;
return V_67 ;
}
static inline int F_29 ( void )
{
return ( ( F_24 () & 0xff00 ) != V_69 ) ;
}
static inline void F_30 ( struct V_13 * V_14 )
{
#ifdef F_31
F_32 ( 0x3fffffffffffe000ULL ) ;
F_33 () ;
V_14 -> V_70 = F_34 ( F_35 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static inline void F_36 ( struct V_13 * V_14 , unsigned int V_63 )
{
switch ( V_14 -> V_50 & 0xff00 ) {
case V_71 :
V_14 -> V_16 = V_72 ;
V_73 [ V_63 ] = L_2 ;
V_14 -> V_74 = V_75 ;
V_14 -> V_7 = V_76 | V_77 |
V_78 ;
if ( F_29 () )
V_14 -> V_7 |= V_8 ;
V_14 -> V_79 = 64 ;
break;
case V_80 :
if ( ( V_14 -> V_50 & 0xff ) == V_81 ) {
if ( F_21 () ) {
V_14 -> V_16 = V_18 ;
V_73 [ V_63 ] = L_3 ;
} else {
V_14 -> V_16 = V_82 ;
V_73 [ V_63 ] = L_4 ;
}
break;
} else {
V_14 -> V_16 = V_83 ;
V_73 [ V_63 ] = L_5 ;
}
V_14 -> V_74 = V_75 ;
V_14 -> V_7 = V_76 | V_77 |
V_78 ;
if ( F_29 () )
V_14 -> V_7 |= V_8 ;
V_14 -> V_79 = 64 ;
break;
case V_84 :
if ( F_37 () & V_85 ) {
if ( ( V_14 -> V_50 & 0xff ) >= V_86 ) {
V_14 -> V_16 = V_87 ;
V_73 [ V_63 ] = L_6 ;
} else {
V_14 -> V_16 = V_88 ;
V_73 [ V_63 ] = L_7 ;
}
} else {
if ( ( V_14 -> V_50 & 0xff ) >= V_86 ) {
V_14 -> V_16 = V_89 ;
V_73 [ V_63 ] = L_8 ;
} else {
V_14 -> V_16 = V_90 ;
V_73 [ V_63 ] = L_9 ;
}
}
V_14 -> V_74 = V_91 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_94 | V_95 |
V_96 ;
V_14 -> V_79 = 48 ;
break;
case V_97 :
switch ( V_14 -> V_50 & 0xf0 ) {
case V_98 :
V_14 -> V_16 = V_99 ;
V_73 [ V_63 ] = L_10 ;
break;
case V_100 :
V_14 -> V_16 = V_101 ;
V_73 [ V_63 ] = L_11 ;
break;
case V_102 :
if ( ( V_14 -> V_50 & 0xf ) < 0x3 ) {
V_14 -> V_16 = V_103 ;
V_73 [ V_63 ] = L_12 ;
} else {
V_14 -> V_16 = V_104 ;
V_73 [ V_63 ] = L_13 ;
}
break;
case V_105 :
if ( ( V_14 -> V_50 & 0xf ) < 0x4 ) {
V_14 -> V_16 = V_106 ;
V_73 [ V_63 ] = L_14 ;
} else {
V_14 -> V_16 = V_107 ;
V_73 [ V_63 ] = L_15 ;
}
break;
default:
F_15 ( V_108 L_16 ) ;
V_14 -> V_16 = V_109 ;
V_73 [ V_63 ] = L_17 ;
break;
}
V_14 -> V_74 = V_91 ;
V_14 -> V_7 = V_92 ;
V_14 -> V_79 = 32 ;
break;
case V_110 :
V_14 -> V_16 = V_111 ;
V_73 [ V_63 ] = L_18 ;
V_14 -> V_74 = V_91 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_96 ;
V_14 -> V_79 = 32 ;
break;
case V_112 :
V_14 -> V_16 = V_22 ;
V_73 [ V_63 ] = L_19 ;
V_14 -> V_74 = V_91 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_96 ;
V_14 -> V_79 = 48 ;
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
case V_113 :
V_14 -> V_74 = V_75 ;
V_14 -> V_7 = V_76 | V_114 ;
if ( ( V_14 -> V_50 & 0xf0 ) == ( V_115 & 0xf0 ) ) {
V_14 -> V_16 = V_20 ;
V_73 [ V_63 ] = L_20 ;
V_14 -> V_79 = 64 ;
} else {
switch ( V_14 -> V_50 & 0xff ) {
case V_116 :
V_14 -> V_16 = V_117 ;
V_73 [ V_63 ] = L_21 ;
V_14 -> V_79 = 32 ;
break;
case V_118 :
V_14 -> V_16 = V_119 ;
V_73 [ V_63 ] = L_22 ;
V_14 -> V_79 = 64 ;
break;
}
}
break;
case V_120 :
V_14 -> V_16 = V_25 ;
V_73 [ V_63 ] = L_23 ;
V_14 -> V_74 = V_91 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_96 ;
V_14 -> V_79 = 48 ;
break;
case V_121 :
V_14 -> V_16 = V_51 ;
V_73 [ V_63 ] = L_24 ;
V_14 -> V_74 = V_91 ;
V_14 -> V_7 = V_92 | V_96 ;
if ( ! ( V_14 -> V_50 & 0x08 ) )
V_14 -> V_7 |= V_8 | V_93 ;
V_14 -> V_79 = 48 ;
break;
case V_122 :
V_14 -> V_16 = V_26 ;
V_73 [ V_63 ] = L_25 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_96 ;
V_14 -> V_79 = 48 ;
break;
case V_124 :
V_14 -> V_16 = V_125 ;
V_73 [ V_63 ] = L_26 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_94 | V_96 ;
V_14 -> V_79 = 48 ;
break;
case V_126 :
V_14 -> V_16 = V_27 ;
V_73 [ V_63 ] = L_27 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_94 | V_96 ;
V_14 -> V_79 = 48 ;
break;
case V_127 :
V_14 -> V_16 = V_28 ;
V_73 [ V_63 ] = L_28 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_128 | V_96 ;
V_14 -> V_79 = 48 ;
break;
case V_129 :
V_14 -> V_16 = V_130 ;
V_73 [ V_63 ] = L_29 ;
V_14 -> V_74 = V_131 ;
V_14 -> V_7 = V_76 | V_8 |
V_96 ;
V_14 -> V_79 = 32 ;
break;
case V_132 :
V_14 -> V_16 = V_133 ;
V_73 [ V_63 ] = L_30 ;
V_14 -> V_74 = V_131 ;
V_14 -> V_7 = V_76 | V_8 |
V_96 ;
V_14 -> V_79 = 32 ;
break;
case V_134 :
V_14 -> V_16 = V_44 ;
V_73 [ V_63 ] = L_31 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_96 ;
V_14 -> V_79 = ( F_38 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_135 :
V_14 -> V_16 = V_54 ;
V_73 [ V_63 ] = L_32 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_92 | V_8 | V_93 |
V_96 ;
V_14 -> V_79 = ( F_38 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_136 :
V_14 -> V_16 = V_137 ;
V_73 [ V_63 ] = L_33 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_76 | V_138 |
V_8 | V_93 |
V_96 ;
V_14 -> V_79 = 384 ;
break;
case V_139 :
V_14 -> V_16 = V_140 ;
V_73 [ V_63 ] = L_34 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_76 | V_141 | V_138 |
V_8 | V_93 |
V_142 | V_94 |
V_96 ;
V_14 -> V_79 = 64 ;
break;
case V_143 :
V_14 -> V_16 = V_144 ;
V_73 [ V_63 ] = L_35 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_76 | V_141 | V_138 |
V_8 | V_93 |
V_142 | V_94 |
V_96 ;
V_14 -> V_79 = 64 ;
break;
case V_145 :
V_14 -> V_16 = V_146 ;
V_73 [ V_63 ] = L_36 ;
V_14 -> V_74 = V_123 ;
V_14 -> V_7 = V_76 | V_141 | V_138 |
V_8 | V_93 |
V_142 | V_94 |
V_96 ;
V_14 -> V_79 = 64 ;
break;
case V_147 :
V_14 -> V_16 = V_148 ;
V_73 [ V_63 ] = L_37 ;
switch ( V_14 -> V_50 & V_55 ) {
case V_149 :
F_23 ( V_63 , L_38 ) ;
break;
case V_150 :
F_23 ( V_63 , L_39 ) ;
break;
}
V_14 -> V_74 = V_91 ;
V_14 -> V_7 = V_92 |
V_8 | V_96 |
V_93 ;
V_14 -> V_79 = 64 ;
break;
}
}
static inline unsigned int F_39 ( struct V_13 * V_14 )
{
unsigned int V_151 ;
int V_152 ;
V_151 = F_37 () ;
if ( ( ( V_151 & V_153 ) >> 7 ) == 1 )
V_14 -> V_7 |= V_76 ;
V_152 = ( V_151 & V_154 ) >> 13 ;
switch ( V_152 ) {
case 0 :
switch ( ( V_151 & V_155 ) >> 10 ) {
case 0 :
V_14 -> V_74 = V_156 ;
break;
case 1 :
V_14 -> V_74 = V_157 ;
break;
default:
goto V_158;
}
break;
case 2 :
switch ( ( V_151 & V_155 ) >> 10 ) {
case 0 :
V_14 -> V_74 = V_159 ;
break;
case 1 :
V_14 -> V_74 = V_160 ;
break;
default:
goto V_158;
}
break;
default:
goto V_158;
}
return V_151 & V_161 ;
V_158:
F_40 ( V_162 , V_151 ) ;
}
static inline unsigned int F_41 ( struct V_13 * V_14 )
{
unsigned int V_163 ;
V_163 = F_42 () ;
if ( V_163 & V_164 )
V_14 -> V_10 |= V_165 ;
if ( V_163 & V_166 )
V_14 -> V_7 |= V_94 ;
if ( V_163 & V_167 )
V_14 -> V_10 |= V_168 ;
if ( V_163 & V_169 )
V_14 -> V_7 |= V_170 ;
if ( V_163 & V_171 ) {
V_14 -> V_7 |= V_8 ;
V_14 -> V_7 |= V_93 ;
}
if ( V_172 )
V_14 -> V_79 = ( ( V_163 & V_173 ) >> 25 ) + 1 ;
return V_163 & V_161 ;
}
static inline unsigned int F_43 ( struct V_13 * V_14 )
{
unsigned int V_174 ;
V_174 = F_44 () ;
if ( V_174 & V_175 )
V_14 -> V_176 . V_177 &= ~ V_178 ;
return V_174 & V_161 ;
}
static inline unsigned int F_45 ( struct V_13 * V_14 )
{
unsigned int V_179 ;
V_179 = F_46 () ;
if ( V_179 & V_180 )
V_14 -> V_10 |= V_181 ;
if ( V_179 & V_182 )
V_14 -> V_10 |= V_11 ;
if ( V_179 & V_183 )
V_14 -> V_7 |= V_184 ;
if ( V_179 & V_185 )
V_14 -> V_7 |= V_186 ;
if ( V_179 & V_187 )
V_14 -> V_10 |= V_188 ;
if ( V_179 & V_189 )
V_14 -> V_7 |= V_190 ;
return V_179 & V_161 ;
}
static inline unsigned int F_47 ( struct V_13 * V_14 )
{
unsigned int V_191 ;
V_191 = F_48 () ;
if ( ( V_191 & V_192 ) == V_193
&& V_172 )
V_14 -> V_79 += ( V_191 & V_194 ) * 0x40 ;
V_14 -> V_195 = ( V_191 >> 16 ) & 0xff ;
return V_191 & V_161 ;
}
static void T_2 F_49 ( struct V_13 * V_14 )
{
int V_196 ;
V_14 -> V_7 = V_138 | V_141 | V_142 |
V_128 | V_96 | V_197 ;
V_14 -> V_176 . V_177 = V_178 ;
V_196 = F_39 ( V_14 ) ;
F_50 ( ! V_196 ) ;
if ( V_196 )
V_196 = F_41 ( V_14 ) ;
if ( V_196 )
V_196 = F_43 ( V_14 ) ;
if ( V_196 )
V_196 = F_45 ( V_14 ) ;
if ( V_196 )
V_196 = F_47 ( V_14 ) ;
F_51 ( V_14 ) ;
if ( V_198 )
V_14 -> V_199 = F_52 () & 0x3ff ;
}
static inline void F_53 ( struct V_13 * V_14 , unsigned int V_63 )
{
F_49 ( V_14 ) ;
switch ( V_14 -> V_50 & 0xff00 ) {
case V_200 :
V_14 -> V_16 = V_29 ;
V_73 [ V_63 ] = L_40 ;
break;
case V_201 :
case V_202 :
V_14 -> V_16 = V_30 ;
V_73 [ V_63 ] = L_41 ;
break;
case V_203 :
case V_204 :
V_14 -> V_16 = V_31 ;
V_73 [ V_63 ] = L_42 ;
break;
case V_205 :
V_14 -> V_16 = V_32 ;
V_73 [ V_63 ] = L_43 ;
break;
case V_206 :
V_14 -> V_16 = V_53 ;
V_73 [ V_63 ] = L_44 ;
break;
case V_207 :
case V_208 :
V_14 -> V_16 = V_45 ;
V_73 [ V_63 ] = L_45 ;
break;
case V_209 :
V_14 -> V_16 = V_33 ;
V_73 [ V_63 ] = L_46 ;
break;
case V_210 :
V_14 -> V_16 = V_46 ;
V_73 [ V_63 ] = L_47 ;
break;
case V_211 :
V_14 -> V_16 = V_49 ;
V_73 [ V_63 ] = L_48 ;
break;
case V_212 :
V_14 -> V_16 = V_47 ;
V_73 [ V_63 ] = L_49 ;
break;
}
F_54 () ;
}
static inline void F_55 ( struct V_13 * V_14 , unsigned int V_63 )
{
F_49 ( V_14 ) ;
switch ( V_14 -> V_50 & 0xff00 ) {
case V_213 :
case V_214 :
V_14 -> V_16 = V_52 ;
switch ( ( V_14 -> V_50 >> 24 ) & 0xff ) {
case 0 :
V_73 [ V_63 ] = L_50 ;
break;
case 1 :
V_73 [ V_63 ] = L_51 ;
break;
case 2 :
V_73 [ V_63 ] = L_52 ;
break;
case 3 :
V_73 [ V_63 ] = L_53 ;
break;
case 4 :
V_73 [ V_63 ] = L_54 ;
if ( ( V_14 -> V_50 & 0xff ) == 2 )
V_73 [ V_63 ] = L_55 ;
break;
case 5 :
V_73 [ V_63 ] = L_56 ;
break;
default:
V_73 [ V_63 ] = L_57 ;
break;
}
break;
}
}
static inline void F_56 ( struct V_13 * V_14 , unsigned int V_63 )
{
F_49 ( V_14 ) ;
switch ( V_14 -> V_50 & 0xff00 ) {
case V_215 :
V_14 -> V_16 = V_216 ;
V_73 [ V_63 ] = L_58 ;
if ( ( V_14 -> V_50 & 0xff ) < 0x02 )
V_14 -> V_7 &= ~ ( V_8 | V_93 ) ;
break;
case V_217 :
V_14 -> V_16 = V_218 ;
V_73 [ V_63 ] = L_59 ;
break;
}
}
static inline void F_57 ( struct V_13 * V_14 , unsigned int V_63 )
{
F_49 ( V_14 ) ;
switch ( V_14 -> V_50 & 0xff00 ) {
case V_219 :
V_14 -> V_16 = V_220 ;
V_73 [ V_63 ] = L_60 ;
V_14 -> V_176 . V_221 = 8 ;
V_14 -> V_79 = 64 ;
break;
}
}
static inline void F_58 ( struct V_13 * V_14 , unsigned int V_63 )
{
F_49 ( V_14 ) ;
switch ( V_14 -> V_50 & 0xff00 ) {
case V_222 :
V_14 -> V_16 = V_34 ;
V_73 [ V_63 ] = L_61 ;
V_14 -> V_74 = V_156 ;
break;
}
}
static inline void F_59 ( struct V_13 * V_14 , unsigned int V_63 )
{
F_49 ( V_14 ) ;
switch ( V_14 -> V_50 & 0xff00 ) {
case V_223 :
case V_224 :
V_14 -> V_16 = V_225 ;
V_73 [ V_63 ] = L_62 ;
F_23 ( V_63 , L_63 ) ;
break;
case V_226 :
case V_227 :
case V_228 :
V_14 -> V_16 = V_35 ;
V_73 [ V_63 ] = L_64 ;
F_23 ( V_63 , L_65 ) ;
break;
case V_229 : {
int V_230 = V_14 -> V_50 & 0xff ;
if ( V_230 >= V_231 &&
V_230 <= V_232 ) {
V_14 -> V_16 = V_37 ;
V_73 [ V_63 ] = L_66 ;
F_23 ( V_63 , L_67 ) ;
} else {
V_14 -> V_16 = V_36 ;
V_73 [ V_63 ] = L_68 ;
F_23 ( V_63 , L_69 ) ;
}
break;
}
case V_233 :
V_14 -> V_16 = V_38 ;
V_73 [ V_63 ] = L_70 ;
F_23 ( V_63 , L_71 ) ;
V_14 -> V_7 |= V_190 ;
break;
}
}
static inline void F_60 ( struct V_13 * V_14 , unsigned int V_63 )
{
F_49 ( V_14 ) ;
switch ( V_14 -> V_50 & 0xff00 ) {
case V_234 :
case V_235 :
case V_236 :
V_14 -> V_16 = V_39 ;
V_73 [ V_63 ] = L_72 ;
goto V_237;
case V_238 :
case V_239 :
case V_240 :
case V_241 :
V_14 -> V_16 = V_40 ;
V_73 [ V_63 ] = L_73 ;
V_237:
F_23 ( V_63 , L_74 ) ;
break;
case V_242 :
V_14 -> V_16 = V_41 ;
V_73 [ V_63 ] = L_75 ;
F_23 ( V_63 , L_76 ) ;
break;
default:
F_15 ( V_108 L_77 ) ;
V_14 -> V_16 = V_243 ;
break;
}
}
static inline void F_61 ( struct V_13 * V_14 , unsigned int V_63 )
{
F_49 ( V_14 ) ;
V_14 -> V_7 &= ~ V_142 ;
switch ( V_14 -> V_50 & 0xff00 ) {
case V_244 :
V_14 -> V_16 = V_42 ;
V_73 [ V_63 ] = L_78 ;
break;
default:
F_40 ( L_79 ) ;
break;
}
}
static inline void F_62 ( struct V_13 * V_14 , int V_63 )
{
F_49 ( V_14 ) ;
V_14 -> V_7 = ( V_76 |
V_138 |
V_142 |
V_128 |
V_94 |
V_170 |
V_96 ) ;
switch ( V_14 -> V_50 & 0xff00 ) {
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
V_14 -> V_16 = V_253 ;
V_73 [ V_63 ] = L_80 ;
break;
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
V_14 -> V_16 = V_253 ;
V_73 [ V_63 ] = L_81 ;
break;
default:
F_15 ( V_108 L_82 ,
V_14 -> V_50 ) ;
V_14 -> V_16 = V_253 ;
break;
}
V_14 -> V_74 = V_159 ;
V_14 -> V_79 = ( ( F_42 () >> 25 ) & 0x3f ) + 1 ;
}
T_2 void F_63 ( void )
{
struct V_13 * V_14 = & V_15 ;
unsigned int V_63 = F_64 () ;
V_14 -> V_50 = V_267 ;
V_14 -> V_67 = V_69 ;
V_14 -> V_16 = V_243 ;
V_14 -> V_50 = F_65 () ;
switch ( V_14 -> V_50 & 0xff0000 ) {
case V_268 :
F_36 ( V_14 , V_63 ) ;
break;
case V_269 :
F_53 ( V_14 , V_63 ) ;
break;
case V_270 :
F_55 ( V_14 , V_63 ) ;
break;
case V_271 :
F_56 ( V_14 , V_63 ) ;
break;
case V_272 :
F_59 ( V_14 , V_63 ) ;
break;
case V_273 :
F_57 ( V_14 , V_63 ) ;
break;
case V_274 :
F_58 ( V_14 , V_63 ) ;
break;
case V_275 :
F_60 ( V_14 , V_63 ) ;
break;
case V_276 :
F_61 ( V_14 , V_63 ) ;
break;
case V_277 :
F_62 ( V_14 , V_63 ) ;
break;
}
F_50 ( ! V_73 [ V_63 ] ) ;
F_50 ( V_14 -> V_16 == V_243 ) ;
F_50 ( F_66 () != V_14 -> V_16 ) ;
if ( V_9 )
V_14 -> V_7 &= ~ V_8 ;
if ( V_12 )
V_14 -> V_10 &= ~ V_11 ;
if ( V_14 -> V_7 & V_8 ) {
V_14 -> V_67 = F_24 () ;
if ( V_14 -> V_74 == V_156 ||
V_14 -> V_74 == V_157 ||
V_14 -> V_74 == V_159 ||
V_14 -> V_74 == V_160 ) {
if ( V_14 -> V_67 & V_278 )
V_14 -> V_10 |= V_279 ;
}
}
if ( V_198 )
V_14 -> V_280 = ( ( F_67 () >> 26 ) & 0x0f ) + 1 ;
else
V_14 -> V_280 = 1 ;
F_30 ( V_14 ) ;
#ifdef F_68
if ( V_63 == 0 )
V_281 = ~ ( ( 1ull << V_282 ) - 1 ) ;
#endif
}
T_2 void F_69 ( void )
{
struct V_13 * V_14 = & V_15 ;
F_15 ( V_108 L_83 ,
V_14 -> V_50 , F_70 () ) ;
if ( V_14 -> V_7 & V_8 )
F_15 ( V_108 L_84 , V_14 -> V_67 ) ;
}
