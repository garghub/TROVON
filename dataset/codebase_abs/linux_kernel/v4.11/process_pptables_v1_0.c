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
static const void * F_6 ( struct V_1 * V_2 )
{
int V_29 = F_7 ( V_30 , V_31 ) ;
T_2 V_32 ;
T_3 V_33 , V_34 ;
void * V_35 = ( void * ) V_2 -> V_36 ;
if ( ! V_35 ) {
V_35 = ( V_37 * )
F_8 ( V_2 -> V_38 ,
V_29 , & V_32 , & V_33 , & V_34 ) ;
V_2 -> V_36 = V_35 ;
V_2 -> V_39 = V_32 ;
}
return V_35 ;
}
static int F_9 (
struct V_1 * V_2 ,
T_4 * * V_40 ,
const T_5 * V_41 ,
T_1 V_42
)
{
T_1 V_43 , V_44 ;
T_4 * V_45 ;
T_6 * V_46 ;
T_7 * V_47 ;
F_5 ((0 != vddc_lookup_pp_tables->ucNumEntries),
L_6 , return 1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( T_6 ) * V_42 ;
V_45 = F_10 ( V_43 , V_48 ) ;
if ( NULL == V_45 )
return - V_49 ;
memset ( V_45 , 0x00 , V_43 ) ;
V_45 -> V_50 = V_41 -> V_51 ;
for ( V_44 = 0 ; V_44 < V_41 -> V_51 ; V_44 ++ ) {
V_46 = F_11 (
T_6 ,
V_52 , V_45 , V_44 ) ;
V_47 = F_11 (
T_7 ,
V_52 , V_41 , V_44 ) ;
V_46 -> V_53 = 0 ;
V_46 -> V_54 = V_47 -> V_55 ;
V_46 -> V_56 = V_47 -> V_57 ;
V_46 -> V_58 = V_47 -> V_59 ;
V_46 -> V_60 = V_47 -> V_61 ;
}
* V_40 = V_45 ;
return 0 ;
}
static int F_12 (
struct V_1 * V_2 ,
T_8 * V_62 )
{
struct V_63 * V_64 = F_10 ( sizeof( T_8 ) , V_48 ) ;
struct V_65 * V_66 =
(struct V_65 * ) ( V_2 -> V_67 ) ;
if ( NULL == V_64 )
return - V_49 ;
V_64 -> V_68
= V_62 -> V_69 ;
V_64 -> V_70
= V_62 -> V_71 ;
V_64 -> V_72
= V_62 -> V_73 ;
V_64 -> V_74
= V_62 -> V_75 ;
V_64 -> V_76
= V_62 -> V_77 ;
V_64 -> V_78
= V_62 -> V_79 ;
V_64 -> V_80
= V_62 -> V_81 ;
V_64 -> V_82
= V_62 -> V_83 ;
V_64 -> V_84
= V_62 -> V_85 ;
V_64 -> V_86
= V_62 -> V_87 ;
V_66 -> V_88 = V_64 ;
return 0 ;
}
static int F_13 (
struct V_1 * V_2 ,
const V_37 * V_89
)
{
int V_90 = 0 ;
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
T_8 * V_62 ;
T_1 V_91 = 0 ;
T_1 V_92 = 0 ;
V_66 -> V_93 =
F_14 ( V_89 -> V_94 ) ;
V_66 -> V_88 = NULL ;
V_66 -> V_95 = NULL ;
V_66 -> V_96 = NULL ;
V_2 -> V_6 . V_97 =
F_14 ( V_89 -> V_98 ) ;
V_2 -> V_6 . V_99 = 0 ;
V_2 -> V_6 . V_100 = 0 ;
V_2 -> V_6 . V_101 = 0 ;
V_2 -> V_6 . V_102 = 0 ;
V_2 -> V_6 . V_103 = 1500000 ;
V_2 -> V_6 . V_104 = 6250 ;
V_92 = 0 ;
if ( 0 == V_92 ) {
if ( V_2 -> V_6 . V_97 != 0 )
F_2 ( V_2 -> V_6 . V_7 ,
V_105 ) ;
}
if ( 0 != V_89 -> V_106 ) {
const T_5 * V_107 =
( T_5 * ) ( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_106 ) ) ;
V_90 = F_9 ( V_2 ,
& V_66 -> V_95 , V_107 , 16 ) ;
}
if ( 0 != V_89 -> V_108 ) {
const T_5 * V_109 =
( T_5 * ) ( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_108 ) ) ;
V_90 = F_9 ( V_2 ,
& V_66 -> V_96 , V_109 , 16 ) ;
}
V_91 = 0 ;
if ( 0 == V_91 ) {
V_62 = ( T_8 * )
( ( ( unsigned long ) V_89 ) + F_14 ( V_89 -> V_110 ) ) ;
if ( 0 != V_89 -> V_110 ) {
if ( F_12 ( V_2 , V_62 ) == 0 ) {
F_2 ( V_2 -> V_6 . V_7 ,
V_111 ) ;
}
}
}
return V_90 ;
}
static int F_15 (
struct V_1 * V_2 ,
struct V_112 * * V_113 ,
T_9 const * V_114
)
{
T_1 V_43 , V_44 ;
struct V_112 * V_45 ;
T_10 * V_115 ;
F_5 ((0 != clk_volt_pp_table->count),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( T_1 ) * V_114 -> V_50 ;
V_45 = F_10 ( V_43 , V_48 ) ;
if ( NULL == V_45 )
return - V_49 ;
memset ( V_45 , 0x00 , V_43 ) ;
V_45 -> V_50 = ( T_1 ) V_114 -> V_50 ;
for ( V_44 = 0 ; V_44 < V_45 -> V_50 ; V_44 ++ ) {
V_115 = F_11 (
T_10 ,
V_52 , V_114 , V_44 ) ;
V_45 -> V_116 [ V_44 ] = ( T_1 ) V_115 -> V_117 ;
}
* V_113 = V_45 ;
return 0 ;
}
static int F_16 (
struct V_1 * V_2 ,
struct V_118 * V_119 ,
T_11 const * V_120
)
{
F_5 ((0 != limitable->ucNumEntries), L_7 , return -1 ) ;
V_119 -> V_121 = ( T_1 ) V_120 -> V_52 [ 0 ] . V_122 ;
V_119 -> V_123 = ( T_1 ) V_120 -> V_52 [ 0 ] . V_124 ;
V_119 -> V_125 = ( V_126 ) V_120 -> V_52 [ 0 ] . V_127 ;
V_119 -> V_128 = ( V_126 ) V_120 -> V_52 [ 0 ] . V_129 ;
V_119 -> V_130 = ( V_126 ) V_120 -> V_52 [ 0 ] . V_131 ;
return 0 ;
}
static int F_17 (
struct V_1 * V_2 ,
T_9 * * V_132 ,
T_12 const * V_133
)
{
T_1 V_43 , V_44 ;
T_9 * V_134 ;
T_10 * V_135 ;
T_13 * V_136 ;
F_5 ((0 != mclk_dep_table->ucNumEntries),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) + sizeof( T_10 )
* V_133 -> V_51 ;
V_134 = F_10 ( V_43 , V_48 ) ;
if ( NULL == V_134 )
return - V_49 ;
memset ( V_134 , 0x00 , V_43 ) ;
V_134 -> V_50 = ( T_1 ) V_133 -> V_51 ;
for ( V_44 = 0 ; V_44 < V_133 -> V_51 ; V_44 ++ ) {
V_135 = F_11 (
T_10 ,
V_52 , V_134 , V_44 ) ;
V_136 = F_11 (
T_13 ,
V_52 , V_133 , V_44 ) ;
V_135 -> V_137 = V_136 -> V_138 ;
V_135 -> V_139 = V_136 -> V_140 ;
V_135 -> V_128 = V_136 -> V_141 ;
V_135 -> V_142 = V_136 -> V_143 ;
V_135 -> V_117 = V_136 -> V_144 ;
}
* V_132 = V_134 ;
return 0 ;
}
static int F_18 (
struct V_1 * V_2 ,
T_9 * * V_145 ,
T_14 const * V_146
)
{
T_1 V_43 , V_44 ;
T_9 * V_147 ;
T_10 * V_148 ;
if ( V_146 -> V_149 < 1 ) {
const T_15 * V_150 =
( T_15 * ) V_146 ;
T_16 * V_151 ;
F_5 ((0 != tonga_table->ucNumEntries),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) + sizeof( T_10 )
* V_150 -> V_51 ;
V_147 = F_10 ( V_43 , V_48 ) ;
if ( NULL == V_147 )
return - V_49 ;
memset ( V_147 , 0x00 , V_43 ) ;
V_147 -> V_50 = ( T_1 ) V_150 -> V_51 ;
for ( V_44 = 0 ; V_44 < V_150 -> V_51 ; V_44 ++ ) {
V_151 = F_11 (
T_16 ,
V_52 , V_150 , V_44 ) ;
V_148 = F_11 (
T_10 ,
V_52 , V_147 , V_44 ) ;
V_148 -> V_137 = V_151 -> V_152 ;
V_148 -> V_139 = V_151 -> V_153 ;
V_148 -> V_117 = V_151 -> V_154 ;
V_148 -> V_155 =
( ( ( V_151 -> V_156 & 0x80 ) >> 7 ) == 0 ) ? 1 : 0 ;
V_148 -> V_157 = ( V_151 -> V_156 & 0x7F ) ;
}
} else {
const T_17 * V_158 =
( T_17 * ) V_146 ;
T_18 * V_151 ;
F_5 ((0 != polaris_table->ucNumEntries),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) + sizeof( T_10 )
* V_158 -> V_51 ;
V_147 = F_10 ( V_43 , V_48 ) ;
if ( NULL == V_147 )
return - V_49 ;
memset ( V_147 , 0x00 , V_43 ) ;
V_147 -> V_50 = ( T_1 ) V_158 -> V_51 ;
for ( V_44 = 0 ; V_44 < V_158 -> V_51 ; V_44 ++ ) {
V_151 = F_11 (
T_18 ,
V_52 , V_158 , V_44 ) ;
V_148 = F_11 (
T_10 ,
V_52 , V_147 , V_44 ) ;
V_148 -> V_137 = V_151 -> V_152 ;
V_148 -> V_139 = V_151 -> V_153 ;
V_148 -> V_117 = V_151 -> V_154 ;
V_148 -> V_155 =
( ( ( V_151 -> V_156 & 0x80 ) >> 7 ) == 0 ) ? 1 : 0 ;
V_148 -> V_157 = ( V_151 -> V_156 & 0x7F ) ;
V_148 -> V_159 = V_151 -> V_160 ;
}
}
* V_145 = V_147 ;
return 0 ;
}
static int F_19 (
struct V_1 * V_2 ,
T_19 * * V_161 ,
T_14 const * V_162
)
{
T_1 V_43 , V_44 , V_163 ;
T_19 * V_164 ;
struct V_65 * V_66 =
(struct V_65 * ) ( V_2 -> V_67 ) ;
T_20 * V_165 ;
if ( V_162 -> V_149 < 1 ) {
const T_21 * V_166 = ( T_21 * ) V_162 ;
T_22 * V_167 ;
F_5 ((atom_pcie_table->ucNumEntries != 0),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( T_20 ) * V_166 -> V_51 ;
V_164 = F_10 ( V_43 , V_48 ) ;
if ( V_164 == NULL )
return - V_49 ;
memset ( V_164 , 0x00 , V_43 ) ;
V_163 = ( V_66 -> V_168 -> V_50 ) + 1 ;
if ( ( T_1 ) V_166 -> V_51 <= V_163 )
V_163 = ( T_1 ) V_166 -> V_51 ;
else
F_20 ( L_8 ) ;
V_164 -> V_50 = V_163 ;
for ( V_44 = 0 ; V_44 < V_163 ; V_44 ++ ) {
V_165 = F_11 (
T_20 ,
V_52 , V_164 , V_44 ) ;
V_167 = F_11 (
T_22 ,
V_52 , V_166 , V_44 ) ;
V_165 -> V_169 = V_167 -> V_170 ;
V_165 -> V_171 = V_167 -> V_172 ;
}
* V_161 = V_164 ;
} else {
const T_23 * V_166 = ( T_23 * ) V_162 ;
T_24 * V_167 ;
F_5 ((atom_pcie_table->ucNumEntries != 0),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( T_20 ) * V_166 -> V_51 ;
V_164 = F_10 ( V_43 , V_48 ) ;
if ( V_164 == NULL )
return - V_49 ;
memset ( V_164 , 0x00 , V_43 ) ;
V_163 = ( V_66 -> V_168 -> V_50 ) + 1 ;
if ( ( T_1 ) V_166 -> V_51 <= V_163 )
V_163 = ( T_1 ) V_166 -> V_51 ;
else
F_20 ( L_8 ) ;
V_164 -> V_50 = V_163 ;
for ( V_44 = 0 ; V_44 < V_163 ; V_44 ++ ) {
V_165 = F_11 (
T_20 ,
V_52 , V_164 , V_44 ) ;
V_167 = F_11 (
T_24 ,
V_52 , V_166 , V_44 ) ;
V_165 -> V_169 = V_167 -> V_170 ;
V_165 -> V_171 = V_167 -> V_172 ;
V_165 -> V_173 = V_167 -> V_174 ;
}
* V_161 = V_164 ;
}
return 0 ;
}
static int F_21 (
struct V_1 * V_2 ,
struct V_175 * * V_176 ,
const T_14 * V_45
)
{
T_1 V_43 ;
struct V_175 * V_177 ;
V_43 = sizeof( T_1 ) + sizeof( struct V_175 ) ;
V_177 = F_10 ( V_43 , V_48 ) ;
if ( NULL == V_177 )
return - V_49 ;
memset ( V_177 , 0x00 , V_43 ) ;
V_2 -> V_178 . V_179 = F_10 ( V_43 , V_48 ) ;
if ( NULL == V_2 -> V_178 . V_179 ) {
F_22 ( V_177 ) ;
return - V_49 ;
}
memset ( V_2 -> V_178 . V_179 , 0x00 , V_43 ) ;
if ( V_45 -> V_149 < 3 ) {
const T_25 * V_150 =
( T_25 * ) V_45 ;
V_177 -> V_180 = V_150 -> V_180 ;
V_177 -> V_181 =
V_150 -> V_181 ;
V_177 -> V_182 = V_150 -> V_182 ;
V_177 -> V_183 =
V_150 -> V_183 ;
V_177 -> V_184 =
V_150 -> V_184 ;
V_177 -> V_185 =
V_150 -> V_185 ;
V_177 -> V_186 =
V_150 -> V_186 ;
V_177 -> V_187 =
V_150 -> V_187 ;
V_177 -> V_188 =
V_150 -> V_189 ;
V_177 -> V_190 =
V_150 -> V_189 ;
V_177 -> V_191 =
V_150 -> V_191 ;
V_177 -> V_192 =
V_150 -> V_192 ;
V_177 -> V_193 =
V_150 -> V_193 ;
} else {
const T_26 * V_194 =
( T_26 * ) V_45 ;
V_177 -> V_180 = V_194 -> V_180 ;
V_177 -> V_181 = V_194 -> V_181 ;
V_177 -> V_182 = V_194 -> V_182 ;
V_177 -> V_183 = V_194 -> V_183 ;
V_177 -> V_184 = V_194 -> V_184 ;
V_177 -> V_185 = V_194 -> V_185 ;
V_177 -> V_186 = V_194 -> V_186 ;
V_177 -> V_187 =
V_194 -> V_187 ;
V_177 -> V_188 =
V_194 -> V_189 ;
V_177 -> V_190 =
V_194 -> V_189 ;
V_177 -> V_191 =
V_194 -> V_191 ;
V_177 -> V_192 =
V_194 -> V_192 ;
V_177 -> V_193 =
V_194 -> V_193 ;
V_177 -> V_195 =
V_194 -> V_195 ;
V_177 -> V_196 =
V_194 -> V_196 ;
V_177 -> V_197 =
V_194 -> V_197 ;
V_177 -> V_198 =
V_194 -> V_198 ;
V_177 -> V_199 =
V_194 -> V_199 ;
V_177 -> V_200 =
V_194 -> V_200 ;
V_177 -> V_201 =
V_194 -> V_201 ;
V_177 -> V_202 =
V_194 -> V_202 ;
V_177 -> V_203 =
V_194 -> V_203 ;
V_177 -> V_204 = V_194 -> V_204 ;
V_177 -> V_205 = V_194 -> V_205 ;
V_177 -> V_206 = V_194 -> V_206 ;
V_177 -> V_207 = V_194 -> V_207 ;
}
* V_176 = V_177 ;
return 0 ;
}
static int F_23 (
struct V_1 * V_2 ,
T_27 * * V_208 ,
const T_28 * V_209
)
{
T_1 V_43 , V_44 ;
const T_29 * V_210 ;
T_27 * V_211 ;
T_30 * V_212 ;
F_5 ((0 != mm_dependency_table->ucNumEntries),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( T_30 )
* V_209 -> V_51 ;
V_211 = F_10 ( V_43 , V_48 ) ;
if ( NULL == V_211 )
return - V_49 ;
memset ( V_211 , 0x00 , V_43 ) ;
V_211 -> V_50 = V_209 -> V_51 ;
for ( V_44 = 0 ; V_44 < V_209 -> V_51 ; V_44 ++ ) {
V_210 = F_11 (
T_29 ,
V_52 , V_209 , V_44 ) ;
V_212 = F_11 (
T_30 ,
V_52 , V_211 , V_44 ) ;
V_212 -> V_213 = V_210 -> V_138 ;
V_212 -> V_214 = V_210 -> V_140 ;
V_212 -> V_215 = V_210 -> V_216 ;
V_212 -> V_217 = V_210 -> V_218 ;
V_212 -> V_219 = V_210 -> V_220 ;
V_212 -> V_221 = V_210 -> V_222 ;
V_212 -> V_223 = V_210 -> V_224 ;
}
* V_208 = V_211 ;
return 0 ;
}
static int F_24 (
struct V_1 * V_2 ,
const V_37 * V_89
)
{
int V_90 = 0 ;
struct V_65 * V_66 =
(struct V_65 * ) ( V_2 -> V_67 ) ;
const T_28 * V_209 =
( const T_28 * ) ( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_225 ) ) ;
const T_14 * V_226 =
( const T_14 * ) ( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_227 ) ) ;
const T_12 * V_133 =
( const T_12 * ) ( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_228 ) ) ;
const T_14 * V_146 =
( const T_14 * ) ( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_229 ) ) ;
const T_11 * V_230 =
( const T_11 * ) ( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_231 ) ) ;
const T_14 * V_164 =
( const T_14 * ) ( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_232 ) ) ;
V_66 -> V_168 = NULL ;
V_66 -> V_233 = NULL ;
V_66 -> V_234 = NULL ;
V_66 -> V_164 = NULL ;
if ( V_89 -> V_225 != 0 )
V_90 = F_23 ( V_2 ,
& V_66 -> V_234 , V_209 ) ;
if ( V_90 == 0 && V_89 -> V_227 != 0 )
V_90 = F_21 ( V_2 ,
& V_66 -> V_179 , V_226 ) ;
if ( V_90 == 0 && V_89 -> V_229 != 0 )
V_90 = F_18 ( V_2 ,
& V_66 -> V_168 , V_146 ) ;
if ( V_90 == 0 && V_89 -> V_228 != 0 )
V_90 = F_17 ( V_2 ,
& V_66 -> V_233 , V_133 ) ;
if ( V_90 == 0 && V_89 -> V_232 != 0 )
V_90 = F_19 ( V_2 ,
& V_66 -> V_164 , V_164 ) ;
if ( V_90 == 0 && V_89 -> V_231 != 0 )
V_90 = F_16 ( V_2 ,
& V_66 -> V_235 , V_230 ) ;
V_2 -> V_178 . V_235 . V_121 =
V_66 -> V_235 . V_121 ;
V_2 -> V_178 . V_235 . V_123 =
V_66 -> V_235 . V_123 ;
V_2 -> V_178 . V_235 . V_125 =
V_66 -> V_235 . V_125 ;
V_2 -> V_178 . V_235 . V_128 =
V_66 -> V_235 . V_128 ;
if ( V_90 == 0 && ( NULL != V_66 -> V_233 )
&& ( 0 != V_66 -> V_233 -> V_50 ) )
V_90 = F_15 ( V_2 , & V_66 -> V_236 ,
V_66 -> V_233 ) ;
if ( V_90 == 0 && ( NULL != V_66 -> V_168 )
&& ( 0 != V_66 -> V_168 -> V_50 ) )
V_90 = F_15 ( V_2 , & V_66 -> V_237 ,
V_66 -> V_168 ) ;
return V_90 ;
}
static int F_25 (
struct V_1 * V_2 ,
const V_37 * V_89 )
{
V_2 -> V_6 . V_238 . V_239 =
F_14 ( V_89 -> V_240 ) ;
V_2 -> V_6 . V_238 . V_241 =
F_14 ( V_89 -> V_242 ) ;
V_2 -> V_6 . V_243 = 0 ;
V_2 -> V_6 . V_244 = 0 ;
V_2 -> V_6 . V_245 = 0 ;
if ( V_2 -> V_6 . V_238 . V_239 > 0 \
&& V_2 -> V_6 . V_238 . V_241 > 0 ) {
F_2 ( V_2 -> V_6 . V_7 ,
V_246 ) ;
}
return 0 ;
}
static int F_26 (
struct V_1 * V_2 ,
const V_37 * V_89
)
{
const T_14 * V_247 ;
T_31 * V_248 ;
V_248 = ( T_31 * )
( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_249 ) ) ;
F_5 ((0 != powerplay_table->usThermalControllerOffset),
L_9 , return -1 ) ;
V_2 -> V_248 . V_250 = V_248 -> V_250 ;
V_2 -> V_248 . V_251 = V_248 -> V_251 ;
V_2 -> V_248 . V_252 = V_248 -> V_252 ;
V_2 -> V_248 . V_253 . V_254 =
( 0 != ( V_248 -> V_255 & V_256 ) ) ;
V_2 -> V_248 . V_253 . V_257 =
V_248 -> V_255 &
V_258 ;
V_2 -> V_248 . V_253 . V_259
= V_248 -> V_260 * 100UL ;
V_2 -> V_248 . V_253 . V_261
= V_248 -> V_262 * 100UL ;
F_1 (
V_2 ,
V_263 != V_2 -> V_248 . V_250 ,
V_264
) ;
if ( 0 == V_89 -> V_265 )
return 0 ;
V_247 = ( const T_14 * )
( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_265 ) ) ;
F_5 ((0 != powerplay_table->usFanTableOffset),
L_10 , return -1 ) ;
F_5 ((0 < fan_table->ucRevId),
L_11 , return -1 ) ;
V_2 -> V_248 . V_266 . V_267
= 100000 ;
F_2 ( V_2 -> V_6 . V_7 ,
V_268 ) ;
if ( V_247 -> V_149 < 8 ) {
const T_32 * V_269 =
( T_32 * ) V_247 ;
V_2 -> V_248 . V_266 . V_270
= V_269 -> V_270 ;
V_2 -> V_248 . V_266 . V_271
= V_269 -> V_271 ;
V_2 -> V_248 . V_266 . V_272
= V_269 -> V_272 ;
V_2 -> V_248 . V_266 . V_273
= V_269 -> V_273 ;
V_2 -> V_248 . V_266 . V_274
= V_269 -> V_274 ;
V_2 -> V_248 . V_266 . V_275
= V_269 -> V_275 ;
V_2 -> V_248 . V_266 . V_276
= V_269 -> V_276 ;
V_2 -> V_248 . V_266 . V_277
= 10900 ;
V_2 -> V_248 . V_266 . V_277
= V_269 -> V_277 ;
V_2 -> V_248 . V_266 . V_278
= V_269 -> V_278 ;
V_2 -> V_248 . V_266 . V_279
= V_269 -> V_280 ;
V_2 -> V_248 . V_266 . V_281
= 4836 ;
V_2 -> V_248 . V_266 . V_282
= V_269 -> V_282 ;
V_2 -> V_248 . V_266 . V_283
= V_269 -> V_284 ;
V_2 -> V_248 . V_266 . V_285
= ( V_269 -> V_285 / 100 ) ;
V_2 -> V_248 . V_266 . V_286
= V_269 -> V_286 ;
V_2 -> V_248 . V_266 . V_287
= V_269 -> V_287 ;
} else {
const T_33 * V_288 =
( T_33 * ) V_247 ;
V_2 -> V_248 . V_266 . V_270
= V_288 -> V_270 ;
V_2 -> V_248 . V_266 . V_271
= V_288 -> V_271 ;
V_2 -> V_248 . V_266 . V_272
= V_288 -> V_272 ;
V_2 -> V_248 . V_266 . V_273
= V_288 -> V_273 ;
V_2 -> V_248 . V_266 . V_274
= V_288 -> V_274 ;
V_2 -> V_248 . V_266 . V_275
= V_288 -> V_275 ;
V_2 -> V_248 . V_266 . V_276
= V_288 -> V_276 ;
V_2 -> V_248 . V_266 . V_277
= V_288 -> V_277 ;
V_2 -> V_248 . V_266 . V_278
= V_288 -> V_278 ;
V_2 -> V_248 . V_266 . V_279
= V_288 -> V_280 ;
V_2 -> V_248 . V_266 . V_281
= 4836 ;
V_2 -> V_248 . V_266 . V_282
= V_288 -> V_282 ;
V_2 -> V_248 . V_266 . V_283
= V_288 -> V_284 ;
V_2 -> V_248 . V_266 . V_285
= ( V_288 -> V_285 / 100 ) ;
V_2 -> V_248 . V_266 . V_286
= V_288 -> V_286 ;
V_2 -> V_248 . V_266 . V_287
= V_288 -> V_287 ;
V_2 -> V_248 . V_266 . V_289
= V_288 -> V_289 ;
V_2 -> V_248 . V_266 . V_290
= V_288 -> V_290 ;
V_2 -> V_248 . V_266 . V_291
= V_288 -> V_291 ;
V_2 -> V_248 . V_266 . V_292
= V_288 -> V_292 ;
V_2 -> V_248 . V_266 . V_293
= V_288 -> V_293 ;
V_2 -> V_248 . V_266 . V_294
= V_288 -> V_294 ;
V_2 -> V_248 . V_266 . V_295
= V_288 -> V_295 ;
}
return 0 ;
}
static int F_27 (
struct V_1 * V_2 ,
const V_37 * V_89
)
{
const T_34 * V_296 ;
V_296 = ( T_34 * ) ( ( ( unsigned long ) V_89 ) +
F_14 ( V_89 -> V_297 ) ) ;
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
static int F_28 ( struct V_1 * V_2 )
{
int V_90 = 0 ;
const V_37 * V_89 ;
V_2 -> V_67 = F_10 ( sizeof( struct V_65 ) , V_48 ) ;
F_5 ((NULL != hwmgr->pptable),
L_14 , return -ENOMEM) ;
memset ( V_2 -> V_67 , 0x00 , sizeof( struct V_65 ) ) ;
V_89 = F_6 ( V_2 ) ;
F_5 ((NULL != powerplay_table),
L_15 , return -1 ) ;
V_90 = F_27 ( V_2 , V_89 ) ;
F_5 ((result == 0),
L_16 , return result) ;
V_90 = F_4 ( V_2 ,
F_29 ( V_89 -> V_298 ) ) ;
F_5 ((result == 0),
L_17 , return result) ;
V_90 = F_26 ( V_2 , V_89 ) ;
F_5 ((result == 0),
L_18 , return result) ;
V_90 = F_25 ( V_2 , V_89 ) ;
F_5 ((result == 0),
L_19 , return result) ;
V_90 = F_24 ( V_2 , V_89 ) ;
F_5 ((result == 0),
L_20 , return result) ;
V_90 = F_13 ( V_2 , V_89 ) ;
F_5 ((result == 0),
L_21 , return result) ;
return V_90 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_65 * V_66 =
(struct V_65 * ) ( V_2 -> V_67 ) ;
F_22 ( V_66 -> V_168 ) ;
V_66 -> V_168 = NULL ;
F_22 ( V_66 -> V_233 ) ;
V_66 -> V_233 = NULL ;
F_22 ( V_66 -> V_236 ) ;
V_66 -> V_236 = NULL ;
F_22 ( V_66 -> V_237 ) ;
V_66 -> V_237 = NULL ;
F_22 ( V_66 -> V_95 ) ;
V_66 -> V_95 = NULL ;
F_22 ( V_66 -> V_96 ) ;
V_66 -> V_96 = NULL ;
F_22 ( V_66 -> V_234 ) ;
V_66 -> V_234 = NULL ;
F_22 ( V_66 -> V_179 ) ;
V_66 -> V_179 = NULL ;
F_22 ( V_2 -> V_178 . V_179 ) ;
V_2 -> V_178 . V_179 = NULL ;
F_22 ( V_66 -> V_88 ) ;
V_66 -> V_88 = NULL ;
F_22 ( V_66 -> V_164 ) ;
V_66 -> V_164 = NULL ;
F_22 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
T_34 const * V_296 ;
const V_37 * V_299 = F_6 ( V_2 ) ;
F_5 ((NULL != pp_table),
L_15 , return -1 ) ;
F_5 ((pp_table->sHeader.ucTableFormatRevision >=
ATOM_Tonga_TABLE_REVISION_TONGA),
L_22 , return -1 ) ;
V_296 = ( T_34 * ) ( ( ( unsigned long ) V_299 ) +
F_14 ( V_299 -> V_297 ) ) ;
return ( T_1 ) ( V_296 -> V_51 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
V_126 V_300 , V_126 V_301 )
{
T_1 V_90 = 0 ;
if ( V_300 & V_302 )
V_90 |= V_303 ;
if ( V_300 & V_304 )
V_90 |= V_305 ;
if ( V_300 & V_306 )
V_90 |= V_307 ;
if ( V_300 & V_308 )
V_90 |= V_309 ;
if ( V_300 & V_310 )
V_90 |= V_311 ;
if ( V_300 & V_312 )
V_90 |= V_313 ;
if ( V_301 & V_314 )
V_90 |= V_315 ;
return V_90 ;
}
static int F_33 ( struct V_1 * V_2 )
{
const V_37 * V_299 = F_6 ( V_2 ) ;
const T_35 * V_316 ;
if ( V_299 == NULL )
return 0 ;
V_316 = ( void * ) V_299 +
F_14 ( V_299 -> V_317 ) ;
return V_316 -> V_51 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_44 ,
struct V_318 * V_319 , void * * V_320 , T_1 * V_321 )
{
const T_36 * V_322 ;
T_16 * V_151 ;
T_13 * V_136 ;
T_29 * V_323 ;
const V_37 * V_67 = F_6 ( V_2 ) ;
const T_35 * V_316 = ( T_35 * ) ( ( ( unsigned long ) V_67 )
+ F_14 ( V_67 -> V_317 ) ) ;
const T_15 * V_146 = ( T_15 * ) ( ( ( unsigned long ) V_67 )
+ F_14 ( V_67 -> V_229 ) ) ;
const T_12 * V_133 = ( T_12 * ) ( ( ( unsigned long ) V_67 )
+ F_14 ( V_67 -> V_228 ) ) ;
const T_28 * V_234 = ( T_28 * ) ( ( ( unsigned long ) V_67 )
+ F_14 ( V_67 -> V_225 ) ) ;
F_5 ((i < vce_state_table->ucNumEntries),
L_23 ,
return -EINVAL) ;
V_322 = F_11 (
T_36 ,
V_52 , V_316 , V_44 ) ;
V_151 = F_11 (
T_16 ,
V_52 , V_146 ,
V_322 -> V_324 ) ;
V_323 = F_11 (
T_29 ,
V_52 , V_234 ,
V_322 -> V_325 ) ;
* V_321 = V_322 -> V_326 ;
V_319 -> V_327 = V_323 -> V_220 ;
V_319 -> V_328 = V_323 -> V_220 ;
V_319 -> V_121 = V_151 -> V_154 ;
if ( V_322 -> V_329 >= V_133 -> V_51 )
V_136 = F_11 (
T_13 ,
V_52 , V_133 ,
V_133 -> V_51 - 1 ) ;
else
V_136 = F_11 (
T_13 ,
V_52 , V_133 ,
V_322 -> V_329 ) ;
V_319 -> V_123 = V_136 -> V_144 ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 ,
T_1 V_330 , struct V_331 * V_332 ,
int (* F_36)( struct V_1 * , void * ,
struct V_331 * , void * , T_1 ) )
{
int V_90 = 0 ;
const T_34 * V_296 ;
const T_37 * V_333 ;
const V_37 * V_299 = F_6 ( V_2 ) ;
int V_44 , V_334 ;
T_1 V_335 = 0 ;
F_5 ((NULL != pp_table), L_15 , return -1;) ;
V_332 -> V_300 . V_336 = V_330 ;
if ( V_299 -> V_337 . V_338 >=
V_339 ) {
V_296 = ( T_34 * ) ( ( ( unsigned long ) V_299 ) +
F_14 ( V_299 -> V_297 ) ) ;
F_5 ((0 < pp_table->usStateArrayOffset),
L_24 , return -1 ) ;
F_5 ((0 < state_arrays->ucNumEntries),
L_25 , return -1 ) ;
F_5 ((entry_index <= state_arrays->ucNumEntries),
L_26 , return -1 ) ;
V_333 = F_11 (
T_37 , V_52 ,
V_296 , V_330 ) ;
V_90 = F_36 ( V_2 , ( void * ) V_333 , V_332 ,
( void * ) V_299 ,
F_32 ( V_2 ,
F_14 ( V_333 -> V_340 ) ,
F_14 ( V_333 -> V_341 ) ) ) ;
}
if ( ! V_90 && ( V_332 -> V_300 . V_335 &
V_303 ) )
V_90 = V_2 -> V_342 -> V_343 ( V_2 , & ( V_332 -> V_344 ) ) ;
V_2 -> V_345 = V_44 = F_33 ( V_2 ) ;
if ( ( V_44 != 0 ) && ( V_44 <= V_346 ) ) {
for ( V_334 = 0 ; V_334 < V_44 ; V_334 ++ )
F_34 ( V_2 , V_334 , & ( V_2 -> V_347 [ V_334 ] ) , NULL , & V_335 ) ;
}
return V_90 ;
}
