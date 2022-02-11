int F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 . V_4 ) || F_2 ( V_2 ) ;
}
int F_3 ( struct V_1 * V_5 )
{
return 1 ;
}
int F_4 ( struct V_1 * V_5 )
{
int V_6 ;
F_5 ( F_6 () ) ;
F_7 () ;
while ( true ) {
if ( F_8 () ) {
F_9 () ;
F_10 () ;
F_7 () ;
continue;
}
if ( F_11 ( V_7 ) ) {
F_12 ( V_5 , V_8 ) ;
V_5 -> V_9 -> V_10 = V_11 ;
V_6 = - V_12 ;
break;
}
V_5 -> V_13 = V_14 ;
F_13 () ;
if ( F_2 ( V_5 ) ) {
F_9 () ;
F_14 ( V_5 ) ;
V_6 = F_15 ( V_5 ) ;
F_7 () ;
if ( V_6 > 0 )
continue;
break;
}
if ( F_16 ( V_5 ) ) {
continue;
}
F_17 () ;
return 1 ;
}
F_9 () ;
return V_6 ;
}
static void F_18 ( struct V_1 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_3 . V_16 ;
int V_17 ;
V_16 -> V_18 = F_19 ( V_16 -> V_18 ) ;
V_16 -> V_19 = F_19 ( V_16 -> V_19 ) ;
V_16 -> V_20 = F_19 ( V_16 -> V_20 ) ;
V_16 -> V_21 = F_19 ( V_16 -> V_21 ) ;
V_16 -> V_22 = F_19 ( V_16 -> V_22 ) ;
V_16 -> V_23 = F_19 ( V_16 -> V_23 ) ;
V_16 -> V_24 = F_19 ( V_16 -> V_24 ) ;
V_16 -> V_25 = F_19 ( V_16 -> V_25 ) ;
V_16 -> V_26 = F_20 ( V_16 -> V_26 ) ;
V_16 -> V_27 = F_20 ( V_16 -> V_27 ) ;
for ( V_17 = 0 ; V_17 < F_21 ( V_16 -> V_28 ) ; V_17 ++ )
V_16 -> V_28 [ V_17 ] = F_20 ( V_16 -> V_28 [ V_17 ] ) ;
}
int F_22 ( struct V_1 * V_5 )
{
int V_29 = F_23 ( V_5 , 11 ) ;
int V_6 ;
unsigned long T_1 V_30 = F_23 ( V_5 , 3 ) ;
unsigned long T_1 V_31 = F_23 ( V_5 , 4 ) ;
unsigned long T_1 V_32 = F_23 ( V_5 , 5 ) ;
unsigned long T_1 V_33 = F_23 ( V_5 , 6 ) ;
unsigned long V_34 = 0 ;
if ( ! ( F_24 ( V_5 ) & V_35 ) ) {
V_30 &= 0xffffffff ;
V_31 &= 0xffffffff ;
V_32 &= 0xffffffff ;
V_33 &= 0xffffffff ;
}
switch ( V_29 ) {
case F_25 ( V_36 ) :
{
#if F_26 ( V_37 ) && F_26 ( V_38 )
int V_39 = true ;
if ( V_5 -> V_3 . V_40 & V_41 )
V_39 = false ;
if ( V_39 != V_5 -> V_3 . V_39 )
F_18 ( V_5 ) ;
V_5 -> V_3 . V_39 = V_39 ;
#endif
if ( ! ( V_31 & V_42 ) ) {
V_5 -> V_3 . V_43 = true ;
F_27 ( V_44 , V_5 ) ;
}
V_5 -> V_3 . V_45 = V_30 & ~ 0xfffULL ;
V_5 -> V_3 . V_46 = V_31 & ~ 0xfffULL ;
#ifdef F_28
if ( ( V_5 -> V_3 . V_45 & 0xf000 ) !=
( ( V_47 ) V_5 -> V_3 . V_16 & 0xf000 ) ) {
void * V_48 = V_5 -> V_3 . V_16 ;
V_47 V_16 = ( V_47 ) V_5 -> V_3 . V_16 ;
void * V_49 ;
V_16 &= V_50 ;
V_16 |= V_5 -> V_3 . V_45 & 0xf000 ;
V_49 = ( void * ) V_16 ;
memcpy ( V_49 , V_48 , 0x1000 ) ;
V_5 -> V_3 . V_16 = V_49 ;
}
#endif
V_34 = V_51 | V_52 ;
V_6 = V_53 ;
break;
}
case F_25 ( V_54 ) :
V_6 = V_53 ;
#if F_26 ( V_55 ) || F_26 ( V_56 )
V_34 |= ( 1 << V_57 ) ;
#endif
break;
case F_29 ( V_58 ) :
V_6 = V_53 ;
F_30 ( V_5 ) ;
F_31 ( V_59 , V_5 ) ;
break;
default:
V_6 = V_60 ;
break;
}
F_32 ( V_5 , 4 , V_34 ) ;
return V_6 ;
}
int F_33 ( struct V_1 * V_5 )
{
int V_6 = false ;
if ( ! V_5 -> V_3 . V_61 )
goto V_62;
if ( ( V_5 -> V_3 . V_63 != V_64 ) && V_5 -> V_3 . V_65 )
goto V_62;
if ( ! V_5 -> V_3 . V_65 && F_34 ( V_5 -> V_66 ) )
goto V_62;
#ifdef F_35
if ( ! F_36 ( V_67 ) )
goto V_62;
#endif
V_6 = true ;
V_62:
V_5 -> V_3 . V_68 = V_6 ;
return V_6 ? 0 : - V_69 ;
}
int F_37 ( struct V_70 * V_9 , struct V_1 * V_5 )
{
enum V_71 V_72 ;
int V_6 ;
V_72 = F_38 ( V_5 ) ;
switch ( V_72 ) {
case V_73 :
V_6 = V_74 ;
break;
case V_75 :
V_6 = V_76 ;
break;
case V_77 :
V_9 -> V_10 = V_78 ;
V_6 = V_79 ;
break;
case V_80 :
{
T_2 V_81 ;
F_39 ( V_5 , V_82 , & V_81 ) ;
F_40 ( L_1 , V_83 , V_81 ) ;
V_6 = V_84 ;
break;
}
default:
F_5 ( 1 ) ;
V_6 = V_76 ;
}
return V_6 ;
}
int F_41 ( struct V_1 * V_5 , V_47 * V_85 , int V_86 , void * V_87 ,
bool V_88 )
{
V_47 V_89 = V_5 -> V_3 . V_45 & V_90 & V_50 ;
struct V_91 V_92 ;
int V_6 ;
V_5 -> V_93 . V_94 ++ ;
V_6 = F_42 ( V_5 , * V_85 , V_88 ? V_95 : V_96 ,
V_97 , & V_92 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_85 = V_92 . V_98 ;
if ( ! V_92 . V_99 )
return - V_100 ;
if ( F_43 ( V_5 ) && V_89 &&
( ( V_92 . V_98 & V_90 & V_50 ) == V_89 ) &&
! ( F_24 ( V_5 ) & V_101 ) ) {
void * V_102 = V_5 -> V_3 . V_16 ;
V_102 += V_92 . V_85 & 0xfff ;
memcpy ( V_102 , V_87 , V_86 ) ;
return V_73 ;
}
if ( F_44 ( V_5 -> V_66 , V_92 . V_98 , V_87 , V_86 ) )
return V_77 ;
return V_73 ;
}
int F_45 ( struct V_1 * V_5 , V_47 * V_85 , int V_86 , void * V_87 ,
bool V_88 )
{
V_47 V_89 = V_5 -> V_3 . V_45 & V_90 & V_50 ;
struct V_91 V_92 ;
int V_103 ;
V_5 -> V_93 . V_104 ++ ;
V_103 = F_42 ( V_5 , * V_85 , V_88 ? V_95 : V_96 ,
V_105 , & V_92 ) ;
if ( V_103 )
return V_103 ;
* V_85 = V_92 . V_98 ;
if ( ! V_92 . V_106 )
return - V_100 ;
if ( ! V_88 && ! V_92 . V_107 )
return - V_108 ;
if ( F_43 ( V_5 ) && V_89 &&
( ( V_92 . V_98 & V_90 & V_50 ) == V_89 ) &&
! ( F_24 ( V_5 ) & V_101 ) ) {
void * V_102 = V_5 -> V_3 . V_16 ;
V_102 += V_92 . V_85 & 0xfff ;
memcpy ( V_87 , V_102 , V_86 ) ;
return V_73 ;
}
if ( F_46 ( V_5 -> V_66 , V_92 . V_98 , V_87 , V_86 ) )
return V_77 ;
return V_73 ;
}
int F_47 ( void )
{
return 0 ;
}
int F_48 ( void )
{
return 0 ;
}
void F_49 ( void * V_109 )
{
* ( int * ) V_109 = F_50 () ;
}
int F_51 ( struct V_66 * V_66 , unsigned long type )
{
struct V_110 * V_111 = NULL ;
if ( type == 0 ) {
if ( V_112 )
V_111 = V_112 ;
else
V_111 = V_113 ;
if ( ! V_111 )
goto V_114;
} else if ( type == V_115 ) {
if ( ! V_112 )
goto V_114;
V_111 = V_112 ;
} else if ( type == V_116 ) {
if ( ! V_113 )
goto V_114;
V_111 = V_113 ;
} else
goto V_114;
if ( V_111 -> V_117 && ! F_52 ( V_111 -> V_117 ) )
return - V_118 ;
V_66 -> V_3 . V_111 = V_111 ;
return F_53 ( V_66 ) ;
V_114:
return - V_69 ;
}
bool F_54 ( void )
{
return false ;
}
int F_55 ( struct V_1 * V_5 )
{
return 0 ;
}
void F_56 ( struct V_66 * V_66 )
{
unsigned int V_17 ;
struct V_1 * V_5 ;
#ifdef F_57
if ( F_34 ( V_66 ) )
F_58 () ;
#endif
F_59 (i, vcpu, kvm)
F_60 ( V_5 ) ;
F_61 ( & V_66 -> V_119 ) ;
for ( V_17 = 0 ; V_17 < F_62 ( & V_66 -> V_120 ) ; V_17 ++ )
V_66 -> V_121 [ V_17 ] = NULL ;
F_63 ( & V_66 -> V_120 , 0 ) ;
F_64 ( V_66 ) ;
F_65 ( & V_66 -> V_119 ) ;
F_66 ( V_66 -> V_3 . V_111 -> V_117 ) ;
}
int F_67 ( struct V_66 * V_66 , long V_122 )
{
int V_6 ;
int V_123 = V_112 ? 1 : 0 ;
if ( V_66 ) {
V_123 = F_34 ( V_66 ) ;
}
switch ( V_122 ) {
#ifdef F_68
case V_124 :
case V_125 :
case V_126 :
#else
case V_127 :
case V_128 :
case V_129 :
#endif
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_6 = 1 ;
break;
case V_138 :
case V_139 :
case V_140 :
#if F_26 ( V_56 ) || F_26 ( V_141 )
case V_142 :
#endif
V_6 = ! V_123 ;
break;
#ifdef F_69
case V_143 :
V_6 = 1 ;
break;
#endif
#ifdef V_37
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
#ifdef F_57
case V_150 :
#endif
V_6 = 1 ;
break;
case V_151 :
V_6 = V_123 ;
break;
#endif
#ifdef F_70
case V_152 :
V_6 = 0 ;
if ( V_66 ) {
if ( V_66 -> V_3 . V_153 > 1 )
V_6 = V_66 -> V_3 . V_153 ;
else
V_6 = V_66 -> V_3 . V_154 ;
} else if ( V_123 ) {
if ( F_36 ( V_155 ) )
V_6 = 1 ;
else
V_6 = V_156 ;
}
break;
case V_157 :
V_6 = 1 ;
if ( V_123 ) {
if ( ! F_36 ( V_155 ) )
V_6 = ( ( V_156 << 1 ) - 1 ) ;
else
V_6 = 8 | 4 | 2 | 1 ;
}
break;
case V_158 :
V_6 = 0 ;
break;
case V_159 :
V_6 = F_71 () ;
break;
case V_160 :
V_6 = ! ! ( V_123 && F_72 () ) ;
break;
case V_161 :
V_6 = ! ! ( V_123 && ! F_72 () &&
F_36 ( V_155 ) ) ;
break;
#endif
case V_162 :
#ifdef F_70
V_6 = V_123 ;
#elif F_26 ( V_163 )
V_6 = 1 ;
#else
V_6 = 0 ;
#endif
break;
#ifdef F_70
case V_164 :
V_6 = V_123 ;
break;
#endif
case V_165 :
if ( V_123 )
V_6 = F_73 () ;
else
V_6 = F_74 () ;
break;
case V_166 :
V_6 = V_167 ;
break;
case V_168 :
V_6 = V_169 ;
break;
#ifdef V_37
case V_170 :
V_6 = 1 ;
break;
case V_171 :
V_6 = 1 ;
break;
case V_172 :
V_6 = ! ! V_123 && ! F_36 ( V_155 ) ;
break;
#endif
#ifdef F_70
case V_173 :
V_6 = V_123 ;
break;
#endif
case V_174 :
V_6 = F_36 ( V_175 ) &&
F_34 ( V_66 ) ;
break;
default:
V_6 = 0 ;
break;
}
return V_6 ;
}
long F_75 ( struct V_176 * V_177 ,
unsigned int V_178 , unsigned long V_179 )
{
return - V_69 ;
}
void F_76 ( struct V_66 * V_66 , struct V_180 * free ,
struct V_180 * V_181 )
{
F_77 ( V_66 , free , V_181 ) ;
}
int F_78 ( struct V_66 * V_66 , struct V_180 * V_182 ,
unsigned long V_183 )
{
return F_79 ( V_66 , V_182 , V_183 ) ;
}
int F_80 ( struct V_66 * V_66 ,
struct V_180 * V_184 ,
const struct V_185 * V_186 ,
enum V_187 V_188 )
{
return F_81 ( V_66 , V_184 , V_186 ) ;
}
void F_82 ( struct V_66 * V_66 ,
const struct V_185 * V_186 ,
const struct V_180 * V_189 ,
const struct V_180 * V_190 ,
enum V_187 V_188 )
{
F_83 ( V_66 , V_186 , V_189 , V_190 ) ;
}
void F_84 ( struct V_66 * V_66 ,
struct V_180 * V_182 )
{
F_85 ( V_66 , V_182 ) ;
}
struct V_1 * F_86 ( struct V_66 * V_66 , unsigned int V_191 )
{
struct V_1 * V_5 ;
V_5 = F_87 ( V_66 , V_191 ) ;
if ( ! F_88 ( V_5 ) ) {
V_5 -> V_3 . V_192 = & V_5 -> V_193 ;
F_89 ( V_5 , V_191 ) ;
}
return V_5 ;
}
void F_90 ( struct V_1 * V_5 )
{
}
void F_60 ( struct V_1 * V_5 )
{
F_91 ( & V_5 -> V_3 . V_194 ) ;
F_92 ( V_5 ) ;
switch ( V_5 -> V_3 . V_195 ) {
case V_196 :
F_93 ( V_5 -> V_3 . V_197 , V_5 ) ;
break;
case V_198 :
if ( F_94 () )
F_95 ( V_5 ) ;
else
F_96 ( V_5 ) ;
break;
}
F_97 ( V_5 ) ;
}
void F_98 ( struct V_1 * V_5 )
{
F_60 ( V_5 ) ;
}
int F_99 ( struct V_1 * V_5 )
{
return F_100 ( V_5 ) ;
}
static enum V_199 F_101 ( struct V_200 * V_201 )
{
struct V_1 * V_5 ;
V_5 = F_102 ( V_201 , struct V_1 , V_3 . V_194 ) ;
F_103 ( V_5 ) ;
return V_202 ;
}
int F_104 ( struct V_1 * V_5 )
{
int V_203 ;
F_105 ( & V_5 -> V_3 . V_194 , V_204 , V_205 ) ;
V_5 -> V_3 . V_194 . V_206 = F_101 ;
V_5 -> V_3 . V_207 = ~ ( V_208 ) 0 ;
#ifdef F_106
F_107 ( & V_5 -> V_3 . V_209 ) ;
#endif
V_203 = F_108 ( V_5 ) ;
return V_203 ;
}
void F_109 ( struct V_1 * V_5 )
{
F_110 ( V_5 ) ;
F_111 ( V_5 ) ;
}
void F_112 ( struct V_1 * V_5 , int V_210 )
{
#ifdef F_68
F_113 ( V_211 , V_5 -> V_3 . V_212 ) ;
#endif
F_114 ( V_5 , V_210 ) ;
}
void F_115 ( struct V_1 * V_5 )
{
F_116 ( V_5 ) ;
#ifdef F_68
V_5 -> V_3 . V_212 = F_117 ( V_211 ) ;
#endif
}
bool F_118 ( void )
{
return ( ( V_112 && V_112 -> V_213 ) ||
( V_113 && V_113 -> V_213 ) ) ;
}
int F_119 ( struct V_214 * V_215 ,
struct V_216 * V_217 )
{
struct V_218 * V_219 =
F_102 ( V_215 , struct V_218 , V_220 ) ;
struct V_66 * V_66 = V_219 -> V_66 ;
if ( V_66 -> V_3 . V_111 -> V_213 )
return V_66 -> V_3 . V_111 -> V_213 ( V_215 , V_217 ) ;
return 0 ;
}
void F_120 ( struct V_214 * V_215 ,
struct V_216 * V_217 )
{
struct V_218 * V_219 =
F_102 ( V_215 , struct V_218 , V_220 ) ;
struct V_66 * V_66 = V_219 -> V_66 ;
if ( V_66 -> V_3 . V_111 -> V_221 )
V_66 -> V_3 . V_111 -> V_221 ( V_215 , V_217 ) ;
}
static inline int F_121 ( int V_222 )
{
int V_223 ;
if ( ( V_222 != 0 ) && ( V_222 != 1 ) )
return - 1 ;
#ifdef F_122
V_223 = V_222 ;
#else
V_223 = 1 - V_222 ;
#endif
return V_223 ;
}
static inline int F_123 ( int V_222 )
{
int V_223 ;
if ( ( V_222 > 3 ) || ( V_222 < 0 ) )
return - 1 ;
#ifdef F_122
V_223 = V_222 ;
#else
V_223 = 3 - V_222 ;
#endif
return V_223 ;
}
static inline void F_124 ( struct V_1 * V_5 ,
V_208 V_224 )
{
union V_225 V_226 ;
int V_223 = F_121 ( V_5 -> V_3 . V_227 ) ;
int V_222 = V_5 -> V_3 . V_228 & V_229 ;
if ( V_223 == - 1 )
return;
if ( V_5 -> V_3 . V_230 ) {
V_226 . V_231 = F_125 ( V_5 , V_222 ) ;
V_226 . V_232 [ V_223 ] = V_224 ;
F_125 ( V_5 , V_222 ) = V_226 . V_231 ;
} else {
F_126 ( V_5 , V_222 , V_223 ) = V_224 ;
}
}
static inline void F_127 ( struct V_1 * V_5 ,
V_208 V_224 )
{
union V_225 V_226 ;
int V_222 = V_5 -> V_3 . V_228 & V_229 ;
if ( V_5 -> V_3 . V_230 ) {
V_226 . V_231 = F_125 ( V_5 , V_222 ) ;
V_226 . V_232 [ 0 ] = V_224 ;
V_226 . V_232 [ 1 ] = V_224 ;
F_125 ( V_5 , V_222 ) = V_226 . V_231 ;
} else {
F_126 ( V_5 , V_222 , 0 ) = V_224 ;
F_126 ( V_5 , V_222 , 1 ) = V_224 ;
}
}
static inline void F_128 ( struct V_1 * V_5 ,
T_2 V_233 )
{
union V_225 V_226 ;
int V_223 = F_123 ( V_5 -> V_3 . V_227 ) ;
int V_222 = V_5 -> V_3 . V_228 & V_229 ;
int V_234 , V_235 ;
if ( V_223 == - 1 )
return;
if ( V_5 -> V_3 . V_230 ) {
V_226 . V_231 = F_125 ( V_5 , V_222 ) ;
V_226 . V_236 [ V_223 ] = V_233 ;
F_125 ( V_5 , V_222 ) = V_226 . V_231 ;
} else {
V_234 = V_223 / 2 ;
V_235 = V_223 % 2 ;
V_226 . V_232 [ 0 ] = F_126 ( V_5 , V_222 , V_234 ) ;
V_226 . V_236 [ V_235 ] = V_233 ;
F_126 ( V_5 , V_222 , V_234 ) = V_226 . V_232 [ 0 ] ;
}
}
static inline V_208 F_129 ( T_2 V_237 )
{
V_208 V_238 ;
F_130 () ;
F_131 () ;
asm ("lfs%U1%X1 0,%1; stfd%U0%X0 0,%0" : "=m" (fprd) : "m" (fprs)
: "fr0");
F_132 () ;
return V_238 ;
}
static inline T_2 F_133 ( V_208 V_238 )
{
T_2 V_237 ;
F_130 () ;
F_131 () ;
asm ("lfd%U1%X1 0,%1; stfs%U0%X0 0,%0" : "=m" (fprs) : "m" (fprd)
: "fr0");
F_132 () ;
return V_237 ;
}
static void F_134 ( struct V_1 * V_5 ,
struct V_70 * V_9 )
{
V_208 V_239 ( V_224 ) ;
if ( V_9 -> V_240 . V_241 > sizeof( V_224 ) ) {
F_135 ( V_242 L_2 , V_9 -> V_240 . V_241 ) ;
return;
}
if ( ! V_5 -> V_3 . V_243 ) {
switch ( V_9 -> V_240 . V_241 ) {
case 8 : V_224 = * ( V_208 * ) V_9 -> V_240 . V_88 ; break;
case 4 : V_224 = * ( T_2 * ) V_9 -> V_240 . V_88 ; break;
case 2 : V_224 = * ( V_244 * ) V_9 -> V_240 . V_88 ; break;
case 1 : V_224 = * ( V_245 * ) V_9 -> V_240 . V_88 ; break;
}
} else {
switch ( V_9 -> V_240 . V_241 ) {
case 8 : V_224 = F_19 ( * ( V_208 * ) V_9 -> V_240 . V_88 ) ; break;
case 4 : V_224 = F_20 ( * ( T_2 * ) V_9 -> V_240 . V_88 ) ; break;
case 2 : V_224 = F_136 ( * ( V_244 * ) V_9 -> V_240 . V_88 ) ; break;
case 1 : V_224 = * ( V_245 * ) V_9 -> V_240 . V_88 ; break;
}
}
if ( ( V_5 -> V_3 . V_246 ) && ( V_9 -> V_240 . V_241 == 4 ) )
V_224 = F_129 ( V_224 ) ;
if ( V_5 -> V_3 . V_247 ) {
switch ( V_9 -> V_240 . V_241 ) {
#ifdef F_137
case 4 :
V_224 = ( V_248 ) ( V_249 ) V_224 ;
break;
#endif
case 2 :
V_224 = ( V_248 ) ( V_250 ) V_224 ;
break;
case 1 :
V_224 = ( V_248 ) ( V_251 ) V_224 ;
break;
}
}
switch ( V_5 -> V_3 . V_228 & V_252 ) {
case V_253 :
F_32 ( V_5 , V_5 -> V_3 . V_228 , V_224 ) ;
break;
case V_254 :
F_138 ( V_5 , V_5 -> V_3 . V_228 & V_229 ) = V_224 ;
break;
#ifdef V_55
case V_255 :
V_5 -> V_3 . V_256 [ V_5 -> V_3 . V_228 & V_229 ] = V_224 ;
break;
case V_257 :
F_138 ( V_5 , V_5 -> V_3 . V_228 & V_229 ) = V_224 ;
V_5 -> V_3 . V_256 [ V_5 -> V_3 . V_228 & V_229 ] = V_224 ;
break;
#endif
#ifdef F_139
case V_258 :
if ( V_5 -> V_3 . V_259 == V_260 )
F_124 ( V_5 , V_224 ) ;
else if ( V_5 -> V_3 . V_259 == V_261 )
F_128 ( V_5 , V_224 ) ;
else if ( V_5 -> V_3 . V_259 ==
V_262 )
F_127 ( V_5 , V_224 ) ;
break;
#endif
default:
F_140 () ;
}
}
static int F_141 ( struct V_70 * V_9 , struct V_1 * V_5 ,
unsigned int V_263 , unsigned int V_264 ,
int V_265 , int V_266 )
{
int V_267 , V_203 ;
bool V_268 ;
if ( F_142 ( V_5 ) ) {
V_268 = V_265 ;
} else {
V_268 = ! V_265 ;
}
if ( V_264 > sizeof( V_9 -> V_240 . V_88 ) ) {
F_135 ( V_242 L_3 , V_83 ,
V_9 -> V_240 . V_241 ) ;
}
V_9 -> V_240 . V_269 = V_5 -> V_3 . V_270 ;
V_9 -> V_240 . V_241 = V_264 ;
V_9 -> V_240 . V_271 = 0 ;
V_5 -> V_3 . V_228 = V_263 ;
V_5 -> V_3 . V_243 = V_268 ;
V_5 -> V_272 = 1 ;
V_5 -> V_273 = 0 ;
V_5 -> V_3 . V_247 = V_266 ;
V_267 = F_143 ( & V_5 -> V_66 -> V_274 ) ;
V_203 = F_144 ( V_5 , V_275 , V_9 -> V_240 . V_269 ,
V_264 , & V_9 -> V_240 . V_88 ) ;
F_145 ( & V_5 -> V_66 -> V_274 , V_267 ) ;
if ( ! V_203 ) {
F_134 ( V_5 , V_9 ) ;
V_5 -> V_272 = 0 ;
return V_73 ;
}
return V_77 ;
}
int F_146 ( struct V_70 * V_9 , struct V_1 * V_5 ,
unsigned int V_263 , unsigned int V_264 ,
int V_265 )
{
return F_141 ( V_9 , V_5 , V_263 , V_264 , V_265 , 0 ) ;
}
int F_147 ( struct V_70 * V_9 , struct V_1 * V_5 ,
unsigned int V_263 , unsigned int V_264 ,
int V_265 )
{
return F_141 ( V_9 , V_5 , V_263 , V_264 , V_265 , 1 ) ;
}
int F_148 ( struct V_70 * V_9 , struct V_1 * V_5 ,
unsigned int V_263 , unsigned int V_264 ,
int V_265 , int V_247 )
{
enum V_71 V_276 = V_73 ;
if ( ( V_5 -> V_3 . V_277 > 4 ) ||
( V_5 -> V_3 . V_277 < 0 ) ) {
return V_80 ;
}
while ( V_5 -> V_3 . V_277 ) {
V_276 = F_141 ( V_9 , V_5 , V_263 , V_264 ,
V_265 , V_247 ) ;
if ( V_276 != V_73 )
break;
V_5 -> V_3 . V_270 += V_9 -> V_240 . V_241 ;
V_5 -> V_3 . V_277 -- ;
V_5 -> V_3 . V_227 ++ ;
}
return V_276 ;
}
int F_149 ( struct V_70 * V_9 , struct V_1 * V_5 ,
V_208 V_226 , unsigned int V_264 , int V_265 )
{
void * V_88 = V_9 -> V_240 . V_88 ;
int V_267 , V_203 ;
bool V_268 ;
if ( F_142 ( V_5 ) ) {
V_268 = V_265 ;
} else {
V_268 = ! V_265 ;
}
if ( V_264 > sizeof( V_9 -> V_240 . V_88 ) ) {
F_135 ( V_242 L_3 , V_83 ,
V_9 -> V_240 . V_241 ) ;
}
V_9 -> V_240 . V_269 = V_5 -> V_3 . V_270 ;
V_9 -> V_240 . V_241 = V_264 ;
V_9 -> V_240 . V_271 = 1 ;
V_5 -> V_272 = 1 ;
V_5 -> V_273 = 1 ;
if ( ( V_5 -> V_3 . V_246 ) && ( V_264 == 4 ) )
V_226 = F_133 ( V_226 ) ;
if ( ! V_268 ) {
switch ( V_264 ) {
case 8 : * ( V_208 * ) V_88 = V_226 ; break;
case 4 : * ( T_2 * ) V_88 = V_226 ; break;
case 2 : * ( V_244 * ) V_88 = V_226 ; break;
case 1 : * ( V_245 * ) V_88 = V_226 ; break;
}
} else {
switch ( V_264 ) {
case 8 : * ( V_208 * ) V_88 = F_19 ( V_226 ) ; break;
case 4 : * ( T_2 * ) V_88 = F_20 ( V_226 ) ; break;
case 2 : * ( V_244 * ) V_88 = F_136 ( V_226 ) ; break;
case 1 : * ( V_245 * ) V_88 = V_226 ; break;
}
}
V_267 = F_143 ( & V_5 -> V_66 -> V_274 ) ;
V_203 = F_150 ( V_5 , V_275 , V_9 -> V_240 . V_269 ,
V_264 , & V_9 -> V_240 . V_88 ) ;
F_145 ( & V_5 -> V_66 -> V_274 , V_267 ) ;
if ( ! V_203 ) {
V_5 -> V_272 = 0 ;
return V_73 ;
}
return V_77 ;
}
static inline int F_151 ( struct V_1 * V_5 , int V_278 , V_208 * V_226 )
{
T_2 V_234 , V_235 ;
union V_225 V_279 ;
int V_280 = 0 ;
int V_281 = V_5 -> V_3 . V_259 ;
int V_282 = 0 ;
switch ( V_281 ) {
case V_260 :
V_280 =
F_121 ( V_5 -> V_3 . V_227 ) ;
if ( V_280 == - 1 ) {
V_282 = - 1 ;
break;
}
if ( ! V_5 -> V_3 . V_230 ) {
* V_226 = F_126 ( V_5 , V_278 , V_280 ) ;
} else {
V_279 . V_231 = F_125 ( V_5 , V_278 ) ;
* V_226 = V_279 . V_232 [ V_280 ] ;
}
break;
case V_261 :
V_280 =
F_123 ( V_5 -> V_3 . V_227 ) ;
if ( V_280 == - 1 ) {
V_282 = - 1 ;
break;
}
if ( ! V_5 -> V_3 . V_230 ) {
V_234 = V_280 / 2 ;
V_235 = V_280 % 2 ;
V_279 . V_232 [ 0 ] = F_126 ( V_5 , V_278 , V_234 ) ;
* V_226 = V_279 . V_236 [ V_235 ] ;
} else {
V_279 . V_231 = F_125 ( V_5 , V_278 ) ;
* V_226 = V_279 . V_236 [ V_280 ] ;
}
break;
default:
V_282 = - 1 ;
break;
}
return V_282 ;
}
int F_152 ( struct V_70 * V_9 , struct V_1 * V_5 ,
int V_278 , unsigned int V_264 , int V_265 )
{
V_208 V_226 ;
enum V_71 V_276 = V_73 ;
V_5 -> V_3 . V_228 = V_278 ;
if ( ( V_5 -> V_3 . V_277 > 4 ) ||
( V_5 -> V_3 . V_277 < 0 ) ) {
return V_80 ;
}
while ( V_5 -> V_3 . V_277 ) {
if ( F_151 ( V_5 , V_278 , & V_226 ) == - 1 )
return V_80 ;
V_276 = F_149 ( V_9 , V_5 ,
V_226 , V_264 , V_265 ) ;
if ( V_276 != V_73 )
break;
V_5 -> V_3 . V_270 += V_9 -> V_240 . V_241 ;
V_5 -> V_3 . V_277 -- ;
V_5 -> V_3 . V_227 ++ ;
}
return V_276 ;
}
static int F_153 ( struct V_1 * V_5 ,
struct V_70 * V_9 )
{
enum V_71 V_276 = V_80 ;
int V_6 ;
V_5 -> V_3 . V_270 += V_9 -> V_240 . V_241 ;
if ( ! V_5 -> V_273 ) {
V_276 = F_148 ( V_9 , V_5 , V_5 -> V_3 . V_228 ,
V_9 -> V_240 . V_241 , 1 , V_5 -> V_3 . V_247 ) ;
} else {
V_276 = F_152 ( V_9 , V_5 ,
V_5 -> V_3 . V_228 , V_9 -> V_240 . V_241 , 1 ) ;
}
switch ( V_276 ) {
case V_77 :
V_9 -> V_10 = V_78 ;
V_6 = V_84 ;
break;
case V_80 :
F_154 ( L_4 ) ;
V_9 -> V_10 = V_283 ;
V_9 -> V_284 . V_285 = V_286 ;
V_6 = V_84 ;
break;
default:
V_6 = V_76 ;
break;
}
return V_6 ;
}
int F_155 ( struct V_1 * V_5 , struct V_287 * V_279 )
{
int V_6 = 0 ;
union V_225 V_226 ;
int V_86 ;
V_86 = F_156 ( V_279 -> V_191 ) ;
if ( V_86 > sizeof( V_226 ) )
return - V_69 ;
V_6 = F_157 ( V_5 , V_279 -> V_191 , & V_226 ) ;
if ( V_6 == - V_69 ) {
V_6 = 0 ;
switch ( V_279 -> V_191 ) {
#ifdef F_158
case V_288 ... V_289 :
if ( ! F_36 ( V_290 ) ) {
V_6 = - V_291 ;
break;
}
V_226 . V_231 = V_5 -> V_3 . V_292 . V_292 [ V_279 -> V_191 - V_288 ] ;
break;
case V_293 :
if ( ! F_36 ( V_290 ) ) {
V_6 = - V_291 ;
break;
}
V_226 = F_159 ( V_279 -> V_191 , V_5 -> V_3 . V_292 . V_294 . V_295 [ 3 ] ) ;
break;
case V_296 :
V_226 = F_159 ( V_279 -> V_191 , V_5 -> V_3 . V_212 ) ;
break;
#endif
default:
V_6 = - V_69 ;
break;
}
}
if ( V_6 )
return V_6 ;
if ( F_160 ( ( char V_297 * ) ( unsigned long ) V_279 -> V_298 , & V_226 , V_86 ) )
V_6 = - V_299 ;
return V_6 ;
}
int F_161 ( struct V_1 * V_5 , struct V_287 * V_279 )
{
int V_6 ;
union V_225 V_226 ;
int V_86 ;
V_86 = F_156 ( V_279 -> V_191 ) ;
if ( V_86 > sizeof( V_226 ) )
return - V_69 ;
if ( F_162 ( & V_226 , ( char V_297 * ) ( unsigned long ) V_279 -> V_298 , V_86 ) )
return - V_299 ;
V_6 = F_163 ( V_5 , V_279 -> V_191 , & V_226 ) ;
if ( V_6 == - V_69 ) {
V_6 = 0 ;
switch ( V_279 -> V_191 ) {
#ifdef F_158
case V_288 ... V_289 :
if ( ! F_36 ( V_290 ) ) {
V_6 = - V_291 ;
break;
}
V_5 -> V_3 . V_292 . V_292 [ V_279 -> V_191 - V_288 ] = V_226 . V_231 ;
break;
case V_293 :
if ( ! F_36 ( V_290 ) ) {
V_6 = - V_291 ;
break;
}
V_5 -> V_3 . V_292 . V_294 . V_295 [ 3 ] = F_164 ( V_279 -> V_191 , V_226 ) ;
break;
case V_296 :
if ( ! F_36 ( V_290 ) ) {
V_6 = - V_291 ;
break;
}
V_5 -> V_3 . V_212 = F_164 ( V_279 -> V_191 , V_226 ) ;
break;
#endif
default:
V_6 = - V_69 ;
break;
}
}
return V_6 ;
}
int F_165 ( struct V_1 * V_5 , struct V_70 * V_9 )
{
int V_6 ;
T_3 V_300 ;
if ( V_5 -> V_272 ) {
V_5 -> V_272 = 0 ;
if ( ! V_5 -> V_273 )
F_134 ( V_5 , V_9 ) ;
#ifdef F_139
if ( V_5 -> V_3 . V_277 > 0 ) {
V_5 -> V_3 . V_277 -- ;
V_5 -> V_3 . V_227 ++ ;
}
if ( V_5 -> V_3 . V_277 > 0 ) {
V_6 = F_153 ( V_5 , V_9 ) ;
if ( V_6 == V_84 ) {
V_5 -> V_272 = 1 ;
return V_6 ;
}
}
#endif
} else if ( V_5 -> V_3 . V_301 ) {
V_208 * V_302 = V_9 -> V_303 . V_302 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < 32 ; V_17 ++ )
F_32 ( V_5 , V_17 , V_302 [ V_17 ] ) ;
V_5 -> V_3 . V_301 = 0 ;
} else if ( V_5 -> V_3 . V_304 ) {
int V_17 ;
F_32 ( V_5 , 3 , V_9 -> V_305 . V_203 ) ;
for ( V_17 = 0 ; V_17 < 9 ; ++ V_17 )
F_32 ( V_5 , 4 + V_17 , V_9 -> V_305 . args [ V_17 ] ) ;
V_5 -> V_3 . V_304 = 0 ;
#ifdef F_68
} else if ( V_5 -> V_3 . V_306 ) {
F_166 ( V_5 , V_9 -> V_307 . V_307 ) ;
V_5 -> V_3 . V_306 = 0 ;
#endif
}
if ( V_5 -> V_308 )
F_167 ( V_309 , & V_5 -> V_310 , & V_300 ) ;
if ( V_9 -> V_311 )
V_6 = - V_12 ;
else
V_6 = F_168 ( V_9 , V_5 ) ;
if ( V_5 -> V_308 )
F_167 ( V_309 , & V_300 , NULL ) ;
return V_6 ;
}
int F_169 ( struct V_1 * V_5 , struct V_312 * V_313 )
{
if ( V_313 -> V_313 == V_314 ) {
F_170 ( V_5 ) ;
return 0 ;
}
F_171 ( V_5 , V_313 ) ;
F_172 ( V_5 ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_5 ,
struct V_315 * V_316 )
{
int V_6 ;
if ( V_316 -> V_317 )
return - V_69 ;
switch ( V_316 -> V_316 ) {
case V_139 :
V_6 = 0 ;
V_5 -> V_3 . V_318 = true ;
break;
case V_129 :
V_6 = 0 ;
V_5 -> V_3 . V_65 = true ;
break;
case V_126 :
V_6 = 0 ;
if ( V_316 -> args [ 0 ] )
V_5 -> V_3 . V_319 |= V_320 ;
else
V_5 -> V_3 . V_319 &= ~ V_320 ;
break;
#ifdef F_68
case V_125 :
V_6 = 0 ;
V_5 -> V_3 . V_321 = true ;
break;
#endif
#if F_26 ( V_56 ) || F_26 ( V_141 )
case V_142 : {
struct V_322 V_323 ;
void V_297 * V_324 = ( void V_297 * ) ( V_325 ) V_316 -> args [ 0 ] ;
V_6 = - V_299 ;
if ( F_162 ( & V_323 , V_324 , sizeof( V_323 ) ) )
break;
V_6 = F_174 ( V_5 , & V_323 ) ;
break;
}
#endif
#ifdef F_69
case V_143 : {
struct V_326 V_327 ;
struct V_328 * V_329 ;
V_6 = - V_330 ;
V_327 = F_175 ( V_316 -> args [ 0 ] ) ;
if ( ! V_327 . V_176 )
break;
V_6 = - V_100 ;
V_329 = F_176 ( V_327 . V_176 ) ;
if ( V_329 )
V_6 = F_177 ( V_329 , V_5 , V_316 -> args [ 1 ] ) ;
F_178 ( V_327 ) ;
break;
}
#endif
#ifdef F_57
case V_150 : {
struct V_326 V_327 ;
struct V_328 * V_329 ;
V_6 = - V_330 ;
V_327 = F_175 ( V_316 -> args [ 0 ] ) ;
if ( ! V_327 . V_176 )
break;
V_6 = - V_100 ;
V_329 = F_176 ( V_327 . V_176 ) ;
if ( V_329 ) {
if ( F_94 () )
V_6 = F_179 ( V_329 , V_5 , V_316 -> args [ 1 ] ) ;
else
V_6 = F_180 ( V_329 , V_5 , V_316 -> args [ 1 ] ) ;
}
F_178 ( V_327 ) ;
break;
}
#endif
#ifdef F_70
case V_173 :
V_6 = - V_69 ;
if ( ! F_34 ( V_5 -> V_66 ) )
break;
V_6 = 0 ;
V_5 -> V_66 -> V_3 . V_331 = true ;
break;
#endif
default:
V_6 = - V_69 ;
break;
}
if ( ! V_6 )
V_6 = F_33 ( V_5 ) ;
return V_6 ;
}
bool F_181 ( struct V_66 * V_66 )
{
#ifdef F_69
if ( V_66 -> V_3 . V_197 )
return true ;
#endif
#ifdef F_57
if ( V_66 -> V_3 . V_332 || V_66 -> V_3 . V_333 )
return true ;
#endif
return false ;
}
int F_182 ( struct V_1 * V_5 ,
struct V_334 * V_335 )
{
return - V_69 ;
}
int F_183 ( struct V_1 * V_5 ,
struct V_334 * V_335 )
{
return - V_69 ;
}
long F_184 ( struct V_176 * V_177 ,
unsigned int V_178 , unsigned long V_179 )
{
struct V_1 * V_5 = V_177 -> V_336 ;
void V_297 * V_337 = ( void V_297 * ) V_179 ;
long V_6 ;
switch ( V_178 ) {
case V_338 : {
struct V_312 V_313 ;
V_6 = - V_299 ;
if ( F_162 ( & V_313 , V_337 , sizeof( V_313 ) ) )
goto V_62;
V_6 = F_169 ( V_5 , & V_313 ) ;
goto V_62;
}
case V_339 :
{
struct V_315 V_316 ;
V_6 = - V_299 ;
if ( F_162 ( & V_316 , V_337 , sizeof( V_316 ) ) )
goto V_62;
V_6 = F_173 ( V_5 , & V_316 ) ;
break;
}
case V_340 :
case V_341 :
{
struct V_287 V_279 ;
V_6 = - V_299 ;
if ( F_162 ( & V_279 , V_337 , sizeof( V_279 ) ) )
goto V_62;
if ( V_178 == V_340 )
V_6 = F_161 ( V_5 , & V_279 ) ;
else
V_6 = F_155 ( V_5 , & V_279 ) ;
break;
}
#if F_26 ( V_56 ) || F_26 ( V_141 )
case V_342 : {
struct V_343 V_344 ;
V_6 = - V_299 ;
if ( F_162 ( & V_344 , V_337 , sizeof( V_344 ) ) )
goto V_62;
V_6 = F_185 ( V_5 , & V_344 ) ;
break;
}
#endif
default:
V_6 = - V_69 ;
}
V_62:
return V_6 ;
}
int F_186 ( struct V_1 * V_5 , struct V_345 * V_346 )
{
return V_347 ;
}
static int F_187 ( struct V_348 * V_349 )
{
T_2 V_350 = 0x60000000 ;
#ifdef F_35
T_2 V_351 = 0x44000022 ;
V_349 -> V_352 [ 0 ] = F_188 ( V_351 ) ;
V_349 -> V_352 [ 1 ] = F_188 ( V_350 ) ;
V_349 -> V_352 [ 2 ] = F_188 ( V_350 ) ;
V_349 -> V_352 [ 3 ] = F_188 ( V_350 ) ;
#else
T_2 V_353 = 0x3c000000 ;
T_2 V_354 = 0x60000000 ;
T_2 V_355 = 0x44000002 ;
T_2 V_356 = 0xffff ;
V_349 -> V_352 [ 0 ] = F_188 ( V_353 | ( ( V_357 >> 16 ) & V_356 ) ) ;
V_349 -> V_352 [ 1 ] = F_188 ( V_354 | ( V_357 & V_356 ) ) ;
V_349 -> V_352 [ 2 ] = F_188 ( V_355 ) ;
V_349 -> V_352 [ 3 ] = F_188 ( V_350 ) ;
#endif
V_349 -> V_317 = V_358 ;
return 0 ;
}
int F_189 ( struct V_66 * V_66 , struct V_359 * V_360 ,
bool V_361 )
{
if ( ! F_190 ( V_66 ) )
return - V_291 ;
V_360 -> V_362 = F_191 ( V_66 , V_363 ,
V_360 -> V_313 , V_360 -> V_364 ,
V_361 ) ;
return 0 ;
}
static int F_192 ( struct V_66 * V_66 ,
struct V_315 * V_316 )
{
int V_6 ;
if ( V_316 -> V_317 )
return - V_69 ;
switch ( V_316 -> V_316 ) {
#ifdef F_193
case V_149 : {
unsigned long V_352 = V_316 -> args [ 0 ] ;
V_6 = - V_69 ;
if ( V_352 > V_365 || ( V_352 & 3 ) ||
V_316 -> args [ 1 ] > 1 )
break;
if ( ! F_194 ( V_66 , V_352 ) )
break;
if ( V_316 -> args [ 1 ] )
F_195 ( V_352 / 4 , V_66 -> V_3 . V_366 ) ;
else
F_196 ( V_352 / 4 , V_66 -> V_3 . V_366 ) ;
V_6 = 0 ;
break;
}
case V_152 : {
unsigned long V_13 = V_316 -> args [ 0 ] ;
unsigned long V_317 = V_316 -> args [ 1 ] ;
V_6 = - V_69 ;
if ( V_66 -> V_3 . V_111 -> V_367 )
V_6 = V_66 -> V_3 . V_111 -> V_367 ( V_66 , V_13 , V_317 ) ;
break;
}
#endif
default:
V_6 = - V_69 ;
break;
}
return V_6 ;
}
long F_197 ( struct V_176 * V_177 ,
unsigned int V_178 , unsigned long V_179 )
{
struct V_66 * V_66 T_1 = V_177 -> V_336 ;
void V_297 * V_337 = ( void V_297 * ) V_179 ;
long V_6 ;
switch ( V_178 ) {
case V_368 : {
struct V_348 V_349 ;
memset ( & V_349 , 0 , sizeof( V_349 ) ) ;
V_6 = F_187 ( & V_349 ) ;
if ( F_160 ( V_337 , & V_349 , sizeof( V_349 ) ) ) {
V_6 = - V_299 ;
goto V_62;
}
break;
}
case V_339 :
{
struct V_315 V_316 ;
V_6 = - V_299 ;
if ( F_162 ( & V_316 , V_337 , sizeof( V_316 ) ) )
goto V_62;
V_6 = F_192 ( V_66 , & V_316 ) ;
break;
}
#ifdef F_198
case V_369 : {
struct V_370 V_371 ;
V_6 = - V_299 ;
if ( F_162 ( & V_371 , V_337 , sizeof( V_371 ) ) )
goto V_62;
if ( V_371 . V_317 ) {
V_6 = - V_69 ;
goto V_62;
}
V_6 = F_199 ( V_66 , & V_371 ) ;
goto V_62;
}
case V_372 : {
struct V_373 V_374 ;
struct V_370 V_371 ;
V_6 = - V_299 ;
if ( F_162 ( & V_374 , V_337 , sizeof( V_374 ) ) )
goto V_62;
V_371 . V_375 = V_374 . V_375 ;
V_371 . V_376 = V_377 ;
V_371 . V_223 = 0 ;
V_371 . V_86 = V_374 . V_378 >>
V_377 ;
V_371 . V_317 = 0 ;
V_6 = F_199 ( V_66 , & V_371 ) ;
goto V_62;
}
#endif
#ifdef V_37
case V_379 : {
struct V_380 V_381 ;
struct V_66 * V_66 = V_177 -> V_336 ;
memset ( & V_381 , 0 , sizeof( V_381 ) ) ;
V_6 = V_66 -> V_3 . V_111 -> V_382 ( V_66 , & V_381 ) ;
if ( V_6 >= 0 && F_160 ( V_337 , & V_381 , sizeof( V_381 ) ) )
V_6 = - V_299 ;
break;
}
case V_383 : {
struct V_66 * V_66 = V_177 -> V_336 ;
V_6 = F_200 ( V_66 , V_337 ) ;
break;
}
case V_384 : {
struct V_66 * V_66 = V_177 -> V_336 ;
struct V_385 V_323 ;
V_6 = - V_69 ;
if ( ! V_66 -> V_3 . V_111 -> V_386 )
goto V_62;
V_6 = - V_299 ;
if ( F_162 ( & V_323 , V_337 , sizeof( V_323 ) ) )
goto V_62;
V_6 = V_66 -> V_3 . V_111 -> V_386 ( V_66 , & V_323 ) ;
break;
}
case V_387 : {
struct V_66 * V_66 = V_177 -> V_336 ;
struct V_388 V_381 ;
V_6 = - V_69 ;
if ( ! V_66 -> V_3 . V_111 -> V_389 )
goto V_62;
V_6 = V_66 -> V_3 . V_111 -> V_389 ( V_66 , & V_381 ) ;
if ( V_6 >= 0 && F_160 ( V_337 , & V_381 , sizeof( V_381 ) ) )
V_6 = - V_299 ;
break;
}
default: {
struct V_66 * V_66 = V_177 -> V_336 ;
V_6 = V_66 -> V_3 . V_111 -> V_390 ( V_177 , V_178 , V_179 ) ;
}
#else
default:
V_6 = - V_391 ;
#endif
}
V_62:
return V_6 ;
}
long F_201 ( void )
{
long V_392 ;
do {
V_392 = F_202 ( V_393 , V_394 ) ;
if ( V_392 >= V_395 ) {
F_203 ( L_5 , V_83 ) ;
return - V_396 ;
}
} while ( F_204 ( V_392 , V_393 ) );
return V_392 ;
}
void F_205 ( long V_392 )
{
F_195 ( V_392 , V_393 ) ;
}
void F_206 ( long V_392 )
{
F_196 ( V_392 , V_393 ) ;
}
void F_207 ( unsigned long V_397 )
{
V_395 = F_208 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_393 , 0 , sizeof( V_393 ) ) ;
}
int F_209 ( void * V_398 )
{
return 0 ;
}
