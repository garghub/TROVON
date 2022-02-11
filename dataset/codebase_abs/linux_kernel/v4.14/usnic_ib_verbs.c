static void F_1 ( char * V_1 , T_1 * V_2 )
{
* V_2 = * ( ( T_1 * ) V_1 ) ;
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
return F_11 ( V_16 ) ;
}
F_12 ( V_16 -> type != V_31 ) ;
V_10 . V_32 = V_16 -> V_33 ;
for ( V_19 = 0 ; V_19 < V_16 -> V_33 ; V_19 ++ )
V_10 . V_34 [ V_19 ] = V_16 -> V_35 [ V_19 ] -> V_36 ;
V_16 = F_8 ( V_4 , V_37 ) ;
if ( F_9 ( V_16 ) ) {
F_4 ( L_3 ,
F_10 ( V_37 ) ,
V_4 -> V_24 ,
F_11 ( V_16 ) ) ;
return F_11 ( V_16 ) ;
}
F_12 ( V_16 -> type != V_37 ) ;
V_10 . V_38 = V_16 -> V_33 ;
for ( V_19 = 0 ; V_19 < V_16 -> V_33 ; V_19 ++ )
V_10 . V_39 [ V_19 ] = V_16 -> V_35 [ V_19 ] -> V_36 ;
V_16 = F_8 ( V_4 , V_40 ) ;
if ( F_9 ( V_16 ) ) {
F_4 ( L_3 ,
F_10 ( V_40 ) ,
V_4 -> V_24 ,
F_11 ( V_16 ) ) ;
return F_11 ( V_16 ) ;
}
F_12 ( V_16 -> type != V_40 ) ;
V_10 . V_41 = V_16 -> V_33 ;
for ( V_19 = 0 ; V_19 < V_16 -> V_33 ; V_19 ++ )
V_10 . V_42 [ V_19 ] = V_16 -> V_35 [ V_19 ] -> V_36 ;
V_18 = F_13 ( & V_4 -> V_43 ,
struct V_17 , V_44 ) ;
V_10 . V_45 = V_18 -> V_46 ;
V_20 = F_14 ( V_6 , & V_10 , sizeof( V_10 ) ) ;
if ( V_20 ) {
F_4 ( L_4 , V_8 -> V_47 . V_48 ) ;
return V_20 ;
}
return 0 ;
}
static struct V_3 *
F_15 ( struct V_7 * V_8 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_21 ;
struct V_56 * V_23 ;
struct V_3 * V_4 ;
struct V_57 * V_58 , * * V_59 ;
int V_19 ;
F_16 ( ! F_17 ( & V_8 -> V_60 ) ) ;
if ( F_18 ( & V_8 -> V_61 ) ) {
F_19 ( L_5 ) ;
return NULL ;
}
if ( V_62 ) {
V_59 = F_20 ( V_50 -> V_63 ) ;
if ( F_9 ( V_59 ) )
return F_21 ( V_59 ) ;
for ( V_19 = 0 ; V_59 [ V_19 ] ; V_19 ++ ) {
V_58 = V_59 [ V_19 ] ;
V_21 = F_22 ( F_23 ( V_58 ) ) ;
F_24 ( & V_21 -> V_64 ) ;
V_23 = V_21 -> V_23 ;
if ( ! F_25 ( V_23 , V_54 ) ) {
F_26 ( L_6 ,
V_8 -> V_47 . V_48 ,
F_6 ( F_3 (
V_23 ) ) ) ;
V_4 = F_27 ( V_8 -> V_65 ,
V_21 , V_50 ,
V_54 ,
V_52 ) ;
F_28 ( & V_21 -> V_64 ) ;
goto V_66;
}
F_28 ( & V_21 -> V_64 ) ;
}
F_29 ( V_59 ) ;
}
F_30 (vf, &us_ibdev->vf_dev_list, link) {
F_24 ( & V_21 -> V_64 ) ;
V_23 = V_21 -> V_23 ;
if ( V_21 -> V_67 == 0 &&
F_25 ( V_23 , V_54 ) == 0 ) {
V_4 = F_27 ( V_8 -> V_65 , V_21 ,
V_50 , V_54 ,
V_52 ) ;
F_28 ( & V_21 -> V_64 ) ;
goto V_66;
}
F_28 ( & V_21 -> V_64 ) ;
}
F_19 ( L_7 , V_8 -> V_47 . V_48 ) ;
return F_31 ( - V_68 ) ;
V_66:
if ( F_32 ( V_4 ) ) {
F_4 ( L_8 ) ;
return F_31 ( V_4 ? F_11 ( V_4 ) : - V_68 ) ;
}
return V_4 ;
}
static void F_33 ( struct V_3 * V_4 )
{
struct V_55 * V_21 = V_4 -> V_21 ;
F_12 ( V_4 -> V_69 != V_70 ) ;
F_24 ( & V_21 -> V_64 ) ;
F_34 ( V_4 ) ;
F_28 ( & V_21 -> V_64 ) ;
}
static int F_35 ( struct V_71 V_72 )
{
if ( V_72 . V_73 . V_46 <= V_74 ||
V_72 . V_73 . V_46 >= V_75 )
return - V_76 ;
return 0 ;
}
enum V_77 F_36 ( struct V_78 * V_57 ,
T_2 V_79 )
{
return V_80 ;
}
int F_37 ( struct V_78 * V_81 ,
struct V_82 * V_83 ,
struct V_5 * V_84 )
{
struct V_7 * V_8 = F_38 ( V_81 ) ;
union V_85 V_86 ;
struct V_87 V_88 ;
int V_89 ;
F_26 ( L_9 ) ;
if ( V_84 -> V_90 || V_84 -> V_91 )
return - V_76 ;
F_39 ( & V_8 -> V_60 ) ;
V_8 -> V_92 -> V_93 -> V_94 ( V_8 -> V_92 , & V_88 ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
F_40 ( V_8 -> V_65 -> V_95 , V_8 -> V_65 -> V_96 ,
& V_86 . V_97 [ 0 ] ) ;
memcpy ( & V_83 -> V_98 , & V_86 . V_99 . V_100 ,
sizeof( V_86 . V_99 . V_100 ) ) ;
F_1 ( & V_88 . V_101 [ 0 ] , & V_83 -> V_2 ) ;
V_83 -> V_102 = V_103 ;
V_83 -> V_104 = V_105 ;
V_83 -> V_106 = V_107 ;
V_83 -> V_108 = V_109 ;
V_83 -> V_110 = V_8 -> V_12 -> V_111 ;
V_89 = F_41 ( V_8 -> V_112 [ V_37 ] ,
V_8 -> V_112 [ V_31 ] ) ;
V_83 -> V_113 = V_89 *
F_42 ( & V_8 -> V_114 ) ;
V_83 -> V_115 = V_116 |
V_117 | V_118 ;
V_83 -> V_119 = V_8 -> V_112 [ V_40 ] *
F_42 ( & V_8 -> V_114 ) ;
V_83 -> V_120 = V_121 ;
V_83 -> V_122 = V_123 ;
V_83 -> V_124 = 0 ;
V_83 -> V_125 = 0 ;
V_83 -> V_126 = V_127 ;
V_83 -> V_128 = V_83 -> V_126 ;
V_83 -> V_129 = 0 ;
V_83 -> V_130 = 0 ;
V_83 -> V_131 = 0 ;
V_83 -> V_132 = 0 ;
V_83 -> V_133 = 0 ;
V_83 -> V_134 = 0 ;
V_83 -> V_135 = 0 ;
V_83 -> V_136 = 0 ;
V_83 -> V_137 = 0 ;
V_83 -> V_138 = 0 ;
V_83 -> V_139 = 0 ;
F_43 ( & V_8 -> V_60 ) ;
return 0 ;
}
int F_44 ( struct V_78 * V_81 , T_2 V_140 ,
struct V_141 * V_83 )
{
struct V_7 * V_8 = F_38 ( V_81 ) ;
F_26 ( L_9 ) ;
F_39 ( & V_8 -> V_60 ) ;
if ( F_45 ( V_81 , V_140 , & V_83 -> V_142 ,
& V_83 -> V_143 ) ) {
F_43 ( & V_8 -> V_60 ) ;
return - V_76 ;
}
V_83 -> V_144 = 0 ;
V_83 -> V_145 = 1 ;
V_83 -> V_146 = 0 ;
V_83 -> V_147 = 0 ;
if ( ! V_8 -> V_65 -> V_148 ) {
V_83 -> V_69 = V_149 ;
V_83 -> V_150 = 3 ;
} else if ( ! V_8 -> V_65 -> V_96 ) {
V_83 -> V_69 = V_151 ;
V_83 -> V_150 = 4 ;
} else {
V_83 -> V_69 = V_152 ;
V_83 -> V_150 = 5 ;
}
V_83 -> V_153 = 0 ;
V_83 -> V_154 = 1 ;
V_83 -> V_155 = 1 ;
V_83 -> V_156 = 0 ;
V_83 -> V_157 = 0 ;
V_83 -> V_158 = V_159 ;
V_83 -> V_160 = F_46 ( V_8 -> V_65 -> V_161 ) ;
V_83 -> V_162 = V_8 -> V_65 -> V_161 ;
V_83 -> V_163 = 1 ;
F_43 ( & V_8 -> V_60 ) ;
return 0 ;
}
int F_47 ( struct V_164 * V_165 , struct V_166 * V_167 ,
int V_168 ,
struct V_169 * V_170 )
{
struct V_3 * V_4 ;
struct V_55 * V_21 ;
int V_20 ;
F_26 ( L_9 ) ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
V_4 = F_48 ( V_165 ) ;
V_21 = V_4 -> V_21 ;
F_39 ( & V_21 -> V_22 -> V_60 ) ;
F_26 ( L_9 ) ;
V_167 -> V_171 = V_4 -> V_69 ;
V_167 -> V_172 = V_4 -> V_69 ;
switch ( V_4 -> V_173 . V_174 ) {
case V_175 :
V_167 -> V_176 = 0 ;
break;
default:
F_4 ( L_10 , V_4 -> V_173 . V_174 ) ;
V_20 = - V_76 ;
goto V_177;
}
F_43 ( & V_21 -> V_22 -> V_60 ) ;
return 0 ;
V_177:
F_43 ( & V_21 -> V_22 -> V_60 ) ;
return V_20 ;
}
int F_49 ( struct V_78 * V_81 , T_2 V_140 , int V_178 ,
union V_85 * V_86 )
{
struct V_7 * V_8 = F_38 ( V_81 ) ;
F_26 ( L_9 ) ;
if ( V_178 > 1 )
return - V_76 ;
F_39 ( & V_8 -> V_60 ) ;
memset ( & ( V_86 -> V_97 [ 0 ] ) , 0 , sizeof( V_86 -> V_97 ) ) ;
F_40 ( V_8 -> V_65 -> V_95 , V_8 -> V_65 -> V_96 ,
& V_86 -> V_97 [ 0 ] ) ;
F_43 ( & V_8 -> V_60 ) ;
return 0 ;
}
struct V_179 * F_50 ( struct V_78 * V_57 , T_2 V_79 )
{
struct V_7 * V_8 = F_38 ( V_57 ) ;
if ( V_8 -> V_92 )
F_51 ( V_8 -> V_92 ) ;
return V_8 -> V_92 ;
}
int F_52 ( struct V_78 * V_81 , T_2 V_140 , T_3 V_178 ,
T_3 * V_180 )
{
if ( V_178 > 1 )
return - V_76 ;
* V_180 = 0xffff ;
return 0 ;
}
struct V_181 * F_53 ( struct V_78 * V_81 ,
struct V_182 * V_183 ,
struct V_5 * V_6 )
{
struct V_49 * V_50 ;
void * V_63 ;
F_26 ( L_9 ) ;
V_50 = F_54 ( sizeof( * V_50 ) , V_184 ) ;
if ( ! V_50 )
return F_31 ( - V_68 ) ;
V_63 = V_50 -> V_63 = F_55 () ;
if ( F_32 ( V_63 ) ) {
F_56 ( V_50 ) ;
return F_31 ( V_63 ? F_11 ( V_63 ) : - V_68 ) ;
}
F_19 ( L_11 ,
V_50 , V_183 , V_81 -> V_48 ) ;
return & V_50 -> V_185 ;
}
int F_57 ( struct V_181 * V_50 )
{
F_19 ( L_12 , V_50 ) ;
F_58 ( ( F_59 ( V_50 ) ) -> V_63 ) ;
F_56 ( V_50 ) ;
return 0 ;
}
struct V_164 * F_60 ( struct V_181 * V_50 ,
struct V_169 * V_186 ,
struct V_5 * V_6 )
{
int V_20 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_187 * V_188 ;
int V_41 ;
struct V_53 V_54 ;
struct V_71 V_72 ;
struct V_51 V_52 ;
F_26 ( L_9 ) ;
V_188 = F_61 ( V_50 -> V_189 -> V_183 ) ;
V_8 = F_38 ( V_50 -> V_57 ) ;
if ( V_186 -> V_190 )
return F_31 ( - V_76 ) ;
V_20 = F_62 ( & V_72 , V_6 , sizeof( V_72 ) ) ;
if ( V_20 ) {
F_4 ( L_13 ,
V_8 -> V_47 . V_48 ) ;
return F_31 ( - V_76 ) ;
}
V_20 = F_35 ( V_72 ) ;
if ( V_20 ) {
F_4 ( L_14 ,
V_8 -> V_47 . V_48 ) ;
return F_31 ( - V_76 ) ;
}
if ( V_186 -> V_174 != V_175 ) {
F_4 ( L_15 ,
V_8 -> V_47 . V_48 , V_186 -> V_174 ) ;
return F_31 ( - V_76 ) ;
}
V_52 = V_72 . V_73 ;
F_39 ( & V_8 -> V_60 ) ;
V_41 = ( V_186 -> V_191 == V_186 -> V_192 ) ? 1 : 2 ;
V_54 = V_193 [ V_52 . V_46 ] ;
F_63 ( & V_54 , V_40 , V_41 ) ;
V_4 = F_15 ( V_8 , F_59 ( V_50 ) ,
& V_52 ,
& V_54 ) ;
if ( F_32 ( V_4 ) ) {
V_20 = V_4 ? F_11 ( V_4 ) : - V_68 ;
goto V_194;
}
V_20 = F_2 ( V_4 , V_6 ) ;
if ( V_20 ) {
V_20 = - V_195 ;
goto V_196;
}
V_4 -> V_197 = V_188 ;
F_64 ( & V_4 -> V_44 , & V_188 -> V_198 ) ;
F_65 ( V_4 -> V_21 ) ;
F_43 ( & V_8 -> V_60 ) ;
return & V_4 -> V_173 ;
V_196:
F_33 ( V_4 ) ;
V_194:
F_43 ( & V_8 -> V_60 ) ;
return F_31 ( V_20 ) ;
}
int F_66 ( struct V_164 * V_165 )
{
struct V_3 * V_4 ;
struct V_55 * V_21 ;
F_26 ( L_9 ) ;
V_4 = F_48 ( V_165 ) ;
V_21 = V_4 -> V_21 ;
F_39 ( & V_21 -> V_22 -> V_60 ) ;
if ( F_67 ( V_4 , V_70 , NULL ) ) {
F_4 ( L_16 ,
V_4 -> V_24 ) ;
}
F_68 ( & V_4 -> V_44 ) ;
F_33 ( V_4 ) ;
F_43 ( & V_21 -> V_22 -> V_60 ) ;
return 0 ;
}
int F_69 ( struct V_164 * V_173 , struct V_166 * V_199 ,
int V_200 , struct V_5 * V_6 )
{
struct V_3 * V_4 ;
int V_201 ;
F_26 ( L_9 ) ;
V_4 = F_48 ( V_173 ) ;
F_39 ( & V_4 -> V_21 -> V_22 -> V_60 ) ;
if ( ( V_200 & V_202 ) && V_199 -> V_79 != 1 ) {
V_201 = - V_76 ;
goto V_203;
}
if ( V_200 & V_204 ) {
V_201 = F_67 ( V_4 , V_199 -> V_171 , NULL ) ;
} else {
F_4 ( L_17 , V_200 ) ;
V_201 = - V_76 ;
}
V_203:
F_43 ( & V_4 -> V_21 -> V_22 -> V_60 ) ;
return V_201 ;
}
struct V_205 * F_70 ( struct V_78 * V_81 ,
const struct V_206 * V_199 ,
struct V_182 * V_183 ,
struct V_5 * V_6 )
{
struct V_205 * V_207 ;
F_26 ( L_9 ) ;
if ( V_199 -> V_208 )
return F_31 ( - V_76 ) ;
V_207 = F_54 ( sizeof( * V_207 ) , V_184 ) ;
if ( ! V_207 )
return F_31 ( - V_195 ) ;
return V_207 ;
}
int F_71 ( struct V_205 * V_207 )
{
F_26 ( L_9 ) ;
F_56 ( V_207 ) ;
return 0 ;
}
struct V_209 * F_72 ( struct V_181 * V_50 , T_1 V_210 , T_1 V_211 ,
T_1 V_212 , int V_213 ,
struct V_5 * V_6 )
{
struct V_214 * V_215 ;
int V_20 ;
F_26 ( L_18 , V_210 ,
V_212 , V_211 ) ;
V_215 = F_54 ( sizeof( * V_215 ) , V_184 ) ;
if ( ! V_215 )
return F_31 ( - V_68 ) ;
V_215 -> V_216 = F_73 ( F_59 ( V_50 ) -> V_63 , V_210 , V_211 ,
V_213 , 0 ) ;
if ( F_32 ( V_215 -> V_216 ) ) {
V_20 = V_215 -> V_216 ? F_11 ( V_215 -> V_216 ) : - V_25 ;
goto V_217;
}
V_215 -> V_218 . V_219 = V_215 -> V_218 . V_220 = 0 ;
return & V_215 -> V_218 ;
V_217:
F_56 ( V_215 ) ;
return F_31 ( V_20 ) ;
}
int F_74 ( struct V_209 * V_218 )
{
struct V_214 * V_215 = F_75 ( V_218 ) ;
F_26 ( L_19 , V_215 -> V_216 -> V_221 , V_215 -> V_216 -> V_211 ) ;
F_76 ( V_215 -> V_216 , V_218 -> V_50 -> V_189 -> V_183 -> V_222 ) ;
F_56 ( V_215 ) ;
return 0 ;
}
struct V_182 * F_77 ( struct V_78 * V_81 ,
struct V_5 * V_6 )
{
struct V_187 * V_183 ;
struct V_7 * V_8 = F_38 ( V_81 ) ;
F_26 ( L_9 ) ;
V_183 = F_78 ( sizeof( * V_183 ) , V_184 ) ;
if ( ! V_183 )
return F_31 ( - V_68 ) ;
F_79 ( & V_183 -> V_198 ) ;
F_39 ( & V_8 -> V_60 ) ;
F_64 ( & V_183 -> V_44 , & V_8 -> V_223 ) ;
F_43 ( & V_8 -> V_60 ) ;
return & V_183 -> V_224 ;
}
int F_80 ( struct V_182 * V_225 )
{
struct V_187 * V_183 = F_61 ( V_225 ) ;
struct V_7 * V_8 = F_38 ( V_225 -> V_57 ) ;
F_26 ( L_9 ) ;
F_39 ( & V_8 -> V_60 ) ;
F_16 ( ! F_18 ( & V_183 -> V_198 ) ) ;
F_68 ( & V_183 -> V_44 ) ;
F_43 ( & V_8 -> V_60 ) ;
F_56 ( V_183 ) ;
return 0 ;
}
int F_81 ( struct V_182 * V_183 ,
struct V_226 * V_227 )
{
struct V_187 * V_228 = F_82 ( V_183 ) ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_55 * V_21 ;
struct V_13 * V_14 ;
T_4 V_28 ;
unsigned int V_30 ;
unsigned int V_26 ;
F_26 ( L_9 ) ;
V_8 = F_38 ( V_183 -> V_57 ) ;
V_227 -> V_229 |= V_230 ;
V_227 -> V_231 = F_83 ( V_227 -> V_231 ) ;
V_26 = V_227 -> V_232 ;
F_26 ( L_20 ,
V_227 -> V_232 , V_233 , V_26 ) ;
F_39 ( & V_8 -> V_60 ) ;
F_30 (qp_grp, &uctx->qp_grp_list, link) {
V_21 = V_4 -> V_21 ;
if ( F_7 ( V_21 -> V_23 ) == V_26 ) {
V_14 = F_5 ( V_21 -> V_23 , 0 ) ;
if ( ( V_227 -> V_234 - V_227 -> V_235 ) != V_14 -> V_30 ) {
F_4 ( L_21 ,
V_14 -> V_30 ,
V_227 -> V_234 - V_227 -> V_235 ) ;
F_43 ( & V_8 -> V_60 ) ;
return - V_76 ;
}
V_28 = V_14 -> V_28 ;
V_30 = V_14 -> V_30 ;
F_26 ( L_22 ,
& V_28 , V_14 -> V_236 , V_14 -> V_30 ) ;
F_43 ( & V_8 -> V_60 ) ;
return F_84 ( V_227 ,
V_227 -> V_235 ,
V_28 >> V_233 ,
V_30 , V_227 -> V_231 ) ;
}
}
F_43 ( & V_8 -> V_60 ) ;
F_4 ( L_23 , V_26 ) ;
return - V_76 ;
}
struct V_237 * F_85 ( struct V_181 * V_50 ,
struct V_238 * V_239 ,
struct V_5 * V_6 )
{
F_26 ( L_9 ) ;
return F_31 ( - V_240 ) ;
}
int F_86 ( struct V_237 * V_241 )
{
F_26 ( L_9 ) ;
return - V_76 ;
}
int F_87 ( struct V_164 * V_173 , struct V_242 * V_243 ,
struct V_242 * * V_244 )
{
F_26 ( L_9 ) ;
return - V_76 ;
}
int F_88 ( struct V_164 * V_173 , struct V_245 * V_243 ,
struct V_245 * * V_244 )
{
F_26 ( L_9 ) ;
return - V_76 ;
}
int F_89 ( struct V_205 * V_246 , int V_247 ,
struct V_248 * V_249 )
{
F_26 ( L_9 ) ;
return - V_76 ;
}
int F_90 ( struct V_205 * V_207 ,
enum V_250 V_208 )
{
F_26 ( L_9 ) ;
return - V_76 ;
}
struct V_209 * F_91 ( struct V_181 * V_50 , int V_251 )
{
F_26 ( L_9 ) ;
return F_31 ( - V_68 ) ;
}
