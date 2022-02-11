static inline bool F_1 ( void ) { return false ; }
int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_6 == NULL )
goto V_7;
if ( F_3 ( V_2 ) ) {
F_4 ( V_2 -> V_2 ) ;
F_5 ( V_2 -> V_2 ) ;
}
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
V_7:
F_9 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_3 * V_4 ;
int V_9 , V_10 ;
V_4 = F_11 ( sizeof( struct V_3 ) , V_11 ) ;
if ( V_4 == NULL ) {
return - V_12 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( ( V_13 != 0 ) &&
F_1 () &&
( F_12 () ||
F_13 () ) &&
( ( V_8 & V_14 ) == 0 ) )
V_8 |= V_15 ;
V_9 = F_14 ( V_4 , V_2 , V_2 -> V_16 , V_8 ) ;
if ( V_9 ) {
F_15 ( & V_2 -> V_16 -> V_2 , L_1 ) ;
goto V_17;
}
if ( ! V_9 ) {
V_10 = F_16 ( V_4 ) ;
if ( V_10 )
F_17 ( & V_2 -> V_16 -> V_2 ,
L_2 ) ;
}
F_18 ( V_4 ) ;
F_19 ( V_4 ) ;
F_20 ( V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_21 ( V_2 -> V_2 ) ;
F_22 ( V_2 -> V_2 , 5000 ) ;
F_23 ( V_2 -> V_2 ) ;
F_24 ( V_2 -> V_2 ) ;
F_25 ( V_2 -> V_2 ) ;
F_26 ( V_2 -> V_2 ) ;
}
V_17:
if ( V_9 ) {
if ( V_4 -> V_6 && F_3 ( V_2 ) )
F_27 ( V_2 -> V_2 ) ;
F_2 ( V_2 ) ;
}
return V_9 ;
}
static int F_28 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_3 * V_4 )
{
switch ( V_21 -> V_22 ) {
case V_23 :
V_19 -> V_24 = V_4 -> V_25 . V_26 ;
V_19 -> V_27 = V_4 -> V_25 . V_28 ;
break;
case V_29 :
V_19 -> V_24 = V_4 -> V_30 . V_26 ;
V_19 -> V_27 = 0 ;
break;
case V_31 :
V_19 -> V_24 = V_4 -> V_32 . V_26 ;
V_19 -> V_27 = 0 ;
break;
case V_33 :
V_19 -> V_24 = V_4 -> V_34 . V_35 ;
V_19 -> V_27 = V_4 -> V_34 . V_36 ;
break;
case V_37 :
V_19 -> V_24 = V_4 -> V_34 . V_38 ;
V_19 -> V_27 = V_4 -> V_34 . V_39 ;
break;
case V_40 :
V_19 -> V_24 = V_4 -> V_34 . V_41 ;
V_19 -> V_27 = V_4 -> V_34 . V_42 ;
break;
case V_43 :
V_19 -> V_24 = V_4 -> V_34 . V_44 ;
V_19 -> V_27 = V_4 -> V_34 . V_45 ;
break;
case V_46 :
if ( V_21 -> V_47 == 0 ) {
V_19 -> V_24 = V_4 -> V_34 . V_48 ;
V_19 -> V_27 = V_4 -> V_34 . V_49 ;
} else if ( V_21 -> V_47 == 1 ) {
V_19 -> V_24 = V_4 -> V_34 . V_50 ;
V_19 -> V_27 = V_4 -> V_34 . V_51 ;
} else
return - V_52 ;
break;
case V_53 :
V_19 -> V_24 = V_4 -> V_54 . V_26 ;
V_19 -> V_27 = 0 ;
break;
case V_55 :
if ( V_21 -> V_47 >= V_4 -> V_56 . V_57 )
return - V_52 ;
V_19 -> V_24 = V_4 -> V_56 . V_58 [ V_21 -> V_47 ] . V_26 ;
V_19 -> V_27 = V_4 -> V_56 . V_58 [ V_21 -> V_47 ] . V_59 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_60 , struct V_61 * V_62 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_63 * V_64 = V_60 ;
struct V_65 * V_66 = & V_4 -> V_67 ;
void T_1 * V_17 = ( void T_1 * ) ( long ) V_64 -> V_68 ;
T_2 V_69 = V_64 -> V_70 ;
struct V_71 * V_72 ;
T_2 V_73 = 0 ;
T_3 V_74 = 0 ;
int V_75 , V_76 ;
if ( ! V_64 -> V_70 || ! V_64 -> V_68 )
return - V_52 ;
switch ( V_64 -> V_77 ) {
case V_78 :
V_73 = V_4 -> V_79 ;
return F_30 ( V_17 , & V_73 , F_31 ( V_69 , 4u ) ) ? - V_80 : 0 ;
case V_81 :
for ( V_75 = 0 , V_76 = 0 ; V_75 < V_4 -> V_67 . V_82 ; V_75 ++ ) {
V_72 = (struct V_71 * ) V_66 -> V_83 [ V_75 ] ;
if ( V_72 && V_72 -> V_84 . V_85 == V_64 -> V_86 . V_85 ) {
struct V_87 * V_87 = F_32 ( V_72 ) ;
V_73 = V_87 -> V_88 ;
V_76 = 1 ;
break;
}
}
if ( ! V_76 ) {
F_33 ( L_3 , V_64 -> V_86 . V_85 ) ;
return - V_52 ;
}
return F_30 ( V_17 , & V_73 , F_31 ( V_69 , 4u ) ) ? - V_80 : 0 ;
case V_89 : {
struct V_90 V_91 = {} ;
enum V_92 type ;
T_2 V_93 = 0 ;
T_2 V_94 = 0 ;
T_2 V_95 = 0 ;
if ( V_64 -> V_96 . V_97 >= V_98 )
return - V_52 ;
switch ( V_64 -> V_96 . type ) {
case V_99 :
type = V_100 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_34 . V_101 ; V_75 ++ )
V_93 |= ( ( V_4 -> V_34 . V_102 [ V_75 ] . V_103 ? 1 : 0 ) << V_75 ) ;
V_94 = V_104 ;
V_95 = 8 ;
break;
case V_105 :
type = V_100 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_34 . V_106 ; V_75 ++ )
V_93 |= ( ( V_4 -> V_34 . V_107 [ V_75 ] . V_103 ? 1 : 0 ) << V_75 ) ;
V_94 = V_104 ;
V_95 = 8 ;
break;
case V_108 :
type = V_109 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_56 . V_57 ; V_75 ++ )
V_93 |= ( ( V_4 -> V_56 . V_58 [ V_75 ] . V_110 . V_103 ? 1 : 0 ) << V_75 ) ;
V_94 = V_104 ;
V_95 = 1 ;
break;
case V_111 :
type = V_112 ;
V_93 = V_4 -> V_30 . V_110 . V_103 ? 1 : 0 ;
V_94 = V_104 ;
V_95 = 16 ;
break;
case V_113 :
type = V_114 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_25 . V_115 ; V_75 ++ )
V_93 |= ( ( V_4 -> V_25 . V_110 [ V_75 ] . V_103 ? 1 : 0 ) << V_75 ) ;
V_94 = V_104 ;
V_95 = 1 ;
break;
default:
return - V_52 ;
}
for ( V_75 = 0 ; V_75 < V_4 -> V_116 ; V_75 ++ ) {
if ( V_4 -> V_117 [ V_75 ] . type == type &&
V_4 -> V_118 [ V_75 ] . V_119 ) {
V_91 . V_120 = V_4 -> V_117 [ V_75 ] . V_121 ;
V_91 . V_122 = V_4 -> V_117 [ V_75 ] . V_123 ;
V_91 . V_124 = 0 ;
V_91 . V_125 = V_93 ;
V_91 . V_94 = V_94 ;
V_91 . V_95 = V_95 ;
break;
}
}
return F_30 ( V_17 , & V_91 ,
F_31 ( ( V_126 ) V_69 , sizeof( V_91 ) ) ) ? - V_80 : 0 ;
}
case V_127 : {
enum V_92 type ;
T_2 V_128 = 0 ;
switch ( V_64 -> V_96 . type ) {
case V_99 :
type = V_100 ;
break;
case V_105 :
type = V_100 ;
break;
case V_108 :
type = V_109 ;
break;
case V_111 :
type = V_112 ;
break;
case V_113 :
type = V_114 ;
break;
default:
return - V_52 ;
}
for ( V_75 = 0 ; V_75 < V_4 -> V_116 ; V_75 ++ )
if ( V_4 -> V_117 [ V_75 ] . type == type &&
V_4 -> V_118 [ V_75 ] . V_119 &&
V_128 < V_98 )
V_128 ++ ;
return F_30 ( V_17 , & V_128 , F_31 ( V_69 , 4u ) ) ? - V_80 : 0 ;
}
case V_129 :
V_74 = F_34 ( V_4 ) ;
return F_30 ( V_17 , & V_74 , F_31 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_130 : {
struct V_18 V_19 ;
int V_131 ;
if ( V_64 -> V_21 . V_97 != 0 )
return - V_52 ;
V_131 = F_28 ( & V_19 , & V_64 -> V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
return F_30 ( V_17 , & V_19 ,
F_31 ( ( V_126 ) V_69 , sizeof( V_19 ) ) ) ? - V_80 : 0 ;
}
case V_132 :
V_74 = F_35 ( & V_4 -> V_133 ) ;
return F_30 ( V_17 , & V_74 , F_31 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_134 :
V_74 = F_35 ( & V_4 -> V_135 ) ;
return F_30 ( V_17 , & V_74 , F_31 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_136 :
V_74 = F_35 ( & V_4 -> V_137 ) ;
return F_30 ( V_17 , & V_74 , F_31 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_138 :
V_74 = F_35 ( & V_4 -> V_139 ) ;
return F_30 ( V_17 , & V_74 , F_31 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_140 :
V_74 = F_35 ( & V_4 -> V_141 ) ;
return F_30 ( V_17 , & V_74 , F_31 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_142 : {
struct V_143 V_144 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_145 = V_4 -> V_146 . V_147 . V_148 >> V_149 ;
V_144 . V_150 = V_4 -> V_146 . V_147 . V_151 >> V_149 ;
V_144 . V_152 = V_4 -> V_146 . V_147 . V_153 >> V_149 ;
V_144 . V_154 = V_4 -> V_146 . V_155 . V_148 >> V_156 ;
V_144 . V_157 = V_4 -> V_146 . V_155 . V_151 >> V_156 ;
V_144 . V_158 = V_4 -> V_146 . V_159 . V_148 >> V_160 ;
V_144 . V_161 = V_4 -> V_146 . V_159 . V_151 >> V_160 ;
return F_30 ( V_17 , & V_144 ,
F_31 ( ( V_126 ) V_69 , sizeof( V_144 ) ) ) ? - V_80 : 0 ;
}
case V_162 : {
struct V_163 V_164 ;
V_164 . V_165 = V_4 -> V_32 . V_166 ;
V_164 . V_165 -= V_4 -> V_167 ;
V_164 . V_168 = V_4 -> V_32 . V_169 ;
V_164 . V_168 -= ( V_4 -> V_167 - V_4 -> V_170 ) ;
V_164 . V_171 = V_4 -> V_32 . V_171 ;
V_164 . V_171 -= V_4 -> V_172 ;
return F_30 ( V_17 , & V_164 ,
F_31 ( ( V_126 ) V_69 , sizeof( V_164 ) ) ) ? - V_80 : 0 ;
}
case V_173 : {
unsigned V_174 , V_175 ;
T_2 * V_176 ;
unsigned V_177 = ( V_64 -> V_178 . V_58 >>
V_179 ) &
V_180 ;
unsigned V_181 = ( V_64 -> V_178 . V_58 >>
V_182 ) &
V_183 ;
if ( V_177 == V_180 )
V_177 = 0xffffffff ;
if ( V_181 == V_183 )
V_181 = 0xffffffff ;
V_176 = F_36 ( V_64 -> V_178 . V_128 , sizeof( * V_176 ) , V_11 ) ;
if ( ! V_176 )
return - V_12 ;
V_175 = V_64 -> V_178 . V_128 * sizeof( * V_176 ) ;
for ( V_75 = 0 ; V_75 < V_64 -> V_178 . V_128 ; V_75 ++ )
if ( F_37 ( V_4 , V_177 , V_181 ,
V_64 -> V_178 . V_184 + V_75 ,
& V_176 [ V_75 ] ) ) {
F_33 ( L_4 ,
V_64 -> V_178 . V_184 + V_75 ) ;
F_9 ( V_176 ) ;
return - V_80 ;
}
V_174 = F_30 ( V_17 , V_176 , F_31 ( V_69 , V_175 ) ) ;
F_9 ( V_176 ) ;
return V_174 ? - V_80 : 0 ;
}
case V_185 : {
struct V_186 V_187 = {} ;
V_187 . V_188 = V_2 -> V_16 -> V_189 ;
V_187 . V_190 = V_4 -> V_191 ;
V_187 . V_192 = V_4 -> V_193 ;
V_187 . V_194 = V_2 -> V_16 -> V_195 ;
V_187 . V_196 = V_4 -> V_196 ;
V_187 . V_197 = V_4 -> V_34 . V_198 . V_199 ;
V_187 . V_200 = V_4 -> V_34 . V_198 . V_201 ;
V_187 . V_202 = F_38 ( V_4 ) * 10 ;
if ( V_4 -> V_54 . V_203 ) {
V_187 . V_204 = F_39 ( V_4 , false ) * 10 ;
V_187 . V_205 = F_40 ( V_4 , false ) * 10 ;
} else {
V_187 . V_204 = V_4 -> V_54 . V_206 * 10 ;
V_187 . V_205 = V_4 -> V_54 . V_207 * 10 ;
}
V_187 . V_208 = V_4 -> V_34 . V_198 . V_209 ;
V_187 . V_210 = V_4 -> V_34 . V_198 . V_211 *
V_4 -> V_34 . V_198 . V_199 ;
V_187 . V_212 = V_4 -> V_34 . V_198 . V_213 ;
V_187 . V_214 = 0 ;
V_187 . V_215 = 0 ;
if ( V_4 -> V_8 & V_14 )
V_187 . V_215 |= V_216 ;
V_187 . V_217 = V_218 ;
V_187 . V_219 = ( T_3 ) V_4 -> V_220 . V_221 * V_104 ;
V_187 . V_222 = F_41 ( ( int ) V_223 , V_104 ) ;
V_187 . V_224 = ( 1 << V_225 ) *
V_104 ;
V_187 . V_226 = V_104 ;
V_187 . V_227 = V_4 -> V_34 . V_228 . V_229 ;
V_187 . V_230 = V_4 -> V_34 . V_228 . V_231 ;
V_187 . V_232 = V_4 -> V_34 . V_232 ;
memcpy ( & V_187 . V_233 [ 0 ] , & V_4 -> V_34 . V_228 . V_234 [ 0 ] ,
sizeof( V_4 -> V_34 . V_228 . V_234 ) ) ;
V_187 . V_235 = V_4 -> V_32 . V_235 ;
V_187 . V_236 = V_4 -> V_32 . V_237 ;
V_187 . V_238 = V_4 -> V_25 . V_239 ;
return F_30 ( V_17 , & V_187 ,
F_31 ( ( V_126 ) V_69 , sizeof( V_187 ) ) ) ? - V_80 : 0 ;
}
default:
F_33 ( L_5 , V_64 -> V_77 ) ;
return - V_52 ;
}
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_43 ( V_4 ) ;
F_44 () ;
}
int F_45 ( struct V_1 * V_2 , struct V_61 * V_240 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_241 * V_242 ;
int V_9 ;
V_240 -> V_243 = NULL ;
V_9 = F_4 ( V_2 -> V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_242 = F_11 ( sizeof( * V_242 ) , V_11 ) ;
if ( F_46 ( ! V_242 ) ) {
V_9 = - V_12 ;
goto V_244;
}
V_9 = F_47 ( V_4 , & V_242 -> V_245 ) ;
if ( V_9 ) {
F_9 ( V_242 ) ;
goto V_244;
}
F_48 ( & V_242 -> V_246 ) ;
F_49 ( & V_242 -> V_247 ) ;
F_50 ( & V_242 -> V_248 ) ;
V_240 -> V_243 = V_242 ;
V_244:
F_25 ( V_2 -> V_2 ) ;
F_26 ( V_2 -> V_2 ) ;
return V_9 ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_61 * V_240 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_241 * V_242 = V_240 -> V_243 ;
struct V_249 * V_250 ;
int V_251 ;
if ( ! V_242 )
return;
F_52 ( & V_242 -> V_248 ) ;
F_53 ( V_4 , V_240 ) ;
F_54 ( V_4 , V_240 ) ;
F_55 ( V_4 , & V_242 -> V_245 ) ;
F_56 (&fpriv->bo_list_handles, list, handle)
F_57 ( V_250 ) ;
F_58 ( & V_242 -> V_247 ) ;
F_59 ( & V_242 -> V_246 ) ;
F_9 ( V_242 ) ;
V_240 -> V_243 = NULL ;
F_25 ( V_2 -> V_2 ) ;
F_26 ( V_2 -> V_2 ) ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_61 * V_240 )
{
F_4 ( V_2 -> V_2 ) ;
}
T_4 F_61 ( struct V_1 * V_2 , unsigned int V_252 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_253 , V_254 , V_255 ;
T_4 V_128 ;
if ( V_252 >= V_4 -> V_67 . V_82 ) {
F_62 ( L_6 , V_252 ) ;
return - V_52 ;
}
if ( V_4 -> V_67 . V_83 [ V_252 ] ) {
do {
V_128 = F_63 ( V_4 , V_252 ) ;
V_255 = F_64 (
V_2 , V_252 , V_256 ,
& V_253 , & V_254 , NULL , NULL ,
& V_4 -> V_67 . V_83 [ V_252 ] -> V_84 . V_257 ) ;
} while ( V_128 != F_63 ( V_4 , V_252 ) );
if ( ( ( V_255 & ( V_258 | V_259 ) ) !=
( V_258 | V_259 ) ) ) {
F_65 ( L_7 , V_255 ) ;
} else {
F_65 ( L_8 ,
V_252 , V_253 ) ;
if ( V_253 >= 0 )
V_128 ++ ;
}
} else {
V_128 = F_63 ( V_4 , V_252 ) ;
F_65 ( L_9 ) ;
}
return V_128 ;
}
int F_66 ( struct V_1 * V_2 , unsigned int V_252 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_260 = F_67 ( V_4 , V_252 ) ;
return F_68 ( V_4 , & V_4 -> V_261 , V_260 ) ;
}
void F_69 ( struct V_1 * V_2 , unsigned int V_252 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_260 = F_67 ( V_4 , V_252 ) ;
F_70 ( V_4 , & V_4 -> V_261 , V_260 ) ;
}
int F_71 ( struct V_1 * V_2 , unsigned int V_252 ,
int * V_262 ,
struct V_263 * V_264 ,
unsigned V_8 )
{
struct V_71 * V_72 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_252 >= V_2 -> V_265 ) {
F_62 ( L_6 , V_252 ) ;
return - V_52 ;
}
V_72 = & V_4 -> V_67 . V_83 [ V_252 ] -> V_84 ;
if ( ! V_72 ) {
F_62 ( L_10 , V_252 ) ;
return - V_52 ;
}
return F_72 ( V_2 , V_252 , V_262 ,
V_264 , V_8 ,
& V_72 -> V_257 ) ;
}
static int F_73 ( struct V_266 * V_267 , void * V_60 )
{
struct V_268 * V_269 = (struct V_268 * ) V_267 -> V_270 ;
struct V_1 * V_2 = V_269 -> V_123 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
int V_131 , V_75 ;
V_21 . V_22 = V_23 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_11 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_29 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_12 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_31 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_13 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_33 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_14 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_37 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_15 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_40 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_16 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_43 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_17 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_46 ;
V_21 . V_47 = 0 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_18 ,
V_19 . V_27 , V_19 . V_24 ) ;
if ( V_4 -> V_271 == V_272 ||
( V_4 -> V_271 > V_273 && V_4 -> V_271 != V_274 ) ) {
V_21 . V_47 = 1 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_19 ,
V_19 . V_27 , V_19 . V_24 ) ;
}
V_21 . V_22 = V_53 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_20 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_55 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_56 . V_57 ; V_75 ++ ) {
V_21 . V_47 = V_75 ;
V_131 = F_28 ( & V_19 , & V_21 , V_4 ) ;
if ( V_131 )
return V_131 ;
F_74 ( V_267 , L_21 ,
V_75 , V_19 . V_27 , V_19 . V_24 ) ;
}
return 0 ;
}
int F_75 ( struct V_3 * V_4 )
{
#if F_76 ( V_275 )
return F_77 ( V_4 , V_276 ,
F_78 ( V_276 ) ) ;
#else
return 0 ;
#endif
}
