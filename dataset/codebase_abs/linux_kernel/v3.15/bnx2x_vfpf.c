static void F_1 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 , T_1 type , T_1 V_5 )
{
struct V_6 * V_7 =
(struct V_6 * ) ( V_3 + V_4 ) ;
V_7 -> type = type ;
V_7 -> V_5 = V_5 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_1 type , T_1 V_5 )
{
F_3 ( & V_2 -> V_10 ) ;
F_4 ( V_11 , L_1 ,
type ) ;
memset ( V_2 -> V_12 , 0 , sizeof( struct V_13 ) ) ;
F_1 ( V_2 , & V_9 -> V_7 , 0 , type , V_5 ) ;
V_9 -> V_14 = sizeof( V_2 -> V_12 -> V_15 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_4 ( V_11 , L_2 ,
V_9 -> V_7 . type ) ;
F_6 ( & V_2 -> V_10 ) ;
}
static void * F_7 ( struct V_1 * V_2 , void * V_3 ,
enum V_16 V_17 )
{
struct V_6 * V_18 = (struct V_6 * ) V_3 ;
do {
if ( V_18 -> type == V_17 )
return V_18 ;
if ( ! V_18 -> V_5 ) {
F_8 ( L_3 ) ;
return NULL ;
}
V_3 += V_18 -> V_5 ;
V_18 = (struct V_6 * ) V_3 ;
} while ( V_18 -> type != V_19 );
F_4 ( V_11 , L_4 , V_17 ) ;
return NULL ;
}
static void F_9 ( struct V_1 * V_2 , void * V_3 )
{
int V_20 = 1 ;
struct V_6 * V_18 = (struct V_6 * ) V_3 ;
while ( V_18 -> type != V_19 ) {
F_4 ( V_11 , L_5 , V_20 ,
V_18 -> type , V_18 -> V_5 ) ;
V_3 += V_18 -> V_5 ;
V_18 = (struct V_6 * ) V_3 ;
V_20 ++ ;
if ( V_20 > V_21 ) {
F_10 ( true , L_6 ) ;
return;
}
}
F_4 ( V_11 , L_5 , V_20 ,
V_18 -> type , V_18 -> V_5 ) ;
}
bool F_11 ( T_1 V_22 )
{
return V_23 < V_22 && V_22 < V_24 ;
}
static inline int F_12 ( int V_25 )
{
switch ( V_25 ) {
case 0 :
return V_26 ;
case - V_27 :
return V_28 ;
default:
return V_29 ;
}
}
static int F_13 ( struct V_1 * V_2 , T_2 * V_30 , T_3 V_31 )
{
struct V_32 T_4 * V_33 =
F_14 ( V_2 , V_34 ) ;
int V_35 = 100 , V_36 = 100 ;
if ( * V_30 ) {
F_8 ( L_7 ) ;
F_15 ( true ) ;
return - V_37 ;
}
F_16 ( V_2 ) ;
if ( V_2 -> V_38 . V_39 & 1 << V_40 ) {
F_4 ( V_11 , L_8 ) ;
* V_30 = V_26 ;
return - V_37 ;
}
F_17 ( F_18 ( V_31 ) ,
& V_33 -> V_41 . V_42 . V_43 ) ;
F_17 ( F_19 ( V_31 ) ,
& V_33 -> V_41 . V_42 . V_44 ) ;
F_20 () ;
F_21 ( 1 , & V_33 -> V_45 . V_42 . V_46 ) ;
while ( ( V_35 >= 0 ) && ( ! * V_30 ) ) {
F_22 ( V_36 ) ;
V_35 -= 1 ;
F_23 ( V_11 , L_9 ) ;
}
if ( ! * V_30 ) {
F_8 ( L_10 ) ;
return - V_47 ;
}
F_4 ( V_48 , L_11 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_5 * V_49 )
{
T_5 V_50 ;
int V_35 = 10 , V_36 = 100 ;
do {
V_50 = F_25 ( V_2 -> V_51 ) ;
if ( F_26 ( V_50 ) )
break;
F_22 ( V_36 ) ;
F_8 ( L_12 ,
V_50 ) ;
} while ( V_35 -- > 0 );
if ( ! F_26 ( V_50 ) ) {
F_8 ( L_13 , V_50 ) ;
return - V_37 ;
}
F_4 ( V_11 , L_14 , V_50 ) ;
* V_49 = ( V_50 & V_52 ) >> V_53 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , T_2 V_54 , T_2 V_55 )
{
int V_25 = 0 , V_56 = 0 ;
struct V_57 * V_15 = & V_2 -> V_12 -> V_15 . V_58 ;
struct V_59 * V_60 = & V_2 -> V_12 -> V_60 . V_61 ;
struct V_62 * V_63 ;
T_5 V_49 ;
bool V_64 = false ;
F_2 ( V_2 , & V_15 -> V_9 , V_65 , sizeof( * V_15 ) ) ;
if ( F_24 ( V_2 , & V_49 ) ) {
V_25 = - V_47 ;
goto V_66;
}
V_15 -> V_67 . V_49 = V_49 ;
V_15 -> V_67 . V_68 = 0 ;
V_15 -> V_69 . V_70 = V_55 ;
V_15 -> V_69 . V_71 = V_54 ;
V_15 -> V_69 . V_72 = V_2 -> V_73 ;
V_15 -> V_69 . V_74 = V_75 ;
V_15 -> V_69 . V_76 = V_77 ;
V_15 -> V_78 = V_2 -> V_79 ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 ,
V_80 , sizeof( struct V_6 ) ) ;
F_1 ( V_2 , V_15 ,
V_15 -> V_9 . V_7 . V_5 + sizeof( struct V_6 ) ,
V_19 ,
sizeof( struct V_81 ) ) ;
F_9 ( V_2 , V_15 ) ;
while ( ! V_64 ) {
F_4 ( V_48 , L_15 ) ;
V_25 = F_13 ( V_2 ,
& V_60 -> V_82 . V_83 ,
V_2 -> V_84 ) ;
if ( V_25 )
goto V_66;
memcpy ( & V_2 -> V_61 , V_60 , sizeof( V_2 -> V_61 ) ) ;
V_56 ++ ;
if ( V_2 -> V_61 . V_82 . V_83 == V_26 ) {
F_4 ( V_48 , L_16 ) ;
V_64 = true ;
} else if ( V_2 -> V_61 . V_82 . V_83 ==
V_28 &&
V_56 < V_85 ) {
F_4 ( V_48 ,
L_17 ) ;
V_15 -> V_69 . V_71 =
F_28 ( V_15 -> V_69 . V_71 ,
V_2 -> V_61 . V_86 . V_71 ) ;
V_15 -> V_69 . V_70 =
F_28 ( V_15 -> V_69 . V_70 ,
V_2 -> V_61 . V_86 . V_70 ) ;
V_15 -> V_69 . V_72 =
F_28 ( V_15 -> V_69 . V_72 ,
V_2 -> V_61 . V_86 . V_72 ) ;
V_15 -> V_69 . V_74 =
F_28 ( V_15 -> V_69 . V_74 ,
V_2 -> V_61 . V_86 . V_74 ) ;
V_15 -> V_69 . V_87 =
F_28 ( V_15 -> V_69 . V_87 ,
V_2 -> V_61 . V_86 . V_87 ) ;
V_15 -> V_69 . V_76 =
F_28 ( V_15 -> V_69 . V_76 ,
V_2 -> V_61 . V_86 . V_76 ) ;
memset ( & V_2 -> V_12 -> V_60 , 0 ,
sizeof( union V_88 ) ) ;
} else {
F_8 ( L_18 ,
V_2 -> V_61 . V_82 . V_83 ) ;
V_25 = - V_47 ;
goto V_66;
}
}
V_63 = (struct V_62 * )
F_7 ( V_2 , V_60 ,
V_80 ) ;
if ( V_63 ) {
memcpy ( V_2 -> V_89 , V_63 -> V_90 , V_91 ) ;
V_2 -> V_92 |= V_93 ;
}
V_2 -> V_94 . V_95 |= ( V_2 -> V_61 . V_96 . V_97 & 0xffff ) ;
V_2 -> V_98 . V_95 = V_2 -> V_94 . V_95 ;
V_2 -> V_99 = V_2 -> V_61 . V_96 . V_99 ;
V_2 -> V_94 . V_100 = V_101 ;
V_2 -> V_94 . V_102 = V_103 ;
V_2 -> V_104 = - 1 ;
V_2 -> V_105 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_94 . V_107 = 0 ;
V_2 -> V_92 |=
V_108 | V_109 | V_110 | V_111 ;
V_2 -> V_73 = V_2 -> V_61 . V_86 . V_72 ;
V_2 -> V_112 = V_2 -> V_61 . V_86 . V_113 [ 0 ] . V_114 ;
F_29 ( V_2 -> V_115 , V_2 -> V_61 . V_96 . V_115 ,
sizeof( V_2 -> V_115 ) ) ;
if ( F_30 ( V_2 -> V_61 . V_86 . V_116 ) )
memcpy ( V_2 -> V_117 -> V_118 ,
V_2 -> V_61 . V_86 . V_116 ,
V_91 ) ;
V_66:
F_5 ( V_2 , & V_15 -> V_9 ) ;
return V_25 ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_119 * V_15 = & V_2 -> V_12 -> V_15 . V_120 ;
struct V_121 * V_60 = & V_2 -> V_12 -> V_60 . V_122 ;
T_5 V_25 , V_49 ;
F_2 ( V_2 , & V_15 -> V_9 , V_123 , sizeof( * V_15 ) ) ;
if ( F_24 ( V_2 , & V_49 ) ) {
V_25 = - V_47 ;
goto V_66;
}
V_15 -> V_49 = V_49 ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
F_9 ( V_2 , V_15 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 , V_2 -> V_84 ) ;
if ( V_25 )
goto V_66;
if ( V_60 -> V_82 . V_83 == V_26 ) {
F_4 ( V_48 , L_19 ) ;
} else {
F_8 ( L_20 ,
V_60 -> V_82 . V_83 ) ;
V_25 = - V_47 ;
goto V_66;
}
V_66:
F_5 ( V_2 , & V_15 -> V_9 ) ;
return V_25 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_124 * V_15 = & V_2 -> V_12 -> V_15 . V_125 ;
struct V_121 * V_60 = & V_2 -> V_12 -> V_60 . V_122 ;
int V_25 , V_20 ;
F_2 ( V_2 , & V_15 -> V_9 , V_126 , sizeof( * V_15 ) ) ;
F_33 (bp, i)
V_15 -> V_127 [ V_20 ] = ( T_3 ) F_34 ( V_2 , V_20 ,
V_128 ) ;
V_15 -> V_129 = V_2 -> V_130 +
F_35 ( struct V_131 , V_132 ) ;
V_15 -> V_133 = sizeof( struct V_134 ) ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
F_9 ( V_2 , V_15 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 , V_2 -> V_84 ) ;
if ( V_25 )
goto V_66;
if ( V_60 -> V_82 . V_83 != V_26 ) {
F_8 ( L_21 ,
V_60 -> V_82 . V_83 ) ;
V_25 = - V_47 ;
goto V_66;
}
F_4 ( V_48 , L_22 ) ;
V_66:
F_5 ( V_2 , & V_15 -> V_9 ) ;
return V_25 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_135 * V_15 = & V_2 -> V_12 -> V_15 . V_136 ;
struct V_121 * V_60 = & V_2 -> V_12 -> V_60 . V_122 ;
int V_20 , V_25 ;
T_5 V_49 ;
if ( F_24 ( V_2 , & V_49 ) )
goto V_137;
F_37 (bp, i)
F_38 ( V_2 , V_20 ) ;
F_39 ( V_2 , V_2 -> V_117 -> V_118 , V_2 -> V_138 -> V_139 , false ) ;
F_2 ( V_2 , & V_15 -> V_9 , V_140 , sizeof( * V_15 ) ) ;
V_15 -> V_49 = V_49 ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
F_9 ( V_2 , V_15 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 , V_2 -> V_84 ) ;
if ( V_25 )
F_8 ( L_23 , V_25 ) ;
else if ( V_60 -> V_82 . V_83 != V_26 )
F_8 ( L_24 ,
V_60 -> V_82 . V_83 ) ;
F_5 ( V_2 , & V_15 -> V_9 ) ;
V_137:
F_40 ( V_2 , 0 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_143 * V_144 )
{
T_2 V_145 = F_44 ( V_142 , V_144 ) ;
T_2 V_146 = F_45 ( V_142 -> V_147 ) ;
F_46 ( V_2 , & V_144 -> V_148 ,
V_145 , V_144 -> V_149 , V_146 ,
F_47 ( V_2 , V_142 , V_150 ) ,
F_48 ( V_2 , V_142 , V_150 ) ,
V_151 ,
& V_142 -> V_152 ,
V_153 ,
& V_2 -> V_154 ) ;
F_49 ( V_2 , & V_144 -> V_155 ,
V_145 , V_144 -> V_149 , V_146 ,
F_47 ( V_2 , V_142 , V_156 ) ,
F_48 ( V_2 , V_142 , V_156 ) ,
V_157 ,
& V_142 -> V_152 ,
V_153 ,
& V_2 -> V_158 ) ;
F_50 ( V_2 , & V_142 -> V_159 , V_145 ,
V_144 -> V_149 , V_146 , V_146 ,
F_47 ( V_2 , V_142 , V_160 ) ,
F_48 ( V_2 , V_142 , V_160 ) ,
V_161 ,
& V_142 -> V_152 ,
V_153 ) ;
F_51 ( V_2 , & V_142 -> V_162 , V_145 , V_144 -> V_149 ,
V_146 , V_146 ,
F_47 ( V_2 , V_142 , V_163 ) ,
F_48 ( V_2 , V_142 , V_163 ) ,
V_164 ,
& V_142 -> V_152 ,
V_153 ) ;
V_142 -> V_165 = V_145 ;
V_144 -> V_166 = true ;
V_144 -> V_167 = true ;
}
int F_52 ( struct V_1 * V_2 , struct V_168 * V_138 ,
bool V_166 )
{
struct V_169 * V_15 = & V_2 -> V_12 -> V_15 . V_170 ;
struct V_121 * V_60 = & V_2 -> V_12 -> V_60 . V_122 ;
T_2 V_171 = V_138 -> V_139 ;
T_1 V_172 = 0 , V_92 = 0 ;
int V_25 ;
F_2 ( V_2 , & V_15 -> V_9 , V_173 , sizeof( * V_15 ) ) ;
if ( ! V_138 -> V_174 ) {
V_92 |= V_175 ;
V_92 |= V_176 ;
if ( V_138 -> V_177 == V_178 )
V_92 |= V_179 ;
V_172 = V_180 ;
}
if ( V_166 )
V_92 |= V_181 ;
V_92 |= V_182 ;
V_92 |= V_183 ;
V_92 |= V_184 ;
F_4 ( V_185 , L_25 ) ;
V_15 -> V_186 = V_171 ;
V_15 -> V_187 = V_188 | V_189 ;
V_15 -> V_190 . V_191 = V_138 -> V_192 ;
V_15 -> V_190 . V_193 = V_138 -> V_192 + V_194 ;
V_15 -> V_190 . V_195 = V_138 -> V_196 ;
V_15 -> V_190 . V_197 = V_138 -> V_198 ;
V_15 -> V_190 . V_199 = V_171 ;
V_15 -> V_190 . V_200 = V_201 ;
V_15 -> V_190 . V_202 = V_2 -> V_203 ? 1000000 / V_2 -> V_203 : 0 ;
V_15 -> V_190 . V_204 = V_2 -> V_117 -> V_204 ;
V_15 -> V_190 . V_205 = V_138 -> V_206 ;
V_15 -> V_190 . V_207 = V_194 * V_208 ;
V_15 -> V_190 . V_209 = V_172 ;
V_15 -> V_190 . V_210 = F_53 ( V_2 -> V_117 -> V_204 ) >> V_211 ;
V_15 -> V_190 . V_210 = ( ( V_15 -> V_190 . V_210 + V_208 - 1 ) &
( ~ ( V_208 - 1 ) ) ) >> V_212 ;
V_15 -> V_190 . V_92 = V_92 ;
V_15 -> V_190 . V_213 = 0 ;
V_15 -> V_190 . V_214 = V_215 ;
V_15 -> V_190 . V_216 = - 1 ;
V_15 -> V_217 . V_218 = V_138 -> V_219 [ V_220 ] -> V_221 ;
V_15 -> V_217 . V_199 = V_171 ;
V_15 -> V_217 . V_200 = V_222 ;
V_15 -> V_217 . V_202 = V_2 -> V_223 ? 1000000 / V_2 -> V_223 : 0 ;
V_15 -> V_217 . V_92 = V_92 ;
V_15 -> V_217 . V_224 = V_225 ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
F_9 ( V_2 , V_15 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 , V_2 -> V_84 ) ;
if ( V_25 )
F_8 ( L_26 ,
V_171 ) ;
if ( V_60 -> V_82 . V_83 != V_26 ) {
F_8 ( L_27 ,
V_171 , V_60 -> V_82 . V_83 ) ;
V_25 = - V_37 ;
}
F_5 ( V_2 , & V_15 -> V_9 ) ;
return V_25 ;
}
static int F_38 ( struct V_1 * V_2 , int V_226 )
{
struct V_227 * V_15 = & V_2 -> V_12 -> V_15 . V_228 ;
struct V_121 * V_60 = & V_2 -> V_12 -> V_60 . V_122 ;
int V_25 ;
F_2 ( V_2 , & V_15 -> V_9 , V_229 ,
sizeof( * V_15 ) ) ;
V_15 -> V_186 = V_226 ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
F_9 ( V_2 , V_15 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 , V_2 -> V_84 ) ;
if ( V_25 ) {
F_8 ( L_28 , V_226 ,
V_25 ) ;
goto V_66;
}
if ( V_60 -> V_82 . V_83 != V_26 ) {
F_8 ( L_29 , V_226 ,
V_60 -> V_82 . V_83 ) ;
V_25 = - V_37 ;
}
V_66:
F_5 ( V_2 , & V_15 -> V_9 ) ;
return V_25 ;
}
int F_39 ( struct V_1 * V_2 , T_2 * V_230 , T_2 V_186 , bool V_231 )
{
struct V_232 * V_15 = & V_2 -> V_12 -> V_15 . V_233 ;
struct V_121 * V_60 = & V_2 -> V_12 -> V_60 . V_122 ;
struct V_234 V_235 = V_2 -> V_236 -> V_237 ;
int V_25 = 0 ;
F_2 ( V_2 , & V_15 -> V_9 , V_238 ,
sizeof( * V_15 ) ) ;
V_15 -> V_92 = V_239 ;
V_15 -> V_186 = V_186 ;
V_15 -> V_240 = 1 ;
V_15 -> V_241 [ 0 ] . V_92 = V_242 ;
if ( V_231 )
V_15 -> V_241 [ 0 ] . V_92 |= V_243 ;
F_16 ( V_2 ) ;
memcpy ( V_15 -> V_241 [ 0 ] . V_244 , V_230 , V_91 ) ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
F_9 ( V_2 , V_15 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 , V_2 -> V_84 ) ;
if ( V_25 ) {
F_8 ( L_30 , V_25 ) ;
goto V_66;
}
while ( V_60 -> V_82 . V_83 == V_29 ) {
F_4 ( V_11 ,
L_31 ) ;
memcpy ( V_2 -> V_117 -> V_118 , V_235 . V_244 , V_91 ) ;
if ( F_16 ( V_2 ) == V_245 ) {
memcpy ( V_15 -> V_241 [ 0 ] . V_244 , V_2 -> V_117 -> V_118 ,
V_91 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 ,
V_2 -> V_84 ) ;
} else {
break;
}
}
if ( V_60 -> V_82 . V_83 != V_26 ) {
F_8 ( L_32 , V_60 -> V_82 . V_83 ) ;
V_25 = - V_37 ;
}
V_66:
F_5 ( V_2 , & V_15 -> V_9 ) ;
return V_25 ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_246 * V_247 )
{
struct V_121 * V_60 = & V_2 -> V_12 -> V_60 . V_122 ;
struct V_248 * V_15 = & V_2 -> V_12 -> V_15 . V_249 ;
int V_25 = 0 ;
F_2 ( V_2 , & V_15 -> V_9 , V_250 ,
sizeof( * V_15 ) ) ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
memcpy ( V_15 -> V_251 , V_247 -> V_251 , V_252 ) ;
memcpy ( V_15 -> V_253 , V_247 -> V_253 , sizeof( V_247 -> V_253 ) ) ;
V_15 -> V_254 = V_252 ;
V_15 -> V_255 = V_256 ;
V_15 -> V_257 = V_247 -> V_257 ;
if ( V_247 -> V_258 & ( 1 << V_259 ) )
V_15 -> V_258 |= V_260 ;
if ( V_247 -> V_258 & ( 1 << V_261 ) )
V_15 -> V_258 |= V_262 ;
if ( V_247 -> V_258 & ( 1 << V_263 ) )
V_15 -> V_258 |= V_264 ;
if ( V_247 -> V_258 & ( 1 << V_265 ) )
V_15 -> V_258 |= V_266 ;
if ( V_247 -> V_258 & ( 1 << V_267 ) )
V_15 -> V_258 |= V_268 ;
if ( V_247 -> V_258 & ( 1 << V_269 ) )
V_15 -> V_258 |= V_270 ;
if ( V_247 -> V_258 & ( 1 << V_271 ) )
V_15 -> V_258 |= V_272 ;
if ( V_247 -> V_258 & ( 1 << V_273 ) )
V_15 -> V_258 |= V_274 ;
if ( V_247 -> V_258 & ( 1 << V_275 ) )
V_15 -> V_258 |= V_276 ;
F_4 ( V_11 , L_33 , V_15 -> V_258 ) ;
F_9 ( V_2 , V_15 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 , V_2 -> V_84 ) ;
if ( V_25 ) {
F_8 ( L_30 , V_25 ) ;
goto V_66;
}
if ( V_60 -> V_82 . V_83 != V_26 ) {
F_4 ( V_11 ,
L_34 ,
V_60 -> V_82 . V_83 ) ;
}
V_66:
F_5 ( V_2 , & V_15 -> V_9 ) ;
return V_25 ;
}
int F_55 ( struct V_277 * V_117 )
{
struct V_1 * V_2 = F_56 ( V_117 ) ;
struct V_232 * V_15 = & V_2 -> V_12 -> V_15 . V_233 ;
struct V_121 * V_60 = & V_2 -> V_12 -> V_60 . V_122 ;
int V_25 , V_20 = 0 ;
struct V_278 * V_279 ;
if ( V_2 -> V_280 != V_281 ) {
F_4 ( V_185 , L_35 , V_2 -> V_280 ) ;
return - V_37 ;
}
F_2 ( V_2 , & V_15 -> V_9 , V_238 ,
sizeof( * V_15 ) ) ;
F_4 ( V_185 , L_36 , V_117 -> V_92 ) ;
F_57 (ha, dev) {
F_4 ( V_185 , L_37 ,
F_58 ( V_279 ) ) ;
memcpy ( V_15 -> V_282 [ V_20 ] , F_58 ( V_279 ) , V_91 ) ;
V_20 ++ ;
}
if ( V_20 >= V_283 ) {
F_4 ( V_185 ,
L_38 ,
V_283 ) ;
return - V_37 ;
}
V_15 -> V_284 = V_20 ;
V_15 -> V_92 |= V_285 ;
V_15 -> V_186 = 0 ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
F_9 ( V_2 , V_15 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 , V_2 -> V_84 ) ;
if ( V_25 ) {
F_8 ( L_39 , V_25 ) ;
goto V_66;
}
if ( V_60 -> V_82 . V_83 != V_26 ) {
F_8 ( L_40 ,
V_60 -> V_82 . V_83 ) ;
V_25 = - V_37 ;
}
V_66:
F_5 ( V_2 , & V_15 -> V_9 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_177 = V_2 -> V_286 ;
struct V_232 * V_15 = & V_2 -> V_12 -> V_15 . V_233 ;
struct V_121 * V_60 = & V_2 -> V_12 -> V_60 . V_122 ;
int V_25 ;
F_2 ( V_2 , & V_15 -> V_9 , V_238 ,
sizeof( * V_15 ) ) ;
F_4 ( V_185 , L_41 , V_177 ) ;
if ( V_177 == V_287 ) {
V_15 -> V_288 = V_289 ;
} else {
V_15 -> V_288 = V_290 ;
V_15 -> V_288 |= V_291 ;
V_15 -> V_288 |= V_292 ;
}
V_15 -> V_92 |= V_293 ;
V_15 -> V_186 = 0 ;
F_1 ( V_2 , V_15 , V_15 -> V_9 . V_7 . V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
F_9 ( V_2 , V_15 ) ;
V_25 = F_13 ( V_2 , & V_60 -> V_82 . V_83 , V_2 -> V_84 ) ;
if ( V_25 )
F_8 ( L_39 , V_25 ) ;
if ( V_60 -> V_82 . V_83 != V_26 ) {
F_8 ( L_42 , V_60 -> V_82 . V_83 ) ;
V_25 = - V_37 ;
}
F_5 ( V_2 , & V_15 -> V_9 ) ;
return V_25 ;
}
static void F_60 ( struct V_1 * V_2 , T_1 V_294 )
{
T_5 V_230 = V_295 +
F_61 ( V_294 ) ;
F_62 ( V_2 , V_230 , V_296 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_1 V_294 )
{
T_5 V_230 = V_295 +
F_64 ( V_294 ) ;
F_62 ( V_2 , V_230 , 1 ) ;
}
static inline void F_65 ( struct V_1 * V_2 )
{
int V_20 ;
F_66 (bp, i)
F_63 ( V_2 , F_67 ( V_2 , V_20 , V_147 ) ) ;
}
void F_68 ( struct V_1 * V_2 , T_2 V_147 )
{
F_69 ( V_2 , V_147 ) ;
F_60 ( V_2 , V_147 ) ;
F_63 ( V_2 , V_147 ) ;
F_70 ( V_2 , V_147 ) ;
}
static int F_71 ( struct V_1 * V_2 , T_2 V_297 ,
T_3 V_298 , T_2 V_299 , T_5 V_300 ,
T_5 V_301 , T_5 V_302 )
{
struct V_303 V_304 ;
if ( F_72 ( V_2 ) ) {
F_8 ( L_43 ) ;
return V_305 ;
}
if ( ! V_2 -> V_306 ) {
F_8 ( L_44 ) ;
return V_305 ;
}
F_73 ( V_2 , & V_304 , V_307 , V_308 ) ;
if ( V_297 ) {
V_304 . V_309 = ( V_299 << V_310 ) |
( V_311 << V_312 ) |
( V_313 << V_314 ) ;
V_304 . V_315 |= ( V_316 << V_317 ) ;
V_304 . V_318 = V_301 ;
V_304 . V_319 = V_300 ;
V_304 . V_320 = F_18 ( V_298 ) ;
V_304 . V_321 = F_19 ( V_298 ) ;
} else {
V_304 . V_309 = ( V_299 << V_322 ) |
( V_323 << V_314 ) |
( V_324 << V_312 ) ;
V_304 . V_315 |= ( V_325 << V_317 ) ;
V_304 . V_318 = F_18 ( V_298 ) ;
V_304 . V_319 = F_19 ( V_298 ) ;
V_304 . V_320 = V_301 ;
V_304 . V_321 = V_300 ;
}
V_304 . V_326 = V_302 ;
return F_74 ( V_2 , & V_304 , F_75 ( V_2 , V_327 ) ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_328 * V_329 = F_77 ( V_2 , V_142 -> V_139 ) ;
T_1 V_5 , type ;
type = V_329 -> V_9 . V_7 . type ;
V_5 = type == V_65 ?
sizeof( struct V_59 ) :
sizeof( struct V_121 ) ;
F_1 ( V_2 , & V_329 -> V_330 -> V_60 , 0 , type , V_5 ) ;
F_1 ( V_2 , & V_329 -> V_330 -> V_60 , V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
int V_331 )
{
struct V_328 * V_329 = F_77 ( V_2 , V_142 -> V_139 ) ;
struct V_121 * V_60 = & V_329 -> V_330 -> V_60 . V_122 ;
T_3 V_298 ;
T_6 V_332 ;
int V_25 ;
F_9 ( V_2 , V_60 ) ;
F_4 ( V_11 , L_45 ,
V_329 -> V_300 , V_329 -> V_301 , V_329 -> V_9 . V_14 ) ;
V_60 -> V_82 . V_83 = F_12 ( V_331 ) ;
V_332 = F_79 ( V_329 -> V_300 , V_329 -> V_301 ) +
V_329 -> V_9 . V_14 ;
V_298 = V_329 -> V_31 +
F_35 ( struct V_13 , V_60 ) ;
V_332 += sizeof( T_6 ) ;
V_298 += sizeof( T_6 ) ;
V_25 = F_71 ( V_2 , false , V_298 , V_142 -> V_147 ,
F_19 ( V_332 ) ,
F_18 ( V_332 ) ,
( sizeof( union V_88 ) - sizeof( T_6 ) ) / 4 ) ;
if ( V_25 ) {
F_8 ( L_46 ,
V_142 -> V_147 ) ;
goto V_333;
}
V_332 -= sizeof( T_6 ) ;
V_298 -= sizeof( T_6 ) ;
F_60 ( V_2 , V_142 -> V_147 ) ;
F_80 () ;
V_25 = F_71 ( V_2 , false , V_298 , V_142 -> V_147 ,
F_19 ( V_332 ) ,
F_18 ( V_332 ) ,
sizeof( T_6 ) / 4 ) ;
F_81 ( V_2 , V_142 , V_329 -> V_9 . V_7 . type ) ;
if ( V_25 ) {
F_8 ( L_47 ,
V_142 -> V_147 ) ;
goto V_333;
}
return;
V_333:
F_82 ( V_2 , V_142 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
int V_25 )
{
F_76 ( V_2 , V_142 ) ;
F_78 ( V_2 , V_142 , V_25 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
void * V_334 ,
T_1 * V_4 )
{
struct V_62 * V_335 ;
if ( ! ( V_2 -> V_92 & V_93 ) )
return;
F_1 ( V_2 , V_334 , * V_4 , V_80 ,
sizeof( struct V_62 ) ) ;
V_335 = (struct V_62 * )
( ( ( T_2 * ) V_334 ) + * V_4 ) ;
memcpy ( V_335 -> V_90 , V_2 -> V_89 , V_91 ) ;
* V_4 += sizeof( struct V_62 ) ;
}
static void F_85 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 , int V_336 )
{
int V_20 ;
struct V_59 * V_60 = & V_329 -> V_330 -> V_60 . V_61 ;
struct V_337 * V_86 = & V_60 -> V_86 ;
T_2 V_83 = F_12 ( V_336 ) ;
T_1 V_5 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_96 . V_97 = V_2 -> V_94 . V_95 ;
V_60 -> V_96 . V_99 = V_2 -> V_99 ;
V_60 -> V_96 . V_338 = V_339 ;
V_60 -> V_96 . V_340 = ( V_341 |
V_342 |
V_343 ) ;
F_86 ( V_2 , V_60 -> V_96 . V_115 ,
sizeof( V_60 -> V_96 . V_115 ) ) ;
if ( V_83 == V_28 ||
V_83 == V_26 ) {
V_86 -> V_70 = F_87 ( V_142 ) ? :
F_88 ( V_2 , V_142 ) ;
V_86 -> V_71 = F_89 ( V_142 ) ? :
F_88 ( V_2 , V_142 ) ;
V_86 -> V_72 = F_90 ( V_142 ) ;
V_86 -> V_74 = F_91 ( V_142 ) ;
V_86 -> V_87 = F_92 ( V_142 ) ;
V_86 -> V_76 = 0 ;
if ( V_83 == V_26 ) {
struct V_234 * V_235 =
F_93 ( V_2 , V_142 -> V_139 ) ;
F_94 (vf, i)
V_86 -> V_344 [ V_20 ] =
F_95 ( V_142 , F_96 ( V_142 , V_20 ) ) ;
F_97 (vf, i) {
V_86 -> V_113 [ V_20 ] . V_114 = F_98 ( V_142 , V_20 ) ;
V_86 -> V_113 [ V_20 ] . V_345 = F_99 ( V_142 , V_20 ) ;
}
if ( V_235 -> V_39 & 1 << V_346 ) {
memcpy ( V_86 -> V_116 , V_235 -> V_244 ,
V_91 ) ;
}
}
}
F_4 ( V_11 , L_48
L_49 ,
V_142 -> V_147 ,
V_60 -> V_96 . V_97 ,
V_60 -> V_96 . V_99 ,
V_60 -> V_96 . V_338 ,
V_60 -> V_96 . V_340 ,
V_86 -> V_70 ,
V_86 -> V_71 ,
V_86 -> V_72 ,
V_86 -> V_74 ,
V_86 -> V_87 ,
V_86 -> V_76 ,
V_60 -> V_96 . V_115 ) ;
F_23 ( V_11 , L_50 ) ;
for ( V_20 = 0 ; V_20 < F_87 ( V_142 ) ; V_20 ++ )
F_23 ( V_11 , L_51 , V_86 -> V_344 [ V_20 ] ) ;
F_23 ( V_11 , L_52 ) ;
for ( V_20 = 0 ; V_20 < F_90 ( V_142 ) ; V_20 ++ )
F_23 ( V_11 , L_53 ,
V_86 -> V_113 [ V_20 ] . V_114 ,
V_86 -> V_113 [ V_20 ] . V_345 ) ;
F_23 ( V_11 , L_54 ) ;
V_5 = sizeof( struct V_59 ) ;
F_1 ( V_2 , & V_329 -> V_330 -> V_60 , 0 , V_65 , V_5 ) ;
if ( F_7 ( V_2 , & V_329 -> V_330 -> V_15 ,
V_80 ) )
F_84 ( V_2 , V_142 , & V_329 -> V_330 -> V_60 , & V_5 ) ;
F_1 ( V_2 , & V_329 -> V_330 -> V_60 , V_5 , V_19 ,
sizeof( struct V_81 ) ) ;
F_78 ( V_2 , V_142 , V_336 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 )
{
int V_25 ;
struct V_57 * V_58 = & V_329 -> V_330 -> V_15 . V_58 ;
F_4 ( V_11 ,
L_55 ,
V_142 -> V_147 , V_58 -> V_67 . V_49 , V_58 -> V_67 . V_68 ,
V_58 -> V_69 . V_70 , V_58 -> V_69 . V_71 ,
V_58 -> V_69 . V_72 , V_58 -> V_69 . V_74 ,
V_58 -> V_69 . V_87 ,
V_58 -> V_69 . V_76 ) ;
V_25 = F_101 ( V_2 , V_142 , & V_58 -> V_69 ) ;
V_142 -> V_347 = V_58 -> V_78 ;
F_85 ( V_2 , V_142 , V_329 , V_25 ) ;
}
static void F_102 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 )
{
struct V_124 * V_125 = & V_329 -> V_330 -> V_15 . V_125 ;
int V_25 ;
V_142 -> V_348 = V_125 -> V_349 ;
V_142 -> V_350 = V_125 -> V_129 ;
V_142 -> V_133 = V_125 -> V_133 ;
V_25 = F_103 ( V_2 , V_142 , ( T_3 * ) V_125 -> V_127 ) ;
if ( V_125 -> V_92 & V_351 )
V_142 -> V_352 |= V_353 ;
F_83 ( V_2 , V_142 , V_25 ) ;
}
static void F_104 ( struct V_1 * V_2 , T_5 V_354 ,
unsigned long * V_355 )
{
if ( V_354 & V_175 )
F_105 ( V_356 , V_355 ) ;
if ( V_354 & V_176 )
F_105 ( V_357 , V_355 ) ;
if ( V_354 & V_179 )
F_105 ( V_358 , V_355 ) ;
if ( V_354 & V_182 )
F_105 ( V_359 , V_355 ) ;
if ( V_354 & V_184 )
F_105 ( V_360 , V_355 ) ;
if ( V_354 & V_361 )
F_105 ( V_362 , V_355 ) ;
if ( V_354 & V_363 )
F_105 ( V_364 , V_355 ) ;
if ( V_354 & V_365 )
F_105 ( V_366 , V_355 ) ;
if ( V_354 & V_181 )
F_105 ( V_367 , V_355 ) ;
if ( F_106 ( V_2 ) )
F_105 ( V_368 , V_355 ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 )
{
struct V_169 * V_170 = & V_329 -> V_330 -> V_15 . V_170 ;
struct V_369 V_370 ;
int V_25 = 0 ;
if ( V_170 -> V_186 >= F_87 ( V_142 ) ) {
F_8 ( L_56 ,
V_170 -> V_186 , F_87 ( V_142 ) ) ;
V_25 = - V_37 ;
goto V_371;
}
if ( V_170 -> V_187 & ( V_188 | V_189 ) ) {
struct V_143 * V_144 = F_96 ( V_142 , V_170 -> V_186 ) ;
unsigned long V_372 = 0 ;
struct V_373 * V_374 ;
struct V_375 * V_376 ;
if ( F_108 ( V_144 ) )
F_43 ( V_2 , V_142 , V_144 ) ;
memset ( & V_370 , 0 ,
sizeof( struct V_369 ) ) ;
V_376 = & V_370 . V_377 ;
V_374 = & V_370 . V_378 . V_247 . V_125 ;
F_105 ( V_379 , & V_376 -> V_92 ) ;
if ( V_170 -> V_187 & V_189 ) {
struct V_380 * V_381 =
& V_376 -> V_381 ;
F_105 ( V_382 , & V_372 ) ;
V_144 -> V_383 = V_170 -> V_217 . V_199 ;
V_374 -> V_384 . V_202 = V_170 -> V_217 . V_202 ;
V_374 -> V_384 . V_385 = V_170 -> V_217 . V_200 ;
F_104 ( V_2 , V_170 -> V_217 . V_92 ,
& V_374 -> V_384 . V_92 ) ;
F_104 ( V_2 , V_170 -> V_217 . V_92 ,
& V_376 -> V_92 ) ;
V_381 -> V_386 = V_170 -> V_217 . V_218 ;
V_381 -> V_385 = V_170 -> V_217 . V_200 ;
V_381 -> V_224 = V_170 -> V_217 . V_224 ;
F_109 ( V_2 , V_142 , V_374 , V_376 ,
V_144 -> V_139 , V_144 -> V_383 ) ;
}
if ( V_170 -> V_187 & V_188 ) {
struct V_387 * V_388 =
& V_376 -> V_388 ;
F_105 ( V_389 , & V_372 ) ;
V_144 -> V_383 = V_170 -> V_190 . V_199 ;
V_374 -> V_390 . V_202 = V_170 -> V_190 . V_202 ;
V_374 -> V_390 . V_385 = V_170 -> V_190 . V_200 ;
F_104 ( V_2 , V_170 -> V_190 . V_92 ,
& V_374 -> V_390 . V_92 ) ;
F_104 ( V_2 , V_170 -> V_190 . V_92 ,
& V_376 -> V_92 ) ;
V_376 -> V_391 . V_204 = V_170 -> V_190 . V_204 ;
V_388 -> V_213 = V_170 -> V_190 . V_213 ;
V_388 -> V_386 = V_170 -> V_190 . V_195 ;
V_388 -> V_392 = V_170 -> V_190 . V_197 ;
V_388 -> V_393 = V_170 -> V_190 . V_191 ;
V_388 -> V_394 = V_170 -> V_190 . V_193 ;
V_388 -> V_205 = V_170 -> V_190 . V_205 ;
V_388 -> V_209 = V_170 -> V_190 . V_209 ;
V_388 -> V_395 = V_170 -> V_190 . V_210 ;
V_388 -> V_207 = V_170 -> V_190 . V_207 ;
V_388 -> V_214 =
V_170 -> V_190 . V_214 ;
V_388 -> V_385 = V_170 -> V_190 . V_200 ;
if ( F_108 ( V_144 ) ) {
T_2 V_396 = F_45 ( V_142 -> V_147 ) ;
V_388 -> V_397 = V_396 ;
F_105 ( V_398 , & V_376 -> V_92 ) ;
}
F_110 ( V_2 , V_142 , V_374 , V_376 ,
V_144 -> V_139 , V_144 -> V_383 ) ;
}
F_111 ( V_2 , V_142 , V_144 , & V_370 , V_372 ) ;
V_25 = F_112 ( V_2 , V_142 , V_144 -> V_139 , & V_370 ) ;
if ( V_25 )
goto V_371;
}
V_371:
F_83 ( V_2 , V_142 , V_25 ) ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
struct V_232 * V_18 ,
struct V_399 * * V_400 ,
T_5 V_401 )
{
int V_20 , V_402 ;
struct V_399 * V_403 = NULL ;
T_7 V_404 ;
V_404 = V_18 -> V_240 *
sizeof( struct V_405 ) +
sizeof( struct V_399 ) ;
V_403 = F_114 ( V_404 , V_406 ) ;
if ( ! V_403 )
return - V_27 ;
for ( V_20 = 0 , V_402 = 0 ; V_20 < V_18 -> V_240 ; V_20 ++ ) {
struct V_407 * V_408 = & V_18 -> V_241 [ V_20 ] ;
if ( ( V_408 -> V_92 & V_401 ) != V_401 )
continue;
if ( V_401 == V_242 ) {
V_403 -> V_241 [ V_402 ] . V_244 = V_408 -> V_244 ;
V_403 -> V_241 [ V_402 ] . type = V_409 ;
} else {
V_403 -> V_241 [ V_402 ] . V_410 = V_408 -> V_411 ;
V_403 -> V_241 [ V_402 ] . type = V_412 ;
}
V_403 -> V_241 [ V_402 ] . V_413 =
( V_408 -> V_92 & V_243 ) ?
true : false ;
V_403 -> V_414 ++ ;
}
if ( ! V_403 -> V_414 )
F_115 ( V_403 ) ;
else
* V_400 = V_403 ;
return 0 ;
}
static void F_116 ( struct V_1 * V_2 , int V_415 , int V_416 ,
struct V_407 * V_417 )
{
F_4 ( V_415 , L_57 , V_416 , V_417 -> V_92 ) ;
if ( V_417 -> V_92 & V_418 )
F_23 ( V_415 , L_58 , V_417 -> V_411 ) ;
if ( V_417 -> V_92 & V_242 )
F_23 ( V_415 , L_59 , V_417 -> V_244 ) ;
F_23 ( V_415 , L_60 ) ;
}
static void F_117 ( struct V_1 * V_2 , int V_415 ,
struct V_232 * V_241 )
{
int V_20 ;
if ( V_241 -> V_92 & V_239 )
for ( V_20 = 0 ; V_20 < V_241 -> V_240 ; V_20 ++ )
F_116 ( V_2 , V_415 , V_20 ,
& V_241 -> V_241 [ V_20 ] ) ;
if ( V_241 -> V_92 & V_293 )
F_4 ( V_415 , L_61 , V_241 -> V_288 ) ;
if ( V_241 -> V_92 & V_285 )
for ( V_20 = 0 ; V_20 < V_241 -> V_284 ; V_20 ++ )
F_4 ( V_415 , L_62 , V_241 -> V_282 [ V_20 ] ) ;
}
static int F_118 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
int V_25 = 0 ;
struct V_232 * V_330 =
& F_77 ( V_2 , V_142 -> V_139 ) -> V_330 -> V_15 . V_233 ;
if ( V_330 -> V_92 & V_239 ) {
struct V_399 * V_403 = NULL ;
V_25 = F_113 ( V_2 , V_142 , V_330 , & V_403 ,
V_419 ) ;
if ( V_25 )
goto V_420;
if ( V_403 ) {
V_25 = F_119 ( V_2 , V_142 , V_403 ,
V_330 -> V_186 ,
false ) ;
if ( V_25 )
goto V_420;
}
V_403 = NULL ;
V_25 = F_113 ( V_2 , V_142 , V_330 , & V_403 ,
V_421 ) ;
if ( V_25 )
goto V_420;
if ( V_403 ) {
V_25 = F_119 ( V_2 , V_142 , V_403 ,
V_330 -> V_186 ,
false ) ;
if ( V_25 )
goto V_420;
}
}
if ( V_330 -> V_92 & V_293 ) {
unsigned long V_422 = 0 ;
struct V_234 * V_235 =
F_93 ( V_2 , V_142 -> V_139 ) ;
if ( V_330 -> V_288 != V_289 ) {
F_105 ( V_423 , & V_422 ) ;
F_105 ( V_424 , & V_422 ) ;
F_105 ( V_425 , & V_422 ) ;
}
if ( ! ( V_235 -> V_39 & ( 1 << V_426 ) ) )
F_105 ( V_427 , & V_422 ) ;
V_25 = F_120 ( V_2 , V_142 , V_330 -> V_186 , V_422 ) ;
if ( V_25 )
goto V_420;
}
if ( V_330 -> V_92 & V_285 ) {
V_25 = F_121 ( V_2 , V_142 , V_330 -> V_282 ,
V_330 -> V_284 , false ) ;
if ( V_25 )
goto V_420;
}
V_420:
if ( V_25 )
F_8 ( L_63 ,
V_142 -> V_147 , V_330 -> V_186 , V_25 ) ;
return V_25 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
struct V_232 * V_241 )
{
struct V_234 * V_235 = F_93 ( V_2 , V_142 -> V_139 ) ;
int V_25 = 0 ;
if ( V_235 -> V_39 & 1 << V_346 ) {
if ( V_241 -> V_240 > 1 ) {
F_8 ( L_64 ,
V_142 -> V_147 ) ;
V_25 = - V_428 ;
goto V_371;
}
if ( V_241 -> V_240 == 1 &&
! F_123 ( V_241 -> V_241 -> V_244 , V_235 -> V_244 ) ) {
F_8 ( L_65 ,
V_142 -> V_147 ) ;
V_25 = - V_428 ;
goto V_371;
}
}
V_371:
return V_25 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
struct V_232 * V_241 )
{
struct V_234 * V_235 = F_93 ( V_2 , V_142 -> V_139 ) ;
int V_25 = 0 ;
if ( V_235 -> V_39 & 1 << V_426 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_241 -> V_240 ; V_20 ++ ) {
if ( V_241 -> V_241 [ V_20 ] . V_92 &
V_418 ) {
F_8 ( L_66 ,
V_142 -> V_147 ) ;
V_25 = - V_428 ;
goto V_371;
}
}
}
if ( V_241 -> V_186 > F_87 ( V_142 ) ) {
V_25 = - V_428 ;
goto V_371;
}
V_371:
return V_25 ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
struct V_328 * V_329 )
{
struct V_232 * V_241 = & V_329 -> V_330 -> V_15 . V_233 ;
int V_25 ;
V_25 = F_122 ( V_2 , V_142 , V_241 ) ;
if ( V_25 )
goto V_371;
V_25 = F_124 ( V_2 , V_142 , V_241 ) ;
if ( V_25 )
goto V_371;
F_4 ( V_11 , L_67 ,
V_142 -> V_147 ,
V_241 -> V_186 ) ;
F_117 ( V_2 , V_11 , V_241 ) ;
V_25 = F_118 ( V_2 , V_142 ) ;
V_371:
F_83 ( V_2 , V_142 , V_25 ) ;
}
static void F_126 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 )
{
int V_429 = V_329 -> V_330 -> V_15 . V_228 . V_186 ;
int V_25 ;
F_4 ( V_11 , L_68 ,
V_142 -> V_147 , V_429 ) ;
V_25 = F_127 ( V_2 , V_142 , V_429 ) ;
F_83 ( V_2 , V_142 , V_25 ) ;
}
static void F_128 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 )
{
int V_25 ;
F_4 ( V_11 , L_69 , V_142 -> V_147 ) ;
V_25 = F_129 ( V_2 , V_142 ) ;
F_83 ( V_2 , V_142 , V_25 ) ;
}
static void F_130 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 )
{
int V_25 ;
F_4 ( V_11 , L_70 , V_142 -> V_147 ) ;
V_25 = F_131 ( V_2 , V_142 ) ;
F_83 ( V_2 , V_142 , V_25 ) ;
}
static void F_132 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 )
{
struct V_246 V_430 ;
struct V_248 * V_431 = & V_329 -> V_330 -> V_15 . V_249 ;
int V_25 = 0 ;
if ( V_431 -> V_254 != V_252 ||
V_431 -> V_255 != V_256 ) {
F_8 ( L_71 ,
V_142 -> V_139 ) ;
V_25 = - V_37 ;
goto V_432;
}
memset ( & V_430 , 0 , sizeof( struct V_246 ) ) ;
memcpy ( V_430 . V_251 , V_431 -> V_251 ,
V_252 ) ;
memcpy ( V_430 . V_253 , V_431 -> V_253 , sizeof( V_431 -> V_253 ) ) ;
V_430 . V_433 = & V_142 -> V_162 ;
V_430 . V_257 = V_431 -> V_257 ;
V_430 . V_258 = 0 ;
V_430 . V_434 = 0 ;
if ( V_431 -> V_258 & V_260 )
F_105 ( V_259 , & V_430 . V_258 ) ;
if ( V_431 -> V_258 & V_262 )
F_105 ( V_261 , & V_430 . V_258 ) ;
if ( V_431 -> V_258 & V_264 )
F_105 ( V_263 , & V_430 . V_258 ) ;
if ( V_431 -> V_258 & V_266 )
F_105 ( V_265 , & V_430 . V_258 ) ;
if ( V_431 -> V_258 & V_268 )
F_105 ( V_267 , & V_430 . V_258 ) ;
if ( V_431 -> V_258 & V_270 )
F_105 ( V_269 , & V_430 . V_258 ) ;
if ( V_431 -> V_258 & V_272 )
F_105 ( V_271 , & V_430 . V_258 ) ;
if ( V_431 -> V_258 & V_274 )
F_105 ( V_273 , & V_430 . V_258 ) ;
if ( V_431 -> V_258 & V_276 )
F_105 ( V_275 , & V_430 . V_258 ) ;
if ( ( ! ( V_431 -> V_258 & V_268 ) &&
V_431 -> V_258 & V_270 ) ||
( ! ( V_431 -> V_258 & V_274 ) &&
V_431 -> V_258 & V_276 ) ) {
F_8 ( L_72 ) ;
V_25 = - V_37 ;
goto V_432;
}
V_25 = F_133 ( V_2 , V_142 , & V_430 ) ;
V_432:
F_83 ( V_2 , V_142 , V_25 ) ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_435 * V_436 )
{
int V_25 = 0 ;
if ( V_436 -> V_437 . V_438 >
V_439 ) {
V_25 = - V_37 ;
F_8 ( L_73 ,
V_436 -> V_437 . V_438 ,
V_439 ) ;
}
if ( V_436 -> V_437 . V_440 > F_135 ( V_2 ) ) {
V_25 = - V_37 ;
F_8 ( L_74 ,
V_436 -> V_437 . V_440 ,
F_135 ( V_2 ) ) ;
}
return V_25 ;
}
static void F_136 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 )
{
struct V_441 V_442 ;
struct V_435 * V_436 = & V_329 -> V_330 -> V_15 . V_443 ;
int V_25 = 0 ;
memset ( & V_442 , 0 , sizeof( V_442 ) ) ;
if ( F_134 ( V_2 , V_436 ) )
goto V_432;
V_442 . V_444 =
V_436 -> V_437 . V_444 ;
V_442 . V_445 =
V_436 -> V_437 . V_445 ;
V_442 . V_446 =
V_436 -> V_437 . V_447 ;
V_442 . V_395 =
V_436 -> V_437 . V_438 ;
V_442 . V_440 =
V_436 -> V_437 . V_440 ;
V_442 . V_448 =
V_436 -> V_437 . V_449 ;
V_442 . V_450 =
V_436 -> V_437 . V_450 ;
V_442 . V_451 =
V_436 -> V_437 . V_451 ;
V_442 . V_452 =
V_436 -> V_437 . V_452 ;
V_442 . V_453 =
V_436 -> V_437 . V_453 ;
V_442 . V_454 =
V_436 -> V_437 . V_454 ;
V_25 = F_137 ( V_2 , V_142 , V_436 , & V_442 ) ;
V_432:
F_83 ( V_2 , V_142 , V_25 ) ;
}
static void F_138 ( struct V_1 * V_2 , struct V_141 * V_142 ,
struct V_328 * V_329 )
{
int V_20 ;
if ( F_11 ( V_329 -> V_9 . V_7 . type ) ) {
F_139 ( V_2 , V_142 , V_329 -> V_9 . V_7 . type ) ;
switch ( V_329 -> V_9 . V_7 . type ) {
case V_65 :
F_100 ( V_2 , V_142 , V_329 ) ;
return;
case V_126 :
F_102 ( V_2 , V_142 , V_329 ) ;
return;
case V_173 :
F_107 ( V_2 , V_142 , V_329 ) ;
return;
case V_238 :
F_125 ( V_2 , V_142 , V_329 ) ;
return;
case V_229 :
F_126 ( V_2 , V_142 , V_329 ) ;
return;
case V_140 :
F_128 ( V_2 , V_142 , V_329 ) ;
return;
case V_123 :
F_130 ( V_2 , V_142 , V_329 ) ;
return;
case V_250 :
F_132 ( V_2 , V_142 , V_329 ) ;
return;
case V_455 :
F_136 ( V_2 , V_142 , V_329 ) ;
return;
}
} else {
F_8 ( L_75 ,
V_329 -> V_9 . V_7 . type , V_329 -> V_9 . V_7 . V_5 ,
V_142 -> V_280 ) ;
for ( V_20 = 0 ; V_20 < 20 ; V_20 ++ )
F_23 ( V_11 , L_76 ,
V_329 -> V_330 -> V_15 . V_456 . V_457 [ V_20 ] ) ;
}
if ( V_142 -> V_280 == V_458 || V_142 -> V_280 == V_459 ) {
F_83 ( V_2 , V_142 , V_460 ) ;
} else {
F_60 ( V_2 , V_142 -> V_147 ) ;
F_80 () ;
F_81 ( V_2 , V_142 , V_329 -> V_9 . V_7 . type ) ;
}
}
void F_140 ( struct V_1 * V_2 ,
struct V_461 * V_462 )
{
T_2 V_463 ;
F_4 ( V_11 ,
L_77 ,
V_462 -> V_49 , V_462 -> V_44 , V_462 -> V_43 ) ;
if ( V_462 -> V_49 - F_141 ( V_2 ) -> V_464 . V_465 >
F_142 ( V_2 ) ) {
F_8 ( L_78 ,
V_462 -> V_49 , F_142 ( V_2 ) ) ;
return;
}
V_463 = F_143 ( V_2 , V_462 -> V_49 ) ;
F_3 ( & F_141 ( V_2 ) -> V_466 ) ;
F_77 ( V_2 , V_463 ) -> V_300 = V_462 -> V_44 ;
F_77 ( V_2 , V_463 ) -> V_301 = V_462 -> V_43 ;
F_141 ( V_2 ) -> V_467 |= ( 1ULL << V_463 ) ;
F_6 ( & F_141 ( V_2 ) -> V_466 ) ;
F_144 ( V_2 , V_468 ) ;
}
void V_328 ( struct V_1 * V_2 )
{
struct V_469 * V_470 = F_141 ( V_2 ) ;
T_6 V_471 ;
T_2 V_463 ;
int V_25 ;
if ( ! V_470 )
return;
F_3 ( & V_470 -> V_466 ) ;
V_471 = V_470 -> V_467 ;
V_470 -> V_467 = 0 ;
F_6 ( & V_470 -> V_466 ) ;
F_66 (bp, vf_idx) {
struct V_328 * V_329 = F_77 ( V_2 , V_463 ) ;
struct V_141 * V_142 = F_145 ( V_2 , V_463 ) ;
if ( ! ( V_471 & ( 1ULL << V_463 ) ) )
continue;
F_4 ( V_11 ,
L_79 ,
V_463 , V_329 -> V_300 , V_329 -> V_301 ,
V_329 -> V_9 . V_14 ) ;
V_25 = F_71 ( V_2 , true , V_329 -> V_31 ,
V_142 -> V_147 , V_329 -> V_300 ,
V_329 -> V_301 ,
sizeof( union V_472 ) / 4 ) ;
if ( V_25 ) {
F_8 ( L_80 ,
V_142 -> V_147 ) ;
F_82 ( V_2 , V_142 ) ;
return;
}
V_329 -> V_9 = V_329 -> V_330 -> V_15 . V_9 ;
memset ( & V_329 -> V_330 -> V_60 , 0 , sizeof( union V_88 ) ) ;
F_138 ( V_2 , V_142 , V_329 ) ;
}
}
int F_146 ( struct V_1 * V_2 , int V_142 )
{
struct V_234 * V_235 = F_93 ( V_2 , V_142 ) ;
T_3 V_298 = F_147 ( V_2 ) -> V_473 +
V_142 * V_474 ;
T_3 V_332 = F_67 ( V_2 , V_142 , V_347 ) ;
int V_25 ;
if ( F_67 ( V_2 , V_142 , V_280 ) != V_459 &&
F_67 ( V_2 , V_142 , V_280 ) != V_458 )
return 0 ;
V_235 -> V_475 ++ ;
V_235 -> V_5 = V_474 ;
V_235 -> V_476 = F_148 ( V_2 , V_235 ) ;
V_25 = F_71 ( V_2 , false , V_298 ,
F_67 ( V_2 , V_142 , V_147 ) , F_19 ( V_332 ) ,
F_18 ( V_332 ) , V_235 -> V_5 / 4 ) ;
return V_25 ;
}
