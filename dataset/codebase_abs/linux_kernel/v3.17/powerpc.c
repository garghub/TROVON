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
F_38 ( V_6 , false , & V_82 ) ;
F_39 ( L_1 , V_83 , V_82 ) ;
V_7 = V_84 ;
break;
}
default:
F_4 ( 1 ) ;
V_7 = V_77 ;
}
return V_7 ;
}
int F_40 ( struct V_1 * V_6 , V_48 * V_85 , int V_86 , void * V_87 ,
bool V_88 )
{
V_48 V_89 = V_6 -> V_3 . V_46 & V_90 & V_51 ;
struct V_91 V_92 ;
int V_7 ;
V_6 -> V_93 . V_94 ++ ;
V_7 = F_41 ( V_6 , * V_85 , V_88 ? V_95 : V_96 ,
V_97 , & V_92 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_85 = V_92 . V_98 ;
if ( ! V_92 . V_99 )
return - V_100 ;
if ( F_42 ( V_6 ) && V_89 &&
( ( V_92 . V_98 & V_90 & V_51 ) == V_89 ) &&
! ( F_23 ( V_6 ) & V_101 ) ) {
void * V_102 = V_6 -> V_3 . V_17 ;
V_102 += V_92 . V_85 & 0xfff ;
memcpy ( V_102 , V_87 , V_86 ) ;
return V_74 ;
}
if ( F_43 ( V_6 -> V_67 , V_92 . V_98 , V_87 , V_86 ) )
return V_78 ;
return V_74 ;
}
int F_44 ( struct V_1 * V_6 , V_48 * V_85 , int V_86 , void * V_87 ,
bool V_88 )
{
V_48 V_89 = V_6 -> V_3 . V_46 & V_90 & V_51 ;
struct V_91 V_92 ;
int V_103 ;
V_6 -> V_93 . V_104 ++ ;
V_103 = F_41 ( V_6 , * V_85 , V_88 ? V_95 : V_96 ,
V_105 , & V_92 ) ;
if ( V_103 )
return V_103 ;
* V_85 = V_92 . V_98 ;
if ( ! V_92 . V_106 )
return - V_100 ;
if ( ! V_88 && ! V_92 . V_107 )
return - V_108 ;
if ( F_42 ( V_6 ) && V_89 &&
( ( V_92 . V_98 & V_90 & V_51 ) == V_89 ) &&
! ( F_23 ( V_6 ) & V_101 ) ) {
void * V_102 = V_6 -> V_3 . V_17 ;
V_102 += V_92 . V_85 & 0xfff ;
memcpy ( V_87 , V_102 , V_86 ) ;
return V_74 ;
}
if ( F_45 ( V_6 -> V_67 , V_92 . V_98 , V_87 , V_86 ) )
return V_78 ;
return V_74 ;
}
int F_46 ( void * V_109 )
{
return 0 ;
}
void F_47 ( void * V_109 )
{
}
int F_48 ( void )
{
return 0 ;
}
void F_49 ( void )
{
}
void F_50 ( void * V_110 )
{
* ( int * ) V_110 = F_51 () ;
}
int F_52 ( struct V_67 * V_67 , unsigned long type )
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
if ( V_112 -> V_118 && ! F_53 ( V_112 -> V_118 ) )
return - V_119 ;
V_67 -> V_3 . V_112 = V_112 ;
return F_54 ( V_67 ) ;
V_115:
return - V_70 ;
}
void F_55 ( struct V_67 * V_67 )
{
unsigned int V_18 ;
struct V_1 * V_6 ;
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
void F_64 ( struct V_67 * V_67 )
{
}
int F_65 ( struct V_67 * V_67 , long V_123 )
{
int V_7 ;
int V_124 = V_113 ? 1 : 0 ;
if ( V_67 ) {
V_124 = F_33 ( V_67 ) ;
}
switch ( V_123 ) {
#ifdef F_66
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
#ifdef F_67
case V_143 :
V_7 = V_144 ;
break;
#endif
#ifdef F_68
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
#ifdef F_69
case V_151 :
#endif
V_7 = 1 ;
break;
#endif
#ifdef F_70
case V_152 :
if ( V_124 )
V_7 = V_153 ;
else
V_7 = 0 ;
break;
case V_154 :
V_7 = V_124 ;
if ( V_7 && F_35 ( V_155 ) )
V_7 = 2 ;
break;
#endif
case V_156 :
#ifdef F_70
if ( V_124 )
V_7 = F_35 ( V_157 ) ? 1 : 0 ;
else
V_7 = 0 ;
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
V_7 = F_71 () ;
else
V_7 = F_72 () ;
break;
case V_161 :
V_7 = V_162 ;
break;
#ifdef V_38
case V_163 :
V_7 = 1 ;
break;
#endif
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_73 ( struct V_164 * V_165 ,
unsigned int V_166 , unsigned long V_167 )
{
return - V_70 ;
}
void F_74 ( struct V_67 * V_67 , struct V_168 * free ,
struct V_168 * V_169 )
{
F_75 ( V_67 , free , V_169 ) ;
}
int F_76 ( struct V_67 * V_67 , struct V_168 * V_170 ,
unsigned long V_171 )
{
return F_77 ( V_67 , V_170 , V_171 ) ;
}
void F_78 ( struct V_67 * V_67 )
{
}
int F_79 ( struct V_67 * V_67 ,
struct V_168 * V_172 ,
struct V_173 * V_174 ,
enum V_175 V_176 )
{
return F_80 ( V_67 , V_172 , V_174 ) ;
}
void F_81 ( struct V_67 * V_67 ,
struct V_173 * V_174 ,
const struct V_168 * V_177 ,
enum V_175 V_176 )
{
F_82 ( V_67 , V_174 , V_177 ) ;
}
void F_83 ( struct V_67 * V_67 )
{
}
void F_84 ( struct V_67 * V_67 ,
struct V_168 * V_170 )
{
F_85 ( V_67 , V_170 ) ;
}
struct V_1 * F_86 ( struct V_67 * V_67 , unsigned int V_178 )
{
struct V_1 * V_6 ;
V_6 = F_87 ( V_67 , V_178 ) ;
if ( ! F_88 ( V_6 ) ) {
V_6 -> V_3 . V_179 = & V_6 -> V_180 ;
F_89 ( V_6 , V_178 ) ;
}
return V_6 ;
}
int F_90 ( struct V_1 * V_6 )
{
return 0 ;
}
void F_57 ( struct V_1 * V_6 )
{
F_91 ( & V_6 -> V_3 . V_181 ) ;
F_92 ( & V_6 -> V_3 . V_182 ) ;
F_93 ( V_6 ) ;
switch ( V_6 -> V_3 . V_183 ) {
case V_184 :
F_94 ( V_6 -> V_3 . V_185 , V_6 ) ;
break;
case V_186 :
F_95 ( V_6 ) ;
break;
}
F_96 ( V_6 ) ;
}
void F_97 ( struct V_1 * V_6 )
{
F_57 ( V_6 ) ;
}
int F_98 ( struct V_1 * V_6 )
{
return F_99 ( V_6 ) ;
}
enum V_187 F_100 ( struct V_188 * V_189 )
{
struct V_1 * V_6 ;
V_6 = F_101 ( V_189 , struct V_1 , V_3 . V_181 ) ;
F_102 ( & V_6 -> V_3 . V_182 ) ;
return V_190 ;
}
int F_103 ( struct V_1 * V_6 )
{
int V_191 ;
F_104 ( & V_6 -> V_3 . V_181 , V_192 , V_193 ) ;
F_105 ( & V_6 -> V_3 . V_182 , V_194 , ( V_48 ) V_6 ) ;
V_6 -> V_3 . V_181 . V_195 = F_100 ;
V_6 -> V_3 . V_196 = ~ ( V_197 ) 0 ;
#ifdef F_106
F_107 ( & V_6 -> V_3 . V_198 ) ;
#endif
V_191 = F_108 ( V_6 ) ;
return V_191 ;
}
void F_109 ( struct V_1 * V_6 )
{
F_110 ( V_6 ) ;
F_111 ( V_6 ) ;
}
void F_112 ( struct V_1 * V_6 , int V_199 )
{
#ifdef F_66
F_113 ( V_200 , V_6 -> V_3 . V_201 ) ;
#endif
F_114 ( V_6 , V_199 ) ;
}
void F_115 ( struct V_1 * V_6 )
{
F_116 ( V_6 ) ;
#ifdef F_66
V_6 -> V_3 . V_201 = F_117 ( V_200 ) ;
#endif
}
static void F_118 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_197 V_202 ( V_203 ) ;
if ( V_10 -> V_204 . V_205 > sizeof( V_203 ) ) {
F_119 ( V_206 L_2 , V_10 -> V_204 . V_205 ) ;
return;
}
if ( V_6 -> V_3 . V_207 ) {
switch ( V_10 -> V_204 . V_205 ) {
case 8 : V_203 = * ( V_197 * ) V_10 -> V_204 . V_88 ; break;
case 4 : V_203 = * ( T_2 * ) V_10 -> V_204 . V_88 ; break;
case 2 : V_203 = * ( V_208 * ) V_10 -> V_204 . V_88 ; break;
case 1 : V_203 = * ( V_209 * ) V_10 -> V_204 . V_88 ; break;
}
} else {
switch ( V_10 -> V_204 . V_205 ) {
case 4 : V_203 = F_120 ( ( T_2 * ) V_10 -> V_204 . V_88 ) ; break;
case 2 : V_203 = F_121 ( ( V_208 * ) V_10 -> V_204 . V_88 ) ; break;
case 1 : V_203 = * ( V_209 * ) V_10 -> V_204 . V_88 ; break;
}
}
if ( V_6 -> V_3 . V_210 ) {
switch ( V_10 -> V_204 . V_205 ) {
#ifdef F_122
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
F_123 ( V_6 , V_6 -> V_3 . V_215 & V_219 ) = V_203 ;
break;
#ifdef V_56
case V_220 :
V_6 -> V_3 . V_221 [ V_6 -> V_3 . V_215 & V_219 ] = V_203 ;
break;
case V_222 :
F_123 ( V_6 , V_6 -> V_3 . V_215 & V_219 ) = V_203 ;
V_6 -> V_3 . V_221 [ V_6 -> V_3 . V_215 & V_219 ] = V_203 ;
break;
#endif
default:
F_124 () ;
}
}
int F_125 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_223 , unsigned int V_224 ,
int V_225 )
{
int V_226 , V_191 ;
int V_227 ;
if ( F_126 ( V_6 ) ) {
V_227 = ! V_225 ;
} else {
V_227 = V_225 ;
}
if ( V_224 > sizeof( V_10 -> V_204 . V_88 ) ) {
F_119 ( V_206 L_3 , V_83 ,
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
V_226 = F_127 ( & V_6 -> V_67 -> V_233 ) ;
V_191 = F_128 ( V_6 -> V_67 , V_234 , V_10 -> V_204 . V_228 ,
V_224 , & V_10 -> V_204 . V_88 ) ;
F_129 ( & V_6 -> V_67 -> V_233 , V_226 ) ;
if ( ! V_191 ) {
F_118 ( V_6 , V_10 ) ;
V_6 -> V_231 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_130 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_223 , unsigned int V_224 ,
int V_225 )
{
int V_7 ;
V_6 -> V_3 . V_210 = 1 ;
V_7 = F_125 ( V_10 , V_6 , V_223 , V_224 , V_225 ) ;
return V_7 ;
}
int F_131 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_197 V_235 , unsigned int V_224 , int V_225 )
{
void * V_88 = V_10 -> V_204 . V_88 ;
int V_226 , V_191 ;
int V_227 ;
if ( F_126 ( V_6 ) ) {
V_227 = ! V_225 ;
} else {
V_227 = V_225 ;
}
if ( V_224 > sizeof( V_10 -> V_204 . V_88 ) ) {
F_119 ( V_206 L_3 , V_83 ,
V_10 -> V_204 . V_205 ) ;
}
V_10 -> V_204 . V_228 = V_6 -> V_3 . V_229 ;
V_10 -> V_204 . V_205 = V_224 ;
V_10 -> V_204 . V_230 = 1 ;
V_6 -> V_231 = 1 ;
V_6 -> V_232 = 1 ;
if ( V_227 ) {
switch ( V_224 ) {
case 8 : * ( V_197 * ) V_88 = V_235 ; break;
case 4 : * ( T_2 * ) V_88 = V_235 ; break;
case 2 : * ( V_208 * ) V_88 = V_235 ; break;
case 1 : * ( V_209 * ) V_88 = V_235 ; break;
}
} else {
switch ( V_224 ) {
case 4 : F_132 ( V_88 , V_235 ) ; break;
case 2 : F_133 ( V_88 , V_235 ) ; break;
case 1 : * ( V_209 * ) V_88 = V_235 ; break;
}
}
V_226 = F_127 ( & V_6 -> V_67 -> V_233 ) ;
V_191 = F_134 ( V_6 -> V_67 , V_234 , V_10 -> V_204 . V_228 ,
V_224 , & V_10 -> V_204 . V_88 ) ;
F_129 ( & V_6 -> V_67 -> V_233 , V_226 ) ;
if ( ! V_191 ) {
V_6 -> V_231 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_135 ( struct V_1 * V_6 , struct V_71 * V_10 )
{
int V_7 ;
T_3 V_236 ;
if ( V_6 -> V_237 )
F_136 ( V_238 , & V_6 -> V_239 , & V_236 ) ;
if ( V_6 -> V_231 ) {
if ( ! V_6 -> V_232 )
F_118 ( V_6 , V_10 ) ;
V_6 -> V_231 = 0 ;
} else if ( V_6 -> V_3 . V_240 ) {
V_197 * V_241 = V_10 -> V_242 . V_241 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_241 [ V_18 ] ) ;
V_6 -> V_3 . V_240 = 0 ;
} else if ( V_6 -> V_3 . V_243 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_244 . V_191 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_244 . args [ V_18 ] ) ;
V_6 -> V_3 . V_243 = 0 ;
#ifdef F_66
} else if ( V_6 -> V_3 . V_245 ) {
F_137 ( V_6 , V_10 -> V_246 . V_246 ) ;
V_6 -> V_3 . V_245 = 0 ;
#endif
}
V_7 = F_138 ( V_10 , V_6 ) ;
if ( V_6 -> V_237 )
F_136 ( V_238 , & V_236 , NULL ) ;
return V_7 ;
}
int F_139 ( struct V_1 * V_6 , struct V_247 * V_248 )
{
if ( V_248 -> V_248 == V_249 ) {
F_140 ( V_6 ) ;
return 0 ;
}
F_141 ( V_6 , V_248 ) ;
F_142 ( V_6 ) ;
return 0 ;
}
static int F_143 ( struct V_1 * V_6 ,
struct V_250 * V_251 )
{
int V_7 ;
if ( V_251 -> V_252 )
return - V_70 ;
switch ( V_251 -> V_251 ) {
case V_139 :
V_7 = 0 ;
V_6 -> V_3 . V_253 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_251 -> args [ 0 ] )
V_6 -> V_3 . V_254 |= V_255 ;
else
V_6 -> V_3 . V_254 &= ~ V_255 ;
break;
#ifdef F_66
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_256 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_142 : {
struct V_257 V_258 ;
void T_4 * V_259 = ( void T_4 * ) ( V_260 ) V_251 -> args [ 0 ] ;
V_7 = - V_261 ;
if ( F_144 ( & V_258 , V_259 , sizeof( V_258 ) ) )
break;
V_7 = F_145 ( V_6 , & V_258 ) ;
break;
}
#endif
#ifdef F_68
case V_145 : {
struct V_262 V_263 ;
struct V_264 * V_265 ;
V_7 = - V_266 ;
V_263 = F_146 ( V_251 -> args [ 0 ] ) ;
if ( ! V_263 . V_164 )
break;
V_7 = - V_100 ;
V_265 = F_147 ( V_263 . V_164 ) ;
if ( V_265 )
V_7 = F_148 ( V_265 , V_6 , V_251 -> args [ 1 ] ) ;
F_149 ( V_263 ) ;
break;
}
#endif
#ifdef F_69
case V_151 : {
struct V_262 V_263 ;
struct V_264 * V_265 ;
V_7 = - V_266 ;
V_263 = F_146 ( V_251 -> args [ 0 ] ) ;
if ( ! V_263 . V_164 )
break;
V_7 = - V_100 ;
V_265 = F_147 ( V_263 . V_164 ) ;
if ( V_265 )
V_7 = F_150 ( V_265 , V_6 , V_251 -> args [ 1 ] ) ;
F_149 ( V_263 ) ;
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
struct V_267 * V_268 )
{
return - V_70 ;
}
int F_152 ( struct V_1 * V_6 ,
struct V_267 * V_268 )
{
return - V_70 ;
}
long F_153 ( struct V_164 * V_165 ,
unsigned int V_166 , unsigned long V_167 )
{
struct V_1 * V_6 = V_165 -> V_269 ;
void T_4 * V_270 = ( void T_4 * ) V_167 ;
long V_7 ;
switch ( V_166 ) {
case V_271 : {
struct V_247 V_248 ;
V_7 = - V_261 ;
if ( F_144 ( & V_248 , V_270 , sizeof( V_248 ) ) )
goto V_63;
V_7 = F_139 ( V_6 , & V_248 ) ;
goto V_63;
}
case V_272 :
{
struct V_250 V_251 ;
V_7 = - V_261 ;
if ( F_144 ( & V_251 , V_270 , sizeof( V_251 ) ) )
goto V_63;
V_7 = F_143 ( V_6 , & V_251 ) ;
break;
}
case V_273 :
case V_274 :
{
struct V_275 V_276 ;
V_7 = - V_261 ;
if ( F_144 ( & V_276 , V_270 , sizeof( V_276 ) ) )
goto V_63;
if ( V_166 == V_273 )
V_7 = F_154 ( V_6 , & V_276 ) ;
else
V_7 = F_155 ( V_6 , & V_276 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_277 : {
struct V_278 V_279 ;
V_7 = - V_261 ;
if ( F_144 ( & V_279 , V_270 , sizeof( V_279 ) ) )
goto V_63;
V_7 = F_156 ( V_6 , & V_279 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_157 ( struct V_1 * V_6 , struct V_280 * V_281 )
{
return V_282 ;
}
static int F_158 ( struct V_283 * V_284 )
{
T_2 V_285 = 0x60000000 ;
#ifdef F_34
T_2 V_286 = 0x44000022 ;
V_284 -> V_287 [ 0 ] = F_159 ( V_286 ) ;
V_284 -> V_287 [ 1 ] = F_159 ( V_285 ) ;
V_284 -> V_287 [ 2 ] = F_159 ( V_285 ) ;
V_284 -> V_287 [ 3 ] = F_159 ( V_285 ) ;
#else
T_2 V_288 = 0x3c000000 ;
T_2 V_289 = 0x60000000 ;
T_2 V_290 = 0x44000002 ;
T_2 V_291 = 0xffff ;
V_284 -> V_287 [ 0 ] = F_159 ( V_288 | ( ( V_292 >> 16 ) & V_291 ) ) ;
V_284 -> V_287 [ 1 ] = F_159 ( V_289 | ( V_292 & V_291 ) ) ;
V_284 -> V_287 [ 2 ] = F_159 ( V_290 ) ;
V_284 -> V_287 [ 3 ] = F_159 ( V_285 ) ;
#endif
V_284 -> V_252 = V_293 ;
return 0 ;
}
int F_160 ( struct V_67 * V_67 , struct V_294 * V_295 ,
bool V_296 )
{
if ( ! F_161 ( V_67 ) )
return - V_297 ;
V_295 -> V_298 = F_162 ( V_67 , V_299 ,
V_295 -> V_248 , V_295 -> V_300 ,
V_296 ) ;
return 0 ;
}
static int F_163 ( struct V_67 * V_67 ,
struct V_250 * V_251 )
{
int V_7 ;
if ( V_251 -> V_252 )
return - V_70 ;
switch ( V_251 -> V_251 ) {
#ifdef F_164
case V_150 : {
unsigned long V_287 = V_251 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_287 > V_301 || ( V_287 & 3 ) ||
V_251 -> args [ 1 ] > 1 )
break;
if ( ! F_165 ( V_67 , V_287 ) )
break;
if ( V_251 -> args [ 1 ] )
F_166 ( V_287 / 4 , V_67 -> V_3 . V_302 ) ;
else
F_30 ( V_287 / 4 , V_67 -> V_3 . V_302 ) ;
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
long F_167 ( struct V_164 * V_165 ,
unsigned int V_166 , unsigned long V_167 )
{
struct V_67 * V_67 T_1 = V_165 -> V_269 ;
void T_4 * V_270 = ( void T_4 * ) V_167 ;
long V_7 ;
switch ( V_166 ) {
case V_303 : {
struct V_283 V_284 ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_7 = F_158 ( & V_284 ) ;
if ( F_168 ( V_270 , & V_284 , sizeof( V_284 ) ) ) {
V_7 = - V_261 ;
goto V_63;
}
break;
}
case V_272 :
{
struct V_250 V_251 ;
V_7 = - V_261 ;
if ( F_144 ( & V_251 , V_270 , sizeof( V_251 ) ) )
goto V_63;
V_7 = F_163 ( V_67 , & V_251 ) ;
break;
}
#ifdef V_38
case V_304 : {
struct V_305 V_306 ;
V_7 = - V_261 ;
if ( F_144 ( & V_306 , V_270 , sizeof( V_306 ) ) )
goto V_63;
V_7 = F_169 ( V_67 , & V_306 ) ;
goto V_63;
}
case V_307 : {
struct V_308 V_309 ;
struct V_67 * V_67 = V_165 -> V_269 ;
memset ( & V_309 , 0 , sizeof( V_309 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_310 ( V_67 , & V_309 ) ;
if ( V_7 >= 0 && F_168 ( V_270 , & V_309 , sizeof( V_309 ) ) )
V_7 = - V_261 ;
break;
}
case V_311 : {
struct V_67 * V_67 = V_165 -> V_269 ;
V_7 = F_170 ( V_67 , V_270 ) ;
break;
}
default: {
struct V_67 * V_67 = V_165 -> V_269 ;
V_7 = V_67 -> V_3 . V_112 -> V_312 ( V_165 , V_166 , V_167 ) ;
}
#else
default:
V_7 = - V_313 ;
#endif
}
V_63:
return V_7 ;
}
long F_171 ( void )
{
long V_314 ;
do {
V_314 = F_172 ( V_315 , V_316 ) ;
if ( V_314 >= V_317 ) {
F_173 ( L_4 , V_83 ) ;
return - V_318 ;
}
} while ( F_174 ( V_314 , V_315 ) );
return V_314 ;
}
void F_175 ( long V_314 )
{
F_166 ( V_314 , V_315 ) ;
}
void F_176 ( long V_314 )
{
F_30 ( V_314 , V_315 ) ;
}
void F_177 ( unsigned long V_319 )
{
V_317 = F_178 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_315 , 0 , sizeof( V_315 ) ) ;
}
int F_179 ( void * V_320 )
{
return 0 ;
}
void F_180 ( void )
{
}
