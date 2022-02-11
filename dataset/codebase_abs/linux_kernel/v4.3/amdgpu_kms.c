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
V_52 = V_4 -> V_70 [ 0 ] . V_71 . V_63 ? 1 : 0 ;
V_52 |= ( ( V_4 -> V_70 [ 1 ] . V_71 . V_63 ? 1 : 0 ) << 1 ) ;
V_53 = V_64 ;
V_54 = 1 ;
break;
case V_72 :
type = V_73 ;
V_52 = V_4 -> V_74 . V_71 . V_63 ? 1 : 0 ;
V_53 = V_64 ;
V_54 = 8 ;
break;
case V_75 :
type = V_76 ;
for ( V_33 = 0 ; V_33 < V_77 ; V_33 ++ )
V_52 |= ( ( V_4 -> V_78 . V_71 [ V_33 ] . V_63 ? 1 : 0 ) << V_33 ) ;
V_53 = V_64 ;
V_54 = 8 ;
break;
default:
return - V_35 ;
}
for ( V_33 = 0 ; V_33 < V_4 -> V_79 ; V_33 ++ ) {
if ( V_4 -> V_80 [ V_33 ] . type == type &&
V_4 -> V_81 [ V_33 ] . V_82 ) {
V_50 . V_83 = V_4 -> V_80 [ V_33 ] . V_84 ;
V_50 . V_85 = V_4 -> V_80 [ V_33 ] . V_86 ;
V_50 . V_87 = 0 ;
V_50 . V_88 = V_52 ;
V_50 . V_53 = V_53 ;
V_50 . V_54 = V_54 ;
break;
}
}
return F_25 ( V_17 , & V_50 ,
F_26 ( ( V_89 ) V_27 , sizeof( V_50 ) ) ) ? - V_39 : 0 ;
}
case V_90 : {
enum V_51 type ;
T_2 V_91 = 0 ;
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
case V_72 :
type = V_73 ;
break;
case V_75 :
type = V_76 ;
break;
default:
return - V_35 ;
}
for ( V_33 = 0 ; V_33 < V_4 -> V_79 ; V_33 ++ )
if ( V_4 -> V_80 [ V_33 ] . type == type &&
V_4 -> V_81 [ V_33 ] . V_82 &&
V_91 < V_57 )
V_91 ++ ;
return F_25 ( V_17 , & V_91 , F_26 ( V_27 , 4u ) ) ? - V_39 : 0 ;
}
case V_92 :
V_32 = F_29 ( V_4 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_93 : {
struct V_94 V_95 ;
if ( V_22 -> V_96 . V_56 != 0 )
return - V_35 ;
switch ( V_22 -> V_96 . V_97 ) {
case V_98 :
V_95 . V_99 = V_4 -> V_78 . V_100 ;
V_95 . V_101 = V_4 -> V_78 . V_102 ;
break;
case V_103 :
V_95 . V_99 = 0 ;
V_95 . V_101 = 0 ;
break;
case V_104 :
V_95 . V_99 = V_4 -> V_105 . V_100 ;
V_95 . V_101 = 0 ;
break;
case V_106 :
V_95 . V_99 = V_4 -> V_60 . V_107 ;
V_95 . V_101 = V_4 -> V_60 . V_108 ;
break;
case V_109 :
V_95 . V_99 = V_4 -> V_60 . V_110 ;
V_95 . V_101 = V_4 -> V_60 . V_111 ;
break;
case V_112 :
V_95 . V_99 = V_4 -> V_60 . V_113 ;
V_95 . V_101 = V_4 -> V_60 . V_114 ;
break;
case V_115 :
V_95 . V_99 = V_4 -> V_60 . V_116 ;
V_95 . V_101 = V_4 -> V_60 . V_117 ;
break;
case V_118 :
if ( V_22 -> V_96 . V_119 == 0 ) {
V_95 . V_99 = V_4 -> V_60 . V_120 ;
V_95 . V_101 = V_4 -> V_60 . V_121 ;
} else if ( V_22 -> V_96 . V_119 == 1 ) {
V_95 . V_99 = V_4 -> V_60 . V_122 ;
V_95 . V_101 = V_4 -> V_60 . V_123 ;
} else
return - V_35 ;
break;
case V_124 :
V_95 . V_99 = V_4 -> V_125 . V_100 ;
V_95 . V_101 = 0 ;
break;
case V_126 :
if ( V_22 -> V_96 . V_119 >= 2 )
return - V_35 ;
V_95 . V_99 = V_4 -> V_70 [ V_22 -> V_96 . V_119 ] . V_100 ;
V_95 . V_101 = V_4 -> V_70 [ V_22 -> V_96 . V_119 ] . V_127 ;
break;
default:
return - V_35 ;
}
return F_25 ( V_17 , & V_95 ,
F_26 ( ( V_89 ) V_27 , sizeof( V_95 ) ) ) ? - V_39 : 0 ;
}
case V_128 :
V_32 = F_30 ( & V_4 -> V_129 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_130 :
V_32 = F_30 ( & V_4 -> V_131 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_132 :
V_32 = F_30 ( & V_4 -> V_133 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_134 :
V_32 = F_30 ( & V_4 -> V_135 ) ;
return F_25 ( V_17 , & V_32 , F_26 ( V_27 , 8u ) ) ? - V_39 : 0 ;
case V_136 : {
struct V_137 V_138 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . V_139 = V_4 -> V_140 . V_141 . V_142 >> V_143 ;
V_138 . V_144 = V_4 -> V_140 . V_141 . V_145 >> V_143 ;
V_138 . V_146 = V_4 -> V_140 . V_141 . V_147 >> V_143 ;
V_138 . V_148 = V_4 -> V_140 . V_149 . V_142 >> V_150 ;
V_138 . V_151 = V_4 -> V_140 . V_149 . V_145 >> V_150 ;
V_138 . V_152 = V_4 -> V_140 . V_153 . V_142 >> V_154 ;
V_138 . V_155 = V_4 -> V_140 . V_153 . V_145 >> V_154 ;
return F_25 ( V_17 , & V_138 ,
F_26 ( ( V_89 ) V_27 , sizeof( V_138 ) ) ) ? - V_39 : 0 ;
}
case V_156 : {
struct V_157 V_158 ;
V_158 . V_159 = V_4 -> V_105 . V_160 ;
V_158 . V_161 = V_4 -> V_105 . V_162 ;
V_158 . V_161 -= V_4 -> V_163 ;
V_158 . V_164 = V_4 -> V_105 . V_164 ;
V_158 . V_164 -= V_4 -> V_165 ;
return F_25 ( V_17 , & V_158 ,
F_26 ( ( V_89 ) V_27 , sizeof( V_158 ) ) ) ? - V_39 : 0 ;
}
case V_166 : {
unsigned V_167 , V_168 ;
T_2 * V_169 ;
unsigned V_170 = ( V_22 -> V_171 . V_172 >>
V_173 ) &
V_174 ;
unsigned V_175 = ( V_22 -> V_171 . V_172 >>
V_176 ) &
V_177 ;
if ( V_170 == V_174 )
V_170 = 0xffffffff ;
if ( V_175 == V_177 )
V_175 = 0xffffffff ;
V_169 = F_31 ( V_22 -> V_171 . V_91 , sizeof( * V_169 ) , V_11 ) ;
if ( ! V_169 )
return - V_12 ;
V_168 = V_22 -> V_171 . V_91 * sizeof( * V_169 ) ;
for ( V_33 = 0 ; V_33 < V_22 -> V_171 . V_91 ; V_33 ++ )
if ( F_32 ( V_4 , V_170 , V_175 ,
V_22 -> V_171 . V_178 + V_33 ,
& V_169 [ V_33 ] ) ) {
F_28 ( L_4 ,
V_22 -> V_171 . V_178 + V_33 ) ;
F_7 ( V_169 ) ;
return - V_39 ;
}
V_167 = F_25 ( V_17 , V_169 , F_26 ( V_27 , V_168 ) ) ;
F_7 ( V_169 ) ;
return V_167 ? - V_39 : 0 ;
}
case V_179 : {
struct V_180 V_181 = {} ;
struct V_182 V_183 ;
V_181 . V_184 = V_2 -> V_16 -> V_185 ;
V_181 . V_186 = V_4 -> V_187 ;
V_181 . V_188 = V_4 -> V_189 ;
V_181 . V_190 = V_2 -> V_16 -> V_191 ;
V_181 . V_192 = V_4 -> V_192 ;
V_181 . V_193 = V_4 -> V_60 . V_194 . V_195 ;
V_181 . V_196 = V_4 -> V_60 . V_194 . V_197 ;
V_181 . V_198 = F_33 ( V_4 ) * 10 ;
if ( V_4 -> V_125 . V_199 ) {
V_181 . V_200 =
V_4 -> V_125 . V_201 . V_202 . V_203 . V_204 * 10 ;
V_181 . V_205 =
V_4 -> V_125 . V_201 . V_202 . V_203 . V_206 * 10 ;
} else {
V_181 . V_200 = V_4 -> V_125 . V_207 * 10 ;
V_181 . V_205 = V_4 -> V_125 . V_208 * 10 ;
}
V_181 . V_209 = V_4 -> V_60 . V_194 . V_210 ;
V_181 . V_211 = V_4 -> V_60 . V_194 . V_212 *
V_4 -> V_60 . V_194 . V_195 ;
V_181 . V_213 = V_4 -> V_60 . V_194 . V_214 ;
V_181 . V_215 = 0 ;
V_181 . V_216 = 0 ;
if ( V_4 -> V_8 & V_14 )
V_181 . V_216 |= V_217 ;
V_181 . V_218 = V_219 ;
V_181 . V_220 = ( T_3 ) V_4 -> V_221 . V_222 * V_64 ;
V_181 . V_223 = F_34 ( ( int ) V_224 , V_64 ) ;
V_181 . V_225 = ( 1 << V_226 ) *
V_64 ;
V_181 . V_227 = V_64 ;
F_35 ( V_4 , & V_183 ) ;
V_181 . V_228 = V_183 . V_229 ;
V_181 . V_230 = V_183 . V_231 ;
V_181 . V_232 = V_4 -> V_60 . V_232 ;
memcpy ( & V_181 . V_233 [ 0 ] , & V_183 . V_234 [ 0 ] , sizeof( V_183 . V_234 ) ) ;
V_181 . V_235 = V_4 -> V_105 . V_235 ;
V_181 . V_236 = V_4 -> V_105 . V_237 ;
V_181 . V_238 = V_4 -> V_78 . V_239 ;
return F_25 ( V_17 , & V_181 ,
F_26 ( ( V_89 ) V_27 , sizeof( V_181 ) ) ) ? - V_39 : 0 ;
}
default:
F_28 ( L_5 , V_22 -> V_36 ) ;
return - V_35 ;
}
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_37 ( V_4 ) ;
F_38 () ;
}
int F_39 ( struct V_1 * V_2 , struct V_19 * V_240 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_241 * V_242 ;
int V_9 ;
V_240 -> V_243 = NULL ;
V_9 = F_3 ( V_2 -> V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_242 = F_9 ( sizeof( * V_242 ) , V_11 ) ;
if ( F_40 ( ! V_242 ) )
return - V_12 ;
V_9 = F_41 ( V_4 , & V_242 -> V_244 ) ;
if ( V_9 )
goto V_245;
F_42 ( & V_242 -> V_246 ) ;
F_43 ( & V_242 -> V_247 ) ;
F_44 ( & V_242 -> V_248 ) ;
V_240 -> V_243 = V_242 ;
F_22 ( V_2 -> V_2 ) ;
F_23 ( V_2 -> V_2 ) ;
return 0 ;
V_245:
F_7 ( V_242 ) ;
return V_9 ;
}
void F_45 ( struct V_1 * V_2 ,
struct V_19 * V_240 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_241 * V_242 = V_240 -> V_243 ;
struct V_249 * V_250 ;
int V_251 ;
if ( ! V_242 )
return;
F_46 ( & V_242 -> V_248 ) ;
F_47 ( V_4 , & V_242 -> V_244 ) ;
F_48 (&fpriv->bo_list_handles, list, handle)
F_49 ( V_250 ) ;
F_50 ( & V_242 -> V_247 ) ;
F_51 ( & V_242 -> V_246 ) ;
F_7 ( V_242 ) ;
V_240 -> V_243 = NULL ;
}
void F_52 ( struct V_1 * V_2 ,
struct V_19 * V_240 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_53 ( V_4 , V_240 ) ;
F_54 ( V_4 , V_240 ) ;
}
T_4 F_55 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_4 -> V_25 . V_41 ) {
F_56 ( L_6 , V_30 ) ;
return - V_35 ;
}
return F_57 ( V_4 , V_30 ) ;
}
int F_58 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_252 = F_59 ( V_4 , V_30 ) ;
return F_60 ( V_4 , & V_4 -> V_253 , V_252 ) ;
}
void F_61 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_252 = F_59 ( V_4 , V_30 ) ;
F_62 ( V_4 , & V_4 -> V_253 , V_252 ) ;
}
int F_63 ( struct V_1 * V_2 , int V_30 ,
int * V_254 ,
struct V_255 * V_256 ,
unsigned V_8 )
{
struct V_29 * V_257 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_2 -> V_258 ) {
F_56 ( L_6 , V_30 ) ;
return - V_35 ;
}
V_257 = & V_4 -> V_25 . V_42 [ V_30 ] -> V_43 ;
return F_64 ( V_2 , V_30 , V_254 ,
V_256 , V_8 ,
V_257 , & V_257 -> V_259 ) ;
}
