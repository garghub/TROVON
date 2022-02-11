static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
static inline struct V_6 * F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_7 ;
}
static inline struct V_8 * F_3 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_9 ;
}
static inline struct V_10 * F_4 ( struct V_1 * V_11 )
{
return V_11 -> V_3 -> V_12 ;
}
static inline struct V_13 * F_5 ( struct V_1 * V_11 )
{
return V_11 -> V_3 -> V_14 ;
}
static inline struct V_15 * F_6 ( struct V_2 * V_3 )
{
return V_3 -> V_16 -> V_17 ;
}
static inline int F_7 ( const struct V_18 * V_19 )
{
return ( V_19 -> V_20 <= V_21 ) ;
}
static inline unsigned int F_8 ( unsigned int V_22 )
{
V_22 -- ;
return ( 3 * V_22 ) / 2 + ( V_22 & 1 ) + 2 ;
}
static void F_9 ( struct V_23 * V_24 , T_1 * V_25 , int * V_26 )
{
T_1 V_27 [ V_28 ] ;
struct V_29 * V_30 = F_10 ( V_24 ) ;
int V_31 = F_11 ( V_30 ) ;
struct V_32 * V_33 ;
int V_34 = 0 ;
V_33 = (struct V_32 * ) V_25 ;
if ( ( F_12 ( V_30 ) == V_35 ) ||
( F_12 ( V_30 ) == V_36 ) ) {
V_34 = F_13 ( & V_33 -> V_37 [ 2 ] , ( V_33 + 1 ) , V_31 ) ;
} else {
F_14 ( V_24 -> V_38 , F_15 ( V_24 -> V_38 ) , V_27 ,
V_31 , V_24 -> V_39 +
V_24 -> V_40 - V_31 ) ;
V_34 = F_13 ( V_27 , ( V_33 + 1 ) , V_31 ) ;
}
if ( V_34 )
* V_26 = - V_41 ;
else
* V_26 = 0 ;
}
int F_16 ( struct V_42 * V_24 , unsigned char * V_25 ,
int V_26 )
{
struct V_43 * V_30 = V_24 -> V_30 ;
struct V_2 * V_3 = F_17 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_44 V_45 ;
unsigned int V_46 , V_47 ;
struct V_48 * V_49 = F_18 ( V_3 -> V_16 ) ;
switch ( V_30 -> V_50 -> V_51 & V_52 ) {
case V_53 :
V_45 . V_24 . V_54 = F_19 ( V_24 ) ;
V_45 . V_3 . V_55 = F_20 ( V_45 . V_24 . V_54 ) ;
F_21 ( & V_17 -> V_56 . V_57 -> V_16 , V_45 . V_3 . V_55 -> V_58 ,
V_45 . V_3 . V_55 -> V_59 , V_60 ) ;
if ( V_45 . V_3 . V_55 -> V_19 ) {
F_22 ( V_45 . V_3 . V_55 -> V_19 ) ;
V_45 . V_3 . V_55 -> V_19 = NULL ;
}
F_23 ( V_45 . V_3 . V_55 -> V_61 ) ;
V_45 . V_3 . V_55 -> V_61 = NULL ;
if ( V_45 . V_3 . V_55 -> V_62 == V_63 ) {
F_9 ( V_45 . V_24 . V_54 , V_25 ,
& V_26 ) ;
V_45 . V_3 . V_55 -> V_62 = V_64 ;
}
V_45 . V_24 . V_54 -> V_65 . V_66 ( V_24 , V_26 ) ;
break;
case V_67 :
V_26 = F_24 ( F_25 ( V_24 ) ,
V_25 , V_26 ) ;
break;
case V_68 :
V_45 . V_24 . V_69 = F_26 ( V_24 ) ;
V_45 . V_3 . V_70 =
F_27 ( V_45 . V_24 . V_69 ) ;
V_46 =
F_28 ( F_29 (
V_45 . V_24 . V_69 ) ) ;
V_47 = V_46 ;
if ( V_46 == V_71 )
V_47 = V_72 ;
else if ( V_46 == V_73 )
V_47 = V_28 ;
if ( V_45 . V_3 . V_70 -> V_19 ) {
F_22 ( V_45 . V_3 . V_70 -> V_19 ) ;
V_45 . V_3 . V_70 -> V_19 = NULL ;
}
if ( V_45 . V_3 . V_70 -> V_74 == 1 ) {
V_45 . V_3 . V_70 -> V_74 = 0 ;
memcpy ( V_45 . V_24 . V_69 -> V_74 , V_25 +
sizeof( struct V_32 ) ,
V_46 ) ;
} else {
memcpy ( V_45 . V_3 . V_70 -> V_75 , V_25 +
sizeof( struct V_32 ) ,
V_47 ) ;
}
V_45 . V_24 . V_69 -> V_65 . V_66 ( V_24 , V_26 ) ;
break;
}
F_30 ( & V_49 -> V_76 . V_66 ) ;
return V_26 ;
}
static inline unsigned int F_31 ( const struct V_18 * V_19 )
{
unsigned int V_77 , V_78 ;
if ( F_7 ( V_19 ) )
return F_32 ( V_19 -> V_20 , 8 ) ;
V_77 = F_33 ( V_19 ) / 8 ;
V_78 = F_34 ( V_19 ) -> V_79 ;
if ( F_35 ( V_19 ) != F_36 ( V_19 ) )
V_78 ++ ;
return V_77 + F_8 ( V_78 ) ;
}
static inline void F_37 ( unsigned char * V_80 ,
const unsigned char * V_81 ,
unsigned int V_82 )
{
T_2 V_27 ;
T_2 V_83 [ V_84 ] ;
int V_85 , V_86 , V_87 ;
T_1 V_88 , V_89 ;
switch ( V_82 ) {
case V_90 :
V_89 = V_91 ;
V_88 = V_92 ;
break;
case V_93 :
V_89 = V_94 ;
V_88 = V_95 ;
break;
case V_96 :
V_89 = V_97 ;
V_88 = V_98 ;
break;
default:
return;
}
for ( V_85 = 0 ; V_85 < V_89 ; V_85 ++ )
V_83 [ V_85 ] = F_38 ( * ( T_2 * ) & V_81 [ 4 * V_85 ] ) ;
V_85 = 0 ;
V_27 = V_83 [ V_89 - 1 ] ;
while ( V_85 + V_89 < ( V_88 + 1 ) * 4 ) {
if ( ! ( V_85 % V_89 ) ) {
V_27 = ( V_27 << 8 ) | ( V_27 >> 24 ) ;
V_27 = F_39 ( V_27 ) ;
V_27 ^= V_99 [ V_85 / V_89 ] ;
} else if ( V_89 == 8 && ( V_85 % 4 == 0 ) ) {
V_27 = F_39 ( V_27 ) ;
}
V_83 [ V_85 % V_89 ] ^= V_27 ;
V_27 = V_83 [ V_85 % V_89 ] ;
V_85 ++ ;
}
V_85 -- ;
for ( V_87 = 0 , V_86 = V_85 % V_89 ; V_87 < V_89 ; V_87 ++ ) {
* ( ( T_2 * ) V_80 + V_87 ) = F_40 ( V_83 [ V_86 ] ) ;
V_86 -- ;
if ( V_86 < 0 )
V_86 += V_89 ;
}
}
static struct V_100 * F_41 ( unsigned int V_101 )
{
struct V_100 * V_102 = F_42 ( - V_103 ) ;
switch ( V_101 ) {
case V_104 :
V_102 = F_43 ( L_1 , 0 , 0 ) ;
break;
case V_71 :
V_102 = F_43 ( L_2 , 0 , 0 ) ;
break;
case V_72 :
V_102 = F_43 ( L_3 , 0 , 0 ) ;
break;
case V_73 :
V_102 = F_43 ( L_4 , 0 , 0 ) ;
break;
case V_28 :
V_102 = F_43 ( L_5 , 0 , 0 ) ;
break;
}
return V_102 ;
}
static int F_44 ( struct V_105 * V_106 ,
char * V_107 , char * V_108 ,
int V_109 )
{
struct V_110 V_111 ;
struct V_112 V_113 ;
struct V_114 V_115 ;
int error ;
if ( V_109 == V_104 ) {
error = F_45 ( V_106 ) ? :
F_46 ( V_106 , V_107 , V_116 ) ? :
F_47 ( V_106 , ( void * ) & V_111 ) ;
memcpy ( V_108 , V_111 . V_117 , V_104 ) ;
} else if ( V_109 == V_71 ) {
error = F_45 ( V_106 ) ? :
F_46 ( V_106 , V_107 , V_118 ) ? :
F_47 ( V_106 , ( void * ) & V_113 ) ;
memcpy ( V_108 , V_113 . V_117 , V_72 ) ;
} else if ( V_109 == V_72 ) {
error = F_45 ( V_106 ) ? :
F_46 ( V_106 , V_107 , V_118 ) ? :
F_47 ( V_106 , ( void * ) & V_113 ) ;
memcpy ( V_108 , V_113 . V_117 , V_72 ) ;
} else if ( V_109 == V_73 ) {
error = F_45 ( V_106 ) ? :
F_46 ( V_106 , V_107 , V_119 ) ? :
F_47 ( V_106 , ( void * ) & V_115 ) ;
memcpy ( V_108 , V_115 . V_117 , V_28 ) ;
} else if ( V_109 == V_28 ) {
error = F_45 ( V_106 ) ? :
F_46 ( V_106 , V_107 , V_119 ) ? :
F_47 ( V_106 , ( void * ) & V_115 ) ;
memcpy ( V_108 , V_115 . V_117 , V_28 ) ;
} else {
error = - V_103 ;
F_48 ( L_6 , V_109 ) ;
}
return error ;
}
static void F_49 ( char * V_120 , int V_101 )
{
int V_85 ;
if ( V_101 == V_28 ) {
for ( V_85 = 0 ; V_85 < ( V_101 / sizeof( V_121 ) ) ; V_85 ++ )
* ( ( V_122 * ) V_120 + V_85 ) =
F_50 ( * ( ( V_121 * ) V_120 + V_85 ) ) ;
} else {
for ( V_85 = 0 ; V_85 < ( V_101 / sizeof( T_2 ) ) ; V_85 ++ )
* ( ( V_123 * ) V_120 + V_85 ) =
F_51 ( * ( ( T_2 * ) V_120 + V_85 ) ) ;
}
}
static inline int F_52 ( struct V_43 * V_30 )
{
struct V_124 * V_125 = V_30 -> V_50 ;
struct V_126 * V_127 =
F_53 ( F_54 ( V_125 ) , struct V_126 ,
V_125 . V_128 ) ;
if ( V_127 -> type == V_129 )
return 1 ;
return 0 ;
}
static void F_55 ( struct V_130 * V_131 ,
struct V_132 * V_133 ,
struct V_134 * V_135 )
{
struct V_136 * V_137 ;
unsigned int V_20 = 0 , V_138 = V_135 -> V_139 ;
unsigned int V_140 = V_135 -> V_140 , V_85 , V_86 = 0 ;
V_131 -> V_141 = F_40 ( F_56 ( V_142 )
| F_57 ( 0 ) ) ;
V_131 -> V_143 =
F_40 ( F_58 ( 0 ) |
F_59 ( 0 ) |
F_60 ( 0 ) |
F_61 ( 0 ) |
F_62 ( 0 ) |
F_63 ( V_140 ) ) ;
V_131 -> V_144 . V_145 = V_146 ;
V_131 -> V_144 . V_147 = F_64 ( V_135 -> V_147 ) ;
V_131 -> V_144 . V_148 = 0 ;
V_137 = (struct V_136 * ) ( ( unsigned char * ) V_131 +
sizeof( struct V_130 ) ) ;
for ( V_85 = 0 ; V_140 && V_138 ; V_137 ++ ) {
for ( V_86 = 0 ; V_86 < 8 && V_140 && V_138 ; V_86 ++ , V_140 -- ) {
V_20 = F_65 ( V_138 , F_66 ( V_133 ) ) ;
V_137 -> V_20 [ V_86 ] = F_64 ( V_20 ) ;
V_137 -> V_149 [ V_86 ] = F_50 ( F_67 ( V_133 ) ) ;
V_138 -= V_20 ;
V_133 = F_68 ( V_133 ) ;
}
}
}
static inline int F_69 ( struct V_150 * V_16 ,
struct V_130 * V_131 ,
struct V_132 * V_133 ,
struct V_134 * V_135 )
{
if ( ! V_133 || ! V_135 -> V_140 )
return - V_103 ;
V_135 -> V_140 = F_70 ( V_16 , V_133 , V_135 -> V_140 , V_60 ) ;
if ( V_135 -> V_140 == 0 ) {
F_48 ( L_7 ) ;
return - V_103 ;
}
F_55 ( V_131 , V_133 , V_135 ) ;
return 0 ;
}
static inline int F_12 ( struct V_29 * V_151 )
{
struct V_152 * V_125 = F_71 ( V_151 ) ;
struct V_126 * V_127 =
F_53 ( V_125 , struct V_126 , V_125 . V_151 ) ;
return V_127 -> type & V_153 ;
}
static inline int F_72 ( struct V_43 * V_30 )
{
struct V_124 * V_125 = V_30 -> V_50 ;
struct V_126 * V_127 =
F_53 ( V_125 , struct V_126 , V_125 . V_154 ) ;
return V_127 -> type & V_153 ;
}
static inline void F_73 ( struct V_18 * V_19 ,
unsigned int * V_155 ,
char * V_156 ,
T_1 V_157 )
{
V_19 -> V_20 += V_157 ;
V_19 -> V_158 += V_157 ;
V_19 -> V_159 += V_157 ;
F_74 ( F_75 ( V_156 ) ) ;
F_76 ( V_19 , * V_155 , F_75 ( V_156 ) ,
F_77 ( V_156 ) , V_157 ) ;
( * V_155 ) ++ ;
}
static inline void
F_78 ( struct V_18 * V_19 , unsigned int * V_155 ,
struct V_132 * V_133 , unsigned int V_160 )
{
struct V_161 * V_162 ;
unsigned int V_163 ;
V_19 -> V_20 += V_160 ;
V_19 -> V_158 += V_160 ;
V_19 -> V_159 += V_160 ;
while ( V_160 > 0 ) {
if ( ! V_133 || ( ! ( V_133 -> V_164 ) ) )
break;
V_162 = F_79 ( V_133 ) ;
F_74 ( V_162 ) ;
V_163 = F_65 ( V_133 -> V_164 , V_160 ) ;
F_76 ( V_19 , * V_155 , V_162 , V_133 -> V_165 , V_163 ) ;
( * V_155 ) ++ ;
V_160 -= V_163 ;
V_133 = F_68 ( V_133 ) ;
}
}
static int F_80 ( struct V_166 * V_16 , unsigned int V_167 )
{
struct V_48 * V_49 = F_81 ( V_16 ) ;
struct V_168 * V_169 =
V_49 -> V_170 . V_171 [ V_172 ] ;
struct V_173 * V_174 ;
int V_175 = 0 ;
F_82 () ;
V_174 = & V_169 -> V_176 [ V_167 ] ;
F_83 ( & V_174 -> V_177 . V_178 ) ;
if ( V_174 -> V_179 )
V_175 = - 1 ;
F_84 ( & V_174 -> V_177 . V_178 ) ;
F_85 () ;
return V_175 ;
}
static int F_86 ( struct V_6 * V_7 ,
struct V_180 * V_181 )
{
if ( V_7 -> V_182 == V_183 ) {
memcpy ( V_181 -> V_81 , V_7 -> V_184 , V_7 -> V_185 ) ;
} else {
memcpy ( V_181 -> V_81 ,
V_7 -> V_81 + ( V_7 -> V_185 >> 1 ) ,
V_7 -> V_185 >> 1 ) ;
memcpy ( V_181 -> V_81 + ( V_7 -> V_185 >> 1 ) ,
V_7 -> V_184 , V_7 -> V_185 >> 1 ) ;
}
return 0 ;
}
static int F_87 ( struct V_132 * V_38 ,
struct V_132 * V_58 ,
unsigned int V_186 ,
unsigned int V_187 ,
short int * V_188 ,
short int * V_189 )
{
int V_190 = 0 , V_191 = 0 ;
int V_192 = V_186 , V_193 = 0 ;
* V_188 = 0 ;
* V_189 = 0 ;
while ( V_38 && V_58 && ( ( V_192 + 1 ) <= V_194 ) &&
V_187 > ( V_195 [ V_192 + 1 ] + V_196 [ V_193 ] ) ) {
V_190 += V_38 -> V_164 ;
V_192 ++ ;
while ( V_58 && ( ( V_193 + 1 ) <= V_197 ) &&
V_187 > ( V_195 [ V_192 ] + V_196 [ V_193 + 1 ] ) ) {
if ( V_190 <= V_191 )
break;
V_191 += V_58 -> V_164 ;
V_58 = F_68 ( V_58 ) ;
V_193 ++ ;
}
V_38 = F_68 ( V_38 ) ;
}
* V_188 = V_192 - V_186 ;
* V_189 = V_193 ;
return F_65 ( V_190 , V_191 ) ;
}
static int F_88 ( struct V_198 * V_199 ,
T_2 V_200 ,
struct V_132 * V_38 ,
struct V_132 * V_58 ,
unsigned int V_201 ,
T_1 * V_202 ,
unsigned short V_203 )
{
int V_26 ;
F_89 ( V_204 , V_199 ) ;
F_90 ( V_204 , V_199 ) ;
F_91 ( V_204 , V_200 , NULL , NULL ) ;
F_92 ( V_204 , V_38 , V_58 ,
V_201 , V_202 ) ;
V_26 = V_203 ? F_93 ( V_204 ) :
F_94 ( V_204 ) ;
F_95 ( V_204 ) ;
return V_26 ;
}
static inline void F_96 ( struct V_2 * V_3 ,
struct V_205 * V_206 ,
void * V_24 , struct V_18 * V_19 ,
int V_207 , int V_208 ,
int V_209 ,
unsigned int V_210 ,
unsigned int V_211 )
{
struct V_15 * V_17 = F_6 ( V_3 ) ;
int V_212 = V_213 ;
int V_147 = V_17 -> V_56 . V_214 [ V_3 -> V_215 ] ;
unsigned int V_216 = 0 , V_79 = 0 ;
if ( F_7 ( V_19 ) ) {
V_216 = V_19 -> V_158 ;
V_212 = V_217 ;
} else {
V_79 = F_34 ( V_19 ) -> V_79 ;
}
V_206 -> V_218 . V_219 = F_97 ( V_216 ,
( ( sizeof( V_206 -> V_181 ) + V_207 ) >> 4 ) ) ;
V_206 -> V_218 . V_220 =
F_40 ( F_98 ( V_221 [ V_79 ] ) |
F_99 ( V_208 ) ) ;
V_206 -> V_218 . V_222 =
F_40 ( F_100 ( F_32 (
( F_31 ( V_19 ) * 8 ) , 16 ) ) ) ;
V_206 -> V_218 . V_223 = F_50 ( ( V_224 ) V_24 ) ;
V_206 -> V_218 . V_225 =
F_101 ( V_3 -> V_16 -> V_226 , V_147 ,
V_209 ? V_212 : V_227 , ! ! V_211 ,
V_3 -> V_228 ) ;
V_206 -> V_229 . V_230 = F_102 ( V_3 -> V_16 -> V_231 ,
V_147 ) ;
V_206 -> V_229 . V_20 = F_40 ( ( F_32 ( ( F_31 ( V_19 ) * 8 ) ,
16 ) - ( ( sizeof( V_206 -> V_218 ) ) >> 4 ) ) ) ;
V_206 -> V_232 . V_233 = F_103 ( V_216 ) ;
V_206 -> V_232 . V_20 = F_51 ( sizeof( struct V_234 ) +
sizeof( V_206 -> V_181 ) +
V_207 + V_210 + V_216 ) ;
}
static struct V_18 * F_104 ( struct V_235 * V_236 )
{
struct V_237 * V_30 = F_105 ( V_236 -> V_24 ) ;
struct V_2 * V_3 = F_106 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_18 * V_19 = NULL ;
struct V_205 * V_206 ;
struct V_130 * V_131 ;
struct V_238 * V_55 =
F_107 ( V_236 -> V_24 ) ;
struct V_134 V_135 ;
unsigned int V_155 = 0 , V_239 , V_240 ;
int error ;
unsigned int V_241 = V_242 , V_207 ;
T_3 V_200 = V_236 -> V_24 -> V_65 . V_200 & V_243 ?
V_244 : V_245 ;
struct V_48 * V_49 = F_18 ( V_3 -> V_16 ) ;
V_240 = F_108 ( V_55 -> V_59 ) ;
V_207 = ( F_32 ( V_7 -> V_185 , 16 ) * 16 ) ;
V_239 = F_109 ( V_207 , V_240 ) ;
V_19 = F_110 ( ( V_239 + sizeof( struct V_246 ) ) , V_200 ) ;
if ( ! V_19 ) {
error = - V_247 ;
goto V_26;
}
F_111 ( V_19 , sizeof( struct V_246 ) ) ;
V_206 = F_112 ( V_19 , V_239 ) ;
V_206 -> V_248 . V_249 =
F_113 ( V_3 -> V_16 -> V_226 , 2 , 1 ) ;
V_206 -> V_248 . V_250 = F_40 ( V_241 + V_236 -> V_251 ) ;
V_206 -> V_248 . V_252 =
F_114 ( 0 , 0 , V_241 + 1 , 0 ) ;
V_206 -> V_248 . V_253 =
F_115 ( 0 , 0 , 0 , 0 ) ;
V_206 -> V_248 . V_254 = F_116 ( V_55 -> V_255 , 0 ,
V_7 -> V_182 ,
0 , 0 , V_241 >> 1 ) ;
V_206 -> V_248 . V_256 = F_117 ( 0 , 0 , 0 ,
0 , 1 , V_240 ) ;
V_206 -> V_181 . V_257 = V_7 -> V_258 ;
if ( ( V_55 -> V_255 == V_259 ) &&
( ! ( F_72 ( F_118 ( V_30 ) ) ==
V_260 ) ) &&
( ! ( F_72 ( F_118 ( V_30 ) ) ==
V_261 ) ) ) {
F_86 ( V_7 , & V_206 -> V_181 ) ;
} else {
if ( ( V_7 -> V_182 == V_183 ) ||
( V_7 -> V_182 == V_262 ) ) {
memcpy ( V_206 -> V_181 . V_81 , V_7 -> V_81 ,
V_7 -> V_185 ) ;
} else {
memcpy ( V_206 -> V_181 . V_81 , V_7 -> V_81 +
( V_7 -> V_185 >> 1 ) ,
V_7 -> V_185 >> 1 ) ;
memcpy ( V_206 -> V_181 . V_81 +
( V_7 -> V_185 >> 1 ) ,
V_7 -> V_81 ,
V_7 -> V_185 >> 1 ) ;
}
}
V_131 = (struct V_130 * ) ( ( T_1 * ) ( V_206 + 1 ) + V_207 ) ;
V_135 . V_140 = V_55 -> V_59 ;
V_135 . V_139 = V_236 -> V_251 ;
V_135 . V_147 = V_236 -> V_147 ;
error = F_69 ( & V_17 -> V_56 . V_57 -> V_16 , V_131 ,
V_55 -> V_58 , & V_135 ) ;
if ( error )
goto V_263;
F_119 ( V_19 , V_239 ) ;
F_73 ( V_19 , & V_155 , V_55 -> V_202 , V_241 ) ;
F_78 ( V_19 , & V_155 , V_236 -> V_192 , V_236 -> V_251 ) ;
F_30 ( & V_49 -> V_76 . V_264 ) ;
F_96 ( V_3 , V_206 , & ( V_236 -> V_24 -> V_65 ) , V_19 , V_207 , 0 , 1 ,
sizeof( struct V_130 ) + V_240 ,
V_7 -> V_182 == V_183 ) ;
V_55 -> V_19 = V_19 ;
F_120 ( V_19 ) ;
return V_19 ;
V_263:
F_22 ( V_19 ) ;
V_26:
return F_42 ( error ) ;
}
static inline int F_121 ( unsigned int V_265 )
{
int V_266 = 0 ;
if ( V_265 == V_267 )
V_266 = V_268 ;
else if ( V_265 == V_269 )
V_266 = V_270 ;
else if ( V_265 == V_271 )
V_266 = V_272 ;
else
V_266 = 0 ;
return V_266 ;
}
static int F_122 ( struct V_237 * V_199 ,
const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_43 * V_30 = F_118 ( V_199 ) ;
struct V_2 * V_3 = F_106 ( V_199 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
int V_26 = 0 ;
F_123 ( V_7 -> V_273 , V_274 ) ;
F_124 ( V_7 -> V_273 , V_199 -> V_65 . V_275 &
V_274 ) ;
V_26 = F_125 ( V_7 -> V_273 , V_81 , V_265 ) ;
V_30 -> V_275 &= ~ V_276 ;
V_30 -> V_275 |=
F_126 ( V_7 -> V_273 ) &
V_276 ;
return V_26 ;
}
static int F_127 ( struct V_237 * V_199 ,
const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_2 * V_3 = F_106 ( V_199 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned int V_266 , V_277 ;
T_4 V_278 = 0 ;
int V_26 ;
V_26 = F_122 ( V_199 , V_81 , V_265 ) ;
if ( V_26 )
goto V_279;
V_266 = F_121 ( V_265 ) ;
V_278 = V_266 == V_270 ? 8 : 0 ;
memcpy ( V_7 -> V_81 , V_81 , V_265 ) ;
V_7 -> V_185 = V_265 ;
F_37 ( V_7 -> V_184 , V_7 -> V_81 , V_265 << 3 ) ;
V_277 = ( V_280 +
V_265 + V_278 ) >> 4 ;
V_7 -> V_258 = F_128 ( V_266 , V_281 ,
0 , 0 , V_277 ) ;
V_7 -> V_182 = V_183 ;
return 0 ;
V_279:
F_129 ( V_199 , V_282 ) ;
V_7 -> V_185 = 0 ;
return V_26 ;
}
static int F_130 ( struct V_237 * V_199 ,
const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_2 * V_3 = F_106 ( V_199 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned int V_266 , V_277 ;
T_4 V_278 = 0 ;
int V_26 ;
V_26 = F_122 ( V_199 , V_81 , V_265 ) ;
if ( V_26 )
goto V_279;
V_266 = F_121 ( V_265 ) ;
V_278 = ( V_266 == V_270 ) ? 8 : 0 ;
memcpy ( V_7 -> V_81 , V_81 , V_265 ) ;
V_7 -> V_185 = V_265 ;
V_277 = ( V_280 +
V_265 + V_278 ) >> 4 ;
V_7 -> V_258 = F_128 ( V_266 , V_281 ,
0 , 0 , V_277 ) ;
V_7 -> V_182 = V_262 ;
return 0 ;
V_279:
F_129 ( V_199 , V_282 ) ;
V_7 -> V_185 = 0 ;
return V_26 ;
}
static int F_131 ( struct V_237 * V_199 ,
const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_2 * V_3 = F_106 ( V_199 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned int V_266 , V_277 ;
T_4 V_278 = 0 ;
int V_26 ;
if ( V_265 < V_283 )
return - V_103 ;
memcpy ( V_7 -> V_284 , V_81 + ( V_265 - V_283 ) ,
V_283 ) ;
V_265 -= V_283 ;
V_26 = F_122 ( V_199 , V_81 , V_265 ) ;
if ( V_26 )
goto V_279;
V_266 = F_121 ( V_265 ) ;
V_278 = ( V_266 == V_270 ) ? 8 : 0 ;
memcpy ( V_7 -> V_81 , V_81 , V_265 ) ;
V_7 -> V_185 = V_265 ;
V_277 = ( V_280 +
V_265 + V_278 ) >> 4 ;
V_7 -> V_258 = F_128 ( V_266 , V_281 ,
0 , 0 , V_277 ) ;
V_7 -> V_182 = V_262 ;
return 0 ;
V_279:
F_129 ( V_199 , V_282 ) ;
V_7 -> V_185 = 0 ;
return V_26 ;
}
static void F_132 ( T_1 * V_285 , T_1 * V_286 , T_2 V_287 )
{
unsigned int V_288 = V_242 ;
V_123 * V_289 = ( V_123 * ) ( V_285 + V_288 ) ;
T_2 V_290 , V_291 ;
memcpy ( V_285 , V_286 , V_242 ) ;
for (; V_288 >= 4 ; V_288 -= 4 ) {
V_291 = F_38 ( * -- V_289 ) ;
V_290 = V_291 + V_287 ;
* V_289 = F_51 ( V_290 ) ;
if ( V_291 < V_290 )
break;
V_287 = 1 ;
}
}
static unsigned int F_133 ( T_1 * V_202 , T_2 V_251 )
{
V_123 * V_289 = ( V_123 * ) ( V_202 + V_242 ) ;
V_121 V_290 ;
T_2 V_27 = F_38 ( * -- V_289 ) ;
V_27 = ~ V_27 ;
V_290 = ( V_121 ) V_27 + 1 ;
if ( ( V_251 / V_242 ) > V_290 )
V_251 = V_290 * V_242 ;
return V_251 ;
}
static int F_134 ( struct V_292 * V_24 , T_1 * V_202 )
{
struct V_237 * V_30 = F_105 ( V_24 ) ;
struct V_2 * V_3 = F_106 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_238 * V_55 = F_107 ( V_24 ) ;
struct V_293 * V_199 ;
int V_175 , V_85 ;
T_1 * V_81 ;
unsigned int V_265 ;
V_199 = V_7 -> V_294 ;
memcpy ( V_202 , V_24 -> V_295 , V_242 ) ;
V_265 = V_7 -> V_185 / 2 ;
V_81 = V_7 -> V_81 + V_265 ;
V_175 = F_135 ( V_199 , V_81 , V_265 ) ;
if ( V_175 )
goto V_296;
F_136 ( V_199 , V_202 , V_202 ) ;
for ( V_85 = 0 ; V_85 < ( V_55 -> V_297 / V_242 ) ; V_85 ++ )
F_137 ( ( V_298 * ) V_202 , ( V_298 * ) V_202 ) ;
F_138 ( V_199 , V_202 , V_202 ) ;
V_296:
return V_175 ;
}
static int F_139 ( struct V_292 * V_24 ,
struct V_32 * V_33 , T_1 * V_202 )
{
struct V_237 * V_30 = F_105 ( V_24 ) ;
struct V_238 * V_55 = F_107 ( V_24 ) ;
int V_299 = F_72 ( F_118 ( V_30 ) ) ;
int V_175 = 0 ;
if ( V_299 == V_260 )
F_132 ( V_202 , V_24 -> V_295 , ( V_55 -> V_297 /
V_242 ) ) ;
else if ( V_299 == V_261 )
* ( V_123 * ) ( V_55 -> V_202 + V_283 +
V_300 ) = F_51 ( ( V_55 -> V_297 /
V_242 ) + 1 ) ;
else if ( V_299 == V_301 )
V_175 = F_134 ( V_24 , V_202 ) ;
else if ( V_299 == V_302 ) {
if ( V_55 -> V_255 )
F_14 ( V_24 -> V_38 , F_15 ( V_24 -> V_38 ) , V_202 ,
16 ,
V_55 -> V_297 - V_242 ) ;
else
memcpy ( V_202 , & V_33 -> V_37 [ 2 ] , V_242 ) ;
}
return V_175 ;
}
static int F_140 ( struct V_292 * V_24 ,
struct V_32 * V_33 , T_1 * V_202 )
{
struct V_237 * V_30 = F_105 ( V_24 ) ;
struct V_238 * V_55 = F_107 ( V_24 ) ;
int V_299 = F_72 ( F_118 ( V_30 ) ) ;
int V_175 = 0 ;
if ( V_299 == V_260 )
F_132 ( V_202 , V_24 -> V_295 , ( V_55 -> V_297 /
V_242 ) ) ;
else if ( V_299 == V_301 )
V_175 = F_134 ( V_24 , V_202 ) ;
else if ( V_299 == V_302 ) {
if ( V_55 -> V_255 )
F_14 ( V_24 -> V_38 , F_15 ( V_24 -> V_38 ) , V_202 ,
16 ,
V_55 -> V_297 - V_242 ) ;
else
memcpy ( V_202 , & V_33 -> V_37 [ 2 ] , V_242 ) ;
}
return V_175 ;
}
static int F_24 ( struct V_292 * V_24 ,
unsigned char * V_25 , int V_26 )
{
struct V_237 * V_30 = F_105 ( V_24 ) ;
struct V_2 * V_3 = F_106 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_18 * V_19 ;
struct V_32 * V_33 = (struct V_32 * ) V_25 ;
struct V_238 * V_55 = F_107 ( V_24 ) ;
struct V_235 V_236 ;
int V_251 ;
F_21 ( & V_17 -> V_56 . V_57 -> V_16 , V_55 -> V_58 , V_55 -> V_59 ,
V_60 ) ;
if ( V_55 -> V_19 ) {
F_22 ( V_55 -> V_19 ) ;
V_55 -> V_19 = NULL ;
}
if ( V_26 )
goto V_66;
if ( V_24 -> V_201 == V_55 -> V_297 ) {
V_26 = F_140 ( V_24 , V_33 , V_24 -> V_295 ) ;
goto V_66;
}
if ( F_141 ( F_80 ( V_17 -> V_56 . V_303 [ 0 ] ,
V_3 -> V_228 ) ) ) {
if ( ! ( V_24 -> V_65 . V_200 & V_304 ) ) {
V_26 = - V_305 ;
goto V_66;
}
}
V_236 . V_192 = F_142 ( V_55 -> V_306 , V_24 -> V_38 ,
V_55 -> V_297 ) ;
V_55 -> V_58 = F_142 ( V_55 -> V_307 , V_55 -> V_193 ,
V_55 -> V_297 ) ;
if ( ! V_236 . V_192 || ! V_55 -> V_58 ) {
F_48 ( L_8 ) ;
V_26 = - V_103 ;
goto V_66;
}
V_251 = F_87 ( V_236 . V_192 , V_55 -> V_58 , 1 ,
F_143 ( V_7 -> V_185 ) ,
& V_236 . V_308 , & V_55 -> V_59 ) ;
if ( ( V_251 + V_55 -> V_297 ) >= V_24 -> V_201 )
V_251 = V_24 -> V_201 - V_55 -> V_297 ;
else
V_251 = F_144 ( V_251 ) ;
V_26 = F_139 ( V_24 , V_33 , V_55 -> V_202 ) ;
if ( V_26 )
goto V_66;
if ( F_141 ( V_251 == 0 ) ) {
V_26 = F_88 ( V_7 -> V_273 ,
V_24 -> V_65 . V_200 ,
V_236 . V_192 ,
V_55 -> V_58 ,
V_24 -> V_201 - V_55 -> V_297 ,
V_55 -> V_202 ,
V_55 -> V_255 ) ;
goto V_66;
}
if ( F_72 ( F_118 ( V_30 ) ) ==
V_260 )
V_251 = F_133 ( V_55 -> V_202 , V_251 ) ;
V_55 -> V_297 += V_251 ;
V_236 . V_147 = V_17 -> V_56 . V_214 [ V_3 -> V_215 ] ;
V_236 . V_24 = V_24 ;
V_236 . V_251 = V_251 ;
V_19 = F_104 ( & V_236 ) ;
if ( F_145 ( V_19 ) ) {
F_48 ( L_9 , V_309 ) ;
V_26 = F_146 ( V_19 ) ;
goto V_66;
}
V_19 -> V_16 = V_17 -> V_56 . V_303 [ 0 ] ;
F_147 ( V_19 , V_310 , V_3 -> V_228 ) ;
F_148 ( V_19 ) ;
return 0 ;
V_66:
F_23 ( V_55 -> V_61 ) ;
V_55 -> V_61 = NULL ;
V_24 -> V_65 . V_66 ( & V_24 -> V_65 , V_26 ) ;
return V_26 ;
}
static int F_149 ( struct V_292 * V_24 ,
unsigned short V_147 ,
struct V_18 * * V_19 ,
unsigned short V_203 )
{
struct V_237 * V_30 = F_105 ( V_24 ) ;
unsigned int V_241 = F_150 ( V_30 ) ;
struct V_238 * V_55 = F_107 ( V_24 ) ;
struct V_2 * V_3 = F_106 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_235 V_236 ;
int V_251 , V_140 , V_26 = - V_103 ;
V_55 -> V_61 = NULL ;
V_55 -> V_297 = 0 ;
if ( ! V_24 -> V_295 )
goto error;
if ( ( V_7 -> V_185 == 0 ) || ( V_241 > V_242 ) ||
( V_24 -> V_201 == 0 ) ||
( V_24 -> V_201 % F_151 ( V_30 ) ) ) {
F_48 ( L_10 ,
V_7 -> V_185 , V_24 -> V_201 , V_241 ) ;
goto error;
}
V_236 . V_192 = V_24 -> V_38 ;
if ( F_152 ( V_24 -> V_58 , & V_140 ) ) {
V_55 -> V_61 = F_153 ( V_24 -> V_58 , V_140 ) ;
if ( F_145 ( V_55 -> V_61 ) )
return F_146 ( V_55 -> V_61 ) ;
V_55 -> V_193 = V_55 -> V_61 ;
} else {
V_55 -> V_193 = V_24 -> V_58 ;
}
V_251 = F_87 ( V_236 . V_192 , V_55 -> V_193 , V_311 ,
F_143 ( V_7 -> V_185 ) ,
& V_236 . V_308 ,
& V_55 -> V_59 ) ;
if ( ( V_251 + V_55 -> V_297 ) >= V_24 -> V_201 )
V_251 = V_24 -> V_201 - V_55 -> V_297 ;
else
V_251 = F_144 ( V_251 ) ;
if ( F_141 ( V_251 > V_24 -> V_201 ) )
V_251 = V_24 -> V_201 ;
if ( F_72 ( F_118 ( V_30 ) ) ==
V_260 ) {
V_251 = F_133 ( V_24 -> V_295 , V_251 ) ;
}
if ( F_72 ( F_118 ( V_30 ) ) ==
V_261 ) {
memcpy ( V_55 -> V_202 , V_7 -> V_284 , V_283 ) ;
memcpy ( V_55 -> V_202 + V_283 , V_24 -> V_295 ,
V_300 ) ;
* ( V_123 * ) ( V_55 -> V_202 + V_283 +
V_300 ) = F_51 ( 1 ) ;
} else {
memcpy ( V_55 -> V_202 , V_24 -> V_295 , V_241 ) ;
}
if ( F_141 ( V_251 == 0 ) ) {
V_26 = F_88 ( V_7 -> V_273 ,
V_24 -> V_65 . V_200 ,
V_24 -> V_38 ,
V_24 -> V_58 ,
V_24 -> V_201 ,
V_24 -> V_295 ,
V_203 ) ;
goto error;
}
V_55 -> V_297 = V_251 ;
V_55 -> V_58 = V_55 -> V_193 ;
V_55 -> V_255 = V_203 ;
V_236 . V_147 = V_147 ;
V_236 . V_24 = V_24 ;
V_236 . V_251 = V_251 ;
* V_19 = F_104 ( & V_236 ) ;
if ( F_145 ( * V_19 ) ) {
V_26 = F_146 ( * V_19 ) ;
goto error;
}
return 0 ;
error:
F_23 ( V_55 -> V_61 ) ;
V_55 -> V_61 = NULL ;
return V_26 ;
}
static int F_154 ( struct V_292 * V_24 )
{
struct V_237 * V_30 = F_105 ( V_24 ) ;
struct V_2 * V_3 = F_106 ( V_30 ) ;
struct V_18 * V_19 = NULL ;
int V_26 ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
if ( F_141 ( F_80 ( V_17 -> V_56 . V_303 [ 0 ] ,
V_3 -> V_228 ) ) ) {
if ( ! ( V_24 -> V_65 . V_200 & V_304 ) )
return - V_305 ;
}
V_26 = F_149 ( V_24 , V_17 -> V_56 . V_214 [ V_3 -> V_215 ] , & V_19 ,
V_312 ) ;
if ( V_26 || ! V_19 )
return V_26 ;
V_19 -> V_16 = V_17 -> V_56 . V_303 [ 0 ] ;
F_147 ( V_19 , V_310 , V_3 -> V_228 ) ;
F_148 ( V_19 ) ;
return - V_313 ;
}
static int F_155 ( struct V_292 * V_24 )
{
struct V_237 * V_30 = F_105 ( V_24 ) ;
struct V_2 * V_3 = F_106 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_18 * V_19 = NULL ;
int V_26 ;
if ( F_141 ( F_80 ( V_17 -> V_56 . V_303 [ 0 ] ,
V_3 -> V_228 ) ) ) {
if ( ! ( V_24 -> V_65 . V_200 & V_304 ) )
return - V_305 ;
}
V_26 = F_149 ( V_24 , V_17 -> V_56 . V_214 [ V_3 -> V_215 ] , & V_19 ,
V_259 ) ;
if ( V_26 || ! V_19 )
return V_26 ;
V_19 -> V_16 = V_17 -> V_56 . V_303 [ 0 ] ;
F_147 ( V_19 , V_310 , V_3 -> V_228 ) ;
F_148 ( V_19 ) ;
return - V_313 ;
}
static int F_156 ( struct V_2 * V_3 )
{
struct V_15 * V_17 = NULL ;
struct V_48 * V_49 ;
unsigned int V_314 ;
int V_315 , V_316 , V_317 ;
int V_26 = 0 , V_318 , V_319 ;
V_314 = F_157 () ;
if ( ! V_3 -> V_16 ) {
V_17 = F_158 () ;
if ( ! V_17 ) {
F_48 ( L_11 ) ;
goto V_296;
}
V_3 -> V_16 = V_17 -> V_16 ;
V_49 = F_18 ( V_3 -> V_16 ) ;
V_317 = F_159 ( ( unsigned int ) V_17 -> V_56 . V_320 ,
V_49 -> V_321 . V_322 ) ;
V_318 = V_17 -> V_56 . V_320 / V_17 -> V_56 . V_323 ;
V_315 = V_317 / V_17 -> V_56 . V_323 ;
V_319 = V_3 -> V_16 -> V_231 * V_318 ;
V_319 += V_314 % V_318 ;
V_316 = V_3 -> V_16 -> V_231 * V_315 ;
V_316 += V_314 % V_315 ;
F_83 ( & V_3 -> V_16 -> V_324 ) ;
V_3 -> V_215 = V_319 ;
V_3 -> V_228 = V_316 ;
V_3 -> V_16 -> V_231 = ! V_3 -> V_16 -> V_231 ;
V_3 -> V_16 -> V_226 = 0 ;
F_84 ( & V_3 -> V_16 -> V_324 ) ;
}
V_296:
return V_26 ;
}
static int F_160 ( struct V_43 * V_30 )
{
struct V_124 * V_125 = V_30 -> V_50 ;
struct V_2 * V_3 = F_17 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
V_7 -> V_273 = F_161 ( V_125 -> V_325 , 0 ,
V_326 | V_327 ) ;
if ( F_145 ( V_7 -> V_273 ) ) {
F_48 ( L_12 , V_125 -> V_325 ) ;
return F_146 ( V_7 -> V_273 ) ;
}
if ( F_72 ( V_30 ) == V_301 ) {
V_7 -> V_294 = F_162 ( L_13 , 0 , 0 ) ;
if ( F_145 ( V_7 -> V_294 ) ) {
F_48 ( L_14 ) ;
return F_146 ( V_7 -> V_294 ) ;
}
} else
V_7 -> V_294 = NULL ;
V_30 -> V_328 . V_329 = sizeof( struct V_238 ) ;
return F_156 ( F_17 ( V_30 ) ) ;
}
static int F_163 ( struct V_43 * V_30 )
{
struct V_124 * V_125 = V_30 -> V_50 ;
struct V_2 * V_3 = F_17 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
V_7 -> V_273 = F_161 ( L_15 , 0 ,
V_326 | V_327 ) ;
if ( F_145 ( V_7 -> V_273 ) ) {
F_48 ( L_12 , V_125 -> V_325 ) ;
return F_146 ( V_7 -> V_273 ) ;
}
V_30 -> V_328 . V_329 = sizeof( struct V_238 ) ;
return F_156 ( F_17 ( V_30 ) ) ;
}
static void F_164 ( struct V_43 * V_30 )
{
struct V_2 * V_3 = F_17 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
F_165 ( V_7 -> V_273 ) ;
if ( V_7 -> V_294 )
F_166 ( V_7 -> V_294 ) ;
}
static int F_167 ( struct V_330 * V_331 ,
unsigned int V_332 )
{
switch ( V_332 ) {
case V_104 :
V_331 -> V_333 = V_334 ;
V_331 -> V_335 = V_336 ;
V_331 -> V_337 = V_104 ;
break;
case V_71 :
V_331 -> V_333 = V_338 ;
V_331 -> V_335 = V_339 ;
V_331 -> V_337 = V_72 ;
break;
case V_72 :
V_331 -> V_333 = V_338 ;
V_331 -> V_335 = V_340 ;
V_331 -> V_337 = V_72 ;
break;
case V_73 :
V_331 -> V_333 = V_341 ;
V_331 -> V_335 = V_342 ;
V_331 -> V_337 = V_28 ;
break;
case V_28 :
V_331 -> V_333 = V_341 ;
V_331 -> V_335 = V_343 ;
V_331 -> V_337 = V_28 ;
break;
default:
F_48 ( L_16 ) ;
return - V_103 ;
}
return 0 ;
}
static inline void F_168 ( struct V_100 * V_102 )
{
F_169 ( V_102 ) ;
}
static struct V_18 * F_170 ( struct V_344 * V_24 ,
struct V_345 * V_346 )
{
struct V_347 * V_348 = F_27 ( V_24 ) ;
struct V_349 * V_30 = F_29 ( V_24 ) ;
struct V_2 * V_3 = F_17 ( F_171 ( V_30 ) ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
struct V_18 * V_19 = NULL ;
struct V_205 * V_206 ;
unsigned int V_155 = 0 , V_239 , V_350 = 0 ;
unsigned int V_46 = F_28 ( V_30 ) ;
unsigned int V_207 = 0 ;
T_1 V_351 = 0 ;
T_3 V_200 = V_24 -> V_65 . V_200 & V_243 ? V_244 :
V_245 ;
struct V_48 * V_49 = F_18 ( V_3 -> V_16 ) ;
V_350 = F_172 ( V_46 ) ;
V_207 = V_346 -> V_352 . V_337 + V_350 ;
if ( V_346 -> V_353 )
V_207 += V_346 -> V_352 . V_337 + V_350 ;
if ( V_348 -> V_74 )
V_351 = V_46 ;
else
V_351 = V_346 -> V_352 . V_337 ;
V_239 = F_173 ( V_207 ) ;
V_19 = F_110 ( ( V_239 + sizeof( struct V_246 ) ) , V_200 ) ;
if ( ! V_19 )
return V_19 ;
F_111 ( V_19 , sizeof( struct V_246 ) ) ;
V_206 = F_112 ( V_19 , V_239 ) ;
V_206 -> V_248 . V_249 =
F_113 ( V_3 -> V_16 -> V_226 , 2 , 0 ) ;
V_206 -> V_248 . V_250 = F_40 ( V_346 -> V_157 + V_346 -> V_354 ) ;
V_206 -> V_248 . V_252 =
F_114 ( 0 , 0 , 0 , 0 ) ;
V_206 -> V_248 . V_253 =
F_115 ( 0 , 1 , 0 , 0 ) ;
V_206 -> V_248 . V_254 =
F_116 ( 0 , 0 , 0 , V_346 -> V_352 . V_335 ,
V_346 -> V_353 , 0 ) ;
V_206 -> V_248 . V_256 =
F_117 ( V_346 -> V_355 , V_346 -> V_356 , 0 , 1 , 0 , 0 ) ;
memcpy ( V_206 -> V_181 . V_81 , V_348 -> V_75 ,
V_346 -> V_352 . V_337 ) ;
if ( V_346 -> V_353 )
memcpy ( V_206 -> V_181 . V_81 +
( ( V_346 -> V_352 . V_337 <= 32 ) ? 32 :
V_357 ) ,
V_9 -> V_358 , V_346 -> V_352 . V_337 ) ;
V_206 -> V_181 . V_257 = F_128 ( V_281 ,
V_346 -> V_352 . V_333 , 0 ,
V_346 -> V_353 ,
( ( V_207 +
sizeof( V_206 -> V_181 ) ) >> 4 ) ) ;
V_206 -> V_248 . V_359 = F_50 ( ( V_121 ) V_346 -> V_359 ) ;
F_119 ( V_19 , V_239 ) ;
if ( V_346 -> V_157 != 0 )
F_73 ( V_19 , & V_155 , V_348 -> V_360 ,
V_346 -> V_157 ) ;
if ( V_346 -> V_354 != 0 )
F_78 ( V_19 , & V_155 , V_24 -> V_38 , V_346 -> V_354 ) ;
F_30 ( & V_49 -> V_76 . V_361 ) ;
F_96 ( V_3 , V_206 , & V_24 -> V_65 , V_19 , V_207 ,
V_351 , 0 , V_362 , 0 ) ;
V_348 -> V_19 = V_19 ;
F_120 ( V_19 ) ;
return V_19 ;
}
static int F_174 ( struct V_344 * V_24 )
{
struct V_347 * V_348 = F_27 ( V_24 ) ;
struct V_349 * V_363 = F_29 ( V_24 ) ;
struct V_2 * V_3 = F_17 ( F_171 ( V_363 ) ) ;
struct V_15 * V_17 = NULL ;
struct V_18 * V_19 ;
T_1 V_364 = 0 , V_365 ;
unsigned int V_201 = V_24 -> V_201 ;
struct V_345 V_331 ;
V_365 = F_175 ( F_171 ( V_363 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_141 ( F_80 ( V_17 -> V_56 . V_303 [ 0 ] ,
V_3 -> V_228 ) ) ) {
if ( ! ( V_24 -> V_65 . V_200 & V_304 ) )
return - V_305 ;
}
if ( V_201 + V_348 -> V_366 >= V_365 ) {
V_364 = ( V_201 + V_348 -> V_366 ) % V_365 ;
V_201 = V_201 + V_348 -> V_366 - V_364 ;
} else {
F_14 ( V_24 -> V_38 , F_15 ( V_24 -> V_38 ) , V_348 -> V_360
+ V_348 -> V_366 , V_201 , 0 ) ;
V_348 -> V_366 += V_201 ;
return 0 ;
}
V_331 . V_353 = 0 ;
V_331 . V_356 = 1 ;
V_331 . V_355 = 0 ;
V_331 . V_354 = V_201 - V_348 -> V_366 ;
V_331 . V_157 = V_348 -> V_366 ;
V_331 . V_359 = 0 ;
F_167 ( & V_331 . V_352 , F_28 ( V_363 ) ) ;
V_348 -> V_74 = 0 ;
V_348 -> V_158 += V_331 . V_354 + V_331 . V_157 ;
V_19 = F_170 ( V_24 , & V_331 ) ;
if ( ! V_19 )
return - V_247 ;
if ( V_364 ) {
T_1 * V_27 ;
V_27 = V_348 -> V_360 ;
V_348 -> V_360 = V_348 -> V_367 ;
V_348 -> V_367 = V_27 ;
F_14 ( V_24 -> V_38 , F_15 ( V_24 -> V_38 ) ,
V_348 -> V_360 , V_364 , V_24 -> V_201 -
V_364 ) ;
}
V_348 -> V_366 = V_364 ;
V_19 -> V_16 = V_17 -> V_56 . V_303 [ 0 ] ;
F_147 ( V_19 , V_310 , V_3 -> V_228 ) ;
F_148 ( V_19 ) ;
return - V_313 ;
}
static void F_176 ( char * V_368 , unsigned int V_365 , V_121 V_359 )
{
memset ( V_368 , 0 , V_365 ) ;
* V_368 = 0x80 ;
if ( V_365 == 64 )
* ( V_122 * ) ( V_368 + 56 ) = F_50 ( V_359 << 3 ) ;
else
* ( V_122 * ) ( V_368 + 120 ) = F_50 ( V_359 << 3 ) ;
}
static int F_177 ( struct V_344 * V_24 )
{
struct V_347 * V_348 = F_27 ( V_24 ) ;
struct V_349 * V_363 = F_29 ( V_24 ) ;
struct V_2 * V_3 = F_17 ( F_171 ( V_363 ) ) ;
struct V_345 V_331 ;
struct V_18 * V_19 ;
struct V_15 * V_17 = NULL ;
T_1 V_365 = F_175 ( F_171 ( V_363 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_52 ( F_171 ( V_363 ) ) )
V_331 . V_353 = 1 ;
else
V_331 . V_353 = 0 ;
V_331 . V_354 = 0 ;
F_167 ( & V_331 . V_352 , F_28 ( V_363 ) ) ;
V_348 -> V_74 = 1 ;
V_331 . V_157 = V_348 -> V_366 ;
V_348 -> V_158 += V_331 . V_157 + V_331 . V_354 ;
if ( V_348 -> V_366 == 0 ) {
F_176 ( V_348 -> V_360 , V_365 , V_348 -> V_158 ) ;
V_331 . V_355 = 0 ;
V_331 . V_356 = 1 ;
V_331 . V_359 = 0 ;
V_331 . V_157 = V_365 ;
} else {
V_331 . V_359 = V_348 -> V_158 ;
V_331 . V_355 = 1 ;
V_331 . V_356 = 0 ;
}
V_19 = F_170 ( V_24 , & V_331 ) ;
if ( ! V_19 )
return - V_247 ;
V_19 -> V_16 = V_17 -> V_56 . V_303 [ 0 ] ;
F_147 ( V_19 , V_310 , V_3 -> V_228 ) ;
F_148 ( V_19 ) ;
return - V_313 ;
}
static int F_178 ( struct V_344 * V_24 )
{
struct V_347 * V_348 = F_27 ( V_24 ) ;
struct V_349 * V_363 = F_29 ( V_24 ) ;
struct V_2 * V_3 = F_17 ( F_171 ( V_363 ) ) ;
struct V_15 * V_17 = NULL ;
struct V_18 * V_19 ;
struct V_345 V_331 ;
T_1 V_365 ;
V_365 = F_175 ( F_171 ( V_363 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_141 ( F_80 ( V_17 -> V_56 . V_303 [ 0 ] ,
V_3 -> V_228 ) ) ) {
if ( ! ( V_24 -> V_65 . V_200 & V_304 ) )
return - V_305 ;
}
if ( F_52 ( F_171 ( V_363 ) ) )
V_331 . V_353 = 1 ;
else
V_331 . V_353 = 0 ;
V_331 . V_354 = V_24 -> V_201 ;
V_331 . V_157 = V_348 -> V_366 ;
F_167 ( & V_331 . V_352 , F_28 ( V_363 ) ) ;
V_348 -> V_158 += V_331 . V_157 + V_331 . V_354 ;
V_348 -> V_74 = 1 ;
if ( ( V_348 -> V_366 + V_24 -> V_201 ) == 0 ) {
F_176 ( V_348 -> V_360 , V_365 , V_348 -> V_158 ) ;
V_331 . V_355 = 0 ;
V_331 . V_356 = 1 ;
V_331 . V_359 = 0 ;
V_331 . V_157 = V_365 ;
} else {
V_331 . V_359 = V_348 -> V_158 ;
V_331 . V_355 = 1 ;
V_331 . V_356 = 0 ;
}
V_19 = F_170 ( V_24 , & V_331 ) ;
if ( ! V_19 )
return - V_247 ;
V_19 -> V_16 = V_17 -> V_56 . V_303 [ 0 ] ;
F_147 ( V_19 , V_310 , V_3 -> V_228 ) ;
F_148 ( V_19 ) ;
return - V_313 ;
}
static int F_179 ( struct V_344 * V_24 )
{
struct V_347 * V_348 = F_27 ( V_24 ) ;
struct V_349 * V_363 = F_29 ( V_24 ) ;
struct V_2 * V_3 = F_17 ( F_171 ( V_363 ) ) ;
struct V_15 * V_17 = NULL ;
struct V_18 * V_19 ;
struct V_345 V_331 ;
T_1 V_365 ;
V_363 -> V_369 ( V_24 ) ;
V_365 = F_175 ( F_171 ( V_363 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_141 ( F_80 ( V_17 -> V_56 . V_303 [ 0 ] ,
V_3 -> V_228 ) ) ) {
if ( ! ( V_24 -> V_65 . V_200 & V_304 ) )
return - V_305 ;
}
if ( F_52 ( F_171 ( V_363 ) ) )
V_331 . V_353 = 1 ;
else
V_331 . V_353 = 0 ;
V_331 . V_355 = 0 ;
V_331 . V_356 = 0 ;
V_331 . V_354 = V_24 -> V_201 ;
V_331 . V_157 = 0 ;
V_331 . V_359 = 0 ;
F_167 ( & V_331 . V_352 , F_28 ( V_363 ) ) ;
V_348 -> V_74 = 1 ;
V_348 -> V_158 += V_331 . V_157 + V_331 . V_354 ;
if ( V_24 -> V_201 == 0 ) {
F_176 ( V_348 -> V_360 , V_365 , 0 ) ;
V_331 . V_356 = 1 ;
V_331 . V_157 = V_365 ;
}
V_19 = F_170 ( V_24 , & V_331 ) ;
if ( ! V_19 )
return - V_247 ;
V_19 -> V_16 = V_17 -> V_56 . V_303 [ 0 ] ;
F_147 ( V_19 , V_310 , V_3 -> V_228 ) ;
F_148 ( V_19 ) ;
return - V_313 ;
}
static int F_180 ( struct V_344 * V_370 , void * V_296 )
{
struct V_347 * V_348 = F_27 ( V_370 ) ;
struct V_347 * V_117 = V_296 ;
V_117 -> V_366 = V_348 -> V_366 ;
V_117 -> V_158 = V_348 -> V_158 ;
memcpy ( V_117 -> V_371 , V_348 -> V_360 , V_348 -> V_366 ) ;
memcpy ( V_117 -> V_75 , V_348 -> V_75 ,
V_357 ) ;
return 0 ;
}
static int F_181 ( struct V_344 * V_370 , const void * V_372 )
{
struct V_347 * V_348 = F_27 ( V_370 ) ;
struct V_347 * V_117 = (struct V_347 * ) V_372 ;
V_348 -> V_366 = V_117 -> V_366 ;
V_348 -> V_158 = V_117 -> V_158 ;
V_348 -> V_360 = V_348 -> V_371 ;
V_348 -> V_367 = V_348 -> V_373 ;
memcpy ( V_348 -> V_371 , V_117 -> V_371 , V_374 ) ;
memcpy ( V_348 -> V_75 , V_117 -> V_75 ,
V_357 ) ;
return 0 ;
}
static int F_182 ( struct V_349 * V_30 , const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_2 * V_3 = F_17 ( F_171 ( V_30 ) ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
unsigned int V_46 = F_28 ( V_30 ) ;
unsigned int V_365 = F_175 ( F_171 ( V_30 ) ) ;
unsigned int V_85 , V_26 = 0 , V_47 ;
F_183 ( V_375 , V_9 -> V_102 ) ;
V_375 -> V_30 = V_9 -> V_102 ;
V_375 -> V_200 = F_184 ( V_9 -> V_102 ) ;
if ( V_265 > V_365 ) {
V_26 = F_185 ( V_375 , V_81 , V_265 ,
V_9 -> V_376 ) ;
if ( V_26 )
goto V_296;
V_265 = V_46 ;
} else {
memcpy ( V_9 -> V_376 , V_81 , V_265 ) ;
}
memset ( V_9 -> V_376 + V_265 , 0 , V_365 - V_265 ) ;
memcpy ( V_9 -> V_358 , V_9 -> V_376 , V_365 ) ;
for ( V_85 = 0 ; V_85 < V_365 / sizeof( int ) ; V_85 ++ ) {
* ( ( unsigned int * ) ( & V_9 -> V_376 ) + V_85 ) ^= V_377 ;
* ( ( unsigned int * ) ( & V_9 -> V_358 ) + V_85 ) ^= V_378 ;
}
V_47 = V_46 ;
if ( V_46 == V_71 )
V_47 = V_72 ;
else if ( V_46 == V_73 )
V_47 = V_28 ;
V_26 = F_44 ( V_375 , V_9 -> V_376 ,
V_9 -> V_376 , V_46 ) ;
if ( V_26 )
goto V_296;
F_49 ( V_9 -> V_376 , V_47 ) ;
V_26 = F_44 ( V_375 , V_9 -> V_358 ,
V_9 -> V_358 , V_46 ) ;
if ( V_26 )
goto V_296;
F_49 ( V_9 -> V_358 , V_47 ) ;
V_296:
return V_26 ;
}
static int F_186 ( struct V_237 * V_199 , const T_1 * V_81 ,
unsigned int V_379 )
{
struct V_2 * V_3 = F_106 ( V_199 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned short V_277 = 0 ;
int V_26 ;
V_26 = F_122 ( V_199 , V_81 , V_379 ) ;
if ( V_26 )
goto V_279;
memcpy ( V_7 -> V_81 , V_81 , V_379 ) ;
V_7 -> V_185 = V_379 ;
F_37 ( V_7 -> V_184 , V_7 -> V_81 , V_379 << 2 ) ;
V_277 = ( V_280 + V_379 ) >> 4 ;
V_7 -> V_258 =
F_128 ( ( V_379 == V_271 ) ?
V_268 :
V_272 ,
V_281 , 1 ,
0 , V_277 ) ;
V_7 -> V_182 = V_380 ;
return 0 ;
V_279:
F_129 ( V_199 , V_282 ) ;
V_7 -> V_185 = 0 ;
return V_26 ;
}
static int F_187 ( struct V_344 * V_370 )
{
struct V_347 * V_348 = F_27 ( V_370 ) ;
struct V_349 * V_30 = F_29 ( V_370 ) ;
int V_46 = F_28 ( V_30 ) ;
V_348 -> V_158 = 0 ;
V_348 -> V_366 = 0 ;
V_348 -> V_360 = V_348 -> V_371 ;
V_348 -> V_367 = V_348 -> V_373 ;
V_348 -> V_19 = NULL ;
V_348 -> V_74 = 0 ;
F_188 ( V_348 -> V_75 , V_46 ) ;
return 0 ;
}
static int F_189 ( struct V_43 * V_30 )
{
F_190 ( F_191 ( V_30 ) ,
sizeof( struct V_347 ) ) ;
return F_156 ( F_17 ( V_30 ) ) ;
}
static int F_192 ( struct V_344 * V_370 )
{
struct V_347 * V_348 = F_27 ( V_370 ) ;
struct V_349 * V_363 = F_29 ( V_370 ) ;
struct V_2 * V_3 = F_17 ( F_171 ( V_363 ) ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
unsigned int V_46 = F_28 ( V_363 ) ;
unsigned int V_365 = F_175 ( F_171 ( V_363 ) ) ;
F_187 ( V_370 ) ;
V_348 -> V_158 = V_365 ;
if ( F_52 ( F_171 ( V_363 ) ) ) {
if ( V_46 == V_71 )
memcpy ( V_348 -> V_75 , V_9 -> V_376 ,
V_72 ) ;
else if ( V_46 == V_73 )
memcpy ( V_348 -> V_75 , V_9 -> V_376 ,
V_28 ) ;
else
memcpy ( V_348 -> V_75 , V_9 -> V_376 ,
V_46 ) ;
}
return 0 ;
}
static int F_193 ( struct V_43 * V_30 )
{
struct V_2 * V_3 = F_17 ( V_30 ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
unsigned int V_46 =
F_28 ( F_191 ( V_30 ) ) ;
F_190 ( F_191 ( V_30 ) ,
sizeof( struct V_347 ) ) ;
V_9 -> V_102 = F_41 ( V_46 ) ;
if ( F_145 ( V_9 -> V_102 ) )
return F_146 ( V_9 -> V_102 ) ;
return F_156 ( F_17 ( V_30 ) ) ;
}
static void F_194 ( struct V_43 * V_30 )
{
struct V_2 * V_3 = F_17 ( V_30 ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
if ( V_9 -> V_102 ) {
F_168 ( V_9 -> V_102 ) ;
V_9 -> V_102 = NULL ;
}
}
static int F_152 ( struct V_132 * V_381 , unsigned int * V_382 )
{
int V_140 = 0 ;
int V_175 = 0 ;
while ( V_381 ) {
if ( V_381 -> V_164 > V_383 )
V_175 = 1 ;
V_140 += F_32 ( V_381 -> V_164 , V_383 ) ;
V_381 = F_68 ( V_381 ) ;
}
* V_382 = V_140 ;
return V_175 ;
}
static inline void F_23 ( struct V_132 * V_381 )
{
F_195 ( V_381 ) ;
}
static struct V_132 * F_153 ( struct V_132 * V_381 ,
unsigned int V_140 )
{
struct V_132 * V_384 , * V_133 ;
int V_85 , V_20 , V_297 = 0 ;
struct V_161 * V_162 ;
int V_165 ;
V_384 = F_196 ( V_140 , sizeof( struct V_132 ) , V_244 ) ;
if ( ! V_384 )
return F_42 ( - V_247 ) ;
V_133 = V_384 ;
F_197 ( V_133 , V_140 ) ;
V_165 = V_381 -> V_165 ;
V_162 = F_79 ( V_381 ) ;
for ( V_85 = 0 ; V_85 < V_140 ; V_85 ++ ) {
V_20 = F_198 ( T_2 , V_381 -> V_164 - V_297 , V_383 ) ;
F_199 ( V_133 , V_162 , V_20 , V_165 ) ;
V_297 += V_20 ;
V_165 += V_20 ;
if ( V_165 >= V_385 ) {
V_165 = V_165 % V_385 ;
V_162 ++ ;
}
if ( V_297 == V_381 -> V_164 ) {
V_297 = 0 ;
V_381 = F_68 ( V_381 ) ;
if ( ! V_381 )
break;
V_162 = F_79 ( V_381 ) ;
V_165 = V_381 -> V_165 ;
}
V_133 = F_68 ( V_133 ) ;
}
return V_384 ;
}
static int F_200 ( struct V_23 * V_24 ,
struct V_1 * V_3 )
{
F_89 ( V_386 , V_3 -> null ) ;
F_90 ( V_386 , V_3 -> null ) ;
F_91 ( V_386 , F_201 ( V_24 ) ,
NULL , NULL ) ;
F_92 ( V_386 , V_24 -> V_38 , V_24 -> V_58 , V_24 -> V_39 ,
NULL ) ;
return F_94 ( V_386 ) ;
}
static int F_202 ( struct V_23 * V_24 , int V_387 ,
int V_388 , int V_389 ,
unsigned short V_203 )
{
unsigned int V_31 = F_11 ( F_10 ( V_24 ) ) ;
if ( ( ( V_24 -> V_40 - ( V_203 ? V_31 : 0 ) ) == 0 ) ||
( V_24 -> V_39 > V_388 ) ||
( V_387 > V_194 ) ||
( V_389 > V_390 ) )
return 1 ;
return 0 ;
}
static int F_203 ( struct V_23 * V_24 , unsigned short V_203 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_204 ( V_30 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_23 * V_204 = F_20 ( V_24 ) ;
F_205 ( V_204 , V_5 -> V_273 ) ;
F_206 ( V_204 , V_24 -> V_65 . V_200 ,
V_24 -> V_65 . V_66 , V_24 -> V_65 . V_37 ) ;
F_207 ( V_204 , V_24 -> V_38 , V_24 -> V_58 , V_24 -> V_40 ,
V_24 -> V_202 ) ;
F_208 ( V_204 , V_24 -> V_39 ) ;
return V_203 ? F_209 ( V_204 ) :
F_210 ( V_204 ) ;
}
static struct V_18 * F_211 ( struct V_23 * V_24 ,
unsigned short V_147 ,
int V_288 ,
unsigned short V_203 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_204 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_391 = F_5 ( V_5 ) ;
struct V_392 * V_55 = F_20 ( V_24 ) ;
struct V_18 * V_19 = NULL ;
struct V_205 * V_206 ;
struct V_130 * V_131 ;
struct V_134 V_135 ;
struct V_132 * V_38 ;
unsigned int V_155 = 0 , V_239 ;
unsigned int V_241 = F_212 ( V_30 ) , V_393 = 0 ;
unsigned int V_207 = 0 , V_140 ;
unsigned short V_394 = 0 ;
unsigned int V_39 = V_24 -> V_39 ;
unsigned int V_31 = F_11 ( V_30 ) ;
int error = - V_103 , V_387 ;
int null = 0 ;
T_3 V_200 = V_24 -> V_65 . V_200 & V_243 ? V_244 :
V_245 ;
struct V_48 * V_49 = F_18 ( V_3 -> V_16 ) ;
V_55 -> V_61 = NULL ;
V_393 = V_24 -> V_39 + V_24 -> V_40 + ( V_203 ? - V_31 :
V_31 ) ;
if ( V_5 -> V_185 == 0 || ( V_24 -> V_40 <= 0 ) )
goto V_26;
if ( V_203 && V_24 -> V_40 < F_11 ( V_30 ) )
goto V_26;
V_387 = F_213 ( V_24 -> V_38 , V_24 -> V_39 + V_24 -> V_40 ) ;
if ( V_387 < 0 )
goto V_26;
V_38 = F_142 ( V_55 -> V_306 , V_24 -> V_38 , V_24 -> V_39 ) ;
if ( V_24 -> V_38 != V_24 -> V_58 ) {
error = F_200 ( V_24 , V_5 ) ;
if ( error )
return F_42 ( error ) ;
}
if ( V_393 && F_152 ( V_24 -> V_58 , & V_140 ) ) {
V_55 -> V_61 = F_153 ( V_24 -> V_58 , V_140 ) ;
if ( F_145 ( V_55 -> V_61 ) )
return F_214 ( V_55 -> V_61 ) ;
V_55 -> V_58 = F_142 ( V_55 -> V_307 ,
V_55 -> V_61 , V_24 -> V_39 ) ;
} else {
if ( V_24 -> V_38 == V_24 -> V_58 )
V_55 -> V_58 = V_38 ;
else
V_55 -> V_58 = F_142 ( V_55 -> V_307 ,
V_24 -> V_58 , V_24 -> V_39 ) ;
}
if ( F_12 ( V_30 ) == V_395 ) {
null = 1 ;
V_39 = 0 ;
}
V_55 -> V_59 = F_213 ( V_55 -> V_58 , V_24 -> V_40 +
( V_203 ? - V_31 : V_31 ) ) ;
if ( V_55 -> V_59 < 0 ) {
F_48 ( L_17 ) ;
error = - V_103 ;
goto V_26;
}
V_393 = F_108 ( V_55 -> V_59 ) ;
V_207 = ( F_215 ( F_216 ( V_5 -> V_258 ) ) << 4 )
- sizeof( V_206 -> V_181 ) ;
V_239 = F_109 ( V_207 , V_393 ) ;
if ( F_202 ( V_24 , V_387 + V_396 ,
V_397 ,
V_239 + ( F_8 ( V_387 + V_396 ) * 8 ) ,
V_203 ) ) {
F_30 ( & V_49 -> V_76 . V_398 ) ;
F_23 ( V_55 -> V_61 ) ;
V_55 -> V_61 = NULL ;
return F_42 ( F_203 ( V_24 , V_203 ) ) ;
}
V_19 = F_110 ( ( V_239 + sizeof( struct V_246 ) ) , V_200 ) ;
if ( ! V_19 ) {
error = - V_247 ;
goto V_26;
}
F_111 ( V_19 , sizeof( struct V_246 ) ) ;
V_206 = F_112 ( V_19 , V_239 ) ;
V_394 = ( V_203 == V_312 ) ? 0 : V_31 ;
V_206 -> V_248 . V_249 =
F_113 ( V_3 -> V_16 -> V_226 , 2 ,
( V_241 ? ( V_39 + 1 ) : 0 ) ) ;
V_206 -> V_248 . V_250 = F_40 ( V_39 + V_241 + V_24 -> V_40 ) ;
V_206 -> V_248 . V_252 = F_114 (
V_39 ? 1 : 0 , V_39 ,
V_39 + V_241 + 1 ,
( V_394 & 0x1F0 ) >> 4 ) ;
V_206 -> V_248 . V_253 = F_115 (
V_394 & 0xF ,
null ? 0 : V_39 + V_241 + 1 ,
V_394 , V_394 ) ;
V_206 -> V_248 . V_254 = F_116 ( V_203 ,
( V_203 == V_312 ) ? 1 : 0 ,
V_183 ,
V_391 -> V_335 , V_5 -> V_399 ,
V_241 >> 1 ) ;
V_206 -> V_248 . V_256 = F_117 ( 0 , 0 , 1 ,
0 , 1 , V_393 ) ;
V_206 -> V_181 . V_257 = V_5 -> V_258 ;
if ( V_203 == V_312 )
memcpy ( V_206 -> V_181 . V_81 , V_5 -> V_81 ,
V_5 -> V_185 ) ;
else
memcpy ( V_206 -> V_181 . V_81 , V_391 -> V_400 ,
V_5 -> V_185 ) ;
memcpy ( V_206 -> V_181 . V_81 + ( F_32 ( V_5 -> V_185 , 16 ) <<
4 ) , V_391 -> V_401 , V_207 -
( F_32 ( V_5 -> V_185 , 16 ) << 4 ) ) ;
V_131 = (struct V_130 * ) ( ( T_1 * ) ( V_206 + 1 ) + V_207 ) ;
V_135 . V_140 = V_55 -> V_59 ;
V_135 . V_139 = V_24 -> V_40 + ( V_203 ? - V_31 : V_31 ) ;
V_135 . V_147 = V_147 ;
error = F_69 ( & V_17 -> V_56 . V_57 -> V_16 , V_131 ,
V_55 -> V_58 , & V_135 ) ;
if ( error )
goto V_402;
F_119 ( V_19 , V_239 ) ;
if ( V_39 ) {
F_78 ( V_19 , & V_155 , V_24 -> V_38 , V_39 ) ;
}
F_73 ( V_19 , & V_155 , V_24 -> V_202 , V_241 ) ;
F_78 ( V_19 , & V_155 , V_38 , V_24 -> V_40 ) ;
F_30 ( & V_49 -> V_76 . V_264 ) ;
F_96 ( V_3 , V_206 , & V_24 -> V_65 , V_19 , V_207 , V_288 , 1 ,
sizeof( struct V_130 ) + V_393 , 0 ) ;
V_55 -> V_19 = V_19 ;
F_120 ( V_19 ) ;
return V_19 ;
V_402:
F_22 ( V_19 ) ;
V_26:
F_23 ( V_55 -> V_61 ) ;
V_55 -> V_61 = NULL ;
return F_42 ( error ) ;
}
static int F_217 ( T_1 * V_403 , unsigned int V_404 , int V_405 )
{
V_123 V_37 ;
memset ( V_403 , 0 , V_405 ) ;
V_403 += V_405 ;
if ( V_405 >= 4 )
V_405 = 4 ;
else if ( V_404 > ( unsigned int ) ( 1 << ( 8 * V_405 ) ) )
return - V_406 ;
V_37 = F_51 ( V_404 ) ;
memcpy ( V_403 - V_405 , ( T_1 * ) & V_37 + 4 - V_405 , V_405 ) ;
return 0 ;
}
static void F_218 ( struct V_23 * V_24 ,
struct V_1 * V_5 ,
unsigned short V_203 )
{
unsigned int V_407 , V_408 , V_409 ;
int V_410 ;
struct V_29 * V_151 = F_10 ( V_24 ) ;
struct V_392 * V_55 = F_20 ( V_24 ) ;
T_1 * V_411 = V_55 -> V_412 ;
V_409 = F_11 ( V_151 ) ;
memcpy ( V_411 , V_55 -> V_202 , 16 ) ;
V_408 = V_411 [ 0 ] ;
V_407 = V_408 + 1 ;
* V_411 |= ( 8 * ( ( V_409 - 2 ) / 2 ) ) ;
if ( V_24 -> V_39 )
* V_411 |= 64 ;
V_410 = F_217 ( V_411 + 16 - V_407 ,
( V_203 == V_259 ) ?
V_24 -> V_40 - V_409 : V_24 -> V_40 , V_407 ) ;
}
static inline int F_219 ( const T_1 * V_202 )
{
if ( V_202 [ 0 ] < 1 || V_202 [ 0 ] > 7 )
return - V_103 ;
return 0 ;
}
static int F_220 ( struct V_23 * V_24 ,
struct V_1 * V_5 ,
unsigned int V_413 ,
unsigned short V_203 )
{
struct V_392 * V_55 = F_20 ( V_24 ) ;
int V_410 = 0 ;
if ( V_413 == V_414 ) {
V_55 -> V_202 [ 0 ] = 3 ;
memcpy ( V_55 -> V_202 + 1 , & V_5 -> V_415 [ 0 ] , 3 ) ;
memcpy ( V_55 -> V_202 + 4 , V_24 -> V_202 , 8 ) ;
memset ( V_55 -> V_202 + 12 , 0 , 4 ) ;
* ( ( unsigned short * ) ( V_55 -> V_412 + 16 ) ) =
F_64 ( V_24 -> V_39 - 8 ) ;
} else {
memcpy ( V_55 -> V_202 , V_24 -> V_202 , 16 ) ;
* ( ( unsigned short * ) ( V_55 -> V_412 + 16 ) ) =
F_64 ( V_24 -> V_39 ) ;
}
F_218 ( V_24 , V_5 , V_203 ) ;
memset ( V_55 -> V_202 + 15 - V_55 -> V_202 [ 0 ] , 0 , V_55 -> V_202 [ 0 ] + 1 ) ;
return V_410 ;
}
static void F_221 ( struct V_234 * V_248 ,
unsigned int V_393 ,
struct V_23 * V_24 ,
unsigned short V_203 ,
struct V_2 * V_416 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_1 * V_5 = F_1 ( F_204 ( V_30 ) ) ;
unsigned int V_241 = V_242 ;
unsigned int V_417 = V_418 ;
unsigned int V_419 = V_420 ;
unsigned int V_421 = V_416 -> V_16 -> V_226 ;
unsigned int V_422 ;
unsigned char V_423 = 0 , V_424 = 0 ;
unsigned int V_39 ;
if ( F_12 ( V_30 ) == V_414 )
V_39 = V_24 -> V_39 - 8 ;
else
V_39 = V_24 -> V_39 ;
V_422 = V_425 +
( ( V_39 ) ? V_426 : 0 ) ;
V_424 = V_24 -> V_40 ?
( V_39 + V_241 + 1 + V_422 ) : 0 ;
if ( V_203 == V_259 ) {
if ( F_11 ( V_30 ) != V_24 -> V_40 )
V_423 = F_11 ( V_30 ) ;
else
V_424 = 0 ;
}
V_248 -> V_249 = F_113 ( V_421 ,
2 , ( V_241 ? ( V_39 + 1 ) : 0 ) +
V_422 ) ;
V_248 -> V_250 =
F_40 ( V_39 + V_241 + V_24 -> V_40 + V_422 ) ;
V_248 -> V_252 = F_114 (
1 , V_39 + V_422 , V_39
+ V_241 + 1 + V_422 , 0 ) ;
V_248 -> V_253 = F_115 ( 0 ,
V_424 , V_423 ,
( V_203 == V_312 ) ? 0 :
F_11 ( V_30 ) ) ;
V_248 -> V_254 = F_116 ( V_203 ,
( V_203 == V_312 ) ? 0 : 1 ,
V_417 , V_419 ,
V_5 -> V_399 , V_241 >> 1 ) ;
V_248 -> V_256 = F_117 ( 0 , 0 , 1 , 0 ,
1 , V_393 ) ;
}
int F_222 ( unsigned short V_203 ,
struct V_23 * V_24 ,
struct V_1 * V_5 ,
unsigned int V_413 )
{
if ( V_413 != V_414 ) {
if ( F_219 ( V_24 -> V_202 ) ) {
F_48 ( L_18 ) ;
return - V_103 ;
}
} else {
if ( V_24 -> V_39 != 16 && V_24 -> V_39 != 20 ) {
F_48 ( L_19 ,
V_24 -> V_39 ) ;
return - V_103 ;
}
}
if ( V_5 -> V_185 == 0 ) {
F_48 ( L_20 ) ;
return - V_103 ;
}
return 0 ;
}
unsigned int F_223 ( struct V_18 * V_19 ,
struct V_23 * V_24 ,
struct V_132 * V_38 ,
unsigned int V_241 ,
struct V_1 * V_5 )
{
unsigned int V_155 = 0 ;
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_392 * V_55 = F_20 ( V_24 ) ;
F_73 ( V_19 , & V_155 , V_55 -> V_412 , V_425 +
( V_24 -> V_39 ? V_426 : 0 ) ) ;
if ( V_24 -> V_39 ) {
if ( F_12 ( V_30 ) == V_414 )
F_78 ( V_19 , & V_155 , V_24 -> V_38 ,
V_24 -> V_39 - 8 ) ;
else
F_78 ( V_19 , & V_155 , V_24 -> V_38 , V_24 -> V_39 ) ;
}
F_73 ( V_19 , & V_155 , V_55 -> V_202 , V_241 ) ;
if ( V_24 -> V_40 )
F_78 ( V_19 , & V_155 , V_38 , V_24 -> V_40 ) ;
return V_155 ;
}
static struct V_18 * F_224 ( struct V_23 * V_24 ,
unsigned short V_147 ,
int V_288 ,
unsigned short V_203 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_204 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_392 * V_55 = F_20 ( V_24 ) ;
struct V_18 * V_19 = NULL ;
struct V_205 * V_206 ;
struct V_130 * V_131 ;
struct V_134 V_135 ;
struct V_132 * V_38 ;
unsigned int V_155 = 0 , V_239 , V_241 = V_242 ;
unsigned int V_393 = 0 , V_207 , V_140 ;
unsigned int V_413 ;
unsigned int V_31 = F_11 ( V_30 ) ;
int error = - V_103 , V_387 ;
T_3 V_200 = V_24 -> V_65 . V_200 & V_243 ? V_244 :
V_245 ;
struct V_48 * V_49 = F_18 ( V_3 -> V_16 ) ;
V_393 = V_24 -> V_39 + V_24 -> V_40 + ( V_203 ? - V_31 :
V_31 ) ;
V_55 -> V_61 = NULL ;
if ( V_203 && V_24 -> V_40 < F_11 ( V_30 ) )
goto V_26;
V_387 = F_213 ( V_24 -> V_38 , V_24 -> V_39 + V_24 -> V_40 ) ;
if ( V_387 < 0 )
goto V_26;
V_413 = F_12 ( V_30 ) ;
V_38 = F_142 ( V_55 -> V_306 , V_24 -> V_38 , V_24 -> V_39 ) ;
if ( V_24 -> V_38 != V_24 -> V_58 ) {
error = F_200 ( V_24 , V_5 ) ;
if ( error ) {
F_48 ( L_21 ) ;
return F_42 ( error ) ;
}
}
if ( V_393 && F_152 ( V_24 -> V_58 , & V_140 ) ) {
V_55 -> V_61 = F_153 ( V_24 -> V_58 , V_140 ) ;
if ( F_145 ( V_55 -> V_61 ) )
return F_214 ( V_55 -> V_61 ) ;
V_55 -> V_58 = F_142 ( V_55 -> V_307 ,
V_55 -> V_61 , V_24 -> V_39 ) ;
} else {
if ( V_24 -> V_38 == V_24 -> V_58 )
V_55 -> V_58 = V_38 ;
else
V_55 -> V_58 = F_142 ( V_55 -> V_307 ,
V_24 -> V_58 , V_24 -> V_39 ) ;
}
V_55 -> V_59 = F_213 ( V_55 -> V_58 , V_24 -> V_40 +
( V_203 ? - V_31 : V_31 ) ) ;
if ( V_55 -> V_59 < 0 ) {
F_48 ( L_22 ) ;
error = - V_103 ;
goto V_26;
}
error = F_222 ( V_203 , V_24 , V_5 , V_413 ) ;
if ( error )
goto V_26;
V_393 = F_108 ( V_55 -> V_59 ) ;
V_207 = ( ( F_32 ( V_5 -> V_185 , 16 ) ) << 4 ) * 2 ;
V_239 = F_109 ( V_207 , V_393 ) ;
if ( F_202 ( V_24 , V_387 + V_427 ,
V_397 - 18 ,
V_239 + ( F_8 ( V_387 + V_427 ) * 8 ) ,
V_203 ) ) {
F_30 ( & V_49 -> V_76 . V_398 ) ;
F_23 ( V_55 -> V_61 ) ;
V_55 -> V_61 = NULL ;
return F_42 ( F_203 ( V_24 , V_203 ) ) ;
}
V_19 = F_110 ( ( V_239 + sizeof( struct V_246 ) ) , V_200 ) ;
if ( ! V_19 ) {
error = - V_247 ;
goto V_26;
}
F_111 ( V_19 , sizeof( struct V_246 ) ) ;
V_206 = F_112 ( V_19 , V_239 ) ;
F_221 ( & V_206 -> V_248 , V_393 , V_24 , V_203 , V_3 ) ;
V_206 -> V_181 . V_257 = V_5 -> V_258 ;
memcpy ( V_206 -> V_181 . V_81 , V_5 -> V_81 , V_5 -> V_185 ) ;
memcpy ( V_206 -> V_181 . V_81 + ( F_32 ( V_5 -> V_185 , 16 ) *
16 ) , V_5 -> V_81 , V_5 -> V_185 ) ;
V_131 = (struct V_130 * ) ( ( T_1 * ) ( V_206 + 1 ) + V_207 ) ;
error = F_220 ( V_24 , V_5 , V_413 , V_203 ) ;
if ( error )
goto V_402;
V_135 . V_140 = V_55 -> V_59 ;
V_135 . V_139 = V_24 -> V_40 + ( V_203 ? - V_31 : V_31 ) ;
V_135 . V_147 = V_147 ;
error = F_69 ( & V_17 -> V_56 . V_57 -> V_16 , V_131 ,
V_55 -> V_58 , & V_135 ) ;
if ( error )
goto V_402;
F_119 ( V_19 , V_239 ) ;
V_155 = F_223 ( V_19 , V_24 , V_38 , V_241 , V_5 ) ;
F_30 ( & V_49 -> V_76 . V_428 ) ;
F_96 ( V_3 , V_206 , & V_24 -> V_65 , V_19 , V_207 , 0 , 1 ,
sizeof( struct V_130 ) + V_393 , 0 ) ;
V_55 -> V_19 = V_19 ;
F_120 ( V_19 ) ;
return V_19 ;
V_402:
F_22 ( V_19 ) ;
V_26:
F_23 ( V_55 -> V_61 ) ;
V_55 -> V_61 = NULL ;
return F_42 ( error ) ;
}
static struct V_18 * F_225 ( struct V_23 * V_24 ,
unsigned short V_147 ,
int V_288 ,
unsigned short V_203 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_204 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_392 * V_55 = F_20 ( V_24 ) ;
struct V_18 * V_19 = NULL ;
struct V_205 * V_206 ;
struct V_130 * V_131 ;
struct V_134 V_135 ;
struct V_132 * V_38 ;
unsigned int V_155 = 0 , V_239 ;
unsigned int V_241 = V_242 ;
unsigned int V_393 = 0 , V_207 , V_140 , V_39 = V_24 -> V_39 ;
unsigned char V_423 = 0 ;
unsigned int V_31 = F_11 ( V_30 ) ;
int error = - V_103 , V_387 ;
T_3 V_200 = V_24 -> V_65 . V_200 & V_243 ? V_244 :
V_245 ;
struct V_48 * V_49 = F_18 ( V_3 -> V_16 ) ;
V_55 -> V_61 = NULL ;
V_393 = V_39 + V_24 -> V_40 + ( V_203 ? - V_31 :
V_31 ) ;
if ( V_5 -> V_185 == 0 )
goto V_26;
if ( V_203 && V_24 -> V_40 < F_11 ( V_30 ) )
goto V_26;
V_387 = F_213 ( V_24 -> V_38 , V_39 + V_24 -> V_40 ) ;
if ( V_387 < 0 )
goto V_26;
V_38 = F_142 ( V_55 -> V_306 , V_24 -> V_38 , V_39 ) ;
if ( V_24 -> V_38 != V_24 -> V_58 ) {
error = F_200 ( V_24 , V_5 ) ;
if ( error )
return F_42 ( error ) ;
}
if ( V_393 && F_152 ( V_24 -> V_58 , & V_140 ) ) {
V_55 -> V_61 = F_153 ( V_24 -> V_58 , V_140 ) ;
if ( F_145 ( V_55 -> V_61 ) )
return F_214 ( V_55 -> V_61 ) ;
V_55 -> V_58 = F_142 ( V_55 -> V_307 ,
V_55 -> V_61 , V_39 ) ;
} else {
if ( V_24 -> V_38 == V_24 -> V_58 )
V_55 -> V_58 = V_38 ;
else
V_55 -> V_58 = F_142 ( V_55 -> V_307 ,
V_24 -> V_58 , V_39 ) ;
}
V_55 -> V_59 = F_213 ( V_55 -> V_58 , V_24 -> V_40 +
( V_203 ? - V_31 : V_31 ) ) ;
if ( V_55 -> V_59 < 0 ) {
F_48 ( L_23 ) ;
error = - V_103 ;
goto V_26;
}
V_393 = F_108 ( V_55 -> V_59 ) ;
V_207 = ( ( F_32 ( V_5 -> V_185 , 16 ) ) << 4 ) +
V_429 ;
V_239 = F_109 ( V_207 , V_393 ) ;
if ( F_202 ( V_24 , V_387 + V_430 ,
V_397 ,
V_239 + ( F_8 ( V_387 + V_430 ) * 8 ) ,
V_203 ) ) {
F_30 ( & V_49 -> V_76 . V_398 ) ;
F_23 ( V_55 -> V_61 ) ;
V_55 -> V_61 = NULL ;
return F_42 ( F_203 ( V_24 , V_203 ) ) ;
}
V_19 = F_110 ( ( V_239 + sizeof( struct V_246 ) ) , V_200 ) ;
if ( ! V_19 ) {
error = - V_247 ;
goto V_26;
}
F_111 ( V_19 , sizeof( struct V_246 ) ) ;
V_206 = F_112 ( V_19 , V_239 ) ;
if ( F_12 ( V_30 ) == V_35 )
V_39 = V_24 -> V_39 - 8 ;
V_423 = ( V_203 == V_312 ) ? 0 : V_31 ;
V_206 -> V_248 . V_249 = F_113 (
V_3 -> V_16 -> V_226 , 2 , ( V_241 ?
( V_39 + 1 ) : 0 ) ) ;
V_206 -> V_248 . V_250 =
F_40 ( V_39 + V_241 + V_24 -> V_40 ) ;
V_206 -> V_248 . V_252 = F_114 (
V_39 ? 1 : 0 , V_39 ,
V_39 + V_241 + 1 , 0 ) ;
V_206 -> V_248 . V_253 =
F_115 ( 0 , V_39 + V_241 + 1 ,
V_423 , V_423 ) ;
V_206 -> V_248 . V_254 =
F_116 ( V_203 , ( V_203 ==
V_312 ) ? 1 : 0 ,
V_431 ,
V_432 ,
V_5 -> V_399 , V_241 >> 1 ) ;
V_206 -> V_248 . V_256 = F_117 ( 0 , 0 , 1 ,
0 , 1 , V_393 ) ;
V_206 -> V_181 . V_257 = V_5 -> V_258 ;
memcpy ( V_206 -> V_181 . V_81 , V_5 -> V_81 , V_5 -> V_185 ) ;
memcpy ( V_206 -> V_181 . V_81 + ( F_32 ( V_5 -> V_185 , 16 ) *
16 ) , F_4 ( V_5 ) -> V_433 , V_429 ) ;
if ( F_12 ( V_30 ) ==
V_35 ) {
memcpy ( V_55 -> V_202 , V_5 -> V_415 , 4 ) ;
memcpy ( V_55 -> V_202 + 4 , V_24 -> V_202 , 8 ) ;
} else {
memcpy ( V_55 -> V_202 , V_24 -> V_202 , 12 ) ;
}
* ( ( unsigned int * ) ( V_55 -> V_202 + 12 ) ) = F_40 ( 0x01 ) ;
V_131 = (struct V_130 * ) ( ( T_1 * ) ( V_206 + 1 ) + V_207 ) ;
V_135 . V_140 = V_55 -> V_59 ;
V_135 . V_139 = V_24 -> V_40 + ( V_203 ? - V_31 : V_31 ) ;
V_135 . V_147 = V_147 ;
error = F_69 ( & V_17 -> V_56 . V_57 -> V_16 , V_131 ,
V_55 -> V_58 , & V_135 ) ;
if ( error )
goto V_402;
F_119 ( V_19 , V_239 ) ;
F_78 ( V_19 , & V_155 , V_24 -> V_38 , V_39 ) ;
F_73 ( V_19 , & V_155 , V_55 -> V_202 , V_241 ) ;
F_78 ( V_19 , & V_155 , V_38 , V_24 -> V_40 ) ;
F_30 ( & V_49 -> V_76 . V_428 ) ;
F_96 ( V_3 , V_206 , & V_24 -> V_65 , V_19 , V_207 , V_288 , 1 ,
sizeof( struct V_130 ) + V_393 ,
V_55 -> V_62 ) ;
V_55 -> V_19 = V_19 ;
F_120 ( V_19 ) ;
return V_19 ;
V_402:
F_22 ( V_19 ) ;
V_26:
F_23 ( V_55 -> V_61 ) ;
V_55 -> V_61 = NULL ;
return F_42 ( error ) ;
}
static int F_226 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_204 ( V_30 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_152 * V_125 = F_71 ( V_30 ) ;
V_5 -> V_273 = F_227 ( V_125 -> V_65 . V_325 , 0 ,
V_327 |
V_326 ) ;
if ( F_145 ( V_5 -> V_273 ) )
return F_146 ( V_5 -> V_273 ) ;
F_228 ( V_30 , F_229 ( sizeof( struct V_392 ) ,
sizeof( struct V_23 ) +
F_230 ( V_5 -> V_273 ) ) ) ;
V_5 -> null = F_231 () ;
if ( F_145 ( V_5 -> null ) )
return F_146 ( V_5 -> null ) ;
return F_156 ( V_3 ) ;
}
static void F_232 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_204 ( V_30 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_233 () ;
F_234 ( V_5 -> V_273 ) ;
}
static int F_235 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_204 ( V_30 ) ) ;
V_5 -> V_399 = V_434 ;
V_5 -> V_435 = V_64 ;
return F_236 ( V_5 -> V_273 , V_31 ) ;
}
static int F_237 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_204 ( V_30 ) ) ;
T_2 V_436 = F_238 ( V_30 ) ;
if ( V_31 == V_437 ) {
V_5 -> V_399 = V_438 ;
V_5 -> V_435 = V_64 ;
} else if ( V_31 == V_439 ) {
V_5 -> V_399 = V_440 ;
V_5 -> V_435 = V_64 ;
} else if ( V_31 == V_441 ) {
V_5 -> V_399 = V_442 ;
V_5 -> V_435 = V_64 ;
} else if ( V_31 == V_443 ) {
V_5 -> V_399 = V_444 ;
V_5 -> V_435 = V_64 ;
} else if ( V_31 == V_445 ) {
V_5 -> V_399 = V_446 ;
V_5 -> V_435 = V_64 ;
} else if ( V_31 == ( V_436 >> 1 ) ) {
V_5 -> V_399 = V_447 ;
V_5 -> V_435 = V_64 ;
} else if ( V_31 == V_436 ) {
V_5 -> V_399 = V_448 ;
V_5 -> V_435 = V_64 ;
} else {
V_5 -> V_399 = V_448 ;
V_5 -> V_435 = V_63 ;
}
return F_236 ( V_5 -> V_273 , V_31 ) ;
}
static int F_239 ( struct V_29 * V_30 , unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_204 ( V_30 ) ) ;
switch ( V_31 ) {
case V_437 :
V_5 -> V_399 = V_438 ;
V_5 -> V_435 = V_64 ;
break;
case V_449 :
V_5 -> V_399 = V_447 ;
V_5 -> V_435 = V_64 ;
break;
case V_443 :
V_5 -> V_399 = V_444 ;
V_5 -> V_435 = V_64 ;
break;
case V_445 :
V_5 -> V_399 = V_446 ;
V_5 -> V_435 = V_64 ;
break;
case V_450 :
V_5 -> V_399 = V_448 ;
V_5 -> V_435 = V_64 ;
break;
case V_451 :
case V_452 :
V_5 -> V_399 = V_448 ;
V_5 -> V_435 = V_63 ;
break;
default:
F_240 ( (struct V_43 * ) V_30 ,
V_282 ) ;
return - V_103 ;
}
return F_236 ( V_5 -> V_273 , V_31 ) ;
}
static int F_241 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_204 ( V_30 ) ) ;
switch ( V_31 ) {
case V_449 :
V_5 -> V_399 = V_447 ;
V_5 -> V_435 = V_64 ;
break;
case V_443 :
V_5 -> V_399 = V_444 ;
V_5 -> V_435 = V_64 ;
break;
case V_450 :
V_5 -> V_399 = V_448 ;
V_5 -> V_435 = V_64 ;
break;
default:
F_240 ( (struct V_43 * ) V_30 ,
V_282 ) ;
return - V_103 ;
}
return F_236 ( V_5 -> V_273 , V_31 ) ;
}
static int F_242 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_204 ( V_30 ) ) ;
switch ( V_31 ) {
case V_437 :
V_5 -> V_399 = V_438 ;
V_5 -> V_435 = V_64 ;
break;
case V_439 :
V_5 -> V_399 = V_440 ;
V_5 -> V_435 = V_64 ;
break;
case V_449 :
V_5 -> V_399 = V_447 ;
V_5 -> V_435 = V_64 ;
break;
case V_441 :
V_5 -> V_399 = V_442 ;
V_5 -> V_435 = V_64 ;
break;
case V_443 :
V_5 -> V_399 = V_444 ;
V_5 -> V_435 = V_64 ;
break;
case V_445 :
V_5 -> V_399 = V_446 ;
V_5 -> V_435 = V_64 ;
break;
case V_450 :
V_5 -> V_399 = V_448 ;
V_5 -> V_435 = V_64 ;
break;
default:
F_240 ( (struct V_43 * ) V_30 ,
V_282 ) ;
return - V_103 ;
}
return F_236 ( V_5 -> V_273 , V_31 ) ;
}
static int F_243 ( struct V_29 * V_151 ,
const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_2 * V_3 = F_204 ( V_151 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned char V_266 , V_333 ;
int V_453 = 0 ;
V_453 = sizeof( struct V_180 ) +
( ( F_32 ( V_265 , 16 ) ) << 4 ) * 2 ;
if ( V_265 == V_267 ) {
V_333 = V_268 ;
V_266 = V_268 ;
} else if ( V_265 == V_269 ) {
V_266 = V_270 ;
V_333 = V_454 ;
} else if ( V_265 == V_271 ) {
V_266 = V_272 ;
V_333 = V_338 ;
} else {
F_240 ( (struct V_43 * ) V_151 ,
V_282 ) ;
V_5 -> V_185 = 0 ;
return - V_103 ;
}
V_5 -> V_258 = F_128 ( V_266 , V_333 , 0 , 0 ,
V_453 >> 4 ) ;
memcpy ( V_5 -> V_81 , V_81 , V_265 ) ;
V_5 -> V_185 = V_265 ;
return 0 ;
}
static int F_244 ( struct V_29 * V_151 ,
const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_2 * V_3 = F_204 ( V_151 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int error ;
F_245 ( V_5 -> V_273 , V_274 ) ;
F_246 ( V_5 -> V_273 , F_247 ( V_151 ) &
V_274 ) ;
error = F_248 ( V_5 -> V_273 , V_81 , V_265 ) ;
F_245 ( V_151 , V_276 ) ;
F_246 ( V_151 , F_247 ( V_5 -> V_273 ) &
V_276 ) ;
if ( error )
return error ;
return F_243 ( V_151 , V_81 , V_265 ) ;
}
static int F_249 ( struct V_29 * V_151 , const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_2 * V_3 = F_204 ( V_151 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int error ;
if ( V_265 < 3 ) {
F_240 ( (struct V_43 * ) V_151 ,
V_282 ) ;
V_5 -> V_185 = 0 ;
return - V_103 ;
}
F_245 ( V_5 -> V_273 , V_274 ) ;
F_246 ( V_5 -> V_273 , F_247 ( V_151 ) &
V_274 ) ;
error = F_248 ( V_5 -> V_273 , V_81 , V_265 ) ;
F_245 ( V_151 , V_276 ) ;
F_246 ( V_151 , F_247 ( V_5 -> V_273 ) &
V_276 ) ;
if ( error )
return error ;
V_265 -= 3 ;
memcpy ( V_5 -> V_415 , V_81 + V_265 , 3 ) ;
return F_243 ( V_151 , V_81 , V_265 ) ;
}
static int F_250 ( struct V_29 * V_151 , const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_2 * V_3 = F_204 ( V_151 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_10 * V_11 = F_4 ( V_5 ) ;
struct V_293 * V_199 ;
unsigned int V_266 ;
int V_175 = 0 , V_453 = 0 ;
V_5 -> V_185 = 0 ;
F_245 ( V_5 -> V_273 , V_274 ) ;
F_246 ( V_5 -> V_273 , F_247 ( V_151 )
& V_274 ) ;
V_175 = F_248 ( V_5 -> V_273 , V_81 , V_265 ) ;
F_245 ( V_151 , V_276 ) ;
F_246 ( V_151 , F_247 ( V_5 -> V_273 ) &
V_276 ) ;
if ( V_175 )
goto V_296;
if ( F_12 ( V_151 ) == V_35 &&
V_265 > 3 ) {
V_265 -= 4 ;
memcpy ( V_5 -> V_415 , V_81 + V_265 , 4 ) ;
}
if ( V_265 == V_267 ) {
V_266 = V_268 ;
} else if ( V_265 == V_269 ) {
V_266 = V_270 ;
} else if ( V_265 == V_271 ) {
V_266 = V_272 ;
} else {
F_240 ( (struct V_43 * ) V_151 ,
V_282 ) ;
F_48 ( L_24 , V_265 ) ;
V_175 = - V_103 ;
goto V_296;
}
memcpy ( V_5 -> V_81 , V_81 , V_265 ) ;
V_5 -> V_185 = V_265 ;
V_453 = sizeof( struct V_180 ) +
( ( F_32 ( V_265 , 16 ) ) << 4 ) +
V_429 ;
V_5 -> V_258 = F_128 ( V_266 ,
V_455 ,
0 , 0 ,
V_453 >> 4 ) ;
V_199 = F_162 ( L_13 , 0 , 0 ) ;
if ( F_145 ( V_199 ) ) {
V_5 -> V_185 = 0 ;
V_175 = - V_247 ;
goto V_296;
}
V_175 = F_135 ( V_199 , V_81 , V_265 ) ;
if ( V_175 ) {
V_5 -> V_185 = 0 ;
goto V_456;
}
memset ( V_11 -> V_433 , 0 , V_429 ) ;
F_136 ( V_199 , V_11 -> V_433 , V_11 -> V_433 ) ;
V_456:
F_166 ( V_199 ) ;
V_296:
return V_175 ;
}
static int F_251 ( struct V_29 * V_14 , const T_1 * V_81 ,
unsigned int V_265 )
{
struct V_2 * V_3 = F_204 ( V_14 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_391 = F_5 ( V_5 ) ;
struct V_457 V_458 ;
unsigned int V_365 ;
unsigned int V_459 = F_71 ( V_14 ) -> V_460 ;
int V_26 = 0 , V_85 , V_461 = 0 ;
unsigned char V_266 = 0 ;
unsigned char V_462 [ V_374 ] = { 0 } ;
struct V_100 * V_102 = F_42 ( - V_103 ) ;
struct V_330 V_346 ;
int V_463 ;
T_1 * V_464 = NULL ;
F_245 ( V_5 -> V_273 , V_274 ) ;
F_246 ( V_5 -> V_273 , F_247 ( V_14 )
& V_274 ) ;
V_26 = F_248 ( V_5 -> V_273 , V_81 , V_265 ) ;
F_245 ( V_14 , V_276 ) ;
F_246 ( V_14 , F_247 ( V_5 -> V_273 )
& V_276 ) ;
if ( V_26 )
goto V_296;
if ( F_252 ( & V_458 , V_81 , V_265 ) != 0 ) {
F_246 ( V_14 , V_282 ) ;
goto V_296;
}
if ( F_167 ( & V_346 , V_459 ) ) {
F_48 ( L_25 ) ;
goto V_296;
}
if ( V_458 . V_465 == V_267 ) {
V_266 = V_268 ;
} else if ( V_458 . V_465 == V_269 ) {
V_266 = V_270 ;
} else if ( V_458 . V_465 == V_271 ) {
V_266 = V_272 ;
} else {
F_48 ( L_26 ) ;
goto V_296;
}
memcpy ( V_5 -> V_81 , V_458 . V_466 , V_458 . V_465 ) ;
V_5 -> V_185 = V_458 . V_465 ;
F_37 ( V_391 -> V_400 , V_5 -> V_81 ,
V_5 -> V_185 << 3 ) ;
V_102 = F_41 ( V_459 ) ;
if ( F_145 ( V_102 ) ) {
F_48 ( L_27 ) ;
V_5 -> V_185 = 0 ;
return - V_103 ;
}
{
F_183 ( V_375 , V_102 ) ;
V_375 -> V_30 = V_102 ;
V_375 -> V_200 = F_184 ( V_102 ) ;
V_365 = F_253 ( V_102 ) ;
V_463 = F_172 ( V_459 ) ;
V_464 = V_391 -> V_401 + V_346 . V_337 + V_463 ;
if ( V_458 . V_467 > V_365 ) {
V_26 = F_185 ( V_375 , V_458 . V_468 ,
V_458 . V_467 ,
V_464 ) ;
if ( V_26 ) {
F_48 ( L_27 ) ;
goto V_296;
}
V_458 . V_467 = V_459 ;
} else
memcpy ( V_464 , V_458 . V_468 , V_458 . V_467 ) ;
memset ( V_462 + V_458 . V_467 , 0 , V_365 - V_458 . V_467 ) ;
memcpy ( V_462 , V_464 , V_458 . V_467 ) ;
for ( V_85 = 0 ; V_85 < V_365 > > 2 ; V_85 ++ )
* ( ( unsigned int * ) V_462 + V_85 ) ^= V_377 ;
if ( F_44 ( V_375 , V_462 , V_391 -> V_401 ,
V_459 ) )
goto V_296;
memset ( V_462 + V_458 . V_467 , 0 , V_365 - V_458 . V_467 ) ;
memcpy ( V_462 , V_464 , V_458 . V_467 ) ;
for ( V_85 = 0 ; V_85 < V_365 > > 2 ; V_85 ++ )
* ( ( unsigned int * ) V_462 + V_85 ) ^= V_378 ;
if ( F_44 ( V_375 , V_462 , V_464 , V_459 ) )
goto V_296;
F_49 ( V_391 -> V_401 , V_346 . V_337 ) ;
F_49 ( V_464 , V_346 . V_337 ) ;
V_461 = sizeof( struct V_180 ) +
( ( F_32 ( V_458 . V_465 , 16 ) ) << 4 ) +
( V_346 . V_337 + V_463 ) * 2 ;
V_5 -> V_258 = F_128 ( V_266 , V_346 . V_333 ,
0 , 1 , V_461 >> 4 ) ;
V_391 -> V_335 = V_346 . V_335 ;
F_168 ( V_102 ) ;
return 0 ;
}
V_296:
V_5 -> V_185 = 0 ;
if ( ! F_145 ( V_102 ) )
F_168 ( V_102 ) ;
return - V_103 ;
}
static int F_254 ( struct V_29 * V_14 ,
const T_1 * V_81 , unsigned int V_265 )
{
struct V_2 * V_3 = F_204 ( V_14 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_391 = F_5 ( V_5 ) ;
struct V_457 V_458 ;
int V_26 ;
int V_461 = 0 ;
unsigned char V_266 = 0 ;
F_245 ( V_5 -> V_273 , V_274 ) ;
F_246 ( V_5 -> V_273 , F_247 ( V_14 )
& V_274 ) ;
V_26 = F_248 ( V_5 -> V_273 , V_81 , V_265 ) ;
F_245 ( V_14 , V_276 ) ;
F_246 ( V_14 , F_247 ( V_5 -> V_273 )
& V_276 ) ;
if ( V_26 )
goto V_296;
if ( F_252 ( & V_458 , V_81 , V_265 ) != 0 ) {
F_246 ( V_14 , V_282 ) ;
goto V_296;
}
if ( V_458 . V_465 == V_267 ) {
V_266 = V_268 ;
} else if ( V_458 . V_465 == V_269 ) {
V_266 = V_270 ;
} else if ( V_458 . V_465 == V_271 ) {
V_266 = V_272 ;
} else {
F_48 ( L_26 ) ;
goto V_296;
}
memcpy ( V_5 -> V_81 , V_458 . V_466 , V_458 . V_465 ) ;
V_5 -> V_185 = V_458 . V_465 ;
F_37 ( V_391 -> V_400 , V_5 -> V_81 ,
V_5 -> V_185 << 3 ) ;
V_461 = sizeof( struct V_180 )
+ ( ( F_32 ( V_458 . V_465 , 16 ) ) << 4 ) ;
V_5 -> V_258 = F_128 ( V_266 , V_281 , 0 ,
0 , V_461 >> 4 ) ;
V_391 -> V_335 = V_469 ;
return 0 ;
V_296:
V_5 -> V_185 = 0 ;
return - V_103 ;
}
static int F_255 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_392 * V_55 = F_20 ( V_24 ) ;
V_55 -> V_62 = V_64 ;
switch ( F_12 ( V_30 ) ) {
case V_470 :
case V_395 :
return F_256 ( V_24 , V_312 , 0 ,
F_211 ) ;
case V_471 :
case V_414 :
return F_256 ( V_24 , V_312 , 0 ,
F_224 ) ;
default:
return F_256 ( V_24 , V_312 , 0 ,
F_225 ) ;
}
}
static int F_257 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_1 * V_5 = F_1 ( F_204 ( V_30 ) ) ;
struct V_392 * V_55 = F_20 ( V_24 ) ;
int V_288 ;
if ( V_5 -> V_435 == V_63 ) {
V_288 = F_238 ( V_30 ) ;
V_55 -> V_62 = V_63 ;
} else {
V_288 = 0 ;
V_55 -> V_62 = V_64 ;
}
switch ( F_12 ( V_30 ) ) {
case V_470 :
case V_395 :
return F_256 ( V_24 , V_259 , V_288 ,
F_211 ) ;
case V_471 :
case V_414 :
return F_256 ( V_24 , V_259 , V_288 ,
F_224 ) ;
default:
return F_256 ( V_24 , V_259 , V_288 ,
F_225 ) ;
}
}
static int F_256 ( struct V_23 * V_24 ,
unsigned short V_203 ,
int V_288 ,
T_5 V_472 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_204 ( V_30 ) ;
struct V_15 * V_17 ;
struct V_18 * V_19 ;
if ( ! V_3 -> V_16 ) {
F_48 ( L_28 , V_309 ) ;
return - V_473 ;
}
V_17 = F_6 ( V_3 ) ;
if ( F_80 ( V_17 -> V_56 . V_303 [ 0 ] ,
V_3 -> V_228 ) ) {
if ( ! ( V_24 -> V_65 . V_200 & V_304 ) )
return - V_305 ;
}
V_19 = V_472 ( V_24 , V_17 -> V_56 . V_214 [ V_3 -> V_215 ] , V_288 ,
V_203 ) ;
if ( F_145 ( V_19 ) || ! V_19 )
return F_146 ( V_19 ) ;
V_19 -> V_16 = V_17 -> V_56 . V_303 [ 0 ] ;
F_147 ( V_19 , V_310 , V_3 -> V_228 ) ;
F_148 ( V_19 ) ;
return - V_313 ;
}
static int F_258 ( void )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < F_259 ( V_474 ) ; V_85 ++ ) {
switch ( V_474 [ V_85 ] . type & V_52 ) {
case V_67 :
if ( V_474 [ V_85 ] . V_475 )
F_260 (
& V_474 [ V_85 ] . V_125 . V_154 ) ;
break;
case V_53 :
if ( V_474 [ V_85 ] . V_475 )
F_261 (
& V_474 [ V_85 ] . V_125 . V_151 ) ;
break;
case V_68 :
if ( V_474 [ V_85 ] . V_475 )
F_262 (
& V_474 [ V_85 ] . V_125 . V_128 ) ;
break;
}
V_474 [ V_85 ] . V_475 = 0 ;
}
return 0 ;
}
static int F_263 ( void )
{
struct V_124 V_476 ;
struct V_477 * V_478 ;
int V_26 = 0 , V_85 ;
char * V_479 = NULL ;
for ( V_85 = 0 ; V_85 < F_259 ( V_474 ) ; V_85 ++ ) {
if ( V_474 [ V_85 ] . V_475 )
continue;
switch ( V_474 [ V_85 ] . type & V_52 ) {
case V_67 :
V_474 [ V_85 ] . V_125 . V_154 . V_480 =
V_481 ;
V_474 [ V_85 ] . V_125 . V_154 . V_482 = V_483 ;
V_474 [ V_85 ] . V_125 . V_154 . V_51 =
V_67 | V_326 |
V_327 ;
V_474 [ V_85 ] . V_125 . V_154 . V_484 =
sizeof( struct V_2 ) +
sizeof( struct V_6 ) ;
V_474 [ V_85 ] . V_125 . V_154 . V_485 = 0 ;
V_474 [ V_85 ] . V_125 . V_154 . V_486 =
& V_487 ;
V_26 = F_264 ( & V_474 [ V_85 ] . V_125 . V_154 ) ;
V_479 = V_474 [ V_85 ] . V_125 . V_154 . V_488 ;
break;
case V_53 :
V_474 [ V_85 ] . V_125 . V_151 . V_65 . V_51 =
V_53 | V_326 |
V_327 ;
V_474 [ V_85 ] . V_125 . V_151 . V_489 = F_255 ;
V_474 [ V_85 ] . V_125 . V_151 . V_490 = F_257 ;
V_474 [ V_85 ] . V_125 . V_151 . V_369 = F_226 ;
V_474 [ V_85 ] . V_125 . V_151 . exit = F_232 ;
V_474 [ V_85 ] . V_125 . V_151 . V_65 . V_482 = V_483 ;
V_26 = F_265 ( & V_474 [ V_85 ] . V_125 . V_151 ) ;
V_479 = V_474 [ V_85 ] . V_125 . V_151 . V_65 . V_488 ;
break;
case V_68 :
V_478 = & V_474 [ V_85 ] . V_125 . V_128 ;
V_478 -> V_491 = F_174 ;
V_478 -> V_492 = F_177 ;
V_478 -> V_493 = F_178 ;
V_478 -> V_494 = F_179 ;
V_478 -> V_495 = F_180 ;
V_478 -> V_496 = F_181 ;
V_478 -> V_497 . V_498 = V_499 ;
V_478 -> V_497 . V_65 . V_480 = V_481 ;
V_478 -> V_497 . V_65 . V_482 = V_483 ;
V_478 -> V_497 . V_65 . V_51 = V_500 ;
V_478 -> V_497 . V_65 . V_485 = 0 ;
V_478 -> V_497 . V_65 . V_501 = NULL ;
V_478 -> V_497 . V_65 . V_486 = & V_502 ;
if ( V_474 [ V_85 ] . type == V_129 ) {
V_478 -> V_497 . V_65 . V_503 = F_193 ;
V_478 -> V_497 . V_65 . V_501 = F_194 ;
V_478 -> V_369 = F_192 ;
V_478 -> V_504 = F_182 ;
V_478 -> V_497 . V_65 . V_484 = V_505 ;
} else {
V_478 -> V_369 = F_187 ;
V_478 -> V_497 . V_65 . V_484 = V_506 ;
V_478 -> V_497 . V_65 . V_503 = F_189 ;
}
V_26 = F_266 ( & V_474 [ V_85 ] . V_125 . V_128 ) ;
V_476 = V_474 [ V_85 ] . V_125 . V_128 . V_497 . V_65 ;
V_479 = V_476 . V_488 ;
break;
}
if ( V_26 ) {
F_48 ( L_29 ,
V_479 ) ;
goto V_507;
} else {
V_474 [ V_85 ] . V_475 = 1 ;
}
}
return 0 ;
V_507:
F_258 () ;
return V_26 ;
}
int F_267 ( void )
{
return F_263 () ;
}
int F_268 ( void )
{
F_258 () ;
return 0 ;
}
