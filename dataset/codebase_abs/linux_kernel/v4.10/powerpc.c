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
#ifdef F_56
case V_151 :
#endif
V_7 = 1 ;
break;
case V_152 :
V_7 = V_124 ;
break;
#endif
#ifdef F_70
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
V_7 = F_71 () ;
break;
#endif
case V_158 :
#ifdef F_70
V_7 = V_124 ;
#elif F_25 ( V_159 )
V_7 = 1 ;
#else
V_7 = 0 ;
#endif
break;
#ifdef F_70
case V_160 :
V_7 = V_124 ;
break;
#endif
case V_161 :
if ( V_124 )
V_7 = F_72 () ;
else
V_7 = F_73 () ;
break;
case V_162 :
V_7 = V_163 ;
break;
case V_164 :
V_7 = V_165 ;
break;
#ifdef V_38
case V_166 :
V_7 = 1 ;
break;
case V_167 :
V_7 = 1 ;
break;
#endif
case V_168 :
V_7 = F_35 ( V_169 ) &&
F_33 ( V_67 ) ;
break;
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_74 ( struct V_170 * V_171 ,
unsigned int V_172 , unsigned long V_173 )
{
return - V_70 ;
}
void F_75 ( struct V_67 * V_67 , struct V_174 * free ,
struct V_174 * V_175 )
{
F_76 ( V_67 , free , V_175 ) ;
}
int F_77 ( struct V_67 * V_67 , struct V_174 * V_176 ,
unsigned long V_177 )
{
return F_78 ( V_67 , V_176 , V_177 ) ;
}
int F_79 ( struct V_67 * V_67 ,
struct V_174 * V_178 ,
const struct V_179 * V_180 ,
enum V_181 V_182 )
{
return F_80 ( V_67 , V_178 , V_180 ) ;
}
void F_81 ( struct V_67 * V_67 ,
const struct V_179 * V_180 ,
const struct V_174 * V_183 ,
const struct V_174 * V_184 ,
enum V_181 V_182 )
{
F_82 ( V_67 , V_180 , V_183 , V_184 ) ;
}
void F_83 ( struct V_67 * V_67 ,
struct V_174 * V_176 )
{
F_84 ( V_67 , V_176 ) ;
}
struct V_1 * F_85 ( struct V_67 * V_67 , unsigned int V_185 )
{
struct V_1 * V_6 ;
V_6 = F_86 ( V_67 , V_185 ) ;
if ( ! F_87 ( V_6 ) ) {
V_6 -> V_3 . V_186 = & V_6 -> V_187 ;
F_88 ( V_6 , V_185 ) ;
}
return V_6 ;
}
void F_89 ( struct V_1 * V_6 )
{
}
void F_59 ( struct V_1 * V_6 )
{
F_90 ( & V_6 -> V_3 . V_188 ) ;
F_91 ( V_6 ) ;
switch ( V_6 -> V_3 . V_189 ) {
case V_190 :
F_92 ( V_6 -> V_3 . V_191 , V_6 ) ;
break;
case V_192 :
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
static enum V_193 F_98 ( struct V_194 * V_195 )
{
struct V_1 * V_6 ;
V_6 = F_99 ( V_195 , struct V_1 , V_3 . V_188 ) ;
F_100 ( V_6 ) ;
return V_196 ;
}
int F_101 ( struct V_1 * V_6 )
{
int V_197 ;
F_102 ( & V_6 -> V_3 . V_188 , V_198 , V_199 ) ;
V_6 -> V_3 . V_188 . V_200 = F_98 ;
V_6 -> V_3 . V_201 = ~ ( V_202 ) 0 ;
#ifdef F_103
F_104 ( & V_6 -> V_3 . V_203 ) ;
#endif
V_197 = F_105 ( V_6 ) ;
return V_197 ;
}
void F_106 ( struct V_1 * V_6 )
{
F_107 ( V_6 ) ;
F_108 ( V_6 ) ;
}
void F_109 ( struct V_1 * V_6 , int V_204 )
{
#ifdef F_67
F_110 ( V_205 , V_6 -> V_3 . V_206 ) ;
#endif
F_111 ( V_6 , V_204 ) ;
}
void F_112 ( struct V_1 * V_6 )
{
F_113 ( V_6 ) ;
#ifdef F_67
V_6 -> V_3 . V_206 = F_114 ( V_205 ) ;
#endif
}
bool F_115 ( void )
{
return ( ( V_113 && V_113 -> V_207 ) ||
( V_114 && V_114 -> V_207 ) ) ;
}
int F_116 ( struct V_208 * V_209 ,
struct V_210 * V_211 )
{
struct V_212 * V_213 =
F_99 ( V_209 , struct V_212 , V_214 ) ;
struct V_67 * V_67 = V_213 -> V_67 ;
if ( V_67 -> V_3 . V_112 -> V_207 )
return V_67 -> V_3 . V_112 -> V_207 ( V_209 , V_211 ) ;
return 0 ;
}
void F_117 ( struct V_208 * V_209 ,
struct V_210 * V_211 )
{
struct V_212 * V_213 =
F_99 ( V_209 , struct V_212 , V_214 ) ;
struct V_67 * V_67 = V_213 -> V_67 ;
if ( V_67 -> V_3 . V_112 -> V_215 )
V_67 -> V_3 . V_112 -> V_215 ( V_209 , V_211 ) ;
}
static void F_118 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_202 V_216 ( V_217 ) ;
if ( V_10 -> V_218 . V_219 > sizeof( V_217 ) ) {
F_119 ( V_220 L_2 , V_10 -> V_218 . V_219 ) ;
return;
}
if ( ! V_6 -> V_3 . V_221 ) {
switch ( V_10 -> V_218 . V_219 ) {
case 8 : V_217 = * ( V_202 * ) V_10 -> V_218 . V_89 ; break;
case 4 : V_217 = * ( T_2 * ) V_10 -> V_218 . V_89 ; break;
case 2 : V_217 = * ( V_222 * ) V_10 -> V_218 . V_89 ; break;
case 1 : V_217 = * ( V_223 * ) V_10 -> V_218 . V_89 ; break;
}
} else {
switch ( V_10 -> V_218 . V_219 ) {
case 8 : V_217 = F_18 ( * ( V_202 * ) V_10 -> V_218 . V_89 ) ; break;
case 4 : V_217 = F_19 ( * ( T_2 * ) V_10 -> V_218 . V_89 ) ; break;
case 2 : V_217 = F_120 ( * ( V_222 * ) V_10 -> V_218 . V_89 ) ; break;
case 1 : V_217 = * ( V_223 * ) V_10 -> V_218 . V_89 ; break;
}
}
if ( V_6 -> V_3 . V_224 ) {
switch ( V_10 -> V_218 . V_219 ) {
#ifdef F_121
case 4 :
V_217 = ( V_225 ) ( V_226 ) V_217 ;
break;
#endif
case 2 :
V_217 = ( V_225 ) ( V_227 ) V_217 ;
break;
case 1 :
V_217 = ( V_225 ) ( V_228 ) V_217 ;
break;
}
}
F_31 ( V_6 , V_6 -> V_3 . V_229 , V_217 ) ;
switch ( V_6 -> V_3 . V_229 & V_230 ) {
case V_231 :
F_31 ( V_6 , V_6 -> V_3 . V_229 , V_217 ) ;
break;
case V_232 :
F_122 ( V_6 , V_6 -> V_3 . V_229 & V_233 ) = V_217 ;
break;
#ifdef V_56
case V_234 :
V_6 -> V_3 . V_235 [ V_6 -> V_3 . V_229 & V_233 ] = V_217 ;
break;
case V_236 :
F_122 ( V_6 , V_6 -> V_3 . V_229 & V_233 ) = V_217 ;
V_6 -> V_3 . V_235 [ V_6 -> V_3 . V_229 & V_233 ] = V_217 ;
break;
#endif
default:
F_123 () ;
}
}
static int F_124 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_237 , unsigned int V_238 ,
int V_239 , int V_240 )
{
int V_241 , V_197 ;
bool V_242 ;
if ( F_125 ( V_6 ) ) {
V_242 = V_239 ;
} else {
V_242 = ! V_239 ;
}
if ( V_238 > sizeof( V_10 -> V_218 . V_89 ) ) {
F_119 ( V_220 L_3 , V_84 ,
V_10 -> V_218 . V_219 ) ;
}
V_10 -> V_218 . V_243 = V_6 -> V_3 . V_244 ;
V_10 -> V_218 . V_219 = V_238 ;
V_10 -> V_218 . V_245 = 0 ;
V_6 -> V_3 . V_229 = V_237 ;
V_6 -> V_3 . V_221 = V_242 ;
V_6 -> V_246 = 1 ;
V_6 -> V_247 = 0 ;
V_6 -> V_3 . V_224 = V_240 ;
V_241 = F_126 ( & V_6 -> V_67 -> V_248 ) ;
V_197 = F_127 ( V_6 , V_249 , V_10 -> V_218 . V_243 ,
V_238 , & V_10 -> V_218 . V_89 ) ;
F_128 ( & V_6 -> V_67 -> V_248 , V_241 ) ;
if ( ! V_197 ) {
F_118 ( V_6 , V_10 ) ;
V_6 -> V_246 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_129 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_237 , unsigned int V_238 ,
int V_239 )
{
return F_124 ( V_10 , V_6 , V_237 , V_238 , V_239 , 0 ) ;
}
int F_130 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_237 , unsigned int V_238 ,
int V_239 )
{
return F_124 ( V_10 , V_6 , V_237 , V_238 , V_239 , 1 ) ;
}
int F_131 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_202 V_250 , unsigned int V_238 , int V_239 )
{
void * V_89 = V_10 -> V_218 . V_89 ;
int V_241 , V_197 ;
bool V_242 ;
if ( F_125 ( V_6 ) ) {
V_242 = V_239 ;
} else {
V_242 = ! V_239 ;
}
if ( V_238 > sizeof( V_10 -> V_218 . V_89 ) ) {
F_119 ( V_220 L_3 , V_84 ,
V_10 -> V_218 . V_219 ) ;
}
V_10 -> V_218 . V_243 = V_6 -> V_3 . V_244 ;
V_10 -> V_218 . V_219 = V_238 ;
V_10 -> V_218 . V_245 = 1 ;
V_6 -> V_246 = 1 ;
V_6 -> V_247 = 1 ;
if ( ! V_242 ) {
switch ( V_238 ) {
case 8 : * ( V_202 * ) V_89 = V_250 ; break;
case 4 : * ( T_2 * ) V_89 = V_250 ; break;
case 2 : * ( V_222 * ) V_89 = V_250 ; break;
case 1 : * ( V_223 * ) V_89 = V_250 ; break;
}
} else {
switch ( V_238 ) {
case 8 : * ( V_202 * ) V_89 = F_18 ( V_250 ) ; break;
case 4 : * ( T_2 * ) V_89 = F_19 ( V_250 ) ; break;
case 2 : * ( V_222 * ) V_89 = F_120 ( V_250 ) ; break;
case 1 : * ( V_223 * ) V_89 = V_250 ; break;
}
}
V_241 = F_126 ( & V_6 -> V_67 -> V_248 ) ;
V_197 = F_132 ( V_6 , V_249 , V_10 -> V_218 . V_243 ,
V_238 , & V_10 -> V_218 . V_89 ) ;
F_128 ( & V_6 -> V_67 -> V_248 , V_241 ) ;
if ( ! V_197 ) {
V_6 -> V_246 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_133 ( struct V_1 * V_6 , struct V_251 * V_252 )
{
int V_7 = 0 ;
union V_253 V_250 ;
int V_87 ;
V_87 = F_134 ( V_252 -> V_185 ) ;
if ( V_87 > sizeof( V_250 ) )
return - V_70 ;
V_7 = F_135 ( V_6 , V_252 -> V_185 , & V_250 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_252 -> V_185 ) {
#ifdef F_136
case V_254 ... V_255 :
if ( ! F_35 ( V_256 ) ) {
V_7 = - V_257 ;
break;
}
V_250 . V_258 = V_6 -> V_3 . V_259 . V_259 [ V_252 -> V_185 - V_254 ] ;
break;
case V_260 :
if ( ! F_35 ( V_256 ) ) {
V_7 = - V_257 ;
break;
}
V_250 = F_137 ( V_252 -> V_185 , V_6 -> V_3 . V_259 . V_261 . V_262 [ 3 ] ) ;
break;
case V_263 :
V_250 = F_137 ( V_252 -> V_185 , V_6 -> V_3 . V_206 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
if ( V_7 )
return V_7 ;
if ( F_138 ( ( char V_264 * ) ( unsigned long ) V_252 -> V_265 , & V_250 , V_87 ) )
V_7 = - V_266 ;
return V_7 ;
}
int F_139 ( struct V_1 * V_6 , struct V_251 * V_252 )
{
int V_7 ;
union V_253 V_250 ;
int V_87 ;
V_87 = F_134 ( V_252 -> V_185 ) ;
if ( V_87 > sizeof( V_250 ) )
return - V_70 ;
if ( F_140 ( & V_250 , ( char V_264 * ) ( unsigned long ) V_252 -> V_265 , V_87 ) )
return - V_266 ;
V_7 = F_141 ( V_6 , V_252 -> V_185 , & V_250 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_252 -> V_185 ) {
#ifdef F_136
case V_254 ... V_255 :
if ( ! F_35 ( V_256 ) ) {
V_7 = - V_257 ;
break;
}
V_6 -> V_3 . V_259 . V_259 [ V_252 -> V_185 - V_254 ] = V_250 . V_258 ;
break;
case V_260 :
if ( ! F_35 ( V_256 ) ) {
V_7 = - V_257 ;
break;
}
V_6 -> V_3 . V_259 . V_261 . V_262 [ 3 ] = F_142 ( V_252 -> V_185 , V_250 ) ;
break;
case V_263 :
if ( ! F_35 ( V_256 ) ) {
V_7 = - V_257 ;
break;
}
V_6 -> V_3 . V_206 = F_142 ( V_252 -> V_185 , V_250 ) ;
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
T_3 V_267 ;
if ( V_6 -> V_268 )
F_144 ( V_269 , & V_6 -> V_270 , & V_267 ) ;
if ( V_6 -> V_246 ) {
if ( ! V_6 -> V_247 )
F_118 ( V_6 , V_10 ) ;
V_6 -> V_246 = 0 ;
} else if ( V_6 -> V_3 . V_271 ) {
V_202 * V_272 = V_10 -> V_273 . V_272 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_272 [ V_18 ] ) ;
V_6 -> V_3 . V_271 = 0 ;
} else if ( V_6 -> V_3 . V_274 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_275 . V_197 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_275 . args [ V_18 ] ) ;
V_6 -> V_3 . V_274 = 0 ;
#ifdef F_67
} else if ( V_6 -> V_3 . V_276 ) {
F_145 ( V_6 , V_10 -> V_277 . V_277 ) ;
V_6 -> V_3 . V_276 = 0 ;
#endif
}
V_7 = F_146 ( V_10 , V_6 ) ;
if ( V_6 -> V_268 )
F_144 ( V_269 , & V_267 , NULL ) ;
return V_7 ;
}
int F_147 ( struct V_1 * V_6 , struct V_278 * V_279 )
{
if ( V_279 -> V_279 == V_280 ) {
F_148 ( V_6 ) ;
return 0 ;
}
F_149 ( V_6 , V_279 ) ;
F_150 ( V_6 ) ;
return 0 ;
}
static int F_151 ( struct V_1 * V_6 ,
struct V_281 * V_282 )
{
int V_7 ;
if ( V_282 -> V_283 )
return - V_70 ;
switch ( V_282 -> V_282 ) {
case V_139 :
V_7 = 0 ;
V_6 -> V_3 . V_284 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_282 -> args [ 0 ] )
V_6 -> V_3 . V_285 |= V_286 ;
else
V_6 -> V_3 . V_285 &= ~ V_286 ;
break;
#ifdef F_67
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_287 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_142 : {
struct V_288 V_289 ;
void V_264 * V_290 = ( void V_264 * ) ( V_291 ) V_282 -> args [ 0 ] ;
V_7 = - V_266 ;
if ( F_140 ( & V_289 , V_290 , sizeof( V_289 ) ) )
break;
V_7 = F_152 ( V_6 , & V_289 ) ;
break;
}
#endif
#ifdef F_69
case V_145 : {
struct V_292 V_293 ;
struct V_294 * V_295 ;
V_7 = - V_296 ;
V_293 = F_153 ( V_282 -> args [ 0 ] ) ;
if ( ! V_293 . V_170 )
break;
V_7 = - V_101 ;
V_295 = F_154 ( V_293 . V_170 ) ;
if ( V_295 )
V_7 = F_155 ( V_295 , V_6 , V_282 -> args [ 1 ] ) ;
F_156 ( V_293 ) ;
break;
}
#endif
#ifdef F_56
case V_151 : {
struct V_292 V_293 ;
struct V_294 * V_295 ;
V_7 = - V_296 ;
V_293 = F_153 ( V_282 -> args [ 0 ] ) ;
if ( ! V_293 . V_170 )
break;
V_7 = - V_101 ;
V_295 = F_154 ( V_293 . V_170 ) ;
if ( V_295 )
V_7 = F_157 ( V_295 , V_6 , V_282 -> args [ 1 ] ) ;
F_156 ( V_293 ) ;
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
if ( V_67 -> V_3 . V_191 )
return true ;
#endif
#ifdef F_56
if ( V_67 -> V_3 . V_297 )
return true ;
#endif
return false ;
}
int F_159 ( struct V_1 * V_6 ,
struct V_298 * V_299 )
{
return - V_70 ;
}
int F_160 ( struct V_1 * V_6 ,
struct V_298 * V_299 )
{
return - V_70 ;
}
long F_161 ( struct V_170 * V_171 ,
unsigned int V_172 , unsigned long V_173 )
{
struct V_1 * V_6 = V_171 -> V_300 ;
void V_264 * V_301 = ( void V_264 * ) V_173 ;
long V_7 ;
switch ( V_172 ) {
case V_302 : {
struct V_278 V_279 ;
V_7 = - V_266 ;
if ( F_140 ( & V_279 , V_301 , sizeof( V_279 ) ) )
goto V_63;
V_7 = F_147 ( V_6 , & V_279 ) ;
goto V_63;
}
case V_303 :
{
struct V_281 V_282 ;
V_7 = - V_266 ;
if ( F_140 ( & V_282 , V_301 , sizeof( V_282 ) ) )
goto V_63;
V_7 = F_151 ( V_6 , & V_282 ) ;
break;
}
case V_304 :
case V_305 :
{
struct V_251 V_252 ;
V_7 = - V_266 ;
if ( F_140 ( & V_252 , V_301 , sizeof( V_252 ) ) )
goto V_63;
if ( V_172 == V_304 )
V_7 = F_139 ( V_6 , & V_252 ) ;
else
V_7 = F_133 ( V_6 , & V_252 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_306 : {
struct V_307 V_308 ;
V_7 = - V_266 ;
if ( F_140 ( & V_308 , V_301 , sizeof( V_308 ) ) )
goto V_63;
V_7 = F_162 ( V_6 , & V_308 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_163 ( struct V_1 * V_6 , struct V_309 * V_310 )
{
return V_311 ;
}
static int F_164 ( struct V_312 * V_313 )
{
T_2 V_314 = 0x60000000 ;
#ifdef F_34
T_2 V_315 = 0x44000022 ;
V_313 -> V_316 [ 0 ] = F_165 ( V_315 ) ;
V_313 -> V_316 [ 1 ] = F_165 ( V_314 ) ;
V_313 -> V_316 [ 2 ] = F_165 ( V_314 ) ;
V_313 -> V_316 [ 3 ] = F_165 ( V_314 ) ;
#else
T_2 V_317 = 0x3c000000 ;
T_2 V_318 = 0x60000000 ;
T_2 V_319 = 0x44000002 ;
T_2 V_320 = 0xffff ;
V_313 -> V_316 [ 0 ] = F_165 ( V_317 | ( ( V_321 >> 16 ) & V_320 ) ) ;
V_313 -> V_316 [ 1 ] = F_165 ( V_318 | ( V_321 & V_320 ) ) ;
V_313 -> V_316 [ 2 ] = F_165 ( V_319 ) ;
V_313 -> V_316 [ 3 ] = F_165 ( V_314 ) ;
#endif
V_313 -> V_283 = V_322 ;
return 0 ;
}
int F_166 ( struct V_67 * V_67 , struct V_323 * V_324 ,
bool V_325 )
{
if ( ! F_167 ( V_67 ) )
return - V_257 ;
V_324 -> V_326 = F_168 ( V_67 , V_327 ,
V_324 -> V_279 , V_324 -> V_328 ,
V_325 ) ;
return 0 ;
}
static int F_169 ( struct V_67 * V_67 ,
struct V_281 * V_282 )
{
int V_7 ;
if ( V_282 -> V_283 )
return - V_70 ;
switch ( V_282 -> V_282 ) {
#ifdef F_170
case V_150 : {
unsigned long V_316 = V_282 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_316 > V_329 || ( V_316 & 3 ) ||
V_282 -> args [ 1 ] > 1 )
break;
if ( ! F_171 ( V_67 , V_316 ) )
break;
if ( V_282 -> args [ 1 ] )
F_172 ( V_316 / 4 , V_67 -> V_3 . V_330 ) ;
else
F_30 ( V_316 / 4 , V_67 -> V_3 . V_330 ) ;
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
long F_173 ( struct V_170 * V_171 ,
unsigned int V_172 , unsigned long V_173 )
{
struct V_67 * V_67 T_1 = V_171 -> V_300 ;
void V_264 * V_301 = ( void V_264 * ) V_173 ;
long V_7 ;
switch ( V_172 ) {
case V_331 : {
struct V_312 V_313 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_7 = F_164 ( & V_313 ) ;
if ( F_138 ( V_301 , & V_313 , sizeof( V_313 ) ) ) {
V_7 = - V_266 ;
goto V_63;
}
break;
}
case V_303 :
{
struct V_281 V_282 ;
V_7 = - V_266 ;
if ( F_140 ( & V_282 , V_301 , sizeof( V_282 ) ) )
goto V_63;
V_7 = F_169 ( V_67 , & V_282 ) ;
break;
}
#ifdef V_38
case V_332 : {
struct V_333 V_334 ;
V_7 = - V_266 ;
if ( F_140 ( & V_334 , V_301 , sizeof( V_334 ) ) )
goto V_63;
if ( V_334 . V_283 ) {
V_7 = - V_70 ;
goto V_63;
}
V_7 = F_174 ( V_67 , & V_334 ) ;
goto V_63;
}
case V_335 : {
struct V_336 V_337 ;
struct V_333 V_334 ;
V_7 = - V_266 ;
if ( F_140 ( & V_337 , V_301 , sizeof( V_337 ) ) )
goto V_63;
V_334 . V_338 = V_337 . V_338 ;
V_334 . V_339 = V_340 ;
V_334 . V_341 = 0 ;
V_334 . V_87 = V_337 . V_342 >>
V_340 ;
V_334 . V_283 = 0 ;
V_7 = F_174 ( V_67 , & V_334 ) ;
goto V_63;
}
case V_343 : {
struct V_344 V_345 ;
struct V_67 * V_67 = V_171 -> V_300 ;
memset ( & V_345 , 0 , sizeof( V_345 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_346 ( V_67 , & V_345 ) ;
if ( V_7 >= 0 && F_138 ( V_301 , & V_345 , sizeof( V_345 ) ) )
V_7 = - V_266 ;
break;
}
case V_347 : {
struct V_67 * V_67 = V_171 -> V_300 ;
V_7 = F_175 ( V_67 , V_301 ) ;
break;
}
default: {
struct V_67 * V_67 = V_171 -> V_300 ;
V_7 = V_67 -> V_3 . V_112 -> V_348 ( V_171 , V_172 , V_173 ) ;
}
#else
default:
V_7 = - V_349 ;
#endif
}
V_63:
return V_7 ;
}
long F_176 ( void )
{
long V_350 ;
do {
V_350 = F_177 ( V_351 , V_352 ) ;
if ( V_350 >= V_353 ) {
F_178 ( L_4 , V_84 ) ;
return - V_354 ;
}
} while ( F_179 ( V_350 , V_351 ) );
return V_350 ;
}
void F_180 ( long V_350 )
{
F_172 ( V_350 , V_351 ) ;
}
void F_181 ( long V_350 )
{
F_30 ( V_350 , V_351 ) ;
}
void F_182 ( unsigned long V_355 )
{
V_353 = F_183 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_351 , 0 , sizeof( V_351 ) ) ;
}
int F_184 ( void * V_356 )
{
return 0 ;
}
