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
V_3 -> V_46 ( V_3 , ( * V_42 ) -> V_47 ) ;
* V_42 = NULL ;
V_23 = 0 ;
}
}
F_28 ( V_3 ) ;
return V_23 ;
}
static int F_34 ( struct V_41 * V_8 , T_1 V_43 ,
int V_48 , struct V_2 * V_49 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
struct V_2 * V_3 ;
struct V_41 * V_42 = NULL ;
int V_23 = - V_50 ;
if ( ! V_8 )
return - V_31 ;
F_35 () ;
F_36 (sk, &net_pfkey->table) {
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_51 ;
if ( V_6 -> V_52 )
F_29 ( V_8 , & V_42 , V_43 , V_3 ) ;
if ( V_3 == V_49 )
continue;
if ( V_48 != V_53 ) {
if ( V_48 & V_54 )
continue;
if ( ( V_48 & V_55 ) &&
! V_6 -> V_56 )
continue;
if ( V_48 & V_57 )
continue;
}
V_51 = F_29 ( V_8 , & V_42 , V_43 , V_3 ) ;
if ( ( V_48 & V_55 ) && V_23 )
V_23 = V_51 ;
}
F_37 () ;
if ( V_49 != NULL )
V_23 = F_29 ( V_8 , & V_42 , V_43 , V_49 ) ;
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
F_34 ( V_6 -> V_7 . V_8 , V_64 , V_57 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = NULL ;
}
F_4 ( V_6 ) ;
return V_60 ;
}
static inline void F_39 ( struct V_58 * V_65 ,
const struct V_58 * V_66 )
{
* V_65 = * V_66 ;
}
static int F_40 ( const struct V_58 * V_66 , int V_23 , struct V_2 * V_3 )
{
struct V_41 * V_8 = F_41 ( sizeof( struct V_58 ) + 16 , V_33 ) ;
struct V_58 * V_59 ;
if ( ! V_8 )
return - V_44 ;
V_23 = - V_23 ;
if ( V_23 == V_67 ||
V_23 == V_68 ||
V_23 == V_69 )
V_23 = V_70 ;
if ( V_23 >= 512 )
V_23 = V_71 ;
F_42 ( V_23 <= 0 || V_23 >= 256 ) ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
F_39 ( V_59 , V_66 ) ;
V_59 -> V_63 = ( V_72 ) V_23 ;
V_59 -> V_73 = ( sizeof( struct V_58 ) /
sizeof( V_74 ) ) ;
F_34 ( V_8 , V_33 , V_57 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_44 ( const void * V_75 )
{
const struct V_76 * V_77 = V_75 ;
const struct V_78 * V_79 = ( const struct V_78 * ) ( V_77 + 1 ) ;
const struct V_80 * sin ;
#if F_45 ( V_81 )
const struct V_82 * V_83 ;
#endif
int V_47 ;
switch ( V_79 -> V_84 ) {
case V_85 :
V_47 = F_46 ( sizeof( * V_77 ) + sizeof( * sin ) , sizeof( V_74 ) ) ;
if ( V_77 -> V_86 != V_47 ||
V_77 -> V_87 > 32 )
return - V_71 ;
break;
#if F_45 ( V_81 )
case V_88 :
V_47 = F_46 ( sizeof( * V_77 ) + sizeof( * V_83 ) , sizeof( V_74 ) ) ;
if ( V_77 -> V_86 != V_47 ||
V_77 -> V_87 > 128 )
return - V_71 ;
break;
#endif
default:
return - V_71 ;
break;
}
return 0 ;
}
static inline int F_47 ( const struct V_89 * V_90 )
{
return F_46 ( sizeof( struct V_89 ) +
V_90 -> V_91 ,
sizeof( V_74 ) ) ;
}
static inline int F_48 ( const void * V_75 )
{
const struct V_89 * V_90 = V_75 ;
int V_47 = V_90 -> V_91 ;
if ( V_47 > V_92 )
return - V_71 ;
V_47 = F_47 ( V_90 ) ;
if ( V_90 -> V_93 != V_47 )
return - V_71 ;
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
V_96 -> V_47 = F_47 ( V_90 ) ;
V_96 -> V_98 = V_90 -> V_99 ;
V_96 -> V_100 = V_90 -> V_101 ;
V_96 -> V_102 = V_90 -> V_103 ;
V_96 -> V_104 = V_90 -> V_91 ;
memcpy ( V_96 + 1 , V_90 + 1 ,
V_96 -> V_104 ) ;
return V_96 ;
}
static int F_51 ( const struct V_76 * V_105 ,
const struct V_76 * V_106 )
{
const struct V_78 * V_107 , * V_108 ;
if ( ! V_105 || ! V_106 )
return 0 ;
V_107 = ( const struct V_78 * ) ( V_105 + 1 ) ;
V_108 = ( const struct V_78 * ) ( V_106 + 1 ) ;
if ( V_107 -> V_84 != V_108 -> V_84 )
return 0 ;
if ( V_107 -> V_84 != V_85
#if F_45 ( V_81 )
&& V_107 -> V_84 != V_88
#endif
)
return 0 ;
return 1 ;
}
static int F_52 ( struct V_41 * V_8 , const struct V_58 * V_59 , void * * V_109 )
{
const char * V_75 = ( char * ) V_59 ;
int V_47 = V_8 -> V_47 ;
V_47 -= sizeof( * V_59 ) ;
V_75 += sizeof( * V_59 ) ;
while ( V_47 > 0 ) {
const struct V_110 * V_111 = ( const struct V_110 * ) V_75 ;
T_2 V_112 ;
int V_113 ;
V_113 = V_111 -> V_114 ;
V_113 *= sizeof( V_74 ) ;
V_112 = V_111 -> V_115 ;
if ( V_113 < sizeof( V_74 ) ||
V_113 > V_47 ||
V_112 == V_116 )
return - V_71 ;
if ( V_112 <= V_117 ) {
int V_118 = ( int ) V_119 [ V_112 ] ;
if ( V_113 < V_118 )
return - V_71 ;
if ( V_109 [ V_112 - 1 ] != NULL )
return - V_71 ;
if ( V_112 == V_120 ||
V_112 == V_121 ||
V_112 == V_122 ||
V_112 == V_123 ) {
if ( F_44 ( V_75 ) )
return - V_71 ;
}
if ( V_112 == V_124 ) {
if ( F_48 ( V_75 ) )
return - V_71 ;
}
V_109 [ V_112 - 1 ] = ( void * ) V_75 ;
}
V_75 += V_113 ;
V_47 -= V_113 ;
}
return 0 ;
}
static T_2
F_53 ( V_72 V_125 )
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
break;
default:
return 0 ;
}
}
static V_72
F_54 ( T_2 V_134 )
{
switch ( V_134 ) {
case V_129 :
return V_128 ;
case V_131 :
return V_130 ;
case V_133 :
return V_132 ;
break;
default:
return 0 ;
}
}
static V_72 F_55 ( V_72 V_134 )
{
return V_134 == V_127 ? 0 : V_134 ;
}
static V_72 F_56 ( V_72 V_134 )
{
return V_134 ? V_134 : V_127 ;
}
static inline int F_57 ( T_3 V_135 )
{
switch ( V_135 ) {
case V_85 :
return sizeof( struct V_80 ) ;
#if F_45 ( V_81 )
case V_88 :
return sizeof( struct V_82 ) ;
#endif
}
return 0 ;
}
static
int F_58 ( const struct V_78 * V_136 , T_4 * V_137 )
{
switch ( V_136 -> V_84 ) {
case V_85 :
V_137 -> V_138 =
( (struct V_80 * ) V_136 ) -> V_139 . V_107 ;
return V_85 ;
#if F_45 ( V_81 )
case V_88 :
memcpy ( V_137 -> V_140 ,
& ( (struct V_82 * ) V_136 ) -> V_141 ,
sizeof( struct V_142 ) ) ;
return V_88 ;
#endif
}
return 0 ;
}
static
int F_59 ( const struct V_76 * V_79 , T_4 * V_137 )
{
return F_58 ( (struct V_78 * ) ( V_79 + 1 ) ,
V_137 ) ;
}
static struct V_143 * F_60 ( struct V_10 * V_10 , const struct V_58 * V_59 , void * const * V_109 )
{
const struct V_144 * V_136 ;
const struct V_76 * V_79 ;
T_2 V_134 ;
unsigned short V_135 ;
T_4 * V_137 ;
V_136 = V_109 [ V_145 - 1 ] ;
if ( V_136 == NULL )
return NULL ;
V_134 = F_53 ( V_59 -> V_146 ) ;
if ( V_134 == 0 )
return NULL ;
V_79 = V_109 [ V_121 - 1 ] ;
if ( V_79 == NULL )
return NULL ;
V_135 = ( ( const struct V_78 * ) ( V_79 + 1 ) ) -> V_84 ;
switch ( V_135 ) {
case V_85 :
V_137 = ( T_4 * ) & ( ( const struct V_80 * ) ( V_79 + 1 ) ) -> V_139 ;
break;
#if F_45 ( V_81 )
case V_88 :
V_137 = ( T_4 * ) & ( ( const struct V_82 * ) ( V_79 + 1 ) ) -> V_141 ;
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
struct V_78 * V_136 ,
unsigned short V_135 )
{
switch ( V_135 ) {
case V_85 :
{
struct V_80 * sin = (struct V_80 * ) V_136 ;
sin -> V_158 = V_85 ;
sin -> V_159 = V_157 ;
sin -> V_139 . V_107 = V_137 -> V_138 ;
memset ( sin -> V_160 , 0 , sizeof( sin -> V_160 ) ) ;
return 32 ;
}
#if F_45 ( V_81 )
case V_88 :
{
struct V_82 * V_83 = (struct V_82 * ) V_136 ;
V_83 -> V_161 = V_88 ;
V_83 -> V_162 = V_157 ;
V_83 -> V_163 = 0 ;
V_83 -> V_141 = * (struct V_142 * ) V_137 -> V_140 ;
V_83 -> V_164 = 0 ;
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
struct V_58 * V_59 ;
struct V_144 * V_136 ;
struct V_168 * V_169 ;
struct V_76 * V_79 ;
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
return F_68 ( - V_71 ) ;
V_176 = sizeof( struct V_58 ) + sizeof( struct V_144 ) +
sizeof( struct V_168 ) +
( ( V_167 & 1 ) ? sizeof( struct V_168 ) : 0 ) +
( ( V_167 & 2 ) ? sizeof( struct V_168 ) : 0 ) +
sizeof( struct V_76 ) * 2 +
V_179 * 2 +
sizeof( struct V_172 ) ;
if ( ( V_175 = V_165 -> V_183 ) ) {
V_97 = F_63 ( V_175 -> V_104 ) ;
V_176 += sizeof( struct V_89 ) + V_97 ;
}
if ( ! F_69 ( & V_165 -> V_184 . V_185 , & V_165 -> V_182 . V_185 , V_165 -> V_182 . V_135 ) )
V_176 += sizeof( struct V_76 ) + V_179 ;
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
V_8 = F_41 ( V_176 + 16 , V_64 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
memset ( V_59 , 0 , V_176 ) ;
V_59 -> V_73 = V_176 / sizeof( V_74 ) ;
V_136 = (struct V_144 * ) F_43 ( V_8 , sizeof( struct V_144 ) ) ;
V_136 -> V_193 = sizeof( struct V_144 ) / sizeof( V_74 ) ;
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
sizeof( struct V_168 ) / sizeof( V_74 ) ;
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
sizeof( struct V_168 ) / sizeof( V_74 ) ;
V_169 -> V_227 = V_238 ;
V_169 -> V_229 = F_73 ( V_165 -> V_230 . V_239 ) ;
V_169 -> V_232 = F_73 ( V_165 -> V_230 . V_240 ) ;
V_169 -> V_234 = V_165 -> V_230 . V_241 ;
V_169 -> V_236 = V_165 -> V_230 . V_242 ;
}
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_74 ) ;
V_169 -> V_227 = V_243 ;
V_169 -> V_229 = V_165 -> V_244 . V_245 ;
V_169 -> V_232 = V_165 -> V_244 . V_246 ;
V_169 -> V_234 = V_165 -> V_244 . V_247 ;
V_169 -> V_236 = V_165 -> V_244 . V_248 ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_179 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_179 ) /
sizeof( V_74 ) ;
V_79 -> V_249 = V_120 ;
V_79 -> V_250 = 0 ;
V_79 -> V_251 = 0 ;
V_79 -> V_87 =
F_66 ( & V_165 -> V_182 . V_185 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_179 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_179 ) /
sizeof( V_74 ) ;
V_79 -> V_249 = V_121 ;
V_79 -> V_250 = 0 ;
V_79 -> V_251 = 0 ;
V_79 -> V_87 =
F_66 ( & V_165 -> V_195 . V_252 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
if ( ! F_69 ( & V_165 -> V_184 . V_185 , & V_165 -> V_182 . V_185 ,
V_165 -> V_182 . V_135 ) ) {
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_179 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_179 ) /
sizeof( V_74 ) ;
V_79 -> V_249 = V_122 ;
V_79 -> V_250 =
F_56 ( V_165 -> V_184 . V_134 ) ;
V_79 -> V_87 = V_165 -> V_184 . V_253 ;
V_79 -> V_251 = 0 ;
F_66 ( & V_165 -> V_184 . V_185 , V_165 -> V_184 . V_254 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
}
if ( V_166 && V_177 ) {
V_171 = (struct V_170 * ) F_43 ( V_8 ,
sizeof( struct V_170 ) + V_177 ) ;
V_171 -> V_255 = ( sizeof( struct V_170 ) + V_177 ) /
sizeof( V_74 ) ;
V_171 -> V_256 = V_257 ;
V_171 -> V_258 = V_165 -> V_186 -> V_187 ;
V_171 -> V_259 = 0 ;
memcpy ( V_171 + 1 , V_165 -> V_186 -> V_260 , ( V_165 -> V_186 -> V_187 + 7 ) / 8 ) ;
}
if ( V_166 && V_178 ) {
V_171 = (struct V_170 * ) F_43 ( V_8 ,
sizeof( struct V_170 ) + V_178 ) ;
V_171 -> V_255 = ( sizeof( struct V_170 ) +
V_178 ) / sizeof( V_74 ) ;
V_171 -> V_256 = V_261 ;
V_171 -> V_258 = V_165 -> V_188 -> V_187 ;
V_171 -> V_259 = 0 ;
memcpy ( V_171 + 1 , V_165 -> V_188 -> V_260 ,
( V_165 -> V_188 -> V_187 + 7 ) / 8 ) ;
}
V_173 = (struct V_172 * ) F_43 ( V_8 , sizeof( struct V_172 ) ) ;
V_173 -> V_262 = sizeof( struct V_172 ) / sizeof( V_74 ) ;
V_173 -> V_263 = V_264 ;
if ( ( V_149 = F_64 ( V_165 -> V_182 . V_149 ) ) < 0 ) {
F_5 ( V_8 ) ;
return F_68 ( - V_71 ) ;
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
V_271 -> V_273 = sizeof( * V_271 ) / sizeof( V_74 ) ;
V_271 -> V_274 = V_275 ;
V_271 -> V_276 = V_181 -> V_190 ;
V_271 -> V_277 [ 0 ] = 0 ;
V_271 -> V_277 [ 1 ] = 0 ;
V_271 -> V_277 [ 2 ] = 0 ;
V_272 = (struct V_192 * ) F_43 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_74 ) ;
V_272 -> V_279 = V_280 ;
V_272 -> V_281 = V_181 -> V_282 ;
V_272 -> V_283 = 0 ;
V_272 = (struct V_192 * ) F_43 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_74 ) ;
V_272 -> V_279 = V_284 ;
V_272 -> V_281 = V_181 -> V_285 ;
V_272 -> V_283 = 0 ;
}
if ( V_175 ) {
V_90 = (struct V_89 * ) F_43 ( V_8 ,
sizeof( struct V_89 ) + V_97 ) ;
V_90 -> V_93 =
( sizeof( struct V_89 ) + V_97 ) / sizeof( V_74 ) ;
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
const struct V_58 * V_59 ,
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
return F_68 ( - V_71 ) ;
if ( V_59 -> V_146 == V_130 &&
! V_109 [ V_261 - 1 ] )
return F_68 ( - V_71 ) ;
if ( V_59 -> V_146 == V_128 &&
! V_109 [ V_257 - 1 ] )
return F_68 ( - V_71 ) ;
if ( ! ! V_109 [ V_228 - 1 ] !=
! ! V_109 [ V_238 - 1 ] )
return F_68 ( - V_71 ) ;
V_134 = F_53 ( V_59 -> V_146 ) ;
if ( V_134 == 0 )
return F_68 ( - V_71 ) ;
V_23 = - V_44 ;
if ( V_136 -> V_209 > V_287 ||
( V_59 -> V_146 == V_132 &&
V_136 -> V_216 > V_288 ) ||
V_136 -> V_216 > V_289 )
return F_68 ( - V_71 ) ;
V_171 = V_109 [ V_257 - 1 ] ;
if ( V_171 != NULL &&
V_136 -> V_209 != V_290 &&
( ( V_171 -> V_258 + 7 ) / 8 == 0 ||
( V_171 -> V_258 + 7 ) / 8 > V_171 -> V_255 * sizeof( V_74 ) ) )
return F_68 ( - V_71 ) ;
V_171 = V_109 [ V_261 - 1 ] ;
if ( V_171 != NULL &&
V_136 -> V_216 != V_291 &&
( ( V_171 -> V_258 + 7 ) / 8 == 0 ||
( V_171 -> V_258 + 7 ) / 8 > V_171 -> V_255 * sizeof( V_74 ) ) )
return F_68 ( - V_71 ) ;
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
if ( V_59 -> V_146 == V_132 ) {
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
V_165 -> V_182 . V_135 = F_59 ( (struct V_76 * ) V_109 [ V_120 - 1 ] ,
& V_165 -> V_182 . V_185 ) ;
F_59 ( (struct V_76 * ) V_109 [ V_121 - 1 ] ,
& V_165 -> V_195 . V_252 ) ;
if ( V_109 [ V_264 - 1 ] ) {
const struct V_172 * V_173 = V_109 [ V_264 - 1 ] ;
int V_149 = F_65 ( V_173 -> V_265 ) ;
if ( V_149 < 0 ) {
V_23 = - V_71 ;
goto V_35;
}
V_165 -> V_182 . V_149 = V_149 ;
V_165 -> V_182 . V_270 = V_173 -> V_269 ;
}
if ( V_109 [ V_122 - 1 ] ) {
const struct V_76 * V_79 = V_109 [ V_122 - 1 ] ;
V_165 -> V_184 . V_135 = F_59 ( V_79 , & V_165 -> V_184 . V_185 ) ;
V_165 -> V_184 . V_253 = V_79 -> V_87 ;
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
V_165 -> V_199 . V_303 = V_59 -> V_62 ;
return V_165 ;
V_35:
V_165 -> V_199 . V_200 = V_304 ;
F_87 ( V_165 ) ;
return F_68 ( V_23 ) ;
}
static int F_88 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
return - V_305 ;
}
static int F_89 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_41 * V_306 ;
struct V_172 * V_173 ;
struct V_76 * V_185 , * V_252 ;
struct V_58 * V_307 ;
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
return - V_71 ;
V_134 = F_53 ( V_59 -> V_146 ) ;
if ( V_134 == 0 )
return - V_71 ;
if ( ( V_173 = V_109 [ V_264 - 1 ] ) != NULL ) {
V_149 = F_65 ( V_173 -> V_265 ) ;
if ( V_149 < 0 )
return - V_71 ;
V_270 = V_173 -> V_269 ;
} else {
V_149 = 0 ;
V_270 = 0 ;
}
V_185 = V_109 [ V_120 - 1 ] ;
V_252 = V_109 [ V_121 - 1 ] ;
V_135 = ( (struct V_78 * ) ( V_185 + 1 ) ) -> V_84 ;
switch ( V_135 ) {
case V_85 :
V_313 = ( T_4 * ) & ( (struct V_80 * ) ( V_252 + 1 ) ) -> V_139 . V_107 ;
V_312 = ( T_4 * ) & ( (struct V_80 * ) ( V_185 + 1 ) ) -> V_139 . V_107 ;
break;
#if F_45 ( V_81 )
case V_88 :
V_313 = ( T_4 * ) & ( (struct V_82 * ) ( V_252 + 1 ) ) -> V_141 ;
V_312 = ( T_4 * ) & ( (struct V_82 * ) ( V_185 + 1 ) ) -> V_141 ;
break;
#endif
}
if ( V_59 -> V_62 ) {
V_165 = F_90 ( V_10 , V_147 , V_59 -> V_62 ) ;
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
V_307 = (struct V_58 * ) V_306 -> V_61 ;
V_307 -> V_319 = V_59 -> V_319 ;
V_307 -> V_320 = V_321 ;
V_307 -> V_146 = F_54 ( V_134 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_62 = V_59 -> V_62 ;
V_307 -> V_323 = V_59 -> V_323 ;
F_87 ( V_165 ) ;
F_34 ( V_306 , V_33 , V_57 , V_3 , V_10 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_165 ;
if ( V_59 -> V_73 != sizeof( struct V_58 ) / 8 )
return - V_305 ;
if ( V_59 -> V_62 == 0 || V_59 -> V_63 == 0 )
return 0 ;
V_165 = F_90 ( V_10 , V_147 , V_59 -> V_62 ) ;
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
struct V_58 * V_59 ;
V_8 = F_75 ( V_165 ) ;
if ( F_94 ( V_8 ) )
return F_95 ( V_8 ) ;
V_59 = (struct V_58 * ) V_8 -> V_61 ;
V_59 -> V_319 = V_29 ;
V_59 -> V_320 = F_100 ( V_343 -> V_326 ) ;
V_59 -> V_146 = F_54 ( V_165 -> V_195 . V_134 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_322 = 0 ;
V_59 -> V_62 = V_343 -> V_303 ;
V_59 -> V_323 = V_343 -> V_344 ;
F_34 ( V_8 , V_64 , V_53 , NULL , F_102 ( V_165 ) ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_165 ;
int V_23 ;
struct V_342 V_343 ;
V_165 = F_77 ( V_10 , V_59 , V_109 ) ;
if ( F_94 ( V_165 ) )
return F_95 ( V_165 ) ;
F_104 ( V_165 ) ;
if ( V_59 -> V_320 == V_337 )
V_23 = F_105 ( V_165 ) ;
else
V_23 = F_106 ( V_165 ) ;
F_107 ( V_165 , V_23 ? 0 : 1 ,
F_108 ( V_345 ) ,
F_109 ( V_345 ) , 0 ) ;
if ( V_23 < 0 ) {
V_165 -> V_199 . V_200 = V_304 ;
F_110 ( V_165 ) ;
goto V_35;
}
if ( V_59 -> V_320 == V_337 )
V_343 . V_326 = V_336 ;
else
V_343 . V_326 = V_338 ;
V_343 . V_303 = V_59 -> V_62 ;
V_343 . V_344 = V_59 -> V_323 ;
F_111 ( V_165 , & V_343 ) ;
V_35:
F_87 ( V_165 ) ;
return V_23 ;
}
static int F_112 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_165 ;
struct V_342 V_343 ;
int V_23 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_71 ;
V_165 = F_60 ( V_10 , V_59 , V_109 ) ;
if ( V_165 == NULL )
return - V_50 ;
if ( ( V_23 = F_113 ( V_165 ) ) )
goto V_35;
if ( F_114 ( V_165 ) ) {
V_23 = - V_26 ;
goto V_35;
}
V_23 = F_115 ( V_165 ) ;
if ( V_23 < 0 )
goto V_35;
V_343 . V_303 = V_59 -> V_62 ;
V_343 . V_344 = V_59 -> V_323 ;
V_343 . V_326 = V_334 ;
F_111 ( V_165 , & V_343 ) ;
V_35:
F_116 ( V_165 , V_23 ? 0 : 1 ,
F_108 ( V_345 ) ,
F_109 ( V_345 ) , 0 ) ;
F_87 ( V_165 ) ;
return V_23 ;
}
static int F_117 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
T_8 V_134 ;
struct V_41 * V_346 ;
struct V_58 * V_307 ;
struct V_143 * V_165 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_71 ;
V_165 = F_60 ( V_10 , V_59 , V_109 ) ;
if ( V_165 == NULL )
return - V_50 ;
V_346 = F_75 ( V_165 ) ;
V_134 = V_165 -> V_195 . V_134 ;
F_87 ( V_165 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_307 = (struct V_58 * ) V_346 -> V_61 ;
V_307 -> V_319 = V_59 -> V_319 ;
V_307 -> V_320 = V_347 ;
V_307 -> V_146 = F_54 ( V_134 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_62 = V_59 -> V_62 ;
V_307 -> V_323 = V_59 -> V_323 ;
F_34 ( V_346 , V_64 , V_57 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static struct V_41 * F_118 ( const struct V_58 * V_66 ,
T_1 V_43 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
int V_47 , V_348 , V_349 , V_350 ;
V_348 = F_119 () ;
if ( V_348 ) {
V_348 *= sizeof( struct V_351 ) ;
V_348 += sizeof( struct V_352 ) ;
}
V_349 = F_120 () ;
if ( V_349 ) {
V_349 *= sizeof( struct V_351 ) ;
V_349 += sizeof( struct V_352 ) ;
}
V_47 = V_349 + V_348 + sizeof( struct V_58 ) ;
V_8 = F_41 ( V_47 + 16 , V_43 ) ;
if ( ! V_8 )
goto V_353;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( * V_59 ) ) ;
F_39 ( V_59 , V_66 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_73 = V_47 / sizeof( V_74 ) ;
if ( V_348 ) {
struct V_352 * V_77 ;
struct V_351 * V_354 ;
V_77 = (struct V_352 * ) F_43 ( V_8 , V_348 ) ;
V_354 = (struct V_351 * ) ( V_77 + 1 ) ;
V_77 -> V_355 = V_348 / sizeof( V_74 ) ;
V_77 -> V_356 = V_357 ;
for ( V_350 = 0 ; ; V_350 ++ ) {
struct V_210 * V_186 = F_121 ( V_350 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( V_186 -> V_358 )
* V_354 ++ = V_186 -> V_214 ;
}
}
if ( V_349 ) {
struct V_352 * V_77 ;
struct V_351 * V_354 ;
V_77 = (struct V_352 * ) F_43 ( V_8 , V_349 ) ;
V_354 = (struct V_351 * ) ( V_77 + 1 ) ;
V_77 -> V_355 = V_349 / sizeof( V_74 ) ;
V_77 -> V_356 = V_359 ;
for ( V_350 = 0 ; ; V_350 ++ ) {
struct V_210 * V_188 = F_122 ( V_350 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_213 )
continue;
if ( V_188 -> V_358 )
* V_354 ++ = V_188 -> V_214 ;
}
}
V_353:
return V_8 ;
}
static int F_123 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_360 ;
if ( V_59 -> V_146 > V_361 )
return - V_71 ;
if ( V_59 -> V_146 != V_126 ) {
if ( V_6 -> V_56 & ( 1 << V_59 -> V_146 ) )
return - V_362 ;
V_6 -> V_56 |= ( 1 << V_59 -> V_146 ) ;
}
F_124 () ;
V_360 = F_118 ( V_59 , V_33 ) ;
if ( ! V_360 ) {
if ( V_59 -> V_146 != V_126 )
V_6 -> V_56 &= ~ ( 1 << V_59 -> V_146 ) ;
return - V_44 ;
}
F_34 ( V_360 , V_33 , V_55 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , const struct V_58 * V_363 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
V_8 = F_41 ( sizeof( struct V_58 ) + 16 , V_64 ) ;
if ( ! V_8 )
return - V_44 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
memcpy ( V_59 , V_363 , sizeof( struct V_58 ) ) ;
V_59 -> V_63 = ( V_72 ) 0 ;
V_59 -> V_73 = ( sizeof( struct V_58 ) / sizeof( V_74 ) ) ;
return F_34 ( V_8 , V_64 , V_57 , V_3 , F_7 ( V_3 ) ) ;
}
static int F_126 ( const struct V_342 * V_343 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
V_8 = F_41 ( sizeof( struct V_58 ) + 16 , V_64 ) ;
if ( ! V_8 )
return - V_44 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_146 = F_54 ( V_343 -> V_61 . V_134 ) ;
V_59 -> V_320 = V_364 ;
V_59 -> V_62 = V_343 -> V_303 ;
V_59 -> V_323 = V_343 -> V_344 ;
V_59 -> V_319 = V_29 ;
V_59 -> V_63 = ( V_72 ) 0 ;
V_59 -> V_73 = ( sizeof( struct V_58 ) / sizeof( V_74 ) ) ;
V_59 -> V_322 = 0 ;
F_34 ( V_8 , V_64 , V_53 , NULL , V_343 -> V_10 ) ;
return 0 ;
}
static int F_127 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_134 ;
struct V_342 V_343 ;
struct V_365 V_366 ;
int V_23 , V_51 ;
V_134 = F_53 ( V_59 -> V_146 ) ;
if ( V_134 == 0 )
return - V_71 ;
V_366 . V_367 = F_108 ( V_345 ) ;
V_366 . V_368 = F_109 ( V_345 ) ;
V_366 . V_369 = 0 ;
V_23 = F_128 ( V_10 , V_134 , & V_366 ) ;
V_51 = F_125 ( V_3 , V_59 ) ;
if ( V_23 || V_51 ) {
if ( V_23 == - V_50 )
V_23 = 0 ;
return V_23 ? V_23 : V_51 ;
}
V_343 . V_61 . V_134 = V_134 ;
V_343 . V_303 = V_59 -> V_62 ;
V_343 . V_344 = V_59 -> V_323 ;
V_343 . V_326 = V_370 ;
V_343 . V_10 = V_10 ;
F_111 ( NULL , & V_343 ) ;
return 0 ;
}
static int F_129 ( struct V_143 * V_165 , int V_371 , void * V_372 )
{
struct V_1 * V_6 = V_372 ;
struct V_41 * V_346 ;
struct V_58 * V_307 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_346 = F_75 ( V_165 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_307 = (struct V_58 * ) V_346 -> V_61 ;
V_307 -> V_319 = V_6 -> V_7 . V_373 ;
V_307 -> V_320 = V_374 ;
V_307 -> V_146 = F_54 ( V_165 -> V_195 . V_134 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_62 = V_371 + 1 ;
V_307 -> V_323 = V_6 -> V_7 . V_375 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_64 , V_57 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_346 ;
return 0 ;
}
static int F_130 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return F_131 ( V_10 , & V_6 -> V_7 . V_376 . V_200 , F_129 , ( void * ) V_6 ) ;
}
static void F_132 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
F_133 ( & V_6 -> V_7 . V_376 . V_200 , V_10 ) ;
}
static int F_134 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
T_7 V_134 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_377 ;
V_134 = F_53 ( V_59 -> V_146 ) ;
if ( V_134 == 0 )
return - V_71 ;
V_6 -> V_7 . V_373 = V_59 -> V_319 ;
V_6 -> V_7 . V_375 = V_59 -> V_323 ;
V_6 -> V_7 . V_7 = F_130 ;
V_6 -> V_7 . V_9 = F_132 ;
F_135 ( & V_6 -> V_7 . V_376 . V_200 , V_134 ) ;
return F_38 ( V_6 ) ;
}
static int F_136 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_125 = V_59 -> V_146 ;
bool V_378 = false ;
if ( V_59 -> V_73 == ( sizeof( * V_59 ) / sizeof( V_74 ) ) ) {
V_378 = true ;
if ( V_125 != 0 && V_125 != 1 )
return - V_71 ;
V_6 -> V_52 = V_125 ;
}
if ( V_378 && F_137 ( V_8 ) )
V_8 = F_138 ( V_8 , V_33 ) ;
else
V_8 = F_31 ( V_8 , V_33 ) ;
if ( V_378 && V_8 ) {
struct V_58 * V_379 = (struct V_58 * ) V_8 -> V_61 ;
V_379 -> V_63 = 0 ;
}
F_34 ( V_8 , V_33 , V_53 , NULL , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_139 ( struct V_380 * V_381 , int V_382 , int V_371 , void * V_372 )
{
int V_350 ;
T_6 V_270 = * ( T_6 * ) V_372 ;
for ( V_350 = 0 ; V_350 < V_381 -> V_383 ; V_350 ++ ) {
if ( V_381 -> V_384 [ V_350 ] . V_270 == V_270 )
return - V_362 ;
}
return 0 ;
}
static T_6 F_140 ( struct V_10 * V_10 )
{
struct V_385 V_386 ;
T_6 V_387 ;
int V_60 ;
static T_6 V_270 = V_388 ;
V_387 = V_270 ;
do {
++ V_270 ;
if ( V_270 == 0 )
V_270 = V_388 + 1 ;
F_141 ( & V_386 , V_389 ) ;
V_60 = V_385 ( V_10 , & V_386 , F_139 , ( void * ) & V_270 ) ;
F_142 ( & V_386 , V_10 ) ;
if ( V_60 != - V_362 )
return V_270 ;
} while ( V_270 != V_387 );
return 0 ;
}
static int
F_143 ( struct V_380 * V_381 , struct V_390 * V_391 )
{
struct V_10 * V_10 = F_144 ( V_381 ) ;
struct V_392 * V_393 = V_381 -> V_384 + V_381 -> V_383 ;
int V_149 ;
if ( V_381 -> V_383 >= V_394 )
return - V_395 ;
if ( V_391 -> V_396 == 0 )
return - V_71 ;
V_393 -> V_195 . V_134 = V_391 -> V_397 ;
if ( ( V_149 = F_65 ( V_391 -> V_396 ) ) < 0 )
return - V_71 ;
V_393 -> V_149 = V_149 ;
if ( V_391 -> V_398 == V_399 )
V_393 -> V_400 = 1 ;
else if ( V_391 -> V_398 == V_401 ) {
V_393 -> V_270 = V_391 -> V_402 ;
if ( V_393 -> V_270 > V_388 )
V_393 -> V_270 = 0 ;
if ( ! V_393 -> V_270 && ! ( V_393 -> V_270 = F_140 ( V_10 ) ) )
return - V_44 ;
}
if ( V_393 -> V_149 == V_152 ) {
T_7 * V_136 = ( T_7 * ) ( V_391 + 1 ) ;
int V_135 , V_403 ;
V_135 = F_58 ( (struct V_78 * ) V_136 ,
& V_393 -> V_185 ) ;
if ( ! V_135 )
return - V_71 ;
V_403 = F_57 ( V_135 ) ;
if ( F_58 ( (struct V_78 * ) ( V_136 + V_403 ) ,
& V_393 -> V_195 . V_252 ) != V_135 )
return - V_71 ;
V_393 -> V_404 = V_135 ;
} else
V_393 -> V_404 = V_381 -> V_135 ;
V_393 -> V_405 = 1 ;
V_381 -> V_383 ++ ;
return 0 ;
}
static int
F_145 ( struct V_380 * V_381 , struct V_406 * V_407 )
{
int V_23 ;
int V_47 = V_407 -> V_408 * 8 - sizeof( struct V_406 ) ;
struct V_390 * V_391 = ( void * ) ( V_407 + 1 ) ;
if ( V_407 -> V_408 * 8 < sizeof( struct V_406 ) )
return - V_71 ;
while ( V_47 >= sizeof( struct V_390 ) ) {
if ( ( V_23 = F_143 ( V_381 , V_391 ) ) < 0 )
return V_23 ;
V_47 -= V_391 -> V_409 ;
V_391 = ( void * ) ( ( T_7 * ) V_391 + V_391 -> V_409 ) ;
}
return 0 ;
}
static inline int F_146 ( const struct V_380 * V_381 )
{
struct V_174 * V_175 = V_381 -> V_183 ;
if ( V_175 ) {
int V_47 = sizeof( struct V_89 ) ;
V_47 += V_175 -> V_104 ;
return F_63 ( V_47 ) ;
}
return 0 ;
}
static int F_147 ( const struct V_380 * V_381 )
{
const struct V_392 * V_393 ;
int V_179 = F_62 ( V_381 -> V_135 ) ;
int V_403 = 0 ;
int V_350 ;
for ( V_350 = 0 ; V_350 < V_381 -> V_383 ; V_350 ++ ) {
V_393 = V_381 -> V_384 + V_350 ;
V_403 += F_57 ( V_393 -> V_404 ) ;
}
return sizeof( struct V_58 ) +
( sizeof( struct V_168 ) * 3 ) +
( sizeof( struct V_76 ) * 2 ) +
( V_179 * 2 ) +
sizeof( struct V_406 ) +
( V_381 -> V_383 * sizeof( struct V_390 ) ) +
( V_403 * 2 ) +
F_146 ( V_381 ) ;
}
static struct V_41 * F_148 ( const struct V_380 * V_381 )
{
struct V_41 * V_8 ;
int V_176 ;
V_176 = F_147 ( V_381 ) ;
V_8 = F_41 ( V_176 + 16 , V_64 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
return V_8 ;
}
static int F_149 ( struct V_41 * V_8 , const struct V_380 * V_381 , int V_382 )
{
struct V_58 * V_59 ;
struct V_76 * V_79 ;
struct V_168 * V_169 ;
struct V_406 * V_407 ;
struct V_89 * V_90 ;
struct V_174 * V_175 ;
int V_350 ;
int V_176 ;
int V_179 = F_62 ( V_381 -> V_135 ) ;
int V_403 = F_57 ( V_381 -> V_135 ) ;
V_176 = F_147 ( V_381 ) ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
memset ( V_59 , 0 , V_176 ) ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_179 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_179 ) /
sizeof( V_74 ) ;
V_79 -> V_249 = V_120 ;
V_79 -> V_250 = F_56 ( V_381 -> V_410 . V_134 ) ;
V_79 -> V_87 = V_381 -> V_410 . V_253 ;
V_79 -> V_251 = 0 ;
if ( ! F_66 ( & V_381 -> V_410 . V_185 ,
V_381 -> V_410 . V_254 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_381 -> V_135 ) )
F_74 () ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_179 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_179 ) /
sizeof( V_74 ) ;
V_79 -> V_249 = V_121 ;
V_79 -> V_250 = F_56 ( V_381 -> V_410 . V_134 ) ;
V_79 -> V_87 = V_381 -> V_410 . V_411 ;
V_79 -> V_251 = 0 ;
F_66 ( & V_381 -> V_410 . V_252 , V_381 -> V_410 . V_412 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_381 -> V_135 ) ;
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_74 ) ;
V_169 -> V_227 = V_228 ;
V_169 -> V_229 = F_73 ( V_381 -> V_230 . V_231 ) ;
V_169 -> V_232 = F_73 ( V_381 -> V_230 . V_233 ) ;
V_169 -> V_234 = V_381 -> V_230 . V_235 ;
V_169 -> V_236 = V_381 -> V_230 . V_237 ;
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_74 ) ;
V_169 -> V_227 = V_238 ;
V_169 -> V_229 = F_73 ( V_381 -> V_230 . V_239 ) ;
V_169 -> V_232 = F_73 ( V_381 -> V_230 . V_240 ) ;
V_169 -> V_234 = V_381 -> V_230 . V_241 ;
V_169 -> V_236 = V_381 -> V_230 . V_242 ;
V_169 = (struct V_168 * ) F_43 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_226 =
sizeof( struct V_168 ) / sizeof( V_74 ) ;
V_169 -> V_227 = V_243 ;
V_169 -> V_229 = V_381 -> V_244 . V_245 ;
V_169 -> V_232 = V_381 -> V_244 . V_246 ;
V_169 -> V_234 = V_381 -> V_244 . V_247 ;
V_169 -> V_236 = V_381 -> V_244 . V_248 ;
V_407 = (struct V_406 * ) F_43 ( V_8 , sizeof( struct V_406 ) ) ;
V_407 -> V_408 = sizeof( struct V_406 ) / sizeof( V_74 ) ;
V_407 -> V_413 = V_414 ;
V_407 -> V_415 = V_416 ;
if ( V_381 -> V_417 == V_418 ) {
if ( V_381 -> V_383 )
V_407 -> V_415 = V_419 ;
else
V_407 -> V_415 = V_420 ;
}
V_407 -> V_421 = V_382 + 1 ;
V_407 -> V_422 = 0 ;
V_407 -> V_423 = V_381 -> V_424 ;
V_407 -> V_425 = V_381 -> V_426 ;
for ( V_350 = 0 ; V_350 < V_381 -> V_383 ; V_350 ++ ) {
const struct V_392 * V_393 = V_381 -> V_384 + V_350 ;
struct V_390 * V_391 ;
int V_427 ;
int V_149 ;
V_427 = sizeof( struct V_390 ) ;
if ( V_393 -> V_149 == V_152 ) {
V_403 = F_57 ( V_393 -> V_404 ) ;
V_427 += V_403 * 2 ;
} else {
V_176 -= 2 * V_403 ;
}
V_391 = ( void * ) F_43 ( V_8 , V_427 ) ;
V_407 -> V_408 += V_427 / 8 ;
memset ( V_391 , 0 , sizeof( * V_391 ) ) ;
V_391 -> V_409 = V_427 ;
V_391 -> V_397 = V_393 -> V_195 . V_134 ;
if ( ( V_149 = F_64 ( V_393 -> V_149 ) ) < 0 )
return - V_71 ;
V_391 -> V_396 = V_149 ;
V_391 -> V_398 = V_428 ;
if ( V_393 -> V_270 )
V_391 -> V_398 = V_401 ;
if ( V_393 -> V_400 )
V_391 -> V_398 = V_399 ;
V_391 -> V_402 = V_393 -> V_270 ;
if ( V_393 -> V_149 == V_152 ) {
T_7 * V_136 = ( void * ) ( V_391 + 1 ) ;
F_66 ( & V_393 -> V_185 , 0 ,
(struct V_78 * ) V_136 ,
V_393 -> V_404 ) ;
F_66 ( & V_393 -> V_195 . V_252 , 0 ,
(struct V_78 * ) ( V_136 + V_403 ) ,
V_393 -> V_404 ) ;
}
}
if ( ( V_175 = V_381 -> V_183 ) ) {
int V_97 = F_146 ( V_381 ) ;
V_90 = (struct V_89 * ) F_43 ( V_8 , V_97 ) ;
V_90 -> V_93 = V_97 / sizeof( V_74 ) ;
V_90 -> V_99 = V_124 ;
V_90 -> V_101 = V_175 -> V_100 ;
V_90 -> V_103 = V_175 -> V_102 ;
V_90 -> V_91 = V_175 -> V_104 ;
memcpy ( V_90 + 1 , V_175 -> V_286 ,
V_175 -> V_104 ) ;
}
V_59 -> V_73 = V_176 / sizeof( V_74 ) ;
V_59 -> V_322 = F_3 ( & V_381 -> V_429 ) ;
return 0 ;
}
static int F_150 ( struct V_380 * V_381 , int V_382 , const struct V_342 * V_343 )
{
struct V_41 * V_346 ;
struct V_58 * V_307 ;
int V_23 ;
V_346 = F_148 ( V_381 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_23 = F_149 ( V_346 , V_381 , V_382 ) ;
if ( V_23 < 0 )
return V_23 ;
V_307 = (struct V_58 * ) V_346 -> V_61 ;
V_307 -> V_319 = V_29 ;
if ( V_343 -> V_61 . V_430 && V_343 -> V_326 == V_327 )
V_307 -> V_320 = V_431 ;
else
V_307 -> V_320 = F_99 ( V_343 -> V_326 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_62 = V_343 -> V_303 ;
V_307 -> V_323 = V_343 -> V_344 ;
F_34 ( V_346 , V_64 , V_53 , NULL , F_144 ( V_381 ) ) ;
return 0 ;
}
static int F_151 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 = 0 ;
struct V_168 * V_169 ;
struct V_76 * V_136 ;
struct V_406 * V_407 ;
struct V_380 * V_381 ;
struct V_342 V_343 ;
struct V_89 * V_90 ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_414 - 1 ] )
return - V_71 ;
V_407 = V_109 [ V_414 - 1 ] ;
if ( V_407 -> V_415 > V_419 )
return - V_71 ;
if ( ! V_407 -> V_421 || V_407 -> V_421 >= V_432 )
return - V_71 ;
V_381 = F_152 ( V_10 , V_33 ) ;
if ( V_381 == NULL )
return - V_44 ;
V_381 -> V_417 = ( V_407 -> V_415 == V_416 ?
V_433 : V_418 ) ;
V_381 -> V_426 = V_407 -> V_425 ;
V_136 = V_109 [ V_120 - 1 ] ;
V_381 -> V_135 = F_59 ( V_136 , & V_381 -> V_410 . V_185 ) ;
V_381 -> V_410 . V_135 = V_381 -> V_135 ;
V_381 -> V_410 . V_253 = V_136 -> V_87 ;
V_381 -> V_410 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_381 -> V_410 . V_254 = ( (struct V_80 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_381 -> V_410 . V_254 )
V_381 -> V_410 . V_434 = F_153 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_381 -> V_410 . V_252 ) ;
V_381 -> V_410 . V_411 = V_136 -> V_87 ;
V_381 -> V_410 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_381 -> V_410 . V_412 = ( (struct V_80 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_381 -> V_410 . V_412 )
V_381 -> V_410 . V_435 = F_153 ( 0xffff ) ;
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 ) {
V_23 = - V_44 ;
goto V_35;
}
V_23 = F_154 ( & V_381 -> V_183 , V_96 , V_33 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
goto V_35;
}
V_381 -> V_230 . V_240 = V_436 ;
V_381 -> V_230 . V_233 = V_436 ;
V_381 -> V_230 . V_239 = V_436 ;
V_381 -> V_230 . V_231 = V_436 ;
if ( ( V_169 = V_109 [ V_228 - 1 ] ) != NULL ) {
V_381 -> V_230 . V_231 = F_80 ( V_169 -> V_229 ) ;
V_381 -> V_230 . V_233 = F_80 ( V_169 -> V_232 ) ;
V_381 -> V_230 . V_235 = V_169 -> V_234 ;
V_381 -> V_230 . V_237 = V_169 -> V_236 ;
}
if ( ( V_169 = V_109 [ V_238 - 1 ] ) != NULL ) {
V_381 -> V_230 . V_239 = F_80 ( V_169 -> V_229 ) ;
V_381 -> V_230 . V_240 = F_80 ( V_169 -> V_232 ) ;
V_381 -> V_230 . V_241 = V_169 -> V_234 ;
V_381 -> V_230 . V_242 = V_169 -> V_236 ;
}
V_381 -> V_383 = 0 ;
if ( V_407 -> V_415 == V_419 &&
( V_23 = F_145 ( V_381 , V_407 ) ) < 0 )
goto V_35;
V_23 = F_155 ( V_407 -> V_421 - 1 , V_381 ,
V_59 -> V_320 != V_332 ) ;
F_156 ( V_381 , V_23 ? 0 : 1 ,
F_108 ( V_345 ) ,
F_109 ( V_345 ) , 0 ) ;
if ( V_23 )
goto V_35;
if ( V_59 -> V_320 == V_332 )
V_343 . V_326 = V_331 ;
else
V_343 . V_326 = V_329 ;
V_343 . V_303 = V_59 -> V_62 ;
V_343 . V_344 = V_59 -> V_323 ;
F_157 ( V_381 , V_407 -> V_421 - 1 , & V_343 ) ;
F_158 ( V_381 ) ;
return 0 ;
V_35:
V_381 -> V_386 . V_437 = 1 ;
F_159 ( V_381 ) ;
return V_23 ;
}
static int F_160 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 ;
struct V_76 * V_136 ;
struct V_406 * V_407 ;
struct V_380 * V_381 ;
struct V_438 V_184 ;
struct V_342 V_343 ;
struct V_89 * V_90 ;
struct V_174 * V_439 = NULL ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_414 - 1 ] )
return - V_71 ;
V_407 = V_109 [ V_414 - 1 ] ;
if ( ! V_407 -> V_421 || V_407 -> V_421 >= V_432 )
return - V_71 ;
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ;
V_184 . V_135 = F_59 ( V_136 , & V_184 . V_185 ) ;
V_184 . V_253 = V_136 -> V_87 ;
V_184 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_184 . V_254 = ( (struct V_80 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_254 )
V_184 . V_434 = F_153 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ;
F_59 ( V_136 , & V_184 . V_252 ) ;
V_184 . V_411 = V_136 -> V_87 ;
V_184 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_184 . V_412 = ( (struct V_80 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_412 )
V_184 . V_435 = F_153 ( 0xffff ) ;
V_90 = V_109 [ V_124 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_96 = F_49 ( V_90 , V_33 ) ;
if ( ! V_96 )
return - V_31 ;
V_23 = F_154 ( & V_439 , V_96 , V_33 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
return V_23 ;
}
V_381 = F_161 ( V_10 , V_147 , V_389 ,
V_407 -> V_421 - 1 , & V_184 , V_439 ,
1 , & V_23 ) ;
F_162 ( V_439 ) ;
if ( V_381 == NULL )
return - V_315 ;
F_163 ( V_381 , V_23 ? 0 : 1 ,
F_108 ( V_345 ) ,
F_109 ( V_345 ) , 0 ) ;
if ( V_23 )
goto V_35;
V_343 . V_303 = V_59 -> V_62 ;
V_343 . V_344 = V_59 -> V_323 ;
V_343 . V_61 . V_430 = 0 ;
V_343 . V_326 = V_327 ;
F_157 ( V_381 , V_407 -> V_421 - 1 , & V_343 ) ;
V_35:
F_158 ( V_381 ) ;
if ( V_23 == 0 )
F_164 ( V_10 ) ;
return V_23 ;
}
static int F_165 ( struct V_2 * V_3 , struct V_380 * V_381 , const struct V_58 * V_59 , int V_382 )
{
int V_23 ;
struct V_41 * V_346 ;
struct V_58 * V_307 ;
V_23 = 0 ;
V_346 = F_148 ( V_381 ) ;
if ( F_94 ( V_346 ) ) {
V_23 = F_95 ( V_346 ) ;
goto V_35;
}
V_23 = F_149 ( V_346 , V_381 , V_382 ) ;
if ( V_23 < 0 )
goto V_35;
V_307 = (struct V_58 * ) V_346 -> V_61 ;
V_307 -> V_319 = V_59 -> V_319 ;
V_307 -> V_320 = V_59 -> V_320 ;
V_307 -> V_146 = 0 ;
V_307 -> V_63 = 0 ;
V_307 -> V_62 = V_59 -> V_62 ;
V_307 -> V_323 = V_59 -> V_323 ;
F_34 ( V_346 , V_64 , V_57 , V_3 , F_144 ( V_381 ) ) ;
V_23 = 0 ;
V_35:
return V_23 ;
}
static int F_166 ( T_3 V_135 )
{
return F_63 ( F_57 ( V_135 ) * 2 ) ;
}
static int F_167 ( struct V_78 * V_136 , int V_113 ,
T_4 * V_185 , T_4 * V_252 ,
T_9 * V_135 )
{
int V_440 , V_403 ;
if ( V_113 < F_166 ( V_136 -> V_84 ) )
return - V_71 ;
V_440 = F_58 ( V_136 , V_185 ) ;
if ( ! V_440 )
return - V_71 ;
V_403 = F_57 ( V_440 ) ;
if ( F_58 ( (struct V_78 * ) ( ( ( T_7 * ) V_136 ) + V_403 ) ,
V_252 ) != V_440 )
return - V_71 ;
* V_135 = V_440 ;
return 0 ;
}
static int F_168 ( struct V_390 * V_441 , int V_47 ,
struct V_442 * V_443 )
{
int V_23 ;
struct V_390 * V_444 ;
int V_149 ;
if ( V_47 <= sizeof( struct V_390 ) ||
V_47 < V_441 -> V_409 )
return - V_71 ;
V_23 = F_167 ( (struct V_78 * ) ( V_441 + 1 ) ,
V_441 -> V_409 ,
& V_443 -> V_445 , & V_443 -> V_446 ,
& V_443 -> V_447 ) ;
if ( V_23 )
return V_23 ;
V_444 = (struct V_390 * ) ( ( T_7 * ) V_441 + V_441 -> V_409 ) ;
V_47 -= V_441 -> V_409 ;
if ( V_47 <= sizeof( struct V_390 ) ||
V_47 < V_444 -> V_409 )
return - V_71 ;
V_23 = F_167 ( (struct V_78 * ) ( V_444 + 1 ) ,
V_444 -> V_409 ,
& V_443 -> V_448 , & V_443 -> V_449 ,
& V_443 -> V_450 ) ;
if ( V_23 )
return V_23 ;
if ( V_441 -> V_397 != V_444 -> V_397 ||
V_441 -> V_396 != V_444 -> V_396 ||
V_441 -> V_402 != V_444 -> V_402 )
return - V_71 ;
V_443 -> V_134 = V_441 -> V_397 ;
if ( ( V_149 = F_65 ( V_441 -> V_396 ) ) < 0 )
return - V_71 ;
V_443 -> V_149 = V_149 ;
V_443 -> V_270 = V_441 -> V_402 ;
return ( ( int ) ( V_441 -> V_409 +
V_444 -> V_409 ) ) ;
}
static int F_169 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_58 * V_59 , void * const * V_109 )
{
int V_350 , V_47 , V_451 , V_23 = - V_71 ;
T_7 V_382 ;
struct V_76 * V_136 ;
struct V_452 * V_453 ;
struct V_406 * V_407 ;
struct V_390 * V_391 ;
struct V_438 V_184 ;
struct V_442 V_443 [ V_394 ] ;
struct V_454 V_455 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
if ( ! F_51 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_414 - 1 ] ) {
V_23 = - V_71 ;
goto V_35;
}
V_453 = V_109 [ V_456 - 1 ] ;
V_407 = V_109 [ V_414 - 1 ] ;
if ( V_407 -> V_421 >= V_432 ) {
V_23 = - V_71 ;
goto V_35;
}
if ( V_453 ) {
V_455 . V_457 = V_453 -> V_458 ;
V_451 = F_167 ( (struct V_78 * ) ( V_453 + 1 ) ,
8 * ( V_453 -> V_459 ) - sizeof( * V_453 ) ,
& V_455 . V_460 , & V_455 . V_461 , & V_455 . V_135 ) ;
if ( V_451 < 0 ) {
V_23 = V_451 ;
goto V_35;
}
}
V_382 = V_407 -> V_421 - 1 ;
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ;
V_184 . V_135 = F_59 ( V_136 , & V_184 . V_185 ) ;
V_184 . V_253 = V_136 -> V_87 ;
V_184 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_184 . V_254 = ( (struct V_80 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_254 )
V_184 . V_434 = F_153 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ,
F_59 ( V_136 , & V_184 . V_252 ) ;
V_184 . V_411 = V_136 -> V_87 ;
V_184 . V_134 = F_55 ( V_136 -> V_250 ) ;
V_184 . V_412 = ( (struct V_80 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_412 )
V_184 . V_435 = F_153 ( 0xffff ) ;
V_391 = (struct V_390 * ) ( V_407 + 1 ) ;
V_350 = 0 ;
V_47 = V_407 -> V_408 * 8 - sizeof( struct V_406 ) ;
while ( V_47 > 0 && V_350 < V_394 ) {
V_451 = F_168 ( V_391 , V_47 , & V_443 [ V_350 ] ) ;
if ( V_451 < 0 ) {
V_23 = V_451 ;
goto V_35;
} else {
V_391 = (struct V_390 * ) ( ( T_7 * ) V_391 + V_451 ) ;
V_47 -= V_451 ;
V_350 ++ ;
}
}
if ( ! V_350 || V_47 > 0 ) {
V_23 = - V_71 ;
goto V_35;
}
return V_442 ( & V_184 , V_382 , V_389 , V_443 , V_350 ,
V_453 ? & V_455 : NULL , V_10 ) ;
V_35:
return V_23 ;
}
static int F_169 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_58 * V_59 , void * const * V_109 )
{
return - V_462 ;
}
static int F_170 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_382 ;
int V_23 = 0 , V_463 ;
struct V_406 * V_407 ;
struct V_380 * V_381 ;
struct V_342 V_343 ;
if ( ( V_407 = V_109 [ V_414 - 1 ] ) == NULL )
return - V_71 ;
V_382 = F_171 ( V_407 -> V_423 ) ;
if ( V_382 >= V_464 )
return - V_71 ;
V_463 = ( V_59 -> V_320 == V_431 ) ;
V_381 = F_172 ( V_10 , V_147 , V_389 ,
V_382 , V_407 -> V_423 , V_463 , & V_23 ) ;
if ( V_381 == NULL )
return - V_315 ;
if ( V_463 ) {
F_163 ( V_381 , V_23 ? 0 : 1 ,
F_108 ( V_345 ) ,
F_109 ( V_345 ) , 0 ) ;
if ( V_23 )
goto V_35;
V_343 . V_303 = V_59 -> V_62 ;
V_343 . V_344 = V_59 -> V_323 ;
V_343 . V_61 . V_430 = 1 ;
V_343 . V_326 = V_327 ;
F_157 ( V_381 , V_382 , & V_343 ) ;
} else {
V_23 = F_165 ( V_3 , V_381 , V_59 , V_382 ) ;
}
V_35:
F_158 ( V_381 ) ;
if ( V_463 && V_23 == 0 )
F_164 ( V_10 ) ;
return V_23 ;
}
static int F_173 ( struct V_380 * V_381 , int V_382 , int V_371 , void * V_372 )
{
struct V_1 * V_6 = V_372 ;
struct V_41 * V_346 ;
struct V_58 * V_307 ;
int V_23 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_346 = F_148 ( V_381 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_23 = F_149 ( V_346 , V_381 , V_382 ) ;
if ( V_23 < 0 )
return V_23 ;
V_307 = (struct V_58 * ) V_346 -> V_61 ;
V_307 -> V_319 = V_6 -> V_7 . V_373 ;
V_307 -> V_320 = V_465 ;
V_307 -> V_146 = V_126 ;
V_307 -> V_63 = 0 ;
V_307 -> V_62 = V_371 + 1 ;
V_307 -> V_323 = V_6 -> V_7 . V_375 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_64 , V_57 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_346 ;
return 0 ;
}
static int F_174 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return V_385 ( V_10 , & V_6 -> V_7 . V_376 . V_466 , F_173 , ( void * ) V_6 ) ;
}
static void F_175 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( (struct V_2 * ) V_6 ) ;
F_142 ( & V_6 -> V_7 . V_376 . V_466 , V_10 ) ;
}
static int F_176 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_377 ;
V_6 -> V_7 . V_373 = V_59 -> V_319 ;
V_6 -> V_7 . V_375 = V_59 -> V_323 ;
V_6 -> V_7 . V_7 = F_174 ;
V_6 -> V_7 . V_9 = F_175 ;
F_141 ( & V_6 -> V_7 . V_376 . V_466 , V_389 ) ;
return F_38 ( V_6 ) ;
}
static int F_177 ( const struct V_342 * V_343 )
{
struct V_41 * V_467 ;
struct V_58 * V_59 ;
V_467 = F_41 ( sizeof( struct V_58 ) + 16 , V_64 ) ;
if ( ! V_467 )
return - V_44 ;
V_59 = (struct V_58 * ) F_43 ( V_467 , sizeof( struct V_58 ) ) ;
V_59 -> V_320 = V_468 ;
V_59 -> V_62 = V_343 -> V_303 ;
V_59 -> V_323 = V_343 -> V_344 ;
V_59 -> V_319 = V_29 ;
V_59 -> V_63 = ( V_72 ) 0 ;
V_59 -> V_146 = V_126 ;
V_59 -> V_73 = ( sizeof( struct V_58 ) / sizeof( V_74 ) ) ;
V_59 -> V_322 = 0 ;
F_34 ( V_467 , V_64 , V_53 , NULL , V_343 -> V_10 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_342 V_343 ;
struct V_365 V_366 ;
int V_23 , V_51 ;
V_366 . V_367 = F_108 ( V_345 ) ;
V_366 . V_368 = F_109 ( V_345 ) ;
V_366 . V_369 = 0 ;
V_23 = F_179 ( V_10 , V_389 , & V_366 ) ;
V_51 = F_125 ( V_3 , V_59 ) ;
if ( V_23 || V_51 ) {
if ( V_23 == - V_50 )
return 0 ;
return V_23 ;
}
V_343 . V_61 . type = V_389 ;
V_343 . V_326 = V_469 ;
V_343 . V_344 = V_59 -> V_323 ;
V_343 . V_303 = V_59 -> V_62 ;
V_343 . V_10 = V_10 ;
F_157 ( NULL , 0 , & V_343 ) ;
return 0 ;
}
static int F_180 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 )
{
void * V_109 [ V_117 ] ;
int V_23 ;
F_34 ( F_31 ( V_8 , V_33 ) , V_33 ,
V_54 , NULL , F_7 ( V_3 ) ) ;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
V_23 = F_52 ( V_8 , V_59 , V_109 ) ;
if ( ! V_23 ) {
V_23 = - V_305 ;
if ( V_470 [ V_59 -> V_320 ] )
V_23 = V_470 [ V_59 -> V_320 ] ( V_3 , V_8 , V_59 , V_109 ) ;
}
return V_23 ;
}
static struct V_58 * F_181 ( struct V_41 * V_8 , int * V_471 )
{
struct V_58 * V_59 = NULL ;
if ( V_8 -> V_47 < sizeof( * V_59 ) ) {
* V_471 = - V_472 ;
} else {
V_59 = (struct V_58 * ) V_8 -> V_61 ;
if ( V_59 -> V_319 != V_29 ||
V_59 -> V_322 != 0 ||
( V_59 -> V_320 <= V_473 ||
V_59 -> V_320 > V_474 ) ) {
V_59 = NULL ;
* V_471 = - V_71 ;
} else if ( V_59 -> V_73 != ( V_8 -> V_47 /
sizeof( V_74 ) ) ||
V_59 -> V_73 < ( sizeof( struct V_58 ) /
sizeof( V_74 ) ) ) {
V_59 = NULL ;
* V_471 = - V_472 ;
} else {
* V_471 = 0 ;
}
}
return V_59 ;
}
static inline int F_182 ( const struct V_392 * V_393 ,
const struct V_210 * V_475 )
{
unsigned int V_195 = V_475 -> V_214 . V_215 ;
if ( V_195 >= sizeof( V_393 -> V_476 ) * 8 )
return 0 ;
return ( V_393 -> V_476 >> V_195 ) & 1 ;
}
static inline int F_183 ( const struct V_392 * V_393 ,
const struct V_210 * V_475 )
{
unsigned int V_195 = V_475 -> V_214 . V_215 ;
if ( V_195 >= sizeof( V_393 -> V_477 ) * 8 )
return 0 ;
return ( V_393 -> V_477 >> V_195 ) & 1 ;
}
static int F_184 ( const struct V_392 * V_393 )
{
int V_350 , V_478 = 0 ;
for ( V_350 = 0 ; ; V_350 ++ ) {
const struct V_210 * V_186 = F_121 ( V_350 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( F_182 ( V_393 , V_186 ) && V_186 -> V_358 )
V_478 += sizeof( struct V_479 ) ;
}
return V_478 + sizeof( struct V_480 ) ;
}
static int F_185 ( const struct V_392 * V_393 )
{
int V_350 , V_455 , V_478 = 0 ;
for ( V_350 = 0 ; ; V_350 ++ ) {
const struct V_210 * V_188 = F_122 ( V_350 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_213 )
continue;
if ( ! ( F_183 ( V_393 , V_188 ) && V_188 -> V_358 ) )
continue;
for ( V_455 = 1 ; ; V_455 ++ ) {
const struct V_210 * V_186 = F_121 ( V_455 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( F_182 ( V_393 , V_186 ) && V_186 -> V_358 )
V_478 += sizeof( struct V_479 ) ;
}
}
return V_478 + sizeof( struct V_480 ) ;
}
static void F_186 ( struct V_41 * V_8 , const struct V_392 * V_393 )
{
struct V_480 * V_75 ;
int V_350 ;
V_75 = (struct V_480 * ) F_43 ( V_8 , sizeof( struct V_480 ) ) ;
V_75 -> V_481 = sizeof( struct V_480 ) / 8 ;
V_75 -> V_482 = V_483 ;
V_75 -> V_484 = 32 ;
memset ( V_75 -> V_485 , 0 , sizeof( V_75 -> V_485 ) ) ;
for ( V_350 = 0 ; ; V_350 ++ ) {
const struct V_210 * V_186 = F_121 ( V_350 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( F_182 ( V_393 , V_186 ) && V_186 -> V_358 ) {
struct V_479 * V_343 ;
V_343 = (struct V_479 * ) F_43 ( V_8 , sizeof( struct V_479 ) ) ;
memset ( V_343 , 0 , sizeof( * V_343 ) ) ;
V_75 -> V_481 += sizeof( struct V_479 ) / 8 ;
V_343 -> V_486 = V_186 -> V_214 . V_215 ;
V_343 -> V_487 = V_186 -> V_214 . V_488 ;
V_343 -> V_489 = V_186 -> V_214 . V_490 ;
V_343 -> V_491 = 24 * 60 * 60 ;
V_343 -> V_492 = 20 * 60 * 60 ;
V_343 -> V_493 = 8 * 60 * 60 ;
V_343 -> V_494 = 7 * 60 * 60 ;
}
}
}
static void F_187 ( struct V_41 * V_8 , const struct V_392 * V_393 )
{
struct V_480 * V_75 ;
int V_350 , V_455 ;
V_75 = (struct V_480 * ) F_43 ( V_8 , sizeof( struct V_480 ) ) ;
V_75 -> V_481 = sizeof( struct V_480 ) / 8 ;
V_75 -> V_482 = V_483 ;
V_75 -> V_484 = 32 ;
memset ( V_75 -> V_485 , 0 , sizeof( V_75 -> V_485 ) ) ;
for ( V_350 = 0 ; ; V_350 ++ ) {
const struct V_210 * V_188 = F_122 ( V_350 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_213 )
continue;
if ( ! ( F_183 ( V_393 , V_188 ) && V_188 -> V_358 ) )
continue;
for ( V_455 = 1 ; ; V_455 ++ ) {
struct V_479 * V_343 ;
const struct V_210 * V_186 = F_121 ( V_455 ) ;
if ( ! V_186 )
break;
if ( ! V_186 -> V_213 )
continue;
if ( ! ( F_182 ( V_393 , V_186 ) && V_186 -> V_358 ) )
continue;
V_343 = (struct V_479 * ) F_43 ( V_8 , sizeof( struct V_479 ) ) ;
memset ( V_343 , 0 , sizeof( * V_343 ) ) ;
V_75 -> V_481 += sizeof( struct V_479 ) / 8 ;
V_343 -> V_486 = V_186 -> V_214 . V_215 ;
V_343 -> V_487 = V_186 -> V_214 . V_488 ;
V_343 -> V_489 = V_186 -> V_214 . V_490 ;
V_343 -> V_495 = V_188 -> V_214 . V_215 ;
V_343 -> V_496 = V_188 -> V_214 . V_488 ;
V_343 -> V_497 = V_188 -> V_214 . V_490 ;
V_343 -> V_491 = 24 * 60 * 60 ;
V_343 -> V_492 = 20 * 60 * 60 ;
V_343 -> V_493 = 8 * 60 * 60 ;
V_343 -> V_494 = 7 * 60 * 60 ;
}
}
}
static int F_188 ( struct V_380 * V_381 , const struct V_342 * V_343 )
{
return 0 ;
}
static int F_189 ( struct V_143 * V_165 , const struct V_342 * V_343 )
{
struct V_41 * V_346 ;
struct V_58 * V_307 ;
int V_498 ;
int V_167 ;
V_498 = V_343 -> V_61 . V_498 ;
if ( V_498 )
V_167 = 2 ;
else
V_167 = 1 ;
V_346 = F_76 ( V_165 , V_167 ) ;
if ( F_94 ( V_346 ) )
return F_95 ( V_346 ) ;
V_307 = (struct V_58 * ) V_346 -> V_61 ;
V_307 -> V_319 = V_29 ;
V_307 -> V_320 = V_341 ;
V_307 -> V_146 = F_54 ( V_165 -> V_195 . V_134 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_62 = 0 ;
V_307 -> V_323 = 0 ;
F_34 ( V_346 , V_64 , V_55 , NULL , F_102 ( V_165 ) ) ;
return 0 ;
}
static int F_190 ( struct V_143 * V_165 , const struct V_342 * V_343 )
{
struct V_10 * V_10 = V_165 ? F_102 ( V_165 ) : V_343 -> V_10 ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
if ( F_3 ( & V_12 -> V_17 ) == 0 )
return 0 ;
switch ( V_343 -> V_326 ) {
case V_340 :
return F_189 ( V_165 , V_343 ) ;
case V_334 :
case V_336 :
case V_338 :
return F_101 ( V_165 , V_343 ) ;
case V_370 :
return F_126 ( V_343 ) ;
case V_499 :
break;
default:
F_11 ( L_3 , V_343 -> V_326 ) ;
break;
}
return 0 ;
}
static int F_191 ( struct V_380 * V_381 , int V_382 , const struct V_342 * V_343 )
{
if ( V_381 && V_381 -> type != V_389 )
return 0 ;
switch ( V_343 -> V_326 ) {
case V_333 :
return F_188 ( V_381 , V_343 ) ;
case V_327 :
case V_329 :
case V_331 :
return F_150 ( V_381 , V_382 , V_343 ) ;
case V_469 :
if ( V_343 -> V_61 . type != V_389 )
break;
return F_177 ( V_343 ) ;
default:
F_11 ( L_2 , V_343 -> V_326 ) ;
break;
}
return 0 ;
}
static T_6 F_192 ( void )
{
T_6 V_500 ;
static T_10 V_501 ;
do {
V_500 = F_193 ( & V_501 ) ;
} while ( ! V_500 );
return V_500 ;
}
static int F_194 ( struct V_143 * V_165 , struct V_392 * V_393 , struct V_380 * V_381 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
struct V_76 * V_79 ;
struct V_406 * V_407 ;
int V_179 ;
int V_176 ;
struct V_89 * V_90 ;
struct V_174 * V_175 ;
int V_97 = 0 ;
V_179 = F_62 ( V_165 -> V_182 . V_135 ) ;
if ( ! V_179 )
return - V_71 ;
V_176 = sizeof( struct V_58 ) +
( sizeof( struct V_76 ) * 2 ) +
( V_179 * 2 ) +
sizeof( struct V_406 ) ;
if ( V_165 -> V_195 . V_134 == V_129 )
V_176 += F_184 ( V_393 ) ;
else if ( V_165 -> V_195 . V_134 == V_131 )
V_176 += F_185 ( V_393 ) ;
if ( ( V_175 = V_165 -> V_183 ) ) {
V_97 = F_63 ( V_175 -> V_104 ) ;
V_176 += sizeof( struct V_89 ) + V_97 ;
}
V_8 = F_41 ( V_176 + 16 , V_64 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_319 = V_29 ;
V_59 -> V_320 = V_502 ;
V_59 -> V_146 = F_54 ( V_165 -> V_195 . V_134 ) ;
V_59 -> V_73 = V_176 / sizeof( V_74 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_322 = 0 ;
V_59 -> V_62 = V_165 -> V_199 . V_303 = F_192 () ;
V_59 -> V_323 = 0 ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_179 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_179 ) /
sizeof( V_74 ) ;
V_79 -> V_249 = V_120 ;
V_79 -> V_250 = 0 ;
V_79 -> V_251 = 0 ;
V_79 -> V_87 =
F_66 ( & V_165 -> V_182 . V_185 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_179 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_179 ) /
sizeof( V_74 ) ;
V_79 -> V_249 = V_121 ;
V_79 -> V_250 = 0 ;
V_79 -> V_251 = 0 ;
V_79 -> V_87 =
F_66 ( & V_165 -> V_195 . V_252 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_407 = (struct V_406 * ) F_43 ( V_8 , sizeof( struct V_406 ) ) ;
V_407 -> V_408 = sizeof( struct V_406 ) / sizeof( V_74 ) ;
V_407 -> V_413 = V_414 ;
V_407 -> V_415 = V_419 ;
V_407 -> V_421 = V_503 + 1 ;
V_407 -> V_422 = 0 ;
V_407 -> V_423 = V_381 -> V_424 ;
V_407 -> V_425 = V_381 -> V_426 ;
if ( V_165 -> V_195 . V_134 == V_129 )
F_186 ( V_8 , V_393 ) ;
else if ( V_165 -> V_195 . V_134 == V_131 )
F_187 ( V_8 , V_393 ) ;
if ( V_175 ) {
V_90 = (struct V_89 * ) F_43 ( V_8 ,
sizeof( struct V_89 ) + V_97 ) ;
V_90 -> V_93 =
( sizeof( struct V_89 ) + V_97 ) / sizeof( V_74 ) ;
V_90 -> V_99 = V_124 ;
V_90 -> V_101 = V_175 -> V_100 ;
V_90 -> V_103 = V_175 -> V_102 ;
V_90 -> V_91 = V_175 -> V_104 ;
memcpy ( V_90 + 1 , V_175 -> V_286 ,
V_175 -> V_104 ) ;
}
return F_34 ( V_8 , V_64 , V_55 , NULL , F_102 ( V_165 ) ) ;
}
static struct V_380 * F_195 ( struct V_2 * V_3 , int V_504 ,
T_7 * V_61 , int V_47 , int * V_382 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_380 * V_381 ;
struct V_406 * V_407 = (struct V_406 * ) V_61 ;
struct V_89 * V_90 ;
switch ( V_3 -> V_38 ) {
case V_85 :
if ( V_504 != V_505 ) {
* V_382 = - V_305 ;
return NULL ;
}
break;
#if F_45 ( V_81 )
case V_88 :
if ( V_504 != V_506 ) {
* V_382 = - V_305 ;
return NULL ;
}
break;
#endif
default:
* V_382 = - V_71 ;
return NULL ;
}
* V_382 = - V_71 ;
if ( V_47 < sizeof( struct V_406 ) ||
V_407 -> V_408 * 8 > V_47 ||
V_407 -> V_415 > V_507 ||
( ! V_407 -> V_421 || V_407 -> V_421 > V_508 ) )
return NULL ;
V_381 = F_152 ( V_10 , V_64 ) ;
if ( V_381 == NULL ) {
* V_382 = - V_44 ;
return NULL ;
}
V_381 -> V_417 = ( V_407 -> V_415 == V_416 ?
V_433 : V_418 ) ;
V_381 -> V_230 . V_240 = V_436 ;
V_381 -> V_230 . V_233 = V_436 ;
V_381 -> V_230 . V_239 = V_436 ;
V_381 -> V_230 . V_231 = V_436 ;
V_381 -> V_135 = V_3 -> V_38 ;
V_381 -> V_383 = 0 ;
if ( V_407 -> V_415 == V_419 &&
( * V_382 = F_145 ( V_381 , V_407 ) ) < 0 )
goto V_35;
if ( V_47 >= ( V_407 -> V_408 * 8 +
sizeof( struct V_89 ) ) ) {
char * V_75 = ( char * ) V_407 ;
struct V_94 * V_96 ;
V_75 += V_407 -> V_408 * 8 ;
V_90 = (struct V_89 * ) V_75 ;
if ( V_47 < V_407 -> V_408 * 8 +
V_90 -> V_93 ) {
* V_382 = - V_71 ;
goto V_35;
}
if ( ( * V_382 = F_48 ( V_75 ) ) )
goto V_35;
V_96 = F_49 ( V_90 , V_64 ) ;
* V_382 = F_154 ( & V_381 -> V_183 , V_96 , V_64 ) ;
F_82 ( V_96 ) ;
if ( * V_382 )
goto V_35;
}
* V_382 = V_407 -> V_421 - 1 ;
return V_381 ;
V_35:
V_381 -> V_386 . V_437 = 1 ;
F_159 ( V_381 ) ;
return NULL ;
}
static int F_196 ( struct V_143 * V_165 , T_4 * V_509 , T_5 V_254 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
struct V_144 * V_136 ;
struct V_76 * V_79 ;
struct V_192 * V_272 ;
int V_179 ;
int V_176 ;
T_8 V_125 = ( V_165 -> V_195 . V_134 == V_131 ? V_130 : 0 ) ;
struct V_180 * V_181 = NULL ;
V_179 = F_62 ( V_165 -> V_182 . V_135 ) ;
if ( ! V_179 )
return - V_71 ;
if ( ! V_125 )
return - V_71 ;
if ( ! V_165 -> V_189 )
return - V_71 ;
V_181 = V_165 -> V_189 ;
V_176 = sizeof( struct V_58 ) +
sizeof( struct V_144 ) +
( sizeof( struct V_76 ) * 2 ) +
( V_179 * 2 ) +
( sizeof( struct V_192 ) * 2 ) ;
V_8 = F_41 ( V_176 + 16 , V_64 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_319 = V_29 ;
V_59 -> V_320 = V_510 ;
V_59 -> V_146 = V_125 ;
V_59 -> V_73 = V_176 / sizeof( V_74 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_322 = 0 ;
V_59 -> V_62 = V_165 -> V_199 . V_303 = F_192 () ;
V_59 -> V_323 = 0 ;
V_136 = (struct V_144 * ) F_43 ( V_8 , sizeof( struct V_144 ) ) ;
V_136 -> V_193 = sizeof( struct V_144 ) / sizeof( V_74 ) ;
V_136 -> V_194 = V_145 ;
V_136 -> V_148 = V_165 -> V_195 . V_196 ;
V_136 -> V_197 = 0 ;
V_136 -> V_202 = 0 ;
V_136 -> V_209 = 0 ;
V_136 -> V_216 = 0 ;
V_136 -> V_218 = 0 ;
V_79 = (struct V_76 * )
F_43 ( V_8 , sizeof( struct V_76 ) + V_179 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_179 ) /
sizeof( V_74 ) ;
V_79 -> V_249 = V_120 ;
V_79 -> V_250 = 0 ;
V_79 -> V_251 = 0 ;
V_79 -> V_87 =
F_66 ( & V_165 -> V_182 . V_185 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_272 = (struct V_192 * ) F_43 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_74 ) ;
V_272 -> V_279 = V_280 ;
V_272 -> V_281 = V_181 -> V_282 ;
V_272 -> V_283 = 0 ;
V_79 = (struct V_76 * )
F_43 ( V_8 , sizeof( struct V_76 ) + V_179 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_179 ) /
sizeof( V_74 ) ;
V_79 -> V_249 = V_121 ;
V_79 -> V_250 = 0 ;
V_79 -> V_251 = 0 ;
V_79 -> V_87 =
F_66 ( V_509 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_272 = (struct V_192 * ) F_43 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_74 ) ;
V_272 -> V_279 = V_284 ;
V_272 -> V_281 = V_254 ;
V_272 -> V_283 = 0 ;
return F_34 ( V_8 , V_64 , V_55 , NULL , F_102 ( V_165 ) ) ;
}
static int F_197 ( struct V_41 * V_8 , int V_511 , int type ,
const struct V_438 * V_184 )
{
struct V_76 * V_79 ;
V_79 = (struct V_76 * ) F_43 ( V_8 , sizeof( struct V_76 ) + V_511 ) ;
V_79 -> V_86 = ( sizeof( struct V_76 ) + V_511 ) / 8 ;
V_79 -> V_249 = type ;
V_79 -> V_250 = V_184 -> V_134 ;
V_79 -> V_251 = 0 ;
switch ( type ) {
case V_120 :
V_79 -> V_87 = V_184 -> V_253 ;
F_66 ( & V_184 -> V_185 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_184 -> V_135 ) ;
break;
case V_121 :
V_79 -> V_87 = V_184 -> V_411 ;
F_66 ( & V_184 -> V_252 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_184 -> V_135 ) ;
break;
default:
return - V_71 ;
}
return 0 ;
}
static int F_198 ( struct V_41 * V_8 , const struct V_454 * V_455 )
{
struct V_452 * V_453 ;
T_7 * V_136 ;
int V_135 = V_455 -> V_135 ;
int V_403 = F_57 ( V_135 ) ;
int V_512 ;
V_512 = ( sizeof( struct V_452 ) +
F_166 ( V_135 ) ) ;
V_453 = (struct V_452 * ) F_43 ( V_8 , V_512 ) ;
memset ( V_453 , 0 , V_512 ) ;
V_453 -> V_459 = V_512 / 8 ;
V_453 -> V_513 = V_456 ;
V_453 -> V_458 = V_455 -> V_457 ;
V_136 = ( T_7 * ) ( V_453 + 1 ) ;
if ( ! F_66 ( & V_455 -> V_460 , 0 , (struct V_78 * ) V_136 , V_135 ) ||
! F_66 ( & V_455 -> V_461 , 0 , (struct V_78 * ) ( V_136 + V_403 ) , V_135 ) )
return - V_71 ;
return 0 ;
}
static int F_199 ( struct V_41 * V_8 ,
V_72 V_134 , V_72 V_149 , int V_514 ,
T_11 V_270 , V_72 V_135 ,
const T_4 * V_105 , const T_4 * V_106 )
{
struct V_390 * V_391 ;
T_7 * V_136 ;
int V_403 = F_57 ( V_135 ) ;
int V_512 ;
V_512 = sizeof( struct V_390 ) +
F_166 ( V_135 ) ;
V_391 = (struct V_390 * ) F_43 ( V_8 , V_512 ) ;
memset ( V_391 , 0 , V_512 ) ;
V_391 -> V_409 = V_512 ;
V_391 -> V_397 = V_134 ;
V_391 -> V_396 = V_149 ;
V_391 -> V_398 = V_514 ;
V_391 -> V_402 = V_270 ;
V_136 = ( T_7 * ) ( V_391 + 1 ) ;
if ( ! F_66 ( V_105 , 0 , (struct V_78 * ) V_136 , V_135 ) ||
! F_66 ( V_106 , 0 , (struct V_78 * ) ( V_136 + V_403 ) , V_135 ) )
return - V_71 ;
return 0 ;
}
static int F_200 ( const struct V_438 * V_184 , T_7 V_382 , T_7 type ,
const struct V_442 * V_443 , int V_515 ,
const struct V_454 * V_455 )
{
int V_350 ;
int V_516 ;
int V_176 = 0 ;
int V_517 = 0 ;
struct V_41 * V_8 ;
struct V_58 * V_59 ;
struct V_406 * V_407 ;
const struct V_442 * V_518 ;
if ( type != V_389 )
return 0 ;
if ( V_515 <= 0 || V_515 > V_394 )
return - V_71 ;
if ( V_455 != NULL ) {
V_176 += F_63 ( sizeof( struct V_452 ) +
F_166 ( V_455 -> V_135 ) ) ;
}
V_516 = F_62 ( V_184 -> V_135 ) ;
if ( ! V_516 )
return - V_71 ;
V_176 += ( sizeof( struct V_76 ) + V_516 ) * 2 ;
V_517 += sizeof( struct V_406 ) ;
for ( V_350 = 0 , V_518 = V_443 ; V_350 < V_515 ; V_350 ++ , V_518 ++ ) {
V_517 += sizeof( struct V_390 ) +
F_166 ( V_518 -> V_447 ) ;
V_517 += sizeof( struct V_390 ) +
F_166 ( V_518 -> V_450 ) ;
}
V_176 += sizeof( struct V_58 ) + V_517 ;
V_8 = F_41 ( V_176 , V_64 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_319 = V_29 ;
V_59 -> V_320 = V_519 ;
V_59 -> V_146 = F_54 ( V_443 -> V_134 ) ;
V_59 -> V_73 = V_176 / 8 ;
V_59 -> V_63 = 0 ;
V_59 -> V_322 = 0 ;
V_59 -> V_62 = 0 ;
V_59 -> V_323 = 0 ;
if ( V_455 != NULL && ( F_198 ( V_8 , V_455 ) < 0 ) )
goto V_23;
F_197 ( V_8 , V_516 , V_120 , V_184 ) ;
F_197 ( V_8 , V_516 , V_121 , V_184 ) ;
V_407 = (struct V_406 * ) F_43 ( V_8 , sizeof( struct V_406 ) ) ;
V_407 -> V_408 = V_517 / 8 ;
V_407 -> V_413 = V_414 ;
V_407 -> V_415 = V_419 ;
V_407 -> V_421 = V_382 + 1 ;
V_407 -> V_422 = 0 ;
V_407 -> V_423 = 0 ;
V_407 -> V_425 = 0 ;
for ( V_350 = 0 , V_518 = V_443 ; V_350 < V_515 ; V_350 ++ , V_518 ++ ) {
int V_149 = F_64 ( V_518 -> V_149 ) ;
if ( V_149 < 0 )
goto V_23;
if ( F_199 ( V_8 , V_518 -> V_134 , V_149 ,
( V_518 -> V_270 ? V_401 : V_428 ) ,
V_518 -> V_270 , V_518 -> V_447 ,
& V_518 -> V_445 , & V_518 -> V_446 ) < 0 )
goto V_23;
if ( F_199 ( V_8 , V_518 -> V_134 , V_149 ,
( V_518 -> V_270 ? V_401 : V_428 ) ,
V_518 -> V_270 , V_518 -> V_450 ,
& V_518 -> V_448 , & V_518 -> V_449 ) < 0 )
goto V_23;
}
F_34 ( V_8 , V_64 , V_53 , NULL , & V_520 ) ;
return 0 ;
V_23:
F_5 ( V_8 ) ;
return - V_71 ;
}
static int F_200 ( const struct V_438 * V_184 , T_7 V_382 , T_7 type ,
const struct V_442 * V_443 , int V_515 ,
const struct V_454 * V_455 )
{
return - V_462 ;
}
static int F_201 ( struct V_521 * V_521 ,
struct V_20 * V_2 , struct V_522 * V_523 , T_12 V_47 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_41 * V_8 = NULL ;
struct V_58 * V_59 = NULL ;
int V_23 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
V_23 = - V_305 ;
if ( V_523 -> V_524 & V_525 )
goto V_35;
V_23 = - V_472 ;
if ( ( unsigned int ) V_47 > V_3 -> V_526 - 32 )
goto V_35;
V_23 = - V_44 ;
V_8 = F_41 ( V_47 , V_33 ) ;
if ( V_8 == NULL )
goto V_35;
V_23 = - V_527 ;
if ( F_202 ( F_43 ( V_8 , V_47 ) , V_523 -> V_528 , V_47 ) )
goto V_35;
V_59 = F_181 ( V_8 , & V_23 ) ;
if ( ! V_59 )
goto V_35;
F_15 ( & V_10 -> V_529 . V_530 ) ;
V_23 = F_180 ( V_3 , V_8 , V_59 ) ;
F_17 ( & V_10 -> V_529 . V_530 ) ;
V_35:
if ( V_23 && V_59 && F_40 ( V_59 , V_23 , V_3 ) == 0 )
V_23 = 0 ;
F_5 ( V_8 ) ;
return V_23 ? : V_47 ;
}
static int F_203 ( struct V_521 * V_521 ,
struct V_20 * V_2 , struct V_522 * V_523 , T_12 V_47 ,
int V_219 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_8 ;
int V_531 , V_23 ;
V_23 = - V_71 ;
if ( V_219 & ~ ( V_532 | V_533 | V_534 | V_535 ) )
goto V_35;
V_8 = F_204 ( V_3 , V_219 , V_219 & V_533 , & V_23 ) ;
if ( V_8 == NULL )
goto V_35;
V_531 = V_8 -> V_47 ;
if ( V_531 > V_47 ) {
V_523 -> V_524 |= V_534 ;
V_531 = V_47 ;
}
F_205 ( V_8 ) ;
V_23 = F_206 ( V_8 , 0 , V_523 -> V_528 , V_531 ) ;
if ( V_23 )
goto V_536;
F_207 ( V_523 , V_3 , V_8 ) ;
V_23 = ( V_219 & V_534 ) ? V_8 -> V_47 : V_531 ;
if ( V_6 -> V_7 . V_7 != NULL &&
3 * F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 )
F_38 ( V_6 ) ;
V_536:
F_208 ( V_3 , V_8 ) ;
V_35:
return V_23 ;
}
static int F_209 ( struct V_537 * V_538 , void * V_539 )
{
struct V_2 * V_540 = F_210 ( V_539 ) ;
if ( V_539 == V_541 )
F_211 ( V_538 , L_4 ) ;
else
F_211 ( V_538 , L_5 ,
V_540 ,
F_3 ( & V_540 -> V_542 ) ,
F_212 ( V_540 ) ,
F_213 ( V_540 ) ,
F_214 ( F_215 ( V_538 ) , F_216 ( V_540 ) ) ,
F_217 ( V_540 )
) ;
return 0 ;
}
static void * F_218 ( struct V_537 * V_538 , T_13 * V_543 )
__acquires( T_14 )
{
struct V_10 * V_10 = F_219 ( V_538 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_35 () ;
return F_220 ( & V_12 -> V_19 , * V_543 ) ;
}
static void * F_221 ( struct V_537 * V_538 , void * V_539 , T_13 * V_543 )
{
struct V_10 * V_10 = F_219 ( V_538 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
return F_222 ( V_539 , & V_12 -> V_19 , V_543 ) ;
}
static void F_223 ( struct V_537 * V_538 , void * V_539 )
__releases( T_14 )
{
F_37 () ;
}
static int F_224 ( struct V_544 * V_544 , struct V_545 * V_545 )
{
return F_225 ( V_544 , V_545 , & V_546 ,
sizeof( struct V_547 ) ) ;
}
static int T_15 F_226 ( struct V_10 * V_10 )
{
struct V_548 * V_549 ;
V_549 = F_227 ( L_6 , 0 , V_10 -> V_550 , & V_551 ) ;
if ( V_549 == NULL )
return - V_31 ;
return 0 ;
}
static void T_16 F_228 ( struct V_10 * V_10 )
{
F_229 ( L_6 , V_10 -> V_550 ) ;
}
static inline int F_226 ( struct V_10 * V_10 )
{
return 0 ;
}
static inline void F_228 ( struct V_10 * V_10 )
{
}
static int T_15 F_230 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
int V_552 ;
F_231 ( & V_12 -> V_19 ) ;
F_232 ( & V_12 -> V_17 , 0 ) ;
V_552 = F_226 ( V_10 ) ;
return V_552 ;
}
static void T_16 F_233 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_228 ( V_10 ) ;
F_42 ( ! F_234 ( & V_12 -> V_19 ) ) ;
}
static void T_17 F_235 ( void )
{
F_236 ( & V_553 ) ;
F_237 ( V_32 ) ;
F_238 ( & V_554 ) ;
F_239 ( & V_34 ) ;
}
static int T_18 F_240 ( void )
{
int V_23 = F_241 ( & V_34 , 0 ) ;
if ( V_23 != 0 )
goto V_35;
V_23 = F_242 ( & V_554 ) ;
if ( V_23 != 0 )
goto V_555;
V_23 = F_243 ( & V_556 ) ;
if ( V_23 != 0 )
goto V_557;
V_23 = F_244 ( & V_553 ) ;
if ( V_23 != 0 )
goto V_558;
V_35:
return V_23 ;
V_558:
F_237 ( V_32 ) ;
V_557:
F_238 ( & V_554 ) ;
V_555:
F_239 ( & V_34 ) ;
goto V_35;
}
