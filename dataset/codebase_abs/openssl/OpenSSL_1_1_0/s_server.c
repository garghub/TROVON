static unsigned int F_1 ( T_1 * V_1 , const char * V_2 ,
unsigned char * V_3 ,
unsigned int V_4 )
{
long V_5 = 0 ;
unsigned char * V_6 ;
if ( V_7 )
F_2 ( V_8 , L_1 ) ;
if ( ! V_2 ) {
F_2 ( V_9 , L_2 ) ;
goto V_10;
}
if ( V_7 )
F_2 ( V_8 , L_3 ,
( int ) strlen ( V_2 ) , V_2 ) ;
if ( strcmp ( V_2 , V_11 ) != 0 ) {
F_2 ( V_8 , L_4
L_5 , V_2 , V_11 ) ;
goto V_10;
}
if ( V_7 )
F_2 ( V_8 , L_6 ) ;
V_6 = F_3 ( V_12 , & V_5 ) ;
if ( V_6 == NULL ) {
F_2 ( V_9 , L_7 ,
V_12 ) ;
return 0 ;
}
if ( V_5 > ( int ) V_4 ) {
F_2 ( V_9 ,
L_8 ,
V_4 , V_5 ) ;
F_4 ( V_6 ) ;
return 0 ;
}
memcpy ( V_3 , V_6 , V_5 ) ;
F_4 ( V_6 ) ;
if ( V_7 )
F_2 ( V_8 , L_9 , V_5 ) ;
return V_5 ;
V_10:
if ( V_7 )
F_2 ( V_9 , L_10 ) ;
( void ) F_5 ( V_9 ) ;
( void ) F_5 ( V_8 ) ;
return 0 ;
}
static int F_6 ( T_1 * V_13 , int * V_14 , void * V_15 )
{
T_2 * V_16 = ( T_2 * ) V_15 ;
int V_17 = V_18 ;
if ( V_16 -> V_19 == NULL && V_16 -> V_20 == NULL ) {
V_16 -> V_19 = F_7 ( V_13 ) ;
F_2 ( V_9 , L_11 , V_16 -> V_19 ) ;
return ( - 1 ) ;
}
if ( V_16 -> V_20 == NULL ) {
F_2 ( V_9 , L_12 , V_16 -> V_19 ) ;
goto V_21;
}
if ( F_8
( V_13 , V_16 -> V_20 -> V_22 , V_16 -> V_20 -> V_23 , V_16 -> V_20 -> V_13 , V_16 -> V_20 -> V_24 ,
V_16 -> V_20 -> V_25 ) < 0 ) {
* V_14 = V_26 ;
goto V_21;
}
F_2 ( V_9 ,
L_13 ,
V_16 -> V_19 , V_16 -> V_20 -> V_25 ) ;
V_17 = V_27 ;
V_21:
F_9 ( V_16 -> V_20 ) ;
V_16 -> V_20 = NULL ;
V_16 -> V_19 = NULL ;
return V_17 ;
}
static const T_3 * F_10 ()
{
if ( V_28 == NULL ) {
V_28 = F_11 ( V_29 ,
L_14 ) ;
if ( V_28 == NULL
|| ! F_12 ( V_28 , V_30 )
|| ! F_13 ( V_28 , V_31 )
|| ! F_14 ( V_28 , V_32 )
|| ! F_15 ( V_28 , V_33 )
|| ! F_16 ( V_28 , V_34 )
|| ! F_17 ( V_28 , V_35 )
|| ! F_18 ( V_28 , V_36 ) )
return NULL ;
}
return V_28 ;
}
static int V_35 ( T_4 * V_37 )
{
T_5 * V_38 ;
V_38 = F_19 ( sizeof( * V_38 ) + 1024 , L_15 ) ;
V_38 -> V_39 = 1024 ;
V_38 -> V_40 [ 0 ] = '\0' ;
F_20 ( V_37 , V_38 ) ;
F_21 ( V_37 , 1 ) ;
return 1 ;
}
static int V_36 ( T_4 * V_41 )
{
T_5 * V_38 ;
if ( V_41 == NULL )
return 0 ;
V_38 = F_22 ( V_41 ) ;
F_4 ( V_38 ) ;
F_20 ( V_41 , NULL ) ;
F_21 ( V_41 , 0 ) ;
return 1 ;
}
static int V_31 ( T_4 * V_42 , char * V_43 , int V_44 )
{
int V_17 = 0 ;
T_4 * V_45 = F_23 ( V_42 ) ;
if ( V_43 == NULL || V_44 == 0 )
return ( 0 ) ;
if ( V_45 == NULL )
return ( 0 ) ;
V_17 = F_24 ( V_45 , V_43 , V_44 ) ;
if ( V_17 > 0 )
F_25 ( V_43 , V_43 , V_17 ) ;
return V_17 ;
}
static int V_30 ( T_4 * V_42 , const char * V_46 , int V_47 )
{
T_5 * V_38 ;
T_4 * V_45 = F_23 ( V_42 ) ;
int V_17 = 0 ;
int V_48 ;
if ( ( V_46 == NULL ) || ( V_47 <= 0 ) )
return ( 0 ) ;
if ( V_45 == NULL )
return 0 ;
V_38 = ( T_5 * ) F_22 ( V_42 ) ;
if ( V_47 > ( V_48 = V_38 -> V_39 ) ) {
V_48 = V_48 + V_48 ;
if ( V_48 < V_47 )
V_48 = V_47 ;
F_4 ( V_38 ) ;
V_38 = F_19 ( sizeof( * V_38 ) + V_48 , L_16 ) ;
V_38 -> V_39 = V_48 ;
V_38 -> V_40 [ 0 ] = '\0' ;
F_20 ( V_42 , V_38 ) ;
}
F_26 ( V_38 -> V_40 , V_46 , V_47 ) ;
V_17 = F_27 ( V_45 , V_38 -> V_40 , V_47 ) ;
return ( V_17 ) ;
}
static long V_34 ( T_4 * V_42 , int V_49 , long V_48 , void * V_50 )
{
long V_17 ;
T_4 * V_45 = F_23 ( V_42 ) ;
if ( V_45 == NULL )
return ( 0 ) ;
switch ( V_49 ) {
case V_51 :
V_17 = 0L ;
break;
default:
V_17 = F_28 ( V_45 , V_49 , V_48 , V_50 ) ;
break;
}
return ( V_17 ) ;
}
static int V_33 ( T_4 * V_52 , char * V_53 , int V_54 )
{
int V_55 , V_17 = 0 ;
T_4 * V_45 = F_23 ( V_52 ) ;
if ( V_45 == NULL )
return 0 ;
for ( V_55 = 0 ; V_55 < V_54 - 1 ; ++ V_55 ) {
V_17 = V_31 ( V_52 , & V_53 [ V_55 ] , 1 ) ;
if ( V_17 <= 0 )
break;
else if ( V_53 [ V_55 ] == '\n' ) {
++ V_55 ;
break;
}
}
if ( V_55 < V_54 )
V_53 [ V_55 ] = '\0' ;
return ( V_17 < 0 && V_55 == 0 ) ? V_17 : V_55 ;
}
static int V_32 ( T_4 * V_52 , const char * V_56 )
{
if ( F_23 ( V_52 ) == NULL )
return 0 ;
return V_30 ( V_52 , V_56 , strlen ( V_56 ) ) ;
}
static int F_29 ( T_1 * V_13 , int * V_14 , void * V_15 )
{
T_6 * V_16 = ( T_6 * ) V_15 ;
const char * V_57 = F_30 ( V_13 , V_58 ) ;
if ( V_57 && V_16 -> V_59 )
F_2 ( V_16 -> V_59 , L_17 ,
V_57 ) ;
if ( ! V_16 -> V_57 )
return V_60 ;
if ( V_57 ) {
if ( strcasecmp ( V_57 , V_16 -> V_57 ) )
return V_16 -> V_61 ;
if ( V_62 ) {
F_2 ( V_16 -> V_59 , L_18 ) ;
F_31 ( V_13 , V_62 ) ;
}
}
return V_63 ;
}
static int F_32 ( T_1 * V_13 , void * V_15 )
{
T_7 * V_64 = V_15 ;
char * V_65 = NULL , * V_66 = NULL , * V_67 = NULL ;
int V_68 ;
unsigned char * V_69 = NULL ;
int V_70 ;
F_33 ( V_71 ) * V_72 = NULL ;
T_8 * V_73 = NULL ;
T_9 * V_74 = NULL ;
T_10 * V_75 ;
T_11 * V_76 = NULL ;
T_12 * V_77 = NULL ;
T_13 * V_78 = NULL ;
F_33 ( V_79 ) * V_80 ;
int V_17 = V_60 ;
int V_55 ;
if ( V_64 -> V_81 )
F_34 ( V_9 , L_19 ) ;
V_73 = F_35 ( V_13 ) ;
V_72 = F_36 ( V_73 ) ;
if ( V_72 ) {
if ( ! F_37 ( F_38 ( V_72 , 0 ) ,
& V_65 , & V_66 , & V_67 , & V_68 ) ) {
F_34 ( V_9 , L_20 ) ;
goto V_21;
}
if ( V_64 -> V_81 )
F_2 ( V_9 , L_21 ,
F_38 ( V_72 , 0 ) ) ;
} else {
if ( ! V_64 -> V_65 ) {
F_34 ( V_9 ,
L_22 ) ;
goto V_82;
}
V_65 = V_64 -> V_65 ;
V_67 = V_64 -> V_67 ;
V_66 = V_64 -> V_66 ;
V_68 = V_64 -> V_68 ;
}
V_74 = F_39 () ;
if ( V_74 == NULL )
goto V_21;
if ( ! F_40 ( V_74 ,
F_41 ( F_42 ( V_13 ) ) ,
NULL , NULL ) )
goto V_21;
V_75 = F_43 ( V_74 , V_83 ,
F_44 ( V_73 ) ) ;
if ( V_75 == NULL ) {
F_34 ( V_9 , L_23 ) ;
goto V_82;
}
V_78 = F_45 ( NULL , V_73 , F_46 ( V_75 ) ) ;
F_47 ( V_75 ) ;
if ( ! V_78 )
goto V_21;
V_76 = F_48 () ;
if ( V_76 == NULL )
goto V_21;
if ( ! F_49 ( V_76 , V_78 ) )
goto V_21;
V_78 = NULL ;
F_50 ( V_13 , & V_80 ) ;
for ( V_55 = 0 ; V_55 < F_51 ( V_80 ) ; V_55 ++ ) {
V_79 * V_84 = F_52 ( V_80 , V_55 ) ;
if ( ! F_53 ( V_76 , V_84 , - 1 ) )
goto V_21;
}
V_77 = F_54 ( V_76 , V_65 , V_67 , V_66 , V_68 , NULL ,
V_64 -> V_85 ) ;
if ( ! V_77 ) {
F_34 ( V_9 , L_24 ) ;
goto V_82;
}
V_70 = F_55 ( V_77 , & V_69 ) ;
if ( V_70 <= 0 )
goto V_21;
F_56 ( V_13 , V_69 , V_70 ) ;
if ( V_64 -> V_81 ) {
F_34 ( V_9 , L_25 ) ;
F_57 ( V_9 , V_77 , 2 ) ;
}
V_17 = V_63 ;
goto V_82;
V_21:
V_17 = V_86 ;
V_82:
if ( V_17 != V_63 )
F_58 ( V_9 ) ;
if ( V_72 ) {
F_4 ( V_65 ) ;
F_4 ( V_67 ) ;
F_4 ( V_66 ) ;
F_59 ( V_72 ) ;
}
F_60 ( V_78 ) ;
F_61 ( V_76 ) ;
F_62 ( V_77 ) ;
F_63 ( V_74 ) ;
return V_17 ;
}
static int F_64 ( T_1 * V_13 , const unsigned char * * V_87 ,
unsigned int * V_88 , void * V_15 )
{
T_14 * V_89 = V_15 ;
* V_87 = V_89 -> V_87 ;
* V_88 = V_89 -> V_88 ;
return V_63 ;
}
static int F_65 ( T_1 * V_13 , const unsigned char * * V_43 , unsigned char * V_90 ,
const unsigned char * V_46 , unsigned int V_91 , void * V_15 )
{
T_15 * V_92 = V_15 ;
if ( ! V_93 ) {
unsigned int V_55 ;
F_2 ( V_8 , L_26 ) ;
for ( V_55 = 0 ; V_55 < V_91 ; ) {
if ( V_55 )
F_27 ( V_8 , L_27 , 2 ) ;
F_27 ( V_8 , & V_46 [ V_55 + 1 ] , V_46 [ V_55 ] ) ;
V_55 += V_46 [ V_55 ] + 1 ;
}
F_27 ( V_8 , L_28 , 1 ) ;
}
if ( F_66
( ( unsigned char * * ) V_43 , V_90 , V_92 -> V_87 , V_92 -> V_88 , V_46 ,
V_91 ) != V_94 ) {
return V_60 ;
}
if ( ! V_93 ) {
F_2 ( V_8 , L_29 ) ;
F_27 ( V_8 , * V_43 , * V_90 ) ;
F_27 ( V_8 , L_28 , 1 ) ;
}
return V_63 ;
}
static int F_67 ( T_1 * V_13 , int V_95 )
{
return V_95 ;
}
int F_68 ( int V_96 , char * V_97 [] )
{
T_16 * V_98 = NULL ;
T_17 * V_99 = NULL , * V_100 = NULL ;
T_18 * V_101 = NULL ;
const T_19 * V_102 = F_69 () ;
T_20 * V_103 = NULL ;
F_33 ( V_71 ) * V_104 = NULL ;
F_33 ( T_8 ) * V_105 = NULL , * V_106 = NULL ;
F_33 ( V_107 ) * V_108 = NULL ;
T_8 * V_109 = NULL , * V_110 = NULL ;
T_21 * V_111 = NULL ;
const char * V_112 = NULL , * V_113 = NULL , * V_114 = NULL , * V_115 = NULL ;
char * V_116 = NULL , * V_117 = NULL , * V_118 = NULL ;
char * V_119 = NULL , * V_120 = NULL , * V_121 = NULL , * V_122 = NULL ;
char * V_123 = NULL , * V_124 ;
#ifdef F_70
int V_125 = 0 ;
#endif
T_22 V_126 ;
int V_127 = 0 , V_128 = 0 , V_129 = 0 , V_130 = 0 ;
#ifndef F_71
char * V_131 = NULL ;
int V_132 = 0 ;
#endif
int V_133 = 0 , V_17 = 1 ;
int V_134 = 0 , V_135 = 0 ;
int V_136 = V_137 , V_138 = V_137 ;
int V_139 = V_137 , V_140 = V_137 ;
int V_141 = 0 , V_142 = - 1 , V_143 = 0 ;
int V_144 = V_145 , V_146 = V_147 ;
int V_148 = 0 , V_149 = V_137 , V_150 = 0 ;
char * V_65 = NULL ;
char * V_66 = F_72 ( V_151 ) ;
unsigned char * V_152 = NULL ;
T_23 V_153 ;
T_17 * V_154 = NULL ;
T_8 * V_155 = NULL ;
T_6 V_156 = { NULL , NULL , V_157 } ;
const char * V_158 = NULL ;
int V_159 = 0 ;
#ifndef F_73
const char * V_160 = NULL ;
T_14 V_89 = { NULL , 0 } ;
#endif
const char * V_161 = NULL ;
T_15 V_92 = { NULL , 0 } ;
#ifndef F_74
static char * V_162 = NULL ;
char * V_16 ;
#endif
#ifndef F_75
char * V_163 = NULL ;
char * V_164 = NULL ;
#endif
int V_165 = 0 , V_166 = 0 , V_167 = 0 , V_168 = 0 ;
int V_169 = V_170 ;
int V_171 = 1 ;
const char * V_172 = V_173 , * V_174 = NULL , * V_175 = NULL ;
const char * V_176 = V_177 , * V_178 = NULL ;
char * V_179 = NULL , * V_180 = NULL , * V_181 = NULL ;
int V_182 = 0 , V_183 = 0 ;
unsigned int V_184 = 0 , V_185 = 0 ;
const char * V_186 = NULL ;
V_187 = V_96 ;
V_188 = V_97 ;
V_189 = V_62 = NULL ;
V_190 = V_191 = 0 ;
V_192 = 0 ;
V_8 = NULL ;
V_7 = 0 ;
V_193 = 0 ;
V_93 = 0 ;
V_194 = 0 ;
V_195 = 0 ;
V_101 = F_76 () ;
V_111 = F_77 () ;
if ( V_101 == NULL || V_111 == NULL )
goto V_196;
F_78 ( V_101 ,
V_197 | V_198 ) ;
V_124 = F_79 ( V_96 , V_97 , V_199 ) ;
while ( ( V_153 = F_80 () ) != V_200 ) {
if ( F_81 ( V_153 ) && ++ V_167 > 1 ) {
F_2 ( V_9 , L_30 ) ;
goto V_196;
}
if ( F_82 ( V_153 ) )
V_168 ++ ;
if ( V_167 == 1 && V_168 ) {
F_2 ( V_9 ,
L_31 ) ;
goto V_196;
}
switch ( V_153 ) {
case V_200 :
case V_201 :
V_202:
F_2 ( V_9 , L_32 , V_124 ) ;
goto V_196;
case V_203 :
F_83 ( V_199 ) ;
V_17 = 0 ;
goto V_196;
case V_204 :
#ifdef F_70
if ( V_144 == F_70 ) {
F_4 ( V_65 ) ; V_65 = NULL ;
F_4 ( V_66 ) ; V_66 = NULL ;
}
#endif
V_144 = V_205 ;
break;
case V_206 :
if ( 1 ) {
#ifdef F_84
#ifdef F_70
if ( V_144 == F_70 ) {
F_4 ( V_65 ) ; V_65 = NULL ;
F_4 ( V_66 ) ; V_66 = NULL ;
}
#endif
V_144 = F_84 ;
} else {
#endif
F_2 ( V_9 , L_33 , V_124 ) ;
goto V_196;
}
break;
case V_207 :
#ifdef F_70
if ( V_144 == F_70 ) {
V_144 = V_145 ;
}
#endif
F_4 ( V_66 ) ; V_66 = NULL ;
F_4 ( V_65 ) ; V_65 = NULL ;
if ( F_85 ( F_86 () , NULL , & V_66 , V_208 ) < 1 ) {
F_2 ( V_9 ,
L_34 ,
V_66 ) ;
goto V_196;
}
break;
case V_209 :
#ifdef F_70
if ( V_144 == F_70 ) {
V_144 = V_145 ;
}
#endif
F_4 ( V_66 ) ; V_66 = NULL ;
F_4 ( V_65 ) ; V_65 = NULL ;
if ( F_85 ( F_86 () , & V_65 , & V_66 , V_208 ) < 1 ) {
F_2 ( V_9 ,
L_35 ,
V_66 ) ;
goto V_196;
}
break;
#ifdef F_70
case V_210 :
V_144 = F_70 ;
F_4 ( V_65 ) ; V_65 = F_72 ( F_86 () ) ;
F_4 ( V_66 ) ; V_66 = NULL ;
break;
case V_211 :
V_125 = 1 ;
break;
#endif
case V_212 :
V_142 = atol ( F_86 () ) ;
break;
case V_213 :
V_169 = V_214 | V_215 ;
V_216 . V_217 = atoi ( F_86 () ) ;
if ( ! V_93 )
F_2 ( V_9 , L_36 , V_216 . V_217 ) ;
break;
case V_218 :
V_169 =
V_214 | V_219 |
V_215 ;
V_216 . V_217 = atoi ( F_86 () ) ;
if ( ! V_93 )
F_2 ( V_9 ,
L_37 ,
V_216 . V_217 ) ;
break;
case V_220 :
V_152 = ( unsigned char * ) F_86 () ;
break;
case V_221 :
V_172 = F_86 () ;
break;
case V_222 :
V_123 = F_86 () ;
break;
case V_223 :
V_150 = 1 ;
break;
case V_224 :
V_186 = F_86 () ;
break;
case V_225 :
if ( ! F_87 ( F_86 () , V_226 , & V_136 ) )
goto V_202;
break;
case V_227 :
V_174 = F_86 () ;
break;
case V_228 :
if ( ! F_87 ( F_86 () , V_229 , & V_138 ) )
goto V_202;
break;
case V_230 :
V_119 = F_86 () ;
break;
case V_231 :
V_175 = F_86 () ;
break;
case V_232 :
#ifndef F_71
V_131 = F_86 () ;
#endif
break;
case V_233 :
if ( ! F_87 ( F_86 () , V_226 , & V_139 ) )
goto V_202;
break;
case V_234 :
V_179 = F_86 () ;
break;
case V_235 :
if ( ! F_87 ( F_86 () , V_226 , & V_140 ) )
goto V_202;
break;
case V_236 :
V_116 = F_86 () ;
break;
case V_237 :
V_180 = F_86 () ;
break;
case V_238 :
V_181 = F_86 () ;
break;
case V_239 :
V_133 = 1 ;
break;
case V_240 :
V_112 = F_86 () ;
break;
case V_241 :
V_134 = 1 ;
break;
case V_242 :
V_114 = F_86 () ;
break;
case V_243 :
V_121 = F_86 () ;
break;
case V_244 :
V_129 = 1 ;
break;
case V_245 :
V_130 = 1 ;
break;
case V_246 :
if ( ! F_87 ( F_86 () , V_226 , & V_149 ) )
goto V_202;
break;
case V_247 :
if ( V_104 == NULL )
V_104 = F_88 () ;
if ( V_104 == NULL
|| ! F_89 ( V_104 , F_90 () )
|| ! F_89 ( V_104 , F_86 () ) ) {
F_2 ( V_9 , L_38 , V_124 ) ;
goto V_196;
}
break;
case V_248 :
if ( ! F_91 ( V_153 , V_111 ) )
goto V_196;
V_127 ++ ;
break;
case V_249 :
if ( ! F_92 ( V_153 , & V_103 ) )
goto V_196;
break;
case V_250 :
V_216 . V_251 = 1 ;
break;
case V_252 :
V_216 . V_253 = 1 ;
break;
case V_254 :
V_128 = 1 ;
break;
case V_255 :
V_113 = F_86 () ;
break;
case V_256 :
V_135 = 1 ;
break;
case V_257 :
V_115 = F_86 () ;
break;
case V_258 :
V_122 = F_86 () ;
break;
case V_259 :
V_190 = 1 ;
break;
case V_260 :
V_190 = V_191 = 1 ;
break;
case V_261 :
V_262 = 1 ;
break;
case V_263 :
V_262 = 0 ;
break;
case V_264 :
V_7 = 1 ;
break;
case V_265 :
V_266 = 1 ;
break;
case V_267 :
V_182 = 1 ;
break;
case V_268 :
V_182 = V_269 . V_81 = 1 ;
break;
case V_270 :
V_182 = 1 ;
V_269 . V_85 = atoi ( F_86 () ) ;
break;
case V_271 :
#ifndef F_93
V_182 = 1 ;
if ( ! F_37 ( F_86 () ,
& V_269 . V_65 ,
& V_269 . V_66 ,
& V_269 . V_67 , & V_269 . V_68 ) ) {
F_2 ( V_9 , L_39 ) ;
goto V_196;
}
#endif
break;
case V_272 :
V_193 = 1 ;
break;
case V_273 :
V_274 = F_94 ( F_86 () , L_40 ) ;
break;
case V_275 :
#ifndef F_95
V_193 = 2 ;
#endif
break;
case V_276 :
V_143 = 1 ;
break;
case V_277 :
V_143 = 2 ;
break;
case V_278 :
V_148 = 1 ;
break;
case V_279 :
V_280 = 1 ;
break;
case V_281 :
V_93 = 1 ;
break;
case V_282 :
V_93 = V_194 = V_216 . V_253 = 1 ;
break;
case V_283 :
#ifndef F_71
V_132 = 1 ;
#endif
break;
case V_284 :
V_183 = 1 ;
break;
case V_285 :
#ifndef F_74
V_162 = F_86 () ;
#endif
break;
case V_286 :
#ifndef F_74
for ( V_16 = V_12 = F_86 () ; * V_16 ; V_16 ++ ) {
if ( isxdigit ( F_96 ( * V_16 ) ) )
continue;
F_2 ( V_9 , L_41 , * V_97 ) ;
goto V_196;
}
#endif
break;
case V_287 :
#ifndef F_75
V_164 = F_86 () ;
if ( V_165 < V_288 )
V_165 = V_288 ;
#endif
break;
case V_289 :
#ifndef F_75
V_163 = F_86 () ;
if ( V_165 < V_288 )
V_165 = V_288 ;
#endif
break;
case V_290 :
V_141 = 1 ;
break;
case V_291 :
V_192 = 1 ;
break;
case V_292 :
V_192 = 2 ;
break;
case V_293 :
V_192 = 3 ;
break;
case V_294 :
V_158 = F_86 () ;
break;
case V_295 :
V_165 = V_296 ;
V_166 = V_296 ;
break;
case V_297 :
V_165 = V_298 ;
V_166 = V_298 ;
break;
case V_299 :
V_165 = V_300 ;
V_166 = V_300 ;
break;
case V_301 :
V_165 = V_288 ;
V_166 = V_288 ;
break;
case V_302 :
#ifndef F_97
V_102 = F_98 () ;
V_146 = V_303 ;
#endif
break;
case V_304 :
#ifndef F_97
V_102 = F_98 () ;
V_165 = V_305 ;
V_166 = V_305 ;
V_146 = V_303 ;
#endif
break;
case V_306 :
#ifndef F_97
V_102 = F_98 () ;
V_165 = V_307 ;
V_166 = V_307 ;
V_146 = V_303 ;
#endif
break;
case V_308 :
#ifndef F_97
V_309 = 1 ;
#endif
break;
case V_310 :
#ifndef F_97
V_311 = atol ( F_86 () ) ;
#endif
break;
case V_312 :
#ifndef F_97
V_313 = 1 ;
#endif
break;
case V_314 :
V_315 = F_86 () ;
break;
case V_316 :
V_98 = F_99 ( F_86 () , 1 ) ;
break;
case V_317 :
V_118 = F_86 () ;
break;
case V_318 :
V_156 . V_57 = F_86 () ;
break;
case V_319 :
V_156 . V_61 = V_86 ;
break;
case V_320 :
V_176 = F_86 () ;
break;
case V_321 :
V_178 = F_86 () ;
break;
case V_322 :
# ifndef F_73
V_160 = F_86 () ;
#endif
break;
case V_323 :
V_161 = F_86 () ;
break;
case V_324 :
#ifndef F_100
V_325 = F_86 () ;
#endif
break;
case V_326 :
V_327 = F_86 () ;
break;
case V_328 :
V_329 = atoi ( F_86 () ) ;
break;
case V_330 :
V_195 = 1 ;
break;
case V_331 :
V_184 = atoi ( F_86 () ) ;
if ( V_184 == 0 ) {
V_184 = V_332 + 1 ;
}
break;
case V_333 :
V_185 = atoi ( F_86 () ) ;
break;
case V_334 :
V_159 = atoi ( F_86 () ) ;
break;
}
}
V_96 = F_101 () ;
V_97 = F_102 () ;
#ifndef F_97
if ( V_192 && V_146 == V_303 ) {
F_2 ( V_9 , L_42 ) ;
goto V_196;
}
if ( V_313 && V_146 != V_303 ) {
F_2 ( V_9 , L_43 ) ;
goto V_196;
}
#endif
#ifdef F_70
if ( V_144 == F_70 && V_146 != V_147 ) {
F_2 ( V_9 ,
L_44 ) ;
goto V_196;
}
#endif
if ( V_184 > V_332 ) {
F_2 ( V_9 , L_45 ) ;
goto V_196;
}
if ( V_185 > V_335 ) {
F_2 ( V_9 , L_46 ) ;
goto V_196;
}
if ( ! F_103 ( V_119 , V_116 , & V_120 , & V_117 ) ) {
F_2 ( V_9 , L_47 ) ;
goto V_196;
}
if ( V_174 == NULL )
V_174 = V_172 ;
if ( V_178 == NULL )
V_178 = V_176 ;
if ( ! F_104 ( & V_103 ) )
goto V_196;
if ( V_133 == 0 ) {
V_99 = F_105 ( V_174 , V_138 , 0 , V_120 , V_98 ,
L_48 ) ;
if ( ! V_99 ) {
F_58 ( V_9 ) ;
goto V_196;
}
V_109 = F_106 ( V_172 , V_136 ,
L_49 ) ;
if ( ! V_109 ) {
F_58 ( V_9 ) ;
goto V_196;
}
if ( V_175 ) {
if ( ! F_107 ( V_175 , & V_105 , V_137 , NULL ,
L_50 ) )
goto V_196;
}
if ( V_156 . V_57 ) {
V_154 = F_105 ( V_178 , V_138 , 0 , V_120 , V_98 ,
L_51 ) ;
if ( ! V_154 ) {
F_58 ( V_9 ) ;
goto V_196;
}
V_155 = F_106 ( V_176 , V_136 ,
L_52 ) ;
if ( ! V_155 ) {
F_58 ( V_9 ) ;
goto V_196;
}
}
}
#if ! F_108 ( F_73 )
if ( V_160 ) {
T_24 V_88 ;
V_89 . V_87 = F_109 ( & V_88 , V_160 ) ;
if ( V_89 . V_87 == NULL )
goto V_196;
V_89 . V_88 = V_88 ;
} else {
V_89 . V_87 = NULL ;
}
#endif
V_92 . V_87 = NULL ;
if ( V_161 ) {
T_24 V_88 ;
V_92 . V_87 = F_109 ( & V_88 , V_161 ) ;
if ( V_92 . V_87 == NULL )
goto V_196;
V_92 . V_88 = V_88 ;
}
if ( V_123 ) {
V_107 * V_336 ;
V_336 = F_110 ( V_123 , V_149 ) ;
if ( ! V_336 ) {
F_34 ( V_9 , L_53 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
V_108 = F_111 () ;
if ( ! V_108 || ! F_112 ( V_108 , V_336 ) ) {
F_34 ( V_9 , L_54 ) ;
F_58 ( V_9 ) ;
F_113 ( V_336 ) ;
goto V_196;
}
}
if ( V_179 ) {
if ( V_180 == NULL )
V_180 = V_179 ;
V_100 = F_105 ( V_180 , V_140 ,
0 , V_117 , V_98 , L_55 ) ;
if ( ! V_100 ) {
F_58 ( V_9 ) ;
goto V_196;
}
V_110 = F_106 ( V_179 , V_139 ,
L_52 ) ;
if ( ! V_110 ) {
F_58 ( V_9 ) ;
goto V_196;
}
if ( V_181 ) {
if ( ! F_107 ( V_181 , & V_106 , V_137 , NULL ,
L_56 ) )
goto V_196;
}
}
if ( ! F_114 ( NULL , 1 ) && V_118 == NULL
&& ! F_115 () ) {
F_2 ( V_9 ,
L_57 ) ;
}
if ( V_118 != NULL )
F_2 ( V_9 , L_58 ,
F_116 ( V_118 ) ) ;
if ( V_8 == NULL ) {
if ( V_93 && ! V_7 ) {
V_8 = F_117 ( F_118 () ) ;
if ( V_193 && ! V_274 )
V_274 = F_119 ( V_337 ) ;
} else {
if ( V_8 == NULL )
V_8 = F_119 ( V_337 ) ;
}
}
#if ! F_108 ( V_338 ) || ! F_108 ( V_339 ) || ! F_108 ( V_340 )
if ( V_133 )
#endif
{
V_172 = NULL ;
V_174 = NULL ;
V_179 = NULL ;
V_180 = NULL ;
V_176 = NULL ;
V_178 = NULL ;
}
V_189 = F_120 ( V_102 ) ;
if ( V_189 == NULL ) {
F_58 ( V_9 ) ;
goto V_196;
}
if ( V_143 )
F_121 ( V_189 , V_143 ) ;
if ( V_158 ) {
if ( F_122 ( V_189 , V_158 ) == 0 ) {
F_2 ( V_9 , L_59 ,
V_158 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
}
if ( F_123 ( V_189 , V_165 ) == 0 )
goto V_196;
if ( F_124 ( V_189 , V_166 ) == 0 )
goto V_196;
if ( V_315 ) {
if ( strlen ( V_315 ) >= 32 )
F_2 ( V_9 ,
L_60 ) ;
if ( ! F_125 ( V_189 , V_341 ) ) {
F_2 ( V_9 , L_61 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
F_2 ( V_9 , L_62 , V_315 ) ;
}
F_126 ( V_189 , 1 ) ;
if ( V_103 )
F_127 ( V_189 , V_103 ) ;
if ( V_148 )
F_128 ( V_189 , V_342 ) ;
if ( V_129 )
F_129 ( V_189 , V_343 ) ;
else if ( V_130 )
F_130 ( V_189 ) ;
else
F_131 ( V_189 , 128 ) ;
if ( V_195 ) {
F_132 ( V_189 , V_344 ) ;
}
if ( V_184 > 0 ) {
F_133 ( V_189 , V_184 ) ;
}
if ( V_185 > 0 ) {
F_134 ( V_189 , V_185 ) ;
}
if ( V_159 > 0 ) {
F_135 ( V_189 , V_159 ) ;
}
#ifndef F_100
if ( V_325 != NULL ) {
if ( F_136 ( V_189 , V_325 ) != 0 ) {
F_2 ( V_9 , L_63 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
}
#endif
if ( ! F_137 ( V_189 , V_113 , V_112 , V_135 , V_134 ) ) {
F_58 ( V_9 ) ;
goto V_196;
}
if ( V_127 && ! F_138 ( V_189 , V_111 ) ) {
F_2 ( V_9 , L_64 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
F_139 ( V_189 , V_108 , 0 ) ;
if ( ! F_140 ( V_101 , V_104 , V_189 ) )
goto V_196;
if ( ! F_141 ( V_189 , V_121 , V_122 , V_114 , V_115 ,
V_108 , V_150 ) ) {
F_2 ( V_9 , L_65 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
if ( V_155 ) {
V_62 = F_120 ( V_102 ) ;
if ( V_62 == NULL ) {
F_58 ( V_9 ) ;
goto V_196;
}
}
if ( V_62 ) {
F_2 ( V_8 , L_66 ) ;
if ( V_143 )
F_121 ( V_189 , V_143 ) ;
if ( V_315 ) {
if ( strlen ( V_315 ) >= 32 )
F_2 ( V_9 ,
L_60 ) ;
if ( ! F_125 ( V_62 , V_341 ) ) {
F_2 ( V_9 , L_61 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
F_2 ( V_9 , L_62 , V_315 ) ;
}
F_126 ( V_62 , 1 ) ;
if ( V_103 )
F_127 ( V_62 , V_103 ) ;
if ( V_148 )
F_128 ( V_62 , V_342 ) ;
if ( V_129 )
F_129 ( V_62 , V_343 ) ;
else if ( V_130 )
F_130 ( V_62 ) ;
else
F_131 ( V_62 , 128 ) ;
if ( V_195 )
F_132 ( V_62 , V_344 ) ;
if ( ! F_137 ( V_62 , V_113 , V_112 , V_135 ,
V_134 ) ) {
F_58 ( V_9 ) ;
goto V_196;
}
if ( V_127 && ! F_138 ( V_62 , V_111 ) ) {
F_2 ( V_9 , L_64 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
F_139 ( V_62 , V_108 , 0 ) ;
if ( ! F_140 ( V_101 , V_104 , V_62 ) )
goto V_196;
}
#ifndef F_73
if ( V_89 . V_87 )
F_142 ( V_189 , F_64 ,
& V_89 ) ;
#endif
if ( V_92 . V_87 )
F_143 ( V_189 , F_65 , & V_92 ) ;
#ifndef F_71
if ( ! V_132 ) {
T_25 * V_345 = NULL ;
if ( V_131 )
V_345 = F_144 ( V_131 ) ;
else if ( V_172 )
V_345 = F_144 ( V_172 ) ;
if ( V_345 != NULL ) {
F_2 ( V_8 , L_67 ) ;
} else {
F_2 ( V_8 , L_68 ) ;
}
( void ) F_5 ( V_8 ) ;
if ( V_345 == NULL )
F_145 ( V_189 , 1 ) ;
else if ( ! F_146 ( V_189 , V_345 ) ) {
F_34 ( V_9 , L_69 ) ;
F_58 ( V_9 ) ;
F_147 ( V_345 ) ;
goto V_196;
}
if ( V_62 ) {
if ( ! V_131 ) {
T_25 * V_346 = F_144 ( V_176 ) ;
if ( V_346 != NULL ) {
F_2 ( V_8 , L_67 ) ;
( void ) F_5 ( V_8 ) ;
F_147 ( V_345 ) ;
V_345 = V_346 ;
}
}
if ( V_345 == NULL )
F_145 ( V_62 , 1 ) ;
else if ( ! F_146 ( V_62 , V_345 ) ) {
F_34 ( V_9 , L_69 ) ;
F_58 ( V_9 ) ;
F_147 ( V_345 ) ;
goto V_196;
}
}
F_147 ( V_345 ) ;
}
#endif
if ( ! F_148 ( V_189 , V_109 , V_99 , V_105 , V_128 ) )
goto V_196;
if ( V_186 != NULL
&& ! F_149 ( V_189 , V_186 ) ) {
F_58 ( V_9 ) ;
goto V_196;
}
if ( V_62 && ! F_148 ( V_62 , V_155 , V_154 , NULL , V_128 ) )
goto V_196;
if ( V_110 != NULL ) {
if ( ! F_148 ( V_189 , V_110 , V_100 , V_106 , V_128 ) )
goto V_196;
}
if ( V_183 ) {
F_150 ( V_189 ,
F_67 ) ;
if ( V_62 )
F_150 ( V_62 ,
F_67 ) ;
}
#ifndef F_74
if ( V_12 != NULL ) {
if ( V_7 )
F_2 ( V_8 , L_70 ) ;
F_151 ( V_189 , F_1 ) ;
}
if ( ! F_152 ( V_189 , V_162 ) ) {
F_2 ( V_9 , L_71 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
#endif
F_153 ( V_189 , V_169 , V_347 ) ;
if ( ! F_154 ( V_189 ,
( void * ) & V_171 ,
sizeof V_171 ) ) {
F_2 ( V_9 , L_72 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
F_155 ( V_189 , V_348 ) ;
F_156 ( V_189 , V_349 ) ;
if ( V_62 ) {
F_153 ( V_62 , V_169 , V_347 ) ;
if ( ! F_154 ( V_62 ,
( void * ) & V_171 ,
sizeof V_171 ) ) {
F_2 ( V_9 , L_72 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
V_156 . V_59 = V_8 ;
F_157 ( V_62 , F_29 ) ;
F_158 ( V_62 , & V_156 ) ;
F_157 ( V_189 , F_29 ) ;
F_158 ( V_189 , & V_156 ) ;
}
#ifndef F_75
if ( V_164 != NULL ) {
V_350 . V_351 = F_159 ( V_163 ) ;
V_350 . V_20 = NULL ;
V_350 . V_19 = NULL ;
if ( ( V_17 =
F_160 ( V_350 . V_351 ,
V_164 ) ) != V_352 ) {
F_2 ( V_9 ,
L_73 ,
V_164 , V_17 ) ;
goto V_196;
}
F_153 ( V_189 , V_170 , V_347 ) ;
F_161 ( V_189 , & V_350 ) ;
F_162 ( V_189 , F_6 ) ;
} else
#endif
if ( V_113 != NULL ) {
F_163 ( V_189 , F_164 ( V_113 ) ) ;
if ( V_62 )
F_163 ( V_62 , F_164 ( V_113 ) ) ;
}
#ifndef F_93
if ( V_182 ) {
F_165 ( V_189 , F_32 ) ;
F_166 ( V_189 , & V_269 ) ;
if ( V_62 ) {
F_165 ( V_62 , F_32 ) ;
F_166 ( V_62 , & V_269 ) ;
}
}
#endif
F_2 ( V_8 , L_74 ) ;
( void ) F_5 ( V_8 ) ;
if ( V_141 )
V_126 = V_353 ;
else if ( V_192 )
V_126 = V_354 ;
else
V_126 = V_355 ;
#ifdef F_70
if ( V_144 == F_70
&& V_125 )
F_167 ( V_65 ) ;
#endif
F_168 ( & V_356 , V_65 , V_66 , V_144 , V_146 ,
V_126 , V_152 , V_142 ) ;
F_169 ( V_8 , V_189 ) ;
V_17 = 0 ;
V_196:
F_170 ( V_189 ) ;
F_171 ( V_109 ) ;
F_172 ( V_108 , F_113 ) ;
F_171 ( V_110 ) ;
F_173 ( V_99 ) ;
F_173 ( V_100 ) ;
F_174 ( V_105 , F_171 ) ;
F_174 ( V_106 , F_171 ) ;
F_4 ( V_120 ) ;
F_4 ( V_117 ) ;
F_4 ( V_65 ) ;
F_4 ( V_66 ) ;
F_175 ( V_111 ) ;
F_176 () ;
F_4 ( V_269 . V_65 ) ;
F_4 ( V_269 . V_66 ) ;
F_4 ( V_269 . V_67 ) ;
F_170 ( V_62 ) ;
F_171 ( V_155 ) ;
F_173 ( V_154 ) ;
#ifndef F_73
F_4 ( V_89 . V_87 ) ;
#endif
F_4 ( V_92 . V_87 ) ;
F_177 ( V_103 ) ;
F_178 ( V_104 ) ;
F_179 ( V_101 ) ;
F_180 ( V_8 ) ;
V_8 = NULL ;
F_180 ( V_274 ) ;
V_274 = NULL ;
#ifdef F_181
F_182 ( V_28 ) ;
#endif
return ( V_17 ) ;
}
static void F_169 ( T_4 * V_357 , T_26 * V_358 )
{
F_2 ( V_357 , L_75 ,
F_183 ( V_358 ) ) ;
F_2 ( V_357 , L_76 ,
F_184 ( V_358 ) ) ;
F_2 ( V_357 , L_77 ,
F_185 ( V_358 ) ) ;
F_2 ( V_357 , L_78 ,
F_186 ( V_358 ) ) ;
F_2 ( V_357 , L_79 ,
F_187 ( V_358 ) ) ;
F_2 ( V_357 , L_80 ,
F_188 ( V_358 ) ) ;
F_2 ( V_357 , L_81 ,
F_189 ( V_358 ) ) ;
F_2 ( V_357 , L_82 , F_190 ( V_358 ) ) ;
F_2 ( V_357 , L_83 ,
F_191 ( V_358 ) ) ;
F_2 ( V_357 , L_84 ,
F_192 ( V_358 ) ) ;
F_2 ( V_357 , L_85 ,
F_193 ( V_358 ) ) ;
F_2 ( V_357 , L_86 ,
F_194 ( V_358 ) ,
F_195 ( V_358 ) ) ;
}
static int V_355 ( int V_13 , int V_359 , unsigned char * V_152 )
{
char * V_53 = NULL ;
T_27 V_360 ;
int V_17 = 1 , V_361 ;
int V_362 , V_55 ;
unsigned long V_363 ;
T_1 * V_364 = NULL ;
T_4 * V_365 ;
struct V_366 V_85 ;
#if F_108 ( V_367 ) || F_108 ( V_368 )
struct V_366 V_369 ;
#else
struct V_366 * V_370 ;
#endif
V_53 = F_19 ( V_371 , L_87 ) ;
if ( V_190 ) {
if ( ! F_196 ( V_13 , 1 ) )
F_58 ( V_9 ) ;
else if ( ! V_93 )
F_2 ( V_9 , L_88 ) ;
}
if ( V_364 == NULL ) {
V_364 = F_197 ( V_189 ) ;
if ( V_266 ) {
F_198 ( V_364 , V_372 ) ;
F_199 ( V_364 , V_8 ) ;
}
if ( V_152
&& ! F_200 ( V_364 ,
V_152 , strlen ( ( char * ) V_152 ) ) ) {
F_2 ( V_9 , L_89 ) ;
V_17 = - 1 ;
goto V_21;
}
}
if ( ! F_201 ( V_364 ) ) {
F_2 ( V_9 , L_90 ) ;
V_17 = - 1 ;
goto V_21;
}
#ifndef F_97
if ( V_359 == V_303 ) {
V_365 = F_202 ( V_13 , V_373 ) ;
if ( V_309 ) {
V_85 . V_374 = 0 ;
V_85 . V_375 = V_376 ;
F_28 ( V_365 , V_377 , 0 , & V_85 ) ;
V_85 . V_374 = 0 ;
V_85 . V_375 = V_378 ;
F_28 ( V_365 , V_379 , 0 , & V_85 ) ;
}
if ( V_311 ) {
if ( V_311 < F_203 ( V_364 ) ) {
F_2 ( V_9 , L_91 ,
F_203 ( V_364 ) ) ;
V_17 = - 1 ;
F_180 ( V_365 ) ;
goto V_21;
}
F_204 ( V_364 , V_380 ) ;
if ( ! F_205 ( V_364 , V_311 ) ) {
F_2 ( V_9 , L_92 ) ;
V_17 = - 1 ;
F_180 ( V_365 ) ;
goto V_21;
}
} else
F_28 ( V_365 , V_381 , 0 , NULL ) ;
F_204 ( V_364 , V_382 ) ;
} else
#endif
V_365 = F_206 ( V_13 , V_373 ) ;
if ( V_191 ) {
T_4 * V_383 ;
V_383 = F_117 ( F_207 () ) ;
V_365 = F_208 ( V_383 , V_365 ) ;
}
F_209 ( V_364 , V_365 , V_365 ) ;
F_210 ( V_364 ) ;
if ( V_7 ) {
F_211 ( F_212 ( V_364 ) , V_384 ) ;
F_213 ( F_212 ( V_364 ) , ( char * ) V_8 ) ;
}
if ( V_193 ) {
#ifndef F_95
if ( V_193 == 2 )
F_214 ( V_364 , V_385 ) ;
else
#endif
F_214 ( V_364 , V_386 ) ;
F_215 ( V_364 , V_274 ? V_274 : V_8 ) ;
}
if ( V_266 ) {
F_198 ( V_364 , V_372 ) ;
F_199 ( V_364 , V_8 ) ;
}
V_361 = V_13 + 1 ;
for (; ; ) {
int V_387 ;
int V_388 ;
V_387 = 0 ;
V_388 = F_216 ( V_364 )
|| ( V_195 && F_217 ( V_364 ) ) ;
if ( ! V_388 ) {
F_218 ( & V_360 ) ;
#if ! F_108 ( V_367 ) && ! F_108 ( V_368 )
F_219 ( fileno ( V_389 ) , & V_360 ) ;
#endif
F_219 ( V_13 , & V_360 ) ;
#if F_108 ( V_367 ) || F_108 ( V_368 )
V_369 . V_374 = 1 ;
V_369 . V_375 = 0 ;
V_55 = F_220 ( V_361 , ( void * ) & V_360 , NULL , NULL , & V_369 ) ;
if ( F_221 () )
V_387 = 1 ;
if ( ( V_55 < 0 ) || ( ! V_55 && ! V_387 ) )
continue;
#else
if ( ( F_222 ( V_364 ) == V_305 ) &&
F_223 ( V_364 , & V_85 ) )
V_370 = & V_85 ;
else
V_370 = NULL ;
V_55 = F_220 ( V_361 , ( void * ) & V_360 , NULL , NULL , V_370 ) ;
if ( ( F_222 ( V_364 ) == V_305 )
&& F_224 ( V_364 ) > 0 ) {
F_2 ( V_9 , L_93 ) ;
}
if ( V_55 <= 0 )
continue;
if ( F_225 ( fileno ( V_389 ) , & V_360 ) )
V_387 = 1 ;
#endif
if ( F_225 ( V_13 , & V_360 ) )
V_388 = 1 ;
}
if ( V_387 ) {
if ( V_280 ) {
int V_390 , V_391 ;
V_55 = F_226 ( V_53 , V_371 / 2 ) ;
V_391 = 0 ;
for ( V_390 = 0 ; V_390 < V_55 ; V_390 ++ )
if ( V_53 [ V_390 ] == '\n' )
V_391 ++ ;
for ( V_390 = V_55 - 1 ; V_390 >= 0 ; V_390 -- ) {
V_53 [ V_390 + V_391 ] = V_53 [ V_390 ] ;
if ( V_53 [ V_390 ] == '\n' ) {
V_391 -- ;
V_55 ++ ;
V_53 [ V_390 + V_391 ] = '\r' ;
}
}
assert ( V_391 == 0 ) ;
} else
V_55 = F_226 ( V_53 , V_371 ) ;
if ( ! V_93 && ! V_194 ) {
if ( ( V_55 <= 0 ) || ( V_53 [ 0 ] == 'Q' ) ) {
F_2 ( V_8 , L_94 ) ;
( void ) F_5 ( V_8 ) ;
F_227 ( V_13 ) ;
F_228 () ;
V_17 = - 11 ;
goto V_21;
}
if ( ( V_55 <= 0 ) || ( V_53 [ 0 ] == 'q' ) ) {
F_2 ( V_8 , L_94 ) ;
( void ) F_5 ( V_8 ) ;
if ( F_222 ( V_364 ) != V_305 )
F_227 ( V_13 ) ;
goto V_21;
}
#ifndef F_229
if ( ( V_53 [ 0 ] == 'B' ) && ( ( V_53 [ 1 ] == '\n' ) || ( V_53 [ 1 ] == '\r' ) ) ) {
F_2 ( V_9 , L_95 ) ;
F_230 ( V_364 ) ;
V_55 = 0 ;
continue;
}
#endif
if ( ( V_53 [ 0 ] == 'r' ) && ( ( V_53 [ 1 ] == '\n' ) || ( V_53 [ 1 ] == '\r' ) ) ) {
F_231 ( V_364 ) ;
V_55 = F_232 ( V_364 ) ;
printf ( L_96 , V_55 ) ;
V_55 = 0 ;
continue;
}
if ( ( V_53 [ 0 ] == 'R' ) && ( ( V_53 [ 1 ] == '\n' ) || ( V_53 [ 1 ] == '\r' ) ) ) {
F_233 ( V_364 ,
V_214 | V_215 ,
NULL ) ;
F_231 ( V_364 ) ;
V_55 = F_232 ( V_364 ) ;
printf ( L_96 , V_55 ) ;
V_55 = 0 ;
continue;
}
if ( V_53 [ 0 ] == 'P' ) {
static const char * V_56 = L_97 ;
F_27 ( F_234 ( V_364 ) , V_56 , strlen ( V_56 ) ) ;
}
if ( V_53 [ 0 ] == 'S' ) {
F_169 ( V_8 , F_42 ( V_364 ) ) ;
}
}
#ifdef F_181
F_26 ( V_53 , V_53 , V_55 ) ;
#endif
V_363 = V_362 = 0 ;
for (; ; ) {
#ifdef F_235
static V_392 = 0 ;
if ( ++ V_392 == 100 ) {
V_392 = 0 ;
F_231 ( V_364 ) ;
}
#endif
V_362 = F_236 ( V_364 , & ( V_53 [ V_363 ] ) , ( unsigned int ) V_55 ) ;
#ifndef F_75
while ( F_237 ( V_364 , V_362 ) == V_393 ) {
F_2 ( V_8 , L_98 ) ;
F_9 ( V_350 . V_20 ) ;
V_350 . V_20 =
F_238 ( V_350 . V_351 ,
V_350 . V_19 ) ;
if ( V_350 . V_20 )
F_2 ( V_8 , L_99 ,
V_350 . V_20 -> V_25 ) ;
else
F_2 ( V_8 , L_100 ) ;
V_362 = F_236 ( V_364 , & ( V_53 [ V_363 ] ) , ( unsigned int ) V_55 ) ;
}
#endif
switch ( F_237 ( V_364 , V_362 ) ) {
case V_27 :
break;
case V_394 :
F_2 ( V_8 , L_101 ) ;
( void ) F_5 ( V_8 ) ;
F_239 ( V_364 ) ;
break;
case V_395 :
case V_396 :
case V_393 :
F_2 ( V_8 , L_102 ) ;
( void ) F_5 ( V_8 ) ;
break;
case V_397 :
case V_398 :
case V_399 :
F_2 ( V_8 , L_103 ) ;
( void ) F_5 ( V_8 ) ;
F_58 ( V_9 ) ;
V_17 = 1 ;
goto V_21;
case V_400 :
F_2 ( V_8 , L_94 ) ;
( void ) F_5 ( V_8 ) ;
V_17 = 1 ;
goto V_21;
}
if ( V_362 > 0 ) {
V_363 += V_362 ;
V_55 -= V_362 ;
}
if ( V_55 <= 0 )
break;
}
}
if ( V_388 ) {
if ( ( ! V_195 || ! F_217 ( V_364 ) )
&& ! F_240 ( V_364 ) ) {
V_55 = F_241 ( V_364 ) ;
if ( V_55 < 0 ) {
V_17 = 0 ;
goto V_21;
} else if ( V_55 == 0 ) {
V_17 = 1 ;
goto V_21;
}
} else {
V_401:
V_55 = F_242 ( V_364 , ( char * ) V_53 , V_371 ) ;
#ifndef F_75
while ( F_237 ( V_364 , V_55 ) == V_393 ) {
F_2 ( V_8 , L_104 ) ;
F_9 ( V_350 . V_20 ) ;
V_350 . V_20 =
F_238 ( V_350 . V_351 ,
V_350 . V_19 ) ;
if ( V_350 . V_20 )
F_2 ( V_8 , L_99 ,
V_350 . V_20 -> V_25 ) ;
else
F_2 ( V_8 , L_100 ) ;
V_55 = F_242 ( V_364 , ( char * ) V_53 , V_371 ) ;
}
#endif
switch ( F_237 ( V_364 , V_55 ) ) {
case V_27 :
#ifdef F_181
F_25 ( V_53 , V_53 , V_55 ) ;
#endif
F_243 ( V_53 , ( unsigned int ) V_55 ) ;
( void ) F_5 ( V_8 ) ;
if ( F_216 ( V_364 ) )
goto V_401;
break;
case V_394 :
F_2 ( V_8 , L_105 ) ;
( void ) F_5 ( V_8 ) ;
F_239 ( V_364 ) ;
break;
case V_395 :
case V_396 :
F_2 ( V_8 , L_106 ) ;
( void ) F_5 ( V_8 ) ;
break;
case V_397 :
case V_398 :
case V_399 :
F_2 ( V_8 , L_103 ) ;
( void ) F_5 ( V_8 ) ;
F_58 ( V_9 ) ;
V_17 = 1 ;
goto V_21;
case V_400 :
F_2 ( V_8 , L_94 ) ;
( void ) F_5 ( V_8 ) ;
V_17 = 1 ;
goto V_21;
}
}
}
}
V_21:
if ( V_364 != NULL ) {
F_2 ( V_8 , L_107 ) ;
F_244 ( V_364 , V_402 | V_403 ) ;
F_245 ( V_364 ) ;
}
F_2 ( V_8 , L_108 ) ;
F_246 ( V_53 , V_371 ) ;
if ( V_17 >= 0 )
F_2 ( V_8 , L_74 ) ;
( void ) F_5 ( V_8 ) ;
return ( V_17 ) ;
}
static void F_228 ( void )
{
F_2 ( V_9 , L_109 ) ;
if ( V_356 >= 0 ) {
F_227 ( V_356 ) ;
}
}
static int F_241 ( T_1 * V_364 )
{
int V_55 ;
const char * V_56 ;
T_8 * V_404 ;
long V_405 ;
char V_53 [ V_406 ] ;
#if ! F_108 ( F_73 )
const unsigned char * V_407 ;
unsigned V_408 ;
#endif
unsigned char * V_409 ;
int V_410 = 0 ;
#ifndef F_97
if ( V_313 ) {
T_28 * V_411 = NULL ;
if ( ( V_411 = F_247 () ) == NULL ) {
F_2 ( V_9 , L_110 ) ;
return 0 ;
}
V_55 = F_248 ( V_364 , V_411 ) ;
if ( V_55 > 0 ) {
T_4 * V_412 ;
int V_413 = - 1 ;
V_412 = F_234 ( V_364 ) ;
if ( V_412 ) {
F_249 ( V_412 , & V_413 ) ;
}
if ( ! V_412 || F_250 ( V_413 , V_411 , 0 ) == 0 ) {
F_2 ( V_9 , L_111 ) ;
F_251 ( V_411 ) ;
return 0 ;
}
F_251 ( V_411 ) ;
V_313 = 0 ;
V_55 = F_252 ( V_364 ) ;
} else {
F_251 ( V_411 ) ;
}
} else
#endif
do {
V_55 = F_252 ( V_364 ) ;
if ( V_55 <= 0 )
V_410 = F_253 ( V_55 ) ;
#ifdef F_254
{
while ( V_55 <= 0
&& F_237 ( V_364 , V_55 ) == V_393
&& F_255 ( V_364 ) == V_414 ) {
F_2 ( V_9 ,
L_112 ) ;
V_55 = F_252 ( V_364 ) ;
if ( V_55 <= 0 )
V_410 = F_253 ( V_55 ) ;
}
}
#endif
#ifndef F_75
while ( V_55 <= 0
&& F_237 ( V_364 , V_55 ) == V_393 ) {
F_2 ( V_8 , L_113 ,
V_350 . V_19 ) ;
F_9 ( V_350 . V_20 ) ;
V_350 . V_20 =
F_238 ( V_350 . V_351 ,
V_350 . V_19 ) ;
if ( V_350 . V_20 )
F_2 ( V_8 , L_99 ,
V_350 . V_20 -> V_25 ) ;
else
F_2 ( V_8 , L_100 ) ;
V_55 = F_252 ( V_364 ) ;
if ( V_55 <= 0 )
V_410 = F_253 ( V_55 ) ;
}
#endif
} while ( V_55 < 0 && F_217 ( V_364 ) );
if ( V_55 <= 0 ) {
if ( ( V_313 && V_55 == 0 )
|| ( ! V_313 && V_410 ) ) {
F_2 ( V_8 , L_114 ) ;
return ( 1 ) ;
}
F_2 ( V_9 , L_103 ) ;
V_405 = F_256 ( V_364 ) ;
if ( V_405 != V_415 ) {
F_2 ( V_9 , L_115 ,
F_257 ( V_405 ) ) ;
}
F_58 ( V_9 ) ;
return ( 0 ) ;
}
if ( V_194 )
F_258 ( V_364 ) ;
F_259 ( V_8 , F_260 ( V_364 ) ) ;
V_404 = F_261 ( V_364 ) ;
if ( V_404 != NULL ) {
F_2 ( V_8 , L_116 ) ;
F_262 ( V_8 , V_404 ) ;
F_263 ( F_264 ( V_404 ) , V_53 , sizeof V_53 ) ;
F_2 ( V_8 , L_117 , V_53 ) ;
F_263 ( F_44 ( V_404 ) , V_53 , sizeof V_53 ) ;
F_2 ( V_8 , L_118 , V_53 ) ;
F_171 ( V_404 ) ;
V_404 = NULL ;
}
if ( F_265 ( V_364 , V_53 , sizeof V_53 ) != NULL )
F_2 ( V_8 , L_119 , V_53 ) ;
V_56 = F_266 ( F_267 ( V_364 ) ) ;
F_268 ( V_8 , V_364 ) ;
#ifndef V_340
F_269 ( V_8 , V_364 ) ;
F_270 ( V_8 , V_364 , 0 ) ;
#endif
F_2 ( V_8 , L_120 , ( V_56 != NULL ) ? V_56 : L_121 ) ;
#if ! F_108 ( F_73 )
F_271 ( V_364 , & V_407 , & V_408 ) ;
if ( V_407 ) {
F_2 ( V_8 , L_122 ) ;
F_27 ( V_8 , V_407 , V_408 ) ;
F_2 ( V_8 , L_28 ) ;
}
#endif
#ifndef F_100
{
T_29 * V_416
= F_272 ( V_364 ) ;
if ( V_416 )
F_2 ( V_8 , L_123 ,
V_416 -> V_417 ) ;
}
#endif
if ( F_273 ( V_364 ) )
F_2 ( V_8 , L_124 ) ;
F_2 ( V_8 , L_125 ,
F_274 ( V_364 ) ? L_126 : L_127 ) ;
if ( V_327 != NULL ) {
F_2 ( V_8 , L_128 ) ;
F_2 ( V_8 , L_129 , V_327 ) ;
F_2 ( V_8 , L_130 , V_329 ) ;
V_409 = F_19 ( V_329 , L_131 ) ;
if ( ! F_275 ( V_364 , V_409 ,
V_329 ,
V_327 ,
strlen ( V_327 ) ,
NULL , 0 , 0 ) ) {
F_2 ( V_8 , L_132 ) ;
} else {
F_2 ( V_8 , L_133 ) ;
for ( V_55 = 0 ; V_55 < V_329 ; V_55 ++ )
F_2 ( V_8 , L_134 , V_409 [ V_55 ] ) ;
F_2 ( V_8 , L_28 ) ;
}
F_4 ( V_409 ) ;
}
( void ) F_5 ( V_8 ) ;
return ( 1 ) ;
}
static T_25 * F_144 ( const char * V_131 )
{
T_25 * V_17 = NULL ;
T_4 * V_357 ;
if ( ( V_357 = F_94 ( V_131 , L_135 ) ) == NULL )
goto V_21;
V_17 = F_276 ( V_357 , NULL , NULL , NULL ) ;
V_21:
F_180 ( V_357 ) ;
return ( V_17 ) ;
}
static int V_354 ( int V_13 , int V_359 , unsigned char * V_152 )
{
char * V_53 = NULL ;
int V_17 = 1 ;
int V_55 , V_390 , V_362 , V_418 ;
T_1 * V_364 ;
const T_30 * V_419 ;
T_4 * V_420 , * V_421 , * V_365 ;
#ifdef F_235
int V_422 = 0 ;
#endif
int V_361 ;
T_27 V_360 ;
V_361 = V_13 + 1 ;
V_53 = F_19 ( V_371 , L_136 ) ;
V_420 = F_117 ( F_277 () ) ;
V_421 = F_117 ( F_278 () ) ;
if ( ( V_420 == NULL ) || ( V_421 == NULL ) )
goto V_21;
if ( V_190 ) {
if ( ! F_196 ( V_13 , 1 ) )
F_58 ( V_9 ) ;
else if ( ! V_93 )
F_2 ( V_9 , L_88 ) ;
}
if ( ! F_279 ( V_420 , V_371 ) )
goto V_21;
if ( ( V_364 = F_197 ( V_189 ) ) == NULL )
goto V_21;
if ( V_266 ) {
F_198 ( V_364 , V_372 ) ;
F_199 ( V_364 , V_8 ) ;
}
if ( V_152
&& ! F_200 ( V_364 , V_152 ,
strlen ( ( char * ) V_152 ) ) )
goto V_21;
V_365 = F_206 ( V_13 , V_373 ) ;
if ( V_191 ) {
T_4 * V_383 ;
V_383 = F_117 ( F_207 () ) ;
V_365 = F_208 ( V_383 , V_365 ) ;
}
F_209 ( V_364 , V_365 , V_365 ) ;
F_210 ( V_364 ) ;
F_280 ( V_421 , V_364 , V_423 ) ;
F_208 ( V_420 , V_421 ) ;
#ifdef F_181
V_420 = F_208 ( F_117 ( F_10 () ) , V_420 ) ;
#endif
if ( V_7 ) {
F_211 ( F_212 ( V_364 ) , V_384 ) ;
F_213 ( F_212 ( V_364 ) , ( char * ) V_8 ) ;
}
if ( V_193 ) {
#ifndef F_95
if ( V_193 == 2 )
F_214 ( V_364 , V_385 ) ;
else
#endif
F_214 ( V_364 , V_386 ) ;
F_215 ( V_364 , V_274 ? V_274 : V_8 ) ;
}
for (; ; ) {
V_55 = F_281 ( V_420 , V_53 , V_371 - 1 ) ;
if ( V_55 < 0 ) {
if ( ! F_282 ( V_420 ) && ! F_217 ( V_364 ) ) {
if ( ! V_93 )
F_58 ( V_9 ) ;
goto V_21;
} else {
F_2 ( V_8 , L_137 ) ;
#ifndef F_75
if ( F_283 ( V_420 )
&& F_284 ( V_420 ) == V_424 ) {
F_2 ( V_8 , L_104 ) ;
F_9 ( V_350 . V_20 ) ;
V_350 . V_20 =
F_238 ( V_350 . V_351 ,
V_350 . V_19 ) ;
if ( V_350 . V_20 )
F_2 ( V_8 , L_99 ,
V_350 . V_20 -> V_25 ) ;
else
F_2 ( V_8 , L_100 ) ;
continue;
}
#endif
#if ! F_108 ( V_368 )
F_285 ( 1 ) ;
#endif
continue;
}
} else if ( V_55 == 0 ) {
V_17 = 1 ;
goto V_196;
}
if ( ( ( V_192 == 1 ) && ( strncmp ( L_138 , V_53 , 4 ) == 0 ) ) ||
( ( V_192 == 2 ) && ( strncmp ( L_139 , V_53 , 11 ) == 0 ) ) ) {
char * V_16 ;
T_8 * V_404 = NULL ;
F_33 ( T_30 ) * V_425 ;
static const char * V_426 = L_140 ;
if ( V_192 == 1 && strncmp ( L_141 , V_53 , 10 ) == 0 ) {
if ( strncmp ( L_142 , V_53 , 14 ) == 0 )
F_233 ( V_364 ,
V_214 | V_215 ,
NULL ) ;
V_55 = F_231 ( V_364 ) ;
F_2 ( V_8 , L_143 , V_55 ) ;
V_55 = F_232 ( V_364 ) ;
if ( V_55 <= 0 ) {
F_2 ( V_8 , L_144 ,
F_237 ( V_364 , V_55 ) ) ;
F_58 ( V_9 ) ;
goto V_21;
}
F_218 ( & V_360 ) ;
F_219 ( V_13 , & V_360 ) ;
V_55 = F_220 ( V_361 , ( void * ) & V_360 , NULL , NULL , NULL ) ;
if ( V_55 <= 0 || ! F_225 ( V_13 , & V_360 ) ) {
F_2 ( V_8 ,
L_145 ) ;
F_58 ( V_9 ) ;
goto V_21;
}
F_281 ( V_420 , V_53 , V_371 - 1 ) ;
}
F_34 ( V_420 ,
L_146 ) ;
F_34 ( V_420 , L_147 ) ;
F_34 ( V_420 , L_148 ) ;
F_34 ( V_420 , L_28 ) ;
for ( V_55 = 0 ; V_55 < V_187 ; V_55 ++ ) {
const char * V_427 ;
for ( V_427 = V_188 [ V_55 ] ; * V_427 ; V_427 ++ )
switch ( * V_427 ) {
case '<' :
F_34 ( V_420 , L_149 ) ;
break;
case '>' :
F_34 ( V_420 , L_150 ) ;
break;
case '&' :
F_34 ( V_420 , L_151 ) ;
break;
default:
F_27 ( V_420 , V_427 , 1 ) ;
break;
}
F_27 ( V_420 , L_152 , 1 ) ;
}
F_34 ( V_420 , L_28 ) ;
F_2 ( V_420 ,
L_125 ,
F_274 ( V_364 ) ?
L_126 : L_127 ) ;
F_2 ( V_420 , L_153 ) ;
V_425 = F_286 ( V_364 ) ;
V_390 = F_287 ( V_425 ) ;
for ( V_55 = 0 ; V_55 < V_390 ; V_55 ++ ) {
V_419 = F_288 ( V_425 , V_55 ) ;
F_2 ( V_420 , L_154 ,
F_289 ( V_419 ) , F_266 ( V_419 ) ) ;
if ( ( ( ( V_55 + 1 ) % 2 ) == 0 ) && ( V_55 + 1 != V_390 ) )
F_34 ( V_420 , L_28 ) ;
}
F_34 ( V_420 , L_28 ) ;
V_16 = F_265 ( V_364 , V_53 , V_371 ) ;
if ( V_16 != NULL ) {
F_2 ( V_420 ,
L_155 ) ;
V_390 = V_55 = 0 ;
while ( * V_16 ) {
if ( * V_16 == ':' ) {
F_27 ( V_420 , V_426 , 26 - V_390 ) ;
V_55 ++ ;
V_390 = 0 ;
F_27 ( V_420 , ( ( V_55 % 3 ) ? L_152 : L_28 ) , 1 ) ;
} else {
F_27 ( V_420 , V_16 , 1 ) ;
V_390 ++ ;
}
V_16 ++ ;
}
F_34 ( V_420 , L_28 ) ;
}
F_268 ( V_420 , V_364 ) ;
#ifndef V_340
F_270 ( V_420 , V_364 , 0 ) ;
#endif
F_2 ( V_420 , ( F_273 ( V_364 )
? L_156 : L_157 ) ) ;
V_419 = F_267 ( V_364 ) ;
F_2 ( V_420 , L_158 ,
F_289 ( V_419 ) , F_266 ( V_419 ) ) ;
F_290 ( V_420 , F_260 ( V_364 ) ) ;
F_2 ( V_420 , L_159 ) ;
F_169 ( V_420 , F_42 ( V_364 ) ) ;
F_2 ( V_420 , L_159 ) ;
V_404 = F_261 ( V_364 ) ;
if ( V_404 != NULL ) {
F_2 ( V_420 , L_116 ) ;
F_291 ( V_420 , V_404 ) ;
F_262 ( V_420 , V_404 ) ;
F_171 ( V_404 ) ;
V_404 = NULL ;
} else
F_34 ( V_420 , L_160 ) ;
F_34 ( V_420 , L_161 ) ;
break;
} else if ( ( V_192 == 2 || V_192 == 3 )
&& ( strncmp ( L_162 , V_53 , 5 ) == 0 ) ) {
T_4 * V_428 ;
char * V_16 , * V_429 ;
static const char * V_430 =
L_163 ;
V_16 = & ( V_53 [ 5 ] ) ;
V_418 = 1 ;
for ( V_429 = V_16 ; * V_429 != '\0' ; V_429 ++ ) {
if ( V_429 [ 0 ] == ' ' )
break;
switch ( V_418 ) {
case 1 :
V_418 = ( V_429 [ 0 ] == '.' ) ? 2 : 0 ;
break;
case 2 :
V_418 = ( V_429 [ 0 ] == '.' ) ? 3 : 0 ;
break;
case 3 :
V_418 = ( V_429 [ 0 ] == '/' ) ? - 1 : 0 ;
break;
}
if ( V_418 == 0 )
V_418 = ( V_429 [ 0 ] == '/' ) ? 1 : 0 ;
}
V_418 = ( V_418 == 3 ) || ( V_418 == - 1 ) ;
if ( * V_429 == '\0' ) {
F_34 ( V_420 , V_430 ) ;
F_2 ( V_420 , L_164 , V_16 ) ;
break;
}
* V_429 = '\0' ;
if ( V_418 ) {
F_34 ( V_420 , V_430 ) ;
F_2 ( V_420 , L_165 , V_16 ) ;
break;
}
if ( * V_16 == '/' ) {
F_34 ( V_420 , V_430 ) ;
F_2 ( V_420 , L_166 , V_16 ) ;
break;
}
if ( F_292 ( V_16 ) > 0 ) {
F_34 ( V_420 , V_430 ) ;
F_2 ( V_420 , L_167 , V_16 ) ;
break;
}
if ( ( V_428 = F_94 ( V_16 , L_135 ) ) == NULL ) {
F_34 ( V_420 , V_430 ) ;
F_2 ( V_420 , L_168 , V_16 ) ;
F_58 ( V_420 ) ;
break;
}
if ( ! V_93 )
F_2 ( V_9 , L_169 , V_16 ) ;
if ( V_192 == 2 ) {
V_55 = strlen ( V_16 ) ;
if ( ( ( V_55 > 5 ) && ( strcmp ( & ( V_16 [ V_55 - 5 ] ) , L_170 ) == 0 ) ) ||
( ( V_55 > 4 ) && ( strcmp ( & ( V_16 [ V_55 - 4 ] ) , L_171 ) == 0 ) ) ||
( ( V_55 > 4 ) && ( strcmp ( & ( V_16 [ V_55 - 4 ] ) , L_172 ) == 0 ) ) )
F_34 ( V_420 ,
L_146 ) ;
else
F_34 ( V_420 ,
L_163 ) ;
}
for (; ; ) {
V_55 = F_24 ( V_428 , V_53 , V_371 ) ;
if ( V_55 <= 0 )
break;
#ifdef F_235
V_422 += V_55 ;
F_2 ( V_9 , L_173 , V_55 ) ;
if ( V_422 > 3 * 1024 ) {
V_422 = 0 ;
F_2 ( V_9 , L_174 ) ;
F_231 ( V_364 ) ;
}
#endif
for ( V_390 = 0 ; V_390 < V_55 ; ) {
#ifdef F_235
static V_392 = 0 ;
if ( ++ V_392 == 13 ) {
F_231 ( V_364 ) ;
}
#endif
V_362 = F_27 ( V_420 , & ( V_53 [ V_390 ] ) , V_55 - V_390 ) ;
if ( V_362 <= 0 ) {
if ( ! F_282 ( V_420 )
&& ! F_217 ( V_364 ) )
goto V_431;
else {
F_2 ( V_8 , L_175 ) ;
}
} else {
V_390 += V_362 ;
}
}
}
V_431:
F_180 ( V_428 ) ;
break;
}
}
for (; ; ) {
V_55 = ( int ) F_5 ( V_420 ) ;
if ( V_55 <= 0 ) {
if ( ! F_282 ( V_420 ) )
break;
} else
break;
}
V_196:
F_244 ( V_364 , V_402 | V_403 ) ;
V_21:
if ( V_17 >= 0 )
F_2 ( V_8 , L_74 ) ;
F_4 ( V_53 ) ;
F_293 ( V_420 ) ;
return ( V_17 ) ;
}
static int V_353 ( int V_13 , int V_359 , unsigned char * V_152 )
{
char * V_53 = NULL ;
int V_55 ;
int V_17 = 1 ;
T_1 * V_364 ;
T_4 * V_420 , * V_421 , * V_365 ;
V_53 = F_19 ( V_371 , L_176 ) ;
V_420 = F_117 ( F_277 () ) ;
V_421 = F_117 ( F_278 () ) ;
if ( ( V_420 == NULL ) || ( V_421 == NULL ) )
goto V_21;
if ( ! F_279 ( V_420 , V_371 ) )
goto V_21;
if ( ( V_364 = F_197 ( V_189 ) ) == NULL )
goto V_21;
if ( V_266 ) {
F_198 ( V_364 , V_372 ) ;
F_199 ( V_364 , V_8 ) ;
}
if ( V_152
&& ! F_200 ( V_364 , V_152 ,
strlen ( ( char * ) V_152 ) ) ) {
F_58 ( V_9 ) ;
goto V_21;
}
V_365 = F_206 ( V_13 , V_373 ) ;
F_209 ( V_364 , V_365 , V_365 ) ;
F_210 ( V_364 ) ;
F_280 ( V_421 , V_364 , V_423 ) ;
F_208 ( V_420 , V_421 ) ;
#ifdef F_181
V_420 = F_208 ( F_117 ( F_10 () ) , V_420 ) ;
#endif
if ( V_7 ) {
F_211 ( F_212 ( V_364 ) , V_384 ) ;
F_213 ( F_212 ( V_364 ) , ( char * ) V_8 ) ;
}
if ( V_193 ) {
#ifndef F_95
if ( V_193 == 2 )
F_214 ( V_364 , V_385 ) ;
else
#endif
F_214 ( V_364 , V_386 ) ;
F_215 ( V_364 , V_274 ? V_274 : V_8 ) ;
}
for (; ; ) {
V_55 = F_294 ( V_420 ) ;
if ( V_55 > 0 )
break;
if ( ! F_282 ( V_420 ) ) {
F_34 ( V_9 , L_177 ) ;
F_58 ( V_9 ) ;
goto V_196;
}
#ifndef F_75
if ( F_283 ( V_420 )
&& F_284 ( V_420 ) == V_424 ) {
F_2 ( V_8 , L_178 ) ;
F_9 ( V_350 . V_20 ) ;
V_350 . V_20 =
F_238 ( V_350 . V_351 ,
V_350 . V_19 ) ;
if ( V_350 . V_20 )
F_2 ( V_8 , L_99 ,
V_350 . V_20 -> V_25 ) ;
else
F_2 ( V_8 , L_100 ) ;
continue;
}
#endif
}
F_2 ( V_9 , L_179 ) ;
F_258 ( V_364 ) ;
for (; ; ) {
V_55 = F_281 ( V_420 , V_53 , V_371 - 1 ) ;
if ( V_55 < 0 ) {
if ( ! F_282 ( V_420 ) ) {
if ( ! V_93 )
F_58 ( V_9 ) ;
goto V_21;
} else {
F_2 ( V_8 , L_137 ) ;
#ifndef F_75
if ( F_283 ( V_420 )
&& F_284 ( V_420 ) == V_424 ) {
F_2 ( V_8 , L_104 ) ;
F_9 ( V_350 . V_20 ) ;
V_350 . V_20 =
F_238 ( V_350 . V_351 ,
V_350 . V_19 ) ;
if ( V_350 . V_20 )
F_2 ( V_8 , L_99 ,
V_350 . V_20 -> V_25 ) ;
else
F_2 ( V_8 , L_100 ) ;
continue;
}
#endif
#if ! F_108 ( V_368 )
F_285 ( 1 ) ;
#endif
continue;
}
} else if ( V_55 == 0 ) {
V_17 = 1 ;
F_2 ( V_9 , L_108 ) ;
goto V_196;
} else {
char * V_16 = V_53 + V_55 - 1 ;
while ( V_55 && ( * V_16 == '\n' || * V_16 == '\r' ) ) {
V_16 -- ;
V_55 -- ;
}
if ( ! V_262 && ( V_55 == 5 ) && ( strncmp ( V_53 , L_180 , 5 ) == 0 ) ) {
V_17 = 1 ;
F_2 ( V_9 , L_108 ) ;
goto V_196;
}
F_295 ( ( unsigned char * ) V_53 , NULL , V_55 ) ;
V_53 [ V_55 ] = '\n' ;
F_27 ( V_420 , V_53 , V_55 + 1 ) ;
for (; ; ) {
V_55 = F_5 ( V_420 ) ;
if ( V_55 > 0 )
break;
if ( ! F_282 ( V_420 ) )
goto V_196;
}
}
}
V_196:
F_244 ( V_364 , V_402 | V_403 ) ;
V_21:
F_4 ( V_53 ) ;
F_293 ( V_420 ) ;
return ( V_17 ) ;
}
static int V_341 ( const T_1 * V_1 , unsigned char * V_78 ,
unsigned int * V_432 )
{
unsigned int V_392 = 0 ;
do {
if ( F_296 ( V_78 , * V_432 ) <= 0 )
return 0 ;
memcpy ( V_78 , V_315 ,
( strlen ( V_315 ) < * V_432 ) ?
strlen ( V_315 ) : * V_432 ) ;
}
while ( F_297 ( V_1 , V_78 , * V_432 ) &&
( ++ V_392 < V_433 ) );
if ( V_392 >= V_433 )
return 0 ;
return 1 ;
}
static int F_298 ( T_1 * V_1 , T_31 * V_434 )
{
T_32 * V_435 = F_19 ( sizeof( * V_435 ) , L_181 ) ;
unsigned char * V_16 ;
F_299 ( V_434 , & V_435 -> V_436 ) ;
V_435 -> V_437 = F_300 ( V_434 , NULL ) ;
if ( V_435 -> V_437 < 0 ) {
F_2 ( V_9 , L_182 ) ;
F_4 ( V_435 ) ;
return 0 ;
}
V_435 -> V_78 = F_301 ( F_299 ( V_434 , NULL ) , V_435 -> V_436 ) ;
V_435 -> V_438 = F_19 ( V_435 -> V_437 , L_183 ) ;
if ( ! V_435 -> V_78 ) {
F_2 ( V_9 , L_184 ) ;
F_4 ( V_435 -> V_78 ) ;
F_4 ( V_435 -> V_438 ) ;
F_4 ( V_435 ) ;
return 0 ;
}
V_16 = V_435 -> V_438 ;
if ( F_300 ( V_434 , & V_16 ) != V_435 -> V_437 ) {
F_2 ( V_9 , L_185 ) ;
F_4 ( V_435 -> V_78 ) ;
F_4 ( V_435 -> V_438 ) ;
F_4 ( V_435 ) ;
return 0 ;
}
V_435 -> V_45 = V_439 ;
V_439 = V_435 ;
F_2 ( V_9 , L_186 ) ;
return 0 ;
}
static T_31 * F_302 ( T_1 * V_1 , const unsigned char * V_78 , int V_436 ,
int * V_440 )
{
T_32 * V_435 ;
* V_440 = 0 ;
for ( V_435 = V_439 ; V_435 ; V_435 = V_435 -> V_45 ) {
if ( V_436 == ( int ) V_435 -> V_436 && ! memcmp ( V_435 -> V_78 , V_78 , V_436 ) ) {
const unsigned char * V_16 = V_435 -> V_438 ;
F_2 ( V_9 , L_187 ) ;
return F_303 ( NULL , & V_16 , V_435 -> V_437 ) ;
}
}
F_2 ( V_9 , L_188 ) ;
return NULL ;
}
static void F_304 ( T_26 * V_441 , T_31 * V_434 )
{
T_32 * V_435 , * V_442 = NULL ;
const unsigned char * V_78 ;
unsigned int V_436 ;
V_78 = F_299 ( V_434 , & V_436 ) ;
for ( V_435 = V_439 ; V_435 ; V_435 = V_435 -> V_45 ) {
if ( V_436 == V_435 -> V_436 && ! memcmp ( V_435 -> V_78 , V_78 , V_436 ) ) {
if ( V_442 )
V_442 -> V_45 = V_435 -> V_45 ;
else
V_439 = V_435 -> V_45 ;
F_4 ( V_435 -> V_78 ) ;
F_4 ( V_435 -> V_438 ) ;
F_4 ( V_435 ) ;
return;
}
V_442 = V_435 ;
}
}
static void F_130 ( T_26 * V_441 )
{
F_129 ( V_441 ,
V_443 |
V_444 ) ;
F_305 ( V_441 , F_298 ) ;
F_306 ( V_441 , F_302 ) ;
F_307 ( V_441 , F_304 ) ;
}
static void F_176 ( void )
{
T_32 * V_435 , * V_445 ;
for ( V_435 = V_439 ; V_435 ; ) {
F_4 ( V_435 -> V_78 ) ;
F_4 ( V_435 -> V_438 ) ;
V_445 = V_435 ;
V_435 = V_435 -> V_45 ;
F_4 ( V_445 ) ;
}
V_439 = NULL ;
}
