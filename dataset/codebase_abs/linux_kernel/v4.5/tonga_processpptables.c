static void F_1 ( struct V_1 * V_2 , bool V_3 , enum V_4 V_5 )
{
if ( V_3 )
F_2 ( V_2 -> V_6 . V_7 , V_5 ) ;
else
F_3 ( V_2 -> V_6 . V_7 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_8 )
{
F_5 ((~powerplay_caps & ____RETIRE16____),
L_1 , continue) ;
F_5 ((~powerplay_caps & ____RETIRE64____),
L_2 , continue) ;
F_5 ((~powerplay_caps & ____RETIRE512____),
L_3 , continue) ;
F_5 ((~powerplay_caps & ____RETIRE1024____),
L_4 , continue) ;
F_5 ((~powerplay_caps & ____RETIRE2048____),
L_5 , continue) ;
F_1 (
V_2 ,
0 != ( V_8 & V_9 ) ,
V_10
) ;
F_1 (
V_2 ,
0 != ( V_8 & V_11 ) ,
V_12
) ;
F_1 (
V_2 ,
0 != ( V_8 & V_13 ) ,
V_14
) ;
F_1 (
V_2 ,
0 != ( V_8 & V_15 ) ,
V_16
) ;
F_1 (
V_2 ,
0 != ( V_8 & V_17 ) ,
V_18
) ;
F_1 (
V_2 ,
0 != ( V_8 & V_19 ) ,
V_20
) ;
F_1 (
V_2 ,
0 != ( V_8 & V_21 ) ,
V_22
) ;
F_1 (
V_2 ,
0 != ( V_8 & V_23 ) ,
V_24
) ;
F_1 (
V_2 ,
0 != ( V_8 & V_25 ) ,
V_26
) ;
F_1 (
V_2 ,
0 != ( V_8 & V_27 ) ,
V_28
) ;
return 0 ;
}
const void * F_6 ( struct V_1 * V_2 )
{
int V_29 = F_7 ( V_30 , V_31 ) ;
T_2 V_32 ;
T_3 V_33 , V_34 ;
void * V_35 ;
V_35 = ( V_36 * )
F_8 ( V_2 -> V_37 , V_29 , & V_32 , & V_33 , & V_34 ) ;
V_2 -> V_38 = V_35 ;
return V_35 ;
}
static int F_9 (
struct V_1 * V_2 ,
T_4 * * V_39 ,
const T_5 * V_40 ,
T_1 V_41
)
{
T_1 V_42 , V_43 ;
T_4 * V_44 ;
F_5 ((0 != vddc_lookup_pp_tables->ucNumEntries),
L_6 , return 1 ) ;
V_42 = sizeof( T_1 ) +
sizeof( V_45 ) * V_41 ;
V_44 = ( T_4 * )
F_10 ( V_42 , V_46 ) ;
if ( NULL == V_44 )
return - V_47 ;
memset ( V_44 , 0x00 , V_42 ) ;
V_44 -> V_48 = V_40 -> V_49 ;
for ( V_43 = 0 ; V_43 < V_40 -> V_49 ; V_43 ++ ) {
V_44 -> V_50 [ V_43 ] . V_51 = 0 ;
V_44 -> V_50 [ V_43 ] . V_52 =
V_40 -> V_50 [ V_43 ] . V_53 ;
V_44 -> V_50 [ V_43 ] . V_54 =
V_40 -> V_50 [ V_43 ] . V_55 ;
V_44 -> V_50 [ V_43 ] . V_56 =
V_40 -> V_50 [ V_43 ] . V_57 ;
V_44 -> V_50 [ V_43 ] . V_58 =
V_40 -> V_50 [ V_43 ] . V_59 ;
}
* V_39 = V_44 ;
return 0 ;
}
static int F_11 (
struct V_1 * V_2 ,
T_6 * V_60 )
{
struct V_61 * V_62 = F_10 ( sizeof( T_6 ) , V_46 ) ;
struct V_63 * V_64 =
(struct V_63 * ) ( V_2 -> V_65 ) ;
if ( NULL == V_62 )
return - V_47 ;
V_62 -> V_66
= V_60 -> V_67 ;
V_62 -> V_68
= V_60 -> V_69 ;
V_62 -> V_70
= V_60 -> V_71 ;
V_62 -> V_72
= V_60 -> V_73 ;
V_62 -> V_74
= V_60 -> V_75 ;
V_62 -> V_76
= V_60 -> V_77 ;
V_62 -> V_78
= V_60 -> V_79 ;
V_62 -> V_80
= V_60 -> V_81 ;
V_62 -> V_82
= V_60 -> V_83 ;
V_62 -> V_84
= V_60 -> V_85 ;
V_64 -> V_86 = V_62 ;
return 0 ;
}
static int F_12 (
struct V_1 * V_2 ,
const V_36 * V_87
)
{
int V_88 = 0 ;
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
T_6 * V_60 ;
T_1 V_89 = 0 ;
T_1 V_90 = 0 ;
V_64 -> V_91 =
F_13 ( V_87 -> V_92 ) ;
V_64 -> V_86 = NULL ;
V_64 -> V_93 = NULL ;
V_64 -> V_94 = NULL ;
V_2 -> V_6 . V_95 =
F_13 ( V_87 -> V_96 ) ;
V_2 -> V_6 . V_97 = 0 ;
V_2 -> V_6 . V_98 = 0 ;
V_2 -> V_6 . V_99 = 0 ;
V_2 -> V_6 . V_100 = 0 ;
V_2 -> V_6 . V_101 = 1500000 ;
V_2 -> V_6 . V_102 = 6250 ;
V_90 = 0 ;
if ( 0 == V_90 ) {
if ( V_2 -> V_6 . V_95 != 0 )
F_2 ( V_2 -> V_6 . V_7 ,
V_103 ) ;
}
if ( 0 != V_87 -> V_104 ) {
const T_5 * V_105 =
( T_5 * ) ( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_104 ) ) ;
V_88 = F_9 ( V_2 ,
& V_64 -> V_93 , V_105 , 16 ) ;
}
if ( 0 != V_87 -> V_106 ) {
const T_5 * V_107 =
( T_5 * ) ( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_106 ) ) ;
V_88 = F_9 ( V_2 ,
& V_64 -> V_94 , V_107 , 16 ) ;
}
V_89 = 0 ;
if ( 0 == V_89 ) {
V_60 = ( T_6 * )
( ( ( unsigned long ) V_87 ) + F_13 ( V_87 -> V_108 ) ) ;
if ( 0 != V_87 -> V_108 ) {
if ( 1 == F_11 ( V_2 , V_60 ) ) {
F_2 ( V_2 -> V_6 . V_7 ,
V_109 ) ;
}
}
}
return V_88 ;
}
static int F_14 (
struct V_1 * V_2 ,
struct V_110 * * V_111 ,
const T_7 * V_112
)
{
T_1 V_42 , V_43 ;
struct V_110 * V_44 ;
F_5 ((0 != clk_volt_pp_table->count),
L_7 , return -1 ) ;
V_42 = sizeof( T_1 ) +
sizeof( T_1 ) * V_112 -> V_48 ;
V_44 = (struct V_110 * ) F_10 ( V_42 , V_46 ) ;
if ( NULL == V_44 )
return - V_47 ;
memset ( V_44 , 0x00 , V_42 ) ;
V_44 -> V_48 = ( T_1 ) V_112 -> V_48 ;
for ( V_43 = 0 ; V_43 < V_44 -> V_48 ; V_43 ++ )
V_44 -> V_113 [ V_43 ] = ( T_1 ) V_112 -> V_50 [ V_43 ] . V_114 ;
* V_111 = V_44 ;
return 0 ;
}
static int F_15 (
struct V_1 * V_2 ,
struct V_115 * V_116 ,
const T_8 * V_117
)
{
F_5 ((0 != limitable->ucNumEntries), L_7 , return -1 ) ;
V_116 -> V_118 = ( T_1 ) V_117 -> V_50 [ 0 ] . V_119 ;
V_116 -> V_120 = ( T_1 ) V_117 -> V_50 [ 0 ] . V_121 ;
V_116 -> V_122 = ( V_123 ) V_117 -> V_50 [ 0 ] . V_124 ;
V_116 -> V_125 = ( V_123 ) V_117 -> V_50 [ 0 ] . V_126 ;
V_116 -> V_127 = ( V_123 ) V_117 -> V_50 [ 0 ] . V_128 ;
return 0 ;
}
static int F_16 (
struct V_1 * V_2 ,
T_7 * * V_129 ,
const T_9 * V_130
)
{
T_1 V_42 , V_43 ;
T_7 * V_131 ;
F_5 ((0 != mclk_dep_table->ucNumEntries),
L_7 , return -1 ) ;
V_42 = sizeof( T_1 ) + sizeof( V_132 )
* V_130 -> V_49 ;
V_131 = ( T_7 * )
F_10 ( V_42 , V_46 ) ;
if ( NULL == V_131 )
return - V_47 ;
memset ( V_131 , 0x00 , V_42 ) ;
V_131 -> V_48 = ( T_1 ) V_130 -> V_49 ;
for ( V_43 = 0 ; V_43 < V_130 -> V_49 ; V_43 ++ ) {
V_131 -> V_50 [ V_43 ] . V_133 =
V_130 -> V_50 [ V_43 ] . V_134 ;
V_131 -> V_50 [ V_43 ] . V_135 =
V_130 -> V_50 [ V_43 ] . V_136 ;
V_131 -> V_50 [ V_43 ] . V_125 =
V_130 -> V_50 [ V_43 ] . V_137 ;
V_131 -> V_50 [ V_43 ] . V_138 =
V_130 -> V_50 [ V_43 ] . V_139 ;
V_131 -> V_50 [ V_43 ] . V_114 =
V_130 -> V_50 [ V_43 ] . V_140 ;
}
* V_129 = V_131 ;
return 0 ;
}
static int F_17 (
struct V_1 * V_2 ,
T_7 * * V_141 ,
const T_10 * V_142
)
{
T_1 V_42 , V_43 ;
T_7 * V_143 ;
F_5 ((0 != sclk_dep_table->ucNumEntries),
L_7 , return -1 ) ;
V_42 = sizeof( T_1 ) + sizeof( V_132 )
* V_142 -> V_49 ;
V_143 = ( T_7 * )
F_10 ( V_42 , V_46 ) ;
if ( NULL == V_143 )
return - V_47 ;
memset ( V_143 , 0x00 , V_42 ) ;
V_143 -> V_48 = ( T_1 ) V_142 -> V_49 ;
for ( V_43 = 0 ; V_43 < V_142 -> V_49 ; V_43 ++ ) {
V_143 -> V_50 [ V_43 ] . V_133 =
V_142 -> V_50 [ V_43 ] . V_144 ;
V_143 -> V_50 [ V_43 ] . V_135 =
V_142 -> V_50 [ V_43 ] . V_145 ;
V_143 -> V_50 [ V_43 ] . V_114 =
V_142 -> V_50 [ V_43 ] . V_146 ;
V_143 -> V_50 [ V_43 ] . V_147 =
( ( ( V_142 -> V_50 [ V_43 ] . V_148 & 0x80 ) >> 7 ) == 0 ) ? 1 : 0 ;
V_143 -> V_50 [ V_43 ] . V_149 =
( V_142 -> V_50 [ V_43 ] . V_148 & 0x7F ) ;
}
* V_141 = V_143 ;
return 0 ;
}
static int F_18 (
struct V_1 * V_2 ,
T_11 * * V_150 ,
const T_12 * V_151
)
{
T_1 V_42 , V_43 , V_152 ;
T_11 * V_153 ;
struct V_63 * V_64 =
(struct V_63 * ) ( V_2 -> V_65 ) ;
F_5 ((0 != atom_pcie_table->ucNumEntries),
L_7 , return -1 ) ;
V_42 = sizeof( T_1 ) +
sizeof( V_154 ) * V_151 -> V_49 ;
V_153 = ( T_11 * ) F_10 ( V_42 , V_46 ) ;
if ( NULL == V_153 )
return - V_47 ;
memset ( V_153 , 0x00 , V_42 ) ;
V_152 = ( V_64 -> V_155 -> V_48 ) + 1 ;
if ( ( T_1 ) V_151 -> V_49 <= V_152 )
V_152 = ( T_1 ) V_151 -> V_49 ;
else
F_19 ( V_156 L_8 ) ;
V_153 -> V_48 = V_152 ;
for ( V_43 = 0 ; V_43 < V_152 ; V_43 ++ ) {
V_153 -> V_50 [ V_43 ] . V_157 =
V_151 -> V_50 [ V_43 ] . V_158 ;
V_153 -> V_50 [ V_43 ] . V_159 =
V_151 -> V_50 [ V_43 ] . V_160 ;
}
* V_150 = V_153 ;
return 0 ;
}
static int F_20 (
struct V_1 * V_2 ,
struct V_161 * * V_162 ,
const T_13 * V_44
)
{
T_1 V_42 ;
struct V_161 * V_163 ;
V_42 = sizeof( T_1 ) + sizeof( struct V_161 ) ;
V_163 = F_10 ( V_42 , V_46 ) ;
if ( NULL == V_163 )
return - V_47 ;
memset ( V_163 , 0x00 , V_42 ) ;
V_2 -> V_164 . V_165 = F_10 ( V_42 , V_46 ) ;
if ( NULL == V_2 -> V_164 . V_165 )
return - V_47 ;
memset ( V_2 -> V_164 . V_165 , 0x00 , V_42 ) ;
if ( V_44 -> V_166 < 3 ) {
const T_14 * V_167 =
( T_14 * ) V_44 ;
V_163 -> V_168 = V_167 -> V_168 ;
V_163 -> V_169 =
V_167 -> V_169 ;
V_163 -> V_170 = V_167 -> V_170 ;
V_163 -> V_171 =
V_167 -> V_171 ;
V_163 -> V_172 =
V_167 -> V_172 ;
V_163 -> V_173 =
V_167 -> V_173 ;
V_163 -> V_174 =
V_167 -> V_174 ;
V_163 -> V_175 =
V_167 -> V_175 ;
V_163 -> V_176 =
V_167 -> V_177 ;
V_163 -> V_178 =
V_167 -> V_177 ;
V_163 -> V_179 =
V_167 -> V_179 ;
V_163 -> V_180 =
V_167 -> V_180 ;
V_163 -> V_181 =
V_167 -> V_181 ;
} else {
const T_15 * V_182 =
( T_15 * ) V_44 ;
V_163 -> V_168 = V_182 -> V_168 ;
V_163 -> V_169 = V_182 -> V_169 ;
V_163 -> V_170 = V_182 -> V_170 ;
V_163 -> V_171 = V_182 -> V_171 ;
V_163 -> V_172 = V_182 -> V_172 ;
V_163 -> V_173 = V_182 -> V_173 ;
V_163 -> V_174 = V_182 -> V_174 ;
V_163 -> V_175 =
V_182 -> V_175 ;
V_163 -> V_176 =
V_182 -> V_177 ;
V_163 -> V_178 =
V_182 -> V_177 ;
V_163 -> V_179 =
V_182 -> V_179 ;
V_163 -> V_180 =
V_182 -> V_180 ;
V_163 -> V_181 =
V_182 -> V_181 ;
V_163 -> V_183 =
V_182 -> V_183 ;
V_163 -> V_184 =
V_182 -> V_184 ;
V_163 -> V_185 =
V_182 -> V_185 ;
V_163 -> V_186 =
V_182 -> V_186 ;
V_163 -> V_187 =
V_182 -> V_187 ;
V_163 -> V_188 =
V_182 -> V_188 ;
V_163 -> V_189 =
V_182 -> V_189 ;
V_163 -> V_190 =
V_182 -> V_190 ;
V_163 -> V_191 =
V_182 -> V_191 ;
V_163 -> V_192 = V_182 -> V_192 ;
V_163 -> V_193 = V_182 -> V_193 ;
V_163 -> V_194 = V_182 -> V_194 ;
V_163 -> V_195 = V_182 -> V_195 ;
}
* V_162 = V_163 ;
return 0 ;
}
static int F_21 (
struct V_1 * V_2 ,
T_16 * * V_196 ,
const T_17 * V_197
)
{
T_1 V_42 , V_43 ;
const T_18 * V_198 ;
T_16 * V_199 ;
F_5 ((0 != mm_dependency_table->ucNumEntries),
L_7 , return -1 ) ;
V_42 = sizeof( T_1 ) +
sizeof( V_200 )
* V_197 -> V_49 ;
V_199 = ( T_16 * )
F_10 ( V_42 , V_46 ) ;
if ( NULL == V_199 )
return - V_47 ;
memset ( V_199 , 0x00 , V_42 ) ;
V_199 -> V_48 = V_197 -> V_49 ;
for ( V_43 = 0 ; V_43 < V_197 -> V_49 ; V_43 ++ ) {
V_198 = & V_197 -> V_50 [ V_43 ] ;
V_199 -> V_50 [ V_43 ] . V_201 = V_198 -> V_134 ;
V_199 -> V_50 [ V_43 ] . V_202 = V_198 -> V_136 ;
V_199 -> V_50 [ V_43 ] . V_203 = V_198 -> V_204 ;
V_199 -> V_50 [ V_43 ] . V_205 = V_198 -> V_206 ;
V_199 -> V_50 [ V_43 ] . V_207 = V_198 -> V_208 ;
V_199 -> V_50 [ V_43 ] . V_209 = V_198 -> V_210 ;
V_199 -> V_50 [ V_43 ] . V_211 = V_198 -> V_212 ;
}
* V_196 = V_199 ;
return 0 ;
}
static int F_22 (
struct V_1 * V_2 ,
const V_36 * V_87
)
{
int V_88 = 0 ;
struct V_63 * V_64 =
(struct V_63 * ) ( V_2 -> V_65 ) ;
const T_17 * V_197 =
( const T_17 * ) ( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_213 ) ) ;
const T_13 * V_214 =
( const T_13 * ) ( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_215 ) ) ;
const T_9 * V_130 =
( const T_9 * ) ( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_216 ) ) ;
const T_10 * V_142 =
( const T_10 * ) ( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_217 ) ) ;
const T_8 * V_218 =
( const T_8 * ) ( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_219 ) ) ;
const T_12 * V_153 =
( const T_12 * ) ( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_220 ) ) ;
V_64 -> V_155 = NULL ;
V_64 -> V_221 = NULL ;
V_64 -> V_222 = NULL ;
V_64 -> V_153 = NULL ;
if ( V_87 -> V_213 != 0 )
V_88 = F_21 ( V_2 ,
& V_64 -> V_222 , V_197 ) ;
if ( V_88 == 0 && V_87 -> V_215 != 0 )
V_88 = F_20 ( V_2 ,
& V_64 -> V_165 , V_214 ) ;
if ( V_88 == 0 && V_87 -> V_217 != 0 )
V_88 = F_17 ( V_2 ,
& V_64 -> V_155 , V_142 ) ;
if ( V_88 == 0 && V_87 -> V_216 != 0 )
V_88 = F_16 ( V_2 ,
& V_64 -> V_221 , V_130 ) ;
if ( V_88 == 0 && V_87 -> V_220 != 0 )
V_88 = F_18 ( V_2 ,
& V_64 -> V_153 , V_153 ) ;
if ( V_88 == 0 && V_87 -> V_219 != 0 )
V_88 = F_15 ( V_2 ,
& V_64 -> V_223 , V_218 ) ;
V_2 -> V_164 . V_223 . V_118 =
V_64 -> V_223 . V_118 ;
V_2 -> V_164 . V_223 . V_120 =
V_64 -> V_223 . V_120 ;
V_2 -> V_164 . V_223 . V_122 =
V_64 -> V_223 . V_122 ;
V_2 -> V_164 . V_223 . V_125 =
V_64 -> V_223 . V_125 ;
if ( V_88 == 0 && ( NULL != V_64 -> V_221 )
&& ( 0 != V_64 -> V_221 -> V_48 ) )
V_88 = F_14 ( V_2 , & V_64 -> V_224 ,
V_64 -> V_221 ) ;
if ( V_88 == 0 && ( NULL != V_64 -> V_155 )
&& ( 0 != V_64 -> V_155 -> V_48 ) )
V_88 = F_14 ( V_2 , & V_64 -> V_225 ,
V_64 -> V_155 ) ;
return V_88 ;
}
static int F_23 (
struct V_1 * V_2 ,
const V_36 * V_87 )
{
V_2 -> V_6 . V_226 . V_227 =
F_13 ( V_87 -> V_228 ) ;
V_2 -> V_6 . V_226 . V_229 =
F_13 ( V_87 -> V_230 ) ;
V_2 -> V_6 . V_231 = 0 ;
V_2 -> V_6 . V_232 = 0 ;
V_2 -> V_6 . V_233 = 0 ;
if ( V_2 -> V_6 . V_226 . V_227 > 0 \
&& V_2 -> V_6 . V_226 . V_229 > 0 ) {
F_2 ( V_2 -> V_6 . V_7 ,
V_234 ) ;
}
return 0 ;
}
static int F_24 (
struct V_1 * V_2 ,
const V_36 * V_87
)
{
const T_13 * V_235 ;
T_19 * V_236 ;
V_236 = ( T_19 * )
( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_237 ) ) ;
F_5 ((0 != powerplay_table->usThermalControllerOffset),
L_9 , return -1 ) ;
V_2 -> V_236 . V_238 = V_236 -> V_238 ;
V_2 -> V_236 . V_239 = V_236 -> V_239 ;
V_2 -> V_236 . V_240 = V_236 -> V_240 ;
V_2 -> V_236 . V_241 . V_242 =
( 0 != ( V_236 -> V_243 & V_244 ) ) ;
V_2 -> V_236 . V_241 . V_245 =
V_236 -> V_243 &
V_246 ;
V_2 -> V_236 . V_241 . V_247
= V_236 -> V_248 * 100UL ;
V_2 -> V_236 . V_241 . V_249
= V_236 -> V_250 * 100UL ;
F_1 (
V_2 ,
V_251 != V_2 -> V_236 . V_238 ,
V_252
) ;
if ( 0 == V_87 -> V_253 )
return 0 ;
V_235 = ( const T_13 * )
( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_253 ) ) ;
F_5 ((0 != powerplay_table->usFanTableOffset),
L_10 , return -1 ) ;
F_5 ((0 < fan_table->ucRevId),
L_11 , return -1 ) ;
V_2 -> V_236 . V_254 . V_255
= 100000 ;
F_2 ( V_2 -> V_6 . V_7 ,
V_256 ) ;
if ( V_235 -> V_166 < 8 ) {
const T_20 * V_257 =
( T_20 * ) V_235 ;
V_2 -> V_236 . V_254 . V_258
= V_257 -> V_258 ;
V_2 -> V_236 . V_254 . V_259
= V_257 -> V_259 ;
V_2 -> V_236 . V_254 . V_260
= V_257 -> V_260 ;
V_2 -> V_236 . V_254 . V_261
= V_257 -> V_261 ;
V_2 -> V_236 . V_254 . V_262
= V_257 -> V_262 ;
V_2 -> V_236 . V_254 . V_263
= V_257 -> V_263 ;
V_2 -> V_236 . V_254 . V_264
= V_257 -> V_264 ;
V_2 -> V_236 . V_254 . V_265
= 10900 ;
V_2 -> V_236 . V_254 . V_265
= V_257 -> V_265 ;
V_2 -> V_236 . V_254 . V_266
= V_257 -> V_266 ;
V_2 -> V_236 . V_254 . V_267
= V_257 -> V_268 ;
V_2 -> V_236 . V_254 . V_269
= 4836 ;
V_2 -> V_236 . V_254 . V_270
= V_257 -> V_270 ;
V_2 -> V_236 . V_254 . V_271
= V_257 -> V_272 ;
V_2 -> V_236 . V_254 . V_273
= ( V_257 -> V_273 / 100 ) ;
V_2 -> V_236 . V_254 . V_274
= V_257 -> V_274 ;
V_2 -> V_236 . V_254 . V_275
= V_257 -> V_275 ;
} else {
const T_21 * V_276 =
( T_21 * ) V_235 ;
V_2 -> V_236 . V_254 . V_258
= V_276 -> V_258 ;
V_2 -> V_236 . V_254 . V_259
= V_276 -> V_259 ;
V_2 -> V_236 . V_254 . V_260
= V_276 -> V_260 ;
V_2 -> V_236 . V_254 . V_261
= V_276 -> V_261 ;
V_2 -> V_236 . V_254 . V_262
= V_276 -> V_262 ;
V_2 -> V_236 . V_254 . V_263
= V_276 -> V_263 ;
V_2 -> V_236 . V_254 . V_264
= V_276 -> V_264 ;
V_2 -> V_236 . V_254 . V_265
= V_276 -> V_265 ;
V_2 -> V_236 . V_254 . V_266
= V_276 -> V_266 ;
V_2 -> V_236 . V_254 . V_267
= V_276 -> V_268 ;
V_2 -> V_236 . V_254 . V_269
= 4836 ;
V_2 -> V_236 . V_254 . V_270
= V_276 -> V_270 ;
V_2 -> V_236 . V_254 . V_271
= V_276 -> V_272 ;
V_2 -> V_236 . V_254 . V_273
= ( V_276 -> V_273 / 100 ) ;
V_2 -> V_236 . V_254 . V_274
= V_276 -> V_274 ;
V_2 -> V_236 . V_254 . V_275
= V_276 -> V_275 ;
V_2 -> V_236 . V_254 . V_277
= V_276 -> V_277 ;
V_2 -> V_236 . V_254 . V_278
= V_276 -> V_278 ;
V_2 -> V_236 . V_254 . V_279
= V_276 -> V_279 ;
V_2 -> V_236 . V_254 . V_280
= V_276 -> V_280 ;
V_2 -> V_236 . V_254 . V_281
= V_276 -> V_281 ;
V_2 -> V_236 . V_254 . V_282
= V_276 -> V_282 ;
V_2 -> V_236 . V_254 . V_283
= V_276 -> V_283 ;
}
return 0 ;
}
static int F_25 (
struct V_1 * V_2 ,
const V_36 * V_87
)
{
const T_22 * V_284 ;
V_284 = ( T_22 * ) ( ( ( unsigned long ) V_87 ) +
F_13 ( V_87 -> V_285 ) ) ;
F_5 ((ATOM_Tonga_TABLE_REVISION_TONGA <=
powerplay_table->sHeader.ucTableFormatRevision),
L_12 , return -1 ) ;
F_5 ((0 != powerplay_table->usStateArrayOffset),
L_13 , return -1 ) ;
F_5 ((0 < powerplay_table->sHeader.usStructureSize),
L_7 , return -1 ) ;
F_5 ((0 < state_arrays->ucNumEntries),
L_7 , return -1 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_88 = 0 ;
const V_36 * V_87 ;
V_2 -> V_65 = F_10 ( sizeof( struct V_63 ) , V_46 ) ;
F_5 ((NULL != hwmgr->pptable),
L_14 , return -ENOMEM) ;
memset ( V_2 -> V_65 , 0x00 , sizeof( struct V_63 ) ) ;
V_87 = F_6 ( V_2 ) ;
F_5 ((NULL != powerplay_table),
L_15 , return -1 ) ;
V_88 = F_25 ( V_2 , V_87 ) ;
F_5 ((result == 0),
L_16 , return result) ;
V_88 = F_4 ( V_2 ,
F_27 ( V_87 -> V_286 ) ) ;
F_5 ((result == 0),
L_17 , return result) ;
V_88 = F_24 ( V_2 , V_87 ) ;
F_5 ((result == 0),
L_18 , return result) ;
V_88 = F_23 ( V_2 , V_87 ) ;
F_5 ((result == 0),
L_19 , return result) ;
V_88 = F_22 ( V_2 , V_87 ) ;
F_5 ((result == 0),
L_20 , return result) ;
V_88 = F_12 ( V_2 , V_87 ) ;
F_5 ((result == 0),
L_21 , return result) ;
return V_88 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_88 = 0 ;
struct V_63 * V_64 =
(struct V_63 * ) ( V_2 -> V_65 ) ;
if ( NULL != V_2 -> V_38 ) {
F_29 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
}
if ( NULL != V_64 -> V_155 )
V_64 -> V_155 = NULL ;
if ( NULL != V_64 -> V_221 )
V_64 -> V_221 = NULL ;
if ( NULL != V_64 -> V_224 )
V_64 -> V_224 = NULL ;
if ( NULL != V_64 -> V_225 )
V_64 -> V_225 = NULL ;
if ( NULL != V_64 -> V_93 )
V_64 -> V_93 = NULL ;
if ( NULL != V_64 -> V_94 )
V_64 -> V_94 = NULL ;
if ( NULL != V_64 -> V_222 )
V_64 -> V_222 = NULL ;
if ( NULL != V_64 -> V_165 )
V_64 -> V_165 = NULL ;
if ( NULL != V_2 -> V_164 . V_165 )
V_2 -> V_164 . V_165 = NULL ;
if ( NULL != V_64 -> V_86 )
V_64 -> V_86 = NULL ;
if ( NULL != V_64 -> V_153 )
V_64 -> V_153 = NULL ;
if ( NULL != V_2 -> V_65 ) {
F_29 ( V_2 -> V_65 ) ;
V_2 -> V_65 = NULL ;
}
return V_88 ;
}
int F_30 ( struct V_1 * V_2 )
{
const T_22 * V_284 ;
const V_36 * V_287 = F_6 ( V_2 ) ;
F_5 ((NULL != pp_table),
L_15 , return -1 ) ;
F_5 ((pp_table->sHeader.ucTableFormatRevision >=
ATOM_Tonga_TABLE_REVISION_TONGA),
L_22 , return -1 ) ;
V_284 = ( T_22 * ) ( ( ( unsigned long ) V_287 ) +
F_13 ( V_287 -> V_285 ) ) ;
return ( T_1 ) ( V_284 -> V_49 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
V_123 V_288 , V_123 V_289 )
{
T_1 V_88 = 0 ;
if ( V_288 & V_290 )
V_88 |= V_291 ;
if ( V_288 & V_292 )
V_88 |= V_293 ;
if ( V_288 & V_294 )
V_88 |= V_295 ;
if ( V_288 & V_296 )
V_88 |= V_297 ;
if ( V_288 & V_298 )
V_88 |= V_299 ;
if ( V_288 & V_300 )
V_88 |= V_301 ;
if ( V_289 & V_302 )
V_88 |= V_303 ;
return V_88 ;
}
int F_32 ( struct V_1 * V_2 ,
T_1 V_304 , struct V_305 * V_306 ,
int (* F_33)( struct V_1 * , void * ,
struct V_305 * , void * , T_1 ) )
{
int V_88 = 0 ;
const T_22 * V_284 ;
const T_23 * V_307 ;
const V_36 * V_287 = F_6 ( V_2 ) ;
F_5 ((NULL != pp_table), L_15 , return -1;) ;
V_306 -> V_288 . V_308 = V_304 ;
if ( V_287 -> V_309 . V_310 >=
V_311 ) {
V_284 = ( T_22 * ) ( ( ( unsigned long ) V_287 ) +
F_13 ( V_287 -> V_285 ) ) ;
F_5 ((0 < pp_table->usStateArrayOffset),
L_23 , return -1 ) ;
F_5 ((0 < state_arrays->ucNumEntries),
L_24 , return -1 ) ;
F_5 ((entry_index <= state_arrays->ucNumEntries),
L_25 , return -1 ) ;
V_307 = & ( V_284 -> V_312 [ V_304 ] ) ;
V_88 = F_33 ( V_2 , ( void * ) V_307 , V_306 ,
( void * ) V_287 ,
F_31 ( V_2 ,
F_13 ( V_307 -> V_313 ) ,
F_13 ( V_307 -> V_314 ) ) ) ;
}
if ( ! V_88 && ( V_306 -> V_288 . V_315 &
V_291 ) )
V_88 = V_2 -> V_316 -> V_317 ( V_2 , & ( V_306 -> V_318 ) ) ;
return V_88 ;
}
