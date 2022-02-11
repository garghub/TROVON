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
static void F_24 ( struct V_10 * V_11 , unsigned int V_33 )
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
static inline unsigned int F_25 ( struct V_10 * V_11 )
{
unsigned int V_43 ;
int V_33 ;
V_43 = F_26 () ;
if ( ( ( V_43 & V_44 ) >> 7 ) == 1 )
V_11 -> V_3 |= V_45 ;
V_33 = ( V_43 & V_46 ) >> 13 ;
switch ( V_33 ) {
case 0 :
switch ( ( V_43 & V_47 ) >> 10 ) {
case 0 :
F_24 ( V_11 , V_38 ) ;
break;
case 1 :
F_24 ( V_11 , V_36 ) ;
break;
default:
goto V_48;
}
break;
case 2 :
switch ( ( V_43 & V_47 ) >> 10 ) {
case 0 :
F_24 ( V_11 , V_37 ) ;
break;
case 1 :
F_24 ( V_11 , V_34 ) ;
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
F_27 ( V_50 , V_43 ) ;
}
static inline unsigned int F_28 ( struct V_10 * V_11 )
{
unsigned int V_51 ;
V_51 = F_29 () ;
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
static inline unsigned int F_30 ( struct V_10 * V_11 )
{
unsigned int V_65 ;
V_65 = F_31 () ;
if ( V_65 & V_66 )
V_11 -> V_67 . V_68 &= ~ V_69 ;
return V_65 & V_49 ;
}
static inline unsigned int F_32 ( struct V_10 * V_11 )
{
unsigned int V_70 ;
V_70 = F_33 () ;
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
static inline unsigned int F_34 ( struct V_10 * V_11 )
{
unsigned int V_89 ;
V_89 = F_35 () ;
if ( ( V_89 & V_90 ) == V_91
&& V_62 )
V_11 -> V_63 += ( V_89 & V_92 ) * 0x40 ;
V_11 -> V_93 = ( V_89 >> 16 ) & 0xff ;
return V_89 & V_49 ;
}
static void F_36 ( struct V_10 * V_11 )
{
int V_94 ;
V_11 -> V_3 = V_95 | V_96 | V_97 |
V_98 | V_99 | V_100 ;
V_11 -> V_67 . V_68 = V_69 ;
V_94 = F_25 ( V_11 ) ;
F_37 ( ! V_94 ) ;
if ( V_94 )
V_94 = F_28 ( V_11 ) ;
if ( V_94 )
V_94 = F_30 ( V_11 ) ;
if ( V_94 )
V_94 = F_32 ( V_11 ) ;
if ( V_94 )
V_94 = F_34 ( V_11 ) ;
F_38 ( V_11 ) ;
if ( V_101 )
V_11 -> V_102 = F_39 () & 0x3ff ;
}
static inline void F_40 ( struct V_10 * V_11 , unsigned int V_25 )
{
switch ( V_11 -> V_15 & 0xff00 ) {
case V_103 :
V_11 -> V_13 = V_104 ;
V_105 [ V_25 ] = L_1 ;
V_11 -> V_3 = V_45 | V_106 |
V_107 ;
if ( F_17 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_63 = 64 ;
break;
case V_108 :
if ( ( V_11 -> V_15 & 0xff ) == V_109 ) {
if ( F_7 () ) {
V_11 -> V_13 = V_110 ;
V_105 [ V_25 ] = L_2 ;
} else {
V_11 -> V_13 = V_111 ;
V_105 [ V_25 ] = L_3 ;
}
} else {
V_11 -> V_13 = V_112 ;
V_105 [ V_25 ] = L_4 ;
}
V_11 -> V_3 = V_45 | V_106 |
V_107 ;
if ( F_17 () )
V_11 -> V_3 |= V_4 ;
V_11 -> V_63 = 64 ;
break;
case V_113 :
if ( F_26 () & V_114 ) {
if ( ( V_11 -> V_15 & 0xff ) >= V_115 ) {
V_11 -> V_13 = V_116 ;
V_105 [ V_25 ] = L_5 ;
} else {
V_11 -> V_13 = V_117 ;
V_105 [ V_25 ] = L_6 ;
}
} else {
if ( ( V_11 -> V_15 & 0xff ) >= V_115 ) {
V_11 -> V_13 = V_118 ;
V_105 [ V_25 ] = L_7 ;
} else {
V_11 -> V_13 = V_119 ;
V_105 [ V_25 ] = L_8 ;
}
}
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_55 | V_121 |
V_99 ;
V_11 -> V_63 = 48 ;
break;
case V_122 :
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_120 ;
V_11 -> V_63 = 32 ;
switch ( V_11 -> V_15 & 0xf0 ) {
case V_123 :
V_11 -> V_13 = V_124 ;
V_105 [ V_25 ] = L_9 ;
break;
case V_125 :
V_11 -> V_13 = V_126 ;
V_105 [ V_25 ] = L_10 ;
break;
case V_127 :
if ( ( V_11 -> V_15 & 0xf ) < 0x3 ) {
V_11 -> V_13 = V_128 ;
V_105 [ V_25 ] = L_11 ;
} else {
V_11 -> V_13 = V_129 ;
V_105 [ V_25 ] = L_12 ;
}
break;
case V_130 :
if ( ( V_11 -> V_15 & 0xf ) < 0x4 ) {
V_11 -> V_13 = V_131 ;
V_105 [ V_25 ] = L_13 ;
} else {
V_11 -> V_13 = V_132 ;
V_11 -> V_3 |= V_99 ;
V_105 [ V_25 ] = L_14 ;
}
break;
default:
F_41 ( V_133 L_15 ) ;
V_11 -> V_13 = V_134 ;
V_105 [ V_25 ] = L_16 ;
break;
}
break;
case V_135 :
V_11 -> V_13 = V_136 ;
V_105 [ V_25 ] = L_17 ;
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_99 ;
V_11 -> V_63 = 32 ;
break;
case V_137 :
V_11 -> V_13 = V_138 ;
V_105 [ V_25 ] = L_18 ;
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_99 ;
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
case V_139 :
V_11 -> V_3 = V_45 | V_140 ;
if ( ( V_11 -> V_15 & 0xf0 ) == ( V_141 & 0xf0 ) ) {
V_11 -> V_13 = V_142 ;
V_105 [ V_25 ] = L_19 ;
V_11 -> V_63 = 64 ;
} else {
switch ( V_11 -> V_15 & 0xff ) {
case V_143 :
V_11 -> V_13 = V_144 ;
V_105 [ V_25 ] = L_20 ;
V_11 -> V_63 = 32 ;
break;
case V_145 :
V_11 -> V_13 = V_146 ;
V_105 [ V_25 ] = L_21 ;
V_11 -> V_63 = 64 ;
break;
}
}
break;
case V_147 :
V_11 -> V_13 = V_148 ;
V_105 [ V_25 ] = L_22 ;
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_99 ;
V_11 -> V_63 = 48 ;
break;
case V_149 :
V_11 -> V_13 = V_150 ;
V_105 [ V_25 ] = L_23 ;
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_120 | V_99 ;
if ( ! ( V_11 -> V_15 & 0x08 ) )
V_11 -> V_3 |= V_4 | V_61 ;
V_11 -> V_63 = 48 ;
break;
case V_151 :
V_11 -> V_13 = V_152 ;
V_105 [ V_25 ] = L_24 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_99 ;
V_11 -> V_63 = 48 ;
break;
case V_153 :
V_11 -> V_13 = V_154 ;
V_105 [ V_25 ] = L_25 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_55 | V_99 ;
V_11 -> V_63 = 48 ;
break;
case V_155 :
V_11 -> V_13 = V_156 ;
V_105 [ V_25 ] = L_26 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_55 | V_99 ;
V_11 -> V_63 = 48 ;
break;
case V_157 :
V_11 -> V_13 = V_158 ;
V_105 [ V_25 ] = L_27 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_98 | V_99 ;
V_11 -> V_63 = 48 ;
break;
case V_159 :
V_11 -> V_13 = V_160 ;
V_105 [ V_25 ] = L_28 ;
F_24 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_45 | V_4 |
V_99 ;
V_11 -> V_63 = 32 ;
break;
case V_161 :
V_11 -> V_13 = V_162 ;
V_105 [ V_25 ] = L_29 ;
F_24 ( V_11 , V_42 ) ;
V_11 -> V_3 = V_45 | V_4 |
V_99 ;
V_11 -> V_63 = 32 ;
break;
case V_163 :
V_11 -> V_13 = V_164 ;
V_105 [ V_25 ] = L_30 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_99 ;
V_11 -> V_63 = ( F_42 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_165 :
V_11 -> V_13 = V_166 ;
V_105 [ V_25 ] = L_31 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_120 | V_4 | V_61 |
V_99 ;
V_11 -> V_63 = ( F_42 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_167 :
V_11 -> V_13 = V_168 ;
V_105 [ V_25 ] = L_32 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_45 | V_95 |
V_4 | V_61 |
V_99 ;
V_11 -> V_63 = 384 ;
break;
case V_169 :
V_11 -> V_13 = V_170 ;
V_105 [ V_25 ] = L_33 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_45 | V_96 | V_95 |
V_4 | V_61 |
V_97 | V_55 |
V_99 ;
V_11 -> V_63 = 64 ;
break;
case V_171 :
V_11 -> V_13 = V_172 ;
V_105 [ V_25 ] = L_34 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_45 | V_96 | V_95 |
V_4 | V_61 |
V_97 | V_55 |
V_99 ;
V_11 -> V_63 = 64 ;
break;
case V_173 :
V_11 -> V_13 = V_174 ;
V_105 [ V_25 ] = L_35 ;
F_24 ( V_11 , V_40 ) ;
V_11 -> V_3 = V_45 | V_96 | V_95 |
V_4 | V_61 |
V_97 | V_55 |
V_99 ;
V_11 -> V_63 = 64 ;
break;
case V_175 :
V_11 -> V_13 = V_176 ;
V_105 [ V_25 ] = L_36 ;
switch ( V_11 -> V_15 & V_16 ) {
case V_177 :
F_11 ( V_25 , L_37 ) ;
break;
case V_178 :
F_11 ( V_25 , L_38 ) ;
break;
}
F_24 ( V_11 , V_41 ) ;
V_11 -> V_3 = V_120 |
V_4 | V_99 |
V_61 ;
V_11 -> V_63 = 64 ;
break;
case V_179 :
F_36 ( V_11 ) ;
V_11 -> V_13 = V_180 ;
switch ( V_11 -> V_15 & V_16 ) {
case V_181 :
V_105 [ V_25 ] = L_39 ;
break;
}
break;
}
}
static inline void F_43 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_36 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_182 :
V_11 -> V_13 = V_183 ;
V_105 [ V_25 ] = L_40 ;
break;
case V_184 :
case V_185 :
V_11 -> V_13 = V_186 ;
V_105 [ V_25 ] = L_41 ;
break;
case V_187 :
case V_188 :
V_11 -> V_13 = V_189 ;
V_105 [ V_25 ] = L_42 ;
break;
case V_190 :
V_11 -> V_13 = V_191 ;
V_105 [ V_25 ] = L_43 ;
break;
case V_192 :
V_11 -> V_13 = V_193 ;
V_105 [ V_25 ] = L_44 ;
break;
case V_194 :
V_11 -> V_13 = V_195 ;
V_105 [ V_25 ] = L_45 ;
break;
case V_196 :
V_11 -> V_13 = V_197 ;
V_105 [ V_25 ] = L_46 ;
break;
case V_198 :
V_11 -> V_13 = V_197 ;
V_105 [ V_25 ] = L_47 ;
break;
case V_199 :
V_11 -> V_13 = V_200 ;
V_105 [ V_25 ] = L_48 ;
break;
case V_201 :
V_11 -> V_13 = V_14 ;
V_105 [ V_25 ] = L_49 ;
break;
case V_202 :
V_11 -> V_13 = V_203 ;
V_105 [ V_25 ] = L_50 ;
break;
case V_204 :
V_11 -> V_13 = V_205 ;
V_105 [ V_25 ] = L_51 ;
break;
case V_206 :
V_11 -> V_13 = V_207 ;
V_105 [ V_25 ] = L_52 ;
break;
case V_208 :
V_11 -> V_13 = V_209 ;
V_105 [ V_25 ] = L_53 ;
break;
case V_210 :
V_11 -> V_13 = V_203 ;
V_105 [ V_25 ] = L_54 ;
break;
}
F_44 () ;
}
static inline void F_45 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_36 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_211 :
case V_212 :
V_11 -> V_13 = V_213 ;
switch ( ( V_11 -> V_15 >> 24 ) & 0xff ) {
case 0 :
V_105 [ V_25 ] = L_55 ;
break;
case 1 :
V_105 [ V_25 ] = L_56 ;
break;
case 2 :
V_105 [ V_25 ] = L_57 ;
break;
case 3 :
V_105 [ V_25 ] = L_58 ;
break;
case 4 :
V_105 [ V_25 ] = L_59 ;
if ( ( V_11 -> V_15 & 0xff ) == 2 )
V_105 [ V_25 ] = L_60 ;
break;
case 5 :
V_105 [ V_25 ] = L_61 ;
break;
default:
V_105 [ V_25 ] = L_62 ;
break;
}
break;
}
}
static inline void F_46 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_36 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_214 :
V_11 -> V_13 = V_215 ;
V_105 [ V_25 ] = L_63 ;
if ( ( V_11 -> V_15 & 0xff ) < 0x02 )
V_11 -> V_3 &= ~ ( V_4 | V_61 ) ;
break;
case V_216 :
V_11 -> V_13 = V_217 ;
V_105 [ V_25 ] = L_64 ;
break;
}
}
static inline void F_47 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_36 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_218 :
V_11 -> V_13 = V_219 ;
V_105 [ V_25 ] = L_65 ;
V_11 -> V_67 . V_220 = 8 ;
V_11 -> V_63 = 64 ;
break;
}
}
static inline void F_48 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_36 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_221 :
V_11 -> V_13 = V_222 ;
V_105 [ V_25 ] = L_66 ;
F_24 ( V_11 , V_38 ) ;
break;
}
}
static inline void F_49 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_36 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_223 :
case V_224 :
V_11 -> V_13 = V_225 ;
V_105 [ V_25 ] = L_67 ;
F_11 ( V_25 , L_68 ) ;
break;
case V_226 :
case V_227 :
case V_228 :
V_11 -> V_13 = V_229 ;
V_105 [ V_25 ] = L_69 ;
F_11 ( V_25 , L_70 ) ;
break;
case V_230 : {
int V_231 = V_11 -> V_15 & 0xff ;
if ( V_231 >= V_232 &&
V_231 <= V_233 ) {
V_11 -> V_13 = V_234 ;
V_105 [ V_25 ] = L_71 ;
F_11 ( V_25 , L_72 ) ;
} else {
V_11 -> V_13 = V_235 ;
V_105 [ V_25 ] = L_73 ;
F_11 ( V_25 , L_74 ) ;
}
break;
}
case V_236 :
V_11 -> V_13 = V_237 ;
V_105 [ V_25 ] = L_75 ;
F_11 ( V_25 , L_76 ) ;
V_11 -> V_3 |= V_84 ;
break;
}
}
static inline void F_50 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_36 ( V_11 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_238 :
case V_239 :
case V_240 :
V_11 -> V_13 = V_241 ;
V_105 [ V_25 ] = L_77 ;
goto V_242;
case V_243 :
case V_244 :
case V_245 :
case V_246 :
V_11 -> V_13 = V_247 ;
V_105 [ V_25 ] = L_78 ;
V_242:
F_11 ( V_25 , L_79 ) ;
break;
case V_248 :
case V_249 :
case V_250 :
case V_251 :
V_11 -> V_13 = V_252 ;
V_105 [ V_25 ] = L_80 ;
F_11 ( V_25 , L_81 ) ;
break;
default:
F_41 ( V_133 L_82 ) ;
V_11 -> V_13 = V_253 ;
break;
}
}
static inline void F_51 ( struct V_10 * V_11 , unsigned int V_25 )
{
F_36 ( V_11 ) ;
V_11 -> V_3 &= ~ V_97 ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_254 :
V_11 -> V_13 = V_255 ;
V_105 [ V_25 ] = L_83 ;
break;
default:
F_27 ( L_84 ) ;
break;
}
}
static inline void F_52 ( struct V_10 * V_11 , int V_25 )
{
F_36 ( V_11 ) ;
if ( ( V_11 -> V_15 & 0xff00 ) == V_256 ) {
V_11 -> V_13 = V_213 ;
V_105 [ V_25 ] = L_85 ;
return;
}
V_11 -> V_3 = ( V_45 |
V_95 |
V_97 |
V_98 |
V_55 |
V_59 |
V_99 ) ;
switch ( V_11 -> V_15 & 0xff00 ) {
case V_257 :
case V_258 :
V_11 -> V_13 = V_259 ;
V_105 [ V_25 ] = L_86 ;
break;
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
V_11 -> V_13 = V_268 ;
V_105 [ V_25 ] = L_87 ;
break;
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
case V_281 :
V_11 -> V_13 = V_268 ;
V_105 [ V_25 ] = L_88 ;
break;
default:
F_53 ( L_89 ,
V_11 -> V_15 ) ;
V_11 -> V_13 = V_268 ;
break;
}
if ( V_11 -> V_13 == V_259 ) {
F_24 ( V_11 , V_34 ) ;
V_11 -> V_3 |= ( V_4 | V_84 | V_100 ) ;
V_11 -> V_63 = ( ( F_54 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_24 ( V_11 , V_37 ) ;
V_11 -> V_63 = ( ( F_29 () >> 25 ) & 0x3f ) + 1 ;
}
V_11 -> V_93 = 0xf ;
}
void F_55 ( void )
{
struct V_10 * V_11 = & V_12 ;
unsigned int V_25 = F_56 () ;
V_11 -> V_15 = V_282 ;
V_11 -> V_29 = V_31 ;
V_11 -> V_13 = V_253 ;
V_11 -> V_15 = F_57 () ;
switch ( V_11 -> V_15 & 0xff0000 ) {
case V_283 :
F_40 ( V_11 , V_25 ) ;
break;
case V_284 :
F_43 ( V_11 , V_25 ) ;
break;
case V_285 :
F_45 ( V_11 , V_25 ) ;
break;
case V_286 :
F_46 ( V_11 , V_25 ) ;
break;
case V_287 :
F_49 ( V_11 , V_25 ) ;
break;
case V_288 :
F_47 ( V_11 , V_25 ) ;
break;
case V_289 :
F_48 ( V_11 , V_25 ) ;
break;
case V_290 :
F_50 ( V_11 , V_25 ) ;
break;
case V_291 :
F_51 ( V_11 , V_25 ) ;
break;
case V_292 :
F_52 ( V_11 , V_25 ) ;
break;
}
F_37 ( ! V_105 [ V_25 ] ) ;
F_37 ( V_11 -> V_13 == V_253 ) ;
F_37 ( F_58 () != V_11 -> V_13 ) ;
if ( V_5 )
V_11 -> V_3 &= ~ V_4 ;
if ( V_9 )
V_11 -> V_6 &= ~ ( V_7 | V_8 ) ;
if ( V_11 -> V_3 & V_4 ) {
V_11 -> V_29 = F_12 () ;
if ( V_11 -> V_35 & ( V_38 | V_36 |
V_37 | V_34 ) ) {
if ( V_11 -> V_29 & V_293 )
V_11 -> V_6 |= V_294 ;
}
}
if ( V_101 ) {
V_11 -> V_295 = ( ( F_59 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_3 |= V_296 ;
}
else
V_11 -> V_295 = 1 ;
F_18 ( V_11 ) ;
#ifdef F_60
if ( V_25 == 0 )
V_297 = ~ ( ( 1ull << V_298 ) - 1 ) ;
#endif
}
void F_61 ( void )
{
struct V_10 * V_11 = & V_12 ;
F_41 ( V_133 L_90 ,
V_11 -> V_15 , F_62 () ) ;
if ( V_11 -> V_3 & V_4 )
F_41 ( V_133 L_91 , V_11 -> V_29 ) ;
}
