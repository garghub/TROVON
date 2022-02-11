static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 = 1 ;
F_2 ( & V_2 -> V_6 ) ;
}
static T_1 F_3 ( struct V_7 * V_8 , T_2 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_10 ;
int V_11 = V_8 -> V_12 - V_2 -> V_13 ;
( * V_9 ) = V_2 -> V_14 . V_15 + V_11 ;
return V_2 -> V_14 . V_16 - V_11 ;
}
static T_1 F_4 ( struct V_7 * V_8 , T_2 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_10 ;
int V_11 = V_8 -> V_12 - V_2 -> V_13 ;
( * V_9 ) = V_2 -> V_14 . V_17 + V_11 ;
return sizeof( struct V_18 ) - V_11 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_3 * V_4 ;
if ( F_6 ( & V_2 -> V_20 ) ) {
V_19 -> V_21 = V_22 ;
return;
}
V_4 = F_7 ( V_2 ) ;
if ( V_4 == NULL ) {
F_8 ( & V_2 -> V_20 ) ;
V_19 -> V_21 = V_22 ;
return;
}
if ( V_19 == & V_2 -> V_14 . V_23 ) {
V_2 -> V_14 . V_24 = F_9 ( & V_2 -> V_25 -> V_26 ,
( V_27 ) sizeof(
struct
V_18 ) ,
( V_28 * ) & V_2 ->
V_14 .
V_17 ,
V_29 ) ;
if ( V_2 -> V_14 . V_24 == NULL ) {
F_10 ( L_1 ) ;
V_19 -> V_21 = V_22 ;
return;
}
memcpy ( V_2 -> V_14 . V_24 , V_19 ,
sizeof( struct V_18 ) ) ;
V_2 -> V_13 = V_2 -> V_14 . V_24 ;
V_2 -> V_30 . V_31 =
( V_32 ) F_4 ;
} else {
V_2 -> V_13 = ( V_33 * ) V_19 ;
V_2 -> V_30 . V_31 =
( V_32 ) F_3 ;
}
V_4 -> V_34 = F_1 ;
V_2 -> V_5 = 0 ;
V_2 -> V_30 . V_12 = V_2 -> V_13 ;
if ( ! F_11 ( V_2 , (struct V_18 * ) V_2 -> V_13 , V_4 ,
& V_2 -> V_30 ) )
goto V_35;
while ( ! V_2 -> V_5 )
F_12 ( V_2 -> V_6 ,
V_2 -> V_5 ) ;
V_35:
if ( V_19 == & V_2 -> V_14 . V_23 ) {
memcpy ( V_19 , V_2 -> V_14 . V_24 ,
sizeof( struct V_18 ) ) ;
F_13 ( & V_2 -> V_25 -> V_26 ,
( V_27 ) sizeof( struct V_18 ) ,
V_2 -> V_14 . V_24 ,
( V_28 ) V_2 -> V_14 . V_17 ) ;
}
F_8 ( & V_2 -> V_20 ) ;
F_14 ( V_2 , (struct V_3 * ) V_4 ) ;
return;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_36 = 1 ;
F_2 ( & V_2 -> V_37 ) ;
}
static T_1 F_16 ( struct V_7 * V_8 ,
T_2 * V_9 )
{
int V_11 = ( V_33 * ) V_8 -> V_12 - V_38 ;
( * V_9 ) = V_39 + V_11 ;
return V_40 - V_11 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_41 = 1 ;
F_2 ( & V_2 -> V_42 ) ;
}
static V_33 F_18 ( struct V_38 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_3 * V_4 ;
struct V_7 V_8 ;
V_33 V_44 = V_45 ;
if ( F_6 ( & V_46 ) )
return V_47 ;
if ( V_38 ) {
if ( V_40 < V_43 -> V_48 ) {
F_13 ( & V_2 -> V_25 -> V_26 ,
( V_27 ) V_40 ,
V_38 ,
V_39 ) ;
goto V_49;
}
} else {
V_49:
V_40 = V_43 -> V_48 ;
V_50 = V_2 -> V_25 ;
V_38 = F_9 ( & V_2 -> V_25 -> V_26 ,
( V_27 )
V_40 ,
&
V_39 ,
V_29 ) ;
}
if ( ! V_38 ) {
F_19 ( V_51 ,
L_2
L_3 ,
V_43 -> V_48 ) ;
F_10 ( L_4 ) ;
V_44 = V_47 ;
goto V_52;
}
memcpy ( V_38 , V_43 -> V_53 , V_43 -> V_48 ) ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 == NULL ) {
F_19 ( V_51 ,
L_5 ) ;
V_44 = V_47 ;
F_10 ( L_6 ) ;
goto V_52;
}
V_2 -> V_41 = 0 ;
V_4 -> V_34 = F_17 ;
V_8 . V_12 = V_38 + V_43 -> V_11 ;
V_8 . V_31 = ( V_32 ) F_16 ;
V_8 . V_48 = V_40 ;
if ( ! (* V_43 -> V_54 )( V_2 , V_4 , & V_8 , V_43 -> V_55 ) ) {
V_2 -> V_41 = 0 ;
goto V_56;
}
while ( ! V_2 -> V_41 )
F_12 ( V_2 -> V_42 ,
V_2 -> V_41 ) ;
V_56:
if ( V_44 == V_45 && V_43 -> V_57 )
(* V_43 -> V_57 )( V_2 , V_4 , V_43 -> V_58 ) ;
F_14 ( V_2 , V_4 ) ;
V_52:
if ( V_44 == V_45 )
memcpy ( V_43 -> V_53 , V_38 , V_43 -> V_48 ) ;
F_8 ( & V_46 ) ;
return V_44 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_7 * V_8 , void * V_55 )
{
struct V_59 * V_60 =
(struct V_59 * ) V_38 ;
F_21 ( V_8 , V_2 , V_4 , V_4 -> V_61 -> V_53 . V_62 ) ;
F_22 ( V_2 , V_4 , V_8 -> V_48 , V_63 ) ;
if ( ! F_23 ( V_2 , V_4 , V_8 ) ) {
V_60 -> V_21 = V_64 ;
return false ;
}
F_24 ( V_2 , V_4 ) ;
return true ;
}
static V_33 F_25 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_38 V_43 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_2 = V_2 ;
V_43 . V_53 = V_60 ;
V_43 . V_48 = sizeof( struct V_59 )
+ F_26 ( V_60 -> V_65 )
+ F_26 ( V_60 -> V_66 ) ;
V_43 . V_11 = 0 ;
V_43 . V_54 = F_20 ;
return F_18 ( & V_43 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_67 = F_28 ( V_4 -> V_68 . V_69 . V_70 . V_67 ) ;
V_4 -> V_61 -> V_71 . V_72 |= F_29 ( V_4 -> V_68 . V_69 . V_70 . V_73 ) ;
(* V_4 -> V_74 )( V_2 , V_4 ) ;
}
static bool F_30 ( struct V_1 * V_2 ,
union V_75 * V_76 ,
struct V_3 * V_4 ,
struct V_7 * V_8 ,
T_1 V_77 ,
T_3 V_67 )
{
struct V_78 * V_53 = & V_4 -> V_61 -> V_53 ;
if ( V_2 -> V_72 & V_79 )
return false ;
F_21 ( V_8 , V_2 , V_4 , V_4 -> V_61 -> V_53 . V_62 ) ;
F_22 ( V_2 , V_4 , V_8 -> V_48 , V_80 ) ;
V_53 -> V_70 . V_77 = F_29 ( V_77 ) ;
V_53 -> V_70 . V_67 = F_31 ( V_67 ) ;
V_53 -> V_70 . V_73 = ( V_33 ) F_26 ( V_4 -> V_61 -> V_71 . V_72 ) ;
V_4 -> V_81 = V_76 ;
V_4 -> V_74 = V_4 -> V_34 ;
V_4 -> V_34 = F_27 ;
if ( ! F_23 ( V_2 , V_4 , V_8 ) )
return false ;
F_24 ( V_2 , V_4 ) ;
return true ;
}
static bool F_32 ( struct V_82 V_73 )
{
bool V_44 ;
V_44 = ( ( V_73 . V_82 [ 7 ] == 0 ) &&
( V_73 . V_82 [ 6 ] == 0 ) &&
( V_73 . V_82 [ 5 ] == 0 ) &&
( V_73 . V_82 [ 4 ] == 0 ) &&
( V_73 . V_82 [ 3 ] == 0 ) &&
( V_73 . V_82 [ 2 ] == 0 ) &&
( V_73 . V_82 [ 0 ] == 0 ) ) ;
return V_44 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_7 * V_8 , void * V_55 )
{
struct V_83 * V_76 = (struct V_83 * ) V_55 ;
union V_75 * V_84 =
(union V_75 * ) V_38 ;
V_33 V_85 = 0 ;
V_33 V_86 = 0 ;
V_33 V_73 = 0 ;
T_1 V_87 = V_88 ;
struct V_89 * V_90 ;
unsigned long V_72 ;
if ( V_76 -> V_91 == V_92 ) {
struct V_93 * V_94 = & V_76 -> V_95 . V_96 ;
V_85 = V_94 -> V_97 ;
V_86 = V_94 -> V_67 ;
V_73 = V_94 -> V_73 ;
} else if ( V_76 -> V_91 == V_98 ) {
struct V_99 * V_100 = & V_76 -> V_95 . V_101 ;
V_85 = V_100 -> V_97 ;
V_86 = V_100 -> V_67 ;
V_73 = V_100 -> V_73 ;
}
if ( V_85 > 0 ) {
V_4 -> V_68 . V_69 . V_70 . V_102 = F_29 (
V_103 ) ;
return false ;
}
V_4 -> V_67 = V_86 ;
V_4 -> V_61 -> V_71 . V_72 |= F_29 ( V_73 ) ;
switch ( V_76 -> V_91 ) {
case V_104 :
{
struct V_105 * V_106 = & V_84 -> V_107 ;
strcpy ( V_106 -> V_108 , F_34 ( V_2 ) ) ;
V_106 -> V_109 = V_110 ;
V_106 -> V_111 = V_112 ;
break;
}
case V_113 :
{
struct V_114 * V_115 = & V_84 -> V_116 ;
V_115 -> V_117 = 0 ;
F_35 ( V_2 -> V_25 , V_118 ,
& V_115 -> V_119 ) ;
F_35 ( V_2 -> V_25 , V_120 ,
& V_115 -> V_121 ) ;
V_115 -> V_122 = F_36 ( V_2 -> V_25 -> V_123 ,
V_2 -> V_25 -> V_124 ) ;
V_115 -> V_125 = V_126 ;
V_115 -> V_127 = V_128 ;
V_115 -> V_129 = V_130 ;
V_115 -> V_131 . V_132 = V_2 -> V_25 -> V_133 -> V_134 ;
V_115 -> V_131 . V_135 = F_37 ( V_2 -> V_25 -> V_136 ) ;
V_115 -> V_131 . V_137 = F_38 ( V_2 -> V_25 -> V_136 ) ;
memset ( V_115 -> V_138 , 0 , sizeof( V_115 -> V_138 ) ) ;
V_115 -> V_139 = F_39 ( F_40 ( V_2 -> V_140 ) ) ;
V_115 -> V_141 = F_41 ( F_40 ( V_2 -> V_140 ) ) ;
V_115 -> V_142 = F_39 ( F_42 ( V_2 -> V_140 ) ) ;
V_115 -> V_143 = F_41 ( F_42 ( V_2 -> V_140 ) ) ;
V_115 -> V_144 = F_41 ( F_42 ( V_2 -> V_145 ) ) ;
V_115 -> V_146 = F_39 ( F_42 ( V_2 -> V_145 ) ) ;
V_115 -> V_147 = F_40 ( V_2 -> V_145 ) ;
if ( V_2 -> V_148 & V_149 )
V_115 -> V_150 = V_151
| V_152 ;
else
V_115 -> V_150 = V_153
| V_154 ;
V_115 -> V_155 = 0 ;
V_115 -> V_156 = 0 ;
V_115 -> V_157 = 0 ;
V_115 -> V_158 = 0 ;
V_115 -> V_159 = 0 ;
V_115 -> V_160 = 0 ;
V_115 -> V_161 = 0 ;
V_115 -> V_162 = 0 ;
break;
}
case V_163 :
{
struct V_164 * V_165 = & V_84 -> V_166 ;
if ( V_2 -> V_72 & V_79 )
V_165 -> V_21 = V_167 ;
else
V_165 -> V_21 = V_168 ;
V_165 -> V_169 = V_170 ;
break;
}
case V_171 :
case V_172 :
case V_173 :
V_87 = V_174 ;
break;
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
if ( ! F_30 ( V_2 , V_84 , V_4 , V_8 ,
V_76 -> V_91 ,
V_184 ) ) {
V_87 = V_185 ;
break;
}
return true ;
case V_186 :
{
struct V_187 * V_188 = & V_84 -> V_189 ;
struct V_82 V_73 ;
memcpy ( & V_73 , V_188 -> V_190 , sizeof( struct V_82 ) ) ;
if ( ! F_32 ( V_73 ) ) {
V_87 = V_191 ;
break;
}
F_43 ( & V_2 -> V_192 , V_72 ) ;
V_90 = F_44 ( V_2 , ( T_2 * ) V_188 -> V_193 ) ;
F_45 ( & V_2 -> V_192 , V_72 ) ;
if ( V_90 == NULL ) {
V_87 = V_191 ;
break;
}
V_188 -> V_194 = 0xFF ;
V_188 -> V_73 = V_188 -> V_190 [ 1 ] ;
V_4 -> V_67 = F_46 ( V_90 , V_2 ) ;
break;
}
case V_92 :
{
struct V_93 * V_94 = & V_84 -> V_96 ;
V_90 = V_2 -> V_195 + V_4 -> V_67 ;
if ( V_90 >= V_2 -> V_196
|| V_90 -> V_197 != V_198
|| V_90 -> V_193 == 0 ) {
V_87 = V_199 ;
break;
}
* ( T_2 * ) V_94 -> V_193 = V_90 -> V_193 ;
memset ( V_94 -> V_190 , 0 , sizeof( V_94 -> V_190 ) ) ;
V_94 -> V_190 [ 1 ] = ( V_33 ) F_26 ( V_4 -> V_61 -> V_71 . V_72 ) ;
break;
}
case V_98 :
V_90 = V_2 -> V_195 + V_4 -> V_67 ;
if ( V_90 >= V_2 -> V_196
|| V_90 -> V_197 != V_198
|| ! ( V_90 -> V_72 & V_200 ) ) {
V_87 = V_199 ;
break;
}
if ( ! F_30 ( V_2 , V_84 , V_4 , V_8 ,
V_76 -> V_91 ,
V_90 -> V_201 ) ) {
V_87 = V_185 ;
break;
}
return true ;
default:
V_87 = V_174 ;
break;
}
V_4 -> V_68 . V_69 . V_70 . V_102 = F_29 ( V_87 ) ;
return false ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_55 )
{
struct V_83 * V_76 = (struct V_83 * ) V_55 ;
union V_75 * V_84 =
(union V_75 * ) V_38 ;
switch ( V_76 -> V_91 ) {
case V_104 :
{
struct V_105 * V_106 =
& V_84 -> V_107 ;
strcpy ( V_106 -> V_202 , V_203 ) ;
V_106 -> V_139 = V_204 ;
V_106 -> V_141 = V_205 ;
V_106 -> V_142 = 0 ;
V_106 -> V_143 = 0 ;
break;
}
case V_186 :
{
struct V_187 * V_188 = & V_84 -> V_189 ;
if ( F_26 ( V_4 -> V_68 . V_69 . V_70 . V_102 ) ==
V_88 ) {
V_188 -> V_67 = V_4 -> V_67 ;
V_188 -> V_97 = 0 ;
}
break;
}
}
V_76 -> V_21 = F_26 ( V_4 -> V_68 . V_69 . V_70 . V_102 ) ;
}
static V_33 F_48 ( struct V_1 * V_2 , struct V_83 * V_76 )
{
struct V_38 V_43 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_2 = V_2 ;
V_43 . V_53 = & V_76 -> V_95 ;
V_43 . V_48 = sizeof( union V_75 ) ;
V_43 . V_11 = 0 ;
V_43 . V_54 = F_33 ;
V_43 . V_55 = V_76 ;
V_43 . V_57 = F_47 ;
V_43 . V_58 = V_76 ;
return F_18 ( & V_43 ) ;
}
static bool F_49 ( struct V_1 * V_2 ,
struct V_206 * V_207 ,
struct V_3 * V_4 ,
struct V_7 * V_8 )
{
F_21 ( V_8 , V_2 , V_4 , V_4 -> V_61 -> V_53 . V_62 ) ;
F_22 ( V_2 , V_4 , V_8 -> V_48 , V_208 ) ;
if ( ! F_23 ( V_2 , V_4 , V_8 ) ) {
V_207 -> V_21 = V_64 ;
return false ;
}
F_24 ( V_2 , V_4 ) ;
return true ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_206 * V_207 = (struct V_206 * ) V_4 -> V_81 ;
struct V_209 * V_210 = & V_207 -> V_95 . V_211 ;
V_33 V_87 = V_212 ;
V_210 -> V_213 = V_4 -> V_68 . V_214 . V_215 ;
V_210 -> V_216 = V_4 -> V_217 ;
V_210 -> V_218 =
F_26 ( V_4 -> V_68 . V_214 . V_218 ) ;
switch ( V_4 -> V_219 ) {
case V_220 :
case V_221 :
V_87 = V_222 ;
break;
case V_223 :
V_87 = V_224 ;
break;
case V_225 :
V_87 = V_226 ;
break;
case V_227 :
case V_228 :
V_87 = V_229 ;
break;
case V_230 :
V_87 = V_231 ;
break;
case V_232 :
V_87 = V_233 ;
break;
case V_234 :
V_87 = V_235 ;
break;
case V_236 :
V_87 = V_237 ;
break;
case V_238 :
V_87 = V_239 ;
break;
case V_240 :
V_87 = V_241 ;
break;
}
V_210 -> V_242 = V_87 ;
V_210 -> V_67 =
F_51 ( V_2 , ( T_3 ) V_210 -> V_67 ) ;
(* V_4 -> V_74 )( V_2 , V_4 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_7 * V_8 ,
void * V_55 )
{
struct V_206 * V_207 = (struct V_206 * ) V_38 ;
V_207 -> V_21 = V_243 ;
switch ( V_207 -> V_244 ) {
case V_245 :
{
V_33 * V_246 = ( V_33 * ) & V_2 -> V_25 -> V_247 ;
struct V_248 * V_249 =
& V_207 -> V_95 . V_250 ;
int V_251 ;
if ( V_207 -> V_72 & V_252 ) {
V_207 -> V_21 = V_253 ;
break;
}
if ( V_207 -> V_254 > V_255 ) {
V_207 -> V_21 = V_256 ;
V_207 -> V_254 = V_255 ;
break;
}
memset ( V_249 , 0 , sizeof( * V_249 ) ) ;
V_249 -> V_257 . V_258 = V_2 -> V_25 -> V_259 ;
V_249 -> V_257 . V_260 = V_2 -> V_25 -> V_261 ;
V_249 -> V_257 . V_262 = V_2 -> V_25 -> V_124 ;
V_249 -> V_257 . V_263 = V_2 -> V_25 -> V_123 ;
V_249 -> V_257 . V_246 [ 0 ] = V_246 [ 0 ] ;
V_249 -> V_257 . V_246 [ 1 ] = V_246 [ 1 ] ;
V_249 -> V_257 . V_246 [ 2 ] = V_246 [ 2 ] ;
V_249 -> V_257 . V_264 = V_2 -> V_25 -> V_265 ;
V_249 -> V_257 . V_132 = V_2 -> V_25 -> V_133 -> V_134 ;
V_249 -> V_257 . V_266 = F_37 ( V_2 -> V_25 -> V_136 ) ;
V_249 -> V_257 . V_267 = F_38 ( V_2 -> V_25 -> V_136 ) ;
V_251 = F_53 ( V_2 -> V_25 , V_268 ) ;
if ( V_251 ) {
T_3 V_269 ;
T_1 V_270 ;
F_54 ( V_2 -> V_25 ,
V_251 + V_271 ,
& V_269 ) ;
F_35 ( V_2 -> V_25 ,
V_251 + V_272 ,
& V_270 ) ;
V_249 -> V_257 . V_273 =
( V_33 ) ( V_269 & V_274 ) ;
V_249 -> V_257 . V_275 =
( V_33 ) ( V_270 & V_276 ) ;
V_249 -> V_257 . V_277 =
( V_33 ) ( ( V_269 & V_278 )
>> V_279 ) ;
V_249 -> V_257 . V_280 =
( V_33 ) ( ( V_270 & V_281 )
>> 4 ) ;
}
V_249 -> V_257 . V_282 = 1 ;
if ( V_2 -> V_25 -> V_283 )
V_249 -> V_257 . V_284 = V_285 ;
else if ( V_2 -> V_25 -> V_286 )
V_249 -> V_257 . V_284 = V_287 ;
else
V_249 -> V_257 . V_284 = V_288 ;
V_249 -> V_289 = V_290 ;
if ( V_2 -> V_148 & V_149 )
V_249 -> V_289 = V_291 ;
if ( V_2 -> V_72 & V_79 )
V_249 -> V_292 |= V_293 ;
V_249 -> V_292 |= V_294 |
V_295 ;
if ( V_2 -> V_25 -> V_123 == V_296
|| V_2 -> V_25 -> V_123 == V_297
|| V_2 -> V_25 -> V_123 == V_298
|| V_2 -> V_25 -> V_123 == V_299 )
V_249 -> V_292 |= V_300 ;
V_249 -> V_301 = V_302 ;
V_249 -> V_303 = V_302 ;
strcpy ( V_249 -> V_304 , V_2 -> V_305 ) ;
strcpy ( V_249 -> V_306 , V_2 -> V_306 ) ;
strcpy ( V_249 -> V_307 , F_55 ( V_2 ) ) ;
strcpy ( V_249 -> V_308 , F_34 ( V_2 ) ) ;
V_249 -> V_309 = V_310 ;
V_249 -> V_311 = 1 ;
V_249 -> V_312 = V_249 -> V_309 ;
V_249 -> V_313 = 256 ;
if ( V_2 -> V_25 -> V_123 == V_314
|| V_2 -> V_25 -> V_123 == V_296 )
V_249 -> V_315 = 4 ;
else
V_249 -> V_315 = 2 ;
V_249 -> V_316 |= V_317 ;
V_249 -> V_318 = V_2 -> V_318 ;
V_249 -> V_319 = V_2 -> V_320
& ( V_321
| V_322
| V_323
| V_324
| V_325
| V_326
| V_327 ) ;
break;
}
case V_328 :
{
struct V_329 * V_330 =
& V_207 -> V_95 . V_331 ;
if ( V_207 -> V_72 & V_252 ) {
V_207 -> V_21 = V_253 ;
break;
}
if ( V_207 -> V_254 > V_332 ) {
V_207 -> V_21 = V_256 ;
V_207 -> V_254 = V_332 ;
} else if ( V_330 -> V_333 == V_334
|| V_330 -> V_333 == V_335 ) {
if ( V_330 -> V_333 == V_334
&& V_330 -> V_336 >= V_302 ) {
V_207 -> V_21 = V_337 ;
} else {
memcpy ( ( T_2 * ) V_330 -> V_338 ,
& V_2 -> V_339 -> V_193 [ 0 ] , sizeof( T_2 ) ) ;
V_330 -> V_340 = sizeof( T_2 ) ;
}
} else {
V_207 -> V_21 = V_341 ;
}
break;
}
case V_342 :
{
if ( V_207 -> V_72 & V_252 ) {
if ( F_49 ( V_2 , V_207 , V_4 , V_8 ) )
return true ;
break;
}
V_207 -> V_21 = V_253 ;
break;
}
case V_343 :
{
struct V_344 * V_345 = & V_207 -> V_95 . V_346 ;
if ( V_207 -> V_72 & V_252 ) {
if ( F_49 ( V_2 , V_207 , V_4 , V_8 ) )
return true ;
break;
}
if ( V_207 -> V_254 > V_347 ) {
V_207 -> V_21 = V_256 ;
V_207 -> V_254 = V_347 ;
break;
}
if ( V_345 -> V_348 == V_349
&& V_207 -> V_254 >= V_347 ) {
if ( V_345 -> V_350 == V_351 ) {
T_1 V_352 = V_207 -> V_353 ;
T_1 V_11 = V_345 -> V_354 ;
T_1 V_355 = V_356 ;
if ( ! ( V_2 -> V_148 & V_357 ) )
V_355 = 0 ;
if ( V_352 > V_355 )
V_352 = V_355 ;
if ( V_11 >= V_355
|| V_11 + V_352 > V_355
|| V_352 == 0 ) {
V_207 -> V_21 = V_341 ;
break;
}
memcpy ( V_345 + 1 ,
V_2 -> V_358 + V_11 ,
V_352 ) ;
V_207 -> V_353 = V_352 ;
} else if ( V_345 -> V_350 == V_359 ) {
memset ( V_2 -> V_358 , 0 ,
V_356 ) ;
F_56 ( & V_2 -> V_148 ,
V_357 ) ;
} else if ( V_345 -> V_350 != V_360 ) {
V_207 -> V_21 = V_253 ;
break;
}
V_345 -> V_361 = 0 ;
V_345 -> V_354 = 0 ;
V_345 -> V_362 = V_356 ;
if ( ! ( V_2 -> V_148 & V_357 ) )
V_345 -> V_362 = 0 ;
} else {
V_207 -> V_21 = V_253 ;
}
break;
}
case V_363 :
{
struct V_209 * V_210 = & V_207 -> V_95 . V_211 ;
struct V_82 V_73 ;
memcpy ( & V_73 , V_210 -> V_73 , sizeof( struct V_82 ) ) ;
if ( V_207 -> V_72 & V_252 ) {
if ( F_49 ( V_2 , V_207 , V_4 , V_8 ) )
return true ;
break;
}
if ( V_207 -> V_254 > V_364 ) {
V_207 -> V_21 = V_256 ;
V_207 -> V_254 = V_364 ;
break;
}
if ( V_210 -> V_67 >= V_310 || ! F_32 ( V_73 ) ) {
V_207 -> V_21 = V_341 ;
break;
}
F_21 ( V_8 , V_2 , V_4 , NULL ) ;
V_8 -> V_48 = V_207 -> V_353 ;
V_8 -> V_12 += F_57 ( struct V_206 , V_95 . V_365 )
+ sizeof( struct V_209 ) ;
V_4 -> V_67 = ( T_3 ) V_210 -> V_67 ;
V_4 -> V_61 -> V_71 . V_72 |= F_29 ( V_210 -> V_73 [ 1 ] ) ;
memcpy ( V_4 -> V_61 -> V_71 . V_366 , V_210 -> V_366 , 16 ) ;
V_4 -> V_61 -> V_71 . V_48 = F_29 ( V_207 -> V_353 ) ;
V_4 -> V_217 = V_210 -> V_216 ;
V_4 -> V_367 = ( V_33 * ) V_210 -> V_368 ;
V_4 -> V_81 = V_207 ;
V_4 -> V_74 = V_4 -> V_34 ;
V_4 -> V_34 = F_50 ;
if ( V_210 -> V_72 & V_369 ) {
V_4 -> V_61 -> V_71 . V_72 |= F_29 ( V_370 ) ;
} else if ( V_210 -> V_72 & V_371 ) {
V_4 -> V_61 -> V_71 . V_72 |= F_29 ( V_372 ) ;
} else {
if ( V_8 -> V_48 ) {
V_207 -> V_21 = V_341 ;
break;
}
}
if ( V_210 -> V_72 & V_373 )
V_4 -> V_61 -> V_71 . V_72 |=
F_29 ( V_374 ) ;
else if ( V_210 -> V_72 & V_375 )
V_4 -> V_61 -> V_71 . V_72 |= F_29 ( V_376 ) ;
if ( ! F_23 ( V_2 , V_4 , V_8 ) ) {
V_207 -> V_21 = V_64 ;
break;
}
F_24 ( V_2 , V_4 ) ;
return true ;
}
case V_377 :
{
struct V_378 * V_94 =
& V_207 -> V_95 . V_379 ;
struct V_89 * V_90 ;
if ( V_207 -> V_72 & V_252 ) {
if ( F_49 ( V_2 , V_207 , V_4 , V_8 ) )
return true ;
break;
}
if ( V_207 -> V_254 > V_380 ) {
V_207 -> V_21 = V_256 ;
V_207 -> V_254 = V_380 ;
break;
}
if ( V_94 -> V_67 >= V_310 ) {
V_207 -> V_21 = V_341 ;
break;
}
V_90 = V_2 -> V_195 + ( T_3 ) V_94 -> V_67 ;
if ( V_90 -> V_197 != V_198 ) {
V_207 -> V_21 = V_381 ;
} else if ( V_94 -> V_333 == V_382 ) {
if ( V_90 -> V_193 == 0 ) {
V_207 -> V_21 = V_253 ;
} else {
* ( T_2 * ) V_94 -> V_338 = V_90 -> V_193 ;
V_94 -> V_340 = sizeof( T_2 ) ;
}
} else if ( V_94 -> V_333 == V_383 ) {
V_207 -> V_21 = V_337 ;
} else {
V_207 -> V_21 = V_341 ;
}
V_94 -> V_67 =
F_51 ( V_2 ,
( T_3 ) V_94 -> V_67 ) ;
break;
}
case V_384 :
case V_385 :
{
if ( F_49 ( V_2 , V_207 , V_4 , V_8 ) )
return true ;
break;
}
case V_386 :
{
struct V_387 * V_388 = & V_207 -> V_95 . V_389 ;
if ( V_207 -> V_72 & V_252 ) {
V_207 -> V_21 = V_253 ;
break;
}
if ( V_207 -> V_254 > V_390 ) {
V_207 -> V_21 = V_256 ;
V_207 -> V_254 = V_390 ;
break;
}
if ( V_388 -> V_391 == V_392 ) {
F_58 ( V_2 ) ;
} else if ( V_388 -> V_391 != V_393 ) {
V_207 -> V_21 = V_253 ;
break;
}
if ( V_2 -> V_72 & V_394 )
V_388 -> V_395 = V_396 ;
else if ( V_2 -> V_72 & V_397 )
V_388 -> V_395 = V_398 ;
else if ( V_2 -> V_72 & V_399 )
V_388 -> V_395 = V_400 ;
else if ( V_2 -> V_72 & V_401 )
V_388 -> V_395 = V_402 ;
else if ( V_2 -> V_72 & V_79 )
V_388 -> V_395 = V_403 ;
else
V_388 -> V_395 = V_404 ;
break;
}
case V_405 :
{
struct V_406 * V_106 = & V_207 -> V_95 . V_407 ;
struct V_89 * V_90 ;
if ( V_207 -> V_72 & V_252 ) {
if ( F_49 ( V_2 , V_207 , V_4 , V_8 ) )
return true ;
break;
}
if ( V_207 -> V_254 > V_408 ) {
V_207 -> V_21 = V_256 ;
V_207 -> V_254 = V_408 ;
break;
}
if ( V_106 -> V_67 >= V_310 ) {
V_207 -> V_21 = V_341 ;
break;
}
V_90 = V_2 -> V_195 + ( T_3 ) V_106 -> V_67 ;
V_106 -> V_67 =
F_51 ( V_2 ,
( T_3 ) V_106 -> V_67 ) ;
if ( V_90 -> V_197 != V_198 ) {
V_207 -> V_21 = V_381 ;
break;
}
V_207 -> V_21 = V_253 ;
break;
}
default:
V_207 -> V_21 = V_409 ;
break;
}
return false ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_55 )
{
struct V_206 * V_410 =
(struct V_206 * ) V_38 ;
F_10 ( L_7 , V_2 -> V_411 ) ;
if ( V_410 -> V_244 == V_245 ) {
struct V_248 * V_249 =
& V_410 -> V_95 . V_250 ;
F_10 ( L_8 ) ;
V_249 -> V_412 = V_204 ;
V_249 -> V_413 = V_205 ;
strcpy ( V_249 -> V_414 , V_203 ) ;
strcpy ( V_249 -> V_415 , V_416 ) ;
V_249 -> V_311 = 1 ;
V_249 -> V_312 = V_417 + 1 ;
V_249 -> V_313 = 1 ;
}
}
V_33 F_60 ( struct V_1 * V_2 ,
struct V_206 * V_410 )
{
struct V_38 V_43 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_2 = V_2 ;
V_43 . V_53 = V_410 ;
V_43 . V_48 = sizeof( struct V_206 ) + V_410 -> V_353 ;
V_43 . V_54 = F_52 ;
V_43 . V_55 = NULL ;
V_43 . V_57 = F_59 ;
V_43 . V_58 = NULL ;
V_43 . V_11 = 0 ;
return F_18 ( & V_43 ) ;
}
int F_61 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_418 * V_95 )
{
int V_44 = 0 ;
V_2 -> V_36 = 0 ;
V_4 -> V_34 = F_15 ;
if ( F_62 ( V_2 , V_4 , V_95 ) ) {
while ( ! V_2 -> V_36 )
F_12 ( V_2 -> V_37 ,
V_2 -> V_36 ) ;
;
if ( V_4 -> V_219 == V_220 )
V_44 = 1 ;
}
return V_44 ;
}
int F_63 ( void * V_419 , int V_420 , void T_4 * V_421 )
{
struct V_422 * V_53 = NULL ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_3 V_423 ;
int V_424 ;
F_19 ( V_425 , L_9 , V_419 , V_420 , V_421 ) ;
if ( ( V_421 == NULL )
|| ( V_420 < V_426 )
|| ( V_420 > V_427 ) )
return - V_428 ;
if ( ! F_64 ( V_429 , V_421 , sizeof( struct V_422 ) ) ) {
F_19 ( V_430 ,
L_10
L_11 , V_420 ,
V_421 ) ;
return - V_431 ;
}
V_53 = F_65 ( sizeof( struct V_422 ) , V_29 ) ;
if ( V_53 == NULL ) {
F_19 ( V_430 ,
L_12 ,
sizeof( struct V_422 ) ) ;
return - V_432 ;
}
V_424 = F_66 ( V_53 , V_421 , sizeof( struct V_422 ) ) ;
if ( V_424 != 0 ) {
F_19 ( V_430 ,
L_13 ,
V_424 ,
V_420 ) ;
F_67 ( V_53 ) ;
return - V_431 ;
}
if ( memcmp ( V_53 -> V_23 . V_433 ,
V_434 ,
V_435 ) != 0 ) {
F_19 ( V_430 , L_14 ) ;
F_67 ( V_53 ) ;
return - V_428 ;
}
V_53 -> V_23 . V_436 = V_45 ;
V_424 = 0 ;
if ( V_420 == V_437 ) {
int V_438 = 0 , V_439 = 0 ;
V_53 -> V_95 . V_440 . V_441 = 0 ;
while ( V_438 < V_442 ) {
if ( V_443 [ V_438 ] ) {
V_53 -> V_95 . V_440 . V_441 ++ ;
V_53 -> V_95 . V_440 . V_444 [ V_439 ] = V_438 ;
V_439 ++ ;
}
V_438 ++ ;
}
goto V_445;
}
if ( V_53 -> V_23 . V_444 == 0xFF ) {
V_2 = (struct V_1 * ) V_419 ;
} else {
V_2 = V_443 [ V_53 -> V_23 . V_444 ] ;
if ( V_53 -> V_23 . V_444 >= V_442 || ( V_2 == NULL ) ) {
V_53 -> V_23 . V_436 = V_446 ;
F_19 ( V_430 , L_15 ) ;
F_67 ( V_53 ) ;
return - V_428 ;
}
}
switch ( V_420 ) {
case V_447 :
if ( V_53 -> V_95 . V_448 . V_449 == V_450 ) {
V_424 = F_68 ( V_2 ,
( char * ) V_53 -> V_95 . V_448 . V_451 ,
0 ,
sizeof( struct
V_422 ) ) ;
if ( V_424 >= 0 ) {
V_424 = F_69 ( V_2 ,
( char * ) V_53 -> V_95 . V_448 .
V_451 ,
0 ,
sizeof( struct
V_422 ) ) ;
}
} else if ( V_53 -> V_95 . V_448 . V_449 == V_452 ) {
V_424 = F_70 ( V_2 ,
( char * ) V_53 -> V_95 . V_448 . V_451 ,
0 ,
sizeof( struct
V_422 ) ) ;
if ( V_424 >= 0 ) {
V_424 = F_71 ( V_2 ,
( char * ) V_53 -> V_95 . V_448 .
V_451 ,
0 ,
sizeof( struct
V_422 ) ) ;
}
} else {
V_53 -> V_23 . V_436 = V_453 ;
}
break;
case V_454 :
memcpy ( V_53 -> V_95 . V_455 . V_456 , V_2 -> V_339 ,
sizeof( struct V_418 ) ) ;
V_53 -> V_95 . V_455 . V_423 = 1 ;
break;
case V_457 :
V_4 = F_7 ( V_2 ) ;
if ( V_4 == NULL ) {
F_8 ( & V_2 -> V_458 ) ;
V_53 -> V_95 . V_455 . V_423 = 0 ;
break;
}
V_423 = F_61 ( V_2 , V_4 ,
(struct V_418 * ) V_53 -> V_95 . V_455 . V_456 ) ;
V_53 -> V_95 . V_455 . V_423 = V_423 ;
F_14 ( V_2 , V_4 ) ;
break;
case V_459 :
F_72 ( V_2 ,
(struct V_418 * ) V_53 -> V_95 . V_455 . V_456 ) ;
V_53 -> V_95 . V_455 . V_423 = 1 ;
break;
case V_460 :
V_53 -> V_95 . V_461 . V_139 = V_204 ;
V_53 -> V_95 . V_461 . V_141 = V_205 ;
V_53 -> V_95 . V_461 . V_462 = V_2 -> V_25 -> V_463 ;
V_53 -> V_95 . V_461 . V_260 = V_2 -> V_25 -> V_261 ;
V_53 -> V_95 . V_461 . V_258 = V_2 -> V_25 -> V_259 ;
V_53 -> V_95 . V_461 . V_464 = V_2 -> V_25 -> V_123 ;
V_53 -> V_95 . V_461 . V_465 = V_2 -> V_25 -> V_265 ;
V_53 -> V_95 . V_461 . V_466 = V_2 -> V_25 -> V_133 -> V_134 ;
V_53 -> V_95 . V_461 . V_467 = V_2 -> V_25 -> V_136 ;
V_53 -> V_95 . V_461 . V_468 = 0 ;
V_53 -> V_95 . V_461 . V_469 = V_2 -> V_470 -> V_469 ;
V_53 -> V_95 . V_461 . V_471 = 0 ;
break;
case V_472 :
V_53 -> V_23 . V_436 = F_25 ( V_2 ,
& V_53 -> V_95 .
V_473 ) ;
break;
case V_474 :
V_53 -> V_23 . V_436 =
F_48 ( V_2 , & V_53 -> V_95 . V_70 ) ;
break;
case V_475 :
V_53 -> V_23 . V_436 = F_60 ( V_2 ,
& V_53 -> V_95 .
V_410 ) ;
break;
case V_476 :
V_424 = F_73 ( V_2 ,
( char * ) & V_53 -> V_95 . V_477 ,
0 ,
sizeof( struct V_478 ) +
V_53 -> V_95 . V_477 . V_353 ) ;
if ( V_424 >= 0 ) {
V_424 = F_74 ( V_2 ,
( char * ) & V_53 -> V_95 . V_477 ,
0 ,
sizeof( struct V_478 ) +
V_53 -> V_95 . V_477 . V_353 ) ;
}
break;
case V_479 :
V_53 -> V_95 . V_480 . V_10 = V_2 ;
V_53 -> V_95 . V_480 . V_481 = V_2 -> V_25 ;
V_53 -> V_95 . V_480 . V_482 = V_2 -> V_470 ;
V_53 -> V_95 . V_480 . V_469 = V_2 -> V_470 -> V_469 ;
break;
default:
F_10 ( L_16 , V_420 ) ;
V_53 -> V_23 . V_436 = V_483 ;
}
V_445:
if ( V_424 < 0 ) {
F_19 ( V_430 , L_17 , V_424 ,
V_420 ) ;
switch ( V_424 ) {
case - V_432 :
case - V_484 :
V_53 -> V_23 . V_436 = V_47 ;
break;
case - V_485 :
case - V_486 :
V_53 -> V_23 . V_436 = V_487 ;
break;
}
V_53 -> V_23 . V_436 = V_488 ;
}
V_424 = F_75 ( V_421 , V_53 , sizeof( struct V_422 ) ) ;
if ( V_424 != 0 ) {
F_19 ( V_430 ,
L_18
L_19 , V_424 ,
V_420 ) ;
F_67 ( V_53 ) ;
return - V_431 ;
}
F_67 ( V_53 ) ;
return 0 ;
}
int F_76 ( struct V_489 * V_490 , int V_420 , void T_4 * V_421 )
{
return F_63 ( V_490 -> V_470 -> V_419 , V_420 , V_421 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_95 ) {
F_13 ( & V_2 -> V_25 -> V_26 ,
( V_27 ) V_2 -> V_14 . V_16 ,
V_2 -> V_14 . V_95 ,
( V_28 ) V_2 -> V_14 . V_15 ) ;
V_2 -> V_14 . V_95 = NULL ;
}
}
static int F_78 ( struct V_1 * V_2 , T_1 V_48 )
{
F_77 ( V_2 ) ;
V_2 -> V_14 . V_16 = V_48 ;
V_2 -> V_14 . V_95 = ( V_33 * ) F_9 ( & V_2 -> V_25 -> V_26 ,
( V_27 ) V_48 ,
( V_28 * ) & V_2 -> V_14 .
V_15 ,
V_29 ) ;
if ( ! V_2 -> V_14 . V_95 ) {
F_10 ( L_20 ) ;
return 0 ;
}
return 1 ;
}
int F_69 ( struct V_1 * V_2 , char * V_491 , long V_492 , int V_493 )
{
F_79 () ;
if ( V_2 -> V_14 . V_494 == V_495 ) {
int V_496 = F_80 ( int , V_493 , sizeof( V_2 -> V_14 . V_23 ) ) ;
F_81 () ;
memcpy ( V_491 , & V_2 -> V_14 . V_23 , V_496 ) ;
F_10 ( L_21 , V_496 ) ;
return V_496 ;
}
if ( V_2 -> V_14 . V_494 == V_497 ) {
T_1 V_48 = V_2 -> V_14 . V_23 . V_48 ;
F_81 () ;
F_10 ( L_22 ,
V_48 ,
V_492 ) ;
if ( V_492 == 0 ) {
if ( V_2 -> V_14 . V_23 . V_498 == V_499 ) {
if ( ! F_78 ( V_2 , V_48 ) )
return - V_432 ;
memcpy ( V_2 -> V_14 . V_95 ,
& V_2 -> V_14 . V_23 ,
sizeof( V_2 -> V_14 . V_23 ) ) ;
F_5 ( V_2 ,
(struct V_18 * ) V_2 -> V_14 . V_95 ) ;
} else if ( V_2 -> V_14 . V_23 . V_498 == V_500 ) {
int V_496 =
F_82 ( ( int ) V_493 ,
( int ) sizeof( V_2 -> V_14 . V_23 ) ) ;
F_5 ( V_2 , & V_2 -> V_14 . V_23 ) ;
memcpy ( V_491 , & V_2 -> V_14 . V_23 , V_496 ) ;
F_10 ( L_23 , V_496 ) ;
return V_496 ;
} else {
F_10 ( L_24 ,
V_2 -> V_14 . V_23 . V_498 ) ;
return - V_485 ;
}
}
if ( V_493 + V_492 > V_48 )
V_493 = V_48 - V_492 ;
if ( V_493 < 0 )
return 0 ;
if ( ! V_2 -> V_14 . V_95 ) {
F_10 (
L_25 ) ;
return - V_432 ;
}
F_10 ( L_26 , V_492 ,
V_493 ,
V_48 ) ;
memcpy ( V_491 , & V_2 -> V_14 . V_95 [ V_492 ] , V_493 ) ;
if ( V_48 <= V_492 + V_493 ) {
F_10 ( L_27 ) ;
F_77 ( V_2 ) ;
}
return V_493 ;
}
F_81 () ;
F_10 ( L_28 ,
V_2 -> V_14 . V_494 ) ;
return - V_486 ;
}
int F_68 ( struct V_1 * V_2 , const char * V_491 , long V_492 ,
int V_493 )
{
T_1 V_48 ;
if ( V_492 == 0 ) {
struct V_18 * V_23 =
(struct V_18 * ) V_491 ;
int V_501 = sizeof( struct V_502 ) ;
V_2 -> V_14 . V_494 = V_503 ;
if ( V_493 < 4
|| V_23 -> V_504 > V_505 ) {
F_10 (
L_29 ) ;
return - V_486 ;
}
if ( V_23 -> V_504 == V_505 )
V_501 = sizeof( struct V_18 ) ;
if ( V_493 < V_501 ) {
F_10 ( L_30 ) ;
return - V_486 ;
}
V_48 = V_23 -> V_48 ;
if ( V_48 > 1024 * 1024 ) {
F_10 (
L_31 ,
V_48 , V_23 -> V_504 ) ;
return - V_486 ;
}
if ( V_23 -> V_498 == V_506 ) {
if ( ! F_78 ( V_2 , V_48 ) )
return - V_432 ;
memcpy ( & V_2 -> V_14 . V_23 ,
V_491 ,
sizeof( * V_23 ) ) ;
} else if ( V_23 -> V_498 == V_499
|| V_23 -> V_498 == V_500 ) {
memcpy ( & V_2 -> V_14 . V_23 ,
V_491 ,
sizeof( * V_23 ) ) ;
V_2 -> V_14 . V_494 = V_497 ;
F_10 (
L_32 ,
V_493 , V_23 -> V_498 ) ;
return V_493 ;
} else {
F_10 ( L_33 ,
V_2 -> V_14 . V_23 . V_498 ) ;
return - V_485 ;
}
} else {
V_48 = V_2 -> V_14 . V_23 . V_48 ;
}
if ( V_492 + V_493 > V_48 )
V_493 = V_48 - V_492 ;
if ( V_493 > 0 ) {
F_10 ( L_34 , V_492 ,
V_493 ,
V_48 ) ;
if ( V_2 -> V_14 . V_23 . V_498 == V_499 )
return V_493 ;
if ( ! V_2 -> V_14 . V_95 ) {
F_10 (
L_35 ) ;
return - V_432 ;
}
memcpy ( & V_2 -> V_14 . V_95 [ V_492 ] , V_491 , V_493 ) ;
if ( V_48 == V_492 + V_493 ) {
F_5 ( V_2 ,
(struct V_18 * ) V_2 -> V_14 . V_95 ) ;
memcpy ( & V_2 -> V_14 . V_23 ,
V_2 -> V_14 . V_95 ,
sizeof( V_2 -> V_14 . V_23 ) ) ;
V_2 -> V_14 . V_494 = V_495 ;
F_10 ( L_36 ) ;
F_77 ( V_2 ) ;
}
}
return V_493 ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_507 = 1 ;
F_2 ( & V_2 -> V_508 ) ;
}
static T_1 F_84 ( struct V_7 * V_8 , T_2 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_10 ;
int V_11 = ( V_33 * ) V_8 -> V_12 - ( V_33 * ) V_2 -> V_509 ;
( * V_9 ) = V_2 -> V_510 + V_11 ;
return V_511 - V_11 ;
}
int F_74 ( struct V_1 * V_2 , char * V_491 , long V_492 , int V_493 )
{
if ( ! V_2 -> V_509 )
return - V_432 ;
if ( V_492 == 0 ) {
struct V_3 * V_4 ;
struct V_478 * V_512 =
(struct V_478 * ) V_2 -> V_509 ;
struct V_7 V_8 ;
bool V_513 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 == NULL ) {
F_10 ( L_37 ) ;
return - V_484 ;
}
V_4 -> V_34 = F_83 ;
V_8 . V_514 = V_4 ;
V_8 . V_10 = V_2 ;
V_8 . V_12 = V_2 -> V_509 + V_515 ;
V_8 . V_31 = ( V_32 ) F_84 ;
V_2 -> V_507 = 0 ;
V_513 =
F_85 ( V_2 , V_512 , V_4 , & V_8 ) ;
if ( V_513 ) {
while ( ! V_2 -> V_507 )
F_12 ( V_2 -> V_508 ,
V_2 -> V_507 ) ;
}
F_14 ( V_2 , (struct V_3 * ) V_4 ) ;
}
if ( V_492 > V_511 )
return 0 ;
if ( V_493 + V_492 > V_511 )
V_493 = V_511 - V_492 ;
if ( V_493 < 0 )
return 0 ;
memcpy ( V_491 , V_2 -> V_509 + V_492 , V_493 ) ;
return V_493 ;
}
int F_73 ( struct V_1 * V_2 , const char * V_491 , long V_492 ,
int V_493 )
{
if ( ! V_2 -> V_509 ) {
V_28 V_516 ;
V_2 -> V_509 = ( V_33 * ) F_9 ( & V_2 -> V_25 -> V_26 ,
( V_27 )
V_511 ,
& V_516 ,
V_29 ) ;
V_2 -> V_510 = V_516 ;
}
if ( ! V_2 -> V_509 )
return - V_432 ;
if ( V_492 > V_511 )
return 0 ;
if ( V_493 + V_492 > V_511 )
V_493 = V_511 - V_492 ;
if ( V_493 < 1 )
return 0 ;
memcpy ( V_2 -> V_509 + V_492 , V_491 , V_493 ) ;
return V_493 ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_517 = 1 ;
F_2 ( & V_2 -> V_518 ) ;
}
static T_1 F_87 ( struct V_7 * V_8 , T_2 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_10 ;
struct V_519 * V_520 =
(struct V_519 * ) V_2 -> V_521 ;
T_1 V_11 = ( V_33 * ) V_8 -> V_12 - ( V_33 * ) V_520 ;
( * V_9 ) = V_2 -> V_522 + V_11 ;
return V_2 -> V_523 - V_11 ;
}
int F_71 ( struct V_1 * V_2 , char * V_491 , long V_492 , int V_493 )
{
if ( ! V_2 -> V_521 )
return - V_432 ;
if ( V_492 == 0 ) {
struct V_3 * V_4 ;
struct V_7 V_8 ;
struct V_519 * V_520 =
(struct V_519 * ) V_2 -> V_521 ;
if ( F_6 ( & V_2 -> V_524 ) ) {
V_525:
V_520 -> V_21 = V_64 ;
return - V_484 ;
}
V_4 = F_7 ( V_2 ) ;
if ( V_4 == NULL ) {
F_10 ( L_38 ) ;
F_8 ( & V_2 -> V_524 ) ;
goto V_525;
}
V_4 -> V_34 = F_86 ;
V_8 . V_12 = V_520 -> V_95 ;
V_8 . V_31 = ( V_32 ) F_87 ;
V_2 -> V_517 = 0 ;
if ( ! F_88 ( V_2 , V_520 , V_4 , & V_8 ) ) {
if ( V_520 -> V_21 == V_64 )
V_493 = - V_484 ;
goto V_526;
}
while ( ! V_2 -> V_517 )
F_12 ( V_2 -> V_518 ,
V_2 -> V_517 ) ;
;
V_526:
F_8 ( & V_2 -> V_524 ) ;
F_14 ( V_2 , (struct V_3 * ) V_4 ) ;
if ( V_493 < 0 )
return V_493 ;
}
if ( V_492 > V_2 -> V_523 )
return 0 ;
if ( V_493 + V_492 > V_2 -> V_523 )
V_493 = V_2 -> V_523 - V_492 ;
if ( V_493 < 0 )
return 0 ;
memcpy ( V_491 , V_2 -> V_521 + V_492 , V_493 ) ;
return V_493 ;
}
int F_70 ( struct V_1 * V_2 , const char * V_491 , long V_492 ,
int V_493 )
{
if ( V_492 == 0 ) {
struct V_519 * V_520 = (struct V_519 * ) V_491 ;
T_1 V_48 = V_520 -> V_527 . V_48 + F_57 (
struct V_519 ,
V_95 ) ;
if ( V_520 -> V_527 . V_527 == V_528 )
V_48 = F_57 ( struct V_519 , V_95 ) ;
if ( V_493 < F_57 ( struct V_519 , V_95 ) )
return - V_486 ;
if ( V_2 -> V_521 ) {
if ( V_2 -> V_523 < V_48 ) {
F_13 ( & V_2 -> V_25 -> V_26 ,
( V_27 ) V_2 -> V_523 ,
V_2 -> V_521 ,
( V_28 ) V_2 -> V_522 ) ;
goto V_529;
}
} else {
V_529:
V_2 -> V_523 = V_48 ;
V_2 -> V_521 = ( V_33 * ) F_9 (
& V_2 -> V_25 -> V_26 ,
( V_27 ) V_2 -> V_523 ,
( V_28 * ) & V_2 -> V_522 ,
V_29 ) ;
}
}
if ( ! V_2 -> V_521 )
return - V_432 ;
if ( V_492 > V_2 -> V_523 )
return 0 ;
if ( V_493 + V_492 > V_2 -> V_523 )
V_493 = V_2 -> V_523 - V_492 ;
if ( V_493 < 1 )
return 0 ;
memcpy ( V_2 -> V_521 + V_492 , V_491 , V_493 ) ;
return V_493 ;
}
