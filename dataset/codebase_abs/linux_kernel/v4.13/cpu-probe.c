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
if ( V_11 -> V_2 & V_62 )
V_11 -> V_35 |= V_63 ;
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
V_64 = 1 ;
return 1 ;
}
static int T_1 F_21 ( char * V_47 )
{
V_65 [ 0 ] . V_58 &= ~ ( V_66 | V_67 ) ;
V_68 = 1 ;
return 1 ;
}
static int T_1 F_22 ( char * V_47 )
{
V_69 = 1 ;
V_65 [ 0 ] . V_35 &= ~ V_70 ;
F_23 ( F_24 () &
~ ( 1 << V_71 ) ) ;
return 1 ;
}
static int T_1 F_25 ( char * V_47 )
{
unsigned int V_72 , V_73 ;
if ( ! V_74 )
return 1 ;
if ( F_26 ( & V_65 [ 0 ] , 0 ) ) {
F_27 ( L_5 ) ;
return 1 ;
}
V_72 = F_28 () ;
V_73 = V_72 & V_75 ;
if ( V_73 == V_76 ) {
F_27 ( L_6 ) ;
return 1 ;
}
V_77 = 1 ;
V_74 = 0 ;
F_29 ( L_7 ) ;
V_65 [ 0 ] . V_78 -= V_65 [ 0 ] . V_79 *
V_65 [ 0 ] . V_80 ;
V_65 [ 0 ] . V_80 = 0 ;
V_65 [ 0 ] . V_79 = 0 ;
return 1 ;
}
static inline void F_30 ( void )
{
struct V_10 * V_11 = & V_81 ;
switch ( F_31 () ) {
case V_82 :
if ( ( V_11 -> V_83 & V_84 ) <= V_85 )
F_32 ( F_33 () | V_86 ) ;
break;
default:
break;
}
}
void T_1 F_34 ( void )
{
F_30 () ;
}
static inline int F_35 ( void )
{
#ifdef F_36
extern unsigned long V_87 ( unsigned long ) ;
unsigned long V_88 , V_89 ;
unsigned long V_90 = F_37 () ;
V_88 = V_87 ( V_91 ) ;
F_38 ( V_90 ^ V_92 ) ;
V_89 = V_87 ( V_91 ) ;
F_38 ( V_90 ) ;
return V_88 != V_89 ;
#else
return 0 ;
#endif
}
static inline void F_39 ( int V_93 , const char * V_94 )
{
if ( V_93 == 0 )
V_95 = V_94 ;
}
static inline void F_40 ( struct V_10 * V_11 )
{
#ifdef F_41
F_42 ( 0x3fffffffffffe000ULL ) ;
F_43 () ;
V_11 -> V_96 = F_44 ( F_45 () & 0x3fffffffffffe000ULL ) ;
#endif
}
static void F_46 ( struct V_10 * V_11 , unsigned int V_97 )
{
switch ( V_97 ) {
case V_28 :
V_11 -> V_24 |= V_27 | V_28 ;
case V_26 :
V_11 -> V_24 |= V_25 | V_26 ;
case V_98 :
V_11 -> V_24 |= V_98 ;
case V_99 :
V_11 -> V_24 |= V_99 ;
case V_100 :
V_11 -> V_24 |= V_101 | V_100 ;
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
case V_101 :
V_11 -> V_24 |= V_101 ;
break;
}
}
static unsigned int F_47 ( struct V_10 * V_11 )
{
unsigned int V_102 = V_11 -> V_78 / V_11 -> V_103 ;
if ( V_102 >= 12 )
return 1 ;
else if ( V_102 >= 6 )
return 2 ;
else
return 3 ;
}
static int F_26 ( struct V_10 * V_11 , enum V_104 V_105 )
{
unsigned int V_106 ;
switch ( V_11 -> V_107 ) {
case V_108 :
case V_109 :
case V_110 :
V_106 = F_48 () ;
if ( V_105 & V_111 )
V_106 |= V_112 ;
else
V_106 &= ~ V_112 ;
if ( V_105 & V_113 ) {
V_106 &= ~ ( 3 << V_114 ) ;
V_106 |= F_47 ( V_11 )
<< V_114 ;
}
F_49 ( V_106 ) ;
F_43 () ;
break;
case V_115 :
case V_116 :
if ( ! ( V_105 & V_111 ) )
return 1 ;
return 0 ;
case V_117 :
F_50 ( V_118 | V_119 |
V_120 | V_121 ) ;
V_106 = F_48 () ;
if ( V_105 & V_111 )
F_49 ( V_106 & ~ V_122 ) ;
else
F_49 ( V_106 | V_122 ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static inline unsigned int F_51 ( struct V_10 * V_11 )
{
unsigned int V_123 ;
int V_97 , V_124 ;
V_123 = F_52 () ;
V_124 = V_123 & V_125 ;
if ( V_124 == V_126 )
V_11 -> V_35 |= V_127 ;
else if ( V_124 == V_128 )
V_11 -> V_35 |= V_127 | V_129 ;
V_97 = ( V_123 & V_130 ) >> 13 ;
switch ( V_97 ) {
case 0 :
switch ( ( V_123 & V_131 ) >> 10 ) {
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
goto V_132;
}
break;
case 2 :
switch ( ( V_123 & V_131 ) >> 10 ) {
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
goto V_132;
}
break;
default:
goto V_132;
}
return V_123 & V_133 ;
V_132:
F_53 ( V_134 , V_123 ) ;
}
static inline unsigned int F_54 ( struct V_10 * V_11 )
{
unsigned int V_135 ;
V_135 = F_55 () ;
if ( V_135 & V_136 )
V_11 -> V_58 |= V_137 ;
if ( V_135 & V_138 )
V_11 -> V_35 |= V_139 ;
if ( V_135 & V_140 )
V_11 -> V_35 |= V_141 ;
if ( V_135 & V_142 )
V_11 -> V_58 |= V_143 ;
if ( V_135 & V_144 )
V_11 -> V_35 |= V_145 ;
if ( V_135 & V_146 ) {
V_11 -> V_35 |= V_49 ;
V_11 -> V_35 |= V_147 ;
}
if ( V_148 ) {
V_11 -> V_78 = ( ( V_135 & V_149 ) >> 25 ) + 1 ;
V_11 -> V_103 = V_11 -> V_78 ;
V_11 -> V_80 = 0 ;
}
return V_135 & V_133 ;
}
static inline unsigned int F_56 ( struct V_10 * V_11 )
{
unsigned int V_150 ;
V_150 = F_57 () ;
if ( V_150 & V_151 )
V_11 -> V_152 . V_105 &= ~ V_153 ;
return V_150 & V_133 ;
}
static inline unsigned int F_58 ( struct V_10 * V_11 )
{
unsigned int V_154 ;
V_154 = F_59 () ;
if ( V_154 & V_155 ) {
V_11 -> V_58 |= V_156 ;
V_11 -> V_35 |= V_157 | V_158 ;
}
if ( V_154 & V_159 )
V_11 -> V_35 |= V_157 ;
if ( V_154 & V_160 )
V_11 -> V_35 |= V_158 ;
if ( V_154 & V_161 )
V_11 -> V_58 |= V_66 ;
if ( V_154 & V_162 ) {
V_11 -> V_58 |= V_67 ;
if ( V_163 )
V_11 -> V_58 |= V_164 ;
}
if ( V_154 & V_165 )
V_11 -> V_35 |= V_166 ;
if ( V_154 & V_167 )
V_11 -> V_35 |= V_168 ;
if ( V_154 & V_169 )
V_11 -> V_35 |= V_170 ;
if ( V_154 & V_171 )
V_11 -> V_58 |= V_172 ;
if ( V_154 & V_173 )
V_11 -> V_35 |= V_174 ;
if ( V_154 & V_175 )
V_11 -> V_35 |= V_176 ;
if ( V_154 & V_177 )
V_11 -> V_58 |= V_178 ;
if ( V_154 & V_179 )
V_11 -> V_35 |= V_180 ;
if ( V_154 & V_181 )
V_11 -> V_35 |= V_182 ;
if ( V_154 & V_183 )
V_11 -> V_35 |= V_184 ;
if ( V_154 & V_185 )
V_11 -> V_58 |= V_186 ;
if ( V_154 & V_187 ) {
V_11 -> V_188 = 0 ;
V_11 -> V_35 |= V_70 ;
}
if ( V_154 & V_189 )
V_11 -> V_35 |= V_190 ;
if ( V_154 & V_191 )
V_11 -> V_35 |= V_192 ;
return V_154 & V_133 ;
}
static inline unsigned int F_60 ( struct V_10 * V_11 )
{
unsigned int V_72 ;
unsigned int V_193 ;
unsigned int V_73 ;
unsigned int V_194 = V_195 ;
unsigned long V_196 ;
V_72 = F_28 () ;
if ( V_148 ) {
if ( ( ( V_72 & V_197 ) >> 29 ) == 2 )
V_11 -> V_35 |= V_198 ;
if ( ! V_163 )
V_73 = V_72 & V_75 ;
else if ( V_199 )
V_73 = V_200 ;
else
V_73 = 0 ;
switch ( V_73 ) {
case V_201 :
V_11 -> V_78 += ( V_72 & V_202 ) * 0x40 ;
V_11 -> V_103 = V_11 -> V_78 ;
break;
case V_200 :
V_11 -> V_103 +=
( ( V_72 & V_203 ) >>
V_204 ) * 0x40 ;
V_11 -> V_78 = V_11 -> V_103 ;
V_194 = V_205 ;
case V_76 :
if ( V_77 )
break;
V_193 = ( V_72 & ~ V_194 ) |
( F_61 ( V_73 ) <<
V_206 ) ;
F_62 ( V_193 ) ;
F_43 () ;
V_72 = F_28 () ;
if ( V_72 != V_193 ) {
F_63 ( L_8 ,
V_207 , V_72 ) ;
F_26 ( V_11 , 0 ) ;
V_77 = 1 ;
break;
}
V_11 -> V_80 = 1 <<
( ( V_72 & V_208 ) >>
V_209 ) ;
V_11 -> V_79 = ( ( V_72 & V_210 ) >>
V_211 ) + 2 ;
V_11 -> V_78 += V_11 -> V_79 * V_11 -> V_80 ;
V_74 = 1 ;
break;
}
}
V_11 -> V_212 = ( V_72 & V_213 )
>> V_214 ;
V_196 = V_215 ;
if ( V_72 & V_216 )
V_196 |= V_217 ;
F_64 ( V_11 , V_196 ) ;
F_65 ( V_196 != F_66 ( V_11 ) ) ;
return V_72 & V_133 ;
}
static inline unsigned int F_67 ( struct V_10 * V_11 )
{
unsigned int V_218 ;
V_218 = F_68 () ;
V_218 &= ~ ( V_219 | V_220 ) ;
F_69 ( V_218 ) ;
if ( V_218 & V_221 )
V_11 -> V_35 |= V_222 ;
if ( V_218 & V_223 )
V_11 -> V_35 |= V_224 ;
if ( V_218 & V_225 )
V_11 -> V_35 |= V_226 ;
if ( V_218 & V_227 )
V_11 -> V_35 |= V_228 ;
if ( V_163 && ( V_218 & V_229 ) )
V_11 -> V_35 |= V_230 ;
if ( V_218 & V_231 )
V_11 -> V_58 |= V_232 ;
return V_218 & V_133 ;
}
static void F_70 ( struct V_10 * V_11 )
{
int V_233 ;
V_11 -> V_35 = V_234 | V_235 | V_236 |
V_237 | V_238 | V_239 ;
V_11 -> V_152 . V_105 = V_153 ;
F_26 ( V_11 , V_77 ? 0 : V_111 ) ;
V_233 = F_51 ( V_11 ) ;
F_71 ( ! V_233 ) ;
if ( V_233 )
V_233 = F_54 ( V_11 ) ;
if ( V_233 )
V_233 = F_56 ( V_11 ) ;
if ( V_233 )
V_233 = F_58 ( V_11 ) ;
if ( V_233 )
V_233 = F_60 ( V_11 ) ;
if ( V_233 )
V_233 = F_67 ( V_11 ) ;
if ( V_240 ) {
T_3 V_241 ;
unsigned int V_7 ;
V_241 = V_242 ? F_72 ()
: ( V_243 ) F_73 () ;
if ( V_241 & V_244 ) {
V_11 -> V_35 |= V_245 ;
} else {
V_7 = F_2 () ;
F_5 ( V_7 | V_246 ) ;
F_74 () ;
if ( V_242 )
F_75 ( V_241 | V_244 ) ;
else
F_76 ( V_241 | V_244 ) ;
F_43 () ;
F_5 ( V_7 ) ;
if ( F_73 () & V_244 ) {
V_11 -> V_35 |= V_245 ;
F_76 ( V_241 ) ;
}
}
}
F_26 ( V_11 , ( V_77 ? 0 : V_111 ) | V_113 ) ;
F_77 ( V_11 ) ;
#ifndef F_78
if ( V_240 ) {
V_11 -> V_247 = F_79 () ;
if ( V_248 )
V_11 -> V_247 >>= F_80 ( F_81 () ) - 1 ;
}
#endif
}
static inline unsigned int F_82 ( struct V_10 * V_11 )
{
unsigned int V_123 ;
F_83 ( V_106 , V_123 , V_133 ) ;
if ( V_123 & V_133 )
V_11 -> V_249 . V_250 |= F_84 ( 1 ) ;
return V_123 & V_133 ;
}
static inline unsigned int F_85 ( struct V_10 * V_11 )
{
unsigned int V_135 , V_251 ;
F_86 ( V_135 , V_135 , V_251 ,
V_133 | V_138 | V_140 |
V_146 ) ;
if ( V_135 & V_146 )
V_11 -> V_249 . V_35 |= V_49 ;
if ( V_251 & V_146 )
V_11 -> V_249 . V_252 |= V_49 ;
if ( V_135 & V_140 )
V_11 -> V_249 . V_35 |= V_141 ;
if ( V_251 & V_140 )
V_11 -> V_249 . V_252 |= V_141 ;
if ( V_135 & V_138 )
V_11 -> V_249 . V_35 |= V_139 ;
if ( V_251 & V_138 )
V_11 -> V_249 . V_252 |= V_139 ;
if ( V_135 & V_133 )
V_11 -> V_249 . V_250 |= F_84 ( 2 ) ;
return V_135 & V_133 ;
}
static inline unsigned int F_87 ( struct V_10 * V_11 )
{
unsigned int V_150 ;
F_83 ( V_150 , V_150 , V_133 ) ;
if ( V_150 & V_133 )
V_11 -> V_249 . V_250 |= F_84 ( 3 ) ;
return V_150 & V_133 ;
}
static inline unsigned int F_88 ( struct V_10 * V_11 )
{
unsigned int V_154 , V_253 ;
F_86 ( V_154 , V_154 , V_253 ,
V_133 | V_185 | V_173 |
V_160 ) ;
if ( V_154 & V_160 )
V_11 -> V_249 . V_35 |= V_158 ;
if ( V_253 & V_160 )
V_11 -> V_249 . V_252 |= V_158 ;
if ( V_154 & V_187 )
V_11 -> V_249 . V_35 |= V_70 ;
if ( V_154 & V_173 )
V_11 -> V_249 . V_35 |= V_174 ;
if ( V_154 & V_179 )
V_11 -> V_249 . V_35 |= V_180 ;
if ( V_154 & V_181 )
V_11 -> V_249 . V_35 |= V_182 ;
if ( V_154 & V_183 )
V_11 -> V_249 . V_35 |= V_184 ;
if ( V_154 & V_185 )
V_11 -> V_249 . V_58 |= V_186 ;
if ( V_253 & V_185 )
V_11 -> V_249 . V_254 |= V_186 ;
if ( V_154 & V_133 )
V_11 -> V_249 . V_250 |= F_84 ( 4 ) ;
return V_154 & V_133 ;
}
static inline unsigned int F_89 ( struct V_10 * V_11 )
{
unsigned int V_72 ;
F_83 ( V_72 , V_72 ,
V_133 | V_213 ) ;
V_11 -> V_249 . V_212 = ( V_72 & V_213 )
>> V_214 ;
if ( V_72 & V_133 )
V_11 -> V_249 . V_250 |= F_84 ( 5 ) ;
return V_72 & V_133 ;
}
static inline unsigned int F_90 ( struct V_10 * V_11 )
{
unsigned int V_218 , V_255 ;
F_86 ( V_218 , V_218 , V_255 ,
V_133 | V_227 | V_223 ) ;
if ( V_218 & V_223 )
V_11 -> V_249 . V_35 |= V_224 ;
if ( V_255 & V_223 )
V_11 -> V_249 . V_252 |= V_224 ;
if ( V_218 & V_225 )
V_11 -> V_249 . V_35 |= V_226 ;
if ( V_218 & V_227 )
V_11 -> V_249 . V_35 |= V_228 ;
if ( V_218 & V_133 )
V_11 -> V_249 . V_250 |= F_84 ( 6 ) ;
return V_218 & V_133 ;
}
static inline void F_91 ( struct V_10 * V_11 )
{
unsigned int V_233 ;
V_233 = F_82 ( V_11 ) ;
if ( V_233 )
V_233 = F_85 ( V_11 ) ;
if ( V_233 )
V_233 = F_87 ( V_11 ) ;
if ( V_233 )
V_233 = F_88 ( V_11 ) ;
if ( V_233 )
V_233 = F_89 ( V_11 ) ;
if ( V_233 )
F_90 ( V_11 ) ;
}
static inline void F_92 ( struct V_10 * V_11 )
{
unsigned int V_256 , V_257 ;
V_256 = F_93 () ;
if ( V_256 & V_258 )
V_11 -> V_35 |= V_259 ;
if ( V_256 & V_260 )
V_11 -> V_35 |= V_261 ;
if ( V_256 & V_262 )
V_11 -> V_35 |= V_263 ;
if ( ! ( V_256 & V_264 ) ) {
V_11 -> V_35 |= V_265 ;
F_94 ( 0 ) ;
F_95 () ;
F_96 ( V_256 | V_266 ) ;
F_43 () ;
V_257 = F_93 () ;
if ( V_257 & V_266 ) {
F_96 ( V_256 ) ;
V_11 -> V_35 |= V_267 ;
}
}
}
static inline void F_97 ( struct V_10 * V_11 )
{
if ( V_268 ) {
F_94 ( V_269 ) ;
F_43 () ;
V_11 -> V_270 = ( F_98 () & V_269 )
>> V_271 ;
F_94 ( 0 ) ;
}
}
static inline void F_99 ( struct V_10 * V_11 )
{
F_100 ( 0xffffffff ) ;
F_43 () ;
V_11 -> V_272 = F_101 () ;
F_100 ( 0 ) ;
}
static inline void F_102 ( struct V_10 * V_11 )
{
F_92 ( V_11 ) ;
if ( V_273 )
F_97 ( V_11 ) ;
F_99 ( V_11 ) ;
F_91 ( V_11 ) ;
}
static inline void F_103 ( struct V_10 * V_11 , unsigned int V_93 )
{
switch ( V_11 -> V_83 & V_274 ) {
case V_275 :
V_11 -> V_107 = V_276 ;
V_277 [ V_93 ] = L_9 ;
V_11 -> V_23 |= V_278 | V_279 ;
V_11 -> V_35 = V_127 | V_280 |
V_281 ;
if ( F_6 () )
V_11 -> V_35 |= V_49 ;
V_11 -> V_78 = 64 ;
break;
case V_282 :
if ( ( V_11 -> V_83 & V_84 ) == V_283 ) {
if ( F_35 () ) {
V_11 -> V_107 = V_284 ;
V_277 [ V_93 ] = L_10 ;
} else {
V_11 -> V_107 = V_285 ;
V_277 [ V_93 ] = L_11 ;
}
} else {
V_11 -> V_107 = V_286 ;
V_277 [ V_93 ] = L_12 ;
}
V_11 -> V_23 |= V_278 | V_279 ;
V_11 -> V_35 = V_127 | V_280 |
V_281 ;
if ( F_6 () )
V_11 -> V_35 |= V_49 ;
V_11 -> V_78 = 64 ;
break;
case V_287 :
if ( F_52 () & V_288 ) {
if ( ( V_11 -> V_83 & V_84 ) >=
V_289 ) {
V_11 -> V_107 = V_290 ;
V_277 [ V_93 ] = L_13 ;
} else {
V_11 -> V_107 = V_291 ;
V_277 [ V_93 ] = L_14 ;
}
} else {
int V_292 = F_52 () & V_293 ;
int V_294 ;
switch ( V_292 ) {
case V_295 :
case V_296 :
case V_297 :
V_294 = 1 ;
break;
default:
V_294 = 0 ;
break;
}
if ( ( V_11 -> V_83 & V_84 ) >=
V_289 ) {
V_11 -> V_107 = V_294 ? V_298 : V_299 ;
V_277 [ V_93 ] = V_294 ? L_15 : L_16 ;
} else {
V_11 -> V_107 = V_294 ? V_300 : V_301 ;
V_277 [ V_93 ] = V_294 ? L_17 : L_18 ;
}
}
F_46 ( V_11 , V_100 ) ;
V_11 -> V_23 |= V_278 ;
V_11 -> V_35 = V_302 | V_49 | V_147 |
V_141 | V_303 |
V_238 ;
V_11 -> V_78 = 48 ;
break;
case V_304 :
F_46 ( V_11 , V_100 ) ;
V_11 -> V_23 |= V_278 ;
V_11 -> V_35 = V_302 ;
V_11 -> V_78 = 32 ;
switch ( V_11 -> V_83 & 0xf0 ) {
case V_305 :
V_11 -> V_107 = V_306 ;
V_277 [ V_93 ] = L_19 ;
break;
case V_307 :
V_11 -> V_107 = V_308 ;
V_277 [ V_93 ] = L_20 ;
break;
case V_309 :
if ( ( V_11 -> V_83 & 0xf ) < 0x3 ) {
V_11 -> V_107 = V_310 ;
V_277 [ V_93 ] = L_21 ;
} else {
V_11 -> V_107 = V_311 ;
V_277 [ V_93 ] = L_22 ;
}
break;
case V_312 :
if ( ( V_11 -> V_83 & 0xf ) < 0x4 ) {
V_11 -> V_107 = V_313 ;
V_277 [ V_93 ] = L_23 ;
} else {
V_11 -> V_107 = V_314 ;
V_11 -> V_35 |= V_238 ;
V_277 [ V_93 ] = L_24 ;
}
break;
default:
F_104 ( V_315 L_25 ) ;
V_11 -> V_107 = V_316 ;
V_277 [ V_93 ] = L_26 ;
break;
}
break;
case V_317 :
V_11 -> V_107 = V_318 ;
V_277 [ V_93 ] = L_27 ;
F_46 ( V_11 , V_100 ) ;
V_11 -> V_23 |= V_278 ;
V_11 -> V_35 = V_302 | V_49 | V_147 |
V_238 ;
V_11 -> V_78 = 32 ;
break;
case V_319 :
V_11 -> V_107 = V_320 ;
V_277 [ V_93 ] = L_28 ;
F_46 ( V_11 , V_100 ) ;
V_11 -> V_23 |= V_278 ;
V_11 -> V_35 = V_302 | V_49 | V_147 |
V_238 ;
V_11 -> V_78 = 48 ;
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
case V_321 :
V_11 -> V_23 |= V_278 | V_279 ;
V_11 -> V_35 = V_127 | V_322 ;
if ( ( V_11 -> V_83 & 0xf0 ) == ( V_323 & 0xf0 ) ) {
V_11 -> V_107 = V_324 ;
V_277 [ V_93 ] = L_29 ;
V_11 -> V_78 = 64 ;
} else {
switch ( V_11 -> V_83 & V_84 ) {
case V_325 :
V_11 -> V_107 = V_326 ;
V_277 [ V_93 ] = L_30 ;
V_11 -> V_78 = 32 ;
break;
case V_327 :
V_11 -> V_107 = V_328 ;
V_277 [ V_93 ] = L_31 ;
V_11 -> V_78 = 64 ;
break;
}
}
break;
case V_329 :
V_11 -> V_107 = V_330 ;
V_277 [ V_93 ] = L_32 ;
F_46 ( V_11 , V_100 ) ;
V_11 -> V_23 |= V_278 ;
V_11 -> V_35 = V_302 | V_49 | V_147 |
V_238 ;
V_11 -> V_78 = 48 ;
break;
case V_331 :
V_11 -> V_107 = V_332 ;
V_277 [ V_93 ] = L_33 ;
F_46 ( V_11 , V_100 ) ;
V_11 -> V_23 |= V_278 ;
V_11 -> V_35 = V_302 | V_238 ;
if ( ! ( V_11 -> V_83 & 0x08 ) )
V_11 -> V_35 |= V_49 | V_147 ;
V_11 -> V_78 = 48 ;
break;
case V_333 :
V_11 -> V_107 = V_334 ;
V_277 [ V_93 ] = L_34 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_35 = V_302 | V_49 | V_147 |
V_238 ;
V_11 -> V_78 = 48 ;
break;
case V_335 :
V_11 -> V_107 = V_336 ;
V_277 [ V_93 ] = L_35 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_35 = V_302 | V_49 | V_147 |
V_141 | V_238 ;
V_11 -> V_78 = 48 ;
break;
case V_337 :
V_11 -> V_107 = V_338 ;
V_277 [ V_93 ] = L_36 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_35 = V_302 | V_49 | V_147 |
V_141 | V_238 ;
V_11 -> V_78 = 48 ;
break;
case V_339 :
V_11 -> V_107 = V_340 ;
V_277 [ V_93 ] = L_37 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_35 = V_302 | V_49 | V_147 |
V_237 | V_238 ;
V_11 -> V_78 = 48 ;
break;
case V_341 :
V_11 -> V_107 = V_342 ;
V_277 [ V_93 ] = L_38 ;
F_46 ( V_11 , V_101 ) ;
V_11 -> V_23 |= V_278 | V_279 ;
V_11 -> V_35 = V_127 | V_49 |
V_238 ;
V_11 -> V_78 = 32 ;
break;
case V_343 :
V_11 -> V_107 = V_344 ;
V_277 [ V_93 ] = L_39 ;
F_46 ( V_11 , V_101 ) ;
V_11 -> V_23 |= V_278 | V_279 ;
V_11 -> V_35 = V_127 | V_49 |
V_238 ;
V_11 -> V_78 = 32 ;
break;
case V_345 :
V_11 -> V_107 = V_346 ;
V_277 [ V_93 ] = L_40 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_35 = V_302 | V_49 | V_147 |
V_238 ;
V_11 -> V_78 = ( F_105 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_347 :
V_11 -> V_107 = V_348 ;
V_277 [ V_93 ] = L_41 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_35 = V_127 | V_234 |
V_49 | V_147 |
V_238 ;
V_11 -> V_78 = 384 ;
break;
case V_349 :
V_11 -> V_107 = V_350 ;
V_277 [ V_93 ] = L_42 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_35 = V_127 | V_235 | V_234 |
V_49 | V_147 |
V_236 | V_141 |
V_238 ;
V_11 -> V_78 = 64 ;
break;
case V_351 :
V_11 -> V_107 = V_352 ;
V_277 [ V_93 ] = L_43 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_35 = V_127 | V_235 | V_234 |
V_49 | V_147 |
V_236 | V_141 |
V_238 | V_353 ;
V_11 -> V_78 = 64 ;
break;
case V_354 :
if ( ( ( V_11 -> V_83 >> 4 ) & 0x0f ) > 2 ) {
V_11 -> V_107 = V_355 ;
V_277 [ V_93 ] = L_44 ;
} else {
V_11 -> V_107 = V_356 ;
V_277 [ V_93 ] = L_45 ;
}
F_46 ( V_11 , V_99 ) ;
V_11 -> V_35 = V_127 | V_235 | V_234 |
V_49 | V_147 |
V_236 | V_141 |
V_238 | V_353 ;
V_11 -> V_78 = 64 ;
break;
case V_357 :
switch ( V_11 -> V_83 & V_84 ) {
case V_358 :
V_11 -> V_107 = V_359 ;
V_277 [ V_93 ] = L_46 ;
F_39 ( V_93 , L_47 ) ;
F_46 ( V_11 , V_100 ) ;
V_11 -> V_23 |= V_278 ;
break;
case V_360 :
V_11 -> V_107 = V_359 ;
V_277 [ V_93 ] = L_46 ;
F_39 ( V_93 , L_48 ) ;
F_46 ( V_11 , V_100 ) ;
V_11 -> V_23 |= V_278 ;
break;
case V_361 :
V_11 -> V_107 = V_117 ;
V_277 [ V_93 ] = L_49 ;
F_39 ( V_93 , L_50 ) ;
F_46 ( V_11 , V_26 ) ;
break;
case V_362 :
case V_363 :
V_11 -> V_107 = V_117 ;
V_277 [ V_93 ] = L_49 ;
F_39 ( V_93 , L_51 ) ;
F_46 ( V_11 , V_26 ) ;
break;
}
V_11 -> V_35 = V_302 |
V_49 | V_238 |
V_147 ;
V_11 -> V_78 = 64 ;
V_11 -> V_364 = V_365 ;
break;
case V_366 :
F_70 ( V_11 ) ;
V_11 -> V_107 = V_367 ;
switch ( V_11 -> V_83 & V_84 ) {
case V_368 :
V_277 [ V_93 ] = L_52 ;
break;
}
break;
}
}
static inline void F_106 ( struct V_10 * V_11 , unsigned int V_93 )
{
V_11 -> V_364 = V_365 ;
switch ( V_11 -> V_83 & V_274 ) {
case V_369 :
V_11 -> V_364 = V_370 ;
V_11 -> V_107 = V_371 ;
V_277 [ V_93 ] = L_53 ;
break;
case V_372 :
V_11 -> V_107 = V_373 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_54 ;
break;
case V_374 :
case V_375 :
V_11 -> V_107 = V_376 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_55 ;
break;
case V_377 :
case V_378 :
V_11 -> V_107 = V_379 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_56 ;
break;
case V_380 :
V_11 -> V_107 = V_381 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_57 ;
break;
case V_382 :
V_11 -> V_107 = V_383 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_58 ;
break;
case V_384 :
V_11 -> V_107 = V_385 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_59 ;
break;
case V_386 :
V_11 -> V_107 = V_387 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_60 ;
break;
case V_388 :
V_11 -> V_107 = V_387 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_61 ;
break;
case V_389 :
V_11 -> V_107 = V_390 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_62 ;
break;
case V_391 :
V_11 -> V_107 = V_82 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_63 ;
break;
case V_392 :
V_11 -> V_107 = V_393 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_64 ;
break;
case V_394 :
V_11 -> V_107 = V_395 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_65 ;
break;
case V_396 :
V_11 -> V_107 = V_397 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_66 ;
break;
case V_398 :
V_11 -> V_107 = V_399 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_67 ;
break;
case V_400 :
V_11 -> V_107 = V_401 ;
V_11 -> V_364 = V_370 ;
V_277 [ V_93 ] = L_68 ;
break;
case V_402 :
V_11 -> V_107 = V_403 ;
V_277 [ V_93 ] = L_69 ;
break;
case V_404 :
V_11 -> V_107 = V_403 ;
V_277 [ V_93 ] = L_70 ;
break;
case V_405 :
V_11 -> V_107 = V_108 ;
V_277 [ V_93 ] = L_71 ;
break;
case V_406 :
V_11 -> V_107 = V_108 ;
V_277 [ V_93 ] = L_72 ;
break;
case V_407 :
V_11 -> V_107 = V_109 ;
V_277 [ V_93 ] = L_73 ;
break;
case V_408 :
V_11 -> V_107 = V_110 ;
V_277 [ V_93 ] = L_74 ;
break;
case V_409 :
V_11 -> V_107 = V_115 ;
V_277 [ V_93 ] = L_75 ;
break;
case V_410 :
V_11 -> V_107 = V_116 ;
V_277 [ V_93 ] = L_76 ;
break;
case V_411 :
V_11 -> V_107 = V_412 ;
V_277 [ V_93 ] = L_77 ;
break;
case V_413 :
V_11 -> V_107 = V_414 ;
V_277 [ V_93 ] = L_78 ;
break;
}
F_70 ( V_11 ) ;
F_107 () ;
switch ( F_108 ( V_11 -> V_107 ) ) {
case V_116 :
V_11 -> V_35 |= V_415 ;
case V_115 :
V_11 -> V_35 |= V_416 ;
default:
break;
}
}
static inline void F_109 ( struct V_10 * V_11 , unsigned int V_93 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_83 & V_274 ) {
case V_417 :
case V_418 :
V_11 -> V_107 = V_419 ;
switch ( ( V_11 -> V_83 >> 24 ) & 0xff ) {
case 0 :
V_277 [ V_93 ] = L_79 ;
break;
case 1 :
V_277 [ V_93 ] = L_80 ;
break;
case 2 :
V_277 [ V_93 ] = L_81 ;
break;
case 3 :
V_277 [ V_93 ] = L_82 ;
break;
case 4 :
V_277 [ V_93 ] = L_83 ;
if ( ( V_11 -> V_83 & V_84 ) == 2 )
V_277 [ V_93 ] = L_84 ;
break;
case 5 :
V_277 [ V_93 ] = L_85 ;
break;
default:
V_277 [ V_93 ] = L_86 ;
break;
}
break;
}
}
static inline void F_110 ( struct V_10 * V_11 , unsigned int V_93 )
{
F_70 ( V_11 ) ;
V_11 -> V_364 = V_365 ;
switch ( V_11 -> V_83 & V_274 ) {
case V_420 :
V_11 -> V_107 = V_421 ;
V_277 [ V_93 ] = L_87 ;
if ( ( V_11 -> V_83 & V_84 ) < 0x02 )
V_11 -> V_35 &= ~ ( V_49 | V_147 ) ;
break;
case V_422 :
V_11 -> V_107 = V_423 ;
V_277 [ V_93 ] = L_88 ;
break;
}
}
static inline void F_111 ( struct V_10 * V_11 , unsigned int V_93 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_83 & V_274 ) {
case V_424 :
V_11 -> V_107 = V_425 ;
V_277 [ V_93 ] = L_89 ;
V_11 -> V_152 . V_426 = 8 ;
V_11 -> V_78 = 64 ;
break;
}
}
static inline void F_112 ( struct V_10 * V_11 , unsigned int V_93 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_83 & V_274 ) {
case V_427 :
V_11 -> V_107 = V_428 ;
V_277 [ V_93 ] = L_90 ;
F_46 ( V_11 , V_25 ) ;
break;
}
}
static inline void F_113 ( struct V_10 * V_11 , unsigned int V_93 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_83 & V_274 ) {
case V_429 :
case V_430 :
V_11 -> V_107 = V_431 ;
V_277 [ V_93 ] = L_91 ;
F_39 ( V_93 , L_92 ) ;
break;
case V_432 :
case V_433 :
case V_434 :
V_11 -> V_107 = V_435 ;
V_277 [ V_93 ] = L_93 ;
F_39 ( V_93 , L_94 ) ;
break;
case V_436 : {
int V_437 = V_11 -> V_83 & V_84 ;
if ( V_437 >= V_438 &&
V_437 <= V_439 ) {
V_11 -> V_107 = V_440 ;
V_277 [ V_93 ] = L_95 ;
F_39 ( V_93 , L_96 ) ;
V_11 -> V_35 |= V_157 ;
} else {
V_11 -> V_107 = V_441 ;
V_277 [ V_93 ] = L_97 ;
F_39 ( V_93 , L_98 ) ;
}
break;
}
case V_442 :
case V_443 :
V_11 -> V_107 = V_444 ;
if ( ( V_11 -> V_83 & V_274 ) == V_443 )
V_277 [ V_93 ] = L_99 ;
else
V_277 [ V_93 ] = L_100 ;
F_39 ( V_93 , L_101 ) ;
V_11 -> V_35 |= V_174 | V_157 ;
break;
}
}
static inline void F_114 ( struct V_10 * V_11 , unsigned int V_93 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_83 & V_274 ) {
case V_445 :
case V_446 :
case V_447 :
V_11 -> V_107 = V_448 ;
V_277 [ V_93 ] = L_102 ;
goto V_449;
case V_450 :
case V_451 :
case V_452 :
case V_453 :
V_11 -> V_107 = V_454 ;
V_277 [ V_93 ] = L_103 ;
V_449:
F_39 ( V_93 , L_104 ) ;
break;
case V_455 :
case V_456 :
case V_457 :
case V_458 :
case V_459 :
V_11 -> V_107 = V_460 ;
V_277 [ V_93 ] = L_105 ;
F_39 ( V_93 , L_106 ) ;
break;
case V_461 :
case V_462 :
case V_463 :
case V_464 :
V_11 -> V_107 = V_465 ;
V_277 [ V_93 ] = L_107 ;
F_39 ( V_93 , L_108 ) ;
break;
default:
F_104 ( V_315 L_109 ) ;
V_11 -> V_107 = V_466 ;
break;
}
}
static inline void F_115 ( struct V_10 * V_11 , unsigned int V_93 )
{
switch ( V_11 -> V_83 & V_274 ) {
case V_357 :
switch ( V_11 -> V_83 & V_84 ) {
case V_467 :
V_11 -> V_107 = V_117 ;
V_277 [ V_93 ] = L_49 ;
F_39 ( V_93 , L_50 ) ;
F_46 ( V_11 , V_28 ) ;
break;
case V_468 :
V_11 -> V_107 = V_117 ;
V_277 [ V_93 ] = L_49 ;
F_39 ( V_93 , L_50 ) ;
F_46 ( V_11 , V_28 ) ;
break;
}
F_70 ( V_11 ) ;
V_11 -> V_35 |= V_129 | V_198 | V_469 ;
V_11 -> V_364 = V_365 ;
break;
default:
F_53 ( L_110 ) ;
break;
}
}
static inline void F_116 ( struct V_10 * V_11 , unsigned int V_93 )
{
F_70 ( V_11 ) ;
V_11 -> V_35 &= ~ V_236 ;
F_71 ( ! F_117 ( V_470 ) || V_470 ) ;
switch ( V_11 -> V_83 & V_274 ) {
case V_471 :
V_11 -> V_107 = V_472 ;
V_11 -> V_364 = V_365 ;
V_277 [ V_93 ] = L_111 ;
break;
default:
F_53 ( L_112 ) ;
break;
}
}
static inline void F_118 ( struct V_10 * V_11 , int V_93 )
{
F_70 ( V_11 ) ;
if ( ( V_11 -> V_83 & V_274 ) == V_473 ) {
V_11 -> V_107 = V_419 ;
V_277 [ V_93 ] = L_113 ;
return;
}
V_11 -> V_35 = ( V_127 |
V_234 |
V_236 |
V_237 |
V_141 |
V_145 |
V_238 ) ;
switch ( V_11 -> V_83 & V_274 ) {
case V_474 :
case V_475 :
case V_476 :
V_11 -> V_107 = V_477 ;
V_277 [ V_93 ] = L_114 ;
break;
case V_478 :
case V_479 :
V_11 -> V_107 = V_477 ;
V_277 [ V_93 ] = L_115 ;
break;
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
case V_486 :
case V_487 :
V_11 -> V_107 = V_488 ;
V_277 [ V_93 ] = L_116 ;
break;
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
case V_494 :
case V_495 :
case V_496 :
case V_497 :
case V_498 :
case V_499 :
case V_500 :
case V_501 :
V_11 -> V_107 = V_488 ;
V_277 [ V_93 ] = L_117 ;
break;
default:
F_29 ( L_118 ,
V_11 -> V_83 ) ;
V_11 -> V_107 = V_488 ;
break;
}
if ( V_11 -> V_107 == V_477 ) {
F_46 ( V_11 , V_28 ) ;
V_11 -> V_35 |= ( V_49 | V_174 | V_239 ) ;
V_11 -> V_78 = ( ( F_48 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_46 ( V_11 , V_26 ) ;
V_11 -> V_78 = ( ( F_55 () >> 25 ) & 0x3f ) + 1 ;
}
V_11 -> V_212 = 0xf ;
}
void F_119 ( void )
{
struct V_10 * V_11 = & V_81 ;
unsigned int V_93 = F_120 () ;
F_39 ( V_93 , L_119 ) ;
V_11 -> V_83 = V_502 ;
V_11 -> V_2 = V_6 ;
V_11 -> V_107 = V_466 ;
V_11 -> V_364 = V_370 ;
V_11 -> V_17 = V_503 ;
V_11 -> V_23 = V_504 | V_33 | V_34 ;
V_11 -> V_83 = F_121 () ;
switch ( V_11 -> V_83 & V_505 ) {
case V_506 :
F_103 ( V_11 , V_93 ) ;
break;
case V_507 :
F_106 ( V_11 , V_93 ) ;
break;
case V_508 :
F_109 ( V_11 , V_93 ) ;
break;
case V_509 :
F_110 ( V_11 , V_93 ) ;
break;
case V_510 :
F_113 ( V_11 , V_93 ) ;
break;
case V_511 :
F_111 ( V_11 , V_93 ) ;
break;
case V_512 :
F_112 ( V_11 , V_93 ) ;
break;
case V_513 :
F_114 ( V_11 , V_93 ) ;
break;
case V_514 :
F_115 ( V_11 , V_93 ) ;
break;
case V_515 :
case V_516 :
case V_517 :
F_116 ( V_11 , V_93 ) ;
break;
case V_518 :
F_118 ( V_11 , V_93 ) ;
break;
}
F_71 ( ! V_277 [ V_93 ] ) ;
F_71 ( V_11 -> V_107 == V_466 ) ;
F_71 ( F_31 () != V_11 -> V_107 ) ;
if ( V_519 ) {
F_122 ( V_520 ) ;
F_43 () ;
if ( F_123 () & V_520 )
V_11 -> V_35 |= V_521 ;
}
if ( V_64 )
V_11 -> V_35 &= ~ V_49 ;
if ( V_68 )
V_11 -> V_58 &= ~ ( V_66 | V_67 ) ;
if ( V_69 ) {
V_11 -> V_35 &= ~ V_70 ;
F_23 ( F_24 () &
~ ( 1 << V_71 ) ) ;
}
if ( V_11 -> V_35 & V_49 )
F_18 ( V_11 ) ;
else
F_19 ( V_11 ) ;
if ( V_522 )
F_124 ( F_125 () |
V_523 ) ;
if ( V_240 ) {
V_11 -> V_524 = ( ( F_126 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_35 |= V_525 ;
}
else
V_11 -> V_524 = 1 ;
if ( V_163 )
V_526 |= V_527 ;
if ( V_528 ) {
V_11 -> V_8 = F_7 () ;
F_127 ( V_11 -> V_8 & V_529 ,
L_120 ) ;
V_526 |= V_530 ;
}
if ( V_531 )
F_102 ( V_11 ) ;
F_40 ( V_11 ) ;
#ifdef F_128
if ( V_93 == 0 )
V_532 = ~ ( ( 1ull << V_533 ) - 1 ) ;
#endif
}
void F_129 ( void )
{
struct V_10 * V_11 = & V_81 ;
F_29 ( L_121 ,
F_120 () , V_11 -> V_83 , F_130 () ) ;
if ( V_11 -> V_35 & V_49 )
F_104 ( V_315 L_122 , V_11 -> V_2 ) ;
if ( V_528 )
F_29 ( L_123 , V_11 -> V_8 ) ;
}
