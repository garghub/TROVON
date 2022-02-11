static inline int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_3 ( V_4 , & V_3 -> V_5 ) ;
}
void F_4 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
F_5 ( & V_8 ) ;
F_6 ( & V_7 -> V_9 , & V_9 ) ;
if ( V_7 -> V_10 ) {
F_7 (tdev, &ofld_dev_list, ofld_dev_list) {
if ( F_1 ( V_2 ) )
V_7 -> V_10 ( V_2 ) ;
}
}
F_8 ( & V_8 ) ;
}
void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
F_5 ( & V_8 ) ;
F_10 ( & V_7 -> V_9 ) ;
if ( V_7 -> remove ) {
F_7 (tdev, &ofld_dev_list, ofld_dev_list) {
if ( F_1 ( V_2 ) )
V_7 -> remove ( V_2 ) ;
}
}
F_8 ( & V_8 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_5 ( & V_8 ) ;
F_7 (client, &client_list, client_list) {
if ( V_7 -> V_10 )
V_7 -> V_10 ( V_2 ) ;
}
F_8 ( & V_8 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_5 ( & V_8 ) ;
F_7 (client, &client_list, client_list) {
if ( V_7 -> remove )
V_7 -> remove ( V_2 ) ;
}
F_8 ( & V_8 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 )
{
struct V_6 * V_7 ;
F_5 ( & V_8 ) ;
F_7 (client, &client_list, client_list) {
if ( V_7 -> V_13 )
V_7 -> V_13 ( V_2 , V_11 , V_12 ) ;
}
F_8 ( & V_8 ) ;
}
static struct V_14 * F_14 ( struct V_3 * V_3 ,
const unsigned char * V_15 ,
unsigned int V_16 )
{
int V_17 ;
F_15 (adapter, i) {
struct V_18 * V_19 ;
struct V_14 * V_20 = V_3 -> V_12 [ V_17 ] ;
const struct V_21 * V_22 = F_16 ( V_20 ) ;
if ( ! memcmp ( V_20 -> V_23 , V_15 , V_24 ) ) {
if ( V_16 && V_16 != V_25 ) {
V_19 = V_22 -> V_26 ;
V_20 = NULL ;
if ( V_19 )
V_20 = F_17 ( V_19 , V_16 ) ;
} else if ( F_18 ( V_20 ) ) {
while ( V_20 -> V_27 )
V_20 = V_20 -> V_27 ;
}
return V_20 ;
}
}
return NULL ;
}
static int F_19 ( struct V_3 * V_3 , unsigned int V_28 ,
void * V_29 )
{
int V_17 ;
int V_30 = 0 ;
unsigned int V_31 = 0 ;
struct V_32 * V_33 = V_29 ;
switch ( V_28 ) {
case V_34 :
V_33 -> V_35 = V_3 -> V_35 ;
V_33 -> V_36 = F_20 ( V_3 , V_37 ) ;
V_33 -> V_38 = F_20 ( V_3 , V_39 ) ;
V_33 -> V_40 = F_20 ( V_3 , V_41 ) ;
V_31 = F_20 ( V_3 , V_42 ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ , V_31 >>= 8 )
V_33 -> V_43 [ V_17 ] = V_31 & 0xFF ;
V_31 = F_20 ( V_3 , V_44 ) ;
V_33 -> V_45 =
V_33 -> V_46 = F_21 ( ( V_31 >> V_47 ) & V_48 ,
( V_31 >> V_49 ) & V_50 ) ;
V_31 = F_21 ( V_3 -> V_51 . V_52 . V_53 ,
F_20 ( V_3 , V_54 ) >> 17 ) ;
V_33 -> V_45 = F_21 ( V_31 , V_33 -> V_45 ) ;
V_31 = F_20 ( V_3 , V_55 ) ;
if ( ( V_31 >> V_56 ) != 0x3f60 ) {
V_31 &= ( V_57 << V_58 ) ;
V_31 |= F_22 ( 0x3f60 ) ;
F_23 ( V_59
L_1 ,
V_3 -> V_60 , V_31 ) ;
F_24 ( V_3 , V_55 , V_31 ) ;
}
V_31 = F_21 ( V_3 -> V_51 . V_52 . V_61 ,
( ( F_20 ( V_3 , V_55 ) ) >>
V_56 ) & V_62 ) ;
V_33 -> V_46 = F_21 ( V_31 , V_33 -> V_46 ) ;
break;
case V_63 :
F_24 ( V_3 , V_41 , V_33 -> V_40 ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ )
V_31 |= ( V_33 -> V_43 [ V_17 ] & 0xF ) << ( 8 * V_17 ) ;
if ( V_31 && ( V_31 != F_20 ( V_3 , V_42 ) ) ) {
F_23 ( V_59
L_2 ,
V_3 -> V_60 , V_31 , V_33 -> V_43 [ 0 ] ,
V_33 -> V_43 [ 1 ] , V_33 -> V_43 [ 2 ] ,
V_33 -> V_43 [ 3 ] ) ;
F_24 ( V_3 , V_42 , V_31 ) ;
}
break;
default:
V_30 = - V_64 ;
}
return V_30 ;
}
static int F_25 ( struct V_3 * V_3 , unsigned int V_28 , void * V_29 )
{
int V_30 = 0 ;
switch ( V_28 ) {
case V_65 : {
struct V_66 * V_67 = V_29 ;
struct V_68 * V_35 = V_3 -> V_35 ;
V_67 -> V_69 = F_26 ( V_35 , 2 ) ;
V_67 -> V_70 = F_27 ( V_35 , 2 ) ;
V_67 -> V_71 =
F_20 ( V_3 , V_72 ) ;
V_67 -> V_73 = F_20 ( V_3 , V_74 ) ;
V_67 -> V_75 =
F_20 ( V_3 , V_76 ) ;
V_67 -> V_77 = F_20 ( V_3 , V_78 ) ;
V_67 -> V_79 = F_20 ( V_3 , V_80 ) ;
V_67 -> V_81 = F_20 ( V_3 , V_82 ) ;
V_67 -> V_83 = V_3 -> V_84 + V_85 ;
V_67 -> V_35 = V_35 ;
break;
}
case V_86 : {
unsigned long V_87 ;
struct V_88 * V_67 = V_29 ;
F_28 ( & V_3 -> V_89 . V_90 , V_87 ) ;
V_30 = F_29 ( V_3 , V_67 -> V_91 , V_67 -> V_92 ,
V_67 -> V_93 ) ;
F_30 ( & V_3 -> V_89 . V_90 , V_87 ) ;
break;
}
case V_94 : {
struct V_95 * V_96 = V_29 ;
struct V_97 * V_98 ;
if ( ( V_96 -> V_99 & 7 ) || ( V_96 -> V_100 & 7 ) )
return - V_101 ;
if ( V_96 -> V_102 == V_103 )
V_98 = & V_3 -> V_104 ;
else if ( V_96 -> V_102 == V_105 )
V_98 = & V_3 -> V_106 ;
else if ( V_96 -> V_102 == V_107 )
V_98 = & V_3 -> V_108 ;
else
return - V_101 ;
V_30 =
F_31 ( V_98 , V_96 -> V_99 / 8 , V_96 -> V_100 / 8 ,
( V_109 * ) V_96 -> V_110 ) ;
if ( V_30 )
return V_30 ;
break;
}
case V_111 : {
struct V_112 * V_67 = V_29 ;
F_32 ( & V_3 -> V_89 . V_90 ) ;
V_30 =
F_33 ( V_3 , V_67 -> V_91 ,
V_67 -> V_113 , V_67 -> V_114 ,
V_115 ,
V_67 -> V_116 , V_67 -> V_93 ,
V_67 -> V_117 ) ;
F_34 ( & V_3 -> V_89 . V_90 ) ;
break;
}
case V_118 :
F_32 ( & V_3 -> V_89 . V_90 ) ;
V_30 = F_35 ( V_3 , * ( unsigned int * ) V_29 ) ;
F_34 ( & V_3 -> V_89 . V_90 ) ;
break;
case V_119 : {
struct V_120 * V_67 = V_29 ;
F_32 ( & V_3 -> V_89 . V_90 ) ;
V_30 = F_36 ( V_3 , V_121 , 0 ,
V_122 ,
V_115 ,
V_67 -> V_113 , V_67 -> V_114 ,
V_123 , 1 , 0 ) ;
F_34 ( & V_3 -> V_89 . V_90 ) ;
break;
}
case V_124 : {
F_37 ( & V_3 -> V_125 ) ;
F_38 ( V_3 , (struct V_126 * ) V_29 ) ;
F_39 ( & V_3 -> V_125 ) ;
break;
}
default:
V_30 = - V_64 ;
}
return V_30 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_28 , void * V_29 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_139 * V_52 = & V_3 -> V_51 . V_52 ;
int V_17 ;
switch ( V_28 ) {
case V_140 :
* ( unsigned int * ) V_29 = V_141 ;
break;
case V_142 :
* ( unsigned int * ) V_29 = V_143 ;
break;
case V_144 :
* ( unsigned int * ) V_29 = 1 << 20 ;
break;
case V_145 :
V_128 = V_29 ;
V_128 -> V_146 = F_41 ( & V_3 -> V_147 ) -
V_3 -> V_51 . V_147 . V_148 -
V_3 -> V_51 . V_147 . V_149 - V_3 -> V_51 . V_147 . V_150 ;
V_128 -> V_151 = 0 ;
break;
case V_152 :
V_128 = V_29 ;
V_128 -> V_146 = V_3 -> V_51 . V_147 . V_150 ;
V_128 -> V_151 = F_41 ( & V_3 -> V_147 ) - V_128 -> V_146 -
V_3 -> V_51 . V_147 . V_149 - V_3 -> V_51 . V_147 . V_148 ;
break;
case V_153 :
* ( unsigned int * ) V_29 = 2048 ;
break;
case V_154 :
V_130 = V_29 ;
V_130 -> V_114 = V_155 ;
V_130 -> V_156 = V_3 -> V_51 . V_156 ;
break;
case V_157 :
V_132 = V_29 ;
V_132 -> V_20 = F_14 ( V_3 , V_132 -> V_158 ,
V_132 -> V_159 &
V_25 ) ;
break;
case V_160 :
V_134 = V_29 ;
V_134 -> V_36 = F_20 ( V_3 , V_161 ) ;
V_134 -> V_38 = F_20 ( V_3 , V_162 ) ;
V_134 -> V_163 = F_20 ( V_3 , V_164 ) ;
break;
case V_165 :
V_136 = V_29 ;
V_136 -> V_166 = V_3 -> V_51 . V_166 ;
F_15 (adapter, i)
V_136 -> V_167 [ V_17 ] = V_3 -> V_12 [ V_17 ] ;
break;
case V_34 :
case V_63 :
if ( ! F_42 ( V_3 ) )
return - V_168 ;
return F_19 ( V_3 , V_28 , V_29 ) ;
case V_65 :
case V_86 :
case V_111 :
case V_118 :
case V_119 :
case V_94 :
case V_124 :
if ( ! F_42 ( V_3 ) )
return - V_168 ;
return F_25 ( V_3 , V_28 , V_29 ) ;
case V_169 :
V_138 = V_29 ;
V_138 -> V_170 = V_52 -> V_61 ;
V_138 -> V_146 = V_52 -> V_171 ;
break;
case V_172 : {
struct V_173 * V_22 = V_29 ;
struct V_21 * V_174 = F_16 ( V_22 -> V_20 ) ;
V_22 -> V_175 = V_174 -> V_173 ;
break;
}
case V_176 : {
struct V_177 * V_178 = V_29 ;
F_37 ( & V_3 -> V_125 ) ;
F_43 ( V_3 , & V_178 -> V_179 ) ;
F_44 ( V_3 , & V_178 -> V_180 ) ;
F_39 ( & V_3 -> V_125 ) ;
break;
}
default:
return - V_64 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_20 , struct V_181 * * V_182 ,
int V_183 )
{
while ( V_183 -- )
F_46 ( V_182 [ V_183 ] ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_20 , struct V_184 * V_185 )
{
}
void F_48 ( struct V_1 * V_20 )
{
V_20 -> V_186 = F_45 ;
V_20 -> V_187 = F_47 ;
}
void * F_49 ( struct V_1 * V_2 , int V_188 )
{
struct V_189 * V_96 = & ( F_50 ( V_2 ) ) -> V_190 ;
union V_191 * V_22 = F_51 ( V_96 , V_188 ) ;
void * V_192 = V_22 -> V_193 . V_192 ;
F_52 ( & V_96 -> V_194 ) ;
V_22 -> V_195 = V_96 -> V_196 ;
V_96 -> V_196 = V_22 ;
V_96 -> V_197 -- ;
F_53 ( & V_96 -> V_194 ) ;
return V_192 ;
}
void F_54 ( struct V_1 * V_2 , int V_198 )
{
struct V_189 * V_96 = & ( F_50 ( V_2 ) ) -> V_190 ;
union V_199 * V_22 = F_55 ( V_96 , V_198 ) ;
F_52 ( & V_96 -> V_200 ) ;
V_22 -> V_195 = V_96 -> V_201 ;
V_96 -> V_201 = V_22 ;
V_96 -> V_202 -- ;
F_53 ( & V_96 -> V_200 ) ;
}
void F_56 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_192 , unsigned int V_128 )
{
struct V_189 * V_96 = & ( F_50 ( V_2 ) ) -> V_190 ;
V_96 -> V_203 [ V_128 ] . V_7 = V_7 ;
V_96 -> V_203 [ V_128 ] . V_192 = V_192 ;
F_57 ( & V_96 -> V_204 ) ;
}
static inline void F_58 ( struct V_181 * V_205 , unsigned int V_128 )
{
struct V_206 * V_28 ;
V_205 -> V_207 = V_208 ;
V_28 = (struct V_206 * ) F_59 ( V_205 , sizeof( * V_28 ) ) ;
V_28 -> V_209 . V_210 = F_60 ( F_61 ( V_211 ) ) ;
F_62 ( V_28 ) = F_60 ( F_63 ( V_212 , V_128 ) ) ;
}
static void F_64 ( struct V_213 * V_214 )
{
struct V_215 * V_216 = F_65 ( V_214 , struct V_215 ,
V_217 ) ;
struct V_181 * V_205 ;
struct V_1 * V_2 = V_216 -> V_20 ;
F_52 ( & V_216 -> V_218 ) ;
while ( V_216 -> V_219 ) {
struct V_220 * V_22 = V_216 -> V_219 ;
V_216 -> V_219 = (struct V_220 * ) V_22 -> V_192 ;
F_53 ( & V_216 -> V_218 ) ;
V_205 = F_66 ( sizeof( struct V_206 ) ,
V_221 ) ;
if ( ! V_205 )
V_205 = V_216 -> V_222 ;
if ( ! V_205 ) {
F_52 ( & V_216 -> V_218 ) ;
V_22 -> V_192 = ( void * ) V_216 -> V_219 ;
V_216 -> V_219 = (struct V_220 * ) V_22 ;
break;
}
F_58 ( V_205 , V_22 - V_216 -> V_190 . V_203 ) ;
F_67 ( V_2 , V_205 ) ;
V_22 -> V_192 = NULL ;
if ( V_205 == V_216 -> V_222 )
V_216 -> V_222 =
F_66 ( sizeof( struct V_206 ) ,
V_221 ) ;
F_52 ( & V_216 -> V_218 ) ;
}
V_216 -> V_223 = ( V_216 -> V_219 == NULL ) ? 0 : 1 ;
F_53 ( & V_216 -> V_218 ) ;
if ( ! V_216 -> V_222 )
V_216 -> V_222 =
F_66 ( sizeof( struct V_206 ) ,
V_221 ) ;
}
void F_68 ( struct V_1 * V_2 , unsigned int V_128 )
{
struct V_215 * V_216 = F_50 ( V_2 ) ;
struct V_220 * V_22 = & V_216 -> V_190 . V_203 [ V_128 ] ;
F_52 ( & V_216 -> V_218 ) ;
V_22 -> V_192 = ( void * ) V_216 -> V_219 ;
V_22 -> V_7 = NULL ;
V_216 -> V_219 = V_22 ;
if ( ! V_22 -> V_192 || V_216 -> V_223 )
F_69 ( & V_216 -> V_217 ) ;
F_53 ( & V_216 -> V_218 ) ;
}
void F_70 ( struct V_1 * V_2 , void * V_192 , unsigned int V_128 )
{
struct V_189 * V_96 = & ( F_50 ( V_2 ) ) -> V_190 ;
F_71 ( V_128 >= V_96 -> V_224 ) ;
if ( V_2 -> type == V_225 )
( void ) F_72 ( & V_96 -> V_203 [ V_128 ] . V_192 , V_192 , NULL ) ;
else {
struct V_181 * V_205 ;
V_205 = F_66 ( sizeof( struct V_206 ) , V_226 ) ;
if ( F_73 ( V_205 ) ) {
F_58 ( V_205 , V_128 ) ;
F_67 ( V_2 , V_205 ) ;
V_96 -> V_203 [ V_128 ] . V_192 = NULL ;
} else
F_68 ( V_2 , V_128 ) ;
}
F_74 ( & V_96 -> V_204 ) ;
}
int F_75 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_192 )
{
int V_188 = - 1 ;
struct V_189 * V_96 = & ( F_50 ( V_2 ) ) -> V_190 ;
F_52 ( & V_96 -> V_194 ) ;
if ( V_96 -> V_196 &&
V_96 -> V_197 + F_76 ( & V_96 -> V_204 ) + V_227 <=
V_96 -> V_224 ) {
union V_191 * V_22 = V_96 -> V_196 ;
V_188 = ( V_22 - V_96 -> V_228 ) + V_96 -> V_229 ;
V_96 -> V_196 = V_22 -> V_195 ;
V_22 -> V_193 . V_192 = V_192 ;
V_22 -> V_193 . V_7 = V_7 ;
V_96 -> V_197 ++ ;
}
F_53 ( & V_96 -> V_194 ) ;
return V_188 ;
}
int F_77 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_192 )
{
int V_198 = - 1 ;
struct V_189 * V_96 = & ( F_50 ( V_2 ) ) -> V_190 ;
F_52 ( & V_96 -> V_200 ) ;
if ( V_96 -> V_201 ) {
union V_199 * V_22 = V_96 -> V_201 ;
V_198 = ( V_22 - V_96 -> V_230 ) + V_96 -> V_231 ;
V_96 -> V_201 = V_22 -> V_195 ;
V_22 -> V_193 . V_192 = V_192 ;
V_22 -> V_193 . V_7 = V_7 ;
V_96 -> V_202 ++ ;
}
F_53 ( & V_96 -> V_200 ) ;
return V_198 ;
}
struct V_1 * F_78 ( struct V_14 * V_20 )
{
const struct V_21 * V_174 = F_16 ( V_20 ) ;
return (struct V_1 * ) V_174 -> V_3 ;
}
static int F_79 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
struct V_232 * V_233 = F_80 ( V_205 ) ;
if ( V_233 -> V_234 != V_235 )
F_23 ( V_236
L_3 ,
V_233 -> V_234 , F_81 ( V_233 ) ) ;
return V_237 ;
}
static int F_82 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
struct V_238 * V_233 = F_80 ( V_205 ) ;
if ( V_233 -> V_234 != V_235 )
F_23 ( V_236
L_4 ,
V_233 -> V_234 , F_81 ( V_233 ) ) ;
return V_237 ;
}
static int F_83 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
struct V_239 * V_233 = F_80 ( V_205 ) ;
if ( V_233 -> V_234 != V_235 )
F_23 ( V_236
L_5 ,
V_233 -> V_234 , F_81 ( V_233 ) ) ;
return V_237 ;
}
static int F_84 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
struct V_240 * V_233 = F_80 ( V_205 ) ;
unsigned int V_188 = F_85 ( F_86 ( V_233 -> V_188 ) ) ;
struct V_220 * V_193 ;
V_193 = F_87 ( & ( F_50 ( V_20 ) ) -> V_190 , V_188 ) ;
if ( V_193 && V_193 -> V_192 && V_193 -> V_7 &&
V_193 -> V_7 -> V_241 &&
V_193 -> V_7 -> V_241 [ V_242 ] ) {
return V_193 -> V_7 -> V_241 [ V_242 ] ( V_20 , V_205 ,
V_193 ->
V_192 ) ;
} else {
F_23 ( V_236 L_6 ,
V_20 -> V_60 , V_242 ) ;
return V_237 | V_243 ;
}
}
static int F_88 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
union V_244 * V_22 = F_80 ( V_205 ) ;
unsigned int V_198 = F_85 ( F_86 ( V_22 -> V_244 ) ) ;
struct V_220 * V_193 ;
V_193 = F_89 ( & ( F_50 ( V_20 ) ) -> V_190 , V_198 ) ;
if ( V_193 && V_193 -> V_192 && V_193 -> V_7 -> V_241 &&
V_193 -> V_7 -> V_241 [ V_22 -> V_245 ] ) {
return V_193 -> V_7 -> V_241 [ V_22 -> V_245 ] ( V_20 , V_205 ,
V_193 -> V_192 ) ;
} else {
F_23 ( V_236 L_6 ,
V_20 -> V_60 , V_22 -> V_245 ) ;
return V_237 | V_243 ;
}
}
static int F_90 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
union V_244 * V_22 = F_80 ( V_205 ) ;
unsigned int V_246 = F_85 ( F_86 ( V_22 -> V_244 ) ) ;
struct V_220 * V_193 ;
V_193 = F_91 ( & ( F_50 ( V_20 ) ) -> V_190 , V_246 ) ;
if ( V_193 && V_193 -> V_192 && V_193 -> V_7 -> V_241 &&
V_193 -> V_7 -> V_241 [ V_22 -> V_245 ] ) {
return V_193 -> V_7 -> V_241 [ V_22 -> V_245 ]
( V_20 , V_205 , V_193 -> V_192 ) ;
} else {
F_23 ( V_236 L_6 ,
V_20 -> V_60 , V_22 -> V_245 ) ;
return V_237 | V_243 ;
}
}
static int F_92 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
struct V_247 * V_28 = F_80 ( V_205 ) ;
unsigned int V_198 = F_93 ( F_86 ( V_28 -> V_248 ) ) ;
struct V_189 * V_96 = & ( F_50 ( V_20 ) ) -> V_190 ;
struct V_220 * V_193 ;
unsigned int V_128 = F_81 ( V_28 ) ;
if ( F_94 ( V_128 >= V_96 -> V_224 ) ) {
F_23 ( L_7 ,
V_20 -> V_60 , V_128 ) ;
F_95 ( F_2 ( V_20 ) ) ;
return V_237 ;
}
V_193 = F_89 ( V_96 , V_198 ) ;
if ( V_193 && V_193 -> V_192 && V_193 -> V_7 -> V_241 &&
V_193 -> V_7 -> V_241 [ V_249 ] ) {
return V_193 -> V_7 -> V_241 [ V_249 ]
( V_20 , V_205 , V_193 -> V_192 ) ;
} else {
F_23 ( V_236 L_6 ,
V_20 -> V_60 , V_249 ) ;
return V_237 | V_243 ;
}
}
static struct V_181 * F_96 ( struct V_181 * V_205 , T_2 V_100 ,
T_3 V_250 )
{
if ( F_73 ( ! F_97 ( V_205 ) ) ) {
F_71 ( V_205 -> V_100 < V_100 ) ;
F_98 ( V_205 , V_100 ) ;
F_99 ( V_205 ) ;
} else {
V_205 = F_66 ( V_100 , V_250 ) ;
if ( V_205 )
F_59 ( V_205 , V_100 ) ;
}
return V_205 ;
}
static int F_100 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
union V_244 * V_22 = F_80 ( V_205 ) ;
unsigned int V_246 = F_85 ( F_86 ( V_22 -> V_244 ) ) ;
struct V_220 * V_193 ;
V_193 = F_91 ( & ( F_50 ( V_20 ) ) -> V_190 , V_246 ) ;
if ( V_193 && V_193 -> V_192 && V_193 -> V_7 -> V_241 &&
V_193 -> V_7 -> V_241 [ V_22 -> V_245 ] ) {
return V_193 -> V_7 -> V_241 [ V_22 -> V_245 ]
( V_20 , V_205 , V_193 -> V_192 ) ;
} else {
struct V_251 * V_28 = F_80 ( V_205 ) ;
struct V_252 * V_233 ;
struct V_181 * V_253 ;
unsigned int V_128 = F_81 ( V_28 ) ;
T_4 V_254 = V_28 -> V_234 ;
if ( V_28 -> V_234 == V_255 ||
V_28 -> V_234 == V_256 )
goto V_257;
V_253 = F_96 ( V_205 ,
sizeof( struct
V_252 ) ,
V_226 ) ;
if ( ! V_253 ) {
F_23 ( L_8 ) ;
goto V_257;
}
V_253 -> V_207 = V_258 ;
F_59 ( V_253 , sizeof( struct V_252 ) ) ;
V_233 = F_80 ( V_253 ) ;
V_233 -> V_209 . V_210 =
F_60 ( F_61 ( V_259 ) ) ;
V_233 -> V_209 . V_260 = F_60 ( F_101 ( V_128 ) ) ;
F_62 ( V_233 ) = F_60 ( F_63 ( V_261 , V_128 ) ) ;
V_233 -> V_254 = V_254 ;
F_67 ( V_20 , V_253 ) ;
V_257:
return V_237 ;
}
}
static int F_102 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
struct V_262 * V_28 = F_80 ( V_205 ) ;
unsigned int V_188 = F_93 ( F_86 ( V_28 -> V_248 ) ) ;
struct V_189 * V_96 = & ( F_50 ( V_20 ) ) -> V_190 ;
struct V_220 * V_193 ;
unsigned int V_128 = F_81 ( V_28 ) ;
if ( F_94 ( V_128 >= V_96 -> V_224 ) ) {
F_23 ( L_9 ,
V_20 -> V_60 , V_128 ) ;
F_95 ( F_2 ( V_20 ) ) ;
return V_237 ;
}
V_193 = F_87 ( V_96 , V_188 ) ;
if ( V_193 && V_193 -> V_192 && V_193 -> V_7 -> V_241 &&
V_193 -> V_7 -> V_241 [ V_263 ] ) {
return V_193 -> V_7 -> V_241 [ V_263 ]
( V_20 , V_205 , V_193 -> V_192 ) ;
} else {
F_23 ( V_236 L_6 ,
V_20 -> V_60 , V_263 ) ;
return V_237 | V_243 ;
}
}
static int F_103 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
struct V_264 * V_22 = F_80 ( V_205 ) ;
V_205 -> V_265 = F_104 ( 0xffff ) ;
V_205 -> V_20 = V_20 -> V_266 ;
F_105 ( V_205 , sizeof( * V_22 ) ) ;
F_106 ( V_205 ) ;
F_107 ( V_205 ) ;
return 0 ;
}
static inline T_1 F_108 ( struct V_181 * V_205 )
{
return F_86 ( ( V_267 V_268 ) V_205 -> V_207 ) >> 8 & 0xfffff ;
}
static inline T_1 F_109 ( struct V_181 * V_205 )
{
return F_110 ( F_86 ( ( V_267 V_268 ) V_205 -> V_269 ) ) ;
}
static int F_111 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
unsigned int V_246 = F_108 ( V_205 ) ;
unsigned int V_245 = F_109 ( V_205 ) ;
struct V_220 * V_193 ;
V_193 = F_91 ( & ( F_50 ( V_20 ) ) -> V_190 , V_246 ) ;
if ( V_193 && V_193 -> V_192 && V_193 -> V_7 -> V_241 &&
V_193 -> V_7 -> V_241 [ V_245 ] ) {
return V_193 -> V_7 -> V_241 [ V_245 ] ( V_20 , V_205 ,
V_193 -> V_192 ) ;
} else {
F_23 ( V_236 L_6 ,
V_20 -> V_60 , V_245 ) ;
return V_237 | V_243 ;
}
}
static int F_112 ( struct V_270 * V_271 , unsigned long V_11 ,
void * V_192 )
{
switch ( V_11 ) {
case ( V_272 ) : {
F_113 ( (struct V_184 * ) V_192 ) ;
break;
}
case ( V_273 ) : {
struct V_274 * V_275 = V_192 ;
F_114 ( V_275 -> V_276 , V_275 -> V_277 ) ;
F_113 ( V_275 -> V_277 -> V_184 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_115 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
F_23 ( V_236 L_10 , V_20 -> V_60 ,
* V_205 -> V_29 ) ;
return V_237 | V_243 ;
}
void F_116 ( unsigned int V_245 , T_5 V_278 )
{
if ( V_245 < V_279 )
V_280 [ V_245 ] = V_278 ? V_278 : F_115 ;
else
F_23 ( V_236 L_11
L_12 , V_245 ) ;
}
static int F_117 ( struct V_1 * V_20 , struct V_181 * * V_182 , int V_183 )
{
while ( V_183 -- ) {
struct V_181 * V_205 = * V_182 ++ ;
unsigned int V_245 = F_109 ( V_205 ) ;
int V_30 = V_280 [ V_245 ] ( V_20, V_205 ) ;
#if V_281
if ( V_30 & V_282 ) {
union V_244 * V_22 = F_80 ( V_205 ) ;
F_23 ( V_236 L_13
L_14 , V_20 -> V_60 , V_245 ,
F_85 ( F_86 ( V_22 -> V_244 ) ) ) ;
}
#endif
if ( V_30 & V_237 )
F_118 ( V_205 ) ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_20 , struct V_181 * V_205 )
{
int V_283 ;
F_119 () ;
V_283 = V_20 -> V_284 ( V_20 , V_205 ) ;
F_120 () ;
return V_283 ;
}
static int F_121 ( struct V_14 * V_20 )
{
struct V_3 * V_3 ;
int V_17 ;
F_122 ( & V_285 ) ;
F_7 (adapter, &adapter_list, adapter_list) {
F_15 (adapter, i) {
if ( V_20 == V_3 -> V_12 [ V_17 ] ) {
F_123 ( & V_285 ) ;
return 1 ;
}
}
}
F_123 ( & V_285 ) ;
return 0 ;
}
static void F_113 ( struct V_184 * V_185 )
{
struct V_14 * V_20 = V_185 -> V_20 ;
if ( V_20 && ( F_121 ( V_20 ) ) ) {
struct V_1 * V_2 = F_78 ( V_20 ) ;
F_71 ( ! V_2 ) ;
F_124 ( V_2 , V_185 ) ;
}
}
static void F_125 ( struct V_1 * V_2 , T_1 V_128 , struct V_286 * V_178 )
{
struct V_181 * V_205 ;
struct V_287 * V_28 ;
V_205 = F_66 ( sizeof( * V_28 ) , V_226 ) ;
if ( ! V_205 ) {
F_23 ( V_236 L_15 , V_288 ) ;
return;
}
V_205 -> V_207 = V_289 ;
V_28 = (struct V_287 * ) F_126 ( V_205 , sizeof( * V_28 ) ) ;
V_28 -> V_209 . V_210 = F_60 ( F_61 ( V_211 ) ) ;
F_62 ( V_28 ) = F_60 ( F_63 ( V_290 , V_128 ) ) ;
V_28 -> V_291 = 0 ;
V_28 -> V_292 = 0 ;
V_28 -> V_293 = F_104 ( V_294 ) ;
V_28 -> V_295 = F_127 ( F_128 ( V_296 ) ) ;
V_28 -> V_31 = F_127 ( F_128 ( V_178 -> V_297 ) ) ;
V_2 -> V_284 ( V_2 , V_205 ) ;
}
static void F_114 ( struct V_298 * V_276 , struct V_298 * V_277 )
{
struct V_14 * V_299 , * V_300 ;
struct V_189 * V_301 ;
struct V_1 * V_2 ;
T_1 V_128 ;
int V_302 ;
struct V_286 * V_178 ;
struct V_220 * V_303 ;
V_299 = V_276 -> V_184 -> V_20 ;
V_300 = V_277 -> V_184 -> V_20 ;
if ( ! F_121 ( V_299 ) )
return;
if ( ! F_121 ( V_300 ) ) {
F_23 ( V_304 L_16
L_17 , V_288 ) ;
return;
}
V_2 = F_78 ( V_299 ) ;
F_71 ( ! V_2 ) ;
if ( V_2 != F_78 ( V_300 ) ) {
F_23 ( V_304 L_18
L_19 , V_288 ) ;
return;
}
V_178 = F_129 ( V_2 , V_277 -> V_184 , V_300 ) ;
if ( ! V_178 ) {
F_23 ( V_236 L_20 ,
V_288 ) ;
return;
}
V_301 = & ( F_50 ( V_2 ) ) -> V_190 ;
for ( V_128 = 0 ; V_128 < V_301 -> V_224 ; V_128 ++ ) {
V_303 = F_91 ( V_301 , V_128 ) ;
F_71 ( ! V_303 ) ;
if ( V_303 && V_303 -> V_192 && V_303 -> V_7 && V_303 -> V_7 -> V_305 ) {
V_302 = V_303 -> V_7 -> V_305 ( V_303 -> V_192 , V_276 , V_277 , V_178 ) ;
if ( V_302 ) {
F_130 ( F_131 ( V_2 ) , V_178 ) ;
F_125 ( V_2 , V_128 , V_178 ) ;
}
}
}
F_132 ( F_131 ( V_2 ) , V_178 ) ;
}
void * F_133 ( unsigned long V_114 )
{
void * V_22 = F_134 ( V_114 , V_221 ) ;
if ( ! V_22 )
V_22 = F_135 ( V_114 ) ;
return V_22 ;
}
void F_136 ( void * V_99 )
{
if ( F_137 ( V_99 ) )
F_138 ( V_99 ) ;
else
F_139 ( V_99 ) ;
}
static int F_140 ( struct V_189 * V_96 , unsigned int V_224 ,
unsigned int V_306 , unsigned int V_307 ,
unsigned int V_229 , unsigned int V_231 )
{
unsigned long V_114 = V_224 * sizeof( * V_96 -> V_203 ) +
V_306 * sizeof( * V_96 -> V_228 ) + V_307 * sizeof( * V_96 -> V_230 ) ;
V_96 -> V_203 = F_133 ( V_114 ) ;
if ( ! V_96 -> V_203 )
return - V_308 ;
V_96 -> V_230 = (union V_199 * ) & V_96 -> V_203 [ V_224 ] ;
V_96 -> V_228 = (union V_191 * ) & V_96 -> V_230 [ V_307 ] ;
V_96 -> V_224 = V_224 ;
V_96 -> V_307 = V_307 ;
V_96 -> V_231 = V_231 ;
V_96 -> V_201 = NULL ;
V_96 -> V_306 = V_306 ;
V_96 -> V_229 = V_229 ;
V_96 -> V_196 = NULL ;
V_96 -> V_202 = V_96 -> V_197 = 0 ;
F_141 ( & V_96 -> V_204 , 0 ) ;
F_142 ( & V_96 -> V_200 ) ;
F_142 ( & V_96 -> V_194 ) ;
if ( V_307 ) {
while ( -- V_307 )
V_96 -> V_230 [ V_307 - 1 ] . V_195 = & V_96 -> V_230 [ V_307 ] ;
V_96 -> V_201 = V_96 -> V_230 ;
}
if ( V_306 ) {
while ( -- V_306 )
V_96 -> V_228 [ V_306 - 1 ] . V_195 = & V_96 -> V_228 [ V_306 ] ;
V_96 -> V_196 = V_96 -> V_228 ;
}
return 0 ;
}
static void F_143 ( struct V_189 * V_96 )
{
F_136 ( V_96 -> V_203 ) ;
}
static inline void F_144 ( struct V_3 * V_309 )
{
F_145 ( & V_285 ) ;
F_6 ( & V_309 -> V_310 , & V_310 ) ;
F_146 ( & V_285 ) ;
}
static inline void F_147 ( struct V_3 * V_309 )
{
F_145 ( & V_285 ) ;
F_10 ( & V_309 -> V_310 ) ;
F_146 ( & V_285 ) ;
}
int F_148 ( struct V_3 * V_3 )
{
struct V_1 * V_20 = & V_3 -> V_2 ;
int V_306 , V_311 ;
struct V_215 * V_96 ;
struct V_127 V_312 , V_127 ;
struct V_129 V_129 ;
unsigned int V_313 ;
V_96 = F_134 ( sizeof( * V_96 ) , V_221 ) ;
if ( ! V_96 )
return - V_308 ;
V_311 = - V_64 ;
if ( V_20 -> V_314 ( V_20 , V_144 , & V_96 -> V_315 ) < 0 ||
V_20 -> V_314 ( V_20 , V_140 , & V_96 -> V_316 ) < 0 ||
V_20 -> V_314 ( V_20 , V_153 , & V_313 ) < 0 ||
V_20 -> V_314 ( V_20 , V_154 , & V_129 ) < 0 ||
V_20 -> V_314 ( V_20 , V_145 , & V_127 ) < 0 ||
V_20 -> V_314 ( V_20 , V_152 , & V_312 ) < 0 )
goto V_317;
V_311 = - V_308 ;
F_131 ( V_20 ) = F_149 ( V_313 ) ;
if ( ! F_131 ( V_20 ) )
goto V_317;
V_306 = F_21 ( V_127 . V_146 / 2 , V_318 ) ;
V_311 = F_140 ( & V_96 -> V_190 , V_127 . V_146 , V_306 ,
V_312 . V_146 , V_319 , V_312 . V_151 ) ;
if ( V_311 )
goto V_320;
V_96 -> V_156 = V_129 . V_156 ;
V_96 -> V_321 = V_129 . V_114 ;
F_150 ( & V_96 -> V_217 , F_64 ) ;
F_142 ( & V_96 -> V_218 ) ;
F_151 ( & V_96 -> V_322 ) ;
V_96 -> V_20 = V_20 ;
F_50 ( V_20 ) = V_96 ;
V_20 -> V_186 = F_117 ;
V_20 -> V_187 = F_124 ;
if ( F_152 ( & V_310 ) )
F_153 ( & V_323 ) ;
V_96 -> V_222 = F_66 ( sizeof( struct V_206 ) , V_221 ) ;
V_96 -> V_223 = 0 ;
F_144 ( V_3 ) ;
return 0 ;
V_320:
F_154 ( F_131 ( V_20 ) ) ;
F_131 ( V_20 ) = NULL ;
V_317:
F_139 ( V_96 ) ;
return V_311 ;
}
void F_155 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
struct V_215 * V_96 = F_50 ( V_2 ) ;
F_147 ( V_3 ) ;
if ( F_152 ( & V_310 ) )
F_156 ( & V_323 ) ;
F_143 ( & V_96 -> V_190 ) ;
F_50 ( V_2 ) = NULL ;
F_154 ( F_131 ( V_2 ) ) ;
F_131 ( V_2 ) = NULL ;
if ( V_96 -> V_222 )
F_118 ( V_96 -> V_222 ) ;
F_139 ( V_96 ) ;
}
static inline void F_157 ( struct V_1 * V_2 )
{
static int V_324 ;
F_5 ( & V_8 ) ;
snprintf ( V_2 -> V_60 , sizeof( V_2 -> V_60 ) , L_21 , V_324 ++ ) ;
F_6 ( & V_2 -> V_325 , & V_325 ) ;
F_8 ( & V_8 ) ;
}
static inline void F_158 ( struct V_1 * V_2 )
{
F_5 ( & V_8 ) ;
F_10 ( & V_2 -> V_325 ) ;
F_8 ( & V_8 ) ;
}
static inline int F_159 ( struct V_3 * V_3 )
{
int type = 0 ;
switch ( V_3 -> V_51 . V_326 ) {
case V_327 :
type = V_225 ;
break;
case V_328 :
case V_329 :
type = V_330 ;
break;
case V_331 :
type = V_332 ;
break;
}
return type ;
}
void T_6 F_160 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
F_151 ( & V_2 -> V_325 ) ;
F_48 ( V_2 ) ;
V_2 -> V_284 = V_333 ;
V_2 -> V_314 = F_40 ;
V_2 -> type = F_159 ( V_3 ) ;
F_157 ( V_2 ) ;
}
void T_7 F_161 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
V_2 -> V_186 = NULL ;
V_2 -> V_187 = NULL ;
F_158 ( V_2 ) ;
}
void T_8 F_162 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_279 ; ++ V_17 )
V_280 [ V_17 ] = F_115 ;
F_116 ( V_334 , F_79 ) ;
F_116 ( V_335 , F_82 ) ;
F_116 ( V_336 , F_83 ) ;
F_116 ( V_337 , F_88 ) ;
F_116 ( V_338 , F_88 ) ;
F_116 ( V_249 , F_92 ) ;
F_116 ( V_339 , F_90 ) ;
F_116 ( V_340 , F_90 ) ;
F_116 ( V_261 , F_90 ) ;
F_116 ( V_341 , F_90 ) ;
F_116 ( V_342 , F_90 ) ;
F_116 ( V_343 , F_90 ) ;
F_116 ( V_344 , F_90 ) ;
F_116 ( V_242 , F_84 ) ;
F_116 ( V_345 , F_90 ) ;
F_116 ( V_346 , F_90 ) ;
F_116 ( V_347 , F_100 ) ;
F_116 ( V_263 , F_102 ) ;
F_116 ( V_348 , F_90 ) ;
F_116 ( V_349 , F_90 ) ;
F_116 ( V_350 , F_111 ) ;
F_116 ( V_351 , F_90 ) ;
F_116 ( V_352 , F_103 ) ;
F_116 ( V_353 , F_90 ) ;
F_116 ( V_354 , F_90 ) ;
F_116 ( V_355 , F_90 ) ;
}
