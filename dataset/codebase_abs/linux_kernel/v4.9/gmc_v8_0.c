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
V_6 V_45 ;
int V_46 , V_47 , V_48 ;
if ( ! V_2 -> V_36 . V_37 )
return - V_49 ;
if ( F_22 ( V_2 ) )
return 0 ;
V_42 = ( const struct V_41 * ) V_2 -> V_36 . V_37 -> V_50 ;
F_23 ( & V_42 -> V_51 ) ;
V_2 -> V_36 . V_52 = F_24 ( V_42 -> V_51 . V_53 ) ;
V_48 = F_24 ( V_42 -> V_54 ) / ( 4 * 2 ) ;
V_44 = ( const T_1 * )
( V_2 -> V_36 . V_37 -> V_50 + F_24 ( V_42 -> V_55 ) ) ;
V_47 = F_24 ( V_42 -> V_51 . V_56 ) / 4 ;
V_43 = ( const T_1 * )
( V_2 -> V_36 . V_37 -> V_50 + F_24 ( V_42 -> V_51 . V_57 ) ) ;
V_45 = F_8 ( F_7 ( V_58 ) , V_59 , V_60 ) ;
if ( V_45 == 0 ) {
F_9 ( V_58 , 0x00000008 ) ;
F_9 ( V_58 , 0x00000010 ) ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
F_9 ( V_61 , F_25 ( V_44 ++ ) ) ;
F_9 ( V_62 , F_25 ( V_44 ++ ) ) ;
}
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ )
F_9 ( V_63 , F_25 ( V_43 ++ ) ) ;
F_9 ( V_58 , 0x00000008 ) ;
F_9 ( V_58 , 0x00000004 ) ;
F_9 ( V_58 , 0x00000001 ) ;
for ( V_46 = 0 ; V_46 < V_2 -> V_64 ; V_46 ++ ) {
if ( F_8 ( F_7 ( V_65 ) ,
V_66 , V_67 ) )
break;
F_11 ( 1 ) ;
}
for ( V_46 = 0 ; V_46 < V_2 -> V_64 ; V_46 ++ ) {
if ( F_8 ( F_7 ( V_65 ) ,
V_66 , V_68 ) )
break;
F_11 ( 1 ) ;
}
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_69 * V_36 )
{
if ( V_36 -> V_70 > 0xFFC0000000ULL ) {
F_27 ( V_2 -> V_38 , L_7 ) ;
V_36 -> V_71 = 0xFFC0000000ULL ;
V_36 -> V_70 = 0xFFC0000000ULL ;
}
F_28 ( V_2 , & V_2 -> V_36 , 0 ) ;
V_2 -> V_36 . V_72 = 0 ;
F_29 ( V_2 , V_36 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_20 V_21 ;
V_6 V_29 ;
int V_46 , V_73 ;
for ( V_46 = 0 , V_73 = 0 ; V_46 < 32 ; V_46 ++ , V_73 += 0x6 ) {
F_9 ( ( 0xb05 + V_73 ) , 0x00000000 ) ;
F_9 ( ( 0xb06 + V_73 ) , 0x00000000 ) ;
F_9 ( ( 0xb07 + V_73 ) , 0x00000000 ) ;
F_9 ( ( 0xb08 + V_73 ) , 0x00000000 ) ;
F_9 ( ( 0xb09 + V_73 ) , 0x00000000 ) ;
}
F_9 ( V_74 , 0 ) ;
if ( V_2 -> V_23 . V_24 )
F_31 ( V_2 , false ) ;
F_4 ( V_2 , & V_21 ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_27 ( V_2 -> V_38 , L_8 ) ;
}
F_9 ( V_75 ,
V_2 -> V_36 . V_76 >> 12 ) ;
F_9 ( V_77 ,
V_2 -> V_36 . V_78 >> 12 ) ;
F_9 ( V_79 ,
V_2 -> V_80 . V_81 >> 12 ) ;
V_29 = ( ( V_2 -> V_36 . V_78 >> 24 ) & 0xFFFF ) << 16 ;
V_29 |= ( ( V_2 -> V_36 . V_76 >> 24 ) & 0xFFFF ) ;
F_9 ( V_82 , V_29 ) ;
F_9 ( V_83 , ( V_2 -> V_36 . V_76 >> 8 ) ) ;
F_9 ( V_84 , ( 2 << 7 ) | ( 1 << 30 ) ) ;
F_9 ( V_85 , 0x3FFFFFFF ) ;
F_9 ( V_86 , 0 ) ;
F_9 ( V_87 , 0x0FFFFFFF ) ;
F_9 ( V_88 , 0x0FFFFFFF ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_27 ( V_2 -> V_38 , L_8 ) ;
}
F_12 ( V_2 , & V_21 ) ;
F_9 ( V_28 , V_89 | V_90 ) ;
V_29 = F_7 ( V_91 ) ;
V_29 = F_10 ( V_29 , V_92 , V_93 , 0 ) ;
F_9 ( V_91 , V_29 ) ;
V_29 = F_7 ( V_94 ) ;
F_9 ( V_94 , V_29 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
V_6 V_29 ;
int V_95 , V_96 ;
V_29 = F_7 ( V_97 ) ;
if ( F_8 ( V_29 , V_98 , V_99 ) ) {
V_95 = 64 ;
} else {
V_95 = 32 ;
}
V_29 = F_7 ( V_100 ) ;
switch ( F_8 ( V_29 , V_101 , V_102 ) ) {
case 0 :
default:
V_96 = 1 ;
break;
case 1 :
V_96 = 2 ;
break;
case 2 :
V_96 = 4 ;
break;
case 3 :
V_96 = 8 ;
break;
case 4 :
V_96 = 3 ;
break;
case 5 :
V_96 = 6 ;
break;
case 6 :
V_96 = 10 ;
break;
case 7 :
V_96 = 12 ;
break;
case 8 :
V_96 = 16 ;
break;
}
V_2 -> V_36 . V_103 = V_96 * V_95 ;
V_2 -> V_36 . V_104 = F_33 ( V_2 -> V_105 , 0 ) ;
V_2 -> V_36 . V_106 = F_34 ( V_2 -> V_105 , 0 ) ;
V_2 -> V_36 . V_70 = F_7 ( V_107 ) * 1024ULL * 1024ULL ;
V_2 -> V_36 . V_71 = F_7 ( V_107 ) * 1024ULL * 1024ULL ;
V_2 -> V_36 . V_108 = V_2 -> V_36 . V_106 ;
if ( V_2 -> V_36 . V_108 > V_2 -> V_36 . V_71 )
V_2 -> V_36 . V_108 = V_2 -> V_36 . V_71 ;
if ( V_109 == - 1 )
V_2 -> V_36 . V_110 = F_35 ( V_2 ) ;
else
V_2 -> V_36 . V_110 = ( V_111 ) V_109 << 20 ;
F_26 ( V_2 , & V_2 -> V_36 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 ,
T_2 V_112 )
{
F_9 ( V_113 , 0 ) ;
F_9 ( V_114 , 1 << V_112 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
void * V_115 ,
T_2 V_116 ,
V_111 V_117 ,
T_2 V_118 )
{
void T_3 * V_119 = ( void * ) V_115 ;
V_111 V_120 ;
V_120 = V_117 & 0x000000FFFFFFF000ULL ;
V_120 |= V_118 ;
F_38 ( V_120 , V_119 + ( V_116 * 8 ) ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
bool V_120 )
{
V_6 V_29 ;
V_29 = F_7 ( V_121 ) ;
V_29 = F_10 ( V_29 , V_122 ,
V_123 , V_120 ) ;
V_29 = F_10 ( V_29 , V_122 ,
V_124 , V_120 ) ;
V_29 = F_10 ( V_29 , V_122 ,
V_125 , V_120 ) ;
V_29 = F_10 ( V_29 , V_122 ,
V_126 , V_120 ) ;
V_29 = F_10 ( V_29 , V_122 ,
V_127 , V_120 ) ;
V_29 = F_10 ( V_29 , V_122 ,
V_128 , V_120 ) ;
V_29 = F_10 ( V_29 , V_122 ,
V_129 , V_120 ) ;
F_9 ( V_121 , V_29 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_130 , V_46 ;
V_6 V_29 ;
if ( V_2 -> V_131 . V_132 == NULL ) {
F_41 ( V_2 -> V_38 , L_9 ) ;
return - V_49 ;
}
V_130 = F_42 ( V_2 ) ;
if ( V_130 )
return V_130 ;
V_29 = F_7 ( V_133 ) ;
V_29 = F_10 ( V_29 , V_134 , V_135 , 1 ) ;
V_29 = F_10 ( V_29 , V_134 , V_136 , 1 ) ;
V_29 = F_10 ( V_29 , V_134 , V_137 , 3 ) ;
V_29 = F_10 ( V_29 , V_134 , V_138 , 1 ) ;
V_29 = F_10 ( V_29 , V_134 , V_139 , 0 ) ;
F_9 ( V_133 , V_29 ) ;
V_29 = F_7 ( V_140 ) ;
V_29 = F_10 ( V_29 , V_141 , V_142 , 1 ) ;
V_29 = F_10 ( V_29 , V_141 , V_143 , 1 ) ;
V_29 = F_10 ( V_29 , V_141 , V_144 , 1 ) ;
V_29 = F_10 ( V_29 , V_141 , V_145 , 1 ) ;
V_29 = F_10 ( V_29 , V_141 , V_146 , 7 ) ;
V_29 = F_10 ( V_29 , V_141 , V_147 , 1 ) ;
V_29 = F_10 ( V_29 , V_141 , V_148 , 1 ) ;
F_9 ( V_140 , V_29 ) ;
V_29 = F_7 ( V_149 ) ;
V_29 = F_10 ( V_29 , V_150 , V_151 , 1 ) ;
V_29 = F_10 ( V_29 , V_150 , V_152 , 1 ) ;
F_9 ( V_149 , V_29 ) ;
V_29 = F_7 ( V_153 ) ;
V_29 = F_10 ( V_29 , V_154 , V_155 , 1 ) ;
V_29 = F_10 ( V_29 , V_154 , V_156 , 4 ) ;
V_29 = F_10 ( V_29 , V_154 , V_157 , 4 ) ;
F_9 ( V_153 , V_29 ) ;
V_29 = F_7 ( V_158 ) ;
V_29 = F_10 ( V_29 , V_159 , V_160 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_161 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_162 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_163 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_164 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_165 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_166 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_167 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_168 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_169 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_170 , 0 ) ;
V_29 = F_10 ( V_29 , V_159 , V_171 , 0 ) ;
F_9 ( V_158 , V_29 ) ;
F_9 ( V_172 , V_2 -> V_36 . V_173 >> 12 ) ;
F_9 ( V_174 , V_2 -> V_36 . V_175 >> 12 ) ;
F_9 ( V_176 , V_2 -> V_131 . V_177 >> 12 ) ;
F_9 ( V_178 ,
( V_6 ) ( V_2 -> V_179 . V_117 >> 12 ) ) ;
F_9 ( V_180 , 0 ) ;
V_29 = F_7 ( V_181 ) ;
V_29 = F_10 ( V_29 , V_182 , V_183 , 1 ) ;
V_29 = F_10 ( V_29 , V_182 , V_184 , 0 ) ;
V_29 = F_10 ( V_29 , V_182 , V_123 , 1 ) ;
F_9 ( V_181 , V_29 ) ;
F_9 ( V_185 , 0 ) ;
F_9 ( V_186 , 0 ) ;
F_9 ( V_187 , 0 ) ;
F_9 ( V_188 , 0 ) ;
F_9 ( V_189 , V_2 -> V_190 . V_191 - 1 ) ;
for ( V_46 = 1 ; V_46 < 16 ; V_46 ++ ) {
if ( V_46 < 8 )
F_9 ( V_176 + V_46 ,
V_2 -> V_131 . V_177 >> 12 ) ;
else
F_9 ( V_192 + V_46 - 8 ,
V_2 -> V_131 . V_177 >> 12 ) ;
}
F_9 ( V_193 ,
( V_6 ) ( V_2 -> V_179 . V_117 >> 12 ) ) ;
F_9 ( V_194 , 4 ) ;
V_29 = F_7 ( V_121 ) ;
V_29 = F_10 ( V_29 , V_122 , V_183 , 1 ) ;
V_29 = F_10 ( V_29 , V_122 , V_184 , 1 ) ;
V_29 = F_10 ( V_29 , V_122 , V_123 , 1 ) ;
V_29 = F_10 ( V_29 , V_122 , V_124 , 1 ) ;
V_29 = F_10 ( V_29 , V_122 , V_125 , 1 ) ;
V_29 = F_10 ( V_29 , V_122 , V_126 , 1 ) ;
V_29 = F_10 ( V_29 , V_122 , V_127 , 1 ) ;
V_29 = F_10 ( V_29 , V_122 , V_128 , 1 ) ;
V_29 = F_10 ( V_29 , V_122 , V_129 , 1 ) ;
V_29 = F_10 ( V_29 , V_122 , V_195 ,
V_196 - 9 ) ;
F_9 ( V_121 , V_29 ) ;
if ( V_197 == V_198 )
F_39 ( V_2 , false ) ;
else
F_39 ( V_2 , true ) ;
F_36 ( V_2 , 0 ) ;
F_43 ( L_10 ,
( unsigned ) ( V_2 -> V_36 . V_110 >> 20 ) ,
( unsigned long long ) V_2 -> V_131 . V_177 ) ;
V_2 -> V_131 . V_199 = true ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_130 ;
if ( V_2 -> V_131 . V_132 ) {
F_45 ( 1 , L_11 ) ;
return 0 ;
}
V_130 = F_46 ( V_2 ) ;
if ( V_130 )
return V_130 ;
V_2 -> V_131 . V_200 = V_2 -> V_131 . V_201 * 8 ;
return F_47 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
V_6 V_29 ;
F_9 ( V_181 , 0 ) ;
F_9 ( V_121 , 0 ) ;
V_29 = F_7 ( V_133 ) ;
V_29 = F_10 ( V_29 , V_134 , V_135 , 0 ) ;
V_29 = F_10 ( V_29 , V_134 , V_136 , 0 ) ;
V_29 = F_10 ( V_29 , V_134 , V_138 , 0 ) ;
F_9 ( V_133 , V_29 ) ;
V_29 = F_7 ( V_140 ) ;
V_29 = F_10 ( V_29 , V_141 , V_142 , 0 ) ;
F_9 ( V_140 , V_29 ) ;
F_9 ( V_149 , 0 ) ;
F_49 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
V_2 -> V_190 . V_202 = V_203 ;
F_54 ( V_2 ) ;
if ( V_2 -> V_118 & V_204 ) {
T_4 V_29 = F_7 ( V_205 ) ;
V_29 <<= 22 ;
V_2 -> V_190 . V_206 = V_29 ;
} else
V_2 -> V_190 . V_206 = 0 ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
}
static void F_56 ( struct V_1 * V_2 ,
V_6 V_207 , V_6 V_117 , V_6 V_208 )
{
V_6 V_209 ;
V_6 V_112 = F_8 ( V_207 , V_210 , V_211 ) ;
V_6 V_212 = F_8 ( V_207 , V_210 ,
V_213 ) ;
char V_214 [ 5 ] = { V_208 >> 24 , ( V_208 >> 16 ) & 0xff ,
( V_208 >> 8 ) & 0xff , V_208 & 0xff , 0 } ;
V_209 = F_8 ( V_207 , V_210 ,
V_215 ) ;
F_19 ( L_12 ,
V_212 , V_112 , V_117 ,
F_8 ( V_207 , V_210 ,
V_216 ) ?
L_13 : L_14 , V_214 , V_208 , V_209 ) ;
}
static int F_57 ( int V_217 )
{
switch ( V_217 ) {
case V_218 :
return V_219 ;
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
default:
return V_232 ;
}
}
static int F_58 ( void * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_61 ( void * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
if ( V_197 != V_198 )
return F_62 ( V_2 , & V_2 -> V_36 . V_234 , 0 ) ;
else
return 0 ;
}
static int F_63 ( void * V_233 )
{
int V_130 ;
int V_235 ;
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
if ( V_2 -> V_118 & V_204 ) {
V_2 -> V_36 . V_236 = V_232 ;
} else {
V_6 V_29 ;
if ( V_2 -> V_3 == V_4 )
V_29 = F_7 ( V_237 ) ;
else
V_29 = F_7 ( V_238 ) ;
V_29 &= V_239 ;
V_2 -> V_36 . V_236 = F_57 ( V_29 ) ;
}
V_130 = F_64 ( V_2 , 146 , & V_2 -> V_36 . V_234 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_64 ( V_2 , 147 , & V_2 -> V_36 . V_234 ) ;
if ( V_130 )
return V_130 ;
V_2 -> V_190 . V_191 = V_240 << 18 ;
V_2 -> V_36 . V_241 = 0xffffffffffULL ;
V_2 -> V_242 = false ;
V_235 = V_2 -> V_242 ? 32 : 40 ;
V_130 = F_65 ( V_2 -> V_105 , F_66 ( V_235 ) ) ;
if ( V_130 ) {
V_2 -> V_242 = true ;
V_235 = 32 ;
F_19 ( V_243 L_15 ) ;
}
V_130 = F_67 ( V_2 -> V_105 , F_66 ( V_235 ) ) ;
if ( V_130 ) {
F_67 ( V_2 -> V_105 , F_66 ( 32 ) ) ;
F_19 ( V_243 L_16 ) ;
}
V_130 = F_14 ( V_2 ) ;
if ( V_130 ) {
F_68 ( L_17 ) ;
return V_130 ;
}
V_130 = F_69 ( V_2 ) ;
if ( V_130 ) {
return V_130 ;
}
V_130 = F_32 ( V_2 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_70 ( V_2 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_44 ( V_2 ) ;
if ( V_130 )
return V_130 ;
if ( ! V_2 -> V_190 . V_244 ) {
V_130 = F_53 ( V_2 ) ;
if ( V_130 ) {
F_41 ( V_2 -> V_38 , L_18 , V_130 ) ;
return V_130 ;
}
V_2 -> V_190 . V_244 = true ;
}
return V_130 ;
}
static int F_71 ( void * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
if ( V_2 -> V_190 . V_244 ) {
F_72 ( V_2 ) ;
F_55 ( V_2 ) ;
V_2 -> V_190 . V_244 = false ;
}
F_50 ( V_2 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
static int F_75 ( void * V_233 )
{
int V_130 ;
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
F_1 ( V_2 ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_3 == V_8 ) {
V_130 = F_21 ( V_2 ) ;
if ( V_130 ) {
F_68 ( L_19 ) ;
return V_130 ;
}
}
V_130 = F_40 ( V_2 ) ;
if ( V_130 )
return V_130 ;
return V_130 ;
}
static int F_76 ( void * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
F_77 ( V_2 , & V_2 -> V_36 . V_234 , 0 ) ;
F_48 ( V_2 ) ;
return 0 ;
}
static int F_78 ( void * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
if ( V_2 -> V_190 . V_244 ) {
F_55 ( V_2 ) ;
V_2 -> V_190 . V_244 = false ;
}
F_76 ( V_2 ) ;
return 0 ;
}
static int F_79 ( void * V_233 )
{
int V_130 ;
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
V_130 = F_75 ( V_2 ) ;
if ( V_130 )
return V_130 ;
if ( ! V_2 -> V_190 . V_244 ) {
V_130 = F_53 ( V_2 ) ;
if ( V_130 ) {
F_41 ( V_2 -> V_38 , L_18 , V_130 ) ;
return V_130 ;
}
V_2 -> V_190 . V_244 = true ;
}
return V_130 ;
}
static bool F_80 ( void * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
V_6 V_29 = F_7 ( V_245 ) ;
if ( V_29 & ( V_246 | V_247 |
V_248 | V_249 | V_250 ) )
return false ;
return true ;
}
static int F_6 ( void * V_233 )
{
unsigned V_46 ;
V_6 V_29 ;
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_64 ; V_46 ++ ) {
V_29 = F_7 ( V_245 ) & ( V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_251 ) ;
if ( ! V_29 )
return 0 ;
F_11 ( 1 ) ;
}
return - V_252 ;
}
static bool F_81 ( void * V_233 )
{
V_6 V_253 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
V_6 V_29 = F_7 ( V_245 ) ;
if ( V_29 & V_250 )
V_253 = F_10 ( V_253 ,
V_254 , V_255 , 1 ) ;
if ( V_29 & ( V_246 | V_247 |
V_248 | V_249 ) ) {
if ( ! ( V_2 -> V_118 & V_204 ) )
V_253 = F_10 ( V_253 ,
V_254 , V_256 , 1 ) ;
}
if ( V_253 ) {
V_2 -> V_36 . V_253 = V_253 ;
return true ;
} else {
V_2 -> V_36 . V_253 = 0 ;
return false ;
}
}
static int F_82 ( void * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
if ( ! V_2 -> V_36 . V_253 )
return 0 ;
F_4 ( V_2 , & V_2 -> V_36 . V_21 ) ;
if ( F_6 ( V_2 ) ) {
F_27 ( V_2 -> V_38 , L_20 ) ;
}
return 0 ;
}
static int F_83 ( void * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
V_6 V_253 ;
if ( ! V_2 -> V_36 . V_253 )
return 0 ;
V_253 = V_2 -> V_36 . V_253 ;
if ( V_253 ) {
V_6 V_29 ;
V_29 = F_7 ( V_257 ) ;
V_29 |= V_253 ;
F_84 ( V_2 -> V_38 , L_21 , V_29 ) ;
F_9 ( V_257 , V_29 ) ;
V_29 = F_7 ( V_257 ) ;
F_11 ( 50 ) ;
V_29 &= ~ V_253 ;
F_9 ( V_257 , V_29 ) ;
V_29 = F_7 ( V_257 ) ;
F_11 ( 50 ) ;
}
return 0 ;
}
static int F_85 ( void * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
if ( ! V_2 -> V_36 . V_253 )
return 0 ;
F_12 ( V_2 , & V_2 -> V_36 . V_21 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_258 * V_259 ,
unsigned type ,
enum V_260 V_261 )
{
V_6 V_29 ;
V_6 V_262 = ( V_263 |
V_264 |
V_265 |
V_266 |
V_267 |
V_268 |
V_269 ) ;
switch ( V_261 ) {
case V_270 :
V_29 = F_7 ( V_181 ) ;
V_29 &= ~ V_262 ;
F_9 ( V_181 , V_29 ) ;
V_29 = F_7 ( V_121 ) ;
V_29 &= ~ V_262 ;
F_9 ( V_121 , V_29 ) ;
break;
case V_271 :
V_29 = F_7 ( V_181 ) ;
V_29 |= V_262 ;
F_9 ( V_181 , V_29 ) ;
V_29 = F_7 ( V_121 ) ;
V_29 |= V_262 ;
F_9 ( V_121 , V_29 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_258 * V_272 ,
struct V_273 * V_274 )
{
V_6 V_117 , V_207 , V_208 ;
V_117 = F_7 ( V_275 ) ;
V_207 = F_7 ( V_276 ) ;
V_208 = F_7 ( V_277 ) ;
F_88 ( V_194 , 1 , ~ 1 ) ;
if ( ! V_117 && ! V_207 )
return 0 ;
if ( V_197 == V_278 )
F_39 ( V_2 , false ) ;
F_41 ( V_2 -> V_38 , L_22 ,
V_274 -> V_279 , V_274 -> V_280 ) ;
F_41 ( V_2 -> V_38 , L_23 ,
V_117 ) ;
F_41 ( V_2 -> V_38 , L_24 ,
V_207 ) ;
F_56 ( V_2 , V_207 , V_117 , V_208 ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 ,
bool V_281 )
{
T_2 V_50 ;
if ( V_281 && ( V_2 -> V_282 & V_283 ) ) {
V_50 = F_7 ( V_284 ) ;
V_50 |= V_285 ;
F_9 ( V_284 , V_50 ) ;
V_50 = F_7 ( V_286 ) ;
V_50 |= V_287 ;
F_9 ( V_286 , V_50 ) ;
V_50 = F_7 ( V_288 ) ;
V_50 |= V_289 ;
F_9 ( V_288 , V_50 ) ;
V_50 = F_7 ( V_290 ) ;
V_50 |= V_291 ;
F_9 ( V_290 , V_50 ) ;
V_50 = F_7 ( V_292 ) ;
V_50 |= V_293 ;
F_9 ( V_292 , V_50 ) ;
V_50 = F_7 ( V_294 ) ;
V_50 |= V_295 ;
F_9 ( V_294 , V_50 ) ;
V_50 = F_7 ( V_296 ) ;
V_50 |= V_297 ;
F_9 ( V_296 , V_50 ) ;
V_50 = F_7 ( V_298 ) ;
V_50 |= V_299 ;
F_9 ( V_298 , V_50 ) ;
V_50 = F_7 ( V_300 ) ;
V_50 |= V_301 ;
F_9 ( V_300 , V_50 ) ;
} else {
V_50 = F_7 ( V_284 ) ;
V_50 &= ~ V_285 ;
F_9 ( V_284 , V_50 ) ;
V_50 = F_7 ( V_286 ) ;
V_50 &= ~ V_287 ;
F_9 ( V_286 , V_50 ) ;
V_50 = F_7 ( V_288 ) ;
V_50 &= ~ V_289 ;
F_9 ( V_288 , V_50 ) ;
V_50 = F_7 ( V_290 ) ;
V_50 &= ~ V_291 ;
F_9 ( V_290 , V_50 ) ;
V_50 = F_7 ( V_292 ) ;
V_50 &= ~ V_293 ;
F_9 ( V_292 , V_50 ) ;
V_50 = F_7 ( V_294 ) ;
V_50 &= ~ V_295 ;
F_9 ( V_294 , V_50 ) ;
V_50 = F_7 ( V_296 ) ;
V_50 &= ~ V_297 ;
F_9 ( V_296 , V_50 ) ;
V_50 = F_7 ( V_298 ) ;
V_50 &= ~ V_299 ;
F_9 ( V_298 , V_50 ) ;
V_50 = F_7 ( V_300 ) ;
V_50 &= ~ V_301 ;
F_9 ( V_300 , V_50 ) ;
}
}
static void F_90 ( struct V_1 * V_2 ,
bool V_281 )
{
T_2 V_50 ;
if ( V_281 && ( V_2 -> V_282 & V_302 ) ) {
V_50 = F_7 ( V_284 ) ;
V_50 |= V_303 ;
F_9 ( V_284 , V_50 ) ;
V_50 = F_7 ( V_286 ) ;
V_50 |= V_304 ;
F_9 ( V_286 , V_50 ) ;
V_50 = F_7 ( V_288 ) ;
V_50 |= V_305 ;
F_9 ( V_288 , V_50 ) ;
V_50 = F_7 ( V_290 ) ;
V_50 |= V_306 ;
F_9 ( V_290 , V_50 ) ;
V_50 = F_7 ( V_292 ) ;
V_50 |= V_307 ;
F_9 ( V_292 , V_50 ) ;
V_50 = F_7 ( V_294 ) ;
V_50 |= V_308 ;
F_9 ( V_294 , V_50 ) ;
V_50 = F_7 ( V_296 ) ;
V_50 |= V_309 ;
F_9 ( V_296 , V_50 ) ;
V_50 = F_7 ( V_298 ) ;
V_50 |= V_310 ;
F_9 ( V_298 , V_50 ) ;
V_50 = F_7 ( V_300 ) ;
V_50 |= V_311 ;
F_9 ( V_300 , V_50 ) ;
} else {
V_50 = F_7 ( V_284 ) ;
V_50 &= ~ V_303 ;
F_9 ( V_284 , V_50 ) ;
V_50 = F_7 ( V_286 ) ;
V_50 &= ~ V_304 ;
F_9 ( V_286 , V_50 ) ;
V_50 = F_7 ( V_288 ) ;
V_50 &= ~ V_305 ;
F_9 ( V_288 , V_50 ) ;
V_50 = F_7 ( V_290 ) ;
V_50 &= ~ V_306 ;
F_9 ( V_290 , V_50 ) ;
V_50 = F_7 ( V_292 ) ;
V_50 &= ~ V_307 ;
F_9 ( V_292 , V_50 ) ;
V_50 = F_7 ( V_294 ) ;
V_50 &= ~ V_308 ;
F_9 ( V_294 , V_50 ) ;
V_50 = F_7 ( V_296 ) ;
V_50 &= ~ V_309 ;
F_9 ( V_296 , V_50 ) ;
V_50 = F_7 ( V_298 ) ;
V_50 &= ~ V_310 ;
F_9 ( V_298 , V_50 ) ;
V_50 = F_7 ( V_300 ) ;
V_50 &= ~ V_311 ;
F_9 ( V_300 , V_50 ) ;
}
}
static int F_91 ( void * V_233 ,
enum V_312 V_261 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
switch ( V_2 -> V_3 ) {
case V_4 :
F_89 ( V_2 ,
V_261 == V_313 ? true : false ) ;
F_90 ( V_2 ,
V_261 == V_313 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_92 ( void * V_233 ,
enum V_314 V_261 )
{
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_131 . V_315 == NULL )
V_2 -> V_131 . V_315 = & V_316 ;
}
static void F_60 ( struct V_1 * V_2 )
{
V_2 -> V_36 . V_234 . V_317 = 1 ;
V_2 -> V_36 . V_234 . V_318 = & V_319 ;
}
