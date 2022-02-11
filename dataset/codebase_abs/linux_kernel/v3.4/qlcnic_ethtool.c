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
snprintf ( V_8 -> V_17 , sizeof( V_8 -> V_17 ) ,
L_1 , V_11 , V_12 , V_13 ) ;
F_6 ( V_8 -> V_18 , F_7 ( V_10 -> V_19 ) ,
sizeof( V_8 -> V_18 ) ) ;
F_6 ( V_8 -> V_20 , V_21 , sizeof( V_8 -> V_20 ) ) ;
F_6 ( V_8 -> V_22 , V_23 ,
sizeof( V_8 -> V_22 ) ) ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_26 = 0 ;
if ( V_10 -> V_27 -> V_28 == V_29 ) {
V_25 -> V_30 = ( V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 ) ;
V_25 -> V_37 = ( V_38 |
V_39 |
V_40 |
V_41 ) ;
F_9 ( V_25 , V_10 -> V_42 ) ;
V_25 -> V_43 = V_10 -> V_44 ;
V_25 -> V_45 = V_10 -> V_46 ;
} else if ( V_10 -> V_27 -> V_28 == V_47 ) {
T_1 V_48 ;
V_48 = F_5 ( V_10 , V_49 ) ;
if ( V_48 == V_50 ) {
V_25 -> V_30 = V_36 ;
V_25 -> V_37 = V_41 ;
} else {
V_25 -> V_30 = V_51 ;
V_25 -> V_37 = V_52 ;
}
if ( F_10 ( V_2 ) && V_10 -> V_53 ) {
F_9 ( V_25 , V_10 -> V_42 ) ;
V_25 -> V_45 = V_10 -> V_46 ;
V_25 -> V_43 = V_10 -> V_44 ;
goto V_54;
}
F_9 ( V_25 , V_55 ) ;
V_25 -> V_43 = V_56 ;
V_25 -> V_45 = V_57 ;
} else
return - V_58 ;
V_54:
V_25 -> V_59 = V_10 -> V_60 ;
V_25 -> V_61 = V_62 ;
switch ( V_10 -> V_27 -> V_63 ) {
case V_64 :
case V_65 :
case V_66 :
V_25 -> V_30 |= V_67 ;
V_25 -> V_37 |= V_68 ;
case V_69 :
case V_70 :
case V_71 :
V_25 -> V_30 |= V_72 ;
V_25 -> V_37 |= V_73 ;
V_25 -> V_74 = V_75 ;
V_25 -> V_45 = V_10 -> V_46 ;
break;
case V_76 :
case V_77 :
case V_78 :
V_25 -> V_30 |= V_79 ;
V_25 -> V_37 |= V_80 ;
V_25 -> V_74 = V_81 ;
V_25 -> V_45 = V_57 ;
break;
case V_82 :
case V_83 :
case V_84 :
V_25 -> V_37 |= V_73 ;
V_25 -> V_30 |= V_72 ;
V_26 = F_10 ( V_2 ) &&
V_10 -> V_53 ;
case V_85 :
V_25 -> V_30 |= V_86 ;
V_25 -> V_37 |= V_87 ;
V_25 -> V_74 = V_88 ;
V_25 -> V_45 = V_57 ;
break;
case V_89 :
if ( V_10 -> V_27 -> V_28 == V_47 ) {
V_25 -> V_45 = V_57 ;
V_25 -> V_30 |= ( V_86 | V_72 ) ;
V_25 -> V_37 |=
( V_87 | V_73 ) ;
V_25 -> V_74 = V_88 ;
V_26 = F_10 ( V_2 ) &&
V_10 -> V_53 ;
} else {
V_25 -> V_45 = V_90 ;
V_25 -> V_30 |= ( V_72 | V_67 ) ;
V_25 -> V_37 |=
( V_73 | V_68 ) ;
V_25 -> V_74 = V_75 ;
}
break;
default:
F_11 ( & V_10 -> V_19 -> V_2 , L_2 ,
V_10 -> V_27 -> V_63 ) ;
return - V_58 ;
}
if ( V_26 ) {
switch ( V_10 -> V_91 ) {
case V_92 :
case V_93 :
case V_94 :
case V_95 :
V_25 -> V_74 = V_88 ;
break;
case V_96 :
case V_97 :
case V_98 :
V_25 -> V_74 = V_75 ;
break;
default:
V_25 -> V_74 = V_99 ;
}
}
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
T_1 V_100 = 0 ;
T_1 V_101 = 0 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_27 -> V_28 != V_29 )
return - V_102 ;
if ( V_25 -> V_43 )
V_100 |= 0x1 ;
if ( V_25 -> V_45 )
V_100 |= 0x2 ;
switch ( F_13 ( V_25 ) ) {
case V_103 :
V_100 |= ( 0 << 8 ) ;
break;
case V_104 :
V_100 |= ( 1 << 8 ) ;
break;
case V_105 :
V_100 |= ( 10 << 8 ) ;
break;
default:
return - V_58 ;
}
V_101 = F_14 ( V_10 , V_100 ) ;
if ( V_101 == V_106 )
return - V_102 ;
else if ( V_101 )
return - V_58 ;
V_10 -> V_42 = F_13 ( V_25 ) ;
V_10 -> V_44 = V_25 -> V_43 ;
V_10 -> V_46 = V_25 -> V_45 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
V_2 -> V_107 -> V_108 ( V_2 ) ;
return V_2 -> V_107 -> V_109 ( V_2 ) ;
}
static void
F_15 ( struct V_1 * V_2 , struct V_110 * V_111 , void * V_112 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_113 * V_114 = V_10 -> V_114 ;
struct V_115 * V_116 ;
T_1 * V_117 = V_112 ;
int V_118 , V_119 = 0 , V_120 = 0 ;
memset ( V_112 , 0 , F_1 ( V_2 ) ) ;
V_111 -> V_22 = ( V_121 << 24 ) |
( V_10 -> V_27 -> V_122 << 16 ) | ( V_10 -> V_19 ) -> V_123 ;
V_117 [ 0 ] = ( 0xcafe0000 | ( V_5 & 0xffff ) ) ;
V_117 [ 1 ] = V_124 ;
for ( V_119 = V_5 + 1 ; V_3 [ V_120 ] != - 1 ; V_120 ++ , V_119 ++ )
V_117 [ V_119 ] = F_5 ( V_10 , V_3 [ V_120 ] ) ;
if ( ! F_16 ( V_125 , & V_10 -> V_126 ) )
return;
V_117 [ V_119 ++ ] = 0xFFEFCDAB ;
V_117 [ V_119 ++ ] = 1 ;
V_117 [ V_119 ++ ] = F_17 ( * ( V_10 -> V_127 -> V_128 ) ) ;
V_117 [ V_119 ++ ] = F_18 ( V_10 -> V_127 -> V_129 ) ;
V_117 [ V_119 ++ ] = 2 ;
V_117 [ V_119 ++ ] = F_18 ( V_114 -> V_130 [ 0 ] . V_131 ) ;
V_117 [ V_119 ++ ] = F_18 ( V_114 -> V_130 [ 1 ] . V_131 ) ;
V_117 [ V_119 ++ ] = V_10 -> V_132 ;
for ( V_118 = 0 ; V_118 < V_10 -> V_132 ; V_118 ++ ) {
V_116 = & ( V_114 -> V_133 [ V_118 ] ) ;
V_117 [ V_119 ++ ] = F_18 ( V_116 -> V_134 ) ;
}
}
static T_1 F_19 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_48 ;
V_48 = F_5 ( V_10 , V_135 ) ;
V_48 = F_20 ( V_10 -> V_27 -> V_136 , V_48 ) ;
return ( V_48 == V_137 ) ? 0 : 1 ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_138 * V_139 ,
T_2 * V_140 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_141 ;
int V_101 ;
if ( V_139 -> V_142 == 0 )
return - V_143 ;
V_139 -> V_144 = ( V_10 -> V_19 ) -> V_145 |
( ( V_10 -> V_19 ) -> V_123 << 16 ) ;
V_141 = V_139 -> V_141 ;
V_101 = F_22 ( V_10 , V_141 , V_140 ,
V_139 -> V_142 ) ;
if ( V_101 < 0 )
return V_101 ;
return 0 ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_146 * V_118 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
V_118 -> V_147 = V_10 -> V_148 ;
V_118 -> V_149 = V_10 -> V_150 ;
V_118 -> V_151 = V_10 -> V_152 ;
V_118 -> V_153 = V_10 -> V_154 ;
V_118 -> V_155 = V_10 -> V_156 ;
V_118 -> V_157 = V_158 ;
}
static T_1
F_24 ( T_1 V_48 , T_1 V_159 , T_1 V_160 , char * V_161 )
{
T_1 V_162 ;
V_162 = V_160 ( V_48 , V_159 ) ;
V_162 = V_159 ( V_162 , V_160 ) ;
V_162 = F_25 ( V_162 ) ;
if ( V_48 != V_162 ) {
F_26 ( V_163 L_3 ,
V_21 , V_161 , V_162 , V_48 ) ;
}
return V_162 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_146 * V_118 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_3 V_148 , V_150 , V_152 ;
if ( V_118 -> V_164 )
return - V_102 ;
V_148 = F_24 ( V_118 -> V_147 ,
V_165 , V_10 -> V_154 , L_4 ) ;
V_150 = F_24 ( V_118 -> V_149 ,
V_166 , V_10 -> V_156 ,
L_5 ) ;
V_152 = F_24 ( V_118 -> V_151 ,
V_167 , V_158 , L_6 ) ;
if ( V_148 == V_10 -> V_148 && V_152 == V_10 -> V_152 &&
V_150 == V_10 -> V_150 )
return 0 ;
V_10 -> V_148 = V_148 ;
V_10 -> V_150 = V_150 ;
V_10 -> V_152 = V_152 ;
return F_28 ( V_10 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
V_169 -> V_170 = F_30 ( F_31 ( int ,
V_10 -> V_171 , F_32 () ) ) ;
V_169 -> V_172 = V_10 -> V_173 ;
V_169 -> V_174 = V_10 -> V_132 ;
V_169 -> V_175 = V_10 -> V_173 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_176 ;
if ( V_169 -> V_177 || V_169 -> V_178 ||
V_169 -> V_175 != V_169 -> V_172 )
return - V_143 ;
V_176 = F_34 ( V_2 , V_169 -> V_170 , V_169 -> V_174 ) ;
if ( V_176 )
return V_176 ;
V_176 = F_35 ( V_10 , V_169 -> V_174 ) ;
F_36 ( V_2 , L_7 ,
V_10 -> V_132 ) ;
return V_176 ;
}
static void
F_37 ( struct V_1 * V_179 ,
struct V_180 * V_181 )
{
struct V_9 * V_10 = F_4 ( V_179 ) ;
int V_74 = V_10 -> V_60 ;
T_4 V_48 ;
if ( V_10 -> V_27 -> V_28 == V_29 ) {
if ( ( V_74 < 0 ) || ( V_74 > V_182 ) )
return;
V_48 = F_5 ( V_10 , F_38 ( V_74 ) ) ;
V_181 -> V_183 = F_39 ( V_48 ) ;
V_48 = F_5 ( V_10 , V_184 ) ;
switch ( V_74 ) {
case 0 :
V_181 -> V_185 = ! ( F_40 ( V_48 ) ) ;
break;
case 1 :
V_181 -> V_185 = ! ( F_41 ( V_48 ) ) ;
break;
case 2 :
V_181 -> V_185 = ! ( F_42 ( V_48 ) ) ;
break;
case 3 :
default:
V_181 -> V_185 = ! ( F_43 ( V_48 ) ) ;
break;
}
} else if ( V_10 -> V_27 -> V_28 == V_47 ) {
if ( ( V_74 < 0 ) || ( V_74 > V_186 ) )
return;
V_181 -> V_183 = 1 ;
V_48 = F_5 ( V_10 , V_187 ) ;
if ( V_74 == 0 )
V_181 -> V_185 = ! ( F_44 ( V_48 ) ) ;
else
V_181 -> V_185 = ! ( F_45 ( V_48 ) ) ;
} else {
F_11 ( & V_179 -> V_2 , L_8 ,
V_10 -> V_27 -> V_28 ) ;
}
}
static int
F_46 ( struct V_1 * V_179 ,
struct V_180 * V_181 )
{
struct V_9 * V_10 = F_4 ( V_179 ) ;
int V_74 = V_10 -> V_60 ;
T_4 V_48 ;
if ( V_10 -> V_27 -> V_28 == V_29 ) {
if ( ( V_74 < 0 ) || ( V_74 > V_182 ) )
return - V_58 ;
V_48 = F_5 ( V_10 , F_38 ( V_74 ) ) ;
if ( V_181 -> V_183 )
F_47 ( V_48 ) ;
else
F_48 ( V_48 ) ;
F_49 ( V_10 , F_38 ( V_74 ) ,
V_48 ) ;
V_48 = F_5 ( V_10 , V_184 ) ;
switch ( V_74 ) {
case 0 :
if ( V_181 -> V_185 )
F_50 ( V_48 ) ;
else
F_51 ( V_48 ) ;
break;
case 1 :
if ( V_181 -> V_185 )
F_52 ( V_48 ) ;
else
F_53 ( V_48 ) ;
break;
case 2 :
if ( V_181 -> V_185 )
F_54 ( V_48 ) ;
else
F_55 ( V_48 ) ;
break;
case 3 :
default:
if ( V_181 -> V_185 )
F_56 ( V_48 ) ;
else
F_57 ( V_48 ) ;
break;
}
F_49 ( V_10 , V_184 , V_48 ) ;
} else if ( V_10 -> V_27 -> V_28 == V_47 ) {
if ( ! V_181 -> V_183 || V_181 -> V_45 )
return - V_102 ;
if ( ( V_74 < 0 ) || ( V_74 > V_186 ) )
return - V_58 ;
V_48 = F_5 ( V_10 , V_187 ) ;
if ( V_74 == 0 ) {
if ( V_181 -> V_185 )
F_58 ( V_48 ) ;
else
F_59 ( V_48 ) ;
} else {
if ( V_181 -> V_185 )
F_60 ( V_48 ) ;
else
F_61 ( V_48 ) ;
}
F_49 ( V_10 , V_187 , V_48 ) ;
} else {
F_11 ( & V_179 -> V_2 , L_8 ,
V_10 -> V_27 -> V_28 ) ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_188 ;
V_188 = F_5 ( V_10 , F_63 ( 0 ) ) ;
if ( ( V_188 & 0xffff ) != V_10 -> V_19 -> V_145 )
return 1 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , int V_189 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
switch ( V_189 ) {
case V_190 :
return V_191 ;
case V_192 :
if ( V_10 -> V_193 & V_194 )
return V_195 + V_196 ;
return V_195 ;
default:
return - V_102 ;
}
}
static int F_65 ( struct V_1 * V_179 )
{
struct V_9 * V_10 = F_4 ( V_179 ) ;
int V_132 = V_10 -> V_132 ;
int V_101 ;
struct V_197 V_198 ;
if ( F_66 ( V_199 , & V_10 -> V_126 ) )
return - V_58 ;
V_101 = F_67 ( V_179 , V_200 ) ;
if ( V_101 )
goto V_201;
V_10 -> V_202 = 0 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_203 . V_198 = V_204 ;
V_198 . V_203 . V_205 = V_10 -> V_27 -> V_136 ;
F_68 ( V_10 , & V_198 ) ;
V_101 = V_198 . V_206 . V_198 ;
if ( V_101 )
goto V_207;
F_69 ( 10 ) ;
V_101 = ! V_10 -> V_202 ;
V_207:
F_70 ( V_179 , V_132 ) ;
V_201:
V_10 -> V_132 = V_132 ;
F_71 ( V_199 , & V_10 -> V_126 ) ;
return V_101 ;
}
static void F_72 ( unsigned char * V_208 , T_2 V_209 [] )
{
unsigned char V_210 [] = { 0xa8 , 0x06 , 0x45 , 0x00 } ;
memset ( V_208 , 0x4e , V_211 ) ;
memcpy ( V_208 , V_209 , V_212 ) ;
memcpy ( V_208 + V_212 , V_209 , V_212 ) ;
memcpy ( V_208 + 2 * V_212 , V_210 , sizeof( V_210 ) ) ;
}
int F_73 ( unsigned char * V_208 , T_2 V_209 [] )
{
unsigned char V_213 [ V_211 ] ;
F_72 ( V_213 , V_209 ) ;
return memcmp ( V_208 , V_213 , V_211 ) ;
}
static int F_74 ( struct V_9 * V_10 , T_2 V_214 )
{
struct V_113 * V_114 = V_10 -> V_114 ;
struct V_115 * V_116 = & V_114 -> V_133 [ 0 ] ;
struct V_215 * V_216 ;
int V_119 , V_217 , V_218 = 0 ;
for ( V_119 = 0 ; V_119 < V_219 ; V_119 ++ ) {
V_216 = F_75 ( V_10 -> V_179 , V_211 ) ;
F_72 ( V_216 -> V_208 , V_10 -> V_220 ) ;
F_76 ( V_216 , V_211 ) ;
V_10 -> V_202 = 0 ;
F_77 ( V_216 , V_10 -> V_179 ) ;
V_217 = 0 ;
do {
F_69 ( 1 ) ;
F_78 ( V_116 ) ;
if ( V_217 ++ > V_221 )
break;
} while ( ! V_10 -> V_202 );
F_79 ( V_216 ) ;
if ( ! V_10 -> V_202 )
F_80 ( V_10 , V_222 ,
L_9 , V_119 + 1 ) ;
else
V_218 ++ ;
}
if ( V_218 != V_119 ) {
F_81 ( & V_10 -> V_19 -> V_2 , L_10 ) ;
if ( V_214 != V_223 ) {
F_81 ( & V_10 -> V_19 -> V_2 ,
L_11
L_12 ) ;
}
return - 1 ;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_179 , T_2 V_214 )
{
struct V_9 * V_10 = F_4 ( V_179 ) ;
int V_132 = V_10 -> V_132 ;
struct V_115 * V_116 ;
int V_217 = 0 ;
int V_101 ;
if ( ! ( V_10 -> V_224 & V_225 ) ) {
F_36 ( V_179 , L_13 ) ;
return - V_102 ;
}
F_80 ( V_10 , V_222 , L_14 ,
V_214 == V_223 ? L_15 : L_16 ) ;
if ( V_10 -> V_226 == V_227 ) {
F_83 ( V_179 , L_17
L_18 ) ;
return 0 ;
}
if ( F_66 ( V_199 , & V_10 -> V_126 ) )
return - V_228 ;
V_101 = F_67 ( V_179 , V_229 ) ;
if ( V_101 )
goto V_201;
V_116 = & V_10 -> V_114 -> V_133 [ 0 ] ;
V_101 = F_84 ( V_10 , V_214 ) ;
if ( V_101 )
goto V_230;
V_10 -> V_202 = 0 ;
do {
F_69 ( 500 ) ;
F_78 ( V_116 ) ;
if ( V_217 ++ > V_221 ) {
F_36 ( V_179 , L_19
L_20 ) ;
V_101 = - V_231 ;
goto V_230;
} else if ( V_10 -> V_202 ) {
V_101 = V_10 -> V_202 ;
goto V_230;
}
} while ( ! F_85 ( V_10 -> V_27 -> V_232 ) );
V_101 = F_74 ( V_10 , V_214 ) ;
F_86 ( V_10 ) ;
V_230:
F_70 ( V_179 , V_132 ) ;
V_201:
V_10 -> V_132 = V_132 ;
F_71 ( V_199 , & V_10 -> V_126 ) ;
return V_101 ;
}
static void
F_87 ( struct V_1 * V_2 , struct V_233 * V_234 ,
T_5 * V_208 )
{
memset ( V_208 , 0 , sizeof( T_5 ) * V_191 ) ;
V_208 [ 0 ] = F_62 ( V_2 ) ;
if ( V_208 [ 0 ] )
V_234 -> V_193 |= V_235 ;
V_208 [ 1 ] = ( T_5 ) F_19 ( V_2 ) ;
if ( V_208 [ 1 ] )
V_234 -> V_193 |= V_235 ;
if ( V_234 -> V_193 & V_236 ) {
V_208 [ 2 ] = F_65 ( V_2 ) ;
if ( V_208 [ 2 ] )
V_234 -> V_193 |= V_235 ;
V_208 [ 3 ] = F_82 ( V_2 , V_223 ) ;
if ( V_208 [ 3 ] )
V_234 -> V_193 |= V_235 ;
if ( V_234 -> V_193 & V_237 ) {
V_208 [ 4 ] = F_82 ( V_2 , V_238 ) ;
if ( V_208 [ 4 ] )
V_234 -> V_193 |= V_235 ;
V_234 -> V_193 |= V_239 ;
}
}
}
static void
F_88 ( struct V_1 * V_2 , T_1 V_240 , T_2 * V_208 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_241 , V_119 ;
switch ( V_240 ) {
case V_190 :
memcpy ( V_208 , * V_242 ,
V_191 * V_243 ) ;
break;
case V_192 :
for ( V_241 = 0 ; V_241 < V_195 ; V_241 ++ ) {
memcpy ( V_208 + V_241 * V_243 ,
V_244 [ V_241 ] . V_245 ,
V_243 ) ;
}
if ( ! ( V_10 -> V_193 & V_194 ) )
return;
for ( V_119 = 0 ; V_119 < V_196 ; V_241 ++ , V_119 ++ ) {
memcpy ( V_208 + V_241 * V_243 ,
V_246 [ V_119 ] ,
V_243 ) ;
}
}
}
static void
F_89 ( int * V_241 , T_5 * V_208 ,
struct V_247 * V_248 )
{
int V_249 = * V_241 ;
V_208 [ V_249 ++ ] = F_90 ( V_248 -> V_250 ) ;
V_208 [ V_249 ++ ] = F_90 ( V_248 -> V_251 ) ;
V_208 [ V_249 ++ ] = F_90 ( V_248 -> V_252 ) ;
V_208 [ V_249 ++ ] = F_90 ( V_248 -> V_253 ) ;
V_208 [ V_249 ++ ] = F_90 ( V_248 -> V_254 ) ;
V_208 [ V_249 ++ ] = F_90 ( V_248 -> V_255 ) ;
V_208 [ V_249 ++ ] = F_90 ( V_248 -> V_256 ) ;
* V_241 = V_249 ;
}
static void
F_91 ( struct V_1 * V_2 ,
struct V_257 * V_248 , T_5 * V_208 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_258 V_259 ;
int V_241 , V_101 ;
for ( V_241 = 0 ; V_241 < V_195 ; V_241 ++ ) {
char * V_112 =
( char * ) V_10 +
V_244 [ V_241 ] . V_260 ;
V_208 [ V_241 ] =
( V_244 [ V_241 ] . V_261 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_112 : ( * ( T_1 * ) V_112 ) ;
}
if ( ! ( V_10 -> V_193 & V_194 ) )
return;
memset ( & V_259 , 0 , sizeof( struct V_258 ) ) ;
V_101 = F_92 ( V_10 , V_10 -> V_27 -> V_136 ,
V_262 , & V_259 . V_263 ) ;
if ( V_101 )
return;
F_89 ( & V_241 , V_208 , & V_259 . V_263 ) ;
V_101 = F_92 ( V_10 , V_10 -> V_27 -> V_136 ,
V_264 , & V_259 . V_265 ) ;
if ( V_101 )
return;
F_89 ( & V_241 , V_208 , & V_259 . V_265 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
enum V_266 V_126 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_132 = V_10 -> V_132 ;
int V_176 = - V_58 , V_267 = 1 ;
if ( V_10 -> V_226 == V_227 ) {
F_83 ( V_2 , L_21
L_18 ) ;
return - V_102 ;
}
switch ( V_126 ) {
case V_268 :
if ( F_66 ( V_269 , & V_10 -> V_126 ) )
return - V_228 ;
if ( F_16 ( V_199 , & V_10 -> V_126 ) )
break;
if ( ! F_16 ( V_125 , & V_10 -> V_126 ) ) {
if ( F_67 ( V_2 , V_270 ) )
break;
F_94 ( V_271 , & V_10 -> V_126 ) ;
}
if ( V_10 -> V_272 -> V_273 ( V_10 , 1 , 0xf ) == 0 ) {
V_176 = 0 ;
break;
}
F_11 ( & V_10 -> V_19 -> V_2 ,
L_22 ) ;
break;
case V_274 :
V_267 = 0 ;
if ( F_16 ( V_199 , & V_10 -> V_126 ) )
break;
if ( ! F_16 ( V_125 , & V_10 -> V_126 ) ) {
if ( F_67 ( V_2 , V_270 ) )
break;
F_94 ( V_271 , & V_10 -> V_126 ) ;
}
if ( V_10 -> V_272 -> V_273 ( V_10 , 0 , 0xf ) )
F_11 ( & V_10 -> V_19 -> V_2 ,
L_23 ) ;
break;
default:
return - V_143 ;
}
if ( F_95 ( V_271 , & V_10 -> V_126 ) )
F_70 ( V_2 , V_132 ) ;
if ( ! V_267 || V_176 )
F_71 ( V_269 , & V_10 -> V_126 ) ;
return V_176 ;
}
static void
F_96 ( struct V_1 * V_2 , struct V_275 * V_276 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_277 ;
V_276 -> V_30 = 0 ;
V_276 -> V_278 = 0 ;
V_277 = F_5 ( V_10 , V_279 ) ;
if ( V_277 & ( 1UL << V_10 -> V_280 ) )
V_276 -> V_30 |= V_281 ;
V_277 = F_5 ( V_10 , V_282 ) ;
if ( V_277 & ( 1UL << V_10 -> V_280 ) )
V_276 -> V_278 |= V_281 ;
}
static int
F_97 ( struct V_1 * V_2 , struct V_275 * V_276 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_277 ;
if ( V_276 -> V_278 & ~ V_281 )
return - V_102 ;
V_277 = F_5 ( V_10 , V_279 ) ;
if ( ! ( V_277 & ( 1 << V_10 -> V_280 ) ) )
return - V_102 ;
V_277 = F_5 ( V_10 , V_282 ) ;
if ( V_276 -> V_278 & V_281 )
V_277 |= 1UL << V_10 -> V_280 ;
else
V_277 &= ~ ( 1UL << V_10 -> V_280 ) ;
F_49 ( V_10 , V_282 , V_277 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_179 ,
struct V_283 * V_284 )
{
struct V_9 * V_10 = F_4 ( V_179 ) ;
if ( ! F_16 ( V_125 , & V_10 -> V_126 ) )
return - V_143 ;
if ( V_284 -> V_285 > 0xffff ||
V_284 -> V_286 > 0xffff ||
V_284 -> V_287 ||
V_284 -> V_288 ||
V_284 -> V_289 ||
V_284 -> V_290 ||
V_284 -> V_291 ||
V_284 -> V_292 ||
V_284 -> V_293 ||
V_284 -> V_294 ||
V_284 -> V_295 ||
V_284 -> V_296 ||
V_284 -> V_297 ||
V_284 -> V_298 ||
V_284 -> V_299 ||
V_284 -> V_300 ||
V_284 -> V_301 ||
V_284 -> V_302 ||
V_284 -> V_303 ||
V_284 -> V_304 ||
V_284 -> V_305 )
return - V_143 ;
if ( ! V_284 -> V_285 ||
! V_284 -> V_286 ) {
V_10 -> V_27 -> V_306 . V_307 = V_308 ;
V_10 -> V_27 -> V_306 . V_309 =
V_310 ;
V_10 -> V_27 -> V_306 . V_311 =
V_312 ;
} else {
V_10 -> V_27 -> V_306 . V_307 = 0 ;
V_10 -> V_27 -> V_306 . V_309 = V_284 -> V_285 ;
V_10 -> V_27 -> V_306 . V_311 =
V_284 -> V_286 ;
}
F_99 ( V_10 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_179 ,
struct V_283 * V_284 )
{
struct V_9 * V_10 = F_4 ( V_179 ) ;
if ( V_10 -> V_313 != V_314 )
return - V_143 ;
V_284 -> V_285 = V_10 -> V_27 -> V_306 . V_309 ;
V_284 -> V_286 = V_10 -> V_27 -> V_306 . V_311 ;
return 0 ;
}
static T_1 F_101 ( struct V_1 * V_179 )
{
struct V_9 * V_10 = F_4 ( V_179 ) ;
return V_10 -> V_315 ;
}
static void F_102 ( struct V_1 * V_179 , T_1 V_316 )
{
struct V_9 * V_10 = F_4 ( V_179 ) ;
V_10 -> V_315 = V_316 ;
}
static int
F_103 ( struct V_1 * V_179 , struct V_317 * V_318 )
{
struct V_9 * V_10 = F_4 ( V_179 ) ;
struct V_319 * V_320 = & V_10 -> V_27 -> V_320 ;
if ( V_320 -> V_321 )
V_318 -> V_142 = V_320 -> V_322 -> V_323 + V_320 -> V_323 ;
else
V_318 -> V_142 = 0 ;
V_318 -> V_307 = V_320 -> V_322 -> V_324 ;
V_318 -> V_22 = V_10 -> V_17 ;
return 0 ;
}
static int
F_104 ( struct V_1 * V_179 , struct V_317 * V_318 ,
void * V_325 )
{
int V_119 , V_326 ;
T_1 * V_327 , * V_208 ;
struct V_9 * V_10 = F_4 ( V_179 ) ;
struct V_319 * V_320 = & V_10 -> V_27 -> V_320 ;
if ( ! V_320 -> V_321 ) {
F_36 ( V_179 , L_24 ) ;
return - V_143 ;
}
V_326 = V_320 -> V_322 -> V_323 ;
V_327 = ( T_1 * ) V_320 -> V_322 ;
V_208 = V_325 ;
for ( V_119 = 0 ; V_119 < V_326 / sizeof( T_1 ) ; V_119 ++ )
* V_208 ++ = F_105 ( * V_327 ++ ) ;
memcpy ( V_325 + V_326 , V_320 -> V_208 , V_320 -> V_323 ) ;
V_318 -> V_142 = V_326 + V_320 -> V_323 ;
V_318 -> V_307 = V_320 -> V_322 -> V_324 ;
F_106 ( V_320 -> V_208 ) ;
V_320 -> V_208 = NULL ;
V_320 -> V_321 = 0 ;
F_36 ( V_179 , L_25 ) ;
return 0 ;
}
static int
F_107 ( struct V_1 * V_179 , struct V_317 * V_48 )
{
int V_101 = 0 ;
struct V_9 * V_10 = F_4 ( V_179 ) ;
struct V_319 * V_320 = & V_10 -> V_27 -> V_320 ;
switch ( V_48 -> V_307 ) {
case V_328 :
if ( ! V_320 -> V_329 ) {
F_36 ( V_179 , L_26 ) ;
return V_101 ;
}
if ( V_320 -> V_321 ) {
F_36 ( V_179 ,
L_27 ) ;
return V_101 ;
}
F_36 ( V_179 , L_28 ) ;
F_108 ( V_10 ) ;
break;
case V_330 :
if ( V_320 -> V_329 ) {
F_36 ( V_179 , L_29 ) ;
V_320 -> V_329 = 0 ;
}
break;
case V_331 :
if ( ! V_320 -> V_329 && V_320 -> V_322 ) {
F_36 ( V_179 , L_30 ) ;
V_320 -> V_329 = 1 ;
}
break;
case V_332 :
F_36 ( V_179 , L_31 ) ;
F_108 ( V_10 ) ;
V_10 -> V_193 &= ~ V_333 ;
break;
default:
if ( V_48 -> V_307 > V_334 ||
V_48 -> V_307 < V_335 ) {
F_36 ( V_179 ,
L_32 , V_48 -> V_307 ) ;
V_101 = - V_143 ;
goto V_336;
}
V_320 -> V_322 -> V_324 = V_48 -> V_307 & 0xff ;
F_36 ( V_179 , L_33 ,
V_320 -> V_322 -> V_324 ) ;
}
V_336:
return V_101 ;
}
