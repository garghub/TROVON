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
V_7 = 1 ;
break;
case V_138 :
case V_139 :
case V_140 :
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_142 :
#endif
V_7 = ! V_124 ;
break;
#ifdef F_68
case V_143 :
V_7 = V_144 ;
break;
#endif
#ifdef F_69
case V_145 :
V_7 = 1 ;
break;
#endif
#ifdef V_38
case V_146 :
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
#endif
#ifdef F_70
case V_153 :
if ( V_124 )
V_7 = V_154 ;
else
V_7 = 0 ;
break;
case V_155 :
V_7 = 0 ;
break;
case V_156 :
V_7 = F_71 () ;
break;
#endif
case V_157 :
#ifdef F_70
V_7 = V_124 ;
#elif F_25 ( V_158 )
V_7 = 1 ;
#else
V_7 = 0 ;
#endif
break;
#ifdef F_70
case V_159 :
V_7 = V_124 ;
break;
#endif
case V_160 :
if ( V_124 )
V_7 = F_72 () ;
else
V_7 = F_73 () ;
break;
case V_161 :
V_7 = V_162 ;
break;
case V_163 :
V_7 = V_164 ;
break;
#ifdef V_38
case V_165 :
V_7 = 1 ;
break;
case V_166 :
V_7 = 1 ;
break;
#endif
case V_167 :
V_7 = F_35 ( V_168 ) &&
F_33 ( V_67 ) ;
break;
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_74 ( struct V_169 * V_170 ,
unsigned int V_171 , unsigned long V_172 )
{
return - V_70 ;
}
void F_75 ( struct V_67 * V_67 , struct V_173 * free ,
struct V_173 * V_174 )
{
F_76 ( V_67 , free , V_174 ) ;
}
int F_77 ( struct V_67 * V_67 , struct V_173 * V_175 ,
unsigned long V_176 )
{
return F_78 ( V_67 , V_175 , V_176 ) ;
}
int F_79 ( struct V_67 * V_67 ,
struct V_173 * V_177 ,
const struct V_178 * V_179 ,
enum V_180 V_181 )
{
return F_80 ( V_67 , V_177 , V_179 ) ;
}
void F_81 ( struct V_67 * V_67 ,
const struct V_178 * V_179 ,
const struct V_173 * V_182 ,
const struct V_173 * V_183 ,
enum V_180 V_181 )
{
F_82 ( V_67 , V_179 , V_182 , V_183 ) ;
}
void F_83 ( struct V_67 * V_67 ,
struct V_173 * V_175 )
{
F_84 ( V_67 , V_175 ) ;
}
struct V_1 * F_85 ( struct V_67 * V_67 , unsigned int V_184 )
{
struct V_1 * V_6 ;
V_6 = F_86 ( V_67 , V_184 ) ;
if ( ! F_87 ( V_6 ) ) {
V_6 -> V_3 . V_185 = & V_6 -> V_186 ;
F_88 ( V_6 , V_184 ) ;
}
return V_6 ;
}
void F_89 ( struct V_1 * V_6 )
{
}
void F_59 ( struct V_1 * V_6 )
{
F_90 ( & V_6 -> V_3 . V_187 ) ;
F_91 ( V_6 ) ;
switch ( V_6 -> V_3 . V_188 ) {
case V_189 :
F_92 ( V_6 -> V_3 . V_190 , V_6 ) ;
break;
case V_191 :
F_93 ( V_6 ) ;
break;
}
F_94 ( V_6 ) ;
}
void F_95 ( struct V_1 * V_6 )
{
F_59 ( V_6 ) ;
}
int F_96 ( struct V_1 * V_6 )
{
return F_97 ( V_6 ) ;
}
static enum V_192 F_98 ( struct V_193 * V_194 )
{
struct V_1 * V_6 ;
V_6 = F_99 ( V_194 , struct V_1 , V_3 . V_187 ) ;
F_100 ( V_6 ) ;
return V_195 ;
}
int F_101 ( struct V_1 * V_6 )
{
int V_196 ;
F_102 ( & V_6 -> V_3 . V_187 , V_197 , V_198 ) ;
V_6 -> V_3 . V_187 . V_199 = F_98 ;
V_6 -> V_3 . V_200 = ~ ( V_201 ) 0 ;
#ifdef F_103
F_104 ( & V_6 -> V_3 . V_202 ) ;
#endif
V_196 = F_105 ( V_6 ) ;
return V_196 ;
}
void F_106 ( struct V_1 * V_6 )
{
F_107 ( V_6 ) ;
F_108 ( V_6 ) ;
}
void F_109 ( struct V_1 * V_6 , int V_203 )
{
#ifdef F_67
F_110 ( V_204 , V_6 -> V_3 . V_205 ) ;
#endif
F_111 ( V_6 , V_203 ) ;
}
void F_112 ( struct V_1 * V_6 )
{
F_113 ( V_6 ) ;
#ifdef F_67
V_6 -> V_3 . V_205 = F_114 ( V_204 ) ;
#endif
}
bool F_115 ( void )
{
return ( ( V_113 && V_113 -> V_206 ) ||
( V_114 && V_114 -> V_206 ) ) ;
}
int F_116 ( struct V_207 * V_208 ,
struct V_209 * V_210 )
{
struct V_211 * V_212 =
F_99 ( V_208 , struct V_211 , V_213 ) ;
struct V_67 * V_67 = V_212 -> V_67 ;
if ( V_67 -> V_3 . V_112 -> V_206 )
return V_67 -> V_3 . V_112 -> V_206 ( V_208 , V_210 ) ;
return 0 ;
}
void F_117 ( struct V_207 * V_208 ,
struct V_209 * V_210 )
{
struct V_211 * V_212 =
F_99 ( V_208 , struct V_211 , V_213 ) ;
struct V_67 * V_67 = V_212 -> V_67 ;
if ( V_67 -> V_3 . V_112 -> V_214 )
V_67 -> V_3 . V_112 -> V_214 ( V_208 , V_210 ) ;
}
static void F_118 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_201 V_215 ( V_216 ) ;
if ( V_10 -> V_217 . V_218 > sizeof( V_216 ) ) {
F_119 ( V_219 L_2 , V_10 -> V_217 . V_218 ) ;
return;
}
if ( ! V_6 -> V_3 . V_220 ) {
switch ( V_10 -> V_217 . V_218 ) {
case 8 : V_216 = * ( V_201 * ) V_10 -> V_217 . V_89 ; break;
case 4 : V_216 = * ( T_2 * ) V_10 -> V_217 . V_89 ; break;
case 2 : V_216 = * ( V_221 * ) V_10 -> V_217 . V_89 ; break;
case 1 : V_216 = * ( V_222 * ) V_10 -> V_217 . V_89 ; break;
}
} else {
switch ( V_10 -> V_217 . V_218 ) {
case 8 : V_216 = F_18 ( * ( V_201 * ) V_10 -> V_217 . V_89 ) ; break;
case 4 : V_216 = F_19 ( * ( T_2 * ) V_10 -> V_217 . V_89 ) ; break;
case 2 : V_216 = F_120 ( * ( V_221 * ) V_10 -> V_217 . V_89 ) ; break;
case 1 : V_216 = * ( V_222 * ) V_10 -> V_217 . V_89 ; break;
}
}
if ( V_6 -> V_3 . V_223 ) {
switch ( V_10 -> V_217 . V_218 ) {
#ifdef F_121
case 4 :
V_216 = ( V_224 ) ( V_225 ) V_216 ;
break;
#endif
case 2 :
V_216 = ( V_224 ) ( V_226 ) V_216 ;
break;
case 1 :
V_216 = ( V_224 ) ( V_227 ) V_216 ;
break;
}
}
F_31 ( V_6 , V_6 -> V_3 . V_228 , V_216 ) ;
switch ( V_6 -> V_3 . V_228 & V_229 ) {
case V_230 :
F_31 ( V_6 , V_6 -> V_3 . V_228 , V_216 ) ;
break;
case V_231 :
F_122 ( V_6 , V_6 -> V_3 . V_228 & V_232 ) = V_216 ;
break;
#ifdef V_56
case V_233 :
V_6 -> V_3 . V_234 [ V_6 -> V_3 . V_228 & V_232 ] = V_216 ;
break;
case V_235 :
F_122 ( V_6 , V_6 -> V_3 . V_228 & V_232 ) = V_216 ;
V_6 -> V_3 . V_234 [ V_6 -> V_3 . V_228 & V_232 ] = V_216 ;
break;
#endif
default:
F_123 () ;
}
}
static int F_124 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_236 , unsigned int V_237 ,
int V_238 , int V_239 )
{
int V_240 , V_196 ;
bool V_241 ;
if ( F_125 ( V_6 ) ) {
V_241 = V_238 ;
} else {
V_241 = ! V_238 ;
}
if ( V_237 > sizeof( V_10 -> V_217 . V_89 ) ) {
F_119 ( V_219 L_3 , V_84 ,
V_10 -> V_217 . V_218 ) ;
}
V_10 -> V_217 . V_242 = V_6 -> V_3 . V_243 ;
V_10 -> V_217 . V_218 = V_237 ;
V_10 -> V_217 . V_244 = 0 ;
V_6 -> V_3 . V_228 = V_236 ;
V_6 -> V_3 . V_220 = V_241 ;
V_6 -> V_245 = 1 ;
V_6 -> V_246 = 0 ;
V_6 -> V_3 . V_223 = V_239 ;
V_240 = F_126 ( & V_6 -> V_67 -> V_247 ) ;
V_196 = F_127 ( V_6 , V_248 , V_10 -> V_217 . V_242 ,
V_237 , & V_10 -> V_217 . V_89 ) ;
F_128 ( & V_6 -> V_67 -> V_247 , V_240 ) ;
if ( ! V_196 ) {
F_118 ( V_6 , V_10 ) ;
V_6 -> V_245 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_129 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_236 , unsigned int V_237 ,
int V_238 )
{
return F_124 ( V_10 , V_6 , V_236 , V_237 , V_238 , 0 ) ;
}
int F_130 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_236 , unsigned int V_237 ,
int V_238 )
{
return F_124 ( V_10 , V_6 , V_236 , V_237 , V_238 , 1 ) ;
}
int F_131 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_201 V_249 , unsigned int V_237 , int V_238 )
{
void * V_89 = V_10 -> V_217 . V_89 ;
int V_240 , V_196 ;
bool V_241 ;
if ( F_125 ( V_6 ) ) {
V_241 = V_238 ;
} else {
V_241 = ! V_238 ;
}
if ( V_237 > sizeof( V_10 -> V_217 . V_89 ) ) {
F_119 ( V_219 L_3 , V_84 ,
V_10 -> V_217 . V_218 ) ;
}
V_10 -> V_217 . V_242 = V_6 -> V_3 . V_243 ;
V_10 -> V_217 . V_218 = V_237 ;
V_10 -> V_217 . V_244 = 1 ;
V_6 -> V_245 = 1 ;
V_6 -> V_246 = 1 ;
if ( ! V_241 ) {
switch ( V_237 ) {
case 8 : * ( V_201 * ) V_89 = V_249 ; break;
case 4 : * ( T_2 * ) V_89 = V_249 ; break;
case 2 : * ( V_221 * ) V_89 = V_249 ; break;
case 1 : * ( V_222 * ) V_89 = V_249 ; break;
}
} else {
switch ( V_237 ) {
case 8 : * ( V_201 * ) V_89 = F_18 ( V_249 ) ; break;
case 4 : * ( T_2 * ) V_89 = F_19 ( V_249 ) ; break;
case 2 : * ( V_221 * ) V_89 = F_120 ( V_249 ) ; break;
case 1 : * ( V_222 * ) V_89 = V_249 ; break;
}
}
V_240 = F_126 ( & V_6 -> V_67 -> V_247 ) ;
V_196 = F_132 ( V_6 , V_248 , V_10 -> V_217 . V_242 ,
V_237 , & V_10 -> V_217 . V_89 ) ;
F_128 ( & V_6 -> V_67 -> V_247 , V_240 ) ;
if ( ! V_196 ) {
V_6 -> V_245 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_133 ( struct V_1 * V_6 , struct V_250 * V_251 )
{
int V_7 = 0 ;
union V_252 V_249 ;
int V_87 ;
V_87 = F_134 ( V_251 -> V_184 ) ;
if ( V_87 > sizeof( V_249 ) )
return - V_70 ;
V_7 = F_135 ( V_6 , V_251 -> V_184 , & V_249 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_251 -> V_184 ) {
#ifdef F_136
case V_253 ... V_254 :
if ( ! F_35 ( V_255 ) ) {
V_7 = - V_256 ;
break;
}
V_249 . V_257 = V_6 -> V_3 . V_258 . V_258 [ V_251 -> V_184 - V_253 ] ;
break;
case V_259 :
if ( ! F_35 ( V_255 ) ) {
V_7 = - V_256 ;
break;
}
V_249 = F_137 ( V_251 -> V_184 , V_6 -> V_3 . V_258 . V_260 . V_261 [ 3 ] ) ;
break;
case V_262 :
V_249 = F_137 ( V_251 -> V_184 , V_6 -> V_3 . V_205 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
if ( V_7 )
return V_7 ;
if ( F_138 ( ( char V_263 * ) ( unsigned long ) V_251 -> V_264 , & V_249 , V_87 ) )
V_7 = - V_265 ;
return V_7 ;
}
int F_139 ( struct V_1 * V_6 , struct V_250 * V_251 )
{
int V_7 ;
union V_252 V_249 ;
int V_87 ;
V_87 = F_134 ( V_251 -> V_184 ) ;
if ( V_87 > sizeof( V_249 ) )
return - V_70 ;
if ( F_140 ( & V_249 , ( char V_263 * ) ( unsigned long ) V_251 -> V_264 , V_87 ) )
return - V_265 ;
V_7 = F_141 ( V_6 , V_251 -> V_184 , & V_249 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_251 -> V_184 ) {
#ifdef F_136
case V_253 ... V_254 :
if ( ! F_35 ( V_255 ) ) {
V_7 = - V_256 ;
break;
}
V_6 -> V_3 . V_258 . V_258 [ V_251 -> V_184 - V_253 ] = V_249 . V_257 ;
break;
case V_259 :
if ( ! F_35 ( V_255 ) ) {
V_7 = - V_256 ;
break;
}
V_6 -> V_3 . V_258 . V_260 . V_261 [ 3 ] = F_142 ( V_251 -> V_184 , V_249 ) ;
break;
case V_262 :
if ( ! F_35 ( V_255 ) ) {
V_7 = - V_256 ;
break;
}
V_6 -> V_3 . V_205 = F_142 ( V_251 -> V_184 , V_249 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
return V_7 ;
}
int F_143 ( struct V_1 * V_6 , struct V_71 * V_10 )
{
int V_7 ;
T_3 V_266 ;
if ( V_6 -> V_267 )
F_144 ( V_268 , & V_6 -> V_269 , & V_266 ) ;
if ( V_6 -> V_245 ) {
if ( ! V_6 -> V_246 )
F_118 ( V_6 , V_10 ) ;
V_6 -> V_245 = 0 ;
} else if ( V_6 -> V_3 . V_270 ) {
V_201 * V_271 = V_10 -> V_272 . V_271 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_271 [ V_18 ] ) ;
V_6 -> V_3 . V_270 = 0 ;
} else if ( V_6 -> V_3 . V_273 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_274 . V_196 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_274 . args [ V_18 ] ) ;
V_6 -> V_3 . V_273 = 0 ;
#ifdef F_67
} else if ( V_6 -> V_3 . V_275 ) {
F_145 ( V_6 , V_10 -> V_276 . V_276 ) ;
V_6 -> V_3 . V_275 = 0 ;
#endif
}
V_7 = F_146 ( V_10 , V_6 ) ;
if ( V_6 -> V_267 )
F_144 ( V_268 , & V_266 , NULL ) ;
return V_7 ;
}
int F_147 ( struct V_1 * V_6 , struct V_277 * V_278 )
{
if ( V_278 -> V_278 == V_279 ) {
F_148 ( V_6 ) ;
return 0 ;
}
F_149 ( V_6 , V_278 ) ;
F_150 ( V_6 ) ;
return 0 ;
}
static int F_151 ( struct V_1 * V_6 ,
struct V_280 * V_281 )
{
int V_7 ;
if ( V_281 -> V_282 )
return - V_70 ;
switch ( V_281 -> V_281 ) {
case V_139 :
V_7 = 0 ;
V_6 -> V_3 . V_283 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_281 -> args [ 0 ] )
V_6 -> V_3 . V_284 |= V_285 ;
else
V_6 -> V_3 . V_284 &= ~ V_285 ;
break;
#ifdef F_67
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_286 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_142 : {
struct V_287 V_288 ;
void V_263 * V_289 = ( void V_263 * ) ( V_290 ) V_281 -> args [ 0 ] ;
V_7 = - V_265 ;
if ( F_140 ( & V_288 , V_289 , sizeof( V_288 ) ) )
break;
V_7 = F_152 ( V_6 , & V_288 ) ;
break;
}
#endif
#ifdef F_69
case V_145 : {
struct V_291 V_292 ;
struct V_293 * V_294 ;
V_7 = - V_295 ;
V_292 = F_153 ( V_281 -> args [ 0 ] ) ;
if ( ! V_292 . V_169 )
break;
V_7 = - V_101 ;
V_294 = F_154 ( V_292 . V_169 ) ;
if ( V_294 )
V_7 = F_155 ( V_294 , V_6 , V_281 -> args [ 1 ] ) ;
F_156 ( V_292 ) ;
break;
}
#endif
#ifdef F_56
case V_152 : {
struct V_291 V_292 ;
struct V_293 * V_294 ;
V_7 = - V_295 ;
V_292 = F_153 ( V_281 -> args [ 0 ] ) ;
if ( ! V_292 . V_169 )
break;
V_7 = - V_101 ;
V_294 = F_154 ( V_292 . V_169 ) ;
if ( V_294 )
V_7 = F_157 ( V_294 , V_6 , V_281 -> args [ 1 ] ) ;
F_156 ( V_292 ) ;
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
bool F_158 ( struct V_67 * V_67 )
{
#ifdef F_69
if ( V_67 -> V_3 . V_190 )
return true ;
#endif
#ifdef F_56
if ( V_67 -> V_3 . V_296 )
return true ;
#endif
return false ;
}
int F_159 ( struct V_1 * V_6 ,
struct V_297 * V_298 )
{
return - V_70 ;
}
int F_160 ( struct V_1 * V_6 ,
struct V_297 * V_298 )
{
return - V_70 ;
}
long F_161 ( struct V_169 * V_170 ,
unsigned int V_171 , unsigned long V_172 )
{
struct V_1 * V_6 = V_170 -> V_299 ;
void V_263 * V_300 = ( void V_263 * ) V_172 ;
long V_7 ;
switch ( V_171 ) {
case V_301 : {
struct V_277 V_278 ;
V_7 = - V_265 ;
if ( F_140 ( & V_278 , V_300 , sizeof( V_278 ) ) )
goto V_63;
V_7 = F_147 ( V_6 , & V_278 ) ;
goto V_63;
}
case V_302 :
{
struct V_280 V_281 ;
V_7 = - V_265 ;
if ( F_140 ( & V_281 , V_300 , sizeof( V_281 ) ) )
goto V_63;
V_7 = F_151 ( V_6 , & V_281 ) ;
break;
}
case V_303 :
case V_304 :
{
struct V_250 V_251 ;
V_7 = - V_265 ;
if ( F_140 ( & V_251 , V_300 , sizeof( V_251 ) ) )
goto V_63;
if ( V_171 == V_303 )
V_7 = F_139 ( V_6 , & V_251 ) ;
else
V_7 = F_133 ( V_6 , & V_251 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_305 : {
struct V_306 V_307 ;
V_7 = - V_265 ;
if ( F_140 ( & V_307 , V_300 , sizeof( V_307 ) ) )
goto V_63;
V_7 = F_162 ( V_6 , & V_307 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_163 ( struct V_1 * V_6 , struct V_308 * V_309 )
{
return V_310 ;
}
static int F_164 ( struct V_311 * V_312 )
{
T_2 V_313 = 0x60000000 ;
#ifdef F_34
T_2 V_314 = 0x44000022 ;
V_312 -> V_315 [ 0 ] = F_165 ( V_314 ) ;
V_312 -> V_315 [ 1 ] = F_165 ( V_313 ) ;
V_312 -> V_315 [ 2 ] = F_165 ( V_313 ) ;
V_312 -> V_315 [ 3 ] = F_165 ( V_313 ) ;
#else
T_2 V_316 = 0x3c000000 ;
T_2 V_317 = 0x60000000 ;
T_2 V_318 = 0x44000002 ;
T_2 V_319 = 0xffff ;
V_312 -> V_315 [ 0 ] = F_165 ( V_316 | ( ( V_320 >> 16 ) & V_319 ) ) ;
V_312 -> V_315 [ 1 ] = F_165 ( V_317 | ( V_320 & V_319 ) ) ;
V_312 -> V_315 [ 2 ] = F_165 ( V_318 ) ;
V_312 -> V_315 [ 3 ] = F_165 ( V_313 ) ;
#endif
V_312 -> V_282 = V_321 ;
return 0 ;
}
int F_166 ( struct V_67 * V_67 , struct V_322 * V_323 ,
bool V_324 )
{
if ( ! F_167 ( V_67 ) )
return - V_256 ;
V_323 -> V_325 = F_168 ( V_67 , V_326 ,
V_323 -> V_278 , V_323 -> V_327 ,
V_324 ) ;
return 0 ;
}
static int F_169 ( struct V_67 * V_67 ,
struct V_280 * V_281 )
{
int V_7 ;
if ( V_281 -> V_282 )
return - V_70 ;
switch ( V_281 -> V_281 ) {
#ifdef F_170
case V_151 : {
unsigned long V_315 = V_281 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_315 > V_328 || ( V_315 & 3 ) ||
V_281 -> args [ 1 ] > 1 )
break;
if ( ! F_171 ( V_67 , V_315 ) )
break;
if ( V_281 -> args [ 1 ] )
F_172 ( V_315 / 4 , V_67 -> V_3 . V_329 ) ;
else
F_30 ( V_315 / 4 , V_67 -> V_3 . V_329 ) ;
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
long F_173 ( struct V_169 * V_170 ,
unsigned int V_171 , unsigned long V_172 )
{
struct V_67 * V_67 T_1 = V_170 -> V_299 ;
void V_263 * V_300 = ( void V_263 * ) V_172 ;
long V_7 ;
switch ( V_171 ) {
case V_330 : {
struct V_311 V_312 ;
memset ( & V_312 , 0 , sizeof( V_312 ) ) ;
V_7 = F_164 ( & V_312 ) ;
if ( F_138 ( V_300 , & V_312 , sizeof( V_312 ) ) ) {
V_7 = - V_265 ;
goto V_63;
}
break;
}
case V_302 :
{
struct V_280 V_281 ;
V_7 = - V_265 ;
if ( F_140 ( & V_281 , V_300 , sizeof( V_281 ) ) )
goto V_63;
V_7 = F_169 ( V_67 , & V_281 ) ;
break;
}
#ifdef V_38
case V_331 : {
struct V_332 V_333 ;
V_7 = - V_265 ;
if ( F_140 ( & V_333 , V_300 , sizeof( V_333 ) ) )
goto V_63;
if ( V_333 . V_282 ) {
V_7 = - V_70 ;
goto V_63;
}
V_7 = F_174 ( V_67 , & V_333 ) ;
goto V_63;
}
case V_334 : {
struct V_335 V_336 ;
struct V_332 V_333 ;
V_7 = - V_265 ;
if ( F_140 ( & V_336 , V_300 , sizeof( V_336 ) ) )
goto V_63;
V_333 . V_337 = V_336 . V_337 ;
V_333 . V_338 = V_339 ;
V_333 . V_340 = 0 ;
V_333 . V_87 = V_336 . V_341 >>
V_339 ;
V_333 . V_282 = 0 ;
V_7 = F_174 ( V_67 , & V_333 ) ;
goto V_63;
}
case V_342 : {
struct V_343 V_344 ;
struct V_67 * V_67 = V_170 -> V_299 ;
memset ( & V_344 , 0 , sizeof( V_344 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_345 ( V_67 , & V_344 ) ;
if ( V_7 >= 0 && F_138 ( V_300 , & V_344 , sizeof( V_344 ) ) )
V_7 = - V_265 ;
break;
}
case V_346 : {
struct V_67 * V_67 = V_170 -> V_299 ;
V_7 = F_175 ( V_67 , V_300 ) ;
break;
}
default: {
struct V_67 * V_67 = V_170 -> V_299 ;
V_7 = V_67 -> V_3 . V_112 -> V_347 ( V_170 , V_171 , V_172 ) ;
}
#else
default:
V_7 = - V_348 ;
#endif
}
V_63:
return V_7 ;
}
long F_176 ( void )
{
long V_349 ;
do {
V_349 = F_177 ( V_350 , V_351 ) ;
if ( V_349 >= V_352 ) {
F_178 ( L_4 , V_84 ) ;
return - V_353 ;
}
} while ( F_179 ( V_349 , V_350 ) );
return V_349 ;
}
void F_180 ( long V_349 )
{
F_172 ( V_349 , V_350 ) ;
}
void F_181 ( long V_349 )
{
F_30 ( V_349 , V_350 ) ;
}
void F_182 ( unsigned long V_354 )
{
V_352 = F_183 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_350 , 0 , sizeof( V_350 ) ) ;
}
int F_184 ( void * V_355 )
{
return 0 ;
}
