int F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 . V_4 ) ||
V_2 -> V_5 ;
}
int F_2 ( struct V_1 * V_6 )
{
return 1 ;
}
int F_3 ( struct V_1 * V_6 )
{
int V_7 ;
F_4 ( F_5 () ) ;
F_6 () ;
while ( true ) {
if ( F_7 () ) {
F_8 () ;
F_9 () ;
F_6 () ;
continue;
}
if ( F_10 ( V_8 ) ) {
F_11 ( V_6 , V_9 ) ;
V_6 -> V_10 -> V_11 = V_12 ;
V_7 = - V_13 ;
break;
}
V_6 -> V_14 = V_15 ;
F_12 () ;
if ( V_6 -> V_5 ) {
F_8 () ;
F_13 ( V_6 ) ;
V_7 = F_14 ( V_6 ) ;
F_6 () ;
if ( V_7 > 0 )
continue;
break;
}
if ( F_15 ( V_6 ) ) {
continue;
}
F_16 () ;
return 1 ;
}
F_8 () ;
return V_7 ;
}
static void F_17 ( struct V_1 * V_6 )
{
struct V_16 * V_17 = V_6 -> V_3 . V_17 ;
int V_18 ;
V_17 -> V_19 = F_18 ( V_17 -> V_19 ) ;
V_17 -> V_20 = F_18 ( V_17 -> V_20 ) ;
V_17 -> V_21 = F_18 ( V_17 -> V_21 ) ;
V_17 -> V_22 = F_18 ( V_17 -> V_22 ) ;
V_17 -> V_23 = F_18 ( V_17 -> V_23 ) ;
V_17 -> V_24 = F_18 ( V_17 -> V_24 ) ;
V_17 -> V_25 = F_18 ( V_17 -> V_25 ) ;
V_17 -> V_26 = F_18 ( V_17 -> V_26 ) ;
V_17 -> V_27 = F_19 ( V_17 -> V_27 ) ;
V_17 -> V_28 = F_19 ( V_17 -> V_28 ) ;
for ( V_18 = 0 ; V_18 < F_20 ( V_17 -> V_29 ) ; V_18 ++ )
V_17 -> V_29 [ V_18 ] = F_19 ( V_17 -> V_29 [ V_18 ] ) ;
}
int F_21 ( struct V_1 * V_6 )
{
int V_30 = F_22 ( V_6 , 11 ) ;
int V_7 ;
unsigned long T_1 V_31 = F_22 ( V_6 , 3 ) ;
unsigned long T_1 V_32 = F_22 ( V_6 , 4 ) ;
unsigned long T_1 V_33 = F_22 ( V_6 , 5 ) ;
unsigned long T_1 V_34 = F_22 ( V_6 , 6 ) ;
unsigned long V_35 = 0 ;
if ( ! ( F_23 ( V_6 ) & V_36 ) ) {
V_31 &= 0xffffffff ;
V_32 &= 0xffffffff ;
V_33 &= 0xffffffff ;
V_34 &= 0xffffffff ;
}
switch ( V_30 ) {
case F_24 ( V_37 ) :
{
#if F_25 ( V_38 ) && F_25 ( V_39 )
int V_40 = true ;
if ( V_6 -> V_3 . V_41 & V_42 )
V_40 = false ;
if ( V_40 != V_6 -> V_3 . V_40 )
F_17 ( V_6 ) ;
V_6 -> V_3 . V_40 = V_40 ;
#endif
if ( ! ( V_32 & V_43 ) ) {
V_6 -> V_3 . V_44 = true ;
F_26 ( V_45 , V_6 ) ;
}
V_6 -> V_3 . V_46 = V_31 & ~ 0xfffULL ;
V_6 -> V_3 . V_47 = V_32 & ~ 0xfffULL ;
#ifdef F_27
if ( ( V_6 -> V_3 . V_46 & 0xf000 ) !=
( ( V_48 ) V_6 -> V_3 . V_17 & 0xf000 ) ) {
void * V_49 = V_6 -> V_3 . V_17 ;
V_48 V_17 = ( V_48 ) V_6 -> V_3 . V_17 ;
void * V_50 ;
V_17 &= V_51 ;
V_17 |= V_6 -> V_3 . V_46 & 0xf000 ;
V_50 = ( void * ) V_17 ;
memcpy ( V_50 , V_49 , 0x1000 ) ;
V_6 -> V_3 . V_17 = V_50 ;
}
#endif
V_35 = V_52 | V_53 ;
V_7 = V_54 ;
break;
}
case F_24 ( V_55 ) :
V_7 = V_54 ;
#if F_25 ( V_56 ) || F_25 ( V_57 )
V_35 |= ( 1 << V_58 ) ;
#endif
break;
case F_28 ( V_59 ) :
V_7 = V_54 ;
F_29 ( V_6 ) ;
F_30 ( V_60 , V_6 ) ;
break;
default:
V_7 = V_61 ;
break;
}
F_31 ( V_6 , 4 , V_35 ) ;
return V_7 ;
}
int F_32 ( struct V_1 * V_6 )
{
int V_7 = false ;
if ( ! V_6 -> V_3 . V_62 )
goto V_63;
if ( ( V_6 -> V_3 . V_64 != V_65 ) && V_6 -> V_3 . V_66 )
goto V_63;
if ( ! V_6 -> V_3 . V_66 && F_33 ( V_6 -> V_67 ) )
goto V_63;
#ifdef F_34
if ( ! F_35 ( V_68 ) )
goto V_63;
#endif
V_7 = true ;
V_63:
V_6 -> V_3 . V_69 = V_7 ;
return V_7 ? 0 : - V_70 ;
}
int F_36 ( struct V_71 * V_10 , struct V_1 * V_6 )
{
enum V_72 V_73 ;
int V_7 ;
V_73 = F_37 ( V_6 ) ;
switch ( V_73 ) {
case V_74 :
V_7 = V_75 ;
break;
case V_76 :
V_7 = V_77 ;
break;
case V_78 :
V_10 -> V_11 = V_79 ;
V_7 = V_80 ;
break;
case V_81 :
{
T_2 V_82 ;
F_38 ( V_6 , V_83 , & V_82 ) ;
F_39 ( L_1 , V_84 , V_82 ) ;
V_7 = V_85 ;
break;
}
default:
F_4 ( 1 ) ;
V_7 = V_77 ;
}
return V_7 ;
}
int F_40 ( struct V_1 * V_6 , V_48 * V_86 , int V_87 , void * V_88 ,
bool V_89 )
{
V_48 V_90 = V_6 -> V_3 . V_46 & V_91 & V_51 ;
struct V_92 V_93 ;
int V_7 ;
V_6 -> V_94 . V_95 ++ ;
V_7 = F_41 ( V_6 , * V_86 , V_89 ? V_96 : V_97 ,
V_98 , & V_93 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_86 = V_93 . V_99 ;
if ( ! V_93 . V_100 )
return - V_101 ;
if ( F_42 ( V_6 ) && V_90 &&
( ( V_93 . V_99 & V_91 & V_51 ) == V_90 ) &&
! ( F_23 ( V_6 ) & V_102 ) ) {
void * V_103 = V_6 -> V_3 . V_17 ;
V_103 += V_93 . V_86 & 0xfff ;
memcpy ( V_103 , V_88 , V_87 ) ;
return V_74 ;
}
if ( F_43 ( V_6 -> V_67 , V_93 . V_99 , V_88 , V_87 ) )
return V_78 ;
return V_74 ;
}
int F_44 ( struct V_1 * V_6 , V_48 * V_86 , int V_87 , void * V_88 ,
bool V_89 )
{
V_48 V_90 = V_6 -> V_3 . V_46 & V_91 & V_51 ;
struct V_92 V_93 ;
int V_104 ;
V_6 -> V_94 . V_105 ++ ;
V_104 = F_41 ( V_6 , * V_86 , V_89 ? V_96 : V_97 ,
V_106 , & V_93 ) ;
if ( V_104 )
return V_104 ;
* V_86 = V_93 . V_99 ;
if ( ! V_93 . V_107 )
return - V_101 ;
if ( ! V_89 && ! V_93 . V_108 )
return - V_109 ;
if ( F_42 ( V_6 ) && V_90 &&
( ( V_93 . V_99 & V_91 & V_51 ) == V_90 ) &&
! ( F_23 ( V_6 ) & V_102 ) ) {
void * V_103 = V_6 -> V_3 . V_17 ;
V_103 += V_93 . V_86 & 0xfff ;
memcpy ( V_88 , V_103 , V_87 ) ;
return V_74 ;
}
if ( F_45 ( V_6 -> V_67 , V_93 . V_99 , V_88 , V_87 ) )
return V_78 ;
return V_74 ;
}
int F_46 ( void )
{
return 0 ;
}
int F_47 ( void )
{
return 0 ;
}
void F_48 ( void * V_110 )
{
* ( int * ) V_110 = F_49 () ;
}
int F_50 ( struct V_67 * V_67 , unsigned long type )
{
struct V_111 * V_112 = NULL ;
if ( type == 0 ) {
if ( V_113 )
V_112 = V_113 ;
else
V_112 = V_114 ;
if ( ! V_112 )
goto V_115;
} else if ( type == V_116 ) {
if ( ! V_113 )
goto V_115;
V_112 = V_113 ;
} else if ( type == V_117 ) {
if ( ! V_114 )
goto V_115;
V_112 = V_114 ;
} else
goto V_115;
if ( V_112 -> V_118 && ! F_51 ( V_112 -> V_118 ) )
return - V_119 ;
V_67 -> V_3 . V_112 = V_112 ;
return F_52 ( V_67 ) ;
V_115:
return - V_70 ;
}
bool F_53 ( void )
{
return false ;
}
int F_54 ( struct V_1 * V_6 )
{
return 0 ;
}
void F_55 ( struct V_67 * V_67 )
{
unsigned int V_18 ;
struct V_1 * V_6 ;
#ifdef F_56
if ( F_33 ( V_67 ) )
F_57 () ;
#endif
F_58 (i, vcpu, kvm)
F_59 ( V_6 ) ;
F_60 ( & V_67 -> V_120 ) ;
for ( V_18 = 0 ; V_18 < F_61 ( & V_67 -> V_121 ) ; V_18 ++ )
V_67 -> V_122 [ V_18 ] = NULL ;
F_62 ( & V_67 -> V_121 , 0 ) ;
F_63 ( V_67 ) ;
F_64 ( & V_67 -> V_120 ) ;
F_65 ( V_67 -> V_3 . V_112 -> V_118 ) ;
}
int F_66 ( struct V_67 * V_67 , long V_123 )
{
int V_7 ;
int V_124 = V_113 ? 1 : 0 ;
if ( V_67 ) {
V_124 = F_33 ( V_67 ) ;
}
switch ( V_123 ) {
#ifdef F_67
case V_125 :
case V_126 :
case V_127 :
#else
case V_128 :
case V_129 :
case V_130 :
#endif
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
V_7 = 1 ;
break;
case V_139 :
case V_140 :
case V_141 :
#if F_25 ( V_57 ) || F_25 ( V_142 )
case V_143 :
#endif
V_7 = ! V_124 ;
break;
#ifdef F_68
case V_144 :
V_7 = 1 ;
break;
#endif
#ifdef V_38
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
#ifdef F_56
case V_151 :
#endif
V_7 = 1 ;
break;
case V_152 :
V_7 = V_124 ;
break;
#endif
#ifdef F_69
case V_153 :
V_7 = 0 ;
if ( V_124 ) {
if ( F_35 ( V_154 ) )
V_7 = 1 ;
else
V_7 = V_155 ;
}
break;
case V_156 :
V_7 = 0 ;
break;
case V_157 :
V_7 = F_70 () ;
break;
case V_158 :
V_7 = ! ! ( V_124 && F_71 () ) ;
break;
case V_159 :
V_7 = ! ! ( V_124 && ! F_71 () &&
F_35 ( V_154 ) ) ;
break;
#endif
case V_160 :
#ifdef F_69
V_7 = V_124 ;
#elif F_25 ( V_161 )
V_7 = 1 ;
#else
V_7 = 0 ;
#endif
break;
#ifdef F_69
case V_162 :
V_7 = V_124 ;
break;
#endif
case V_163 :
if ( V_124 )
V_7 = F_72 () ;
else
V_7 = F_73 () ;
break;
case V_164 :
V_7 = V_165 ;
break;
case V_166 :
V_7 = V_167 ;
break;
#ifdef V_38
case V_168 :
V_7 = 1 ;
break;
case V_169 :
V_7 = 1 ;
break;
case V_170 :
V_7 = ! ! V_124 && ! F_35 ( V_154 ) ;
break;
#endif
case V_171 :
V_7 = F_35 ( V_172 ) &&
F_33 ( V_67 ) ;
break;
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_74 ( struct V_173 * V_174 ,
unsigned int V_175 , unsigned long V_176 )
{
return - V_70 ;
}
void F_75 ( struct V_67 * V_67 , struct V_177 * free ,
struct V_177 * V_178 )
{
F_76 ( V_67 , free , V_178 ) ;
}
int F_77 ( struct V_67 * V_67 , struct V_177 * V_179 ,
unsigned long V_180 )
{
return F_78 ( V_67 , V_179 , V_180 ) ;
}
int F_79 ( struct V_67 * V_67 ,
struct V_177 * V_181 ,
const struct V_182 * V_183 ,
enum V_184 V_185 )
{
return F_80 ( V_67 , V_181 , V_183 ) ;
}
void F_81 ( struct V_67 * V_67 ,
const struct V_182 * V_183 ,
const struct V_177 * V_186 ,
const struct V_177 * V_187 ,
enum V_184 V_185 )
{
F_82 ( V_67 , V_183 , V_186 , V_187 ) ;
}
void F_83 ( struct V_67 * V_67 ,
struct V_177 * V_179 )
{
F_84 ( V_67 , V_179 ) ;
}
struct V_1 * F_85 ( struct V_67 * V_67 , unsigned int V_188 )
{
struct V_1 * V_6 ;
V_6 = F_86 ( V_67 , V_188 ) ;
if ( ! F_87 ( V_6 ) ) {
V_6 -> V_3 . V_189 = & V_6 -> V_190 ;
F_88 ( V_6 , V_188 ) ;
}
return V_6 ;
}
void F_89 ( struct V_1 * V_6 )
{
}
void F_59 ( struct V_1 * V_6 )
{
F_90 ( & V_6 -> V_3 . V_191 ) ;
F_91 ( V_6 ) ;
switch ( V_6 -> V_3 . V_192 ) {
case V_193 :
F_92 ( V_6 -> V_3 . V_194 , V_6 ) ;
break;
case V_195 :
if ( F_93 () )
F_94 ( V_6 ) ;
else
F_95 ( V_6 ) ;
break;
}
F_96 ( V_6 ) ;
}
void F_97 ( struct V_1 * V_6 )
{
F_59 ( V_6 ) ;
}
int F_98 ( struct V_1 * V_6 )
{
return F_99 ( V_6 ) ;
}
static enum V_196 F_100 ( struct V_197 * V_198 )
{
struct V_1 * V_6 ;
V_6 = F_101 ( V_198 , struct V_1 , V_3 . V_191 ) ;
F_102 ( V_6 ) ;
return V_199 ;
}
int F_103 ( struct V_1 * V_6 )
{
int V_200 ;
F_104 ( & V_6 -> V_3 . V_191 , V_201 , V_202 ) ;
V_6 -> V_3 . V_191 . V_203 = F_100 ;
V_6 -> V_3 . V_204 = ~ ( V_205 ) 0 ;
#ifdef F_105
F_106 ( & V_6 -> V_3 . V_206 ) ;
#endif
V_200 = F_107 ( V_6 ) ;
return V_200 ;
}
void F_108 ( struct V_1 * V_6 )
{
F_109 ( V_6 ) ;
F_110 ( V_6 ) ;
}
void F_111 ( struct V_1 * V_6 , int V_207 )
{
#ifdef F_67
F_112 ( V_208 , V_6 -> V_3 . V_209 ) ;
#endif
F_113 ( V_6 , V_207 ) ;
}
void F_114 ( struct V_1 * V_6 )
{
F_115 ( V_6 ) ;
#ifdef F_67
V_6 -> V_3 . V_209 = F_116 ( V_208 ) ;
#endif
}
bool F_117 ( void )
{
return ( ( V_113 && V_113 -> V_210 ) ||
( V_114 && V_114 -> V_210 ) ) ;
}
int F_118 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_215 * V_216 =
F_101 ( V_212 , struct V_215 , V_217 ) ;
struct V_67 * V_67 = V_216 -> V_67 ;
if ( V_67 -> V_3 . V_112 -> V_210 )
return V_67 -> V_3 . V_112 -> V_210 ( V_212 , V_214 ) ;
return 0 ;
}
void F_119 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_215 * V_216 =
F_101 ( V_212 , struct V_215 , V_217 ) ;
struct V_67 * V_67 = V_216 -> V_67 ;
if ( V_67 -> V_3 . V_112 -> V_218 )
V_67 -> V_3 . V_112 -> V_218 ( V_212 , V_214 ) ;
}
static inline int F_120 ( int V_219 )
{
int V_220 ;
if ( ( V_219 != 0 ) && ( V_219 != 1 ) )
return - 1 ;
#ifdef F_121
V_220 = V_219 ;
#else
V_220 = 1 - V_219 ;
#endif
return V_220 ;
}
static inline int F_122 ( int V_219 )
{
int V_220 ;
if ( ( V_219 > 3 ) || ( V_219 < 0 ) )
return - 1 ;
#ifdef F_121
V_220 = V_219 ;
#else
V_220 = 3 - V_219 ;
#endif
return V_220 ;
}
static inline void F_123 ( struct V_1 * V_6 ,
V_205 V_221 )
{
union V_222 V_223 ;
int V_220 = F_120 ( V_6 -> V_3 . V_224 ) ;
int V_219 = V_6 -> V_3 . V_225 & V_226 ;
if ( V_220 == - 1 )
return;
if ( V_6 -> V_3 . V_227 ) {
V_223 . V_228 = F_124 ( V_6 , V_219 ) ;
V_223 . V_229 [ V_220 ] = V_221 ;
F_124 ( V_6 , V_219 ) = V_223 . V_228 ;
} else {
F_125 ( V_6 , V_219 , V_220 ) = V_221 ;
}
}
static inline void F_126 ( struct V_1 * V_6 ,
V_205 V_221 )
{
union V_222 V_223 ;
int V_219 = V_6 -> V_3 . V_225 & V_226 ;
if ( V_6 -> V_3 . V_227 ) {
V_223 . V_228 = F_124 ( V_6 , V_219 ) ;
V_223 . V_229 [ 0 ] = V_221 ;
V_223 . V_229 [ 1 ] = V_221 ;
F_124 ( V_6 , V_219 ) = V_223 . V_228 ;
} else {
F_125 ( V_6 , V_219 , 0 ) = V_221 ;
F_125 ( V_6 , V_219 , 1 ) = V_221 ;
}
}
static inline void F_127 ( struct V_1 * V_6 ,
T_2 V_230 )
{
union V_222 V_223 ;
int V_220 = F_122 ( V_6 -> V_3 . V_224 ) ;
int V_219 = V_6 -> V_3 . V_225 & V_226 ;
int V_231 , V_232 ;
if ( V_220 == - 1 )
return;
if ( V_6 -> V_3 . V_227 ) {
V_223 . V_228 = F_124 ( V_6 , V_219 ) ;
V_223 . V_233 [ V_220 ] = V_230 ;
F_124 ( V_6 , V_219 ) = V_223 . V_228 ;
} else {
V_231 = V_220 / 2 ;
V_232 = V_220 % 2 ;
V_223 . V_229 [ 0 ] = F_125 ( V_6 , V_219 , V_231 ) ;
V_223 . V_233 [ V_232 ] = V_230 ;
F_125 ( V_6 , V_219 , V_231 ) = V_223 . V_229 [ 0 ] ;
}
}
static inline V_205 F_128 ( T_2 V_234 )
{
V_205 V_235 ;
F_129 () ;
F_130 () ;
asm ("lfs%U1%X1 0,%1; stfd%U0%X0 0,%0" : "=m" (fprd) : "m" (fprs)
: "fr0");
F_131 () ;
return V_235 ;
}
static inline T_2 F_132 ( V_205 V_235 )
{
T_2 V_234 ;
F_129 () ;
F_130 () ;
asm ("lfd%U1%X1 0,%1; stfs%U0%X0 0,%0" : "=m" (fprs) : "m" (fprd)
: "fr0");
F_131 () ;
return V_234 ;
}
static void F_133 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_205 V_236 ( V_221 ) ;
if ( V_10 -> V_237 . V_238 > sizeof( V_221 ) ) {
F_134 ( V_239 L_2 , V_10 -> V_237 . V_238 ) ;
return;
}
if ( ! V_6 -> V_3 . V_240 ) {
switch ( V_10 -> V_237 . V_238 ) {
case 8 : V_221 = * ( V_205 * ) V_10 -> V_237 . V_89 ; break;
case 4 : V_221 = * ( T_2 * ) V_10 -> V_237 . V_89 ; break;
case 2 : V_221 = * ( V_241 * ) V_10 -> V_237 . V_89 ; break;
case 1 : V_221 = * ( V_242 * ) V_10 -> V_237 . V_89 ; break;
}
} else {
switch ( V_10 -> V_237 . V_238 ) {
case 8 : V_221 = F_18 ( * ( V_205 * ) V_10 -> V_237 . V_89 ) ; break;
case 4 : V_221 = F_19 ( * ( T_2 * ) V_10 -> V_237 . V_89 ) ; break;
case 2 : V_221 = F_135 ( * ( V_241 * ) V_10 -> V_237 . V_89 ) ; break;
case 1 : V_221 = * ( V_242 * ) V_10 -> V_237 . V_89 ; break;
}
}
if ( ( V_6 -> V_3 . V_243 ) && ( V_10 -> V_237 . V_238 == 4 ) )
V_221 = F_128 ( V_221 ) ;
if ( V_6 -> V_3 . V_244 ) {
switch ( V_10 -> V_237 . V_238 ) {
#ifdef F_136
case 4 :
V_221 = ( V_245 ) ( V_246 ) V_221 ;
break;
#endif
case 2 :
V_221 = ( V_245 ) ( V_247 ) V_221 ;
break;
case 1 :
V_221 = ( V_245 ) ( V_248 ) V_221 ;
break;
}
}
switch ( V_6 -> V_3 . V_225 & V_249 ) {
case V_250 :
F_31 ( V_6 , V_6 -> V_3 . V_225 , V_221 ) ;
break;
case V_251 :
F_137 ( V_6 , V_6 -> V_3 . V_225 & V_226 ) = V_221 ;
break;
#ifdef V_56
case V_252 :
V_6 -> V_3 . V_253 [ V_6 -> V_3 . V_225 & V_226 ] = V_221 ;
break;
case V_254 :
F_137 ( V_6 , V_6 -> V_3 . V_225 & V_226 ) = V_221 ;
V_6 -> V_3 . V_253 [ V_6 -> V_3 . V_225 & V_226 ] = V_221 ;
break;
#endif
#ifdef F_138
case V_255 :
if ( V_6 -> V_3 . V_256 == V_257 )
F_123 ( V_6 , V_221 ) ;
else if ( V_6 -> V_3 . V_256 == V_258 )
F_127 ( V_6 , V_221 ) ;
else if ( V_6 -> V_3 . V_256 ==
V_259 )
F_126 ( V_6 , V_221 ) ;
break;
#endif
default:
F_139 () ;
}
}
static int F_140 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_260 , unsigned int V_261 ,
int V_262 , int V_263 )
{
int V_264 , V_200 ;
bool V_265 ;
if ( F_141 ( V_6 ) ) {
V_265 = V_262 ;
} else {
V_265 = ! V_262 ;
}
if ( V_261 > sizeof( V_10 -> V_237 . V_89 ) ) {
F_134 ( V_239 L_3 , V_84 ,
V_10 -> V_237 . V_238 ) ;
}
V_10 -> V_237 . V_266 = V_6 -> V_3 . V_267 ;
V_10 -> V_237 . V_238 = V_261 ;
V_10 -> V_237 . V_268 = 0 ;
V_6 -> V_3 . V_225 = V_260 ;
V_6 -> V_3 . V_240 = V_265 ;
V_6 -> V_269 = 1 ;
V_6 -> V_270 = 0 ;
V_6 -> V_3 . V_244 = V_263 ;
V_264 = F_142 ( & V_6 -> V_67 -> V_271 ) ;
V_200 = F_143 ( V_6 , V_272 , V_10 -> V_237 . V_266 ,
V_261 , & V_10 -> V_237 . V_89 ) ;
F_144 ( & V_6 -> V_67 -> V_271 , V_264 ) ;
if ( ! V_200 ) {
F_133 ( V_6 , V_10 ) ;
V_6 -> V_269 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_145 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_260 , unsigned int V_261 ,
int V_262 )
{
return F_140 ( V_10 , V_6 , V_260 , V_261 , V_262 , 0 ) ;
}
int F_146 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_260 , unsigned int V_261 ,
int V_262 )
{
return F_140 ( V_10 , V_6 , V_260 , V_261 , V_262 , 1 ) ;
}
int F_147 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_260 , unsigned int V_261 ,
int V_262 , int V_244 )
{
enum V_72 V_273 = V_74 ;
if ( ( V_6 -> V_3 . V_274 > 4 ) ||
( V_6 -> V_3 . V_274 < 0 ) ) {
return V_81 ;
}
while ( V_6 -> V_3 . V_274 ) {
V_273 = F_140 ( V_10 , V_6 , V_260 , V_261 ,
V_262 , V_244 ) ;
if ( V_273 != V_74 )
break;
V_6 -> V_3 . V_267 += V_10 -> V_237 . V_238 ;
V_6 -> V_3 . V_274 -- ;
V_6 -> V_3 . V_224 ++ ;
}
return V_273 ;
}
int F_148 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_205 V_223 , unsigned int V_261 , int V_262 )
{
void * V_89 = V_10 -> V_237 . V_89 ;
int V_264 , V_200 ;
bool V_265 ;
if ( F_141 ( V_6 ) ) {
V_265 = V_262 ;
} else {
V_265 = ! V_262 ;
}
if ( V_261 > sizeof( V_10 -> V_237 . V_89 ) ) {
F_134 ( V_239 L_3 , V_84 ,
V_10 -> V_237 . V_238 ) ;
}
V_10 -> V_237 . V_266 = V_6 -> V_3 . V_267 ;
V_10 -> V_237 . V_238 = V_261 ;
V_10 -> V_237 . V_268 = 1 ;
V_6 -> V_269 = 1 ;
V_6 -> V_270 = 1 ;
if ( ( V_6 -> V_3 . V_243 ) && ( V_261 == 4 ) )
V_223 = F_132 ( V_223 ) ;
if ( ! V_265 ) {
switch ( V_261 ) {
case 8 : * ( V_205 * ) V_89 = V_223 ; break;
case 4 : * ( T_2 * ) V_89 = V_223 ; break;
case 2 : * ( V_241 * ) V_89 = V_223 ; break;
case 1 : * ( V_242 * ) V_89 = V_223 ; break;
}
} else {
switch ( V_261 ) {
case 8 : * ( V_205 * ) V_89 = F_18 ( V_223 ) ; break;
case 4 : * ( T_2 * ) V_89 = F_19 ( V_223 ) ; break;
case 2 : * ( V_241 * ) V_89 = F_135 ( V_223 ) ; break;
case 1 : * ( V_242 * ) V_89 = V_223 ; break;
}
}
V_264 = F_142 ( & V_6 -> V_67 -> V_271 ) ;
V_200 = F_149 ( V_6 , V_272 , V_10 -> V_237 . V_266 ,
V_261 , & V_10 -> V_237 . V_89 ) ;
F_144 ( & V_6 -> V_67 -> V_271 , V_264 ) ;
if ( ! V_200 ) {
V_6 -> V_269 = 0 ;
return V_74 ;
}
return V_78 ;
}
static inline int F_150 ( struct V_1 * V_6 , int V_275 , V_205 * V_223 )
{
T_2 V_231 , V_232 ;
union V_222 V_276 ;
int V_277 = 0 ;
int V_278 = V_6 -> V_3 . V_256 ;
int V_279 = 0 ;
switch ( V_278 ) {
case V_257 :
V_277 =
F_120 ( V_6 -> V_3 . V_224 ) ;
if ( V_277 == - 1 ) {
V_279 = - 1 ;
break;
}
if ( ! V_6 -> V_3 . V_227 ) {
* V_223 = F_125 ( V_6 , V_275 , V_277 ) ;
} else {
V_276 . V_228 = F_124 ( V_6 , V_275 ) ;
* V_223 = V_276 . V_229 [ V_277 ] ;
}
break;
case V_258 :
V_277 =
F_122 ( V_6 -> V_3 . V_224 ) ;
if ( V_277 == - 1 ) {
V_279 = - 1 ;
break;
}
if ( ! V_6 -> V_3 . V_227 ) {
V_231 = V_277 / 2 ;
V_232 = V_277 % 2 ;
V_276 . V_229 [ 0 ] = F_125 ( V_6 , V_275 , V_231 ) ;
* V_223 = V_276 . V_233 [ V_232 ] ;
} else {
V_276 . V_228 = F_124 ( V_6 , V_275 ) ;
* V_223 = V_276 . V_233 [ V_277 ] ;
}
break;
default:
V_279 = - 1 ;
break;
}
return V_279 ;
}
int F_151 ( struct V_71 * V_10 , struct V_1 * V_6 ,
int V_275 , unsigned int V_261 , int V_262 )
{
V_205 V_223 ;
enum V_72 V_273 = V_74 ;
V_6 -> V_3 . V_225 = V_275 ;
if ( ( V_6 -> V_3 . V_274 > 4 ) ||
( V_6 -> V_3 . V_274 < 0 ) ) {
return V_81 ;
}
while ( V_6 -> V_3 . V_274 ) {
if ( F_150 ( V_6 , V_275 , & V_223 ) == - 1 )
return V_81 ;
V_273 = F_148 ( V_10 , V_6 ,
V_223 , V_261 , V_262 ) ;
if ( V_273 != V_74 )
break;
V_6 -> V_3 . V_267 += V_10 -> V_237 . V_238 ;
V_6 -> V_3 . V_274 -- ;
V_6 -> V_3 . V_224 ++ ;
}
return V_273 ;
}
static int F_152 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
enum V_72 V_273 = V_81 ;
int V_7 ;
V_6 -> V_3 . V_267 += V_10 -> V_237 . V_238 ;
if ( ! V_6 -> V_270 ) {
V_273 = F_147 ( V_10 , V_6 , V_6 -> V_3 . V_225 ,
V_10 -> V_237 . V_238 , 1 , V_6 -> V_3 . V_244 ) ;
} else {
V_273 = F_151 ( V_10 , V_6 ,
V_6 -> V_3 . V_225 , V_10 -> V_237 . V_238 , 1 ) ;
}
switch ( V_273 ) {
case V_78 :
V_10 -> V_11 = V_79 ;
V_7 = V_85 ;
break;
case V_81 :
F_153 ( L_4 ) ;
V_10 -> V_11 = V_280 ;
V_10 -> V_281 . V_282 = V_283 ;
V_7 = V_85 ;
break;
default:
V_7 = V_77 ;
break;
}
return V_7 ;
}
int F_154 ( struct V_1 * V_6 , struct V_284 * V_276 )
{
int V_7 = 0 ;
union V_222 V_223 ;
int V_87 ;
V_87 = F_155 ( V_276 -> V_188 ) ;
if ( V_87 > sizeof( V_223 ) )
return - V_70 ;
V_7 = F_156 ( V_6 , V_276 -> V_188 , & V_223 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_276 -> V_188 ) {
#ifdef F_157
case V_285 ... V_286 :
if ( ! F_35 ( V_287 ) ) {
V_7 = - V_288 ;
break;
}
V_223 . V_228 = V_6 -> V_3 . V_289 . V_289 [ V_276 -> V_188 - V_285 ] ;
break;
case V_290 :
if ( ! F_35 ( V_287 ) ) {
V_7 = - V_288 ;
break;
}
V_223 = F_158 ( V_276 -> V_188 , V_6 -> V_3 . V_289 . V_291 . V_292 [ 3 ] ) ;
break;
case V_293 :
V_223 = F_158 ( V_276 -> V_188 , V_6 -> V_3 . V_209 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
if ( V_7 )
return V_7 ;
if ( F_159 ( ( char V_294 * ) ( unsigned long ) V_276 -> V_295 , & V_223 , V_87 ) )
V_7 = - V_296 ;
return V_7 ;
}
int F_160 ( struct V_1 * V_6 , struct V_284 * V_276 )
{
int V_7 ;
union V_222 V_223 ;
int V_87 ;
V_87 = F_155 ( V_276 -> V_188 ) ;
if ( V_87 > sizeof( V_223 ) )
return - V_70 ;
if ( F_161 ( & V_223 , ( char V_294 * ) ( unsigned long ) V_276 -> V_295 , V_87 ) )
return - V_296 ;
V_7 = F_162 ( V_6 , V_276 -> V_188 , & V_223 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_276 -> V_188 ) {
#ifdef F_157
case V_285 ... V_286 :
if ( ! F_35 ( V_287 ) ) {
V_7 = - V_288 ;
break;
}
V_6 -> V_3 . V_289 . V_289 [ V_276 -> V_188 - V_285 ] = V_223 . V_228 ;
break;
case V_290 :
if ( ! F_35 ( V_287 ) ) {
V_7 = - V_288 ;
break;
}
V_6 -> V_3 . V_289 . V_291 . V_292 [ 3 ] = F_163 ( V_276 -> V_188 , V_223 ) ;
break;
case V_293 :
if ( ! F_35 ( V_287 ) ) {
V_7 = - V_288 ;
break;
}
V_6 -> V_3 . V_209 = F_163 ( V_276 -> V_188 , V_223 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
return V_7 ;
}
int F_164 ( struct V_1 * V_6 , struct V_71 * V_10 )
{
int V_7 ;
T_3 V_297 ;
if ( V_6 -> V_269 ) {
V_6 -> V_269 = 0 ;
if ( ! V_6 -> V_270 )
F_133 ( V_6 , V_10 ) ;
#ifdef F_138
if ( V_6 -> V_3 . V_274 > 0 ) {
V_6 -> V_3 . V_274 -- ;
V_6 -> V_3 . V_224 ++ ;
}
if ( V_6 -> V_3 . V_274 > 0 ) {
V_7 = F_152 ( V_6 , V_10 ) ;
if ( V_7 == V_85 ) {
V_6 -> V_269 = 1 ;
return V_7 ;
}
}
#endif
} else if ( V_6 -> V_3 . V_298 ) {
V_205 * V_299 = V_10 -> V_300 . V_299 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_299 [ V_18 ] ) ;
V_6 -> V_3 . V_298 = 0 ;
} else if ( V_6 -> V_3 . V_301 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_302 . V_200 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_302 . args [ V_18 ] ) ;
V_6 -> V_3 . V_301 = 0 ;
#ifdef F_67
} else if ( V_6 -> V_3 . V_303 ) {
F_165 ( V_6 , V_10 -> V_304 . V_304 ) ;
V_6 -> V_3 . V_303 = 0 ;
#endif
}
if ( V_6 -> V_305 )
F_166 ( V_306 , & V_6 -> V_307 , & V_297 ) ;
if ( V_10 -> V_308 )
V_7 = - V_13 ;
else
V_7 = F_167 ( V_10 , V_6 ) ;
if ( V_6 -> V_305 )
F_166 ( V_306 , & V_297 , NULL ) ;
return V_7 ;
}
int F_168 ( struct V_1 * V_6 , struct V_309 * V_310 )
{
if ( V_310 -> V_310 == V_311 ) {
F_169 ( V_6 ) ;
return 0 ;
}
F_170 ( V_6 , V_310 ) ;
F_171 ( V_6 ) ;
return 0 ;
}
static int F_172 ( struct V_1 * V_6 ,
struct V_312 * V_313 )
{
int V_7 ;
if ( V_313 -> V_314 )
return - V_70 ;
switch ( V_313 -> V_313 ) {
case V_140 :
V_7 = 0 ;
V_6 -> V_3 . V_315 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_313 -> args [ 0 ] )
V_6 -> V_3 . V_316 |= V_317 ;
else
V_6 -> V_3 . V_316 &= ~ V_317 ;
break;
#ifdef F_67
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_318 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_142 )
case V_143 : {
struct V_319 V_320 ;
void V_294 * V_321 = ( void V_294 * ) ( V_322 ) V_313 -> args [ 0 ] ;
V_7 = - V_296 ;
if ( F_161 ( & V_320 , V_321 , sizeof( V_320 ) ) )
break;
V_7 = F_173 ( V_6 , & V_320 ) ;
break;
}
#endif
#ifdef F_68
case V_144 : {
struct V_323 V_324 ;
struct V_325 * V_326 ;
V_7 = - V_327 ;
V_324 = F_174 ( V_313 -> args [ 0 ] ) ;
if ( ! V_324 . V_173 )
break;
V_7 = - V_101 ;
V_326 = F_175 ( V_324 . V_173 ) ;
if ( V_326 )
V_7 = F_176 ( V_326 , V_6 , V_313 -> args [ 1 ] ) ;
F_177 ( V_324 ) ;
break;
}
#endif
#ifdef F_56
case V_151 : {
struct V_323 V_324 ;
struct V_325 * V_326 ;
V_7 = - V_327 ;
V_324 = F_174 ( V_313 -> args [ 0 ] ) ;
if ( ! V_324 . V_173 )
break;
V_7 = - V_101 ;
V_326 = F_175 ( V_324 . V_173 ) ;
if ( V_326 ) {
if ( F_93 () )
V_7 = F_178 ( V_326 , V_6 , V_313 -> args [ 1 ] ) ;
else
V_7 = F_179 ( V_326 , V_6 , V_313 -> args [ 1 ] ) ;
}
F_177 ( V_324 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
break;
}
if ( ! V_7 )
V_7 = F_32 ( V_6 ) ;
return V_7 ;
}
bool F_180 ( struct V_67 * V_67 )
{
#ifdef F_68
if ( V_67 -> V_3 . V_194 )
return true ;
#endif
#ifdef F_56
if ( V_67 -> V_3 . V_328 || V_67 -> V_3 . V_329 )
return true ;
#endif
return false ;
}
int F_181 ( struct V_1 * V_6 ,
struct V_330 * V_331 )
{
return - V_70 ;
}
int F_182 ( struct V_1 * V_6 ,
struct V_330 * V_331 )
{
return - V_70 ;
}
long F_183 ( struct V_173 * V_174 ,
unsigned int V_175 , unsigned long V_176 )
{
struct V_1 * V_6 = V_174 -> V_332 ;
void V_294 * V_333 = ( void V_294 * ) V_176 ;
long V_7 ;
switch ( V_175 ) {
case V_334 : {
struct V_309 V_310 ;
V_7 = - V_296 ;
if ( F_161 ( & V_310 , V_333 , sizeof( V_310 ) ) )
goto V_63;
V_7 = F_168 ( V_6 , & V_310 ) ;
goto V_63;
}
case V_335 :
{
struct V_312 V_313 ;
V_7 = - V_296 ;
if ( F_161 ( & V_313 , V_333 , sizeof( V_313 ) ) )
goto V_63;
V_7 = F_172 ( V_6 , & V_313 ) ;
break;
}
case V_336 :
case V_337 :
{
struct V_284 V_276 ;
V_7 = - V_296 ;
if ( F_161 ( & V_276 , V_333 , sizeof( V_276 ) ) )
goto V_63;
if ( V_175 == V_336 )
V_7 = F_160 ( V_6 , & V_276 ) ;
else
V_7 = F_154 ( V_6 , & V_276 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_142 )
case V_338 : {
struct V_339 V_340 ;
V_7 = - V_296 ;
if ( F_161 ( & V_340 , V_333 , sizeof( V_340 ) ) )
goto V_63;
V_7 = F_184 ( V_6 , & V_340 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_185 ( struct V_1 * V_6 , struct V_341 * V_342 )
{
return V_343 ;
}
static int F_186 ( struct V_344 * V_345 )
{
T_2 V_346 = 0x60000000 ;
#ifdef F_34
T_2 V_347 = 0x44000022 ;
V_345 -> V_348 [ 0 ] = F_187 ( V_347 ) ;
V_345 -> V_348 [ 1 ] = F_187 ( V_346 ) ;
V_345 -> V_348 [ 2 ] = F_187 ( V_346 ) ;
V_345 -> V_348 [ 3 ] = F_187 ( V_346 ) ;
#else
T_2 V_349 = 0x3c000000 ;
T_2 V_350 = 0x60000000 ;
T_2 V_351 = 0x44000002 ;
T_2 V_352 = 0xffff ;
V_345 -> V_348 [ 0 ] = F_187 ( V_349 | ( ( V_353 >> 16 ) & V_352 ) ) ;
V_345 -> V_348 [ 1 ] = F_187 ( V_350 | ( V_353 & V_352 ) ) ;
V_345 -> V_348 [ 2 ] = F_187 ( V_351 ) ;
V_345 -> V_348 [ 3 ] = F_187 ( V_346 ) ;
#endif
V_345 -> V_314 = V_354 ;
return 0 ;
}
int F_188 ( struct V_67 * V_67 , struct V_355 * V_356 ,
bool V_357 )
{
if ( ! F_189 ( V_67 ) )
return - V_288 ;
V_356 -> V_358 = F_190 ( V_67 , V_359 ,
V_356 -> V_310 , V_356 -> V_360 ,
V_357 ) ;
return 0 ;
}
static int F_191 ( struct V_67 * V_67 ,
struct V_312 * V_313 )
{
int V_7 ;
if ( V_313 -> V_314 )
return - V_70 ;
switch ( V_313 -> V_313 ) {
#ifdef F_192
case V_150 : {
unsigned long V_348 = V_313 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_348 > V_361 || ( V_348 & 3 ) ||
V_313 -> args [ 1 ] > 1 )
break;
if ( ! F_193 ( V_67 , V_348 ) )
break;
if ( V_313 -> args [ 1 ] )
F_194 ( V_348 / 4 , V_67 -> V_3 . V_362 ) ;
else
F_195 ( V_348 / 4 , V_67 -> V_3 . V_362 ) ;
V_7 = 0 ;
break;
}
#endif
default:
V_7 = - V_70 ;
break;
}
return V_7 ;
}
long F_196 ( struct V_173 * V_174 ,
unsigned int V_175 , unsigned long V_176 )
{
struct V_67 * V_67 T_1 = V_174 -> V_332 ;
void V_294 * V_333 = ( void V_294 * ) V_176 ;
long V_7 ;
switch ( V_175 ) {
case V_363 : {
struct V_344 V_345 ;
memset ( & V_345 , 0 , sizeof( V_345 ) ) ;
V_7 = F_186 ( & V_345 ) ;
if ( F_159 ( V_333 , & V_345 , sizeof( V_345 ) ) ) {
V_7 = - V_296 ;
goto V_63;
}
break;
}
case V_335 :
{
struct V_312 V_313 ;
V_7 = - V_296 ;
if ( F_161 ( & V_313 , V_333 , sizeof( V_313 ) ) )
goto V_63;
V_7 = F_191 ( V_67 , & V_313 ) ;
break;
}
#ifdef F_197
case V_364 : {
struct V_365 V_366 ;
V_7 = - V_296 ;
if ( F_161 ( & V_366 , V_333 , sizeof( V_366 ) ) )
goto V_63;
if ( V_366 . V_314 ) {
V_7 = - V_70 ;
goto V_63;
}
V_7 = F_198 ( V_67 , & V_366 ) ;
goto V_63;
}
case V_367 : {
struct V_368 V_369 ;
struct V_365 V_366 ;
V_7 = - V_296 ;
if ( F_161 ( & V_369 , V_333 , sizeof( V_369 ) ) )
goto V_63;
V_366 . V_370 = V_369 . V_370 ;
V_366 . V_371 = V_372 ;
V_366 . V_220 = 0 ;
V_366 . V_87 = V_369 . V_373 >>
V_372 ;
V_366 . V_314 = 0 ;
V_7 = F_198 ( V_67 , & V_366 ) ;
goto V_63;
}
#endif
#ifdef V_38
case V_374 : {
struct V_375 V_376 ;
struct V_67 * V_67 = V_174 -> V_332 ;
memset ( & V_376 , 0 , sizeof( V_376 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_377 ( V_67 , & V_376 ) ;
if ( V_7 >= 0 && F_159 ( V_333 , & V_376 , sizeof( V_376 ) ) )
V_7 = - V_296 ;
break;
}
case V_378 : {
struct V_67 * V_67 = V_174 -> V_332 ;
V_7 = F_199 ( V_67 , V_333 ) ;
break;
}
case V_379 : {
struct V_67 * V_67 = V_174 -> V_332 ;
struct V_380 V_320 ;
V_7 = - V_70 ;
if ( ! V_67 -> V_3 . V_112 -> V_381 )
goto V_63;
V_7 = - V_296 ;
if ( F_161 ( & V_320 , V_333 , sizeof( V_320 ) ) )
goto V_63;
V_7 = V_67 -> V_3 . V_112 -> V_381 ( V_67 , & V_320 ) ;
break;
}
case V_382 : {
struct V_67 * V_67 = V_174 -> V_332 ;
struct V_383 V_376 ;
V_7 = - V_70 ;
if ( ! V_67 -> V_3 . V_112 -> V_384 )
goto V_63;
V_7 = V_67 -> V_3 . V_112 -> V_384 ( V_67 , & V_376 ) ;
if ( V_7 >= 0 && F_159 ( V_333 , & V_376 , sizeof( V_376 ) ) )
V_7 = - V_296 ;
break;
}
default: {
struct V_67 * V_67 = V_174 -> V_332 ;
V_7 = V_67 -> V_3 . V_112 -> V_385 ( V_174 , V_175 , V_176 ) ;
}
#else
default:
V_7 = - V_386 ;
#endif
}
V_63:
return V_7 ;
}
long F_200 ( void )
{
long V_387 ;
do {
V_387 = F_201 ( V_388 , V_389 ) ;
if ( V_387 >= V_390 ) {
F_202 ( L_5 , V_84 ) ;
return - V_391 ;
}
} while ( F_203 ( V_387 , V_388 ) );
return V_387 ;
}
void F_204 ( long V_387 )
{
F_194 ( V_387 , V_388 ) ;
}
void F_205 ( long V_387 )
{
F_195 ( V_387 , V_388 ) ;
}
void F_206 ( unsigned long V_392 )
{
V_390 = F_207 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_388 , 0 , sizeof( V_388 ) ) ;
}
int F_208 ( void * V_393 )
{
return 0 ;
}
