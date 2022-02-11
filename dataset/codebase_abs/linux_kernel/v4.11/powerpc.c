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
F_30 ( V_60 , & V_6 -> V_5 ) ;
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
V_7 = V_145 ;
break;
#endif
#ifdef F_69
case V_146 :
V_7 = 1 ;
break;
#endif
#ifdef V_38
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
#ifdef F_56
case V_152 :
#endif
V_7 = 1 ;
break;
case V_153 :
V_7 = V_124 ;
break;
#endif
#ifdef F_70
case V_154 :
V_7 = 0 ;
if ( V_124 ) {
if ( F_35 ( V_155 ) )
V_7 = 1 ;
else
V_7 = V_156 ;
}
break;
case V_157 :
V_7 = 0 ;
break;
case V_158 :
V_7 = F_71 () ;
break;
case V_159 :
V_7 = ! ! ( V_124 && F_72 () ) ;
break;
case V_160 :
V_7 = ! ! ( V_124 && ! F_72 () &&
F_35 ( V_155 ) ) ;
break;
#endif
case V_161 :
#ifdef F_70
V_7 = V_124 ;
#elif F_25 ( V_162 )
V_7 = 1 ;
#else
V_7 = 0 ;
#endif
break;
#ifdef F_70
case V_163 :
V_7 = V_124 ;
break;
#endif
case V_164 :
if ( V_124 )
V_7 = F_73 () ;
else
V_7 = F_74 () ;
break;
case V_165 :
V_7 = V_166 ;
break;
case V_167 :
V_7 = V_168 ;
break;
#ifdef V_38
case V_169 :
V_7 = 1 ;
break;
case V_170 :
V_7 = 1 ;
break;
case V_171 :
V_7 = ! ! V_124 && ! F_35 ( V_155 ) ;
break;
#endif
case V_172 :
V_7 = F_35 ( V_173 ) &&
F_33 ( V_67 ) ;
break;
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_75 ( struct V_174 * V_175 ,
unsigned int V_176 , unsigned long V_177 )
{
return - V_70 ;
}
void F_76 ( struct V_67 * V_67 , struct V_178 * free ,
struct V_178 * V_179 )
{
F_77 ( V_67 , free , V_179 ) ;
}
int F_78 ( struct V_67 * V_67 , struct V_178 * V_180 ,
unsigned long V_181 )
{
return F_79 ( V_67 , V_180 , V_181 ) ;
}
int F_80 ( struct V_67 * V_67 ,
struct V_178 * V_182 ,
const struct V_183 * V_184 ,
enum V_185 V_186 )
{
return F_81 ( V_67 , V_182 , V_184 ) ;
}
void F_82 ( struct V_67 * V_67 ,
const struct V_183 * V_184 ,
const struct V_178 * V_187 ,
const struct V_178 * V_188 ,
enum V_185 V_186 )
{
F_83 ( V_67 , V_184 , V_187 , V_188 ) ;
}
void F_84 ( struct V_67 * V_67 ,
struct V_178 * V_180 )
{
F_85 ( V_67 , V_180 ) ;
}
struct V_1 * F_86 ( struct V_67 * V_67 , unsigned int V_189 )
{
struct V_1 * V_6 ;
V_6 = F_87 ( V_67 , V_189 ) ;
if ( ! F_88 ( V_6 ) ) {
V_6 -> V_3 . V_190 = & V_6 -> V_191 ;
F_89 ( V_6 , V_189 ) ;
}
return V_6 ;
}
void F_90 ( struct V_1 * V_6 )
{
}
void F_59 ( struct V_1 * V_6 )
{
F_91 ( & V_6 -> V_3 . V_192 ) ;
F_92 ( V_6 ) ;
switch ( V_6 -> V_3 . V_193 ) {
case V_194 :
F_93 ( V_6 -> V_3 . V_195 , V_6 ) ;
break;
case V_196 :
F_94 ( V_6 ) ;
break;
}
F_95 ( V_6 ) ;
}
void F_96 ( struct V_1 * V_6 )
{
F_59 ( V_6 ) ;
}
int F_97 ( struct V_1 * V_6 )
{
return F_98 ( V_6 ) ;
}
static enum V_197 F_99 ( struct V_198 * V_199 )
{
struct V_1 * V_6 ;
V_6 = F_100 ( V_199 , struct V_1 , V_3 . V_192 ) ;
F_101 ( V_6 ) ;
return V_200 ;
}
int F_102 ( struct V_1 * V_6 )
{
int V_201 ;
F_103 ( & V_6 -> V_3 . V_192 , V_202 , V_203 ) ;
V_6 -> V_3 . V_192 . V_204 = F_99 ;
V_6 -> V_3 . V_205 = ~ ( V_206 ) 0 ;
#ifdef F_104
F_105 ( & V_6 -> V_3 . V_207 ) ;
#endif
V_201 = F_106 ( V_6 ) ;
return V_201 ;
}
void F_107 ( struct V_1 * V_6 )
{
F_108 ( V_6 ) ;
F_109 ( V_6 ) ;
}
void F_110 ( struct V_1 * V_6 , int V_208 )
{
#ifdef F_67
F_111 ( V_209 , V_6 -> V_3 . V_210 ) ;
#endif
F_112 ( V_6 , V_208 ) ;
}
void F_113 ( struct V_1 * V_6 )
{
F_114 ( V_6 ) ;
#ifdef F_67
V_6 -> V_3 . V_210 = F_115 ( V_209 ) ;
#endif
}
bool F_116 ( void )
{
return ( ( V_113 && V_113 -> V_211 ) ||
( V_114 && V_114 -> V_211 ) ) ;
}
int F_117 ( struct V_212 * V_213 ,
struct V_214 * V_215 )
{
struct V_216 * V_217 =
F_100 ( V_213 , struct V_216 , V_218 ) ;
struct V_67 * V_67 = V_217 -> V_67 ;
if ( V_67 -> V_3 . V_112 -> V_211 )
return V_67 -> V_3 . V_112 -> V_211 ( V_213 , V_215 ) ;
return 0 ;
}
void F_118 ( struct V_212 * V_213 ,
struct V_214 * V_215 )
{
struct V_216 * V_217 =
F_100 ( V_213 , struct V_216 , V_218 ) ;
struct V_67 * V_67 = V_217 -> V_67 ;
if ( V_67 -> V_3 . V_112 -> V_219 )
V_67 -> V_3 . V_112 -> V_219 ( V_213 , V_215 ) ;
}
static void F_119 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_206 V_220 ( V_221 ) ;
if ( V_10 -> V_222 . V_223 > sizeof( V_221 ) ) {
F_120 ( V_224 L_2 , V_10 -> V_222 . V_223 ) ;
return;
}
if ( ! V_6 -> V_3 . V_225 ) {
switch ( V_10 -> V_222 . V_223 ) {
case 8 : V_221 = * ( V_206 * ) V_10 -> V_222 . V_89 ; break;
case 4 : V_221 = * ( T_2 * ) V_10 -> V_222 . V_89 ; break;
case 2 : V_221 = * ( V_226 * ) V_10 -> V_222 . V_89 ; break;
case 1 : V_221 = * ( V_227 * ) V_10 -> V_222 . V_89 ; break;
}
} else {
switch ( V_10 -> V_222 . V_223 ) {
case 8 : V_221 = F_18 ( * ( V_206 * ) V_10 -> V_222 . V_89 ) ; break;
case 4 : V_221 = F_19 ( * ( T_2 * ) V_10 -> V_222 . V_89 ) ; break;
case 2 : V_221 = F_121 ( * ( V_226 * ) V_10 -> V_222 . V_89 ) ; break;
case 1 : V_221 = * ( V_227 * ) V_10 -> V_222 . V_89 ; break;
}
}
if ( V_6 -> V_3 . V_228 ) {
switch ( V_10 -> V_222 . V_223 ) {
#ifdef F_122
case 4 :
V_221 = ( V_229 ) ( V_230 ) V_221 ;
break;
#endif
case 2 :
V_221 = ( V_229 ) ( V_231 ) V_221 ;
break;
case 1 :
V_221 = ( V_229 ) ( V_232 ) V_221 ;
break;
}
}
F_31 ( V_6 , V_6 -> V_3 . V_233 , V_221 ) ;
switch ( V_6 -> V_3 . V_233 & V_234 ) {
case V_235 :
F_31 ( V_6 , V_6 -> V_3 . V_233 , V_221 ) ;
break;
case V_236 :
F_123 ( V_6 , V_6 -> V_3 . V_233 & V_237 ) = V_221 ;
break;
#ifdef V_56
case V_238 :
V_6 -> V_3 . V_239 [ V_6 -> V_3 . V_233 & V_237 ] = V_221 ;
break;
case V_240 :
F_123 ( V_6 , V_6 -> V_3 . V_233 & V_237 ) = V_221 ;
V_6 -> V_3 . V_239 [ V_6 -> V_3 . V_233 & V_237 ] = V_221 ;
break;
#endif
default:
F_124 () ;
}
}
static int F_125 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_241 , unsigned int V_242 ,
int V_243 , int V_244 )
{
int V_245 , V_201 ;
bool V_246 ;
if ( F_126 ( V_6 ) ) {
V_246 = V_243 ;
} else {
V_246 = ! V_243 ;
}
if ( V_242 > sizeof( V_10 -> V_222 . V_89 ) ) {
F_120 ( V_224 L_3 , V_84 ,
V_10 -> V_222 . V_223 ) ;
}
V_10 -> V_222 . V_247 = V_6 -> V_3 . V_248 ;
V_10 -> V_222 . V_223 = V_242 ;
V_10 -> V_222 . V_249 = 0 ;
V_6 -> V_3 . V_233 = V_241 ;
V_6 -> V_3 . V_225 = V_246 ;
V_6 -> V_250 = 1 ;
V_6 -> V_251 = 0 ;
V_6 -> V_3 . V_228 = V_244 ;
V_245 = F_127 ( & V_6 -> V_67 -> V_252 ) ;
V_201 = F_128 ( V_6 , V_253 , V_10 -> V_222 . V_247 ,
V_242 , & V_10 -> V_222 . V_89 ) ;
F_129 ( & V_6 -> V_67 -> V_252 , V_245 ) ;
if ( ! V_201 ) {
F_119 ( V_6 , V_10 ) ;
V_6 -> V_250 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_130 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_241 , unsigned int V_242 ,
int V_243 )
{
return F_125 ( V_10 , V_6 , V_241 , V_242 , V_243 , 0 ) ;
}
int F_131 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_241 , unsigned int V_242 ,
int V_243 )
{
return F_125 ( V_10 , V_6 , V_241 , V_242 , V_243 , 1 ) ;
}
int F_132 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_206 V_254 , unsigned int V_242 , int V_243 )
{
void * V_89 = V_10 -> V_222 . V_89 ;
int V_245 , V_201 ;
bool V_246 ;
if ( F_126 ( V_6 ) ) {
V_246 = V_243 ;
} else {
V_246 = ! V_243 ;
}
if ( V_242 > sizeof( V_10 -> V_222 . V_89 ) ) {
F_120 ( V_224 L_3 , V_84 ,
V_10 -> V_222 . V_223 ) ;
}
V_10 -> V_222 . V_247 = V_6 -> V_3 . V_248 ;
V_10 -> V_222 . V_223 = V_242 ;
V_10 -> V_222 . V_249 = 1 ;
V_6 -> V_250 = 1 ;
V_6 -> V_251 = 1 ;
if ( ! V_246 ) {
switch ( V_242 ) {
case 8 : * ( V_206 * ) V_89 = V_254 ; break;
case 4 : * ( T_2 * ) V_89 = V_254 ; break;
case 2 : * ( V_226 * ) V_89 = V_254 ; break;
case 1 : * ( V_227 * ) V_89 = V_254 ; break;
}
} else {
switch ( V_242 ) {
case 8 : * ( V_206 * ) V_89 = F_18 ( V_254 ) ; break;
case 4 : * ( T_2 * ) V_89 = F_19 ( V_254 ) ; break;
case 2 : * ( V_226 * ) V_89 = F_121 ( V_254 ) ; break;
case 1 : * ( V_227 * ) V_89 = V_254 ; break;
}
}
V_245 = F_127 ( & V_6 -> V_67 -> V_252 ) ;
V_201 = F_133 ( V_6 , V_253 , V_10 -> V_222 . V_247 ,
V_242 , & V_10 -> V_222 . V_89 ) ;
F_129 ( & V_6 -> V_67 -> V_252 , V_245 ) ;
if ( ! V_201 ) {
V_6 -> V_250 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_134 ( struct V_1 * V_6 , struct V_255 * V_256 )
{
int V_7 = 0 ;
union V_257 V_254 ;
int V_87 ;
V_87 = F_135 ( V_256 -> V_189 ) ;
if ( V_87 > sizeof( V_254 ) )
return - V_70 ;
V_7 = F_136 ( V_6 , V_256 -> V_189 , & V_254 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_256 -> V_189 ) {
#ifdef F_137
case V_258 ... V_259 :
if ( ! F_35 ( V_260 ) ) {
V_7 = - V_261 ;
break;
}
V_254 . V_262 = V_6 -> V_3 . V_263 . V_263 [ V_256 -> V_189 - V_258 ] ;
break;
case V_264 :
if ( ! F_35 ( V_260 ) ) {
V_7 = - V_261 ;
break;
}
V_254 = F_138 ( V_256 -> V_189 , V_6 -> V_3 . V_263 . V_265 . V_266 [ 3 ] ) ;
break;
case V_267 :
V_254 = F_138 ( V_256 -> V_189 , V_6 -> V_3 . V_210 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
if ( V_7 )
return V_7 ;
if ( F_139 ( ( char V_268 * ) ( unsigned long ) V_256 -> V_269 , & V_254 , V_87 ) )
V_7 = - V_270 ;
return V_7 ;
}
int F_140 ( struct V_1 * V_6 , struct V_255 * V_256 )
{
int V_7 ;
union V_257 V_254 ;
int V_87 ;
V_87 = F_135 ( V_256 -> V_189 ) ;
if ( V_87 > sizeof( V_254 ) )
return - V_70 ;
if ( F_141 ( & V_254 , ( char V_268 * ) ( unsigned long ) V_256 -> V_269 , V_87 ) )
return - V_270 ;
V_7 = F_142 ( V_6 , V_256 -> V_189 , & V_254 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_256 -> V_189 ) {
#ifdef F_137
case V_258 ... V_259 :
if ( ! F_35 ( V_260 ) ) {
V_7 = - V_261 ;
break;
}
V_6 -> V_3 . V_263 . V_263 [ V_256 -> V_189 - V_258 ] = V_254 . V_262 ;
break;
case V_264 :
if ( ! F_35 ( V_260 ) ) {
V_7 = - V_261 ;
break;
}
V_6 -> V_3 . V_263 . V_265 . V_266 [ 3 ] = F_143 ( V_256 -> V_189 , V_254 ) ;
break;
case V_267 :
if ( ! F_35 ( V_260 ) ) {
V_7 = - V_261 ;
break;
}
V_6 -> V_3 . V_210 = F_143 ( V_256 -> V_189 , V_254 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
return V_7 ;
}
int F_144 ( struct V_1 * V_6 , struct V_71 * V_10 )
{
int V_7 ;
T_3 V_271 ;
if ( V_6 -> V_272 )
F_145 ( V_273 , & V_6 -> V_274 , & V_271 ) ;
if ( V_6 -> V_250 ) {
if ( ! V_6 -> V_251 )
F_119 ( V_6 , V_10 ) ;
V_6 -> V_250 = 0 ;
} else if ( V_6 -> V_3 . V_275 ) {
V_206 * V_276 = V_10 -> V_277 . V_276 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_276 [ V_18 ] ) ;
V_6 -> V_3 . V_275 = 0 ;
} else if ( V_6 -> V_3 . V_278 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_279 . V_201 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_279 . args [ V_18 ] ) ;
V_6 -> V_3 . V_278 = 0 ;
#ifdef F_67
} else if ( V_6 -> V_3 . V_280 ) {
F_146 ( V_6 , V_10 -> V_281 . V_281 ) ;
V_6 -> V_3 . V_280 = 0 ;
#endif
}
if ( V_10 -> V_282 )
V_7 = - V_13 ;
else
V_7 = F_147 ( V_10 , V_6 ) ;
if ( V_6 -> V_272 )
F_145 ( V_273 , & V_271 , NULL ) ;
return V_7 ;
}
int F_148 ( struct V_1 * V_6 , struct V_283 * V_284 )
{
if ( V_284 -> V_284 == V_285 ) {
F_149 ( V_6 ) ;
return 0 ;
}
F_150 ( V_6 , V_284 ) ;
F_151 ( V_6 ) ;
return 0 ;
}
static int F_152 ( struct V_1 * V_6 ,
struct V_286 * V_287 )
{
int V_7 ;
if ( V_287 -> V_288 )
return - V_70 ;
switch ( V_287 -> V_287 ) {
case V_140 :
V_7 = 0 ;
V_6 -> V_3 . V_289 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_287 -> args [ 0 ] )
V_6 -> V_3 . V_290 |= V_291 ;
else
V_6 -> V_3 . V_290 &= ~ V_291 ;
break;
#ifdef F_67
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_292 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_142 )
case V_143 : {
struct V_293 V_294 ;
void V_268 * V_295 = ( void V_268 * ) ( V_296 ) V_287 -> args [ 0 ] ;
V_7 = - V_270 ;
if ( F_141 ( & V_294 , V_295 , sizeof( V_294 ) ) )
break;
V_7 = F_153 ( V_6 , & V_294 ) ;
break;
}
#endif
#ifdef F_69
case V_146 : {
struct V_297 V_298 ;
struct V_299 * V_300 ;
V_7 = - V_301 ;
V_298 = F_154 ( V_287 -> args [ 0 ] ) ;
if ( ! V_298 . V_174 )
break;
V_7 = - V_101 ;
V_300 = F_155 ( V_298 . V_174 ) ;
if ( V_300 )
V_7 = F_156 ( V_300 , V_6 , V_287 -> args [ 1 ] ) ;
F_157 ( V_298 ) ;
break;
}
#endif
#ifdef F_56
case V_152 : {
struct V_297 V_298 ;
struct V_299 * V_300 ;
V_7 = - V_301 ;
V_298 = F_154 ( V_287 -> args [ 0 ] ) ;
if ( ! V_298 . V_174 )
break;
V_7 = - V_101 ;
V_300 = F_155 ( V_298 . V_174 ) ;
if ( V_300 )
V_7 = F_158 ( V_300 , V_6 , V_287 -> args [ 1 ] ) ;
F_157 ( V_298 ) ;
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
bool F_159 ( struct V_67 * V_67 )
{
#ifdef F_69
if ( V_67 -> V_3 . V_195 )
return true ;
#endif
#ifdef F_56
if ( V_67 -> V_3 . V_302 )
return true ;
#endif
return false ;
}
int F_160 ( struct V_1 * V_6 ,
struct V_303 * V_304 )
{
return - V_70 ;
}
int F_161 ( struct V_1 * V_6 ,
struct V_303 * V_304 )
{
return - V_70 ;
}
long F_162 ( struct V_174 * V_175 ,
unsigned int V_176 , unsigned long V_177 )
{
struct V_1 * V_6 = V_175 -> V_305 ;
void V_268 * V_306 = ( void V_268 * ) V_177 ;
long V_7 ;
switch ( V_176 ) {
case V_307 : {
struct V_283 V_284 ;
V_7 = - V_270 ;
if ( F_141 ( & V_284 , V_306 , sizeof( V_284 ) ) )
goto V_63;
V_7 = F_148 ( V_6 , & V_284 ) ;
goto V_63;
}
case V_308 :
{
struct V_286 V_287 ;
V_7 = - V_270 ;
if ( F_141 ( & V_287 , V_306 , sizeof( V_287 ) ) )
goto V_63;
V_7 = F_152 ( V_6 , & V_287 ) ;
break;
}
case V_309 :
case V_310 :
{
struct V_255 V_256 ;
V_7 = - V_270 ;
if ( F_141 ( & V_256 , V_306 , sizeof( V_256 ) ) )
goto V_63;
if ( V_176 == V_309 )
V_7 = F_140 ( V_6 , & V_256 ) ;
else
V_7 = F_134 ( V_6 , & V_256 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_142 )
case V_311 : {
struct V_312 V_313 ;
V_7 = - V_270 ;
if ( F_141 ( & V_313 , V_306 , sizeof( V_313 ) ) )
goto V_63;
V_7 = F_163 ( V_6 , & V_313 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_164 ( struct V_1 * V_6 , struct V_314 * V_315 )
{
return V_316 ;
}
static int F_165 ( struct V_317 * V_318 )
{
T_2 V_319 = 0x60000000 ;
#ifdef F_34
T_2 V_320 = 0x44000022 ;
V_318 -> V_321 [ 0 ] = F_166 ( V_320 ) ;
V_318 -> V_321 [ 1 ] = F_166 ( V_319 ) ;
V_318 -> V_321 [ 2 ] = F_166 ( V_319 ) ;
V_318 -> V_321 [ 3 ] = F_166 ( V_319 ) ;
#else
T_2 V_322 = 0x3c000000 ;
T_2 V_323 = 0x60000000 ;
T_2 V_324 = 0x44000002 ;
T_2 V_325 = 0xffff ;
V_318 -> V_321 [ 0 ] = F_166 ( V_322 | ( ( V_326 >> 16 ) & V_325 ) ) ;
V_318 -> V_321 [ 1 ] = F_166 ( V_323 | ( V_326 & V_325 ) ) ;
V_318 -> V_321 [ 2 ] = F_166 ( V_324 ) ;
V_318 -> V_321 [ 3 ] = F_166 ( V_319 ) ;
#endif
V_318 -> V_288 = V_327 ;
return 0 ;
}
int F_167 ( struct V_67 * V_67 , struct V_328 * V_329 ,
bool V_330 )
{
if ( ! F_168 ( V_67 ) )
return - V_261 ;
V_329 -> V_331 = F_169 ( V_67 , V_332 ,
V_329 -> V_284 , V_329 -> V_333 ,
V_330 ) ;
return 0 ;
}
static int F_170 ( struct V_67 * V_67 ,
struct V_286 * V_287 )
{
int V_7 ;
if ( V_287 -> V_288 )
return - V_70 ;
switch ( V_287 -> V_287 ) {
#ifdef F_171
case V_151 : {
unsigned long V_321 = V_287 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_321 > V_334 || ( V_321 & 3 ) ||
V_287 -> args [ 1 ] > 1 )
break;
if ( ! F_172 ( V_67 , V_321 ) )
break;
if ( V_287 -> args [ 1 ] )
F_173 ( V_321 / 4 , V_67 -> V_3 . V_335 ) ;
else
F_30 ( V_321 / 4 , V_67 -> V_3 . V_335 ) ;
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
long F_174 ( struct V_174 * V_175 ,
unsigned int V_176 , unsigned long V_177 )
{
struct V_67 * V_67 T_1 = V_175 -> V_305 ;
void V_268 * V_306 = ( void V_268 * ) V_177 ;
long V_7 ;
switch ( V_176 ) {
case V_336 : {
struct V_317 V_318 ;
memset ( & V_318 , 0 , sizeof( V_318 ) ) ;
V_7 = F_165 ( & V_318 ) ;
if ( F_139 ( V_306 , & V_318 , sizeof( V_318 ) ) ) {
V_7 = - V_270 ;
goto V_63;
}
break;
}
case V_308 :
{
struct V_286 V_287 ;
V_7 = - V_270 ;
if ( F_141 ( & V_287 , V_306 , sizeof( V_287 ) ) )
goto V_63;
V_7 = F_170 ( V_67 , & V_287 ) ;
break;
}
#ifdef V_38
case V_337 : {
struct V_338 V_339 ;
V_7 = - V_270 ;
if ( F_141 ( & V_339 , V_306 , sizeof( V_339 ) ) )
goto V_63;
if ( V_339 . V_288 ) {
V_7 = - V_70 ;
goto V_63;
}
V_7 = F_175 ( V_67 , & V_339 ) ;
goto V_63;
}
case V_340 : {
struct V_341 V_342 ;
struct V_338 V_339 ;
V_7 = - V_270 ;
if ( F_141 ( & V_342 , V_306 , sizeof( V_342 ) ) )
goto V_63;
V_339 . V_343 = V_342 . V_343 ;
V_339 . V_344 = V_345 ;
V_339 . V_346 = 0 ;
V_339 . V_87 = V_342 . V_347 >>
V_345 ;
V_339 . V_288 = 0 ;
V_7 = F_175 ( V_67 , & V_339 ) ;
goto V_63;
}
case V_348 : {
struct V_349 V_350 ;
struct V_67 * V_67 = V_175 -> V_305 ;
memset ( & V_350 , 0 , sizeof( V_350 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_351 ( V_67 , & V_350 ) ;
if ( V_7 >= 0 && F_139 ( V_306 , & V_350 , sizeof( V_350 ) ) )
V_7 = - V_270 ;
break;
}
case V_352 : {
struct V_67 * V_67 = V_175 -> V_305 ;
V_7 = F_176 ( V_67 , V_306 ) ;
break;
}
case V_353 : {
struct V_67 * V_67 = V_175 -> V_305 ;
struct V_354 V_294 ;
V_7 = - V_70 ;
if ( ! V_67 -> V_3 . V_112 -> V_355 )
goto V_63;
V_7 = - V_270 ;
if ( F_141 ( & V_294 , V_306 , sizeof( V_294 ) ) )
goto V_63;
V_7 = V_67 -> V_3 . V_112 -> V_355 ( V_67 , & V_294 ) ;
break;
}
case V_356 : {
struct V_67 * V_67 = V_175 -> V_305 ;
struct V_357 V_350 ;
V_7 = - V_70 ;
if ( ! V_67 -> V_3 . V_112 -> V_358 )
goto V_63;
V_7 = V_67 -> V_3 . V_112 -> V_358 ( V_67 , & V_350 ) ;
if ( V_7 >= 0 && F_139 ( V_306 , & V_350 , sizeof( V_350 ) ) )
V_7 = - V_270 ;
break;
}
default: {
struct V_67 * V_67 = V_175 -> V_305 ;
V_7 = V_67 -> V_3 . V_112 -> V_359 ( V_175 , V_176 , V_177 ) ;
}
#else
default:
V_7 = - V_360 ;
#endif
}
V_63:
return V_7 ;
}
long F_177 ( void )
{
long V_361 ;
do {
V_361 = F_178 ( V_362 , V_363 ) ;
if ( V_361 >= V_364 ) {
F_179 ( L_4 , V_84 ) ;
return - V_365 ;
}
} while ( F_180 ( V_361 , V_362 ) );
return V_361 ;
}
void F_181 ( long V_361 )
{
F_173 ( V_361 , V_362 ) ;
}
void F_182 ( long V_361 )
{
F_30 ( V_361 , V_362 ) ;
}
void F_183 ( unsigned long V_366 )
{
V_364 = F_184 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_362 , 0 , sizeof( V_362 ) ) ;
}
int F_185 ( void * V_367 )
{
return 0 ;
}
