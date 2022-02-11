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
if ( V_16 && V_16 != V_21 ) {
F_16 () ;
V_18 = F_17 ( V_18 , V_16 ) ;
F_18 () ;
} else if ( F_19 ( V_18 ) ) {
while ( V_18 -> V_22 )
V_18 = V_18 -> V_22 ;
}
return V_18 ;
}
}
return NULL ;
}
static int F_20 ( struct V_3 * V_3 , unsigned int V_23 ,
void * V_24 )
{
int V_17 ;
int V_25 = 0 ;
unsigned int V_26 = 0 ;
struct V_27 * V_28 = V_24 ;
switch ( V_23 ) {
case V_29 :
V_28 -> V_30 = V_3 -> V_30 ;
V_28 -> V_31 = F_21 ( V_3 , V_32 ) ;
V_28 -> V_33 = F_21 ( V_3 , V_34 ) ;
V_28 -> V_35 = F_21 ( V_3 , V_36 ) ;
V_26 = F_21 ( V_3 , V_37 ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ , V_26 >>= 8 )
V_28 -> V_38 [ V_17 ] = V_26 & 0xFF ;
V_26 = F_21 ( V_3 , V_39 ) ;
V_28 -> V_40 =
V_28 -> V_41 = F_22 ( ( V_26 >> V_42 ) & V_43 ,
( V_26 >> V_44 ) & V_45 ) ;
V_26 = F_22 ( V_3 -> V_46 . V_47 . V_48 ,
F_21 ( V_3 , V_49 ) >> 17 ) ;
V_28 -> V_40 = F_22 ( V_26 , V_28 -> V_40 ) ;
V_26 = F_21 ( V_3 , V_50 ) ;
if ( ( V_26 >> V_51 ) != 0x3f60 ) {
V_26 &= ( V_52 << V_53 ) ;
V_26 |= F_23 ( 0x3f60 ) ;
F_24 ( V_54
L_1 ,
V_3 -> V_55 , V_26 ) ;
F_25 ( V_3 , V_50 , V_26 ) ;
}
V_26 = F_22 ( V_3 -> V_46 . V_47 . V_56 ,
( ( F_21 ( V_3 , V_50 ) ) >>
V_51 ) & V_57 ) ;
V_28 -> V_41 = F_22 ( V_26 , V_28 -> V_41 ) ;
break;
case V_58 :
F_25 ( V_3 , V_36 , V_28 -> V_35 ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ )
V_26 |= ( V_28 -> V_38 [ V_17 ] & 0xF ) << ( 8 * V_17 ) ;
if ( V_26 && ( V_26 != F_21 ( V_3 , V_37 ) ) ) {
F_24 ( V_54
L_2 ,
V_3 -> V_55 , V_26 , V_28 -> V_38 [ 0 ] ,
V_28 -> V_38 [ 1 ] , V_28 -> V_38 [ 2 ] ,
V_28 -> V_38 [ 3 ] ) ;
F_25 ( V_3 , V_37 , V_26 ) ;
}
break;
default:
V_25 = - V_59 ;
}
return V_25 ;
}
static int F_26 ( struct V_3 * V_3 , unsigned int V_23 , void * V_24 )
{
int V_25 = 0 ;
switch ( V_23 ) {
case V_60 : {
struct V_61 * V_62 = V_24 ;
struct V_63 * V_30 = V_3 -> V_30 ;
V_62 -> V_64 = F_27 ( V_30 , 2 ) ;
V_62 -> V_65 = F_28 ( V_30 , 2 ) ;
V_62 -> V_66 =
F_21 ( V_3 , V_67 ) ;
V_62 -> V_68 = F_21 ( V_3 , V_69 ) ;
V_62 -> V_70 =
F_21 ( V_3 , V_71 ) ;
V_62 -> V_72 = F_21 ( V_3 , V_73 ) ;
V_62 -> V_74 = F_21 ( V_3 , V_75 ) ;
V_62 -> V_76 = F_21 ( V_3 , V_77 ) ;
V_62 -> V_78 = V_3 -> V_79 + V_80 ;
V_62 -> V_30 = V_30 ;
break;
}
case V_81 : {
unsigned long V_82 ;
struct V_83 * V_62 = V_24 ;
F_29 ( & V_3 -> V_84 . V_85 , V_82 ) ;
V_25 = F_30 ( V_3 , V_62 -> V_86 , V_62 -> V_87 ,
V_62 -> V_88 ) ;
F_31 ( & V_3 -> V_84 . V_85 , V_82 ) ;
break;
}
case V_89 : {
struct V_90 * V_91 = V_24 ;
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
V_25 =
F_32 ( V_93 , V_91 -> V_94 / 8 , V_91 -> V_95 / 8 ,
( V_104 * ) V_91 -> V_105 ) ;
if ( V_25 )
return V_25 ;
break;
}
case V_106 : {
struct V_107 * V_62 = V_24 ;
F_33 ( & V_3 -> V_84 . V_85 ) ;
V_25 =
F_34 ( V_3 , V_62 -> V_86 ,
V_62 -> V_108 , V_62 -> V_109 ,
V_110 ,
V_62 -> V_111 , V_62 -> V_88 ,
V_62 -> V_112 ) ;
F_35 ( & V_3 -> V_84 . V_85 ) ;
break;
}
case V_113 :
F_33 ( & V_3 -> V_84 . V_85 ) ;
V_25 = F_36 ( V_3 , * ( unsigned int * ) V_24 ) ;
F_35 ( & V_3 -> V_84 . V_85 ) ;
break;
case V_114 : {
struct V_115 * V_62 = V_24 ;
F_33 ( & V_3 -> V_84 . V_85 ) ;
V_25 = F_37 ( V_3 , V_116 , 0 ,
V_117 ,
V_110 ,
V_62 -> V_108 , V_62 -> V_109 ,
V_118 , 1 , 0 ) ;
F_35 ( & V_3 -> V_84 . V_85 ) ;
break;
}
case V_119 : {
F_38 ( & V_3 -> V_120 ) ;
F_39 ( V_3 , (struct V_121 * ) V_24 ) ;
F_40 ( & V_3 -> V_120 ) ;
break;
}
default:
V_25 = - V_59 ;
}
return V_25 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_23 , void * V_24 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_134 * V_47 = & V_3 -> V_46 . V_47 ;
int V_17 ;
switch ( V_23 ) {
case V_135 :
* ( unsigned int * ) V_24 = V_136 ;
break;
case V_137 :
* ( unsigned int * ) V_24 = V_138 ;
break;
case V_139 :
* ( unsigned int * ) V_24 = 1 << 20 ;
break;
case V_140 :
V_123 = V_24 ;
V_123 -> V_141 = F_42 ( & V_3 -> V_142 ) -
V_3 -> V_46 . V_142 . V_143 -
V_3 -> V_46 . V_142 . V_144 - V_3 -> V_46 . V_142 . V_145 ;
V_123 -> V_146 = 0 ;
break;
case V_147 :
V_123 = V_24 ;
V_123 -> V_141 = V_3 -> V_46 . V_142 . V_145 ;
V_123 -> V_146 = F_42 ( & V_3 -> V_142 ) - V_123 -> V_141 -
V_3 -> V_46 . V_142 . V_144 - V_3 -> V_46 . V_142 . V_143 ;
break;
case V_148 :
* ( unsigned int * ) V_24 = 2048 ;
break;
case V_149 :
V_125 = V_24 ;
V_125 -> V_109 = V_150 ;
V_125 -> V_151 = V_3 -> V_46 . V_151 ;
break;
case V_152 :
V_127 = V_24 ;
V_127 -> V_18 = F_14 ( V_3 , V_127 -> V_153 ,
V_127 -> V_154 &
V_21 ) ;
break;
case V_155 :
V_129 = V_24 ;
V_129 -> V_31 = F_21 ( V_3 , V_156 ) ;
V_129 -> V_33 = F_21 ( V_3 , V_157 ) ;
V_129 -> V_158 = F_21 ( V_3 , V_159 ) ;
break;
case V_160 :
V_131 = V_24 ;
V_131 -> V_161 = V_3 -> V_46 . V_161 ;
F_15 (adapter, i)
V_131 -> V_162 [ V_17 ] = V_3 -> V_12 [ V_17 ] ;
break;
case V_29 :
case V_58 :
if ( ! F_43 ( V_3 ) )
return - V_163 ;
return F_20 ( V_3 , V_23 , V_24 ) ;
case V_60 :
case V_81 :
case V_106 :
case V_113 :
case V_114 :
case V_89 :
case V_119 :
if ( ! F_43 ( V_3 ) )
return - V_163 ;
return F_26 ( V_3 , V_23 , V_24 ) ;
case V_164 :
V_133 = V_24 ;
V_133 -> V_165 = V_47 -> V_56 ;
V_133 -> V_141 = V_47 -> V_166 ;
break;
case V_167 : {
struct V_168 * V_169 = V_24 ;
struct V_170 * V_171 = F_44 ( V_169 -> V_18 ) ;
V_169 -> V_172 = V_171 -> V_168 ;
break;
}
case V_173 : {
struct V_174 * V_175 = V_24 ;
F_38 ( & V_3 -> V_120 ) ;
F_45 ( V_3 , & V_175 -> V_176 ) ;
F_46 ( V_3 , & V_175 -> V_177 ) ;
F_40 ( & V_3 -> V_120 ) ;
break;
}
default:
return - V_59 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_18 , struct V_178 * * V_179 ,
int V_180 )
{
while ( V_180 -- )
F_48 ( V_179 [ V_180 ] ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_18 , struct V_181 * V_182 )
{
}
void F_50 ( struct V_1 * V_18 )
{
V_18 -> V_183 = F_47 ;
V_18 -> V_184 = F_49 ;
}
void * F_51 ( struct V_1 * V_2 , int V_185 )
{
struct V_186 * V_91 = & ( F_52 ( V_2 ) ) -> V_187 ;
union V_188 * V_169 = F_53 ( V_91 , V_185 ) ;
void * V_189 = V_169 -> V_190 . V_189 ;
F_54 ( & V_91 -> V_191 ) ;
V_169 -> V_192 = V_91 -> V_193 ;
V_91 -> V_193 = V_169 ;
V_91 -> V_194 -- ;
F_55 ( & V_91 -> V_191 ) ;
return V_189 ;
}
void F_56 ( struct V_1 * V_2 , int V_195 )
{
struct V_186 * V_91 = & ( F_52 ( V_2 ) ) -> V_187 ;
union V_196 * V_169 = F_57 ( V_91 , V_195 ) ;
F_54 ( & V_91 -> V_197 ) ;
V_169 -> V_192 = V_91 -> V_198 ;
V_91 -> V_198 = V_169 ;
V_91 -> V_199 -- ;
F_55 ( & V_91 -> V_197 ) ;
}
void F_58 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_189 , unsigned int V_123 )
{
struct V_186 * V_91 = & ( F_52 ( V_2 ) ) -> V_187 ;
V_91 -> V_200 [ V_123 ] . V_7 = V_7 ;
V_91 -> V_200 [ V_123 ] . V_189 = V_189 ;
F_59 ( & V_91 -> V_201 ) ;
}
static inline void F_60 ( struct V_178 * V_202 , unsigned int V_123 )
{
struct V_203 * V_23 ;
V_202 -> V_204 = V_205 ;
V_23 = (struct V_203 * ) F_61 ( V_202 , sizeof( * V_23 ) ) ;
V_23 -> V_206 . V_207 = F_62 ( F_63 ( V_208 ) ) ;
F_64 ( V_23 ) = F_62 ( F_65 ( V_209 , V_123 ) ) ;
}
static void F_66 ( struct V_210 * V_211 )
{
struct V_212 * V_213 = F_67 ( V_211 , struct V_212 ,
V_214 ) ;
struct V_178 * V_202 ;
struct V_1 * V_2 = V_213 -> V_18 ;
F_54 ( & V_213 -> V_215 ) ;
while ( V_213 -> V_216 ) {
struct V_217 * V_169 = V_213 -> V_216 ;
V_213 -> V_216 = V_169 -> V_189 ;
F_55 ( & V_213 -> V_215 ) ;
V_202 = F_68 ( sizeof( struct V_203 ) ,
V_218 ) ;
if ( ! V_202 )
V_202 = V_213 -> V_219 ;
if ( ! V_202 ) {
F_54 ( & V_213 -> V_215 ) ;
V_169 -> V_189 = ( void * ) V_213 -> V_216 ;
V_213 -> V_216 = (struct V_217 * ) V_169 ;
break;
}
F_60 ( V_202 , V_169 - V_213 -> V_187 . V_200 ) ;
F_69 ( V_2 , V_202 ) ;
V_169 -> V_189 = NULL ;
if ( V_202 == V_213 -> V_219 )
V_213 -> V_219 =
F_68 ( sizeof( struct V_203 ) ,
V_218 ) ;
F_54 ( & V_213 -> V_215 ) ;
}
V_213 -> V_220 = ( V_213 -> V_216 == NULL ) ? 0 : 1 ;
F_55 ( & V_213 -> V_215 ) ;
if ( ! V_213 -> V_219 )
V_213 -> V_219 =
F_68 ( sizeof( struct V_203 ) ,
V_218 ) ;
}
void F_70 ( struct V_1 * V_2 , unsigned int V_123 )
{
struct V_212 * V_213 = F_52 ( V_2 ) ;
struct V_217 * V_169 = & V_213 -> V_187 . V_200 [ V_123 ] ;
F_54 ( & V_213 -> V_215 ) ;
V_169 -> V_189 = ( void * ) V_213 -> V_216 ;
V_169 -> V_7 = NULL ;
V_213 -> V_216 = V_169 ;
if ( ! V_169 -> V_189 || V_213 -> V_220 )
F_71 ( & V_213 -> V_214 ) ;
F_55 ( & V_213 -> V_215 ) ;
}
void F_72 ( struct V_1 * V_2 , void * V_189 , unsigned int V_123 )
{
struct V_186 * V_91 = & ( F_52 ( V_2 ) ) -> V_187 ;
F_73 ( V_123 >= V_91 -> V_221 ) ;
if ( V_2 -> type == V_222 )
( void ) F_74 ( & V_91 -> V_200 [ V_123 ] . V_189 , V_189 , NULL ) ;
else {
struct V_178 * V_202 ;
V_202 = F_68 ( sizeof( struct V_203 ) , V_223 ) ;
if ( F_75 ( V_202 ) ) {
F_60 ( V_202 , V_123 ) ;
F_69 ( V_2 , V_202 ) ;
V_91 -> V_200 [ V_123 ] . V_189 = NULL ;
} else
F_70 ( V_2 , V_123 ) ;
}
F_76 ( & V_91 -> V_201 ) ;
}
int F_77 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_189 )
{
int V_185 = - 1 ;
struct V_186 * V_91 = & ( F_52 ( V_2 ) ) -> V_187 ;
F_54 ( & V_91 -> V_191 ) ;
if ( V_91 -> V_193 &&
V_91 -> V_194 + F_78 ( & V_91 -> V_201 ) + V_224 <=
V_91 -> V_221 ) {
union V_188 * V_169 = V_91 -> V_193 ;
V_185 = ( V_169 - V_91 -> V_225 ) + V_91 -> V_226 ;
V_91 -> V_193 = V_169 -> V_192 ;
V_169 -> V_190 . V_189 = V_189 ;
V_169 -> V_190 . V_7 = V_7 ;
V_91 -> V_194 ++ ;
}
F_55 ( & V_91 -> V_191 ) ;
return V_185 ;
}
int F_79 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_189 )
{
int V_195 = - 1 ;
struct V_186 * V_91 = & ( F_52 ( V_2 ) ) -> V_187 ;
F_54 ( & V_91 -> V_197 ) ;
if ( V_91 -> V_198 ) {
union V_196 * V_169 = V_91 -> V_198 ;
V_195 = ( V_169 - V_91 -> V_227 ) + V_91 -> V_228 ;
V_91 -> V_198 = V_169 -> V_192 ;
V_169 -> V_190 . V_189 = V_189 ;
V_169 -> V_190 . V_7 = V_7 ;
V_91 -> V_199 ++ ;
}
F_55 ( & V_91 -> V_197 ) ;
return V_195 ;
}
struct V_1 * F_80 ( struct V_14 * V_18 )
{
const struct V_170 * V_171 = F_44 ( V_18 ) ;
return (struct V_1 * ) V_171 -> V_3 ;
}
static int F_81 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_229 * V_230 = F_82 ( V_202 ) ;
if ( V_230 -> V_231 != V_232 )
F_24 ( V_233
L_3 ,
V_230 -> V_231 , F_83 ( V_230 ) ) ;
return V_234 ;
}
static int F_84 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_235 * V_230 = F_82 ( V_202 ) ;
if ( V_230 -> V_231 != V_232 )
F_24 ( V_233
L_4 ,
V_230 -> V_231 , F_83 ( V_230 ) ) ;
return V_234 ;
}
static int F_85 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_236 * V_230 = F_82 ( V_202 ) ;
if ( V_230 -> V_231 != V_232 )
F_24 ( V_233
L_5 ,
V_230 -> V_231 , F_83 ( V_230 ) ) ;
return V_234 ;
}
static int F_86 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_237 * V_230 = F_82 ( V_202 ) ;
unsigned int V_185 = F_87 ( F_88 ( V_230 -> V_185 ) ) ;
struct V_217 * V_190 ;
V_190 = F_89 ( & ( F_52 ( V_18 ) ) -> V_187 , V_185 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 &&
V_190 -> V_7 -> V_238 &&
V_190 -> V_7 -> V_238 [ V_239 ] ) {
return V_190 -> V_7 -> V_238 [ V_239 ] ( V_18 , V_202 ,
V_190 ->
V_189 ) ;
} else {
F_24 ( V_233 L_6 ,
V_18 -> V_55 , V_239 ) ;
return V_234 | V_240 ;
}
}
static int F_90 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
union V_241 * V_169 = F_82 ( V_202 ) ;
unsigned int V_195 = F_87 ( F_88 ( V_169 -> V_241 ) ) ;
struct V_217 * V_190 ;
V_190 = F_91 ( & ( F_52 ( V_18 ) ) -> V_187 , V_195 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_238 &&
V_190 -> V_7 -> V_238 [ V_169 -> V_242 ] ) {
return V_190 -> V_7 -> V_238 [ V_169 -> V_242 ] ( V_18 , V_202 ,
V_190 -> V_189 ) ;
} else {
F_24 ( V_233 L_6 ,
V_18 -> V_55 , V_169 -> V_242 ) ;
return V_234 | V_240 ;
}
}
static int F_92 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
union V_241 * V_169 = F_82 ( V_202 ) ;
unsigned int V_243 = F_87 ( F_88 ( V_169 -> V_241 ) ) ;
struct V_217 * V_190 ;
V_190 = F_93 ( & ( F_52 ( V_18 ) ) -> V_187 , V_243 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_238 &&
V_190 -> V_7 -> V_238 [ V_169 -> V_242 ] ) {
return V_190 -> V_7 -> V_238 [ V_169 -> V_242 ]
( V_18 , V_202 , V_190 -> V_189 ) ;
} else {
F_24 ( V_233 L_6 ,
V_18 -> V_55 , V_169 -> V_242 ) ;
return V_234 | V_240 ;
}
}
static int F_94 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_244 * V_23 = F_82 ( V_202 ) ;
unsigned int V_195 = F_95 ( F_88 ( V_23 -> V_245 ) ) ;
struct V_186 * V_91 = & ( F_52 ( V_18 ) ) -> V_187 ;
struct V_217 * V_190 ;
unsigned int V_123 = F_83 ( V_23 ) ;
if ( F_96 ( V_123 >= V_91 -> V_221 ) ) {
F_24 ( L_7 ,
V_18 -> V_55 , V_123 ) ;
F_97 ( F_2 ( V_18 ) ) ;
return V_234 ;
}
V_190 = F_91 ( V_91 , V_195 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_238 &&
V_190 -> V_7 -> V_238 [ V_246 ] ) {
return V_190 -> V_7 -> V_238 [ V_246 ]
( V_18 , V_202 , V_190 -> V_189 ) ;
} else {
F_24 ( V_233 L_6 ,
V_18 -> V_55 , V_246 ) ;
return V_234 | V_240 ;
}
}
static struct V_178 * F_98 ( struct V_178 * V_202 , T_2 V_95 ,
T_3 V_247 )
{
if ( F_75 ( ! F_99 ( V_202 ) ) ) {
F_73 ( V_202 -> V_95 < V_95 ) ;
F_100 ( V_202 , V_95 ) ;
F_101 ( V_202 ) ;
} else {
V_202 = F_68 ( V_95 , V_247 ) ;
if ( V_202 )
F_61 ( V_202 , V_95 ) ;
}
return V_202 ;
}
static int F_102 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
union V_241 * V_169 = F_82 ( V_202 ) ;
unsigned int V_243 = F_87 ( F_88 ( V_169 -> V_241 ) ) ;
struct V_217 * V_190 ;
V_190 = F_93 ( & ( F_52 ( V_18 ) ) -> V_187 , V_243 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_238 &&
V_190 -> V_7 -> V_238 [ V_169 -> V_242 ] ) {
return V_190 -> V_7 -> V_238 [ V_169 -> V_242 ]
( V_18 , V_202 , V_190 -> V_189 ) ;
} else {
struct V_248 * V_23 = F_82 ( V_202 ) ;
struct V_249 * V_230 ;
struct V_178 * V_250 ;
unsigned int V_123 = F_83 ( V_23 ) ;
T_4 V_251 = V_23 -> V_231 ;
if ( V_23 -> V_231 == V_252 ||
V_23 -> V_231 == V_253 )
goto V_254;
V_250 = F_98 ( V_202 ,
sizeof( struct
V_249 ) ,
V_223 ) ;
if ( ! V_250 ) {
F_24 ( L_8 ) ;
goto V_254;
}
V_250 -> V_204 = V_255 ;
F_61 ( V_250 , sizeof( struct V_249 ) ) ;
V_230 = F_82 ( V_250 ) ;
V_230 -> V_206 . V_207 =
F_62 ( F_63 ( V_256 ) ) ;
V_230 -> V_206 . V_257 = F_62 ( F_103 ( V_123 ) ) ;
F_64 ( V_230 ) = F_62 ( F_65 ( V_258 , V_123 ) ) ;
V_230 -> V_251 = V_251 ;
F_69 ( V_18 , V_250 ) ;
V_254:
return V_234 ;
}
}
static int F_104 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_259 * V_23 = F_82 ( V_202 ) ;
unsigned int V_185 = F_95 ( F_88 ( V_23 -> V_245 ) ) ;
struct V_186 * V_91 = & ( F_52 ( V_18 ) ) -> V_187 ;
struct V_217 * V_190 ;
unsigned int V_123 = F_83 ( V_23 ) ;
if ( F_96 ( V_123 >= V_91 -> V_221 ) ) {
F_24 ( L_9 ,
V_18 -> V_55 , V_123 ) ;
F_97 ( F_2 ( V_18 ) ) ;
return V_234 ;
}
V_190 = F_89 ( V_91 , V_185 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_238 &&
V_190 -> V_7 -> V_238 [ V_260 ] ) {
return V_190 -> V_7 -> V_238 [ V_260 ]
( V_18 , V_202 , V_190 -> V_189 ) ;
} else {
F_24 ( V_233 L_6 ,
V_18 -> V_55 , V_260 ) ;
return V_234 | V_240 ;
}
}
static int F_105 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
struct V_261 * V_169 = F_82 ( V_202 ) ;
V_202 -> V_262 = F_106 ( 0xffff ) ;
V_202 -> V_18 = V_18 -> V_263 ;
F_107 ( V_202 , sizeof( * V_169 ) ) ;
F_108 ( V_202 ) ;
F_109 ( V_202 ) ;
return 0 ;
}
static inline T_1 F_110 ( struct V_178 * V_202 )
{
return F_88 ( ( V_264 V_265 ) V_202 -> V_204 ) >> 8 & 0xfffff ;
}
static inline T_1 F_111 ( struct V_178 * V_202 )
{
return F_112 ( F_88 ( ( V_264 V_265 ) V_202 -> V_266 ) ) ;
}
static int F_113 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
unsigned int V_243 = F_110 ( V_202 ) ;
unsigned int V_242 = F_111 ( V_202 ) ;
struct V_217 * V_190 ;
V_190 = F_93 ( & ( F_52 ( V_18 ) ) -> V_187 , V_243 ) ;
if ( V_190 && V_190 -> V_189 && V_190 -> V_7 -> V_238 &&
V_190 -> V_7 -> V_238 [ V_242 ] ) {
return V_190 -> V_7 -> V_238 [ V_242 ] ( V_18 , V_202 ,
V_190 -> V_189 ) ;
} else {
F_24 ( V_233 L_6 ,
V_18 -> V_55 , V_242 ) ;
return V_234 | V_240 ;
}
}
static int F_114 ( struct V_267 * V_268 , unsigned long V_11 ,
void * V_189 )
{
switch ( V_11 ) {
case ( V_269 ) : {
F_115 ( (struct V_181 * ) V_189 ) ;
break;
}
case ( V_270 ) : {
struct V_271 * V_272 = V_189 ;
F_116 ( V_272 -> V_273 , V_272 -> V_274 ) ;
F_115 ( F_117 ( V_272 -> V_274 ) ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_118 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
F_24 ( V_233 L_10 , V_18 -> V_55 ,
* V_202 -> V_24 ) ;
return V_234 | V_240 ;
}
void F_119 ( unsigned int V_242 , T_5 V_275 )
{
if ( V_242 < V_276 )
V_277 [ V_242 ] = V_275 ? V_275 : F_118 ;
else
F_24 ( V_233 L_11
L_12 , V_242 ) ;
}
static int F_120 ( struct V_1 * V_18 , struct V_178 * * V_179 , int V_180 )
{
while ( V_180 -- ) {
struct V_178 * V_202 = * V_179 ++ ;
unsigned int V_242 = F_111 ( V_202 ) ;
int V_25 = V_277 [ V_242 ] ( V_18, V_202 ) ;
#if V_278
if ( V_25 & V_279 ) {
union V_241 * V_169 = F_82 ( V_202 ) ;
F_24 ( V_233 L_13
L_14 , V_18 -> V_55 , V_242 ,
F_87 ( F_88 ( V_169 -> V_241 ) ) ) ;
}
#endif
if ( V_25 & V_234 )
F_121 ( V_202 ) ;
}
return 0 ;
}
int F_69 ( struct V_1 * V_18 , struct V_178 * V_202 )
{
int V_280 ;
F_122 () ;
V_280 = V_18 -> V_281 ( V_18 , V_202 ) ;
F_123 () ;
return V_280 ;
}
static int F_124 ( struct V_14 * V_18 )
{
struct V_3 * V_3 ;
int V_17 ;
F_125 ( & V_282 ) ;
F_7 (adapter, &adapter_list, adapter_list) {
F_15 (adapter, i) {
if ( V_18 == V_3 -> V_12 [ V_17 ] ) {
F_126 ( & V_282 ) ;
return 1 ;
}
}
}
F_126 ( & V_282 ) ;
return 0 ;
}
static void F_115 ( struct V_181 * V_182 )
{
struct V_14 * V_18 ;
if ( ! V_182 )
return;
V_18 = V_182 -> V_18 ;
if ( V_18 && ( F_124 ( V_18 ) ) ) {
struct V_1 * V_2 = F_80 ( V_18 ) ;
F_73 ( ! V_2 ) ;
F_127 ( V_2 , V_182 ) ;
}
}
static void F_128 ( struct V_1 * V_2 , T_1 V_123 , struct V_283 * V_175 )
{
struct V_178 * V_202 ;
struct V_284 * V_23 ;
V_202 = F_68 ( sizeof( * V_23 ) , V_223 ) ;
if ( ! V_202 ) {
F_24 ( V_233 L_15 , V_285 ) ;
return;
}
V_202 -> V_204 = V_286 ;
V_23 = (struct V_284 * ) F_129 ( V_202 , sizeof( * V_23 ) ) ;
V_23 -> V_206 . V_207 = F_62 ( F_63 ( V_208 ) ) ;
F_64 ( V_23 ) = F_62 ( F_65 ( V_287 , V_123 ) ) ;
V_23 -> V_288 = 0 ;
V_23 -> V_289 = 0 ;
V_23 -> V_290 = F_106 ( V_291 ) ;
V_23 -> V_292 = F_130 ( F_131 ( V_293 ) ) ;
V_23 -> V_26 = F_130 ( F_131 ( V_175 -> V_294 ) ) ;
V_2 -> V_281 ( V_2 , V_202 ) ;
}
static void F_116 ( struct V_295 * V_273 , struct V_295 * V_274 )
{
struct V_14 * V_296 , * V_297 ;
struct V_181 * V_180 ;
struct V_186 * V_298 ;
struct V_1 * V_2 ;
T_1 V_123 ;
int V_299 ;
struct V_283 * V_175 ;
struct V_217 * V_300 ;
V_180 = F_117 ( V_273 ) ;
if ( ! V_180 )
return;
V_296 = V_180 -> V_18 ;
V_180 = F_117 ( V_274 ) ;
if ( ! V_180 )
return;
V_297 = V_180 -> V_18 ;
if ( ! F_124 ( V_296 ) )
return;
if ( ! F_124 ( V_297 ) ) {
F_24 ( V_301 L_16
L_17 , V_285 ) ;
return;
}
V_2 = F_80 ( V_296 ) ;
F_73 ( ! V_2 ) ;
if ( V_2 != F_80 ( V_297 ) ) {
F_24 ( V_301 L_18
L_19 , V_285 ) ;
return;
}
V_175 = F_132 ( V_2 , V_274 , V_297 ) ;
if ( ! V_175 ) {
F_24 ( V_233 L_20 ,
V_285 ) ;
return;
}
V_298 = & ( F_52 ( V_2 ) ) -> V_187 ;
for ( V_123 = 0 ; V_123 < V_298 -> V_221 ; V_123 ++ ) {
V_300 = F_93 ( V_298 , V_123 ) ;
F_73 ( ! V_300 ) ;
if ( V_300 && V_300 -> V_189 && V_300 -> V_7 && V_300 -> V_7 -> V_302 ) {
V_299 = V_300 -> V_7 -> V_302 ( V_300 -> V_189 , V_273 , V_274 , V_175 ) ;
if ( V_299 ) {
F_16 () ;
F_133 ( F_134 ( V_2 ) , V_175 ) ;
F_18 () ;
F_128 ( V_2 , V_123 , V_175 ) ;
}
}
}
F_135 ( V_2 , V_175 ) ;
}
void * F_136 ( unsigned long V_109 )
{
void * V_169 = F_137 ( V_109 , V_218 ) ;
if ( ! V_169 )
V_169 = F_138 ( V_109 ) ;
return V_169 ;
}
void F_139 ( void * V_94 )
{
if ( F_140 ( V_94 ) )
F_141 ( V_94 ) ;
else
F_142 ( V_94 ) ;
}
static int F_143 ( struct V_186 * V_91 , unsigned int V_221 ,
unsigned int V_303 , unsigned int V_304 ,
unsigned int V_226 , unsigned int V_228 )
{
unsigned long V_109 = V_221 * sizeof( * V_91 -> V_200 ) +
V_303 * sizeof( * V_91 -> V_225 ) + V_304 * sizeof( * V_91 -> V_227 ) ;
V_91 -> V_200 = F_136 ( V_109 ) ;
if ( ! V_91 -> V_200 )
return - V_305 ;
V_91 -> V_227 = (union V_196 * ) & V_91 -> V_200 [ V_221 ] ;
V_91 -> V_225 = (union V_188 * ) & V_91 -> V_227 [ V_304 ] ;
V_91 -> V_221 = V_221 ;
V_91 -> V_304 = V_304 ;
V_91 -> V_228 = V_228 ;
V_91 -> V_198 = NULL ;
V_91 -> V_303 = V_303 ;
V_91 -> V_226 = V_226 ;
V_91 -> V_193 = NULL ;
V_91 -> V_199 = V_91 -> V_194 = 0 ;
F_144 ( & V_91 -> V_201 , 0 ) ;
F_145 ( & V_91 -> V_197 ) ;
F_145 ( & V_91 -> V_191 ) ;
if ( V_304 ) {
while ( -- V_304 )
V_91 -> V_227 [ V_304 - 1 ] . V_192 = & V_91 -> V_227 [ V_304 ] ;
V_91 -> V_198 = V_91 -> V_227 ;
}
if ( V_303 ) {
while ( -- V_303 )
V_91 -> V_225 [ V_303 - 1 ] . V_192 = & V_91 -> V_225 [ V_303 ] ;
V_91 -> V_193 = V_91 -> V_225 ;
}
return 0 ;
}
static void F_146 ( struct V_186 * V_91 )
{
F_139 ( V_91 -> V_200 ) ;
}
static inline void F_147 ( struct V_3 * V_306 )
{
F_148 ( & V_282 ) ;
F_6 ( & V_306 -> V_307 , & V_307 ) ;
F_149 ( & V_282 ) ;
}
static inline void F_150 ( struct V_3 * V_306 )
{
F_148 ( & V_282 ) ;
F_10 ( & V_306 -> V_307 ) ;
F_149 ( & V_282 ) ;
}
int F_151 ( struct V_3 * V_3 )
{
struct V_1 * V_18 = & V_3 -> V_2 ;
int V_303 , V_308 ;
struct V_212 * V_91 ;
struct V_122 V_309 , V_122 ;
struct V_124 V_124 ;
unsigned int V_310 ;
V_91 = F_137 ( sizeof( * V_91 ) , V_218 ) ;
if ( ! V_91 )
return - V_305 ;
V_308 = - V_59 ;
if ( V_18 -> V_311 ( V_18 , V_139 , & V_91 -> V_312 ) < 0 ||
V_18 -> V_311 ( V_18 , V_135 , & V_91 -> V_313 ) < 0 ||
V_18 -> V_311 ( V_18 , V_148 , & V_310 ) < 0 ||
V_18 -> V_311 ( V_18 , V_149 , & V_124 ) < 0 ||
V_18 -> V_311 ( V_18 , V_140 , & V_122 ) < 0 ||
V_18 -> V_311 ( V_18 , V_147 , & V_309 ) < 0 )
goto V_314;
V_308 = - V_305 ;
F_152 ( V_18 -> V_315 , F_153 ( V_310 ) ) ;
if ( ! F_134 ( V_18 ) )
goto V_314;
V_303 = F_22 ( V_122 . V_141 / 2 , V_316 ) ;
V_308 = F_143 ( & V_91 -> V_187 , V_122 . V_141 , V_303 ,
V_309 . V_141 , V_317 , V_309 . V_146 ) ;
if ( V_308 )
goto V_318;
V_91 -> V_151 = V_124 . V_151 ;
V_91 -> V_319 = V_124 . V_109 ;
F_154 ( & V_91 -> V_214 , F_66 ) ;
F_145 ( & V_91 -> V_215 ) ;
F_155 ( & V_91 -> V_320 ) ;
V_91 -> V_18 = V_18 ;
F_52 ( V_18 ) = V_91 ;
V_18 -> V_183 = F_120 ;
V_18 -> V_184 = F_127 ;
if ( F_156 ( & V_307 ) )
F_157 ( & V_321 ) ;
V_91 -> V_219 = F_68 ( sizeof( struct V_203 ) , V_218 ) ;
V_91 -> V_220 = 0 ;
F_147 ( V_3 ) ;
return 0 ;
V_318:
F_158 ( F_134 ( V_18 ) ) ;
F_152 ( V_18 -> V_315 , NULL ) ;
V_314:
F_142 ( V_91 ) ;
return V_308 ;
}
static void F_159 ( struct V_322 * V_323 )
{
struct V_324 * V_325 = F_67 ( V_323 , struct V_324 , V_322 ) ;
F_158 ( V_325 ) ;
}
void F_160 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
struct V_212 * V_91 = F_52 ( V_2 ) ;
struct V_324 * V_325 ;
F_150 ( V_3 ) ;
if ( F_156 ( & V_307 ) )
F_161 ( & V_321 ) ;
F_146 ( & V_91 -> V_187 ) ;
F_52 ( V_2 ) = NULL ;
F_16 () ;
V_325 = F_134 ( V_2 ) ;
F_18 () ;
F_152 ( V_2 -> V_315 , NULL ) ;
F_162 ( & V_325 -> V_322 , F_159 ) ;
if ( V_91 -> V_219 )
F_121 ( V_91 -> V_219 ) ;
F_142 ( V_91 ) ;
}
static inline void F_163 ( struct V_1 * V_2 )
{
static int V_326 ;
F_5 ( & V_8 ) ;
snprintf ( V_2 -> V_55 , sizeof( V_2 -> V_55 ) , L_21 , V_326 ++ ) ;
F_6 ( & V_2 -> V_327 , & V_327 ) ;
F_8 ( & V_8 ) ;
}
static inline void F_164 ( struct V_1 * V_2 )
{
F_5 ( & V_8 ) ;
F_10 ( & V_2 -> V_327 ) ;
F_8 ( & V_8 ) ;
}
static inline int F_165 ( struct V_3 * V_3 )
{
int type = 0 ;
switch ( V_3 -> V_46 . V_328 ) {
case V_329 :
type = V_222 ;
break;
case V_330 :
case V_331 :
type = V_332 ;
break;
case V_333 :
type = V_334 ;
break;
}
return type ;
}
void T_6 F_166 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
F_155 ( & V_2 -> V_327 ) ;
F_50 ( V_2 ) ;
V_2 -> V_281 = V_335 ;
V_2 -> V_311 = F_41 ;
V_2 -> type = F_165 ( V_3 ) ;
F_163 ( V_2 ) ;
}
void T_7 F_167 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
V_2 -> V_183 = NULL ;
V_2 -> V_184 = NULL ;
F_164 ( V_2 ) ;
}
void T_8 F_168 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_276 ; ++ V_17 )
V_277 [ V_17 ] = F_118 ;
F_119 ( V_336 , F_81 ) ;
F_119 ( V_337 , F_84 ) ;
F_119 ( V_338 , F_85 ) ;
F_119 ( V_339 , F_90 ) ;
F_119 ( V_340 , F_90 ) ;
F_119 ( V_246 , F_94 ) ;
F_119 ( V_341 , F_92 ) ;
F_119 ( V_342 , F_92 ) ;
F_119 ( V_258 , F_92 ) ;
F_119 ( V_343 , F_92 ) ;
F_119 ( V_344 , F_92 ) ;
F_119 ( V_345 , F_92 ) ;
F_119 ( V_346 , F_92 ) ;
F_119 ( V_239 , F_86 ) ;
F_119 ( V_347 , F_92 ) ;
F_119 ( V_348 , F_92 ) ;
F_119 ( V_349 , F_102 ) ;
F_119 ( V_260 , F_104 ) ;
F_119 ( V_350 , F_92 ) ;
F_119 ( V_351 , F_92 ) ;
F_119 ( V_352 , F_113 ) ;
F_119 ( V_353 , F_92 ) ;
F_119 ( V_354 , F_105 ) ;
F_119 ( V_355 , F_92 ) ;
F_119 ( V_356 , F_92 ) ;
F_119 ( V_357 , F_92 ) ;
}
