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
F_15 () ;
V_28 = F_16 ( V_29 ) ;
F_17 ( V_27 ) ;
return V_28 ;
}
static inline int F_18 ( void )
{
return ( ( F_13 () & V_30 ) != V_31 ) ;
}
static inline void F_19 ( struct V_10 * V_11 )
{
#ifdef F_20
F_21 ( 0x3fffffffffffe000ULL ) ;
F_22 () ;
V_11 -> V_32 = F_23 ( F_24 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void F_25 ( struct V_10 * V_11 , unsigned int V_33 )
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
V_11 -> V_35 |= V_42 | V_41 ;
break;
case V_36 :
V_11 -> V_35 |= V_36 ;
case V_38 :
V_11 -> V_35 |= V_38 ;
case V_42 :
V_11 -> V_35 |= V_42 ;
break;
}
}
static inline unsigned int F_26 ( struct V_10 * V_11 )
{
unsigned int V_43 ;
int V_33 ;
V_43 = F_27 () ;
if ( ( ( V_43 & V_44 ) >> 7 ) == 1 )
V_11 -> V_3 |= V_45 ;
V_33 = ( V_43 & V_46 ) >> 13 ;
switch ( V_33 ) {
case 0 :
switch ( ( V_43 & V_47 ) >> 10 ) {
case 0 :
F_25 ( V_11 , V_38 ) ;
break;
case 1 :
F_25 ( V_11 , V_36 ) ;
break;
default:
goto V_48;
}
break;
case 2 :
switch ( ( V_43 & V_47 ) >> 10 ) {
case 0 :
F_25 ( V_11 , V_37 ) ;
break;
case 1 :
F_25 ( V_11 , V_34 ) ;
break;
default:
goto V_48;
}
break;
default:
goto V_48;
}
return V_43 & V_49 ;
V_48:
F_28 ( V_50 , V_43 ) ;
}
static inline unsigned int F_29 ( struct V_10 * V_11 )
{
unsigned int V_51 ;
V_51 = F_30 () ;
if ( V_51 & V_52 )
V_11 -> V_6 |= V_53 ;
if ( V_51 & V_54 )
V_11 -> V_3 |= V_55 ;
if ( V_51 & V_56 )
V_11 -> V_6 |= V_57 ;
if ( V_51 & V_58 )
V_11 -> V_3 |= V_59 ;
if ( V_51 & V_60 ) {
V_11 -> V_3 |= V_4 ;
V_11 -> V_3 |= V_61 ;
}
if ( V_62 )
V_11 -> V_63 = ( ( V_51 & V_64 ) >> 25 ) + 1 ;
return V_51 & V_49 ;
}
static inline unsigned int F_31 ( struct V_10 * V_11 )
{
unsigned int V_65 ;
V_65 = F_32 () ;
if ( V_65 & V_66 )
V_11 -> V_67 . V_68 &= ~ V_69 ;
return V_65 & V_49 ;
}
static inline unsigned int F_33 ( struct V_10 * V_11 )
{
unsigned int V_70 ;
V_70 = F_34 () ;
if ( V_70 & V_71 ) {
V_11 -> V_6 |= V_72 ;
V_11 -> V_3 |= V_73 ;
}
if ( V_70 & V_74 )
V_11 -> V_3 |= V_73 ;
if ( V_70 & V_75 )
V_11 -> V_6 |= V_7 ;
if ( V_70 & V_76 )
V_11 -> V_6 |= V_8 ;
if ( V_70 & V_77 )
V_11 -> V_3 |= V_78 ;
if ( V_70 & V_79 )
V_11 -> V_3 |= V_80 ;
if ( V_70 & V_81 )
V_11 -> V_6 |= V_82 ;
if ( V_70 & V_83 )
V_11 -> V_3 |= V_84 ;
if ( V_70 & V_85 )
V_11 -> V_3 |= V_86 ;
if ( V_70 & V_87 )
V_11 -> V_6 |= V_88 ;
return V_70 & V_49 ;
}
static inline unsigned int F_35 ( struct V_10 * V_11 )
{
unsigned int V_89 ;
V_89 = F_36 () ;
if ( ( V_89 & V_90 ) == V_91
&& V_62 )
V_11 -> V_63 += ( V_89 & V_92 ) * 0x40 ;
V_11 -> V_93 = ( V_89 >> 16 ) & 0xff ;
return V_89 & V_49 ;
}
static inline unsigned int F_37 ( struct V_10 * V_11 )
{
unsigned int V_94 ;
V_94 = F_38 () ;
V_94 &= ~ V_95 ;
F_39 ( V_94 ) ;
return V_94 & V_49 ;
}
static void F_40 ( struct V_10 * V_11 )
{
int V_96 ;
V_11 -> V_3 = V_97 | V_98 | V_99 |
V_100 | V_101 | V_102 ;
V_11 -> V_67 . V_68 = V_69 ;
V_96 = F_26 ( V_11 ) ;
F_41 ( ! V_96 ) ;
if ( V_96 )
V_96 = F_29 ( V_11 ) ;
if ( V_96 )
V_96 = F_31 ( V_11 ) ;
if ( V_96 )
V_96 = F_33 ( V_11 ) ;
if ( V_96 )
V_96 = F_35 ( V_11 ) ;
if ( V_96 )
V_96 = F_37 ( V_11 ) ;
F_42 ( V_11 ) ;
if ( V_103 )
V_11 -> V_104 = F_43 () & 0x3ff ;
}
static inline void F_44 ( struct V_10 * V_11 , unsigned int V_24 )
{
switch ( V_11 -> V_14 & V_105 ) {
case V_106 :
V_11 -> V_107 = V_108 ;
V_109 [ V_24 ] = L_1 ;
V_11 -> V_3 = V_45 | V_110 |
V_111 ;
if ( F_18 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_63 = 64 ;
break;
case V_112 :
if ( ( V_11 -> V_14 & V_15 ) == V_113 ) {
if ( F_8 () ) {
V_11 -> V_107 = V_114 ;
V_109 [ V_24 ] = L_2 ;
} else {
V_11 -> V_107 = V_115 ;
V_109 [ V_24 ] = L_3 ;
}
} else {
V_11 -> V_107 = V_116 ;
V_109 [ V_24 ] = L_4 ;
}
V_11 -> V_3 = V_45 | V_110 |
V_111 ;
if ( F_18 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_63 = 64 ;
break;
case V_117 :
if ( F_27 () & V_118 ) {
if ( ( V_11 -> V_14 & V_15 ) >=
V_119 ) {
V_11 -> V_107 = V_120 ;
V_109 [ V_24 ] = L_5 ;
} else {
V_11 -> V_107 = V_121 ;
V_109 [ V_24 ] = L_6 ;
}
} else {
if ( ( V_11 -> V_14 & V_15 ) >=
V_119 ) {
V_11 -> V_107 = V_122 ;
V_109 [ V_24 ] = L_7 ;
} else {
V_11 -> V_107 = V_123 ;
V_109 [ V_24 ] = L_8 ;
}
}
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_55 | V_125 |
V_101 ;
V_11 -> V_63 = 48 ;
break;
case V_126 :
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_124 ;
V_11 -> V_63 = 32 ;
switch ( V_11 -> V_14 & 0xf0 ) {
case V_127 :
V_11 -> V_107 = V_128 ;
V_109 [ V_24 ] = L_9 ;
break;
case V_129 :
V_11 -> V_107 = V_130 ;
V_109 [ V_24 ] = L_10 ;
break;
case V_131 :
if ( ( V_11 -> V_14 & 0xf ) < 0x3 ) {
V_11 -> V_107 = V_132 ;
V_109 [ V_24 ] = L_11 ;
} else {
V_11 -> V_107 = V_133 ;
V_109 [ V_24 ] = L_12 ;
}
break;
case V_134 :
if ( ( V_11 -> V_14 & 0xf ) < 0x4 ) {
V_11 -> V_107 = V_135 ;
V_109 [ V_24 ] = L_13 ;
} else {
V_11 -> V_107 = V_136 ;
V_11 -> V_3 |= V_101 ;
V_109 [ V_24 ] = L_14 ;
}
break;
default:
F_45 ( V_137 L_15 ) ;
V_11 -> V_107 = V_138 ;
V_109 [ V_24 ] = L_16 ;
break;
}
break;
case V_139 :
V_11 -> V_107 = V_140 ;
V_109 [ V_24 ] = L_17 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_101 ;
V_11 -> V_63 = 32 ;
break;
case V_141 :
V_11 -> V_107 = V_142 ;
V_109 [ V_24 ] = L_18 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_101 ;
V_11 -> V_63 = 48 ;
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
case V_143 :
V_11 -> V_3 = V_45 | V_144 ;
if ( ( V_11 -> V_14 & 0xf0 ) == ( V_145 & 0xf0 ) ) {
V_11 -> V_107 = V_146 ;
V_109 [ V_24 ] = L_19 ;
V_11 -> V_63 = 64 ;
} else {
switch ( V_11 -> V_14 & V_15 ) {
case V_147 :
V_11 -> V_107 = V_148 ;
V_109 [ V_24 ] = L_20 ;
V_11 -> V_63 = 32 ;
break;
case V_149 :
V_11 -> V_107 = V_150 ;
V_109 [ V_24 ] = L_21 ;
V_11 -> V_63 = 64 ;
break;
}
}
break;
case V_151 :
V_11 -> V_107 = V_152 ;
V_109 [ V_24 ] = L_22 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_101 ;
V_11 -> V_63 = 48 ;
break;
case V_153 :
V_11 -> V_107 = V_154 ;
V_109 [ V_24 ] = L_23 ;
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_124 | V_101 ;
if ( ! ( V_11 -> V_14 & 0x08 ) )
V_11 -> V_3 |= V_4 | V_61 ;
V_11 -> V_63 = 48 ;
break;
case V_155 :
V_11 -> V_107 = V_156 ;
V_109 [ V_24 ] = L_24 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_101 ;
V_11 -> V_63 = 48 ;
break;
case V_157 :
V_11 -> V_107 = V_158 ;
V_109 [ V_24 ] = L_25 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_55 | V_101 ;
V_11 -> V_63 = 48 ;
break;
case V_159 :
V_11 -> V_107 = V_160 ;
V_109 [ V_24 ] = L_26 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_55 | V_101 ;
V_11 -> V_63 = 48 ;
break;
case V_161 :
V_11 -> V_107 = V_162 ;
V_109 [ V_24 ] = L_27 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_100 | V_101 ;
V_11 -> V_63 = 48 ;
break;
case V_163 :
V_11 -> V_107 = V_164 ;
V_109 [ V_24 ] = L_28 ;
F_25 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_45 | V_4 |
V_101 ;
V_11 -> V_63 = 32 ;
break;
case V_165 :
V_11 -> V_107 = V_166 ;
V_109 [ V_24 ] = L_29 ;
F_25 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_45 | V_4 |
V_101 ;
V_11 -> V_63 = 32 ;
break;
case V_167 :
V_11 -> V_107 = V_168 ;
V_109 [ V_24 ] = L_30 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_101 ;
V_11 -> V_63 = ( F_46 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_169 :
V_11 -> V_107 = V_170 ;
V_109 [ V_24 ] = L_31 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_124 | V_4 | V_61 |
V_101 ;
V_11 -> V_63 = ( F_46 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_171 :
V_11 -> V_107 = V_172 ;
V_109 [ V_24 ] = L_32 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_45 | V_97 |
V_4 | V_61 |
V_101 ;
V_11 -> V_63 = 384 ;
break;
case V_173 :
V_11 -> V_107 = V_174 ;
V_109 [ V_24 ] = L_33 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_45 | V_98 | V_97 |
V_4 | V_61 |
V_99 | V_55 |
V_101 ;
V_11 -> V_63 = 64 ;
break;
case V_175 :
V_11 -> V_107 = V_176 ;
V_109 [ V_24 ] = L_34 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_45 | V_98 | V_97 |
V_4 | V_61 |
V_99 | V_55 |
V_101 ;
V_11 -> V_63 = 64 ;
break;
case V_177 :
V_11 -> V_107 = V_178 ;
V_109 [ V_24 ] = L_35 ;
F_25 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_45 | V_98 | V_97 |
V_4 | V_61 |
V_99 | V_55 |
V_101 ;
V_11 -> V_63 = 64 ;
break;
case V_179 :
V_11 -> V_107 = V_180 ;
V_109 [ V_24 ] = L_36 ;
switch ( V_11 -> V_14 & V_15 ) {
case V_181 :
F_12 ( V_24 , L_37 ) ;
break;
case V_182 :
F_12 ( V_24 , L_38 ) ;
break;
}
F_25 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_124 |
V_4 | V_101 |
V_61 ;
V_11 -> V_63 = 64 ;
break;
case V_183 :
F_40 ( V_11 ) ;
V_11 -> V_107 = V_184 ;
switch ( V_11 -> V_14 & V_15 ) {
case V_185 :
V_109 [ V_24 ] = L_39 ;
break;
}
break;
}
}
static inline void F_47 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_40 ( V_11 ) ;
switch ( V_11 -> V_14 & V_105 ) {
case V_186 :
V_11 -> V_107 = V_187 ;
V_109 [ V_24 ] = L_40 ;
break;
case V_188 :
case V_189 :
V_11 -> V_107 = V_190 ;
V_109 [ V_24 ] = L_41 ;
break;
case V_191 :
case V_192 :
V_11 -> V_107 = V_193 ;
V_109 [ V_24 ] = L_42 ;
break;
case V_194 :
V_11 -> V_107 = V_195 ;
V_109 [ V_24 ] = L_43 ;
break;
case V_196 :
V_11 -> V_107 = V_197 ;
V_109 [ V_24 ] = L_44 ;
break;
case V_198 :
V_11 -> V_107 = V_199 ;
V_109 [ V_24 ] = L_45 ;
break;
case V_200 :
V_11 -> V_107 = V_201 ;
V_109 [ V_24 ] = L_46 ;
break;
case V_202 :
V_11 -> V_107 = V_201 ;
V_109 [ V_24 ] = L_47 ;
break;
case V_203 :
V_11 -> V_107 = V_204 ;
V_109 [ V_24 ] = L_48 ;
break;
case V_205 :
V_11 -> V_107 = V_13 ;
V_109 [ V_24 ] = L_49 ;
break;
case V_206 :
V_11 -> V_107 = V_207 ;
V_109 [ V_24 ] = L_50 ;
break;
case V_208 :
V_11 -> V_107 = V_209 ;
V_109 [ V_24 ] = L_51 ;
break;
case V_210 :
V_11 -> V_107 = V_211 ;
V_109 [ V_24 ] = L_52 ;
break;
case V_212 :
V_11 -> V_107 = V_213 ;
V_109 [ V_24 ] = L_53 ;
break;
case V_214 :
V_11 -> V_107 = V_207 ;
V_109 [ V_24 ] = L_54 ;
break;
}
F_48 () ;
}
static inline void F_49 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_40 ( V_11 ) ;
switch ( V_11 -> V_14 & V_105 ) {
case V_215 :
case V_216 :
V_11 -> V_107 = V_217 ;
switch ( ( V_11 -> V_14 >> 24 ) & 0xff ) {
case 0 :
V_109 [ V_24 ] = L_55 ;
break;
case 1 :
V_109 [ V_24 ] = L_56 ;
break;
case 2 :
V_109 [ V_24 ] = L_57 ;
break;
case 3 :
V_109 [ V_24 ] = L_58 ;
break;
case 4 :
V_109 [ V_24 ] = L_59 ;
if ( ( V_11 -> V_14 & V_15 ) == 2 )
V_109 [ V_24 ] = L_60 ;
break;
case 5 :
V_109 [ V_24 ] = L_61 ;
break;
default:
V_109 [ V_24 ] = L_62 ;
break;
}
break;
}
}
static inline void F_50 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_40 ( V_11 ) ;
switch ( V_11 -> V_14 & V_105 ) {
case V_218 :
V_11 -> V_107 = V_219 ;
V_109 [ V_24 ] = L_63 ;
if ( ( V_11 -> V_14 & V_15 ) < 0x02 )
V_11 -> V_3 &= ~ ( V_4 | V_61 ) ;
break;
case V_220 :
V_11 -> V_107 = V_221 ;
V_109 [ V_24 ] = L_64 ;
break;
}
}
static inline void F_51 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_40 ( V_11 ) ;
switch ( V_11 -> V_14 & V_105 ) {
case V_222 :
V_11 -> V_107 = V_223 ;
V_109 [ V_24 ] = L_65 ;
V_11 -> V_67 . V_224 = 8 ;
V_11 -> V_63 = 64 ;
break;
}
}
static inline void F_52 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_40 ( V_11 ) ;
switch ( V_11 -> V_14 & V_105 ) {
case V_225 :
V_11 -> V_107 = V_226 ;
V_109 [ V_24 ] = L_66 ;
F_25 ( V_11 , V_38 ) ;
break;
}
}
static inline void F_53 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_40 ( V_11 ) ;
switch ( V_11 -> V_14 & V_105 ) {
case V_227 :
case V_228 :
V_11 -> V_107 = V_229 ;
V_109 [ V_24 ] = L_67 ;
F_12 ( V_24 , L_68 ) ;
break;
case V_230 :
case V_231 :
case V_232 :
V_11 -> V_107 = V_233 ;
V_109 [ V_24 ] = L_69 ;
F_12 ( V_24 , L_70 ) ;
break;
case V_234 : {
int V_235 = V_11 -> V_14 & V_15 ;
if ( V_235 >= V_236 &&
V_235 <= V_237 ) {
V_11 -> V_107 = V_238 ;
V_109 [ V_24 ] = L_71 ;
F_12 ( V_24 , L_72 ) ;
} else {
V_11 -> V_107 = V_239 ;
V_109 [ V_24 ] = L_73 ;
F_12 ( V_24 , L_74 ) ;
}
break;
}
case V_240 :
V_11 -> V_107 = V_241 ;
V_109 [ V_24 ] = L_75 ;
F_12 ( V_24 , L_76 ) ;
V_11 -> V_3 |= V_84 ;
break;
}
}
static inline void F_54 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_40 ( V_11 ) ;
switch ( V_11 -> V_14 & V_105 ) {
case V_242 :
case V_243 :
case V_244 :
V_11 -> V_107 = V_245 ;
V_109 [ V_24 ] = L_77 ;
goto V_246;
case V_247 :
case V_248 :
case V_249 :
case V_250 :
V_11 -> V_107 = V_251 ;
V_109 [ V_24 ] = L_78 ;
V_246:
F_12 ( V_24 , L_79 ) ;
break;
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
V_11 -> V_107 = V_257 ;
V_109 [ V_24 ] = L_80 ;
F_12 ( V_24 , L_81 ) ;
break;
case V_258 :
case V_259 :
V_11 -> V_107 = V_260 ;
V_109 [ V_24 ] = L_82 ;
F_12 ( V_24 , L_83 ) ;
break;
default:
F_45 ( V_137 L_84 ) ;
V_11 -> V_107 = V_261 ;
break;
}
}
static inline void F_55 ( struct V_10 * V_11 , unsigned int V_24 )
{
F_40 ( V_11 ) ;
V_11 -> V_3 &= ~ V_99 ;
switch ( V_11 -> V_14 & V_105 ) {
case V_262 :
V_11 -> V_107 = V_263 ;
V_109 [ V_24 ] = L_85 ;
break;
default:
F_28 ( L_86 ) ;
break;
}
}
static inline void F_56 ( struct V_10 * V_11 , int V_24 )
{
F_40 ( V_11 ) ;
if ( ( V_11 -> V_14 & V_105 ) == V_264 ) {
V_11 -> V_107 = V_217 ;
V_109 [ V_24 ] = L_87 ;
return;
}
V_11 -> V_3 = ( V_45 |
V_97 |
V_99 |
V_100 |
V_55 |
V_59 |
V_101 ) ;
switch ( V_11 -> V_14 & V_105 ) {
case V_265 :
V_11 -> V_107 = V_266 ;
V_109 [ V_24 ] = L_88 ;
break;
case V_267 :
case V_268 :
V_11 -> V_107 = V_266 ;
V_109 [ V_24 ] = L_89 ;
break;
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
V_11 -> V_107 = V_277 ;
V_109 [ V_24 ] = L_90 ;
break;
case V_278 :
case V_279 :
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
V_11 -> V_107 = V_277 ;
V_109 [ V_24 ] = L_91 ;
break;
default:
F_57 ( L_92 ,
V_11 -> V_14 ) ;
V_11 -> V_107 = V_277 ;
break;
}
if ( V_11 -> V_107 == V_266 ) {
F_25 ( V_11 , V_34 ) ;
V_11 -> V_3 |= ( V_4 | V_84 | V_102 ) ;
V_11 -> V_63 = ( ( F_58 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_25 ( V_11 , V_37 ) ;
V_11 -> V_63 = ( ( F_30 () >> 25 ) & 0x3f ) + 1 ;
}
V_11 -> V_93 = 0xf ;
}
void F_59 ( void )
{
struct V_10 * V_11 = & V_12 ;
unsigned int V_24 = F_60 () ;
V_11 -> V_14 = V_291 ;
V_11 -> V_28 = V_31 ;
V_11 -> V_107 = V_261 ;
V_11 -> V_14 = F_61 () ;
switch ( V_11 -> V_14 & V_292 ) {
case V_293 :
F_44 ( V_11 , V_24 ) ;
break;
case V_294 :
F_47 ( V_11 , V_24 ) ;
break;
case V_295 :
F_49 ( V_11 , V_24 ) ;
break;
case V_296 :
F_50 ( V_11 , V_24 ) ;
break;
case V_297 :
F_53 ( V_11 , V_24 ) ;
break;
case V_298 :
F_51 ( V_11 , V_24 ) ;
break;
case V_299 :
F_52 ( V_11 , V_24 ) ;
break;
case V_300 :
F_54 ( V_11 , V_24 ) ;
break;
case V_301 :
F_55 ( V_11 , V_24 ) ;
break;
case V_302 :
F_56 ( V_11 , V_24 ) ;
break;
}
F_41 ( ! V_109 [ V_24 ] ) ;
F_41 ( V_11 -> V_107 == V_261 ) ;
F_41 ( F_4 () != V_11 -> V_107 ) ;
if ( V_5 )
V_11 -> V_3 &= ~ V_4 ;
if ( V_9 )
V_11 -> V_6 &= ~ ( V_7 | V_8 ) ;
if ( V_11 -> V_3 & V_4 ) {
V_11 -> V_28 = F_13 () ;
if ( V_11 -> V_35 & ( V_38 | V_36 |
V_37 | V_34 ) ) {
if ( V_11 -> V_28 & V_303 )
V_11 -> V_6 |= V_304 ;
}
}
if ( V_103 ) {
V_11 -> V_305 = ( ( F_62 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_3 |= V_306 ;
}
else
V_11 -> V_305 = 1 ;
F_19 ( V_11 ) ;
#ifdef F_63
if ( V_24 == 0 )
V_307 = ~ ( ( 1ull << V_308 ) - 1 ) ;
#endif
}
void F_64 ( void )
{
struct V_10 * V_11 = & V_12 ;
F_45 ( V_137 L_93 ,
V_11 -> V_14 , F_65 () ) ;
if ( V_11 -> V_3 & V_4 )
F_45 ( V_137 L_94 , V_11 -> V_28 ) ;
}
