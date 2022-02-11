T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , ( ( V_3 ) & V_2 -> V_8 ) ) ;
V_5 = F_4 ( V_9 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , ( ( V_3 ) & V_2 -> V_8 ) ) ;
F_3 ( V_9 , ( V_10 ) ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
T_1 V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
V_11 = F_8 ( V_13 ) ;
F_9 ( V_13 , V_11 | V_14 ) ;
( void ) F_8 ( V_13 ) ;
F_9 ( V_13 , V_11 ) ;
}
F_10 () ;
}
T_2 F_11 ( T_2 V_15 , T_1 V_4 )
{
V_15 = ( F_12 ( V_15 ) >> 8 ) |
( ( F_13 ( V_15 ) & 0xff ) << 24 ) ;
if ( V_4 & V_16 )
V_15 |= V_17 ;
if ( V_4 & V_18 )
V_15 |= V_19 ;
if ( ! ( V_4 & V_20 ) )
V_15 |= V_21 ;
return V_15 ;
}
void F_14 ( struct V_1 * V_2 , unsigned V_12 ,
T_2 V_22 )
{
void T_3 * V_23 = V_2 -> V_24 . V_23 ;
F_15 ( V_22 , ( ( void T_3 * ) V_23 ) + ( V_12 * 4 ) ) ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_24 . V_25 ) {
F_17 ( 1 , L_1 ) ;
return 0 ;
}
V_5 = F_18 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_19 ( V_2 ) ;
if ( V_5 )
F_20 ( L_2 ) ;
V_2 -> V_24 . V_26 = V_2 -> V_24 . V_27 * 4 ;
V_2 -> V_28 -> V_24 . V_29 = & F_7 ;
V_2 -> V_28 -> V_24 . V_30 = & F_11 ;
V_2 -> V_28 -> V_24 . V_31 = & F_14 ;
return F_21 ( V_2 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
T_1 V_32 ;
T_1 V_11 ;
int V_5 ;
if ( V_2 -> V_24 . V_25 == NULL ) {
F_23 ( V_2 -> V_33 , L_3 ) ;
return - V_34 ;
}
V_5 = F_24 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_11 = V_35 ;
F_9 ( V_13 , V_11 ) ;
F_9 ( V_36 , V_2 -> V_37 . V_38 ) ;
V_11 = V_2 -> V_37 . V_39 & ~ V_40 ;
F_9 ( V_41 , V_11 ) ;
F_9 ( V_42 , 0 ) ;
F_9 ( V_43 , 0 ) ;
V_32 = V_2 -> V_24 . V_32 ;
F_9 ( V_44 , V_32 ) ;
F_9 ( V_45 , V_2 -> V_37 . V_46 ) ;
F_9 ( V_47 , 0 ) ;
F_9 ( V_48 , 0 ) ;
V_11 = F_8 ( V_13 ) ;
V_11 |= V_49 ;
V_11 |= V_35 ;
F_9 ( V_13 , V_11 ) ;
F_7 ( V_2 ) ;
F_25 ( L_4 ,
( unsigned ) ( V_2 -> V_37 . V_50 >> 20 ) ,
( unsigned long long ) V_32 ) ;
V_2 -> V_24 . V_51 = true ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
T_4 V_11 ;
F_9 ( V_36 , 0 ) ;
F_9 ( V_41 , 0 ) ;
F_9 ( V_42 , 0 ) ;
F_9 ( V_43 , 0 ) ;
V_11 = F_8 ( V_13 ) ;
V_11 |= V_35 ;
F_9 ( V_13 , V_11 & ~ V_49 ) ;
F_27 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
F_26 ( V_2 ) ;
F_30 ( V_2 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = & V_2 -> V_55 [ V_53 -> V_55 ] ;
F_32 ( V_55 , F_33 ( V_56 , 0 ) ) ;
F_32 ( V_55 , 0 ) ;
F_32 ( V_55 , F_33 ( V_57 , 0 ) ) ;
F_32 ( V_55 , 0 ) ;
F_32 ( V_55 , F_33 ( V_58 , 0 ) ) ;
F_32 ( V_55 , V_59 ) ;
F_32 ( V_55 , F_33 ( V_60 , 0 ) ) ;
F_32 ( V_55 , V_61 ) ;
F_32 ( V_55 , F_33 ( V_62 , 0 ) ) ;
F_32 ( V_55 , ( V_63 |
V_64 |
V_65 ) ) ;
F_32 ( V_55 , F_33 ( V_66 , 0 ) ) ;
F_32 ( V_55 , V_2 -> V_67 . V_68 . V_69 |
V_70 ) ;
F_32 ( V_55 , F_33 ( V_66 , 0 ) ) ;
F_32 ( V_55 , V_2 -> V_67 . V_68 . V_69 ) ;
F_32 ( V_55 , F_33 ( V_2 -> V_71 [ V_53 -> V_55 ] . V_72 , 0 ) ) ;
F_32 ( V_55 , V_53 -> V_73 ) ;
F_32 ( V_55 , F_33 ( V_74 , 0 ) ) ;
F_32 ( V_55 , V_75 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
unsigned V_76 ;
int V_5 ;
V_76 = ( V_77 | V_78 ) ;
switch( V_2 -> V_79 ) {
case 2 :
V_76 |= V_80 ;
break;
case 3 :
V_76 |= V_81 ;
break;
case 4 :
V_76 |= V_82 ;
break;
case 1 :
default:
V_76 |= V_83 ;
break;
}
V_5 = F_35 ( V_2 , V_55 , 64 ) ;
if ( V_5 ) {
return;
}
F_32 ( V_55 , F_33 ( V_84 , 0 ) ) ;
F_32 ( V_55 ,
V_85 |
V_86 |
V_87 |
V_88 ) ;
F_32 ( V_55 , F_33 ( V_89 , 0 ) ) ;
F_32 ( V_55 , V_76 ) ;
F_32 ( V_55 , F_33 ( V_62 , 0 ) ) ;
F_32 ( V_55 ,
V_64 |
V_63 ) ;
F_32 ( V_55 , F_33 ( V_90 , 0 ) ) ;
F_32 ( V_55 , V_91 ) ;
F_32 ( V_55 , F_33 ( V_92 , 0 ) ) ;
F_32 ( V_55 , 0 ) ;
F_32 ( V_55 , F_33 ( V_93 , 0 ) ) ;
F_32 ( V_55 , 0 ) ;
F_32 ( V_55 , F_33 ( V_58 , 0 ) ) ;
F_32 ( V_55 , V_59 | V_94 ) ;
F_32 ( V_55 , F_33 ( V_60 , 0 ) ) ;
F_32 ( V_55 , V_61 | V_95 ) ;
F_32 ( V_55 , F_33 ( V_62 , 0 ) ) ;
F_32 ( V_55 ,
V_64 |
V_63 ) ;
F_32 ( V_55 , F_33 ( V_96 , 0 ) ) ;
F_32 ( V_55 , 0 ) ;
F_32 ( V_55 , F_33 ( V_58 , 0 ) ) ;
F_32 ( V_55 , V_59 | V_94 ) ;
F_32 ( V_55 , F_33 ( V_60 , 0 ) ) ;
F_32 ( V_55 , V_61 | V_95 ) ;
F_32 ( V_55 , F_33 ( V_97 , 0 ) ) ;
F_32 ( V_55 ,
( ( 6 << V_98 ) |
( 6 << V_99 ) |
( 6 << V_100 ) |
( 6 << V_101 ) |
( 6 << V_102 ) |
( 6 << V_103 ) |
( 6 << V_104 ) |
( 6 << V_105 ) ) ) ;
F_32 ( V_55 , F_33 ( V_106 , 0 ) ) ;
F_32 ( V_55 ,
( ( 6 << V_107 ) |
( 6 << V_108 ) |
( 6 << V_109 ) |
( 6 << V_110 ) |
( 6 << V_111 ) |
( 6 << V_112 ) |
( 6 << V_113 ) ) ) ;
F_32 ( V_55 , F_33 ( V_114 , 0 ) ) ;
F_32 ( V_55 , V_115 | V_116 ) ;
F_32 ( V_55 , F_33 ( V_117 , 0 ) ) ;
F_32 ( V_55 ,
V_118 | V_119 ) ;
F_32 ( V_55 , F_33 ( V_120 , 0 ) ) ;
F_32 ( V_55 ,
V_121 |
V_122 ) ;
F_36 ( V_2 , V_55 , false ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_123 = 0 ;
if ( V_2 -> V_124 == V_125 &&
( F_4 ( V_126 ) & V_127 ) == V_128 ) {
V_2 -> V_123 |= V_129 ;
}
}
int F_38 ( struct V_1 * V_2 )
{
unsigned V_12 ;
T_1 V_11 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_130 ; V_12 ++ ) {
V_11 = F_4 ( V_131 ) ;
if ( V_11 & V_132 ) {
return 0 ;
}
F_39 ( 1 ) ;
}
return - 1 ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_76 , V_11 ;
if ( ( V_2 -> V_124 == V_125 && V_2 -> V_133 -> V_134 != 0x4144 ) ||
( V_2 -> V_124 == V_135 && V_2 -> V_133 -> V_134 != 0x4148 ) ) {
V_2 -> V_79 = 2 ;
} else {
V_2 -> V_79 = 1 ;
}
V_2 -> V_136 = 1 ;
V_76 = ( V_77 | V_78 ) ;
switch ( V_2 -> V_79 ) {
case 2 :
V_76 |= V_80 ;
break;
case 3 :
V_76 |= V_81 ;
break;
case 4 :
V_76 |= V_82 ;
break;
default:
case 1 :
V_76 |= V_83 ;
break;
}
F_3 ( V_89 , V_76 ) ;
if ( F_41 ( V_2 ) ) {
F_42 ( L_5 ) ;
}
V_11 = F_4 ( V_90 ) ;
F_3 ( V_90 , V_11 | V_91 ) ;
F_3 ( V_137 ,
V_138 |
V_139 ) ;
if ( F_41 ( V_2 ) ) {
F_42 ( L_5 ) ;
}
if ( F_38 ( V_2 ) ) {
F_42 ( L_6 ) ;
}
F_25 ( L_7 ,
V_2 -> V_79 , V_2 -> V_136 ) ;
}
int F_43 ( struct V_1 * V_2 , bool V_140 )
{
struct V_141 V_142 ;
T_4 V_143 , V_11 ;
int V_144 = 0 ;
V_143 = F_4 ( V_145 ) ;
if ( ! F_44 ( V_143 ) ) {
return 0 ;
}
F_45 ( V_2 , & V_142 ) ;
V_143 = F_4 ( V_145 ) ;
F_46 ( V_2 -> V_33 , L_8 , V_146 , __LINE__ , V_143 ) ;
F_3 ( V_147 , 0 ) ;
V_11 = F_4 ( V_148 ) ;
F_3 ( V_148 , V_11 | V_149 ) ;
F_3 ( V_150 , 0 ) ;
F_3 ( V_151 , 0 ) ;
F_3 ( V_148 , V_11 ) ;
F_47 ( V_2 -> V_133 ) ;
F_48 ( V_2 ) ;
F_3 ( V_152 , F_49 ( 1 ) |
F_50 ( 1 ) ) ;
F_4 ( V_152 ) ;
F_51 ( 500 ) ;
F_3 ( V_152 , 0 ) ;
F_51 ( 1 ) ;
V_143 = F_4 ( V_145 ) ;
F_46 ( V_2 -> V_33 , L_8 , V_146 , __LINE__ , V_143 ) ;
F_3 ( V_152 , F_52 ( 1 ) ) ;
F_4 ( V_152 ) ;
F_51 ( 500 ) ;
F_3 ( V_152 , 0 ) ;
F_51 ( 1 ) ;
V_143 = F_4 ( V_145 ) ;
F_46 ( V_2 -> V_33 , L_8 , V_146 , __LINE__ , V_143 ) ;
F_53 ( V_2 -> V_133 ) ;
F_54 ( V_2 ) ;
if ( F_55 ( V_143 ) || F_56 ( V_143 ) ) {
F_23 ( V_2 -> V_33 , L_9 ) ;
V_144 = - 1 ;
} else
F_46 ( V_2 -> V_33 , L_10 ) ;
F_57 ( V_2 , & V_142 ) ;
return V_144 ;
}
void F_58 ( struct V_1 * V_2 )
{
T_5 V_153 ;
T_4 V_11 ;
V_2 -> V_37 . V_154 = true ;
V_11 = F_4 ( V_155 ) ;
V_11 &= V_156 ;
switch ( V_11 ) {
case 0 : V_2 -> V_37 . V_157 = 64 ; break;
case 1 : V_2 -> V_37 . V_157 = 128 ; break;
case 2 : V_2 -> V_37 . V_157 = 256 ; break;
default: V_2 -> V_37 . V_157 = 128 ; break;
}
F_59 ( V_2 ) ;
V_153 = V_2 -> V_37 . V_158 ;
if ( V_2 -> V_4 & V_159 )
V_153 = ( F_4 ( V_160 ) & 0xffff ) << 16 ;
F_60 ( V_2 , & V_2 -> V_37 , V_153 ) ;
V_2 -> V_37 . V_161 = 0 ;
if ( ! ( V_2 -> V_4 & V_162 ) )
F_61 ( V_2 , & V_2 -> V_37 ) ;
F_62 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 , int V_163 )
{
T_1 V_164 , V_165 ;
if ( V_2 -> V_4 & V_159 )
return;
if ( ! ( V_2 -> V_4 & V_166 ) )
return;
switch ( V_163 ) {
case 0 :
V_165 = V_167 ;
break;
case 1 :
V_165 = V_168 ;
break;
case 2 :
V_165 = V_169 ;
break;
case 4 :
V_165 = V_170 ;
break;
case 8 :
V_165 = V_171 ;
break;
case 12 :
V_165 = V_172 ;
break;
case 16 :
default:
V_165 = V_173 ;
break;
}
V_164 = F_8 ( V_174 ) ;
if ( ( V_164 & V_175 ) ==
( V_165 << V_176 ) )
return;
V_164 &= ~ ( V_177 |
V_178 |
V_179 |
V_180 ) ;
V_164 |= V_165 ;
F_9 ( V_174 , V_164 ) ;
F_9 ( V_174 , ( V_164 |
V_178 ) ) ;
V_164 = F_8 ( V_174 ) ;
while ( V_164 == 0xffffffff )
V_164 = F_8 ( V_174 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
T_4 V_164 ;
if ( V_2 -> V_4 & V_159 )
return 0 ;
if ( ! ( V_2 -> V_4 & V_166 ) )
return 0 ;
V_164 = F_8 ( V_174 ) ;
switch ( ( V_164 & V_175 ) >> V_176 ) {
case V_167 :
return 0 ;
case V_168 :
return 1 ;
case V_169 :
return 2 ;
case V_170 :
return 4 ;
case V_171 :
return 8 ;
case V_173 :
default:
return 16 ;
}
}
static int F_65 ( struct V_181 * V_182 , void * V_183 )
{
struct V_184 * V_185 = (struct V_184 * ) V_182 -> V_186 ;
struct V_187 * V_33 = V_185 -> V_188 -> V_33 ;
struct V_1 * V_2 = V_33 -> V_189 ;
T_1 V_11 ;
V_11 = F_8 ( V_13 ) ;
F_66 ( V_182 , L_11 , V_11 ) ;
V_11 = F_8 ( V_44 ) ;
F_66 ( V_182 , L_12 , V_11 ) ;
V_11 = F_8 ( V_36 ) ;
F_66 ( V_182 , L_13 , V_11 ) ;
V_11 = F_8 ( V_42 ) ;
F_66 ( V_182 , L_14 , V_11 ) ;
V_11 = F_8 ( V_41 ) ;
F_66 ( V_182 , L_15 , V_11 ) ;
V_11 = F_8 ( V_43 ) ;
F_66 ( V_182 , L_16 , V_11 ) ;
V_11 = F_8 ( V_48 ) ;
F_66 ( V_182 , L_17 , V_11 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
#if F_67 ( V_190 )
return F_68 ( V_2 , V_191 , 1 ) ;
#else
return 0 ;
#endif
}
static int F_69 ( struct V_192 * V_193 ,
struct V_194 * V_195 ,
unsigned V_196 , unsigned V_3 )
{
struct V_197 * V_198 ;
struct V_199 * V_200 ;
volatile T_1 * V_201 ;
T_1 V_11 , V_202 = 0 ;
unsigned V_12 ;
int V_5 ;
T_4 V_203 ;
V_201 = V_193 -> V_201 . V_23 ;
V_200 = (struct V_199 * ) V_193 -> V_200 ;
V_203 = F_70 ( V_193 , V_196 ) ;
switch( V_3 ) {
case V_204 :
case V_205 :
V_5 = F_71 ( V_193 ) ;
if ( V_5 ) {
F_20 ( L_18 ,
V_196 , V_3 ) ;
F_72 ( V_193 , V_195 ) ;
return V_5 ;
}
break;
case V_206 :
case V_207 :
V_5 = F_73 ( V_193 , V_195 , V_196 , V_3 ) ;
if ( V_5 )
return V_5 ;
break;
case V_208 :
case V_209 :
case V_210 :
case V_211 :
V_12 = ( V_3 - V_208 ) >> 2 ;
V_5 = F_74 ( V_193 , & V_198 , 0 ) ;
if ( V_5 ) {
F_20 ( L_18 ,
V_196 , V_3 ) ;
F_72 ( V_193 , V_195 ) ;
return V_5 ;
}
V_200 -> V_212 [ V_12 ] . V_25 = V_198 -> V_25 ;
V_200 -> V_212 [ V_12 ] . V_213 = V_203 ;
V_200 -> V_214 = true ;
V_201 [ V_196 ] = V_203 + ( ( T_4 ) V_198 -> V_215 ) ;
break;
case V_216 :
V_5 = F_74 ( V_193 , & V_198 , 0 ) ;
if ( V_5 ) {
F_20 ( L_18 ,
V_196 , V_3 ) ;
F_72 ( V_193 , V_195 ) ;
return V_5 ;
}
V_200 -> V_217 . V_25 = V_198 -> V_25 ;
V_200 -> V_217 . V_213 = V_203 ;
V_200 -> V_218 = true ;
V_201 [ V_196 ] = V_203 + ( ( T_4 ) V_198 -> V_215 ) ;
break;
case V_219 :
case V_219 + 4 :
case V_219 + 8 :
case V_219 + 12 :
case V_219 + 16 :
case V_219 + 20 :
case V_219 + 24 :
case V_219 + 28 :
case V_219 + 32 :
case V_219 + 36 :
case V_219 + 40 :
case V_219 + 44 :
case V_219 + 48 :
case V_219 + 52 :
case V_219 + 56 :
case V_219 + 60 :
V_12 = ( V_3 - V_219 ) >> 2 ;
V_5 = F_74 ( V_193 , & V_198 , 0 ) ;
if ( V_5 ) {
F_20 ( L_18 ,
V_196 , V_3 ) ;
F_72 ( V_193 , V_195 ) ;
return V_5 ;
}
if ( V_193 -> V_220 & V_221 ) {
V_201 [ V_196 ] = ( V_203 & 31 ) |
( ( V_203 & ~ 31 ) + ( T_4 ) V_198 -> V_215 ) ;
} else {
if ( V_198 -> V_222 & V_223 )
V_202 |= V_224 ;
if ( V_198 -> V_222 & V_225 )
V_202 |= V_226 ;
else if ( V_198 -> V_222 & V_227 )
V_202 |= V_228 ;
V_11 = V_203 + ( ( T_4 ) V_198 -> V_215 ) ;
V_11 |= V_202 ;
V_201 [ V_196 ] = V_11 ;
}
V_200 -> V_229 [ V_12 ] . V_25 = V_198 -> V_25 ;
V_200 -> V_230 = true ;
break;
case 0x2084 :
V_200 -> V_231 = V_203 ;
break;
case 0x20B4 :
V_200 -> V_232 = V_203 & 0x7F ;
break;
case 0x2134 :
V_200 -> V_233 = V_203 & 0x00FFFFFFUL ;
break;
case 0x2088 :
if ( V_193 -> V_2 -> V_124 < V_234 )
goto V_235;
V_200 -> V_236 = V_203 & 0xFFFFFF ;
break;
case 0x43E4 :
V_200 -> V_237 = ( ( V_203 >> 13 ) & 0x1FFF ) + 1 ;
if ( V_193 -> V_2 -> V_124 < V_234 ) {
V_200 -> V_237 -= 1440 ;
}
V_200 -> V_214 = true ;
V_200 -> V_218 = true ;
break;
case 0x4E00 :
if ( ( V_203 & ( 1 << 10 ) ) &&
V_193 -> V_2 -> V_238 != V_193 -> V_239 ) {
F_20 ( L_19 ) ;
return - V_34 ;
}
V_200 -> V_240 = ( ( V_203 >> 5 ) & 0x3 ) + 1 ;
V_200 -> V_214 = true ;
break;
case 0x4E38 :
case 0x4E3C :
case 0x4E40 :
case 0x4E44 :
if ( ! ( V_193 -> V_220 & V_221 ) ) {
V_5 = F_74 ( V_193 , & V_198 , 0 ) ;
if ( V_5 ) {
F_20 ( L_18 ,
V_196 , V_3 ) ;
F_72 ( V_193 , V_195 ) ;
return V_5 ;
}
if ( V_198 -> V_222 & V_223 )
V_202 |= V_241 ;
if ( V_198 -> V_222 & V_225 )
V_202 |= V_242 ;
else if ( V_198 -> V_222 & V_227 )
V_202 |= V_243 ;
V_11 = V_203 & ~ ( 0x7 << 16 ) ;
V_11 |= V_202 ;
V_201 [ V_196 ] = V_11 ;
}
V_12 = ( V_3 - 0x4E38 ) >> 2 ;
V_200 -> V_212 [ V_12 ] . V_244 = V_203 & 0x3FFE ;
switch ( ( ( V_203 >> 21 ) & 0xF ) ) {
case 9 :
case 11 :
case 12 :
V_200 -> V_212 [ V_12 ] . V_245 = 1 ;
break;
case 3 :
case 4 :
case 13 :
case 15 :
V_200 -> V_212 [ V_12 ] . V_245 = 2 ;
break;
case 5 :
if ( V_193 -> V_2 -> V_124 < V_234 ) {
F_20 ( L_20 ,
( ( V_203 >> 21 ) & 0xF ) ) ;
return - V_34 ;
}
case 6 :
V_200 -> V_212 [ V_12 ] . V_245 = 4 ;
break;
case 10 :
V_200 -> V_212 [ V_12 ] . V_245 = 8 ;
break;
case 7 :
V_200 -> V_212 [ V_12 ] . V_245 = 16 ;
break;
default:
F_20 ( L_21 ,
( ( V_203 >> 21 ) & 0xF ) ) ;
return - V_34 ;
}
V_200 -> V_214 = true ;
break;
case 0x4F00 :
if ( V_203 & 2 ) {
V_200 -> V_246 = true ;
} else {
V_200 -> V_246 = false ;
}
V_200 -> V_218 = true ;
break;
case 0x4F10 :
switch ( ( V_203 & 0xF ) ) {
case 0 :
case 1 :
V_200 -> V_217 . V_245 = 2 ;
break;
case 2 :
V_200 -> V_217 . V_245 = 4 ;
break;
default:
F_20 ( L_22 ,
( V_203 & 0xF ) ) ;
return - V_34 ;
}
V_200 -> V_218 = true ;
break;
case 0x4F24 :
if ( ! ( V_193 -> V_220 & V_221 ) ) {
V_5 = F_74 ( V_193 , & V_198 , 0 ) ;
if ( V_5 ) {
F_20 ( L_18 ,
V_196 , V_3 ) ;
F_72 ( V_193 , V_195 ) ;
return V_5 ;
}
if ( V_198 -> V_222 & V_223 )
V_202 |= V_247 ;
if ( V_198 -> V_222 & V_225 )
V_202 |= V_248 ;
else if ( V_198 -> V_222 & V_227 )
V_202 |= V_249 ;
V_11 = V_203 & ~ ( 0x7 << 16 ) ;
V_11 |= V_202 ;
V_201 [ V_196 ] = V_11 ;
}
V_200 -> V_217 . V_244 = V_203 & 0x3FFC ;
V_200 -> V_218 = true ;
break;
case 0x4104 :
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
bool V_250 ;
V_250 = ! ! ( V_203 & ( 1 << V_12 ) ) ;
V_200 -> V_229 [ V_12 ] . V_250 = V_250 ;
}
V_200 -> V_230 = true ;
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
V_12 = ( V_3 - 0x44C0 ) >> 2 ;
V_11 = ( V_203 >> 25 ) & 0x3 ;
V_200 -> V_229 [ V_12 ] . V_251 = V_11 ;
switch ( ( V_203 & 0x1F ) ) {
case V_252 :
case V_253 :
case V_254 :
V_200 -> V_229 [ V_12 ] . V_245 = 1 ;
V_200 -> V_229 [ V_12 ] . V_255 = V_256 ;
break;
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
V_200 -> V_229 [ V_12 ] . V_245 = 2 ;
V_200 -> V_229 [ V_12 ] . V_255 = V_256 ;
break;
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case 0x17 :
case V_273 :
case 0x1e :
V_200 -> V_229 [ V_12 ] . V_245 = 4 ;
V_200 -> V_229 [ V_12 ] . V_255 = V_256 ;
break;
case V_274 :
case V_275 :
case V_276 :
V_200 -> V_229 [ V_12 ] . V_245 = 8 ;
V_200 -> V_229 [ V_12 ] . V_255 = V_256 ;
break;
case V_277 :
V_200 -> V_229 [ V_12 ] . V_245 = 16 ;
V_200 -> V_229 [ V_12 ] . V_255 = V_256 ;
break;
case V_278 :
V_200 -> V_229 [ V_12 ] . V_245 = 1 ;
V_200 -> V_229 [ V_12 ] . V_255 = V_279 ;
break;
case V_280 :
if ( V_193 -> V_2 -> V_124 < V_281 ) {
F_20 ( L_23 ,
( V_203 & 0x1F ) ) ;
return - V_34 ;
}
case V_282 :
case V_283 :
V_200 -> V_229 [ V_12 ] . V_245 = 1 ;
V_200 -> V_229 [ V_12 ] . V_255 = V_284 ;
break;
default:
F_20 ( L_23 ,
( V_203 & 0x1F ) ) ;
return - V_34 ;
}
V_200 -> V_230 = true ;
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
V_12 = ( V_3 - 0x4400 ) >> 2 ;
V_11 = V_203 & 0x7 ;
if ( V_11 == 2 || V_11 == 4 || V_11 == 6 ) {
V_200 -> V_229 [ V_12 ] . V_285 = false ;
}
V_11 = ( V_203 >> 3 ) & 0x7 ;
if ( V_11 == 2 || V_11 == 4 || V_11 == 6 ) {
V_200 -> V_229 [ V_12 ] . V_286 = false ;
}
V_200 -> V_230 = true ;
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
V_12 = ( V_3 - 0x4500 ) >> 2 ;
V_11 = V_203 & 0x3FFF ;
V_200 -> V_229 [ V_12 ] . V_244 = V_11 + 1 ;
if ( V_193 -> V_2 -> V_124 >= V_234 ) {
V_11 = ( ( V_203 >> 15 ) & 1 ) << 11 ;
V_200 -> V_229 [ V_12 ] . V_287 = V_11 ;
V_11 = ( ( V_203 >> 16 ) & 1 ) << 11 ;
V_200 -> V_229 [ V_12 ] . V_288 = V_11 ;
if ( V_203 & ( 1 << 14 ) ) {
V_200 -> V_229 [ V_12 ] . V_255 =
V_279 ;
}
} else if ( V_203 & ( 1 << 14 ) ) {
F_20 ( L_24 ) ;
return - V_34 ;
}
V_200 -> V_230 = true ;
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
V_12 = ( V_3 - 0x4480 ) >> 2 ;
V_11 = V_203 & 0x7FF ;
V_200 -> V_229 [ V_12 ] . V_289 = V_11 + 1 ;
V_11 = ( V_203 >> 11 ) & 0x7FF ;
V_200 -> V_229 [ V_12 ] . V_290 = V_11 + 1 ;
V_11 = ( V_203 >> 26 ) & 0xF ;
V_200 -> V_229 [ V_12 ] . V_291 = V_11 ;
V_11 = V_203 & ( 1 << 31 ) ;
V_200 -> V_229 [ V_12 ] . V_292 = ! ! V_11 ;
V_11 = ( V_203 >> 22 ) & 0xF ;
V_200 -> V_229 [ V_12 ] . V_293 = V_11 ;
V_200 -> V_230 = true ;
break;
case V_294 :
V_5 = F_74 ( V_193 , & V_198 , 0 ) ;
if ( V_5 ) {
F_20 ( L_18 ,
V_196 , V_3 ) ;
F_72 ( V_193 , V_195 ) ;
return V_5 ;
}
V_201 [ V_196 ] = V_203 + ( ( T_4 ) V_198 -> V_215 ) ;
break;
case 0x4e0c :
V_200 -> V_295 = V_203 ;
V_200 -> V_214 = true ;
break;
case 0x43a4 :
if ( V_193 -> V_2 -> V_296 != V_193 -> V_239 ) {
if ( V_203 & 0x1 )
V_201 [ V_196 ] = V_203 & ~ 1 ;
}
break;
case 0x4f1c :
V_200 -> V_297 = ! ! ( V_203 & ( 1 << 5 ) ) ;
V_200 -> V_214 = true ;
V_200 -> V_218 = true ;
if ( V_193 -> V_2 -> V_296 != V_193 -> V_239 ) {
if ( V_203 & ( V_298 |
V_299 |
V_300 |
V_301 ) )
goto V_235;
}
break;
case 0x4e04 :
V_200 -> V_302 = ! ! ( V_203 & ( 1 << 2 ) ) ;
V_200 -> V_214 = true ;
break;
case V_303 :
V_5 = F_74 ( V_193 , & V_198 , 0 ) ;
if ( V_5 ) {
F_20 ( L_18 ,
V_196 , V_3 ) ;
F_72 ( V_193 , V_195 ) ;
return V_5 ;
}
V_200 -> V_304 . V_25 = V_198 -> V_25 ;
V_200 -> V_304 . V_213 = V_203 ;
V_200 -> V_305 = true ;
V_201 [ V_196 ] = V_203 + ( ( T_4 ) V_198 -> V_215 ) ;
break;
case V_306 :
V_200 -> V_304 . V_244 = V_203 & 0x3FFE ;
V_200 -> V_305 = true ;
break;
case V_307 :
V_200 -> V_308 = V_203 & 0x1 ;
V_200 -> V_305 = true ;
break;
case 0x4f30 :
case 0x4f34 :
case 0x4f44 :
case 0x4f54 :
if ( V_203 && ( V_193 -> V_2 -> V_296 != V_193 -> V_239 ) )
goto V_235;
break;
case 0x4028 :
if ( V_203 && ( V_193 -> V_2 -> V_296 != V_193 -> V_239 ) )
goto V_235;
if ( V_193 -> V_2 -> V_124 >= V_309 )
break;
goto V_235;
break;
case 0x4be8 :
if ( V_193 -> V_2 -> V_124 == V_310 )
break;
default:
goto V_235;
}
return 0 ;
V_235:
F_75 ( L_25 ,
V_3 , V_196 , V_203 ) ;
return - V_34 ;
}
static int F_76 ( struct V_192 * V_193 ,
struct V_194 * V_195 )
{
struct V_197 * V_198 ;
struct V_199 * V_200 ;
volatile T_1 * V_201 ;
unsigned V_196 ;
int V_5 ;
V_201 = V_193 -> V_201 . V_23 ;
V_196 = V_195 -> V_196 + 1 ;
V_200 = (struct V_199 * ) V_193 -> V_200 ;
switch( V_195 -> V_311 ) {
case V_312 :
V_5 = F_77 ( V_193 , V_195 , V_196 ) ;
if ( V_5 )
return V_5 ;
break;
case V_313 :
V_5 = F_74 ( V_193 , & V_198 , 0 ) ;
if ( V_5 ) {
F_20 ( L_26 , V_195 -> V_311 ) ;
F_72 ( V_193 , V_195 ) ;
return V_5 ;
}
V_201 [ V_196 + 1 ] = F_70 ( V_193 , V_196 + 1 ) + ( ( T_4 ) V_198 -> V_215 ) ;
V_5 = F_78 ( V_193 , V_195 , V_198 -> V_25 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_314 :
if ( ( ( F_70 ( V_193 , V_196 + 1 ) >> 4 ) & 0x3 ) != 3 ) {
F_20 ( L_27 ) ;
return - V_34 ;
}
V_200 -> V_231 = F_70 ( V_193 , V_196 + 1 ) ;
V_200 -> V_315 = V_195 -> V_316 - 1 ;
V_5 = F_79 ( V_193 -> V_2 , V_200 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_317 :
if ( ( ( F_70 ( V_193 , V_196 ) >> 4 ) & 0x3 ) != 3 ) {
F_20 ( L_27 ) ;
return - V_34 ;
}
V_200 -> V_231 = F_70 ( V_193 , V_196 ) ;
V_200 -> V_315 = V_195 -> V_316 ;
V_5 = F_79 ( V_193 -> V_2 , V_200 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_318 :
V_200 -> V_231 = F_70 ( V_193 , V_196 + 1 ) ;
V_5 = F_79 ( V_193 -> V_2 , V_200 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_319 :
V_200 -> V_231 = F_70 ( V_193 , V_196 ) ;
V_5 = F_79 ( V_193 -> V_2 , V_200 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_320 :
V_200 -> V_231 = F_70 ( V_193 , V_196 + 1 ) ;
V_5 = F_79 ( V_193 -> V_2 , V_200 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_321 :
V_200 -> V_231 = F_70 ( V_193 , V_196 ) ;
V_5 = F_79 ( V_193 -> V_2 , V_200 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_322 :
case V_323 :
if ( V_193 -> V_2 -> V_296 != V_193 -> V_239 )
return - V_34 ;
break;
case V_324 :
if ( V_193 -> V_2 -> V_238 != V_193 -> V_239 )
return - V_34 ;
break;
case V_325 :
break;
default:
F_20 ( L_28 , V_195 -> V_311 ) ;
return - V_34 ;
}
return 0 ;
}
int F_80 ( struct V_192 * V_193 )
{
struct V_194 V_195 ;
struct V_199 * V_200 ;
int V_5 ;
V_200 = F_81 ( sizeof( * V_200 ) , V_326 ) ;
if ( V_200 == NULL )
return - V_327 ;
F_82 ( V_193 -> V_2 , V_200 ) ;
V_193 -> V_200 = V_200 ;
do {
V_5 = F_83 ( V_193 , & V_195 , V_193 -> V_196 ) ;
if ( V_5 ) {
return V_5 ;
}
V_193 -> V_196 += V_195 . V_316 + 2 ;
switch ( V_195 . type ) {
case V_328 :
V_5 = F_84 ( V_193 , & V_195 ,
V_193 -> V_2 -> V_67 . V_68 . V_329 ,
V_193 -> V_2 -> V_67 . V_68 . V_330 ,
& F_69 ) ;
break;
case V_331 :
break;
case V_332 :
V_5 = F_76 ( V_193 , & V_195 ) ;
break;
default:
F_20 ( L_29 , V_195 . type ) ;
return - V_34 ;
}
if ( V_5 ) {
return V_5 ;
}
} while ( V_193 -> V_196 < V_193 -> V_333 -> V_334 );
return 0 ;
}
void F_85 ( struct V_1 * V_2 )
{
V_2 -> V_67 . V_68 . V_329 = V_335 ;
V_2 -> V_67 . V_68 . V_330 = F_86 ( V_335 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_141 V_142 ;
int V_5 ;
V_5 = F_88 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_30 ) ;
}
F_45 ( V_2 , & V_142 ) ;
if ( V_2 -> V_4 & V_162 ) {
F_3 ( V_336 ,
F_89 ( V_2 -> V_37 . V_38 >> 16 ) |
F_90 ( V_2 -> V_37 . V_39 >> 16 ) ) ;
F_3 ( V_337 , F_12 ( V_2 -> V_37 . V_338 ) ) ;
F_3 ( V_339 ,
F_13 ( V_2 -> V_37 . V_338 ) & 0xff ) ;
} else {
F_3 ( V_336 , 0x0FFFFFFF ) ;
F_3 ( V_337 , 0 ) ;
F_3 ( V_339 , 0 ) ;
}
if ( F_38 ( V_2 ) )
F_25 ( L_31 ) ;
F_3 ( V_340 ,
F_91 ( V_2 -> V_37 . V_46 >> 16 ) |
F_92 ( V_2 -> V_37 . V_341 >> 16 ) ) ;
F_57 ( V_2 , & V_142 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
T_4 V_11 ;
if ( V_342 != - 1 && V_342 )
F_94 ( V_2 , 1 ) ;
V_11 = F_95 ( V_343 ) ;
V_11 |= F_96 ( 1 ) | F_97 ( 1 ) ;
if ( ( V_2 -> V_124 == V_309 ) || ( V_2 -> V_124 == V_344 ) )
V_11 |= F_98 ( 1 ) ;
F_99 ( V_343 , V_11 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_5 ;
F_101 ( V_2 ) ;
F_87 ( V_2 ) ;
F_93 ( V_2 ) ;
F_40 ( V_2 ) ;
if ( V_2 -> V_4 & V_166 ) {
V_5 = F_22 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_2 -> V_124 == V_125 ||
V_2 -> V_124 == V_135 ||
V_2 -> V_124 == V_309 )
F_54 ( V_2 ) ;
if ( V_2 -> V_4 & V_345 ) {
V_5 = F_102 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
V_5 = F_103 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_104 ( V_2 , V_346 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_32 , V_5 ) ;
return V_5 ;
}
if ( ! V_2 -> V_347 . V_348 ) {
V_5 = F_105 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
F_106 ( V_2 ) ;
V_2 -> V_67 . V_68 . V_69 = F_4 ( V_66 ) ;
V_5 = F_107 ( V_2 , 1024 * 1024 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_33 , V_5 ) ;
return V_5 ;
}
V_5 = F_108 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_34 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
int F_109 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_4 & V_166 )
F_26 ( V_2 ) ;
if ( V_2 -> V_4 & V_345 )
F_110 ( V_2 ) ;
F_93 ( V_2 ) ;
if ( F_111 ( V_2 ) ) {
F_112 ( V_2 -> V_33 , L_35 ,
F_4 ( V_145 ) ,
F_4 ( V_349 ) ) ;
}
F_113 ( V_2 -> V_350 ) ;
F_93 ( V_2 ) ;
F_114 ( V_2 ) ;
V_2 -> V_351 = true ;
V_5 = F_100 ( V_2 ) ;
if ( V_5 ) {
V_2 -> V_351 = false ;
}
return V_5 ;
}
int F_115 ( struct V_1 * V_2 )
{
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
if ( V_2 -> V_4 & V_166 )
F_26 ( V_2 ) ;
if ( V_2 -> V_4 & V_345 )
F_110 ( V_2 ) ;
return 0 ;
}
void F_120 ( struct V_1 * V_2 )
{
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
if ( V_2 -> V_4 & V_166 )
F_28 ( V_2 ) ;
if ( V_2 -> V_4 & V_345 )
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 -> V_352 ) ;
V_2 -> V_352 = NULL ;
}
int F_133 ( struct V_1 * V_2 )
{
int V_5 ;
F_134 ( V_2 ) ;
F_135 ( V_2 ) ;
F_114 ( V_2 ) ;
F_136 ( V_2 ) ;
if ( ! F_137 ( V_2 ) ) {
if ( F_138 ( V_2 ) )
return - V_34 ;
}
if ( V_2 -> V_353 ) {
F_23 ( V_2 -> V_33 , L_36 ) ;
return - V_34 ;
} else {
V_5 = F_139 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
if ( F_111 ( V_2 ) ) {
F_112 ( V_2 -> V_33 ,
L_35 ,
F_4 ( V_145 ) ,
F_4 ( V_349 ) ) ;
}
if ( F_140 ( V_2 ) == false )
return - V_34 ;
F_37 ( V_2 ) ;
F_141 ( V_2 -> V_350 ) ;
if ( V_2 -> V_4 & V_162 ) {
V_5 = F_142 ( V_2 ) ;
if ( V_5 ) {
F_143 ( V_2 ) ;
}
}
F_58 ( V_2 ) ;
V_5 = F_144 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_145 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_4 & V_166 ) {
V_5 = F_16 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_2 -> V_4 & V_345 ) {
V_5 = F_146 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
F_85 ( V_2 ) ;
F_147 ( V_2 ) ;
V_2 -> V_351 = true ;
V_5 = F_100 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_37 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_128 ( V_2 ) ;
if ( V_2 -> V_4 & V_166 )
F_28 ( V_2 ) ;
if ( V_2 -> V_4 & V_345 )
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
V_2 -> V_351 = false ;
}
return 0 ;
}
