static int
F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
T_2 V_5 ;
int V_6 = 0 ;
T_2 V_7 = 0 ;
T_2 V_8 ;
F_2 ( L_1 , V_4 ) ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 += 100 , V_3 += 100 / sizeof( T_2 ) ) {
F_3 ( V_2 , V_9 , V_8 + V_10 ) ;
V_5 = F_4 ( V_2 , V_11 ) ;
if ( V_5 != F_5 ( * V_3 ) ) {
V_6 = - V_12 ;
V_7 ++ ;
if ( V_7 >= 3 )
break;
}
}
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
T_2 V_5 ;
T_2 V_13 = V_4 ;
int V_6 = 0 ;
T_2 V_7 ;
F_2 ( L_1 , V_4 ) ;
F_3 ( V_2 , V_9 , V_10 ) ;
V_7 = 0 ;
for (; V_4 > 0 ; V_4 -= sizeof( T_2 ) , V_3 ++ ) {
V_5 = F_4 ( V_2 , V_11 ) ;
if ( V_5 != F_5 ( * V_3 ) ) {
F_7 ( L_2
L_3 ,
V_13 - V_4 , V_5 , F_5 ( * V_3 ) ) ;
V_6 = - V_12 ;
V_7 ++ ;
if ( V_7 >= 20 )
break;
}
}
if ( ! V_7 )
F_2 ( L_4 ) ;
return V_6 ;
}
int
F_8 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
T_2 V_4 ;
int V_6 ;
V_3 = ( T_1 * ) V_2 -> V_14 . V_15 ;
V_4 = V_2 -> V_14 . V_4 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_6 ) {
F_2 ( L_5 ) ;
return 0 ;
}
V_3 = ( T_1 * ) V_2 -> V_16 . V_15 ;
V_4 = V_2 -> V_16 . V_4 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_6 ) {
F_2 ( L_6 ) ;
return 0 ;
}
V_3 = ( T_1 * ) V_2 -> V_17 . V_15 ;
V_4 = V_2 -> V_17 . V_4 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_6 ) {
F_2 ( L_7 ) ;
return 0 ;
}
F_7 ( L_8 ) ;
V_3 = ( T_1 * ) V_2 -> V_14 . V_15 ;
V_4 = V_2 -> V_14 . V_4 ;
V_6 = F_6 ( V_2 , V_3 , V_4 ) ;
return V_6 ;
}
int
F_9 ( struct V_1 * V_2 )
{
T_3 V_18 ;
int V_6 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
F_10 ( V_2 , V_20 ,
V_21 ) ;
V_6 =
F_11 ( V_2 , V_20 ,
V_21 ,
V_21 ,
V_22 ) ;
if ( V_6 >= 0 )
return V_6 ;
}
return V_6 ;
}
void
F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_20 ,
V_21 ) ;
}
int
F_14 ( struct V_1 * V_2 )
{
T_3 V_23 ;
T_3 V_24 ;
V_23 = F_15 ( V_2 , V_25 ) ;
V_24 = F_15 ( V_2 , V_26 ) ;
if ( V_23 < V_2 -> V_27 -> V_23 ||
V_24 < V_2 -> V_27 -> V_28 )
goto V_29;
F_16 ( L_9 , V_23 , V_24 ) ;
return 0 ;
V_29:
F_7 ( L_10
L_11 , V_23 , V_2 -> V_27 -> V_23 ,
V_24 , V_2 -> V_27 -> V_28 ) ;
return - V_30 ;
}
void
F_17 ( const struct V_1 * V_2 , T_4 * V_31 )
{
const T_4 * V_32 = F_18 ( V_2 ,
V_33 ) ;
memcpy ( V_31 , V_32 , V_34 ) ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_4 = sizeof( struct V_35 ) ,
. V_41 = V_36 ,
. V_42 = V_43 ,
. V_44 = NULL ,
} ;
T_2 V_45 ;
V_45 = F_4 ( V_2 , V_46 ) ;
if ( V_45 != ( V_45 & V_47 ) )
F_20 ( V_2 , V_46 , V_45 & V_47 ) ;
return F_21 ( V_2 , & V_38 ) ;
}
void
F_22 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_46 , V_48 ) ;
}
static int
F_23 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_14 . V_15 ;
T_2 V_4 = V_2 -> V_14 . V_4 ;
T_2 V_45 ;
T_2 V_5 ;
F_2 ( L_12 ) ;
V_5 = F_24 ( V_2 , V_49 ) ;
for ( V_45 = V_50 ; V_45 < V_50 + V_4 ;
V_45 += sizeof( T_2 ) , V_3 ++ ) {
V_5 = F_24 ( V_2 , V_45 ) ;
if ( V_5 != F_5 ( * V_3 ) ) {
F_7 ( L_13
L_14 ,
V_50 , V_45 - V_50 ,
V_4 , V_5 , F_5 ( * V_3 ) ) ;
return - V_12 ;
}
}
F_2 ( L_15 ) ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_14 . V_15 ;
T_2 V_4 = V_2 -> V_14 . V_4 ;
T_5 V_51 ;
T_5 V_52 ;
T_2 V_53 ;
T_2 V_54 ;
int V_8 ;
T_2 V_55 ;
T_2 V_56 ;
int V_6 ;
F_2 ( L_16 ) ;
V_2 -> V_57 = V_58 ;
if ( V_4 > V_59 )
return - V_30 ;
V_51 = V_2 -> V_16 . V_60 >> 4 ;
V_52 = V_2 -> V_61 . V_60 >> 4 ;
V_53 = V_2 -> V_16 . V_4 ;
V_54 = V_2 -> V_61 . V_4 ;
F_26 ( V_2 , V_62 , V_51 ) ;
F_26 ( V_2 , V_63 , V_52 ) ;
F_26 ( V_2 , V_64 , V_53 ) ;
F_26 ( V_2 , V_65 , V_54 ) ;
for ( V_56 = V_50 ;
V_56 < V_50 + V_4 ;
V_56 += sizeof( T_2 ) , V_3 ++ )
F_27 ( V_2 , V_56 , F_5 ( * V_3 ) ) ;
V_6 = F_23 ( V_2 ) ;
if ( V_6 )
return V_6 ;
F_26 ( V_2 , V_66 , 0x0 ) ;
F_26 ( V_2 , V_67 , V_68 ) ;
F_26 ( V_2 , V_49 , V_4 / sizeof( T_2 ) ) ;
F_26 ( V_2 , V_69 , V_70 ) ;
for ( V_8 = 0 ; V_8 < 100 ; V_8 ++ ) {
V_55 = F_24 ( V_2 , V_69 ) ;
if ( ! ( V_55 & V_70 ) )
break;
F_28 ( 10 ) ;
}
if ( V_8 < 100 )
F_2 ( L_17 , V_8 ) ;
else {
F_7 ( L_18 ) ;
return - V_12 ;
}
F_26 ( V_2 , V_69 , V_71 ) ;
return 0 ;
}
static int
F_29 ( struct V_1 * V_2 )
{
T_5 V_51 ;
T_5 V_52 ;
int V_6 = 0 ;
V_51 = V_2 -> V_17 . V_60 >> 4 ;
V_52 = V_2 -> V_72 . V_60 >> 4 ;
F_26 ( V_2 , V_62 , V_51 ) ;
F_26 ( V_2 , V_63 , V_52 ) ;
F_26 ( V_2 , V_65 , V_2 -> V_73 . V_4 ) ;
F_26 ( V_2 , V_64 ,
V_2 -> V_17 . V_4 | V_74 ) ;
F_2 ( L_19 ) ;
return V_6 ;
}
static void
F_30 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) ) {
F_2 ( L_20 ) ;
goto V_75;
}
V_2 -> V_76 = F_31 ( V_2 ) ;
F_2 ( L_21 ) ;
if ( F_29 ( V_2 ) ) {
F_2 ( L_22 ) ;
goto V_75;
}
return;
V_75:
F_32 ( V_2 -> V_77 , & V_2 -> V_75 ) ;
}
static bool
F_33 ( T_1 V_78 )
{
int V_79 =
F_5 ( V_78 & V_80 ) >>
V_81 ;
return ( V_79 == V_82 ||
V_79 == V_83 ) ;
}
void
F_34 ( struct V_1 * V_2 )
{
unsigned long V_42 ;
T_3 V_84 ;
F_35 ( & V_2 -> V_85 , V_42 ) ;
V_84 = F_15 ( V_2 , V_86 ) ;
if ( F_36 ( V_84 ) == V_87 )
F_10 ( V_2 , V_20 ,
F_36 ( V_84 ) |
F_37 ( V_84 ) |
F_38 ( V_84 ) ) ;
F_10 ( V_2 , V_20 ,
V_88 |
V_89 ) ;
V_2 -> V_90 =
(struct V_91 * )
F_18 ( V_2 , V_92 ) ;
F_39 ( & V_2 -> V_85 , V_42 ) ;
}
static void
F_40 ( struct V_1 * V_2 )
{
struct V_93 * V_41 = & ( V_2 -> V_94 ) ;
if ( V_41 -> V_95 == V_96 && F_41 ( V_2 ) ) {
struct V_97 V_38 ;
V_41 -> V_98 = 0 ;
V_41 -> V_99 = 0 ;
V_41 -> V_100 = 0 ;
V_41 -> V_101 = 0 ;
V_41 -> V_102 = 0 ;
V_41 -> V_103 = 0 ;
V_41 -> V_104 = 0 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_105 . V_106 = V_107 ;
V_38 . V_108 = 0 ;
V_38 . V_109 = 0 ;
V_38 . V_110 = 0 ;
if ( F_42 ( V_2 , V_111 , sizeof( V_38 ) , & V_38 ) )
F_7 ( L_23 ) ;
V_41 -> V_95 = V_112 ;
F_43 ( L_24 ) ;
}
}
static T_6
F_44 ( T_6 V_113 , T_6 V_114 , T_6 * V_115 )
{
T_6 V_116 = 1 ;
if ( V_113 < 0 ) {
V_116 = - V_116 ;
V_113 = - V_113 ;
}
if ( V_114 < 0 ) {
V_116 = - V_116 ;
V_114 = - V_114 ;
}
* V_115 = 1 ;
* V_115 = ( ( V_113 * 2 + V_114 ) / ( V_114 * 2 ) ) * V_116 ;
return 1 ;
}
static T_6
F_45 ( T_6 V_117 , T_6 V_118 )
{
T_6 V_119 = 0 ;
if ( V_120 == V_117 ||
V_120 == V_118 )
return 0 ;
F_44 ( V_118 - V_117 ,
V_121 , & V_119 ) ;
if ( V_118 > V_117 )
V_119 *= 2 ;
if ( ( V_119 < - 2 ) || ( V_119 > 2 ) )
V_119 = 0 ;
return V_119 ;
}
static T_6
F_46 ( T_3 V_122 )
{
if ( V_122 >= V_123 &&
V_122 <= V_124 )
return V_125 ;
if ( V_122 >= V_126 &&
V_122 <= V_127 )
return V_128 ;
if ( V_122 >= V_129 &&
V_122 <= V_130 )
return V_131 ;
if ( V_122 >= V_132 &&
V_122 <= V_133 )
return V_134 ;
if ( V_122 >= V_135 &&
V_122 <= V_136 )
return V_137 ;
return - V_30 ;
}
static T_2
F_47 ( const struct V_1 * V_2 , T_2 V_122 )
{
T_6 V_138 = - 1 ;
for ( V_138 = 0 ; V_138 < V_139 ; V_138 ++ ) {
if ( V_2 -> V_90 -> V_140 [ V_138 ] . V_141 == 0 )
continue;
if ( V_122 >= V_2 -> V_90 -> V_140 [ V_138 ] . V_141 &&
V_122 <= V_2 -> V_90 -> V_140 [ V_138 ] . V_142 )
break;
}
return V_138 ;
}
static T_6
F_48 ( T_6 V_143 , T_6 V_144 , T_6 y1 , T_6 V_145 , T_6 V_146 )
{
T_6 V_5 ;
if ( V_145 == V_144 )
return y1 ;
else {
F_44 ( ( V_145 - V_143 ) * ( y1 - V_146 ) , ( V_145 - V_144 ) , & V_5 ) ;
return V_5 + V_146 ;
}
}
static int
F_49 ( struct V_1 * V_2 , T_2 V_122 ,
struct V_147 * V_148 )
{
T_6 V_149 = - 1 ;
T_2 V_150 ;
T_2 V_151 ;
const struct V_152 * V_153 ;
const struct V_152 * V_154 ;
struct V_152 * V_155 ;
T_2 V_156 ;
T_2 V_157 ;
V_149 = F_47 ( V_2 , V_122 ) ;
if ( V_149 >= V_139 ) {
F_7 ( L_25 , V_122 ) ;
return - 1 ;
}
V_156 = V_2 -> V_90 -> V_140 [ V_149 ] . V_158 . V_159 ;
V_157 = V_2 -> V_90 -> V_140 [ V_149 ] . V_160 . V_159 ;
V_148 -> V_159 = ( T_4 ) V_122 ;
F_50 ( L_26 , V_122 , V_149 ,
V_156 , V_157 ) ;
for ( V_150 = 0 ; V_150 < V_161 ; V_150 ++ ) {
for ( V_151 = 0 ; V_151 < V_162 ; V_151 ++ ) {
V_153 = & ( V_2 -> V_90 -> V_140 [ V_149 ] . V_158 .
V_163 [ V_150 ] [ V_151 ] ) ;
V_154 = & ( V_2 -> V_90 -> V_140 [ V_149 ] . V_160 .
V_163 [ V_150 ] [ V_151 ] ) ;
V_155 = & ( V_148 -> V_163 [ V_150 ] [ V_151 ] ) ;
V_155 -> V_164 =
( T_4 ) F_48 ( V_122 , V_156 ,
V_153 -> V_164 , V_157 ,
V_154 -> V_164 ) ;
V_155 -> V_165 =
( T_4 ) F_48 ( V_122 , V_156 ,
V_153 -> V_165 , V_157 ,
V_154 -> V_165 ) ;
V_155 -> V_76 =
( T_4 ) F_48 ( V_122 , V_156 ,
V_153 -> V_76 ,
V_157 ,
V_154 -> V_76 ) ;
V_155 -> V_166 =
( V_167 ) F_48 ( V_122 , V_156 ,
V_153 -> V_166 , V_157 ,
V_154 -> V_166 ) ;
F_50 ( L_27 , V_150 ,
V_151 , V_153 -> V_164 , V_154 -> V_164 ,
V_155 -> V_164 ) ;
F_50 ( L_28 , V_150 ,
V_151 , V_153 -> V_165 , V_154 -> V_165 ,
V_155 -> V_165 ) ;
F_50 ( L_29 , V_150 ,
V_151 , V_153 -> V_166 , V_154 -> V_166 , V_155 -> V_166 ) ;
F_50 ( L_30 , V_150 ,
V_151 , V_153 -> V_76 , V_154 -> V_76 ,
V_155 -> V_76 ) ;
}
}
return 0 ;
}
static T_6
F_51 ( T_6 V_168 , T_2 V_169 )
{
if ( ! V_169 ) {
if ( ( V_168 & 7 ) <= 4 )
return V_170 ;
}
return V_171 ;
}
static int
F_52 ( struct V_1 * V_2 , T_4 V_169 , T_3 V_122 , T_4 V_172 ,
T_4 V_173 ,
struct V_174 * V_175 )
{
T_4 V_176 ;
T_6 V_177 ;
T_6 V_178 ;
T_6 V_179 ;
T_6 V_180 ;
T_6 V_181 ;
T_6 V_182 ;
T_6 V_183 = V_184 ;
int V_8 ;
int V_150 ;
const struct V_185 * V_186 = NULL ;
struct V_147 V_187 ;
const struct V_152 * V_188 ;
T_7 V_189 ;
T_6 V_190 ;
T_6 V_191 ;
T_6 V_192 ;
T_6 V_193 ;
T_6 V_194 ;
T_6 V_195 [ 2 ] ;
T_6 V_196 [ 2 ] ;
T_6 V_197 [ 2 ] ;
T_6 V_198 ;
V_178 = 2 * V_2 -> V_199 ;
F_50 ( L_31 , V_122 , V_169 , V_172 ) ;
V_186 = F_53 ( V_2 , V_2 -> V_169 , V_122 ) ;
if ( ! F_54 ( V_186 ) )
return - V_30 ;
V_183 = F_46 ( V_122 ) ;
if ( V_183 < 0 ) {
F_7 ( L_32 , V_122 ) ;
return V_183 ;
}
F_50 ( L_33 , V_122 ,
V_183 ) ;
if ( V_172 ) {
if ( V_173 )
V_122 -= 2 ;
else
V_122 += 2 ;
}
if ( V_169 )
V_176 = V_2 -> V_90 -> V_200 ;
else
V_176 = V_2 -> V_90 -> V_201 ;
if ( V_176 < V_202 ||
V_176 > V_203 ) {
if ( V_169 )
V_176 = V_204 ;
else
V_176 = V_205 ;
}
if ( V_172 )
V_181 = V_186 -> V_206 * 2 ;
else
V_181 = V_186 -> V_207 * 2 ;
if ( ( V_181 < V_208 ) ||
( V_181 > V_209 ) ) {
if ( V_169 )
V_181 = V_210 ;
else
V_181 = V_211 ;
}
F_49 ( V_2 , V_122 , & V_187 ) ;
V_189 = F_55 ( V_2 -> V_90 -> V_189 ) ;
V_190 = ( T_6 ) F_5 ( V_2 -> V_212 . V_189 ) ;
V_191 =
F_45 ( V_189 , V_190 ) ;
F_50 ( L_34 , V_190 ,
V_189 , V_191 ) ;
V_180 = F_56 ( V_2 -> V_76 , V_213 ) ;
V_180 = F_57 ( V_2 -> V_76 , V_214 ) ;
V_180 = F_58 ( V_180 ) ;
V_192 =
V_215 [ V_183 ] . V_216 ;
V_193 =
V_215 [ V_183 ] . V_217 ;
for ( V_150 = 0 ; V_150 < 2 ; V_150 ++ ) {
V_188 = & V_187 . V_163 [ V_150 ] [ 1 ] ;
V_194 = V_188 -> V_76 ;
F_44 ( ( V_180 -
V_194 ) * V_193 ,
V_192 ,
& V_195 [ V_150 ] ) ;
V_196 [ V_150 ] = V_188 -> V_165 ;
V_197 [ V_150 ] = V_188 -> V_164 ;
F_50 ( L_35 , V_150 ) ;
F_50 ( L_36 L_37 ,
V_194 , V_180 , V_195 [ V_150 ] ) ;
F_50 ( L_38 , V_196 [ V_150 ] ,
V_197 [ V_150 ] ) ;
}
for ( V_8 = 0 ; V_8 < V_218 ; V_8 ++ ) {
T_4 V_219 ;
union V_220 V_221 ;
if ( V_8 & 0x8 ) {
V_182 =
V_181 -
V_222 ;
V_219 = 1 ;
} else {
V_182 = V_181 ;
V_219 = 0 ;
}
V_179 = V_176 - V_223 [ V_8 ] ;
if ( V_179 > V_182 )
V_179 = V_182 ;
V_177 = V_178 ;
if ( V_177 > V_179 )
V_177 = V_179 ;
F_50 ( L_39 , V_8 ,
V_176 - V_223 [ V_8 ] ,
V_182 , V_178 , V_177 ) ;
for ( V_150 = 0 ; V_150 < 2 ; V_150 ++ ) {
T_6 V_224 ;
if ( V_219 )
V_224 =
( T_6 ) F_5 ( V_2 -> V_212 .
V_225 [ V_183 ] [ V_150 ] ) ;
else
V_224 = 0 ;
V_198 =
( T_4 ) ( V_196 [ V_150 ] -
( V_177 - V_197 [ V_150 ] ) -
V_195 [ V_150 ] - V_191 +
V_224 ) ;
if ( V_198 < F_51 ( V_8 , V_169 ) )
V_198 = F_51 ( V_8 , V_169 ) ;
if ( ! V_169 )
V_198 += 9 ;
if ( V_8 == V_226 )
V_198 +=
V_227 ;
if ( V_198 > 107 ) {
F_59 ( L_40 , V_198 ) ;
V_198 = 107 ;
}
if ( V_198 < 0 ) {
F_59 ( L_41 , V_198 ) ;
V_198 = 0 ;
}
V_221 . V_149 . V_228 [ V_150 ] =
V_229 [ V_169 ] [ V_198 ] . V_230 ;
V_221 . V_149 . V_231 [ V_150 ] =
V_229 [ V_169 ] [ V_198 ] . V_232 ;
F_50 ( L_42
L_43 , V_150 , V_224 ,
V_198 , V_221 . V_149 . V_228 [ V_150 ] ,
V_221 . V_149 . V_231 [ V_150 ] ) ;
}
V_175 -> V_233 [ V_8 ] . V_234 = F_60 ( V_221 . V_234 ) ;
}
return 0 ;
}
static int
F_61 ( struct V_1 * V_2 )
{
struct V_235 V_38 = { 0 } ;
int V_6 ;
T_4 V_169 = 0 ;
bool V_172 = false ;
T_4 V_173 = 0 ;
if ( F_62
( F_63 ( V_236 , & V_2 -> V_237 ) ,
L_44 ) )
return - V_238 ;
V_169 = V_2 -> V_169 == V_239 ;
V_172 = F_33 ( V_2 -> V_240 . V_42 ) ;
if ( V_172 && ( V_2 -> V_240 . V_42 & V_241 ) )
V_173 = 1 ;
V_38 . V_169 = V_169 ;
V_38 . V_122 = V_2 -> V_240 . V_122 ;
V_6 =
F_52 ( V_2 , V_169 , F_55 ( V_2 -> V_240 . V_122 ) ,
V_172 , V_173 , & V_38 . V_221 ) ;
if ( V_6 )
goto V_242;
V_6 = F_42 ( V_2 , V_243 , sizeof( V_38 ) , & V_38 ) ;
V_242:
return V_6 ;
}
static int
F_64 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
struct V_244 V_245 ;
const struct V_246 * V_247 = & V_2 -> V_248 ;
const struct V_246 * V_249 = & V_2 -> V_240 ;
if ( V_247 -> V_42 == V_249 -> V_42 &&
V_247 -> V_250 == V_249 -> V_250 &&
V_247 -> V_251 == V_249 -> V_251 &&
V_247 -> V_252 ==
V_249 -> V_252 &&
V_247 -> V_253 ==
V_249 -> V_253 &&
V_247 -> V_254 == V_249 -> V_254 &&
V_247 -> V_255 == V_249 -> V_255 ) {
F_2 ( L_45 ) ;
return 0 ;
}
V_245 . V_42 = V_2 -> V_248 . V_42 ;
V_245 . V_250 = V_2 -> V_248 . V_250 ;
V_245 . V_255 = V_2 -> V_248 . V_255 ;
V_245 . V_251 = V_2 -> V_248 . V_251 ;
V_245 . V_256 = 0 ;
V_245 . V_252 =
V_2 -> V_248 . V_252 ;
V_245 . V_253 =
V_2 -> V_248 . V_253 ;
V_245 . V_257 = V_2 -> V_248 . V_254 ;
V_6 =
F_65 ( V_2 , V_258 , sizeof( V_245 ) ,
& V_245 , NULL ) ;
return V_6 ;
}
static int
F_66 ( struct V_1 * V_2 )
{
struct V_246 * V_259 = ( void * ) & V_2 -> V_240 ;
int V_6 ;
bool V_260 = ! ! ( V_2 -> V_248 . V_250 & V_261 ) ;
if ( ! F_67 ( V_2 ) )
return - V_262 ;
V_2 -> V_248 . V_42 |= V_263 ;
V_6 = F_68 ( V_2 ) ;
if ( V_6 ) {
F_7 ( L_46 ) ;
return - V_30 ;
}
if ( F_63 ( V_264 , & V_2 -> V_237 ) &&
V_2 -> V_265 != V_2 -> V_248 . V_122 ) {
F_69 ( L_47 ,
F_55 ( V_2 -> V_265 ) ) ;
F_70 ( V_2 , false ) ;
}
if ( ! F_71 ( V_2 ) ) {
V_6 = F_72 ( V_2 ) ;
if ( V_6 ) {
F_7 ( L_48 , V_6 ) ;
return V_6 ;
}
memcpy ( V_259 , & V_2 -> V_248 , sizeof( * V_259 ) ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 , V_2 -> V_266 , false ) ;
return 0 ;
}
if ( F_75 ( V_2 ) && V_260 ) {
F_2 ( L_49 ) ;
V_259 -> V_250 &= ~ V_261 ;
V_6 =
F_42 ( V_2 , V_267 ,
sizeof( struct V_246 ) , V_259 ) ;
if ( V_6 ) {
V_259 -> V_250 |= V_261 ;
F_7 ( L_50 , V_6 ) ;
return V_6 ;
}
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
V_6 = F_78 ( V_2 ) ;
if ( V_6 ) {
F_7 ( L_51 , V_6 ) ;
return V_6 ;
}
}
F_2 ( L_52 L_53
L_54 L_55 , ( V_260 ? L_56 : L_57 ) ,
F_55 ( V_2 -> V_248 . V_122 ) , V_2 -> V_248 . V_268 ) ;
F_79 ( V_2 , ! V_2 -> V_27 -> V_269 -> V_270 ) ;
if ( ! V_260 ) {
V_6 =
F_42 ( V_2 , V_267 ,
sizeof( struct V_246 ) , & V_2 -> V_248 ) ;
if ( V_6 ) {
F_7 ( L_58 , V_6 ) ;
return V_6 ;
}
F_2 ( L_59 ) ;
memcpy ( V_259 , & V_2 -> V_248 , sizeof( * V_259 ) ) ;
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
V_6 = F_78 ( V_2 ) ;
if ( V_6 ) {
F_7 ( L_51 , V_6 ) ;
return V_6 ;
}
}
if ( V_260 ) {
V_2 -> V_271 = 0 ;
V_6 =
F_42 ( V_2 , V_267 ,
sizeof( struct V_246 ) , & V_2 -> V_248 ) ;
if ( V_6 ) {
F_7 ( L_58 , V_6 ) ;
return V_6 ;
}
memcpy ( V_259 , & V_2 -> V_248 , sizeof( * V_259 ) ) ;
}
F_73 ( V_2 ) ;
F_80 ( V_2 ) ;
V_6 = F_74 ( V_2 , V_2 -> V_266 , true ) ;
if ( V_6 ) {
F_7 ( L_60 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int
F_81 ( struct V_1 * V_2 ,
struct V_272 * V_273 )
{
int V_274 ;
T_4 V_169 = 0 ;
bool V_172 = false ;
T_4 V_173 = 0 ;
struct V_275 V_38 ;
const struct V_185 * V_186 ;
T_2 V_276 , V_277 ;
T_3 V_278 ;
T_2 V_279 ;
T_4 V_280 ;
T_3 V_281 = F_55 ( V_2 -> V_282 . V_281 ) ;
struct V_283 * V_284 = V_2 -> V_284 ;
V_169 = ( V_2 -> V_169 == V_239 ) ;
if ( F_82 ( V_284 == NULL ) )
return - V_12 ;
V_172 = F_33 ( V_2 -> V_248 . V_42 ) ;
if ( V_172 && ( V_2 -> V_248 . V_42 & V_241 ) )
V_173 = 1 ;
V_38 . V_169 = V_169 ;
V_38 . V_285 = 0 ;
V_278 = V_273 -> V_122 -> V_286 ;
V_38 . V_122 = F_83 ( V_278 ) ;
V_38 . V_78 = V_2 -> V_248 . V_42 ;
V_38 . V_287 = V_2 -> V_248 . V_250 ;
V_280 = V_273 -> V_18 ;
V_279 = V_273 -> V_288 & 0x0ffffffff ;
if ( V_2 -> V_289 > V_279 && V_281 ) {
if ( V_280 >
( ( V_2 -> V_289 - V_279 ) / V_281 ) ) {
V_280 -=
( V_2 -> V_289 - V_279 ) / V_281 ;
} else
V_280 = 0 ;
}
if ( V_280 <= 1 )
V_38 . V_290 = F_60 ( V_2 -> V_289 ) ;
else {
V_276 =
V_284 -> V_291 . V_292 * V_280 * V_293 ;
V_277 =
F_84 ( V_2 , V_276 ,
V_281 ) ;
V_38 . V_290 =
F_85 ( V_2 , V_2 -> V_289 ,
V_277 , V_281 ) ;
}
F_69 ( L_61 , V_38 . V_290 ) ;
V_186 = F_53 ( V_2 , V_2 -> V_169 , V_278 ) ;
if ( V_186 )
V_38 . V_285 = F_86 ( V_186 ) ;
else {
F_7 ( L_62 ,
V_2 -> V_240 . V_122 , V_278 ) ;
return - V_294 ;
}
V_274 = F_52 ( V_2 , V_169 , V_278 , V_172 , V_173 ,
& V_38 . V_221 ) ;
if ( V_274 ) {
F_69 ( L_63 , V_274 ) ;
return V_274 ;
}
return F_42 ( V_2 , V_295 , sizeof( V_38 ) , & V_38 ) ;
}
static void
F_87 ( struct V_1 * V_2 , struct V_296 * V_297 ,
T_3 V_298 )
{
struct V_299 * V_300 = V_2 -> V_301 . V_32 ;
int V_302 = V_297 -> V_303 . V_39 ;
int V_304 = V_297 -> V_303 . V_304 ;
int V_4 = V_298 + V_305 + V_306 ;
T_8 V_307 ;
F_88 ( V_4 > 0xFFF || V_304 >= V_308 ) ;
V_307 = F_83 ( V_4 & 0xFFF ) ;
V_300 [ V_302 ] . V_309 [ V_304 ] = V_307 ;
if ( V_304 < V_310 )
V_300 [ V_302 ] . V_309 [ V_308 + V_304 ] =
V_307 ;
}
static int
F_31 ( struct V_1 * V_2 )
{
T_6 V_76 ;
T_6 V_311 ;
T_6 V_312 , V_313 , V_314 ;
T_2 V_315 ;
if ( F_63 ( V_316 , & V_2 -> V_237 ) &&
( V_2 -> V_317 . V_318 . V_319 & V_320 ) ) {
F_89 ( L_64 ) ;
V_312 = ( T_6 ) F_5 ( V_2 -> V_212 . V_321 [ 1 ] ) ;
V_313 = ( T_6 ) F_5 ( V_2 -> V_212 . V_322 [ 1 ] ) ;
V_314 = ( T_6 ) F_5 ( V_2 -> V_212 . V_323 [ 1 ] ) ;
V_315 = F_5 ( V_2 -> V_212 . V_324 [ 1 ] ) ;
} else {
F_89 ( L_65 ) ;
V_312 = ( T_6 ) F_5 ( V_2 -> V_212 . V_321 [ 0 ] ) ;
V_313 = ( T_6 ) F_5 ( V_2 -> V_212 . V_322 [ 0 ] ) ;
V_314 = ( T_6 ) F_5 ( V_2 -> V_212 . V_323 [ 0 ] ) ;
V_315 = F_5 ( V_2 -> V_212 . V_324 [ 0 ] ) ;
}
if ( ! F_63 ( V_316 , & V_2 -> V_237 ) )
V_311 = F_90 ( V_315 , 23 ) ;
else
V_311 = F_90 ( F_5
( V_2 -> V_317 . V_318 . V_325 . V_326 . V_76 ) ,
23 ) ;
F_89 ( L_66 , V_312 , V_313 , V_314 , V_311 ) ;
if ( V_314 == V_312 ) {
F_7 ( L_67 ) ;
return - 1 ;
}
V_76 = V_327 * ( V_311 - V_313 ) ;
V_76 /= ( V_314 - V_312 ) ;
V_76 =
( V_76 * 97 ) / 100 + V_328 ;
F_89 ( L_68 , V_76 ,
F_58 ( V_76 ) ) ;
return V_76 ;
}
static int
F_91 ( struct V_1 * V_2 )
{
int V_329 ;
if ( ! F_63 ( V_330 , & V_2 -> V_237 ) ) {
F_89 ( L_69 ) ;
return 0 ;
}
V_329 = V_2 -> V_76 - V_2 -> V_331 ;
if ( V_329 < 0 ) {
F_92 ( L_70 , V_329 ) ;
V_329 = - V_329 ;
} else if ( V_329 == 0 )
F_92 ( L_71 ) ;
else
F_92 ( L_72 , V_329 ) ;
if ( V_329 < V_332 ) {
F_92 ( L_73 ) ;
return 0 ;
}
F_92 ( L_74 ) ;
return 1 ;
}
void
F_93 ( struct V_1 * V_2 )
{
T_6 V_333 ;
V_333 = F_31 ( V_2 ) ;
if ( F_94 ( V_333 ) )
return;
if ( V_2 -> V_76 != V_333 ) {
if ( V_2 -> V_76 )
F_89 ( L_75 L_76 ,
F_58 ( V_2 -> V_76 ) ,
F_58 ( V_333 ) ) ;
else
F_89 ( L_77 L_78 ,
F_58 ( V_333 ) ) ;
}
V_2 -> V_76 = V_333 ;
F_95 ( V_316 , & V_2 -> V_237 ) ;
if ( ! V_2 -> V_334 &&
F_96 ( ! F_63 ( V_335 , & V_2 -> V_237 ) ) &&
F_91 ( V_2 ) )
F_32 ( V_2 -> V_77 , & V_2 -> V_336 ) ;
}
static T_3
F_97 ( T_4 V_337 , T_3 V_4 )
{
switch ( V_337 ) {
case V_267 :
return ( T_3 ) sizeof( struct V_338 ) ;
default:
return V_4 ;
}
}
static T_3
F_98 ( const struct V_339 * V_38 , T_4 * V_41 )
{
struct V_340 * V_341 = (struct V_340 * ) V_41 ;
V_341 -> V_342 = V_38 -> V_342 ;
memcpy ( & V_341 -> V_343 , & V_38 -> V_343 , sizeof( struct V_344 ) ) ;
memcpy ( & V_341 -> V_345 , & V_38 -> V_345 , sizeof( struct V_346 ) ) ;
V_341 -> V_347 = V_38 -> V_347 ;
V_341 -> V_348 = V_38 -> V_348 ;
V_341 -> V_349 = V_38 -> V_349 ;
V_341 -> V_350 = V_38 -> V_350 ;
V_341 -> V_351 = V_38 -> V_351 ;
V_341 -> V_352 = V_38 -> V_352 ;
V_341 -> V_353 = V_38 -> V_353 ;
V_341 -> V_354 = F_83 ( 0 ) ;
V_341 -> V_355 = F_83 ( 0 ) ;
return ( T_3 ) sizeof( struct V_340 ) ;
}
static void
F_99 ( struct V_1 * V_2 )
{
if ( memcmp ( & V_2 -> V_248 , & V_2 -> V_240 , sizeof( V_2 -> V_248 ) ) )
F_100 ( V_2 ) ;
}
static void
F_101 ( struct V_1 * V_2 )
{
struct V_283 * V_284 = V_2 -> V_284 ;
struct V_356 * V_357 = NULL ;
int V_6 = 0 ;
if ( ! V_284 || ! V_2 -> V_358 )
return;
if ( F_63 ( V_359 , & V_2 -> V_237 ) )
return;
F_102 ( V_2 , 200 ) ;
V_357 = & V_2 -> V_360 -> V_357 ;
V_2 -> V_248 . V_250 &= ~ V_261 ;
F_100 ( V_2 ) ;
V_6 = F_103 ( V_2 ) ;
if ( V_6 )
F_59 ( L_79 L_80 ) ;
V_2 -> V_248 . V_250 |= V_261 ;
F_104 ( V_2 , & V_2 -> V_361 ) ;
if ( V_2 -> V_362 -> V_363 )
V_2 -> V_362 -> V_363 ( V_2 ) ;
V_2 -> V_248 . V_364 = F_83 ( V_284 -> V_291 . V_365 ) ;
F_105 ( L_81 , V_284 -> V_291 . V_365 ,
V_284 -> V_291 . V_292 ) ;
if ( V_284 -> V_291 . V_366 )
V_2 -> V_248 . V_42 |= V_367 ;
else
V_2 -> V_248 . V_42 &= ~ V_367 ;
if ( V_2 -> V_248 . V_42 & V_368 ) {
if ( V_284 -> V_291 . V_369 )
V_2 -> V_248 . V_42 |= V_370 ;
else
V_2 -> V_248 . V_42 &= ~ V_370 ;
}
F_100 ( V_2 ) ;
F_105 ( L_82 , V_284 -> V_291 . V_365 ,
V_2 -> V_240 . V_268 ) ;
switch ( V_284 -> type ) {
case V_371 :
break;
case V_372 :
F_106 ( V_2 ) ;
break;
default:
F_7 ( L_83 , V_373 ,
V_284 -> type ) ;
break;
}
if ( V_2 -> V_94 . V_95 == V_374 )
F_107 ( V_2 , false ) ;
F_40 ( V_2 ) ;
V_2 -> V_271 = 1 ;
}
static void
F_108 ( struct V_1 * V_2 )
{
struct V_283 * V_284 = V_2 -> V_284 ;
int V_6 = 0 ;
F_109 ( & V_2 -> V_375 ) ;
if ( F_63 ( V_359 , & V_2 -> V_237 ) )
return;
if ( ! F_75 ( V_2 ) ) {
V_2 -> V_248 . V_250 &= ~ V_261 ;
F_100 ( V_2 ) ;
V_6 = F_103 ( V_2 ) ;
if ( V_6 )
F_59 ( L_84
L_80 ) ;
V_2 -> V_94 . V_376 = V_2 -> V_377 . V_378 ;
F_104 ( V_2 , & V_2 -> V_361 ) ;
if ( V_2 -> V_362 -> V_363 )
V_2 -> V_362 -> V_363 ( V_2 ) ;
V_2 -> V_248 . V_364 = 0 ;
if ( V_284 -> V_291 . V_366 )
V_2 -> V_248 . V_42 |= V_367 ;
else
V_2 -> V_248 . V_42 &= ~ V_367 ;
if ( V_2 -> V_248 . V_42 & V_368 ) {
if ( V_284 -> V_291 . V_369 )
V_2 -> V_248 . V_42 |= V_370 ;
else
V_2 -> V_248 . V_42 &= ~ V_370 ;
}
F_106 ( V_2 ) ;
V_2 -> V_248 . V_250 |= V_261 ;
F_100 ( V_2 ) ;
}
F_106 ( V_2 ) ;
}
