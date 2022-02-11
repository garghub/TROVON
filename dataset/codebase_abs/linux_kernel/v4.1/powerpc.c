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
struct V_172 * V_173 ,
enum V_174 V_175 )
{
return F_77 ( V_67 , V_171 , V_173 ) ;
}
void F_78 ( struct V_67 * V_67 ,
struct V_172 * V_173 ,
const struct V_167 * V_176 ,
enum V_174 V_175 )
{
F_79 ( V_67 , V_173 , V_176 ) ;
}
void F_80 ( struct V_67 * V_67 ,
struct V_167 * V_169 )
{
F_81 ( V_67 , V_169 ) ;
}
struct V_1 * F_82 ( struct V_67 * V_67 , unsigned int V_177 )
{
struct V_1 * V_6 ;
V_6 = F_83 ( V_67 , V_177 ) ;
if ( ! F_84 ( V_6 ) ) {
V_6 -> V_3 . V_178 = & V_6 -> V_179 ;
F_85 ( V_6 , V_177 ) ;
}
return V_6 ;
}
void F_86 ( struct V_1 * V_6 )
{
}
void F_55 ( struct V_1 * V_6 )
{
F_87 ( & V_6 -> V_3 . V_180 ) ;
F_88 ( V_6 ) ;
switch ( V_6 -> V_3 . V_181 ) {
case V_182 :
F_89 ( V_6 -> V_3 . V_183 , V_6 ) ;
break;
case V_184 :
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
enum V_185 F_95 ( struct V_186 * V_187 )
{
struct V_1 * V_6 ;
V_6 = F_96 ( V_187 , struct V_1 , V_3 . V_180 ) ;
F_97 ( V_6 ) ;
return V_188 ;
}
int F_98 ( struct V_1 * V_6 )
{
int V_189 ;
F_99 ( & V_6 -> V_3 . V_180 , V_190 , V_191 ) ;
V_6 -> V_3 . V_180 . V_192 = F_95 ;
V_6 -> V_3 . V_193 = ~ ( V_194 ) 0 ;
#ifdef F_100
F_101 ( & V_6 -> V_3 . V_195 ) ;
#endif
V_189 = F_102 ( V_6 ) ;
return V_189 ;
}
void F_103 ( struct V_1 * V_6 )
{
F_104 ( V_6 ) ;
F_105 ( V_6 ) ;
}
void F_106 ( struct V_1 * V_6 , int V_196 )
{
#ifdef F_63
F_107 ( V_197 , V_6 -> V_3 . V_198 ) ;
#endif
F_108 ( V_6 , V_196 ) ;
}
void F_109 ( struct V_1 * V_6 )
{
F_110 ( V_6 ) ;
#ifdef F_63
V_6 -> V_3 . V_198 = F_111 ( V_197 ) ;
#endif
}
static void F_112 ( struct V_1 * V_6 ,
struct V_71 * V_10 )
{
V_194 V_199 ( V_200 ) ;
if ( V_10 -> V_201 . V_202 > sizeof( V_200 ) ) {
F_113 ( V_203 L_2 , V_10 -> V_201 . V_202 ) ;
return;
}
if ( ! V_6 -> V_3 . V_204 ) {
switch ( V_10 -> V_201 . V_202 ) {
case 8 : V_200 = * ( V_194 * ) V_10 -> V_201 . V_89 ; break;
case 4 : V_200 = * ( T_2 * ) V_10 -> V_201 . V_89 ; break;
case 2 : V_200 = * ( V_205 * ) V_10 -> V_201 . V_89 ; break;
case 1 : V_200 = * ( V_206 * ) V_10 -> V_201 . V_89 ; break;
}
} else {
switch ( V_10 -> V_201 . V_202 ) {
case 8 : V_200 = F_18 ( * ( V_194 * ) V_10 -> V_201 . V_89 ) ; break;
case 4 : V_200 = F_19 ( * ( T_2 * ) V_10 -> V_201 . V_89 ) ; break;
case 2 : V_200 = F_114 ( * ( V_205 * ) V_10 -> V_201 . V_89 ) ; break;
case 1 : V_200 = * ( V_206 * ) V_10 -> V_201 . V_89 ; break;
}
}
if ( V_6 -> V_3 . V_207 ) {
switch ( V_10 -> V_201 . V_202 ) {
#ifdef F_115
case 4 :
V_200 = ( V_208 ) ( V_209 ) V_200 ;
break;
#endif
case 2 :
V_200 = ( V_208 ) ( V_210 ) V_200 ;
break;
case 1 :
V_200 = ( V_208 ) ( V_211 ) V_200 ;
break;
}
}
F_31 ( V_6 , V_6 -> V_3 . V_212 , V_200 ) ;
switch ( V_6 -> V_3 . V_212 & V_213 ) {
case V_214 :
F_31 ( V_6 , V_6 -> V_3 . V_212 , V_200 ) ;
break;
case V_215 :
F_116 ( V_6 , V_6 -> V_3 . V_212 & V_216 ) = V_200 ;
break;
#ifdef V_56
case V_217 :
V_6 -> V_3 . V_218 [ V_6 -> V_3 . V_212 & V_216 ] = V_200 ;
break;
case V_219 :
F_116 ( V_6 , V_6 -> V_3 . V_212 & V_216 ) = V_200 ;
V_6 -> V_3 . V_218 [ V_6 -> V_3 . V_212 & V_216 ] = V_200 ;
break;
#endif
default:
F_117 () ;
}
}
int F_118 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_220 , unsigned int V_221 ,
int V_222 )
{
int V_223 , V_189 ;
bool V_224 ;
if ( F_119 ( V_6 ) ) {
V_224 = V_222 ;
} else {
V_224 = ! V_222 ;
}
if ( V_221 > sizeof( V_10 -> V_201 . V_89 ) ) {
F_113 ( V_203 L_3 , V_84 ,
V_10 -> V_201 . V_202 ) ;
}
V_10 -> V_201 . V_225 = V_6 -> V_3 . V_226 ;
V_10 -> V_201 . V_202 = V_221 ;
V_10 -> V_201 . V_227 = 0 ;
V_6 -> V_3 . V_212 = V_220 ;
V_6 -> V_3 . V_204 = V_224 ;
V_6 -> V_228 = 1 ;
V_6 -> V_229 = 0 ;
V_6 -> V_3 . V_207 = 0 ;
V_223 = F_120 ( & V_6 -> V_67 -> V_230 ) ;
V_189 = F_121 ( V_6 , V_231 , V_10 -> V_201 . V_225 ,
V_221 , & V_10 -> V_201 . V_89 ) ;
F_122 ( & V_6 -> V_67 -> V_230 , V_223 ) ;
if ( ! V_189 ) {
F_112 ( V_6 , V_10 ) ;
V_6 -> V_228 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_123 ( struct V_71 * V_10 , struct V_1 * V_6 ,
unsigned int V_220 , unsigned int V_221 ,
int V_222 )
{
int V_7 ;
V_6 -> V_3 . V_207 = 1 ;
V_7 = F_118 ( V_10 , V_6 , V_220 , V_221 , V_222 ) ;
return V_7 ;
}
int F_124 ( struct V_71 * V_10 , struct V_1 * V_6 ,
V_194 V_232 , unsigned int V_221 , int V_222 )
{
void * V_89 = V_10 -> V_201 . V_89 ;
int V_223 , V_189 ;
bool V_224 ;
if ( F_119 ( V_6 ) ) {
V_224 = V_222 ;
} else {
V_224 = ! V_222 ;
}
if ( V_221 > sizeof( V_10 -> V_201 . V_89 ) ) {
F_113 ( V_203 L_3 , V_84 ,
V_10 -> V_201 . V_202 ) ;
}
V_10 -> V_201 . V_225 = V_6 -> V_3 . V_226 ;
V_10 -> V_201 . V_202 = V_221 ;
V_10 -> V_201 . V_227 = 1 ;
V_6 -> V_228 = 1 ;
V_6 -> V_229 = 1 ;
if ( ! V_224 ) {
switch ( V_221 ) {
case 8 : * ( V_194 * ) V_89 = V_232 ; break;
case 4 : * ( T_2 * ) V_89 = V_232 ; break;
case 2 : * ( V_205 * ) V_89 = V_232 ; break;
case 1 : * ( V_206 * ) V_89 = V_232 ; break;
}
} else {
switch ( V_221 ) {
case 8 : * ( V_194 * ) V_89 = F_18 ( V_232 ) ; break;
case 4 : * ( T_2 * ) V_89 = F_19 ( V_232 ) ; break;
case 2 : * ( V_205 * ) V_89 = F_114 ( V_232 ) ; break;
case 1 : * ( V_206 * ) V_89 = V_232 ; break;
}
}
V_223 = F_120 ( & V_6 -> V_67 -> V_230 ) ;
V_189 = F_125 ( V_6 , V_231 , V_10 -> V_201 . V_225 ,
V_221 , & V_10 -> V_201 . V_89 ) ;
F_122 ( & V_6 -> V_67 -> V_230 , V_223 ) ;
if ( ! V_189 ) {
V_6 -> V_228 = 0 ;
return V_74 ;
}
return V_78 ;
}
int F_126 ( struct V_1 * V_6 , struct V_233 * V_234 )
{
int V_7 = 0 ;
union V_235 V_232 ;
int V_87 ;
V_87 = F_127 ( V_234 -> V_177 ) ;
if ( V_87 > sizeof( V_232 ) )
return - V_70 ;
V_7 = F_128 ( V_6 , V_234 -> V_177 , & V_232 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_234 -> V_177 ) {
#ifdef F_129
case V_236 ... V_237 :
if ( ! F_35 ( V_238 ) ) {
V_7 = - V_239 ;
break;
}
V_6 -> V_3 . V_240 . V_240 [ V_234 -> V_177 - V_236 ] = V_232 . V_241 ;
break;
case V_242 :
if ( ! F_35 ( V_238 ) ) {
V_7 = - V_239 ;
break;
}
V_6 -> V_3 . V_240 . V_243 . V_244 [ 3 ] = F_130 ( V_234 -> V_177 , V_232 ) ;
break;
case V_245 :
if ( ! F_35 ( V_238 ) ) {
V_7 = - V_239 ;
break;
}
V_6 -> V_3 . V_198 = F_130 ( V_234 -> V_177 , V_232 ) ;
break;
#endif
default:
V_7 = - V_70 ;
break;
}
}
if ( V_7 )
return V_7 ;
if ( F_131 ( ( char V_246 * ) ( unsigned long ) V_234 -> V_247 , & V_232 , V_87 ) )
V_7 = - V_248 ;
return V_7 ;
}
int F_132 ( struct V_1 * V_6 , struct V_233 * V_234 )
{
int V_7 ;
union V_235 V_232 ;
int V_87 ;
V_87 = F_127 ( V_234 -> V_177 ) ;
if ( V_87 > sizeof( V_232 ) )
return - V_70 ;
if ( F_133 ( & V_232 , ( char V_246 * ) ( unsigned long ) V_234 -> V_247 , V_87 ) )
return - V_248 ;
V_7 = F_134 ( V_6 , V_234 -> V_177 , & V_232 ) ;
if ( V_7 == - V_70 ) {
V_7 = 0 ;
switch ( V_234 -> V_177 ) {
#ifdef F_129
case V_236 ... V_237 :
if ( ! F_35 ( V_238 ) ) {
V_7 = - V_239 ;
break;
}
V_232 . V_241 = V_6 -> V_3 . V_240 . V_240 [ V_234 -> V_177 - V_236 ] ;
break;
case V_242 :
if ( ! F_35 ( V_238 ) ) {
V_7 = - V_239 ;
break;
}
V_232 = F_135 ( V_234 -> V_177 , V_6 -> V_3 . V_240 . V_243 . V_244 [ 3 ] ) ;
break;
case V_245 :
V_232 = F_135 ( V_234 -> V_177 , V_6 -> V_3 . V_198 ) ;
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
T_3 V_249 ;
if ( V_6 -> V_250 )
F_137 ( V_251 , & V_6 -> V_252 , & V_249 ) ;
if ( V_6 -> V_228 ) {
if ( ! V_6 -> V_229 )
F_112 ( V_6 , V_10 ) ;
V_6 -> V_228 = 0 ;
} else if ( V_6 -> V_3 . V_253 ) {
V_194 * V_254 = V_10 -> V_255 . V_254 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_31 ( V_6 , V_18 , V_254 [ V_18 ] ) ;
V_6 -> V_3 . V_253 = 0 ;
} else if ( V_6 -> V_3 . V_256 ) {
int V_18 ;
F_31 ( V_6 , 3 , V_10 -> V_257 . V_189 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_31 ( V_6 , 4 + V_18 , V_10 -> V_257 . args [ V_18 ] ) ;
V_6 -> V_3 . V_256 = 0 ;
#ifdef F_63
} else if ( V_6 -> V_3 . V_258 ) {
F_138 ( V_6 , V_10 -> V_259 . V_259 ) ;
V_6 -> V_3 . V_258 = 0 ;
#endif
}
V_7 = F_139 ( V_10 , V_6 ) ;
if ( V_6 -> V_250 )
F_137 ( V_251 , & V_249 , NULL ) ;
return V_7 ;
}
int F_140 ( struct V_1 * V_6 , struct V_260 * V_261 )
{
if ( V_261 -> V_261 == V_262 ) {
F_141 ( V_6 ) ;
return 0 ;
}
F_142 ( V_6 , V_261 ) ;
F_143 ( V_6 ) ;
return 0 ;
}
static int F_144 ( struct V_1 * V_6 ,
struct V_263 * V_264 )
{
int V_7 ;
if ( V_264 -> V_265 )
return - V_70 ;
switch ( V_264 -> V_264 ) {
case V_139 :
V_7 = 0 ;
V_6 -> V_3 . V_266 = true ;
break;
case V_130 :
V_7 = 0 ;
V_6 -> V_3 . V_66 = true ;
break;
case V_127 :
V_7 = 0 ;
if ( V_264 -> args [ 0 ] )
V_6 -> V_3 . V_267 |= V_268 ;
else
V_6 -> V_3 . V_267 &= ~ V_268 ;
break;
#ifdef F_63
case V_126 :
V_7 = 0 ;
V_6 -> V_3 . V_269 = true ;
break;
#endif
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_142 : {
struct V_270 V_271 ;
void V_246 * V_272 = ( void V_246 * ) ( V_273 ) V_264 -> args [ 0 ] ;
V_7 = - V_248 ;
if ( F_133 ( & V_271 , V_272 , sizeof( V_271 ) ) )
break;
V_7 = F_145 ( V_6 , & V_271 ) ;
break;
}
#endif
#ifdef F_65
case V_145 : {
struct V_274 V_275 ;
struct V_276 * V_277 ;
V_7 = - V_278 ;
V_275 = F_146 ( V_264 -> args [ 0 ] ) ;
if ( ! V_275 . V_163 )
break;
V_7 = - V_101 ;
V_277 = F_147 ( V_275 . V_163 ) ;
if ( V_277 )
V_7 = F_148 ( V_277 , V_6 , V_264 -> args [ 1 ] ) ;
F_149 ( V_275 ) ;
break;
}
#endif
#ifdef F_66
case V_151 : {
struct V_274 V_275 ;
struct V_276 * V_277 ;
V_7 = - V_278 ;
V_275 = F_146 ( V_264 -> args [ 0 ] ) ;
if ( ! V_275 . V_163 )
break;
V_7 = - V_101 ;
V_277 = F_147 ( V_275 . V_163 ) ;
if ( V_277 )
V_7 = F_150 ( V_277 , V_6 , V_264 -> args [ 1 ] ) ;
F_149 ( V_275 ) ;
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
struct V_279 * V_280 )
{
return - V_70 ;
}
int F_152 ( struct V_1 * V_6 ,
struct V_279 * V_280 )
{
return - V_70 ;
}
long F_153 ( struct V_163 * V_164 ,
unsigned int V_165 , unsigned long V_166 )
{
struct V_1 * V_6 = V_164 -> V_281 ;
void V_246 * V_282 = ( void V_246 * ) V_166 ;
long V_7 ;
switch ( V_165 ) {
case V_283 : {
struct V_260 V_261 ;
V_7 = - V_248 ;
if ( F_133 ( & V_261 , V_282 , sizeof( V_261 ) ) )
goto V_63;
V_7 = F_140 ( V_6 , & V_261 ) ;
goto V_63;
}
case V_284 :
{
struct V_263 V_264 ;
V_7 = - V_248 ;
if ( F_133 ( & V_264 , V_282 , sizeof( V_264 ) ) )
goto V_63;
V_7 = F_144 ( V_6 , & V_264 ) ;
break;
}
case V_285 :
case V_286 :
{
struct V_233 V_234 ;
V_7 = - V_248 ;
if ( F_133 ( & V_234 , V_282 , sizeof( V_234 ) ) )
goto V_63;
if ( V_165 == V_285 )
V_7 = F_132 ( V_6 , & V_234 ) ;
else
V_7 = F_126 ( V_6 , & V_234 ) ;
break;
}
#if F_25 ( V_57 ) || F_25 ( V_141 )
case V_287 : {
struct V_288 V_289 ;
V_7 = - V_248 ;
if ( F_133 ( & V_289 , V_282 , sizeof( V_289 ) ) )
goto V_63;
V_7 = F_154 ( V_6 , & V_289 ) ;
break;
}
#endif
default:
V_7 = - V_70 ;
}
V_63:
return V_7 ;
}
int F_155 ( struct V_1 * V_6 , struct V_290 * V_291 )
{
return V_292 ;
}
static int F_156 ( struct V_293 * V_294 )
{
T_2 V_295 = 0x60000000 ;
#ifdef F_34
T_2 V_296 = 0x44000022 ;
V_294 -> V_297 [ 0 ] = F_157 ( V_296 ) ;
V_294 -> V_297 [ 1 ] = F_157 ( V_295 ) ;
V_294 -> V_297 [ 2 ] = F_157 ( V_295 ) ;
V_294 -> V_297 [ 3 ] = F_157 ( V_295 ) ;
#else
T_2 V_298 = 0x3c000000 ;
T_2 V_299 = 0x60000000 ;
T_2 V_300 = 0x44000002 ;
T_2 V_301 = 0xffff ;
V_294 -> V_297 [ 0 ] = F_157 ( V_298 | ( ( V_302 >> 16 ) & V_301 ) ) ;
V_294 -> V_297 [ 1 ] = F_157 ( V_299 | ( V_302 & V_301 ) ) ;
V_294 -> V_297 [ 2 ] = F_157 ( V_300 ) ;
V_294 -> V_297 [ 3 ] = F_157 ( V_295 ) ;
#endif
V_294 -> V_265 = V_303 ;
return 0 ;
}
int F_158 ( struct V_67 * V_67 , struct V_304 * V_305 ,
bool V_306 )
{
if ( ! F_159 ( V_67 ) )
return - V_239 ;
V_305 -> V_307 = F_160 ( V_67 , V_308 ,
V_305 -> V_261 , V_305 -> V_309 ,
V_306 ) ;
return 0 ;
}
static int F_161 ( struct V_67 * V_67 ,
struct V_263 * V_264 )
{
int V_7 ;
if ( V_264 -> V_265 )
return - V_70 ;
switch ( V_264 -> V_264 ) {
#ifdef F_162
case V_150 : {
unsigned long V_297 = V_264 -> args [ 0 ] ;
V_7 = - V_70 ;
if ( V_297 > V_310 || ( V_297 & 3 ) ||
V_264 -> args [ 1 ] > 1 )
break;
if ( ! F_163 ( V_67 , V_297 ) )
break;
if ( V_264 -> args [ 1 ] )
F_164 ( V_297 / 4 , V_67 -> V_3 . V_311 ) ;
else
F_30 ( V_297 / 4 , V_67 -> V_3 . V_311 ) ;
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
struct V_67 * V_67 T_1 = V_164 -> V_281 ;
void V_246 * V_282 = ( void V_246 * ) V_166 ;
long V_7 ;
switch ( V_165 ) {
case V_312 : {
struct V_293 V_294 ;
memset ( & V_294 , 0 , sizeof( V_294 ) ) ;
V_7 = F_156 ( & V_294 ) ;
if ( F_131 ( V_282 , & V_294 , sizeof( V_294 ) ) ) {
V_7 = - V_248 ;
goto V_63;
}
break;
}
case V_284 :
{
struct V_263 V_264 ;
V_7 = - V_248 ;
if ( F_133 ( & V_264 , V_282 , sizeof( V_264 ) ) )
goto V_63;
V_7 = F_161 ( V_67 , & V_264 ) ;
break;
}
#ifdef V_38
case V_313 : {
struct V_314 V_315 ;
V_7 = - V_248 ;
if ( F_133 ( & V_315 , V_282 , sizeof( V_315 ) ) )
goto V_63;
V_7 = F_166 ( V_67 , & V_315 ) ;
goto V_63;
}
case V_316 : {
struct V_317 V_318 ;
struct V_67 * V_67 = V_164 -> V_281 ;
memset ( & V_318 , 0 , sizeof( V_318 ) ) ;
V_7 = V_67 -> V_3 . V_112 -> V_319 ( V_67 , & V_318 ) ;
if ( V_7 >= 0 && F_131 ( V_282 , & V_318 , sizeof( V_318 ) ) )
V_7 = - V_248 ;
break;
}
case V_320 : {
struct V_67 * V_67 = V_164 -> V_281 ;
V_7 = F_167 ( V_67 , V_282 ) ;
break;
}
default: {
struct V_67 * V_67 = V_164 -> V_281 ;
V_7 = V_67 -> V_3 . V_112 -> V_321 ( V_164 , V_165 , V_166 ) ;
}
#else
default:
V_7 = - V_322 ;
#endif
}
V_63:
return V_7 ;
}
long F_168 ( void )
{
long V_323 ;
do {
V_323 = F_169 ( V_324 , V_325 ) ;
if ( V_323 >= V_326 ) {
F_170 ( L_4 , V_84 ) ;
return - V_327 ;
}
} while ( F_171 ( V_323 , V_324 ) );
return V_323 ;
}
void F_172 ( long V_323 )
{
F_164 ( V_323 , V_324 ) ;
}
void F_173 ( long V_323 )
{
F_30 ( V_323 , V_324 ) ;
}
void F_174 ( unsigned long V_328 )
{
V_326 = F_175 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_324 , 0 , sizeof( V_324 ) ) ;
}
int F_176 ( void * V_329 )
{
return 0 ;
}
