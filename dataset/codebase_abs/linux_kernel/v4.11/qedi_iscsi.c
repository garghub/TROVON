int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
V_3 = F_2 ( V_2 , V_4 ) ;
if ( ! V_3 )
continue;
F_3 ( V_2 , V_3 ) ;
}
return V_6 ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 -> V_12 ;
struct V_1 * V_2 ;
V_2 = F_5 ( V_10 ) ;
return F_1 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
if ( V_3 -> V_13 . V_14 ) {
F_7 ( & V_2 -> V_15 -> V_16 , V_17 ,
V_3 -> V_13 . V_14 ,
V_3 -> V_13 . V_18 ) ;
V_3 -> V_13 . V_14 = NULL ;
}
if ( V_3 -> V_13 . V_19 ) {
F_7 ( & V_2 -> V_15 -> V_16 , V_17 ,
V_3 -> V_13 . V_19 ,
V_3 -> V_13 . V_20 ) ;
V_3 -> V_13 . V_19 = NULL ;
}
if ( V_3 -> V_13 . V_21 ) {
F_7 ( & V_2 -> V_15 -> V_16 ,
V_22 ,
V_3 -> V_13 . V_21 ,
V_3 -> V_13 . V_23 ) ;
V_3 -> V_13 . V_21 = NULL ;
}
if ( V_3 -> V_13 . V_24 ) {
F_7 ( & V_2 -> V_15 -> V_16 ,
V_22 ,
V_3 -> V_13 . V_24 ,
V_3 -> V_13 . V_25 ) ;
V_3 -> V_13 . V_24 = NULL ;
}
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
V_3 -> V_13 . V_24 =
F_9 ( & V_2 -> V_15 -> V_16 ,
V_22 ,
& V_3 -> V_13 . V_25 ,
V_26 ) ;
if ( ! V_3 -> V_13 . V_24 )
goto V_27;
V_3 -> V_13 . V_28 = 0 ;
V_3 -> V_13 . V_29 = V_3 -> V_13 . V_24 ;
V_3 -> V_13 . V_21 =
F_9 ( & V_2 -> V_15 -> V_16 ,
V_22 ,
& V_3 -> V_13 . V_23 ,
V_26 ) ;
if ( ! V_3 -> V_13 . V_21 )
goto V_30;
V_3 -> V_13 . V_31 = V_22 ;
V_3 -> V_13 . V_32 = V_3 -> V_13 . V_21 ;
V_3 -> V_13 . V_19 =
F_9 ( & V_2 -> V_15 -> V_16 , V_17 ,
& V_3 -> V_13 . V_20 , V_26 ) ;
if ( ! V_3 -> V_13 . V_19 )
goto V_33;
V_3 -> V_13 . V_14 =
F_9 ( & V_2 -> V_15 -> V_16 , V_17 ,
& V_3 -> V_13 . V_18 ,
V_26 ) ;
if ( ! V_3 -> V_13 . V_14 )
goto V_34;
F_10 ( & V_2 -> V_35 , V_36 ,
L_1 ,
V_3 -> V_37 ) ;
return 0 ;
V_34:
F_7 ( & V_2 -> V_15 -> V_16 , V_17 ,
V_3 -> V_13 . V_19 ,
V_3 -> V_13 . V_20 ) ;
V_3 -> V_13 . V_19 = NULL ;
V_33:
F_7 ( & V_2 -> V_15 -> V_16 , V_22 ,
V_3 -> V_13 . V_21 ,
V_3 -> V_13 . V_23 ) ;
V_3 -> V_13 . V_21 = NULL ;
V_30:
F_7 ( & V_2 -> V_15 -> V_16 , V_22 ,
V_3 -> V_13 . V_24 ,
V_3 -> V_13 . V_25 ) ;
V_3 -> V_13 . V_24 = NULL ;
V_27:
F_11 ( V_38 , V_3 -> V_39 -> V_40 ,
L_2 ) ;
return - V_41 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_43 -> V_44 ; V_4 ++ ) {
struct V_45 * V_46 = V_43 -> V_47 [ V_4 ] ;
struct V_48 * V_8 = V_46 -> V_40 ;
if ( V_8 -> V_49 . V_50 )
F_7 ( & V_2 -> V_15 -> V_16 ,
V_51 *
sizeof( struct V_52 ) ,
V_8 -> V_49 . V_50 ,
V_8 -> V_49 . V_53 ) ;
if ( V_8 -> V_54 )
F_7 ( & V_2 -> V_15 -> V_16 ,
V_55 ,
V_8 -> V_54 ,
V_8 -> V_56 ) ;
}
}
static int F_13 ( struct V_1 * V_2 , struct V_42 * V_43 ,
struct V_48 * V_8 )
{
struct V_57 * V_58 = & V_8 -> V_49 ;
struct V_52 * V_59 ;
V_58 -> V_50 = F_9 ( & V_2 -> V_15 -> V_16 ,
V_51 *
sizeof( * V_59 ) ,
& V_58 -> V_53 , V_26 ) ;
if ( ! V_58 -> V_50 ) {
F_14 ( V_38 , V_43 ,
L_3 ) ;
return - V_41 ;
}
V_58 -> V_60 = 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_43 -> V_44 ; V_4 ++ ) {
struct V_45 * V_46 = V_43 -> V_47 [ V_4 ] ;
struct V_48 * V_8 = V_46 -> V_40 ;
V_46 -> V_61 = & V_8 -> V_61 ;
V_46 -> V_62 = sizeof( struct V_63 ) ;
if ( F_13 ( V_2 , V_43 , V_8 ) )
goto V_64;
V_8 -> V_54 = F_9 ( & V_2 -> V_15 -> V_16 ,
V_55 ,
& V_8 -> V_56 ,
V_26 ) ;
if ( ! V_8 -> V_54 )
goto V_64;
}
return 0 ;
V_64:
F_12 ( V_2 , V_43 ) ;
return - V_41 ;
}
static struct V_65 *
F_16 ( struct V_66 * V_67 , T_1 V_44 ,
T_1 V_68 , T_2 V_69 )
{
struct V_9 * V_10 ;
struct V_65 * V_70 ;
struct V_1 * V_2 ;
struct V_71 * V_72 ;
if ( ! V_67 )
return NULL ;
V_72 = V_67 -> V_40 ;
V_10 = V_72 -> V_2 -> V_10 ;
V_2 = F_5 ( V_10 ) ;
if ( V_44 > V_2 -> V_73 )
V_44 = V_2 -> V_73 ;
else if ( V_44 < V_74 )
V_44 = V_74 ;
V_70 = F_17 ( & V_75 , V_10 ,
V_44 , 0 , sizeof( struct V_48 ) ,
V_69 , V_76 ) ;
if ( ! V_70 ) {
F_18 ( & V_2 -> V_35 ,
L_4 , V_72 ) ;
return NULL ;
}
if ( F_15 ( V_2 , V_70 -> V_40 ) ) {
F_18 ( & V_2 -> V_35 ,
L_5 , V_72 ) ;
goto V_77;
}
return V_70 ;
V_77:
F_19 ( V_70 ) ;
return NULL ;
}
static void F_20 ( struct V_65 * V_70 )
{
struct V_42 * V_43 = V_70 -> V_40 ;
struct V_9 * V_10 = F_21 ( V_70 ) ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
F_12 ( V_2 , V_43 ) ;
F_19 ( V_70 ) ;
}
static struct V_78 *
F_22 ( struct V_65 * V_70 , T_2 V_79 )
{
struct V_9 * V_10 = F_21 ( V_70 ) ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_78 * V_39 ;
struct V_3 * V_3 ;
struct V_80 * V_81 ;
V_39 = F_23 ( V_70 , sizeof( * V_3 ) ,
V_79 ) ;
if ( ! V_39 ) {
F_18 ( & V_2 -> V_35 ,
L_6 ,
V_79 , V_70 ) ;
return NULL ;
}
V_81 = V_39 -> V_40 ;
V_3 = V_81 -> V_40 ;
V_3 -> V_39 = V_39 ;
V_3 -> V_2 = V_2 ;
V_3 -> V_67 = NULL ;
V_3 -> V_82 = 0 ;
F_24 ( & V_3 -> V_83 ) ;
F_25 ( & V_3 -> V_84 ) ;
if ( F_8 ( V_2 , V_3 ) ) {
F_11 ( V_85 , V_81 ,
L_7 ,
V_79 , V_70 ) ;
goto V_86;
}
return V_39 ;
V_86:
F_26 ( V_39 ) ;
return NULL ;
}
void F_27 ( struct V_65 * V_70 )
{
F_28 ( V_70 ) ;
}
void F_29 ( struct V_65 * V_70 )
{
F_30 ( V_70 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
T_3 V_87 = V_3 -> V_37 ;
if ( V_2 -> V_88 . V_89 [ V_87 ] ) {
F_11 ( V_85 , V_3 -> V_39 -> V_40 ,
L_8 ,
V_87 ) ;
return - V_90 ;
}
V_2 -> V_88 . V_89 [ V_87 ] = V_3 ;
return 0 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 , T_3 V_87 )
{
if ( ! V_2 -> V_88 . V_89 ) {
F_18 ( & V_2 -> V_35 , L_9 ) ;
return NULL ;
} else if ( V_87 >= V_2 -> V_5 ) {
F_18 ( & V_2 -> V_35 , L_10 , V_87 ) ;
return NULL ;
}
return V_2 -> V_88 . V_89 [ V_87 ] ;
}
static int F_32 ( struct V_65 * V_70 ,
struct V_78 * V_39 ,
T_4 V_91 , int V_92 )
{
struct V_80 * V_81 = V_39 -> V_40 ;
struct V_3 * V_3 = V_81 -> V_40 ;
struct V_9 * V_10 = F_21 ( V_70 ) ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_71 * V_72 ;
struct V_66 * V_67 ;
V_67 = F_33 ( V_91 ) ;
if ( ! V_67 )
return - V_93 ;
V_72 = V_67 -> V_40 ;
if ( ( V_72 -> V_94 == V_95 ) ||
( V_72 -> V_94 == V_96 ) )
return - V_93 ;
if ( F_34 ( V_70 , V_39 , V_92 ) )
return - V_93 ;
V_72 -> V_81 = V_3 ;
V_3 -> V_67 = V_72 ;
V_3 -> V_37 = V_72 -> V_87 ;
V_3 -> V_97 = V_72 -> V_97 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 0 ;
if ( F_31 ( V_2 , V_3 ) )
return - V_93 ;
F_25 ( & V_3 -> V_100 ) ;
F_24 ( & V_3 -> V_101 ) ;
F_35 ( & V_3 -> V_102 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_103 * V_104 ;
struct V_78 * V_39 = V_3 -> V_39 ;
struct V_80 * V_81 = V_39 -> V_40 ;
struct V_71 * V_72 ;
int V_105 ;
V_72 = V_3 -> V_67 ;
V_104 = F_37 ( sizeof( * V_104 ) , V_26 ) ;
if ( ! V_104 ) {
F_18 ( & V_2 -> V_35 , L_11 ) ;
return - V_41 ;
}
V_104 -> V_106 = 0 ;
if ( V_81 -> V_107 )
F_38 ( V_104 -> V_106 ,
V_108 , true ) ;
if ( V_81 -> V_109 )
F_38 ( V_104 -> V_106 ,
V_110 , true ) ;
if ( V_81 -> V_43 -> V_111 )
F_38 ( V_104 -> V_106 ,
V_112 ,
true ) ;
if ( V_81 -> V_43 -> V_113 )
F_38 ( V_104 -> V_106 ,
V_114 ,
true ) ;
V_104 -> V_115 = V_81 -> V_43 -> V_116 ;
V_104 -> V_117 = V_81 -> V_118 ;
V_104 -> V_119 = V_81 -> V_120 ;
V_104 -> V_121 = V_81 -> V_43 -> V_122 ;
V_104 -> V_123 = V_81 -> V_124 ;
V_105 = V_125 -> V_126 ( V_2 -> V_127 , V_72 -> V_128 ,
V_104 ) ;
if ( V_105 ) {
V_105 = - V_129 ;
F_18 ( & V_2 -> V_35 , L_12 ) ;
}
F_39 ( V_104 ) ;
return V_105 ;
}
static T_1 F_40 ( T_1 V_130 , T_5 V_131 , T_5 V_132 , T_5 V_133 )
{
T_1 V_134 = 0 ;
T_1 V_135 = V_136 ;
if ( V_131 )
V_135 += V_137 ;
else
V_135 += V_138 ;
if ( V_133 )
V_135 += V_139 ;
V_134 = V_130 - V_135 ;
if ( V_132 )
V_134 -= V_140 ;
if ( ! V_134 )
V_134 = V_141 ;
return V_134 ;
}
static int F_41 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_142 * V_104 ;
int V_105 ;
int V_4 ;
V_104 = F_37 ( sizeof( * V_104 ) , V_26 ) ;
if ( ! V_104 ) {
F_18 ( & V_2 -> V_35 ,
L_13 , V_72 ) ;
return - V_41 ;
}
F_42 ( V_104 -> V_143 . V_144 , V_72 -> V_145 ) ;
F_42 ( V_104 -> V_146 . V_144 , V_72 -> V_147 ) ;
V_104 -> V_143 . V_148 [ 0 ] = F_43 ( V_72 -> V_149 [ 0 ] ) ;
V_104 -> V_146 . V_148 [ 0 ] = F_43 ( V_72 -> V_150 [ 0 ] ) ;
if ( V_72 -> V_151 == V_152 ) {
V_104 -> V_153 = 0 ;
F_10 ( & V_2 -> V_35 , V_154 ,
L_14 ,
V_72 -> V_149 , V_72 -> V_150 ) ;
} else {
for ( V_4 = 1 ; V_4 < 4 ; V_4 ++ ) {
V_104 -> V_143 . V_148 [ V_4 ] = F_43 ( V_72 -> V_149 [ V_4 ] ) ;
V_104 -> V_146 . V_148 [ V_4 ] = F_43 ( V_72 -> V_150 [ V_4 ] ) ;
}
V_104 -> V_153 = 1 ;
F_10 ( & V_2 -> V_35 , V_154 ,
L_15 ,
V_72 -> V_149 , V_72 -> V_150 ) ;
}
V_104 -> V_143 . V_155 = V_72 -> V_156 ;
V_104 -> V_146 . V_155 = V_72 -> V_157 ;
V_104 -> V_158 = V_159 ;
V_104 -> V_160 = V_72 -> V_161 ;
V_104 -> V_162 = V_72 -> V_162 ;
F_38 ( V_104 -> V_163 , V_164 , 1 ) ;
F_38 ( V_104 -> V_163 , V_165 , 1 ) ;
F_38 ( V_104 -> V_163 , V_166 , 1 ) ;
F_38 ( V_104 -> V_163 , V_167 , 1 ) ;
V_104 -> V_168 = ( V_72 -> V_97 % 8 ) ;
V_104 -> V_169 = V_170 ;
V_104 -> V_171 = 3 ;
V_104 -> V_172 = 65535 ;
V_104 -> V_173 = V_174 ;
V_104 -> V_175 = 65535 ;
V_104 -> V_176 = 300 ;
V_104 -> V_177 = 150 ;
V_104 -> V_178 = 0 ;
V_104 -> V_179 = V_180 ;
V_104 -> V_181 = V_182 ;
V_104 -> V_183 = V_184 ;
V_104 -> V_185 = V_186 ;
V_104 -> V_187 = V_188 ;
V_104 -> V_189 = V_72 -> V_157 ;
V_104 -> V_190 = V_72 -> V_156 ;
V_104 -> V_134 = F_40 ( V_72 -> V_130 ,
( V_72 -> V_151 == V_191 ) ,
1 , ( V_72 -> V_162 != 0 ) ) ;
V_104 -> V_192 = 4 ;
V_104 -> V_193 = 1000 ;
V_104 -> V_194 = 200 ;
V_104 -> V_195 = 2 ;
F_10 ( & V_2 -> V_35 , V_196 ,
L_16 ,
V_104 -> V_168 , V_104 -> V_134 ) ;
V_105 = V_125 -> V_197 ( V_2 -> V_127 , V_72 -> V_128 , V_104 ) ;
if ( V_105 )
F_18 ( & V_2 -> V_35 , L_17 ,
V_105 , V_72 ) ;
F_39 ( V_104 ) ;
return V_105 ;
}
static int F_44 ( struct V_78 * V_39 )
{
struct V_80 * V_81 = V_39 -> V_40 ;
struct V_3 * V_3 = V_81 -> V_40 ;
struct V_1 * V_2 ;
int V_105 ;
V_2 = V_3 -> V_2 ;
V_105 = F_36 ( V_2 , V_3 ) ;
if ( V_105 ) {
F_11 ( V_85 , V_81 ,
L_18 ) ;
V_105 = - V_93 ;
goto V_198;
}
F_45 ( V_199 , & V_3 -> V_200 ) ;
V_3 -> V_201 = 0 ;
V_105 = F_46 ( V_39 ) ;
if ( V_105 ) {
F_11 ( V_85 , V_81 ,
L_19 ) ;
}
V_198:
return V_105 ;
}
static void F_47 ( struct V_78 * V_39 )
{
struct V_80 * V_81 = V_39 -> V_40 ;
struct V_3 * V_3 = V_81 -> V_40 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = F_21 ( F_48 ( V_39 ) ) ;
V_2 = F_5 ( V_10 ) ;
F_6 ( V_2 , V_3 ) ;
F_26 ( V_39 ) ;
}
static int F_49 ( struct V_66 * V_67 ,
enum V_202 V_203 , char * V_204 )
{
struct V_71 * V_72 = V_67 -> V_40 ;
int V_205 ;
if ( ! V_72 )
return - V_206 ;
switch ( V_203 ) {
case V_207 :
V_205 = sprintf ( V_204 , L_20 , V_72 -> V_157 ) ;
break;
case V_208 :
if ( V_72 -> V_151 == V_152 )
V_205 = sprintf ( V_204 , L_21 , V_72 -> V_150 ) ;
else
V_205 = sprintf ( V_204 , L_22 , V_72 -> V_150 ) ;
break;
default:
return - V_206 ;
}
return V_205 ;
}
static int F_50 ( struct V_9 * V_10 ,
enum V_209 V_203 , char * V_204 )
{
struct V_1 * V_2 ;
int V_205 ;
V_2 = F_5 ( V_10 ) ;
switch ( V_203 ) {
case V_210 :
V_205 = F_51 ( V_204 , V_2 -> V_144 , 6 ) ;
break;
case V_211 :
V_205 = sprintf ( V_204 , L_23 , V_10 -> V_212 ) ;
break;
case V_213 :
if ( V_2 -> V_151 == V_152 )
V_205 = sprintf ( V_204 , L_21 , V_2 -> V_214 ) ;
else
V_205 = sprintf ( V_204 , L_22 , V_2 -> V_214 ) ;
break;
default:
return F_52 ( V_10 , V_203 , V_204 ) ;
}
return V_205 ;
}
static void F_53 ( struct V_78 * V_39 ,
struct V_215 * V_216 )
{
struct V_80 * V_81 = V_39 -> V_40 ;
struct V_217 V_215 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = F_21 ( F_48 ( V_39 ) ) ;
V_2 = F_5 ( V_10 ) ;
V_125 -> V_218 ( V_2 -> V_127 , & V_215 ) ;
V_81 -> V_219 = V_215 . V_220 ;
V_81 -> V_221 = V_215 . V_222 ;
V_81 -> V_223 = ( T_2 ) V_215 . V_224 ;
V_81 -> V_225 = ( T_2 ) V_215 . V_226 ;
V_81 -> V_227 = ( T_2 ) V_215 . V_228 ;
V_216 -> V_219 = V_81 -> V_219 ;
V_216 -> V_221 = V_81 -> V_221 ;
V_216 -> V_229 = V_81 -> V_230 ;
V_216 -> V_231 = V_81 -> V_223 ;
V_216 -> V_232 = V_81 -> V_233 ;
V_216 -> V_234 = V_81 -> V_225 ;
V_216 -> V_235 = V_81 -> V_227 ;
V_216 -> V_236 = V_81 -> V_237 ;
V_216 -> V_238 = V_81 -> V_239 ;
V_216 -> V_240 = 0 ;
V_216 -> V_241 = 0 ;
strcpy ( V_216 -> V_242 [ 0 ] . V_243 , L_24 ) ;
V_216 -> V_242 [ 0 ] . V_244 = V_81 -> V_245 ;
V_216 -> V_246 = 1 ;
}
static void F_54 ( struct V_3 * V_3 )
{
struct V_52 * V_247 ;
V_247 = (struct V_52 * ) V_3 -> V_13 . V_19 ;
V_247 -> V_248 . V_249 =
( T_3 ) ( ( T_4 ) V_3 -> V_13 . V_25 >> 32 ) ;
V_247 -> V_248 . V_250 = ( T_3 ) V_3 -> V_13 . V_25 ;
V_247 -> V_251 = V_3 -> V_13 . V_29 -
V_3 -> V_13 . V_24 ;
V_247 -> V_252 = 0 ;
V_247 = (struct V_52 * ) V_3 -> V_13 . V_14 ;
V_247 -> V_248 . V_249 =
( T_3 ) ( ( T_4 ) V_3 -> V_13 . V_23 >> 32 ) ;
V_247 -> V_248 . V_250 = ( T_3 ) V_3 -> V_13 . V_23 ;
V_247 -> V_251 = V_22 ;
V_247 -> V_252 = 0 ;
}
static int F_55 ( struct V_45 * V_46 )
{
struct V_48 * V_8 = V_46 -> V_40 ;
struct V_3 * V_3 = V_8 -> V_81 ;
char * V_204 ;
int V_253 ;
int V_254 = 0 ;
F_54 ( V_3 ) ;
switch ( V_46 -> V_61 -> V_255 & V_256 ) {
case V_257 :
F_56 ( V_3 , V_46 ) ;
break;
case V_258 :
V_253 = V_3 -> V_13 . V_28 ;
V_204 = V_3 -> V_13 . V_24 ;
if ( V_253 )
V_254 = F_57 ( V_3 , V_46 ,
V_204 , V_253 , 1 ) ;
else
V_254 = F_57 ( V_3 , V_46 ,
NULL , 0 , 1 ) ;
break;
case V_259 :
V_254 = F_58 ( V_3 , V_46 ) ;
break;
case V_260 :
V_254 = F_59 ( V_3 , V_46 ) ;
break;
case V_261 :
V_254 = F_60 ( V_3 , V_46 ) ;
break;
default:
F_11 ( V_85 , V_3 -> V_39 -> V_40 ,
L_25 , V_46 -> V_61 -> V_255 ) ;
}
return V_254 ;
}
static int F_61 ( struct V_80 * V_81 , struct V_45 * V_46 )
{
struct V_3 * V_3 = V_81 -> V_40 ;
struct V_48 * V_8 = V_46 -> V_40 ;
memset ( V_3 -> V_13 . V_24 , 0 , V_22 ) ;
V_3 -> V_13 . V_28 = V_46 -> V_262 ;
if ( V_46 -> V_262 ) {
memcpy ( V_3 -> V_13 . V_24 , V_46 -> V_263 ,
V_46 -> V_262 ) ;
V_3 -> V_13 . V_29 =
V_3 -> V_13 . V_24 + V_46 -> V_262 ;
}
V_8 -> V_81 = V_81 -> V_40 ;
V_8 -> V_264 = NULL ;
return F_55 ( V_46 ) ;
}
static int F_62 ( struct V_45 * V_46 )
{
struct V_80 * V_81 = V_46 -> V_81 ;
struct V_3 * V_3 = V_81 -> V_40 ;
struct V_48 * V_8 = V_46 -> V_40 ;
struct V_7 * V_265 = V_46 -> V_265 ;
V_8 -> V_94 = 0 ;
V_8 -> V_46 = NULL ;
V_8 -> V_266 = false ;
V_8 -> V_81 = V_3 ;
V_8 -> V_46 = V_46 ;
V_8 -> V_267 = false ;
F_24 ( & V_8 -> V_268 ) ;
if ( ! V_265 )
return F_61 ( V_81 , V_46 ) ;
V_8 -> V_264 = V_265 ;
return F_63 ( V_46 ) ;
}
static struct V_66 *
F_64 ( struct V_9 * V_10 , struct V_269 * V_150 ,
int V_270 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 ;
struct V_71 * V_72 ;
struct V_271 * V_272 ;
struct V_273 * V_274 ;
struct V_275 * V_127 = NULL ;
struct V_276 * V_277 = NULL ;
struct V_278 V_279 ;
T_3 V_280 = V_281 ;
T_3 V_87 = V_282 ;
T_1 V_205 = 0 ;
char * V_204 = NULL ;
int V_283 ;
if ( ! V_10 ) {
V_283 = - V_129 ;
F_18 ( NULL , L_26 ) ;
return F_65 ( V_283 ) ;
}
if ( V_284 ) {
V_283 = - V_41 ;
return F_65 ( V_283 ) ;
}
V_2 = F_5 ( V_10 ) ;
V_127 = V_2 -> V_127 ;
V_277 = V_2 -> V_277 ;
if ( F_66 ( V_285 , & V_2 -> V_200 ) ||
F_66 ( V_286 , & V_2 -> V_200 ) ) {
V_283 = - V_41 ;
return F_65 ( V_283 ) ;
}
V_67 = F_67 ( sizeof( struct V_71 ) ) ;
if ( ! V_67 ) {
F_18 ( & V_2 -> V_35 , L_27 ) ;
V_283 = - V_41 ;
return F_65 ( V_283 ) ;
}
V_72 = V_67 -> V_40 ;
memset ( V_72 , 0 , sizeof( struct V_71 ) ) ;
V_72 -> V_94 = V_287 ;
V_72 -> V_87 = ( T_3 ) - 1 ;
V_72 -> V_2 = V_2 ;
if ( V_150 -> V_288 == V_289 ) {
V_272 = (struct V_271 * ) V_150 ;
memcpy ( V_72 -> V_150 , & V_272 -> V_290 . V_291 ,
sizeof( struct V_292 ) ) ;
V_72 -> V_157 = F_68 ( V_272 -> V_293 ) ;
V_72 -> V_151 = V_152 ;
F_10 ( & V_2 -> V_35 , V_154 ,
L_28 ,
V_72 -> V_150 , V_72 -> V_157 ) ;
} else if ( V_150 -> V_288 == V_294 ) {
V_274 = (struct V_273 * ) V_150 ;
memcpy ( V_72 -> V_150 , & V_274 -> V_295 ,
sizeof( struct V_296 ) ) ;
V_72 -> V_157 = F_68 ( V_274 -> V_297 ) ;
V_72 -> V_151 = V_191 ;
F_10 ( & V_2 -> V_35 , V_154 ,
L_29 ,
V_72 -> V_150 , V_72 -> V_157 ) ;
} else {
F_18 ( & V_2 -> V_35 , L_30 ) ;
}
if ( F_69 ( & V_2 -> V_298 ) != V_299 ) {
F_70 ( & V_2 -> V_35 , L_31 ) ;
V_283 = - V_129 ;
goto V_300;
}
V_283 = F_71 ( V_2 , V_72 ) ;
if ( V_283 )
goto V_300;
V_283 = V_125 -> V_301 ( V_2 -> V_127 , & V_72 -> V_128 ,
& V_72 -> V_97 , & V_72 -> V_302 ) ;
if ( V_283 ) {
F_18 ( & V_2 -> V_35 , L_32 ) ;
V_283 = - V_129 ;
goto V_303;
}
V_87 = V_72 -> V_128 ;
V_72 -> V_87 = V_87 ;
F_35 ( & V_72 -> V_304 ) ;
F_35 ( & V_72 -> V_305 ) ;
V_72 -> V_94 = V_306 ;
V_2 -> V_307 [ V_87 ] = V_72 ;
V_204 = ( char * ) & V_279 ;
V_205 = sizeof( V_279 ) ;
memset ( & V_279 , 0 , V_205 ) ;
V_280 = V_308 ;
V_279 . V_128 = ( T_4 ) V_72 -> V_87 ;
V_279 . V_130 = V_2 -> V_309 ;
V_72 -> V_130 = V_2 -> V_309 ;
if ( V_72 -> V_151 == V_152 ) {
memcpy ( & V_279 . V_146 . V_310 , & V_72 -> V_150 ,
sizeof( struct V_292 ) ) ;
V_279 . V_311 = 4 ;
} else {
memcpy ( & V_279 . V_146 . V_312 , & V_72 -> V_150 ,
sizeof( struct V_296 ) ) ;
V_279 . V_311 = 16 ;
}
V_283 = F_72 ( V_10 , & V_75 , V_280 , V_204 ,
V_205 ) ;
if ( V_283 ) {
F_18 ( & V_2 -> V_35 ,
L_33 ,
V_87 , V_283 ) ;
goto V_313;
}
F_73 ( & V_2 -> V_314 ) ;
return V_67 ;
V_313:
V_2 -> V_307 [ V_87 ] = NULL ;
V_283 = V_125 -> V_315 ( V_2 -> V_127 , V_72 -> V_128 ) ;
if ( V_283 )
F_70 ( & V_2 -> V_35 , L_34 ,
V_283 ) ;
V_303:
F_74 ( V_2 , V_72 ) ;
V_300:
F_75 ( V_67 ) ;
return F_65 ( V_283 ) ;
}
static int F_76 ( struct V_66 * V_67 , int V_316 )
{
struct V_71 * V_72 ;
int V_283 = 0 ;
if ( V_284 )
return 1 ;
V_72 = V_67 -> V_40 ;
if ( V_72 -> V_94 == V_287 ||
V_72 -> V_94 == V_317 )
return - 1 ;
if ( V_72 -> V_94 == V_318 )
V_283 = 1 ;
V_283 = F_77 ( V_72 -> V_304 ,
F_78 ( V_72 ) ,
F_79 ( V_316 ) ) ;
if ( V_72 -> V_94 == V_317 )
V_283 = - 1 ;
if ( V_283 > 0 )
return 1 ;
else if ( ! V_283 )
return 0 ;
else
return V_283 ;
}
static void F_80 ( struct V_3 * V_3 )
{
struct V_48 * V_8 , * V_319 ;
F_81 (cmd, cmd_tmp, &qedi_conn->active_cmd_list,
io_cmd) {
F_82 ( & V_8 -> V_268 ) ;
V_3 -> V_82 -- ;
}
}
static void F_83 ( struct V_66 * V_67 )
{
struct V_71 * V_72 ;
struct V_3 * V_3 = NULL ;
struct V_80 * V_81 = NULL ;
struct V_1 * V_2 ;
int V_283 = 0 ;
int V_320 = 20 * V_321 ;
int V_201 = 0 ;
int V_322 = 10 ;
V_72 = V_67 -> V_40 ;
V_2 = V_72 -> V_2 ;
F_84 ( & V_72 -> V_323 ) ;
if ( V_72 -> V_81 ) {
V_3 = V_72 -> V_81 ;
V_81 = V_3 -> V_39 -> V_40 ;
F_85 ( V_81 ) ;
V_201 = V_3 -> V_201 ;
while ( V_322 -- ) {
if ( ! F_66 ( V_199 ,
& V_3 -> V_200 ) ) {
break;
}
F_86 ( 1000 ) ;
}
if ( F_66 ( V_286 , & V_2 -> V_200 ) ) {
if ( V_284 ) {
F_10 ( & V_2 -> V_35 , V_196 ,
L_35 ,
V_72 -> V_87 ) ;
goto V_324;
}
F_10 ( & V_2 -> V_35 , V_196 ,
L_36 ,
V_72 -> V_87 , V_72 , V_72 -> V_94 ) ;
F_80 ( V_3 ) ;
goto V_325;
}
}
if ( V_284 )
goto V_324;
switch ( V_72 -> V_94 ) {
case V_306 :
goto V_325;
case V_317 :
break;
case V_318 :
if ( F_87 ( ! V_3 ) )
break;
F_10 ( & V_2 -> V_35 , V_196 ,
L_37 ,
V_3 -> V_82 , V_201 ,
V_72 -> V_94 ,
V_72 -> V_87 ,
V_72 -> V_81
) ;
if ( ! V_3 -> V_82 )
V_201 = 0 ;
else
V_201 = 1 ;
if ( V_201 )
F_88 ( V_2 , V_3 , NULL ) ;
break;
default:
break;
}
V_72 -> V_94 = V_326 ;
V_283 = V_125 -> V_327 ( V_2 -> V_127 , V_72 -> V_128 , V_201 ) ;
if ( V_283 ) {
F_70 ( & V_2 -> V_35 ,
L_38 , V_283 ) ;
} else {
V_283 = F_77 (
V_72 -> V_305 ,
( V_72 -> V_94 !=
V_326 ) ,
V_320 ) ;
if ( ( V_283 <= 0 ) || ( V_72 -> V_94 == V_326 ) ) {
F_70 ( & V_2 -> V_35 ,
L_39 ,
V_283 , V_320 , V_72 -> V_87 ) ;
}
}
V_325:
V_283 = V_125 -> V_315 ( V_2 -> V_127 , V_72 -> V_128 ) ;
if ( V_283 )
F_70 ( & V_2 -> V_35 ,
L_40 ,
V_283 , V_72 -> V_87 ) ;
V_324:
V_72 -> V_94 = V_287 ;
V_2 -> V_307 [ V_72 -> V_87 ] = NULL ;
V_2 -> V_88 . V_89 [ V_72 -> V_87 ] = NULL ;
F_89 ( & V_2 -> V_328 , V_72 -> V_156 ) ;
F_74 ( V_2 , V_72 ) ;
if ( V_3 )
V_3 -> V_67 = NULL ;
V_72 -> V_81 = NULL ;
V_72 -> V_2 = NULL ;
F_90 ( & V_2 -> V_314 ) ;
F_75 ( V_67 ) ;
}
static int F_91 ( struct V_1 * V_2 , T_1 V_329 )
{
struct V_275 * V_127 = V_2 -> V_127 ;
struct V_276 * V_277 ;
struct V_330 * V_331 ;
struct V_332 * V_333 ;
T_3 V_205 ;
int V_254 = 0 ;
V_277 = V_2 -> V_277 ;
if ( ! V_277 ) {
F_18 ( & V_2 -> V_35 , L_41 ) ;
return - V_93 ;
}
V_331 = (struct V_330 * ) V_277 -> V_331 ;
if ( ! V_331 ) {
F_18 ( & V_2 -> V_35 , L_42 ) ;
return - V_93 ;
}
V_205 = V_331 -> V_334 ;
if ( ! V_205 ) {
F_18 ( & V_2 -> V_35 , L_43 , V_205 ) ;
return - V_93 ;
}
V_333 = F_92 ( V_205 , V_335 ) ;
if ( ! V_333 ) {
F_18 ( & V_2 -> V_35 , L_44 ) ;
return - V_93 ;
}
F_93 ( V_333 , V_205 ) ;
memcpy ( V_333 -> V_263 , V_277 -> V_336 , V_205 ) ;
V_333 -> V_337 = V_338 ;
if ( V_329 )
F_94 ( V_333 , F_95 ( V_339 ) , V_329 ) ;
V_254 = V_125 -> V_340 -> V_341 ( V_127 , V_333 ) ;
if ( V_254 ) {
F_18 ( & V_2 -> V_35 , L_45 ,
V_254 ) ;
F_96 ( V_333 ) ;
}
V_331 -> V_334 = 0 ;
V_331 -> V_342 ++ ;
return V_254 ;
}
static void F_97 ( struct V_343 * V_344 )
{
struct V_71 * V_72 =
F_98 ( V_344 , struct V_71 , V_323 ) ;
struct V_1 * V_2 ;
int V_320 = 20 * V_321 ;
int V_283 ;
V_2 = V_72 -> V_2 ;
V_283 = F_41 ( V_72 ) ;
if ( V_283 ) {
F_18 ( & V_2 -> V_35 ,
L_46 ,
V_72 -> V_87 , V_72 , V_283 ) ;
V_72 -> V_94 = V_317 ;
return;
}
V_283 = F_77 ( V_72 -> V_305 ,
( V_72 -> V_94 ==
V_318 ) ,
V_320 ) ;
if ( ( V_283 <= 0 ) || ( V_72 -> V_94 != V_318 ) ) {
V_72 -> V_94 = V_317 ;
F_18 ( & V_2 -> V_35 ,
L_47 ,
V_72 -> V_87 , V_72 ) ;
}
}
static int F_99 ( struct V_9 * V_10 , struct V_278 * V_345 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
int V_283 = 0 ;
T_3 V_87 ;
T_1 V_346 = 0 ;
if ( ! V_10 ) {
V_283 = - V_129 ;
F_18 ( NULL , L_26 ) ;
return V_283 ;
}
if ( strcmp ( V_10 -> V_347 -> V_348 , L_48 ) ) {
V_283 = - V_129 ;
F_18 ( NULL , L_49 ,
V_10 -> V_347 -> V_348 ) ;
return V_283 ;
}
V_2 = F_5 ( V_10 ) ;
if ( V_345 -> V_128 == V_349 ) {
V_283 = F_91 ( V_2 , V_345 -> V_162 ) ;
goto V_350;
}
V_87 = ( T_3 ) V_345 -> V_128 ;
V_72 = V_2 -> V_307 [ V_87 ] ;
F_10 ( & V_2 -> V_35 , V_154 ,
L_50 , V_87 , V_72 ) ;
if ( ! F_100 ( & V_345 -> V_351 [ 0 ] ) ) {
F_101 ( & V_2 -> V_35 , L_51 ) ;
V_283 = - V_352 ;
goto V_350;
}
F_42 ( & V_72 -> V_145 [ 0 ] , & V_2 -> V_144 [ 0 ] ) ;
F_42 ( & V_72 -> V_147 [ 0 ] , & V_345 -> V_351 [ 0 ] ) ;
V_72 -> V_162 = V_345 -> V_162 ;
if ( V_345 -> V_130 < V_353 ) {
V_72 -> V_130 = V_2 -> V_309 ;
F_10 ( & V_2 -> V_35 , V_196 ,
L_52 ,
V_345 -> V_130 , V_72 -> V_130 ) ;
}
if ( V_345 -> V_130 != V_2 -> V_309 ) {
if ( V_345 -> V_130 > V_354 ) {
V_283 = - V_93 ;
F_18 ( NULL , L_53 , V_345 -> V_130 ) ;
goto V_350;
}
F_102 ( V_2 , V_345 -> V_130 ) ;
V_72 -> V_130 = V_2 -> V_309 ;
}
V_346 = V_72 -> V_156 ;
if ( V_346 >= V_355 &&
V_346 < V_356 ) {
if ( F_103 ( & V_2 -> V_328 , V_346 ) )
V_346 = 0 ;
} else {
V_346 = 0 ;
}
if ( ! V_346 ) {
V_346 = F_104 ( & V_2 -> V_328 ) ;
if ( V_346 == V_357 ) {
F_18 ( & V_2 -> V_35 ,
L_54 ,
V_87 ) ;
V_283 = - V_41 ;
goto V_350;
}
}
V_72 -> V_156 = V_346 ;
if ( V_72 -> V_151 == V_152 ) {
memcpy ( & V_72 -> V_149 [ 0 ] , & V_345 -> V_143 . V_310 ,
sizeof( struct V_292 ) ) ;
memcpy ( & V_2 -> V_214 [ 0 ] , & V_345 -> V_143 . V_310 ,
sizeof( struct V_292 ) ) ;
V_2 -> V_151 = V_152 ;
F_10 ( & V_2 -> V_35 , V_154 ,
L_55 ,
V_72 -> V_149 , V_72 -> V_156 ,
V_72 -> V_150 , V_72 -> V_157 ) ;
} else {
memcpy ( & V_72 -> V_149 [ 0 ] , & V_345 -> V_143 . V_312 ,
sizeof( struct V_296 ) ) ;
memcpy ( & V_2 -> V_214 [ 0 ] , & V_345 -> V_143 . V_312 ,
sizeof( struct V_296 ) ) ;
V_2 -> V_151 = V_191 ;
F_10 ( & V_2 -> V_35 , V_154 ,
L_56 ,
V_72 -> V_149 , V_72 -> V_156 ,
V_72 -> V_150 , V_72 -> V_157 ) ;
}
F_105 ( & V_72 -> V_323 , F_97 ) ;
F_106 ( V_2 -> V_358 , & V_72 -> V_323 ) ;
V_283 = 0 ;
V_350:
return V_283 ;
}
static T_6 F_107 ( int V_359 , int V_203 )
{
switch ( V_359 ) {
case V_360 :
switch ( V_203 ) {
case V_211 :
case V_210 :
case V_213 :
return 0444 ;
default:
return 0 ;
}
case V_361 :
switch ( V_203 ) {
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_208 :
case V_207 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
return 0444 ;
default:
return 0 ;
}
}
return 0 ;
}
static void F_108 ( struct V_45 * V_46 )
{
if ( ! V_46 -> V_265 || V_46 -> V_94 == V_394 ) {
F_10 ( NULL , V_395 , L_57 ,
F_69 ( & V_46 -> V_396 ) ) ;
return;
}
F_109 ( V_46 -> V_40 ) ;
}
void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_65 * V_397 ;
struct V_78 * V_39 ;
struct V_80 * V_81 ;
V_39 = V_3 -> V_39 ;
V_81 = V_39 -> V_40 ;
V_397 = F_48 ( V_39 ) ;
if ( F_110 ( V_397 ) ) {
V_3 -> V_201 = 1 ;
F_18 ( & V_2 -> V_35 ,
L_58 ,
V_81 -> V_43 -> V_94 , V_3 -> V_37 ) ;
F_111 ( V_3 -> V_39 -> V_40 ,
V_398 ) ;
}
}
char * F_112 ( enum V_399 V_400 )
{
int V_4 ;
char * V_401 = NULL ;
for ( V_4 = 0 ; V_4 < F_113 ( V_402 ) ; V_4 ++ ) {
if ( V_402 [ V_4 ] . V_403 == V_400 ) {
V_401 = V_402 [ V_4 ] . V_404 ;
break;
}
}
return V_401 ;
}
void F_114 ( struct V_71 * V_67 , struct V_405 * V_263 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
char V_406 [] = L_59 ;
char V_407 [] = L_60 ;
char V_408 [] = L_61 ;
char * V_409 ;
int V_410 = 0 ;
T_3 V_411 = 0 ;
char * V_401 ;
if ( ! V_67 )
return;
V_3 = V_67 -> V_81 ;
if ( ! V_3 )
return;
V_2 = V_67 -> V_2 ;
F_18 ( & V_2 -> V_35 , L_62 ,
V_263 -> V_403 ) ;
if ( V_411 ) {
V_410 = 0 ;
V_409 = V_406 ;
} else {
V_410 = 1 ;
V_409 = V_407 ;
}
V_401 = F_112 ( V_263 -> V_403 ) ;
if ( ! V_401 ) {
V_410 = 0 ;
V_401 = V_408 ;
}
F_11 ( V_85 ,
V_3 -> V_39 -> V_40 ,
L_63 , V_409 , V_401 ) ;
if ( V_410 )
F_3 ( V_3 -> V_2 , V_3 ) ;
}
void F_115 ( struct V_71 * V_67 , struct V_405 * V_263 )
{
struct V_3 * V_3 ;
if ( ! V_67 )
return;
V_3 = V_67 -> V_81 ;
if ( ! V_3 )
return;
F_18 ( & V_67 -> V_2 -> V_35 , L_64 ,
V_263 -> V_403 ) ;
F_3 ( V_3 -> V_2 , V_3 ) ;
}
