static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static int F_2 ( const struct V_2 * V_3 )
{
if ( 3 * F_3 ( & V_3 -> V_4 ) <= 2 * V_3 -> V_5 )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_6 )
{
if ( V_6 -> V_7 . V_7 ) {
if ( V_6 -> V_7 . V_8 ) {
F_5 ( V_6 -> V_7 . V_8 ) ;
V_6 -> V_7 . V_8 = NULL ;
}
V_6 -> V_7 . V_9 ( V_6 ) ;
V_6 -> V_7 . V_7 = NULL ;
V_6 -> V_7 . V_9 = NULL ;
}
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_4 ( F_1 ( V_3 ) ) ;
F_9 ( & V_3 -> V_14 ) ;
if ( ! F_10 ( V_3 , V_15 ) ) {
F_11 ( L_1 , V_3 ) ;
return;
}
F_12 ( F_3 ( & V_3 -> V_4 ) ) ;
F_12 ( F_3 ( & V_3 -> V_16 ) ) ;
F_13 ( & V_12 -> V_17 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_15 ( & V_18 ) ;
F_16 ( V_3 , & V_12 -> V_19 ) ;
F_17 ( & V_18 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
F_15 ( & V_18 ) ;
F_19 ( V_3 ) ;
F_17 ( & V_18 ) ;
}
static int F_20 ( struct V_10 * V_10 , struct V_20 * V_2 , int V_21 ,
int V_22 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
struct V_2 * V_3 ;
int V_23 ;
if ( ! F_21 ( V_10 -> V_24 , V_25 ) )
return - V_26 ;
if ( V_2 -> type != V_27 )
return - V_28 ;
if ( V_21 != V_29 )
return - V_30 ;
V_23 = - V_31 ;
V_3 = F_22 ( V_10 , V_32 , V_33 , & V_34 ) ;
if ( V_3 == NULL )
goto V_35;
V_2 -> V_36 = & V_37 ;
F_23 ( V_2 , V_3 ) ;
V_3 -> V_38 = V_32 ;
V_3 -> V_39 = F_6 ;
F_24 ( & V_12 -> V_17 ) ;
F_14 ( V_3 ) ;
return 0 ;
V_35:
return V_23 ;
}
static int F_25 ( struct V_20 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
if ( ! V_3 )
return 0 ;
F_18 ( V_3 ) ;
F_26 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_9 ( & V_3 -> V_40 ) ;
F_27 () ;
F_28 ( V_3 ) ;
return 0 ;
}
static int F_29 ( struct V_41 * V_8 , struct V_41 * * V_42 ,
T_1 V_43 , struct V_2 * V_3 )
{
int V_23 = - V_44 ;
F_30 ( V_3 ) ;
if ( * V_42 == NULL ) {
if ( F_3 ( & V_8 -> V_45 ) != 1 ) {
* V_42 = F_31 ( V_8 , V_43 ) ;
} else {
* V_42 = V_8 ;
F_24 ( & V_8 -> V_45 ) ;
}
}
if ( * V_42 != NULL ) {
if ( F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 ) {
F_32 ( * V_42 , V_3 ) ;
F_33 ( & V_3 -> V_14 , * V_42 ) ;
V_3 -> V_46 ( V_3 ) ;
* V_42 = NULL ;
V_23 = 0 ;
}
}
F_28 ( V_3 ) ;
return V_23 ;
}
static int F_34 ( struct V_41 * V_8 , T_1 V_43 ,
int V_47 , struct V_2 * V_48 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
struct V_2 * V_3 ;
struct V_41 * V_42 = NULL ;
int V_23 = - V_49 ;
if ( ! V_8 )
return - V_31 ;
F_35 () ;
F_36 (sk, &net_pfkey->table) {
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_50 ;
if ( V_6 -> V_51 )
F_29 ( V_8 , & V_42 , V_43 , V_3 ) ;
if ( V_3 == V_48 )
continue;
if ( V_47 != V_52 ) {
if ( V_47 & V_53 )
continue;
if ( ( V_47 & V_54 ) &&
! V_6 -> V_55 )
continue;
if ( V_47 & V_56 )
continue;
}
V_50 = F_29 ( V_8 , & V_42 , V_43 , V_3 ) ;
if ( ( V_47 & V_54 ) && V_23 )
V_23 = V_50 ;
}
F_37 () ;
if ( V_48 != NULL )
V_23 = F_29 ( V_8 , & V_42 , V_43 , V_48 ) ;
F_5 ( V_42 ) ;
F_5 ( V_8 ) ;
return V_23 ;
}
static int F_38 ( struct V_1 * V_6 )
{
struct V_57 * V_58 ;
int V_59 ;
V_59 = V_6 -> V_7 . V_7 ( V_6 ) ;
if ( V_59 == - V_44 )
return 0 ;
if ( V_6 -> V_7 . V_8 ) {
if ( ! F_2 ( & V_6 -> V_3 ) )
return 0 ;
V_58 = (struct V_57 * ) V_6 -> V_7 . V_8 -> V_60 ;
V_58 -> V_61 = 0 ;
V_58 -> V_62 = V_59 ;
F_34 ( V_6 -> V_7 . V_8 , V_63 , V_56 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = NULL ;
}
F_4 ( V_6 ) ;
return V_59 ;
}
static inline void F_39 ( struct V_57 * V_64 ,
const struct V_57 * V_65 )
{
* V_64 = * V_65 ;
}
static int F_40 ( const struct V_57 * V_65 , int V_23 , struct V_2 * V_3 )
{
struct V_41 * V_8 = F_41 ( sizeof( struct V_57 ) + 16 , V_33 ) ;
struct V_57 * V_58 ;
if ( ! V_8 )
return - V_44 ;
V_23 = - V_23 ;
if ( V_23 == V_66 ||
V_23 == V_67 ||
V_23 == V_68 )
V_23 = V_69 ;
if ( V_23 >= 512 )
V_23 = V_70 ;
F_42 ( V_23 <= 0 || V_23 >= 256 ) ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
F_39 ( V_58 , V_65 ) ;
V_58 -> V_62 = ( V_71 ) V_23 ;
V_58 -> V_72 = ( sizeof( struct V_57 ) /
sizeof( V_73 ) ) ;
F_34 ( V_8 , V_33 , V_56 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_44 ( const void * V_74 )
{
const struct V_75 * V_76 = V_74 ;
const struct V_77 * V_78 = ( const struct V_77 * ) ( V_76 + 1 ) ;
const struct V_79 * sin ;
#if F_45 ( V_80 )
const struct V_81 * V_82 ;
#endif
int V_83 ;
switch ( V_78 -> V_84 ) {
case V_85 :
V_83 = F_46 ( sizeof( * V_76 ) + sizeof( * sin ) , sizeof( V_73 ) ) ;
if ( V_76 -> V_86 != V_83 ||
V_76 -> V_87 > 32 )
return - V_70 ;
break;
#if F_45 ( V_80 )
case V_88 :
V_83 = F_46 ( sizeof( * V_76 ) + sizeof( * V_82 ) , sizeof( V_73 ) ) ;
if ( V_76 -> V_86 != V_83 ||
V_76 -> V_87 > 128 )
return - V_70 ;
break;
#endif
default:
return - V_70 ;
}
return 0 ;
}
static inline int F_47 ( const struct V_89 * V_90 )
{
return F_46 ( sizeof( struct V_89 ) +
V_90 -> V_91 ,
sizeof( V_73 ) ) ;
}
static inline int F_48 ( const void * V_74 )
{
const struct V_89 * V_90 = V_74 ;
int V_83 = V_90 -> V_91 ;
if ( V_83 > V_92 )
return - V_70 ;
V_83 = F_47 ( V_90 ) ;
if ( V_90 -> V_93 != V_83 )
return - V_70 ;
return 0 ;
}
static inline struct V_94 * F_49 ( const struct V_89 * V_90 ,
T_1 V_95 )
{
struct V_94 * V_96 = NULL ;
int V_97 = V_90 -> V_91 ;
V_96 = F_50 ( ( sizeof( * V_96 ) + V_97 ) , V_95 ) ;
if ( ! V_96 )
return NULL ;
V_96 -> V_83 = F_47 ( V_90 ) ;
V_96 -> V_98 = V_90 -> V_99 ;
V_96 -> V_100 = V_90 -> V_101 ;
V_96 -> V_102 = V_90 -> V_103 ;
V_96 -> V_104 = V_90 -> V_91 ;
memcpy ( V_96 + 1 , V_90 + 1 ,
V_96 -> V_104 ) ;
return V_96 ;
}
static int F_51 ( const struct V_75 * V_105 ,
const struct V_75 * V_106 )
{
const struct V_77 * V_107 , * V_108 ;
if ( ! V_105 || ! V_106 )
return 0 ;
V_107 = ( const struct V_77 * ) ( V_105 + 1 ) ;
V_108 = ( const struct V_77 * ) ( V_106 + 1 ) ;
if ( V_107 -> V_84 != V_108 -> V_84 )
return 0 ;
if ( V_107 -> V_84 != V_85
#if F_45 ( V_80 )
&& V_107 -> V_84 != V_88
#endif
)
return 0 ;
return 1 ;
}
static int F_52 ( struct V_41 * V_8 , const struct V_57 * V_58 , void * * V_109 )
{
const char * V_74 = ( char * ) V_58 ;
int V_83 = V_8 -> V_83 ;
V_83 -= sizeof( * V_58 ) ;
V_74 += sizeof( * V_58 ) ;
while ( V_83 > 0 ) {
const struct V_110 * V_111 = ( const struct V_110 * ) V_74 ;
T_2 V_112 ;
int V_113 ;
V_113 = V_111 -> V_114 ;
V_113 *= sizeof( V_73 ) ;
V_112 = V_111 -> V_115 ;
if ( V_113 < sizeof( V_73 ) ||
V_113 > V_83 ||
V_112 == V_116 )
return - V_70 ;
if ( V_112 <= V_117 ) {
int V_118 = ( int ) V_119 [ V_112 ] ;
if ( V_113 < V_118 )
return - V_70 ;
if ( V_109 [ V_112 - 1 ] != NULL )
return - V_70 ;
if ( V_112 == V_120 ||
V_112 == V_121 ||
V_112 == V_122 ||
V_112 == V_123 ) {
if ( F_44 ( V_74 ) )
return - V_70 ;
}
if ( V_112 == V_124 ) {
if ( F_48 ( V_74 ) )
return - V_70 ;
}
V_109 [ V_112 - 1 ] = ( void * ) V_74 ;
}
V_74 += V_113 ;
V_83 -= V_113 ;
}
return 0 ;
}
static T_2
F_53 ( V_71 V_125 )
{
switch ( V_125 ) {
case V_126 :
return V_127 ;
case V_128 :
return V_129 ;
case V_130 :
return V_131 ;
case V_132 :
return V_133 ;
default:
return 0 ;
}
}
static V_71
F_54 ( T_2 V_134 )
{
switch ( V_134 ) {
case V_129 :
return V_128 ;
case V_131 :
return V_130 ;
case V_133 :
return V_132 ;
default:
return 0 ;
}
}
static V_71 F_55 ( V_71 V_134 )
{
return V_134 == V_127 ? 0 : V_134 ;
}
static V_71 F_56 ( V_71 V_134 )
{
return V_134 ? V_134 : V_127 ;
}
static inline int F_57 ( T_3 V_135 )
{
switch ( V_135 ) {
case V_85 :
return sizeof( struct V_79 ) ;
#if F_45 ( V_80 )
case V_88 :
return sizeof( struct V_81 ) ;
#endif
}
return 0 ;
}
static
int F_58 ( const struct V_77 * V_136 , T_4 * V_137 )
{
switch ( V_136 -> V_84 ) {
case V_85 :
V_137 -> V_138 =
( (struct V_79 * ) V_136 ) -> V_139 . V_107 ;
return V_85 ;
#if F_45 ( V_80 )
case V_88 :
memcpy ( V_137 -> V_140 ,
& ( (struct V_81 * ) V_136 ) -> V_141 ,
sizeof( struct V_142 ) ) ;
return V_88 ;
#endif
}
return 0 ;
}
static
int F_59 ( const struct V_75 * V_78 , T_4 * V_137 )
{
return F_58 ( (struct V_77 * ) ( V_78 + 1 ) ,
V_137 ) ;
}
static struct V_143 * F_60 ( struct V_10 * V_10 , const struct V_57 * V_58 , void * const * V_109 )
{
const struct V_144 * V_136 ;
const struct V_75 * V_78 ;
T_2 V_134 ;
unsigned short V_135 ;
T_4 * V_137 ;
V_136 = V_109 [ V_145 - 1 ] ;
if ( V_136 == NULL )
return NULL ;
V_134 = F_53 ( V_58 -> V_146 ) ;
if ( V_134 == 0 )
return NULL ;
V_78 = V_109 [ V_121 - 1 ] ;
if ( V_78 == NULL )
return NULL ;
V_135 = ( ( const struct V_77 * ) ( V_78 + 1 ) ) -> V_84 ;
switch ( V_135 ) {
case V_85 :
V_137 = ( T_4 * ) & ( ( const struct V_79 * ) ( V_78 + 1 ) ) -> V_139 ;
break;
#if F_45 ( V_80 )
case V_88 :
V_137 = ( T_4 * ) & ( ( const struct V_81 * ) ( V_78 + 1 ) ) -> V_141 ;
break;
#endif
default:
V_137 = NULL ;
}
if ( ! V_137 )
return NULL ;
return F_61 ( V_10 , V_147 , V_137 , V_136 -> V_148 , V_134 , V_135 ) ;
}
static int
F_62 ( T_3 V_135 )
{
return F_63 ( F_57 ( V_135 ) ) ;
}
static inline int F_64 ( int V_149 )
{
switch( V_149 ) {
case V_150 :
return V_151 ;
case V_152 :
return V_153 ;
case V_154 :
return V_155 ;
default:
return - 1 ;
}
}
static inline int F_65 ( int V_149 )
{
switch( V_149 ) {
case V_156 :
case V_151 :
return V_150 ;
case V_153 :
return V_152 ;
case V_155 :
return V_154 ;
default:
return - 1 ;
}
}
static unsigned int F_66 ( const T_4 * V_137 , T_5 V_157 ,
struct V_77 * V_136 ,
unsigned short V_135 )
{
switch ( V_135 ) {
case V_85 :
{
struct V_79 * sin = (struct V_79 * ) V_136 ;
sin -> V_158 = V_85 ;
sin -> V_159 = V_157 ;
sin -> V_139 . V_107 = V_137 -> V_138 ;
memset ( sin -> V_160 , 0 , sizeof( sin -> V_160 ) ) ;
return 32 ;
}
#if F_45 ( V_80 )
case V_88 :
{
struct V_81 * V_82 = (struct V_81 * ) V_136 ;
V_82 -> V_161 = V_88 ;
V_82 -> V_162 = V_157 ;
V_82 -> V_163 = 0 ;
V_82 -> V_141 = V_137 -> V_164 ;
V_82 -> V_165 = 0 ;
return 128 ;
}
#endif
}
return 0 ;
}
static struct V_41 * F_67 ( const struct V_143 * V_166 ,
int V_167 , int V_168 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
struct V_144 * V_136 ;
struct V_169 * V_170 ;
struct V_75 * V_78 ;
struct V_171 * V_172 ;
struct V_173 * V_174 ;
struct V_89 * V_90 ;
struct V_175 * V_176 ;
int V_97 = 0 ;
int V_177 ;
int V_178 = 0 ;
int V_179 = 0 ;
int V_180 ;
struct V_181 * V_182 = NULL ;
int V_149 ;
V_180 = F_62 ( V_166 -> V_183 . V_135 ) ;
if ( ! V_180 )
return F_68 ( - V_70 ) ;
V_177 = sizeof( struct V_57 ) + sizeof( struct V_144 ) +
sizeof( struct V_169 ) +
( ( V_168 & 1 ) ? sizeof( struct V_169 ) : 0 ) +
( ( V_168 & 2 ) ? sizeof( struct V_169 ) : 0 ) +
sizeof( struct V_75 ) * 2 +
V_180 * 2 +
sizeof( struct V_173 ) ;
if ( ( V_176 = V_166 -> V_184 ) ) {
V_97 = F_63 ( V_176 -> V_104 ) ;
V_177 += sizeof( struct V_89 ) + V_97 ;
}
if ( ! F_69 ( & V_166 -> V_185 . V_186 , & V_166 -> V_183 . V_186 , V_166 -> V_183 . V_135 ) )
V_177 += sizeof( struct V_75 ) + V_180 ;
if ( V_167 ) {
if ( V_166 -> V_187 && V_166 -> V_187 -> V_188 ) {
V_178 =
F_63 ( ( V_166 -> V_187 -> V_188 + 7 ) / 8 ) ;
V_177 += sizeof( struct V_171 ) + V_178 ;
}
if ( V_166 -> V_189 && V_166 -> V_189 -> V_188 ) {
V_179 =
F_63 ( ( V_166 -> V_189 -> V_188 + 7 ) / 8 ) ;
V_177 += sizeof( struct V_171 ) + V_179 ;
}
}
if ( V_166 -> V_190 )
V_182 = V_166 -> V_190 ;
if ( V_182 && V_182 -> V_191 ) {
V_177 += sizeof( struct V_192 ) ;
V_177 += sizeof( struct V_193 ) ;
V_177 += sizeof( struct V_193 ) ;
}
V_8 = F_41 ( V_177 + 16 , V_63 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
memset ( V_58 , 0 , V_177 ) ;
V_58 -> V_72 = V_177 / sizeof( V_73 ) ;
V_136 = (struct V_144 * ) F_43 ( V_8 , sizeof( struct V_144 ) ) ;
V_136 -> V_194 = sizeof( struct V_144 ) / sizeof( V_73 ) ;
V_136 -> V_195 = V_145 ;
V_136 -> V_148 = V_166 -> V_196 . V_197 ;
V_136 -> V_198 = V_166 -> V_183 . V_199 ;
switch ( V_166 -> V_200 . V_201 ) {
case V_202 :
V_136 -> V_203 = V_166 -> V_200 . V_204 ?
V_205 : V_206 ;
break;
case V_207 :
V_136 -> V_203 = V_208 ;
break;
default:
V_136 -> V_203 = V_209 ;
break;
}
V_136 -> V_210 = 0 ;
if ( V_166 -> V_187 ) {
struct V_211 * V_212 = F_70 ( V_166 -> V_187 -> V_213 , 0 ) ;
V_136 -> V_210 = ( V_212 && V_212 -> V_214 ) ?
V_212 -> V_215 . V_216 : 0 ;
}
V_136 -> V_217 = 0 ;
F_42 ( V_166 -> V_189 && V_166 -> V_218 ) ;
if ( V_166 -> V_189 ) {
struct V_211 * V_212 = F_71 ( V_166 -> V_189 -> V_213 , 0 ) ;
V_136 -> V_217 = ( V_212 && V_212 -> V_214 ) ?
V_212 -> V_215 . V_216 : 0 ;
}
if ( V_166 -> V_218 ) {
struct V_211 * V_212 = F_72 ( V_166 -> V_218 -> V_213 , 0 ) ;
V_136 -> V_217 = ( V_212 && V_212 -> V_214 ) ?
V_212 -> V_215 . V_216 : 0 ;
}
V_136 -> V_219 = 0 ;
if ( V_166 -> V_183 . V_220 & V_221 )
V_136 -> V_219 |= V_222 ;
if ( V_166 -> V_183 . V_220 & V_223 )
V_136 -> V_219 |= V_224 ;
if ( V_166 -> V_183 . V_220 & V_225 )
V_136 -> V_219 |= V_226 ;
if ( V_168 & 2 ) {
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_227 =
sizeof( struct V_169 ) / sizeof( V_73 ) ;
V_170 -> V_228 = V_229 ;
V_170 -> V_230 = F_73 ( V_166 -> V_231 . V_232 ) ;
V_170 -> V_233 = F_73 ( V_166 -> V_231 . V_234 ) ;
V_170 -> V_235 = V_166 -> V_231 . V_236 ;
V_170 -> V_237 = V_166 -> V_231 . V_238 ;
}
if ( V_168 & 1 ) {
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_227 =
sizeof( struct V_169 ) / sizeof( V_73 ) ;
V_170 -> V_228 = V_239 ;
V_170 -> V_230 = F_73 ( V_166 -> V_231 . V_240 ) ;
V_170 -> V_233 = F_73 ( V_166 -> V_231 . V_241 ) ;
V_170 -> V_235 = V_166 -> V_231 . V_242 ;
V_170 -> V_237 = V_166 -> V_231 . V_243 ;
}
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_227 =
sizeof( struct V_169 ) / sizeof( V_73 ) ;
V_170 -> V_228 = V_244 ;
V_170 -> V_230 = V_166 -> V_245 . V_246 ;
V_170 -> V_233 = V_166 -> V_245 . V_247 ;
V_170 -> V_235 = V_166 -> V_245 . V_248 ;
V_170 -> V_237 = V_166 -> V_245 . V_249 ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_120 ;
V_78 -> V_251 = 0 ;
V_78 -> V_252 = 0 ;
V_78 -> V_87 =
F_66 ( & V_166 -> V_183 . V_186 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_166 -> V_183 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_121 ;
V_78 -> V_251 = 0 ;
V_78 -> V_252 = 0 ;
V_78 -> V_87 =
F_66 ( & V_166 -> V_196 . V_253 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_166 -> V_183 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
if ( ! F_69 ( & V_166 -> V_185 . V_186 , & V_166 -> V_183 . V_186 ,
V_166 -> V_183 . V_135 ) ) {
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_122 ;
V_78 -> V_251 =
F_56 ( V_166 -> V_185 . V_134 ) ;
V_78 -> V_87 = V_166 -> V_185 . V_254 ;
V_78 -> V_252 = 0 ;
F_66 ( & V_166 -> V_185 . V_186 , V_166 -> V_185 . V_255 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_166 -> V_183 . V_135 ) ;
}
if ( V_167 && V_178 ) {
V_172 = (struct V_171 * ) F_43 ( V_8 ,
sizeof( struct V_171 ) + V_178 ) ;
V_172 -> V_256 = ( sizeof( struct V_171 ) + V_178 ) /
sizeof( V_73 ) ;
V_172 -> V_257 = V_258 ;
V_172 -> V_259 = V_166 -> V_187 -> V_188 ;
V_172 -> V_260 = 0 ;
memcpy ( V_172 + 1 , V_166 -> V_187 -> V_261 , ( V_166 -> V_187 -> V_188 + 7 ) / 8 ) ;
}
if ( V_167 && V_179 ) {
V_172 = (struct V_171 * ) F_43 ( V_8 ,
sizeof( struct V_171 ) + V_179 ) ;
V_172 -> V_256 = ( sizeof( struct V_171 ) +
V_179 ) / sizeof( V_73 ) ;
V_172 -> V_257 = V_262 ;
V_172 -> V_259 = V_166 -> V_189 -> V_188 ;
V_172 -> V_260 = 0 ;
memcpy ( V_172 + 1 , V_166 -> V_189 -> V_261 ,
( V_166 -> V_189 -> V_188 + 7 ) / 8 ) ;
}
V_174 = (struct V_173 * ) F_43 ( V_8 , sizeof( struct V_173 ) ) ;
V_174 -> V_263 = sizeof( struct V_173 ) / sizeof( V_73 ) ;
V_174 -> V_264 = V_265 ;
if ( ( V_149 = F_64 ( V_166 -> V_183 . V_149 ) ) < 0 ) {
F_5 ( V_8 ) ;
return F_68 ( - V_70 ) ;
}
V_174 -> V_266 = V_149 ;
V_174 -> V_267 = 0 ;
V_174 -> V_268 = 0 ;
V_174 -> V_269 = 0 ;
V_174 -> V_270 = V_166 -> V_183 . V_271 ;
if ( V_182 && V_182 -> V_191 ) {
struct V_192 * V_272 ;
struct V_193 * V_273 ;
V_272 = (struct V_192 * ) F_43 ( V_8 , sizeof( * V_272 ) ) ;
V_272 -> V_274 = sizeof( * V_272 ) / sizeof( V_73 ) ;
V_272 -> V_275 = V_276 ;
V_272 -> V_277 = V_182 -> V_191 ;
V_272 -> V_278 [ 0 ] = 0 ;
V_272 -> V_278 [ 1 ] = 0 ;
V_272 -> V_278 [ 2 ] = 0 ;
V_273 = (struct V_193 * ) F_43 ( V_8 , sizeof ( * V_273 ) ) ;
V_273 -> V_279 = sizeof( * V_273 ) / sizeof( V_73 ) ;
V_273 -> V_280 = V_281 ;
V_273 -> V_282 = V_182 -> V_283 ;
V_273 -> V_284 = 0 ;
V_273 = (struct V_193 * ) F_43 ( V_8 , sizeof ( * V_273 ) ) ;
V_273 -> V_279 = sizeof( * V_273 ) / sizeof( V_73 ) ;
V_273 -> V_280 = V_285 ;
V_273 -> V_282 = V_182 -> V_286 ;
V_273 -> V_284 = 0 ;
}
if ( V_176 ) {
V_90 = (struct V_89 * ) F_43 ( V_8 ,
sizeof( struct V_89 ) + V_97 ) ;
V_90 -> V_93 =
( sizeof( struct V_89 ) + V_97 ) / sizeof( V_73 ) ;
V_90 -> V_99 = V_124 ;
V_90 -> V_101 = V_176 -> V_100 ;
V_90 -> V_103 = V_176 -> V_102 ;
V_90 -> V_91 = V_176 -> V_104 ;
memcpy ( V_90 + 1 , V_176 -> V_287 ,
V_176 -> V_104 ) ;
}
return V_8 ;
}
static inline struct V_41 * F_75 ( const struct V_143 * V_166 )
{
struct V_41 * V_8 ;
V_8 = F_67 ( V_166 , 1 , 3 ) ;
return V_8 ;
}
static inline struct V_41 * F_76 ( const struct V_143 * V_166 ,
int V_168 )
{
return F_67 ( V_166 , 0 , V_168 ) ;
}
static struct V_143 * F_77 ( struct V_10 * V_10 ,
const struct V_57 * V_58 ,
void * const * V_109 )
{
struct V_143 * V_166 ;
const struct V_169 * V_170 ;
const struct V_144 * V_136 ;
const struct V_171 * V_172 ;
const struct V_89 * V_90 ;
T_2 V_134 ;
int V_23 ;
V_136 = V_109 [ V_145 - 1 ] ;
if ( ! V_136 ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return F_68 ( - V_70 ) ;
if ( V_58 -> V_146 == V_130 &&
! V_109 [ V_262 - 1 ] )
return F_68 ( - V_70 ) ;
if ( V_58 -> V_146 == V_128 &&
! V_109 [ V_258 - 1 ] )
return F_68 ( - V_70 ) ;
if ( ! ! V_109 [ V_229 - 1 ] !=
! ! V_109 [ V_239 - 1 ] )
return F_68 ( - V_70 ) ;
V_134 = F_53 ( V_58 -> V_146 ) ;
if ( V_134 == 0 )
return F_68 ( - V_70 ) ;
V_23 = - V_44 ;
if ( V_136 -> V_210 > V_288 ||
( V_58 -> V_146 == V_132 &&
V_136 -> V_217 > V_289 ) ||
V_136 -> V_217 > V_290 )
return F_68 ( - V_70 ) ;
V_172 = V_109 [ V_258 - 1 ] ;
if ( V_172 != NULL &&
V_136 -> V_210 != V_291 &&
( ( V_172 -> V_259 + 7 ) / 8 == 0 ||
( V_172 -> V_259 + 7 ) / 8 > V_172 -> V_256 * sizeof( V_73 ) ) )
return F_68 ( - V_70 ) ;
V_172 = V_109 [ V_262 - 1 ] ;
if ( V_172 != NULL &&
V_136 -> V_217 != V_292 &&
( ( V_172 -> V_259 + 7 ) / 8 == 0 ||
( V_172 -> V_259 + 7 ) / 8 > V_172 -> V_256 * sizeof( V_73 ) ) )
return F_68 ( - V_70 ) ;
V_166 = F_78 ( V_10 ) ;
if ( V_166 == NULL )
return F_68 ( - V_44 ) ;
V_166 -> V_196 . V_134 = V_134 ;
V_166 -> V_196 . V_197 = V_136 -> V_148 ;
V_166 -> V_183 . V_199 = F_79 (unsigned int, sa->sadb_sa_replay,
(sizeof(x->replay.bitmap) * 8)) ;
if ( V_136 -> V_219 & V_222 )
V_166 -> V_183 . V_220 |= V_221 ;
if ( V_136 -> V_219 & V_224 )
V_166 -> V_183 . V_220 |= V_223 ;
if ( V_136 -> V_219 & V_226 )
V_166 -> V_183 . V_220 |= V_225 ;
V_170 = V_109 [ V_229 - 1 ] ;
if ( V_170 != NULL ) {
V_166 -> V_231 . V_232 = F_80 ( V_170 -> V_230 ) ;
V_166 -> V_231 . V_234 = F_80 ( V_170 -> V_233 ) ;
V_166 -> V_231 . V_236 = V_170 -> V_235 ;
V_166 -> V_231 . V_238 = V_170 -> V_237 ;
}
V_170 = V_109 [ V_239 - 1 ] ;
if ( V_170 != NULL ) {
V_166 -> V_231 . V_240 = F_80 ( V_170 -> V_230 ) ;
V_166 -> V_231 . V_241 = F_80 ( V_170 -> V_233 ) ;
V_166 -> V_231 . V_242 = V_170 -> V_235 ;
V_166 -> V_231 . V_243 = V_170 -> V_237 ;
}
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 )
goto V_35;
V_23 = F_81 ( V_166 , V_96 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
goto V_35;
}
V_172 = V_109 [ V_258 - 1 ] ;
if ( V_136 -> V_210 ) {
int V_293 = 0 ;
struct V_211 * V_212 = F_83 ( V_136 -> V_210 ) ;
if ( ! V_212 || ! V_212 -> V_214 ) {
V_23 = - V_294 ;
goto V_35;
}
if ( V_172 )
V_293 = ( V_172 -> V_259 + 7 ) / 8 ;
V_166 -> V_187 = F_50 ( sizeof( * V_166 -> V_187 ) + V_293 , V_33 ) ;
if ( ! V_166 -> V_187 )
goto V_35;
strcpy ( V_166 -> V_187 -> V_213 , V_212 -> V_295 ) ;
V_166 -> V_187 -> V_188 = 0 ;
if ( V_172 ) {
V_166 -> V_187 -> V_188 = V_172 -> V_259 ;
memcpy ( V_166 -> V_187 -> V_261 , V_172 + 1 , V_293 ) ;
}
V_166 -> V_187 -> V_296 = V_212 -> V_297 . V_298 . V_299 ;
V_166 -> V_183 . V_300 = V_136 -> V_210 ;
}
if ( V_136 -> V_217 ) {
if ( V_58 -> V_146 == V_132 ) {
struct V_211 * V_212 = F_84 ( V_136 -> V_217 ) ;
if ( ! V_212 || ! V_212 -> V_214 ) {
V_23 = - V_294 ;
goto V_35;
}
V_166 -> V_218 = F_50 ( sizeof( * V_166 -> V_218 ) , V_33 ) ;
if ( ! V_166 -> V_218 )
goto V_35;
strcpy ( V_166 -> V_218 -> V_213 , V_212 -> V_295 ) ;
V_166 -> V_183 . V_301 = V_136 -> V_217 ;
} else {
int V_293 = 0 ;
struct V_211 * V_212 = F_85 ( V_136 -> V_217 ) ;
if ( ! V_212 || ! V_212 -> V_214 ) {
V_23 = - V_294 ;
goto V_35;
}
V_172 = (struct V_171 * ) V_109 [ V_262 - 1 ] ;
if ( V_172 )
V_293 = ( V_172 -> V_259 + 7 ) / 8 ;
V_166 -> V_189 = F_50 ( sizeof( * V_166 -> V_189 ) + V_293 , V_33 ) ;
if ( ! V_166 -> V_189 )
goto V_35;
strcpy ( V_166 -> V_189 -> V_213 , V_212 -> V_295 ) ;
V_166 -> V_189 -> V_188 = 0 ;
if ( V_172 ) {
V_166 -> V_189 -> V_188 = V_172 -> V_259 ;
memcpy ( V_166 -> V_189 -> V_261 , V_172 + 1 , V_293 ) ;
}
V_166 -> V_183 . V_302 = V_136 -> V_217 ;
}
}
V_166 -> V_183 . V_135 = F_59 ( (struct V_75 * ) V_109 [ V_120 - 1 ] ,
& V_166 -> V_183 . V_186 ) ;
F_59 ( (struct V_75 * ) V_109 [ V_121 - 1 ] ,
& V_166 -> V_196 . V_253 ) ;
if ( V_109 [ V_265 - 1 ] ) {
const struct V_173 * V_174 = V_109 [ V_265 - 1 ] ;
int V_149 = F_65 ( V_174 -> V_266 ) ;
if ( V_149 < 0 ) {
V_23 = - V_70 ;
goto V_35;
}
V_166 -> V_183 . V_149 = V_149 ;
V_166 -> V_183 . V_271 = V_174 -> V_270 ;
}
if ( V_109 [ V_122 - 1 ] ) {
const struct V_75 * V_78 = V_109 [ V_122 - 1 ] ;
V_166 -> V_185 . V_135 = F_59 ( V_78 , & V_166 -> V_185 . V_186 ) ;
V_166 -> V_185 . V_254 = V_78 -> V_87 ;
}
if ( ! V_166 -> V_185 . V_135 )
V_166 -> V_185 . V_135 = V_166 -> V_183 . V_135 ;
if ( V_109 [ V_276 - 1 ] ) {
const struct V_192 * V_272 ;
struct V_181 * V_182 ;
V_166 -> V_190 = F_50 ( sizeof( * V_166 -> V_190 ) , V_33 ) ;
if ( ! V_166 -> V_190 )
goto V_35;
V_182 = V_166 -> V_190 ;
V_272 = V_109 [ V_276 - 1 ] ;
V_182 -> V_191 = V_272 -> V_277 ;
if ( V_109 [ V_281 - 1 ] ) {
const struct V_193 * V_273 =
V_109 [ V_281 - 1 ] ;
V_182 -> V_283 = V_273 -> V_282 ;
}
if ( V_109 [ V_285 - 1 ] ) {
const struct V_193 * V_273 =
V_109 [ V_285 - 1 ] ;
V_182 -> V_286 = V_273 -> V_282 ;
}
memset ( & V_182 -> V_303 , 0 , sizeof( V_182 -> V_303 ) ) ;
}
V_23 = F_86 ( V_166 ) ;
if ( V_23 )
goto V_35;
V_166 -> V_200 . V_304 = V_58 -> V_61 ;
return V_166 ;
V_35:
V_166 -> V_200 . V_201 = V_305 ;
F_87 ( V_166 ) ;
return F_68 ( V_23 ) ;
}
static int F_88 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
return - V_306 ;
}
static int F_89 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_41 * V_307 ;
struct V_173 * V_174 ;
struct V_75 * V_186 , * V_253 ;
struct V_57 * V_308 ;
struct V_309 * V_310 ;
struct V_143 * V_166 = NULL ;
int V_149 ;
int V_23 ;
T_6 V_311 , V_312 ;
T_6 V_271 ;
T_7 V_134 ;
unsigned short V_135 ;
T_4 * V_313 = NULL , * V_314 = NULL ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_70 ;
V_134 = F_53 ( V_58 -> V_146 ) ;
if ( V_134 == 0 )
return - V_70 ;
if ( ( V_174 = V_109 [ V_265 - 1 ] ) != NULL ) {
V_149 = F_65 ( V_174 -> V_266 ) ;
if ( V_149 < 0 )
return - V_70 ;
V_271 = V_174 -> V_270 ;
} else {
V_149 = 0 ;
V_271 = 0 ;
}
V_186 = V_109 [ V_120 - 1 ] ;
V_253 = V_109 [ V_121 - 1 ] ;
V_135 = ( (struct V_77 * ) ( V_186 + 1 ) ) -> V_84 ;
switch ( V_135 ) {
case V_85 :
V_314 = ( T_4 * ) & ( (struct V_79 * ) ( V_253 + 1 ) ) -> V_139 . V_107 ;
V_313 = ( T_4 * ) & ( (struct V_79 * ) ( V_186 + 1 ) ) -> V_139 . V_107 ;
break;
#if F_45 ( V_80 )
case V_88 :
V_314 = ( T_4 * ) & ( (struct V_81 * ) ( V_253 + 1 ) ) -> V_141 ;
V_313 = ( T_4 * ) & ( (struct V_81 * ) ( V_186 + 1 ) ) -> V_141 ;
break;
#endif
}
if ( V_58 -> V_61 ) {
V_166 = F_90 ( V_10 , V_147 , V_58 -> V_61 ) ;
if ( V_166 && ! F_69 ( & V_166 -> V_196 . V_253 , V_314 , V_135 ) ) {
F_87 ( V_166 ) ;
V_166 = NULL ;
}
}
if ( ! V_166 )
V_166 = F_91 ( V_10 , & V_315 , V_149 , V_271 , V_134 , V_314 , V_313 , 1 , V_135 ) ;
if ( V_166 == NULL )
return - V_316 ;
V_311 = 0x100 ;
V_312 = 0x0fffffff ;
V_310 = V_109 [ V_317 - 1 ] ;
if ( V_310 ) {
V_311 = V_310 -> V_318 ;
V_312 = V_310 -> V_319 ;
}
V_23 = F_92 ( V_166 -> V_196 . V_134 , V_311 , V_312 ) ;
if ( V_23 ) {
F_87 ( V_166 ) ;
return V_23 ;
}
V_23 = F_93 ( V_166 , V_311 , V_312 ) ;
V_307 = V_23 ? F_68 ( V_23 ) : F_75 ( V_166 ) ;
if ( F_94 ( V_307 ) ) {
F_87 ( V_166 ) ;
return F_95 ( V_307 ) ;
}
V_308 = (struct V_57 * ) V_307 -> V_60 ;
V_308 -> V_320 = V_58 -> V_320 ;
V_308 -> V_321 = V_322 ;
V_308 -> V_146 = F_54 ( V_134 ) ;
V_308 -> V_62 = 0 ;
V_308 -> V_323 = 0 ;
V_308 -> V_61 = V_58 -> V_61 ;
V_308 -> V_324 = V_58 -> V_324 ;
F_87 ( V_166 ) ;
F_34 ( V_307 , V_33 , V_56 , V_3 , V_10 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_166 ;
if ( V_58 -> V_72 != sizeof( struct V_57 ) / 8 )
return - V_306 ;
if ( V_58 -> V_61 == 0 || V_58 -> V_62 == 0 )
return 0 ;
V_166 = F_90 ( V_10 , V_147 , V_58 -> V_61 ) ;
if ( V_166 == NULL )
return 0 ;
F_97 ( & V_166 -> V_325 ) ;
if ( V_166 -> V_200 . V_201 == V_207 )
V_166 -> V_200 . V_201 = V_326 ;
F_98 ( & V_166 -> V_325 ) ;
F_87 ( V_166 ) ;
return 0 ;
}
static inline int F_99 ( int V_327 )
{
switch ( V_327 ) {
case V_328 :
return V_329 ;
case V_330 :
return V_331 ;
case V_332 :
return V_333 ;
case V_334 :
default:
F_11 ( L_2 , V_327 ) ;
break;
}
return 0 ;
}
static inline int F_100 ( int V_327 )
{
switch ( V_327 ) {
case V_335 :
return V_336 ;
case V_337 :
return V_338 ;
case V_339 :
return V_340 ;
case V_341 :
return V_342 ;
default:
F_11 ( L_3 , V_327 ) ;
break;
}
return 0 ;
}
static int F_101 ( struct V_143 * V_166 , const struct V_343 * V_344 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
V_8 = F_75 ( V_166 ) ;
if ( F_94 ( V_8 ) )
return F_95 ( V_8 ) ;
V_58 = (struct V_57 * ) V_8 -> V_60 ;
V_58 -> V_320 = V_29 ;
V_58 -> V_321 = F_100 ( V_344 -> V_327 ) ;
V_58 -> V_146 = F_54 ( V_166 -> V_196 . V_134 ) ;
V_58 -> V_62 = 0 ;
V_58 -> V_323 = 0 ;
V_58 -> V_61 = V_344 -> V_304 ;
V_58 -> V_324 = V_344 -> V_345 ;
F_34 ( V_8 , V_63 , V_52 , NULL , F_102 ( V_166 ) ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_166 ;
int V_23 ;
struct V_343 V_344 ;
V_166 = F_77 ( V_10 , V_58 , V_109 ) ;
if ( F_94 ( V_166 ) )
return F_95 ( V_166 ) ;
F_104 ( V_166 ) ;
if ( V_58 -> V_321 == V_338 )
V_23 = F_105 ( V_166 ) ;
else
V_23 = F_106 ( V_166 ) ;
F_107 ( V_166 , V_23 ? 0 : 1 , true ) ;
if ( V_23 < 0 ) {
V_166 -> V_200 . V_201 = V_305 ;
F_108 ( V_166 ) ;
goto V_35;
}
if ( V_58 -> V_321 == V_338 )
V_344 . V_327 = V_337 ;
else
V_344 . V_327 = V_339 ;
V_344 . V_304 = V_58 -> V_61 ;
V_344 . V_345 = V_58 -> V_324 ;
F_109 ( V_166 , & V_344 ) ;
V_35:
F_87 ( V_166 ) ;
return V_23 ;
}
static int F_110 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_166 ;
struct V_343 V_344 ;
int V_23 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_70 ;
V_166 = F_60 ( V_10 , V_58 , V_109 ) ;
if ( V_166 == NULL )
return - V_49 ;
if ( ( V_23 = F_111 ( V_166 ) ) )
goto V_35;
if ( F_112 ( V_166 ) ) {
V_23 = - V_26 ;
goto V_35;
}
V_23 = F_113 ( V_166 ) ;
if ( V_23 < 0 )
goto V_35;
V_344 . V_304 = V_58 -> V_61 ;
V_344 . V_345 = V_58 -> V_324 ;
V_344 . V_327 = V_335 ;
F_109 ( V_166 , & V_344 ) ;
V_35:
F_114 ( V_166 , V_23 ? 0 : 1 , true ) ;
F_87 ( V_166 ) ;
return V_23 ;
}
static int F_115 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
T_8 V_134 ;
struct V_41 * V_346 ;
struct V_57 * V_308 ;
struct V_143 * V_166 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_70 ;
V_166 = F_60 ( V_10 , V_58 , V_109 ) ;
if ( V_166 == NULL )
return - V_49 ;
V_346 = F_75 ( V_166 ) ;
V_134 = V_166 -> V_196 . V_134 ;
F_87 ( V_166 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_308 = (struct V_57 * ) V_346 -> V_60 ;
V_308 -> V_320 = V_58 -> V_320 ;
V_308 -> V_321 = V_347 ;
V_308 -> V_146 = F_54 ( V_134 ) ;
V_308 -> V_62 = 0 ;
V_308 -> V_323 = 0 ;
V_308 -> V_61 = V_58 -> V_61 ;
V_308 -> V_324 = V_58 -> V_324 ;
F_34 ( V_346 , V_63 , V_56 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static struct V_41 * F_116 ( const struct V_57 * V_65 ,
T_1 V_43 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
int V_83 , V_348 , V_349 , V_350 ;
V_348 = F_117 () ;
if ( V_348 ) {
V_348 *= sizeof( struct V_351 ) ;
V_348 += sizeof( struct V_352 ) ;
}
V_349 = F_118 () ;
if ( V_349 ) {
V_349 *= sizeof( struct V_351 ) ;
V_349 += sizeof( struct V_352 ) ;
}
V_83 = V_349 + V_348 + sizeof( struct V_57 ) ;
V_8 = F_41 ( V_83 + 16 , V_43 ) ;
if ( ! V_8 )
goto V_353;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( * V_58 ) ) ;
F_39 ( V_58 , V_65 ) ;
V_58 -> V_62 = 0 ;
V_58 -> V_72 = V_83 / sizeof( V_73 ) ;
if ( V_348 ) {
struct V_352 * V_76 ;
struct V_351 * V_354 ;
V_76 = (struct V_352 * ) F_43 ( V_8 , V_348 ) ;
V_354 = (struct V_351 * ) ( V_76 + 1 ) ;
V_76 -> V_355 = V_348 / sizeof( V_73 ) ;
V_76 -> V_356 = V_357 ;
for ( V_350 = 0 ; ; V_350 ++ ) {
struct V_211 * V_187 = F_119 ( V_350 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( V_187 -> V_358 )
* V_354 ++ = V_187 -> V_215 ;
}
}
if ( V_349 ) {
struct V_352 * V_76 ;
struct V_351 * V_354 ;
V_76 = (struct V_352 * ) F_43 ( V_8 , V_349 ) ;
V_354 = (struct V_351 * ) ( V_76 + 1 ) ;
V_76 -> V_355 = V_349 / sizeof( V_73 ) ;
V_76 -> V_356 = V_359 ;
for ( V_350 = 0 ; ; V_350 ++ ) {
struct V_211 * V_189 = F_120 ( V_350 ) ;
if ( ! V_189 )
break;
if ( ! V_189 -> V_214 )
continue;
if ( V_189 -> V_358 )
* V_354 ++ = V_189 -> V_215 ;
}
}
V_353:
return V_8 ;
}
static int F_121 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_360 ;
if ( V_58 -> V_146 > V_361 )
return - V_70 ;
if ( V_58 -> V_146 != V_126 ) {
if ( V_6 -> V_55 & ( 1 << V_58 -> V_146 ) )
return - V_362 ;
V_6 -> V_55 |= ( 1 << V_58 -> V_146 ) ;
}
F_122 () ;
V_360 = F_116 ( V_58 , V_33 ) ;
if ( ! V_360 ) {
if ( V_58 -> V_146 != V_126 )
V_6 -> V_55 &= ~ ( 1 << V_58 -> V_146 ) ;
return - V_44 ;
}
F_34 ( V_360 , V_33 , V_54 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_123 ( struct V_2 * V_3 , const struct V_57 * V_363 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
V_8 = F_41 ( sizeof( struct V_57 ) + 16 , V_63 ) ;
if ( ! V_8 )
return - V_44 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
memcpy ( V_58 , V_363 , sizeof( struct V_57 ) ) ;
V_58 -> V_62 = ( V_71 ) 0 ;
V_58 -> V_72 = ( sizeof( struct V_57 ) / sizeof( V_73 ) ) ;
return F_34 ( V_8 , V_63 , V_56 , V_3 , F_7 ( V_3 ) ) ;
}
static int F_124 ( const struct V_343 * V_344 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
V_8 = F_41 ( sizeof( struct V_57 ) + 16 , V_63 ) ;
if ( ! V_8 )
return - V_44 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
V_58 -> V_146 = F_54 ( V_344 -> V_60 . V_134 ) ;
V_58 -> V_321 = V_364 ;
V_58 -> V_61 = V_344 -> V_304 ;
V_58 -> V_324 = V_344 -> V_345 ;
V_58 -> V_320 = V_29 ;
V_58 -> V_62 = ( V_71 ) 0 ;
V_58 -> V_72 = ( sizeof( struct V_57 ) / sizeof( V_73 ) ) ;
V_58 -> V_323 = 0 ;
F_34 ( V_8 , V_63 , V_52 , NULL , V_344 -> V_10 ) ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_134 ;
struct V_343 V_344 ;
int V_23 , V_50 ;
V_134 = F_53 ( V_58 -> V_146 ) ;
if ( V_134 == 0 )
return - V_70 ;
V_23 = F_126 ( V_10 , V_134 , true ) ;
V_50 = F_123 ( V_3 , V_58 ) ;
if ( V_23 || V_50 ) {
if ( V_23 == - V_49 )
V_23 = 0 ;
return V_23 ? V_23 : V_50 ;
}
V_344 . V_60 . V_134 = V_134 ;
V_344 . V_304 = V_58 -> V_61 ;
V_344 . V_345 = V_58 -> V_324 ;
V_344 . V_327 = V_365 ;
V_344 . V_10 = V_10 ;
F_109 ( NULL , & V_344 ) ;
return 0 ;
}
static int F_127 ( struct V_143 * V_166 , int V_366 , void * V_367 )
{
struct V_1 * V_6 = V_367 ;
struct V_41 * V_346 ;
struct V_57 * V_308 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_346 = F_75 ( V_166 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_308 = (struct V_57 * ) V_346 -> V_60 ;
V_308 -> V_320 = V_6 -> V_7 . V_368 ;
V_308 -> V_321 = V_369 ;
V_308 -> V_146 = F_54 ( V_166 -> V_196 . V_134 ) ;
V_308 -> V_62 = 0 ;
V_308 -> V_323 = 0 ;
V_308 -> V_61 = V_366 + 1 ;
V_308 -> V_324 = V_6 -> V_7 . V_370 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_63 , V_56 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_346 ;
return 0 ;
}
static int F_128 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return F_129 ( V_10 , & V_6 -> V_7 . V_371 . V_201 , F_127 , ( void * ) V_6 ) ;
}
static void F_130 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
F_131 ( & V_6 -> V_7 . V_371 . V_201 , V_10 ) ;
}
static int F_132 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
T_7 V_134 ;
struct V_372 * V_373 = NULL ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_374 ;
V_134 = F_53 ( V_58 -> V_146 ) ;
if ( V_134 == 0 )
return - V_70 ;
if ( V_109 [ V_375 - 1 ] ) {
struct V_376 * V_377 = V_109 [ V_375 - 1 ] ;
V_373 = F_50 ( sizeof( * V_373 ) , V_33 ) ;
if ( V_373 == NULL )
return - V_31 ;
memcpy ( & V_373 -> V_186 , & V_377 -> V_378 ,
sizeof( T_4 ) ) ;
memcpy ( & V_373 -> V_253 , & V_377 -> V_379 ,
sizeof( T_4 ) ) ;
V_373 -> V_135 = V_377 -> V_380 ;
V_373 -> V_381 = V_377 -> V_382 ;
V_373 -> V_383 = V_377 -> V_384 ;
}
V_6 -> V_7 . V_368 = V_58 -> V_320 ;
V_6 -> V_7 . V_370 = V_58 -> V_324 ;
V_6 -> V_7 . V_7 = F_128 ;
V_6 -> V_7 . V_9 = F_130 ;
F_133 ( & V_6 -> V_7 . V_371 . V_201 , V_134 , V_373 ) ;
return F_38 ( V_6 ) ;
}
static int F_134 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_125 = V_58 -> V_146 ;
bool V_385 = false ;
if ( V_58 -> V_72 == ( sizeof( * V_58 ) / sizeof( V_73 ) ) ) {
V_385 = true ;
if ( V_125 != 0 && V_125 != 1 )
return - V_70 ;
V_6 -> V_51 = V_125 ;
}
if ( V_385 && F_135 ( V_8 ) )
V_8 = F_136 ( V_8 , V_33 ) ;
else
V_8 = F_31 ( V_8 , V_33 ) ;
if ( V_385 && V_8 ) {
struct V_57 * V_386 = (struct V_57 * ) V_8 -> V_60 ;
V_386 -> V_62 = 0 ;
}
F_34 ( V_8 , V_33 , V_52 , NULL , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_137 ( struct V_387 * V_388 , int V_389 , int V_366 , void * V_367 )
{
int V_350 ;
T_6 V_271 = * ( T_6 * ) V_367 ;
for ( V_350 = 0 ; V_350 < V_388 -> V_390 ; V_350 ++ ) {
if ( V_388 -> V_391 [ V_350 ] . V_271 == V_271 )
return - V_362 ;
}
return 0 ;
}
static T_6 F_138 ( struct V_10 * V_10 )
{
struct V_392 V_393 ;
T_6 V_394 ;
int V_59 ;
static T_6 V_271 = V_395 ;
V_394 = V_271 ;
do {
++ V_271 ;
if ( V_271 == 0 )
V_271 = V_395 + 1 ;
F_139 ( & V_393 , V_396 ) ;
V_59 = V_392 ( V_10 , & V_393 , F_137 , ( void * ) & V_271 ) ;
F_140 ( & V_393 , V_10 ) ;
if ( V_59 != - V_362 )
return V_271 ;
} while ( V_271 != V_394 );
return 0 ;
}
static int
F_141 ( struct V_387 * V_388 , struct V_397 * V_398 )
{
struct V_10 * V_10 = F_142 ( V_388 ) ;
struct V_399 * V_400 = V_388 -> V_391 + V_388 -> V_390 ;
int V_149 ;
if ( V_388 -> V_390 >= V_401 )
return - V_402 ;
if ( V_398 -> V_403 == 0 )
return - V_70 ;
V_400 -> V_196 . V_134 = V_398 -> V_404 ;
if ( ( V_149 = F_65 ( V_398 -> V_403 ) ) < 0 )
return - V_70 ;
V_400 -> V_149 = V_149 ;
if ( V_398 -> V_405 == V_406 )
V_400 -> V_407 = 1 ;
else if ( V_398 -> V_405 == V_408 ) {
V_400 -> V_271 = V_398 -> V_409 ;
if ( V_400 -> V_271 > V_395 )
V_400 -> V_271 = 0 ;
if ( ! V_400 -> V_271 && ! ( V_400 -> V_271 = F_138 ( V_10 ) ) )
return - V_44 ;
}
if ( V_400 -> V_149 == V_152 ) {
T_7 * V_136 = ( T_7 * ) ( V_398 + 1 ) ;
int V_135 , V_410 ;
V_135 = F_58 ( (struct V_77 * ) V_136 ,
& V_400 -> V_186 ) ;
if ( ! V_135 )
return - V_70 ;
V_410 = F_57 ( V_135 ) ;
if ( F_58 ( (struct V_77 * ) ( V_136 + V_410 ) ,
& V_400 -> V_196 . V_253 ) != V_135 )
return - V_70 ;
V_400 -> V_411 = V_135 ;
} else
V_400 -> V_411 = V_388 -> V_135 ;
V_400 -> V_412 = 1 ;
V_388 -> V_390 ++ ;
return 0 ;
}
static int
F_143 ( struct V_387 * V_388 , struct V_413 * V_414 )
{
int V_23 ;
int V_83 = V_414 -> V_415 * 8 - sizeof( struct V_413 ) ;
struct V_397 * V_398 = ( void * ) ( V_414 + 1 ) ;
if ( V_414 -> V_415 * 8 < sizeof( struct V_413 ) )
return - V_70 ;
while ( V_83 >= sizeof( struct V_397 ) ) {
if ( ( V_23 = F_141 ( V_388 , V_398 ) ) < 0 )
return V_23 ;
V_83 -= V_398 -> V_416 ;
V_398 = ( void * ) ( ( T_7 * ) V_398 + V_398 -> V_416 ) ;
}
return 0 ;
}
static inline int F_144 ( const struct V_387 * V_388 )
{
struct V_175 * V_176 = V_388 -> V_184 ;
if ( V_176 ) {
int V_83 = sizeof( struct V_89 ) ;
V_83 += V_176 -> V_104 ;
return F_63 ( V_83 ) ;
}
return 0 ;
}
static int F_145 ( const struct V_387 * V_388 )
{
const struct V_399 * V_400 ;
int V_180 = F_62 ( V_388 -> V_135 ) ;
int V_410 = 0 ;
int V_350 ;
for ( V_350 = 0 ; V_350 < V_388 -> V_390 ; V_350 ++ ) {
V_400 = V_388 -> V_391 + V_350 ;
V_410 += F_57 ( V_400 -> V_411 ) ;
}
return sizeof( struct V_57 ) +
( sizeof( struct V_169 ) * 3 ) +
( sizeof( struct V_75 ) * 2 ) +
( V_180 * 2 ) +
sizeof( struct V_413 ) +
( V_388 -> V_390 * sizeof( struct V_397 ) ) +
( V_410 * 2 ) +
F_144 ( V_388 ) ;
}
static struct V_41 * F_146 ( const struct V_387 * V_388 )
{
struct V_41 * V_8 ;
int V_177 ;
V_177 = F_145 ( V_388 ) ;
V_8 = F_41 ( V_177 + 16 , V_63 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
return V_8 ;
}
static int F_147 ( struct V_41 * V_8 , const struct V_387 * V_388 , int V_389 )
{
struct V_57 * V_58 ;
struct V_75 * V_78 ;
struct V_169 * V_170 ;
struct V_413 * V_414 ;
struct V_89 * V_90 ;
struct V_175 * V_176 ;
int V_350 ;
int V_177 ;
int V_180 = F_62 ( V_388 -> V_135 ) ;
int V_410 = F_57 ( V_388 -> V_135 ) ;
V_177 = F_145 ( V_388 ) ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
memset ( V_58 , 0 , V_177 ) ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_120 ;
V_78 -> V_251 = F_56 ( V_388 -> V_417 . V_134 ) ;
V_78 -> V_87 = V_388 -> V_417 . V_254 ;
V_78 -> V_252 = 0 ;
if ( ! F_66 ( & V_388 -> V_417 . V_186 ,
V_388 -> V_417 . V_255 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_388 -> V_135 ) )
F_74 () ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_121 ;
V_78 -> V_251 = F_56 ( V_388 -> V_417 . V_134 ) ;
V_78 -> V_87 = V_388 -> V_417 . V_418 ;
V_78 -> V_252 = 0 ;
F_66 ( & V_388 -> V_417 . V_253 , V_388 -> V_417 . V_419 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_388 -> V_135 ) ;
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_227 =
sizeof( struct V_169 ) / sizeof( V_73 ) ;
V_170 -> V_228 = V_229 ;
V_170 -> V_230 = F_73 ( V_388 -> V_231 . V_232 ) ;
V_170 -> V_233 = F_73 ( V_388 -> V_231 . V_234 ) ;
V_170 -> V_235 = V_388 -> V_231 . V_236 ;
V_170 -> V_237 = V_388 -> V_231 . V_238 ;
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_227 =
sizeof( struct V_169 ) / sizeof( V_73 ) ;
V_170 -> V_228 = V_239 ;
V_170 -> V_230 = F_73 ( V_388 -> V_231 . V_240 ) ;
V_170 -> V_233 = F_73 ( V_388 -> V_231 . V_241 ) ;
V_170 -> V_235 = V_388 -> V_231 . V_242 ;
V_170 -> V_237 = V_388 -> V_231 . V_243 ;
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_227 =
sizeof( struct V_169 ) / sizeof( V_73 ) ;
V_170 -> V_228 = V_244 ;
V_170 -> V_230 = V_388 -> V_245 . V_246 ;
V_170 -> V_233 = V_388 -> V_245 . V_247 ;
V_170 -> V_235 = V_388 -> V_245 . V_248 ;
V_170 -> V_237 = V_388 -> V_245 . V_249 ;
V_414 = (struct V_413 * ) F_43 ( V_8 , sizeof( struct V_413 ) ) ;
V_414 -> V_415 = sizeof( struct V_413 ) / sizeof( V_73 ) ;
V_414 -> V_420 = V_421 ;
V_414 -> V_422 = V_423 ;
if ( V_388 -> V_424 == V_425 ) {
if ( V_388 -> V_390 )
V_414 -> V_422 = V_426 ;
else
V_414 -> V_422 = V_427 ;
}
V_414 -> V_428 = V_389 + 1 ;
V_414 -> V_429 = 0 ;
V_414 -> V_430 = V_388 -> V_431 ;
V_414 -> V_432 = V_388 -> V_433 ;
for ( V_350 = 0 ; V_350 < V_388 -> V_390 ; V_350 ++ ) {
const struct V_399 * V_400 = V_388 -> V_391 + V_350 ;
struct V_397 * V_398 ;
int V_434 ;
int V_149 ;
V_434 = sizeof( struct V_397 ) ;
if ( V_400 -> V_149 == V_152 ) {
V_410 = F_57 ( V_400 -> V_411 ) ;
V_434 += V_410 * 2 ;
} else {
V_177 -= 2 * V_410 ;
}
V_398 = ( void * ) F_43 ( V_8 , V_434 ) ;
V_414 -> V_415 += V_434 / 8 ;
memset ( V_398 , 0 , sizeof( * V_398 ) ) ;
V_398 -> V_416 = V_434 ;
V_398 -> V_404 = V_400 -> V_196 . V_134 ;
if ( ( V_149 = F_64 ( V_400 -> V_149 ) ) < 0 )
return - V_70 ;
V_398 -> V_403 = V_149 ;
V_398 -> V_405 = V_435 ;
if ( V_400 -> V_271 )
V_398 -> V_405 = V_408 ;
if ( V_400 -> V_407 )
V_398 -> V_405 = V_406 ;
V_398 -> V_409 = V_400 -> V_271 ;
if ( V_400 -> V_149 == V_152 ) {
T_7 * V_136 = ( void * ) ( V_398 + 1 ) ;
F_66 ( & V_400 -> V_186 , 0 ,
(struct V_77 * ) V_136 ,
V_400 -> V_411 ) ;
F_66 ( & V_400 -> V_196 . V_253 , 0 ,
(struct V_77 * ) ( V_136 + V_410 ) ,
V_400 -> V_411 ) ;
}
}
if ( ( V_176 = V_388 -> V_184 ) ) {
int V_97 = F_144 ( V_388 ) ;
V_90 = (struct V_89 * ) F_43 ( V_8 , V_97 ) ;
V_90 -> V_93 = V_97 / sizeof( V_73 ) ;
V_90 -> V_99 = V_124 ;
V_90 -> V_101 = V_176 -> V_100 ;
V_90 -> V_103 = V_176 -> V_102 ;
V_90 -> V_91 = V_176 -> V_104 ;
memcpy ( V_90 + 1 , V_176 -> V_287 ,
V_176 -> V_104 ) ;
}
V_58 -> V_72 = V_177 / sizeof( V_73 ) ;
V_58 -> V_323 = F_3 ( & V_388 -> V_436 ) ;
return 0 ;
}
static int F_148 ( struct V_387 * V_388 , int V_389 , const struct V_343 * V_344 )
{
struct V_41 * V_346 ;
struct V_57 * V_308 ;
int V_23 ;
V_346 = F_146 ( V_388 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_23 = F_147 ( V_346 , V_388 , V_389 ) ;
if ( V_23 < 0 )
return V_23 ;
V_308 = (struct V_57 * ) V_346 -> V_60 ;
V_308 -> V_320 = V_29 ;
if ( V_344 -> V_60 . V_437 && V_344 -> V_327 == V_328 )
V_308 -> V_321 = V_438 ;
else
V_308 -> V_321 = F_99 ( V_344 -> V_327 ) ;
V_308 -> V_62 = 0 ;
V_308 -> V_61 = V_344 -> V_304 ;
V_308 -> V_324 = V_344 -> V_345 ;
F_34 ( V_346 , V_63 , V_52 , NULL , F_142 ( V_388 ) ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 = 0 ;
struct V_169 * V_170 ;
struct V_75 * V_136 ;
struct V_413 * V_414 ;
struct V_387 * V_388 ;
struct V_343 V_344 ;
struct V_89 * V_90 ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_421 - 1 ] )
return - V_70 ;
V_414 = V_109 [ V_421 - 1 ] ;
if ( V_414 -> V_422 > V_426 )
return - V_70 ;
if ( ! V_414 -> V_428 || V_414 -> V_428 >= V_439 )
return - V_70 ;
V_388 = F_150 ( V_10 , V_33 ) ;
if ( V_388 == NULL )
return - V_44 ;
V_388 -> V_424 = ( V_414 -> V_422 == V_423 ?
V_440 : V_425 ) ;
V_388 -> V_433 = V_414 -> V_432 ;
V_136 = V_109 [ V_120 - 1 ] ;
V_388 -> V_135 = F_59 ( V_136 , & V_388 -> V_417 . V_186 ) ;
V_388 -> V_417 . V_135 = V_388 -> V_135 ;
V_388 -> V_417 . V_254 = V_136 -> V_87 ;
V_388 -> V_417 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_388 -> V_417 . V_255 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_388 -> V_417 . V_255 )
V_388 -> V_417 . V_441 = F_151 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_388 -> V_417 . V_253 ) ;
V_388 -> V_417 . V_418 = V_136 -> V_87 ;
V_388 -> V_417 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_388 -> V_417 . V_419 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_388 -> V_417 . V_419 )
V_388 -> V_417 . V_442 = F_151 ( 0xffff ) ;
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 ) {
V_23 = - V_44 ;
goto V_35;
}
V_23 = F_152 ( & V_388 -> V_184 , V_96 , V_33 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
goto V_35;
}
V_388 -> V_231 . V_241 = V_443 ;
V_388 -> V_231 . V_234 = V_443 ;
V_388 -> V_231 . V_240 = V_443 ;
V_388 -> V_231 . V_232 = V_443 ;
if ( ( V_170 = V_109 [ V_229 - 1 ] ) != NULL ) {
V_388 -> V_231 . V_232 = F_80 ( V_170 -> V_230 ) ;
V_388 -> V_231 . V_234 = F_80 ( V_170 -> V_233 ) ;
V_388 -> V_231 . V_236 = V_170 -> V_235 ;
V_388 -> V_231 . V_238 = V_170 -> V_237 ;
}
if ( ( V_170 = V_109 [ V_239 - 1 ] ) != NULL ) {
V_388 -> V_231 . V_240 = F_80 ( V_170 -> V_230 ) ;
V_388 -> V_231 . V_241 = F_80 ( V_170 -> V_233 ) ;
V_388 -> V_231 . V_242 = V_170 -> V_235 ;
V_388 -> V_231 . V_243 = V_170 -> V_237 ;
}
V_388 -> V_390 = 0 ;
if ( V_414 -> V_422 == V_426 &&
( V_23 = F_143 ( V_388 , V_414 ) ) < 0 )
goto V_35;
V_23 = F_153 ( V_414 -> V_428 - 1 , V_388 ,
V_58 -> V_321 != V_333 ) ;
F_154 ( V_388 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
if ( V_58 -> V_321 == V_333 )
V_344 . V_327 = V_332 ;
else
V_344 . V_327 = V_330 ;
V_344 . V_304 = V_58 -> V_61 ;
V_344 . V_345 = V_58 -> V_324 ;
F_155 ( V_388 , V_414 -> V_428 - 1 , & V_344 ) ;
F_156 ( V_388 ) ;
return 0 ;
V_35:
V_388 -> V_393 . V_444 = 1 ;
F_157 ( V_388 ) ;
return V_23 ;
}
static int F_158 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 ;
struct V_75 * V_136 ;
struct V_413 * V_414 ;
struct V_387 * V_388 ;
struct V_445 V_185 ;
struct V_343 V_344 ;
struct V_89 * V_90 ;
struct V_175 * V_446 = NULL ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_421 - 1 ] )
return - V_70 ;
V_414 = V_109 [ V_421 - 1 ] ;
if ( ! V_414 -> V_428 || V_414 -> V_428 >= V_439 )
return - V_70 ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ;
V_185 . V_135 = F_59 ( V_136 , & V_185 . V_186 ) ;
V_185 . V_254 = V_136 -> V_87 ;
V_185 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_185 . V_255 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_185 . V_255 )
V_185 . V_441 = F_151 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_185 . V_253 ) ;
V_185 . V_418 = V_136 -> V_87 ;
V_185 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_185 . V_419 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_185 . V_419 )
V_185 . V_442 = F_151 ( 0xffff ) ;
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 )
return - V_31 ;
V_23 = F_152 ( & V_446 , V_96 , V_33 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
return V_23 ;
}
V_388 = F_159 ( V_10 , V_147 , V_396 ,
V_414 -> V_428 - 1 , & V_185 , V_446 ,
1 , & V_23 ) ;
F_160 ( V_446 ) ;
if ( V_388 == NULL )
return - V_316 ;
F_161 ( V_388 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
V_344 . V_304 = V_58 -> V_61 ;
V_344 . V_345 = V_58 -> V_324 ;
V_344 . V_60 . V_437 = 0 ;
V_344 . V_327 = V_328 ;
F_155 ( V_388 , V_414 -> V_428 - 1 , & V_344 ) ;
V_35:
F_156 ( V_388 ) ;
if ( V_23 == 0 )
F_162 ( V_10 ) ;
return V_23 ;
}
static int F_163 ( struct V_2 * V_3 , struct V_387 * V_388 , const struct V_57 * V_58 , int V_389 )
{
int V_23 ;
struct V_41 * V_346 ;
struct V_57 * V_308 ;
V_23 = 0 ;
V_346 = F_146 ( V_388 ) ;
if ( F_94 ( V_346 ) ) {
V_23 = F_95 ( V_346 ) ;
goto V_35;
}
V_23 = F_147 ( V_346 , V_388 , V_389 ) ;
if ( V_23 < 0 )
goto V_35;
V_308 = (struct V_57 * ) V_346 -> V_60 ;
V_308 -> V_320 = V_58 -> V_320 ;
V_308 -> V_321 = V_58 -> V_321 ;
V_308 -> V_146 = 0 ;
V_308 -> V_62 = 0 ;
V_308 -> V_61 = V_58 -> V_61 ;
V_308 -> V_324 = V_58 -> V_324 ;
F_34 ( V_346 , V_63 , V_56 , V_3 , F_142 ( V_388 ) ) ;
V_23 = 0 ;
V_35:
return V_23 ;
}
static int F_164 ( T_3 V_135 )
{
return F_63 ( F_57 ( V_135 ) * 2 ) ;
}
static int F_165 ( struct V_77 * V_136 , int V_113 ,
T_4 * V_186 , T_4 * V_253 ,
T_9 * V_135 )
{
int V_447 , V_410 ;
if ( V_113 < F_164 ( V_136 -> V_84 ) )
return - V_70 ;
V_447 = F_58 ( V_136 , V_186 ) ;
if ( ! V_447 )
return - V_70 ;
V_410 = F_57 ( V_447 ) ;
if ( F_58 ( (struct V_77 * ) ( ( ( T_7 * ) V_136 ) + V_410 ) ,
V_253 ) != V_447 )
return - V_70 ;
* V_135 = V_447 ;
return 0 ;
}
static int F_166 ( struct V_397 * V_448 , int V_83 ,
struct V_449 * V_450 )
{
int V_23 ;
struct V_397 * V_451 ;
int V_149 ;
if ( V_83 <= sizeof( struct V_397 ) ||
V_83 < V_448 -> V_416 )
return - V_70 ;
V_23 = F_165 ( (struct V_77 * ) ( V_448 + 1 ) ,
V_448 -> V_416 ,
& V_450 -> V_452 , & V_450 -> V_453 ,
& V_450 -> V_454 ) ;
if ( V_23 )
return V_23 ;
V_451 = (struct V_397 * ) ( ( T_7 * ) V_448 + V_448 -> V_416 ) ;
V_83 -= V_448 -> V_416 ;
if ( V_83 <= sizeof( struct V_397 ) ||
V_83 < V_451 -> V_416 )
return - V_70 ;
V_23 = F_165 ( (struct V_77 * ) ( V_451 + 1 ) ,
V_451 -> V_416 ,
& V_450 -> V_455 , & V_450 -> V_456 ,
& V_450 -> V_457 ) ;
if ( V_23 )
return V_23 ;
if ( V_448 -> V_404 != V_451 -> V_404 ||
V_448 -> V_403 != V_451 -> V_403 ||
V_448 -> V_409 != V_451 -> V_409 )
return - V_70 ;
V_450 -> V_134 = V_448 -> V_404 ;
if ( ( V_149 = F_65 ( V_448 -> V_403 ) ) < 0 )
return - V_70 ;
V_450 -> V_149 = V_149 ;
V_450 -> V_271 = V_448 -> V_409 ;
return ( ( int ) ( V_448 -> V_416 +
V_451 -> V_416 ) ) ;
}
static int F_167 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_57 * V_58 , void * const * V_109 )
{
int V_350 , V_83 , V_458 , V_23 = - V_70 ;
T_7 V_389 ;
struct V_75 * V_136 ;
struct V_459 * V_460 ;
struct V_413 * V_414 ;
struct V_397 * V_398 ;
struct V_445 V_185 ;
struct V_449 V_450 [ V_401 ] ;
struct V_461 V_462 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_421 - 1 ] ) {
V_23 = - V_70 ;
goto V_35;
}
V_460 = V_109 [ V_463 - 1 ] ;
V_414 = V_109 [ V_421 - 1 ] ;
if ( V_414 -> V_428 >= V_439 ) {
V_23 = - V_70 ;
goto V_35;
}
if ( V_460 ) {
V_462 . V_464 = V_460 -> V_465 ;
V_458 = F_165 ( (struct V_77 * ) ( V_460 + 1 ) ,
8 * ( V_460 -> V_466 ) - sizeof( * V_460 ) ,
& V_462 . V_467 , & V_462 . V_468 , & V_462 . V_135 ) ;
if ( V_458 < 0 ) {
V_23 = V_458 ;
goto V_35;
}
}
V_389 = V_414 -> V_428 - 1 ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ;
V_185 . V_135 = F_59 ( V_136 , & V_185 . V_186 ) ;
V_185 . V_254 = V_136 -> V_87 ;
V_185 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_185 . V_255 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_185 . V_255 )
V_185 . V_441 = F_151 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_185 . V_253 ) ;
V_185 . V_418 = V_136 -> V_87 ;
V_185 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_185 . V_419 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_185 . V_419 )
V_185 . V_442 = F_151 ( 0xffff ) ;
V_398 = (struct V_397 * ) ( V_414 + 1 ) ;
V_350 = 0 ;
V_83 = V_414 -> V_415 * 8 - sizeof( struct V_413 ) ;
while ( V_83 > 0 && V_350 < V_401 ) {
V_458 = F_166 ( V_398 , V_83 , & V_450 [ V_350 ] ) ;
if ( V_458 < 0 ) {
V_23 = V_458 ;
goto V_35;
} else {
V_398 = (struct V_397 * ) ( ( T_7 * ) V_398 + V_458 ) ;
V_83 -= V_458 ;
V_350 ++ ;
}
}
if ( ! V_350 || V_83 > 0 ) {
V_23 = - V_70 ;
goto V_35;
}
return V_449 ( & V_185 , V_389 , V_396 , V_450 , V_350 ,
V_460 ? & V_462 : NULL , V_10 ) ;
V_35:
return V_23 ;
}
static int F_167 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_57 * V_58 , void * const * V_109 )
{
return - V_469 ;
}
static int F_168 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_389 ;
int V_23 = 0 , V_470 ;
struct V_413 * V_414 ;
struct V_387 * V_388 ;
struct V_343 V_344 ;
if ( ( V_414 = V_109 [ V_421 - 1 ] ) == NULL )
return - V_70 ;
V_389 = F_169 ( V_414 -> V_430 ) ;
if ( V_389 >= V_471 )
return - V_70 ;
V_470 = ( V_58 -> V_321 == V_438 ) ;
V_388 = F_170 ( V_10 , V_147 , V_396 ,
V_389 , V_414 -> V_430 , V_470 , & V_23 ) ;
if ( V_388 == NULL )
return - V_316 ;
if ( V_470 ) {
F_161 ( V_388 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
V_344 . V_304 = V_58 -> V_61 ;
V_344 . V_345 = V_58 -> V_324 ;
V_344 . V_60 . V_437 = 1 ;
V_344 . V_327 = V_328 ;
F_155 ( V_388 , V_389 , & V_344 ) ;
} else {
V_23 = F_163 ( V_3 , V_388 , V_58 , V_389 ) ;
}
V_35:
F_156 ( V_388 ) ;
if ( V_470 && V_23 == 0 )
F_162 ( V_10 ) ;
return V_23 ;
}
static int F_171 ( struct V_387 * V_388 , int V_389 , int V_366 , void * V_367 )
{
struct V_1 * V_6 = V_367 ;
struct V_41 * V_346 ;
struct V_57 * V_308 ;
int V_23 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_346 = F_146 ( V_388 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_23 = F_147 ( V_346 , V_388 , V_389 ) ;
if ( V_23 < 0 )
return V_23 ;
V_308 = (struct V_57 * ) V_346 -> V_60 ;
V_308 -> V_320 = V_6 -> V_7 . V_368 ;
V_308 -> V_321 = V_472 ;
V_308 -> V_146 = V_126 ;
V_308 -> V_62 = 0 ;
V_308 -> V_61 = V_366 + 1 ;
V_308 -> V_324 = V_6 -> V_7 . V_370 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_63 , V_56 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_346 ;
return 0 ;
}
static int F_172 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return V_392 ( V_10 , & V_6 -> V_7 . V_371 . V_473 , F_171 , ( void * ) V_6 ) ;
}
static void F_173 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( (struct V_2 * ) V_6 ) ;
F_140 ( & V_6 -> V_7 . V_371 . V_473 , V_10 ) ;
}
static int F_174 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_374 ;
V_6 -> V_7 . V_368 = V_58 -> V_320 ;
V_6 -> V_7 . V_370 = V_58 -> V_324 ;
V_6 -> V_7 . V_7 = F_172 ;
V_6 -> V_7 . V_9 = F_173 ;
F_139 ( & V_6 -> V_7 . V_371 . V_473 , V_396 ) ;
return F_38 ( V_6 ) ;
}
static int F_175 ( const struct V_343 * V_344 )
{
struct V_41 * V_474 ;
struct V_57 * V_58 ;
V_474 = F_41 ( sizeof( struct V_57 ) + 16 , V_63 ) ;
if ( ! V_474 )
return - V_44 ;
V_58 = (struct V_57 * ) F_43 ( V_474 , sizeof( struct V_57 ) ) ;
V_58 -> V_321 = V_475 ;
V_58 -> V_61 = V_344 -> V_304 ;
V_58 -> V_324 = V_344 -> V_345 ;
V_58 -> V_320 = V_29 ;
V_58 -> V_62 = ( V_71 ) 0 ;
V_58 -> V_146 = V_126 ;
V_58 -> V_72 = ( sizeof( struct V_57 ) / sizeof( V_73 ) ) ;
V_58 -> V_323 = 0 ;
F_34 ( V_474 , V_63 , V_52 , NULL , V_344 -> V_10 ) ;
return 0 ;
}
static int F_176 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_343 V_344 ;
int V_23 , V_50 ;
V_23 = F_177 ( V_10 , V_396 , true ) ;
V_50 = F_123 ( V_3 , V_58 ) ;
if ( V_23 || V_50 ) {
if ( V_23 == - V_49 )
return 0 ;
return V_23 ;
}
V_344 . V_60 . type = V_396 ;
V_344 . V_327 = V_476 ;
V_344 . V_345 = V_58 -> V_324 ;
V_344 . V_304 = V_58 -> V_61 ;
V_344 . V_10 = V_10 ;
F_155 ( NULL , 0 , & V_344 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 )
{
void * V_109 [ V_117 ] ;
int V_23 ;
F_34 ( F_31 ( V_8 , V_33 ) , V_33 ,
V_53 , NULL , F_7 ( V_3 ) ) ;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
V_23 = F_52 ( V_8 , V_58 , V_109 ) ;
if ( ! V_23 ) {
V_23 = - V_306 ;
if ( V_477 [ V_58 -> V_321 ] )
V_23 = V_477 [ V_58 -> V_321 ] ( V_3 , V_8 , V_58 , V_109 ) ;
}
return V_23 ;
}
static struct V_57 * F_179 ( struct V_41 * V_8 , int * V_478 )
{
struct V_57 * V_58 = NULL ;
if ( V_8 -> V_83 < sizeof( * V_58 ) ) {
* V_478 = - V_479 ;
} else {
V_58 = (struct V_57 * ) V_8 -> V_60 ;
if ( V_58 -> V_320 != V_29 ||
V_58 -> V_323 != 0 ||
( V_58 -> V_321 <= V_480 ||
V_58 -> V_321 > V_481 ) ) {
V_58 = NULL ;
* V_478 = - V_70 ;
} else if ( V_58 -> V_72 != ( V_8 -> V_83 /
sizeof( V_73 ) ) ||
V_58 -> V_72 < ( sizeof( struct V_57 ) /
sizeof( V_73 ) ) ) {
V_58 = NULL ;
* V_478 = - V_479 ;
} else {
* V_478 = 0 ;
}
}
return V_58 ;
}
static inline int F_180 ( const struct V_399 * V_400 ,
const struct V_211 * V_482 )
{
unsigned int V_196 = V_482 -> V_215 . V_216 ;
if ( V_196 >= sizeof( V_400 -> V_483 ) * 8 )
return 0 ;
return ( V_400 -> V_483 >> V_196 ) & 1 ;
}
static inline int F_181 ( const struct V_399 * V_400 ,
const struct V_211 * V_482 )
{
unsigned int V_196 = V_482 -> V_215 . V_216 ;
if ( V_196 >= sizeof( V_400 -> V_484 ) * 8 )
return 0 ;
return ( V_400 -> V_484 >> V_196 ) & 1 ;
}
static int F_182 ( const struct V_399 * V_400 )
{
int V_350 , V_485 = 0 ;
for ( V_350 = 0 ; ; V_350 ++ ) {
const struct V_211 * V_187 = F_119 ( V_350 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( F_180 ( V_400 , V_187 ) && V_187 -> V_358 )
V_485 += sizeof( struct V_486 ) ;
}
return V_485 + sizeof( struct V_487 ) ;
}
static int F_183 ( const struct V_399 * V_400 )
{
int V_350 , V_462 , V_485 = 0 ;
for ( V_350 = 0 ; ; V_350 ++ ) {
const struct V_211 * V_189 = F_120 ( V_350 ) ;
if ( ! V_189 )
break;
if ( ! V_189 -> V_214 )
continue;
if ( ! ( F_181 ( V_400 , V_189 ) && V_189 -> V_358 ) )
continue;
for ( V_462 = 1 ; ; V_462 ++ ) {
const struct V_211 * V_187 = F_119 ( V_462 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( F_180 ( V_400 , V_187 ) && V_187 -> V_358 )
V_485 += sizeof( struct V_486 ) ;
}
}
return V_485 + sizeof( struct V_487 ) ;
}
static void F_184 ( struct V_41 * V_8 , const struct V_399 * V_400 )
{
struct V_487 * V_74 ;
int V_350 ;
V_74 = (struct V_487 * ) F_43 ( V_8 , sizeof( struct V_487 ) ) ;
V_74 -> V_488 = sizeof( struct V_487 ) / 8 ;
V_74 -> V_489 = V_490 ;
V_74 -> V_491 = 32 ;
memset ( V_74 -> V_492 , 0 , sizeof( V_74 -> V_492 ) ) ;
for ( V_350 = 0 ; ; V_350 ++ ) {
const struct V_211 * V_187 = F_119 ( V_350 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( F_180 ( V_400 , V_187 ) && V_187 -> V_358 ) {
struct V_486 * V_344 ;
V_344 = (struct V_486 * ) F_43 ( V_8 , sizeof( struct V_486 ) ) ;
memset ( V_344 , 0 , sizeof( * V_344 ) ) ;
V_74 -> V_488 += sizeof( struct V_486 ) / 8 ;
V_344 -> V_493 = V_187 -> V_215 . V_216 ;
V_344 -> V_494 = V_187 -> V_215 . V_495 ;
V_344 -> V_496 = V_187 -> V_215 . V_497 ;
V_344 -> V_498 = 24 * 60 * 60 ;
V_344 -> V_499 = 20 * 60 * 60 ;
V_344 -> V_500 = 8 * 60 * 60 ;
V_344 -> V_501 = 7 * 60 * 60 ;
}
}
}
static void F_185 ( struct V_41 * V_8 , const struct V_399 * V_400 )
{
struct V_487 * V_74 ;
int V_350 , V_462 ;
V_74 = (struct V_487 * ) F_43 ( V_8 , sizeof( struct V_487 ) ) ;
V_74 -> V_488 = sizeof( struct V_487 ) / 8 ;
V_74 -> V_489 = V_490 ;
V_74 -> V_491 = 32 ;
memset ( V_74 -> V_492 , 0 , sizeof( V_74 -> V_492 ) ) ;
for ( V_350 = 0 ; ; V_350 ++ ) {
const struct V_211 * V_189 = F_120 ( V_350 ) ;
if ( ! V_189 )
break;
if ( ! V_189 -> V_214 )
continue;
if ( ! ( F_181 ( V_400 , V_189 ) && V_189 -> V_358 ) )
continue;
for ( V_462 = 1 ; ; V_462 ++ ) {
struct V_486 * V_344 ;
const struct V_211 * V_187 = F_119 ( V_462 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( ! ( F_180 ( V_400 , V_187 ) && V_187 -> V_358 ) )
continue;
V_344 = (struct V_486 * ) F_43 ( V_8 , sizeof( struct V_486 ) ) ;
memset ( V_344 , 0 , sizeof( * V_344 ) ) ;
V_74 -> V_488 += sizeof( struct V_486 ) / 8 ;
V_344 -> V_493 = V_187 -> V_215 . V_216 ;
V_344 -> V_494 = V_187 -> V_215 . V_495 ;
V_344 -> V_496 = V_187 -> V_215 . V_497 ;
V_344 -> V_502 = V_189 -> V_215 . V_216 ;
V_344 -> V_503 = V_189 -> V_215 . V_495 ;
V_344 -> V_504 = V_189 -> V_215 . V_497 ;
V_344 -> V_498 = 24 * 60 * 60 ;
V_344 -> V_499 = 20 * 60 * 60 ;
V_344 -> V_500 = 8 * 60 * 60 ;
V_344 -> V_501 = 7 * 60 * 60 ;
}
}
}
static int F_186 ( struct V_387 * V_388 , const struct V_343 * V_344 )
{
return 0 ;
}
static int F_187 ( struct V_143 * V_166 , const struct V_343 * V_344 )
{
struct V_41 * V_346 ;
struct V_57 * V_308 ;
int V_505 ;
int V_168 ;
V_505 = V_344 -> V_60 . V_505 ;
if ( V_505 )
V_168 = 2 ;
else
V_168 = 1 ;
V_346 = F_76 ( V_166 , V_168 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_308 = (struct V_57 * ) V_346 -> V_60 ;
V_308 -> V_320 = V_29 ;
V_308 -> V_321 = V_342 ;
V_308 -> V_146 = F_54 ( V_166 -> V_196 . V_134 ) ;
V_308 -> V_62 = 0 ;
V_308 -> V_323 = 0 ;
V_308 -> V_61 = 0 ;
V_308 -> V_324 = 0 ;
F_34 ( V_346 , V_63 , V_54 , NULL , F_102 ( V_166 ) ) ;
return 0 ;
}
static int F_188 ( struct V_143 * V_166 , const struct V_343 * V_344 )
{
struct V_10 * V_10 = V_166 ? F_102 ( V_166 ) : V_344 -> V_10 ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
if ( F_3 ( & V_12 -> V_17 ) == 0 )
return 0 ;
switch ( V_344 -> V_327 ) {
case V_341 :
return F_187 ( V_166 , V_344 ) ;
case V_335 :
case V_337 :
case V_339 :
return F_101 ( V_166 , V_344 ) ;
case V_365 :
return F_124 ( V_344 ) ;
case V_506 :
break;
default:
F_11 ( L_3 , V_344 -> V_327 ) ;
break;
}
return 0 ;
}
static int F_189 ( struct V_387 * V_388 , int V_389 , const struct V_343 * V_344 )
{
if ( V_388 && V_388 -> type != V_396 )
return 0 ;
switch ( V_344 -> V_327 ) {
case V_334 :
return F_186 ( V_388 , V_344 ) ;
case V_328 :
case V_330 :
case V_332 :
return F_148 ( V_388 , V_389 , V_344 ) ;
case V_476 :
if ( V_344 -> V_60 . type != V_396 )
break;
return F_175 ( V_344 ) ;
default:
F_11 ( L_2 , V_344 -> V_327 ) ;
break;
}
return 0 ;
}
static T_6 F_190 ( void )
{
T_6 V_507 ;
static T_10 V_508 ;
do {
V_507 = F_191 ( & V_508 ) ;
} while ( ! V_507 );
return V_507 ;
}
static bool F_192 ( const struct V_343 * V_344 )
{
struct V_11 * V_12 = F_8 ( V_344 -> V_10 , V_13 ) ;
struct V_2 * V_3 ;
bool V_509 = false ;
F_35 () ;
F_36 (sk, &net_pfkey->table) {
if ( F_1 ( V_3 ) -> V_55 ) {
V_509 = true ;
break;
}
}
F_37 () ;
return V_509 ;
}
static int F_193 ( struct V_143 * V_166 , struct V_399 * V_400 , struct V_387 * V_388 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
struct V_75 * V_78 ;
struct V_413 * V_414 ;
int V_180 ;
int V_177 ;
struct V_89 * V_90 ;
struct V_175 * V_176 ;
int V_97 = 0 ;
V_180 = F_62 ( V_166 -> V_183 . V_135 ) ;
if ( ! V_180 )
return - V_70 ;
V_177 = sizeof( struct V_57 ) +
( sizeof( struct V_75 ) * 2 ) +
( V_180 * 2 ) +
sizeof( struct V_413 ) ;
if ( V_166 -> V_196 . V_134 == V_129 )
V_177 += F_182 ( V_400 ) ;
else if ( V_166 -> V_196 . V_134 == V_131 )
V_177 += F_183 ( V_400 ) ;
if ( ( V_176 = V_166 -> V_184 ) ) {
V_97 = F_63 ( V_176 -> V_104 ) ;
V_177 += sizeof( struct V_89 ) + V_97 ;
}
V_8 = F_41 ( V_177 + 16 , V_63 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
V_58 -> V_320 = V_29 ;
V_58 -> V_321 = V_510 ;
V_58 -> V_146 = F_54 ( V_166 -> V_196 . V_134 ) ;
V_58 -> V_72 = V_177 / sizeof( V_73 ) ;
V_58 -> V_62 = 0 ;
V_58 -> V_323 = 0 ;
V_58 -> V_61 = V_166 -> V_200 . V_304 = F_190 () ;
V_58 -> V_324 = 0 ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_120 ;
V_78 -> V_251 = 0 ;
V_78 -> V_252 = 0 ;
V_78 -> V_87 =
F_66 ( & V_166 -> V_183 . V_186 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_166 -> V_183 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_121 ;
V_78 -> V_251 = 0 ;
V_78 -> V_252 = 0 ;
V_78 -> V_87 =
F_66 ( & V_166 -> V_196 . V_253 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_166 -> V_183 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_414 = (struct V_413 * ) F_43 ( V_8 , sizeof( struct V_413 ) ) ;
V_414 -> V_415 = sizeof( struct V_413 ) / sizeof( V_73 ) ;
V_414 -> V_420 = V_421 ;
V_414 -> V_422 = V_426 ;
V_414 -> V_428 = V_511 + 1 ;
V_414 -> V_429 = 0 ;
V_414 -> V_430 = V_388 -> V_431 ;
V_414 -> V_432 = V_388 -> V_433 ;
if ( V_166 -> V_196 . V_134 == V_129 )
F_184 ( V_8 , V_400 ) ;
else if ( V_166 -> V_196 . V_134 == V_131 )
F_185 ( V_8 , V_400 ) ;
if ( V_176 ) {
V_90 = (struct V_89 * ) F_43 ( V_8 ,
sizeof( struct V_89 ) + V_97 ) ;
V_90 -> V_93 =
( sizeof( struct V_89 ) + V_97 ) / sizeof( V_73 ) ;
V_90 -> V_99 = V_124 ;
V_90 -> V_101 = V_176 -> V_100 ;
V_90 -> V_103 = V_176 -> V_102 ;
V_90 -> V_91 = V_176 -> V_104 ;
memcpy ( V_90 + 1 , V_176 -> V_287 ,
V_176 -> V_104 ) ;
}
return F_34 ( V_8 , V_63 , V_54 , NULL , F_102 ( V_166 ) ) ;
}
static struct V_387 * F_194 ( struct V_2 * V_3 , int V_512 ,
T_7 * V_60 , int V_83 , int * V_389 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_387 * V_388 ;
struct V_413 * V_414 = (struct V_413 * ) V_60 ;
struct V_89 * V_90 ;
switch ( V_3 -> V_38 ) {
case V_85 :
if ( V_512 != V_513 ) {
* V_389 = - V_306 ;
return NULL ;
}
break;
#if F_45 ( V_80 )
case V_88 :
if ( V_512 != V_514 ) {
* V_389 = - V_306 ;
return NULL ;
}
break;
#endif
default:
* V_389 = - V_70 ;
return NULL ;
}
* V_389 = - V_70 ;
if ( V_83 < sizeof( struct V_413 ) ||
V_414 -> V_415 * 8 > V_83 ||
V_414 -> V_422 > V_515 ||
( ! V_414 -> V_428 || V_414 -> V_428 > V_516 ) )
return NULL ;
V_388 = F_150 ( V_10 , V_63 ) ;
if ( V_388 == NULL ) {
* V_389 = - V_44 ;
return NULL ;
}
V_388 -> V_424 = ( V_414 -> V_422 == V_423 ?
V_440 : V_425 ) ;
V_388 -> V_231 . V_241 = V_443 ;
V_388 -> V_231 . V_234 = V_443 ;
V_388 -> V_231 . V_240 = V_443 ;
V_388 -> V_231 . V_232 = V_443 ;
V_388 -> V_135 = V_3 -> V_38 ;
V_388 -> V_390 = 0 ;
if ( V_414 -> V_422 == V_426 &&
( * V_389 = F_143 ( V_388 , V_414 ) ) < 0 )
goto V_35;
if ( V_83 >= ( V_414 -> V_415 * 8 +
sizeof( struct V_89 ) ) ) {
char * V_74 = ( char * ) V_414 ;
struct V_94 * V_96 ;
V_74 += V_414 -> V_415 * 8 ;
V_90 = (struct V_89 * ) V_74 ;
if ( V_83 < V_414 -> V_415 * 8 +
V_90 -> V_93 ) {
* V_389 = - V_70 ;
goto V_35;
}
if ( ( * V_389 = F_48 ( V_74 ) ) )
goto V_35;
V_96 = F_49 ( V_90 , V_63 ) ;
* V_389 = F_152 ( & V_388 -> V_184 , V_96 , V_63 ) ;
F_82 ( V_96 ) ;
if ( * V_389 )
goto V_35;
}
* V_389 = V_414 -> V_428 - 1 ;
return V_388 ;
V_35:
V_388 -> V_393 . V_444 = 1 ;
F_157 ( V_388 ) ;
return NULL ;
}
static int F_195 ( struct V_143 * V_166 , T_4 * V_517 , T_5 V_255 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
struct V_144 * V_136 ;
struct V_75 * V_78 ;
struct V_193 * V_273 ;
int V_180 ;
int V_177 ;
T_8 V_125 = ( V_166 -> V_196 . V_134 == V_131 ? V_130 : 0 ) ;
struct V_181 * V_182 = NULL ;
V_180 = F_62 ( V_166 -> V_183 . V_135 ) ;
if ( ! V_180 )
return - V_70 ;
if ( ! V_125 )
return - V_70 ;
if ( ! V_166 -> V_190 )
return - V_70 ;
V_182 = V_166 -> V_190 ;
V_177 = sizeof( struct V_57 ) +
sizeof( struct V_144 ) +
( sizeof( struct V_75 ) * 2 ) +
( V_180 * 2 ) +
( sizeof( struct V_193 ) * 2 ) ;
V_8 = F_41 ( V_177 + 16 , V_63 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
V_58 -> V_320 = V_29 ;
V_58 -> V_321 = V_518 ;
V_58 -> V_146 = V_125 ;
V_58 -> V_72 = V_177 / sizeof( V_73 ) ;
V_58 -> V_62 = 0 ;
V_58 -> V_323 = 0 ;
V_58 -> V_61 = V_166 -> V_200 . V_304 = F_190 () ;
V_58 -> V_324 = 0 ;
V_136 = (struct V_144 * ) F_43 ( V_8 , sizeof( struct V_144 ) ) ;
V_136 -> V_194 = sizeof( struct V_144 ) / sizeof( V_73 ) ;
V_136 -> V_195 = V_145 ;
V_136 -> V_148 = V_166 -> V_196 . V_197 ;
V_136 -> V_198 = 0 ;
V_136 -> V_203 = 0 ;
V_136 -> V_210 = 0 ;
V_136 -> V_217 = 0 ;
V_136 -> V_219 = 0 ;
V_78 = (struct V_75 * )
F_43 ( V_8 , sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_120 ;
V_78 -> V_251 = 0 ;
V_78 -> V_252 = 0 ;
V_78 -> V_87 =
F_66 ( & V_166 -> V_183 . V_186 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_166 -> V_183 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_273 = (struct V_193 * ) F_43 ( V_8 , sizeof ( * V_273 ) ) ;
V_273 -> V_279 = sizeof( * V_273 ) / sizeof( V_73 ) ;
V_273 -> V_280 = V_281 ;
V_273 -> V_282 = V_182 -> V_283 ;
V_273 -> V_284 = 0 ;
V_78 = (struct V_75 * )
F_43 ( V_8 , sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_121 ;
V_78 -> V_251 = 0 ;
V_78 -> V_252 = 0 ;
V_78 -> V_87 =
F_66 ( V_517 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_166 -> V_183 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_273 = (struct V_193 * ) F_43 ( V_8 , sizeof ( * V_273 ) ) ;
V_273 -> V_279 = sizeof( * V_273 ) / sizeof( V_73 ) ;
V_273 -> V_280 = V_285 ;
V_273 -> V_282 = V_255 ;
V_273 -> V_284 = 0 ;
return F_34 ( V_8 , V_63 , V_54 , NULL , F_102 ( V_166 ) ) ;
}
static int F_196 ( struct V_41 * V_8 , int V_519 , int type ,
const struct V_445 * V_185 )
{
struct V_75 * V_78 ;
V_78 = (struct V_75 * ) F_43 ( V_8 , sizeof( struct V_75 ) + V_519 ) ;
V_78 -> V_86 = ( sizeof( struct V_75 ) + V_519 ) / 8 ;
V_78 -> V_250 = type ;
V_78 -> V_251 = V_185 -> V_134 ;
V_78 -> V_252 = 0 ;
switch ( type ) {
case V_120 :
V_78 -> V_87 = V_185 -> V_254 ;
F_66 ( & V_185 -> V_186 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_185 -> V_135 ) ;
break;
case V_121 :
V_78 -> V_87 = V_185 -> V_418 ;
F_66 ( & V_185 -> V_253 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_185 -> V_135 ) ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static int F_197 ( struct V_41 * V_8 , const struct V_461 * V_462 )
{
struct V_459 * V_460 ;
T_7 * V_136 ;
int V_135 = V_462 -> V_135 ;
int V_410 = F_57 ( V_135 ) ;
int V_520 ;
V_520 = ( sizeof( struct V_459 ) +
F_164 ( V_135 ) ) ;
V_460 = (struct V_459 * ) F_43 ( V_8 , V_520 ) ;
memset ( V_460 , 0 , V_520 ) ;
V_460 -> V_466 = V_520 / 8 ;
V_460 -> V_521 = V_463 ;
V_460 -> V_465 = V_462 -> V_464 ;
V_136 = ( T_7 * ) ( V_460 + 1 ) ;
if ( ! F_66 ( & V_462 -> V_467 , 0 , (struct V_77 * ) V_136 , V_135 ) ||
! F_66 ( & V_462 -> V_468 , 0 , (struct V_77 * ) ( V_136 + V_410 ) , V_135 ) )
return - V_70 ;
return 0 ;
}
static int F_198 ( struct V_41 * V_8 ,
V_71 V_134 , V_71 V_149 , int V_522 ,
T_11 V_271 , V_71 V_135 ,
const T_4 * V_105 , const T_4 * V_106 )
{
struct V_397 * V_398 ;
T_7 * V_136 ;
int V_410 = F_57 ( V_135 ) ;
int V_520 ;
V_520 = sizeof( struct V_397 ) +
F_164 ( V_135 ) ;
V_398 = (struct V_397 * ) F_43 ( V_8 , V_520 ) ;
memset ( V_398 , 0 , V_520 ) ;
V_398 -> V_416 = V_520 ;
V_398 -> V_404 = V_134 ;
V_398 -> V_403 = V_149 ;
V_398 -> V_405 = V_522 ;
V_398 -> V_409 = V_271 ;
V_136 = ( T_7 * ) ( V_398 + 1 ) ;
if ( ! F_66 ( V_105 , 0 , (struct V_77 * ) V_136 , V_135 ) ||
! F_66 ( V_106 , 0 , (struct V_77 * ) ( V_136 + V_410 ) , V_135 ) )
return - V_70 ;
return 0 ;
}
static int F_199 ( const struct V_445 * V_185 , T_7 V_389 , T_7 type ,
const struct V_449 * V_450 , int V_523 ,
const struct V_461 * V_462 )
{
int V_350 ;
int V_524 ;
int V_177 = 0 ;
int V_525 = 0 ;
struct V_41 * V_8 ;
struct V_57 * V_58 ;
struct V_413 * V_414 ;
const struct V_449 * V_526 ;
if ( type != V_396 )
return 0 ;
if ( V_523 <= 0 || V_523 > V_401 )
return - V_70 ;
if ( V_462 != NULL ) {
V_177 += F_63 ( sizeof( struct V_459 ) +
F_164 ( V_462 -> V_135 ) ) ;
}
V_524 = F_62 ( V_185 -> V_135 ) ;
if ( ! V_524 )
return - V_70 ;
V_177 += ( sizeof( struct V_75 ) + V_524 ) * 2 ;
V_525 += sizeof( struct V_413 ) ;
for ( V_350 = 0 , V_526 = V_450 ; V_350 < V_523 ; V_350 ++ , V_526 ++ ) {
V_525 += sizeof( struct V_397 ) +
F_164 ( V_526 -> V_454 ) ;
V_525 += sizeof( struct V_397 ) +
F_164 ( V_526 -> V_457 ) ;
}
V_177 += sizeof( struct V_57 ) + V_525 ;
V_8 = F_41 ( V_177 , V_63 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
V_58 -> V_320 = V_29 ;
V_58 -> V_321 = V_527 ;
V_58 -> V_146 = F_54 ( V_450 -> V_134 ) ;
V_58 -> V_72 = V_177 / 8 ;
V_58 -> V_62 = 0 ;
V_58 -> V_323 = 0 ;
V_58 -> V_61 = 0 ;
V_58 -> V_324 = 0 ;
if ( V_462 != NULL && ( F_197 ( V_8 , V_462 ) < 0 ) )
goto V_23;
F_196 ( V_8 , V_524 , V_120 , V_185 ) ;
F_196 ( V_8 , V_524 , V_121 , V_185 ) ;
V_414 = (struct V_413 * ) F_43 ( V_8 , sizeof( struct V_413 ) ) ;
V_414 -> V_415 = V_525 / 8 ;
V_414 -> V_420 = V_421 ;
V_414 -> V_422 = V_426 ;
V_414 -> V_428 = V_389 + 1 ;
V_414 -> V_429 = 0 ;
V_414 -> V_430 = 0 ;
V_414 -> V_432 = 0 ;
for ( V_350 = 0 , V_526 = V_450 ; V_350 < V_523 ; V_350 ++ , V_526 ++ ) {
int V_149 = F_64 ( V_526 -> V_149 ) ;
if ( V_149 < 0 )
goto V_23;
if ( F_198 ( V_8 , V_526 -> V_134 , V_149 ,
( V_526 -> V_271 ? V_408 : V_435 ) ,
V_526 -> V_271 , V_526 -> V_454 ,
& V_526 -> V_452 , & V_526 -> V_453 ) < 0 )
goto V_23;
if ( F_198 ( V_8 , V_526 -> V_134 , V_149 ,
( V_526 -> V_271 ? V_408 : V_435 ) ,
V_526 -> V_271 , V_526 -> V_457 ,
& V_526 -> V_455 , & V_526 -> V_456 ) < 0 )
goto V_23;
}
F_34 ( V_8 , V_63 , V_52 , NULL , & V_528 ) ;
return 0 ;
V_23:
F_5 ( V_8 ) ;
return - V_70 ;
}
static int F_199 ( const struct V_445 * V_185 , T_7 V_389 , T_7 type ,
const struct V_449 * V_450 , int V_523 ,
const struct V_461 * V_462 )
{
return - V_469 ;
}
static int F_200 ( struct V_20 * V_2 , struct V_529 * V_530 , T_12 V_83 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_41 * V_8 = NULL ;
struct V_57 * V_58 = NULL ;
int V_23 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
V_23 = - V_306 ;
if ( V_530 -> V_531 & V_532 )
goto V_35;
V_23 = - V_479 ;
if ( ( unsigned int ) V_83 > V_3 -> V_533 - 32 )
goto V_35;
V_23 = - V_44 ;
V_8 = F_41 ( V_83 , V_33 ) ;
if ( V_8 == NULL )
goto V_35;
V_23 = - V_534 ;
if ( F_201 ( F_43 ( V_8 , V_83 ) , V_530 , V_83 ) )
goto V_35;
V_58 = F_179 ( V_8 , & V_23 ) ;
if ( ! V_58 )
goto V_35;
F_15 ( & V_10 -> V_535 . V_536 ) ;
V_23 = F_178 ( V_3 , V_8 , V_58 ) ;
F_17 ( & V_10 -> V_535 . V_536 ) ;
V_35:
if ( V_23 && V_58 && F_40 ( V_58 , V_23 , V_3 ) == 0 )
V_23 = 0 ;
F_5 ( V_8 ) ;
return V_23 ? : V_83 ;
}
static int F_202 ( struct V_20 * V_2 , struct V_529 * V_530 , T_12 V_83 ,
int V_220 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_8 ;
int V_537 , V_23 ;
V_23 = - V_70 ;
if ( V_220 & ~ ( V_538 | V_539 | V_540 | V_541 ) )
goto V_35;
V_8 = F_203 ( V_3 , V_220 , V_220 & V_539 , & V_23 ) ;
if ( V_8 == NULL )
goto V_35;
V_537 = V_8 -> V_83 ;
if ( V_537 > V_83 ) {
V_530 -> V_531 |= V_540 ;
V_537 = V_83 ;
}
F_204 ( V_8 ) ;
V_23 = F_205 ( V_8 , 0 , V_530 , V_537 ) ;
if ( V_23 )
goto V_542;
F_206 ( V_530 , V_3 , V_8 ) ;
V_23 = ( V_220 & V_540 ) ? V_8 -> V_83 : V_537 ;
if ( V_6 -> V_7 . V_7 != NULL &&
3 * F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 )
F_38 ( V_6 ) ;
V_542:
F_207 ( V_3 , V_8 ) ;
V_35:
return V_23 ;
}
static int F_208 ( struct V_543 * V_544 , void * V_545 )
{
struct V_2 * V_546 = F_209 ( V_545 ) ;
if ( V_545 == V_547 )
F_210 ( V_544 , L_4 ) ;
else
F_210 ( V_544 , L_5 ,
V_546 ,
F_3 ( & V_546 -> V_548 ) ,
F_211 ( V_546 ) ,
F_212 ( V_546 ) ,
F_213 ( F_214 ( V_544 ) , F_215 ( V_546 ) ) ,
F_216 ( V_546 )
) ;
return 0 ;
}
static void * F_217 ( struct V_543 * V_544 , T_13 * V_549 )
__acquires( T_14 )
{
struct V_10 * V_10 = F_218 ( V_544 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_35 () ;
return F_219 ( & V_12 -> V_19 , * V_549 ) ;
}
static void * F_220 ( struct V_543 * V_544 , void * V_545 , T_13 * V_549 )
{
struct V_10 * V_10 = F_218 ( V_544 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
return F_221 ( V_545 , & V_12 -> V_19 , V_549 ) ;
}
static void F_222 ( struct V_543 * V_544 , void * V_545 )
__releases( T_14 )
{
F_37 () ;
}
static int F_223 ( struct V_550 * V_550 , struct V_551 * V_551 )
{
return F_224 ( V_550 , V_551 , & V_552 ,
sizeof( struct V_553 ) ) ;
}
static int T_15 F_225 ( struct V_10 * V_10 )
{
struct V_554 * V_555 ;
V_555 = F_226 ( L_6 , 0 , V_10 -> V_556 , & V_557 ) ;
if ( V_555 == NULL )
return - V_31 ;
return 0 ;
}
static void T_16 F_227 ( struct V_10 * V_10 )
{
F_228 ( L_6 , V_10 -> V_556 ) ;
}
static inline int F_225 ( struct V_10 * V_10 )
{
return 0 ;
}
static inline void F_227 ( struct V_10 * V_10 )
{
}
static int T_15 F_229 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
int V_558 ;
F_230 ( & V_12 -> V_19 ) ;
F_231 ( & V_12 -> V_17 , 0 ) ;
V_558 = F_225 ( V_10 ) ;
return V_558 ;
}
static void T_16 F_232 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_227 ( V_10 ) ;
F_42 ( ! F_233 ( & V_12 -> V_19 ) ) ;
}
static void T_17 F_234 ( void )
{
F_235 ( & V_559 ) ;
F_236 ( V_32 ) ;
F_237 ( & V_560 ) ;
F_238 ( & V_34 ) ;
}
static int T_18 F_239 ( void )
{
int V_23 = F_240 ( & V_34 , 0 ) ;
if ( V_23 != 0 )
goto V_35;
V_23 = F_241 ( & V_560 ) ;
if ( V_23 != 0 )
goto V_561;
V_23 = F_242 ( & V_562 ) ;
if ( V_23 != 0 )
goto V_563;
V_23 = F_243 ( & V_559 ) ;
if ( V_23 != 0 )
goto V_564;
V_35:
return V_23 ;
V_564:
F_236 ( V_32 ) ;
V_563:
F_237 ( & V_560 ) ;
V_561:
F_238 ( & V_34 ) ;
goto V_35;
}
