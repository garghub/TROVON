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
case V_162 :
V_7 = V_163 ;
break;
#ifdef V_38
case V_164 :
V_7 = 1 ;
break;
#endif
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_71 ( struct V_165 * V_166 ,
unsigned int V_167 , unsigned long V_168 )
{
return - V_70 ;
}
void F_72 ( struct V_67 * V_67 , struct V_169 * free ,
struct V_169 * V_170 )
{
F_73 ( V_67 , free , V_170 ) ;
}
int F_74 ( struct V_67 * V_67 , struct V_169 * V_171 ,
unsigned long V_172 )
{
return F_75 ( V_67 , V_171 , V_172 ) ;
}
int F_76 ( struct V_67 * V_67 ,
struct V_169 * V_173 ,
const struct V_174 * V_175 ,
enum V_176 V_177 )
{
return F_77 ( V_67 , V_173 , V_175 ) ;
}
void F_78 ( struct V_67 * V_67 ,
const struct V_174 * V_175 ,
const struct V_169 * V_178 ,
const struct V_169 * V_179 ,
enum V_176 V_177 )
{
F_79 ( V_67 , V_175 , V_178 , V_179 ) ;
}
void F_80 ( struct V_67 * V_67 ,
struct V_169 * V_171 )
{
F_81 ( V_67 , V_171 ) ;
}
struct V_1 * F_82 ( struct V_67 * V_67 , unsigned int V_180 )
{
struct V_1 * V_6 ;
V_6 = F_83 ( V_67 , V_180 ) ;
if ( ! F_84 ( V_6 ) ) {
V_6 -> V_3 . V_181 = & V_6 -> V_182 ;
F_85 ( V_6 , V_180 ) ;
}
return V_6 ;
}
void F_86 ( struct V_1 * V_6 )
{
}
void F_55 ( struct V_1 * V_6 )
{
F_87 ( & V_6 -> V_3 . V_183 ) ;
F_88 ( V_6 ) ;
switch ( V_6 -> V_3 . V_184 ) {
case V_185 :
F_89 ( V_6 -> V_3 . V_186 , V_6 ) ;
break;
case V_187 :
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
static enum V_188 F_95 ( struct V_189 * V_190 )
{
struct V_1 * V_6 ;
V_6 = F_96 ( V_190 , struct V_1 , V_3 . V_183 ) ;
F_97 ( V_6 ) ;
return V_191 ;
}
int F_98 ( struct V_1 * V_6 )
{
int V_192 ;
F_99 ( & V_6 -> V_3 . V_183 , V_193 , V_194 ) ;
V_6 -> V_3 . V_183 . V_195 = F_95 ;
V_6 -> V_3 . V_196 = ~ ( V_197 ) 0 ;
#ifdef F_100
F_101 ( & V_6 -> V_3 . V_198 ) ;
#endif
V_192 = F_102 ( V_6 ) ;
return V_192 ;
}
void F_103 ( struct V_1 * V_6 )
{
F_104 ( V_6 ) ;
F_105 ( V_6 ) ;
}
void F_106 ( struct V_1 * V_6 , int V_199 )
{
#ifdef F_63
F_107 ( V_200 , V_6 -> V_3 . V_201 ) ;
#endif
F_108 ( V_6 , V_199 ) ;
}
void F_109 ( struct V_1 * V_6 )
{
F_110 ( V_6 ) ;
#ifdef F_63
V_6 -> V_3 . V_201 = F_111 ( V_200 ) ;
#endif
}
static void F_112 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_197 V_202 ( V_203 ) ;
if ( V_10 -> V_204 . V_205 > sizeof( V_203 ) ) {
F_113 ( V_206 L_2 , V_10 -> V_204 . V_205 ) ;
return;
}
if ( ! V_6 -> V_3 . V_207 ) {
switch ( V_10 -> V_204 . V_205 ) {
case 8 : V_203 = * ( V_197 * ) V_10 -> V_204 . V_89 ; break;
case 4 : V_203 = * ( T_2 * ) V_10 -> V_204 . V_89 ; break;
case 2 : V_203 = * ( V_208 * ) V_10 -> V_204 . V_89 ; break;
case 1 : V_203 = * ( V_209 * ) V_10 -> V_204 . V_89 ; break;
}
} else {
switch ( V_10 -> V_204 . V_205 ) {
case 8 : V_203 = F_18 ( * ( V_197 * ) V_10 -> V_204 . V_89 ) ; break;
case 4 : V_203 = F_19 ( * ( T_2 * ) V_10 -> V_204 . V_89 ) ; break;
case 2 : V_203 = F_114 ( * ( V_208 * ) V_10 -> V_204 . V_89 ) ; break;
case 1 : V_203 = * ( V_209 * ) V_10 -> V_204 . V_89 ; break;
}
}
if ( V_6 -> V_3 . V_210 ) {
switch ( V_10 -> V_204 . V_205 ) {
#ifdef F_115
case 4 :
V_203 = ( V_211 ) ( V_212 ) V_203 ;
break;
#endif
case 2 :
V_203 = ( V_211 ) ( V_213 ) V_203 ;
break;
case 1 :
V_203 = ( V_211 ) ( V_214 ) V_203 ;
break;
}
}
F_31 ( V_6 , V_6 -> V_3 . V_215 , V_203 ) ;
switch ( V_6 -> V_3 . V_215 & V_216 ) {
case V_217 :
F_31 ( V_6 , V_6 -> V_3 . V_215 , V_203 ) ;
break;
case V_218 :
F_116 ( V_6 , V_6 -> V_3 . V_215 & V_219 ) = V_203 ;
break;
#ifdef V_56
case V_220 :
V_6 -> V_3 . V_221 [ V_6 -> V_3 . V_215 & V_219 ] = V_203 ;
break;
case V_222 :
F_116 ( V_6 , V_6 -> V_3 . V_215 & V_219 ) = V_203 ;
V_6 -> V_3 . V_221 [ V_6 -> V_3 . V_215 & V_219 ] = V_203 ;
break;
#endif
default:
F_117 () ;
}
}
int F_118 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_223 , unsigned int V_224 ,
int V_225 )
{
int V_226 , V_192 ;
bool V_227 ;
if ( F_119 ( V_6 ) ) {
V_227 = V_225 ;
} else {
V_227 = ! V_225 ;
}
if ( V_224 > sizeof( V_10 -> V_204 . V_89 ) ) {
F_113 ( V_206 L_3 , V_84 ,
V_10 -> V_204 . V_205 ) ;
}
V_10 -> V_204 . V_228 = V_6 -> V_3 . V_229 ;
V_10 -> V_204 . V_205 = V_224 ;
V_10 -> V_204 . V_230 = 0 ;
V_6 -> V_3 . V_215 = V_223 ;
V_6 -> V_3 . V_207 = V_227 ;
V_6 -> V_231 = 1 ;
V_6 -> V_232 = 0 ;
V_6 -> V_3 . V_210 = 0 ;
V_226 = F_120 ( & V_6 -> V_67 -> V_233 ) ;
V_192 = F_121 ( V_6 , V_234 , V_10 -> V_204 . V_228 ,
V_224 , & V_10 -> V_204 . V_89 ) ;
F_122 ( & V_6 -> V_67 -> V_233 , V_226 ) ;
if ( ! V_192 ) {
F_112 ( V_6 , V_10 ) ;
V_6 -> V_231 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_123 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_223 , unsigned int V_224 ,
int V_225 )
{
int V_7 ;
V_6 -> V_3 . V_210 = 1 ;
V_7 = F_118 ( V_10 , V_6 , V_223 , V_224 , V_225 ) ;
return V_7 ;
}
int F_124 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_197 V_235 , unsigned int V_224 , int V_225 )
{
void * V_89 = V_10 -> V_204 . V_89 ;
int V_226 , V_192 ;
bool V_227 ;
if ( F_119 ( V_6 ) ) {
V_227 = V_225 ;
} else {
V_227 = ! V_225 ;
}
if ( V_224 > sizeof( V_10 -> V_204 . V_89 ) ) {
F_113 ( V_206 L_3 , V_84 ,
V_10 -> V_204 . V_205 ) ;
}
V_10 -> V_204 . V_228 = V_6 -> V_3 . V_229 ;
V_10 -> V_204 . V_205 = V_224 ;
V_10 -> V_204 . V_230 = 1 ;
V_6 -> V_231 = 1 ;
V_6 -> V_232 = 1 ;
if ( ! V_227 ) {
switch ( V_224 ) {
case 8 : * ( V_197 * ) V_89 = V_235 ; break;
case 4 : * ( T_2 * ) V_89 = V_235 ; break;
case 2 : * ( V_208 * ) V_89 = V_235 ; break;
case 1 : * ( V_209 * ) V_89 = V_235 ; break;
}
} else {
switch ( V_224 ) {
case 8 : * ( V_197 * ) V_89 = F_18 ( V_235 ) ; break;
case 4 : * ( T_2 * ) V_89 = F_19 ( V_235 ) ; break;
case 2 : * ( V_208 * ) V_89 = F_114 ( V_235 ) ; break;
case 1 : * ( V_209 * ) V_89 = V_235 ; break;
}
}
V_226 = F_120 ( & V_6 -> V_67 -> V_233 ) ;
V_192 = F_125 ( V_6 , V_234 , V_10 -> V_204 . V_228 ,
V_224 , & V_10 -> V_204 . V_89 ) ;
F_122 ( & V_6 -> V_67 -> V_233 , V_226 ) ;
if ( ! V_192 ) {
V_6 -> V_231 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_126 ( struct V_1 * V_6 , struct V_236 * V_237 )
{
int V_7 = 0 ;
union V_238 V_235 ;
int V_87 ;
V_87 = F_127 ( V_237 -> V_180 ) ;
if ( V_87 > sizeof( V_235 ) )
return - V_70 ;
V_7 = F_128 ( V_6 , V_237 -> V_180 , & V_235 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_237 -> V_180 ) {
#ifdef F_129
case V_239 ... V_240 :
if ( ! F_35 ( V_241 ) ) {
V_7 = - V_242 ;
break;
}
V_6 -> V_3 . V_243 . V_243 [ V_237 -> V_180 - V_239 ] = V_235 . V_244 ;
break;
case V_245 :
if ( ! F_35 ( V_241 ) ) {
V_7 = - V_242 ;
break;
}
V_6 -> V_3 . V_243 . V_246 . V_247 [ 3 ] = F_130 ( V_237 -> V_180 , V_235 ) ;
break;
case V_248 :
if ( ! F_35 ( V_241 ) ) {
V_7 = - V_242 ;
break;
}
V_6 -> V_3 . V_201 = F_130 ( V_237 -> V_180 , V_235 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
if ( V_7 )
return V_7 ;
if ( F_131 ( ( char V_249 * ) ( unsigned long ) V_237 -> V_250 , & V_235 , V_87 ) )
V_7 = - V_251 ;
return V_7 ;
}
int F_132 ( struct V_1 * V_6 , struct V_236 * V_237 )
{
int V_7 ;
union V_238 V_235 ;
int V_87 ;
V_87 = F_127 ( V_237 -> V_180 ) ;
if ( V_87 > sizeof( V_235 ) )
return - V_70 ;
if ( F_133 ( & V_235 , ( char V_249 * ) ( unsigned long ) V_237 -> V_250 , V_87 ) )
return - V_251 ;
V_7 = F_134 ( V_6 , V_237 -> V_180 , & V_235 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_237 -> V_180 ) {
#ifdef F_129
case V_239 ... V_240 :
if ( ! F_35 ( V_241 ) ) {
V_7 = - V_242 ;
break;
}
V_235 . V_244 = V_6 -> V_3 . V_243 . V_243 [ V_237 -> V_180 - V_239 ] ;
break;
case V_245 :
if ( ! F_35 ( V_241 ) ) {
V_7 = - V_242 ;
break;
}
V_235 = F_135 ( V_237 -> V_180 , V_6 -> V_3 . V_243 . V_246 . V_247 [ 3 ] ) ;
break;
case V_248 :
V_235 = F_135 ( V_237 -> V_180 , V_6 -> V_3 . V_201 ) ;
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
T_3 V_252 ;
if ( V_6 -> V_253 )
F_137 ( V_254 , & V_6 -> V_255 , & V_252 ) ;
if ( V_6 -> V_231 ) {
if ( ! V_6 -> V_232 )
F_112 ( V_6 , V_10 ) ;
V_6 -> V_231 = 0 ;
} else if ( V_6 -> V_3 . V_256 ) {
V_197 * V_257 = V_10 -> V_258 . V_257 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_257 [ V_18 ] ) ;
V_6 -> V_3 . V_256 = 0 ;
} else if ( V_6 -> V_3 . V_259 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_260 . V_192 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_260 . args [ V_18 ] ) ;
V_6 -> V_3 . V_259 = 0 ;
#ifdef F_63
} else if ( V_6 -> V_3 . V_261 ) {
F_138 ( V_6 , V_10 -> V_262 . V_262 ) ;
V_6 -> V_3 . V_261 = 0 ;
#endif
}
V_7 = F_139 ( V_10 , V_6 ) ;
if ( V_6 -> V_253 )
F_137 ( V_254 , & V_252 , NULL ) ;
return V_7 ;
}
int F_140 ( struct V_1 * V_6 , struct V_263 * V_264 )
{
if ( V_264 -> V_264 == V_265 ) {
F_141 ( V_6 ) ;
return 0 ;
}
F_142 ( V_6 , V_264 ) ;
F_143 ( V_6 ) ;
return 0 ;
}
static int F_144 ( struct V_1 * V_6 ,
struct V_266 * V_267 )
{
int V_7 ;
if ( V_267 -> V_268 )
return - V_70 ;
switch ( V_267 -> V_267 ) {
case V_139 :
V_7 = 0 ;
V_6 -> V_3 . V_269 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_267 -> args [ 0 ] )
V_6 -> V_3 . V_270 |= V_271 ;
else
V_6 -> V_3 . V_270 &= ~ V_271 ;
break;
#ifdef F_63
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_272 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_142 : {
struct V_273 V_274 ;
void V_249 * V_275 = ( void V_249 * ) ( V_276 ) V_267 -> args [ 0 ] ;
V_7 = - V_251 ;
if ( F_133 ( & V_274 , V_275 , sizeof( V_274 ) ) )
break;
V_7 = F_145 ( V_6 , & V_274 ) ;
break;
}
#endif
#ifdef F_65
case V_145 : {
struct V_277 V_278 ;
struct V_279 * V_280 ;
V_7 = - V_281 ;
V_278 = F_146 ( V_267 -> args [ 0 ] ) ;
if ( ! V_278 . V_165 )
break;
V_7 = - V_101 ;
V_280 = F_147 ( V_278 . V_165 ) ;
if ( V_280 )
V_7 = F_148 ( V_280 , V_6 , V_267 -> args [ 1 ] ) ;
F_149 ( V_278 ) ;
break;
}
#endif
#ifdef F_66
case V_151 : {
struct V_277 V_278 ;
struct V_279 * V_280 ;
V_7 = - V_281 ;
V_278 = F_146 ( V_267 -> args [ 0 ] ) ;
if ( ! V_278 . V_165 )
break;
V_7 = - V_101 ;
V_280 = F_147 ( V_278 . V_165 ) ;
if ( V_280 )
V_7 = F_150 ( V_280 , V_6 , V_267 -> args [ 1 ] ) ;
F_149 ( V_278 ) ;
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
struct V_282 * V_283 )
{
return - V_70 ;
}
int F_152 ( struct V_1 * V_6 ,
struct V_282 * V_283 )
{
return - V_70 ;
}
long F_153 ( struct V_165 * V_166 ,
unsigned int V_167 , unsigned long V_168 )
{
struct V_1 * V_6 = V_166 -> V_284 ;
void V_249 * V_285 = ( void V_249 * ) V_168 ;
long V_7 ;
switch ( V_167 ) {
case V_286 : {
struct V_263 V_264 ;
V_7 = - V_251 ;
if ( F_133 ( & V_264 , V_285 , sizeof( V_264 ) ) )
goto V_63;
V_7 = F_140 ( V_6 , & V_264 ) ;
goto V_63;
}
case V_287 :
{
struct V_266 V_267 ;
V_7 = - V_251 ;
if ( F_133 ( & V_267 , V_285 , sizeof( V_267 ) ) )
goto V_63;
V_7 = F_144 ( V_6 , & V_267 ) ;
break;
}
case V_288 :
case V_289 :
{
struct V_236 V_237 ;
V_7 = - V_251 ;
if ( F_133 ( & V_237 , V_285 , sizeof( V_237 ) ) )
goto V_63;
if ( V_167 == V_288 )
V_7 = F_132 ( V_6 , & V_237 ) ;
else
V_7 = F_126 ( V_6 , & V_237 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_290 : {
struct V_291 V_292 ;
V_7 = - V_251 ;
if ( F_133 ( & V_292 , V_285 , sizeof( V_292 ) ) )
goto V_63;
V_7 = F_154 ( V_6 , & V_292 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_155 ( struct V_1 * V_6 , struct V_293 * V_294 )
{
return V_295 ;
}
static int F_156 ( struct V_296 * V_297 )
{
T_2 V_298 = 0x60000000 ;
#ifdef F_34
T_2 V_299 = 0x44000022 ;
V_297 -> V_300 [ 0 ] = F_157 ( V_299 ) ;
V_297 -> V_300 [ 1 ] = F_157 ( V_298 ) ;
V_297 -> V_300 [ 2 ] = F_157 ( V_298 ) ;
V_297 -> V_300 [ 3 ] = F_157 ( V_298 ) ;
#else
T_2 V_301 = 0x3c000000 ;
T_2 V_302 = 0x60000000 ;
T_2 V_303 = 0x44000002 ;
T_2 V_304 = 0xffff ;
V_297 -> V_300 [ 0 ] = F_157 ( V_301 | ( ( V_305 >> 16 ) & V_304 ) ) ;
V_297 -> V_300 [ 1 ] = F_157 ( V_302 | ( V_305 & V_304 ) ) ;
V_297 -> V_300 [ 2 ] = F_157 ( V_303 ) ;
V_297 -> V_300 [ 3 ] = F_157 ( V_298 ) ;
#endif
V_297 -> V_268 = V_306 ;
return 0 ;
}
int F_158 ( struct V_67 * V_67 , struct V_307 * V_308 ,
bool V_309 )
{
if ( ! F_159 ( V_67 ) )
return - V_242 ;
V_308 -> V_310 = F_160 ( V_67 , V_311 ,
V_308 -> V_264 , V_308 -> V_312 ,
V_309 ) ;
return 0 ;
}
static int F_161 ( struct V_67 * V_67 ,
struct V_266 * V_267 )
{
int V_7 ;
if ( V_267 -> V_268 )
return - V_70 ;
switch ( V_267 -> V_267 ) {
#ifdef F_162
case V_150 : {
unsigned long V_300 = V_267 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_300 > V_313 || ( V_300 & 3 ) ||
V_267 -> args [ 1 ] > 1 )
break;
if ( ! F_163 ( V_67 , V_300 ) )
break;
if ( V_267 -> args [ 1 ] )
F_164 ( V_300 / 4 , V_67 -> V_3 . V_314 ) ;
else
F_30 ( V_300 / 4 , V_67 -> V_3 . V_314 ) ;
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
long F_165 ( struct V_165 * V_166 ,
unsigned int V_167 , unsigned long V_168 )
{
struct V_67 * V_67 T_1 = V_166 -> V_284 ;
void V_249 * V_285 = ( void V_249 * ) V_168 ;
long V_7 ;
switch ( V_167 ) {
case V_315 : {
struct V_296 V_297 ;
memset ( & V_297 , 0 , sizeof( V_297 ) ) ;
V_7 = F_156 ( & V_297 ) ;
if ( F_131 ( V_285 , & V_297 , sizeof( V_297 ) ) ) {
V_7 = - V_251 ;
goto V_63;
}
break;
}
case V_287 :
{
struct V_266 V_267 ;
V_7 = - V_251 ;
if ( F_133 ( & V_267 , V_285 , sizeof( V_267 ) ) )
goto V_63;
V_7 = F_161 ( V_67 , & V_267 ) ;
break;
}
#ifdef V_38
case V_316 : {
struct V_317 V_318 ;
V_7 = - V_251 ;
if ( F_133 ( & V_318 , V_285 , sizeof( V_318 ) ) )
goto V_63;
V_7 = F_166 ( V_67 , & V_318 ) ;
goto V_63;
}
case V_319 : {
struct V_320 V_321 ;
struct V_67 * V_67 = V_166 -> V_284 ;
memset ( & V_321 , 0 , sizeof( V_321 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_322 ( V_67 , & V_321 ) ;
if ( V_7 >= 0 && F_131 ( V_285 , & V_321 , sizeof( V_321 ) ) )
V_7 = - V_251 ;
break;
}
case V_323 : {
struct V_67 * V_67 = V_166 -> V_284 ;
V_7 = F_167 ( V_67 , V_285 ) ;
break;
}
default: {
struct V_67 * V_67 = V_166 -> V_284 ;
V_7 = V_67 -> V_3 . V_112 -> V_324 ( V_166 , V_167 , V_168 ) ;
}
#else
default:
V_7 = - V_325 ;
#endif
}
V_63:
return V_7 ;
}
long F_168 ( void )
{
long V_326 ;
do {
V_326 = F_169 ( V_327 , V_328 ) ;
if ( V_326 >= V_329 ) {
F_170 ( L_4 , V_84 ) ;
return - V_330 ;
}
} while ( F_171 ( V_326 , V_327 ) );
return V_326 ;
}
void F_172 ( long V_326 )
{
F_164 ( V_326 , V_327 ) ;
}
void F_173 ( long V_326 )
{
F_30 ( V_326 , V_327 ) ;
}
void F_174 ( unsigned long V_331 )
{
V_329 = F_175 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_327 , 0 , sizeof( V_327 ) ) ;
}
int F_176 ( void * V_332 )
{
return 0 ;
}
