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
#if F_46 ( V_82 ) || F_46 ( V_83 )
const struct V_84 * V_85 ;
#endif
int V_46 ;
switch ( V_80 -> V_86 ) {
case V_87 :
V_46 = F_47 ( sizeof( * V_78 ) + sizeof( * sin ) , sizeof( V_75 ) ) ;
if ( V_78 -> V_88 != V_46 ||
V_78 -> V_89 > 32 )
return - V_72 ;
break;
#if F_46 ( V_82 ) || F_46 ( V_83 )
case V_90 :
V_46 = F_47 ( sizeof( * V_78 ) + sizeof( * V_85 ) , sizeof( V_75 ) ) ;
if ( V_78 -> V_88 != V_46 ||
V_78 -> V_89 > 128 )
return - V_72 ;
break;
#endif
default:
return - V_72 ;
break;
}
return 0 ;
}
static inline int F_48 ( const struct V_91 * V_92 )
{
return F_47 ( sizeof( struct V_91 ) +
V_92 -> V_93 ,
sizeof( V_75 ) ) ;
}
static inline int F_49 ( const void * V_76 )
{
const struct V_91 * V_92 = V_76 ;
int V_46 = V_92 -> V_93 ;
if ( V_46 > V_94 )
return - V_72 ;
V_46 = F_48 ( V_92 ) ;
if ( V_92 -> V_95 != V_46 )
return - V_72 ;
return 0 ;
}
static inline struct V_96 * F_50 ( const struct V_91 * V_92 )
{
struct V_96 * V_97 = NULL ;
int V_98 = V_92 -> V_93 ;
V_97 = F_51 ( ( sizeof( * V_97 ) + V_98 ) , V_32 ) ;
if ( ! V_97 )
return NULL ;
V_97 -> V_46 = F_48 ( V_92 ) ;
V_97 -> V_99 = V_92 -> V_100 ;
V_97 -> V_101 = V_92 -> V_102 ;
V_97 -> V_103 = V_92 -> V_104 ;
V_97 -> V_105 = V_92 -> V_93 ;
memcpy ( V_97 + 1 , V_92 + 1 ,
V_97 -> V_105 ) ;
return V_97 ;
}
static int F_52 ( const struct V_77 * V_106 ,
const struct V_77 * V_107 )
{
const struct V_79 * V_108 , * V_109 ;
if ( ! V_106 || ! V_107 )
return 0 ;
V_108 = ( const struct V_79 * ) ( V_106 + 1 ) ;
V_109 = ( const struct V_79 * ) ( V_107 + 1 ) ;
if ( V_108 -> V_86 != V_109 -> V_86 )
return 0 ;
if ( V_108 -> V_86 != V_87
#if F_46 ( V_82 ) || F_46 ( V_83 )
&& V_108 -> V_86 != V_90
#endif
)
return 0 ;
return 1 ;
}
static int F_53 ( struct V_40 * V_8 , const struct V_59 * V_60 , void * * V_110 )
{
const char * V_76 = ( char * ) V_60 ;
int V_46 = V_8 -> V_46 ;
V_46 -= sizeof( * V_60 ) ;
V_76 += sizeof( * V_60 ) ;
while ( V_46 > 0 ) {
const struct V_111 * V_112 = ( const struct V_111 * ) V_76 ;
T_2 V_113 ;
int V_114 ;
V_114 = V_112 -> V_115 ;
V_114 *= sizeof( V_75 ) ;
V_113 = V_112 -> V_116 ;
if ( V_114 < sizeof( V_75 ) ||
V_114 > V_46 ||
V_113 == V_117 )
return - V_72 ;
if ( V_113 <= V_118 ) {
int V_119 = ( int ) V_120 [ V_113 ] ;
if ( V_114 < V_119 )
return - V_72 ;
if ( V_110 [ V_113 - 1 ] != NULL )
return - V_72 ;
if ( V_113 == V_121 ||
V_113 == V_122 ||
V_113 == V_123 ||
V_113 == V_124 ) {
if ( F_45 ( V_76 ) )
return - V_72 ;
}
if ( V_113 == V_125 ) {
if ( F_49 ( V_76 ) )
return - V_72 ;
}
V_110 [ V_113 - 1 ] = ( void * ) V_76 ;
}
V_76 += V_114 ;
V_46 -= V_114 ;
}
return 0 ;
}
static T_2
F_54 ( V_73 V_126 )
{
switch ( V_126 ) {
case V_127 :
return V_128 ;
case V_129 :
return V_130 ;
case V_131 :
return V_132 ;
case V_133 :
return V_134 ;
break;
default:
return 0 ;
}
}
static V_73
F_55 ( T_2 V_135 )
{
switch ( V_135 ) {
case V_130 :
return V_129 ;
case V_132 :
return V_131 ;
case V_134 :
return V_133 ;
break;
default:
return 0 ;
}
}
static V_73 F_56 ( V_73 V_135 )
{
return V_135 == V_128 ? 0 : V_135 ;
}
static V_73 F_57 ( V_73 V_135 )
{
return V_135 ? V_135 : V_128 ;
}
static inline int F_58 ( T_3 V_136 )
{
switch ( V_136 ) {
case V_87 :
return sizeof( struct V_81 ) ;
#if F_46 ( V_82 ) || F_46 ( V_83 )
case V_90 :
return sizeof( struct V_84 ) ;
#endif
}
return 0 ;
}
static
int F_59 ( const struct V_79 * V_137 , T_4 * V_138 )
{
switch ( V_137 -> V_86 ) {
case V_87 :
V_138 -> V_139 =
( (struct V_81 * ) V_137 ) -> V_140 . V_108 ;
return V_87 ;
#if F_46 ( V_82 ) || F_46 ( V_83 )
case V_90 :
memcpy ( V_138 -> V_141 ,
& ( (struct V_84 * ) V_137 ) -> V_142 ,
sizeof( struct V_143 ) ) ;
return V_90 ;
#endif
}
return 0 ;
}
static
int F_60 ( const struct V_77 * V_80 , T_4 * V_138 )
{
return F_59 ( (struct V_79 * ) ( V_80 + 1 ) ,
V_138 ) ;
}
static struct V_144 * F_61 ( struct V_10 * V_10 , const struct V_59 * V_60 , void * const * V_110 )
{
const struct V_145 * V_137 ;
const struct V_77 * V_80 ;
T_2 V_135 ;
unsigned short V_136 ;
T_4 * V_138 ;
V_137 = ( const struct V_145 * ) V_110 [ V_146 - 1 ] ;
if ( V_137 == NULL )
return NULL ;
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 )
return NULL ;
V_80 = ( const struct V_77 * ) V_110 [ V_122 - 1 ] ;
if ( V_80 == NULL )
return NULL ;
V_136 = ( ( const struct V_79 * ) ( V_80 + 1 ) ) -> V_86 ;
switch ( V_136 ) {
case V_87 :
V_138 = ( T_4 * ) & ( ( const struct V_81 * ) ( V_80 + 1 ) ) -> V_140 ;
break;
#if F_46 ( V_82 ) || F_46 ( V_83 )
case V_90 :
V_138 = ( T_4 * ) & ( ( const struct V_84 * ) ( V_80 + 1 ) ) -> V_142 ;
break;
#endif
default:
V_138 = NULL ;
}
if ( ! V_138 )
return NULL ;
return F_62 ( V_10 , V_148 , V_138 , V_137 -> V_149 , V_135 , V_136 ) ;
}
static int
F_63 ( T_3 V_136 )
{
return F_64 ( F_58 ( V_136 ) ) ;
}
static inline int F_65 ( int V_150 )
{
switch( V_150 ) {
case V_151 :
return V_152 ;
case V_153 :
return V_154 ;
case V_155 :
return V_156 ;
default:
return - 1 ;
}
}
static inline int F_66 ( int V_150 )
{
switch( V_150 ) {
case V_157 :
case V_152 :
return V_151 ;
case V_154 :
return V_153 ;
case V_156 :
return V_155 ;
default:
return - 1 ;
}
}
static unsigned int F_67 ( const T_4 * V_138 , T_5 V_158 ,
struct V_79 * V_137 ,
unsigned short V_136 )
{
switch ( V_136 ) {
case V_87 :
{
struct V_81 * sin = (struct V_81 * ) V_137 ;
sin -> V_159 = V_87 ;
sin -> V_160 = V_158 ;
sin -> V_140 . V_108 = V_138 -> V_139 ;
memset ( sin -> V_161 , 0 , sizeof( sin -> V_161 ) ) ;
return 32 ;
}
#if F_46 ( V_82 ) || F_46 ( V_83 )
case V_90 :
{
struct V_84 * V_85 = (struct V_84 * ) V_137 ;
V_85 -> V_162 = V_90 ;
V_85 -> V_163 = V_158 ;
V_85 -> V_164 = 0 ;
F_68 ( & V_85 -> V_142 , ( const struct V_143 * ) V_138 -> V_141 ) ;
V_85 -> V_165 = 0 ;
return 128 ;
}
#endif
}
return 0 ;
}
static struct V_40 * F_69 ( const struct V_144 * V_166 ,
int V_167 , int V_168 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
struct V_145 * V_137 ;
struct V_169 * V_170 ;
struct V_77 * V_80 ;
struct V_171 * V_172 ;
struct V_173 * V_174 ;
struct V_91 * V_92 ;
struct V_175 * V_176 ;
int V_98 = 0 ;
int V_177 ;
int V_178 = 0 ;
int V_179 = 0 ;
int V_180 ;
struct V_181 * V_182 = NULL ;
int V_150 ;
V_180 = F_63 ( V_166 -> V_183 . V_136 ) ;
if ( ! V_180 )
return F_70 ( - V_72 ) ;
V_177 = sizeof( struct V_59 ) + sizeof( struct V_145 ) +
sizeof( struct V_169 ) +
( ( V_168 & 1 ) ? sizeof( struct V_169 ) : 0 ) +
( ( V_168 & 2 ) ? sizeof( struct V_169 ) : 0 ) +
sizeof( struct V_77 ) * 2 +
V_180 * 2 +
sizeof( struct V_173 ) ;
if ( ( V_176 = V_166 -> V_184 ) ) {
V_98 = F_64 ( V_176 -> V_105 ) ;
V_177 += sizeof( struct V_91 ) + V_98 ;
}
if ( F_71 ( & V_166 -> V_185 . V_186 , & V_166 -> V_183 . V_186 , V_166 -> V_183 . V_136 ) )
V_177 += sizeof( struct V_77 ) + V_180 ;
if ( V_167 ) {
if ( V_166 -> V_187 && V_166 -> V_187 -> V_188 ) {
V_178 =
F_64 ( ( V_166 -> V_187 -> V_188 + 7 ) / 8 ) ;
V_177 += sizeof( struct V_171 ) + V_178 ;
}
if ( V_166 -> V_189 && V_166 -> V_189 -> V_188 ) {
V_179 =
F_64 ( ( V_166 -> V_189 -> V_188 + 7 ) / 8 ) ;
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
V_8 = F_42 ( V_177 + 16 , V_65 ) ;
if ( V_8 == NULL )
return F_70 ( - V_43 ) ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
memset ( V_60 , 0 , V_177 ) ;
V_60 -> V_74 = V_177 / sizeof( V_75 ) ;
V_137 = (struct V_145 * ) F_44 ( V_8 , sizeof( struct V_145 ) ) ;
V_137 -> V_194 = sizeof( struct V_145 ) / sizeof( V_75 ) ;
V_137 -> V_195 = V_146 ;
V_137 -> V_149 = V_166 -> V_196 . V_197 ;
V_137 -> V_198 = V_166 -> V_183 . V_199 ;
switch ( V_166 -> V_200 . V_201 ) {
case V_202 :
V_137 -> V_203 = V_166 -> V_200 . V_204 ?
V_205 : V_206 ;
break;
case V_207 :
V_137 -> V_203 = V_208 ;
break;
default:
V_137 -> V_203 = V_209 ;
break;
}
V_137 -> V_210 = 0 ;
if ( V_166 -> V_187 ) {
struct V_211 * V_212 = F_72 ( V_166 -> V_187 -> V_213 , 0 ) ;
V_137 -> V_210 = V_212 ? V_212 -> V_214 . V_215 : 0 ;
}
V_137 -> V_216 = 0 ;
F_43 ( V_166 -> V_189 && V_166 -> V_217 ) ;
if ( V_166 -> V_189 ) {
struct V_211 * V_212 = F_73 ( V_166 -> V_189 -> V_213 , 0 ) ;
V_137 -> V_216 = V_212 ? V_212 -> V_214 . V_215 : 0 ;
}
if ( V_166 -> V_217 ) {
struct V_211 * V_212 = F_74 ( V_166 -> V_217 -> V_213 , 0 ) ;
V_137 -> V_216 = V_212 ? V_212 -> V_214 . V_215 : 0 ;
}
V_137 -> V_218 = 0 ;
if ( V_166 -> V_183 . V_219 & V_220 )
V_137 -> V_218 |= V_221 ;
if ( V_166 -> V_183 . V_219 & V_222 )
V_137 -> V_218 |= V_223 ;
if ( V_166 -> V_183 . V_219 & V_224 )
V_137 -> V_218 |= V_225 ;
if ( V_168 & 2 ) {
V_170 = (struct V_169 * ) F_44 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_226 =
sizeof( struct V_169 ) / sizeof( V_75 ) ;
V_170 -> V_227 = V_228 ;
V_170 -> V_229 = F_75 ( V_166 -> V_230 . V_231 ) ;
V_170 -> V_232 = F_75 ( V_166 -> V_230 . V_233 ) ;
V_170 -> V_234 = V_166 -> V_230 . V_235 ;
V_170 -> V_236 = V_166 -> V_230 . V_237 ;
}
if ( V_168 & 1 ) {
V_170 = (struct V_169 * ) F_44 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_226 =
sizeof( struct V_169 ) / sizeof( V_75 ) ;
V_170 -> V_227 = V_238 ;
V_170 -> V_229 = F_75 ( V_166 -> V_230 . V_239 ) ;
V_170 -> V_232 = F_75 ( V_166 -> V_230 . V_240 ) ;
V_170 -> V_234 = V_166 -> V_230 . V_241 ;
V_170 -> V_236 = V_166 -> V_230 . V_242 ;
}
V_170 = (struct V_169 * ) F_44 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_226 =
sizeof( struct V_169 ) / sizeof( V_75 ) ;
V_170 -> V_227 = V_243 ;
V_170 -> V_229 = V_166 -> V_244 . V_245 ;
V_170 -> V_232 = V_166 -> V_244 . V_246 ;
V_170 -> V_234 = V_166 -> V_244 . V_247 ;
V_170 -> V_236 = V_166 -> V_244 . V_248 ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_180 ) ;
V_80 -> V_88 =
( sizeof( struct V_77 ) + V_180 ) /
sizeof( V_75 ) ;
V_80 -> V_249 = V_121 ;
V_80 -> V_250 = 0 ;
V_80 -> V_251 = 0 ;
V_80 -> V_89 =
F_67 ( & V_166 -> V_183 . V_186 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_166 -> V_183 . V_136 ) ;
if ( ! V_80 -> V_89 )
F_76 () ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_180 ) ;
V_80 -> V_88 =
( sizeof( struct V_77 ) + V_180 ) /
sizeof( V_75 ) ;
V_80 -> V_249 = V_122 ;
V_80 -> V_250 = 0 ;
V_80 -> V_251 = 0 ;
V_80 -> V_89 =
F_67 ( & V_166 -> V_196 . V_252 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_166 -> V_183 . V_136 ) ;
if ( ! V_80 -> V_89 )
F_76 () ;
if ( F_71 ( & V_166 -> V_185 . V_186 , & V_166 -> V_183 . V_186 ,
V_166 -> V_183 . V_136 ) ) {
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_180 ) ;
V_80 -> V_88 =
( sizeof( struct V_77 ) + V_180 ) /
sizeof( V_75 ) ;
V_80 -> V_249 = V_123 ;
V_80 -> V_250 =
F_57 ( V_166 -> V_185 . V_135 ) ;
V_80 -> V_89 = V_166 -> V_185 . V_253 ;
V_80 -> V_251 = 0 ;
F_67 ( & V_166 -> V_185 . V_186 , V_166 -> V_185 . V_254 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_166 -> V_183 . V_136 ) ;
}
if ( V_167 && V_178 ) {
V_172 = (struct V_171 * ) F_44 ( V_8 ,
sizeof( struct V_171 ) + V_178 ) ;
V_172 -> V_255 = ( sizeof( struct V_171 ) + V_178 ) /
sizeof( V_75 ) ;
V_172 -> V_256 = V_257 ;
V_172 -> V_258 = V_166 -> V_187 -> V_188 ;
V_172 -> V_259 = 0 ;
memcpy ( V_172 + 1 , V_166 -> V_187 -> V_260 , ( V_166 -> V_187 -> V_188 + 7 ) / 8 ) ;
}
if ( V_167 && V_179 ) {
V_172 = (struct V_171 * ) F_44 ( V_8 ,
sizeof( struct V_171 ) + V_179 ) ;
V_172 -> V_255 = ( sizeof( struct V_171 ) +
V_179 ) / sizeof( V_75 ) ;
V_172 -> V_256 = V_261 ;
V_172 -> V_258 = V_166 -> V_189 -> V_188 ;
V_172 -> V_259 = 0 ;
memcpy ( V_172 + 1 , V_166 -> V_189 -> V_260 ,
( V_166 -> V_189 -> V_188 + 7 ) / 8 ) ;
}
V_174 = (struct V_173 * ) F_44 ( V_8 , sizeof( struct V_173 ) ) ;
V_174 -> V_262 = sizeof( struct V_173 ) / sizeof( V_75 ) ;
V_174 -> V_263 = V_264 ;
if ( ( V_150 = F_65 ( V_166 -> V_183 . V_150 ) ) < 0 ) {
F_5 ( V_8 ) ;
return F_70 ( - V_72 ) ;
}
V_174 -> V_265 = V_150 ;
V_174 -> V_266 = 0 ;
V_174 -> V_267 = 0 ;
V_174 -> V_268 = 0 ;
V_174 -> V_269 = V_166 -> V_183 . V_270 ;
if ( V_182 && V_182 -> V_191 ) {
struct V_192 * V_271 ;
struct V_193 * V_272 ;
V_271 = (struct V_192 * ) F_44 ( V_8 , sizeof( * V_271 ) ) ;
V_271 -> V_273 = sizeof( * V_271 ) / sizeof( V_75 ) ;
V_271 -> V_274 = V_275 ;
V_271 -> V_276 = V_182 -> V_191 ;
V_271 -> V_277 [ 0 ] = 0 ;
V_271 -> V_277 [ 1 ] = 0 ;
V_271 -> V_277 [ 2 ] = 0 ;
V_272 = (struct V_193 * ) F_44 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_75 ) ;
V_272 -> V_279 = V_280 ;
V_272 -> V_281 = V_182 -> V_282 ;
V_272 -> V_283 = 0 ;
V_272 = (struct V_193 * ) F_44 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_75 ) ;
V_272 -> V_279 = V_284 ;
V_272 -> V_281 = V_182 -> V_285 ;
V_272 -> V_283 = 0 ;
}
if ( V_176 ) {
V_92 = (struct V_91 * ) F_44 ( V_8 ,
sizeof( struct V_91 ) + V_98 ) ;
V_92 -> V_95 =
( sizeof( struct V_91 ) + V_98 ) / sizeof( V_75 ) ;
V_92 -> V_100 = V_125 ;
V_92 -> V_102 = V_176 -> V_101 ;
V_92 -> V_104 = V_176 -> V_103 ;
V_92 -> V_93 = V_176 -> V_105 ;
memcpy ( V_92 + 1 , V_176 -> V_286 ,
V_176 -> V_105 ) ;
}
return V_8 ;
}
static inline struct V_40 * F_77 ( const struct V_144 * V_166 )
{
struct V_40 * V_8 ;
V_8 = F_69 ( V_166 , 1 , 3 ) ;
return V_8 ;
}
static inline struct V_40 * F_78 ( const struct V_144 * V_166 ,
int V_168 )
{
return F_69 ( V_166 , 0 , V_168 ) ;
}
static struct V_144 * F_79 ( struct V_10 * V_10 ,
const struct V_59 * V_60 ,
void * const * V_110 )
{
struct V_144 * V_166 ;
const struct V_169 * V_170 ;
const struct V_145 * V_137 ;
const struct V_171 * V_172 ;
const struct V_91 * V_92 ;
T_2 V_135 ;
int V_23 ;
V_137 = ( const struct V_145 * ) V_110 [ V_146 - 1 ] ;
if ( ! V_137 ||
! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) )
return F_70 ( - V_72 ) ;
if ( V_60 -> V_147 == V_131 &&
! V_110 [ V_261 - 1 ] )
return F_70 ( - V_72 ) ;
if ( V_60 -> V_147 == V_129 &&
! V_110 [ V_257 - 1 ] )
return F_70 ( - V_72 ) ;
if ( ! ! V_110 [ V_228 - 1 ] !=
! ! V_110 [ V_238 - 1 ] )
return F_70 ( - V_72 ) ;
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 )
return F_70 ( - V_72 ) ;
V_23 = - V_43 ;
if ( V_137 -> V_210 > V_287 ||
( V_60 -> V_147 == V_133 &&
V_137 -> V_216 > V_288 ) ||
V_137 -> V_216 > V_289 )
return F_70 ( - V_72 ) ;
V_172 = ( const struct V_171 * ) V_110 [ V_257 - 1 ] ;
if ( V_172 != NULL &&
V_137 -> V_210 != V_290 &&
( ( V_172 -> V_258 + 7 ) / 8 == 0 ||
( V_172 -> V_258 + 7 ) / 8 > V_172 -> V_255 * sizeof( V_75 ) ) )
return F_70 ( - V_72 ) ;
V_172 = V_110 [ V_261 - 1 ] ;
if ( V_172 != NULL &&
V_137 -> V_216 != V_291 &&
( ( V_172 -> V_258 + 7 ) / 8 == 0 ||
( V_172 -> V_258 + 7 ) / 8 > V_172 -> V_255 * sizeof( V_75 ) ) )
return F_70 ( - V_72 ) ;
V_166 = F_80 ( V_10 ) ;
if ( V_166 == NULL )
return F_70 ( - V_43 ) ;
V_166 -> V_196 . V_135 = V_135 ;
V_166 -> V_196 . V_197 = V_137 -> V_149 ;
V_166 -> V_183 . V_199 = V_137 -> V_198 ;
if ( V_137 -> V_218 & V_221 )
V_166 -> V_183 . V_219 |= V_220 ;
if ( V_137 -> V_218 & V_223 )
V_166 -> V_183 . V_219 |= V_222 ;
if ( V_137 -> V_218 & V_225 )
V_166 -> V_183 . V_219 |= V_224 ;
V_170 = ( const struct V_169 * ) V_110 [ V_228 - 1 ] ;
if ( V_170 != NULL ) {
V_166 -> V_230 . V_231 = F_81 ( V_170 -> V_229 ) ;
V_166 -> V_230 . V_233 = F_81 ( V_170 -> V_232 ) ;
V_166 -> V_230 . V_235 = V_170 -> V_234 ;
V_166 -> V_230 . V_237 = V_170 -> V_236 ;
}
V_170 = ( const struct V_169 * ) V_110 [ V_238 - 1 ] ;
if ( V_170 != NULL ) {
V_166 -> V_230 . V_239 = F_81 ( V_170 -> V_229 ) ;
V_166 -> V_230 . V_240 = F_81 ( V_170 -> V_232 ) ;
V_166 -> V_230 . V_241 = V_170 -> V_234 ;
V_166 -> V_230 . V_242 = V_170 -> V_236 ;
}
V_92 = ( const struct V_91 * ) V_110 [ V_125 - 1 ] ;
if ( V_92 != NULL ) {
struct V_96 * V_97 = F_50 ( V_92 ) ;
if ( ! V_97 )
goto V_34;
V_23 = F_82 ( V_166 , V_97 ) ;
F_83 ( V_97 ) ;
if ( V_23 )
goto V_34;
}
V_172 = ( const struct V_171 * ) V_110 [ V_257 - 1 ] ;
if ( V_137 -> V_210 ) {
int V_292 = 0 ;
struct V_211 * V_212 = F_84 ( V_137 -> V_210 ) ;
if ( ! V_212 ) {
V_23 = - V_293 ;
goto V_34;
}
if ( V_172 )
V_292 = ( V_172 -> V_258 + 7 ) / 8 ;
V_166 -> V_187 = F_51 ( sizeof( * V_166 -> V_187 ) + V_292 , V_32 ) ;
if ( ! V_166 -> V_187 )
goto V_34;
strcpy ( V_166 -> V_187 -> V_213 , V_212 -> V_294 ) ;
V_166 -> V_187 -> V_188 = 0 ;
if ( V_172 ) {
V_166 -> V_187 -> V_188 = V_172 -> V_258 ;
memcpy ( V_166 -> V_187 -> V_260 , V_172 + 1 , V_292 ) ;
}
V_166 -> V_187 -> V_295 = V_212 -> V_296 . V_297 . V_298 ;
V_166 -> V_183 . V_299 = V_137 -> V_210 ;
}
if ( V_137 -> V_216 ) {
if ( V_60 -> V_147 == V_133 ) {
struct V_211 * V_212 = F_85 ( V_137 -> V_216 ) ;
if ( ! V_212 ) {
V_23 = - V_293 ;
goto V_34;
}
V_166 -> V_217 = F_51 ( sizeof( * V_166 -> V_217 ) , V_32 ) ;
if ( ! V_166 -> V_217 )
goto V_34;
strcpy ( V_166 -> V_217 -> V_213 , V_212 -> V_294 ) ;
V_166 -> V_183 . V_300 = V_137 -> V_216 ;
} else {
int V_292 = 0 ;
struct V_211 * V_212 = F_86 ( V_137 -> V_216 ) ;
if ( ! V_212 ) {
V_23 = - V_293 ;
goto V_34;
}
V_172 = (struct V_171 * ) V_110 [ V_261 - 1 ] ;
if ( V_172 )
V_292 = ( V_172 -> V_258 + 7 ) / 8 ;
V_166 -> V_189 = F_51 ( sizeof( * V_166 -> V_189 ) + V_292 , V_32 ) ;
if ( ! V_166 -> V_189 )
goto V_34;
strcpy ( V_166 -> V_189 -> V_213 , V_212 -> V_294 ) ;
V_166 -> V_189 -> V_188 = 0 ;
if ( V_172 ) {
V_166 -> V_189 -> V_188 = V_172 -> V_258 ;
memcpy ( V_166 -> V_189 -> V_260 , V_172 + 1 , V_292 ) ;
}
V_166 -> V_183 . V_301 = V_137 -> V_216 ;
}
}
V_166 -> V_183 . V_136 = F_60 ( (struct V_77 * ) V_110 [ V_121 - 1 ] ,
& V_166 -> V_183 . V_186 ) ;
if ( ! V_166 -> V_183 . V_136 ) {
V_23 = - V_302 ;
goto V_34;
}
F_60 ( (struct V_77 * ) V_110 [ V_122 - 1 ] ,
& V_166 -> V_196 . V_252 ) ;
if ( V_110 [ V_264 - 1 ] ) {
const struct V_173 * V_174 = V_110 [ V_264 - 1 ] ;
int V_150 = F_66 ( V_174 -> V_265 ) ;
if ( V_150 < 0 ) {
V_23 = - V_72 ;
goto V_34;
}
V_166 -> V_183 . V_150 = V_150 ;
V_166 -> V_183 . V_270 = V_174 -> V_269 ;
}
if ( V_110 [ V_123 - 1 ] ) {
const struct V_77 * V_80 = V_110 [ V_123 - 1 ] ;
V_166 -> V_185 . V_136 = F_60 ( V_80 , & V_166 -> V_185 . V_186 ) ;
V_166 -> V_185 . V_253 = V_80 -> V_89 ;
}
if ( ! V_166 -> V_185 . V_136 )
V_166 -> V_185 . V_136 = V_166 -> V_183 . V_136 ;
if ( V_110 [ V_275 - 1 ] ) {
const struct V_192 * V_271 ;
struct V_181 * V_182 ;
V_166 -> V_190 = F_51 ( sizeof( * V_166 -> V_190 ) , V_32 ) ;
if ( ! V_166 -> V_190 )
goto V_34;
V_182 = V_166 -> V_190 ;
V_271 = V_110 [ V_275 - 1 ] ;
V_182 -> V_191 = V_271 -> V_276 ;
if ( V_110 [ V_280 - 1 ] ) {
const struct V_193 * V_272 =
V_110 [ V_280 - 1 ] ;
V_182 -> V_282 = V_272 -> V_281 ;
}
if ( V_110 [ V_284 - 1 ] ) {
const struct V_193 * V_272 =
V_110 [ V_284 - 1 ] ;
V_182 -> V_285 = V_272 -> V_281 ;
}
memset ( & V_182 -> V_303 , 0 , sizeof( V_182 -> V_303 ) ) ;
}
V_23 = F_87 ( V_166 ) ;
if ( V_23 )
goto V_34;
V_166 -> V_200 . V_304 = V_60 -> V_63 ;
return V_166 ;
V_34:
V_166 -> V_200 . V_201 = V_305 ;
F_88 ( V_166 ) ;
return F_70 ( V_23 ) ;
}
static int F_89 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
return - V_306 ;
}
static int F_90 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_40 * V_307 ;
struct V_173 * V_174 ;
struct V_77 * V_186 , * V_252 ;
struct V_59 * V_308 ;
struct V_309 * V_310 ;
struct V_144 * V_166 = NULL ;
int V_150 ;
int V_23 ;
T_6 V_311 , V_312 ;
T_6 V_270 ;
T_7 V_135 ;
unsigned short V_136 ;
T_4 * V_313 = NULL , * V_314 = NULL ;
if ( ! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) )
return - V_72 ;
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 )
return - V_72 ;
if ( ( V_174 = V_110 [ V_264 - 1 ] ) != NULL ) {
V_150 = F_66 ( V_174 -> V_265 ) ;
if ( V_150 < 0 )
return - V_72 ;
V_270 = V_174 -> V_269 ;
} else {
V_150 = 0 ;
V_270 = 0 ;
}
V_186 = V_110 [ V_121 - 1 ] ;
V_252 = V_110 [ V_122 - 1 ] ;
V_136 = ( (struct V_79 * ) ( V_186 + 1 ) ) -> V_86 ;
switch ( V_136 ) {
case V_87 :
V_314 = ( T_4 * ) & ( (struct V_81 * ) ( V_252 + 1 ) ) -> V_140 . V_108 ;
V_313 = ( T_4 * ) & ( (struct V_81 * ) ( V_186 + 1 ) ) -> V_140 . V_108 ;
break;
#if F_46 ( V_82 ) || F_46 ( V_83 )
case V_90 :
V_314 = ( T_4 * ) & ( (struct V_84 * ) ( V_252 + 1 ) ) -> V_142 ;
V_313 = ( T_4 * ) & ( (struct V_84 * ) ( V_186 + 1 ) ) -> V_142 ;
break;
#endif
}
if ( V_60 -> V_63 ) {
V_166 = F_91 ( V_10 , V_148 , V_60 -> V_63 ) ;
if ( V_166 && F_71 ( & V_166 -> V_196 . V_252 , V_314 , V_136 ) ) {
F_88 ( V_166 ) ;
V_166 = NULL ;
}
}
if ( ! V_166 )
V_166 = F_92 ( V_10 , & V_315 , V_150 , V_270 , V_135 , V_314 , V_313 , 1 , V_136 ) ;
if ( V_166 == NULL )
return - V_316 ;
V_311 = 0x100 ;
V_312 = 0x0fffffff ;
V_310 = V_110 [ V_317 - 1 ] ;
if ( V_310 ) {
V_311 = V_310 -> V_318 ;
V_312 = V_310 -> V_319 ;
}
V_23 = F_93 ( V_166 , V_311 , V_312 ) ;
V_307 = V_23 ? F_70 ( V_23 ) : F_77 ( V_166 ) ;
if ( F_94 ( V_307 ) ) {
F_88 ( V_166 ) ;
return F_95 ( V_307 ) ;
}
V_308 = (struct V_59 * ) V_307 -> V_62 ;
V_308 -> V_320 = V_60 -> V_320 ;
V_308 -> V_321 = V_322 ;
V_308 -> V_147 = F_55 ( V_135 ) ;
V_308 -> V_64 = 0 ;
V_308 -> V_323 = 0 ;
V_308 -> V_63 = V_60 -> V_63 ;
V_308 -> V_324 = V_60 -> V_324 ;
F_88 ( V_166 ) ;
F_35 ( V_307 , V_32 , V_58 , V_3 , V_10 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_144 * V_166 ;
if ( V_60 -> V_74 != sizeof( struct V_59 ) / 8 )
return - V_306 ;
if ( V_60 -> V_63 == 0 || V_60 -> V_64 == 0 )
return 0 ;
V_166 = F_91 ( V_10 , V_148 , V_60 -> V_63 ) ;
if ( V_166 == NULL )
return 0 ;
F_97 ( & V_166 -> V_325 ) ;
if ( V_166 -> V_200 . V_201 == V_207 ) {
V_166 -> V_200 . V_201 = V_326 ;
F_98 ( & V_10 -> V_327 . V_328 ) ;
}
F_99 ( & V_166 -> V_325 ) ;
F_88 ( V_166 ) ;
return 0 ;
}
static inline int F_100 ( int V_329 )
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
static inline int F_101 ( int V_329 )
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
static int F_102 ( struct V_144 * V_166 , const struct V_345 * V_346 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
V_8 = F_77 ( V_166 ) ;
if ( F_94 ( V_8 ) )
return F_95 ( V_8 ) ;
V_60 = (struct V_59 * ) V_8 -> V_62 ;
V_60 -> V_320 = V_28 ;
V_60 -> V_321 = F_101 ( V_346 -> V_329 ) ;
V_60 -> V_147 = F_55 ( V_166 -> V_196 . V_135 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_323 = 0 ;
V_60 -> V_63 = V_346 -> V_304 ;
V_60 -> V_324 = V_346 -> V_347 ;
F_35 ( V_8 , V_65 , V_54 , NULL , F_103 ( V_166 ) ) ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_144 * V_166 ;
int V_23 ;
struct V_345 V_346 ;
V_166 = F_79 ( V_10 , V_60 , V_110 ) ;
if ( F_94 ( V_166 ) )
return F_95 ( V_166 ) ;
F_105 ( V_166 ) ;
if ( V_60 -> V_321 == V_340 )
V_23 = F_106 ( V_166 ) ;
else
V_23 = F_107 ( V_166 ) ;
F_108 ( V_166 , V_23 ? 0 : 1 ,
F_109 ( V_348 ) ,
F_110 ( V_348 ) , 0 ) ;
if ( V_23 < 0 ) {
V_166 -> V_200 . V_201 = V_305 ;
F_111 ( V_166 ) ;
goto V_34;
}
if ( V_60 -> V_321 == V_340 )
V_346 . V_329 = V_339 ;
else
V_346 . V_329 = V_341 ;
V_346 . V_304 = V_60 -> V_63 ;
V_346 . V_347 = V_60 -> V_324 ;
F_112 ( V_166 , & V_346 ) ;
V_34:
F_88 ( V_166 ) ;
return V_23 ;
}
static int F_113 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_144 * V_166 ;
struct V_345 V_346 ;
int V_23 ;
if ( ! V_110 [ V_146 - 1 ] ||
! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) )
return - V_72 ;
V_166 = F_61 ( V_10 , V_60 , V_110 ) ;
if ( V_166 == NULL )
return - V_51 ;
if ( ( V_23 = F_114 ( V_166 ) ) )
goto V_34;
if ( F_115 ( V_166 ) ) {
V_23 = - V_25 ;
goto V_34;
}
V_23 = F_116 ( V_166 ) ;
if ( V_23 < 0 )
goto V_34;
V_346 . V_304 = V_60 -> V_63 ;
V_346 . V_347 = V_60 -> V_324 ;
V_346 . V_329 = V_337 ;
F_112 ( V_166 , & V_346 ) ;
V_34:
F_117 ( V_166 , V_23 ? 0 : 1 ,
F_109 ( V_348 ) ,
F_110 ( V_348 ) , 0 ) ;
F_88 ( V_166 ) ;
return V_23 ;
}
static int F_118 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
T_8 V_135 ;
struct V_40 * V_349 ;
struct V_59 * V_308 ;
struct V_144 * V_166 ;
if ( ! V_110 [ V_146 - 1 ] ||
! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) )
return - V_72 ;
V_166 = F_61 ( V_10 , V_60 , V_110 ) ;
if ( V_166 == NULL )
return - V_51 ;
V_349 = F_77 ( V_166 ) ;
V_135 = V_166 -> V_196 . V_135 ;
F_88 ( V_166 ) ;
if ( F_94 ( V_349 ) )
return F_95 ( V_349 ) ;
V_308 = (struct V_59 * ) V_349 -> V_62 ;
V_308 -> V_320 = V_60 -> V_320 ;
V_308 -> V_321 = V_350 ;
V_308 -> V_147 = F_55 ( V_135 ) ;
V_308 -> V_64 = 0 ;
V_308 -> V_323 = 0 ;
V_308 -> V_63 = V_60 -> V_63 ;
V_308 -> V_324 = V_60 -> V_324 ;
F_35 ( V_349 , V_65 , V_58 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static struct V_40 * F_119 ( const struct V_59 * V_67 ,
T_1 V_42 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
int V_46 , V_351 , V_352 , V_353 ;
V_351 = F_120 () ;
if ( V_351 ) {
V_351 *= sizeof( struct V_354 ) ;
V_351 += sizeof( struct V_355 ) ;
}
V_352 = F_121 () ;
if ( V_352 ) {
V_352 *= sizeof( struct V_354 ) ;
V_352 += sizeof( struct V_355 ) ;
}
V_46 = V_352 + V_351 + sizeof( struct V_59 ) ;
V_8 = F_42 ( V_46 + 16 , V_42 ) ;
if ( ! V_8 )
goto V_356;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( * V_60 ) ) ;
F_40 ( V_60 , V_67 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_74 = V_46 / sizeof( V_75 ) ;
if ( V_351 ) {
struct V_355 * V_78 ;
struct V_354 * V_357 ;
V_78 = (struct V_355 * ) F_44 ( V_8 , V_351 ) ;
V_357 = (struct V_354 * ) ( V_78 + 1 ) ;
V_78 -> V_358 = V_351 / sizeof( V_75 ) ;
V_78 -> V_359 = V_360 ;
for ( V_353 = 0 ; ; V_353 ++ ) {
struct V_211 * V_187 = F_122 ( V_353 ) ;
if ( ! V_187 )
break;
if ( V_187 -> V_361 )
* V_357 ++ = V_187 -> V_214 ;
}
}
if ( V_352 ) {
struct V_355 * V_78 ;
struct V_354 * V_357 ;
V_78 = (struct V_355 * ) F_44 ( V_8 , V_352 ) ;
V_357 = (struct V_354 * ) ( V_78 + 1 ) ;
V_78 -> V_358 = V_352 / sizeof( V_75 ) ;
V_78 -> V_359 = V_362 ;
for ( V_353 = 0 ; ; V_353 ++ ) {
struct V_211 * V_189 = F_123 ( V_353 ) ;
if ( ! V_189 )
break;
if ( V_189 -> V_361 )
* V_357 ++ = V_189 -> V_214 ;
}
}
V_356:
return V_8 ;
}
static int F_124 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_40 * V_363 ;
if ( V_60 -> V_147 > V_364 )
return - V_72 ;
if ( V_60 -> V_147 != V_127 ) {
if ( V_6 -> V_57 & ( 1 << V_60 -> V_147 ) )
return - V_365 ;
V_6 -> V_57 |= ( 1 << V_60 -> V_147 ) ;
}
F_125 () ;
V_363 = F_119 ( V_60 , V_32 ) ;
if ( ! V_363 ) {
if ( V_60 -> V_147 != V_127 )
V_6 -> V_57 &= ~ ( 1 << V_60 -> V_147 ) ;
return - V_43 ;
}
F_35 ( V_363 , V_32 , V_56 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_126 ( struct V_2 * V_3 , const struct V_59 * V_366 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
V_8 = F_42 ( sizeof( struct V_59 ) + 16 , V_65 ) ;
if ( ! V_8 )
return - V_43 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
memcpy ( V_60 , V_366 , sizeof( struct V_59 ) ) ;
V_60 -> V_64 = ( V_73 ) 0 ;
V_60 -> V_74 = ( sizeof( struct V_59 ) / sizeof( V_75 ) ) ;
return F_35 ( V_8 , V_65 , V_58 , V_3 , F_7 ( V_3 ) ) ;
}
static int F_127 ( const struct V_345 * V_346 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
V_8 = F_42 ( sizeof( struct V_59 ) + 16 , V_65 ) ;
if ( ! V_8 )
return - V_43 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_147 = F_55 ( V_346 -> V_62 . V_135 ) ;
V_60 -> V_321 = V_367 ;
V_60 -> V_63 = V_346 -> V_304 ;
V_60 -> V_324 = V_346 -> V_347 ;
V_60 -> V_320 = V_28 ;
V_60 -> V_64 = ( V_73 ) 0 ;
V_60 -> V_74 = ( sizeof( struct V_59 ) / sizeof( V_75 ) ) ;
F_35 ( V_8 , V_65 , V_54 , NULL , V_346 -> V_10 ) ;
return 0 ;
}
static int F_128 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned V_135 ;
struct V_345 V_346 ;
struct V_368 V_369 ;
int V_23 , V_52 ;
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 )
return - V_72 ;
V_369 . V_370 = F_109 ( V_348 ) ;
V_369 . V_371 = F_110 ( V_348 ) ;
V_369 . V_372 = 0 ;
V_23 = F_129 ( V_10 , V_135 , & V_369 ) ;
V_52 = F_126 ( V_3 , V_60 ) ;
if ( V_23 || V_52 ) {
if ( V_23 == - V_51 )
V_23 = 0 ;
return V_23 ? V_23 : V_52 ;
}
V_346 . V_62 . V_135 = V_135 ;
V_346 . V_304 = V_60 -> V_63 ;
V_346 . V_347 = V_60 -> V_324 ;
V_346 . V_329 = V_373 ;
V_346 . V_10 = V_10 ;
F_112 ( NULL , & V_346 ) ;
return 0 ;
}
static int F_130 ( struct V_144 * V_166 , int V_374 , void * V_375 )
{
struct V_1 * V_6 = V_375 ;
struct V_40 * V_349 ;
struct V_59 * V_308 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_43 ;
V_349 = F_77 ( V_166 ) ;
if ( F_94 ( V_349 ) )
return F_95 ( V_349 ) ;
V_308 = (struct V_59 * ) V_349 -> V_62 ;
V_308 -> V_320 = V_6 -> V_7 . V_376 ;
V_308 -> V_321 = V_377 ;
V_308 -> V_147 = F_55 ( V_166 -> V_196 . V_135 ) ;
V_308 -> V_64 = 0 ;
V_308 -> V_323 = 0 ;
V_308 -> V_63 = V_374 + 1 ;
V_308 -> V_324 = V_6 -> V_7 . V_378 ;
if ( V_6 -> V_7 . V_8 )
F_35 ( V_6 -> V_7 . V_8 , V_65 , V_58 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_349 ;
return 0 ;
}
static int F_131 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return F_132 ( V_10 , & V_6 -> V_7 . V_379 . V_201 , F_130 , ( void * ) V_6 ) ;
}
static void F_133 ( struct V_1 * V_6 )
{
F_134 ( & V_6 -> V_7 . V_379 . V_201 ) ;
}
static int F_135 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
T_7 V_135 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_380 ;
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 )
return - V_72 ;
V_6 -> V_7 . V_376 = V_60 -> V_320 ;
V_6 -> V_7 . V_378 = V_60 -> V_324 ;
V_6 -> V_7 . V_7 = F_131 ;
V_6 -> V_7 . V_9 = F_133 ;
F_136 ( & V_6 -> V_7 . V_379 . V_201 , V_135 ) ;
return F_39 ( V_6 ) ;
}
static int F_137 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_126 = V_60 -> V_147 ;
bool V_381 = false ;
if ( V_60 -> V_74 == ( sizeof( * V_60 ) / sizeof( V_75 ) ) ) {
V_381 = true ;
if ( V_126 != 0 && V_126 != 1 )
return - V_72 ;
V_6 -> V_53 = V_126 ;
}
if ( V_381 && F_138 ( V_8 ) )
V_8 = F_139 ( V_8 , V_32 ) ;
else
V_8 = F_31 ( V_8 , V_32 ) ;
if ( V_381 && V_8 ) {
struct V_59 * V_382 = (struct V_59 * ) V_8 -> V_62 ;
V_382 -> V_64 = 0 ;
}
F_35 ( V_8 , V_32 , V_54 , NULL , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_140 ( struct V_383 * V_384 , int V_385 , int V_374 , void * V_375 )
{
int V_353 ;
T_6 V_270 = * ( T_6 * ) V_375 ;
for ( V_353 = 0 ; V_353 < V_384 -> V_386 ; V_353 ++ ) {
if ( V_384 -> V_387 [ V_353 ] . V_270 == V_270 )
return - V_365 ;
}
return 0 ;
}
static T_6 F_141 ( struct V_10 * V_10 )
{
struct V_388 V_389 ;
T_6 V_390 ;
int V_61 ;
static T_6 V_270 = V_391 ;
V_390 = V_270 ;
do {
++ V_270 ;
if ( V_270 == 0 )
V_270 = V_391 + 1 ;
F_142 ( & V_389 , V_392 ) ;
V_61 = V_388 ( V_10 , & V_389 , F_140 , ( void * ) & V_270 ) ;
F_143 ( & V_389 ) ;
if ( V_61 != - V_365 )
return V_270 ;
} while ( V_270 != V_390 );
return 0 ;
}
static int
F_144 ( struct V_383 * V_384 , struct V_393 * V_394 )
{
struct V_10 * V_10 = F_145 ( V_384 ) ;
struct V_395 * V_396 = V_384 -> V_387 + V_384 -> V_386 ;
int V_150 ;
if ( V_384 -> V_386 >= V_397 )
return - V_398 ;
if ( V_394 -> V_399 == 0 )
return - V_72 ;
V_396 -> V_196 . V_135 = V_394 -> V_400 ;
if ( ( V_150 = F_66 ( V_394 -> V_399 ) ) < 0 )
return - V_72 ;
V_396 -> V_150 = V_150 ;
if ( V_394 -> V_401 == V_402 )
V_396 -> V_403 = 1 ;
else if ( V_394 -> V_401 == V_404 ) {
V_396 -> V_270 = V_394 -> V_405 ;
if ( V_396 -> V_270 > V_391 )
V_396 -> V_270 = 0 ;
if ( ! V_396 -> V_270 && ! ( V_396 -> V_270 = F_141 ( V_10 ) ) )
return - V_43 ;
}
if ( V_396 -> V_150 == V_153 ) {
T_7 * V_137 = ( T_7 * ) ( V_394 + 1 ) ;
int V_136 , V_406 ;
V_136 = F_59 ( (struct V_79 * ) V_137 ,
& V_396 -> V_186 ) ;
if ( ! V_136 )
return - V_72 ;
V_406 = F_58 ( V_136 ) ;
if ( F_59 ( (struct V_79 * ) ( V_137 + V_406 ) ,
& V_396 -> V_196 . V_252 ) != V_136 )
return - V_72 ;
V_396 -> V_407 = V_136 ;
} else
V_396 -> V_407 = V_384 -> V_136 ;
V_396 -> V_408 = 1 ;
V_384 -> V_386 ++ ;
return 0 ;
}
static int
F_146 ( struct V_383 * V_384 , struct V_409 * V_410 )
{
int V_23 ;
int V_46 = V_410 -> V_411 * 8 - sizeof( struct V_409 ) ;
struct V_393 * V_394 = ( void * ) ( V_410 + 1 ) ;
while ( V_46 >= sizeof( struct V_393 ) ) {
if ( ( V_23 = F_144 ( V_384 , V_394 ) ) < 0 )
return V_23 ;
V_46 -= V_394 -> V_412 ;
V_394 = ( void * ) ( ( T_7 * ) V_394 + V_394 -> V_412 ) ;
}
return 0 ;
}
static inline int F_147 ( const struct V_383 * V_384 )
{
struct V_175 * V_176 = V_384 -> V_184 ;
if ( V_176 ) {
int V_46 = sizeof( struct V_91 ) ;
V_46 += V_176 -> V_105 ;
return F_64 ( V_46 ) ;
}
return 0 ;
}
static int F_148 ( const struct V_383 * V_384 )
{
const struct V_395 * V_396 ;
int V_180 = F_63 ( V_384 -> V_136 ) ;
int V_406 = 0 ;
int V_353 ;
for ( V_353 = 0 ; V_353 < V_384 -> V_386 ; V_353 ++ ) {
V_396 = V_384 -> V_387 + V_353 ;
V_406 += F_58 ( V_396 -> V_407 ) ;
}
return sizeof( struct V_59 ) +
( sizeof( struct V_169 ) * 3 ) +
( sizeof( struct V_77 ) * 2 ) +
( V_180 * 2 ) +
sizeof( struct V_409 ) +
( V_384 -> V_386 * sizeof( struct V_393 ) ) +
( V_406 * 2 ) +
F_147 ( V_384 ) ;
}
static struct V_40 * F_149 ( const struct V_383 * V_384 )
{
struct V_40 * V_8 ;
int V_177 ;
V_177 = F_148 ( V_384 ) ;
V_8 = F_42 ( V_177 + 16 , V_65 ) ;
if ( V_8 == NULL )
return F_70 ( - V_43 ) ;
return V_8 ;
}
static int F_150 ( struct V_40 * V_8 , const struct V_383 * V_384 , int V_385 )
{
struct V_59 * V_60 ;
struct V_77 * V_80 ;
struct V_169 * V_170 ;
struct V_409 * V_410 ;
struct V_91 * V_92 ;
struct V_175 * V_176 ;
int V_353 ;
int V_177 ;
int V_180 = F_63 ( V_384 -> V_136 ) ;
int V_406 = F_58 ( V_384 -> V_136 ) ;
V_177 = F_148 ( V_384 ) ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
memset ( V_60 , 0 , V_177 ) ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_180 ) ;
V_80 -> V_88 =
( sizeof( struct V_77 ) + V_180 ) /
sizeof( V_75 ) ;
V_80 -> V_249 = V_121 ;
V_80 -> V_250 = F_57 ( V_384 -> V_413 . V_135 ) ;
V_80 -> V_89 = V_384 -> V_413 . V_253 ;
V_80 -> V_251 = 0 ;
if ( ! F_67 ( & V_384 -> V_413 . V_186 ,
V_384 -> V_413 . V_254 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_384 -> V_136 ) )
F_76 () ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_180 ) ;
V_80 -> V_88 =
( sizeof( struct V_77 ) + V_180 ) /
sizeof( V_75 ) ;
V_80 -> V_249 = V_122 ;
V_80 -> V_250 = F_57 ( V_384 -> V_413 . V_135 ) ;
V_80 -> V_89 = V_384 -> V_413 . V_414 ;
V_80 -> V_251 = 0 ;
F_67 ( & V_384 -> V_413 . V_252 , V_384 -> V_413 . V_415 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_384 -> V_136 ) ;
V_170 = (struct V_169 * ) F_44 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_226 =
sizeof( struct V_169 ) / sizeof( V_75 ) ;
V_170 -> V_227 = V_228 ;
V_170 -> V_229 = F_75 ( V_384 -> V_230 . V_231 ) ;
V_170 -> V_232 = F_75 ( V_384 -> V_230 . V_233 ) ;
V_170 -> V_234 = V_384 -> V_230 . V_235 ;
V_170 -> V_236 = V_384 -> V_230 . V_237 ;
V_170 = (struct V_169 * ) F_44 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_226 =
sizeof( struct V_169 ) / sizeof( V_75 ) ;
V_170 -> V_227 = V_238 ;
V_170 -> V_229 = F_75 ( V_384 -> V_230 . V_239 ) ;
V_170 -> V_232 = F_75 ( V_384 -> V_230 . V_240 ) ;
V_170 -> V_234 = V_384 -> V_230 . V_241 ;
V_170 -> V_236 = V_384 -> V_230 . V_242 ;
V_170 = (struct V_169 * ) F_44 ( V_8 ,
sizeof( struct V_169 ) ) ;
V_170 -> V_226 =
sizeof( struct V_169 ) / sizeof( V_75 ) ;
V_170 -> V_227 = V_243 ;
V_170 -> V_229 = V_384 -> V_244 . V_245 ;
V_170 -> V_232 = V_384 -> V_244 . V_246 ;
V_170 -> V_234 = V_384 -> V_244 . V_247 ;
V_170 -> V_236 = V_384 -> V_244 . V_248 ;
V_410 = (struct V_409 * ) F_44 ( V_8 , sizeof( struct V_409 ) ) ;
V_410 -> V_411 = sizeof( struct V_409 ) / sizeof( V_75 ) ;
V_410 -> V_416 = V_417 ;
V_410 -> V_418 = V_419 ;
if ( V_384 -> V_420 == V_421 ) {
if ( V_384 -> V_386 )
V_410 -> V_418 = V_422 ;
else
V_410 -> V_418 = V_423 ;
}
V_410 -> V_424 = V_385 + 1 ;
V_410 -> V_425 = V_384 -> V_426 ;
V_410 -> V_427 = V_384 -> V_428 ;
for ( V_353 = 0 ; V_353 < V_384 -> V_386 ; V_353 ++ ) {
const struct V_395 * V_396 = V_384 -> V_387 + V_353 ;
struct V_393 * V_394 ;
int V_429 ;
int V_150 ;
V_429 = sizeof( struct V_393 ) ;
if ( V_396 -> V_150 == V_153 ) {
V_406 = F_58 ( V_396 -> V_407 ) ;
V_429 += V_406 * 2 ;
} else {
V_177 -= 2 * V_406 ;
}
V_394 = ( void * ) F_44 ( V_8 , V_429 ) ;
V_410 -> V_411 += V_429 / 8 ;
memset ( V_394 , 0 , sizeof( * V_394 ) ) ;
V_394 -> V_412 = V_429 ;
V_394 -> V_400 = V_396 -> V_196 . V_135 ;
if ( ( V_150 = F_65 ( V_396 -> V_150 ) ) < 0 )
return - V_72 ;
V_394 -> V_399 = V_150 ;
V_394 -> V_401 = V_430 ;
if ( V_396 -> V_270 )
V_394 -> V_401 = V_404 ;
if ( V_396 -> V_403 )
V_394 -> V_401 = V_402 ;
V_394 -> V_405 = V_396 -> V_270 ;
if ( V_396 -> V_150 == V_153 ) {
T_7 * V_137 = ( void * ) ( V_394 + 1 ) ;
F_67 ( & V_396 -> V_186 , 0 ,
(struct V_79 * ) V_137 ,
V_396 -> V_407 ) ;
F_67 ( & V_396 -> V_196 . V_252 , 0 ,
(struct V_79 * ) ( V_137 + V_406 ) ,
V_396 -> V_407 ) ;
}
}
if ( ( V_176 = V_384 -> V_184 ) ) {
int V_98 = F_147 ( V_384 ) ;
V_92 = (struct V_91 * ) F_44 ( V_8 , V_98 ) ;
V_92 -> V_95 = V_98 / sizeof( V_75 ) ;
V_92 -> V_100 = V_125 ;
V_92 -> V_102 = V_176 -> V_101 ;
V_92 -> V_104 = V_176 -> V_103 ;
V_92 -> V_93 = V_176 -> V_105 ;
memcpy ( V_92 + 1 , V_176 -> V_286 ,
V_176 -> V_105 ) ;
}
V_60 -> V_74 = V_177 / sizeof( V_75 ) ;
V_60 -> V_323 = F_3 ( & V_384 -> V_431 ) ;
return 0 ;
}
static int F_151 ( struct V_383 * V_384 , int V_385 , const struct V_345 * V_346 )
{
struct V_40 * V_349 ;
struct V_59 * V_308 ;
int V_23 ;
V_349 = F_149 ( V_384 ) ;
if ( F_94 ( V_349 ) )
return F_95 ( V_349 ) ;
V_23 = F_150 ( V_349 , V_384 , V_385 ) ;
if ( V_23 < 0 )
return V_23 ;
V_308 = (struct V_59 * ) V_349 -> V_62 ;
V_308 -> V_320 = V_28 ;
if ( V_346 -> V_62 . V_432 && V_346 -> V_329 == V_330 )
V_308 -> V_321 = V_433 ;
else
V_308 -> V_321 = F_100 ( V_346 -> V_329 ) ;
V_308 -> V_64 = 0 ;
V_308 -> V_63 = V_346 -> V_304 ;
V_308 -> V_324 = V_346 -> V_347 ;
F_35 ( V_349 , V_65 , V_54 , NULL , F_145 ( V_384 ) ) ;
return 0 ;
}
static int F_152 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 = 0 ;
struct V_169 * V_170 ;
struct V_77 * V_137 ;
struct V_409 * V_410 ;
struct V_383 * V_384 ;
struct V_345 V_346 ;
struct V_91 * V_92 ;
if ( ! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) ||
! V_110 [ V_417 - 1 ] )
return - V_72 ;
V_410 = V_110 [ V_417 - 1 ] ;
if ( V_410 -> V_418 > V_422 )
return - V_72 ;
if ( ! V_410 -> V_424 || V_410 -> V_424 >= V_434 )
return - V_72 ;
V_384 = F_153 ( V_10 , V_32 ) ;
if ( V_384 == NULL )
return - V_43 ;
V_384 -> V_420 = ( V_410 -> V_418 == V_419 ?
V_435 : V_421 ) ;
V_384 -> V_428 = V_410 -> V_427 ;
V_137 = V_110 [ V_121 - 1 ] ,
V_384 -> V_136 = F_60 ( V_137 , & V_384 -> V_413 . V_186 ) ;
if ( ! V_384 -> V_136 ) {
V_23 = - V_72 ;
goto V_34;
}
V_384 -> V_413 . V_136 = V_384 -> V_136 ;
V_384 -> V_413 . V_253 = V_137 -> V_89 ;
V_384 -> V_413 . V_135 = F_56 ( V_137 -> V_250 ) ;
V_384 -> V_413 . V_254 = ( (struct V_81 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_384 -> V_413 . V_254 )
V_384 -> V_413 . V_436 = F_154 ( 0xffff ) ;
V_137 = V_110 [ V_122 - 1 ] ,
F_60 ( V_137 , & V_384 -> V_413 . V_252 ) ;
V_384 -> V_413 . V_414 = V_137 -> V_89 ;
V_384 -> V_413 . V_135 = F_56 ( V_137 -> V_250 ) ;
V_384 -> V_413 . V_415 = ( (struct V_81 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_384 -> V_413 . V_415 )
V_384 -> V_413 . V_437 = F_154 ( 0xffff ) ;
V_92 = (struct V_91 * ) V_110 [ V_125 - 1 ] ;
if ( V_92 != NULL ) {
struct V_96 * V_97 = F_50 ( V_92 ) ;
if ( ! V_97 ) {
V_23 = - V_43 ;
goto V_34;
}
V_23 = F_155 ( & V_384 -> V_184 , V_97 ) ;
F_83 ( V_97 ) ;
if ( V_23 )
goto V_34;
}
V_384 -> V_230 . V_240 = V_438 ;
V_384 -> V_230 . V_233 = V_438 ;
V_384 -> V_230 . V_239 = V_438 ;
V_384 -> V_230 . V_231 = V_438 ;
if ( ( V_170 = V_110 [ V_228 - 1 ] ) != NULL ) {
V_384 -> V_230 . V_231 = F_81 ( V_170 -> V_229 ) ;
V_384 -> V_230 . V_233 = F_81 ( V_170 -> V_232 ) ;
V_384 -> V_230 . V_235 = V_170 -> V_234 ;
V_384 -> V_230 . V_237 = V_170 -> V_236 ;
}
if ( ( V_170 = V_110 [ V_238 - 1 ] ) != NULL ) {
V_384 -> V_230 . V_239 = F_81 ( V_170 -> V_229 ) ;
V_384 -> V_230 . V_240 = F_81 ( V_170 -> V_232 ) ;
V_384 -> V_230 . V_241 = V_170 -> V_234 ;
V_384 -> V_230 . V_242 = V_170 -> V_236 ;
}
V_384 -> V_386 = 0 ;
if ( V_410 -> V_418 == V_422 &&
( V_23 = F_146 ( V_384 , V_410 ) ) < 0 )
goto V_34;
V_23 = F_156 ( V_410 -> V_424 - 1 , V_384 ,
V_60 -> V_321 != V_335 ) ;
F_157 ( V_384 , V_23 ? 0 : 1 ,
F_109 ( V_348 ) ,
F_110 ( V_348 ) , 0 ) ;
if ( V_23 )
goto V_34;
if ( V_60 -> V_321 == V_335 )
V_346 . V_329 = V_334 ;
else
V_346 . V_329 = V_332 ;
V_346 . V_304 = V_60 -> V_63 ;
V_346 . V_347 = V_60 -> V_324 ;
F_158 ( V_384 , V_410 -> V_424 - 1 , & V_346 ) ;
F_159 ( V_384 ) ;
return 0 ;
V_34:
V_384 -> V_389 . V_439 = 1 ;
F_160 ( V_384 ) ;
return V_23 ;
}
static int F_161 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 ;
struct V_77 * V_137 ;
struct V_409 * V_410 ;
struct V_383 * V_384 ;
struct V_440 V_185 ;
struct V_345 V_346 ;
struct V_91 * V_92 ;
struct V_175 * V_441 = NULL ;
if ( ! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) ||
! V_110 [ V_417 - 1 ] )
return - V_72 ;
V_410 = V_110 [ V_417 - 1 ] ;
if ( ! V_410 -> V_424 || V_410 -> V_424 >= V_434 )
return - V_72 ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
V_137 = V_110 [ V_121 - 1 ] ,
V_185 . V_136 = F_60 ( V_137 , & V_185 . V_186 ) ;
V_185 . V_253 = V_137 -> V_89 ;
V_185 . V_135 = F_56 ( V_137 -> V_250 ) ;
V_185 . V_254 = ( (struct V_81 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_185 . V_254 )
V_185 . V_436 = F_154 ( 0xffff ) ;
V_137 = V_110 [ V_122 - 1 ] ,
F_60 ( V_137 , & V_185 . V_252 ) ;
V_185 . V_414 = V_137 -> V_89 ;
V_185 . V_135 = F_56 ( V_137 -> V_250 ) ;
V_185 . V_415 = ( (struct V_81 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_185 . V_415 )
V_185 . V_437 = F_154 ( 0xffff ) ;
V_92 = (struct V_91 * ) V_110 [ V_125 - 1 ] ;
if ( V_92 != NULL ) {
struct V_96 * V_97 = F_50 ( V_92 ) ;
if ( ! V_97 )
return - V_30 ;
V_23 = F_155 ( & V_441 , V_97 ) ;
F_83 ( V_97 ) ;
if ( V_23 )
return V_23 ;
}
V_384 = F_162 ( V_10 , V_148 , V_392 ,
V_410 -> V_424 - 1 , & V_185 , V_441 ,
1 , & V_23 ) ;
F_163 ( V_441 ) ;
if ( V_384 == NULL )
return - V_316 ;
F_164 ( V_384 , V_23 ? 0 : 1 ,
F_109 ( V_348 ) ,
F_110 ( V_348 ) , 0 ) ;
if ( V_23 )
goto V_34;
V_346 . V_304 = V_60 -> V_63 ;
V_346 . V_347 = V_60 -> V_324 ;
V_346 . V_62 . V_432 = 0 ;
V_346 . V_329 = V_330 ;
F_158 ( V_384 , V_410 -> V_424 - 1 , & V_346 ) ;
V_34:
F_159 ( V_384 ) ;
return V_23 ;
}
static int F_165 ( struct V_2 * V_3 , struct V_383 * V_384 , const struct V_59 * V_60 , int V_385 )
{
int V_23 ;
struct V_40 * V_349 ;
struct V_59 * V_308 ;
V_23 = 0 ;
V_349 = F_149 ( V_384 ) ;
if ( F_94 ( V_349 ) ) {
V_23 = F_95 ( V_349 ) ;
goto V_34;
}
V_23 = F_150 ( V_349 , V_384 , V_385 ) ;
if ( V_23 < 0 )
goto V_34;
V_308 = (struct V_59 * ) V_349 -> V_62 ;
V_308 -> V_320 = V_60 -> V_320 ;
V_308 -> V_321 = V_60 -> V_321 ;
V_308 -> V_147 = 0 ;
V_308 -> V_64 = 0 ;
V_308 -> V_63 = V_60 -> V_63 ;
V_308 -> V_324 = V_60 -> V_324 ;
F_35 ( V_349 , V_65 , V_58 , V_3 , F_145 ( V_384 ) ) ;
V_23 = 0 ;
V_34:
return V_23 ;
}
static int F_166 ( T_3 V_136 )
{
return F_64 ( F_58 ( V_136 ) * 2 ) ;
}
static int F_167 ( struct V_79 * V_137 , int V_114 ,
T_4 * V_186 , T_4 * V_252 ,
T_9 * V_136 )
{
int V_442 , V_406 ;
if ( V_114 < F_166 ( V_137 -> V_86 ) )
return - V_72 ;
V_442 = F_59 ( V_137 , V_186 ) ;
if ( ! V_442 )
return - V_72 ;
V_406 = F_58 ( V_442 ) ;
if ( F_59 ( (struct V_79 * ) ( ( ( T_7 * ) V_137 ) + V_406 ) ,
V_252 ) != V_442 )
return - V_72 ;
* V_136 = V_442 ;
return 0 ;
}
static int F_168 ( struct V_393 * V_443 , int V_46 ,
struct V_444 * V_445 )
{
int V_23 ;
struct V_393 * V_446 ;
int V_150 ;
if ( V_46 <= sizeof( struct V_393 ) ||
V_46 < V_443 -> V_412 )
return - V_72 ;
V_23 = F_167 ( (struct V_79 * ) ( V_443 + 1 ) ,
V_443 -> V_412 ,
& V_445 -> V_447 , & V_445 -> V_448 ,
& V_445 -> V_449 ) ;
if ( V_23 )
return V_23 ;
V_446 = (struct V_393 * ) ( ( T_7 * ) V_443 + V_443 -> V_412 ) ;
V_46 -= V_443 -> V_412 ;
if ( V_46 <= sizeof( struct V_393 ) ||
V_46 < V_446 -> V_412 )
return - V_72 ;
V_23 = F_167 ( (struct V_79 * ) ( V_446 + 1 ) ,
V_446 -> V_412 ,
& V_445 -> V_450 , & V_445 -> V_451 ,
& V_445 -> V_452 ) ;
if ( V_23 )
return V_23 ;
if ( V_443 -> V_400 != V_446 -> V_400 ||
V_443 -> V_399 != V_446 -> V_399 ||
V_443 -> V_405 != V_446 -> V_405 )
return - V_72 ;
V_445 -> V_135 = V_443 -> V_400 ;
if ( ( V_150 = F_66 ( V_443 -> V_399 ) ) < 0 )
return - V_72 ;
V_445 -> V_150 = V_150 ;
V_445 -> V_270 = V_443 -> V_405 ;
return ( ( int ) ( V_443 -> V_412 +
V_446 -> V_412 ) ) ;
}
static int F_169 ( struct V_2 * V_3 , struct V_40 * V_8 ,
const struct V_59 * V_60 , void * const * V_110 )
{
int V_353 , V_46 , V_453 , V_23 = - V_72 ;
T_7 V_385 ;
struct V_77 * V_137 ;
struct V_454 * V_455 ;
struct V_409 * V_410 ;
struct V_393 * V_394 ;
struct V_440 V_185 ;
struct V_444 V_445 [ V_397 ] ;
struct V_456 V_457 ;
if ( ! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) ||
! V_110 [ V_417 - 1 ] ) {
V_23 = - V_72 ;
goto V_34;
}
V_455 = V_110 [ V_458 - 1 ] ;
V_410 = V_110 [ V_417 - 1 ] ;
if ( V_410 -> V_424 >= V_434 ) {
V_23 = - V_72 ;
goto V_34;
}
if ( V_455 ) {
V_457 . V_459 = V_455 -> V_460 ;
V_453 = F_167 ( (struct V_79 * ) ( V_455 + 1 ) ,
8 * ( V_455 -> V_461 ) - sizeof( * V_455 ) ,
& V_457 . V_462 , & V_457 . V_463 , & V_457 . V_136 ) ;
if ( V_453 < 0 ) {
V_23 = V_453 ;
goto V_34;
}
}
V_385 = V_410 -> V_424 - 1 ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
V_137 = V_110 [ V_121 - 1 ] ;
V_185 . V_136 = F_60 ( V_137 , & V_185 . V_186 ) ;
V_185 . V_253 = V_137 -> V_89 ;
V_185 . V_135 = F_56 ( V_137 -> V_250 ) ;
V_185 . V_254 = ( (struct V_81 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_185 . V_254 )
V_185 . V_436 = F_154 ( 0xffff ) ;
V_137 = V_110 [ V_122 - 1 ] ,
F_60 ( V_137 , & V_185 . V_252 ) ;
V_185 . V_414 = V_137 -> V_89 ;
V_185 . V_135 = F_56 ( V_137 -> V_250 ) ;
V_185 . V_415 = ( (struct V_81 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_185 . V_415 )
V_185 . V_437 = F_154 ( 0xffff ) ;
V_394 = (struct V_393 * ) ( V_410 + 1 ) ;
V_353 = 0 ;
V_46 = V_410 -> V_411 * 8 - sizeof( struct V_409 ) ;
while ( V_46 > 0 && V_353 < V_397 ) {
V_453 = F_168 ( V_394 , V_46 , & V_445 [ V_353 ] ) ;
if ( V_453 < 0 ) {
V_23 = V_453 ;
goto V_34;
} else {
V_394 = (struct V_393 * ) ( ( T_7 * ) V_394 + V_453 ) ;
V_46 -= V_453 ;
V_353 ++ ;
}
}
if ( ! V_353 || V_46 > 0 ) {
V_23 = - V_72 ;
goto V_34;
}
return V_444 ( & V_185 , V_385 , V_392 , V_445 , V_353 ,
V_455 ? & V_457 : NULL ) ;
V_34:
return V_23 ;
}
static int F_169 ( struct V_2 * V_3 , struct V_40 * V_8 ,
const struct V_59 * V_60 , void * const * V_110 )
{
return - V_464 ;
}
static int F_170 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_385 ;
int V_23 = 0 , V_465 ;
struct V_409 * V_410 ;
struct V_383 * V_384 ;
struct V_345 V_346 ;
if ( ( V_410 = V_110 [ V_417 - 1 ] ) == NULL )
return - V_72 ;
V_385 = F_171 ( V_410 -> V_425 ) ;
if ( V_385 >= V_466 )
return - V_72 ;
V_465 = ( V_60 -> V_321 == V_433 ) ;
V_384 = F_172 ( V_10 , V_148 , V_392 ,
V_385 , V_410 -> V_425 , V_465 , & V_23 ) ;
if ( V_384 == NULL )
return - V_316 ;
if ( V_465 ) {
F_164 ( V_384 , V_23 ? 0 : 1 ,
F_109 ( V_348 ) ,
F_110 ( V_348 ) , 0 ) ;
if ( V_23 )
goto V_34;
V_346 . V_304 = V_60 -> V_63 ;
V_346 . V_347 = V_60 -> V_324 ;
V_346 . V_62 . V_432 = 1 ;
V_346 . V_329 = V_330 ;
F_158 ( V_384 , V_385 , & V_346 ) ;
} else {
V_23 = F_165 ( V_3 , V_384 , V_60 , V_385 ) ;
}
V_34:
F_159 ( V_384 ) ;
return V_23 ;
}
static int F_173 ( struct V_383 * V_384 , int V_385 , int V_374 , void * V_375 )
{
struct V_1 * V_6 = V_375 ;
struct V_40 * V_349 ;
struct V_59 * V_308 ;
int V_23 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_43 ;
V_349 = F_149 ( V_384 ) ;
if ( F_94 ( V_349 ) )
return F_95 ( V_349 ) ;
V_23 = F_150 ( V_349 , V_384 , V_385 ) ;
if ( V_23 < 0 )
return V_23 ;
V_308 = (struct V_59 * ) V_349 -> V_62 ;
V_308 -> V_320 = V_6 -> V_7 . V_376 ;
V_308 -> V_321 = V_467 ;
V_308 -> V_147 = V_127 ;
V_308 -> V_64 = 0 ;
V_308 -> V_63 = V_374 + 1 ;
V_308 -> V_324 = V_6 -> V_7 . V_378 ;
if ( V_6 -> V_7 . V_8 )
F_35 ( V_6 -> V_7 . V_8 , V_65 , V_58 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_349 ;
return 0 ;
}
static int F_174 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return V_388 ( V_10 , & V_6 -> V_7 . V_379 . V_468 , F_173 , ( void * ) V_6 ) ;
}
static void F_175 ( struct V_1 * V_6 )
{
F_143 ( & V_6 -> V_7 . V_379 . V_468 ) ;
}
static int F_176 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_7 . V_7 != NULL )
return - V_380 ;
V_6 -> V_7 . V_376 = V_60 -> V_320 ;
V_6 -> V_7 . V_378 = V_60 -> V_324 ;
V_6 -> V_7 . V_7 = F_174 ;
V_6 -> V_7 . V_9 = F_175 ;
F_142 ( & V_6 -> V_7 . V_379 . V_468 , V_392 ) ;
return F_39 ( V_6 ) ;
}
static int F_177 ( const struct V_345 * V_346 )
{
struct V_40 * V_469 ;
struct V_59 * V_60 ;
V_469 = F_42 ( sizeof( struct V_59 ) + 16 , V_65 ) ;
if ( ! V_469 )
return - V_43 ;
V_60 = (struct V_59 * ) F_44 ( V_469 , sizeof( struct V_59 ) ) ;
V_60 -> V_321 = V_470 ;
V_60 -> V_63 = V_346 -> V_304 ;
V_60 -> V_324 = V_346 -> V_347 ;
V_60 -> V_320 = V_28 ;
V_60 -> V_64 = ( V_73 ) 0 ;
V_60 -> V_74 = ( sizeof( struct V_59 ) / sizeof( V_75 ) ) ;
F_35 ( V_469 , V_65 , V_54 , NULL , V_346 -> V_10 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_345 V_346 ;
struct V_368 V_369 ;
int V_23 , V_52 ;
V_369 . V_370 = F_109 ( V_348 ) ;
V_369 . V_371 = F_110 ( V_348 ) ;
V_369 . V_372 = 0 ;
V_23 = F_179 ( V_10 , V_392 , & V_369 ) ;
V_52 = F_126 ( V_3 , V_60 ) ;
if ( V_23 || V_52 ) {
if ( V_23 == - V_51 )
return 0 ;
return V_23 ;
}
V_346 . V_62 . type = V_392 ;
V_346 . V_329 = V_471 ;
V_346 . V_347 = V_60 -> V_324 ;
V_346 . V_304 = V_60 -> V_63 ;
V_346 . V_10 = V_10 ;
F_158 ( NULL , 0 , & V_346 ) ;
return 0 ;
}
static int F_180 ( struct V_2 * V_3 , struct V_40 * V_8 , const struct V_59 * V_60 )
{
void * V_110 [ V_118 ] ;
int V_23 ;
F_35 ( F_31 ( V_8 , V_32 ) , V_32 ,
V_55 , NULL , F_7 ( V_3 ) ) ;
memset ( V_110 , 0 , sizeof( V_110 ) ) ;
V_23 = F_53 ( V_8 , V_60 , V_110 ) ;
if ( ! V_23 ) {
V_23 = - V_306 ;
if ( V_472 [ V_60 -> V_321 ] )
V_23 = V_472 [ V_60 -> V_321 ] ( V_3 , V_8 , V_60 , V_110 ) ;
}
return V_23 ;
}
static struct V_59 * F_181 ( struct V_40 * V_8 , int * V_473 )
{
struct V_59 * V_60 = NULL ;
if ( V_8 -> V_46 < sizeof( * V_60 ) ) {
* V_473 = - V_474 ;
} else {
V_60 = (struct V_59 * ) V_8 -> V_62 ;
if ( V_60 -> V_320 != V_28 ||
V_60 -> V_323 != 0 ||
( V_60 -> V_321 <= V_475 ||
V_60 -> V_321 > V_476 ) ) {
V_60 = NULL ;
* V_473 = - V_72 ;
} else if ( V_60 -> V_74 != ( V_8 -> V_46 /
sizeof( V_75 ) ) ||
V_60 -> V_74 < ( sizeof( struct V_59 ) /
sizeof( V_75 ) ) ) {
V_60 = NULL ;
* V_473 = - V_474 ;
} else {
* V_473 = 0 ;
}
}
return V_60 ;
}
static inline int F_182 ( const struct V_395 * V_396 ,
const struct V_211 * V_477 )
{
unsigned int V_196 = V_477 -> V_214 . V_215 ;
if ( V_196 >= sizeof( V_396 -> V_478 ) * 8 )
return 0 ;
return ( V_396 -> V_478 >> V_196 ) & 1 ;
}
static inline int F_183 ( const struct V_395 * V_396 ,
const struct V_211 * V_477 )
{
unsigned int V_196 = V_477 -> V_214 . V_215 ;
if ( V_196 >= sizeof( V_396 -> V_479 ) * 8 )
return 0 ;
return ( V_396 -> V_479 >> V_196 ) & 1 ;
}
static int F_184 ( const struct V_395 * V_396 )
{
int V_353 , V_480 = 0 ;
for ( V_353 = 0 ; ; V_353 ++ ) {
const struct V_211 * V_187 = F_122 ( V_353 ) ;
if ( ! V_187 )
break;
if ( F_182 ( V_396 , V_187 ) && V_187 -> V_361 )
V_480 += sizeof( struct V_481 ) ;
}
return V_480 + sizeof( struct V_482 ) ;
}
static int F_185 ( const struct V_395 * V_396 )
{
int V_353 , V_457 , V_480 = 0 ;
for ( V_353 = 0 ; ; V_353 ++ ) {
const struct V_211 * V_189 = F_123 ( V_353 ) ;
if ( ! V_189 )
break;
if ( ! ( F_183 ( V_396 , V_189 ) && V_189 -> V_361 ) )
continue;
for ( V_457 = 1 ; ; V_457 ++ ) {
const struct V_211 * V_187 = F_122 ( V_457 ) ;
if ( ! V_187 )
break;
if ( F_182 ( V_396 , V_187 ) && V_187 -> V_361 )
V_480 += sizeof( struct V_481 ) ;
}
}
return V_480 + sizeof( struct V_482 ) ;
}
static void F_186 ( struct V_40 * V_8 , const struct V_395 * V_396 )
{
struct V_482 * V_76 ;
int V_353 ;
V_76 = (struct V_482 * ) F_44 ( V_8 , sizeof( struct V_482 ) ) ;
V_76 -> V_483 = sizeof( struct V_482 ) / 8 ;
V_76 -> V_484 = V_485 ;
V_76 -> V_486 = 32 ;
memset ( V_76 -> V_487 , 0 , sizeof( V_76 -> V_487 ) ) ;
for ( V_353 = 0 ; ; V_353 ++ ) {
const struct V_211 * V_187 = F_122 ( V_353 ) ;
if ( ! V_187 )
break;
if ( F_182 ( V_396 , V_187 ) && V_187 -> V_361 ) {
struct V_481 * V_346 ;
V_346 = (struct V_481 * ) F_44 ( V_8 , sizeof( struct V_481 ) ) ;
memset ( V_346 , 0 , sizeof( * V_346 ) ) ;
V_76 -> V_483 += sizeof( struct V_481 ) / 8 ;
V_346 -> V_488 = V_187 -> V_214 . V_215 ;
V_346 -> V_489 = V_187 -> V_214 . V_490 ;
V_346 -> V_491 = V_187 -> V_214 . V_492 ;
V_346 -> V_493 = 24 * 60 * 60 ;
V_346 -> V_494 = 20 * 60 * 60 ;
V_346 -> V_495 = 8 * 60 * 60 ;
V_346 -> V_496 = 7 * 60 * 60 ;
}
}
}
static void F_187 ( struct V_40 * V_8 , const struct V_395 * V_396 )
{
struct V_482 * V_76 ;
int V_353 , V_457 ;
V_76 = (struct V_482 * ) F_44 ( V_8 , sizeof( struct V_482 ) ) ;
V_76 -> V_483 = sizeof( struct V_482 ) / 8 ;
V_76 -> V_484 = V_485 ;
V_76 -> V_486 = 32 ;
memset ( V_76 -> V_487 , 0 , sizeof( V_76 -> V_487 ) ) ;
for ( V_353 = 0 ; ; V_353 ++ ) {
const struct V_211 * V_189 = F_123 ( V_353 ) ;
if ( ! V_189 )
break;
if ( ! ( F_183 ( V_396 , V_189 ) && V_189 -> V_361 ) )
continue;
for ( V_457 = 1 ; ; V_457 ++ ) {
struct V_481 * V_346 ;
const struct V_211 * V_187 = F_122 ( V_457 ) ;
if ( ! V_187 )
break;
if ( ! ( F_182 ( V_396 , V_187 ) && V_187 -> V_361 ) )
continue;
V_346 = (struct V_481 * ) F_44 ( V_8 , sizeof( struct V_481 ) ) ;
memset ( V_346 , 0 , sizeof( * V_346 ) ) ;
V_76 -> V_483 += sizeof( struct V_481 ) / 8 ;
V_346 -> V_488 = V_187 -> V_214 . V_215 ;
V_346 -> V_489 = V_187 -> V_214 . V_490 ;
V_346 -> V_491 = V_187 -> V_214 . V_492 ;
V_346 -> V_497 = V_189 -> V_214 . V_215 ;
V_346 -> V_498 = V_189 -> V_214 . V_490 ;
V_346 -> V_499 = V_189 -> V_214 . V_492 ;
V_346 -> V_493 = 24 * 60 * 60 ;
V_346 -> V_494 = 20 * 60 * 60 ;
V_346 -> V_495 = 8 * 60 * 60 ;
V_346 -> V_496 = 7 * 60 * 60 ;
}
}
}
static int F_188 ( struct V_383 * V_384 , const struct V_345 * V_346 )
{
return 0 ;
}
static int F_189 ( struct V_144 * V_166 , const struct V_345 * V_346 )
{
struct V_40 * V_349 ;
struct V_59 * V_308 ;
int V_500 ;
int V_168 ;
V_500 = V_346 -> V_62 . V_500 ;
if ( V_500 )
V_168 = 2 ;
else
V_168 = 1 ;
V_349 = F_78 ( V_166 , V_168 ) ;
if ( F_94 ( V_349 ) )
return F_95 ( V_349 ) ;
V_308 = (struct V_59 * ) V_349 -> V_62 ;
V_308 -> V_320 = V_28 ;
V_308 -> V_321 = V_344 ;
V_308 -> V_147 = F_55 ( V_166 -> V_196 . V_135 ) ;
V_308 -> V_64 = 0 ;
V_308 -> V_323 = 0 ;
V_308 -> V_63 = 0 ;
V_308 -> V_324 = 0 ;
F_35 ( V_349 , V_65 , V_56 , NULL , F_103 ( V_166 ) ) ;
return 0 ;
}
static int F_190 ( struct V_144 * V_166 , const struct V_345 * V_346 )
{
struct V_10 * V_10 = V_166 ? F_103 ( V_166 ) : V_346 -> V_10 ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
if ( F_3 ( & V_12 -> V_17 ) == 0 )
return 0 ;
switch ( V_346 -> V_329 ) {
case V_343 :
return F_189 ( V_166 , V_346 ) ;
case V_337 :
case V_339 :
case V_341 :
return F_102 ( V_166 , V_346 ) ;
case V_373 :
return F_127 ( V_346 ) ;
case V_501 :
break;
default:
F_11 ( L_3 , V_346 -> V_329 ) ;
break;
}
return 0 ;
}
static int F_191 ( struct V_383 * V_384 , int V_385 , const struct V_345 * V_346 )
{
if ( V_384 && V_384 -> type != V_392 )
return 0 ;
switch ( V_346 -> V_329 ) {
case V_336 :
return F_188 ( V_384 , V_346 ) ;
case V_330 :
case V_332 :
case V_334 :
return F_151 ( V_384 , V_385 , V_346 ) ;
case V_471 :
if ( V_346 -> V_62 . type != V_392 )
break;
return F_177 ( V_346 ) ;
default:
F_11 ( L_2 , V_346 -> V_329 ) ;
break;
}
return 0 ;
}
static T_6 F_192 ( void )
{
T_6 V_502 ;
static T_10 V_503 ;
do {
V_502 = F_193 ( & V_503 ) ;
} while ( ! V_502 );
return V_502 ;
}
static int F_194 ( struct V_144 * V_166 , struct V_395 * V_396 , struct V_383 * V_384 , int V_385 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
struct V_77 * V_80 ;
struct V_409 * V_410 ;
int V_180 ;
int V_177 ;
struct V_91 * V_92 ;
struct V_175 * V_176 ;
int V_98 = 0 ;
V_180 = F_63 ( V_166 -> V_183 . V_136 ) ;
if ( ! V_180 )
return - V_72 ;
V_177 = sizeof( struct V_59 ) +
( sizeof( struct V_77 ) * 2 ) +
( V_180 * 2 ) +
sizeof( struct V_409 ) ;
if ( V_166 -> V_196 . V_135 == V_130 )
V_177 += F_184 ( V_396 ) ;
else if ( V_166 -> V_196 . V_135 == V_132 )
V_177 += F_185 ( V_396 ) ;
if ( ( V_176 = V_166 -> V_184 ) ) {
V_98 = F_64 ( V_176 -> V_105 ) ;
V_177 += sizeof( struct V_91 ) + V_98 ;
}
V_8 = F_42 ( V_177 + 16 , V_65 ) ;
if ( V_8 == NULL )
return - V_30 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_320 = V_28 ;
V_60 -> V_321 = V_504 ;
V_60 -> V_147 = F_55 ( V_166 -> V_196 . V_135 ) ;
V_60 -> V_74 = V_177 / sizeof( V_75 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_323 = 0 ;
V_60 -> V_63 = V_166 -> V_200 . V_304 = F_192 () ;
V_60 -> V_324 = 0 ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_180 ) ;
V_80 -> V_88 =
( sizeof( struct V_77 ) + V_180 ) /
sizeof( V_75 ) ;
V_80 -> V_249 = V_121 ;
V_80 -> V_250 = 0 ;
V_80 -> V_251 = 0 ;
V_80 -> V_89 =
F_67 ( & V_166 -> V_183 . V_186 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_166 -> V_183 . V_136 ) ;
if ( ! V_80 -> V_89 )
F_76 () ;
V_80 = (struct V_77 * ) F_44 ( V_8 ,
sizeof( struct V_77 ) + V_180 ) ;
V_80 -> V_88 =
( sizeof( struct V_77 ) + V_180 ) /
sizeof( V_75 ) ;
V_80 -> V_249 = V_122 ;
V_80 -> V_250 = 0 ;
V_80 -> V_251 = 0 ;
V_80 -> V_89 =
F_67 ( & V_166 -> V_196 . V_252 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_166 -> V_183 . V_136 ) ;
if ( ! V_80 -> V_89 )
F_76 () ;
V_410 = (struct V_409 * ) F_44 ( V_8 , sizeof( struct V_409 ) ) ;
V_410 -> V_411 = sizeof( struct V_409 ) / sizeof( V_75 ) ;
V_410 -> V_416 = V_417 ;
V_410 -> V_418 = V_422 ;
V_410 -> V_424 = V_385 + 1 ;
V_410 -> V_425 = V_384 -> V_426 ;
if ( V_166 -> V_196 . V_135 == V_130 )
F_186 ( V_8 , V_396 ) ;
else if ( V_166 -> V_196 . V_135 == V_132 )
F_187 ( V_8 , V_396 ) ;
if ( V_176 ) {
V_92 = (struct V_91 * ) F_44 ( V_8 ,
sizeof( struct V_91 ) + V_98 ) ;
V_92 -> V_95 =
( sizeof( struct V_91 ) + V_98 ) / sizeof( V_75 ) ;
V_92 -> V_100 = V_125 ;
V_92 -> V_102 = V_176 -> V_101 ;
V_92 -> V_104 = V_176 -> V_103 ;
V_92 -> V_93 = V_176 -> V_105 ;
memcpy ( V_92 + 1 , V_176 -> V_286 ,
V_176 -> V_105 ) ;
}
return F_35 ( V_8 , V_65 , V_56 , NULL , F_103 ( V_166 ) ) ;
}
static struct V_383 * F_195 ( struct V_2 * V_3 , int V_505 ,
T_7 * V_62 , int V_46 , int * V_385 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_383 * V_384 ;
struct V_409 * V_410 = (struct V_409 * ) V_62 ;
struct V_91 * V_92 ;
switch ( V_3 -> V_37 ) {
case V_87 :
if ( V_505 != V_506 ) {
* V_385 = - V_306 ;
return NULL ;
}
break;
#if F_46 ( V_82 ) || F_46 ( V_83 )
case V_90 :
if ( V_505 != V_507 ) {
* V_385 = - V_306 ;
return NULL ;
}
break;
#endif
default:
* V_385 = - V_72 ;
return NULL ;
}
* V_385 = - V_72 ;
if ( V_46 < sizeof( struct V_409 ) ||
V_410 -> V_411 * 8 > V_46 ||
V_410 -> V_418 > V_508 ||
( ! V_410 -> V_424 || V_410 -> V_424 > V_509 ) )
return NULL ;
V_384 = F_153 ( V_10 , V_65 ) ;
if ( V_384 == NULL ) {
* V_385 = - V_43 ;
return NULL ;
}
V_384 -> V_420 = ( V_410 -> V_418 == V_419 ?
V_435 : V_421 ) ;
V_384 -> V_230 . V_240 = V_438 ;
V_384 -> V_230 . V_233 = V_438 ;
V_384 -> V_230 . V_239 = V_438 ;
V_384 -> V_230 . V_231 = V_438 ;
V_384 -> V_136 = V_3 -> V_37 ;
V_384 -> V_386 = 0 ;
if ( V_410 -> V_418 == V_422 &&
( * V_385 = F_146 ( V_384 , V_410 ) ) < 0 )
goto V_34;
if ( V_46 >= ( V_410 -> V_411 * 8 +
sizeof( struct V_91 ) ) ) {
char * V_76 = ( char * ) V_410 ;
struct V_96 * V_97 ;
V_76 += V_410 -> V_411 * 8 ;
V_92 = (struct V_91 * ) V_76 ;
if ( V_46 < V_410 -> V_411 * 8 +
V_92 -> V_95 ) {
* V_385 = - V_72 ;
goto V_34;
}
if ( ( * V_385 = F_49 ( V_76 ) ) )
goto V_34;
V_97 = F_50 ( V_92 ) ;
* V_385 = F_155 ( & V_384 -> V_184 , V_97 ) ;
F_83 ( V_97 ) ;
if ( * V_385 )
goto V_34;
}
* V_385 = V_410 -> V_424 - 1 ;
return V_384 ;
V_34:
V_384 -> V_389 . V_439 = 1 ;
F_160 ( V_384 ) ;
return NULL ;
}
static int F_196 ( struct V_144 * V_166 , T_4 * V_510 , T_5 V_254 )
{
struct V_40 * V_8 ;
struct V_59 * V_60 ;
struct V_145 * V_137 ;
struct V_77 * V_80 ;
struct V_193 * V_272 ;
int V_180 ;
int V_177 ;
T_8 V_126 = ( V_166 -> V_196 . V_135 == V_132 ? V_131 : 0 ) ;
struct V_181 * V_182 = NULL ;
V_180 = F_63 ( V_166 -> V_183 . V_136 ) ;
if ( ! V_180 )
return - V_72 ;
if ( ! V_126 )
return - V_72 ;
if ( ! V_166 -> V_190 )
return - V_72 ;
V_182 = V_166 -> V_190 ;
V_177 = sizeof( struct V_59 ) +
sizeof( struct V_145 ) +
( sizeof( struct V_77 ) * 2 ) +
( V_180 * 2 ) +
( sizeof( struct V_193 ) * 2 ) ;
V_8 = F_42 ( V_177 + 16 , V_65 ) ;
if ( V_8 == NULL )
return - V_30 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_320 = V_28 ;
V_60 -> V_321 = V_511 ;
V_60 -> V_147 = V_126 ;
V_60 -> V_74 = V_177 / sizeof( V_75 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_323 = 0 ;
V_60 -> V_63 = V_166 -> V_200 . V_304 = F_192 () ;
V_60 -> V_324 = 0 ;
V_137 = (struct V_145 * ) F_44 ( V_8 , sizeof( struct V_145 ) ) ;
V_137 -> V_194 = sizeof( struct V_145 ) / sizeof( V_75 ) ;
V_137 -> V_195 = V_146 ;
V_137 -> V_149 = V_166 -> V_196 . V_197 ;
V_137 -> V_198 = 0 ;
V_137 -> V_203 = 0 ;
V_137 -> V_210 = 0 ;
V_137 -> V_216 = 0 ;
V_137 -> V_218 = 0 ;
V_80 = (struct V_77 * )
F_44 ( V_8 , sizeof( struct V_77 ) + V_180 ) ;
V_80 -> V_88 =
( sizeof( struct V_77 ) + V_180 ) /
sizeof( V_75 ) ;
V_80 -> V_249 = V_121 ;
V_80 -> V_250 = 0 ;
V_80 -> V_251 = 0 ;
V_80 -> V_89 =
F_67 ( & V_166 -> V_183 . V_186 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_166 -> V_183 . V_136 ) ;
if ( ! V_80 -> V_89 )
F_76 () ;
V_272 = (struct V_193 * ) F_44 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_75 ) ;
V_272 -> V_279 = V_280 ;
V_272 -> V_281 = V_182 -> V_282 ;
V_272 -> V_283 = 0 ;
V_80 = (struct V_77 * )
F_44 ( V_8 , sizeof( struct V_77 ) + V_180 ) ;
V_80 -> V_88 =
( sizeof( struct V_77 ) + V_180 ) /
sizeof( V_75 ) ;
V_80 -> V_249 = V_122 ;
V_80 -> V_250 = 0 ;
V_80 -> V_251 = 0 ;
V_80 -> V_89 =
F_67 ( V_510 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_166 -> V_183 . V_136 ) ;
if ( ! V_80 -> V_89 )
F_76 () ;
V_272 = (struct V_193 * ) F_44 ( V_8 , sizeof ( * V_272 ) ) ;
V_272 -> V_278 = sizeof( * V_272 ) / sizeof( V_75 ) ;
V_272 -> V_279 = V_284 ;
V_272 -> V_281 = V_254 ;
V_272 -> V_283 = 0 ;
return F_35 ( V_8 , V_65 , V_56 , NULL , F_103 ( V_166 ) ) ;
}
static int F_197 ( struct V_40 * V_8 , int V_512 , int type ,
const struct V_440 * V_185 )
{
struct V_77 * V_80 ;
V_80 = (struct V_77 * ) F_44 ( V_8 , sizeof( struct V_77 ) + V_512 ) ;
V_80 -> V_88 = ( sizeof( struct V_77 ) + V_512 ) / 8 ;
V_80 -> V_249 = type ;
V_80 -> V_250 = V_185 -> V_135 ;
V_80 -> V_251 = 0 ;
switch ( type ) {
case V_121 :
V_80 -> V_89 = V_185 -> V_253 ;
F_67 ( & V_185 -> V_186 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_185 -> V_136 ) ;
break;
case V_122 :
V_80 -> V_89 = V_185 -> V_414 ;
F_67 ( & V_185 -> V_252 , 0 ,
(struct V_79 * ) ( V_80 + 1 ) ,
V_185 -> V_136 ) ;
break;
default:
return - V_72 ;
}
return 0 ;
}
static int F_198 ( struct V_40 * V_8 , const struct V_456 * V_457 )
{
struct V_454 * V_455 ;
T_7 * V_137 ;
int V_136 = V_457 -> V_136 ;
int V_406 = F_58 ( V_136 ) ;
int V_513 ;
V_513 = ( sizeof( struct V_454 ) +
F_166 ( V_136 ) ) ;
V_455 = (struct V_454 * ) F_44 ( V_8 , V_513 ) ;
memset ( V_455 , 0 , V_513 ) ;
V_455 -> V_461 = V_513 / 8 ;
V_455 -> V_514 = V_458 ;
V_455 -> V_460 = V_457 -> V_459 ;
V_137 = ( T_7 * ) ( V_455 + 1 ) ;
if ( ! F_67 ( & V_457 -> V_462 , 0 , (struct V_79 * ) V_137 , V_136 ) ||
! F_67 ( & V_457 -> V_463 , 0 , (struct V_79 * ) ( V_137 + V_406 ) , V_136 ) )
return - V_72 ;
return 0 ;
}
static int F_199 ( struct V_40 * V_8 ,
V_73 V_135 , V_73 V_150 , int V_515 ,
T_11 V_270 , V_73 V_136 ,
const T_4 * V_106 , const T_4 * V_107 )
{
struct V_393 * V_394 ;
T_7 * V_137 ;
int V_406 = F_58 ( V_136 ) ;
int V_513 ;
V_513 = sizeof( struct V_393 ) +
F_166 ( V_136 ) ;
V_394 = (struct V_393 * ) F_44 ( V_8 , V_513 ) ;
memset ( V_394 , 0 , V_513 ) ;
V_394 -> V_412 = V_513 ;
V_394 -> V_400 = V_135 ;
V_394 -> V_399 = V_150 ;
V_394 -> V_401 = V_515 ;
V_394 -> V_405 = V_270 ;
V_137 = ( T_7 * ) ( V_394 + 1 ) ;
if ( ! F_67 ( V_106 , 0 , (struct V_79 * ) V_137 , V_136 ) ||
! F_67 ( V_107 , 0 , (struct V_79 * ) ( V_137 + V_406 ) , V_136 ) )
return - V_72 ;
return 0 ;
}
static int F_200 ( const struct V_440 * V_185 , T_7 V_385 , T_7 type ,
const struct V_444 * V_445 , int V_516 ,
const struct V_456 * V_457 )
{
int V_353 ;
int V_517 ;
int V_177 = 0 ;
int V_518 = 0 ;
struct V_40 * V_8 ;
struct V_59 * V_60 ;
struct V_409 * V_410 ;
const struct V_444 * V_519 ;
if ( type != V_392 )
return 0 ;
if ( V_516 <= 0 || V_516 > V_397 )
return - V_72 ;
if ( V_457 != NULL ) {
V_177 += F_64 ( sizeof( struct V_454 ) +
F_166 ( V_457 -> V_136 ) ) ;
}
V_517 = F_63 ( V_185 -> V_136 ) ;
if ( ! V_517 )
return - V_72 ;
V_177 += ( sizeof( struct V_77 ) + V_517 ) * 2 ;
V_518 += sizeof( struct V_409 ) ;
for ( V_353 = 0 , V_519 = V_445 ; V_353 < V_516 ; V_353 ++ , V_519 ++ ) {
V_518 += sizeof( struct V_393 ) +
F_166 ( V_519 -> V_449 ) ;
V_518 += sizeof( struct V_393 ) +
F_166 ( V_519 -> V_452 ) ;
}
V_177 += sizeof( struct V_59 ) + V_518 ;
V_8 = F_42 ( V_177 , V_65 ) ;
if ( V_8 == NULL )
return - V_30 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_320 = V_28 ;
V_60 -> V_321 = V_520 ;
V_60 -> V_147 = F_55 ( V_445 -> V_135 ) ;
V_60 -> V_74 = V_177 / 8 ;
V_60 -> V_64 = 0 ;
V_60 -> V_323 = 0 ;
V_60 -> V_63 = 0 ;
V_60 -> V_324 = 0 ;
if ( V_457 != NULL && ( F_198 ( V_8 , V_457 ) < 0 ) )
return - V_72 ;
F_197 ( V_8 , V_517 , V_121 , V_185 ) ;
F_197 ( V_8 , V_517 , V_122 , V_185 ) ;
V_410 = (struct V_409 * ) F_44 ( V_8 , sizeof( struct V_409 ) ) ;
V_410 -> V_411 = V_518 / 8 ;
V_410 -> V_416 = V_417 ;
V_410 -> V_418 = V_422 ;
V_410 -> V_424 = V_385 + 1 ;
V_410 -> V_425 = 0 ;
V_410 -> V_427 = 0 ;
for ( V_353 = 0 , V_519 = V_445 ; V_353 < V_516 ; V_353 ++ , V_519 ++ ) {
int V_150 = F_65 ( V_519 -> V_150 ) ;
if ( V_150 < 0 )
goto V_23;
if ( F_199 ( V_8 , V_519 -> V_135 , V_150 ,
( V_519 -> V_270 ? V_404 : V_430 ) ,
V_519 -> V_270 , V_519 -> V_449 ,
& V_519 -> V_447 , & V_519 -> V_448 ) < 0 )
goto V_23;
if ( F_199 ( V_8 , V_519 -> V_135 , V_150 ,
( V_519 -> V_270 ? V_404 : V_430 ) ,
V_519 -> V_270 , V_519 -> V_452 ,
& V_519 -> V_450 , & V_519 -> V_451 ) < 0 )
goto V_23;
}
F_35 ( V_8 , V_65 , V_54 , NULL , & V_521 ) ;
return 0 ;
V_23:
F_5 ( V_8 ) ;
return - V_72 ;
}
static int F_200 ( const struct V_440 * V_185 , T_7 V_385 , T_7 type ,
const struct V_444 * V_445 , int V_516 ,
const struct V_456 * V_457 )
{
return - V_464 ;
}
static int F_201 ( struct V_522 * V_522 ,
struct V_20 * V_2 , struct V_523 * V_524 , T_12 V_46 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_40 * V_8 = NULL ;
struct V_59 * V_60 = NULL ;
int V_23 ;
V_23 = - V_306 ;
if ( V_524 -> V_525 & V_526 )
goto V_34;
V_23 = - V_474 ;
if ( ( unsigned ) V_46 > V_3 -> V_527 - 32 )
goto V_34;
V_23 = - V_43 ;
V_8 = F_42 ( V_46 , V_32 ) ;
if ( V_8 == NULL )
goto V_34;
V_23 = - V_528 ;
if ( F_202 ( F_44 ( V_8 , V_46 ) , V_524 -> V_529 , V_46 ) )
goto V_34;
V_60 = F_181 ( V_8 , & V_23 ) ;
if ( ! V_60 )
goto V_34;
F_15 ( & V_530 ) ;
V_23 = F_180 ( V_3 , V_8 , V_60 ) ;
F_17 ( & V_530 ) ;
V_34:
if ( V_23 && V_60 && F_41 ( V_60 , V_23 , V_3 ) == 0 )
V_23 = 0 ;
F_5 ( V_8 ) ;
return V_23 ? : V_46 ;
}
static int F_203 ( struct V_522 * V_522 ,
struct V_20 * V_2 , struct V_523 * V_524 , T_12 V_46 ,
int V_219 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_40 * V_8 ;
int V_531 , V_23 ;
V_23 = - V_72 ;
if ( V_219 & ~ ( V_532 | V_533 | V_534 | V_535 ) )
goto V_34;
V_524 -> V_536 = 0 ;
V_8 = F_204 ( V_3 , V_219 , V_219 & V_533 , & V_23 ) ;
if ( V_8 == NULL )
goto V_34;
V_531 = V_8 -> V_46 ;
if ( V_531 > V_46 ) {
V_524 -> V_525 |= V_534 ;
V_531 = V_46 ;
}
F_205 ( V_8 ) ;
V_23 = F_206 ( V_8 , 0 , V_524 -> V_529 , V_531 ) ;
if ( V_23 )
goto V_537;
F_207 ( V_524 , V_3 , V_8 ) ;
V_23 = ( V_219 & V_534 ) ? V_8 -> V_46 : V_531 ;
if ( V_6 -> V_7 . V_7 != NULL &&
3 * F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 )
F_39 ( V_6 ) ;
V_537:
F_208 ( V_3 , V_8 ) ;
V_34:
return V_23 ;
}
static int F_209 ( struct V_538 * V_539 , void * V_540 )
{
struct V_2 * V_541 = F_210 ( V_540 ) ;
if ( V_540 == V_542 )
F_211 ( V_539 , L_4 ) ;
else
F_211 ( V_539 , L_5 ,
V_541 ,
F_3 ( & V_541 -> V_543 ) ,
F_212 ( V_541 ) ,
F_213 ( V_541 ) ,
F_214 ( V_541 ) ,
F_215 ( V_541 )
) ;
return 0 ;
}
static void * F_216 ( struct V_538 * V_539 , T_13 * V_544 )
__acquires( T_14 )
{
struct V_10 * V_10 = F_217 ( V_539 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_36 () ;
return F_218 ( & V_12 -> V_19 , * V_544 ) ;
}
static void * F_219 ( struct V_538 * V_539 , void * V_540 , T_13 * V_544 )
{
struct V_10 * V_10 = F_217 ( V_539 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
return F_220 ( V_540 , & V_12 -> V_19 , V_544 ) ;
}
static void F_221 ( struct V_538 * V_539 , void * V_540 )
__releases( T_14 )
{
F_38 () ;
}
static int F_222 ( struct V_545 * V_545 , struct V_546 * V_546 )
{
return F_223 ( V_545 , V_546 , & V_547 ,
sizeof( struct V_548 ) ) ;
}
static int T_15 F_224 ( struct V_10 * V_10 )
{
struct V_549 * V_550 ;
V_550 = F_225 ( V_10 , L_6 , 0 , & V_551 ) ;
if ( V_550 == NULL )
return - V_30 ;
return 0 ;
}
static void T_16 F_226 ( struct V_10 * V_10 )
{
F_227 ( V_10 , L_6 ) ;
}
static inline int F_224 ( struct V_10 * V_10 )
{
return 0 ;
}
static inline void F_226 ( struct V_10 * V_10 )
{
}
static int T_15 F_228 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
int V_552 ;
F_229 ( & V_12 -> V_19 ) ;
F_230 ( & V_12 -> V_17 , 0 ) ;
V_552 = F_224 ( V_10 ) ;
return V_552 ;
}
static void T_16 F_231 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_226 ( V_10 ) ;
F_43 ( ! F_232 ( & V_12 -> V_19 ) ) ;
}
static void T_17 F_233 ( void )
{
F_234 ( & V_553 ) ;
F_235 ( V_31 ) ;
F_236 ( & V_554 ) ;
F_237 ( & V_33 ) ;
}
static int T_18 F_238 ( void )
{
int V_23 = F_239 ( & V_33 , 0 ) ;
if ( V_23 != 0 )
goto V_34;
V_23 = F_240 ( & V_554 ) ;
if ( V_23 != 0 )
goto V_555;
V_23 = F_241 ( & V_556 ) ;
if ( V_23 != 0 )
goto V_557;
V_23 = F_242 ( & V_553 ) ;
if ( V_23 != 0 )
goto V_558;
V_34:
return V_23 ;
V_558:
F_235 ( V_31 ) ;
V_557:
F_236 ( & V_554 ) ;
V_555:
F_237 ( & V_33 ) ;
goto V_34;
}
