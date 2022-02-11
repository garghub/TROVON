static void F_1 ( struct V_1 * V_2 , bool V_3 ,
enum V_4 V_5 )
{
if ( V_3 )
F_2 ( V_2 -> V_6 . V_7 , V_5 ) ;
else
F_3 ( V_2 -> V_6 . V_7 , V_5 ) ;
}
static const void * F_4 ( struct V_1 * V_2 )
{
int V_8 = F_5 ( V_9 ) ;
T_1 V_10 ;
T_2 V_11 , V_12 ;
const void * V_13 = V_2 -> V_14 ;
if ( ! V_13 ) {
V_13 = ( V_15 * )
F_6 ( V_2 -> V_16 , V_8 ,
& V_10 , & V_11 , & V_12 ) ;
V_2 -> V_14 = V_13 ;
}
return V_13 ;
}
static int F_7 (
struct V_1 * V_2 ,
const V_15 * V_17 )
{
const T_3 * V_18 ;
V_18 = ( T_3 * ) ( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_19 ) ) ;
F_9 ((powerplay_table->sHeader.format_revision >=
ATOM_Vega10_TABLE_REVISION_VEGA10),
L_1 , return -1 ) ;
F_9 (powerplay_table->usStateArrayOffset,
L_2 , return -1 ) ;
F_9 (powerplay_table->sHeader.structuresize > 0 ,
L_3 , return -1 ) ;
F_9 (state_arrays->ucNumEntries > 0 ,
L_3 , return -1 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_4 V_20 )
{
F_1 (
V_2 ,
0 != ( V_20 & V_21 ) ,
V_22 ) ;
F_1 (
V_2 ,
0 != ( V_20 & V_23 ) ,
V_24 ) ;
F_1 (
V_2 ,
0 != ( V_20 & V_25 ) ,
V_26 ) ;
F_1 (
V_2 ,
0 != ( V_20 & V_27 ) ,
V_28 ) ;
F_1 (
V_2 ,
0 != ( V_20 & V_29 ) ,
V_30 ) ;
return 0 ;
}
static int F_11 (
struct V_1 * V_2 ,
const V_15 * V_17 )
{
const T_5 * V_31 ;
const T_6 * V_32 ;
const T_7 * V_33 ;
const T_8 * V_34 ;
V_31 = ( T_5 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_35 ) ) ;
F_9 ((powerplay_table->usThermalControllerOffset != 0),
L_4 , return -EINVAL) ;
V_2 -> V_31 . V_36 = V_31 -> V_36 ;
V_2 -> V_31 . V_37 = V_31 -> V_37 ;
V_2 -> V_31 . V_38 = V_31 -> V_38 ;
V_2 -> V_31 . V_39 . V_40 =
( 0 != ( V_31 -> V_41 &
V_42 ) ) ;
V_2 -> V_31 . V_39 . V_43 =
V_31 -> V_41 &
V_44 ;
V_2 -> V_31 . V_39 . V_45 =
V_31 -> V_46 * 100UL ;
V_2 -> V_31 . V_39 . V_47 =
V_31 -> V_48 * 100UL ;
V_2 -> V_31 . V_49 . V_50
= 100000 ;
F_1 (
V_2 ,
V_51 != V_2 -> V_31 . V_36 ,
V_52 ) ;
if ( ! V_17 -> V_53 )
return 0 ;
V_32 = ( const T_6 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_53 ) ) ;
if ( V_32 -> V_54 == 10 ) {
V_33 = ( T_7 * ) V_32 ;
F_9 ((fan_table_v1->ucRevId >= 8),
L_5 , return -EINVAL) ;
F_2 ( V_2 -> V_6 . V_7 ,
V_55 ) ;
V_2 -> V_31 . V_49 . V_56 =
F_8 ( V_33 -> V_56 ) ;
V_2 -> V_31 . V_49 . V_57 =
F_8 ( V_33 -> V_58 ) ;
V_2 -> V_31 . V_49 . V_59 =
F_8 ( V_33 -> V_60 ) ;
V_2 -> V_31 . V_49 . V_61 =
F_8 ( V_33 -> V_62 ) ;
V_2 -> V_31 . V_49 . V_63 =
F_8 ( V_33 -> V_64 ) ;
V_2 -> V_31 . V_49 . V_65 =
F_8 ( V_33 -> V_66 ) ;
V_2 -> V_31 . V_49 . V_67 =
F_8 ( V_33 -> V_68 ) ;
V_2 -> V_31 . V_49 . V_69 =
F_8 ( V_33 -> V_69 ) ;
V_2 -> V_31 . V_49 . V_70 =
F_8 ( V_33 -> V_70 ) ;
V_2 -> V_31 . V_49 . V_71 =
F_8 ( V_33 -> V_71 ) ;
V_2 -> V_31 . V_49 . V_72 =
F_8 ( V_33 -> V_72 ) ;
V_2 -> V_31 . V_49 . V_73 =
F_8 ( V_33 -> V_73 ) ;
V_2 -> V_31 . V_49 . V_74 =
F_8 ( V_33 -> V_74 ) ;
V_2 -> V_31 . V_49 . V_75 =
F_8 ( V_33 -> V_75 ) ;
V_2 -> V_31 . V_49 . V_76 =
V_33 -> V_76 ;
V_2 -> V_31 . V_49 . V_77 =
F_8 ( V_33 -> V_78 ) ;
V_2 -> V_31 . V_49 . V_79 =
F_8 ( V_33 -> V_80 ) ;
} else if ( V_32 -> V_54 > 10 ) {
V_34 = ( T_8 * ) V_32 ;
V_2 -> V_31 . V_39 . V_43 =
V_34 -> V_41 & V_44 ;
V_2 -> V_31 . V_39 . V_45 = V_34 -> V_46 * 100UL ;
V_2 -> V_31 . V_39 . V_47 = V_34 -> V_48 * 100UL ;
F_2 ( V_2 -> V_6 . V_7 ,
V_55 ) ;
V_2 -> V_31 . V_49 . V_56 =
F_8 ( V_34 -> V_56 ) ;
V_2 -> V_31 . V_49 . V_57 =
V_34 -> V_48 * 100UL ;
V_2 -> V_31 . V_49 . V_59 =
F_8 ( V_34 -> V_60 ) ;
V_2 -> V_31 . V_49 . V_61 =
F_8 ( V_34 -> V_81 ) ;
V_2 -> V_31 . V_49 . V_63 =
F_8 ( V_34 -> V_64 ) ;
V_2 -> V_31 . V_49 . V_65 =
F_8 ( V_34 -> V_66 ) ;
V_2 -> V_31 . V_49 . V_67 =
F_8 ( V_34 -> V_68 ) ;
V_2 -> V_31 . V_49 . V_69 =
F_8 ( V_34 -> V_69 ) ;
V_2 -> V_31 . V_49 . V_70 =
F_8 ( V_34 -> V_70 ) ;
V_2 -> V_31 . V_49 . V_71 =
F_8 ( V_34 -> V_71 ) ;
V_2 -> V_31 . V_49 . V_72 =
F_8 ( V_34 -> V_72 ) ;
V_2 -> V_31 . V_49 . V_73 =
F_8 ( V_34 -> V_73 ) ;
V_2 -> V_31 . V_49 . V_74 =
F_8 ( V_34 -> V_74 ) ;
V_2 -> V_31 . V_49 . V_75 =
F_8 ( V_34 -> V_75 ) ;
V_2 -> V_31 . V_49 . V_76 =
V_34 -> V_76 ;
V_2 -> V_31 . V_49 . V_77 =
F_8 ( V_34 -> V_78 ) ;
V_2 -> V_31 . V_49 . V_79 =
F_8 ( V_34 -> V_80 ) ;
}
return 0 ;
}
static int F_12 (
struct V_1 * V_2 ,
const V_15 * V_17 )
{
V_2 -> V_6 . V_82 . V_83 =
F_13 ( V_17 -> V_84 ) ;
V_2 -> V_6 . V_82 . V_85 =
F_13 ( V_17 -> V_86 ) ;
V_2 -> V_6 . V_87 = 0 ;
V_2 -> V_6 . V_88 = 0 ;
V_2 -> V_6 . V_89 = 0 ;
if ( V_2 -> V_6 . V_82 . V_83 > 0 &&
V_2 -> V_6 . V_82 . V_85 > 0 ) {
F_2 ( V_2 -> V_6 . V_7 ,
V_90 ) ;
}
return 0 ;
}
static int F_14 (
struct V_1 * V_2 ,
T_9 * * V_91 ,
const T_10 * V_92 )
{
T_4 V_93 , V_94 ;
const T_11 * V_95 ;
T_9 * V_96 ;
F_9 ((mm_dependency_table->ucNumEntries != 0),
L_3 , return -1 ) ;
V_93 = sizeof( T_4 ) +
sizeof( V_97 ) *
V_92 -> V_98 ;
V_96 = ( T_9 * )
F_15 ( V_93 , V_99 ) ;
if ( ! V_96 )
return - V_100 ;
V_96 -> V_101 = V_92 -> V_98 ;
for ( V_94 = 0 ; V_94 < V_92 -> V_98 ; V_94 ++ ) {
V_95 = & V_92 -> V_102 [ V_94 ] ;
V_96 -> V_102 [ V_94 ] . V_103 = V_95 -> V_104 ;
V_96 -> V_102 [ V_94 ] . V_105 =
F_13 ( V_95 -> V_106 ) ;
V_96 -> V_102 [ V_94 ] . V_107 = F_13 ( V_95 -> V_108 ) ;
V_96 -> V_102 [ V_94 ] . V_109 = F_13 ( V_95 -> V_110 ) ;
V_96 -> V_102 [ V_94 ] . V_111 = F_13 ( V_95 -> V_112 ) ;
}
* V_91 = V_96 ;
return 0 ;
}
static void F_16 ( T_12 line , T_12 * V_113 , T_12 * V_114 )
{
switch( line ) {
case V_115 :
* V_113 = V_116 ;
* V_114 = V_117 ;
break;
case V_118 :
* V_113 = V_119 ;
* V_114 = V_120 ;
break;
case V_121 :
* V_113 = V_122 ;
* V_114 = V_123 ;
break;
case V_124 :
* V_113 = V_125 ;
* V_114 = V_126 ;
break;
case V_127 :
* V_113 = V_128 ;
* V_114 = V_129 ;
break;
case V_130 :
* V_113 = V_131 ;
* V_114 = V_132 ;
break;
case V_133 :
* V_113 = V_134 ;
* V_114 = V_135 ;
break;
case V_136 :
* V_113 = V_137 ;
* V_114 = V_138 ;
break;
default:
* V_113 = 0 ;
* V_114 = 0 ;
break;
}
}
static int F_17 (
struct V_1 * V_2 ,
struct V_139 * * V_140 ,
const T_6 * V_141 )
{
T_4 V_93 ;
struct V_139 * V_142 ;
T_12 V_113 ;
T_12 V_114 ;
const T_13 * V_143 ;
const T_14 * V_144 ;
V_93 = sizeof( T_4 ) + sizeof( struct V_139 ) ;
V_142 = F_15 ( V_93 , V_99 ) ;
if ( ! V_142 )
return - V_100 ;
if ( V_141 -> V_54 == 5 ) {
V_143 = ( T_13 * ) V_141 ;
V_142 -> V_145 = F_8 ( V_143 -> V_146 ) ;
V_142 -> V_147 = F_8 ( V_143 -> V_148 ) ;
V_142 -> V_149 = F_8 ( V_143 -> V_150 ) ;
V_142 -> V_151 =
F_8 ( V_143 -> V_151 ) ;
V_142 -> V_152 =
F_8 ( V_143 -> V_152 ) ;
V_142 -> V_153 =
F_8 ( V_143 -> V_154 ) ;
V_142 -> V_155 =
F_8 ( V_143 -> V_155 ) ;
V_142 -> V_156 =
F_8 ( V_143 -> V_156 ) ;
V_142 -> V_157 =
F_8 ( V_143 -> V_157 ) ;
V_142 -> V_158 =
F_8 ( V_143 -> V_159 ) ;
V_142 -> V_160 =
F_8 ( V_143 -> V_161 ) ;
V_142 -> V_162 =
F_8 ( V_143 -> V_162 ) ;
V_142 -> V_163 = V_143 -> V_163 ;
V_142 -> V_164 = V_143 -> V_164 ;
V_142 -> V_165 = V_143 -> V_166 ;
V_142 -> V_167 = V_143 -> V_167 ;
V_142 -> V_168 = V_143 -> V_168 ;
V_142 -> V_169 = V_143 -> V_170 ;
V_142 -> V_171 = V_143 -> V_171 ;
V_142 -> V_172 = V_143 -> V_172 ;
V_142 -> V_173 = V_143 -> V_174 ;
V_142 -> V_175 = V_143 -> V_175 ;
V_2 -> V_6 . V_176 = F_8 ( V_143 -> V_177 ) ;
} else {
V_144 = ( T_14 * ) V_141 ;
V_142 -> V_145 = F_8 ( V_144 -> V_146 ) ;
V_142 -> V_147 = F_8 ( V_144 -> V_148 ) ;
V_142 -> V_149 = F_8 ( V_144 -> V_150 ) ;
V_142 -> V_151 =
F_8 ( V_144 -> V_151 ) ;
V_142 -> V_152 =
F_8 ( V_144 -> V_152 ) ;
V_142 -> V_153 =
F_8 ( V_144 -> V_154 ) ;
V_142 -> V_155 =
F_8 ( V_144 -> V_155 ) ;
V_142 -> V_156 =
F_8 ( V_144 -> V_156 ) ;
V_142 -> V_157 =
F_8 ( V_144 -> V_157 ) ;
V_142 -> V_158 =
F_8 ( V_144 -> V_159 ) ;
V_142 -> V_160 =
F_8 ( V_144 -> V_161 ) ;
V_142 -> V_162 =
F_8 ( V_144 -> V_162 ) ;
V_142 -> V_163 = V_144 -> V_163 ;
V_142 -> V_164 = V_144 -> V_164 ;
F_16 ( V_144 -> V_165 , & V_113 , & V_114 ) ;
V_142 -> V_165 = V_113 ;
V_142 -> V_167 = V_114 ;
V_142 -> V_168 = V_144 -> V_168 ;
F_16 ( V_144 -> V_169 , & V_113 , & V_114 ) ;
V_142 -> V_169 = V_113 ;
V_142 -> V_171 = V_114 ;
V_142 -> V_172 = V_144 -> V_172 ;
F_16 ( V_144 -> V_173 , & V_113 , & V_114 ) ;
V_142 -> V_173 = V_113 ;
V_142 -> V_175 = V_114 ;
V_2 -> V_6 . V_176 =
F_8 ( V_144 -> V_177 ) ;
}
* V_140 = V_142 ;
return 0 ;
}
static int F_18 (
struct V_1 * V_2 ,
T_15 * * V_178 ,
const T_16 * V_179 )
{
T_4 V_93 , V_94 ;
T_15 * V_180 ;
F_9 (clk_dep_table->ucNumEntries,
L_3 , return -1 ) ;
V_93 = sizeof( T_4 ) +
sizeof( V_181 ) *
V_179 -> V_98 ;
V_180 = ( T_15 * )
F_15 ( V_93 , V_99 ) ;
if ( ! V_180 )
return - V_100 ;
V_180 -> V_101 = ( T_4 ) V_179 -> V_98 ;
for ( V_94 = 0 ; V_94 < V_179 -> V_98 ; V_94 ++ ) {
V_180 -> V_102 [ V_94 ] . V_182 =
V_179 -> V_102 [ V_94 ] . V_183 ;
V_180 -> V_102 [ V_94 ] . V_184 =
F_13 ( V_179 -> V_102 [ V_94 ] . V_185 ) ;
}
* V_178 = V_180 ;
return 0 ;
}
static int F_19 (
struct V_1 * V_2 ,
T_15 * * V_186 ,
const T_17 * V_187 )
{
T_4 V_93 , V_94 ;
T_15 * V_188 ;
F_9 (mclk_dep_table->ucNumEntries,
L_3 , return -1 ) ;
V_93 = sizeof( T_4 ) +
sizeof( V_181 ) *
V_187 -> V_98 ;
V_188 = ( T_15 * )
F_15 ( V_93 , V_99 ) ;
if ( ! V_188 )
return - V_100 ;
V_188 -> V_101 = ( T_4 ) V_187 -> V_98 ;
for ( V_94 = 0 ; V_94 < V_187 -> V_98 ; V_94 ++ ) {
V_188 -> V_102 [ V_94 ] . V_182 =
V_187 -> V_102 [ V_94 ] . V_183 ;
V_188 -> V_102 [ V_94 ] . V_189 =
V_187 -> V_102 [ V_94 ] . V_190 ;
V_188 -> V_102 [ V_94 ] . V_191 =
V_187 -> V_102 [ V_94 ] . V_192 ;
V_188 -> V_102 [ V_94 ] . V_184 =
F_13 ( V_187 -> V_102 [ V_94 ] . V_193 ) ;
}
* V_186 = V_188 ;
return 0 ;
}
static int F_20 (
struct V_1 * V_2 ,
struct T_15
* * V_178 ,
const T_18 * V_179 )
{
T_4 V_93 , V_94 ;
struct T_15
* V_180 ;
F_9 ((clk_dep_table->ucNumEntries != 0),
L_3 , return -1 ) ;
V_93 = sizeof( T_4 ) +
sizeof( V_181 ) *
V_179 -> V_98 ;
V_180 = (struct T_15 * )
F_15 ( V_93 , V_99 ) ;
if ( ! V_180 )
return - V_100 ;
V_180 -> V_101 = V_179 -> V_98 ;
for ( V_94 = 0 ; V_94 < V_180 -> V_101 ; V_94 ++ ) {
V_180 -> V_102 [ V_94 ] . V_182 =
V_179 -> V_102 [ V_94 ] . V_183 ;
V_180 -> V_102 [ V_94 ] . V_184 =
F_13 ( V_179 -> V_102 [ V_94 ] . V_185 ) ;
V_180 -> V_102 [ V_94 ] . V_194 =
( ( ( V_179 -> V_102 [ V_94 ] . V_195 & 0x80 )
>> 15 ) == 0 ) ? 1 : 0 ;
V_180 -> V_102 [ V_94 ] . V_196 =
( V_179 -> V_102 [ V_94 ] . V_195 & 0x7F ) ;
V_180 -> V_102 [ V_94 ] . V_197 =
V_179 -> V_102 [ V_94 ] . V_198 ;
}
* V_178 = V_180 ;
return 0 ;
}
static int F_21 (
struct V_1 * V_2 ,
struct T_15
* * V_178 ,
const T_19 * V_179 )
{
T_4 V_93 , V_94 ;
struct T_15
* V_180 ;
F_9 ((clk_dep_table->ucNumEntries != 0),
L_3 , return -1 ) ;
V_93 = sizeof( T_4 ) +
sizeof( V_181 ) *
V_179 -> V_98 ;
V_180 = (struct T_15 * )
F_15 ( V_93 , V_99 ) ;
if ( ! V_180 )
return - V_100 ;
V_180 -> V_101 = V_179 -> V_98 ;
for ( V_94 = 0 ; V_94 < V_180 -> V_101 ; V_94 ++ ) {
V_180 -> V_102 [ V_94 ] . V_182 =
V_179 -> V_102 [ V_94 ] . V_183 ;
V_180 -> V_102 [ V_94 ] . V_184 =
F_13 ( V_179 -> V_102 [ V_94 ] . V_185 ) ;
}
* V_178 = V_180 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_199 * * V_200 ,
const T_6 * V_141 )
{
T_4 V_93 , V_94 , V_201 ;
struct V_199 * V_202 ;
struct V_203 * V_204 =
(struct V_203 * ) ( V_2 -> V_205 ) ;
const T_20 * V_206 =
( T_20 * ) V_141 ;
F_9 (atom_pcie_table->ucNumEntries,
L_3 ,
return 0 ) ;
V_93 = sizeof( T_4 ) +
sizeof( struct V_207 ) *
V_206 -> V_98 ;
V_202 = (struct V_199 * )
F_15 ( V_93 , V_99 ) ;
if ( ! V_202 )
return - V_100 ;
V_201 = V_204 -> V_208 -> V_101 ;
if ( V_206 -> V_98 <= V_201 )
V_201 = V_206 -> V_98 ;
else
F_23 ( L_6
L_7
L_8 ) ;
V_202 -> V_101 = V_201 ;
for ( V_94 = 0 ; V_94 < V_201 ; V_94 ++ ) {
V_202 -> V_102 [ V_94 ] . V_209 =
V_206 -> V_102 [ V_94 ] . V_210 ;
V_202 -> V_102 [ V_94 ] . V_211 =
V_206 -> V_102 [ V_94 ] . V_212 ;
V_202 -> V_102 [ V_94 ] . V_213 =
V_206 -> V_102 [ V_94 ] . V_214 ;
}
* V_200 = V_202 ;
return 0 ;
}
static int F_24 (
struct V_1 * V_2 ,
struct V_215 * V_216 ,
const T_21 * V_217 )
{
F_9 (limit_table->ucNumEntries,
L_3 , return -1 ) ;
V_216 -> V_218 = F_13 ( V_217 -> V_102 [ 0 ] . V_219 ) ;
V_216 -> V_220 = F_13 ( V_217 -> V_102 [ 0 ] . V_221 ) ;
V_216 -> V_222 = F_13 ( V_217 -> V_102 [ 0 ] . V_223 ) ;
V_216 -> V_224 = F_8 ( V_217 -> V_102 [ 0 ] . V_225 ) ;
V_216 -> V_226 = F_8 ( V_217 -> V_102 [ 0 ] . V_227 ) ;
V_216 -> V_228 = F_8 ( V_217 -> V_102 [ 0 ] . V_229 ) ;
return 0 ;
}
static int F_25 (
struct V_1 * V_2 ,
struct V_230 * * V_180 ,
const T_15 * V_231 )
{
T_4 V_93 , V_94 ;
struct V_230 * V_141 ;
F_9 (clk_volt_pp_table->count,
L_3 , return -1 ) ;
V_93 = sizeof( T_4 ) +
sizeof( T_4 ) * V_231 -> V_101 ;
V_141 = F_15 ( V_93 , V_99 ) ;
if ( ! V_141 )
return - V_100 ;
V_141 -> V_101 = ( T_4 ) V_231 -> V_101 ;
for ( V_94 = 0 ; V_94 < V_141 -> V_101 ; V_94 ++ )
V_141 -> V_232 [ V_94 ] = ( T_4 ) V_231 -> V_102 [ V_94 ] . V_184 ;
* V_180 = V_141 ;
return 0 ;
}
static int F_26 (
struct V_1 * V_2 ,
const V_15 * V_17 )
{
int V_233 = 0 ;
struct V_203 * V_234 =
(struct V_203 * ) ( V_2 -> V_205 ) ;
const T_10 * V_92 =
( const T_10 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_235 ) ) ;
const T_6 * V_143 =
( const T_6 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_236 ) ) ;
const T_16 * V_237 =
( const T_16 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_238 ) ) ;
const T_18 * V_239 =
( const T_18 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_240 ) ) ;
const T_19 * V_241 =
( const T_19 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_242 ) ) ;
const T_17 * V_187 =
( const T_17 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_243 ) ) ;
const T_21 * V_244 =
( const T_21 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_245 ) ) ;
const T_6 * V_202 =
( const T_6 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_246 ) ) ;
const T_22 * V_247 =
( const T_22 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_248 ) ) ;
const T_23 * V_249 =
( const T_23 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_250 ) ) ;
const T_24 * V_251 =
( const T_24 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_252 ) ) ;
V_234 -> V_253 = NULL ;
V_234 -> V_208 = NULL ;
V_234 -> V_254 = NULL ;
V_234 -> V_255 = NULL ;
V_234 -> V_256 = NULL ;
V_234 -> V_142 = NULL ;
V_234 -> V_257 = NULL ;
V_234 -> V_258 = NULL ;
V_234 -> V_259 = NULL ;
if ( V_17 -> V_235 )
V_233 = F_14 ( V_2 ,
& V_234 -> V_256 ,
V_92 ) ;
if ( ! V_233 && V_17 -> V_236 )
V_233 = F_17 ( V_2 ,
& V_234 -> V_142 ,
V_143 ) ;
if ( ! V_233 && V_17 -> V_238 )
V_233 = F_18 ( V_2 ,
& V_234 -> V_253 ,
V_237 ) ;
if ( ! V_233 && V_17 -> V_240 )
V_233 = F_20 ( V_2 ,
& V_234 -> V_208 ,
V_239 ) ;
if ( ! V_233 && V_17 -> V_248 )
V_233 = F_21 ( V_2 ,
& V_234 -> V_257 ,
( const T_19 * )
V_247 ) ;
if ( ! V_233 && V_17 -> V_250 )
V_233 = F_21 ( V_2 ,
& V_234 -> V_258 ,
( const T_19 * )
V_249 ) ;
if ( ! V_233 && V_17 -> V_252 )
V_233 = F_21 ( V_2 ,
& V_234 -> V_259 ,
( const T_19 * )
V_251 ) ;
if ( ! V_233 && V_17 -> V_242 )
V_233 = F_21 ( V_2 ,
& V_234 -> V_255 ,
V_241 ) ;
if ( ! V_233 && V_17 -> V_243 )
V_233 = F_19 ( V_2 ,
& V_234 -> V_254 ,
V_187 ) ;
if ( ! V_233 && V_17 -> V_246 )
V_233 = F_22 ( V_2 ,
& V_234 -> V_202 ,
V_202 ) ;
if ( ! V_233 && V_17 -> V_245 )
V_233 = F_24 ( V_2 ,
& V_234 -> V_260 ,
V_244 ) ;
V_2 -> V_261 . V_260 . V_218 =
V_234 -> V_260 . V_218 ;
V_2 -> V_261 . V_260 . V_220 =
V_234 -> V_260 . V_220 ;
V_2 -> V_261 . V_260 . V_224 =
V_234 -> V_260 . V_224 ;
V_2 -> V_261 . V_260 . V_226 =
V_234 -> V_260 . V_226 ;
if ( ! V_233 &&
V_234 -> V_253 &&
V_234 -> V_253 -> V_101 )
V_233 = F_25 ( V_2 ,
& V_234 -> V_262 ,
V_234 -> V_253 ) ;
if ( ! V_233 &&
V_234 -> V_208 &&
V_234 -> V_208 -> V_101 )
V_233 = F_25 ( V_2 ,
& V_234 -> V_263 ,
V_234 -> V_208 ) ;
if ( ! V_233 &&
V_234 -> V_255 &&
V_234 -> V_255 -> V_101 )
V_233 = F_25 ( V_2 ,
& V_234 -> V_264 ,
V_234 -> V_255 ) ;
if ( ! V_233 &&
V_234 -> V_254 &&
V_234 -> V_254 -> V_101 )
V_233 = F_25 ( V_2 ,
& V_234 -> V_265 ,
V_234 -> V_254 ) ;
return V_233 ;
}
static int F_27 (
struct V_1 * V_2 ,
T_25 * * V_266 ,
const T_26 * V_267 ,
T_4 V_268 )
{
T_4 V_93 , V_94 ;
T_25 * V_141 ;
F_9 ((vddc_lookup_pp_tables->ucNumEntries != 0),
L_9 , return 1 ) ;
V_93 = sizeof( T_4 ) +
sizeof( V_269 ) * V_268 ;
V_141 = ( T_25 * )
F_15 ( V_93 , V_99 ) ;
if ( NULL == V_141 )
return - V_100 ;
V_141 -> V_101 = V_267 -> V_98 ;
for ( V_94 = 0 ; V_94 < V_267 -> V_98 ; V_94 ++ )
V_141 -> V_102 [ V_94 ] . V_270 =
F_8 ( V_267 -> V_102 [ V_94 ] . V_271 ) ;
* V_266 = V_141 ;
return 0 ;
}
static int F_28 (
struct V_1 * V_2 ,
const V_15 * V_17 )
{
int V_233 = 0 ;
struct V_203 * V_234 =
(struct V_203 * ) ( V_2 -> V_205 ) ;
T_4 V_272 = 0 ;
V_234 -> V_273 =
F_8 ( V_17 -> V_274 ) ;
V_234 -> V_275 =
F_8 ( V_17 -> V_276 ) ;
V_234 -> V_277 =
F_8 ( V_17 -> V_278 ) ;
V_234 -> V_279 =
F_8 ( V_17 -> V_280 ) ;
V_234 -> V_281 =
F_8 ( V_17 -> V_282 ) ;
V_234 -> V_283 =
F_8 ( V_17 -> V_284 ) ;
V_234 -> V_285 =
F_8 ( V_17 -> V_286 ) ;
V_234 -> V_287 =
F_8 ( V_17 -> V_288 ) ;
V_234 -> V_289 =
F_8 ( V_17 -> V_290 ) ;
V_234 -> V_291 =
F_8 ( V_17 -> V_292 ) ;
V_234 -> V_293 =
F_8 ( V_17 -> V_294 ) ;
V_234 -> V_295 =
F_8 ( V_17 -> V_296 ) ;
V_234 -> V_297 = NULL ;
V_234 -> V_298 = NULL ;
V_234 -> V_299 = NULL ;
V_234 -> V_300 = NULL ;
V_2 -> V_6 . V_301 =
F_8 ( V_17 -> V_302 ) ;
V_2 -> V_6 . V_303 = 0 ;
V_2 -> V_6 . V_304 = 0 ;
V_2 -> V_6 . V_305 = 0 ;
V_2 -> V_6 . V_306 = 0 ;
V_2 -> V_6 . V_307 = 1500000 ;
V_2 -> V_6 . V_308 = 6250 ;
V_272 = 0 ;
if ( ! V_272 ) {
if ( V_2 -> V_6 . V_301 )
F_2 ( V_2 -> V_6 . V_7 ,
V_309 ) ;
}
if ( V_17 -> V_310 ) {
const T_26 * V_311 =
( T_26 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_310 ) ) ;
V_233 = F_27 ( V_2 ,
& V_234 -> V_298 , V_311 , 8 ) ;
}
if ( V_17 -> V_312 ) {
const T_26 * V_313 =
( T_26 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_312 ) ) ;
V_233 = F_27 ( V_2 ,
& V_234 -> V_299 , V_313 , 4 ) ;
}
if ( V_17 -> V_314 ) {
const T_26 * V_315 =
( T_26 * )
( ( ( unsigned long ) V_17 ) +
F_8 ( V_17 -> V_314 ) ) ;
V_233 = F_27 ( V_2 ,
& V_234 -> V_300 , V_315 , 4 ) ;
}
return V_233 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_233 = 0 ;
const V_15 * V_17 ;
V_2 -> V_205 = F_15 ( sizeof( struct V_203 ) , V_99 ) ;
F_9 ((NULL != hwmgr->pptable),
L_10 , return -ENOMEM) ;
V_17 = F_4 ( V_2 ) ;
F_9 ((NULL != powerplay_table),
L_11 , return -1 ) ;
V_233 = F_7 ( V_2 , V_17 ) ;
F_9 ((result == 0),
L_12 , return result) ;
V_233 = F_10 ( V_2 ,
F_13 ( V_17 -> V_316 ) ) ;
F_9 ((result == 0),
L_13 , return result) ;
V_233 = F_11 ( V_2 , V_17 ) ;
F_9 ((result == 0),
L_14 , return result) ;
V_233 = F_12 ( V_2 , V_17 ) ;
F_9 ((result == 0),
L_15 , return result) ;
V_233 = F_26 ( V_2 , V_17 ) ;
F_9 ((result == 0),
L_16 , return result) ;
V_233 = F_28 ( V_2 , V_17 ) ;
F_9 ((result == 0),
L_17 , return result) ;
return V_233 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_233 = 0 ;
struct V_203 * V_234 =
(struct V_203 * ) ( V_2 -> V_205 ) ;
F_31 ( V_234 -> V_208 ) ;
V_234 -> V_208 = NULL ;
F_31 ( V_234 -> V_254 ) ;
V_234 -> V_254 = NULL ;
F_31 ( V_234 -> V_265 ) ;
V_234 -> V_265 = NULL ;
F_31 ( V_234 -> V_263 ) ;
V_234 -> V_263 = NULL ;
F_31 ( V_234 -> V_298 ) ;
V_234 -> V_298 = NULL ;
F_31 ( V_234 -> V_299 ) ;
V_234 -> V_299 = NULL ;
F_31 ( V_234 -> V_300 ) ;
V_234 -> V_300 = NULL ;
F_31 ( V_234 -> V_297 ) ;
V_234 -> V_297 = NULL ;
F_31 ( V_234 -> V_256 ) ;
V_234 -> V_256 = NULL ;
F_31 ( V_234 -> V_317 ) ;
V_234 -> V_317 = NULL ;
F_31 ( V_2 -> V_261 . V_317 ) ;
V_2 -> V_261 . V_317 = NULL ;
F_31 ( V_234 -> V_142 ) ;
V_234 -> V_142 = NULL ;
F_31 ( V_2 -> V_205 ) ;
V_2 -> V_205 = NULL ;
return V_233 ;
}
int F_32 ( struct V_1 * V_2 )
{
const T_3 * V_18 ;
const V_15 * V_318 = F_4 ( V_2 ) ;
F_9 ((NULL != pp_table),
L_11 , return -1 ) ;
F_9 ((pp_table->sHeader.format_revision >=
ATOM_Vega10_TABLE_REVISION_VEGA10),
L_18 , return -1 ) ;
V_18 = ( T_3 * ) ( ( ( unsigned long ) V_318 ) +
F_8 ( V_318 -> V_19 ) ) ;
return ( T_4 ) ( V_18 -> V_98 ) ;
}
static T_4 F_33 ( struct V_1 * V_2 ,
T_27 V_319 , T_27 V_320 )
{
T_4 V_233 = 0 ;
if ( V_319 & V_321 )
V_233 |= V_322 ;
if ( V_319 & V_323 )
V_233 |= V_324 ;
if ( V_319 & V_325 )
V_233 |= V_326 ;
if ( V_319 & V_327 )
V_233 |= V_328 ;
if ( V_319 & V_329 )
V_233 |= V_330 ;
if ( V_319 & V_331 )
V_233 |= V_332 ;
if ( V_320 & V_333 )
V_233 |= V_334 ;
return V_233 ;
}
int F_34 ( struct V_1 * V_2 ,
T_4 V_335 , struct V_336 * V_337 ,
int (* F_35)( struct V_1 * , void * ,
struct V_336 * , void * , T_4 ) )
{
int V_233 = 0 ;
const T_3 * V_18 ;
const T_28 * V_338 ;
const V_15 * V_318 =
F_4 ( V_2 ) ;
F_9 (pp_table, L_11 ,
return -1;) ;
V_337 -> V_319 . V_339 = V_335 ;
if ( V_318 -> V_340 . V_341 >=
V_342 ) {
V_18 = ( T_3 * )
( ( ( unsigned long ) V_318 ) +
F_8 ( V_318 -> V_19 ) ) ;
F_9 (pp_table->usStateArrayOffset > 0 ,
L_19 ,
return -1 ) ;
F_9 (state_arrays->ucNumEntries > 0 ,
L_20 ,
return -1 ) ;
F_9 ((entry_index <= state_arrays->ucNumEntries),
L_21 ,
return -1 ) ;
V_338 = & ( V_18 -> V_343 [ V_335 ] ) ;
V_233 = F_35 ( V_2 , ( void * ) V_338 , V_337 ,
( void * ) V_318 ,
F_33 ( V_2 ,
F_8 ( V_338 -> V_344 ) ,
F_8 ( V_338 -> V_345 ) ) ) ;
}
if ( ! V_233 && ( V_337 -> V_319 . V_346 &
V_322 ) )
V_233 = V_2 -> V_347 -> V_348 ( V_2 , & ( V_337 -> V_349 ) ) ;
return V_233 ;
}
