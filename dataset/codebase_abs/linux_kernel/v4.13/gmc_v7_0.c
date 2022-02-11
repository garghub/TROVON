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
F_19 ( L_7 , V_22 ) ;
F_20 ( V_2 -> V_29 . V_30 ) ;
V_2 -> V_29 . V_30 = NULL ;
}
return V_23 ;
}
static int F_21 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 ;
const T_1 * V_35 = NULL ;
const T_1 * V_36 = NULL ;
V_6 V_37 ;
int V_38 , V_39 , V_40 ;
if ( ! V_2 -> V_29 . V_30 )
return - V_41 ;
V_34 = ( const struct V_33 * ) V_2 -> V_29 . V_30 -> V_42 ;
F_22 ( & V_34 -> V_43 ) ;
V_2 -> V_29 . V_44 = F_23 ( V_34 -> V_43 . V_45 ) ;
V_40 = F_23 ( V_34 -> V_46 ) / ( 4 * 2 ) ;
V_36 = ( const T_1 * )
( V_2 -> V_29 . V_30 -> V_42 + F_23 ( V_34 -> V_47 ) ) ;
V_39 = F_23 ( V_34 -> V_43 . V_48 ) / 4 ;
V_35 = ( const T_1 * )
( V_2 -> V_29 . V_30 -> V_42 + F_23 ( V_34 -> V_43 . V_49 ) ) ;
V_37 = F_8 ( F_7 ( V_50 ) , V_51 , V_52 ) ;
if ( V_37 == 0 ) {
F_9 ( V_50 , 0x00000008 ) ;
F_9 ( V_50 , 0x00000010 ) ;
for ( V_38 = 0 ; V_38 < V_40 ; V_38 ++ ) {
F_9 ( V_53 , F_24 ( V_36 ++ ) ) ;
F_9 ( V_54 , F_24 ( V_36 ++ ) ) ;
}
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
F_9 ( V_55 , F_24 ( V_35 ++ ) ) ;
F_9 ( V_50 , 0x00000008 ) ;
F_9 ( V_50 , 0x00000004 ) ;
F_9 ( V_50 , 0x00000001 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_56 ; V_38 ++ ) {
if ( F_8 ( F_7 ( V_57 ) ,
V_58 , V_59 ) )
break;
F_11 ( 1 ) ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_56 ; V_38 ++ ) {
if ( F_8 ( F_7 ( V_57 ) ,
V_58 , V_60 ) )
break;
F_11 ( 1 ) ;
}
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_61 * V_29 )
{
if ( V_29 -> V_62 > 0xFFC0000000ULL ) {
F_26 ( V_2 -> V_31 , L_8 ) ;
V_29 -> V_63 = 0xFFC0000000ULL ;
V_29 -> V_62 = 0xFFC0000000ULL ;
}
F_27 ( V_2 , & V_2 -> V_29 , 0 ) ;
V_2 -> V_29 . V_64 = 0 ;
F_28 ( V_2 , V_29 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_8 V_9 ;
V_6 V_17 ;
int V_38 , V_65 ;
for ( V_38 = 0 , V_65 = 0 ; V_38 < 32 ; V_38 ++ , V_65 += 0x6 ) {
F_9 ( ( 0xb05 + V_65 ) , 0x00000000 ) ;
F_9 ( ( 0xb06 + V_65 ) , 0x00000000 ) ;
F_9 ( ( 0xb07 + V_65 ) , 0x00000000 ) ;
F_9 ( ( 0xb08 + V_65 ) , 0x00000000 ) ;
F_9 ( ( 0xb09 + V_65 ) , 0x00000000 ) ;
}
F_9 ( V_66 , 0 ) ;
if ( V_2 -> V_11 . V_12 )
F_30 ( V_2 , false ) ;
F_4 ( V_2 , & V_9 ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_26 ( V_2 -> V_31 , L_9 ) ;
}
F_9 ( V_67 ,
V_2 -> V_29 . V_68 >> 12 ) ;
F_9 ( V_69 ,
V_2 -> V_29 . V_70 >> 12 ) ;
F_9 ( V_71 ,
V_2 -> V_72 . V_73 >> 12 ) ;
V_17 = ( ( V_2 -> V_29 . V_70 >> 24 ) & 0xFFFF ) << 16 ;
V_17 |= ( ( V_2 -> V_29 . V_68 >> 24 ) & 0xFFFF ) ;
F_9 ( V_74 , V_17 ) ;
F_9 ( V_75 , ( V_2 -> V_29 . V_68 >> 8 ) ) ;
F_9 ( V_76 , ( 2 << 7 ) | ( 1 << 30 ) ) ;
F_9 ( V_77 , 0x3FFFFFFF ) ;
F_9 ( V_78 , 0 ) ;
F_9 ( V_79 , 0x0FFFFFFF ) ;
F_9 ( V_80 , 0x0FFFFFFF ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_26 ( V_2 -> V_31 , L_9 ) ;
}
F_12 ( V_2 , & V_9 ) ;
F_9 ( V_16 , V_81 | V_82 ) ;
V_17 = F_7 ( V_83 ) ;
V_17 = F_10 ( V_17 , V_84 , V_85 , 0 ) ;
F_9 ( V_83 , V_17 ) ;
V_17 = F_7 ( V_86 ) ;
F_9 ( V_86 , V_17 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
V_2 -> V_29 . V_87 = F_32 ( V_2 ) ;
if ( ! V_2 -> V_29 . V_87 ) {
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
V_2 -> V_29 . V_87 = V_89 * V_88 ;
}
V_2 -> V_29 . V_96 = F_33 ( V_2 -> V_97 , 0 ) ;
V_2 -> V_29 . V_98 = F_34 ( V_2 -> V_97 , 0 ) ;
V_2 -> V_29 . V_62 = F_7 ( V_99 ) * 1024ULL * 1024ULL ;
V_2 -> V_29 . V_63 = F_7 ( V_99 ) * 1024ULL * 1024ULL ;
#ifdef F_35
if ( V_2 -> V_100 & V_101 ) {
V_2 -> V_29 . V_96 = ( ( V_102 ) F_7 ( V_103 ) ) << 22 ;
V_2 -> V_29 . V_98 = V_2 -> V_29 . V_63 ;
}
#endif
V_2 -> V_29 . V_104 = V_2 -> V_29 . V_98 ;
if ( V_2 -> V_29 . V_104 > V_2 -> V_29 . V_63 )
V_2 -> V_29 . V_104 = V_2 -> V_29 . V_63 ;
if ( V_105 == - 1 )
V_2 -> V_29 . V_106 = F_36 ( ( V_107 << 20 ) ,
V_2 -> V_29 . V_62 ) ;
else
V_2 -> V_29 . V_106 = ( V_108 ) V_105 << 20 ;
F_25 ( V_2 , & V_2 -> V_29 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 ,
T_2 V_109 )
{
F_9 ( V_110 , 0 ) ;
F_9 ( V_111 , 1 << V_109 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
void * V_112 ,
T_2 V_113 ,
V_108 V_114 ,
V_108 V_100 )
{
void T_3 * V_115 = ( void * ) V_112 ;
V_108 V_116 ;
V_116 = V_114 & 0xFFFFFFFFFFFFF000ULL ;
V_116 |= V_100 ;
F_39 ( V_116 , V_115 + ( V_113 * 8 ) ) ;
return 0 ;
}
static V_108 F_40 ( struct V_1 * V_2 ,
T_2 V_100 )
{
V_108 V_117 = 0 ;
if ( V_100 & V_118 )
V_117 |= V_119 ;
if ( V_100 & V_120 )
V_117 |= V_121 ;
if ( V_100 & V_122 )
V_117 |= V_123 ;
return V_117 ;
}
static V_108 F_41 ( struct V_1 * V_2 , V_108 V_114 )
{
F_42 ( V_114 & 0xFFFFFF0000000FFFULL ) ;
return V_114 ;
}
static void F_43 ( struct V_1 * V_2 ,
bool V_116 )
{
V_6 V_17 ;
V_17 = F_7 ( V_124 ) ;
V_17 = F_10 ( V_17 , V_125 ,
V_126 , V_116 ) ;
V_17 = F_10 ( V_17 , V_125 ,
V_127 , V_116 ) ;
V_17 = F_10 ( V_17 , V_125 ,
V_128 , V_116 ) ;
V_17 = F_10 ( V_17 , V_125 ,
V_129 , V_116 ) ;
V_17 = F_10 ( V_17 , V_125 ,
V_130 , V_116 ) ;
V_17 = F_10 ( V_17 , V_125 ,
V_131 , V_116 ) ;
F_9 ( V_124 , V_17 ) ;
}
static void F_44 ( struct V_1 * V_2 , bool V_132 )
{
T_2 V_17 ;
if ( V_132 && ! V_2 -> V_29 . V_133 ) {
F_26 ( V_2 -> V_31 , L_10 ) ;
V_2 -> V_29 . V_133 = true ;
}
V_17 = F_7 ( V_134 ) ;
V_17 = F_10 ( V_17 , V_135 ,
V_136 , V_132 ) ;
V_17 = F_10 ( V_17 , V_135 ,
V_137 , V_132 ) ;
V_17 = F_10 ( V_17 , V_135 ,
V_138 , V_132 ) ;
V_17 = F_10 ( V_17 , V_135 ,
V_139 , V_132 ) ;
V_17 = F_10 ( V_17 , V_135 ,
V_140 , V_132 ) ;
V_17 = F_10 ( V_17 , V_135 ,
V_141 , V_132 ) ;
V_17 = F_10 ( V_17 , V_135 ,
V_142 , V_132 ) ;
F_9 ( V_134 , V_17 ) ;
if ( V_132 ) {
T_2 V_143 = V_144 >> V_145 ;
T_2 V_146 = V_2 -> V_147 . V_148 ;
F_9 ( V_149 , V_143 ) ;
F_9 ( V_150 , V_143 ) ;
F_9 ( V_151 , V_143 ) ;
F_9 ( V_152 , V_143 ) ;
F_9 ( V_153 , V_146 ) ;
F_9 ( V_154 , V_146 ) ;
F_9 ( V_155 , V_146 ) ;
F_9 ( V_156 , V_146 ) ;
} else {
F_9 ( V_149 , 0xfffffff ) ;
F_9 ( V_150 , 0xfffffff ) ;
F_9 ( V_151 , 0xfffffff ) ;
F_9 ( V_152 , 0xfffffff ) ;
F_9 ( V_153 , 0x0 ) ;
F_9 ( V_154 , 0x0 ) ;
F_9 ( V_155 , 0x0 ) ;
F_9 ( V_156 , 0x0 ) ;
}
}
static int F_45 ( struct V_1 * V_2 )
{
int V_157 , V_38 ;
V_6 V_17 ;
if ( V_2 -> V_158 . V_159 == NULL ) {
F_46 ( V_2 -> V_31 , L_11 ) ;
return - V_41 ;
}
V_157 = F_47 ( V_2 ) ;
if ( V_157 )
return V_157 ;
V_17 = F_7 ( V_160 ) ;
V_17 = F_10 ( V_17 , V_161 , V_162 , 1 ) ;
V_17 = F_10 ( V_17 , V_161 , V_163 , 1 ) ;
V_17 = F_10 ( V_17 , V_161 , V_164 , 3 ) ;
V_17 = F_10 ( V_17 , V_161 , V_165 , 1 ) ;
V_17 = F_10 ( V_17 , V_161 , V_166 , 0 ) ;
F_9 ( V_160 , V_17 ) ;
V_17 = F_7 ( V_167 ) ;
V_17 = F_10 ( V_17 , V_168 , V_169 , 1 ) ;
V_17 = F_10 ( V_17 , V_168 , V_170 , 1 ) ;
V_17 = F_10 ( V_17 , V_168 , V_171 , 1 ) ;
V_17 = F_10 ( V_17 , V_168 , V_172 , 1 ) ;
V_17 = F_10 ( V_17 , V_168 , V_173 , 7 ) ;
V_17 = F_10 ( V_17 , V_168 , V_174 , 1 ) ;
V_17 = F_10 ( V_17 , V_168 , V_175 , 1 ) ;
F_9 ( V_167 , V_17 ) ;
V_17 = F_10 ( 0 , V_176 , V_177 , 1 ) ;
V_17 = F_10 ( V_17 , V_176 , V_178 , 1 ) ;
F_9 ( V_179 , V_17 ) ;
V_17 = F_7 ( V_180 ) ;
V_17 = F_10 ( V_17 , V_181 , V_182 , 1 ) ;
V_17 = F_10 ( V_17 , V_181 , V_183 , 4 ) ;
V_17 = F_10 ( V_17 , V_181 , V_184 , 4 ) ;
F_9 ( V_180 , V_17 ) ;
F_9 ( V_185 , V_2 -> V_29 . V_186 >> 12 ) ;
F_9 ( V_187 , V_2 -> V_29 . V_188 >> 12 ) ;
F_9 ( V_189 , V_2 -> V_158 . V_190 >> 12 ) ;
F_9 ( V_191 ,
( V_6 ) ( V_2 -> V_192 . V_114 >> 12 ) ) ;
F_9 ( V_193 , 0 ) ;
V_17 = F_7 ( V_194 ) ;
V_17 = F_10 ( V_17 , V_195 , V_196 , 1 ) ;
V_17 = F_10 ( V_17 , V_195 , V_197 , 0 ) ;
V_17 = F_10 ( V_17 , V_195 , V_126 , 1 ) ;
F_9 ( V_194 , V_17 ) ;
F_9 ( 0x575 , 0 ) ;
F_9 ( 0x576 , 0 ) ;
F_9 ( 0x577 , 0 ) ;
F_9 ( V_198 , 0 ) ;
F_9 ( V_199 , V_2 -> V_147 . V_148 - 1 ) ;
for ( V_38 = 1 ; V_38 < 16 ; V_38 ++ ) {
if ( V_38 < 8 )
F_9 ( V_189 + V_38 ,
V_2 -> V_158 . V_190 >> 12 ) ;
else
F_9 ( V_200 + V_38 - 8 ,
V_2 -> V_158 . V_190 >> 12 ) ;
}
F_9 ( V_201 ,
( V_6 ) ( V_2 -> V_192 . V_114 >> 12 ) ) ;
F_9 ( V_202 , 4 ) ;
V_17 = F_7 ( V_124 ) ;
V_17 = F_10 ( V_17 , V_125 , V_196 , 1 ) ;
V_17 = F_10 ( V_17 , V_125 , V_197 , 1 ) ;
V_17 = F_10 ( V_17 , V_125 , V_203 ,
V_2 -> V_147 . V_204 - 9 ) ;
F_9 ( V_124 , V_17 ) ;
if ( V_205 == V_206 )
F_43 ( V_2 , false ) ;
else
F_43 ( V_2 , true ) ;
if ( V_2 -> V_3 == V_26 ) {
V_17 = F_7 ( V_207 ) ;
V_17 &= ~ V_208 ;
F_9 ( V_207 , V_17 ) ;
}
F_37 ( V_2 , 0 ) ;
F_48 ( L_12 ,
( unsigned ) ( V_2 -> V_29 . V_106 >> 20 ) ,
( unsigned long long ) V_2 -> V_158 . V_190 ) ;
V_2 -> V_158 . V_209 = true ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_157 ;
if ( V_2 -> V_158 . V_159 ) {
F_50 ( 1 , L_13 ) ;
return 0 ;
}
V_157 = F_51 ( V_2 ) ;
if ( V_157 )
return V_157 ;
V_2 -> V_158 . V_210 = V_2 -> V_158 . V_211 * 8 ;
V_2 -> V_158 . V_212 = 0 ;
return F_52 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
V_6 V_17 ;
F_9 ( V_194 , 0 ) ;
F_9 ( V_124 , 0 ) ;
V_17 = F_7 ( V_160 ) ;
V_17 = F_10 ( V_17 , V_161 , V_162 , 0 ) ;
V_17 = F_10 ( V_17 , V_161 , V_163 , 0 ) ;
V_17 = F_10 ( V_17 , V_161 , V_165 , 0 ) ;
F_9 ( V_160 , V_17 ) ;
V_17 = F_7 ( V_167 ) ;
V_17 = F_10 ( V_17 , V_168 , V_169 , 0 ) ;
F_9 ( V_167 , V_17 ) ;
F_9 ( V_179 , 0 ) ;
F_54 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
V_6 V_213 , V_6 V_114 , V_6 V_214 )
{
V_6 V_215 ;
V_6 V_109 = F_8 ( V_213 , V_216 , V_217 ) ;
V_6 V_218 = F_8 ( V_213 , V_216 ,
V_219 ) ;
char V_220 [ 5 ] = { V_214 >> 24 , ( V_214 >> 16 ) & 0xff ,
( V_214 >> 8 ) & 0xff , V_214 & 0xff , 0 } ;
V_215 = F_8 ( V_213 , V_216 ,
V_221 ) ;
F_46 ( V_2 -> V_31 , L_14 ,
V_218 , V_109 , V_114 ,
F_8 ( V_213 , V_216 ,
V_222 ) ?
L_15 : L_16 , V_220 , V_214 , V_215 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
bool V_132 )
{
int V_38 ;
V_6 V_223 , V_42 ;
for ( V_38 = 0 ; V_38 < F_3 ( V_224 ) ; V_38 ++ ) {
V_223 = V_42 = F_7 ( V_224 [ V_38 ] ) ;
if ( V_132 && ( V_2 -> V_225 & V_226 ) )
V_42 |= V_227 [ V_38 ] ;
else
V_42 &= ~ V_227 [ V_38 ] ;
if ( V_42 != V_223 )
F_9 ( V_224 [ V_38 ] , V_42 ) ;
}
}
static void F_60 ( struct V_1 * V_2 ,
bool V_132 )
{
int V_38 ;
V_6 V_223 , V_42 ;
for ( V_38 = 0 ; V_38 < F_3 ( V_224 ) ; V_38 ++ ) {
V_223 = V_42 = F_7 ( V_224 [ V_38 ] ) ;
if ( V_132 && ( V_2 -> V_225 & V_228 ) )
V_42 |= V_229 [ V_38 ] ;
else
V_42 &= ~ V_229 [ V_38 ] ;
if ( V_42 != V_223 )
F_9 ( V_224 [ V_38 ] , V_42 ) ;
}
}
static void F_61 ( struct V_1 * V_2 ,
bool V_132 )
{
V_6 V_223 , V_42 ;
V_223 = V_42 = F_62 ( V_230 ) ;
if ( V_132 && ( V_2 -> V_225 & V_231 ) ) {
V_42 = F_10 ( V_42 , V_232 , V_233 , 1 ) ;
V_42 = F_10 ( V_42 , V_232 , V_234 , 1 ) ;
V_42 = F_10 ( V_42 , V_232 , V_235 , 1 ) ;
V_42 = F_10 ( V_42 , V_232 , V_236 , 1 ) ;
} else {
V_42 = F_10 ( V_42 , V_232 , V_233 , 0 ) ;
V_42 = F_10 ( V_42 , V_232 , V_234 , 0 ) ;
V_42 = F_10 ( V_42 , V_232 , V_235 , 0 ) ;
V_42 = F_10 ( V_42 , V_232 , V_236 , 0 ) ;
}
if ( V_223 != V_42 )
F_63 ( V_230 , V_42 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
bool V_132 )
{
V_6 V_223 , V_42 ;
V_223 = V_42 = F_7 ( V_86 ) ;
if ( V_132 && ( V_2 -> V_225 & V_237 ) )
V_42 = F_10 ( V_42 , V_238 , V_239 , 0 ) ;
else
V_42 = F_10 ( V_42 , V_238 , V_239 , 1 ) ;
if ( V_223 != V_42 )
F_9 ( V_86 , V_42 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
bool V_132 )
{
V_6 V_223 , V_42 ;
V_223 = V_42 = F_7 ( V_240 ) ;
if ( V_132 && ( V_2 -> V_225 & V_241 ) )
V_42 = F_10 ( V_42 , V_242 , V_243 , 1 ) ;
else
V_42 = F_10 ( V_42 , V_242 , V_243 , 0 ) ;
if ( V_223 != V_42 )
F_9 ( V_240 , V_42 ) ;
}
static int F_66 ( int V_244 )
{
switch ( V_244 ) {
case V_245 :
return V_246 ;
case V_247 :
return V_248 ;
case V_249 :
return V_250 ;
case V_251 :
return V_252 ;
case V_253 :
return V_254 ;
case V_255 :
return V_256 ;
case V_257 :
return V_258 ;
default:
return V_259 ;
}
}
static int F_67 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_29 . V_261 = 0x2000000000000000ULL ;
V_2 -> V_29 . V_262 =
V_2 -> V_29 . V_261 + ( 4ULL << 30 ) - 1 ;
V_2 -> V_29 . V_263 =
V_2 -> V_29 . V_262 + 1 ;
V_2 -> V_29 . V_264 =
V_2 -> V_29 . V_263 + ( 4ULL << 30 ) - 1 ;
return 0 ;
}
static int F_70 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
if ( V_205 != V_206 )
return F_71 ( V_2 , & V_2 -> V_29 . V_265 , 0 ) ;
else
return 0 ;
}
static int F_72 ( void * V_260 )
{
int V_157 ;
int V_266 ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
if ( V_2 -> V_100 & V_101 ) {
V_2 -> V_29 . V_267 = V_259 ;
} else {
V_6 V_17 = F_7 ( V_268 ) ;
V_17 &= V_269 ;
V_2 -> V_29 . V_267 = F_66 ( V_17 ) ;
}
V_157 = F_73 ( V_2 , V_270 , 146 , & V_2 -> V_29 . V_265 ) ;
if ( V_157 )
return V_157 ;
V_157 = F_73 ( V_2 , V_270 , 147 , & V_2 -> V_29 . V_265 ) ;
if ( V_157 )
return V_157 ;
F_74 ( V_2 , 64 ) ;
V_2 -> V_147 . V_148 = V_2 -> V_147 . V_271 << 18 ;
V_2 -> V_29 . V_272 = 0xffffffffffULL ;
V_2 -> V_29 . V_273 = 256 * 1024 ;
V_2 -> V_274 = false ;
V_266 = V_2 -> V_274 ? 32 : 40 ;
V_157 = F_75 ( V_2 -> V_97 , F_76 ( V_266 ) ) ;
if ( V_157 ) {
V_2 -> V_274 = true ;
V_266 = 32 ;
F_77 ( L_17 ) ;
}
V_157 = F_78 ( V_2 -> V_97 , F_76 ( V_266 ) ) ;
if ( V_157 ) {
F_78 ( V_2 -> V_97 , F_76 ( 32 ) ) ;
F_77 ( L_18 ) ;
}
V_157 = F_14 ( V_2 ) ;
if ( V_157 ) {
F_79 ( L_19 ) ;
return V_157 ;
}
V_157 = F_31 ( V_2 ) ;
if ( V_157 )
return V_157 ;
V_157 = F_80 ( V_2 ) ;
if ( V_157 )
return V_157 ;
V_157 = F_49 ( V_2 ) ;
if ( V_157 )
return V_157 ;
V_2 -> V_147 . V_275 [ 0 ] . V_276 = V_277 ;
V_2 -> V_147 . V_278 = 1 ;
F_81 ( V_2 ) ;
if ( V_2 -> V_100 & V_101 ) {
V_102 V_17 = F_7 ( V_103 ) ;
V_17 <<= 22 ;
V_2 -> V_147 . V_279 = V_17 ;
} else {
V_2 -> V_147 . V_279 = 0 ;
}
return 0 ;
}
static int F_82 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_83 ( V_2 ) ;
F_55 ( V_2 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_86 ( void * V_260 )
{
int V_157 ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_1 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( ! ( V_2 -> V_100 & V_101 ) ) {
V_157 = F_21 ( V_2 ) ;
if ( V_157 ) {
F_79 ( L_20 ) ;
return V_157 ;
}
}
V_157 = F_45 ( V_2 ) ;
if ( V_157 )
return V_157 ;
return V_157 ;
}
static int F_87 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_88 ( V_2 , & V_2 -> V_29 . V_265 , 0 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_89 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_87 ( V_2 ) ;
return 0 ;
}
static int F_90 ( void * V_260 )
{
int V_157 ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
V_157 = F_86 ( V_2 ) ;
if ( V_157 )
return V_157 ;
F_91 ( V_2 ) ;
return 0 ;
}
static bool F_92 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
V_6 V_17 = F_7 ( V_280 ) ;
if ( V_17 & ( V_281 | V_282 |
V_283 | V_284 | V_285 ) )
return false ;
return true ;
}
static int F_6 ( void * V_260 )
{
unsigned V_38 ;
V_6 V_17 ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_56 ; V_38 ++ ) {
V_17 = F_7 ( V_280 ) & ( V_281 |
V_282 |
V_283 |
V_284 |
V_285 ) ;
if ( ! V_17 )
return 0 ;
F_11 ( 1 ) ;
}
return - V_286 ;
}
static int F_93 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
struct V_8 V_9 ;
V_6 V_287 = 0 ;
V_6 V_17 = F_7 ( V_280 ) ;
if ( V_17 & V_285 )
V_287 = F_10 ( V_287 ,
V_288 , V_289 , 1 ) ;
if ( V_17 & ( V_281 | V_282 |
V_283 | V_284 ) ) {
if ( ! ( V_2 -> V_100 & V_101 ) )
V_287 = F_10 ( V_287 ,
V_288 , V_290 , 1 ) ;
}
if ( V_287 ) {
F_4 ( V_2 , & V_9 ) ;
if ( F_6 ( ( void * ) V_2 ) ) {
F_26 ( V_2 -> V_31 , L_21 ) ;
}
V_17 = F_7 ( V_291 ) ;
V_17 |= V_287 ;
F_94 ( V_2 -> V_31 , L_22 , V_17 ) ;
F_9 ( V_291 , V_17 ) ;
V_17 = F_7 ( V_291 ) ;
F_11 ( 50 ) ;
V_17 &= ~ V_287 ;
F_9 ( V_291 , V_17 ) ;
V_17 = F_7 ( V_291 ) ;
F_11 ( 50 ) ;
F_12 ( V_2 , & V_9 ) ;
F_11 ( 50 ) ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
unsigned type ,
enum V_294 V_295 )
{
V_6 V_17 ;
V_6 V_296 = ( V_297 |
V_298 |
V_299 |
V_300 |
V_301 |
V_302 ) ;
switch ( V_295 ) {
case V_303 :
V_17 = F_7 ( V_194 ) ;
V_17 &= ~ V_296 ;
F_9 ( V_194 , V_17 ) ;
V_17 = F_7 ( V_124 ) ;
V_17 &= ~ V_296 ;
F_9 ( V_124 , V_17 ) ;
break;
case V_304 :
V_17 = F_7 ( V_194 ) ;
V_17 |= V_296 ;
F_9 ( V_194 , V_17 ) ;
V_17 = F_7 ( V_124 ) ;
V_17 |= V_296 ;
F_9 ( V_124 , V_17 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_292 * V_305 ,
struct V_306 * V_307 )
{
V_6 V_114 , V_213 , V_214 ;
V_114 = F_7 ( V_308 ) ;
V_213 = F_7 ( V_309 ) ;
V_214 = F_7 ( V_310 ) ;
F_97 ( V_202 , 1 , ~ 1 ) ;
if ( ! V_114 && ! V_213 )
return 0 ;
if ( V_205 == V_311 )
F_43 ( V_2 , false ) ;
if ( F_98 () ) {
F_46 ( V_2 -> V_31 , L_23 ,
V_307 -> V_312 , V_307 -> V_313 [ 0 ] ) ;
F_46 ( V_2 -> V_31 , L_24 ,
V_114 ) ;
F_46 ( V_2 -> V_31 , L_25 ,
V_213 ) ;
F_58 ( V_2 , V_213 , V_114 , V_214 ) ;
}
return 0 ;
}
static int F_99 ( void * V_260 ,
enum V_314 V_295 )
{
bool V_315 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
if ( V_295 == V_316 )
V_315 = true ;
if ( ! ( V_2 -> V_100 & V_101 ) ) {
F_60 ( V_2 , V_315 ) ;
F_59 ( V_2 , V_315 ) ;
}
F_61 ( V_2 , V_315 ) ;
F_64 ( V_2 , V_315 ) ;
F_65 ( V_2 , V_315 ) ;
return 0 ;
}
static int F_100 ( void * V_260 ,
enum V_317 V_295 )
{
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_158 . V_318 == NULL )
V_2 -> V_158 . V_318 = & V_319 ;
}
static void F_69 ( struct V_1 * V_2 )
{
V_2 -> V_29 . V_265 . V_320 = 1 ;
V_2 -> V_29 . V_265 . V_321 = & V_322 ;
}
