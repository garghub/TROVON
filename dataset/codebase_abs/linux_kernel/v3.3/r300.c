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
int F_5 ( struct V_1 * V_2 , int V_4 , T_2 V_7 )
{
void T_3 * V_8 = V_2 -> V_9 . V_8 ;
if ( V_4 < 0 || V_4 > V_2 -> V_9 . V_10 ) {
return - V_11 ;
}
V_7 = ( F_6 ( V_7 ) >> 8 ) |
( ( F_7 ( V_7 ) & 0xff ) << 24 ) |
V_12 | V_13 ;
F_8 ( V_7 , ( ( void T_3 * ) V_8 ) + ( V_4 * 4 ) ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_9 . V_15 ) {
F_10 ( 1 , L_1 ) ;
return 0 ;
}
V_14 = F_11 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_12 ( V_2 ) ;
if ( V_14 )
F_13 ( L_2 ) ;
V_2 -> V_9 . V_16 = V_2 -> V_9 . V_10 * 4 ;
V_2 -> V_17 -> V_18 = & F_1 ;
V_2 -> V_17 -> V_19 = & F_5 ;
return F_14 ( V_2 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
T_1 V_20 ;
T_1 V_3 ;
int V_14 ;
if ( V_2 -> V_9 . V_15 == NULL ) {
F_16 ( V_2 -> V_21 , L_3 ) ;
return - V_11 ;
}
V_14 = F_17 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_18 ( V_2 ) ;
V_3 = V_22 ;
F_3 ( V_5 , V_3 ) ;
F_3 ( V_23 , V_2 -> V_24 . V_25 ) ;
V_3 = V_2 -> V_24 . V_26 & ~ V_27 ;
F_3 ( V_28 , V_3 ) ;
F_3 ( V_29 , 0 ) ;
F_3 ( V_30 , 0 ) ;
V_20 = V_2 -> V_9 . V_20 ;
F_3 ( V_31 , V_20 ) ;
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
( unsigned long long ) V_20 ) ;
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
void F_28 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = & V_2 -> V_42 [ V_63 ] ;
unsigned V_64 ;
int V_14 ;
V_64 = ( V_65 | V_66 ) ;
switch( V_2 -> V_67 ) {
case 2 :
V_64 |= V_68 ;
break;
case 3 :
V_64 |= V_69 ;
break;
case 4 :
V_64 |= V_70 ;
break;
case 1 :
default:
V_64 |= V_71 ;
break;
}
V_14 = F_29 ( V_2 , V_42 , 64 ) ;
if ( V_14 ) {
return;
}
F_26 ( V_42 , F_27 ( V_72 , 0 ) ) ;
F_26 ( V_42 ,
V_73 |
V_74 |
V_75 |
V_76 ) ;
F_26 ( V_42 , F_27 ( V_77 , 0 ) ) ;
F_26 ( V_42 , V_64 ) ;
F_26 ( V_42 , F_27 ( V_49 , 0 ) ) ;
F_26 ( V_42 ,
V_51 |
V_50 ) ;
F_26 ( V_42 , F_27 ( V_78 , 0 ) ) ;
F_26 ( V_42 , V_79 ) ;
F_26 ( V_42 , F_27 ( V_80 , 0 ) ) ;
F_26 ( V_42 , 0 ) ;
F_26 ( V_42 , F_27 ( V_81 , 0 ) ) ;
F_26 ( V_42 , 0 ) ;
F_26 ( V_42 , F_27 ( V_45 , 0 ) ) ;
F_26 ( V_42 , V_46 | V_82 ) ;
F_26 ( V_42 , F_27 ( V_47 , 0 ) ) ;
F_26 ( V_42 , V_48 | V_83 ) ;
F_26 ( V_42 , F_27 ( V_49 , 0 ) ) ;
F_26 ( V_42 ,
V_51 |
V_50 ) ;
F_26 ( V_42 , F_27 ( V_84 , 0 ) ) ;
F_26 ( V_42 , 0 ) ;
F_26 ( V_42 , F_27 ( V_45 , 0 ) ) ;
F_26 ( V_42 , V_46 | V_82 ) ;
F_26 ( V_42 , F_27 ( V_47 , 0 ) ) ;
F_26 ( V_42 , V_48 | V_83 ) ;
F_26 ( V_42 , F_27 ( V_85 , 0 ) ) ;
F_26 ( V_42 ,
( ( 6 << V_86 ) |
( 6 << V_87 ) |
( 6 << V_88 ) |
( 6 << V_89 ) |
( 6 << V_90 ) |
( 6 << V_91 ) |
( 6 << V_92 ) |
( 6 << V_93 ) ) ) ;
F_26 ( V_42 , F_27 ( V_94 , 0 ) ) ;
F_26 ( V_42 ,
( ( 6 << V_95 ) |
( 6 << V_96 ) |
( 6 << V_97 ) |
( 6 << V_98 ) |
( 6 << V_99 ) |
( 6 << V_100 ) |
( 6 << V_101 ) ) ) ;
F_26 ( V_42 , F_27 ( V_102 , 0 ) ) ;
F_26 ( V_42 , V_103 | V_104 ) ;
F_26 ( V_42 , F_27 ( V_105 , 0 ) ) ;
F_26 ( V_42 ,
V_106 | V_107 ) ;
F_26 ( V_42 , F_27 ( V_108 , 0 ) ) ;
F_26 ( V_42 ,
V_109 |
V_110 ) ;
F_30 ( V_2 , V_42 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
V_2 -> V_111 = 0 ;
if ( V_2 -> V_112 == V_113 &&
( F_32 ( V_114 ) & V_115 ) == V_116 ) {
V_2 -> V_111 |= V_117 ;
}
}
int F_33 ( struct V_1 * V_2 )
{
unsigned V_4 ;
T_1 V_3 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_118 ; V_4 ++ ) {
V_3 = F_32 ( V_119 ) ;
if ( V_3 & V_120 ) {
return 0 ;
}
F_34 ( 1 ) ;
}
return - 1 ;
}
void F_35 ( struct V_1 * V_2 )
{
T_1 V_64 , V_3 ;
if ( ( V_2 -> V_112 == V_113 && V_2 -> V_121 -> V_122 != 0x4144 ) ||
( V_2 -> V_112 == V_123 && V_2 -> V_121 -> V_122 != 0x4148 ) ) {
V_2 -> V_67 = 2 ;
} else {
V_2 -> V_67 = 1 ;
}
V_2 -> V_124 = 1 ;
V_64 = ( V_65 | V_66 ) ;
switch ( V_2 -> V_67 ) {
case 2 :
V_64 |= V_68 ;
break;
case 3 :
V_64 |= V_69 ;
break;
case 4 :
V_64 |= V_70 ;
break;
default:
case 1 :
V_64 |= V_71 ;
break;
}
F_36 ( V_77 , V_64 ) ;
if ( F_37 ( V_2 ) ) {
F_38 ( V_125 L_5
L_6 ) ;
}
V_3 = F_32 ( V_78 ) ;
F_36 ( V_78 , V_3 | V_79 ) ;
F_36 ( V_126 ,
V_127 |
V_128 ) ;
if ( F_37 ( V_2 ) ) {
F_38 ( V_125 L_5
L_6 ) ;
}
if ( F_33 ( V_2 ) ) {
F_38 ( V_125 L_7
L_6 ) ;
}
F_19 ( L_8 ,
V_2 -> V_67 , V_2 -> V_124 ) ;
}
bool F_39 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
T_4 V_129 ;
int V_14 ;
V_129 = F_32 ( V_130 ) ;
if ( ! F_40 ( V_129 ) ) {
F_41 ( & V_2 -> V_54 . V_55 . V_131 , V_42 ) ;
return false ;
}
V_14 = F_29 ( V_2 , V_42 , 2 ) ;
if ( ! V_14 ) {
F_26 ( V_42 , 0x80000000 ) ;
F_26 ( V_42 , 0x80000000 ) ;
F_30 ( V_2 , V_42 ) ;
}
V_42 -> V_132 = F_32 ( V_133 ) ;
return F_42 ( V_2 , & V_2 -> V_54 . V_55 . V_131 , V_42 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_134 V_135 ;
T_4 V_136 , V_3 ;
int V_137 = 0 ;
V_136 = F_32 ( V_130 ) ;
if ( ! F_40 ( V_136 ) ) {
return 0 ;
}
F_44 ( V_2 , & V_135 ) ;
V_136 = F_32 ( V_130 ) ;
F_45 ( V_2 -> V_21 , L_9 , V_138 , __LINE__ , V_136 ) ;
F_36 ( V_139 , 0 ) ;
V_3 = F_32 ( V_140 ) ;
F_36 ( V_140 , V_3 | V_141 ) ;
F_36 ( V_142 , 0 ) ;
F_36 ( V_143 , 0 ) ;
F_36 ( V_140 , V_3 ) ;
F_46 ( V_2 -> V_121 ) ;
F_47 ( V_2 ) ;
F_36 ( V_144 , F_48 ( 1 ) |
F_49 ( 1 ) ) ;
F_32 ( V_144 ) ;
F_50 ( 500 ) ;
F_36 ( V_144 , 0 ) ;
F_50 ( 1 ) ;
V_136 = F_32 ( V_130 ) ;
F_45 ( V_2 -> V_21 , L_9 , V_138 , __LINE__ , V_136 ) ;
F_36 ( V_144 , F_51 ( 1 ) ) ;
F_32 ( V_144 ) ;
F_50 ( 500 ) ;
F_36 ( V_144 , 0 ) ;
F_50 ( 1 ) ;
V_136 = F_32 ( V_130 ) ;
F_45 ( V_2 -> V_21 , L_9 , V_138 , __LINE__ , V_136 ) ;
F_52 ( V_2 -> V_121 ) ;
F_53 ( V_2 ) ;
if ( F_54 ( V_136 ) || F_55 ( V_136 ) ) {
F_16 ( V_2 -> V_21 , L_10 ) ;
V_2 -> V_145 = true ;
V_137 = - 1 ;
} else
F_45 ( V_2 -> V_21 , L_11 ) ;
F_56 ( V_2 , & V_135 ) ;
return V_137 ;
}
void F_57 ( struct V_1 * V_2 )
{
T_5 V_146 ;
T_4 V_3 ;
V_2 -> V_24 . V_147 = true ;
V_3 = F_32 ( V_148 ) ;
V_3 &= V_149 ;
switch ( V_3 ) {
case 0 : V_2 -> V_24 . V_150 = 64 ; break;
case 1 : V_2 -> V_24 . V_150 = 128 ; break;
case 2 : V_2 -> V_24 . V_150 = 256 ; break;
default: V_2 -> V_24 . V_150 = 128 ; break;
}
F_58 ( V_2 ) ;
V_146 = V_2 -> V_24 . V_151 ;
if ( V_2 -> V_152 & V_153 )
V_146 = ( F_32 ( V_154 ) & 0xffff ) << 16 ;
F_59 ( V_2 , & V_2 -> V_24 , V_146 ) ;
V_2 -> V_24 . V_155 = 0 ;
if ( ! ( V_2 -> V_152 & V_156 ) )
F_60 ( V_2 , & V_2 -> V_24 ) ;
F_61 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 , int V_157 )
{
T_1 V_158 , V_159 ;
if ( V_2 -> V_152 & V_153 )
return;
if ( ! ( V_2 -> V_152 & V_160 ) )
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
int F_63 ( struct V_1 * V_2 )
{
T_4 V_158 ;
if ( V_2 -> V_152 & V_153 )
return 0 ;
if ( ! ( V_2 -> V_152 & V_160 ) )
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
static int F_64 ( struct V_175 * V_176 , void * V_177 )
{
struct V_178 * V_179 = (struct V_178 * ) V_176 -> V_180 ;
struct V_181 * V_21 = V_179 -> V_182 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_183 ;
T_1 V_3 ;
V_3 = F_2 ( V_5 ) ;
F_65 ( V_176 , L_12 , V_3 ) ;
V_3 = F_2 ( V_31 ) ;
F_65 ( V_176 , L_13 , V_3 ) ;
V_3 = F_2 ( V_23 ) ;
F_65 ( V_176 , L_14 , V_3 ) ;
V_3 = F_2 ( V_29 ) ;
F_65 ( V_176 , L_15 , V_3 ) ;
V_3 = F_2 ( V_28 ) ;
F_65 ( V_176 , L_16 , V_3 ) ;
V_3 = F_2 ( V_30 ) ;
F_65 ( V_176 , L_17 , V_3 ) ;
V_3 = F_2 ( V_35 ) ;
F_65 ( V_176 , L_18 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
#if F_66 ( V_184 )
return F_67 ( V_2 , V_185 , 1 ) ;
#else
return 0 ;
#endif
}
static int F_68 ( struct V_186 * V_187 ,
struct V_188 * V_189 ,
unsigned V_190 , unsigned V_191 )
{
struct V_192 * V_193 ;
struct V_194 * V_195 ;
volatile T_1 * V_196 ;
T_1 V_3 , V_197 = 0 ;
unsigned V_4 ;
int V_14 ;
T_4 V_198 ;
V_196 = V_187 -> V_196 -> V_8 ;
V_195 = (struct V_194 * ) V_187 -> V_195 ;
V_198 = F_69 ( V_187 , V_190 ) ;
switch( V_191 ) {
case V_199 :
case V_200 :
V_14 = F_70 ( V_187 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_71 ( V_187 , V_189 ) ;
return V_14 ;
}
break;
case V_201 :
case V_202 :
V_14 = F_72 ( V_187 , V_189 , V_190 , V_191 ) ;
if ( V_14 )
return V_14 ;
break;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
V_4 = ( V_191 - V_203 ) >> 2 ;
V_14 = F_73 ( V_187 , & V_193 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_71 ( V_187 , V_189 ) ;
return V_14 ;
}
V_195 -> V_207 [ V_4 ] . V_15 = V_193 -> V_15 ;
V_195 -> V_207 [ V_4 ] . V_208 = V_198 ;
V_195 -> V_209 = true ;
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
break;
case V_212 :
V_14 = F_73 ( V_187 , & V_193 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_71 ( V_187 , V_189 ) ;
return V_14 ;
}
V_195 -> V_213 . V_15 = V_193 -> V_15 ;
V_195 -> V_213 . V_208 = V_198 ;
V_195 -> V_214 = true ;
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
break;
case V_215 :
case V_215 + 4 :
case V_215 + 8 :
case V_215 + 12 :
case V_215 + 16 :
case V_215 + 20 :
case V_215 + 24 :
case V_215 + 28 :
case V_215 + 32 :
case V_215 + 36 :
case V_215 + 40 :
case V_215 + 44 :
case V_215 + 48 :
case V_215 + 52 :
case V_215 + 56 :
case V_215 + 60 :
V_4 = ( V_191 - V_215 ) >> 2 ;
V_14 = F_73 ( V_187 , & V_193 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_71 ( V_187 , V_189 ) ;
return V_14 ;
}
if ( V_187 -> V_216 & V_217 ) {
V_196 [ V_190 ] = ( V_198 & 31 ) |
( ( V_198 & ~ 31 ) + ( T_4 ) V_193 -> V_210 . V_211 ) ;
} else {
if ( V_193 -> V_210 . V_218 & V_219 )
V_197 |= V_220 ;
if ( V_193 -> V_210 . V_218 & V_221 )
V_197 |= V_222 ;
else if ( V_193 -> V_210 . V_218 & V_223 )
V_197 |= V_224 ;
V_3 = V_198 + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
V_3 |= V_197 ;
V_196 [ V_190 ] = V_3 ;
}
V_195 -> V_225 [ V_4 ] . V_15 = V_193 -> V_15 ;
V_195 -> V_226 = true ;
break;
case 0x2084 :
V_195 -> V_227 = V_198 ;
break;
case 0x20B4 :
V_195 -> V_228 = V_198 & 0x7F ;
break;
case 0x2134 :
V_195 -> V_229 = V_198 & 0x00FFFFFFUL ;
break;
case 0x2088 :
if ( V_187 -> V_2 -> V_112 < V_230 )
goto V_231;
V_195 -> V_232 = V_198 & 0xFFFFFF ;
break;
case 0x43E4 :
V_195 -> V_233 = ( ( V_198 >> 13 ) & 0x1FFF ) + 1 ;
if ( V_187 -> V_2 -> V_112 < V_230 ) {
V_195 -> V_233 -= 1440 ;
}
V_195 -> V_209 = true ;
V_195 -> V_214 = true ;
break;
case 0x4E00 :
if ( ( V_198 & ( 1 << 10 ) ) &&
V_187 -> V_2 -> V_234 != V_187 -> V_235 ) {
F_13 ( L_20 ) ;
return - V_11 ;
}
V_195 -> V_236 = ( ( V_198 >> 5 ) & 0x3 ) + 1 ;
V_195 -> V_209 = true ;
break;
case 0x4E38 :
case 0x4E3C :
case 0x4E40 :
case 0x4E44 :
if ( ! ( V_187 -> V_216 & V_217 ) ) {
V_14 = F_73 ( V_187 , & V_193 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_71 ( V_187 , V_189 ) ;
return V_14 ;
}
if ( V_193 -> V_210 . V_218 & V_219 )
V_197 |= V_237 ;
if ( V_193 -> V_210 . V_218 & V_221 )
V_197 |= V_238 ;
else if ( V_193 -> V_210 . V_218 & V_223 )
V_197 |= V_239 ;
V_3 = V_198 & ~ ( 0x7 << 16 ) ;
V_3 |= V_197 ;
V_196 [ V_190 ] = V_3 ;
}
V_4 = ( V_191 - 0x4E38 ) >> 2 ;
V_195 -> V_207 [ V_4 ] . V_240 = V_198 & 0x3FFE ;
switch ( ( ( V_198 >> 21 ) & 0xF ) ) {
case 9 :
case 11 :
case 12 :
V_195 -> V_207 [ V_4 ] . V_241 = 1 ;
break;
case 3 :
case 4 :
case 13 :
case 15 :
V_195 -> V_207 [ V_4 ] . V_241 = 2 ;
break;
case 5 :
if ( V_187 -> V_2 -> V_112 < V_230 ) {
F_13 ( L_21 ,
( ( V_198 >> 21 ) & 0xF ) ) ;
return - V_11 ;
}
case 6 :
V_195 -> V_207 [ V_4 ] . V_241 = 4 ;
break;
case 10 :
V_195 -> V_207 [ V_4 ] . V_241 = 8 ;
break;
case 7 :
V_195 -> V_207 [ V_4 ] . V_241 = 16 ;
break;
default:
F_13 ( L_22 ,
( ( V_198 >> 21 ) & 0xF ) ) ;
return - V_11 ;
}
V_195 -> V_209 = true ;
break;
case 0x4F00 :
if ( V_198 & 2 ) {
V_195 -> V_242 = true ;
} else {
V_195 -> V_242 = false ;
}
V_195 -> V_214 = true ;
break;
case 0x4F10 :
switch ( ( V_198 & 0xF ) ) {
case 0 :
case 1 :
V_195 -> V_213 . V_241 = 2 ;
break;
case 2 :
V_195 -> V_213 . V_241 = 4 ;
break;
default:
F_13 ( L_23 ,
( V_198 & 0xF ) ) ;
return - V_11 ;
}
V_195 -> V_214 = true ;
break;
case 0x4F24 :
if ( ! ( V_187 -> V_216 & V_217 ) ) {
V_14 = F_73 ( V_187 , & V_193 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_71 ( V_187 , V_189 ) ;
return V_14 ;
}
if ( V_193 -> V_210 . V_218 & V_219 )
V_197 |= V_243 ;
if ( V_193 -> V_210 . V_218 & V_221 )
V_197 |= V_244 ;
else if ( V_193 -> V_210 . V_218 & V_223 )
V_197 |= V_245 ;
V_3 = V_198 & ~ ( 0x7 << 16 ) ;
V_3 |= V_197 ;
V_196 [ V_190 ] = V_3 ;
}
V_195 -> V_213 . V_240 = V_198 & 0x3FFC ;
V_195 -> V_214 = true ;
break;
case 0x4104 :
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
bool V_246 ;
V_246 = ! ! ( V_198 & ( 1 << V_4 ) ) ;
V_195 -> V_225 [ V_4 ] . V_246 = V_246 ;
}
V_195 -> V_226 = true ;
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
V_195 -> V_225 [ V_4 ] . V_247 = V_3 ;
switch ( ( V_198 & 0x1F ) ) {
case V_248 :
case V_249 :
case V_250 :
V_195 -> V_225 [ V_4 ] . V_241 = 1 ;
V_195 -> V_225 [ V_4 ] . V_251 = V_252 ;
break;
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
V_195 -> V_225 [ V_4 ] . V_241 = 2 ;
V_195 -> V_225 [ V_4 ] . V_251 = V_252 ;
break;
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case 0x17 :
case V_269 :
case 0x1e :
V_195 -> V_225 [ V_4 ] . V_241 = 4 ;
V_195 -> V_225 [ V_4 ] . V_251 = V_252 ;
break;
case V_270 :
case V_271 :
case V_272 :
V_195 -> V_225 [ V_4 ] . V_241 = 8 ;
V_195 -> V_225 [ V_4 ] . V_251 = V_252 ;
break;
case V_273 :
V_195 -> V_225 [ V_4 ] . V_241 = 16 ;
V_195 -> V_225 [ V_4 ] . V_251 = V_252 ;
break;
case V_274 :
V_195 -> V_225 [ V_4 ] . V_241 = 1 ;
V_195 -> V_225 [ V_4 ] . V_251 = V_275 ;
break;
case V_276 :
if ( V_187 -> V_2 -> V_112 < V_277 ) {
F_13 ( L_24 ,
( V_198 & 0x1F ) ) ;
return - V_11 ;
}
case V_278 :
case V_279 :
V_195 -> V_225 [ V_4 ] . V_241 = 1 ;
V_195 -> V_225 [ V_4 ] . V_251 = V_280 ;
break;
default:
F_13 ( L_24 ,
( V_198 & 0x1F ) ) ;
return - V_11 ;
}
V_195 -> V_226 = true ;
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
V_195 -> V_225 [ V_4 ] . V_281 = false ;
}
V_3 = ( V_198 >> 3 ) & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_195 -> V_225 [ V_4 ] . V_282 = false ;
}
V_195 -> V_226 = true ;
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
V_195 -> V_225 [ V_4 ] . V_240 = V_3 + 1 ;
if ( V_187 -> V_2 -> V_112 >= V_230 ) {
V_3 = ( ( V_198 >> 15 ) & 1 ) << 11 ;
V_195 -> V_225 [ V_4 ] . V_283 = V_3 ;
V_3 = ( ( V_198 >> 16 ) & 1 ) << 11 ;
V_195 -> V_225 [ V_4 ] . V_284 = V_3 ;
if ( V_198 & ( 1 << 14 ) ) {
V_195 -> V_225 [ V_4 ] . V_251 =
V_275 ;
}
} else if ( V_198 & ( 1 << 14 ) ) {
F_13 ( L_25 ) ;
return - V_11 ;
}
V_195 -> V_226 = true ;
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
V_195 -> V_225 [ V_4 ] . V_285 = V_3 + 1 ;
V_3 = ( V_198 >> 11 ) & 0x7FF ;
V_195 -> V_225 [ V_4 ] . V_286 = V_3 + 1 ;
V_3 = ( V_198 >> 26 ) & 0xF ;
V_195 -> V_225 [ V_4 ] . V_287 = V_3 ;
V_3 = V_198 & ( 1 << 31 ) ;
V_195 -> V_225 [ V_4 ] . V_288 = ! ! V_3 ;
V_3 = ( V_198 >> 22 ) & 0xF ;
V_195 -> V_225 [ V_4 ] . V_289 = V_3 ;
V_195 -> V_226 = true ;
break;
case V_290 :
V_14 = F_73 ( V_187 , & V_193 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_71 ( V_187 , V_189 ) ;
return V_14 ;
}
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
break;
case 0x4e0c :
V_195 -> V_291 = V_198 ;
V_195 -> V_209 = true ;
break;
case 0x43a4 :
if ( V_187 -> V_2 -> V_292 != V_187 -> V_235 ) {
if ( V_198 & 0x1 )
V_196 [ V_190 ] = V_198 & ~ 1 ;
}
break;
case 0x4f1c :
V_195 -> V_293 = ! ! ( V_198 & ( 1 << 5 ) ) ;
V_195 -> V_209 = true ;
V_195 -> V_214 = true ;
if ( V_187 -> V_2 -> V_292 != V_187 -> V_235 ) {
if ( V_198 & ( V_294 |
V_295 |
V_296 |
V_297 ) )
goto V_231;
}
break;
case 0x4e04 :
V_195 -> V_298 = ! ! ( V_198 & ( 1 << 2 ) ) ;
V_195 -> V_209 = true ;
break;
case V_299 :
V_14 = F_73 ( V_187 , & V_193 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_71 ( V_187 , V_189 ) ;
return V_14 ;
}
V_195 -> V_300 . V_15 = V_193 -> V_15 ;
V_195 -> V_300 . V_208 = V_198 ;
V_195 -> V_301 = true ;
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
break;
case V_302 :
V_195 -> V_300 . V_240 = V_198 & 0x3FFE ;
V_195 -> V_301 = true ;
break;
case V_303 :
V_195 -> V_304 = V_198 & 0x1 ;
V_195 -> V_301 = true ;
break;
case 0x4f30 :
case 0x4f34 :
case 0x4f44 :
case 0x4f54 :
if ( V_198 && ( V_187 -> V_2 -> V_292 != V_187 -> V_235 ) )
goto V_231;
break;
case 0x4028 :
if ( V_198 && ( V_187 -> V_2 -> V_292 != V_187 -> V_235 ) )
goto V_231;
if ( V_187 -> V_2 -> V_112 >= V_305 )
break;
goto V_231;
break;
case 0x4be8 :
if ( V_187 -> V_2 -> V_112 == V_306 )
break;
default:
goto V_231;
}
return 0 ;
V_231:
F_38 ( V_307 L_26 ,
V_191 , V_190 , V_198 ) ;
return - V_11 ;
}
static int F_74 ( struct V_186 * V_187 ,
struct V_188 * V_189 )
{
struct V_192 * V_193 ;
struct V_194 * V_195 ;
volatile T_1 * V_196 ;
unsigned V_190 ;
int V_14 ;
V_196 = V_187 -> V_196 -> V_8 ;
V_190 = V_189 -> V_190 + 1 ;
V_195 = (struct V_194 * ) V_187 -> V_195 ;
switch( V_189 -> V_308 ) {
case V_309 :
V_14 = F_75 ( V_187 , V_189 , V_190 ) ;
if ( V_14 )
return V_14 ;
break;
case V_310 :
V_14 = F_73 ( V_187 , & V_193 ) ;
if ( V_14 ) {
F_13 ( L_27 , V_189 -> V_308 ) ;
F_71 ( V_187 , V_189 ) ;
return V_14 ;
}
V_196 [ V_190 + 1 ] = F_69 ( V_187 , V_190 + 1 ) + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
V_14 = F_76 ( V_187 , V_189 , V_193 -> V_15 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_311 :
if ( ( ( F_69 ( V_187 , V_190 + 1 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_11 ;
}
V_195 -> V_227 = F_69 ( V_187 , V_190 + 1 ) ;
V_195 -> V_312 = V_189 -> V_313 - 1 ;
V_14 = F_77 ( V_187 -> V_2 , V_195 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_314 :
if ( ( ( F_69 ( V_187 , V_190 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_11 ;
}
V_195 -> V_227 = F_69 ( V_187 , V_190 ) ;
V_195 -> V_312 = V_189 -> V_313 ;
V_14 = F_77 ( V_187 -> V_2 , V_195 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_315 :
V_195 -> V_227 = F_69 ( V_187 , V_190 + 1 ) ;
V_14 = F_77 ( V_187 -> V_2 , V_195 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_316 :
V_195 -> V_227 = F_69 ( V_187 , V_190 ) ;
V_14 = F_77 ( V_187 -> V_2 , V_195 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_317 :
V_195 -> V_227 = F_69 ( V_187 , V_190 + 1 ) ;
V_14 = F_77 ( V_187 -> V_2 , V_195 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_318 :
V_195 -> V_227 = F_69 ( V_187 , V_190 ) ;
V_14 = F_77 ( V_187 -> V_2 , V_195 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_319 :
case V_320 :
if ( V_187 -> V_2 -> V_292 != V_187 -> V_235 )
return - V_11 ;
break;
case V_321 :
if ( V_187 -> V_2 -> V_234 != V_187 -> V_235 )
return - V_11 ;
break;
case V_322 :
break;
default:
F_13 ( L_29 , V_189 -> V_308 ) ;
return - V_11 ;
}
return 0 ;
}
int F_78 ( struct V_186 * V_187 )
{
struct V_188 V_189 ;
struct V_194 * V_195 ;
int V_14 ;
V_195 = F_79 ( sizeof( * V_195 ) , V_323 ) ;
if ( V_195 == NULL )
return - V_324 ;
F_80 ( V_187 -> V_2 , V_195 ) ;
V_187 -> V_195 = V_195 ;
do {
V_14 = F_81 ( V_187 , & V_189 , V_187 -> V_190 ) ;
if ( V_14 ) {
return V_14 ;
}
V_187 -> V_190 += V_189 . V_313 + 2 ;
switch ( V_189 . type ) {
case V_325 :
V_14 = F_82 ( V_187 , & V_189 ,
V_187 -> V_2 -> V_54 . V_55 . V_326 ,
V_187 -> V_2 -> V_54 . V_55 . V_327 ,
& F_68 ) ;
break;
case V_328 :
break;
case V_329 :
V_14 = F_74 ( V_187 , & V_189 ) ;
break;
default:
F_13 ( L_30 , V_189 . type ) ;
return - V_11 ;
}
if ( V_14 ) {
return V_14 ;
}
} while ( V_187 -> V_190 < V_187 -> V_330 [ V_187 -> V_331 ] . V_332 );
return 0 ;
}
void F_83 ( struct V_1 * V_2 )
{
V_2 -> V_54 . V_55 . V_326 = V_333 ;
V_2 -> V_54 . V_55 . V_327 = F_84 ( V_333 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_134 V_135 ;
int V_14 ;
V_14 = F_86 ( V_2 ) ;
if ( V_14 ) {
F_16 ( V_2 -> V_21 , L_31 ) ;
}
F_44 ( V_2 , & V_135 ) ;
if ( V_2 -> V_152 & V_156 ) {
F_36 ( V_334 ,
F_87 ( V_2 -> V_24 . V_25 >> 16 ) |
F_88 ( V_2 -> V_24 . V_26 >> 16 ) ) ;
F_36 ( V_335 , F_6 ( V_2 -> V_24 . V_336 ) ) ;
F_36 ( V_337 ,
F_7 ( V_2 -> V_24 . V_336 ) & 0xff ) ;
} else {
F_36 ( V_334 , 0x0FFFFFFF ) ;
F_36 ( V_335 , 0 ) ;
F_36 ( V_337 , 0 ) ;
}
if ( F_33 ( V_2 ) )
F_19 ( L_32 ) ;
F_36 ( V_338 ,
F_89 ( V_2 -> V_24 . V_33 >> 16 ) |
F_90 ( V_2 -> V_24 . V_339 >> 16 ) ) ;
F_56 ( V_2 , & V_135 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
T_4 V_3 ;
if ( V_340 != - 1 && V_340 )
F_92 ( V_2 , 1 ) ;
V_3 = F_93 ( V_341 ) ;
V_3 |= F_94 ( 1 ) | F_95 ( 1 ) ;
if ( ( V_2 -> V_112 == V_305 ) || ( V_2 -> V_112 == V_342 ) )
V_3 |= F_96 ( 1 ) ;
F_97 ( V_341 , V_3 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_14 ;
F_99 ( V_2 ) ;
F_85 ( V_2 ) ;
F_91 ( V_2 ) ;
F_35 ( V_2 ) ;
if ( V_2 -> V_152 & V_160 ) {
V_14 = F_15 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_112 == V_113 ||
V_2 -> V_112 == V_123 ||
V_2 -> V_112 == V_305 )
F_53 ( V_2 ) ;
if ( V_2 -> V_152 & V_343 ) {
V_14 = F_100 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_101 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_102 ( V_2 , V_63 ) ;
if ( V_14 ) {
F_16 ( V_2 -> V_21 , L_33 , V_14 ) ;
return V_14 ;
}
F_103 ( V_2 ) ;
V_2 -> V_54 . V_55 . V_56 = F_32 ( V_53 ) ;
V_14 = F_104 ( V_2 , 1024 * 1024 ) ;
if ( V_14 ) {
F_16 ( V_2 -> V_21 , L_34 , V_14 ) ;
return V_14 ;
}
V_14 = F_105 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_106 ( V_2 ) ;
if ( V_14 ) {
F_16 ( V_2 -> V_21 , L_35 , V_14 ) ;
V_2 -> V_344 = false ;
return V_14 ;
}
return 0 ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_152 & V_160 )
F_20 ( V_2 ) ;
if ( V_2 -> V_152 & V_343 )
F_108 ( V_2 ) ;
F_91 ( V_2 ) ;
if ( F_109 ( V_2 ) ) {
F_110 ( V_2 -> V_21 , L_36 ,
F_32 ( V_130 ) ,
F_32 ( V_345 ) ) ;
}
F_111 ( V_2 -> V_346 ) ;
F_91 ( V_2 ) ;
F_112 ( V_2 ) ;
V_2 -> V_344 = true ;
V_14 = F_98 ( V_2 ) ;
if ( V_14 ) {
V_2 -> V_344 = false ;
}
return V_14 ;
}
int F_113 ( struct V_1 * V_2 )
{
F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
if ( V_2 -> V_152 & V_160 )
F_20 ( V_2 ) ;
if ( V_2 -> V_152 & V_343 )
F_108 ( V_2 ) ;
return 0 ;
}
void F_118 ( struct V_1 * V_2 )
{
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
if ( V_2 -> V_152 & V_160 )
F_22 ( V_2 ) ;
if ( V_2 -> V_152 & V_343 )
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 -> V_347 ) ;
V_2 -> V_347 = NULL ;
}
int F_130 ( struct V_1 * V_2 )
{
int V_14 ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_112 ( V_2 ) ;
F_133 ( V_2 ) ;
if ( ! F_134 ( V_2 ) ) {
if ( F_135 ( V_2 ) )
return - V_11 ;
}
if ( V_2 -> V_348 ) {
F_16 ( V_2 -> V_21 , L_37 ) ;
return - V_11 ;
} else {
V_14 = F_136 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( F_109 ( V_2 ) ) {
F_110 ( V_2 -> V_21 ,
L_36 ,
F_32 ( V_130 ) ,
F_32 ( V_345 ) ) ;
}
if ( F_137 ( V_2 ) == false )
return - V_11 ;
F_31 ( V_2 ) ;
F_138 ( V_2 -> V_346 ) ;
if ( V_2 -> V_152 & V_156 ) {
V_14 = F_139 ( V_2 ) ;
if ( V_14 ) {
F_140 ( V_2 ) ;
}
}
F_57 ( V_2 ) ;
V_14 = F_141 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_142 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_143 ( V_2 ) ;
if ( V_14 )
return V_14 ;
if ( V_2 -> V_152 & V_160 ) {
V_14 = F_9 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_152 & V_343 ) {
V_14 = F_144 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
F_83 ( V_2 ) ;
V_14 = F_145 ( V_2 ) ;
V_2 -> V_344 = true ;
if ( V_14 ) {
F_16 ( V_2 -> V_21 , L_38 , V_14 ) ;
V_2 -> V_344 = false ;
}
V_14 = F_98 ( V_2 ) ;
if ( V_14 ) {
F_16 ( V_2 -> V_21 , L_39 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_125 ( V_2 ) ;
if ( V_2 -> V_152 & V_160 )
F_22 ( V_2 ) ;
if ( V_2 -> V_152 & V_343 )
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
V_2 -> V_344 = false ;
}
return 0 ;
}
