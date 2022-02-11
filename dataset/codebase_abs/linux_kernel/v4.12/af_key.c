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
struct V_1 * V_6 ;
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
V_6 = F_1 ( V_3 ) ;
F_23 ( & V_6 -> V_36 ) ;
V_2 -> V_37 = & V_38 ;
F_24 ( V_2 , V_3 ) ;
V_3 -> V_39 = V_32 ;
V_3 -> V_40 = F_6 ;
F_25 ( & V_12 -> V_17 ) ;
F_14 ( V_3 ) ;
return 0 ;
V_35:
return V_23 ;
}
static int F_26 ( struct V_20 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
if ( ! V_3 )
return 0 ;
F_18 ( V_3 ) ;
F_27 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_9 ( & V_3 -> V_41 ) ;
F_28 () ;
F_29 ( V_3 ) ;
return 0 ;
}
static int F_30 ( struct V_42 * V_8 , struct V_42 * * V_43 ,
T_1 V_44 , struct V_2 * V_3 )
{
int V_23 = - V_45 ;
F_31 ( V_3 ) ;
if ( * V_43 == NULL ) {
if ( F_3 ( & V_8 -> V_46 ) != 1 ) {
* V_43 = F_32 ( V_8 , V_44 ) ;
} else {
* V_43 = V_8 ;
F_25 ( & V_8 -> V_46 ) ;
}
}
if ( * V_43 != NULL ) {
if ( F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 ) {
F_33 ( * V_43 , V_3 ) ;
F_34 ( & V_3 -> V_14 , * V_43 ) ;
V_3 -> V_47 ( V_3 ) ;
* V_43 = NULL ;
V_23 = 0 ;
}
}
F_29 ( V_3 ) ;
return V_23 ;
}
static int F_35 ( struct V_42 * V_8 ,
int V_48 , struct V_2 * V_49 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
struct V_2 * V_3 ;
struct V_42 * V_43 = NULL ;
int V_23 = - V_50 ;
if ( ! V_8 )
return - V_31 ;
F_36 () ;
F_37 (sk, &net_pfkey->table) {
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_51 ;
if ( V_6 -> V_52 )
F_30 ( V_8 , & V_43 , V_53 , V_3 ) ;
if ( V_3 == V_49 )
continue;
if ( V_48 != V_54 ) {
if ( V_48 & V_55 )
continue;
if ( ( V_48 & V_56 ) &&
! V_6 -> V_57 )
continue;
if ( V_48 & V_58 )
continue;
}
V_51 = F_30 ( V_8 , & V_43 , V_53 , V_3 ) ;
if ( ( V_48 & V_56 ) && V_23 )
V_23 = V_51 ;
}
F_38 () ;
if ( V_49 != NULL )
V_23 = F_30 ( V_8 , & V_43 , V_33 , V_49 ) ;
F_5 ( V_43 ) ;
F_5 ( V_8 ) ;
return V_23 ;
}
static int F_39 ( struct V_1 * V_6 )
{
struct V_59 * V_60 ;
int V_61 ;
F_15 ( & V_6 -> V_36 ) ;
if ( ! V_6 -> V_7 . V_7 ) {
V_61 = 0 ;
goto V_35;
}
V_61 = V_6 -> V_7 . V_7 ( V_6 ) ;
if ( V_61 == - V_45 ) {
V_61 = 0 ;
goto V_35;
}
if ( V_6 -> V_7 . V_8 ) {
if ( ! F_2 ( & V_6 -> V_3 ) ) {
V_61 = 0 ;
goto V_35;
}
V_60 = (struct V_59 * ) V_6 -> V_7 . V_8 -> V_62 ;
V_60 -> V_63 = 0 ;
V_60 -> V_64 = V_61 ;
F_35 ( V_6 -> V_7 . V_8 , V_58 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = NULL ;
}
F_4 ( V_6 ) ;
V_35:
F_17 ( & V_6 -> V_36 ) ;
return V_61 ;
}
static inline void F_40 ( struct V_59 * V_65 ,
const struct V_59 * V_66 )
{
* V_65 = * V_66 ;
}
static int F_41 ( const struct V_59 * V_66 , int V_23 , struct V_2 * V_3 )
{
struct V_42 * V_8 = F_42 ( sizeof( struct V_59 ) + 16 , V_33 ) ;
struct V_59 * V_60 ;
if ( ! V_8 )
return - V_45 ;
V_23 = - V_23 ;
if ( V_23 == V_67 ||
V_23 == V_68 ||
V_23 == V_69 )
V_23 = V_70 ;
if ( V_23 >= 512 )
V_23 = V_71 ;
F_43 ( V_23 <= 0 || V_23 >= 256 ) ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
F_40 ( V_60 , V_66 ) ;
V_60 -> V_64 = ( V_72 ) V_23 ;
V_60 -> V_73 = ( sizeof( struct V_59 ) /
sizeof( V_74 ) ) ;
F_35 ( V_8 , V_58 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_45 ( const void * V_75 )
{
const struct V_76 * V_77 = V_75 ;
const struct V_78 * V_79 = ( const struct V_78 * ) ( V_77 + 1 ) ;
const struct V_80 * sin ;
#if F_46 ( V_81 )
const struct V_82 * V_83 ;
#endif
int V_84 ;
switch ( V_79 -> V_85 ) {
case V_86 :
V_84 = F_47 ( sizeof( * V_77 ) + sizeof( * sin ) , sizeof( V_74 ) ) ;
if ( V_77 -> V_87 != V_84 ||
V_77 -> V_88 > 32 )
return - V_71 ;
break;
#if F_46 ( V_81 )
case V_89 :
V_84 = F_47 ( sizeof( * V_77 ) + sizeof( * V_83 ) , sizeof( V_74 ) ) ;
if ( V_77 -> V_87 != V_84 ||
V_77 -> V_88 > 128 )
return - V_71 ;
break;
#endif
default:
return - V_71 ;
}
return 0 ;
}
static inline int F_48 ( const struct V_90 * V_91 )
{
return F_47 ( sizeof( struct V_90 ) +
V_91 -> V_92 ,
sizeof( V_74 ) ) ;
}
static inline int F_49 ( const void * V_75 )
{
const struct V_90 * V_91 = V_75 ;
int V_84 = V_91 -> V_92 ;
if ( V_84 > V_93 )
return - V_71 ;
V_84 = F_48 ( V_91 ) ;
if ( V_91 -> V_94 != V_84 )
return - V_71 ;
return 0 ;
}
static inline struct V_95 * F_50 ( const struct V_90 * V_91 ,
T_1 V_96 )
{
struct V_95 * V_97 = NULL ;
int V_98 = V_91 -> V_92 ;
V_97 = F_51 ( ( sizeof( * V_97 ) + V_98 ) , V_96 ) ;
if ( ! V_97 )
return NULL ;
V_97 -> V_84 = F_48 ( V_91 ) ;
V_97 -> V_99 = V_91 -> V_100 ;
V_97 -> V_101 = V_91 -> V_102 ;
V_97 -> V_103 = V_91 -> V_104 ;
V_97 -> V_105 = V_91 -> V_92 ;
memcpy ( V_97 + 1 , V_91 + 1 ,
V_97 -> V_105 ) ;
return V_97 ;
}
static int F_52 ( const struct V_76 * V_106 ,
const struct V_76 * V_107 )
{
const struct V_78 * V_108 , * V_109 ;
if ( ! V_106 || ! V_107 )
return 0 ;
V_108 = ( const struct V_78 * ) ( V_106 + 1 ) ;
V_109 = ( const struct V_78 * ) ( V_107 + 1 ) ;
if ( V_108 -> V_85 != V_109 -> V_85 )
return 0 ;
if ( V_108 -> V_85 != V_86
#if F_46 ( V_81 )
&& V_108 -> V_85 != V_89
#endif
)
return 0 ;
return 1 ;
}
static int F_53 ( struct V_42 * V_8 , const struct V_59 * V_60 , void * * V_110 )
{
const char * V_75 = ( char * ) V_60 ;
int V_84 = V_8 -> V_84 ;
V_84 -= sizeof( * V_60 ) ;
V_75 += sizeof( * V_60 ) ;
while ( V_84 > 0 ) {
const struct V_111 * V_112 = ( const struct V_111 * ) V_75 ;
T_2 V_113 ;
int V_114 ;
V_114 = V_112 -> V_115 ;
V_114 *= sizeof( V_74 ) ;
V_113 = V_112 -> V_116 ;
if ( V_114 < sizeof( V_74 ) ||
V_114 > V_84 ||
V_113 == V_117 )
return - V_71 ;
if ( V_113 <= V_118 ) {
int V_119 = ( int ) V_120 [ V_113 ] ;
if ( V_114 < V_119 )
return - V_71 ;
if ( V_110 [ V_113 - 1 ] != NULL )
return - V_71 ;
if ( V_113 == V_121 ||
V_113 == V_122 ||
V_113 == V_123 ||
V_113 == V_124 ) {
if ( F_45 ( V_75 ) )
return - V_71 ;
}
if ( V_113 == V_125 ) {
if ( F_49 ( V_75 ) )
return - V_71 ;
}
V_110 [ V_113 - 1 ] = ( void * ) V_75 ;
}
V_75 += V_114 ;
V_84 -= V_114 ;
}
return 0 ;
}
static T_2
F_54 ( V_72 V_126 )
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
default:
return 0 ;
}
}
static V_72
F_55 ( T_2 V_135 )
{
switch ( V_135 ) {
case V_130 :
return V_129 ;
case V_132 :
return V_131 ;
case V_134 :
return V_133 ;
default:
return 0 ;
}
}
static V_72 F_56 ( V_72 V_135 )
{
return V_135 == V_128 ? 0 : V_135 ;
}
static V_72 F_57 ( V_72 V_135 )
{
return V_135 ? V_135 : V_128 ;
}
static inline int F_58 ( T_3 V_136 )
{
switch ( V_136 ) {
case V_86 :
return sizeof( struct V_80 ) ;
#if F_46 ( V_81 )
case V_89 :
return sizeof( struct V_82 ) ;
#endif
}
return 0 ;
}
static
int F_59 ( const struct V_78 * V_137 , T_4 * V_138 )
{
switch ( V_137 -> V_85 ) {
case V_86 :
V_138 -> V_139 =
( (struct V_80 * ) V_137 ) -> V_140 . V_108 ;
return V_86 ;
#if F_46 ( V_81 )
case V_89 :
memcpy ( V_138 -> V_141 ,
& ( (struct V_82 * ) V_137 ) -> V_142 ,
sizeof( struct V_143 ) ) ;
return V_89 ;
#endif
}
return 0 ;
}
static
int F_60 ( const struct V_76 * V_79 , T_4 * V_138 )
{
return F_59 ( (struct V_78 * ) ( V_79 + 1 ) ,
V_138 ) ;
}
static struct V_144 * F_61 ( struct V_10 * V_10 , const struct V_59 * V_60 , void * const * V_110 )
{
const struct V_145 * V_137 ;
const struct V_76 * V_79 ;
T_2 V_135 ;
unsigned short V_136 ;
T_4 * V_138 ;
V_137 = V_110 [ V_146 - 1 ] ;
if ( V_137 == NULL )
return NULL ;
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 )
return NULL ;
V_79 = V_110 [ V_122 - 1 ] ;
if ( V_79 == NULL )
return NULL ;
V_136 = ( ( const struct V_78 * ) ( V_79 + 1 ) ) -> V_85 ;
switch ( V_136 ) {
case V_86 :
V_138 = ( T_4 * ) & ( ( const struct V_80 * ) ( V_79 + 1 ) ) -> V_140 ;
break;
#if F_46 ( V_81 )
case V_89 :
V_138 = ( T_4 * ) & ( ( const struct V_82 * ) ( V_79 + 1 ) ) -> V_142 ;
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
struct V_78 * V_137 ,
unsigned short V_136 )
{
switch ( V_136 ) {
case V_86 :
{
struct V_80 * sin = (struct V_80 * ) V_137 ;
sin -> V_159 = V_86 ;
sin -> V_160 = V_158 ;
sin -> V_140 . V_108 = V_138 -> V_139 ;
memset ( sin -> V_161 , 0 , sizeof( sin -> V_161 ) ) ;
return 32 ;
}
#if F_46 ( V_81 )
case V_89 :
{
struct V_82 * V_83 = (struct V_82 * ) V_137 ;
V_83 -> V_162 = V_89 ;
V_83 -> V_163 = V_158 ;
V_83 -> V_164 = 0 ;
V_83 -> V_142 = V_138 -> V_165 ;
V_83 -> V_166 = 0 ;
return 128 ;
}
#endif
}
return 0 ;
}
static struct V_42 * F_68 ( const struct V_144 * V_167 ,
int V_168 , int V_169 )
{
struct V_42 * V_8 ;
struct V_59 * V_60 ;
struct V_145 * V_137 ;
struct V_170 * V_171 ;
struct V_76 * V_79 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
struct V_90 * V_91 ;
struct V_176 * V_177 ;
int V_98 = 0 ;
int V_178 ;
int V_179 = 0 ;
int V_180 = 0 ;
int V_181 ;
struct V_182 * V_183 = NULL ;
int V_150 ;
V_181 = F_63 ( V_167 -> V_184 . V_136 ) ;
if ( ! V_181 )
return F_69 ( - V_71 ) ;
V_178 = sizeof( struct V_59 ) + sizeof( struct V_145 ) +
sizeof( struct V_170 ) +
( ( V_169 & 1 ) ? sizeof( struct V_170 ) : 0 ) +
( ( V_169 & 2 ) ? sizeof( struct V_170 ) : 0 ) +
sizeof( struct V_76 ) * 2 +
V_181 * 2 +
sizeof( struct V_174 ) ;
if ( ( V_177 = V_167 -> V_185 ) ) {
V_98 = F_64 ( V_177 -> V_105 ) ;
V_178 += sizeof( struct V_90 ) + V_98 ;
}
if ( ! F_70 ( & V_167 -> V_186 . V_187 , & V_167 -> V_184 . V_187 , V_167 -> V_184 . V_136 ) )
V_178 += sizeof( struct V_76 ) + V_181 ;
if ( V_168 ) {
if ( V_167 -> V_188 && V_167 -> V_188 -> V_189 ) {
V_179 =
F_64 ( ( V_167 -> V_188 -> V_189 + 7 ) / 8 ) ;
V_178 += sizeof( struct V_172 ) + V_179 ;
}
if ( V_167 -> V_190 && V_167 -> V_190 -> V_189 ) {
V_180 =
F_64 ( ( V_167 -> V_190 -> V_189 + 7 ) / 8 ) ;
V_178 += sizeof( struct V_172 ) + V_180 ;
}
}
if ( V_167 -> V_191 )
V_183 = V_167 -> V_191 ;
if ( V_183 && V_183 -> V_192 ) {
V_178 += sizeof( struct V_193 ) ;
V_178 += sizeof( struct V_194 ) ;
V_178 += sizeof( struct V_194 ) ;
}
V_8 = F_42 ( V_178 + 16 , V_53 ) ;
if ( V_8 == NULL )
return F_69 ( - V_45 ) ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
memset ( V_60 , 0 , V_178 ) ;
V_60 -> V_73 = V_178 / sizeof( V_74 ) ;
V_137 = (struct V_145 * ) F_44 ( V_8 , sizeof( struct V_145 ) ) ;
V_137 -> V_195 = sizeof( struct V_145 ) / sizeof( V_74 ) ;
V_137 -> V_196 = V_146 ;
V_137 -> V_149 = V_167 -> V_197 . V_198 ;
V_137 -> V_199 = V_167 -> V_184 . V_200 ;
switch ( V_167 -> V_201 . V_202 ) {
case V_203 :
V_137 -> V_204 = V_167 -> V_201 . V_205 ?
V_206 : V_207 ;
break;
case V_208 :
V_137 -> V_204 = V_209 ;
break;
default:
V_137 -> V_204 = V_210 ;
break;
}
V_137 -> V_211 = 0 ;
if ( V_167 -> V_188 ) {
struct V_212 * V_213 = F_71 ( V_167 -> V_188 -> V_214 , 0 ) ;
V_137 -> V_211 = ( V_213 && V_213 -> V_215 ) ?
V_213 -> V_216 . V_217 : 0 ;
}
V_137 -> V_218 = 0 ;
F_43 ( V_167 -> V_190 && V_167 -> V_219 ) ;
if ( V_167 -> V_190 ) {
struct V_212 * V_213 = F_72 ( V_167 -> V_190 -> V_214 , 0 ) ;
V_137 -> V_218 = ( V_213 && V_213 -> V_215 ) ?
V_213 -> V_216 . V_217 : 0 ;
}
if ( V_167 -> V_219 ) {
struct V_212 * V_213 = F_73 ( V_167 -> V_219 -> V_214 , 0 ) ;
V_137 -> V_218 = ( V_213 && V_213 -> V_215 ) ?
V_213 -> V_216 . V_217 : 0 ;
}
V_137 -> V_220 = 0 ;
if ( V_167 -> V_184 . V_221 & V_222 )
V_137 -> V_220 |= V_223 ;
if ( V_167 -> V_184 . V_221 & V_224 )
V_137 -> V_220 |= V_225 ;
if ( V_167 -> V_184 . V_221 & V_226 )
V_137 -> V_220 |= V_227 ;
if ( V_169 & 2 ) {
V_171 = (struct V_170 * ) F_44 ( V_8 ,
sizeof( struct V_170 ) ) ;
V_171 -> V_228 =
sizeof( struct V_170 ) / sizeof( V_74 ) ;
V_171 -> V_229 = V_230 ;
V_171 -> V_231 = F_74 ( V_167 -> V_232 . V_233 ) ;
V_171 -> V_234 = F_74 ( V_167 -> V_232 . V_235 ) ;
V_171 -> V_236 = V_167 -> V_232 . V_237 ;
V_171 -> V_238 = V_167 -> V_232 . V_239 ;
}
if ( V_169 & 1 ) {
V_171 = (struct V_170 * ) F_44 ( V_8 ,
sizeof( struct V_170 ) ) ;
V_171 -> V_228 =
sizeof( struct V_170 ) / sizeof( V_74 ) ;
V_171 -> V_229 = V_240 ;
V_171 -> V_231 = F_74 ( V_167 -> V_232 . V_241 ) ;
V_171 -> V_234 = F_74 ( V_167 -> V_232 . V_242 ) ;
V_171 -> V_236 = V_167 -> V_232 . V_243 ;
V_171 -> V_238 = V_167 -> V_232 . V_244 ;
}
V_171 = (struct V_170 * ) F_44 ( V_8 ,
sizeof( struct V_170 ) ) ;
V_171 -> V_228 =
sizeof( struct V_170 ) / sizeof( V_74 ) ;
V_171 -> V_229 = V_245 ;
V_171 -> V_231 = V_167 -> V_246 . V_247 ;
V_171 -> V_234 = V_167 -> V_246 . V_248 ;
V_171 -> V_236 = V_167 -> V_246 . V_249 ;
V_171 -> V_238 = V_167 -> V_246 . V_250 ;
V_79 = (struct V_76 * ) F_44 ( V_8 ,
sizeof( struct V_76 ) + V_181 ) ;
V_79 -> V_87 =
( sizeof( struct V_76 ) + V_181 ) /
sizeof( V_74 ) ;
V_79 -> V_251 = V_121 ;
V_79 -> V_252 = 0 ;
V_79 -> V_253 = 0 ;
V_79 -> V_88 =
F_67 ( & V_167 -> V_184 . V_187 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_167 -> V_184 . V_136 ) ;
if ( ! V_79 -> V_88 )
F_75 () ;
V_79 = (struct V_76 * ) F_44 ( V_8 ,
sizeof( struct V_76 ) + V_181 ) ;
V_79 -> V_87 =
( sizeof( struct V_76 ) + V_181 ) /
sizeof( V_74 ) ;
V_79 -> V_251 = V_122 ;
V_79 -> V_252 = 0 ;
V_79 -> V_253 = 0 ;
V_79 -> V_88 =
F_67 ( & V_167 -> V_197 . V_254 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_167 -> V_184 . V_136 ) ;
if ( ! V_79 -> V_88 )
F_75 () ;
if ( ! F_70 ( & V_167 -> V_186 . V_187 , & V_167 -> V_184 . V_187 ,
V_167 -> V_184 . V_136 ) ) {
V_79 = (struct V_76 * ) F_44 ( V_8 ,
sizeof( struct V_76 ) + V_181 ) ;
V_79 -> V_87 =
( sizeof( struct V_76 ) + V_181 ) /
sizeof( V_74 ) ;
V_79 -> V_251 = V_123 ;
V_79 -> V_252 =
F_57 ( V_167 -> V_186 . V_135 ) ;
V_79 -> V_88 = V_167 -> V_186 . V_255 ;
V_79 -> V_253 = 0 ;
F_67 ( & V_167 -> V_186 . V_187 , V_167 -> V_186 . V_256 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_167 -> V_184 . V_136 ) ;
}
if ( V_168 && V_179 ) {
V_173 = (struct V_172 * ) F_44 ( V_8 ,
sizeof( struct V_172 ) + V_179 ) ;
V_173 -> V_257 = ( sizeof( struct V_172 ) + V_179 ) /
sizeof( V_74 ) ;
V_173 -> V_258 = V_259 ;
V_173 -> V_260 = V_167 -> V_188 -> V_189 ;
V_173 -> V_261 = 0 ;
memcpy ( V_173 + 1 , V_167 -> V_188 -> V_262 , ( V_167 -> V_188 -> V_189 + 7 ) / 8 ) ;
}
if ( V_168 && V_180 ) {
V_173 = (struct V_172 * ) F_44 ( V_8 ,
sizeof( struct V_172 ) + V_180 ) ;
V_173 -> V_257 = ( sizeof( struct V_172 ) +
V_180 ) / sizeof( V_74 ) ;
V_173 -> V_258 = V_263 ;
V_173 -> V_260 = V_167 -> V_190 -> V_189 ;
V_173 -> V_261 = 0 ;
memcpy ( V_173 + 1 , V_167 -> V_190 -> V_262 ,
( V_167 -> V_190 -> V_189 + 7 ) / 8 ) ;
}
V_175 = (struct V_174 * ) F_44 ( V_8 , sizeof( struct V_174 ) ) ;
V_175 -> V_264 = sizeof( struct V_174 ) / sizeof( V_74 ) ;
V_175 -> V_265 = V_266 ;
if ( ( V_150 = F_65 ( V_167 -> V_184 . V_150 ) ) < 0 ) {
F_5 ( V_8 ) ;
return F_69 ( - V_71 ) ;
}
V_175 -> V_267 = V_150 ;
V_175 -> V_268 = 0 ;
V_175 -> V_269 = 0 ;
V_175 -> V_270 = 0 ;
V_175 -> V_271 = V_167 -> V_184 . V_272 ;
if ( V_183 && V_183 -> V_192 ) {
struct V_193 * V_273 ;
struct V_194 * V_274 ;
V_273 = (struct V_193 * ) F_44 ( V_8 , sizeof( * V_273 ) ) ;
V_273 -> V_275 = sizeof( * V_273 ) / sizeof( V_74 ) ;
V_273 -> V_276 = V_277 ;
V_273 -> V_278 = V_183 -> V_192 ;
V_273 -> V_279 [ 0 ] = 0 ;
V_273 -> V_279 [ 1 ] = 0 ;
V_273 -> V_279 [ 2 ] = 0 ;
V_274 = (struct V_194 * ) F_44 ( V_8 , sizeof ( * V_274 ) ) ;
V_274 -> V_280 = sizeof( * V_274 ) / sizeof( V_74 ) ;
V_274 -> V_281 = V_282 ;
V_274 -> V_283 = V_183 -> V_284 ;
V_274 -> V_285 = 0 ;
V_274 = (struct V_194 * ) F_44 ( V_8 , sizeof ( * V_274 ) ) ;
V_274 -> V_280 = sizeof( * V_274 ) / sizeof( V_74 ) ;
V_274 -> V_281 = V_286 ;
V_274 -> V_283 = V_183 -> V_287 ;
V_274 -> V_285 = 0 ;
}
if ( V_177 ) {
V_91 = (struct V_90 * ) F_44 ( V_8 ,
sizeof( struct V_90 ) + V_98 ) ;
V_91 -> V_94 =
( sizeof( struct V_90 ) + V_98 ) / sizeof( V_74 ) ;
V_91 -> V_100 = V_125 ;
V_91 -> V_102 = V_177 -> V_101 ;
V_91 -> V_104 = V_177 -> V_103 ;
V_91 -> V_92 = V_177 -> V_105 ;
memcpy ( V_91 + 1 , V_177 -> V_288 ,
V_177 -> V_105 ) ;
}
return V_8 ;
}
static inline struct V_42 * F_76 ( const struct V_144 * V_167 )
{
struct V_42 * V_8 ;
V_8 = F_68 ( V_167 , 1 , 3 ) ;
return V_8 ;
}
static inline struct V_42 * F_77 ( const struct V_144 * V_167 ,
int V_169 )
{
return F_68 ( V_167 , 0 , V_169 ) ;
}
static struct V_144 * F_78 ( struct V_10 * V_10 ,
const struct V_59 * V_60 ,
void * const * V_110 )
{
struct V_144 * V_167 ;
const struct V_170 * V_171 ;
const struct V_145 * V_137 ;
const struct V_172 * V_173 ;
const struct V_90 * V_91 ;
T_2 V_135 ;
int V_23 ;
V_137 = V_110 [ V_146 - 1 ] ;
if ( ! V_137 ||
! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) )
return F_69 ( - V_71 ) ;
if ( V_60 -> V_147 == V_131 &&
! V_110 [ V_263 - 1 ] )
return F_69 ( - V_71 ) ;
if ( V_60 -> V_147 == V_129 &&
! V_110 [ V_259 - 1 ] )
return F_69 ( - V_71 ) ;
if ( ! ! V_110 [ V_230 - 1 ] !=
! ! V_110 [ V_240 - 1 ] )
return F_69 ( - V_71 ) ;
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 )
return F_69 ( - V_71 ) ;
V_23 = - V_45 ;
if ( V_137 -> V_211 > V_289 ||
( V_60 -> V_147 == V_133 &&
V_137 -> V_218 > V_290 ) ||
V_137 -> V_218 > V_291 )
return F_69 ( - V_71 ) ;
V_173 = V_110 [ V_259 - 1 ] ;
if ( V_173 != NULL &&
V_137 -> V_211 != V_292 &&
( ( V_173 -> V_260 + 7 ) / 8 == 0 ||
( V_173 -> V_260 + 7 ) / 8 > V_173 -> V_257 * sizeof( V_74 ) ) )
return F_69 ( - V_71 ) ;
V_173 = V_110 [ V_263 - 1 ] ;
if ( V_173 != NULL &&
V_137 -> V_218 != V_293 &&
( ( V_173 -> V_260 + 7 ) / 8 == 0 ||
( V_173 -> V_260 + 7 ) / 8 > V_173 -> V_257 * sizeof( V_74 ) ) )
return F_69 ( - V_71 ) ;
V_167 = F_79 ( V_10 ) ;
if ( V_167 == NULL )
return F_69 ( - V_45 ) ;
V_167 -> V_197 . V_135 = V_135 ;
V_167 -> V_197 . V_198 = V_137 -> V_149 ;
V_167 -> V_184 . V_200 = F_80 (unsigned int, sa->sadb_sa_replay,
(sizeof(x->replay.bitmap) * 8)) ;
if ( V_137 -> V_220 & V_223 )
V_167 -> V_184 . V_221 |= V_222 ;
if ( V_137 -> V_220 & V_225 )
V_167 -> V_184 . V_221 |= V_224 ;
if ( V_137 -> V_220 & V_227 )
V_167 -> V_184 . V_221 |= V_226 ;
V_171 = V_110 [ V_230 - 1 ] ;
if ( V_171 != NULL ) {
V_167 -> V_232 . V_233 = F_81 ( V_171 -> V_231 ) ;
V_167 -> V_232 . V_235 = F_81 ( V_171 -> V_234 ) ;
V_167 -> V_232 . V_237 = V_171 -> V_236 ;
V_167 -> V_232 . V_239 = V_171 -> V_238 ;
}
V_171 = V_110 [ V_240 - 1 ] ;
if ( V_171 != NULL ) {
V_167 -> V_232 . V_241 = F_81 ( V_171 -> V_231 ) ;
V_167 -> V_232 . V_242 = F_81 ( V_171 -> V_234 ) ;
V_167 -> V_232 . V_243 = V_171 -> V_236 ;
V_167 -> V_232 . V_244 = V_171 -> V_238 ;
}
V_91 = V_110 [ V_125 - 1 ] ;
if ( V_91 != NULL ) {
struct V_95 * V_97 = F_50 ( V_91 , V_33 ) ;
if ( ! V_97 )
goto V_35;
V_23 = F_82 ( V_167 , V_97 ) ;
F_83 ( V_97 ) ;
if ( V_23 )
goto V_35;
}
V_23 = - V_45 ;
V_173 = V_110 [ V_259 - 1 ] ;
if ( V_137 -> V_211 ) {
int V_294 = 0 ;
struct V_212 * V_213 = F_84 ( V_137 -> V_211 ) ;
if ( ! V_213 || ! V_213 -> V_215 ) {
V_23 = - V_295 ;
goto V_35;
}
if ( V_173 )
V_294 = ( V_173 -> V_260 + 7 ) / 8 ;
V_167 -> V_188 = F_51 ( sizeof( * V_167 -> V_188 ) + V_294 , V_33 ) ;
if ( ! V_167 -> V_188 ) {
V_23 = - V_31 ;
goto V_35;
}
strcpy ( V_167 -> V_188 -> V_214 , V_213 -> V_296 ) ;
V_167 -> V_188 -> V_189 = 0 ;
if ( V_173 ) {
V_167 -> V_188 -> V_189 = V_173 -> V_260 ;
memcpy ( V_167 -> V_188 -> V_262 , V_173 + 1 , V_294 ) ;
}
V_167 -> V_188 -> V_297 = V_213 -> V_298 . V_299 . V_300 ;
V_167 -> V_184 . V_301 = V_137 -> V_211 ;
}
if ( V_137 -> V_218 ) {
if ( V_60 -> V_147 == V_133 ) {
struct V_212 * V_213 = F_85 ( V_137 -> V_218 ) ;
if ( ! V_213 || ! V_213 -> V_215 ) {
V_23 = - V_295 ;
goto V_35;
}
V_167 -> V_219 = F_51 ( sizeof( * V_167 -> V_219 ) , V_33 ) ;
if ( ! V_167 -> V_219 ) {
V_23 = - V_31 ;
goto V_35;
}
strcpy ( V_167 -> V_219 -> V_214 , V_213 -> V_296 ) ;
V_167 -> V_184 . V_302 = V_137 -> V_218 ;
} else {
int V_294 = 0 ;
struct V_212 * V_213 = F_86 ( V_137 -> V_218 ) ;
if ( ! V_213 || ! V_213 -> V_215 ) {
V_23 = - V_295 ;
goto V_35;
}
V_173 = (struct V_172 * ) V_110 [ V_263 - 1 ] ;
if ( V_173 )
V_294 = ( V_173 -> V_260 + 7 ) / 8 ;
V_167 -> V_190 = F_51 ( sizeof( * V_167 -> V_190 ) + V_294 , V_33 ) ;
if ( ! V_167 -> V_190 ) {
V_23 = - V_31 ;
goto V_35;
}
strcpy ( V_167 -> V_190 -> V_214 , V_213 -> V_296 ) ;
V_167 -> V_190 -> V_189 = 0 ;
if ( V_173 ) {
V_167 -> V_190 -> V_189 = V_173 -> V_260 ;
memcpy ( V_167 -> V_190 -> V_262 , V_173 + 1 , V_294 ) ;
}
V_167 -> V_184 . V_303 = V_137 -> V_218 ;
V_167 -> V_304 = V_213 -> V_298 . V_305 . V_304 ;
}
}
V_167 -> V_184 . V_136 = F_60 ( (struct V_76 * ) V_110 [ V_121 - 1 ] ,
& V_167 -> V_184 . V_187 ) ;
F_60 ( (struct V_76 * ) V_110 [ V_122 - 1 ] ,
& V_167 -> V_197 . V_254 ) ;
if ( V_110 [ V_266 - 1 ] ) {
const struct V_174 * V_175 = V_110 [ V_266 - 1 ] ;
int V_150 = F_66 ( V_175 -> V_267 ) ;
if ( V_150 < 0 ) {
V_23 = - V_71 ;
goto V_35;
}
V_167 -> V_184 . V_150 = V_150 ;
V_167 -> V_184 . V_272 = V_175 -> V_271 ;
}
if ( V_110 [ V_123 - 1 ] ) {
const struct V_76 * V_79 = V_110 [ V_123 - 1 ] ;
V_167 -> V_186 . V_136 = F_60 ( V_79 , & V_167 -> V_186 . V_187 ) ;
V_167 -> V_186 . V_255 = V_79 -> V_88 ;
}
if ( ! V_167 -> V_186 . V_136 )
V_167 -> V_186 . V_136 = V_167 -> V_184 . V_136 ;
if ( V_110 [ V_277 - 1 ] ) {
const struct V_193 * V_273 ;
struct V_182 * V_183 ;
V_167 -> V_191 = F_51 ( sizeof( * V_167 -> V_191 ) , V_33 ) ;
if ( ! V_167 -> V_191 ) {
V_23 = - V_31 ;
goto V_35;
}
V_183 = V_167 -> V_191 ;
V_273 = V_110 [ V_277 - 1 ] ;
V_183 -> V_192 = V_273 -> V_278 ;
if ( V_110 [ V_282 - 1 ] ) {
const struct V_194 * V_274 =
V_110 [ V_282 - 1 ] ;
V_183 -> V_284 = V_274 -> V_283 ;
}
if ( V_110 [ V_286 - 1 ] ) {
const struct V_194 * V_274 =
V_110 [ V_286 - 1 ] ;
V_183 -> V_287 = V_274 -> V_283 ;
}
memset ( & V_183 -> V_306 , 0 , sizeof( V_183 -> V_306 ) ) ;
}
V_23 = F_87 ( V_167 ) ;
if ( V_23 )
goto V_35;
V_167 -> V_201 . V_307 = V_60 -> V_63 ;
return V_167 ;
V_35:
V_167 -> V_201 . V_202 = V_308 ;
F_88 ( V_167 ) ;
return F_69 ( V_23 ) ;
}
static int F_89 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
return - V_309 ;
}
static int F_90 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_42 * V_310 ;
struct V_174 * V_175 ;
struct V_76 * V_187 , * V_254 ;
struct V_59 * V_311 ;
struct V_312 * V_313 ;
struct V_144 * V_167 = NULL ;
int V_150 ;
int V_23 ;
T_6 V_314 , V_315 ;
T_6 V_272 ;
T_7 V_135 ;
unsigned short V_136 ;
T_4 * V_316 = NULL , * V_317 = NULL ;
if ( ! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) )
return - V_71 ;
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 )
return - V_71 ;
if ( ( V_175 = V_110 [ V_266 - 1 ] ) != NULL ) {
V_150 = F_66 ( V_175 -> V_267 ) ;
if ( V_150 < 0 )
return - V_71 ;
V_272 = V_175 -> V_271 ;
} else {
V_150 = 0 ;
V_272 = 0 ;
}
V_187 = V_110 [ V_121 - 1 ] ;
V_254 = V_110 [ V_122 - 1 ] ;
V_136 = ( (struct V_78 * ) ( V_187 + 1 ) ) -> V_85 ;
switch ( V_136 ) {
case V_86 :
V_317 = ( T_4 * ) & ( (struct V_80 * ) ( V_254 + 1 ) ) -> V_140 . V_108 ;
V_316 = ( T_4 * ) & ( (struct V_80 * ) ( V_187 + 1 ) ) -> V_140 . V_108 ;
break;
#if F_46 ( V_81 )
case V_89 :
V_317 = ( T_4 * ) & ( (struct V_82 * ) ( V_254 + 1 ) ) -> V_142 ;
V_316 = ( T_4 * ) & ( (struct V_82 * ) ( V_187 + 1 ) ) -> V_142 ;
break;
#endif
}
if ( V_60 -> V_63 ) {
V_167 = F_91 ( V_10 , V_148 , V_60 -> V_63 ) ;
if ( V_167 && ! F_70 ( & V_167 -> V_197 . V_254 , V_317 , V_136 ) ) {
F_88 ( V_167 ) ;
V_167 = NULL ;
}
}
if ( ! V_167 )
V_167 = F_92 ( V_10 , & V_318 , V_150 , V_272 , V_135 , V_317 , V_316 , 1 , V_136 ) ;
if ( V_167 == NULL )
return - V_319 ;
V_314 = 0x100 ;
V_315 = 0x0fffffff ;
V_313 = V_110 [ V_320 - 1 ] ;
if ( V_313 ) {
V_314 = V_313 -> V_321 ;
V_315 = V_313 -> V_322 ;
}
V_23 = F_93 ( V_167 -> V_197 . V_135 , V_314 , V_315 ) ;
if ( V_23 ) {
F_88 ( V_167 ) ;
return V_23 ;
}
V_23 = F_94 ( V_167 , V_314 , V_315 ) ;
V_310 = V_23 ? F_69 ( V_23 ) : F_76 ( V_167 ) ;
if ( F_95 ( V_310 ) ) {
F_88 ( V_167 ) ;
return F_96 ( V_310 ) ;
}
V_311 = (struct V_59 * ) V_310 -> V_62 ;
V_311 -> V_323 = V_60 -> V_323 ;
V_311 -> V_324 = V_325 ;
V_311 -> V_147 = F_55 ( V_135 ) ;
V_311 -> V_64 = 0 ;
V_311 -> V_326 = 0 ;
V_311 -> V_63 = V_60 -> V_63 ;
V_311 -> V_327 = V_60 -> V_327 ;
F_88 ( V_167 ) ;
F_35 ( V_310 , V_58 , V_3 , V_10 ) ;
return 0 ;
}
static int F_97 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_144 * V_167 ;
if ( V_60 -> V_73 != sizeof( struct V_59 ) / 8 )
return - V_309 ;
if ( V_60 -> V_63 == 0 || V_60 -> V_64 == 0 )
return 0 ;
V_167 = F_91 ( V_10 , V_148 , V_60 -> V_63 ) ;
if ( V_167 == NULL )
return 0 ;
F_98 ( & V_167 -> V_328 ) ;
if ( V_167 -> V_201 . V_202 == V_208 )
V_167 -> V_201 . V_202 = V_329 ;
F_99 ( & V_167 -> V_328 ) ;
F_88 ( V_167 ) ;
return 0 ;
}
static inline int F_100 ( int V_330 )
{
switch ( V_330 ) {
case V_331 :
return V_332 ;
case V_333 :
return V_334 ;
case V_335 :
return V_336 ;
case V_337 :
default:
F_11 ( L_2 , V_330 ) ;
break;
}
return 0 ;
}
static inline int F_101 ( int V_330 )
{
switch ( V_330 ) {
case V_338 :
return V_339 ;
case V_340 :
return V_341 ;
case V_342 :
return V_343 ;
case V_344 :
return V_345 ;
default:
F_11 ( L_3 , V_330 ) ;
break;
}
return 0 ;
}
static int F_102 ( struct V_144 * V_167 , const struct V_346 * V_347 )
{
struct V_42 * V_8 ;
struct V_59 * V_60 ;
V_8 = F_76 ( V_167 ) ;
if ( F_95 ( V_8 ) )
return F_96 ( V_8 ) ;
V_60 = (struct V_59 * ) V_8 -> V_62 ;
V_60 -> V_323 = V_29 ;
V_60 -> V_324 = F_101 ( V_347 -> V_330 ) ;
V_60 -> V_147 = F_55 ( V_167 -> V_197 . V_135 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_326 = 0 ;
V_60 -> V_63 = V_347 -> V_307 ;
V_60 -> V_327 = V_347 -> V_348 ;
F_35 ( V_8 , V_54 , NULL , F_103 ( V_167 ) ) ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_144 * V_167 ;
int V_23 ;
struct V_346 V_347 ;
V_167 = F_78 ( V_10 , V_60 , V_110 ) ;
if ( F_95 ( V_167 ) )
return F_96 ( V_167 ) ;
F_105 ( V_167 ) ;
if ( V_60 -> V_324 == V_341 )
V_23 = F_106 ( V_167 ) ;
else
V_23 = F_107 ( V_167 ) ;
F_108 ( V_167 , V_23 ? 0 : 1 , true ) ;
if ( V_23 < 0 ) {
V_167 -> V_201 . V_202 = V_308 ;
F_109 ( V_167 ) ;
goto V_35;
}
if ( V_60 -> V_324 == V_341 )
V_347 . V_330 = V_340 ;
else
V_347 . V_330 = V_342 ;
V_347 . V_307 = V_60 -> V_63 ;
V_347 . V_348 = V_60 -> V_327 ;
F_110 ( V_167 , & V_347 ) ;
V_35:
F_88 ( V_167 ) ;
return V_23 ;
}
static int F_111 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_144 * V_167 ;
struct V_346 V_347 ;
int V_23 ;
if ( ! V_110 [ V_146 - 1 ] ||
! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) )
return - V_71 ;
V_167 = F_61 ( V_10 , V_60 , V_110 ) ;
if ( V_167 == NULL )
return - V_50 ;
if ( ( V_23 = F_112 ( V_167 ) ) )
goto V_35;
if ( F_113 ( V_167 ) ) {
V_23 = - V_26 ;
goto V_35;
}
V_23 = F_114 ( V_167 ) ;
if ( V_23 < 0 )
goto V_35;
V_347 . V_307 = V_60 -> V_63 ;
V_347 . V_348 = V_60 -> V_327 ;
V_347 . V_330 = V_338 ;
F_110 ( V_167 , & V_347 ) ;
V_35:
F_115 ( V_167 , V_23 ? 0 : 1 , true ) ;
F_88 ( V_167 ) ;
return V_23 ;
}
static int F_116 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
T_8 V_135 ;
struct V_42 * V_349 ;
struct V_59 * V_311 ;
struct V_144 * V_167 ;
if ( ! V_110 [ V_146 - 1 ] ||
! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) )
return - V_71 ;
V_167 = F_61 ( V_10 , V_60 , V_110 ) ;
if ( V_167 == NULL )
return - V_50 ;
V_349 = F_76 ( V_167 ) ;
V_135 = V_167 -> V_197 . V_135 ;
F_88 ( V_167 ) ;
if ( F_95 ( V_349 ) )
return F_96 ( V_349 ) ;
V_311 = (struct V_59 * ) V_349 -> V_62 ;
V_311 -> V_323 = V_60 -> V_323 ;
V_311 -> V_324 = V_350 ;
V_311 -> V_147 = F_55 ( V_135 ) ;
V_311 -> V_64 = 0 ;
V_311 -> V_326 = 0 ;
V_311 -> V_63 = V_60 -> V_63 ;
V_311 -> V_327 = V_60 -> V_327 ;
F_35 ( V_349 , V_58 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static struct V_42 * F_117 ( const struct V_59 * V_66 ,
T_1 V_44 )
{
struct V_42 * V_8 ;
struct V_59 * V_60 ;
int V_84 , V_351 , V_352 , V_353 ;
V_351 = F_118 () ;
if ( V_351 ) {
V_351 *= sizeof( struct V_354 ) ;
V_351 += sizeof( struct V_355 ) ;
}
V_352 = F_119 () ;
if ( V_352 ) {
V_352 *= sizeof( struct V_354 ) ;
V_352 += sizeof( struct V_355 ) ;
}
V_84 = V_352 + V_351 + sizeof( struct V_59 ) ;
V_8 = F_42 ( V_84 + 16 , V_44 ) ;
if ( ! V_8 )
goto V_356;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( * V_60 ) ) ;
F_40 ( V_60 , V_66 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_73 = V_84 / sizeof( V_74 ) ;
if ( V_351 ) {
struct V_355 * V_77 ;
struct V_354 * V_357 ;
V_77 = (struct V_355 * ) F_44 ( V_8 , V_351 ) ;
V_357 = (struct V_354 * ) ( V_77 + 1 ) ;
V_77 -> V_358 = V_351 / sizeof( V_74 ) ;
V_77 -> V_359 = V_360 ;
for ( V_353 = 0 ; ; V_353 ++ ) {
struct V_212 * V_188 = F_120 ( V_353 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_215 )
continue;
if ( V_188 -> V_361 )
* V_357 ++ = V_188 -> V_216 ;
}
}
if ( V_352 ) {
struct V_355 * V_77 ;
struct V_354 * V_357 ;
V_77 = (struct V_355 * ) F_44 ( V_8 , V_352 ) ;
V_357 = (struct V_354 * ) ( V_77 + 1 ) ;
V_77 -> V_358 = V_352 / sizeof( V_74 ) ;
V_77 -> V_359 = V_362 ;
for ( V_353 = 0 ; ; V_353 ++ ) {
struct V_212 * V_190 = F_121 ( V_353 ) ;
if ( ! V_190 )
break;
if ( ! V_190 -> V_215 )
continue;
if ( V_190 -> V_361 )
* V_357 ++ = V_190 -> V_216 ;
}
}
V_356:
return V_8 ;
}
static int F_122 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_42 * V_363 ;
if ( V_60 -> V_147 > V_364 )
return - V_71 ;
if ( V_60 -> V_147 != V_127 ) {
if ( V_6 -> V_57 & ( 1 << V_60 -> V_147 ) )
return - V_365 ;
V_6 -> V_57 |= ( 1 << V_60 -> V_147 ) ;
}
F_123 () ;
V_363 = F_117 ( V_60 , V_33 ) ;
if ( ! V_363 ) {
if ( V_60 -> V_147 != V_127 )
V_6 -> V_57 &= ~ ( 1 << V_60 -> V_147 ) ;
return - V_45 ;
}
F_35 ( V_363 , V_56 , V_3 , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_124 ( struct V_2 * V_3 , const struct V_59 * V_366 )
{
struct V_42 * V_8 ;
struct V_59 * V_60 ;
V_8 = F_42 ( sizeof( struct V_59 ) + 16 , V_53 ) ;
if ( ! V_8 )
return - V_45 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
memcpy ( V_60 , V_366 , sizeof( struct V_59 ) ) ;
V_60 -> V_64 = ( V_72 ) 0 ;
V_60 -> V_73 = ( sizeof( struct V_59 ) / sizeof( V_74 ) ) ;
return F_35 ( V_8 , V_58 , V_3 , F_7 ( V_3 ) ) ;
}
static int F_125 ( const struct V_346 * V_347 )
{
struct V_42 * V_8 ;
struct V_59 * V_60 ;
V_8 = F_42 ( sizeof( struct V_59 ) + 16 , V_53 ) ;
if ( ! V_8 )
return - V_45 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_147 = F_55 ( V_347 -> V_62 . V_135 ) ;
V_60 -> V_324 = V_367 ;
V_60 -> V_63 = V_347 -> V_307 ;
V_60 -> V_327 = V_347 -> V_348 ;
V_60 -> V_323 = V_29 ;
V_60 -> V_64 = ( V_72 ) 0 ;
V_60 -> V_73 = ( sizeof( struct V_59 ) / sizeof( V_74 ) ) ;
V_60 -> V_326 = 0 ;
F_35 ( V_8 , V_54 , NULL , V_347 -> V_10 ) ;
return 0 ;
}
static int F_126 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_135 ;
struct V_346 V_347 ;
int V_23 , V_51 ;
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 )
return - V_71 ;
V_23 = F_127 ( V_10 , V_135 , true ) ;
V_51 = F_124 ( V_3 , V_60 ) ;
if ( V_23 || V_51 ) {
if ( V_23 == - V_50 )
V_23 = 0 ;
return V_23 ? V_23 : V_51 ;
}
V_347 . V_62 . V_135 = V_135 ;
V_347 . V_307 = V_60 -> V_63 ;
V_347 . V_348 = V_60 -> V_327 ;
V_347 . V_330 = V_368 ;
V_347 . V_10 = V_10 ;
F_110 ( NULL , & V_347 ) ;
return 0 ;
}
static int F_128 ( struct V_144 * V_167 , int V_369 , void * V_370 )
{
struct V_1 * V_6 = V_370 ;
struct V_42 * V_349 ;
struct V_59 * V_311 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_45 ;
V_349 = F_76 ( V_167 ) ;
if ( F_95 ( V_349 ) )
return F_96 ( V_349 ) ;
V_311 = (struct V_59 * ) V_349 -> V_62 ;
V_311 -> V_323 = V_6 -> V_7 . V_371 ;
V_311 -> V_324 = V_372 ;
V_311 -> V_147 = F_55 ( V_167 -> V_197 . V_135 ) ;
V_311 -> V_64 = 0 ;
V_311 -> V_326 = 0 ;
V_311 -> V_63 = V_369 + 1 ;
V_311 -> V_327 = V_6 -> V_7 . V_373 ;
if ( V_6 -> V_7 . V_8 )
F_35 ( V_6 -> V_7 . V_8 , V_58 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_349 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return F_130 ( V_10 , & V_6 -> V_7 . V_374 . V_202 , F_128 , ( void * ) V_6 ) ;
}
static void F_131 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
F_132 ( & V_6 -> V_7 . V_374 . V_202 , V_10 ) ;
}
static int F_133 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
T_7 V_135 ;
struct V_375 * V_376 = NULL ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_15 ( & V_6 -> V_36 ) ;
if ( V_6 -> V_7 . V_7 != NULL ) {
F_17 ( & V_6 -> V_36 ) ;
return - V_377 ;
}
V_135 = F_54 ( V_60 -> V_147 ) ;
if ( V_135 == 0 ) {
F_17 ( & V_6 -> V_36 ) ;
return - V_71 ;
}
if ( V_110 [ V_378 - 1 ] ) {
struct V_379 * V_380 = V_110 [ V_378 - 1 ] ;
V_376 = F_51 ( sizeof( * V_376 ) , V_33 ) ;
if ( V_376 == NULL ) {
F_17 ( & V_6 -> V_36 ) ;
return - V_31 ;
}
memcpy ( & V_376 -> V_187 , & V_380 -> V_381 ,
sizeof( T_4 ) ) ;
memcpy ( & V_376 -> V_254 , & V_380 -> V_382 ,
sizeof( T_4 ) ) ;
V_376 -> V_136 = V_380 -> V_383 ;
V_376 -> V_384 = V_380 -> V_385 ;
V_376 -> V_386 = V_380 -> V_387 ;
}
V_6 -> V_7 . V_371 = V_60 -> V_323 ;
V_6 -> V_7 . V_373 = V_60 -> V_327 ;
V_6 -> V_7 . V_7 = F_129 ;
V_6 -> V_7 . V_9 = F_131 ;
F_134 ( & V_6 -> V_7 . V_374 . V_202 , V_135 , V_376 ) ;
F_17 ( & V_6 -> V_36 ) ;
return F_39 ( V_6 ) ;
}
static int F_135 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_126 = V_60 -> V_147 ;
bool V_388 = false ;
if ( V_60 -> V_73 == ( sizeof( * V_60 ) / sizeof( V_74 ) ) ) {
V_388 = true ;
if ( V_126 != 0 && V_126 != 1 )
return - V_71 ;
V_6 -> V_52 = V_126 ;
}
if ( V_388 && F_136 ( V_8 ) )
V_8 = F_137 ( V_8 , V_33 ) ;
else
V_8 = F_32 ( V_8 , V_33 ) ;
if ( V_388 && V_8 ) {
struct V_59 * V_389 = (struct V_59 * ) V_8 -> V_62 ;
V_389 -> V_64 = 0 ;
}
F_35 ( V_8 , V_54 , NULL , F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_138 ( struct V_390 * V_391 , int V_392 , int V_369 , void * V_370 )
{
int V_353 ;
T_6 V_272 = * ( T_6 * ) V_370 ;
for ( V_353 = 0 ; V_353 < V_391 -> V_393 ; V_353 ++ ) {
if ( V_391 -> V_394 [ V_353 ] . V_272 == V_272 )
return - V_365 ;
}
return 0 ;
}
static T_6 F_139 ( struct V_10 * V_10 )
{
struct V_395 V_396 ;
T_6 V_397 ;
int V_61 ;
static T_6 V_272 = V_398 ;
V_397 = V_272 ;
do {
++ V_272 ;
if ( V_272 == 0 )
V_272 = V_398 + 1 ;
F_140 ( & V_396 , V_399 ) ;
V_61 = V_395 ( V_10 , & V_396 , F_138 , ( void * ) & V_272 ) ;
F_141 ( & V_396 , V_10 ) ;
if ( V_61 != - V_365 )
return V_272 ;
} while ( V_272 != V_397 );
return 0 ;
}
static int
F_142 ( struct V_390 * V_391 , struct V_400 * V_401 )
{
struct V_10 * V_10 = F_143 ( V_391 ) ;
struct V_402 * V_403 = V_391 -> V_394 + V_391 -> V_393 ;
int V_150 ;
if ( V_391 -> V_393 >= V_404 )
return - V_405 ;
if ( V_401 -> V_406 == 0 )
return - V_71 ;
V_403 -> V_197 . V_135 = V_401 -> V_407 ;
if ( ( V_150 = F_66 ( V_401 -> V_406 ) ) < 0 )
return - V_71 ;
V_403 -> V_150 = V_150 ;
if ( V_401 -> V_408 == V_409 )
V_403 -> V_410 = 1 ;
else if ( V_401 -> V_408 == V_411 ) {
V_403 -> V_272 = V_401 -> V_412 ;
if ( V_403 -> V_272 > V_398 )
V_403 -> V_272 = 0 ;
if ( ! V_403 -> V_272 && ! ( V_403 -> V_272 = F_139 ( V_10 ) ) )
return - V_45 ;
}
if ( V_403 -> V_150 == V_153 ) {
int V_23 ;
V_23 = F_144 (
(struct V_78 * ) ( V_401 + 1 ) ,
V_401 -> V_413 - sizeof( * V_401 ) ,
& V_403 -> V_187 , & V_403 -> V_197 . V_254 , & V_403 -> V_414 ) ;
if ( V_23 )
return V_23 ;
} else
V_403 -> V_414 = V_391 -> V_136 ;
V_403 -> V_415 = 1 ;
V_391 -> V_393 ++ ;
return 0 ;
}
static int
F_145 ( struct V_390 * V_391 , struct V_416 * V_417 )
{
int V_23 ;
int V_84 = V_417 -> V_418 * 8 - sizeof( struct V_416 ) ;
struct V_400 * V_401 = ( void * ) ( V_417 + 1 ) ;
if ( V_417 -> V_418 * 8 < sizeof( struct V_416 ) )
return - V_71 ;
while ( V_84 >= sizeof( * V_401 ) ) {
if ( V_84 < V_401 -> V_413 ||
V_401 -> V_413 < sizeof( * V_401 ) )
return - V_71 ;
if ( ( V_23 = F_142 ( V_391 , V_401 ) ) < 0 )
return V_23 ;
V_84 -= V_401 -> V_413 ;
V_401 = ( void * ) ( ( T_7 * ) V_401 + V_401 -> V_413 ) ;
}
return 0 ;
}
static inline int F_146 ( const struct V_390 * V_391 )
{
struct V_176 * V_177 = V_391 -> V_185 ;
if ( V_177 ) {
int V_84 = sizeof( struct V_90 ) ;
V_84 += V_177 -> V_105 ;
return F_64 ( V_84 ) ;
}
return 0 ;
}
static int F_147 ( const struct V_390 * V_391 )
{
const struct V_402 * V_403 ;
int V_181 = F_63 ( V_391 -> V_136 ) ;
int V_419 = 0 ;
int V_353 ;
for ( V_353 = 0 ; V_353 < V_391 -> V_393 ; V_353 ++ ) {
V_403 = V_391 -> V_394 + V_353 ;
V_419 += F_58 ( V_403 -> V_414 ) ;
}
return sizeof( struct V_59 ) +
( sizeof( struct V_170 ) * 3 ) +
( sizeof( struct V_76 ) * 2 ) +
( V_181 * 2 ) +
sizeof( struct V_416 ) +
( V_391 -> V_393 * sizeof( struct V_400 ) ) +
( V_419 * 2 ) +
F_146 ( V_391 ) ;
}
static struct V_42 * F_148 ( const struct V_390 * V_391 )
{
struct V_42 * V_8 ;
int V_178 ;
V_178 = F_147 ( V_391 ) ;
V_8 = F_42 ( V_178 + 16 , V_53 ) ;
if ( V_8 == NULL )
return F_69 ( - V_45 ) ;
return V_8 ;
}
static int F_149 ( struct V_42 * V_8 , const struct V_390 * V_391 , int V_392 )
{
struct V_59 * V_60 ;
struct V_76 * V_79 ;
struct V_170 * V_171 ;
struct V_416 * V_417 ;
struct V_90 * V_91 ;
struct V_176 * V_177 ;
int V_353 ;
int V_178 ;
int V_181 = F_63 ( V_391 -> V_136 ) ;
int V_419 = F_58 ( V_391 -> V_136 ) ;
V_178 = F_147 ( V_391 ) ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
memset ( V_60 , 0 , V_178 ) ;
V_79 = (struct V_76 * ) F_44 ( V_8 ,
sizeof( struct V_76 ) + V_181 ) ;
V_79 -> V_87 =
( sizeof( struct V_76 ) + V_181 ) /
sizeof( V_74 ) ;
V_79 -> V_251 = V_121 ;
V_79 -> V_252 = F_57 ( V_391 -> V_420 . V_135 ) ;
V_79 -> V_88 = V_391 -> V_420 . V_255 ;
V_79 -> V_253 = 0 ;
if ( ! F_67 ( & V_391 -> V_420 . V_187 ,
V_391 -> V_420 . V_256 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_391 -> V_136 ) )
F_75 () ;
V_79 = (struct V_76 * ) F_44 ( V_8 ,
sizeof( struct V_76 ) + V_181 ) ;
V_79 -> V_87 =
( sizeof( struct V_76 ) + V_181 ) /
sizeof( V_74 ) ;
V_79 -> V_251 = V_122 ;
V_79 -> V_252 = F_57 ( V_391 -> V_420 . V_135 ) ;
V_79 -> V_88 = V_391 -> V_420 . V_421 ;
V_79 -> V_253 = 0 ;
F_67 ( & V_391 -> V_420 . V_254 , V_391 -> V_420 . V_422 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_391 -> V_136 ) ;
V_171 = (struct V_170 * ) F_44 ( V_8 ,
sizeof( struct V_170 ) ) ;
V_171 -> V_228 =
sizeof( struct V_170 ) / sizeof( V_74 ) ;
V_171 -> V_229 = V_230 ;
V_171 -> V_231 = F_74 ( V_391 -> V_232 . V_233 ) ;
V_171 -> V_234 = F_74 ( V_391 -> V_232 . V_235 ) ;
V_171 -> V_236 = V_391 -> V_232 . V_237 ;
V_171 -> V_238 = V_391 -> V_232 . V_239 ;
V_171 = (struct V_170 * ) F_44 ( V_8 ,
sizeof( struct V_170 ) ) ;
V_171 -> V_228 =
sizeof( struct V_170 ) / sizeof( V_74 ) ;
V_171 -> V_229 = V_240 ;
V_171 -> V_231 = F_74 ( V_391 -> V_232 . V_241 ) ;
V_171 -> V_234 = F_74 ( V_391 -> V_232 . V_242 ) ;
V_171 -> V_236 = V_391 -> V_232 . V_243 ;
V_171 -> V_238 = V_391 -> V_232 . V_244 ;
V_171 = (struct V_170 * ) F_44 ( V_8 ,
sizeof( struct V_170 ) ) ;
V_171 -> V_228 =
sizeof( struct V_170 ) / sizeof( V_74 ) ;
V_171 -> V_229 = V_245 ;
V_171 -> V_231 = V_391 -> V_246 . V_247 ;
V_171 -> V_234 = V_391 -> V_246 . V_248 ;
V_171 -> V_236 = V_391 -> V_246 . V_249 ;
V_171 -> V_238 = V_391 -> V_246 . V_250 ;
V_417 = (struct V_416 * ) F_44 ( V_8 , sizeof( struct V_416 ) ) ;
V_417 -> V_418 = sizeof( struct V_416 ) / sizeof( V_74 ) ;
V_417 -> V_423 = V_424 ;
V_417 -> V_425 = V_426 ;
if ( V_391 -> V_427 == V_428 ) {
if ( V_391 -> V_393 )
V_417 -> V_425 = V_429 ;
else
V_417 -> V_425 = V_430 ;
}
V_417 -> V_431 = V_392 + 1 ;
V_417 -> V_432 = 0 ;
V_417 -> V_433 = V_391 -> V_434 ;
V_417 -> V_435 = V_391 -> V_436 ;
for ( V_353 = 0 ; V_353 < V_391 -> V_393 ; V_353 ++ ) {
const struct V_402 * V_403 = V_391 -> V_394 + V_353 ;
struct V_400 * V_401 ;
int V_437 ;
int V_150 ;
V_437 = sizeof( struct V_400 ) ;
if ( V_403 -> V_150 == V_153 ) {
V_419 = F_58 ( V_403 -> V_414 ) ;
V_437 += V_419 * 2 ;
} else {
V_178 -= 2 * V_419 ;
}
V_401 = ( void * ) F_44 ( V_8 , V_437 ) ;
V_417 -> V_418 += V_437 / 8 ;
memset ( V_401 , 0 , sizeof( * V_401 ) ) ;
V_401 -> V_413 = V_437 ;
V_401 -> V_407 = V_403 -> V_197 . V_135 ;
if ( ( V_150 = F_65 ( V_403 -> V_150 ) ) < 0 )
return - V_71 ;
V_401 -> V_406 = V_150 ;
V_401 -> V_408 = V_438 ;
if ( V_403 -> V_272 )
V_401 -> V_408 = V_411 ;
if ( V_403 -> V_410 )
V_401 -> V_408 = V_409 ;
V_401 -> V_412 = V_403 -> V_272 ;
if ( V_403 -> V_150 == V_153 ) {
T_7 * V_137 = ( void * ) ( V_401 + 1 ) ;
F_67 ( & V_403 -> V_187 , 0 ,
(struct V_78 * ) V_137 ,
V_403 -> V_414 ) ;
F_67 ( & V_403 -> V_197 . V_254 , 0 ,
(struct V_78 * ) ( V_137 + V_419 ) ,
V_403 -> V_414 ) ;
}
}
if ( ( V_177 = V_391 -> V_185 ) ) {
int V_98 = F_146 ( V_391 ) ;
V_91 = (struct V_90 * ) F_44 ( V_8 , V_98 ) ;
V_91 -> V_94 = V_98 / sizeof( V_74 ) ;
V_91 -> V_100 = V_125 ;
V_91 -> V_102 = V_177 -> V_101 ;
V_91 -> V_104 = V_177 -> V_103 ;
V_91 -> V_92 = V_177 -> V_105 ;
memcpy ( V_91 + 1 , V_177 -> V_288 ,
V_177 -> V_105 ) ;
}
V_60 -> V_73 = V_178 / sizeof( V_74 ) ;
V_60 -> V_326 = F_3 ( & V_391 -> V_439 ) ;
return 0 ;
}
static int F_150 ( struct V_390 * V_391 , int V_392 , const struct V_346 * V_347 )
{
struct V_42 * V_349 ;
struct V_59 * V_311 ;
int V_23 ;
V_349 = F_148 ( V_391 ) ;
if ( F_95 ( V_349 ) )
return F_96 ( V_349 ) ;
V_23 = F_149 ( V_349 , V_391 , V_392 ) ;
if ( V_23 < 0 )
return V_23 ;
V_311 = (struct V_59 * ) V_349 -> V_62 ;
V_311 -> V_323 = V_29 ;
if ( V_347 -> V_62 . V_440 && V_347 -> V_330 == V_331 )
V_311 -> V_324 = V_441 ;
else
V_311 -> V_324 = F_100 ( V_347 -> V_330 ) ;
V_311 -> V_64 = 0 ;
V_311 -> V_63 = V_347 -> V_307 ;
V_311 -> V_327 = V_347 -> V_348 ;
F_35 ( V_349 , V_54 , NULL , F_143 ( V_391 ) ) ;
return 0 ;
}
static int F_151 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 = 0 ;
struct V_170 * V_171 ;
struct V_76 * V_137 ;
struct V_416 * V_417 ;
struct V_390 * V_391 ;
struct V_346 V_347 ;
struct V_90 * V_91 ;
if ( ! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) ||
! V_110 [ V_424 - 1 ] )
return - V_71 ;
V_417 = V_110 [ V_424 - 1 ] ;
if ( V_417 -> V_425 > V_429 )
return - V_71 ;
if ( ! V_417 -> V_431 || V_417 -> V_431 >= V_442 )
return - V_71 ;
V_391 = F_152 ( V_10 , V_33 ) ;
if ( V_391 == NULL )
return - V_45 ;
V_391 -> V_427 = ( V_417 -> V_425 == V_426 ?
V_443 : V_428 ) ;
V_391 -> V_436 = V_417 -> V_435 ;
V_137 = V_110 [ V_121 - 1 ] ;
V_391 -> V_136 = F_60 ( V_137 , & V_391 -> V_420 . V_187 ) ;
V_391 -> V_420 . V_136 = V_391 -> V_136 ;
V_391 -> V_420 . V_255 = V_137 -> V_88 ;
V_391 -> V_420 . V_135 = F_56 ( V_137 -> V_252 ) ;
V_391 -> V_420 . V_256 = ( (struct V_80 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_391 -> V_420 . V_256 )
V_391 -> V_420 . V_444 = F_153 ( 0xffff ) ;
V_137 = V_110 [ V_122 - 1 ] ;
F_60 ( V_137 , & V_391 -> V_420 . V_254 ) ;
V_391 -> V_420 . V_421 = V_137 -> V_88 ;
V_391 -> V_420 . V_135 = F_56 ( V_137 -> V_252 ) ;
V_391 -> V_420 . V_422 = ( (struct V_80 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_391 -> V_420 . V_422 )
V_391 -> V_420 . V_445 = F_153 ( 0xffff ) ;
V_91 = V_110 [ V_125 - 1 ] ;
if ( V_91 != NULL ) {
struct V_95 * V_97 = F_50 ( V_91 , V_33 ) ;
if ( ! V_97 ) {
V_23 = - V_45 ;
goto V_35;
}
V_23 = F_154 ( & V_391 -> V_185 , V_97 , V_33 ) ;
F_83 ( V_97 ) ;
if ( V_23 )
goto V_35;
}
V_391 -> V_232 . V_242 = V_446 ;
V_391 -> V_232 . V_235 = V_446 ;
V_391 -> V_232 . V_241 = V_446 ;
V_391 -> V_232 . V_233 = V_446 ;
if ( ( V_171 = V_110 [ V_230 - 1 ] ) != NULL ) {
V_391 -> V_232 . V_233 = F_81 ( V_171 -> V_231 ) ;
V_391 -> V_232 . V_235 = F_81 ( V_171 -> V_234 ) ;
V_391 -> V_232 . V_237 = V_171 -> V_236 ;
V_391 -> V_232 . V_239 = V_171 -> V_238 ;
}
if ( ( V_171 = V_110 [ V_240 - 1 ] ) != NULL ) {
V_391 -> V_232 . V_241 = F_81 ( V_171 -> V_231 ) ;
V_391 -> V_232 . V_242 = F_81 ( V_171 -> V_234 ) ;
V_391 -> V_232 . V_243 = V_171 -> V_236 ;
V_391 -> V_232 . V_244 = V_171 -> V_238 ;
}
V_391 -> V_393 = 0 ;
if ( V_417 -> V_425 == V_429 &&
( V_23 = F_145 ( V_391 , V_417 ) ) < 0 )
goto V_35;
V_23 = F_155 ( V_417 -> V_431 - 1 , V_391 ,
V_60 -> V_324 != V_336 ) ;
F_156 ( V_391 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
if ( V_60 -> V_324 == V_336 )
V_347 . V_330 = V_335 ;
else
V_347 . V_330 = V_333 ;
V_347 . V_307 = V_60 -> V_63 ;
V_347 . V_348 = V_60 -> V_327 ;
F_157 ( V_391 , V_417 -> V_431 - 1 , & V_347 ) ;
F_158 ( V_391 ) ;
return 0 ;
V_35:
V_391 -> V_396 . V_447 = 1 ;
F_159 ( V_391 ) ;
return V_23 ;
}
static int F_160 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
int V_23 ;
struct V_76 * V_137 ;
struct V_416 * V_417 ;
struct V_390 * V_391 ;
struct V_448 V_186 ;
struct V_346 V_347 ;
struct V_90 * V_91 ;
struct V_176 * V_449 = NULL ;
if ( ! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) ||
! V_110 [ V_424 - 1 ] )
return - V_71 ;
V_417 = V_110 [ V_424 - 1 ] ;
if ( ! V_417 -> V_431 || V_417 -> V_431 >= V_442 )
return - V_71 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_137 = V_110 [ V_121 - 1 ] ;
V_186 . V_136 = F_60 ( V_137 , & V_186 . V_187 ) ;
V_186 . V_255 = V_137 -> V_88 ;
V_186 . V_135 = F_56 ( V_137 -> V_252 ) ;
V_186 . V_256 = ( (struct V_80 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_186 . V_256 )
V_186 . V_444 = F_153 ( 0xffff ) ;
V_137 = V_110 [ V_122 - 1 ] ;
F_60 ( V_137 , & V_186 . V_254 ) ;
V_186 . V_421 = V_137 -> V_88 ;
V_186 . V_135 = F_56 ( V_137 -> V_252 ) ;
V_186 . V_422 = ( (struct V_80 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_186 . V_422 )
V_186 . V_445 = F_153 ( 0xffff ) ;
V_91 = V_110 [ V_125 - 1 ] ;
if ( V_91 != NULL ) {
struct V_95 * V_97 = F_50 ( V_91 , V_33 ) ;
if ( ! V_97 )
return - V_31 ;
V_23 = F_154 ( & V_449 , V_97 , V_33 ) ;
F_83 ( V_97 ) ;
if ( V_23 )
return V_23 ;
}
V_391 = F_161 ( V_10 , V_148 , V_399 ,
V_417 -> V_431 - 1 , & V_186 , V_449 ,
1 , & V_23 ) ;
F_162 ( V_449 ) ;
if ( V_391 == NULL )
return - V_319 ;
F_163 ( V_391 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
V_347 . V_307 = V_60 -> V_63 ;
V_347 . V_348 = V_60 -> V_327 ;
V_347 . V_62 . V_440 = 0 ;
V_347 . V_330 = V_331 ;
F_157 ( V_391 , V_417 -> V_431 - 1 , & V_347 ) ;
V_35:
F_158 ( V_391 ) ;
if ( V_23 == 0 )
F_164 ( V_10 ) ;
return V_23 ;
}
static int F_165 ( struct V_2 * V_3 , struct V_390 * V_391 , const struct V_59 * V_60 , int V_392 )
{
int V_23 ;
struct V_42 * V_349 ;
struct V_59 * V_311 ;
V_23 = 0 ;
V_349 = F_148 ( V_391 ) ;
if ( F_95 ( V_349 ) ) {
V_23 = F_96 ( V_349 ) ;
goto V_35;
}
V_23 = F_149 ( V_349 , V_391 , V_392 ) ;
if ( V_23 < 0 )
goto V_35;
V_311 = (struct V_59 * ) V_349 -> V_62 ;
V_311 -> V_323 = V_60 -> V_323 ;
V_311 -> V_324 = V_60 -> V_324 ;
V_311 -> V_147 = 0 ;
V_311 -> V_64 = 0 ;
V_311 -> V_63 = V_60 -> V_63 ;
V_311 -> V_327 = V_60 -> V_327 ;
F_35 ( V_349 , V_58 , V_3 , F_143 ( V_391 ) ) ;
V_23 = 0 ;
V_35:
return V_23 ;
}
static int F_166 ( T_3 V_136 )
{
return F_64 ( F_58 ( V_136 ) * 2 ) ;
}
static int F_144 ( struct V_78 * V_137 , int V_114 ,
T_4 * V_187 , T_4 * V_254 ,
T_9 * V_136 )
{
int V_450 , V_419 ;
if ( V_114 < 2 || V_114 < F_166 ( V_137 -> V_85 ) )
return - V_71 ;
V_450 = F_59 ( V_137 , V_187 ) ;
if ( ! V_450 )
return - V_71 ;
V_419 = F_58 ( V_450 ) ;
if ( F_59 ( (struct V_78 * ) ( ( ( T_7 * ) V_137 ) + V_419 ) ,
V_254 ) != V_450 )
return - V_71 ;
* V_136 = V_450 ;
return 0 ;
}
static int F_167 ( struct V_400 * V_451 , int V_84 ,
struct V_452 * V_453 )
{
int V_23 ;
struct V_400 * V_454 ;
int V_150 ;
if ( V_84 < sizeof( * V_451 ) ||
V_84 < V_451 -> V_413 ||
V_451 -> V_413 < sizeof( * V_451 ) )
return - V_71 ;
V_23 = F_144 ( (struct V_78 * ) ( V_451 + 1 ) ,
V_451 -> V_413 - sizeof( * V_451 ) ,
& V_453 -> V_455 , & V_453 -> V_456 ,
& V_453 -> V_457 ) ;
if ( V_23 )
return V_23 ;
V_454 = (struct V_400 * ) ( ( T_7 * ) V_451 + V_451 -> V_413 ) ;
V_84 -= V_451 -> V_413 ;
if ( V_84 <= sizeof( * V_454 ) ||
V_84 < V_454 -> V_413 ||
V_454 -> V_413 < sizeof( * V_454 ) )
return - V_71 ;
V_23 = F_144 ( (struct V_78 * ) ( V_454 + 1 ) ,
V_454 -> V_413 - sizeof( * V_454 ) ,
& V_453 -> V_458 , & V_453 -> V_459 ,
& V_453 -> V_460 ) ;
if ( V_23 )
return V_23 ;
if ( V_451 -> V_407 != V_454 -> V_407 ||
V_451 -> V_406 != V_454 -> V_406 ||
V_451 -> V_412 != V_454 -> V_412 )
return - V_71 ;
V_453 -> V_135 = V_451 -> V_407 ;
if ( ( V_150 = F_66 ( V_451 -> V_406 ) ) < 0 )
return - V_71 ;
V_453 -> V_150 = V_150 ;
V_453 -> V_272 = V_451 -> V_412 ;
return ( ( int ) ( V_451 -> V_413 +
V_454 -> V_413 ) ) ;
}
static int F_168 ( struct V_2 * V_3 , struct V_42 * V_8 ,
const struct V_59 * V_60 , void * const * V_110 )
{
int V_353 , V_84 , V_461 , V_23 = - V_71 ;
T_7 V_392 ;
struct V_76 * V_137 ;
struct V_462 * V_463 ;
struct V_416 * V_417 ;
struct V_400 * V_401 ;
struct V_448 V_186 ;
struct V_452 V_453 [ V_404 ] ;
struct V_464 V_465 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
if ( ! F_52 ( V_110 [ V_121 - 1 ] ,
V_110 [ V_122 - 1 ] ) ||
! V_110 [ V_424 - 1 ] ) {
V_23 = - V_71 ;
goto V_35;
}
V_463 = V_110 [ V_466 - 1 ] ;
V_417 = V_110 [ V_424 - 1 ] ;
if ( V_417 -> V_431 >= V_442 ) {
V_23 = - V_71 ;
goto V_35;
}
if ( V_463 ) {
V_465 . V_467 = V_463 -> V_468 ;
V_461 = F_144 ( (struct V_78 * ) ( V_463 + 1 ) ,
8 * ( V_463 -> V_469 ) - sizeof( * V_463 ) ,
& V_465 . V_470 , & V_465 . V_471 , & V_465 . V_136 ) ;
if ( V_461 < 0 ) {
V_23 = V_461 ;
goto V_35;
}
}
V_392 = V_417 -> V_431 - 1 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_137 = V_110 [ V_121 - 1 ] ;
V_186 . V_136 = F_60 ( V_137 , & V_186 . V_187 ) ;
V_186 . V_255 = V_137 -> V_88 ;
V_186 . V_135 = F_56 ( V_137 -> V_252 ) ;
V_186 . V_256 = ( (struct V_80 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_186 . V_256 )
V_186 . V_444 = F_153 ( 0xffff ) ;
V_137 = V_110 [ V_122 - 1 ] ;
F_60 ( V_137 , & V_186 . V_254 ) ;
V_186 . V_421 = V_137 -> V_88 ;
V_186 . V_135 = F_56 ( V_137 -> V_252 ) ;
V_186 . V_422 = ( (struct V_80 * ) ( V_137 + 1 ) ) -> V_160 ;
if ( V_186 . V_422 )
V_186 . V_445 = F_153 ( 0xffff ) ;
V_401 = (struct V_400 * ) ( V_417 + 1 ) ;
V_353 = 0 ;
V_84 = V_417 -> V_418 * 8 - sizeof( struct V_416 ) ;
while ( V_84 > 0 && V_353 < V_404 ) {
V_461 = F_167 ( V_401 , V_84 , & V_453 [ V_353 ] ) ;
if ( V_461 < 0 ) {
V_23 = V_461 ;
goto V_35;
} else {
V_401 = (struct V_400 * ) ( ( T_7 * ) V_401 + V_461 ) ;
V_84 -= V_461 ;
V_353 ++ ;
}
}
if ( ! V_353 || V_84 > 0 ) {
V_23 = - V_71 ;
goto V_35;
}
return V_452 ( & V_186 , V_392 , V_399 , V_453 , V_353 ,
V_463 ? & V_465 : NULL , V_10 ) ;
V_35:
return V_23 ;
}
static int F_168 ( struct V_2 * V_3 , struct V_42 * V_8 ,
const struct V_59 * V_60 , void * const * V_110 )
{
return - V_472 ;
}
static int F_169 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
unsigned int V_392 ;
int V_23 = 0 , V_473 ;
struct V_416 * V_417 ;
struct V_390 * V_391 ;
struct V_346 V_347 ;
if ( ( V_417 = V_110 [ V_424 - 1 ] ) == NULL )
return - V_71 ;
V_392 = F_170 ( V_417 -> V_433 ) ;
if ( V_392 >= V_474 )
return - V_71 ;
V_473 = ( V_60 -> V_324 == V_441 ) ;
V_391 = F_171 ( V_10 , V_148 , V_399 ,
V_392 , V_417 -> V_433 , V_473 , & V_23 ) ;
if ( V_391 == NULL )
return - V_319 ;
if ( V_473 ) {
F_163 ( V_391 , V_23 ? 0 : 1 , true ) ;
if ( V_23 )
goto V_35;
V_347 . V_307 = V_60 -> V_63 ;
V_347 . V_348 = V_60 -> V_327 ;
V_347 . V_62 . V_440 = 1 ;
V_347 . V_330 = V_331 ;
F_157 ( V_391 , V_392 , & V_347 ) ;
} else {
V_23 = F_165 ( V_3 , V_391 , V_60 , V_392 ) ;
}
V_35:
F_158 ( V_391 ) ;
if ( V_473 && V_23 == 0 )
F_164 ( V_10 ) ;
return V_23 ;
}
static int F_172 ( struct V_390 * V_391 , int V_392 , int V_369 , void * V_370 )
{
struct V_1 * V_6 = V_370 ;
struct V_42 * V_349 ;
struct V_59 * V_311 ;
int V_23 ;
if ( ! F_2 ( & V_6 -> V_3 ) )
return - V_45 ;
V_349 = F_148 ( V_391 ) ;
if ( F_95 ( V_349 ) )
return F_96 ( V_349 ) ;
V_23 = F_149 ( V_349 , V_391 , V_392 ) ;
if ( V_23 < 0 )
return V_23 ;
V_311 = (struct V_59 * ) V_349 -> V_62 ;
V_311 -> V_323 = V_6 -> V_7 . V_371 ;
V_311 -> V_324 = V_475 ;
V_311 -> V_147 = V_127 ;
V_311 -> V_64 = 0 ;
V_311 -> V_63 = V_369 + 1 ;
V_311 -> V_327 = V_6 -> V_7 . V_373 ;
if ( V_6 -> V_7 . V_8 )
F_35 ( V_6 -> V_7 . V_8 , V_58 ,
& V_6 -> V_3 , F_7 ( & V_6 -> V_3 ) ) ;
V_6 -> V_7 . V_8 = V_349 ;
return 0 ;
}
static int F_173 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( & V_6 -> V_3 ) ;
return V_395 ( V_10 , & V_6 -> V_7 . V_374 . V_476 , F_172 , ( void * ) V_6 ) ;
}
static void F_174 ( struct V_1 * V_6 )
{
struct V_10 * V_10 = F_7 ( (struct V_2 * ) V_6 ) ;
F_141 ( & V_6 -> V_7 . V_374 . V_476 , V_10 ) ;
}
static int F_175 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_15 ( & V_6 -> V_36 ) ;
if ( V_6 -> V_7 . V_7 != NULL ) {
F_17 ( & V_6 -> V_36 ) ;
return - V_377 ;
}
V_6 -> V_7 . V_371 = V_60 -> V_323 ;
V_6 -> V_7 . V_373 = V_60 -> V_327 ;
V_6 -> V_7 . V_7 = F_173 ;
V_6 -> V_7 . V_9 = F_174 ;
F_140 ( & V_6 -> V_7 . V_374 . V_476 , V_399 ) ;
F_17 ( & V_6 -> V_36 ) ;
return F_39 ( V_6 ) ;
}
static int F_176 ( const struct V_346 * V_347 )
{
struct V_42 * V_477 ;
struct V_59 * V_60 ;
V_477 = F_42 ( sizeof( struct V_59 ) + 16 , V_53 ) ;
if ( ! V_477 )
return - V_45 ;
V_60 = (struct V_59 * ) F_44 ( V_477 , sizeof( struct V_59 ) ) ;
V_60 -> V_324 = V_478 ;
V_60 -> V_63 = V_347 -> V_307 ;
V_60 -> V_327 = V_347 -> V_348 ;
V_60 -> V_323 = V_29 ;
V_60 -> V_64 = ( V_72 ) 0 ;
V_60 -> V_147 = V_127 ;
V_60 -> V_73 = ( sizeof( struct V_59 ) / sizeof( V_74 ) ) ;
V_60 -> V_326 = 0 ;
F_35 ( V_477 , V_54 , NULL , V_347 -> V_10 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 , void * const * V_110 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_346 V_347 ;
int V_23 , V_51 ;
V_23 = F_178 ( V_10 , V_399 , true ) ;
if ( ! V_23 )
F_164 ( V_10 ) ;
V_51 = F_124 ( V_3 , V_60 ) ;
if ( V_23 || V_51 ) {
if ( V_23 == - V_50 )
return 0 ;
return V_23 ;
}
V_347 . V_62 . type = V_399 ;
V_347 . V_330 = V_479 ;
V_347 . V_348 = V_60 -> V_327 ;
V_347 . V_307 = V_60 -> V_63 ;
V_347 . V_10 = V_10 ;
F_157 ( NULL , 0 , & V_347 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_3 , struct V_42 * V_8 , const struct V_59 * V_60 )
{
void * V_110 [ V_118 ] ;
int V_23 ;
F_35 ( F_32 ( V_8 , V_33 ) ,
V_55 , NULL , F_7 ( V_3 ) ) ;
memset ( V_110 , 0 , sizeof( V_110 ) ) ;
V_23 = F_53 ( V_8 , V_60 , V_110 ) ;
if ( ! V_23 ) {
V_23 = - V_309 ;
if ( V_480 [ V_60 -> V_324 ] )
V_23 = V_480 [ V_60 -> V_324 ] ( V_3 , V_8 , V_60 , V_110 ) ;
}
return V_23 ;
}
static struct V_59 * F_180 ( struct V_42 * V_8 , int * V_481 )
{
struct V_59 * V_60 = NULL ;
if ( V_8 -> V_84 < sizeof( * V_60 ) ) {
* V_481 = - V_482 ;
} else {
V_60 = (struct V_59 * ) V_8 -> V_62 ;
if ( V_60 -> V_323 != V_29 ||
V_60 -> V_326 != 0 ||
( V_60 -> V_324 <= V_483 ||
V_60 -> V_324 > V_484 ) ) {
V_60 = NULL ;
* V_481 = - V_71 ;
} else if ( V_60 -> V_73 != ( V_8 -> V_84 /
sizeof( V_74 ) ) ||
V_60 -> V_73 < ( sizeof( struct V_59 ) /
sizeof( V_74 ) ) ) {
V_60 = NULL ;
* V_481 = - V_482 ;
} else {
* V_481 = 0 ;
}
}
return V_60 ;
}
static inline int F_181 ( const struct V_402 * V_403 ,
const struct V_212 * V_485 )
{
unsigned int V_197 = V_485 -> V_216 . V_217 ;
if ( V_197 >= sizeof( V_403 -> V_486 ) * 8 )
return 0 ;
return ( V_403 -> V_486 >> V_197 ) & 1 ;
}
static inline int F_182 ( const struct V_402 * V_403 ,
const struct V_212 * V_485 )
{
unsigned int V_197 = V_485 -> V_216 . V_217 ;
if ( V_197 >= sizeof( V_403 -> V_487 ) * 8 )
return 0 ;
return ( V_403 -> V_487 >> V_197 ) & 1 ;
}
static int F_183 ( const struct V_402 * V_403 )
{
int V_353 , V_488 = 0 ;
for ( V_353 = 0 ; ; V_353 ++ ) {
const struct V_212 * V_188 = F_120 ( V_353 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_215 )
continue;
if ( F_181 ( V_403 , V_188 ) && V_188 -> V_361 )
V_488 += sizeof( struct V_489 ) ;
}
return V_488 + sizeof( struct V_490 ) ;
}
static int F_184 ( const struct V_402 * V_403 )
{
int V_353 , V_465 , V_488 = 0 ;
for ( V_353 = 0 ; ; V_353 ++ ) {
const struct V_212 * V_190 = F_121 ( V_353 ) ;
if ( ! V_190 )
break;
if ( ! V_190 -> V_215 )
continue;
if ( ! ( F_182 ( V_403 , V_190 ) && V_190 -> V_361 ) )
continue;
for ( V_465 = 1 ; ; V_465 ++ ) {
const struct V_212 * V_188 = F_120 ( V_465 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_215 )
continue;
if ( F_181 ( V_403 , V_188 ) && V_188 -> V_361 )
V_488 += sizeof( struct V_489 ) ;
}
}
return V_488 + sizeof( struct V_490 ) ;
}
static void F_185 ( struct V_42 * V_8 , const struct V_402 * V_403 )
{
struct V_490 * V_75 ;
int V_353 ;
V_75 = (struct V_490 * ) F_44 ( V_8 , sizeof( struct V_490 ) ) ;
V_75 -> V_491 = sizeof( struct V_490 ) / 8 ;
V_75 -> V_492 = V_493 ;
V_75 -> V_494 = 32 ;
memset ( V_75 -> V_495 , 0 , sizeof( V_75 -> V_495 ) ) ;
for ( V_353 = 0 ; ; V_353 ++ ) {
const struct V_212 * V_188 = F_120 ( V_353 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_215 )
continue;
if ( F_181 ( V_403 , V_188 ) && V_188 -> V_361 ) {
struct V_489 * V_347 ;
V_347 = (struct V_489 * ) F_44 ( V_8 , sizeof( struct V_489 ) ) ;
memset ( V_347 , 0 , sizeof( * V_347 ) ) ;
V_75 -> V_491 += sizeof( struct V_489 ) / 8 ;
V_347 -> V_496 = V_188 -> V_216 . V_217 ;
V_347 -> V_497 = V_188 -> V_216 . V_498 ;
V_347 -> V_499 = V_188 -> V_216 . V_500 ;
V_347 -> V_501 = 24 * 60 * 60 ;
V_347 -> V_502 = 20 * 60 * 60 ;
V_347 -> V_503 = 8 * 60 * 60 ;
V_347 -> V_504 = 7 * 60 * 60 ;
}
}
}
static void F_186 ( struct V_42 * V_8 , const struct V_402 * V_403 )
{
struct V_490 * V_75 ;
int V_353 , V_465 ;
V_75 = (struct V_490 * ) F_44 ( V_8 , sizeof( struct V_490 ) ) ;
V_75 -> V_491 = sizeof( struct V_490 ) / 8 ;
V_75 -> V_492 = V_493 ;
V_75 -> V_494 = 32 ;
memset ( V_75 -> V_495 , 0 , sizeof( V_75 -> V_495 ) ) ;
for ( V_353 = 0 ; ; V_353 ++ ) {
const struct V_212 * V_190 = F_121 ( V_353 ) ;
if ( ! V_190 )
break;
if ( ! V_190 -> V_215 )
continue;
if ( ! ( F_182 ( V_403 , V_190 ) && V_190 -> V_361 ) )
continue;
for ( V_465 = 1 ; ; V_465 ++ ) {
struct V_489 * V_347 ;
const struct V_212 * V_188 = F_120 ( V_465 ) ;
if ( ! V_188 )
break;
if ( ! V_188 -> V_215 )
continue;
if ( ! ( F_181 ( V_403 , V_188 ) && V_188 -> V_361 ) )
continue;
V_347 = (struct V_489 * ) F_44 ( V_8 , sizeof( struct V_489 ) ) ;
memset ( V_347 , 0 , sizeof( * V_347 ) ) ;
V_75 -> V_491 += sizeof( struct V_489 ) / 8 ;
V_347 -> V_496 = V_188 -> V_216 . V_217 ;
V_347 -> V_497 = V_188 -> V_216 . V_498 ;
V_347 -> V_499 = V_188 -> V_216 . V_500 ;
V_347 -> V_505 = V_190 -> V_216 . V_217 ;
V_347 -> V_506 = V_190 -> V_216 . V_498 ;
V_347 -> V_507 = V_190 -> V_216 . V_500 ;
V_347 -> V_501 = 24 * 60 * 60 ;
V_347 -> V_502 = 20 * 60 * 60 ;
V_347 -> V_503 = 8 * 60 * 60 ;
V_347 -> V_504 = 7 * 60 * 60 ;
}
}
}
static int F_187 ( struct V_390 * V_391 , const struct V_346 * V_347 )
{
return 0 ;
}
static int F_188 ( struct V_144 * V_167 , const struct V_346 * V_347 )
{
struct V_42 * V_349 ;
struct V_59 * V_311 ;
int V_508 ;
int V_169 ;
V_508 = V_347 -> V_62 . V_508 ;
if ( V_508 )
V_169 = 2 ;
else
V_169 = 1 ;
V_349 = F_77 ( V_167 , V_169 ) ;
if ( F_95 ( V_349 ) )
return F_96 ( V_349 ) ;
V_311 = (struct V_59 * ) V_349 -> V_62 ;
V_311 -> V_323 = V_29 ;
V_311 -> V_324 = V_345 ;
V_311 -> V_147 = F_55 ( V_167 -> V_197 . V_135 ) ;
V_311 -> V_64 = 0 ;
V_311 -> V_326 = 0 ;
V_311 -> V_63 = 0 ;
V_311 -> V_327 = 0 ;
F_35 ( V_349 , V_56 , NULL , F_103 ( V_167 ) ) ;
return 0 ;
}
static int F_189 ( struct V_144 * V_167 , const struct V_346 * V_347 )
{
struct V_10 * V_10 = V_167 ? F_103 ( V_167 ) : V_347 -> V_10 ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
if ( F_3 ( & V_12 -> V_17 ) == 0 )
return 0 ;
switch ( V_347 -> V_330 ) {
case V_344 :
return F_188 ( V_167 , V_347 ) ;
case V_338 :
case V_340 :
case V_342 :
return F_102 ( V_167 , V_347 ) ;
case V_368 :
return F_125 ( V_347 ) ;
case V_509 :
break;
default:
F_11 ( L_3 , V_347 -> V_330 ) ;
break;
}
return 0 ;
}
static int F_190 ( struct V_390 * V_391 , int V_392 , const struct V_346 * V_347 )
{
if ( V_391 && V_391 -> type != V_399 )
return 0 ;
switch ( V_347 -> V_330 ) {
case V_337 :
return F_187 ( V_391 , V_347 ) ;
case V_331 :
case V_333 :
case V_335 :
return F_150 ( V_391 , V_392 , V_347 ) ;
case V_479 :
if ( V_347 -> V_62 . type != V_399 )
break;
return F_176 ( V_347 ) ;
default:
F_11 ( L_2 , V_347 -> V_330 ) ;
break;
}
return 0 ;
}
static T_6 F_191 ( void )
{
T_6 V_510 ;
static T_10 V_511 ;
do {
V_510 = F_192 ( & V_511 ) ;
} while ( ! V_510 );
return V_510 ;
}
static bool F_193 ( const struct V_346 * V_347 )
{
struct V_11 * V_12 = F_8 ( V_347 -> V_10 , V_13 ) ;
struct V_2 * V_3 ;
bool V_512 = false ;
F_36 () ;
F_37 (sk, &net_pfkey->table) {
if ( F_1 ( V_3 ) -> V_57 ) {
V_512 = true ;
break;
}
}
F_38 () ;
return V_512 ;
}
static int F_194 ( struct V_144 * V_167 , struct V_402 * V_403 , struct V_390 * V_391 )
{
struct V_42 * V_8 ;
struct V_59 * V_60 ;
struct V_76 * V_79 ;
struct V_416 * V_417 ;
int V_181 ;
int V_178 ;
struct V_90 * V_91 ;
struct V_176 * V_177 ;
int V_98 = 0 ;
V_181 = F_63 ( V_167 -> V_184 . V_136 ) ;
if ( ! V_181 )
return - V_71 ;
V_178 = sizeof( struct V_59 ) +
( sizeof( struct V_76 ) * 2 ) +
( V_181 * 2 ) +
sizeof( struct V_416 ) ;
if ( V_167 -> V_197 . V_135 == V_130 )
V_178 += F_183 ( V_403 ) ;
else if ( V_167 -> V_197 . V_135 == V_132 )
V_178 += F_184 ( V_403 ) ;
if ( ( V_177 = V_167 -> V_185 ) ) {
V_98 = F_64 ( V_177 -> V_105 ) ;
V_178 += sizeof( struct V_90 ) + V_98 ;
}
V_8 = F_42 ( V_178 + 16 , V_53 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_323 = V_29 ;
V_60 -> V_324 = V_513 ;
V_60 -> V_147 = F_55 ( V_167 -> V_197 . V_135 ) ;
V_60 -> V_73 = V_178 / sizeof( V_74 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_326 = 0 ;
V_60 -> V_63 = V_167 -> V_201 . V_307 = F_191 () ;
V_60 -> V_327 = 0 ;
V_79 = (struct V_76 * ) F_44 ( V_8 ,
sizeof( struct V_76 ) + V_181 ) ;
V_79 -> V_87 =
( sizeof( struct V_76 ) + V_181 ) /
sizeof( V_74 ) ;
V_79 -> V_251 = V_121 ;
V_79 -> V_252 = 0 ;
V_79 -> V_253 = 0 ;
V_79 -> V_88 =
F_67 ( & V_167 -> V_184 . V_187 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_167 -> V_184 . V_136 ) ;
if ( ! V_79 -> V_88 )
F_75 () ;
V_79 = (struct V_76 * ) F_44 ( V_8 ,
sizeof( struct V_76 ) + V_181 ) ;
V_79 -> V_87 =
( sizeof( struct V_76 ) + V_181 ) /
sizeof( V_74 ) ;
V_79 -> V_251 = V_122 ;
V_79 -> V_252 = 0 ;
V_79 -> V_253 = 0 ;
V_79 -> V_88 =
F_67 ( & V_167 -> V_197 . V_254 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_167 -> V_184 . V_136 ) ;
if ( ! V_79 -> V_88 )
F_75 () ;
V_417 = (struct V_416 * ) F_44 ( V_8 , sizeof( struct V_416 ) ) ;
V_417 -> V_418 = sizeof( struct V_416 ) / sizeof( V_74 ) ;
V_417 -> V_423 = V_424 ;
V_417 -> V_425 = V_429 ;
V_417 -> V_431 = V_514 + 1 ;
V_417 -> V_432 = 0 ;
V_417 -> V_433 = V_391 -> V_434 ;
V_417 -> V_435 = V_391 -> V_436 ;
if ( V_167 -> V_197 . V_135 == V_130 )
F_185 ( V_8 , V_403 ) ;
else if ( V_167 -> V_197 . V_135 == V_132 )
F_186 ( V_8 , V_403 ) ;
if ( V_177 ) {
V_91 = (struct V_90 * ) F_44 ( V_8 ,
sizeof( struct V_90 ) + V_98 ) ;
V_91 -> V_94 =
( sizeof( struct V_90 ) + V_98 ) / sizeof( V_74 ) ;
V_91 -> V_100 = V_125 ;
V_91 -> V_102 = V_177 -> V_101 ;
V_91 -> V_104 = V_177 -> V_103 ;
V_91 -> V_92 = V_177 -> V_105 ;
memcpy ( V_91 + 1 , V_177 -> V_288 ,
V_177 -> V_105 ) ;
}
return F_35 ( V_8 , V_56 , NULL , F_103 ( V_167 ) ) ;
}
static struct V_390 * F_195 ( struct V_2 * V_3 , int V_515 ,
T_7 * V_62 , int V_84 , int * V_392 )
{
struct V_10 * V_10 = F_7 ( V_3 ) ;
struct V_390 * V_391 ;
struct V_416 * V_417 = (struct V_416 * ) V_62 ;
struct V_90 * V_91 ;
switch ( V_3 -> V_39 ) {
case V_86 :
if ( V_515 != V_516 ) {
* V_392 = - V_309 ;
return NULL ;
}
break;
#if F_46 ( V_81 )
case V_89 :
if ( V_515 != V_517 ) {
* V_392 = - V_309 ;
return NULL ;
}
break;
#endif
default:
* V_392 = - V_71 ;
return NULL ;
}
* V_392 = - V_71 ;
if ( V_84 < sizeof( struct V_416 ) ||
V_417 -> V_418 * 8 > V_84 ||
V_417 -> V_425 > V_518 ||
( ! V_417 -> V_431 || V_417 -> V_431 > V_519 ) )
return NULL ;
V_391 = F_152 ( V_10 , V_53 ) ;
if ( V_391 == NULL ) {
* V_392 = - V_45 ;
return NULL ;
}
V_391 -> V_427 = ( V_417 -> V_425 == V_426 ?
V_443 : V_428 ) ;
V_391 -> V_232 . V_242 = V_446 ;
V_391 -> V_232 . V_235 = V_446 ;
V_391 -> V_232 . V_241 = V_446 ;
V_391 -> V_232 . V_233 = V_446 ;
V_391 -> V_136 = V_3 -> V_39 ;
V_391 -> V_393 = 0 ;
if ( V_417 -> V_425 == V_429 &&
( * V_392 = F_145 ( V_391 , V_417 ) ) < 0 )
goto V_35;
if ( V_84 >= ( V_417 -> V_418 * 8 +
sizeof( struct V_90 ) ) ) {
char * V_75 = ( char * ) V_417 ;
struct V_95 * V_97 ;
V_75 += V_417 -> V_418 * 8 ;
V_91 = (struct V_90 * ) V_75 ;
if ( V_84 < V_417 -> V_418 * 8 +
V_91 -> V_94 * 8 ) {
* V_392 = - V_71 ;
goto V_35;
}
if ( ( * V_392 = F_49 ( V_75 ) ) )
goto V_35;
V_97 = F_50 ( V_91 , V_53 ) ;
* V_392 = F_154 ( & V_391 -> V_185 , V_97 , V_53 ) ;
F_83 ( V_97 ) ;
if ( * V_392 )
goto V_35;
}
* V_392 = V_417 -> V_431 - 1 ;
return V_391 ;
V_35:
V_391 -> V_396 . V_447 = 1 ;
F_159 ( V_391 ) ;
return NULL ;
}
static int F_196 ( struct V_144 * V_167 , T_4 * V_520 , T_5 V_256 )
{
struct V_42 * V_8 ;
struct V_59 * V_60 ;
struct V_145 * V_137 ;
struct V_76 * V_79 ;
struct V_194 * V_274 ;
int V_181 ;
int V_178 ;
T_8 V_126 = ( V_167 -> V_197 . V_135 == V_132 ? V_131 : 0 ) ;
struct V_182 * V_183 = NULL ;
V_181 = F_63 ( V_167 -> V_184 . V_136 ) ;
if ( ! V_181 )
return - V_71 ;
if ( ! V_126 )
return - V_71 ;
if ( ! V_167 -> V_191 )
return - V_71 ;
V_183 = V_167 -> V_191 ;
V_178 = sizeof( struct V_59 ) +
sizeof( struct V_145 ) +
( sizeof( struct V_76 ) * 2 ) +
( V_181 * 2 ) +
( sizeof( struct V_194 ) * 2 ) ;
V_8 = F_42 ( V_178 + 16 , V_53 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_323 = V_29 ;
V_60 -> V_324 = V_521 ;
V_60 -> V_147 = V_126 ;
V_60 -> V_73 = V_178 / sizeof( V_74 ) ;
V_60 -> V_64 = 0 ;
V_60 -> V_326 = 0 ;
V_60 -> V_63 = V_167 -> V_201 . V_307 = F_191 () ;
V_60 -> V_327 = 0 ;
V_137 = (struct V_145 * ) F_44 ( V_8 , sizeof( struct V_145 ) ) ;
V_137 -> V_195 = sizeof( struct V_145 ) / sizeof( V_74 ) ;
V_137 -> V_196 = V_146 ;
V_137 -> V_149 = V_167 -> V_197 . V_198 ;
V_137 -> V_199 = 0 ;
V_137 -> V_204 = 0 ;
V_137 -> V_211 = 0 ;
V_137 -> V_218 = 0 ;
V_137 -> V_220 = 0 ;
V_79 = (struct V_76 * )
F_44 ( V_8 , sizeof( struct V_76 ) + V_181 ) ;
V_79 -> V_87 =
( sizeof( struct V_76 ) + V_181 ) /
sizeof( V_74 ) ;
V_79 -> V_251 = V_121 ;
V_79 -> V_252 = 0 ;
V_79 -> V_253 = 0 ;
V_79 -> V_88 =
F_67 ( & V_167 -> V_184 . V_187 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_167 -> V_184 . V_136 ) ;
if ( ! V_79 -> V_88 )
F_75 () ;
V_274 = (struct V_194 * ) F_44 ( V_8 , sizeof ( * V_274 ) ) ;
V_274 -> V_280 = sizeof( * V_274 ) / sizeof( V_74 ) ;
V_274 -> V_281 = V_282 ;
V_274 -> V_283 = V_183 -> V_284 ;
V_274 -> V_285 = 0 ;
V_79 = (struct V_76 * )
F_44 ( V_8 , sizeof( struct V_76 ) + V_181 ) ;
V_79 -> V_87 =
( sizeof( struct V_76 ) + V_181 ) /
sizeof( V_74 ) ;
V_79 -> V_251 = V_122 ;
V_79 -> V_252 = 0 ;
V_79 -> V_253 = 0 ;
V_79 -> V_88 =
F_67 ( V_520 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_167 -> V_184 . V_136 ) ;
if ( ! V_79 -> V_88 )
F_75 () ;
V_274 = (struct V_194 * ) F_44 ( V_8 , sizeof ( * V_274 ) ) ;
V_274 -> V_280 = sizeof( * V_274 ) / sizeof( V_74 ) ;
V_274 -> V_281 = V_286 ;
V_274 -> V_283 = V_256 ;
V_274 -> V_285 = 0 ;
return F_35 ( V_8 , V_56 , NULL , F_103 ( V_167 ) ) ;
}
static int F_197 ( struct V_42 * V_8 , int V_522 , int type ,
const struct V_448 * V_186 )
{
struct V_76 * V_79 ;
V_79 = (struct V_76 * ) F_44 ( V_8 , sizeof( struct V_76 ) + V_522 ) ;
V_79 -> V_87 = ( sizeof( struct V_76 ) + V_522 ) / 8 ;
V_79 -> V_251 = type ;
V_79 -> V_252 = V_186 -> V_135 ;
V_79 -> V_253 = 0 ;
switch ( type ) {
case V_121 :
V_79 -> V_88 = V_186 -> V_255 ;
F_67 ( & V_186 -> V_187 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_186 -> V_136 ) ;
break;
case V_122 :
V_79 -> V_88 = V_186 -> V_421 ;
F_67 ( & V_186 -> V_254 , 0 ,
(struct V_78 * ) ( V_79 + 1 ) ,
V_186 -> V_136 ) ;
break;
default:
return - V_71 ;
}
return 0 ;
}
static int F_198 ( struct V_42 * V_8 , const struct V_464 * V_465 )
{
struct V_462 * V_463 ;
T_7 * V_137 ;
int V_136 = V_465 -> V_136 ;
int V_419 = F_58 ( V_136 ) ;
int V_523 ;
V_523 = ( sizeof( struct V_462 ) +
F_166 ( V_136 ) ) ;
V_463 = (struct V_462 * ) F_44 ( V_8 , V_523 ) ;
memset ( V_463 , 0 , V_523 ) ;
V_463 -> V_469 = V_523 / 8 ;
V_463 -> V_524 = V_466 ;
V_463 -> V_468 = V_465 -> V_467 ;
V_137 = ( T_7 * ) ( V_463 + 1 ) ;
if ( ! F_67 ( & V_465 -> V_470 , 0 , (struct V_78 * ) V_137 , V_136 ) ||
! F_67 ( & V_465 -> V_471 , 0 , (struct V_78 * ) ( V_137 + V_419 ) , V_136 ) )
return - V_71 ;
return 0 ;
}
static int F_199 ( struct V_42 * V_8 ,
V_72 V_135 , V_72 V_150 , int V_525 ,
T_11 V_272 , V_72 V_136 ,
const T_4 * V_106 , const T_4 * V_107 )
{
struct V_400 * V_401 ;
T_7 * V_137 ;
int V_419 = F_58 ( V_136 ) ;
int V_523 ;
V_523 = sizeof( struct V_400 ) +
F_166 ( V_136 ) ;
V_401 = (struct V_400 * ) F_44 ( V_8 , V_523 ) ;
memset ( V_401 , 0 , V_523 ) ;
V_401 -> V_413 = V_523 ;
V_401 -> V_407 = V_135 ;
V_401 -> V_406 = V_150 ;
V_401 -> V_408 = V_525 ;
V_401 -> V_412 = V_272 ;
V_137 = ( T_7 * ) ( V_401 + 1 ) ;
if ( ! F_67 ( V_106 , 0 , (struct V_78 * ) V_137 , V_136 ) ||
! F_67 ( V_107 , 0 , (struct V_78 * ) ( V_137 + V_419 ) , V_136 ) )
return - V_71 ;
return 0 ;
}
static int F_200 ( const struct V_448 * V_186 , T_7 V_392 , T_7 type ,
const struct V_452 * V_453 , int V_526 ,
const struct V_464 * V_465 )
{
int V_353 ;
int V_527 ;
int V_178 = 0 ;
int V_528 = 0 ;
struct V_42 * V_8 ;
struct V_59 * V_60 ;
struct V_416 * V_417 ;
const struct V_452 * V_529 ;
if ( type != V_399 )
return 0 ;
if ( V_526 <= 0 || V_526 > V_404 )
return - V_71 ;
if ( V_465 != NULL ) {
V_178 += F_64 ( sizeof( struct V_462 ) +
F_166 ( V_465 -> V_136 ) ) ;
}
V_527 = F_63 ( V_186 -> V_136 ) ;
if ( ! V_527 )
return - V_71 ;
V_178 += ( sizeof( struct V_76 ) + V_527 ) * 2 ;
V_528 += sizeof( struct V_416 ) ;
for ( V_353 = 0 , V_529 = V_453 ; V_353 < V_526 ; V_353 ++ , V_529 ++ ) {
V_528 += sizeof( struct V_400 ) +
F_166 ( V_529 -> V_457 ) ;
V_528 += sizeof( struct V_400 ) +
F_166 ( V_529 -> V_460 ) ;
}
V_178 += sizeof( struct V_59 ) + V_528 ;
V_8 = F_42 ( V_178 , V_53 ) ;
if ( V_8 == NULL )
return - V_31 ;
V_60 = (struct V_59 * ) F_44 ( V_8 , sizeof( struct V_59 ) ) ;
V_60 -> V_323 = V_29 ;
V_60 -> V_324 = V_530 ;
V_60 -> V_147 = F_55 ( V_453 -> V_135 ) ;
V_60 -> V_73 = V_178 / 8 ;
V_60 -> V_64 = 0 ;
V_60 -> V_326 = 0 ;
V_60 -> V_63 = 0 ;
V_60 -> V_327 = 0 ;
if ( V_465 != NULL && ( F_198 ( V_8 , V_465 ) < 0 ) )
goto V_23;
F_197 ( V_8 , V_527 , V_121 , V_186 ) ;
F_197 ( V_8 , V_527 , V_122 , V_186 ) ;
V_417 = (struct V_416 * ) F_44 ( V_8 , sizeof( struct V_416 ) ) ;
V_417 -> V_418 = V_528 / 8 ;
V_417 -> V_423 = V_424 ;
V_417 -> V_425 = V_429 ;
V_417 -> V_431 = V_392 + 1 ;
V_417 -> V_432 = 0 ;
V_417 -> V_433 = 0 ;
V_417 -> V_435 = 0 ;
for ( V_353 = 0 , V_529 = V_453 ; V_353 < V_526 ; V_353 ++ , V_529 ++ ) {
int V_150 = F_65 ( V_529 -> V_150 ) ;
if ( V_150 < 0 )
goto V_23;
if ( F_199 ( V_8 , V_529 -> V_135 , V_150 ,
( V_529 -> V_272 ? V_411 : V_438 ) ,
V_529 -> V_272 , V_529 -> V_457 ,
& V_529 -> V_455 , & V_529 -> V_456 ) < 0 )
goto V_23;
if ( F_199 ( V_8 , V_529 -> V_135 , V_150 ,
( V_529 -> V_272 ? V_411 : V_438 ) ,
V_529 -> V_272 , V_529 -> V_460 ,
& V_529 -> V_458 , & V_529 -> V_459 ) < 0 )
goto V_23;
}
F_35 ( V_8 , V_54 , NULL , & V_531 ) ;
return 0 ;
V_23:
F_5 ( V_8 ) ;
return - V_71 ;
}
static int F_200 ( const struct V_448 * V_186 , T_7 V_392 , T_7 type ,
const struct V_452 * V_453 , int V_526 ,
const struct V_464 * V_465 )
{
return - V_472 ;
}
static int F_201 ( struct V_20 * V_2 , struct V_532 * V_533 , T_12 V_84 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_42 * V_8 = NULL ;
struct V_59 * V_60 = NULL ;
int V_23 ;
struct V_10 * V_10 = F_7 ( V_3 ) ;
V_23 = - V_309 ;
if ( V_533 -> V_534 & V_535 )
goto V_35;
V_23 = - V_482 ;
if ( ( unsigned int ) V_84 > V_3 -> V_536 - 32 )
goto V_35;
V_23 = - V_45 ;
V_8 = F_42 ( V_84 , V_33 ) ;
if ( V_8 == NULL )
goto V_35;
V_23 = - V_537 ;
if ( F_202 ( F_44 ( V_8 , V_84 ) , V_533 , V_84 ) )
goto V_35;
V_60 = F_180 ( V_8 , & V_23 ) ;
if ( ! V_60 )
goto V_35;
F_15 ( & V_10 -> V_538 . V_539 ) ;
V_23 = F_179 ( V_3 , V_8 , V_60 ) ;
F_17 ( & V_10 -> V_538 . V_539 ) ;
V_35:
if ( V_23 && V_60 && F_41 ( V_60 , V_23 , V_3 ) == 0 )
V_23 = 0 ;
F_5 ( V_8 ) ;
return V_23 ? : V_84 ;
}
static int F_203 ( struct V_20 * V_2 , struct V_532 * V_533 , T_12 V_84 ,
int V_221 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_42 * V_8 ;
int V_540 , V_23 ;
V_23 = - V_71 ;
if ( V_221 & ~ ( V_541 | V_542 | V_543 | V_544 ) )
goto V_35;
V_8 = F_204 ( V_3 , V_221 , V_221 & V_542 , & V_23 ) ;
if ( V_8 == NULL )
goto V_35;
V_540 = V_8 -> V_84 ;
if ( V_540 > V_84 ) {
V_533 -> V_534 |= V_543 ;
V_540 = V_84 ;
}
F_205 ( V_8 ) ;
V_23 = F_206 ( V_8 , 0 , V_533 , V_540 ) ;
if ( V_23 )
goto V_545;
F_207 ( V_533 , V_3 , V_8 ) ;
V_23 = ( V_221 & V_543 ) ? V_8 -> V_84 : V_540 ;
if ( V_6 -> V_7 . V_7 != NULL &&
3 * F_3 ( & V_3 -> V_4 ) <= V_3 -> V_5 )
F_39 ( V_6 ) ;
V_545:
F_208 ( V_3 , V_8 ) ;
V_35:
return V_23 ;
}
static int F_209 ( struct V_546 * V_547 , void * V_548 )
{
struct V_2 * V_549 = F_210 ( V_548 ) ;
if ( V_548 == V_550 )
F_211 ( V_547 , L_4 ) ;
else
F_211 ( V_547 , L_5 ,
V_549 ,
F_3 ( & V_549 -> V_551 ) ,
F_212 ( V_549 ) ,
F_213 ( V_549 ) ,
F_214 ( F_215 ( V_547 ) , F_216 ( V_549 ) ) ,
F_217 ( V_549 )
) ;
return 0 ;
}
static void * F_218 ( struct V_546 * V_547 , T_13 * V_552 )
__acquires( T_14 )
{
struct V_10 * V_10 = F_219 ( V_547 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_36 () ;
return F_220 ( & V_12 -> V_19 , * V_552 ) ;
}
static void * F_221 ( struct V_546 * V_547 , void * V_548 , T_13 * V_552 )
{
struct V_10 * V_10 = F_219 ( V_547 ) ;
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
return F_222 ( V_548 , & V_12 -> V_19 , V_552 ) ;
}
static void F_223 ( struct V_546 * V_547 , void * V_548 )
__releases( T_14 )
{
F_38 () ;
}
static int F_224 ( struct V_553 * V_553 , struct V_554 * V_554 )
{
return F_225 ( V_553 , V_554 , & V_555 ,
sizeof( struct V_556 ) ) ;
}
static int T_15 F_226 ( struct V_10 * V_10 )
{
struct V_557 * V_558 ;
V_558 = F_227 ( L_6 , 0 , V_10 -> V_559 , & V_560 ) ;
if ( V_558 == NULL )
return - V_31 ;
return 0 ;
}
static void T_16 F_228 ( struct V_10 * V_10 )
{
F_229 ( L_6 , V_10 -> V_559 ) ;
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
int V_561 ;
F_231 ( & V_12 -> V_19 ) ;
F_232 ( & V_12 -> V_17 , 0 ) ;
V_561 = F_226 ( V_10 ) ;
return V_561 ;
}
static void T_16 F_233 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , V_13 ) ;
F_228 ( V_10 ) ;
F_43 ( ! F_234 ( & V_12 -> V_19 ) ) ;
}
static void T_17 F_235 ( void )
{
F_236 ( & V_562 ) ;
F_237 ( V_32 ) ;
F_238 ( & V_563 ) ;
F_239 ( & V_34 ) ;
}
static int T_18 F_240 ( void )
{
int V_23 = F_241 ( & V_34 , 0 ) ;
if ( V_23 != 0 )
goto V_35;
V_23 = F_242 ( & V_563 ) ;
if ( V_23 != 0 )
goto V_564;
V_23 = F_243 ( & V_565 ) ;
if ( V_23 != 0 )
goto V_566;
V_23 = F_244 ( & V_562 ) ;
if ( V_23 != 0 )
goto V_567;
V_35:
return V_23 ;
V_567:
F_237 ( V_32 ) ;
V_566:
F_238 ( & V_563 ) ;
V_564:
F_239 ( & V_34 ) ;
goto V_35;
}
