static void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
F_2 ( V_2 ,
V_5 ,
( const V_6 ) F_3 ( V_5 ) ) ;
F_2 ( V_2 ,
V_7 ,
( const V_6 ) F_3 ( V_7 ) ) ;
break;
case V_8 :
F_2 ( V_2 ,
V_9 ,
( const V_6 ) F_3 ( V_9 ) ) ;
F_2 ( V_2 ,
V_10 ,
( const V_6 ) F_3 ( V_10 ) ) ;
break;
case V_11 :
F_2 ( V_2 ,
V_12 ,
( const V_6 ) F_3 ( V_12 ) ) ;
break;
case V_13 :
F_2 ( V_2 ,
V_14 ,
( const V_6 ) F_3 ( V_14 ) ) ;
break;
case V_15 :
F_2 ( V_2 ,
V_16 ,
( const V_6 ) F_3 ( V_16 ) ) ;
break;
case V_17 :
F_2 ( V_2 ,
V_18 ,
( const V_6 ) F_3 ( V_18 ) ) ;
F_2 ( V_2 ,
V_19 ,
( const V_6 ) F_3 ( V_19 ) ) ;
break;
default:
break;
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
V_6 V_22 ;
if ( V_2 -> V_23 . V_24 )
F_5 ( V_2 , V_21 ) ;
F_6 ( V_2 ) ;
V_22 = F_7 ( V_25 ) ;
if ( F_8 ( V_22 , V_26 , V_27 ) != 1 ) {
F_9 ( V_28 , 0 ) ;
V_22 = F_10 ( V_22 ,
V_26 , V_27 , 1 ) ;
F_9 ( V_25 , V_22 ) ;
}
F_11 ( 100 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
V_6 V_29 ;
V_29 = F_7 ( V_25 ) ;
V_29 = F_10 ( V_29 , V_26 , V_27 , 0 ) ;
F_9 ( V_25 , V_29 ) ;
V_29 = F_10 ( 0 , V_30 , V_31 , 1 ) ;
V_29 = F_10 ( V_29 , V_30 , V_32 , 1 ) ;
F_9 ( V_28 , V_29 ) ;
if ( V_2 -> V_23 . V_24 )
F_13 ( V_2 , V_21 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
const char * V_33 ;
char V_34 [ 30 ] ;
int V_35 ;
F_15 ( L_1 ) ;
switch ( V_2 -> V_3 ) {
case V_8 :
V_33 = L_2 ;
break;
case V_11 :
V_33 = L_3 ;
break;
case V_13 :
V_33 = L_4 ;
break;
case V_4 :
case V_15 :
case V_17 :
return 0 ;
default: F_16 () ;
}
snprintf ( V_34 , sizeof( V_34 ) , L_5 , V_33 ) ;
V_35 = F_17 ( & V_2 -> V_36 . V_37 , V_34 , V_2 -> V_38 ) ;
if ( V_35 )
goto V_39;
V_35 = F_18 ( V_2 -> V_36 . V_37 ) ;
V_39:
if ( V_35 ) {
F_19 ( V_40
L_6 ,
V_34 ) ;
F_20 ( V_2 -> V_36 . V_37 ) ;
V_2 -> V_36 . V_37 = NULL ;
}
return V_35 ;
}
static int F_21 ( struct V_1 * V_2 )
{
const struct V_41 * V_42 ;
const T_1 * V_43 = NULL ;
const T_1 * V_44 = NULL ;
V_6 V_45 , V_22 = 0 ;
int V_46 , V_47 , V_48 ;
if ( ! V_2 -> V_36 . V_37 )
return - V_49 ;
if ( V_2 -> V_50 . V_51 )
return 0 ;
V_42 = ( const struct V_41 * ) V_2 -> V_36 . V_37 -> V_52 ;
F_22 ( & V_42 -> V_53 ) ;
V_2 -> V_36 . V_54 = F_23 ( V_42 -> V_53 . V_55 ) ;
V_48 = F_23 ( V_42 -> V_56 ) / ( 4 * 2 ) ;
V_44 = ( const T_1 * )
( V_2 -> V_36 . V_37 -> V_52 + F_23 ( V_42 -> V_57 ) ) ;
V_47 = F_23 ( V_42 -> V_53 . V_58 ) / 4 ;
V_43 = ( const T_1 * )
( V_2 -> V_36 . V_37 -> V_52 + F_23 ( V_42 -> V_53 . V_59 ) ) ;
V_45 = F_8 ( F_7 ( V_60 ) , V_61 , V_62 ) ;
if ( V_45 == 0 ) {
if ( V_45 ) {
V_22 = F_7 ( V_25 ) ;
F_9 ( V_25 , V_22 | 1 ) ;
}
F_9 ( V_60 , 0x00000008 ) ;
F_9 ( V_60 , 0x00000010 ) ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
F_9 ( V_63 , F_24 ( V_44 ++ ) ) ;
F_9 ( V_64 , F_24 ( V_44 ++ ) ) ;
}
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ )
F_9 ( V_65 , F_24 ( V_43 ++ ) ) ;
F_9 ( V_60 , 0x00000008 ) ;
F_9 ( V_60 , 0x00000004 ) ;
F_9 ( V_60 , 0x00000001 ) ;
for ( V_46 = 0 ; V_46 < V_2 -> V_66 ; V_46 ++ ) {
if ( F_8 ( F_7 ( V_67 ) ,
V_68 , V_69 ) )
break;
F_11 ( 1 ) ;
}
for ( V_46 = 0 ; V_46 < V_2 -> V_66 ; V_46 ++ ) {
if ( F_8 ( F_7 ( V_67 ) ,
V_68 , V_70 ) )
break;
F_11 ( 1 ) ;
}
if ( V_45 )
F_9 ( V_25 , V_22 ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_71 * V_36 )
{
if ( V_36 -> V_72 > 0xFFC0000000ULL ) {
F_26 ( V_2 -> V_38 , L_7 ) ;
V_36 -> V_73 = 0xFFC0000000ULL ;
V_36 -> V_72 = 0xFFC0000000ULL ;
}
F_27 ( V_2 , & V_2 -> V_36 , 0 ) ;
V_2 -> V_36 . V_74 = 0 ;
F_28 ( V_2 , V_36 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
V_6 V_29 ;
int V_46 , V_75 ;
for ( V_46 = 0 , V_75 = 0 ; V_46 < 32 ; V_46 ++ , V_75 += 0x6 ) {
F_9 ( ( 0xb05 + V_75 ) , 0x00000000 ) ;
F_9 ( ( 0xb06 + V_75 ) , 0x00000000 ) ;
F_9 ( ( 0xb07 + V_75 ) , 0x00000000 ) ;
F_9 ( ( 0xb08 + V_75 ) , 0x00000000 ) ;
F_9 ( ( 0xb09 + V_75 ) , 0x00000000 ) ;
}
F_9 ( V_76 , 0 ) ;
if ( V_2 -> V_23 . V_24 )
F_30 ( V_2 , false ) ;
F_4 ( V_2 , & V_21 ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_26 ( V_2 -> V_38 , L_8 ) ;
}
F_9 ( V_77 ,
V_2 -> V_36 . V_78 >> 12 ) ;
F_9 ( V_79 ,
V_2 -> V_36 . V_80 >> 12 ) ;
F_9 ( V_81 ,
V_2 -> V_82 . V_83 >> 12 ) ;
V_29 = ( ( V_2 -> V_36 . V_80 >> 24 ) & 0xFFFF ) << 16 ;
V_29 |= ( ( V_2 -> V_36 . V_78 >> 24 ) & 0xFFFF ) ;
F_9 ( V_84 , V_29 ) ;
F_9 ( V_85 , ( V_2 -> V_36 . V_78 >> 8 ) ) ;
F_9 ( V_86 , ( 2 << 7 ) | ( 1 << 30 ) ) ;
F_9 ( V_87 , 0x3FFFFFFF ) ;
F_9 ( V_88 , 0 ) ;
F_9 ( V_89 , 0x0FFFFFFF ) ;
F_9 ( V_90 , 0x0FFFFFFF ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_26 ( V_2 -> V_38 , L_8 ) ;
}
F_12 ( V_2 , & V_21 ) ;
F_9 ( V_28 , V_91 | V_92 ) ;
V_29 = F_7 ( V_93 ) ;
V_29 = F_10 ( V_29 , V_94 , V_95 , 0 ) ;
F_9 ( V_93 , V_29 ) ;
V_29 = F_7 ( V_96 ) ;
F_9 ( V_96 , V_29 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
V_6 V_29 ;
int V_97 , V_98 ;
V_29 = F_7 ( V_99 ) ;
if ( F_8 ( V_29 , V_100 , V_101 ) ) {
V_97 = 64 ;
} else {
V_97 = 32 ;
}
V_29 = F_7 ( V_102 ) ;
switch ( F_8 ( V_29 , V_103 , V_104 ) ) {
case 0 :
default:
V_98 = 1 ;
break;
case 1 :
V_98 = 2 ;
break;
case 2 :
V_98 = 4 ;
break;
case 3 :
V_98 = 8 ;
break;
case 4 :
V_98 = 3 ;
break;
case 5 :
V_98 = 6 ;
break;
case 6 :
V_98 = 10 ;
break;
case 7 :
V_98 = 12 ;
break;
case 8 :
V_98 = 16 ;
break;
}
V_2 -> V_36 . V_105 = V_98 * V_97 ;
V_2 -> V_36 . V_106 = F_32 ( V_2 -> V_107 , 0 ) ;
V_2 -> V_36 . V_108 = F_33 ( V_2 -> V_107 , 0 ) ;
V_2 -> V_36 . V_72 = F_7 ( V_109 ) * 1024ULL * 1024ULL ;
V_2 -> V_36 . V_73 = F_7 ( V_109 ) * 1024ULL * 1024ULL ;
V_2 -> V_36 . V_110 = V_2 -> V_36 . V_108 ;
if ( V_2 -> V_36 . V_110 > V_2 -> V_36 . V_73 )
V_2 -> V_36 . V_110 = V_2 -> V_36 . V_73 ;
if ( V_111 == - 1 )
V_2 -> V_36 . V_112 = F_34 ( ( 1024ULL << 20 ) , V_2 -> V_36 . V_72 ) ;
else
V_2 -> V_36 . V_112 = ( V_113 ) V_111 << 20 ;
F_25 ( V_2 , & V_2 -> V_36 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
T_2 V_114 )
{
F_9 ( V_115 , 0 ) ;
F_9 ( V_116 , 1 << V_114 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
void * V_117 ,
T_2 V_118 ,
V_113 V_119 ,
T_2 V_120 )
{
void T_3 * V_121 = ( void * ) V_117 ;
V_113 V_122 ;
V_122 = V_119 & 0x000000FFFFFFF000ULL ;
V_122 |= V_120 ;
F_37 ( V_122 , V_121 + ( V_118 * 8 ) ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
bool V_122 )
{
V_6 V_29 ;
V_29 = F_7 ( V_123 ) ;
V_29 = F_10 ( V_29 , V_124 ,
V_125 , V_122 ) ;
V_29 = F_10 ( V_29 , V_124 ,
V_126 , V_122 ) ;
V_29 = F_10 ( V_29 , V_124 ,
V_127 , V_122 ) ;
V_29 = F_10 ( V_29 , V_124 ,
V_128 , V_122 ) ;
V_29 = F_10 ( V_29 , V_124 ,
V_129 , V_122 ) ;
V_29 = F_10 ( V_29 , V_124 ,
V_130 , V_122 ) ;
V_29 = F_10 ( V_29 , V_124 ,
V_131 , V_122 ) ;
F_9 ( V_123 , V_29 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_132 , V_46 ;
V_6 V_29 ;
if ( V_2 -> V_133 . V_134 == NULL ) {
F_40 ( V_2 -> V_38 , L_9 ) ;
return - V_49 ;
}
V_132 = F_41 ( V_2 ) ;
if ( V_132 )
return V_132 ;
V_29 = F_7 ( V_135 ) ;
V_29 = F_10 ( V_29 , V_136 , V_137 , 1 ) ;
V_29 = F_10 ( V_29 , V_136 , V_138 , 1 ) ;
V_29 = F_10 ( V_29 , V_136 , V_139 , 3 ) ;
V_29 = F_10 ( V_29 , V_136 , V_140 , 1 ) ;
V_29 = F_10 ( V_29 , V_136 , V_141 , 0 ) ;
F_9 ( V_135 , V_29 ) ;
V_29 = F_7 ( V_142 ) ;
V_29 = F_10 ( V_29 , V_143 , V_144 , 1 ) ;
V_29 = F_10 ( V_29 , V_143 , V_145 , 1 ) ;
V_29 = F_10 ( V_29 , V_143 , V_146 , 1 ) ;
V_29 = F_10 ( V_29 , V_143 , V_147 , 1 ) ;
V_29 = F_10 ( V_29 , V_143 , V_148 , 7 ) ;
V_29 = F_10 ( V_29 , V_143 , V_149 , 1 ) ;
V_29 = F_10 ( V_29 , V_143 , V_150 , 1 ) ;
F_9 ( V_142 , V_29 ) ;
V_29 = F_7 ( V_151 ) ;
V_29 = F_10 ( V_29 , V_152 , V_153 , 1 ) ;
V_29 = F_10 ( V_29 , V_152 , V_154 , 1 ) ;
F_9 ( V_151 , V_29 ) ;
V_29 = F_7 ( V_155 ) ;
V_29 = F_10 ( V_29 , V_156 , V_157 , 1 ) ;
V_29 = F_10 ( V_29 , V_156 , V_158 , 4 ) ;
V_29 = F_10 ( V_29 , V_156 , V_159 , 4 ) ;
F_9 ( V_155 , V_29 ) ;
V_29 = F_7 ( V_160 ) ;
V_29 = F_10 ( V_29 , V_161 , V_162 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_163 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_164 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_165 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_166 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_167 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_168 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_169 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_170 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_171 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_172 , 0 ) ;
V_29 = F_10 ( V_29 , V_161 , V_173 , 0 ) ;
F_9 ( V_160 , V_29 ) ;
F_9 ( V_174 , V_2 -> V_36 . V_175 >> 12 ) ;
F_9 ( V_176 , V_2 -> V_36 . V_177 >> 12 ) ;
F_9 ( V_178 , V_2 -> V_133 . V_179 >> 12 ) ;
F_9 ( V_180 ,
( V_6 ) ( V_2 -> V_181 . V_119 >> 12 ) ) ;
F_9 ( V_182 , 0 ) ;
V_29 = F_7 ( V_183 ) ;
V_29 = F_10 ( V_29 , V_184 , V_185 , 1 ) ;
V_29 = F_10 ( V_29 , V_184 , V_186 , 0 ) ;
V_29 = F_10 ( V_29 , V_184 , V_125 , 1 ) ;
F_9 ( V_183 , V_29 ) ;
F_9 ( V_187 , 0 ) ;
F_9 ( V_188 , 0 ) ;
F_9 ( V_189 , 0 ) ;
F_9 ( V_190 , 0 ) ;
F_9 ( V_191 , V_2 -> V_192 . V_193 - 1 ) ;
for ( V_46 = 1 ; V_46 < 16 ; V_46 ++ ) {
if ( V_46 < 8 )
F_9 ( V_178 + V_46 ,
V_2 -> V_133 . V_179 >> 12 ) ;
else
F_9 ( V_194 + V_46 - 8 ,
V_2 -> V_133 . V_179 >> 12 ) ;
}
F_9 ( V_195 ,
( V_6 ) ( V_2 -> V_181 . V_119 >> 12 ) ) ;
F_9 ( V_196 , 4 ) ;
V_29 = F_7 ( V_123 ) ;
V_29 = F_10 ( V_29 , V_124 , V_185 , 1 ) ;
V_29 = F_10 ( V_29 , V_124 , V_186 , 1 ) ;
V_29 = F_10 ( V_29 , V_124 , V_125 , 1 ) ;
V_29 = F_10 ( V_29 , V_124 , V_126 , 1 ) ;
V_29 = F_10 ( V_29 , V_124 , V_127 , 1 ) ;
V_29 = F_10 ( V_29 , V_124 , V_128 , 1 ) ;
V_29 = F_10 ( V_29 , V_124 , V_129 , 1 ) ;
V_29 = F_10 ( V_29 , V_124 , V_130 , 1 ) ;
V_29 = F_10 ( V_29 , V_124 , V_131 , 1 ) ;
V_29 = F_10 ( V_29 , V_124 , V_197 ,
V_198 - 9 ) ;
F_9 ( V_123 , V_29 ) ;
if ( V_199 == V_200 )
F_38 ( V_2 , false ) ;
else
F_38 ( V_2 , true ) ;
F_35 ( V_2 , 0 ) ;
F_42 ( L_10 ,
( unsigned ) ( V_2 -> V_36 . V_112 >> 20 ) ,
( unsigned long long ) V_2 -> V_133 . V_179 ) ;
V_2 -> V_133 . V_201 = true ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_132 ;
if ( V_2 -> V_133 . V_134 ) {
F_44 ( 1 , L_11 ) ;
return 0 ;
}
V_132 = F_45 ( V_2 ) ;
if ( V_132 )
return V_132 ;
V_2 -> V_133 . V_202 = V_2 -> V_133 . V_203 * 8 ;
return F_46 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
V_6 V_29 ;
F_9 ( V_183 , 0 ) ;
F_9 ( V_123 , 0 ) ;
V_29 = F_7 ( V_135 ) ;
V_29 = F_10 ( V_29 , V_136 , V_137 , 0 ) ;
V_29 = F_10 ( V_29 , V_136 , V_138 , 0 ) ;
V_29 = F_10 ( V_29 , V_136 , V_140 , 0 ) ;
F_9 ( V_135 , V_29 ) ;
V_29 = F_7 ( V_142 ) ;
V_29 = F_10 ( V_29 , V_143 , V_144 , 0 ) ;
F_9 ( V_142 , V_29 ) ;
F_9 ( V_151 , 0 ) ;
F_48 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
V_2 -> V_192 . V_204 = V_205 ;
F_53 ( V_2 ) ;
if ( V_2 -> V_120 & V_206 ) {
T_4 V_29 = F_7 ( V_207 ) ;
V_29 <<= 22 ;
V_2 -> V_192 . V_208 = V_29 ;
} else
V_2 -> V_192 . V_208 = 0 ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
}
static void F_55 ( struct V_1 * V_2 ,
V_6 V_209 , V_6 V_119 , V_6 V_210 )
{
V_6 V_211 ;
V_6 V_114 = F_8 ( V_209 , V_212 , V_213 ) ;
V_6 V_214 = F_8 ( V_209 , V_212 ,
V_215 ) ;
char V_216 [ 5 ] = { V_210 >> 24 , ( V_210 >> 16 ) & 0xff ,
( V_210 >> 8 ) & 0xff , V_210 & 0xff , 0 } ;
V_211 = F_8 ( V_209 , V_212 ,
V_217 ) ;
F_19 ( L_12 ,
V_214 , V_114 , V_119 ,
F_8 ( V_209 , V_212 ,
V_218 ) ?
L_13 : L_14 , V_216 , V_210 , V_211 ) ;
}
static int F_56 ( int V_219 )
{
switch ( V_219 ) {
case V_220 :
return V_221 ;
case V_222 :
return V_223 ;
case V_224 :
return V_225 ;
case V_226 :
return V_227 ;
case V_228 :
return V_229 ;
case V_230 :
return V_231 ;
case V_232 :
return V_233 ;
default:
return V_234 ;
}
}
static int F_57 ( void * V_235 )
{
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_60 ( void * V_235 )
{
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
if ( V_199 != V_200 )
return F_61 ( V_2 , & V_2 -> V_36 . V_236 , 0 ) ;
else
return 0 ;
}
static int F_62 ( void * V_235 )
{
int V_132 ;
int V_237 ;
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
if ( V_2 -> V_120 & V_206 ) {
V_2 -> V_36 . V_238 = V_234 ;
} else {
V_6 V_29 ;
if ( V_2 -> V_3 == V_4 )
V_29 = F_7 ( V_239 ) ;
else
V_29 = F_7 ( V_240 ) ;
V_29 &= V_241 ;
V_2 -> V_36 . V_238 = F_56 ( V_29 ) ;
}
V_132 = F_63 ( V_2 , 146 , & V_2 -> V_36 . V_236 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_63 ( V_2 , 147 , & V_2 -> V_36 . V_236 ) ;
if ( V_132 )
return V_132 ;
V_2 -> V_192 . V_193 = V_242 << 18 ;
V_2 -> V_36 . V_243 = 0xffffffffffULL ;
V_2 -> V_244 = false ;
V_237 = V_2 -> V_244 ? 32 : 40 ;
V_132 = F_64 ( V_2 -> V_107 , F_65 ( V_237 ) ) ;
if ( V_132 ) {
V_2 -> V_244 = true ;
V_237 = 32 ;
F_19 ( V_245 L_15 ) ;
}
V_132 = F_66 ( V_2 -> V_107 , F_65 ( V_237 ) ) ;
if ( V_132 ) {
F_66 ( V_2 -> V_107 , F_65 ( 32 ) ) ;
F_19 ( V_245 L_16 ) ;
}
V_132 = F_14 ( V_2 ) ;
if ( V_132 ) {
F_67 ( L_17 ) ;
return V_132 ;
}
V_132 = F_31 ( V_2 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_68 ( V_2 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_43 ( V_2 ) ;
if ( V_132 )
return V_132 ;
if ( ! V_2 -> V_192 . V_246 ) {
V_132 = F_52 ( V_2 ) ;
if ( V_132 ) {
F_40 ( V_2 -> V_38 , L_18 , V_132 ) ;
return V_132 ;
}
V_2 -> V_192 . V_246 = true ;
}
return V_132 ;
}
static int F_69 ( void * V_235 )
{
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
if ( V_2 -> V_192 . V_246 ) {
F_70 ( V_2 ) ;
F_54 ( V_2 ) ;
V_2 -> V_192 . V_246 = false ;
}
F_49 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
return 0 ;
}
static int F_73 ( void * V_235 )
{
int V_132 ;
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
F_1 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( V_2 -> V_3 == V_8 ) {
V_132 = F_21 ( V_2 ) ;
if ( V_132 ) {
F_67 ( L_19 ) ;
return V_132 ;
}
}
V_132 = F_39 ( V_2 ) ;
if ( V_132 )
return V_132 ;
return V_132 ;
}
static int F_74 ( void * V_235 )
{
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
F_75 ( V_2 , & V_2 -> V_36 . V_236 , 0 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_76 ( void * V_235 )
{
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
if ( V_2 -> V_192 . V_246 ) {
F_54 ( V_2 ) ;
V_2 -> V_192 . V_246 = false ;
}
F_74 ( V_2 ) ;
return 0 ;
}
static int F_77 ( void * V_235 )
{
int V_132 ;
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
V_132 = F_73 ( V_2 ) ;
if ( V_132 )
return V_132 ;
if ( ! V_2 -> V_192 . V_246 ) {
V_132 = F_52 ( V_2 ) ;
if ( V_132 ) {
F_40 ( V_2 -> V_38 , L_18 , V_132 ) ;
return V_132 ;
}
V_2 -> V_192 . V_246 = true ;
}
return V_132 ;
}
static bool F_78 ( void * V_235 )
{
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
V_6 V_29 = F_7 ( V_247 ) ;
if ( V_29 & ( V_248 | V_249 |
V_250 | V_251 | V_252 ) )
return false ;
return true ;
}
static int F_6 ( void * V_235 )
{
unsigned V_46 ;
V_6 V_29 ;
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_66 ; V_46 ++ ) {
V_29 = F_7 ( V_247 ) & ( V_248 |
V_249 |
V_250 |
V_251 |
V_252 |
V_253 ) ;
if ( ! V_29 )
return 0 ;
F_11 ( 1 ) ;
}
return - V_254 ;
}
static int F_79 ( void * V_235 )
{
struct V_20 V_21 ;
V_6 V_255 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
V_6 V_29 = F_7 ( V_247 ) ;
if ( V_29 & V_252 )
V_255 = F_10 ( V_255 ,
V_256 , V_257 , 1 ) ;
if ( V_29 & ( V_248 | V_249 |
V_250 | V_251 ) ) {
if ( ! ( V_2 -> V_120 & V_206 ) )
V_255 = F_10 ( V_255 ,
V_256 , V_258 , 1 ) ;
}
if ( V_255 ) {
F_4 ( V_2 , & V_21 ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_26 ( V_2 -> V_38 , L_20 ) ;
}
V_29 = F_7 ( V_259 ) ;
V_29 |= V_255 ;
F_80 ( V_2 -> V_38 , L_21 , V_29 ) ;
F_9 ( V_259 , V_29 ) ;
V_29 = F_7 ( V_259 ) ;
F_11 ( 50 ) ;
V_29 &= ~ V_255 ;
F_9 ( V_259 , V_29 ) ;
V_29 = F_7 ( V_259 ) ;
F_11 ( 50 ) ;
F_12 ( V_2 , & V_21 ) ;
F_11 ( 50 ) ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_260 * V_261 ,
unsigned type ,
enum V_262 V_263 )
{
V_6 V_29 ;
V_6 V_264 = ( V_265 |
V_266 |
V_267 |
V_268 |
V_269 |
V_270 |
V_271 ) ;
switch ( V_263 ) {
case V_272 :
V_29 = F_7 ( V_183 ) ;
V_29 &= ~ V_264 ;
F_9 ( V_183 , V_29 ) ;
V_29 = F_7 ( V_123 ) ;
V_29 &= ~ V_264 ;
F_9 ( V_123 , V_29 ) ;
break;
case V_273 :
V_29 = F_7 ( V_183 ) ;
V_29 |= V_264 ;
F_9 ( V_183 , V_29 ) ;
V_29 = F_7 ( V_123 ) ;
V_29 |= V_264 ;
F_9 ( V_123 , V_29 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_260 * V_274 ,
struct V_275 * V_276 )
{
V_6 V_119 , V_209 , V_210 ;
V_119 = F_7 ( V_277 ) ;
V_209 = F_7 ( V_278 ) ;
V_210 = F_7 ( V_279 ) ;
F_83 ( V_196 , 1 , ~ 1 ) ;
if ( ! V_119 && ! V_209 )
return 0 ;
if ( V_199 == V_280 )
F_38 ( V_2 , false ) ;
F_40 ( V_2 -> V_38 , L_22 ,
V_276 -> V_281 , V_276 -> V_282 ) ;
F_40 ( V_2 -> V_38 , L_23 ,
V_119 ) ;
F_40 ( V_2 -> V_38 , L_24 ,
V_209 ) ;
F_55 ( V_2 , V_209 , V_119 , V_210 ) ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 ,
bool V_283 )
{
T_2 V_52 ;
if ( V_283 && ( V_2 -> V_284 & V_285 ) ) {
V_52 = F_7 ( V_286 ) ;
V_52 |= V_287 ;
F_9 ( V_286 , V_52 ) ;
V_52 = F_7 ( V_288 ) ;
V_52 |= V_289 ;
F_9 ( V_288 , V_52 ) ;
V_52 = F_7 ( V_290 ) ;
V_52 |= V_291 ;
F_9 ( V_290 , V_52 ) ;
V_52 = F_7 ( V_292 ) ;
V_52 |= V_293 ;
F_9 ( V_292 , V_52 ) ;
V_52 = F_7 ( V_294 ) ;
V_52 |= V_295 ;
F_9 ( V_294 , V_52 ) ;
V_52 = F_7 ( V_296 ) ;
V_52 |= V_297 ;
F_9 ( V_296 , V_52 ) ;
V_52 = F_7 ( V_298 ) ;
V_52 |= V_299 ;
F_9 ( V_298 , V_52 ) ;
V_52 = F_7 ( V_300 ) ;
V_52 |= V_301 ;
F_9 ( V_300 , V_52 ) ;
V_52 = F_7 ( V_302 ) ;
V_52 |= V_303 ;
F_9 ( V_302 , V_52 ) ;
} else {
V_52 = F_7 ( V_286 ) ;
V_52 &= ~ V_287 ;
F_9 ( V_286 , V_52 ) ;
V_52 = F_7 ( V_288 ) ;
V_52 &= ~ V_289 ;
F_9 ( V_288 , V_52 ) ;
V_52 = F_7 ( V_290 ) ;
V_52 &= ~ V_291 ;
F_9 ( V_290 , V_52 ) ;
V_52 = F_7 ( V_292 ) ;
V_52 &= ~ V_293 ;
F_9 ( V_292 , V_52 ) ;
V_52 = F_7 ( V_294 ) ;
V_52 &= ~ V_295 ;
F_9 ( V_294 , V_52 ) ;
V_52 = F_7 ( V_296 ) ;
V_52 &= ~ V_297 ;
F_9 ( V_296 , V_52 ) ;
V_52 = F_7 ( V_298 ) ;
V_52 &= ~ V_299 ;
F_9 ( V_298 , V_52 ) ;
V_52 = F_7 ( V_300 ) ;
V_52 &= ~ V_301 ;
F_9 ( V_300 , V_52 ) ;
V_52 = F_7 ( V_302 ) ;
V_52 &= ~ V_303 ;
F_9 ( V_302 , V_52 ) ;
}
}
static void F_85 ( struct V_1 * V_2 ,
bool V_283 )
{
T_2 V_52 ;
if ( V_283 && ( V_2 -> V_284 & V_304 ) ) {
V_52 = F_7 ( V_286 ) ;
V_52 |= V_305 ;
F_9 ( V_286 , V_52 ) ;
V_52 = F_7 ( V_288 ) ;
V_52 |= V_306 ;
F_9 ( V_288 , V_52 ) ;
V_52 = F_7 ( V_290 ) ;
V_52 |= V_307 ;
F_9 ( V_290 , V_52 ) ;
V_52 = F_7 ( V_292 ) ;
V_52 |= V_308 ;
F_9 ( V_292 , V_52 ) ;
V_52 = F_7 ( V_294 ) ;
V_52 |= V_309 ;
F_9 ( V_294 , V_52 ) ;
V_52 = F_7 ( V_296 ) ;
V_52 |= V_310 ;
F_9 ( V_296 , V_52 ) ;
V_52 = F_7 ( V_298 ) ;
V_52 |= V_311 ;
F_9 ( V_298 , V_52 ) ;
V_52 = F_7 ( V_300 ) ;
V_52 |= V_312 ;
F_9 ( V_300 , V_52 ) ;
V_52 = F_7 ( V_302 ) ;
V_52 |= V_313 ;
F_9 ( V_302 , V_52 ) ;
} else {
V_52 = F_7 ( V_286 ) ;
V_52 &= ~ V_305 ;
F_9 ( V_286 , V_52 ) ;
V_52 = F_7 ( V_288 ) ;
V_52 &= ~ V_306 ;
F_9 ( V_288 , V_52 ) ;
V_52 = F_7 ( V_290 ) ;
V_52 &= ~ V_307 ;
F_9 ( V_290 , V_52 ) ;
V_52 = F_7 ( V_292 ) ;
V_52 &= ~ V_308 ;
F_9 ( V_292 , V_52 ) ;
V_52 = F_7 ( V_294 ) ;
V_52 &= ~ V_309 ;
F_9 ( V_294 , V_52 ) ;
V_52 = F_7 ( V_296 ) ;
V_52 &= ~ V_310 ;
F_9 ( V_296 , V_52 ) ;
V_52 = F_7 ( V_298 ) ;
V_52 &= ~ V_311 ;
F_9 ( V_298 , V_52 ) ;
V_52 = F_7 ( V_300 ) ;
V_52 &= ~ V_312 ;
F_9 ( V_300 , V_52 ) ;
V_52 = F_7 ( V_302 ) ;
V_52 &= ~ V_313 ;
F_9 ( V_302 , V_52 ) ;
}
}
static int F_86 ( void * V_235 ,
enum V_314 V_263 )
{
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
switch ( V_2 -> V_3 ) {
case V_4 :
F_84 ( V_2 ,
V_263 == V_315 ? true : false ) ;
F_85 ( V_2 ,
V_263 == V_315 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_87 ( void * V_235 ,
enum V_316 V_263 )
{
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_133 . V_317 == NULL )
V_2 -> V_133 . V_317 = & V_318 ;
}
static void F_59 ( struct V_1 * V_2 )
{
V_2 -> V_36 . V_236 . V_319 = 1 ;
V_2 -> V_36 . V_236 . V_320 = & V_321 ;
}
