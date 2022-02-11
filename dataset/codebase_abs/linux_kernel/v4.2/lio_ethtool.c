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
V_37 -> V_46 = V_47 ;
}
static void
F_7 ( struct V_1 * V_30 ,
struct V_48 * V_49 )
{
struct V_5 * V_5 = F_2 ( V_30 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_50 = 0 , V_51 = 0 , V_52 = 0 , V_53 = 0 ;
if ( F_8 ( V_7 ) ) {
struct V_54 * V_55 = F_9 ( V_7 , V_56 , V_57 ) ;
V_50 = F_10 ( V_55 ) ;
V_51 = F_11 ( V_55 ) ;
V_53 = F_12 ( V_55 , V_5 -> V_58 ) ;
V_52 = F_13 ( V_55 , V_5 -> V_58 ) ;
}
V_49 -> V_50 = V_50 ;
V_49 -> V_51 = V_51 ;
V_49 -> V_53 = V_53 ;
V_49 -> V_52 = V_52 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_2 V_59 [ 128 ] ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_60 * V_61 ;
int V_62 ;
V_61 = (struct V_60 * ) ( & V_8 -> V_63 ) ;
V_62 = sprintf ( V_59 , L_3 ,
V_61 -> V_64 , V_61 -> V_65 ,
V_61 -> V_66 , V_61 -> V_67 ) ;
return V_62 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_68 * V_69 ,
T_2 * V_70 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_60 * V_61 ;
int V_62 ;
if ( V_69 -> V_71 != 0 )
return - V_72 ;
V_69 -> V_73 = V_8 -> V_29 -> V_74 ;
V_61 = (struct V_60 * ) ( & V_8 -> V_63 ) ;
V_62 =
sprintf ( ( char * ) V_70 ,
L_3 ,
V_61 -> V_64 , V_61 -> V_65 ,
V_61 -> V_66 , V_61 -> V_67 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_75 , int V_76 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_77 V_78 ;
struct V_79 V_80 ;
int V_81 = 0 ;
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . V_82 . V_83 = 0 ;
V_78 . V_82 . V_12 . V_84 = V_85 ;
V_78 . V_82 . V_12 . V_86 = V_5 -> V_10 . V_58 ;
V_78 . V_82 . V_12 . V_87 = V_75 ;
V_78 . V_82 . V_12 . V_88 = V_76 ;
V_78 . V_89 = 100 ;
V_78 . V_90 = ( V_83 ) V_2 ;
V_78 . V_91 = V_92 ;
V_80 . V_93 = V_94 ;
V_81 = F_17 ( V_5 -> V_8 , & V_78 , V_80 ) ;
if ( V_81 < 0 ) {
F_3 ( & V_7 -> V_29 -> V_30 , L_4 ) ;
return - V_72 ;
}
return 0 ;
}
static void F_18 ( struct V_6 * V_7 ,
T_1 V_31 ,
void * V_59 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_100 = (struct V_99 * ) V_59 ;
V_96 = (struct V_95 * ) V_100 -> V_101 ;
V_98 = (struct V_97 * ) V_100 -> V_102 ;
V_7 = F_19 ( V_98 -> V_103 ) ;
if ( V_31 ) {
F_3 ( & V_7 -> V_29 -> V_30 , L_5 ,
F_20 ( V_31 ) ) ;
F_21 ( V_98 -> V_104 ) = - 1 ;
} else {
F_21 ( V_98 -> V_104 ) = 1 ;
}
F_22 ( & V_98 -> V_105 ) ;
}
static int
F_23 ( struct V_5 * V_5 , int V_106 , int V_107 , int * V_108 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_99 * V_100 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_109 * V_110 ;
int V_111 = 0 ;
V_100 = (struct V_99 * )
F_24 ( V_8 ,
sizeof( struct V_109 ) ,
sizeof( struct V_95 ) ,
sizeof( struct V_97 ) ) ;
if ( ! V_100 )
return - V_112 ;
V_98 = (struct V_97 * ) V_100 -> V_102 ;
V_96 = (struct V_95 * ) V_100 -> V_101 ;
V_110 = (struct V_109 * ) V_100 -> V_113 ;
F_21 ( V_98 -> V_104 ) = 0 ;
V_98 -> V_103 = F_25 ( V_8 ) ;
V_110 -> V_106 = V_106 ;
V_110 -> V_114 = V_107 ;
if ( V_106 )
V_110 -> V_115 = * V_108 ;
V_110 -> V_116 = V_5 -> V_10 . V_58 ;
F_26 ( ( V_83 * ) V_110 , sizeof( struct V_109 ) / 8 ) ;
F_27 ( V_8 , V_100 , V_117 , V_118 ,
0 , 0 , 0 ) ;
V_100 -> V_89 = 1000 ;
V_100 -> V_119 = F_18 ;
V_100 -> V_120 = V_100 ;
F_28 ( & V_98 -> V_105 ) ;
V_111 = F_29 ( V_8 , V_100 ) ;
if ( V_111 ) {
F_3 ( & V_8 -> V_29 -> V_30 ,
L_6 ,
V_111 ) ;
V_111 = - V_121 ;
} else {
F_30 ( & V_98 -> V_105 , & V_98 -> V_104 ) ;
V_111 = V_96 -> V_31 ;
if ( V_111 ) {
F_3 ( & V_8 -> V_29 -> V_30 , L_7 ) ;
V_111 = - V_121 ;
} else {
F_26 ( ( V_83 * ) ( & V_96 -> V_122 ) ,
sizeof( struct V_109 ) / 8 ) ;
if ( F_21 ( V_98 -> V_104 ) == 1 ) {
if ( ! V_106 )
* V_108 = V_96 -> V_122 . V_115 ;
} else {
V_111 = - V_72 ;
}
}
}
F_31 ( V_8 , V_100 ) ;
return V_111 ;
}
static int F_32 ( struct V_1 * V_2 ,
enum V_123 V_124 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_108 , V_81 ;
switch ( V_124 ) {
case V_125 :
if ( V_7 -> V_126 == V_127 ) {
F_16 ( V_2 , V_128 ,
V_129 ) ;
return 2 ;
} else if ( V_7 -> V_126 == V_130 ) {
V_81 = F_23 ( V_5 , 0 ,
V_131 ,
& V_5 -> V_132 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_23 ( V_5 , 0 ,
V_133 ,
& V_5 -> V_134 ) ;
if ( V_81 )
return V_81 ;
V_108 = V_135 ;
V_81 =
F_23 ( V_5 , 1 ,
V_131 ,
& V_108 ) ;
if ( V_81 )
return V_81 ;
V_108 = V_136 ;
V_81 =
F_23 ( V_5 , 1 ,
V_133 ,
& V_108 ) ;
if ( V_81 )
return V_81 ;
} else {
return - V_72 ;
}
break;
case V_137 :
if ( V_7 -> V_126 == V_127 ) {
F_16 ( V_2 , V_128 ,
V_138 ) ;
} else if ( V_7 -> V_126 == V_130 ) {
return - V_72 ;
} else {
return - V_72 ;
}
break;
case V_139 :
if ( V_7 -> V_126 == V_127 )
F_16 ( V_2 , V_128 ,
V_140 ) ;
else if ( V_7 -> V_126 == V_130 )
return - V_72 ;
else
return - V_72 ;
break;
case V_141 :
if ( V_7 -> V_126 == V_127 ) {
F_16 ( V_2 , V_128 ,
V_142 ) ;
} else if ( V_7 -> V_126 == V_130 ) {
V_81 = F_23 ( V_5 , 1 ,
V_133 ,
& V_5 -> V_134 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_23 ( V_5 , 1 ,
V_131 ,
& V_5 -> V_132 ) ;
if ( V_81 )
return V_81 ;
} else {
return - V_72 ;
}
break;
default:
return - V_72 ;
}
return 0 ;
}
static void
F_33 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_145 = 0 , V_146 = 0 , V_147 = 0 ,
V_148 = 0 ;
if ( F_8 ( V_7 ) ) {
struct V_54 * V_55 = F_9 ( V_7 , V_56 , V_57 ) ;
V_145 = V_149 ;
V_146 = V_150 ;
V_148 = F_34 ( V_55 , V_5 -> V_58 ) ;
V_147 = F_35 ( V_55 , V_5 -> V_58 ) ;
}
if ( V_5 -> V_151 > V_152 ) {
V_144 -> V_148 = 0 ;
V_144 -> V_146 = 0 ;
V_144 -> V_153 = 0 ;
V_144 -> V_154 = V_148 ;
V_144 -> V_155 = 0 ;
V_144 -> V_156 = V_146 ;
} else {
V_144 -> V_148 = V_148 ;
V_144 -> V_146 = V_146 ;
V_144 -> V_153 = 0 ;
V_144 -> V_154 = 0 ;
V_144 -> V_155 = 0 ;
V_144 -> V_156 = 0 ;
}
V_144 -> V_147 = V_147 ;
V_144 -> V_145 = V_145 ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_157 ;
}
static void F_37 ( struct V_1 * V_2 , T_1 V_158 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( ( V_158 ^ V_5 -> V_157 ) & V_159 ) {
if ( V_158 & V_159 )
F_38 ( V_2 ,
V_160 ) ;
else
F_38 ( V_2 ,
V_161 ) ;
}
V_5 -> V_157 = V_158 ;
}
static void
F_39 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
V_163 -> V_164 = 1 ;
V_163 -> V_165 = 1 ;
}
static void
F_40 ( struct V_1 * V_2 ,
struct V_166 * V_167 , V_83 * V_168 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
int V_169 = 0 , V_170 ;
for ( V_170 = 0 ; V_170 < V_171 ; V_170 ++ ) {
if ( ! ( V_8 -> V_172 . V_173 & ( 1UL << V_170 ) ) )
continue;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_174 [ V_170 ] -> V_167 . V_175 ) ;
V_168 [ V_169 ++ ] =
F_20 (
V_8 -> V_174 [ V_170 ] -> V_167 . V_176 ) ;
V_168 [ V_169 ++ ] =
F_20 (
V_8 -> V_174 [ V_170 ] -> V_167 . V_177 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_174 [ V_170 ] -> V_167 . V_178 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_174 [ V_170 ] -> V_167 . V_179 ) ;
V_168 [ V_169 ++ ] =
F_41 ( V_8 -> V_174 [ V_170 ] -> V_180 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_174 [ V_170 ] -> V_167 . V_181 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_174 [ V_170 ] -> V_167 . V_182 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_174 [ V_170 ] -> V_167 . V_183 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_174 [ V_170 ] -> V_167 . V_184 ) ;
}
for ( V_170 = 0 ; V_170 < V_185 ; V_170 ++ ) {
if ( ! ( V_8 -> V_172 . V_186 & ( 1UL << V_170 ) ) )
continue;
V_168 [ V_169 ++ ] = F_20 ( V_8 -> V_187 [ V_170 ] -> V_167 . V_188 ) ;
V_168 [ V_169 ++ ] = F_20 ( V_8 -> V_187 [ V_170 ] -> V_167 . V_189 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_187 [ V_170 ] -> V_167 . V_190 ) ;
V_168 [ V_169 ++ ] = F_20 ( V_8 -> V_187 [ V_170 ] -> V_167 . V_191 ) ;
V_168 [ V_169 ++ ] = F_20 ( V_8 -> V_187 [ V_170 ] -> V_167 . V_192 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_187 [ V_170 ] -> V_167 . V_193 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_187 [ V_170 ] -> V_167 . V_194 ) ;
V_168 [ V_169 ++ ] =
F_20 ( V_8 -> V_187 [ V_170 ] -> V_167 . V_195 ) ;
}
}
static void F_42 ( struct V_1 * V_2 , T_1 V_196 , T_2 * V_168 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
int V_197 , V_198 , V_169 , V_170 ;
V_197 = F_43 ( V_199 ) ;
for ( V_169 = 0 ; V_169 < V_171 ; V_169 ++ ) {
if ( ! ( V_8 -> V_172 . V_173 & ( 1UL << V_169 ) ) )
continue;
for ( V_170 = 0 ; V_170 < V_197 ; V_170 ++ ) {
sprintf ( V_168 , L_8 , V_169 , V_199 [ V_170 ] ) ;
V_168 += V_200 ;
}
}
V_198 = F_43 ( V_201 ) ;
for ( V_169 = 0 ; V_169 < V_185 ; V_169 ++ ) {
if ( ! ( V_8 -> V_172 . V_186 & ( 1UL << V_169 ) ) )
continue;
for ( V_170 = 0 ; V_170 < V_198 ; V_170 ++ ) {
sprintf ( V_168 , L_9 , V_169 , V_201 [ V_170 ] ) ;
V_168 += V_200 ;
}
}
}
static int F_44 ( struct V_1 * V_2 , int V_202 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
return ( F_43 ( V_199 ) * V_8 -> V_203 ) +
( F_43 ( V_201 ) * V_8 -> V_204 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_205 * V_206 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_207 * V_56 = (struct V_207 * ) V_7 -> V_208 ;
struct V_209 * V_173 ;
struct V_210 * V_211 ;
V_211 = & V_7 -> V_212 ;
switch ( V_7 -> V_126 ) {
case V_130 :
case V_127 :
if ( ! V_211 -> V_213 ) {
V_206 -> V_214 =
F_46 ( V_56 -> V_57 ) ;
V_206 -> V_215 =
F_47 ( V_56 -> V_57 ) ;
} else {
V_206 -> V_216 =
V_211 -> V_213 ;
V_206 -> V_217 =
V_211 -> V_218 ;
V_206 -> V_219 =
V_211 -> V_220 ;
V_206 -> V_221 =
V_211 -> V_222 ;
V_206 -> V_223 =
V_211 -> V_224 ;
V_206 -> V_225 =
V_211 -> V_226 ;
V_206 -> V_227 =
V_211 -> V_228 ;
V_206 -> V_229 =
V_211 -> V_230 ;
}
V_173 = V_7 -> V_174 [ V_5 -> V_10 . V_231 [ 0 ] ] ;
V_206 -> V_232 = V_173 -> V_233 ;
break;
default:
F_48 ( V_5 , V_234 , V_5 -> V_2 , L_10 ) ;
return - V_72 ;
}
return 0 ;
}
static void F_49 ( struct V_6 * V_8 ,
T_1 V_31 ,
void * V_235 )
{
struct V_236 * V_84 = V_235 ;
struct V_99 * V_100 = V_84 -> V_100 ;
V_8 = V_84 -> V_8 ;
if ( V_31 )
F_3 ( & V_8 -> V_29 -> V_30 , L_11 ,
F_20 ( V_31 ) ) ;
else
F_50 ( & V_8 -> V_29 -> V_30 ,
L_12 ,
V_8 -> V_212 . V_213 ) ;
F_31 ( V_8 , V_100 ) ;
}
static int F_51 ( void * V_7 , struct V_210 * V_237 )
{
struct V_99 * V_100 ;
struct V_236 * V_84 ;
struct V_210 * V_238 ;
int V_111 ;
struct V_6 * V_8 = (struct V_6 * ) V_7 ;
V_100 = (struct V_99 * )
F_24 ( V_8 ,
sizeof( struct V_210 ) ,
0 ,
sizeof( struct V_236 ) ) ;
if ( ! V_100 )
return - V_112 ;
V_84 = (struct V_236 * ) V_100 -> V_102 ;
V_238 = (struct V_210 * ) V_100 -> V_113 ;
memcpy ( V_238 , V_237 , sizeof( struct V_210 ) ) ;
F_26 ( ( V_83 * ) V_238 , ( sizeof( struct V_210 ) ) / 8 ) ;
V_84 -> V_100 = V_100 ;
V_84 -> V_238 = V_238 ;
V_84 -> V_8 = V_8 ;
F_27 ( V_8 , V_100 , V_117 ,
V_239 , 0 , 0 , 0 ) ;
V_100 -> V_119 = F_49 ;
V_100 -> V_120 = V_84 ;
V_100 -> V_89 = 1000 ;
V_111 = F_29 ( V_8 , V_100 ) ;
if ( V_111 ) {
F_31 ( V_8 , V_100 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_52 ( struct V_5 * V_5 , struct V_205
* V_206 , int V_240 )
{
int V_81 = 0 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_210 * V_211 ;
V_211 = & V_7 -> V_212 ;
if ( V_240 ) {
if ( V_206 -> V_217 )
V_211 -> V_218 =
V_206 -> V_217 ;
else
V_211 -> V_218 =
V_241 ;
if ( V_206 -> V_219 )
V_211 -> V_220 =
V_206 -> V_219 ;
else
V_211 -> V_220 =
V_242 ;
if ( V_206 -> V_221 )
V_211 -> V_222 =
V_206 -> V_221 ;
else
V_211 -> V_222 =
V_243 ;
if ( V_206 -> V_223 )
V_211 -> V_224 =
V_206 -> V_223 ;
else
V_211 -> V_224 =
V_244 ;
if ( V_206 -> V_225 )
V_211 -> V_226 =
V_206 -> V_225 ;
else
V_211 -> V_226 =
V_245 ;
if ( V_206 -> V_227 )
V_211 -> V_228 =
V_206 -> V_227 ;
else
V_211 -> V_228 =
V_246 ;
if ( V_206 -> V_229 )
V_211 -> V_230 =
V_206 -> V_229 ;
else
V_211 -> V_230 =
V_247 ;
}
V_211 -> V_213 = V_240 ;
V_81 = F_51 ( V_7 , V_211 ) ;
return V_81 ;
}
static int
F_53 ( struct V_5 * V_5 , struct V_205 * V_206 )
{
int V_81 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_207 * V_56 = (struct V_207 * ) V_7 -> V_208 ;
T_1 V_215 ;
if ( ! V_206 -> V_215 )
V_215 = V_248 ;
else
V_215 = V_206 -> V_215 ;
V_81 = F_52 ( V_5 , V_206 , 0 ) ;
if ( V_81 )
return V_81 ;
F_54 ( V_7 , V_249 ,
V_215 ) ;
F_55 ( V_56 -> V_57 , V_215 ) ;
return 0 ;
}
static int F_56 ( struct V_5 * V_5 , struct V_205
* V_206 )
{
int V_81 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_207 * V_56 = (struct V_207 * ) V_7 -> V_208 ;
T_1 V_250 , V_214 ;
if ( ! V_206 -> V_214 )
V_214 = V_251 ;
else
V_214 = V_206 -> V_214 ;
V_81 = F_52 ( V_5 , V_206 , 0 ) ;
if ( V_81 )
return V_81 ;
V_250 = F_57 ( V_7 , V_214 ) ;
F_54 ( V_7 , V_252 , V_250 ) ;
F_58 ( V_56 -> V_57 , V_214 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_205 * V_206 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_81 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_170 , V_253 ;
if ( ( V_206 -> V_232 >= V_254 ) &&
( V_206 -> V_232 <= V_255 ) ) {
for ( V_170 = 0 ; V_170 < V_5 -> V_10 . V_256 ; V_170 ++ ) {
V_253 = V_5 -> V_10 . V_231 [ V_170 ] ;
V_7 -> V_174 [ V_253 ] -> V_233 =
V_206 -> V_232 ;
}
} else {
F_3 ( & V_7 -> V_29 -> V_30 ,
L_13 ,
V_206 -> V_232 , V_254 ,
V_255 ) ;
return - V_72 ;
}
if ( V_206 -> V_216 ) {
V_81 = F_52 ( V_5 , V_206 , 1 ) ;
if ( V_81 )
goto V_257;
}
if ( ( V_206 -> V_214 ) &&
( ! V_206 -> V_216 ) ) {
V_81 = F_56 ( V_5 , V_206 ) ;
if ( V_81 )
goto V_257;
}
if ( ( V_206 -> V_215 ) &&
( ! V_206 -> V_216 ) ) {
V_81 = F_53 ( V_5 , V_206 ) ;
if ( V_81 )
goto V_257;
}
if ( ( ! V_206 -> V_215 ) &&
( ! V_206 -> V_216 ) &&
( ! V_206 -> V_214 ) ) {
F_50 ( & V_7 -> V_29 -> V_30 ,
L_14 ) ;
F_50 ( & V_7 -> V_29 -> V_30 ,
L_15 ,
V_251 , V_248 ) ;
V_81 = F_56 ( V_5 , V_206 ) ;
if ( V_81 )
goto V_257;
V_81 = F_53 ( V_5 , V_206 ) ;
if ( V_81 )
goto V_257;
}
return 0 ;
V_257:
return V_81 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_258 * V_259 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
V_259 -> V_260 =
V_261 |
V_262 |
V_263 |
V_264 |
V_265 | V_266 ;
if ( V_5 -> V_267 )
V_259 -> V_268 = F_61 ( V_5 -> V_267 ) ;
else
V_259 -> V_268 = - 1 ;
V_259 -> V_269 = ( 1 << V_270 ) | ( 1 << V_271 ) ;
V_259 -> V_272 = ( 1 << V_273 ) |
( 1 << V_274 ) |
( 1 << V_275 ) |
( 1 << V_276 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 ;
struct V_77 V_78 ;
struct V_79 V_80 ;
int V_81 = 0 ;
V_10 = & V_5 -> V_10 ;
if ( V_4 -> V_27 != V_277 && V_4 -> V_27 != V_28 )
return - V_72 ;
if ( V_4 -> V_27 == V_28 && ( ( V_4 -> V_32 != V_278 &&
V_4 -> V_32 != V_279 ) ||
( V_4 -> V_33 != V_280 &&
V_4 -> V_33 != V_281 ) ) )
return - V_72 ;
if ( V_10 -> V_11 . V_12 . V_13 == V_14 ||
V_10 -> V_11 . V_12 . V_13 == V_15 ) {
F_50 ( & V_7 -> V_29 -> V_30 , L_16 ) ;
return - V_72 ;
}
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 . V_82 . V_83 = 0 ;
V_78 . V_82 . V_12 . V_84 = V_282 ;
V_78 . V_89 = 1000 ;
V_78 . V_90 = ( V_83 ) V_2 ;
V_78 . V_82 . V_12 . V_86 = V_5 -> V_10 . V_58 ;
V_78 . V_91 = V_92 ;
if ( V_4 -> V_27 == V_277 ) {
V_78 . V_82 . V_12 . V_283 = V_284 |
V_285 ;
V_78 . V_82 . V_12 . V_87 = V_4 -> V_22 ;
} else {
V_78 . V_82 . V_12 . V_283 = V_284 ;
V_78 . V_82 . V_12 . V_88 = V_4 -> V_33 ;
V_78 . V_82 . V_12 . V_87 = V_4 -> V_32 ;
}
V_80 . V_93 = V_94 ;
V_81 = F_17 ( V_5 -> V_8 , & V_78 , V_80 ) ;
if ( V_81 < 0 ) {
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
return V_47 ;
}
static int F_66 ( char * V_12 , struct V_6 * V_7 )
{
T_1 V_286 ;
int V_169 , V_62 = 0 ;
V_62 += sprintf ( V_12 + V_62 , L_18 ) ;
V_286 = V_287 ;
V_62 += sprintf ( V_12 + V_62 , L_19 ,
V_287 , F_67 ( V_7 , V_286 ) ) ;
V_286 = V_288 ;
V_62 += sprintf ( V_12 + V_62 , L_20 ,
V_288 , F_67 ( V_7 , V_286 ) ) ;
V_286 = V_289 ;
V_62 += sprintf ( V_12 + V_62 , L_21 ,
V_289 , F_67 ( V_7 , V_286 ) ) ;
V_286 = V_290 ;
V_62 += sprintf ( V_12 + V_62 , L_22 ,
V_290 , F_67 ( V_7 , V_286 ) ) ;
V_286 = V_291 ;
V_62 += sprintf ( V_12 + V_62 , L_23 ,
V_291 , F_67 ( V_7 , V_286 ) ) ;
V_286 = V_292 ;
V_62 += sprintf ( V_12 + V_62 , L_24 ,
V_292 , F_67 ( V_7 , V_286 ) ) ;
V_62 += sprintf ( V_12 + V_62 , L_25 ,
V_293 ,
F_67 ( V_7 , V_293 ) ) ;
V_62 += sprintf ( V_12 + V_62 , L_26 ,
V_294 , F_67 ( V_7 ,
V_294 ) ) ;
V_62 += sprintf ( V_12 + V_62 , L_27 ,
V_295 ,
F_67 ( V_7 , V_295 ) ) ;
V_62 += sprintf ( V_12 + V_62 , L_28 , V_296 ,
F_67 ( V_7 , V_296 ) ) ;
for ( V_169 = 0 ; V_169 < V_7 -> V_204 ; V_169 ++ ) {
V_286 = F_68 ( V_169 ) ;
V_62 += sprintf ( V_12 + V_62 , L_29 ,
V_286 , V_169 , F_67 ( V_7 , V_286 ) ) ;
V_286 = F_69 ( V_169 ) ;
V_62 += sprintf ( V_12 + V_62 , L_30 ,
V_286 , V_169 , F_67 ( V_7 , V_286 ) ) ;
}
V_286 = V_249 ;
V_62 += sprintf ( V_12 + V_62 , L_31 ,
V_286 , F_67 ( V_7 , V_286 ) ) ;
V_286 = V_252 ;
V_62 += sprintf ( V_12 + V_62 , L_32 ,
V_286 , F_67 ( V_7 , V_286 ) ) ;
for ( V_169 = 0 ; V_169 <= 3 ; V_169 ++ ) {
T_1 V_286 ;
V_286 = F_70 ( V_169 ) ;
V_62 += sprintf ( V_12 + V_62 , L_33 ,
V_286 , V_169 , F_67 ( V_7 , V_286 ) ) ;
V_286 = F_71 ( V_169 ) ;
V_62 += sprintf ( V_12 + V_62 , L_34 ,
V_286 , V_169 , F_67 ( V_7 , V_286 ) ) ;
}
V_62 += sprintf ( V_12 + V_62 , L_35 ,
F_72 ( 0 ) ,
F_67 ( V_7 , F_72 ( 0 ) ) ) ;
V_286 = F_73 ( 0 ) ;
V_62 += sprintf ( V_12 + V_62 , L_36 ,
F_73 ( 0 ) , F_67 ( V_7 , V_286 ) ) ;
V_286 = F_74 ( 0 ) ;
V_62 += sprintf ( V_12 + V_62 , L_37 ,
F_74 ( 0 ) ,
F_67 ( V_7 , V_286 ) ) ;
V_62 += sprintf ( V_12 + V_62 , L_38 ,
F_72 ( 1 ) ,
F_67 ( V_7 , F_72 ( 1 ) ) ) ;
V_286 = F_73 ( 1 ) ;
V_62 += sprintf ( V_12 + V_62 , L_39 ,
F_73 ( 1 ) ,
F_67 ( V_7 , V_286 ) ) ;
V_286 = F_73 ( 1 ) ;
V_62 += sprintf ( V_12 + V_62 , L_40 ,
F_74 ( 1 ) ,
F_67 ( V_7 , V_286 ) ) ;
V_62 += sprintf ( V_12 + V_62 , L_41 ) ;
for ( V_169 = 0 ; V_169 < 16 ; V_169 ++ ) {
V_286 = F_75 ( V_7 , F_76 ( V_169 , V_7 -> V_297 ) ) ;
V_62 += sprintf ( V_12 + V_62 , L_42 ,
F_76 ( V_169 , V_7 -> V_297 ) , V_169 , V_286 ) ;
}
return V_62 ;
}
static int F_77 ( char * V_12 , struct V_6 * V_7 )
{
T_1 V_76 ;
int V_169 , V_62 = 0 ;
V_62 += sprintf ( V_12 + V_62 ,
L_43 ) ;
for ( V_169 = 0 ; V_169 <= 13 ; V_169 ++ ) {
F_78 ( V_7 -> V_29 , ( V_169 * 4 ) , & V_76 ) ;
V_62 += sprintf ( V_12 + V_62 , L_44 ,
( V_169 * 4 ) , V_169 , V_76 ) ;
}
for ( V_169 = 30 ; V_169 <= 34 ; V_169 ++ ) {
F_78 ( V_7 -> V_29 , ( V_169 * 4 ) , & V_76 ) ;
V_62 += sprintf ( V_12 + V_62 , L_44 ,
( V_169 * 4 ) , V_169 , V_76 ) ;
}
return V_62 ;
}
static void F_79 ( struct V_1 * V_30 ,
struct V_298 * V_299 , void * V_300 )
{
struct V_5 * V_5 = F_2 ( V_30 ) ;
int V_62 = 0 ;
struct V_6 * V_7 = V_5 -> V_8 ;
memset ( V_300 , 0 , V_47 ) ;
V_299 -> V_39 = V_301 ;
switch ( V_7 -> V_126 ) {
case V_130 :
case V_127 :
V_62 += F_66 ( V_300 + V_62 , V_7 ) ;
V_62 += F_77 ( V_300 + V_62 , V_7 ) ;
break;
default:
F_3 ( & V_7 -> V_29 -> V_30 , L_45 ,
V_302 , V_7 -> V_126 ) ;
}
}
void F_80 ( struct V_1 * V_2 )
{
V_2 -> V_303 = & V_304 ;
}
