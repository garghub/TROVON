void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
V_3 = F_2 ( V_5 ) ;
F_3 ( V_5 , V_3 | V_6 ) ;
( void ) F_2 ( V_5 ) ;
F_3 ( V_5 , V_3 ) ;
}
F_4 () ;
}
T_2 F_5 ( T_2 V_7 , T_1 V_8 )
{
V_7 = ( F_6 ( V_7 ) >> 8 ) |
( ( F_7 ( V_7 ) & 0xff ) << 24 ) ;
if ( V_8 & V_9 )
V_7 |= V_10 ;
if ( V_8 & V_11 )
V_7 |= V_12 ;
if ( ! ( V_8 & V_13 ) )
V_7 |= V_14 ;
return V_7 ;
}
void F_8 ( struct V_1 * V_2 , unsigned V_4 ,
T_2 V_15 )
{
void T_3 * V_16 = V_2 -> V_17 . V_16 ;
F_9 ( V_15 , ( ( void T_3 * ) V_16 ) + ( V_4 * 4 ) ) ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_17 . V_19 ) {
F_11 ( 1 , L_1 ) ;
return 0 ;
}
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( V_2 ) ;
if ( V_18 )
F_14 ( L_2 ) ;
V_2 -> V_17 . V_20 = V_2 -> V_17 . V_21 * 4 ;
V_2 -> V_22 -> V_17 . V_23 = & F_1 ;
V_2 -> V_22 -> V_17 . V_24 = & F_5 ;
V_2 -> V_22 -> V_17 . V_25 = & F_8 ;
return F_15 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
T_1 V_26 ;
T_1 V_3 ;
int V_18 ;
if ( V_2 -> V_17 . V_19 == NULL ) {
F_17 ( V_2 -> V_27 , L_3 ) ;
return - V_28 ;
}
V_18 = F_18 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_3 = V_29 ;
F_3 ( V_5 , V_3 ) ;
F_3 ( V_30 , V_2 -> V_31 . V_32 ) ;
V_3 = V_2 -> V_31 . V_33 & ~ V_34 ;
F_3 ( V_35 , V_3 ) ;
F_3 ( V_36 , 0 ) ;
F_3 ( V_37 , 0 ) ;
V_26 = V_2 -> V_17 . V_26 ;
F_3 ( V_38 , V_26 ) ;
F_3 ( V_39 , V_2 -> V_31 . V_40 ) ;
F_3 ( V_41 , 0 ) ;
F_3 ( V_42 , 0 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_43 ;
V_3 |= V_29 ;
F_3 ( V_5 , V_3 ) ;
F_1 ( V_2 ) ;
F_19 ( L_4 ,
( unsigned ) ( V_2 -> V_31 . V_44 >> 20 ) ,
( unsigned long long ) V_26 ) ;
V_2 -> V_17 . V_45 = true ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
T_4 V_3 ;
F_3 ( V_30 , 0 ) ;
F_3 ( V_35 , 0 ) ;
F_3 ( V_36 , 0 ) ;
F_3 ( V_37 , 0 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_29 ;
F_3 ( V_5 , V_3 & ~ V_43 ) ;
F_21 ( V_2 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_20 ( V_2 ) ;
F_24 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_2 -> V_49 [ V_47 -> V_49 ] ;
F_26 ( V_49 , F_27 ( V_50 , 0 ) ) ;
F_26 ( V_49 , 0 ) ;
F_26 ( V_49 , F_27 ( V_51 , 0 ) ) ;
F_26 ( V_49 , 0 ) ;
F_26 ( V_49 , F_27 ( V_52 , 0 ) ) ;
F_26 ( V_49 , V_53 ) ;
F_26 ( V_49 , F_27 ( V_54 , 0 ) ) ;
F_26 ( V_49 , V_55 ) ;
F_26 ( V_49 , F_27 ( V_56 , 0 ) ) ;
F_26 ( V_49 , ( V_57 |
V_58 |
V_59 ) ) ;
F_26 ( V_49 , F_27 ( V_60 , 0 ) ) ;
F_26 ( V_49 , V_2 -> V_61 . V_62 . V_63 |
V_64 ) ;
F_26 ( V_49 , F_27 ( V_60 , 0 ) ) ;
F_26 ( V_49 , V_2 -> V_61 . V_62 . V_63 ) ;
F_26 ( V_49 , F_27 ( V_2 -> V_65 [ V_47 -> V_49 ] . V_66 , 0 ) ) ;
F_26 ( V_49 , V_47 -> V_67 ) ;
F_26 ( V_49 , F_27 ( V_68 , 0 ) ) ;
F_26 ( V_49 , V_69 ) ;
}
void F_28 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
unsigned V_70 ;
int V_18 ;
V_70 = ( V_71 | V_72 ) ;
switch( V_2 -> V_73 ) {
case 2 :
V_70 |= V_74 ;
break;
case 3 :
V_70 |= V_75 ;
break;
case 4 :
V_70 |= V_76 ;
break;
case 1 :
default:
V_70 |= V_77 ;
break;
}
V_18 = F_29 ( V_2 , V_49 , 64 ) ;
if ( V_18 ) {
return;
}
F_26 ( V_49 , F_27 ( V_78 , 0 ) ) ;
F_26 ( V_49 ,
V_79 |
V_80 |
V_81 |
V_82 ) ;
F_26 ( V_49 , F_27 ( V_83 , 0 ) ) ;
F_26 ( V_49 , V_70 ) ;
F_26 ( V_49 , F_27 ( V_56 , 0 ) ) ;
F_26 ( V_49 ,
V_58 |
V_57 ) ;
F_26 ( V_49 , F_27 ( V_84 , 0 ) ) ;
F_26 ( V_49 , V_85 ) ;
F_26 ( V_49 , F_27 ( V_86 , 0 ) ) ;
F_26 ( V_49 , 0 ) ;
F_26 ( V_49 , F_27 ( V_87 , 0 ) ) ;
F_26 ( V_49 , 0 ) ;
F_26 ( V_49 , F_27 ( V_52 , 0 ) ) ;
F_26 ( V_49 , V_53 | V_88 ) ;
F_26 ( V_49 , F_27 ( V_54 , 0 ) ) ;
F_26 ( V_49 , V_55 | V_89 ) ;
F_26 ( V_49 , F_27 ( V_56 , 0 ) ) ;
F_26 ( V_49 ,
V_58 |
V_57 ) ;
F_26 ( V_49 , F_27 ( V_90 , 0 ) ) ;
F_26 ( V_49 , 0 ) ;
F_26 ( V_49 , F_27 ( V_52 , 0 ) ) ;
F_26 ( V_49 , V_53 | V_88 ) ;
F_26 ( V_49 , F_27 ( V_54 , 0 ) ) ;
F_26 ( V_49 , V_55 | V_89 ) ;
F_26 ( V_49 , F_27 ( V_91 , 0 ) ) ;
F_26 ( V_49 ,
( ( 6 << V_92 ) |
( 6 << V_93 ) |
( 6 << V_94 ) |
( 6 << V_95 ) |
( 6 << V_96 ) |
( 6 << V_97 ) |
( 6 << V_98 ) |
( 6 << V_99 ) ) ) ;
F_26 ( V_49 , F_27 ( V_100 , 0 ) ) ;
F_26 ( V_49 ,
( ( 6 << V_101 ) |
( 6 << V_102 ) |
( 6 << V_103 ) |
( 6 << V_104 ) |
( 6 << V_105 ) |
( 6 << V_106 ) |
( 6 << V_107 ) ) ) ;
F_26 ( V_49 , F_27 ( V_108 , 0 ) ) ;
F_26 ( V_49 , V_109 | V_110 ) ;
F_26 ( V_49 , F_27 ( V_111 , 0 ) ) ;
F_26 ( V_49 ,
V_112 | V_113 ) ;
F_26 ( V_49 , F_27 ( V_114 , 0 ) ) ;
F_26 ( V_49 ,
V_115 |
V_116 ) ;
F_30 ( V_2 , V_49 , false ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
V_2 -> V_117 = 0 ;
if ( V_2 -> V_118 == V_119 &&
( F_32 ( V_120 ) & V_121 ) == V_122 ) {
V_2 -> V_117 |= V_123 ;
}
}
int F_33 ( struct V_1 * V_2 )
{
unsigned V_4 ;
T_1 V_3 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_124 ; V_4 ++ ) {
V_3 = F_32 ( V_125 ) ;
if ( V_3 & V_126 ) {
return 0 ;
}
F_34 ( 1 ) ;
}
return - 1 ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_70 , V_3 ;
if ( ( V_2 -> V_118 == V_119 && V_2 -> V_127 -> V_128 != 0x4144 ) ||
( V_2 -> V_118 == V_129 && V_2 -> V_127 -> V_128 != 0x4148 ) ) {
V_2 -> V_73 = 2 ;
} else {
V_2 -> V_73 = 1 ;
}
V_2 -> V_130 = 1 ;
V_70 = ( V_71 | V_72 ) ;
switch ( V_2 -> V_73 ) {
case 2 :
V_70 |= V_74 ;
break;
case 3 :
V_70 |= V_75 ;
break;
case 4 :
V_70 |= V_76 ;
break;
default:
case 1 :
V_70 |= V_77 ;
break;
}
F_36 ( V_83 , V_70 ) ;
if ( F_37 ( V_2 ) ) {
F_38 ( V_131 L_5
L_6 ) ;
}
V_3 = F_32 ( V_84 ) ;
F_36 ( V_84 , V_3 | V_85 ) ;
F_36 ( V_132 ,
V_133 |
V_134 ) ;
if ( F_37 ( V_2 ) ) {
F_38 ( V_131 L_5
L_6 ) ;
}
if ( F_33 ( V_2 ) ) {
F_38 ( V_131 L_7
L_6 ) ;
}
F_19 ( L_8 ,
V_2 -> V_73 , V_2 -> V_130 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_135 V_136 ;
T_4 V_137 , V_3 ;
int V_138 = 0 ;
V_137 = F_32 ( V_139 ) ;
if ( ! F_40 ( V_137 ) ) {
return 0 ;
}
F_41 ( V_2 , & V_136 ) ;
V_137 = F_32 ( V_139 ) ;
F_42 ( V_2 -> V_27 , L_9 , V_140 , __LINE__ , V_137 ) ;
F_36 ( V_141 , 0 ) ;
V_3 = F_32 ( V_142 ) ;
F_36 ( V_142 , V_3 | V_143 ) ;
F_36 ( V_144 , 0 ) ;
F_36 ( V_145 , 0 ) ;
F_36 ( V_142 , V_3 ) ;
F_43 ( V_2 -> V_127 ) ;
F_44 ( V_2 ) ;
F_36 ( V_146 , F_45 ( 1 ) |
F_46 ( 1 ) ) ;
F_32 ( V_146 ) ;
F_47 ( 500 ) ;
F_36 ( V_146 , 0 ) ;
F_47 ( 1 ) ;
V_137 = F_32 ( V_139 ) ;
F_42 ( V_2 -> V_27 , L_9 , V_140 , __LINE__ , V_137 ) ;
F_36 ( V_146 , F_48 ( 1 ) ) ;
F_32 ( V_146 ) ;
F_47 ( 500 ) ;
F_36 ( V_146 , 0 ) ;
F_47 ( 1 ) ;
V_137 = F_32 ( V_139 ) ;
F_42 ( V_2 -> V_27 , L_9 , V_140 , __LINE__ , V_137 ) ;
F_49 ( V_2 -> V_127 ) ;
F_50 ( V_2 ) ;
if ( F_51 ( V_137 ) || F_52 ( V_137 ) ) {
F_17 ( V_2 -> V_27 , L_10 ) ;
V_138 = - 1 ;
} else
F_42 ( V_2 -> V_27 , L_11 ) ;
F_53 ( V_2 , & V_136 ) ;
return V_138 ;
}
void F_54 ( struct V_1 * V_2 )
{
T_5 V_147 ;
T_4 V_3 ;
V_2 -> V_31 . V_148 = true ;
V_3 = F_32 ( V_149 ) ;
V_3 &= V_150 ;
switch ( V_3 ) {
case 0 : V_2 -> V_31 . V_151 = 64 ; break;
case 1 : V_2 -> V_31 . V_151 = 128 ; break;
case 2 : V_2 -> V_31 . V_151 = 256 ; break;
default: V_2 -> V_31 . V_151 = 128 ; break;
}
F_55 ( V_2 ) ;
V_147 = V_2 -> V_31 . V_152 ;
if ( V_2 -> V_8 & V_153 )
V_147 = ( F_32 ( V_154 ) & 0xffff ) << 16 ;
F_56 ( V_2 , & V_2 -> V_31 , V_147 ) ;
V_2 -> V_31 . V_155 = 0 ;
if ( ! ( V_2 -> V_8 & V_156 ) )
F_57 ( V_2 , & V_2 -> V_31 ) ;
F_58 ( V_2 ) ;
}
void F_59 ( struct V_1 * V_2 , int V_157 )
{
T_1 V_158 , V_159 ;
if ( V_2 -> V_8 & V_153 )
return;
if ( ! ( V_2 -> V_8 & V_160 ) )
return;
switch ( V_157 ) {
case 0 :
V_159 = V_161 ;
break;
case 1 :
V_159 = V_162 ;
break;
case 2 :
V_159 = V_163 ;
break;
case 4 :
V_159 = V_164 ;
break;
case 8 :
V_159 = V_165 ;
break;
case 12 :
V_159 = V_166 ;
break;
case 16 :
default:
V_159 = V_167 ;
break;
}
V_158 = F_2 ( V_168 ) ;
if ( ( V_158 & V_169 ) ==
( V_159 << V_170 ) )
return;
V_158 &= ~ ( V_171 |
V_172 |
V_173 |
V_174 ) ;
V_158 |= V_159 ;
F_3 ( V_168 , V_158 ) ;
F_3 ( V_168 , ( V_158 |
V_172 ) ) ;
V_158 = F_2 ( V_168 ) ;
while ( V_158 == 0xffffffff )
V_158 = F_2 ( V_168 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
T_4 V_158 ;
if ( V_2 -> V_8 & V_153 )
return 0 ;
if ( ! ( V_2 -> V_8 & V_160 ) )
return 0 ;
V_158 = F_2 ( V_168 ) ;
switch ( ( V_158 & V_169 ) >> V_170 ) {
case V_161 :
return 0 ;
case V_162 :
return 1 ;
case V_163 :
return 2 ;
case V_164 :
return 4 ;
case V_165 :
return 8 ;
case V_167 :
default:
return 16 ;
}
}
static int F_61 ( struct V_175 * V_176 , void * V_177 )
{
struct V_178 * V_179 = (struct V_178 * ) V_176 -> V_180 ;
struct V_181 * V_27 = V_179 -> V_182 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_183 ;
T_1 V_3 ;
V_3 = F_2 ( V_5 ) ;
F_62 ( V_176 , L_12 , V_3 ) ;
V_3 = F_2 ( V_38 ) ;
F_62 ( V_176 , L_13 , V_3 ) ;
V_3 = F_2 ( V_30 ) ;
F_62 ( V_176 , L_14 , V_3 ) ;
V_3 = F_2 ( V_36 ) ;
F_62 ( V_176 , L_15 , V_3 ) ;
V_3 = F_2 ( V_35 ) ;
F_62 ( V_176 , L_16 , V_3 ) ;
V_3 = F_2 ( V_37 ) ;
F_62 ( V_176 , L_17 , V_3 ) ;
V_3 = F_2 ( V_42 ) ;
F_62 ( V_176 , L_18 , V_3 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
#if F_63 ( V_184 )
return F_64 ( V_2 , V_185 , 1 ) ;
#else
return 0 ;
#endif
}
static int F_65 ( struct V_186 * V_187 ,
struct V_188 * V_189 ,
unsigned V_190 , unsigned V_191 )
{
struct V_192 * V_193 ;
struct V_194 * V_195 ;
volatile T_1 * V_196 ;
T_1 V_3 , V_197 = 0 ;
unsigned V_4 ;
int V_18 ;
T_4 V_198 ;
V_196 = V_187 -> V_196 . V_16 ;
V_195 = (struct V_194 * ) V_187 -> V_195 ;
V_198 = F_66 ( V_187 , V_190 ) ;
switch( V_191 ) {
case V_199 :
case V_200 :
V_18 = F_67 ( V_187 ) ;
if ( V_18 ) {
F_14 ( L_19 ,
V_190 , V_191 ) ;
F_68 ( V_187 , V_189 ) ;
return V_18 ;
}
break;
case V_201 :
case V_202 :
V_18 = F_69 ( V_187 , V_189 , V_190 , V_191 ) ;
if ( V_18 )
return V_18 ;
break;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
V_4 = ( V_191 - V_203 ) >> 2 ;
V_18 = F_70 ( V_187 , & V_193 , 0 ) ;
if ( V_18 ) {
F_14 ( L_19 ,
V_190 , V_191 ) ;
F_68 ( V_187 , V_189 ) ;
return V_18 ;
}
V_195 -> V_207 [ V_4 ] . V_19 = V_193 -> V_19 ;
V_195 -> V_207 [ V_4 ] . V_208 = V_198 ;
V_195 -> V_209 = true ;
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 ) ;
break;
case V_211 :
V_18 = F_70 ( V_187 , & V_193 , 0 ) ;
if ( V_18 ) {
F_14 ( L_19 ,
V_190 , V_191 ) ;
F_68 ( V_187 , V_189 ) ;
return V_18 ;
}
V_195 -> V_212 . V_19 = V_193 -> V_19 ;
V_195 -> V_212 . V_208 = V_198 ;
V_195 -> V_213 = true ;
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 ) ;
break;
case V_214 :
case V_214 + 4 :
case V_214 + 8 :
case V_214 + 12 :
case V_214 + 16 :
case V_214 + 20 :
case V_214 + 24 :
case V_214 + 28 :
case V_214 + 32 :
case V_214 + 36 :
case V_214 + 40 :
case V_214 + 44 :
case V_214 + 48 :
case V_214 + 52 :
case V_214 + 56 :
case V_214 + 60 :
V_4 = ( V_191 - V_214 ) >> 2 ;
V_18 = F_70 ( V_187 , & V_193 , 0 ) ;
if ( V_18 ) {
F_14 ( L_19 ,
V_190 , V_191 ) ;
F_68 ( V_187 , V_189 ) ;
return V_18 ;
}
if ( V_187 -> V_215 & V_216 ) {
V_196 [ V_190 ] = ( V_198 & 31 ) |
( ( V_198 & ~ 31 ) + ( T_4 ) V_193 -> V_210 ) ;
} else {
if ( V_193 -> V_217 & V_218 )
V_197 |= V_219 ;
if ( V_193 -> V_217 & V_220 )
V_197 |= V_221 ;
else if ( V_193 -> V_217 & V_222 )
V_197 |= V_223 ;
V_3 = V_198 + ( ( T_4 ) V_193 -> V_210 ) ;
V_3 |= V_197 ;
V_196 [ V_190 ] = V_3 ;
}
V_195 -> V_224 [ V_4 ] . V_19 = V_193 -> V_19 ;
V_195 -> V_225 = true ;
break;
case 0x2084 :
V_195 -> V_226 = V_198 ;
break;
case 0x20B4 :
V_195 -> V_227 = V_198 & 0x7F ;
break;
case 0x2134 :
V_195 -> V_228 = V_198 & 0x00FFFFFFUL ;
break;
case 0x2088 :
if ( V_187 -> V_2 -> V_118 < V_229 )
goto V_230;
V_195 -> V_231 = V_198 & 0xFFFFFF ;
break;
case 0x43E4 :
V_195 -> V_232 = ( ( V_198 >> 13 ) & 0x1FFF ) + 1 ;
if ( V_187 -> V_2 -> V_118 < V_229 ) {
V_195 -> V_232 -= 1440 ;
}
V_195 -> V_209 = true ;
V_195 -> V_213 = true ;
break;
case 0x4E00 :
if ( ( V_198 & ( 1 << 10 ) ) &&
V_187 -> V_2 -> V_233 != V_187 -> V_234 ) {
F_14 ( L_20 ) ;
return - V_28 ;
}
V_195 -> V_235 = ( ( V_198 >> 5 ) & 0x3 ) + 1 ;
V_195 -> V_209 = true ;
break;
case 0x4E38 :
case 0x4E3C :
case 0x4E40 :
case 0x4E44 :
if ( ! ( V_187 -> V_215 & V_216 ) ) {
V_18 = F_70 ( V_187 , & V_193 , 0 ) ;
if ( V_18 ) {
F_14 ( L_19 ,
V_190 , V_191 ) ;
F_68 ( V_187 , V_189 ) ;
return V_18 ;
}
if ( V_193 -> V_217 & V_218 )
V_197 |= V_236 ;
if ( V_193 -> V_217 & V_220 )
V_197 |= V_237 ;
else if ( V_193 -> V_217 & V_222 )
V_197 |= V_238 ;
V_3 = V_198 & ~ ( 0x7 << 16 ) ;
V_3 |= V_197 ;
V_196 [ V_190 ] = V_3 ;
}
V_4 = ( V_191 - 0x4E38 ) >> 2 ;
V_195 -> V_207 [ V_4 ] . V_239 = V_198 & 0x3FFE ;
switch ( ( ( V_198 >> 21 ) & 0xF ) ) {
case 9 :
case 11 :
case 12 :
V_195 -> V_207 [ V_4 ] . V_240 = 1 ;
break;
case 3 :
case 4 :
case 13 :
case 15 :
V_195 -> V_207 [ V_4 ] . V_240 = 2 ;
break;
case 5 :
if ( V_187 -> V_2 -> V_118 < V_229 ) {
F_14 ( L_21 ,
( ( V_198 >> 21 ) & 0xF ) ) ;
return - V_28 ;
}
case 6 :
V_195 -> V_207 [ V_4 ] . V_240 = 4 ;
break;
case 10 :
V_195 -> V_207 [ V_4 ] . V_240 = 8 ;
break;
case 7 :
V_195 -> V_207 [ V_4 ] . V_240 = 16 ;
break;
default:
F_14 ( L_22 ,
( ( V_198 >> 21 ) & 0xF ) ) ;
return - V_28 ;
}
V_195 -> V_209 = true ;
break;
case 0x4F00 :
if ( V_198 & 2 ) {
V_195 -> V_241 = true ;
} else {
V_195 -> V_241 = false ;
}
V_195 -> V_213 = true ;
break;
case 0x4F10 :
switch ( ( V_198 & 0xF ) ) {
case 0 :
case 1 :
V_195 -> V_212 . V_240 = 2 ;
break;
case 2 :
V_195 -> V_212 . V_240 = 4 ;
break;
default:
F_14 ( L_23 ,
( V_198 & 0xF ) ) ;
return - V_28 ;
}
V_195 -> V_213 = true ;
break;
case 0x4F24 :
if ( ! ( V_187 -> V_215 & V_216 ) ) {
V_18 = F_70 ( V_187 , & V_193 , 0 ) ;
if ( V_18 ) {
F_14 ( L_19 ,
V_190 , V_191 ) ;
F_68 ( V_187 , V_189 ) ;
return V_18 ;
}
if ( V_193 -> V_217 & V_218 )
V_197 |= V_242 ;
if ( V_193 -> V_217 & V_220 )
V_197 |= V_243 ;
else if ( V_193 -> V_217 & V_222 )
V_197 |= V_244 ;
V_3 = V_198 & ~ ( 0x7 << 16 ) ;
V_3 |= V_197 ;
V_196 [ V_190 ] = V_3 ;
}
V_195 -> V_212 . V_239 = V_198 & 0x3FFC ;
V_195 -> V_213 = true ;
break;
case 0x4104 :
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
bool V_245 ;
V_245 = ! ! ( V_198 & ( 1 << V_4 ) ) ;
V_195 -> V_224 [ V_4 ] . V_245 = V_245 ;
}
V_195 -> V_225 = true ;
break;
case 0x44C0 :
case 0x44C4 :
case 0x44C8 :
case 0x44CC :
case 0x44D0 :
case 0x44D4 :
case 0x44D8 :
case 0x44DC :
case 0x44E0 :
case 0x44E4 :
case 0x44E8 :
case 0x44EC :
case 0x44F0 :
case 0x44F4 :
case 0x44F8 :
case 0x44FC :
V_4 = ( V_191 - 0x44C0 ) >> 2 ;
V_3 = ( V_198 >> 25 ) & 0x3 ;
V_195 -> V_224 [ V_4 ] . V_246 = V_3 ;
switch ( ( V_198 & 0x1F ) ) {
case V_247 :
case V_248 :
case V_249 :
V_195 -> V_224 [ V_4 ] . V_240 = 1 ;
V_195 -> V_224 [ V_4 ] . V_250 = V_251 ;
break;
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
V_195 -> V_224 [ V_4 ] . V_240 = 2 ;
V_195 -> V_224 [ V_4 ] . V_250 = V_251 ;
break;
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case 0x17 :
case V_268 :
case 0x1e :
V_195 -> V_224 [ V_4 ] . V_240 = 4 ;
V_195 -> V_224 [ V_4 ] . V_250 = V_251 ;
break;
case V_269 :
case V_270 :
case V_271 :
V_195 -> V_224 [ V_4 ] . V_240 = 8 ;
V_195 -> V_224 [ V_4 ] . V_250 = V_251 ;
break;
case V_272 :
V_195 -> V_224 [ V_4 ] . V_240 = 16 ;
V_195 -> V_224 [ V_4 ] . V_250 = V_251 ;
break;
case V_273 :
V_195 -> V_224 [ V_4 ] . V_240 = 1 ;
V_195 -> V_224 [ V_4 ] . V_250 = V_274 ;
break;
case V_275 :
if ( V_187 -> V_2 -> V_118 < V_276 ) {
F_14 ( L_24 ,
( V_198 & 0x1F ) ) ;
return - V_28 ;
}
case V_277 :
case V_278 :
V_195 -> V_224 [ V_4 ] . V_240 = 1 ;
V_195 -> V_224 [ V_4 ] . V_250 = V_279 ;
break;
default:
F_14 ( L_24 ,
( V_198 & 0x1F ) ) ;
return - V_28 ;
}
V_195 -> V_225 = true ;
break;
case 0x4400 :
case 0x4404 :
case 0x4408 :
case 0x440C :
case 0x4410 :
case 0x4414 :
case 0x4418 :
case 0x441C :
case 0x4420 :
case 0x4424 :
case 0x4428 :
case 0x442C :
case 0x4430 :
case 0x4434 :
case 0x4438 :
case 0x443C :
V_4 = ( V_191 - 0x4400 ) >> 2 ;
V_3 = V_198 & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_195 -> V_224 [ V_4 ] . V_280 = false ;
}
V_3 = ( V_198 >> 3 ) & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_195 -> V_224 [ V_4 ] . V_281 = false ;
}
V_195 -> V_225 = true ;
break;
case 0x4500 :
case 0x4504 :
case 0x4508 :
case 0x450C :
case 0x4510 :
case 0x4514 :
case 0x4518 :
case 0x451C :
case 0x4520 :
case 0x4524 :
case 0x4528 :
case 0x452C :
case 0x4530 :
case 0x4534 :
case 0x4538 :
case 0x453C :
V_4 = ( V_191 - 0x4500 ) >> 2 ;
V_3 = V_198 & 0x3FFF ;
V_195 -> V_224 [ V_4 ] . V_239 = V_3 + 1 ;
if ( V_187 -> V_2 -> V_118 >= V_229 ) {
V_3 = ( ( V_198 >> 15 ) & 1 ) << 11 ;
V_195 -> V_224 [ V_4 ] . V_282 = V_3 ;
V_3 = ( ( V_198 >> 16 ) & 1 ) << 11 ;
V_195 -> V_224 [ V_4 ] . V_283 = V_3 ;
if ( V_198 & ( 1 << 14 ) ) {
V_195 -> V_224 [ V_4 ] . V_250 =
V_274 ;
}
} else if ( V_198 & ( 1 << 14 ) ) {
F_14 ( L_25 ) ;
return - V_28 ;
}
V_195 -> V_225 = true ;
break;
case 0x4480 :
case 0x4484 :
case 0x4488 :
case 0x448C :
case 0x4490 :
case 0x4494 :
case 0x4498 :
case 0x449C :
case 0x44A0 :
case 0x44A4 :
case 0x44A8 :
case 0x44AC :
case 0x44B0 :
case 0x44B4 :
case 0x44B8 :
case 0x44BC :
V_4 = ( V_191 - 0x4480 ) >> 2 ;
V_3 = V_198 & 0x7FF ;
V_195 -> V_224 [ V_4 ] . V_284 = V_3 + 1 ;
V_3 = ( V_198 >> 11 ) & 0x7FF ;
V_195 -> V_224 [ V_4 ] . V_285 = V_3 + 1 ;
V_3 = ( V_198 >> 26 ) & 0xF ;
V_195 -> V_224 [ V_4 ] . V_286 = V_3 ;
V_3 = V_198 & ( 1 << 31 ) ;
V_195 -> V_224 [ V_4 ] . V_287 = ! ! V_3 ;
V_3 = ( V_198 >> 22 ) & 0xF ;
V_195 -> V_224 [ V_4 ] . V_288 = V_3 ;
V_195 -> V_225 = true ;
break;
case V_289 :
V_18 = F_70 ( V_187 , & V_193 , 0 ) ;
if ( V_18 ) {
F_14 ( L_19 ,
V_190 , V_191 ) ;
F_68 ( V_187 , V_189 ) ;
return V_18 ;
}
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 ) ;
break;
case 0x4e0c :
V_195 -> V_290 = V_198 ;
V_195 -> V_209 = true ;
break;
case 0x43a4 :
if ( V_187 -> V_2 -> V_291 != V_187 -> V_234 ) {
if ( V_198 & 0x1 )
V_196 [ V_190 ] = V_198 & ~ 1 ;
}
break;
case 0x4f1c :
V_195 -> V_292 = ! ! ( V_198 & ( 1 << 5 ) ) ;
V_195 -> V_209 = true ;
V_195 -> V_213 = true ;
if ( V_187 -> V_2 -> V_291 != V_187 -> V_234 ) {
if ( V_198 & ( V_293 |
V_294 |
V_295 |
V_296 ) )
goto V_230;
}
break;
case 0x4e04 :
V_195 -> V_297 = ! ! ( V_198 & ( 1 << 2 ) ) ;
V_195 -> V_209 = true ;
break;
case V_298 :
V_18 = F_70 ( V_187 , & V_193 , 0 ) ;
if ( V_18 ) {
F_14 ( L_19 ,
V_190 , V_191 ) ;
F_68 ( V_187 , V_189 ) ;
return V_18 ;
}
V_195 -> V_299 . V_19 = V_193 -> V_19 ;
V_195 -> V_299 . V_208 = V_198 ;
V_195 -> V_300 = true ;
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 ) ;
break;
case V_301 :
V_195 -> V_299 . V_239 = V_198 & 0x3FFE ;
V_195 -> V_300 = true ;
break;
case V_302 :
V_195 -> V_303 = V_198 & 0x1 ;
V_195 -> V_300 = true ;
break;
case 0x4f30 :
case 0x4f34 :
case 0x4f44 :
case 0x4f54 :
if ( V_198 && ( V_187 -> V_2 -> V_291 != V_187 -> V_234 ) )
goto V_230;
break;
case 0x4028 :
if ( V_198 && ( V_187 -> V_2 -> V_291 != V_187 -> V_234 ) )
goto V_230;
if ( V_187 -> V_2 -> V_118 >= V_304 )
break;
goto V_230;
break;
case 0x4be8 :
if ( V_187 -> V_2 -> V_118 == V_305 )
break;
default:
goto V_230;
}
return 0 ;
V_230:
F_38 ( V_306 L_26 ,
V_191 , V_190 , V_198 ) ;
return - V_28 ;
}
static int F_71 ( struct V_186 * V_187 ,
struct V_188 * V_189 )
{
struct V_192 * V_193 ;
struct V_194 * V_195 ;
volatile T_1 * V_196 ;
unsigned V_190 ;
int V_18 ;
V_196 = V_187 -> V_196 . V_16 ;
V_190 = V_189 -> V_190 + 1 ;
V_195 = (struct V_194 * ) V_187 -> V_195 ;
switch( V_189 -> V_307 ) {
case V_308 :
V_18 = F_72 ( V_187 , V_189 , V_190 ) ;
if ( V_18 )
return V_18 ;
break;
case V_309 :
V_18 = F_70 ( V_187 , & V_193 , 0 ) ;
if ( V_18 ) {
F_14 ( L_27 , V_189 -> V_307 ) ;
F_68 ( V_187 , V_189 ) ;
return V_18 ;
}
V_196 [ V_190 + 1 ] = F_66 ( V_187 , V_190 + 1 ) + ( ( T_4 ) V_193 -> V_210 ) ;
V_18 = F_73 ( V_187 , V_189 , V_193 -> V_19 ) ;
if ( V_18 ) {
return V_18 ;
}
break;
case V_310 :
if ( ( ( F_66 ( V_187 , V_190 + 1 ) >> 4 ) & 0x3 ) != 3 ) {
F_14 ( L_28 ) ;
return - V_28 ;
}
V_195 -> V_226 = F_66 ( V_187 , V_190 + 1 ) ;
V_195 -> V_311 = V_189 -> V_312 - 1 ;
V_18 = F_74 ( V_187 -> V_2 , V_195 ) ;
if ( V_18 ) {
return V_18 ;
}
break;
case V_313 :
if ( ( ( F_66 ( V_187 , V_190 ) >> 4 ) & 0x3 ) != 3 ) {
F_14 ( L_28 ) ;
return - V_28 ;
}
V_195 -> V_226 = F_66 ( V_187 , V_190 ) ;
V_195 -> V_311 = V_189 -> V_312 ;
V_18 = F_74 ( V_187 -> V_2 , V_195 ) ;
if ( V_18 ) {
return V_18 ;
}
break;
case V_314 :
V_195 -> V_226 = F_66 ( V_187 , V_190 + 1 ) ;
V_18 = F_74 ( V_187 -> V_2 , V_195 ) ;
if ( V_18 ) {
return V_18 ;
}
break;
case V_315 :
V_195 -> V_226 = F_66 ( V_187 , V_190 ) ;
V_18 = F_74 ( V_187 -> V_2 , V_195 ) ;
if ( V_18 ) {
return V_18 ;
}
break;
case V_316 :
V_195 -> V_226 = F_66 ( V_187 , V_190 + 1 ) ;
V_18 = F_74 ( V_187 -> V_2 , V_195 ) ;
if ( V_18 ) {
return V_18 ;
}
break;
case V_317 :
V_195 -> V_226 = F_66 ( V_187 , V_190 ) ;
V_18 = F_74 ( V_187 -> V_2 , V_195 ) ;
if ( V_18 ) {
return V_18 ;
}
break;
case V_318 :
case V_319 :
if ( V_187 -> V_2 -> V_291 != V_187 -> V_234 )
return - V_28 ;
break;
case V_320 :
if ( V_187 -> V_2 -> V_233 != V_187 -> V_234 )
return - V_28 ;
break;
case V_321 :
break;
default:
F_14 ( L_29 , V_189 -> V_307 ) ;
return - V_28 ;
}
return 0 ;
}
int F_75 ( struct V_186 * V_187 )
{
struct V_188 V_189 ;
struct V_194 * V_195 ;
int V_18 ;
V_195 = F_76 ( sizeof( * V_195 ) , V_322 ) ;
if ( V_195 == NULL )
return - V_323 ;
F_77 ( V_187 -> V_2 , V_195 ) ;
V_187 -> V_195 = V_195 ;
do {
V_18 = F_78 ( V_187 , & V_189 , V_187 -> V_190 ) ;
if ( V_18 ) {
return V_18 ;
}
V_187 -> V_190 += V_189 . V_312 + 2 ;
switch ( V_189 . type ) {
case V_324 :
V_18 = F_79 ( V_187 , & V_189 ,
V_187 -> V_2 -> V_61 . V_62 . V_325 ,
V_187 -> V_2 -> V_61 . V_62 . V_326 ,
& F_65 ) ;
break;
case V_327 :
break;
case V_328 :
V_18 = F_71 ( V_187 , & V_189 ) ;
break;
default:
F_14 ( L_30 , V_189 . type ) ;
return - V_28 ;
}
if ( V_18 ) {
return V_18 ;
}
} while ( V_187 -> V_190 < V_187 -> V_329 -> V_330 );
return 0 ;
}
void F_80 ( struct V_1 * V_2 )
{
V_2 -> V_61 . V_62 . V_325 = V_331 ;
V_2 -> V_61 . V_62 . V_326 = F_81 ( V_331 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_135 V_136 ;
int V_18 ;
V_18 = F_83 ( V_2 ) ;
if ( V_18 ) {
F_17 ( V_2 -> V_27 , L_31 ) ;
}
F_41 ( V_2 , & V_136 ) ;
if ( V_2 -> V_8 & V_156 ) {
F_36 ( V_332 ,
F_84 ( V_2 -> V_31 . V_32 >> 16 ) |
F_85 ( V_2 -> V_31 . V_33 >> 16 ) ) ;
F_36 ( V_333 , F_6 ( V_2 -> V_31 . V_334 ) ) ;
F_36 ( V_335 ,
F_7 ( V_2 -> V_31 . V_334 ) & 0xff ) ;
} else {
F_36 ( V_332 , 0x0FFFFFFF ) ;
F_36 ( V_333 , 0 ) ;
F_36 ( V_335 , 0 ) ;
}
if ( F_33 ( V_2 ) )
F_19 ( L_32 ) ;
F_36 ( V_336 ,
F_86 ( V_2 -> V_31 . V_40 >> 16 ) |
F_87 ( V_2 -> V_31 . V_337 >> 16 ) ) ;
F_53 ( V_2 , & V_136 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
T_4 V_3 ;
if ( V_338 != - 1 && V_338 )
F_89 ( V_2 , 1 ) ;
V_3 = F_90 ( V_339 ) ;
V_3 |= F_91 ( 1 ) | F_92 ( 1 ) ;
if ( ( V_2 -> V_118 == V_304 ) || ( V_2 -> V_118 == V_340 ) )
V_3 |= F_93 ( 1 ) ;
F_94 ( V_339 , V_3 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_18 ;
F_96 ( V_2 ) ;
F_82 ( V_2 ) ;
F_88 ( V_2 ) ;
F_35 ( V_2 ) ;
if ( V_2 -> V_8 & V_160 ) {
V_18 = F_16 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_118 == V_119 ||
V_2 -> V_118 == V_129 ||
V_2 -> V_118 == V_304 )
F_50 ( V_2 ) ;
if ( V_2 -> V_8 & V_341 ) {
V_18 = F_97 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
V_18 = F_98 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_99 ( V_2 , V_342 ) ;
if ( V_18 ) {
F_17 ( V_2 -> V_27 , L_33 , V_18 ) ;
return V_18 ;
}
if ( ! V_2 -> V_343 . V_344 ) {
V_18 = F_100 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
F_101 ( V_2 ) ;
V_2 -> V_61 . V_62 . V_63 = F_32 ( V_60 ) ;
V_18 = F_102 ( V_2 , 1024 * 1024 ) ;
if ( V_18 ) {
F_17 ( V_2 -> V_27 , L_34 , V_18 ) ;
return V_18 ;
}
V_18 = F_103 ( V_2 ) ;
if ( V_18 ) {
F_17 ( V_2 -> V_27 , L_35 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_8 & V_160 )
F_20 ( V_2 ) ;
if ( V_2 -> V_8 & V_341 )
F_105 ( V_2 ) ;
F_88 ( V_2 ) ;
if ( F_106 ( V_2 ) ) {
F_107 ( V_2 -> V_27 , L_36 ,
F_32 ( V_139 ) ,
F_32 ( V_345 ) ) ;
}
F_108 ( V_2 -> V_346 ) ;
F_88 ( V_2 ) ;
F_109 ( V_2 ) ;
V_2 -> V_347 = true ;
V_18 = F_95 ( V_2 ) ;
if ( V_18 ) {
V_2 -> V_347 = false ;
}
return V_18 ;
}
int F_110 ( struct V_1 * V_2 )
{
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
F_114 ( V_2 ) ;
if ( V_2 -> V_8 & V_160 )
F_20 ( V_2 ) ;
if ( V_2 -> V_8 & V_341 )
F_105 ( V_2 ) ;
return 0 ;
}
void F_115 ( struct V_1 * V_2 )
{
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
if ( V_2 -> V_8 & V_160 )
F_22 ( V_2 ) ;
if ( V_2 -> V_8 & V_341 )
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 -> V_348 ) ;
V_2 -> V_348 = NULL ;
}
int F_128 ( struct V_1 * V_2 )
{
int V_18 ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_109 ( V_2 ) ;
F_131 ( V_2 ) ;
if ( ! F_132 ( V_2 ) ) {
if ( F_133 ( V_2 ) )
return - V_28 ;
}
if ( V_2 -> V_349 ) {
F_17 ( V_2 -> V_27 , L_37 ) ;
return - V_28 ;
} else {
V_18 = F_134 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
if ( F_106 ( V_2 ) ) {
F_107 ( V_2 -> V_27 ,
L_36 ,
F_32 ( V_139 ) ,
F_32 ( V_345 ) ) ;
}
if ( F_135 ( V_2 ) == false )
return - V_28 ;
F_31 ( V_2 ) ;
F_136 ( V_2 -> V_346 ) ;
if ( V_2 -> V_8 & V_156 ) {
V_18 = F_137 ( V_2 ) ;
if ( V_18 ) {
F_138 ( V_2 ) ;
}
}
F_54 ( V_2 ) ;
V_18 = F_139 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_140 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_2 -> V_8 & V_160 ) {
V_18 = F_10 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_8 & V_341 ) {
V_18 = F_141 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
F_80 ( V_2 ) ;
F_142 ( V_2 ) ;
V_2 -> V_347 = true ;
V_18 = F_95 ( V_2 ) ;
if ( V_18 ) {
F_17 ( V_2 -> V_27 , L_38 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_123 ( V_2 ) ;
if ( V_2 -> V_8 & V_160 )
F_22 ( V_2 ) ;
if ( V_2 -> V_8 & V_341 )
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
V_2 -> V_347 = false ;
}
return 0 ;
}
