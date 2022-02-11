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
}
static T_1
F_26 ( T_1 V_50 , T_1 V_160 , T_1 V_161 , char * V_162 )
{
T_1 V_163 ;
V_163 = V_161 ( V_50 , V_160 ) ;
V_163 = V_160 ( V_163 , V_161 ) ;
V_163 = F_27 ( V_163 ) ;
if ( V_50 != V_163 ) {
F_28 ( V_164 L_3 ,
V_21 , V_162 , V_163 , V_50 ) ;
}
return V_163 ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_147 * V_120 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_2 V_149 , V_151 , V_153 ;
if ( V_120 -> V_165 )
return - V_104 ;
V_149 = F_26 ( V_120 -> V_148 ,
V_166 , V_10 -> V_155 , L_4 ) ;
V_151 = F_26 ( V_120 -> V_150 ,
V_167 , V_10 -> V_157 ,
L_5 ) ;
V_153 = F_26 ( V_120 -> V_152 ,
V_168 , V_159 , L_6 ) ;
if ( V_149 == V_10 -> V_149 && V_153 == V_10 -> V_153 &&
V_151 == V_10 -> V_151 )
return 0 ;
V_10 -> V_149 = V_149 ;
V_10 -> V_151 = V_151 ;
V_10 -> V_153 = V_153 ;
return F_30 ( V_10 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
V_170 -> V_171 = F_32 ( F_33 ( int ,
V_10 -> V_172 , F_34 () ) ) ;
V_170 -> V_173 = V_10 -> V_174 ;
V_170 -> V_175 = V_10 -> V_134 ;
V_170 -> V_176 = V_10 -> V_174 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_177 ;
if ( V_170 -> V_178 || V_170 -> V_179 ||
V_170 -> V_176 != V_170 -> V_173 )
return - V_144 ;
V_177 = F_36 ( V_2 , V_170 -> V_171 , V_170 -> V_175 ) ;
if ( V_177 )
return V_177 ;
V_177 = F_37 ( V_10 , V_170 -> V_175 ) ;
F_38 ( V_2 , L_7 ,
V_10 -> V_134 ) ;
return V_177 ;
}
static void
F_39 ( struct V_1 * V_180 ,
struct V_181 * V_182 )
{
struct V_9 * V_10 = F_4 ( V_180 ) ;
int V_76 = V_10 -> V_62 ;
T_4 V_50 ;
if ( V_10 -> V_28 -> V_30 == V_31 ) {
if ( ( V_76 < 0 ) || ( V_76 > V_183 ) )
return;
V_50 = F_5 ( V_10 , F_40 ( V_76 ) ) ;
V_182 -> V_184 = F_41 ( V_50 ) ;
V_50 = F_5 ( V_10 , V_185 ) ;
switch ( V_76 ) {
case 0 :
V_182 -> V_186 = ! ( F_42 ( V_50 ) ) ;
break;
case 1 :
V_182 -> V_186 = ! ( F_43 ( V_50 ) ) ;
break;
case 2 :
V_182 -> V_186 = ! ( F_44 ( V_50 ) ) ;
break;
case 3 :
default:
V_182 -> V_186 = ! ( F_45 ( V_50 ) ) ;
break;
}
} else if ( V_10 -> V_28 -> V_30 == V_49 ) {
if ( ( V_76 < 0 ) || ( V_76 > V_187 ) )
return;
V_182 -> V_184 = 1 ;
V_50 = F_5 ( V_10 , V_188 ) ;
if ( V_76 == 0 )
V_182 -> V_186 = ! ( F_46 ( V_50 ) ) ;
else
V_182 -> V_186 = ! ( F_47 ( V_50 ) ) ;
} else {
F_13 ( & V_180 -> V_2 , L_8 ,
V_10 -> V_28 -> V_30 ) ;
}
}
static int
F_48 ( struct V_1 * V_180 ,
struct V_181 * V_182 )
{
struct V_9 * V_10 = F_4 ( V_180 ) ;
int V_76 = V_10 -> V_62 ;
T_4 V_50 ;
if ( V_10 -> V_28 -> V_30 == V_31 ) {
if ( ( V_76 < 0 ) || ( V_76 > V_183 ) )
return - V_60 ;
V_50 = F_5 ( V_10 , F_40 ( V_76 ) ) ;
if ( V_182 -> V_184 )
F_49 ( V_50 ) ;
else
F_50 ( V_50 ) ;
F_51 ( V_10 , F_40 ( V_76 ) ,
V_50 ) ;
V_50 = F_5 ( V_10 , V_185 ) ;
switch ( V_76 ) {
case 0 :
if ( V_182 -> V_186 )
F_52 ( V_50 ) ;
else
F_53 ( V_50 ) ;
break;
case 1 :
if ( V_182 -> V_186 )
F_54 ( V_50 ) ;
else
F_55 ( V_50 ) ;
break;
case 2 :
if ( V_182 -> V_186 )
F_56 ( V_50 ) ;
else
F_57 ( V_50 ) ;
break;
case 3 :
default:
if ( V_182 -> V_186 )
F_58 ( V_50 ) ;
else
F_59 ( V_50 ) ;
break;
}
F_51 ( V_10 , V_185 , V_50 ) ;
} else if ( V_10 -> V_28 -> V_30 == V_49 ) {
if ( ! V_182 -> V_184 || V_182 -> V_47 )
return - V_104 ;
if ( ( V_76 < 0 ) || ( V_76 > V_187 ) )
return - V_60 ;
V_50 = F_5 ( V_10 , V_188 ) ;
if ( V_76 == 0 ) {
if ( V_182 -> V_186 )
F_60 ( V_50 ) ;
else
F_61 ( V_50 ) ;
} else {
if ( V_182 -> V_186 )
F_62 ( V_50 ) ;
else
F_63 ( V_50 ) ;
}
F_51 ( V_10 , V_188 , V_50 ) ;
} else {
F_13 ( & V_180 -> V_2 , L_8 ,
V_10 -> V_28 -> V_30 ) ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_189 ;
V_189 = F_5 ( V_10 , F_65 ( 0 ) ) ;
if ( ( V_189 & 0xffff ) != V_10 -> V_19 -> V_146 )
return 1 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , int V_190 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
switch ( V_190 ) {
case V_191 :
return V_192 ;
case V_193 :
if ( V_10 -> V_194 & V_195 )
return V_196 + V_197 ;
return V_196 ;
default:
return - V_104 ;
}
}
static int F_67 ( struct V_1 * V_180 )
{
struct V_9 * V_10 = F_4 ( V_180 ) ;
int V_134 = V_10 -> V_134 ;
int V_103 ;
struct V_198 V_199 ;
if ( F_68 ( V_200 , & V_10 -> V_128 ) )
return - V_60 ;
V_103 = F_69 ( V_180 , V_201 ) ;
if ( V_103 )
goto V_202;
V_10 -> V_203 = 0 ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
V_199 . V_204 . V_199 = V_205 ;
V_199 . V_204 . V_206 = V_10 -> V_28 -> V_29 ;
F_70 ( V_10 , & V_199 ) ;
V_103 = V_199 . V_207 . V_199 ;
if ( V_103 )
goto V_208;
F_71 ( 10 ) ;
V_103 = ! V_10 -> V_203 ;
V_208:
F_72 ( V_180 , V_134 ) ;
V_202:
V_10 -> V_134 = V_134 ;
F_73 ( V_200 , & V_10 -> V_128 ) ;
return V_103 ;
}
static void F_74 ( unsigned char * V_209 , T_3 V_210 [] )
{
unsigned char V_211 [] = { 0xa8 , 0x06 , 0x45 , 0x00 } ;
memset ( V_209 , 0x4e , V_212 ) ;
memcpy ( V_209 , V_210 , V_213 ) ;
memcpy ( V_209 + V_213 , V_210 , V_213 ) ;
memcpy ( V_209 + 2 * V_213 , V_211 , sizeof( V_211 ) ) ;
}
int F_75 ( unsigned char * V_209 , T_3 V_210 [] )
{
unsigned char V_214 [ V_212 ] ;
F_74 ( V_214 , V_210 ) ;
return memcmp ( V_209 , V_214 , V_212 ) ;
}
static int F_76 ( struct V_9 * V_10 , T_3 V_215 )
{
struct V_115 * V_116 = V_10 -> V_116 ;
struct V_117 * V_118 = & V_116 -> V_135 [ 0 ] ;
struct V_216 * V_217 ;
int V_121 , V_218 , V_219 = 0 ;
for ( V_121 = 0 ; V_121 < V_220 ; V_121 ++ ) {
V_217 = F_77 ( V_212 ) ;
F_74 ( V_217 -> V_209 , V_10 -> V_221 ) ;
F_78 ( V_217 , V_212 ) ;
V_10 -> V_203 = 0 ;
F_79 ( V_217 , V_10 -> V_180 ) ;
V_218 = 0 ;
do {
F_71 ( 1 ) ;
F_80 ( V_118 ) ;
if ( V_218 ++ > V_222 )
break;
} while ( ! V_10 -> V_203 );
F_81 ( V_217 ) ;
if ( ! V_10 -> V_203 )
F_82 ( V_10 , V_223 ,
L_9 , V_121 + 1 ) ;
else
V_219 ++ ;
}
if ( V_219 != V_121 ) {
F_83 ( & V_10 -> V_19 -> V_2 , L_10 ) ;
if ( V_215 != V_224 ) {
F_83 ( & V_10 -> V_19 -> V_2 ,
L_11
L_12 ) ;
}
return - 1 ;
}
return 0 ;
}
static int F_84 ( struct V_1 * V_180 , T_3 V_215 )
{
struct V_9 * V_10 = F_4 ( V_180 ) ;
int V_134 = V_10 -> V_134 ;
struct V_117 * V_118 ;
int V_218 = 0 ;
int V_103 ;
if ( ! ( V_10 -> V_225 & V_226 ) ) {
F_38 ( V_180 , L_13 ) ;
return - V_104 ;
}
F_82 ( V_10 , V_223 , L_14 ,
V_215 == V_224 ? L_15 : L_16 ) ;
if ( V_10 -> V_227 == V_228 ) {
F_85 ( V_180 , L_17
L_18 ) ;
return 0 ;
}
if ( F_68 ( V_200 , & V_10 -> V_128 ) )
return - V_229 ;
V_103 = F_69 ( V_180 , V_230 ) ;
if ( V_103 )
goto V_202;
V_118 = & V_10 -> V_116 -> V_135 [ 0 ] ;
V_103 = F_86 ( V_10 , V_215 ) ;
if ( V_103 )
goto V_231;
V_10 -> V_203 = 0 ;
do {
F_71 ( 500 ) ;
F_80 ( V_118 ) ;
if ( V_218 ++ > V_222 ) {
F_38 ( V_180 , L_19
L_20 ) ;
V_103 = - V_232 ;
goto V_231;
} else if ( V_10 -> V_203 ) {
V_103 = V_10 -> V_203 ;
goto V_231;
}
} while ( ! F_87 ( V_10 -> V_28 -> V_233 ) );
V_103 = F_76 ( V_10 , V_215 ) ;
F_88 ( V_10 ) ;
V_231:
F_72 ( V_180 , V_134 ) ;
V_202:
V_10 -> V_134 = V_134 ;
F_73 ( V_200 , & V_10 -> V_128 ) ;
return V_103 ;
}
static void
F_89 ( struct V_1 * V_2 , struct V_234 * V_235 ,
T_5 * V_209 )
{
memset ( V_209 , 0 , sizeof( T_5 ) * V_192 ) ;
V_209 [ 0 ] = F_64 ( V_2 ) ;
if ( V_209 [ 0 ] )
V_235 -> V_194 |= V_236 ;
V_209 [ 1 ] = ( T_5 ) F_21 ( V_2 ) ;
if ( V_209 [ 1 ] )
V_235 -> V_194 |= V_236 ;
if ( V_235 -> V_194 & V_237 ) {
V_209 [ 2 ] = F_67 ( V_2 ) ;
if ( V_209 [ 2 ] )
V_235 -> V_194 |= V_236 ;
V_209 [ 3 ] = F_84 ( V_2 , V_224 ) ;
if ( V_209 [ 3 ] )
V_235 -> V_194 |= V_236 ;
if ( V_235 -> V_194 & V_238 ) {
V_209 [ 4 ] = F_84 ( V_2 , V_239 ) ;
if ( V_209 [ 4 ] )
V_235 -> V_194 |= V_236 ;
V_235 -> V_194 |= V_240 ;
}
}
}
static void
F_90 ( struct V_1 * V_2 , T_1 V_241 , T_3 * V_209 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_242 , V_121 ;
switch ( V_241 ) {
case V_191 :
memcpy ( V_209 , * V_243 ,
V_192 * V_244 ) ;
break;
case V_193 :
for ( V_242 = 0 ; V_242 < V_196 ; V_242 ++ ) {
memcpy ( V_209 + V_242 * V_244 ,
V_245 [ V_242 ] . V_246 ,
V_244 ) ;
}
if ( ! ( V_10 -> V_194 & V_195 ) )
return;
for ( V_121 = 0 ; V_121 < V_197 ; V_242 ++ , V_121 ++ ) {
memcpy ( V_209 + V_242 * V_244 ,
V_247 [ V_121 ] ,
V_244 ) ;
}
}
}
static void
F_91 ( int * V_242 , T_5 * V_209 ,
struct V_248 * V_249 )
{
int V_250 = * V_242 ;
V_209 [ V_250 ++ ] = F_92 ( V_249 -> V_251 ) ;
V_209 [ V_250 ++ ] = F_92 ( V_249 -> V_252 ) ;
V_209 [ V_250 ++ ] = F_92 ( V_249 -> V_253 ) ;
V_209 [ V_250 ++ ] = F_92 ( V_249 -> V_254 ) ;
V_209 [ V_250 ++ ] = F_92 ( V_249 -> V_255 ) ;
V_209 [ V_250 ++ ] = F_92 ( V_249 -> V_256 ) ;
V_209 [ V_250 ++ ] = F_92 ( V_249 -> V_257 ) ;
* V_242 = V_250 ;
}
static void
F_93 ( struct V_1 * V_2 ,
struct V_258 * V_249 , T_5 * V_209 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_259 V_260 ;
int V_242 , V_103 ;
for ( V_242 = 0 ; V_242 < V_196 ; V_242 ++ ) {
char * V_114 =
( char * ) V_10 +
V_245 [ V_242 ] . V_261 ;
V_209 [ V_242 ] =
( V_245 [ V_242 ] . V_262 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_114 : ( * ( T_1 * ) V_114 ) ;
}
if ( ! ( V_10 -> V_194 & V_195 ) )
return;
memset ( & V_260 , 0 , sizeof( struct V_259 ) ) ;
V_103 = F_94 ( V_10 , V_10 -> V_28 -> V_29 ,
V_263 , & V_260 . V_264 ) ;
if ( V_103 )
return;
F_91 ( & V_242 , V_209 , & V_260 . V_264 ) ;
V_103 = F_94 ( V_10 , V_10 -> V_28 -> V_29 ,
V_265 , & V_260 . V_266 ) ;
if ( V_103 )
return;
F_91 ( & V_242 , V_209 , & V_260 . V_266 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
enum V_267 V_128 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_134 = V_10 -> V_134 ;
int V_177 = - V_60 , V_268 = 1 ;
if ( V_10 -> V_227 == V_228 ) {
F_85 ( V_2 , L_21
L_18 ) ;
return - V_104 ;
}
switch ( V_128 ) {
case V_269 :
if ( F_68 ( V_270 , & V_10 -> V_128 ) )
return - V_229 ;
if ( F_18 ( V_200 , & V_10 -> V_128 ) )
break;
if ( ! F_18 ( V_127 , & V_10 -> V_128 ) ) {
if ( F_69 ( V_2 , V_271 ) )
break;
F_96 ( V_272 , & V_10 -> V_128 ) ;
}
if ( V_10 -> V_273 -> V_274 ( V_10 , 1 , 0xf ) == 0 ) {
V_177 = 0 ;
break;
}
F_13 ( & V_10 -> V_19 -> V_2 ,
L_22 ) ;
break;
case V_275 :
V_268 = 0 ;
if ( F_18 ( V_200 , & V_10 -> V_128 ) )
break;
if ( ! F_18 ( V_127 , & V_10 -> V_128 ) ) {
if ( F_69 ( V_2 , V_271 ) )
break;
F_96 ( V_272 , & V_10 -> V_128 ) ;
}
if ( V_10 -> V_273 -> V_274 ( V_10 , 0 , 0xf ) )
F_13 ( & V_10 -> V_19 -> V_2 ,
L_23 ) ;
break;
default:
return - V_144 ;
}
if ( F_97 ( V_272 , & V_10 -> V_128 ) )
F_72 ( V_2 , V_134 ) ;
if ( ! V_268 || V_177 )
F_73 ( V_270 , & V_10 -> V_128 ) ;
return V_177 ;
}
static void
F_98 ( struct V_1 * V_2 , struct V_276 * V_277 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_278 ;
V_277 -> V_32 = 0 ;
V_277 -> V_279 = 0 ;
V_278 = F_5 ( V_10 , V_280 ) ;
if ( V_278 & ( 1UL << V_10 -> V_281 ) )
V_277 -> V_32 |= V_282 ;
V_278 = F_5 ( V_10 , V_283 ) ;
if ( V_278 & ( 1UL << V_10 -> V_281 ) )
V_277 -> V_279 |= V_282 ;
}
static int
F_99 ( struct V_1 * V_2 , struct V_276 * V_277 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_278 ;
if ( V_277 -> V_279 & ~ V_282 )
return - V_104 ;
V_278 = F_5 ( V_10 , V_280 ) ;
if ( ! ( V_278 & ( 1 << V_10 -> V_281 ) ) )
return - V_104 ;
V_278 = F_5 ( V_10 , V_283 ) ;
if ( V_277 -> V_279 & V_282 )
V_278 |= 1UL << V_10 -> V_281 ;
else
V_278 &= ~ ( 1UL << V_10 -> V_281 ) ;
F_51 ( V_10 , V_283 , V_278 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_180 ,
struct V_284 * V_285 )
{
struct V_9 * V_10 = F_4 ( V_180 ) ;
if ( ! F_18 ( V_127 , & V_10 -> V_128 ) )
return - V_144 ;
if ( V_285 -> V_286 > 0xffff ||
V_285 -> V_287 > 0xffff ||
V_285 -> V_288 ||
V_285 -> V_289 ||
V_285 -> V_290 ||
V_285 -> V_291 ||
V_285 -> V_292 ||
V_285 -> V_293 ||
V_285 -> V_294 ||
V_285 -> V_295 ||
V_285 -> V_296 ||
V_285 -> V_297 ||
V_285 -> V_298 ||
V_285 -> V_299 ||
V_285 -> V_300 ||
V_285 -> V_301 ||
V_285 -> V_302 ||
V_285 -> V_303 ||
V_285 -> V_304 ||
V_285 -> V_305 ||
V_285 -> V_306 )
return - V_144 ;
if ( ! V_285 -> V_286 ||
! V_285 -> V_287 ) {
V_10 -> V_28 -> V_307 . V_308 = V_309 ;
V_10 -> V_28 -> V_307 . V_310 =
V_311 ;
V_10 -> V_28 -> V_307 . V_312 =
V_313 ;
} else {
V_10 -> V_28 -> V_307 . V_308 = 0 ;
V_10 -> V_28 -> V_307 . V_310 = V_285 -> V_286 ;
V_10 -> V_28 -> V_307 . V_312 =
V_285 -> V_287 ;
}
F_101 ( V_10 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_180 ,
struct V_284 * V_285 )
{
struct V_9 * V_10 = F_4 ( V_180 ) ;
if ( V_10 -> V_314 != V_315 )
return - V_144 ;
V_285 -> V_286 = V_10 -> V_28 -> V_307 . V_310 ;
V_285 -> V_287 = V_10 -> V_28 -> V_307 . V_312 ;
return 0 ;
}
static T_1 F_103 ( struct V_1 * V_180 )
{
struct V_9 * V_10 = F_4 ( V_180 ) ;
return V_10 -> V_316 ;
}
static void F_104 ( struct V_1 * V_180 , T_1 V_317 )
{
struct V_9 * V_10 = F_4 ( V_180 ) ;
V_10 -> V_316 = V_317 ;
}
static int
F_105 ( struct V_1 * V_180 , struct V_318 * V_319 )
{
struct V_9 * V_10 = F_4 ( V_180 ) ;
struct V_320 * V_321 = & V_10 -> V_28 -> V_321 ;
if ( V_321 -> V_322 )
V_319 -> V_143 = V_321 -> V_323 -> V_324 + V_321 -> V_324 ;
else
V_319 -> V_143 = 0 ;
V_319 -> V_308 = V_321 -> V_323 -> V_325 ;
V_319 -> V_22 = V_10 -> V_17 ;
return 0 ;
}
static int
F_106 ( struct V_1 * V_180 , struct V_318 * V_319 ,
void * V_326 )
{
int V_121 , V_327 ;
T_1 * V_328 , * V_209 ;
struct V_9 * V_10 = F_4 ( V_180 ) ;
struct V_320 * V_321 = & V_10 -> V_28 -> V_321 ;
if ( ! V_321 -> V_322 ) {
F_38 ( V_180 , L_24 ) ;
F_107 ( V_10 ) ;
return - V_144 ;
}
V_327 = V_321 -> V_323 -> V_324 ;
V_328 = ( T_1 * ) V_321 -> V_323 ;
V_209 = V_326 ;
for ( V_121 = 0 ; V_121 < V_327 / sizeof( T_1 ) ; V_121 ++ )
* V_209 ++ = F_108 ( * V_328 ++ ) ;
memcpy ( V_326 + V_327 , V_321 -> V_209 , V_321 -> V_324 ) ;
V_319 -> V_143 = V_327 + V_321 -> V_324 ;
V_319 -> V_308 = V_321 -> V_323 -> V_325 ;
F_109 ( V_321 -> V_209 ) ;
V_321 -> V_209 = NULL ;
V_321 -> V_322 = 0 ;
return 0 ;
}
static int
F_110 ( struct V_1 * V_180 , struct V_318 * V_50 )
{
int V_103 = 0 ;
struct V_9 * V_10 = F_4 ( V_180 ) ;
struct V_320 * V_321 = & V_10 -> V_28 -> V_321 ;
switch ( V_50 -> V_308 ) {
case V_329 :
if ( ! V_321 -> V_330 ) {
F_38 ( V_180 , L_25 ) ;
return V_103 ;
}
if ( V_321 -> V_322 ) {
F_111 ( & V_10 -> V_19 -> V_2 ,
L_26 ) ;
return V_103 ;
}
F_38 ( V_180 , L_27 ) ;
F_112 ( V_10 ) ;
break;
case V_331 :
if ( V_321 -> V_330 ) {
F_38 ( V_180 , L_28 ) ;
V_321 -> V_330 = 0 ;
}
break;
case V_332 :
if ( ! V_321 -> V_330 && V_321 -> V_323 ) {
F_38 ( V_180 , L_29 ) ;
V_321 -> V_330 = 1 ;
}
break;
case V_333 :
F_38 ( V_180 , L_30 ) ;
F_112 ( V_10 ) ;
V_10 -> V_194 &= ~ V_334 ;
break;
default:
if ( V_50 -> V_308 > V_335 ||
V_50 -> V_308 < V_336 ) {
F_38 ( V_180 ,
L_31 , V_50 -> V_308 ) ;
V_103 = - V_144 ;
goto V_337;
}
V_321 -> V_323 -> V_325 = V_50 -> V_308 & 0xff ;
F_38 ( V_180 , L_32 ,
V_321 -> V_323 -> V_325 ) ;
}
V_337:
return V_103 ;
}
