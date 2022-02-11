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
struct V_91 * V_92 )
{
struct V_7 * V_8 = F_37 ( V_90 ) ;
union V_93 V_94 ;
struct V_95 V_96 ;
struct V_97 V_81 ;
int V_98 ;
F_25 ( L_9 ) ;
F_38 ( & V_8 -> V_62 ) ;
V_8 -> V_99 -> V_100 -> V_101 ( V_8 -> V_99 , & V_96 ) ;
V_8 -> V_99 -> V_100 -> V_102 ( V_8 -> V_99 , & V_81 ) ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
F_39 ( V_8 -> V_68 -> V_103 , V_8 -> V_68 -> V_104 ,
& V_94 . V_105 [ 0 ] ) ;
memcpy ( & V_92 -> V_106 , & V_94 . V_107 . V_108 ,
sizeof( V_94 . V_107 . V_108 ) ) ;
F_1 ( & V_96 . V_109 [ 0 ] , & V_92 -> V_2 ) ;
V_92 -> V_110 = V_111 ;
V_92 -> V_112 = V_113 ;
V_92 -> V_114 = V_115 ;
V_92 -> V_116 = V_117 ;
V_92 -> V_118 = V_8 -> V_12 -> V_119 ;
V_98 = F_40 ( V_8 -> V_120 [ V_38 ] ,
V_8 -> V_120 [ V_31 ] ) ;
V_92 -> V_121 = V_98 *
F_41 ( & V_8 -> V_122 . V_123 ) ;
V_92 -> V_124 = V_125 |
V_126 | V_127 ;
V_92 -> V_128 = V_8 -> V_120 [ V_41 ] *
F_41 ( & V_8 -> V_122 . V_123 ) ;
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
F_42 ( & V_8 -> V_62 ) ;
return 0 ;
}
int F_43 ( struct V_87 * V_90 , T_2 V_149 ,
struct V_150 * V_92 )
{
struct V_7 * V_8 = F_37 ( V_90 ) ;
struct V_97 V_81 ;
F_25 ( L_9 ) ;
F_38 ( & V_8 -> V_62 ) ;
V_8 -> V_99 -> V_100 -> V_102 ( V_8 -> V_99 , & V_81 ) ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_92 -> V_151 = 0 ;
V_92 -> V_152 = 1 ;
V_92 -> V_153 = 0 ;
V_92 -> V_154 = 0 ;
if ( ! V_8 -> V_68 -> V_155 ) {
V_92 -> V_69 = V_156 ;
V_92 -> V_157 = 3 ;
} else if ( ! V_8 -> V_68 -> V_104 ) {
V_92 -> V_69 = V_158 ;
V_92 -> V_157 = 4 ;
} else {
V_92 -> V_69 = V_159 ;
V_92 -> V_157 = 5 ;
}
V_92 -> V_160 = 0 ;
V_92 -> V_161 = 1 ;
V_92 -> V_162 = 1 ;
V_92 -> V_163 = 0 ;
V_92 -> V_164 = 0 ;
F_33 ( V_81 . V_71 , & V_92 -> V_72 ,
& V_92 -> V_73 ) ;
V_92 -> V_165 = V_166 ;
V_92 -> V_167 = F_44 ( V_8 -> V_68 -> V_168 ) ;
V_92 -> V_169 = V_8 -> V_68 -> V_168 ;
V_92 -> V_170 = 1 ;
F_42 ( & V_8 -> V_62 ) ;
return 0 ;
}
int F_45 ( struct V_171 * V_172 , struct V_173 * V_174 ,
int V_175 ,
struct V_176 * V_177 )
{
struct V_3 * V_4 ;
struct V_56 * V_21 ;
int V_20 ;
F_25 ( L_9 ) ;
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
V_4 = F_46 ( V_172 ) ;
V_21 = V_4 -> V_21 ;
F_38 ( & V_21 -> V_22 -> V_62 ) ;
F_25 ( L_9 ) ;
V_174 -> V_178 = V_4 -> V_69 ;
V_174 -> V_179 = V_4 -> V_69 ;
switch ( V_4 -> V_180 . V_181 ) {
case V_182 :
V_174 -> V_183 = 0 ;
break;
default:
F_4 ( L_10 , V_4 -> V_180 . V_181 ) ;
V_20 = - V_85 ;
goto V_184;
}
F_42 ( & V_21 -> V_22 -> V_62 ) ;
return 0 ;
V_184:
F_42 ( & V_21 -> V_22 -> V_62 ) ;
return V_20 ;
}
int F_47 ( struct V_87 * V_90 , T_2 V_149 , int V_185 ,
union V_93 * V_94 )
{
struct V_7 * V_8 = F_37 ( V_90 ) ;
F_25 ( L_9 ) ;
if ( V_185 > 1 )
return - V_85 ;
F_38 ( & V_8 -> V_62 ) ;
memset ( & ( V_94 -> V_105 [ 0 ] ) , 0 , sizeof( V_94 -> V_105 ) ) ;
F_39 ( V_8 -> V_68 -> V_103 , V_8 -> V_68 -> V_104 ,
& V_94 -> V_105 [ 0 ] ) ;
F_42 ( & V_8 -> V_62 ) ;
return 0 ;
}
int F_48 ( struct V_87 * V_90 , T_2 V_149 , T_3 V_185 ,
T_3 * V_186 )
{
if ( V_185 > 1 )
return - V_85 ;
* V_186 = 0xffff ;
return 0 ;
}
struct V_187 * F_49 ( struct V_87 * V_90 ,
struct V_188 * V_189 ,
struct V_5 * V_6 )
{
struct V_50 * V_51 ;
void * V_65 ;
F_25 ( L_9 ) ;
V_51 = F_50 ( sizeof( * V_51 ) , V_190 ) ;
if ( ! V_51 )
return F_29 ( - V_32 ) ;
V_65 = V_51 -> V_65 = F_51 () ;
if ( F_9 ( V_65 ) ) {
F_52 ( V_51 ) ;
return F_29 ( V_65 ? F_11 ( V_65 ) : - V_32 ) ;
}
F_19 ( L_11 ,
V_51 , V_189 , V_90 -> V_49 ) ;
return & V_51 -> V_191 ;
}
int F_53 ( struct V_187 * V_51 )
{
F_19 ( L_12 , V_51 ) ;
F_54 ( ( F_55 ( V_51 ) ) -> V_65 ) ;
F_52 ( V_51 ) ;
return 0 ;
}
struct V_171 * F_56 ( struct V_187 * V_51 ,
struct V_176 * V_192 ,
struct V_5 * V_6 )
{
int V_20 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_193 * V_194 ;
int V_42 ;
struct V_54 V_55 ;
struct V_80 V_81 ;
struct V_52 V_53 ;
F_25 ( L_9 ) ;
V_194 = F_57 ( V_51 -> V_195 -> V_189 ) ;
V_8 = F_37 ( V_51 -> V_58 ) ;
if ( V_192 -> V_196 )
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
if ( V_192 -> V_181 != V_182 ) {
F_4 ( L_15 ,
V_8 -> V_48 . V_49 , V_192 -> V_181 ) ;
return F_29 ( - V_85 ) ;
}
V_53 = V_81 . V_82 ;
F_38 ( & V_8 -> V_62 ) ;
V_42 = ( V_192 -> V_197 == V_192 -> V_198 ) ? 1 : 2 ;
V_55 = V_199 [ V_53 . V_47 ] ;
F_59 ( & V_55 , V_41 , V_42 ) ;
V_4 = F_15 ( V_8 , F_55 ( V_51 ) ,
& V_53 ,
& V_55 ) ;
if ( F_9 ( V_4 ) ) {
V_20 = V_4 ? F_11 ( V_4 ) : - V_32 ;
goto V_200;
}
V_20 = F_2 ( V_4 , V_6 ) ;
if ( V_20 ) {
V_20 = - V_201 ;
goto V_202;
}
V_4 -> V_203 = V_194 ;
F_60 ( & V_4 -> V_45 , & V_194 -> V_204 ) ;
F_61 ( V_4 -> V_21 ) ;
F_42 ( & V_8 -> V_62 ) ;
return & V_4 -> V_180 ;
V_202:
F_31 ( V_4 ) ;
V_200:
F_42 ( & V_8 -> V_62 ) ;
return F_29 ( V_20 ) ;
}
int F_62 ( struct V_171 * V_172 )
{
struct V_3 * V_4 ;
struct V_56 * V_21 ;
F_25 ( L_9 ) ;
V_4 = F_46 ( V_172 ) ;
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
int F_65 ( struct V_171 * V_180 , struct V_173 * V_205 ,
int V_206 , struct V_5 * V_6 )
{
struct V_3 * V_4 ;
int V_207 ;
F_25 ( L_9 ) ;
V_4 = F_46 ( V_180 ) ;
F_38 ( & V_4 -> V_21 -> V_22 -> V_62 ) ;
if ( ( V_206 & V_208 ) && V_205 -> V_178 == V_209 ) {
V_207 = F_63 ( V_4 , V_209 , NULL ) ;
} else if ( ( V_206 & V_208 ) && V_205 -> V_178 == V_210 ) {
V_207 = F_63 ( V_4 , V_210 , NULL ) ;
} else if ( ( V_206 & V_208 ) && V_205 -> V_178 == V_211 ) {
V_207 = F_63 ( V_4 , V_211 , NULL ) ;
} else {
F_4 ( L_17 ,
V_206 & V_208 , V_205 -> V_178 ) ;
V_207 = - V_85 ;
}
F_42 ( & V_4 -> V_21 -> V_22 -> V_62 ) ;
return V_207 ;
}
struct V_212 * F_66 ( struct V_87 * V_90 , int V_213 ,
int V_214 , struct V_188 * V_189 ,
struct V_5 * V_6 )
{
struct V_212 * V_215 ;
F_25 ( L_9 ) ;
V_215 = F_50 ( sizeof( * V_215 ) , V_190 ) ;
if ( ! V_215 )
return F_29 ( - V_201 ) ;
return V_215 ;
}
int F_67 ( struct V_212 * V_215 )
{
F_25 ( L_9 ) ;
F_52 ( V_215 ) ;
return 0 ;
}
struct V_216 * F_68 ( struct V_187 * V_51 , T_1 V_217 , T_1 V_218 ,
T_1 V_219 , int V_220 ,
struct V_5 * V_6 )
{
struct V_221 * V_222 ;
int V_20 ;
F_25 ( L_18 , V_217 ,
V_219 , V_218 ) ;
V_222 = F_50 ( sizeof( * V_222 ) , V_190 ) ;
if ( F_9 ( V_222 ) )
return F_29 ( V_222 ? F_11 ( V_222 ) : - V_32 ) ;
V_222 -> V_223 = F_69 ( F_55 ( V_51 ) -> V_65 , V_217 , V_218 ,
V_220 , 0 ) ;
if ( F_9 ( V_222 -> V_223 ) ) {
V_20 = V_222 -> V_223 ? F_11 ( V_222 -> V_223 ) : - V_25 ;
goto V_224;
}
V_222 -> V_225 . V_226 = V_222 -> V_225 . V_227 = 0 ;
return & V_222 -> V_225 ;
V_224:
F_52 ( V_222 ) ;
return F_29 ( V_20 ) ;
}
int F_70 ( struct V_216 * V_225 )
{
struct V_221 * V_222 = F_71 ( V_225 ) ;
F_25 ( L_19 , V_222 -> V_223 -> V_228 , V_222 -> V_223 -> V_218 ) ;
F_72 ( V_222 -> V_223 , V_225 -> V_51 -> V_195 -> V_189 -> V_229 ) ;
F_52 ( V_222 ) ;
return 0 ;
}
struct V_188 * F_73 ( struct V_87 * V_90 ,
struct V_5 * V_6 )
{
struct V_193 * V_189 ;
struct V_7 * V_8 = F_37 ( V_90 ) ;
F_25 ( L_9 ) ;
V_189 = F_74 ( sizeof( * V_189 ) , V_190 ) ;
if ( ! V_189 )
return F_29 ( - V_32 ) ;
F_75 ( & V_189 -> V_204 ) ;
F_38 ( & V_8 -> V_62 ) ;
F_60 ( & V_189 -> V_45 , & V_8 -> V_230 ) ;
F_42 ( & V_8 -> V_62 ) ;
return & V_189 -> V_231 ;
}
int F_76 ( struct V_188 * V_232 )
{
struct V_193 * V_189 = F_57 ( V_232 ) ;
struct V_7 * V_8 = F_37 ( V_232 -> V_58 ) ;
F_25 ( L_9 ) ;
F_38 ( & V_8 -> V_62 ) ;
F_16 ( ! F_18 ( & V_189 -> V_204 ) ) ;
F_64 ( & V_189 -> V_45 ) ;
F_42 ( & V_8 -> V_62 ) ;
F_52 ( V_189 ) ;
return 0 ;
}
int F_77 ( struct V_188 * V_189 ,
struct V_233 * V_234 )
{
struct V_193 * V_235 = F_78 ( V_189 ) ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_56 * V_21 ;
struct V_13 * V_14 ;
T_4 V_28 ;
unsigned int V_30 ;
unsigned int V_26 ;
F_25 ( L_9 ) ;
V_8 = F_37 ( V_189 -> V_58 ) ;
V_234 -> V_236 |= V_237 ;
V_234 -> V_238 = F_79 ( V_234 -> V_238 ) ;
V_26 = V_234 -> V_239 ;
F_25 ( L_20 ,
V_234 -> V_239 , V_240 , V_26 ) ;
F_38 ( & V_8 -> V_62 ) ;
F_28 (qp_grp, &uctx->qp_grp_list, link) {
V_21 = V_4 -> V_21 ;
if ( F_7 ( V_21 -> V_23 ) == V_26 ) {
V_14 = F_5 ( V_21 -> V_23 , 0 ) ;
if ( ( V_234 -> V_241 - V_234 -> V_242 ) != V_14 -> V_30 ) {
F_4 ( L_21 ,
V_14 -> V_30 ,
V_234 -> V_241 - V_234 -> V_242 ) ;
F_42 ( & V_8 -> V_62 ) ;
return - V_85 ;
}
V_28 = V_14 -> V_28 ;
V_30 = V_14 -> V_30 ;
F_25 ( L_22 ,
& V_28 , V_14 -> V_243 , V_14 -> V_30 ) ;
F_42 ( & V_8 -> V_62 ) ;
return F_80 ( V_234 ,
V_234 -> V_242 ,
V_28 >> V_240 ,
V_30 , V_234 -> V_238 ) ;
}
}
F_42 ( & V_8 -> V_62 ) ;
F_4 ( L_23 , V_26 ) ;
return - V_85 ;
}
struct V_244 * F_81 ( struct V_187 * V_51 ,
struct V_245 * V_246 )
{
F_25 ( L_9 ) ;
return F_29 ( - V_247 ) ;
}
int F_82 ( struct V_244 * V_248 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_83 ( struct V_171 * V_180 , struct V_249 * V_250 ,
struct V_249 * * V_251 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_84 ( struct V_171 * V_180 , struct V_252 * V_250 ,
struct V_252 * * V_251 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_85 ( struct V_212 * V_253 , int V_254 ,
struct V_255 * V_256 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
int F_86 ( struct V_212 * V_215 ,
enum V_257 V_258 )
{
F_25 ( L_9 ) ;
return - V_85 ;
}
struct V_216 * F_87 ( struct V_187 * V_51 , int V_259 )
{
F_25 ( L_9 ) ;
return F_29 ( - V_32 ) ;
}
