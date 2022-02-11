static inline bool F_1 ( void ) { return false ; }
int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_6 == NULL )
goto V_7;
F_3 ( V_2 -> V_2 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
V_7:
F_7 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_3 * V_4 ;
int V_9 , V_10 ;
V_4 = F_9 ( sizeof( struct V_3 ) , V_11 ) ;
if ( V_4 == NULL ) {
return - V_12 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( ( V_13 != 0 ) &&
F_1 () &&
( ( V_8 & V_14 ) == 0 ) )
V_8 |= V_15 ;
V_9 = F_10 ( V_4 , V_2 , V_2 -> V_16 , V_8 ) ;
if ( V_9 ) {
F_11 ( & V_2 -> V_16 -> V_2 , L_1 ) ;
goto V_17;
}
if ( ! V_9 ) {
V_10 = F_12 ( V_4 ) ;
if ( V_10 )
F_13 ( & V_2 -> V_16 -> V_2 ,
L_2 ) ;
}
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
F_16 ( V_4 ) ;
if ( F_17 ( V_2 ) ) {
F_18 ( V_2 -> V_2 ) ;
F_19 ( V_2 -> V_2 , 5000 ) ;
F_20 ( V_2 -> V_2 ) ;
F_21 ( V_2 -> V_2 ) ;
F_22 ( V_2 -> V_2 ) ;
F_23 ( V_2 -> V_2 ) ;
}
V_17:
if ( V_9 )
F_2 ( V_2 ) ;
return V_9 ;
}
static int F_24 ( struct V_1 * V_2 , void * V_18 , struct V_19 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_21 * V_22 = V_18 ;
struct V_23 * V_24 = & V_4 -> V_25 ;
void T_1 * V_17 = ( void T_1 * ) ( long ) V_22 -> V_26 ;
T_2 V_27 = V_22 -> V_28 ;
struct V_29 * V_30 ;
T_2 V_31 = 0 ;
T_3 V_32 = 0 ;
int V_33 , V_34 ;
if ( ! V_22 -> V_28 || ! V_22 -> V_26 )
return - V_35 ;
switch ( V_22 -> V_36 ) {
case V_37 :
V_31 = V_4 -> V_38 ;
return F_25 ( V_17 , & V_31 , F_26 ( V_27 , 4u ) ) ? - V_39 : 0 ;
case V_40 :
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_4 -> V_25 . V_41 ; V_33 ++ ) {
V_30 = (struct V_29 * ) V_24 -> V_42 [ V_33 ] ;
if ( V_30 && V_30 -> V_43 . V_44 == V_22 -> V_45 . V_44 ) {
struct V_46 * V_46 = F_27 ( V_30 ) ;
V_31 = V_46 -> V_47 ;
V_34 = 1 ;
break;
}
}
if ( ! V_34 ) {
F_28 ( L_3 , V_22 -> V_45 . V_44 ) ;
return - V_35 ;
}
return F_25 ( V_17 , & V_31 , F_26 ( V_27 , 4u ) ) ? - V_39 : 0 ;
case V_48 : {
struct V_49 V_50 = {} ;
enum V_51 type ;
T_2 V_52 = 0 ;
T_2 V_53 = 0 ;
T_2 V_54 = 0 ;
if ( V_22 -> V_55 . V_56 >= V_57 )
return - V_35 ;
switch ( V_22 -> V_55 . type ) {
case V_58 :
type = V_59 ;
for ( V_33 = 0 ; V_33 < V_4 -> V_60 . V_61 ; V_33 ++ )
V_52 |= ( ( V_4 -> V_60 . V_62 [ V_33 ] . V_63 ? 1 : 0 ) << V_33 ) ;
V_53 = V_64 ;
V_54 = 8 ;
break;
case V_65 :
type = V_59 ;
for ( V_33 = 0 ; V_33 < V_4 -> V_60 . V_66 ; V_33 ++ )
V_52 |= ( ( V_4 -> V_60 . V_67 [ V_33 ] . V_63 ? 1 : 0 ) << V_33 ) ;
V_53 = V_64 ;
V_54 = 8 ;
break;
case V_68 :
type = V_69 ;
for ( V_33 = 0 ; V_33 < V_4 -> V_70 . V_71 ; V_33 ++ )
V_52 |= ( ( V_4 -> V_70 . V_72 [ V_33 ] . V_73 . V_63 ? 1 : 0 ) << V_33 ) ;
V_53 = V_64 ;
V_54 = 1 ;
break;
case V_74 :
type = V_75 ;
V_52 = V_4 -> V_76 . V_73 . V_63 ? 1 : 0 ;
V_53 = V_64 ;
V_54 = 8 ;
break;
case V_77 :
type = V_78 ;
for ( V_33 = 0 ; V_33 < V_79 ; V_33 ++ )
V_52 |= ( ( V_4 -> V_80 . V_73 [ V_33 ] . V_63 ? 1 : 0 ) << V_33 ) ;
V_53 = V_64 ;
V_54 = 8 ;
break;
default:
return - V_35 ;
}
for ( V_33 = 0 ; V_33 < V_4 -> V_81 ; V_33 ++ ) {
if ( V_4 -> V_82 [ V_33 ] . type == type &&
V_4 -> V_83 [ V_33 ] . V_84 ) {
V_50 . V_85 = V_4 -> V_82 [ V_33 ] . V_86 ;
V_50 . V_87 = V_4 -> V_82 [ V_33 ] . V_88 ;
V_50 . V_89 = 0 ;
V_50 . V_90 = V_52 ;
V_50 . V_53 = V_53 ;
V_50 . V_54 = V_54 ;
break;
}
}
return F_25 ( V_17 , & V_50 ,
F_26 ( ( V_91 ) V_27 , sizeof( V_50 ) ) ) ? - V_39 : 0 ;
}
case V_92 : {
enum V_51 type ;
T_2 V_93 = 0 ;
switch ( V_22 -> V_55 . type ) {
case V_58 :
type = V_59 ;
break;
case V_65 :
type = V_59 ;
break;
case V_68 :
type = V_69 ;
break;
case V_74 :
type = V_75 ;
break;
case V_77 :
type = V_78 ;
break;
default:
return - V_35 ;
}
for ( V_33 = 0 ; V_33 < V_4 -> V_81 ; V_33 ++ )
if ( V_4 -> V_82 [ V_33 ] . type == type &&
V_4 -> V_83 [ V_33 ] . V_84 &&
V_93 < V_57 )
V_93 ++ ;
return F_25 ( V_17 , & V_93 , F_26 ( V_27 , 4u ) ) ? - V_39 : 0 ;
}
case V_94 :
V_32 = F_29 ( V_4 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_95 : {
struct V_96 V_97 ;
if ( V_22 -> V_98 . V_56 != 0 )
return - V_35 ;
switch ( V_22 -> V_98 . V_99 ) {
case V_100 :
V_97 . V_101 = V_4 -> V_80 . V_102 ;
V_97 . V_103 = V_4 -> V_80 . V_104 ;
break;
case V_105 :
V_97 . V_101 = V_4 -> V_76 . V_102 ;
V_97 . V_103 = 0 ;
break;
case V_106 :
V_97 . V_101 = V_4 -> V_107 . V_102 ;
V_97 . V_103 = 0 ;
break;
case V_108 :
V_97 . V_101 = V_4 -> V_60 . V_109 ;
V_97 . V_103 = V_4 -> V_60 . V_110 ;
break;
case V_111 :
V_97 . V_101 = V_4 -> V_60 . V_112 ;
V_97 . V_103 = V_4 -> V_60 . V_113 ;
break;
case V_114 :
V_97 . V_101 = V_4 -> V_60 . V_115 ;
V_97 . V_103 = V_4 -> V_60 . V_116 ;
break;
case V_117 :
V_97 . V_101 = V_4 -> V_60 . V_118 ;
V_97 . V_103 = V_4 -> V_60 . V_119 ;
break;
case V_120 :
if ( V_22 -> V_98 . V_121 == 0 ) {
V_97 . V_101 = V_4 -> V_60 . V_122 ;
V_97 . V_103 = V_4 -> V_60 . V_123 ;
} else if ( V_22 -> V_98 . V_121 == 1 ) {
V_97 . V_101 = V_4 -> V_60 . V_124 ;
V_97 . V_103 = V_4 -> V_60 . V_125 ;
} else
return - V_35 ;
break;
case V_126 :
V_97 . V_101 = V_4 -> V_127 . V_102 ;
V_97 . V_103 = 0 ;
break;
case V_128 :
if ( V_22 -> V_98 . V_121 >= V_4 -> V_70 . V_71 )
return - V_35 ;
V_97 . V_101 = V_4 -> V_70 . V_72 [ V_22 -> V_98 . V_121 ] . V_102 ;
V_97 . V_103 = V_4 -> V_70 . V_72 [ V_22 -> V_98 . V_121 ] . V_129 ;
break;
default:
return - V_35 ;
}
return F_25 ( V_17 , & V_97 ,
F_26 ( ( V_91 ) V_27 , sizeof( V_97 ) ) ) ? - V_39 : 0 ;
}
case V_130 :
V_32 = F_30 ( & V_4 -> V_131 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_132 :
V_32 = F_30 ( & V_4 -> V_133 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_134 :
V_32 = F_30 ( & V_4 -> V_135 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_136 :
V_32 = F_30 ( & V_4 -> V_137 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_138 : {
struct V_139 V_140 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_141 = V_4 -> V_142 . V_143 . V_144 >> V_145 ;
V_140 . V_146 = V_4 -> V_142 . V_143 . V_147 >> V_145 ;
V_140 . V_148 = V_4 -> V_142 . V_143 . V_149 >> V_145 ;
V_140 . V_150 = V_4 -> V_142 . V_151 . V_144 >> V_152 ;
V_140 . V_153 = V_4 -> V_142 . V_151 . V_147 >> V_152 ;
V_140 . V_154 = V_4 -> V_142 . V_155 . V_144 >> V_156 ;
V_140 . V_157 = V_4 -> V_142 . V_155 . V_147 >> V_156 ;
return F_25 ( V_17 , & V_140 ,
F_26 ( ( V_91 ) V_27 , sizeof( V_140 ) ) ) ? - V_39 : 0 ;
}
case V_158 : {
struct V_159 V_160 ;
V_160 . V_161 = V_4 -> V_107 . V_162 ;
V_160 . V_161 -= V_4 -> V_163 ;
V_160 . V_164 = V_4 -> V_107 . V_165 ;
V_160 . V_164 -= ( V_4 -> V_163 - V_4 -> V_166 ) ;
V_160 . V_167 = V_4 -> V_107 . V_167 ;
V_160 . V_167 -= V_4 -> V_168 ;
return F_25 ( V_17 , & V_160 ,
F_26 ( ( V_91 ) V_27 , sizeof( V_160 ) ) ) ? - V_39 : 0 ;
}
case V_169 : {
unsigned V_170 , V_171 ;
T_2 * V_172 ;
unsigned V_173 = ( V_22 -> V_174 . V_72 >>
V_175 ) &
V_176 ;
unsigned V_177 = ( V_22 -> V_174 . V_72 >>
V_178 ) &
V_179 ;
if ( V_173 == V_176 )
V_173 = 0xffffffff ;
if ( V_177 == V_179 )
V_177 = 0xffffffff ;
V_172 = F_31 ( V_22 -> V_174 . V_93 , sizeof( * V_172 ) , V_11 ) ;
if ( ! V_172 )
return - V_12 ;
V_171 = V_22 -> V_174 . V_93 * sizeof( * V_172 ) ;
for ( V_33 = 0 ; V_33 < V_22 -> V_174 . V_93 ; V_33 ++ )
if ( F_32 ( V_4 , V_173 , V_177 ,
V_22 -> V_174 . V_180 + V_33 ,
& V_172 [ V_33 ] ) ) {
F_28 ( L_4 ,
V_22 -> V_174 . V_180 + V_33 ) ;
F_7 ( V_172 ) ;
return - V_39 ;
}
V_170 = F_25 ( V_17 , V_172 , F_26 ( V_27 , V_171 ) ) ;
F_7 ( V_172 ) ;
return V_170 ? - V_39 : 0 ;
}
case V_181 : {
struct V_182 V_183 = {} ;
V_183 . V_184 = V_2 -> V_16 -> V_185 ;
V_183 . V_186 = V_4 -> V_187 ;
V_183 . V_188 = V_4 -> V_189 ;
V_183 . V_190 = V_2 -> V_16 -> V_191 ;
V_183 . V_192 = V_4 -> V_192 ;
V_183 . V_193 = V_4 -> V_60 . V_194 . V_195 ;
V_183 . V_196 = V_4 -> V_60 . V_194 . V_197 ;
V_183 . V_198 = F_33 ( V_4 ) * 10 ;
if ( V_4 -> V_127 . V_199 ) {
V_183 . V_200 =
V_4 -> V_127 . V_201 . V_202 . V_203 . V_204 * 10 ;
V_183 . V_205 =
V_4 -> V_127 . V_201 . V_202 . V_203 . V_206 * 10 ;
} else {
V_183 . V_200 = V_4 -> V_127 . V_207 * 10 ;
V_183 . V_205 = V_4 -> V_127 . V_208 * 10 ;
}
V_183 . V_209 = V_4 -> V_60 . V_194 . V_210 ;
V_183 . V_211 = V_4 -> V_60 . V_194 . V_212 *
V_4 -> V_60 . V_194 . V_195 ;
V_183 . V_213 = V_4 -> V_60 . V_194 . V_214 ;
V_183 . V_215 = 0 ;
V_183 . V_216 = 0 ;
if ( V_4 -> V_8 & V_14 )
V_183 . V_216 |= V_217 ;
V_183 . V_218 = V_219 ;
V_183 . V_220 = ( T_3 ) V_4 -> V_221 . V_222 * V_64 ;
V_183 . V_223 = F_34 ( ( int ) V_224 , V_64 ) ;
V_183 . V_225 = ( 1 << V_226 ) *
V_64 ;
V_183 . V_227 = V_64 ;
V_183 . V_228 = V_4 -> V_60 . V_229 . V_230 ;
V_183 . V_231 = V_4 -> V_60 . V_229 . V_232 ;
V_183 . V_233 = V_4 -> V_60 . V_233 ;
memcpy ( & V_183 . V_234 [ 0 ] , & V_4 -> V_60 . V_229 . V_235 [ 0 ] ,
sizeof( V_4 -> V_60 . V_229 . V_235 ) ) ;
V_183 . V_236 = V_4 -> V_107 . V_236 ;
V_183 . V_237 = V_4 -> V_107 . V_238 ;
V_183 . V_239 = V_4 -> V_80 . V_240 ;
return F_25 ( V_17 , & V_183 ,
F_26 ( ( V_91 ) V_27 , sizeof( V_183 ) ) ) ? - V_39 : 0 ;
}
default:
F_28 ( L_5 , V_22 -> V_36 ) ;
return - V_35 ;
}
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_36 ( V_4 ) ;
F_37 () ;
}
int F_38 ( struct V_1 * V_2 , struct V_19 * V_241 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_242 * V_243 ;
int V_9 ;
V_241 -> V_244 = NULL ;
V_9 = F_3 ( V_2 -> V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_243 = F_9 ( sizeof( * V_243 ) , V_11 ) ;
if ( F_39 ( ! V_243 ) )
return - V_12 ;
V_9 = F_40 ( V_4 , & V_243 -> V_245 ) ;
if ( V_9 )
goto V_246;
F_41 ( & V_243 -> V_247 ) ;
F_42 ( & V_243 -> V_248 ) ;
F_43 ( & V_243 -> V_249 ) ;
V_241 -> V_244 = V_243 ;
F_22 ( V_2 -> V_2 ) ;
F_23 ( V_2 -> V_2 ) ;
return 0 ;
V_246:
F_7 ( V_243 ) ;
return V_9 ;
}
void F_44 ( struct V_1 * V_2 ,
struct V_19 * V_241 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_242 * V_243 = V_241 -> V_244 ;
struct V_250 * V_251 ;
int V_252 ;
if ( ! V_243 )
return;
F_45 ( & V_243 -> V_249 ) ;
F_46 ( V_4 , & V_243 -> V_245 ) ;
F_47 (&fpriv->bo_list_handles, list, handle)
F_48 ( V_251 ) ;
F_49 ( & V_243 -> V_248 ) ;
F_50 ( & V_243 -> V_247 ) ;
F_7 ( V_243 ) ;
V_241 -> V_244 = NULL ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_19 * V_241 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_52 ( V_4 , V_241 ) ;
F_53 ( V_4 , V_241 ) ;
}
T_4 F_54 ( struct V_1 * V_2 , unsigned int V_253 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_254 , V_255 , V_256 ;
T_4 V_93 ;
if ( V_253 >= V_4 -> V_25 . V_41 ) {
F_55 ( L_6 , V_253 ) ;
return - V_35 ;
}
if ( V_4 -> V_25 . V_42 [ V_253 ] ) {
do {
V_93 = F_56 ( V_4 , V_253 ) ;
V_256 = F_57 (
V_2 , V_253 , V_257 ,
& V_254 , & V_255 , NULL , NULL ,
& V_4 -> V_25 . V_42 [ V_253 ] -> V_43 . V_258 ) ;
} while ( V_93 != F_56 ( V_4 , V_253 ) );
if ( ( ( V_256 & ( V_259 | V_260 ) ) !=
( V_259 | V_260 ) ) ) {
F_58 ( L_7 , V_256 ) ;
} else {
F_58 ( L_8 ,
V_253 , V_254 ) ;
if ( V_254 >= 0 )
V_93 ++ ;
}
} else {
V_93 = F_56 ( V_4 , V_253 ) ;
F_58 ( L_9 ) ;
}
return V_93 ;
}
int F_59 ( struct V_1 * V_2 , unsigned int V_253 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_261 = F_60 ( V_4 , V_253 ) ;
return F_61 ( V_4 , & V_4 -> V_262 , V_261 ) ;
}
void F_62 ( struct V_1 * V_2 , unsigned int V_253 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_261 = F_60 ( V_4 , V_253 ) ;
F_63 ( V_4 , & V_4 -> V_262 , V_261 ) ;
}
int F_64 ( struct V_1 * V_2 , unsigned int V_253 ,
int * V_263 ,
struct V_264 * V_265 ,
unsigned V_8 )
{
struct V_29 * V_30 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_253 >= V_2 -> V_266 ) {
F_55 ( L_6 , V_253 ) ;
return - V_35 ;
}
V_30 = & V_4 -> V_25 . V_42 [ V_253 ] -> V_43 ;
if ( ! V_30 ) {
F_55 ( L_10 , V_253 ) ;
return - V_35 ;
}
return F_65 ( V_2 , V_253 , V_263 ,
V_265 , V_8 ,
& V_30 -> V_258 ) ;
}
