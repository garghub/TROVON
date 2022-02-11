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
V_3 = F_22 ( V_10 , V_32 , V_33 , & V_34 , V_22 ) ;
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
static int F_34 ( struct V_41 * V_8 ,
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
F_29 ( V_8 , & V_42 , V_52 , V_3 ) ;
if ( V_3 == V_48 )
continue;
if ( V_47 != V_53 ) {
if ( V_47 & V_54 )
continue;
if ( ( V_47 & V_55 ) &&
! V_6 -> V_56 )
continue;
if ( V_47 & V_57 )
continue;
}
V_50 = F_29 ( V_8 , & V_42 , V_52 , V_3 ) ;
if ( ( V_47 & V_55 ) && V_23 )
V_23 = V_50 ;
}
F_37 () ;
if ( V_48 != NULL )
V_23 = F_29 ( V_8 , & V_42 , V_33 , V_48 ) ;
F_5 ( V_42 ) ;
F_5 ( V_8 ) ;
return V_23 ;
}
static int F_38 ( struct V_1 * V_6 )
{
struct V_58 * V_59 ;
int V_60 ;
V_60 = V_6 -> V_7 . V_7 ( V_6 ) ;
if ( V_60 == - V_44 )
return 0 ;
if ( V_6 -> V_7 . V_8 ) {
if ( ! F_2 ( & V_6 -> V_3 ) )
return 0 ;
V_59 = (struct V_58 * ) V_6 -> V_7 . V_8 -> V_61 ;
V_59 -> V_62 = 0 ;
V_59 -> V_63 = V_60 ;
F_34 ( V_6 -> V_7 . V_8 , V_57 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = NULL ;
}
F_4 ( V_6 ) ;
return V_60 ;
}
static inline void F_39 ( struct V_58 * V_64 ,
const struct V_58 * V_65 )
{
* V_64 = * V_65 ;
}
static int F_40 ( const struct V_58 * V_65 , int V_23 , struct V_2 * V_3 )
{
struct V_41 * V_8 = F_41 ( sizeof( struct V_58 ) + 16 , V_33 ) ;
struct V_58 * V_59 ;
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
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
F_39 ( V_59 , V_65 ) ;
V_59 -> V_63 = ( V_71 ) V_23 ;
V_59 -> V_72 = ( sizeof( struct V_58 ) /
sizeof( V_73 ) ) ;
F_34 ( V_8 , V_57 , V_3 , F_7 ( V_3 ) ) ;
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
static int F_52 ( struct V_41 * V_8 , const struct V_58 * V_59 , void * * V_109 )
{
const char * V_74 = ( char * ) V_59 ;
int V_83 = V_8 -> V_83 ;
V_83 -= sizeof( * V_59 ) ;
V_74 += sizeof( * V_59 ) ;
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
static struct V_143 * F_60 ( struct V_10 * V_10 , const struct V_58 * V_59 , void * const * V_109 )
{
const struct V_144 * V_136 ;
const struct V_75 * V_78 ;
T_2 V_134 ;
unsigned short V_135 ;
T_4 * V_137 ;
V_136 = V_109 [ V_145 - 1 ] ;
if ( V_136 == NULL )
return NULL ;
V_134 = F_53 ( V_59 -> V_146 ) ;
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
struct V_58 * V_59 ;
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
V_177 = sizeof( struct V_58 ) + sizeof( struct V_144 ) +
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
V_8 = F_41 ( V_177 + 16 , V_52 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
memset ( V_59 , 0 , V_177 ) ;
V_59 -> V_72 = V_177 / sizeof( V_73 ) ;
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
const struct V_58 * V_59 ,
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
if ( V_59 -> V_146 == V_130 &&
! V_109 [ V_262 - 1 ] )
return F_68 ( - V_70 ) ;
if ( V_59 -> V_146 == V_128 &&
! V_109 [ V_258 - 1 ] )
return F_68 ( - V_70 ) ;
if ( ! ! V_109 [ V_229 - 1 ] !=
! ! V_109 [ V_239 - 1 ] )
return F_68 ( - V_70 ) ;
V_134 = F_53 ( V_59 -> V_146 ) ;
if ( V_134 == 0 )
return F_68 ( - V_70 ) ;
V_23 = - V_44 ;
if ( V_136 -> V_210 > V_288 ||
( V_59 -> V_146 == V_132 &&
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
if ( V_59 -> V_146 == V_132 ) {
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
V_166 -> V_303 = V_212 -> V_297 . V_304 . V_303 ;
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
memset ( & V_182 -> V_305 , 0 , sizeof( V_182 -> V_305 ) ) ;
}
V_23 = F_86 ( V_166 ) ;
if ( V_23 )
goto V_35;
V_166 -> V_200 . V_306 = V_59 -> V_62 ;
return V_166 ;
V_35:
V_166 -> V_200 . V_201 = V_307 ;
F_87 ( V_166 ) ;
return F_68 ( V_23 ) ;
}
static int F_88 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
return - V_308 ;
}
static int F_89 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_41 * V_309 ;
struct V_173 * V_174 ;
struct V_75 * V_186 , * V_253 ;
struct V_58 * V_310 ;
struct V_311 * V_312 ;
struct V_143 * V_166 = NULL ;
int V_149 ;
int V_23 ;
T_6 V_313 , V_314 ;
T_6 V_271 ;
T_7 V_134 ;
unsigned short V_135 ;
T_4 * V_315 = NULL , * V_316 = NULL ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_70 ;
V_134 = F_53 ( V_59 -> V_146 ) ;
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
V_316 = ( T_4 * ) & ( (struct V_79 * ) ( V_253 + 1 ) ) -> V_139 . V_107 ;
V_315 = ( T_4 * ) & ( (struct V_79 * ) ( V_186 + 1 ) ) -> V_139 . V_107 ;
break;
#if F_45 ( V_80 )
case V_88 :
V_316 = ( T_4 * ) & ( (struct V_81 * ) ( V_253 + 1 ) ) -> V_141 ;
V_315 = ( T_4 * ) & ( (struct V_81 * ) ( V_186 + 1 ) ) -> V_141 ;
break;
#endif
}
if ( V_59 -> V_62 ) {
V_166 = F_90 ( V_10 , V_147 , V_59 -> V_62 ) ;
if ( V_166 && ! F_69 ( & V_166 -> V_196 . V_253 , V_316 , V_135 ) ) {
F_87 ( V_166 ) ;
V_166 = NULL ;
}
}
if ( ! V_166 )
V_166 = F_91 ( V_10 , & V_317 , V_149 , V_271 , V_134 , V_316 , V_315 , 1 , V_135 ) ;
if ( V_166 == NULL )
return - V_318 ;
V_313 = 0x100 ;
V_314 = 0x0fffffff ;
V_312 = V_109 [ V_319 - 1 ] ;
if ( V_312 ) {
V_313 = V_312 -> V_320 ;
V_314 = V_312 -> V_321 ;
}
V_23 = F_92 ( V_166 -> V_196 . V_134 , V_313 , V_314 ) ;
if ( V_23 ) {
F_87 ( V_166 ) ;
return V_23 ;
}
V_23 = F_93 ( V_166 , V_313 , V_314 ) ;
V_309 = V_23 ? F_68 ( V_23 ) : F_75 ( V_166 ) ;
if ( F_94 ( V_309 ) ) {
F_87 ( V_166 ) ;
return F_95 ( V_309 ) ;
}
V_310 = (struct V_58 * ) V_309 -> V_61 ;
V_310 -> V_322 = V_59 -> V_322 ;
V_310 -> V_323 = V_324 ;
V_310 -> V_146 = F_54 ( V_134 ) ;
V_310 -> V_63 = 0 ;
V_310 -> V_325 = 0 ;
V_310 -> V_62 = V_59 -> V_62 ;
V_310 -> V_326 = V_59 -> V_326 ;
F_87 ( V_166 ) ;
F_34 ( V_309 , V_57 , V_3 , V_10 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_166 ;
if ( V_59 -> V_72 != sizeof( struct V_58 ) / 8 )
return - V_308 ;
if ( V_59 -> V_62 == 0 || V_59 -> V_63 == 0 )
return 0 ;
V_166 = F_90 ( V_10 , V_147 , V_59 -> V_62 ) ;
if ( V_166 == NULL )
return 0 ;
F_97 ( & V_166 -> V_327 ) ;
if ( V_166 -> V_200 . V_201 == V_207 )
V_166 -> V_200 . V_201 = V_328 ;
F_98 ( & V_166 -> V_327 ) ;
F_87 ( V_166 ) ;
return 0 ;
}
static inline int F_99 ( int V_329 )
{
switch ( V_329 ) {
case V_330 :
return V_331 ;
case V_332 :
return V_333 ;
case V_334 :
return V_335 ;
case V_336 :
default:
F_11 ( L_2 , V_329 ) ;
break;
}
return 0 ;
}
static inline int F_100 ( int V_329 )
{
switch ( V_329 ) {
case V_337 :
return V_338 ;
case V_339 :
return V_340 ;
case V_341 :
return V_342 ;
case V_343 :
return V_344 ;
default:
F_11 ( L_3 , V_329 ) ;
break;
}
return 0 ;
}
static int F_101 ( struct V_143 * V_166 , const struct V_345 * V_346 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
V_8 = F_75 ( V_166 ) ;
if ( F_94 ( V_8 ) )
return F_95 ( V_8 ) ;
V_59 = (struct V_58 * ) V_8 -> V_61 ;
V_59 -> V_322 = V_29 ;
V_59 -> V_323 = F_100 ( V_346 -> V_329 ) ;
V_59 -> V_146 = F_54 ( V_166 -> V_196 . V_134 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_325 = 0 ;
V_59 -> V_62 = V_346 -> V_306 ;
V_59 -> V_326 = V_346 -> V_347 ;
F_34 ( V_8 , V_53 , NULL , F_102 ( V_166 ) ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_166 ;
int V_23 ;
struct V_345 V_346 ;
V_166 = F_77 ( V_10 , V_59 , V_109 ) ;
if ( F_94 ( V_166 ) )
return F_95 ( V_166 ) ;
F_104 ( V_166 ) ;
if ( V_59 -> V_323 == V_340 )
V_23 = F_105 ( V_166 ) ;
else
V_23 = F_106 ( V_166 ) ;
F_107 ( V_166 , V_23 ? 0 : 1 , true ) ;
if ( V_23 < 0 ) {
V_166 -> V_200 . V_201 = V_307 ;
F_108 ( V_166 ) ;
goto V_35;
}
if ( V_59 -> V_323 == V_340 )
V_346 . V_329 = V_339 ;
else
V_346 . V_329 = V_341 ;
V_346 . V_306 = V_59 -> V_62 ;
V_346 . V_347 = V_59 -> V_326 ;
F_109 ( V_166 , & V_346 ) ;
V_35:
F_87 ( V_166 ) ;
return V_23 ;
}
static int F_110 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_166 ;
struct V_345 V_346 ;
int V_23 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_70 ;
V_166 = F_60 ( V_10 , V_59 , V_109 ) ;
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
V_346 . V_306 = V_59 -> V_62 ;
V_346 . V_347 = V_59 -> V_326 ;
V_346 . V_329 = V_337 ;
F_109 ( V_166 , & V_346 ) ;
V_35:
F_114 ( V_166 , V_23 ? 0 : 1 , true ) ;
F_87 ( V_166 ) ;
return V_23 ;
}
static int F_115 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
T_8 V_134 ;
struct V_41 * V_348 ;
struct V_58 * V_310 ;
struct V_143 * V_166 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_70 ;
V_166 = F_60 ( V_10 , V_59 , V_109 ) ;
if ( V_166 == NULL )
return - V_49 ;
V_348 = F_75 ( V_166 ) ;
V_134 = V_166 -> V_196 . V_134 ;
F_87 ( V_166 ) ;
if ( F_94 ( V_348 ) )
return F_95 ( V_348 ) ;
V_310 = (struct V_58 * ) V_348 -> V_61 ;
V_310 -> V_322 = V_59 -> V_322 ;
V_310 -> V_323 = V_349 ;
V_310 -> V_146 = F_54 ( V_134 ) ;
V_310 -> V_63 = 0 ;
V_310 -> V_325 = 0 ;
V_310 -> V_62 = V_59 -> V_62 ;
V_310 -> V_326 = V_59 -> V_326 ;
F_34 ( V_348 , V_57 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static struct V_41 * F_116 ( const struct V_58 * V_65 ,
T_1 V_43 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
int V_83 , V_350 , V_351 , V_352 ;
V_350 = F_117 () ;
if ( V_350 ) {
V_350 *= sizeof( struct V_353 ) ;
V_350 += sizeof( struct V_354 ) ;
}
V_351 = F_118 () ;
if ( V_351 ) {
V_351 *= sizeof( struct V_353 ) ;
V_351 += sizeof( struct V_354 ) ;
}
V_83 = V_351 + V_350 + sizeof( struct V_58 ) ;
V_8 = F_41 ( V_83 + 16 , V_43 ) ;
if ( ! V_8 )
goto V_355;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( * V_59 ) ) ;
F_39 ( V_59 , V_65 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_72 = V_83 / sizeof( V_73 ) ;
if ( V_350 ) {
struct V_354 * V_76 ;
struct V_353 * V_356 ;
V_76 = (struct V_354 * ) F_43 ( V_8 , V_350 ) ;
V_356 = (struct V_353 * ) ( V_76 + 1 ) ;
V_76 -> V_357 = V_350 / sizeof( V_73 ) ;
V_76 -> V_358 = V_359 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
struct V_211 * V_187 = F_119 ( V_352 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( V_187 -> V_360 )
* V_356 ++ = V_187 -> V_215 ;
}
}
if ( V_351 ) {
struct V_354 * V_76 ;
struct V_353 * V_356 ;
V_76 = (struct V_354 * ) F_43 ( V_8 , V_351 ) ;
V_356 = (struct V_353 * ) ( V_76 + 1 ) ;
V_76 -> V_357 = V_351 / sizeof( V_73 ) ;
V_76 -> V_358 = V_361 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
struct V_211 * V_189 = F_120 ( V_352 ) ;
if ( ! V_189 )
break;
if ( ! V_189 -> V_214 )
continue;
if ( V_189 -> V_360 )
* V_356 ++ = V_189 -> V_215 ;
}
}
V_355:
return V_8 ;
}
static int F_121 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_362 ;
if ( V_59 -> V_146 > V_363 )
return - V_70 ;
if ( V_59 -> V_146 != V_126 ) {
if ( V_6 -> V_56 & ( 1 << V_59 -> V_146 ) )
return - V_364 ;
V_6 -> V_56 |= ( 1 << V_59 -> V_146 ) ;
}
F_122 () ;
V_362 = F_116 ( V_59 , V_33 ) ;
if ( ! V_362 ) {
if ( V_59 -> V_146 != V_126 )
V_6 -> V_56 &= ~ ( 1 << V_59 -> V_146 ) ;
return - V_44 ;
}
F_34 ( V_362 , V_55 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_123 ( struct V_2 * V_3 , const struct V_58 * V_365 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
V_8 = F_41 ( sizeof( struct V_58 ) + 16 , V_52 ) ;
if ( ! V_8 )
return - V_44 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
memcpy ( V_59 , V_365 , sizeof( struct V_58 ) ) ;
V_59 -> V_63 = ( V_71 ) 0 ;
V_59 -> V_72 = ( sizeof( struct V_58 ) / sizeof( V_73 ) ) ;
return F_34 ( V_8 , V_57 , V_3 , F_7 ( V_3 ) ) ;
}
static int F_124 ( const struct V_345 * V_346 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
V_8 = F_41 ( sizeof( struct V_58 ) + 16 , V_52 ) ;
if ( ! V_8 )
return - V_44 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_146 = F_54 ( V_346 -> V_61 . V_134 ) ;
V_59 -> V_323 = V_366 ;
V_59 -> V_62 = V_346 -> V_306 ;
V_59 -> V_326 = V_346 -> V_347 ;
V_59 -> V_322 = V_29 ;
V_59 -> V_63 = ( V_71 ) 0 ;
V_59 -> V_72 = ( sizeof( struct V_58 ) / sizeof( V_73 ) ) ;
V_59 -> V_325 = 0 ;
F_34 ( V_8 , V_53 , NULL , V_346 -> V_10 ) ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_134 ;
struct V_345 V_346 ;
int V_23 , V_50 ;
V_134 = F_53 ( V_59 -> V_146 ) ;
if ( V_134 == 0 )
return - V_70 ;
V_23 = F_126 ( V_10 , V_134 , true ) ;
V_50 = F_123 ( V_3 , V_59 ) ;
if ( V_23 || V_50 ) {
if ( V_23 == - V_49 )
V_23 = 0 ;
return V_23 ? V_23 : V_50 ;
}
V_346 . V_61 . V_134 = V_134 ;
V_346 . V_306 = V_59 -> V_62 ;
V_346 . V_347 = V_59 -> V_326 ;
V_346 . V_329 = V_367 ;
V_346 . V_10 = V_10 ;
F_109 ( NULL , & V_346 ) ;
return 0 ;
}
static int F_127 ( struct V_143 * V_166 , int V_368 , void * V_369 )
{
struct V_1 * V_6 = V_369 ;
struct V_41 * V_348 ;
struct V_58 * V_310 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_348 = F_75 ( V_166 ) ;
if ( F_94 ( V_348 ) )
return F_95 ( V_348 ) ;
V_310 = (struct V_58 * ) V_348 -> V_61 ;
V_310 -> V_322 = V_6 -> V_7 . V_370 ;
V_310 -> V_323 = V_371 ;
V_310 -> V_146 = F_54 ( V_166 -> V_196 . V_134 ) ;
V_310 -> V_63 = 0 ;
V_310 -> V_325 = 0 ;
V_310 -> V_62 = V_368 + 1 ;
V_310 -> V_326 = V_6 -> V_7 . V_372 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_57 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_348 ;
return 0 ;
}
static int F_128 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return F_129 ( V_10 , & V_6 -> V_7 . V_373 . V_201 , F_127 , ( void * ) V_6 ) ;
}
static void F_130 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
F_131 ( & V_6 -> V_7 . V_373 . V_201 , V_10 ) ;
}
static int F_132 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
T_7 V_134 ;
struct V_374 * V_375 = NULL ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_376 ;
V_134 = F_53 ( V_59 -> V_146 ) ;
if ( V_134 == 0 )
return - V_70 ;
if ( V_109 [ V_377 - 1 ] ) {
struct V_378 * V_379 = V_109 [ V_377 - 1 ] ;
V_375 = F_50 ( sizeof( * V_375 ) , V_33 ) ;
if ( V_375 == NULL )
return - V_31 ;
memcpy ( & V_375 -> V_186 , & V_379 -> V_380 ,
sizeof( T_4 ) ) ;
memcpy ( & V_375 -> V_253 , & V_379 -> V_381 ,
sizeof( T_4 ) ) ;
V_375 -> V_135 = V_379 -> V_382 ;
V_375 -> V_383 = V_379 -> V_384 ;
V_375 -> V_385 = V_379 -> V_386 ;
}
V_6 -> V_7 . V_370 = V_59 -> V_322 ;
V_6 -> V_7 . V_372 = V_59 -> V_326 ;
V_6 -> V_7 . V_7 = F_128 ;
V_6 -> V_7 . V_9 = F_130 ;
F_133 ( & V_6 -> V_7 . V_373 . V_201 , V_134 , V_375 ) ;
return F_38 ( V_6 ) ;
}
static int F_134 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_125 = V_59 -> V_146 ;
bool V_387 = false ;
if ( V_59 -> V_72 == ( sizeof( * V_59 ) / sizeof( V_73 ) ) ) {
V_387 = true ;
if ( V_125 != 0 && V_125 != 1 )
return - V_70 ;
V_6 -> V_51 = V_125 ;
}
if ( V_387 && F_135 ( V_8 ) )
V_8 = F_136 ( V_8 , V_33 ) ;
else
V_8 = F_31 ( V_8 , V_33 ) ;
if ( V_387 && V_8 ) {
struct V_58 * V_388 = (struct V_58 * ) V_8 -> V_61 ;
V_388 -> V_63 = 0 ;
}
F_34 ( V_8 , V_53 , NULL , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_137 ( struct V_389 * V_390 , int V_391 , int V_368 , void * V_369 )
{
int V_352 ;
T_6 V_271 = * ( T_6 * ) V_369 ;
for ( V_352 = 0 ; V_352 < V_390 -> V_392 ; V_352 ++ ) {
if ( V_390 -> V_393 [ V_352 ] . V_271 == V_271 )
return - V_364 ;
}
return 0 ;
}
static T_6 F_138 ( struct V_10 * V_10 )
{
struct V_394 V_395 ;
T_6 V_396 ;
int V_60 ;
static T_6 V_271 = V_397 ;
V_396 = V_271 ;
do {
++ V_271 ;
if ( V_271 == 0 )
V_271 = V_397 + 1 ;
F_139 ( & V_395 , V_398 ) ;
V_60 = V_394 ( V_10 , & V_395 , F_137 , ( void * ) & V_271 ) ;
F_140 ( & V_395 , V_10 ) ;
if ( V_60 != - V_364 )
return V_271 ;
} while ( V_271 != V_396 );
return 0 ;
}
static int
F_141 ( struct V_389 * V_390 , struct V_399 * V_400 )
{
struct V_10 * V_10 = F_142 ( V_390 ) ;
struct V_401 * V_402 = V_390 -> V_393 + V_390 -> V_392 ;
int V_149 ;
if ( V_390 -> V_392 >= V_403 )
return - V_404 ;
if ( V_400 -> V_405 == 0 )
return - V_70 ;
V_402 -> V_196 . V_134 = V_400 -> V_406 ;
if ( ( V_149 = F_65 ( V_400 -> V_405 ) ) < 0 )
return - V_70 ;
V_402 -> V_149 = V_149 ;
if ( V_400 -> V_407 == V_408 )
V_402 -> V_409 = 1 ;
else if ( V_400 -> V_407 == V_410 ) {
V_402 -> V_271 = V_400 -> V_411 ;
if ( V_402 -> V_271 > V_397 )
V_402 -> V_271 = 0 ;
if ( ! V_402 -> V_271 && ! ( V_402 -> V_271 = F_138 ( V_10 ) ) )
return - V_44 ;
}
if ( V_402 -> V_149 == V_152 ) {
T_7 * V_136 = ( T_7 * ) ( V_400 + 1 ) ;
int V_135 , V_412 ;
V_135 = F_58 ( (struct V_77 * ) V_136 ,
& V_402 -> V_186 ) ;
if ( ! V_135 )
return - V_70 ;
V_412 = F_57 ( V_135 ) ;
if ( F_58 ( (struct V_77 * ) ( V_136 + V_412 ) ,
& V_402 -> V_196 . V_253 ) != V_135 )
return - V_70 ;
V_402 -> V_413 = V_135 ;
} else
V_402 -> V_413 = V_390 -> V_135 ;
V_402 -> V_414 = 1 ;
V_390 -> V_392 ++ ;
return 0 ;
}
static int
F_143 ( struct V_389 * V_390 , struct V_415 * V_416 )
{
int V_23 ;
int V_83 = V_416 -> V_417 * 8 - sizeof( struct V_415 ) ;
struct V_399 * V_400 = ( void * ) ( V_416 + 1 ) ;
if ( V_416 -> V_417 * 8 < sizeof( struct V_415 ) )
return - V_70 ;
while ( V_83 >= sizeof( struct V_399 ) ) {
if ( ( V_23 = F_141 ( V_390 , V_400 ) ) < 0 )
return V_23 ;
V_83 -= V_400 -> V_418 ;
V_400 = ( void * ) ( ( T_7 * ) V_400 + V_400 -> V_418 ) ;
}
return 0 ;
}
static inline int F_144 ( const struct V_389 * V_390 )
{
struct V_175 * V_176 = V_390 -> V_184 ;
if ( V_176 ) {
int V_83 = sizeof( struct V_89 ) ;
V_83 += V_176 -> V_104 ;
return F_63 ( V_83 ) ;
}
return 0 ;
}
static int F_145 ( const struct V_389 * V_390 )
{
const struct V_401 * V_402 ;
int V_180 = F_62 ( V_390 -> V_135 ) ;
int V_412 = 0 ;
int V_352 ;
for ( V_352 = 0 ; V_352 < V_390 -> V_392 ; V_352 ++ ) {
V_402 = V_390 -> V_393 + V_352 ;
V_412 += F_57 ( V_402 -> V_413 ) ;
}
return sizeof( struct V_58 ) +
( sizeof( struct V_169 ) * 3 ) +
( sizeof( struct V_75 ) * 2 ) +
( V_180 * 2 ) +
sizeof( struct V_415 ) +
( V_390 -> V_392 * sizeof( struct V_399 ) ) +
( V_412 * 2 ) +
F_144 ( V_390 ) ;
}
static struct V_41 * F_146 ( const struct V_389 * V_390 )
{
struct V_41 * V_8 ;
int V_177 ;
V_177 = F_145 ( V_390 ) ;
V_8 = F_41 ( V_177 + 16 , V_52 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
return V_8 ;
}
static int F_147 ( struct V_41 * V_8 , const struct V_389 * V_390 , int V_391 )
{
struct V_58 * V_59 ;
struct V_75 * V_78 ;
struct V_169 * V_170 ;
struct V_415 * V_416 ;
struct V_89 * V_90 ;
struct V_175 * V_176 ;
int V_352 ;
int V_177 ;
int V_180 = F_62 ( V_390 -> V_135 ) ;
int V_412 = F_57 ( V_390 -> V_135 ) ;
V_177 = F_145 ( V_390 ) ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
memset ( V_59 , 0 , V_177 ) ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_120 ;
V_78 -> V_251 = F_56 ( V_390 -> V_419 . V_134 ) ;
V_78 -> V_87 = V_390 -> V_419 . V_254 ;
V_78 -> V_252 = 0 ;
if ( ! F_66 ( & V_390 -> V_419 . V_186 ,
V_390 -> V_419 . V_255 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_390 -> V_135 ) )
F_74 () ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_180 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_180 ) /
sizeof( V_73 ) ;
V_78 -> V_250 = V_121 ;
V_78 -> V_251 = F_56 ( V_390 -> V_419 . V_134 ) ;
V_78 -> V_87 = V_390 -> V_419 . V_420 ;
V_78 -> V_252 = 0 ;
F_66 ( & V_390 -> V_419 . V_253 , V_390 -> V_419 . V_421 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_390 -> V_135 ) ;
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_227 =
sizeof( struct V_169 ) / sizeof( V_73 ) ;
V_170 -> V_228 = V_229 ;
V_170 -> V_230 = F_73 ( V_390 -> V_231 . V_232 ) ;
V_170 -> V_233 = F_73 ( V_390 -> V_231 . V_234 ) ;
V_170 -> V_235 = V_390 -> V_231 . V_236 ;
V_170 -> V_237 = V_390 -> V_231 . V_238 ;
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_227 =
sizeof( struct V_169 ) / sizeof( V_73 ) ;
V_170 -> V_228 = V_239 ;
V_170 -> V_230 = F_73 ( V_390 -> V_231 . V_240 ) ;
V_170 -> V_233 = F_73 ( V_390 -> V_231 . V_241 ) ;
V_170 -> V_235 = V_390 -> V_231 . V_242 ;
V_170 -> V_237 = V_390 -> V_231 . V_243 ;
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_227 =
sizeof( struct V_169 ) / sizeof( V_73 ) ;
V_170 -> V_228 = V_244 ;
V_170 -> V_230 = V_390 -> V_245 . V_246 ;
V_170 -> V_233 = V_390 -> V_245 . V_247 ;
V_170 -> V_235 = V_390 -> V_245 . V_248 ;
V_170 -> V_237 = V_390 -> V_245 . V_249 ;
V_416 = (struct V_415 * ) F_43 ( V_8 , sizeof( struct V_415 ) ) ;
V_416 -> V_417 = sizeof( struct V_415 ) / sizeof( V_73 ) ;
V_416 -> V_422 = V_423 ;
V_416 -> V_424 = V_425 ;
if ( V_390 -> V_426 == V_427 ) {
if ( V_390 -> V_392 )
V_416 -> V_424 = V_428 ;
else
V_416 -> V_424 = V_429 ;
}
V_416 -> V_430 = V_391 + 1 ;
V_416 -> V_431 = 0 ;
V_416 -> V_432 = V_390 -> V_433 ;
V_416 -> V_434 = V_390 -> V_435 ;
for ( V_352 = 0 ; V_352 < V_390 -> V_392 ; V_352 ++ ) {
const struct V_401 * V_402 = V_390 -> V_393 + V_352 ;
struct V_399 * V_400 ;
int V_436 ;
int V_149 ;
V_436 = sizeof( struct V_399 ) ;
if ( V_402 -> V_149 == V_152 ) {
V_412 = F_57 ( V_402 -> V_413 ) ;
V_436 += V_412 * 2 ;
} else {
V_177 -= 2 * V_412 ;
}
V_400 = ( void * ) F_43 ( V_8 , V_436 ) ;
V_416 -> V_417 += V_436 / 8 ;
memset ( V_400 , 0 , sizeof( * V_400 ) ) ;
V_400 -> V_418 = V_436 ;
V_400 -> V_406 = V_402 -> V_196 . V_134 ;
if ( ( V_149 = F_64 ( V_402 -> V_149 ) ) < 0 )
return - V_70 ;
V_400 -> V_405 = V_149 ;
V_400 -> V_407 = V_437 ;
if ( V_402 -> V_271 )
V_400 -> V_407 = V_410 ;
if ( V_402 -> V_409 )
V_400 -> V_407 = V_408 ;
V_400 -> V_411 = V_402 -> V_271 ;
if ( V_402 -> V_149 == V_152 ) {
T_7 * V_136 = ( void * ) ( V_400 + 1 ) ;
F_66 ( & V_402 -> V_186 , 0 ,
(struct V_77 * ) V_136 ,
V_402 -> V_413 ) ;
F_66 ( & V_402 -> V_196 . V_253 , 0 ,
(struct V_77 * ) ( V_136 + V_412 ) ,
V_402 -> V_413 ) ;
}
}
if ( ( V_176 = V_390 -> V_184 ) ) {
int V_97 = F_144 ( V_390 ) ;
V_90 = (struct V_89 * ) F_43 ( V_8 , V_97 ) ;
V_90 -> V_93 = V_97 / sizeof( V_73 ) ;
V_90 -> V_99 = V_124 ;
V_90 -> V_101 = V_176 -> V_100 ;
V_90 -> V_103 = V_176 -> V_102 ;
V_90 -> V_91 = V_176 -> V_104 ;
memcpy ( V_90 + 1 , V_176 -> V_287 ,
V_176 -> V_104 ) ;
}
V_59 -> V_72 = V_177 / sizeof( V_73 ) ;
V_59 -> V_325 = F_3 ( & V_390 -> V_438 ) ;
return 0 ;
}
static int F_148 ( struct V_389 * V_390 , int V_391 , const struct V_345 * V_346 )
{
struct V_41 * V_348 ;
struct V_58 * V_310 ;
int V_23 ;
V_348 = F_146 ( V_390 ) ;
if ( F_94 ( V_348 ) )
return F_95 ( V_348 ) ;
V_23 = F_147 ( V_348 , V_390 , V_391 ) ;
if ( V_23 < 0 )
return V_23 ;
V_310 = (struct V_58 * ) V_348 -> V_61 ;
V_310 -> V_322 = V_29 ;
if ( V_346 -> V_61 . V_439 && V_346 -> V_329 == V_330 )
V_310 -> V_323 = V_440 ;
else
V_310 -> V_323 = F_99 ( V_346 -> V_329 ) ;
V_310 -> V_63 = 0 ;
V_310 -> V_62 = V_346 -> V_306 ;
V_310 -> V_326 = V_346 -> V_347 ;
F_34 ( V_348 , V_53 , NULL , F_142 ( V_390 ) ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 = 0 ;
struct V_169 * V_170 ;
struct V_75 * V_136 ;
struct V_415 * V_416 ;
struct V_389 * V_390 ;
struct V_345 V_346 ;
struct V_89 * V_90 ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_423 - 1 ] )
return - V_70 ;
V_416 = V_109 [ V_423 - 1 ] ;
if ( V_416 -> V_424 > V_428 )
return - V_70 ;
if ( ! V_416 -> V_430 || V_416 -> V_430 >= V_441 )
return - V_70 ;
V_390 = F_150 ( V_10 , V_33 ) ;
if ( V_390 == NULL )
return - V_44 ;
V_390 -> V_426 = ( V_416 -> V_424 == V_425 ?
V_442 : V_427 ) ;
V_390 -> V_435 = V_416 -> V_434 ;
V_136 = V_109 [ V_120 - 1 ] ;
V_390 -> V_135 = F_59 ( V_136 , & V_390 -> V_419 . V_186 ) ;
V_390 -> V_419 . V_135 = V_390 -> V_135 ;
V_390 -> V_419 . V_254 = V_136 -> V_87 ;
V_390 -> V_419 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_390 -> V_419 . V_255 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_390 -> V_419 . V_255 )
V_390 -> V_419 . V_443 = F_151 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_390 -> V_419 . V_253 ) ;
V_390 -> V_419 . V_420 = V_136 -> V_87 ;
V_390 -> V_419 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_390 -> V_419 . V_421 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_390 -> V_419 . V_421 )
V_390 -> V_419 . V_444 = F_151 ( 0xffff ) ;
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 ) {
V_23 = - V_44 ;
goto V_35;
}
V_23 = F_152 ( & V_390 -> V_184 , V_96 , V_33 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
goto V_35;
}
V_390 -> V_231 . V_241 = V_445 ;
V_390 -> V_231 . V_234 = V_445 ;
V_390 -> V_231 . V_240 = V_445 ;
V_390 -> V_231 . V_232 = V_445 ;
if ( ( V_170 = V_109 [ V_229 - 1 ] ) != NULL ) {
V_390 -> V_231 . V_232 = F_80 ( V_170 -> V_230 ) ;
V_390 -> V_231 . V_234 = F_80 ( V_170 -> V_233 ) ;
V_390 -> V_231 . V_236 = V_170 -> V_235 ;
V_390 -> V_231 . V_238 = V_170 -> V_237 ;
}
if ( ( V_170 = V_109 [ V_239 - 1 ] ) != NULL ) {
V_390 -> V_231 . V_240 = F_80 ( V_170 -> V_230 ) ;
V_390 -> V_231 . V_241 = F_80 ( V_170 -> V_233 ) ;
V_390 -> V_231 . V_242 = V_170 -> V_235 ;
V_390 -> V_231 . V_243 = V_170 -> V_237 ;
}
V_390 -> V_392 = 0 ;
if ( V_416 -> V_424 == V_428 &&
( V_23 = F_143 ( V_390 , V_416 ) ) < 0 )
goto V_35;
V_23 = F_153 ( V_416 -> V_430 - 1 , V_390 ,
V_59 -> V_323 != V_335 ) ;
F_154 ( V_390 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
if ( V_59 -> V_323 == V_335 )
V_346 . V_329 = V_334 ;
else
V_346 . V_329 = V_332 ;
V_346 . V_306 = V_59 -> V_62 ;
V_346 . V_347 = V_59 -> V_326 ;
F_155 ( V_390 , V_416 -> V_430 - 1 , & V_346 ) ;
F_156 ( V_390 ) ;
return 0 ;
V_35:
V_390 -> V_395 . V_446 = 1 ;
F_157 ( V_390 ) ;
return V_23 ;
}
static int F_158 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 ;
struct V_75 * V_136 ;
struct V_415 * V_416 ;
struct V_389 * V_390 ;
struct V_447 V_185 ;
struct V_345 V_346 ;
struct V_89 * V_90 ;
struct V_175 * V_448 = NULL ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_423 - 1 ] )
return - V_70 ;
V_416 = V_109 [ V_423 - 1 ] ;
if ( ! V_416 -> V_430 || V_416 -> V_430 >= V_441 )
return - V_70 ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ;
V_185 . V_135 = F_59 ( V_136 , & V_185 . V_186 ) ;
V_185 . V_254 = V_136 -> V_87 ;
V_185 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_185 . V_255 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_185 . V_255 )
V_185 . V_443 = F_151 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_185 . V_253 ) ;
V_185 . V_420 = V_136 -> V_87 ;
V_185 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_185 . V_421 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_185 . V_421 )
V_185 . V_444 = F_151 ( 0xffff ) ;
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 )
return - V_31 ;
V_23 = F_152 ( & V_448 , V_96 , V_33 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
return V_23 ;
}
V_390 = F_159 ( V_10 , V_147 , V_398 ,
V_416 -> V_430 - 1 , & V_185 , V_448 ,
1 , & V_23 ) ;
F_160 ( V_448 ) ;
if ( V_390 == NULL )
return - V_318 ;
F_161 ( V_390 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
V_346 . V_306 = V_59 -> V_62 ;
V_346 . V_347 = V_59 -> V_326 ;
V_346 . V_61 . V_439 = 0 ;
V_346 . V_329 = V_330 ;
F_155 ( V_390 , V_416 -> V_430 - 1 , & V_346 ) ;
V_35:
F_156 ( V_390 ) ;
if ( V_23 == 0 )
F_162 ( V_10 ) ;
return V_23 ;
}
static int F_163 ( struct V_2 * V_3 , struct V_389 * V_390 , const struct V_58 * V_59 , int V_391 )
{
int V_23 ;
struct V_41 * V_348 ;
struct V_58 * V_310 ;
V_23 = 0 ;
V_348 = F_146 ( V_390 ) ;
if ( F_94 ( V_348 ) ) {
V_23 = F_95 ( V_348 ) ;
goto V_35;
}
V_23 = F_147 ( V_348 , V_390 , V_391 ) ;
if ( V_23 < 0 )
goto V_35;
V_310 = (struct V_58 * ) V_348 -> V_61 ;
V_310 -> V_322 = V_59 -> V_322 ;
V_310 -> V_323 = V_59 -> V_323 ;
V_310 -> V_146 = 0 ;
V_310 -> V_63 = 0 ;
V_310 -> V_62 = V_59 -> V_62 ;
V_310 -> V_326 = V_59 -> V_326 ;
F_34 ( V_348 , V_57 , V_3 , F_142 ( V_390 ) ) ;
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
int V_449 , V_412 ;
if ( V_113 < F_164 ( V_136 -> V_84 ) )
return - V_70 ;
V_449 = F_58 ( V_136 , V_186 ) ;
if ( ! V_449 )
return - V_70 ;
V_412 = F_57 ( V_449 ) ;
if ( F_58 ( (struct V_77 * ) ( ( ( T_7 * ) V_136 ) + V_412 ) ,
V_253 ) != V_449 )
return - V_70 ;
* V_135 = V_449 ;
return 0 ;
}
static int F_166 ( struct V_399 * V_450 , int V_83 ,
struct V_451 * V_452 )
{
int V_23 ;
struct V_399 * V_453 ;
int V_149 ;
if ( V_83 <= sizeof( struct V_399 ) ||
V_83 < V_450 -> V_418 )
return - V_70 ;
V_23 = F_165 ( (struct V_77 * ) ( V_450 + 1 ) ,
V_450 -> V_418 ,
& V_452 -> V_454 , & V_452 -> V_455 ,
& V_452 -> V_456 ) ;
if ( V_23 )
return V_23 ;
V_453 = (struct V_399 * ) ( ( T_7 * ) V_450 + V_450 -> V_418 ) ;
V_83 -= V_450 -> V_418 ;
if ( V_83 <= sizeof( struct V_399 ) ||
V_83 < V_453 -> V_418 )
return - V_70 ;
V_23 = F_165 ( (struct V_77 * ) ( V_453 + 1 ) ,
V_453 -> V_418 ,
& V_452 -> V_457 , & V_452 -> V_458 ,
& V_452 -> V_459 ) ;
if ( V_23 )
return V_23 ;
if ( V_450 -> V_406 != V_453 -> V_406 ||
V_450 -> V_405 != V_453 -> V_405 ||
V_450 -> V_411 != V_453 -> V_411 )
return - V_70 ;
V_452 -> V_134 = V_450 -> V_406 ;
if ( ( V_149 = F_65 ( V_450 -> V_405 ) ) < 0 )
return - V_70 ;
V_452 -> V_149 = V_149 ;
V_452 -> V_271 = V_450 -> V_411 ;
return ( ( int ) ( V_450 -> V_418 +
V_453 -> V_418 ) ) ;
}
static int F_167 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_58 * V_59 , void * const * V_109 )
{
int V_352 , V_83 , V_460 , V_23 = - V_70 ;
T_7 V_391 ;
struct V_75 * V_136 ;
struct V_461 * V_462 ;
struct V_415 * V_416 ;
struct V_399 * V_400 ;
struct V_447 V_185 ;
struct V_451 V_452 [ V_403 ] ;
struct V_463 V_464 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_423 - 1 ] ) {
V_23 = - V_70 ;
goto V_35;
}
V_462 = V_109 [ V_465 - 1 ] ;
V_416 = V_109 [ V_423 - 1 ] ;
if ( V_416 -> V_430 >= V_441 ) {
V_23 = - V_70 ;
goto V_35;
}
if ( V_462 ) {
V_464 . V_466 = V_462 -> V_467 ;
V_460 = F_165 ( (struct V_77 * ) ( V_462 + 1 ) ,
8 * ( V_462 -> V_468 ) - sizeof( * V_462 ) ,
& V_464 . V_469 , & V_464 . V_470 , & V_464 . V_135 ) ;
if ( V_460 < 0 ) {
V_23 = V_460 ;
goto V_35;
}
}
V_391 = V_416 -> V_430 - 1 ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ;
V_185 . V_135 = F_59 ( V_136 , & V_185 . V_186 ) ;
V_185 . V_254 = V_136 -> V_87 ;
V_185 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_185 . V_255 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_185 . V_255 )
V_185 . V_443 = F_151 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_185 . V_253 ) ;
V_185 . V_420 = V_136 -> V_87 ;
V_185 . V_134 = F_55 ( V_136 -> V_251 ) ;
V_185 . V_421 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_185 . V_421 )
V_185 . V_444 = F_151 ( 0xffff ) ;
V_400 = (struct V_399 * ) ( V_416 + 1 ) ;
V_352 = 0 ;
V_83 = V_416 -> V_417 * 8 - sizeof( struct V_415 ) ;
while ( V_83 > 0 && V_352 < V_403 ) {
V_460 = F_166 ( V_400 , V_83 , & V_452 [ V_352 ] ) ;
if ( V_460 < 0 ) {
V_23 = V_460 ;
goto V_35;
} else {
V_400 = (struct V_399 * ) ( ( T_7 * ) V_400 + V_460 ) ;
V_83 -= V_460 ;
V_352 ++ ;
}
}
if ( ! V_352 || V_83 > 0 ) {
V_23 = - V_70 ;
goto V_35;
}
return V_451 ( & V_185 , V_391 , V_398 , V_452 , V_352 ,
V_462 ? & V_464 : NULL , V_10 ) ;
V_35:
return V_23 ;
}
static int F_167 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_58 * V_59 , void * const * V_109 )
{
return - V_471 ;
}
static int F_168 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_391 ;
int V_23 = 0 , V_472 ;
struct V_415 * V_416 ;
struct V_389 * V_390 ;
struct V_345 V_346 ;
if ( ( V_416 = V_109 [ V_423 - 1 ] ) == NULL )
return - V_70 ;
V_391 = F_169 ( V_416 -> V_432 ) ;
if ( V_391 >= V_473 )
return - V_70 ;
V_472 = ( V_59 -> V_323 == V_440 ) ;
V_390 = F_170 ( V_10 , V_147 , V_398 ,
V_391 , V_416 -> V_432 , V_472 , & V_23 ) ;
if ( V_390 == NULL )
return - V_318 ;
if ( V_472 ) {
F_161 ( V_390 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
V_346 . V_306 = V_59 -> V_62 ;
V_346 . V_347 = V_59 -> V_326 ;
V_346 . V_61 . V_439 = 1 ;
V_346 . V_329 = V_330 ;
F_155 ( V_390 , V_391 , & V_346 ) ;
} else {
V_23 = F_163 ( V_3 , V_390 , V_59 , V_391 ) ;
}
V_35:
F_156 ( V_390 ) ;
if ( V_472 && V_23 == 0 )
F_162 ( V_10 ) ;
return V_23 ;
}
static int F_171 ( struct V_389 * V_390 , int V_391 , int V_368 , void * V_369 )
{
struct V_1 * V_6 = V_369 ;
struct V_41 * V_348 ;
struct V_58 * V_310 ;
int V_23 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_348 = F_146 ( V_390 ) ;
if ( F_94 ( V_348 ) )
return F_95 ( V_348 ) ;
V_23 = F_147 ( V_348 , V_390 , V_391 ) ;
if ( V_23 < 0 )
return V_23 ;
V_310 = (struct V_58 * ) V_348 -> V_61 ;
V_310 -> V_322 = V_6 -> V_7 . V_370 ;
V_310 -> V_323 = V_474 ;
V_310 -> V_146 = V_126 ;
V_310 -> V_63 = 0 ;
V_310 -> V_62 = V_368 + 1 ;
V_310 -> V_326 = V_6 -> V_7 . V_372 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_57 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_348 ;
return 0 ;
}
static int F_172 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return V_394 ( V_10 , & V_6 -> V_7 . V_373 . V_475 , F_171 , ( void * ) V_6 ) ;
}
static void F_173 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( (struct V_2 * ) V_6 ) ;
F_140 ( & V_6 -> V_7 . V_373 . V_475 , V_10 ) ;
}
static int F_174 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_376 ;
V_6 -> V_7 . V_370 = V_59 -> V_322 ;
V_6 -> V_7 . V_372 = V_59 -> V_326 ;
V_6 -> V_7 . V_7 = F_172 ;
V_6 -> V_7 . V_9 = F_173 ;
F_139 ( & V_6 -> V_7 . V_373 . V_475 , V_398 ) ;
return F_38 ( V_6 ) ;
}
static int F_175 ( const struct V_345 * V_346 )
{
struct V_41 * V_476 ;
struct V_58 * V_59 ;
V_476 = F_41 ( sizeof( struct V_58 ) + 16 , V_52 ) ;
if ( ! V_476 )
return - V_44 ;
V_59 = (struct V_58 * ) F_43 ( V_476 , sizeof( struct V_58 ) ) ;
V_59 -> V_323 = V_477 ;
V_59 -> V_62 = V_346 -> V_306 ;
V_59 -> V_326 = V_346 -> V_347 ;
V_59 -> V_322 = V_29 ;
V_59 -> V_63 = ( V_71 ) 0 ;
V_59 -> V_146 = V_126 ;
V_59 -> V_72 = ( sizeof( struct V_58 ) / sizeof( V_73 ) ) ;
V_59 -> V_325 = 0 ;
F_34 ( V_476 , V_53 , NULL , V_346 -> V_10 ) ;
return 0 ;
}
static int F_176 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_345 V_346 ;
int V_23 , V_50 ;
V_23 = F_177 ( V_10 , V_398 , true ) ;
V_50 = F_123 ( V_3 , V_59 ) ;
if ( V_23 || V_50 ) {
if ( V_23 == - V_49 )
return 0 ;
return V_23 ;
}
V_346 . V_61 . type = V_398 ;
V_346 . V_329 = V_478 ;
V_346 . V_347 = V_59 -> V_326 ;
V_346 . V_306 = V_59 -> V_62 ;
V_346 . V_10 = V_10 ;
F_155 ( NULL , 0 , & V_346 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 )
{
void * V_109 [ V_117 ] ;
int V_23 ;
F_34 ( F_31 ( V_8 , V_33 ) ,
V_54 , NULL , F_7 ( V_3 ) ) ;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
V_23 = F_52 ( V_8 , V_59 , V_109 ) ;
if ( ! V_23 ) {
V_23 = - V_308 ;
if ( V_479 [ V_59 -> V_323 ] )
V_23 = V_479 [ V_59 -> V_323 ] ( V_3 , V_8 , V_59 , V_109 ) ;
}
return V_23 ;
}
static struct V_58 * F_179 ( struct V_41 * V_8 , int * V_480 )
{
struct V_58 * V_59 = NULL ;
if ( V_8 -> V_83 < sizeof( * V_59 ) ) {
* V_480 = - V_481 ;
} else {
V_59 = (struct V_58 * ) V_8 -> V_61 ;
if ( V_59 -> V_322 != V_29 ||
V_59 -> V_325 != 0 ||
( V_59 -> V_323 <= V_482 ||
V_59 -> V_323 > V_483 ) ) {
V_59 = NULL ;
* V_480 = - V_70 ;
} else if ( V_59 -> V_72 != ( V_8 -> V_83 /
sizeof( V_73 ) ) ||
V_59 -> V_72 < ( sizeof( struct V_58 ) /
sizeof( V_73 ) ) ) {
V_59 = NULL ;
* V_480 = - V_481 ;
} else {
* V_480 = 0 ;
}
}
return V_59 ;
}
static inline int F_180 ( const struct V_401 * V_402 ,
const struct V_211 * V_484 )
{
unsigned int V_196 = V_484 -> V_215 . V_216 ;
if ( V_196 >= sizeof( V_402 -> V_485 ) * 8 )
return 0 ;
return ( V_402 -> V_485 >> V_196 ) & 1 ;
}
static inline int F_181 ( const struct V_401 * V_402 ,
const struct V_211 * V_484 )
{
unsigned int V_196 = V_484 -> V_215 . V_216 ;
if ( V_196 >= sizeof( V_402 -> V_486 ) * 8 )
return 0 ;
return ( V_402 -> V_486 >> V_196 ) & 1 ;
}
static int F_182 ( const struct V_401 * V_402 )
{
int V_352 , V_487 = 0 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_211 * V_187 = F_119 ( V_352 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( F_180 ( V_402 , V_187 ) && V_187 -> V_360 )
V_487 += sizeof( struct V_488 ) ;
}
return V_487 + sizeof( struct V_489 ) ;
}
static int F_183 ( const struct V_401 * V_402 )
{
int V_352 , V_464 , V_487 = 0 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_211 * V_189 = F_120 ( V_352 ) ;
if ( ! V_189 )
break;
if ( ! V_189 -> V_214 )
continue;
if ( ! ( F_181 ( V_402 , V_189 ) && V_189 -> V_360 ) )
continue;
for ( V_464 = 1 ; ; V_464 ++ ) {
const struct V_211 * V_187 = F_119 ( V_464 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( F_180 ( V_402 , V_187 ) && V_187 -> V_360 )
V_487 += sizeof( struct V_488 ) ;
}
}
return V_487 + sizeof( struct V_489 ) ;
}
static void F_184 ( struct V_41 * V_8 , const struct V_401 * V_402 )
{
struct V_489 * V_74 ;
int V_352 ;
V_74 = (struct V_489 * ) F_43 ( V_8 , sizeof( struct V_489 ) ) ;
V_74 -> V_490 = sizeof( struct V_489 ) / 8 ;
V_74 -> V_491 = V_492 ;
V_74 -> V_493 = 32 ;
memset ( V_74 -> V_494 , 0 , sizeof( V_74 -> V_494 ) ) ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_211 * V_187 = F_119 ( V_352 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( F_180 ( V_402 , V_187 ) && V_187 -> V_360 ) {
struct V_488 * V_346 ;
V_346 = (struct V_488 * ) F_43 ( V_8 , sizeof( struct V_488 ) ) ;
memset ( V_346 , 0 , sizeof( * V_346 ) ) ;
V_74 -> V_490 += sizeof( struct V_488 ) / 8 ;
V_346 -> V_495 = V_187 -> V_215 . V_216 ;
V_346 -> V_496 = V_187 -> V_215 . V_497 ;
V_346 -> V_498 = V_187 -> V_215 . V_499 ;
V_346 -> V_500 = 24 * 60 * 60 ;
V_346 -> V_501 = 20 * 60 * 60 ;
V_346 -> V_502 = 8 * 60 * 60 ;
V_346 -> V_503 = 7 * 60 * 60 ;
}
}
}
static void F_185 ( struct V_41 * V_8 , const struct V_401 * V_402 )
{
struct V_489 * V_74 ;
int V_352 , V_464 ;
V_74 = (struct V_489 * ) F_43 ( V_8 , sizeof( struct V_489 ) ) ;
V_74 -> V_490 = sizeof( struct V_489 ) / 8 ;
V_74 -> V_491 = V_492 ;
V_74 -> V_493 = 32 ;
memset ( V_74 -> V_494 , 0 , sizeof( V_74 -> V_494 ) ) ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_211 * V_189 = F_120 ( V_352 ) ;
if ( ! V_189 )
break;
if ( ! V_189 -> V_214 )
continue;
if ( ! ( F_181 ( V_402 , V_189 ) && V_189 -> V_360 ) )
continue;
for ( V_464 = 1 ; ; V_464 ++ ) {
struct V_488 * V_346 ;
const struct V_211 * V_187 = F_119 ( V_464 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_214 )
continue;
if ( ! ( F_180 ( V_402 , V_187 ) && V_187 -> V_360 ) )
continue;
V_346 = (struct V_488 * ) F_43 ( V_8 , sizeof( struct V_488 ) ) ;
memset ( V_346 , 0 , sizeof( * V_346 ) ) ;
V_74 -> V_490 += sizeof( struct V_488 ) / 8 ;
V_346 -> V_495 = V_187 -> V_215 . V_216 ;
V_346 -> V_496 = V_187 -> V_215 . V_497 ;
V_346 -> V_498 = V_187 -> V_215 . V_499 ;
V_346 -> V_504 = V_189 -> V_215 . V_216 ;
V_346 -> V_505 = V_189 -> V_215 . V_497 ;
V_346 -> V_506 = V_189 -> V_215 . V_499 ;
V_346 -> V_500 = 24 * 60 * 60 ;
V_346 -> V_501 = 20 * 60 * 60 ;
V_346 -> V_502 = 8 * 60 * 60 ;
V_346 -> V_503 = 7 * 60 * 60 ;
}
}
}
static int F_186 ( struct V_389 * V_390 , const struct V_345 * V_346 )
{
return 0 ;
}
static int F_187 ( struct V_143 * V_166 , const struct V_345 * V_346 )
{
struct V_41 * V_348 ;
struct V_58 * V_310 ;
int V_507 ;
int V_168 ;
V_507 = V_346 -> V_61 . V_507 ;
if ( V_507 )
V_168 = 2 ;
else
V_168 = 1 ;
V_348 = F_76 ( V_166 , V_168 ) ;
if ( F_94 ( V_348 ) )
return F_95 ( V_348 ) ;
V_310 = (struct V_58 * ) V_348 -> V_61 ;
V_310 -> V_322 = V_29 ;
V_310 -> V_323 = V_344 ;
V_310 -> V_146 = F_54 ( V_166 -> V_196 . V_134 ) ;
V_310 -> V_63 = 0 ;
V_310 -> V_325 = 0 ;
V_310 -> V_62 = 0 ;
V_310 -> V_326 = 0 ;
F_34 ( V_348 , V_55 , NULL , F_102 ( V_166 ) ) ;
return 0 ;
}
static int F_188 ( struct V_143 * V_166 , const struct V_345 * V_346 )
{
struct V_10 * V_10 = V_166 ? F_102 ( V_166 ) : V_346 -> V_10 ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
if ( F_3 ( & V_12 -> V_17 ) == 0 )
return 0 ;
switch ( V_346 -> V_329 ) {
case V_343 :
return F_187 ( V_166 , V_346 ) ;
case V_337 :
case V_339 :
case V_341 :
return F_101 ( V_166 , V_346 ) ;
case V_367 :
return F_124 ( V_346 ) ;
case V_508 :
break;
default:
F_11 ( L_3 , V_346 -> V_329 ) ;
break;
}
return 0 ;
}
static int F_189 ( struct V_389 * V_390 , int V_391 , const struct V_345 * V_346 )
{
if ( V_390 && V_390 -> type != V_398 )
return 0 ;
switch ( V_346 -> V_329 ) {
case V_336 :
return F_186 ( V_390 , V_346 ) ;
case V_330 :
case V_332 :
case V_334 :
return F_148 ( V_390 , V_391 , V_346 ) ;
case V_478 :
if ( V_346 -> V_61 . type != V_398 )
break;
return F_175 ( V_346 ) ;
default:
F_11 ( L_2 , V_346 -> V_329 ) ;
break;
}
return 0 ;
}
static T_6 F_190 ( void )
{
T_6 V_509 ;
static T_10 V_510 ;
do {
V_509 = F_191 ( & V_510 ) ;
} while ( ! V_509 );
return V_509 ;
}
static bool F_192 ( const struct V_345 * V_346 )
{
struct V_11 * V_12 = F_8 ( V_346 -> V_10 , V_13 ) ;
struct V_2 * V_3 ;
bool V_511 = false ;
F_35 () ;
F_36 (sk, &net_pfkey->table) {
if ( F_1 ( V_3 ) -> V_56 ) {
V_511 = true ;
break;
}
}
F_37 () ;
return V_511 ;
}
static int F_193 ( struct V_143 * V_166 , struct V_401 * V_402 , struct V_389 * V_390 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
struct V_75 * V_78 ;
struct V_415 * V_416 ;
int V_180 ;
int V_177 ;
struct V_89 * V_90 ;
struct V_175 * V_176 ;
int V_97 = 0 ;
V_180 = F_62 ( V_166 -> V_183 . V_135 ) ;
if ( ! V_180 )
return - V_70 ;
V_177 = sizeof( struct V_58 ) +
( sizeof( struct V_75 ) * 2 ) +
( V_180 * 2 ) +
sizeof( struct V_415 ) ;
if ( V_166 -> V_196 . V_134 == V_129 )
V_177 += F_182 ( V_402 ) ;
else if ( V_166 -> V_196 . V_134 == V_131 )
V_177 += F_183 ( V_402 ) ;
if ( ( V_176 = V_166 -> V_184 ) ) {
V_97 = F_63 ( V_176 -> V_104 ) ;
V_177 += sizeof( struct V_89 ) + V_97 ;
}
V_8 = F_41 ( V_177 + 16 , V_52 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_322 = V_29 ;
V_59 -> V_323 = V_512 ;
V_59 -> V_146 = F_54 ( V_166 -> V_196 . V_134 ) ;
V_59 -> V_72 = V_177 / sizeof( V_73 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_325 = 0 ;
V_59 -> V_62 = V_166 -> V_200 . V_306 = F_190 () ;
V_59 -> V_326 = 0 ;
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
V_416 = (struct V_415 * ) F_43 ( V_8 , sizeof( struct V_415 ) ) ;
V_416 -> V_417 = sizeof( struct V_415 ) / sizeof( V_73 ) ;
V_416 -> V_422 = V_423 ;
V_416 -> V_424 = V_428 ;
V_416 -> V_430 = V_513 + 1 ;
V_416 -> V_431 = 0 ;
V_416 -> V_432 = V_390 -> V_433 ;
V_416 -> V_434 = V_390 -> V_435 ;
if ( V_166 -> V_196 . V_134 == V_129 )
F_184 ( V_8 , V_402 ) ;
else if ( V_166 -> V_196 . V_134 == V_131 )
F_185 ( V_8 , V_402 ) ;
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
return F_34 ( V_8 , V_55 , NULL , F_102 ( V_166 ) ) ;
}
static struct V_389 * F_194 ( struct V_2 * V_3 , int V_514 ,
T_7 * V_61 , int V_83 , int * V_391 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_389 * V_390 ;
struct V_415 * V_416 = (struct V_415 * ) V_61 ;
struct V_89 * V_90 ;
switch ( V_3 -> V_38 ) {
case V_85 :
if ( V_514 != V_515 ) {
* V_391 = - V_308 ;
return NULL ;
}
break;
#if F_45 ( V_80 )
case V_88 :
if ( V_514 != V_516 ) {
* V_391 = - V_308 ;
return NULL ;
}
break;
#endif
default:
* V_391 = - V_70 ;
return NULL ;
}
* V_391 = - V_70 ;
if ( V_83 < sizeof( struct V_415 ) ||
V_416 -> V_417 * 8 > V_83 ||
V_416 -> V_424 > V_517 ||
( ! V_416 -> V_430 || V_416 -> V_430 > V_518 ) )
return NULL ;
V_390 = F_150 ( V_10 , V_52 ) ;
if ( V_390 == NULL ) {
* V_391 = - V_44 ;
return NULL ;
}
V_390 -> V_426 = ( V_416 -> V_424 == V_425 ?
V_442 : V_427 ) ;
V_390 -> V_231 . V_241 = V_445 ;
V_390 -> V_231 . V_234 = V_445 ;
V_390 -> V_231 . V_240 = V_445 ;
V_390 -> V_231 . V_232 = V_445 ;
V_390 -> V_135 = V_3 -> V_38 ;
V_390 -> V_392 = 0 ;
if ( V_416 -> V_424 == V_428 &&
( * V_391 = F_143 ( V_390 , V_416 ) ) < 0 )
goto V_35;
if ( V_83 >= ( V_416 -> V_417 * 8 +
sizeof( struct V_89 ) ) ) {
char * V_74 = ( char * ) V_416 ;
struct V_94 * V_96 ;
V_74 += V_416 -> V_417 * 8 ;
V_90 = (struct V_89 * ) V_74 ;
if ( V_83 < V_416 -> V_417 * 8 +
V_90 -> V_93 ) {
* V_391 = - V_70 ;
goto V_35;
}
if ( ( * V_391 = F_48 ( V_74 ) ) )
goto V_35;
V_96 = F_49 ( V_90 , V_52 ) ;
* V_391 = F_152 ( & V_390 -> V_184 , V_96 , V_52 ) ;
F_82 ( V_96 ) ;
if ( * V_391 )
goto V_35;
}
* V_391 = V_416 -> V_430 - 1 ;
return V_390 ;
V_35:
V_390 -> V_395 . V_446 = 1 ;
F_157 ( V_390 ) ;
return NULL ;
}
static int F_195 ( struct V_143 * V_166 , T_4 * V_519 , T_5 V_255 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
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
V_177 = sizeof( struct V_58 ) +
sizeof( struct V_144 ) +
( sizeof( struct V_75 ) * 2 ) +
( V_180 * 2 ) +
( sizeof( struct V_193 ) * 2 ) ;
V_8 = F_41 ( V_177 + 16 , V_52 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_322 = V_29 ;
V_59 -> V_323 = V_520 ;
V_59 -> V_146 = V_125 ;
V_59 -> V_72 = V_177 / sizeof( V_73 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_325 = 0 ;
V_59 -> V_62 = V_166 -> V_200 . V_306 = F_190 () ;
V_59 -> V_326 = 0 ;
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
F_66 ( V_519 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_166 -> V_183 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_273 = (struct V_193 * ) F_43 ( V_8 , sizeof ( * V_273 ) ) ;
V_273 -> V_279 = sizeof( * V_273 ) / sizeof( V_73 ) ;
V_273 -> V_280 = V_285 ;
V_273 -> V_282 = V_255 ;
V_273 -> V_284 = 0 ;
return F_34 ( V_8 , V_55 , NULL , F_102 ( V_166 ) ) ;
}
static int F_196 ( struct V_41 * V_8 , int V_521 , int type ,
const struct V_447 * V_185 )
{
struct V_75 * V_78 ;
V_78 = (struct V_75 * ) F_43 ( V_8 , sizeof( struct V_75 ) + V_521 ) ;
V_78 -> V_86 = ( sizeof( struct V_75 ) + V_521 ) / 8 ;
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
V_78 -> V_87 = V_185 -> V_420 ;
F_66 ( & V_185 -> V_253 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_185 -> V_135 ) ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static int F_197 ( struct V_41 * V_8 , const struct V_463 * V_464 )
{
struct V_461 * V_462 ;
T_7 * V_136 ;
int V_135 = V_464 -> V_135 ;
int V_412 = F_57 ( V_135 ) ;
int V_522 ;
V_522 = ( sizeof( struct V_461 ) +
F_164 ( V_135 ) ) ;
V_462 = (struct V_461 * ) F_43 ( V_8 , V_522 ) ;
memset ( V_462 , 0 , V_522 ) ;
V_462 -> V_468 = V_522 / 8 ;
V_462 -> V_523 = V_465 ;
V_462 -> V_467 = V_464 -> V_466 ;
V_136 = ( T_7 * ) ( V_462 + 1 ) ;
if ( ! F_66 ( & V_464 -> V_469 , 0 , (struct V_77 * ) V_136 , V_135 ) ||
! F_66 ( & V_464 -> V_470 , 0 , (struct V_77 * ) ( V_136 + V_412 ) , V_135 ) )
return - V_70 ;
return 0 ;
}
static int F_198 ( struct V_41 * V_8 ,
V_71 V_134 , V_71 V_149 , int V_524 ,
T_11 V_271 , V_71 V_135 ,
const T_4 * V_105 , const T_4 * V_106 )
{
struct V_399 * V_400 ;
T_7 * V_136 ;
int V_412 = F_57 ( V_135 ) ;
int V_522 ;
V_522 = sizeof( struct V_399 ) +
F_164 ( V_135 ) ;
V_400 = (struct V_399 * ) F_43 ( V_8 , V_522 ) ;
memset ( V_400 , 0 , V_522 ) ;
V_400 -> V_418 = V_522 ;
V_400 -> V_406 = V_134 ;
V_400 -> V_405 = V_149 ;
V_400 -> V_407 = V_524 ;
V_400 -> V_411 = V_271 ;
V_136 = ( T_7 * ) ( V_400 + 1 ) ;
if ( ! F_66 ( V_105 , 0 , (struct V_77 * ) V_136 , V_135 ) ||
! F_66 ( V_106 , 0 , (struct V_77 * ) ( V_136 + V_412 ) , V_135 ) )
return - V_70 ;
return 0 ;
}
static int F_199 ( const struct V_447 * V_185 , T_7 V_391 , T_7 type ,
const struct V_451 * V_452 , int V_525 ,
const struct V_463 * V_464 )
{
int V_352 ;
int V_526 ;
int V_177 = 0 ;
int V_527 = 0 ;
struct V_41 * V_8 ;
struct V_58 * V_59 ;
struct V_415 * V_416 ;
const struct V_451 * V_528 ;
if ( type != V_398 )
return 0 ;
if ( V_525 <= 0 || V_525 > V_403 )
return - V_70 ;
if ( V_464 != NULL ) {
V_177 += F_63 ( sizeof( struct V_461 ) +
F_164 ( V_464 -> V_135 ) ) ;
}
V_526 = F_62 ( V_185 -> V_135 ) ;
if ( ! V_526 )
return - V_70 ;
V_177 += ( sizeof( struct V_75 ) + V_526 ) * 2 ;
V_527 += sizeof( struct V_415 ) ;
for ( V_352 = 0 , V_528 = V_452 ; V_352 < V_525 ; V_352 ++ , V_528 ++ ) {
V_527 += sizeof( struct V_399 ) +
F_164 ( V_528 -> V_456 ) ;
V_527 += sizeof( struct V_399 ) +
F_164 ( V_528 -> V_459 ) ;
}
V_177 += sizeof( struct V_58 ) + V_527 ;
V_8 = F_41 ( V_177 , V_52 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_322 = V_29 ;
V_59 -> V_323 = V_529 ;
V_59 -> V_146 = F_54 ( V_452 -> V_134 ) ;
V_59 -> V_72 = V_177 / 8 ;
V_59 -> V_63 = 0 ;
V_59 -> V_325 = 0 ;
V_59 -> V_62 = 0 ;
V_59 -> V_326 = 0 ;
if ( V_464 != NULL && ( F_197 ( V_8 , V_464 ) < 0 ) )
goto V_23;
F_196 ( V_8 , V_526 , V_120 , V_185 ) ;
F_196 ( V_8 , V_526 , V_121 , V_185 ) ;
V_416 = (struct V_415 * ) F_43 ( V_8 , sizeof( struct V_415 ) ) ;
V_416 -> V_417 = V_527 / 8 ;
V_416 -> V_422 = V_423 ;
V_416 -> V_424 = V_428 ;
V_416 -> V_430 = V_391 + 1 ;
V_416 -> V_431 = 0 ;
V_416 -> V_432 = 0 ;
V_416 -> V_434 = 0 ;
for ( V_352 = 0 , V_528 = V_452 ; V_352 < V_525 ; V_352 ++ , V_528 ++ ) {
int V_149 = F_64 ( V_528 -> V_149 ) ;
if ( V_149 < 0 )
goto V_23;
if ( F_198 ( V_8 , V_528 -> V_134 , V_149 ,
( V_528 -> V_271 ? V_410 : V_437 ) ,
V_528 -> V_271 , V_528 -> V_456 ,
& V_528 -> V_454 , & V_528 -> V_455 ) < 0 )
goto V_23;
if ( F_198 ( V_8 , V_528 -> V_134 , V_149 ,
( V_528 -> V_271 ? V_410 : V_437 ) ,
V_528 -> V_271 , V_528 -> V_459 ,
& V_528 -> V_457 , & V_528 -> V_458 ) < 0 )
goto V_23;
}
F_34 ( V_8 , V_53 , NULL , & V_530 ) ;
return 0 ;
V_23:
F_5 ( V_8 ) ;
return - V_70 ;
}
static int F_199 ( const struct V_447 * V_185 , T_7 V_391 , T_7 type ,
const struct V_451 * V_452 , int V_525 ,
const struct V_463 * V_464 )
{
return - V_471 ;
}
static int F_200 ( struct V_20 * V_2 , struct V_531 * V_532 , T_12 V_83 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_41 * V_8 = NULL ;
struct V_58 * V_59 = NULL ;
int V_23 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
V_23 = - V_308 ;
if ( V_532 -> V_533 & V_534 )
goto V_35;
V_23 = - V_481 ;
if ( ( unsigned int ) V_83 > V_3 -> V_535 - 32 )
goto V_35;
V_23 = - V_44 ;
V_8 = F_41 ( V_83 , V_33 ) ;
if ( V_8 == NULL )
goto V_35;
V_23 = - V_536 ;
if ( F_201 ( F_43 ( V_8 , V_83 ) , V_532 , V_83 ) )
goto V_35;
V_59 = F_179 ( V_8 , & V_23 ) ;
if ( ! V_59 )
goto V_35;
F_15 ( & V_10 -> V_537 . V_538 ) ;
V_23 = F_178 ( V_3 , V_8 , V_59 ) ;
F_17 ( & V_10 -> V_537 . V_538 ) ;
V_35:
if ( V_23 && V_59 && F_40 ( V_59 , V_23 , V_3 ) == 0 )
V_23 = 0 ;
F_5 ( V_8 ) ;
return V_23 ? : V_83 ;
}
static int F_202 ( struct V_20 * V_2 , struct V_531 * V_532 , T_12 V_83 ,
int V_220 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_8 ;
int V_539 , V_23 ;
V_23 = - V_70 ;
if ( V_220 & ~ ( V_540 | V_541 | V_542 | V_543 ) )
goto V_35;
V_8 = F_203 ( V_3 , V_220 , V_220 & V_541 , & V_23 ) ;
if ( V_8 == NULL )
goto V_35;
V_539 = V_8 -> V_83 ;
if ( V_539 > V_83 ) {
V_532 -> V_533 |= V_542 ;
V_539 = V_83 ;
}
F_204 ( V_8 ) ;
V_23 = F_205 ( V_8 , 0 , V_532 , V_539 ) ;
if ( V_23 )
goto V_544;
F_206 ( V_532 , V_3 , V_8 ) ;
V_23 = ( V_220 & V_542 ) ? V_8 -> V_83 : V_539 ;
if ( V_6 -> V_7 . V_7 != NULL &&
3 * F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 )
F_38 ( V_6 ) ;
V_544:
F_207 ( V_3 , V_8 ) ;
V_35:
return V_23 ;
}
static int F_208 ( struct V_545 * V_546 , void * V_547 )
{
struct V_2 * V_548 = F_209 ( V_547 ) ;
if ( V_547 == V_549 )
F_210 ( V_546 , L_4 ) ;
else
F_210 ( V_546 , L_5 ,
V_548 ,
F_3 ( & V_548 -> V_550 ) ,
F_211 ( V_548 ) ,
F_212 ( V_548 ) ,
F_213 ( F_214 ( V_546 ) , F_215 ( V_548 ) ) ,
F_216 ( V_548 )
) ;
return 0 ;
}
static void * F_217 ( struct V_545 * V_546 , T_13 * V_551 )
__acquires( T_14 )
{
struct V_10 * V_10 = F_218 ( V_546 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_35 () ;
return F_219 ( & V_12 -> V_19 , * V_551 ) ;
}
static void * F_220 ( struct V_545 * V_546 , void * V_547 , T_13 * V_551 )
{
struct V_10 * V_10 = F_218 ( V_546 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
return F_221 ( V_547 , & V_12 -> V_19 , V_551 ) ;
}
static void F_222 ( struct V_545 * V_546 , void * V_547 )
__releases( T_14 )
{
F_37 () ;
}
static int F_223 ( struct V_552 * V_552 , struct V_553 * V_553 )
{
return F_224 ( V_552 , V_553 , & V_554 ,
sizeof( struct V_555 ) ) ;
}
static int T_15 F_225 ( struct V_10 * V_10 )
{
struct V_556 * V_557 ;
V_557 = F_226 ( L_6 , 0 , V_10 -> V_558 , & V_559 ) ;
if ( V_557 == NULL )
return - V_31 ;
return 0 ;
}
static void T_16 F_227 ( struct V_10 * V_10 )
{
F_228 ( L_6 , V_10 -> V_558 ) ;
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
int V_560 ;
F_230 ( & V_12 -> V_19 ) ;
F_231 ( & V_12 -> V_17 , 0 ) ;
V_560 = F_225 ( V_10 ) ;
return V_560 ;
}
static void T_16 F_232 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_227 ( V_10 ) ;
F_42 ( ! F_233 ( & V_12 -> V_19 ) ) ;
}
static void T_17 F_234 ( void )
{
F_235 ( & V_561 ) ;
F_236 ( V_32 ) ;
F_237 ( & V_562 ) ;
F_238 ( & V_34 ) ;
}
static int T_18 F_239 ( void )
{
int V_23 = F_240 ( & V_34 , 0 ) ;
if ( V_23 != 0 )
goto V_35;
V_23 = F_241 ( & V_562 ) ;
if ( V_23 != 0 )
goto V_563;
V_23 = F_242 ( & V_564 ) ;
if ( V_23 != 0 )
goto V_565;
V_23 = F_243 ( & V_561 ) ;
if ( V_23 != 0 )
goto V_566;
V_35:
return V_23 ;
V_566:
F_236 ( V_32 ) ;
V_565:
F_237 ( & V_562 ) ;
V_563:
F_238 ( & V_34 ) ;
goto V_35;
}
