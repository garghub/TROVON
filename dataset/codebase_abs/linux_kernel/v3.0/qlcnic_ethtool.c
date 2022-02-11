static int F_1 ( struct V_1 * V_2 )
{
return sizeof( V_3 ) + V_4 +
V_5 + 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return V_6 ;
}
static void
F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_11 , V_12 , V_13 ;
V_11 = F_5 ( V_10 , V_14 ) ;
V_12 = F_5 ( V_10 , V_15 ) ;
V_13 = F_5 ( V_10 , V_16 ) ;
sprintf ( V_8 -> V_17 , L_1 , V_11 , V_12 , V_13 ) ;
F_6 ( V_8 -> V_18 , F_7 ( V_10 -> V_19 ) , 32 ) ;
F_6 ( V_8 -> V_20 , V_21 , 32 ) ;
F_6 ( V_8 -> V_22 , V_23 , 32 ) ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_26 = 0 ;
T_2 V_27 = V_10 -> V_28 -> V_29 ;
if ( V_10 -> V_28 -> V_30 == V_31 ) {
V_25 -> V_32 = ( V_33 |
V_34 |
V_35 |
V_36 |
V_37 |
V_38 ) ;
V_25 -> V_39 = ( V_40 |
V_41 |
V_42 |
V_43 ) ;
F_9 ( V_25 , V_10 -> V_44 ) ;
V_25 -> V_45 = V_10 -> V_46 ;
V_25 -> V_47 = V_10 -> V_48 ;
} else if ( V_10 -> V_28 -> V_30 == V_49 ) {
T_1 V_50 ;
V_50 = F_5 ( V_10 , V_51 ) ;
if ( V_50 == V_52 ) {
V_25 -> V_32 = V_38 ;
V_25 -> V_39 = V_43 ;
} else {
V_25 -> V_32 = V_53 ;
V_25 -> V_39 = V_54 ;
}
if ( F_10 ( V_2 ) && V_10 -> V_55 ) {
F_9 ( V_25 , V_10 -> V_44 ) ;
V_25 -> V_47 = V_10 -> V_48 ;
V_25 -> V_45 = V_10 -> V_46 ;
goto V_56;
}
V_50 = F_5 ( V_10 , F_11 ( V_27 ) ) ;
F_9 ( V_25 , V_57 *
F_12 ( V_27 , V_50 ) ) ;
V_25 -> V_45 = V_58 ;
V_25 -> V_47 = V_59 ;
} else
return - V_60 ;
V_56:
V_25 -> V_61 = V_10 -> V_62 ;
V_25 -> V_63 = V_64 ;
switch ( V_10 -> V_28 -> V_65 ) {
case V_66 :
case V_67 :
case V_68 :
V_25 -> V_32 |= V_69 ;
V_25 -> V_39 |= V_70 ;
case V_71 :
case V_72 :
case V_73 :
V_25 -> V_32 |= V_74 ;
V_25 -> V_39 |= V_75 ;
V_25 -> V_76 = V_77 ;
V_25 -> V_47 = V_10 -> V_48 ;
break;
case V_78 :
case V_79 :
case V_80 :
V_25 -> V_32 |= V_81 ;
V_25 -> V_39 |= V_82 ;
V_25 -> V_76 = V_83 ;
V_25 -> V_47 = V_59 ;
break;
case V_84 :
case V_85 :
case V_86 :
V_25 -> V_39 |= V_75 ;
V_25 -> V_32 |= V_74 ;
V_26 = F_10 ( V_2 ) &&
V_10 -> V_55 ;
case V_87 :
V_25 -> V_32 |= V_88 ;
V_25 -> V_39 |= V_89 ;
V_25 -> V_76 = V_90 ;
V_25 -> V_47 = V_59 ;
break;
case V_91 :
if ( V_10 -> V_28 -> V_30 == V_49 ) {
V_25 -> V_47 = V_59 ;
V_25 -> V_32 |= ( V_88 | V_74 ) ;
V_25 -> V_39 |=
( V_89 | V_75 ) ;
V_25 -> V_76 = V_90 ;
V_26 = F_10 ( V_2 ) &&
V_10 -> V_55 ;
} else {
V_25 -> V_47 = V_92 ;
V_25 -> V_32 |= ( V_74 | V_69 ) ;
V_25 -> V_39 |=
( V_75 | V_70 ) ;
V_25 -> V_76 = V_77 ;
}
break;
default:
F_13 ( & V_10 -> V_19 -> V_2 , L_2 ,
V_10 -> V_28 -> V_65 ) ;
return - V_60 ;
}
if ( V_26 ) {
switch ( V_10 -> V_93 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
V_25 -> V_76 = V_90 ;
break;
case V_98 :
case V_99 :
case V_100 :
V_25 -> V_76 = V_77 ;
break;
default:
V_25 -> V_76 = V_101 ;
}
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
T_1 V_102 = 0 ;
T_1 V_103 = 0 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_28 -> V_30 != V_31 )
return - V_104 ;
if ( V_25 -> V_45 )
V_102 |= 0x1 ;
if ( V_25 -> V_47 )
V_102 |= 0x2 ;
switch ( F_15 ( V_25 ) ) {
case V_105 :
V_102 |= ( 0 << 8 ) ;
break;
case V_106 :
V_102 |= ( 1 << 8 ) ;
break;
case V_107 :
V_102 |= ( 10 << 8 ) ;
break;
default:
return - V_60 ;
}
V_103 = F_16 ( V_10 , V_102 ) ;
if ( V_103 == V_108 )
return - V_104 ;
else if ( V_103 )
return - V_60 ;
V_10 -> V_44 = F_15 ( V_25 ) ;
V_10 -> V_46 = V_25 -> V_45 ;
V_10 -> V_48 = V_25 -> V_47 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
V_2 -> V_109 -> V_110 ( V_2 ) ;
return V_2 -> V_109 -> V_111 ( V_2 ) ;
}
static void
F_17 ( struct V_1 * V_2 , struct V_112 * V_113 , void * V_114 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_115 * V_116 = V_10 -> V_116 ;
struct V_117 * V_118 ;
T_1 * V_119 = V_114 ;
int V_120 , V_121 = 0 , V_122 = 0 ;
memset ( V_114 , 0 , F_1 ( V_2 ) ) ;
V_113 -> V_22 = ( V_123 << 24 ) |
( V_10 -> V_28 -> V_124 << 16 ) | ( V_10 -> V_19 ) -> V_125 ;
V_119 [ 0 ] = ( 0xcafe0000 | ( V_5 & 0xffff ) ) ;
V_119 [ 1 ] = V_126 ;
for ( V_121 = V_5 + 1 ; V_3 [ V_122 ] != - 1 ; V_122 ++ , V_121 ++ )
V_119 [ V_121 ] = F_5 ( V_10 , V_3 [ V_122 ] ) ;
if ( ! F_18 ( V_127 , & V_10 -> V_128 ) )
return;
V_119 [ V_121 ++ ] = 0xFFEFCDAB ;
V_119 [ V_121 ++ ] = 1 ;
V_119 [ V_121 ++ ] = F_19 ( * ( V_10 -> V_129 -> V_130 ) ) ;
V_119 [ V_121 ++ ] = F_20 ( V_10 -> V_129 -> V_131 ) ;
V_119 [ V_121 ++ ] = 2 ;
V_119 [ V_121 ++ ] = F_20 ( V_116 -> V_132 [ 0 ] . V_133 ) ;
V_119 [ V_121 ++ ] = F_20 ( V_116 -> V_132 [ 1 ] . V_133 ) ;
V_119 [ V_121 ++ ] = V_10 -> V_134 ;
for ( V_120 = 0 ; V_120 < V_10 -> V_134 ; V_120 ++ ) {
V_118 = & ( V_116 -> V_135 [ V_120 ] ) ;
V_119 [ V_121 ++ ] = F_20 ( V_118 -> V_136 ) ;
}
}
static T_1 F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_50 ;
V_50 = F_5 ( V_10 , V_137 ) ;
V_50 = F_22 ( V_10 -> V_28 -> V_29 , V_50 ) ;
return ( V_50 == V_138 ) ? 0 : 1 ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_139 * V_140 ,
T_3 * V_141 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_142 ;
int V_103 ;
if ( V_140 -> V_143 == 0 )
return - V_144 ;
V_140 -> V_145 = ( V_10 -> V_19 ) -> V_146 |
( ( V_10 -> V_19 ) -> V_125 << 16 ) ;
V_142 = V_140 -> V_142 ;
V_103 = F_24 ( V_10 , V_142 , V_141 ,
V_140 -> V_143 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
static void
F_25 ( struct V_1 * V_2 ,
struct V_147 * V_120 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
V_120 -> V_148 = V_10 -> V_149 ;
V_120 -> V_150 = V_10 -> V_151 ;
V_120 -> V_152 = V_10 -> V_153 ;
V_120 -> V_154 = V_10 -> V_155 ;
V_120 -> V_156 = V_10 -> V_157 ;
V_120 -> V_158 = V_159 ;
V_120 -> V_160 = 0 ;
V_120 -> V_161 = 0 ;
}
static T_1
F_26 ( T_1 V_50 , T_1 V_162 , T_1 V_163 , char * V_164 )
{
T_1 V_165 ;
V_165 = V_163 ( V_50 , V_162 ) ;
V_165 = V_162 ( V_165 , V_163 ) ;
V_165 = F_27 ( V_165 ) ;
if ( V_50 != V_165 ) {
F_28 ( V_166 L_3 ,
V_21 , V_164 , V_165 , V_50 ) ;
}
return V_165 ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_147 * V_120 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_2 V_149 , V_151 , V_153 ;
if ( V_120 -> V_161 )
return - V_104 ;
V_149 = F_26 ( V_120 -> V_148 ,
V_167 , V_10 -> V_155 , L_4 ) ;
V_151 = F_26 ( V_120 -> V_150 ,
V_168 , V_10 -> V_157 ,
L_5 ) ;
V_153 = F_26 ( V_120 -> V_152 ,
V_169 , V_159 , L_6 ) ;
if ( V_149 == V_10 -> V_149 && V_153 == V_10 -> V_153 &&
V_151 == V_10 -> V_151 )
return 0 ;
V_10 -> V_149 = V_149 ;
V_10 -> V_151 = V_151 ;
V_10 -> V_153 = V_153 ;
return F_30 ( V_10 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_170 * V_171 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
V_171 -> V_172 = F_32 ( F_33 ( int ,
V_10 -> V_173 , F_34 () ) ) ;
V_171 -> V_174 = V_10 -> V_175 ;
V_171 -> V_176 = V_10 -> V_134 ;
V_171 -> V_177 = V_10 -> V_175 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_170 * V_171 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_178 ;
if ( V_171 -> V_179 || V_171 -> V_180 ||
V_171 -> V_177 != V_171 -> V_174 )
return - V_144 ;
V_178 = F_36 ( V_2 , V_171 -> V_172 , V_171 -> V_176 ) ;
if ( V_178 )
return V_178 ;
V_178 = F_37 ( V_10 , V_171 -> V_176 ) ;
F_38 ( V_2 , L_7 ,
V_10 -> V_134 ) ;
return V_178 ;
}
static void
F_39 ( struct V_1 * V_181 ,
struct V_182 * V_183 )
{
struct V_9 * V_10 = F_4 ( V_181 ) ;
int V_76 = V_10 -> V_62 ;
T_4 V_50 ;
if ( V_10 -> V_28 -> V_30 == V_31 ) {
if ( ( V_76 < 0 ) || ( V_76 > V_184 ) )
return;
V_50 = F_5 ( V_10 , F_40 ( V_76 ) ) ;
V_183 -> V_185 = F_41 ( V_50 ) ;
V_50 = F_5 ( V_10 , V_186 ) ;
switch ( V_76 ) {
case 0 :
V_183 -> V_187 = ! ( F_42 ( V_50 ) ) ;
break;
case 1 :
V_183 -> V_187 = ! ( F_43 ( V_50 ) ) ;
break;
case 2 :
V_183 -> V_187 = ! ( F_44 ( V_50 ) ) ;
break;
case 3 :
default:
V_183 -> V_187 = ! ( F_45 ( V_50 ) ) ;
break;
}
} else if ( V_10 -> V_28 -> V_30 == V_49 ) {
if ( ( V_76 < 0 ) || ( V_76 > V_188 ) )
return;
V_183 -> V_185 = 1 ;
V_50 = F_5 ( V_10 , V_189 ) ;
if ( V_76 == 0 )
V_183 -> V_187 = ! ( F_46 ( V_50 ) ) ;
else
V_183 -> V_187 = ! ( F_47 ( V_50 ) ) ;
} else {
F_13 ( & V_181 -> V_2 , L_8 ,
V_10 -> V_28 -> V_30 ) ;
}
}
static int
F_48 ( struct V_1 * V_181 ,
struct V_182 * V_183 )
{
struct V_9 * V_10 = F_4 ( V_181 ) ;
int V_76 = V_10 -> V_62 ;
T_4 V_50 ;
if ( V_10 -> V_28 -> V_30 == V_31 ) {
if ( ( V_76 < 0 ) || ( V_76 > V_184 ) )
return - V_60 ;
V_50 = F_5 ( V_10 , F_40 ( V_76 ) ) ;
if ( V_183 -> V_185 )
F_49 ( V_50 ) ;
else
F_50 ( V_50 ) ;
F_51 ( V_10 , F_40 ( V_76 ) ,
V_50 ) ;
V_50 = F_5 ( V_10 , V_186 ) ;
switch ( V_76 ) {
case 0 :
if ( V_183 -> V_187 )
F_52 ( V_50 ) ;
else
F_53 ( V_50 ) ;
break;
case 1 :
if ( V_183 -> V_187 )
F_54 ( V_50 ) ;
else
F_55 ( V_50 ) ;
break;
case 2 :
if ( V_183 -> V_187 )
F_56 ( V_50 ) ;
else
F_57 ( V_50 ) ;
break;
case 3 :
default:
if ( V_183 -> V_187 )
F_58 ( V_50 ) ;
else
F_59 ( V_50 ) ;
break;
}
F_51 ( V_10 , V_186 , V_50 ) ;
} else if ( V_10 -> V_28 -> V_30 == V_49 ) {
if ( ! V_183 -> V_185 || V_183 -> V_47 )
return - V_104 ;
if ( ( V_76 < 0 ) || ( V_76 > V_188 ) )
return - V_60 ;
V_50 = F_5 ( V_10 , V_189 ) ;
if ( V_76 == 0 ) {
if ( V_183 -> V_187 )
F_60 ( V_50 ) ;
else
F_61 ( V_50 ) ;
} else {
if ( V_183 -> V_187 )
F_62 ( V_50 ) ;
else
F_63 ( V_50 ) ;
}
F_51 ( V_10 , V_189 , V_50 ) ;
} else {
F_13 ( & V_181 -> V_2 , L_8 ,
V_10 -> V_28 -> V_30 ) ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_190 ;
V_190 = F_5 ( V_10 , F_65 ( 0 ) ) ;
if ( ( V_190 & 0xffff ) != V_10 -> V_19 -> V_146 )
return 1 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , int V_191 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
switch ( V_191 ) {
case V_192 :
return V_193 ;
case V_194 :
if ( V_10 -> V_195 & V_196 )
return V_197 + V_198 ;
return V_197 ;
default:
return - V_104 ;
}
}
static int F_67 ( struct V_1 * V_181 )
{
struct V_9 * V_10 = F_4 ( V_181 ) ;
int V_134 = V_10 -> V_134 ;
int V_103 ;
if ( F_68 ( V_199 , & V_10 -> V_128 ) )
return - V_60 ;
V_103 = F_69 ( V_181 , V_200 ) ;
if ( V_103 )
goto V_201;
V_10 -> V_202 = 0 ;
V_103 = F_70 ( V_10 , V_10 -> V_28 -> V_29 ,
V_10 -> V_203 , V_10 -> V_28 -> V_29 ,
0 , 0 , 0x00000011 ) ;
if ( V_103 )
goto V_204;
F_71 ( 10 ) ;
V_103 = ! V_10 -> V_202 ;
V_204:
F_72 ( V_181 , V_134 ) ;
V_201:
V_10 -> V_134 = V_134 ;
F_73 ( V_199 , & V_10 -> V_128 ) ;
return V_103 ;
}
static void
F_74 ( struct V_1 * V_2 , struct V_205 * V_206 ,
T_5 * V_207 )
{
memset ( V_207 , 0 , sizeof( T_5 ) * V_193 ) ;
V_207 [ 0 ] = F_64 ( V_2 ) ;
if ( V_207 [ 0 ] )
V_206 -> V_195 |= V_208 ;
V_207 [ 1 ] = ( T_5 ) F_21 ( V_2 ) ;
if ( V_207 [ 1 ] )
V_206 -> V_195 |= V_208 ;
if ( V_206 -> V_195 & V_209 ) {
V_207 [ 2 ] = F_67 ( V_2 ) ;
if ( V_207 [ 2 ] )
V_206 -> V_195 |= V_208 ;
}
}
static void
F_75 ( struct V_1 * V_2 , T_1 V_210 , T_3 * V_207 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_211 , V_121 ;
switch ( V_210 ) {
case V_192 :
memcpy ( V_207 , * V_212 ,
V_193 * V_213 ) ;
break;
case V_194 :
for ( V_211 = 0 ; V_211 < V_197 ; V_211 ++ ) {
memcpy ( V_207 + V_211 * V_213 ,
V_214 [ V_211 ] . V_215 ,
V_213 ) ;
}
if ( ! ( V_10 -> V_195 & V_196 ) )
return;
for ( V_121 = 0 ; V_121 < V_198 ; V_211 ++ , V_121 ++ ) {
memcpy ( V_207 + V_211 * V_213 ,
V_216 [ V_121 ] ,
V_213 ) ;
}
}
}
static void
F_76 ( int * V_211 , T_5 * V_207 ,
struct V_217 * V_218 )
{
int V_219 = * V_211 ;
V_207 [ V_219 ++ ] = F_77 ( V_218 -> V_220 ) ;
V_207 [ V_219 ++ ] = F_77 ( V_218 -> V_221 ) ;
V_207 [ V_219 ++ ] = F_77 ( V_218 -> V_222 ) ;
V_207 [ V_219 ++ ] = F_77 ( V_218 -> V_223 ) ;
V_207 [ V_219 ++ ] = F_77 ( V_218 -> V_224 ) ;
V_207 [ V_219 ++ ] = F_77 ( V_218 -> V_225 ) ;
V_207 [ V_219 ++ ] = F_77 ( V_218 -> V_226 ) ;
* V_211 = V_219 ;
}
static void
F_78 ( struct V_1 * V_2 ,
struct V_227 * V_218 , T_5 * V_207 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_228 V_229 ;
int V_211 , V_103 ;
for ( V_211 = 0 ; V_211 < V_197 ; V_211 ++ ) {
char * V_114 =
( char * ) V_10 +
V_214 [ V_211 ] . V_230 ;
V_207 [ V_211 ] =
( V_214 [ V_211 ] . V_231 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_114 : ( * ( T_1 * ) V_114 ) ;
}
if ( ! ( V_10 -> V_195 & V_196 ) )
return;
memset ( & V_229 , 0 , sizeof( struct V_228 ) ) ;
V_103 = F_79 ( V_10 , V_10 -> V_28 -> V_29 ,
V_232 , & V_229 . V_233 ) ;
if ( V_103 )
return;
F_76 ( & V_211 , V_207 , & V_229 . V_233 ) ;
V_103 = F_79 ( V_10 , V_10 -> V_28 -> V_29 ,
V_234 , & V_229 . V_235 ) ;
if ( V_103 )
return;
F_76 ( & V_211 , V_207 , & V_229 . V_235 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
enum V_236 V_128 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_134 = V_10 -> V_134 ;
switch ( V_128 ) {
case V_237 :
if ( ! F_18 ( V_127 , & V_10 -> V_128 ) ) {
if ( F_68 ( V_199 , & V_10 -> V_128 ) )
return - V_60 ;
if ( F_69 ( V_2 , V_238 ) ) {
F_73 ( V_199 , & V_10 -> V_128 ) ;
return - V_60 ;
}
F_81 ( V_239 , & V_10 -> V_128 ) ;
}
if ( V_10 -> V_240 -> V_241 ( V_10 , 1 , 0xf ) == 0 )
return 0 ;
F_13 ( & V_10 -> V_19 -> V_2 ,
L_9 ) ;
break;
case V_242 :
if ( V_10 -> V_240 -> V_241 ( V_10 , 0 , 0xf ) )
F_13 ( & V_10 -> V_19 -> V_2 ,
L_10 ) ;
break;
default:
return - V_144 ;
}
if ( F_82 ( V_239 , & V_10 -> V_128 ) ) {
F_72 ( V_2 , V_134 ) ;
F_73 ( V_199 , & V_10 -> V_128 ) ;
}
return - V_60 ;
}
static void
F_83 ( struct V_1 * V_2 , struct V_243 * V_244 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_245 ;
V_244 -> V_32 = 0 ;
V_244 -> V_246 = 0 ;
V_245 = F_5 ( V_10 , V_247 ) ;
if ( V_245 & ( 1UL << V_10 -> V_248 ) )
V_244 -> V_32 |= V_249 ;
V_245 = F_5 ( V_10 , V_250 ) ;
if ( V_245 & ( 1UL << V_10 -> V_248 ) )
V_244 -> V_246 |= V_249 ;
}
static int
F_84 ( struct V_1 * V_2 , struct V_243 * V_244 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_245 ;
if ( V_244 -> V_246 & ~ V_249 )
return - V_104 ;
V_245 = F_5 ( V_10 , V_247 ) ;
if ( ! ( V_245 & ( 1 << V_10 -> V_248 ) ) )
return - V_104 ;
V_245 = F_5 ( V_10 , V_250 ) ;
if ( V_244 -> V_246 & V_249 )
V_245 |= 1UL << V_10 -> V_248 ;
else
V_245 &= ~ ( 1UL << V_10 -> V_248 ) ;
F_51 ( V_10 , V_250 , V_245 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_181 ,
struct V_251 * V_252 )
{
struct V_9 * V_10 = F_4 ( V_181 ) ;
if ( ! F_18 ( V_127 , & V_10 -> V_128 ) )
return - V_144 ;
if ( V_252 -> V_253 > 0xffff ||
V_252 -> V_254 > 0xffff ||
V_252 -> V_255 ||
V_252 -> V_256 ||
V_252 -> V_257 ||
V_252 -> V_258 ||
V_252 -> V_259 ||
V_252 -> V_260 ||
V_252 -> V_261 ||
V_252 -> V_262 ||
V_252 -> V_263 ||
V_252 -> V_264 ||
V_252 -> V_265 ||
V_252 -> V_266 ||
V_252 -> V_267 ||
V_252 -> V_268 ||
V_252 -> V_269 ||
V_252 -> V_270 ||
V_252 -> V_271 ||
V_252 -> V_272 ||
V_252 -> V_273 )
return - V_144 ;
if ( ! V_252 -> V_253 ||
! V_252 -> V_254 ) {
V_10 -> V_28 -> V_274 . V_275 = V_276 ;
V_10 -> V_28 -> V_274 . V_277 =
V_278 ;
V_10 -> V_28 -> V_274 . V_279 =
V_280 ;
} else {
V_10 -> V_28 -> V_274 . V_275 = 0 ;
V_10 -> V_28 -> V_274 . V_277 = V_252 -> V_253 ;
V_10 -> V_28 -> V_274 . V_279 =
V_252 -> V_254 ;
}
F_86 ( V_10 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_181 ,
struct V_251 * V_252 )
{
struct V_9 * V_10 = F_4 ( V_181 ) ;
if ( V_10 -> V_281 != V_282 )
return - V_144 ;
V_252 -> V_253 = V_10 -> V_28 -> V_274 . V_277 ;
V_252 -> V_254 = V_10 -> V_28 -> V_274 . V_279 ;
return 0 ;
}
static T_1 F_88 ( struct V_1 * V_181 )
{
struct V_9 * V_10 = F_4 ( V_181 ) ;
return V_10 -> V_283 ;
}
static void F_89 ( struct V_1 * V_181 , T_1 V_284 )
{
struct V_9 * V_10 = F_4 ( V_181 ) ;
V_10 -> V_283 = V_284 ;
}
static int
F_90 ( struct V_1 * V_181 , struct V_285 * V_286 )
{
struct V_9 * V_10 = F_4 ( V_181 ) ;
struct V_287 * V_288 = & V_10 -> V_28 -> V_288 ;
V_286 -> V_143 = V_288 -> V_289 -> V_290 + V_288 -> V_290 ;
V_286 -> V_275 = V_288 -> V_289 -> V_291 ;
V_286 -> V_22 = V_10 -> V_17 ;
return 0 ;
}
static int
F_91 ( struct V_1 * V_181 , struct V_285 * V_286 ,
void * V_292 )
{
int V_121 , V_293 ;
T_1 * V_294 , * V_207 ;
struct V_9 * V_10 = F_4 ( V_181 ) ;
struct V_287 * V_288 = & V_10 -> V_28 -> V_288 ;
if ( F_92 ( V_10 ) )
return - V_60 ;
if ( ! V_288 -> V_295 ) {
F_38 ( V_181 , L_11 ) ;
F_93 ( V_10 ) ;
return - V_144 ;
}
V_293 = V_288 -> V_289 -> V_290 ;
V_294 = ( T_1 * ) V_288 -> V_289 ;
V_207 = ( T_1 * ) V_292 ;
for ( V_121 = 0 ; V_121 < V_293 / sizeof( T_1 ) ; V_121 ++ )
* V_207 ++ = F_94 ( * V_294 ++ ) ;
memcpy ( V_292 + V_293 , V_288 -> V_207 , V_288 -> V_290 ) ;
V_286 -> V_143 = V_293 + V_288 -> V_290 ;
V_286 -> V_275 = V_288 -> V_289 -> V_291 ;
F_95 ( V_288 -> V_207 ) ;
V_288 -> V_207 = NULL ;
V_288 -> V_295 = 0 ;
F_93 ( V_10 ) ;
return 0 ;
}
static int
F_96 ( struct V_1 * V_181 , struct V_285 * V_50 )
{
int V_103 = 0 ;
struct V_9 * V_10 = F_4 ( V_181 ) ;
struct V_287 * V_288 = & V_10 -> V_28 -> V_288 ;
if ( V_50 -> V_275 == V_296 ) {
F_38 ( V_181 , L_12 ) ;
F_97 ( V_10 ) ;
} else {
if ( V_50 -> V_275 > V_297 ||
V_50 -> V_275 < V_298 ) {
F_38 ( V_181 ,
L_13 , V_50 -> V_275 ) ;
V_103 = - V_144 ;
goto V_299;
}
if ( F_92 ( V_10 ) )
return - V_60 ;
V_288 -> V_289 -> V_291 = V_50 -> V_275 & 0xff ;
F_93 ( V_10 ) ;
F_38 ( V_181 , L_14 ,
V_288 -> V_289 -> V_291 ) ;
}
V_299:
return V_103 ;
}
