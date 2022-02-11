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
switch ( V_11 -> V_13 ) {
case V_14 :
if ( ( V_11 -> V_15 & V_16 ) <= V_17 )
F_4 ( F_5 () | V_18 ) ;
break;
default:
break;
}
}
void T_1 F_6 ( void )
{
F_3 () ;
}
static inline int F_7 ( void )
{
#ifdef F_8
extern unsigned long V_19 ( unsigned long ) ;
unsigned long V_20 , V_21 ;
unsigned long V_22 = F_9 () ;
V_20 = V_19 ( V_23 ) ;
F_10 ( V_22 ^ V_24 ) ;
V_21 = V_19 ( V_23 ) ;
F_10 ( V_22 ) ;
return V_20 != V_21 ;
#else
return 0 ;
#endif
}
static inline void F_11 ( int V_25 , const char * V_26 )
{
if ( V_25 == 0 )
V_27 = V_26 ;
}
static inline unsigned long F_12 ( void )
{
unsigned long V_28 , V_29 ;
V_28 = F_13 () ;
F_14 () ;
V_29 = F_15 ( V_30 ) ;
F_16 ( V_28 ) ;
return V_29 ;
}
static inline int F_17 ( void )
{
return ( ( F_12 () & 0xff00 ) != V_31 ) ;
}
static inline void F_18 ( struct V_10 * V_11 )
{
#ifdef F_19
F_20 ( 0x3fffffffffffe000ULL ) ;
F_21 () ;
V_11 -> V_32 = F_22 ( F_23 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void T_2 F_24 ( struct V_10 * V_11 , unsigned int V_33 )
{
switch ( V_33 ) {
case V_34 :
V_11 -> V_35 |= V_36 | V_34 ;
case V_37 :
V_11 -> V_35 |= V_38 | V_37 ;
case V_39 :
V_11 -> V_35 |= V_39 ;
case V_40 :
V_11 -> V_35 |= V_40 ;
case V_41 :
V_11 -> V_35 |= V_42 | V_43 |
V_41 ;
break;
case V_36 :
V_11 -> V_35 |= V_36 ;
case V_38 :
V_11 -> V_35 |= V_38 ;
case V_43 :
V_11 -> V_35 |= V_43 ;
case V_42 :
V_11 -> V_35 |= V_42 ;
break;
}
}
static inline unsigned int F_25 ( struct V_10 * V_11 )
{
unsigned int V_44 ;
int V_33 ;
V_44 = F_26 () ;
if ( ( ( V_44 & V_45 ) >> 7 ) == 1 )
V_11 -> V_3 |= V_46 ;
V_33 = ( V_44 & V_47 ) >> 13 ;
switch ( V_33 ) {
case 0 :
switch ( ( V_44 & V_48 ) >> 10 ) {
case 0 :
F_24 ( V_11 , V_38 ) ;
break;
case 1 :
F_24 ( V_11 , V_36 ) ;
break;
default:
goto V_49;
}
break;
case 2 :
switch ( ( V_44 & V_48 ) >> 10 ) {
case 0 :
F_24 ( V_11 , V_37 ) ;
break;
case 1 :
F_24 ( V_11 , V_34 ) ;
break;
default:
goto V_49;
}
break;
default:
goto V_49;
}
return V_44 & V_50 ;
V_49:
F_27 ( V_51 , V_44 ) ;
}
static inline unsigned int F_28 ( struct V_10 * V_11 )
{
unsigned int V_52 ;
V_52 = F_29 () ;
if ( V_52 & V_53 )
V_11 -> V_6 |= V_54 ;
if ( V_52 & V_55 )
V_11 -> V_3 |= V_56 ;
if ( V_52 & V_57 )
V_11 -> V_6 |= V_58 ;
if ( V_52 & V_59 )
V_11 -> V_3 |= V_60 ;
if ( V_52 & V_61 ) {
V_11 -> V_3 |= V_4 ;
V_11 -> V_3 |= V_62 ;
}
if ( V_63 )
V_11 -> V_64 = ( ( V_52 & V_65 ) >> 25 ) + 1 ;
return V_52 & V_50 ;
}
static inline unsigned int F_30 ( struct V_10 * V_11 )
{
unsigned int V_66 ;
V_66 = F_31 () ;
if ( V_66 & V_67 )
V_11 -> V_68 . V_69 &= ~ V_70 ;
return V_66 & V_50 ;
}
static inline unsigned int F_32 ( struct V_10 * V_11 )
{
unsigned int V_71 ;
V_71 = F_33 () ;
if ( V_71 & V_72 ) {
V_11 -> V_6 |= V_73 ;
V_11 -> V_3 |= V_74 ;
}
if ( V_71 & V_75 )
V_11 -> V_3 |= V_74 ;
if ( V_71 & V_76 )
V_11 -> V_6 |= V_7 ;
if ( V_71 & V_77 )
V_11 -> V_6 |= V_8 ;
if ( V_71 & V_78 )
V_11 -> V_3 |= V_79 ;
if ( V_71 & V_80 )
V_11 -> V_3 |= V_81 ;
if ( V_71 & V_82 )
V_11 -> V_6 |= V_83 ;
if ( V_71 & V_84 )
V_11 -> V_3 |= V_85 ;
if ( V_71 & V_86 )
V_11 -> V_3 |= V_87 ;
#ifdef F_34
F_35 ( F_33 () | V_88 ) ;
#endif
if ( V_71 & V_89 )
V_11 -> V_6 |= V_90 ;
return V_71 & V_50 ;
}
static inline unsigned int F_36 ( struct V_10 * V_11 )
{
unsigned int V_91 ;
V_91 = F_37 () ;
if ( ( V_91 & V_92 ) == V_93
&& V_63 )
V_11 -> V_64 += ( V_91 & V_94 ) * 0x40 ;
V_11 -> V_95 = ( V_91 >> 16 ) & 0xff ;
return V_91 & V_50 ;
}
static void T_2 F_38 ( struct V_10 * V_11 )
{
int V_96 ;
V_11 -> V_3 = V_97 | V_98 | V_99 |
V_100 | V_101 | V_102 ;
V_11 -> V_68 . V_69 = V_70 ;
V_96 = F_25 ( V_11 ) ;
F_39 ( ! V_96 ) ;
if ( V_96 )
V_96 = F_28 ( V_11 ) ;
if ( V_96 )
V_96 = F_30 ( V_11 ) ;
if ( V_96 )
V_96 = F_32 ( V_11 ) ;
if ( V_96 )
V_96 = F_36 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_103 )
V_11 -> V_104 = F_41 () & 0x3ff ;
}
static inline void F_42 ( struct V_10 * V_11 , unsigned int V_25 )
{
switch ( V_11 -> V_15 & 0xff00 ) {
case V_105 :
V_11 -> V_13 = V_106 ;
V_107 [ V_25 ] = L_1 ;
F_24 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_46 | V_108 |
V_109 ;
if ( F_17 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_64 = 64 ;
break;
case V_110 :
if ( ( V_11 -> V_15 & 0xff ) == V_111 ) {
if ( F_7 () ) {
V_11 -> V_13 = V_112 ;
V_107 [ V_25 ] = L_2 ;
} else {
V_11 -> V_13 = V_113 ;
V_107 [ V_25 ] = L_3 ;
}
} else {
V_11 -> V_13 = V_114 ;
V_107 [ V_25 ] = L_4 ;
}
F_24 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_46 | V_108 |
V_109 ;
if ( F_17 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_64 = 64 ;
break;
case V_115 :
if ( F_26 () & V_116 ) {
if ( ( V_11 -> V_15 & 0xff ) >= V_117 ) {
V_11 -> V_13 = V_118 ;
V_107 [ V_25 ] = L_5 ;
} else {
V_11 -> V_13 = V_119 ;
V_107 [ V_25 ] = L_6 ;
}
} else {
if ( ( V_11 -> V_15 & 0xff ) >= V_117 ) {
V_11 -> V_13 = V_120 ;
V_107 [ V_25 ] = L_7 ;
} else {
V_11 -> V_13 = V_121 ;
V_107 [ V_25 ] = L_8 ;
}
}
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_56 | V_123 |
V_101 ;
V_11 -> V_64 = 48 ;
break;
case V_124 :
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_122 ;
V_11 -> V_64 = 32 ;
switch ( V_11 -> V_15 & 0xf0 ) {
case V_125 :
V_11 -> V_13 = V_126 ;
V_107 [ V_25 ] = L_9 ;
break;
case V_127 :
V_11 -> V_13 = V_128 ;
V_107 [ V_25 ] = L_10 ;
break;
case V_129 :
if ( ( V_11 -> V_15 & 0xf ) < 0x3 ) {
V_11 -> V_13 = V_130 ;
V_107 [ V_25 ] = L_11 ;
} else {
V_11 -> V_13 = V_131 ;
V_107 [ V_25 ] = L_12 ;
}
break;
case V_132 :
if ( ( V_11 -> V_15 & 0xf ) < 0x4 ) {
V_11 -> V_13 = V_133 ;
V_107 [ V_25 ] = L_13 ;
} else {
V_11 -> V_13 = V_134 ;
V_11 -> V_3 |= V_101 ;
V_107 [ V_25 ] = L_14 ;
}
break;
default:
F_43 ( V_135 L_15 ) ;
V_11 -> V_13 = V_136 ;
V_107 [ V_25 ] = L_16 ;
break;
}
break;
case V_137 :
V_11 -> V_13 = V_138 ;
V_107 [ V_25 ] = L_17 ;
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_101 ;
V_11 -> V_64 = 32 ;
break;
case V_139 :
V_11 -> V_13 = V_140 ;
V_107 [ V_25 ] = L_18 ;
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_101 ;
V_11 -> V_64 = 48 ;
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
case V_141 :
F_24 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_46 | V_142 ;
if ( ( V_11 -> V_15 & 0xf0 ) == ( V_143 & 0xf0 ) ) {
V_11 -> V_13 = V_144 ;
V_107 [ V_25 ] = L_19 ;
V_11 -> V_64 = 64 ;
} else {
switch ( V_11 -> V_15 & 0xff ) {
case V_145 :
V_11 -> V_13 = V_146 ;
V_107 [ V_25 ] = L_20 ;
V_11 -> V_64 = 32 ;
break;
case V_147 :
V_11 -> V_13 = V_148 ;
V_107 [ V_25 ] = L_21 ;
V_11 -> V_64 = 64 ;
break;
}
}
break;
case V_149 :
V_11 -> V_13 = V_150 ;
V_107 [ V_25 ] = L_22 ;
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_101 ;
V_11 -> V_64 = 48 ;
break;
case V_151 :
V_11 -> V_13 = V_152 ;
V_107 [ V_25 ] = L_23 ;
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_122 | V_101 ;
if ( ! ( V_11 -> V_15 & 0x08 ) )
V_11 -> V_3 |= V_4 | V_62 ;
V_11 -> V_64 = 48 ;
break;
case V_153 :
V_11 -> V_13 = V_154 ;
V_107 [ V_25 ] = L_24 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_101 ;
V_11 -> V_64 = 48 ;
break;
case V_155 :
V_11 -> V_13 = V_156 ;
V_107 [ V_25 ] = L_25 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_56 | V_101 ;
V_11 -> V_64 = 48 ;
break;
case V_157 :
V_11 -> V_13 = V_158 ;
V_107 [ V_25 ] = L_26 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_56 | V_101 ;
V_11 -> V_64 = 48 ;
break;
case V_159 :
V_11 -> V_13 = V_160 ;
V_107 [ V_25 ] = L_27 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_100 | V_101 ;
V_11 -> V_64 = 48 ;
break;
case V_161 :
V_11 -> V_13 = V_162 ;
V_107 [ V_25 ] = L_28 ;
F_24 ( V_11 , V_43 ) ;
V_11 -> V_3 = V_46 | V_4 |
V_101 ;
V_11 -> V_64 = 32 ;
break;
case V_163 :
V_11 -> V_13 = V_164 ;
V_107 [ V_25 ] = L_29 ;
F_24 ( V_11 , V_43 ) ;
V_11 -> V_3 = V_46 | V_4 |
V_101 ;
V_11 -> V_64 = 32 ;
break;
case V_165 :
V_11 -> V_13 = V_166 ;
V_107 [ V_25 ] = L_30 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_101 ;
V_11 -> V_64 = ( F_44 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_167 :
V_11 -> V_13 = V_168 ;
V_107 [ V_25 ] = L_31 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_122 | V_4 | V_62 |
V_101 ;
V_11 -> V_64 = ( F_44 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_169 :
V_11 -> V_13 = V_170 ;
V_107 [ V_25 ] = L_32 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_46 | V_97 |
V_4 | V_62 |
V_101 ;
V_11 -> V_64 = 384 ;
break;
case V_171 :
V_11 -> V_13 = V_172 ;
V_107 [ V_25 ] = L_33 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_46 | V_98 | V_97 |
V_4 | V_62 |
V_99 | V_56 |
V_101 ;
V_11 -> V_64 = 64 ;
break;
case V_173 :
V_11 -> V_13 = V_174 ;
V_107 [ V_25 ] = L_34 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_46 | V_98 | V_97 |
V_4 | V_62 |
V_99 | V_56 |
V_101 ;
V_11 -> V_64 = 64 ;
break;
case V_175 :
V_11 -> V_13 = V_176 ;
V_107 [ V_25 ] = L_35 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_46 | V_98 | V_97 |
V_4 | V_62 |
V_99 | V_56 |
V_101 ;
V_11 -> V_64 = 64 ;
break;
case V_177 :
V_11 -> V_13 = V_178 ;
V_107 [ V_25 ] = L_36 ;
switch ( V_11 -> V_15 & V_16 ) {
case V_179 :
F_11 ( V_25 , L_37 ) ;
break;
case V_180 :
F_11 ( V_25 , L_38 ) ;
break;
}
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_122 |
V_4 | V_101 |
V_62 ;
V_11 -> V_64 = 64 ;
break;
case V_181 :
F_38 ( V_11 ) ;
V_11 -> V_13 = V_182 ;
switch ( V_11 -> V_15 & V_16 ) {
case V_183 :
V_107 [ V_25 ] = L_39 ;
break;
}
break;
}
}
static inline void F_45 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_38 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_184 :
V_11 -> V_13 = V_185 ;
V_107 [ V_25 ] = L_40 ;
break;
case V_186 :
case V_187 :
V_11 -> V_13 = V_188 ;
V_107 [ V_25 ] = L_41 ;
break;
case V_189 :
case V_190 :
V_11 -> V_13 = V_191 ;
V_107 [ V_25 ] = L_42 ;
break;
case V_192 :
V_11 -> V_13 = V_193 ;
V_107 [ V_25 ] = L_43 ;
break;
case V_194 :
V_11 -> V_13 = V_195 ;
V_107 [ V_25 ] = L_44 ;
break;
case V_196 :
V_11 -> V_13 = V_197 ;
V_107 [ V_25 ] = L_45 ;
break;
case V_198 :
V_11 -> V_13 = V_199 ;
V_107 [ V_25 ] = L_46 ;
break;
case V_200 :
V_11 -> V_13 = V_199 ;
V_107 [ V_25 ] = L_47 ;
break;
case V_201 :
V_11 -> V_13 = V_202 ;
V_107 [ V_25 ] = L_48 ;
break;
case V_203 :
V_11 -> V_13 = V_14 ;
V_107 [ V_25 ] = L_49 ;
break;
case V_204 :
V_11 -> V_13 = V_205 ;
V_107 [ V_25 ] = L_50 ;
break;
case V_206 :
V_11 -> V_13 = V_207 ;
V_107 [ V_25 ] = L_51 ;
break;
case V_208 :
V_11 -> V_13 = V_209 ;
V_107 [ V_25 ] = L_52 ;
break;
case V_210 :
V_11 -> V_13 = V_211 ;
V_107 [ V_25 ] = L_53 ;
break;
case V_212 :
V_11 -> V_13 = V_205 ;
V_107 [ V_25 ] = L_54 ;
break;
}
F_46 () ;
}
static inline void F_47 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_38 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_213 :
case V_214 :
V_11 -> V_13 = V_215 ;
switch ( ( V_11 -> V_15 >> 24 ) & 0xff ) {
case 0 :
V_107 [ V_25 ] = L_55 ;
break;
case 1 :
V_107 [ V_25 ] = L_56 ;
break;
case 2 :
V_107 [ V_25 ] = L_57 ;
break;
case 3 :
V_107 [ V_25 ] = L_58 ;
break;
case 4 :
V_107 [ V_25 ] = L_59 ;
if ( ( V_11 -> V_15 & 0xff ) == 2 )
V_107 [ V_25 ] = L_60 ;
break;
case 5 :
V_107 [ V_25 ] = L_61 ;
break;
default:
V_107 [ V_25 ] = L_62 ;
break;
}
break;
}
}
static inline void F_48 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_38 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_216 :
V_11 -> V_13 = V_217 ;
V_107 [ V_25 ] = L_63 ;
if ( ( V_11 -> V_15 & 0xff ) < 0x02 )
V_11 -> V_3 &= ~ ( V_4 | V_62 ) ;
break;
case V_218 :
V_11 -> V_13 = V_219 ;
V_107 [ V_25 ] = L_64 ;
break;
}
}
static inline void F_49 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_38 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_220 :
V_11 -> V_13 = V_221 ;
V_107 [ V_25 ] = L_65 ;
V_11 -> V_68 . V_222 = 8 ;
V_11 -> V_64 = 64 ;
break;
}
}
static inline void F_50 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_38 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_223 :
V_11 -> V_13 = V_224 ;
V_107 [ V_25 ] = L_66 ;
F_24 ( V_11 , V_38 ) ;
break;
}
}
static inline void F_51 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_38 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_225 :
case V_226 :
V_11 -> V_13 = V_227 ;
V_107 [ V_25 ] = L_67 ;
F_11 ( V_25 , L_68 ) ;
break;
case V_228 :
case V_229 :
case V_230 :
V_11 -> V_13 = V_231 ;
V_107 [ V_25 ] = L_69 ;
F_11 ( V_25 , L_70 ) ;
break;
case V_232 : {
int V_233 = V_11 -> V_15 & 0xff ;
if ( V_233 >= V_234 &&
V_233 <= V_235 ) {
V_11 -> V_13 = V_236 ;
V_107 [ V_25 ] = L_71 ;
F_11 ( V_25 , L_72 ) ;
} else {
V_11 -> V_13 = V_237 ;
V_107 [ V_25 ] = L_73 ;
F_11 ( V_25 , L_74 ) ;
}
break;
}
case V_238 :
V_11 -> V_13 = V_239 ;
V_107 [ V_25 ] = L_75 ;
F_11 ( V_25 , L_76 ) ;
V_11 -> V_3 |= V_85 ;
break;
}
}
static inline void F_52 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_38 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_240 :
case V_241 :
case V_242 :
V_11 -> V_13 = V_243 ;
V_107 [ V_25 ] = L_77 ;
goto V_244;
case V_245 :
case V_246 :
case V_247 :
case V_248 :
V_11 -> V_13 = V_249 ;
V_107 [ V_25 ] = L_78 ;
V_244:
F_11 ( V_25 , L_79 ) ;
break;
case V_250 :
case V_251 :
case V_252 :
case V_253 :
V_11 -> V_13 = V_254 ;
V_107 [ V_25 ] = L_80 ;
F_11 ( V_25 , L_81 ) ;
break;
default:
F_43 ( V_135 L_82 ) ;
V_11 -> V_13 = V_255 ;
break;
}
}
static inline void F_53 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_38 ( V_11 ) ;
V_11 -> V_3 &= ~ V_99 ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_256 :
V_11 -> V_13 = V_257 ;
V_107 [ V_25 ] = L_83 ;
break;
default:
F_27 ( L_84 ) ;
break;
}
}
static inline void F_54 ( struct V_10 * V_11 , int V_25 )
{
F_38 ( V_11 ) ;
if ( ( V_11 -> V_15 & 0xff00 ) == V_258 ) {
V_11 -> V_13 = V_215 ;
V_107 [ V_25 ] = L_85 ;
return;
}
V_11 -> V_3 = ( V_46 |
V_97 |
V_99 |
V_100 |
V_56 |
V_60 |
V_101 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_259 :
case V_260 :
V_11 -> V_13 = V_261 ;
V_107 [ V_25 ] = L_86 ;
break;
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
V_11 -> V_13 = V_270 ;
V_107 [ V_25 ] = L_87 ;
break;
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
case V_281 :
case V_282 :
case V_283 :
V_11 -> V_13 = V_270 ;
V_107 [ V_25 ] = L_88 ;
break;
default:
F_55 ( L_89 ,
V_11 -> V_15 ) ;
V_11 -> V_13 = V_270 ;
break;
}
if ( V_11 -> V_13 == V_261 ) {
F_24 ( V_11 , V_34 ) ;
V_11 -> V_3 |= ( V_4 | V_85 | V_102 ) ;
V_11 -> V_64 = ( ( F_56 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_24 ( V_11 , V_37 ) ;
V_11 -> V_64 = ( ( F_29 () >> 25 ) & 0x3f ) + 1 ;
}
}
T_2 void F_57 ( void )
{
struct V_10 * V_11 = & V_12 ;
unsigned int V_25 = F_58 () ;
V_11 -> V_15 = V_284 ;
V_11 -> V_29 = V_31 ;
V_11 -> V_13 = V_255 ;
V_11 -> V_15 = F_59 () ;
switch ( V_11 -> V_15 & 0xff0000 ) {
case V_285 :
F_42 ( V_11 , V_25 ) ;
break;
case V_286 :
F_45 ( V_11 , V_25 ) ;
break;
case V_287 :
F_47 ( V_11 , V_25 ) ;
break;
case V_288 :
F_48 ( V_11 , V_25 ) ;
break;
case V_289 :
F_51 ( V_11 , V_25 ) ;
break;
case V_290 :
F_49 ( V_11 , V_25 ) ;
break;
case V_291 :
F_50 ( V_11 , V_25 ) ;
break;
case V_292 :
F_52 ( V_11 , V_25 ) ;
break;
case V_293 :
F_53 ( V_11 , V_25 ) ;
break;
case V_294 :
F_54 ( V_11 , V_25 ) ;
break;
}
F_39 ( ! V_107 [ V_25 ] ) ;
F_39 ( V_11 -> V_13 == V_255 ) ;
F_39 ( F_60 () != V_11 -> V_13 ) ;
if ( V_5 )
V_11 -> V_3 &= ~ V_4 ;
if ( V_9 )
V_11 -> V_6 &= ~ ( V_7 | V_8 ) ;
if ( V_11 -> V_3 & V_4 ) {
V_11 -> V_29 = F_12 () ;
if ( V_11 -> V_35 & ( V_38 | V_36 |
V_37 | V_34 ) ) {
if ( V_11 -> V_29 & V_295 )
V_11 -> V_6 |= V_296 ;
}
}
if ( V_103 ) {
V_11 -> V_297 = ( ( F_61 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_3 |= V_298 ;
}
else
V_11 -> V_297 = 1 ;
F_18 ( V_11 ) ;
#ifdef F_62
if ( V_25 == 0 )
V_299 = ~ ( ( 1ull << V_300 ) - 1 ) ;
#endif
}
T_2 void F_63 ( void )
{
struct V_10 * V_11 = & V_12 ;
F_43 ( V_135 L_90 ,
V_11 -> V_15 , F_64 () ) ;
if ( V_11 -> V_3 & V_4 )
F_43 ( V_135 L_91 , V_11 -> V_29 ) ;
}
