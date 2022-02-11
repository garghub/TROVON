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
F_42 ( V_137 L_5
L_6 ) ;
}
V_11 = F_4 ( V_90 ) ;
F_3 ( V_90 , V_11 | V_91 ) ;
F_3 ( V_138 ,
V_139 |
V_140 ) ;
if ( F_41 ( V_2 ) ) {
F_42 ( V_137 L_5
L_6 ) ;
}
if ( F_38 ( V_2 ) ) {
F_42 ( V_137 L_7
L_6 ) ;
}
F_25 ( L_8 ,
V_2 -> V_79 , V_2 -> V_136 ) ;
}
int F_43 ( struct V_1 * V_2 , bool V_141 )
{
struct V_142 V_143 ;
T_4 V_144 , V_11 ;
int V_145 = 0 ;
V_144 = F_4 ( V_146 ) ;
if ( ! F_44 ( V_144 ) ) {
return 0 ;
}
F_45 ( V_2 , & V_143 ) ;
V_144 = F_4 ( V_146 ) ;
F_46 ( V_2 -> V_33 , L_9 , V_147 , __LINE__ , V_144 ) ;
F_3 ( V_148 , 0 ) ;
V_11 = F_4 ( V_149 ) ;
F_3 ( V_149 , V_11 | V_150 ) ;
F_3 ( V_151 , 0 ) ;
F_3 ( V_152 , 0 ) ;
F_3 ( V_149 , V_11 ) ;
F_47 ( V_2 -> V_133 ) ;
F_48 ( V_2 ) ;
F_3 ( V_153 , F_49 ( 1 ) |
F_50 ( 1 ) ) ;
F_4 ( V_153 ) ;
F_51 ( 500 ) ;
F_3 ( V_153 , 0 ) ;
F_51 ( 1 ) ;
V_144 = F_4 ( V_146 ) ;
F_46 ( V_2 -> V_33 , L_9 , V_147 , __LINE__ , V_144 ) ;
F_3 ( V_153 , F_52 ( 1 ) ) ;
F_4 ( V_153 ) ;
F_51 ( 500 ) ;
F_3 ( V_153 , 0 ) ;
F_51 ( 1 ) ;
V_144 = F_4 ( V_146 ) ;
F_46 ( V_2 -> V_33 , L_9 , V_147 , __LINE__ , V_144 ) ;
F_53 ( V_2 -> V_133 ) ;
F_54 ( V_2 ) ;
if ( F_55 ( V_144 ) || F_56 ( V_144 ) ) {
F_23 ( V_2 -> V_33 , L_10 ) ;
V_145 = - 1 ;
} else
F_46 ( V_2 -> V_33 , L_11 ) ;
F_57 ( V_2 , & V_143 ) ;
return V_145 ;
}
void F_58 ( struct V_1 * V_2 )
{
T_5 V_154 ;
T_4 V_11 ;
V_2 -> V_37 . V_155 = true ;
V_11 = F_4 ( V_156 ) ;
V_11 &= V_157 ;
switch ( V_11 ) {
case 0 : V_2 -> V_37 . V_158 = 64 ; break;
case 1 : V_2 -> V_37 . V_158 = 128 ; break;
case 2 : V_2 -> V_37 . V_158 = 256 ; break;
default: V_2 -> V_37 . V_158 = 128 ; break;
}
F_59 ( V_2 ) ;
V_154 = V_2 -> V_37 . V_159 ;
if ( V_2 -> V_4 & V_160 )
V_154 = ( F_4 ( V_161 ) & 0xffff ) << 16 ;
F_60 ( V_2 , & V_2 -> V_37 , V_154 ) ;
V_2 -> V_37 . V_162 = 0 ;
if ( ! ( V_2 -> V_4 & V_163 ) )
F_61 ( V_2 , & V_2 -> V_37 ) ;
F_62 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 , int V_164 )
{
T_1 V_165 , V_166 ;
if ( V_2 -> V_4 & V_160 )
return;
if ( ! ( V_2 -> V_4 & V_167 ) )
return;
switch ( V_164 ) {
case 0 :
V_166 = V_168 ;
break;
case 1 :
V_166 = V_169 ;
break;
case 2 :
V_166 = V_170 ;
break;
case 4 :
V_166 = V_171 ;
break;
case 8 :
V_166 = V_172 ;
break;
case 12 :
V_166 = V_173 ;
break;
case 16 :
default:
V_166 = V_174 ;
break;
}
V_165 = F_8 ( V_175 ) ;
if ( ( V_165 & V_176 ) ==
( V_166 << V_177 ) )
return;
V_165 &= ~ ( V_178 |
V_179 |
V_180 |
V_181 ) ;
V_165 |= V_166 ;
F_9 ( V_175 , V_165 ) ;
F_9 ( V_175 , ( V_165 |
V_179 ) ) ;
V_165 = F_8 ( V_175 ) ;
while ( V_165 == 0xffffffff )
V_165 = F_8 ( V_175 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
T_4 V_165 ;
if ( V_2 -> V_4 & V_160 )
return 0 ;
if ( ! ( V_2 -> V_4 & V_167 ) )
return 0 ;
V_165 = F_8 ( V_175 ) ;
switch ( ( V_165 & V_176 ) >> V_177 ) {
case V_168 :
return 0 ;
case V_169 :
return 1 ;
case V_170 :
return 2 ;
case V_171 :
return 4 ;
case V_172 :
return 8 ;
case V_174 :
default:
return 16 ;
}
}
static int F_65 ( struct V_182 * V_183 , void * V_184 )
{
struct V_185 * V_186 = (struct V_185 * ) V_183 -> V_187 ;
struct V_188 * V_33 = V_186 -> V_189 -> V_33 ;
struct V_1 * V_2 = V_33 -> V_190 ;
T_1 V_11 ;
V_11 = F_8 ( V_13 ) ;
F_66 ( V_183 , L_12 , V_11 ) ;
V_11 = F_8 ( V_44 ) ;
F_66 ( V_183 , L_13 , V_11 ) ;
V_11 = F_8 ( V_36 ) ;
F_66 ( V_183 , L_14 , V_11 ) ;
V_11 = F_8 ( V_42 ) ;
F_66 ( V_183 , L_15 , V_11 ) ;
V_11 = F_8 ( V_41 ) ;
F_66 ( V_183 , L_16 , V_11 ) ;
V_11 = F_8 ( V_43 ) ;
F_66 ( V_183 , L_17 , V_11 ) ;
V_11 = F_8 ( V_48 ) ;
F_66 ( V_183 , L_18 , V_11 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
#if F_67 ( V_191 )
return F_68 ( V_2 , V_192 , 1 ) ;
#else
return 0 ;
#endif
}
static int F_69 ( struct V_193 * V_194 ,
struct V_195 * V_196 ,
unsigned V_197 , unsigned V_3 )
{
struct V_198 * V_199 ;
struct V_200 * V_201 ;
volatile T_1 * V_202 ;
T_1 V_11 , V_203 = 0 ;
unsigned V_12 ;
int V_5 ;
T_4 V_204 ;
V_202 = V_194 -> V_202 . V_23 ;
V_201 = (struct V_200 * ) V_194 -> V_201 ;
V_204 = F_70 ( V_194 , V_197 ) ;
switch( V_3 ) {
case V_205 :
case V_206 :
V_5 = F_71 ( V_194 ) ;
if ( V_5 ) {
F_20 ( L_19 ,
V_197 , V_3 ) ;
F_72 ( V_194 , V_196 ) ;
return V_5 ;
}
break;
case V_207 :
case V_208 :
V_5 = F_73 ( V_194 , V_196 , V_197 , V_3 ) ;
if ( V_5 )
return V_5 ;
break;
case V_209 :
case V_210 :
case V_211 :
case V_212 :
V_12 = ( V_3 - V_209 ) >> 2 ;
V_5 = F_74 ( V_194 , & V_199 , 0 ) ;
if ( V_5 ) {
F_20 ( L_19 ,
V_197 , V_3 ) ;
F_72 ( V_194 , V_196 ) ;
return V_5 ;
}
V_201 -> V_213 [ V_12 ] . V_25 = V_199 -> V_25 ;
V_201 -> V_213 [ V_12 ] . V_214 = V_204 ;
V_201 -> V_215 = true ;
V_202 [ V_197 ] = V_204 + ( ( T_4 ) V_199 -> V_216 ) ;
break;
case V_217 :
V_5 = F_74 ( V_194 , & V_199 , 0 ) ;
if ( V_5 ) {
F_20 ( L_19 ,
V_197 , V_3 ) ;
F_72 ( V_194 , V_196 ) ;
return V_5 ;
}
V_201 -> V_218 . V_25 = V_199 -> V_25 ;
V_201 -> V_218 . V_214 = V_204 ;
V_201 -> V_219 = true ;
V_202 [ V_197 ] = V_204 + ( ( T_4 ) V_199 -> V_216 ) ;
break;
case V_220 :
case V_220 + 4 :
case V_220 + 8 :
case V_220 + 12 :
case V_220 + 16 :
case V_220 + 20 :
case V_220 + 24 :
case V_220 + 28 :
case V_220 + 32 :
case V_220 + 36 :
case V_220 + 40 :
case V_220 + 44 :
case V_220 + 48 :
case V_220 + 52 :
case V_220 + 56 :
case V_220 + 60 :
V_12 = ( V_3 - V_220 ) >> 2 ;
V_5 = F_74 ( V_194 , & V_199 , 0 ) ;
if ( V_5 ) {
F_20 ( L_19 ,
V_197 , V_3 ) ;
F_72 ( V_194 , V_196 ) ;
return V_5 ;
}
if ( V_194 -> V_221 & V_222 ) {
V_202 [ V_197 ] = ( V_204 & 31 ) |
( ( V_204 & ~ 31 ) + ( T_4 ) V_199 -> V_216 ) ;
} else {
if ( V_199 -> V_223 & V_224 )
V_203 |= V_225 ;
if ( V_199 -> V_223 & V_226 )
V_203 |= V_227 ;
else if ( V_199 -> V_223 & V_228 )
V_203 |= V_229 ;
V_11 = V_204 + ( ( T_4 ) V_199 -> V_216 ) ;
V_11 |= V_203 ;
V_202 [ V_197 ] = V_11 ;
}
V_201 -> V_230 [ V_12 ] . V_25 = V_199 -> V_25 ;
V_201 -> V_231 = true ;
break;
case 0x2084 :
V_201 -> V_232 = V_204 ;
break;
case 0x20B4 :
V_201 -> V_233 = V_204 & 0x7F ;
break;
case 0x2134 :
V_201 -> V_234 = V_204 & 0x00FFFFFFUL ;
break;
case 0x2088 :
if ( V_194 -> V_2 -> V_124 < V_235 )
goto V_236;
V_201 -> V_237 = V_204 & 0xFFFFFF ;
break;
case 0x43E4 :
V_201 -> V_238 = ( ( V_204 >> 13 ) & 0x1FFF ) + 1 ;
if ( V_194 -> V_2 -> V_124 < V_235 ) {
V_201 -> V_238 -= 1440 ;
}
V_201 -> V_215 = true ;
V_201 -> V_219 = true ;
break;
case 0x4E00 :
if ( ( V_204 & ( 1 << 10 ) ) &&
V_194 -> V_2 -> V_239 != V_194 -> V_240 ) {
F_20 ( L_20 ) ;
return - V_34 ;
}
V_201 -> V_241 = ( ( V_204 >> 5 ) & 0x3 ) + 1 ;
V_201 -> V_215 = true ;
break;
case 0x4E38 :
case 0x4E3C :
case 0x4E40 :
case 0x4E44 :
if ( ! ( V_194 -> V_221 & V_222 ) ) {
V_5 = F_74 ( V_194 , & V_199 , 0 ) ;
if ( V_5 ) {
F_20 ( L_19 ,
V_197 , V_3 ) ;
F_72 ( V_194 , V_196 ) ;
return V_5 ;
}
if ( V_199 -> V_223 & V_224 )
V_203 |= V_242 ;
if ( V_199 -> V_223 & V_226 )
V_203 |= V_243 ;
else if ( V_199 -> V_223 & V_228 )
V_203 |= V_244 ;
V_11 = V_204 & ~ ( 0x7 << 16 ) ;
V_11 |= V_203 ;
V_202 [ V_197 ] = V_11 ;
}
V_12 = ( V_3 - 0x4E38 ) >> 2 ;
V_201 -> V_213 [ V_12 ] . V_245 = V_204 & 0x3FFE ;
switch ( ( ( V_204 >> 21 ) & 0xF ) ) {
case 9 :
case 11 :
case 12 :
V_201 -> V_213 [ V_12 ] . V_246 = 1 ;
break;
case 3 :
case 4 :
case 13 :
case 15 :
V_201 -> V_213 [ V_12 ] . V_246 = 2 ;
break;
case 5 :
if ( V_194 -> V_2 -> V_124 < V_235 ) {
F_20 ( L_21 ,
( ( V_204 >> 21 ) & 0xF ) ) ;
return - V_34 ;
}
case 6 :
V_201 -> V_213 [ V_12 ] . V_246 = 4 ;
break;
case 10 :
V_201 -> V_213 [ V_12 ] . V_246 = 8 ;
break;
case 7 :
V_201 -> V_213 [ V_12 ] . V_246 = 16 ;
break;
default:
F_20 ( L_22 ,
( ( V_204 >> 21 ) & 0xF ) ) ;
return - V_34 ;
}
V_201 -> V_215 = true ;
break;
case 0x4F00 :
if ( V_204 & 2 ) {
V_201 -> V_247 = true ;
} else {
V_201 -> V_247 = false ;
}
V_201 -> V_219 = true ;
break;
case 0x4F10 :
switch ( ( V_204 & 0xF ) ) {
case 0 :
case 1 :
V_201 -> V_218 . V_246 = 2 ;
break;
case 2 :
V_201 -> V_218 . V_246 = 4 ;
break;
default:
F_20 ( L_23 ,
( V_204 & 0xF ) ) ;
return - V_34 ;
}
V_201 -> V_219 = true ;
break;
case 0x4F24 :
if ( ! ( V_194 -> V_221 & V_222 ) ) {
V_5 = F_74 ( V_194 , & V_199 , 0 ) ;
if ( V_5 ) {
F_20 ( L_19 ,
V_197 , V_3 ) ;
F_72 ( V_194 , V_196 ) ;
return V_5 ;
}
if ( V_199 -> V_223 & V_224 )
V_203 |= V_248 ;
if ( V_199 -> V_223 & V_226 )
V_203 |= V_249 ;
else if ( V_199 -> V_223 & V_228 )
V_203 |= V_250 ;
V_11 = V_204 & ~ ( 0x7 << 16 ) ;
V_11 |= V_203 ;
V_202 [ V_197 ] = V_11 ;
}
V_201 -> V_218 . V_245 = V_204 & 0x3FFC ;
V_201 -> V_219 = true ;
break;
case 0x4104 :
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
bool V_251 ;
V_251 = ! ! ( V_204 & ( 1 << V_12 ) ) ;
V_201 -> V_230 [ V_12 ] . V_251 = V_251 ;
}
V_201 -> V_231 = true ;
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
V_11 = ( V_204 >> 25 ) & 0x3 ;
V_201 -> V_230 [ V_12 ] . V_252 = V_11 ;
switch ( ( V_204 & 0x1F ) ) {
case V_253 :
case V_254 :
case V_255 :
V_201 -> V_230 [ V_12 ] . V_246 = 1 ;
V_201 -> V_230 [ V_12 ] . V_256 = V_257 ;
break;
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
V_201 -> V_230 [ V_12 ] . V_246 = 2 ;
V_201 -> V_230 [ V_12 ] . V_256 = V_257 ;
break;
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case 0x17 :
case V_274 :
case 0x1e :
V_201 -> V_230 [ V_12 ] . V_246 = 4 ;
V_201 -> V_230 [ V_12 ] . V_256 = V_257 ;
break;
case V_275 :
case V_276 :
case V_277 :
V_201 -> V_230 [ V_12 ] . V_246 = 8 ;
V_201 -> V_230 [ V_12 ] . V_256 = V_257 ;
break;
case V_278 :
V_201 -> V_230 [ V_12 ] . V_246 = 16 ;
V_201 -> V_230 [ V_12 ] . V_256 = V_257 ;
break;
case V_279 :
V_201 -> V_230 [ V_12 ] . V_246 = 1 ;
V_201 -> V_230 [ V_12 ] . V_256 = V_280 ;
break;
case V_281 :
if ( V_194 -> V_2 -> V_124 < V_282 ) {
F_20 ( L_24 ,
( V_204 & 0x1F ) ) ;
return - V_34 ;
}
case V_283 :
case V_284 :
V_201 -> V_230 [ V_12 ] . V_246 = 1 ;
V_201 -> V_230 [ V_12 ] . V_256 = V_285 ;
break;
default:
F_20 ( L_24 ,
( V_204 & 0x1F ) ) ;
return - V_34 ;
}
V_201 -> V_231 = true ;
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
V_11 = V_204 & 0x7 ;
if ( V_11 == 2 || V_11 == 4 || V_11 == 6 ) {
V_201 -> V_230 [ V_12 ] . V_286 = false ;
}
V_11 = ( V_204 >> 3 ) & 0x7 ;
if ( V_11 == 2 || V_11 == 4 || V_11 == 6 ) {
V_201 -> V_230 [ V_12 ] . V_287 = false ;
}
V_201 -> V_231 = true ;
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
V_11 = V_204 & 0x3FFF ;
V_201 -> V_230 [ V_12 ] . V_245 = V_11 + 1 ;
if ( V_194 -> V_2 -> V_124 >= V_235 ) {
V_11 = ( ( V_204 >> 15 ) & 1 ) << 11 ;
V_201 -> V_230 [ V_12 ] . V_288 = V_11 ;
V_11 = ( ( V_204 >> 16 ) & 1 ) << 11 ;
V_201 -> V_230 [ V_12 ] . V_289 = V_11 ;
if ( V_204 & ( 1 << 14 ) ) {
V_201 -> V_230 [ V_12 ] . V_256 =
V_280 ;
}
} else if ( V_204 & ( 1 << 14 ) ) {
F_20 ( L_25 ) ;
return - V_34 ;
}
V_201 -> V_231 = true ;
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
V_11 = V_204 & 0x7FF ;
V_201 -> V_230 [ V_12 ] . V_290 = V_11 + 1 ;
V_11 = ( V_204 >> 11 ) & 0x7FF ;
V_201 -> V_230 [ V_12 ] . V_291 = V_11 + 1 ;
V_11 = ( V_204 >> 26 ) & 0xF ;
V_201 -> V_230 [ V_12 ] . V_292 = V_11 ;
V_11 = V_204 & ( 1 << 31 ) ;
V_201 -> V_230 [ V_12 ] . V_293 = ! ! V_11 ;
V_11 = ( V_204 >> 22 ) & 0xF ;
V_201 -> V_230 [ V_12 ] . V_294 = V_11 ;
V_201 -> V_231 = true ;
break;
case V_295 :
V_5 = F_74 ( V_194 , & V_199 , 0 ) ;
if ( V_5 ) {
F_20 ( L_19 ,
V_197 , V_3 ) ;
F_72 ( V_194 , V_196 ) ;
return V_5 ;
}
V_202 [ V_197 ] = V_204 + ( ( T_4 ) V_199 -> V_216 ) ;
break;
case 0x4e0c :
V_201 -> V_296 = V_204 ;
V_201 -> V_215 = true ;
break;
case 0x43a4 :
if ( V_194 -> V_2 -> V_297 != V_194 -> V_240 ) {
if ( V_204 & 0x1 )
V_202 [ V_197 ] = V_204 & ~ 1 ;
}
break;
case 0x4f1c :
V_201 -> V_298 = ! ! ( V_204 & ( 1 << 5 ) ) ;
V_201 -> V_215 = true ;
V_201 -> V_219 = true ;
if ( V_194 -> V_2 -> V_297 != V_194 -> V_240 ) {
if ( V_204 & ( V_299 |
V_300 |
V_301 |
V_302 ) )
goto V_236;
}
break;
case 0x4e04 :
V_201 -> V_303 = ! ! ( V_204 & ( 1 << 2 ) ) ;
V_201 -> V_215 = true ;
break;
case V_304 :
V_5 = F_74 ( V_194 , & V_199 , 0 ) ;
if ( V_5 ) {
F_20 ( L_19 ,
V_197 , V_3 ) ;
F_72 ( V_194 , V_196 ) ;
return V_5 ;
}
V_201 -> V_305 . V_25 = V_199 -> V_25 ;
V_201 -> V_305 . V_214 = V_204 ;
V_201 -> V_306 = true ;
V_202 [ V_197 ] = V_204 + ( ( T_4 ) V_199 -> V_216 ) ;
break;
case V_307 :
V_201 -> V_305 . V_245 = V_204 & 0x3FFE ;
V_201 -> V_306 = true ;
break;
case V_308 :
V_201 -> V_309 = V_204 & 0x1 ;
V_201 -> V_306 = true ;
break;
case 0x4f30 :
case 0x4f34 :
case 0x4f44 :
case 0x4f54 :
if ( V_204 && ( V_194 -> V_2 -> V_297 != V_194 -> V_240 ) )
goto V_236;
break;
case 0x4028 :
if ( V_204 && ( V_194 -> V_2 -> V_297 != V_194 -> V_240 ) )
goto V_236;
if ( V_194 -> V_2 -> V_124 >= V_310 )
break;
goto V_236;
break;
case 0x4be8 :
if ( V_194 -> V_2 -> V_124 == V_311 )
break;
default:
goto V_236;
}
return 0 ;
V_236:
F_42 ( V_312 L_26 ,
V_3 , V_197 , V_204 ) ;
return - V_34 ;
}
static int F_75 ( struct V_193 * V_194 ,
struct V_195 * V_196 )
{
struct V_198 * V_199 ;
struct V_200 * V_201 ;
volatile T_1 * V_202 ;
unsigned V_197 ;
int V_5 ;
V_202 = V_194 -> V_202 . V_23 ;
V_197 = V_196 -> V_197 + 1 ;
V_201 = (struct V_200 * ) V_194 -> V_201 ;
switch( V_196 -> V_313 ) {
case V_314 :
V_5 = F_76 ( V_194 , V_196 , V_197 ) ;
if ( V_5 )
return V_5 ;
break;
case V_315 :
V_5 = F_74 ( V_194 , & V_199 , 0 ) ;
if ( V_5 ) {
F_20 ( L_27 , V_196 -> V_313 ) ;
F_72 ( V_194 , V_196 ) ;
return V_5 ;
}
V_202 [ V_197 + 1 ] = F_70 ( V_194 , V_197 + 1 ) + ( ( T_4 ) V_199 -> V_216 ) ;
V_5 = F_77 ( V_194 , V_196 , V_199 -> V_25 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_316 :
if ( ( ( F_70 ( V_194 , V_197 + 1 ) >> 4 ) & 0x3 ) != 3 ) {
F_20 ( L_28 ) ;
return - V_34 ;
}
V_201 -> V_232 = F_70 ( V_194 , V_197 + 1 ) ;
V_201 -> V_317 = V_196 -> V_318 - 1 ;
V_5 = F_78 ( V_194 -> V_2 , V_201 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_319 :
if ( ( ( F_70 ( V_194 , V_197 ) >> 4 ) & 0x3 ) != 3 ) {
F_20 ( L_28 ) ;
return - V_34 ;
}
V_201 -> V_232 = F_70 ( V_194 , V_197 ) ;
V_201 -> V_317 = V_196 -> V_318 ;
V_5 = F_78 ( V_194 -> V_2 , V_201 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_320 :
V_201 -> V_232 = F_70 ( V_194 , V_197 + 1 ) ;
V_5 = F_78 ( V_194 -> V_2 , V_201 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_321 :
V_201 -> V_232 = F_70 ( V_194 , V_197 ) ;
V_5 = F_78 ( V_194 -> V_2 , V_201 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_322 :
V_201 -> V_232 = F_70 ( V_194 , V_197 + 1 ) ;
V_5 = F_78 ( V_194 -> V_2 , V_201 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_323 :
V_201 -> V_232 = F_70 ( V_194 , V_197 ) ;
V_5 = F_78 ( V_194 -> V_2 , V_201 ) ;
if ( V_5 ) {
return V_5 ;
}
break;
case V_324 :
case V_325 :
if ( V_194 -> V_2 -> V_297 != V_194 -> V_240 )
return - V_34 ;
break;
case V_326 :
if ( V_194 -> V_2 -> V_239 != V_194 -> V_240 )
return - V_34 ;
break;
case V_327 :
break;
default:
F_20 ( L_29 , V_196 -> V_313 ) ;
return - V_34 ;
}
return 0 ;
}
int F_79 ( struct V_193 * V_194 )
{
struct V_195 V_196 ;
struct V_200 * V_201 ;
int V_5 ;
V_201 = F_80 ( sizeof( * V_201 ) , V_328 ) ;
if ( V_201 == NULL )
return - V_329 ;
F_81 ( V_194 -> V_2 , V_201 ) ;
V_194 -> V_201 = V_201 ;
do {
V_5 = F_82 ( V_194 , & V_196 , V_194 -> V_197 ) ;
if ( V_5 ) {
return V_5 ;
}
V_194 -> V_197 += V_196 . V_318 + 2 ;
switch ( V_196 . type ) {
case V_330 :
V_5 = F_83 ( V_194 , & V_196 ,
V_194 -> V_2 -> V_67 . V_68 . V_331 ,
V_194 -> V_2 -> V_67 . V_68 . V_332 ,
& F_69 ) ;
break;
case V_333 :
break;
case V_334 :
V_5 = F_75 ( V_194 , & V_196 ) ;
break;
default:
F_20 ( L_30 , V_196 . type ) ;
return - V_34 ;
}
if ( V_5 ) {
return V_5 ;
}
} while ( V_194 -> V_197 < V_194 -> V_335 -> V_336 );
return 0 ;
}
void F_84 ( struct V_1 * V_2 )
{
V_2 -> V_67 . V_68 . V_331 = V_337 ;
V_2 -> V_67 . V_68 . V_332 = F_85 ( V_337 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_142 V_143 ;
int V_5 ;
V_5 = F_87 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_31 ) ;
}
F_45 ( V_2 , & V_143 ) ;
if ( V_2 -> V_4 & V_163 ) {
F_3 ( V_338 ,
F_88 ( V_2 -> V_37 . V_38 >> 16 ) |
F_89 ( V_2 -> V_37 . V_39 >> 16 ) ) ;
F_3 ( V_339 , F_12 ( V_2 -> V_37 . V_340 ) ) ;
F_3 ( V_341 ,
F_13 ( V_2 -> V_37 . V_340 ) & 0xff ) ;
} else {
F_3 ( V_338 , 0x0FFFFFFF ) ;
F_3 ( V_339 , 0 ) ;
F_3 ( V_341 , 0 ) ;
}
if ( F_38 ( V_2 ) )
F_25 ( L_32 ) ;
F_3 ( V_342 ,
F_90 ( V_2 -> V_37 . V_46 >> 16 ) |
F_91 ( V_2 -> V_37 . V_343 >> 16 ) ) ;
F_57 ( V_2 , & V_143 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
T_4 V_11 ;
if ( V_344 != - 1 && V_344 )
F_93 ( V_2 , 1 ) ;
V_11 = F_94 ( V_345 ) ;
V_11 |= F_95 ( 1 ) | F_96 ( 1 ) ;
if ( ( V_2 -> V_124 == V_310 ) || ( V_2 -> V_124 == V_346 ) )
V_11 |= F_97 ( 1 ) ;
F_98 ( V_345 , V_11 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_5 ;
F_100 ( V_2 ) ;
F_86 ( V_2 ) ;
F_92 ( V_2 ) ;
F_40 ( V_2 ) ;
if ( V_2 -> V_4 & V_167 ) {
V_5 = F_22 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_2 -> V_124 == V_125 ||
V_2 -> V_124 == V_135 ||
V_2 -> V_124 == V_310 )
F_54 ( V_2 ) ;
if ( V_2 -> V_4 & V_347 ) {
V_5 = F_101 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
V_5 = F_102 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_103 ( V_2 , V_348 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_33 , V_5 ) ;
return V_5 ;
}
if ( ! V_2 -> V_349 . V_350 ) {
V_5 = F_104 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
F_105 ( V_2 ) ;
V_2 -> V_67 . V_68 . V_69 = F_4 ( V_66 ) ;
V_5 = F_106 ( V_2 , 1024 * 1024 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_34 , V_5 ) ;
return V_5 ;
}
V_5 = F_107 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_35 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
int F_108 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_4 & V_167 )
F_26 ( V_2 ) ;
if ( V_2 -> V_4 & V_347 )
F_109 ( V_2 ) ;
F_92 ( V_2 ) ;
if ( F_110 ( V_2 ) ) {
F_111 ( V_2 -> V_33 , L_36 ,
F_4 ( V_146 ) ,
F_4 ( V_351 ) ) ;
}
F_112 ( V_2 -> V_352 ) ;
F_92 ( V_2 ) ;
F_113 ( V_2 ) ;
V_2 -> V_353 = true ;
V_5 = F_99 ( V_2 ) ;
if ( V_5 ) {
V_2 -> V_353 = false ;
}
return V_5 ;
}
int F_114 ( struct V_1 * V_2 )
{
F_115 ( V_2 ) ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
if ( V_2 -> V_4 & V_167 )
F_26 ( V_2 ) ;
if ( V_2 -> V_4 & V_347 )
F_109 ( V_2 ) ;
return 0 ;
}
void F_119 ( struct V_1 * V_2 )
{
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
if ( V_2 -> V_4 & V_167 )
F_28 ( V_2 ) ;
if ( V_2 -> V_4 & V_347 )
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 -> V_354 ) ;
V_2 -> V_354 = NULL ;
}
int F_132 ( struct V_1 * V_2 )
{
int V_5 ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
F_113 ( V_2 ) ;
F_135 ( V_2 ) ;
if ( ! F_136 ( V_2 ) ) {
if ( F_137 ( V_2 ) )
return - V_34 ;
}
if ( V_2 -> V_355 ) {
F_23 ( V_2 -> V_33 , L_37 ) ;
return - V_34 ;
} else {
V_5 = F_138 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
if ( F_110 ( V_2 ) ) {
F_111 ( V_2 -> V_33 ,
L_36 ,
F_4 ( V_146 ) ,
F_4 ( V_351 ) ) ;
}
if ( F_139 ( V_2 ) == false )
return - V_34 ;
F_37 ( V_2 ) ;
F_140 ( V_2 -> V_352 ) ;
if ( V_2 -> V_4 & V_163 ) {
V_5 = F_141 ( V_2 ) ;
if ( V_5 ) {
F_142 ( V_2 ) ;
}
}
F_58 ( V_2 ) ;
V_5 = F_143 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_144 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_4 & V_167 ) {
V_5 = F_16 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_2 -> V_4 & V_347 ) {
V_5 = F_145 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
F_84 ( V_2 ) ;
F_146 ( V_2 ) ;
V_2 -> V_353 = true ;
V_5 = F_99 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 -> V_33 , L_38 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_127 ( V_2 ) ;
if ( V_2 -> V_4 & V_167 )
F_28 ( V_2 ) ;
if ( V_2 -> V_4 & V_347 )
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
V_2 -> V_353 = false ;
}
return 0 ;
}
