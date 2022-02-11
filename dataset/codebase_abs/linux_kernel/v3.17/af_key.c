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
V_82 -> V_141 = * (struct V_142 * ) V_137 -> V_140 ;
V_82 -> V_164 = 0 ;
return 128 ;
}
#endif
}
return 0 ;
}
static struct V_41 * F_67 ( const struct V_143 * V_165 ,
int V_166 , int V_167 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
struct V_144 * V_136 ;
struct V_168 * V_169 ;
struct V_75 * V_78 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
struct V_89 * V_90 ;
struct V_174 * V_175 ;
int V_97 = 0 ;
int V_176 ;
int V_177 = 0 ;
int V_178 = 0 ;
int V_179 ;
struct V_180 * V_181 = NULL ;
int V_149 ;
V_179 = F_62 ( V_165 -> V_182 . V_135 ) ;
if ( ! V_179 )
return F_68 ( - V_70 ) ;
V_176 = sizeof( struct V_57 ) + sizeof( struct V_144 ) +
sizeof( struct V_168 ) +
( ( V_167 & 1 ) ? sizeof( struct V_168 ) : 0 ) +
( ( V_167 & 2 ) ? sizeof( struct V_168 ) : 0 ) +
sizeof( struct V_75 ) * 2 +
V_179 * 2 +
sizeof( struct V_172 ) ;
if ( ( V_175 = V_165 -> V_183 ) ) {
V_97 = F_63 ( V_175 -> V_104 ) ;
V_176 += sizeof( struct V_89 ) + V_97 ;
}
if ( ! F_69 ( & V_165 -> V_184 . V_185 , & V_165 -> V_182 . V_185 , V_165 -> V_182 . V_135 ) )
V_176 += sizeof( struct V_75 ) + V_179 ;
if ( V_166 ) {
if ( V_165 -> V_186 && V_165 -> V_186 -> V_187 ) {
V_177 =
F_63 ( ( V_165 -> V_186 -> V_187 + 7 ) / 8 ) ;
V_176 += sizeof( struct V_170 ) + V_177 ;
}
if ( V_165 -> V_188 && V_165 -> V_188 -> V_187 ) {
V_178 =
F_63 ( ( V_165 -> V_188 -> V_187 + 7 ) / 8 ) ;
V_176 += sizeof( struct V_170 ) + V_178 ;
}
}
if ( V_165 -> V_189 )
V_181 = V_165 -> V_189 ;
if ( V_181 && V_181 -> V_190 ) {
V_176 += sizeof( struct V_191 ) ;
V_176 += sizeof( struct V_192 ) ;
V_176 += sizeof( struct V_192 ) ;
}
V_8 = F_41 ( V_176 + 16 , V_63 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
memset ( V_58 , 0 , V_176 ) ;
V_58 -> V_72 = V_176 / sizeof( V_73 ) ;
V_136 = (struct V_144 * ) F_43 ( V_8 , sizeof( struct V_144 ) ) ;
V_136 -> V_193 = sizeof( struct V_144 ) / sizeof( V_73 ) ;
V_136 -> V_194 = V_145 ;
V_136 -> V_148 = V_165 -> V_195 . V_196 ;
V_136 -> V_197 = V_165 -> V_182 . V_198 ;
switch ( V_165 -> V_199 . V_200 ) {
case V_201 :
V_136 -> V_202 = V_165 -> V_199 . V_203 ?
V_204 : V_205 ;
break;
case V_206 :
V_136 -> V_202 = V_207 ;
break;
default:
V_136 -> V_202 = V_208 ;
break;
}
V_136 -> V_209 = 0 ;
if ( V_165 -> V_186 ) {
struct V_210 * V_211 = F_70 ( V_165 -> V_186 -> V_212 , 0 ) ;
V_136 -> V_209 = ( V_211 && V_211 -> V_213 ) ?
V_211 -> V_214 . V_215 : 0 ;
}
V_136 -> V_216 = 0 ;
F_42 ( V_165 -> V_188 && V_165 -> V_217 ) ;
if ( V_165 -> V_188 ) {
struct V_210 * V_211 = F_71 ( V_165 -> V_188 -> V_212 , 0 ) ;
V_136 -> V_216 = ( V_211 && V_211 -> V_213 ) ?
V_211 -> V_214 . V_215 : 0 ;
}
if ( V_165 -> V_217 ) {
struct V_210 * V_211 = F_72 ( V_165 -> V_217 -> V_212 , 0 ) ;
V_136 -> V_216 = ( V_211 && V_211 -> V_213 ) ?
V_211 -> V_214 . V_215 : 0 ;
}
V_136 -> V_218 = 0 ;
if ( V_165 -> V_182 . V_219 & V_220 )
V_136 -> V_218 |= V_221 ;
if ( V_165 -> V_182 . V_219 & V_222 )
V_136 -> V_218 |= V_223 ;
if ( V_165 -> V_182 . V_219 & V_224 )
V_136 -> V_218 |= V_225 ;
if ( V_167 & 2 ) {
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_73 ) ;
V_169 -> V_227 = V_228 ;
V_169 -> V_229 = F_73 ( V_165 -> V_230 . V_231 ) ;
V_169 -> V_232 = F_73 ( V_165 -> V_230 . V_233 ) ;
V_169 -> V_234 = V_165 -> V_230 . V_235 ;
V_169 -> V_236 = V_165 -> V_230 . V_237 ;
}
if ( V_167 & 1 ) {
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_73 ) ;
V_169 -> V_227 = V_238 ;
V_169 -> V_229 = F_73 ( V_165 -> V_230 . V_239 ) ;
V_169 -> V_232 = F_73 ( V_165 -> V_230 . V_240 ) ;
V_169 -> V_234 = V_165 -> V_230 . V_241 ;
V_169 -> V_236 = V_165 -> V_230 . V_242 ;
}
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_73 ) ;
V_169 -> V_227 = V_243 ;
V_169 -> V_229 = V_165 -> V_244 . V_245 ;
V_169 -> V_232 = V_165 -> V_244 . V_246 ;
V_169 -> V_234 = V_165 -> V_244 . V_247 ;
V_169 -> V_236 = V_165 -> V_244 . V_248 ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_179 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_179 ) /
sizeof( V_73 ) ;
V_78 -> V_249 = V_120 ;
V_78 -> V_250 = 0 ;
V_78 -> V_251 = 0 ;
V_78 -> V_87 =
F_66 ( & V_165 -> V_182 . V_185 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_179 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_179 ) /
sizeof( V_73 ) ;
V_78 -> V_249 = V_121 ;
V_78 -> V_250 = 0 ;
V_78 -> V_251 = 0 ;
V_78 -> V_87 =
F_66 ( & V_165 -> V_195 . V_252 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
if ( ! F_69 ( & V_165 -> V_184 . V_185 , & V_165 -> V_182 . V_185 ,
V_165 -> V_182 . V_135 ) ) {
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_179 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_179 ) /
sizeof( V_73 ) ;
V_78 -> V_249 = V_122 ;
V_78 -> V_250 =
F_56 ( V_165 -> V_184 . V_134 ) ;
V_78 -> V_87 = V_165 -> V_184 . V_253 ;
V_78 -> V_251 = 0 ;
F_66 ( & V_165 -> V_184 . V_185 , V_165 -> V_184 . V_254 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
}
if ( V_166 && V_177 ) {
V_171 = (struct V_170 * ) F_43 ( V_8 ,
sizeof( struct V_170 ) + V_177 ) ;
V_171 -> V_255 = ( sizeof( struct V_170 ) + V_177 ) /
sizeof( V_73 ) ;
V_171 -> V_256 = V_257 ;
V_171 -> V_258 = V_165 -> V_186 -> V_187 ;
V_171 -> V_259 = 0 ;
memcpy ( V_171 + 1 , V_165 -> V_186 -> V_260 , ( V_165 -> V_186 -> V_187 + 7 ) / 8 ) ;
}
if ( V_166 && V_178 ) {
V_171 = (struct V_170 * ) F_43 ( V_8 ,
sizeof( struct V_170 ) + V_178 ) ;
V_171 -> V_255 = ( sizeof( struct V_170 ) +
V_178 ) / sizeof( V_73 ) ;
V_171 -> V_256 = V_261 ;
V_171 -> V_258 = V_165 -> V_188 -> V_187 ;
V_171 -> V_259 = 0 ;
memcpy ( V_171 + 1 , V_165 -> V_188 -> V_260 ,
( V_165 -> V_188 -> V_187 + 7 ) / 8 ) ;
}
V_173 = (struct V_172 * ) F_43 ( V_8 , sizeof( struct V_172 ) ) ;
V_173 -> V_262 = sizeof( struct V_172 ) / sizeof( V_73 ) ;
V_173 -> V_263 = V_264 ;
if ( ( V_149 = F_64 ( V_165 -> V_182 . V_149 ) ) < 0 ) {
F_5 ( V_8 ) ;
return F_68 ( - V_70 ) ;
}
V_173 -> V_265 = V_149 ;
V_173 -> V_266 = 0 ;
V_173 -> V_267 = 0 ;
V_173 -> V_268 = 0 ;
V_173 -> V_269 = V_165 -> V_182 . V_270 ;
if ( V_181 && V_181 -> V_190 ) {
struct V_191 * V_271 ;
struct V_192 * V_272 ;
V_271 = (struct V_191 * ) F_43 ( V_8 , sizeof( * V_271 ) ) ;
V_271 -> V_273 = sizeof( * V_271 ) / sizeof( V_73 ) ;
V_271 -> V_274 = V_275 ;
V_271 -> V_276 = V_181 -> V_190 ;
V_271 -> V_277 [ 0 ] = 0 ;
V_271 -> V_277 [ 1 ] = 0 ;
V_271 -> V_277 [ 2 ] = 0 ;
V_272 = (struct V_192 * ) F_43 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_73 ) ;
V_272 -> V_279 = V_280 ;
V_272 -> V_281 = V_181 -> V_282 ;
V_272 -> V_283 = 0 ;
V_272 = (struct V_192 * ) F_43 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_73 ) ;
V_272 -> V_279 = V_284 ;
V_272 -> V_281 = V_181 -> V_285 ;
V_272 -> V_283 = 0 ;
}
if ( V_175 ) {
V_90 = (struct V_89 * ) F_43 ( V_8 ,
sizeof( struct V_89 ) + V_97 ) ;
V_90 -> V_93 =
( sizeof( struct V_89 ) + V_97 ) / sizeof( V_73 ) ;
V_90 -> V_99 = V_124 ;
V_90 -> V_101 = V_175 -> V_100 ;
V_90 -> V_103 = V_175 -> V_102 ;
V_90 -> V_91 = V_175 -> V_104 ;
memcpy ( V_90 + 1 , V_175 -> V_286 ,
V_175 -> V_104 ) ;
}
return V_8 ;
}
static inline struct V_41 * F_75 ( const struct V_143 * V_165 )
{
struct V_41 * V_8 ;
V_8 = F_67 ( V_165 , 1 , 3 ) ;
return V_8 ;
}
static inline struct V_41 * F_76 ( const struct V_143 * V_165 ,
int V_167 )
{
return F_67 ( V_165 , 0 , V_167 ) ;
}
static struct V_143 * F_77 ( struct V_10 * V_10 ,
const struct V_57 * V_58 ,
void * const * V_109 )
{
struct V_143 * V_165 ;
const struct V_168 * V_169 ;
const struct V_144 * V_136 ;
const struct V_170 * V_171 ;
const struct V_89 * V_90 ;
T_2 V_134 ;
int V_23 ;
V_136 = V_109 [ V_145 - 1 ] ;
if ( ! V_136 ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return F_68 ( - V_70 ) ;
if ( V_58 -> V_146 == V_130 &&
! V_109 [ V_261 - 1 ] )
return F_68 ( - V_70 ) ;
if ( V_58 -> V_146 == V_128 &&
! V_109 [ V_257 - 1 ] )
return F_68 ( - V_70 ) ;
if ( ! ! V_109 [ V_228 - 1 ] !=
! ! V_109 [ V_238 - 1 ] )
return F_68 ( - V_70 ) ;
V_134 = F_53 ( V_58 -> V_146 ) ;
if ( V_134 == 0 )
return F_68 ( - V_70 ) ;
V_23 = - V_44 ;
if ( V_136 -> V_209 > V_287 ||
( V_58 -> V_146 == V_132 &&
V_136 -> V_216 > V_288 ) ||
V_136 -> V_216 > V_289 )
return F_68 ( - V_70 ) ;
V_171 = V_109 [ V_257 - 1 ] ;
if ( V_171 != NULL &&
V_136 -> V_209 != V_290 &&
( ( V_171 -> V_258 + 7 ) / 8 == 0 ||
( V_171 -> V_258 + 7 ) / 8 > V_171 -> V_255 * sizeof( V_73 ) ) )
return F_68 ( - V_70 ) ;
V_171 = V_109 [ V_261 - 1 ] ;
if ( V_171 != NULL &&
V_136 -> V_216 != V_291 &&
( ( V_171 -> V_258 + 7 ) / 8 == 0 ||
( V_171 -> V_258 + 7 ) / 8 > V_171 -> V_255 * sizeof( V_73 ) ) )
return F_68 ( - V_70 ) ;
V_165 = F_78 ( V_10 ) ;
if ( V_165 == NULL )
return F_68 ( - V_44 ) ;
V_165 -> V_195 . V_134 = V_134 ;
V_165 -> V_195 . V_196 = V_136 -> V_148 ;
V_165 -> V_182 . V_198 = F_79 (unsigned int, sa->sadb_sa_replay,
(sizeof(x->replay.bitmap) * 8)) ;
if ( V_136 -> V_218 & V_221 )
V_165 -> V_182 . V_219 |= V_220 ;
if ( V_136 -> V_218 & V_223 )
V_165 -> V_182 . V_219 |= V_222 ;
if ( V_136 -> V_218 & V_225 )
V_165 -> V_182 . V_219 |= V_224 ;
V_169 = V_109 [ V_228 - 1 ] ;
if ( V_169 != NULL ) {
V_165 -> V_230 . V_231 = F_80 ( V_169 -> V_229 ) ;
V_165 -> V_230 . V_233 = F_80 ( V_169 -> V_232 ) ;
V_165 -> V_230 . V_235 = V_169 -> V_234 ;
V_165 -> V_230 . V_237 = V_169 -> V_236 ;
}
V_169 = V_109 [ V_238 - 1 ] ;
if ( V_169 != NULL ) {
V_165 -> V_230 . V_239 = F_80 ( V_169 -> V_229 ) ;
V_165 -> V_230 . V_240 = F_80 ( V_169 -> V_232 ) ;
V_165 -> V_230 . V_241 = V_169 -> V_234 ;
V_165 -> V_230 . V_242 = V_169 -> V_236 ;
}
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 )
goto V_35;
V_23 = F_81 ( V_165 , V_96 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
goto V_35;
}
V_171 = V_109 [ V_257 - 1 ] ;
if ( V_136 -> V_209 ) {
int V_292 = 0 ;
struct V_210 * V_211 = F_83 ( V_136 -> V_209 ) ;
if ( ! V_211 || ! V_211 -> V_213 ) {
V_23 = - V_293 ;
goto V_35;
}
if ( V_171 )
V_292 = ( V_171 -> V_258 + 7 ) / 8 ;
V_165 -> V_186 = F_50 ( sizeof( * V_165 -> V_186 ) + V_292 , V_33 ) ;
if ( ! V_165 -> V_186 )
goto V_35;
strcpy ( V_165 -> V_186 -> V_212 , V_211 -> V_294 ) ;
V_165 -> V_186 -> V_187 = 0 ;
if ( V_171 ) {
V_165 -> V_186 -> V_187 = V_171 -> V_258 ;
memcpy ( V_165 -> V_186 -> V_260 , V_171 + 1 , V_292 ) ;
}
V_165 -> V_186 -> V_295 = V_211 -> V_296 . V_297 . V_298 ;
V_165 -> V_182 . V_299 = V_136 -> V_209 ;
}
if ( V_136 -> V_216 ) {
if ( V_58 -> V_146 == V_132 ) {
struct V_210 * V_211 = F_84 ( V_136 -> V_216 ) ;
if ( ! V_211 || ! V_211 -> V_213 ) {
V_23 = - V_293 ;
goto V_35;
}
V_165 -> V_217 = F_50 ( sizeof( * V_165 -> V_217 ) , V_33 ) ;
if ( ! V_165 -> V_217 )
goto V_35;
strcpy ( V_165 -> V_217 -> V_212 , V_211 -> V_294 ) ;
V_165 -> V_182 . V_300 = V_136 -> V_216 ;
} else {
int V_292 = 0 ;
struct V_210 * V_211 = F_85 ( V_136 -> V_216 ) ;
if ( ! V_211 || ! V_211 -> V_213 ) {
V_23 = - V_293 ;
goto V_35;
}
V_171 = (struct V_170 * ) V_109 [ V_261 - 1 ] ;
if ( V_171 )
V_292 = ( V_171 -> V_258 + 7 ) / 8 ;
V_165 -> V_188 = F_50 ( sizeof( * V_165 -> V_188 ) + V_292 , V_33 ) ;
if ( ! V_165 -> V_188 )
goto V_35;
strcpy ( V_165 -> V_188 -> V_212 , V_211 -> V_294 ) ;
V_165 -> V_188 -> V_187 = 0 ;
if ( V_171 ) {
V_165 -> V_188 -> V_187 = V_171 -> V_258 ;
memcpy ( V_165 -> V_188 -> V_260 , V_171 + 1 , V_292 ) ;
}
V_165 -> V_182 . V_301 = V_136 -> V_216 ;
}
}
V_165 -> V_182 . V_135 = F_59 ( (struct V_75 * ) V_109 [ V_120 - 1 ] ,
& V_165 -> V_182 . V_185 ) ;
F_59 ( (struct V_75 * ) V_109 [ V_121 - 1 ] ,
& V_165 -> V_195 . V_252 ) ;
if ( V_109 [ V_264 - 1 ] ) {
const struct V_172 * V_173 = V_109 [ V_264 - 1 ] ;
int V_149 = F_65 ( V_173 -> V_265 ) ;
if ( V_149 < 0 ) {
V_23 = - V_70 ;
goto V_35;
}
V_165 -> V_182 . V_149 = V_149 ;
V_165 -> V_182 . V_270 = V_173 -> V_269 ;
}
if ( V_109 [ V_122 - 1 ] ) {
const struct V_75 * V_78 = V_109 [ V_122 - 1 ] ;
V_165 -> V_184 . V_135 = F_59 ( V_78 , & V_165 -> V_184 . V_185 ) ;
V_165 -> V_184 . V_253 = V_78 -> V_87 ;
}
if ( ! V_165 -> V_184 . V_135 )
V_165 -> V_184 . V_135 = V_165 -> V_182 . V_135 ;
if ( V_109 [ V_275 - 1 ] ) {
const struct V_191 * V_271 ;
struct V_180 * V_181 ;
V_165 -> V_189 = F_50 ( sizeof( * V_165 -> V_189 ) , V_33 ) ;
if ( ! V_165 -> V_189 )
goto V_35;
V_181 = V_165 -> V_189 ;
V_271 = V_109 [ V_275 - 1 ] ;
V_181 -> V_190 = V_271 -> V_276 ;
if ( V_109 [ V_280 - 1 ] ) {
const struct V_192 * V_272 =
V_109 [ V_280 - 1 ] ;
V_181 -> V_282 = V_272 -> V_281 ;
}
if ( V_109 [ V_284 - 1 ] ) {
const struct V_192 * V_272 =
V_109 [ V_284 - 1 ] ;
V_181 -> V_285 = V_272 -> V_281 ;
}
memset ( & V_181 -> V_302 , 0 , sizeof( V_181 -> V_302 ) ) ;
}
V_23 = F_86 ( V_165 ) ;
if ( V_23 )
goto V_35;
V_165 -> V_199 . V_303 = V_58 -> V_61 ;
return V_165 ;
V_35:
V_165 -> V_199 . V_200 = V_304 ;
F_87 ( V_165 ) ;
return F_68 ( V_23 ) ;
}
static int F_88 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
return - V_305 ;
}
static int F_89 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_41 * V_306 ;
struct V_172 * V_173 ;
struct V_75 * V_185 , * V_252 ;
struct V_57 * V_307 ;
struct V_308 * V_309 ;
struct V_143 * V_165 = NULL ;
int V_149 ;
int V_23 ;
T_6 V_310 , V_311 ;
T_6 V_270 ;
T_7 V_134 ;
unsigned short V_135 ;
T_4 * V_312 = NULL , * V_313 = NULL ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_70 ;
V_134 = F_53 ( V_58 -> V_146 ) ;
if ( V_134 == 0 )
return - V_70 ;
if ( ( V_173 = V_109 [ V_264 - 1 ] ) != NULL ) {
V_149 = F_65 ( V_173 -> V_265 ) ;
if ( V_149 < 0 )
return - V_70 ;
V_270 = V_173 -> V_269 ;
} else {
V_149 = 0 ;
V_270 = 0 ;
}
V_185 = V_109 [ V_120 - 1 ] ;
V_252 = V_109 [ V_121 - 1 ] ;
V_135 = ( (struct V_77 * ) ( V_185 + 1 ) ) -> V_84 ;
switch ( V_135 ) {
case V_85 :
V_313 = ( T_4 * ) & ( (struct V_79 * ) ( V_252 + 1 ) ) -> V_139 . V_107 ;
V_312 = ( T_4 * ) & ( (struct V_79 * ) ( V_185 + 1 ) ) -> V_139 . V_107 ;
break;
#if F_45 ( V_80 )
case V_88 :
V_313 = ( T_4 * ) & ( (struct V_81 * ) ( V_252 + 1 ) ) -> V_141 ;
V_312 = ( T_4 * ) & ( (struct V_81 * ) ( V_185 + 1 ) ) -> V_141 ;
break;
#endif
}
if ( V_58 -> V_61 ) {
V_165 = F_90 ( V_10 , V_147 , V_58 -> V_61 ) ;
if ( V_165 && ! F_69 ( & V_165 -> V_195 . V_252 , V_313 , V_135 ) ) {
F_87 ( V_165 ) ;
V_165 = NULL ;
}
}
if ( ! V_165 )
V_165 = F_91 ( V_10 , & V_314 , V_149 , V_270 , V_134 , V_313 , V_312 , 1 , V_135 ) ;
if ( V_165 == NULL )
return - V_315 ;
V_310 = 0x100 ;
V_311 = 0x0fffffff ;
V_309 = V_109 [ V_316 - 1 ] ;
if ( V_309 ) {
V_310 = V_309 -> V_317 ;
V_311 = V_309 -> V_318 ;
}
V_23 = F_92 ( V_165 -> V_195 . V_134 , V_310 , V_311 ) ;
if ( V_23 ) {
F_87 ( V_165 ) ;
return V_23 ;
}
V_23 = F_93 ( V_165 , V_310 , V_311 ) ;
V_306 = V_23 ? F_68 ( V_23 ) : F_75 ( V_165 ) ;
if ( F_94 ( V_306 ) ) {
F_87 ( V_165 ) ;
return F_95 ( V_306 ) ;
}
V_307 = (struct V_57 * ) V_306 -> V_60 ;
V_307 -> V_319 = V_58 -> V_319 ;
V_307 -> V_320 = V_321 ;
V_307 -> V_146 = F_54 ( V_134 ) ;
V_307 -> V_62 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_61 = V_58 -> V_61 ;
V_307 -> V_323 = V_58 -> V_323 ;
F_87 ( V_165 ) ;
F_34 ( V_306 , V_33 , V_56 , V_3 , V_10 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_165 ;
if ( V_58 -> V_72 != sizeof( struct V_57 ) / 8 )
return - V_305 ;
if ( V_58 -> V_61 == 0 || V_58 -> V_62 == 0 )
return 0 ;
V_165 = F_90 ( V_10 , V_147 , V_58 -> V_61 ) ;
if ( V_165 == NULL )
return 0 ;
F_97 ( & V_165 -> V_324 ) ;
if ( V_165 -> V_199 . V_200 == V_206 )
V_165 -> V_199 . V_200 = V_325 ;
F_98 ( & V_165 -> V_324 ) ;
F_87 ( V_165 ) ;
return 0 ;
}
static inline int F_99 ( int V_326 )
{
switch ( V_326 ) {
case V_327 :
return V_328 ;
case V_329 :
return V_330 ;
case V_331 :
return V_332 ;
case V_333 :
default:
F_11 ( L_2 , V_326 ) ;
break;
}
return 0 ;
}
static inline int F_100 ( int V_326 )
{
switch ( V_326 ) {
case V_334 :
return V_335 ;
case V_336 :
return V_337 ;
case V_338 :
return V_339 ;
case V_340 :
return V_341 ;
default:
F_11 ( L_3 , V_326 ) ;
break;
}
return 0 ;
}
static int F_101 ( struct V_143 * V_165 , const struct V_342 * V_343 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
V_8 = F_75 ( V_165 ) ;
if ( F_94 ( V_8 ) )
return F_95 ( V_8 ) ;
V_58 = (struct V_57 * ) V_8 -> V_60 ;
V_58 -> V_319 = V_29 ;
V_58 -> V_320 = F_100 ( V_343 -> V_326 ) ;
V_58 -> V_146 = F_54 ( V_165 -> V_195 . V_134 ) ;
V_58 -> V_62 = 0 ;
V_58 -> V_322 = 0 ;
V_58 -> V_61 = V_343 -> V_303 ;
V_58 -> V_323 = V_343 -> V_344 ;
F_34 ( V_8 , V_63 , V_52 , NULL , F_102 ( V_165 ) ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_165 ;
int V_23 ;
struct V_342 V_343 ;
V_165 = F_77 ( V_10 , V_58 , V_109 ) ;
if ( F_94 ( V_165 ) )
return F_95 ( V_165 ) ;
F_104 ( V_165 ) ;
if ( V_58 -> V_320 == V_337 )
V_23 = F_105 ( V_165 ) ;
else
V_23 = F_106 ( V_165 ) ;
F_107 ( V_165 , V_23 ? 0 : 1 , true ) ;
if ( V_23 < 0 ) {
V_165 -> V_199 . V_200 = V_304 ;
F_108 ( V_165 ) ;
goto V_35;
}
if ( V_58 -> V_320 == V_337 )
V_343 . V_326 = V_336 ;
else
V_343 . V_326 = V_338 ;
V_343 . V_303 = V_58 -> V_61 ;
V_343 . V_344 = V_58 -> V_323 ;
F_109 ( V_165 , & V_343 ) ;
V_35:
F_87 ( V_165 ) ;
return V_23 ;
}
static int F_110 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_165 ;
struct V_342 V_343 ;
int V_23 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_70 ;
V_165 = F_60 ( V_10 , V_58 , V_109 ) ;
if ( V_165 == NULL )
return - V_49 ;
if ( ( V_23 = F_111 ( V_165 ) ) )
goto V_35;
if ( F_112 ( V_165 ) ) {
V_23 = - V_26 ;
goto V_35;
}
V_23 = F_113 ( V_165 ) ;
if ( V_23 < 0 )
goto V_35;
V_343 . V_303 = V_58 -> V_61 ;
V_343 . V_344 = V_58 -> V_323 ;
V_343 . V_326 = V_334 ;
F_109 ( V_165 , & V_343 ) ;
V_35:
F_114 ( V_165 , V_23 ? 0 : 1 , true ) ;
F_87 ( V_165 ) ;
return V_23 ;
}
static int F_115 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
T_8 V_134 ;
struct V_41 * V_345 ;
struct V_57 * V_307 ;
struct V_143 * V_165 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_70 ;
V_165 = F_60 ( V_10 , V_58 , V_109 ) ;
if ( V_165 == NULL )
return - V_49 ;
V_345 = F_75 ( V_165 ) ;
V_134 = V_165 -> V_195 . V_134 ;
F_87 ( V_165 ) ;
if ( F_94 ( V_345 ) )
return F_95 ( V_345 ) ;
V_307 = (struct V_57 * ) V_345 -> V_60 ;
V_307 -> V_319 = V_58 -> V_319 ;
V_307 -> V_320 = V_346 ;
V_307 -> V_146 = F_54 ( V_134 ) ;
V_307 -> V_62 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_61 = V_58 -> V_61 ;
V_307 -> V_323 = V_58 -> V_323 ;
F_34 ( V_345 , V_63 , V_56 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static struct V_41 * F_116 ( const struct V_57 * V_65 ,
T_1 V_43 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
int V_83 , V_347 , V_348 , V_349 ;
V_347 = F_117 () ;
if ( V_347 ) {
V_347 *= sizeof( struct V_350 ) ;
V_347 += sizeof( struct V_351 ) ;
}
V_348 = F_118 () ;
if ( V_348 ) {
V_348 *= sizeof( struct V_350 ) ;
V_348 += sizeof( struct V_351 ) ;
}
V_83 = V_348 + V_347 + sizeof( struct V_57 ) ;
V_8 = F_41 ( V_83 + 16 , V_43 ) ;
if ( ! V_8 )
goto V_352;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( * V_58 ) ) ;
F_39 ( V_58 , V_65 ) ;
V_58 -> V_62 = 0 ;
V_58 -> V_72 = V_83 / sizeof( V_73 ) ;
if ( V_347 ) {
struct V_351 * V_76 ;
struct V_350 * V_353 ;
V_76 = (struct V_351 * ) F_43 ( V_8 , V_347 ) ;
V_353 = (struct V_350 * ) ( V_76 + 1 ) ;
V_76 -> V_354 = V_347 / sizeof( V_73 ) ;
V_76 -> V_355 = V_356 ;
for ( V_349 = 0 ; ; V_349 ++ ) {
struct V_210 * V_186 = F_119 ( V_349 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( V_186 -> V_357 )
* V_353 ++ = V_186 -> V_214 ;
}
}
if ( V_348 ) {
struct V_351 * V_76 ;
struct V_350 * V_353 ;
V_76 = (struct V_351 * ) F_43 ( V_8 , V_348 ) ;
V_353 = (struct V_350 * ) ( V_76 + 1 ) ;
V_76 -> V_354 = V_348 / sizeof( V_73 ) ;
V_76 -> V_355 = V_358 ;
for ( V_349 = 0 ; ; V_349 ++ ) {
struct V_210 * V_188 = F_120 ( V_349 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_213 )
continue;
if ( V_188 -> V_357 )
* V_353 ++ = V_188 -> V_214 ;
}
}
V_352:
return V_8 ;
}
static int F_121 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_359 ;
if ( V_58 -> V_146 > V_360 )
return - V_70 ;
if ( V_58 -> V_146 != V_126 ) {
if ( V_6 -> V_55 & ( 1 << V_58 -> V_146 ) )
return - V_361 ;
V_6 -> V_55 |= ( 1 << V_58 -> V_146 ) ;
}
F_122 () ;
V_359 = F_116 ( V_58 , V_33 ) ;
if ( ! V_359 ) {
if ( V_58 -> V_146 != V_126 )
V_6 -> V_55 &= ~ ( 1 << V_58 -> V_146 ) ;
return - V_44 ;
}
F_34 ( V_359 , V_33 , V_54 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_123 ( struct V_2 * V_3 , const struct V_57 * V_362 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
V_8 = F_41 ( sizeof( struct V_57 ) + 16 , V_63 ) ;
if ( ! V_8 )
return - V_44 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
memcpy ( V_58 , V_362 , sizeof( struct V_57 ) ) ;
V_58 -> V_62 = ( V_71 ) 0 ;
V_58 -> V_72 = ( sizeof( struct V_57 ) / sizeof( V_73 ) ) ;
return F_34 ( V_8 , V_63 , V_56 , V_3 , F_7 ( V_3 ) ) ;
}
static int F_124 ( const struct V_342 * V_343 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
V_8 = F_41 ( sizeof( struct V_57 ) + 16 , V_63 ) ;
if ( ! V_8 )
return - V_44 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
V_58 -> V_146 = F_54 ( V_343 -> V_60 . V_134 ) ;
V_58 -> V_320 = V_363 ;
V_58 -> V_61 = V_343 -> V_303 ;
V_58 -> V_323 = V_343 -> V_344 ;
V_58 -> V_319 = V_29 ;
V_58 -> V_62 = ( V_71 ) 0 ;
V_58 -> V_72 = ( sizeof( struct V_57 ) / sizeof( V_73 ) ) ;
V_58 -> V_322 = 0 ;
F_34 ( V_8 , V_63 , V_52 , NULL , V_343 -> V_10 ) ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_134 ;
struct V_342 V_343 ;
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
V_343 . V_60 . V_134 = V_134 ;
V_343 . V_303 = V_58 -> V_61 ;
V_343 . V_344 = V_58 -> V_323 ;
V_343 . V_326 = V_364 ;
V_343 . V_10 = V_10 ;
F_109 ( NULL , & V_343 ) ;
return 0 ;
}
static int F_127 ( struct V_143 * V_165 , int V_365 , void * V_366 )
{
struct V_1 * V_6 = V_366 ;
struct V_41 * V_345 ;
struct V_57 * V_307 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_345 = F_75 ( V_165 ) ;
if ( F_94 ( V_345 ) )
return F_95 ( V_345 ) ;
V_307 = (struct V_57 * ) V_345 -> V_60 ;
V_307 -> V_319 = V_6 -> V_7 . V_367 ;
V_307 -> V_320 = V_368 ;
V_307 -> V_146 = F_54 ( V_165 -> V_195 . V_134 ) ;
V_307 -> V_62 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_61 = V_365 + 1 ;
V_307 -> V_323 = V_6 -> V_7 . V_369 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_63 , V_56 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_345 ;
return 0 ;
}
static int F_128 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return F_129 ( V_10 , & V_6 -> V_7 . V_370 . V_200 , F_127 , ( void * ) V_6 ) ;
}
static void F_130 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
F_131 ( & V_6 -> V_7 . V_370 . V_200 , V_10 ) ;
}
static int F_132 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
T_7 V_134 ;
struct V_371 * V_372 = NULL ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_373 ;
V_134 = F_53 ( V_58 -> V_146 ) ;
if ( V_134 == 0 )
return - V_70 ;
if ( V_109 [ V_374 - 1 ] ) {
struct V_375 * V_376 = V_109 [ V_374 - 1 ] ;
V_372 = F_50 ( sizeof( * V_372 ) , V_33 ) ;
if ( V_372 == NULL )
return - V_31 ;
memcpy ( & V_372 -> V_185 , & V_376 -> V_377 ,
sizeof( T_4 ) ) ;
memcpy ( & V_372 -> V_252 , & V_376 -> V_378 ,
sizeof( T_4 ) ) ;
V_372 -> V_135 = V_376 -> V_379 ;
V_372 -> V_380 = V_376 -> V_381 ;
V_372 -> V_382 = V_376 -> V_383 ;
}
V_6 -> V_7 . V_367 = V_58 -> V_319 ;
V_6 -> V_7 . V_369 = V_58 -> V_323 ;
V_6 -> V_7 . V_7 = F_128 ;
V_6 -> V_7 . V_9 = F_130 ;
F_133 ( & V_6 -> V_7 . V_370 . V_200 , V_134 , V_372 ) ;
return F_38 ( V_6 ) ;
}
static int F_134 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_125 = V_58 -> V_146 ;
bool V_384 = false ;
if ( V_58 -> V_72 == ( sizeof( * V_58 ) / sizeof( V_73 ) ) ) {
V_384 = true ;
if ( V_125 != 0 && V_125 != 1 )
return - V_70 ;
V_6 -> V_51 = V_125 ;
}
if ( V_384 && F_135 ( V_8 ) )
V_8 = F_136 ( V_8 , V_33 ) ;
else
V_8 = F_31 ( V_8 , V_33 ) ;
if ( V_384 && V_8 ) {
struct V_57 * V_385 = (struct V_57 * ) V_8 -> V_60 ;
V_385 -> V_62 = 0 ;
}
F_34 ( V_8 , V_33 , V_52 , NULL , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_137 ( struct V_386 * V_387 , int V_388 , int V_365 , void * V_366 )
{
int V_349 ;
T_6 V_270 = * ( T_6 * ) V_366 ;
for ( V_349 = 0 ; V_349 < V_387 -> V_389 ; V_349 ++ ) {
if ( V_387 -> V_390 [ V_349 ] . V_270 == V_270 )
return - V_361 ;
}
return 0 ;
}
static T_6 F_138 ( struct V_10 * V_10 )
{
struct V_391 V_392 ;
T_6 V_393 ;
int V_59 ;
static T_6 V_270 = V_394 ;
V_393 = V_270 ;
do {
++ V_270 ;
if ( V_270 == 0 )
V_270 = V_394 + 1 ;
F_139 ( & V_392 , V_395 ) ;
V_59 = V_391 ( V_10 , & V_392 , F_137 , ( void * ) & V_270 ) ;
F_140 ( & V_392 , V_10 ) ;
if ( V_59 != - V_361 )
return V_270 ;
} while ( V_270 != V_393 );
return 0 ;
}
static int
F_141 ( struct V_386 * V_387 , struct V_396 * V_397 )
{
struct V_10 * V_10 = F_142 ( V_387 ) ;
struct V_398 * V_399 = V_387 -> V_390 + V_387 -> V_389 ;
int V_149 ;
if ( V_387 -> V_389 >= V_400 )
return - V_401 ;
if ( V_397 -> V_402 == 0 )
return - V_70 ;
V_399 -> V_195 . V_134 = V_397 -> V_403 ;
if ( ( V_149 = F_65 ( V_397 -> V_402 ) ) < 0 )
return - V_70 ;
V_399 -> V_149 = V_149 ;
if ( V_397 -> V_404 == V_405 )
V_399 -> V_406 = 1 ;
else if ( V_397 -> V_404 == V_407 ) {
V_399 -> V_270 = V_397 -> V_408 ;
if ( V_399 -> V_270 > V_394 )
V_399 -> V_270 = 0 ;
if ( ! V_399 -> V_270 && ! ( V_399 -> V_270 = F_138 ( V_10 ) ) )
return - V_44 ;
}
if ( V_399 -> V_149 == V_152 ) {
T_7 * V_136 = ( T_7 * ) ( V_397 + 1 ) ;
int V_135 , V_409 ;
V_135 = F_58 ( (struct V_77 * ) V_136 ,
& V_399 -> V_185 ) ;
if ( ! V_135 )
return - V_70 ;
V_409 = F_57 ( V_135 ) ;
if ( F_58 ( (struct V_77 * ) ( V_136 + V_409 ) ,
& V_399 -> V_195 . V_252 ) != V_135 )
return - V_70 ;
V_399 -> V_410 = V_135 ;
} else
V_399 -> V_410 = V_387 -> V_135 ;
V_399 -> V_411 = 1 ;
V_387 -> V_389 ++ ;
return 0 ;
}
static int
F_143 ( struct V_386 * V_387 , struct V_412 * V_413 )
{
int V_23 ;
int V_83 = V_413 -> V_414 * 8 - sizeof( struct V_412 ) ;
struct V_396 * V_397 = ( void * ) ( V_413 + 1 ) ;
if ( V_413 -> V_414 * 8 < sizeof( struct V_412 ) )
return - V_70 ;
while ( V_83 >= sizeof( struct V_396 ) ) {
if ( ( V_23 = F_141 ( V_387 , V_397 ) ) < 0 )
return V_23 ;
V_83 -= V_397 -> V_415 ;
V_397 = ( void * ) ( ( T_7 * ) V_397 + V_397 -> V_415 ) ;
}
return 0 ;
}
static inline int F_144 ( const struct V_386 * V_387 )
{
struct V_174 * V_175 = V_387 -> V_183 ;
if ( V_175 ) {
int V_83 = sizeof( struct V_89 ) ;
V_83 += V_175 -> V_104 ;
return F_63 ( V_83 ) ;
}
return 0 ;
}
static int F_145 ( const struct V_386 * V_387 )
{
const struct V_398 * V_399 ;
int V_179 = F_62 ( V_387 -> V_135 ) ;
int V_409 = 0 ;
int V_349 ;
for ( V_349 = 0 ; V_349 < V_387 -> V_389 ; V_349 ++ ) {
V_399 = V_387 -> V_390 + V_349 ;
V_409 += F_57 ( V_399 -> V_410 ) ;
}
return sizeof( struct V_57 ) +
( sizeof( struct V_168 ) * 3 ) +
( sizeof( struct V_75 ) * 2 ) +
( V_179 * 2 ) +
sizeof( struct V_412 ) +
( V_387 -> V_389 * sizeof( struct V_396 ) ) +
( V_409 * 2 ) +
F_144 ( V_387 ) ;
}
static struct V_41 * F_146 ( const struct V_386 * V_387 )
{
struct V_41 * V_8 ;
int V_176 ;
V_176 = F_145 ( V_387 ) ;
V_8 = F_41 ( V_176 + 16 , V_63 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
return V_8 ;
}
static int F_147 ( struct V_41 * V_8 , const struct V_386 * V_387 , int V_388 )
{
struct V_57 * V_58 ;
struct V_75 * V_78 ;
struct V_168 * V_169 ;
struct V_412 * V_413 ;
struct V_89 * V_90 ;
struct V_174 * V_175 ;
int V_349 ;
int V_176 ;
int V_179 = F_62 ( V_387 -> V_135 ) ;
int V_409 = F_57 ( V_387 -> V_135 ) ;
V_176 = F_145 ( V_387 ) ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
memset ( V_58 , 0 , V_176 ) ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_179 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_179 ) /
sizeof( V_73 ) ;
V_78 -> V_249 = V_120 ;
V_78 -> V_250 = F_56 ( V_387 -> V_416 . V_134 ) ;
V_78 -> V_87 = V_387 -> V_416 . V_253 ;
V_78 -> V_251 = 0 ;
if ( ! F_66 ( & V_387 -> V_416 . V_185 ,
V_387 -> V_416 . V_254 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_387 -> V_135 ) )
F_74 () ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_179 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_179 ) /
sizeof( V_73 ) ;
V_78 -> V_249 = V_121 ;
V_78 -> V_250 = F_56 ( V_387 -> V_416 . V_134 ) ;
V_78 -> V_87 = V_387 -> V_416 . V_417 ;
V_78 -> V_251 = 0 ;
F_66 ( & V_387 -> V_416 . V_252 , V_387 -> V_416 . V_418 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_387 -> V_135 ) ;
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_73 ) ;
V_169 -> V_227 = V_228 ;
V_169 -> V_229 = F_73 ( V_387 -> V_230 . V_231 ) ;
V_169 -> V_232 = F_73 ( V_387 -> V_230 . V_233 ) ;
V_169 -> V_234 = V_387 -> V_230 . V_235 ;
V_169 -> V_236 = V_387 -> V_230 . V_237 ;
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_73 ) ;
V_169 -> V_227 = V_238 ;
V_169 -> V_229 = F_73 ( V_387 -> V_230 . V_239 ) ;
V_169 -> V_232 = F_73 ( V_387 -> V_230 . V_240 ) ;
V_169 -> V_234 = V_387 -> V_230 . V_241 ;
V_169 -> V_236 = V_387 -> V_230 . V_242 ;
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_73 ) ;
V_169 -> V_227 = V_243 ;
V_169 -> V_229 = V_387 -> V_244 . V_245 ;
V_169 -> V_232 = V_387 -> V_244 . V_246 ;
V_169 -> V_234 = V_387 -> V_244 . V_247 ;
V_169 -> V_236 = V_387 -> V_244 . V_248 ;
V_413 = (struct V_412 * ) F_43 ( V_8 , sizeof( struct V_412 ) ) ;
V_413 -> V_414 = sizeof( struct V_412 ) / sizeof( V_73 ) ;
V_413 -> V_419 = V_420 ;
V_413 -> V_421 = V_422 ;
if ( V_387 -> V_423 == V_424 ) {
if ( V_387 -> V_389 )
V_413 -> V_421 = V_425 ;
else
V_413 -> V_421 = V_426 ;
}
V_413 -> V_427 = V_388 + 1 ;
V_413 -> V_428 = 0 ;
V_413 -> V_429 = V_387 -> V_430 ;
V_413 -> V_431 = V_387 -> V_432 ;
for ( V_349 = 0 ; V_349 < V_387 -> V_389 ; V_349 ++ ) {
const struct V_398 * V_399 = V_387 -> V_390 + V_349 ;
struct V_396 * V_397 ;
int V_433 ;
int V_149 ;
V_433 = sizeof( struct V_396 ) ;
if ( V_399 -> V_149 == V_152 ) {
V_409 = F_57 ( V_399 -> V_410 ) ;
V_433 += V_409 * 2 ;
} else {
V_176 -= 2 * V_409 ;
}
V_397 = ( void * ) F_43 ( V_8 , V_433 ) ;
V_413 -> V_414 += V_433 / 8 ;
memset ( V_397 , 0 , sizeof( * V_397 ) ) ;
V_397 -> V_415 = V_433 ;
V_397 -> V_403 = V_399 -> V_195 . V_134 ;
if ( ( V_149 = F_64 ( V_399 -> V_149 ) ) < 0 )
return - V_70 ;
V_397 -> V_402 = V_149 ;
V_397 -> V_404 = V_434 ;
if ( V_399 -> V_270 )
V_397 -> V_404 = V_407 ;
if ( V_399 -> V_406 )
V_397 -> V_404 = V_405 ;
V_397 -> V_408 = V_399 -> V_270 ;
if ( V_399 -> V_149 == V_152 ) {
T_7 * V_136 = ( void * ) ( V_397 + 1 ) ;
F_66 ( & V_399 -> V_185 , 0 ,
(struct V_77 * ) V_136 ,
V_399 -> V_410 ) ;
F_66 ( & V_399 -> V_195 . V_252 , 0 ,
(struct V_77 * ) ( V_136 + V_409 ) ,
V_399 -> V_410 ) ;
}
}
if ( ( V_175 = V_387 -> V_183 ) ) {
int V_97 = F_144 ( V_387 ) ;
V_90 = (struct V_89 * ) F_43 ( V_8 , V_97 ) ;
V_90 -> V_93 = V_97 / sizeof( V_73 ) ;
V_90 -> V_99 = V_124 ;
V_90 -> V_101 = V_175 -> V_100 ;
V_90 -> V_103 = V_175 -> V_102 ;
V_90 -> V_91 = V_175 -> V_104 ;
memcpy ( V_90 + 1 , V_175 -> V_286 ,
V_175 -> V_104 ) ;
}
V_58 -> V_72 = V_176 / sizeof( V_73 ) ;
V_58 -> V_322 = F_3 ( & V_387 -> V_435 ) ;
return 0 ;
}
static int F_148 ( struct V_386 * V_387 , int V_388 , const struct V_342 * V_343 )
{
struct V_41 * V_345 ;
struct V_57 * V_307 ;
int V_23 ;
V_345 = F_146 ( V_387 ) ;
if ( F_94 ( V_345 ) )
return F_95 ( V_345 ) ;
V_23 = F_147 ( V_345 , V_387 , V_388 ) ;
if ( V_23 < 0 )
return V_23 ;
V_307 = (struct V_57 * ) V_345 -> V_60 ;
V_307 -> V_319 = V_29 ;
if ( V_343 -> V_60 . V_436 && V_343 -> V_326 == V_327 )
V_307 -> V_320 = V_437 ;
else
V_307 -> V_320 = F_99 ( V_343 -> V_326 ) ;
V_307 -> V_62 = 0 ;
V_307 -> V_61 = V_343 -> V_303 ;
V_307 -> V_323 = V_343 -> V_344 ;
F_34 ( V_345 , V_63 , V_52 , NULL , F_142 ( V_387 ) ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 = 0 ;
struct V_168 * V_169 ;
struct V_75 * V_136 ;
struct V_412 * V_413 ;
struct V_386 * V_387 ;
struct V_342 V_343 ;
struct V_89 * V_90 ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_420 - 1 ] )
return - V_70 ;
V_413 = V_109 [ V_420 - 1 ] ;
if ( V_413 -> V_421 > V_425 )
return - V_70 ;
if ( ! V_413 -> V_427 || V_413 -> V_427 >= V_438 )
return - V_70 ;
V_387 = F_150 ( V_10 , V_33 ) ;
if ( V_387 == NULL )
return - V_44 ;
V_387 -> V_423 = ( V_413 -> V_421 == V_422 ?
V_439 : V_424 ) ;
V_387 -> V_432 = V_413 -> V_431 ;
V_136 = V_109 [ V_120 - 1 ] ;
V_387 -> V_135 = F_59 ( V_136 , & V_387 -> V_416 . V_185 ) ;
V_387 -> V_416 . V_135 = V_387 -> V_135 ;
V_387 -> V_416 . V_253 = V_136 -> V_87 ;
V_387 -> V_416 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_387 -> V_416 . V_254 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_387 -> V_416 . V_254 )
V_387 -> V_416 . V_440 = F_151 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_387 -> V_416 . V_252 ) ;
V_387 -> V_416 . V_417 = V_136 -> V_87 ;
V_387 -> V_416 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_387 -> V_416 . V_418 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_387 -> V_416 . V_418 )
V_387 -> V_416 . V_441 = F_151 ( 0xffff ) ;
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 ) {
V_23 = - V_44 ;
goto V_35;
}
V_23 = F_152 ( & V_387 -> V_183 , V_96 , V_33 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
goto V_35;
}
V_387 -> V_230 . V_240 = V_442 ;
V_387 -> V_230 . V_233 = V_442 ;
V_387 -> V_230 . V_239 = V_442 ;
V_387 -> V_230 . V_231 = V_442 ;
if ( ( V_169 = V_109 [ V_228 - 1 ] ) != NULL ) {
V_387 -> V_230 . V_231 = F_80 ( V_169 -> V_229 ) ;
V_387 -> V_230 . V_233 = F_80 ( V_169 -> V_232 ) ;
V_387 -> V_230 . V_235 = V_169 -> V_234 ;
V_387 -> V_230 . V_237 = V_169 -> V_236 ;
}
if ( ( V_169 = V_109 [ V_238 - 1 ] ) != NULL ) {
V_387 -> V_230 . V_239 = F_80 ( V_169 -> V_229 ) ;
V_387 -> V_230 . V_240 = F_80 ( V_169 -> V_232 ) ;
V_387 -> V_230 . V_241 = V_169 -> V_234 ;
V_387 -> V_230 . V_242 = V_169 -> V_236 ;
}
V_387 -> V_389 = 0 ;
if ( V_413 -> V_421 == V_425 &&
( V_23 = F_143 ( V_387 , V_413 ) ) < 0 )
goto V_35;
V_23 = F_153 ( V_413 -> V_427 - 1 , V_387 ,
V_58 -> V_320 != V_332 ) ;
F_154 ( V_387 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
if ( V_58 -> V_320 == V_332 )
V_343 . V_326 = V_331 ;
else
V_343 . V_326 = V_329 ;
V_343 . V_303 = V_58 -> V_61 ;
V_343 . V_344 = V_58 -> V_323 ;
F_155 ( V_387 , V_413 -> V_427 - 1 , & V_343 ) ;
F_156 ( V_387 ) ;
return 0 ;
V_35:
V_387 -> V_392 . V_443 = 1 ;
F_157 ( V_387 ) ;
return V_23 ;
}
static int F_158 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 ;
struct V_75 * V_136 ;
struct V_412 * V_413 ;
struct V_386 * V_387 ;
struct V_444 V_184 ;
struct V_342 V_343 ;
struct V_89 * V_90 ;
struct V_174 * V_445 = NULL ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_420 - 1 ] )
return - V_70 ;
V_413 = V_109 [ V_420 - 1 ] ;
if ( ! V_413 -> V_427 || V_413 -> V_427 >= V_438 )
return - V_70 ;
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ;
V_184 . V_135 = F_59 ( V_136 , & V_184 . V_185 ) ;
V_184 . V_253 = V_136 -> V_87 ;
V_184 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_184 . V_254 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_254 )
V_184 . V_440 = F_151 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_184 . V_252 ) ;
V_184 . V_417 = V_136 -> V_87 ;
V_184 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_184 . V_418 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_418 )
V_184 . V_441 = F_151 ( 0xffff ) ;
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 )
return - V_31 ;
V_23 = F_152 ( & V_445 , V_96 , V_33 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
return V_23 ;
}
V_387 = F_159 ( V_10 , V_147 , V_395 ,
V_413 -> V_427 - 1 , & V_184 , V_445 ,
1 , & V_23 ) ;
F_160 ( V_445 ) ;
if ( V_387 == NULL )
return - V_315 ;
F_161 ( V_387 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
V_343 . V_303 = V_58 -> V_61 ;
V_343 . V_344 = V_58 -> V_323 ;
V_343 . V_60 . V_436 = 0 ;
V_343 . V_326 = V_327 ;
F_155 ( V_387 , V_413 -> V_427 - 1 , & V_343 ) ;
V_35:
F_156 ( V_387 ) ;
if ( V_23 == 0 )
F_162 ( V_10 ) ;
return V_23 ;
}
static int F_163 ( struct V_2 * V_3 , struct V_386 * V_387 , const struct V_57 * V_58 , int V_388 )
{
int V_23 ;
struct V_41 * V_345 ;
struct V_57 * V_307 ;
V_23 = 0 ;
V_345 = F_146 ( V_387 ) ;
if ( F_94 ( V_345 ) ) {
V_23 = F_95 ( V_345 ) ;
goto V_35;
}
V_23 = F_147 ( V_345 , V_387 , V_388 ) ;
if ( V_23 < 0 )
goto V_35;
V_307 = (struct V_57 * ) V_345 -> V_60 ;
V_307 -> V_319 = V_58 -> V_319 ;
V_307 -> V_320 = V_58 -> V_320 ;
V_307 -> V_146 = 0 ;
V_307 -> V_62 = 0 ;
V_307 -> V_61 = V_58 -> V_61 ;
V_307 -> V_323 = V_58 -> V_323 ;
F_34 ( V_345 , V_63 , V_56 , V_3 , F_142 ( V_387 ) ) ;
V_23 = 0 ;
V_35:
return V_23 ;
}
static int F_164 ( T_3 V_135 )
{
return F_63 ( F_57 ( V_135 ) * 2 ) ;
}
static int F_165 ( struct V_77 * V_136 , int V_113 ,
T_4 * V_185 , T_4 * V_252 ,
T_9 * V_135 )
{
int V_446 , V_409 ;
if ( V_113 < F_164 ( V_136 -> V_84 ) )
return - V_70 ;
V_446 = F_58 ( V_136 , V_185 ) ;
if ( ! V_446 )
return - V_70 ;
V_409 = F_57 ( V_446 ) ;
if ( F_58 ( (struct V_77 * ) ( ( ( T_7 * ) V_136 ) + V_409 ) ,
V_252 ) != V_446 )
return - V_70 ;
* V_135 = V_446 ;
return 0 ;
}
static int F_166 ( struct V_396 * V_447 , int V_83 ,
struct V_448 * V_449 )
{
int V_23 ;
struct V_396 * V_450 ;
int V_149 ;
if ( V_83 <= sizeof( struct V_396 ) ||
V_83 < V_447 -> V_415 )
return - V_70 ;
V_23 = F_165 ( (struct V_77 * ) ( V_447 + 1 ) ,
V_447 -> V_415 ,
& V_449 -> V_451 , & V_449 -> V_452 ,
& V_449 -> V_453 ) ;
if ( V_23 )
return V_23 ;
V_450 = (struct V_396 * ) ( ( T_7 * ) V_447 + V_447 -> V_415 ) ;
V_83 -= V_447 -> V_415 ;
if ( V_83 <= sizeof( struct V_396 ) ||
V_83 < V_450 -> V_415 )
return - V_70 ;
V_23 = F_165 ( (struct V_77 * ) ( V_450 + 1 ) ,
V_450 -> V_415 ,
& V_449 -> V_454 , & V_449 -> V_455 ,
& V_449 -> V_456 ) ;
if ( V_23 )
return V_23 ;
if ( V_447 -> V_403 != V_450 -> V_403 ||
V_447 -> V_402 != V_450 -> V_402 ||
V_447 -> V_408 != V_450 -> V_408 )
return - V_70 ;
V_449 -> V_134 = V_447 -> V_403 ;
if ( ( V_149 = F_65 ( V_447 -> V_402 ) ) < 0 )
return - V_70 ;
V_449 -> V_149 = V_149 ;
V_449 -> V_270 = V_447 -> V_408 ;
return ( ( int ) ( V_447 -> V_415 +
V_450 -> V_415 ) ) ;
}
static int F_167 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_57 * V_58 , void * const * V_109 )
{
int V_349 , V_83 , V_457 , V_23 = - V_70 ;
T_7 V_388 ;
struct V_75 * V_136 ;
struct V_458 * V_459 ;
struct V_412 * V_413 ;
struct V_396 * V_397 ;
struct V_444 V_184 ;
struct V_448 V_449 [ V_400 ] ;
struct V_460 V_461 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_420 - 1 ] ) {
V_23 = - V_70 ;
goto V_35;
}
V_459 = V_109 [ V_462 - 1 ] ;
V_413 = V_109 [ V_420 - 1 ] ;
if ( V_413 -> V_427 >= V_438 ) {
V_23 = - V_70 ;
goto V_35;
}
if ( V_459 ) {
V_461 . V_463 = V_459 -> V_464 ;
V_457 = F_165 ( (struct V_77 * ) ( V_459 + 1 ) ,
8 * ( V_459 -> V_465 ) - sizeof( * V_459 ) ,
& V_461 . V_466 , & V_461 . V_467 , & V_461 . V_135 ) ;
if ( V_457 < 0 ) {
V_23 = V_457 ;
goto V_35;
}
}
V_388 = V_413 -> V_427 - 1 ;
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ;
V_184 . V_135 = F_59 ( V_136 , & V_184 . V_185 ) ;
V_184 . V_253 = V_136 -> V_87 ;
V_184 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_184 . V_254 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_254 )
V_184 . V_440 = F_151 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_184 . V_252 ) ;
V_184 . V_417 = V_136 -> V_87 ;
V_184 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_184 . V_418 = ( (struct V_79 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_418 )
V_184 . V_441 = F_151 ( 0xffff ) ;
V_397 = (struct V_396 * ) ( V_413 + 1 ) ;
V_349 = 0 ;
V_83 = V_413 -> V_414 * 8 - sizeof( struct V_412 ) ;
while ( V_83 > 0 && V_349 < V_400 ) {
V_457 = F_166 ( V_397 , V_83 , & V_449 [ V_349 ] ) ;
if ( V_457 < 0 ) {
V_23 = V_457 ;
goto V_35;
} else {
V_397 = (struct V_396 * ) ( ( T_7 * ) V_397 + V_457 ) ;
V_83 -= V_457 ;
V_349 ++ ;
}
}
if ( ! V_349 || V_83 > 0 ) {
V_23 = - V_70 ;
goto V_35;
}
return V_448 ( & V_184 , V_388 , V_395 , V_449 , V_349 ,
V_459 ? & V_461 : NULL , V_10 ) ;
V_35:
return V_23 ;
}
static int F_167 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_57 * V_58 , void * const * V_109 )
{
return - V_468 ;
}
static int F_168 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_388 ;
int V_23 = 0 , V_469 ;
struct V_412 * V_413 ;
struct V_386 * V_387 ;
struct V_342 V_343 ;
if ( ( V_413 = V_109 [ V_420 - 1 ] ) == NULL )
return - V_70 ;
V_388 = F_169 ( V_413 -> V_429 ) ;
if ( V_388 >= V_470 )
return - V_70 ;
V_469 = ( V_58 -> V_320 == V_437 ) ;
V_387 = F_170 ( V_10 , V_147 , V_395 ,
V_388 , V_413 -> V_429 , V_469 , & V_23 ) ;
if ( V_387 == NULL )
return - V_315 ;
if ( V_469 ) {
F_161 ( V_387 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
V_343 . V_303 = V_58 -> V_61 ;
V_343 . V_344 = V_58 -> V_323 ;
V_343 . V_60 . V_436 = 1 ;
V_343 . V_326 = V_327 ;
F_155 ( V_387 , V_388 , & V_343 ) ;
} else {
V_23 = F_163 ( V_3 , V_387 , V_58 , V_388 ) ;
}
V_35:
F_156 ( V_387 ) ;
if ( V_469 && V_23 == 0 )
F_162 ( V_10 ) ;
return V_23 ;
}
static int F_171 ( struct V_386 * V_387 , int V_388 , int V_365 , void * V_366 )
{
struct V_1 * V_6 = V_366 ;
struct V_41 * V_345 ;
struct V_57 * V_307 ;
int V_23 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_345 = F_146 ( V_387 ) ;
if ( F_94 ( V_345 ) )
return F_95 ( V_345 ) ;
V_23 = F_147 ( V_345 , V_387 , V_388 ) ;
if ( V_23 < 0 )
return V_23 ;
V_307 = (struct V_57 * ) V_345 -> V_60 ;
V_307 -> V_319 = V_6 -> V_7 . V_367 ;
V_307 -> V_320 = V_471 ;
V_307 -> V_146 = V_126 ;
V_307 -> V_62 = 0 ;
V_307 -> V_61 = V_365 + 1 ;
V_307 -> V_323 = V_6 -> V_7 . V_369 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_63 , V_56 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_345 ;
return 0 ;
}
static int F_172 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return V_391 ( V_10 , & V_6 -> V_7 . V_370 . V_472 , F_171 , ( void * ) V_6 ) ;
}
static void F_173 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( (struct V_2 * ) V_6 ) ;
F_140 ( & V_6 -> V_7 . V_370 . V_472 , V_10 ) ;
}
static int F_174 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_373 ;
V_6 -> V_7 . V_367 = V_58 -> V_319 ;
V_6 -> V_7 . V_369 = V_58 -> V_323 ;
V_6 -> V_7 . V_7 = F_172 ;
V_6 -> V_7 . V_9 = F_173 ;
F_139 ( & V_6 -> V_7 . V_370 . V_472 , V_395 ) ;
return F_38 ( V_6 ) ;
}
static int F_175 ( const struct V_342 * V_343 )
{
struct V_41 * V_473 ;
struct V_57 * V_58 ;
V_473 = F_41 ( sizeof( struct V_57 ) + 16 , V_63 ) ;
if ( ! V_473 )
return - V_44 ;
V_58 = (struct V_57 * ) F_43 ( V_473 , sizeof( struct V_57 ) ) ;
V_58 -> V_320 = V_474 ;
V_58 -> V_61 = V_343 -> V_303 ;
V_58 -> V_323 = V_343 -> V_344 ;
V_58 -> V_319 = V_29 ;
V_58 -> V_62 = ( V_71 ) 0 ;
V_58 -> V_146 = V_126 ;
V_58 -> V_72 = ( sizeof( struct V_57 ) / sizeof( V_73 ) ) ;
V_58 -> V_322 = 0 ;
F_34 ( V_473 , V_63 , V_52 , NULL , V_343 -> V_10 ) ;
return 0 ;
}
static int F_176 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_57 * V_58 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_342 V_343 ;
int V_23 , V_50 ;
V_23 = F_177 ( V_10 , V_395 , true ) ;
V_50 = F_123 ( V_3 , V_58 ) ;
if ( V_23 || V_50 ) {
if ( V_23 == - V_49 )
return 0 ;
return V_23 ;
}
V_343 . V_60 . type = V_395 ;
V_343 . V_326 = V_475 ;
V_343 . V_344 = V_58 -> V_323 ;
V_343 . V_303 = V_58 -> V_61 ;
V_343 . V_10 = V_10 ;
F_155 ( NULL , 0 , & V_343 ) ;
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
V_23 = - V_305 ;
if ( V_476 [ V_58 -> V_320 ] )
V_23 = V_476 [ V_58 -> V_320 ] ( V_3 , V_8 , V_58 , V_109 ) ;
}
return V_23 ;
}
static struct V_57 * F_179 ( struct V_41 * V_8 , int * V_477 )
{
struct V_57 * V_58 = NULL ;
if ( V_8 -> V_83 < sizeof( * V_58 ) ) {
* V_477 = - V_478 ;
} else {
V_58 = (struct V_57 * ) V_8 -> V_60 ;
if ( V_58 -> V_319 != V_29 ||
V_58 -> V_322 != 0 ||
( V_58 -> V_320 <= V_479 ||
V_58 -> V_320 > V_480 ) ) {
V_58 = NULL ;
* V_477 = - V_70 ;
} else if ( V_58 -> V_72 != ( V_8 -> V_83 /
sizeof( V_73 ) ) ||
V_58 -> V_72 < ( sizeof( struct V_57 ) /
sizeof( V_73 ) ) ) {
V_58 = NULL ;
* V_477 = - V_478 ;
} else {
* V_477 = 0 ;
}
}
return V_58 ;
}
static inline int F_180 ( const struct V_398 * V_399 ,
const struct V_210 * V_481 )
{
unsigned int V_195 = V_481 -> V_214 . V_215 ;
if ( V_195 >= sizeof( V_399 -> V_482 ) * 8 )
return 0 ;
return ( V_399 -> V_482 >> V_195 ) & 1 ;
}
static inline int F_181 ( const struct V_398 * V_399 ,
const struct V_210 * V_481 )
{
unsigned int V_195 = V_481 -> V_214 . V_215 ;
if ( V_195 >= sizeof( V_399 -> V_483 ) * 8 )
return 0 ;
return ( V_399 -> V_483 >> V_195 ) & 1 ;
}
static int F_182 ( const struct V_398 * V_399 )
{
int V_349 , V_484 = 0 ;
for ( V_349 = 0 ; ; V_349 ++ ) {
const struct V_210 * V_186 = F_119 ( V_349 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( F_180 ( V_399 , V_186 ) && V_186 -> V_357 )
V_484 += sizeof( struct V_485 ) ;
}
return V_484 + sizeof( struct V_486 ) ;
}
static int F_183 ( const struct V_398 * V_399 )
{
int V_349 , V_461 , V_484 = 0 ;
for ( V_349 = 0 ; ; V_349 ++ ) {
const struct V_210 * V_188 = F_120 ( V_349 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_213 )
continue;
if ( ! ( F_181 ( V_399 , V_188 ) && V_188 -> V_357 ) )
continue;
for ( V_461 = 1 ; ; V_461 ++ ) {
const struct V_210 * V_186 = F_119 ( V_461 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( F_180 ( V_399 , V_186 ) && V_186 -> V_357 )
V_484 += sizeof( struct V_485 ) ;
}
}
return V_484 + sizeof( struct V_486 ) ;
}
static void F_184 ( struct V_41 * V_8 , const struct V_398 * V_399 )
{
struct V_486 * V_74 ;
int V_349 ;
V_74 = (struct V_486 * ) F_43 ( V_8 , sizeof( struct V_486 ) ) ;
V_74 -> V_487 = sizeof( struct V_486 ) / 8 ;
V_74 -> V_488 = V_489 ;
V_74 -> V_490 = 32 ;
memset ( V_74 -> V_491 , 0 , sizeof( V_74 -> V_491 ) ) ;
for ( V_349 = 0 ; ; V_349 ++ ) {
const struct V_210 * V_186 = F_119 ( V_349 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( F_180 ( V_399 , V_186 ) && V_186 -> V_357 ) {
struct V_485 * V_343 ;
V_343 = (struct V_485 * ) F_43 ( V_8 , sizeof( struct V_485 ) ) ;
memset ( V_343 , 0 , sizeof( * V_343 ) ) ;
V_74 -> V_487 += sizeof( struct V_485 ) / 8 ;
V_343 -> V_492 = V_186 -> V_214 . V_215 ;
V_343 -> V_493 = V_186 -> V_214 . V_494 ;
V_343 -> V_495 = V_186 -> V_214 . V_496 ;
V_343 -> V_497 = 24 * 60 * 60 ;
V_343 -> V_498 = 20 * 60 * 60 ;
V_343 -> V_499 = 8 * 60 * 60 ;
V_343 -> V_500 = 7 * 60 * 60 ;
}
}
}
static void F_185 ( struct V_41 * V_8 , const struct V_398 * V_399 )
{
struct V_486 * V_74 ;
int V_349 , V_461 ;
V_74 = (struct V_486 * ) F_43 ( V_8 , sizeof( struct V_486 ) ) ;
V_74 -> V_487 = sizeof( struct V_486 ) / 8 ;
V_74 -> V_488 = V_489 ;
V_74 -> V_490 = 32 ;
memset ( V_74 -> V_491 , 0 , sizeof( V_74 -> V_491 ) ) ;
for ( V_349 = 0 ; ; V_349 ++ ) {
const struct V_210 * V_188 = F_120 ( V_349 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_213 )
continue;
if ( ! ( F_181 ( V_399 , V_188 ) && V_188 -> V_357 ) )
continue;
for ( V_461 = 1 ; ; V_461 ++ ) {
struct V_485 * V_343 ;
const struct V_210 * V_186 = F_119 ( V_461 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( ! ( F_180 ( V_399 , V_186 ) && V_186 -> V_357 ) )
continue;
V_343 = (struct V_485 * ) F_43 ( V_8 , sizeof( struct V_485 ) ) ;
memset ( V_343 , 0 , sizeof( * V_343 ) ) ;
V_74 -> V_487 += sizeof( struct V_485 ) / 8 ;
V_343 -> V_492 = V_186 -> V_214 . V_215 ;
V_343 -> V_493 = V_186 -> V_214 . V_494 ;
V_343 -> V_495 = V_186 -> V_214 . V_496 ;
V_343 -> V_501 = V_188 -> V_214 . V_215 ;
V_343 -> V_502 = V_188 -> V_214 . V_494 ;
V_343 -> V_503 = V_188 -> V_214 . V_496 ;
V_343 -> V_497 = 24 * 60 * 60 ;
V_343 -> V_498 = 20 * 60 * 60 ;
V_343 -> V_499 = 8 * 60 * 60 ;
V_343 -> V_500 = 7 * 60 * 60 ;
}
}
}
static int F_186 ( struct V_386 * V_387 , const struct V_342 * V_343 )
{
return 0 ;
}
static int F_187 ( struct V_143 * V_165 , const struct V_342 * V_343 )
{
struct V_41 * V_345 ;
struct V_57 * V_307 ;
int V_504 ;
int V_167 ;
V_504 = V_343 -> V_60 . V_504 ;
if ( V_504 )
V_167 = 2 ;
else
V_167 = 1 ;
V_345 = F_76 ( V_165 , V_167 ) ;
if ( F_94 ( V_345 ) )
return F_95 ( V_345 ) ;
V_307 = (struct V_57 * ) V_345 -> V_60 ;
V_307 -> V_319 = V_29 ;
V_307 -> V_320 = V_341 ;
V_307 -> V_146 = F_54 ( V_165 -> V_195 . V_134 ) ;
V_307 -> V_62 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_61 = 0 ;
V_307 -> V_323 = 0 ;
F_34 ( V_345 , V_63 , V_54 , NULL , F_102 ( V_165 ) ) ;
return 0 ;
}
static int F_188 ( struct V_143 * V_165 , const struct V_342 * V_343 )
{
struct V_10 * V_10 = V_165 ? F_102 ( V_165 ) : V_343 -> V_10 ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
if ( F_3 ( & V_12 -> V_17 ) == 0 )
return 0 ;
switch ( V_343 -> V_326 ) {
case V_340 :
return F_187 ( V_165 , V_343 ) ;
case V_334 :
case V_336 :
case V_338 :
return F_101 ( V_165 , V_343 ) ;
case V_364 :
return F_124 ( V_343 ) ;
case V_505 :
break;
default:
F_11 ( L_3 , V_343 -> V_326 ) ;
break;
}
return 0 ;
}
static int F_189 ( struct V_386 * V_387 , int V_388 , const struct V_342 * V_343 )
{
if ( V_387 && V_387 -> type != V_395 )
return 0 ;
switch ( V_343 -> V_326 ) {
case V_333 :
return F_186 ( V_387 , V_343 ) ;
case V_327 :
case V_329 :
case V_331 :
return F_148 ( V_387 , V_388 , V_343 ) ;
case V_475 :
if ( V_343 -> V_60 . type != V_395 )
break;
return F_175 ( V_343 ) ;
default:
F_11 ( L_2 , V_343 -> V_326 ) ;
break;
}
return 0 ;
}
static T_6 F_190 ( void )
{
T_6 V_506 ;
static T_10 V_507 ;
do {
V_506 = F_191 ( & V_507 ) ;
} while ( ! V_506 );
return V_506 ;
}
static bool F_192 ( const struct V_342 * V_343 )
{
struct V_11 * V_12 = F_8 ( V_343 -> V_10 , V_13 ) ;
struct V_2 * V_3 ;
bool V_508 = false ;
F_35 () ;
F_36 (sk, &net_pfkey->table) {
if ( F_1 ( V_3 ) -> V_55 ) {
V_508 = true ;
break;
}
}
F_37 () ;
return V_508 ;
}
static int F_193 ( struct V_143 * V_165 , struct V_398 * V_399 , struct V_386 * V_387 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
struct V_75 * V_78 ;
struct V_412 * V_413 ;
int V_179 ;
int V_176 ;
struct V_89 * V_90 ;
struct V_174 * V_175 ;
int V_97 = 0 ;
V_179 = F_62 ( V_165 -> V_182 . V_135 ) ;
if ( ! V_179 )
return - V_70 ;
V_176 = sizeof( struct V_57 ) +
( sizeof( struct V_75 ) * 2 ) +
( V_179 * 2 ) +
sizeof( struct V_412 ) ;
if ( V_165 -> V_195 . V_134 == V_129 )
V_176 += F_182 ( V_399 ) ;
else if ( V_165 -> V_195 . V_134 == V_131 )
V_176 += F_183 ( V_399 ) ;
if ( ( V_175 = V_165 -> V_183 ) ) {
V_97 = F_63 ( V_175 -> V_104 ) ;
V_176 += sizeof( struct V_89 ) + V_97 ;
}
V_8 = F_41 ( V_176 + 16 , V_63 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
V_58 -> V_319 = V_29 ;
V_58 -> V_320 = V_509 ;
V_58 -> V_146 = F_54 ( V_165 -> V_195 . V_134 ) ;
V_58 -> V_72 = V_176 / sizeof( V_73 ) ;
V_58 -> V_62 = 0 ;
V_58 -> V_322 = 0 ;
V_58 -> V_61 = V_165 -> V_199 . V_303 = F_190 () ;
V_58 -> V_323 = 0 ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_179 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_179 ) /
sizeof( V_73 ) ;
V_78 -> V_249 = V_120 ;
V_78 -> V_250 = 0 ;
V_78 -> V_251 = 0 ;
V_78 -> V_87 =
F_66 ( & V_165 -> V_182 . V_185 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_78 = (struct V_75 * ) F_43 ( V_8 ,
sizeof( struct V_75 ) + V_179 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_179 ) /
sizeof( V_73 ) ;
V_78 -> V_249 = V_121 ;
V_78 -> V_250 = 0 ;
V_78 -> V_251 = 0 ;
V_78 -> V_87 =
F_66 ( & V_165 -> V_195 . V_252 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_413 = (struct V_412 * ) F_43 ( V_8 , sizeof( struct V_412 ) ) ;
V_413 -> V_414 = sizeof( struct V_412 ) / sizeof( V_73 ) ;
V_413 -> V_419 = V_420 ;
V_413 -> V_421 = V_425 ;
V_413 -> V_427 = V_510 + 1 ;
V_413 -> V_428 = 0 ;
V_413 -> V_429 = V_387 -> V_430 ;
V_413 -> V_431 = V_387 -> V_432 ;
if ( V_165 -> V_195 . V_134 == V_129 )
F_184 ( V_8 , V_399 ) ;
else if ( V_165 -> V_195 . V_134 == V_131 )
F_185 ( V_8 , V_399 ) ;
if ( V_175 ) {
V_90 = (struct V_89 * ) F_43 ( V_8 ,
sizeof( struct V_89 ) + V_97 ) ;
V_90 -> V_93 =
( sizeof( struct V_89 ) + V_97 ) / sizeof( V_73 ) ;
V_90 -> V_99 = V_124 ;
V_90 -> V_101 = V_175 -> V_100 ;
V_90 -> V_103 = V_175 -> V_102 ;
V_90 -> V_91 = V_175 -> V_104 ;
memcpy ( V_90 + 1 , V_175 -> V_286 ,
V_175 -> V_104 ) ;
}
return F_34 ( V_8 , V_63 , V_54 , NULL , F_102 ( V_165 ) ) ;
}
static struct V_386 * F_194 ( struct V_2 * V_3 , int V_511 ,
T_7 * V_60 , int V_83 , int * V_388 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_386 * V_387 ;
struct V_412 * V_413 = (struct V_412 * ) V_60 ;
struct V_89 * V_90 ;
switch ( V_3 -> V_38 ) {
case V_85 :
if ( V_511 != V_512 ) {
* V_388 = - V_305 ;
return NULL ;
}
break;
#if F_45 ( V_80 )
case V_88 :
if ( V_511 != V_513 ) {
* V_388 = - V_305 ;
return NULL ;
}
break;
#endif
default:
* V_388 = - V_70 ;
return NULL ;
}
* V_388 = - V_70 ;
if ( V_83 < sizeof( struct V_412 ) ||
V_413 -> V_414 * 8 > V_83 ||
V_413 -> V_421 > V_514 ||
( ! V_413 -> V_427 || V_413 -> V_427 > V_515 ) )
return NULL ;
V_387 = F_150 ( V_10 , V_63 ) ;
if ( V_387 == NULL ) {
* V_388 = - V_44 ;
return NULL ;
}
V_387 -> V_423 = ( V_413 -> V_421 == V_422 ?
V_439 : V_424 ) ;
V_387 -> V_230 . V_240 = V_442 ;
V_387 -> V_230 . V_233 = V_442 ;
V_387 -> V_230 . V_239 = V_442 ;
V_387 -> V_230 . V_231 = V_442 ;
V_387 -> V_135 = V_3 -> V_38 ;
V_387 -> V_389 = 0 ;
if ( V_413 -> V_421 == V_425 &&
( * V_388 = F_143 ( V_387 , V_413 ) ) < 0 )
goto V_35;
if ( V_83 >= ( V_413 -> V_414 * 8 +
sizeof( struct V_89 ) ) ) {
char * V_74 = ( char * ) V_413 ;
struct V_94 * V_96 ;
V_74 += V_413 -> V_414 * 8 ;
V_90 = (struct V_89 * ) V_74 ;
if ( V_83 < V_413 -> V_414 * 8 +
V_90 -> V_93 ) {
* V_388 = - V_70 ;
goto V_35;
}
if ( ( * V_388 = F_48 ( V_74 ) ) )
goto V_35;
V_96 = F_49 ( V_90 , V_63 ) ;
* V_388 = F_152 ( & V_387 -> V_183 , V_96 , V_63 ) ;
F_82 ( V_96 ) ;
if ( * V_388 )
goto V_35;
}
* V_388 = V_413 -> V_427 - 1 ;
return V_387 ;
V_35:
V_387 -> V_392 . V_443 = 1 ;
F_157 ( V_387 ) ;
return NULL ;
}
static int F_195 ( struct V_143 * V_165 , T_4 * V_516 , T_5 V_254 )
{
struct V_41 * V_8 ;
struct V_57 * V_58 ;
struct V_144 * V_136 ;
struct V_75 * V_78 ;
struct V_192 * V_272 ;
int V_179 ;
int V_176 ;
T_8 V_125 = ( V_165 -> V_195 . V_134 == V_131 ? V_130 : 0 ) ;
struct V_180 * V_181 = NULL ;
V_179 = F_62 ( V_165 -> V_182 . V_135 ) ;
if ( ! V_179 )
return - V_70 ;
if ( ! V_125 )
return - V_70 ;
if ( ! V_165 -> V_189 )
return - V_70 ;
V_181 = V_165 -> V_189 ;
V_176 = sizeof( struct V_57 ) +
sizeof( struct V_144 ) +
( sizeof( struct V_75 ) * 2 ) +
( V_179 * 2 ) +
( sizeof( struct V_192 ) * 2 ) ;
V_8 = F_41 ( V_176 + 16 , V_63 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
V_58 -> V_319 = V_29 ;
V_58 -> V_320 = V_517 ;
V_58 -> V_146 = V_125 ;
V_58 -> V_72 = V_176 / sizeof( V_73 ) ;
V_58 -> V_62 = 0 ;
V_58 -> V_322 = 0 ;
V_58 -> V_61 = V_165 -> V_199 . V_303 = F_190 () ;
V_58 -> V_323 = 0 ;
V_136 = (struct V_144 * ) F_43 ( V_8 , sizeof( struct V_144 ) ) ;
V_136 -> V_193 = sizeof( struct V_144 ) / sizeof( V_73 ) ;
V_136 -> V_194 = V_145 ;
V_136 -> V_148 = V_165 -> V_195 . V_196 ;
V_136 -> V_197 = 0 ;
V_136 -> V_202 = 0 ;
V_136 -> V_209 = 0 ;
V_136 -> V_216 = 0 ;
V_136 -> V_218 = 0 ;
V_78 = (struct V_75 * )
F_43 ( V_8 , sizeof( struct V_75 ) + V_179 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_179 ) /
sizeof( V_73 ) ;
V_78 -> V_249 = V_120 ;
V_78 -> V_250 = 0 ;
V_78 -> V_251 = 0 ;
V_78 -> V_87 =
F_66 ( & V_165 -> V_182 . V_185 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_272 = (struct V_192 * ) F_43 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_73 ) ;
V_272 -> V_279 = V_280 ;
V_272 -> V_281 = V_181 -> V_282 ;
V_272 -> V_283 = 0 ;
V_78 = (struct V_75 * )
F_43 ( V_8 , sizeof( struct V_75 ) + V_179 ) ;
V_78 -> V_86 =
( sizeof( struct V_75 ) + V_179 ) /
sizeof( V_73 ) ;
V_78 -> V_249 = V_121 ;
V_78 -> V_250 = 0 ;
V_78 -> V_251 = 0 ;
V_78 -> V_87 =
F_66 ( V_516 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_78 -> V_87 )
F_74 () ;
V_272 = (struct V_192 * ) F_43 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_73 ) ;
V_272 -> V_279 = V_284 ;
V_272 -> V_281 = V_254 ;
V_272 -> V_283 = 0 ;
return F_34 ( V_8 , V_63 , V_54 , NULL , F_102 ( V_165 ) ) ;
}
static int F_196 ( struct V_41 * V_8 , int V_518 , int type ,
const struct V_444 * V_184 )
{
struct V_75 * V_78 ;
V_78 = (struct V_75 * ) F_43 ( V_8 , sizeof( struct V_75 ) + V_518 ) ;
V_78 -> V_86 = ( sizeof( struct V_75 ) + V_518 ) / 8 ;
V_78 -> V_249 = type ;
V_78 -> V_250 = V_184 -> V_134 ;
V_78 -> V_251 = 0 ;
switch ( type ) {
case V_120 :
V_78 -> V_87 = V_184 -> V_253 ;
F_66 ( & V_184 -> V_185 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_184 -> V_135 ) ;
break;
case V_121 :
V_78 -> V_87 = V_184 -> V_417 ;
F_66 ( & V_184 -> V_252 , 0 ,
(struct V_77 * ) ( V_78 + 1 ) ,
V_184 -> V_135 ) ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static int F_197 ( struct V_41 * V_8 , const struct V_460 * V_461 )
{
struct V_458 * V_459 ;
T_7 * V_136 ;
int V_135 = V_461 -> V_135 ;
int V_409 = F_57 ( V_135 ) ;
int V_519 ;
V_519 = ( sizeof( struct V_458 ) +
F_164 ( V_135 ) ) ;
V_459 = (struct V_458 * ) F_43 ( V_8 , V_519 ) ;
memset ( V_459 , 0 , V_519 ) ;
V_459 -> V_465 = V_519 / 8 ;
V_459 -> V_520 = V_462 ;
V_459 -> V_464 = V_461 -> V_463 ;
V_136 = ( T_7 * ) ( V_459 + 1 ) ;
if ( ! F_66 ( & V_461 -> V_466 , 0 , (struct V_77 * ) V_136 , V_135 ) ||
! F_66 ( & V_461 -> V_467 , 0 , (struct V_77 * ) ( V_136 + V_409 ) , V_135 ) )
return - V_70 ;
return 0 ;
}
static int F_198 ( struct V_41 * V_8 ,
V_71 V_134 , V_71 V_149 , int V_521 ,
T_11 V_270 , V_71 V_135 ,
const T_4 * V_105 , const T_4 * V_106 )
{
struct V_396 * V_397 ;
T_7 * V_136 ;
int V_409 = F_57 ( V_135 ) ;
int V_519 ;
V_519 = sizeof( struct V_396 ) +
F_164 ( V_135 ) ;
V_397 = (struct V_396 * ) F_43 ( V_8 , V_519 ) ;
memset ( V_397 , 0 , V_519 ) ;
V_397 -> V_415 = V_519 ;
V_397 -> V_403 = V_134 ;
V_397 -> V_402 = V_149 ;
V_397 -> V_404 = V_521 ;
V_397 -> V_408 = V_270 ;
V_136 = ( T_7 * ) ( V_397 + 1 ) ;
if ( ! F_66 ( V_105 , 0 , (struct V_77 * ) V_136 , V_135 ) ||
! F_66 ( V_106 , 0 , (struct V_77 * ) ( V_136 + V_409 ) , V_135 ) )
return - V_70 ;
return 0 ;
}
static int F_199 ( const struct V_444 * V_184 , T_7 V_388 , T_7 type ,
const struct V_448 * V_449 , int V_522 ,
const struct V_460 * V_461 )
{
int V_349 ;
int V_523 ;
int V_176 = 0 ;
int V_524 = 0 ;
struct V_41 * V_8 ;
struct V_57 * V_58 ;
struct V_412 * V_413 ;
const struct V_448 * V_525 ;
if ( type != V_395 )
return 0 ;
if ( V_522 <= 0 || V_522 > V_400 )
return - V_70 ;
if ( V_461 != NULL ) {
V_176 += F_63 ( sizeof( struct V_458 ) +
F_164 ( V_461 -> V_135 ) ) ;
}
V_523 = F_62 ( V_184 -> V_135 ) ;
if ( ! V_523 )
return - V_70 ;
V_176 += ( sizeof( struct V_75 ) + V_523 ) * 2 ;
V_524 += sizeof( struct V_412 ) ;
for ( V_349 = 0 , V_525 = V_449 ; V_349 < V_522 ; V_349 ++ , V_525 ++ ) {
V_524 += sizeof( struct V_396 ) +
F_164 ( V_525 -> V_453 ) ;
V_524 += sizeof( struct V_396 ) +
F_164 ( V_525 -> V_456 ) ;
}
V_176 += sizeof( struct V_57 ) + V_524 ;
V_8 = F_41 ( V_176 , V_63 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_58 = (struct V_57 * ) F_43 ( V_8 , sizeof( struct V_57 ) ) ;
V_58 -> V_319 = V_29 ;
V_58 -> V_320 = V_526 ;
V_58 -> V_146 = F_54 ( V_449 -> V_134 ) ;
V_58 -> V_72 = V_176 / 8 ;
V_58 -> V_62 = 0 ;
V_58 -> V_322 = 0 ;
V_58 -> V_61 = 0 ;
V_58 -> V_323 = 0 ;
if ( V_461 != NULL && ( F_197 ( V_8 , V_461 ) < 0 ) )
goto V_23;
F_196 ( V_8 , V_523 , V_120 , V_184 ) ;
F_196 ( V_8 , V_523 , V_121 , V_184 ) ;
V_413 = (struct V_412 * ) F_43 ( V_8 , sizeof( struct V_412 ) ) ;
V_413 -> V_414 = V_524 / 8 ;
V_413 -> V_419 = V_420 ;
V_413 -> V_421 = V_425 ;
V_413 -> V_427 = V_388 + 1 ;
V_413 -> V_428 = 0 ;
V_413 -> V_429 = 0 ;
V_413 -> V_431 = 0 ;
for ( V_349 = 0 , V_525 = V_449 ; V_349 < V_522 ; V_349 ++ , V_525 ++ ) {
int V_149 = F_64 ( V_525 -> V_149 ) ;
if ( V_149 < 0 )
goto V_23;
if ( F_198 ( V_8 , V_525 -> V_134 , V_149 ,
( V_525 -> V_270 ? V_407 : V_434 ) ,
V_525 -> V_270 , V_525 -> V_453 ,
& V_525 -> V_451 , & V_525 -> V_452 ) < 0 )
goto V_23;
if ( F_198 ( V_8 , V_525 -> V_134 , V_149 ,
( V_525 -> V_270 ? V_407 : V_434 ) ,
V_525 -> V_270 , V_525 -> V_456 ,
& V_525 -> V_454 , & V_525 -> V_455 ) < 0 )
goto V_23;
}
F_34 ( V_8 , V_63 , V_52 , NULL , & V_527 ) ;
return 0 ;
V_23:
F_5 ( V_8 ) ;
return - V_70 ;
}
static int F_199 ( const struct V_444 * V_184 , T_7 V_388 , T_7 type ,
const struct V_448 * V_449 , int V_522 ,
const struct V_460 * V_461 )
{
return - V_468 ;
}
static int F_200 ( struct V_528 * V_528 ,
struct V_20 * V_2 , struct V_529 * V_530 , T_12 V_83 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_41 * V_8 = NULL ;
struct V_57 * V_58 = NULL ;
int V_23 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
V_23 = - V_305 ;
if ( V_530 -> V_531 & V_532 )
goto V_35;
V_23 = - V_478 ;
if ( ( unsigned int ) V_83 > V_3 -> V_533 - 32 )
goto V_35;
V_23 = - V_44 ;
V_8 = F_41 ( V_83 , V_33 ) ;
if ( V_8 == NULL )
goto V_35;
V_23 = - V_534 ;
if ( F_201 ( F_43 ( V_8 , V_83 ) , V_530 -> V_535 , V_83 ) )
goto V_35;
V_58 = F_179 ( V_8 , & V_23 ) ;
if ( ! V_58 )
goto V_35;
F_15 ( & V_10 -> V_536 . V_537 ) ;
V_23 = F_178 ( V_3 , V_8 , V_58 ) ;
F_17 ( & V_10 -> V_536 . V_537 ) ;
V_35:
if ( V_23 && V_58 && F_40 ( V_58 , V_23 , V_3 ) == 0 )
V_23 = 0 ;
F_5 ( V_8 ) ;
return V_23 ? : V_83 ;
}
static int F_202 ( struct V_528 * V_528 ,
struct V_20 * V_2 , struct V_529 * V_530 , T_12 V_83 ,
int V_219 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_8 ;
int V_538 , V_23 ;
V_23 = - V_70 ;
if ( V_219 & ~ ( V_539 | V_540 | V_541 | V_542 ) )
goto V_35;
V_8 = F_203 ( V_3 , V_219 , V_219 & V_540 , & V_23 ) ;
if ( V_8 == NULL )
goto V_35;
V_538 = V_8 -> V_83 ;
if ( V_538 > V_83 ) {
V_530 -> V_531 |= V_541 ;
V_538 = V_83 ;
}
F_204 ( V_8 ) ;
V_23 = F_205 ( V_8 , 0 , V_530 -> V_535 , V_538 ) ;
if ( V_23 )
goto V_543;
F_206 ( V_530 , V_3 , V_8 ) ;
V_23 = ( V_219 & V_541 ) ? V_8 -> V_83 : V_538 ;
if ( V_6 -> V_7 . V_7 != NULL &&
3 * F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 )
F_38 ( V_6 ) ;
V_543:
F_207 ( V_3 , V_8 ) ;
V_35:
return V_23 ;
}
static int F_208 ( struct V_544 * V_545 , void * V_546 )
{
struct V_2 * V_547 = F_209 ( V_546 ) ;
if ( V_546 == V_548 )
F_210 ( V_545 , L_4 ) ;
else
F_210 ( V_545 , L_5 ,
V_547 ,
F_3 ( & V_547 -> V_549 ) ,
F_211 ( V_547 ) ,
F_212 ( V_547 ) ,
F_213 ( F_214 ( V_545 ) , F_215 ( V_547 ) ) ,
F_216 ( V_547 )
) ;
return 0 ;
}
static void * F_217 ( struct V_544 * V_545 , T_13 * V_550 )
__acquires( T_14 )
{
struct V_10 * V_10 = F_218 ( V_545 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_35 () ;
return F_219 ( & V_12 -> V_19 , * V_550 ) ;
}
static void * F_220 ( struct V_544 * V_545 , void * V_546 , T_13 * V_550 )
{
struct V_10 * V_10 = F_218 ( V_545 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
return F_221 ( V_546 , & V_12 -> V_19 , V_550 ) ;
}
static void F_222 ( struct V_544 * V_545 , void * V_546 )
__releases( T_14 )
{
F_37 () ;
}
static int F_223 ( struct V_551 * V_551 , struct V_552 * V_552 )
{
return F_224 ( V_551 , V_552 , & V_553 ,
sizeof( struct V_554 ) ) ;
}
static int T_15 F_225 ( struct V_10 * V_10 )
{
struct V_555 * V_556 ;
V_556 = F_226 ( L_6 , 0 , V_10 -> V_557 , & V_558 ) ;
if ( V_556 == NULL )
return - V_31 ;
return 0 ;
}
static void T_16 F_227 ( struct V_10 * V_10 )
{
F_228 ( L_6 , V_10 -> V_557 ) ;
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
int V_559 ;
F_230 ( & V_12 -> V_19 ) ;
F_231 ( & V_12 -> V_17 , 0 ) ;
V_559 = F_225 ( V_10 ) ;
return V_559 ;
}
static void T_16 F_232 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_227 ( V_10 ) ;
F_42 ( ! F_233 ( & V_12 -> V_19 ) ) ;
}
static void T_17 F_234 ( void )
{
F_235 ( & V_560 ) ;
F_236 ( V_32 ) ;
F_237 ( & V_561 ) ;
F_238 ( & V_34 ) ;
}
static int T_18 F_239 ( void )
{
int V_23 = F_240 ( & V_34 , 0 ) ;
if ( V_23 != 0 )
goto V_35;
V_23 = F_241 ( & V_561 ) ;
if ( V_23 != 0 )
goto V_562;
V_23 = F_242 ( & V_563 ) ;
if ( V_23 != 0 )
goto V_564;
V_23 = F_243 ( & V_560 ) ;
if ( V_23 != 0 )
goto V_565;
V_35:
return V_23 ;
V_565:
F_236 ( V_32 ) ;
V_564:
F_237 ( & V_561 ) ;
V_562:
F_238 ( & V_34 ) ;
goto V_35;
}
