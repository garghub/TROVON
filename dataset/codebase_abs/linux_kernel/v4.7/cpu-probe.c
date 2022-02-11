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
case V_107 :
V_103 = F_48 () ;
V_103 &= ~ ( 3 << V_108 ) ;
if ( V_102 )
F_49 ( V_103 |
( F_47 ( V_11 )
<< V_108 )
| V_109 ) ;
else
F_49 ( V_103 & ~ V_109 ) ;
break;
case V_110 :
V_103 = F_34 () ;
V_103 &= ~ ( 3 << V_111 ) ;
F_33 ( V_103 | ( F_47 ( V_11 )
<< V_111 ) ) ;
break;
case V_112 :
F_50 ( V_113 | V_114 |
V_115 | V_116 ) ;
V_103 = F_48 () ;
if ( V_102 )
F_49 ( V_103 & ~ V_117 ) ;
else
F_49 ( V_103 | V_117 ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static inline unsigned int F_51 ( struct V_10 * V_11 )
{
unsigned int V_118 ;
int V_95 , V_119 ;
V_118 = F_52 () ;
V_119 = V_118 & V_120 ;
if ( V_119 == V_121 )
V_11 -> V_35 |= V_122 ;
else if ( V_119 == V_123 )
V_11 -> V_35 |= V_122 | V_124 ;
V_95 = ( V_118 & V_125 ) >> 13 ;
switch ( V_95 ) {
case 0 :
switch ( ( V_118 & V_126 ) >> 10 ) {
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
goto V_127;
}
break;
case 2 :
switch ( ( V_118 & V_126 ) >> 10 ) {
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
goto V_127;
}
break;
default:
goto V_127;
}
return V_118 & V_128 ;
V_127:
F_53 ( V_129 , V_118 ) ;
}
static inline unsigned int F_54 ( struct V_10 * V_11 )
{
unsigned int V_130 ;
V_130 = F_55 () ;
if ( V_130 & V_131 )
V_11 -> V_58 |= V_132 ;
if ( V_130 & V_133 )
V_11 -> V_35 |= V_134 ;
if ( V_130 & V_135 )
V_11 -> V_35 |= V_136 ;
if ( V_130 & V_137 )
V_11 -> V_58 |= V_138 ;
if ( V_130 & V_139 )
V_11 -> V_35 |= V_140 ;
if ( V_130 & V_141 ) {
V_11 -> V_35 |= V_49 ;
V_11 -> V_35 |= V_142 ;
}
if ( V_143 ) {
V_11 -> V_76 = ( ( V_130 & V_144 ) >> 25 ) + 1 ;
V_11 -> V_101 = V_11 -> V_76 ;
V_11 -> V_78 = 0 ;
}
return V_130 & V_128 ;
}
static inline unsigned int F_56 ( struct V_10 * V_11 )
{
unsigned int V_145 ;
V_145 = F_57 () ;
if ( V_145 & V_146 )
V_11 -> V_147 . V_148 &= ~ V_149 ;
return V_145 & V_128 ;
}
static inline unsigned int F_58 ( struct V_10 * V_11 )
{
unsigned int V_150 ;
V_150 = F_59 () ;
if ( V_150 & V_151 ) {
V_11 -> V_58 |= V_152 ;
V_11 -> V_35 |= V_153 | V_154 ;
}
if ( V_150 & V_155 )
V_11 -> V_35 |= V_153 ;
if ( V_150 & V_156 )
V_11 -> V_35 |= V_154 ;
if ( V_150 & V_157 )
V_11 -> V_58 |= V_64 ;
if ( V_150 & V_158 ) {
V_11 -> V_58 |= V_65 ;
if ( V_159 )
V_11 -> V_58 |= V_160 ;
}
if ( V_150 & V_161 )
V_11 -> V_35 |= V_162 ;
if ( V_150 & V_163 )
V_11 -> V_35 |= V_164 ;
if ( V_150 & V_165 )
V_11 -> V_35 |= V_166 ;
if ( V_150 & V_167 )
V_11 -> V_58 |= V_168 ;
if ( V_150 & V_169 )
V_11 -> V_35 |= V_170 ;
if ( V_150 & V_171 )
V_11 -> V_35 |= V_172 ;
if ( V_150 & V_173 )
V_11 -> V_58 |= V_174 ;
if ( V_150 & V_175 )
V_11 -> V_35 |= V_176 ;
if ( V_150 & V_177 )
V_11 -> V_35 |= V_178 ;
if ( V_150 & V_179 )
V_11 -> V_35 |= V_180 ;
if ( V_150 & V_181 )
V_11 -> V_58 |= V_182 ;
if ( V_150 & V_183 ) {
V_11 -> V_184 = 0 ;
V_11 -> V_35 |= V_68 ;
}
if ( V_150 & V_185 )
V_11 -> V_35 |= V_186 ;
if ( V_150 & V_187 )
V_11 -> V_35 |= V_188 ;
return V_150 & V_128 ;
}
static inline unsigned int F_60 ( struct V_10 * V_11 )
{
unsigned int V_70 ;
unsigned int V_189 ;
unsigned int V_71 ;
unsigned int V_190 = V_191 ;
unsigned long V_192 ;
V_70 = F_29 () ;
if ( V_143 ) {
if ( ( ( V_70 & V_193 ) >> 29 ) == 2 )
V_11 -> V_35 |= V_194 ;
if ( ! V_159 )
V_71 = V_70 & V_73 ;
else if ( V_195 )
V_71 = V_196 ;
else
V_71 = 0 ;
switch ( V_71 ) {
case V_197 :
V_11 -> V_76 += ( V_70 & V_198 ) * 0x40 ;
V_11 -> V_101 = V_11 -> V_76 ;
break;
case V_196 :
V_11 -> V_101 +=
( ( V_70 & V_199 ) >>
V_200 ) * 0x40 ;
V_11 -> V_76 = V_11 -> V_101 ;
V_190 = V_201 ;
case V_74 :
if ( V_75 )
break;
V_189 = ( V_70 & ~ V_190 ) |
( F_61 ( V_71 ) <<
V_202 ) ;
F_62 ( V_189 ) ;
F_28 () ;
V_70 = F_29 () ;
if ( V_70 != V_189 ) {
F_63 ( L_8 ,
V_203 , V_70 ) ;
F_26 ( V_11 , 0 ) ;
break;
}
V_11 -> V_78 = 1 <<
( ( V_70 & V_204 ) >>
V_205 ) ;
V_11 -> V_77 = ( ( V_70 & V_206 ) >>
V_207 ) + 2 ;
V_11 -> V_76 += V_11 -> V_77 * V_11 -> V_78 ;
V_72 = 1 ;
break;
}
}
V_11 -> V_208 = ( V_70 & V_209 )
>> V_210 ;
V_192 = V_211 ;
if ( V_70 & V_212 )
V_192 |= V_213 ;
F_64 ( V_11 , V_192 ) ;
F_65 ( V_192 != F_66 ( V_11 ) ) ;
return V_70 & V_128 ;
}
static inline unsigned int F_67 ( struct V_10 * V_11 )
{
unsigned int V_214 ;
V_214 = F_68 () ;
V_214 &= ~ ( V_215 | V_216 ) ;
F_69 ( V_214 ) ;
if ( V_214 & V_217 )
V_11 -> V_35 |= V_218 ;
if ( V_214 & V_219 )
V_11 -> V_35 |= V_220 ;
if ( V_214 & V_221 )
V_11 -> V_35 |= V_222 ;
if ( V_214 & V_223 )
V_11 -> V_35 |= V_224 ;
if ( V_159 && ( V_214 & V_225 ) )
V_11 -> V_35 |= V_226 ;
return V_214 & V_128 ;
}
static void F_70 ( struct V_10 * V_11 )
{
int V_227 ;
V_11 -> V_35 = V_228 | V_229 | V_230 |
V_231 | V_232 | V_233 ;
V_11 -> V_147 . V_148 = V_149 ;
F_26 ( V_11 , ! V_75 ) ;
V_227 = F_51 ( V_11 ) ;
F_71 ( ! V_227 ) ;
if ( V_227 )
V_227 = F_54 ( V_11 ) ;
if ( V_227 )
V_227 = F_56 ( V_11 ) ;
if ( V_227 )
V_227 = F_58 ( V_11 ) ;
if ( V_227 )
V_227 = F_60 ( V_11 ) ;
if ( V_227 )
V_227 = F_67 ( V_11 ) ;
if ( V_234 ) {
T_3 V_235 ;
unsigned int V_7 ;
V_235 = V_236 ? F_72 ()
: ( V_237 ) F_73 () ;
if ( V_235 & V_238 ) {
V_11 -> V_35 |= V_239 ;
} else {
V_7 = F_2 () ;
F_5 ( V_7 | V_240 ) ;
F_74 () ;
if ( V_236 )
F_75 ( V_235 | V_238 ) ;
else
F_76 ( V_235 | V_238 ) ;
F_28 () ;
F_5 ( V_7 ) ;
if ( F_73 () & V_238 ) {
V_11 -> V_35 |= V_239 ;
F_76 ( V_235 ) ;
}
}
}
F_77 ( V_11 ) ;
#ifndef F_78
if ( V_234 ) {
V_11 -> V_241 = F_79 () ;
if ( V_242 )
V_11 -> V_241 >>= F_80 ( F_81 () ) - 1 ;
}
#endif
}
static inline unsigned int F_82 ( struct V_10 * V_11 )
{
unsigned int V_118 ;
F_83 ( V_103 , V_118 , V_128 ) ;
if ( V_118 & V_128 )
V_11 -> V_243 . V_244 |= F_84 ( 1 ) ;
return V_118 & V_128 ;
}
static inline unsigned int F_85 ( struct V_10 * V_11 )
{
unsigned int V_130 , V_245 ;
F_86 ( V_130 , V_130 , V_245 ,
V_128 | V_133 | V_135 |
V_141 ) ;
if ( V_130 & V_141 )
V_11 -> V_243 . V_35 |= V_49 ;
if ( V_245 & V_141 )
V_11 -> V_243 . V_246 |= V_49 ;
if ( V_130 & V_135 )
V_11 -> V_243 . V_35 |= V_136 ;
if ( V_245 & V_135 )
V_11 -> V_243 . V_246 |= V_136 ;
if ( V_130 & V_133 )
V_11 -> V_243 . V_35 |= V_134 ;
if ( V_245 & V_133 )
V_11 -> V_243 . V_246 |= V_134 ;
if ( V_130 & V_128 )
V_11 -> V_243 . V_244 |= F_84 ( 2 ) ;
return V_130 & V_128 ;
}
static inline unsigned int F_87 ( struct V_10 * V_11 )
{
unsigned int V_145 ;
F_83 ( V_145 , V_145 , V_128 ) ;
if ( V_145 & V_128 )
V_11 -> V_243 . V_244 |= F_84 ( 3 ) ;
return V_145 & V_128 ;
}
static inline unsigned int F_88 ( struct V_10 * V_11 )
{
unsigned int V_150 , V_247 ;
F_86 ( V_150 , V_150 , V_247 ,
V_128 | V_181 | V_156 ) ;
if ( V_150 & V_156 )
V_11 -> V_243 . V_35 |= V_154 ;
if ( V_247 & V_156 )
V_11 -> V_243 . V_246 |= V_154 ;
if ( V_150 & V_183 )
V_11 -> V_243 . V_35 |= V_68 ;
if ( V_150 & V_175 )
V_11 -> V_243 . V_35 |= V_176 ;
if ( V_150 & V_177 )
V_11 -> V_243 . V_35 |= V_178 ;
if ( V_150 & V_179 )
V_11 -> V_243 . V_35 |= V_180 ;
if ( V_150 & V_181 )
V_11 -> V_243 . V_58 |= V_182 ;
if ( V_247 & V_181 )
V_11 -> V_243 . V_248 |= V_182 ;
if ( V_150 & V_128 )
V_11 -> V_243 . V_244 |= F_84 ( 4 ) ;
return V_150 & V_128 ;
}
static inline unsigned int F_89 ( struct V_10 * V_11 )
{
unsigned int V_70 ;
F_83 ( V_70 , V_70 ,
V_128 | V_209 ) ;
V_11 -> V_243 . V_208 = ( V_70 & V_209 )
>> V_210 ;
if ( V_70 & V_128 )
V_11 -> V_243 . V_244 |= F_84 ( 5 ) ;
return V_70 & V_128 ;
}
static inline unsigned int F_90 ( struct V_10 * V_11 )
{
unsigned int V_214 , V_249 ;
F_86 ( V_214 , V_214 , V_249 ,
V_128 | V_219 ) ;
if ( V_214 & V_219 )
V_11 -> V_243 . V_35 |= V_220 ;
if ( V_249 & V_219 )
V_11 -> V_243 . V_246 |= V_220 ;
if ( V_214 & V_221 )
V_11 -> V_243 . V_35 |= V_222 ;
if ( V_214 & V_128 )
V_11 -> V_243 . V_244 |= F_84 ( 6 ) ;
return V_214 & V_128 ;
}
static inline void F_91 ( struct V_10 * V_11 )
{
unsigned int V_227 ;
V_227 = F_82 ( V_11 ) ;
if ( V_227 )
V_227 = F_85 ( V_11 ) ;
if ( V_227 )
V_227 = F_87 ( V_11 ) ;
if ( V_227 )
V_227 = F_88 ( V_11 ) ;
if ( V_227 )
V_227 = F_89 ( V_11 ) ;
if ( V_227 )
F_90 ( V_11 ) ;
}
static inline void F_92 ( struct V_10 * V_11 )
{
unsigned int V_250 , V_251 ;
V_250 = F_93 () ;
if ( V_250 & V_252 )
V_11 -> V_35 |= V_253 ;
if ( V_250 & V_254 )
V_11 -> V_35 |= V_255 ;
if ( V_250 & V_256 )
V_11 -> V_35 |= V_257 ;
if ( ! ( V_250 & V_258 ) ) {
V_11 -> V_35 |= V_259 ;
F_94 ( 0 ) ;
F_95 () ;
F_96 ( V_250 | V_260 ) ;
F_28 () ;
V_251 = F_93 () ;
if ( V_251 & V_260 ) {
F_96 ( V_250 ) ;
V_11 -> V_35 |= V_261 ;
}
}
}
static inline void F_97 ( struct V_10 * V_11 )
{
if ( V_262 ) {
F_94 ( V_263 ) ;
F_28 () ;
V_11 -> V_264 = ( F_98 () & V_263 )
>> V_265 ;
F_94 ( 0 ) ;
}
}
static inline void F_99 ( struct V_10 * V_11 )
{
F_100 ( 0xffffffff ) ;
F_28 () ;
V_11 -> V_266 = F_101 () ;
F_100 ( 0 ) ;
}
static inline void F_102 ( struct V_10 * V_11 )
{
F_92 ( V_11 ) ;
if ( V_267 )
F_97 ( V_11 ) ;
F_99 ( V_11 ) ;
F_91 ( V_11 ) ;
}
static inline void F_103 ( struct V_10 * V_11 , unsigned int V_91 )
{
switch ( V_11 -> V_81 & V_268 ) {
case V_269 :
V_11 -> V_104 = V_270 ;
V_271 [ V_91 ] = L_9 ;
V_11 -> V_23 |= V_272 | V_273 ;
V_11 -> V_35 = V_122 | V_274 |
V_275 ;
if ( F_6 () )
V_11 -> V_35 |= V_49 ;
V_11 -> V_76 = 64 ;
break;
case V_276 :
if ( ( V_11 -> V_81 & V_82 ) == V_277 ) {
if ( F_36 () ) {
V_11 -> V_104 = V_278 ;
V_271 [ V_91 ] = L_10 ;
} else {
V_11 -> V_104 = V_279 ;
V_271 [ V_91 ] = L_11 ;
}
} else {
V_11 -> V_104 = V_280 ;
V_271 [ V_91 ] = L_12 ;
}
V_11 -> V_23 |= V_272 | V_273 ;
V_11 -> V_35 = V_122 | V_274 |
V_275 ;
if ( F_6 () )
V_11 -> V_35 |= V_49 ;
V_11 -> V_76 = 64 ;
break;
case V_281 :
if ( F_52 () & V_282 ) {
if ( ( V_11 -> V_81 & V_82 ) >=
V_283 ) {
V_11 -> V_104 = V_284 ;
V_271 [ V_91 ] = L_13 ;
} else {
V_11 -> V_104 = V_285 ;
V_271 [ V_91 ] = L_14 ;
}
} else {
int V_286 = F_52 () & V_287 ;
int V_288 ;
switch ( V_286 ) {
case V_289 :
case V_290 :
case V_291 :
V_288 = 1 ;
break;
default:
V_288 = 0 ;
break;
}
if ( ( V_11 -> V_81 & V_82 ) >=
V_283 ) {
V_11 -> V_104 = V_288 ? V_292 : V_293 ;
V_271 [ V_91 ] = V_288 ? L_15 : L_16 ;
} else {
V_11 -> V_104 = V_288 ? V_294 : V_295 ;
V_271 [ V_91 ] = V_288 ? L_17 : L_18 ;
}
}
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_272 ;
V_11 -> V_35 = V_296 | V_49 | V_142 |
V_136 | V_297 |
V_232 ;
V_11 -> V_76 = 48 ;
break;
case V_298 :
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_272 ;
V_11 -> V_35 = V_296 ;
V_11 -> V_76 = 32 ;
switch ( V_11 -> V_81 & 0xf0 ) {
case V_299 :
V_11 -> V_104 = V_300 ;
V_271 [ V_91 ] = L_19 ;
break;
case V_301 :
V_11 -> V_104 = V_302 ;
V_271 [ V_91 ] = L_20 ;
break;
case V_303 :
if ( ( V_11 -> V_81 & 0xf ) < 0x3 ) {
V_11 -> V_104 = V_304 ;
V_271 [ V_91 ] = L_21 ;
} else {
V_11 -> V_104 = V_305 ;
V_271 [ V_91 ] = L_22 ;
}
break;
case V_306 :
if ( ( V_11 -> V_81 & 0xf ) < 0x4 ) {
V_11 -> V_104 = V_307 ;
V_271 [ V_91 ] = L_23 ;
} else {
V_11 -> V_104 = V_308 ;
V_11 -> V_35 |= V_232 ;
V_271 [ V_91 ] = L_24 ;
}
break;
default:
F_104 ( V_309 L_25 ) ;
V_11 -> V_104 = V_310 ;
V_271 [ V_91 ] = L_26 ;
break;
}
break;
case V_311 :
V_11 -> V_104 = V_312 ;
V_271 [ V_91 ] = L_27 ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_272 ;
V_11 -> V_35 = V_296 | V_49 | V_142 |
V_232 ;
V_11 -> V_76 = 32 ;
break;
case V_313 :
V_11 -> V_104 = V_314 ;
V_271 [ V_91 ] = L_28 ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_272 ;
V_11 -> V_35 = V_296 | V_49 | V_142 |
V_232 ;
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
case V_315 :
V_11 -> V_23 |= V_272 | V_273 ;
V_11 -> V_35 = V_122 | V_316 ;
if ( ( V_11 -> V_81 & 0xf0 ) == ( V_317 & 0xf0 ) ) {
V_11 -> V_104 = V_318 ;
V_271 [ V_91 ] = L_29 ;
V_11 -> V_76 = 64 ;
} else {
switch ( V_11 -> V_81 & V_82 ) {
case V_319 :
V_11 -> V_104 = V_320 ;
V_271 [ V_91 ] = L_30 ;
V_11 -> V_76 = 32 ;
break;
case V_321 :
V_11 -> V_104 = V_322 ;
V_271 [ V_91 ] = L_31 ;
V_11 -> V_76 = 64 ;
break;
}
}
break;
case V_323 :
V_11 -> V_104 = V_324 ;
V_271 [ V_91 ] = L_32 ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_272 ;
V_11 -> V_35 = V_296 | V_49 | V_142 |
V_232 ;
V_11 -> V_76 = 48 ;
break;
case V_325 :
V_11 -> V_104 = V_326 ;
V_271 [ V_91 ] = L_33 ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_272 ;
V_11 -> V_35 = V_296 | V_232 ;
if ( ! ( V_11 -> V_81 & 0x08 ) )
V_11 -> V_35 |= V_49 | V_142 ;
V_11 -> V_76 = 48 ;
break;
case V_327 :
V_11 -> V_104 = V_328 ;
V_271 [ V_91 ] = L_34 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_296 | V_49 | V_142 |
V_232 ;
V_11 -> V_76 = 48 ;
break;
case V_329 :
V_11 -> V_104 = V_330 ;
V_271 [ V_91 ] = L_35 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_296 | V_49 | V_142 |
V_136 | V_232 ;
V_11 -> V_76 = 48 ;
break;
case V_331 :
V_11 -> V_104 = V_332 ;
V_271 [ V_91 ] = L_36 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_296 | V_49 | V_142 |
V_136 | V_232 ;
V_11 -> V_76 = 48 ;
break;
case V_333 :
V_11 -> V_104 = V_334 ;
V_271 [ V_91 ] = L_37 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_296 | V_49 | V_142 |
V_231 | V_232 ;
V_11 -> V_76 = 48 ;
break;
case V_335 :
V_11 -> V_104 = V_336 ;
V_271 [ V_91 ] = L_38 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_23 |= V_272 | V_273 ;
V_11 -> V_35 = V_122 | V_49 |
V_232 ;
V_11 -> V_76 = 32 ;
break;
case V_337 :
V_11 -> V_104 = V_338 ;
V_271 [ V_91 ] = L_39 ;
F_46 ( V_11 , V_99 ) ;
V_11 -> V_23 |= V_272 | V_273 ;
V_11 -> V_35 = V_122 | V_49 |
V_232 ;
V_11 -> V_76 = 32 ;
break;
case V_339 :
V_11 -> V_104 = V_340 ;
V_271 [ V_91 ] = L_40 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_296 | V_49 | V_142 |
V_232 ;
V_11 -> V_76 = ( F_105 () & ( 1 << 29 ) ) ? 64 : 48 ;
break;
case V_341 :
V_11 -> V_104 = V_342 ;
V_271 [ V_91 ] = L_41 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_122 | V_228 |
V_49 | V_142 |
V_232 ;
V_11 -> V_76 = 384 ;
break;
case V_343 :
V_11 -> V_104 = V_344 ;
V_271 [ V_91 ] = L_42 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_122 | V_229 | V_228 |
V_49 | V_142 |
V_230 | V_136 |
V_232 ;
V_11 -> V_76 = 64 ;
break;
case V_345 :
V_11 -> V_104 = V_346 ;
V_271 [ V_91 ] = L_43 ;
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_122 | V_229 | V_228 |
V_49 | V_142 |
V_230 | V_136 |
V_232 | V_347 ;
V_11 -> V_76 = 64 ;
break;
case V_348 :
if ( ( ( V_11 -> V_81 >> 4 ) & 0x0f ) > 2 ) {
V_11 -> V_104 = V_349 ;
V_271 [ V_91 ] = L_44 ;
} else {
V_11 -> V_104 = V_350 ;
V_271 [ V_91 ] = L_45 ;
}
F_46 ( V_11 , V_97 ) ;
V_11 -> V_35 = V_122 | V_229 | V_228 |
V_49 | V_142 |
V_230 | V_136 |
V_232 | V_347 ;
V_11 -> V_76 = 64 ;
break;
case V_351 :
switch ( V_11 -> V_81 & V_82 ) {
case V_352 :
V_11 -> V_104 = V_353 ;
V_271 [ V_91 ] = L_46 ;
F_40 ( V_91 , L_47 ) ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_272 ;
break;
case V_354 :
V_11 -> V_104 = V_353 ;
V_271 [ V_91 ] = L_46 ;
F_40 ( V_91 , L_48 ) ;
F_46 ( V_11 , V_98 ) ;
V_11 -> V_23 |= V_272 ;
break;
case V_355 :
V_11 -> V_104 = V_112 ;
V_271 [ V_91 ] = L_49 ;
F_40 ( V_91 , L_50 ) ;
F_46 ( V_11 , V_26 ) ;
break;
case V_356 :
case V_357 :
V_11 -> V_104 = V_112 ;
V_271 [ V_91 ] = L_49 ;
F_40 ( V_91 , L_51 ) ;
F_46 ( V_11 , V_26 ) ;
break;
}
V_11 -> V_35 = V_296 |
V_49 | V_232 |
V_142 ;
V_11 -> V_76 = 64 ;
V_11 -> V_358 = V_359 ;
break;
case V_360 :
F_70 ( V_11 ) ;
V_11 -> V_104 = V_361 ;
switch ( V_11 -> V_81 & V_82 ) {
case V_362 :
V_271 [ V_91 ] = L_52 ;
break;
}
break;
}
}
static inline void F_106 ( struct V_10 * V_11 , unsigned int V_91 )
{
V_11 -> V_358 = V_359 ;
switch ( V_11 -> V_81 & V_268 ) {
case V_363 :
V_11 -> V_358 = V_364 ;
V_11 -> V_104 = V_365 ;
V_271 [ V_91 ] = L_53 ;
break;
case V_366 :
V_11 -> V_104 = V_367 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_54 ;
break;
case V_368 :
case V_369 :
V_11 -> V_104 = V_370 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_55 ;
break;
case V_371 :
case V_372 :
V_11 -> V_104 = V_373 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_56 ;
break;
case V_374 :
V_11 -> V_104 = V_375 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_57 ;
break;
case V_376 :
V_11 -> V_104 = V_377 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_58 ;
break;
case V_378 :
V_11 -> V_104 = V_379 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_59 ;
break;
case V_380 :
V_11 -> V_104 = V_381 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_60 ;
break;
case V_382 :
V_11 -> V_104 = V_381 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_61 ;
break;
case V_383 :
V_11 -> V_104 = V_384 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_62 ;
break;
case V_385 :
V_11 -> V_104 = V_80 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_63 ;
break;
case V_386 :
V_11 -> V_104 = V_387 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_64 ;
break;
case V_388 :
V_11 -> V_104 = V_389 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_65 ;
break;
case V_390 :
V_11 -> V_104 = V_391 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_66 ;
break;
case V_392 :
V_11 -> V_104 = V_393 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_67 ;
break;
case V_394 :
V_11 -> V_104 = V_395 ;
V_11 -> V_358 = V_364 ;
V_271 [ V_91 ] = L_68 ;
break;
case V_396 :
V_11 -> V_104 = V_397 ;
V_271 [ V_91 ] = L_69 ;
break;
case V_398 :
V_11 -> V_104 = V_397 ;
V_271 [ V_91 ] = L_70 ;
break;
case V_399 :
V_11 -> V_104 = V_105 ;
V_271 [ V_91 ] = L_71 ;
break;
case V_400 :
V_11 -> V_104 = V_105 ;
V_271 [ V_91 ] = L_72 ;
break;
case V_401 :
V_11 -> V_104 = V_106 ;
V_271 [ V_91 ] = L_73 ;
break;
case V_402 :
V_11 -> V_104 = V_107 ;
V_271 [ V_91 ] = L_74 ;
break;
case V_403 :
V_11 -> V_104 = V_110 ;
V_271 [ V_91 ] = L_75 ;
break;
case V_404 :
V_11 -> V_104 = V_405 ;
V_271 [ V_91 ] = L_76 ;
break;
case V_406 :
V_11 -> V_104 = V_407 ;
V_271 [ V_91 ] = L_77 ;
break;
}
F_70 ( V_11 ) ;
F_107 () ;
}
static inline void F_108 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_81 & V_268 ) {
case V_408 :
case V_409 :
V_11 -> V_104 = V_410 ;
switch ( ( V_11 -> V_81 >> 24 ) & 0xff ) {
case 0 :
V_271 [ V_91 ] = L_78 ;
break;
case 1 :
V_271 [ V_91 ] = L_79 ;
break;
case 2 :
V_271 [ V_91 ] = L_80 ;
break;
case 3 :
V_271 [ V_91 ] = L_81 ;
break;
case 4 :
V_271 [ V_91 ] = L_82 ;
if ( ( V_11 -> V_81 & V_82 ) == 2 )
V_271 [ V_91 ] = L_83 ;
break;
case 5 :
V_271 [ V_91 ] = L_84 ;
break;
default:
V_271 [ V_91 ] = L_85 ;
break;
}
break;
}
}
static inline void F_109 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_70 ( V_11 ) ;
V_11 -> V_358 = V_359 ;
switch ( V_11 -> V_81 & V_268 ) {
case V_411 :
V_11 -> V_104 = V_412 ;
V_271 [ V_91 ] = L_86 ;
if ( ( V_11 -> V_81 & V_82 ) < 0x02 )
V_11 -> V_35 &= ~ ( V_49 | V_142 ) ;
break;
case V_413 :
V_11 -> V_104 = V_414 ;
V_271 [ V_91 ] = L_87 ;
break;
}
}
static inline void F_110 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_81 & V_268 ) {
case V_415 :
V_11 -> V_104 = V_416 ;
V_271 [ V_91 ] = L_88 ;
V_11 -> V_147 . V_417 = 8 ;
V_11 -> V_76 = 64 ;
break;
}
}
static inline void F_111 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_81 & V_268 ) {
case V_418 :
V_11 -> V_104 = V_419 ;
V_271 [ V_91 ] = L_89 ;
F_46 ( V_11 , V_25 ) ;
break;
}
}
static inline void F_112 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_81 & V_268 ) {
case V_420 :
case V_421 :
V_11 -> V_104 = V_422 ;
V_271 [ V_91 ] = L_90 ;
F_40 ( V_91 , L_91 ) ;
break;
case V_423 :
case V_424 :
case V_425 :
V_11 -> V_104 = V_426 ;
V_271 [ V_91 ] = L_92 ;
F_40 ( V_91 , L_93 ) ;
break;
case V_427 : {
int V_428 = V_11 -> V_81 & V_82 ;
if ( V_428 >= V_429 &&
V_428 <= V_430 ) {
V_11 -> V_104 = V_431 ;
V_271 [ V_91 ] = L_94 ;
F_40 ( V_91 , L_95 ) ;
V_11 -> V_35 |= V_153 ;
} else {
V_11 -> V_104 = V_432 ;
V_271 [ V_91 ] = L_96 ;
F_40 ( V_91 , L_97 ) ;
}
break;
}
case V_433 :
case V_434 :
V_11 -> V_104 = V_435 ;
if ( ( V_11 -> V_81 & V_268 ) == V_434 )
V_271 [ V_91 ] = L_98 ;
else
V_271 [ V_91 ] = L_99 ;
F_40 ( V_91 , L_100 ) ;
V_11 -> V_35 |= V_170 | V_153 ;
break;
}
}
static inline void F_113 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_70 ( V_11 ) ;
switch ( V_11 -> V_81 & V_268 ) {
case V_436 :
case V_437 :
case V_438 :
V_11 -> V_104 = V_439 ;
V_271 [ V_91 ] = L_101 ;
goto V_440;
case V_441 :
case V_442 :
case V_443 :
case V_444 :
V_11 -> V_104 = V_445 ;
V_271 [ V_91 ] = L_102 ;
V_440:
F_40 ( V_91 , L_103 ) ;
break;
case V_446 :
case V_447 :
case V_448 :
case V_449 :
case V_450 :
V_11 -> V_104 = V_451 ;
V_271 [ V_91 ] = L_104 ;
F_40 ( V_91 , L_105 ) ;
break;
case V_452 :
case V_453 :
case V_454 :
case V_455 :
V_11 -> V_104 = V_456 ;
V_271 [ V_91 ] = L_106 ;
F_40 ( V_91 , L_107 ) ;
break;
default:
F_104 ( V_309 L_108 ) ;
V_11 -> V_104 = V_457 ;
break;
}
}
static inline void F_114 ( struct V_10 * V_11 , unsigned int V_91 )
{
switch ( V_11 -> V_81 & V_268 ) {
case V_351 :
switch ( V_11 -> V_81 & V_82 ) {
case V_458 :
V_11 -> V_104 = V_112 ;
V_271 [ V_91 ] = L_49 ;
F_40 ( V_91 , L_50 ) ;
F_46 ( V_11 , V_28 ) ;
break;
}
F_70 ( V_11 ) ;
V_11 -> V_35 |= V_194 | V_459 ;
V_11 -> V_358 = V_359 ;
break;
default:
F_53 ( L_109 ) ;
break;
}
}
static inline void F_115 ( struct V_10 * V_11 , unsigned int V_91 )
{
F_70 ( V_11 ) ;
V_11 -> V_35 &= ~ V_230 ;
F_71 ( ! F_116 ( V_460 ) || V_460 ) ;
switch ( V_11 -> V_81 & V_268 ) {
case V_461 :
V_11 -> V_104 = V_462 ;
V_11 -> V_358 = V_359 ;
V_271 [ V_91 ] = L_110 ;
break;
default:
F_53 ( L_111 ) ;
break;
}
}
static inline void F_117 ( struct V_10 * V_11 , int V_91 )
{
F_70 ( V_11 ) ;
if ( ( V_11 -> V_81 & V_268 ) == V_463 ) {
V_11 -> V_104 = V_410 ;
V_271 [ V_91 ] = L_112 ;
return;
}
V_11 -> V_35 = ( V_122 |
V_228 |
V_230 |
V_231 |
V_136 |
V_140 |
V_232 ) ;
switch ( V_11 -> V_81 & V_268 ) {
case V_464 :
case V_465 :
case V_466 :
V_11 -> V_104 = V_467 ;
V_271 [ V_91 ] = L_113 ;
break;
case V_468 :
case V_469 :
V_11 -> V_104 = V_467 ;
V_271 [ V_91 ] = L_114 ;
break;
case V_470 :
case V_471 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_477 :
V_11 -> V_104 = V_478 ;
V_271 [ V_91 ] = L_115 ;
break;
case V_479 :
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_488 :
case V_489 :
case V_490 :
case V_491 :
V_11 -> V_104 = V_478 ;
V_271 [ V_91 ] = L_116 ;
break;
default:
F_30 ( L_117 ,
V_11 -> V_81 ) ;
V_11 -> V_104 = V_478 ;
break;
}
if ( V_11 -> V_104 == V_467 ) {
F_46 ( V_11 , V_28 ) ;
V_11 -> V_35 |= ( V_49 | V_170 | V_233 ) ;
V_11 -> V_76 = ( ( F_48 () >> 16 ) & 0xffff ) + 1 ;
} else {
F_46 ( V_11 , V_26 ) ;
V_11 -> V_76 = ( ( F_55 () >> 25 ) & 0x3f ) + 1 ;
}
V_11 -> V_208 = 0xf ;
}
void F_118 ( void )
{
struct V_10 * V_11 = & V_79 ;
unsigned int V_91 = F_119 () ;
V_11 -> V_81 = V_492 ;
V_11 -> V_2 = V_6 ;
V_11 -> V_104 = V_457 ;
V_11 -> V_358 = V_364 ;
V_11 -> V_17 = V_493 ;
V_11 -> V_23 = V_494 | V_33 | V_34 ;
V_11 -> V_81 = F_120 () ;
switch ( V_11 -> V_81 & V_495 ) {
case V_496 :
F_103 ( V_11 , V_91 ) ;
break;
case V_497 :
F_106 ( V_11 , V_91 ) ;
break;
case V_498 :
F_108 ( V_11 , V_91 ) ;
break;
case V_499 :
F_109 ( V_11 , V_91 ) ;
break;
case V_500 :
F_112 ( V_11 , V_91 ) ;
break;
case V_501 :
F_110 ( V_11 , V_91 ) ;
break;
case V_502 :
F_111 ( V_11 , V_91 ) ;
break;
case V_503 :
F_113 ( V_11 , V_91 ) ;
break;
case V_504 :
F_114 ( V_11 , V_91 ) ;
break;
case V_505 :
case V_506 :
case V_507 :
F_115 ( V_11 , V_91 ) ;
break;
case V_508 :
F_117 ( V_11 , V_91 ) ;
break;
}
F_71 ( ! V_271 [ V_91 ] ) ;
F_71 ( V_11 -> V_104 == V_457 ) ;
F_71 ( F_32 () != V_11 -> V_104 ) ;
if ( V_509 ) {
F_121 ( V_510 ) ;
F_28 () ;
if ( F_122 () & V_510 )
V_11 -> V_35 |= V_511 ;
}
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
if ( V_512 )
F_123 ( F_124 () |
V_513 ) ;
if ( V_234 ) {
V_11 -> V_514 = ( ( F_125 () >> 26 ) & 0x0f ) + 1 ;
V_11 -> V_35 |= V_515 ;
}
else
V_11 -> V_514 = 1 ;
if ( V_159 )
V_516 |= V_517 ;
if ( V_518 ) {
V_11 -> V_8 = F_7 () ;
F_126 ( V_11 -> V_8 & V_519 ,
L_118 ) ;
V_516 |= V_520 ;
}
if ( V_521 )
F_102 ( V_11 ) ;
F_41 ( V_11 ) ;
#ifdef F_127
if ( V_91 == 0 )
V_522 = ~ ( ( 1ull << V_523 ) - 1 ) ;
#endif
}
void F_128 ( void )
{
struct V_10 * V_11 = & V_79 ;
F_30 ( L_119 ,
F_119 () , V_11 -> V_81 , F_129 () ) ;
if ( V_11 -> V_35 & V_49 )
F_104 ( V_309 L_120 , V_11 -> V_2 ) ;
if ( V_518 )
F_30 ( L_121 , V_11 -> V_8 ) ;
}
