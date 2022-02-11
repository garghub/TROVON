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
static void F_4 ( struct V_1 * V_2 )
{
V_6 V_8 ;
F_5 ( ( void * ) V_2 ) ;
V_8 = F_6 ( V_9 ) ;
if ( F_7 ( V_8 , V_10 , V_11 ) != 1 ) {
F_8 ( V_12 , 0 ) ;
V_8 = F_9 ( V_8 ,
V_10 , V_11 , 0 ) ;
F_8 ( V_9 , V_8 | 1 ) ;
}
F_10 ( 100 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_6 V_13 ;
V_13 = F_6 ( V_9 ) ;
V_13 = F_9 ( V_13 , V_10 , V_11 , 0 ) ;
F_8 ( V_9 , V_13 ) ;
V_13 = F_9 ( 0 , V_14 , V_15 , 1 ) ;
V_13 = F_9 ( V_13 , V_14 , V_16 , 1 ) ;
F_8 ( V_12 , V_13 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
const char * V_17 ;
char V_18 [ 30 ] ;
int V_19 ;
F_13 ( L_1 ) ;
switch ( V_2 -> V_3 ) {
case V_20 :
V_17 = L_2 ;
break;
case V_21 :
V_17 = L_3 ;
break;
case V_4 :
V_17 = L_4 ;
break;
case V_22 :
case V_23 :
case V_24 :
return 0 ;
default: F_14 () ;
}
if ( V_2 -> V_3 == V_4 )
snprintf ( V_18 , sizeof( V_18 ) , L_5 , V_17 ) ;
else
snprintf ( V_18 , sizeof( V_18 ) , L_6 , V_17 ) ;
V_19 = F_15 ( & V_2 -> V_25 . V_26 , V_18 , V_2 -> V_27 ) ;
if ( V_19 )
goto V_28;
V_19 = F_16 ( V_2 -> V_25 . V_26 ) ;
V_28:
if ( V_19 ) {
F_17 ( L_7 , V_18 ) ;
F_18 ( V_2 -> V_25 . V_26 ) ;
V_2 -> V_25 . V_26 = NULL ;
}
return V_19 ;
}
static int F_19 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 ;
const T_1 * V_31 = NULL ;
const T_1 * V_32 = NULL ;
V_6 V_33 ;
int V_34 , V_35 , V_36 ;
if ( ! V_2 -> V_25 . V_26 )
return - V_37 ;
V_30 = ( const struct V_29 * ) V_2 -> V_25 . V_26 -> V_38 ;
F_20 ( & V_30 -> V_39 ) ;
V_2 -> V_25 . V_40 = F_21 ( V_30 -> V_39 . V_41 ) ;
V_36 = F_21 ( V_30 -> V_42 ) / ( 4 * 2 ) ;
V_32 = ( const T_1 * )
( V_2 -> V_25 . V_26 -> V_38 + F_21 ( V_30 -> V_43 ) ) ;
V_35 = F_21 ( V_30 -> V_39 . V_44 ) / 4 ;
V_31 = ( const T_1 * )
( V_2 -> V_25 . V_26 -> V_38 + F_21 ( V_30 -> V_39 . V_45 ) ) ;
V_33 = F_7 ( F_6 ( V_46 ) , V_47 , V_48 ) ;
if ( V_33 == 0 ) {
F_8 ( V_46 , 0x00000008 ) ;
F_8 ( V_46 , 0x00000010 ) ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ ) {
F_8 ( V_49 , F_22 ( V_32 ++ ) ) ;
F_8 ( V_50 , F_22 ( V_32 ++ ) ) ;
}
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
F_8 ( V_51 , F_22 ( V_31 ++ ) ) ;
F_8 ( V_46 , 0x00000008 ) ;
F_8 ( V_46 , 0x00000004 ) ;
F_8 ( V_46 , 0x00000001 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_52 ; V_34 ++ ) {
if ( F_7 ( F_6 ( V_53 ) ,
V_54 , V_55 ) )
break;
F_10 ( 1 ) ;
}
for ( V_34 = 0 ; V_34 < V_2 -> V_52 ; V_34 ++ ) {
if ( F_7 ( F_6 ( V_53 ) ,
V_54 , V_56 ) )
break;
F_10 ( 1 ) ;
}
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_57 * V_25 )
{
T_2 V_58 = F_6 ( V_59 ) & 0xFFFF ;
V_58 <<= 24 ;
if ( V_25 -> V_60 > 0xFFC0000000ULL ) {
F_24 ( V_2 -> V_27 , L_8 ) ;
V_25 -> V_61 = 0xFFC0000000ULL ;
V_25 -> V_60 = 0xFFC0000000ULL ;
}
F_25 ( V_2 , & V_2 -> V_25 , V_58 ) ;
F_26 ( V_2 , V_25 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
V_6 V_13 ;
int V_34 , V_62 ;
for ( V_34 = 0 , V_62 = 0 ; V_34 < 32 ; V_34 ++ , V_62 += 0x6 ) {
F_8 ( ( 0xb05 + V_62 ) , 0x00000000 ) ;
F_8 ( ( 0xb06 + V_62 ) , 0x00000000 ) ;
F_8 ( ( 0xb07 + V_62 ) , 0x00000000 ) ;
F_8 ( ( 0xb08 + V_62 ) , 0x00000000 ) ;
F_8 ( ( 0xb09 + V_62 ) , 0x00000000 ) ;
}
F_8 ( V_63 , 0 ) ;
if ( F_5 ( ( void * ) V_2 ) ) {
F_24 ( V_2 -> V_27 , L_9 ) ;
}
if ( V_2 -> V_64 . V_65 ) {
V_13 = F_6 ( V_66 ) ;
V_13 = F_9 ( V_13 , V_67 , V_68 , 1 ) ;
F_8 ( V_66 , V_13 ) ;
V_13 = F_6 ( V_69 ) ;
V_13 = F_9 ( V_13 , V_70 , V_71 , 0 ) ;
F_8 ( V_69 , V_13 ) ;
}
F_8 ( V_72 ,
V_2 -> V_25 . V_73 >> 12 ) ;
F_8 ( V_74 ,
V_2 -> V_25 . V_75 >> 12 ) ;
F_8 ( V_76 ,
V_2 -> V_77 . V_78 >> 12 ) ;
F_8 ( V_79 , 0 ) ;
F_8 ( V_80 , 0x0FFFFFFF ) ;
F_8 ( V_81 , 0x0FFFFFFF ) ;
if ( F_5 ( ( void * ) V_2 ) ) {
F_24 ( V_2 -> V_27 , L_9 ) ;
}
F_8 ( V_12 , V_82 | V_83 ) ;
V_13 = F_6 ( V_84 ) ;
V_13 = F_9 ( V_13 , V_85 , V_86 , 0 ) ;
F_8 ( V_84 , V_13 ) ;
V_13 = F_6 ( V_87 ) ;
F_8 ( V_87 , V_13 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_88 = F_29 ( V_2 ) ;
if ( ! V_2 -> V_25 . V_88 ) {
V_6 V_13 ;
int V_89 , V_90 ;
V_13 = F_6 ( V_91 ) ;
if ( F_7 ( V_13 , V_92 , V_93 ) ) {
V_89 = 64 ;
} else {
V_89 = 32 ;
}
V_13 = F_6 ( V_94 ) ;
switch ( F_7 ( V_13 , V_95 , V_96 ) ) {
case 0 :
default:
V_90 = 1 ;
break;
case 1 :
V_90 = 2 ;
break;
case 2 :
V_90 = 4 ;
break;
case 3 :
V_90 = 8 ;
break;
case 4 :
V_90 = 3 ;
break;
case 5 :
V_90 = 6 ;
break;
case 6 :
V_90 = 10 ;
break;
case 7 :
V_90 = 12 ;
break;
case 8 :
V_90 = 16 ;
break;
}
V_2 -> V_25 . V_88 = V_90 * V_89 ;
}
V_2 -> V_25 . V_97 = F_30 ( V_2 -> V_98 , 0 ) ;
V_2 -> V_25 . V_99 = F_31 ( V_2 -> V_98 , 0 ) ;
V_2 -> V_25 . V_60 = F_6 ( V_100 ) * 1024ULL * 1024ULL ;
V_2 -> V_25 . V_61 = F_6 ( V_100 ) * 1024ULL * 1024ULL ;
#ifdef F_32
if ( V_2 -> V_101 & V_102 ) {
V_2 -> V_25 . V_97 = ( ( T_2 ) F_6 ( V_103 ) ) << 22 ;
V_2 -> V_25 . V_99 = V_2 -> V_25 . V_61 ;
}
#endif
V_2 -> V_25 . V_104 = V_2 -> V_25 . V_99 ;
if ( V_2 -> V_25 . V_104 > V_2 -> V_25 . V_61 )
V_2 -> V_25 . V_104 = V_2 -> V_25 . V_61 ;
if ( V_105 == - 1 ) {
switch ( V_2 -> V_3 ) {
case V_4 :
default:
V_2 -> V_25 . V_106 = 256ULL << 20 ;
break;
#ifdef F_33
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
V_2 -> V_25 . V_106 = 1024ULL << 20 ;
break;
#endif
}
} else {
V_2 -> V_25 . V_106 = ( T_2 ) V_105 << 20 ;
}
F_23 ( V_2 , & V_2 -> V_25 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 ,
T_3 V_107 )
{
F_8 ( V_108 , 0 ) ;
F_8 ( V_109 , 1 << V_107 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
void * V_110 ,
T_3 V_111 ,
T_4 V_112 ,
T_4 V_101 )
{
void T_5 * V_113 = ( void * ) V_110 ;
T_4 V_114 ;
V_114 = V_112 & 0xFFFFFFFFFFFFF000ULL ;
V_114 |= V_101 ;
F_36 ( V_114 , V_113 + ( V_111 * 8 ) ) ;
return 0 ;
}
static T_4 F_37 ( struct V_1 * V_2 ,
T_3 V_101 )
{
T_4 V_115 = 0 ;
if ( V_101 & V_116 )
V_115 |= V_117 ;
if ( V_101 & V_118 )
V_115 |= V_119 ;
if ( V_101 & V_120 )
V_115 |= V_121 ;
return V_115 ;
}
static T_4 F_38 ( struct V_1 * V_2 , T_4 V_112 )
{
F_39 ( V_112 & 0xFFFFFF0000000FFFULL ) ;
return V_112 ;
}
static void F_40 ( struct V_1 * V_2 ,
bool V_114 )
{
V_6 V_13 ;
V_13 = F_6 ( V_122 ) ;
V_13 = F_9 ( V_13 , V_123 ,
V_124 , V_114 ) ;
V_13 = F_9 ( V_13 , V_123 ,
V_125 , V_114 ) ;
V_13 = F_9 ( V_13 , V_123 ,
V_126 , V_114 ) ;
V_13 = F_9 ( V_13 , V_123 ,
V_127 , V_114 ) ;
V_13 = F_9 ( V_13 , V_123 ,
V_128 , V_114 ) ;
V_13 = F_9 ( V_13 , V_123 ,
V_129 , V_114 ) ;
F_8 ( V_122 , V_13 ) ;
}
static void F_41 ( struct V_1 * V_2 , bool V_130 )
{
T_3 V_13 ;
if ( V_130 && ! V_2 -> V_25 . V_131 ) {
F_24 ( V_2 -> V_27 , L_10 ) ;
V_2 -> V_25 . V_131 = true ;
}
V_13 = F_6 ( V_132 ) ;
V_13 = F_9 ( V_13 , V_133 ,
V_134 , V_130 ) ;
V_13 = F_9 ( V_13 , V_133 ,
V_135 , V_130 ) ;
V_13 = F_9 ( V_13 , V_133 ,
V_136 , V_130 ) ;
V_13 = F_9 ( V_13 , V_133 ,
V_137 , V_130 ) ;
V_13 = F_9 ( V_13 , V_133 ,
V_138 , V_130 ) ;
V_13 = F_9 ( V_13 , V_133 ,
V_139 , V_130 ) ;
V_13 = F_9 ( V_13 , V_133 ,
V_140 , V_130 ) ;
F_8 ( V_132 , V_13 ) ;
if ( V_130 ) {
T_3 V_141 = V_142 >> V_143 ;
T_3 V_144 = V_2 -> V_145 . V_146 ;
F_8 ( V_147 , V_141 ) ;
F_8 ( V_148 , V_141 ) ;
F_8 ( V_149 , V_141 ) ;
F_8 ( V_150 , V_141 ) ;
F_8 ( V_151 , V_144 ) ;
F_8 ( V_152 , V_144 ) ;
F_8 ( V_153 , V_144 ) ;
F_8 ( V_154 , V_144 ) ;
} else {
F_8 ( V_147 , 0xfffffff ) ;
F_8 ( V_148 , 0xfffffff ) ;
F_8 ( V_149 , 0xfffffff ) ;
F_8 ( V_150 , 0xfffffff ) ;
F_8 ( V_151 , 0x0 ) ;
F_8 ( V_152 , 0x0 ) ;
F_8 ( V_153 , 0x0 ) ;
F_8 ( V_154 , 0x0 ) ;
}
}
static int F_42 ( struct V_1 * V_2 )
{
int V_155 , V_34 ;
V_6 V_13 , V_156 ;
if ( V_2 -> V_157 . V_158 == NULL ) {
F_43 ( V_2 -> V_27 , L_11 ) ;
return - V_37 ;
}
V_155 = F_44 ( V_2 ) ;
if ( V_155 )
return V_155 ;
V_13 = F_6 ( V_159 ) ;
V_13 = F_9 ( V_13 , V_160 , V_161 , 1 ) ;
V_13 = F_9 ( V_13 , V_160 , V_162 , 1 ) ;
V_13 = F_9 ( V_13 , V_160 , V_163 , 3 ) ;
V_13 = F_9 ( V_13 , V_160 , V_164 , 1 ) ;
V_13 = F_9 ( V_13 , V_160 , V_165 , 0 ) ;
F_8 ( V_159 , V_13 ) ;
V_13 = F_6 ( V_166 ) ;
V_13 = F_9 ( V_13 , V_167 , V_168 , 1 ) ;
V_13 = F_9 ( V_13 , V_167 , V_169 , 1 ) ;
V_13 = F_9 ( V_13 , V_167 , V_170 , 1 ) ;
V_13 = F_9 ( V_13 , V_167 , V_171 , 1 ) ;
V_13 = F_9 ( V_13 , V_167 , V_172 , 7 ) ;
V_13 = F_9 ( V_13 , V_167 , V_173 , 1 ) ;
V_13 = F_9 ( V_13 , V_167 , V_174 , 1 ) ;
F_8 ( V_166 , V_13 ) ;
V_13 = F_9 ( 0 , V_175 , V_176 , 1 ) ;
V_13 = F_9 ( V_13 , V_175 , V_177 , 1 ) ;
F_8 ( V_178 , V_13 ) ;
V_156 = V_2 -> V_145 . V_179 ;
V_13 = F_6 ( V_180 ) ;
V_13 = F_9 ( V_13 , V_181 , V_182 , 1 ) ;
V_13 = F_9 ( V_13 , V_181 , V_183 , V_156 ) ;
V_13 = F_9 ( V_13 , V_181 , V_184 , V_156 ) ;
F_8 ( V_180 , V_13 ) ;
F_8 ( V_185 , V_2 -> V_25 . V_186 >> 12 ) ;
F_8 ( V_187 , V_2 -> V_25 . V_188 >> 12 ) ;
F_8 ( V_189 , V_2 -> V_157 . V_190 >> 12 ) ;
F_8 ( V_191 ,
( V_6 ) ( V_2 -> V_192 . V_112 >> 12 ) ) ;
F_8 ( V_193 , 0 ) ;
V_13 = F_6 ( V_194 ) ;
V_13 = F_9 ( V_13 , V_195 , V_196 , 1 ) ;
V_13 = F_9 ( V_13 , V_195 , V_197 , 0 ) ;
V_13 = F_9 ( V_13 , V_195 , V_124 , 1 ) ;
F_8 ( V_194 , V_13 ) ;
F_8 ( 0x575 , 0 ) ;
F_8 ( 0x576 , 0 ) ;
F_8 ( 0x577 , 0 ) ;
F_8 ( V_198 , 0 ) ;
F_8 ( V_199 , V_2 -> V_145 . V_146 - 1 ) ;
for ( V_34 = 1 ; V_34 < 16 ; V_34 ++ ) {
if ( V_34 < 8 )
F_8 ( V_189 + V_34 ,
V_2 -> V_157 . V_190 >> 12 ) ;
else
F_8 ( V_200 + V_34 - 8 ,
V_2 -> V_157 . V_190 >> 12 ) ;
}
F_8 ( V_201 ,
( V_6 ) ( V_2 -> V_192 . V_112 >> 12 ) ) ;
F_8 ( V_202 , 4 ) ;
V_13 = F_6 ( V_122 ) ;
V_13 = F_9 ( V_13 , V_123 , V_196 , 1 ) ;
V_13 = F_9 ( V_13 , V_123 , V_197 , 1 ) ;
V_13 = F_9 ( V_13 , V_123 , V_203 ,
V_2 -> V_145 . V_204 - 9 ) ;
F_8 ( V_122 , V_13 ) ;
if ( V_205 == V_206 )
F_40 ( V_2 , false ) ;
else
F_40 ( V_2 , true ) ;
if ( V_2 -> V_3 == V_22 ) {
V_13 = F_6 ( V_207 ) ;
V_13 &= ~ V_208 ;
F_8 ( V_207 , V_13 ) ;
}
F_34 ( V_2 , 0 ) ;
F_45 ( L_12 ,
( unsigned ) ( V_2 -> V_25 . V_106 >> 20 ) ,
( unsigned long long ) V_2 -> V_157 . V_190 ) ;
V_2 -> V_157 . V_209 = true ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_155 ;
if ( V_2 -> V_157 . V_158 ) {
F_47 ( 1 , L_13 ) ;
return 0 ;
}
V_155 = F_48 ( V_2 ) ;
if ( V_155 )
return V_155 ;
V_2 -> V_157 . V_210 = V_2 -> V_157 . V_211 * 8 ;
V_2 -> V_157 . V_212 = 0 ;
return F_49 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
V_6 V_13 ;
F_8 ( V_194 , 0 ) ;
F_8 ( V_122 , 0 ) ;
V_13 = F_6 ( V_159 ) ;
V_13 = F_9 ( V_13 , V_160 , V_161 , 0 ) ;
V_13 = F_9 ( V_13 , V_160 , V_162 , 0 ) ;
V_13 = F_9 ( V_13 , V_160 , V_164 , 0 ) ;
F_8 ( V_159 , V_13 ) ;
V_13 = F_6 ( V_166 ) ;
V_13 = F_9 ( V_13 , V_167 , V_168 , 0 ) ;
F_8 ( V_166 , V_13 ) ;
F_8 ( V_178 , 0 ) ;
F_51 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
V_6 V_213 , V_6 V_112 , V_6 V_214 )
{
V_6 V_215 ;
V_6 V_107 = F_7 ( V_213 , V_216 , V_217 ) ;
V_6 V_218 = F_7 ( V_213 , V_216 ,
V_219 ) ;
char V_220 [ 5 ] = { V_214 >> 24 , ( V_214 >> 16 ) & 0xff ,
( V_214 >> 8 ) & 0xff , V_214 & 0xff , 0 } ;
V_215 = F_7 ( V_213 , V_216 ,
V_221 ) ;
F_43 ( V_2 -> V_27 , L_14 ,
V_218 , V_107 , V_112 ,
F_7 ( V_213 , V_216 ,
V_222 ) ?
L_15 : L_16 , V_220 , V_214 , V_215 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
bool V_130 )
{
int V_34 ;
V_6 V_223 , V_38 ;
for ( V_34 = 0 ; V_34 < F_3 ( V_224 ) ; V_34 ++ ) {
V_223 = V_38 = F_6 ( V_224 [ V_34 ] ) ;
if ( V_130 && ( V_2 -> V_225 & V_226 ) )
V_38 |= V_227 [ V_34 ] ;
else
V_38 &= ~ V_227 [ V_34 ] ;
if ( V_38 != V_223 )
F_8 ( V_224 [ V_34 ] , V_38 ) ;
}
}
static void F_57 ( struct V_1 * V_2 ,
bool V_130 )
{
int V_34 ;
V_6 V_223 , V_38 ;
for ( V_34 = 0 ; V_34 < F_3 ( V_224 ) ; V_34 ++ ) {
V_223 = V_38 = F_6 ( V_224 [ V_34 ] ) ;
if ( V_130 && ( V_2 -> V_225 & V_228 ) )
V_38 |= V_229 [ V_34 ] ;
else
V_38 &= ~ V_229 [ V_34 ] ;
if ( V_38 != V_223 )
F_8 ( V_224 [ V_34 ] , V_38 ) ;
}
}
static void F_58 ( struct V_1 * V_2 ,
bool V_130 )
{
V_6 V_223 , V_38 ;
V_223 = V_38 = F_59 ( V_230 ) ;
if ( V_130 && ( V_2 -> V_225 & V_231 ) ) {
V_38 = F_9 ( V_38 , V_232 , V_233 , 1 ) ;
V_38 = F_9 ( V_38 , V_232 , V_234 , 1 ) ;
V_38 = F_9 ( V_38 , V_232 , V_235 , 1 ) ;
V_38 = F_9 ( V_38 , V_232 , V_236 , 1 ) ;
} else {
V_38 = F_9 ( V_38 , V_232 , V_233 , 0 ) ;
V_38 = F_9 ( V_38 , V_232 , V_234 , 0 ) ;
V_38 = F_9 ( V_38 , V_232 , V_235 , 0 ) ;
V_38 = F_9 ( V_38 , V_232 , V_236 , 0 ) ;
}
if ( V_223 != V_38 )
F_60 ( V_230 , V_38 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
bool V_130 )
{
V_6 V_223 , V_38 ;
V_223 = V_38 = F_6 ( V_87 ) ;
if ( V_130 && ( V_2 -> V_225 & V_237 ) )
V_38 = F_9 ( V_38 , V_238 , V_239 , 0 ) ;
else
V_38 = F_9 ( V_38 , V_238 , V_239 , 1 ) ;
if ( V_223 != V_38 )
F_8 ( V_87 , V_38 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
bool V_130 )
{
V_6 V_223 , V_38 ;
V_223 = V_38 = F_6 ( V_240 ) ;
if ( V_130 && ( V_2 -> V_225 & V_241 ) )
V_38 = F_9 ( V_38 , V_242 , V_243 , 1 ) ;
else
V_38 = F_9 ( V_38 , V_242 , V_243 , 0 ) ;
if ( V_223 != V_38 )
F_8 ( V_240 , V_38 ) ;
}
static int F_63 ( int V_244 )
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
static int F_64 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
V_2 -> V_25 . V_261 = 0x2000000000000000ULL ;
V_2 -> V_25 . V_262 =
V_2 -> V_25 . V_261 + ( 4ULL << 30 ) - 1 ;
V_2 -> V_25 . V_263 =
V_2 -> V_25 . V_262 + 1 ;
V_2 -> V_25 . V_264 =
V_2 -> V_25 . V_263 + ( 4ULL << 30 ) - 1 ;
return 0 ;
}
static int F_67 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
if ( V_205 != V_206 )
return F_68 ( V_2 , & V_2 -> V_25 . V_265 , 0 ) ;
else
return 0 ;
}
static int F_69 ( void * V_260 )
{
int V_155 ;
int V_266 ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
if ( V_2 -> V_101 & V_102 ) {
V_2 -> V_25 . V_267 = V_259 ;
} else {
V_6 V_13 = F_6 ( V_268 ) ;
V_13 &= V_269 ;
V_2 -> V_25 . V_267 = F_63 ( V_13 ) ;
}
V_155 = F_70 ( V_2 , V_270 , 146 , & V_2 -> V_25 . V_265 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_70 ( V_2 , V_270 , 147 , & V_2 -> V_25 . V_265 ) ;
if ( V_155 )
return V_155 ;
F_71 ( V_2 , 64 , 4 ) ;
V_2 -> V_145 . V_146 = V_2 -> V_145 . V_271 << 18 ;
V_2 -> V_25 . V_272 = 0xffffffffffULL ;
V_2 -> V_25 . V_273 = 256 * 1024 ;
V_2 -> V_274 = false ;
V_266 = V_2 -> V_274 ? 32 : 40 ;
V_155 = F_72 ( V_2 -> V_98 , F_73 ( V_266 ) ) ;
if ( V_155 ) {
V_2 -> V_274 = true ;
V_266 = 32 ;
F_74 ( L_17 ) ;
}
V_155 = F_75 ( V_2 -> V_98 , F_73 ( V_266 ) ) ;
if ( V_155 ) {
F_75 ( V_2 -> V_98 , F_73 ( 32 ) ) ;
F_74 ( L_18 ) ;
}
V_155 = F_12 ( V_2 ) ;
if ( V_155 ) {
F_76 ( L_19 ) ;
return V_155 ;
}
V_155 = F_28 ( V_2 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_77 ( V_2 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_46 ( V_2 ) ;
if ( V_155 )
return V_155 ;
V_2 -> V_145 . V_275 [ 0 ] . V_276 = V_277 ;
V_2 -> V_145 . V_278 = 1 ;
F_78 ( V_2 ) ;
if ( V_2 -> V_101 & V_102 ) {
T_2 V_13 = F_6 ( V_103 ) ;
V_13 <<= 22 ;
V_2 -> V_145 . V_279 = V_13 ;
} else {
V_2 -> V_145 . V_279 = 0 ;
}
return 0 ;
}
static int F_79 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_80 ( V_2 ) ;
F_52 ( V_2 ) ;
F_81 ( V_2 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static int F_83 ( void * V_260 )
{
int V_155 ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_1 ( V_2 ) ;
F_27 ( V_2 ) ;
if ( ! ( V_2 -> V_101 & V_102 ) ) {
V_155 = F_19 ( V_2 ) ;
if ( V_155 ) {
F_76 ( L_20 ) ;
return V_155 ;
}
}
V_155 = F_42 ( V_2 ) ;
if ( V_155 )
return V_155 ;
return V_155 ;
}
static int F_84 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_85 ( V_2 , & V_2 -> V_25 . V_265 , 0 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static int F_86 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_87 ( void * V_260 )
{
int V_155 ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
V_155 = F_83 ( V_2 ) ;
if ( V_155 )
return V_155 ;
F_88 ( V_2 ) ;
return 0 ;
}
static bool F_89 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
V_6 V_13 = F_6 ( V_280 ) ;
if ( V_13 & ( V_281 | V_282 |
V_283 | V_284 | V_285 ) )
return false ;
return true ;
}
static int F_5 ( void * V_260 )
{
unsigned V_34 ;
V_6 V_13 ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_52 ; V_34 ++ ) {
V_13 = F_6 ( V_280 ) & ( V_281 |
V_282 |
V_283 |
V_284 |
V_285 ) ;
if ( ! V_13 )
return 0 ;
F_10 ( 1 ) ;
}
return - V_286 ;
}
static int F_90 ( void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
V_6 V_287 = 0 ;
V_6 V_13 = F_6 ( V_280 ) ;
if ( V_13 & V_285 )
V_287 = F_9 ( V_287 ,
V_288 , V_289 , 1 ) ;
if ( V_13 & ( V_281 | V_282 |
V_283 | V_284 ) ) {
if ( ! ( V_2 -> V_101 & V_102 ) )
V_287 = F_9 ( V_287 ,
V_288 , V_290 , 1 ) ;
}
if ( V_287 ) {
F_4 ( V_2 ) ;
if ( F_5 ( ( void * ) V_2 ) ) {
F_24 ( V_2 -> V_27 , L_21 ) ;
}
V_13 = F_6 ( V_291 ) ;
V_13 |= V_287 ;
F_91 ( V_2 -> V_27 , L_22 , V_13 ) ;
F_8 ( V_291 , V_13 ) ;
V_13 = F_6 ( V_291 ) ;
F_10 ( 50 ) ;
V_13 &= ~ V_287 ;
F_8 ( V_291 , V_13 ) ;
V_13 = F_6 ( V_291 ) ;
F_10 ( 50 ) ;
F_11 ( V_2 ) ;
F_10 ( 50 ) ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
unsigned type ,
enum V_294 V_295 )
{
V_6 V_13 ;
V_6 V_296 = ( V_297 |
V_298 |
V_299 |
V_300 |
V_301 |
V_302 ) ;
switch ( V_295 ) {
case V_303 :
V_13 = F_6 ( V_194 ) ;
V_13 &= ~ V_296 ;
F_8 ( V_194 , V_13 ) ;
V_13 = F_6 ( V_122 ) ;
V_13 &= ~ V_296 ;
F_8 ( V_122 , V_13 ) ;
break;
case V_304 :
V_13 = F_6 ( V_194 ) ;
V_13 |= V_296 ;
F_8 ( V_194 , V_13 ) ;
V_13 = F_6 ( V_122 ) ;
V_13 |= V_296 ;
F_8 ( V_122 , V_13 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_292 * V_305 ,
struct V_306 * V_307 )
{
V_6 V_112 , V_213 , V_214 ;
V_112 = F_6 ( V_308 ) ;
V_213 = F_6 ( V_309 ) ;
V_214 = F_6 ( V_310 ) ;
F_94 ( V_202 , 1 , ~ 1 ) ;
if ( ! V_112 && ! V_213 )
return 0 ;
if ( V_205 == V_311 )
F_40 ( V_2 , false ) ;
if ( F_95 () ) {
F_43 ( V_2 -> V_27 , L_23 ,
V_307 -> V_312 , V_307 -> V_313 [ 0 ] ) ;
F_43 ( V_2 -> V_27 , L_24 ,
V_112 ) ;
F_43 ( V_2 -> V_27 , L_25 ,
V_213 ) ;
F_55 ( V_2 , V_213 , V_112 , V_214 ) ;
}
return 0 ;
}
static int F_96 ( void * V_260 ,
enum V_314 V_295 )
{
bool V_315 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
if ( V_295 == V_316 )
V_315 = true ;
if ( ! ( V_2 -> V_101 & V_102 ) ) {
F_57 ( V_2 , V_315 ) ;
F_56 ( V_2 , V_315 ) ;
}
F_58 ( V_2 , V_315 ) ;
F_61 ( V_2 , V_315 ) ;
F_62 ( V_2 , V_315 ) ;
return 0 ;
}
static int F_97 ( void * V_260 ,
enum V_317 V_295 )
{
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_157 . V_318 == NULL )
V_2 -> V_157 . V_318 = & V_319 ;
}
static void F_66 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_265 . V_320 = 1 ;
V_2 -> V_25 . V_265 . V_321 = & V_322 ;
}
