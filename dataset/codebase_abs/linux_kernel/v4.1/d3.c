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
F_9 ( & V_23 -> V_27 ) ;
F_10 (ifa, &idev->addr_list, if_list) {
V_10 -> V_28 [ V_26 ] = V_25 -> V_29 ;
V_26 ++ ;
if ( V_26 >= V_30 )
break;
}
F_11 ( & V_23 -> V_27 ) ;
V_10 -> V_31 = V_26 ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_26 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
V_10 -> V_32 = V_26 ;
}
static void F_13 ( T_1 * V_33 , T_2 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
V_34 [ V_35 ] = F_14 ( V_33 [ V_35 ] ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 ,
struct V_39 * V_40 ,
void * V_41 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_42 * V_6 = V_41 ;
struct V_43 * V_43 , * V_44 = NULL ;
struct V_45 * V_45 , * V_46 = NULL ;
struct V_47 * V_48 ;
T_3 * V_49 ;
struct V_50 V_51 ;
T_4 V_52 = 0 ;
T_1 V_33 [ V_36 ] ;
int V_53 , V_35 ;
F_4 ( & V_8 -> V_13 ) ;
switch ( V_40 -> V_54 ) {
case V_55 :
case V_56 : {
struct {
struct V_57 V_58 ;
struct V_59 V_60 ;
} V_61 V_62 = {
. V_58 . V_63 =
F_16 ( F_17 ( V_10 -> V_64 ,
V_10 -> V_65 ) ) ,
. V_58 . V_66 = 1 ,
. V_58 . V_67 = V_68 ,
. V_60 . V_69 = V_40 -> V_70 ,
. V_60 . V_71 = V_40 -> V_72 ,
} ;
if ( V_40 -> V_73 & V_74 )
break;
memcpy ( & V_62 . V_60 . V_40 [ 3 ] , V_40 -> V_40 , V_40 -> V_72 ) ;
if ( V_40 -> V_70 == V_10 -> V_32 ) {
V_62 . V_60 . V_75 = 0 ;
} else {
V_6 -> V_76 ++ ;
V_62 . V_60 . V_75 = V_6 -> V_76 ;
}
V_53 = F_18 ( V_8 , V_77 , 0 , sizeof( V_62 ) , & V_62 ) ;
V_6 -> error = V_53 != 0 ;
V_8 -> V_78 = V_40 -> V_79 ;
V_8 -> V_80 = V_40 -> V_81 ;
V_8 -> V_82 = V_40 -> V_79 ;
V_8 -> V_83 = V_40 -> V_81 ;
goto V_84;
}
default:
V_6 -> error = true ;
goto V_84;
case V_85 :
goto V_84;
case V_86 :
if ( V_38 ) {
V_45 = V_6 -> V_87 -> V_88 . V_89 . V_90 ;
V_46 = & V_6 -> V_87 -> V_88 . V_89 . V_91 ;
V_48 = V_6 -> V_89 -> V_92 ;
F_19 ( V_40 , & V_51 ) ;
V_46 -> V_93 = F_14 ( V_51 . V_89 . V_93 ) ;
V_46 -> V_94 = F_16 ( V_51 . V_89 . V_94 ) ;
F_20 ( V_40 , V_51 . V_89 . V_94 , V_33 ) ;
F_13 ( V_33 , V_6 -> V_89 -> V_95 . V_33 ) ;
memcpy ( V_6 -> V_89 -> V_96 . V_95 ,
& V_40 -> V_40 [ V_97 ] ,
V_98 ) ;
V_49 = V_6 -> V_89 -> V_96 . V_99 ;
} else {
V_45 =
V_6 -> V_87 -> V_88 . V_89 . V_100 ;
V_48 = V_6 -> V_89 -> V_101 ;
V_49 = V_6 -> V_89 -> V_96 . V_102 ;
}
for ( V_35 = 0 ; V_35 < V_103 ; V_35 ++ ) {
F_21 ( V_40 , V_35 , & V_51 ) ;
V_45 [ V_35 ] . V_93 = F_14 ( V_51 . V_89 . V_93 ) ;
V_45 [ V_35 ] . V_94 = F_16 ( V_51 . V_89 . V_94 ) ;
if ( V_51 . V_89 . V_94 > V_52 )
V_52 = V_51 . V_89 . V_94 ;
}
F_22 ( V_40 , V_4 -> V_104 . V_105 ,
V_52 , V_33 ) ;
F_13 ( V_33 , V_48 [ 0 ] . V_33 ) ;
F_22 ( V_40 , V_4 -> V_104 . V_105 ,
V_52 + 1 , V_33 ) ;
F_13 ( V_33 , V_48 [ 1 ] . V_33 ) ;
memcpy ( V_49 ,
& V_40 -> V_40 [ V_106 ] ,
V_98 ) ;
V_6 -> V_107 = true ;
V_6 -> V_108 = true ;
break;
case V_109 :
if ( V_38 ) {
T_3 * V_110 = V_51 . V_111 . V_110 ;
V_43 = V_6 -> V_87 -> V_88 . V_112 . V_90 ;
V_44 = & V_6 -> V_87 -> V_88 . V_112 . V_91 ;
F_19 ( V_40 , & V_51 ) ;
V_44 -> V_110 = F_5 ( ( V_113 ) V_110 [ 5 ] |
( ( V_113 ) V_110 [ 4 ] << 8 ) |
( ( V_113 ) V_110 [ 3 ] << 16 ) |
( ( V_113 ) V_110 [ 2 ] << 24 ) |
( ( V_113 ) V_110 [ 1 ] << 32 ) |
( ( V_113 ) V_110 [ 0 ] << 40 ) ) ;
} else {
V_43 = V_6 -> V_87 -> V_88 . V_112 . V_100 ;
}
for ( V_35 = 0 ; V_35 < V_103 ; V_35 ++ ) {
T_3 * V_110 = V_51 . V_111 . V_110 ;
F_21 ( V_40 , V_35 , & V_51 ) ;
V_43 -> V_110 = F_5 ( ( V_113 ) V_110 [ 5 ] |
( ( V_113 ) V_110 [ 4 ] << 8 ) |
( ( V_113 ) V_110 [ 3 ] << 16 ) |
( ( V_113 ) V_110 [ 2 ] << 24 ) |
( ( V_113 ) V_110 [ 1 ] << 32 ) |
( ( V_113 ) V_110 [ 0 ] << 40 ) ) ;
}
V_6 -> V_108 = true ;
break;
}
if ( V_40 -> V_73 & V_74 ) {
V_40 -> V_114 = 0 ;
V_8 -> V_78 = V_40 -> V_79 ;
V_8 -> V_80 = V_40 -> V_81 ;
} else {
V_40 -> V_114 = 1 ;
V_8 -> V_82 = V_40 -> V_79 ;
V_8 -> V_83 = V_40 -> V_81 ;
}
V_53 = F_23 ( V_8 , V_4 , V_38 , V_40 , true ) ;
V_6 -> error = V_53 != 0 ;
V_84:
F_7 ( & V_8 -> V_13 ) ;
}
static int F_24 ( struct V_7 * V_8 ,
struct V_115 * V_116 )
{
struct V_117 * V_118 ;
struct V_119 V_120 = {
. V_64 = V_121 ,
. V_122 [ 0 ] = V_123 ,
} ;
int V_35 , V_124 ;
if ( ! V_116 -> V_125 )
return 0 ;
V_120 . V_126 [ 0 ] = sizeof( * V_118 ) +
V_116 -> V_125 * sizeof( struct V_127 ) ;
V_118 = F_25 ( V_120 . V_126 [ 0 ] , V_128 ) ;
if ( ! V_118 )
return - V_129 ;
V_118 -> V_125 = F_16 ( V_116 -> V_125 ) ;
for ( V_35 = 0 ; V_35 < V_116 -> V_125 ; V_35 ++ ) {
int V_130 = F_26 ( V_116 -> V_131 [ V_35 ] . V_132 , 8 ) ;
memcpy ( & V_118 -> V_131 [ V_35 ] . V_133 ,
V_116 -> V_131 [ V_35 ] . V_133 , V_130 ) ;
memcpy ( & V_118 -> V_131 [ V_35 ] . V_134 ,
V_116 -> V_131 [ V_35 ] . V_134 ,
V_116 -> V_131 [ V_35 ] . V_132 ) ;
V_118 -> V_131 [ V_35 ] . V_135 = V_130 ;
V_118 -> V_131 [ V_35 ] . V_136 =
V_116 -> V_131 [ V_35 ] . V_132 ;
}
V_120 . V_6 [ 0 ] = V_118 ;
V_124 = F_27 ( V_8 , & V_120 ) ;
F_28 ( V_118 ) ;
return V_124 ;
}
static T_2 F_29 ( int V_126 , T_5 V_137 , T_5 V_138 )
{
T_6 V_139 = F_30 ( V_126 , V_137 , V_138 , 0 ) ;
return F_14 ( F_31 ( ( V_140 V_141 ) V_139 ) ) ;
}
static void F_32 ( struct V_3 * V_4 ,
struct V_142 * V_143 ,
void * V_144 , T_3 * V_133 ,
T_2 * V_145 ,
enum V_146 V_147 )
{
struct {
struct V_148 V_149 ;
struct V_150 V_151 ;
struct V_152 V_143 ;
T_3 V_6 [] ;
} V_61 * V_153 = V_144 ;
T_1 V_154 = sizeof( struct V_150 ) + sizeof( struct V_152 ) ;
int V_35 ;
V_153 -> V_149 . V_155 = F_33 ( V_156 ) ,
V_153 -> V_151 . V_157 = 4 ;
V_153 -> V_151 . V_158 = 5 ;
V_153 -> V_151 . V_159 = V_160 ;
switch ( V_147 ) {
case V_161 :
case V_162 :
case V_163 :
memcpy ( V_153 -> V_149 . V_164 , V_143 -> V_165 , V_166 ) ;
memcpy ( V_153 -> V_149 . V_167 , V_4 -> V_29 , V_166 ) ;
V_153 -> V_151 . V_168 = 128 ;
V_153 -> V_151 . V_137 = V_143 -> V_169 ;
V_153 -> V_151 . V_138 = V_143 -> V_170 ;
V_153 -> V_143 . V_171 = F_33 ( V_143 -> V_172 ) ;
V_153 -> V_143 . V_173 = F_33 ( V_143 -> V_174 ) ;
V_153 -> V_143 . V_175 = sizeof( struct V_152 ) / 4 ;
V_153 -> V_143 . V_176 = F_33 ( 65000 ) ;
break;
case V_177 :
case V_178 :
case V_179 :
memcpy ( V_153 -> V_149 . V_164 , V_4 -> V_29 , V_166 ) ;
memcpy ( V_153 -> V_149 . V_167 , V_143 -> V_165 , V_166 ) ;
V_153 -> V_151 . V_137 = V_143 -> V_170 ;
V_153 -> V_151 . V_138 = V_143 -> V_169 ;
V_153 -> V_143 . V_171 = F_33 ( V_143 -> V_174 ) ;
V_153 -> V_143 . V_173 = F_33 ( V_143 -> V_172 ) ;
break;
default:
F_34 ( 1 ) ;
return;
}
switch ( V_147 ) {
case V_161 :
memset ( V_153 -> V_6 , 0x01 , 8 ) ;
V_154 += 8 ;
V_153 -> V_143 . V_175 = ( sizeof( struct V_152 ) + 8 ) / 4 ;
V_153 -> V_143 . V_180 = 1 ;
break;
case V_162 :
V_154 += V_143 -> V_181 ;
memcpy ( V_153 -> V_6 , V_143 -> V_182 , V_143 -> V_181 ) ;
V_153 -> V_143 . V_183 = 1 ;
V_153 -> V_143 . V_184 = 1 ;
break;
case V_163 :
V_153 -> V_143 . V_185 = 1 ;
V_153 -> V_143 . V_184 = 1 ;
break;
case V_177 :
V_153 -> V_143 . V_180 = 1 ;
V_153 -> V_143 . V_184 = 1 ;
break;
case V_178 :
V_153 -> V_143 . V_184 = 1 ;
break;
case V_179 :
V_154 += V_143 -> V_186 ;
V_153 -> V_143 . V_183 = 1 ;
V_153 -> V_143 . V_184 = 1 ;
memcpy ( V_153 -> V_6 , V_143 -> V_187 , V_143 -> V_186 ) ;
break;
}
switch ( V_147 ) {
case V_161 :
case V_162 :
case V_163 :
V_153 -> V_151 . V_188 = F_33 ( V_154 ) ;
V_153 -> V_151 . V_139 = F_35 ( & V_153 -> V_151 , V_153 -> V_151 . V_158 ) ;
break;
case V_179 :
for ( V_35 = 0 ; V_35 < F_26 ( V_143 -> V_186 , 8 ) ; V_35 ++ ) {
T_3 V_189 = V_143 -> V_190 [ V_35 ] ;
V_133 [ V_35 + 6 ] |= V_189 << 6 ;
if ( V_35 + 1 < F_26 ( V_143 -> V_186 , 8 ) )
V_133 [ V_35 + 7 ] = V_189 >> 2 ;
}
case V_177 :
case V_178 :
V_133 [ 0 ] = 0xff ;
V_133 [ 1 ] = 0x7f ;
V_133 [ 2 ] = 0x80 ;
V_133 [ 3 ] = 0xfc ;
V_133 [ 4 ] = 0x3f ;
V_133 [ 5 ] = 0x80 ;
break;
} ;
* V_145 = F_29 ( V_154 - sizeof( struct V_150 ) ,
V_153 -> V_151 . V_137 , V_153 -> V_151 . V_138 ) ;
}
static int F_36 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
struct V_142 * V_143 )
{
struct V_191 * V_192 ;
struct V_119 V_120 = {
. V_64 = V_193 ,
. V_126 = { sizeof( * V_192 ) , } ,
. V_122 = { V_123 , } ,
} ;
int V_53 ;
if ( ! V_143 )
return 0 ;
V_192 = F_37 ( sizeof( * V_192 ) , V_128 ) ;
if ( ! V_192 )
return - V_129 ;
V_120 . V_6 [ 0 ] = V_192 ;
V_192 -> V_194 = 10 ;
V_192 -> V_195 = 10 ;
V_192 -> V_196 = 1 ;
V_192 -> V_197 = 1 ;
F_32 (
V_4 , V_143 , V_192 -> V_198 . V_6 , NULL ,
& V_192 -> V_198 . V_199 . V_200 ,
V_161 ) ;
V_192 -> V_198 . V_199 . V_201 = 0 ;
F_32 (
V_4 , V_143 , V_192 -> V_202 . V_6 , V_192 -> V_202 . V_203 ,
& V_192 -> V_202 . V_199 . V_200 ,
V_177 ) ;
V_192 -> V_202 . V_199 . V_201 = 0 ;
F_32 (
V_4 , V_143 , V_192 -> V_204 . V_6 , NULL ,
& V_192 -> V_204 . V_199 . V_200 ,
V_162 ) ;
V_192 -> V_204 . V_199 . V_201 =
F_14 ( V_143 -> V_181 ) ;
V_192 -> V_205 = V_143 -> V_206 . V_207 ;
V_192 -> V_208 = V_143 -> V_206 . V_126 ;
V_192 -> V_209 = F_16 ( V_143 -> V_206 . V_210 ) ;
V_192 -> V_211 = F_14 ( V_143 -> V_212 ) ;
if ( V_143 -> V_213 . V_126 ) {
V_192 -> V_214 = V_143 -> V_213 . V_207 ;
V_192 -> V_215 = V_143 -> V_213 . V_126 ;
V_192 -> V_216 =
F_14 ( V_143 -> V_217 % V_143 -> V_213 . V_126 ) ;
memcpy ( V_192 -> V_218 , V_143 -> V_213 . V_219 ,
V_143 -> V_217 ) ;
} else {
V_192 -> V_216 = F_14 ( 65535 ) ;
}
F_32 (
V_4 , V_143 , V_192 -> V_220 . V_6 ,
V_192 -> V_220 . V_203 ,
& V_192 -> V_220 . V_199 . V_200 ,
V_178 ) ;
V_192 -> V_220 . V_199 . V_201 = 0 ;
F_32 (
V_4 , V_143 , V_192 -> V_221 . V_6 , V_192 -> V_221 . V_203 ,
& V_192 -> V_221 . V_199 . V_200 ,
V_179 ) ;
V_192 -> V_221 . V_199 . V_201 =
F_14 ( V_143 -> V_186 ) ;
F_32 (
V_4 , V_143 , V_192 -> V_222 . V_6 , NULL ,
& V_192 -> V_222 . V_199 . V_200 ,
V_163 ) ;
V_192 -> V_222 . V_199 . V_201 = 0 ;
V_53 = F_27 ( V_8 , & V_120 ) ;
F_28 ( V_192 ) ;
return V_53 ;
}
static int F_38 ( struct V_7 * V_8 , struct V_3 * V_4 ,
struct V_37 * V_223 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_224 * V_225 ;
T_3 V_226 , V_227 ;
struct V_228 V_229 ;
int V_53 , V_35 ;
struct V_230 V_231 = {} ;
struct V_232 V_233 = {} ;
T_4 V_234 ;
if ( F_34 ( ! V_10 -> V_235 ) )
return - V_236 ;
F_39 () ;
V_225 = F_40 ( V_4 -> V_237 ) ;
if ( F_34 ( ! V_225 ) ) {
F_41 () ;
return - V_236 ;
}
V_229 = V_225 -> V_238 ;
V_226 = V_225 -> V_239 ;
V_227 = V_225 -> V_240 ;
F_41 () ;
V_53 = F_42 ( V_8 , V_10 -> V_235 , & V_229 ,
V_226 , V_227 ) ;
if ( V_53 )
return V_53 ;
V_10 -> V_241 = false ;
if ( F_34 ( ! V_4 -> V_104 . V_242 ) )
return - V_236 ;
V_53 = F_43 ( V_8 , V_4 ) ;
if ( V_53 )
return V_53 ;
V_231 . V_243 =
F_16 ( F_17 ( V_10 -> V_235 -> V_64 ,
V_10 -> V_235 -> V_65 ) ) ;
V_231 . V_244 = F_16 ( V_245 ) ;
V_231 . V_246 =
F_16 ( F_17 ( V_10 -> V_235 -> V_64 ,
V_10 -> V_235 -> V_65 ) ) ;
V_231 . V_247 [ 0 ] = F_16 ( F_17 ( V_10 -> V_64 ,
V_10 -> V_65 ) ) ;
for ( V_35 = 1 ; V_35 < V_248 ; V_35 ++ )
V_231 . V_247 [ V_35 ] = F_16 ( V_249 ) ;
V_234 = 0 ;
V_53 = F_44 ( V_8 , V_250 ,
sizeof( V_231 ) , & V_231 ,
& V_234 ) ;
if ( V_53 ) {
F_45 ( V_8 , L_1 , V_53 ) ;
return V_53 ;
}
if ( V_234 ) {
F_45 ( V_8 , L_2 , V_234 ) ;
return - V_251 ;
}
V_53 = F_46 ( V_8 , V_223 , false ) ;
if ( V_53 )
return V_53 ;
F_47 ( V_8 -> V_252 [ V_10 -> V_253 ] , V_223 ) ;
V_53 = F_48 ( V_8 , V_4 , false , NULL ) ;
if ( V_53 )
return V_53 ;
V_233 . V_254 [ 0 ] . V_243 =
F_16 ( F_17 ( V_10 -> V_235 -> V_64 ,
V_10 -> V_235 -> V_65 ) ) ;
V_233 . V_254 [ 0 ] . V_255 = F_16 ( V_256 ) ;
V_233 . V_254 [ 0 ] . V_257 = F_16 ( V_256 ) ;
for ( V_35 = 1 ; V_35 < V_258 ; V_35 ++ )
V_233 . V_254 [ V_35 ] . V_243 = F_16 ( V_249 ) ;
V_53 = F_18 ( V_8 , V_259 , 0 ,
sizeof( V_233 ) , & V_233 ) ;
if ( V_53 )
F_45 ( V_8 , L_3 , V_53 ) ;
if ( F_49 ( V_8 ) && F_50 ( V_8 ) )
F_45 ( V_8 , L_4 ) ;
return 0 ;
}
static int F_51 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_260 V_261 = {
. V_262 = F_16 ( V_263 ) ,
. V_63 =
F_16 ( F_17 ( V_10 -> V_64 ,
V_10 -> V_65 ) ) ,
} ;
struct V_119 V_120 = {
. V_64 = V_264 ,
. V_73 = V_265 ,
} ;
int V_124 ;
T_4 V_266 ;
V_120 . V_6 [ 0 ] = & V_261 ;
V_120 . V_126 [ 0 ] = sizeof( V_261 ) ;
V_124 = F_27 ( V_8 , & V_120 ) ;
if ( V_124 )
return V_124 ;
V_266 = F_52 ( V_120 . V_267 ) ;
if ( V_266 < sizeof( T_2 ) ) {
V_124 = - V_236 ;
} else {
V_124 = F_53 ( ( T_2 * ) V_120 . V_267 -> V_6 ) ;
V_124 = ( T_1 ) ( V_124 - 0x10 ) ;
}
F_54 ( & V_120 ) ;
return V_124 ;
}
void F_55 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_260 V_261 = {
. V_262 = F_16 ( V_268 ) ,
. V_63 =
F_16 ( F_17 ( V_10 -> V_64 ,
V_10 -> V_65 ) ) ,
. V_269 = F_14 ( V_10 -> V_270 ) ,
} ;
if ( ! V_10 -> V_271 )
return;
V_10 -> V_271 = false ;
if ( F_18 ( V_8 , V_264 , 0 ,
sizeof( V_261 ) , & V_261 ) )
F_45 ( V_8 , L_5 ) ;
}
static int F_56 ( struct V_7 * V_8 )
{
F_57 ( V_8 ) ;
F_58 ( V_8 -> V_272 ) ;
F_59 ( V_273 , & V_8 -> V_234 ) ;
memset ( V_8 -> V_274 , 0 , sizeof( V_8 -> V_274 ) ) ;
V_8 -> V_78 = 0 ;
V_8 -> V_80 = 0 ;
V_8 -> V_78 = 0 ;
V_8 -> V_80 = 0 ;
return F_60 ( V_8 ) ;
}
static int
F_61 ( struct V_7 * V_8 ,
struct V_115 * V_116 ,
struct V_275 * V_276 ,
struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_37 * V_223 )
{
int V_53 ;
struct V_277 * V_278 = F_62 ( V_223 ) ;
V_276 -> V_279 =
V_223 -> V_280 . V_281 ;
V_53 = F_51 ( V_8 , V_4 ) ;
if ( V_53 < 0 )
return V_53 ;
V_276 -> V_282 = F_14 ( V_53 ) ;
F_63 ( V_278 , V_276 ) ;
if ( V_116 -> V_283 )
V_276 -> V_284 |=
F_16 ( V_285 |
V_286 ) ;
if ( V_116 -> V_287 )
V_276 -> V_284 |=
F_16 ( V_288 ) ;
if ( V_116 -> V_289 )
V_276 -> V_284 |=
F_16 ( V_290 ) ;
if ( V_116 -> V_291 )
V_276 -> V_284 |=
F_16 ( V_292 ) ;
if ( V_116 -> V_293 )
V_276 -> V_284 |=
F_16 ( V_294 ) ;
if ( V_116 -> V_125 )
V_276 -> V_284 |=
F_16 ( V_295 ) ;
if ( V_116 -> V_296 )
V_276 -> V_284 |=
F_16 ( V_297 ) ;
if ( V_116 -> V_143 ) {
V_276 -> V_284 |=
F_16 ( V_298 |
V_299 |
V_300 |
V_286 ) ;
}
return 0 ;
}
static int
F_64 ( struct V_7 * V_8 ,
struct V_115 * V_116 ,
struct V_275 * V_276 ,
struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_37 * V_223 )
{
struct V_301 V_302 = {} ;
struct V_303 V_304 = {} ;
struct V_42 V_305 = {
. V_108 = false ,
. V_89 = & V_304 ,
. V_107 = false ,
} ;
int V_53 ;
V_53 = F_56 ( V_8 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_38 ( V_8 , V_4 , V_223 ) ;
if ( V_53 )
return V_53 ;
V_305 . V_87 = F_37 ( sizeof( * V_305 . V_87 ) , V_128 ) ;
if ( ! V_305 . V_87 )
return - V_129 ;
if ( ! V_11 . V_12 ) {
F_7 ( & V_8 -> V_13 ) ;
F_65 ( V_8 -> V_2 , V_4 ,
F_15 ,
& V_305 ) ;
F_4 ( & V_8 -> V_13 ) ;
if ( V_305 . error ) {
V_53 = - V_251 ;
goto V_34;
}
if ( V_305 . V_108 ) {
struct V_119 V_306 = {
. V_64 = V_307 ,
. V_6 [ 0 ] = V_305 . V_87 ,
. V_122 [ 0 ] = V_123 ,
. V_126 [ 0 ] = sizeof( * V_305 . V_87 ) ,
} ;
V_53 = F_27 ( V_8 , & V_306 ) ;
if ( V_53 )
goto V_34;
}
if ( V_305 . V_107 ) {
V_53 = F_18 ( V_8 ,
V_308 ,
0 , sizeof( V_304 ) ,
& V_304 ) ;
if ( V_53 )
goto V_34;
}
if ( V_10 -> V_14 . V_21 ) {
memset ( & V_302 , 0 , sizeof( V_302 ) ) ;
memcpy ( V_302 . V_17 , V_10 -> V_14 . V_17 ,
V_18 ) ;
V_302 . V_309 = F_14 ( V_18 ) ;
memcpy ( V_302 . V_15 , V_10 -> V_14 . V_15 ,
V_16 ) ;
V_302 . V_310 = F_14 ( V_16 ) ;
V_302 . V_19 = V_10 -> V_14 . V_19 ;
V_53 = F_18 ( V_8 ,
V_311 , 0 ,
sizeof( V_302 ) ,
& V_302 ) ;
if ( V_53 )
goto V_34;
}
}
V_53 = F_18 ( V_8 , V_312 , 0 ,
sizeof( * V_276 ) ,
V_276 ) ;
if ( V_53 )
goto V_34;
V_53 = F_24 ( V_8 , V_116 ) ;
if ( V_53 )
goto V_34;
V_53 = F_66 ( V_8 , V_4 , false , 0 ) ;
if ( V_53 )
goto V_34;
V_53 = F_36 ( V_8 , V_4 , V_116 -> V_143 ) ;
V_34:
F_28 ( V_305 . V_87 ) ;
return V_53 ;
}
static int
F_67 ( struct V_7 * V_8 ,
struct V_115 * V_116 ,
struct V_313 * V_314 ,
struct V_3 * V_4 )
{
struct V_275 V_276 = {} ;
int V_53 ;
V_53 = F_56 ( V_8 ) ;
if ( V_53 )
return V_53 ;
if ( V_116 -> V_296 )
V_276 . V_284 |=
F_16 ( V_297 ) ;
V_53 = F_18 ( V_8 , V_312 , 0 ,
sizeof( V_276 ) ,
& V_276 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_68 ( V_8 , V_4 , V_314 , & V_8 -> V_315 ) ;
if ( V_53 )
return V_53 ;
if ( F_34 ( V_8 -> V_316 || V_8 -> V_317 ) )
return - V_318 ;
if ( V_314 -> V_319 ) {
V_8 -> V_316 = F_69 ( V_314 -> V_320 ,
sizeof( * V_314 -> V_320 ) *
V_314 -> V_319 ,
V_128 ) ;
if ( V_8 -> V_316 )
V_8 -> V_321 = V_314 -> V_319 ;
}
V_8 -> V_317 = F_69 ( V_314 -> V_322 ,
sizeof( * V_314 -> V_322 ) *
V_314 -> V_323 ,
V_128 ) ;
if ( V_8 -> V_317 )
V_8 -> V_324 = V_314 -> V_323 ;
return 0 ;
}
static void F_70 ( struct V_7 * V_8 )
{
F_28 ( V_8 -> V_316 ) ;
V_8 -> V_316 = NULL ;
V_8 -> V_321 = 0 ;
F_28 ( V_8 -> V_317 ) ;
V_8 -> V_317 = NULL ;
V_8 -> V_324 = 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_115 * V_116 ,
bool V_325 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_4 = NULL ;
struct V_9 * V_10 = NULL ;
struct V_37 * V_223 = NULL ;
struct V_326 V_327 = {
. V_328 = F_16 ( 10 * 1000 * 1000 ) ,
} ;
struct V_119 V_329 = {
. V_64 = V_330 ,
. V_73 = V_265 ,
. V_6 [ 0 ] = & V_327 ,
. V_126 [ 0 ] = sizeof( V_327 ) ,
} ;
int V_53 ;
int V_126 V_331 ;
if ( ! V_116 ) {
F_34 ( ! V_325 ) ;
return - V_236 ;
}
F_4 ( & V_8 -> V_13 ) ;
V_4 = F_72 ( V_8 ) ;
if ( F_73 ( V_4 ) ) {
V_53 = 1 ;
goto V_332;
}
V_10 = F_3 ( V_4 ) ;
if ( V_10 -> V_253 == V_333 ) {
if ( ! V_116 -> V_314 && ! V_8 -> V_314 ) {
V_53 = 1 ;
goto V_332;
}
V_53 = F_67 (
V_8 , V_116 , V_116 -> V_314 ? : V_8 -> V_314 , V_4 ) ;
if ( V_53 )
goto V_34;
V_8 -> V_334 = true ;
} else {
struct V_275 V_276 = {} ;
V_223 = F_74 (
V_8 -> V_252 [ V_10 -> V_253 ] ,
F_75 ( & V_8 -> V_13 ) ) ;
if ( F_73 ( V_223 ) ) {
V_53 = - V_236 ;
goto V_332;
}
V_53 = F_61 ( V_8 , V_116 , & V_276 ,
V_4 , V_10 , V_223 ) ;
if ( V_53 )
goto V_332;
V_53 = F_64 ( V_8 , V_116 , & V_276 ,
V_4 , V_10 , V_223 ) ;
if ( V_53 )
goto V_34;
V_8 -> V_334 = false ;
}
V_53 = F_76 ( V_8 ) ;
if ( V_53 )
goto V_34;
V_53 = F_77 ( V_8 ) ;
if ( V_53 )
goto V_34;
#ifdef F_78
if ( V_8 -> V_335 )
V_327 . V_336 |=
F_16 ( V_337 ) ;
#endif
V_53 = F_27 ( V_8 , & V_329 ) ;
if ( V_53 )
goto V_34;
#ifdef F_78
V_126 = F_52 ( V_329 . V_267 ) ;
if ( V_126 >= sizeof( T_4 ) ) {
V_8 -> V_338 =
F_79 ( ( V_339 * ) V_329 . V_267 -> V_6 ) ;
}
#endif
F_54 ( & V_329 ) ;
F_80 ( V_273 , & V_8 -> V_234 ) ;
F_81 ( V_8 -> V_272 , V_325 ) ;
V_34:
if ( V_53 < 0 ) {
F_82 ( V_8 , V_340 ) ;
F_83 ( V_8 -> V_2 ) ;
F_70 ( V_8 ) ;
}
V_332:
F_7 ( & V_8 -> V_13 ) ;
return V_53 ;
}
static int F_84 ( struct V_7 * V_8 )
{
struct V_341 V_342 ;
static const T_3 V_343 [] = { V_330 } ;
int V_53 ;
F_85 ( & V_8 -> V_344 , & V_342 ,
V_343 , F_86 ( V_343 ) ,
NULL , NULL ) ;
V_53 = F_87 ( V_8 -> V_2 -> V_345 ) ;
if ( V_53 )
goto V_346;
V_53 = F_88 ( & V_8 -> V_344 , & V_342 , V_347 ) ;
F_89 ( V_53 ) ;
return V_53 ;
V_346:
F_90 ( & V_8 -> V_344 , & V_342 ) ;
return V_53 ;
}
int F_91 ( struct V_1 * V_2 , struct V_115 * V_116 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_92 ( V_8 -> V_272 ) ;
if ( V_116 -> V_348 ) {
if ( V_8 -> V_272 -> V_349 == V_350 ) {
int V_53 = F_84 ( V_8 ) ;
if ( V_53 )
return V_53 ;
}
F_4 ( & V_8 -> V_351 ) ;
F_93 ( V_352 , & V_8 -> V_353 ) ;
F_7 ( & V_8 -> V_351 ) ;
return 0 ;
}
return F_71 ( V_2 , V_116 , false ) ;
}
static void F_94 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
struct V_354 * V_234 )
{
struct V_355 * V_153 = NULL ;
struct V_356 V_357 = {
. V_358 = - 1 ,
} ;
struct V_356 * V_359 = & V_357 ;
T_4 V_360 = V_234 -> V_361 ;
if ( V_360 == V_362 ) {
V_359 = NULL ;
goto V_363;
}
if ( V_360 & V_364 )
V_357 . V_287 = true ;
if ( V_360 & V_365 )
V_357 . V_358 =
V_234 -> V_366 ;
if ( V_360 & ( V_367 |
V_368 ) )
V_357 . V_283 = true ;
if ( V_360 & V_369 )
V_357 . V_289 = true ;
if ( V_360 & V_370 )
V_357 . V_296 = true ;
if ( V_360 & V_371 )
V_357 . V_291 = true ;
if ( V_360 & V_372 )
V_357 . V_293 = true ;
if ( V_360 & V_373 )
V_357 . V_374 = true ;
if ( V_360 & V_375 )
V_357 . V_376 = true ;
if ( V_360 & V_377 )
V_357 . V_378 = true ;
if ( V_234 -> V_379 ) {
int V_380 = V_234 -> V_379 ;
int V_381 = V_234 -> V_382 ;
const T_3 * V_383 = V_234 -> V_384 ;
struct V_385 * V_386 = ( void * ) V_383 ;
int V_387 = V_381 - V_380 ;
if ( F_89 ( V_387 < 0 ) )
V_387 = 0 ;
if ( F_95 ( V_386 -> V_388 ) ) {
int V_389 = F_96 ( V_386 -> V_388 ) ;
int V_390 = 0 , V_391 = 4 ;
V_153 = F_97 ( V_380 , V_128 ) ;
if ( ! V_153 )
goto V_363;
memcpy ( F_98 ( V_153 , V_389 ) , V_383 , V_389 ) ;
V_383 += V_389 ;
V_380 -= V_389 ;
if ( F_99 ( V_386 -> V_388 ) ) {
if ( F_100 ( V_386 -> V_392 ) ) {
V_390 = V_8 -> V_82 ;
V_391 += V_8 -> V_83 ;
} else {
V_390 = V_8 -> V_78 ;
V_391 += V_8 -> V_80 ;
}
}
if ( V_387 >= V_391 ) {
V_391 = 0 ;
V_387 -= V_391 ;
} else {
V_391 -= V_387 ;
V_387 = 0 ;
}
V_380 -= V_390 + V_391 ;
V_383 += V_390 ;
memcpy ( F_98 ( V_153 , V_380 ) , V_383 , V_380 ) ;
if ( F_101 ( V_153 , V_4 -> V_29 , V_4 -> type ) )
goto V_363;
V_357 . V_393 = V_153 -> V_6 ;
V_357 . V_394 = V_153 -> V_126 ;
V_357 . V_395 = V_153 -> V_126 - V_387 ;
V_357 . V_396 = false ;
} else {
int V_397 = 4 ;
if ( V_387 >= 4 ) {
V_387 -= 4 ;
V_397 = 0 ;
} else {
V_397 -= V_387 ;
V_387 = 0 ;
}
V_380 -= V_397 ;
V_357 . V_393 = V_234 -> V_384 ;
V_357 . V_394 = V_380 ;
V_357 . V_395 = V_381 - V_387 ;
V_357 . V_396 = true ;
}
}
V_363:
F_102 ( V_4 , V_359 , V_128 ) ;
F_103 ( V_153 ) ;
}
static void F_104 ( struct V_43 * V_398 ,
struct V_50 * V_51 )
{
V_113 V_110 ;
V_110 = F_105 ( V_398 -> V_110 ) ;
V_51 -> V_111 . V_110 [ 0 ] = V_110 >> 40 ;
V_51 -> V_111 . V_110 [ 1 ] = V_110 >> 32 ;
V_51 -> V_111 . V_110 [ 2 ] = V_110 >> 24 ;
V_51 -> V_111 . V_110 [ 3 ] = V_110 >> 16 ;
V_51 -> V_111 . V_110 [ 4 ] = V_110 >> 8 ;
V_51 -> V_111 . V_110 [ 5 ] = V_110 ;
}
static void F_106 ( struct V_45 * V_398 ,
struct V_50 * V_51 )
{
V_51 -> V_89 . V_94 = F_107 ( V_398 -> V_94 ) ;
V_51 -> V_89 . V_93 = F_108 ( V_398 -> V_93 ) ;
}
static void F_109 ( struct V_43 * V_399 ,
struct V_39 * V_40 )
{
int V_400 ;
F_110 ( V_103 != V_401 ) ;
for ( V_400 = 0 ; V_400 < V_103 ; V_400 ++ ) {
struct V_50 V_51 = {} ;
F_104 ( & V_399 [ V_400 ] , & V_51 ) ;
F_111 ( V_40 , V_400 , & V_51 ) ;
}
}
static void F_112 ( struct V_45 * V_399 ,
struct V_39 * V_40 )
{
int V_400 ;
F_110 ( V_103 != V_401 ) ;
for ( V_400 = 0 ; V_400 < V_103 ; V_400 ++ ) {
struct V_50 V_51 = {} ;
F_106 ( & V_399 [ V_400 ] , & V_51 ) ;
F_111 ( V_40 , V_400 , & V_51 ) ;
}
}
static void F_113 ( struct V_39 * V_40 ,
struct V_402 * V_234 )
{
union V_403 * V_404 = & V_234 -> V_405 . V_404 . V_88 ;
switch ( V_40 -> V_54 ) {
case V_109 :
F_109 ( V_404 -> V_112 . V_100 , V_40 ) ;
break;
case V_86 :
F_112 ( V_404 -> V_89 . V_100 , V_40 ) ;
break;
default:
F_34 ( 1 ) ;
}
}
static void F_114 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 ,
struct V_39 * V_40 ,
void * V_41 )
{
struct V_406 * V_6 = V_41 ;
if ( V_6 -> V_407 )
return;
switch ( V_40 -> V_54 ) {
case V_55 :
case V_56 :
return;
case V_109 :
case V_86 :
break;
default:
V_6 -> V_407 = true ;
return;
}
V_6 -> V_66 ++ ;
if ( V_38 ) {
struct V_50 V_51 = {} ;
union V_403 * V_398 = & V_6 -> V_234 -> V_405 . V_404 . V_88 ;
if ( V_6 -> V_408 )
return;
switch ( V_40 -> V_54 ) {
case V_109 :
F_104 ( & V_398 -> V_112 . V_91 , & V_51 ) ;
F_109 ( V_398 -> V_112 . V_90 , V_40 ) ;
break;
case V_86 :
F_106 ( & V_398 -> V_89 . V_91 , & V_51 ) ;
F_112 ( V_398 -> V_89 . V_90 , V_40 ) ;
break;
}
F_115 ( V_40 , & V_51 ) ;
return;
}
if ( V_6 -> V_408 ) {
V_6 -> V_409 = V_40 ;
V_6 -> V_54 = V_40 -> V_54 ;
return;
}
if ( V_6 -> V_234 -> V_410 )
F_116 ( V_40 ) ;
else if ( V_6 -> V_409 == V_40 )
F_113 ( V_40 , V_6 -> V_234 ) ;
}
static bool F_117 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
struct V_402 * V_234 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_406 V_411 = {
. V_234 = V_234 ,
} ;
T_4 V_412 =
V_367 |
V_368 ;
if ( ! V_234 || ! V_4 -> V_104 . V_105 )
return false ;
if ( F_107 ( V_234 -> V_361 ) & V_412 )
return false ;
V_411 . V_408 = true ;
F_65 ( V_8 -> V_2 , V_4 ,
F_114 , & V_411 ) ;
if ( V_411 . V_407 )
return false ;
if ( ! V_411 . V_66 )
goto V_34;
if ( ! V_411 . V_409 )
return false ;
V_411 . V_408 = false ;
F_65 ( V_8 -> V_2 , V_4 ,
F_114 , & V_411 ) ;
if ( V_234 -> V_410 ) {
struct V_39 * V_40 ;
struct {
struct V_39 V_413 ;
T_3 V_40 [ 32 ] ;
} V_413 = {
. V_413 . V_54 = V_411 . V_54 ,
. V_413 . V_70 = V_234 -> V_405 . V_69 ,
} ;
switch ( V_411 . V_54 ) {
case V_109 :
V_413 . V_413 . V_72 = V_414 ;
memcpy ( V_413 . V_413 . V_40 , V_234 -> V_405 . V_415 ,
V_414 ) ;
break;
case V_86 :
V_413 . V_413 . V_72 = V_416 ;
memcpy ( V_413 . V_413 . V_40 , V_234 -> V_405 . V_415 , 16 ) ;
memcpy ( V_413 . V_413 . V_40 +
V_106 ,
V_234 -> V_405 . V_417 , 8 ) ;
break;
}
V_40 = F_118 ( V_4 , & V_413 . V_413 ) ;
if ( F_119 ( V_40 ) )
return false ;
F_113 ( V_40 , V_234 ) ;
}
if ( V_234 -> V_410 ) {
V_20 V_19 =
F_120 ( F_105 ( V_234 -> V_19 ) ) ;
F_121 ( V_4 , V_4 -> V_104 . V_105 ,
( void * ) & V_19 , V_128 ) ;
}
V_34:
V_10 -> V_271 = true ;
V_10 -> V_270 = F_108 ( V_234 -> V_418 ) + 0x10 ;
return true ;
}
static struct V_402 *
F_122 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
T_4 V_419 = V_8 -> V_420 ;
struct V_421 {
T_4 V_21 ;
T_4 V_422 ;
} V_423 ;
struct V_119 V_120 = {
. V_64 = V_424 ,
. V_73 = V_265 ,
} ;
struct V_402 * V_234 , * V_425 ;
int V_53 , V_126 , V_426 ;
F_123 ( V_8 -> V_272 , V_419 ,
& V_423 , sizeof( V_423 ) ) ;
if ( V_423 . V_21 ) {
F_124 ( V_8 , L_6 ,
V_423 . V_21 , V_423 . V_422 ) ;
if ( V_423 . V_422 == V_427 ) {
struct V_356 V_357 = {
. V_296 = true ,
} ;
F_102 ( V_4 , & V_357 ,
V_128 ) ;
}
return F_125 ( - V_251 ) ;
}
V_53 = F_18 ( V_8 , V_428 , 0 , 0 , NULL ) ;
if ( V_53 )
F_45 ( V_8 , L_7 , V_53 ) ;
V_53 = F_27 ( V_8 , & V_120 ) ;
if ( V_53 ) {
F_45 ( V_8 , L_8 , V_53 ) ;
return F_125 ( V_53 ) ;
}
if ( ! V_120 . V_267 ) {
V_425 = F_125 ( - V_429 ) ;
goto V_430;
}
V_426 = sizeof( * V_425 ) ;
V_126 = F_52 ( V_120 . V_267 ) ;
if ( V_126 < V_426 ) {
F_45 ( V_8 , L_9 ) ;
V_425 = F_125 ( - V_251 ) ;
goto V_430;
}
V_234 = ( void * ) V_120 . V_267 -> V_6 ;
if ( V_126 != ( V_426 +
F_126 ( F_107 ( V_234 -> V_379 ) , 4 ) ) ) {
F_45 ( V_8 , L_9 ) ;
V_425 = F_125 ( - V_251 ) ;
goto V_430;
}
V_425 = F_69 ( V_234 , V_126 , V_128 ) ;
V_430:
F_54 ( & V_120 ) ;
return V_425 ;
}
static bool F_127 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
struct V_354 V_234 ;
struct V_402 * V_425 ;
int V_35 ;
bool V_431 ;
struct V_37 * V_223 ;
struct V_277 * V_278 ;
V_425 = F_122 ( V_8 , V_4 ) ;
if ( F_73 ( V_425 ) )
goto V_84;
V_234 . V_366 = F_108 ( V_425 -> V_366 ) ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ )
V_234 . V_432 [ V_35 ] =
F_108 ( V_425 -> V_432 [ V_35 ] ) ;
V_234 . V_361 = F_107 ( V_425 -> V_361 ) ;
V_234 . V_382 =
F_107 ( V_425 -> V_382 ) ;
V_234 . V_379 =
F_107 ( V_425 -> V_379 ) ;
V_234 . V_384 = V_425 -> V_384 ;
V_223 = F_74 (
V_8 -> V_252 [ 0 ] ,
F_75 ( & V_8 -> V_13 ) ) ;
if ( F_73 ( V_223 ) )
goto V_433;
V_278 = F_62 ( V_223 ) ;
for ( V_35 = 0 ; V_35 < V_434 ; V_35 ++ ) {
T_1 V_51 = V_234 . V_432 [ V_35 ] ;
V_51 += 0x10 ;
V_278 -> V_435 [ V_35 ] . V_436 = V_51 ;
}
F_7 ( & V_8 -> V_13 ) ;
F_94 ( V_8 , V_4 , & V_234 ) ;
V_431 = F_117 ( V_8 , V_4 , V_425 ) ;
F_28 ( V_425 ) ;
return V_431 ;
V_433:
F_28 ( V_425 ) ;
V_84:
F_7 ( & V_8 -> V_13 ) ;
return false ;
}
static int
F_128 ( struct V_7 * V_8 ,
struct V_437 * V_438 )
{
struct V_439 * V_440 ;
struct V_119 V_120 = {
. V_64 = V_441 ,
. V_73 = V_265 ,
} ;
int V_53 , V_126 ;
V_53 = F_27 ( V_8 , & V_120 ) ;
if ( V_53 ) {
F_45 ( V_8 , L_10 , V_53 ) ;
return V_53 ;
}
if ( ! V_120 . V_267 ) {
V_53 = - V_429 ;
goto V_430;
}
V_126 = F_52 ( V_120 . V_267 ) ;
if ( V_126 < sizeof( * V_440 ) ) {
F_45 ( V_8 , L_11 ) ;
V_53 = - V_251 ;
goto V_430;
}
V_440 = ( void * ) V_120 . V_267 -> V_6 ;
V_438 -> V_442 = F_107 ( V_440 -> V_442 ) ;
memcpy ( V_438 -> V_443 , V_440 -> V_443 , sizeof( V_438 -> V_443 ) ) ;
#ifdef F_78
V_8 -> V_444 = F_107 ( V_440 -> V_445 ) ;
#endif
V_430:
F_54 ( & V_120 ) ;
return V_53 ;
}
static void F_129 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
struct V_446 * V_334 = NULL ;
struct V_356 V_357 = {
. V_358 = - 1 ,
} ;
struct V_356 * V_359 = & V_357 ;
struct V_437 V_440 ;
struct V_402 * V_425 ;
unsigned long V_442 ;
T_4 V_360 = 0 ;
int V_35 , V_447 , V_448 , V_53 ;
V_425 = F_122 ( V_8 , V_4 ) ;
if ( ! F_73 ( V_425 ) ) {
V_360 = F_107 ( V_425 -> V_361 ) ;
F_28 ( V_425 ) ;
}
if ( V_360 & V_370 )
V_357 . V_296 = true ;
if ( V_360 != V_362 )
goto V_34;
V_53 = F_128 ( V_8 , & V_440 ) ;
if ( V_53 || ! V_440 . V_442 ) {
V_359 = NULL ;
goto V_34;
}
V_442 = V_440 . V_442 ;
if ( V_8 -> V_321 ) {
V_448 = F_130 ( V_442 ) ;
} else {
F_45 ( V_8 , L_12 ) ;
V_448 = 0 ;
}
V_334 = F_37 ( sizeof( * V_334 ) +
( V_448 * sizeof( V_334 -> V_443 [ 0 ] ) ) ,
V_128 ) ;
if ( ! V_334 || ! V_448 )
goto V_449;
F_131 (i, &matched_profiles, mvm->n_nd_match_sets) {
struct V_450 * V_451 ;
struct V_452 * V_453 ;
int V_323 = 0 ;
V_451 = & V_440 . V_443 [ V_35 ] ;
for ( V_447 = 0 ; V_447 < V_454 ; V_447 ++ )
V_323 += F_132 ( V_451 -> V_455 [ V_447 ] ) ;
V_453 = F_37 ( sizeof( * V_453 ) +
( V_323 * sizeof( * V_453 -> V_322 ) ) ,
V_128 ) ;
if ( ! V_453 )
goto V_449;
V_334 -> V_443 [ V_334 -> V_448 ++ ] = V_453 ;
V_453 -> V_456 . V_457 = V_8 -> V_316 [ V_35 ] . V_456 . V_457 ;
memcpy ( V_453 -> V_456 . V_456 , V_8 -> V_316 [ V_35 ] . V_456 . V_456 ,
V_453 -> V_456 . V_457 ) ;
if ( V_8 -> V_324 < V_323 )
continue;
for ( V_447 = 0 ; V_447 < V_454 * 8 ; V_447 ++ )
if ( V_451 -> V_455 [ V_447 / 8 ] & ( F_133 ( V_447 % 8 ) ) )
V_453 -> V_322 [ V_453 -> V_323 ++ ] =
V_8 -> V_317 [ V_447 ] -> V_458 ;
}
V_449:
V_357 . V_334 = V_334 ;
V_34:
F_70 ( V_8 ) ;
F_7 ( & V_8 -> V_13 ) ;
F_102 ( V_4 , V_359 , V_128 ) ;
if ( V_334 ) {
for ( V_35 = 0 ; V_35 < V_334 -> V_448 ; V_35 ++ )
F_28 ( V_334 -> V_443 [ V_35 ] ) ;
F_28 ( V_334 ) ;
}
}
static void F_134 ( struct V_7 * V_8 )
{
#ifdef F_78
const struct V_459 * V_460 = & V_8 -> V_461 -> V_460 [ V_462 ] ;
T_4 V_126 = V_460 -> V_463 [ V_464 ] . V_126 ;
T_4 V_465 = V_460 -> V_463 [ V_464 ] . V_207 ;
if ( ! V_8 -> V_466 )
return;
if ( ! V_8 -> V_467 ) {
V_8 -> V_467 = F_37 ( V_126 , V_128 ) ;
if ( ! V_8 -> V_467 )
return;
}
F_123 ( V_8 -> V_272 , V_465 , V_8 -> V_467 , V_126 ) ;
#endif
}
static void F_135 ( void * V_6 , T_3 * V_468 ,
struct V_3 * V_4 )
{
if ( V_6 == V_4 )
return;
if ( V_4 -> type == V_469 )
F_136 ( V_4 ) ;
}
static int F_137 ( struct V_7 * V_8 , bool V_325 )
{
struct V_3 * V_4 = NULL ;
int V_53 ;
enum V_470 V_471 ;
bool V_431 = false ;
F_4 ( & V_8 -> V_13 ) ;
V_4 = F_72 ( V_8 ) ;
if ( F_73 ( V_4 ) )
goto V_124;
V_53 = F_138 ( V_8 -> V_272 , & V_471 , V_325 ) ;
if ( V_53 )
goto V_124;
if ( V_471 != V_472 ) {
F_124 ( V_8 , L_13 ) ;
goto V_124;
}
F_134 ( V_8 ) ;
F_139 ( V_8 ) ;
if ( V_8 -> V_334 ) {
F_129 ( V_8 , V_4 ) ;
goto V_34;
} else {
V_431 = F_127 ( V_8 , V_4 ) ;
#ifdef F_78
if ( V_431 )
V_8 -> V_473 = V_4 ;
#endif
goto V_474;
}
V_124:
F_70 ( V_8 ) ;
F_7 ( & V_8 -> V_13 ) ;
V_474:
if ( ! V_325 )
F_140 ( V_8 -> V_2 ,
V_475 ,
F_135 , V_431 ? V_4 : NULL ) ;
V_34:
F_59 ( V_273 , & V_8 -> V_234 ) ;
F_59 ( V_476 , & V_8 -> V_234 ) ;
F_82 ( V_8 , V_340 ) ;
return 1 ;
}
int F_141 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_142 ( V_8 -> V_272 ) ;
if ( V_8 -> V_2 -> V_477 -> V_478 -> V_348 ) {
if ( V_8 -> V_272 -> V_349 == V_350 ) {
int V_53 = F_143 ( V_2 -> V_345 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
return F_137 ( V_8 , false ) ;
}
void F_144 ( struct V_1 * V_2 , bool V_479 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_145 ( V_8 -> V_272 -> V_480 , V_479 ) ;
}
static int F_146 ( struct V_481 * V_481 , struct V_482 * V_482 )
{
struct V_7 * V_8 = V_481 -> V_483 ;
int V_124 ;
if ( V_8 -> V_484 )
return - V_318 ;
V_482 -> V_485 = V_481 -> V_483 ;
F_147 ( V_8 -> V_2 ) ;
F_148 () ;
F_149 () ;
V_124 = F_71 ( V_8 -> V_2 , V_8 -> V_2 -> V_477 -> V_478 , true ) ;
F_150 () ;
if ( V_124 > 0 )
V_124 = - V_236 ;
if ( V_124 ) {
F_151 ( V_8 -> V_2 ) ;
return V_124 ;
}
V_8 -> V_484 = true ;
V_8 -> V_473 = NULL ;
return 0 ;
}
static T_7 F_152 ( struct V_482 * V_482 , char T_8 * V_486 ,
T_9 V_487 , T_10 * V_488 )
{
struct V_7 * V_8 = V_482 -> V_485 ;
T_4 V_489 ;
while ( true ) {
if ( V_8 -> V_338 ) {
V_489 = F_153 ( V_8 -> V_272 ,
V_8 -> V_338 ) ;
if ( V_489 )
break;
}
if ( F_154 ( 100 ) )
break;
}
return 0 ;
}
static void F_155 ( void * V_41 , T_3 * V_468 ,
struct V_3 * V_4 )
{
if ( V_41 == V_4 )
return;
if ( V_4 -> type == V_469 )
F_156 ( V_4 ) ;
}
static int F_157 ( struct V_481 * V_481 , struct V_482 * V_482 )
{
struct V_7 * V_8 = V_481 -> V_483 ;
int V_490 = 10 ;
V_8 -> V_484 = false ;
F_149 () ;
F_137 ( V_8 , true ) ;
F_150 () ;
F_158 ( & V_8 -> V_344 ) ;
F_83 ( V_8 -> V_2 ) ;
while ( F_159 ( V_273 , & V_8 -> V_234 ) &&
V_490 > 0 ) {
V_490 -- ;
F_160 ( 1000 ) ;
}
if ( V_490 == 0 )
F_45 ( V_8 , L_14 ) ;
F_161 (
V_8 -> V_2 , V_475 ,
F_155 , V_8 -> V_473 ) ;
F_151 ( V_8 -> V_2 ) ;
return 0 ;
}
