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
default:
break;
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
V_6 V_10 ;
if ( V_2 -> V_11 . V_12 )
F_5 ( V_2 , V_9 ) ;
F_6 ( ( void * ) V_2 ) ;
V_10 = F_7 ( V_13 ) ;
if ( F_8 ( V_10 , V_14 , V_15 ) != 1 ) {
F_9 ( V_16 , 0 ) ;
V_10 = F_10 ( V_10 ,
V_14 , V_15 , 0 ) ;
F_9 ( V_13 , V_10 | 1 ) ;
}
F_11 ( 100 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
V_6 V_17 ;
V_17 = F_7 ( V_13 ) ;
V_17 = F_10 ( V_17 , V_14 , V_15 , 0 ) ;
F_9 ( V_13 , V_17 ) ;
V_17 = F_10 ( 0 , V_18 , V_19 , 1 ) ;
V_17 = F_10 ( V_17 , V_18 , V_20 , 1 ) ;
F_9 ( V_16 , V_17 ) ;
if ( V_2 -> V_11 . V_12 )
F_13 ( V_2 , V_9 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
const char * V_21 ;
char V_22 [ 30 ] ;
int V_23 ;
F_15 ( L_1 ) ;
switch ( V_2 -> V_3 ) {
case V_24 :
V_21 = L_2 ;
break;
case V_25 :
V_21 = L_3 ;
break;
case V_4 :
V_21 = L_4 ;
break;
case V_26 :
case V_27 :
case V_28 :
return 0 ;
default: F_16 () ;
}
if ( V_2 -> V_3 == V_4 )
snprintf ( V_22 , sizeof( V_22 ) , L_5 , V_21 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_6 , V_21 ) ;
V_23 = F_17 ( & V_2 -> V_29 . V_30 , V_22 , V_2 -> V_31 ) ;
if ( V_23 )
goto V_32;
V_23 = F_18 ( V_2 -> V_29 . V_30 ) ;
V_32:
if ( V_23 ) {
F_19 ( V_33
L_7 ,
V_22 ) ;
F_20 ( V_2 -> V_29 . V_30 ) ;
V_2 -> V_29 . V_30 = NULL ;
}
return V_23 ;
}
static int F_21 ( struct V_1 * V_2 )
{
const struct V_34 * V_35 ;
const T_1 * V_36 = NULL ;
const T_1 * V_37 = NULL ;
V_6 V_38 ;
int V_39 , V_40 , V_41 ;
if ( ! V_2 -> V_29 . V_30 )
return - V_42 ;
V_35 = ( const struct V_34 * ) V_2 -> V_29 . V_30 -> V_43 ;
F_22 ( & V_35 -> V_44 ) ;
V_2 -> V_29 . V_45 = F_23 ( V_35 -> V_44 . V_46 ) ;
V_41 = F_23 ( V_35 -> V_47 ) / ( 4 * 2 ) ;
V_37 = ( const T_1 * )
( V_2 -> V_29 . V_30 -> V_43 + F_23 ( V_35 -> V_48 ) ) ;
V_40 = F_23 ( V_35 -> V_44 . V_49 ) / 4 ;
V_36 = ( const T_1 * )
( V_2 -> V_29 . V_30 -> V_43 + F_23 ( V_35 -> V_44 . V_50 ) ) ;
V_38 = F_8 ( F_7 ( V_51 ) , V_52 , V_53 ) ;
if ( V_38 == 0 ) {
F_9 ( V_51 , 0x00000008 ) ;
F_9 ( V_51 , 0x00000010 ) ;
for ( V_39 = 0 ; V_39 < V_41 ; V_39 ++ ) {
F_9 ( V_54 , F_24 ( V_37 ++ ) ) ;
F_9 ( V_55 , F_24 ( V_37 ++ ) ) ;
}
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_9 ( V_56 , F_24 ( V_36 ++ ) ) ;
F_9 ( V_51 , 0x00000008 ) ;
F_9 ( V_51 , 0x00000004 ) ;
F_9 ( V_51 , 0x00000001 ) ;
for ( V_39 = 0 ; V_39 < V_2 -> V_57 ; V_39 ++ ) {
if ( F_8 ( F_7 ( V_58 ) ,
V_59 , V_60 ) )
break;
F_11 ( 1 ) ;
}
for ( V_39 = 0 ; V_39 < V_2 -> V_57 ; V_39 ++ ) {
if ( F_8 ( F_7 ( V_58 ) ,
V_59 , V_61 ) )
break;
F_11 ( 1 ) ;
}
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_62 * V_29 )
{
if ( V_29 -> V_63 > 0xFFC0000000ULL ) {
F_26 ( V_2 -> V_31 , L_8 ) ;
V_29 -> V_64 = 0xFFC0000000ULL ;
V_29 -> V_63 = 0xFFC0000000ULL ;
}
F_27 ( V_2 , & V_2 -> V_29 , 0 ) ;
V_2 -> V_29 . V_65 = 0 ;
F_28 ( V_2 , V_29 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_8 V_9 ;
V_6 V_17 ;
int V_39 , V_66 ;
for ( V_39 = 0 , V_66 = 0 ; V_39 < 32 ; V_39 ++ , V_66 += 0x6 ) {
F_9 ( ( 0xb05 + V_66 ) , 0x00000000 ) ;
F_9 ( ( 0xb06 + V_66 ) , 0x00000000 ) ;
F_9 ( ( 0xb07 + V_66 ) , 0x00000000 ) ;
F_9 ( ( 0xb08 + V_66 ) , 0x00000000 ) ;
F_9 ( ( 0xb09 + V_66 ) , 0x00000000 ) ;
}
F_9 ( V_67 , 0 ) ;
if ( V_2 -> V_11 . V_12 )
F_30 ( V_2 , false ) ;
F_4 ( V_2 , & V_9 ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_26 ( V_2 -> V_31 , L_9 ) ;
}
F_9 ( V_68 ,
V_2 -> V_29 . V_69 >> 12 ) ;
F_9 ( V_70 ,
V_2 -> V_29 . V_71 >> 12 ) ;
F_9 ( V_72 ,
V_2 -> V_73 . V_74 >> 12 ) ;
V_17 = ( ( V_2 -> V_29 . V_71 >> 24 ) & 0xFFFF ) << 16 ;
V_17 |= ( ( V_2 -> V_29 . V_69 >> 24 ) & 0xFFFF ) ;
F_9 ( V_75 , V_17 ) ;
F_9 ( V_76 , ( V_2 -> V_29 . V_69 >> 8 ) ) ;
F_9 ( V_77 , ( 2 << 7 ) | ( 1 << 30 ) ) ;
F_9 ( V_78 , 0x3FFFFFFF ) ;
F_9 ( V_79 , 0 ) ;
F_9 ( V_80 , 0x0FFFFFFF ) ;
F_9 ( V_81 , 0x0FFFFFFF ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_26 ( V_2 -> V_31 , L_9 ) ;
}
F_12 ( V_2 , & V_9 ) ;
F_9 ( V_16 , V_82 | V_83 ) ;
V_17 = F_7 ( V_84 ) ;
V_17 = F_10 ( V_17 , V_85 , V_86 , 0 ) ;
F_9 ( V_84 , V_17 ) ;
V_17 = F_7 ( V_87 ) ;
F_9 ( V_87 , V_17 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
V_6 V_17 ;
int V_88 , V_89 ;
V_17 = F_7 ( V_90 ) ;
if ( F_8 ( V_17 , V_91 , V_92 ) ) {
V_88 = 64 ;
} else {
V_88 = 32 ;
}
V_17 = F_7 ( V_93 ) ;
switch ( F_8 ( V_17 , V_94 , V_95 ) ) {
case 0 :
default:
V_89 = 1 ;
break;
case 1 :
V_89 = 2 ;
break;
case 2 :
V_89 = 4 ;
break;
case 3 :
V_89 = 8 ;
break;
case 4 :
V_89 = 3 ;
break;
case 5 :
V_89 = 6 ;
break;
case 6 :
V_89 = 10 ;
break;
case 7 :
V_89 = 12 ;
break;
case 8 :
V_89 = 16 ;
break;
}
V_2 -> V_29 . V_96 = V_89 * V_88 ;
V_2 -> V_29 . V_97 = F_32 ( V_2 -> V_98 , 0 ) ;
V_2 -> V_29 . V_99 = F_33 ( V_2 -> V_98 , 0 ) ;
V_2 -> V_29 . V_63 = F_7 ( V_100 ) * 1024ULL * 1024ULL ;
V_2 -> V_29 . V_64 = F_7 ( V_100 ) * 1024ULL * 1024ULL ;
V_2 -> V_29 . V_101 = V_2 -> V_29 . V_99 ;
if ( V_2 -> V_29 . V_101 > V_2 -> V_29 . V_64 )
V_2 -> V_29 . V_101 = V_2 -> V_29 . V_64 ;
if ( V_102 == - 1 )
V_2 -> V_29 . V_103 = F_34 ( V_2 ) ;
else
V_2 -> V_29 . V_103 = ( V_104 ) V_102 << 20 ;
F_25 ( V_2 , & V_2 -> V_29 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
T_2 V_105 )
{
F_9 ( V_106 , 0 ) ;
F_9 ( V_107 , 1 << V_105 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
void * V_108 ,
T_2 V_109 ,
V_104 V_110 ,
T_2 V_111 )
{
void T_3 * V_112 = ( void * ) V_108 ;
V_104 V_113 ;
V_113 = V_110 & 0xFFFFFFFFFFFFF000ULL ;
V_113 |= V_111 ;
F_37 ( V_113 , V_112 + ( V_109 * 8 ) ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
bool V_113 )
{
V_6 V_17 ;
V_17 = F_7 ( V_114 ) ;
V_17 = F_10 ( V_17 , V_115 ,
V_116 , V_113 ) ;
V_17 = F_10 ( V_17 , V_115 ,
V_117 , V_113 ) ;
V_17 = F_10 ( V_17 , V_115 ,
V_118 , V_113 ) ;
V_17 = F_10 ( V_17 , V_115 ,
V_119 , V_113 ) ;
V_17 = F_10 ( V_17 , V_115 ,
V_120 , V_113 ) ;
V_17 = F_10 ( V_17 , V_115 ,
V_121 , V_113 ) ;
F_9 ( V_114 , V_17 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_122 , V_39 ;
V_6 V_17 ;
if ( V_2 -> V_123 . V_124 == NULL ) {
F_40 ( V_2 -> V_31 , L_10 ) ;
return - V_42 ;
}
V_122 = F_41 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_17 = F_7 ( V_125 ) ;
V_17 = F_10 ( V_17 , V_126 , V_127 , 1 ) ;
V_17 = F_10 ( V_17 , V_126 , V_128 , 1 ) ;
V_17 = F_10 ( V_17 , V_126 , V_129 , 3 ) ;
V_17 = F_10 ( V_17 , V_126 , V_130 , 1 ) ;
V_17 = F_10 ( V_17 , V_126 , V_131 , 0 ) ;
F_9 ( V_125 , V_17 ) ;
V_17 = F_7 ( V_132 ) ;
V_17 = F_10 ( V_17 , V_133 , V_134 , 1 ) ;
V_17 = F_10 ( V_17 , V_133 , V_135 , 1 ) ;
V_17 = F_10 ( V_17 , V_133 , V_136 , 1 ) ;
V_17 = F_10 ( V_17 , V_133 , V_137 , 1 ) ;
V_17 = F_10 ( V_17 , V_133 , V_138 , 7 ) ;
V_17 = F_10 ( V_17 , V_133 , V_139 , 1 ) ;
V_17 = F_10 ( V_17 , V_133 , V_140 , 1 ) ;
F_9 ( V_132 , V_17 ) ;
V_17 = F_10 ( 0 , V_141 , V_142 , 1 ) ;
V_17 = F_10 ( V_17 , V_141 , V_143 , 1 ) ;
F_9 ( V_144 , V_17 ) ;
V_17 = F_7 ( V_145 ) ;
V_17 = F_10 ( V_17 , V_146 , V_147 , 1 ) ;
V_17 = F_10 ( V_17 , V_146 , V_148 , 4 ) ;
V_17 = F_10 ( V_17 , V_146 , V_149 , 4 ) ;
F_9 ( V_145 , V_17 ) ;
F_9 ( V_150 , V_2 -> V_29 . V_151 >> 12 ) ;
F_9 ( V_152 , V_2 -> V_29 . V_153 >> 12 ) ;
F_9 ( V_154 , V_2 -> V_123 . V_155 >> 12 ) ;
F_9 ( V_156 ,
( V_6 ) ( V_2 -> V_157 . V_110 >> 12 ) ) ;
F_9 ( V_158 , 0 ) ;
V_17 = F_7 ( V_159 ) ;
V_17 = F_10 ( V_17 , V_160 , V_161 , 1 ) ;
V_17 = F_10 ( V_17 , V_160 , V_162 , 0 ) ;
V_17 = F_10 ( V_17 , V_160 , V_116 , 1 ) ;
F_9 ( V_159 , V_17 ) ;
F_9 ( 0x575 , 0 ) ;
F_9 ( 0x576 , 0 ) ;
F_9 ( 0x577 , 0 ) ;
F_9 ( V_163 , 0 ) ;
F_9 ( V_164 , V_2 -> V_165 . V_166 - 1 ) ;
for ( V_39 = 1 ; V_39 < 16 ; V_39 ++ ) {
if ( V_39 < 8 )
F_9 ( V_154 + V_39 ,
V_2 -> V_123 . V_155 >> 12 ) ;
else
F_9 ( V_167 + V_39 - 8 ,
V_2 -> V_123 . V_155 >> 12 ) ;
}
F_9 ( V_168 ,
( V_6 ) ( V_2 -> V_157 . V_110 >> 12 ) ) ;
F_9 ( V_169 , 4 ) ;
V_17 = F_7 ( V_114 ) ;
V_17 = F_10 ( V_17 , V_115 , V_161 , 1 ) ;
V_17 = F_10 ( V_17 , V_115 , V_162 , 1 ) ;
V_17 = F_10 ( V_17 , V_115 , V_170 ,
V_171 - 9 ) ;
F_9 ( V_114 , V_17 ) ;
if ( V_172 == V_173 )
F_38 ( V_2 , false ) ;
else
F_38 ( V_2 , true ) ;
if ( V_2 -> V_3 == V_26 ) {
V_17 = F_7 ( V_174 ) ;
V_17 &= ~ V_175 ;
F_9 ( V_174 , V_17 ) ;
}
F_35 ( V_2 , 0 ) ;
F_42 ( L_11 ,
( unsigned ) ( V_2 -> V_29 . V_103 >> 20 ) ,
( unsigned long long ) V_2 -> V_123 . V_155 ) ;
V_2 -> V_123 . V_176 = true ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_122 ;
if ( V_2 -> V_123 . V_124 ) {
F_44 ( 1 , L_12 ) ;
return 0 ;
}
V_122 = F_45 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_2 -> V_123 . V_177 = V_2 -> V_123 . V_178 * 8 ;
return F_46 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
V_6 V_17 ;
F_9 ( V_159 , 0 ) ;
F_9 ( V_114 , 0 ) ;
V_17 = F_7 ( V_125 ) ;
V_17 = F_10 ( V_17 , V_126 , V_127 , 0 ) ;
V_17 = F_10 ( V_17 , V_126 , V_128 , 0 ) ;
V_17 = F_10 ( V_17 , V_126 , V_130 , 0 ) ;
F_9 ( V_125 , V_17 ) ;
V_17 = F_7 ( V_132 ) ;
V_17 = F_10 ( V_17 , V_133 , V_134 , 0 ) ;
F_9 ( V_132 , V_17 ) ;
F_9 ( V_144 , 0 ) ;
F_48 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
V_2 -> V_165 . V_179 = V_180 ;
F_53 ( V_2 ) ;
if ( V_2 -> V_111 & V_181 ) {
T_4 V_17 = F_7 ( V_182 ) ;
V_17 <<= 22 ;
V_2 -> V_165 . V_183 = V_17 ;
} else
V_2 -> V_165 . V_183 = 0 ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
}
static void F_55 ( struct V_1 * V_2 ,
V_6 V_184 , V_6 V_110 , V_6 V_185 )
{
V_6 V_186 ;
V_6 V_105 = F_8 ( V_184 , V_187 , V_188 ) ;
V_6 V_189 = F_8 ( V_184 , V_187 ,
V_190 ) ;
char V_191 [ 5 ] = { V_185 >> 24 , ( V_185 >> 16 ) & 0xff ,
( V_185 >> 8 ) & 0xff , V_185 & 0xff , 0 } ;
V_186 = F_8 ( V_184 , V_187 ,
V_192 ) ;
F_19 ( L_13 ,
V_189 , V_105 , V_110 ,
F_8 ( V_184 , V_187 ,
V_193 ) ?
L_14 : L_15 , V_191 , V_185 , V_186 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
bool V_194 )
{
int V_39 ;
V_6 V_195 , V_43 ;
for ( V_39 = 0 ; V_39 < F_3 ( V_196 ) ; V_39 ++ ) {
V_195 = V_43 = F_7 ( V_196 [ V_39 ] ) ;
if ( V_194 && ( V_2 -> V_197 & V_198 ) )
V_43 |= V_199 [ V_39 ] ;
else
V_43 &= ~ V_199 [ V_39 ] ;
if ( V_43 != V_195 )
F_9 ( V_196 [ V_39 ] , V_43 ) ;
}
}
static void F_57 ( struct V_1 * V_2 ,
bool V_194 )
{
int V_39 ;
V_6 V_195 , V_43 ;
for ( V_39 = 0 ; V_39 < F_3 ( V_196 ) ; V_39 ++ ) {
V_195 = V_43 = F_7 ( V_196 [ V_39 ] ) ;
if ( V_194 && ( V_2 -> V_197 & V_200 ) )
V_43 |= V_201 [ V_39 ] ;
else
V_43 &= ~ V_201 [ V_39 ] ;
if ( V_43 != V_195 )
F_9 ( V_196 [ V_39 ] , V_43 ) ;
}
}
static void F_58 ( struct V_1 * V_2 ,
bool V_194 )
{
V_6 V_195 , V_43 ;
V_195 = V_43 = F_59 ( V_202 ) ;
if ( V_194 && ( V_2 -> V_197 & V_203 ) ) {
V_43 = F_10 ( V_43 , V_204 , V_205 , 1 ) ;
V_43 = F_10 ( V_43 , V_204 , V_206 , 1 ) ;
V_43 = F_10 ( V_43 , V_204 , V_207 , 1 ) ;
V_43 = F_10 ( V_43 , V_204 , V_208 , 1 ) ;
} else {
V_43 = F_10 ( V_43 , V_204 , V_205 , 0 ) ;
V_43 = F_10 ( V_43 , V_204 , V_206 , 0 ) ;
V_43 = F_10 ( V_43 , V_204 , V_207 , 0 ) ;
V_43 = F_10 ( V_43 , V_204 , V_208 , 0 ) ;
}
if ( V_195 != V_43 )
F_60 ( V_202 , V_43 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
bool V_194 )
{
V_6 V_195 , V_43 ;
V_195 = V_43 = F_7 ( V_87 ) ;
if ( V_194 && ( V_2 -> V_197 & V_209 ) )
V_43 = F_10 ( V_43 , V_210 , V_211 , 0 ) ;
else
V_43 = F_10 ( V_43 , V_210 , V_211 , 1 ) ;
if ( V_195 != V_43 )
F_9 ( V_87 , V_43 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
bool V_194 )
{
V_6 V_195 , V_43 ;
V_195 = V_43 = F_7 ( V_212 ) ;
if ( V_194 && ( V_2 -> V_197 & V_213 ) )
V_43 = F_10 ( V_43 , V_214 , V_215 , 1 ) ;
else
V_43 = F_10 ( V_43 , V_214 , V_215 , 0 ) ;
if ( V_195 != V_43 )
F_9 ( V_212 , V_43 ) ;
}
static int F_63 ( int V_216 )
{
switch ( V_216 ) {
case V_217 :
return V_218 ;
case V_219 :
return V_220 ;
case V_221 :
return V_222 ;
case V_223 :
return V_224 ;
case V_225 :
return V_226 ;
case V_227 :
return V_228 ;
case V_229 :
return V_230 ;
default:
return V_231 ;
}
}
static int F_64 ( void * V_232 )
{
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
static int F_67 ( void * V_232 )
{
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
if ( V_172 != V_173 )
return F_68 ( V_2 , & V_2 -> V_29 . V_233 , 0 ) ;
else
return 0 ;
}
static int F_69 ( void * V_232 )
{
int V_122 ;
int V_234 ;
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
if ( V_2 -> V_111 & V_181 ) {
V_2 -> V_29 . V_235 = V_231 ;
} else {
V_6 V_17 = F_7 ( V_236 ) ;
V_17 &= V_237 ;
V_2 -> V_29 . V_235 = F_63 ( V_17 ) ;
}
V_122 = F_70 ( V_2 , 146 , & V_2 -> V_29 . V_233 ) ;
if ( V_122 )
return V_122 ;
V_122 = F_70 ( V_2 , 147 , & V_2 -> V_29 . V_233 ) ;
if ( V_122 )
return V_122 ;
V_2 -> V_165 . V_166 = V_238 << 18 ;
V_2 -> V_29 . V_239 = 0xffffffffffULL ;
V_2 -> V_240 = false ;
V_234 = V_2 -> V_240 ? 32 : 40 ;
V_122 = F_71 ( V_2 -> V_98 , F_72 ( V_234 ) ) ;
if ( V_122 ) {
V_2 -> V_240 = true ;
V_234 = 32 ;
F_19 ( V_241 L_16 ) ;
}
V_122 = F_73 ( V_2 -> V_98 , F_72 ( V_234 ) ) ;
if ( V_122 ) {
F_73 ( V_2 -> V_98 , F_72 ( 32 ) ) ;
F_19 ( V_241 L_17 ) ;
}
V_122 = F_14 ( V_2 ) ;
if ( V_122 ) {
F_74 ( L_18 ) ;
return V_122 ;
}
V_122 = F_75 ( V_2 ) ;
if ( V_122 ) {
return V_122 ;
}
V_122 = F_31 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_122 = F_76 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_122 = F_43 ( V_2 ) ;
if ( V_122 )
return V_122 ;
if ( ! V_2 -> V_165 . V_242 ) {
V_122 = F_52 ( V_2 ) ;
if ( V_122 ) {
F_40 ( V_2 -> V_31 , L_19 , V_122 ) ;
return V_122 ;
}
V_2 -> V_165 . V_242 = true ;
}
return V_122 ;
}
static int F_77 ( void * V_232 )
{
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
if ( V_2 -> V_165 . V_242 ) {
F_78 ( V_2 ) ;
F_54 ( V_2 ) ;
V_2 -> V_165 . V_242 = false ;
}
F_49 ( V_2 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static int F_81 ( void * V_232 )
{
int V_122 ;
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
F_1 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( ! ( V_2 -> V_111 & V_181 ) ) {
V_122 = F_21 ( V_2 ) ;
if ( V_122 ) {
F_74 ( L_20 ) ;
return V_122 ;
}
}
V_122 = F_39 ( V_2 ) ;
if ( V_122 )
return V_122 ;
return V_122 ;
}
static int F_82 ( void * V_232 )
{
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
F_83 ( V_2 , & V_2 -> V_29 . V_233 , 0 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_84 ( void * V_232 )
{
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
if ( V_2 -> V_165 . V_242 ) {
F_54 ( V_2 ) ;
V_2 -> V_165 . V_242 = false ;
}
F_82 ( V_2 ) ;
return 0 ;
}
static int F_85 ( void * V_232 )
{
int V_122 ;
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
V_122 = F_81 ( V_2 ) ;
if ( V_122 )
return V_122 ;
if ( ! V_2 -> V_165 . V_242 ) {
V_122 = F_52 ( V_2 ) ;
if ( V_122 ) {
F_40 ( V_2 -> V_31 , L_19 , V_122 ) ;
return V_122 ;
}
V_2 -> V_165 . V_242 = true ;
}
return V_122 ;
}
static bool F_86 ( void * V_232 )
{
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
V_6 V_17 = F_7 ( V_243 ) ;
if ( V_17 & ( V_244 | V_245 |
V_246 | V_247 | V_248 ) )
return false ;
return true ;
}
static int F_6 ( void * V_232 )
{
unsigned V_39 ;
V_6 V_17 ;
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_57 ; V_39 ++ ) {
V_17 = F_7 ( V_243 ) & ( V_244 |
V_245 |
V_246 |
V_247 |
V_248 ) ;
if ( ! V_17 )
return 0 ;
F_11 ( 1 ) ;
}
return - V_249 ;
}
static int F_87 ( void * V_232 )
{
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
struct V_8 V_9 ;
V_6 V_250 = 0 ;
V_6 V_17 = F_7 ( V_243 ) ;
if ( V_17 & V_248 )
V_250 = F_10 ( V_250 ,
V_251 , V_252 , 1 ) ;
if ( V_17 & ( V_244 | V_245 |
V_246 | V_247 ) ) {
if ( ! ( V_2 -> V_111 & V_181 ) )
V_250 = F_10 ( V_250 ,
V_251 , V_253 , 1 ) ;
}
if ( V_250 ) {
F_4 ( V_2 , & V_9 ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_26 ( V_2 -> V_31 , L_21 ) ;
}
V_17 = F_7 ( V_254 ) ;
V_17 |= V_250 ;
F_88 ( V_2 -> V_31 , L_22 , V_17 ) ;
F_9 ( V_254 , V_17 ) ;
V_17 = F_7 ( V_254 ) ;
F_11 ( 50 ) ;
V_17 &= ~ V_250 ;
F_9 ( V_254 , V_17 ) ;
V_17 = F_7 ( V_254 ) ;
F_11 ( 50 ) ;
F_12 ( V_2 , & V_9 ) ;
F_11 ( 50 ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_255 * V_256 ,
unsigned type ,
enum V_257 V_258 )
{
V_6 V_17 ;
V_6 V_259 = ( V_260 |
V_261 |
V_262 |
V_263 |
V_264 |
V_265 ) ;
switch ( V_258 ) {
case V_266 :
V_17 = F_7 ( V_159 ) ;
V_17 &= ~ V_259 ;
F_9 ( V_159 , V_17 ) ;
V_17 = F_7 ( V_114 ) ;
V_17 &= ~ V_259 ;
F_9 ( V_114 , V_17 ) ;
break;
case V_267 :
V_17 = F_7 ( V_159 ) ;
V_17 |= V_259 ;
F_9 ( V_159 , V_17 ) ;
V_17 = F_7 ( V_114 ) ;
V_17 |= V_259 ;
F_9 ( V_114 , V_17 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_255 * V_268 ,
struct V_269 * V_270 )
{
V_6 V_110 , V_184 , V_185 ;
V_110 = F_7 ( V_271 ) ;
V_184 = F_7 ( V_272 ) ;
V_185 = F_7 ( V_273 ) ;
F_91 ( V_169 , 1 , ~ 1 ) ;
if ( ! V_110 && ! V_184 )
return 0 ;
if ( V_172 == V_274 )
F_38 ( V_2 , false ) ;
F_40 ( V_2 -> V_31 , L_23 ,
V_270 -> V_275 , V_270 -> V_276 ) ;
F_40 ( V_2 -> V_31 , L_24 ,
V_110 ) ;
F_40 ( V_2 -> V_31 , L_25 ,
V_184 ) ;
F_55 ( V_2 , V_184 , V_110 , V_185 ) ;
return 0 ;
}
static int F_92 ( void * V_232 ,
enum V_277 V_258 )
{
bool V_278 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_232 ;
if ( V_258 == V_279 )
V_278 = true ;
if ( ! ( V_2 -> V_111 & V_181 ) ) {
F_57 ( V_2 , V_278 ) ;
F_56 ( V_2 , V_278 ) ;
}
F_58 ( V_2 , V_278 ) ;
F_61 ( V_2 , V_278 ) ;
F_62 ( V_2 , V_278 ) ;
return 0 ;
}
static int F_93 ( void * V_232 ,
enum V_280 V_258 )
{
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_123 . V_281 == NULL )
V_2 -> V_123 . V_281 = & V_282 ;
}
static void F_66 ( struct V_1 * V_2 )
{
V_2 -> V_29 . V_233 . V_283 = 1 ;
V_2 -> V_29 . V_233 . V_284 = & V_285 ;
}
