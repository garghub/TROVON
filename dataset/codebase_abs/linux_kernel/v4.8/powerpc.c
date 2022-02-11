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
#ifdef F_54
if ( F_33 ( V_67 ) )
F_55 () ;
#endif
F_56 (i, vcpu, kvm)
F_57 ( V_6 ) ;
F_58 ( & V_67 -> V_120 ) ;
for ( V_18 = 0 ; V_18 < F_59 ( & V_67 -> V_121 ) ; V_18 ++ )
V_67 -> V_122 [ V_18 ] = NULL ;
F_60 ( & V_67 -> V_121 , 0 ) ;
F_61 ( V_67 ) ;
F_62 ( & V_67 -> V_120 ) ;
F_63 ( V_67 -> V_3 . V_112 -> V_118 ) ;
}
int F_64 ( struct V_67 * V_67 , long V_123 )
{
int V_7 ;
int V_124 = V_113 ? 1 : 0 ;
if ( V_67 ) {
V_124 = F_33 ( V_67 ) ;
}
switch ( V_123 ) {
#ifdef F_65
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
#ifdef F_66
case V_143 :
V_7 = V_144 ;
break;
#endif
#ifdef F_67
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
#ifdef F_54
case V_152 :
#endif
V_7 = 1 ;
break;
#endif
#ifdef F_68
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
V_7 = F_69 () ;
break;
#endif
case V_157 :
#ifdef F_68
V_7 = V_124 ;
#elif F_25 ( V_158 )
V_7 = 1 ;
#else
V_7 = 0 ;
#endif
break;
#ifdef F_68
case V_159 :
V_7 = V_124 ;
break;
#endif
case V_160 :
if ( V_124 )
V_7 = F_70 () ;
else
V_7 = F_71 () ;
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
long F_72 ( struct V_169 * V_170 ,
unsigned int V_171 , unsigned long V_172 )
{
return - V_70 ;
}
void F_73 ( struct V_67 * V_67 , struct V_173 * free ,
struct V_173 * V_174 )
{
F_74 ( V_67 , free , V_174 ) ;
}
int F_75 ( struct V_67 * V_67 , struct V_173 * V_175 ,
unsigned long V_176 )
{
return F_76 ( V_67 , V_175 , V_176 ) ;
}
int F_77 ( struct V_67 * V_67 ,
struct V_173 * V_177 ,
const struct V_178 * V_179 ,
enum V_180 V_181 )
{
return F_78 ( V_67 , V_177 , V_179 ) ;
}
void F_79 ( struct V_67 * V_67 ,
const struct V_178 * V_179 ,
const struct V_173 * V_182 ,
const struct V_173 * V_183 ,
enum V_180 V_181 )
{
F_80 ( V_67 , V_179 , V_182 , V_183 ) ;
}
void F_81 ( struct V_67 * V_67 ,
struct V_173 * V_175 )
{
F_82 ( V_67 , V_175 ) ;
}
struct V_1 * F_83 ( struct V_67 * V_67 , unsigned int V_184 )
{
struct V_1 * V_6 ;
V_6 = F_84 ( V_67 , V_184 ) ;
if ( ! F_85 ( V_6 ) ) {
V_6 -> V_3 . V_185 = & V_6 -> V_186 ;
F_86 ( V_6 , V_184 ) ;
}
return V_6 ;
}
void F_87 ( struct V_1 * V_6 )
{
}
void F_57 ( struct V_1 * V_6 )
{
F_88 ( & V_6 -> V_3 . V_187 ) ;
F_89 ( V_6 ) ;
switch ( V_6 -> V_3 . V_188 ) {
case V_189 :
F_90 ( V_6 -> V_3 . V_190 , V_6 ) ;
break;
case V_191 :
F_91 ( V_6 ) ;
break;
}
F_92 ( V_6 ) ;
}
void F_93 ( struct V_1 * V_6 )
{
F_57 ( V_6 ) ;
}
int F_94 ( struct V_1 * V_6 )
{
return F_95 ( V_6 ) ;
}
static enum V_192 F_96 ( struct V_193 * V_194 )
{
struct V_1 * V_6 ;
V_6 = F_97 ( V_194 , struct V_1 , V_3 . V_187 ) ;
F_98 ( V_6 ) ;
return V_195 ;
}
int F_99 ( struct V_1 * V_6 )
{
int V_196 ;
F_100 ( & V_6 -> V_3 . V_187 , V_197 , V_198 ) ;
V_6 -> V_3 . V_187 . V_199 = F_96 ;
V_6 -> V_3 . V_200 = ~ ( V_201 ) 0 ;
#ifdef F_101
F_102 ( & V_6 -> V_3 . V_202 ) ;
#endif
V_196 = F_103 ( V_6 ) ;
return V_196 ;
}
void F_104 ( struct V_1 * V_6 )
{
F_105 ( V_6 ) ;
F_106 ( V_6 ) ;
}
void F_107 ( struct V_1 * V_6 , int V_203 )
{
#ifdef F_65
F_108 ( V_204 , V_6 -> V_3 . V_205 ) ;
#endif
F_109 ( V_6 , V_203 ) ;
}
void F_110 ( struct V_1 * V_6 )
{
F_111 ( V_6 ) ;
#ifdef F_65
V_6 -> V_3 . V_205 = F_112 ( V_204 ) ;
#endif
}
static void F_113 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_201 V_206 ( V_207 ) ;
if ( V_10 -> V_208 . V_209 > sizeof( V_207 ) ) {
F_114 ( V_210 L_2 , V_10 -> V_208 . V_209 ) ;
return;
}
if ( ! V_6 -> V_3 . V_211 ) {
switch ( V_10 -> V_208 . V_209 ) {
case 8 : V_207 = * ( V_201 * ) V_10 -> V_208 . V_89 ; break;
case 4 : V_207 = * ( T_2 * ) V_10 -> V_208 . V_89 ; break;
case 2 : V_207 = * ( V_212 * ) V_10 -> V_208 . V_89 ; break;
case 1 : V_207 = * ( V_213 * ) V_10 -> V_208 . V_89 ; break;
}
} else {
switch ( V_10 -> V_208 . V_209 ) {
case 8 : V_207 = F_18 ( * ( V_201 * ) V_10 -> V_208 . V_89 ) ; break;
case 4 : V_207 = F_19 ( * ( T_2 * ) V_10 -> V_208 . V_89 ) ; break;
case 2 : V_207 = F_115 ( * ( V_212 * ) V_10 -> V_208 . V_89 ) ; break;
case 1 : V_207 = * ( V_213 * ) V_10 -> V_208 . V_89 ; break;
}
}
if ( V_6 -> V_3 . V_214 ) {
switch ( V_10 -> V_208 . V_209 ) {
#ifdef F_116
case 4 :
V_207 = ( V_215 ) ( V_216 ) V_207 ;
break;
#endif
case 2 :
V_207 = ( V_215 ) ( V_217 ) V_207 ;
break;
case 1 :
V_207 = ( V_215 ) ( V_218 ) V_207 ;
break;
}
}
F_31 ( V_6 , V_6 -> V_3 . V_219 , V_207 ) ;
switch ( V_6 -> V_3 . V_219 & V_220 ) {
case V_221 :
F_31 ( V_6 , V_6 -> V_3 . V_219 , V_207 ) ;
break;
case V_222 :
F_117 ( V_6 , V_6 -> V_3 . V_219 & V_223 ) = V_207 ;
break;
#ifdef V_56
case V_224 :
V_6 -> V_3 . V_225 [ V_6 -> V_3 . V_219 & V_223 ] = V_207 ;
break;
case V_226 :
F_117 ( V_6 , V_6 -> V_3 . V_219 & V_223 ) = V_207 ;
V_6 -> V_3 . V_225 [ V_6 -> V_3 . V_219 & V_223 ] = V_207 ;
break;
#endif
default:
F_118 () ;
}
}
static int F_119 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_227 , unsigned int V_228 ,
int V_229 , int V_230 )
{
int V_231 , V_196 ;
bool V_232 ;
if ( F_120 ( V_6 ) ) {
V_232 = V_229 ;
} else {
V_232 = ! V_229 ;
}
if ( V_228 > sizeof( V_10 -> V_208 . V_89 ) ) {
F_114 ( V_210 L_3 , V_84 ,
V_10 -> V_208 . V_209 ) ;
}
V_10 -> V_208 . V_233 = V_6 -> V_3 . V_234 ;
V_10 -> V_208 . V_209 = V_228 ;
V_10 -> V_208 . V_235 = 0 ;
V_6 -> V_3 . V_219 = V_227 ;
V_6 -> V_3 . V_211 = V_232 ;
V_6 -> V_236 = 1 ;
V_6 -> V_237 = 0 ;
V_6 -> V_3 . V_214 = V_230 ;
V_231 = F_121 ( & V_6 -> V_67 -> V_238 ) ;
V_196 = F_122 ( V_6 , V_239 , V_10 -> V_208 . V_233 ,
V_228 , & V_10 -> V_208 . V_89 ) ;
F_123 ( & V_6 -> V_67 -> V_238 , V_231 ) ;
if ( ! V_196 ) {
F_113 ( V_6 , V_10 ) ;
V_6 -> V_236 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_124 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_227 , unsigned int V_228 ,
int V_229 )
{
return F_119 ( V_10 , V_6 , V_227 , V_228 , V_229 , 0 ) ;
}
int F_125 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_227 , unsigned int V_228 ,
int V_229 )
{
return F_119 ( V_10 , V_6 , V_227 , V_228 , V_229 , 1 ) ;
}
int F_126 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_201 V_240 , unsigned int V_228 , int V_229 )
{
void * V_89 = V_10 -> V_208 . V_89 ;
int V_231 , V_196 ;
bool V_232 ;
if ( F_120 ( V_6 ) ) {
V_232 = V_229 ;
} else {
V_232 = ! V_229 ;
}
if ( V_228 > sizeof( V_10 -> V_208 . V_89 ) ) {
F_114 ( V_210 L_3 , V_84 ,
V_10 -> V_208 . V_209 ) ;
}
V_10 -> V_208 . V_233 = V_6 -> V_3 . V_234 ;
V_10 -> V_208 . V_209 = V_228 ;
V_10 -> V_208 . V_235 = 1 ;
V_6 -> V_236 = 1 ;
V_6 -> V_237 = 1 ;
if ( ! V_232 ) {
switch ( V_228 ) {
case 8 : * ( V_201 * ) V_89 = V_240 ; break;
case 4 : * ( T_2 * ) V_89 = V_240 ; break;
case 2 : * ( V_212 * ) V_89 = V_240 ; break;
case 1 : * ( V_213 * ) V_89 = V_240 ; break;
}
} else {
switch ( V_228 ) {
case 8 : * ( V_201 * ) V_89 = F_18 ( V_240 ) ; break;
case 4 : * ( T_2 * ) V_89 = F_19 ( V_240 ) ; break;
case 2 : * ( V_212 * ) V_89 = F_115 ( V_240 ) ; break;
case 1 : * ( V_213 * ) V_89 = V_240 ; break;
}
}
V_231 = F_121 ( & V_6 -> V_67 -> V_238 ) ;
V_196 = F_127 ( V_6 , V_239 , V_10 -> V_208 . V_233 ,
V_228 , & V_10 -> V_208 . V_89 ) ;
F_123 ( & V_6 -> V_67 -> V_238 , V_231 ) ;
if ( ! V_196 ) {
V_6 -> V_236 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_128 ( struct V_1 * V_6 , struct V_241 * V_242 )
{
int V_7 = 0 ;
union V_243 V_240 ;
int V_87 ;
V_87 = F_129 ( V_242 -> V_184 ) ;
if ( V_87 > sizeof( V_240 ) )
return - V_70 ;
V_7 = F_130 ( V_6 , V_242 -> V_184 , & V_240 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_242 -> V_184 ) {
#ifdef F_131
case V_244 ... V_245 :
if ( ! F_35 ( V_246 ) ) {
V_7 = - V_247 ;
break;
}
V_240 . V_248 = V_6 -> V_3 . V_249 . V_249 [ V_242 -> V_184 - V_244 ] ;
break;
case V_250 :
if ( ! F_35 ( V_246 ) ) {
V_7 = - V_247 ;
break;
}
V_240 = F_132 ( V_242 -> V_184 , V_6 -> V_3 . V_249 . V_251 . V_252 [ 3 ] ) ;
break;
case V_253 :
V_240 = F_132 ( V_242 -> V_184 , V_6 -> V_3 . V_205 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
if ( V_7 )
return V_7 ;
if ( F_133 ( ( char V_254 * ) ( unsigned long ) V_242 -> V_255 , & V_240 , V_87 ) )
V_7 = - V_256 ;
return V_7 ;
}
int F_134 ( struct V_1 * V_6 , struct V_241 * V_242 )
{
int V_7 ;
union V_243 V_240 ;
int V_87 ;
V_87 = F_129 ( V_242 -> V_184 ) ;
if ( V_87 > sizeof( V_240 ) )
return - V_70 ;
if ( F_135 ( & V_240 , ( char V_254 * ) ( unsigned long ) V_242 -> V_255 , V_87 ) )
return - V_256 ;
V_7 = F_136 ( V_6 , V_242 -> V_184 , & V_240 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_242 -> V_184 ) {
#ifdef F_131
case V_244 ... V_245 :
if ( ! F_35 ( V_246 ) ) {
V_7 = - V_247 ;
break;
}
V_6 -> V_3 . V_249 . V_249 [ V_242 -> V_184 - V_244 ] = V_240 . V_248 ;
break;
case V_250 :
if ( ! F_35 ( V_246 ) ) {
V_7 = - V_247 ;
break;
}
V_6 -> V_3 . V_249 . V_251 . V_252 [ 3 ] = F_137 ( V_242 -> V_184 , V_240 ) ;
break;
case V_253 :
if ( ! F_35 ( V_246 ) ) {
V_7 = - V_247 ;
break;
}
V_6 -> V_3 . V_205 = F_137 ( V_242 -> V_184 , V_240 ) ;
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
T_3 V_257 ;
if ( V_6 -> V_258 )
F_139 ( V_259 , & V_6 -> V_260 , & V_257 ) ;
if ( V_6 -> V_236 ) {
if ( ! V_6 -> V_237 )
F_113 ( V_6 , V_10 ) ;
V_6 -> V_236 = 0 ;
} else if ( V_6 -> V_3 . V_261 ) {
V_201 * V_262 = V_10 -> V_263 . V_262 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_262 [ V_18 ] ) ;
V_6 -> V_3 . V_261 = 0 ;
} else if ( V_6 -> V_3 . V_264 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_265 . V_196 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_265 . args [ V_18 ] ) ;
V_6 -> V_3 . V_264 = 0 ;
#ifdef F_65
} else if ( V_6 -> V_3 . V_266 ) {
F_140 ( V_6 , V_10 -> V_267 . V_267 ) ;
V_6 -> V_3 . V_266 = 0 ;
#endif
}
V_7 = F_141 ( V_10 , V_6 ) ;
if ( V_6 -> V_258 )
F_139 ( V_259 , & V_257 , NULL ) ;
return V_7 ;
}
int F_142 ( struct V_1 * V_6 , struct V_268 * V_269 )
{
if ( V_269 -> V_269 == V_270 ) {
F_143 ( V_6 ) ;
return 0 ;
}
F_144 ( V_6 , V_269 ) ;
F_145 ( V_6 ) ;
return 0 ;
}
static int F_146 ( struct V_1 * V_6 ,
struct V_271 * V_272 )
{
int V_7 ;
if ( V_272 -> V_273 )
return - V_70 ;
switch ( V_272 -> V_272 ) {
case V_139 :
V_7 = 0 ;
V_6 -> V_3 . V_274 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_272 -> args [ 0 ] )
V_6 -> V_3 . V_275 |= V_276 ;
else
V_6 -> V_3 . V_275 &= ~ V_276 ;
break;
#ifdef F_65
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_277 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_142 : {
struct V_278 V_279 ;
void V_254 * V_280 = ( void V_254 * ) ( V_281 ) V_272 -> args [ 0 ] ;
V_7 = - V_256 ;
if ( F_135 ( & V_279 , V_280 , sizeof( V_279 ) ) )
break;
V_7 = F_147 ( V_6 , & V_279 ) ;
break;
}
#endif
#ifdef F_67
case V_145 : {
struct V_282 V_283 ;
struct V_284 * V_285 ;
V_7 = - V_286 ;
V_283 = F_148 ( V_272 -> args [ 0 ] ) ;
if ( ! V_283 . V_169 )
break;
V_7 = - V_101 ;
V_285 = F_149 ( V_283 . V_169 ) ;
if ( V_285 )
V_7 = F_150 ( V_285 , V_6 , V_272 -> args [ 1 ] ) ;
F_151 ( V_283 ) ;
break;
}
#endif
#ifdef F_54
case V_152 : {
struct V_282 V_283 ;
struct V_284 * V_285 ;
V_7 = - V_286 ;
V_283 = F_148 ( V_272 -> args [ 0 ] ) ;
if ( ! V_283 . V_169 )
break;
V_7 = - V_101 ;
V_285 = F_149 ( V_283 . V_169 ) ;
if ( V_285 )
V_7 = F_152 ( V_285 , V_6 , V_272 -> args [ 1 ] ) ;
F_151 ( V_283 ) ;
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
struct V_287 * V_288 )
{
return - V_70 ;
}
int F_154 ( struct V_1 * V_6 ,
struct V_287 * V_288 )
{
return - V_70 ;
}
long F_155 ( struct V_169 * V_170 ,
unsigned int V_171 , unsigned long V_172 )
{
struct V_1 * V_6 = V_170 -> V_289 ;
void V_254 * V_290 = ( void V_254 * ) V_172 ;
long V_7 ;
switch ( V_171 ) {
case V_291 : {
struct V_268 V_269 ;
V_7 = - V_256 ;
if ( F_135 ( & V_269 , V_290 , sizeof( V_269 ) ) )
goto V_63;
V_7 = F_142 ( V_6 , & V_269 ) ;
goto V_63;
}
case V_292 :
{
struct V_271 V_272 ;
V_7 = - V_256 ;
if ( F_135 ( & V_272 , V_290 , sizeof( V_272 ) ) )
goto V_63;
V_7 = F_146 ( V_6 , & V_272 ) ;
break;
}
case V_293 :
case V_294 :
{
struct V_241 V_242 ;
V_7 = - V_256 ;
if ( F_135 ( & V_242 , V_290 , sizeof( V_242 ) ) )
goto V_63;
if ( V_171 == V_293 )
V_7 = F_134 ( V_6 , & V_242 ) ;
else
V_7 = F_128 ( V_6 , & V_242 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_295 : {
struct V_296 V_297 ;
V_7 = - V_256 ;
if ( F_135 ( & V_297 , V_290 , sizeof( V_297 ) ) )
goto V_63;
V_7 = F_156 ( V_6 , & V_297 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_157 ( struct V_1 * V_6 , struct V_298 * V_299 )
{
return V_300 ;
}
static int F_158 ( struct V_301 * V_302 )
{
T_2 V_303 = 0x60000000 ;
#ifdef F_34
T_2 V_304 = 0x44000022 ;
V_302 -> V_305 [ 0 ] = F_159 ( V_304 ) ;
V_302 -> V_305 [ 1 ] = F_159 ( V_303 ) ;
V_302 -> V_305 [ 2 ] = F_159 ( V_303 ) ;
V_302 -> V_305 [ 3 ] = F_159 ( V_303 ) ;
#else
T_2 V_306 = 0x3c000000 ;
T_2 V_307 = 0x60000000 ;
T_2 V_308 = 0x44000002 ;
T_2 V_309 = 0xffff ;
V_302 -> V_305 [ 0 ] = F_159 ( V_306 | ( ( V_310 >> 16 ) & V_309 ) ) ;
V_302 -> V_305 [ 1 ] = F_159 ( V_307 | ( V_310 & V_309 ) ) ;
V_302 -> V_305 [ 2 ] = F_159 ( V_308 ) ;
V_302 -> V_305 [ 3 ] = F_159 ( V_303 ) ;
#endif
V_302 -> V_273 = V_311 ;
return 0 ;
}
int F_160 ( struct V_67 * V_67 , struct V_312 * V_313 ,
bool V_314 )
{
if ( ! F_161 ( V_67 ) )
return - V_247 ;
V_313 -> V_315 = F_162 ( V_67 , V_316 ,
V_313 -> V_269 , V_313 -> V_317 ,
V_314 ) ;
return 0 ;
}
static int F_163 ( struct V_67 * V_67 ,
struct V_271 * V_272 )
{
int V_7 ;
if ( V_272 -> V_273 )
return - V_70 ;
switch ( V_272 -> V_272 ) {
#ifdef F_164
case V_151 : {
unsigned long V_305 = V_272 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_305 > V_318 || ( V_305 & 3 ) ||
V_272 -> args [ 1 ] > 1 )
break;
if ( ! F_165 ( V_67 , V_305 ) )
break;
if ( V_272 -> args [ 1 ] )
F_166 ( V_305 / 4 , V_67 -> V_3 . V_319 ) ;
else
F_30 ( V_305 / 4 , V_67 -> V_3 . V_319 ) ;
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
long F_167 ( struct V_169 * V_170 ,
unsigned int V_171 , unsigned long V_172 )
{
struct V_67 * V_67 T_1 = V_170 -> V_289 ;
void V_254 * V_290 = ( void V_254 * ) V_172 ;
long V_7 ;
switch ( V_171 ) {
case V_320 : {
struct V_301 V_302 ;
memset ( & V_302 , 0 , sizeof( V_302 ) ) ;
V_7 = F_158 ( & V_302 ) ;
if ( F_133 ( V_290 , & V_302 , sizeof( V_302 ) ) ) {
V_7 = - V_256 ;
goto V_63;
}
break;
}
case V_292 :
{
struct V_271 V_272 ;
V_7 = - V_256 ;
if ( F_135 ( & V_272 , V_290 , sizeof( V_272 ) ) )
goto V_63;
V_7 = F_163 ( V_67 , & V_272 ) ;
break;
}
#ifdef V_38
case V_321 : {
struct V_322 V_323 ;
V_7 = - V_256 ;
if ( F_135 ( & V_323 , V_290 , sizeof( V_323 ) ) )
goto V_63;
if ( V_323 . V_273 ) {
V_7 = - V_70 ;
goto V_63;
}
V_7 = F_168 ( V_67 , & V_323 ) ;
goto V_63;
}
case V_324 : {
struct V_325 V_326 ;
struct V_322 V_323 ;
V_7 = - V_256 ;
if ( F_135 ( & V_326 , V_290 , sizeof( V_326 ) ) )
goto V_63;
V_323 . V_327 = V_326 . V_327 ;
V_323 . V_328 = V_329 ;
V_323 . V_330 = 0 ;
V_323 . V_87 = V_326 . V_331 >>
V_329 ;
V_323 . V_273 = 0 ;
V_7 = F_168 ( V_67 , & V_323 ) ;
goto V_63;
}
case V_332 : {
struct V_333 V_334 ;
struct V_67 * V_67 = V_170 -> V_289 ;
memset ( & V_334 , 0 , sizeof( V_334 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_335 ( V_67 , & V_334 ) ;
if ( V_7 >= 0 && F_133 ( V_290 , & V_334 , sizeof( V_334 ) ) )
V_7 = - V_256 ;
break;
}
case V_336 : {
struct V_67 * V_67 = V_170 -> V_289 ;
V_7 = F_169 ( V_67 , V_290 ) ;
break;
}
default: {
struct V_67 * V_67 = V_170 -> V_289 ;
V_7 = V_67 -> V_3 . V_112 -> V_337 ( V_170 , V_171 , V_172 ) ;
}
#else
default:
V_7 = - V_338 ;
#endif
}
V_63:
return V_7 ;
}
long F_170 ( void )
{
long V_339 ;
do {
V_339 = F_171 ( V_340 , V_341 ) ;
if ( V_339 >= V_342 ) {
F_172 ( L_4 , V_84 ) ;
return - V_343 ;
}
} while ( F_173 ( V_339 , V_340 ) );
return V_339 ;
}
void F_174 ( long V_339 )
{
F_166 ( V_339 , V_340 ) ;
}
void F_175 ( long V_339 )
{
F_30 ( V_339 , V_340 ) ;
}
void F_176 ( unsigned long V_344 )
{
V_342 = F_177 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_340 , 0 , sizeof( V_340 ) ) ;
}
int F_178 ( void * V_345 )
{
return 0 ;
}
