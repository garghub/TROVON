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
void F_53 ( struct V_67 * V_67 )
{
unsigned int V_18 ;
struct V_1 * V_6 ;
F_54 (i, vcpu, kvm)
F_55 ( V_6 ) ;
F_56 ( & V_67 -> V_120 ) ;
for ( V_18 = 0 ; V_18 < F_57 ( & V_67 -> V_121 ) ; V_18 ++ )
V_67 -> V_122 [ V_18 ] = NULL ;
F_58 ( & V_67 -> V_121 , 0 ) ;
F_59 ( V_67 ) ;
F_60 ( & V_67 -> V_120 ) ;
F_61 ( V_67 -> V_3 . V_112 -> V_118 ) ;
}
int F_62 ( struct V_67 * V_67 , long V_123 )
{
int V_7 ;
int V_124 = V_113 ? 1 : 0 ;
if ( V_67 ) {
V_124 = F_33 ( V_67 ) ;
}
switch ( V_123 ) {
#ifdef F_63
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
#ifdef F_64
case V_143 :
V_7 = V_144 ;
break;
#endif
#ifdef F_65
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
#ifdef F_66
case V_151 :
#endif
V_7 = 1 ;
break;
#endif
#ifdef F_67
case V_152 :
if ( V_124 )
V_7 = V_153 ;
else
V_7 = 0 ;
break;
case V_154 :
V_7 = 0 ;
break;
#endif
case V_155 :
#ifdef F_67
V_7 = V_124 ;
#elif F_25 ( V_156 )
V_7 = 1 ;
#else
V_7 = 0 ;
#endif
break;
#ifdef F_67
case V_157 :
V_7 = V_124 ;
break;
#endif
case V_158 :
if ( V_124 )
V_7 = F_68 () ;
else
V_7 = F_69 () ;
break;
case V_159 :
V_7 = V_160 ;
break;
#ifdef V_38
case V_161 :
V_7 = 1 ;
break;
#endif
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_70 ( struct V_162 * V_163 ,
unsigned int V_164 , unsigned long V_165 )
{
return - V_70 ;
}
void F_71 ( struct V_67 * V_67 , struct V_166 * free ,
struct V_166 * V_167 )
{
F_72 ( V_67 , free , V_167 ) ;
}
int F_73 ( struct V_67 * V_67 , struct V_166 * V_168 ,
unsigned long V_169 )
{
return F_74 ( V_67 , V_168 , V_169 ) ;
}
int F_75 ( struct V_67 * V_67 ,
struct V_166 * V_170 ,
struct V_171 * V_172 ,
enum V_173 V_174 )
{
return F_76 ( V_67 , V_170 , V_172 ) ;
}
void F_77 ( struct V_67 * V_67 ,
struct V_171 * V_172 ,
const struct V_166 * V_175 ,
enum V_173 V_174 )
{
F_78 ( V_67 , V_172 , V_175 ) ;
}
void F_79 ( struct V_67 * V_67 ,
struct V_166 * V_168 )
{
F_80 ( V_67 , V_168 ) ;
}
struct V_1 * F_81 ( struct V_67 * V_67 , unsigned int V_176 )
{
struct V_1 * V_6 ;
V_6 = F_82 ( V_67 , V_176 ) ;
if ( ! F_83 ( V_6 ) ) {
V_6 -> V_3 . V_177 = & V_6 -> V_178 ;
F_84 ( V_6 , V_176 ) ;
}
return V_6 ;
}
void F_85 ( struct V_1 * V_6 )
{
}
void F_55 ( struct V_1 * V_6 )
{
F_86 ( & V_6 -> V_3 . V_179 ) ;
F_87 ( V_6 ) ;
switch ( V_6 -> V_3 . V_180 ) {
case V_181 :
F_88 ( V_6 -> V_3 . V_182 , V_6 ) ;
break;
case V_183 :
F_89 ( V_6 ) ;
break;
}
F_90 ( V_6 ) ;
}
void F_91 ( struct V_1 * V_6 )
{
F_55 ( V_6 ) ;
}
int F_92 ( struct V_1 * V_6 )
{
return F_93 ( V_6 ) ;
}
enum V_184 F_94 ( struct V_185 * V_186 )
{
struct V_1 * V_6 ;
V_6 = F_95 ( V_186 , struct V_1 , V_3 . V_179 ) ;
F_96 ( V_6 ) ;
return V_187 ;
}
int F_97 ( struct V_1 * V_6 )
{
int V_188 ;
F_98 ( & V_6 -> V_3 . V_179 , V_189 , V_190 ) ;
V_6 -> V_3 . V_179 . V_191 = F_94 ;
V_6 -> V_3 . V_192 = ~ ( V_193 ) 0 ;
#ifdef F_99
F_100 ( & V_6 -> V_3 . V_194 ) ;
#endif
V_188 = F_101 ( V_6 ) ;
return V_188 ;
}
void F_102 ( struct V_1 * V_6 )
{
F_103 ( V_6 ) ;
F_104 ( V_6 ) ;
}
void F_105 ( struct V_1 * V_6 , int V_195 )
{
#ifdef F_63
F_106 ( V_196 , V_6 -> V_3 . V_197 ) ;
#endif
F_107 ( V_6 , V_195 ) ;
}
void F_108 ( struct V_1 * V_6 )
{
F_109 ( V_6 ) ;
#ifdef F_63
V_6 -> V_3 . V_197 = F_110 ( V_196 ) ;
#endif
}
static void F_111 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_193 V_198 ( V_199 ) ;
if ( V_10 -> V_200 . V_201 > sizeof( V_199 ) ) {
F_112 ( V_202 L_2 , V_10 -> V_200 . V_201 ) ;
return;
}
if ( V_6 -> V_3 . V_203 ) {
switch ( V_10 -> V_200 . V_201 ) {
case 8 : V_199 = * ( V_193 * ) V_10 -> V_200 . V_89 ; break;
case 4 : V_199 = * ( T_2 * ) V_10 -> V_200 . V_89 ; break;
case 2 : V_199 = * ( V_204 * ) V_10 -> V_200 . V_89 ; break;
case 1 : V_199 = * ( V_205 * ) V_10 -> V_200 . V_89 ; break;
}
} else {
switch ( V_10 -> V_200 . V_201 ) {
case 4 : V_199 = F_113 ( ( T_2 * ) V_10 -> V_200 . V_89 ) ; break;
case 2 : V_199 = F_114 ( ( V_204 * ) V_10 -> V_200 . V_89 ) ; break;
case 1 : V_199 = * ( V_205 * ) V_10 -> V_200 . V_89 ; break;
}
}
if ( V_6 -> V_3 . V_206 ) {
switch ( V_10 -> V_200 . V_201 ) {
#ifdef F_115
case 4 :
V_199 = ( V_207 ) ( V_208 ) V_199 ;
break;
#endif
case 2 :
V_199 = ( V_207 ) ( V_209 ) V_199 ;
break;
case 1 :
V_199 = ( V_207 ) ( V_210 ) V_199 ;
break;
}
}
F_31 ( V_6 , V_6 -> V_3 . V_211 , V_199 ) ;
switch ( V_6 -> V_3 . V_211 & V_212 ) {
case V_213 :
F_31 ( V_6 , V_6 -> V_3 . V_211 , V_199 ) ;
break;
case V_214 :
F_116 ( V_6 , V_6 -> V_3 . V_211 & V_215 ) = V_199 ;
break;
#ifdef V_56
case V_216 :
V_6 -> V_3 . V_217 [ V_6 -> V_3 . V_211 & V_215 ] = V_199 ;
break;
case V_218 :
F_116 ( V_6 , V_6 -> V_3 . V_211 & V_215 ) = V_199 ;
V_6 -> V_3 . V_217 [ V_6 -> V_3 . V_211 & V_215 ] = V_199 ;
break;
#endif
default:
F_117 () ;
}
}
int F_118 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_219 , unsigned int V_220 ,
int V_221 )
{
int V_222 , V_188 ;
int V_223 ;
if ( F_119 ( V_6 ) ) {
V_223 = ! V_221 ;
} else {
V_223 = V_221 ;
}
if ( V_220 > sizeof( V_10 -> V_200 . V_89 ) ) {
F_112 ( V_202 L_3 , V_84 ,
V_10 -> V_200 . V_201 ) ;
}
V_10 -> V_200 . V_224 = V_6 -> V_3 . V_225 ;
V_10 -> V_200 . V_201 = V_220 ;
V_10 -> V_200 . V_226 = 0 ;
V_6 -> V_3 . V_211 = V_219 ;
V_6 -> V_3 . V_203 = V_223 ;
V_6 -> V_227 = 1 ;
V_6 -> V_228 = 0 ;
V_6 -> V_3 . V_206 = 0 ;
V_222 = F_120 ( & V_6 -> V_67 -> V_229 ) ;
V_188 = F_121 ( V_6 -> V_67 , V_230 , V_10 -> V_200 . V_224 ,
V_220 , & V_10 -> V_200 . V_89 ) ;
F_122 ( & V_6 -> V_67 -> V_229 , V_222 ) ;
if ( ! V_188 ) {
F_111 ( V_6 , V_10 ) ;
V_6 -> V_227 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_123 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_219 , unsigned int V_220 ,
int V_221 )
{
int V_7 ;
V_6 -> V_3 . V_206 = 1 ;
V_7 = F_118 ( V_10 , V_6 , V_219 , V_220 , V_221 ) ;
return V_7 ;
}
int F_124 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_193 V_231 , unsigned int V_220 , int V_221 )
{
void * V_89 = V_10 -> V_200 . V_89 ;
int V_222 , V_188 ;
int V_223 ;
if ( F_119 ( V_6 ) ) {
V_223 = ! V_221 ;
} else {
V_223 = V_221 ;
}
if ( V_220 > sizeof( V_10 -> V_200 . V_89 ) ) {
F_112 ( V_202 L_3 , V_84 ,
V_10 -> V_200 . V_201 ) ;
}
V_10 -> V_200 . V_224 = V_6 -> V_3 . V_225 ;
V_10 -> V_200 . V_201 = V_220 ;
V_10 -> V_200 . V_226 = 1 ;
V_6 -> V_227 = 1 ;
V_6 -> V_228 = 1 ;
if ( V_223 ) {
switch ( V_220 ) {
case 8 : * ( V_193 * ) V_89 = V_231 ; break;
case 4 : * ( T_2 * ) V_89 = V_231 ; break;
case 2 : * ( V_204 * ) V_89 = V_231 ; break;
case 1 : * ( V_205 * ) V_89 = V_231 ; break;
}
} else {
switch ( V_220 ) {
case 4 : F_125 ( V_89 , V_231 ) ; break;
case 2 : F_126 ( V_89 , V_231 ) ; break;
case 1 : * ( V_205 * ) V_89 = V_231 ; break;
}
}
V_222 = F_120 ( & V_6 -> V_67 -> V_229 ) ;
V_188 = F_127 ( V_6 -> V_67 , V_230 , V_10 -> V_200 . V_224 ,
V_220 , & V_10 -> V_200 . V_89 ) ;
F_122 ( & V_6 -> V_67 -> V_229 , V_222 ) ;
if ( ! V_188 ) {
V_6 -> V_227 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_128 ( struct V_1 * V_6 , struct V_232 * V_233 )
{
int V_7 = 0 ;
union V_234 V_231 ;
int V_87 ;
V_87 = F_129 ( V_233 -> V_176 ) ;
if ( V_87 > sizeof( V_231 ) )
return - V_70 ;
V_7 = F_130 ( V_6 , V_233 -> V_176 , & V_231 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_233 -> V_176 ) {
#ifdef F_131
case V_235 ... V_236 :
if ( ! F_35 ( V_237 ) ) {
V_7 = - V_238 ;
break;
}
V_6 -> V_3 . V_239 . V_239 [ V_233 -> V_176 - V_235 ] = V_231 . V_240 ;
break;
case V_241 :
if ( ! F_35 ( V_237 ) ) {
V_7 = - V_238 ;
break;
}
V_6 -> V_3 . V_239 . V_242 . V_243 [ 3 ] = F_132 ( V_233 -> V_176 , V_231 ) ;
break;
case V_244 :
if ( ! F_35 ( V_237 ) ) {
V_7 = - V_238 ;
break;
}
V_6 -> V_3 . V_197 = F_132 ( V_233 -> V_176 , V_231 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
if ( V_7 )
return V_7 ;
if ( F_133 ( ( char V_245 * ) ( unsigned long ) V_233 -> V_246 , & V_231 , V_87 ) )
V_7 = - V_247 ;
return V_7 ;
}
int F_134 ( struct V_1 * V_6 , struct V_232 * V_233 )
{
int V_7 ;
union V_234 V_231 ;
int V_87 ;
V_87 = F_129 ( V_233 -> V_176 ) ;
if ( V_87 > sizeof( V_231 ) )
return - V_70 ;
if ( F_135 ( & V_231 , ( char V_245 * ) ( unsigned long ) V_233 -> V_246 , V_87 ) )
return - V_247 ;
V_7 = F_136 ( V_6 , V_233 -> V_176 , & V_231 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_233 -> V_176 ) {
#ifdef F_131
case V_235 ... V_236 :
if ( ! F_35 ( V_237 ) ) {
V_7 = - V_238 ;
break;
}
V_231 . V_240 = V_6 -> V_3 . V_239 . V_239 [ V_233 -> V_176 - V_235 ] ;
break;
case V_241 :
if ( ! F_35 ( V_237 ) ) {
V_7 = - V_238 ;
break;
}
V_231 = F_137 ( V_233 -> V_176 , V_6 -> V_3 . V_239 . V_242 . V_243 [ 3 ] ) ;
break;
case V_244 :
V_231 = F_137 ( V_233 -> V_176 , V_6 -> V_3 . V_197 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
return V_7 ;
}
int F_138 ( struct V_1 * V_6 , struct V_71 * V_10 )
{
int V_7 ;
T_3 V_248 ;
if ( V_6 -> V_249 )
F_139 ( V_250 , & V_6 -> V_251 , & V_248 ) ;
if ( V_6 -> V_227 ) {
if ( ! V_6 -> V_228 )
F_111 ( V_6 , V_10 ) ;
V_6 -> V_227 = 0 ;
} else if ( V_6 -> V_3 . V_252 ) {
V_193 * V_253 = V_10 -> V_254 . V_253 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_253 [ V_18 ] ) ;
V_6 -> V_3 . V_252 = 0 ;
} else if ( V_6 -> V_3 . V_255 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_256 . V_188 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_256 . args [ V_18 ] ) ;
V_6 -> V_3 . V_255 = 0 ;
#ifdef F_63
} else if ( V_6 -> V_3 . V_257 ) {
F_140 ( V_6 , V_10 -> V_258 . V_258 ) ;
V_6 -> V_3 . V_257 = 0 ;
#endif
}
V_7 = F_141 ( V_10 , V_6 ) ;
if ( V_6 -> V_249 )
F_139 ( V_250 , & V_248 , NULL ) ;
return V_7 ;
}
int F_142 ( struct V_1 * V_6 , struct V_259 * V_260 )
{
if ( V_260 -> V_260 == V_261 ) {
F_143 ( V_6 ) ;
return 0 ;
}
F_144 ( V_6 , V_260 ) ;
F_145 ( V_6 ) ;
return 0 ;
}
static int F_146 ( struct V_1 * V_6 ,
struct V_262 * V_263 )
{
int V_7 ;
if ( V_263 -> V_264 )
return - V_70 ;
switch ( V_263 -> V_263 ) {
case V_139 :
V_7 = 0 ;
V_6 -> V_3 . V_265 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_263 -> args [ 0 ] )
V_6 -> V_3 . V_266 |= V_267 ;
else
V_6 -> V_3 . V_266 &= ~ V_267 ;
break;
#ifdef F_63
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_268 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_142 : {
struct V_269 V_270 ;
void V_245 * V_271 = ( void V_245 * ) ( V_272 ) V_263 -> args [ 0 ] ;
V_7 = - V_247 ;
if ( F_135 ( & V_270 , V_271 , sizeof( V_270 ) ) )
break;
V_7 = F_147 ( V_6 , & V_270 ) ;
break;
}
#endif
#ifdef F_65
case V_145 : {
struct V_273 V_274 ;
struct V_275 * V_276 ;
V_7 = - V_277 ;
V_274 = F_148 ( V_263 -> args [ 0 ] ) ;
if ( ! V_274 . V_162 )
break;
V_7 = - V_101 ;
V_276 = F_149 ( V_274 . V_162 ) ;
if ( V_276 )
V_7 = F_150 ( V_276 , V_6 , V_263 -> args [ 1 ] ) ;
F_151 ( V_274 ) ;
break;
}
#endif
#ifdef F_66
case V_151 : {
struct V_273 V_274 ;
struct V_275 * V_276 ;
V_7 = - V_277 ;
V_274 = F_148 ( V_263 -> args [ 0 ] ) ;
if ( ! V_274 . V_162 )
break;
V_7 = - V_101 ;
V_276 = F_149 ( V_274 . V_162 ) ;
if ( V_276 )
V_7 = F_152 ( V_276 , V_6 , V_263 -> args [ 1 ] ) ;
F_151 ( V_274 ) ;
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
int F_153 ( struct V_1 * V_6 ,
struct V_278 * V_279 )
{
return - V_70 ;
}
int F_154 ( struct V_1 * V_6 ,
struct V_278 * V_279 )
{
return - V_70 ;
}
long F_155 ( struct V_162 * V_163 ,
unsigned int V_164 , unsigned long V_165 )
{
struct V_1 * V_6 = V_163 -> V_280 ;
void V_245 * V_281 = ( void V_245 * ) V_165 ;
long V_7 ;
switch ( V_164 ) {
case V_282 : {
struct V_259 V_260 ;
V_7 = - V_247 ;
if ( F_135 ( & V_260 , V_281 , sizeof( V_260 ) ) )
goto V_63;
V_7 = F_142 ( V_6 , & V_260 ) ;
goto V_63;
}
case V_283 :
{
struct V_262 V_263 ;
V_7 = - V_247 ;
if ( F_135 ( & V_263 , V_281 , sizeof( V_263 ) ) )
goto V_63;
V_7 = F_146 ( V_6 , & V_263 ) ;
break;
}
case V_284 :
case V_285 :
{
struct V_232 V_233 ;
V_7 = - V_247 ;
if ( F_135 ( & V_233 , V_281 , sizeof( V_233 ) ) )
goto V_63;
if ( V_164 == V_284 )
V_7 = F_134 ( V_6 , & V_233 ) ;
else
V_7 = F_128 ( V_6 , & V_233 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_286 : {
struct V_287 V_288 ;
V_7 = - V_247 ;
if ( F_135 ( & V_288 , V_281 , sizeof( V_288 ) ) )
goto V_63;
V_7 = F_156 ( V_6 , & V_288 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_157 ( struct V_1 * V_6 , struct V_289 * V_290 )
{
return V_291 ;
}
static int F_158 ( struct V_292 * V_293 )
{
T_2 V_294 = 0x60000000 ;
#ifdef F_34
T_2 V_295 = 0x44000022 ;
V_293 -> V_296 [ 0 ] = F_159 ( V_295 ) ;
V_293 -> V_296 [ 1 ] = F_159 ( V_294 ) ;
V_293 -> V_296 [ 2 ] = F_159 ( V_294 ) ;
V_293 -> V_296 [ 3 ] = F_159 ( V_294 ) ;
#else
T_2 V_297 = 0x3c000000 ;
T_2 V_298 = 0x60000000 ;
T_2 V_299 = 0x44000002 ;
T_2 V_300 = 0xffff ;
V_293 -> V_296 [ 0 ] = F_159 ( V_297 | ( ( V_301 >> 16 ) & V_300 ) ) ;
V_293 -> V_296 [ 1 ] = F_159 ( V_298 | ( V_301 & V_300 ) ) ;
V_293 -> V_296 [ 2 ] = F_159 ( V_299 ) ;
V_293 -> V_296 [ 3 ] = F_159 ( V_294 ) ;
#endif
V_293 -> V_264 = V_302 ;
return 0 ;
}
int F_160 ( struct V_67 * V_67 , struct V_303 * V_304 ,
bool V_305 )
{
if ( ! F_161 ( V_67 ) )
return - V_238 ;
V_304 -> V_306 = F_162 ( V_67 , V_307 ,
V_304 -> V_260 , V_304 -> V_308 ,
V_305 ) ;
return 0 ;
}
static int F_163 ( struct V_67 * V_67 ,
struct V_262 * V_263 )
{
int V_7 ;
if ( V_263 -> V_264 )
return - V_70 ;
switch ( V_263 -> V_263 ) {
#ifdef F_164
case V_150 : {
unsigned long V_296 = V_263 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_296 > V_309 || ( V_296 & 3 ) ||
V_263 -> args [ 1 ] > 1 )
break;
if ( ! F_165 ( V_67 , V_296 ) )
break;
if ( V_263 -> args [ 1 ] )
F_166 ( V_296 / 4 , V_67 -> V_3 . V_310 ) ;
else
F_30 ( V_296 / 4 , V_67 -> V_3 . V_310 ) ;
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
long F_167 ( struct V_162 * V_163 ,
unsigned int V_164 , unsigned long V_165 )
{
struct V_67 * V_67 T_1 = V_163 -> V_280 ;
void V_245 * V_281 = ( void V_245 * ) V_165 ;
long V_7 ;
switch ( V_164 ) {
case V_311 : {
struct V_292 V_293 ;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
V_7 = F_158 ( & V_293 ) ;
if ( F_133 ( V_281 , & V_293 , sizeof( V_293 ) ) ) {
V_7 = - V_247 ;
goto V_63;
}
break;
}
case V_283 :
{
struct V_262 V_263 ;
V_7 = - V_247 ;
if ( F_135 ( & V_263 , V_281 , sizeof( V_263 ) ) )
goto V_63;
V_7 = F_163 ( V_67 , & V_263 ) ;
break;
}
#ifdef V_38
case V_312 : {
struct V_313 V_314 ;
V_7 = - V_247 ;
if ( F_135 ( & V_314 , V_281 , sizeof( V_314 ) ) )
goto V_63;
V_7 = F_168 ( V_67 , & V_314 ) ;
goto V_63;
}
case V_315 : {
struct V_316 V_317 ;
struct V_67 * V_67 = V_163 -> V_280 ;
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_318 ( V_67 , & V_317 ) ;
if ( V_7 >= 0 && F_133 ( V_281 , & V_317 , sizeof( V_317 ) ) )
V_7 = - V_247 ;
break;
}
case V_319 : {
struct V_67 * V_67 = V_163 -> V_280 ;
V_7 = F_169 ( V_67 , V_281 ) ;
break;
}
default: {
struct V_67 * V_67 = V_163 -> V_280 ;
V_7 = V_67 -> V_3 . V_112 -> V_320 ( V_163 , V_164 , V_165 ) ;
}
#else
default:
V_7 = - V_321 ;
#endif
}
V_63:
return V_7 ;
}
long F_170 ( void )
{
long V_322 ;
do {
V_322 = F_171 ( V_323 , V_324 ) ;
if ( V_322 >= V_325 ) {
F_172 ( L_4 , V_84 ) ;
return - V_326 ;
}
} while ( F_173 ( V_322 , V_323 ) );
return V_322 ;
}
void F_174 ( long V_322 )
{
F_166 ( V_322 , V_323 ) ;
}
void F_175 ( long V_322 )
{
F_30 ( V_322 , V_323 ) ;
}
void F_176 ( unsigned long V_327 )
{
V_325 = F_177 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_323 , 0 , sizeof( V_323 ) ) ;
}
int F_178 ( void * V_328 )
{
return 0 ;
}
