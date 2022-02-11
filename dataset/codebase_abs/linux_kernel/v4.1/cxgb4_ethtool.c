static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
F_2 ( V_2 ) -> V_3 = V_4 ;
}
static int F_4 ( struct V_1 * V_2 , int V_5 )
{
switch ( V_5 ) {
case V_6 :
return F_5 ( V_7 ) ;
default:
return - V_8 ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_7 ( V_10 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return V_11 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_9 * V_9 = F_2 ( V_2 ) ;
T_1 V_14 ;
F_10 ( V_13 -> V_15 , V_16 , sizeof( V_13 -> V_15 ) ) ;
F_10 ( V_13 -> V_17 , V_18 ,
sizeof( V_13 -> V_17 ) ) ;
F_10 ( V_13 -> V_19 , F_11 ( V_9 -> V_20 ) ,
sizeof( V_13 -> V_19 ) ) ;
if ( V_9 -> V_21 . V_22 )
snprintf ( V_13 -> V_23 , sizeof( V_13 -> V_23 ) ,
L_1 ,
F_12 ( V_9 -> V_21 . V_22 ) ,
F_13 ( V_9 -> V_21 . V_22 ) ,
F_14 ( V_9 -> V_21 . V_22 ) ,
F_15 ( V_9 -> V_21 . V_22 ) ,
F_12 ( V_9 -> V_21 . V_24 ) ,
F_13 ( V_9 -> V_21 . V_24 ) ,
F_14 ( V_9 -> V_21 . V_24 ) ,
F_15 ( V_9 -> V_21 . V_24 ) ) ;
if ( ! F_16 ( V_9 , & V_14 ) )
snprintf ( V_13 -> V_25 , sizeof( V_13 -> V_25 ) ,
L_2 ,
F_12 ( V_14 ) ,
F_13 ( V_14 ) ,
F_14 ( V_14 ) ,
F_15 ( V_14 ) ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_26 , T_2 * V_27 )
{
if ( V_26 == V_6 )
memcpy ( V_27 , V_7 , sizeof( V_7 ) ) ;
}
static void F_18 ( const struct V_9 * V_10 ,
const struct V_28 * V_29 ,
struct V_30 * V_31 )
{
int V_32 ;
const struct V_33 * V_34 = & V_10 -> V_35 . V_36 [ V_29 -> V_37 ] ;
const struct V_38 * V_39 = & V_10 -> V_35 . V_40 [ V_29 -> V_37 ] ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
for ( V_32 = 0 ; V_32 < V_29 -> V_41 ; V_32 ++ , V_39 ++ , V_34 ++ ) {
V_31 -> V_42 += V_34 -> V_42 ;
V_31 -> V_43 += V_34 -> V_44 ;
V_31 -> V_45 += V_39 -> V_46 . V_47 ;
V_31 -> V_48 += V_39 -> V_46 . V_48 ;
V_31 -> V_49 += V_34 -> V_49 ;
V_31 -> V_50 += V_39 -> V_46 . V_51 ;
V_31 -> V_52 += V_39 -> V_46 . V_53 ;
}
}
static void F_19 ( struct V_1 * V_2 , struct V_54 * V_46 ,
T_3 * V_27 )
{
struct V_28 * V_55 = F_20 ( V_2 ) ;
struct V_9 * V_9 = V_55 -> V_9 ;
T_1 V_56 , V_57 ;
F_21 ( V_9 , V_55 -> V_58 , (struct V_59 * ) V_27 ) ;
V_27 += sizeof( struct V_59 ) / sizeof( T_3 ) ;
F_18 ( V_9 , V_55 , (struct V_30 * ) V_27 ) ;
V_27 += sizeof( struct V_30 ) / sizeof( T_3 ) ;
if ( ! F_22 ( V_9 -> V_21 . V_60 ) ) {
F_23 ( V_9 , V_61 , F_24 ( 7 ) ) ;
V_56 = F_25 ( V_9 , V_62 ) ;
V_57 = F_25 ( V_9 , V_63 ) ;
* V_27 = V_56 - V_57 ;
V_27 ++ ;
* V_27 = V_57 ;
V_27 ++ ;
} else {
memset ( V_27 , 0 , 2 * sizeof( T_3 ) ) ;
* V_27 += 2 ;
}
}
static void F_26 ( struct V_1 * V_2 , struct V_64 * V_65 ,
void * V_66 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_4 V_67 ;
V_67 = F_7 ( V_10 ) ;
V_65 -> V_17 = F_27 ( V_10 ) ;
F_28 ( V_10 , V_66 , V_67 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = F_20 ( V_2 ) ;
if ( ! F_30 ( V_2 ) )
return - V_68 ;
if ( V_29 -> V_69 . V_70 != V_71 )
return - V_72 ;
F_31 ( V_29 -> V_9 , V_29 -> V_9 -> V_73 , V_29 -> V_58 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
enum V_74 V_75 )
{
unsigned int V_4 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_75 == V_76 )
V_4 = 0xffff ;
else if ( V_75 == V_77 )
V_4 = 0 ;
else
return - V_72 ;
return F_33 ( V_10 , V_10 -> V_73 , F_34 ( V_2 ) -> V_78 , V_4 ) ;
}
static unsigned int F_35 ( enum V_79 type , unsigned int V_80 )
{
unsigned int V_81 = 0 ;
if ( type == V_82 || type == V_83 ||
type == V_84 ) {
V_81 |= V_85 ;
if ( V_80 & V_86 )
V_81 |= V_87 ;
if ( V_80 & V_88 )
V_81 |= V_89 ;
if ( V_80 & V_90 )
V_81 |= V_91 ;
} else if ( type == V_92 || type == V_93 ) {
V_81 |= V_94 ;
if ( V_80 & V_88 )
V_81 |= V_95 ;
if ( V_80 & V_90 )
V_81 |= V_96 ;
} else if ( type == V_97 ) {
V_81 |= V_94 | V_98 ;
} else if ( type == V_99 ) {
V_81 |= V_94 | V_100 |
V_98 | V_95 ;
} else if ( type == V_101 ) {
V_81 |= V_94 | V_100 |
V_98 | V_95 |
V_96 ;
} else if ( type == V_102 ||
type == V_103 ||
type == V_104 ||
type == V_105 ||
type == V_106 ) {
V_81 |= V_107 ;
if ( V_80 & V_88 )
V_81 |= V_89 ;
if ( V_80 & V_90 )
V_81 |= V_91 ;
} else if ( type == V_108 ||
type == V_109 ) {
V_81 |= V_110 ;
V_81 |= V_107 ;
}
if ( V_80 & V_111 )
V_81 |= V_112 ;
return V_81 ;
}
static unsigned int F_36 ( unsigned int V_80 )
{
unsigned int V_81 = 0 ;
if ( V_80 & V_113 )
V_81 |= V_86 ;
if ( V_80 & V_114 )
V_81 |= V_88 ;
if ( V_80 & V_115 )
V_81 |= V_90 ;
if ( V_80 & V_116 )
V_81 |= V_117 ;
return V_81 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_118 * V_119 )
{
const struct V_28 * V_29 = F_20 ( V_2 ) ;
if ( V_29 -> V_120 == V_82 ||
V_29 -> V_120 == V_83 ||
V_29 -> V_120 == V_84 ) {
V_119 -> V_121 = V_122 ;
} else if ( V_29 -> V_120 == V_102 ||
V_29 -> V_120 == V_103 ) {
V_119 -> V_121 = V_123 ;
} else if ( V_29 -> V_120 == V_104 ||
V_29 -> V_120 == V_105 ||
V_29 -> V_120 == V_106 ||
V_29 -> V_120 == V_109 ) {
if ( V_29 -> V_124 == V_125 ||
V_29 -> V_124 == V_126 ||
V_29 -> V_124 == V_127 ||
V_29 -> V_124 == V_128 )
V_119 -> V_121 = V_123 ;
else if ( V_29 -> V_124 == V_129 ||
V_29 -> V_124 == V_130 )
V_119 -> V_121 = V_131 ;
else
V_119 -> V_121 = V_132 ;
} else {
V_119 -> V_121 = V_132 ;
}
if ( V_29 -> V_133 >= 0 ) {
V_119 -> V_134 = V_29 -> V_133 ;
V_119 -> V_135 = V_136 ;
V_119 -> V_137 = V_29 -> V_120 == V_82 ?
V_138 : V_139 ;
} else {
V_119 -> V_134 = 0 ;
V_119 -> V_135 = V_140 ;
V_119 -> V_137 = 0 ;
}
V_119 -> V_141 = F_35 ( V_29 -> V_120 , V_29 -> V_69 . V_141 ) ;
V_119 -> V_142 = F_35 ( V_29 -> V_120 ,
V_29 -> V_69 . V_142 ) ;
F_38 ( V_119 ,
F_39 ( V_2 ) ? V_29 -> V_69 . V_143 : 0 ) ;
V_119 -> V_144 = V_145 ;
V_119 -> V_70 = V_29 -> V_69 . V_70 ;
V_119 -> V_146 = 0 ;
V_119 -> V_147 = 0 ;
return 0 ;
}
static unsigned int F_40 ( int V_143 )
{
if ( V_143 == 100 )
return V_86 ;
if ( V_143 == 1000 )
return V_88 ;
if ( V_143 == 10000 )
return V_90 ;
if ( V_143 == 40000 )
return V_117 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_118 * V_119 )
{
unsigned int V_148 ;
struct V_28 * V_29 = F_20 ( V_2 ) ;
struct V_149 * V_150 = & V_29 -> V_69 ;
T_1 V_143 = F_42 ( V_119 ) ;
if ( V_119 -> V_144 != V_145 )
return - V_72 ;
if ( ! ( V_150 -> V_141 & V_111 ) ) {
if ( V_119 -> V_70 == V_151 &&
( V_150 -> V_141 & F_40 ( V_143 ) ) )
return 0 ;
return - V_72 ;
}
if ( V_119 -> V_70 == V_151 ) {
V_148 = F_40 ( V_143 ) ;
if ( ! ( V_150 -> V_141 & V_148 ) ||
( V_143 == 1000 ) ||
( V_143 == 10000 ) ||
( V_143 == 40000 ) )
return - V_72 ;
V_150 -> V_152 = V_148 ;
V_150 -> V_142 = 0 ;
} else {
V_148 = F_36 ( V_119 -> V_142 ) ;
if ( ! ( V_150 -> V_141 & V_148 ) )
return - V_72 ;
V_150 -> V_152 = 0 ;
V_150 -> V_142 = V_148 | V_111 ;
}
V_150 -> V_70 = V_119 -> V_70 ;
if ( F_30 ( V_2 ) )
return F_43 ( V_29 -> V_9 , V_29 -> V_9 -> V_73 , V_29 -> V_58 ,
V_150 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_28 * V_29 = F_20 ( V_2 ) ;
V_154 -> V_70 = ( V_29 -> V_69 . V_155 & V_156 ) != 0 ;
V_154 -> V_157 = ( V_29 -> V_69 . V_158 & V_159 ) != 0 ;
V_154 -> V_160 = ( V_29 -> V_69 . V_158 & V_161 ) != 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_28 * V_29 = F_20 ( V_2 ) ;
struct V_149 * V_150 = & V_29 -> V_69 ;
if ( V_154 -> V_70 == V_151 )
V_150 -> V_155 = 0 ;
else if ( V_150 -> V_141 & V_111 )
V_150 -> V_155 = V_156 ;
else
return - V_72 ;
if ( V_154 -> V_157 )
V_150 -> V_155 |= V_159 ;
if ( V_154 -> V_160 )
V_150 -> V_155 |= V_161 ;
if ( F_30 ( V_2 ) )
return F_43 ( V_29 -> V_9 , V_29 -> V_9 -> V_73 , V_29 -> V_58 ,
V_150 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
const struct V_28 * V_55 = F_20 ( V_2 ) ;
const struct V_35 * V_31 = & V_55 -> V_9 -> V_35 ;
V_163 -> V_164 = V_165 ;
V_163 -> V_166 = V_167 ;
V_163 -> V_168 = 0 ;
V_163 -> V_169 = V_170 ;
V_163 -> V_171 = V_31 -> V_40 [ V_55 -> V_37 ] . V_172 . V_173 - 8 ;
V_163 -> V_174 = V_31 -> V_40 [ V_55 -> V_37 ] . V_175 . V_173 ;
V_163 -> V_176 = 0 ;
V_163 -> V_177 = V_31 -> V_36 [ V_55 -> V_37 ] . V_178 . V_173 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
int V_32 ;
const struct V_28 * V_55 = F_20 ( V_2 ) ;
struct V_9 * V_9 = V_55 -> V_9 ;
struct V_35 * V_31 = & V_9 -> V_35 ;
if ( V_163 -> V_171 > V_165 || V_163 -> V_176 ||
V_163 -> V_177 > V_170 ||
V_163 -> V_174 > V_167 ||
V_163 -> V_174 < V_179 ||
V_163 -> V_171 < V_180 || V_163 -> V_177 < V_181 )
return - V_72 ;
if ( V_9 -> V_182 & V_183 )
return - V_184 ;
for ( V_32 = 0 ; V_32 < V_55 -> V_41 ; ++ V_32 ) {
V_31 -> V_36 [ V_55 -> V_37 + V_32 ] . V_178 . V_173 = V_163 -> V_177 ;
V_31 -> V_40 [ V_55 -> V_37 + V_32 ] . V_172 . V_173 = V_163 -> V_171 + 8 ;
V_31 -> V_40 [ V_55 -> V_37 + V_32 ] . V_175 . V_173 = V_163 -> V_174 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
unsigned int V_185 , unsigned int V_186 )
{
int V_32 , V_187 ;
struct V_28 * V_55 = F_20 ( V_2 ) ;
struct V_9 * V_10 = V_55 -> V_9 ;
struct V_38 * V_178 = & V_10 -> V_35 . V_40 [ V_55 -> V_37 ] ;
for ( V_32 = 0 ; V_32 < V_55 -> V_41 ; V_32 ++ , V_178 ++ ) {
V_187 = F_49 ( & V_178 -> V_175 , V_185 , V_186 ) ;
if ( V_187 )
return V_187 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_188 )
{
int V_32 ;
struct V_28 * V_55 = F_20 ( V_2 ) ;
struct V_9 * V_10 = V_55 -> V_9 ;
struct V_38 * V_178 = & V_10 -> V_35 . V_40 [ V_55 -> V_37 ] ;
for ( V_32 = 0 ; V_32 < V_55 -> V_41 ; V_32 ++ , V_178 ++ )
V_178 -> V_175 . V_188 = V_188 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_28 * V_55 = F_20 ( V_2 ) ;
struct V_9 * V_10 = V_55 -> V_9 ;
struct V_38 * V_178 = & V_10 -> V_35 . V_40 [ V_55 -> V_37 ] ;
return V_178 -> V_175 . V_188 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
F_50 ( V_2 , V_190 -> V_191 ) ;
return F_48 ( V_2 , V_190 -> V_192 ,
V_190 -> V_193 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
const struct V_28 * V_55 = F_20 ( V_2 ) ;
const struct V_9 * V_10 = V_55 -> V_9 ;
const struct V_194 * V_195 = & V_10 -> V_35 . V_40 [ V_55 -> V_37 ] . V_175 ;
V_190 -> V_192 = F_54 ( V_10 , V_195 ) ;
V_190 -> V_193 = ( V_195 -> V_196 & V_197 ) ?
V_10 -> V_35 . V_198 [ V_195 -> V_199 ] : 0 ;
V_190 -> V_191 = F_51 ( V_2 ) ;
return 0 ;
}
static int F_55 ( unsigned int V_200 , unsigned int V_73 , unsigned int V_201 )
{
V_73 *= V_201 ;
if ( V_200 < 1024 )
return V_200 + ( 31 << 10 ) ;
if ( V_200 < 1024 + V_73 )
return 31744 - V_73 + V_200 - 1024 ;
if ( V_200 < V_11 )
return V_200 - 1024 - V_73 ;
return - V_72 ;
}
static int F_56 ( struct V_9 * V_10 , unsigned int V_200 , T_1 * V_81 )
{
int V_202 = F_55 ( V_200 , V_10 -> V_73 , V_203 ) ;
if ( V_202 >= 0 )
V_202 = F_57 ( V_10 -> V_20 , V_202 , sizeof( T_1 ) , V_81 ) ;
return V_202 < 0 ? V_202 : 0 ;
}
static int F_58 ( struct V_9 * V_10 , unsigned int V_200 , T_1 V_81 )
{
int V_202 = F_55 ( V_200 , V_10 -> V_73 , V_203 ) ;
if ( V_202 >= 0 )
V_202 = F_59 ( V_10 -> V_20 , V_202 , sizeof( T_1 ) , & V_81 ) ;
return V_202 < 0 ? V_202 : 0 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_204 * V_163 ,
T_2 * V_27 )
{
int V_32 , V_187 = 0 ;
struct V_9 * V_9 = F_2 ( V_2 ) ;
T_2 * V_66 = F_61 ( V_11 , V_205 ) ;
if ( ! V_66 )
return - V_206 ;
V_163 -> V_207 = V_208 ;
for ( V_32 = V_163 -> V_209 & ~ 3 ; ! V_187 && V_32 < V_163 -> V_209 + V_163 -> V_210 ; V_32 += 4 )
V_187 = F_56 ( V_9 , V_32 , ( T_1 * ) & V_66 [ V_32 ] ) ;
if ( ! V_187 )
memcpy ( V_27 , V_66 + V_163 -> V_209 , V_163 -> V_210 ) ;
F_62 ( V_66 ) ;
return V_187 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_204 * V_211 ,
T_2 * V_27 )
{
T_2 * V_66 ;
int V_187 = 0 ;
T_1 V_212 , V_213 , * V_29 ;
struct V_9 * V_9 = F_2 ( V_2 ) ;
if ( V_211 -> V_207 != V_208 )
return - V_72 ;
V_212 = V_211 -> V_209 & ~ 3 ;
V_213 = ( V_211 -> V_210 + ( V_211 -> V_209 & 3 ) + 3 ) & ~ 3 ;
if ( V_9 -> V_73 > 0 ) {
T_1 V_214 = 1024 + V_9 -> V_73 * V_203 ;
if ( V_212 < V_214 ||
V_212 + V_213 > V_214 + V_203 )
return - V_215 ;
}
if ( V_212 != V_211 -> V_209 || V_213 != V_211 -> V_210 ) {
V_66 = F_61 ( V_213 , V_205 ) ;
if ( ! V_66 )
return - V_206 ;
V_187 = F_56 ( V_9 , V_212 , ( T_1 * ) V_66 ) ;
if ( ! V_187 && V_213 > 4 )
V_187 = F_56 ( V_9 ,
V_212 + V_213 - 4 ,
( T_1 * ) & V_66 [ V_213 - 4 ] ) ;
if ( V_187 )
goto V_216;
memcpy ( V_66 + ( V_211 -> V_209 & 3 ) , V_27 , V_211 -> V_210 ) ;
} else {
V_66 = V_27 ;
}
V_187 = F_64 ( V_9 , false ) ;
if ( V_187 )
goto V_216;
for ( V_29 = ( T_1 * ) V_66 ; ! V_187 && V_213 ; V_213 -= 4 , V_29 ++ ) {
V_187 = F_58 ( V_9 , V_212 , * V_29 ) ;
V_212 += 4 ;
}
if ( ! V_187 )
V_187 = F_64 ( V_9 , true ) ;
V_216:
if ( V_66 != V_27 )
F_62 ( V_66 ) ;
return V_187 ;
}
static int F_65 ( struct V_1 * V_217 , struct V_218 * V_219 )
{
int V_220 ;
const struct V_221 * V_222 ;
struct V_9 * V_10 = F_2 ( V_217 ) ;
unsigned int V_223 = V_224 + 1 ;
V_219 -> V_27 [ sizeof( V_219 -> V_27 ) - 1 ] = '\0' ;
V_220 = F_66 ( & V_222 , V_219 -> V_27 , V_10 -> V_225 ) ;
if ( V_220 < 0 )
return V_220 ;
if ( V_10 -> V_182 & V_183 )
V_223 = V_10 -> V_223 ;
V_220 = F_67 ( V_10 , V_223 , V_222 -> V_27 , V_222 -> V_173 , 1 ) ;
F_68 ( V_222 ) ;
if ( ! V_220 )
F_69 ( V_10 -> V_225 ,
L_3 , V_219 -> V_27 ) ;
return V_220 ;
}
static void F_70 ( struct V_1 * V_2 , struct V_226 * V_227 )
{
V_227 -> V_141 = V_228 | V_229 ;
V_227 -> V_230 = F_2 ( V_2 ) -> V_227 ;
memset ( & V_227 -> V_231 , 0 , sizeof( V_227 -> V_231 ) ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_226 * V_227 )
{
int V_187 = 0 ;
struct V_28 * V_55 = F_20 ( V_2 ) ;
if ( V_227 -> V_230 & ~ V_232 )
return - V_72 ;
F_72 ( V_55 -> V_9 , V_55 -> V_58 ,
( V_227 -> V_230 & V_229 ) ? V_2 -> V_233 : NULL ) ;
if ( V_227 -> V_230 & V_228 ) {
V_187 = F_73 ( V_55 -> V_9 , V_55 -> V_58 , 0xfe , ~ 0ULL ,
~ 0ULL , 0 , false ) ;
if ( ! V_187 )
V_187 = F_73 ( V_55 -> V_9 , V_55 -> V_58 , 1 ,
~ 6ULL , ~ 0ULL , V_234 , true ) ;
} else {
F_73 ( V_55 -> V_9 , V_55 -> V_58 , 0 , 0 , 0 , 0 , false ) ;
}
return V_187 ;
}
static T_1 F_74 ( struct V_1 * V_2 )
{
const struct V_28 * V_55 = F_20 ( V_2 ) ;
return V_55 -> V_235 ;
}
static int F_75 ( struct V_1 * V_2 , T_1 * V_29 , T_2 * V_236 , T_2 * V_237 )
{
const struct V_28 * V_55 = F_20 ( V_2 ) ;
unsigned int V_238 = V_55 -> V_235 ;
if ( V_237 )
* V_237 = V_239 ;
if ( ! V_29 )
return 0 ;
while ( V_238 -- )
V_29 [ V_238 ] = V_55 -> V_240 [ V_238 ] ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , const T_1 * V_29 , const T_2 * V_236 ,
const T_2 V_237 )
{
unsigned int V_32 ;
struct V_28 * V_55 = F_20 ( V_2 ) ;
if ( V_236 ||
( V_237 != V_241 && V_237 != V_239 ) )
return - V_8 ;
if ( ! V_29 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_55 -> V_235 ; V_32 ++ )
V_55 -> V_240 [ V_32 ] = V_29 [ V_32 ] ;
if ( V_55 -> V_9 -> V_182 & V_183 )
return F_77 ( V_55 , V_55 -> V_240 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_242 * V_13 ,
T_1 * V_243 )
{
const struct V_28 * V_55 = F_20 ( V_2 ) ;
switch ( V_13 -> V_119 ) {
case V_244 : {
unsigned int V_81 = V_55 -> V_245 ;
V_13 -> V_27 = 0 ;
switch ( V_13 -> V_246 ) {
case V_247 :
if ( V_81 & V_248 )
V_13 -> V_27 = V_249 | V_250 |
V_251 | V_252 ;
else if ( V_81 & V_253 )
V_13 -> V_27 = V_249 | V_250 ;
break;
case V_254 :
if ( ( V_81 & V_248 ) &&
( V_81 & V_255 ) )
V_13 -> V_27 = V_249 | V_250 |
V_251 | V_252 ;
else if ( V_81 & V_253 )
V_13 -> V_27 = V_249 | V_250 ;
break;
case V_256 :
case V_257 :
case V_258 :
if ( V_81 & V_253 )
V_13 -> V_27 = V_249 | V_250 ;
break;
case V_259 :
if ( V_81 & V_260 )
V_13 -> V_27 = V_249 | V_250 |
V_251 | V_252 ;
else if ( V_81 & V_261 )
V_13 -> V_27 = V_249 | V_250 ;
break;
case V_262 :
if ( ( V_81 & V_260 ) &&
( V_81 & V_255 ) )
V_13 -> V_27 = V_249 | V_250 |
V_251 | V_252 ;
else if ( V_81 & V_261 )
V_13 -> V_27 = V_249 | V_250 ;
break;
case V_263 :
case V_264 :
case V_265 :
if ( V_81 & V_261 )
V_13 -> V_27 = V_249 | V_250 ;
break;
}
return 0 ;
}
case V_266 :
V_13 -> V_27 = V_55 -> V_41 ;
return 0 ;
}
return - V_8 ;
}
void F_79 ( struct V_1 * V_217 )
{
V_217 -> V_267 = & V_268 ;
}
