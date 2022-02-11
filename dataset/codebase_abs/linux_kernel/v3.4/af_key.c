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
if ( ! F_21 ( V_24 ) )
return - V_25 ;
if ( V_2 -> type != V_26 )
return - V_27 ;
if ( V_21 != V_28 )
return - V_29 ;
V_23 = - V_30 ;
V_3 = F_22 ( V_10 , V_31 , V_32 , & V_33 ) ;
if ( V_3 == NULL )
goto V_34;
V_2 -> V_35 = & V_36 ;
F_23 ( V_2 , V_3 ) ;
V_3 -> V_37 = V_31 ;
V_3 -> V_38 = F_6 ;
F_24 ( & V_12 -> V_17 ) ;
F_14 ( V_3 ) ;
return 0 ;
V_34:
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
F_9 ( & V_3 -> V_39 ) ;
F_27 () ;
F_28 ( V_3 ) ;
return 0 ;
}
static int F_29 ( struct V_40 * V_8 , struct V_40 * * V_41 ,
T_1 V_42 , struct V_2 * V_3 )
{
int V_23 = - V_43 ;
F_30 ( V_3 ) ;
if ( * V_41 == NULL ) {
if ( F_3 ( & V_8 -> V_44 ) != 1 ) {
* V_41 = F_31 ( V_8 , V_42 ) ;
} else {
* V_41 = V_8 ;
F_24 ( & V_8 -> V_44 ) ;
}
}
if ( * V_41 != NULL ) {
if ( F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 ) {
F_32 ( * V_41 ) ;
F_33 ( * V_41 , V_3 ) ;
F_34 ( & V_3 -> V_14 , * V_41 ) ;
V_3 -> V_45 ( V_3 , ( * V_41 ) -> V_46 ) ;
* V_41 = NULL ;
V_23 = 0 ;
}
}
F_28 ( V_3 ) ;
return V_23 ;
}
static int F_35 ( struct V_40 * V_8 , T_1 V_42 ,
int V_47 , struct V_2 * V_48 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
struct V_2 * V_3 ;
struct V_49 * V_50 ;
struct V_40 * V_41 = NULL ;
int V_23 = - V_51 ;
if ( ! V_8 )
return - V_30 ;
F_36 () ;
F_37 (sk, node, &net_pfkey->table) {
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_52 ;
if ( V_6 -> V_53 )
F_29 ( V_8 , & V_41 , V_42 , V_3 ) ;
if ( V_3 == V_48 )
continue;
if ( V_47 != V_54 ) {
if ( V_47 & V_55 )
continue;
if ( ( V_47 & V_56 ) &&
! V_6 -> V_57 )
continue;
if ( V_47 & V_58 )
continue;
}
V_52 = F_29 ( V_8 , & V_41 , V_42 , V_3 ) ;
if ( ( V_47 & V_56 ) && V_23 )
V_23 = V_52 ;
}
F_38 () ;
if ( V_48 != NULL )
V_23 = F_29 ( V_8 , & V_41 , V_42 , V_48 ) ;
F_5 ( V_41 ) ;
F_5 ( V_8 ) ;
return V_23 ;
}
static int F_39 ( struct V_1 * V_6 )
{
struct V_59 * V_60 ;
int V_61 ;
V_61 = V_6 -> V_7 . V_7 ( V_6 ) ;
if ( V_61 == - V_43 )
return 0 ;
if ( V_6 -> V_7 . V_8 ) {
if ( ! F_2 ( & V_6 -> V_3 ) )
return 0 ;
V_60 = (struct V_59 * ) V_6 -> V_7 . V_8 -> V_62 ;
V_60 -> V_63 = 0 ;
V_60 -> V_64 = V_61 ;
F_35 ( V_6 -> V_7 . V_8 , V_65 , V_58 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = NULL ;
}
F_4 ( V_6 ) ;
return V_61 ;
}
static inline void F_40 ( struct V_59 * V_66 ,
const struct V_59 * V_67 )
{
* V_66 = * V_67 ;
}
static int F_41 ( const struct V_59 * V_67 , int V_23 , struct V_2 * V_3 )
{
struct V_40 * V_8 = F_42 ( sizeof( struct V_59 ) + 16 , V_32 ) ;
struct V_59 * V_60 ;
if ( ! V_8 )
return - V_43 ;
V_23 = - V_23 ;
if ( V_23 == V_68 ||
V_23 == V_69 ||
V_23 == V_70 )
V_23 = V_71 ;
if ( V_23 >= 512 )
V_23 = V_72 ;
F_43 ( V_23 <= 0 || V_23 >= 256 ) ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
F_40 ( V_60 , V_67 ) ;
V_60 -> V_64 = ( V_73 ) V_23 ;
V_60 -> V_74 = ( sizeof( struct V_59 ) /
sizeof( V_75 ) ) ;
F_35 ( V_8 , V_32 , V_58 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_45 ( const void * V_76 )
{
const struct V_77 * V_78 = V_76 ;
const struct V_79 * V_80 = ( const struct V_79 * ) ( V_78 + 1 ) ;
const struct V_81 * sin ;
#if F_46 ( V_82 )
const struct V_83 * V_84 ;
#endif
int V_46 ;
switch ( V_80 -> V_85 ) {
case V_86 :
V_46 = F_47 ( sizeof( * V_78 ) + sizeof( * sin ) , sizeof( V_75 ) ) ;
if ( V_78 -> V_87 != V_46 ||
V_78 -> V_88 > 32 )
return - V_72 ;
break;
#if F_46 ( V_82 )
case V_89 :
V_46 = F_47 ( sizeof( * V_78 ) + sizeof( * V_84 ) , sizeof( V_75 ) ) ;
if ( V_78 -> V_87 != V_46 ||
V_78 -> V_88 > 128 )
return - V_72 ;
break;
#endif
default:
return - V_72 ;
break;
}
return 0 ;
}
static inline int F_48 ( const struct V_90 * V_91 )
{
return F_47 ( sizeof( struct V_90 ) +
V_91 -> V_92 ,
sizeof( V_75 ) ) ;
}
static inline int F_49 ( const void * V_76 )
{
const struct V_90 * V_91 = V_76 ;
int V_46 = V_91 -> V_92 ;
if ( V_46 > V_93 )
return - V_72 ;
V_46 = F_48 ( V_91 ) ;
if ( V_91 -> V_94 != V_46 )
return - V_72 ;
return 0 ;
}
static inline struct V_95 * F_50 ( const struct V_90 * V_91 )
{
struct V_95 * V_96 = NULL ;
int V_97 = V_91 -> V_92 ;
V_96 = F_51 ( ( sizeof( * V_96 ) + V_97 ) , V_32 ) ;
if ( ! V_96 )
return NULL ;
V_96 -> V_46 = F_48 ( V_91 ) ;
V_96 -> V_98 = V_91 -> V_99 ;
V_96 -> V_100 = V_91 -> V_101 ;
V_96 -> V_102 = V_91 -> V_103 ;
V_96 -> V_104 = V_91 -> V_92 ;
memcpy ( V_96 + 1 , V_91 + 1 ,
V_96 -> V_104 ) ;
return V_96 ;
}
static int F_52 ( const struct V_77 * V_105 ,
const struct V_77 * V_106 )
{
const struct V_79 * V_107 , * V_108 ;
if ( ! V_105 || ! V_106 )
return 0 ;
V_107 = ( const struct V_79 * ) ( V_105 + 1 ) ;
V_108 = ( const struct V_79 * ) ( V_106 + 1 ) ;
if ( V_107 -> V_85 != V_108 -> V_85 )
return 0 ;
if ( V_107 -> V_85 != V_86
#if F_46 ( V_82 )
&& V_107 -> V_85 != V_89
#endif
)
return 0 ;
return 1 ;
}
static int F_53 ( struct V_40 * V_8 , const struct V_59 * V_60 , void * * V_109 )
{
const char * V_76 = ( char * ) V_60 ;
int V_46 = V_8 -> V_46 ;
V_46 -= sizeof( * V_60 ) ;
V_76 += sizeof( * V_60 ) ;
while ( V_46 > 0 ) {
const struct V_110 * V_111 = ( const struct V_110 * ) V_76 ;
T_2 V_112 ;
int V_113 ;
V_113 = V_111 -> V_114 ;
V_113 *= sizeof( V_75 ) ;
V_112 = V_111 -> V_115 ;
if ( V_113 < sizeof( V_75 ) ||
V_113 > V_46 ||
V_112 == V_116 )
return - V_72 ;
if ( V_112 <= V_117 ) {
int V_118 = ( int ) V_119 [ V_112 ] ;
if ( V_113 < V_118 )
return - V_72 ;
if ( V_109 [ V_112 - 1 ] != NULL )
return - V_72 ;
if ( V_112 == V_120 ||
V_112 == V_121 ||
V_112 == V_122 ||
V_112 == V_123 ) {
if ( F_45 ( V_76 ) )
return - V_72 ;
}
if ( V_112 == V_124 ) {
if ( F_49 ( V_76 ) )
return - V_72 ;
}
V_109 [ V_112 - 1 ] = ( void * ) V_76 ;
}
V_76 += V_113 ;
V_46 -= V_113 ;
}
return 0 ;
}
static T_2
F_54 ( V_73 V_125 )
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
static V_73
F_55 ( T_2 V_134 )
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
static V_73 F_56 ( V_73 V_134 )
{
return V_134 == V_127 ? 0 : V_134 ;
}
static V_73 F_57 ( V_73 V_134 )
{
return V_134 ? V_134 : V_127 ;
}
static inline int F_58 ( T_3 V_135 )
{
switch ( V_135 ) {
case V_86 :
return sizeof( struct V_81 ) ;
#if F_46 ( V_82 )
case V_89 :
return sizeof( struct V_83 ) ;
#endif
}
return 0 ;
}
static
int F_59 ( const struct V_79 * V_136 , T_4 * V_137 )
{
switch ( V_136 -> V_85 ) {
case V_86 :
V_137 -> V_138 =
( (struct V_81 * ) V_136 ) -> V_139 . V_107 ;
return V_86 ;
#if F_46 ( V_82 )
case V_89 :
memcpy ( V_137 -> V_140 ,
& ( (struct V_83 * ) V_136 ) -> V_141 ,
sizeof( struct V_142 ) ) ;
return V_89 ;
#endif
}
return 0 ;
}
static
int F_60 ( const struct V_77 * V_80 , T_4 * V_137 )
{
return F_59 ( (struct V_79 * ) ( V_80 + 1 ) ,
V_137 ) ;
}
static struct V_143 * F_61 ( struct V_10 * V_10 , const struct V_59 * V_60 , void * const * V_109 )
{
const struct V_144 * V_136 ;
const struct V_77 * V_80 ;
T_2 V_134 ;
unsigned short V_135 ;
T_4 * V_137 ;
V_136 = V_109 [ V_145 - 1 ] ;
if ( V_136 == NULL )
return NULL ;
V_134 = F_54 ( V_60 -> V_146 ) ;
if ( V_134 == 0 )
return NULL ;
V_80 = V_109 [ V_121 - 1 ] ;
if ( V_80 == NULL )
return NULL ;
V_135 = ( ( const struct V_79 * ) ( V_80 + 1 ) ) -> V_85 ;
switch ( V_135 ) {
case V_86 :
V_137 = ( T_4 * ) & ( ( const struct V_81 * ) ( V_80 + 1 ) ) -> V_139 ;
break;
#if F_46 ( V_82 )
case V_89 :
V_137 = ( T_4 * ) & ( ( const struct V_83 * ) ( V_80 + 1 ) ) -> V_141 ;
break;
#endif
default:
V_137 = NULL ;
}
if ( ! V_137 )
return NULL ;
return F_62 ( V_10 , V_147 , V_137 , V_136 -> V_148 , V_134 , V_135 ) ;
}
static int
F_63 ( T_3 V_135 )
{
return F_64 ( F_58 ( V_135 ) ) ;
}
static inline int F_65 ( int V_149 )
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
static inline int F_66 ( int V_149 )
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
static unsigned int F_67 ( const T_4 * V_137 , T_5 V_157 ,
struct V_79 * V_136 ,
unsigned short V_135 )
{
switch ( V_135 ) {
case V_86 :
{
struct V_81 * sin = (struct V_81 * ) V_136 ;
sin -> V_158 = V_86 ;
sin -> V_159 = V_157 ;
sin -> V_139 . V_107 = V_137 -> V_138 ;
memset ( sin -> V_160 , 0 , sizeof( sin -> V_160 ) ) ;
return 32 ;
}
#if F_46 ( V_82 )
case V_89 :
{
struct V_83 * V_84 = (struct V_83 * ) V_136 ;
V_84 -> V_161 = V_89 ;
V_84 -> V_162 = V_157 ;
V_84 -> V_163 = 0 ;
V_84 -> V_141 = * (struct V_142 * ) V_137 -> V_140 ;
V_84 -> V_164 = 0 ;
return 128 ;
}
#endif
}
return 0 ;
}
static struct V_40 * F_68 ( const struct V_143 * V_165 ,
int V_166 , int V_167 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
struct V_144 * V_136 ;
struct V_168 * V_169 ;
struct V_77 * V_80 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
struct V_90 * V_91 ;
struct V_174 * V_175 ;
int V_97 = 0 ;
int V_176 ;
int V_177 = 0 ;
int V_178 = 0 ;
int V_179 ;
struct V_180 * V_181 = NULL ;
int V_149 ;
V_179 = F_63 ( V_165 -> V_182 . V_135 ) ;
if ( ! V_179 )
return F_69 ( - V_72 ) ;
V_176 = sizeof( struct V_59 ) + sizeof( struct V_144 ) +
sizeof( struct V_168 ) +
( ( V_167 & 1 ) ? sizeof( struct V_168 ) : 0 ) +
( ( V_167 & 2 ) ? sizeof( struct V_168 ) : 0 ) +
sizeof( struct V_77 ) * 2 +
V_179 * 2 +
sizeof( struct V_172 ) ;
if ( ( V_175 = V_165 -> V_183 ) ) {
V_97 = F_64 ( V_175 -> V_104 ) ;
V_176 += sizeof( struct V_90 ) + V_97 ;
}
if ( F_70 ( & V_165 -> V_184 . V_185 , & V_165 -> V_182 . V_185 , V_165 -> V_182 . V_135 ) )
V_176 += sizeof( struct V_77 ) + V_179 ;
if ( V_166 ) {
if ( V_165 -> V_186 && V_165 -> V_186 -> V_187 ) {
V_177 =
F_64 ( ( V_165 -> V_186 -> V_187 + 7 ) / 8 ) ;
V_176 += sizeof( struct V_170 ) + V_177 ;
}
if ( V_165 -> V_188 && V_165 -> V_188 -> V_187 ) {
V_178 =
F_64 ( ( V_165 -> V_188 -> V_187 + 7 ) / 8 ) ;
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
V_8 = F_42 ( V_176 + 16 , V_65 ) ;
if ( V_8 == NULL )
return F_69 ( - V_43 ) ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
memset ( V_60 , 0 , V_176 ) ;
V_60 -> V_74 = V_176 / sizeof( V_75 ) ;
V_136 = (struct V_144 * ) F_44 ( V_8 , sizeof( struct V_144 ) ) ;
V_136 -> V_193 = sizeof( struct V_144 ) / sizeof( V_75 ) ;
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
struct V_210 * V_211 = F_71 ( V_165 -> V_186 -> V_212 , 0 ) ;
V_136 -> V_209 = V_211 ? V_211 -> V_213 . V_214 : 0 ;
}
V_136 -> V_215 = 0 ;
F_43 ( V_165 -> V_188 && V_165 -> V_216 ) ;
if ( V_165 -> V_188 ) {
struct V_210 * V_211 = F_72 ( V_165 -> V_188 -> V_212 , 0 ) ;
V_136 -> V_215 = V_211 ? V_211 -> V_213 . V_214 : 0 ;
}
if ( V_165 -> V_216 ) {
struct V_210 * V_211 = F_73 ( V_165 -> V_216 -> V_212 , 0 ) ;
V_136 -> V_215 = V_211 ? V_211 -> V_213 . V_214 : 0 ;
}
V_136 -> V_217 = 0 ;
if ( V_165 -> V_182 . V_218 & V_219 )
V_136 -> V_217 |= V_220 ;
if ( V_165 -> V_182 . V_218 & V_221 )
V_136 -> V_217 |= V_222 ;
if ( V_165 -> V_182 . V_218 & V_223 )
V_136 -> V_217 |= V_224 ;
if ( V_167 & 2 ) {
V_169 = (struct V_168 * ) F_44 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_225 =
sizeof( struct V_168 ) / sizeof( V_75 ) ;
V_169 -> V_226 = V_227 ;
V_169 -> V_228 = F_74 ( V_165 -> V_229 . V_230 ) ;
V_169 -> V_231 = F_74 ( V_165 -> V_229 . V_232 ) ;
V_169 -> V_233 = V_165 -> V_229 . V_234 ;
V_169 -> V_235 = V_165 -> V_229 . V_236 ;
}
if ( V_167 & 1 ) {
V_169 = (struct V_168 * ) F_44 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_225 =
sizeof( struct V_168 ) / sizeof( V_75 ) ;
V_169 -> V_226 = V_237 ;
V_169 -> V_228 = F_74 ( V_165 -> V_229 . V_238 ) ;
V_169 -> V_231 = F_74 ( V_165 -> V_229 . V_239 ) ;
V_169 -> V_233 = V_165 -> V_229 . V_240 ;
V_169 -> V_235 = V_165 -> V_229 . V_241 ;
}
V_169 = (struct V_168 * ) F_44 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_225 =
sizeof( struct V_168 ) / sizeof( V_75 ) ;
V_169 -> V_226 = V_242 ;
V_169 -> V_228 = V_165 -> V_243 . V_244 ;
V_169 -> V_231 = V_165 -> V_243 . V_245 ;
V_169 -> V_233 = V_165 -> V_243 . V_246 ;
V_169 -> V_235 = V_165 -> V_243 . V_247 ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_179 ) ;
V_80 -> V_87 =
( sizeof( struct V_77 ) + V_179 ) /
sizeof( V_75 ) ;
V_80 -> V_248 = V_120 ;
V_80 -> V_249 = 0 ;
V_80 -> V_250 = 0 ;
V_80 -> V_88 =
F_67 ( & V_165 -> V_182 . V_185 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_80 -> V_88 )
F_75 () ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_179 ) ;
V_80 -> V_87 =
( sizeof( struct V_77 ) + V_179 ) /
sizeof( V_75 ) ;
V_80 -> V_248 = V_121 ;
V_80 -> V_249 = 0 ;
V_80 -> V_250 = 0 ;
V_80 -> V_88 =
F_67 ( & V_165 -> V_195 . V_251 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_80 -> V_88 )
F_75 () ;
if ( F_70 ( & V_165 -> V_184 . V_185 , & V_165 -> V_182 . V_185 ,
V_165 -> V_182 . V_135 ) ) {
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_179 ) ;
V_80 -> V_87 =
( sizeof( struct V_77 ) + V_179 ) /
sizeof( V_75 ) ;
V_80 -> V_248 = V_122 ;
V_80 -> V_249 =
F_57 ( V_165 -> V_184 . V_134 ) ;
V_80 -> V_88 = V_165 -> V_184 . V_252 ;
V_80 -> V_250 = 0 ;
F_67 ( & V_165 -> V_184 . V_185 , V_165 -> V_184 . V_253 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
}
if ( V_166 && V_177 ) {
V_171 = (struct V_170 * ) F_44 ( V_8 ,
sizeof( struct V_170 ) + V_177 ) ;
V_171 -> V_254 = ( sizeof( struct V_170 ) + V_177 ) /
sizeof( V_75 ) ;
V_171 -> V_255 = V_256 ;
V_171 -> V_257 = V_165 -> V_186 -> V_187 ;
V_171 -> V_258 = 0 ;
memcpy ( V_171 + 1 , V_165 -> V_186 -> V_259 , ( V_165 -> V_186 -> V_187 + 7 ) / 8 ) ;
}
if ( V_166 && V_178 ) {
V_171 = (struct V_170 * ) F_44 ( V_8 ,
sizeof( struct V_170 ) + V_178 ) ;
V_171 -> V_254 = ( sizeof( struct V_170 ) +
V_178 ) / sizeof( V_75 ) ;
V_171 -> V_255 = V_260 ;
V_171 -> V_257 = V_165 -> V_188 -> V_187 ;
V_171 -> V_258 = 0 ;
memcpy ( V_171 + 1 , V_165 -> V_188 -> V_259 ,
( V_165 -> V_188 -> V_187 + 7 ) / 8 ) ;
}
V_173 = (struct V_172 * ) F_44 ( V_8 , sizeof( struct V_172 ) ) ;
V_173 -> V_261 = sizeof( struct V_172 ) / sizeof( V_75 ) ;
V_173 -> V_262 = V_263 ;
if ( ( V_149 = F_65 ( V_165 -> V_182 . V_149 ) ) < 0 ) {
F_5 ( V_8 ) ;
return F_69 ( - V_72 ) ;
}
V_173 -> V_264 = V_149 ;
V_173 -> V_265 = 0 ;
V_173 -> V_266 = 0 ;
V_173 -> V_267 = 0 ;
V_173 -> V_268 = V_165 -> V_182 . V_269 ;
if ( V_181 && V_181 -> V_190 ) {
struct V_191 * V_270 ;
struct V_192 * V_271 ;
V_270 = (struct V_191 * ) F_44 ( V_8 , sizeof( * V_270 ) ) ;
V_270 -> V_272 = sizeof( * V_270 ) / sizeof( V_75 ) ;
V_270 -> V_273 = V_274 ;
V_270 -> V_275 = V_181 -> V_190 ;
V_270 -> V_276 [ 0 ] = 0 ;
V_270 -> V_276 [ 1 ] = 0 ;
V_270 -> V_276 [ 2 ] = 0 ;
V_271 = (struct V_192 * ) F_44 ( V_8 , sizeof ( * V_271 ) ) ;
V_271 -> V_277 = sizeof( * V_271 ) / sizeof( V_75 ) ;
V_271 -> V_278 = V_279 ;
V_271 -> V_280 = V_181 -> V_281 ;
V_271 -> V_282 = 0 ;
V_271 = (struct V_192 * ) F_44 ( V_8 , sizeof ( * V_271 ) ) ;
V_271 -> V_277 = sizeof( * V_271 ) / sizeof( V_75 ) ;
V_271 -> V_278 = V_283 ;
V_271 -> V_280 = V_181 -> V_284 ;
V_271 -> V_282 = 0 ;
}
if ( V_175 ) {
V_91 = (struct V_90 * ) F_44 ( V_8 ,
sizeof( struct V_90 ) + V_97 ) ;
V_91 -> V_94 =
( sizeof( struct V_90 ) + V_97 ) / sizeof( V_75 ) ;
V_91 -> V_99 = V_124 ;
V_91 -> V_101 = V_175 -> V_100 ;
V_91 -> V_103 = V_175 -> V_102 ;
V_91 -> V_92 = V_175 -> V_104 ;
memcpy ( V_91 + 1 , V_175 -> V_285 ,
V_175 -> V_104 ) ;
}
return V_8 ;
}
static inline struct V_40 * F_76 ( const struct V_143 * V_165 )
{
struct V_40 * V_8 ;
V_8 = F_68 ( V_165 , 1 , 3 ) ;
return V_8 ;
}
static inline struct V_40 * F_77 ( const struct V_143 * V_165 ,
int V_167 )
{
return F_68 ( V_165 , 0 , V_167 ) ;
}
static struct V_143 * F_78 ( struct V_10 * V_10 ,
const struct V_59 * V_60 ,
void * const * V_109 )
{
struct V_143 * V_165 ;
const struct V_168 * V_169 ;
const struct V_144 * V_136 ;
const struct V_170 * V_171 ;
const struct V_90 * V_91 ;
T_2 V_134 ;
int V_23 ;
V_136 = V_109 [ V_145 - 1 ] ;
if ( ! V_136 ||
! F_52 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return F_69 ( - V_72 ) ;
if ( V_60 -> V_146 == V_130 &&
! V_109 [ V_260 - 1 ] )
return F_69 ( - V_72 ) ;
if ( V_60 -> V_146 == V_128 &&
! V_109 [ V_256 - 1 ] )
return F_69 ( - V_72 ) ;
if ( ! ! V_109 [ V_227 - 1 ] !=
! ! V_109 [ V_237 - 1 ] )
return F_69 ( - V_72 ) ;
V_134 = F_54 ( V_60 -> V_146 ) ;
if ( V_134 == 0 )
return F_69 ( - V_72 ) ;
V_23 = - V_43 ;
if ( V_136 -> V_209 > V_286 ||
( V_60 -> V_146 == V_132 &&
V_136 -> V_215 > V_287 ) ||
V_136 -> V_215 > V_288 )
return F_69 ( - V_72 ) ;
V_171 = V_109 [ V_256 - 1 ] ;
if ( V_171 != NULL &&
V_136 -> V_209 != V_289 &&
( ( V_171 -> V_257 + 7 ) / 8 == 0 ||
( V_171 -> V_257 + 7 ) / 8 > V_171 -> V_254 * sizeof( V_75 ) ) )
return F_69 ( - V_72 ) ;
V_171 = V_109 [ V_260 - 1 ] ;
if ( V_171 != NULL &&
V_136 -> V_215 != V_290 &&
( ( V_171 -> V_257 + 7 ) / 8 == 0 ||
( V_171 -> V_257 + 7 ) / 8 > V_171 -> V_254 * sizeof( V_75 ) ) )
return F_69 ( - V_72 ) ;
V_165 = F_79 ( V_10 ) ;
if ( V_165 == NULL )
return F_69 ( - V_43 ) ;
V_165 -> V_195 . V_134 = V_134 ;
V_165 -> V_195 . V_196 = V_136 -> V_148 ;
V_165 -> V_182 . V_198 = V_136 -> V_197 ;
if ( V_136 -> V_217 & V_220 )
V_165 -> V_182 . V_218 |= V_219 ;
if ( V_136 -> V_217 & V_222 )
V_165 -> V_182 . V_218 |= V_221 ;
if ( V_136 -> V_217 & V_224 )
V_165 -> V_182 . V_218 |= V_223 ;
V_169 = V_109 [ V_227 - 1 ] ;
if ( V_169 != NULL ) {
V_165 -> V_229 . V_230 = F_80 ( V_169 -> V_228 ) ;
V_165 -> V_229 . V_232 = F_80 ( V_169 -> V_231 ) ;
V_165 -> V_229 . V_234 = V_169 -> V_233 ;
V_165 -> V_229 . V_236 = V_169 -> V_235 ;
}
V_169 = V_109 [ V_237 - 1 ] ;
if ( V_169 != NULL ) {
V_165 -> V_229 . V_238 = F_80 ( V_169 -> V_228 ) ;
V_165 -> V_229 . V_239 = F_80 ( V_169 -> V_231 ) ;
V_165 -> V_229 . V_240 = V_169 -> V_233 ;
V_165 -> V_229 . V_241 = V_169 -> V_235 ;
}
V_91 = V_109 [ V_124 - 1 ] ;
if ( V_91 != NULL ) {
struct V_95 * V_96 = F_50 ( V_91 ) ;
if ( ! V_96 )
goto V_34;
V_23 = F_81 ( V_165 , V_96 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
goto V_34;
}
V_171 = V_109 [ V_256 - 1 ] ;
if ( V_136 -> V_209 ) {
int V_291 = 0 ;
struct V_210 * V_211 = F_83 ( V_136 -> V_209 ) ;
if ( ! V_211 ) {
V_23 = - V_292 ;
goto V_34;
}
if ( V_171 )
V_291 = ( V_171 -> V_257 + 7 ) / 8 ;
V_165 -> V_186 = F_51 ( sizeof( * V_165 -> V_186 ) + V_291 , V_32 ) ;
if ( ! V_165 -> V_186 )
goto V_34;
strcpy ( V_165 -> V_186 -> V_212 , V_211 -> V_293 ) ;
V_165 -> V_186 -> V_187 = 0 ;
if ( V_171 ) {
V_165 -> V_186 -> V_187 = V_171 -> V_257 ;
memcpy ( V_165 -> V_186 -> V_259 , V_171 + 1 , V_291 ) ;
}
V_165 -> V_186 -> V_294 = V_211 -> V_295 . V_296 . V_297 ;
V_165 -> V_182 . V_298 = V_136 -> V_209 ;
}
if ( V_136 -> V_215 ) {
if ( V_60 -> V_146 == V_132 ) {
struct V_210 * V_211 = F_84 ( V_136 -> V_215 ) ;
if ( ! V_211 ) {
V_23 = - V_292 ;
goto V_34;
}
V_165 -> V_216 = F_51 ( sizeof( * V_165 -> V_216 ) , V_32 ) ;
if ( ! V_165 -> V_216 )
goto V_34;
strcpy ( V_165 -> V_216 -> V_212 , V_211 -> V_293 ) ;
V_165 -> V_182 . V_299 = V_136 -> V_215 ;
} else {
int V_291 = 0 ;
struct V_210 * V_211 = F_85 ( V_136 -> V_215 ) ;
if ( ! V_211 ) {
V_23 = - V_292 ;
goto V_34;
}
V_171 = (struct V_170 * ) V_109 [ V_260 - 1 ] ;
if ( V_171 )
V_291 = ( V_171 -> V_257 + 7 ) / 8 ;
V_165 -> V_188 = F_51 ( sizeof( * V_165 -> V_188 ) + V_291 , V_32 ) ;
if ( ! V_165 -> V_188 )
goto V_34;
strcpy ( V_165 -> V_188 -> V_212 , V_211 -> V_293 ) ;
V_165 -> V_188 -> V_187 = 0 ;
if ( V_171 ) {
V_165 -> V_188 -> V_187 = V_171 -> V_257 ;
memcpy ( V_165 -> V_188 -> V_259 , V_171 + 1 , V_291 ) ;
}
V_165 -> V_182 . V_300 = V_136 -> V_215 ;
}
}
V_165 -> V_182 . V_135 = F_60 ( (struct V_77 * ) V_109 [ V_120 - 1 ] ,
& V_165 -> V_182 . V_185 ) ;
if ( ! V_165 -> V_182 . V_135 ) {
V_23 = - V_301 ;
goto V_34;
}
F_60 ( (struct V_77 * ) V_109 [ V_121 - 1 ] ,
& V_165 -> V_195 . V_251 ) ;
if ( V_109 [ V_263 - 1 ] ) {
const struct V_172 * V_173 = V_109 [ V_263 - 1 ] ;
int V_149 = F_66 ( V_173 -> V_264 ) ;
if ( V_149 < 0 ) {
V_23 = - V_72 ;
goto V_34;
}
V_165 -> V_182 . V_149 = V_149 ;
V_165 -> V_182 . V_269 = V_173 -> V_268 ;
}
if ( V_109 [ V_122 - 1 ] ) {
const struct V_77 * V_80 = V_109 [ V_122 - 1 ] ;
V_165 -> V_184 . V_135 = F_60 ( V_80 , & V_165 -> V_184 . V_185 ) ;
V_165 -> V_184 . V_252 = V_80 -> V_88 ;
}
if ( ! V_165 -> V_184 . V_135 )
V_165 -> V_184 . V_135 = V_165 -> V_182 . V_135 ;
if ( V_109 [ V_274 - 1 ] ) {
const struct V_191 * V_270 ;
struct V_180 * V_181 ;
V_165 -> V_189 = F_51 ( sizeof( * V_165 -> V_189 ) , V_32 ) ;
if ( ! V_165 -> V_189 )
goto V_34;
V_181 = V_165 -> V_189 ;
V_270 = V_109 [ V_274 - 1 ] ;
V_181 -> V_190 = V_270 -> V_275 ;
if ( V_109 [ V_279 - 1 ] ) {
const struct V_192 * V_271 =
V_109 [ V_279 - 1 ] ;
V_181 -> V_281 = V_271 -> V_280 ;
}
if ( V_109 [ V_283 - 1 ] ) {
const struct V_192 * V_271 =
V_109 [ V_283 - 1 ] ;
V_181 -> V_284 = V_271 -> V_280 ;
}
memset ( & V_181 -> V_302 , 0 , sizeof( V_181 -> V_302 ) ) ;
}
V_23 = F_86 ( V_165 ) ;
if ( V_23 )
goto V_34;
V_165 -> V_199 . V_303 = V_60 -> V_63 ;
return V_165 ;
V_34:
V_165 -> V_199 . V_200 = V_304 ;
F_87 ( V_165 ) ;
return F_69 ( V_23 ) ;
}
static int F_88 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
return - V_305 ;
}
static int F_89 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_40 * V_306 ;
struct V_172 * V_173 ;
struct V_77 * V_185 , * V_251 ;
struct V_59 * V_307 ;
struct V_308 * V_309 ;
struct V_143 * V_165 = NULL ;
int V_149 ;
int V_23 ;
T_6 V_310 , V_311 ;
T_6 V_269 ;
T_7 V_134 ;
unsigned short V_135 ;
T_4 * V_312 = NULL , * V_313 = NULL ;
if ( ! F_52 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_72 ;
V_134 = F_54 ( V_60 -> V_146 ) ;
if ( V_134 == 0 )
return - V_72 ;
if ( ( V_173 = V_109 [ V_263 - 1 ] ) != NULL ) {
V_149 = F_66 ( V_173 -> V_264 ) ;
if ( V_149 < 0 )
return - V_72 ;
V_269 = V_173 -> V_268 ;
} else {
V_149 = 0 ;
V_269 = 0 ;
}
V_185 = V_109 [ V_120 - 1 ] ;
V_251 = V_109 [ V_121 - 1 ] ;
V_135 = ( (struct V_79 * ) ( V_185 + 1 ) ) -> V_85 ;
switch ( V_135 ) {
case V_86 :
V_313 = ( T_4 * ) & ( (struct V_81 * ) ( V_251 + 1 ) ) -> V_139 . V_107 ;
V_312 = ( T_4 * ) & ( (struct V_81 * ) ( V_185 + 1 ) ) -> V_139 . V_107 ;
break;
#if F_46 ( V_82 )
case V_89 :
V_313 = ( T_4 * ) & ( (struct V_83 * ) ( V_251 + 1 ) ) -> V_141 ;
V_312 = ( T_4 * ) & ( (struct V_83 * ) ( V_185 + 1 ) ) -> V_141 ;
break;
#endif
}
if ( V_60 -> V_63 ) {
V_165 = F_90 ( V_10 , V_147 , V_60 -> V_63 ) ;
if ( V_165 && F_70 ( & V_165 -> V_195 . V_251 , V_313 , V_135 ) ) {
F_87 ( V_165 ) ;
V_165 = NULL ;
}
}
if ( ! V_165 )
V_165 = F_91 ( V_10 , & V_314 , V_149 , V_269 , V_134 , V_313 , V_312 , 1 , V_135 ) ;
if ( V_165 == NULL )
return - V_315 ;
V_310 = 0x100 ;
V_311 = 0x0fffffff ;
V_309 = V_109 [ V_316 - 1 ] ;
if ( V_309 ) {
V_310 = V_309 -> V_317 ;
V_311 = V_309 -> V_318 ;
}
V_23 = F_92 ( V_165 , V_310 , V_311 ) ;
V_306 = V_23 ? F_69 ( V_23 ) : F_76 ( V_165 ) ;
if ( F_93 ( V_306 ) ) {
F_87 ( V_165 ) ;
return F_94 ( V_306 ) ;
}
V_307 = (struct V_59 * ) V_306 -> V_62 ;
V_307 -> V_319 = V_60 -> V_319 ;
V_307 -> V_320 = V_321 ;
V_307 -> V_146 = F_55 ( V_134 ) ;
V_307 -> V_64 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_63 = V_60 -> V_63 ;
V_307 -> V_323 = V_60 -> V_323 ;
F_87 ( V_165 ) ;
F_35 ( V_306 , V_32 , V_58 , V_3 , V_10 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_165 ;
if ( V_60 -> V_74 != sizeof( struct V_59 ) / 8 )
return - V_305 ;
if ( V_60 -> V_63 == 0 || V_60 -> V_64 == 0 )
return 0 ;
V_165 = F_90 ( V_10 , V_147 , V_60 -> V_63 ) ;
if ( V_165 == NULL )
return 0 ;
F_96 ( & V_165 -> V_324 ) ;
if ( V_165 -> V_199 . V_200 == V_206 ) {
V_165 -> V_199 . V_200 = V_325 ;
F_97 ( & V_10 -> V_326 . V_327 ) ;
}
F_98 ( & V_165 -> V_324 ) ;
F_87 ( V_165 ) ;
return 0 ;
}
static inline int F_99 ( int V_328 )
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
static inline int F_100 ( int V_328 )
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
static int F_101 ( struct V_143 * V_165 , const struct V_344 * V_345 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
V_8 = F_76 ( V_165 ) ;
if ( F_93 ( V_8 ) )
return F_94 ( V_8 ) ;
V_60 = (struct V_59 * ) V_8 -> V_62 ;
V_60 -> V_319 = V_28 ;
V_60 -> V_320 = F_100 ( V_345 -> V_328 ) ;
V_60 -> V_146 = F_55 ( V_165 -> V_195 . V_134 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_322 = 0 ;
V_60 -> V_63 = V_345 -> V_303 ;
V_60 -> V_323 = V_345 -> V_346 ;
F_35 ( V_8 , V_65 , V_54 , NULL , F_102 ( V_165 ) ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_165 ;
int V_23 ;
struct V_344 V_345 ;
V_165 = F_78 ( V_10 , V_60 , V_109 ) ;
if ( F_93 ( V_165 ) )
return F_94 ( V_165 ) ;
F_104 ( V_165 ) ;
if ( V_60 -> V_320 == V_339 )
V_23 = F_105 ( V_165 ) ;
else
V_23 = F_106 ( V_165 ) ;
F_107 ( V_165 , V_23 ? 0 : 1 ,
F_108 ( V_347 ) ,
F_109 ( V_347 ) , 0 ) ;
if ( V_23 < 0 ) {
V_165 -> V_199 . V_200 = V_304 ;
F_110 ( V_165 ) ;
goto V_34;
}
if ( V_60 -> V_320 == V_339 )
V_345 . V_328 = V_338 ;
else
V_345 . V_328 = V_340 ;
V_345 . V_303 = V_60 -> V_63 ;
V_345 . V_346 = V_60 -> V_323 ;
F_111 ( V_165 , & V_345 ) ;
V_34:
F_87 ( V_165 ) ;
return V_23 ;
}
static int F_112 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_143 * V_165 ;
struct V_344 V_345 ;
int V_23 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_52 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_72 ;
V_165 = F_61 ( V_10 , V_60 , V_109 ) ;
if ( V_165 == NULL )
return - V_51 ;
if ( ( V_23 = F_113 ( V_165 ) ) )
goto V_34;
if ( F_114 ( V_165 ) ) {
V_23 = - V_25 ;
goto V_34;
}
V_23 = F_115 ( V_165 ) ;
if ( V_23 < 0 )
goto V_34;
V_345 . V_303 = V_60 -> V_63 ;
V_345 . V_346 = V_60 -> V_323 ;
V_345 . V_328 = V_336 ;
F_111 ( V_165 , & V_345 ) ;
V_34:
F_116 ( V_165 , V_23 ? 0 : 1 ,
F_108 ( V_347 ) ,
F_109 ( V_347 ) , 0 ) ;
F_87 ( V_165 ) ;
return V_23 ;
}
static int F_117 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
T_8 V_134 ;
struct V_40 * V_348 ;
struct V_59 * V_307 ;
struct V_143 * V_165 ;
if ( ! V_109 [ V_145 - 1 ] ||
! F_52 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) )
return - V_72 ;
V_165 = F_61 ( V_10 , V_60 , V_109 ) ;
if ( V_165 == NULL )
return - V_51 ;
V_348 = F_76 ( V_165 ) ;
V_134 = V_165 -> V_195 . V_134 ;
F_87 ( V_165 ) ;
if ( F_93 ( V_348 ) )
return F_94 ( V_348 ) ;
V_307 = (struct V_59 * ) V_348 -> V_62 ;
V_307 -> V_319 = V_60 -> V_319 ;
V_307 -> V_320 = V_349 ;
V_307 -> V_146 = F_55 ( V_134 ) ;
V_307 -> V_64 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_63 = V_60 -> V_63 ;
V_307 -> V_323 = V_60 -> V_323 ;
F_35 ( V_348 , V_65 , V_58 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static struct V_40 * F_118 ( const struct V_59 * V_67 ,
T_1 V_42 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
int V_46 , V_350 , V_351 , V_352 ;
V_350 = F_119 () ;
if ( V_350 ) {
V_350 *= sizeof( struct V_353 ) ;
V_350 += sizeof( struct V_354 ) ;
}
V_351 = F_120 () ;
if ( V_351 ) {
V_351 *= sizeof( struct V_353 ) ;
V_351 += sizeof( struct V_354 ) ;
}
V_46 = V_351 + V_350 + sizeof( struct V_59 ) ;
V_8 = F_42 ( V_46 + 16 , V_42 ) ;
if ( ! V_8 )
goto V_355;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( * V_60 ) ) ;
F_40 ( V_60 , V_67 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_74 = V_46 / sizeof( V_75 ) ;
if ( V_350 ) {
struct V_354 * V_78 ;
struct V_353 * V_356 ;
V_78 = (struct V_354 * ) F_44 ( V_8 , V_350 ) ;
V_356 = (struct V_353 * ) ( V_78 + 1 ) ;
V_78 -> V_357 = V_350 / sizeof( V_75 ) ;
V_78 -> V_358 = V_359 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
struct V_210 * V_186 = F_121 ( V_352 ) ;
if ( ! V_186 )
break;
if ( V_186 -> V_360 )
* V_356 ++ = V_186 -> V_213 ;
}
}
if ( V_351 ) {
struct V_354 * V_78 ;
struct V_353 * V_356 ;
V_78 = (struct V_354 * ) F_44 ( V_8 , V_351 ) ;
V_356 = (struct V_353 * ) ( V_78 + 1 ) ;
V_78 -> V_357 = V_351 / sizeof( V_75 ) ;
V_78 -> V_358 = V_361 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
struct V_210 * V_188 = F_122 ( V_352 ) ;
if ( ! V_188 )
break;
if ( V_188 -> V_360 )
* V_356 ++ = V_188 -> V_213 ;
}
}
V_355:
return V_8 ;
}
static int F_123 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_40 * V_362 ;
if ( V_60 -> V_146 > V_363 )
return - V_72 ;
if ( V_60 -> V_146 != V_126 ) {
if ( V_6 -> V_57 & ( 1 << V_60 -> V_146 ) )
return - V_364 ;
V_6 -> V_57 |= ( 1 << V_60 -> V_146 ) ;
}
F_124 () ;
V_362 = F_118 ( V_60 , V_32 ) ;
if ( ! V_362 ) {
if ( V_60 -> V_146 != V_126 )
V_6 -> V_57 &= ~ ( 1 << V_60 -> V_146 ) ;
return - V_43 ;
}
F_35 ( V_362 , V_32 , V_56 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , const struct V_59 * V_365 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
V_8 = F_42 ( sizeof( struct V_59 ) + 16 , V_65 ) ;
if ( ! V_8 )
return - V_43 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
memcpy ( V_60 , V_365 , sizeof( struct V_59 ) ) ;
V_60 -> V_64 = ( V_73 ) 0 ;
V_60 -> V_74 = ( sizeof( struct V_59 ) / sizeof( V_75 ) ) ;
return F_35 ( V_8 , V_65 , V_58 , V_3 , F_7 ( V_3 ) ) ;
}
static int F_126 ( const struct V_344 * V_345 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
V_8 = F_42 ( sizeof( struct V_59 ) + 16 , V_65 ) ;
if ( ! V_8 )
return - V_43 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_146 = F_55 ( V_345 -> V_62 . V_134 ) ;
V_60 -> V_320 = V_366 ;
V_60 -> V_63 = V_345 -> V_303 ;
V_60 -> V_323 = V_345 -> V_346 ;
V_60 -> V_319 = V_28 ;
V_60 -> V_64 = ( V_73 ) 0 ;
V_60 -> V_74 = ( sizeof( struct V_59 ) / sizeof( V_75 ) ) ;
F_35 ( V_8 , V_65 , V_54 , NULL , V_345 -> V_10 ) ;
return 0 ;
}
static int F_127 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned V_134 ;
struct V_344 V_345 ;
struct V_367 V_368 ;
int V_23 , V_52 ;
V_134 = F_54 ( V_60 -> V_146 ) ;
if ( V_134 == 0 )
return - V_72 ;
V_368 . V_369 = F_108 ( V_347 ) ;
V_368 . V_370 = F_109 ( V_347 ) ;
V_368 . V_371 = 0 ;
V_23 = F_128 ( V_10 , V_134 , & V_368 ) ;
V_52 = F_125 ( V_3 , V_60 ) ;
if ( V_23 || V_52 ) {
if ( V_23 == - V_51 )
V_23 = 0 ;
return V_23 ? V_23 : V_52 ;
}
V_345 . V_62 . V_134 = V_134 ;
V_345 . V_303 = V_60 -> V_63 ;
V_345 . V_346 = V_60 -> V_323 ;
V_345 . V_328 = V_372 ;
V_345 . V_10 = V_10 ;
F_111 ( NULL , & V_345 ) ;
return 0 ;
}
static int F_129 ( struct V_143 * V_165 , int V_373 , void * V_374 )
{
struct V_1 * V_6 = V_374 ;
struct V_40 * V_348 ;
struct V_59 * V_307 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_43 ;
V_348 = F_76 ( V_165 ) ;
if ( F_93 ( V_348 ) )
return F_94 ( V_348 ) ;
V_307 = (struct V_59 * ) V_348 -> V_62 ;
V_307 -> V_319 = V_6 -> V_7 . V_375 ;
V_307 -> V_320 = V_376 ;
V_307 -> V_146 = F_55 ( V_165 -> V_195 . V_134 ) ;
V_307 -> V_64 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_63 = V_373 + 1 ;
V_307 -> V_323 = V_6 -> V_7 . V_377 ;
if ( V_6 -> V_7 . V_8 )
F_35 ( V_6 -> V_7 . V_8 , V_65 , V_58 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_348 ;
return 0 ;
}
static int F_130 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return F_131 ( V_10 , & V_6 -> V_7 . V_378 . V_200 , F_129 , ( void * ) V_6 ) ;
}
static void F_132 ( struct V_1 * V_6 )
{
F_133 ( & V_6 -> V_7 . V_378 . V_200 ) ;
}
static int F_134 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
T_7 V_134 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_379 ;
V_134 = F_54 ( V_60 -> V_146 ) ;
if ( V_134 == 0 )
return - V_72 ;
V_6 -> V_7 . V_375 = V_60 -> V_319 ;
V_6 -> V_7 . V_377 = V_60 -> V_323 ;
V_6 -> V_7 . V_7 = F_130 ;
V_6 -> V_7 . V_9 = F_132 ;
F_135 ( & V_6 -> V_7 . V_378 . V_200 , V_134 ) ;
return F_39 ( V_6 ) ;
}
static int F_136 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_125 = V_60 -> V_146 ;
bool V_380 = false ;
if ( V_60 -> V_74 == ( sizeof( * V_60 ) / sizeof( V_75 ) ) ) {
V_380 = true ;
if ( V_125 != 0 && V_125 != 1 )
return - V_72 ;
V_6 -> V_53 = V_125 ;
}
if ( V_380 && F_137 ( V_8 ) )
V_8 = F_138 ( V_8 , V_32 ) ;
else
V_8 = F_31 ( V_8 , V_32 ) ;
if ( V_380 && V_8 ) {
struct V_59 * V_381 = (struct V_59 * ) V_8 -> V_62 ;
V_381 -> V_64 = 0 ;
}
F_35 ( V_8 , V_32 , V_54 , NULL , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_139 ( struct V_382 * V_383 , int V_384 , int V_373 , void * V_374 )
{
int V_352 ;
T_6 V_269 = * ( T_6 * ) V_374 ;
for ( V_352 = 0 ; V_352 < V_383 -> V_385 ; V_352 ++ ) {
if ( V_383 -> V_386 [ V_352 ] . V_269 == V_269 )
return - V_364 ;
}
return 0 ;
}
static T_6 F_140 ( struct V_10 * V_10 )
{
struct V_387 V_388 ;
T_6 V_389 ;
int V_61 ;
static T_6 V_269 = V_390 ;
V_389 = V_269 ;
do {
++ V_269 ;
if ( V_269 == 0 )
V_269 = V_390 + 1 ;
F_141 ( & V_388 , V_391 ) ;
V_61 = V_387 ( V_10 , & V_388 , F_139 , ( void * ) & V_269 ) ;
F_142 ( & V_388 ) ;
if ( V_61 != - V_364 )
return V_269 ;
} while ( V_269 != V_389 );
return 0 ;
}
static int
F_143 ( struct V_382 * V_383 , struct V_392 * V_393 )
{
struct V_10 * V_10 = F_144 ( V_383 ) ;
struct V_394 * V_395 = V_383 -> V_386 + V_383 -> V_385 ;
int V_149 ;
if ( V_383 -> V_385 >= V_396 )
return - V_397 ;
if ( V_393 -> V_398 == 0 )
return - V_72 ;
V_395 -> V_195 . V_134 = V_393 -> V_399 ;
if ( ( V_149 = F_66 ( V_393 -> V_398 ) ) < 0 )
return - V_72 ;
V_395 -> V_149 = V_149 ;
if ( V_393 -> V_400 == V_401 )
V_395 -> V_402 = 1 ;
else if ( V_393 -> V_400 == V_403 ) {
V_395 -> V_269 = V_393 -> V_404 ;
if ( V_395 -> V_269 > V_390 )
V_395 -> V_269 = 0 ;
if ( ! V_395 -> V_269 && ! ( V_395 -> V_269 = F_140 ( V_10 ) ) )
return - V_43 ;
}
if ( V_395 -> V_149 == V_152 ) {
T_7 * V_136 = ( T_7 * ) ( V_393 + 1 ) ;
int V_135 , V_405 ;
V_135 = F_59 ( (struct V_79 * ) V_136 ,
& V_395 -> V_185 ) ;
if ( ! V_135 )
return - V_72 ;
V_405 = F_58 ( V_135 ) ;
if ( F_59 ( (struct V_79 * ) ( V_136 + V_405 ) ,
& V_395 -> V_195 . V_251 ) != V_135 )
return - V_72 ;
V_395 -> V_406 = V_135 ;
} else
V_395 -> V_406 = V_383 -> V_135 ;
V_395 -> V_407 = 1 ;
V_383 -> V_385 ++ ;
return 0 ;
}
static int
F_145 ( struct V_382 * V_383 , struct V_408 * V_409 )
{
int V_23 ;
int V_46 = V_409 -> V_410 * 8 - sizeof( struct V_408 ) ;
struct V_392 * V_393 = ( void * ) ( V_409 + 1 ) ;
while ( V_46 >= sizeof( struct V_392 ) ) {
if ( ( V_23 = F_143 ( V_383 , V_393 ) ) < 0 )
return V_23 ;
V_46 -= V_393 -> V_411 ;
V_393 = ( void * ) ( ( T_7 * ) V_393 + V_393 -> V_411 ) ;
}
return 0 ;
}
static inline int F_146 ( const struct V_382 * V_383 )
{
struct V_174 * V_175 = V_383 -> V_183 ;
if ( V_175 ) {
int V_46 = sizeof( struct V_90 ) ;
V_46 += V_175 -> V_104 ;
return F_64 ( V_46 ) ;
}
return 0 ;
}
static int F_147 ( const struct V_382 * V_383 )
{
const struct V_394 * V_395 ;
int V_179 = F_63 ( V_383 -> V_135 ) ;
int V_405 = 0 ;
int V_352 ;
for ( V_352 = 0 ; V_352 < V_383 -> V_385 ; V_352 ++ ) {
V_395 = V_383 -> V_386 + V_352 ;
V_405 += F_58 ( V_395 -> V_406 ) ;
}
return sizeof( struct V_59 ) +
( sizeof( struct V_168 ) * 3 ) +
( sizeof( struct V_77 ) * 2 ) +
( V_179 * 2 ) +
sizeof( struct V_408 ) +
( V_383 -> V_385 * sizeof( struct V_392 ) ) +
( V_405 * 2 ) +
F_146 ( V_383 ) ;
}
static struct V_40 * F_148 ( const struct V_382 * V_383 )
{
struct V_40 * V_8 ;
int V_176 ;
V_176 = F_147 ( V_383 ) ;
V_8 = F_42 ( V_176 + 16 , V_65 ) ;
if ( V_8 == NULL )
return F_69 ( - V_43 ) ;
return V_8 ;
}
static int F_149 ( struct V_40 * V_8 , const struct V_382 * V_383 , int V_384 )
{
struct V_59 * V_60 ;
struct V_77 * V_80 ;
struct V_168 * V_169 ;
struct V_408 * V_409 ;
struct V_90 * V_91 ;
struct V_174 * V_175 ;
int V_352 ;
int V_176 ;
int V_179 = F_63 ( V_383 -> V_135 ) ;
int V_405 = F_58 ( V_383 -> V_135 ) ;
V_176 = F_147 ( V_383 ) ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
memset ( V_60 , 0 , V_176 ) ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_179 ) ;
V_80 -> V_87 =
( sizeof( struct V_77 ) + V_179 ) /
sizeof( V_75 ) ;
V_80 -> V_248 = V_120 ;
V_80 -> V_249 = F_57 ( V_383 -> V_412 . V_134 ) ;
V_80 -> V_88 = V_383 -> V_412 . V_252 ;
V_80 -> V_250 = 0 ;
if ( ! F_67 ( & V_383 -> V_412 . V_185 ,
V_383 -> V_412 . V_253 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_383 -> V_135 ) )
F_75 () ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_179 ) ;
V_80 -> V_87 =
( sizeof( struct V_77 ) + V_179 ) /
sizeof( V_75 ) ;
V_80 -> V_248 = V_121 ;
V_80 -> V_249 = F_57 ( V_383 -> V_412 . V_134 ) ;
V_80 -> V_88 = V_383 -> V_412 . V_413 ;
V_80 -> V_250 = 0 ;
F_67 ( & V_383 -> V_412 . V_251 , V_383 -> V_412 . V_414 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_383 -> V_135 ) ;
V_169 = (struct V_168 * ) F_44 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_225 =
sizeof( struct V_168 ) / sizeof( V_75 ) ;
V_169 -> V_226 = V_227 ;
V_169 -> V_228 = F_74 ( V_383 -> V_229 . V_230 ) ;
V_169 -> V_231 = F_74 ( V_383 -> V_229 . V_232 ) ;
V_169 -> V_233 = V_383 -> V_229 . V_234 ;
V_169 -> V_235 = V_383 -> V_229 . V_236 ;
V_169 = (struct V_168 * ) F_44 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_225 =
sizeof( struct V_168 ) / sizeof( V_75 ) ;
V_169 -> V_226 = V_237 ;
V_169 -> V_228 = F_74 ( V_383 -> V_229 . V_238 ) ;
V_169 -> V_231 = F_74 ( V_383 -> V_229 . V_239 ) ;
V_169 -> V_233 = V_383 -> V_229 . V_240 ;
V_169 -> V_235 = V_383 -> V_229 . V_241 ;
V_169 = (struct V_168 * ) F_44 ( V_8 ,
sizeof( struct V_168 ) ) ;
V_169 -> V_225 =
sizeof( struct V_168 ) / sizeof( V_75 ) ;
V_169 -> V_226 = V_242 ;
V_169 -> V_228 = V_383 -> V_243 . V_244 ;
V_169 -> V_231 = V_383 -> V_243 . V_245 ;
V_169 -> V_233 = V_383 -> V_243 . V_246 ;
V_169 -> V_235 = V_383 -> V_243 . V_247 ;
V_409 = (struct V_408 * ) F_44 ( V_8 , sizeof( struct V_408 ) ) ;
V_409 -> V_410 = sizeof( struct V_408 ) / sizeof( V_75 ) ;
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
int V_149 ;
V_428 = sizeof( struct V_392 ) ;
if ( V_395 -> V_149 == V_152 ) {
V_405 = F_58 ( V_395 -> V_406 ) ;
V_428 += V_405 * 2 ;
} else {
V_176 -= 2 * V_405 ;
}
V_393 = ( void * ) F_44 ( V_8 , V_428 ) ;
V_409 -> V_410 += V_428 / 8 ;
memset ( V_393 , 0 , sizeof( * V_393 ) ) ;
V_393 -> V_411 = V_428 ;
V_393 -> V_399 = V_395 -> V_195 . V_134 ;
if ( ( V_149 = F_65 ( V_395 -> V_149 ) ) < 0 )
return - V_72 ;
V_393 -> V_398 = V_149 ;
V_393 -> V_400 = V_429 ;
if ( V_395 -> V_269 )
V_393 -> V_400 = V_403 ;
if ( V_395 -> V_402 )
V_393 -> V_400 = V_401 ;
V_393 -> V_404 = V_395 -> V_269 ;
if ( V_395 -> V_149 == V_152 ) {
T_7 * V_136 = ( void * ) ( V_393 + 1 ) ;
F_67 ( & V_395 -> V_185 , 0 ,
(struct V_79 * ) V_136 ,
V_395 -> V_406 ) ;
F_67 ( & V_395 -> V_195 . V_251 , 0 ,
(struct V_79 * ) ( V_136 + V_405 ) ,
V_395 -> V_406 ) ;
}
}
if ( ( V_175 = V_383 -> V_183 ) ) {
int V_97 = F_146 ( V_383 ) ;
V_91 = (struct V_90 * ) F_44 ( V_8 , V_97 ) ;
V_91 -> V_94 = V_97 / sizeof( V_75 ) ;
V_91 -> V_99 = V_124 ;
V_91 -> V_101 = V_175 -> V_100 ;
V_91 -> V_103 = V_175 -> V_102 ;
V_91 -> V_92 = V_175 -> V_104 ;
memcpy ( V_91 + 1 , V_175 -> V_285 ,
V_175 -> V_104 ) ;
}
V_60 -> V_74 = V_176 / sizeof( V_75 ) ;
V_60 -> V_322 = F_3 ( & V_383 -> V_430 ) ;
return 0 ;
}
static int F_150 ( struct V_382 * V_383 , int V_384 , const struct V_344 * V_345 )
{
struct V_40 * V_348 ;
struct V_59 * V_307 ;
int V_23 ;
V_348 = F_148 ( V_383 ) ;
if ( F_93 ( V_348 ) )
return F_94 ( V_348 ) ;
V_23 = F_149 ( V_348 , V_383 , V_384 ) ;
if ( V_23 < 0 )
return V_23 ;
V_307 = (struct V_59 * ) V_348 -> V_62 ;
V_307 -> V_319 = V_28 ;
if ( V_345 -> V_62 . V_431 && V_345 -> V_328 == V_329 )
V_307 -> V_320 = V_432 ;
else
V_307 -> V_320 = F_99 ( V_345 -> V_328 ) ;
V_307 -> V_64 = 0 ;
V_307 -> V_63 = V_345 -> V_303 ;
V_307 -> V_323 = V_345 -> V_346 ;
F_35 ( V_348 , V_65 , V_54 , NULL , F_144 ( V_383 ) ) ;
return 0 ;
}
static int F_151 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 = 0 ;
struct V_168 * V_169 ;
struct V_77 * V_136 ;
struct V_408 * V_409 ;
struct V_382 * V_383 ;
struct V_344 V_345 ;
struct V_90 * V_91 ;
if ( ! F_52 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_416 - 1 ] )
return - V_72 ;
V_409 = V_109 [ V_416 - 1 ] ;
if ( V_409 -> V_417 > V_421 )
return - V_72 ;
if ( ! V_409 -> V_423 || V_409 -> V_423 >= V_433 )
return - V_72 ;
V_383 = F_152 ( V_10 , V_32 ) ;
if ( V_383 == NULL )
return - V_43 ;
V_383 -> V_419 = ( V_409 -> V_417 == V_418 ?
V_434 : V_420 ) ;
V_383 -> V_427 = V_409 -> V_426 ;
V_136 = V_109 [ V_120 - 1 ] ,
V_383 -> V_135 = F_60 ( V_136 , & V_383 -> V_412 . V_185 ) ;
if ( ! V_383 -> V_135 ) {
V_23 = - V_72 ;
goto V_34;
}
V_383 -> V_412 . V_135 = V_383 -> V_135 ;
V_383 -> V_412 . V_252 = V_136 -> V_88 ;
V_383 -> V_412 . V_134 = F_56 ( V_136 -> V_249 ) ;
V_383 -> V_412 . V_253 = ( (struct V_81 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_383 -> V_412 . V_253 )
V_383 -> V_412 . V_435 = F_153 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ,
F_60 ( V_136 , & V_383 -> V_412 . V_251 ) ;
V_383 -> V_412 . V_413 = V_136 -> V_88 ;
V_383 -> V_412 . V_134 = F_56 ( V_136 -> V_249 ) ;
V_383 -> V_412 . V_414 = ( (struct V_81 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_383 -> V_412 . V_414 )
V_383 -> V_412 . V_436 = F_153 ( 0xffff ) ;
V_91 = V_109 [ V_124 - 1 ] ;
if ( V_91 != NULL ) {
struct V_95 * V_96 = F_50 ( V_91 ) ;
if ( ! V_96 ) {
V_23 = - V_43 ;
goto V_34;
}
V_23 = F_154 ( & V_383 -> V_183 , V_96 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
goto V_34;
}
V_383 -> V_229 . V_239 = V_437 ;
V_383 -> V_229 . V_232 = V_437 ;
V_383 -> V_229 . V_238 = V_437 ;
V_383 -> V_229 . V_230 = V_437 ;
if ( ( V_169 = V_109 [ V_227 - 1 ] ) != NULL ) {
V_383 -> V_229 . V_230 = F_80 ( V_169 -> V_228 ) ;
V_383 -> V_229 . V_232 = F_80 ( V_169 -> V_231 ) ;
V_383 -> V_229 . V_234 = V_169 -> V_233 ;
V_383 -> V_229 . V_236 = V_169 -> V_235 ;
}
if ( ( V_169 = V_109 [ V_237 - 1 ] ) != NULL ) {
V_383 -> V_229 . V_238 = F_80 ( V_169 -> V_228 ) ;
V_383 -> V_229 . V_239 = F_80 ( V_169 -> V_231 ) ;
V_383 -> V_229 . V_240 = V_169 -> V_233 ;
V_383 -> V_229 . V_241 = V_169 -> V_235 ;
}
V_383 -> V_385 = 0 ;
if ( V_409 -> V_417 == V_421 &&
( V_23 = F_145 ( V_383 , V_409 ) ) < 0 )
goto V_34;
V_23 = F_155 ( V_409 -> V_423 - 1 , V_383 ,
V_60 -> V_320 != V_334 ) ;
F_156 ( V_383 , V_23 ? 0 : 1 ,
F_108 ( V_347 ) ,
F_109 ( V_347 ) , 0 ) ;
if ( V_23 )
goto V_34;
if ( V_60 -> V_320 == V_334 )
V_345 . V_328 = V_333 ;
else
V_345 . V_328 = V_331 ;
V_345 . V_303 = V_60 -> V_63 ;
V_345 . V_346 = V_60 -> V_323 ;
F_157 ( V_383 , V_409 -> V_423 - 1 , & V_345 ) ;
F_158 ( V_383 ) ;
return 0 ;
V_34:
V_383 -> V_388 . V_438 = 1 ;
F_159 ( V_383 ) ;
return V_23 ;
}
static int F_160 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 ;
struct V_77 * V_136 ;
struct V_408 * V_409 ;
struct V_382 * V_383 ;
struct V_439 V_184 ;
struct V_344 V_345 ;
struct V_90 * V_91 ;
struct V_174 * V_440 = NULL ;
if ( ! F_52 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_416 - 1 ] )
return - V_72 ;
V_409 = V_109 [ V_416 - 1 ] ;
if ( ! V_409 -> V_423 || V_409 -> V_423 >= V_433 )
return - V_72 ;
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ,
V_184 . V_135 = F_60 ( V_136 , & V_184 . V_185 ) ;
V_184 . V_252 = V_136 -> V_88 ;
V_184 . V_134 = F_56 ( V_136 -> V_249 ) ;
V_184 . V_253 = ( (struct V_81 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_253 )
V_184 . V_435 = F_153 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ,
F_60 ( V_136 , & V_184 . V_251 ) ;
V_184 . V_413 = V_136 -> V_88 ;
V_184 . V_134 = F_56 ( V_136 -> V_249 ) ;
V_184 . V_414 = ( (struct V_81 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_414 )
V_184 . V_436 = F_153 ( 0xffff ) ;
V_91 = V_109 [ V_124 - 1 ] ;
if ( V_91 != NULL ) {
struct V_95 * V_96 = F_50 ( V_91 ) ;
if ( ! V_96 )
return - V_30 ;
V_23 = F_154 ( & V_440 , V_96 ) ;
F_82 ( V_96 ) ;
if ( V_23 )
return V_23 ;
}
V_383 = F_161 ( V_10 , V_147 , V_391 ,
V_409 -> V_423 - 1 , & V_184 , V_440 ,
1 , & V_23 ) ;
F_162 ( V_440 ) ;
if ( V_383 == NULL )
return - V_315 ;
F_163 ( V_383 , V_23 ? 0 : 1 ,
F_108 ( V_347 ) ,
F_109 ( V_347 ) , 0 ) ;
if ( V_23 )
goto V_34;
V_345 . V_303 = V_60 -> V_63 ;
V_345 . V_346 = V_60 -> V_323 ;
V_345 . V_62 . V_431 = 0 ;
V_345 . V_328 = V_329 ;
F_157 ( V_383 , V_409 -> V_423 - 1 , & V_345 ) ;
V_34:
F_158 ( V_383 ) ;
return V_23 ;
}
static int F_164 ( struct V_2 * V_3 , struct V_382 * V_383 , const struct V_59 * V_60 , int V_384 )
{
int V_23 ;
struct V_40 * V_348 ;
struct V_59 * V_307 ;
V_23 = 0 ;
V_348 = F_148 ( V_383 ) ;
if ( F_93 ( V_348 ) ) {
V_23 = F_94 ( V_348 ) ;
goto V_34;
}
V_23 = F_149 ( V_348 , V_383 , V_384 ) ;
if ( V_23 < 0 )
goto V_34;
V_307 = (struct V_59 * ) V_348 -> V_62 ;
V_307 -> V_319 = V_60 -> V_319 ;
V_307 -> V_320 = V_60 -> V_320 ;
V_307 -> V_146 = 0 ;
V_307 -> V_64 = 0 ;
V_307 -> V_63 = V_60 -> V_63 ;
V_307 -> V_323 = V_60 -> V_323 ;
F_35 ( V_348 , V_65 , V_58 , V_3 , F_144 ( V_383 ) ) ;
V_23 = 0 ;
V_34:
return V_23 ;
}
static int F_165 ( T_3 V_135 )
{
return F_64 ( F_58 ( V_135 ) * 2 ) ;
}
static int F_166 ( struct V_79 * V_136 , int V_113 ,
T_4 * V_185 , T_4 * V_251 ,
T_9 * V_135 )
{
int V_441 , V_405 ;
if ( V_113 < F_165 ( V_136 -> V_85 ) )
return - V_72 ;
V_441 = F_59 ( V_136 , V_185 ) ;
if ( ! V_441 )
return - V_72 ;
V_405 = F_58 ( V_441 ) ;
if ( F_59 ( (struct V_79 * ) ( ( ( T_7 * ) V_136 ) + V_405 ) ,
V_251 ) != V_441 )
return - V_72 ;
* V_135 = V_441 ;
return 0 ;
}
static int F_167 ( struct V_392 * V_442 , int V_46 ,
struct V_443 * V_444 )
{
int V_23 ;
struct V_392 * V_445 ;
int V_149 ;
if ( V_46 <= sizeof( struct V_392 ) ||
V_46 < V_442 -> V_411 )
return - V_72 ;
V_23 = F_166 ( (struct V_79 * ) ( V_442 + 1 ) ,
V_442 -> V_411 ,
& V_444 -> V_446 , & V_444 -> V_447 ,
& V_444 -> V_448 ) ;
if ( V_23 )
return V_23 ;
V_445 = (struct V_392 * ) ( ( T_7 * ) V_442 + V_442 -> V_411 ) ;
V_46 -= V_442 -> V_411 ;
if ( V_46 <= sizeof( struct V_392 ) ||
V_46 < V_445 -> V_411 )
return - V_72 ;
V_23 = F_166 ( (struct V_79 * ) ( V_445 + 1 ) ,
V_445 -> V_411 ,
& V_444 -> V_449 , & V_444 -> V_450 ,
& V_444 -> V_451 ) ;
if ( V_23 )
return V_23 ;
if ( V_442 -> V_399 != V_445 -> V_399 ||
V_442 -> V_398 != V_445 -> V_398 ||
V_442 -> V_404 != V_445 -> V_404 )
return - V_72 ;
V_444 -> V_134 = V_442 -> V_399 ;
if ( ( V_149 = F_66 ( V_442 -> V_398 ) ) < 0 )
return - V_72 ;
V_444 -> V_149 = V_149 ;
V_444 -> V_269 = V_442 -> V_404 ;
return ( ( int ) ( V_442 -> V_411 +
V_445 -> V_411 ) ) ;
}
static int F_168 ( struct V_2 * V_3 , struct V_40 * V_8 ,
const struct V_59 * V_60 , void * const * V_109 )
{
int V_352 , V_46 , V_452 , V_23 = - V_72 ;
T_7 V_384 ;
struct V_77 * V_136 ;
struct V_453 * V_454 ;
struct V_408 * V_409 ;
struct V_392 * V_393 ;
struct V_439 V_184 ;
struct V_443 V_444 [ V_396 ] ;
struct V_455 V_456 ;
if ( ! F_52 ( V_109 [ V_120 - 1 ] ,
V_109 [ V_121 - 1 ] ) ||
! V_109 [ V_416 - 1 ] ) {
V_23 = - V_72 ;
goto V_34;
}
V_454 = V_109 [ V_457 - 1 ] ;
V_409 = V_109 [ V_416 - 1 ] ;
if ( V_409 -> V_423 >= V_433 ) {
V_23 = - V_72 ;
goto V_34;
}
if ( V_454 ) {
V_456 . V_458 = V_454 -> V_459 ;
V_452 = F_166 ( (struct V_79 * ) ( V_454 + 1 ) ,
8 * ( V_454 -> V_460 ) - sizeof( * V_454 ) ,
& V_456 . V_461 , & V_456 . V_462 , & V_456 . V_135 ) ;
if ( V_452 < 0 ) {
V_23 = V_452 ;
goto V_34;
}
}
V_384 = V_409 -> V_423 - 1 ;
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
V_136 = V_109 [ V_120 - 1 ] ;
V_184 . V_135 = F_60 ( V_136 , & V_184 . V_185 ) ;
V_184 . V_252 = V_136 -> V_88 ;
V_184 . V_134 = F_56 ( V_136 -> V_249 ) ;
V_184 . V_253 = ( (struct V_81 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_253 )
V_184 . V_435 = F_153 ( 0xffff ) ;
V_136 = V_109 [ V_121 - 1 ] ,
F_60 ( V_136 , & V_184 . V_251 ) ;
V_184 . V_413 = V_136 -> V_88 ;
V_184 . V_134 = F_56 ( V_136 -> V_249 ) ;
V_184 . V_414 = ( (struct V_81 * ) ( V_136 + 1 ) ) -> V_159 ;
if ( V_184 . V_414 )
V_184 . V_436 = F_153 ( 0xffff ) ;
V_393 = (struct V_392 * ) ( V_409 + 1 ) ;
V_352 = 0 ;
V_46 = V_409 -> V_410 * 8 - sizeof( struct V_408 ) ;
while ( V_46 > 0 && V_352 < V_396 ) {
V_452 = F_167 ( V_393 , V_46 , & V_444 [ V_352 ] ) ;
if ( V_452 < 0 ) {
V_23 = V_452 ;
goto V_34;
} else {
V_393 = (struct V_392 * ) ( ( T_7 * ) V_393 + V_452 ) ;
V_46 -= V_452 ;
V_352 ++ ;
}
}
if ( ! V_352 || V_46 > 0 ) {
V_23 = - V_72 ;
goto V_34;
}
return V_443 ( & V_184 , V_384 , V_391 , V_444 , V_352 ,
V_454 ? & V_456 : NULL ) ;
V_34:
return V_23 ;
}
static int F_168 ( struct V_2 * V_3 , struct V_40 * V_8 ,
const struct V_59 * V_60 , void * const * V_109 )
{
return - V_463 ;
}
static int F_169 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_384 ;
int V_23 = 0 , V_464 ;
struct V_408 * V_409 ;
struct V_382 * V_383 ;
struct V_344 V_345 ;
if ( ( V_409 = V_109 [ V_416 - 1 ] ) == NULL )
return - V_72 ;
V_384 = F_170 ( V_409 -> V_424 ) ;
if ( V_384 >= V_465 )
return - V_72 ;
V_464 = ( V_60 -> V_320 == V_432 ) ;
V_383 = F_171 ( V_10 , V_147 , V_391 ,
V_384 , V_409 -> V_424 , V_464 , & V_23 ) ;
if ( V_383 == NULL )
return - V_315 ;
if ( V_464 ) {
F_163 ( V_383 , V_23 ? 0 : 1 ,
F_108 ( V_347 ) ,
F_109 ( V_347 ) , 0 ) ;
if ( V_23 )
goto V_34;
V_345 . V_303 = V_60 -> V_63 ;
V_345 . V_346 = V_60 -> V_323 ;
V_345 . V_62 . V_431 = 1 ;
V_345 . V_328 = V_329 ;
F_157 ( V_383 , V_384 , & V_345 ) ;
} else {
V_23 = F_164 ( V_3 , V_383 , V_60 , V_384 ) ;
}
V_34:
F_158 ( V_383 ) ;
return V_23 ;
}
static int F_172 ( struct V_382 * V_383 , int V_384 , int V_373 , void * V_374 )
{
struct V_1 * V_6 = V_374 ;
struct V_40 * V_348 ;
struct V_59 * V_307 ;
int V_23 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_43 ;
V_348 = F_148 ( V_383 ) ;
if ( F_93 ( V_348 ) )
return F_94 ( V_348 ) ;
V_23 = F_149 ( V_348 , V_383 , V_384 ) ;
if ( V_23 < 0 )
return V_23 ;
V_307 = (struct V_59 * ) V_348 -> V_62 ;
V_307 -> V_319 = V_6 -> V_7 . V_375 ;
V_307 -> V_320 = V_466 ;
V_307 -> V_146 = V_126 ;
V_307 -> V_64 = 0 ;
V_307 -> V_63 = V_373 + 1 ;
V_307 -> V_323 = V_6 -> V_7 . V_377 ;
if ( V_6 -> V_7 . V_8 )
F_35 ( V_6 -> V_7 . V_8 , V_65 , V_58 ,
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
F_142 ( & V_6 -> V_7 . V_378 . V_467 ) ;
}
static int F_175 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_379 ;
V_6 -> V_7 . V_375 = V_60 -> V_319 ;
V_6 -> V_7 . V_377 = V_60 -> V_323 ;
V_6 -> V_7 . V_7 = F_173 ;
V_6 -> V_7 . V_9 = F_174 ;
F_141 ( & V_6 -> V_7 . V_378 . V_467 , V_391 ) ;
return F_39 ( V_6 ) ;
}
static int F_176 ( const struct V_344 * V_345 )
{
struct V_40 * V_468 ;
struct V_59 * V_60 ;
V_468 = F_42 ( sizeof( struct V_59 ) + 16 , V_65 ) ;
if ( ! V_468 )
return - V_43 ;
V_60 = (struct V_59 * ) F_44 ( V_468 , sizeof( struct V_59 ) ) ;
V_60 -> V_320 = V_469 ;
V_60 -> V_63 = V_345 -> V_303 ;
V_60 -> V_323 = V_345 -> V_346 ;
V_60 -> V_319 = V_28 ;
V_60 -> V_64 = ( V_73 ) 0 ;
V_60 -> V_74 = ( sizeof( struct V_59 ) / sizeof( V_75 ) ) ;
F_35 ( V_468 , V_65 , V_54 , NULL , V_345 -> V_10 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_109 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_344 V_345 ;
struct V_367 V_368 ;
int V_23 , V_52 ;
V_368 . V_369 = F_108 ( V_347 ) ;
V_368 . V_370 = F_109 ( V_347 ) ;
V_368 . V_371 = 0 ;
V_23 = F_178 ( V_10 , V_391 , & V_368 ) ;
V_52 = F_125 ( V_3 , V_60 ) ;
if ( V_23 || V_52 ) {
if ( V_23 == - V_51 )
return 0 ;
return V_23 ;
}
V_345 . V_62 . type = V_391 ;
V_345 . V_328 = V_470 ;
V_345 . V_346 = V_60 -> V_323 ;
V_345 . V_303 = V_60 -> V_63 ;
V_345 . V_10 = V_10 ;
F_157 ( NULL , 0 , & V_345 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 )
{
void * V_109 [ V_117 ] ;
int V_23 ;
F_35 ( F_31 ( V_8 , V_32 ) , V_32 ,
V_55 , NULL , F_7 ( V_3 ) ) ;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
V_23 = F_53 ( V_8 , V_60 , V_109 ) ;
if ( ! V_23 ) {
V_23 = - V_305 ;
if ( V_471 [ V_60 -> V_320 ] )
V_23 = V_471 [ V_60 -> V_320 ] ( V_3 , V_8 , V_60 , V_109 ) ;
}
return V_23 ;
}
static struct V_59 * F_180 ( struct V_40 * V_8 , int * V_472 )
{
struct V_59 * V_60 = NULL ;
if ( V_8 -> V_46 < sizeof( * V_60 ) ) {
* V_472 = - V_473 ;
} else {
V_60 = (struct V_59 * ) V_8 -> V_62 ;
if ( V_60 -> V_319 != V_28 ||
V_60 -> V_322 != 0 ||
( V_60 -> V_320 <= V_474 ||
V_60 -> V_320 > V_475 ) ) {
V_60 = NULL ;
* V_472 = - V_72 ;
} else if ( V_60 -> V_74 != ( V_8 -> V_46 /
sizeof( V_75 ) ) ||
V_60 -> V_74 < ( sizeof( struct V_59 ) /
sizeof( V_75 ) ) ) {
V_60 = NULL ;
* V_472 = - V_473 ;
} else {
* V_472 = 0 ;
}
}
return V_60 ;
}
static inline int F_181 ( const struct V_394 * V_395 ,
const struct V_210 * V_476 )
{
unsigned int V_195 = V_476 -> V_213 . V_214 ;
if ( V_195 >= sizeof( V_395 -> V_477 ) * 8 )
return 0 ;
return ( V_395 -> V_477 >> V_195 ) & 1 ;
}
static inline int F_182 ( const struct V_394 * V_395 ,
const struct V_210 * V_476 )
{
unsigned int V_195 = V_476 -> V_213 . V_214 ;
if ( V_195 >= sizeof( V_395 -> V_478 ) * 8 )
return 0 ;
return ( V_395 -> V_478 >> V_195 ) & 1 ;
}
static int F_183 ( const struct V_394 * V_395 )
{
int V_352 , V_479 = 0 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_210 * V_186 = F_121 ( V_352 ) ;
if ( ! V_186 )
break;
if ( F_181 ( V_395 , V_186 ) && V_186 -> V_360 )
V_479 += sizeof( struct V_480 ) ;
}
return V_479 + sizeof( struct V_481 ) ;
}
static int F_184 ( const struct V_394 * V_395 )
{
int V_352 , V_456 , V_479 = 0 ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_210 * V_188 = F_122 ( V_352 ) ;
if ( ! V_188 )
break;
if ( ! ( F_182 ( V_395 , V_188 ) && V_188 -> V_360 ) )
continue;
for ( V_456 = 1 ; ; V_456 ++ ) {
const struct V_210 * V_186 = F_121 ( V_456 ) ;
if ( ! V_186 )
break;
if ( F_181 ( V_395 , V_186 ) && V_186 -> V_360 )
V_479 += sizeof( struct V_480 ) ;
}
}
return V_479 + sizeof( struct V_481 ) ;
}
static void F_185 ( struct V_40 * V_8 , const struct V_394 * V_395 )
{
struct V_481 * V_76 ;
int V_352 ;
V_76 = (struct V_481 * ) F_44 ( V_8 , sizeof( struct V_481 ) ) ;
V_76 -> V_482 = sizeof( struct V_481 ) / 8 ;
V_76 -> V_483 = V_484 ;
V_76 -> V_485 = 32 ;
memset ( V_76 -> V_486 , 0 , sizeof( V_76 -> V_486 ) ) ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_210 * V_186 = F_121 ( V_352 ) ;
if ( ! V_186 )
break;
if ( F_181 ( V_395 , V_186 ) && V_186 -> V_360 ) {
struct V_480 * V_345 ;
V_345 = (struct V_480 * ) F_44 ( V_8 , sizeof( struct V_480 ) ) ;
memset ( V_345 , 0 , sizeof( * V_345 ) ) ;
V_76 -> V_482 += sizeof( struct V_480 ) / 8 ;
V_345 -> V_487 = V_186 -> V_213 . V_214 ;
V_345 -> V_488 = V_186 -> V_213 . V_489 ;
V_345 -> V_490 = V_186 -> V_213 . V_491 ;
V_345 -> V_492 = 24 * 60 * 60 ;
V_345 -> V_493 = 20 * 60 * 60 ;
V_345 -> V_494 = 8 * 60 * 60 ;
V_345 -> V_495 = 7 * 60 * 60 ;
}
}
}
static void F_186 ( struct V_40 * V_8 , const struct V_394 * V_395 )
{
struct V_481 * V_76 ;
int V_352 , V_456 ;
V_76 = (struct V_481 * ) F_44 ( V_8 , sizeof( struct V_481 ) ) ;
V_76 -> V_482 = sizeof( struct V_481 ) / 8 ;
V_76 -> V_483 = V_484 ;
V_76 -> V_485 = 32 ;
memset ( V_76 -> V_486 , 0 , sizeof( V_76 -> V_486 ) ) ;
for ( V_352 = 0 ; ; V_352 ++ ) {
const struct V_210 * V_188 = F_122 ( V_352 ) ;
if ( ! V_188 )
break;
if ( ! ( F_182 ( V_395 , V_188 ) && V_188 -> V_360 ) )
continue;
for ( V_456 = 1 ; ; V_456 ++ ) {
struct V_480 * V_345 ;
const struct V_210 * V_186 = F_121 ( V_456 ) ;
if ( ! V_186 )
break;
if ( ! ( F_181 ( V_395 , V_186 ) && V_186 -> V_360 ) )
continue;
V_345 = (struct V_480 * ) F_44 ( V_8 , sizeof( struct V_480 ) ) ;
memset ( V_345 , 0 , sizeof( * V_345 ) ) ;
V_76 -> V_482 += sizeof( struct V_480 ) / 8 ;
V_345 -> V_487 = V_186 -> V_213 . V_214 ;
V_345 -> V_488 = V_186 -> V_213 . V_489 ;
V_345 -> V_490 = V_186 -> V_213 . V_491 ;
V_345 -> V_496 = V_188 -> V_213 . V_214 ;
V_345 -> V_497 = V_188 -> V_213 . V_489 ;
V_345 -> V_498 = V_188 -> V_213 . V_491 ;
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
static int F_188 ( struct V_143 * V_165 , const struct V_344 * V_345 )
{
struct V_40 * V_348 ;
struct V_59 * V_307 ;
int V_499 ;
int V_167 ;
V_499 = V_345 -> V_62 . V_499 ;
if ( V_499 )
V_167 = 2 ;
else
V_167 = 1 ;
V_348 = F_77 ( V_165 , V_167 ) ;
if ( F_93 ( V_348 ) )
return F_94 ( V_348 ) ;
V_307 = (struct V_59 * ) V_348 -> V_62 ;
V_307 -> V_319 = V_28 ;
V_307 -> V_320 = V_343 ;
V_307 -> V_146 = F_55 ( V_165 -> V_195 . V_134 ) ;
V_307 -> V_64 = 0 ;
V_307 -> V_322 = 0 ;
V_307 -> V_63 = 0 ;
V_307 -> V_323 = 0 ;
F_35 ( V_348 , V_65 , V_56 , NULL , F_102 ( V_165 ) ) ;
return 0 ;
}
static int F_189 ( struct V_143 * V_165 , const struct V_344 * V_345 )
{
struct V_10 * V_10 = V_165 ? F_102 ( V_165 ) : V_345 -> V_10 ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
if ( F_3 ( & V_12 -> V_17 ) == 0 )
return 0 ;
switch ( V_345 -> V_328 ) {
case V_342 :
return F_188 ( V_165 , V_345 ) ;
case V_336 :
case V_338 :
case V_340 :
return F_101 ( V_165 , V_345 ) ;
case V_372 :
return F_126 ( V_345 ) ;
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
return F_150 ( V_383 , V_384 , V_345 ) ;
case V_470 :
if ( V_345 -> V_62 . type != V_391 )
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
static int F_193 ( struct V_143 * V_165 , struct V_394 * V_395 , struct V_382 * V_383 , int V_384 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
struct V_77 * V_80 ;
struct V_408 * V_409 ;
int V_179 ;
int V_176 ;
struct V_90 * V_91 ;
struct V_174 * V_175 ;
int V_97 = 0 ;
V_179 = F_63 ( V_165 -> V_182 . V_135 ) ;
if ( ! V_179 )
return - V_72 ;
V_176 = sizeof( struct V_59 ) +
( sizeof( struct V_77 ) * 2 ) +
( V_179 * 2 ) +
sizeof( struct V_408 ) ;
if ( V_165 -> V_195 . V_134 == V_129 )
V_176 += F_183 ( V_395 ) ;
else if ( V_165 -> V_195 . V_134 == V_131 )
V_176 += F_184 ( V_395 ) ;
if ( ( V_175 = V_165 -> V_183 ) ) {
V_97 = F_64 ( V_175 -> V_104 ) ;
V_176 += sizeof( struct V_90 ) + V_97 ;
}
V_8 = F_42 ( V_176 + 16 , V_65 ) ;
if ( V_8 == NULL )
return - V_30 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_319 = V_28 ;
V_60 -> V_320 = V_503 ;
V_60 -> V_146 = F_55 ( V_165 -> V_195 . V_134 ) ;
V_60 -> V_74 = V_176 / sizeof( V_75 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_322 = 0 ;
V_60 -> V_63 = V_165 -> V_199 . V_303 = F_191 () ;
V_60 -> V_323 = 0 ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_179 ) ;
V_80 -> V_87 =
( sizeof( struct V_77 ) + V_179 ) /
sizeof( V_75 ) ;
V_80 -> V_248 = V_120 ;
V_80 -> V_249 = 0 ;
V_80 -> V_250 = 0 ;
V_80 -> V_88 =
F_67 ( & V_165 -> V_182 . V_185 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_80 -> V_88 )
F_75 () ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_179 ) ;
V_80 -> V_87 =
( sizeof( struct V_77 ) + V_179 ) /
sizeof( V_75 ) ;
V_80 -> V_248 = V_121 ;
V_80 -> V_249 = 0 ;
V_80 -> V_250 = 0 ;
V_80 -> V_88 =
F_67 ( & V_165 -> V_195 . V_251 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_80 -> V_88 )
F_75 () ;
V_409 = (struct V_408 * ) F_44 ( V_8 , sizeof( struct V_408 ) ) ;
V_409 -> V_410 = sizeof( struct V_408 ) / sizeof( V_75 ) ;
V_409 -> V_415 = V_416 ;
V_409 -> V_417 = V_421 ;
V_409 -> V_423 = V_384 + 1 ;
V_409 -> V_424 = V_383 -> V_425 ;
if ( V_165 -> V_195 . V_134 == V_129 )
F_185 ( V_8 , V_395 ) ;
else if ( V_165 -> V_195 . V_134 == V_131 )
F_186 ( V_8 , V_395 ) ;
if ( V_175 ) {
V_91 = (struct V_90 * ) F_44 ( V_8 ,
sizeof( struct V_90 ) + V_97 ) ;
V_91 -> V_94 =
( sizeof( struct V_90 ) + V_97 ) / sizeof( V_75 ) ;
V_91 -> V_99 = V_124 ;
V_91 -> V_101 = V_175 -> V_100 ;
V_91 -> V_103 = V_175 -> V_102 ;
V_91 -> V_92 = V_175 -> V_104 ;
memcpy ( V_91 + 1 , V_175 -> V_285 ,
V_175 -> V_104 ) ;
}
return F_35 ( V_8 , V_65 , V_56 , NULL , F_102 ( V_165 ) ) ;
}
static struct V_382 * F_194 ( struct V_2 * V_3 , int V_504 ,
T_7 * V_62 , int V_46 , int * V_384 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_382 * V_383 ;
struct V_408 * V_409 = (struct V_408 * ) V_62 ;
struct V_90 * V_91 ;
switch ( V_3 -> V_37 ) {
case V_86 :
if ( V_504 != V_505 ) {
* V_384 = - V_305 ;
return NULL ;
}
break;
#if F_46 ( V_82 )
case V_89 :
if ( V_504 != V_506 ) {
* V_384 = - V_305 ;
return NULL ;
}
break;
#endif
default:
* V_384 = - V_72 ;
return NULL ;
}
* V_384 = - V_72 ;
if ( V_46 < sizeof( struct V_408 ) ||
V_409 -> V_410 * 8 > V_46 ||
V_409 -> V_417 > V_507 ||
( ! V_409 -> V_423 || V_409 -> V_423 > V_508 ) )
return NULL ;
V_383 = F_152 ( V_10 , V_65 ) ;
if ( V_383 == NULL ) {
* V_384 = - V_43 ;
return NULL ;
}
V_383 -> V_419 = ( V_409 -> V_417 == V_418 ?
V_434 : V_420 ) ;
V_383 -> V_229 . V_239 = V_437 ;
V_383 -> V_229 . V_232 = V_437 ;
V_383 -> V_229 . V_238 = V_437 ;
V_383 -> V_229 . V_230 = V_437 ;
V_383 -> V_135 = V_3 -> V_37 ;
V_383 -> V_385 = 0 ;
if ( V_409 -> V_417 == V_421 &&
( * V_384 = F_145 ( V_383 , V_409 ) ) < 0 )
goto V_34;
if ( V_46 >= ( V_409 -> V_410 * 8 +
sizeof( struct V_90 ) ) ) {
char * V_76 = ( char * ) V_409 ;
struct V_95 * V_96 ;
V_76 += V_409 -> V_410 * 8 ;
V_91 = (struct V_90 * ) V_76 ;
if ( V_46 < V_409 -> V_410 * 8 +
V_91 -> V_94 ) {
* V_384 = - V_72 ;
goto V_34;
}
if ( ( * V_384 = F_49 ( V_76 ) ) )
goto V_34;
V_96 = F_50 ( V_91 ) ;
* V_384 = F_154 ( & V_383 -> V_183 , V_96 ) ;
F_82 ( V_96 ) ;
if ( * V_384 )
goto V_34;
}
* V_384 = V_409 -> V_423 - 1 ;
return V_383 ;
V_34:
V_383 -> V_388 . V_438 = 1 ;
F_159 ( V_383 ) ;
return NULL ;
}
static int F_195 ( struct V_143 * V_165 , T_4 * V_509 , T_5 V_253 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
struct V_144 * V_136 ;
struct V_77 * V_80 ;
struct V_192 * V_271 ;
int V_179 ;
int V_176 ;
T_8 V_125 = ( V_165 -> V_195 . V_134 == V_131 ? V_130 : 0 ) ;
struct V_180 * V_181 = NULL ;
V_179 = F_63 ( V_165 -> V_182 . V_135 ) ;
if ( ! V_179 )
return - V_72 ;
if ( ! V_125 )
return - V_72 ;
if ( ! V_165 -> V_189 )
return - V_72 ;
V_181 = V_165 -> V_189 ;
V_176 = sizeof( struct V_59 ) +
sizeof( struct V_144 ) +
( sizeof( struct V_77 ) * 2 ) +
( V_179 * 2 ) +
( sizeof( struct V_192 ) * 2 ) ;
V_8 = F_42 ( V_176 + 16 , V_65 ) ;
if ( V_8 == NULL )
return - V_30 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_319 = V_28 ;
V_60 -> V_320 = V_510 ;
V_60 -> V_146 = V_125 ;
V_60 -> V_74 = V_176 / sizeof( V_75 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_322 = 0 ;
V_60 -> V_63 = V_165 -> V_199 . V_303 = F_191 () ;
V_60 -> V_323 = 0 ;
V_136 = (struct V_144 * ) F_44 ( V_8 , sizeof( struct V_144 ) ) ;
V_136 -> V_193 = sizeof( struct V_144 ) / sizeof( V_75 ) ;
V_136 -> V_194 = V_145 ;
V_136 -> V_148 = V_165 -> V_195 . V_196 ;
V_136 -> V_197 = 0 ;
V_136 -> V_202 = 0 ;
V_136 -> V_209 = 0 ;
V_136 -> V_215 = 0 ;
V_136 -> V_217 = 0 ;
V_80 = (struct V_77 * )
F_44 ( V_8 , sizeof( struct V_77 ) + V_179 ) ;
V_80 -> V_87 =
( sizeof( struct V_77 ) + V_179 ) /
sizeof( V_75 ) ;
V_80 -> V_248 = V_120 ;
V_80 -> V_249 = 0 ;
V_80 -> V_250 = 0 ;
V_80 -> V_88 =
F_67 ( & V_165 -> V_182 . V_185 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_80 -> V_88 )
F_75 () ;
V_271 = (struct V_192 * ) F_44 ( V_8 , sizeof ( * V_271 ) ) ;
V_271 -> V_277 = sizeof( * V_271 ) / sizeof( V_75 ) ;
V_271 -> V_278 = V_279 ;
V_271 -> V_280 = V_181 -> V_281 ;
V_271 -> V_282 = 0 ;
V_80 = (struct V_77 * )
F_44 ( V_8 , sizeof( struct V_77 ) + V_179 ) ;
V_80 -> V_87 =
( sizeof( struct V_77 ) + V_179 ) /
sizeof( V_75 ) ;
V_80 -> V_248 = V_121 ;
V_80 -> V_249 = 0 ;
V_80 -> V_250 = 0 ;
V_80 -> V_88 =
F_67 ( V_509 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_165 -> V_182 . V_135 ) ;
if ( ! V_80 -> V_88 )
F_75 () ;
V_271 = (struct V_192 * ) F_44 ( V_8 , sizeof ( * V_271 ) ) ;
V_271 -> V_277 = sizeof( * V_271 ) / sizeof( V_75 ) ;
V_271 -> V_278 = V_283 ;
V_271 -> V_280 = V_253 ;
V_271 -> V_282 = 0 ;
return F_35 ( V_8 , V_65 , V_56 , NULL , F_102 ( V_165 ) ) ;
}
static int F_196 ( struct V_40 * V_8 , int V_511 , int type ,
const struct V_439 * V_184 )
{
struct V_77 * V_80 ;
V_80 = (struct V_77 * ) F_44 ( V_8 , sizeof( struct V_77 ) + V_511 ) ;
V_80 -> V_87 = ( sizeof( struct V_77 ) + V_511 ) / 8 ;
V_80 -> V_248 = type ;
V_80 -> V_249 = V_184 -> V_134 ;
V_80 -> V_250 = 0 ;
switch ( type ) {
case V_120 :
V_80 -> V_88 = V_184 -> V_252 ;
F_67 ( & V_184 -> V_185 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_184 -> V_135 ) ;
break;
case V_121 :
V_80 -> V_88 = V_184 -> V_413 ;
F_67 ( & V_184 -> V_251 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_184 -> V_135 ) ;
break;
default:
return - V_72 ;
}
return 0 ;
}
static int F_197 ( struct V_40 * V_8 , const struct V_455 * V_456 )
{
struct V_453 * V_454 ;
T_7 * V_136 ;
int V_135 = V_456 -> V_135 ;
int V_405 = F_58 ( V_135 ) ;
int V_512 ;
V_512 = ( sizeof( struct V_453 ) +
F_165 ( V_135 ) ) ;
V_454 = (struct V_453 * ) F_44 ( V_8 , V_512 ) ;
memset ( V_454 , 0 , V_512 ) ;
V_454 -> V_460 = V_512 / 8 ;
V_454 -> V_513 = V_457 ;
V_454 -> V_459 = V_456 -> V_458 ;
V_136 = ( T_7 * ) ( V_454 + 1 ) ;
if ( ! F_67 ( & V_456 -> V_461 , 0 , (struct V_79 * ) V_136 , V_135 ) ||
! F_67 ( & V_456 -> V_462 , 0 , (struct V_79 * ) ( V_136 + V_405 ) , V_135 ) )
return - V_72 ;
return 0 ;
}
static int F_198 ( struct V_40 * V_8 ,
V_73 V_134 , V_73 V_149 , int V_514 ,
T_11 V_269 , V_73 V_135 ,
const T_4 * V_105 , const T_4 * V_106 )
{
struct V_392 * V_393 ;
T_7 * V_136 ;
int V_405 = F_58 ( V_135 ) ;
int V_512 ;
V_512 = sizeof( struct V_392 ) +
F_165 ( V_135 ) ;
V_393 = (struct V_392 * ) F_44 ( V_8 , V_512 ) ;
memset ( V_393 , 0 , V_512 ) ;
V_393 -> V_411 = V_512 ;
V_393 -> V_399 = V_134 ;
V_393 -> V_398 = V_149 ;
V_393 -> V_400 = V_514 ;
V_393 -> V_404 = V_269 ;
V_136 = ( T_7 * ) ( V_393 + 1 ) ;
if ( ! F_67 ( V_105 , 0 , (struct V_79 * ) V_136 , V_135 ) ||
! F_67 ( V_106 , 0 , (struct V_79 * ) ( V_136 + V_405 ) , V_135 ) )
return - V_72 ;
return 0 ;
}
static int F_199 ( const struct V_439 * V_184 , T_7 V_384 , T_7 type ,
const struct V_443 * V_444 , int V_515 ,
const struct V_455 * V_456 )
{
int V_352 ;
int V_516 ;
int V_176 = 0 ;
int V_517 = 0 ;
struct V_40 * V_8 ;
struct V_59 * V_60 ;
struct V_408 * V_409 ;
const struct V_443 * V_518 ;
if ( type != V_391 )
return 0 ;
if ( V_515 <= 0 || V_515 > V_396 )
return - V_72 ;
if ( V_456 != NULL ) {
V_176 += F_64 ( sizeof( struct V_453 ) +
F_165 ( V_456 -> V_135 ) ) ;
}
V_516 = F_63 ( V_184 -> V_135 ) ;
if ( ! V_516 )
return - V_72 ;
V_176 += ( sizeof( struct V_77 ) + V_516 ) * 2 ;
V_517 += sizeof( struct V_408 ) ;
for ( V_352 = 0 , V_518 = V_444 ; V_352 < V_515 ; V_352 ++ , V_518 ++ ) {
V_517 += sizeof( struct V_392 ) +
F_165 ( V_518 -> V_448 ) ;
V_517 += sizeof( struct V_392 ) +
F_165 ( V_518 -> V_451 ) ;
}
V_176 += sizeof( struct V_59 ) + V_517 ;
V_8 = F_42 ( V_176 , V_65 ) ;
if ( V_8 == NULL )
return - V_30 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_319 = V_28 ;
V_60 -> V_320 = V_519 ;
V_60 -> V_146 = F_55 ( V_444 -> V_134 ) ;
V_60 -> V_74 = V_176 / 8 ;
V_60 -> V_64 = 0 ;
V_60 -> V_322 = 0 ;
V_60 -> V_63 = 0 ;
V_60 -> V_323 = 0 ;
if ( V_456 != NULL && ( F_197 ( V_8 , V_456 ) < 0 ) )
goto V_23;
F_196 ( V_8 , V_516 , V_120 , V_184 ) ;
F_196 ( V_8 , V_516 , V_121 , V_184 ) ;
V_409 = (struct V_408 * ) F_44 ( V_8 , sizeof( struct V_408 ) ) ;
V_409 -> V_410 = V_517 / 8 ;
V_409 -> V_415 = V_416 ;
V_409 -> V_417 = V_421 ;
V_409 -> V_423 = V_384 + 1 ;
V_409 -> V_424 = 0 ;
V_409 -> V_426 = 0 ;
for ( V_352 = 0 , V_518 = V_444 ; V_352 < V_515 ; V_352 ++ , V_518 ++ ) {
int V_149 = F_65 ( V_518 -> V_149 ) ;
if ( V_149 < 0 )
goto V_23;
if ( F_198 ( V_8 , V_518 -> V_134 , V_149 ,
( V_518 -> V_269 ? V_403 : V_429 ) ,
V_518 -> V_269 , V_518 -> V_448 ,
& V_518 -> V_446 , & V_518 -> V_447 ) < 0 )
goto V_23;
if ( F_198 ( V_8 , V_518 -> V_134 , V_149 ,
( V_518 -> V_269 ? V_403 : V_429 ) ,
V_518 -> V_269 , V_518 -> V_451 ,
& V_518 -> V_449 , & V_518 -> V_450 ) < 0 )
goto V_23;
}
F_35 ( V_8 , V_65 , V_54 , NULL , & V_520 ) ;
return 0 ;
V_23:
F_5 ( V_8 ) ;
return - V_72 ;
}
static int F_199 ( const struct V_439 * V_184 , T_7 V_384 , T_7 type ,
const struct V_443 * V_444 , int V_515 ,
const struct V_455 * V_456 )
{
return - V_463 ;
}
static int F_200 ( struct V_521 * V_521 ,
struct V_20 * V_2 , struct V_522 * V_523 , T_12 V_46 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_40 * V_8 = NULL ;
struct V_59 * V_60 = NULL ;
int V_23 ;
V_23 = - V_305 ;
if ( V_523 -> V_524 & V_525 )
goto V_34;
V_23 = - V_473 ;
if ( ( unsigned ) V_46 > V_3 -> V_526 - 32 )
goto V_34;
V_23 = - V_43 ;
V_8 = F_42 ( V_46 , V_32 ) ;
if ( V_8 == NULL )
goto V_34;
V_23 = - V_527 ;
if ( F_201 ( F_44 ( V_8 , V_46 ) , V_523 -> V_528 , V_46 ) )
goto V_34;
V_60 = F_180 ( V_8 , & V_23 ) ;
if ( ! V_60 )
goto V_34;
F_15 ( & V_529 ) ;
V_23 = F_179 ( V_3 , V_8 , V_60 ) ;
F_17 ( & V_529 ) ;
V_34:
if ( V_23 && V_60 && F_41 ( V_60 , V_23 , V_3 ) == 0 )
V_23 = 0 ;
F_5 ( V_8 ) ;
return V_23 ? : V_46 ;
}
static int F_202 ( struct V_521 * V_521 ,
struct V_20 * V_2 , struct V_522 * V_523 , T_12 V_46 ,
int V_218 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_40 * V_8 ;
int V_530 , V_23 ;
V_23 = - V_72 ;
if ( V_218 & ~ ( V_531 | V_532 | V_533 | V_534 ) )
goto V_34;
V_523 -> V_535 = 0 ;
V_8 = F_203 ( V_3 , V_218 , V_218 & V_532 , & V_23 ) ;
if ( V_8 == NULL )
goto V_34;
V_530 = V_8 -> V_46 ;
if ( V_530 > V_46 ) {
V_523 -> V_524 |= V_533 ;
V_530 = V_46 ;
}
F_204 ( V_8 ) ;
V_23 = F_205 ( V_8 , 0 , V_523 -> V_528 , V_530 ) ;
if ( V_23 )
goto V_536;
F_206 ( V_523 , V_3 , V_8 ) ;
V_23 = ( V_218 & V_533 ) ? V_8 -> V_46 : V_530 ;
if ( V_6 -> V_7 . V_7 != NULL &&
3 * F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 )
F_39 ( V_6 ) ;
V_536:
F_207 ( V_3 , V_8 ) ;
V_34:
return V_23 ;
}
static int F_208 ( struct V_537 * V_538 , void * V_539 )
{
struct V_2 * V_540 = F_209 ( V_539 ) ;
if ( V_539 == V_541 )
F_210 ( V_538 , L_4 ) ;
else
F_210 ( V_538 , L_5 ,
V_540 ,
F_3 ( & V_540 -> V_542 ) ,
F_211 ( V_540 ) ,
F_212 ( V_540 ) ,
F_213 ( V_540 ) ,
F_214 ( V_540 )
) ;
return 0 ;
}
static void * F_215 ( struct V_537 * V_538 , T_13 * V_543 )
__acquires( T_14 )
{
struct V_10 * V_10 = F_216 ( V_538 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_36 () ;
return F_217 ( & V_12 -> V_19 , * V_543 ) ;
}
static void * F_218 ( struct V_537 * V_538 , void * V_539 , T_13 * V_543 )
{
struct V_10 * V_10 = F_216 ( V_538 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
return F_219 ( V_539 , & V_12 -> V_19 , V_543 ) ;
}
static void F_220 ( struct V_537 * V_538 , void * V_539 )
__releases( T_14 )
{
F_38 () ;
}
static int F_221 ( struct V_544 * V_544 , struct V_545 * V_545 )
{
return F_222 ( V_544 , V_545 , & V_546 ,
sizeof( struct V_547 ) ) ;
}
static int T_15 F_223 ( struct V_10 * V_10 )
{
struct V_548 * V_549 ;
V_549 = F_224 ( V_10 , L_6 , 0 , & V_550 ) ;
if ( V_549 == NULL )
return - V_30 ;
return 0 ;
}
static void T_16 F_225 ( struct V_10 * V_10 )
{
F_226 ( V_10 , L_6 ) ;
}
static inline int F_223 ( struct V_10 * V_10 )
{
return 0 ;
}
static inline void F_225 ( struct V_10 * V_10 )
{
}
static int T_15 F_227 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
int V_551 ;
F_228 ( & V_12 -> V_19 ) ;
F_229 ( & V_12 -> V_17 , 0 ) ;
V_551 = F_223 ( V_10 ) ;
return V_551 ;
}
static void T_16 F_230 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_225 ( V_10 ) ;
F_43 ( ! F_231 ( & V_12 -> V_19 ) ) ;
}
static void T_17 F_232 ( void )
{
F_233 ( & V_552 ) ;
F_234 ( V_31 ) ;
F_235 ( & V_553 ) ;
F_236 ( & V_33 ) ;
}
static int T_18 F_237 ( void )
{
int V_23 = F_238 ( & V_33 , 0 ) ;
if ( V_23 != 0 )
goto V_34;
V_23 = F_239 ( & V_553 ) ;
if ( V_23 != 0 )
goto V_554;
V_23 = F_240 ( & V_555 ) ;
if ( V_23 != 0 )
goto V_556;
V_23 = F_241 ( & V_552 ) ;
if ( V_23 != 0 )
goto V_557;
V_34:
return V_23 ;
V_557:
F_234 ( V_31 ) ;
V_556:
F_235 ( & V_553 ) ;
V_554:
F_236 ( & V_33 ) ;
goto V_34;
}
