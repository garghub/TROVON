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
V_34 = memcmp ( & V_33 -> V_37 [ 2 ] , ( V_33 + 1 ) , V_31 ) ;
} else {
F_13 ( V_24 -> V_38 , F_14 ( V_24 -> V_38 ) , V_27 ,
V_31 , V_24 -> V_39 +
V_24 -> V_40 - V_31 ) ;
V_34 = memcmp ( V_27 , ( V_33 + 1 ) , V_31 ) ;
}
if ( V_34 )
* V_26 = - V_41 ;
else
* V_26 = 0 ;
}
int F_15 ( struct V_42 * V_24 , unsigned char * V_25 ,
int V_26 )
{
struct V_43 * V_30 = V_24 -> V_30 ;
struct V_2 * V_3 = F_16 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_44 V_45 ;
struct V_32 * V_33 ;
unsigned int V_46 , V_47 ;
switch ( V_30 -> V_48 -> V_49 & V_50 ) {
case V_51 :
V_45 . V_24 . V_52 = (struct V_23 * ) V_24 ;
V_45 . V_3 . V_53 = F_17 ( V_45 . V_24 . V_52 ) ;
F_18 ( & V_17 -> V_54 . V_55 -> V_16 , V_45 . V_3 . V_53 -> V_56 ,
V_45 . V_3 . V_53 -> V_57 , V_58 ) ;
if ( V_45 . V_3 . V_53 -> V_19 ) {
F_19 ( V_45 . V_3 . V_53 -> V_19 ) ;
V_45 . V_3 . V_53 -> V_19 = NULL ;
}
if ( V_45 . V_3 . V_53 -> V_59 == V_60 ) {
F_9 ( V_45 . V_24 . V_52 , V_25 ,
& V_26 ) ;
V_45 . V_3 . V_53 -> V_59 = V_61 ;
}
break;
case V_62 :
V_45 . V_24 . V_63 = (struct V_64 * ) V_24 ;
V_45 . V_3 . V_6 =
F_20 ( V_45 . V_24 . V_63 ) ;
if ( ! V_26 ) {
V_33 = (struct V_32 * ) V_25 ;
memcpy ( V_45 . V_24 . V_63 -> V_65 , & V_33 -> V_37 [ 2 ] ,
V_66 ) ;
}
F_18 ( & V_17 -> V_54 . V_55 -> V_16 , V_45 . V_24 . V_63 -> V_56 ,
V_45 . V_3 . V_6 -> V_57 , V_58 ) ;
if ( V_45 . V_3 . V_6 -> V_19 ) {
F_19 ( V_45 . V_3 . V_6 -> V_19 ) ;
V_45 . V_3 . V_6 -> V_19 = NULL ;
}
break;
case V_67 :
V_45 . V_24 . V_68 = (struct V_69 * ) V_24 ;
V_45 . V_3 . V_70 =
F_21 ( V_45 . V_24 . V_68 ) ;
V_46 =
F_22 ( F_23 (
V_45 . V_24 . V_68 ) ) ;
V_47 = V_46 ;
if ( V_46 == V_71 )
V_47 = V_72 ;
else if ( V_46 == V_73 )
V_47 = V_28 ;
if ( V_45 . V_3 . V_70 -> V_19 ) {
F_19 ( V_45 . V_3 . V_70 -> V_19 ) ;
V_45 . V_3 . V_70 -> V_19 = NULL ;
}
if ( V_45 . V_3 . V_70 -> V_74 == 1 ) {
V_45 . V_3 . V_70 -> V_74 = 0 ;
memcpy ( V_45 . V_24 . V_68 -> V_74 , V_25 +
sizeof( struct V_32 ) ,
V_46 ) ;
} else {
memcpy ( V_45 . V_3 . V_70 -> V_75 , V_25 +
sizeof( struct V_32 ) ,
V_47 ) ;
}
break;
}
return V_26 ;
}
static inline unsigned int F_24 ( const struct V_18 * V_19 )
{
unsigned int V_76 , V_77 ;
if ( F_7 ( V_19 ) )
return F_25 ( V_19 -> V_20 , 8 ) ;
V_76 = F_26 ( V_19 ) / 8 ;
V_77 = F_27 ( V_19 ) -> V_78 ;
if ( F_28 ( V_19 ) != F_29 ( V_19 ) )
V_77 ++ ;
return V_76 + F_8 ( V_77 ) ;
}
static inline void F_30 ( unsigned char * V_79 ,
const unsigned char * V_80 ,
unsigned int V_81 )
{
T_2 V_27 ;
T_2 V_82 [ V_83 ] ;
int V_84 , V_85 , V_86 ;
T_1 V_87 , V_88 ;
switch ( V_81 ) {
case V_89 :
V_88 = V_90 ;
V_87 = V_91 ;
break;
case V_92 :
V_88 = V_93 ;
V_87 = V_94 ;
break;
case V_95 :
V_88 = V_96 ;
V_87 = V_97 ;
break;
default:
return;
}
for ( V_84 = 0 ; V_84 < V_88 ; V_84 ++ )
V_82 [ V_84 ] = F_31 ( * ( T_2 * ) & V_80 [ 4 * V_84 ] ) ;
V_84 = 0 ;
V_27 = V_82 [ V_88 - 1 ] ;
while ( V_84 + V_88 < ( V_87 + 1 ) * 4 ) {
if ( ! ( V_84 % V_88 ) ) {
V_27 = ( V_27 << 8 ) | ( V_27 >> 24 ) ;
V_27 = F_32 ( V_27 ) ;
V_27 ^= V_98 [ V_84 / V_88 ] ;
} else if ( V_88 == 8 && ( V_84 % 4 == 0 ) ) {
V_27 = F_32 ( V_27 ) ;
}
V_82 [ V_84 % V_88 ] ^= V_27 ;
V_27 = V_82 [ V_84 % V_88 ] ;
V_84 ++ ;
}
V_84 -- ;
for ( V_86 = 0 , V_85 = V_84 % V_88 ; V_86 < V_88 ; V_86 ++ ) {
* ( ( T_2 * ) V_79 + V_86 ) = F_33 ( V_82 [ V_85 ] ) ;
V_85 -- ;
if ( V_85 < 0 )
V_85 += V_88 ;
}
}
static struct V_99 * F_34 ( unsigned int V_100 )
{
struct V_99 * V_101 = F_35 ( - V_102 ) ;
switch ( V_100 ) {
case V_103 :
V_101 = F_36 ( L_1 , 0 , 0 ) ;
break;
case V_71 :
V_101 = F_36 ( L_2 , 0 , 0 ) ;
break;
case V_72 :
V_101 = F_36 ( L_3 , 0 , 0 ) ;
break;
case V_73 :
V_101 = F_36 ( L_4 , 0 , 0 ) ;
break;
case V_28 :
V_101 = F_36 ( L_5 , 0 , 0 ) ;
break;
}
return V_101 ;
}
static int F_37 ( struct V_104 * V_105 ,
char * V_106 , char * V_107 ,
int V_108 )
{
struct V_109 V_110 ;
struct V_111 V_112 ;
struct V_113 V_114 ;
int error ;
if ( V_108 == V_103 ) {
error = F_38 ( V_105 ) ? :
F_39 ( V_105 , V_106 , V_115 ) ? :
F_40 ( V_105 , ( void * ) & V_110 ) ;
memcpy ( V_107 , V_110 . V_116 , V_103 ) ;
} else if ( V_108 == V_71 ) {
error = F_38 ( V_105 ) ? :
F_39 ( V_105 , V_106 , V_117 ) ? :
F_40 ( V_105 , ( void * ) & V_112 ) ;
memcpy ( V_107 , V_112 . V_116 , V_72 ) ;
} else if ( V_108 == V_72 ) {
error = F_38 ( V_105 ) ? :
F_39 ( V_105 , V_106 , V_117 ) ? :
F_40 ( V_105 , ( void * ) & V_112 ) ;
memcpy ( V_107 , V_112 . V_116 , V_72 ) ;
} else if ( V_108 == V_73 ) {
error = F_38 ( V_105 ) ? :
F_39 ( V_105 , V_106 , V_118 ) ? :
F_40 ( V_105 , ( void * ) & V_114 ) ;
memcpy ( V_107 , V_114 . V_116 , V_28 ) ;
} else if ( V_108 == V_28 ) {
error = F_38 ( V_105 ) ? :
F_39 ( V_105 , V_106 , V_118 ) ? :
F_40 ( V_105 , ( void * ) & V_114 ) ;
memcpy ( V_107 , V_114 . V_116 , V_28 ) ;
} else {
error = - V_102 ;
F_41 ( L_6 , V_108 ) ;
}
return error ;
}
static void F_42 ( char * V_119 , int V_100 )
{
int V_84 ;
if ( V_100 == V_28 ) {
for ( V_84 = 0 ; V_84 < ( V_100 / sizeof( V_120 ) ) ; V_84 ++ )
* ( ( V_121 * ) V_119 + V_84 ) =
F_43 ( * ( ( V_120 * ) V_119 + V_84 ) ) ;
} else {
for ( V_84 = 0 ; V_84 < ( V_100 / sizeof( T_2 ) ) ; V_84 ++ )
* ( ( V_122 * ) V_119 + V_84 ) =
F_44 ( * ( ( T_2 * ) V_119 + V_84 ) ) ;
}
}
static inline int F_45 ( struct V_43 * V_30 )
{
struct V_123 * V_124 = V_30 -> V_48 ;
struct V_125 * V_126 =
F_46 ( F_47 ( V_124 ) , struct V_125 ,
V_124 . V_127 ) ;
if ( V_126 -> type == V_128 )
return 1 ;
return 0 ;
}
static void F_48 ( struct V_129 * V_130 ,
struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_135 * V_136 ;
int V_137 = V_134 -> V_138 ;
unsigned int V_139 = V_134 -> V_139 , V_84 , V_85 = 0 ;
V_130 -> V_140 = F_33 ( F_49 ( V_141 )
| F_50 ( 0 ) ) ;
V_130 -> V_142 =
F_33 ( F_51 ( 0 ) |
F_52 ( 0 ) |
F_53 ( 0 ) |
F_54 ( 0 ) |
F_55 ( 0 ) |
F_56 ( V_139 ) ) ;
V_130 -> V_143 . V_144 = V_145 ;
V_130 -> V_143 . V_146 = F_57 ( V_134 -> V_146 ) ;
V_130 -> V_143 . V_147 = 0 ;
V_136 = (struct V_135 * ) ( ( unsigned char * ) V_130 +
sizeof( struct V_129 ) ) ;
for ( V_84 = 0 ; V_139 ; V_136 ++ ) {
for ( V_85 = 0 ; V_85 < 8 && V_139 ; V_85 ++ , V_139 -- ) {
V_137 -= F_58 ( V_132 ) ;
V_136 -> V_20 [ V_85 ] = F_57 ( F_58 ( V_132 ) ) ;
V_136 -> V_148 [ V_85 ] = F_43 ( F_59 ( V_132 ) ) ;
V_132 = F_60 ( V_132 ) ;
}
}
if ( V_137 ) {
V_85 -- ;
V_136 -- ;
V_136 -> V_20 [ V_85 ] = F_57 ( F_61 ( V_136 -> V_20 [ V_85 ] ) + ( V_137 ) ) ;
}
}
static inline int F_62 ( struct V_149 * V_16 ,
struct V_129 * V_130 ,
struct V_131 * V_132 ,
struct V_133 * V_134 )
{
if ( ! V_132 || ! V_134 -> V_139 )
return 0 ;
V_134 -> V_139 = F_63 ( V_16 , V_132 , V_134 -> V_139 , V_58 ) ;
if ( V_134 -> V_139 == 0 ) {
F_41 ( L_7 ) ;
return - V_102 ;
}
F_48 ( V_130 , V_132 , V_134 ) ;
return 0 ;
}
static inline int F_12 ( struct V_29 * V_150 )
{
struct V_151 * V_124 = F_64 ( V_150 ) ;
struct V_125 * V_126 =
F_46 ( V_124 , struct V_125 , V_124 . V_150 ) ;
return V_126 -> type & V_152 ;
}
static inline int F_65 ( struct V_43 * V_30 )
{
struct V_123 * V_124 = V_30 -> V_48 ;
struct V_125 * V_126 =
F_46 ( V_124 , struct V_125 , V_124 . V_153 ) ;
return V_126 -> type & V_152 ;
}
static inline void F_66 ( struct V_18 * V_19 ,
unsigned int * V_154 ,
char * V_155 ,
T_1 V_156 )
{
V_19 -> V_20 += V_156 ;
V_19 -> V_157 += V_156 ;
V_19 -> V_158 += V_156 ;
F_67 ( F_68 ( V_155 ) ) ;
F_69 ( V_19 , * V_154 , F_68 ( V_155 ) ,
F_70 ( V_155 ) , V_156 ) ;
( * V_154 ) ++ ;
}
static inline void
F_71 ( struct V_18 * V_19 , unsigned int * V_154 ,
struct V_131 * V_132 , unsigned int V_159 )
{
struct V_160 * V_161 ;
unsigned int V_162 ;
V_19 -> V_20 += V_159 ;
V_19 -> V_157 += V_159 ;
V_19 -> V_158 += V_159 ;
while ( V_159 > 0 ) {
if ( ! V_132 || ( ! ( V_132 -> V_163 ) ) )
break;
V_161 = F_72 ( V_132 ) ;
F_67 ( V_161 ) ;
V_162 = F_73 ( V_132 -> V_163 , V_159 ) ;
F_69 ( V_19 , * V_154 , V_161 , V_132 -> V_164 , V_162 ) ;
( * V_154 ) ++ ;
V_159 -= V_162 ;
V_132 = F_60 ( V_132 ) ;
}
}
static int F_74 ( struct V_6 * V_7 ,
struct V_165 * V_166 )
{
if ( V_7 -> V_167 == V_168 ) {
memcpy ( V_166 -> V_80 , V_7 -> V_169 , V_7 -> V_170 ) ;
} else {
memcpy ( V_166 -> V_80 ,
V_7 -> V_80 + ( V_7 -> V_170 >> 1 ) ,
V_7 -> V_170 >> 1 ) ;
memcpy ( V_166 -> V_80 + ( V_7 -> V_170 >> 1 ) ,
V_7 -> V_169 , V_7 -> V_170 >> 1 ) ;
}
return 0 ;
}
static inline void F_75 ( struct V_2 * V_3 ,
struct V_171 * V_172 ,
void * V_24 , struct V_18 * V_19 ,
int V_173 , int V_174 ,
int V_175 ,
unsigned int V_176 )
{
struct V_15 * V_17 = F_6 ( V_3 ) ;
int V_177 = V_178 ;
int V_146 = V_17 -> V_54 . V_179 [ V_3 -> V_180 ] ;
unsigned int V_181 = 0 , V_78 = 0 ;
if ( F_7 ( V_19 ) ) {
V_181 = V_19 -> V_157 ;
V_177 = V_182 ;
} else {
V_78 = F_27 ( V_19 ) -> V_78 ;
}
V_172 -> V_183 . V_184 = F_76 ( V_181 ,
( ( sizeof( V_172 -> V_166 ) + V_173 ) >> 4 ) ) ;
V_172 -> V_183 . V_185 =
F_33 ( F_77 ( V_186 [ V_78 ] ) |
F_78 ( V_174 ) ) ;
V_172 -> V_183 . V_187 =
F_33 ( F_79 ( F_25 (
( F_24 ( V_19 ) * 8 ) , 16 ) ) ) ;
V_172 -> V_183 . V_188 = F_43 ( ( V_189 ) V_24 ) ;
V_172 -> V_183 . V_190 =
F_80 ( V_3 -> V_16 -> V_191 , V_146 ,
V_175 ? V_177 : V_192 , V_3 -> V_193 ) ;
V_172 -> V_194 . V_195 = F_81 ( V_3 -> V_16 -> V_196 ,
V_146 ) ;
V_172 -> V_194 . V_20 = F_33 ( ( F_25 ( ( F_24 ( V_19 ) * 8 ) ,
16 ) - ( ( sizeof( V_172 -> V_183 ) ) >> 4 ) ) ) ;
V_172 -> V_197 . V_198 = F_82 ( V_181 ) ;
V_172 -> V_197 . V_20 = F_44 ( sizeof( struct V_199 ) +
sizeof( V_172 -> V_166 ) +
V_173 + V_176 + V_181 ) ;
}
static struct V_18
* F_83 ( struct V_64 * V_24 ,
unsigned short V_146 ,
unsigned short V_200 )
{
struct V_201 * V_30 = F_84 ( V_24 ) ;
struct V_2 * V_3 = F_85 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
struct V_129 * V_130 ;
struct V_202 * V_53 = F_20 ( V_24 ) ;
struct V_133 V_134 ;
unsigned int V_154 = 0 , V_203 , V_204 ;
unsigned int V_205 = F_86 ( V_30 ) , V_173 ;
T_3 V_206 = V_24 -> V_207 . V_206 & V_208 ? V_209 :
V_210 ;
if ( ! V_24 -> V_65 )
return F_35 ( - V_102 ) ;
V_53 -> V_57 = F_87 ( V_24 -> V_56 , V_24 -> V_211 ) ;
if ( V_53 -> V_57 <= 0 ) {
F_41 ( L_8 ) ;
return F_35 ( - V_102 ) ;
}
if ( ( V_7 -> V_170 == 0 ) || ( V_205 > V_66 ) ||
( V_24 -> V_211 <= 0 ) || ( V_24 -> V_211 % V_66 ) ) {
F_41 ( L_9 ,
V_7 -> V_170 , V_24 -> V_211 , V_205 ) ;
return F_35 ( - V_102 ) ;
}
V_204 = F_88 ( V_53 -> V_57 ) ;
V_173 = ( F_25 ( V_7 -> V_170 , 16 ) * 16 ) ;
V_203 = F_89 ( V_173 , V_204 ) ;
V_19 = F_90 ( ( V_203 + sizeof( struct V_212 ) ) , V_206 ) ;
if ( ! V_19 )
return F_35 ( - V_213 ) ;
F_91 ( V_19 , sizeof( struct V_212 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_203 ) ;
memset ( V_172 , 0 , V_203 ) ;
V_172 -> V_214 . V_215 =
F_93 ( V_3 -> V_16 -> V_191 , 2 , 1 ) ;
V_172 -> V_214 . V_216 = F_33 ( V_205 + V_24 -> V_211 ) ;
V_172 -> V_214 . V_217 =
F_94 ( 0 , 0 , V_205 + 1 , 0 ) ;
V_172 -> V_214 . V_218 =
F_95 ( 0 , 0 , 0 , 0 ) ;
V_172 -> V_214 . V_219 = F_96 ( V_200 , 0 ,
V_7 -> V_167 ,
0 , 0 , V_205 >> 1 ) ;
V_172 -> V_214 . V_220 = F_97 ( 0 , 0 , 0 ,
0 , 1 , V_204 ) ;
V_172 -> V_166 . V_221 = V_7 -> V_222 ;
if ( V_200 == V_223 ) {
F_74 ( V_7 , & V_172 -> V_166 ) ;
} else {
if ( V_7 -> V_167 == V_168 ) {
memcpy ( V_172 -> V_166 . V_80 , V_7 -> V_80 ,
V_7 -> V_170 ) ;
} else {
memcpy ( V_172 -> V_166 . V_80 , V_7 -> V_80 +
( V_7 -> V_170 >> 1 ) ,
V_7 -> V_170 >> 1 ) ;
memcpy ( V_172 -> V_166 . V_80 +
( V_7 -> V_170 >> 1 ) ,
V_7 -> V_80 ,
V_7 -> V_170 >> 1 ) ;
}
}
V_130 = (struct V_129 * ) ( ( T_1 * ) ( V_172 + 1 ) + V_173 ) ;
V_134 . V_139 = V_53 -> V_57 ;
V_134 . V_138 = V_24 -> V_211 ;
V_134 . V_146 = V_146 ;
V_134 . V_224 = 1 ;
if ( F_62 ( & V_17 -> V_54 . V_55 -> V_16 , V_130 , V_24 -> V_56 ,
& V_134 ) )
goto V_225;
F_98 ( V_19 , V_203 ) ;
memcpy ( V_53 -> V_226 , V_24 -> V_65 , V_205 ) ;
F_66 ( V_19 , & V_154 , V_53 -> V_226 , V_205 ) ;
F_71 ( V_19 , & V_154 , V_24 -> V_38 , V_24 -> V_211 ) ;
F_75 ( V_3 , V_172 , V_24 , V_19 , V_173 , 0 , 1 ,
sizeof( struct V_129 ) + V_204 ) ;
V_53 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
V_225:
F_19 ( V_19 ) ;
return F_35 ( - V_213 ) ;
}
static int F_100 ( struct V_201 * V_30 , const T_1 * V_80 ,
unsigned int V_227 )
{
struct V_2 * V_3 = F_85 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned int V_228 , V_229 ;
T_4 V_230 = 0 ;
if ( V_227 == V_231 ) {
V_228 = V_232 ;
} else if ( V_227 == V_233 ) {
V_230 = 8 ;
V_228 = V_234 ;
} else if ( V_227 == V_235 ) {
V_228 = V_236 ;
} else {
goto V_237;
}
memcpy ( V_7 -> V_80 , V_80 , V_227 ) ;
V_7 -> V_170 = V_227 ;
F_30 ( V_7 -> V_169 , V_7 -> V_80 , V_227 << 3 ) ;
V_229 = ( V_238 +
V_227 + V_230 ) >> 4 ;
V_7 -> V_222 = F_101 ( V_228 , V_239 ,
0 , 0 , V_229 ) ;
V_7 -> V_167 = V_168 ;
return 0 ;
V_237:
F_102 ( V_30 , V_240 ) ;
V_7 -> V_170 = 0 ;
return - V_102 ;
}
static int F_103 ( struct V_241 * V_16 , unsigned int V_242 )
{
struct V_243 * V_244 = F_104 ( V_16 ) ;
struct V_245 * V_246 =
V_244 -> V_247 . V_248 [ V_249 ] ;
struct V_250 * V_251 ;
int V_252 = 0 ;
F_105 () ;
V_251 = & V_246 -> V_253 [ V_242 ] ;
F_106 ( & V_251 -> V_254 . V_255 ) ;
if ( V_251 -> V_256 )
V_252 = - 1 ;
F_107 ( & V_251 -> V_254 . V_255 ) ;
F_108 () ;
return V_252 ;
}
static int F_109 ( struct V_64 * V_24 )
{
struct V_201 * V_30 = F_84 ( V_24 ) ;
struct V_2 * V_3 = F_85 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_18 * V_19 ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_257 [ 0 ] ,
V_3 -> V_193 ) ) ) {
if ( ! ( V_24 -> V_207 . V_206 & V_258 ) )
return - V_259 ;
}
V_19 = F_83 ( V_24 , V_17 -> V_54 . V_179 [ V_3 -> V_180 ] ,
V_260 ) ;
if ( F_111 ( V_19 ) ) {
F_41 ( L_10 , V_261 ) ;
return F_112 ( V_19 ) ;
}
V_19 -> V_16 = V_17 -> V_54 . V_257 [ 0 ] ;
F_113 ( V_19 , V_262 , V_3 -> V_193 ) ;
F_114 ( V_19 ) ;
return - V_263 ;
}
static int F_115 ( struct V_64 * V_24 )
{
struct V_201 * V_30 = F_84 ( V_24 ) ;
struct V_2 * V_3 = F_85 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_18 * V_19 ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_257 [ 0 ] ,
V_3 -> V_193 ) ) ) {
if ( ! ( V_24 -> V_207 . V_206 & V_258 ) )
return - V_259 ;
}
V_19 = F_83 ( V_24 , V_17 -> V_54 . V_179 [ V_3 -> V_180 ] ,
V_223 ) ;
if ( F_111 ( V_19 ) ) {
F_41 ( L_10 , V_261 ) ;
return F_112 ( V_19 ) ;
}
V_19 -> V_16 = V_17 -> V_54 . V_257 [ 0 ] ;
F_113 ( V_19 , V_262 , V_3 -> V_193 ) ;
F_114 ( V_19 ) ;
return - V_263 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_15 * V_17 ;
struct V_243 * V_244 ;
unsigned int V_264 ;
int V_265 , V_266 , V_267 ;
int V_26 = 0 , V_268 , V_269 ;
V_264 = F_117 () ;
if ( ! V_3 -> V_16 ) {
V_26 = F_118 ( & V_3 -> V_16 ) ;
if ( V_26 ) {
F_41 ( L_11 ) ;
goto V_270;
}
V_17 = F_6 ( V_3 ) ;
V_244 = F_119 ( V_3 -> V_16 ) ;
V_267 = F_120 ( ( unsigned int ) V_17 -> V_54 . V_271 ,
V_244 -> V_272 . V_273 ) ;
V_268 = V_17 -> V_54 . V_271 / V_17 -> V_54 . V_274 ;
V_265 = V_267 / V_17 -> V_54 . V_274 ;
V_269 = V_3 -> V_16 -> V_196 * V_268 ;
V_269 += V_264 % V_268 ;
V_266 = V_3 -> V_16 -> V_196 * V_265 ;
V_266 += V_264 % V_265 ;
F_106 ( & V_3 -> V_16 -> V_275 ) ;
V_3 -> V_180 = V_269 ;
V_3 -> V_193 = V_266 ;
V_3 -> V_16 -> V_196 = ! V_3 -> V_16 -> V_196 ;
V_3 -> V_16 -> V_191 = 0 ;
F_107 ( & V_3 -> V_16 -> V_275 ) ;
}
V_270:
return V_26 ;
}
static int F_121 ( struct V_43 * V_30 )
{
V_30 -> V_276 . V_277 = sizeof( struct V_202 ) ;
return F_116 ( F_16 ( V_30 ) ) ;
}
static int F_122 ( struct V_278 * V_279 ,
unsigned int V_280 )
{
switch ( V_280 ) {
case V_103 :
V_279 -> V_281 = V_282 ;
V_279 -> V_283 = V_284 ;
V_279 -> V_285 = V_103 ;
break;
case V_71 :
V_279 -> V_281 = V_286 ;
V_279 -> V_283 = V_287 ;
V_279 -> V_285 = V_72 ;
break;
case V_72 :
V_279 -> V_281 = V_286 ;
V_279 -> V_283 = V_288 ;
V_279 -> V_285 = V_72 ;
break;
case V_73 :
V_279 -> V_281 = V_289 ;
V_279 -> V_283 = V_290 ;
V_279 -> V_285 = V_28 ;
break;
case V_28 :
V_279 -> V_281 = V_289 ;
V_279 -> V_283 = V_291 ;
V_279 -> V_285 = V_28 ;
break;
default:
F_41 ( L_12 ) ;
return - V_102 ;
}
return 0 ;
}
static inline void F_123 ( struct V_99 * V_101 )
{
F_124 ( V_101 ) ;
}
static struct V_18 * F_125 ( struct V_69 * V_24 ,
struct V_292 * V_293 )
{
struct V_294 * V_295 = F_21 ( V_24 ) ;
struct V_296 * V_30 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_126 ( V_30 ) ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
unsigned int V_154 = 0 , V_203 , V_297 = 0 ;
unsigned int V_46 = F_22 ( V_30 ) ;
unsigned int V_173 = 0 ;
T_1 V_298 = 0 ;
T_3 V_206 = V_24 -> V_207 . V_206 & V_208 ? V_209 :
V_210 ;
V_297 = F_127 ( V_46 ) ;
V_173 = V_293 -> V_299 . V_285 + V_297 ;
if ( V_293 -> V_300 )
V_173 += V_293 -> V_299 . V_285 + V_297 ;
if ( V_295 -> V_74 )
V_298 = V_46 ;
else
V_298 = V_293 -> V_299 . V_285 ;
V_203 = F_128 ( V_173 ) ;
V_19 = F_90 ( ( V_203 + sizeof( struct V_212 ) ) , V_206 ) ;
if ( ! V_19 )
return V_19 ;
F_91 ( V_19 , sizeof( struct V_212 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_203 ) ;
memset ( V_172 , 0 , V_203 ) ;
V_172 -> V_214 . V_215 =
F_93 ( V_3 -> V_16 -> V_191 , 2 , 0 ) ;
V_172 -> V_214 . V_216 = F_33 ( V_293 -> V_156 + V_293 -> V_301 ) ;
V_172 -> V_214 . V_217 =
F_94 ( 0 , 0 , 0 , 0 ) ;
V_172 -> V_214 . V_218 =
F_95 ( 0 , 1 , 0 , 0 ) ;
V_172 -> V_214 . V_219 =
F_96 ( 0 , 0 , 0 , V_293 -> V_299 . V_283 ,
V_293 -> V_300 , 0 ) ;
V_172 -> V_214 . V_220 =
F_97 ( V_293 -> V_302 , V_293 -> V_303 , 0 , 1 , 0 , 0 ) ;
memcpy ( V_172 -> V_166 . V_80 , V_295 -> V_75 ,
V_293 -> V_299 . V_285 ) ;
if ( V_293 -> V_300 )
memcpy ( V_172 -> V_166 . V_80 +
( ( V_293 -> V_299 . V_285 <= 32 ) ? 32 :
V_304 ) ,
V_9 -> V_305 , V_293 -> V_299 . V_285 ) ;
V_172 -> V_166 . V_221 = F_101 ( V_239 ,
V_293 -> V_299 . V_281 , 0 ,
V_293 -> V_300 ,
( ( V_173 +
sizeof( V_172 -> V_166 ) ) >> 4 ) ) ;
V_172 -> V_214 . V_306 = F_43 ( ( V_120 ) V_293 -> V_306 ) ;
F_98 ( V_19 , V_203 ) ;
if ( V_293 -> V_156 != 0 )
F_66 ( V_19 , & V_154 , V_295 -> V_307 ,
V_293 -> V_156 ) ;
if ( V_293 -> V_301 != 0 )
F_71 ( V_19 , & V_154 , V_24 -> V_38 , V_293 -> V_301 ) ;
F_75 ( V_3 , V_172 , V_24 , V_19 , V_173 , V_298 , 0 ,
V_308 ) ;
V_295 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
}
static int F_129 ( struct V_69 * V_24 )
{
struct V_294 * V_295 = F_21 ( V_24 ) ;
struct V_296 * V_309 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_126 ( V_309 ) ) ;
struct V_15 * V_17 = NULL ;
struct V_18 * V_19 ;
T_1 V_310 = 0 , V_311 ;
unsigned int V_211 = V_24 -> V_211 ;
struct V_292 V_279 ;
V_311 = F_130 ( F_126 ( V_309 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_257 [ 0 ] ,
V_3 -> V_193 ) ) ) {
if ( ! ( V_24 -> V_207 . V_206 & V_258 ) )
return - V_259 ;
}
if ( V_211 + V_295 -> V_312 >= V_311 ) {
V_310 = ( V_211 + V_295 -> V_312 ) % V_311 ;
V_211 = V_211 + V_295 -> V_312 - V_310 ;
} else {
F_13 ( V_24 -> V_38 , F_14 ( V_24 -> V_38 ) , V_295 -> V_307
+ V_295 -> V_312 , V_211 , 0 ) ;
V_295 -> V_312 += V_211 ;
return 0 ;
}
V_279 . V_300 = 0 ;
V_279 . V_303 = 1 ;
V_279 . V_302 = 0 ;
V_279 . V_301 = V_211 - V_295 -> V_312 ;
V_279 . V_156 = V_295 -> V_312 ;
V_279 . V_306 = 0 ;
F_122 ( & V_279 . V_299 , F_22 ( V_309 ) ) ;
V_295 -> V_74 = 0 ;
V_295 -> V_157 += V_279 . V_301 + V_279 . V_156 ;
V_19 = F_125 ( V_24 , & V_279 ) ;
if ( ! V_19 )
return - V_213 ;
if ( V_310 ) {
T_1 * V_27 ;
V_27 = V_295 -> V_307 ;
V_295 -> V_307 = V_295 -> V_313 ;
V_295 -> V_313 = V_27 ;
F_13 ( V_24 -> V_38 , F_14 ( V_24 -> V_38 ) ,
V_295 -> V_307 , V_310 , V_24 -> V_211 -
V_310 ) ;
}
V_295 -> V_312 = V_310 ;
V_19 -> V_16 = V_17 -> V_54 . V_257 [ 0 ] ;
F_113 ( V_19 , V_262 , V_3 -> V_193 ) ;
F_114 ( V_19 ) ;
return - V_263 ;
}
static void F_131 ( char * V_314 , unsigned int V_311 , V_120 V_306 )
{
memset ( V_314 , 0 , V_311 ) ;
* V_314 = 0x80 ;
if ( V_311 == 64 )
* ( V_121 * ) ( V_314 + 56 ) = F_43 ( V_306 << 3 ) ;
else
* ( V_121 * ) ( V_314 + 120 ) = F_43 ( V_306 << 3 ) ;
}
static int F_132 ( struct V_69 * V_24 )
{
struct V_294 * V_295 = F_21 ( V_24 ) ;
struct V_296 * V_309 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_126 ( V_309 ) ) ;
struct V_292 V_279 ;
struct V_18 * V_19 ;
struct V_15 * V_17 = NULL ;
T_1 V_311 = F_130 ( F_126 ( V_309 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_45 ( F_126 ( V_309 ) ) )
V_279 . V_300 = 1 ;
else
V_279 . V_300 = 0 ;
V_279 . V_301 = 0 ;
F_122 ( & V_279 . V_299 , F_22 ( V_309 ) ) ;
V_295 -> V_74 = 1 ;
V_279 . V_156 = V_295 -> V_312 ;
V_295 -> V_157 += V_279 . V_156 + V_279 . V_301 ;
if ( V_295 -> V_312 == 0 ) {
F_131 ( V_295 -> V_307 , V_311 , V_295 -> V_157 ) ;
V_279 . V_302 = 0 ;
V_279 . V_303 = 1 ;
V_279 . V_306 = 0 ;
V_279 . V_156 = V_311 ;
} else {
V_279 . V_306 = V_295 -> V_157 ;
V_279 . V_302 = 1 ;
V_279 . V_303 = 0 ;
}
V_19 = F_125 ( V_24 , & V_279 ) ;
if ( ! V_19 )
return - V_213 ;
V_19 -> V_16 = V_17 -> V_54 . V_257 [ 0 ] ;
F_113 ( V_19 , V_262 , V_3 -> V_193 ) ;
F_114 ( V_19 ) ;
return - V_263 ;
}
static int F_133 ( struct V_69 * V_24 )
{
struct V_294 * V_295 = F_21 ( V_24 ) ;
struct V_296 * V_309 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_126 ( V_309 ) ) ;
struct V_15 * V_17 = NULL ;
struct V_18 * V_19 ;
struct V_292 V_279 ;
T_1 V_311 ;
V_311 = F_130 ( F_126 ( V_309 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_257 [ 0 ] ,
V_3 -> V_193 ) ) ) {
if ( ! ( V_24 -> V_207 . V_206 & V_258 ) )
return - V_259 ;
}
if ( F_45 ( F_126 ( V_309 ) ) )
V_279 . V_300 = 1 ;
else
V_279 . V_300 = 0 ;
V_279 . V_301 = V_24 -> V_211 ;
V_279 . V_156 = V_295 -> V_312 ;
F_122 ( & V_279 . V_299 , F_22 ( V_309 ) ) ;
V_295 -> V_157 += V_279 . V_156 + V_279 . V_301 ;
V_295 -> V_74 = 1 ;
if ( ( V_295 -> V_312 + V_24 -> V_211 ) == 0 ) {
F_131 ( V_295 -> V_307 , V_311 , V_295 -> V_157 ) ;
V_279 . V_302 = 0 ;
V_279 . V_303 = 1 ;
V_279 . V_306 = 0 ;
V_279 . V_156 = V_311 ;
} else {
V_279 . V_306 = V_295 -> V_157 ;
V_279 . V_302 = 1 ;
V_279 . V_303 = 0 ;
}
V_19 = F_125 ( V_24 , & V_279 ) ;
if ( ! V_19 )
return - V_213 ;
V_19 -> V_16 = V_17 -> V_54 . V_257 [ 0 ] ;
F_113 ( V_19 , V_262 , V_3 -> V_193 ) ;
F_114 ( V_19 ) ;
return - V_263 ;
}
static int F_134 ( struct V_69 * V_24 )
{
struct V_294 * V_295 = F_21 ( V_24 ) ;
struct V_296 * V_309 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_126 ( V_309 ) ) ;
struct V_15 * V_17 = NULL ;
struct V_18 * V_19 ;
struct V_292 V_279 ;
T_1 V_311 ;
V_309 -> V_315 ( V_24 ) ;
V_311 = F_130 ( F_126 ( V_309 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_257 [ 0 ] ,
V_3 -> V_193 ) ) ) {
if ( ! ( V_24 -> V_207 . V_206 & V_258 ) )
return - V_259 ;
}
if ( F_45 ( F_126 ( V_309 ) ) )
V_279 . V_300 = 1 ;
else
V_279 . V_300 = 0 ;
V_279 . V_302 = 0 ;
V_279 . V_303 = 0 ;
V_279 . V_301 = V_24 -> V_211 ;
V_279 . V_156 = 0 ;
V_279 . V_306 = 0 ;
F_122 ( & V_279 . V_299 , F_22 ( V_309 ) ) ;
V_295 -> V_74 = 1 ;
V_295 -> V_157 += V_279 . V_156 + V_279 . V_301 ;
if ( V_24 -> V_211 == 0 ) {
F_131 ( V_295 -> V_307 , V_311 , 0 ) ;
V_279 . V_303 = 1 ;
V_279 . V_156 = V_311 ;
}
V_19 = F_125 ( V_24 , & V_279 ) ;
if ( ! V_19 )
return - V_213 ;
V_19 -> V_16 = V_17 -> V_54 . V_257 [ 0 ] ;
F_113 ( V_19 , V_262 , V_3 -> V_193 ) ;
F_114 ( V_19 ) ;
return - V_263 ;
}
static int F_135 ( struct V_69 * V_316 , void * V_270 )
{
struct V_294 * V_295 = F_21 ( V_316 ) ;
struct V_294 * V_116 = V_270 ;
V_116 -> V_312 = V_295 -> V_312 ;
V_116 -> V_157 = V_295 -> V_157 ;
memcpy ( V_116 -> V_317 , V_295 -> V_307 , V_295 -> V_312 ) ;
memcpy ( V_116 -> V_75 , V_295 -> V_75 ,
V_304 ) ;
return 0 ;
}
static int F_136 ( struct V_69 * V_316 , const void * V_318 )
{
struct V_294 * V_295 = F_21 ( V_316 ) ;
struct V_294 * V_116 = (struct V_294 * ) V_318 ;
V_295 -> V_312 = V_116 -> V_312 ;
V_295 -> V_157 = V_116 -> V_157 ;
V_295 -> V_307 = V_295 -> V_317 ;
V_295 -> V_313 = V_295 -> V_319 ;
memcpy ( V_295 -> V_317 , V_116 -> V_317 , V_320 ) ;
memcpy ( V_295 -> V_75 , V_116 -> V_75 ,
V_304 ) ;
return 0 ;
}
static int F_137 ( struct V_296 * V_30 , const T_1 * V_80 ,
unsigned int V_227 )
{
struct V_2 * V_3 = F_16 ( F_126 ( V_30 ) ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
unsigned int V_46 = F_22 ( V_30 ) ;
unsigned int V_311 = F_130 ( F_126 ( V_30 ) ) ;
unsigned int V_84 , V_26 = 0 , V_47 ;
F_138 ( V_321 , V_9 -> V_101 ) ;
V_321 -> V_30 = V_9 -> V_101 ;
V_321 -> V_206 = F_139 ( V_9 -> V_101 ) ;
if ( V_227 > V_311 ) {
V_26 = F_140 ( V_321 , V_80 , V_227 ,
V_9 -> V_322 ) ;
if ( V_26 )
goto V_270;
V_227 = V_46 ;
} else {
memcpy ( V_9 -> V_322 , V_80 , V_227 ) ;
}
memset ( V_9 -> V_322 + V_227 , 0 , V_311 - V_227 ) ;
memcpy ( V_9 -> V_305 , V_9 -> V_322 , V_311 ) ;
for ( V_84 = 0 ; V_84 < V_311 / sizeof( int ) ; V_84 ++ ) {
* ( ( unsigned int * ) ( & V_9 -> V_322 ) + V_84 ) ^= V_323 ;
* ( ( unsigned int * ) ( & V_9 -> V_305 ) + V_84 ) ^= V_324 ;
}
V_47 = V_46 ;
if ( V_46 == V_71 )
V_47 = V_72 ;
else if ( V_46 == V_73 )
V_47 = V_28 ;
V_26 = F_37 ( V_321 , V_9 -> V_322 ,
V_9 -> V_322 , V_46 ) ;
if ( V_26 )
goto V_270;
F_42 ( V_9 -> V_322 , V_47 ) ;
V_26 = F_37 ( V_321 , V_9 -> V_305 ,
V_9 -> V_305 , V_46 ) ;
if ( V_26 )
goto V_270;
F_42 ( V_9 -> V_305 , V_47 ) ;
V_270:
return V_26 ;
}
static int F_141 ( struct V_201 * V_30 , const T_1 * V_80 ,
unsigned int V_325 )
{
struct V_2 * V_3 = F_85 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned short V_229 = 0 ;
if ( ( V_325 != ( V_231 << 1 ) ) &&
( V_325 != ( V_235 << 1 ) ) ) {
F_142 ( (struct V_43 * ) V_30 ,
V_240 ) ;
V_7 -> V_170 = 0 ;
return - V_102 ;
}
memcpy ( V_7 -> V_80 , V_80 , V_325 ) ;
V_7 -> V_170 = V_325 ;
F_30 ( V_7 -> V_169 , V_7 -> V_80 , V_325 << 2 ) ;
V_229 = ( V_238 + V_325 ) >> 4 ;
V_7 -> V_222 =
F_101 ( ( V_325 == V_235 ) ?
V_232 :
V_236 ,
V_239 , 1 ,
0 , V_229 ) ;
V_7 -> V_167 = V_326 ;
return 0 ;
}
static int F_143 ( struct V_69 * V_316 )
{
struct V_294 * V_295 = F_21 ( V_316 ) ;
struct V_296 * V_30 = F_23 ( V_316 ) ;
int V_46 = F_22 ( V_30 ) ;
V_295 -> V_157 = 0 ;
V_295 -> V_312 = 0 ;
V_295 -> V_307 = V_295 -> V_317 ;
V_295 -> V_313 = V_295 -> V_319 ;
V_295 -> V_19 = NULL ;
V_295 -> V_74 = 0 ;
F_144 ( V_295 -> V_75 , V_46 ) ;
return 0 ;
}
static int F_145 ( struct V_43 * V_30 )
{
F_146 ( F_147 ( V_30 ) ,
sizeof( struct V_294 ) ) ;
return F_116 ( F_16 ( V_30 ) ) ;
}
static int F_148 ( struct V_69 * V_316 )
{
struct V_294 * V_295 = F_21 ( V_316 ) ;
struct V_296 * V_309 = F_23 ( V_316 ) ;
struct V_2 * V_3 = F_16 ( F_126 ( V_309 ) ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
unsigned int V_46 = F_22 ( V_309 ) ;
unsigned int V_311 = F_130 ( F_126 ( V_309 ) ) ;
F_143 ( V_316 ) ;
V_295 -> V_157 = V_311 ;
if ( F_45 ( F_126 ( V_309 ) ) ) {
if ( V_46 == V_71 )
memcpy ( V_295 -> V_75 , V_9 -> V_322 ,
V_72 ) ;
else if ( V_46 == V_73 )
memcpy ( V_295 -> V_75 , V_9 -> V_322 ,
V_28 ) ;
else
memcpy ( V_295 -> V_75 , V_9 -> V_322 ,
V_46 ) ;
}
return 0 ;
}
static int F_149 ( struct V_43 * V_30 )
{
struct V_2 * V_3 = F_16 ( V_30 ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
unsigned int V_46 =
F_22 ( F_147 ( V_30 ) ) ;
F_146 ( F_147 ( V_30 ) ,
sizeof( struct V_294 ) ) ;
V_9 -> V_101 = F_34 ( V_46 ) ;
if ( F_111 ( V_9 -> V_101 ) )
return F_112 ( V_9 -> V_101 ) ;
return F_116 ( F_16 ( V_30 ) ) ;
}
static void F_150 ( struct V_43 * V_30 )
{
struct V_2 * V_3 = F_16 ( V_30 ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
if ( V_9 -> V_101 ) {
F_123 ( V_9 -> V_101 ) ;
V_9 -> V_101 = NULL ;
}
}
static int F_151 ( struct V_23 * V_24 ,
struct V_1 * V_3 )
{
F_152 ( V_327 , V_3 -> null ) ;
F_153 ( V_327 , V_3 -> null ) ;
F_154 ( V_327 , F_155 ( V_24 ) ,
NULL , NULL ) ;
F_156 ( V_327 , V_24 -> V_38 , V_24 -> V_56 , V_24 -> V_39 ,
NULL ) ;
return F_157 ( V_327 ) ;
}
static int F_158 ( struct V_23 * V_24 , int V_328 ,
int V_329 , int V_330 ,
unsigned short V_200 )
{
unsigned int V_31 = F_11 ( F_10 ( V_24 ) ) ;
if ( ( ( V_24 -> V_40 - ( V_200 ? V_31 : 0 ) ) == 0 ) ||
( V_24 -> V_39 > V_329 ) ||
( V_328 > V_331 ) ||
( V_330 > V_332 ) )
return 1 ;
return 0 ;
}
static int F_159 ( struct V_23 * V_24 , unsigned short V_200 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_160 ( V_30 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_23 * V_333 = F_17 ( V_24 ) ;
F_161 ( V_333 , V_5 -> V_334 ) ;
F_162 ( V_333 , V_24 -> V_207 . V_206 ,
V_24 -> V_207 . V_335 , V_24 -> V_207 . V_37 ) ;
F_163 ( V_333 , V_24 -> V_38 , V_24 -> V_56 , V_24 -> V_40 ,
V_24 -> V_226 ) ;
F_164 ( V_333 , V_24 -> V_39 ) ;
return V_200 ? F_165 ( V_333 ) :
F_166 ( V_333 ) ;
}
static struct V_18 * F_167 ( struct V_23 * V_24 ,
unsigned short V_146 ,
int V_336 ,
unsigned short V_200 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_160 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_337 = F_5 ( V_5 ) ;
struct V_338 * V_53 = F_17 ( V_24 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
struct V_129 * V_130 ;
struct V_133 V_134 ;
struct V_131 * V_38 ;
unsigned int V_154 = 0 , V_203 ;
unsigned int V_205 = F_168 ( V_30 ) , V_339 = 0 ;
unsigned int V_173 = 0 ;
unsigned short V_340 = 0 ;
unsigned int V_39 = V_24 -> V_39 ;
unsigned int V_31 = F_11 ( V_30 ) ;
int V_26 = - V_102 , V_328 ;
int null = 0 ;
T_3 V_206 = V_24 -> V_207 . V_206 & V_208 ? V_209 :
V_210 ;
if ( V_5 -> V_170 == 0 || ( V_24 -> V_40 == 0 ) )
goto V_26;
if ( V_200 && V_24 -> V_40 < F_11 ( V_30 ) )
goto V_26;
V_328 = F_87 ( V_24 -> V_38 , V_24 -> V_39 + V_24 -> V_40 ) ;
if ( V_328 < 0 )
goto V_26;
V_38 = F_169 ( V_53 -> V_341 , V_24 -> V_38 , V_24 -> V_39 ) ;
V_53 -> V_56 = V_38 ;
if ( V_24 -> V_38 != V_24 -> V_56 ) {
V_26 = F_151 ( V_24 , V_5 ) ;
if ( V_26 )
return F_35 ( V_26 ) ;
V_53 -> V_56 = F_169 ( V_53 -> V_342 , V_24 -> V_56 ,
V_24 -> V_39 ) ;
}
if ( F_12 ( V_30 ) == V_343 ) {
null = 1 ;
V_39 = 0 ;
}
V_53 -> V_57 = F_87 ( V_53 -> V_56 , V_24 -> V_40 +
( V_200 ? - V_31 : V_31 ) ) ;
if ( V_53 -> V_57 < 0 ) {
F_41 ( L_13 ) ;
goto V_26;
}
V_339 = F_88 ( V_53 -> V_57 ) ;
V_173 = ( F_170 ( F_171 ( V_5 -> V_222 ) ) << 4 )
- sizeof( V_172 -> V_166 ) ;
V_203 = F_89 ( V_173 , V_339 ) ;
if ( F_158 ( V_24 , V_328 + V_344 ,
V_345 ,
V_203 + ( F_8 ( V_328 + V_344 ) * 8 ) ,
V_200 ) ) {
return F_35 ( F_159 ( V_24 , V_200 ) ) ;
}
V_19 = F_90 ( ( V_203 + sizeof( struct V_212 ) ) , V_206 ) ;
if ( ! V_19 )
goto V_26;
F_91 ( V_19 , sizeof( struct V_212 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_203 ) ;
memset ( V_172 , 0 , V_203 ) ;
V_340 = ( V_200 == V_260 ) ? 0 : V_31 ;
V_172 -> V_214 . V_215 =
F_93 ( V_3 -> V_16 -> V_191 , 2 ,
( V_205 ? ( V_39 + 1 ) : 0 ) ) ;
V_172 -> V_214 . V_216 = F_33 ( V_39 + V_205 + V_24 -> V_40 ) ;
V_172 -> V_214 . V_217 = F_94 (
V_39 ? 1 : 0 , V_39 ,
V_39 + V_205 + 1 ,
( V_340 & 0x1F0 ) >> 4 ) ;
V_172 -> V_214 . V_218 = F_95 (
V_340 & 0xF ,
null ? 0 : V_39 + V_205 + 1 ,
V_340 , V_340 ) ;
V_172 -> V_214 . V_219 = F_96 ( V_200 ,
( V_200 == V_260 ) ? 1 : 0 ,
V_168 ,
V_337 -> V_283 , V_5 -> V_346 ,
V_205 >> 1 ) ;
V_172 -> V_214 . V_220 = F_97 ( 0 , 0 , 1 ,
0 , 1 , V_339 ) ;
V_172 -> V_166 . V_221 = V_5 -> V_222 ;
if ( V_200 == V_260 )
memcpy ( V_172 -> V_166 . V_80 , V_5 -> V_80 ,
V_5 -> V_170 ) ;
else
memcpy ( V_172 -> V_166 . V_80 , V_337 -> V_347 ,
V_5 -> V_170 ) ;
memcpy ( V_172 -> V_166 . V_80 + ( F_25 ( V_5 -> V_170 , 16 ) <<
4 ) , V_337 -> V_348 , V_173 -
( F_25 ( V_5 -> V_170 , 16 ) << 4 ) ) ;
V_130 = (struct V_129 * ) ( ( T_1 * ) ( V_172 + 1 ) + V_173 ) ;
V_134 . V_139 = V_53 -> V_57 ;
V_134 . V_138 = V_24 -> V_40 + ( V_200 ? - V_31 : V_31 ) ;
V_134 . V_146 = V_146 ;
V_134 . V_224 = 0 ;
if ( F_62 ( & V_17 -> V_54 . V_55 -> V_16 , V_130 , V_53 -> V_56 ,
& V_134 ) )
goto V_349;
F_98 ( V_19 , V_203 ) ;
if ( V_39 ) {
F_71 ( V_19 , & V_154 , V_24 -> V_38 , V_39 ) ;
}
F_66 ( V_19 , & V_154 , V_24 -> V_226 , V_205 ) ;
F_71 ( V_19 , & V_154 , V_38 , V_24 -> V_40 ) ;
F_75 ( V_3 , V_172 , V_24 , V_19 , V_173 , V_336 , 1 ,
sizeof( struct V_129 ) + V_339 ) ;
V_53 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
V_349:
F_19 ( V_19 ) ;
V_26:
return F_35 ( - V_102 ) ;
}
static int F_172 ( T_1 * V_350 , unsigned int V_351 , int V_352 )
{
V_122 V_37 ;
memset ( V_350 , 0 , V_352 ) ;
V_350 += V_352 ;
if ( V_352 >= 4 )
V_352 = 4 ;
else if ( V_351 > ( unsigned int ) ( 1 << ( 8 * V_352 ) ) )
return - V_353 ;
V_37 = F_44 ( V_351 ) ;
memcpy ( V_350 - V_352 , ( T_1 * ) & V_37 + 4 - V_352 , V_352 ) ;
return 0 ;
}
static void F_173 ( struct V_23 * V_24 ,
struct V_1 * V_5 ,
unsigned short V_200 )
{
unsigned int V_354 , V_355 , V_356 ;
int V_357 ;
struct V_29 * V_150 = F_10 ( V_24 ) ;
struct V_338 * V_53 = F_17 ( V_24 ) ;
T_1 * V_358 = V_53 -> V_359 ;
V_356 = F_11 ( V_150 ) ;
memcpy ( V_358 , V_53 -> V_226 , 16 ) ;
V_355 = V_358 [ 0 ] ;
V_354 = V_355 + 1 ;
* V_358 |= ( 8 * ( ( V_356 - 2 ) / 2 ) ) ;
if ( V_24 -> V_39 )
* V_358 |= 64 ;
V_357 = F_172 ( V_358 + 16 - V_354 ,
( V_200 == V_223 ) ?
V_24 -> V_40 - V_356 : V_24 -> V_40 , V_354 ) ;
}
static inline int F_174 ( const T_1 * V_226 )
{
if ( V_226 [ 0 ] < 1 || V_226 [ 0 ] > 7 )
return - V_102 ;
return 0 ;
}
static int F_175 ( struct V_23 * V_24 ,
struct V_1 * V_5 ,
unsigned int V_360 ,
unsigned short V_200 )
{
struct V_338 * V_53 = F_17 ( V_24 ) ;
int V_357 = 0 ;
if ( V_360 == V_361 ) {
V_53 -> V_226 [ 0 ] = 3 ;
memcpy ( V_53 -> V_226 + 1 , & V_5 -> V_362 [ 0 ] , 3 ) ;
memcpy ( V_53 -> V_226 + 4 , V_24 -> V_226 , 8 ) ;
memset ( V_53 -> V_226 + 12 , 0 , 4 ) ;
* ( ( unsigned short * ) ( V_53 -> V_359 + 16 ) ) =
F_57 ( V_24 -> V_39 - 8 ) ;
} else {
memcpy ( V_53 -> V_226 , V_24 -> V_226 , 16 ) ;
* ( ( unsigned short * ) ( V_53 -> V_359 + 16 ) ) =
F_57 ( V_24 -> V_39 ) ;
}
F_173 ( V_24 , V_5 , V_200 ) ;
memset ( V_53 -> V_226 + 15 - V_53 -> V_226 [ 0 ] , 0 , V_53 -> V_226 [ 0 ] + 1 ) ;
return V_357 ;
}
static void F_176 ( struct V_199 * V_214 ,
unsigned int V_339 ,
struct V_23 * V_24 ,
unsigned short V_200 ,
struct V_2 * V_363 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_1 * V_5 = F_1 ( F_160 ( V_30 ) ) ;
unsigned int V_205 = V_66 ;
unsigned int V_364 = V_365 ;
unsigned int V_366 = V_367 ;
unsigned int V_368 = V_363 -> V_16 -> V_191 ;
unsigned int V_369 ;
unsigned char V_370 = 0 , V_371 = 0 ;
unsigned int V_39 ;
if ( F_12 ( V_30 ) == V_361 )
V_39 = V_24 -> V_39 - 8 ;
else
V_39 = V_24 -> V_39 ;
V_369 = V_372 +
( ( V_39 ) ? V_373 : 0 ) ;
V_371 = V_24 -> V_40 ?
( V_39 + V_205 + 1 + V_369 ) : 0 ;
if ( V_200 == V_223 ) {
if ( F_11 ( V_30 ) != V_24 -> V_40 )
V_370 = F_11 ( V_30 ) ;
else
V_371 = 0 ;
}
V_214 -> V_215 = F_93 ( V_368 ,
2 , ( V_205 ? ( V_39 + 1 ) : 0 ) +
V_369 ) ;
V_214 -> V_216 =
F_33 ( V_39 + V_205 + V_24 -> V_40 + V_369 ) ;
V_214 -> V_217 = F_94 (
1 , V_39 + V_369 , V_39
+ V_205 + 1 + V_369 , 0 ) ;
V_214 -> V_218 = F_95 ( 0 ,
V_371 , V_370 ,
( V_200 == V_260 ) ? 0 :
F_11 ( V_30 ) ) ;
V_214 -> V_219 = F_96 ( V_200 ,
( V_200 == V_260 ) ? 0 : 1 ,
V_364 , V_366 ,
V_5 -> V_346 , V_205 >> 1 ) ;
V_214 -> V_220 = F_97 ( 0 , 0 , 1 , 0 ,
1 , V_339 ) ;
}
int F_177 ( unsigned short V_200 ,
struct V_23 * V_24 ,
struct V_1 * V_5 ,
unsigned int V_360 )
{
if ( V_360 != V_361 ) {
if ( F_174 ( V_24 -> V_226 ) ) {
F_41 ( L_14 ) ;
return - V_102 ;
}
} else {
if ( V_24 -> V_39 != 16 && V_24 -> V_39 != 20 ) {
F_41 ( L_15 ,
V_24 -> V_39 ) ;
return - V_102 ;
}
}
if ( V_5 -> V_170 == 0 ) {
F_41 ( L_16 ) ;
return - V_102 ;
}
return 0 ;
}
unsigned int F_178 ( struct V_18 * V_19 ,
struct V_23 * V_24 ,
struct V_131 * V_38 ,
unsigned int V_205 ,
struct V_1 * V_5 )
{
unsigned int V_154 = 0 ;
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_338 * V_53 = F_17 ( V_24 ) ;
F_66 ( V_19 , & V_154 , V_53 -> V_359 , V_372 +
( V_24 -> V_39 ? V_373 : 0 ) ) ;
if ( V_24 -> V_39 ) {
if ( F_12 ( V_30 ) == V_361 )
F_71 ( V_19 , & V_154 , V_24 -> V_38 ,
V_24 -> V_39 - 8 ) ;
else
F_71 ( V_19 , & V_154 , V_24 -> V_38 , V_24 -> V_39 ) ;
}
F_66 ( V_19 , & V_154 , V_53 -> V_226 , V_205 ) ;
if ( V_24 -> V_40 )
F_71 ( V_19 , & V_154 , V_38 , V_24 -> V_40 ) ;
return V_154 ;
}
static struct V_18 * F_179 ( struct V_23 * V_24 ,
unsigned short V_146 ,
int V_336 ,
unsigned short V_200 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_160 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_338 * V_53 = F_17 ( V_24 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
struct V_129 * V_130 ;
struct V_133 V_134 ;
struct V_131 * V_38 ;
unsigned int V_154 = 0 , V_203 , V_205 = V_66 ;
unsigned int V_339 = 0 , V_173 ;
unsigned int V_360 ;
unsigned int V_31 = F_11 ( V_30 ) ;
int V_26 = - V_102 , V_328 ;
T_3 V_206 = V_24 -> V_207 . V_206 & V_208 ? V_209 :
V_210 ;
if ( V_200 && V_24 -> V_40 < F_11 ( V_30 ) )
goto V_26;
V_328 = F_87 ( V_24 -> V_38 , V_24 -> V_39 + V_24 -> V_40 ) ;
if ( V_328 < 0 )
goto V_26;
V_360 = F_12 ( V_30 ) ;
V_38 = F_169 ( V_53 -> V_341 , V_24 -> V_38 , V_24 -> V_39 ) ;
V_53 -> V_56 = V_38 ;
if ( V_24 -> V_38 != V_24 -> V_56 ) {
V_26 = F_151 ( V_24 , V_5 ) ;
if ( V_26 ) {
F_41 ( L_17 ) ;
return F_35 ( V_26 ) ;
}
V_53 -> V_56 = F_169 ( V_53 -> V_342 , V_24 -> V_56 ,
V_24 -> V_39 ) ;
}
V_53 -> V_57 = F_87 ( V_53 -> V_56 , V_24 -> V_40 +
( V_200 ? - V_31 : V_31 ) ) ;
if ( V_53 -> V_57 < 0 ) {
F_41 ( L_18 ) ;
goto V_26;
}
if ( F_177 ( V_200 , V_24 , V_5 , V_360 ) )
goto V_26;
V_339 = F_88 ( V_53 -> V_57 ) ;
V_173 = ( ( F_25 ( V_5 -> V_170 , 16 ) ) << 4 ) * 2 ;
V_203 = F_89 ( V_173 , V_339 ) ;
if ( F_158 ( V_24 , V_328 + V_374 ,
V_345 - 18 ,
V_203 + ( F_8 ( V_328 + V_374 ) * 8 ) ,
V_200 ) ) {
return F_35 ( F_159 ( V_24 , V_200 ) ) ;
}
V_19 = F_90 ( ( V_203 + sizeof( struct V_212 ) ) , V_206 ) ;
if ( ! V_19 )
goto V_26;
F_91 ( V_19 , sizeof( struct V_212 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_203 ) ;
memset ( V_172 , 0 , V_203 ) ;
F_176 ( & V_172 -> V_214 , V_339 , V_24 , V_200 , V_3 ) ;
V_172 -> V_166 . V_221 = V_5 -> V_222 ;
memcpy ( V_172 -> V_166 . V_80 , V_5 -> V_80 , V_5 -> V_170 ) ;
memcpy ( V_172 -> V_166 . V_80 + ( F_25 ( V_5 -> V_170 , 16 ) *
16 ) , V_5 -> V_80 , V_5 -> V_170 ) ;
V_130 = (struct V_129 * ) ( ( T_1 * ) ( V_172 + 1 ) + V_173 ) ;
if ( F_175 ( V_24 , V_5 , V_360 , V_200 ) )
goto V_349;
V_134 . V_139 = V_53 -> V_57 ;
V_134 . V_138 = V_24 -> V_40 + ( V_200 ? - V_31 : V_31 ) ;
V_134 . V_146 = V_146 ;
V_134 . V_224 = 0 ;
if ( F_62 ( & V_17 -> V_54 . V_55 -> V_16 , V_130 , V_53 -> V_56 ,
& V_134 ) )
goto V_349;
F_98 ( V_19 , V_203 ) ;
V_154 = F_178 ( V_19 , V_24 , V_38 , V_205 , V_5 ) ;
F_75 ( V_3 , V_172 , V_24 , V_19 , V_173 , 0 , 1 ,
sizeof( struct V_129 ) + V_339 ) ;
V_53 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
V_349:
F_19 ( V_19 ) ;
V_19 = NULL ;
V_26:
return F_35 ( - V_102 ) ;
}
static struct V_18 * F_180 ( struct V_23 * V_24 ,
unsigned short V_146 ,
int V_336 ,
unsigned short V_200 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_160 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_338 * V_53 = F_17 ( V_24 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
struct V_129 * V_130 ;
struct V_133 V_134 ;
struct V_131 * V_38 ;
unsigned int V_154 = 0 , V_203 ;
unsigned int V_205 = V_66 ;
unsigned int V_339 = 0 , V_173 ;
unsigned char V_370 = 0 ;
unsigned int V_375 = 0 ;
unsigned int V_31 = F_11 ( V_30 ) ;
int V_26 = - V_102 , V_328 ;
T_3 V_206 = V_24 -> V_207 . V_206 & V_208 ? V_209 :
V_210 ;
if ( V_5 -> V_170 == 0 )
goto V_26;
if ( V_200 && V_24 -> V_40 < F_11 ( V_30 ) )
goto V_26;
V_328 = F_87 ( V_24 -> V_38 , V_24 -> V_39 + V_24 -> V_40 ) ;
if ( V_328 < 0 )
goto V_26;
V_38 = F_169 ( V_53 -> V_341 , V_24 -> V_38 , V_24 -> V_39 ) ;
V_53 -> V_56 = V_38 ;
if ( V_24 -> V_38 != V_24 -> V_56 ) {
V_26 = F_151 ( V_24 , V_5 ) ;
if ( V_26 )
return F_35 ( V_26 ) ;
V_53 -> V_56 = F_169 ( V_53 -> V_342 , V_24 -> V_56 ,
V_24 -> V_39 ) ;
}
if ( ! V_24 -> V_40 )
V_375 = V_66 ;
else
V_375 = V_24 -> V_40 ;
V_53 -> V_57 = F_87 ( V_53 -> V_56 , V_24 -> V_40 +
( V_200 ? - V_31 : V_31 ) ) ;
if ( V_53 -> V_57 < 0 ) {
F_41 ( L_19 ) ;
goto V_26;
}
V_339 = F_88 ( V_53 -> V_57 ) ;
V_173 = ( ( F_25 ( V_5 -> V_170 , 16 ) ) << 4 ) +
V_376 ;
V_203 = F_89 ( V_173 , V_339 ) ;
if ( F_158 ( V_24 , V_328 + V_377 ,
V_345 ,
V_203 + ( F_8 ( V_328 + V_377 ) * 8 ) ,
V_200 ) ) {
return F_35 ( F_159 ( V_24 , V_200 ) ) ;
}
V_19 = F_90 ( ( V_203 + sizeof( struct V_212 ) ) , V_206 ) ;
if ( ! V_19 )
goto V_26;
F_91 ( V_19 , sizeof( struct V_212 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_203 ) ;
memset ( V_172 , 0 , V_203 ) ;
if ( F_12 ( V_30 ) == V_35 )
V_24 -> V_39 -= 8 ;
V_370 = ( V_200 == V_260 ) ? 0 : V_31 ;
V_172 -> V_214 . V_215 = F_93 (
V_3 -> V_16 -> V_191 , 2 , ( V_205 ?
( V_24 -> V_39 + 1 ) : 0 ) ) ;
V_172 -> V_214 . V_216 =
F_33 ( V_24 -> V_39 + V_205 + V_24 -> V_40 ) ;
V_172 -> V_214 . V_217 = F_94 (
V_24 -> V_39 ? 1 : 0 , V_24 -> V_39 ,
V_24 -> V_39 + V_205 + 1 , 0 ) ;
V_172 -> V_214 . V_218 =
F_95 ( 0 , V_24 -> V_39 + V_205 + 1 ,
V_370 , V_370 ) ;
V_172 -> V_214 . V_219 =
F_96 ( V_200 , ( V_200 ==
V_260 ) ? 1 : 0 ,
V_378 ,
V_379 ,
V_5 -> V_346 , V_205 >> 1 ) ;
V_172 -> V_214 . V_220 = F_97 ( 0 , 0 , 1 ,
0 , 1 , V_339 ) ;
V_172 -> V_166 . V_221 = V_5 -> V_222 ;
memcpy ( V_172 -> V_166 . V_80 , V_5 -> V_80 , V_5 -> V_170 ) ;
memcpy ( V_172 -> V_166 . V_80 + ( F_25 ( V_5 -> V_170 , 16 ) *
16 ) , F_4 ( V_5 ) -> V_380 , V_376 ) ;
if ( F_12 ( V_30 ) ==
V_35 ) {
memcpy ( V_53 -> V_226 , V_5 -> V_362 , 4 ) ;
memcpy ( V_53 -> V_226 + 4 , V_24 -> V_226 , 8 ) ;
} else {
memcpy ( V_53 -> V_226 , V_24 -> V_226 , 12 ) ;
}
* ( ( unsigned int * ) ( V_53 -> V_226 + 12 ) ) = F_33 ( 0x01 ) ;
V_130 = (struct V_129 * ) ( ( T_1 * ) ( V_172 + 1 ) + V_173 ) ;
V_134 . V_139 = V_53 -> V_57 ;
V_134 . V_138 = V_24 -> V_40 + ( V_200 ? - V_31 : V_31 ) ;
V_134 . V_146 = V_146 ;
V_134 . V_224 = 0 ;
if ( F_62 ( & V_17 -> V_54 . V_55 -> V_16 , V_130 , V_53 -> V_56 ,
& V_134 ) )
goto V_349;
F_98 ( V_19 , V_203 ) ;
F_71 ( V_19 , & V_154 , V_24 -> V_38 , V_24 -> V_39 ) ;
F_66 ( V_19 , & V_154 , V_53 -> V_226 , V_205 ) ;
F_71 ( V_19 , & V_154 , V_38 , V_24 -> V_40 ) ;
F_75 ( V_3 , V_172 , V_24 , V_19 , V_173 , V_336 , 1 ,
sizeof( struct V_129 ) + V_339 ) ;
V_53 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
V_349:
F_19 ( V_19 ) ;
V_19 = NULL ;
V_26:
return V_19 ;
}
static int F_181 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_160 ( V_30 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_151 * V_124 = F_64 ( V_30 ) ;
V_5 -> V_334 = F_182 ( V_124 -> V_207 . V_381 , 0 ,
V_382 ) ;
if ( F_111 ( V_5 -> V_334 ) )
return F_112 ( V_5 -> V_334 ) ;
F_183 ( V_30 , F_184 ( sizeof( struct V_338 ) ,
sizeof( struct V_23 ) +
F_185 ( V_5 -> V_334 ) ) ) ;
V_5 -> null = F_186 () ;
if ( F_111 ( V_5 -> null ) )
return F_112 ( V_5 -> null ) ;
return F_116 ( V_3 ) ;
}
static void F_187 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_160 ( V_30 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_188 () ;
F_189 ( V_5 -> V_334 ) ;
}
static int F_190 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_160 ( V_30 ) ) ;
V_5 -> V_346 = V_383 ;
V_5 -> V_384 = V_61 ;
return F_191 ( V_5 -> V_334 , V_31 ) ;
}
static int F_192 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_160 ( V_30 ) ) ;
T_2 V_385 = F_193 ( V_30 ) ;
if ( V_31 == V_386 ) {
V_5 -> V_346 = V_387 ;
V_5 -> V_384 = V_61 ;
} else if ( V_31 == V_388 ) {
V_5 -> V_346 = V_389 ;
V_5 -> V_384 = V_61 ;
} else if ( V_31 == V_390 ) {
V_5 -> V_346 = V_391 ;
V_5 -> V_384 = V_61 ;
} else if ( V_31 == V_392 ) {
V_5 -> V_346 = V_393 ;
V_5 -> V_384 = V_61 ;
} else if ( V_31 == V_394 ) {
V_5 -> V_346 = V_395 ;
V_5 -> V_384 = V_61 ;
} else if ( V_31 == ( V_385 >> 1 ) ) {
V_5 -> V_346 = V_396 ;
V_5 -> V_384 = V_61 ;
} else if ( V_31 == V_385 ) {
V_5 -> V_346 = V_397 ;
V_5 -> V_384 = V_61 ;
} else {
V_5 -> V_346 = V_397 ;
V_5 -> V_384 = V_60 ;
}
return F_191 ( V_5 -> V_334 , V_31 ) ;
}
static int F_194 ( struct V_29 * V_30 , unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_160 ( V_30 ) ) ;
switch ( V_31 ) {
case V_386 :
V_5 -> V_346 = V_387 ;
V_5 -> V_384 = V_61 ;
break;
case V_398 :
V_5 -> V_346 = V_396 ;
V_5 -> V_384 = V_61 ;
break;
case V_392 :
V_5 -> V_346 = V_393 ;
V_5 -> V_384 = V_61 ;
break;
case V_394 :
V_5 -> V_346 = V_395 ;
V_5 -> V_384 = V_61 ;
break;
case V_399 :
V_5 -> V_346 = V_397 ;
V_5 -> V_384 = V_61 ;
break;
case V_400 :
case V_401 :
V_5 -> V_346 = V_397 ;
V_5 -> V_384 = V_60 ;
break;
default:
F_142 ( (struct V_43 * ) V_30 ,
V_240 ) ;
return - V_102 ;
}
return F_191 ( V_5 -> V_334 , V_31 ) ;
}
static int F_195 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_160 ( V_30 ) ) ;
switch ( V_31 ) {
case V_398 :
V_5 -> V_346 = V_396 ;
V_5 -> V_384 = V_61 ;
break;
case V_392 :
V_5 -> V_346 = V_393 ;
V_5 -> V_384 = V_61 ;
break;
case V_399 :
V_5 -> V_346 = V_397 ;
V_5 -> V_384 = V_61 ;
break;
default:
F_142 ( (struct V_43 * ) V_30 ,
V_240 ) ;
return - V_102 ;
}
return F_191 ( V_5 -> V_334 , V_31 ) ;
}
static int F_196 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_160 ( V_30 ) ) ;
switch ( V_31 ) {
case V_386 :
V_5 -> V_346 = V_387 ;
V_5 -> V_384 = V_61 ;
break;
case V_388 :
V_5 -> V_346 = V_389 ;
V_5 -> V_384 = V_61 ;
break;
case V_398 :
V_5 -> V_346 = V_396 ;
V_5 -> V_384 = V_61 ;
break;
case V_390 :
V_5 -> V_346 = V_391 ;
V_5 -> V_384 = V_61 ;
break;
case V_392 :
V_5 -> V_346 = V_393 ;
V_5 -> V_384 = V_61 ;
break;
case V_394 :
V_5 -> V_346 = V_395 ;
V_5 -> V_384 = V_61 ;
break;
case V_399 :
V_5 -> V_346 = V_397 ;
V_5 -> V_384 = V_61 ;
break;
default:
F_142 ( (struct V_43 * ) V_30 ,
V_240 ) ;
return - V_102 ;
}
return F_191 ( V_5 -> V_334 , V_31 ) ;
}
static int F_197 ( struct V_29 * V_150 ,
const T_1 * V_80 ,
unsigned int V_227 )
{
struct V_2 * V_3 = F_160 ( V_150 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned char V_228 , V_281 ;
int V_402 = 0 ;
V_402 = sizeof( struct V_165 ) +
( ( F_25 ( V_227 , 16 ) ) << 4 ) * 2 ;
if ( V_227 == V_231 ) {
V_281 = V_232 ;
V_228 = V_232 ;
} else if ( V_227 == V_233 ) {
V_228 = V_234 ;
V_281 = V_403 ;
} else if ( V_227 == V_235 ) {
V_228 = V_236 ;
V_281 = V_286 ;
} else {
F_142 ( (struct V_43 * ) V_150 ,
V_240 ) ;
V_5 -> V_170 = 0 ;
return - V_102 ;
}
V_5 -> V_222 = F_101 ( V_228 , V_281 , 0 , 0 ,
V_402 >> 4 ) ;
memcpy ( V_5 -> V_80 , V_80 , V_227 ) ;
V_5 -> V_170 = V_227 ;
return 0 ;
}
static int F_198 ( struct V_29 * V_150 ,
const T_1 * V_80 ,
unsigned int V_227 )
{
struct V_2 * V_3 = F_160 ( V_150 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int error ;
F_199 ( V_5 -> V_334 , V_404 ) ;
F_200 ( V_5 -> V_334 , F_201 ( V_150 ) &
V_404 ) ;
error = F_202 ( V_5 -> V_334 , V_80 , V_227 ) ;
F_199 ( V_150 , V_405 ) ;
F_200 ( V_150 , F_201 ( V_5 -> V_334 ) &
V_405 ) ;
if ( error )
return error ;
return F_197 ( V_150 , V_80 , V_227 ) ;
}
static int F_203 ( struct V_29 * V_150 , const T_1 * V_80 ,
unsigned int V_227 )
{
struct V_2 * V_3 = F_160 ( V_150 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_227 < 3 ) {
F_142 ( (struct V_43 * ) V_150 ,
V_240 ) ;
V_5 -> V_170 = 0 ;
return - V_102 ;
}
V_227 -= 3 ;
memcpy ( V_5 -> V_362 , V_80 + V_227 , 3 ) ;
return F_197 ( V_150 , V_80 , V_227 ) ;
}
static int F_204 ( struct V_29 * V_150 , const T_1 * V_80 ,
unsigned int V_227 )
{
struct V_2 * V_3 = F_160 ( V_150 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_10 * V_11 = F_4 ( V_5 ) ;
struct V_406 * V_407 ;
unsigned int V_228 ;
int V_252 = 0 , V_402 = 0 ;
V_5 -> V_170 = 0 ;
F_199 ( V_5 -> V_334 , V_404 ) ;
F_200 ( V_5 -> V_334 , F_201 ( V_150 )
& V_404 ) ;
V_252 = F_202 ( V_5 -> V_334 , V_80 , V_227 ) ;
F_199 ( V_150 , V_405 ) ;
F_200 ( V_150 , F_201 ( V_5 -> V_334 ) &
V_405 ) ;
if ( V_252 )
goto V_270;
if ( F_12 ( V_150 ) == V_35 &&
V_227 > 3 ) {
V_227 -= 4 ;
memcpy ( V_5 -> V_362 , V_80 + V_227 , 4 ) ;
}
if ( V_227 == V_231 ) {
V_228 = V_232 ;
} else if ( V_227 == V_233 ) {
V_228 = V_234 ;
} else if ( V_227 == V_235 ) {
V_228 = V_236 ;
} else {
F_142 ( (struct V_43 * ) V_150 ,
V_240 ) ;
F_41 ( L_20 , V_227 ) ;
V_252 = - V_102 ;
goto V_270;
}
memcpy ( V_5 -> V_80 , V_80 , V_227 ) ;
V_5 -> V_170 = V_227 ;
V_402 = sizeof( struct V_165 ) +
( ( F_25 ( V_227 , 16 ) ) << 4 ) +
V_376 ;
V_5 -> V_222 = F_101 ( V_228 ,
V_408 ,
0 , 0 ,
V_402 >> 4 ) ;
V_407 = F_205 ( L_21 , 0 , 0 ) ;
if ( F_111 ( V_407 ) ) {
V_5 -> V_170 = 0 ;
V_252 = - V_213 ;
goto V_270;
}
V_252 = F_206 ( V_407 , V_80 , V_227 ) ;
if ( V_252 ) {
V_5 -> V_170 = 0 ;
goto V_409;
}
memset ( V_11 -> V_380 , 0 , V_376 ) ;
F_207 ( V_407 , V_11 -> V_380 , V_11 -> V_380 ) ;
V_409:
F_208 ( V_407 ) ;
V_270:
return V_252 ;
}
static int F_209 ( struct V_29 * V_14 , const T_1 * V_80 ,
unsigned int V_227 )
{
struct V_2 * V_3 = F_160 ( V_14 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_337 = F_5 ( V_5 ) ;
struct V_410 V_411 ;
unsigned int V_311 ;
unsigned int V_412 = F_64 ( V_14 ) -> V_413 ;
int V_26 = 0 , V_84 , V_414 = 0 ;
unsigned char V_228 = 0 ;
unsigned char V_415 [ V_320 ] = { 0 } ;
struct V_99 * V_101 = F_35 ( - V_102 ) ;
struct V_278 V_293 ;
int V_224 ;
T_1 * V_416 = NULL ;
F_199 ( V_5 -> V_334 , V_404 ) ;
F_200 ( V_5 -> V_334 , F_201 ( V_14 )
& V_404 ) ;
V_26 = F_202 ( V_5 -> V_334 , V_80 , V_227 ) ;
F_199 ( V_14 , V_405 ) ;
F_200 ( V_14 , F_201 ( V_5 -> V_334 )
& V_405 ) ;
if ( V_26 )
goto V_270;
if ( F_210 ( & V_411 , V_80 , V_227 ) != 0 ) {
F_200 ( V_14 , V_240 ) ;
goto V_270;
}
if ( F_122 ( & V_293 , V_412 ) ) {
F_41 ( L_22 ) ;
goto V_270;
}
if ( V_411 . V_417 == V_231 ) {
V_228 = V_232 ;
} else if ( V_411 . V_417 == V_233 ) {
V_228 = V_234 ;
} else if ( V_411 . V_417 == V_235 ) {
V_228 = V_236 ;
} else {
F_41 ( L_23 ) ;
goto V_270;
}
memcpy ( V_5 -> V_80 , V_411 . V_418 , V_411 . V_417 ) ;
V_5 -> V_170 = V_411 . V_417 ;
F_30 ( V_337 -> V_347 , V_5 -> V_80 ,
V_5 -> V_170 << 3 ) ;
V_101 = F_34 ( V_412 ) ;
if ( F_111 ( V_101 ) ) {
F_41 ( L_24 ) ;
V_5 -> V_170 = 0 ;
return - V_102 ;
}
{
F_138 ( V_321 , V_101 ) ;
V_321 -> V_30 = V_101 ;
V_321 -> V_206 = F_139 ( V_101 ) ;
V_311 = F_211 ( V_101 ) ;
V_224 = F_127 ( V_412 ) ;
V_416 = V_337 -> V_348 + V_293 . V_285 + V_224 ;
if ( V_411 . V_419 > V_311 ) {
V_26 = F_140 ( V_321 , V_411 . V_420 ,
V_411 . V_419 ,
V_416 ) ;
if ( V_26 ) {
F_41 ( L_24 ) ;
goto V_270;
}
V_411 . V_419 = V_412 ;
} else
memcpy ( V_416 , V_411 . V_420 , V_411 . V_419 ) ;
memset ( V_415 + V_411 . V_419 , 0 , V_311 - V_411 . V_419 ) ;
memcpy ( V_415 , V_416 , V_411 . V_419 ) ;
for ( V_84 = 0 ; V_84 < V_311 > > 2 ; V_84 ++ )
* ( ( unsigned int * ) V_415 + V_84 ) ^= V_323 ;
if ( F_37 ( V_321 , V_415 , V_337 -> V_348 ,
V_412 ) )
goto V_270;
memset ( V_415 + V_411 . V_419 , 0 , V_311 - V_411 . V_419 ) ;
memcpy ( V_415 , V_416 , V_411 . V_419 ) ;
for ( V_84 = 0 ; V_84 < V_311 > > 2 ; V_84 ++ )
* ( ( unsigned int * ) V_415 + V_84 ) ^= V_324 ;
if ( F_37 ( V_321 , V_415 , V_416 , V_412 ) )
goto V_270;
F_42 ( V_337 -> V_348 , V_293 . V_285 ) ;
F_42 ( V_416 , V_293 . V_285 ) ;
V_414 = sizeof( struct V_165 ) +
( ( F_25 ( V_411 . V_417 , 16 ) ) << 4 ) +
( V_293 . V_285 + V_224 ) * 2 ;
V_5 -> V_222 = F_101 ( V_228 , V_293 . V_281 ,
0 , 1 , V_414 >> 4 ) ;
V_337 -> V_283 = V_293 . V_283 ;
F_123 ( V_101 ) ;
return 0 ;
}
V_270:
V_5 -> V_170 = 0 ;
if ( ! F_111 ( V_101 ) )
F_123 ( V_101 ) ;
return - V_102 ;
}
static int F_212 ( struct V_29 * V_14 ,
const T_1 * V_80 , unsigned int V_227 )
{
struct V_2 * V_3 = F_160 ( V_14 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_337 = F_5 ( V_5 ) ;
struct V_410 V_411 ;
int V_26 ;
int V_414 = 0 ;
unsigned char V_228 = 0 ;
F_199 ( V_5 -> V_334 , V_404 ) ;
F_200 ( V_5 -> V_334 , F_201 ( V_14 )
& V_404 ) ;
V_26 = F_202 ( V_5 -> V_334 , V_80 , V_227 ) ;
F_199 ( V_14 , V_405 ) ;
F_200 ( V_14 , F_201 ( V_5 -> V_334 )
& V_405 ) ;
if ( V_26 )
goto V_270;
if ( F_210 ( & V_411 , V_80 , V_227 ) != 0 ) {
F_200 ( V_14 , V_240 ) ;
goto V_270;
}
if ( V_411 . V_417 == V_231 ) {
V_228 = V_232 ;
} else if ( V_411 . V_417 == V_233 ) {
V_228 = V_234 ;
} else if ( V_411 . V_417 == V_235 ) {
V_228 = V_236 ;
} else {
F_41 ( L_23 ) ;
goto V_270;
}
memcpy ( V_5 -> V_80 , V_411 . V_418 , V_411 . V_417 ) ;
V_5 -> V_170 = V_411 . V_417 ;
F_30 ( V_337 -> V_347 , V_5 -> V_80 ,
V_5 -> V_170 << 3 ) ;
V_414 = sizeof( struct V_165 )
+ ( ( F_25 ( V_411 . V_417 , 16 ) ) << 4 ) ;
V_5 -> V_222 = F_101 ( V_228 , V_239 , 0 ,
0 , V_414 >> 4 ) ;
V_337 -> V_283 = V_421 ;
return 0 ;
V_270:
V_5 -> V_170 = 0 ;
return - V_102 ;
}
static int F_213 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_338 * V_53 = F_17 ( V_24 ) ;
V_53 -> V_59 = V_61 ;
switch ( F_12 ( V_30 ) ) {
case V_422 :
case V_343 :
return F_214 ( V_24 , V_260 , 0 ,
F_167 ) ;
case V_423 :
case V_361 :
return F_214 ( V_24 , V_260 , 0 ,
F_179 ) ;
default:
return F_214 ( V_24 , V_260 , 0 ,
F_180 ) ;
}
}
static int F_215 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_1 * V_5 = F_1 ( F_160 ( V_30 ) ) ;
struct V_338 * V_53 = F_17 ( V_24 ) ;
int V_336 ;
if ( V_5 -> V_384 == V_60 ) {
V_336 = F_193 ( V_30 ) ;
V_53 -> V_59 = V_60 ;
} else {
V_336 = 0 ;
V_53 -> V_59 = V_61 ;
}
switch ( F_12 ( V_30 ) ) {
case V_422 :
case V_343 :
return F_214 ( V_24 , V_223 , V_336 ,
F_167 ) ;
case V_423 :
case V_361 :
return F_214 ( V_24 , V_223 , V_336 ,
F_179 ) ;
default:
return F_214 ( V_24 , V_223 , V_336 ,
F_180 ) ;
}
}
static int F_214 ( struct V_23 * V_24 ,
unsigned short V_200 ,
int V_336 ,
T_5 V_424 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_160 ( V_30 ) ;
struct V_15 * V_17 ;
struct V_18 * V_19 ;
if ( ! V_3 -> V_16 ) {
F_41 ( L_25 , V_261 ) ;
return - V_425 ;
}
V_17 = F_6 ( V_3 ) ;
if ( F_103 ( V_17 -> V_54 . V_257 [ 0 ] ,
V_3 -> V_193 ) ) {
if ( ! ( V_24 -> V_207 . V_206 & V_258 ) )
return - V_259 ;
}
V_19 = V_424 ( V_24 , V_17 -> V_54 . V_179 [ V_3 -> V_180 ] , V_336 ,
V_200 ) ;
if ( F_111 ( V_19 ) || ! V_19 )
return F_112 ( V_19 ) ;
V_19 -> V_16 = V_17 -> V_54 . V_257 [ 0 ] ;
F_113 ( V_19 , V_262 , V_3 -> V_193 ) ;
F_114 ( V_19 ) ;
return - V_263 ;
}
static int F_216 ( void )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < F_217 ( V_426 ) ; V_84 ++ ) {
switch ( V_426 [ V_84 ] . type & V_50 ) {
case V_62 :
if ( V_426 [ V_84 ] . V_427 )
F_218 (
& V_426 [ V_84 ] . V_124 . V_153 ) ;
break;
case V_51 :
if ( V_426 [ V_84 ] . V_427 )
F_219 (
& V_426 [ V_84 ] . V_124 . V_150 ) ;
break;
case V_67 :
if ( V_426 [ V_84 ] . V_427 )
F_220 (
& V_426 [ V_84 ] . V_124 . V_127 ) ;
break;
}
V_426 [ V_84 ] . V_427 = 0 ;
}
return 0 ;
}
static int F_221 ( void )
{
struct V_123 V_428 ;
struct V_429 * V_430 ;
int V_26 = 0 , V_84 ;
char * V_431 = NULL ;
for ( V_84 = 0 ; V_84 < F_217 ( V_426 ) ; V_84 ++ ) {
if ( V_426 [ V_84 ] . V_427 )
continue;
switch ( V_426 [ V_84 ] . type & V_50 ) {
case V_62 :
V_26 = F_222 ( & V_426 [ V_84 ] . V_124 . V_153 ) ;
V_431 = V_426 [ V_84 ] . V_124 . V_153 . V_432 ;
break;
case V_51 :
V_426 [ V_84 ] . V_124 . V_150 . V_207 . V_49 =
V_51 | V_433 |
V_382 ;
V_426 [ V_84 ] . V_124 . V_150 . V_434 = F_213 ;
V_426 [ V_84 ] . V_124 . V_150 . V_435 = F_215 ;
V_426 [ V_84 ] . V_124 . V_150 . V_315 = F_181 ;
V_426 [ V_84 ] . V_124 . V_150 . exit = F_187 ;
V_426 [ V_84 ] . V_124 . V_150 . V_207 . V_436 = V_437 ;
V_26 = F_223 ( & V_426 [ V_84 ] . V_124 . V_150 ) ;
V_431 = V_426 [ V_84 ] . V_124 . V_150 . V_207 . V_432 ;
break;
case V_67 :
V_430 = & V_426 [ V_84 ] . V_124 . V_127 ;
V_430 -> V_438 = F_129 ;
V_430 -> V_439 = F_132 ;
V_430 -> V_440 = F_133 ;
V_430 -> V_441 = F_134 ;
V_430 -> V_442 = F_135 ;
V_430 -> V_443 = F_136 ;
V_430 -> V_444 . V_445 = V_446 ;
V_430 -> V_444 . V_207 . V_447 = V_448 ;
V_430 -> V_444 . V_207 . V_436 = V_437 ;
V_430 -> V_444 . V_207 . V_49 = V_449 ;
V_430 -> V_444 . V_207 . V_450 = 0 ;
V_430 -> V_444 . V_207 . V_451 = NULL ;
V_430 -> V_444 . V_207 . V_452 = & V_453 ;
if ( V_426 [ V_84 ] . type == V_128 ) {
V_430 -> V_444 . V_207 . V_454 = F_149 ;
V_430 -> V_444 . V_207 . V_451 = F_150 ;
V_430 -> V_315 = F_148 ;
V_430 -> V_455 = F_137 ;
V_430 -> V_444 . V_207 . V_456 = V_457 ;
} else {
V_430 -> V_315 = F_143 ;
V_430 -> V_444 . V_207 . V_456 = V_458 ;
V_430 -> V_444 . V_207 . V_454 = F_145 ;
}
V_26 = F_224 ( & V_426 [ V_84 ] . V_124 . V_127 ) ;
V_428 = V_426 [ V_84 ] . V_124 . V_127 . V_444 . V_207 ;
V_431 = V_428 . V_432 ;
break;
}
if ( V_26 ) {
F_41 ( L_26 ,
V_431 ) ;
goto V_459;
} else {
V_426 [ V_84 ] . V_427 = 1 ;
}
}
return 0 ;
V_459:
F_216 () ;
return V_26 ;
}
int F_225 ( void )
{
return F_221 () ;
}
int F_226 ( void )
{
F_216 () ;
return 0 ;
}
