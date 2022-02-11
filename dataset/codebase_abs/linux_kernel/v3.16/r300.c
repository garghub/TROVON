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
void F_5 ( struct V_1 * V_2 , unsigned V_4 ,
T_2 V_7 )
{
void T_3 * V_8 = V_2 -> V_9 . V_8 ;
V_7 = ( F_6 ( V_7 ) >> 8 ) |
( ( F_7 ( V_7 ) & 0xff ) << 24 ) |
V_10 | V_11 ;
F_8 ( V_7 , ( ( void T_3 * ) V_8 ) + ( V_4 * 4 ) ) ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 -> V_9 . V_13 ) {
F_10 ( 1 , L_1 ) ;
return 0 ;
}
V_12 = F_11 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_12 ( V_2 ) ;
if ( V_12 )
F_13 ( L_2 ) ;
V_2 -> V_9 . V_14 = V_2 -> V_9 . V_15 * 4 ;
V_2 -> V_16 -> V_9 . V_17 = & F_1 ;
V_2 -> V_16 -> V_9 . V_18 = & F_5 ;
return F_14 ( V_2 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
T_1 V_19 ;
T_1 V_3 ;
int V_12 ;
if ( V_2 -> V_9 . V_13 == NULL ) {
F_16 ( V_2 -> V_20 , L_3 ) ;
return - V_21 ;
}
V_12 = F_17 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_18 ( V_2 ) ;
V_3 = V_22 ;
F_3 ( V_5 , V_3 ) ;
F_3 ( V_23 , V_2 -> V_24 . V_25 ) ;
V_3 = V_2 -> V_24 . V_26 & ~ V_27 ;
F_3 ( V_28 , V_3 ) ;
F_3 ( V_29 , 0 ) ;
F_3 ( V_30 , 0 ) ;
V_19 = V_2 -> V_9 . V_19 ;
F_3 ( V_31 , V_19 ) ;
F_3 ( V_32 , V_2 -> V_24 . V_33 ) ;
F_3 ( V_34 , 0 ) ;
F_3 ( V_35 , 0 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_36 ;
V_3 |= V_22 ;
F_3 ( V_5 , V_3 ) ;
F_1 ( V_2 ) ;
F_19 ( L_4 ,
( unsigned ) ( V_2 -> V_24 . V_37 >> 20 ) ,
( unsigned long long ) V_19 ) ;
V_2 -> V_9 . V_38 = true ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
T_4 V_3 ;
F_3 ( V_23 , 0 ) ;
F_3 ( V_28 , 0 ) ;
F_3 ( V_29 , 0 ) ;
F_3 ( V_30 , 0 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_22 ;
F_3 ( V_5 , V_3 & ~ V_36 ) ;
F_21 ( V_2 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_20 ( V_2 ) ;
F_24 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = & V_2 -> V_42 [ V_40 -> V_42 ] ;
F_26 ( V_42 , F_27 ( V_43 , 0 ) ) ;
F_26 ( V_42 , 0 ) ;
F_26 ( V_42 , F_27 ( V_44 , 0 ) ) ;
F_26 ( V_42 , 0 ) ;
F_26 ( V_42 , F_27 ( V_45 , 0 ) ) ;
F_26 ( V_42 , V_46 ) ;
F_26 ( V_42 , F_27 ( V_47 , 0 ) ) ;
F_26 ( V_42 , V_48 ) ;
F_26 ( V_42 , F_27 ( V_49 , 0 ) ) ;
F_26 ( V_42 , ( V_50 |
V_51 |
V_52 ) ) ;
F_26 ( V_42 , F_27 ( V_53 , 0 ) ) ;
F_26 ( V_42 , V_2 -> V_54 . V_55 . V_56 |
V_57 ) ;
F_26 ( V_42 , F_27 ( V_53 , 0 ) ) ;
F_26 ( V_42 , V_2 -> V_54 . V_55 . V_56 ) ;
F_26 ( V_42 , F_27 ( V_2 -> V_58 [ V_40 -> V_42 ] . V_59 , 0 ) ) ;
F_26 ( V_42 , V_40 -> V_60 ) ;
F_26 ( V_42 , F_27 ( V_61 , 0 ) ) ;
F_26 ( V_42 , V_62 ) ;
}
void F_28 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
unsigned V_63 ;
int V_12 ;
V_63 = ( V_64 | V_65 ) ;
switch( V_2 -> V_66 ) {
case 2 :
V_63 |= V_67 ;
break;
case 3 :
V_63 |= V_68 ;
break;
case 4 :
V_63 |= V_69 ;
break;
case 1 :
default:
V_63 |= V_70 ;
break;
}
V_12 = F_29 ( V_2 , V_42 , 64 ) ;
if ( V_12 ) {
return;
}
F_26 ( V_42 , F_27 ( V_71 , 0 ) ) ;
F_26 ( V_42 ,
V_72 |
V_73 |
V_74 |
V_75 ) ;
F_26 ( V_42 , F_27 ( V_76 , 0 ) ) ;
F_26 ( V_42 , V_63 ) ;
F_26 ( V_42 , F_27 ( V_49 , 0 ) ) ;
F_26 ( V_42 ,
V_51 |
V_50 ) ;
F_26 ( V_42 , F_27 ( V_77 , 0 ) ) ;
F_26 ( V_42 , V_78 ) ;
F_26 ( V_42 , F_27 ( V_79 , 0 ) ) ;
F_26 ( V_42 , 0 ) ;
F_26 ( V_42 , F_27 ( V_80 , 0 ) ) ;
F_26 ( V_42 , 0 ) ;
F_26 ( V_42 , F_27 ( V_45 , 0 ) ) ;
F_26 ( V_42 , V_46 | V_81 ) ;
F_26 ( V_42 , F_27 ( V_47 , 0 ) ) ;
F_26 ( V_42 , V_48 | V_82 ) ;
F_26 ( V_42 , F_27 ( V_49 , 0 ) ) ;
F_26 ( V_42 ,
V_51 |
V_50 ) ;
F_26 ( V_42 , F_27 ( V_83 , 0 ) ) ;
F_26 ( V_42 , 0 ) ;
F_26 ( V_42 , F_27 ( V_45 , 0 ) ) ;
F_26 ( V_42 , V_46 | V_81 ) ;
F_26 ( V_42 , F_27 ( V_47 , 0 ) ) ;
F_26 ( V_42 , V_48 | V_82 ) ;
F_26 ( V_42 , F_27 ( V_84 , 0 ) ) ;
F_26 ( V_42 ,
( ( 6 << V_85 ) |
( 6 << V_86 ) |
( 6 << V_87 ) |
( 6 << V_88 ) |
( 6 << V_89 ) |
( 6 << V_90 ) |
( 6 << V_91 ) |
( 6 << V_92 ) ) ) ;
F_26 ( V_42 , F_27 ( V_93 , 0 ) ) ;
F_26 ( V_42 ,
( ( 6 << V_94 ) |
( 6 << V_95 ) |
( 6 << V_96 ) |
( 6 << V_97 ) |
( 6 << V_98 ) |
( 6 << V_99 ) |
( 6 << V_100 ) ) ) ;
F_26 ( V_42 , F_27 ( V_101 , 0 ) ) ;
F_26 ( V_42 , V_102 | V_103 ) ;
F_26 ( V_42 , F_27 ( V_104 , 0 ) ) ;
F_26 ( V_42 ,
V_105 | V_106 ) ;
F_26 ( V_42 , F_27 ( V_107 , 0 ) ) ;
F_26 ( V_42 ,
V_108 |
V_109 ) ;
F_30 ( V_2 , V_42 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
V_2 -> V_110 = 0 ;
if ( V_2 -> V_111 == V_112 &&
( F_32 ( V_113 ) & V_114 ) == V_115 ) {
V_2 -> V_110 |= V_116 ;
}
}
int F_33 ( struct V_1 * V_2 )
{
unsigned V_4 ;
T_1 V_3 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_117 ; V_4 ++ ) {
V_3 = F_32 ( V_118 ) ;
if ( V_3 & V_119 ) {
return 0 ;
}
F_34 ( 1 ) ;
}
return - 1 ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_63 , V_3 ;
if ( ( V_2 -> V_111 == V_112 && V_2 -> V_120 -> V_121 != 0x4144 ) ||
( V_2 -> V_111 == V_122 && V_2 -> V_120 -> V_121 != 0x4148 ) ) {
V_2 -> V_66 = 2 ;
} else {
V_2 -> V_66 = 1 ;
}
V_2 -> V_123 = 1 ;
V_63 = ( V_64 | V_65 ) ;
switch ( V_2 -> V_66 ) {
case 2 :
V_63 |= V_67 ;
break;
case 3 :
V_63 |= V_68 ;
break;
case 4 :
V_63 |= V_69 ;
break;
default:
case 1 :
V_63 |= V_70 ;
break;
}
F_36 ( V_76 , V_63 ) ;
if ( F_37 ( V_2 ) ) {
F_38 ( V_124 L_5
L_6 ) ;
}
V_3 = F_32 ( V_77 ) ;
F_36 ( V_77 , V_3 | V_78 ) ;
F_36 ( V_125 ,
V_126 |
V_127 ) ;
if ( F_37 ( V_2 ) ) {
F_38 ( V_124 L_5
L_6 ) ;
}
if ( F_33 ( V_2 ) ) {
F_38 ( V_124 L_7
L_6 ) ;
}
F_19 ( L_8 ,
V_2 -> V_66 , V_2 -> V_123 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_128 V_129 ;
T_4 V_130 , V_3 ;
int V_131 = 0 ;
V_130 = F_32 ( V_132 ) ;
if ( ! F_40 ( V_130 ) ) {
return 0 ;
}
F_41 ( V_2 , & V_129 ) ;
V_130 = F_32 ( V_132 ) ;
F_42 ( V_2 -> V_20 , L_9 , V_133 , __LINE__ , V_130 ) ;
F_36 ( V_134 , 0 ) ;
V_3 = F_32 ( V_135 ) ;
F_36 ( V_135 , V_3 | V_136 ) ;
F_36 ( V_137 , 0 ) ;
F_36 ( V_138 , 0 ) ;
F_36 ( V_135 , V_3 ) ;
F_43 ( V_2 -> V_120 ) ;
F_44 ( V_2 ) ;
F_36 ( V_139 , F_45 ( 1 ) |
F_46 ( 1 ) ) ;
F_32 ( V_139 ) ;
F_47 ( 500 ) ;
F_36 ( V_139 , 0 ) ;
F_47 ( 1 ) ;
V_130 = F_32 ( V_132 ) ;
F_42 ( V_2 -> V_20 , L_9 , V_133 , __LINE__ , V_130 ) ;
F_36 ( V_139 , F_48 ( 1 ) ) ;
F_32 ( V_139 ) ;
F_47 ( 500 ) ;
F_36 ( V_139 , 0 ) ;
F_47 ( 1 ) ;
V_130 = F_32 ( V_132 ) ;
F_42 ( V_2 -> V_20 , L_9 , V_133 , __LINE__ , V_130 ) ;
F_49 ( V_2 -> V_120 ) ;
F_50 ( V_2 ) ;
if ( F_51 ( V_130 ) || F_52 ( V_130 ) ) {
F_16 ( V_2 -> V_20 , L_10 ) ;
V_131 = - 1 ;
} else
F_42 ( V_2 -> V_20 , L_11 ) ;
F_53 ( V_2 , & V_129 ) ;
return V_131 ;
}
void F_54 ( struct V_1 * V_2 )
{
T_5 V_140 ;
T_4 V_3 ;
V_2 -> V_24 . V_141 = true ;
V_3 = F_32 ( V_142 ) ;
V_3 &= V_143 ;
switch ( V_3 ) {
case 0 : V_2 -> V_24 . V_144 = 64 ; break;
case 1 : V_2 -> V_24 . V_144 = 128 ; break;
case 2 : V_2 -> V_24 . V_144 = 256 ; break;
default: V_2 -> V_24 . V_144 = 128 ; break;
}
F_55 ( V_2 ) ;
V_140 = V_2 -> V_24 . V_145 ;
if ( V_2 -> V_146 & V_147 )
V_140 = ( F_32 ( V_148 ) & 0xffff ) << 16 ;
F_56 ( V_2 , & V_2 -> V_24 , V_140 ) ;
V_2 -> V_24 . V_149 = 0 ;
if ( ! ( V_2 -> V_146 & V_150 ) )
F_57 ( V_2 , & V_2 -> V_24 ) ;
F_58 ( V_2 ) ;
}
void F_59 ( struct V_1 * V_2 , int V_151 )
{
T_1 V_152 , V_153 ;
if ( V_2 -> V_146 & V_147 )
return;
if ( ! ( V_2 -> V_146 & V_154 ) )
return;
switch ( V_151 ) {
case 0 :
V_153 = V_155 ;
break;
case 1 :
V_153 = V_156 ;
break;
case 2 :
V_153 = V_157 ;
break;
case 4 :
V_153 = V_158 ;
break;
case 8 :
V_153 = V_159 ;
break;
case 12 :
V_153 = V_160 ;
break;
case 16 :
default:
V_153 = V_161 ;
break;
}
V_152 = F_2 ( V_162 ) ;
if ( ( V_152 & V_163 ) ==
( V_153 << V_164 ) )
return;
V_152 &= ~ ( V_165 |
V_166 |
V_167 |
V_168 ) ;
V_152 |= V_153 ;
F_3 ( V_162 , V_152 ) ;
F_3 ( V_162 , ( V_152 |
V_166 ) ) ;
V_152 = F_2 ( V_162 ) ;
while ( V_152 == 0xffffffff )
V_152 = F_2 ( V_162 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
T_4 V_152 ;
if ( V_2 -> V_146 & V_147 )
return 0 ;
if ( ! ( V_2 -> V_146 & V_154 ) )
return 0 ;
V_152 = F_2 ( V_162 ) ;
switch ( ( V_152 & V_163 ) >> V_164 ) {
case V_155 :
return 0 ;
case V_156 :
return 1 ;
case V_157 :
return 2 ;
case V_158 :
return 4 ;
case V_159 :
return 8 ;
case V_161 :
default:
return 16 ;
}
}
static int F_61 ( struct V_169 * V_170 , void * V_171 )
{
struct V_172 * V_173 = (struct V_172 * ) V_170 -> V_174 ;
struct V_175 * V_20 = V_173 -> V_176 -> V_20 ;
struct V_1 * V_2 = V_20 -> V_177 ;
T_1 V_3 ;
V_3 = F_2 ( V_5 ) ;
F_62 ( V_170 , L_12 , V_3 ) ;
V_3 = F_2 ( V_31 ) ;
F_62 ( V_170 , L_13 , V_3 ) ;
V_3 = F_2 ( V_23 ) ;
F_62 ( V_170 , L_14 , V_3 ) ;
V_3 = F_2 ( V_29 ) ;
F_62 ( V_170 , L_15 , V_3 ) ;
V_3 = F_2 ( V_28 ) ;
F_62 ( V_170 , L_16 , V_3 ) ;
V_3 = F_2 ( V_30 ) ;
F_62 ( V_170 , L_17 , V_3 ) ;
V_3 = F_2 ( V_35 ) ;
F_62 ( V_170 , L_18 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
#if F_63 ( V_178 )
return F_64 ( V_2 , V_179 , 1 ) ;
#else
return 0 ;
#endif
}
static int F_65 ( struct V_180 * V_181 ,
struct V_182 * V_183 ,
unsigned V_184 , unsigned V_185 )
{
struct V_186 * V_187 ;
struct V_188 * V_189 ;
volatile T_1 * V_190 ;
T_1 V_3 , V_191 = 0 ;
unsigned V_4 ;
int V_12 ;
T_4 V_192 ;
V_190 = V_181 -> V_190 . V_8 ;
V_189 = (struct V_188 * ) V_181 -> V_189 ;
V_192 = F_66 ( V_181 , V_184 ) ;
switch( V_185 ) {
case V_193 :
case V_194 :
V_12 = F_67 ( V_181 ) ;
if ( V_12 ) {
F_13 ( L_19 ,
V_184 , V_185 ) ;
F_68 ( V_181 , V_183 ) ;
return V_12 ;
}
break;
case V_195 :
case V_196 :
V_12 = F_69 ( V_181 , V_183 , V_184 , V_185 ) ;
if ( V_12 )
return V_12 ;
break;
case V_197 :
case V_198 :
case V_199 :
case V_200 :
V_4 = ( V_185 - V_197 ) >> 2 ;
V_12 = F_70 ( V_181 , & V_187 , 0 ) ;
if ( V_12 ) {
F_13 ( L_19 ,
V_184 , V_185 ) ;
F_68 ( V_181 , V_183 ) ;
return V_12 ;
}
V_189 -> V_201 [ V_4 ] . V_13 = V_187 -> V_13 ;
V_189 -> V_201 [ V_4 ] . V_202 = V_192 ;
V_189 -> V_203 = true ;
V_190 [ V_184 ] = V_192 + ( ( T_4 ) V_187 -> V_204 ) ;
break;
case V_205 :
V_12 = F_70 ( V_181 , & V_187 , 0 ) ;
if ( V_12 ) {
F_13 ( L_19 ,
V_184 , V_185 ) ;
F_68 ( V_181 , V_183 ) ;
return V_12 ;
}
V_189 -> V_206 . V_13 = V_187 -> V_13 ;
V_189 -> V_206 . V_202 = V_192 ;
V_189 -> V_207 = true ;
V_190 [ V_184 ] = V_192 + ( ( T_4 ) V_187 -> V_204 ) ;
break;
case V_208 :
case V_208 + 4 :
case V_208 + 8 :
case V_208 + 12 :
case V_208 + 16 :
case V_208 + 20 :
case V_208 + 24 :
case V_208 + 28 :
case V_208 + 32 :
case V_208 + 36 :
case V_208 + 40 :
case V_208 + 44 :
case V_208 + 48 :
case V_208 + 52 :
case V_208 + 56 :
case V_208 + 60 :
V_4 = ( V_185 - V_208 ) >> 2 ;
V_12 = F_70 ( V_181 , & V_187 , 0 ) ;
if ( V_12 ) {
F_13 ( L_19 ,
V_184 , V_185 ) ;
F_68 ( V_181 , V_183 ) ;
return V_12 ;
}
if ( V_181 -> V_209 & V_210 ) {
V_190 [ V_184 ] = ( V_192 & 31 ) |
( ( V_192 & ~ 31 ) + ( T_4 ) V_187 -> V_204 ) ;
} else {
if ( V_187 -> V_211 & V_212 )
V_191 |= V_213 ;
if ( V_187 -> V_211 & V_214 )
V_191 |= V_215 ;
else if ( V_187 -> V_211 & V_216 )
V_191 |= V_217 ;
V_3 = V_192 + ( ( T_4 ) V_187 -> V_204 ) ;
V_3 |= V_191 ;
V_190 [ V_184 ] = V_3 ;
}
V_189 -> V_218 [ V_4 ] . V_13 = V_187 -> V_13 ;
V_189 -> V_219 = true ;
break;
case 0x2084 :
V_189 -> V_220 = V_192 ;
break;
case 0x20B4 :
V_189 -> V_221 = V_192 & 0x7F ;
break;
case 0x2134 :
V_189 -> V_222 = V_192 & 0x00FFFFFFUL ;
break;
case 0x2088 :
if ( V_181 -> V_2 -> V_111 < V_223 )
goto V_224;
V_189 -> V_225 = V_192 & 0xFFFFFF ;
break;
case 0x43E4 :
V_189 -> V_226 = ( ( V_192 >> 13 ) & 0x1FFF ) + 1 ;
if ( V_181 -> V_2 -> V_111 < V_223 ) {
V_189 -> V_226 -= 1440 ;
}
V_189 -> V_203 = true ;
V_189 -> V_207 = true ;
break;
case 0x4E00 :
if ( ( V_192 & ( 1 << 10 ) ) &&
V_181 -> V_2 -> V_227 != V_181 -> V_228 ) {
F_13 ( L_20 ) ;
return - V_21 ;
}
V_189 -> V_229 = ( ( V_192 >> 5 ) & 0x3 ) + 1 ;
V_189 -> V_203 = true ;
break;
case 0x4E38 :
case 0x4E3C :
case 0x4E40 :
case 0x4E44 :
if ( ! ( V_181 -> V_209 & V_210 ) ) {
V_12 = F_70 ( V_181 , & V_187 , 0 ) ;
if ( V_12 ) {
F_13 ( L_19 ,
V_184 , V_185 ) ;
F_68 ( V_181 , V_183 ) ;
return V_12 ;
}
if ( V_187 -> V_211 & V_212 )
V_191 |= V_230 ;
if ( V_187 -> V_211 & V_214 )
V_191 |= V_231 ;
else if ( V_187 -> V_211 & V_216 )
V_191 |= V_232 ;
V_3 = V_192 & ~ ( 0x7 << 16 ) ;
V_3 |= V_191 ;
V_190 [ V_184 ] = V_3 ;
}
V_4 = ( V_185 - 0x4E38 ) >> 2 ;
V_189 -> V_201 [ V_4 ] . V_233 = V_192 & 0x3FFE ;
switch ( ( ( V_192 >> 21 ) & 0xF ) ) {
case 9 :
case 11 :
case 12 :
V_189 -> V_201 [ V_4 ] . V_234 = 1 ;
break;
case 3 :
case 4 :
case 13 :
case 15 :
V_189 -> V_201 [ V_4 ] . V_234 = 2 ;
break;
case 5 :
if ( V_181 -> V_2 -> V_111 < V_223 ) {
F_13 ( L_21 ,
( ( V_192 >> 21 ) & 0xF ) ) ;
return - V_21 ;
}
case 6 :
V_189 -> V_201 [ V_4 ] . V_234 = 4 ;
break;
case 10 :
V_189 -> V_201 [ V_4 ] . V_234 = 8 ;
break;
case 7 :
V_189 -> V_201 [ V_4 ] . V_234 = 16 ;
break;
default:
F_13 ( L_22 ,
( ( V_192 >> 21 ) & 0xF ) ) ;
return - V_21 ;
}
V_189 -> V_203 = true ;
break;
case 0x4F00 :
if ( V_192 & 2 ) {
V_189 -> V_235 = true ;
} else {
V_189 -> V_235 = false ;
}
V_189 -> V_207 = true ;
break;
case 0x4F10 :
switch ( ( V_192 & 0xF ) ) {
case 0 :
case 1 :
V_189 -> V_206 . V_234 = 2 ;
break;
case 2 :
V_189 -> V_206 . V_234 = 4 ;
break;
default:
F_13 ( L_23 ,
( V_192 & 0xF ) ) ;
return - V_21 ;
}
V_189 -> V_207 = true ;
break;
case 0x4F24 :
if ( ! ( V_181 -> V_209 & V_210 ) ) {
V_12 = F_70 ( V_181 , & V_187 , 0 ) ;
if ( V_12 ) {
F_13 ( L_19 ,
V_184 , V_185 ) ;
F_68 ( V_181 , V_183 ) ;
return V_12 ;
}
if ( V_187 -> V_211 & V_212 )
V_191 |= V_236 ;
if ( V_187 -> V_211 & V_214 )
V_191 |= V_237 ;
else if ( V_187 -> V_211 & V_216 )
V_191 |= V_238 ;
V_3 = V_192 & ~ ( 0x7 << 16 ) ;
V_3 |= V_191 ;
V_190 [ V_184 ] = V_3 ;
}
V_189 -> V_206 . V_233 = V_192 & 0x3FFC ;
V_189 -> V_207 = true ;
break;
case 0x4104 :
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
bool V_239 ;
V_239 = ! ! ( V_192 & ( 1 << V_4 ) ) ;
V_189 -> V_218 [ V_4 ] . V_239 = V_239 ;
}
V_189 -> V_219 = true ;
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
V_4 = ( V_185 - 0x44C0 ) >> 2 ;
V_3 = ( V_192 >> 25 ) & 0x3 ;
V_189 -> V_218 [ V_4 ] . V_240 = V_3 ;
switch ( ( V_192 & 0x1F ) ) {
case V_241 :
case V_242 :
case V_243 :
V_189 -> V_218 [ V_4 ] . V_234 = 1 ;
V_189 -> V_218 [ V_4 ] . V_244 = V_245 ;
break;
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
V_189 -> V_218 [ V_4 ] . V_234 = 2 ;
V_189 -> V_218 [ V_4 ] . V_244 = V_245 ;
break;
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case 0x17 :
case V_262 :
case 0x1e :
V_189 -> V_218 [ V_4 ] . V_234 = 4 ;
V_189 -> V_218 [ V_4 ] . V_244 = V_245 ;
break;
case V_263 :
case V_264 :
case V_265 :
V_189 -> V_218 [ V_4 ] . V_234 = 8 ;
V_189 -> V_218 [ V_4 ] . V_244 = V_245 ;
break;
case V_266 :
V_189 -> V_218 [ V_4 ] . V_234 = 16 ;
V_189 -> V_218 [ V_4 ] . V_244 = V_245 ;
break;
case V_267 :
V_189 -> V_218 [ V_4 ] . V_234 = 1 ;
V_189 -> V_218 [ V_4 ] . V_244 = V_268 ;
break;
case V_269 :
if ( V_181 -> V_2 -> V_111 < V_270 ) {
F_13 ( L_24 ,
( V_192 & 0x1F ) ) ;
return - V_21 ;
}
case V_271 :
case V_272 :
V_189 -> V_218 [ V_4 ] . V_234 = 1 ;
V_189 -> V_218 [ V_4 ] . V_244 = V_273 ;
break;
default:
F_13 ( L_24 ,
( V_192 & 0x1F ) ) ;
return - V_21 ;
}
V_189 -> V_219 = true ;
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
V_4 = ( V_185 - 0x4400 ) >> 2 ;
V_3 = V_192 & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_189 -> V_218 [ V_4 ] . V_274 = false ;
}
V_3 = ( V_192 >> 3 ) & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_189 -> V_218 [ V_4 ] . V_275 = false ;
}
V_189 -> V_219 = true ;
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
V_4 = ( V_185 - 0x4500 ) >> 2 ;
V_3 = V_192 & 0x3FFF ;
V_189 -> V_218 [ V_4 ] . V_233 = V_3 + 1 ;
if ( V_181 -> V_2 -> V_111 >= V_223 ) {
V_3 = ( ( V_192 >> 15 ) & 1 ) << 11 ;
V_189 -> V_218 [ V_4 ] . V_276 = V_3 ;
V_3 = ( ( V_192 >> 16 ) & 1 ) << 11 ;
V_189 -> V_218 [ V_4 ] . V_277 = V_3 ;
if ( V_192 & ( 1 << 14 ) ) {
V_189 -> V_218 [ V_4 ] . V_244 =
V_268 ;
}
} else if ( V_192 & ( 1 << 14 ) ) {
F_13 ( L_25 ) ;
return - V_21 ;
}
V_189 -> V_219 = true ;
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
V_4 = ( V_185 - 0x4480 ) >> 2 ;
V_3 = V_192 & 0x7FF ;
V_189 -> V_218 [ V_4 ] . V_278 = V_3 + 1 ;
V_3 = ( V_192 >> 11 ) & 0x7FF ;
V_189 -> V_218 [ V_4 ] . V_279 = V_3 + 1 ;
V_3 = ( V_192 >> 26 ) & 0xF ;
V_189 -> V_218 [ V_4 ] . V_280 = V_3 ;
V_3 = V_192 & ( 1 << 31 ) ;
V_189 -> V_218 [ V_4 ] . V_281 = ! ! V_3 ;
V_3 = ( V_192 >> 22 ) & 0xF ;
V_189 -> V_218 [ V_4 ] . V_282 = V_3 ;
V_189 -> V_219 = true ;
break;
case V_283 :
V_12 = F_70 ( V_181 , & V_187 , 0 ) ;
if ( V_12 ) {
F_13 ( L_19 ,
V_184 , V_185 ) ;
F_68 ( V_181 , V_183 ) ;
return V_12 ;
}
V_190 [ V_184 ] = V_192 + ( ( T_4 ) V_187 -> V_204 ) ;
break;
case 0x4e0c :
V_189 -> V_284 = V_192 ;
V_189 -> V_203 = true ;
break;
case 0x43a4 :
if ( V_181 -> V_2 -> V_285 != V_181 -> V_228 ) {
if ( V_192 & 0x1 )
V_190 [ V_184 ] = V_192 & ~ 1 ;
}
break;
case 0x4f1c :
V_189 -> V_286 = ! ! ( V_192 & ( 1 << 5 ) ) ;
V_189 -> V_203 = true ;
V_189 -> V_207 = true ;
if ( V_181 -> V_2 -> V_285 != V_181 -> V_228 ) {
if ( V_192 & ( V_287 |
V_288 |
V_289 |
V_290 ) )
goto V_224;
}
break;
case 0x4e04 :
V_189 -> V_291 = ! ! ( V_192 & ( 1 << 2 ) ) ;
V_189 -> V_203 = true ;
break;
case V_292 :
V_12 = F_70 ( V_181 , & V_187 , 0 ) ;
if ( V_12 ) {
F_13 ( L_19 ,
V_184 , V_185 ) ;
F_68 ( V_181 , V_183 ) ;
return V_12 ;
}
V_189 -> V_293 . V_13 = V_187 -> V_13 ;
V_189 -> V_293 . V_202 = V_192 ;
V_189 -> V_294 = true ;
V_190 [ V_184 ] = V_192 + ( ( T_4 ) V_187 -> V_204 ) ;
break;
case V_295 :
V_189 -> V_293 . V_233 = V_192 & 0x3FFE ;
V_189 -> V_294 = true ;
break;
case V_296 :
V_189 -> V_297 = V_192 & 0x1 ;
V_189 -> V_294 = true ;
break;
case 0x4f30 :
case 0x4f34 :
case 0x4f44 :
case 0x4f54 :
if ( V_192 && ( V_181 -> V_2 -> V_285 != V_181 -> V_228 ) )
goto V_224;
break;
case 0x4028 :
if ( V_192 && ( V_181 -> V_2 -> V_285 != V_181 -> V_228 ) )
goto V_224;
if ( V_181 -> V_2 -> V_111 >= V_298 )
break;
goto V_224;
break;
case 0x4be8 :
if ( V_181 -> V_2 -> V_111 == V_299 )
break;
default:
goto V_224;
}
return 0 ;
V_224:
F_38 ( V_300 L_26 ,
V_185 , V_184 , V_192 ) ;
return - V_21 ;
}
static int F_71 ( struct V_180 * V_181 ,
struct V_182 * V_183 )
{
struct V_186 * V_187 ;
struct V_188 * V_189 ;
volatile T_1 * V_190 ;
unsigned V_184 ;
int V_12 ;
V_190 = V_181 -> V_190 . V_8 ;
V_184 = V_183 -> V_184 + 1 ;
V_189 = (struct V_188 * ) V_181 -> V_189 ;
switch( V_183 -> V_301 ) {
case V_302 :
V_12 = F_72 ( V_181 , V_183 , V_184 ) ;
if ( V_12 )
return V_12 ;
break;
case V_303 :
V_12 = F_70 ( V_181 , & V_187 , 0 ) ;
if ( V_12 ) {
F_13 ( L_27 , V_183 -> V_301 ) ;
F_68 ( V_181 , V_183 ) ;
return V_12 ;
}
V_190 [ V_184 + 1 ] = F_66 ( V_181 , V_184 + 1 ) + ( ( T_4 ) V_187 -> V_204 ) ;
V_12 = F_73 ( V_181 , V_183 , V_187 -> V_13 ) ;
if ( V_12 ) {
return V_12 ;
}
break;
case V_304 :
if ( ( ( F_66 ( V_181 , V_184 + 1 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_21 ;
}
V_189 -> V_220 = F_66 ( V_181 , V_184 + 1 ) ;
V_189 -> V_305 = V_183 -> V_306 - 1 ;
V_12 = F_74 ( V_181 -> V_2 , V_189 ) ;
if ( V_12 ) {
return V_12 ;
}
break;
case V_307 :
if ( ( ( F_66 ( V_181 , V_184 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_21 ;
}
V_189 -> V_220 = F_66 ( V_181 , V_184 ) ;
V_189 -> V_305 = V_183 -> V_306 ;
V_12 = F_74 ( V_181 -> V_2 , V_189 ) ;
if ( V_12 ) {
return V_12 ;
}
break;
case V_308 :
V_189 -> V_220 = F_66 ( V_181 , V_184 + 1 ) ;
V_12 = F_74 ( V_181 -> V_2 , V_189 ) ;
if ( V_12 ) {
return V_12 ;
}
break;
case V_309 :
V_189 -> V_220 = F_66 ( V_181 , V_184 ) ;
V_12 = F_74 ( V_181 -> V_2 , V_189 ) ;
if ( V_12 ) {
return V_12 ;
}
break;
case V_310 :
V_189 -> V_220 = F_66 ( V_181 , V_184 + 1 ) ;
V_12 = F_74 ( V_181 -> V_2 , V_189 ) ;
if ( V_12 ) {
return V_12 ;
}
break;
case V_311 :
V_189 -> V_220 = F_66 ( V_181 , V_184 ) ;
V_12 = F_74 ( V_181 -> V_2 , V_189 ) ;
if ( V_12 ) {
return V_12 ;
}
break;
case V_312 :
case V_313 :
if ( V_181 -> V_2 -> V_285 != V_181 -> V_228 )
return - V_21 ;
break;
case V_314 :
if ( V_181 -> V_2 -> V_227 != V_181 -> V_228 )
return - V_21 ;
break;
case V_315 :
break;
default:
F_13 ( L_29 , V_183 -> V_301 ) ;
return - V_21 ;
}
return 0 ;
}
int F_75 ( struct V_180 * V_181 )
{
struct V_182 V_183 ;
struct V_188 * V_189 ;
int V_12 ;
V_189 = F_76 ( sizeof( * V_189 ) , V_316 ) ;
if ( V_189 == NULL )
return - V_317 ;
F_77 ( V_181 -> V_2 , V_189 ) ;
V_181 -> V_189 = V_189 ;
do {
V_12 = F_78 ( V_181 , & V_183 , V_181 -> V_184 ) ;
if ( V_12 ) {
return V_12 ;
}
V_181 -> V_184 += V_183 . V_306 + 2 ;
switch ( V_183 . type ) {
case V_318 :
V_12 = F_79 ( V_181 , & V_183 ,
V_181 -> V_2 -> V_54 . V_55 . V_319 ,
V_181 -> V_2 -> V_54 . V_55 . V_320 ,
& F_65 ) ;
break;
case V_321 :
break;
case V_322 :
V_12 = F_71 ( V_181 , & V_183 ) ;
break;
default:
F_13 ( L_30 , V_183 . type ) ;
return - V_21 ;
}
if ( V_12 ) {
return V_12 ;
}
} while ( V_181 -> V_184 < V_181 -> V_323 [ V_181 -> V_324 ] . V_325 );
return 0 ;
}
void F_80 ( struct V_1 * V_2 )
{
V_2 -> V_54 . V_55 . V_319 = V_326 ;
V_2 -> V_54 . V_55 . V_320 = F_81 ( V_326 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_128 V_129 ;
int V_12 ;
V_12 = F_83 ( V_2 ) ;
if ( V_12 ) {
F_16 ( V_2 -> V_20 , L_31 ) ;
}
F_41 ( V_2 , & V_129 ) ;
if ( V_2 -> V_146 & V_150 ) {
F_36 ( V_327 ,
F_84 ( V_2 -> V_24 . V_25 >> 16 ) |
F_85 ( V_2 -> V_24 . V_26 >> 16 ) ) ;
F_36 ( V_328 , F_6 ( V_2 -> V_24 . V_329 ) ) ;
F_36 ( V_330 ,
F_7 ( V_2 -> V_24 . V_329 ) & 0xff ) ;
} else {
F_36 ( V_327 , 0x0FFFFFFF ) ;
F_36 ( V_328 , 0 ) ;
F_36 ( V_330 , 0 ) ;
}
if ( F_33 ( V_2 ) )
F_19 ( L_32 ) ;
F_36 ( V_331 ,
F_86 ( V_2 -> V_24 . V_33 >> 16 ) |
F_87 ( V_2 -> V_24 . V_332 >> 16 ) ) ;
F_53 ( V_2 , & V_129 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
T_4 V_3 ;
if ( V_333 != - 1 && V_333 )
F_89 ( V_2 , 1 ) ;
V_3 = F_90 ( V_334 ) ;
V_3 |= F_91 ( 1 ) | F_92 ( 1 ) ;
if ( ( V_2 -> V_111 == V_298 ) || ( V_2 -> V_111 == V_335 ) )
V_3 |= F_93 ( 1 ) ;
F_94 ( V_334 , V_3 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_12 ;
F_96 ( V_2 ) ;
F_82 ( V_2 ) ;
F_88 ( V_2 ) ;
F_35 ( V_2 ) ;
if ( V_2 -> V_146 & V_154 ) {
V_12 = F_15 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_2 -> V_111 == V_112 ||
V_2 -> V_111 == V_122 ||
V_2 -> V_111 == V_298 )
F_50 ( V_2 ) ;
if ( V_2 -> V_146 & V_336 ) {
V_12 = F_97 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_98 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_99 ( V_2 , V_337 ) ;
if ( V_12 ) {
F_16 ( V_2 -> V_20 , L_33 , V_12 ) ;
return V_12 ;
}
if ( ! V_2 -> V_338 . V_339 ) {
V_12 = F_100 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
F_101 ( V_2 ) ;
V_2 -> V_54 . V_55 . V_56 = F_32 ( V_53 ) ;
V_12 = F_102 ( V_2 , 1024 * 1024 ) ;
if ( V_12 ) {
F_16 ( V_2 -> V_20 , L_34 , V_12 ) ;
return V_12 ;
}
V_12 = F_103 ( V_2 ) ;
if ( V_12 ) {
F_16 ( V_2 -> V_20 , L_35 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 -> V_146 & V_154 )
F_20 ( V_2 ) ;
if ( V_2 -> V_146 & V_336 )
F_105 ( V_2 ) ;
F_88 ( V_2 ) ;
if ( F_106 ( V_2 ) ) {
F_107 ( V_2 -> V_20 , L_36 ,
F_32 ( V_132 ) ,
F_32 ( V_340 ) ) ;
}
F_108 ( V_2 -> V_341 ) ;
F_88 ( V_2 ) ;
F_109 ( V_2 ) ;
V_2 -> V_342 = true ;
V_12 = F_95 ( V_2 ) ;
if ( V_12 ) {
V_2 -> V_342 = false ;
}
return V_12 ;
}
int F_110 ( struct V_1 * V_2 )
{
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
F_114 ( V_2 ) ;
if ( V_2 -> V_146 & V_154 )
F_20 ( V_2 ) ;
if ( V_2 -> V_146 & V_336 )
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
if ( V_2 -> V_146 & V_154 )
F_22 ( V_2 ) ;
if ( V_2 -> V_146 & V_336 )
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 -> V_343 ) ;
V_2 -> V_343 = NULL ;
}
int F_128 ( struct V_1 * V_2 )
{
int V_12 ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_109 ( V_2 ) ;
F_131 ( V_2 ) ;
if ( ! F_132 ( V_2 ) ) {
if ( F_133 ( V_2 ) )
return - V_21 ;
}
if ( V_2 -> V_344 ) {
F_16 ( V_2 -> V_20 , L_37 ) ;
return - V_21 ;
} else {
V_12 = F_134 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
if ( F_106 ( V_2 ) ) {
F_107 ( V_2 -> V_20 ,
L_36 ,
F_32 ( V_132 ) ,
F_32 ( V_340 ) ) ;
}
if ( F_135 ( V_2 ) == false )
return - V_21 ;
F_31 ( V_2 ) ;
F_136 ( V_2 -> V_341 ) ;
if ( V_2 -> V_146 & V_150 ) {
V_12 = F_137 ( V_2 ) ;
if ( V_12 ) {
F_138 ( V_2 ) ;
}
}
F_54 ( V_2 ) ;
V_12 = F_139 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_140 ( V_2 ) ;
if ( V_12 )
return V_12 ;
if ( V_2 -> V_146 & V_154 ) {
V_12 = F_9 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_2 -> V_146 & V_336 ) {
V_12 = F_141 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
F_80 ( V_2 ) ;
F_142 ( V_2 ) ;
V_2 -> V_342 = true ;
V_12 = F_95 ( V_2 ) ;
if ( V_12 ) {
F_16 ( V_2 -> V_20 , L_38 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_123 ( V_2 ) ;
if ( V_2 -> V_146 & V_154 )
F_22 ( V_2 ) ;
if ( V_2 -> V_146 & V_336 )
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
V_2 -> V_342 = false ;
}
return 0 ;
}
