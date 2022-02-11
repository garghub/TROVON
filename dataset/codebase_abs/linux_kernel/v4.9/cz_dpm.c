static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
return V_4 ;
}
static struct V_6 * F_2 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = V_8 -> V_10 . V_11 . V_12 ;
return V_9 ;
}
static T_1 F_3 ( struct V_7 * V_8 ,
T_1 V_13 )
{
T_1 V_14 = 6200 - V_13 * 25 ;
return V_14 ;
}
static void F_4 ( struct V_7 * V_8 ,
struct V_15 * V_16 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_17 * V_18 =
& V_8 -> V_10 . V_11 . V_19 . V_20 ;
if ( V_18 -> V_21 > 0 ) {
V_16 -> V_22 = V_18 -> V_23 [ V_18 -> V_21 - 1 ] . V_24 ;
V_16 -> V_25 = F_3 ( V_8 ,
V_18 -> V_23 [ V_18 -> V_21 - 1 ] . V_26 ) ;
}
V_16 -> V_27 = V_9 -> V_28 . V_29 [ 0 ] ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_30 * V_31 = & V_8 -> V_31 ;
int V_32 = F_6 ( V_33 , V_34 ) ;
union V_35 * V_35 ;
T_2 V_36 , V_37 ;
T_3 V_38 ;
int V_39 = 0 ;
if ( F_7 ( V_31 -> V_40 , V_32 , NULL ,
& V_36 , & V_37 , & V_38 ) ) {
V_35 = (union V_35 * ) ( V_31 -> V_40 -> V_41 +
V_38 ) ;
if ( V_37 != 9 ) {
F_8 ( L_1 , V_36 , V_37 ) ;
return - V_42 ;
}
V_9 -> V_28 . V_43 =
F_9 ( V_35 -> V_44 . V_45 ) ;
V_9 -> V_28 . V_46 =
F_9 ( V_35 -> V_44 . V_47 ) ;
V_9 -> V_28 . V_48 =
F_9 ( V_35 -> V_44 . V_49 ) ;
V_9 -> V_28 . V_50 =
F_10 ( V_35 -> V_44 . V_51 ) ;
if ( V_35 -> V_44 . V_52 == 0 )
V_9 -> V_28 . V_53 = 203 ;
else
V_9 -> V_28 . V_53 = V_35 -> V_44 . V_52 ;
if ( V_35 -> V_44 . V_54 == 0 )
V_9 -> V_28 . V_55 = 5 ;
else
V_9 -> V_28 . V_55 = V_35 -> V_44 . V_54 ;
if ( V_9 -> V_28 . V_53 <= V_9 -> V_28 . V_55 ) {
F_8 ( L_2 ) ;
return - V_42 ;
}
if ( F_9 ( V_35 -> V_44 . V_56 ) & ( 1 << 3 ) &&
V_9 -> V_57 )
V_9 -> V_28 . V_58 = true ;
else
V_9 -> V_28 . V_58 = false ;
for ( V_39 = 0 ; V_39 < V_59 ; V_39 ++ ) {
if ( V_39 < V_60 )
V_9 -> V_28 . V_29 [ V_39 ] =
F_9 ( V_35 -> V_44 . V_61 [ V_39 ] ) ;
V_9 -> V_28 . V_62 [ V_39 ] =
F_9 ( V_35 -> V_44 . V_63 [ V_39 ] ) ;
}
for ( V_39 = 0 ; V_39 < V_64 ; V_39 ++ )
V_9 -> V_28 . V_65 [ V_39 ] =
F_9 ( V_35 -> V_44 . V_66 [ V_39 ] . V_67 ) ;
for ( V_39 = 0 ; V_39 < V_59 ; V_39 ++ )
V_9 -> V_28 . V_68 [ V_39 ] =
F_9 ( V_35 -> V_44 . V_69 [ V_39 ] ) ;
if ( F_9 ( V_35 -> V_44 . V_70 ) &
V_71 )
V_9 -> V_72 = true ;
V_9 -> V_28 . V_73 =
V_35 -> V_44 . V_74 ;
F_4 ( V_8 ,
& V_8 -> V_10 . V_11 . V_19 . V_75 ) ;
}
return 0 ;
}
static void F_11 ( struct V_7 * V_8 )
{
int V_39 ;
struct V_76 * V_77 =
& V_8 -> V_10 . V_11 . V_19 . V_78 ;
struct V_79 * V_80 =
& V_8 -> V_10 . V_11 . V_19 . V_81 ;
struct V_17 * V_82 =
& V_8 -> V_10 . V_11 . V_19 . V_83 ;
if ( V_77 -> V_21 ) {
for ( V_39 = 0 ; V_39 < V_77 -> V_21 ; V_39 ++ )
V_77 -> V_23 [ V_39 ] . V_26 =
F_3 ( V_8 ,
V_77 -> V_23 [ V_39 ] . V_26 ) ;
}
if ( V_80 -> V_21 ) {
for ( V_39 = 0 ; V_39 < V_80 -> V_21 ; V_39 ++ )
V_80 -> V_23 [ V_39 ] . V_26 =
F_3 ( V_8 ,
V_80 -> V_23 [ V_39 ] . V_26 ) ;
}
if ( V_82 -> V_21 ) {
for ( V_39 = 0 ; V_39 < V_82 -> V_21 ; V_39 ++ )
V_82 -> V_23 [ V_39 ] . V_26 =
F_3 ( V_8 ,
V_82 -> V_23 [ V_39 ] . V_26 ) ;
}
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_84 . V_22 = V_9 -> V_28 . V_43 ;
V_9 -> V_84 . V_85 = V_9 -> V_28 . V_50 ;
V_9 -> V_84 . V_86 = 0 ;
V_9 -> V_84 . V_87 = 0 ;
V_9 -> V_84 . V_88 = 1 ;
V_9 -> V_84 . V_89 = 0 ;
V_9 -> V_84 . V_90 = 0 ;
V_9 -> V_84 . V_91 = 0 ;
}
static void F_13 ( struct V_7 * V_8 ,
struct V_1 * V_4 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_4 -> V_92 = 1 ;
V_4 -> V_93 [ 0 ] = V_9 -> V_84 ;
}
static void F_14 ( struct V_7 * V_8 ,
struct V_2 * V_3 , int V_32 ,
union V_94 * V_95 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_96 * V_97 = & V_4 -> V_93 [ V_32 ] ;
struct V_17 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_20 ;
V_97 -> V_22 = V_16 -> V_23 [ V_95 -> V_98 . V_32 ] . V_24 ;
V_97 -> V_85 = V_16 -> V_23 [ V_95 -> V_98 . V_32 ] . V_26 ;
V_4 -> V_92 = V_32 + 1 ;
if ( V_9 -> V_99 ) {
V_97 -> V_86 = 5 ;
V_97 -> V_87 = 5 ;
}
}
static void F_15 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_100 * V_101 ,
T_2 V_102 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_3 -> V_103 = F_9 ( V_101 -> V_104 ) ;
V_3 -> V_105 = F_10 ( V_101 -> V_106 ) ;
V_3 -> V_107 = F_10 ( V_101 -> V_108 ) ;
if ( V_109 < V_102 ) {
V_3 -> V_110 = F_9 ( V_101 -> V_111 ) ;
V_3 -> V_112 = F_9 ( V_101 -> V_113 ) ;
} else {
V_3 -> V_110 = 0 ;
V_3 -> V_112 = 0 ;
}
if ( V_3 -> V_105 & V_114 ) {
V_8 -> V_10 . V_11 . V_115 = V_3 ;
F_13 ( V_8 , V_4 ) ;
}
if ( V_3 -> V_105 & V_116 )
V_8 -> V_10 . V_11 . V_117 = V_3 ;
}
static int F_16 ( struct V_7 * V_8 )
{
struct V_30 * V_31 = & V_8 -> V_31 ;
struct V_100 * V_101 ;
union V_118 * V_119 ;
int V_39 , V_120 , V_121 , V_122 , V_123 ;
union V_94 * V_95 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
union V_130 * V_130 ;
int V_32 = F_6 ( V_33 , V_131 ) ;
T_3 V_38 ;
T_2 V_36 , V_37 ;
T_2 * V_132 ;
struct V_1 * V_4 ;
if ( ! F_7 ( V_31 -> V_40 , V_32 , NULL ,
& V_36 , & V_37 , & V_38 ) )
return - V_42 ;
V_130 = (union V_130 * ) ( V_31 -> V_40 -> V_41 + V_38 ) ;
V_125 = (struct V_124 * )
( V_31 -> V_40 -> V_41 + V_38 +
F_10 ( V_130 -> V_133 . V_134 ) ) ;
V_127 = (struct V_126 * )
( V_31 -> V_40 -> V_41 + V_38 +
F_10 ( V_130 -> V_133 . V_135 ) ) ;
V_129 = (struct V_128 * )
( V_31 -> V_40 -> V_41 + V_38 +
F_10 ( V_130 -> V_133 . V_136 ) ) ;
V_8 -> V_10 . V_11 . V_4 = F_17 ( sizeof( struct V_2 ) *
V_125 -> V_137 , V_138 ) ;
if ( ! V_8 -> V_10 . V_11 . V_4 )
return - V_139 ;
V_132 = ( T_2 * ) V_125 -> V_140 ;
V_8 -> V_10 . V_11 . V_141 =
F_9 ( V_130 -> V_133 . V_142 ) ;
V_8 -> V_10 . V_11 . V_143 =
F_10 ( V_130 -> V_133 . V_144 ) ;
V_8 -> V_10 . V_11 . V_145 =
F_10 ( V_130 -> V_133 . V_146 ) ;
for ( V_39 = 0 ; V_39 < V_125 -> V_137 ; V_39 ++ ) {
V_119 = (union V_118 * ) V_132 ;
V_122 = V_119 -> V_147 . V_148 ;
V_101 = (struct V_100 * )
& V_129 -> V_149 [ V_122 ] ;
V_4 = F_17 ( sizeof( struct V_1 ) , V_138 ) ;
if ( V_4 == NULL ) {
for ( V_120 = 0 ; V_120 < V_39 ; V_120 ++ )
F_18 ( V_8 -> V_10 . V_11 . V_4 [ V_120 ] . V_5 ) ;
F_18 ( V_8 -> V_10 . V_11 . V_4 ) ;
return - V_139 ;
}
V_8 -> V_10 . V_11 . V_4 [ V_39 ] . V_5 = V_4 ;
V_121 = 0 ;
for ( V_120 = 0 ; V_120 < V_119 -> V_147 . V_150 ; V_120 ++ ) {
V_123 = V_119 -> V_147 . V_151 [ V_120 ] ;
if ( V_123 >= V_127 -> V_137 )
continue;
if ( V_121 >= V_152 )
break;
V_95 = (union V_94 * )
& V_127 -> V_153 [ V_123 *
V_127 -> V_154 ] ;
F_14 ( V_8 , & V_8 -> V_10 . V_11 . V_4 [ V_39 ] ,
V_121 , V_95 ) ;
V_121 ++ ;
}
F_15 ( V_8 , & V_8 -> V_10 . V_11 . V_4 [ V_39 ] ,
V_101 ,
V_129 -> V_154 ) ;
V_132 += 2 + V_119 -> V_147 . V_150 ;
}
V_8 -> V_10 . V_11 . V_155 = V_125 -> V_137 ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_4 V_14 ;
int V_156 ;
V_156 = F_20 ( V_8 , V_157 +
F_21 ( struct V_158 ,
V_159 ) ,
& V_14 , V_9 -> V_160 ) ;
if ( V_156 == 0 )
V_9 -> V_161 = V_14 ;
return V_156 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
int V_156 , V_39 ;
V_9 = F_17 ( sizeof( struct V_6 ) , V_138 ) ;
if ( NULL == V_9 )
return - V_139 ;
V_8 -> V_10 . V_11 . V_12 = V_9 ;
V_156 = F_23 ( V_8 ) ;
if ( V_156 )
goto V_162;
V_156 = F_24 ( V_8 ) ;
if ( V_156 )
goto V_162;
V_9 -> V_160 = V_163 ;
for ( V_39 = 0 ; V_39 < V_152 ; V_39 ++ )
V_9 -> V_164 [ V_39 ] = V_165 ;
V_9 -> V_166 = 0x0 ;
V_9 -> V_167 = 0x0 ;
V_9 -> V_168 = 25000 ;
V_9 -> V_169 = 1 ;
V_9 -> V_57 = false ;
V_9 -> V_170 = true ;
V_9 -> V_171 = true ;
V_9 -> V_172 = false ;
if ( V_9 -> V_172 ) {
V_9 -> V_173 = true ;
V_9 -> V_174 = true ;
V_9 -> V_175 = true ;
V_9 -> V_176 = true ;
}
if ( V_177 )
V_9 -> V_99 = true ;
else
V_9 -> V_99 = false ;
V_9 -> V_178 = 0x00c00033 ;
V_9 -> V_179 = true ;
V_9 -> V_180 = false ;
V_9 -> V_181 = false ;
V_9 -> V_182 = 0 ;
V_9 -> V_183 = false ;
V_9 -> V_184 = 500 ;
V_9 -> V_185 = true ;
V_9 -> V_186 = ( V_8 -> V_187 & V_188 ) ? true : false ;
V_9 -> V_189 = true ;
V_9 -> V_190 = ( V_8 -> V_187 & V_191 ) ? true : false ;
V_9 -> V_192 = true ;
V_9 -> V_193 = ( V_8 -> V_187 & V_194 ) ? true : false ;
V_9 -> V_195 = true ;
V_9 -> V_196 = false ;
V_9 -> V_197 = true ;
V_9 -> V_198 = false ;
V_9 -> V_199 = false ;
V_9 -> V_200 = true ;
V_156 = F_5 ( V_8 ) ;
if ( V_156 )
goto V_162;
F_11 ( V_8 ) ;
F_12 ( V_8 ) ;
V_156 = F_16 ( V_8 ) ;
if ( V_156 )
goto V_162;
V_156 = F_19 ( V_8 ) ;
if ( V_156 )
goto V_162;
V_9 -> V_201 = true ;
V_9 -> V_202 = false ;
return 0 ;
V_162:
F_25 ( V_8 ) ;
return V_156 ;
}
static void F_25 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_10 . V_11 . V_155 ; V_39 ++ )
F_18 ( V_8 -> V_10 . V_11 . V_4 [ V_39 ] . V_5 ) ;
F_18 ( V_8 -> V_10 . V_11 . V_4 ) ;
F_18 ( V_8 -> V_10 . V_11 . V_12 ) ;
F_26 ( V_8 ) ;
}
static void
F_27 ( struct V_7 * V_8 ,
struct V_203 * V_204 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_17 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_20 ;
struct V_76 * V_77 =
& V_8 -> V_10 . V_11 . V_19 . V_78 ;
struct V_79 * V_80 =
& V_8 -> V_10 . V_11 . V_19 . V_81 ;
T_4 V_205 = F_28 ( F_29 ( V_206 ) ,
V_207 , V_208 ) ;
T_4 V_209 = F_28 ( F_29 ( V_210 ) ,
V_211 , V_212 ) ;
T_4 V_213 = F_28 ( F_29 ( V_210 ) ,
V_211 , V_214 ) ;
T_4 V_22 , V_110 , V_112 , V_215 , V_14 ;
T_3 V_216 , V_217 ;
if ( V_205 >= V_218 ) {
F_30 ( V_204 , L_3 , V_205 ) ;
} else {
V_22 = V_16 -> V_23 [ V_205 ] . V_24 ;
F_30 ( V_204 , L_4 , V_205 , V_22 ) ;
}
V_14 = ( F_29 ( V_219 ) &
V_220 ) >> V_221 ;
V_216 = F_3 ( V_8 , ( T_3 ) V_14 ) ;
V_14 = ( F_29 ( V_222 ) &
V_223 ) >> V_224 ;
V_217 = F_3 ( V_8 , ( T_3 ) V_14 ) ;
F_30 ( V_204 , L_5 , V_216 , V_217 ) ;
F_30 ( V_204 , L_6 , V_9 -> V_225 ? L_7 : L_8 ) ;
if ( ! V_9 -> V_225 ) {
if ( V_209 >= V_152 ) {
F_30 ( V_204 , L_9 , V_209 ) ;
} else {
V_110 = V_77 -> V_23 [ V_209 ] . V_110 ;
V_112 = V_77 -> V_23 [ V_209 ] . V_112 ;
F_30 ( V_204 , L_10 , V_209 , V_110 , V_112 ) ;
}
}
F_30 ( V_204 , L_11 , V_9 -> V_226 ? L_7 : L_8 ) ;
if ( ! V_9 -> V_226 ) {
if ( V_213 >= V_152 ) {
F_30 ( V_204 , L_12 , V_213 ) ;
} else {
V_215 = V_80 -> V_23 [ V_213 ] . V_215 ;
F_30 ( V_204 , L_13 , V_213 , V_215 ) ;
}
}
}
static void F_31 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
int V_39 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_32 ( V_3 -> V_105 , V_3 -> V_107 ) ;
F_33 ( V_3 -> V_103 ) ;
F_34 ( L_14 , V_3 -> V_110 , V_3 -> V_112 ) ;
for ( V_39 = 0 ; V_39 < V_4 -> V_92 ; V_39 ++ ) {
struct V_96 * V_97 = & V_4 -> V_93 [ V_39 ] ;
F_34 ( L_15 ,
V_39 , V_97 -> V_22 ,
F_3 ( V_8 , V_97 -> V_85 ) ) ;
}
F_35 ( V_8 , V_3 ) ;
}
static int F_36 ( void * V_227 )
{
struct V_7 * V_8 = (struct V_7 * ) V_227 ;
F_37 ( V_8 ) ;
return 0 ;
}
static int F_38 ( void * V_227 )
{
struct V_7 * V_8 = (struct V_7 * ) V_227 ;
if ( V_228 ) {
int V_156 ;
V_156 = F_39 ( V_8 ) ;
if ( V_156 )
return V_156 ;
F_40 ( V_8 , true ) ;
F_41 ( V_8 , true ) ;
}
return 0 ;
}
static int F_42 ( void * V_227 )
{
struct V_7 * V_8 = (struct V_7 * ) V_227 ;
int V_156 = 0 ;
V_8 -> V_10 . V_11 . V_229 = V_230 ;
V_8 -> V_10 . V_11 . V_231 = V_230 ;
V_8 -> V_10 . V_11 . V_232 = V_233 ;
V_8 -> V_10 . V_234 = V_8 -> clock . V_234 ;
V_8 -> V_10 . V_235 = V_8 -> clock . V_235 ;
V_8 -> V_10 . V_236 = V_8 -> clock . V_234 ;
V_8 -> V_10 . V_237 = V_8 -> clock . V_235 ;
V_8 -> V_10 . V_238 = V_239 ;
if ( V_228 == 0 )
return 0 ;
F_43 ( & V_8 -> V_10 . V_240 ) ;
V_156 = F_22 ( V_8 ) ;
if ( V_156 )
goto V_241;
V_8 -> V_10 . V_11 . V_242 = V_8 -> V_10 . V_11 . V_243 = V_8 -> V_10 . V_11 . V_115 ;
if ( V_228 == 1 )
F_44 ( V_8 ) ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
F_34 ( L_16 ) ;
return 0 ;
V_241:
F_25 ( V_8 ) ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
F_8 ( L_17 ) ;
return V_156 ;
}
static int F_46 ( void * V_227 )
{
struct V_7 * V_8 = (struct V_7 * ) V_227 ;
F_43 ( & V_8 -> V_10 . V_240 ) ;
F_47 ( V_8 ) ;
F_25 ( V_8 ) ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
return 0 ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_244 = 0 ;
}
static int F_49 ( struct V_7 * V_8 ,
void * * V_16 )
{
return F_50 ( V_8 , V_16 ) ;
}
static int F_51 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_245 * V_246 ;
struct V_247 V_248 ;
void * V_16 = NULL ;
T_5 V_39 = 0 ;
int V_156 = 0 ;
struct V_17 * V_249 =
& V_8 -> V_10 . V_11 . V_19 . V_20 ;
struct V_17 * V_250 =
& V_8 -> V_10 . V_11 . V_19 . V_251 ;
struct V_76 * V_77 =
& V_8 -> V_10 . V_11 . V_19 . V_78 ;
struct V_79 * V_80 =
& V_8 -> V_10 . V_11 . V_19 . V_81 ;
struct V_17 * V_82 =
& V_8 -> V_10 . V_11 . V_19 . V_83 ;
if ( ! V_9 -> V_200 )
return 0 ;
V_156 = F_49 ( V_8 , & V_16 ) ;
if ( V_156 ) {
F_8 ( L_18 ) ;
return - V_42 ;
}
V_246 = (struct V_245 * ) V_16 ;
if ( V_249 -> V_21 > V_152 ||
V_250 -> V_21 > V_152 ||
V_77 -> V_21 > V_152 ||
V_80 -> V_21 > V_152 ||
V_82 -> V_21 > V_152 ) {
F_8 ( L_19 ) ;
return - V_42 ;
}
for ( V_39 = 0 ; V_39 < V_152 ; V_39 ++ ) {
V_246 -> V_252 . V_253 [ V_39 ] . V_254 =
( V_39 < V_249 -> V_21 ) ? ( T_5 ) V_249 -> V_23 [ V_39 ] . V_26 : 0 ;
V_246 -> V_252 . V_253 [ V_39 ] . V_255 =
( V_39 < V_249 -> V_21 ) ? V_249 -> V_23 [ V_39 ] . V_24 : 0 ;
V_156 = F_52 ( V_8 , V_256 ,
V_246 -> V_252 . V_253 [ V_39 ] . V_255 ,
false , & V_248 ) ;
if ( V_156 )
return V_156 ;
V_246 -> V_252 . V_253 [ V_39 ] . V_257 =
( T_5 ) V_248 . V_258 ;
V_246 -> V_252 . V_253 [ V_39 ] . V_259 =
( V_39 < V_250 -> V_21 ) ? ( T_5 ) V_250 -> V_23 [ V_39 ] . V_26 : 0 ;
V_246 -> V_260 . V_253 [ V_39 ] . V_259 =
( V_39 < V_82 -> V_21 ) ? ( T_5 ) V_82 -> V_23 [ V_39 ] . V_26 : 0 ;
V_246 -> V_260 . V_253 [ V_39 ] . V_255 =
( V_39 < V_82 -> V_21 ) ? V_82 -> V_23 [ V_39 ] . V_24 : 0 ;
V_156 = F_52 ( V_8 , V_256 ,
V_246 -> V_252 . V_253 [ V_39 ] . V_255 ,
false , & V_248 ) ;
if ( V_156 )
return V_156 ;
V_246 -> V_260 . V_253 [ V_39 ] . V_257 =
( T_5 ) V_248 . V_258 ;
V_246 -> V_261 . V_253 [ V_39 ] . V_259 =
( V_39 < V_77 -> V_21 ) ? ( T_5 ) V_77 -> V_23 [ V_39 ] . V_26 : 0 ;
V_246 -> V_261 . V_253 [ V_39 ] . V_255 =
( V_39 < V_77 -> V_21 ) ? V_77 -> V_23 [ V_39 ] . V_110 : 0 ;
V_156 = F_52 ( V_8 , V_256 ,
V_246 -> V_261 . V_253 [ V_39 ] . V_255 ,
false , & V_248 ) ;
if ( V_156 )
return V_156 ;
V_246 -> V_261 . V_253 [ V_39 ] . V_257 =
( T_5 ) V_248 . V_258 ;
V_246 -> V_262 . V_253 [ V_39 ] . V_259 =
( V_39 < V_77 -> V_21 ) ? ( T_5 ) V_77 -> V_23 [ V_39 ] . V_26 : 0 ;
V_246 -> V_262 . V_253 [ V_39 ] . V_255 =
( V_39 < V_77 -> V_21 ) ? V_77 -> V_23 [ V_39 ] . V_112 : 0 ;
V_156 = F_52 ( V_8 , V_256 ,
V_246 -> V_262 . V_253 [ V_39 ] . V_255 ,
false , & V_248 ) ;
if ( V_156 )
return V_156 ;
V_246 -> V_262 . V_253 [ V_39 ] . V_257 =
( T_5 ) V_248 . V_258 ;
V_246 -> V_263 . V_253 [ V_39 ] . V_259 =
( V_39 < V_80 -> V_21 ) ? ( T_5 ) V_80 -> V_23 [ V_39 ] . V_26 : 0 ;
V_246 -> V_263 . V_253 [ V_39 ] . V_255 =
( V_39 < V_80 -> V_21 ) ? V_80 -> V_23 [ V_39 ] . V_215 : 0 ;
V_156 = F_52 ( V_8 , V_256 ,
V_246 -> V_263 . V_253 [ V_39 ] . V_255 ,
false , & V_248 ) ;
if ( V_156 )
return V_156 ;
V_246 -> V_263 . V_253 [ V_39 ] . V_257 =
( T_5 ) V_248 . V_258 ;
}
V_156 = F_53 ( V_8 ) ;
if ( V_156 ) {
F_8 ( L_20 ) ;
return V_156 ;
}
return 0 ;
}
static void F_54 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_17 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_20 ;
T_6 clock = 0 , V_264 ;
if ( ! V_16 || ! V_16 -> V_21 ) {
F_8 ( L_21 ) ;
return;
}
V_9 -> V_265 . V_266 = 0 ;
V_9 -> V_265 . V_267 = 0 ;
F_55 ( V_8 , V_268 ) ;
V_264 = F_56 ( V_8 ) ;
if ( V_264 < V_16 -> V_21 ) {
clock = V_16 -> V_23 [ V_264 ] . V_24 ;
} else {
F_8 ( L_22 ) ;
clock = V_16 -> V_23 [ V_16 -> V_21 - 1 ] . V_24 ;
}
V_9 -> V_265 . V_269 = clock ;
V_9 -> V_265 . V_270 = clock ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_76 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_78 ;
T_6 clock = 0 , V_264 ;
if ( ! V_16 || ! V_16 -> V_21 ) {
F_8 ( L_21 ) ;
return;
}
V_9 -> V_271 . V_266 = 0 ;
V_9 -> V_271 . V_267 = 0 ;
F_55 ( V_8 , V_272 ) ;
V_264 = F_56 ( V_8 ) ;
if ( V_264 < V_16 -> V_21 ) {
clock = V_16 -> V_23 [ V_264 ] . V_110 ;
} else {
F_8 ( L_23 ) ;
clock = V_16 -> V_23 [ V_16 -> V_21 - 1 ] . V_110 ;
}
V_9 -> V_271 . V_269 = clock ;
V_9 -> V_271 . V_270 = clock ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_79 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_81 ;
T_6 clock = 0 , V_264 ;
if ( ! V_16 || ! V_16 -> V_21 ) {
F_8 ( L_21 ) ;
return;
}
V_9 -> V_273 . V_266 = V_16 -> V_23 [ 0 ] . V_215 ;
V_9 -> V_273 . V_267 = V_16 -> V_23 [ 0 ] . V_215 ;
F_55 ( V_8 , V_274 ) ;
V_264 = F_56 ( V_8 ) ;
if ( V_264 < V_16 -> V_21 ) {
clock = V_16 -> V_23 [ V_264 ] . V_215 ;
} else {
F_8 ( L_24 ) ;
clock = V_16 -> V_23 [ V_16 -> V_21 - 1 ] . V_215 ;
}
V_9 -> V_273 . V_269 = clock ;
V_9 -> V_273 . V_270 = clock ;
}
static void F_59 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_17 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_83 ;
T_6 clock = 0 , V_264 ;
if ( ! V_16 || ! V_16 -> V_21 ) {
F_8 ( L_21 ) ;
return;
}
V_9 -> V_275 . V_266 = 0 ;
V_9 -> V_275 . V_267 = 0 ;
F_55 ( V_8 , V_276 ) ;
V_264 = F_56 ( V_8 ) ;
if ( V_264 < V_16 -> V_21 ) {
clock = V_16 -> V_23 [ V_264 ] . V_24 ;
} else {
F_8 ( L_25 ) ;
clock = V_16 -> V_23 [ V_16 -> V_21 - 1 ] . V_24 ;
}
V_9 -> V_275 . V_269 = clock ;
V_9 -> V_275 . V_270 = clock ;
}
static void F_60 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_225 = false ;
V_9 -> V_226 = false ;
V_9 -> V_277 = false ;
}
static void F_61 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_278 = 0 ;
}
static void F_62 ( struct V_7 * V_8 )
{
F_48 ( V_8 ) ;
F_51 ( V_8 ) ;
F_54 ( V_8 ) ;
F_57 ( V_8 ) ;
F_58 ( V_8 ) ;
F_59 ( V_8 ) ;
F_60 ( V_8 ) ;
F_61 ( V_8 ) ;
}
static bool F_63 ( struct V_7 * V_8 ,
T_6 V_279 )
{
T_6 V_280 = 0 ;
int V_156 ;
V_156 = F_64 ( V_8 ,
V_281 , 0 ) ;
if ( V_156 ) {
F_8 ( L_26 ) ;
return false ;
} else {
V_280 = F_56 ( V_8 ) ;
if ( V_279 & V_280 )
return true ;
}
return false ;
}
static bool F_65 ( struct V_7 * V_8 )
{
if ( F_63 ( V_8 ,
V_282 ) )
return true ;
return false ;
}
static void F_66 ( struct V_7 * V_8 )
{
F_67 ( V_283 , V_284 ) ;
}
static void F_68 ( struct V_7 * V_8 )
{
F_67 ( V_283 , 0 ) ;
}
static int F_69 ( struct V_7 * V_8 )
{
int V_156 = 0 ;
if ( V_228 ) {
V_156 = F_64 ( V_8 ,
V_285 , V_286 ) ;
if ( V_156 ) {
F_8 ( L_27 ) ;
return - V_42 ;
}
}
return 0 ;
}
static int F_70 ( struct V_7 * V_8 )
{
int V_156 = 0 ;
if ( V_228 && V_8 -> V_10 . V_201 ) {
V_156 = F_64 ( V_8 ,
V_287 , V_286 ) ;
if ( V_156 ) {
F_8 ( L_28 ) ;
return - V_42 ;
}
}
return 0 ;
}
static T_6 F_71 ( struct V_7 * V_8 ,
T_6 clock , T_1 V_288 )
{
int V_39 = 0 ;
struct V_17 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_20 ;
switch ( V_288 ) {
case V_289 :
case V_290 :
for ( V_39 = 0 ; V_39 < V_16 -> V_21 ; V_39 ++ )
if ( clock <= V_16 -> V_23 [ V_39 ] . V_24 )
break;
if ( V_39 == V_16 -> V_21 )
V_39 = V_16 -> V_21 - 1 ;
break;
case V_291 :
case V_292 :
for ( V_39 = V_16 -> V_21 - 1 ; V_39 >= 0 ; V_39 -- )
if ( clock >= V_16 -> V_23 [ V_39 ] . V_24 )
break;
if ( V_39 < 0 )
V_39 = 0 ;
break;
default:
break;
}
return V_39 ;
}
static T_6 F_72 ( struct V_7 * V_8 ,
T_6 clock , T_1 V_288 )
{
int V_39 = 0 ;
struct V_79 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_81 ;
if ( V_16 -> V_21 == 0 )
return 0 ;
switch ( V_288 ) {
case V_293 :
case V_294 :
for ( V_39 = 0 ; V_39 < V_16 -> V_21 - 1 ; V_39 ++ )
if ( clock <= V_16 -> V_23 [ V_39 ] . V_215 )
break;
break;
case V_295 :
case V_296 :
for ( V_39 = V_16 -> V_21 - 1 ; V_39 > 0 ; V_39 -- )
if ( clock >= V_16 -> V_23 [ V_39 ] . V_215 )
break;
break;
default:
break;
}
return V_39 ;
}
static T_6 F_73 ( struct V_7 * V_8 ,
T_6 clock , T_1 V_288 )
{
int V_39 = 0 ;
struct V_76 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_78 ;
switch ( V_288 ) {
case V_297 :
case V_298 :
for ( V_39 = 0 ; V_39 < V_16 -> V_21 ; V_39 ++ )
if ( clock <= V_16 -> V_23 [ V_39 ] . V_110 )
break;
if ( V_39 == V_16 -> V_21 )
V_39 = V_16 -> V_21 - 1 ;
break;
case V_299 :
case V_300 :
for ( V_39 = V_16 -> V_21 - 1 ; V_39 >= 0 ; V_39 -- )
if ( clock >= V_16 -> V_23 [ V_39 ] . V_110 )
break;
if ( V_39 < 0 )
V_39 = 0 ;
break;
default:
break;
}
return V_39 ;
}
static int F_74 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_6 V_266 = 0 ;
T_6 V_269 = 0 ;
int V_156 = 0 ;
V_9 -> V_265 . V_266 = V_9 -> V_28 . V_43 ;
V_9 -> V_265 . V_269 = V_9 -> V_28 . V_43 ;
V_266 = F_71 ( V_8 ,
V_9 -> V_265 . V_266 ,
V_289 ) ;
V_269 = F_71 ( V_8 ,
V_9 -> V_265 . V_269 ,
V_291 ) ;
V_156 = F_64 ( V_8 ,
V_289 , V_266 ) ;
if ( V_156 )
return - V_42 ;
V_156 = F_64 ( V_8 ,
V_291 , V_269 ) ;
if ( V_156 )
return - V_42 ;
return 0 ;
}
static int F_75 ( struct V_7 * V_8 )
{
return 0 ;
}
static int F_76 ( struct V_7 * V_8 )
{
return 0 ;
}
static int F_77 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_78 ( struct V_7 * V_8 , bool V_301 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_6 V_302 = 0 ;
if ( V_9 -> V_173 ) {
V_302 = F_79 ( V_303 ) ;
if ( V_301 )
V_302 = F_80 ( V_302 , V_304 , V_305 , 1 ) ;
else
V_302 = F_80 ( V_302 , V_304 , V_305 , 0 ) ;
F_81 ( V_303 , V_302 ) ;
}
if ( V_9 -> V_174 ) {
V_302 = F_79 ( V_306 ) ;
if ( V_301 )
V_302 = F_80 ( V_302 , V_307 , V_305 , 1 ) ;
else
V_302 = F_80 ( V_302 , V_307 , V_305 , 0 ) ;
F_81 ( V_306 , V_302 ) ;
}
if ( V_9 -> V_175 ) {
V_302 = F_79 ( V_308 ) ;
if ( V_301 )
V_302 = F_80 ( V_302 , V_309 , V_305 , 1 ) ;
else
V_302 = F_80 ( V_302 , V_309 , V_305 , 0 ) ;
F_81 ( V_308 , V_302 ) ;
}
if ( V_9 -> V_176 ) {
V_302 = F_79 ( V_310 ) ;
if ( V_301 )
V_302 = F_80 ( V_302 , V_304 , V_305 , 1 ) ;
else
V_302 = F_80 ( V_302 , V_304 , V_305 , 0 ) ;
F_81 ( V_310 , V_302 ) ;
}
}
static int F_82 ( struct V_7 * V_8 , bool V_301 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 ;
if ( V_9 -> V_173 || V_9 -> V_174 ||
V_9 -> V_175 || V_9 -> V_176 ) {
if ( V_8 -> V_311 . V_312 != V_313 ) {
V_156 = F_75 ( V_8 ) ;
if ( V_156 ) {
F_8 ( L_29 ) ;
return - V_42 ;
}
V_8 -> V_311 . V_312 = V_313 ;
}
V_156 = F_77 ( V_8 ) ;
if ( V_156 ) {
F_8 ( L_30 ) ;
return - V_42 ;
}
F_78 ( V_8 , V_301 ) ;
if ( V_8 -> V_311 . V_312 == V_313 ) {
V_156 = F_76 ( V_8 ) ;
if ( V_156 ) {
F_8 ( L_31 ) ;
return - V_42 ;
}
V_8 -> V_311 . V_312 = V_314 ;
}
}
return 0 ;
}
static void F_83 ( struct V_7 * V_8 )
{
}
static void F_84 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_9 -> V_242 = * V_4 ;
V_9 -> V_315 = * V_3 ;
V_9 -> V_315 . V_5 = V_4 ;
}
static void F_85 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_9 -> V_243 = * V_4 ;
V_9 -> V_316 = * V_3 ;
V_9 -> V_316 . V_5 = V_4 ;
}
static void F_86 ( struct V_7 * V_8 ,
struct V_2 * V_317 ,
struct V_2 * V_318 )
{
struct V_1 * V_4 = F_1 ( V_317 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_15 * V_319 =
& V_8 -> V_10 . V_11 . V_19 . V_75 ;
T_6 V_27 = 0 ;
V_4 -> V_320 = false ;
V_4 -> V_321 = true ;
V_9 -> V_322 = V_317 -> V_112 || V_317 -> V_110 ||
V_317 -> V_323 || V_317 -> V_215 ;
if ( ( V_317 -> V_105 & V_324 ) ==
V_325 )
V_9 -> V_326 = true ;
else
V_9 -> V_326 = false ;
if ( V_9 -> V_196 )
V_27 = V_319 -> V_27 ;
if ( V_27 > V_9 -> V_28 . V_29 [ V_60 - 1 ] )
V_4 -> V_320 = true ;
}
static int F_87 ( struct V_7 * V_8 )
{
const char * V_327 ;
int V_156 = 0 ;
if ( F_65 ( V_8 ) )
return - V_42 ;
F_66 ( V_8 ) ;
switch ( V_8 -> V_328 ) {
case V_329 :
V_327 = L_32 ;
break;
case V_330 :
V_327 = L_33 ;
break;
default:
F_88 () ;
}
V_156 = F_69 ( V_8 ) ;
if ( V_156 ) {
F_8 ( L_34 , V_327 ) ;
return - V_42 ;
}
V_156 = F_74 ( V_8 ) ;
if ( V_156 ) {
F_8 ( L_35 , V_327 ) ;
return - V_42 ;
}
V_156 = F_82 ( V_8 , true ) ;
if ( V_156 ) {
F_8 ( L_36 , V_327 ) ;
return - V_42 ;
}
F_83 ( V_8 ) ;
F_84 ( V_8 , V_8 -> V_10 . V_11 . V_115 ) ;
return 0 ;
}
static int F_89 ( void * V_227 )
{
struct V_7 * V_8 = (struct V_7 * ) V_227 ;
int V_156 = 0 ;
F_43 ( & V_8 -> V_10 . V_240 ) ;
V_156 = F_90 ( V_8 ) ;
if ( V_156 ) {
F_8 ( L_37 ) ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
return V_156 ;
}
V_156 = F_91 ( V_8 ) ;
if ( V_156 ) {
F_8 ( L_38 ) ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
return V_156 ;
}
if ( ! V_228 ) {
V_8 -> V_10 . V_201 = false ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
return V_156 ;
}
F_62 ( V_8 ) ;
V_156 = F_87 ( V_8 ) ;
if ( V_156 )
V_8 -> V_10 . V_201 = false ;
else
V_8 -> V_10 . V_201 = true ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
return 0 ;
}
static int F_92 ( struct V_7 * V_8 )
{
int V_156 = 0 ;
if ( ! F_65 ( V_8 ) )
return - V_42 ;
V_156 = F_82 ( V_8 , false ) ;
if ( V_156 ) {
F_8 ( L_39 ) ;
return - V_42 ;
}
F_40 ( V_8 , false ) ;
F_41 ( V_8 , false ) ;
F_68 ( V_8 ) ;
F_70 ( V_8 ) ;
F_84 ( V_8 , V_8 -> V_10 . V_11 . V_115 ) ;
return 0 ;
}
static int F_93 ( void * V_227 )
{
int V_156 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_227 ;
F_43 ( & V_8 -> V_10 . V_240 ) ;
F_94 ( V_8 ) ;
if ( V_8 -> V_10 . V_201 ) {
V_156 = F_92 ( V_8 ) ;
V_8 -> V_10 . V_11 . V_242 =
V_8 -> V_10 . V_11 . V_243 =
V_8 -> V_10 . V_11 . V_115 ;
}
V_8 -> V_10 . V_201 = false ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
return V_156 ;
}
static int F_95 ( void * V_227 )
{
int V_156 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_227 ;
if ( V_8 -> V_10 . V_201 ) {
F_43 ( & V_8 -> V_10 . V_240 ) ;
V_156 = F_92 ( V_8 ) ;
V_8 -> V_10 . V_11 . V_242 =
V_8 -> V_10 . V_11 . V_243 =
V_8 -> V_10 . V_11 . V_115 ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
}
return V_156 ;
}
static int F_96 ( void * V_227 )
{
int V_156 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_227 ;
F_43 ( & V_8 -> V_10 . V_240 ) ;
V_156 = F_91 ( V_8 ) ;
if ( V_156 ) {
F_8 ( L_38 ) ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
return V_156 ;
}
if ( ! V_228 ) {
V_8 -> V_10 . V_201 = false ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
return V_156 ;
}
F_62 ( V_8 ) ;
V_156 = F_87 ( V_8 ) ;
if ( V_156 )
V_8 -> V_10 . V_201 = false ;
else
V_8 -> V_10 . V_201 = true ;
F_45 ( & V_8 -> V_10 . V_240 ) ;
if ( V_8 -> V_10 . V_201 )
F_97 ( V_8 ) ;
return 0 ;
}
static int F_98 ( void * V_227 ,
enum V_331 V_229 )
{
return 0 ;
}
static int F_99 ( void * V_227 ,
enum V_332 V_229 )
{
return 0 ;
}
static int F_100 ( struct V_7 * V_8 )
{
int V_333 = 0 ;
T_6 V_334 = F_29 ( V_335 ) ;
T_6 V_336 = F_28 ( V_334 , V_337 , V_338 ) ;
if ( F_28 ( V_334 , V_337 , V_339 ) )
V_333 = 1000 * ( ( V_336 / 8 ) - 49 ) ;
else
V_333 = 1000 * ( V_336 / 8 ) ;
return V_333 ;
}
static int F_101 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 V_243 = * V_8 -> V_10 . V_11 . V_243 ;
struct V_2 * V_340 = & V_243 ;
F_85 ( V_8 , V_340 ) ;
F_86 ( V_8 , & V_9 -> V_316 ,
& V_9 -> V_315 ) ;
return 0 ;
}
static int F_102 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_15 * V_319 =
& V_8 -> V_10 . V_11 . V_19 . V_75 ;
T_6 clock , V_341 = 0 ;
clock = V_9 -> V_265 . V_266 ;
if ( V_9 -> V_196 ) {
V_341 = V_319 -> V_22 * 75 / 100 ;
if ( clock < V_341 )
clock = V_341 ;
}
if ( clock != V_9 -> V_265 . V_266 ) {
V_9 -> V_265 . V_266 = clock ;
F_64 ( V_8 ,
V_289 ,
F_71 ( V_8 , clock ,
V_289 ) ) ;
}
if ( V_9 -> V_196 &&
V_9 -> V_265 . V_269 != clock ) {
V_9 -> V_265 . V_269 = clock ;
F_64 ( V_8 ,
V_291 ,
F_71 ( V_8 , clock ,
V_291 ) ) ;
} else {
F_64 ( V_8 ,
V_291 ,
F_71 ( V_8 ,
V_9 -> V_265 . V_269 ,
V_291 ) ) ;
}
return 0 ;
}
static int F_103 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_99 ) {
F_64 ( V_8 ,
V_342 ,
V_343 ) ;
}
return 0 ;
}
static int F_104 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_64 ( V_8 ,
V_344 ,
V_9 -> V_265 . V_269 ) ;
return 0 ;
}
static int F_105 ( struct V_7 * V_8 )
{
int V_156 = 0 ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_197 && ! V_9 -> V_198 ) {
V_156 = F_64 ( V_8 ,
V_285 ,
V_345 ) ;
if ( V_156 ) {
F_8 ( L_40 ) ;
return V_156 ;
}
V_9 -> V_198 = true ;
}
return V_156 ;
}
static void F_106 ( struct V_7 * V_8 ,
bool V_301 )
{
if ( V_301 )
F_55 ( V_8 , V_346 ) ;
else
F_55 ( V_8 , V_347 ) ;
}
static int F_107 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_4 = & V_9 -> V_243 ;
if ( V_9 -> V_28 . V_58 ) {
if ( V_4 -> V_320 )
F_106 ( V_8 , false ) ;
else
F_106 ( V_8 , true ) ;
}
return 0 ;
}
static int F_108 ( struct V_7 * V_8 )
{
F_102 ( V_8 ) ;
F_103 ( V_8 ) ;
F_104 ( V_8 ) ;
F_105 ( V_8 ) ;
F_107 ( V_8 ) ;
return 0 ;
}
static void F_109 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_4 = & V_9 -> V_316 ;
F_84 ( V_8 , V_4 ) ;
}
static int F_110 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 = 0 ;
if ( V_9 -> V_265 . V_266 != V_9 -> V_265 . V_269 ) {
V_9 -> V_265 . V_266 =
V_9 -> V_265 . V_269 ;
V_156 = F_64 ( V_8 ,
V_289 ,
F_71 ( V_8 ,
V_9 -> V_265 . V_266 ,
V_289 ) ) ;
if ( V_156 )
return V_156 ;
}
return V_156 ;
}
static int F_111 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 = 0 ;
if ( V_9 -> V_265 . V_269 != V_9 -> V_265 . V_266 ) {
V_9 -> V_265 . V_269 = V_9 -> V_265 . V_266 ;
V_156 = F_64 ( V_8 ,
V_291 ,
F_71 ( V_8 ,
V_9 -> V_265 . V_269 ,
V_291 ) ) ;
if ( V_156 )
return V_156 ;
}
return V_156 ;
}
static T_6 F_112 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( ! V_9 -> V_348 ) {
F_55 ( V_8 , V_268 ) ;
V_9 -> V_348 = F_56 ( V_8 ) + 1 ;
}
if ( V_9 -> V_348 > V_152 ) {
F_8 ( L_41 ) ;
return - V_42 ;
}
return V_9 -> V_348 ;
}
static int F_113 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_17 * V_18 =
& V_8 -> V_10 . V_11 . V_19 . V_20 ;
T_6 V_264 = 0 ;
int V_156 = 0 ;
V_9 -> V_265 . V_266 = V_18 -> V_23 [ 0 ] . V_24 ;
V_264 = F_112 ( V_8 ) - 1 ;
if ( V_264 < V_18 -> V_21 )
V_9 -> V_265 . V_269 = V_18 -> V_23 [ V_264 ] . V_24 ;
else
V_9 -> V_265 . V_269 =
V_18 -> V_23 [ V_18 -> V_21 - 1 ] . V_24 ;
V_156 = F_64 ( V_8 ,
V_289 ,
F_71 ( V_8 ,
V_9 -> V_265 . V_266 ,
V_289 ) ) ;
if ( V_156 )
return V_156 ;
V_156 = F_64 ( V_8 ,
V_291 ,
F_71 ( V_8 ,
V_9 -> V_265 . V_269 ,
V_291 ) ) ;
if ( V_156 )
return V_156 ;
F_114 ( L_42 ,
V_9 -> V_265 . V_266 ,
V_9 -> V_265 . V_269 ) ;
return 0 ;
}
static int F_115 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 = 0 ;
if ( V_9 -> V_271 . V_266 != V_9 -> V_271 . V_269 ) {
V_9 -> V_271 . V_266 =
V_9 -> V_271 . V_269 ;
V_156 = F_64 ( V_8 ,
V_297 ,
F_73 ( V_8 ,
V_9 -> V_271 . V_266 ,
V_297 ) ) ;
if ( V_156 )
return V_156 ;
}
return V_156 ;
}
static int F_116 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 = 0 ;
if ( V_9 -> V_271 . V_269 != V_9 -> V_271 . V_266 ) {
V_9 -> V_271 . V_269 = V_9 -> V_271 . V_266 ;
V_156 = F_64 ( V_8 ,
V_299 ,
F_73 ( V_8 ,
V_9 -> V_271 . V_269 ,
V_299 ) ) ;
if ( V_156 )
return V_156 ;
}
return V_156 ;
}
static T_6 F_117 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( ! V_9 -> V_349 ) {
F_55 ( V_8 , V_272 ) ;
V_9 -> V_349 = F_56 ( V_8 ) + 1 ;
}
if ( V_9 -> V_349 > V_152 ) {
F_8 ( L_43 ) ;
return - V_42 ;
}
return V_9 -> V_349 ;
}
static int F_118 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_76 * V_18 =
& V_8 -> V_10 . V_11 . V_19 . V_78 ;
T_6 V_264 = 0 ;
int V_156 = 0 ;
V_9 -> V_271 . V_266 = V_18 -> V_23 [ 0 ] . V_110 ;
V_264 = F_117 ( V_8 ) - 1 ;
if ( V_264 < V_18 -> V_21 )
V_9 -> V_271 . V_269 = V_18 -> V_23 [ V_264 ] . V_110 ;
else
V_9 -> V_271 . V_269 =
V_18 -> V_23 [ V_18 -> V_21 - 1 ] . V_110 ;
V_156 = F_64 ( V_8 ,
V_297 ,
F_73 ( V_8 ,
V_9 -> V_271 . V_266 ,
V_297 ) ) ;
if ( V_156 )
return V_156 ;
V_156 = F_64 ( V_8 ,
V_299 ,
F_73 ( V_8 ,
V_9 -> V_271 . V_269 ,
V_299 ) ) ;
if ( V_156 )
return V_156 ;
F_114 ( L_44 ,
V_9 -> V_271 . V_266 ,
V_9 -> V_271 . V_269 ) ;
return 0 ;
}
static int F_119 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 = 0 ;
if ( V_9 -> V_273 . V_266 != V_9 -> V_273 . V_269 ) {
V_9 -> V_273 . V_266 =
V_9 -> V_273 . V_269 ;
V_156 = F_64 ( V_8 ,
V_293 ,
F_72 ( V_8 ,
V_9 -> V_273 . V_266 ,
V_293 ) ) ;
if ( V_156 )
return V_156 ;
}
return V_156 ;
}
static int F_120 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 = 0 ;
if ( V_9 -> V_273 . V_269 != V_9 -> V_273 . V_266 ) {
V_9 -> V_273 . V_269 = V_9 -> V_273 . V_266 ;
V_156 = F_64 ( V_8 ,
V_295 ,
F_73 ( V_8 ,
V_9 -> V_273 . V_269 ,
V_295 ) ) ;
if ( V_156 )
return V_156 ;
}
return V_156 ;
}
static T_6 F_121 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( ! V_9 -> V_350 ) {
F_55 ( V_8 , V_274 ) ;
V_9 -> V_350 = F_56 ( V_8 ) + 1 ;
}
if ( V_9 -> V_350 > V_152 ) {
F_8 ( L_45 ) ;
return - V_42 ;
}
return V_9 -> V_350 ;
}
static int F_122 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_79 * V_18 =
& V_8 -> V_10 . V_11 . V_19 . V_81 ;
T_6 V_264 = 0 ;
int V_156 = 0 ;
V_9 -> V_273 . V_266 = V_18 -> V_23 [ 0 ] . V_215 ;
V_264 = F_121 ( V_8 ) - 1 ;
if ( V_264 < V_18 -> V_21 )
V_9 -> V_273 . V_269 = V_18 -> V_23 [ V_264 ] . V_215 ;
else
V_9 -> V_273 . V_269 =
V_18 -> V_23 [ V_18 -> V_21 - 1 ] . V_215 ;
V_156 = F_64 ( V_8 ,
V_293 ,
F_72 ( V_8 ,
V_9 -> V_273 . V_266 ,
V_293 ) ) ;
if ( V_156 )
return V_156 ;
V_156 = F_64 ( V_8 ,
V_295 ,
F_72 ( V_8 ,
V_9 -> V_273 . V_269 ,
V_295 ) ) ;
if ( V_156 )
return V_156 ;
F_114 ( L_46 ,
V_9 -> V_273 . V_266 ,
V_9 -> V_273 . V_269 ) ;
return 0 ;
}
static int F_123 ( struct V_7 * V_8 ,
enum V_351 V_264 )
{
int V_156 = 0 ;
switch ( V_264 ) {
case V_352 :
V_156 = F_113 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_110 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_118 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_115 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_122 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_119 ( V_8 ) ;
if ( V_156 )
return V_156 ;
break;
case V_353 :
V_156 = F_113 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_111 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_118 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_116 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_122 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_120 ( V_8 ) ;
if ( V_156 )
return V_156 ;
break;
case V_233 :
V_156 = F_113 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_118 ( V_8 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_122 ( V_8 ) ;
if ( V_156 )
return V_156 ;
break;
default:
break;
}
V_8 -> V_10 . V_11 . V_232 = V_264 ;
return V_156 ;
}
static void F_124 ( struct V_7 * V_8 )
{
}
static T_6 F_125 ( struct V_7 * V_8 , bool V_354 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_355 = F_1 ( & V_9 -> V_316 ) ;
if ( V_354 )
return V_355 -> V_93 [ 0 ] . V_22 ;
else
return V_355 -> V_93 [ V_355 -> V_92 - 1 ] . V_22 ;
}
static T_6 F_126 ( struct V_7 * V_8 , bool V_354 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
return V_9 -> V_28 . V_46 ;
}
static int F_127 ( struct V_7 * V_8 , bool V_301 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 = 0 ;
if ( V_301 && V_9 -> V_189 ) {
V_9 -> V_356 |= V_357 ;
F_114 ( L_47 ) ;
V_156 = F_64 ( V_8 ,
V_285 , V_358 ) ;
} else {
V_9 -> V_356 &= ~ V_357 ;
F_114 ( L_48 ) ;
V_156 = F_64 ( V_8 ,
V_287 , V_358 ) ;
}
return V_156 ;
}
static int F_128 ( struct V_7 * V_8 , bool V_359 )
{
return F_127 ( V_8 , ! V_359 ) ;
}
static void F_40 ( struct V_7 * V_8 , bool V_359 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 ;
if ( V_9 -> V_225 == V_359 )
return;
V_9 -> V_225 = V_359 ;
if ( V_359 ) {
if ( V_9 -> V_186 ) {
V_156 = F_129 ( V_8 , V_360 ,
V_361 ) ;
if ( V_156 ) {
F_8 ( L_49 ) ;
return;
}
V_156 = F_130 ( V_8 , V_360 ,
V_362 ) ;
if ( V_156 ) {
F_8 ( L_50 ) ;
return;
}
}
F_128 ( V_8 , V_359 ) ;
if ( V_9 -> V_186 ) {
V_156 = F_55 ( V_8 , V_363 ) ;
if ( V_156 ) {
F_8 ( L_51 ) ;
return;
}
}
} else {
if ( V_9 -> V_186 ) {
if ( V_9 -> V_202 )
V_156 = F_64 ( V_8 , V_364 , 1 ) ;
else
V_156 = F_64 ( V_8 , V_364 , 0 ) ;
if ( V_156 ) {
F_8 ( L_52 ) ;
return;
}
V_156 = F_130 ( V_8 , V_360 ,
V_365 ) ;
if ( V_156 ) {
F_8 ( L_53 ) ;
return;
}
V_156 = F_129 ( V_8 , V_360 ,
V_366 ) ;
if ( V_156 ) {
F_8 ( L_54 ) ;
return;
}
}
F_128 ( V_8 , V_359 ) ;
}
}
static int F_131 ( struct V_7 * V_8 , bool V_301 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_156 = 0 ;
if ( V_301 && V_9 -> V_192 ) {
V_9 -> V_356 |= V_367 ;
F_114 ( L_55 ) ;
V_156 = F_64 ( V_8 ,
V_285 , V_368 ) ;
} else {
V_9 -> V_356 &= ~ V_367 ;
F_114 ( L_56 ) ;
V_156 = F_64 ( V_8 ,
V_287 , V_368 ) ;
}
return V_156 ;
}
static int F_132 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_79 * V_16 =
& V_8 -> V_10 . V_11 . V_19 . V_81 ;
if ( V_9 -> V_196 ) {
V_9 -> V_273 . V_267 = V_16 -> V_23 [ V_16 -> V_21 - 1 ] . V_215 ;
} else {
}
F_64 ( V_8 ,
V_294 ,
F_72 ( V_8 ,
V_9 -> V_273 . V_267 ,
V_294 ) ) ;
return 0 ;
}
static void F_41 ( struct V_7 * V_8 , bool V_359 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_190 ) {
if ( V_9 -> V_226 != V_359 ) {
if ( V_359 ) {
F_129 ( V_8 , V_369 ,
V_361 ) ;
F_130 ( V_8 , V_369 ,
V_362 ) ;
F_131 ( V_8 , false ) ;
F_55 ( V_8 , V_370 ) ;
V_9 -> V_226 = true ;
} else {
F_55 ( V_8 , V_371 ) ;
V_9 -> V_226 = false ;
F_130 ( V_8 , V_369 ,
V_365 ) ;
F_129 ( V_8 , V_369 ,
V_366 ) ;
F_132 ( V_8 ) ;
F_131 ( V_8 , true ) ;
}
} else {
if ( ! V_9 -> V_226 ) {
F_132 ( V_8 ) ;
}
}
} else {
V_9 -> V_226 = V_359 ;
F_132 ( V_8 ) ;
F_131 ( V_8 , ! V_359 ) ;
}
}
static void F_37 ( struct V_7 * V_8 )
{
if ( NULL == V_8 -> V_10 . V_372 )
V_8 -> V_10 . V_372 = & V_373 ;
}
