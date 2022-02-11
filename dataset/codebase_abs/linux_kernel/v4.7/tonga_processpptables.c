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
F_5 ((0 != vddc_lookup_pp_tables->ucNumEntries),
L_6 , return 1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( V_46 ) * V_42 ;
V_45 = ( T_4 * )
F_10 ( V_43 , V_47 ) ;
if ( NULL == V_45 )
return - V_48 ;
memset ( V_45 , 0x00 , V_43 ) ;
V_45 -> V_49 = V_41 -> V_50 ;
for ( V_44 = 0 ; V_44 < V_41 -> V_50 ; V_44 ++ ) {
V_45 -> V_51 [ V_44 ] . V_52 = 0 ;
V_45 -> V_51 [ V_44 ] . V_53 =
V_41 -> V_51 [ V_44 ] . V_54 ;
V_45 -> V_51 [ V_44 ] . V_55 =
V_41 -> V_51 [ V_44 ] . V_56 ;
V_45 -> V_51 [ V_44 ] . V_57 =
V_41 -> V_51 [ V_44 ] . V_58 ;
V_45 -> V_51 [ V_44 ] . V_59 =
V_41 -> V_51 [ V_44 ] . V_60 ;
}
* V_40 = V_45 ;
return 0 ;
}
static int F_11 (
struct V_1 * V_2 ,
T_6 * V_61 )
{
struct V_62 * V_63 = F_10 ( sizeof( T_6 ) , V_47 ) ;
struct V_64 * V_65 =
(struct V_64 * ) ( V_2 -> V_66 ) ;
if ( NULL == V_63 )
return - V_48 ;
V_63 -> V_67
= V_61 -> V_68 ;
V_63 -> V_69
= V_61 -> V_70 ;
V_63 -> V_71
= V_61 -> V_72 ;
V_63 -> V_73
= V_61 -> V_74 ;
V_63 -> V_75
= V_61 -> V_76 ;
V_63 -> V_77
= V_61 -> V_78 ;
V_63 -> V_79
= V_61 -> V_80 ;
V_63 -> V_81
= V_61 -> V_82 ;
V_63 -> V_83
= V_61 -> V_84 ;
V_63 -> V_85
= V_61 -> V_86 ;
V_65 -> V_87 = V_63 ;
return 0 ;
}
static int F_12 (
struct V_1 * V_2 ,
const V_37 * V_88
)
{
int V_89 = 0 ;
struct V_64 * V_65 = (struct V_64 * ) ( V_2 -> V_66 ) ;
T_6 * V_61 ;
T_1 V_90 = 0 ;
T_1 V_91 = 0 ;
V_65 -> V_92 =
F_13 ( V_88 -> V_93 ) ;
V_65 -> V_87 = NULL ;
V_65 -> V_94 = NULL ;
V_65 -> V_95 = NULL ;
V_2 -> V_6 . V_96 =
F_13 ( V_88 -> V_97 ) ;
V_2 -> V_6 . V_98 = 0 ;
V_2 -> V_6 . V_99 = 0 ;
V_2 -> V_6 . V_100 = 0 ;
V_2 -> V_6 . V_101 = 0 ;
V_2 -> V_6 . V_102 = 1500000 ;
V_2 -> V_6 . V_103 = 6250 ;
V_91 = 0 ;
if ( 0 == V_91 ) {
if ( V_2 -> V_6 . V_96 != 0 )
F_2 ( V_2 -> V_6 . V_7 ,
V_104 ) ;
}
if ( 0 != V_88 -> V_105 ) {
const T_5 * V_106 =
( T_5 * ) ( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_105 ) ) ;
V_89 = F_9 ( V_2 ,
& V_65 -> V_94 , V_106 , 16 ) ;
}
if ( 0 != V_88 -> V_107 ) {
const T_5 * V_108 =
( T_5 * ) ( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_107 ) ) ;
V_89 = F_9 ( V_2 ,
& V_65 -> V_95 , V_108 , 16 ) ;
}
V_90 = 0 ;
if ( 0 == V_90 ) {
V_61 = ( T_6 * )
( ( ( unsigned long ) V_88 ) + F_13 ( V_88 -> V_109 ) ) ;
if ( 0 != V_88 -> V_109 ) {
if ( F_11 ( V_2 , V_61 ) == 0 ) {
F_2 ( V_2 -> V_6 . V_7 ,
V_110 ) ;
}
}
}
return V_89 ;
}
static int F_14 (
struct V_1 * V_2 ,
struct V_111 * * V_112 ,
const T_7 * V_113
)
{
T_1 V_43 , V_44 ;
struct V_111 * V_45 ;
F_5 ((0 != clk_volt_pp_table->count),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( T_1 ) * V_113 -> V_49 ;
V_45 = (struct V_111 * ) F_10 ( V_43 , V_47 ) ;
if ( NULL == V_45 )
return - V_48 ;
memset ( V_45 , 0x00 , V_43 ) ;
V_45 -> V_49 = ( T_1 ) V_113 -> V_49 ;
for ( V_44 = 0 ; V_44 < V_45 -> V_49 ; V_44 ++ )
V_45 -> V_114 [ V_44 ] = ( T_1 ) V_113 -> V_51 [ V_44 ] . V_115 ;
* V_112 = V_45 ;
return 0 ;
}
static int F_15 (
struct V_1 * V_2 ,
struct V_116 * V_117 ,
const T_8 * V_118
)
{
F_5 ((0 != limitable->ucNumEntries), L_7 , return -1 ) ;
V_117 -> V_119 = ( T_1 ) V_118 -> V_51 [ 0 ] . V_120 ;
V_117 -> V_121 = ( T_1 ) V_118 -> V_51 [ 0 ] . V_122 ;
V_117 -> V_123 = ( V_124 ) V_118 -> V_51 [ 0 ] . V_125 ;
V_117 -> V_126 = ( V_124 ) V_118 -> V_51 [ 0 ] . V_127 ;
V_117 -> V_128 = ( V_124 ) V_118 -> V_51 [ 0 ] . V_129 ;
return 0 ;
}
static int F_16 (
struct V_1 * V_2 ,
T_7 * * V_130 ,
const T_9 * V_131
)
{
T_1 V_43 , V_44 ;
T_7 * V_132 ;
F_5 ((0 != mclk_dep_table->ucNumEntries),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) + sizeof( V_133 )
* V_131 -> V_50 ;
V_132 = ( T_7 * )
F_10 ( V_43 , V_47 ) ;
if ( NULL == V_132 )
return - V_48 ;
memset ( V_132 , 0x00 , V_43 ) ;
V_132 -> V_49 = ( T_1 ) V_131 -> V_50 ;
for ( V_44 = 0 ; V_44 < V_131 -> V_50 ; V_44 ++ ) {
V_132 -> V_51 [ V_44 ] . V_134 =
V_131 -> V_51 [ V_44 ] . V_135 ;
V_132 -> V_51 [ V_44 ] . V_136 =
V_131 -> V_51 [ V_44 ] . V_137 ;
V_132 -> V_51 [ V_44 ] . V_126 =
V_131 -> V_51 [ V_44 ] . V_138 ;
V_132 -> V_51 [ V_44 ] . V_139 =
V_131 -> V_51 [ V_44 ] . V_140 ;
V_132 -> V_51 [ V_44 ] . V_115 =
V_131 -> V_51 [ V_44 ] . V_141 ;
}
* V_130 = V_132 ;
return 0 ;
}
static int F_17 (
struct V_1 * V_2 ,
T_7 * * V_142 ,
const T_10 * V_143
)
{
T_1 V_43 , V_44 ;
T_7 * V_144 ;
if ( V_143 -> V_145 < 1 ) {
const T_11 * V_146 =
( T_11 * ) V_143 ;
F_5 ((0 != tonga_table->ucNumEntries),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) + sizeof( V_133 )
* V_146 -> V_50 ;
V_144 = ( T_7 * )
F_10 ( V_43 , V_47 ) ;
if ( NULL == V_144 )
return - V_48 ;
memset ( V_144 , 0x00 , V_43 ) ;
V_144 -> V_49 = ( T_1 ) V_146 -> V_50 ;
for ( V_44 = 0 ; V_44 < V_146 -> V_50 ; V_44 ++ ) {
V_144 -> V_51 [ V_44 ] . V_134 =
V_146 -> V_51 [ V_44 ] . V_147 ;
V_144 -> V_51 [ V_44 ] . V_136 =
V_146 -> V_51 [ V_44 ] . V_148 ;
V_144 -> V_51 [ V_44 ] . V_115 =
V_146 -> V_51 [ V_44 ] . V_149 ;
V_144 -> V_51 [ V_44 ] . V_150 =
( ( ( V_146 -> V_51 [ V_44 ] . V_151 & 0x80 ) >> 7 ) == 0 ) ? 1 : 0 ;
V_144 -> V_51 [ V_44 ] . V_152 =
( V_146 -> V_51 [ V_44 ] . V_151 & 0x7F ) ;
}
} else {
const T_12 * V_153 =
( T_12 * ) V_143 ;
F_5 ((0 != polaris_table->ucNumEntries),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) + sizeof( V_133 )
* V_153 -> V_50 ;
V_144 = ( T_7 * )
F_10 ( V_43 , V_47 ) ;
if ( NULL == V_144 )
return - V_48 ;
memset ( V_144 , 0x00 , V_43 ) ;
V_144 -> V_49 = ( T_1 ) V_153 -> V_50 ;
for ( V_44 = 0 ; V_44 < V_153 -> V_50 ; V_44 ++ ) {
V_144 -> V_51 [ V_44 ] . V_134 =
V_153 -> V_51 [ V_44 ] . V_147 ;
V_144 -> V_51 [ V_44 ] . V_136 =
V_153 -> V_51 [ V_44 ] . V_148 ;
V_144 -> V_51 [ V_44 ] . V_115 =
V_153 -> V_51 [ V_44 ] . V_149 ;
V_144 -> V_51 [ V_44 ] . V_150 =
( ( ( V_153 -> V_51 [ V_44 ] . V_151 & 0x80 ) >> 7 ) == 0 ) ? 1 : 0 ;
V_144 -> V_51 [ V_44 ] . V_152 =
( V_153 -> V_51 [ V_44 ] . V_151 & 0x7F ) ;
V_144 -> V_51 [ V_44 ] . V_154 = V_153 -> V_51 [ V_44 ] . V_155 ;
}
}
* V_142 = V_144 ;
return 0 ;
}
static int F_18 (
struct V_1 * V_2 ,
T_13 * * V_156 ,
const T_10 * V_157
)
{
T_1 V_43 , V_44 , V_158 ;
T_13 * V_159 ;
struct V_64 * V_65 =
(struct V_64 * ) ( V_2 -> V_66 ) ;
if ( V_157 -> V_145 < 1 ) {
const T_14 * V_160 = ( T_14 * ) V_157 ;
F_5 ((atom_pcie_table->ucNumEntries != 0),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( V_161 ) * V_160 -> V_50 ;
V_159 = ( T_13 * ) F_10 ( V_43 , V_47 ) ;
if ( V_159 == NULL )
return - V_48 ;
memset ( V_159 , 0x00 , V_43 ) ;
V_158 = ( V_65 -> V_162 -> V_49 ) + 1 ;
if ( ( T_1 ) V_160 -> V_50 <= V_158 )
V_158 = ( T_1 ) V_160 -> V_50 ;
else
F_19 ( V_163 L_8 ) ;
V_159 -> V_49 = V_158 ;
for ( V_44 = 0 ; V_44 < V_158 ; V_44 ++ ) {
V_159 -> V_51 [ V_44 ] . V_164 =
V_160 -> V_51 [ V_44 ] . V_165 ;
V_159 -> V_51 [ V_44 ] . V_166 =
V_160 -> V_51 [ V_44 ] . V_167 ;
}
* V_156 = V_159 ;
} else {
const T_15 * V_160 = ( T_15 * ) V_157 ;
F_5 ((atom_pcie_table->ucNumEntries != 0),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( V_161 ) * V_160 -> V_50 ;
V_159 = ( T_13 * ) F_10 ( V_43 , V_47 ) ;
if ( V_159 == NULL )
return - V_48 ;
memset ( V_159 , 0x00 , V_43 ) ;
V_158 = ( V_65 -> V_162 -> V_49 ) + 1 ;
if ( ( T_1 ) V_160 -> V_50 <= V_158 )
V_158 = ( T_1 ) V_160 -> V_50 ;
else
F_19 ( V_163 L_8 ) ;
V_159 -> V_49 = V_158 ;
for ( V_44 = 0 ; V_44 < V_158 ; V_44 ++ ) {
V_159 -> V_51 [ V_44 ] . V_164 =
V_160 -> V_51 [ V_44 ] . V_165 ;
V_159 -> V_51 [ V_44 ] . V_166 =
V_160 -> V_51 [ V_44 ] . V_167 ;
V_159 -> V_51 [ V_44 ] . V_168 =
V_160 -> V_51 [ V_44 ] . V_169 ;
}
* V_156 = V_159 ;
}
return 0 ;
}
static int F_20 (
struct V_1 * V_2 ,
struct V_170 * * V_171 ,
const T_10 * V_45
)
{
T_1 V_43 ;
struct V_170 * V_172 ;
V_43 = sizeof( T_1 ) + sizeof( struct V_170 ) ;
V_172 = F_10 ( V_43 , V_47 ) ;
if ( NULL == V_172 )
return - V_48 ;
memset ( V_172 , 0x00 , V_43 ) ;
V_2 -> V_173 . V_174 = F_10 ( V_43 , V_47 ) ;
if ( NULL == V_2 -> V_173 . V_174 ) {
F_21 ( V_172 ) ;
return - V_48 ;
}
memset ( V_2 -> V_173 . V_174 , 0x00 , V_43 ) ;
if ( V_45 -> V_145 < 3 ) {
const T_16 * V_146 =
( T_16 * ) V_45 ;
V_172 -> V_175 = V_146 -> V_175 ;
V_172 -> V_176 =
V_146 -> V_176 ;
V_172 -> V_177 = V_146 -> V_177 ;
V_172 -> V_178 =
V_146 -> V_178 ;
V_172 -> V_179 =
V_146 -> V_179 ;
V_172 -> V_180 =
V_146 -> V_180 ;
V_172 -> V_181 =
V_146 -> V_181 ;
V_172 -> V_182 =
V_146 -> V_182 ;
V_172 -> V_183 =
V_146 -> V_184 ;
V_172 -> V_185 =
V_146 -> V_184 ;
V_172 -> V_186 =
V_146 -> V_186 ;
V_172 -> V_187 =
V_146 -> V_187 ;
V_172 -> V_188 =
V_146 -> V_188 ;
} else {
const T_17 * V_189 =
( T_17 * ) V_45 ;
V_172 -> V_175 = V_189 -> V_175 ;
V_172 -> V_176 = V_189 -> V_176 ;
V_172 -> V_177 = V_189 -> V_177 ;
V_172 -> V_178 = V_189 -> V_178 ;
V_172 -> V_179 = V_189 -> V_179 ;
V_172 -> V_180 = V_189 -> V_180 ;
V_172 -> V_181 = V_189 -> V_181 ;
V_172 -> V_182 =
V_189 -> V_182 ;
V_172 -> V_183 =
V_189 -> V_184 ;
V_172 -> V_185 =
V_189 -> V_184 ;
V_172 -> V_186 =
V_189 -> V_186 ;
V_172 -> V_187 =
V_189 -> V_187 ;
V_172 -> V_188 =
V_189 -> V_188 ;
V_172 -> V_190 =
V_189 -> V_190 ;
V_172 -> V_191 =
V_189 -> V_191 ;
V_172 -> V_192 =
V_189 -> V_192 ;
V_172 -> V_193 =
V_189 -> V_193 ;
V_172 -> V_194 =
V_189 -> V_194 ;
V_172 -> V_195 =
V_189 -> V_195 ;
V_172 -> V_196 =
V_189 -> V_196 ;
V_172 -> V_197 =
V_189 -> V_197 ;
V_172 -> V_198 =
V_189 -> V_198 ;
V_172 -> V_199 = V_189 -> V_199 ;
V_172 -> V_200 = V_189 -> V_200 ;
V_172 -> V_201 = V_189 -> V_201 ;
V_172 -> V_202 = V_189 -> V_202 ;
}
* V_171 = V_172 ;
return 0 ;
}
static int F_22 (
struct V_1 * V_2 ,
T_18 * * V_203 ,
const T_19 * V_204
)
{
T_1 V_43 , V_44 ;
const T_20 * V_205 ;
T_18 * V_206 ;
F_5 ((0 != mm_dependency_table->ucNumEntries),
L_7 , return -1 ) ;
V_43 = sizeof( T_1 ) +
sizeof( V_207 )
* V_204 -> V_50 ;
V_206 = ( T_18 * )
F_10 ( V_43 , V_47 ) ;
if ( NULL == V_206 )
return - V_48 ;
memset ( V_206 , 0x00 , V_43 ) ;
V_206 -> V_49 = V_204 -> V_50 ;
for ( V_44 = 0 ; V_44 < V_204 -> V_50 ; V_44 ++ ) {
V_205 = & V_204 -> V_51 [ V_44 ] ;
V_206 -> V_51 [ V_44 ] . V_208 = V_205 -> V_135 ;
V_206 -> V_51 [ V_44 ] . V_209 = V_205 -> V_137 ;
V_206 -> V_51 [ V_44 ] . V_210 = V_205 -> V_211 ;
V_206 -> V_51 [ V_44 ] . V_212 = V_205 -> V_213 ;
V_206 -> V_51 [ V_44 ] . V_214 = V_205 -> V_215 ;
V_206 -> V_51 [ V_44 ] . V_216 = V_205 -> V_217 ;
V_206 -> V_51 [ V_44 ] . V_218 = V_205 -> V_219 ;
}
* V_203 = V_206 ;
return 0 ;
}
static int F_23 (
struct V_1 * V_2 ,
const V_37 * V_88
)
{
int V_89 = 0 ;
struct V_64 * V_65 =
(struct V_64 * ) ( V_2 -> V_66 ) ;
const T_19 * V_204 =
( const T_19 * ) ( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_220 ) ) ;
const T_10 * V_221 =
( const T_10 * ) ( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_222 ) ) ;
const T_9 * V_131 =
( const T_9 * ) ( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_223 ) ) ;
const T_10 * V_143 =
( const T_10 * ) ( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_224 ) ) ;
const T_8 * V_225 =
( const T_8 * ) ( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_226 ) ) ;
const T_10 * V_159 =
( const T_10 * ) ( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_227 ) ) ;
V_65 -> V_162 = NULL ;
V_65 -> V_228 = NULL ;
V_65 -> V_229 = NULL ;
V_65 -> V_159 = NULL ;
if ( V_88 -> V_220 != 0 )
V_89 = F_22 ( V_2 ,
& V_65 -> V_229 , V_204 ) ;
if ( V_89 == 0 && V_88 -> V_222 != 0 )
V_89 = F_20 ( V_2 ,
& V_65 -> V_174 , V_221 ) ;
if ( V_89 == 0 && V_88 -> V_224 != 0 )
V_89 = F_17 ( V_2 ,
& V_65 -> V_162 , V_143 ) ;
if ( V_89 == 0 && V_88 -> V_223 != 0 )
V_89 = F_16 ( V_2 ,
& V_65 -> V_228 , V_131 ) ;
if ( V_89 == 0 && V_88 -> V_227 != 0 )
V_89 = F_18 ( V_2 ,
& V_65 -> V_159 , V_159 ) ;
if ( V_89 == 0 && V_88 -> V_226 != 0 )
V_89 = F_15 ( V_2 ,
& V_65 -> V_230 , V_225 ) ;
V_2 -> V_173 . V_230 . V_119 =
V_65 -> V_230 . V_119 ;
V_2 -> V_173 . V_230 . V_121 =
V_65 -> V_230 . V_121 ;
V_2 -> V_173 . V_230 . V_123 =
V_65 -> V_230 . V_123 ;
V_2 -> V_173 . V_230 . V_126 =
V_65 -> V_230 . V_126 ;
if ( V_89 == 0 && ( NULL != V_65 -> V_228 )
&& ( 0 != V_65 -> V_228 -> V_49 ) )
V_89 = F_14 ( V_2 , & V_65 -> V_231 ,
V_65 -> V_228 ) ;
if ( V_89 == 0 && ( NULL != V_65 -> V_162 )
&& ( 0 != V_65 -> V_162 -> V_49 ) )
V_89 = F_14 ( V_2 , & V_65 -> V_232 ,
V_65 -> V_162 ) ;
return V_89 ;
}
static int F_24 (
struct V_1 * V_2 ,
const V_37 * V_88 )
{
V_2 -> V_6 . V_233 . V_234 =
F_13 ( V_88 -> V_235 ) ;
V_2 -> V_6 . V_233 . V_236 =
F_13 ( V_88 -> V_237 ) ;
V_2 -> V_6 . V_238 = 0 ;
V_2 -> V_6 . V_239 = 0 ;
V_2 -> V_6 . V_240 = 0 ;
if ( V_2 -> V_6 . V_233 . V_234 > 0 \
&& V_2 -> V_6 . V_233 . V_236 > 0 ) {
F_2 ( V_2 -> V_6 . V_7 ,
V_241 ) ;
}
return 0 ;
}
static int F_25 (
struct V_1 * V_2 ,
const V_37 * V_88
)
{
const T_10 * V_242 ;
T_21 * V_243 ;
V_243 = ( T_21 * )
( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_244 ) ) ;
F_5 ((0 != powerplay_table->usThermalControllerOffset),
L_9 , return -1 ) ;
V_2 -> V_243 . V_245 = V_243 -> V_245 ;
V_2 -> V_243 . V_246 = V_243 -> V_246 ;
V_2 -> V_243 . V_247 = V_243 -> V_247 ;
V_2 -> V_243 . V_248 . V_249 =
( 0 != ( V_243 -> V_250 & V_251 ) ) ;
V_2 -> V_243 . V_248 . V_252 =
V_243 -> V_250 &
V_253 ;
V_2 -> V_243 . V_248 . V_254
= V_243 -> V_255 * 100UL ;
V_2 -> V_243 . V_248 . V_256
= V_243 -> V_257 * 100UL ;
F_1 (
V_2 ,
V_258 != V_2 -> V_243 . V_245 ,
V_259
) ;
if ( 0 == V_88 -> V_260 )
return 0 ;
V_242 = ( const T_10 * )
( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_260 ) ) ;
F_5 ((0 != powerplay_table->usFanTableOffset),
L_10 , return -1 ) ;
F_5 ((0 < fan_table->ucRevId),
L_11 , return -1 ) ;
V_2 -> V_243 . V_261 . V_262
= 100000 ;
F_2 ( V_2 -> V_6 . V_7 ,
V_263 ) ;
if ( V_242 -> V_145 < 8 ) {
const T_22 * V_264 =
( T_22 * ) V_242 ;
V_2 -> V_243 . V_261 . V_265
= V_264 -> V_265 ;
V_2 -> V_243 . V_261 . V_266
= V_264 -> V_266 ;
V_2 -> V_243 . V_261 . V_267
= V_264 -> V_267 ;
V_2 -> V_243 . V_261 . V_268
= V_264 -> V_268 ;
V_2 -> V_243 . V_261 . V_269
= V_264 -> V_269 ;
V_2 -> V_243 . V_261 . V_270
= V_264 -> V_270 ;
V_2 -> V_243 . V_261 . V_271
= V_264 -> V_271 ;
V_2 -> V_243 . V_261 . V_272
= 10900 ;
V_2 -> V_243 . V_261 . V_272
= V_264 -> V_272 ;
V_2 -> V_243 . V_261 . V_273
= V_264 -> V_273 ;
V_2 -> V_243 . V_261 . V_274
= V_264 -> V_275 ;
V_2 -> V_243 . V_261 . V_276
= 4836 ;
V_2 -> V_243 . V_261 . V_277
= V_264 -> V_277 ;
V_2 -> V_243 . V_261 . V_278
= V_264 -> V_279 ;
V_2 -> V_243 . V_261 . V_280
= ( V_264 -> V_280 / 100 ) ;
V_2 -> V_243 . V_261 . V_281
= V_264 -> V_281 ;
V_2 -> V_243 . V_261 . V_282
= V_264 -> V_282 ;
} else {
const T_23 * V_283 =
( T_23 * ) V_242 ;
V_2 -> V_243 . V_261 . V_265
= V_283 -> V_265 ;
V_2 -> V_243 . V_261 . V_266
= V_283 -> V_266 ;
V_2 -> V_243 . V_261 . V_267
= V_283 -> V_267 ;
V_2 -> V_243 . V_261 . V_268
= V_283 -> V_268 ;
V_2 -> V_243 . V_261 . V_269
= V_283 -> V_269 ;
V_2 -> V_243 . V_261 . V_270
= V_283 -> V_270 ;
V_2 -> V_243 . V_261 . V_271
= V_283 -> V_271 ;
V_2 -> V_243 . V_261 . V_272
= V_283 -> V_272 ;
V_2 -> V_243 . V_261 . V_273
= V_283 -> V_273 ;
V_2 -> V_243 . V_261 . V_274
= V_283 -> V_275 ;
V_2 -> V_243 . V_261 . V_276
= 4836 ;
V_2 -> V_243 . V_261 . V_277
= V_283 -> V_277 ;
V_2 -> V_243 . V_261 . V_278
= V_283 -> V_279 ;
V_2 -> V_243 . V_261 . V_280
= ( V_283 -> V_280 / 100 ) ;
V_2 -> V_243 . V_261 . V_281
= V_283 -> V_281 ;
V_2 -> V_243 . V_261 . V_282
= V_283 -> V_282 ;
V_2 -> V_243 . V_261 . V_284
= V_283 -> V_284 ;
V_2 -> V_243 . V_261 . V_285
= V_283 -> V_285 ;
V_2 -> V_243 . V_261 . V_286
= V_283 -> V_286 ;
V_2 -> V_243 . V_261 . V_287
= V_283 -> V_287 ;
V_2 -> V_243 . V_261 . V_288
= V_283 -> V_288 ;
V_2 -> V_243 . V_261 . V_289
= V_283 -> V_289 ;
V_2 -> V_243 . V_261 . V_290
= V_283 -> V_290 ;
}
return 0 ;
}
static int F_26 (
struct V_1 * V_2 ,
const V_37 * V_88
)
{
const T_24 * V_291 ;
V_291 = ( T_24 * ) ( ( ( unsigned long ) V_88 ) +
F_13 ( V_88 -> V_292 ) ) ;
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
int F_27 ( struct V_1 * V_2 )
{
int V_89 = 0 ;
const V_37 * V_88 ;
V_2 -> V_66 = F_10 ( sizeof( struct V_64 ) , V_47 ) ;
F_5 ((NULL != hwmgr->pptable),
L_14 , return -ENOMEM) ;
memset ( V_2 -> V_66 , 0x00 , sizeof( struct V_64 ) ) ;
V_88 = F_6 ( V_2 ) ;
F_5 ((NULL != powerplay_table),
L_15 , return -1 ) ;
V_89 = F_26 ( V_2 , V_88 ) ;
F_5 ((result == 0),
L_16 , return result) ;
V_89 = F_4 ( V_2 ,
F_28 ( V_88 -> V_293 ) ) ;
F_5 ((result == 0),
L_17 , return result) ;
V_89 = F_25 ( V_2 , V_88 ) ;
F_5 ((result == 0),
L_18 , return result) ;
V_89 = F_24 ( V_2 , V_88 ) ;
F_5 ((result == 0),
L_19 , return result) ;
V_89 = F_23 ( V_2 , V_88 ) ;
F_5 ((result == 0),
L_20 , return result) ;
V_89 = F_12 ( V_2 , V_88 ) ;
F_5 ((result == 0),
L_21 , return result) ;
return V_89 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_89 = 0 ;
struct V_64 * V_65 =
(struct V_64 * ) ( V_2 -> V_66 ) ;
if ( NULL != V_2 -> V_36 )
V_2 -> V_36 = NULL ;
F_21 ( V_65 -> V_162 ) ;
V_65 -> V_162 = NULL ;
F_21 ( V_65 -> V_228 ) ;
V_65 -> V_228 = NULL ;
F_21 ( V_65 -> V_231 ) ;
V_65 -> V_231 = NULL ;
F_21 ( V_65 -> V_232 ) ;
V_65 -> V_232 = NULL ;
F_21 ( V_65 -> V_94 ) ;
V_65 -> V_94 = NULL ;
F_21 ( V_65 -> V_95 ) ;
V_65 -> V_95 = NULL ;
F_21 ( V_65 -> V_229 ) ;
V_65 -> V_229 = NULL ;
F_21 ( V_65 -> V_174 ) ;
V_65 -> V_174 = NULL ;
F_21 ( V_2 -> V_173 . V_174 ) ;
V_2 -> V_173 . V_174 = NULL ;
F_21 ( V_65 -> V_87 ) ;
V_65 -> V_87 = NULL ;
F_21 ( V_65 -> V_159 ) ;
V_65 -> V_159 = NULL ;
F_21 ( V_2 -> V_66 ) ;
V_2 -> V_66 = NULL ;
return V_89 ;
}
int F_30 ( struct V_1 * V_2 )
{
const T_24 * V_291 ;
const V_37 * V_294 = F_6 ( V_2 ) ;
F_5 ((NULL != pp_table),
L_15 , return -1 ) ;
F_5 ((pp_table->sHeader.ucTableFormatRevision >=
ATOM_Tonga_TABLE_REVISION_TONGA),
L_22 , return -1 ) ;
V_291 = ( T_24 * ) ( ( ( unsigned long ) V_294 ) +
F_13 ( V_294 -> V_292 ) ) ;
return ( T_1 ) ( V_291 -> V_50 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
V_124 V_295 , V_124 V_296 )
{
T_1 V_89 = 0 ;
if ( V_295 & V_297 )
V_89 |= V_298 ;
if ( V_295 & V_299 )
V_89 |= V_300 ;
if ( V_295 & V_301 )
V_89 |= V_302 ;
if ( V_295 & V_303 )
V_89 |= V_304 ;
if ( V_295 & V_305 )
V_89 |= V_306 ;
if ( V_295 & V_307 )
V_89 |= V_308 ;
if ( V_296 & V_309 )
V_89 |= V_310 ;
return V_89 ;
}
int F_32 ( struct V_1 * V_2 ,
T_1 V_311 , struct V_312 * V_313 ,
int (* F_33)( struct V_1 * , void * ,
struct V_312 * , void * , T_1 ) )
{
int V_89 = 0 ;
const T_24 * V_291 ;
const T_25 * V_314 ;
const V_37 * V_294 = F_6 ( V_2 ) ;
F_5 ((NULL != pp_table), L_15 , return -1;) ;
V_313 -> V_295 . V_315 = V_311 ;
if ( V_294 -> V_316 . V_317 >=
V_318 ) {
V_291 = ( T_24 * ) ( ( ( unsigned long ) V_294 ) +
F_13 ( V_294 -> V_292 ) ) ;
F_5 ((0 < pp_table->usStateArrayOffset),
L_23 , return -1 ) ;
F_5 ((0 < state_arrays->ucNumEntries),
L_24 , return -1 ) ;
F_5 ((entry_index <= state_arrays->ucNumEntries),
L_25 , return -1 ) ;
V_314 = & ( V_291 -> V_319 [ V_311 ] ) ;
V_89 = F_33 ( V_2 , ( void * ) V_314 , V_313 ,
( void * ) V_294 ,
F_31 ( V_2 ,
F_13 ( V_314 -> V_320 ) ,
F_13 ( V_314 -> V_321 ) ) ) ;
}
if ( ! V_89 && ( V_313 -> V_295 . V_322 &
V_298 ) )
V_89 = V_2 -> V_323 -> V_324 ( V_2 , & ( V_313 -> V_325 ) ) ;
return V_89 ;
}
