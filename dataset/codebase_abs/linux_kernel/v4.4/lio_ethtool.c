static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 ;
V_10 = & V_5 -> V_10 ;
if ( V_10 -> V_11 . V_12 . V_13 == V_14 ||
V_10 -> V_11 . V_12 . V_13 == V_15 ) {
V_4 -> V_16 = V_17 ;
V_4 -> V_18 =
( V_19 | V_20 |
V_21 ) ;
V_4 -> V_22 =
( V_23 | V_24 ) ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = V_28 ;
} else {
F_3 ( & V_7 -> V_29 -> V_30 , L_1 ) ;
}
if ( V_10 -> V_11 . V_12 . V_31 ) {
F_4 ( V_4 , V_10 -> V_11 . V_12 . V_32 ) ;
V_4 -> V_33 = V_10 -> V_11 . V_12 . V_33 ;
} else {
F_4 ( V_4 , V_34 ) ;
V_4 -> V_33 = V_35 ;
}
return 0 ;
}
static void
F_5 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( V_2 ) ;
V_7 = V_5 -> V_8 ;
memset ( V_37 , 0 , sizeof( struct V_36 ) ) ;
strcpy ( V_37 -> V_38 , L_2 ) ;
strcpy ( V_37 -> V_39 , V_40 ) ;
strncpy ( V_37 -> V_41 , V_7 -> V_42 . V_43 ,
V_44 ) ;
strncpy ( V_37 -> V_45 , F_6 ( V_7 -> V_29 ) , 32 ) ;
}
static void
F_7 ( struct V_1 * V_30 ,
struct V_46 * V_47 )
{
struct V_5 * V_5 = F_2 ( V_30 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_48 = 0 , V_49 = 0 , V_50 = 0 , V_51 = 0 ;
if ( F_8 ( V_7 ) ) {
struct V_52 * V_53 = F_9 ( V_7 , V_54 , V_55 ) ;
V_48 = F_10 ( V_53 ) ;
V_49 = F_11 ( V_53 ) ;
V_51 = F_12 ( V_53 , V_5 -> V_56 ) ;
V_50 = F_13 ( V_53 , V_5 -> V_56 ) ;
}
V_47 -> V_48 = V_48 ;
V_47 -> V_49 = V_49 ;
V_47 -> V_51 = V_51 ;
V_47 -> V_50 = V_50 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_2 V_57 [ 128 ] ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_58 * V_59 ;
int V_60 ;
V_59 = (struct V_58 * ) ( & V_8 -> V_61 ) ;
V_60 = sprintf ( V_57 , L_3 ,
V_59 -> V_62 , V_59 -> V_63 ,
V_59 -> V_64 , V_59 -> V_65 ) ;
return V_60 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_66 * V_67 ,
T_2 * V_68 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_58 * V_59 ;
int V_60 ;
if ( V_67 -> V_69 != 0 )
return - V_70 ;
V_67 -> V_71 = V_8 -> V_29 -> V_72 ;
V_59 = (struct V_58 * ) ( & V_8 -> V_61 ) ;
V_60 =
sprintf ( ( char * ) V_68 ,
L_3 ,
V_59 -> V_62 , V_59 -> V_63 ,
V_59 -> V_64 , V_59 -> V_65 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_73 , int V_74 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
int V_79 = 0 ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 . V_80 . V_81 = 0 ;
V_76 . V_80 . V_12 . V_82 = V_83 ;
V_76 . V_80 . V_12 . V_84 = V_5 -> V_10 . V_56 ;
V_76 . V_80 . V_12 . V_85 = V_73 ;
V_76 . V_80 . V_12 . V_86 = V_74 ;
V_76 . V_87 = 100 ;
V_76 . V_88 = ( V_81 ) V_2 ;
V_76 . V_89 = V_90 ;
V_78 . V_91 = V_92 ;
V_79 = F_17 ( V_5 -> V_8 , & V_76 , V_78 ) ;
if ( V_79 < 0 ) {
F_3 ( & V_7 -> V_29 -> V_30 , L_4 ) ;
return - V_70 ;
}
return 0 ;
}
static void F_18 ( struct V_6 * V_7 ,
T_1 V_31 ,
void * V_57 )
{
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_97 * V_98 = (struct V_97 * ) V_57 ;
V_94 = (struct V_93 * ) V_98 -> V_99 ;
V_96 = (struct V_95 * ) V_98 -> V_100 ;
V_7 = F_19 ( V_96 -> V_101 ) ;
if ( V_31 ) {
F_3 ( & V_7 -> V_29 -> V_30 , L_5 ,
F_20 ( V_31 ) ) ;
F_21 ( V_96 -> V_102 ) = - 1 ;
} else {
F_21 ( V_96 -> V_102 ) = 1 ;
}
F_22 ( & V_96 -> V_103 ) ;
}
static int
F_23 ( struct V_5 * V_5 , int V_104 , int V_105 , int * V_106 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_97 * V_98 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_107 * V_108 ;
int V_109 = 0 ;
V_98 = (struct V_97 * )
F_24 ( V_8 ,
sizeof( struct V_107 ) ,
sizeof( struct V_93 ) ,
sizeof( struct V_95 ) ) ;
if ( ! V_98 )
return - V_110 ;
V_96 = (struct V_95 * ) V_98 -> V_100 ;
V_94 = (struct V_93 * ) V_98 -> V_99 ;
V_108 = (struct V_107 * ) V_98 -> V_111 ;
F_21 ( V_96 -> V_102 ) = 0 ;
V_96 -> V_101 = F_25 ( V_8 ) ;
V_108 -> V_104 = V_104 ;
V_108 -> V_112 = V_105 ;
if ( V_104 )
V_108 -> V_113 = * V_106 ;
V_108 -> V_114 = V_5 -> V_10 . V_56 ;
F_26 ( ( V_81 * ) V_108 , sizeof( struct V_107 ) / 8 ) ;
F_27 ( V_8 , V_98 , V_115 , V_116 ,
0 , 0 , 0 ) ;
V_98 -> V_87 = 1000 ;
V_98 -> V_117 = F_18 ;
V_98 -> V_118 = V_98 ;
F_28 ( & V_96 -> V_103 ) ;
V_109 = F_29 ( V_8 , V_98 ) ;
if ( V_109 ) {
F_3 ( & V_8 -> V_29 -> V_30 ,
L_6 ,
V_109 ) ;
V_109 = - V_119 ;
} else {
F_30 ( & V_96 -> V_103 , & V_96 -> V_102 ) ;
V_109 = V_94 -> V_31 ;
if ( V_109 ) {
F_3 ( & V_8 -> V_29 -> V_30 , L_7 ) ;
V_109 = - V_119 ;
} else {
F_26 ( ( V_81 * ) ( & V_94 -> V_120 ) ,
sizeof( struct V_107 ) / 8 ) ;
if ( F_21 ( V_96 -> V_102 ) == 1 ) {
if ( ! V_104 )
* V_106 = V_94 -> V_120 . V_113 ;
} else {
V_109 = - V_70 ;
}
}
}
F_31 ( V_8 , V_98 ) ;
return V_109 ;
}
static int F_32 ( struct V_1 * V_2 ,
enum V_121 V_122 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_106 , V_79 ;
switch ( V_122 ) {
case V_123 :
if ( V_7 -> V_124 == V_125 ) {
F_16 ( V_2 , V_126 ,
V_127 ) ;
return 2 ;
} else if ( V_7 -> V_124 == V_128 ) {
V_79 = F_23 ( V_5 , 0 ,
V_129 ,
& V_5 -> V_130 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_23 ( V_5 , 0 ,
V_131 ,
& V_5 -> V_132 ) ;
if ( V_79 )
return V_79 ;
V_106 = V_133 ;
V_79 =
F_23 ( V_5 , 1 ,
V_129 ,
& V_106 ) ;
if ( V_79 )
return V_79 ;
V_106 = V_134 ;
V_79 =
F_23 ( V_5 , 1 ,
V_131 ,
& V_106 ) ;
if ( V_79 )
return V_79 ;
} else {
return - V_70 ;
}
break;
case V_135 :
if ( V_7 -> V_124 == V_125 ) {
F_16 ( V_2 , V_126 ,
V_136 ) ;
} else if ( V_7 -> V_124 == V_128 ) {
return - V_70 ;
} else {
return - V_70 ;
}
break;
case V_137 :
if ( V_7 -> V_124 == V_125 )
F_16 ( V_2 , V_126 ,
V_138 ) ;
else if ( V_7 -> V_124 == V_128 )
return - V_70 ;
else
return - V_70 ;
break;
case V_139 :
if ( V_7 -> V_124 == V_125 ) {
F_16 ( V_2 , V_126 ,
V_140 ) ;
} else if ( V_7 -> V_124 == V_128 ) {
V_79 = F_23 ( V_5 , 1 ,
V_131 ,
& V_5 -> V_132 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_23 ( V_5 , 1 ,
V_129 ,
& V_5 -> V_130 ) ;
if ( V_79 )
return V_79 ;
} else {
return - V_70 ;
}
break;
default:
return - V_70 ;
}
return 0 ;
}
static void
F_33 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_143 = 0 , V_144 = 0 , V_145 = 0 ,
V_146 = 0 ;
if ( F_8 ( V_7 ) ) {
struct V_52 * V_53 = F_9 ( V_7 , V_54 , V_55 ) ;
V_143 = V_147 ;
V_144 = V_148 ;
V_146 = F_34 ( V_53 , V_5 -> V_56 ) ;
V_145 = F_35 ( V_53 , V_5 -> V_56 ) ;
}
if ( V_5 -> V_149 > V_150 ) {
V_142 -> V_146 = 0 ;
V_142 -> V_144 = 0 ;
V_142 -> V_151 = 0 ;
V_142 -> V_152 = V_146 ;
V_142 -> V_153 = 0 ;
V_142 -> V_154 = V_144 ;
} else {
V_142 -> V_146 = V_146 ;
V_142 -> V_144 = V_144 ;
V_142 -> V_151 = 0 ;
V_142 -> V_152 = 0 ;
V_142 -> V_153 = 0 ;
V_142 -> V_154 = 0 ;
}
V_142 -> V_145 = V_145 ;
V_142 -> V_143 = V_143 ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_155 ;
}
static void F_37 ( struct V_1 * V_2 , T_1 V_156 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( ( V_156 ^ V_5 -> V_155 ) & V_157 ) {
if ( V_156 & V_157 )
F_38 ( V_2 ,
V_158 ) ;
else
F_38 ( V_2 ,
V_159 ) ;
}
V_5 -> V_155 = V_156 ;
}
static void
F_39 ( struct V_1 * V_2 , struct V_160 * V_161 )
{
V_161 -> V_162 = 1 ;
V_161 -> V_163 = 1 ;
}
static void
F_40 ( struct V_1 * V_2 ,
struct V_164 * V_165 , V_81 * V_166 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
int V_167 = 0 , V_168 ;
for ( V_168 = 0 ; V_168 < V_169 ; V_168 ++ ) {
if ( ! ( V_8 -> V_170 . V_171 & ( 1UL << V_168 ) ) )
continue;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_172 [ V_168 ] -> V_165 . V_173 ) ;
V_166 [ V_167 ++ ] =
F_20 (
V_8 -> V_172 [ V_168 ] -> V_165 . V_174 ) ;
V_166 [ V_167 ++ ] =
F_20 (
V_8 -> V_172 [ V_168 ] -> V_165 . V_175 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_172 [ V_168 ] -> V_165 . V_176 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_172 [ V_168 ] -> V_165 . V_177 ) ;
V_166 [ V_167 ++ ] =
F_41 ( V_8 -> V_172 [ V_168 ] -> V_178 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_172 [ V_168 ] -> V_165 . V_179 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_172 [ V_168 ] -> V_165 . V_180 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_172 [ V_168 ] -> V_165 . V_181 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_172 [ V_168 ] -> V_165 . V_182 ) ;
}
for ( V_168 = 0 ; V_168 < V_183 ; V_168 ++ ) {
if ( ! ( V_8 -> V_170 . V_184 & ( 1UL << V_168 ) ) )
continue;
V_166 [ V_167 ++ ] = F_20 ( V_8 -> V_185 [ V_168 ] -> V_165 . V_186 ) ;
V_166 [ V_167 ++ ] = F_20 ( V_8 -> V_185 [ V_168 ] -> V_165 . V_187 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_185 [ V_168 ] -> V_165 . V_188 ) ;
V_166 [ V_167 ++ ] = F_20 ( V_8 -> V_185 [ V_168 ] -> V_165 . V_189 ) ;
V_166 [ V_167 ++ ] = F_20 ( V_8 -> V_185 [ V_168 ] -> V_165 . V_190 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_185 [ V_168 ] -> V_165 . V_191 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_185 [ V_168 ] -> V_165 . V_192 ) ;
V_166 [ V_167 ++ ] =
F_20 ( V_8 -> V_185 [ V_168 ] -> V_165 . V_193 ) ;
}
}
static void F_42 ( struct V_1 * V_2 , T_1 V_194 , T_2 * V_166 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
int V_195 , V_196 , V_167 , V_168 ;
V_195 = F_43 ( V_197 ) ;
for ( V_167 = 0 ; V_167 < V_169 ; V_167 ++ ) {
if ( ! ( V_8 -> V_170 . V_171 & ( 1UL << V_167 ) ) )
continue;
for ( V_168 = 0 ; V_168 < V_195 ; V_168 ++ ) {
sprintf ( V_166 , L_8 , V_167 , V_197 [ V_168 ] ) ;
V_166 += V_198 ;
}
}
V_196 = F_43 ( V_199 ) ;
for ( V_167 = 0 ; V_167 < V_183 ; V_167 ++ ) {
if ( ! ( V_8 -> V_170 . V_184 & ( 1UL << V_167 ) ) )
continue;
for ( V_168 = 0 ; V_168 < V_196 ; V_168 ++ ) {
sprintf ( V_166 , L_9 , V_167 , V_199 [ V_168 ] ) ;
V_166 += V_198 ;
}
}
}
static int F_44 ( struct V_1 * V_2 , int V_200 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
return ( F_43 ( V_197 ) * V_8 -> V_201 ) +
( F_43 ( V_199 ) * V_8 -> V_202 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_205 * V_54 = (struct V_205 * ) V_7 -> V_206 ;
struct V_207 * V_171 ;
struct V_208 * V_209 ;
V_209 = & V_7 -> V_210 ;
switch ( V_7 -> V_124 ) {
case V_128 :
case V_125 :
if ( ! V_209 -> V_211 ) {
V_204 -> V_212 =
F_46 ( V_54 -> V_55 ) ;
V_204 -> V_213 =
F_47 ( V_54 -> V_55 ) ;
} else {
V_204 -> V_214 =
V_209 -> V_211 ;
V_204 -> V_215 =
V_209 -> V_216 ;
V_204 -> V_217 =
V_209 -> V_218 ;
V_204 -> V_219 =
V_209 -> V_220 ;
V_204 -> V_221 =
V_209 -> V_222 ;
V_204 -> V_223 =
V_209 -> V_224 ;
V_204 -> V_225 =
V_209 -> V_226 ;
V_204 -> V_227 =
V_209 -> V_228 ;
}
V_171 = V_7 -> V_172 [ V_5 -> V_10 . V_229 [ 0 ] ] ;
V_204 -> V_230 = V_171 -> V_231 ;
break;
default:
F_48 ( V_5 , V_232 , V_5 -> V_2 , L_10 ) ;
return - V_70 ;
}
return 0 ;
}
static void F_49 ( struct V_6 * V_8 ,
T_1 V_31 ,
void * V_233 )
{
struct V_234 * V_82 = V_233 ;
struct V_97 * V_98 = V_82 -> V_98 ;
V_8 = V_82 -> V_8 ;
if ( V_31 )
F_3 ( & V_8 -> V_29 -> V_30 , L_11 ,
F_20 ( V_31 ) ) ;
else
F_50 ( & V_8 -> V_29 -> V_30 ,
L_12 ,
V_8 -> V_210 . V_211 ) ;
F_31 ( V_8 , V_98 ) ;
}
static int F_51 ( void * V_7 , struct V_208 * V_235 )
{
struct V_97 * V_98 ;
struct V_234 * V_82 ;
struct V_208 * V_236 ;
int V_109 ;
struct V_6 * V_8 = (struct V_6 * ) V_7 ;
V_98 = (struct V_97 * )
F_24 ( V_8 ,
sizeof( struct V_208 ) ,
0 ,
sizeof( struct V_234 ) ) ;
if ( ! V_98 )
return - V_110 ;
V_82 = (struct V_234 * ) V_98 -> V_100 ;
V_236 = (struct V_208 * ) V_98 -> V_111 ;
memcpy ( V_236 , V_235 , sizeof( struct V_208 ) ) ;
F_26 ( ( V_81 * ) V_236 , ( sizeof( struct V_208 ) ) / 8 ) ;
V_82 -> V_98 = V_98 ;
V_82 -> V_236 = V_236 ;
V_82 -> V_8 = V_8 ;
F_27 ( V_8 , V_98 , V_115 ,
V_237 , 0 , 0 , 0 ) ;
V_98 -> V_117 = F_49 ;
V_98 -> V_118 = V_82 ;
V_98 -> V_87 = 1000 ;
V_109 = F_29 ( V_8 , V_98 ) ;
if ( V_109 ) {
F_31 ( V_8 , V_98 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_52 ( struct V_5 * V_5 , struct V_203
* V_204 , int V_238 )
{
int V_79 = 0 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_208 * V_209 ;
V_209 = & V_7 -> V_210 ;
if ( V_238 ) {
if ( V_204 -> V_215 )
V_209 -> V_216 =
V_204 -> V_215 ;
else
V_209 -> V_216 =
V_239 ;
if ( V_204 -> V_217 )
V_209 -> V_218 =
V_204 -> V_217 ;
else
V_209 -> V_218 =
V_240 ;
if ( V_204 -> V_219 )
V_209 -> V_220 =
V_204 -> V_219 ;
else
V_209 -> V_220 =
V_241 ;
if ( V_204 -> V_221 )
V_209 -> V_222 =
V_204 -> V_221 ;
else
V_209 -> V_222 =
V_242 ;
if ( V_204 -> V_223 )
V_209 -> V_224 =
V_204 -> V_223 ;
else
V_209 -> V_224 =
V_243 ;
if ( V_204 -> V_225 )
V_209 -> V_226 =
V_204 -> V_225 ;
else
V_209 -> V_226 =
V_244 ;
if ( V_204 -> V_227 )
V_209 -> V_228 =
V_204 -> V_227 ;
else
V_209 -> V_228 =
V_245 ;
}
V_209 -> V_211 = V_238 ;
V_79 = F_51 ( V_7 , V_209 ) ;
return V_79 ;
}
static int
F_53 ( struct V_5 * V_5 , struct V_203 * V_204 )
{
int V_79 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_205 * V_54 = (struct V_205 * ) V_7 -> V_206 ;
T_1 V_213 ;
if ( ! V_204 -> V_213 )
V_213 = V_246 ;
else
V_213 = V_204 -> V_213 ;
V_79 = F_52 ( V_5 , V_204 , 0 ) ;
if ( V_79 )
return V_79 ;
F_54 ( V_7 , V_247 ,
V_213 ) ;
F_55 ( V_54 -> V_55 , V_213 ) ;
return 0 ;
}
static int F_56 ( struct V_5 * V_5 , struct V_203
* V_204 )
{
int V_79 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_205 * V_54 = (struct V_205 * ) V_7 -> V_206 ;
T_1 V_248 , V_212 ;
if ( ! V_204 -> V_212 )
V_212 = V_249 ;
else
V_212 = V_204 -> V_212 ;
V_79 = F_52 ( V_5 , V_204 , 0 ) ;
if ( V_79 )
return V_79 ;
V_248 = F_57 ( V_7 , V_212 ) ;
F_54 ( V_7 , V_250 , V_248 ) ;
F_58 ( V_54 -> V_55 , V_212 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_79 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_168 , V_251 ;
if ( ( V_204 -> V_230 >= V_252 ) &&
( V_204 -> V_230 <= V_253 ) ) {
for ( V_168 = 0 ; V_168 < V_5 -> V_10 . V_254 ; V_168 ++ ) {
V_251 = V_5 -> V_10 . V_229 [ V_168 ] ;
V_7 -> V_172 [ V_251 ] -> V_231 =
V_204 -> V_230 ;
}
} else {
F_3 ( & V_7 -> V_29 -> V_30 ,
L_13 ,
V_204 -> V_230 , V_252 ,
V_253 ) ;
return - V_70 ;
}
if ( V_204 -> V_214 ) {
V_79 = F_52 ( V_5 , V_204 , 1 ) ;
if ( V_79 )
goto V_255;
}
if ( ( V_204 -> V_212 ) &&
( ! V_204 -> V_214 ) ) {
V_79 = F_56 ( V_5 , V_204 ) ;
if ( V_79 )
goto V_255;
}
if ( ( V_204 -> V_213 ) &&
( ! V_204 -> V_214 ) ) {
V_79 = F_53 ( V_5 , V_204 ) ;
if ( V_79 )
goto V_255;
}
if ( ( ! V_204 -> V_213 ) &&
( ! V_204 -> V_214 ) &&
( ! V_204 -> V_212 ) ) {
F_50 ( & V_7 -> V_29 -> V_30 ,
L_14 ) ;
F_50 ( & V_7 -> V_29 -> V_30 ,
L_15 ,
V_249 , V_246 ) ;
V_79 = F_56 ( V_5 , V_204 ) ;
if ( V_79 )
goto V_255;
V_79 = F_53 ( V_5 , V_204 ) ;
if ( V_79 )
goto V_255;
}
return 0 ;
V_255:
return V_79 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_256 * V_257 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
V_257 -> V_258 =
V_259 |
V_260 |
V_261 |
V_262 |
V_263 | V_264 ;
if ( V_5 -> V_265 )
V_257 -> V_266 = F_61 ( V_5 -> V_265 ) ;
else
V_257 -> V_266 = - 1 ;
V_257 -> V_267 = ( 1 << V_268 ) | ( 1 << V_269 ) ;
V_257 -> V_270 = ( 1 << V_271 ) |
( 1 << V_272 ) |
( 1 << V_273 ) |
( 1 << V_274 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
int V_79 = 0 ;
V_10 = & V_5 -> V_10 ;
if ( V_4 -> V_27 != V_275 && V_4 -> V_27 != V_28 )
return - V_70 ;
if ( V_4 -> V_27 == V_28 && ( ( V_4 -> V_32 != V_276 &&
V_4 -> V_32 != V_277 ) ||
( V_4 -> V_33 != V_278 &&
V_4 -> V_33 != V_279 ) ) )
return - V_70 ;
if ( V_10 -> V_11 . V_12 . V_13 == V_14 ||
V_10 -> V_11 . V_12 . V_13 == V_15 ) {
F_50 ( & V_7 -> V_29 -> V_30 , L_16 ) ;
return - V_70 ;
}
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 . V_80 . V_81 = 0 ;
V_76 . V_80 . V_12 . V_82 = V_280 ;
V_76 . V_87 = 1000 ;
V_76 . V_88 = ( V_81 ) V_2 ;
V_76 . V_80 . V_12 . V_84 = V_5 -> V_10 . V_56 ;
V_76 . V_89 = V_90 ;
if ( V_4 -> V_27 == V_275 ) {
V_76 . V_80 . V_12 . V_281 = V_282 |
V_283 ;
V_76 . V_80 . V_12 . V_85 = V_4 -> V_22 ;
} else {
V_76 . V_80 . V_12 . V_281 = V_282 ;
V_76 . V_80 . V_12 . V_86 = V_4 -> V_33 ;
V_76 . V_80 . V_12 . V_85 = V_4 -> V_32 ;
}
V_78 . V_91 = V_92 ;
V_79 = F_17 ( V_5 -> V_8 , & V_76 , V_78 ) ;
if ( V_79 < 0 ) {
F_3 ( & V_7 -> V_29 -> V_30 , L_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
if ( F_64 ( V_2 ) ) {
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_27 = 0 ;
V_4 . V_32 = 0 ;
V_4 . V_33 = 0 ;
F_62 ( V_2 , & V_4 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_30 )
{
return V_284 ;
}
static int F_66 ( char * V_12 , struct V_6 * V_7 )
{
T_1 V_285 ;
int V_167 , V_60 = 0 ;
V_60 += sprintf ( V_12 + V_60 , L_18 ) ;
V_285 = V_286 ;
V_60 += sprintf ( V_12 + V_60 , L_19 ,
V_286 , F_67 ( V_7 , V_285 ) ) ;
V_285 = V_287 ;
V_60 += sprintf ( V_12 + V_60 , L_20 ,
V_287 , F_67 ( V_7 , V_285 ) ) ;
V_285 = V_288 ;
V_60 += sprintf ( V_12 + V_60 , L_21 ,
V_288 , F_67 ( V_7 , V_285 ) ) ;
V_285 = V_289 ;
V_60 += sprintf ( V_12 + V_60 , L_22 ,
V_289 , F_67 ( V_7 , V_285 ) ) ;
V_285 = V_290 ;
V_60 += sprintf ( V_12 + V_60 , L_23 ,
V_290 , F_67 ( V_7 , V_285 ) ) ;
V_285 = V_291 ;
V_60 += sprintf ( V_12 + V_60 , L_24 ,
V_291 , F_67 ( V_7 , V_285 ) ) ;
V_60 += sprintf ( V_12 + V_60 , L_25 ,
V_292 ,
F_67 ( V_7 , V_292 ) ) ;
V_60 += sprintf ( V_12 + V_60 , L_26 ,
V_293 , F_67 ( V_7 ,
V_293 ) ) ;
V_60 += sprintf ( V_12 + V_60 , L_27 ,
V_294 ,
F_67 ( V_7 , V_294 ) ) ;
V_60 += sprintf ( V_12 + V_60 , L_28 , V_295 ,
F_67 ( V_7 , V_295 ) ) ;
for ( V_167 = 0 ; V_167 < V_7 -> V_202 ; V_167 ++ ) {
V_285 = F_68 ( V_167 ) ;
V_60 += sprintf ( V_12 + V_60 , L_29 ,
V_285 , V_167 , F_67 ( V_7 , V_285 ) ) ;
V_285 = F_69 ( V_167 ) ;
V_60 += sprintf ( V_12 + V_60 , L_30 ,
V_285 , V_167 , F_67 ( V_7 , V_285 ) ) ;
}
V_285 = V_247 ;
V_60 += sprintf ( V_12 + V_60 , L_31 ,
V_285 , F_67 ( V_7 , V_285 ) ) ;
V_285 = V_250 ;
V_60 += sprintf ( V_12 + V_60 , L_32 ,
V_285 , F_67 ( V_7 , V_285 ) ) ;
for ( V_167 = 0 ; V_167 <= 3 ; V_167 ++ ) {
T_1 V_285 ;
V_285 = F_70 ( V_167 ) ;
V_60 += sprintf ( V_12 + V_60 , L_33 ,
V_285 , V_167 , F_67 ( V_7 , V_285 ) ) ;
V_285 = F_71 ( V_167 ) ;
V_60 += sprintf ( V_12 + V_60 , L_34 ,
V_285 , V_167 , F_67 ( V_7 , V_285 ) ) ;
}
V_60 += sprintf ( V_12 + V_60 , L_35 ,
F_72 ( 0 ) ,
F_67 ( V_7 , F_72 ( 0 ) ) ) ;
V_285 = F_73 ( 0 ) ;
V_60 += sprintf ( V_12 + V_60 , L_36 ,
F_73 ( 0 ) , F_67 ( V_7 , V_285 ) ) ;
V_285 = F_74 ( 0 ) ;
V_60 += sprintf ( V_12 + V_60 , L_37 ,
F_74 ( 0 ) ,
F_67 ( V_7 , V_285 ) ) ;
V_60 += sprintf ( V_12 + V_60 , L_38 ,
F_72 ( 1 ) ,
F_67 ( V_7 , F_72 ( 1 ) ) ) ;
V_285 = F_73 ( 1 ) ;
V_60 += sprintf ( V_12 + V_60 , L_39 ,
F_73 ( 1 ) ,
F_67 ( V_7 , V_285 ) ) ;
V_285 = F_73 ( 1 ) ;
V_60 += sprintf ( V_12 + V_60 , L_40 ,
F_74 ( 1 ) ,
F_67 ( V_7 , V_285 ) ) ;
V_60 += sprintf ( V_12 + V_60 , L_41 ) ;
for ( V_167 = 0 ; V_167 < 16 ; V_167 ++ ) {
V_285 = F_75 ( V_7 , F_76 ( V_167 , V_7 -> V_296 ) ) ;
V_60 += sprintf ( V_12 + V_60 , L_42 ,
F_76 ( V_167 , V_7 -> V_296 ) , V_167 , V_285 ) ;
}
return V_60 ;
}
static int F_77 ( char * V_12 , struct V_6 * V_7 )
{
T_1 V_74 ;
int V_167 , V_60 = 0 ;
V_60 += sprintf ( V_12 + V_60 ,
L_43 ) ;
for ( V_167 = 0 ; V_167 <= 13 ; V_167 ++ ) {
F_78 ( V_7 -> V_29 , ( V_167 * 4 ) , & V_74 ) ;
V_60 += sprintf ( V_12 + V_60 , L_44 ,
( V_167 * 4 ) , V_167 , V_74 ) ;
}
for ( V_167 = 30 ; V_167 <= 34 ; V_167 ++ ) {
F_78 ( V_7 -> V_29 , ( V_167 * 4 ) , & V_74 ) ;
V_60 += sprintf ( V_12 + V_60 , L_44 ,
( V_167 * 4 ) , V_167 , V_74 ) ;
}
return V_60 ;
}
static void F_79 ( struct V_1 * V_30 ,
struct V_297 * V_298 , void * V_299 )
{
struct V_5 * V_5 = F_2 ( V_30 ) ;
int V_60 = 0 ;
struct V_6 * V_7 = V_5 -> V_8 ;
memset ( V_299 , 0 , V_284 ) ;
V_298 -> V_39 = V_300 ;
switch ( V_7 -> V_124 ) {
case V_128 :
case V_125 :
V_60 += F_66 ( V_299 + V_60 , V_7 ) ;
V_60 += F_77 ( V_299 + V_60 , V_7 ) ;
break;
default:
F_3 ( & V_7 -> V_29 -> V_30 , L_45 ,
V_301 , V_7 -> V_124 ) ;
}
}
void F_80 ( struct V_1 * V_2 )
{
V_2 -> V_302 = & V_303 ;
}
