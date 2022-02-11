static inline unsigned long F_1 ( void )
{
unsigned long V_1 , V_2 ;
V_1 = F_2 () ;
F_3 ( V_3 ) ;
V_2 = F_4 ( V_4 ) ;
F_5 ( V_1 ) ;
return V_2 ;
}
static inline int F_6 ( void )
{
return ( F_1 () & V_5 ) != V_6 ;
}
static inline unsigned long F_7 ( void )
{
unsigned long V_7 , V_8 ;
V_7 = F_2 () ;
F_3 ( V_9 ) ;
F_8 () ;
V_8 = F_9 () ;
F_10 () ;
F_5 ( V_7 ) ;
return V_8 ;
}
static inline void F_11 ( struct V_10 * V_11 )
{
unsigned long V_12 , V_13 , V_14 , V_15 , V_16 ;
V_14 = V_11 -> V_17 ;
V_13 = V_18 | V_19 | V_20 | V_21 ;
V_12 = F_2 () ;
F_3 ( V_3 ) ;
V_15 = V_14 & V_13 ;
F_12 ( V_22 , V_15 ) ;
V_15 = F_4 ( V_22 ) ;
V_16 = V_14 | ~ V_13 ;
F_12 ( V_22 , V_16 ) ;
V_16 = F_4 ( V_22 ) ;
F_12 ( V_22 , V_14 ) ;
F_5 ( V_12 ) ;
V_11 -> V_23 = ~ ( V_15 ^ V_16 ) & ~ V_13 ;
}
static void F_13 ( struct V_10 * V_11 )
{
if ( V_11 -> V_24 & ( V_25 | V_26 |
V_27 | V_28 |
V_29 | V_30 ) ) {
unsigned long V_12 , V_31 , V_14 , V_15 , V_16 ;
V_12 = F_2 () ;
F_3 ( V_3 ) ;
V_31 = F_4 ( V_4 ) ;
if ( V_31 & V_32 ) {
V_14 = F_4 ( V_22 ) ;
V_15 = V_14 & ~ ( V_33 | V_34 ) ;
F_12 ( V_22 , V_15 ) ;
V_15 = F_4 ( V_22 ) ;
V_16 = V_14 | V_33 | V_34 ;
F_12 ( V_22 , V_16 ) ;
V_16 = F_4 ( V_22 ) ;
F_12 ( V_22 , V_14 ) ;
if ( ! ( V_15 & V_34 ) )
V_11 -> V_35 |= V_36 ;
if ( V_16 & V_34 )
V_11 -> V_35 |= V_37 ;
if ( ( V_15 ^ V_16 ) & V_33 )
V_11 -> V_23 &= ~ V_33 ;
else
V_11 -> V_17 |= V_14 & V_33 ;
if ( ( V_15 ^ V_16 ) & V_34 )
V_11 -> V_23 &= ~ V_34 ;
else
V_11 -> V_17 |= V_14 & V_34 ;
} else {
V_11 -> V_35 |= V_36 ;
}
F_5 ( V_12 ) ;
} else {
V_11 -> V_35 |= V_36 ;
}
}
static void F_14 ( struct V_10 * V_11 )
{
V_11 -> V_35 &= ~ ( V_37 | V_36 ) ;
V_11 -> V_17 &= ~ ( V_33 | V_34 ) ;
V_11 -> V_23 &= ~ ( V_33 | V_34 ) ;
switch ( V_38 ) {
case V_39 :
if ( V_11 -> V_24 & ( V_25 | V_26 |
V_27 | V_28 |
V_29 | V_30 ) ) {
V_11 -> V_35 |= V_37 | V_36 ;
} else {
V_11 -> V_35 |= V_36 ;
V_11 -> V_23 |= V_33 | V_34 ;
}
break;
case V_40 :
V_11 -> V_35 |= V_36 ;
V_11 -> V_23 |= V_33 | V_34 ;
break;
case V_41 :
V_11 -> V_35 |= V_37 ;
V_11 -> V_17 |= V_33 | V_34 ;
V_11 -> V_23 |= V_33 | V_34 ;
break;
case V_42 :
V_11 -> V_35 |= V_37 | V_36 ;
break;
}
}
static void F_15 ( struct V_10 * V_11 )
{
switch ( V_38 ) {
case V_39 :
V_43 = ! ! V_44 ;
V_45 = ! ! V_46 ;
break;
case V_40 :
V_43 = ! ! V_44 ;
V_45 = ! V_44 ;
break;
case V_41 :
V_43 = ! V_46 ;
V_45 = ! ! V_46 ;
break;
case V_42 :
V_43 = true ;
V_45 = true ;
break;
}
}
static int T_1 F_16 ( char * V_47 )
{
if ( ! V_47 )
return - 1 ;
else if ( ! strcmp ( V_47 , L_1 ) )
V_38 = V_39 ;
else if ( ! strcmp ( V_47 , L_2 ) )
V_38 = V_40 ;
else if ( ! strcmp ( V_47 , L_3 ) )
V_38 = V_41 ;
else if ( ! strcmp ( V_47 , L_4 ) )
V_38 = V_42 ;
else
return - 1 ;
if ( ! ( V_48 . V_35 & V_49 ) )
F_14 ( & V_48 ) ;
F_15 ( & V_48 ) ;
return 0 ;
}
static void F_17 ( struct V_10 * V_11 )
{
T_2 V_50 ;
V_50 = 0 ;
if ( V_11 -> V_24 & ( V_25 | V_26 |
V_27 | V_28 |
V_29 | V_30 ) )
V_50 |= V_51 | V_52 ;
if ( V_11 -> V_24 & ( V_27 | V_28 |
V_29 | V_30 ) )
V_50 |= V_53 | V_54 | V_55 ;
if ( V_11 -> V_35 & V_37 )
V_50 |= V_32 ;
V_11 -> V_2 = V_50 ;
}
static void F_18 ( struct V_10 * V_11 )
{
V_11 -> V_2 = F_1 () ;
V_56 = V_11 -> V_23 ;
if ( V_11 -> V_24 & ( V_25 | V_26 |
V_27 | V_28 |
V_29 | V_30 ) ) {
if ( V_11 -> V_2 & V_57 )
V_11 -> V_58 |= V_59 ;
if ( V_11 -> V_2 & V_60 )
V_11 -> V_35 |= V_61 ;
}
F_11 ( V_11 ) ;
F_13 ( V_11 ) ;
F_15 ( V_11 ) ;
}
static void F_19 ( struct V_10 * V_11 )
{
V_11 -> V_35 &= ~ V_49 ;
V_11 -> V_23 = V_56 ;
F_14 ( V_11 ) ;
F_15 ( V_11 ) ;
F_17 ( V_11 ) ;
}
static int T_1 F_20 ( char * V_47 )
{
F_19 ( & V_48 ) ;
V_62 = 1 ;
return 1 ;
}
static int T_1 F_21 ( char * V_47 )
{
V_63 [ 0 ] . V_58 &= ~ ( V_64 | V_65 ) ;
V_66 = 1 ;
return 1 ;
}
static int T_1 F_22 ( char * V_47 )
{
V_67 = 1 ;
V_63 [ 0 ] . V_35 &= ~ V_68 ;
F_23 ( F_24 () &
~ ( 1 << V_69 ) ) ;
return 1 ;
}
static int T_1 F_25 ( char * V_47 )
{
unsigned int V_70 , V_71 ;
if ( ! V_72 )
return 1 ;
if ( F_26 ( & V_63 [ 0 ] , 0 ) ) {
F_27 ( L_5 ) ;
return 1 ;
}
F_28 () ;
V_70 = F_29 () ;
V_71 = V_70 & V_73 ;
if ( V_71 == V_74 ) {
F_27 ( L_6 ) ;
return 1 ;
}
V_75 = 1 ;
V_72 = 0 ;
F_30 ( L_7 ) ;
V_63 [ 0 ] . V_76 -= V_63 [ 0 ] . V_77 *
V_63 [ 0 ] . V_78 ;
V_63 [ 0 ] . V_78 = 0 ;
V_63 [ 0 ] . V_77 = 0 ;
return 1 ;
}
static inline void F_31 ( void )
{
struct V_10 * V_11 = & V_79 ;
switch ( F_32 () ) {
case V_80 :
if ( ( V_11 -> V_81 & V_82 ) <= V_83 )
F_33 ( F_34 () | V_84 ) ;
break;
default:
break;
}
}
void T_1 F_35 ( void )
{
F_31 () ;
}
static inline int F_36 ( void )
{
#ifdef F_37
extern unsigned long V_85 ( unsigned long ) ;
unsigned long V_86 , V_87 ;
unsigned long V_88 = F_38 () ;
V_86 = V_85 ( V_89 ) ;
F_39 ( V_88 ^ V_90 ) ;
V_87 = V_85 ( V_89 ) ;
F_39 ( V_88 ) ;
return V_86 != V_87 ;
#else
return 0 ;
#endif
}
static inline void F_40 ( int V_91 , const char * V_92 )
{
if ( V_91 == 0 )
V_93 = V_92 ;
}
static inline void F_41 ( struct V_10 * V_11 )
{
#ifdef F_42
F_43 ( 0x3fffffffffffe000ULL ) ;
F_28 () ;
V_11 -> V_94 = F_44 ( F_45 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void F_46 ( struct V_10 * V_11 , unsigned int V_95 )
{
switch ( V_95 ) {
case V_28 :
V_11 -> V_24 |= V_27 | V_28 ;
case V_26 :
V_11 -> V_24 |= V_25 | V_26 ;
case V_96 :
V_11 -> V_24 |= V_96 ;
case V_97 :
V_11 -> V_24 |= V_97 ;
case V_98 :
V_11 -> V_24 |= V_99 | V_98 ;
break;
case V_30 :
V_11 -> V_24 |= V_29 | V_30 ;
case V_29 :
V_11 -> V_24 |= V_29 ;
break;
case V_27 :
V_11 -> V_24 |= V_27 ;
case V_25 :
V_11 -> V_24 |= V_25 ;
case V_99 :
V_11 -> V_24 |= V_99 ;
break;
}
}
static unsigned int F_47 ( struct V_10 * V_11 )
{
unsigned int V_100 = V_11 -> V_76 / V_11 -> V_101 ;
if ( V_100 >= 12 )
return 1 ;
else if ( V_100 >= 6 )
return 2 ;
else
return 3 ;
}
static int F_26 ( struct V_10 * V_11 , int V_102 )
{
unsigned int V_103 ;
switch ( V_11 -> V_104 ) {
case V_105 :
case V_106 :
V_103 = F_48 () ;
V_103 &= ~ ( 3 << V_107 ) ;
if ( V_102 )
F_49 ( V_103 |
( F_47 ( V_11 )
<< V_107 )
| V_108 ) ;
else
F_49 ( V_103 & ~ V_108 ) ;
break;
case V_109 :
V_103 = F_34 () ;
V_103 &= ~ ( 3 << V_110 ) ;
F_33 ( V_103 | ( F_47 ( V_11 )
<< V_110 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static inline unsigned int F_50 ( struct V_10 * V_11 )
{
unsigned int V_111 ;
int V_95 , V_112 ;
V_111 = F_51 () ;
V_112 = V_111 & V_113 ;
if ( V_112 == V_114 )
V_11 -> V_35 |= V_115 ;
else if ( V_112 == V_116 )
V_11 -> V_35 |= V_115 | V_117 ;
V_95 = ( V_111 & V_118 ) >> 13 ;
switch ( V_95 ) {
case 0 :
switch ( ( V_111 & V_119 ) >> 10 ) {
case 0 :
F_46 ( V_11 , V_25 ) ;
break;
case 1 :
F_46 ( V_11 , V_27 ) ;
break;
case 2 :
F_46 ( V_11 , V_29 ) ;
break;
default:
goto V_120;
}
break;
case 2 :
switch ( ( V_111 & V_119 ) >> 10 ) {
case 0 :
F_46 ( V_11 , V_26 ) ;
break;
case 1 :
F_46 ( V_11 , V_28 ) ;
break;
case 2 :
F_46 ( V_11 , V_30 ) ;
break;
default:
goto V_120;
}
break;
default:
goto V_120;
}
return V_111 & V_121 ;
V_120:
F_52 ( V_122 , V_111 ) ;
}
static inline unsigned int F_53 ( struct V_10 * V_11 )
{
unsigned int V_123 ;
V_123 = F_54 () ;
if ( V_123 & V_124 )
V_11 -> V_58 |= V_125 ;
if ( V_123 & V_126 )
V_11 -> V_35 |= V_127 ;
if ( V_123 & V_128 )
V_11 -> V_58 |= V_129 ;
if ( V_123 & V_130 )
V_11 -> V_35 |= V_131 ;
if ( V_123 & V_132 ) {
V_11 -> V_35 |= V_49 ;
V_11 -> V_35 |= V_133 ;
}
if ( V_134 ) {
V_11 -> V_76 = ( ( V_123 & V_135 ) >> 25 ) + 1 ;
V_11 -> V_101 = V_11 -> V_76 ;
V_11 -> V_78 = 0 ;
}
return V_123 & V_121 ;
}
static inline unsigned int F_55 ( struct V_10 * V_11 )
{
unsigned int V_136 ;
V_136 = F_56 () ;
if ( V_136 & V_137 )
V_11 -> V_138 . V_139 &= ~ V_140 ;
return V_136 & V_121 ;
}
static inline unsigned int F_57 ( struct V_10 * V_11 )
{
unsigned int V_141 ;
V_141 = F_58 () ;
if ( V_141 & V_142 ) {
V_11 -> V_58 |= V_143 ;
V_11 -> V_35 |= V_144 ;
}
if ( V_141 & V_145 )
V_11 -> V_35 |= V_144 ;
if ( V_141 & V_146 )
V_11 -> V_58 |= V_64 ;
if ( V_141 & V_147 )
V_11 -> V_58 |= V_65 ;
if ( V_141 & V_148 )
V_11 -> V_35 |= V_149 ;
if ( V_141 & V_150 )
V_11 -> V_35 |= V_151 ;
if ( V_141 & V_152 )
V_11 -> V_58 |= V_153 ;
if ( V_141 & V_154 )
V_11 -> V_35 |= V_155 ;
if ( V_141 & V_156 )
V_11 -> V_35 |= V_157 ;
if ( V_141 & V_158 )
V_11 -> V_58 |= V_159 ;
if ( V_141 & V_160 )
V_11 -> V_35 |= V_161 ;
if ( V_141 & V_162 )
V_11 -> V_58 |= V_163 ;
if ( V_141 & V_164 ) {
V_11 -> V_165 = 0 ;
V_11 -> V_35 |= V_68 ;
}
if ( V_141 & V_166 )
V_11 -> V_35 |= V_167 ;
if ( V_141 & V_168 )
V_11 -> V_35 |= V_169 ;
return V_141 & V_121 ;
}
static inline unsigned int F_59 ( struct V_10 * V_11 )
{
unsigned int V_70 ;
unsigned int V_170 ;
unsigned int V_71 ;
unsigned int V_171 = V_172 ;
V_70 = F_29 () ;
if ( V_134 ) {
if ( ( ( V_70 & V_173 ) >> 29 ) == 2 )
V_11 -> V_35 |= V_174 ;
if ( ! V_175 )
V_71 = V_70 & V_73 ;
else if ( V_176 )
V_71 = V_177 ;
else
V_71 = 0 ;
switch ( V_71 ) {
case V_178 :
V_11 -> V_76 += ( V_70 & V_179 ) * 0x40 ;
V_11 -> V_101 = V_11 -> V_76 ;
break;
case V_177 :
V_11 -> V_101 +=
( ( V_70 & V_180 ) >>
V_181 ) * 0x40 ;
V_11 -> V_76 = V_11 -> V_101 ;
V_171 = V_182 ;
case V_74 :
if ( V_75 )
break;
V_170 = ( V_70 & ~ V_171 ) |
( F_60 ( V_71 ) <<
V_183 ) ;
F_61 ( V_170 ) ;
F_28 () ;
V_70 = F_29 () ;
if ( V_70 != V_170 ) {
F_62 ( L_8 ,
V_184 , V_70 ) ;
F_26 ( V_11 , 0 ) ;
break;
}
V_11 -> V_78 = 1 <<
( ( V_70 & V_185 ) >>
V_186 ) ;
V_11 -> V_77 = ( ( V_70 & V_187 ) >>
V_188 ) + 2 ;
V_11 -> V_76 += V_11 -> V_77 * V_11 -> V_78 ;
V_72 = 1 ;
break;
}
}
V_11 -> V_189 = ( V_70 >> 16 ) & 0xff ;
return V_70 & V_121 ;
}
static inline unsigned int F_63 ( struct V_10 * V_11 )
{
unsigned int V_190 ;
V_190 = F_64 () ;
V_190 &= ~ ( V_191 | V_192 ) ;
F_65 ( V_190 ) ;
if ( V_190 & V_193 )
V_11 -> V_35 |= V_194 ;
if ( V_190 & V_195 )
V_11 -> V_35 |= V_196 ;
if ( V_190 & V_197 )
V_11 -> V_35 |= V_198 ;
#ifdef F_66
if ( V_190 & V_199 )
V_11 -> V_35 |= V_200 ;
#endif
return V_190 & V_121 ;
}
static void F_67 ( struct V_10 * V_11 )
{
int V_201 ;
V_11 -> V_35 = V_202 | V_203 | V_204 |
V_205 | V_206 | V_207 ;
V_11 -> V_138 . V_139 = V_140 ;
F_26 ( V_11 , ! V_75 ) ;
V_201 = F_50 ( V_11 ) ;
F_68 ( ! V_201 ) ;
if ( V_201 )
V_201 = F_53 ( V_11 ) ;
if ( V_201 )
V_201 = F_55 ( V_11 ) ;
if ( V_201 )
V_201 = F_57 ( V_11 ) ;
if ( V_201 )
V_201 = F_59 ( V_11 ) ;
if ( V_201 )
V_201 = F_63 ( V_11 ) ;
F_69 ( V_11 ) ;
if ( V_208 ) {
F_70 ( V_209 ) ;
F_28 () ;
if ( F_71 () & V_209 )
V_11 -> V_35 |= V_210 ;
}
#ifndef F_72
if ( V_211 ) {
V_11 -> V_212 = F_73 () ;
if ( V_213 )
V_11 -> V_212 >>= F_74 ( F_75 () ) - 1 ;
}
#endif
}
static inline void F_76 ( struct V_10 * V_11 , unsigned int V_91 )
{
switch ( V_11 -> V_81 & V_214 ) {
case V_215 :
V_11 -> V_104 = V_216 ;
V_217 [ V_91 ] = L_9 ;
V_11 -> V_23 |= V_218 | V_219 ;
V_11 -> V_35 = V_115 | V_220 |
V_221 ;
if ( F_6 () )
V_11 -> V_35 |= V_49 ;
V_11 -> V_76 = 64 ;
break;
case V_222 :
if ( ( V_11 -> V_81 & V_82 ) == V_223 ) {
if ( F_36 () ) {
V_11 -> V_104 = V_224 ;
V_217 [ V_91 ] = L_10 ;
} else {
V_11 -> V_104 = V_225 ;
V_217 [ V_91 ] = L_11 ;
}
} else {
V_11 -> V_104 = V_226 ;
V_217 [ V_91 ] = L_12 ;
}
V_11 -> V_23 |= V_218 | V_219 ;
V_11 -> V_35 = V_115 | V_220 |
V_221 ;
if ( F_6 () )
V_11 -> V_35 |= V_49 ;
V_11 -> V_76 = 64 ;
break;
case V_227 :
if ( F_51 () & V_228 ) {
if ( ( V_11 -> V_81 & V_82 ) >=
V_229 ) {
V_11 -> V_104 = V_230 ;
V_217 [ V_91 ] = L_13 ;
} else {
V_11 -> V_104 = V_231 ;
V_217 [ V_91 ] = L_14 ;
}
} else {
int V_232 = F_51 () & V_233 ;
int V_234 ;
switch ( V_232 ) {
case V_235 :
case V_236 :
case V_237 :
V_234 = 1 ;
break;
default:
V_234 = 0 ;
break;
}
if ( ( V_11 -> V_81 & V_82 ) >=
V_229 ) {
V_11 -> V_104 = V_234 ? V_238 : V_239 ;
V_217 [ V_91 ] = V_234 ? L_15 : L_16 ;
} else {
V_11 -> V_104 = V_234 ? V_240 : V_241 ;
V_217 [ V_91 ] = V_234 ? L_17 : L_18 ;
}
}
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_218 ;
V_11 -> V_35 = V_242 | V_49 | V_133 |
V_127 | V_243 |
V_206 ;
V_11 -> V_76 = 48 ;
break;
case V_244 :
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_218 ;
V_11 -> V_35 = V_242 ;
V_11 -> V_76 = 32 ;
switch ( V_11 -> V_81 & 0xf0 ) {
case V_245 :
V_11 -> V_104 = V_246 ;
V_217 [ V_91 ] = L_19 ;
break;
case V_247 :
V_11 -> V_104 = V_248 ;
V_217 [ V_91 ] = L_20 ;
break;
case V_249 :
if ( ( V_11 -> V_81 & 0xf ) < 0x3 ) {
V_11 -> V_104 = V_250 ;
V_217 [ V_91 ] = L_21 ;
} else {
V_11 -> V_104 = V_251 ;
V_217 [ V_91 ] = L_22 ;
}
break;
case V_252 :
if ( ( V_11 -> V_81 & 0xf ) < 0x4 ) {
V_11 -> V_104 = V_253 ;
V_217 [ V_91 ] = L_23 ;
} else {
V_11 -> V_104 = V_254 ;
V_11 -> V_35 |= V_206 ;
V_217 [ V_91 ] = L_24 ;
}
break;
default:
F_77 ( V_255 L_25 ) ;
V_11 -> V_104 = V_256 ;
V_217 [ V_91 ] = L_26 ;
break;
}
break;
case V_257 :
V_11 -> V_104 = V_258 ;
V_217 [ V_91 ] = L_27 ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_218 ;
V_11 -> V_35 = V_242 | V_49 | V_133 |
V_206 ;
V_11 -> V_76 = 32 ;
break;
case V_259 :
V_11 -> V_104 = V_260 ;
V_217 [ V_91 ] = L_28 ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_218 ;
V_11 -> V_35 = V_242 | V_49 | V_133 |
V_206 ;
V_11 -> V_76 = 48 ;
break;
#if 0
case PRID_IMP_R4650:
c->cputype = CPU_R4650;
__cpu_name[cpu] = "R4650";
set_isa(c, MIPS_CPU_ISA_III);
c->fpu_msk31 |= FPU_CSR_CONDX;
c->options = R4K_OPTS | MIPS_CPU_FPU | MIPS_CPU_LLSC;
c->tlbsize = 48;
break;
#endif
case V_261 :
V_11 -> V_23 |= V_218 | V_219 ;
V_11 -> V_35 = V_115 | V_262 ;
if ( ( V_11 -> V_81 & 0xf0 ) == ( V_263 & 0xf0 ) ) {
V_11 -> V_104 = V_264 ;
V_217 [ V_91 ] = L_29 ;
V_11 -> V_76 = 64 ;
} else {
switch ( V_11 -> V_81 & V_82 ) {
case V_265 :
V_11 -> V_104 = V_266 ;
V_217 [ V_91 ] = L_30 ;
V_11 -> V_76 = 32 ;
break;
case V_267 :
V_11 -> V_104 = V_268 ;
V_217 [ V_91 ] = L_31 ;
V_11 -> V_76 = 64 ;
break;
}
}
break;
case V_269 :
V_11 -> V_104 = V_270 ;
V_217 [ V_91 ] = L_32 ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_218 ;
V_11 -> V_35 = V_242 | V_49 | V_133 |
V_206 ;
V_11 -> V_76 = 48 ;
break;
case V_271 :
V_11 -> V_104 = V_272 ;
V_217 [ V_91 ] = L_33 ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_218 ;
V_11 -> V_35 = V_242 | V_206 ;
if ( ! ( V_11 -> V_81 & 0x08 ) )
V_11 -> V_35 |= V_49 | V_133 ;
V_11 -> V_76 = 48 ;
break;
case V_273 :
V_11 -> V_104 = V_274 ;
V_217 [ V_91 ] = L_34 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_242 | V_49 | V_133 |
V_206 ;
V_11 -> V_76 = 48 ;
break;
case V_275 :
V_11 -> V_104 = V_276 ;
V_217 [ V_91 ] = L_35 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_242 | V_49 | V_133 |
V_127 | V_206 ;
V_11 -> V_76 = 48 ;
break;
case V_277 :
V_11 -> V_104 = V_278 ;
V_217 [ V_91 ] = L_36 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_242 | V_49 | V_133 |
V_127 | V_206 ;
V_11 -> V_76 = 48 ;
break;
case V_279 :
V_11 -> V_104 = V_280 ;
V_217 [ V_91 ] = L_37 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_242 | V_49 | V_133 |
V_205 | V_206 ;
V_11 -> V_76 = 48 ;
break;
case V_281 :
V_11 -> V_104 = V_282 ;
V_217 [ V_91 ] = L_38 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_23 |= V_218 | V_219 ;
V_11 -> V_35 = V_115 | V_49 |
V_206 ;
V_11 -> V_76 = 32 ;
break;
case V_283 :
V_11 -> V_104 = V_284 ;
V_217 [ V_91 ] = L_39 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_23 |= V_218 | V_219 ;
V_11 -> V_35 = V_115 | V_49 |
V_206 ;
V_11 -> V_76 = 32 ;
break;
case V_285 :
V_11 -> V_104 = V_286 ;
V_217 [ V_91 ] = L_40 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_242 | V_49 | V_133 |
V_206 ;
V_11 -> V_76 = ( F_78 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_287 :
V_11 -> V_104 = V_288 ;
V_217 [ V_91 ] = L_41 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_115 | V_202 |
V_49 | V_133 |
V_206 ;
V_11 -> V_76 = 384 ;
break;
case V_289 :
V_11 -> V_104 = V_290 ;
V_217 [ V_91 ] = L_42 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_115 | V_203 | V_202 |
V_49 | V_133 |
V_204 | V_127 |
V_206 ;
V_11 -> V_76 = 64 ;
break;
case V_291 :
V_11 -> V_104 = V_292 ;
V_217 [ V_91 ] = L_43 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_115 | V_203 | V_202 |
V_49 | V_133 |
V_204 | V_127 |
V_206 | V_293 ;
V_11 -> V_76 = 64 ;
break;
case V_294 :
if ( ( ( V_11 -> V_81 >> 4 ) & 0x0f ) > 2 ) {
V_11 -> V_104 = V_295 ;
V_217 [ V_91 ] = L_44 ;
} else {
V_11 -> V_104 = V_296 ;
V_217 [ V_91 ] = L_45 ;
}
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_115 | V_203 | V_202 |
V_49 | V_133 |
V_204 | V_127 |
V_206 | V_293 ;
V_11 -> V_76 = 64 ;
break;
case V_297 :
switch ( V_11 -> V_81 & V_82 ) {
case V_298 :
V_11 -> V_104 = V_299 ;
V_217 [ V_91 ] = L_46 ;
F_40 ( V_91 , L_47 ) ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_218 ;
break;
case V_300 :
V_11 -> V_104 = V_299 ;
V_217 [ V_91 ] = L_46 ;
F_40 ( V_91 , L_48 ) ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_218 ;
break;
case V_301 :
V_11 -> V_104 = V_302 ;
V_217 [ V_91 ] = L_49 ;
F_40 ( V_91 , L_50 ) ;
F_46 ( V_11 , V_26 ) ;
break;
case V_303 :
case V_304 :
V_11 -> V_104 = V_302 ;
V_217 [ V_91 ] = L_49 ;
F_40 ( V_91 , L_51 ) ;
F_46 ( V_11 , V_26 ) ;
break;
}
V_11 -> V_35 = V_242 |
V_49 | V_206 |
V_133 ;
V_11 -> V_76 = 64 ;
V_11 -> V_305 = V_306 ;
break;
case V_307 :
F_67 ( V_11 ) ;
V_11 -> V_104 = V_308 ;
switch ( V_11 -> V_81 & V_82 ) {
case V_309 :
V_217 [ V_91 ] = L_52 ;
break;
}
break;
}
}
static inline void F_79 ( struct V_10 * V_11 , unsigned int V_91 )
{
V_11 -> V_305 = V_306 ;
switch ( V_11 -> V_81 & V_214 ) {
case V_310 :
V_11 -> V_305 = V_311 ;
V_11 -> V_104 = V_312 ;
V_217 [ V_91 ] = L_53 ;
break;
case V_313 :
V_11 -> V_104 = V_314 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_54 ;
break;
case V_315 :
case V_316 :
V_11 -> V_104 = V_317 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_55 ;
break;
case V_318 :
case V_319 :
V_11 -> V_104 = V_320 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_56 ;
break;
case V_321 :
V_11 -> V_104 = V_322 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_57 ;
break;
case V_323 :
V_11 -> V_104 = V_324 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_58 ;
break;
case V_325 :
V_11 -> V_104 = V_326 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_59 ;
break;
case V_327 :
V_11 -> V_104 = V_328 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_60 ;
break;
case V_329 :
V_11 -> V_104 = V_328 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_61 ;
break;
case V_330 :
V_11 -> V_104 = V_331 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_62 ;
break;
case V_332 :
V_11 -> V_104 = V_80 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_63 ;
break;
case V_333 :
V_11 -> V_104 = V_334 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_64 ;
break;
case V_335 :
V_11 -> V_104 = V_336 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_65 ;
break;
case V_337 :
V_11 -> V_104 = V_338 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_66 ;
break;
case V_339 :
V_11 -> V_104 = V_340 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_67 ;
break;
case V_341 :
V_11 -> V_104 = V_342 ;
V_11 -> V_305 = V_311 ;
V_217 [ V_91 ] = L_68 ;
break;
case V_343 :
V_11 -> V_104 = V_344 ;
V_217 [ V_91 ] = L_69 ;
break;
case V_345 :
V_11 -> V_104 = V_344 ;
V_217 [ V_91 ] = L_70 ;
break;
case V_346 :
V_11 -> V_104 = V_105 ;
V_217 [ V_91 ] = L_71 ;
break;
case V_347 :
V_11 -> V_104 = V_105 ;
V_217 [ V_91 ] = L_72 ;
break;
case V_348 :
V_11 -> V_104 = V_106 ;
V_217 [ V_91 ] = L_73 ;
break;
case V_349 :
V_11 -> V_104 = V_109 ;
V_217 [ V_91 ] = L_74 ;
break;
case V_350 :
V_11 -> V_104 = V_351 ;
V_217 [ V_91 ] = L_75 ;
break;
}
F_67 ( V_11 ) ;
F_80 () ;
}
static inline void F_81 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_67 ( V_11 ) ;
switch ( V_11 -> V_81 & V_214 ) {
case V_352 :
case V_353 :
V_11 -> V_104 = V_354 ;
switch ( ( V_11 -> V_81 >> 24 ) & 0xff ) {
case 0 :
V_217 [ V_91 ] = L_76 ;
break;
case 1 :
V_217 [ V_91 ] = L_77 ;
break;
case 2 :
V_217 [ V_91 ] = L_78 ;
break;
case 3 :
V_217 [ V_91 ] = L_79 ;
break;
case 4 :
V_217 [ V_91 ] = L_80 ;
if ( ( V_11 -> V_81 & V_82 ) == 2 )
V_217 [ V_91 ] = L_81 ;
break;
case 5 :
V_217 [ V_91 ] = L_82 ;
break;
default:
V_217 [ V_91 ] = L_83 ;
break;
}
break;
}
}
static inline void F_82 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_67 ( V_11 ) ;
V_11 -> V_305 = V_306 ;
switch ( V_11 -> V_81 & V_214 ) {
case V_355 :
V_11 -> V_104 = V_356 ;
V_217 [ V_91 ] = L_84 ;
if ( ( V_11 -> V_81 & V_82 ) < 0x02 )
V_11 -> V_35 &= ~ ( V_49 | V_133 ) ;
break;
case V_357 :
V_11 -> V_104 = V_358 ;
V_217 [ V_91 ] = L_85 ;
break;
}
}
static inline void F_83 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_67 ( V_11 ) ;
switch ( V_11 -> V_81 & V_214 ) {
case V_359 :
V_11 -> V_104 = V_360 ;
V_217 [ V_91 ] = L_86 ;
V_11 -> V_138 . V_361 = 8 ;
V_11 -> V_76 = 64 ;
break;
}
}
static inline void F_84 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_67 ( V_11 ) ;
switch ( V_11 -> V_81 & V_214 ) {
case V_362 :
V_11 -> V_104 = V_363 ;
V_217 [ V_91 ] = L_87 ;
F_46 ( V_11 , V_25 ) ;
break;
}
}
static inline void F_85 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_67 ( V_11 ) ;
switch ( V_11 -> V_81 & V_214 ) {
case V_364 :
case V_365 :
V_11 -> V_104 = V_366 ;
V_217 [ V_91 ] = L_88 ;
F_40 ( V_91 , L_89 ) ;
break;
case V_367 :
case V_368 :
case V_369 :
V_11 -> V_104 = V_370 ;
V_217 [ V_91 ] = L_90 ;
F_40 ( V_91 , L_91 ) ;
break;
case V_371 : {
int V_372 = V_11 -> V_81 & V_82 ;
if ( V_372 >= V_373 &&
V_372 <= V_374 ) {
V_11 -> V_104 = V_375 ;
V_217 [ V_91 ] = L_92 ;
F_40 ( V_91 , L_93 ) ;
} else {
V_11 -> V_104 = V_376 ;
V_217 [ V_91 ] = L_94 ;
F_40 ( V_91 , L_95 ) ;
}
break;
}
case V_377 :
case V_378 :
V_11 -> V_104 = V_379 ;
V_217 [ V_91 ] = L_96 ;
F_40 ( V_91 , L_97 ) ;
V_11 -> V_35 |= V_155 ;
break;
}
}
static inline void F_86 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_67 ( V_11 ) ;
switch ( V_11 -> V_81 & V_214 ) {
case V_380 :
case V_381 :
case V_382 :
V_11 -> V_104 = V_383 ;
V_217 [ V_91 ] = L_98 ;
goto V_384;
case V_385 :
case V_386 :
case V_387 :
case V_388 :
V_11 -> V_104 = V_389 ;
V_217 [ V_91 ] = L_99 ;
V_384:
F_40 ( V_91 , L_100 ) ;
break;
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
V_11 -> V_104 = V_395 ;
V_217 [ V_91 ] = L_101 ;
F_40 ( V_91 , L_102 ) ;
break;
case V_396 :
case V_397 :
V_11 -> V_104 = V_398 ;
V_217 [ V_91 ] = L_103 ;
F_40 ( V_91 , L_104 ) ;
break;
default:
F_77 ( V_255 L_105 ) ;
V_11 -> V_104 = V_399 ;
break;
}
}
static inline void F_87 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_67 ( V_11 ) ;
V_11 -> V_35 &= ~ V_204 ;
F_68 ( ! F_88 ( V_400 ) || V_400 ) ;
switch ( V_11 -> V_81 & V_214 ) {
case V_401 :
V_11 -> V_104 = V_402 ;
V_11 -> V_305 = V_306 ;
V_217 [ V_91 ] = L_106 ;
break;
default:
F_52 ( L_107 ) ;
break;
}
}
static inline void F_89 ( struct V_10 * V_11 , int V_91 )
{
F_67 ( V_11 ) ;
if ( ( V_11 -> V_81 & V_214 ) == V_403 ) {
V_11 -> V_104 = V_354 ;
V_217 [ V_91 ] = L_108 ;
return;
}
V_11 -> V_35 = ( V_115 |
V_202 |
V_204 |
V_205 |
V_127 |
V_131 |
V_206 ) ;
switch ( V_11 -> V_81 & V_214 ) {
case V_404 :
case V_405 :
case V_406 :
V_11 -> V_104 = V_407 ;
V_217 [ V_91 ] = L_109 ;
break;
case V_408 :
case V_409 :
V_11 -> V_104 = V_407 ;
V_217 [ V_91 ] = L_110 ;
break;
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
V_11 -> V_104 = V_418 ;
V_217 [ V_91 ] = L_111 ;
break;
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
V_11 -> V_104 = V_418 ;
V_217 [ V_91 ] = L_112 ;
break;
default:
F_30 ( L_113 ,
V_11 -> V_81 ) ;
V_11 -> V_104 = V_418 ;
break;
}
if ( V_11 -> V_104 == V_407 ) {
F_46 ( V_11 , V_28 ) ;
V_11 -> V_35 |= ( V_49 | V_155 | V_207 ) ;
V_11 -> V_76 = ( ( F_48 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_46 ( V_11 , V_26 ) ;
V_11 -> V_76 = ( ( F_54 () >> 25 ) & 0x3f ) + 1 ;
}
V_11 -> V_189 = 0xf ;
}
void F_90 ( void )
{
struct V_10 * V_11 = & V_79 ;
unsigned int V_91 = F_91 () ;
V_11 -> V_81 = V_432 ;
V_11 -> V_2 = V_6 ;
V_11 -> V_104 = V_399 ;
V_11 -> V_305 = V_311 ;
V_11 -> V_17 = V_433 ;
V_11 -> V_23 = V_434 | V_33 | V_34 ;
V_11 -> V_81 = F_92 () ;
switch ( V_11 -> V_81 & V_435 ) {
case V_436 :
F_76 ( V_11 , V_91 ) ;
break;
case V_437 :
F_79 ( V_11 , V_91 ) ;
break;
case V_438 :
F_81 ( V_11 , V_91 ) ;
break;
case V_439 :
F_82 ( V_11 , V_91 ) ;
break;
case V_440 :
F_85 ( V_11 , V_91 ) ;
break;
case V_441 :
F_83 ( V_11 , V_91 ) ;
break;
case V_442 :
F_84 ( V_11 , V_91 ) ;
break;
case V_443 :
F_86 ( V_11 , V_91 ) ;
break;
case V_444 :
case V_445 :
case V_446 :
F_87 ( V_11 , V_91 ) ;
break;
case V_447 :
F_89 ( V_11 , V_91 ) ;
break;
}
F_68 ( ! V_217 [ V_91 ] ) ;
F_68 ( V_11 -> V_104 == V_399 ) ;
F_68 ( F_32 () != V_11 -> V_104 ) ;
if ( V_62 )
V_11 -> V_35 &= ~ V_49 ;
if ( V_66 )
V_11 -> V_58 &= ~ ( V_64 | V_65 ) ;
if ( V_67 ) {
V_11 -> V_35 &= ~ V_68 ;
F_23 ( F_24 () &
~ ( 1 << V_69 ) ) ;
}
if ( V_11 -> V_35 & V_49 )
F_18 ( V_11 ) ;
else
F_19 ( V_11 ) ;
if ( V_448 )
F_93 ( F_94 () |
V_449 ) ;
if ( V_211 ) {
V_11 -> V_450 = ( ( F_95 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_35 |= V_451 ;
}
else
V_11 -> V_450 = 1 ;
if ( V_175 )
V_452 |= V_453 ;
if ( V_454 ) {
V_11 -> V_8 = F_7 () ;
F_96 ( V_11 -> V_8 & V_455 ,
L_114 ) ;
V_452 |= V_456 ;
}
F_41 ( V_11 ) ;
#ifdef F_97
if ( V_91 == 0 )
V_457 = ~ ( ( 1ull << V_458 ) - 1 ) ;
#endif
}
void F_98 ( void )
{
struct V_10 * V_11 = & V_79 ;
F_30 ( L_115 ,
F_91 () , V_11 -> V_81 , F_99 () ) ;
if ( V_11 -> V_35 & V_49 )
F_77 ( V_255 L_116 , V_11 -> V_2 ) ;
if ( V_454 )
F_30 ( L_117 , V_11 -> V_8 ) ;
}
