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
V_19 -> V_21 = V_22 ;
goto V_23;
}
if ( V_19 == & V_2 -> V_14 . V_24 ) {
V_2 -> V_14 . V_25 = F_8 ( & V_2 -> V_26 -> V_27 ,
( V_28 ) sizeof(
struct
V_18 ) ,
( V_29 * ) & V_2 ->
V_14 .
V_17 ,
V_30 ) ;
if ( V_2 -> V_14 . V_25 == NULL ) {
F_9 ( L_1 ) ;
V_19 -> V_21 = V_22 ;
goto V_31;
}
memcpy ( V_2 -> V_14 . V_25 , V_19 ,
sizeof( struct V_18 ) ) ;
V_2 -> V_13 = V_2 -> V_14 . V_25 ;
V_2 -> V_32 . V_33 =
( V_34 ) F_4 ;
} else {
V_2 -> V_13 = ( V_35 * ) V_19 ;
V_2 -> V_32 . V_33 =
( V_34 ) F_3 ;
}
V_4 -> V_36 = F_1 ;
V_2 -> V_5 = 0 ;
V_2 -> V_32 . V_12 = V_2 -> V_13 ;
if ( ! F_10 ( V_2 , (struct V_18 * ) V_2 -> V_13 , V_4 ,
& V_2 -> V_32 ) )
goto V_37;
while ( ! V_2 -> V_5 )
F_11 ( V_2 -> V_6 ,
V_2 -> V_5 ) ;
V_37:
if ( V_19 == & V_2 -> V_14 . V_24 ) {
memcpy ( V_19 , V_2 -> V_14 . V_25 ,
sizeof( struct V_18 ) ) ;
F_12 ( & V_2 -> V_26 -> V_27 ,
( V_28 ) sizeof( struct V_18 ) ,
V_2 -> V_14 . V_25 ,
( V_29 ) V_2 -> V_14 . V_17 ) ;
}
V_31:
F_13 ( V_2 , (struct V_3 * ) V_4 ) ;
V_23:
F_14 ( & V_2 -> V_20 ) ;
return;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_38 = 1 ;
F_2 ( & V_2 -> V_39 ) ;
}
static T_1 F_16 ( struct V_7 * V_8 ,
T_2 * V_9 )
{
int V_11 = ( V_35 * ) V_8 -> V_12 - V_40 ;
( * V_9 ) = V_41 + V_11 ;
return V_42 - V_11 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_43 = 1 ;
F_2 ( & V_2 -> V_44 ) ;
}
static V_35 F_18 ( struct V_40 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_3 * V_4 ;
struct V_7 V_8 ;
V_35 V_46 = V_47 ;
if ( F_6 ( & V_48 ) )
return V_49 ;
if ( V_40 ) {
if ( V_42 < V_45 -> V_50 ) {
F_12 ( & V_2 -> V_26 -> V_27 ,
( V_28 ) V_42 ,
V_40 ,
V_41 ) ;
goto V_51;
}
} else {
V_51:
V_42 = V_45 -> V_50 ;
V_52 = V_2 -> V_26 ;
V_40 = F_8 ( & V_2 -> V_26 -> V_27 ,
( V_28 )
V_42 ,
&
V_41 ,
V_30 ) ;
}
if ( ! V_40 ) {
F_19 ( V_53 ,
L_2
L_3 ,
V_45 -> V_50 ) ;
F_9 ( L_4 ) ;
V_46 = V_49 ;
goto V_54;
}
memcpy ( V_40 , V_45 -> V_55 , V_45 -> V_50 ) ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 == NULL ) {
F_19 ( V_53 ,
L_5 ) ;
V_46 = V_49 ;
F_9 ( L_6 ) ;
goto V_54;
}
V_2 -> V_43 = 0 ;
V_4 -> V_36 = F_17 ;
V_8 . V_12 = V_40 + V_45 -> V_11 ;
V_8 . V_33 = ( V_34 ) F_16 ;
V_8 . V_50 = V_42 ;
if ( ! (* V_45 -> V_56 )( V_2 , V_4 , & V_8 , V_45 -> V_57 ) ) {
V_2 -> V_43 = 0 ;
goto V_58;
}
while ( ! V_2 -> V_43 )
F_11 ( V_2 -> V_44 ,
V_2 -> V_43 ) ;
V_58:
if ( V_46 == V_47 && V_45 -> V_59 )
(* V_45 -> V_59 )( V_2 , V_4 , V_45 -> V_60 ) ;
F_13 ( V_2 , V_4 ) ;
V_54:
if ( V_46 == V_47 )
memcpy ( V_45 -> V_55 , V_40 , V_45 -> V_50 ) ;
F_14 ( & V_48 ) ;
return V_46 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_7 * V_8 , void * V_57 )
{
struct V_61 * V_62 =
(struct V_61 * ) V_40 ;
F_21 ( V_8 , V_2 , V_4 , V_4 -> V_63 -> V_55 . V_64 ) ;
F_22 ( V_2 , V_4 , V_8 -> V_50 , V_65 ) ;
if ( ! F_23 ( V_2 , V_4 , V_8 ) ) {
V_62 -> V_21 = V_66 ;
return false ;
}
F_24 ( V_2 , V_4 ) ;
return true ;
}
static V_35 F_25 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
struct V_40 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_2 = V_2 ;
V_45 . V_55 = V_62 ;
V_45 . V_50 = sizeof( struct V_61 )
+ F_26 ( V_62 -> V_67 )
+ F_26 ( V_62 -> V_68 ) ;
V_45 . V_11 = 0 ;
V_45 . V_56 = F_20 ;
return F_18 ( & V_45 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_69 = F_28 ( V_4 -> V_70 . V_71 . V_72 . V_69 ) ;
V_4 -> V_63 -> V_73 . V_74 |= F_29 ( V_4 -> V_70 . V_71 . V_72 . V_75 ) ;
(* V_4 -> V_76 )( V_2 , V_4 ) ;
}
static bool F_30 ( struct V_1 * V_2 ,
union V_77 * V_78 ,
struct V_3 * V_4 ,
struct V_7 * V_8 ,
T_1 V_79 ,
T_3 V_69 )
{
struct V_80 * V_55 = & V_4 -> V_63 -> V_55 ;
if ( F_31 ( V_81 , & V_2 -> V_74 ) )
return false ;
F_21 ( V_8 , V_2 , V_4 , V_4 -> V_63 -> V_55 . V_64 ) ;
F_22 ( V_2 , V_4 , V_8 -> V_50 , V_82 ) ;
V_55 -> V_72 . V_79 = F_29 ( V_79 ) ;
V_55 -> V_72 . V_69 = F_32 ( V_69 ) ;
V_55 -> V_72 . V_75 = ( V_35 ) F_26 ( V_4 -> V_63 -> V_73 . V_74 ) ;
V_4 -> V_83 = V_78 ;
V_4 -> V_76 = V_4 -> V_36 ;
V_4 -> V_36 = F_27 ;
if ( ! F_23 ( V_2 , V_4 , V_8 ) )
return false ;
F_24 ( V_2 , V_4 ) ;
return true ;
}
static bool F_33 ( struct V_84 V_75 )
{
bool V_46 ;
V_46 = ( ( V_75 . V_84 [ 7 ] == 0 ) &&
( V_75 . V_84 [ 6 ] == 0 ) &&
( V_75 . V_84 [ 5 ] == 0 ) &&
( V_75 . V_84 [ 4 ] == 0 ) &&
( V_75 . V_84 [ 3 ] == 0 ) &&
( V_75 . V_84 [ 2 ] == 0 ) &&
( V_75 . V_84 [ 0 ] == 0 ) ) ;
return V_46 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_7 * V_8 , void * V_57 )
{
struct V_85 * V_78 = (struct V_85 * ) V_57 ;
union V_77 * V_86 =
(union V_77 * ) V_40 ;
V_35 V_87 = 0 ;
V_35 V_88 = 0 ;
V_35 V_75 = 0 ;
T_1 V_89 = V_90 ;
struct V_91 * V_92 ;
unsigned long V_74 ;
if ( V_78 -> V_93 == V_94 ) {
struct V_95 * V_96 = & V_78 -> V_97 . V_98 ;
V_87 = V_96 -> V_99 ;
V_88 = V_96 -> V_69 ;
V_75 = V_96 -> V_75 ;
} else if ( V_78 -> V_93 == V_100 ) {
struct V_101 * V_102 = & V_78 -> V_97 . V_103 ;
V_87 = V_102 -> V_99 ;
V_88 = V_102 -> V_69 ;
V_75 = V_102 -> V_75 ;
}
if ( V_87 > 0 ) {
V_4 -> V_70 . V_71 . V_72 . V_104 = F_29 (
V_105 ) ;
return false ;
}
V_4 -> V_69 = V_88 ;
V_4 -> V_63 -> V_73 . V_74 |= F_29 ( V_75 ) ;
switch ( V_78 -> V_93 ) {
case V_106 :
{
struct V_107 * V_108 = & V_86 -> V_109 ;
strcpy ( V_108 -> V_110 , F_35 ( V_2 ) ) ;
V_108 -> V_111 = V_112 ;
V_108 -> V_113 = V_114 ;
break;
}
case V_115 :
{
struct V_116 * V_117 = & V_86 -> V_118 ;
V_117 -> V_119 = 0 ;
F_36 ( V_2 -> V_26 , V_120 ,
& V_117 -> V_121 ) ;
F_36 ( V_2 -> V_26 , V_122 ,
& V_117 -> V_123 ) ;
V_117 -> V_124 = F_37 ( V_2 -> V_26 -> V_125 ,
V_2 -> V_26 -> V_126 ) ;
V_117 -> V_127 = V_128 ;
V_117 -> V_129 = V_130 ;
V_117 -> V_131 = V_132 ;
V_117 -> V_133 . V_134 = V_2 -> V_26 -> V_135 -> V_136 ;
V_117 -> V_133 . V_137 = F_38 ( V_2 -> V_26 -> V_138 ) ;
V_117 -> V_133 . V_139 = F_39 ( V_2 -> V_26 -> V_138 ) ;
memset ( V_117 -> V_140 , 0 , sizeof( V_117 -> V_140 ) ) ;
V_117 -> V_141 = F_40 ( F_41 ( V_2 -> V_142 ) ) ;
V_117 -> V_143 = F_42 ( F_41 ( V_2 -> V_142 ) ) ;
V_117 -> V_144 = F_40 ( F_43 ( V_2 -> V_142 ) ) ;
V_117 -> V_145 = F_42 ( F_43 ( V_2 -> V_142 ) ) ;
V_117 -> V_146 = F_42 ( F_43 ( V_2 -> V_147 ) ) ;
V_117 -> V_148 = F_40 ( F_43 ( V_2 -> V_147 ) ) ;
V_117 -> V_149 = F_41 ( V_2 -> V_147 ) ;
if ( F_31 ( V_150 , & V_2 -> V_151 ) )
V_117 -> V_152 = V_153
| V_154 ;
else
V_117 -> V_152 = V_155
| V_156 ;
V_117 -> V_157 = 0 ;
V_117 -> V_158 = 0 ;
V_117 -> V_159 = 0 ;
V_117 -> V_160 = 0 ;
V_117 -> V_161 = 0 ;
V_117 -> V_162 = 0 ;
V_117 -> V_163 = 0 ;
V_117 -> V_164 = 0 ;
break;
}
case V_165 :
{
struct V_166 * V_167 = & V_86 -> V_168 ;
if ( F_31 ( V_81 , & V_2 -> V_74 ) )
V_167 -> V_21 = V_169 ;
else
V_167 -> V_21 = V_170 ;
V_167 -> V_171 = V_172 ;
break;
}
case V_173 :
case V_174 :
case V_175 :
V_89 = V_176 ;
break;
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
if ( ! F_30 ( V_2 , V_86 , V_4 , V_8 ,
V_78 -> V_93 ,
V_186 ) ) {
V_89 = V_187 ;
break;
}
return true ;
case V_188 :
{
struct V_189 * V_190 = & V_86 -> V_191 ;
struct V_84 V_75 ;
memcpy ( & V_75 , V_190 -> V_192 , sizeof( struct V_84 ) ) ;
if ( ! F_33 ( V_75 ) ) {
V_89 = V_193 ;
break;
}
F_44 ( & V_2 -> V_194 , V_74 ) ;
V_92 = F_45 ( V_2 , ( T_2 * ) V_190 -> V_195 ) ;
F_46 ( & V_2 -> V_194 , V_74 ) ;
if ( V_92 == NULL ) {
V_89 = V_193 ;
break;
}
V_190 -> V_196 = 0xFF ;
V_190 -> V_75 = V_190 -> V_192 [ 1 ] ;
V_4 -> V_69 = F_47 ( V_92 , V_2 ) ;
break;
}
case V_94 :
{
struct V_95 * V_96 = & V_86 -> V_98 ;
V_92 = V_2 -> V_197 + V_4 -> V_69 ;
if ( V_92 >= V_2 -> V_198
|| V_92 -> V_199 != V_200
|| V_92 -> V_195 == 0 ) {
V_89 = V_201 ;
break;
}
* ( T_2 * ) V_96 -> V_195 = V_92 -> V_195 ;
memset ( V_96 -> V_192 , 0 , sizeof( V_96 -> V_192 ) ) ;
V_96 -> V_192 [ 1 ] = ( V_35 ) F_26 ( V_4 -> V_63 -> V_73 . V_74 ) ;
break;
}
case V_100 :
V_92 = V_2 -> V_197 + V_4 -> V_69 ;
if ( V_92 >= V_2 -> V_198
|| V_92 -> V_199 != V_200
|| ! ( V_92 -> V_74 & V_202 ) ) {
V_89 = V_201 ;
break;
}
if ( ! F_30 ( V_2 , V_86 , V_4 , V_8 ,
V_78 -> V_93 ,
V_92 -> V_203 ) ) {
V_89 = V_187 ;
break;
}
return true ;
default:
V_89 = V_176 ;
break;
}
V_4 -> V_70 . V_71 . V_72 . V_104 = F_29 ( V_89 ) ;
return false ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_57 )
{
struct V_85 * V_78 = (struct V_85 * ) V_57 ;
union V_77 * V_86 =
(union V_77 * ) V_40 ;
switch ( V_78 -> V_93 ) {
case V_106 :
{
struct V_107 * V_108 =
& V_86 -> V_109 ;
strcpy ( V_108 -> V_204 , V_205 ) ;
V_108 -> V_141 = V_206 ;
V_108 -> V_143 = V_207 ;
V_108 -> V_144 = 0 ;
V_108 -> V_145 = 0 ;
break;
}
case V_188 :
{
struct V_189 * V_190 = & V_86 -> V_191 ;
if ( F_26 ( V_4 -> V_70 . V_71 . V_72 . V_104 ) ==
V_90 ) {
V_190 -> V_69 = V_4 -> V_69 ;
V_190 -> V_99 = 0 ;
}
break;
}
}
V_78 -> V_21 = F_26 ( V_4 -> V_70 . V_71 . V_72 . V_104 ) ;
}
static V_35 F_49 ( struct V_1 * V_2 , struct V_85 * V_78 )
{
struct V_40 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_2 = V_2 ;
V_45 . V_55 = & V_78 -> V_97 ;
V_45 . V_50 = sizeof( union V_77 ) ;
V_45 . V_11 = 0 ;
V_45 . V_56 = F_34 ;
V_45 . V_57 = V_78 ;
V_45 . V_59 = F_48 ;
V_45 . V_60 = V_78 ;
return F_18 ( & V_45 ) ;
}
static bool F_50 ( struct V_1 * V_2 ,
struct V_208 * V_209 ,
struct V_3 * V_4 ,
struct V_7 * V_8 )
{
F_21 ( V_8 , V_2 , V_4 , V_4 -> V_63 -> V_55 . V_64 ) ;
F_22 ( V_2 , V_4 , V_8 -> V_50 , V_210 ) ;
if ( ! F_23 ( V_2 , V_4 , V_8 ) ) {
V_209 -> V_21 = V_66 ;
return false ;
}
F_24 ( V_2 , V_4 ) ;
return true ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_208 * V_209 = (struct V_208 * ) V_4 -> V_83 ;
struct V_211 * V_212 = & V_209 -> V_97 . V_213 ;
V_35 V_89 = V_214 ;
V_212 -> V_215 = V_4 -> V_70 . V_216 . V_217 ;
V_212 -> V_218 = V_4 -> V_219 ;
V_212 -> V_220 =
F_26 ( V_4 -> V_70 . V_216 . V_220 ) ;
switch ( V_4 -> V_221 ) {
case V_222 :
case V_223 :
V_89 = V_224 ;
break;
case V_225 :
V_89 = V_226 ;
break;
case V_227 :
V_89 = V_228 ;
break;
case V_229 :
case V_230 :
V_89 = V_231 ;
break;
case V_232 :
V_89 = V_233 ;
break;
case V_234 :
V_89 = V_235 ;
break;
case V_236 :
V_89 = V_237 ;
break;
case V_238 :
V_89 = V_239 ;
break;
case V_240 :
V_89 = V_241 ;
break;
case V_242 :
V_89 = V_243 ;
break;
}
V_212 -> V_244 = V_89 ;
V_212 -> V_69 =
F_52 ( V_2 , ( T_3 ) V_212 -> V_69 ) ;
(* V_4 -> V_76 )( V_2 , V_4 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_7 * V_8 ,
void * V_57 )
{
struct V_208 * V_209 = (struct V_208 * ) V_40 ;
V_209 -> V_21 = V_245 ;
switch ( V_209 -> V_246 ) {
case V_247 :
{
V_35 * V_248 = ( V_35 * ) & V_2 -> V_26 -> V_249 ;
struct V_250 * V_251 =
& V_209 -> V_97 . V_252 ;
int V_253 ;
if ( V_209 -> V_74 & V_254 ) {
V_209 -> V_21 = V_255 ;
break;
}
if ( V_209 -> V_256 > V_257 ) {
V_209 -> V_21 = V_258 ;
V_209 -> V_256 = V_257 ;
break;
}
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
V_251 -> V_259 . V_260 = V_2 -> V_26 -> V_261 ;
V_251 -> V_259 . V_262 = V_2 -> V_26 -> V_263 ;
V_251 -> V_259 . V_264 = V_2 -> V_26 -> V_126 ;
V_251 -> V_259 . V_265 = V_2 -> V_26 -> V_125 ;
V_251 -> V_259 . V_248 [ 0 ] = V_248 [ 0 ] ;
V_251 -> V_259 . V_248 [ 1 ] = V_248 [ 1 ] ;
V_251 -> V_259 . V_248 [ 2 ] = V_248 [ 2 ] ;
V_251 -> V_259 . V_266 = V_2 -> V_26 -> V_267 ;
V_251 -> V_259 . V_134 = V_2 -> V_26 -> V_135 -> V_136 ;
V_251 -> V_259 . V_268 = F_38 ( V_2 -> V_26 -> V_138 ) ;
V_251 -> V_259 . V_269 = F_39 ( V_2 -> V_26 -> V_138 ) ;
V_253 = F_54 ( V_2 -> V_26 , V_270 ) ;
if ( V_253 ) {
T_3 V_271 ;
T_1 V_272 ;
F_55 ( V_2 -> V_26 ,
V_253 + V_273 ,
& V_271 ) ;
F_36 ( V_2 -> V_26 ,
V_253 + V_274 ,
& V_272 ) ;
V_251 -> V_259 . V_275 =
( V_35 ) ( V_271 & V_276 ) ;
V_251 -> V_259 . V_277 =
( V_35 ) ( V_272 & V_278 ) ;
V_251 -> V_259 . V_279 =
( V_35 ) ( ( V_271 & V_280 )
>> V_281 ) ;
V_251 -> V_259 . V_282 =
( V_35 ) ( ( V_272 & V_283 )
>> 4 ) ;
}
V_251 -> V_259 . V_284 = 1 ;
if ( V_2 -> V_26 -> V_285 )
V_251 -> V_259 . V_286 = V_287 ;
else if ( V_2 -> V_26 -> V_288 )
V_251 -> V_259 . V_286 = V_289 ;
else
V_251 -> V_259 . V_286 = V_290 ;
V_251 -> V_291 = V_292 ;
if ( F_31 ( V_150 , & V_2 -> V_151 ) )
V_251 -> V_291 = V_293 ;
if ( F_31 ( V_81 , & V_2 -> V_74 ) )
V_251 -> V_294 |= V_295 ;
V_251 -> V_294 |= V_296 |
V_297 ;
if ( V_2 -> V_26 -> V_125 == V_298
|| V_2 -> V_26 -> V_125 == V_299
|| V_2 -> V_26 -> V_125 == V_300
|| V_2 -> V_26 -> V_125 == V_301 )
V_251 -> V_294 |= V_302 ;
V_251 -> V_303 = V_304 ;
V_251 -> V_305 = V_304 ;
strcpy ( V_251 -> V_306 , V_2 -> V_307 ) ;
strcpy ( V_251 -> V_308 , V_2 -> V_308 ) ;
strcpy ( V_251 -> V_309 , F_56 ( V_2 ) ) ;
strcpy ( V_251 -> V_310 , F_35 ( V_2 ) ) ;
V_251 -> V_311 = V_312 ;
V_251 -> V_313 = 1 ;
V_251 -> V_314 = V_251 -> V_311 ;
V_251 -> V_315 = 256 ;
if ( V_2 -> V_26 -> V_125 == V_316
|| V_2 -> V_26 -> V_125 == V_298 )
V_251 -> V_317 = 4 ;
else
V_251 -> V_317 = 2 ;
V_251 -> V_318 |= V_319 ;
V_251 -> V_320 = V_2 -> V_320 ;
V_251 -> V_321 = V_2 -> V_322
& ( V_323
| V_324
| V_325
| V_326
| V_327
| V_328
| V_329 ) ;
break;
}
case V_330 :
{
struct V_331 * V_332 =
& V_209 -> V_97 . V_333 ;
if ( V_209 -> V_74 & V_254 ) {
V_209 -> V_21 = V_255 ;
break;
}
if ( V_209 -> V_256 > V_334 ) {
V_209 -> V_21 = V_258 ;
V_209 -> V_256 = V_334 ;
} else if ( V_332 -> V_335 == V_336
|| V_332 -> V_335 == V_337 ) {
if ( V_332 -> V_335 == V_336
&& V_332 -> V_338 >= V_304 ) {
V_209 -> V_21 = V_339 ;
} else {
memcpy ( ( T_2 * ) V_332 -> V_340 ,
& V_2 -> V_341 -> V_195 [ 0 ] , sizeof( T_2 ) ) ;
V_332 -> V_342 = sizeof( T_2 ) ;
}
} else {
V_209 -> V_21 = V_343 ;
}
break;
}
case V_344 :
{
if ( V_209 -> V_74 & V_254 ) {
if ( F_50 ( V_2 , V_209 , V_4 , V_8 ) )
return true ;
break;
}
V_209 -> V_21 = V_255 ;
break;
}
case V_345 :
{
struct V_346 * V_347 = & V_209 -> V_97 . V_348 ;
if ( V_209 -> V_74 & V_254 ) {
if ( F_50 ( V_2 , V_209 , V_4 , V_8 ) )
return true ;
break;
}
if ( V_209 -> V_256 > V_349 ) {
V_209 -> V_21 = V_258 ;
V_209 -> V_256 = V_349 ;
break;
}
if ( V_347 -> V_350 == V_351
&& V_209 -> V_256 >= V_349 ) {
if ( V_347 -> V_352 == V_353 ) {
T_1 V_354 = V_209 -> V_355 ;
T_1 V_11 = V_347 -> V_356 ;
T_1 V_357 = V_358 ;
if ( ! F_31 ( V_359 , & V_2 -> V_151 ) )
V_357 = 0 ;
if ( V_354 > V_357 )
V_354 = V_357 ;
if ( V_11 >= V_357
|| V_11 + V_354 > V_357
|| V_354 == 0 ) {
V_209 -> V_21 = V_343 ;
break;
}
memcpy ( V_347 + 1 ,
V_2 -> V_360 + V_11 ,
V_354 ) ;
V_209 -> V_355 = V_354 ;
} else if ( V_347 -> V_352 == V_361 ) {
memset ( V_2 -> V_360 , 0 ,
V_358 ) ;
F_57 ( V_359 , & V_2 -> V_151 ) ;
} else if ( V_347 -> V_352 != V_362 ) {
V_209 -> V_21 = V_255 ;
break;
}
V_347 -> V_363 = 0 ;
V_347 -> V_356 = 0 ;
V_347 -> V_364 = V_358 ;
if ( ! F_31 ( V_359 , & V_2 -> V_151 ) )
V_347 -> V_364 = 0 ;
} else {
V_209 -> V_21 = V_255 ;
}
break;
}
case V_365 :
{
struct V_211 * V_212 = & V_209 -> V_97 . V_213 ;
struct V_84 V_75 ;
memcpy ( & V_75 , V_212 -> V_75 , sizeof( struct V_84 ) ) ;
if ( V_209 -> V_74 & V_254 ) {
if ( F_50 ( V_2 , V_209 , V_4 , V_8 ) )
return true ;
break;
}
if ( V_209 -> V_256 > V_366 ) {
V_209 -> V_21 = V_258 ;
V_209 -> V_256 = V_366 ;
break;
}
if ( V_212 -> V_69 >= V_312 || ! F_33 ( V_75 ) ) {
V_209 -> V_21 = V_343 ;
break;
}
F_21 ( V_8 , V_2 , V_4 , NULL ) ;
V_8 -> V_50 = V_209 -> V_355 ;
V_8 -> V_12 += F_58 ( struct V_208 , V_97 . V_367 )
+ sizeof( struct V_211 ) ;
V_4 -> V_69 = ( T_3 ) V_212 -> V_69 ;
V_4 -> V_63 -> V_73 . V_74 |= F_29 ( V_212 -> V_75 [ 1 ] ) ;
memcpy ( V_4 -> V_63 -> V_73 . V_368 , V_212 -> V_368 , 16 ) ;
V_4 -> V_63 -> V_73 . V_50 = F_29 ( V_209 -> V_355 ) ;
V_4 -> V_219 = V_212 -> V_218 ;
V_4 -> V_369 = ( V_35 * ) V_212 -> V_370 ;
V_4 -> V_83 = V_209 ;
V_4 -> V_76 = V_4 -> V_36 ;
V_4 -> V_36 = F_51 ;
if ( V_212 -> V_74 & V_371 ) {
V_4 -> V_63 -> V_73 . V_74 |= F_29 ( V_372 ) ;
} else if ( V_212 -> V_74 & V_373 ) {
V_4 -> V_63 -> V_73 . V_74 |= F_29 ( V_374 ) ;
} else {
if ( V_8 -> V_50 ) {
V_209 -> V_21 = V_343 ;
break;
}
}
if ( V_212 -> V_74 & V_375 )
V_4 -> V_63 -> V_73 . V_74 |=
F_29 ( V_376 ) ;
else if ( V_212 -> V_74 & V_377 )
V_4 -> V_63 -> V_73 . V_74 |= F_29 ( V_378 ) ;
if ( ! F_23 ( V_2 , V_4 , V_8 ) ) {
V_209 -> V_21 = V_66 ;
break;
}
F_24 ( V_2 , V_4 ) ;
return true ;
}
case V_379 :
{
struct V_380 * V_96 =
& V_209 -> V_97 . V_381 ;
struct V_91 * V_92 ;
if ( V_209 -> V_74 & V_254 ) {
if ( F_50 ( V_2 , V_209 , V_4 , V_8 ) )
return true ;
break;
}
if ( V_209 -> V_256 > V_382 ) {
V_209 -> V_21 = V_258 ;
V_209 -> V_256 = V_382 ;
break;
}
if ( V_96 -> V_69 >= V_312 ) {
V_209 -> V_21 = V_343 ;
break;
}
V_92 = V_2 -> V_197 + ( T_3 ) V_96 -> V_69 ;
if ( V_92 -> V_199 != V_200 ) {
V_209 -> V_21 = V_383 ;
} else if ( V_96 -> V_335 == V_384 ) {
if ( V_92 -> V_195 == 0 ) {
V_209 -> V_21 = V_255 ;
} else {
* ( T_2 * ) V_96 -> V_340 = V_92 -> V_195 ;
V_96 -> V_342 = sizeof( T_2 ) ;
}
} else if ( V_96 -> V_335 == V_385 ) {
V_209 -> V_21 = V_339 ;
} else {
V_209 -> V_21 = V_343 ;
}
V_96 -> V_69 =
F_52 ( V_2 ,
( T_3 ) V_96 -> V_69 ) ;
break;
}
case V_386 :
case V_387 :
{
if ( F_50 ( V_2 , V_209 , V_4 , V_8 ) )
return true ;
break;
}
case V_388 :
{
struct V_389 * V_390 = & V_209 -> V_97 . V_391 ;
if ( V_209 -> V_74 & V_254 ) {
V_209 -> V_21 = V_255 ;
break;
}
if ( V_209 -> V_256 > V_392 ) {
V_209 -> V_21 = V_258 ;
V_209 -> V_256 = V_392 ;
break;
}
if ( V_390 -> V_393 == V_394 ) {
F_59 ( V_2 ) ;
} else if ( V_390 -> V_393 != V_395 ) {
V_209 -> V_21 = V_255 ;
break;
}
if ( F_31 ( V_396 , & V_2 -> V_74 ) )
V_390 -> V_397 = V_398 ;
else if ( F_31 ( V_399 , & V_2 -> V_74 ) )
V_390 -> V_397 = V_400 ;
else if ( F_31 ( V_401 , & V_2 -> V_74 ) )
V_390 -> V_397 = V_402 ;
else if ( F_31 ( V_403 , & V_2 -> V_74 ) )
V_390 -> V_397 = V_404 ;
else if ( F_31 ( V_81 , & V_2 -> V_74 ) )
V_390 -> V_397 = V_405 ;
else
V_390 -> V_397 = V_406 ;
break;
}
case V_407 :
{
struct V_408 * V_108 = & V_209 -> V_97 . V_409 ;
struct V_91 * V_92 ;
if ( V_209 -> V_74 & V_254 ) {
if ( F_50 ( V_2 , V_209 , V_4 , V_8 ) )
return true ;
break;
}
if ( V_209 -> V_256 > V_410 ) {
V_209 -> V_21 = V_258 ;
V_209 -> V_256 = V_410 ;
break;
}
if ( V_108 -> V_69 >= V_312 ) {
V_209 -> V_21 = V_343 ;
break;
}
V_92 = V_2 -> V_197 + ( T_3 ) V_108 -> V_69 ;
V_108 -> V_69 =
F_52 ( V_2 ,
( T_3 ) V_108 -> V_69 ) ;
if ( V_92 -> V_199 != V_200 ) {
V_209 -> V_21 = V_383 ;
break;
}
V_209 -> V_21 = V_255 ;
break;
}
default:
V_209 -> V_21 = V_411 ;
break;
}
return false ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_57 )
{
struct V_208 * V_412 =
(struct V_208 * ) V_40 ;
F_9 ( L_7 , V_2 -> V_413 ) ;
if ( V_412 -> V_246 == V_247 ) {
struct V_250 * V_251 =
& V_412 -> V_97 . V_252 ;
F_9 ( L_8 ) ;
V_251 -> V_414 = V_206 ;
V_251 -> V_415 = V_207 ;
strcpy ( V_251 -> V_416 , V_205 ) ;
strcpy ( V_251 -> V_417 , V_418 ) ;
V_251 -> V_313 = 1 ;
V_251 -> V_314 = V_419 + 1 ;
V_251 -> V_315 = 1 ;
}
}
V_35 F_61 ( struct V_1 * V_2 ,
struct V_208 * V_412 )
{
struct V_40 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_2 = V_2 ;
V_45 . V_55 = V_412 ;
V_45 . V_50 = sizeof( struct V_208 ) + V_412 -> V_355 ;
V_45 . V_56 = F_53 ;
V_45 . V_57 = NULL ;
V_45 . V_59 = F_60 ;
V_45 . V_60 = NULL ;
V_45 . V_11 = 0 ;
return F_18 ( & V_45 ) ;
}
int F_62 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_420 * V_97 )
{
int V_46 = 0 ;
V_2 -> V_38 = 0 ;
V_4 -> V_36 = F_15 ;
if ( F_63 ( V_2 , V_4 , V_97 ) ) {
while ( ! V_2 -> V_38 )
F_11 ( V_2 -> V_39 ,
V_2 -> V_38 ) ;
;
if ( V_4 -> V_221 == V_222 )
V_46 = 1 ;
}
return V_46 ;
}
int F_64 ( void * V_421 , int V_422 , void T_4 * V_423 )
{
struct V_424 * V_55 = NULL ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_3 V_425 ;
int V_426 ;
F_19 ( V_427 , L_9 , V_421 , V_422 , V_423 ) ;
if ( ( V_423 == NULL )
|| ( V_422 < V_428 )
|| ( V_422 > V_429 ) )
return - V_430 ;
V_55 = F_65 ( V_423 , sizeof( struct V_424 ) ) ;
if ( F_66 ( V_55 ) ) {
F_19 ( V_431 ,
L_10
L_11 , V_422 ,
V_423 ) ;
return F_67 ( V_55 ) ;
}
if ( memcmp ( V_55 -> V_24 . V_432 ,
V_433 ,
V_434 ) != 0 ) {
F_19 ( V_431 , L_12 ) ;
F_68 ( V_55 ) ;
return - V_430 ;
}
V_55 -> V_24 . V_435 = V_47 ;
V_426 = 0 ;
if ( V_422 == V_436 ) {
int V_437 = 0 , V_438 = 0 ;
V_55 -> V_97 . V_439 . V_440 = 0 ;
while ( V_437 < V_441 ) {
if ( V_442 [ V_437 ] ) {
V_55 -> V_97 . V_439 . V_440 ++ ;
V_55 -> V_97 . V_439 . V_443 [ V_438 ] = V_437 ;
V_438 ++ ;
}
V_437 ++ ;
}
goto V_444;
}
if ( V_55 -> V_24 . V_443 == 0xFF ) {
V_2 = (struct V_1 * ) V_421 ;
} else {
if ( V_55 -> V_24 . V_443 >= V_441 ||
V_442 [ V_55 -> V_24 . V_443 ] == NULL ) {
V_55 -> V_24 . V_435 = V_445 ;
F_19 ( V_431 , L_13 ) ;
F_68 ( V_55 ) ;
return - V_430 ;
}
V_2 = V_442 [ V_55 -> V_24 . V_443 ] ;
}
switch ( V_422 ) {
case V_446 :
if ( V_55 -> V_97 . V_447 . V_448 == V_449 ) {
V_426 = F_69 ( V_2 ,
( char * ) V_55 -> V_97 . V_447 . V_450 ,
0 ,
sizeof( struct
V_424 ) ) ;
if ( V_426 >= 0 ) {
V_426 = F_70 ( V_2 ,
( char * ) V_55 -> V_97 . V_447 .
V_450 ,
0 ,
sizeof( struct
V_424 ) ) ;
}
} else if ( V_55 -> V_97 . V_447 . V_448 == V_451 ) {
V_426 = F_71 ( V_2 ,
( char * ) V_55 -> V_97 . V_447 . V_450 ,
0 ,
sizeof( struct
V_424 ) ) ;
if ( V_426 >= 0 ) {
V_426 = F_72 ( V_2 ,
( char * ) V_55 -> V_97 . V_447 .
V_450 ,
0 ,
sizeof( struct
V_424 ) ) ;
}
} else {
V_55 -> V_24 . V_435 = V_452 ;
}
break;
case V_453 :
memcpy ( V_55 -> V_97 . V_454 . V_455 , V_2 -> V_341 ,
sizeof( struct V_420 ) ) ;
V_55 -> V_97 . V_454 . V_425 = 1 ;
break;
case V_456 :
V_4 = F_7 ( V_2 ) ;
if ( V_4 == NULL ) {
F_68 ( V_55 ) ;
F_19 ( V_431 ,
L_5 ) ;
return - V_457 ;
}
V_425 = F_62 ( V_2 , V_4 ,
(struct V_420 * ) V_55 -> V_97 . V_454 . V_455 ) ;
V_55 -> V_97 . V_454 . V_425 = V_425 ;
F_13 ( V_2 , V_4 ) ;
break;
case V_458 :
F_73 ( V_2 ,
(struct V_420 * ) V_55 -> V_97 . V_454 . V_455 ) ;
V_55 -> V_97 . V_454 . V_425 = 1 ;
break;
case V_459 :
V_55 -> V_97 . V_460 . V_141 = V_206 ;
V_55 -> V_97 . V_460 . V_143 = V_207 ;
V_55 -> V_97 . V_460 . V_461 = V_2 -> V_26 -> V_462 ;
V_55 -> V_97 . V_460 . V_262 = V_2 -> V_26 -> V_263 ;
V_55 -> V_97 . V_460 . V_260 = V_2 -> V_26 -> V_261 ;
V_55 -> V_97 . V_460 . V_463 = V_2 -> V_26 -> V_125 ;
V_55 -> V_97 . V_460 . V_464 = V_2 -> V_26 -> V_267 ;
V_55 -> V_97 . V_460 . V_465 = V_2 -> V_26 -> V_135 -> V_136 ;
V_55 -> V_97 . V_460 . V_466 = V_2 -> V_26 -> V_138 ;
V_55 -> V_97 . V_460 . V_467 = 0 ;
V_55 -> V_97 . V_460 . V_468 = V_2 -> V_469 -> V_468 ;
V_55 -> V_97 . V_460 . V_470 = 0 ;
break;
case V_471 :
V_55 -> V_24 . V_435 = F_25 ( V_2 ,
& V_55 -> V_97 .
V_472 ) ;
break;
case V_473 :
V_55 -> V_24 . V_435 =
F_49 ( V_2 , & V_55 -> V_97 . V_72 ) ;
break;
case V_474 :
V_55 -> V_24 . V_435 = F_61 ( V_2 ,
& V_55 -> V_97 .
V_412 ) ;
break;
case V_475 :
V_426 = F_74 ( V_2 ,
( char * ) & V_55 -> V_97 . V_476 ,
0 ,
sizeof( struct V_477 ) +
V_55 -> V_97 . V_476 . V_355 ) ;
if ( V_426 >= 0 ) {
V_426 = F_75 ( V_2 ,
( char * ) & V_55 -> V_97 . V_476 ,
0 ,
sizeof( struct V_477 ) +
V_55 -> V_97 . V_476 . V_355 ) ;
}
break;
case V_478 :
V_55 -> V_97 . V_479 . V_10 = V_2 ;
V_55 -> V_97 . V_479 . V_480 = V_2 -> V_26 ;
V_55 -> V_97 . V_479 . V_481 = V_2 -> V_469 ;
V_55 -> V_97 . V_479 . V_468 = V_2 -> V_469 -> V_468 ;
break;
default:
F_9 ( L_14 , V_422 ) ;
V_55 -> V_24 . V_435 = V_482 ;
}
V_444:
if ( V_426 < 0 ) {
F_19 ( V_431 , L_15 , V_426 ,
V_422 ) ;
switch ( V_426 ) {
case - V_457 :
case - V_483 :
V_55 -> V_24 . V_435 = V_49 ;
break;
case - V_484 :
case - V_485 :
V_55 -> V_24 . V_435 = V_486 ;
break;
default:
V_55 -> V_24 . V_435 = V_487 ;
break;
}
}
V_426 = F_76 ( V_423 , V_55 , sizeof( struct V_424 ) ) ;
if ( V_426 != 0 ) {
F_19 ( V_431 ,
L_16
L_17 , V_426 ,
V_422 ) ;
F_68 ( V_55 ) ;
return - V_488 ;
}
F_68 ( V_55 ) ;
return 0 ;
}
int F_77 ( struct V_489 * V_490 , int V_422 , void T_4 * V_423 )
{
return F_64 ( V_490 -> V_469 -> V_421 , V_422 , V_423 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_97 ) {
F_12 ( & V_2 -> V_26 -> V_27 ,
( V_28 ) V_2 -> V_14 . V_16 ,
V_2 -> V_14 . V_97 ,
( V_29 ) V_2 -> V_14 . V_15 ) ;
V_2 -> V_14 . V_97 = NULL ;
}
}
static int F_79 ( struct V_1 * V_2 , T_1 V_50 )
{
F_78 ( V_2 ) ;
V_2 -> V_14 . V_16 = V_50 ;
V_2 -> V_14 . V_97 = ( V_35 * ) F_8 ( & V_2 -> V_26 -> V_27 ,
( V_28 ) V_50 ,
( V_29 * ) & V_2 -> V_14 .
V_15 ,
V_30 ) ;
if ( ! V_2 -> V_14 . V_97 ) {
F_9 ( L_18 ) ;
return 0 ;
}
return 1 ;
}
int F_70 ( struct V_1 * V_2 , char * V_491 , long V_492 , int V_493 )
{
F_80 () ;
if ( V_2 -> V_14 . V_494 == V_495 ) {
int V_496 = F_81 ( int , V_493 , sizeof( V_2 -> V_14 . V_24 ) ) ;
F_82 () ;
memcpy ( V_491 , & V_2 -> V_14 . V_24 , V_496 ) ;
F_9 ( L_19 , V_496 ) ;
return V_496 ;
}
if ( V_2 -> V_14 . V_494 == V_497 ) {
T_1 V_50 = V_2 -> V_14 . V_24 . V_50 ;
F_82 () ;
F_9 ( L_20 ,
V_50 ,
V_492 ) ;
if ( V_492 == 0 ) {
if ( V_2 -> V_14 . V_24 . V_498 == V_499 ) {
if ( ! F_79 ( V_2 , V_50 ) )
return - V_457 ;
memcpy ( V_2 -> V_14 . V_97 ,
& V_2 -> V_14 . V_24 ,
sizeof( V_2 -> V_14 . V_24 ) ) ;
F_5 ( V_2 ,
(struct V_18 * ) V_2 -> V_14 . V_97 ) ;
} else if ( V_2 -> V_14 . V_24 . V_498 == V_500 ) {
int V_496 =
F_83 ( ( int ) V_493 ,
( int ) sizeof( V_2 -> V_14 . V_24 ) ) ;
F_5 ( V_2 , & V_2 -> V_14 . V_24 ) ;
memcpy ( V_491 , & V_2 -> V_14 . V_24 , V_496 ) ;
F_9 ( L_21 , V_496 ) ;
return V_496 ;
} else {
F_9 ( L_22 ,
V_2 -> V_14 . V_24 . V_498 ) ;
return - V_484 ;
}
}
if ( V_493 + V_492 > V_50 )
V_493 = V_50 - V_492 ;
if ( V_493 < 0 )
return 0 ;
if ( ! V_2 -> V_14 . V_97 ) {
F_9 (
L_23 ) ;
return - V_457 ;
}
F_9 ( L_24 , V_492 ,
V_493 ,
V_50 ) ;
memcpy ( V_491 , & V_2 -> V_14 . V_97 [ V_492 ] , V_493 ) ;
if ( V_50 <= V_492 + V_493 ) {
F_9 ( L_25 ) ;
F_78 ( V_2 ) ;
}
return V_493 ;
}
F_82 () ;
F_9 ( L_26 ,
V_2 -> V_14 . V_494 ) ;
return - V_485 ;
}
int F_69 ( struct V_1 * V_2 , const char * V_491 , long V_492 ,
int V_493 )
{
T_1 V_50 ;
if ( V_492 == 0 ) {
struct V_18 * V_24 =
(struct V_18 * ) V_491 ;
int V_501 = sizeof( struct V_502 ) ;
V_2 -> V_14 . V_494 = V_503 ;
if ( V_493 < 4
|| V_24 -> V_504 > V_505 ) {
F_9 (
L_27 ) ;
return - V_485 ;
}
if ( V_24 -> V_504 == V_505 )
V_501 = sizeof( struct V_18 ) ;
if ( V_493 < V_501 ) {
F_9 ( L_28 ) ;
return - V_485 ;
}
V_50 = V_24 -> V_50 ;
if ( V_50 > 1024 * 1024 ) {
F_9 (
L_29 ,
V_50 , V_24 -> V_504 ) ;
return - V_485 ;
}
if ( V_24 -> V_498 == V_506 ) {
if ( ! F_79 ( V_2 , V_50 ) )
return - V_457 ;
memcpy ( & V_2 -> V_14 . V_24 ,
V_491 ,
sizeof( * V_24 ) ) ;
} else if ( V_24 -> V_498 == V_499
|| V_24 -> V_498 == V_500 ) {
memcpy ( & V_2 -> V_14 . V_24 ,
V_491 ,
sizeof( * V_24 ) ) ;
V_2 -> V_14 . V_494 = V_497 ;
F_9 (
L_30 ,
V_493 , V_24 -> V_498 ) ;
return V_493 ;
} else {
F_9 ( L_31 ,
V_2 -> V_14 . V_24 . V_498 ) ;
return - V_484 ;
}
} else {
V_50 = V_2 -> V_14 . V_24 . V_50 ;
}
if ( V_492 + V_493 > V_50 )
V_493 = V_50 - V_492 ;
if ( V_493 > 0 ) {
F_9 ( L_32 , V_492 ,
V_493 ,
V_50 ) ;
if ( V_2 -> V_14 . V_24 . V_498 == V_499 )
return V_493 ;
if ( ! V_2 -> V_14 . V_97 ) {
F_9 (
L_33 ) ;
return - V_457 ;
}
memcpy ( & V_2 -> V_14 . V_97 [ V_492 ] , V_491 , V_493 ) ;
if ( V_50 == V_492 + V_493 ) {
F_5 ( V_2 ,
(struct V_18 * ) V_2 -> V_14 . V_97 ) ;
memcpy ( & V_2 -> V_14 . V_24 ,
V_2 -> V_14 . V_97 ,
sizeof( V_2 -> V_14 . V_24 ) ) ;
V_2 -> V_14 . V_494 = V_495 ;
F_9 ( L_34 ) ;
F_78 ( V_2 ) ;
}
}
return V_493 ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_507 = 1 ;
F_2 ( & V_2 -> V_508 ) ;
}
static T_1 F_85 ( struct V_7 * V_8 , T_2 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_10 ;
int V_11 = ( V_35 * ) V_8 -> V_12 - ( V_35 * ) V_2 -> V_509 ;
( * V_9 ) = V_2 -> V_510 + V_11 ;
return V_511 - V_11 ;
}
int F_75 ( struct V_1 * V_2 , char * V_491 , long V_492 , int V_493 )
{
if ( ! V_2 -> V_509 )
return - V_457 ;
if ( V_492 == 0 ) {
struct V_3 * V_4 ;
struct V_477 * V_512 =
(struct V_477 * ) V_2 -> V_509 ;
struct V_7 V_8 ;
bool V_513 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 == NULL ) {
F_9 ( L_35 ) ;
return - V_483 ;
}
V_4 -> V_36 = F_84 ;
V_8 . V_514 = V_4 ;
V_8 . V_10 = V_2 ;
V_8 . V_12 = V_2 -> V_509 + V_515 ;
V_8 . V_33 = ( V_34 ) F_85 ;
V_2 -> V_507 = 0 ;
V_513 =
F_86 ( V_2 , V_512 , V_4 , & V_8 ) ;
if ( V_513 ) {
while ( ! V_2 -> V_507 )
F_11 ( V_2 -> V_508 ,
V_2 -> V_507 ) ;
}
F_13 ( V_2 , (struct V_3 * ) V_4 ) ;
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
int F_74 ( struct V_1 * V_2 , const char * V_491 , long V_492 ,
int V_493 )
{
if ( ! V_2 -> V_509 ) {
V_29 V_516 ;
V_2 -> V_509 = ( V_35 * ) F_8 ( & V_2 -> V_26 -> V_27 ,
( V_28 )
V_511 ,
& V_516 ,
V_30 ) ;
V_2 -> V_510 = V_516 ;
}
if ( ! V_2 -> V_509 )
return - V_457 ;
if ( V_492 > V_511 )
return 0 ;
if ( V_493 + V_492 > V_511 )
V_493 = V_511 - V_492 ;
if ( V_493 < 1 )
return 0 ;
memcpy ( V_2 -> V_509 + V_492 , V_491 , V_493 ) ;
return V_493 ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_517 = 1 ;
F_2 ( & V_2 -> V_518 ) ;
}
static T_1 F_88 ( struct V_7 * V_8 , T_2 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_10 ;
struct V_519 * V_520 =
(struct V_519 * ) V_2 -> V_521 ;
T_1 V_11 = ( V_35 * ) V_8 -> V_12 - ( V_35 * ) V_520 ;
( * V_9 ) = V_2 -> V_522 + V_11 ;
return V_2 -> V_523 - V_11 ;
}
int F_72 ( struct V_1 * V_2 , char * V_491 , long V_492 , int V_493 )
{
if ( ! V_2 -> V_521 )
return - V_457 ;
if ( V_492 == 0 ) {
struct V_3 * V_4 ;
struct V_7 V_8 ;
struct V_519 * V_520 =
(struct V_519 * ) V_2 -> V_521 ;
if ( F_6 ( & V_2 -> V_524 ) ) {
V_525:
V_520 -> V_21 = V_66 ;
return - V_483 ;
}
V_4 = F_7 ( V_2 ) ;
if ( V_4 == NULL ) {
F_9 ( L_36 ) ;
F_14 ( & V_2 -> V_524 ) ;
goto V_525;
}
V_4 -> V_36 = F_87 ;
V_8 . V_12 = V_520 -> V_97 ;
V_8 . V_33 = ( V_34 ) F_88 ;
V_2 -> V_517 = 0 ;
if ( ! F_89 ( V_2 , V_520 , V_4 , & V_8 ) ) {
if ( V_520 -> V_21 == V_66 )
V_493 = - V_483 ;
goto V_526;
}
while ( ! V_2 -> V_517 )
F_11 ( V_2 -> V_518 ,
V_2 -> V_517 ) ;
;
V_526:
F_14 ( & V_2 -> V_524 ) ;
F_13 ( V_2 , (struct V_3 * ) V_4 ) ;
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
int F_71 ( struct V_1 * V_2 , const char * V_491 , long V_492 ,
int V_493 )
{
if ( V_492 == 0 ) {
struct V_519 * V_520 = (struct V_519 * ) V_491 ;
T_1 V_50 = V_520 -> V_527 . V_50 + F_58 (
struct V_519 ,
V_97 ) ;
if ( V_520 -> V_527 . V_527 == V_528 )
V_50 = F_58 ( struct V_519 , V_97 ) ;
if ( V_493 < F_58 ( struct V_519 , V_97 ) )
return - V_485 ;
if ( V_2 -> V_521 ) {
if ( V_2 -> V_523 < V_50 ) {
F_12 ( & V_2 -> V_26 -> V_27 ,
( V_28 ) V_2 -> V_523 ,
V_2 -> V_521 ,
( V_29 ) V_2 -> V_522 ) ;
goto V_529;
}
} else {
V_529:
V_2 -> V_523 = V_50 ;
V_2 -> V_521 = ( V_35 * ) F_8 (
& V_2 -> V_26 -> V_27 ,
( V_28 ) V_2 -> V_523 ,
( V_29 * ) & V_2 -> V_522 ,
V_30 ) ;
}
}
if ( ! V_2 -> V_521 )
return - V_457 ;
if ( V_492 > V_2 -> V_523 )
return 0 ;
if ( V_493 + V_492 > V_2 -> V_523 )
V_493 = V_2 -> V_523 - V_492 ;
if ( V_493 < 1 )
return 0 ;
memcpy ( V_2 -> V_521 + V_492 , V_491 , V_493 ) ;
return V_493 ;
}
