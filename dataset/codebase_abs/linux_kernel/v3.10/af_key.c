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
static inline struct V_94 * F_49 ( const struct V_89 * V_90 )
{
struct V_94 * V_95 = NULL ;
int V_96 = V_90 -> V_91 ;
V_95 = F_50 ( ( sizeof( * V_95 ) + V_96 ) , V_33 ) ;
if ( ! V_95 )
return NULL ;
V_95 -> V_47 = F_47 ( V_90 ) ;
V_95 -> V_97 = V_90 -> V_98 ;
V_95 -> V_99 = V_90 -> V_100 ;
V_95 -> V_101 = V_90 -> V_102 ;
V_95 -> V_103 = V_90 -> V_91 ;
memcpy ( V_95 + 1 , V_90 + 1 ,
V_95 -> V_103 ) ;
return V_95 ;
}
static int F_51 ( const struct V_76 * V_104 ,
const struct V_76 * V_105 )
{
const struct V_78 * V_106 , * V_107 ;
if ( ! V_104 || ! V_105 )
return 0 ;
V_106 = ( const struct V_78 * ) ( V_104 + 1 ) ;
V_107 = ( const struct V_78 * ) ( V_105 + 1 ) ;
if ( V_106 -> V_84 != V_107 -> V_84 )
return 0 ;
if ( V_106 -> V_84 != V_85
#if F_45 ( V_81 )
&& V_106 -> V_84 != V_88
#endif
)
return 0 ;
return 1 ;
}
static int F_52 ( struct V_41 * V_8 , const struct V_58 * V_59 , void * * V_108 )
{
const char * V_75 = ( char * ) V_59 ;
int V_47 = V_8 -> V_47 ;
V_47 -= sizeof( * V_59 ) ;
V_75 += sizeof( * V_59 ) ;
while ( V_47 > 0 ) {
const struct V_109 * V_110 = ( const struct V_109 * ) V_75 ;
T_2 V_111 ;
int V_112 ;
V_112 = V_110 -> V_113 ;
V_112 *= sizeof( V_74 ) ;
V_111 = V_110 -> V_114 ;
if ( V_112 < sizeof( V_74 ) ||
V_112 > V_47 ||
V_111 == V_115 )
return - V_71 ;
if ( V_111 <= V_116 ) {
int V_117 = ( int ) V_118 [ V_111 ] ;
if ( V_112 < V_117 )
return - V_71 ;
if ( V_108 [ V_111 - 1 ] != NULL )
return - V_71 ;
if ( V_111 == V_119 ||
V_111 == V_120 ||
V_111 == V_121 ||
V_111 == V_122 ) {
if ( F_44 ( V_75 ) )
return - V_71 ;
}
if ( V_111 == V_123 ) {
if ( F_48 ( V_75 ) )
return - V_71 ;
}
V_108 [ V_111 - 1 ] = ( void * ) V_75 ;
}
V_75 += V_112 ;
V_47 -= V_112 ;
}
return 0 ;
}
static T_2
F_53 ( V_72 V_124 )
{
switch ( V_124 ) {
case V_125 :
return V_126 ;
case V_127 :
return V_128 ;
case V_129 :
return V_130 ;
case V_131 :
return V_132 ;
break;
default:
return 0 ;
}
}
static V_72
F_54 ( T_2 V_133 )
{
switch ( V_133 ) {
case V_128 :
return V_127 ;
case V_130 :
return V_129 ;
case V_132 :
return V_131 ;
break;
default:
return 0 ;
}
}
static V_72 F_55 ( V_72 V_133 )
{
return V_133 == V_126 ? 0 : V_133 ;
}
static V_72 F_56 ( V_72 V_133 )
{
return V_133 ? V_133 : V_126 ;
}
static inline int F_57 ( T_3 V_134 )
{
switch ( V_134 ) {
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
int F_58 ( const struct V_78 * V_135 , T_4 * V_136 )
{
switch ( V_135 -> V_84 ) {
case V_85 :
V_136 -> V_137 =
( (struct V_80 * ) V_135 ) -> V_138 . V_106 ;
return V_85 ;
#if F_45 ( V_81 )
case V_88 :
memcpy ( V_136 -> V_139 ,
& ( (struct V_82 * ) V_135 ) -> V_140 ,
sizeof( struct V_141 ) ) ;
return V_88 ;
#endif
}
return 0 ;
}
static
int F_59 ( const struct V_76 * V_79 , T_4 * V_136 )
{
return F_58 ( (struct V_78 * ) ( V_79 + 1 ) ,
V_136 ) ;
}
static struct V_142 * F_60 ( struct V_10 * V_10 , const struct V_58 * V_59 , void * const * V_108 )
{
const struct V_143 * V_135 ;
const struct V_76 * V_79 ;
T_2 V_133 ;
unsigned short V_134 ;
T_4 * V_136 ;
V_135 = V_108 [ V_144 - 1 ] ;
if ( V_135 == NULL )
return NULL ;
V_133 = F_53 ( V_59 -> V_145 ) ;
if ( V_133 == 0 )
return NULL ;
V_79 = V_108 [ V_120 - 1 ] ;
if ( V_79 == NULL )
return NULL ;
V_134 = ( ( const struct V_78 * ) ( V_79 + 1 ) ) -> V_84 ;
switch ( V_134 ) {
case V_85 :
V_136 = ( T_4 * ) & ( ( const struct V_80 * ) ( V_79 + 1 ) ) -> V_138 ;
break;
#if F_45 ( V_81 )
case V_88 :
V_136 = ( T_4 * ) & ( ( const struct V_82 * ) ( V_79 + 1 ) ) -> V_140 ;
break;
#endif
default:
V_136 = NULL ;
}
if ( ! V_136 )
return NULL ;
return F_61 ( V_10 , V_146 , V_136 , V_135 -> V_147 , V_133 , V_134 ) ;
}
static int
F_62 ( T_3 V_134 )
{
return F_63 ( F_57 ( V_134 ) ) ;
}
static inline int F_64 ( int V_148 )
{
switch( V_148 ) {
case V_149 :
return V_150 ;
case V_151 :
return V_152 ;
case V_153 :
return V_154 ;
default:
return - 1 ;
}
}
static inline int F_65 ( int V_148 )
{
switch( V_148 ) {
case V_155 :
case V_150 :
return V_149 ;
case V_152 :
return V_151 ;
case V_154 :
return V_153 ;
default:
return - 1 ;
}
}
static unsigned int F_66 ( const T_4 * V_136 , T_5 V_156 ,
struct V_78 * V_135 ,
unsigned short V_134 )
{
switch ( V_134 ) {
case V_85 :
{
struct V_80 * sin = (struct V_80 * ) V_135 ;
sin -> V_157 = V_85 ;
sin -> V_158 = V_156 ;
sin -> V_138 . V_106 = V_136 -> V_137 ;
memset ( sin -> V_159 , 0 , sizeof( sin -> V_159 ) ) ;
return 32 ;
}
#if F_45 ( V_81 )
case V_88 :
{
struct V_82 * V_83 = (struct V_82 * ) V_135 ;
V_83 -> V_160 = V_88 ;
V_83 -> V_161 = V_156 ;
V_83 -> V_162 = 0 ;
V_83 -> V_140 = * (struct V_141 * ) V_136 -> V_139 ;
V_83 -> V_163 = 0 ;
return 128 ;
}
#endif
}
return 0 ;
}
static struct V_41 * F_67 ( const struct V_142 * V_164 ,
int V_165 , int V_166 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
struct V_143 * V_135 ;
struct V_167 * V_168 ;
struct V_76 * V_79 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
struct V_89 * V_90 ;
struct V_173 * V_174 ;
int V_96 = 0 ;
int V_175 ;
int V_176 = 0 ;
int V_177 = 0 ;
int V_178 ;
struct V_179 * V_180 = NULL ;
int V_148 ;
V_178 = F_62 ( V_164 -> V_181 . V_134 ) ;
if ( ! V_178 )
return F_68 ( - V_71 ) ;
V_175 = sizeof( struct V_58 ) + sizeof( struct V_143 ) +
sizeof( struct V_167 ) +
( ( V_166 & 1 ) ? sizeof( struct V_167 ) : 0 ) +
( ( V_166 & 2 ) ? sizeof( struct V_167 ) : 0 ) +
sizeof( struct V_76 ) * 2 +
V_178 * 2 +
sizeof( struct V_171 ) ;
if ( ( V_174 = V_164 -> V_182 ) ) {
V_96 = F_63 ( V_174 -> V_103 ) ;
V_175 += sizeof( struct V_89 ) + V_96 ;
}
if ( ! F_69 ( & V_164 -> V_183 . V_184 , & V_164 -> V_181 . V_184 , V_164 -> V_181 . V_134 ) )
V_175 += sizeof( struct V_76 ) + V_178 ;
if ( V_165 ) {
if ( V_164 -> V_185 && V_164 -> V_185 -> V_186 ) {
V_176 =
F_63 ( ( V_164 -> V_185 -> V_186 + 7 ) / 8 ) ;
V_175 += sizeof( struct V_169 ) + V_176 ;
}
if ( V_164 -> V_187 && V_164 -> V_187 -> V_186 ) {
V_177 =
F_63 ( ( V_164 -> V_187 -> V_186 + 7 ) / 8 ) ;
V_175 += sizeof( struct V_169 ) + V_177 ;
}
}
if ( V_164 -> V_188 )
V_180 = V_164 -> V_188 ;
if ( V_180 && V_180 -> V_189 ) {
V_175 += sizeof( struct V_190 ) ;
V_175 += sizeof( struct V_191 ) ;
V_175 += sizeof( struct V_191 ) ;
}
V_8 = F_41 ( V_175 + 16 , V_64 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
memset ( V_59 , 0 , V_175 ) ;
V_59 -> V_73 = V_175 / sizeof( V_74 ) ;
V_135 = (struct V_143 * ) F_43 ( V_8 , sizeof( struct V_143 ) ) ;
V_135 -> V_192 = sizeof( struct V_143 ) / sizeof( V_74 ) ;
V_135 -> V_193 = V_144 ;
V_135 -> V_147 = V_164 -> V_194 . V_195 ;
V_135 -> V_196 = V_164 -> V_181 . V_197 ;
switch ( V_164 -> V_198 . V_199 ) {
case V_200 :
V_135 -> V_201 = V_164 -> V_198 . V_202 ?
V_203 : V_204 ;
break;
case V_205 :
V_135 -> V_201 = V_206 ;
break;
default:
V_135 -> V_201 = V_207 ;
break;
}
V_135 -> V_208 = 0 ;
if ( V_164 -> V_185 ) {
struct V_209 * V_210 = F_70 ( V_164 -> V_185 -> V_211 , 0 ) ;
V_135 -> V_208 = ( V_210 && V_210 -> V_212 ) ?
V_210 -> V_213 . V_214 : 0 ;
}
V_135 -> V_215 = 0 ;
F_42 ( V_164 -> V_187 && V_164 -> V_216 ) ;
if ( V_164 -> V_187 ) {
struct V_209 * V_210 = F_71 ( V_164 -> V_187 -> V_211 , 0 ) ;
V_135 -> V_215 = ( V_210 && V_210 -> V_212 ) ?
V_210 -> V_213 . V_214 : 0 ;
}
if ( V_164 -> V_216 ) {
struct V_209 * V_210 = F_72 ( V_164 -> V_216 -> V_211 , 0 ) ;
V_135 -> V_215 = ( V_210 && V_210 -> V_212 ) ?
V_210 -> V_213 . V_214 : 0 ;
}
V_135 -> V_217 = 0 ;
if ( V_164 -> V_181 . V_218 & V_219 )
V_135 -> V_217 |= V_220 ;
if ( V_164 -> V_181 . V_218 & V_221 )
V_135 -> V_217 |= V_222 ;
if ( V_164 -> V_181 . V_218 & V_223 )
V_135 -> V_217 |= V_224 ;
if ( V_166 & 2 ) {
V_168 = (struct V_167 * ) F_43 ( V_8 ,
sizeof( struct V_167 ) ) ;
V_168 -> V_225 =
sizeof( struct V_167 ) / sizeof( V_74 ) ;
V_168 -> V_226 = V_227 ;
V_168 -> V_228 = F_73 ( V_164 -> V_229 . V_230 ) ;
V_168 -> V_231 = F_73 ( V_164 -> V_229 . V_232 ) ;
V_168 -> V_233 = V_164 -> V_229 . V_234 ;
V_168 -> V_235 = V_164 -> V_229 . V_236 ;
}
if ( V_166 & 1 ) {
V_168 = (struct V_167 * ) F_43 ( V_8 ,
sizeof( struct V_167 ) ) ;
V_168 -> V_225 =
sizeof( struct V_167 ) / sizeof( V_74 ) ;
V_168 -> V_226 = V_237 ;
V_168 -> V_228 = F_73 ( V_164 -> V_229 . V_238 ) ;
V_168 -> V_231 = F_73 ( V_164 -> V_229 . V_239 ) ;
V_168 -> V_233 = V_164 -> V_229 . V_240 ;
V_168 -> V_235 = V_164 -> V_229 . V_241 ;
}
V_168 = (struct V_167 * ) F_43 ( V_8 ,
sizeof( struct V_167 ) ) ;
V_168 -> V_225 =
sizeof( struct V_167 ) / sizeof( V_74 ) ;
V_168 -> V_226 = V_242 ;
V_168 -> V_228 = V_164 -> V_243 . V_244 ;
V_168 -> V_231 = V_164 -> V_243 . V_245 ;
V_168 -> V_233 = V_164 -> V_243 . V_246 ;
V_168 -> V_235 = V_164 -> V_243 . V_247 ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_178 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_178 ) /
sizeof( V_74 ) ;
V_79 -> V_248 = V_119 ;
V_79 -> V_249 = 0 ;
V_79 -> V_250 = 0 ;
V_79 -> V_87 =
F_66 ( & V_164 -> V_181 . V_184 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_164 -> V_181 . V_134 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_178 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_178 ) /
sizeof( V_74 ) ;
V_79 -> V_248 = V_120 ;
V_79 -> V_249 = 0 ;
V_79 -> V_250 = 0 ;
V_79 -> V_87 =
F_66 ( & V_164 -> V_194 . V_251 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_164 -> V_181 . V_134 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
if ( ! F_69 ( & V_164 -> V_183 . V_184 , & V_164 -> V_181 . V_184 ,
V_164 -> V_181 . V_134 ) ) {
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_178 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_178 ) /
sizeof( V_74 ) ;
V_79 -> V_248 = V_121 ;
V_79 -> V_249 =
F_56 ( V_164 -> V_183 . V_133 ) ;
V_79 -> V_87 = V_164 -> V_183 . V_252 ;
V_79 -> V_250 = 0 ;
F_66 ( & V_164 -> V_183 . V_184 , V_164 -> V_183 . V_253 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_164 -> V_181 . V_134 ) ;
}
if ( V_165 && V_176 ) {
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) + V_176 ) ;
V_170 -> V_254 = ( sizeof( struct V_169 ) + V_176 ) /
sizeof( V_74 ) ;
V_170 -> V_255 = V_256 ;
V_170 -> V_257 = V_164 -> V_185 -> V_186 ;
V_170 -> V_258 = 0 ;
memcpy ( V_170 + 1 , V_164 -> V_185 -> V_259 , ( V_164 -> V_185 -> V_186 + 7 ) / 8 ) ;
}
if ( V_165 && V_177 ) {
V_170 = (struct V_169 * ) F_43 ( V_8 ,
sizeof( struct V_169 ) + V_177 ) ;
V_170 -> V_254 = ( sizeof( struct V_169 ) +
V_177 ) / sizeof( V_74 ) ;
V_170 -> V_255 = V_260 ;
V_170 -> V_257 = V_164 -> V_187 -> V_186 ;
V_170 -> V_258 = 0 ;
memcpy ( V_170 + 1 , V_164 -> V_187 -> V_259 ,
( V_164 -> V_187 -> V_186 + 7 ) / 8 ) ;
}
V_172 = (struct V_171 * ) F_43 ( V_8 , sizeof( struct V_171 ) ) ;
V_172 -> V_261 = sizeof( struct V_171 ) / sizeof( V_74 ) ;
V_172 -> V_262 = V_263 ;
if ( ( V_148 = F_64 ( V_164 -> V_181 . V_148 ) ) < 0 ) {
F_5 ( V_8 ) ;
return F_68 ( - V_71 ) ;
}
V_172 -> V_264 = V_148 ;
V_172 -> V_265 = 0 ;
V_172 -> V_266 = 0 ;
V_172 -> V_267 = 0 ;
V_172 -> V_268 = V_164 -> V_181 . V_269 ;
if ( V_180 && V_180 -> V_189 ) {
struct V_190 * V_270 ;
struct V_191 * V_271 ;
V_270 = (struct V_190 * ) F_43 ( V_8 , sizeof( * V_270 ) ) ;
V_270 -> V_272 = sizeof( * V_270 ) / sizeof( V_74 ) ;
V_270 -> V_273 = V_274 ;
V_270 -> V_275 = V_180 -> V_189 ;
V_270 -> V_276 [ 0 ] = 0 ;
V_270 -> V_276 [ 1 ] = 0 ;
V_270 -> V_276 [ 2 ] = 0 ;
V_271 = (struct V_191 * ) F_43 ( V_8 , sizeof ( * V_271 ) ) ;
V_271 -> V_277 = sizeof( * V_271 ) / sizeof( V_74 ) ;
V_271 -> V_278 = V_279 ;
V_271 -> V_280 = V_180 -> V_281 ;
V_271 -> V_282 = 0 ;
V_271 = (struct V_191 * ) F_43 ( V_8 , sizeof ( * V_271 ) ) ;
V_271 -> V_277 = sizeof( * V_271 ) / sizeof( V_74 ) ;
V_271 -> V_278 = V_283 ;
V_271 -> V_280 = V_180 -> V_284 ;
V_271 -> V_282 = 0 ;
}
if ( V_174 ) {
V_90 = (struct V_89 * ) F_43 ( V_8 ,
sizeof( struct V_89 ) + V_96 ) ;
V_90 -> V_93 =
( sizeof( struct V_89 ) + V_96 ) / sizeof( V_74 ) ;
V_90 -> V_98 = V_123 ;
V_90 -> V_100 = V_174 -> V_99 ;
V_90 -> V_102 = V_174 -> V_101 ;
V_90 -> V_91 = V_174 -> V_103 ;
memcpy ( V_90 + 1 , V_174 -> V_285 ,
V_174 -> V_103 ) ;
}
return V_8 ;
}
static inline struct V_41 * F_75 ( const struct V_142 * V_164 )
{
struct V_41 * V_8 ;
V_8 = F_67 ( V_164 , 1 , 3 ) ;
return V_8 ;
}
static inline struct V_41 * F_76 ( const struct V_142 * V_164 ,
int V_166 )
{
return F_67 ( V_164 , 0 , V_166 ) ;
}
static struct V_142 * F_77 ( struct V_10 * V_10 ,
const struct V_58 * V_59 ,
void * const * V_108 )
{
struct V_142 * V_164 ;
const struct V_167 * V_168 ;
const struct V_143 * V_135 ;
const struct V_169 * V_170 ;
const struct V_89 * V_90 ;
T_2 V_133 ;
int V_23 ;
V_135 = V_108 [ V_144 - 1 ] ;
if ( ! V_135 ||
! F_51 ( V_108 [ V_119 - 1 ] ,
V_108 [ V_120 - 1 ] ) )
return F_68 ( - V_71 ) ;
if ( V_59 -> V_145 == V_129 &&
! V_108 [ V_260 - 1 ] )
return F_68 ( - V_71 ) ;
if ( V_59 -> V_145 == V_127 &&
! V_108 [ V_256 - 1 ] )
return F_68 ( - V_71 ) ;
if ( ! ! V_108 [ V_227 - 1 ] !=
! ! V_108 [ V_237 - 1 ] )
return F_68 ( - V_71 ) ;
V_133 = F_53 ( V_59 -> V_145 ) ;
if ( V_133 == 0 )
return F_68 ( - V_71 ) ;
V_23 = - V_44 ;
if ( V_135 -> V_208 > V_286 ||
( V_59 -> V_145 == V_131 &&
V_135 -> V_215 > V_287 ) ||
V_135 -> V_215 > V_288 )
return F_68 ( - V_71 ) ;
V_170 = V_108 [ V_256 - 1 ] ;
if ( V_170 != NULL &&
V_135 -> V_208 != V_289 &&
( ( V_170 -> V_257 + 7 ) / 8 == 0 ||
( V_170 -> V_257 + 7 ) / 8 > V_170 -> V_254 * sizeof( V_74 ) ) )
return F_68 ( - V_71 ) ;
V_170 = V_108 [ V_260 - 1 ] ;
if ( V_170 != NULL &&
V_135 -> V_215 != V_290 &&
( ( V_170 -> V_257 + 7 ) / 8 == 0 ||
( V_170 -> V_257 + 7 ) / 8 > V_170 -> V_254 * sizeof( V_74 ) ) )
return F_68 ( - V_71 ) ;
V_164 = F_78 ( V_10 ) ;
if ( V_164 == NULL )
return F_68 ( - V_44 ) ;
V_164 -> V_194 . V_133 = V_133 ;
V_164 -> V_194 . V_195 = V_135 -> V_147 ;
V_164 -> V_181 . V_197 = V_135 -> V_196 ;
if ( V_135 -> V_217 & V_220 )
V_164 -> V_181 . V_218 |= V_219 ;
if ( V_135 -> V_217 & V_222 )
V_164 -> V_181 . V_218 |= V_221 ;
if ( V_135 -> V_217 & V_224 )
V_164 -> V_181 . V_218 |= V_223 ;
V_168 = V_108 [ V_227 - 1 ] ;
if ( V_168 != NULL ) {
V_164 -> V_229 . V_230 = F_79 ( V_168 -> V_228 ) ;
V_164 -> V_229 . V_232 = F_79 ( V_168 -> V_231 ) ;
V_164 -> V_229 . V_234 = V_168 -> V_233 ;
V_164 -> V_229 . V_236 = V_168 -> V_235 ;
}
V_168 = V_108 [ V_237 - 1 ] ;
if ( V_168 != NULL ) {
V_164 -> V_229 . V_238 = F_79 ( V_168 -> V_228 ) ;
V_164 -> V_229 . V_239 = F_79 ( V_168 -> V_231 ) ;
V_164 -> V_229 . V_240 = V_168 -> V_233 ;
V_164 -> V_229 . V_241 = V_168 -> V_235 ;
}
V_90 = V_108 [ V_123 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_95 = F_49 ( V_90 ) ;
if ( ! V_95 )
goto V_35;
V_23 = F_80 ( V_164 , V_95 ) ;
F_81 ( V_95 ) ;
if ( V_23 )
goto V_35;
}
V_170 = V_108 [ V_256 - 1 ] ;
if ( V_135 -> V_208 ) {
int V_291 = 0 ;
struct V_209 * V_210 = F_82 ( V_135 -> V_208 ) ;
if ( ! V_210 || ! V_210 -> V_212 ) {
V_23 = - V_292 ;
goto V_35;
}
if ( V_170 )
V_291 = ( V_170 -> V_257 + 7 ) / 8 ;
V_164 -> V_185 = F_50 ( sizeof( * V_164 -> V_185 ) + V_291 , V_33 ) ;
if ( ! V_164 -> V_185 )
goto V_35;
strcpy ( V_164 -> V_185 -> V_211 , V_210 -> V_293 ) ;
V_164 -> V_185 -> V_186 = 0 ;
if ( V_170 ) {
V_164 -> V_185 -> V_186 = V_170 -> V_257 ;
memcpy ( V_164 -> V_185 -> V_259 , V_170 + 1 , V_291 ) ;
}
V_164 -> V_185 -> V_294 = V_210 -> V_295 . V_296 . V_297 ;
V_164 -> V_181 . V_298 = V_135 -> V_208 ;
}
if ( V_135 -> V_215 ) {
if ( V_59 -> V_145 == V_131 ) {
struct V_209 * V_210 = F_83 ( V_135 -> V_215 ) ;
if ( ! V_210 || ! V_210 -> V_212 ) {
V_23 = - V_292 ;
goto V_35;
}
V_164 -> V_216 = F_50 ( sizeof( * V_164 -> V_216 ) , V_33 ) ;
if ( ! V_164 -> V_216 )
goto V_35;
strcpy ( V_164 -> V_216 -> V_211 , V_210 -> V_293 ) ;
V_164 -> V_181 . V_299 = V_135 -> V_215 ;
} else {
int V_291 = 0 ;
struct V_209 * V_210 = F_84 ( V_135 -> V_215 ) ;
if ( ! V_210 || ! V_210 -> V_212 ) {
V_23 = - V_292 ;
goto V_35;
}
V_170 = (struct V_169 * ) V_108 [ V_260 - 1 ] ;
if ( V_170 )
V_291 = ( V_170 -> V_257 + 7 ) / 8 ;
V_164 -> V_187 = F_50 ( sizeof( * V_164 -> V_187 ) + V_291 , V_33 ) ;
if ( ! V_164 -> V_187 )
goto V_35;
strcpy ( V_164 -> V_187 -> V_211 , V_210 -> V_293 ) ;
V_164 -> V_187 -> V_186 = 0 ;
if ( V_170 ) {
V_164 -> V_187 -> V_186 = V_170 -> V_257 ;
memcpy ( V_164 -> V_187 -> V_259 , V_170 + 1 , V_291 ) ;
}
V_164 -> V_181 . V_300 = V_135 -> V_215 ;
}
}
V_164 -> V_181 . V_134 = F_59 ( (struct V_76 * ) V_108 [ V_119 - 1 ] ,
& V_164 -> V_181 . V_184 ) ;
if ( ! V_164 -> V_181 . V_134 ) {
V_23 = - V_301 ;
goto V_35;
}
F_59 ( (struct V_76 * ) V_108 [ V_120 - 1 ] ,
& V_164 -> V_194 . V_251 ) ;
if ( V_108 [ V_263 - 1 ] ) {
const struct V_171 * V_172 = V_108 [ V_263 - 1 ] ;
int V_148 = F_65 ( V_172 -> V_264 ) ;
if ( V_148 < 0 ) {
V_23 = - V_71 ;
goto V_35;
}
V_164 -> V_181 . V_148 = V_148 ;
V_164 -> V_181 . V_269 = V_172 -> V_268 ;
}
if ( V_108 [ V_121 - 1 ] ) {
const struct V_76 * V_79 = V_108 [ V_121 - 1 ] ;
V_164 -> V_183 . V_134 = F_59 ( V_79 , & V_164 -> V_183 . V_184 ) ;
V_164 -> V_183 . V_252 = V_79 -> V_87 ;
}
if ( ! V_164 -> V_183 . V_134 )
V_164 -> V_183 . V_134 = V_164 -> V_181 . V_134 ;
if ( V_108 [ V_274 - 1 ] ) {
const struct V_190 * V_270 ;
struct V_179 * V_180 ;
V_164 -> V_188 = F_50 ( sizeof( * V_164 -> V_188 ) , V_33 ) ;
if ( ! V_164 -> V_188 )
goto V_35;
V_180 = V_164 -> V_188 ;
V_270 = V_108 [ V_274 - 1 ] ;
V_180 -> V_189 = V_270 -> V_275 ;
if ( V_108 [ V_279 - 1 ] ) {
const struct V_191 * V_271 =
V_108 [ V_279 - 1 ] ;
V_180 -> V_281 = V_271 -> V_280 ;
}
if ( V_108 [ V_283 - 1 ] ) {
const struct V_191 * V_271 =
V_108 [ V_283 - 1 ] ;
V_180 -> V_284 = V_271 -> V_280 ;
}
memset ( & V_180 -> V_302 , 0 , sizeof( V_180 -> V_302 ) ) ;
}
V_23 = F_85 ( V_164 ) ;
if ( V_23 )
goto V_35;
V_164 -> V_198 . V_303 = V_59 -> V_62 ;
return V_164 ;
V_35:
V_164 -> V_198 . V_199 = V_304 ;
F_86 ( V_164 ) ;
return F_68 ( V_23 ) ;
}
static int F_87 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
return - V_305 ;
}
static int F_88 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_41 * V_306 ;
struct V_171 * V_172 ;
struct V_76 * V_184 , * V_251 ;
struct V_58 * V_307 ;
struct V_308 * V_309 ;
struct V_142 * V_164 = NULL ;
int V_148 ;
int V_23 ;
T_6 V_310 , V_311 ;
T_6 V_269 ;
T_7 V_133 ;
unsigned short V_134 ;
T_4 * V_312 = NULL , * V_313 = NULL ;
if ( ! F_51 ( V_108 [ V_119 - 1 ] ,
V_108 [ V_120 - 1 ] ) )
return - V_71 ;
V_133 = F_53 ( V_59 -> V_145 ) ;
if ( V_133 == 0 )
return - V_71 ;
if ( ( V_172 = V_108 [ V_263 - 1 ] ) != NULL ) {
V_148 = F_65 ( V_172 -> V_264 ) ;
if ( V_148 < 0 )
return - V_71 ;
V_269 = V_172 -> V_268 ;
} else {
V_148 = 0 ;
V_269 = 0 ;
}
V_184 = V_108 [ V_119 - 1 ] ;
V_251 = V_108 [ V_120 - 1 ] ;
V_134 = ( (struct V_78 * ) ( V_184 + 1 ) ) -> V_84 ;
switch ( V_134 ) {
case V_85 :
V_313 = ( T_4 * ) & ( (struct V_80 * ) ( V_251 + 1 ) ) -> V_138 . V_106 ;
V_312 = ( T_4 * ) & ( (struct V_80 * ) ( V_184 + 1 ) ) -> V_138 . V_106 ;
break;
#if F_45 ( V_81 )
case V_88 :
V_313 = ( T_4 * ) & ( (struct V_82 * ) ( V_251 + 1 ) ) -> V_140 ;
V_312 = ( T_4 * ) & ( (struct V_82 * ) ( V_184 + 1 ) ) -> V_140 ;
break;
#endif
}
if ( V_59 -> V_62 ) {
V_164 = F_89 ( V_10 , V_146 , V_59 -> V_62 ) ;
if ( V_164 && ! F_69 ( & V_164 -> V_194 . V_251 , V_313 , V_134 ) ) {
F_86 ( V_164 ) ;
V_164 = NULL ;
}
}
if ( ! V_164 )
V_164 = F_90 ( V_10 , & V_314 , V_148 , V_269 , V_133 , V_313 , V_312 , 1 , V_134 ) ;
if ( V_164 == NULL )
return - V_315 ;
V_310 = 0x100 ;
V_311 = 0x0fffffff ;
V_309 = V_108 [ V_316 - 1 ] ;
if ( V_309 ) {
V_310 = V_309 -> V_317 ;
V_311 = V_309 -> V_318 ;
}
V_23 = F_91 ( V_164 , V_310 , V_311 ) ;
V_306 = V_23 ? F_68 ( V_23 ) : F_75 ( V_164 ) ;
if ( F_92 ( V_306 ) ) {
F_86 ( V_164 ) ;
return F_93 ( V_306 ) ;
}
V_307 = (struct V_58 * ) V_306 -> V_61 ;
V_307 -> V_319 = V_59 -> V_319 ;
V_307 -> V_320 = V_321 ;
V_307 -> V_145 = F_54 ( V_133 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_62 = V_59 -> V_62 ;
V_307 -> V_323 = V_59 -> V_323 ;
F_86 ( V_164 ) ;
F_34 ( V_306 , V_33 , V_57 , V_3 , V_10 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_142 * V_164 ;
if ( V_59 -> V_73 != sizeof( struct V_58 ) / 8 )
return - V_305 ;
if ( V_59 -> V_62 == 0 || V_59 -> V_63 == 0 )
return 0 ;
V_164 = F_89 ( V_10 , V_146 , V_59 -> V_62 ) ;
if ( V_164 == NULL )
return 0 ;
F_95 ( & V_164 -> V_324 ) ;
if ( V_164 -> V_198 . V_199 == V_205 ) {
V_164 -> V_198 . V_199 = V_325 ;
F_96 ( & V_10 -> V_326 . V_327 ) ;
}
F_97 ( & V_164 -> V_324 ) ;
F_86 ( V_164 ) ;
return 0 ;
}
static inline int F_98 ( int V_328 )
{
switch ( V_328 ) {
case V_329 :
return V_330 ;
case V_331 :
return V_332 ;
case V_333 :
return V_334 ;
case V_335 :
default:
F_11 ( L_2 , V_328 ) ;
break;
}
return 0 ;
}
static inline int F_99 ( int V_328 )
{
switch ( V_328 ) {
case V_336 :
return V_337 ;
case V_338 :
return V_339 ;
case V_340 :
return V_341 ;
case V_342 :
return V_343 ;
default:
F_11 ( L_3 , V_328 ) ;
break;
}
return 0 ;
}
static int F_100 ( struct V_142 * V_164 , const struct V_344 * V_345 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
V_8 = F_75 ( V_164 ) ;
if ( F_92 ( V_8 ) )
return F_93 ( V_8 ) ;
V_59 = (struct V_58 * ) V_8 -> V_61 ;
V_59 -> V_319 = V_29 ;
V_59 -> V_320 = F_99 ( V_345 -> V_328 ) ;
V_59 -> V_145 = F_54 ( V_164 -> V_194 . V_133 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_322 = 0 ;
V_59 -> V_62 = V_345 -> V_303 ;
V_59 -> V_323 = V_345 -> V_346 ;
F_34 ( V_8 , V_64 , V_53 , NULL , F_101 ( V_164 ) ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_142 * V_164 ;
int V_23 ;
struct V_344 V_345 ;
V_164 = F_77 ( V_10 , V_59 , V_108 ) ;
if ( F_92 ( V_164 ) )
return F_93 ( V_164 ) ;
F_103 ( V_164 ) ;
if ( V_59 -> V_320 == V_339 )
V_23 = F_104 ( V_164 ) ;
else
V_23 = F_105 ( V_164 ) ;
F_106 ( V_164 , V_23 ? 0 : 1 ,
F_107 ( V_347 ) ,
F_108 ( V_347 ) , 0 ) ;
if ( V_23 < 0 ) {
V_164 -> V_198 . V_199 = V_304 ;
F_109 ( V_164 ) ;
goto V_35;
}
if ( V_59 -> V_320 == V_339 )
V_345 . V_328 = V_338 ;
else
V_345 . V_328 = V_340 ;
V_345 . V_303 = V_59 -> V_62 ;
V_345 . V_346 = V_59 -> V_323 ;
F_110 ( V_164 , & V_345 ) ;
V_35:
F_86 ( V_164 ) ;
return V_23 ;
}
static int F_111 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_142 * V_164 ;
struct V_344 V_345 ;
int V_23 ;
if ( ! V_108 [ V_144 - 1 ] ||
! F_51 ( V_108 [ V_119 - 1 ] ,
V_108 [ V_120 - 1 ] ) )
return - V_71 ;
V_164 = F_60 ( V_10 , V_59 , V_108 ) ;
if ( V_164 == NULL )
return - V_50 ;
if ( ( V_23 = F_112 ( V_164 ) ) )
goto V_35;
if ( F_113 ( V_164 ) ) {
V_23 = - V_26 ;
goto V_35;
}
V_23 = F_114 ( V_164 ) ;
if ( V_23 < 0 )
goto V_35;
V_345 . V_303 = V_59 -> V_62 ;
V_345 . V_346 = V_59 -> V_323 ;
V_345 . V_328 = V_336 ;
F_110 ( V_164 , & V_345 ) ;
V_35:
F_115 ( V_164 , V_23 ? 0 : 1 ,
F_107 ( V_347 ) ,
F_108 ( V_347 ) , 0 ) ;
F_86 ( V_164 ) ;
return V_23 ;
}
static int F_116 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
T_8 V_133 ;
struct V_41 * V_348 ;
struct V_58 * V_307 ;
struct V_142 * V_164 ;
if ( ! V_108 [ V_144 - 1 ] ||
! F_51 ( V_108 [ V_119 - 1 ] ,
V_108 [ V_120 - 1 ] ) )
return - V_71 ;
V_164 = F_60 ( V_10 , V_59 , V_108 ) ;
if ( V_164 == NULL )
return - V_50 ;
V_348 = F_75 ( V_164 ) ;
V_133 = V_164 -> V_194 . V_133 ;
F_86 ( V_164 ) ;
if ( F_92 ( V_348 ) )
return F_93 ( V_348 ) ;
V_307 = (struct V_58 * ) V_348 -> V_61 ;
V_307 -> V_319 = V_59 -> V_319 ;
V_307 -> V_320 = V_349 ;
V_307 -> V_145 = F_54 ( V_133 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_62 = V_59 -> V_62 ;
V_307 -> V_323 = V_59 -> V_323 ;
F_34 ( V_348 , V_64 , V_57 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static struct V_41 * F_117 ( const struct V_58 * V_66 ,
T_1 V_43 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
int V_47 , V_350 , V_351 , V_352 ;
V_350 = F_118 () ;
if ( V_350 ) {
V_350 *= sizeof( struct V_353 ) ;
V_350 += sizeof( struct V_354 ) ;
}
V_351 = F_119 () ;
if ( V_351 ) {
V_351 *= sizeof( struct V_353 ) ;
V_351 += sizeof( struct V_354 ) ;
}
V_47 = V_351 + V_350 + sizeof( struct V_58 ) ;
V_8 = F_41 ( V_47 + 16 , V_43 ) ;
if ( ! V_8 )
goto V_355;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( * V_59 ) ) ;
F_39 ( V_59 , V_66 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_73 = V_47 / sizeof( V_74 ) ;
if ( V_350 ) {
struct V_354 * V_77 ;
struct V_353 * V_356 ;
V_77 = (struct V_354 * ) F_43 ( V_8 , V_350 ) ;
V_356 = (struct V_353 * ) ( V_77 + 1 ) ;
V_77 -> V_357 = V_350 / sizeof( V_74 ) ;
V_77 -> V_358 = V_359 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
struct V_209 * V_185 = F_120 ( V_352 ) ;
if ( ! V_185 )
break;
if ( ! V_185 -> V_212 )
continue;
if ( V_185 -> V_360 )
* V_356 ++ = V_185 -> V_213 ;
}
}
if ( V_351 ) {
struct V_354 * V_77 ;
struct V_353 * V_356 ;
V_77 = (struct V_354 * ) F_43 ( V_8 , V_351 ) ;
V_356 = (struct V_353 * ) ( V_77 + 1 ) ;
V_77 -> V_357 = V_351 / sizeof( V_74 ) ;
V_77 -> V_358 = V_361 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
struct V_209 * V_187 = F_121 ( V_352 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_212 )
continue;
if ( V_187 -> V_360 )
* V_356 ++ = V_187 -> V_213 ;
}
}
V_355:
return V_8 ;
}
static int F_122 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_362 ;
if ( V_59 -> V_145 > V_363 )
return - V_71 ;
if ( V_59 -> V_145 != V_125 ) {
if ( V_6 -> V_56 & ( 1 << V_59 -> V_145 ) )
return - V_364 ;
V_6 -> V_56 |= ( 1 << V_59 -> V_145 ) ;
}
F_123 () ;
V_362 = F_117 ( V_59 , V_33 ) ;
if ( ! V_362 ) {
if ( V_59 -> V_145 != V_125 )
V_6 -> V_56 &= ~ ( 1 << V_59 -> V_145 ) ;
return - V_44 ;
}
F_34 ( V_362 , V_33 , V_55 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_124 ( struct V_2 * V_3 , const struct V_58 * V_365 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
V_8 = F_41 ( sizeof( struct V_58 ) + 16 , V_64 ) ;
if ( ! V_8 )
return - V_44 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
memcpy ( V_59 , V_365 , sizeof( struct V_58 ) ) ;
V_59 -> V_63 = ( V_72 ) 0 ;
V_59 -> V_73 = ( sizeof( struct V_58 ) / sizeof( V_74 ) ) ;
return F_34 ( V_8 , V_64 , V_57 , V_3 , F_7 ( V_3 ) ) ;
}
static int F_125 ( const struct V_344 * V_345 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
V_8 = F_41 ( sizeof( struct V_58 ) + 16 , V_64 ) ;
if ( ! V_8 )
return - V_44 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_145 = F_54 ( V_345 -> V_61 . V_133 ) ;
V_59 -> V_320 = V_366 ;
V_59 -> V_62 = V_345 -> V_303 ;
V_59 -> V_323 = V_345 -> V_346 ;
V_59 -> V_319 = V_29 ;
V_59 -> V_63 = ( V_72 ) 0 ;
V_59 -> V_73 = ( sizeof( struct V_58 ) / sizeof( V_74 ) ) ;
V_59 -> V_322 = 0 ;
F_34 ( V_8 , V_64 , V_53 , NULL , V_345 -> V_10 ) ;
return 0 ;
}
static int F_126 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_133 ;
struct V_344 V_345 ;
struct V_367 V_368 ;
int V_23 , V_51 ;
V_133 = F_53 ( V_59 -> V_145 ) ;
if ( V_133 == 0 )
return - V_71 ;
V_368 . V_369 = F_107 ( V_347 ) ;
V_368 . V_370 = F_108 ( V_347 ) ;
V_368 . V_371 = 0 ;
V_23 = F_127 ( V_10 , V_133 , & V_368 ) ;
V_51 = F_124 ( V_3 , V_59 ) ;
if ( V_23 || V_51 ) {
if ( V_23 == - V_50 )
V_23 = 0 ;
return V_23 ? V_23 : V_51 ;
}
V_345 . V_61 . V_133 = V_133 ;
V_345 . V_303 = V_59 -> V_62 ;
V_345 . V_346 = V_59 -> V_323 ;
V_345 . V_328 = V_372 ;
V_345 . V_10 = V_10 ;
F_110 ( NULL , & V_345 ) ;
return 0 ;
}
static int F_128 ( struct V_142 * V_164 , int V_373 , void * V_374 )
{
struct V_1 * V_6 = V_374 ;
struct V_41 * V_348 ;
struct V_58 * V_307 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_348 = F_75 ( V_164 ) ;
if ( F_92 ( V_348 ) )
return F_93 ( V_348 ) ;
V_307 = (struct V_58 * ) V_348 -> V_61 ;
V_307 -> V_319 = V_6 -> V_7 . V_375 ;
V_307 -> V_320 = V_376 ;
V_307 -> V_145 = F_54 ( V_164 -> V_194 . V_133 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_62 = V_373 + 1 ;
V_307 -> V_323 = V_6 -> V_7 . V_377 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_64 , V_57 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_348 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return F_130 ( V_10 , & V_6 -> V_7 . V_378 . V_199 , F_128 , ( void * ) V_6 ) ;
}
static void F_131 ( struct V_1 * V_6 )
{
F_132 ( & V_6 -> V_7 . V_378 . V_199 ) ;
}
static int F_133 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
T_7 V_133 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_379 ;
V_133 = F_53 ( V_59 -> V_145 ) ;
if ( V_133 == 0 )
return - V_71 ;
V_6 -> V_7 . V_375 = V_59 -> V_319 ;
V_6 -> V_7 . V_377 = V_59 -> V_323 ;
V_6 -> V_7 . V_7 = F_129 ;
V_6 -> V_7 . V_9 = F_131 ;
F_134 ( & V_6 -> V_7 . V_378 . V_199 , V_133 ) ;
return F_38 ( V_6 ) ;
}
static int F_135 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_124 = V_59 -> V_145 ;
bool V_380 = false ;
if ( V_59 -> V_73 == ( sizeof( * V_59 ) / sizeof( V_74 ) ) ) {
V_380 = true ;
if ( V_124 != 0 && V_124 != 1 )
return - V_71 ;
V_6 -> V_52 = V_124 ;
}
if ( V_380 && F_136 ( V_8 ) )
V_8 = F_137 ( V_8 , V_33 ) ;
else
V_8 = F_31 ( V_8 , V_33 ) ;
if ( V_380 && V_8 ) {
struct V_58 * V_381 = (struct V_58 * ) V_8 -> V_61 ;
V_381 -> V_63 = 0 ;
}
F_34 ( V_8 , V_33 , V_53 , NULL , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_138 ( struct V_382 * V_383 , int V_384 , int V_373 , void * V_374 )
{
int V_352 ;
T_6 V_269 = * ( T_6 * ) V_374 ;
for ( V_352 = 0 ; V_352 < V_383 -> V_385 ; V_352 ++ ) {
if ( V_383 -> V_386 [ V_352 ] . V_269 == V_269 )
return - V_364 ;
}
return 0 ;
}
static T_6 F_139 ( struct V_10 * V_10 )
{
struct V_387 V_388 ;
T_6 V_389 ;
int V_60 ;
static T_6 V_269 = V_390 ;
V_389 = V_269 ;
do {
++ V_269 ;
if ( V_269 == 0 )
V_269 = V_390 + 1 ;
F_140 ( & V_388 , V_391 ) ;
V_60 = V_387 ( V_10 , & V_388 , F_138 , ( void * ) & V_269 ) ;
F_141 ( & V_388 ) ;
if ( V_60 != - V_364 )
return V_269 ;
} while ( V_269 != V_389 );
return 0 ;
}
static int
F_142 ( struct V_382 * V_383 , struct V_392 * V_393 )
{
struct V_10 * V_10 = F_143 ( V_383 ) ;
struct V_394 * V_395 = V_383 -> V_386 + V_383 -> V_385 ;
int V_148 ;
if ( V_383 -> V_385 >= V_396 )
return - V_397 ;
if ( V_393 -> V_398 == 0 )
return - V_71 ;
V_395 -> V_194 . V_133 = V_393 -> V_399 ;
if ( ( V_148 = F_65 ( V_393 -> V_398 ) ) < 0 )
return - V_71 ;
V_395 -> V_148 = V_148 ;
if ( V_393 -> V_400 == V_401 )
V_395 -> V_402 = 1 ;
else if ( V_393 -> V_400 == V_403 ) {
V_395 -> V_269 = V_393 -> V_404 ;
if ( V_395 -> V_269 > V_390 )
V_395 -> V_269 = 0 ;
if ( ! V_395 -> V_269 && ! ( V_395 -> V_269 = F_139 ( V_10 ) ) )
return - V_44 ;
}
if ( V_395 -> V_148 == V_151 ) {
T_7 * V_135 = ( T_7 * ) ( V_393 + 1 ) ;
int V_134 , V_405 ;
V_134 = F_58 ( (struct V_78 * ) V_135 ,
& V_395 -> V_184 ) ;
if ( ! V_134 )
return - V_71 ;
V_405 = F_57 ( V_134 ) ;
if ( F_58 ( (struct V_78 * ) ( V_135 + V_405 ) ,
& V_395 -> V_194 . V_251 ) != V_134 )
return - V_71 ;
V_395 -> V_406 = V_134 ;
} else
V_395 -> V_406 = V_383 -> V_134 ;
V_395 -> V_407 = 1 ;
V_383 -> V_385 ++ ;
return 0 ;
}
static int
F_144 ( struct V_382 * V_383 , struct V_408 * V_409 )
{
int V_23 ;
int V_47 = V_409 -> V_410 * 8 - sizeof( struct V_408 ) ;
struct V_392 * V_393 = ( void * ) ( V_409 + 1 ) ;
if ( V_409 -> V_410 * 8 < sizeof( struct V_408 ) )
return - V_71 ;
while ( V_47 >= sizeof( struct V_392 ) ) {
if ( ( V_23 = F_142 ( V_383 , V_393 ) ) < 0 )
return V_23 ;
V_47 -= V_393 -> V_411 ;
V_393 = ( void * ) ( ( T_7 * ) V_393 + V_393 -> V_411 ) ;
}
return 0 ;
}
static inline int F_145 ( const struct V_382 * V_383 )
{
struct V_173 * V_174 = V_383 -> V_182 ;
if ( V_174 ) {
int V_47 = sizeof( struct V_89 ) ;
V_47 += V_174 -> V_103 ;
return F_63 ( V_47 ) ;
}
return 0 ;
}
static int F_146 ( const struct V_382 * V_383 )
{
const struct V_394 * V_395 ;
int V_178 = F_62 ( V_383 -> V_134 ) ;
int V_405 = 0 ;
int V_352 ;
for ( V_352 = 0 ; V_352 < V_383 -> V_385 ; V_352 ++ ) {
V_395 = V_383 -> V_386 + V_352 ;
V_405 += F_57 ( V_395 -> V_406 ) ;
}
return sizeof( struct V_58 ) +
( sizeof( struct V_167 ) * 3 ) +
( sizeof( struct V_76 ) * 2 ) +
( V_178 * 2 ) +
sizeof( struct V_408 ) +
( V_383 -> V_385 * sizeof( struct V_392 ) ) +
( V_405 * 2 ) +
F_145 ( V_383 ) ;
}
static struct V_41 * F_147 ( const struct V_382 * V_383 )
{
struct V_41 * V_8 ;
int V_175 ;
V_175 = F_146 ( V_383 ) ;
V_8 = F_41 ( V_175 + 16 , V_64 ) ;
if ( V_8 == NULL )
return F_68 ( - V_44 ) ;
return V_8 ;
}
static int F_148 ( struct V_41 * V_8 , const struct V_382 * V_383 , int V_384 )
{
struct V_58 * V_59 ;
struct V_76 * V_79 ;
struct V_167 * V_168 ;
struct V_408 * V_409 ;
struct V_89 * V_90 ;
struct V_173 * V_174 ;
int V_352 ;
int V_175 ;
int V_178 = F_62 ( V_383 -> V_134 ) ;
int V_405 = F_57 ( V_383 -> V_134 ) ;
V_175 = F_146 ( V_383 ) ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
memset ( V_59 , 0 , V_175 ) ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_178 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_178 ) /
sizeof( V_74 ) ;
V_79 -> V_248 = V_119 ;
V_79 -> V_249 = F_56 ( V_383 -> V_412 . V_133 ) ;
V_79 -> V_87 = V_383 -> V_412 . V_252 ;
V_79 -> V_250 = 0 ;
if ( ! F_66 ( & V_383 -> V_412 . V_184 ,
V_383 -> V_412 . V_253 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_383 -> V_134 ) )
F_74 () ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_178 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_178 ) /
sizeof( V_74 ) ;
V_79 -> V_248 = V_120 ;
V_79 -> V_249 = F_56 ( V_383 -> V_412 . V_133 ) ;
V_79 -> V_87 = V_383 -> V_412 . V_413 ;
V_79 -> V_250 = 0 ;
F_66 ( & V_383 -> V_412 . V_251 , V_383 -> V_412 . V_414 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_383 -> V_134 ) ;
V_168 = (struct V_167 * ) F_43 ( V_8 ,
sizeof( struct V_167 ) ) ;
V_168 -> V_225 =
sizeof( struct V_167 ) / sizeof( V_74 ) ;
V_168 -> V_226 = V_227 ;
V_168 -> V_228 = F_73 ( V_383 -> V_229 . V_230 ) ;
V_168 -> V_231 = F_73 ( V_383 -> V_229 . V_232 ) ;
V_168 -> V_233 = V_383 -> V_229 . V_234 ;
V_168 -> V_235 = V_383 -> V_229 . V_236 ;
V_168 = (struct V_167 * ) F_43 ( V_8 ,
sizeof( struct V_167 ) ) ;
V_168 -> V_225 =
sizeof( struct V_167 ) / sizeof( V_74 ) ;
V_168 -> V_226 = V_237 ;
V_168 -> V_228 = F_73 ( V_383 -> V_229 . V_238 ) ;
V_168 -> V_231 = F_73 ( V_383 -> V_229 . V_239 ) ;
V_168 -> V_233 = V_383 -> V_229 . V_240 ;
V_168 -> V_235 = V_383 -> V_229 . V_241 ;
V_168 = (struct V_167 * ) F_43 ( V_8 ,
sizeof( struct V_167 ) ) ;
V_168 -> V_225 =
sizeof( struct V_167 ) / sizeof( V_74 ) ;
V_168 -> V_226 = V_242 ;
V_168 -> V_228 = V_383 -> V_243 . V_244 ;
V_168 -> V_231 = V_383 -> V_243 . V_245 ;
V_168 -> V_233 = V_383 -> V_243 . V_246 ;
V_168 -> V_235 = V_383 -> V_243 . V_247 ;
V_409 = (struct V_408 * ) F_43 ( V_8 , sizeof( struct V_408 ) ) ;
V_409 -> V_410 = sizeof( struct V_408 ) / sizeof( V_74 ) ;
V_409 -> V_415 = V_416 ;
V_409 -> V_417 = V_418 ;
if ( V_383 -> V_419 == V_420 ) {
if ( V_383 -> V_385 )
V_409 -> V_417 = V_421 ;
else
V_409 -> V_417 = V_422 ;
}
V_409 -> V_423 = V_384 + 1 ;
V_409 -> V_424 = V_383 -> V_425 ;
V_409 -> V_426 = V_383 -> V_427 ;
for ( V_352 = 0 ; V_352 < V_383 -> V_385 ; V_352 ++ ) {
const struct V_394 * V_395 = V_383 -> V_386 + V_352 ;
struct V_392 * V_393 ;
int V_428 ;
int V_148 ;
V_428 = sizeof( struct V_392 ) ;
if ( V_395 -> V_148 == V_151 ) {
V_405 = F_57 ( V_395 -> V_406 ) ;
V_428 += V_405 * 2 ;
} else {
V_175 -= 2 * V_405 ;
}
V_393 = ( void * ) F_43 ( V_8 , V_428 ) ;
V_409 -> V_410 += V_428 / 8 ;
memset ( V_393 , 0 , sizeof( * V_393 ) ) ;
V_393 -> V_411 = V_428 ;
V_393 -> V_399 = V_395 -> V_194 . V_133 ;
if ( ( V_148 = F_64 ( V_395 -> V_148 ) ) < 0 )
return - V_71 ;
V_393 -> V_398 = V_148 ;
V_393 -> V_400 = V_429 ;
if ( V_395 -> V_269 )
V_393 -> V_400 = V_403 ;
if ( V_395 -> V_402 )
V_393 -> V_400 = V_401 ;
V_393 -> V_404 = V_395 -> V_269 ;
if ( V_395 -> V_148 == V_151 ) {
T_7 * V_135 = ( void * ) ( V_393 + 1 ) ;
F_66 ( & V_395 -> V_184 , 0 ,
(struct V_78 * ) V_135 ,
V_395 -> V_406 ) ;
F_66 ( & V_395 -> V_194 . V_251 , 0 ,
(struct V_78 * ) ( V_135 + V_405 ) ,
V_395 -> V_406 ) ;
}
}
if ( ( V_174 = V_383 -> V_182 ) ) {
int V_96 = F_145 ( V_383 ) ;
V_90 = (struct V_89 * ) F_43 ( V_8 , V_96 ) ;
V_90 -> V_93 = V_96 / sizeof( V_74 ) ;
V_90 -> V_98 = V_123 ;
V_90 -> V_100 = V_174 -> V_99 ;
V_90 -> V_102 = V_174 -> V_101 ;
V_90 -> V_91 = V_174 -> V_103 ;
memcpy ( V_90 + 1 , V_174 -> V_285 ,
V_174 -> V_103 ) ;
}
V_59 -> V_73 = V_175 / sizeof( V_74 ) ;
V_59 -> V_322 = F_3 ( & V_383 -> V_430 ) ;
return 0 ;
}
static int F_149 ( struct V_382 * V_383 , int V_384 , const struct V_344 * V_345 )
{
struct V_41 * V_348 ;
struct V_58 * V_307 ;
int V_23 ;
V_348 = F_147 ( V_383 ) ;
if ( F_92 ( V_348 ) )
return F_93 ( V_348 ) ;
V_23 = F_148 ( V_348 , V_383 , V_384 ) ;
if ( V_23 < 0 )
return V_23 ;
V_307 = (struct V_58 * ) V_348 -> V_61 ;
V_307 -> V_319 = V_29 ;
if ( V_345 -> V_61 . V_431 && V_345 -> V_328 == V_329 )
V_307 -> V_320 = V_432 ;
else
V_307 -> V_320 = F_98 ( V_345 -> V_328 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_62 = V_345 -> V_303 ;
V_307 -> V_323 = V_345 -> V_346 ;
F_34 ( V_348 , V_64 , V_53 , NULL , F_143 ( V_383 ) ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 = 0 ;
struct V_167 * V_168 ;
struct V_76 * V_135 ;
struct V_408 * V_409 ;
struct V_382 * V_383 ;
struct V_344 V_345 ;
struct V_89 * V_90 ;
if ( ! F_51 ( V_108 [ V_119 - 1 ] ,
V_108 [ V_120 - 1 ] ) ||
! V_108 [ V_416 - 1 ] )
return - V_71 ;
V_409 = V_108 [ V_416 - 1 ] ;
if ( V_409 -> V_417 > V_421 )
return - V_71 ;
if ( ! V_409 -> V_423 || V_409 -> V_423 >= V_433 )
return - V_71 ;
V_383 = F_151 ( V_10 , V_33 ) ;
if ( V_383 == NULL )
return - V_44 ;
V_383 -> V_419 = ( V_409 -> V_417 == V_418 ?
V_434 : V_420 ) ;
V_383 -> V_427 = V_409 -> V_426 ;
V_135 = V_108 [ V_119 - 1 ] ;
V_383 -> V_134 = F_59 ( V_135 , & V_383 -> V_412 . V_184 ) ;
if ( ! V_383 -> V_134 ) {
V_23 = - V_71 ;
goto V_35;
}
V_383 -> V_412 . V_134 = V_383 -> V_134 ;
V_383 -> V_412 . V_252 = V_135 -> V_87 ;
V_383 -> V_412 . V_133 = F_55 ( V_135 -> V_249 ) ;
V_383 -> V_412 . V_253 = ( (struct V_80 * ) ( V_135 + 1 ) ) -> V_158 ;
if ( V_383 -> V_412 . V_253 )
V_383 -> V_412 . V_435 = F_152 ( 0xffff ) ;
V_135 = V_108 [ V_120 - 1 ] ;
F_59 ( V_135 , & V_383 -> V_412 . V_251 ) ;
V_383 -> V_412 . V_413 = V_135 -> V_87 ;
V_383 -> V_412 . V_133 = F_55 ( V_135 -> V_249 ) ;
V_383 -> V_412 . V_414 = ( (struct V_80 * ) ( V_135 + 1 ) ) -> V_158 ;
if ( V_383 -> V_412 . V_414 )
V_383 -> V_412 . V_436 = F_152 ( 0xffff ) ;
V_90 = V_108 [ V_123 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_95 = F_49 ( V_90 ) ;
if ( ! V_95 ) {
V_23 = - V_44 ;
goto V_35;
}
V_23 = F_153 ( & V_383 -> V_182 , V_95 ) ;
F_81 ( V_95 ) ;
if ( V_23 )
goto V_35;
}
V_383 -> V_229 . V_239 = V_437 ;
V_383 -> V_229 . V_232 = V_437 ;
V_383 -> V_229 . V_238 = V_437 ;
V_383 -> V_229 . V_230 = V_437 ;
if ( ( V_168 = V_108 [ V_227 - 1 ] ) != NULL ) {
V_383 -> V_229 . V_230 = F_79 ( V_168 -> V_228 ) ;
V_383 -> V_229 . V_232 = F_79 ( V_168 -> V_231 ) ;
V_383 -> V_229 . V_234 = V_168 -> V_233 ;
V_383 -> V_229 . V_236 = V_168 -> V_235 ;
}
if ( ( V_168 = V_108 [ V_237 - 1 ] ) != NULL ) {
V_383 -> V_229 . V_238 = F_79 ( V_168 -> V_228 ) ;
V_383 -> V_229 . V_239 = F_79 ( V_168 -> V_231 ) ;
V_383 -> V_229 . V_240 = V_168 -> V_233 ;
V_383 -> V_229 . V_241 = V_168 -> V_235 ;
}
V_383 -> V_385 = 0 ;
if ( V_409 -> V_417 == V_421 &&
( V_23 = F_144 ( V_383 , V_409 ) ) < 0 )
goto V_35;
V_23 = F_154 ( V_409 -> V_423 - 1 , V_383 ,
V_59 -> V_320 != V_334 ) ;
F_155 ( V_383 , V_23 ? 0 : 1 ,
F_107 ( V_347 ) ,
F_108 ( V_347 ) , 0 ) ;
if ( V_23 )
goto V_35;
if ( V_59 -> V_320 == V_334 )
V_345 . V_328 = V_333 ;
else
V_345 . V_328 = V_331 ;
V_345 . V_303 = V_59 -> V_62 ;
V_345 . V_346 = V_59 -> V_323 ;
F_156 ( V_383 , V_409 -> V_423 - 1 , & V_345 ) ;
F_157 ( V_383 ) ;
return 0 ;
V_35:
V_383 -> V_388 . V_438 = 1 ;
F_158 ( V_383 ) ;
return V_23 ;
}
static int F_159 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 ;
struct V_76 * V_135 ;
struct V_408 * V_409 ;
struct V_382 * V_383 ;
struct V_439 V_183 ;
struct V_344 V_345 ;
struct V_89 * V_90 ;
struct V_173 * V_440 = NULL ;
if ( ! F_51 ( V_108 [ V_119 - 1 ] ,
V_108 [ V_120 - 1 ] ) ||
! V_108 [ V_416 - 1 ] )
return - V_71 ;
V_409 = V_108 [ V_416 - 1 ] ;
if ( ! V_409 -> V_423 || V_409 -> V_423 >= V_433 )
return - V_71 ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
V_135 = V_108 [ V_119 - 1 ] ;
V_183 . V_134 = F_59 ( V_135 , & V_183 . V_184 ) ;
V_183 . V_252 = V_135 -> V_87 ;
V_183 . V_133 = F_55 ( V_135 -> V_249 ) ;
V_183 . V_253 = ( (struct V_80 * ) ( V_135 + 1 ) ) -> V_158 ;
if ( V_183 . V_253 )
V_183 . V_435 = F_152 ( 0xffff ) ;
V_135 = V_108 [ V_120 - 1 ] ;
F_59 ( V_135 , & V_183 . V_251 ) ;
V_183 . V_413 = V_135 -> V_87 ;
V_183 . V_133 = F_55 ( V_135 -> V_249 ) ;
V_183 . V_414 = ( (struct V_80 * ) ( V_135 + 1 ) ) -> V_158 ;
if ( V_183 . V_414 )
V_183 . V_436 = F_152 ( 0xffff ) ;
V_90 = V_108 [ V_123 - 1 ] ;
if ( V_90 != NULL ) {
struct V_94 * V_95 = F_49 ( V_90 ) ;
if ( ! V_95 )
return - V_31 ;
V_23 = F_153 ( & V_440 , V_95 ) ;
F_81 ( V_95 ) ;
if ( V_23 )
return V_23 ;
}
V_383 = F_160 ( V_10 , V_146 , V_391 ,
V_409 -> V_423 - 1 , & V_183 , V_440 ,
1 , & V_23 ) ;
F_161 ( V_440 ) ;
if ( V_383 == NULL )
return - V_315 ;
F_162 ( V_383 , V_23 ? 0 : 1 ,
F_107 ( V_347 ) ,
F_108 ( V_347 ) , 0 ) ;
if ( V_23 )
goto V_35;
V_345 . V_303 = V_59 -> V_62 ;
V_345 . V_346 = V_59 -> V_323 ;
V_345 . V_61 . V_431 = 0 ;
V_345 . V_328 = V_329 ;
F_156 ( V_383 , V_409 -> V_423 - 1 , & V_345 ) ;
V_35:
F_157 ( V_383 ) ;
if ( V_23 == 0 )
F_163 ( V_10 ) ;
return V_23 ;
}
static int F_164 ( struct V_2 * V_3 , struct V_382 * V_383 , const struct V_58 * V_59 , int V_384 )
{
int V_23 ;
struct V_41 * V_348 ;
struct V_58 * V_307 ;
V_23 = 0 ;
V_348 = F_147 ( V_383 ) ;
if ( F_92 ( V_348 ) ) {
V_23 = F_93 ( V_348 ) ;
goto V_35;
}
V_23 = F_148 ( V_348 , V_383 , V_384 ) ;
if ( V_23 < 0 )
goto V_35;
V_307 = (struct V_58 * ) V_348 -> V_61 ;
V_307 -> V_319 = V_59 -> V_319 ;
V_307 -> V_320 = V_59 -> V_320 ;
V_307 -> V_145 = 0 ;
V_307 -> V_63 = 0 ;
V_307 -> V_62 = V_59 -> V_62 ;
V_307 -> V_323 = V_59 -> V_323 ;
F_34 ( V_348 , V_64 , V_57 , V_3 , F_143 ( V_383 ) ) ;
V_23 = 0 ;
V_35:
return V_23 ;
}
static int F_165 ( T_3 V_134 )
{
return F_63 ( F_57 ( V_134 ) * 2 ) ;
}
static int F_166 ( struct V_78 * V_135 , int V_112 ,
T_4 * V_184 , T_4 * V_251 ,
T_9 * V_134 )
{
int V_441 , V_405 ;
if ( V_112 < F_165 ( V_135 -> V_84 ) )
return - V_71 ;
V_441 = F_58 ( V_135 , V_184 ) ;
if ( ! V_441 )
return - V_71 ;
V_405 = F_57 ( V_441 ) ;
if ( F_58 ( (struct V_78 * ) ( ( ( T_7 * ) V_135 ) + V_405 ) ,
V_251 ) != V_441 )
return - V_71 ;
* V_134 = V_441 ;
return 0 ;
}
static int F_167 ( struct V_392 * V_442 , int V_47 ,
struct V_443 * V_444 )
{
int V_23 ;
struct V_392 * V_445 ;
int V_148 ;
if ( V_47 <= sizeof( struct V_392 ) ||
V_47 < V_442 -> V_411 )
return - V_71 ;
V_23 = F_166 ( (struct V_78 * ) ( V_442 + 1 ) ,
V_442 -> V_411 ,
& V_444 -> V_446 , & V_444 -> V_447 ,
& V_444 -> V_448 ) ;
if ( V_23 )
return V_23 ;
V_445 = (struct V_392 * ) ( ( T_7 * ) V_442 + V_442 -> V_411 ) ;
V_47 -= V_442 -> V_411 ;
if ( V_47 <= sizeof( struct V_392 ) ||
V_47 < V_445 -> V_411 )
return - V_71 ;
V_23 = F_166 ( (struct V_78 * ) ( V_445 + 1 ) ,
V_445 -> V_411 ,
& V_444 -> V_449 , & V_444 -> V_450 ,
& V_444 -> V_451 ) ;
if ( V_23 )
return V_23 ;
if ( V_442 -> V_399 != V_445 -> V_399 ||
V_442 -> V_398 != V_445 -> V_398 ||
V_442 -> V_404 != V_445 -> V_404 )
return - V_71 ;
V_444 -> V_133 = V_442 -> V_399 ;
if ( ( V_148 = F_65 ( V_442 -> V_398 ) ) < 0 )
return - V_71 ;
V_444 -> V_148 = V_148 ;
V_444 -> V_269 = V_442 -> V_404 ;
return ( ( int ) ( V_442 -> V_411 +
V_445 -> V_411 ) ) ;
}
static int F_168 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_58 * V_59 , void * const * V_108 )
{
int V_352 , V_47 , V_452 , V_23 = - V_71 ;
T_7 V_384 ;
struct V_76 * V_135 ;
struct V_453 * V_454 ;
struct V_408 * V_409 ;
struct V_392 * V_393 ;
struct V_439 V_183 ;
struct V_443 V_444 [ V_396 ] ;
struct V_455 V_456 ;
if ( ! F_51 ( V_108 [ V_119 - 1 ] ,
V_108 [ V_120 - 1 ] ) ||
! V_108 [ V_416 - 1 ] ) {
V_23 = - V_71 ;
goto V_35;
}
V_454 = V_108 [ V_457 - 1 ] ;
V_409 = V_108 [ V_416 - 1 ] ;
if ( V_409 -> V_423 >= V_433 ) {
V_23 = - V_71 ;
goto V_35;
}
if ( V_454 ) {
V_456 . V_458 = V_454 -> V_459 ;
V_452 = F_166 ( (struct V_78 * ) ( V_454 + 1 ) ,
8 * ( V_454 -> V_460 ) - sizeof( * V_454 ) ,
& V_456 . V_461 , & V_456 . V_462 , & V_456 . V_134 ) ;
if ( V_452 < 0 ) {
V_23 = V_452 ;
goto V_35;
}
}
V_384 = V_409 -> V_423 - 1 ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
V_135 = V_108 [ V_119 - 1 ] ;
V_183 . V_134 = F_59 ( V_135 , & V_183 . V_184 ) ;
V_183 . V_252 = V_135 -> V_87 ;
V_183 . V_133 = F_55 ( V_135 -> V_249 ) ;
V_183 . V_253 = ( (struct V_80 * ) ( V_135 + 1 ) ) -> V_158 ;
if ( V_183 . V_253 )
V_183 . V_435 = F_152 ( 0xffff ) ;
V_135 = V_108 [ V_120 - 1 ] ,
F_59 ( V_135 , & V_183 . V_251 ) ;
V_183 . V_413 = V_135 -> V_87 ;
V_183 . V_133 = F_55 ( V_135 -> V_249 ) ;
V_183 . V_414 = ( (struct V_80 * ) ( V_135 + 1 ) ) -> V_158 ;
if ( V_183 . V_414 )
V_183 . V_436 = F_152 ( 0xffff ) ;
V_393 = (struct V_392 * ) ( V_409 + 1 ) ;
V_352 = 0 ;
V_47 = V_409 -> V_410 * 8 - sizeof( struct V_408 ) ;
while ( V_47 > 0 && V_352 < V_396 ) {
V_452 = F_167 ( V_393 , V_47 , & V_444 [ V_352 ] ) ;
if ( V_452 < 0 ) {
V_23 = V_452 ;
goto V_35;
} else {
V_393 = (struct V_392 * ) ( ( T_7 * ) V_393 + V_452 ) ;
V_47 -= V_452 ;
V_352 ++ ;
}
}
if ( ! V_352 || V_47 > 0 ) {
V_23 = - V_71 ;
goto V_35;
}
return V_443 ( & V_183 , V_384 , V_391 , V_444 , V_352 ,
V_454 ? & V_456 : NULL ) ;
V_35:
return V_23 ;
}
static int F_168 ( struct V_2 * V_3 , struct V_41 * V_8 ,
const struct V_58 * V_59 , void * const * V_108 )
{
return - V_463 ;
}
static int F_169 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_384 ;
int V_23 = 0 , V_464 ;
struct V_408 * V_409 ;
struct V_382 * V_383 ;
struct V_344 V_345 ;
if ( ( V_409 = V_108 [ V_416 - 1 ] ) == NULL )
return - V_71 ;
V_384 = F_170 ( V_409 -> V_424 ) ;
if ( V_384 >= V_465 )
return - V_71 ;
V_464 = ( V_59 -> V_320 == V_432 ) ;
V_383 = F_171 ( V_10 , V_146 , V_391 ,
V_384 , V_409 -> V_424 , V_464 , & V_23 ) ;
if ( V_383 == NULL )
return - V_315 ;
if ( V_464 ) {
F_162 ( V_383 , V_23 ? 0 : 1 ,
F_107 ( V_347 ) ,
F_108 ( V_347 ) , 0 ) ;
if ( V_23 )
goto V_35;
V_345 . V_303 = V_59 -> V_62 ;
V_345 . V_346 = V_59 -> V_323 ;
V_345 . V_61 . V_431 = 1 ;
V_345 . V_328 = V_329 ;
F_156 ( V_383 , V_384 , & V_345 ) ;
} else {
V_23 = F_164 ( V_3 , V_383 , V_59 , V_384 ) ;
}
V_35:
F_157 ( V_383 ) ;
if ( V_464 && V_23 == 0 )
F_163 ( V_10 ) ;
return V_23 ;
}
static int F_172 ( struct V_382 * V_383 , int V_384 , int V_373 , void * V_374 )
{
struct V_1 * V_6 = V_374 ;
struct V_41 * V_348 ;
struct V_58 * V_307 ;
int V_23 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_44 ;
V_348 = F_147 ( V_383 ) ;
if ( F_92 ( V_348 ) )
return F_93 ( V_348 ) ;
V_23 = F_148 ( V_348 , V_383 , V_384 ) ;
if ( V_23 < 0 )
return V_23 ;
V_307 = (struct V_58 * ) V_348 -> V_61 ;
V_307 -> V_319 = V_6 -> V_7 . V_375 ;
V_307 -> V_320 = V_466 ;
V_307 -> V_145 = V_125 ;
V_307 -> V_63 = 0 ;
V_307 -> V_62 = V_373 + 1 ;
V_307 -> V_323 = V_6 -> V_7 . V_377 ;
if ( V_6 -> V_7 . V_8 )
F_34 ( V_6 -> V_7 . V_8 , V_64 , V_57 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_348 ;
return 0 ;
}
static int F_173 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return V_387 ( V_10 , & V_6 -> V_7 . V_378 . V_467 , F_172 , ( void * ) V_6 ) ;
}
static void F_174 ( struct V_1 * V_6 )
{
F_141 ( & V_6 -> V_7 . V_378 . V_467 ) ;
}
static int F_175 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_379 ;
V_6 -> V_7 . V_375 = V_59 -> V_319 ;
V_6 -> V_7 . V_377 = V_59 -> V_323 ;
V_6 -> V_7 . V_7 = F_173 ;
V_6 -> V_7 . V_9 = F_174 ;
F_140 ( & V_6 -> V_7 . V_378 . V_467 , V_391 ) ;
return F_38 ( V_6 ) ;
}
static int F_176 ( const struct V_344 * V_345 )
{
struct V_41 * V_468 ;
struct V_58 * V_59 ;
V_468 = F_41 ( sizeof( struct V_58 ) + 16 , V_64 ) ;
if ( ! V_468 )
return - V_44 ;
V_59 = (struct V_58 * ) F_43 ( V_468 , sizeof( struct V_58 ) ) ;
V_59 -> V_320 = V_469 ;
V_59 -> V_62 = V_345 -> V_303 ;
V_59 -> V_323 = V_345 -> V_346 ;
V_59 -> V_319 = V_29 ;
V_59 -> V_63 = ( V_72 ) 0 ;
V_59 -> V_145 = V_125 ;
V_59 -> V_73 = ( sizeof( struct V_58 ) / sizeof( V_74 ) ) ;
V_59 -> V_322 = 0 ;
F_34 ( V_468 , V_64 , V_53 , NULL , V_345 -> V_10 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 , void * const * V_108 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_344 V_345 ;
struct V_367 V_368 ;
int V_23 , V_51 ;
V_368 . V_369 = F_107 ( V_347 ) ;
V_368 . V_370 = F_108 ( V_347 ) ;
V_368 . V_371 = 0 ;
V_23 = F_178 ( V_10 , V_391 , & V_368 ) ;
V_51 = F_124 ( V_3 , V_59 ) ;
if ( V_23 || V_51 ) {
if ( V_23 == - V_50 )
return 0 ;
return V_23 ;
}
V_345 . V_61 . type = V_391 ;
V_345 . V_328 = V_470 ;
V_345 . V_346 = V_59 -> V_323 ;
V_345 . V_303 = V_59 -> V_62 ;
V_345 . V_10 = V_10 ;
F_156 ( NULL , 0 , & V_345 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_3 , struct V_41 * V_8 , const struct V_58 * V_59 )
{
void * V_108 [ V_116 ] ;
int V_23 ;
F_34 ( F_31 ( V_8 , V_33 ) , V_33 ,
V_54 , NULL , F_7 ( V_3 ) ) ;
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
V_23 = F_52 ( V_8 , V_59 , V_108 ) ;
if ( ! V_23 ) {
V_23 = - V_305 ;
if ( V_471 [ V_59 -> V_320 ] )
V_23 = V_471 [ V_59 -> V_320 ] ( V_3 , V_8 , V_59 , V_108 ) ;
}
return V_23 ;
}
static struct V_58 * F_180 ( struct V_41 * V_8 , int * V_472 )
{
struct V_58 * V_59 = NULL ;
if ( V_8 -> V_47 < sizeof( * V_59 ) ) {
* V_472 = - V_473 ;
} else {
V_59 = (struct V_58 * ) V_8 -> V_61 ;
if ( V_59 -> V_319 != V_29 ||
V_59 -> V_322 != 0 ||
( V_59 -> V_320 <= V_474 ||
V_59 -> V_320 > V_475 ) ) {
V_59 = NULL ;
* V_472 = - V_71 ;
} else if ( V_59 -> V_73 != ( V_8 -> V_47 /
sizeof( V_74 ) ) ||
V_59 -> V_73 < ( sizeof( struct V_58 ) /
sizeof( V_74 ) ) ) {
V_59 = NULL ;
* V_472 = - V_473 ;
} else {
* V_472 = 0 ;
}
}
return V_59 ;
}
static inline int F_181 ( const struct V_394 * V_395 ,
const struct V_209 * V_476 )
{
unsigned int V_194 = V_476 -> V_213 . V_214 ;
if ( V_194 >= sizeof( V_395 -> V_477 ) * 8 )
return 0 ;
return ( V_395 -> V_477 >> V_194 ) & 1 ;
}
static inline int F_182 ( const struct V_394 * V_395 ,
const struct V_209 * V_476 )
{
unsigned int V_194 = V_476 -> V_213 . V_214 ;
if ( V_194 >= sizeof( V_395 -> V_478 ) * 8 )
return 0 ;
return ( V_395 -> V_478 >> V_194 ) & 1 ;
}
static int F_183 ( const struct V_394 * V_395 )
{
int V_352 , V_479 = 0 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_209 * V_185 = F_120 ( V_352 ) ;
if ( ! V_185 )
break;
if ( ! V_185 -> V_212 )
continue;
if ( F_181 ( V_395 , V_185 ) && V_185 -> V_360 )
V_479 += sizeof( struct V_480 ) ;
}
return V_479 + sizeof( struct V_481 ) ;
}
static int F_184 ( const struct V_394 * V_395 )
{
int V_352 , V_456 , V_479 = 0 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_209 * V_187 = F_121 ( V_352 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_212 )
continue;
if ( ! ( F_182 ( V_395 , V_187 ) && V_187 -> V_360 ) )
continue;
for ( V_456 = 1 ; ; V_456 ++ ) {
const struct V_209 * V_185 = F_120 ( V_456 ) ;
if ( ! V_185 )
break;
if ( ! V_185 -> V_212 )
continue;
if ( F_181 ( V_395 , V_185 ) && V_185 -> V_360 )
V_479 += sizeof( struct V_480 ) ;
}
}
return V_479 + sizeof( struct V_481 ) ;
}
static void F_185 ( struct V_41 * V_8 , const struct V_394 * V_395 )
{
struct V_481 * V_75 ;
int V_352 ;
V_75 = (struct V_481 * ) F_43 ( V_8 , sizeof( struct V_481 ) ) ;
V_75 -> V_482 = sizeof( struct V_481 ) / 8 ;
V_75 -> V_483 = V_484 ;
V_75 -> V_485 = 32 ;
memset ( V_75 -> V_486 , 0 , sizeof( V_75 -> V_486 ) ) ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_209 * V_185 = F_120 ( V_352 ) ;
if ( ! V_185 )
break;
if ( ! V_185 -> V_212 )
continue;
if ( F_181 ( V_395 , V_185 ) && V_185 -> V_360 ) {
struct V_480 * V_345 ;
V_345 = (struct V_480 * ) F_43 ( V_8 , sizeof( struct V_480 ) ) ;
memset ( V_345 , 0 , sizeof( * V_345 ) ) ;
V_75 -> V_482 += sizeof( struct V_480 ) / 8 ;
V_345 -> V_487 = V_185 -> V_213 . V_214 ;
V_345 -> V_488 = V_185 -> V_213 . V_489 ;
V_345 -> V_490 = V_185 -> V_213 . V_491 ;
V_345 -> V_492 = 24 * 60 * 60 ;
V_345 -> V_493 = 20 * 60 * 60 ;
V_345 -> V_494 = 8 * 60 * 60 ;
V_345 -> V_495 = 7 * 60 * 60 ;
}
}
}
static void F_186 ( struct V_41 * V_8 , const struct V_394 * V_395 )
{
struct V_481 * V_75 ;
int V_352 , V_456 ;
V_75 = (struct V_481 * ) F_43 ( V_8 , sizeof( struct V_481 ) ) ;
V_75 -> V_482 = sizeof( struct V_481 ) / 8 ;
V_75 -> V_483 = V_484 ;
V_75 -> V_485 = 32 ;
memset ( V_75 -> V_486 , 0 , sizeof( V_75 -> V_486 ) ) ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_209 * V_187 = F_121 ( V_352 ) ;
if ( ! V_187 )
break;
if ( ! V_187 -> V_212 )
continue;
if ( ! ( F_182 ( V_395 , V_187 ) && V_187 -> V_360 ) )
continue;
for ( V_456 = 1 ; ; V_456 ++ ) {
struct V_480 * V_345 ;
const struct V_209 * V_185 = F_120 ( V_456 ) ;
if ( ! V_185 )
break;
if ( ! V_185 -> V_212 )
continue;
if ( ! ( F_181 ( V_395 , V_185 ) && V_185 -> V_360 ) )
continue;
V_345 = (struct V_480 * ) F_43 ( V_8 , sizeof( struct V_480 ) ) ;
memset ( V_345 , 0 , sizeof( * V_345 ) ) ;
V_75 -> V_482 += sizeof( struct V_480 ) / 8 ;
V_345 -> V_487 = V_185 -> V_213 . V_214 ;
V_345 -> V_488 = V_185 -> V_213 . V_489 ;
V_345 -> V_490 = V_185 -> V_213 . V_491 ;
V_345 -> V_496 = V_187 -> V_213 . V_214 ;
V_345 -> V_497 = V_187 -> V_213 . V_489 ;
V_345 -> V_498 = V_187 -> V_213 . V_491 ;
V_345 -> V_492 = 24 * 60 * 60 ;
V_345 -> V_493 = 20 * 60 * 60 ;
V_345 -> V_494 = 8 * 60 * 60 ;
V_345 -> V_495 = 7 * 60 * 60 ;
}
}
}
static int F_187 ( struct V_382 * V_383 , const struct V_344 * V_345 )
{
return 0 ;
}
static int F_188 ( struct V_142 * V_164 , const struct V_344 * V_345 )
{
struct V_41 * V_348 ;
struct V_58 * V_307 ;
int V_499 ;
int V_166 ;
V_499 = V_345 -> V_61 . V_499 ;
if ( V_499 )
V_166 = 2 ;
else
V_166 = 1 ;
V_348 = F_76 ( V_164 , V_166 ) ;
if ( F_92 ( V_348 ) )
return F_93 ( V_348 ) ;
V_307 = (struct V_58 * ) V_348 -> V_61 ;
V_307 -> V_319 = V_29 ;
V_307 -> V_320 = V_343 ;
V_307 -> V_145 = F_54 ( V_164 -> V_194 . V_133 ) ;
V_307 -> V_63 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_62 = 0 ;
V_307 -> V_323 = 0 ;
F_34 ( V_348 , V_64 , V_55 , NULL , F_101 ( V_164 ) ) ;
return 0 ;
}
static int F_189 ( struct V_142 * V_164 , const struct V_344 * V_345 )
{
struct V_10 * V_10 = V_164 ? F_101 ( V_164 ) : V_345 -> V_10 ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
if ( F_3 ( & V_12 -> V_17 ) == 0 )
return 0 ;
switch ( V_345 -> V_328 ) {
case V_342 :
return F_188 ( V_164 , V_345 ) ;
case V_336 :
case V_338 :
case V_340 :
return F_100 ( V_164 , V_345 ) ;
case V_372 :
return F_125 ( V_345 ) ;
case V_500 :
break;
default:
F_11 ( L_3 , V_345 -> V_328 ) ;
break;
}
return 0 ;
}
static int F_190 ( struct V_382 * V_383 , int V_384 , const struct V_344 * V_345 )
{
if ( V_383 && V_383 -> type != V_391 )
return 0 ;
switch ( V_345 -> V_328 ) {
case V_335 :
return F_187 ( V_383 , V_345 ) ;
case V_329 :
case V_331 :
case V_333 :
return F_149 ( V_383 , V_384 , V_345 ) ;
case V_470 :
if ( V_345 -> V_61 . type != V_391 )
break;
return F_176 ( V_345 ) ;
default:
F_11 ( L_2 , V_345 -> V_328 ) ;
break;
}
return 0 ;
}
static T_6 F_191 ( void )
{
T_6 V_501 ;
static T_10 V_502 ;
do {
V_501 = F_192 ( & V_502 ) ;
} while ( ! V_501 );
return V_501 ;
}
static int F_193 ( struct V_142 * V_164 , struct V_394 * V_395 , struct V_382 * V_383 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
struct V_76 * V_79 ;
struct V_408 * V_409 ;
int V_178 ;
int V_175 ;
struct V_89 * V_90 ;
struct V_173 * V_174 ;
int V_96 = 0 ;
V_178 = F_62 ( V_164 -> V_181 . V_134 ) ;
if ( ! V_178 )
return - V_71 ;
V_175 = sizeof( struct V_58 ) +
( sizeof( struct V_76 ) * 2 ) +
( V_178 * 2 ) +
sizeof( struct V_408 ) ;
if ( V_164 -> V_194 . V_133 == V_128 )
V_175 += F_183 ( V_395 ) ;
else if ( V_164 -> V_194 . V_133 == V_130 )
V_175 += F_184 ( V_395 ) ;
if ( ( V_174 = V_164 -> V_182 ) ) {
V_96 = F_63 ( V_174 -> V_103 ) ;
V_175 += sizeof( struct V_89 ) + V_96 ;
}
V_8 = F_41 ( V_175 + 16 , V_64 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_319 = V_29 ;
V_59 -> V_320 = V_503 ;
V_59 -> V_145 = F_54 ( V_164 -> V_194 . V_133 ) ;
V_59 -> V_73 = V_175 / sizeof( V_74 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_322 = 0 ;
V_59 -> V_62 = V_164 -> V_198 . V_303 = F_191 () ;
V_59 -> V_323 = 0 ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_178 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_178 ) /
sizeof( V_74 ) ;
V_79 -> V_248 = V_119 ;
V_79 -> V_249 = 0 ;
V_79 -> V_250 = 0 ;
V_79 -> V_87 =
F_66 ( & V_164 -> V_181 . V_184 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_164 -> V_181 . V_134 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_79 = (struct V_76 * ) F_43 ( V_8 ,
sizeof( struct V_76 ) + V_178 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_178 ) /
sizeof( V_74 ) ;
V_79 -> V_248 = V_120 ;
V_79 -> V_249 = 0 ;
V_79 -> V_250 = 0 ;
V_79 -> V_87 =
F_66 ( & V_164 -> V_194 . V_251 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_164 -> V_181 . V_134 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_409 = (struct V_408 * ) F_43 ( V_8 , sizeof( struct V_408 ) ) ;
V_409 -> V_410 = sizeof( struct V_408 ) / sizeof( V_74 ) ;
V_409 -> V_415 = V_416 ;
V_409 -> V_417 = V_421 ;
V_409 -> V_423 = V_504 + 1 ;
V_409 -> V_424 = V_383 -> V_425 ;
if ( V_164 -> V_194 . V_133 == V_128 )
F_185 ( V_8 , V_395 ) ;
else if ( V_164 -> V_194 . V_133 == V_130 )
F_186 ( V_8 , V_395 ) ;
if ( V_174 ) {
V_90 = (struct V_89 * ) F_43 ( V_8 ,
sizeof( struct V_89 ) + V_96 ) ;
V_90 -> V_93 =
( sizeof( struct V_89 ) + V_96 ) / sizeof( V_74 ) ;
V_90 -> V_98 = V_123 ;
V_90 -> V_100 = V_174 -> V_99 ;
V_90 -> V_102 = V_174 -> V_101 ;
V_90 -> V_91 = V_174 -> V_103 ;
memcpy ( V_90 + 1 , V_174 -> V_285 ,
V_174 -> V_103 ) ;
}
return F_34 ( V_8 , V_64 , V_55 , NULL , F_101 ( V_164 ) ) ;
}
static struct V_382 * F_194 ( struct V_2 * V_3 , int V_505 ,
T_7 * V_61 , int V_47 , int * V_384 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_382 * V_383 ;
struct V_408 * V_409 = (struct V_408 * ) V_61 ;
struct V_89 * V_90 ;
switch ( V_3 -> V_38 ) {
case V_85 :
if ( V_505 != V_506 ) {
* V_384 = - V_305 ;
return NULL ;
}
break;
#if F_45 ( V_81 )
case V_88 :
if ( V_505 != V_507 ) {
* V_384 = - V_305 ;
return NULL ;
}
break;
#endif
default:
* V_384 = - V_71 ;
return NULL ;
}
* V_384 = - V_71 ;
if ( V_47 < sizeof( struct V_408 ) ||
V_409 -> V_410 * 8 > V_47 ||
V_409 -> V_417 > V_508 ||
( ! V_409 -> V_423 || V_409 -> V_423 > V_509 ) )
return NULL ;
V_383 = F_151 ( V_10 , V_64 ) ;
if ( V_383 == NULL ) {
* V_384 = - V_44 ;
return NULL ;
}
V_383 -> V_419 = ( V_409 -> V_417 == V_418 ?
V_434 : V_420 ) ;
V_383 -> V_229 . V_239 = V_437 ;
V_383 -> V_229 . V_232 = V_437 ;
V_383 -> V_229 . V_238 = V_437 ;
V_383 -> V_229 . V_230 = V_437 ;
V_383 -> V_134 = V_3 -> V_38 ;
V_383 -> V_385 = 0 ;
if ( V_409 -> V_417 == V_421 &&
( * V_384 = F_144 ( V_383 , V_409 ) ) < 0 )
goto V_35;
if ( V_47 >= ( V_409 -> V_410 * 8 +
sizeof( struct V_89 ) ) ) {
char * V_75 = ( char * ) V_409 ;
struct V_94 * V_95 ;
V_75 += V_409 -> V_410 * 8 ;
V_90 = (struct V_89 * ) V_75 ;
if ( V_47 < V_409 -> V_410 * 8 +
V_90 -> V_93 ) {
* V_384 = - V_71 ;
goto V_35;
}
if ( ( * V_384 = F_48 ( V_75 ) ) )
goto V_35;
V_95 = F_49 ( V_90 ) ;
* V_384 = F_153 ( & V_383 -> V_182 , V_95 ) ;
F_81 ( V_95 ) ;
if ( * V_384 )
goto V_35;
}
* V_384 = V_409 -> V_423 - 1 ;
return V_383 ;
V_35:
V_383 -> V_388 . V_438 = 1 ;
F_158 ( V_383 ) ;
return NULL ;
}
static int F_195 ( struct V_142 * V_164 , T_4 * V_510 , T_5 V_253 )
{
struct V_41 * V_8 ;
struct V_58 * V_59 ;
struct V_143 * V_135 ;
struct V_76 * V_79 ;
struct V_191 * V_271 ;
int V_178 ;
int V_175 ;
T_8 V_124 = ( V_164 -> V_194 . V_133 == V_130 ? V_129 : 0 ) ;
struct V_179 * V_180 = NULL ;
V_178 = F_62 ( V_164 -> V_181 . V_134 ) ;
if ( ! V_178 )
return - V_71 ;
if ( ! V_124 )
return - V_71 ;
if ( ! V_164 -> V_188 )
return - V_71 ;
V_180 = V_164 -> V_188 ;
V_175 = sizeof( struct V_58 ) +
sizeof( struct V_143 ) +
( sizeof( struct V_76 ) * 2 ) +
( V_178 * 2 ) +
( sizeof( struct V_191 ) * 2 ) ;
V_8 = F_41 ( V_175 + 16 , V_64 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_319 = V_29 ;
V_59 -> V_320 = V_511 ;
V_59 -> V_145 = V_124 ;
V_59 -> V_73 = V_175 / sizeof( V_74 ) ;
V_59 -> V_63 = 0 ;
V_59 -> V_322 = 0 ;
V_59 -> V_62 = V_164 -> V_198 . V_303 = F_191 () ;
V_59 -> V_323 = 0 ;
V_135 = (struct V_143 * ) F_43 ( V_8 , sizeof( struct V_143 ) ) ;
V_135 -> V_192 = sizeof( struct V_143 ) / sizeof( V_74 ) ;
V_135 -> V_193 = V_144 ;
V_135 -> V_147 = V_164 -> V_194 . V_195 ;
V_135 -> V_196 = 0 ;
V_135 -> V_201 = 0 ;
V_135 -> V_208 = 0 ;
V_135 -> V_215 = 0 ;
V_135 -> V_217 = 0 ;
V_79 = (struct V_76 * )
F_43 ( V_8 , sizeof( struct V_76 ) + V_178 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_178 ) /
sizeof( V_74 ) ;
V_79 -> V_248 = V_119 ;
V_79 -> V_249 = 0 ;
V_79 -> V_250 = 0 ;
V_79 -> V_87 =
F_66 ( & V_164 -> V_181 . V_184 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_164 -> V_181 . V_134 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_271 = (struct V_191 * ) F_43 ( V_8 , sizeof ( * V_271 ) ) ;
V_271 -> V_277 = sizeof( * V_271 ) / sizeof( V_74 ) ;
V_271 -> V_278 = V_279 ;
V_271 -> V_280 = V_180 -> V_281 ;
V_271 -> V_282 = 0 ;
V_79 = (struct V_76 * )
F_43 ( V_8 , sizeof( struct V_76 ) + V_178 ) ;
V_79 -> V_86 =
( sizeof( struct V_76 ) + V_178 ) /
sizeof( V_74 ) ;
V_79 -> V_248 = V_120 ;
V_79 -> V_249 = 0 ;
V_79 -> V_250 = 0 ;
V_79 -> V_87 =
F_66 ( V_510 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_164 -> V_181 . V_134 ) ;
if ( ! V_79 -> V_87 )
F_74 () ;
V_271 = (struct V_191 * ) F_43 ( V_8 , sizeof ( * V_271 ) ) ;
V_271 -> V_277 = sizeof( * V_271 ) / sizeof( V_74 ) ;
V_271 -> V_278 = V_283 ;
V_271 -> V_280 = V_253 ;
V_271 -> V_282 = 0 ;
return F_34 ( V_8 , V_64 , V_55 , NULL , F_101 ( V_164 ) ) ;
}
static int F_196 ( struct V_41 * V_8 , int V_512 , int type ,
const struct V_439 * V_183 )
{
struct V_76 * V_79 ;
V_79 = (struct V_76 * ) F_43 ( V_8 , sizeof( struct V_76 ) + V_512 ) ;
V_79 -> V_86 = ( sizeof( struct V_76 ) + V_512 ) / 8 ;
V_79 -> V_248 = type ;
V_79 -> V_249 = V_183 -> V_133 ;
V_79 -> V_250 = 0 ;
switch ( type ) {
case V_119 :
V_79 -> V_87 = V_183 -> V_252 ;
F_66 ( & V_183 -> V_184 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_183 -> V_134 ) ;
break;
case V_120 :
V_79 -> V_87 = V_183 -> V_413 ;
F_66 ( & V_183 -> V_251 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_183 -> V_134 ) ;
break;
default:
return - V_71 ;
}
return 0 ;
}
static int F_197 ( struct V_41 * V_8 , const struct V_455 * V_456 )
{
struct V_453 * V_454 ;
T_7 * V_135 ;
int V_134 = V_456 -> V_134 ;
int V_405 = F_57 ( V_134 ) ;
int V_513 ;
V_513 = ( sizeof( struct V_453 ) +
F_165 ( V_134 ) ) ;
V_454 = (struct V_453 * ) F_43 ( V_8 , V_513 ) ;
memset ( V_454 , 0 , V_513 ) ;
V_454 -> V_460 = V_513 / 8 ;
V_454 -> V_514 = V_457 ;
V_454 -> V_459 = V_456 -> V_458 ;
V_135 = ( T_7 * ) ( V_454 + 1 ) ;
if ( ! F_66 ( & V_456 -> V_461 , 0 , (struct V_78 * ) V_135 , V_134 ) ||
! F_66 ( & V_456 -> V_462 , 0 , (struct V_78 * ) ( V_135 + V_405 ) , V_134 ) )
return - V_71 ;
return 0 ;
}
static int F_198 ( struct V_41 * V_8 ,
V_72 V_133 , V_72 V_148 , int V_515 ,
T_11 V_269 , V_72 V_134 ,
const T_4 * V_104 , const T_4 * V_105 )
{
struct V_392 * V_393 ;
T_7 * V_135 ;
int V_405 = F_57 ( V_134 ) ;
int V_513 ;
V_513 = sizeof( struct V_392 ) +
F_165 ( V_134 ) ;
V_393 = (struct V_392 * ) F_43 ( V_8 , V_513 ) ;
memset ( V_393 , 0 , V_513 ) ;
V_393 -> V_411 = V_513 ;
V_393 -> V_399 = V_133 ;
V_393 -> V_398 = V_148 ;
V_393 -> V_400 = V_515 ;
V_393 -> V_404 = V_269 ;
V_135 = ( T_7 * ) ( V_393 + 1 ) ;
if ( ! F_66 ( V_104 , 0 , (struct V_78 * ) V_135 , V_134 ) ||
! F_66 ( V_105 , 0 , (struct V_78 * ) ( V_135 + V_405 ) , V_134 ) )
return - V_71 ;
return 0 ;
}
static int F_199 ( const struct V_439 * V_183 , T_7 V_384 , T_7 type ,
const struct V_443 * V_444 , int V_516 ,
const struct V_455 * V_456 )
{
int V_352 ;
int V_517 ;
int V_175 = 0 ;
int V_518 = 0 ;
struct V_41 * V_8 ;
struct V_58 * V_59 ;
struct V_408 * V_409 ;
const struct V_443 * V_519 ;
if ( type != V_391 )
return 0 ;
if ( V_516 <= 0 || V_516 > V_396 )
return - V_71 ;
if ( V_456 != NULL ) {
V_175 += F_63 ( sizeof( struct V_453 ) +
F_165 ( V_456 -> V_134 ) ) ;
}
V_517 = F_62 ( V_183 -> V_134 ) ;
if ( ! V_517 )
return - V_71 ;
V_175 += ( sizeof( struct V_76 ) + V_517 ) * 2 ;
V_518 += sizeof( struct V_408 ) ;
for ( V_352 = 0 , V_519 = V_444 ; V_352 < V_516 ; V_352 ++ , V_519 ++ ) {
V_518 += sizeof( struct V_392 ) +
F_165 ( V_519 -> V_448 ) ;
V_518 += sizeof( struct V_392 ) +
F_165 ( V_519 -> V_451 ) ;
}
V_175 += sizeof( struct V_58 ) + V_518 ;
V_8 = F_41 ( V_175 , V_64 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_59 = (struct V_58 * ) F_43 ( V_8 , sizeof( struct V_58 ) ) ;
V_59 -> V_319 = V_29 ;
V_59 -> V_320 = V_520 ;
V_59 -> V_145 = F_54 ( V_444 -> V_133 ) ;
V_59 -> V_73 = V_175 / 8 ;
V_59 -> V_63 = 0 ;
V_59 -> V_322 = 0 ;
V_59 -> V_62 = 0 ;
V_59 -> V_323 = 0 ;
if ( V_456 != NULL && ( F_197 ( V_8 , V_456 ) < 0 ) )
goto V_23;
F_196 ( V_8 , V_517 , V_119 , V_183 ) ;
F_196 ( V_8 , V_517 , V_120 , V_183 ) ;
V_409 = (struct V_408 * ) F_43 ( V_8 , sizeof( struct V_408 ) ) ;
V_409 -> V_410 = V_518 / 8 ;
V_409 -> V_415 = V_416 ;
V_409 -> V_417 = V_421 ;
V_409 -> V_423 = V_384 + 1 ;
V_409 -> V_424 = 0 ;
V_409 -> V_426 = 0 ;
for ( V_352 = 0 , V_519 = V_444 ; V_352 < V_516 ; V_352 ++ , V_519 ++ ) {
int V_148 = F_64 ( V_519 -> V_148 ) ;
if ( V_148 < 0 )
goto V_23;
if ( F_198 ( V_8 , V_519 -> V_133 , V_148 ,
( V_519 -> V_269 ? V_403 : V_429 ) ,
V_519 -> V_269 , V_519 -> V_448 ,
& V_519 -> V_446 , & V_519 -> V_447 ) < 0 )
goto V_23;
if ( F_198 ( V_8 , V_519 -> V_133 , V_148 ,
( V_519 -> V_269 ? V_403 : V_429 ) ,
V_519 -> V_269 , V_519 -> V_451 ,
& V_519 -> V_449 , & V_519 -> V_450 ) < 0 )
goto V_23;
}
F_34 ( V_8 , V_64 , V_53 , NULL , & V_521 ) ;
return 0 ;
V_23:
F_5 ( V_8 ) ;
return - V_71 ;
}
static int F_199 ( const struct V_439 * V_183 , T_7 V_384 , T_7 type ,
const struct V_443 * V_444 , int V_516 ,
const struct V_455 * V_456 )
{
return - V_463 ;
}
static int F_200 ( struct V_522 * V_522 ,
struct V_20 * V_2 , struct V_523 * V_524 , T_12 V_47 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_41 * V_8 = NULL ;
struct V_58 * V_59 = NULL ;
int V_23 ;
V_23 = - V_305 ;
if ( V_524 -> V_525 & V_526 )
goto V_35;
V_23 = - V_473 ;
if ( ( unsigned int ) V_47 > V_3 -> V_527 - 32 )
goto V_35;
V_23 = - V_44 ;
V_8 = F_41 ( V_47 , V_33 ) ;
if ( V_8 == NULL )
goto V_35;
V_23 = - V_528 ;
if ( F_201 ( F_43 ( V_8 , V_47 ) , V_524 -> V_529 , V_47 ) )
goto V_35;
V_59 = F_180 ( V_8 , & V_23 ) ;
if ( ! V_59 )
goto V_35;
F_15 ( & V_530 ) ;
V_23 = F_179 ( V_3 , V_8 , V_59 ) ;
F_17 ( & V_530 ) ;
V_35:
if ( V_23 && V_59 && F_40 ( V_59 , V_23 , V_3 ) == 0 )
V_23 = 0 ;
F_5 ( V_8 ) ;
return V_23 ? : V_47 ;
}
static int F_202 ( struct V_522 * V_522 ,
struct V_20 * V_2 , struct V_523 * V_524 , T_12 V_47 ,
int V_218 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_41 * V_8 ;
int V_531 , V_23 ;
V_23 = - V_71 ;
if ( V_218 & ~ ( V_532 | V_533 | V_534 | V_535 ) )
goto V_35;
V_524 -> V_536 = 0 ;
V_8 = F_203 ( V_3 , V_218 , V_218 & V_533 , & V_23 ) ;
if ( V_8 == NULL )
goto V_35;
V_531 = V_8 -> V_47 ;
if ( V_531 > V_47 ) {
V_524 -> V_525 |= V_534 ;
V_531 = V_47 ;
}
F_204 ( V_8 ) ;
V_23 = F_205 ( V_8 , 0 , V_524 -> V_529 , V_531 ) ;
if ( V_23 )
goto V_537;
F_206 ( V_524 , V_3 , V_8 ) ;
V_23 = ( V_218 & V_534 ) ? V_8 -> V_47 : V_531 ;
if ( V_6 -> V_7 . V_7 != NULL &&
3 * F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 )
F_38 ( V_6 ) ;
V_537:
F_207 ( V_3 , V_8 ) ;
V_35:
return V_23 ;
}
static int F_208 ( struct V_538 * V_539 , void * V_540 )
{
struct V_2 * V_541 = F_209 ( V_540 ) ;
if ( V_540 == V_542 )
F_210 ( V_539 , L_4 ) ;
else
F_210 ( V_539 , L_5 ,
V_541 ,
F_3 ( & V_541 -> V_543 ) ,
F_211 ( V_541 ) ,
F_212 ( V_541 ) ,
F_213 ( F_214 ( V_539 ) , F_215 ( V_541 ) ) ,
F_216 ( V_541 )
) ;
return 0 ;
}
static void * F_217 ( struct V_538 * V_539 , T_13 * V_544 )
__acquires( T_14 )
{
struct V_10 * V_10 = F_218 ( V_539 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_35 () ;
return F_219 ( & V_12 -> V_19 , * V_544 ) ;
}
static void * F_220 ( struct V_538 * V_539 , void * V_540 , T_13 * V_544 )
{
struct V_10 * V_10 = F_218 ( V_539 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
return F_221 ( V_540 , & V_12 -> V_19 , V_544 ) ;
}
static void F_222 ( struct V_538 * V_539 , void * V_540 )
__releases( T_14 )
{
F_37 () ;
}
static int F_223 ( struct V_545 * V_545 , struct V_546 * V_546 )
{
return F_224 ( V_545 , V_546 , & V_547 ,
sizeof( struct V_548 ) ) ;
}
static int T_15 F_225 ( struct V_10 * V_10 )
{
struct V_549 * V_550 ;
V_550 = F_226 ( L_6 , 0 , V_10 -> V_551 , & V_552 ) ;
if ( V_550 == NULL )
return - V_31 ;
return 0 ;
}
static void T_16 F_227 ( struct V_10 * V_10 )
{
F_228 ( L_6 , V_10 -> V_551 ) ;
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
int V_553 ;
F_230 ( & V_12 -> V_19 ) ;
F_231 ( & V_12 -> V_17 , 0 ) ;
V_553 = F_225 ( V_10 ) ;
return V_553 ;
}
static void T_16 F_232 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_227 ( V_10 ) ;
F_42 ( ! F_233 ( & V_12 -> V_19 ) ) ;
}
static void T_17 F_234 ( void )
{
F_235 ( & V_554 ) ;
F_236 ( V_32 ) ;
F_237 ( & V_555 ) ;
F_238 ( & V_34 ) ;
}
static int T_18 F_239 ( void )
{
int V_23 = F_240 ( & V_34 , 0 ) ;
if ( V_23 != 0 )
goto V_35;
V_23 = F_241 ( & V_555 ) ;
if ( V_23 != 0 )
goto V_556;
V_23 = F_242 ( & V_557 ) ;
if ( V_23 != 0 )
goto V_558;
V_23 = F_243 ( & V_554 ) ;
if ( V_23 != 0 )
goto V_559;
V_35:
return V_23 ;
V_559:
F_236 ( V_32 ) ;
V_558:
F_237 ( & V_555 ) ;
V_556:
F_238 ( & V_34 ) ;
goto V_35;
}
