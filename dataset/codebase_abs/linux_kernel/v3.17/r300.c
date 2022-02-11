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
T_2 V_7 , T_1 V_8 )
{
void T_3 * V_9 = V_2 -> V_10 . V_9 ;
V_7 = ( F_6 ( V_7 ) >> 8 ) |
( ( F_7 ( V_7 ) & 0xff ) << 24 ) ;
if ( V_8 & V_11 )
V_7 |= V_12 ;
if ( V_8 & V_13 )
V_7 |= V_14 ;
if ( ! ( V_8 & V_15 ) )
V_7 |= V_16 ;
F_8 ( V_7 , ( ( void T_3 * ) V_9 ) + ( V_4 * 4 ) ) ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_17 ;
if ( V_2 -> V_10 . V_18 ) {
F_10 ( 1 , L_1 ) ;
return 0 ;
}
V_17 = F_11 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_12 ( V_2 ) ;
if ( V_17 )
F_13 ( L_2 ) ;
V_2 -> V_10 . V_19 = V_2 -> V_10 . V_20 * 4 ;
V_2 -> V_21 -> V_10 . V_22 = & F_1 ;
V_2 -> V_21 -> V_10 . V_23 = & F_5 ;
return F_14 ( V_2 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
T_1 V_24 ;
T_1 V_3 ;
int V_17 ;
if ( V_2 -> V_10 . V_18 == NULL ) {
F_16 ( V_2 -> V_25 , L_3 ) ;
return - V_26 ;
}
V_17 = F_17 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_3 = V_27 ;
F_3 ( V_5 , V_3 ) ;
F_3 ( V_28 , V_2 -> V_29 . V_30 ) ;
V_3 = V_2 -> V_29 . V_31 & ~ V_32 ;
F_3 ( V_33 , V_3 ) ;
F_3 ( V_34 , 0 ) ;
F_3 ( V_35 , 0 ) ;
V_24 = V_2 -> V_10 . V_24 ;
F_3 ( V_36 , V_24 ) ;
F_3 ( V_37 , V_2 -> V_29 . V_38 ) ;
F_3 ( V_39 , 0 ) ;
F_3 ( V_40 , 0 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_41 ;
V_3 |= V_27 ;
F_3 ( V_5 , V_3 ) ;
F_1 ( V_2 ) ;
F_18 ( L_4 ,
( unsigned ) ( V_2 -> V_29 . V_42 >> 20 ) ,
( unsigned long long ) V_24 ) ;
V_2 -> V_10 . V_43 = true ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
T_4 V_3 ;
F_3 ( V_28 , 0 ) ;
F_3 ( V_33 , 0 ) ;
F_3 ( V_34 , 0 ) ;
F_3 ( V_35 , 0 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_27 ;
F_3 ( V_5 , V_3 & ~ V_41 ) ;
F_20 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_19 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 = & V_2 -> V_47 [ V_45 -> V_47 ] ;
F_25 ( V_47 , F_26 ( V_48 , 0 ) ) ;
F_25 ( V_47 , 0 ) ;
F_25 ( V_47 , F_26 ( V_49 , 0 ) ) ;
F_25 ( V_47 , 0 ) ;
F_25 ( V_47 , F_26 ( V_50 , 0 ) ) ;
F_25 ( V_47 , V_51 ) ;
F_25 ( V_47 , F_26 ( V_52 , 0 ) ) ;
F_25 ( V_47 , V_53 ) ;
F_25 ( V_47 , F_26 ( V_54 , 0 ) ) ;
F_25 ( V_47 , ( V_55 |
V_56 |
V_57 ) ) ;
F_25 ( V_47 , F_26 ( V_58 , 0 ) ) ;
F_25 ( V_47 , V_2 -> V_59 . V_60 . V_61 |
V_62 ) ;
F_25 ( V_47 , F_26 ( V_58 , 0 ) ) ;
F_25 ( V_47 , V_2 -> V_59 . V_60 . V_61 ) ;
F_25 ( V_47 , F_26 ( V_2 -> V_63 [ V_45 -> V_47 ] . V_64 , 0 ) ) ;
F_25 ( V_47 , V_45 -> V_65 ) ;
F_25 ( V_47 , F_26 ( V_66 , 0 ) ) ;
F_25 ( V_47 , V_67 ) ;
}
void F_27 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
unsigned V_68 ;
int V_17 ;
V_68 = ( V_69 | V_70 ) ;
switch( V_2 -> V_71 ) {
case 2 :
V_68 |= V_72 ;
break;
case 3 :
V_68 |= V_73 ;
break;
case 4 :
V_68 |= V_74 ;
break;
case 1 :
default:
V_68 |= V_75 ;
break;
}
V_17 = F_28 ( V_2 , V_47 , 64 ) ;
if ( V_17 ) {
return;
}
F_25 ( V_47 , F_26 ( V_76 , 0 ) ) ;
F_25 ( V_47 ,
V_77 |
V_78 |
V_79 |
V_80 ) ;
F_25 ( V_47 , F_26 ( V_81 , 0 ) ) ;
F_25 ( V_47 , V_68 ) ;
F_25 ( V_47 , F_26 ( V_54 , 0 ) ) ;
F_25 ( V_47 ,
V_56 |
V_55 ) ;
F_25 ( V_47 , F_26 ( V_82 , 0 ) ) ;
F_25 ( V_47 , V_83 ) ;
F_25 ( V_47 , F_26 ( V_84 , 0 ) ) ;
F_25 ( V_47 , 0 ) ;
F_25 ( V_47 , F_26 ( V_85 , 0 ) ) ;
F_25 ( V_47 , 0 ) ;
F_25 ( V_47 , F_26 ( V_50 , 0 ) ) ;
F_25 ( V_47 , V_51 | V_86 ) ;
F_25 ( V_47 , F_26 ( V_52 , 0 ) ) ;
F_25 ( V_47 , V_53 | V_87 ) ;
F_25 ( V_47 , F_26 ( V_54 , 0 ) ) ;
F_25 ( V_47 ,
V_56 |
V_55 ) ;
F_25 ( V_47 , F_26 ( V_88 , 0 ) ) ;
F_25 ( V_47 , 0 ) ;
F_25 ( V_47 , F_26 ( V_50 , 0 ) ) ;
F_25 ( V_47 , V_51 | V_86 ) ;
F_25 ( V_47 , F_26 ( V_52 , 0 ) ) ;
F_25 ( V_47 , V_53 | V_87 ) ;
F_25 ( V_47 , F_26 ( V_89 , 0 ) ) ;
F_25 ( V_47 ,
( ( 6 << V_90 ) |
( 6 << V_91 ) |
( 6 << V_92 ) |
( 6 << V_93 ) |
( 6 << V_94 ) |
( 6 << V_95 ) |
( 6 << V_96 ) |
( 6 << V_97 ) ) ) ;
F_25 ( V_47 , F_26 ( V_98 , 0 ) ) ;
F_25 ( V_47 ,
( ( 6 << V_99 ) |
( 6 << V_100 ) |
( 6 << V_101 ) |
( 6 << V_102 ) |
( 6 << V_103 ) |
( 6 << V_104 ) |
( 6 << V_105 ) ) ) ;
F_25 ( V_47 , F_26 ( V_106 , 0 ) ) ;
F_25 ( V_47 , V_107 | V_108 ) ;
F_25 ( V_47 , F_26 ( V_109 , 0 ) ) ;
F_25 ( V_47 ,
V_110 | V_111 ) ;
F_25 ( V_47 , F_26 ( V_112 , 0 ) ) ;
F_25 ( V_47 ,
V_113 |
V_114 ) ;
F_29 ( V_2 , V_47 , false ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_115 = 0 ;
if ( V_2 -> V_116 == V_117 &&
( F_31 ( V_118 ) & V_119 ) == V_120 ) {
V_2 -> V_115 |= V_121 ;
}
}
int F_32 ( struct V_1 * V_2 )
{
unsigned V_4 ;
T_1 V_3 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_122 ; V_4 ++ ) {
V_3 = F_31 ( V_123 ) ;
if ( V_3 & V_124 ) {
return 0 ;
}
F_33 ( 1 ) ;
}
return - 1 ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_68 , V_3 ;
if ( ( V_2 -> V_116 == V_117 && V_2 -> V_125 -> V_126 != 0x4144 ) ||
( V_2 -> V_116 == V_127 && V_2 -> V_125 -> V_126 != 0x4148 ) ) {
V_2 -> V_71 = 2 ;
} else {
V_2 -> V_71 = 1 ;
}
V_2 -> V_128 = 1 ;
V_68 = ( V_69 | V_70 ) ;
switch ( V_2 -> V_71 ) {
case 2 :
V_68 |= V_72 ;
break;
case 3 :
V_68 |= V_73 ;
break;
case 4 :
V_68 |= V_74 ;
break;
default:
case 1 :
V_68 |= V_75 ;
break;
}
F_35 ( V_81 , V_68 ) ;
if ( F_36 ( V_2 ) ) {
F_37 ( V_129 L_5
L_6 ) ;
}
V_3 = F_31 ( V_82 ) ;
F_35 ( V_82 , V_3 | V_83 ) ;
F_35 ( V_130 ,
V_131 |
V_132 ) ;
if ( F_36 ( V_2 ) ) {
F_37 ( V_129 L_5
L_6 ) ;
}
if ( F_32 ( V_2 ) ) {
F_37 ( V_129 L_7
L_6 ) ;
}
F_18 ( L_8 ,
V_2 -> V_71 , V_2 -> V_128 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_133 V_134 ;
T_4 V_135 , V_3 ;
int V_136 = 0 ;
V_135 = F_31 ( V_137 ) ;
if ( ! F_39 ( V_135 ) ) {
return 0 ;
}
F_40 ( V_2 , & V_134 ) ;
V_135 = F_31 ( V_137 ) ;
F_41 ( V_2 -> V_25 , L_9 , V_138 , __LINE__ , V_135 ) ;
F_35 ( V_139 , 0 ) ;
V_3 = F_31 ( V_140 ) ;
F_35 ( V_140 , V_3 | V_141 ) ;
F_35 ( V_142 , 0 ) ;
F_35 ( V_143 , 0 ) ;
F_35 ( V_140 , V_3 ) ;
F_42 ( V_2 -> V_125 ) ;
F_43 ( V_2 ) ;
F_35 ( V_144 , F_44 ( 1 ) |
F_45 ( 1 ) ) ;
F_31 ( V_144 ) ;
F_46 ( 500 ) ;
F_35 ( V_144 , 0 ) ;
F_46 ( 1 ) ;
V_135 = F_31 ( V_137 ) ;
F_41 ( V_2 -> V_25 , L_9 , V_138 , __LINE__ , V_135 ) ;
F_35 ( V_144 , F_47 ( 1 ) ) ;
F_31 ( V_144 ) ;
F_46 ( 500 ) ;
F_35 ( V_144 , 0 ) ;
F_46 ( 1 ) ;
V_135 = F_31 ( V_137 ) ;
F_41 ( V_2 -> V_25 , L_9 , V_138 , __LINE__ , V_135 ) ;
F_48 ( V_2 -> V_125 ) ;
F_49 ( V_2 ) ;
if ( F_50 ( V_135 ) || F_51 ( V_135 ) ) {
F_16 ( V_2 -> V_25 , L_10 ) ;
V_136 = - 1 ;
} else
F_41 ( V_2 -> V_25 , L_11 ) ;
F_52 ( V_2 , & V_134 ) ;
return V_136 ;
}
void F_53 ( struct V_1 * V_2 )
{
T_5 V_145 ;
T_4 V_3 ;
V_2 -> V_29 . V_146 = true ;
V_3 = F_31 ( V_147 ) ;
V_3 &= V_148 ;
switch ( V_3 ) {
case 0 : V_2 -> V_29 . V_149 = 64 ; break;
case 1 : V_2 -> V_29 . V_149 = 128 ; break;
case 2 : V_2 -> V_29 . V_149 = 256 ; break;
default: V_2 -> V_29 . V_149 = 128 ; break;
}
F_54 ( V_2 ) ;
V_145 = V_2 -> V_29 . V_150 ;
if ( V_2 -> V_8 & V_151 )
V_145 = ( F_31 ( V_152 ) & 0xffff ) << 16 ;
F_55 ( V_2 , & V_2 -> V_29 , V_145 ) ;
V_2 -> V_29 . V_153 = 0 ;
if ( ! ( V_2 -> V_8 & V_154 ) )
F_56 ( V_2 , & V_2 -> V_29 ) ;
F_57 ( V_2 ) ;
}
void F_58 ( struct V_1 * V_2 , int V_155 )
{
T_1 V_156 , V_157 ;
if ( V_2 -> V_8 & V_151 )
return;
if ( ! ( V_2 -> V_8 & V_158 ) )
return;
switch ( V_155 ) {
case 0 :
V_157 = V_159 ;
break;
case 1 :
V_157 = V_160 ;
break;
case 2 :
V_157 = V_161 ;
break;
case 4 :
V_157 = V_162 ;
break;
case 8 :
V_157 = V_163 ;
break;
case 12 :
V_157 = V_164 ;
break;
case 16 :
default:
V_157 = V_165 ;
break;
}
V_156 = F_2 ( V_166 ) ;
if ( ( V_156 & V_167 ) ==
( V_157 << V_168 ) )
return;
V_156 &= ~ ( V_169 |
V_170 |
V_171 |
V_172 ) ;
V_156 |= V_157 ;
F_3 ( V_166 , V_156 ) ;
F_3 ( V_166 , ( V_156 |
V_170 ) ) ;
V_156 = F_2 ( V_166 ) ;
while ( V_156 == 0xffffffff )
V_156 = F_2 ( V_166 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
T_4 V_156 ;
if ( V_2 -> V_8 & V_151 )
return 0 ;
if ( ! ( V_2 -> V_8 & V_158 ) )
return 0 ;
V_156 = F_2 ( V_166 ) ;
switch ( ( V_156 & V_167 ) >> V_168 ) {
case V_159 :
return 0 ;
case V_160 :
return 1 ;
case V_161 :
return 2 ;
case V_162 :
return 4 ;
case V_163 :
return 8 ;
case V_165 :
default:
return 16 ;
}
}
static int F_60 ( struct V_173 * V_174 , void * V_175 )
{
struct V_176 * V_177 = (struct V_176 * ) V_174 -> V_178 ;
struct V_179 * V_25 = V_177 -> V_180 -> V_25 ;
struct V_1 * V_2 = V_25 -> V_181 ;
T_1 V_3 ;
V_3 = F_2 ( V_5 ) ;
F_61 ( V_174 , L_12 , V_3 ) ;
V_3 = F_2 ( V_36 ) ;
F_61 ( V_174 , L_13 , V_3 ) ;
V_3 = F_2 ( V_28 ) ;
F_61 ( V_174 , L_14 , V_3 ) ;
V_3 = F_2 ( V_34 ) ;
F_61 ( V_174 , L_15 , V_3 ) ;
V_3 = F_2 ( V_33 ) ;
F_61 ( V_174 , L_16 , V_3 ) ;
V_3 = F_2 ( V_35 ) ;
F_61 ( V_174 , L_17 , V_3 ) ;
V_3 = F_2 ( V_40 ) ;
F_61 ( V_174 , L_18 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
#if F_62 ( V_182 )
return F_63 ( V_2 , V_183 , 1 ) ;
#else
return 0 ;
#endif
}
static int F_64 ( struct V_184 * V_185 ,
struct V_186 * V_187 ,
unsigned V_188 , unsigned V_189 )
{
struct V_190 * V_191 ;
struct V_192 * V_193 ;
volatile T_1 * V_194 ;
T_1 V_3 , V_195 = 0 ;
unsigned V_4 ;
int V_17 ;
T_4 V_196 ;
V_194 = V_185 -> V_194 . V_9 ;
V_193 = (struct V_192 * ) V_185 -> V_193 ;
V_196 = F_65 ( V_185 , V_188 ) ;
switch( V_189 ) {
case V_197 :
case V_198 :
V_17 = F_66 ( V_185 ) ;
if ( V_17 ) {
F_13 ( L_19 ,
V_188 , V_189 ) ;
F_67 ( V_185 , V_187 ) ;
return V_17 ;
}
break;
case V_199 :
case V_200 :
V_17 = F_68 ( V_185 , V_187 , V_188 , V_189 ) ;
if ( V_17 )
return V_17 ;
break;
case V_201 :
case V_202 :
case V_203 :
case V_204 :
V_4 = ( V_189 - V_201 ) >> 2 ;
V_17 = F_69 ( V_185 , & V_191 , 0 ) ;
if ( V_17 ) {
F_13 ( L_19 ,
V_188 , V_189 ) ;
F_67 ( V_185 , V_187 ) ;
return V_17 ;
}
V_193 -> V_205 [ V_4 ] . V_18 = V_191 -> V_18 ;
V_193 -> V_205 [ V_4 ] . V_206 = V_196 ;
V_193 -> V_207 = true ;
V_194 [ V_188 ] = V_196 + ( ( T_4 ) V_191 -> V_208 ) ;
break;
case V_209 :
V_17 = F_69 ( V_185 , & V_191 , 0 ) ;
if ( V_17 ) {
F_13 ( L_19 ,
V_188 , V_189 ) ;
F_67 ( V_185 , V_187 ) ;
return V_17 ;
}
V_193 -> V_210 . V_18 = V_191 -> V_18 ;
V_193 -> V_210 . V_206 = V_196 ;
V_193 -> V_211 = true ;
V_194 [ V_188 ] = V_196 + ( ( T_4 ) V_191 -> V_208 ) ;
break;
case V_212 :
case V_212 + 4 :
case V_212 + 8 :
case V_212 + 12 :
case V_212 + 16 :
case V_212 + 20 :
case V_212 + 24 :
case V_212 + 28 :
case V_212 + 32 :
case V_212 + 36 :
case V_212 + 40 :
case V_212 + 44 :
case V_212 + 48 :
case V_212 + 52 :
case V_212 + 56 :
case V_212 + 60 :
V_4 = ( V_189 - V_212 ) >> 2 ;
V_17 = F_69 ( V_185 , & V_191 , 0 ) ;
if ( V_17 ) {
F_13 ( L_19 ,
V_188 , V_189 ) ;
F_67 ( V_185 , V_187 ) ;
return V_17 ;
}
if ( V_185 -> V_213 & V_214 ) {
V_194 [ V_188 ] = ( V_196 & 31 ) |
( ( V_196 & ~ 31 ) + ( T_4 ) V_191 -> V_208 ) ;
} else {
if ( V_191 -> V_215 & V_216 )
V_195 |= V_217 ;
if ( V_191 -> V_215 & V_218 )
V_195 |= V_219 ;
else if ( V_191 -> V_215 & V_220 )
V_195 |= V_221 ;
V_3 = V_196 + ( ( T_4 ) V_191 -> V_208 ) ;
V_3 |= V_195 ;
V_194 [ V_188 ] = V_3 ;
}
V_193 -> V_222 [ V_4 ] . V_18 = V_191 -> V_18 ;
V_193 -> V_223 = true ;
break;
case 0x2084 :
V_193 -> V_224 = V_196 ;
break;
case 0x20B4 :
V_193 -> V_225 = V_196 & 0x7F ;
break;
case 0x2134 :
V_193 -> V_226 = V_196 & 0x00FFFFFFUL ;
break;
case 0x2088 :
if ( V_185 -> V_2 -> V_116 < V_227 )
goto V_228;
V_193 -> V_229 = V_196 & 0xFFFFFF ;
break;
case 0x43E4 :
V_193 -> V_230 = ( ( V_196 >> 13 ) & 0x1FFF ) + 1 ;
if ( V_185 -> V_2 -> V_116 < V_227 ) {
V_193 -> V_230 -= 1440 ;
}
V_193 -> V_207 = true ;
V_193 -> V_211 = true ;
break;
case 0x4E00 :
if ( ( V_196 & ( 1 << 10 ) ) &&
V_185 -> V_2 -> V_231 != V_185 -> V_232 ) {
F_13 ( L_20 ) ;
return - V_26 ;
}
V_193 -> V_233 = ( ( V_196 >> 5 ) & 0x3 ) + 1 ;
V_193 -> V_207 = true ;
break;
case 0x4E38 :
case 0x4E3C :
case 0x4E40 :
case 0x4E44 :
if ( ! ( V_185 -> V_213 & V_214 ) ) {
V_17 = F_69 ( V_185 , & V_191 , 0 ) ;
if ( V_17 ) {
F_13 ( L_19 ,
V_188 , V_189 ) ;
F_67 ( V_185 , V_187 ) ;
return V_17 ;
}
if ( V_191 -> V_215 & V_216 )
V_195 |= V_234 ;
if ( V_191 -> V_215 & V_218 )
V_195 |= V_235 ;
else if ( V_191 -> V_215 & V_220 )
V_195 |= V_236 ;
V_3 = V_196 & ~ ( 0x7 << 16 ) ;
V_3 |= V_195 ;
V_194 [ V_188 ] = V_3 ;
}
V_4 = ( V_189 - 0x4E38 ) >> 2 ;
V_193 -> V_205 [ V_4 ] . V_237 = V_196 & 0x3FFE ;
switch ( ( ( V_196 >> 21 ) & 0xF ) ) {
case 9 :
case 11 :
case 12 :
V_193 -> V_205 [ V_4 ] . V_238 = 1 ;
break;
case 3 :
case 4 :
case 13 :
case 15 :
V_193 -> V_205 [ V_4 ] . V_238 = 2 ;
break;
case 5 :
if ( V_185 -> V_2 -> V_116 < V_227 ) {
F_13 ( L_21 ,
( ( V_196 >> 21 ) & 0xF ) ) ;
return - V_26 ;
}
case 6 :
V_193 -> V_205 [ V_4 ] . V_238 = 4 ;
break;
case 10 :
V_193 -> V_205 [ V_4 ] . V_238 = 8 ;
break;
case 7 :
V_193 -> V_205 [ V_4 ] . V_238 = 16 ;
break;
default:
F_13 ( L_22 ,
( ( V_196 >> 21 ) & 0xF ) ) ;
return - V_26 ;
}
V_193 -> V_207 = true ;
break;
case 0x4F00 :
if ( V_196 & 2 ) {
V_193 -> V_239 = true ;
} else {
V_193 -> V_239 = false ;
}
V_193 -> V_211 = true ;
break;
case 0x4F10 :
switch ( ( V_196 & 0xF ) ) {
case 0 :
case 1 :
V_193 -> V_210 . V_238 = 2 ;
break;
case 2 :
V_193 -> V_210 . V_238 = 4 ;
break;
default:
F_13 ( L_23 ,
( V_196 & 0xF ) ) ;
return - V_26 ;
}
V_193 -> V_211 = true ;
break;
case 0x4F24 :
if ( ! ( V_185 -> V_213 & V_214 ) ) {
V_17 = F_69 ( V_185 , & V_191 , 0 ) ;
if ( V_17 ) {
F_13 ( L_19 ,
V_188 , V_189 ) ;
F_67 ( V_185 , V_187 ) ;
return V_17 ;
}
if ( V_191 -> V_215 & V_216 )
V_195 |= V_240 ;
if ( V_191 -> V_215 & V_218 )
V_195 |= V_241 ;
else if ( V_191 -> V_215 & V_220 )
V_195 |= V_242 ;
V_3 = V_196 & ~ ( 0x7 << 16 ) ;
V_3 |= V_195 ;
V_194 [ V_188 ] = V_3 ;
}
V_193 -> V_210 . V_237 = V_196 & 0x3FFC ;
V_193 -> V_211 = true ;
break;
case 0x4104 :
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
bool V_243 ;
V_243 = ! ! ( V_196 & ( 1 << V_4 ) ) ;
V_193 -> V_222 [ V_4 ] . V_243 = V_243 ;
}
V_193 -> V_223 = true ;
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
V_4 = ( V_189 - 0x44C0 ) >> 2 ;
V_3 = ( V_196 >> 25 ) & 0x3 ;
V_193 -> V_222 [ V_4 ] . V_244 = V_3 ;
switch ( ( V_196 & 0x1F ) ) {
case V_245 :
case V_246 :
case V_247 :
V_193 -> V_222 [ V_4 ] . V_238 = 1 ;
V_193 -> V_222 [ V_4 ] . V_248 = V_249 ;
break;
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
V_193 -> V_222 [ V_4 ] . V_238 = 2 ;
V_193 -> V_222 [ V_4 ] . V_248 = V_249 ;
break;
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case 0x17 :
case V_266 :
case 0x1e :
V_193 -> V_222 [ V_4 ] . V_238 = 4 ;
V_193 -> V_222 [ V_4 ] . V_248 = V_249 ;
break;
case V_267 :
case V_268 :
case V_269 :
V_193 -> V_222 [ V_4 ] . V_238 = 8 ;
V_193 -> V_222 [ V_4 ] . V_248 = V_249 ;
break;
case V_270 :
V_193 -> V_222 [ V_4 ] . V_238 = 16 ;
V_193 -> V_222 [ V_4 ] . V_248 = V_249 ;
break;
case V_271 :
V_193 -> V_222 [ V_4 ] . V_238 = 1 ;
V_193 -> V_222 [ V_4 ] . V_248 = V_272 ;
break;
case V_273 :
if ( V_185 -> V_2 -> V_116 < V_274 ) {
F_13 ( L_24 ,
( V_196 & 0x1F ) ) ;
return - V_26 ;
}
case V_275 :
case V_276 :
V_193 -> V_222 [ V_4 ] . V_238 = 1 ;
V_193 -> V_222 [ V_4 ] . V_248 = V_277 ;
break;
default:
F_13 ( L_24 ,
( V_196 & 0x1F ) ) ;
return - V_26 ;
}
V_193 -> V_223 = true ;
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
V_4 = ( V_189 - 0x4400 ) >> 2 ;
V_3 = V_196 & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_193 -> V_222 [ V_4 ] . V_278 = false ;
}
V_3 = ( V_196 >> 3 ) & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_193 -> V_222 [ V_4 ] . V_279 = false ;
}
V_193 -> V_223 = true ;
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
V_4 = ( V_189 - 0x4500 ) >> 2 ;
V_3 = V_196 & 0x3FFF ;
V_193 -> V_222 [ V_4 ] . V_237 = V_3 + 1 ;
if ( V_185 -> V_2 -> V_116 >= V_227 ) {
V_3 = ( ( V_196 >> 15 ) & 1 ) << 11 ;
V_193 -> V_222 [ V_4 ] . V_280 = V_3 ;
V_3 = ( ( V_196 >> 16 ) & 1 ) << 11 ;
V_193 -> V_222 [ V_4 ] . V_281 = V_3 ;
if ( V_196 & ( 1 << 14 ) ) {
V_193 -> V_222 [ V_4 ] . V_248 =
V_272 ;
}
} else if ( V_196 & ( 1 << 14 ) ) {
F_13 ( L_25 ) ;
return - V_26 ;
}
V_193 -> V_223 = true ;
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
V_4 = ( V_189 - 0x4480 ) >> 2 ;
V_3 = V_196 & 0x7FF ;
V_193 -> V_222 [ V_4 ] . V_282 = V_3 + 1 ;
V_3 = ( V_196 >> 11 ) & 0x7FF ;
V_193 -> V_222 [ V_4 ] . V_283 = V_3 + 1 ;
V_3 = ( V_196 >> 26 ) & 0xF ;
V_193 -> V_222 [ V_4 ] . V_284 = V_3 ;
V_3 = V_196 & ( 1 << 31 ) ;
V_193 -> V_222 [ V_4 ] . V_285 = ! ! V_3 ;
V_3 = ( V_196 >> 22 ) & 0xF ;
V_193 -> V_222 [ V_4 ] . V_286 = V_3 ;
V_193 -> V_223 = true ;
break;
case V_287 :
V_17 = F_69 ( V_185 , & V_191 , 0 ) ;
if ( V_17 ) {
F_13 ( L_19 ,
V_188 , V_189 ) ;
F_67 ( V_185 , V_187 ) ;
return V_17 ;
}
V_194 [ V_188 ] = V_196 + ( ( T_4 ) V_191 -> V_208 ) ;
break;
case 0x4e0c :
V_193 -> V_288 = V_196 ;
V_193 -> V_207 = true ;
break;
case 0x43a4 :
if ( V_185 -> V_2 -> V_289 != V_185 -> V_232 ) {
if ( V_196 & 0x1 )
V_194 [ V_188 ] = V_196 & ~ 1 ;
}
break;
case 0x4f1c :
V_193 -> V_290 = ! ! ( V_196 & ( 1 << 5 ) ) ;
V_193 -> V_207 = true ;
V_193 -> V_211 = true ;
if ( V_185 -> V_2 -> V_289 != V_185 -> V_232 ) {
if ( V_196 & ( V_291 |
V_292 |
V_293 |
V_294 ) )
goto V_228;
}
break;
case 0x4e04 :
V_193 -> V_295 = ! ! ( V_196 & ( 1 << 2 ) ) ;
V_193 -> V_207 = true ;
break;
case V_296 :
V_17 = F_69 ( V_185 , & V_191 , 0 ) ;
if ( V_17 ) {
F_13 ( L_19 ,
V_188 , V_189 ) ;
F_67 ( V_185 , V_187 ) ;
return V_17 ;
}
V_193 -> V_297 . V_18 = V_191 -> V_18 ;
V_193 -> V_297 . V_206 = V_196 ;
V_193 -> V_298 = true ;
V_194 [ V_188 ] = V_196 + ( ( T_4 ) V_191 -> V_208 ) ;
break;
case V_299 :
V_193 -> V_297 . V_237 = V_196 & 0x3FFE ;
V_193 -> V_298 = true ;
break;
case V_300 :
V_193 -> V_301 = V_196 & 0x1 ;
V_193 -> V_298 = true ;
break;
case 0x4f30 :
case 0x4f34 :
case 0x4f44 :
case 0x4f54 :
if ( V_196 && ( V_185 -> V_2 -> V_289 != V_185 -> V_232 ) )
goto V_228;
break;
case 0x4028 :
if ( V_196 && ( V_185 -> V_2 -> V_289 != V_185 -> V_232 ) )
goto V_228;
if ( V_185 -> V_2 -> V_116 >= V_302 )
break;
goto V_228;
break;
case 0x4be8 :
if ( V_185 -> V_2 -> V_116 == V_303 )
break;
default:
goto V_228;
}
return 0 ;
V_228:
F_37 ( V_304 L_26 ,
V_189 , V_188 , V_196 ) ;
return - V_26 ;
}
static int F_70 ( struct V_184 * V_185 ,
struct V_186 * V_187 )
{
struct V_190 * V_191 ;
struct V_192 * V_193 ;
volatile T_1 * V_194 ;
unsigned V_188 ;
int V_17 ;
V_194 = V_185 -> V_194 . V_9 ;
V_188 = V_187 -> V_188 + 1 ;
V_193 = (struct V_192 * ) V_185 -> V_193 ;
switch( V_187 -> V_305 ) {
case V_306 :
V_17 = F_71 ( V_185 , V_187 , V_188 ) ;
if ( V_17 )
return V_17 ;
break;
case V_307 :
V_17 = F_69 ( V_185 , & V_191 , 0 ) ;
if ( V_17 ) {
F_13 ( L_27 , V_187 -> V_305 ) ;
F_67 ( V_185 , V_187 ) ;
return V_17 ;
}
V_194 [ V_188 + 1 ] = F_65 ( V_185 , V_188 + 1 ) + ( ( T_4 ) V_191 -> V_208 ) ;
V_17 = F_72 ( V_185 , V_187 , V_191 -> V_18 ) ;
if ( V_17 ) {
return V_17 ;
}
break;
case V_308 :
if ( ( ( F_65 ( V_185 , V_188 + 1 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_26 ;
}
V_193 -> V_224 = F_65 ( V_185 , V_188 + 1 ) ;
V_193 -> V_309 = V_187 -> V_310 - 1 ;
V_17 = F_73 ( V_185 -> V_2 , V_193 ) ;
if ( V_17 ) {
return V_17 ;
}
break;
case V_311 :
if ( ( ( F_65 ( V_185 , V_188 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_26 ;
}
V_193 -> V_224 = F_65 ( V_185 , V_188 ) ;
V_193 -> V_309 = V_187 -> V_310 ;
V_17 = F_73 ( V_185 -> V_2 , V_193 ) ;
if ( V_17 ) {
return V_17 ;
}
break;
case V_312 :
V_193 -> V_224 = F_65 ( V_185 , V_188 + 1 ) ;
V_17 = F_73 ( V_185 -> V_2 , V_193 ) ;
if ( V_17 ) {
return V_17 ;
}
break;
case V_313 :
V_193 -> V_224 = F_65 ( V_185 , V_188 ) ;
V_17 = F_73 ( V_185 -> V_2 , V_193 ) ;
if ( V_17 ) {
return V_17 ;
}
break;
case V_314 :
V_193 -> V_224 = F_65 ( V_185 , V_188 + 1 ) ;
V_17 = F_73 ( V_185 -> V_2 , V_193 ) ;
if ( V_17 ) {
return V_17 ;
}
break;
case V_315 :
V_193 -> V_224 = F_65 ( V_185 , V_188 ) ;
V_17 = F_73 ( V_185 -> V_2 , V_193 ) ;
if ( V_17 ) {
return V_17 ;
}
break;
case V_316 :
case V_317 :
if ( V_185 -> V_2 -> V_289 != V_185 -> V_232 )
return - V_26 ;
break;
case V_318 :
if ( V_185 -> V_2 -> V_231 != V_185 -> V_232 )
return - V_26 ;
break;
case V_319 :
break;
default:
F_13 ( L_29 , V_187 -> V_305 ) ;
return - V_26 ;
}
return 0 ;
}
int F_74 ( struct V_184 * V_185 )
{
struct V_186 V_187 ;
struct V_192 * V_193 ;
int V_17 ;
V_193 = F_75 ( sizeof( * V_193 ) , V_320 ) ;
if ( V_193 == NULL )
return - V_321 ;
F_76 ( V_185 -> V_2 , V_193 ) ;
V_185 -> V_193 = V_193 ;
do {
V_17 = F_77 ( V_185 , & V_187 , V_185 -> V_188 ) ;
if ( V_17 ) {
return V_17 ;
}
V_185 -> V_188 += V_187 . V_310 + 2 ;
switch ( V_187 . type ) {
case V_322 :
V_17 = F_78 ( V_185 , & V_187 ,
V_185 -> V_2 -> V_59 . V_60 . V_323 ,
V_185 -> V_2 -> V_59 . V_60 . V_324 ,
& F_64 ) ;
break;
case V_325 :
break;
case V_326 :
V_17 = F_70 ( V_185 , & V_187 ) ;
break;
default:
F_13 ( L_30 , V_187 . type ) ;
return - V_26 ;
}
if ( V_17 ) {
return V_17 ;
}
} while ( V_185 -> V_188 < V_185 -> V_327 [ V_185 -> V_328 ] . V_329 );
return 0 ;
}
void F_79 ( struct V_1 * V_2 )
{
V_2 -> V_59 . V_60 . V_323 = V_330 ;
V_2 -> V_59 . V_60 . V_324 = F_80 ( V_330 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_133 V_134 ;
int V_17 ;
V_17 = F_82 ( V_2 ) ;
if ( V_17 ) {
F_16 ( V_2 -> V_25 , L_31 ) ;
}
F_40 ( V_2 , & V_134 ) ;
if ( V_2 -> V_8 & V_154 ) {
F_35 ( V_331 ,
F_83 ( V_2 -> V_29 . V_30 >> 16 ) |
F_84 ( V_2 -> V_29 . V_31 >> 16 ) ) ;
F_35 ( V_332 , F_6 ( V_2 -> V_29 . V_333 ) ) ;
F_35 ( V_334 ,
F_7 ( V_2 -> V_29 . V_333 ) & 0xff ) ;
} else {
F_35 ( V_331 , 0x0FFFFFFF ) ;
F_35 ( V_332 , 0 ) ;
F_35 ( V_334 , 0 ) ;
}
if ( F_32 ( V_2 ) )
F_18 ( L_32 ) ;
F_35 ( V_335 ,
F_85 ( V_2 -> V_29 . V_38 >> 16 ) |
F_86 ( V_2 -> V_29 . V_336 >> 16 ) ) ;
F_52 ( V_2 , & V_134 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
T_4 V_3 ;
if ( V_337 != - 1 && V_337 )
F_88 ( V_2 , 1 ) ;
V_3 = F_89 ( V_338 ) ;
V_3 |= F_90 ( 1 ) | F_91 ( 1 ) ;
if ( ( V_2 -> V_116 == V_302 ) || ( V_2 -> V_116 == V_339 ) )
V_3 |= F_92 ( 1 ) ;
F_93 ( V_338 , V_3 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_17 ;
F_95 ( V_2 ) ;
F_81 ( V_2 ) ;
F_87 ( V_2 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_8 & V_158 ) {
V_17 = F_15 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
if ( V_2 -> V_116 == V_117 ||
V_2 -> V_116 == V_127 ||
V_2 -> V_116 == V_302 )
F_49 ( V_2 ) ;
if ( V_2 -> V_8 & V_340 ) {
V_17 = F_96 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
V_17 = F_97 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_98 ( V_2 , V_341 ) ;
if ( V_17 ) {
F_16 ( V_2 -> V_25 , L_33 , V_17 ) ;
return V_17 ;
}
if ( ! V_2 -> V_342 . V_343 ) {
V_17 = F_99 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
F_100 ( V_2 ) ;
V_2 -> V_59 . V_60 . V_61 = F_31 ( V_58 ) ;
V_17 = F_101 ( V_2 , 1024 * 1024 ) ;
if ( V_17 ) {
F_16 ( V_2 -> V_25 , L_34 , V_17 ) ;
return V_17 ;
}
V_17 = F_102 ( V_2 ) ;
if ( V_17 ) {
F_16 ( V_2 -> V_25 , L_35 , V_17 ) ;
return V_17 ;
}
return 0 ;
}
int F_103 ( struct V_1 * V_2 )
{
int V_17 ;
if ( V_2 -> V_8 & V_158 )
F_19 ( V_2 ) ;
if ( V_2 -> V_8 & V_340 )
F_104 ( V_2 ) ;
F_87 ( V_2 ) ;
if ( F_105 ( V_2 ) ) {
F_106 ( V_2 -> V_25 , L_36 ,
F_31 ( V_137 ) ,
F_31 ( V_344 ) ) ;
}
F_107 ( V_2 -> V_345 ) ;
F_87 ( V_2 ) ;
F_108 ( V_2 ) ;
V_2 -> V_346 = true ;
V_17 = F_94 ( V_2 ) ;
if ( V_17 ) {
V_2 -> V_346 = false ;
}
return V_17 ;
}
int F_109 ( struct V_1 * V_2 )
{
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
if ( V_2 -> V_8 & V_158 )
F_19 ( V_2 ) ;
if ( V_2 -> V_8 & V_340 )
F_104 ( V_2 ) ;
return 0 ;
}
void F_114 ( struct V_1 * V_2 )
{
F_115 ( V_2 ) ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
if ( V_2 -> V_8 & V_158 )
F_21 ( V_2 ) ;
if ( V_2 -> V_8 & V_340 )
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 -> V_347 ) ;
V_2 -> V_347 = NULL ;
}
int F_127 ( struct V_1 * V_2 )
{
int V_17 ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
F_108 ( V_2 ) ;
F_130 ( V_2 ) ;
if ( ! F_131 ( V_2 ) ) {
if ( F_132 ( V_2 ) )
return - V_26 ;
}
if ( V_2 -> V_348 ) {
F_16 ( V_2 -> V_25 , L_37 ) ;
return - V_26 ;
} else {
V_17 = F_133 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
if ( F_105 ( V_2 ) ) {
F_106 ( V_2 -> V_25 ,
L_36 ,
F_31 ( V_137 ) ,
F_31 ( V_344 ) ) ;
}
if ( F_134 ( V_2 ) == false )
return - V_26 ;
F_30 ( V_2 ) ;
F_135 ( V_2 -> V_345 ) ;
if ( V_2 -> V_8 & V_154 ) {
V_17 = F_136 ( V_2 ) ;
if ( V_17 ) {
F_137 ( V_2 ) ;
}
}
F_53 ( V_2 ) ;
V_17 = F_138 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_139 ( V_2 ) ;
if ( V_17 )
return V_17 ;
if ( V_2 -> V_8 & V_158 ) {
V_17 = F_9 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
if ( V_2 -> V_8 & V_340 ) {
V_17 = F_140 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
F_79 ( V_2 ) ;
F_141 ( V_2 ) ;
V_2 -> V_346 = true ;
V_17 = F_94 ( V_2 ) ;
if ( V_17 ) {
F_16 ( V_2 -> V_25 , L_38 ) ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_122 ( V_2 ) ;
if ( V_2 -> V_8 & V_158 )
F_21 ( V_2 ) ;
if ( V_2 -> V_8 & V_340 )
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
V_2 -> V_346 = false ;
}
return 0 ;
}
