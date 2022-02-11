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
struct V_14 * V_18 = V_3 -> V_12 [ V_17 ] ;
if ( ! memcmp ( V_18 -> V_19 , V_15 , V_20 ) ) {
F_16 () ;
if ( V_16 && V_16 != V_21 ) {
V_18 = F_17 ( V_18 , F_18 ( V_22 ) , V_16 ) ;
} else if ( F_19 ( V_18 ) ) {
struct V_14 * V_23 ;
while ( ( V_23 =
F_20 ( V_18 ) ) )
V_18 = V_23 ;
}
F_21 () ;
return V_18 ;
}
}
return NULL ;
}
static int F_22 ( struct V_3 * V_3 , unsigned int V_24 ,
void * V_25 )
{
int V_17 ;
int V_26 = 0 ;
unsigned int V_27 = 0 ;
struct V_28 * V_29 = V_25 ;
switch ( V_24 ) {
case V_30 :
V_29 -> V_31 = V_3 -> V_31 ;
V_29 -> V_32 = F_23 ( V_3 , V_33 ) ;
V_29 -> V_34 = F_23 ( V_3 , V_35 ) ;
V_29 -> V_36 = F_23 ( V_3 , V_37 ) ;
V_27 = F_23 ( V_3 , V_38 ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ , V_27 >>= 8 )
V_29 -> V_39 [ V_17 ] = V_27 & 0xFF ;
V_27 = F_23 ( V_3 , V_40 ) ;
V_29 -> V_41 =
V_29 -> V_42 = F_24 ( ( V_27 >> V_43 ) & V_44 ,
( V_27 >> V_45 ) & V_46 ) ;
V_27 = F_24 ( V_3 -> V_47 . V_48 . V_49 ,
F_23 ( V_3 , V_50 ) >> 17 ) ;
V_29 -> V_41 = F_24 ( V_27 , V_29 -> V_41 ) ;
V_27 = F_23 ( V_3 , V_51 ) ;
if ( ( V_27 >> V_52 ) != 0x3f60 ) {
V_27 &= ( V_53 << V_54 ) ;
V_27 |= F_25 ( 0x3f60 ) ;
F_26 ( L_1 ,
V_3 -> V_55 , V_27 ) ;
F_27 ( V_3 , V_51 , V_27 ) ;
}
V_27 = F_24 ( V_3 -> V_47 . V_48 . V_56 ,
( ( F_23 ( V_3 , V_51 ) ) >>
V_52 ) & V_57 ) ;
V_29 -> V_42 = F_24 ( V_27 , V_29 -> V_42 ) ;
break;
case V_58 :
F_27 ( V_3 , V_37 , V_29 -> V_36 ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ )
V_27 |= ( V_29 -> V_39 [ V_17 ] & 0xF ) << ( 8 * V_17 ) ;
if ( V_27 && ( V_27 != F_23 ( V_3 , V_38 ) ) ) {
F_26 ( L_2 ,
V_3 -> V_55 , V_27 , V_29 -> V_39 [ 0 ] ,
V_29 -> V_39 [ 1 ] , V_29 -> V_39 [ 2 ] ,
V_29 -> V_39 [ 3 ] ) ;
F_27 ( V_3 , V_38 , V_27 ) ;
}
break;
default:
V_26 = - V_59 ;
}
return V_26 ;
}
static int F_28 ( struct V_3 * V_3 , unsigned int V_24 , void * V_25 )
{
int V_26 = 0 ;
switch ( V_24 ) {
case V_60 : {
struct V_61 * V_62 = V_25 ;
struct V_63 * V_31 = V_3 -> V_31 ;
V_62 -> V_64 = F_29 ( V_31 , 2 ) ;
V_62 -> V_65 = F_30 ( V_31 , 2 ) ;
V_62 -> V_66 =
F_23 ( V_3 , V_67 ) ;
V_62 -> V_68 = F_23 ( V_3 , V_69 ) ;
V_62 -> V_70 =
F_23 ( V_3 , V_71 ) ;
V_62 -> V_72 = F_23 ( V_3 , V_73 ) ;
V_62 -> V_74 = F_23 ( V_3 , V_75 ) ;
V_62 -> V_76 = F_23 ( V_3 , V_77 ) ;
V_62 -> V_78 = V_3 -> V_79 + V_80 ;
V_62 -> V_31 = V_31 ;
break;
}
case V_81 : {
unsigned long V_82 ;
struct V_83 * V_62 = V_25 ;
F_31 ( & V_3 -> V_84 . V_85 , V_82 ) ;
V_26 = F_32 ( V_3 , V_62 -> V_86 , V_62 -> V_87 ,
V_62 -> V_88 ) ;
F_33 ( & V_3 -> V_84 . V_85 , V_82 ) ;
break;
}
case V_89 : {
struct V_90 * V_91 = V_25 ;
struct V_92 * V_93 ;
if ( ( V_91 -> V_94 & 7 ) || ( V_91 -> V_95 & 7 ) )
return - V_96 ;
if ( V_91 -> V_97 == V_98 )
V_93 = & V_3 -> V_99 ;
else if ( V_91 -> V_97 == V_100 )
V_93 = & V_3 -> V_101 ;
else if ( V_91 -> V_97 == V_102 )
V_93 = & V_3 -> V_103 ;
else
return - V_96 ;
V_26 =
F_34 ( V_93 , V_91 -> V_94 / 8 , V_91 -> V_95 / 8 ,
( V_104 * ) V_91 -> V_105 ) ;
if ( V_26 )
return V_26 ;
break;
}
case V_106 : {
struct V_107 * V_62 = V_25 ;
F_35 ( & V_3 -> V_84 . V_85 ) ;
V_26 =
F_36 ( V_3 , V_62 -> V_86 ,
V_62 -> V_108 , V_62 -> V_109 ,
V_110 ,
V_62 -> V_111 , V_62 -> V_88 ,
V_62 -> V_112 ) ;
F_37 ( & V_3 -> V_84 . V_85 ) ;
break;
}
case V_113 :
F_35 ( & V_3 -> V_84 . V_85 ) ;
V_26 = F_38 ( V_3 , * ( unsigned int * ) V_25 ) ;
F_37 ( & V_3 -> V_84 . V_85 ) ;
break;
case V_114 : {
struct V_115 * V_62 = V_25 ;
F_35 ( & V_3 -> V_84 . V_85 ) ;
V_26 = F_39 ( V_3 , V_116 , 0 ,
V_117 ,
V_110 ,
V_62 -> V_108 , V_62 -> V_109 ,
V_118 , 1 , 0 ) ;
F_37 ( & V_3 -> V_84 . V_85 ) ;
break;
}
case V_119 : {
F_40 ( & V_3 -> V_120 ) ;
F_41 ( V_3 , (struct V_121 * ) V_25 ) ;
F_42 ( & V_3 -> V_120 ) ;
break;
}
default:
V_26 = - V_59 ;
}
return V_26 ;
}
static int F_43 ( struct V_1 * V_2 , unsigned int V_24 , void * V_25 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_134 * V_48 = & V_3 -> V_47 . V_48 ;
int V_17 ;
switch ( V_24 ) {
case V_135 :
* ( unsigned int * ) V_25 = V_136 ;
break;
case V_137 :
* ( unsigned int * ) V_25 = V_138 ;
break;
case V_139 :
* ( unsigned int * ) V_25 = 1 << 20 ;
break;
case V_140 :
V_123 = V_25 ;
V_123 -> V_141 = F_44 ( & V_3 -> V_142 ) -
V_3 -> V_47 . V_142 . V_143 -
V_3 -> V_47 . V_142 . V_144 - V_3 -> V_47 . V_142 . V_145 ;
V_123 -> V_146 = 0 ;
break;
case V_147 :
V_123 = V_25 ;
V_123 -> V_141 = V_3 -> V_47 . V_142 . V_145 ;
V_123 -> V_146 = F_44 ( & V_3 -> V_142 ) - V_123 -> V_141 -
V_3 -> V_47 . V_142 . V_144 - V_3 -> V_47 . V_142 . V_143 ;
break;
case V_148 :
* ( unsigned int * ) V_25 = 2048 ;
break;
case V_149 :
V_125 = V_25 ;
V_125 -> V_109 = V_150 ;
V_125 -> V_151 = V_3 -> V_47 . V_151 ;
break;
case V_152 :
V_127 = V_25 ;
V_127 -> V_18 = F_14 ( V_3 , V_127 -> V_153 ,
V_127 -> V_154 &
V_21 ) ;
break;
case V_155 :
V_129 = V_25 ;
V_129 -> V_32 = F_23 ( V_3 , V_156 ) ;
V_129 -> V_34 = F_23 ( V_3 , V_157 ) ;
V_129 -> V_158 = F_23 ( V_3 , V_159 ) ;
break;
case V_160 :
V_131 = V_25 ;
V_131 -> V_161 = V_3 -> V_47 . V_161 ;
F_15 (adapter, i)
V_131 -> V_162 [ V_17 ] = V_3 -> V_12 [ V_17 ] ;
break;
case V_30 :
case V_58 :
if ( ! F_45 ( V_3 ) )
return - V_163 ;
return F_22 ( V_3 , V_24 , V_25 ) ;
case V_60 :
case V_81 :
case V_106 :
case V_113 :
case V_114 :
case V_89 :
case V_119 :
if ( ! F_45 ( V_3 ) )
return - V_163 ;
return F_28 ( V_3 , V_24 , V_25 ) ;
case V_164 :
V_133 = V_25 ;
V_133 -> V_165 = V_48 -> V_56 ;
V_133 -> V_141 = V_48 -> V_166 ;
break;
case V_167 : {
struct V_168 * V_169 = V_25 ;
struct V_170 * V_171 = F_46 ( V_169 -> V_18 ) ;
V_169 -> V_172 = V_171 -> V_168 ;
break;
}
case V_173 : {
struct V_174 * V_175 = V_25 ;
F_40 ( & V_3 -> V_120 ) ;
F_47 ( V_3 , & V_175 -> V_176 ) ;
F_48 ( V_3 , & V_175 -> V_177 ) ;
F_42 ( & V_3 -> V_120 ) ;
break;
}
default:
return - V_59 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_18 , struct V_178 * * V_179 ,
int V_180 )
{
while ( V_180 -- )
F_50 ( V_179 [ V_180 ] ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_18 , struct V_181 * V_182 )
{
}
void F_52 ( struct V_1 * V_18 )
{
V_18 -> V_183 = F_49 ;
V_18 -> V_184 = F_51 ;
}
void * F_53 ( struct V_1 * V_2 , int V_185 )
{
struct V_186 * V_91 = & ( F_54 ( V_2 ) ) -> V_187 ;
union V_188 * V_169 = F_55 ( V_91 , V_185 ) ;
void * V_189 = V_169 -> V_190 . V_189 ;
F_56 ( & V_91 -> V_191 ) ;
V_169 -> V_192 = V_91 -> V_193 ;
V_91 -> V_193 = V_169 ;
V_91 -> V_194 -- ;
F_57 ( & V_91 -> V_191 ) ;
return V_189 ;
}
void F_58 ( struct V_1 * V_2 , int V_195 )
{
struct V_186 * V_91 = & ( F_54 ( V_2 ) ) -> V_187 ;
union V_196 * V_169 = F_59 ( V_91 , V_195 ) ;
F_56 ( & V_91 -> V_197 ) ;
V_169 -> V_192 = V_91 -> V_198 ;
V_91 -> V_198 = V_169 ;
V_91 -> V_199 -- ;
F_57 ( & V_91 -> V_197 ) ;
}
void F_60 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_189 , unsigned int V_123 )
{
struct V_186 * V_91 = & ( F_54 ( V_2 ) ) -> V_187 ;
V_91 -> V_200 [ V_123 ] . V_7 = V_7 ;
V_91 -> V_200 [ V_123 ] . V_189 = V_189 ;
F_61 ( & V_91 -> V_201 ) ;
}
static inline void F_62 ( struct V_178 * V_202 , unsigned int V_123 )
{
struct V_203 * V_24 ;
V_202 -> V_204 = V_205 ;
V_24 = (struct V_203 * ) F_63 ( V_202 , sizeof( * V_24 ) ) ;
V_24 -> V_206 . V_207 = F_64 ( F_65 ( V_208 ) ) ;
F_66 ( V_24 ) = F_64 ( F_67 ( V_209 , V_123 ) ) ;
}
static void F_68 ( struct V_210 * V_211 )
{
struct V_212 * V_213 = F_69 ( V_211 , struct V_212 ,
V_214 ) ;
struct V_178 * V_202 ;
struct V_1 * V_2 = V_213 -> V_18 ;
F_56 ( & V_213 -> V_215 ) ;
while ( V_213 -> V_216 ) {
struct V_217 * V_169 = V_213 -> V_216 ;
V_213 -> V_216 = V_169 -> V_189 ;
F_57 ( & V_213 -> V_215 ) ;
V_202 = F_70 ( sizeof( struct V_203 ) ,
V_218 ) ;
if ( ! V_202 )
V_202 = V_213 -> V_219 ;
if ( ! V_202 ) {
F_56 ( & V_213 -> V_215 ) ;
V_169 -> V_189 = ( void * ) V_213 -> V_216 ;
V_213 -> V_216 = V_169 ;
break;
}
F_62 ( V_202 , V_169 - V_213 -> V_187 . V_200 ) ;
F_71 ( V_2 , V_202 ) ;
V_169 -> V_189 = NULL ;
if ( V_202 == V_213 -> V_219 )
V_213 -> V_219 =
F_70 ( sizeof( struct V_203 ) ,
V_218 ) ;
F_56 ( & V_213 -> V_215 ) ;
}
V_213 -> V_220 = ( V_213 -> V_216 == NULL ) ? 0 : 1 ;
F_57 ( & V_213 -> V_215 ) ;
if ( ! V_213 -> V_219 )
V_213 -> V_219 =
F_70 ( sizeof( struct V_203 ) ,
V_218 ) ;
}
void F_72 ( struct V_1 * V_2 , unsigned int V_123 )
{
struct V_212 * V_213 = F_54 ( V_2 ) ;
struct V_217 * V_169 = & V_213 -> V_187 . V_200 [ V_123 ] ;
F_56 ( & V_213 -> V_215 ) ;
V_169 -> V_189 = ( void * ) V_213 -> V_216 ;
V_169 -> V_7 = NULL ;
V_213 -> V_216 = V_169 ;
if ( ! V_169 -> V_189 || V_213 -> V_220 )
F_73 ( & V_213 -> V_214 ) ;
F_57 ( & V_213 -> V_215 ) ;
}
void F_74 ( struct V_1 * V_2 , void * V_189 , unsigned int V_123 )
{
struct V_186 * V_91 = & ( F_54 ( V_2 ) ) -> V_187 ;
F_75 ( V_123 >= V_91 -> V_221 ) ;
if ( V_2 -> type == V_222 )
( void ) F_76 ( & V_91 -> V_200 [ V_123 ] . V_189 , V_189 , NULL ) ;
else {
struct V_178 * V_202 ;
V_202 = F_70 ( sizeof( struct V_203 ) , V_223 ) ;
if ( F_77 ( V_202 ) ) {
F_62 ( V_202 , V_123 ) ;
F_71 ( V_2 , V_202 ) ;
V_91 -> V_200 [ V_123 ] . V_189 = NULL ;
} else
F_72 ( V_2 , V_123 ) ;
}
F_78 ( & V_91 -> V_201 ) ;
}
int F_79 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_189 )
{
int V_185 = - 1 ;
struct V_186 * V_91 = & ( F_54 ( V_2 ) ) -> V_187 ;
F_56 ( & V_91 -> V_191 ) ;
if ( V_91 -> V_193 &&
V_91 -> V_194 + F_80 ( & V_91 -> V_201 ) + V_224 <=
V_91 -> V_221 ) {
union V_188 * V_169 = V_91 -> V_193 ;
V_185 = ( V_169 - V_91 -> V_225 ) + V_91 -> V_226 ;
V_91 -> V_193 = V_169 -> V_192 ;
V_169 -> V_190 . V_189 = V_189 ;
V_169 -> V_190 . V_7 = V_7 ;
V_91 -> V_194 ++ ;
}
F_57 ( & V_91 -> V_191 ) ;
return V_185 ;
}
int F_81 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_189 )
{
int V_195 = - 1 ;
struct V_186 * V_91 = & ( F_54 ( V_2 ) ) -> V_187 ;
F_56 ( & V_91 -> V_197 ) ;
if ( V_91 -> V_198 ) {
union V_196 * V_169 = V_91 -> V_198 ;
V_195 = ( V_169 - V_91 -> V_227 ) + V_91 -> V_228 ;
V_91 -> V_198 = V_169 -> V_192 ;
V_169 -> V_190 . V_189 = V_189 ;
V_169 -> V_190 . V_7 = V_7 ;
V_91 -> V_199 ++ ;
}
F_57 ( & V_91 -> V_197 ) ;
return V_195 ;
}
struct V_1 * F_82 ( struct V_14 * V_18 )
{
const struct V_170 * V_171 = F_46 ( V_18 ) ;
return (struct V_1 * ) V_171 -> V_3 ;
}
static int F_83 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_229 * V_230 = F_84 ( V_202 ) ;
if ( V_230 -> V_231 != V_232 )
F_85 ( L_3 ,
V_230 -> V_231 , F_86 ( V_230 ) ) ;
return V_233 ;
}
static int F_87 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_234 * V_230 = F_84 ( V_202 ) ;
if ( V_230 -> V_231 != V_232 )
F_85 ( L_4 ,
V_230 -> V_231 , F_86 ( V_230 ) ) ;
return V_233 ;
}
static int F_88 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_235 * V_230 = F_84 ( V_202 ) ;
if ( V_230 -> V_231 != V_232 )
F_85 ( L_5 ,
V_230 -> V_231 , F_86 ( V_230 ) ) ;
return V_233 ;
}
static int F_89 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_236 * V_230 = F_84 ( V_202 ) ;
unsigned int V_185 = F_90 ( F_91 ( V_230 -> V_185 ) ) ;
struct V_217 * V_190 ;
V_190 = F_92 ( & ( F_54 ( V_18 ) ) -> V_187 , V_185 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 &&
V_190 -> V_7 -> V_237 &&
V_190 -> V_7 -> V_237 [ V_238 ] ) {
return V_190 -> V_7 -> V_237 [ V_238 ] ( V_18 , V_202 ,
V_190 ->
V_189 ) ;
} else {
F_85 ( L_6 ,
V_18 -> V_55 , V_238 ) ;
return V_233 | V_239 ;
}
}
static int F_93 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
union V_240 * V_169 = F_84 ( V_202 ) ;
unsigned int V_195 = F_90 ( F_91 ( V_169 -> V_240 ) ) ;
struct V_217 * V_190 ;
V_190 = F_94 ( & ( F_54 ( V_18 ) ) -> V_187 , V_195 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_237 &&
V_190 -> V_7 -> V_237 [ V_169 -> V_241 ] ) {
return V_190 -> V_7 -> V_237 [ V_169 -> V_241 ] ( V_18 , V_202 ,
V_190 -> V_189 ) ;
} else {
F_85 ( L_6 ,
V_18 -> V_55 , V_169 -> V_241 ) ;
return V_233 | V_239 ;
}
}
static int F_95 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
union V_240 * V_169 = F_84 ( V_202 ) ;
unsigned int V_242 = F_90 ( F_91 ( V_169 -> V_240 ) ) ;
struct V_217 * V_190 ;
V_190 = F_96 ( & ( F_54 ( V_18 ) ) -> V_187 , V_242 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_237 &&
V_190 -> V_7 -> V_237 [ V_169 -> V_241 ] ) {
return V_190 -> V_7 -> V_237 [ V_169 -> V_241 ]
( V_18 , V_202 , V_190 -> V_189 ) ;
} else {
F_85 ( L_6 ,
V_18 -> V_55 , V_169 -> V_241 ) ;
return V_233 | V_239 ;
}
}
static int F_97 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_243 * V_24 = F_84 ( V_202 ) ;
unsigned int V_195 = F_98 ( F_91 ( V_24 -> V_244 ) ) ;
struct V_186 * V_91 = & ( F_54 ( V_18 ) ) -> V_187 ;
struct V_217 * V_190 ;
unsigned int V_123 = F_86 ( V_24 ) ;
if ( F_99 ( V_123 >= V_91 -> V_221 ) ) {
F_100 ( L_7 ,
V_18 -> V_55 , V_123 ) ;
F_101 ( F_2 ( V_18 ) ) ;
return V_233 ;
}
V_190 = F_94 ( V_91 , V_195 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_237 &&
V_190 -> V_7 -> V_237 [ V_245 ] ) {
return V_190 -> V_7 -> V_237 [ V_245 ]
( V_18 , V_202 , V_190 -> V_189 ) ;
} else {
F_85 ( L_6 ,
V_18 -> V_55 , V_245 ) ;
return V_233 | V_239 ;
}
}
static struct V_178 * F_102 ( struct V_178 * V_202 , T_2 V_95 ,
T_3 V_246 )
{
if ( F_77 ( ! F_103 ( V_202 ) ) ) {
F_75 ( V_202 -> V_95 < V_95 ) ;
F_104 ( V_202 , V_95 ) ;
F_105 ( V_202 ) ;
} else {
V_202 = F_70 ( V_95 , V_246 ) ;
if ( V_202 )
F_63 ( V_202 , V_95 ) ;
}
return V_202 ;
}
static int F_106 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
union V_240 * V_169 = F_84 ( V_202 ) ;
unsigned int V_242 = F_90 ( F_91 ( V_169 -> V_240 ) ) ;
struct V_217 * V_190 ;
V_190 = F_96 ( & ( F_54 ( V_18 ) ) -> V_187 , V_242 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_237 &&
V_190 -> V_7 -> V_237 [ V_169 -> V_241 ] ) {
return V_190 -> V_7 -> V_237 [ V_169 -> V_241 ]
( V_18 , V_202 , V_190 -> V_189 ) ;
} else {
struct V_247 * V_24 = F_84 ( V_202 ) ;
struct V_248 * V_230 ;
struct V_178 * V_249 ;
unsigned int V_123 = F_86 ( V_24 ) ;
T_4 V_250 = V_24 -> V_231 ;
if ( V_24 -> V_231 == V_251 ||
V_24 -> V_231 == V_252 )
goto V_253;
V_249 = F_102 ( V_202 ,
sizeof( struct
V_248 ) ,
V_223 ) ;
if ( ! V_249 ) {
F_100 ( L_8 ) ;
goto V_253;
}
V_249 -> V_204 = V_254 ;
F_63 ( V_249 , sizeof( struct V_248 ) ) ;
V_230 = F_84 ( V_249 ) ;
V_230 -> V_206 . V_207 =
F_64 ( F_65 ( V_255 ) ) ;
V_230 -> V_206 . V_256 = F_64 ( F_107 ( V_123 ) ) ;
F_66 ( V_230 ) = F_64 ( F_67 ( V_257 , V_123 ) ) ;
V_230 -> V_250 = V_250 ;
F_71 ( V_18 , V_249 ) ;
V_253:
return V_233 ;
}
}
static int F_108 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_258 * V_24 = F_84 ( V_202 ) ;
unsigned int V_185 = F_98 ( F_91 ( V_24 -> V_244 ) ) ;
struct V_186 * V_91 = & ( F_54 ( V_18 ) ) -> V_187 ;
struct V_217 * V_190 ;
unsigned int V_123 = F_86 ( V_24 ) ;
if ( F_99 ( V_123 >= V_91 -> V_221 ) ) {
F_100 ( L_9 ,
V_18 -> V_55 , V_123 ) ;
F_101 ( F_2 ( V_18 ) ) ;
return V_233 ;
}
V_190 = F_92 ( V_91 , V_185 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_237 &&
V_190 -> V_7 -> V_237 [ V_259 ] ) {
return V_190 -> V_7 -> V_237 [ V_259 ]
( V_18 , V_202 , V_190 -> V_189 ) ;
} else {
F_85 ( L_6 ,
V_18 -> V_55 , V_259 ) ;
return V_233 | V_239 ;
}
}
static int F_109 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_260 * V_169 = F_84 ( V_202 ) ;
V_202 -> V_261 = F_18 ( 0xffff ) ;
V_202 -> V_18 = V_18 -> V_262 ;
F_110 ( V_202 , sizeof( * V_169 ) ) ;
F_111 ( V_202 ) ;
F_112 ( V_202 ) ;
return 0 ;
}
static inline T_1 F_113 ( struct V_178 * V_202 )
{
return F_91 ( ( V_263 V_264 ) V_202 -> V_204 ) >> 8 & 0xfffff ;
}
static inline T_1 F_114 ( struct V_178 * V_202 )
{
return F_115 ( F_91 ( ( V_263 V_264 ) V_202 -> V_265 ) ) ;
}
static int F_116 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
unsigned int V_242 = F_113 ( V_202 ) ;
unsigned int V_241 = F_114 ( V_202 ) ;
struct V_217 * V_190 ;
V_190 = F_96 ( & ( F_54 ( V_18 ) ) -> V_187 , V_242 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_237 &&
V_190 -> V_7 -> V_237 [ V_241 ] ) {
return V_190 -> V_7 -> V_237 [ V_241 ] ( V_18 , V_202 ,
V_190 -> V_189 ) ;
} else {
F_85 ( L_6 ,
V_18 -> V_55 , V_241 ) ;
return V_233 | V_239 ;
}
}
static int F_117 ( struct V_266 * V_267 , unsigned long V_11 ,
void * V_189 )
{
switch ( V_11 ) {
case ( V_268 ) : {
F_118 ( (struct V_181 * ) V_189 ) ;
break;
}
case ( V_269 ) : {
struct V_270 * V_271 = V_189 ;
F_119 ( V_271 -> V_272 , V_271 -> V_273 , V_271 -> V_182 ,
V_271 -> V_274 ) ;
F_118 ( V_271 -> V_182 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_120 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
F_85 ( L_10 , V_18 -> V_55 , * V_202 -> V_25 ) ;
return V_233 | V_239 ;
}
void F_121 ( unsigned int V_241 , T_5 V_275 )
{
if ( V_241 < V_276 )
V_277 [ V_241 ] = V_275 ? V_275 : F_120 ;
else
F_85 ( L_11 ,
V_241 ) ;
}
static int F_122 ( struct V_1 * V_18 , struct V_178 * * V_179 , int V_180 )
{
while ( V_180 -- ) {
struct V_178 * V_202 = * V_179 ++ ;
unsigned int V_241 = F_114 ( V_202 ) ;
int V_26 = V_277 [ V_241 ] ( V_18, V_202 ) ;
#if V_278
if ( V_26 & V_279 ) {
union V_240 * V_169 = F_84 ( V_202 ) ;
F_85 ( L_12 ,
V_18 -> V_55 , V_241 , F_90 ( F_91 ( V_169 -> V_240 ) ) ) ;
}
#endif
if ( V_26 & V_233 )
F_123 ( V_202 ) ;
}
return 0 ;
}
int F_71 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
int V_280 ;
F_124 () ;
V_280 = V_18 -> V_281 ( V_18 , V_202 ) ;
F_125 () ;
return V_280 ;
}
static int F_126 ( struct V_14 * V_18 )
{
struct V_3 * V_3 ;
int V_17 ;
F_127 ( & V_282 ) ;
F_7 (adapter, &adapter_list, adapter_list) {
F_15 (adapter, i) {
if ( V_18 == V_3 -> V_12 [ V_17 ] ) {
F_128 ( & V_282 ) ;
return 1 ;
}
}
}
F_128 ( & V_282 ) ;
return 0 ;
}
static void F_118 ( struct V_181 * V_182 )
{
struct V_14 * V_18 ;
if ( ! V_182 )
return;
V_18 = V_182 -> V_18 ;
if ( V_18 && ( F_126 ( V_18 ) ) ) {
struct V_1 * V_2 = F_82 ( V_18 ) ;
F_75 ( ! V_2 ) ;
F_129 ( V_2 , V_182 ) ;
}
}
static void F_130 ( struct V_1 * V_2 , T_1 V_123 , struct V_283 * V_175 )
{
struct V_178 * V_202 ;
struct V_284 * V_24 ;
V_202 = F_70 ( sizeof( * V_24 ) , V_223 ) ;
if ( ! V_202 ) {
F_85 ( L_13 , V_285 ) ;
return;
}
V_202 -> V_204 = V_286 ;
V_24 = (struct V_284 * ) F_131 ( V_202 , sizeof( * V_24 ) ) ;
V_24 -> V_206 . V_207 = F_64 ( F_65 ( V_208 ) ) ;
F_66 ( V_24 ) = F_64 ( F_67 ( V_287 , V_123 ) ) ;
V_24 -> V_288 = 0 ;
V_24 -> V_289 = 0 ;
V_24 -> V_290 = F_18 ( V_291 ) ;
V_24 -> V_292 = F_132 ( F_133 ( V_293 ) ) ;
V_24 -> V_27 = F_132 ( F_133 ( V_175 -> V_294 ) ) ;
V_2 -> V_281 ( V_2 , V_202 ) ;
}
static void F_119 ( struct V_295 * V_272 , struct V_295 * V_273 ,
struct V_181 * V_182 ,
const void * V_274 )
{
struct V_14 * V_18 ;
struct V_186 * V_296 ;
struct V_1 * V_2 ;
T_1 V_123 ;
int V_297 ;
struct V_283 * V_175 ;
struct V_217 * V_298 ;
V_18 = V_182 -> V_18 ;
if ( ! F_126 ( V_18 ) )
return;
V_2 = F_82 ( V_18 ) ;
F_75 ( ! V_2 ) ;
V_175 = F_134 ( V_2 , V_273 , V_18 , V_274 ) ;
if ( ! V_175 ) {
F_85 ( L_14 , V_285 ) ;
return;
}
V_296 = & ( F_54 ( V_2 ) ) -> V_187 ;
for ( V_123 = 0 ; V_123 < V_296 -> V_221 ; V_123 ++ ) {
V_298 = F_96 ( V_296 , V_123 ) ;
F_75 ( ! V_298 ) ;
if ( V_298 && V_298 -> V_189 && V_298 -> V_7 && V_298 -> V_7 -> V_299 ) {
V_297 = V_298 -> V_7 -> V_299 ( V_298 -> V_189 , V_272 , V_273 , V_175 ) ;
if ( V_297 ) {
F_16 () ;
F_135 ( F_136 ( V_2 ) , V_175 ) ;
F_21 () ;
F_130 ( V_2 , V_123 , V_175 ) ;
}
}
}
F_137 ( V_2 , V_175 ) ;
}
void * F_138 ( unsigned long V_109 )
{
void * V_169 = F_139 ( V_109 , V_218 | V_300 ) ;
if ( ! V_169 )
V_169 = F_140 ( V_109 ) ;
return V_169 ;
}
void F_141 ( void * V_94 )
{
if ( F_142 ( V_94 ) )
F_143 ( V_94 ) ;
else
F_144 ( V_94 ) ;
}
static int F_145 ( struct V_186 * V_91 , unsigned int V_221 ,
unsigned int V_301 , unsigned int V_302 ,
unsigned int V_226 , unsigned int V_228 )
{
unsigned long V_109 = V_221 * sizeof( * V_91 -> V_200 ) +
V_301 * sizeof( * V_91 -> V_225 ) + V_302 * sizeof( * V_91 -> V_227 ) ;
V_91 -> V_200 = F_138 ( V_109 ) ;
if ( ! V_91 -> V_200 )
return - V_303 ;
V_91 -> V_227 = (union V_196 * ) & V_91 -> V_200 [ V_221 ] ;
V_91 -> V_225 = (union V_188 * ) & V_91 -> V_227 [ V_302 ] ;
V_91 -> V_221 = V_221 ;
V_91 -> V_302 = V_302 ;
V_91 -> V_228 = V_228 ;
V_91 -> V_198 = NULL ;
V_91 -> V_301 = V_301 ;
V_91 -> V_226 = V_226 ;
V_91 -> V_193 = NULL ;
V_91 -> V_199 = V_91 -> V_194 = 0 ;
F_146 ( & V_91 -> V_201 , 0 ) ;
F_147 ( & V_91 -> V_197 ) ;
F_147 ( & V_91 -> V_191 ) ;
if ( V_302 ) {
while ( -- V_302 )
V_91 -> V_227 [ V_302 - 1 ] . V_192 = & V_91 -> V_227 [ V_302 ] ;
V_91 -> V_198 = V_91 -> V_227 ;
}
if ( V_301 ) {
while ( -- V_301 )
V_91 -> V_225 [ V_301 - 1 ] . V_192 = & V_91 -> V_225 [ V_301 ] ;
V_91 -> V_193 = V_91 -> V_225 ;
}
return 0 ;
}
static void F_148 ( struct V_186 * V_91 )
{
F_141 ( V_91 -> V_200 ) ;
}
static inline void F_149 ( struct V_3 * V_304 )
{
F_150 ( & V_282 ) ;
F_6 ( & V_304 -> V_305 , & V_305 ) ;
F_151 ( & V_282 ) ;
}
static inline void F_152 ( struct V_3 * V_304 )
{
F_150 ( & V_282 ) ;
F_10 ( & V_304 -> V_305 ) ;
F_151 ( & V_282 ) ;
}
int F_153 ( struct V_3 * V_3 )
{
struct V_1 * V_18 = & V_3 -> V_2 ;
int V_301 , V_306 ;
struct V_212 * V_91 ;
struct V_122 V_307 , V_122 ;
struct V_124 V_124 ;
unsigned int V_308 ;
struct V_309 * V_310 ;
V_91 = F_139 ( sizeof( * V_91 ) , V_218 ) ;
if ( ! V_91 )
return - V_303 ;
V_306 = - V_59 ;
if ( V_18 -> V_311 ( V_18 , V_139 , & V_91 -> V_312 ) < 0 ||
V_18 -> V_311 ( V_18 , V_135 , & V_91 -> V_313 ) < 0 ||
V_18 -> V_311 ( V_18 , V_148 , & V_308 ) < 0 ||
V_18 -> V_311 ( V_18 , V_149 , & V_124 ) < 0 ||
V_18 -> V_311 ( V_18 , V_140 , & V_122 ) < 0 ||
V_18 -> V_311 ( V_18 , V_147 , & V_307 ) < 0 )
goto V_314;
V_306 = - V_303 ;
V_310 = F_154 ( V_308 ) ;
if ( ! V_310 )
goto V_314;
V_301 = F_24 ( V_122 . V_141 / 2 , V_315 ) ;
V_306 = F_145 ( & V_91 -> V_187 , V_122 . V_141 , V_301 ,
V_307 . V_141 , V_316 , V_307 . V_146 ) ;
if ( V_306 )
goto V_317;
V_91 -> V_151 = V_124 . V_151 ;
V_91 -> V_318 = V_124 . V_109 ;
F_155 ( & V_91 -> V_214 , F_68 ) ;
F_147 ( & V_91 -> V_215 ) ;
F_156 ( & V_91 -> V_319 ) ;
V_91 -> V_18 = V_18 ;
F_157 ( V_18 -> V_320 , V_310 ) ;
F_54 ( V_18 ) = V_91 ;
V_18 -> V_183 = F_122 ;
V_18 -> V_184 = F_129 ;
if ( F_158 ( & V_305 ) )
F_159 ( & V_321 ) ;
V_91 -> V_219 = F_70 ( sizeof( struct V_203 ) , V_218 ) ;
V_91 -> V_220 = 0 ;
F_149 ( V_3 ) ;
return 0 ;
V_317:
F_160 ( V_310 ) ;
V_314:
F_144 ( V_91 ) ;
return V_306 ;
}
static void F_161 ( struct V_322 * V_323 )
{
struct V_309 * V_324 = F_69 ( V_323 , struct V_309 , V_322 ) ;
F_160 ( V_324 ) ;
}
void F_162 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
struct V_212 * V_91 = F_54 ( V_2 ) ;
struct V_309 * V_324 ;
F_152 ( V_3 ) ;
if ( F_158 ( & V_305 ) )
F_163 ( & V_321 ) ;
F_148 ( & V_91 -> V_187 ) ;
F_54 ( V_2 ) = NULL ;
F_16 () ;
V_324 = F_136 ( V_2 ) ;
F_21 () ;
F_157 ( V_2 -> V_320 , NULL ) ;
F_164 ( & V_324 -> V_322 , F_161 ) ;
if ( V_91 -> V_219 )
F_123 ( V_91 -> V_219 ) ;
F_144 ( V_91 ) ;
}
static inline void F_165 ( struct V_1 * V_2 )
{
static int V_325 ;
F_5 ( & V_8 ) ;
snprintf ( V_2 -> V_55 , sizeof( V_2 -> V_55 ) , L_15 , V_325 ++ ) ;
F_6 ( & V_2 -> V_326 , & V_326 ) ;
F_8 ( & V_8 ) ;
}
static inline void F_166 ( struct V_1 * V_2 )
{
F_5 ( & V_8 ) ;
F_10 ( & V_2 -> V_326 ) ;
F_8 ( & V_8 ) ;
}
static inline int F_167 ( struct V_3 * V_3 )
{
int type = 0 ;
switch ( V_3 -> V_47 . V_327 ) {
case V_328 :
type = V_222 ;
break;
case V_329 :
case V_330 :
type = V_331 ;
break;
case V_332 :
type = V_333 ;
break;
}
return type ;
}
void F_168 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
F_156 ( & V_2 -> V_326 ) ;
F_52 ( V_2 ) ;
V_2 -> V_281 = V_334 ;
V_2 -> V_311 = F_43 ;
V_2 -> type = F_167 ( V_3 ) ;
F_165 ( V_2 ) ;
}
void F_169 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
V_2 -> V_183 = NULL ;
V_2 -> V_184 = NULL ;
F_166 ( V_2 ) ;
}
void T_6 F_170 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_276 ; ++ V_17 )
V_277 [ V_17 ] = F_120 ;
F_121 ( V_335 , F_83 ) ;
F_121 ( V_336 , F_87 ) ;
F_121 ( V_337 , F_88 ) ;
F_121 ( V_338 , F_93 ) ;
F_121 ( V_339 , F_93 ) ;
F_121 ( V_245 , F_97 ) ;
F_121 ( V_340 , F_95 ) ;
F_121 ( V_341 , F_95 ) ;
F_121 ( V_257 , F_95 ) ;
F_121 ( V_342 , F_95 ) ;
F_121 ( V_343 , F_95 ) ;
F_121 ( V_344 , F_95 ) ;
F_121 ( V_345 , F_95 ) ;
F_121 ( V_238 , F_89 ) ;
F_121 ( V_346 , F_95 ) ;
F_121 ( V_347 , F_95 ) ;
F_121 ( V_348 , F_106 ) ;
F_121 ( V_259 , F_108 ) ;
F_121 ( V_349 , F_95 ) ;
F_121 ( V_350 , F_95 ) ;
F_121 ( V_351 , F_116 ) ;
F_121 ( V_352 , F_95 ) ;
F_121 ( V_353 , F_109 ) ;
F_121 ( V_354 , F_95 ) ;
F_121 ( V_355 , F_95 ) ;
F_121 ( V_356 , F_95 ) ;
}
