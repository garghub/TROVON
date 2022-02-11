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
for ( V_19 = 0 ; V_59 [ V_19 ] ; V_19 ++ ) {
V_58 = V_59 [ V_19 ] ;
V_21 = F_21 ( F_22 ( V_58 ) ) ;
F_23 ( & V_21 -> V_64 ) ;
V_23 = V_21 -> V_23 ;
if ( ! F_24 ( V_23 , V_54 ) ) {
F_25 ( L_6 ,
V_8 -> V_47 . V_48 ,
F_6 ( F_3 (
V_23 ) ) ) ;
V_4 = F_26 ( V_8 -> V_65 ,
V_21 , V_50 ,
V_54 ,
V_52 ) ;
F_27 ( & V_21 -> V_64 ) ;
goto V_66;
}
F_27 ( & V_21 -> V_64 ) ;
}
F_28 ( V_59 ) ;
}
F_29 (vf, &us_ibdev->vf_dev_list, link) {
F_23 ( & V_21 -> V_64 ) ;
V_23 = V_21 -> V_23 ;
if ( V_21 -> V_67 == 0 &&
F_24 ( V_23 , V_54 ) == 0 ) {
V_4 = F_26 ( V_8 -> V_65 , V_21 ,
V_50 , V_54 ,
V_52 ) ;
F_27 ( & V_21 -> V_64 ) ;
goto V_66;
}
F_27 ( & V_21 -> V_64 ) ;
}
F_19 ( L_7 , V_8 -> V_47 . V_48 ) ;
return F_30 ( - V_68 ) ;
V_66:
if ( F_31 ( V_4 ) ) {
F_4 ( L_8 ) ;
return F_30 ( V_4 ? F_11 ( V_4 ) : - V_68 ) ;
}
return V_4 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_55 * V_21 = V_4 -> V_21 ;
F_12 ( V_4 -> V_69 != V_70 ) ;
F_23 ( & V_21 -> V_64 ) ;
F_33 ( V_4 ) ;
F_27 ( & V_21 -> V_64 ) ;
}
static void F_34 ( int V_71 , T_2 * V_72 ,
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
static int F_35 ( struct V_80 V_81 )
{
if ( V_81 . V_82 . V_46 <= V_83 ||
V_81 . V_82 . V_46 >= V_84 )
return - V_85 ;
return 0 ;
}
enum V_86 F_36 ( struct V_87 * V_57 ,
T_2 V_88 )
{
return V_89 ;
}
int F_37 ( struct V_87 * V_90 ,
struct V_91 * V_92 ,
struct V_5 * V_93 )
{
struct V_7 * V_8 = F_38 ( V_90 ) ;
union V_94 V_95 ;
struct V_96 V_97 ;
int V_98 ;
F_25 ( L_9 ) ;
if ( V_93 -> V_99 || V_93 -> V_100 )
return - V_85 ;
F_39 ( & V_8 -> V_60 ) ;
V_8 -> V_101 -> V_102 -> V_103 ( V_8 -> V_101 , & V_97 ) ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
F_40 ( V_8 -> V_65 -> V_104 , V_8 -> V_65 -> V_105 ,
& V_95 . V_106 [ 0 ] ) ;
memcpy ( & V_92 -> V_107 , & V_95 . V_108 . V_109 ,
sizeof( V_95 . V_108 . V_109 ) ) ;
F_1 ( & V_97 . V_110 [ 0 ] , & V_92 -> V_2 ) ;
V_92 -> V_111 = V_112 ;
V_92 -> V_113 = V_114 ;
V_92 -> V_115 = V_116 ;
V_92 -> V_117 = V_118 ;
V_92 -> V_119 = V_8 -> V_12 -> V_120 ;
V_98 = F_41 ( V_8 -> V_121 [ V_37 ] ,
V_8 -> V_121 [ V_31 ] ) ;
V_92 -> V_122 = V_98 *
F_42 ( & V_8 -> V_123 ) ;
V_92 -> V_124 = V_125 |
V_126 | V_127 ;
V_92 -> V_128 = V_8 -> V_121 [ V_40 ] *
F_42 ( & V_8 -> V_123 ) ;
V_92 -> V_129 = V_130 ;
V_92 -> V_131 = V_132 ;
V_92 -> V_133 = 0 ;
V_92 -> V_134 = 0 ;
V_92 -> V_135 = V_136 ;
V_92 -> V_137 = V_92 -> V_135 ;
V_92 -> V_138 = 0 ;
V_92 -> V_139 = 0 ;
V_92 -> V_140 = 0 ;
V_92 -> V_141 = 0 ;
V_92 -> V_142 = 0 ;
V_92 -> V_143 = 0 ;
V_92 -> V_144 = 0 ;
V_92 -> V_145 = 0 ;
V_92 -> V_146 = 0 ;
V_92 -> V_147 = 0 ;
V_92 -> V_148 = 0 ;
F_43 ( & V_8 -> V_60 ) ;
return 0 ;
}
int F_44 ( struct V_87 * V_90 , T_2 V_149 ,
struct V_150 * V_92 )
{
struct V_7 * V_8 = F_38 ( V_90 ) ;
struct V_151 V_81 ;
F_25 ( L_9 ) ;
F_39 ( & V_8 -> V_60 ) ;
F_45 ( V_8 -> V_101 , & V_81 ) ;
V_92 -> V_152 = 0 ;
V_92 -> V_153 = 1 ;
V_92 -> V_154 = 0 ;
V_92 -> V_155 = 0 ;
if ( ! V_8 -> V_65 -> V_156 ) {
V_92 -> V_69 = V_157 ;
V_92 -> V_158 = 3 ;
} else if ( ! V_8 -> V_65 -> V_105 ) {
V_92 -> V_69 = V_159 ;
V_92 -> V_158 = 4 ;
} else {
V_92 -> V_69 = V_160 ;
V_92 -> V_158 = 5 ;
}
V_92 -> V_161 = 0 ;
V_92 -> V_162 = 1 ;
V_92 -> V_163 = 1 ;
V_92 -> V_164 = 0 ;
V_92 -> V_165 = 0 ;
F_34 ( V_81 . V_166 . V_71 , & V_92 -> V_72 ,
& V_92 -> V_73 ) ;
V_92 -> V_167 = V_168 ;
V_92 -> V_169 = F_46 ( V_8 -> V_65 -> V_170 ) ;
V_92 -> V_171 = V_8 -> V_65 -> V_170 ;
V_92 -> V_172 = 1 ;
F_43 ( & V_8 -> V_60 ) ;
return 0 ;
}
int F_47 ( struct V_173 * V_174 , struct V_175 * V_176 ,
int V_177 ,
struct V_178 * V_179 )
{
struct V_3 * V_4 ;
struct V_55 * V_21 ;
int V_20 ;
F_25 ( L_9 ) ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
V_4 = F_48 ( V_174 ) ;
V_21 = V_4 -> V_21 ;
F_39 ( & V_21 -> V_22 -> V_60 ) ;
F_25 ( L_9 ) ;
V_176 -> V_180 = V_4 -> V_69 ;
V_176 -> V_181 = V_4 -> V_69 ;
switch ( V_4 -> V_182 . V_183 ) {
case V_184 :
V_176 -> V_185 = 0 ;
break;
default:
F_4 ( L_10 , V_4 -> V_182 . V_183 ) ;
V_20 = - V_85 ;
goto V_186;
}
F_43 ( & V_21 -> V_22 -> V_60 ) ;
return 0 ;
V_186:
F_43 ( & V_21 -> V_22 -> V_60 ) ;
return V_20 ;
}
int F_49 ( struct V_87 * V_90 , T_2 V_149 , int V_187 ,
union V_94 * V_95 )
{
struct V_7 * V_8 = F_38 ( V_90 ) ;
F_25 ( L_9 ) ;
if ( V_187 > 1 )
return - V_85 ;
F_39 ( & V_8 -> V_60 ) ;
memset ( & ( V_95 -> V_106 [ 0 ] ) , 0 , sizeof( V_95 -> V_106 ) ) ;
F_40 ( V_8 -> V_65 -> V_104 , V_8 -> V_65 -> V_105 ,
& V_95 -> V_106 [ 0 ] ) ;
F_43 ( & V_8 -> V_60 ) ;
return 0 ;
}
int F_50 ( struct V_87 * V_90 , T_2 V_149 , T_3 V_187 ,
T_3 * V_188 )
{
if ( V_187 > 1 )
return - V_85 ;
* V_188 = 0xffff ;
return 0 ;
}
struct V_189 * F_51 ( struct V_87 * V_90 ,
struct V_190 * V_191 ,
struct V_5 * V_6 )
{
struct V_49 * V_50 ;
void * V_63 ;
F_25 ( L_9 ) ;
V_50 = F_52 ( sizeof( * V_50 ) , V_192 ) ;
if ( ! V_50 )
return F_30 ( - V_68 ) ;
V_63 = V_50 -> V_63 = F_53 () ;
if ( F_31 ( V_63 ) ) {
F_54 ( V_50 ) ;
return F_30 ( V_63 ? F_11 ( V_63 ) : - V_68 ) ;
}
F_19 ( L_11 ,
V_50 , V_191 , V_90 -> V_48 ) ;
return & V_50 -> V_193 ;
}
int F_55 ( struct V_189 * V_50 )
{
F_19 ( L_12 , V_50 ) ;
F_56 ( ( F_57 ( V_50 ) ) -> V_63 ) ;
F_54 ( V_50 ) ;
return 0 ;
}
struct V_173 * F_58 ( struct V_189 * V_50 ,
struct V_178 * V_194 ,
struct V_5 * V_6 )
{
int V_20 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_195 * V_196 ;
int V_41 ;
struct V_53 V_54 ;
struct V_80 V_81 ;
struct V_51 V_52 ;
F_25 ( L_9 ) ;
V_196 = F_59 ( V_50 -> V_197 -> V_191 ) ;
V_8 = F_38 ( V_50 -> V_57 ) ;
if ( V_194 -> V_198 )
return F_30 ( - V_85 ) ;
V_20 = F_60 ( & V_81 , V_6 , sizeof( V_81 ) ) ;
if ( V_20 ) {
F_4 ( L_13 ,
V_8 -> V_47 . V_48 ) ;
return F_30 ( - V_85 ) ;
}
V_20 = F_35 ( V_81 ) ;
if ( V_20 ) {
F_4 ( L_14 ,
V_8 -> V_47 . V_48 ) ;
return F_30 ( - V_85 ) ;
}
if ( V_194 -> V_183 != V_184 ) {
F_4 ( L_15 ,
V_8 -> V_47 . V_48 , V_194 -> V_183 ) ;
return F_30 ( - V_85 ) ;
}
V_52 = V_81 . V_82 ;
F_39 ( & V_8 -> V_60 ) ;
V_41 = ( V_194 -> V_199 == V_194 -> V_200 ) ? 1 : 2 ;
V_54 = V_201 [ V_52 . V_46 ] ;
F_61 ( & V_54 , V_40 , V_41 ) ;
V_4 = F_15 ( V_8 , F_57 ( V_50 ) ,
& V_52 ,
& V_54 ) ;
if ( F_31 ( V_4 ) ) {
V_20 = V_4 ? F_11 ( V_4 ) : - V_68 ;
goto V_202;
}
V_20 = F_2 ( V_4 , V_6 ) ;
if ( V_20 ) {
V_20 = - V_203 ;
goto V_204;
}
V_4 -> V_205 = V_196 ;
F_62 ( & V_4 -> V_44 , & V_196 -> V_206 ) ;
F_63 ( V_4 -> V_21 ) ;
F_43 ( & V_8 -> V_60 ) ;
return & V_4 -> V_182 ;
V_204:
F_32 ( V_4 ) ;
V_202:
F_43 ( & V_8 -> V_60 ) ;
return F_30 ( V_20 ) ;
}
int F_64 ( struct V_173 * V_174 )
{
struct V_3 * V_4 ;
struct V_55 * V_21 ;
F_25 ( L_9 ) ;
V_4 = F_48 ( V_174 ) ;
V_21 = V_4 -> V_21 ;
F_39 ( & V_21 -> V_22 -> V_60 ) ;
if ( F_65 ( V_4 , V_70 , NULL ) ) {
F_4 ( L_16 ,
V_4 -> V_24 ) ;
}
F_66 ( & V_4 -> V_44 ) ;
F_32 ( V_4 ) ;
F_43 ( & V_21 -> V_22 -> V_60 ) ;
return 0 ;
}
int F_67 ( struct V_173 * V_182 , struct V_175 * V_207 ,
int V_208 , struct V_5 * V_6 )
{
struct V_3 * V_4 ;
int V_209 ;
F_25 ( L_9 ) ;
V_4 = F_48 ( V_182 ) ;
F_39 ( & V_4 -> V_21 -> V_22 -> V_60 ) ;
if ( ( V_208 & V_210 ) && V_207 -> V_88 != 1 ) {
V_209 = - V_85 ;
goto V_211;
}
if ( V_208 & V_212 ) {
V_209 = F_65 ( V_4 , V_207 -> V_180 , NULL ) ;
} else {
F_4 ( L_17 , V_208 ) ;
V_209 = - V_85 ;
}
V_211:
F_43 ( & V_4 -> V_21 -> V_22 -> V_60 ) ;
return V_209 ;
}
struct V_213 * F_68 ( struct V_87 * V_90 ,
const struct V_214 * V_207 ,
struct V_190 * V_191 ,
struct V_5 * V_6 )
{
struct V_213 * V_215 ;
F_25 ( L_9 ) ;
if ( V_207 -> V_216 )
return F_30 ( - V_85 ) ;
V_215 = F_52 ( sizeof( * V_215 ) , V_192 ) ;
if ( ! V_215 )
return F_30 ( - V_203 ) ;
return V_215 ;
}
int F_69 ( struct V_213 * V_215 )
{
F_25 ( L_9 ) ;
F_54 ( V_215 ) ;
return 0 ;
}
struct V_217 * F_70 ( struct V_189 * V_50 , T_1 V_218 , T_1 V_219 ,
T_1 V_220 , int V_221 ,
struct V_5 * V_6 )
{
struct V_222 * V_223 ;
int V_20 ;
F_25 ( L_18 , V_218 ,
V_220 , V_219 ) ;
V_223 = F_52 ( sizeof( * V_223 ) , V_192 ) ;
if ( ! V_223 )
return F_30 ( - V_68 ) ;
V_223 -> V_224 = F_71 ( F_57 ( V_50 ) -> V_63 , V_218 , V_219 ,
V_221 , 0 ) ;
if ( F_31 ( V_223 -> V_224 ) ) {
V_20 = V_223 -> V_224 ? F_11 ( V_223 -> V_224 ) : - V_25 ;
goto V_225;
}
V_223 -> V_226 . V_227 = V_223 -> V_226 . V_228 = 0 ;
return & V_223 -> V_226 ;
V_225:
F_54 ( V_223 ) ;
return F_30 ( V_20 ) ;
}
int F_72 ( struct V_217 * V_226 )
{
struct V_222 * V_223 = F_73 ( V_226 ) ;
F_25 ( L_19 , V_223 -> V_224 -> V_229 , V_223 -> V_224 -> V_219 ) ;
F_74 ( V_223 -> V_224 , V_226 -> V_50 -> V_197 -> V_191 -> V_230 ) ;
F_54 ( V_223 ) ;
return 0 ;
}
struct V_190 * F_75 ( struct V_87 * V_90 ,
struct V_5 * V_6 )
{
struct V_195 * V_191 ;
struct V_7 * V_8 = F_38 ( V_90 ) ;
F_25 ( L_9 ) ;
V_191 = F_76 ( sizeof( * V_191 ) , V_192 ) ;
if ( ! V_191 )
return F_30 ( - V_68 ) ;
F_77 ( & V_191 -> V_206 ) ;
F_39 ( & V_8 -> V_60 ) ;
F_62 ( & V_191 -> V_44 , & V_8 -> V_231 ) ;
F_43 ( & V_8 -> V_60 ) ;
return & V_191 -> V_232 ;
}
int F_78 ( struct V_190 * V_233 )
{
struct V_195 * V_191 = F_59 ( V_233 ) ;
struct V_7 * V_8 = F_38 ( V_233 -> V_57 ) ;
F_25 ( L_9 ) ;
F_39 ( & V_8 -> V_60 ) ;
F_16 ( ! F_18 ( & V_191 -> V_206 ) ) ;
F_66 ( & V_191 -> V_44 ) ;
F_43 ( & V_8 -> V_60 ) ;
F_54 ( V_191 ) ;
return 0 ;
}
int F_79 ( struct V_190 * V_191 ,
struct V_234 * V_235 )
{
struct V_195 * V_236 = F_80 ( V_191 ) ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_55 * V_21 ;
struct V_13 * V_14 ;
T_4 V_28 ;
unsigned int V_30 ;
unsigned int V_26 ;
F_25 ( L_9 ) ;
V_8 = F_38 ( V_191 -> V_57 ) ;
V_235 -> V_237 |= V_238 ;
V_235 -> V_239 = F_81 ( V_235 -> V_239 ) ;
V_26 = V_235 -> V_240 ;
F_25 ( L_20 ,
V_235 -> V_240 , V_241 , V_26 ) ;
F_39 ( & V_8 -> V_60 ) ;
F_29 (qp_grp, &uctx->qp_grp_list, link) {
V_21 = V_4 -> V_21 ;
if ( F_7 ( V_21 -> V_23 ) == V_26 ) {
V_14 = F_5 ( V_21 -> V_23 , 0 ) ;
if ( ( V_235 -> V_242 - V_235 -> V_243 ) != V_14 -> V_30 ) {
F_4 ( L_21 ,
V_14 -> V_30 ,
V_235 -> V_242 - V_235 -> V_243 ) ;
F_43 ( & V_8 -> V_60 ) ;
return - V_85 ;
}
V_28 = V_14 -> V_28 ;
V_30 = V_14 -> V_30 ;
F_25 ( L_22 ,
& V_28 , V_14 -> V_244 , V_14 -> V_30 ) ;
F_43 ( & V_8 -> V_60 ) ;
return F_82 ( V_235 ,
V_235 -> V_243 ,
V_28 >> V_241 ,
V_30 , V_235 -> V_239 ) ;
}
}
F_43 ( & V_8 -> V_60 ) ;
F_4 ( L_23 , V_26 ) ;
return - V_85 ;
}
struct V_245 * F_83 ( struct V_189 * V_50 ,
struct V_246 * V_247 ,
struct V_5 * V_6 )
{
F_25 ( L_9 ) ;
return F_30 ( - V_248 ) ;
}
int F_84 ( struct V_245 * V_249 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_85 ( struct V_173 * V_182 , struct V_250 * V_251 ,
struct V_250 * * V_252 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_86 ( struct V_173 * V_182 , struct V_253 * V_251 ,
struct V_253 * * V_252 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_87 ( struct V_213 * V_254 , int V_255 ,
struct V_256 * V_257 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_88 ( struct V_213 * V_215 ,
enum V_258 V_216 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
struct V_217 * F_89 ( struct V_189 * V_50 , int V_259 )
{
F_25 ( L_9 ) ;
return F_30 ( - V_68 ) ;
}
