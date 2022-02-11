void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
if ( V_11 . V_12 )
return;
F_4 ( & V_8 -> V_13 ) ;
memcpy ( V_10 -> V_14 . V_15 , V_6 -> V_15 , V_16 ) ;
memcpy ( V_10 -> V_14 . V_17 , V_6 -> V_17 , V_18 ) ;
V_10 -> V_14 . V_19 =
F_5 ( F_6 ( ( V_20 * ) & V_6 -> V_19 ) ) ;
V_10 -> V_14 . V_21 = true ;
F_7 ( & V_8 -> V_13 ) ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_24 * V_25 ;
int V_26 = 0 ;
memset ( V_10 -> V_27 , 0 , sizeof( V_10 -> V_27 ) ) ;
F_9 ( & V_23 -> V_28 ) ;
F_10 (ifa, &idev->addr_list, if_list) {
V_10 -> V_29 [ V_26 ] = V_25 -> V_30 ;
if ( V_25 -> V_31 & V_32 )
F_11 ( V_26 , V_10 -> V_27 ) ;
V_26 ++ ;
if ( V_26 >= V_33 )
break;
}
F_12 ( & V_23 -> V_28 ) ;
V_10 -> V_34 = V_26 ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_26 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
V_10 -> V_35 = V_26 ;
}
static void F_14 ( T_1 * V_36 , T_2 * V_37 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
V_37 [ V_38 ] = F_15 ( V_36 [ V_38 ] ) ;
}
static const T_3 * F_16 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
struct V_44 * V_45 ,
int V_46 , int V_47 )
{
const T_3 * V_48 = V_45 -> V_49 . V_50 ;
int V_38 ;
F_17 ( V_41 , V_46 , V_45 ) ;
for ( V_38 = 1 ; V_38 < V_47 ; V_38 ++ ) {
const T_3 * V_51 = V_43 -> V_52 [ V_38 ] . V_50 [ V_46 ] ;
if ( memcmp ( V_48 , V_51 , V_53 ) <= 0 )
V_48 = V_51 ;
}
return V_48 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_54 * V_55 ,
struct V_40 * V_41 ,
void * V_56 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_57 * V_6 = V_56 ;
struct V_58 * V_58 , * V_59 = NULL ;
struct V_60 * V_60 , * V_61 = NULL ;
struct V_62 * V_63 ;
T_3 * V_64 ;
struct V_44 V_45 ;
T_4 V_65 = 0 ;
T_1 V_36 [ V_39 ] ;
int V_48 , V_38 ;
switch ( V_41 -> V_66 ) {
case V_67 :
case V_68 : {
struct {
struct V_69 V_70 ;
struct V_71 V_72 ;
} V_73 V_74 = {
. V_70 . V_75 =
F_19 ( F_20 ( V_10 -> V_76 ,
V_10 -> V_77 ) ) ,
. V_70 . V_78 = 1 ,
. V_70 . V_79 = V_80 ,
. V_72 . V_81 = V_41 -> V_82 ,
. V_72 . V_83 = V_41 -> V_84 ,
} ;
if ( V_41 -> V_31 & V_85 )
break;
memcpy ( & V_74 . V_72 . V_41 [ 3 ] , V_41 -> V_41 , V_41 -> V_84 ) ;
if ( V_41 -> V_82 == V_10 -> V_35 ) {
V_74 . V_72 . V_86 = 0 ;
} else {
V_6 -> V_87 ++ ;
V_74 . V_72 . V_86 = V_6 -> V_87 ;
}
if ( V_6 -> V_88 ) {
F_4 ( & V_8 -> V_13 ) ;
V_48 = F_21 ( V_8 , V_89 , 0 ,
sizeof( V_74 ) , & V_74 ) ;
V_6 -> error = V_48 != 0 ;
V_8 -> V_90 = V_41 -> V_91 ;
V_8 -> V_92 = V_41 -> V_93 ;
V_8 -> V_94 = V_41 -> V_91 ;
V_8 -> V_95 = V_41 -> V_93 ;
F_7 ( & V_8 -> V_13 ) ;
}
return;
}
default:
V_6 -> error = true ;
return;
case V_96 :
return;
case V_97 :
if ( V_55 ) {
V_60 = V_6 -> V_98 -> V_99 . V_100 . V_101 ;
V_61 = & V_6 -> V_98 -> V_99 . V_100 . V_102 ;
V_63 = V_6 -> V_100 -> V_103 ;
F_22 ( V_41 , & V_45 ) ;
V_61 -> V_104 = F_15 ( V_45 . V_100 . V_104 ) ;
V_61 -> V_105 = F_19 ( V_45 . V_100 . V_105 ) ;
F_23 ( V_41 , V_45 . V_100 . V_105 , V_36 ) ;
F_14 ( V_36 , V_6 -> V_100 -> V_106 . V_36 ) ;
memcpy ( V_6 -> V_100 -> V_107 . V_106 ,
& V_41 -> V_41 [ V_108 ] ,
V_109 ) ;
V_64 = V_6 -> V_100 -> V_107 . V_110 ;
} else {
V_60 =
V_6 -> V_98 -> V_99 . V_100 . V_111 ;
V_63 = V_6 -> V_100 -> V_112 ;
V_64 = V_6 -> V_100 -> V_107 . V_113 ;
}
for ( V_38 = 0 ; V_38 < V_114 ; V_38 ++ ) {
F_17 ( V_41 , V_38 , & V_45 ) ;
V_60 [ V_38 ] . V_104 = F_15 ( V_45 . V_100 . V_104 ) ;
V_60 [ V_38 ] . V_105 = F_19 ( V_45 . V_100 . V_105 ) ;
if ( V_45 . V_100 . V_105 > V_65 )
V_65 = V_45 . V_100 . V_105 ;
}
F_24 ( V_41 , V_4 -> V_115 . V_116 ,
V_65 , V_36 ) ;
F_14 ( V_36 , V_63 [ 0 ] . V_36 ) ;
F_24 ( V_41 , V_4 -> V_115 . V_116 ,
V_65 + 1 , V_36 ) ;
F_14 ( V_36 , V_63 [ 1 ] . V_36 ) ;
memcpy ( V_64 ,
& V_41 -> V_41 [ V_117 ] ,
V_109 ) ;
V_6 -> V_118 = true ;
V_6 -> V_119 = true ;
break;
case V_120 :
if ( V_55 ) {
T_5 V_121 ;
V_58 = V_6 -> V_98 -> V_99 . V_122 . V_101 ;
V_59 = & V_6 -> V_98 -> V_99 . V_122 . V_102 ;
V_121 = F_25 ( & V_41 -> V_123 ) ;
V_59 -> V_50 = F_5 ( V_121 ) ;
} else {
V_58 = V_6 -> V_98 -> V_99 . V_122 . V_111 ;
}
if ( V_55 && F_26 ( V_8 ) ) {
struct V_124 * V_125 ;
struct V_42 * V_43 ;
const T_3 * V_50 ;
V_125 = F_27 ( V_55 ) ;
V_43 = F_28 (
V_125 -> V_43 [ V_41 -> V_82 ] ,
F_29 ( & V_8 -> V_13 ) ) ;
if ( F_30 ( ! V_43 ) )
break;
for ( V_38 = 0 ; V_38 < V_126 ; V_38 ++ ) {
V_50 = F_16 ( V_41 , V_43 , & V_45 , V_38 ,
V_8 -> V_127 -> V_128 ) ;
V_58 [ V_38 ] . V_50 = F_5 ( ( T_5 ) V_50 [ 5 ] |
( ( T_5 ) V_50 [ 4 ] << 8 ) |
( ( T_5 ) V_50 [ 3 ] << 16 ) |
( ( T_5 ) V_50 [ 2 ] << 24 ) |
( ( T_5 ) V_50 [ 1 ] << 32 ) |
( ( T_5 ) V_50 [ 0 ] << 40 ) ) ;
}
} else {
for ( V_38 = 0 ; V_38 < V_114 ; V_38 ++ ) {
T_3 * V_50 = V_45 . V_49 . V_50 ;
F_17 ( V_41 , V_38 , & V_45 ) ;
V_58 [ V_38 ] . V_50 = F_5 ( ( T_5 ) V_50 [ 5 ] |
( ( T_5 ) V_50 [ 4 ] << 8 ) |
( ( T_5 ) V_50 [ 3 ] << 16 ) |
( ( T_5 ) V_50 [ 2 ] << 24 ) |
( ( T_5 ) V_50 [ 1 ] << 32 ) |
( ( T_5 ) V_50 [ 0 ] << 40 ) ) ;
}
}
V_6 -> V_119 = true ;
break;
}
if ( V_6 -> V_88 ) {
F_4 ( & V_8 -> V_13 ) ;
if ( V_41 -> V_31 & V_85 ) {
V_8 -> V_90 = V_41 -> V_91 ;
V_8 -> V_92 = V_41 -> V_93 ;
V_48 = F_31 ( V_8 , V_4 , V_55 , V_41 , 0 ) ;
} else {
V_8 -> V_94 = V_41 -> V_91 ;
V_8 -> V_95 = V_41 -> V_93 ;
V_48 = F_31 ( V_8 , V_4 , V_55 , V_41 , 1 ) ;
}
F_7 ( & V_8 -> V_13 ) ;
V_6 -> error = V_48 != 0 ;
}
}
static int F_32 ( struct V_7 * V_8 ,
struct V_129 * V_130 )
{
struct V_131 * V_132 ;
struct V_133 V_134 = {
. V_76 = V_135 ,
. V_136 [ 0 ] = V_137 ,
} ;
int V_38 , V_138 ;
if ( ! V_130 -> V_139 )
return 0 ;
V_134 . V_140 [ 0 ] = sizeof( * V_132 ) +
V_130 -> V_139 * sizeof( struct V_141 ) ;
V_132 = F_33 ( V_134 . V_140 [ 0 ] , V_142 ) ;
if ( ! V_132 )
return - V_143 ;
V_132 -> V_139 = F_19 ( V_130 -> V_139 ) ;
for ( V_38 = 0 ; V_38 < V_130 -> V_139 ; V_38 ++ ) {
int V_144 = F_34 ( V_130 -> V_145 [ V_38 ] . V_146 , 8 ) ;
memcpy ( & V_132 -> V_145 [ V_38 ] . V_147 ,
V_130 -> V_145 [ V_38 ] . V_147 , V_144 ) ;
memcpy ( & V_132 -> V_145 [ V_38 ] . V_148 ,
V_130 -> V_145 [ V_38 ] . V_148 ,
V_130 -> V_145 [ V_38 ] . V_146 ) ;
V_132 -> V_145 [ V_38 ] . V_149 = V_144 ;
V_132 -> V_145 [ V_38 ] . V_150 =
V_130 -> V_145 [ V_38 ] . V_146 ;
}
V_134 . V_6 [ 0 ] = V_132 ;
V_138 = F_35 ( V_8 , & V_134 ) ;
F_36 ( V_132 ) ;
return V_138 ;
}
static T_2 F_37 ( int V_140 , T_6 V_151 , T_6 V_152 )
{
T_7 V_153 = F_38 ( V_140 , V_151 , V_152 , 0 ) ;
return F_15 ( F_39 ( ( V_154 V_155 ) V_153 ) ) ;
}
static void F_40 ( struct V_3 * V_4 ,
struct V_156 * V_157 ,
void * V_158 , T_3 * V_147 ,
T_2 * V_159 ,
enum V_160 V_161 )
{
struct {
struct V_162 V_163 ;
struct V_164 V_165 ;
struct V_166 V_157 ;
T_3 V_6 [] ;
} V_73 * V_167 = V_158 ;
T_1 V_168 = sizeof( struct V_164 ) + sizeof( struct V_166 ) ;
int V_38 ;
V_167 -> V_163 . V_169 = F_41 ( V_170 ) ,
V_167 -> V_165 . V_171 = 4 ;
V_167 -> V_165 . V_172 = 5 ;
V_167 -> V_165 . V_173 = V_174 ;
switch ( V_161 ) {
case V_175 :
case V_176 :
case V_177 :
memcpy ( V_167 -> V_163 . V_178 , V_157 -> V_179 , V_180 ) ;
memcpy ( V_167 -> V_163 . V_181 , V_4 -> V_30 , V_180 ) ;
V_167 -> V_165 . V_182 = 128 ;
V_167 -> V_165 . V_151 = V_157 -> V_183 ;
V_167 -> V_165 . V_152 = V_157 -> V_184 ;
V_167 -> V_157 . V_185 = F_41 ( V_157 -> V_186 ) ;
V_167 -> V_157 . V_187 = F_41 ( V_157 -> V_188 ) ;
V_167 -> V_157 . V_189 = sizeof( struct V_166 ) / 4 ;
V_167 -> V_157 . V_190 = F_41 ( 65000 ) ;
break;
case V_191 :
case V_192 :
case V_193 :
memcpy ( V_167 -> V_163 . V_178 , V_4 -> V_30 , V_180 ) ;
memcpy ( V_167 -> V_163 . V_181 , V_157 -> V_179 , V_180 ) ;
V_167 -> V_165 . V_151 = V_157 -> V_184 ;
V_167 -> V_165 . V_152 = V_157 -> V_183 ;
V_167 -> V_157 . V_185 = F_41 ( V_157 -> V_188 ) ;
V_167 -> V_157 . V_187 = F_41 ( V_157 -> V_186 ) ;
break;
default:
F_30 ( 1 ) ;
return;
}
switch ( V_161 ) {
case V_175 :
memset ( V_167 -> V_6 , 0x01 , 8 ) ;
V_168 += 8 ;
V_167 -> V_157 . V_189 = ( sizeof( struct V_166 ) + 8 ) / 4 ;
V_167 -> V_157 . V_194 = 1 ;
break;
case V_176 :
V_168 += V_157 -> V_195 ;
memcpy ( V_167 -> V_6 , V_157 -> V_196 , V_157 -> V_195 ) ;
V_167 -> V_157 . V_197 = 1 ;
V_167 -> V_157 . V_198 = 1 ;
break;
case V_177 :
V_167 -> V_157 . V_199 = 1 ;
V_167 -> V_157 . V_198 = 1 ;
break;
case V_191 :
V_167 -> V_157 . V_194 = 1 ;
V_167 -> V_157 . V_198 = 1 ;
break;
case V_192 :
V_167 -> V_157 . V_198 = 1 ;
break;
case V_193 :
V_168 += V_157 -> V_200 ;
V_167 -> V_157 . V_197 = 1 ;
V_167 -> V_157 . V_198 = 1 ;
memcpy ( V_167 -> V_6 , V_157 -> V_201 , V_157 -> V_200 ) ;
break;
}
switch ( V_161 ) {
case V_175 :
case V_176 :
case V_177 :
V_167 -> V_165 . V_202 = F_41 ( V_168 ) ;
V_167 -> V_165 . V_153 = F_42 ( & V_167 -> V_165 , V_167 -> V_165 . V_172 ) ;
break;
case V_193 :
for ( V_38 = 0 ; V_38 < F_34 ( V_157 -> V_200 , 8 ) ; V_38 ++ ) {
T_3 V_51 = V_157 -> V_203 [ V_38 ] ;
V_147 [ V_38 + 6 ] |= V_51 << 6 ;
if ( V_38 + 1 < F_34 ( V_157 -> V_200 , 8 ) )
V_147 [ V_38 + 7 ] = V_51 >> 2 ;
}
case V_191 :
case V_192 :
V_147 [ 0 ] = 0xff ;
V_147 [ 1 ] = 0x7f ;
V_147 [ 2 ] = 0x80 ;
V_147 [ 3 ] = 0xfc ;
V_147 [ 4 ] = 0x3f ;
V_147 [ 5 ] = 0x80 ;
break;
} ;
* V_159 = F_37 ( V_168 - sizeof( struct V_164 ) ,
V_167 -> V_165 . V_151 , V_167 -> V_165 . V_152 ) ;
}
static int F_43 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
struct V_156 * V_157 )
{
struct V_204 * V_205 ;
struct V_133 V_134 = {
. V_76 = V_206 ,
. V_140 = { sizeof( * V_205 ) , } ,
. V_136 = { V_137 , } ,
} ;
int V_48 ;
if ( ! V_157 )
return 0 ;
V_205 = F_44 ( sizeof( * V_205 ) , V_142 ) ;
if ( ! V_205 )
return - V_143 ;
V_134 . V_6 [ 0 ] = V_205 ;
V_205 -> V_207 = 10 ;
V_205 -> V_208 = 10 ;
V_205 -> V_209 = 1 ;
V_205 -> V_210 = 1 ;
F_40 (
V_4 , V_157 , V_205 -> V_211 . V_6 , NULL ,
& V_205 -> V_211 . V_212 . V_213 ,
V_175 ) ;
V_205 -> V_211 . V_212 . V_214 = 0 ;
F_40 (
V_4 , V_157 , V_205 -> V_215 . V_6 , V_205 -> V_215 . V_216 ,
& V_205 -> V_215 . V_212 . V_213 ,
V_191 ) ;
V_205 -> V_215 . V_212 . V_214 = 0 ;
F_40 (
V_4 , V_157 , V_205 -> V_217 . V_6 , NULL ,
& V_205 -> V_217 . V_212 . V_213 ,
V_176 ) ;
V_205 -> V_217 . V_212 . V_214 =
F_15 ( V_157 -> V_195 ) ;
V_205 -> V_218 = V_157 -> V_219 . V_220 ;
V_205 -> V_221 = V_157 -> V_219 . V_140 ;
V_205 -> V_222 = F_19 ( V_157 -> V_219 . V_223 ) ;
V_205 -> V_224 = F_15 ( V_157 -> V_225 ) ;
if ( V_157 -> V_226 . V_140 ) {
V_205 -> V_227 = V_157 -> V_226 . V_220 ;
V_205 -> V_228 = V_157 -> V_226 . V_140 ;
V_205 -> V_229 =
F_15 ( V_157 -> V_230 % V_157 -> V_226 . V_140 ) ;
memcpy ( V_205 -> V_231 , V_157 -> V_226 . V_232 ,
V_157 -> V_230 ) ;
} else {
V_205 -> V_229 = F_15 ( 65535 ) ;
}
F_40 (
V_4 , V_157 , V_205 -> V_233 . V_6 ,
V_205 -> V_233 . V_216 ,
& V_205 -> V_233 . V_212 . V_213 ,
V_192 ) ;
V_205 -> V_233 . V_212 . V_214 = 0 ;
F_40 (
V_4 , V_157 , V_205 -> V_234 . V_6 , V_205 -> V_234 . V_216 ,
& V_205 -> V_234 . V_212 . V_213 ,
V_193 ) ;
V_205 -> V_234 . V_212 . V_214 =
F_15 ( V_157 -> V_200 ) ;
F_40 (
V_4 , V_157 , V_205 -> V_235 . V_6 , NULL ,
& V_205 -> V_235 . V_212 . V_213 ,
V_177 ) ;
V_205 -> V_235 . V_212 . V_214 = 0 ;
V_48 = F_35 ( V_8 , & V_134 ) ;
F_36 ( V_205 ) ;
return V_48 ;
}
static int F_45 ( struct V_7 * V_8 , struct V_3 * V_4 ,
struct V_54 * V_236 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_237 * V_238 ;
T_3 V_239 , V_240 ;
struct V_241 V_242 ;
int V_48 , V_38 ;
struct V_243 V_244 = {} ;
struct V_245 V_246 = {} ;
T_4 V_247 ;
if ( F_30 ( ! V_10 -> V_248 ) )
return - V_249 ;
F_46 () ;
V_238 = F_47 ( V_4 -> V_250 ) ;
if ( F_30 ( ! V_238 ) ) {
F_48 () ;
return - V_249 ;
}
V_242 = V_238 -> V_251 ;
V_239 = V_238 -> V_252 ;
V_240 = V_238 -> V_253 ;
F_48 () ;
V_48 = F_49 ( V_8 , V_10 -> V_248 , & V_242 ,
V_239 , V_240 ) ;
if ( V_48 )
return V_48 ;
V_10 -> V_254 = false ;
if ( F_30 ( ! V_4 -> V_115 . V_255 ) )
return - V_249 ;
V_48 = F_50 ( V_8 , V_4 ) ;
if ( V_48 )
return V_48 ;
V_244 . V_256 =
F_19 ( F_20 ( V_10 -> V_248 -> V_76 ,
V_10 -> V_248 -> V_77 ) ) ;
V_244 . V_257 = F_19 ( V_258 ) ;
V_244 . V_259 =
F_19 ( F_20 ( V_10 -> V_248 -> V_76 ,
V_10 -> V_248 -> V_77 ) ) ;
V_244 . V_260 [ 0 ] = F_19 ( F_20 ( V_10 -> V_76 ,
V_10 -> V_77 ) ) ;
for ( V_38 = 1 ; V_38 < V_261 ; V_38 ++ )
V_244 . V_260 [ V_38 ] = F_19 ( V_262 ) ;
V_247 = 0 ;
V_48 = F_51 ( V_8 , V_263 ,
sizeof( V_244 ) , & V_244 ,
& V_247 ) ;
if ( V_48 ) {
F_52 ( V_8 , L_1 , V_48 ) ;
return V_48 ;
}
if ( V_247 ) {
F_52 ( V_8 , L_2 , V_247 ) ;
return - V_264 ;
}
V_48 = F_53 ( V_8 , V_236 , false ) ;
if ( V_48 )
return V_48 ;
F_54 ( V_8 -> V_265 [ V_10 -> V_266 ] , V_236 ) ;
V_48 = F_55 ( V_8 , V_4 , false , NULL ) ;
if ( V_48 )
return V_48 ;
V_246 . V_267 [ 0 ] . V_256 =
F_19 ( F_20 ( V_10 -> V_248 -> V_76 ,
V_10 -> V_248 -> V_77 ) ) ;
V_246 . V_267 [ 0 ] . V_268 = F_19 ( V_269 ) ;
V_246 . V_267 [ 0 ] . V_270 = F_19 ( V_269 ) ;
for ( V_38 = 1 ; V_38 < V_271 ; V_38 ++ )
V_246 . V_267 [ V_38 ] . V_256 = F_19 ( V_262 ) ;
V_48 = F_21 ( V_8 , V_272 , 0 ,
sizeof( V_246 ) , & V_246 ) ;
if ( V_48 )
F_52 ( V_8 , L_3 , V_48 ) ;
if ( F_56 ( V_8 ) && F_57 ( V_8 ) )
F_52 ( V_8 , L_4 ) ;
return 0 ;
}
static int F_58 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_273 V_274 = {
. V_275 = F_19 ( V_276 ) ,
. V_75 =
F_19 ( F_20 ( V_10 -> V_76 ,
V_10 -> V_77 ) ) ,
} ;
struct V_133 V_134 = {
. V_76 = V_277 ,
. V_31 = V_278 ,
} ;
int V_138 ;
T_4 V_279 ;
V_134 . V_6 [ 0 ] = & V_274 ;
V_134 . V_140 [ 0 ] = sizeof( V_274 ) ;
V_138 = F_35 ( V_8 , & V_134 ) ;
if ( V_138 )
return V_138 ;
V_279 = F_59 ( V_134 . V_280 ) ;
if ( V_279 < sizeof( T_2 ) ) {
V_138 = - V_249 ;
} else {
V_138 = F_60 ( ( T_2 * ) V_134 . V_280 -> V_6 ) ;
V_138 = ( T_1 ) ( V_138 - 0x10 ) ;
}
F_61 ( & V_134 ) ;
return V_138 ;
}
void F_62 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_273 V_274 = {
. V_275 = F_19 ( V_281 ) ,
. V_75 =
F_19 ( F_20 ( V_10 -> V_76 ,
V_10 -> V_77 ) ) ,
. V_282 = F_15 ( V_10 -> V_283 ) ,
} ;
if ( ! V_10 -> V_284 )
return;
V_10 -> V_284 = false ;
if ( F_21 ( V_8 , V_277 , 0 ,
sizeof( V_274 ) , & V_274 ) )
F_52 ( V_8 , L_5 ) ;
}
static int F_63 ( struct V_7 * V_8 )
{
F_64 ( V_8 , V_285 , true ) ;
F_65 ( V_8 -> V_127 ) ;
F_66 ( V_286 , & V_8 -> V_247 ) ;
memset ( V_8 -> V_287 , 0 , sizeof( V_8 -> V_287 ) ) ;
V_8 -> V_90 = 0 ;
V_8 -> V_92 = 0 ;
V_8 -> V_90 = 0 ;
V_8 -> V_92 = 0 ;
return F_67 ( V_8 ) ;
}
static int
F_68 ( struct V_7 * V_8 ,
struct V_129 * V_130 ,
struct V_288 * V_289 ,
struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_54 * V_236 )
{
int V_48 ;
struct V_124 * V_290 = F_27 ( V_236 ) ;
V_289 -> V_291 =
V_236 -> V_292 . V_293 ;
V_289 -> V_31 = V_294 |
V_295 | V_296 ;
V_48 = F_58 ( V_8 , V_4 ) ;
if ( V_48 < 0 )
return V_48 ;
V_289 -> V_297 = F_15 ( V_48 ) ;
F_69 ( V_290 , V_289 ) ;
if ( V_130 -> V_298 )
V_289 -> V_299 |=
F_19 ( V_300 |
V_301 ) ;
if ( V_130 -> V_302 )
V_289 -> V_299 |=
F_19 ( V_303 ) ;
if ( V_130 -> V_304 )
V_289 -> V_299 |=
F_19 ( V_305 ) ;
if ( V_130 -> V_306 )
V_289 -> V_299 |=
F_19 ( V_307 ) ;
if ( V_130 -> V_308 )
V_289 -> V_299 |=
F_19 ( V_309 ) ;
if ( V_130 -> V_139 )
V_289 -> V_299 |=
F_19 ( V_310 ) ;
if ( V_130 -> V_311 )
V_289 -> V_299 |=
F_19 ( V_312 ) ;
if ( V_130 -> V_157 ) {
V_289 -> V_299 |=
F_19 ( V_313 |
V_314 |
V_315 |
V_301 ) ;
}
return 0 ;
}
static void
F_70 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
void (* F_71)( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_54 * V_55 ,
struct V_40 * V_41 ,
void * V_6 ) ,
void * V_6 )
{
struct V_54 * V_236 ;
F_46 () ;
V_236 = F_47 ( V_8 -> V_265 [ V_8 -> V_316 ] ) ;
if ( F_72 ( V_236 ) )
goto V_37;
F_73 ( V_8 -> V_2 , V_4 , F_71 , V_6 ) ;
V_37:
F_48 () ;
}
int F_74 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
bool V_317 ,
T_4 V_318 )
{
struct V_319 V_320 = {} ;
struct V_321 V_322 = {} ;
struct V_57 V_323 = {
. V_88 = ! V_317 ,
. V_119 = false ,
. V_100 = & V_322 ,
. V_118 = false ,
} ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
int V_48 ;
V_323 . V_98 = F_44 ( sizeof( * V_323 . V_98 ) , V_142 ) ;
if ( ! V_323 . V_98 )
return - V_143 ;
if ( ! V_317 ) {
F_75 ( V_8 -> V_2 , V_4 ,
F_18 ,
& V_323 ) ;
} else {
F_70 ( V_8 , V_4 ,
F_18 ,
& V_323 ) ;
}
if ( V_323 . error ) {
V_48 = - V_264 ;
goto V_37;
}
if ( V_323 . V_119 ) {
V_48 = F_21 ( V_8 ,
V_324 , V_318 ,
sizeof( * V_323 . V_98 ) ,
V_323 . V_98 ) ;
if ( V_48 )
goto V_37;
}
if ( V_323 . V_118 ) {
V_48 = F_21 ( V_8 ,
V_325 ,
V_318 , sizeof( V_322 ) ,
& V_322 ) ;
if ( V_48 )
goto V_37;
}
if ( V_10 -> V_14 . V_21 && ! V_317 ) {
memset ( & V_320 , 0 , sizeof( V_320 ) ) ;
memcpy ( V_320 . V_17 , V_10 -> V_14 . V_17 ,
V_18 ) ;
V_320 . V_326 = F_15 ( V_18 ) ;
memcpy ( V_320 . V_15 , V_10 -> V_14 . V_15 ,
V_16 ) ;
V_320 . V_327 = F_15 ( V_16 ) ;
V_320 . V_19 = V_10 -> V_14 . V_19 ;
V_48 = F_21 ( V_8 ,
V_328 , V_318 ,
sizeof( V_320 ) ,
& V_320 ) ;
if ( V_48 )
goto V_37;
}
V_48 = 0 ;
V_37:
F_36 ( V_323 . V_98 ) ;
return V_48 ;
}
static int
F_76 ( struct V_7 * V_8 ,
struct V_129 * V_130 ,
struct V_288 * V_289 ,
struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_54 * V_236 )
{
int V_48 ;
V_48 = F_63 ( V_8 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_45 ( V_8 , V_4 , V_236 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_11 . V_12 ) {
F_7 ( & V_8 -> V_13 ) ;
V_48 = F_74 ( V_8 , V_4 , false ,
V_329 ) ;
F_4 ( & V_8 -> V_13 ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_21 ( V_8 , V_330 , 0 ,
sizeof( * V_289 ) ,
V_289 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_32 ( V_8 , V_130 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_77 ( V_8 , V_4 , false , true , 0 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_43 ( V_8 , V_4 , V_130 -> V_157 ) ;
return V_48 ;
}
static int
F_78 ( struct V_7 * V_8 ,
struct V_129 * V_130 ,
struct V_331 * V_332 ,
struct V_3 * V_4 )
{
struct V_288 V_289 = {} ;
int V_48 ;
V_48 = F_63 ( V_8 ) ;
if ( V_48 )
return V_48 ;
if ( V_130 -> V_311 )
V_289 . V_299 |=
F_19 ( V_312 ) ;
V_48 = F_21 ( V_8 , V_330 , 0 ,
sizeof( V_289 ) ,
& V_289 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_79 ( V_8 , V_4 , V_332 , & V_8 -> V_333 ,
V_334 ) ;
if ( V_48 )
return V_48 ;
if ( F_30 ( V_8 -> V_335 || V_8 -> V_336 ) )
return - V_337 ;
if ( V_332 -> V_338 ) {
V_8 -> V_335 = F_80 ( V_332 -> V_339 ,
sizeof( * V_332 -> V_339 ) *
V_332 -> V_338 ,
V_142 ) ;
if ( V_8 -> V_335 )
V_8 -> V_340 = V_332 -> V_338 ;
}
V_8 -> V_336 = F_80 ( V_332 -> V_341 ,
sizeof( * V_332 -> V_341 ) *
V_332 -> V_342 ,
V_142 ) ;
if ( V_8 -> V_336 )
V_8 -> V_343 = V_332 -> V_342 ;
return 0 ;
}
static void F_81 ( struct V_7 * V_8 )
{
F_36 ( V_8 -> V_335 ) ;
V_8 -> V_335 = NULL ;
V_8 -> V_340 = 0 ;
F_36 ( V_8 -> V_336 ) ;
V_8 -> V_336 = NULL ;
V_8 -> V_343 = 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
bool V_344 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_4 = NULL ;
struct V_9 * V_10 = NULL ;
struct V_54 * V_236 = NULL ;
struct V_345 V_346 = {
. V_347 = F_19 ( 10 * 1000 * 1000 ) ,
} ;
struct V_133 V_348 = {
. V_76 = V_349 ,
. V_31 = V_278 ,
. V_6 [ 0 ] = & V_346 ,
. V_140 [ 0 ] = sizeof( V_346 ) ,
} ;
int V_48 ;
int V_140 V_350 ;
if ( ! V_130 ) {
F_30 ( ! V_344 ) ;
return - V_249 ;
}
F_4 ( & V_8 -> V_13 ) ;
V_4 = F_83 ( V_8 ) ;
if ( F_72 ( V_4 ) ) {
V_48 = 1 ;
goto V_351;
}
V_10 = F_3 ( V_4 ) ;
if ( V_10 -> V_266 == V_352 ) {
if ( ! V_130 -> V_332 ) {
V_48 = 1 ;
goto V_351;
}
V_48 = F_78 (
V_8 , V_130 , V_130 -> V_332 , V_4 ) ;
if ( V_48 )
goto V_37;
V_8 -> V_353 = true ;
} else {
struct V_288 V_289 = {} ;
V_236 = F_28 (
V_8 -> V_265 [ V_10 -> V_266 ] ,
F_29 ( & V_8 -> V_13 ) ) ;
if ( F_72 ( V_236 ) ) {
V_48 = - V_249 ;
goto V_351;
}
V_48 = F_68 ( V_8 , V_130 , & V_289 ,
V_4 , V_10 , V_236 ) ;
if ( V_48 )
goto V_351;
V_48 = F_76 ( V_8 , V_130 , & V_289 ,
V_4 , V_10 , V_236 ) ;
if ( V_48 )
goto V_37;
V_8 -> V_353 = false ;
}
V_48 = F_84 ( V_8 ) ;
if ( V_48 )
goto V_37;
V_48 = F_85 ( V_8 ) ;
if ( V_48 )
goto V_37;
#ifdef F_86
if ( V_8 -> V_354 )
V_346 . V_355 |=
F_19 ( V_356 ) ;
#endif
V_48 = F_35 ( V_8 , & V_348 ) ;
if ( V_48 )
goto V_37;
#ifdef F_86
V_140 = F_59 ( V_348 . V_280 ) ;
if ( V_140 >= sizeof( T_4 ) ) {
V_8 -> V_357 =
F_87 ( ( V_358 * ) V_348 . V_280 -> V_6 ) ;
}
#endif
F_61 ( & V_348 ) ;
F_88 ( V_286 , & V_8 -> V_247 ) ;
F_89 ( V_8 -> V_127 , V_344 ) ;
V_37:
if ( V_48 < 0 ) {
F_90 ( V_8 , V_359 ) ;
F_91 ( V_8 -> V_2 ) ;
F_81 ( V_8 ) ;
}
V_351:
F_7 ( & V_8 -> V_13 ) ;
return V_48 ;
}
static int F_92 ( struct V_7 * V_8 )
{
struct V_360 V_361 ;
static const T_1 V_362 [] = { V_349 } ;
int V_48 ;
F_93 ( & V_8 -> V_363 , & V_361 ,
V_362 , F_94 ( V_362 ) ,
NULL , NULL ) ;
V_48 = F_95 ( V_8 -> V_2 -> V_364 ) ;
if ( V_48 )
goto V_365;
V_48 = F_96 ( & V_8 -> V_363 , & V_361 , V_366 ) ;
F_97 ( V_48 ) ;
return V_48 ;
V_365:
F_98 ( & V_8 -> V_363 , & V_361 ) ;
return V_48 ;
}
int F_99 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_367 * V_127 = V_8 -> V_127 ;
int V_48 ;
F_100 ( & V_8 -> V_368 ) ;
V_48 = F_101 ( V_127 ) ;
if ( V_48 )
return V_48 ;
if ( V_130 -> V_369 ) {
V_127 -> V_370 = V_371 ;
if ( F_102 ( V_8 ) ) {
V_48 = F_92 ( V_8 ) ;
if ( V_48 )
return V_48 ;
}
F_4 ( & V_8 -> V_372 ) ;
F_11 ( V_373 , & V_8 -> V_374 ) ;
F_7 ( & V_8 -> V_372 ) ;
F_89 ( V_127 , false ) ;
return 0 ;
}
V_127 -> V_370 = V_375 ;
return F_82 ( V_2 , V_130 , false ) ;
}
static void F_103 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
struct V_376 * V_247 )
{
struct V_377 * V_167 = NULL ;
struct V_378 V_379 = {
. V_380 = - 1 ,
} ;
struct V_378 * V_381 = & V_379 ;
T_4 V_382 = V_247 -> V_383 ;
if ( V_382 == V_384 ) {
V_381 = NULL ;
goto V_385;
}
F_104 ( V_8 -> V_386 , 0 ) ;
if ( V_382 & V_387 )
V_379 . V_302 = true ;
if ( V_382 & V_388 )
V_379 . V_380 =
V_247 -> V_389 ;
if ( V_382 & ( V_390 |
V_391 ) )
V_379 . V_298 = true ;
if ( V_382 & V_392 )
V_379 . V_304 = true ;
if ( V_382 & V_393 )
V_379 . V_311 = true ;
if ( V_382 & V_394 )
V_379 . V_306 = true ;
if ( V_382 & V_395 )
V_379 . V_308 = true ;
if ( V_382 & V_396 )
V_379 . V_397 = true ;
if ( V_382 & V_398 )
V_379 . V_399 = true ;
if ( V_382 & V_400 )
V_379 . V_401 = true ;
if ( V_247 -> V_402 ) {
int V_403 = V_247 -> V_402 ;
int V_404 = V_247 -> V_405 ;
const T_3 * V_406 = V_247 -> V_407 ;
struct V_408 * V_409 = ( void * ) V_406 ;
int V_410 = V_404 - V_403 ;
if ( F_97 ( V_410 < 0 ) )
V_410 = 0 ;
if ( F_105 ( V_409 -> V_411 ) ) {
int V_412 = F_106 ( V_409 -> V_411 ) ;
int V_413 = 0 , V_414 = 4 ;
V_167 = F_107 ( V_403 , V_142 ) ;
if ( ! V_167 )
goto V_385;
memcpy ( F_108 ( V_167 , V_412 ) , V_406 , V_412 ) ;
V_406 += V_412 ;
V_403 -= V_412 ;
if ( F_109 ( V_409 -> V_411 ) ) {
if ( F_110 ( V_409 -> V_415 ) ) {
V_413 = V_8 -> V_94 ;
V_414 += V_8 -> V_95 ;
} else {
V_413 = V_8 -> V_90 ;
V_414 += V_8 -> V_92 ;
}
}
if ( V_410 >= V_414 ) {
V_414 = 0 ;
V_410 -= V_414 ;
} else {
V_414 -= V_410 ;
V_410 = 0 ;
}
V_403 -= V_413 + V_414 ;
V_406 += V_413 ;
memcpy ( F_108 ( V_167 , V_403 ) , V_406 , V_403 ) ;
if ( F_111 ( V_167 , V_4 -> V_30 , V_4 -> type ) )
goto V_385;
V_379 . V_416 = V_167 -> V_6 ;
V_379 . V_417 = V_167 -> V_140 ;
V_379 . V_418 = V_167 -> V_140 - V_410 ;
V_379 . V_419 = false ;
} else {
int V_420 = 4 ;
if ( V_410 >= 4 ) {
V_410 -= 4 ;
V_420 = 0 ;
} else {
V_420 -= V_410 ;
V_410 = 0 ;
}
V_403 -= V_420 ;
V_379 . V_416 = V_247 -> V_407 ;
V_379 . V_417 = V_403 ;
V_379 . V_418 = V_404 - V_410 ;
V_379 . V_419 = true ;
}
}
V_385:
F_112 ( V_4 , V_381 , V_142 ) ;
F_113 ( V_167 ) ;
}
static void F_114 ( struct V_58 * V_421 ,
struct V_44 * V_45 )
{
T_5 V_50 ;
V_50 = F_115 ( V_421 -> V_50 ) ;
V_45 -> V_49 . V_50 [ 0 ] = V_50 >> 40 ;
V_45 -> V_49 . V_50 [ 1 ] = V_50 >> 32 ;
V_45 -> V_49 . V_50 [ 2 ] = V_50 >> 24 ;
V_45 -> V_49 . V_50 [ 3 ] = V_50 >> 16 ;
V_45 -> V_49 . V_50 [ 4 ] = V_50 >> 8 ;
V_45 -> V_49 . V_50 [ 5 ] = V_50 ;
}
static void F_116 ( struct V_60 * V_421 ,
struct V_44 * V_45 )
{
V_45 -> V_100 . V_105 = F_117 ( V_421 -> V_105 ) ;
V_45 -> V_100 . V_104 = F_118 ( V_421 -> V_104 ) ;
}
static void F_119 ( struct V_7 * V_8 , struct V_58 * V_422 ,
struct V_54 * V_55 ,
struct V_40 * V_41 )
{
int V_46 ;
F_120 ( V_114 != V_423 ) ;
if ( V_55 && F_26 ( V_8 ) ) {
struct V_124 * V_125 ;
struct V_42 * V_43 ;
V_125 = F_27 ( V_55 ) ;
V_43 = F_28 ( V_125 -> V_43 [ V_41 -> V_82 ] ,
F_29 ( & V_8 -> V_13 ) ) ;
if ( F_30 ( ! V_43 ) )
return;
for ( V_46 = 0 ; V_46 < V_126 ; V_46 ++ ) {
struct V_44 V_45 = {} ;
int V_38 ;
F_114 ( & V_422 [ V_46 ] , & V_45 ) ;
F_121 ( V_41 , V_46 , & V_45 ) ;
for ( V_38 = 1 ; V_38 < V_8 -> V_127 -> V_128 ; V_38 ++ )
memcpy ( V_43 -> V_52 [ V_38 ] . V_50 [ V_46 ] ,
V_45 . V_49 . V_50 , V_53 ) ;
}
} else {
for ( V_46 = 0 ; V_46 < V_114 ; V_46 ++ ) {
struct V_44 V_45 = {} ;
F_114 ( & V_422 [ V_46 ] , & V_45 ) ;
F_121 ( V_41 , V_46 , & V_45 ) ;
}
}
}
static void F_122 ( struct V_60 * V_422 ,
struct V_40 * V_41 )
{
int V_46 ;
F_120 ( V_114 != V_423 ) ;
for ( V_46 = 0 ; V_46 < V_114 ; V_46 ++ ) {
struct V_44 V_45 = {} ;
F_116 ( & V_422 [ V_46 ] , & V_45 ) ;
F_121 ( V_41 , V_46 , & V_45 ) ;
}
}
static void F_123 ( struct V_7 * V_8 ,
struct V_40 * V_41 ,
struct V_424 * V_247 )
{
union V_425 * V_426 = & V_247 -> V_427 . V_426 . V_99 ;
switch ( V_41 -> V_66 ) {
case V_120 :
F_119 ( V_8 , V_426 -> V_122 . V_111 , NULL , V_41 ) ;
break;
case V_97 :
F_122 ( V_426 -> V_100 . V_111 , V_41 ) ;
break;
default:
F_30 ( 1 ) ;
}
}
static void F_124 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_54 * V_55 ,
struct V_40 * V_41 ,
void * V_56 )
{
struct V_428 * V_6 = V_56 ;
if ( V_6 -> V_429 )
return;
switch ( V_41 -> V_66 ) {
case V_67 :
case V_68 :
return;
case V_120 :
case V_97 :
break;
default:
V_6 -> V_429 = true ;
return;
}
V_6 -> V_78 ++ ;
if ( V_55 ) {
struct V_44 V_45 = {} ;
union V_425 * V_421 = & V_6 -> V_247 -> V_427 . V_426 . V_99 ;
if ( V_6 -> V_430 )
return;
switch ( V_41 -> V_66 ) {
case V_120 :
F_119 ( V_6 -> V_8 , V_421 -> V_122 . V_101 ,
V_55 , V_41 ) ;
F_125 ( & V_41 -> V_123 , F_115 ( V_421 -> V_122 . V_102 . V_50 ) ) ;
break;
case V_97 :
F_116 ( & V_421 -> V_100 . V_102 , & V_45 ) ;
F_122 ( V_421 -> V_100 . V_101 , V_41 ) ;
F_126 ( V_41 , & V_45 ) ;
break;
}
return;
}
if ( V_6 -> V_430 ) {
V_6 -> V_431 = V_41 ;
V_6 -> V_66 = V_41 -> V_66 ;
return;
}
if ( V_6 -> V_247 -> V_432 )
F_127 ( V_41 ) ;
else if ( V_6 -> V_431 == V_41 )
F_123 ( V_6 -> V_8 , V_41 , V_6 -> V_247 ) ;
}
static bool F_128 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
struct V_424 * V_247 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_428 V_433 = {
. V_8 = V_8 ,
. V_247 = V_247 ,
} ;
T_4 V_434 =
V_390 |
V_391 ;
if ( ! V_247 || ! V_4 -> V_115 . V_116 )
return false ;
if ( F_117 ( V_247 -> V_383 ) & V_434 )
return false ;
V_433 . V_430 = true ;
F_75 ( V_8 -> V_2 , V_4 ,
F_124 , & V_433 ) ;
if ( V_433 . V_429 )
return false ;
if ( ! V_433 . V_78 )
goto V_37;
if ( ! V_433 . V_431 )
return false ;
V_433 . V_430 = false ;
F_75 ( V_8 -> V_2 , V_4 ,
F_124 , & V_433 ) ;
if ( V_247 -> V_432 ) {
struct V_40 * V_41 ;
struct {
struct V_40 V_435 ;
T_3 V_41 [ 32 ] ;
} V_435 = {
. V_435 . V_66 = V_433 . V_66 ,
. V_435 . V_82 = V_247 -> V_427 . V_81 ,
} ;
switch ( V_433 . V_66 ) {
case V_120 :
V_435 . V_435 . V_84 = V_436 ;
memcpy ( V_435 . V_435 . V_41 , V_247 -> V_427 . V_437 ,
V_436 ) ;
break;
case V_97 :
V_435 . V_435 . V_84 = V_438 ;
memcpy ( V_435 . V_435 . V_41 , V_247 -> V_427 . V_437 , 16 ) ;
memcpy ( V_435 . V_435 . V_41 +
V_117 ,
V_247 -> V_427 . V_439 , 8 ) ;
break;
}
V_41 = F_129 ( V_4 , & V_435 . V_435 ) ;
if ( F_130 ( V_41 ) )
return false ;
F_123 ( V_8 , V_41 , V_247 ) ;
}
if ( V_247 -> V_432 ) {
V_20 V_19 =
F_131 ( F_115 ( V_247 -> V_19 ) ) ;
F_132 ( V_4 , V_4 -> V_115 . V_116 ,
( void * ) & V_19 , V_142 ) ;
}
V_37:
V_10 -> V_284 = true ;
V_10 -> V_283 = F_118 ( V_247 -> V_440 ) + 0x10 ;
return true ;
}
static struct V_424 *
F_133 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
T_4 V_441 = V_8 -> V_442 ;
struct V_443 {
T_4 V_21 ;
T_4 V_444 ;
} V_445 ;
struct V_133 V_134 = {
. V_76 = V_446 ,
. V_31 = V_278 ,
} ;
struct V_424 * V_247 , * V_447 ;
int V_48 , V_140 , V_448 ;
F_134 ( V_8 -> V_127 , V_441 ,
& V_445 , sizeof( V_445 ) ) ;
if ( V_445 . V_21 ) {
F_135 ( V_8 , L_6 ,
V_445 . V_21 , V_445 . V_444 ) ;
if ( V_445 . V_444 == V_449 ) {
struct V_378 V_379 = {
. V_311 = true ,
} ;
F_112 ( V_4 , & V_379 ,
V_142 ) ;
}
return F_136 ( - V_264 ) ;
}
V_48 = F_21 ( V_8 , V_450 , 0 , 0 , NULL ) ;
if ( V_48 )
F_52 ( V_8 , L_7 , V_48 ) ;
V_48 = F_35 ( V_8 , & V_134 ) ;
if ( V_48 ) {
F_52 ( V_8 , L_8 , V_48 ) ;
return F_136 ( V_48 ) ;
}
if ( ! V_134 . V_280 ) {
V_447 = F_136 ( - V_451 ) ;
goto V_452;
}
V_448 = sizeof( * V_447 ) ;
V_140 = F_59 ( V_134 . V_280 ) ;
if ( V_140 < V_448 ) {
F_52 ( V_8 , L_9 ) ;
V_447 = F_136 ( - V_264 ) ;
goto V_452;
}
V_247 = ( void * ) V_134 . V_280 -> V_6 ;
if ( V_140 != ( V_448 +
F_137 ( F_117 ( V_247 -> V_402 ) , 4 ) ) ) {
F_52 ( V_8 , L_9 ) ;
V_447 = F_136 ( - V_264 ) ;
goto V_452;
}
V_447 = F_80 ( V_247 , V_140 , V_142 ) ;
V_452:
F_61 ( & V_134 ) ;
return V_447 ;
}
static bool F_138 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
struct V_376 V_247 ;
struct V_424 * V_447 ;
int V_38 ;
bool V_453 ;
struct V_54 * V_236 ;
struct V_124 * V_290 ;
V_447 = F_133 ( V_8 , V_4 ) ;
if ( F_72 ( V_447 ) )
goto V_454;
V_247 . V_389 = F_118 ( V_447 -> V_389 ) ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ )
V_247 . V_455 [ V_38 ] =
F_118 ( V_447 -> V_455 [ V_38 ] ) ;
V_247 . V_383 = F_117 ( V_447 -> V_383 ) ;
V_247 . V_405 =
F_117 ( V_447 -> V_405 ) ;
V_247 . V_402 =
F_117 ( V_447 -> V_402 ) ;
V_247 . V_407 = V_447 -> V_407 ;
V_236 = F_28 (
V_8 -> V_265 [ 0 ] ,
F_29 ( & V_8 -> V_13 ) ) ;
if ( F_72 ( V_236 ) )
goto V_456;
V_290 = F_27 ( V_236 ) ;
for ( V_38 = 0 ; V_38 < V_126 ; V_38 ++ ) {
T_1 V_45 = V_247 . V_455 [ V_38 ] ;
V_45 += 0x10 ;
V_290 -> V_457 [ V_38 ] . V_458 = V_45 ;
}
F_7 ( & V_8 -> V_13 ) ;
F_103 ( V_8 , V_4 , & V_247 ) ;
V_453 = F_128 ( V_8 , V_4 , V_447 ) ;
F_36 ( V_447 ) ;
return V_453 ;
V_456:
F_36 ( V_447 ) ;
V_454:
F_7 ( & V_8 -> V_13 ) ;
return false ;
}
void F_139 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
struct V_424 * V_247 )
{
struct V_428 V_433 = {
. V_8 = V_8 ,
. V_247 = V_247 ,
} ;
if ( F_97 ( V_247 -> V_432 ) )
return;
V_433 . V_430 = true ;
F_70 ( V_8 , V_4 , F_124 , & V_433 ) ;
V_433 . V_430 = false ;
F_70 ( V_8 , V_4 , F_124 , & V_433 ) ;
}
static int
F_140 ( struct V_7 * V_8 ,
struct V_459 * V_460 )
{
struct V_461 * V_462 ;
struct V_133 V_134 = {
. V_76 = V_463 ,
. V_31 = V_278 ,
} ;
int V_48 , V_140 ;
V_48 = F_35 ( V_8 , & V_134 ) ;
if ( V_48 ) {
F_52 ( V_8 , L_10 , V_48 ) ;
return V_48 ;
}
if ( ! V_134 . V_280 ) {
V_48 = - V_451 ;
goto V_452;
}
V_140 = F_59 ( V_134 . V_280 ) ;
if ( V_140 < sizeof( * V_462 ) ) {
F_52 ( V_8 , L_11 ) ;
V_48 = - V_264 ;
goto V_452;
}
V_462 = ( void * ) V_134 . V_280 -> V_6 ;
V_460 -> V_464 = F_117 ( V_462 -> V_464 ) ;
memcpy ( V_460 -> V_465 , V_462 -> V_465 , sizeof( V_460 -> V_465 ) ) ;
#ifdef F_86
V_8 -> V_466 = F_117 ( V_462 -> V_467 ) ;
#endif
V_452:
F_61 ( & V_134 ) ;
return V_48 ;
}
static void F_141 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
struct V_468 * V_353 = NULL ;
struct V_378 V_379 = {
. V_380 = - 1 ,
} ;
struct V_378 * V_381 = & V_379 ;
struct V_459 V_462 ;
struct V_424 * V_447 ;
unsigned long V_464 ;
T_4 V_382 = 0 ;
int V_38 , V_469 , V_470 , V_48 ;
V_447 = F_133 ( V_8 , V_4 ) ;
if ( ! F_72 ( V_447 ) ) {
V_382 = F_117 ( V_447 -> V_383 ) ;
F_36 ( V_447 ) ;
}
if ( V_382 & V_393 )
V_379 . V_311 = true ;
if ( V_382 != V_384 )
goto V_37;
V_48 = F_140 ( V_8 , & V_462 ) ;
if ( V_48 || ! V_462 . V_464 ) {
V_381 = NULL ;
goto V_37;
}
V_464 = V_462 . V_464 ;
if ( V_8 -> V_340 ) {
V_470 = F_142 ( V_464 ) ;
} else {
F_52 ( V_8 , L_12 ) ;
V_470 = 0 ;
}
V_353 = F_44 ( sizeof( * V_353 ) +
( V_470 * sizeof( V_353 -> V_465 [ 0 ] ) ) ,
V_142 ) ;
if ( ! V_353 || ! V_470 )
goto V_471;
F_143 (i, &matched_profiles, mvm->n_nd_match_sets) {
struct V_472 * V_473 ;
struct V_474 * V_475 ;
int V_26 , V_342 = 0 ;
V_473 = & V_462 . V_465 [ V_38 ] ;
for ( V_469 = 0 ; V_469 < V_476 ; V_469 ++ )
V_342 += F_144 ( V_473 -> V_477 [ V_469 ] ) ;
V_475 = F_44 ( sizeof( * V_475 ) +
( V_342 * sizeof( * V_475 -> V_341 ) ) ,
V_142 ) ;
if ( ! V_475 )
goto V_471;
V_353 -> V_465 [ V_353 -> V_470 ++ ] = V_475 ;
V_26 = V_8 -> V_340 - V_38 - 1 ;
V_475 -> V_478 . V_479 = V_8 -> V_335 [ V_26 ] . V_478 . V_479 ;
memcpy ( V_475 -> V_478 . V_478 , V_8 -> V_335 [ V_26 ] . V_478 . V_478 ,
V_475 -> V_478 . V_479 ) ;
if ( V_8 -> V_343 < V_342 )
continue;
for ( V_469 = 0 ; V_469 < V_476 * 8 ; V_469 ++ )
if ( V_473 -> V_477 [ V_469 / 8 ] & ( F_145 ( V_469 % 8 ) ) )
V_475 -> V_341 [ V_475 -> V_342 ++ ] =
V_8 -> V_336 [ V_469 ] -> V_480 ;
}
V_471:
V_379 . V_353 = V_353 ;
V_37:
F_81 ( V_8 ) ;
F_7 ( & V_8 -> V_13 ) ;
F_112 ( V_4 , V_381 , V_142 ) ;
if ( V_353 ) {
for ( V_38 = 0 ; V_38 < V_353 -> V_470 ; V_38 ++ )
F_36 ( V_353 -> V_465 [ V_38 ] ) ;
F_36 ( V_353 ) ;
}
}
static void F_146 ( struct V_7 * V_8 )
{
#ifdef F_86
const struct V_481 * V_482 = & V_8 -> V_483 -> V_482 [ V_484 ] ;
T_4 V_140 = V_482 -> V_485 [ V_486 ] . V_140 ;
T_4 V_487 = V_482 -> V_485 [ V_486 ] . V_220 ;
if ( ! V_8 -> V_488 )
return;
if ( ! V_8 -> V_489 ) {
V_8 -> V_489 = F_44 ( V_140 , V_142 ) ;
if ( ! V_8 -> V_489 )
return;
}
F_134 ( V_8 -> V_127 , V_487 , V_8 -> V_489 , V_140 ) ;
#endif
}
static void F_147 ( void * V_6 , T_3 * V_490 ,
struct V_3 * V_4 )
{
if ( V_6 == V_4 )
return;
if ( V_4 -> type == V_491 )
F_148 ( V_4 ) ;
}
static int F_149 ( struct V_7 * V_8 , bool V_344 )
{
struct V_3 * V_4 = NULL ;
int V_48 ;
enum V_492 V_493 ;
bool V_453 = false ;
F_4 ( & V_8 -> V_13 ) ;
V_4 = F_83 ( V_8 ) ;
if ( F_72 ( V_4 ) )
goto V_138;
V_48 = F_150 ( V_8 -> V_127 , & V_493 , V_344 ) ;
if ( V_48 )
goto V_138;
if ( V_493 != V_494 ) {
F_135 ( V_8 , L_13 ) ;
goto V_138;
}
F_146 ( V_8 ) ;
F_151 ( V_8 ) ;
if ( V_8 -> V_353 ) {
F_141 ( V_8 , V_4 ) ;
goto V_37;
} else {
V_453 = F_138 ( V_8 , V_4 ) ;
#ifdef F_86
if ( V_453 )
V_8 -> V_495 = V_4 ;
#endif
goto V_496;
}
V_138:
F_81 ( V_8 ) ;
F_7 ( & V_8 -> V_13 ) ;
V_496:
if ( ! V_344 )
F_152 ( V_8 -> V_2 ,
V_497 ,
F_147 , V_453 ? V_4 : NULL ) ;
V_37:
F_66 ( V_286 , & V_8 -> V_247 ) ;
F_66 ( V_498 , & V_8 -> V_247 ) ;
F_90 ( V_8 , V_359 ) ;
return 1 ;
}
static int F_153 ( struct V_7 * V_8 )
{
F_154 ( V_8 -> V_127 ) ;
return F_149 ( V_8 , false ) ;
}
static int F_155 ( struct V_7 * V_8 )
{
bool V_499 ;
enum V_492 V_493 ;
struct V_367 * V_127 = V_8 -> V_127 ;
F_150 ( V_127 , & V_493 , false ) ;
F_4 ( & V_8 -> V_372 ) ;
F_156 ( V_373 , & V_8 -> V_374 ) ;
V_499 = F_157 ( V_500 ,
& V_8 -> V_374 ) ;
F_7 ( & V_8 -> V_372 ) ;
if ( V_499 ) {
F_158 ( V_8 , L_14 ) ;
F_159 ( V_8 ) ;
}
F_154 ( V_127 ) ;
if ( F_102 ( V_8 ) ) {
int V_48 = F_160 ( V_8 -> V_2 -> V_364 ) ;
if ( V_48 )
return V_48 ;
}
return 0 ;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_48 ;
if ( V_8 -> V_127 -> V_370 == V_371 )
V_48 = F_155 ( V_8 ) ;
else
V_48 = F_153 ( V_8 ) ;
V_8 -> V_127 -> V_370 = V_501 ;
return V_48 ;
}
void F_162 ( struct V_1 * V_2 , bool V_502 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_163 ( V_8 -> V_127 -> V_386 , V_502 ) ;
}
static int F_164 ( struct V_503 * V_503 , struct V_504 * V_504 )
{
struct V_7 * V_8 = V_503 -> V_505 ;
int V_138 ;
if ( V_8 -> V_506 )
return - V_337 ;
V_504 -> V_507 = V_503 -> V_505 ;
F_165 ( V_8 -> V_2 ) ;
F_166 () ;
V_8 -> V_127 -> V_370 = V_375 ;
F_167 () ;
V_138 = F_82 ( V_8 -> V_2 , V_8 -> V_2 -> V_508 -> V_509 , true ) ;
F_168 () ;
if ( V_138 > 0 )
V_138 = - V_249 ;
if ( V_138 ) {
F_169 ( V_8 -> V_2 ) ;
return V_138 ;
}
V_8 -> V_506 = true ;
V_8 -> V_495 = NULL ;
return 0 ;
}
static T_8 F_170 ( struct V_504 * V_504 , char T_9 * V_510 ,
T_10 V_511 , T_11 * V_512 )
{
struct V_7 * V_8 = V_504 -> V_507 ;
T_4 V_513 ;
while ( true ) {
if ( V_8 -> V_357 ) {
V_513 = F_171 ( V_8 -> V_127 ,
V_8 -> V_357 ) ;
if ( V_513 )
break;
}
if ( F_172 ( 100 ) )
break;
}
return 0 ;
}
static void F_173 ( void * V_56 , T_3 * V_490 ,
struct V_3 * V_4 )
{
if ( V_56 == V_4 )
return;
if ( V_4 -> type == V_491 )
F_174 ( V_4 ) ;
}
static int F_175 ( struct V_503 * V_503 , struct V_504 * V_504 )
{
struct V_7 * V_8 = V_503 -> V_505 ;
int V_514 = 10 ;
V_8 -> V_506 = false ;
F_167 () ;
F_149 ( V_8 , true ) ;
F_168 () ;
V_8 -> V_127 -> V_370 = V_501 ;
F_176 ( & V_8 -> V_363 ) ;
F_91 ( V_8 -> V_2 ) ;
while ( F_177 ( V_286 , & V_8 -> V_247 ) &&
V_514 > 0 ) {
V_514 -- ;
F_178 ( 1000 ) ;
}
if ( V_514 == 0 )
F_52 ( V_8 , L_15 ) ;
F_179 (
V_8 -> V_2 , V_497 ,
F_173 , V_8 -> V_495 ) ;
F_169 ( V_8 -> V_2 ) ;
return 0 ;
}
