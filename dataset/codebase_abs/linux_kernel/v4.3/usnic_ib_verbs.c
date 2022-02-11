static void F_1 ( char * V_1 , T_1 * V_2 )
{
* V_2 = ( T_1 ) * V_1 ;
}
static int F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_19 , V_20 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_8 = V_4 -> V_21 -> V_22 ;
V_12 = F_3 ( V_4 -> V_21 -> V_23 ) ;
if ( ! V_12 ) {
F_4 ( L_1 ,
V_4 -> V_24 ) ;
return - V_25 ;
}
V_14 = F_5 ( V_4 -> V_21 -> V_23 , 0 ) ;
if ( ! V_14 ) {
F_4 ( L_2 ,
V_4 -> V_24 , F_6 ( V_12 ) ) ;
return - V_25 ;
}
V_10 . V_26 = F_7 ( V_4 -> V_21 -> V_23 ) ;
V_10 . V_27 = V_14 -> V_28 ;
V_10 . V_29 = V_14 -> V_30 ;
V_16 = F_8 ( V_4 , V_31 ) ;
if ( F_9 ( V_16 ) ) {
F_4 ( L_3 ,
F_10 ( V_31 ) ,
V_4 -> V_24 ,
F_11 ( V_16 ) ) ;
return V_16 ? F_11 ( V_16 ) : - V_32 ;
}
F_12 ( V_16 -> type != V_31 ) ;
V_10 . V_33 = V_16 -> V_34 ;
for ( V_19 = 0 ; V_19 < V_16 -> V_34 ; V_19 ++ )
V_10 . V_35 [ V_19 ] = V_16 -> V_36 [ V_19 ] -> V_37 ;
V_16 = F_8 ( V_4 , V_38 ) ;
if ( F_9 ( V_16 ) ) {
F_4 ( L_3 ,
F_10 ( V_38 ) ,
V_4 -> V_24 ,
F_11 ( V_16 ) ) ;
return V_16 ? F_11 ( V_16 ) : - V_32 ;
}
F_12 ( V_16 -> type != V_38 ) ;
V_10 . V_39 = V_16 -> V_34 ;
for ( V_19 = 0 ; V_19 < V_16 -> V_34 ; V_19 ++ )
V_10 . V_40 [ V_19 ] = V_16 -> V_36 [ V_19 ] -> V_37 ;
V_16 = F_8 ( V_4 , V_41 ) ;
if ( F_9 ( V_16 ) ) {
F_4 ( L_3 ,
F_10 ( V_41 ) ,
V_4 -> V_24 ,
F_11 ( V_16 ) ) ;
return V_16 ? F_11 ( V_16 ) : - V_32 ;
}
F_12 ( V_16 -> type != V_41 ) ;
V_10 . V_42 = V_16 -> V_34 ;
for ( V_19 = 0 ; V_19 < V_16 -> V_34 ; V_19 ++ )
V_10 . V_43 [ V_19 ] = V_16 -> V_36 [ V_19 ] -> V_37 ;
V_18 = F_13 ( & V_4 -> V_44 ,
struct V_17 , V_45 ) ;
V_10 . V_46 = V_18 -> V_47 ;
V_20 = F_14 ( V_6 , & V_10 , sizeof( V_10 ) ) ;
if ( V_20 ) {
F_4 ( L_4 , V_8 -> V_48 . V_49 ) ;
return V_20 ;
}
return 0 ;
}
static struct V_3 *
F_15 ( struct V_7 * V_8 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_56 * V_21 ;
struct V_57 * V_23 ;
struct V_3 * V_4 ;
struct V_58 * V_59 , * * V_60 ;
int V_19 , V_61 = 0 ;
F_16 ( ! F_17 ( & V_8 -> V_62 ) ) ;
if ( F_18 ( & V_8 -> V_63 ) ) {
F_19 ( L_5 ) ;
return NULL ;
}
if ( V_64 ) {
V_60 = F_20 ( V_51 -> V_65 ) ;
for ( V_19 = 0 ; V_60 [ V_19 ] ; V_19 ++ ) {
V_59 = V_60 [ V_19 ] ;
V_21 = F_21 ( F_22 ( V_59 ) ) ;
F_23 ( & V_21 -> V_66 ) ;
V_23 = V_21 -> V_23 ;
if ( ! F_24 ( V_23 , V_55 ) ) {
F_25 ( L_6 ,
V_8 -> V_48 . V_49 ,
F_6 ( F_3 (
V_23 ) ) ) ;
V_61 = 1 ;
break;
}
F_26 ( & V_21 -> V_66 ) ;
}
F_27 ( V_60 ) ;
}
if ( ! V_61 ) {
F_28 (vf, &us_ibdev->vf_dev_list, link) {
F_23 ( & V_21 -> V_66 ) ;
V_23 = V_21 -> V_23 ;
if ( V_21 -> V_67 == 0 &&
F_24 ( V_23 , V_55 ) == 0 ) {
V_61 = 1 ;
break;
}
F_26 ( & V_21 -> V_66 ) ;
}
}
if ( ! V_61 ) {
F_19 ( L_7 ,
V_8 -> V_48 . V_49 ) ;
return F_29 ( - V_32 ) ;
}
V_4 = F_30 ( V_8 -> V_68 , V_21 , V_51 , V_55 ,
V_53 ) ;
F_26 ( & V_21 -> V_66 ) ;
if ( F_9 ( V_4 ) ) {
F_4 ( L_8 ) ;
return F_29 ( V_4 ? F_11 ( V_4 ) : - V_32 ) ;
}
return V_4 ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_56 * V_21 = V_4 -> V_21 ;
F_12 ( V_4 -> V_69 != V_70 ) ;
F_23 ( & V_21 -> V_66 ) ;
F_32 ( V_4 ) ;
F_26 ( & V_21 -> V_66 ) ;
}
static void F_33 ( int V_71 , T_2 * V_72 ,
T_2 * V_73 )
{
if ( V_71 <= 10000 ) {
* V_73 = V_74 ;
* V_72 = V_75 ;
} else if ( V_71 <= 20000 ) {
* V_73 = V_76 ;
* V_72 = V_77 ;
} else if ( V_71 <= 30000 ) {
* V_73 = V_76 ;
* V_72 = V_78 ;
} else if ( V_71 <= 40000 ) {
* V_73 = V_76 ;
* V_72 = V_75 ;
} else {
* V_73 = V_76 ;
* V_72 = V_79 ;
}
}
static int F_34 ( struct V_80 V_81 )
{
if ( V_81 . V_82 . V_47 <= V_83 ||
V_81 . V_82 . V_47 >= V_84 )
return - V_85 ;
return 0 ;
}
enum V_86 F_35 ( struct V_87 * V_58 ,
T_2 V_88 )
{
return V_89 ;
}
int F_36 ( struct V_87 * V_90 ,
struct V_91 * V_92 ,
struct V_5 * V_93 )
{
struct V_7 * V_8 = F_37 ( V_90 ) ;
union V_94 V_95 ;
struct V_96 V_97 ;
struct V_98 V_81 ;
int V_99 ;
F_25 ( L_9 ) ;
if ( V_93 -> V_100 || V_93 -> V_101 )
return - V_85 ;
F_38 ( & V_8 -> V_62 ) ;
V_8 -> V_102 -> V_103 -> V_104 ( V_8 -> V_102 , & V_97 ) ;
V_8 -> V_102 -> V_103 -> V_105 ( V_8 -> V_102 , & V_81 ) ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
F_39 ( V_8 -> V_68 -> V_106 , V_8 -> V_68 -> V_107 ,
& V_95 . V_108 [ 0 ] ) ;
memcpy ( & V_92 -> V_109 , & V_95 . V_110 . V_111 ,
sizeof( V_95 . V_110 . V_111 ) ) ;
F_1 ( & V_97 . V_112 [ 0 ] , & V_92 -> V_2 ) ;
V_92 -> V_113 = V_114 ;
V_92 -> V_115 = V_116 ;
V_92 -> V_117 = V_118 ;
V_92 -> V_119 = V_120 ;
V_92 -> V_121 = V_8 -> V_12 -> V_122 ;
V_99 = F_40 ( V_8 -> V_123 [ V_38 ] ,
V_8 -> V_123 [ V_31 ] ) ;
V_92 -> V_124 = V_99 *
F_41 ( & V_8 -> V_125 . V_126 ) ;
V_92 -> V_127 = V_128 |
V_129 | V_130 ;
V_92 -> V_131 = V_8 -> V_123 [ V_41 ] *
F_41 ( & V_8 -> V_125 . V_126 ) ;
V_92 -> V_132 = V_133 ;
V_92 -> V_134 = V_135 ;
V_92 -> V_136 = 0 ;
V_92 -> V_137 = 0 ;
V_92 -> V_138 = V_139 ;
V_92 -> V_140 = V_92 -> V_138 ;
V_92 -> V_141 = 0 ;
V_92 -> V_142 = 0 ;
V_92 -> V_143 = 0 ;
V_92 -> V_144 = 0 ;
V_92 -> V_145 = 0 ;
V_92 -> V_146 = 0 ;
V_92 -> V_147 = 0 ;
V_92 -> V_148 = 0 ;
V_92 -> V_149 = 0 ;
V_92 -> V_150 = 0 ;
V_92 -> V_151 = 0 ;
F_42 ( & V_8 -> V_62 ) ;
return 0 ;
}
int F_43 ( struct V_87 * V_90 , T_2 V_152 ,
struct V_153 * V_92 )
{
struct V_7 * V_8 = F_37 ( V_90 ) ;
struct V_98 V_81 ;
F_25 ( L_9 ) ;
F_38 ( & V_8 -> V_62 ) ;
V_8 -> V_102 -> V_103 -> V_105 ( V_8 -> V_102 , & V_81 ) ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_92 -> V_154 = 0 ;
V_92 -> V_155 = 1 ;
V_92 -> V_156 = 0 ;
V_92 -> V_157 = 0 ;
if ( ! V_8 -> V_68 -> V_158 ) {
V_92 -> V_69 = V_159 ;
V_92 -> V_160 = 3 ;
} else if ( ! V_8 -> V_68 -> V_107 ) {
V_92 -> V_69 = V_161 ;
V_92 -> V_160 = 4 ;
} else {
V_92 -> V_69 = V_162 ;
V_92 -> V_160 = 5 ;
}
V_92 -> V_163 = 0 ;
V_92 -> V_164 = 1 ;
V_92 -> V_165 = 1 ;
V_92 -> V_166 = 0 ;
V_92 -> V_167 = 0 ;
F_33 ( V_81 . V_71 , & V_92 -> V_72 ,
& V_92 -> V_73 ) ;
V_92 -> V_168 = V_169 ;
V_92 -> V_170 = F_44 ( V_8 -> V_68 -> V_171 ) ;
V_92 -> V_172 = V_8 -> V_68 -> V_171 ;
V_92 -> V_173 = 1 ;
F_42 ( & V_8 -> V_62 ) ;
return 0 ;
}
int F_45 ( struct V_174 * V_175 , struct V_176 * V_177 ,
int V_178 ,
struct V_179 * V_180 )
{
struct V_3 * V_4 ;
struct V_56 * V_21 ;
int V_20 ;
F_25 ( L_9 ) ;
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
V_4 = F_46 ( V_175 ) ;
V_21 = V_4 -> V_21 ;
F_38 ( & V_21 -> V_22 -> V_62 ) ;
F_25 ( L_9 ) ;
V_177 -> V_181 = V_4 -> V_69 ;
V_177 -> V_182 = V_4 -> V_69 ;
switch ( V_4 -> V_183 . V_184 ) {
case V_185 :
V_177 -> V_186 = 0 ;
break;
default:
F_4 ( L_10 , V_4 -> V_183 . V_184 ) ;
V_20 = - V_85 ;
goto V_187;
}
F_42 ( & V_21 -> V_22 -> V_62 ) ;
return 0 ;
V_187:
F_42 ( & V_21 -> V_22 -> V_62 ) ;
return V_20 ;
}
int F_47 ( struct V_87 * V_90 , T_2 V_152 , int V_188 ,
union V_94 * V_95 )
{
struct V_7 * V_8 = F_37 ( V_90 ) ;
F_25 ( L_9 ) ;
if ( V_188 > 1 )
return - V_85 ;
F_38 ( & V_8 -> V_62 ) ;
memset ( & ( V_95 -> V_108 [ 0 ] ) , 0 , sizeof( V_95 -> V_108 ) ) ;
F_39 ( V_8 -> V_68 -> V_106 , V_8 -> V_68 -> V_107 ,
& V_95 -> V_108 [ 0 ] ) ;
F_42 ( & V_8 -> V_62 ) ;
return 0 ;
}
int F_48 ( struct V_87 * V_90 , T_2 V_152 , T_3 V_188 ,
T_3 * V_189 )
{
if ( V_188 > 1 )
return - V_85 ;
* V_189 = 0xffff ;
return 0 ;
}
struct V_190 * F_49 ( struct V_87 * V_90 ,
struct V_191 * V_192 ,
struct V_5 * V_6 )
{
struct V_50 * V_51 ;
void * V_65 ;
F_25 ( L_9 ) ;
V_51 = F_50 ( sizeof( * V_51 ) , V_193 ) ;
if ( ! V_51 )
return F_29 ( - V_32 ) ;
V_65 = V_51 -> V_65 = F_51 () ;
if ( F_9 ( V_65 ) ) {
F_52 ( V_51 ) ;
return F_29 ( V_65 ? F_11 ( V_65 ) : - V_32 ) ;
}
F_19 ( L_11 ,
V_51 , V_192 , V_90 -> V_49 ) ;
return & V_51 -> V_194 ;
}
int F_53 ( struct V_190 * V_51 )
{
F_19 ( L_12 , V_51 ) ;
F_54 ( ( F_55 ( V_51 ) ) -> V_65 ) ;
F_52 ( V_51 ) ;
return 0 ;
}
struct V_174 * F_56 ( struct V_190 * V_51 ,
struct V_179 * V_195 ,
struct V_5 * V_6 )
{
int V_20 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_196 * V_197 ;
int V_42 ;
struct V_54 V_55 ;
struct V_80 V_81 ;
struct V_52 V_53 ;
F_25 ( L_9 ) ;
V_197 = F_57 ( V_51 -> V_198 -> V_192 ) ;
V_8 = F_37 ( V_51 -> V_58 ) ;
if ( V_195 -> V_199 )
return F_29 ( - V_85 ) ;
V_20 = F_58 ( & V_81 , V_6 , sizeof( V_81 ) ) ;
if ( V_20 ) {
F_4 ( L_13 ,
V_8 -> V_48 . V_49 ) ;
return F_29 ( - V_85 ) ;
}
V_20 = F_34 ( V_81 ) ;
if ( V_20 ) {
F_4 ( L_14 ,
V_8 -> V_48 . V_49 ) ;
return F_29 ( - V_85 ) ;
}
if ( V_195 -> V_184 != V_185 ) {
F_4 ( L_15 ,
V_8 -> V_48 . V_49 , V_195 -> V_184 ) ;
return F_29 ( - V_85 ) ;
}
V_53 = V_81 . V_82 ;
F_38 ( & V_8 -> V_62 ) ;
V_42 = ( V_195 -> V_200 == V_195 -> V_201 ) ? 1 : 2 ;
V_55 = V_202 [ V_53 . V_47 ] ;
F_59 ( & V_55 , V_41 , V_42 ) ;
V_4 = F_15 ( V_8 , F_55 ( V_51 ) ,
& V_53 ,
& V_55 ) ;
if ( F_9 ( V_4 ) ) {
V_20 = V_4 ? F_11 ( V_4 ) : - V_32 ;
goto V_203;
}
V_20 = F_2 ( V_4 , V_6 ) ;
if ( V_20 ) {
V_20 = - V_204 ;
goto V_205;
}
V_4 -> V_206 = V_197 ;
F_60 ( & V_4 -> V_45 , & V_197 -> V_207 ) ;
F_61 ( V_4 -> V_21 ) ;
F_42 ( & V_8 -> V_62 ) ;
return & V_4 -> V_183 ;
V_205:
F_31 ( V_4 ) ;
V_203:
F_42 ( & V_8 -> V_62 ) ;
return F_29 ( V_20 ) ;
}
int F_62 ( struct V_174 * V_175 )
{
struct V_3 * V_4 ;
struct V_56 * V_21 ;
F_25 ( L_9 ) ;
V_4 = F_46 ( V_175 ) ;
V_21 = V_4 -> V_21 ;
F_38 ( & V_21 -> V_22 -> V_62 ) ;
if ( F_63 ( V_4 , V_70 , NULL ) ) {
F_4 ( L_16 ,
V_4 -> V_24 ) ;
}
F_64 ( & V_4 -> V_45 ) ;
F_31 ( V_4 ) ;
F_42 ( & V_21 -> V_22 -> V_62 ) ;
return 0 ;
}
int F_65 ( struct V_174 * V_183 , struct V_176 * V_208 ,
int V_209 , struct V_5 * V_6 )
{
struct V_3 * V_4 ;
int V_210 ;
F_25 ( L_9 ) ;
V_4 = F_46 ( V_183 ) ;
F_38 ( & V_4 -> V_21 -> V_22 -> V_62 ) ;
if ( ( V_209 & V_211 ) && V_208 -> V_181 == V_212 ) {
V_210 = F_63 ( V_4 , V_212 , NULL ) ;
} else if ( ( V_209 & V_211 ) && V_208 -> V_181 == V_213 ) {
V_210 = F_63 ( V_4 , V_213 , NULL ) ;
} else if ( ( V_209 & V_211 ) && V_208 -> V_181 == V_214 ) {
V_210 = F_63 ( V_4 , V_214 , NULL ) ;
} else {
F_4 ( L_17 ,
V_209 & V_211 , V_208 -> V_181 ) ;
V_210 = - V_85 ;
}
F_42 ( & V_4 -> V_21 -> V_22 -> V_62 ) ;
return V_210 ;
}
struct V_215 * F_66 ( struct V_87 * V_90 ,
const struct V_216 * V_208 ,
struct V_191 * V_192 ,
struct V_5 * V_6 )
{
struct V_215 * V_217 ;
F_25 ( L_9 ) ;
if ( V_208 -> V_218 )
return F_29 ( - V_85 ) ;
V_217 = F_50 ( sizeof( * V_217 ) , V_193 ) ;
if ( ! V_217 )
return F_29 ( - V_204 ) ;
return V_217 ;
}
int F_67 ( struct V_215 * V_217 )
{
F_25 ( L_9 ) ;
F_52 ( V_217 ) ;
return 0 ;
}
struct V_219 * F_68 ( struct V_190 * V_51 , T_1 V_220 , T_1 V_221 ,
T_1 V_222 , int V_223 ,
struct V_5 * V_6 )
{
struct V_224 * V_225 ;
int V_20 ;
F_25 ( L_18 , V_220 ,
V_222 , V_221 ) ;
V_225 = F_50 ( sizeof( * V_225 ) , V_193 ) ;
if ( F_9 ( V_225 ) )
return F_29 ( V_225 ? F_11 ( V_225 ) : - V_32 ) ;
V_225 -> V_226 = F_69 ( F_55 ( V_51 ) -> V_65 , V_220 , V_221 ,
V_223 , 0 ) ;
if ( F_9 ( V_225 -> V_226 ) ) {
V_20 = V_225 -> V_226 ? F_11 ( V_225 -> V_226 ) : - V_25 ;
goto V_227;
}
V_225 -> V_228 . V_229 = V_225 -> V_228 . V_230 = 0 ;
return & V_225 -> V_228 ;
V_227:
F_52 ( V_225 ) ;
return F_29 ( V_20 ) ;
}
int F_70 ( struct V_219 * V_228 )
{
struct V_224 * V_225 = F_71 ( V_228 ) ;
F_25 ( L_19 , V_225 -> V_226 -> V_231 , V_225 -> V_226 -> V_221 ) ;
F_72 ( V_225 -> V_226 , V_228 -> V_51 -> V_198 -> V_192 -> V_232 ) ;
F_52 ( V_225 ) ;
return 0 ;
}
struct V_191 * F_73 ( struct V_87 * V_90 ,
struct V_5 * V_6 )
{
struct V_196 * V_192 ;
struct V_7 * V_8 = F_37 ( V_90 ) ;
F_25 ( L_9 ) ;
V_192 = F_74 ( sizeof( * V_192 ) , V_193 ) ;
if ( ! V_192 )
return F_29 ( - V_32 ) ;
F_75 ( & V_192 -> V_207 ) ;
F_38 ( & V_8 -> V_62 ) ;
F_60 ( & V_192 -> V_45 , & V_8 -> V_233 ) ;
F_42 ( & V_8 -> V_62 ) ;
return & V_192 -> V_234 ;
}
int F_76 ( struct V_191 * V_235 )
{
struct V_196 * V_192 = F_57 ( V_235 ) ;
struct V_7 * V_8 = F_37 ( V_235 -> V_58 ) ;
F_25 ( L_9 ) ;
F_38 ( & V_8 -> V_62 ) ;
F_16 ( ! F_18 ( & V_192 -> V_207 ) ) ;
F_64 ( & V_192 -> V_45 ) ;
F_42 ( & V_8 -> V_62 ) ;
F_52 ( V_192 ) ;
return 0 ;
}
int F_77 ( struct V_191 * V_192 ,
struct V_236 * V_237 )
{
struct V_196 * V_238 = F_78 ( V_192 ) ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_56 * V_21 ;
struct V_13 * V_14 ;
T_4 V_28 ;
unsigned int V_30 ;
unsigned int V_26 ;
F_25 ( L_9 ) ;
V_8 = F_37 ( V_192 -> V_58 ) ;
V_237 -> V_239 |= V_240 ;
V_237 -> V_241 = F_79 ( V_237 -> V_241 ) ;
V_26 = V_237 -> V_242 ;
F_25 ( L_20 ,
V_237 -> V_242 , V_243 , V_26 ) ;
F_38 ( & V_8 -> V_62 ) ;
F_28 (qp_grp, &uctx->qp_grp_list, link) {
V_21 = V_4 -> V_21 ;
if ( F_7 ( V_21 -> V_23 ) == V_26 ) {
V_14 = F_5 ( V_21 -> V_23 , 0 ) ;
if ( ( V_237 -> V_244 - V_237 -> V_245 ) != V_14 -> V_30 ) {
F_4 ( L_21 ,
V_14 -> V_30 ,
V_237 -> V_244 - V_237 -> V_245 ) ;
F_42 ( & V_8 -> V_62 ) ;
return - V_85 ;
}
V_28 = V_14 -> V_28 ;
V_30 = V_14 -> V_30 ;
F_25 ( L_22 ,
& V_28 , V_14 -> V_246 , V_14 -> V_30 ) ;
F_42 ( & V_8 -> V_62 ) ;
return F_80 ( V_237 ,
V_237 -> V_245 ,
V_28 >> V_243 ,
V_30 , V_237 -> V_241 ) ;
}
}
F_42 ( & V_8 -> V_62 ) ;
F_4 ( L_23 , V_26 ) ;
return - V_85 ;
}
struct V_247 * F_81 ( struct V_190 * V_51 ,
struct V_248 * V_249 )
{
F_25 ( L_9 ) ;
return F_29 ( - V_250 ) ;
}
int F_82 ( struct V_247 * V_251 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_83 ( struct V_174 * V_183 , struct V_252 * V_253 ,
struct V_252 * * V_254 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_84 ( struct V_174 * V_183 , struct V_255 * V_253 ,
struct V_255 * * V_254 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_85 ( struct V_215 * V_256 , int V_257 ,
struct V_258 * V_259 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_86 ( struct V_215 * V_217 ,
enum V_260 V_218 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
struct V_219 * F_87 ( struct V_190 * V_51 , int V_261 )
{
F_25 ( L_9 ) ;
return F_29 ( - V_32 ) ;
}
