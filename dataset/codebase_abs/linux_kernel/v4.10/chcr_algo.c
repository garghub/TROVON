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
struct V_99 * V_101 = NULL ;
switch ( V_100 ) {
case V_102 :
V_101 = F_35 ( L_1 , 0 , 0 ) ;
break;
case V_71 :
V_101 = F_35 ( L_2 , 0 , 0 ) ;
break;
case V_72 :
V_101 = F_35 ( L_3 , 0 , 0 ) ;
break;
case V_73 :
V_101 = F_35 ( L_4 , 0 , 0 ) ;
break;
case V_28 :
V_101 = F_35 ( L_5 , 0 , 0 ) ;
break;
}
return V_101 ;
}
static int F_36 ( struct V_103 * V_104 ,
char * V_105 , char * V_106 ,
int V_107 )
{
struct V_108 V_109 ;
struct V_110 V_111 ;
struct V_112 V_113 ;
int error ;
if ( V_107 == V_102 ) {
error = F_37 ( V_104 ) ? :
F_38 ( V_104 , V_105 , V_114 ) ? :
F_39 ( V_104 , ( void * ) & V_109 ) ;
memcpy ( V_106 , V_109 . V_115 , V_102 ) ;
} else if ( V_107 == V_71 ) {
error = F_37 ( V_104 ) ? :
F_38 ( V_104 , V_105 , V_116 ) ? :
F_39 ( V_104 , ( void * ) & V_111 ) ;
memcpy ( V_106 , V_111 . V_115 , V_72 ) ;
} else if ( V_107 == V_72 ) {
error = F_37 ( V_104 ) ? :
F_38 ( V_104 , V_105 , V_116 ) ? :
F_39 ( V_104 , ( void * ) & V_111 ) ;
memcpy ( V_106 , V_111 . V_115 , V_72 ) ;
} else if ( V_107 == V_73 ) {
error = F_37 ( V_104 ) ? :
F_38 ( V_104 , V_105 , V_117 ) ? :
F_39 ( V_104 , ( void * ) & V_113 ) ;
memcpy ( V_106 , V_113 . V_115 , V_28 ) ;
} else if ( V_107 == V_28 ) {
error = F_37 ( V_104 ) ? :
F_38 ( V_104 , V_105 , V_117 ) ? :
F_39 ( V_104 , ( void * ) & V_113 ) ;
memcpy ( V_106 , V_113 . V_115 , V_28 ) ;
} else {
error = - V_118 ;
F_40 ( L_6 , V_107 ) ;
}
return error ;
}
static void F_41 ( char * V_119 , int V_100 )
{
int V_84 ;
if ( V_100 == V_28 ) {
for ( V_84 = 0 ; V_84 < ( V_100 / sizeof( V_120 ) ) ; V_84 ++ )
* ( ( V_121 * ) V_119 + V_84 ) =
F_42 ( * ( ( V_120 * ) V_119 + V_84 ) ) ;
} else {
for ( V_84 = 0 ; V_84 < ( V_100 / sizeof( T_2 ) ) ; V_84 ++ )
* ( ( V_122 * ) V_119 + V_84 ) =
F_43 ( * ( ( T_2 * ) V_119 + V_84 ) ) ;
}
}
static inline int F_44 ( struct V_43 * V_30 )
{
struct V_123 * V_124 = V_30 -> V_48 ;
struct V_125 * V_126 =
F_45 ( F_46 ( V_124 ) , struct V_125 ,
V_124 . V_127 ) ;
if ( V_126 -> type == V_128 )
return 1 ;
return 0 ;
}
static void F_47 ( struct V_129 * V_130 ,
struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_135 * V_136 ;
int V_137 = V_134 -> V_138 ;
unsigned int V_139 = V_134 -> V_139 , V_84 , V_85 = 0 ;
V_130 -> V_140 = F_33 ( F_48 ( V_141 )
| F_49 ( 0 ) ) ;
V_130 -> V_142 =
F_33 ( F_50 ( 0 ) |
F_51 ( 0 ) |
F_52 ( 0 ) |
F_53 ( 0 ) |
F_54 ( 0 ) |
F_55 ( V_139 ) ) ;
V_130 -> V_143 . V_144 = V_145 ;
V_130 -> V_143 . V_146 = F_56 ( V_134 -> V_146 ) ;
V_130 -> V_143 . V_147 = 0 ;
V_136 = (struct V_135 * ) ( ( unsigned char * ) V_130 +
sizeof( struct V_129 ) ) ;
for ( V_84 = 0 ; V_139 ; V_136 ++ ) {
for ( V_85 = 0 ; V_85 < 8 && V_139 ; V_85 ++ , V_139 -- ) {
V_137 -= F_57 ( V_132 ) ;
V_136 -> V_20 [ V_85 ] = F_56 ( F_57 ( V_132 ) ) ;
V_136 -> V_148 [ V_85 ] = F_42 ( F_58 ( V_132 ) ) ;
V_132 = F_59 ( V_132 ) ;
}
}
if ( V_137 ) {
V_85 -- ;
V_136 -- ;
V_136 -> V_20 [ V_85 ] = F_56 ( F_60 ( V_136 -> V_20 [ V_85 ] ) + ( V_137 ) ) ;
}
}
static inline int F_61 ( struct V_149 * V_16 ,
struct V_129 * V_130 ,
struct V_131 * V_132 ,
struct V_133 * V_134 )
{
if ( ! V_132 || ! V_134 -> V_139 )
return 0 ;
V_134 -> V_139 = F_62 ( V_16 , V_132 , V_134 -> V_139 , V_58 ) ;
if ( V_134 -> V_139 == 0 ) {
F_40 ( L_7 ) ;
return - V_118 ;
}
F_47 ( V_130 , V_132 , V_134 ) ;
return 0 ;
}
static inline int F_12 ( struct V_29 * V_150 )
{
struct V_151 * V_124 = F_63 ( V_150 ) ;
struct V_125 * V_126 =
F_45 ( V_124 , struct V_125 , V_124 . V_150 ) ;
return V_126 -> type & V_152 ;
}
static inline int F_64 ( struct V_43 * V_30 )
{
struct V_123 * V_124 = V_30 -> V_48 ;
struct V_125 * V_126 =
F_45 ( V_124 , struct V_125 , V_124 . V_153 ) ;
return V_126 -> type & V_152 ;
}
static inline void F_65 ( struct V_18 * V_19 ,
unsigned int * V_154 ,
char * V_155 ,
T_1 V_156 )
{
V_19 -> V_20 += V_156 ;
V_19 -> V_157 += V_156 ;
V_19 -> V_158 += V_156 ;
F_66 ( F_67 ( V_155 ) ) ;
F_68 ( V_19 , * V_154 , F_67 ( V_155 ) ,
F_69 ( V_155 ) , V_156 ) ;
( * V_154 ) ++ ;
}
static inline void
F_70 ( struct V_18 * V_19 , unsigned int * V_154 ,
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
V_161 = F_71 ( V_132 ) ;
F_66 ( V_161 ) ;
V_162 = F_72 ( V_132 -> V_163 , V_159 ) ;
F_68 ( V_19 , * V_154 , V_161 , V_132 -> V_164 , V_162 ) ;
( * V_154 ) ++ ;
V_159 -= V_162 ;
V_132 = F_59 ( V_132 ) ;
}
}
static int F_73 ( struct V_6 * V_7 ,
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
static inline void F_74 ( struct V_2 * V_3 ,
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
V_172 -> V_183 . V_184 = F_75 ( V_181 ,
( ( sizeof( V_172 -> V_166 ) + V_173 ) >> 4 ) ) ;
V_172 -> V_183 . V_185 =
F_33 ( F_76 ( V_186 [ V_78 ] ) |
F_77 ( V_174 ) ) ;
V_172 -> V_183 . V_187 =
F_33 ( F_78 ( F_25 (
( F_24 ( V_19 ) * 8 ) , 16 ) ) ) ;
V_172 -> V_183 . V_188 = F_42 ( ( V_189 ) V_24 ) ;
V_172 -> V_183 . V_190 =
F_79 ( V_3 -> V_16 -> V_180 , V_146 ,
V_175 ? V_177 : V_191 ) ;
V_172 -> V_192 . V_193 = F_80 ( V_3 -> V_16 -> V_180 ) ;
V_172 -> V_192 . V_20 = F_33 ( ( F_25 ( ( F_24 ( V_19 ) * 8 ) ,
16 ) - ( ( sizeof( V_172 -> V_183 ) ) >> 4 ) ) ) ;
V_172 -> V_194 . V_195 = F_81 ( V_181 ) ;
V_172 -> V_194 . V_20 = F_43 ( sizeof( struct V_196 ) +
sizeof( V_172 -> V_166 ) +
V_173 + V_176 + V_181 ) ;
}
static struct V_18
* F_82 ( struct V_64 * V_24 ,
unsigned short V_146 ,
unsigned short V_197 )
{
struct V_198 * V_30 = F_83 ( V_24 ) ;
struct V_2 * V_3 = F_84 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
struct V_129 * V_130 ;
struct V_199 * V_53 = F_20 ( V_24 ) ;
struct V_133 V_134 ;
unsigned int V_154 = 0 , V_200 , V_201 ;
unsigned int V_202 = F_85 ( V_30 ) , V_173 ;
T_3 V_203 = V_24 -> V_204 . V_203 & V_205 ? V_206 :
V_207 ;
if ( ! V_24 -> V_65 )
return F_86 ( - V_118 ) ;
V_53 -> V_57 = F_87 ( V_24 -> V_56 , V_24 -> V_208 ) ;
if ( V_53 -> V_57 <= 0 ) {
F_40 ( L_8 ) ;
return F_86 ( - V_118 ) ;
}
if ( ( V_7 -> V_170 == 0 ) || ( V_202 > V_66 ) ||
( V_24 -> V_208 <= 0 ) || ( V_24 -> V_208 % V_66 ) ) {
F_40 ( L_9 ,
V_7 -> V_170 , V_24 -> V_208 , V_202 ) ;
return F_86 ( - V_118 ) ;
}
V_201 = F_88 ( V_53 -> V_57 ) ;
V_173 = ( F_25 ( V_7 -> V_170 , 16 ) * 16 ) ;
V_200 = F_89 ( V_173 , V_201 ) ;
V_19 = F_90 ( ( V_200 + sizeof( struct V_209 ) ) , V_203 ) ;
if ( ! V_19 )
return F_86 ( - V_210 ) ;
F_91 ( V_19 , sizeof( struct V_209 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_200 ) ;
memset ( V_172 , 0 , V_200 ) ;
V_172 -> V_211 . V_212 =
F_93 ( V_3 -> V_16 -> V_180 , 2 , 1 ) ;
V_172 -> V_211 . V_213 = F_33 ( V_202 + V_24 -> V_208 ) ;
V_172 -> V_211 . V_214 =
F_94 ( 0 , 0 , V_202 + 1 , 0 ) ;
V_172 -> V_211 . V_215 =
F_95 ( 0 , 0 , 0 , 0 ) ;
V_172 -> V_211 . V_216 = F_96 ( V_197 , 0 ,
V_7 -> V_167 ,
0 , 0 , V_202 >> 1 ) ;
V_172 -> V_211 . V_217 = F_97 ( 0 , 0 , 0 ,
0 , 1 , V_201 ) ;
V_172 -> V_166 . V_218 = V_7 -> V_219 ;
if ( V_197 == V_220 ) {
F_73 ( V_7 , & V_172 -> V_166 ) ;
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
V_134 . V_138 = V_24 -> V_208 ;
V_134 . V_146 = V_146 ;
V_134 . V_221 = 1 ;
if ( F_61 ( & V_17 -> V_54 . V_55 -> V_16 , V_130 , V_24 -> V_56 ,
& V_134 ) )
goto V_222;
F_98 ( V_19 , V_200 ) ;
memcpy ( V_53 -> V_223 , V_24 -> V_65 , V_202 ) ;
F_65 ( V_19 , & V_154 , V_53 -> V_223 , V_202 ) ;
F_70 ( V_19 , & V_154 , V_24 -> V_38 , V_24 -> V_208 ) ;
F_74 ( V_3 , V_172 , V_24 , V_19 , V_173 , 0 , 1 ,
sizeof( struct V_129 ) + V_201 ) ;
V_53 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
V_222:
F_19 ( V_19 ) ;
return F_86 ( - V_210 ) ;
}
static int F_100 ( struct V_198 * V_30 , const T_1 * V_80 ,
unsigned int V_224 )
{
struct V_2 * V_3 = F_84 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned int V_225 , V_226 ;
T_4 V_227 = 0 ;
if ( V_224 == V_228 ) {
V_225 = V_229 ;
} else if ( V_224 == V_230 ) {
V_227 = 8 ;
V_225 = V_231 ;
} else if ( V_224 == V_232 ) {
V_225 = V_233 ;
} else {
goto V_234;
}
memcpy ( V_7 -> V_80 , V_80 , V_224 ) ;
V_7 -> V_170 = V_224 ;
F_30 ( V_7 -> V_169 , V_7 -> V_80 , V_224 << 3 ) ;
V_226 = ( V_235 +
V_224 + V_227 ) >> 4 ;
V_7 -> V_219 = F_101 ( V_225 , V_236 ,
0 , 0 , V_226 ) ;
V_7 -> V_167 = V_168 ;
return 0 ;
V_234:
F_102 ( V_30 , V_237 ) ;
V_7 -> V_170 = 0 ;
return - V_118 ;
}
static int F_103 ( struct V_238 * V_16 , unsigned int V_239 )
{
struct V_240 * V_241 = F_104 ( V_16 ) ;
struct V_242 * V_243 =
V_241 -> V_244 . V_245 [ V_246 ] ;
struct V_247 * V_248 ;
int V_249 = 0 ;
F_105 () ;
V_248 = & V_243 -> V_250 [ V_239 ] ;
F_106 ( & V_248 -> V_251 . V_252 ) ;
if ( V_248 -> V_253 )
V_249 = - 1 ;
F_107 ( & V_248 -> V_251 . V_252 ) ;
F_108 () ;
return V_249 ;
}
static int F_109 ( struct V_64 * V_24 )
{
struct V_198 * V_30 = F_83 ( V_24 ) ;
struct V_2 * V_3 = F_84 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_18 * V_19 ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_254 [ 0 ] ,
V_3 -> V_180 ) ) ) {
if ( ! ( V_24 -> V_204 . V_203 & V_255 ) )
return - V_256 ;
}
V_19 = F_82 ( V_24 , V_17 -> V_54 . V_179 [ V_3 -> V_180 ] ,
V_257 ) ;
if ( F_111 ( V_19 ) ) {
F_40 ( L_10 , V_258 ) ;
return F_112 ( V_19 ) ;
}
V_19 -> V_16 = V_17 -> V_54 . V_254 [ 0 ] ;
F_113 ( V_19 , V_259 , V_3 -> V_180 ) ;
F_114 ( V_19 ) ;
return - V_260 ;
}
static int F_115 ( struct V_64 * V_24 )
{
struct V_198 * V_30 = F_83 ( V_24 ) ;
struct V_2 * V_3 = F_84 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_18 * V_19 ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_254 [ 0 ] ,
V_3 -> V_180 ) ) ) {
if ( ! ( V_24 -> V_204 . V_203 & V_255 ) )
return - V_256 ;
}
V_19 = F_82 ( V_24 , V_17 -> V_54 . V_179 [ 0 ] ,
V_220 ) ;
if ( F_111 ( V_19 ) ) {
F_40 ( L_10 , V_258 ) ;
return F_112 ( V_19 ) ;
}
V_19 -> V_16 = V_17 -> V_54 . V_254 [ 0 ] ;
F_113 ( V_19 , V_259 , V_3 -> V_180 ) ;
F_114 ( V_19 ) ;
return - V_260 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_15 * V_17 ;
unsigned int V_261 ;
int V_26 = 0 , V_262 , V_263 ;
V_261 = F_117 () ;
if ( ! V_3 -> V_16 ) {
V_26 = F_118 ( & V_3 -> V_16 ) ;
if ( V_26 ) {
F_40 ( L_11 ) ;
goto V_264;
}
V_17 = F_6 ( V_3 ) ;
V_262 = V_17 -> V_54 . V_265 / V_17 -> V_54 . V_266 ;
V_263 = V_3 -> V_16 -> V_180 * V_262 ;
V_263 += V_261 % V_262 ;
F_106 ( & V_3 -> V_16 -> V_267 ) ;
V_3 -> V_180 = V_263 ;
V_3 -> V_16 -> V_180 = ! V_3 -> V_16 -> V_180 ;
F_107 ( & V_3 -> V_16 -> V_267 ) ;
}
V_264:
return V_26 ;
}
static int F_119 ( struct V_43 * V_30 )
{
V_30 -> V_268 . V_269 = sizeof( struct V_199 ) ;
return F_116 ( F_16 ( V_30 ) ) ;
}
static int F_120 ( struct V_270 * V_271 ,
unsigned int V_272 )
{
switch ( V_272 ) {
case V_102 :
V_271 -> V_273 = V_274 ;
V_271 -> V_275 = V_276 ;
V_271 -> V_277 = V_102 ;
break;
case V_71 :
V_271 -> V_273 = V_278 ;
V_271 -> V_275 = V_279 ;
V_271 -> V_277 = V_72 ;
break;
case V_72 :
V_271 -> V_273 = V_278 ;
V_271 -> V_275 = V_280 ;
V_271 -> V_277 = V_72 ;
break;
case V_73 :
V_271 -> V_273 = V_281 ;
V_271 -> V_275 = V_282 ;
V_271 -> V_277 = V_28 ;
break;
case V_28 :
V_271 -> V_273 = V_281 ;
V_271 -> V_275 = V_283 ;
V_271 -> V_277 = V_28 ;
break;
default:
F_40 ( L_12 ) ;
return - V_118 ;
}
return 0 ;
}
static inline void F_121 ( struct V_99 * V_101 )
{
F_122 ( V_101 ) ;
}
static struct V_18 * F_123 ( struct V_69 * V_24 ,
struct V_284 * V_285 )
{
struct V_286 * V_287 = F_21 ( V_24 ) ;
struct V_288 * V_30 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_124 ( V_30 ) ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
unsigned int V_154 = 0 , V_200 , V_289 = 0 ;
unsigned int V_46 = F_22 ( V_30 ) ;
unsigned int V_173 = 0 ;
T_1 V_290 = 0 ;
T_3 V_203 = V_24 -> V_204 . V_203 & V_205 ? V_206 :
V_207 ;
V_289 = F_125 ( V_46 ) ;
V_173 = V_285 -> V_291 . V_277 + V_289 ;
if ( V_285 -> V_292 )
V_173 += V_285 -> V_291 . V_277 + V_289 ;
if ( V_287 -> V_74 )
V_290 = V_46 ;
else
V_290 = V_285 -> V_291 . V_277 ;
V_200 = F_126 ( V_173 ) ;
V_19 = F_90 ( ( V_200 + sizeof( struct V_209 ) ) , V_203 ) ;
if ( ! V_19 )
return V_19 ;
F_91 ( V_19 , sizeof( struct V_209 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_200 ) ;
memset ( V_172 , 0 , V_200 ) ;
V_172 -> V_211 . V_212 =
F_93 ( V_3 -> V_16 -> V_180 , 2 , 0 ) ;
V_172 -> V_211 . V_213 = F_33 ( V_285 -> V_156 + V_285 -> V_293 ) ;
V_172 -> V_211 . V_214 =
F_94 ( 0 , 0 , 0 , 0 ) ;
V_172 -> V_211 . V_215 =
F_95 ( 0 , 1 , 0 , 0 ) ;
V_172 -> V_211 . V_216 =
F_96 ( 0 , 0 , 0 , V_285 -> V_291 . V_275 ,
V_285 -> V_292 , 0 ) ;
V_172 -> V_211 . V_217 =
F_97 ( V_285 -> V_294 , V_285 -> V_295 , 0 , 1 , 0 , 0 ) ;
memcpy ( V_172 -> V_166 . V_80 , V_287 -> V_75 ,
V_285 -> V_291 . V_277 ) ;
if ( V_285 -> V_292 )
memcpy ( V_172 -> V_166 . V_80 +
( ( V_285 -> V_291 . V_277 <= 32 ) ? 32 :
V_296 ) ,
V_9 -> V_297 , V_285 -> V_291 . V_277 ) ;
V_172 -> V_166 . V_218 = F_101 ( V_236 ,
V_285 -> V_291 . V_273 , 0 ,
V_285 -> V_292 ,
( ( V_173 +
sizeof( V_172 -> V_166 ) ) >> 4 ) ) ;
V_172 -> V_211 . V_298 = F_42 ( ( V_120 ) V_285 -> V_298 ) ;
F_98 ( V_19 , V_200 ) ;
if ( V_285 -> V_156 != 0 )
F_65 ( V_19 , & V_154 , V_287 -> V_299 ,
V_285 -> V_156 ) ;
if ( V_285 -> V_293 != 0 )
F_70 ( V_19 , & V_154 , V_24 -> V_38 , V_285 -> V_293 ) ;
F_74 ( V_3 , V_172 , V_24 , V_19 , V_173 , V_290 , 0 ,
V_300 ) ;
V_287 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
}
static int F_127 ( struct V_69 * V_24 )
{
struct V_286 * V_287 = F_21 ( V_24 ) ;
struct V_288 * V_301 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_124 ( V_301 ) ) ;
struct V_15 * V_17 = NULL ;
struct V_18 * V_19 ;
T_1 V_302 = 0 , V_303 ;
unsigned int V_208 = V_24 -> V_208 ;
struct V_284 V_271 ;
V_303 = F_128 ( F_124 ( V_301 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_254 [ 0 ] ,
V_3 -> V_180 ) ) ) {
if ( ! ( V_24 -> V_204 . V_203 & V_255 ) )
return - V_256 ;
}
if ( V_208 + V_287 -> V_304 >= V_303 ) {
V_302 = ( V_208 + V_287 -> V_304 ) % V_303 ;
V_208 = V_208 + V_287 -> V_304 - V_302 ;
} else {
F_13 ( V_24 -> V_38 , F_14 ( V_24 -> V_38 ) , V_287 -> V_299
+ V_287 -> V_304 , V_208 , 0 ) ;
V_287 -> V_304 += V_208 ;
return 0 ;
}
V_271 . V_292 = 0 ;
V_271 . V_295 = 1 ;
V_271 . V_294 = 0 ;
V_271 . V_293 = V_208 - V_287 -> V_304 ;
V_271 . V_156 = V_287 -> V_304 ;
V_271 . V_298 = 0 ;
F_120 ( & V_271 . V_291 , F_22 ( V_301 ) ) ;
V_287 -> V_74 = 0 ;
V_287 -> V_157 += V_271 . V_293 + V_271 . V_156 ;
V_19 = F_123 ( V_24 , & V_271 ) ;
if ( ! V_19 )
return - V_210 ;
if ( V_302 ) {
T_1 * V_27 ;
V_27 = V_287 -> V_299 ;
V_287 -> V_299 = V_287 -> V_305 ;
V_287 -> V_305 = V_27 ;
F_13 ( V_24 -> V_38 , F_14 ( V_24 -> V_38 ) ,
V_287 -> V_299 , V_302 , V_24 -> V_208 -
V_302 ) ;
}
V_287 -> V_304 = V_302 ;
V_19 -> V_16 = V_17 -> V_54 . V_254 [ 0 ] ;
F_113 ( V_19 , V_259 , V_3 -> V_180 ) ;
F_114 ( V_19 ) ;
return - V_260 ;
}
static void F_129 ( char * V_306 , unsigned int V_303 , V_120 V_298 )
{
memset ( V_306 , 0 , V_303 ) ;
* V_306 = 0x80 ;
if ( V_303 == 64 )
* ( V_121 * ) ( V_306 + 56 ) = F_42 ( V_298 << 3 ) ;
else
* ( V_121 * ) ( V_306 + 120 ) = F_42 ( V_298 << 3 ) ;
}
static int F_130 ( struct V_69 * V_24 )
{
struct V_286 * V_287 = F_21 ( V_24 ) ;
struct V_288 * V_301 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_124 ( V_301 ) ) ;
struct V_284 V_271 ;
struct V_18 * V_19 ;
struct V_15 * V_17 = NULL ;
T_1 V_303 = F_128 ( F_124 ( V_301 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_44 ( F_124 ( V_301 ) ) )
V_271 . V_292 = 1 ;
else
V_271 . V_292 = 0 ;
V_271 . V_293 = 0 ;
F_120 ( & V_271 . V_291 , F_22 ( V_301 ) ) ;
V_287 -> V_74 = 1 ;
V_271 . V_156 = V_287 -> V_304 ;
V_287 -> V_157 += V_271 . V_156 + V_271 . V_293 ;
if ( V_287 -> V_304 == 0 ) {
F_129 ( V_287 -> V_299 , V_303 , V_287 -> V_157 ) ;
V_271 . V_294 = 0 ;
V_271 . V_295 = 1 ;
V_271 . V_298 = 0 ;
V_271 . V_156 = V_303 ;
} else {
V_271 . V_298 = V_287 -> V_157 ;
V_271 . V_294 = 1 ;
V_271 . V_295 = 0 ;
}
V_19 = F_123 ( V_24 , & V_271 ) ;
if ( ! V_19 )
return - V_210 ;
V_19 -> V_16 = V_17 -> V_54 . V_254 [ 0 ] ;
F_113 ( V_19 , V_259 , V_3 -> V_180 ) ;
F_114 ( V_19 ) ;
return - V_260 ;
}
static int F_131 ( struct V_69 * V_24 )
{
struct V_286 * V_287 = F_21 ( V_24 ) ;
struct V_288 * V_301 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_124 ( V_301 ) ) ;
struct V_15 * V_17 = NULL ;
struct V_18 * V_19 ;
struct V_284 V_271 ;
T_1 V_303 ;
V_303 = F_128 ( F_124 ( V_301 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_254 [ 0 ] ,
V_3 -> V_180 ) ) ) {
if ( ! ( V_24 -> V_204 . V_203 & V_255 ) )
return - V_256 ;
}
if ( F_44 ( F_124 ( V_301 ) ) )
V_271 . V_292 = 1 ;
else
V_271 . V_292 = 0 ;
V_271 . V_293 = V_24 -> V_208 ;
V_271 . V_156 = V_287 -> V_304 ;
F_120 ( & V_271 . V_291 , F_22 ( V_301 ) ) ;
V_287 -> V_157 += V_271 . V_156 + V_271 . V_293 ;
V_287 -> V_74 = 1 ;
if ( ( V_287 -> V_304 + V_24 -> V_208 ) == 0 ) {
F_129 ( V_287 -> V_299 , V_303 , V_287 -> V_157 ) ;
V_271 . V_294 = 0 ;
V_271 . V_295 = 1 ;
V_271 . V_298 = 0 ;
V_271 . V_156 = V_303 ;
} else {
V_271 . V_298 = V_287 -> V_157 ;
V_271 . V_294 = 1 ;
V_271 . V_295 = 0 ;
}
V_19 = F_123 ( V_24 , & V_271 ) ;
if ( ! V_19 )
return - V_210 ;
V_19 -> V_16 = V_17 -> V_54 . V_254 [ 0 ] ;
F_113 ( V_19 , V_259 , V_3 -> V_180 ) ;
F_114 ( V_19 ) ;
return - V_260 ;
}
static int F_132 ( struct V_69 * V_24 )
{
struct V_286 * V_287 = F_21 ( V_24 ) ;
struct V_288 * V_301 = F_23 ( V_24 ) ;
struct V_2 * V_3 = F_16 ( F_124 ( V_301 ) ) ;
struct V_15 * V_17 = NULL ;
struct V_18 * V_19 ;
struct V_284 V_271 ;
T_1 V_303 ;
V_301 -> V_307 ( V_24 ) ;
V_303 = F_128 ( F_124 ( V_301 ) ) ;
V_17 = F_6 ( V_3 ) ;
if ( F_110 ( F_103 ( V_17 -> V_54 . V_254 [ 0 ] ,
V_3 -> V_180 ) ) ) {
if ( ! ( V_24 -> V_204 . V_203 & V_255 ) )
return - V_256 ;
}
if ( F_44 ( F_124 ( V_301 ) ) )
V_271 . V_292 = 1 ;
else
V_271 . V_292 = 0 ;
V_271 . V_294 = 0 ;
V_271 . V_295 = 0 ;
V_271 . V_293 = V_24 -> V_208 ;
V_271 . V_156 = 0 ;
V_271 . V_298 = 0 ;
F_120 ( & V_271 . V_291 , F_22 ( V_301 ) ) ;
V_287 -> V_74 = 1 ;
V_287 -> V_157 += V_271 . V_156 + V_271 . V_293 ;
if ( V_24 -> V_208 == 0 ) {
F_129 ( V_287 -> V_299 , V_303 , 0 ) ;
V_271 . V_295 = 1 ;
V_271 . V_156 = V_303 ;
}
V_19 = F_123 ( V_24 , & V_271 ) ;
if ( ! V_19 )
return - V_210 ;
V_19 -> V_16 = V_17 -> V_54 . V_254 [ 0 ] ;
F_113 ( V_19 , V_259 , V_3 -> V_180 ) ;
F_114 ( V_19 ) ;
return - V_260 ;
}
static int F_133 ( struct V_69 * V_308 , void * V_264 )
{
struct V_286 * V_287 = F_21 ( V_308 ) ;
struct V_286 * V_115 = V_264 ;
V_115 -> V_304 = V_287 -> V_304 ;
V_115 -> V_157 = V_287 -> V_157 ;
memcpy ( V_115 -> V_309 , V_287 -> V_299 , V_287 -> V_304 ) ;
memcpy ( V_115 -> V_75 , V_287 -> V_75 ,
V_296 ) ;
return 0 ;
}
static int F_134 ( struct V_69 * V_308 , const void * V_310 )
{
struct V_286 * V_287 = F_21 ( V_308 ) ;
struct V_286 * V_115 = (struct V_286 * ) V_310 ;
V_287 -> V_304 = V_115 -> V_304 ;
V_287 -> V_157 = V_115 -> V_157 ;
V_287 -> V_299 = V_287 -> V_309 ;
V_287 -> V_305 = V_287 -> V_311 ;
memcpy ( V_287 -> V_309 , V_115 -> V_309 , V_312 ) ;
memcpy ( V_287 -> V_75 , V_115 -> V_75 ,
V_296 ) ;
return 0 ;
}
static int F_135 ( struct V_288 * V_30 , const T_1 * V_80 ,
unsigned int V_224 )
{
struct V_2 * V_3 = F_16 ( F_124 ( V_30 ) ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
unsigned int V_46 = F_22 ( V_30 ) ;
unsigned int V_303 = F_128 ( F_124 ( V_30 ) ) ;
unsigned int V_84 , V_26 = 0 , V_47 ;
F_136 ( V_313 , V_9 -> V_101 ) ;
V_313 -> V_30 = V_9 -> V_101 ;
V_313 -> V_203 = F_137 ( V_9 -> V_101 ) ;
if ( V_224 > V_303 ) {
V_26 = F_138 ( V_313 , V_80 , V_224 ,
V_9 -> V_314 ) ;
if ( V_26 )
goto V_264;
V_224 = V_46 ;
} else {
memcpy ( V_9 -> V_314 , V_80 , V_224 ) ;
}
memset ( V_9 -> V_314 + V_224 , 0 , V_303 - V_224 ) ;
memcpy ( V_9 -> V_297 , V_9 -> V_314 , V_303 ) ;
for ( V_84 = 0 ; V_84 < V_303 / sizeof( int ) ; V_84 ++ ) {
* ( ( unsigned int * ) ( & V_9 -> V_314 ) + V_84 ) ^= V_315 ;
* ( ( unsigned int * ) ( & V_9 -> V_297 ) + V_84 ) ^= V_316 ;
}
V_47 = V_46 ;
if ( V_46 == V_71 )
V_47 = V_72 ;
else if ( V_46 == V_73 )
V_47 = V_28 ;
V_26 = F_36 ( V_313 , V_9 -> V_314 ,
V_9 -> V_314 , V_46 ) ;
if ( V_26 )
goto V_264;
F_41 ( V_9 -> V_314 , V_47 ) ;
V_26 = F_36 ( V_313 , V_9 -> V_297 ,
V_9 -> V_297 , V_46 ) ;
if ( V_26 )
goto V_264;
F_41 ( V_9 -> V_297 , V_47 ) ;
V_264:
return V_26 ;
}
static int F_139 ( struct V_198 * V_30 , const T_1 * V_80 ,
unsigned int V_317 )
{
struct V_2 * V_3 = F_84 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned short V_226 = 0 ;
if ( ( V_317 != ( V_228 << 1 ) ) &&
( V_317 != ( V_232 << 1 ) ) ) {
F_140 ( (struct V_43 * ) V_30 ,
V_237 ) ;
V_7 -> V_170 = 0 ;
return - V_118 ;
}
memcpy ( V_7 -> V_80 , V_80 , V_317 ) ;
V_7 -> V_170 = V_317 ;
F_30 ( V_7 -> V_169 , V_7 -> V_80 , V_317 << 2 ) ;
V_226 = ( V_235 + V_317 ) >> 4 ;
V_7 -> V_219 =
F_101 ( ( V_317 == V_232 ) ?
V_229 :
V_233 ,
V_236 , 1 ,
0 , V_226 ) ;
V_7 -> V_167 = V_318 ;
return 0 ;
}
static int F_141 ( struct V_69 * V_308 )
{
struct V_286 * V_287 = F_21 ( V_308 ) ;
struct V_288 * V_30 = F_23 ( V_308 ) ;
int V_46 = F_22 ( V_30 ) ;
V_287 -> V_157 = 0 ;
V_287 -> V_304 = 0 ;
V_287 -> V_299 = V_287 -> V_309 ;
V_287 -> V_305 = V_287 -> V_311 ;
V_287 -> V_19 = NULL ;
V_287 -> V_74 = 0 ;
F_142 ( V_287 -> V_75 , V_46 ) ;
return 0 ;
}
static int F_143 ( struct V_43 * V_30 )
{
F_144 ( F_145 ( V_30 ) ,
sizeof( struct V_286 ) ) ;
return F_116 ( F_16 ( V_30 ) ) ;
}
static int F_146 ( struct V_69 * V_308 )
{
struct V_286 * V_287 = F_21 ( V_308 ) ;
struct V_288 * V_301 = F_23 ( V_308 ) ;
struct V_2 * V_3 = F_16 ( F_124 ( V_301 ) ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
unsigned int V_46 = F_22 ( V_301 ) ;
unsigned int V_303 = F_128 ( F_124 ( V_301 ) ) ;
F_141 ( V_308 ) ;
V_287 -> V_157 = V_303 ;
if ( F_44 ( F_124 ( V_301 ) ) ) {
if ( V_46 == V_71 )
memcpy ( V_287 -> V_75 , V_9 -> V_314 ,
V_72 ) ;
else if ( V_46 == V_73 )
memcpy ( V_287 -> V_75 , V_9 -> V_314 ,
V_28 ) ;
else
memcpy ( V_287 -> V_75 , V_9 -> V_314 ,
V_46 ) ;
}
return 0 ;
}
static int F_147 ( struct V_43 * V_30 )
{
struct V_2 * V_3 = F_16 ( V_30 ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
unsigned int V_46 =
F_22 ( F_145 ( V_30 ) ) ;
F_144 ( F_145 ( V_30 ) ,
sizeof( struct V_286 ) ) ;
V_9 -> V_101 = F_34 ( V_46 ) ;
if ( F_111 ( V_9 -> V_101 ) )
return F_112 ( V_9 -> V_101 ) ;
return F_116 ( F_16 ( V_30 ) ) ;
}
static void F_148 ( struct V_43 * V_30 )
{
struct V_2 * V_3 = F_16 ( V_30 ) ;
struct V_8 * V_9 = F_3 ( V_3 ) ;
if ( V_9 -> V_101 ) {
F_121 ( V_9 -> V_101 ) ;
V_9 -> V_101 = NULL ;
}
}
static int F_149 ( struct V_23 * V_24 ,
struct V_1 * V_3 )
{
F_150 ( V_319 , V_3 -> null ) ;
F_151 ( V_319 , V_3 -> null ) ;
F_152 ( V_319 , F_153 ( V_24 ) ,
NULL , NULL ) ;
F_154 ( V_319 , V_24 -> V_38 , V_24 -> V_56 , V_24 -> V_39 ,
NULL ) ;
return F_155 ( V_319 ) ;
}
static unsigned char F_156 ( unsigned int V_31 )
{
switch ( V_31 ) {
case V_320 :
return V_321 ;
case V_322 :
return V_323 ;
case V_324 :
return V_325 ;
}
return V_326 ;
}
static struct V_18 * F_157 ( struct V_23 * V_24 ,
unsigned short V_146 ,
int V_327 ,
unsigned short V_197 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_158 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_328 = F_5 ( V_5 ) ;
struct V_329 * V_53 = F_17 ( V_24 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
struct V_129 * V_130 ;
struct V_133 V_134 ;
struct V_131 * V_38 ;
unsigned int V_154 = 0 , V_200 ;
unsigned int V_202 = F_159 ( V_30 ) , V_330 = 0 ;
unsigned int V_173 = 0 ;
unsigned short V_331 = 0 ;
unsigned int V_39 = V_24 -> V_39 ;
unsigned int V_31 = F_11 ( V_30 ) ;
int V_26 = 0 ;
int null = 0 ;
T_3 V_203 = V_24 -> V_204 . V_203 & V_205 ? V_206 :
V_207 ;
if ( V_5 -> V_170 == 0 || ( V_24 -> V_40 == 0 ) )
goto V_26;
if ( V_197 && V_24 -> V_40 < F_11 ( V_30 ) )
goto V_26;
if ( F_87 ( V_24 -> V_38 , V_24 -> V_39 + V_24 -> V_40 ) < 0 )
goto V_26;
V_38 = F_160 ( V_53 -> V_332 , V_24 -> V_38 , V_24 -> V_39 ) ;
V_53 -> V_56 = V_38 ;
if ( V_24 -> V_38 != V_24 -> V_56 ) {
V_26 = F_149 ( V_24 , V_5 ) ;
if ( V_26 )
return F_86 ( V_26 ) ;
V_53 -> V_56 = F_160 ( V_53 -> V_333 , V_24 -> V_56 ,
V_24 -> V_39 ) ;
}
if ( F_12 ( V_30 ) == V_334 ) {
null = 1 ;
V_39 = 0 ;
}
V_53 -> V_57 = F_87 ( V_53 -> V_56 , V_24 -> V_40 +
( V_197 ? - V_31 : V_31 ) ) ;
if ( V_53 -> V_57 <= 0 ) {
F_40 ( L_13 ) ;
goto V_26;
}
V_330 = F_88 ( V_53 -> V_57 ) ;
V_173 = ( F_161 ( F_162 ( V_5 -> V_219 ) ) << 4 )
- sizeof( V_172 -> V_166 ) ;
V_200 = F_89 ( V_173 , V_330 ) ;
V_19 = F_90 ( ( V_200 + sizeof( struct V_209 ) ) , V_203 ) ;
if ( ! V_19 )
goto V_26;
F_91 ( V_19 , sizeof( struct V_209 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_200 ) ;
memset ( V_172 , 0 , V_200 ) ;
V_331 = ( V_197 == V_257 ) ? 0 : V_31 ;
V_172 -> V_211 . V_212 =
F_93 ( V_3 -> V_16 -> V_180 , 2 ,
( V_202 ? ( V_39 + 1 ) : 0 ) ) ;
V_172 -> V_211 . V_213 = F_33 ( V_39 + V_202 + V_24 -> V_40 ) ;
V_172 -> V_211 . V_214 = F_94 (
V_39 ? 1 : 0 , V_39 ,
V_39 + V_202 + 1 ,
( V_331 & 0x1F0 ) >> 4 ) ;
V_172 -> V_211 . V_215 = F_95 (
V_331 & 0xF ,
null ? 0 : V_39 + V_202 + 1 ,
V_331 , V_331 ) ;
V_172 -> V_211 . V_216 = F_96 ( V_197 ,
( V_197 == V_257 ) ? 1 : 0 ,
V_168 ,
V_328 -> V_275 , V_5 -> V_335 ,
V_202 >> 1 ) ;
V_172 -> V_211 . V_217 = F_97 ( 0 , 0 , 1 ,
0 , 1 , V_330 ) ;
V_172 -> V_166 . V_218 = V_5 -> V_219 ;
if ( V_197 == V_257 )
memcpy ( V_172 -> V_166 . V_80 , V_5 -> V_80 ,
V_5 -> V_170 ) ;
else
memcpy ( V_172 -> V_166 . V_80 , V_328 -> V_336 ,
V_5 -> V_170 ) ;
memcpy ( V_172 -> V_166 . V_80 + ( F_25 ( V_5 -> V_170 , 16 ) <<
4 ) , V_328 -> V_337 , V_173 -
( F_25 ( V_5 -> V_170 , 16 ) << 4 ) ) ;
V_130 = (struct V_129 * ) ( ( T_1 * ) ( V_172 + 1 ) + V_173 ) ;
V_134 . V_139 = V_53 -> V_57 ;
V_134 . V_138 = V_24 -> V_40 + ( V_197 ? - V_31 : V_31 ) ;
V_134 . V_146 = V_146 ;
V_134 . V_221 = 0 ;
if ( F_61 ( & V_17 -> V_54 . V_55 -> V_16 , V_130 , V_53 -> V_56 ,
& V_134 ) )
goto V_338;
F_98 ( V_19 , V_200 ) ;
if ( V_39 ) {
F_70 ( V_19 , & V_154 , V_24 -> V_38 , V_39 ) ;
}
F_65 ( V_19 , & V_154 , V_24 -> V_223 , V_202 ) ;
F_70 ( V_19 , & V_154 , V_38 , V_24 -> V_40 ) ;
F_74 ( V_3 , V_172 , V_24 , V_19 , V_173 , V_327 , 1 ,
sizeof( struct V_129 ) + V_330 ) ;
V_53 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
V_338:
F_19 ( V_19 ) ;
V_26:
return F_86 ( - V_118 ) ;
}
static void F_163 ( struct V_131 * V_132 ,
unsigned short V_164 )
{
struct V_160 * V_161 ;
unsigned char * V_148 ;
V_161 = F_71 ( V_132 ) ;
F_66 ( V_161 ) ;
#ifdef F_164
V_148 = F_165 ( V_161 , V_339 ) ;
#else
V_148 = F_165 ( V_161 ) ;
#endif
memset ( V_148 + V_132 -> V_164 , 0 , V_164 + 1 ) ;
F_166 ( V_148 ) ;
}
static int F_167 ( T_1 * V_340 , unsigned int V_341 , int V_342 )
{
V_122 V_37 ;
memset ( V_340 , 0 , V_342 ) ;
V_340 += V_342 ;
if ( V_342 >= 4 )
V_342 = 4 ;
else if ( V_341 > ( unsigned int ) ( 1 << ( 8 * V_342 ) ) )
return - V_343 ;
V_37 = F_43 ( V_341 ) ;
memcpy ( V_340 - V_342 , ( T_1 * ) & V_37 + 4 - V_342 , V_342 ) ;
return 0 ;
}
static void F_168 ( struct V_23 * V_24 ,
struct V_1 * V_5 ,
unsigned short V_197 )
{
unsigned int V_344 , V_345 , V_346 ;
int V_347 ;
struct V_29 * V_150 = F_10 ( V_24 ) ;
struct V_329 * V_53 = F_17 ( V_24 ) ;
T_1 * V_348 = V_53 -> V_349 ;
V_346 = F_11 ( V_150 ) ;
memcpy ( V_348 , V_53 -> V_223 , 16 ) ;
V_345 = V_348 [ 0 ] ;
V_344 = V_345 + 1 ;
* V_348 |= ( 8 * ( ( V_346 - 2 ) / 2 ) ) ;
if ( V_24 -> V_39 )
* V_348 |= 64 ;
V_347 = F_167 ( V_348 + 16 - V_344 ,
( V_197 == V_220 ) ?
V_24 -> V_40 - V_346 : V_24 -> V_40 , V_344 ) ;
}
static inline int F_169 ( const T_1 * V_223 )
{
if ( V_223 [ 0 ] < 1 || V_223 [ 0 ] > 7 )
return - V_118 ;
return 0 ;
}
static int F_170 ( struct V_23 * V_24 ,
struct V_1 * V_5 ,
unsigned int V_350 ,
unsigned short V_197 )
{
struct V_329 * V_53 = F_17 ( V_24 ) ;
int V_347 = 0 ;
if ( V_24 -> V_39 > V_351 ) {
F_40 ( L_14 ,
V_351 ) ;
return - V_118 ;
}
if ( V_350 == V_352 ) {
V_53 -> V_223 [ 0 ] = 3 ;
memcpy ( V_53 -> V_223 + 1 , & V_5 -> V_353 [ 0 ] , 3 ) ;
memcpy ( V_53 -> V_223 + 4 , V_24 -> V_223 , 8 ) ;
memset ( V_53 -> V_223 + 12 , 0 , 4 ) ;
* ( ( unsigned short * ) ( V_53 -> V_349 + 16 ) ) =
F_56 ( V_24 -> V_39 - 8 ) ;
} else {
memcpy ( V_53 -> V_223 , V_24 -> V_223 , 16 ) ;
* ( ( unsigned short * ) ( V_53 -> V_349 + 16 ) ) =
F_56 ( V_24 -> V_39 ) ;
}
F_168 ( V_24 , V_5 , V_197 ) ;
memset ( V_53 -> V_223 + 15 - V_53 -> V_223 [ 0 ] , 0 , V_53 -> V_223 [ 0 ] + 1 ) ;
return V_347 ;
}
static void F_171 ( struct V_196 * V_211 ,
unsigned int V_330 ,
struct V_23 * V_24 ,
unsigned short V_197 ,
struct V_2 * V_354 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
unsigned int V_202 = V_66 ;
unsigned int V_355 = V_356 ;
unsigned int V_357 = V_358 ;
unsigned int V_359 = V_354 -> V_16 -> V_180 ;
unsigned int V_360 ;
unsigned char V_361 = 0 , V_362 = 0 ;
unsigned char V_335 = F_156 ( F_11 ( V_30 ) ) ;
unsigned int V_39 ;
if ( F_12 ( V_30 ) == V_352 )
V_39 = V_24 -> V_39 - 8 ;
else
V_39 = V_24 -> V_39 ;
V_360 = V_363 +
( ( V_39 ) ? V_364 : 0 ) ;
V_362 = V_24 -> V_40 ?
( V_39 + V_202 + 1 + V_360 ) : 0 ;
if ( V_197 == V_220 ) {
if ( F_11 ( V_30 ) != V_24 -> V_40 )
V_361 = F_11 ( V_30 ) ;
else
V_362 = 0 ;
}
V_211 -> V_212 = F_93 ( V_359 ,
2 , ( V_202 ? ( V_39 + 1 ) : 0 ) +
V_360 ) ;
V_211 -> V_213 =
F_33 ( V_39 + V_202 + V_24 -> V_40 + V_360 ) ;
V_211 -> V_214 = F_94 (
1 , V_39 + V_360 , V_39
+ V_202 + 1 + V_360 , 0 ) ;
V_211 -> V_215 = F_95 ( 0 ,
V_362 , V_361 ,
( V_197 == V_257 ) ? 0 :
F_11 ( V_30 ) ) ;
V_211 -> V_216 = F_96 ( V_197 ,
( V_197 == V_257 ) ? 0 : 1 ,
V_355 , V_357 , V_335 ,
V_202 >> 1 ) ;
V_211 -> V_217 = F_97 ( 0 , 0 , 1 , 0 ,
1 , V_330 ) ;
}
int F_172 ( unsigned short V_197 ,
struct V_23 * V_24 ,
struct V_1 * V_5 ,
unsigned int V_350 )
{
if ( V_350 != V_352 ) {
if ( F_169 ( V_24 -> V_223 ) ) {
F_40 ( L_15 ) ;
return - V_118 ;
}
} else {
if ( V_24 -> V_39 != 16 && V_24 -> V_39 != 20 ) {
F_40 ( L_16 ,
V_24 -> V_39 ) ;
return - V_118 ;
}
}
if ( V_5 -> V_170 == 0 ) {
F_40 ( L_17 ) ;
return - V_118 ;
}
return 0 ;
}
unsigned int F_173 ( struct V_18 * V_19 ,
struct V_23 * V_24 ,
struct V_131 * V_38 ,
unsigned int V_202 ,
struct V_1 * V_5 )
{
unsigned int V_154 = 0 ;
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_329 * V_53 = F_17 ( V_24 ) ;
F_65 ( V_19 , & V_154 , V_53 -> V_349 , V_363 +
( V_24 -> V_39 ? V_364 : 0 ) ) ;
if ( V_24 -> V_39 ) {
if ( F_12 ( V_30 ) == V_352 )
F_70 ( V_19 , & V_154 , V_24 -> V_38 ,
V_24 -> V_39 - 8 ) ;
else
F_70 ( V_19 , & V_154 , V_24 -> V_38 , V_24 -> V_39 ) ;
}
F_65 ( V_19 , & V_154 , V_53 -> V_223 , V_202 ) ;
if ( V_24 -> V_40 )
F_70 ( V_19 , & V_154 , V_38 , V_24 -> V_40 ) ;
return V_154 ;
}
static struct V_18 * F_174 ( struct V_23 * V_24 ,
unsigned short V_146 ,
int V_327 ,
unsigned short V_197 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_158 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_329 * V_53 = F_17 ( V_24 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
struct V_129 * V_130 ;
struct V_133 V_134 ;
struct V_131 * V_38 ;
unsigned int V_154 = 0 , V_200 , V_202 = V_66 ;
unsigned int V_330 = 0 , V_173 ;
unsigned int V_350 ;
unsigned int V_31 = F_11 ( V_30 ) ;
int V_26 = 0 ;
T_3 V_203 = V_24 -> V_204 . V_203 & V_205 ? V_206 :
V_207 ;
if ( V_197 && V_24 -> V_40 < F_11 ( V_30 ) )
goto V_26;
if ( F_87 ( V_24 -> V_38 , V_24 -> V_39 + V_24 -> V_40 ) < 0 )
goto V_26;
V_350 = F_12 ( V_30 ) ;
V_38 = F_160 ( V_53 -> V_332 , V_24 -> V_38 , V_24 -> V_39 ) ;
V_53 -> V_56 = V_38 ;
if ( V_24 -> V_38 != V_24 -> V_56 ) {
V_26 = F_149 ( V_24 , V_5 ) ;
if ( V_26 ) {
F_40 ( L_18 ) ;
return F_86 ( V_26 ) ;
}
V_53 -> V_56 = F_160 ( V_53 -> V_333 , V_24 -> V_56 ,
V_24 -> V_39 ) ;
}
V_53 -> V_57 = F_87 ( V_53 -> V_56 , V_24 -> V_40 +
( V_197 ? - V_31 : V_31 ) ) ;
if ( V_53 -> V_57 <= 0 ) {
F_40 ( L_19 ) ;
goto V_26;
}
if ( F_172 ( V_197 , V_24 , V_5 , V_350 ) )
goto V_26;
V_330 = F_88 ( V_53 -> V_57 ) ;
V_173 = ( ( F_25 ( V_5 -> V_170 , 16 ) ) << 4 ) * 2 ;
V_200 = F_89 ( V_173 , V_330 ) ;
V_19 = F_90 ( ( V_200 + sizeof( struct V_209 ) ) , V_203 ) ;
if ( ! V_19 )
goto V_26;
F_91 ( V_19 , sizeof( struct V_209 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_200 ) ;
memset ( V_172 , 0 , V_200 ) ;
F_171 ( & V_172 -> V_211 , V_330 , V_24 , V_197 , V_3 ) ;
V_172 -> V_166 . V_218 = V_5 -> V_219 ;
memcpy ( V_172 -> V_166 . V_80 , V_5 -> V_80 , V_5 -> V_170 ) ;
memcpy ( V_172 -> V_166 . V_80 + ( F_25 ( V_5 -> V_170 , 16 ) *
16 ) , V_5 -> V_80 , V_5 -> V_170 ) ;
V_130 = (struct V_129 * ) ( ( T_1 * ) ( V_172 + 1 ) + V_173 ) ;
if ( F_170 ( V_24 , V_5 , V_350 , V_197 ) )
goto V_338;
V_134 . V_139 = V_53 -> V_57 ;
V_134 . V_138 = V_24 -> V_40 + ( V_197 ? - V_31 : V_31 ) ;
V_134 . V_146 = V_146 ;
V_134 . V_221 = 0 ;
if ( F_61 ( & V_17 -> V_54 . V_55 -> V_16 , V_130 , V_53 -> V_56 ,
& V_134 ) )
goto V_338;
F_98 ( V_19 , V_200 ) ;
V_154 = F_173 ( V_19 , V_24 , V_38 , V_202 , V_5 ) ;
F_74 ( V_3 , V_172 , V_24 , V_19 , V_173 , 0 , 1 ,
sizeof( struct V_129 ) + V_330 ) ;
V_53 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
V_338:
F_19 ( V_19 ) ;
V_19 = NULL ;
V_26:
return F_86 ( - V_118 ) ;
}
static struct V_18 * F_175 ( struct V_23 * V_24 ,
unsigned short V_146 ,
int V_327 ,
unsigned short V_197 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_158 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_329 * V_53 = F_17 ( V_24 ) ;
struct V_18 * V_19 = NULL ;
struct V_171 * V_172 ;
struct V_129 * V_130 ;
struct V_133 V_134 ;
struct V_131 * V_38 ;
unsigned int V_154 = 0 , V_200 ;
unsigned int V_202 = V_66 ;
unsigned int V_330 = 0 , V_173 ;
unsigned char V_361 = 0 ;
unsigned int V_365 = 0 ;
unsigned int V_31 = F_11 ( V_30 ) ;
unsigned char V_335 = F_156 ( V_31 ) ;
int V_26 = 0 ;
T_3 V_203 = V_24 -> V_204 . V_203 & V_205 ? V_206 :
V_207 ;
if ( V_5 -> V_170 == 0 )
goto V_26;
if ( V_197 && V_24 -> V_40 < F_11 ( V_30 ) )
goto V_26;
if ( F_87 ( V_24 -> V_38 , V_24 -> V_39 + V_24 -> V_40 ) < 0 )
goto V_26;
V_38 = F_160 ( V_53 -> V_332 , V_24 -> V_38 , V_24 -> V_39 ) ;
V_53 -> V_56 = V_38 ;
if ( V_24 -> V_38 != V_24 -> V_56 ) {
V_26 = F_149 ( V_24 , V_5 ) ;
if ( V_26 )
return F_86 ( V_26 ) ;
V_53 -> V_56 = F_160 ( V_53 -> V_333 , V_24 -> V_56 ,
V_24 -> V_39 ) ;
}
if ( ! V_24 -> V_40 )
V_365 = V_66 ;
else
V_365 = V_24 -> V_40 ;
V_53 -> V_57 = F_87 ( V_53 -> V_56 , V_24 -> V_40 +
( V_197 ? - V_31 : V_31 ) ) ;
if ( V_53 -> V_57 <= 0 ) {
F_40 ( L_20 ) ;
goto V_26;
}
V_330 = F_88 ( V_53 -> V_57 ) ;
V_173 = ( ( F_25 ( V_5 -> V_170 , 16 ) ) << 4 ) +
V_366 ;
V_200 = F_89 ( V_173 , V_330 ) ;
V_19 = F_90 ( ( V_200 + sizeof( struct V_209 ) ) , V_203 ) ;
if ( ! V_19 )
goto V_26;
F_91 ( V_19 , sizeof( struct V_209 ) ) ;
V_172 = (struct V_171 * ) F_92 ( V_19 , V_200 ) ;
memset ( V_172 , 0 , V_200 ) ;
if ( F_12 ( V_30 ) == V_35 )
V_24 -> V_39 -= 8 ;
V_361 = ( V_197 == V_257 ) ? 0 : V_31 ;
V_172 -> V_211 . V_212 = F_93 (
V_3 -> V_16 -> V_180 , 2 , ( V_202 ?
( V_24 -> V_39 + 1 ) : 0 ) ) ;
V_172 -> V_211 . V_213 = F_33 ( V_24 -> V_39 + V_202 + V_365 ) ;
V_172 -> V_211 . V_214 = F_94 (
V_24 -> V_39 ? 1 : 0 , V_24 -> V_39 ,
V_24 -> V_39 + V_202 + 1 , 0 ) ;
if ( V_24 -> V_40 ) {
V_172 -> V_211 . V_215 =
F_95 ( 0 , V_24 -> V_39 + V_202 + 1 ,
V_361 , V_361 ) ;
V_172 -> V_211 . V_216 =
F_96 ( V_197 , ( V_197 ==
V_257 ) ? 1 : 0 ,
V_367 ,
V_368 , V_335 ,
V_202 >> 1 ) ;
} else {
V_172 -> V_211 . V_215 =
F_95 ( 0 , 0 , 0 , 0 ) ;
V_172 -> V_211 . V_216 =
F_96 ( V_197 ,
( V_197 == V_257 ) ?
1 : 0 , V_168 ,
0 , 0 , V_202 >> 1 ) ;
}
V_172 -> V_211 . V_217 = F_97 ( 0 , 0 , 1 ,
0 , 1 , V_330 ) ;
V_172 -> V_166 . V_218 = V_5 -> V_219 ;
memcpy ( V_172 -> V_166 . V_80 , V_5 -> V_80 , V_5 -> V_170 ) ;
memcpy ( V_172 -> V_166 . V_80 + ( F_25 ( V_5 -> V_170 , 16 ) *
16 ) , F_4 ( V_5 ) -> V_369 , V_366 ) ;
if ( F_12 ( V_30 ) ==
V_35 ) {
memcpy ( V_53 -> V_223 , V_5 -> V_353 , 4 ) ;
memcpy ( V_53 -> V_223 + 4 , V_24 -> V_223 , 8 ) ;
} else {
memcpy ( V_53 -> V_223 , V_24 -> V_223 , 12 ) ;
}
* ( ( unsigned int * ) ( V_53 -> V_223 + 12 ) ) = F_33 ( 0x01 ) ;
V_130 = (struct V_129 * ) ( ( T_1 * ) ( V_172 + 1 ) + V_173 ) ;
V_134 . V_139 = V_53 -> V_57 ;
V_134 . V_138 = V_24 -> V_40 + ( V_197 ? - V_31 : V_31 ) ;
V_134 . V_146 = V_146 ;
V_134 . V_221 = 0 ;
if ( F_61 ( & V_17 -> V_54 . V_55 -> V_16 , V_130 , V_53 -> V_56 ,
& V_134 ) )
goto V_338;
F_98 ( V_19 , V_200 ) ;
F_70 ( V_19 , & V_154 , V_24 -> V_38 , V_24 -> V_39 ) ;
F_65 ( V_19 , & V_154 , V_53 -> V_223 , V_202 ) ;
if ( V_24 -> V_40 ) {
F_70 ( V_19 , & V_154 , V_38 , V_24 -> V_40 ) ;
} else {
F_163 ( V_24 -> V_56 , V_31 - 1 ) ;
F_70 ( V_19 , & V_154 , V_53 -> V_56 , V_365 ) ;
}
F_74 ( V_3 , V_172 , V_24 , V_19 , V_173 , V_327 , 1 ,
sizeof( struct V_129 ) + V_330 ) ;
V_53 -> V_19 = V_19 ;
F_99 ( V_19 ) ;
return V_19 ;
V_338:
F_19 ( V_19 ) ;
V_19 = NULL ;
V_26:
return V_19 ;
}
static int F_176 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_158 ( V_30 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_177 ( V_30 , sizeof( struct V_329 ) ) ;
V_5 -> null = F_178 () ;
if ( F_111 ( V_5 -> null ) )
return F_112 ( V_5 -> null ) ;
return F_116 ( V_3 ) ;
}
static void F_179 ( struct V_29 * V_30 )
{
F_180 () ;
}
static int F_181 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_158 ( V_30 ) ) ;
V_5 -> V_335 = V_370 ;
V_5 -> V_371 = V_61 ;
return 0 ;
}
static int F_182 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_158 ( V_30 ) ) ;
T_2 V_372 = F_183 ( V_30 ) ;
if ( V_31 == V_373 ) {
V_5 -> V_335 = V_321 ;
V_5 -> V_371 = V_61 ;
} else if ( V_31 == V_374 ) {
V_5 -> V_335 = V_375 ;
V_5 -> V_371 = V_61 ;
} else if ( V_31 == V_322 ) {
V_5 -> V_335 = V_323 ;
V_5 -> V_371 = V_61 ;
} else if ( V_31 == V_324 ) {
V_5 -> V_335 = V_325 ;
V_5 -> V_371 = V_61 ;
} else if ( V_31 == V_376 ) {
V_5 -> V_335 = V_377 ;
V_5 -> V_371 = V_61 ;
} else if ( V_31 == ( V_372 >> 1 ) ) {
V_5 -> V_335 = V_378 ;
V_5 -> V_371 = V_61 ;
} else if ( V_31 == V_372 ) {
V_5 -> V_335 = V_326 ;
V_5 -> V_371 = V_61 ;
} else {
V_5 -> V_335 = V_326 ;
V_5 -> V_371 = V_60 ;
}
return 0 ;
}
static int F_184 ( struct V_29 * V_30 , unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_158 ( V_30 ) ) ;
switch ( V_31 ) {
case V_373 :
V_5 -> V_335 = V_321 ;
V_5 -> V_371 = V_61 ;
break;
case V_320 :
V_5 -> V_335 = V_378 ;
V_5 -> V_371 = V_61 ;
break;
case V_324 :
V_5 -> V_335 = V_325 ;
V_5 -> V_371 = V_61 ;
break;
case V_376 :
V_5 -> V_335 = V_377 ;
V_5 -> V_371 = V_61 ;
break;
case V_379 :
V_5 -> V_335 = V_326 ;
V_5 -> V_371 = V_61 ;
break;
case V_380 :
case V_381 :
V_5 -> V_335 = V_326 ;
V_5 -> V_371 = V_60 ;
break;
default:
F_140 ( (struct V_43 * ) V_30 ,
V_237 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_185 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_158 ( V_30 ) ) ;
switch ( V_31 ) {
case V_320 :
V_5 -> V_335 = V_378 ;
V_5 -> V_371 = V_61 ;
break;
case V_324 :
V_5 -> V_335 = V_325 ;
V_5 -> V_371 = V_61 ;
break;
case V_379 :
V_5 -> V_335 = V_326 ;
V_5 -> V_371 = V_61 ;
break;
default:
F_140 ( (struct V_43 * ) V_30 ,
V_237 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_186 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_5 = F_1 ( F_158 ( V_30 ) ) ;
switch ( V_31 ) {
case V_373 :
V_5 -> V_335 = V_321 ;
V_5 -> V_371 = V_61 ;
break;
case V_374 :
V_5 -> V_335 = V_375 ;
V_5 -> V_371 = V_61 ;
break;
case V_320 :
V_5 -> V_335 = V_378 ;
V_5 -> V_371 = V_61 ;
break;
case V_322 :
V_5 -> V_335 = V_323 ;
V_5 -> V_371 = V_61 ;
break;
case V_324 :
V_5 -> V_335 = V_325 ;
V_5 -> V_371 = V_61 ;
break;
case V_376 :
V_5 -> V_335 = V_377 ;
V_5 -> V_371 = V_61 ;
break;
case V_379 :
V_5 -> V_335 = V_326 ;
V_5 -> V_371 = V_61 ;
break;
default:
F_140 ( (struct V_43 * ) V_30 ,
V_237 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_187 ( struct V_29 * V_150 ,
const T_1 * V_80 ,
unsigned int V_224 )
{
struct V_2 * V_3 = F_158 ( V_150 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned char V_225 , V_273 ;
int V_382 = 0 ;
memcpy ( V_5 -> V_80 , V_80 , V_224 ) ;
V_5 -> V_170 = V_224 ;
V_382 = sizeof( struct V_165 ) +
( ( F_25 ( V_224 , 16 ) ) << 4 ) * 2 ;
if ( V_224 == V_228 ) {
V_273 = V_229 ;
V_225 = V_229 ;
} else if ( V_224 == V_230 ) {
V_225 = V_231 ;
V_273 = V_383 ;
} else if ( V_224 == V_232 ) {
V_225 = V_233 ;
V_273 = V_278 ;
} else {
F_140 ( (struct V_43 * ) V_150 ,
V_237 ) ;
V_5 -> V_170 = 0 ;
return - V_118 ;
}
V_5 -> V_219 = F_101 ( V_225 , V_273 , 0 , 0 ,
V_382 >> 4 ) ;
return 0 ;
}
static int F_188 ( struct V_29 * V_150 , const T_1 * V_80 ,
unsigned int V_224 )
{
struct V_2 * V_3 = F_158 ( V_150 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_224 < 3 ) {
F_140 ( (struct V_43 * ) V_150 ,
V_237 ) ;
V_5 -> V_170 = 0 ;
return - V_118 ;
}
V_224 -= 3 ;
memcpy ( V_5 -> V_353 , V_80 + V_224 , 3 ) ;
return F_187 ( V_150 , V_80 , V_224 ) ;
}
static int F_189 ( struct V_29 * V_150 , const T_1 * V_80 ,
unsigned int V_224 )
{
struct V_2 * V_3 = F_158 ( V_150 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_10 * V_11 = F_4 ( V_5 ) ;
struct V_384 V_385 ;
struct V_131 V_38 [ 1 ] ;
unsigned int V_225 ;
int V_249 = 0 , V_382 = 0 ;
if ( F_12 ( V_150 ) == V_35 &&
V_224 > 3 ) {
V_224 -= 4 ;
memcpy ( V_5 -> V_353 , V_80 + V_224 , 4 ) ;
}
if ( V_224 == V_228 ) {
V_225 = V_229 ;
} else if ( V_224 == V_230 ) {
V_225 = V_231 ;
} else if ( V_224 == V_232 ) {
V_225 = V_233 ;
} else {
F_140 ( (struct V_43 * ) V_150 ,
V_237 ) ;
V_5 -> V_170 = 0 ;
F_40 ( L_21 , V_224 ) ;
V_249 = - V_118 ;
goto V_264;
}
memcpy ( V_5 -> V_80 , V_80 , V_224 ) ;
V_5 -> V_170 = V_224 ;
V_382 = sizeof( struct V_165 ) +
( ( F_25 ( V_224 , 16 ) ) << 4 ) +
V_366 ;
V_5 -> V_219 = F_101 ( V_225 ,
V_386 ,
0 , 0 ,
V_382 >> 4 ) ;
V_385 . V_30 = F_190 ( L_22 , 0 , 0 ) ;
if ( F_111 ( V_385 . V_30 ) ) {
V_5 -> V_170 = 0 ;
V_249 = - V_210 ;
goto V_264;
}
V_385 . V_203 = 0 ;
V_249 = F_191 ( V_385 . V_30 , V_80 , V_224 ) ;
if ( V_249 ) {
V_5 -> V_170 = 0 ;
goto V_387;
}
memset ( V_11 -> V_369 , 0 , V_366 ) ;
F_192 ( & V_38 [ 0 ] , V_11 -> V_369 , V_366 ) ;
V_249 = F_193 ( & V_385 , & V_38 [ 0 ] , & V_38 [ 0 ] , V_366 ) ;
V_387:
F_194 ( V_385 . V_30 ) ;
V_264:
return V_249 ;
}
static int F_195 ( struct V_29 * V_14 , const T_1 * V_80 ,
unsigned int V_224 )
{
struct V_2 * V_3 = F_158 ( V_14 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_328 = F_5 ( V_5 ) ;
struct V_388 V_389 ;
unsigned int V_303 ;
unsigned int V_390 = F_63 ( V_14 ) -> V_391 ;
int V_26 = 0 , V_84 , V_392 = 0 ;
unsigned char V_225 = 0 ;
unsigned char V_393 [ V_312 ] = { 0 } ;
struct V_99 * V_101 = NULL ;
struct V_270 V_285 ;
int V_221 ;
T_1 * V_394 = NULL ;
if ( F_196 ( & V_389 , V_80 , V_224 ) != 0 ) {
F_197 ( V_14 , V_237 ) ;
goto V_264;
}
if ( F_120 ( & V_285 , V_390 ) ) {
F_40 ( L_23 ) ;
goto V_264;
}
if ( V_389 . V_395 == V_228 ) {
V_225 = V_229 ;
} else if ( V_389 . V_395 == V_230 ) {
V_225 = V_231 ;
} else if ( V_389 . V_395 == V_232 ) {
V_225 = V_233 ;
} else {
F_40 ( L_24 ) ;
goto V_264;
}
memcpy ( V_5 -> V_80 , V_389 . V_396 , V_389 . V_395 ) ;
V_5 -> V_170 = V_389 . V_395 ;
F_30 ( V_328 -> V_336 , V_5 -> V_80 ,
V_5 -> V_170 << 3 ) ;
V_101 = F_34 ( V_390 ) ;
if ( F_111 ( V_101 ) ) {
F_40 ( L_25 ) ;
goto V_264;
}
{
F_136 ( V_313 , V_101 ) ;
V_313 -> V_30 = V_101 ;
V_313 -> V_203 = F_137 ( V_101 ) ;
V_303 = F_198 ( V_101 ) ;
V_221 = F_125 ( V_390 ) ;
V_394 = V_328 -> V_337 + V_285 . V_277 + V_221 ;
if ( V_389 . V_397 > V_303 ) {
V_26 = F_138 ( V_313 , V_389 . V_398 ,
V_389 . V_397 ,
V_394 ) ;
if ( V_26 ) {
F_40 ( L_25 ) ;
goto V_264;
}
V_389 . V_397 = V_390 ;
} else
memcpy ( V_394 , V_389 . V_398 , V_389 . V_397 ) ;
memset ( V_393 + V_389 . V_397 , 0 , V_303 - V_389 . V_397 ) ;
memcpy ( V_393 , V_394 , V_389 . V_397 ) ;
for ( V_84 = 0 ; V_84 < V_303 > > 2 ; V_84 ++ )
* ( ( unsigned int * ) V_393 + V_84 ) ^= V_315 ;
if ( F_36 ( V_313 , V_393 , V_328 -> V_337 ,
V_390 ) )
goto V_264;
memset ( V_393 + V_389 . V_397 , 0 , V_303 - V_389 . V_397 ) ;
memcpy ( V_393 , V_394 , V_389 . V_397 ) ;
for ( V_84 = 0 ; V_84 < V_303 > > 2 ; V_84 ++ )
* ( ( unsigned int * ) V_393 + V_84 ) ^= V_316 ;
if ( F_36 ( V_313 , V_393 , V_394 , V_390 ) )
goto V_264;
F_41 ( V_328 -> V_337 , V_285 . V_277 ) ;
F_41 ( V_394 , V_285 . V_277 ) ;
V_392 = sizeof( struct V_165 ) +
( ( F_25 ( V_389 . V_395 , 16 ) ) << 4 ) +
( V_285 . V_277 + V_221 ) * 2 ;
V_5 -> V_219 = F_101 ( V_225 , V_285 . V_273 ,
0 , 1 , V_392 >> 4 ) ;
V_328 -> V_275 = V_285 . V_275 ;
F_121 ( V_101 ) ;
return 0 ;
}
V_264:
V_5 -> V_170 = 0 ;
if ( V_101 )
F_121 ( V_101 ) ;
return - V_118 ;
}
static int F_199 ( struct V_29 * V_14 ,
const T_1 * V_80 , unsigned int V_224 )
{
struct V_2 * V_3 = F_158 ( V_14 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_13 * V_328 = F_5 ( V_5 ) ;
struct V_388 V_389 ;
int V_392 = 0 ;
unsigned char V_225 = 0 ;
if ( F_196 ( & V_389 , V_80 , V_224 ) != 0 ) {
F_197 ( V_14 , V_237 ) ;
goto V_264;
}
if ( V_389 . V_395 == V_228 ) {
V_225 = V_229 ;
} else if ( V_389 . V_395 == V_230 ) {
V_225 = V_231 ;
} else if ( V_389 . V_395 == V_232 ) {
V_225 = V_233 ;
} else {
F_40 ( L_24 ) ;
goto V_264;
}
memcpy ( V_5 -> V_80 , V_389 . V_396 , V_389 . V_395 ) ;
V_5 -> V_170 = V_389 . V_395 ;
F_30 ( V_328 -> V_336 , V_5 -> V_80 ,
V_5 -> V_170 << 3 ) ;
V_392 = sizeof( struct V_165 )
+ ( ( F_25 ( V_389 . V_395 , 16 ) ) << 4 ) ;
V_5 -> V_219 = F_101 ( V_225 , V_236 , 0 ,
0 , V_392 >> 4 ) ;
V_328 -> V_275 = V_399 ;
return 0 ;
V_264:
V_5 -> V_170 = 0 ;
return - V_118 ;
}
static int F_200 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_329 * V_53 = F_17 ( V_24 ) ;
V_53 -> V_59 = V_61 ;
switch ( F_12 ( V_30 ) ) {
case V_400 :
case V_334 :
return F_201 ( V_24 , V_257 , 0 ,
F_157 ) ;
case V_401 :
case V_352 :
return F_201 ( V_24 , V_257 , 0 ,
F_174 ) ;
default:
return F_201 ( V_24 , V_257 , 0 ,
F_175 ) ;
}
}
static int F_202 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_1 * V_5 = F_1 ( F_158 ( V_30 ) ) ;
struct V_329 * V_53 = F_17 ( V_24 ) ;
int V_327 ;
if ( V_5 -> V_371 == V_60 ) {
V_327 = F_183 ( V_30 ) ;
V_53 -> V_59 = V_60 ;
} else {
V_327 = 0 ;
V_53 -> V_59 = V_61 ;
}
switch ( F_12 ( V_30 ) ) {
case V_400 :
case V_334 :
return F_201 ( V_24 , V_220 , V_327 ,
F_157 ) ;
case V_401 :
case V_352 :
return F_201 ( V_24 , V_220 , V_327 ,
F_174 ) ;
default:
return F_201 ( V_24 , V_220 , V_327 ,
F_175 ) ;
}
}
static int F_201 ( struct V_23 * V_24 ,
unsigned short V_197 ,
int V_327 ,
T_5 V_402 )
{
struct V_29 * V_30 = F_10 ( V_24 ) ;
struct V_2 * V_3 = F_158 ( V_30 ) ;
struct V_15 * V_17 = F_6 ( V_3 ) ;
struct V_18 * V_19 ;
if ( V_3 && ! V_3 -> V_16 ) {
F_40 ( L_26 , V_258 ) ;
return - V_403 ;
}
if ( F_103 ( V_17 -> V_54 . V_254 [ 0 ] ,
V_3 -> V_180 ) ) {
if ( ! ( V_24 -> V_204 . V_203 & V_255 ) )
return - V_256 ;
}
V_19 = V_402 ( V_24 , V_17 -> V_54 . V_179 [ V_3 -> V_180 ] , V_327 ,
V_197 ) ;
if ( F_111 ( V_19 ) || V_19 == NULL ) {
F_40 ( L_27 , V_258 ) ;
return F_112 ( V_19 ) ;
}
V_19 -> V_16 = V_17 -> V_54 . V_254 [ 0 ] ;
F_113 ( V_19 , V_259 , V_3 -> V_180 ) ;
F_114 ( V_19 ) ;
return - V_260 ;
}
static int F_203 ( void )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < F_204 ( V_404 ) ; V_84 ++ ) {
switch ( V_404 [ V_84 ] . type & V_50 ) {
case V_405 :
if ( V_404 [ V_84 ] . V_406 )
F_205 (
& V_404 [ V_84 ] . V_124 . V_153 ) ;
break;
case V_51 :
if ( V_404 [ V_84 ] . V_406 )
F_206 (
& V_404 [ V_84 ] . V_124 . V_150 ) ;
break;
case V_67 :
if ( V_404 [ V_84 ] . V_406 )
F_207 (
& V_404 [ V_84 ] . V_124 . V_127 ) ;
break;
}
V_404 [ V_84 ] . V_406 = 0 ;
}
return 0 ;
}
static int F_208 ( void )
{
struct V_123 V_407 ;
struct V_408 * V_409 ;
int V_26 = 0 , V_84 ;
char * V_410 = NULL ;
for ( V_84 = 0 ; V_84 < F_204 ( V_404 ) ; V_84 ++ ) {
if ( V_404 [ V_84 ] . V_406 )
continue;
switch ( V_404 [ V_84 ] . type & V_50 ) {
case V_405 :
V_26 = F_209 ( & V_404 [ V_84 ] . V_124 . V_153 ) ;
V_410 = V_404 [ V_84 ] . V_124 . V_153 . V_411 ;
break;
case V_51 :
V_404 [ V_84 ] . V_124 . V_150 . V_204 . V_412 =
V_413 ;
V_404 [ V_84 ] . V_124 . V_150 . V_204 . V_49 =
V_51 | V_414 ;
V_404 [ V_84 ] . V_124 . V_150 . V_415 = F_200 ;
V_404 [ V_84 ] . V_124 . V_150 . V_416 = F_202 ;
V_404 [ V_84 ] . V_124 . V_150 . V_307 = F_176 ;
V_404 [ V_84 ] . V_124 . V_150 . exit = F_179 ;
V_404 [ V_84 ] . V_124 . V_150 . V_204 . V_417 = V_418 ;
V_26 = F_210 ( & V_404 [ V_84 ] . V_124 . V_150 ) ;
V_410 = V_404 [ V_84 ] . V_124 . V_150 . V_204 . V_411 ;
break;
case V_67 :
V_409 = & V_404 [ V_84 ] . V_124 . V_127 ;
V_409 -> V_419 = F_127 ;
V_409 -> V_420 = F_130 ;
V_409 -> V_421 = F_131 ;
V_409 -> V_422 = F_132 ;
V_409 -> V_423 = F_133 ;
V_409 -> V_424 = F_134 ;
V_409 -> V_425 . V_426 = V_427 ;
V_409 -> V_425 . V_204 . V_412 = V_413 ;
V_409 -> V_425 . V_204 . V_417 = V_418 ;
V_409 -> V_425 . V_204 . V_49 = V_428 ;
V_409 -> V_425 . V_204 . V_429 = 0 ;
V_409 -> V_425 . V_204 . V_430 = NULL ;
V_409 -> V_425 . V_204 . V_431 = & V_432 ;
if ( V_404 [ V_84 ] . type == V_128 ) {
V_409 -> V_425 . V_204 . V_433 = F_147 ;
V_409 -> V_425 . V_204 . V_430 = F_148 ;
V_409 -> V_307 = F_146 ;
V_409 -> V_434 = F_135 ;
V_409 -> V_425 . V_204 . V_435 = V_436 ;
} else {
V_409 -> V_307 = F_141 ;
V_409 -> V_425 . V_204 . V_435 = V_437 ;
V_409 -> V_425 . V_204 . V_433 = F_143 ;
}
V_26 = F_211 ( & V_404 [ V_84 ] . V_124 . V_127 ) ;
V_407 = V_404 [ V_84 ] . V_124 . V_127 . V_425 . V_204 ;
V_410 = V_407 . V_411 ;
break;
}
if ( V_26 ) {
F_40 ( L_28 ,
V_410 ) ;
goto V_438;
} else {
V_404 [ V_84 ] . V_406 = 1 ;
}
}
return 0 ;
V_438:
F_203 () ;
return V_26 ;
}
int F_212 ( void )
{
return F_208 () ;
}
int F_213 ( void )
{
F_203 () ;
return 0 ;
}
