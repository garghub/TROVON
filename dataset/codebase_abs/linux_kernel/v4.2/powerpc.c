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
case V_155 :
V_7 = F_68 () ;
break;
#endif
case V_156 :
#ifdef F_67
V_7 = V_124 ;
#elif F_25 ( V_157 )
V_7 = 1 ;
#else
V_7 = 0 ;
#endif
break;
#ifdef F_67
case V_158 :
V_7 = V_124 ;
break;
#endif
case V_159 :
if ( V_124 )
V_7 = F_69 () ;
else
V_7 = F_70 () ;
break;
case V_160 :
V_7 = V_161 ;
break;
#ifdef V_38
case V_162 :
V_7 = 1 ;
break;
#endif
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_71 ( struct V_163 * V_164 ,
unsigned int V_165 , unsigned long V_166 )
{
return - V_70 ;
}
void F_72 ( struct V_67 * V_67 , struct V_167 * free ,
struct V_167 * V_168 )
{
F_73 ( V_67 , free , V_168 ) ;
}
int F_74 ( struct V_67 * V_67 , struct V_167 * V_169 ,
unsigned long V_170 )
{
return F_75 ( V_67 , V_169 , V_170 ) ;
}
int F_76 ( struct V_67 * V_67 ,
struct V_167 * V_171 ,
const struct V_172 * V_173 ,
enum V_174 V_175 )
{
return F_77 ( V_67 , V_171 , V_173 ) ;
}
void F_78 ( struct V_67 * V_67 ,
const struct V_172 * V_173 ,
const struct V_167 * V_176 ,
const struct V_167 * V_177 ,
enum V_174 V_175 )
{
F_79 ( V_67 , V_173 , V_176 , V_177 ) ;
}
void F_80 ( struct V_67 * V_67 ,
struct V_167 * V_169 )
{
F_81 ( V_67 , V_169 ) ;
}
struct V_1 * F_82 ( struct V_67 * V_67 , unsigned int V_178 )
{
struct V_1 * V_6 ;
V_6 = F_83 ( V_67 , V_178 ) ;
if ( ! F_84 ( V_6 ) ) {
V_6 -> V_3 . V_179 = & V_6 -> V_180 ;
F_85 ( V_6 , V_178 ) ;
}
return V_6 ;
}
void F_86 ( struct V_1 * V_6 )
{
}
void F_55 ( struct V_1 * V_6 )
{
F_87 ( & V_6 -> V_3 . V_181 ) ;
F_88 ( V_6 ) ;
switch ( V_6 -> V_3 . V_182 ) {
case V_183 :
F_89 ( V_6 -> V_3 . V_184 , V_6 ) ;
break;
case V_185 :
F_90 ( V_6 ) ;
break;
}
F_91 ( V_6 ) ;
}
void F_92 ( struct V_1 * V_6 )
{
F_55 ( V_6 ) ;
}
int F_93 ( struct V_1 * V_6 )
{
return F_94 ( V_6 ) ;
}
enum V_186 F_95 ( struct V_187 * V_188 )
{
struct V_1 * V_6 ;
V_6 = F_96 ( V_188 , struct V_1 , V_3 . V_181 ) ;
F_97 ( V_6 ) ;
return V_189 ;
}
int F_98 ( struct V_1 * V_6 )
{
int V_190 ;
F_99 ( & V_6 -> V_3 . V_181 , V_191 , V_192 ) ;
V_6 -> V_3 . V_181 . V_193 = F_95 ;
V_6 -> V_3 . V_194 = ~ ( V_195 ) 0 ;
#ifdef F_100
F_101 ( & V_6 -> V_3 . V_196 ) ;
#endif
V_190 = F_102 ( V_6 ) ;
return V_190 ;
}
void F_103 ( struct V_1 * V_6 )
{
F_104 ( V_6 ) ;
F_105 ( V_6 ) ;
}
void F_106 ( struct V_1 * V_6 , int V_197 )
{
#ifdef F_63
F_107 ( V_198 , V_6 -> V_3 . V_199 ) ;
#endif
F_108 ( V_6 , V_197 ) ;
}
void F_109 ( struct V_1 * V_6 )
{
F_110 ( V_6 ) ;
#ifdef F_63
V_6 -> V_3 . V_199 = F_111 ( V_198 ) ;
#endif
}
static void F_112 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_195 V_200 ( V_201 ) ;
if ( V_10 -> V_202 . V_203 > sizeof( V_201 ) ) {
F_113 ( V_204 L_2 , V_10 -> V_202 . V_203 ) ;
return;
}
if ( ! V_6 -> V_3 . V_205 ) {
switch ( V_10 -> V_202 . V_203 ) {
case 8 : V_201 = * ( V_195 * ) V_10 -> V_202 . V_89 ; break;
case 4 : V_201 = * ( T_2 * ) V_10 -> V_202 . V_89 ; break;
case 2 : V_201 = * ( V_206 * ) V_10 -> V_202 . V_89 ; break;
case 1 : V_201 = * ( V_207 * ) V_10 -> V_202 . V_89 ; break;
}
} else {
switch ( V_10 -> V_202 . V_203 ) {
case 8 : V_201 = F_18 ( * ( V_195 * ) V_10 -> V_202 . V_89 ) ; break;
case 4 : V_201 = F_19 ( * ( T_2 * ) V_10 -> V_202 . V_89 ) ; break;
case 2 : V_201 = F_114 ( * ( V_206 * ) V_10 -> V_202 . V_89 ) ; break;
case 1 : V_201 = * ( V_207 * ) V_10 -> V_202 . V_89 ; break;
}
}
if ( V_6 -> V_3 . V_208 ) {
switch ( V_10 -> V_202 . V_203 ) {
#ifdef F_115
case 4 :
V_201 = ( V_209 ) ( V_210 ) V_201 ;
break;
#endif
case 2 :
V_201 = ( V_209 ) ( V_211 ) V_201 ;
break;
case 1 :
V_201 = ( V_209 ) ( V_212 ) V_201 ;
break;
}
}
F_31 ( V_6 , V_6 -> V_3 . V_213 , V_201 ) ;
switch ( V_6 -> V_3 . V_213 & V_214 ) {
case V_215 :
F_31 ( V_6 , V_6 -> V_3 . V_213 , V_201 ) ;
break;
case V_216 :
F_116 ( V_6 , V_6 -> V_3 . V_213 & V_217 ) = V_201 ;
break;
#ifdef V_56
case V_218 :
V_6 -> V_3 . V_219 [ V_6 -> V_3 . V_213 & V_217 ] = V_201 ;
break;
case V_220 :
F_116 ( V_6 , V_6 -> V_3 . V_213 & V_217 ) = V_201 ;
V_6 -> V_3 . V_219 [ V_6 -> V_3 . V_213 & V_217 ] = V_201 ;
break;
#endif
default:
F_117 () ;
}
}
int F_118 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_221 , unsigned int V_222 ,
int V_223 )
{
int V_224 , V_190 ;
bool V_225 ;
if ( F_119 ( V_6 ) ) {
V_225 = V_223 ;
} else {
V_225 = ! V_223 ;
}
if ( V_222 > sizeof( V_10 -> V_202 . V_89 ) ) {
F_113 ( V_204 L_3 , V_84 ,
V_10 -> V_202 . V_203 ) ;
}
V_10 -> V_202 . V_226 = V_6 -> V_3 . V_227 ;
V_10 -> V_202 . V_203 = V_222 ;
V_10 -> V_202 . V_228 = 0 ;
V_6 -> V_3 . V_213 = V_221 ;
V_6 -> V_3 . V_205 = V_225 ;
V_6 -> V_229 = 1 ;
V_6 -> V_230 = 0 ;
V_6 -> V_3 . V_208 = 0 ;
V_224 = F_120 ( & V_6 -> V_67 -> V_231 ) ;
V_190 = F_121 ( V_6 , V_232 , V_10 -> V_202 . V_226 ,
V_222 , & V_10 -> V_202 . V_89 ) ;
F_122 ( & V_6 -> V_67 -> V_231 , V_224 ) ;
if ( ! V_190 ) {
F_112 ( V_6 , V_10 ) ;
V_6 -> V_229 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_123 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_221 , unsigned int V_222 ,
int V_223 )
{
int V_7 ;
V_6 -> V_3 . V_208 = 1 ;
V_7 = F_118 ( V_10 , V_6 , V_221 , V_222 , V_223 ) ;
return V_7 ;
}
int F_124 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_195 V_233 , unsigned int V_222 , int V_223 )
{
void * V_89 = V_10 -> V_202 . V_89 ;
int V_224 , V_190 ;
bool V_225 ;
if ( F_119 ( V_6 ) ) {
V_225 = V_223 ;
} else {
V_225 = ! V_223 ;
}
if ( V_222 > sizeof( V_10 -> V_202 . V_89 ) ) {
F_113 ( V_204 L_3 , V_84 ,
V_10 -> V_202 . V_203 ) ;
}
V_10 -> V_202 . V_226 = V_6 -> V_3 . V_227 ;
V_10 -> V_202 . V_203 = V_222 ;
V_10 -> V_202 . V_228 = 1 ;
V_6 -> V_229 = 1 ;
V_6 -> V_230 = 1 ;
if ( ! V_225 ) {
switch ( V_222 ) {
case 8 : * ( V_195 * ) V_89 = V_233 ; break;
case 4 : * ( T_2 * ) V_89 = V_233 ; break;
case 2 : * ( V_206 * ) V_89 = V_233 ; break;
case 1 : * ( V_207 * ) V_89 = V_233 ; break;
}
} else {
switch ( V_222 ) {
case 8 : * ( V_195 * ) V_89 = F_18 ( V_233 ) ; break;
case 4 : * ( T_2 * ) V_89 = F_19 ( V_233 ) ; break;
case 2 : * ( V_206 * ) V_89 = F_114 ( V_233 ) ; break;
case 1 : * ( V_207 * ) V_89 = V_233 ; break;
}
}
V_224 = F_120 ( & V_6 -> V_67 -> V_231 ) ;
V_190 = F_125 ( V_6 , V_232 , V_10 -> V_202 . V_226 ,
V_222 , & V_10 -> V_202 . V_89 ) ;
F_122 ( & V_6 -> V_67 -> V_231 , V_224 ) ;
if ( ! V_190 ) {
V_6 -> V_229 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_126 ( struct V_1 * V_6 , struct V_234 * V_235 )
{
int V_7 = 0 ;
union V_236 V_233 ;
int V_87 ;
V_87 = F_127 ( V_235 -> V_178 ) ;
if ( V_87 > sizeof( V_233 ) )
return - V_70 ;
V_7 = F_128 ( V_6 , V_235 -> V_178 , & V_233 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_235 -> V_178 ) {
#ifdef F_129
case V_237 ... V_238 :
if ( ! F_35 ( V_239 ) ) {
V_7 = - V_240 ;
break;
}
V_6 -> V_3 . V_241 . V_241 [ V_235 -> V_178 - V_237 ] = V_233 . V_242 ;
break;
case V_243 :
if ( ! F_35 ( V_239 ) ) {
V_7 = - V_240 ;
break;
}
V_6 -> V_3 . V_241 . V_244 . V_245 [ 3 ] = F_130 ( V_235 -> V_178 , V_233 ) ;
break;
case V_246 :
if ( ! F_35 ( V_239 ) ) {
V_7 = - V_240 ;
break;
}
V_6 -> V_3 . V_199 = F_130 ( V_235 -> V_178 , V_233 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
if ( V_7 )
return V_7 ;
if ( F_131 ( ( char V_247 * ) ( unsigned long ) V_235 -> V_248 , & V_233 , V_87 ) )
V_7 = - V_249 ;
return V_7 ;
}
int F_132 ( struct V_1 * V_6 , struct V_234 * V_235 )
{
int V_7 ;
union V_236 V_233 ;
int V_87 ;
V_87 = F_127 ( V_235 -> V_178 ) ;
if ( V_87 > sizeof( V_233 ) )
return - V_70 ;
if ( F_133 ( & V_233 , ( char V_247 * ) ( unsigned long ) V_235 -> V_248 , V_87 ) )
return - V_249 ;
V_7 = F_134 ( V_6 , V_235 -> V_178 , & V_233 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_235 -> V_178 ) {
#ifdef F_129
case V_237 ... V_238 :
if ( ! F_35 ( V_239 ) ) {
V_7 = - V_240 ;
break;
}
V_233 . V_242 = V_6 -> V_3 . V_241 . V_241 [ V_235 -> V_178 - V_237 ] ;
break;
case V_243 :
if ( ! F_35 ( V_239 ) ) {
V_7 = - V_240 ;
break;
}
V_233 = F_135 ( V_235 -> V_178 , V_6 -> V_3 . V_241 . V_244 . V_245 [ 3 ] ) ;
break;
case V_246 :
V_233 = F_135 ( V_235 -> V_178 , V_6 -> V_3 . V_199 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
return V_7 ;
}
int F_136 ( struct V_1 * V_6 , struct V_71 * V_10 )
{
int V_7 ;
T_3 V_250 ;
if ( V_6 -> V_251 )
F_137 ( V_252 , & V_6 -> V_253 , & V_250 ) ;
if ( V_6 -> V_229 ) {
if ( ! V_6 -> V_230 )
F_112 ( V_6 , V_10 ) ;
V_6 -> V_229 = 0 ;
} else if ( V_6 -> V_3 . V_254 ) {
V_195 * V_255 = V_10 -> V_256 . V_255 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_255 [ V_18 ] ) ;
V_6 -> V_3 . V_254 = 0 ;
} else if ( V_6 -> V_3 . V_257 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_258 . V_190 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_258 . args [ V_18 ] ) ;
V_6 -> V_3 . V_257 = 0 ;
#ifdef F_63
} else if ( V_6 -> V_3 . V_259 ) {
F_138 ( V_6 , V_10 -> V_260 . V_260 ) ;
V_6 -> V_3 . V_259 = 0 ;
#endif
}
V_7 = F_139 ( V_10 , V_6 ) ;
if ( V_6 -> V_251 )
F_137 ( V_252 , & V_250 , NULL ) ;
return V_7 ;
}
int F_140 ( struct V_1 * V_6 , struct V_261 * V_262 )
{
if ( V_262 -> V_262 == V_263 ) {
F_141 ( V_6 ) ;
return 0 ;
}
F_142 ( V_6 , V_262 ) ;
F_143 ( V_6 ) ;
return 0 ;
}
static int F_144 ( struct V_1 * V_6 ,
struct V_264 * V_265 )
{
int V_7 ;
if ( V_265 -> V_266 )
return - V_70 ;
switch ( V_265 -> V_265 ) {
case V_139 :
V_7 = 0 ;
V_6 -> V_3 . V_267 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_265 -> args [ 0 ] )
V_6 -> V_3 . V_268 |= V_269 ;
else
V_6 -> V_3 . V_268 &= ~ V_269 ;
break;
#ifdef F_63
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_270 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_142 : {
struct V_271 V_272 ;
void V_247 * V_273 = ( void V_247 * ) ( V_274 ) V_265 -> args [ 0 ] ;
V_7 = - V_249 ;
if ( F_133 ( & V_272 , V_273 , sizeof( V_272 ) ) )
break;
V_7 = F_145 ( V_6 , & V_272 ) ;
break;
}
#endif
#ifdef F_65
case V_145 : {
struct V_275 V_276 ;
struct V_277 * V_278 ;
V_7 = - V_279 ;
V_276 = F_146 ( V_265 -> args [ 0 ] ) ;
if ( ! V_276 . V_163 )
break;
V_7 = - V_101 ;
V_278 = F_147 ( V_276 . V_163 ) ;
if ( V_278 )
V_7 = F_148 ( V_278 , V_6 , V_265 -> args [ 1 ] ) ;
F_149 ( V_276 ) ;
break;
}
#endif
#ifdef F_66
case V_151 : {
struct V_275 V_276 ;
struct V_277 * V_278 ;
V_7 = - V_279 ;
V_276 = F_146 ( V_265 -> args [ 0 ] ) ;
if ( ! V_276 . V_163 )
break;
V_7 = - V_101 ;
V_278 = F_147 ( V_276 . V_163 ) ;
if ( V_278 )
V_7 = F_150 ( V_278 , V_6 , V_265 -> args [ 1 ] ) ;
F_149 ( V_276 ) ;
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
int F_151 ( struct V_1 * V_6 ,
struct V_280 * V_281 )
{
return - V_70 ;
}
int F_152 ( struct V_1 * V_6 ,
struct V_280 * V_281 )
{
return - V_70 ;
}
long F_153 ( struct V_163 * V_164 ,
unsigned int V_165 , unsigned long V_166 )
{
struct V_1 * V_6 = V_164 -> V_282 ;
void V_247 * V_283 = ( void V_247 * ) V_166 ;
long V_7 ;
switch ( V_165 ) {
case V_284 : {
struct V_261 V_262 ;
V_7 = - V_249 ;
if ( F_133 ( & V_262 , V_283 , sizeof( V_262 ) ) )
goto V_63;
V_7 = F_140 ( V_6 , & V_262 ) ;
goto V_63;
}
case V_285 :
{
struct V_264 V_265 ;
V_7 = - V_249 ;
if ( F_133 ( & V_265 , V_283 , sizeof( V_265 ) ) )
goto V_63;
V_7 = F_144 ( V_6 , & V_265 ) ;
break;
}
case V_286 :
case V_287 :
{
struct V_234 V_235 ;
V_7 = - V_249 ;
if ( F_133 ( & V_235 , V_283 , sizeof( V_235 ) ) )
goto V_63;
if ( V_165 == V_286 )
V_7 = F_132 ( V_6 , & V_235 ) ;
else
V_7 = F_126 ( V_6 , & V_235 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_288 : {
struct V_289 V_290 ;
V_7 = - V_249 ;
if ( F_133 ( & V_290 , V_283 , sizeof( V_290 ) ) )
goto V_63;
V_7 = F_154 ( V_6 , & V_290 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_155 ( struct V_1 * V_6 , struct V_291 * V_292 )
{
return V_293 ;
}
static int F_156 ( struct V_294 * V_295 )
{
T_2 V_296 = 0x60000000 ;
#ifdef F_34
T_2 V_297 = 0x44000022 ;
V_295 -> V_298 [ 0 ] = F_157 ( V_297 ) ;
V_295 -> V_298 [ 1 ] = F_157 ( V_296 ) ;
V_295 -> V_298 [ 2 ] = F_157 ( V_296 ) ;
V_295 -> V_298 [ 3 ] = F_157 ( V_296 ) ;
#else
T_2 V_299 = 0x3c000000 ;
T_2 V_300 = 0x60000000 ;
T_2 V_301 = 0x44000002 ;
T_2 V_302 = 0xffff ;
V_295 -> V_298 [ 0 ] = F_157 ( V_299 | ( ( V_303 >> 16 ) & V_302 ) ) ;
V_295 -> V_298 [ 1 ] = F_157 ( V_300 | ( V_303 & V_302 ) ) ;
V_295 -> V_298 [ 2 ] = F_157 ( V_301 ) ;
V_295 -> V_298 [ 3 ] = F_157 ( V_296 ) ;
#endif
V_295 -> V_266 = V_304 ;
return 0 ;
}
int F_158 ( struct V_67 * V_67 , struct V_305 * V_306 ,
bool V_307 )
{
if ( ! F_159 ( V_67 ) )
return - V_240 ;
V_306 -> V_308 = F_160 ( V_67 , V_309 ,
V_306 -> V_262 , V_306 -> V_310 ,
V_307 ) ;
return 0 ;
}
static int F_161 ( struct V_67 * V_67 ,
struct V_264 * V_265 )
{
int V_7 ;
if ( V_265 -> V_266 )
return - V_70 ;
switch ( V_265 -> V_265 ) {
#ifdef F_162
case V_150 : {
unsigned long V_298 = V_265 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_298 > V_311 || ( V_298 & 3 ) ||
V_265 -> args [ 1 ] > 1 )
break;
if ( ! F_163 ( V_67 , V_298 ) )
break;
if ( V_265 -> args [ 1 ] )
F_164 ( V_298 / 4 , V_67 -> V_3 . V_312 ) ;
else
F_30 ( V_298 / 4 , V_67 -> V_3 . V_312 ) ;
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
long F_165 ( struct V_163 * V_164 ,
unsigned int V_165 , unsigned long V_166 )
{
struct V_67 * V_67 T_1 = V_164 -> V_282 ;
void V_247 * V_283 = ( void V_247 * ) V_166 ;
long V_7 ;
switch ( V_165 ) {
case V_313 : {
struct V_294 V_295 ;
memset ( & V_295 , 0 , sizeof( V_295 ) ) ;
V_7 = F_156 ( & V_295 ) ;
if ( F_131 ( V_283 , & V_295 , sizeof( V_295 ) ) ) {
V_7 = - V_249 ;
goto V_63;
}
break;
}
case V_285 :
{
struct V_264 V_265 ;
V_7 = - V_249 ;
if ( F_133 ( & V_265 , V_283 , sizeof( V_265 ) ) )
goto V_63;
V_7 = F_161 ( V_67 , & V_265 ) ;
break;
}
#ifdef V_38
case V_314 : {
struct V_315 V_316 ;
V_7 = - V_249 ;
if ( F_133 ( & V_316 , V_283 , sizeof( V_316 ) ) )
goto V_63;
V_7 = F_166 ( V_67 , & V_316 ) ;
goto V_63;
}
case V_317 : {
struct V_318 V_319 ;
struct V_67 * V_67 = V_164 -> V_282 ;
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_320 ( V_67 , & V_319 ) ;
if ( V_7 >= 0 && F_131 ( V_283 , & V_319 , sizeof( V_319 ) ) )
V_7 = - V_249 ;
break;
}
case V_321 : {
struct V_67 * V_67 = V_164 -> V_282 ;
V_7 = F_167 ( V_67 , V_283 ) ;
break;
}
default: {
struct V_67 * V_67 = V_164 -> V_282 ;
V_7 = V_67 -> V_3 . V_112 -> V_322 ( V_164 , V_165 , V_166 ) ;
}
#else
default:
V_7 = - V_323 ;
#endif
}
V_63:
return V_7 ;
}
long F_168 ( void )
{
long V_324 ;
do {
V_324 = F_169 ( V_325 , V_326 ) ;
if ( V_324 >= V_327 ) {
F_170 ( L_4 , V_84 ) ;
return - V_328 ;
}
} while ( F_171 ( V_324 , V_325 ) );
return V_324 ;
}
void F_172 ( long V_324 )
{
F_164 ( V_324 , V_325 ) ;
}
void F_173 ( long V_324 )
{
F_30 ( V_324 , V_325 ) ;
}
void F_174 ( unsigned long V_329 )
{
V_327 = F_175 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_325 , 0 , sizeof( V_325 ) ) ;
}
int F_176 ( void * V_330 )
{
return 0 ;
}
