static int T_1 F_1 ( void )
{
int error ;
V_1 = F_2 ( 2 ) ;
if ( ! V_1 )
return - V_2 ;
V_1 -> V_3 = V_4 ;
V_1 -> V_5 = L_1 ;
V_1 -> V_6 = L_2 ;
V_1 -> V_7 = V_8 ;
V_1 -> V_9 = V_10 ;
V_1 -> type = V_11 ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_14 . V_16 =
V_17 | V_18 | V_19 | V_20 | V_21 ;
V_1 -> V_14 . V_22 = 9600 ;
V_1 -> V_14 . V_23 = 9600 ;
V_1 -> V_24 = V_25 ;
F_3 ( V_1 , & V_26 ) ;
if ( ( error = F_4 ( V_1 ) ) ) {
F_5 ( V_27 L_3 ,
error ) ;
F_6 ( V_1 ) ;
return 1 ;
}
return 0 ;
}
static void T_1 F_7 ( void )
{
struct V_28 * V_29 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < 2 ; V_30 ++ ) {
V_29 = V_31 + V_30 ;
F_8 ( & V_29 -> V_32 . V_29 ) ;
V_29 -> V_32 . V_29 . V_33 = & V_34 ;
V_29 -> V_32 . V_35 = V_36 ;
V_29 -> V_32 . V_37 = V_38 / 2 ;
V_29 -> V_32 . V_39 = 30 * V_38 ;
V_29 -> V_32 . V_40 = & V_41 ;
#ifdef F_9
V_29 -> V_32 . V_42 = V_43 ;
#endif
F_10 ( & V_29 -> V_32 . V_29 . V_44 ) ;
F_10 ( & V_29 -> V_32 . V_29 . V_45 ) ;
}
}
static int T_1 F_11 ( void )
{
struct V_28 * V_29 ;
int error ;
F_5 ( V_46 L_4 ) ;
V_29 = & V_31 [ 0 ] ;
V_29 -> V_47 = V_48 ;
V_29 -> V_49 = ( volatile unsigned char * ) V_50 ;
V_29 -> V_51 = V_29 -> V_49 + 1 ;
V_29 -> V_52 = & V_31 [ 0 ] ;
V_29 -> V_53 = & V_31 [ 1 ] ;
error = F_12 ( V_54 , V_55 , V_56 ,
L_5 , V_29 ) ;
if ( error )
goto V_57;
error = F_12 ( V_58 , V_59 , V_56 ,
L_6 , V_29 ) ;
if ( error )
goto V_60;
error = F_12 ( V_61 , V_62 , V_56 ,
L_7 , V_29 ) ;
if ( error )
goto V_63;
error = F_12 ( V_64 , V_65 ,
V_56 , L_8 , V_29 ) ;
if ( error )
goto V_66;
{
F_13 ( V_29 ) ;
F_14 ( V_67 , 0 ) ;
F_14 ( V_68 , V_69 ) ;
F_14 ( V_70 , V_71 ) ;
F_15 ( V_70 , 0xff , V_72 ) ;
}
V_29 = & V_31 [ 1 ] ;
V_29 -> V_47 = V_73 ;
V_29 -> V_49 = ( volatile unsigned char * ) V_74 ;
V_29 -> V_51 = V_29 -> V_49 + 1 ;
V_29 -> V_52 = & V_31 [ 0 ] ;
V_29 -> V_53 = & V_31 [ 1 ] ;
error = F_12 ( V_75 , V_55 , V_56 ,
L_9 , V_29 ) ;
if ( error )
goto V_76;
error = F_12 ( V_77 , V_59 , V_56 ,
L_10 , V_29 ) ;
if ( error )
goto V_78;
error = F_12 ( V_79 , V_62 , V_56 ,
L_11 , V_29 ) ;
if ( error )
goto V_80;
error = F_12 ( V_81 , V_65 ,
V_56 , L_12 , V_29 ) ;
if ( error )
goto V_82;
{
F_13 ( V_29 ) ;
F_14 ( V_67 , 0 ) ;
}
V_83 -> V_84 = V_85 | V_86 ;
F_7 () ;
F_1 () ;
return 0 ;
V_82:
F_16 ( V_79 , V_29 ) ;
V_80:
F_16 ( V_77 , V_29 ) ;
V_78:
F_16 ( V_75 , V_29 ) ;
V_76:
F_16 ( V_64 , V_29 ) ;
V_66:
F_16 ( V_61 , V_29 ) ;
V_63:
F_16 ( V_58 , V_29 ) ;
V_60:
F_16 ( V_54 , V_29 ) ;
V_57:
return error ;
}
static int T_1 F_17 ( void )
{
struct V_28 * V_29 ;
int error ;
if ( ! ( V_87 & V_88 ) )
return ( - V_89 ) ;
F_5 ( V_46 L_13 ) ;
V_29 = & V_31 [ 0 ] ;
V_29 -> V_47 = V_48 ;
V_29 -> V_49 = ( volatile unsigned char * ) V_90 ;
V_29 -> V_51 = V_29 -> V_49 + 2 ;
V_29 -> V_52 = & V_31 [ 0 ] ;
V_29 -> V_53 = & V_31 [ 1 ] ;
error = F_12 ( V_91 , V_55 , V_56 ,
L_5 , V_29 ) ;
if ( error )
goto V_57;
error = F_12 ( V_92 , V_59 , V_56 ,
L_6 , V_29 ) ;
if ( error )
goto V_60;
error = F_12 ( V_93 , V_62 , V_56 ,
L_7 , V_29 ) ;
if ( error )
goto V_63;
error = F_12 ( V_94 , V_65 ,
V_56 , L_8 , V_29 ) ;
if ( error )
goto V_66;
{
F_13 ( V_29 ) ;
F_14 ( V_67 , 0 ) ;
F_14 ( V_68 , V_95 ) ;
F_14 ( V_70 , V_71 ) ;
F_15 ( V_70 , 0xff , V_72 ) ;
}
V_29 = & V_31 [ 1 ] ;
V_29 -> V_47 = V_73 ;
V_29 -> V_49 = ( volatile unsigned char * ) V_96 ;
V_29 -> V_51 = V_29 -> V_49 + 2 ;
V_29 -> V_52 = & V_31 [ 0 ] ;
V_29 -> V_53 = & V_31 [ 1 ] ;
error = F_12 ( V_97 , V_55 , V_56 ,
L_9 , V_29 ) ;
if ( error )
goto V_76;
error = F_12 ( V_98 , V_59 , V_56 ,
L_10 , V_29 ) ;
if ( error )
goto V_78;
error = F_12 ( V_99 , V_62 , V_56 ,
L_11 , V_29 ) ;
if ( error )
goto V_80;
error = F_12 ( V_100 , V_65 ,
V_56 , L_12 , V_29 ) ;
if ( error )
goto V_82;
{
F_13 ( V_29 ) ;
F_14 ( V_67 , 0 ) ;
}
* ( volatile char * ) 0xfff4201d = 0x14 ;
F_7 () ;
F_1 () ;
return 0 ;
V_82:
F_16 ( V_99 , V_29 ) ;
V_80:
F_16 ( V_98 , V_29 ) ;
V_78:
F_16 ( V_97 , V_29 ) ;
V_76:
F_16 ( V_94 , V_29 ) ;
V_66:
F_16 ( V_93 , V_29 ) ;
V_63:
F_16 ( V_92 , V_29 ) ;
V_60:
F_16 ( V_91 , V_29 ) ;
V_57:
return error ;
}
static int T_1 F_18 ( void )
{
struct V_28 * V_29 ;
int error ;
F_5 ( V_46 L_14 ) ;
V_29 = & V_31 [ 0 ] ;
V_29 -> V_47 = V_48 ;
V_29 -> V_49 = ( volatile unsigned char * ) V_101 ;
V_29 -> V_51 = V_29 -> V_49 + 4 ;
V_29 -> V_52 = & V_31 [ 0 ] ;
V_29 -> V_53 = & V_31 [ 1 ] ;
error = F_12 ( V_102 , V_55 , V_56 ,
L_5 , V_29 ) ;
if ( error )
goto V_57;
error = F_12 ( V_103 , V_59 , V_56 ,
L_6 , V_29 ) ;
if ( error )
goto V_60;
error = F_12 ( V_104 , V_62 , V_56 ,
L_7 , V_29 ) ;
if ( error )
goto V_63;
error = F_12 ( V_105 , V_65 ,
V_56 , L_8 , V_29 ) ;
if ( error )
goto V_66;
{
F_13 ( V_29 ) ;
F_14 ( V_67 , 0 ) ;
F_14 ( V_68 , V_106 ) ;
F_14 ( V_70 , V_71 ) ;
F_15 ( V_70 , 0xff , V_72 ) ;
}
V_29 = & V_31 [ 1 ] ;
V_29 -> V_47 = V_73 ;
V_29 -> V_49 = ( volatile unsigned char * ) V_107 ;
V_29 -> V_51 = V_29 -> V_49 + 4 ;
V_29 -> V_52 = & V_31 [ 0 ] ;
V_29 -> V_53 = & V_31 [ 1 ] ;
error = F_12 ( V_108 , V_55 , V_56 ,
L_9 , V_29 ) ;
if ( error )
goto V_76;
error = F_12 ( V_109 , V_59 , V_56 ,
L_10 , V_29 ) ;
if ( error )
goto V_78;
error = F_12 ( V_110 , V_62 , V_56 ,
L_11 , V_29 ) ;
if ( error )
goto V_80;
error = F_12 ( V_111 , V_65 ,
V_56 , L_12 , V_29 ) ;
if ( error )
goto V_82;
{
F_13 ( V_29 ) ;
F_14 ( V_67 , 0 ) ;
}
F_7 () ;
F_1 () ;
return 0 ;
V_57:
F_16 ( V_103 , V_29 ) ;
V_60:
F_16 ( V_104 , V_29 ) ;
V_63:
F_16 ( V_105 , V_29 ) ;
V_66:
F_16 ( V_108 , V_29 ) ;
V_76:
F_16 ( V_109 , V_29 ) ;
V_78:
F_16 ( V_110 , V_29 ) ;
V_80:
F_16 ( V_111 , V_29 ) ;
V_82:
return error ;
}
static int T_1 F_19 ( void )
{
int V_112 = - V_89 ;
#ifdef F_20
if ( V_113 )
V_112 = F_11 () ;
#endif
#ifdef F_21
if ( V_114 )
V_112 = F_17 () ;
#endif
#ifdef F_22
if ( V_115 )
V_112 = F_18 () ;
#endif
return V_112 ;
}
static T_2 V_62 ( int V_116 , void * V_117 )
{
unsigned char V_118 ;
struct V_28 * V_29 = V_117 ;
struct V_119 * V_120 = V_29 -> V_32 . V_29 . V_120 ;
F_13 ( V_29 ) ;
V_118 = F_23 ( V_121 ) ;
if ( ! V_120 ) {
F_5 ( V_122 L_15 ) ;
F_24 ( V_123 , V_124 ) ;
return V_125 ;
}
F_25 ( V_120 , V_118 , 0 ) ;
if ( F_26 ( V_126 ) &
( V_29 -> V_47 == V_48 ? V_127 : V_128 ) ) {
V_65 ( V_116 , V_117 ) ;
return V_125 ;
}
F_24 ( V_123 , V_124 ) ;
F_27 ( V_120 ) ;
return V_125 ;
}
static T_2 V_65 ( int V_116 , void * V_117 )
{
struct V_28 * V_29 = V_117 ;
struct V_119 * V_120 = V_29 -> V_32 . V_29 . V_120 ;
unsigned char V_129 , V_118 , V_130 ;
int V_131 = V_29 -> V_47 == V_48 ?
V_127 : V_128 ;
F_13 ( V_29 ) ;
if ( ! V_120 ) {
F_5 ( V_122 L_16 ) ;
F_14 ( V_123 , V_132 ) ;
F_24 ( V_123 , V_124 ) ;
return V_125 ;
}
do {
V_129 = F_26 ( V_133 ) ;
V_118 = F_23 ( V_121 ) ;
if ( V_129 & V_134 )
V_130 = V_135 ;
else if ( V_129 & V_136 )
V_130 = V_137 ;
else if ( V_129 & V_138 )
V_130 = V_139 ;
else
V_130 = 0 ;
F_25 ( V_120 , V_118 , V_130 ) ;
if ( V_130 )
F_14 ( V_123 , V_132 ) ;
} while( F_26 ( V_126 ) & V_131 );
F_24 ( V_123 , V_124 ) ;
F_27 ( V_120 ) ;
return V_125 ;
}
static T_2 V_55 ( int V_116 , void * V_117 )
{
struct V_28 * V_29 = V_117 ;
F_13 ( V_29 ) ;
if ( ! V_29 -> V_32 . V_29 . V_120 ) {
F_5 ( V_122 L_17 ) ;
F_15 ( V_67 , ~ V_140 , 0 ) ;
F_14 ( V_123 , V_141 ) ;
F_24 ( V_123 , V_124 ) ;
return V_125 ;
}
while ( ( F_23 ( V_142 ) & V_143 ) ) {
if ( V_29 -> V_144 ) {
F_14 ( V_145 , V_29 -> V_144 ) ;
V_29 -> V_144 = 0 ;
}
else if ( ( V_29 -> V_32 . V_146 <= 0 ) ||
V_29 -> V_32 . V_29 . V_120 -> V_147 ||
V_29 -> V_32 . V_29 . V_120 -> V_148 )
break;
else {
F_14 ( V_145 , V_29 -> V_32 . V_149 [ V_29 -> V_32 . V_150 ++ ] ) ;
V_29 -> V_32 . V_150 = V_29 -> V_32 . V_150 & ( V_151 - 1 ) ;
if ( -- V_29 -> V_32 . V_146 <= 0 )
break;
}
}
if ( ( V_29 -> V_32 . V_146 <= 0 ) || V_29 -> V_32 . V_29 . V_120 -> V_147 ||
V_29 -> V_32 . V_29 . V_120 -> V_148 ) {
F_15 ( V_67 , ~ V_140 , 0 ) ;
F_14 ( V_123 , V_141 ) ;
V_29 -> V_32 . V_29 . V_24 &= ~ V_152 ;
}
if ( V_29 -> V_32 . V_29 . V_120 && V_29 -> V_32 . V_146 <= V_29 -> V_32 . V_153 )
F_28 ( V_29 -> V_32 . V_29 . V_120 ) ;
F_24 ( V_123 , V_124 ) ;
return V_125 ;
}
static T_2 V_59 ( int V_116 , void * V_117 )
{
struct V_28 * V_29 = V_117 ;
unsigned V_47 = V_29 -> V_47 ;
unsigned char V_154 , V_155 , V_156 ;
F_13 ( V_29 ) ;
V_154 = V_157 [ V_47 ] ;
V_155 = V_157 [ V_47 ] = F_23 ( V_142 ) ;
V_156 = V_154 ^ V_155 ;
if ( V_156 & V_158 ) {
V_29 -> V_159 = ! ! ( V_155 & V_158 ) ;
if ( ! ( V_29 -> V_32 . V_29 . V_24 & V_160 ) )
;
else if ( V_29 -> V_159 ) {
F_29 ( & V_29 -> V_32 . V_29 . V_44 ) ;
}
else {
if ( V_29 -> V_32 . V_29 . V_120 )
F_30 ( V_29 -> V_32 . V_29 . V_120 ) ;
}
}
F_14 ( V_123 , V_161 ) ;
F_24 ( V_123 , V_124 ) ;
return V_125 ;
}
static void F_31 ( void * V_162 )
{
struct V_28 * V_29 = V_162 ;
unsigned long V_24 ;
F_13 ( V_29 ) ;
F_32 ( V_24 ) ;
F_15 ( V_67 , ~ V_140 , 0 ) ;
V_29 -> V_32 . V_29 . V_24 &= ~ V_152 ;
F_33 ( V_24 ) ;
}
static void F_34 ( void * V_162 )
{
struct V_28 * V_29 = V_162 ;
unsigned long V_24 ;
F_13 ( V_29 ) ;
F_32 ( V_24 ) ;
F_15 ( V_67 , 0xff , V_140 ) ;
V_55 ( 0 , V_29 ) ;
F_33 ( V_24 ) ;
}
static void F_35 ( void * V_162 )
{
struct V_28 * V_29 = V_162 ;
unsigned long V_24 ;
F_13 ( V_29 ) ;
F_32 ( V_24 ) ;
F_15 ( V_67 ,
~ ( V_163 | V_164 | V_165 ) , 0 ) ;
F_33 ( V_24 ) ;
}
static void F_36 ( void * V_162 )
{
struct V_28 * V_29 = V_162 ;
unsigned long V_24 ;
F_13 ( V_29 ) ;
F_32 ( V_24 ) ;
F_15 ( V_67 , 0xff ,
V_165 | V_164 | V_166 ) ;
F_33 ( V_24 ) ;
}
static int F_37 ( struct V_167 * V_29 )
{
struct V_28 * V_168 = F_38 ( V_29 , struct V_28 , V_32 . V_29 ) ;
unsigned V_47 = V_168 -> V_47 ;
return ! ! ( V_157 [ V_47 ] & V_158 ) ;
}
static void F_39 ( void * V_162 )
{
struct V_28 * V_29 = V_162 ;
V_29 -> V_32 . V_29 . V_24 &= ~ V_169 ;
if ( V_29 -> V_32 . V_29 . V_120 && ( V_29 -> V_32 . V_29 . V_120 -> V_170 -> V_16 & V_20 ) ) {
F_40 ( V_29 , 0 , 0 ) ;
}
}
static int F_41 ( void * V_162 )
{
static int V_171 [ 4 ] = { 0 , 2 , 1 , 3 } ;
unsigned V_172 , V_173 , V_174 , V_47 , V_175 = 0 ;
unsigned long V_24 ;
struct V_28 * V_29 = V_162 ;
F_13 ( V_29 ) ;
if ( ! V_29 -> V_32 . V_29 . V_120 || ! V_29 -> V_32 . V_29 . V_120 -> V_170 ) return 0 ;
V_47 = V_29 -> V_47 ;
if ( V_47 == V_48 )
return 0 ;
V_172 = V_29 -> V_32 . V_29 . V_120 -> V_170 -> V_16 ;
V_173 = V_29 -> V_32 . V_173 ;
V_174 = ( V_172 & V_176 ) >> 4 ;
if ( V_173 == 0 ) {
F_32 ( V_24 ) ;
F_15 ( V_177 , ~ V_178 , 0 ) ;
F_33 ( V_24 ) ;
return 0 ;
}
else if ( ( V_114 && ( V_173 < 50 || V_173 > 38400 ) ) ||
( V_113 && ( V_173 < 50 || V_173 > 19200 ) ) ||
( V_115 && ( V_173 < 50 || V_173 > 76800 ) ) ) {
F_5 ( V_179 L_18 , V_173 ) ;
return 0 ;
}
if ( V_172 & V_21 )
V_29 -> V_32 . V_29 . V_24 &= ~ V_160 ;
else
V_29 -> V_32 . V_29 . V_24 |= V_160 ;
#ifdef F_20
if ( V_113 )
V_175 = ( V_180 + V_173 / 2 ) / ( 16 * 2 * V_173 ) - 2 ;
#endif
#ifdef F_21
if ( V_114 )
V_175 = ( V_181 + V_173 / 2 ) / ( 16 * 2 * V_173 ) - 2 ;
#endif
#ifdef F_22
if ( V_115 )
V_175 = ( V_182 + V_173 / 2 ) / ( 16 * 2 * V_173 ) - 2 ;
#endif
F_32 ( V_24 ) ;
F_15 ( V_183 , ~ ( V_184 | V_185 ) ,
( V_171 [ V_174 ] << 6 ) |
( ( V_172 & V_186 ) ? V_185 : 0 ) ) ;
F_15 ( V_187 ,
~ ( V_188 | V_189 ) ,
( ( V_172 & V_190
? ( V_172 & V_191 ? V_192 : V_193 )
: V_194 )
| ( V_172 & V_195 ? V_196 : V_197 ) ) ) ;
F_15 ( V_177 , ~ V_198 , V_171 [ V_174 ] << 5 | V_178 ) ;
F_15 ( V_199 , ~ V_200 , 0 ) ;
F_14 ( V_201 , V_175 & 0xff ) ;
F_14 ( V_202 , ( V_175 >> 8 ) & 0xff ) ;
F_15 ( V_199 , 0xff , V_200 ) ;
F_33 ( V_24 ) ;
return 0 ;
}
static int F_42 ( void * V_162 )
{
struct V_28 * V_29 = V_162 ;
F_13 ( V_29 ) ;
return ( F_26 ( V_133 ) & V_203 ) ? 0 : 1 ;
}
static void F_43 ( void * V_162 )
{
F_31 ( V_162 ) ;
F_35 ( V_162 ) ;
}
static void F_44 ( void * V_162 )
{
F_31 ( V_162 ) ;
F_35 ( V_162 ) ;
}
static void F_40 ( struct V_28 * V_29 , int V_204 , int V_205 )
{
unsigned long V_24 ;
unsigned char V_206 ;
F_13 ( V_29 ) ;
F_32 ( V_24 ) ;
V_206 = F_26 ( V_177 ) ;
if ( V_204 >= 0 ) V_206 = V_204 ? ( V_206 | V_178 ) : ( V_206 & ~ V_178 ) ;
if ( V_205 >= 0 ) V_206 = V_205 ? ( V_206 | V_207 ) : ( V_206 & ~ V_207 ) ;
F_14 ( V_177 , V_206 ) ;
F_33 ( V_24 ) ;
}
static void F_45 ( struct V_119 * V_120 , char V_118 )
{
struct V_28 * V_29 = V_120 -> V_208 ;
V_29 -> V_144 = V_118 ;
if ( V_118 )
F_34 ( V_29 ) ;
}
static int F_46 ( struct V_119 * V_120 , struct V_209 * V_210 )
{
int line = V_120 -> V_211 ;
int V_212 ;
struct V_28 * V_29 = & V_31 [ line ] ;
int V_30 , V_47 = V_29 -> V_47 ;
unsigned long V_24 ;
F_13 ( V_29 ) ;
#if F_47 ( F_21 ) || F_47 ( F_20 )
static const struct {
unsigned V_213 , V_214 ;
} V_215 [] = {
{ V_187 , V_194 | V_197 | V_216 } ,
{ V_67 , V_164 | V_217 } ,
{ V_183 , V_218 } ,
{ V_177 , V_219 } ,
{ V_220 , 0 } ,
{ V_221 , V_222 | V_223 } ,
{ V_199 , V_200 | V_224 } ,
{ V_183 , V_225 | V_218 } ,
{ V_177 , V_226 | V_207 | V_178 | V_219 } ,
{ V_227 , V_228 } ,
{ V_123 , V_161 } ,
{ V_123 , V_161 } ,
} ;
#endif
#if F_47 ( F_22 )
static const struct {
unsigned V_213 , V_214 ;
} V_229 [] = {
{ V_187 , V_194 | V_197 | V_216 } ,
{ V_67 , V_164 | V_217 } ,
{ V_183 , V_218 } ,
{ V_177 , V_219 } ,
{ V_220 , 0 } ,
{ V_221 , V_230 | V_222 | V_223 } ,
{ V_199 , V_200 } ,
{ V_183 , V_225 | V_218 } ,
{ V_177 , V_226 | V_207 | V_178 | V_219 } ,
{ V_227 , V_228 } ,
{ V_123 , V_161 } ,
{ V_123 , V_161 } ,
} ;
#endif
if ( ! ( V_29 -> V_32 . V_29 . V_24 & V_231 ) ) {
F_32 ( V_24 ) ;
#if F_47 ( F_20 ) || F_47 ( F_21 )
if ( V_113 || V_114 ) {
for ( V_30 = 0 ; V_30 < F_48 ( V_215 ) ; ++ V_30 )
F_14 ( V_215 [ V_30 ] . V_213 , V_215 [ V_30 ] . V_214 ) ;
}
#endif
#if F_47 ( F_22 )
if ( V_115 ) {
for ( V_30 = 0 ; V_30 < F_48 ( V_229 ) ; ++ V_30 )
F_14 ( V_229 [ V_30 ] . V_213 , V_229 [ V_30 ] . V_214 ) ;
}
#endif
V_157 [ V_47 ] = F_26 ( V_142 ) ;
V_29 -> V_159 = 0 ;
F_40 ( V_29 , 1 , 1 ) ;
F_33 ( V_24 ) ;
}
V_120 -> V_208 = V_29 ;
V_29 -> V_32 . V_29 . V_120 = V_120 ;
V_29 -> V_32 . V_29 . V_232 ++ ;
V_212 = F_49 ( & V_29 -> V_32 ) ;
if ( V_212 ) {
V_29 -> V_32 . V_29 . V_232 -- ;
return V_212 ;
}
V_29 -> V_32 . V_29 . V_24 |= V_169 ;
V_212 = F_50 ( V_29 , V_210 ) ;
if ( V_212 ) {
V_29 -> V_32 . V_29 . V_232 -- ;
return V_212 ;
}
V_29 -> V_159 = F_51 ( & V_29 -> V_32 . V_29 ) ;
F_36 ( V_29 ) ;
return 0 ;
}
static void F_52 ( struct V_119 * V_120 )
{
struct V_28 * V_29 = V_120 -> V_208 ;
unsigned long V_24 ;
F_13 ( V_29 ) ;
if ( V_120 -> V_170 -> V_16 & V_186 ) {
F_32 ( V_24 ) ;
F_15 ( V_177 , ~ V_207 , 0 ) ;
F_33 ( V_24 ) ;
}
if ( F_53 ( V_120 ) )
F_45 ( V_120 , F_54 ( V_120 ) ) ;
}
static void F_55 ( struct V_119 * V_120 )
{
struct V_28 * V_29 = V_120 -> V_208 ;
unsigned long V_24 ;
F_13 ( V_29 ) ;
if ( V_120 -> V_170 -> V_16 & V_186 ) {
F_32 ( V_24 ) ;
F_15 ( V_177 , 0xff , V_207 ) ;
F_33 ( V_24 ) ;
}
if ( F_53 ( V_120 ) )
F_45 ( V_120 , F_56 ( V_120 ) ) ;
}
static int F_57 ( struct V_119 * V_120 ,
unsigned int V_233 , unsigned long V_234 )
{
return - V_235 ;
}
static int F_58 ( struct V_119 * V_120 , int V_236 )
{
struct V_28 * V_29 = V_120 -> V_208 ;
unsigned long V_24 ;
F_13 ( V_29 ) ;
F_32 ( V_24 ) ;
F_15 ( V_177 , ~ V_237 ,
V_236 ? V_237 : 0 ) ;
F_33 ( V_24 ) ;
return 0 ;
}
static void F_59 ( char V_118 )
{
volatile char * V_238 = NULL ;
#ifdef F_20
if ( V_113 )
V_238 = ( volatile char * ) V_50 ;
#endif
#ifdef F_21
if ( V_114 )
V_238 = ( volatile char * ) V_90 ;
#endif
#ifdef F_22
if ( V_115 )
V_238 = ( volatile char * ) V_101 ;
#endif
do {
F_60 () ;
}
while ( ! ( * V_238 & 4 ) );
F_60 () ;
* V_238 = 8 ;
F_60 () ;
* V_238 = V_118 ;
}
static void F_61 ( struct V_239 * V_240 , const char * V_241 , unsigned V_232 )
{
unsigned long V_24 ;
F_32 ( V_24 ) ;
while ( V_232 -- )
{
if ( * V_241 == '\n' )
F_59 ( '\r' ) ;
F_59 ( * V_241 ++ ) ;
}
F_33 ( V_24 ) ;
}
static struct V_242 * F_62 ( struct V_239 * V_243 , int * V_211 )
{
* V_211 = V_243 -> V_211 ;
return V_1 ;
}
static int T_1 F_63 ( void )
{
if ( V_244 == V_245 ||
V_244 == V_246 ||
V_244 == V_247 ||
V_244 == V_248 ||
V_244 == V_249 )
F_64 ( & V_250 ) ;
return 0 ;
}
