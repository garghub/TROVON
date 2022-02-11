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
void T_3 * V_8 = ( void * ) V_2 -> V_9 . V_10 . V_11 . V_8 ;
if ( V_4 < 0 || V_4 > V_2 -> V_9 . V_12 ) {
return - V_13 ;
}
V_7 = ( F_6 ( V_7 ) >> 8 ) |
( ( F_7 ( V_7 ) & 0xff ) << 24 ) |
V_14 | V_15 ;
F_8 ( V_7 , ( ( void T_3 * ) V_8 ) + ( V_4 * 4 ) ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_16 ;
if ( V_2 -> V_9 . V_10 . V_11 . V_17 ) {
F_10 ( 1 , L_1 ) ;
return 0 ;
}
V_16 = F_11 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_12 ( V_2 ) ;
if ( V_16 )
F_13 ( L_2 ) ;
V_2 -> V_9 . V_18 = V_2 -> V_9 . V_12 * 4 ;
V_2 -> V_19 -> V_20 = & F_1 ;
V_2 -> V_19 -> V_21 = & F_5 ;
return F_14 ( V_2 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
T_1 V_22 ;
T_1 V_3 ;
int V_16 ;
if ( V_2 -> V_9 . V_10 . V_11 . V_17 == NULL ) {
F_16 ( V_2 -> V_23 , L_3 ) ;
return - V_13 ;
}
V_16 = F_17 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_18 ( V_2 ) ;
V_3 = V_24 ;
F_3 ( V_5 , V_3 ) ;
F_3 ( V_25 , V_2 -> V_26 . V_27 ) ;
V_3 = V_2 -> V_26 . V_28 & ~ V_29 ;
F_3 ( V_30 , V_3 ) ;
F_3 ( V_31 , 0 ) ;
F_3 ( V_32 , 0 ) ;
V_22 = V_2 -> V_9 . V_22 ;
F_3 ( V_33 , V_22 ) ;
F_3 ( V_34 , V_2 -> V_26 . V_35 ) ;
F_3 ( V_36 , 0 ) ;
F_3 ( V_37 , 0 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_38 ;
V_3 |= V_24 ;
F_3 ( V_5 , V_3 ) ;
F_1 ( V_2 ) ;
F_19 ( L_4 ,
( unsigned ) ( V_2 -> V_26 . V_39 >> 20 ) , V_22 ) ;
V_2 -> V_9 . V_40 = true ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
T_4 V_3 ;
int V_16 ;
F_3 ( V_25 , 0 ) ;
F_3 ( V_30 , 0 ) ;
F_3 ( V_31 , 0 ) ;
F_3 ( V_32 , 0 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_24 ;
F_3 ( V_5 , V_3 & ~ V_38 ) ;
if ( V_2 -> V_9 . V_10 . V_11 . V_17 ) {
V_16 = F_21 ( V_2 -> V_9 . V_10 . V_11 . V_17 , false ) ;
if ( F_22 ( V_16 == 0 ) ) {
F_23 ( V_2 -> V_9 . V_10 . V_11 . V_17 ) ;
F_24 ( V_2 -> V_9 . V_10 . V_11 . V_17 ) ;
F_25 ( V_2 -> V_9 . V_10 . V_11 . V_17 ) ;
}
}
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_20 ( V_2 ) ;
F_28 ( V_2 ) ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
F_30 ( V_2 , F_31 ( V_43 , 0 ) ) ;
F_30 ( V_2 , 0 ) ;
F_30 ( V_2 , F_31 ( V_44 , 0 ) ) ;
F_30 ( V_2 , 0 ) ;
F_30 ( V_2 , F_31 ( V_45 , 0 ) ) ;
F_30 ( V_2 , V_46 ) ;
F_30 ( V_2 , F_31 ( V_47 , 0 ) ) ;
F_30 ( V_2 , V_48 ) ;
F_30 ( V_2 , F_31 ( V_49 , 0 ) ) ;
F_30 ( V_2 , ( V_50 |
V_51 |
V_52 ) ) ;
F_30 ( V_2 , F_31 ( V_53 , 0 ) ) ;
F_30 ( V_2 , V_2 -> V_54 . V_55 . V_56 |
V_57 ) ;
F_30 ( V_2 , F_31 ( V_53 , 0 ) ) ;
F_30 ( V_2 , V_2 -> V_54 . V_55 . V_56 ) ;
F_30 ( V_2 , F_31 ( V_2 -> V_58 . V_59 , 0 ) ) ;
F_30 ( V_2 , V_42 -> V_60 ) ;
F_30 ( V_2 , F_31 ( V_61 , 0 ) ) ;
F_30 ( V_2 , V_62 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
unsigned V_63 ;
int V_16 ;
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
V_16 = F_33 ( V_2 , 64 ) ;
if ( V_16 ) {
return;
}
F_30 ( V_2 , F_31 ( V_71 , 0 ) ) ;
F_30 ( V_2 ,
V_72 |
V_73 |
V_74 |
V_75 ) ;
F_30 ( V_2 , F_31 ( V_76 , 0 ) ) ;
F_30 ( V_2 , V_63 ) ;
F_30 ( V_2 , F_31 ( V_49 , 0 ) ) ;
F_30 ( V_2 ,
V_51 |
V_50 ) ;
F_30 ( V_2 , F_31 ( V_77 , 0 ) ) ;
F_30 ( V_2 , V_78 ) ;
F_30 ( V_2 , F_31 ( V_79 , 0 ) ) ;
F_30 ( V_2 , 0 ) ;
F_30 ( V_2 , F_31 ( V_80 , 0 ) ) ;
F_30 ( V_2 , 0 ) ;
F_30 ( V_2 , F_31 ( V_45 , 0 ) ) ;
F_30 ( V_2 , V_46 | V_81 ) ;
F_30 ( V_2 , F_31 ( V_47 , 0 ) ) ;
F_30 ( V_2 , V_48 | V_82 ) ;
F_30 ( V_2 , F_31 ( V_49 , 0 ) ) ;
F_30 ( V_2 ,
V_51 |
V_50 ) ;
F_30 ( V_2 , F_31 ( V_83 , 0 ) ) ;
F_30 ( V_2 , 0 ) ;
F_30 ( V_2 , F_31 ( V_45 , 0 ) ) ;
F_30 ( V_2 , V_46 | V_81 ) ;
F_30 ( V_2 , F_31 ( V_47 , 0 ) ) ;
F_30 ( V_2 , V_48 | V_82 ) ;
F_30 ( V_2 , F_31 ( V_84 , 0 ) ) ;
F_30 ( V_2 ,
( ( 6 << V_85 ) |
( 6 << V_86 ) |
( 6 << V_87 ) |
( 6 << V_88 ) |
( 6 << V_89 ) |
( 6 << V_90 ) |
( 6 << V_91 ) |
( 6 << V_92 ) ) ) ;
F_30 ( V_2 , F_31 ( V_93 , 0 ) ) ;
F_30 ( V_2 ,
( ( 6 << V_94 ) |
( 6 << V_95 ) |
( 6 << V_96 ) |
( 6 << V_97 ) |
( 6 << V_98 ) |
( 6 << V_99 ) |
( 6 << V_100 ) ) ) ;
F_30 ( V_2 , F_31 ( V_101 , 0 ) ) ;
F_30 ( V_2 , V_102 | V_103 ) ;
F_30 ( V_2 , F_31 ( V_104 , 0 ) ) ;
F_30 ( V_2 ,
V_105 | V_106 ) ;
F_30 ( V_2 , F_31 ( V_107 , 0 ) ) ;
F_30 ( V_2 ,
V_108 |
V_109 ) ;
F_34 ( V_2 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
V_2 -> V_110 = 0 ;
if ( V_2 -> V_111 == V_112 &&
( F_36 ( V_113 ) & V_114 ) == V_115 ) {
V_2 -> V_110 |= V_116 ;
}
}
int F_37 ( struct V_1 * V_2 )
{
unsigned V_4 ;
T_1 V_3 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_117 ; V_4 ++ ) {
V_3 = F_36 ( V_118 ) ;
if ( V_3 & V_119 ) {
return 0 ;
}
F_38 ( 1 ) ;
}
return - 1 ;
}
void F_39 ( struct V_1 * V_2 )
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
F_40 ( V_76 , V_63 ) ;
if ( F_41 ( V_2 ) ) {
F_42 ( V_124 L_5
L_6 ) ;
}
V_3 = F_36 ( V_77 ) ;
F_40 ( V_77 , V_3 | V_78 ) ;
F_40 ( V_125 ,
V_126 |
V_127 ) ;
if ( F_41 ( V_2 ) ) {
F_42 ( V_124 L_5
L_6 ) ;
}
if ( F_37 ( V_2 ) ) {
F_42 ( V_124 L_7
L_6 ) ;
}
F_19 ( L_8 ,
V_2 -> V_66 , V_2 -> V_123 ) ;
}
bool F_43 ( struct V_1 * V_2 )
{
T_4 V_128 ;
int V_16 ;
V_128 = F_36 ( V_129 ) ;
if ( ! F_44 ( V_128 ) ) {
F_45 ( & V_2 -> V_54 . V_55 . V_130 , & V_2 -> V_131 ) ;
return false ;
}
V_16 = F_33 ( V_2 , 2 ) ;
if ( ! V_16 ) {
F_30 ( V_2 , 0x80000000 ) ;
F_30 ( V_2 , 0x80000000 ) ;
F_34 ( V_2 ) ;
}
V_2 -> V_131 . V_132 = F_36 ( V_133 ) ;
return F_46 ( V_2 , & V_2 -> V_54 . V_55 . V_130 , & V_2 -> V_131 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_134 V_135 ;
T_4 V_136 , V_3 ;
int V_137 = 0 ;
V_136 = F_36 ( V_129 ) ;
if ( ! F_44 ( V_136 ) ) {
return 0 ;
}
F_48 ( V_2 , & V_135 ) ;
V_136 = F_36 ( V_129 ) ;
F_49 ( V_2 -> V_23 , L_9 , V_138 , __LINE__ , V_136 ) ;
F_40 ( V_139 , 0 ) ;
V_3 = F_36 ( V_140 ) ;
F_40 ( V_140 , V_3 | V_141 ) ;
F_40 ( V_142 , 0 ) ;
F_40 ( V_143 , 0 ) ;
F_40 ( V_140 , V_3 ) ;
F_50 ( V_2 -> V_120 ) ;
F_51 ( V_2 ) ;
F_40 ( V_144 , F_52 ( 1 ) |
F_53 ( 1 ) ) ;
F_36 ( V_144 ) ;
F_54 ( 500 ) ;
F_40 ( V_144 , 0 ) ;
F_54 ( 1 ) ;
V_136 = F_36 ( V_129 ) ;
F_49 ( V_2 -> V_23 , L_9 , V_138 , __LINE__ , V_136 ) ;
F_40 ( V_144 , F_55 ( 1 ) ) ;
F_36 ( V_144 ) ;
F_54 ( 500 ) ;
F_40 ( V_144 , 0 ) ;
F_54 ( 1 ) ;
V_136 = F_36 ( V_129 ) ;
F_49 ( V_2 -> V_23 , L_9 , V_138 , __LINE__ , V_136 ) ;
F_56 ( V_2 -> V_120 ) ;
F_57 ( V_2 ) ;
if ( F_58 ( V_136 ) || F_59 ( V_136 ) ) {
F_16 ( V_2 -> V_23 , L_10 ) ;
V_2 -> V_145 = true ;
V_137 = - 1 ;
} else
F_49 ( V_2 -> V_23 , L_11 ) ;
F_60 ( V_2 , & V_135 ) ;
return V_137 ;
}
void F_61 ( struct V_1 * V_2 )
{
T_5 V_146 ;
T_4 V_3 ;
V_2 -> V_26 . V_147 = true ;
V_3 = F_36 ( V_148 ) ;
V_3 &= V_149 ;
switch ( V_3 ) {
case 0 : V_2 -> V_26 . V_150 = 64 ; break;
case 1 : V_2 -> V_26 . V_150 = 128 ; break;
case 2 : V_2 -> V_26 . V_150 = 256 ; break;
default: V_2 -> V_26 . V_150 = 128 ; break;
}
F_62 ( V_2 ) ;
V_146 = V_2 -> V_26 . V_151 ;
if ( V_2 -> V_152 & V_153 )
V_146 = ( F_36 ( V_154 ) & 0xffff ) << 16 ;
F_63 ( V_2 , & V_2 -> V_26 , V_146 ) ;
V_2 -> V_26 . V_155 = 0 ;
if ( ! ( V_2 -> V_152 & V_156 ) )
F_64 ( V_2 , & V_2 -> V_26 ) ;
F_65 ( V_2 ) ;
}
void F_66 ( struct V_1 * V_2 , int V_157 )
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
int F_67 ( struct V_1 * V_2 )
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
static int F_68 ( struct V_175 * V_176 , void * V_177 )
{
struct V_178 * V_179 = (struct V_178 * ) V_176 -> V_180 ;
struct V_181 * V_23 = V_179 -> V_182 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_183 ;
T_1 V_3 ;
V_3 = F_2 ( V_5 ) ;
F_69 ( V_176 , L_12 , V_3 ) ;
V_3 = F_2 ( V_33 ) ;
F_69 ( V_176 , L_13 , V_3 ) ;
V_3 = F_2 ( V_25 ) ;
F_69 ( V_176 , L_14 , V_3 ) ;
V_3 = F_2 ( V_31 ) ;
F_69 ( V_176 , L_15 , V_3 ) ;
V_3 = F_2 ( V_30 ) ;
F_69 ( V_176 , L_16 , V_3 ) ;
V_3 = F_2 ( V_32 ) ;
F_69 ( V_176 , L_17 , V_3 ) ;
V_3 = F_2 ( V_37 ) ;
F_69 ( V_176 , L_18 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
#if F_70 ( V_184 )
return F_71 ( V_2 , V_185 , 1 ) ;
#else
return 0 ;
#endif
}
static int F_72 ( struct V_186 * V_187 ,
struct V_188 * V_189 ,
unsigned V_190 , unsigned V_191 )
{
struct V_192 * V_193 ;
struct V_194 * V_195 ;
volatile T_1 * V_196 ;
T_1 V_3 , V_197 = 0 ;
unsigned V_4 ;
int V_16 ;
T_4 V_198 ;
V_196 = V_187 -> V_196 -> V_8 ;
V_195 = (struct V_194 * ) V_187 -> V_195 ;
V_198 = F_73 ( V_187 , V_190 ) ;
switch( V_191 ) {
case V_199 :
case V_200 :
V_16 = F_74 ( V_187 ) ;
if ( V_16 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_75 ( V_187 , V_189 ) ;
return V_16 ;
}
break;
case V_201 :
case V_202 :
V_16 = F_76 ( V_187 , V_189 , V_190 , V_191 ) ;
if ( V_16 )
return V_16 ;
break;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
V_4 = ( V_191 - V_203 ) >> 2 ;
V_16 = F_77 ( V_187 , & V_193 ) ;
if ( V_16 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_75 ( V_187 , V_189 ) ;
return V_16 ;
}
V_195 -> V_207 [ V_4 ] . V_17 = V_193 -> V_17 ;
V_195 -> V_207 [ V_4 ] . V_208 = V_198 ;
V_195 -> V_209 = true ;
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
break;
case V_212 :
V_16 = F_77 ( V_187 , & V_193 ) ;
if ( V_16 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_75 ( V_187 , V_189 ) ;
return V_16 ;
}
V_195 -> V_213 . V_17 = V_193 -> V_17 ;
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
V_16 = F_77 ( V_187 , & V_193 ) ;
if ( V_16 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_75 ( V_187 , V_189 ) ;
return V_16 ;
}
if ( V_193 -> V_210 . V_216 & V_217 )
V_197 |= V_218 ;
if ( V_193 -> V_210 . V_216 & V_219 )
V_197 |= V_220 ;
else if ( V_193 -> V_210 . V_216 & V_221 )
V_197 |= V_222 ;
V_3 = V_198 + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
V_3 |= V_197 ;
V_196 [ V_190 ] = V_3 ;
V_195 -> V_223 [ V_4 ] . V_17 = V_193 -> V_17 ;
V_195 -> V_224 = true ;
break;
case 0x2084 :
V_195 -> V_225 = V_198 ;
break;
case 0x20B4 :
V_195 -> V_226 = V_198 & 0x7F ;
break;
case 0x2134 :
V_195 -> V_227 = V_198 & 0x00FFFFFFUL ;
break;
case 0x2088 :
if ( V_187 -> V_2 -> V_111 < V_228 )
goto V_229;
V_195 -> V_230 = V_198 & 0xFFFFFF ;
break;
case 0x43E4 :
V_195 -> V_231 = ( ( V_198 >> 13 ) & 0x1FFF ) + 1 ;
if ( V_187 -> V_2 -> V_111 < V_228 ) {
V_195 -> V_231 -= 1440 ;
}
V_195 -> V_209 = true ;
V_195 -> V_214 = true ;
break;
case 0x4E00 :
if ( ( V_198 & ( 1 << 10 ) ) &&
V_187 -> V_2 -> V_232 != V_187 -> V_233 ) {
F_13 ( L_20 ) ;
return - V_13 ;
}
V_195 -> V_234 = ( ( V_198 >> 5 ) & 0x3 ) + 1 ;
V_195 -> V_209 = true ;
break;
case 0x4E38 :
case 0x4E3C :
case 0x4E40 :
case 0x4E44 :
V_16 = F_77 ( V_187 , & V_193 ) ;
if ( V_16 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_75 ( V_187 , V_189 ) ;
return V_16 ;
}
if ( V_193 -> V_210 . V_216 & V_217 )
V_197 |= V_235 ;
if ( V_193 -> V_210 . V_216 & V_219 )
V_197 |= V_236 ;
else if ( V_193 -> V_210 . V_216 & V_221 )
V_197 |= V_237 ;
V_3 = V_198 & ~ ( 0x7 << 16 ) ;
V_3 |= V_197 ;
V_196 [ V_190 ] = V_3 ;
V_4 = ( V_191 - 0x4E38 ) >> 2 ;
V_195 -> V_207 [ V_4 ] . V_238 = V_198 & 0x3FFE ;
switch ( ( ( V_198 >> 21 ) & 0xF ) ) {
case 9 :
case 11 :
case 12 :
V_195 -> V_207 [ V_4 ] . V_239 = 1 ;
break;
case 3 :
case 4 :
case 13 :
case 15 :
V_195 -> V_207 [ V_4 ] . V_239 = 2 ;
break;
case 5 :
if ( V_187 -> V_2 -> V_111 < V_228 ) {
F_13 ( L_21 ,
( ( V_198 >> 21 ) & 0xF ) ) ;
return - V_13 ;
}
case 6 :
V_195 -> V_207 [ V_4 ] . V_239 = 4 ;
break;
case 10 :
V_195 -> V_207 [ V_4 ] . V_239 = 8 ;
break;
case 7 :
V_195 -> V_207 [ V_4 ] . V_239 = 16 ;
break;
default:
F_13 ( L_22 ,
( ( V_198 >> 21 ) & 0xF ) ) ;
return - V_13 ;
}
V_195 -> V_209 = true ;
break;
case 0x4F00 :
if ( V_198 & 2 ) {
V_195 -> V_240 = true ;
} else {
V_195 -> V_240 = false ;
}
V_195 -> V_214 = true ;
break;
case 0x4F10 :
switch ( ( V_198 & 0xF ) ) {
case 0 :
case 1 :
V_195 -> V_213 . V_239 = 2 ;
break;
case 2 :
V_195 -> V_213 . V_239 = 4 ;
break;
default:
F_13 ( L_23 ,
( V_198 & 0xF ) ) ;
return - V_13 ;
}
V_195 -> V_214 = true ;
break;
case 0x4F24 :
V_16 = F_77 ( V_187 , & V_193 ) ;
if ( V_16 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_75 ( V_187 , V_189 ) ;
return V_16 ;
}
if ( V_193 -> V_210 . V_216 & V_217 )
V_197 |= V_241 ;
if ( V_193 -> V_210 . V_216 & V_219 )
V_197 |= V_242 ;
else if ( V_193 -> V_210 . V_216 & V_221 )
V_197 |= V_243 ;
V_3 = V_198 & ~ ( 0x7 << 16 ) ;
V_3 |= V_197 ;
V_196 [ V_190 ] = V_3 ;
V_195 -> V_213 . V_238 = V_198 & 0x3FFC ;
V_195 -> V_214 = true ;
break;
case 0x4104 :
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
bool V_244 ;
V_244 = ! ! ( V_198 & ( 1 << V_4 ) ) ;
V_195 -> V_223 [ V_4 ] . V_244 = V_244 ;
}
V_195 -> V_224 = true ;
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
V_195 -> V_223 [ V_4 ] . V_245 = V_3 ;
switch ( ( V_198 & 0x1F ) ) {
case V_246 :
case V_247 :
case V_248 :
V_195 -> V_223 [ V_4 ] . V_239 = 1 ;
V_195 -> V_223 [ V_4 ] . V_249 = V_250 ;
break;
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
V_195 -> V_223 [ V_4 ] . V_239 = 2 ;
V_195 -> V_223 [ V_4 ] . V_249 = V_250 ;
break;
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case 0x17 :
case V_267 :
case 0x1e :
V_195 -> V_223 [ V_4 ] . V_239 = 4 ;
V_195 -> V_223 [ V_4 ] . V_249 = V_250 ;
break;
case V_268 :
case V_269 :
case V_270 :
V_195 -> V_223 [ V_4 ] . V_239 = 8 ;
V_195 -> V_223 [ V_4 ] . V_249 = V_250 ;
break;
case V_271 :
V_195 -> V_223 [ V_4 ] . V_239 = 16 ;
V_195 -> V_223 [ V_4 ] . V_249 = V_250 ;
break;
case V_272 :
V_195 -> V_223 [ V_4 ] . V_239 = 1 ;
V_195 -> V_223 [ V_4 ] . V_249 = V_273 ;
break;
case V_274 :
if ( V_187 -> V_2 -> V_111 < V_275 ) {
F_13 ( L_24 ,
( V_198 & 0x1F ) ) ;
return - V_13 ;
}
case V_276 :
case V_277 :
V_195 -> V_223 [ V_4 ] . V_239 = 1 ;
V_195 -> V_223 [ V_4 ] . V_249 = V_278 ;
break;
default:
F_13 ( L_24 ,
( V_198 & 0x1F ) ) ;
return - V_13 ;
}
V_195 -> V_224 = true ;
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
V_195 -> V_223 [ V_4 ] . V_279 = false ;
}
V_3 = ( V_198 >> 3 ) & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_195 -> V_223 [ V_4 ] . V_280 = false ;
}
V_195 -> V_224 = true ;
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
V_195 -> V_223 [ V_4 ] . V_238 = V_3 + 1 ;
if ( V_187 -> V_2 -> V_111 >= V_228 ) {
V_3 = ( ( V_198 >> 15 ) & 1 ) << 11 ;
V_195 -> V_223 [ V_4 ] . V_281 = V_3 ;
V_3 = ( ( V_198 >> 16 ) & 1 ) << 11 ;
V_195 -> V_223 [ V_4 ] . V_282 = V_3 ;
if ( V_198 & ( 1 << 14 ) ) {
V_195 -> V_223 [ V_4 ] . V_249 =
V_273 ;
}
} else if ( V_198 & ( 1 << 14 ) ) {
F_13 ( L_25 ) ;
return - V_13 ;
}
V_195 -> V_224 = true ;
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
V_195 -> V_223 [ V_4 ] . V_283 = V_3 + 1 ;
V_3 = ( V_198 >> 11 ) & 0x7FF ;
V_195 -> V_223 [ V_4 ] . V_284 = V_3 + 1 ;
V_3 = ( V_198 >> 26 ) & 0xF ;
V_195 -> V_223 [ V_4 ] . V_285 = V_3 ;
V_3 = V_198 & ( 1 << 31 ) ;
V_195 -> V_223 [ V_4 ] . V_286 = ! ! V_3 ;
V_3 = ( V_198 >> 22 ) & 0xF ;
V_195 -> V_223 [ V_4 ] . V_287 = V_3 ;
V_195 -> V_224 = true ;
break;
case V_288 :
V_16 = F_77 ( V_187 , & V_193 ) ;
if ( V_16 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_75 ( V_187 , V_189 ) ;
return V_16 ;
}
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
break;
case 0x4e0c :
V_195 -> V_289 = V_198 ;
V_195 -> V_209 = true ;
break;
case 0x43a4 :
if ( V_187 -> V_2 -> V_290 != V_187 -> V_233 ) {
if ( V_198 & 0x1 )
V_196 [ V_190 ] = V_198 & ~ 1 ;
}
break;
case 0x4f1c :
V_195 -> V_291 = ! ! ( V_198 & ( 1 << 5 ) ) ;
V_195 -> V_209 = true ;
V_195 -> V_214 = true ;
if ( V_187 -> V_2 -> V_290 != V_187 -> V_233 ) {
if ( V_198 & ( V_292 |
V_293 |
V_294 |
V_295 ) )
goto V_229;
}
break;
case 0x4e04 :
V_195 -> V_296 = ! ! ( V_198 & ( 1 << 2 ) ) ;
V_195 -> V_209 = true ;
break;
case V_297 :
V_16 = F_77 ( V_187 , & V_193 ) ;
if ( V_16 ) {
F_13 ( L_19 ,
V_190 , V_191 ) ;
F_75 ( V_187 , V_189 ) ;
return V_16 ;
}
V_195 -> V_298 . V_17 = V_193 -> V_17 ;
V_195 -> V_298 . V_208 = V_198 ;
V_195 -> V_299 = true ;
V_196 [ V_190 ] = V_198 + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
break;
case V_300 :
V_195 -> V_298 . V_238 = V_198 & 0x3FFE ;
V_195 -> V_299 = true ;
break;
case V_301 :
V_195 -> V_302 = V_198 & 0x1 ;
V_195 -> V_299 = true ;
break;
case 0x4f30 :
case 0x4f34 :
case 0x4f44 :
case 0x4f54 :
if ( V_198 && ( V_187 -> V_2 -> V_290 != V_187 -> V_233 ) )
goto V_229;
break;
case 0x4028 :
if ( V_198 && ( V_187 -> V_2 -> V_290 != V_187 -> V_233 ) )
goto V_229;
if ( V_187 -> V_2 -> V_111 >= V_303 )
break;
goto V_229;
break;
case 0x4be8 :
if ( V_187 -> V_2 -> V_111 == V_304 )
break;
default:
goto V_229;
}
return 0 ;
V_229:
F_42 ( V_305 L_26 ,
V_191 , V_190 , V_198 ) ;
return - V_13 ;
}
static int F_78 ( struct V_186 * V_187 ,
struct V_188 * V_189 )
{
struct V_192 * V_193 ;
struct V_194 * V_195 ;
volatile T_1 * V_196 ;
unsigned V_190 ;
int V_16 ;
V_196 = V_187 -> V_196 -> V_8 ;
V_190 = V_189 -> V_190 + 1 ;
V_195 = (struct V_194 * ) V_187 -> V_195 ;
switch( V_189 -> V_306 ) {
case V_307 :
V_16 = F_79 ( V_187 , V_189 , V_190 ) ;
if ( V_16 )
return V_16 ;
break;
case V_308 :
V_16 = F_77 ( V_187 , & V_193 ) ;
if ( V_16 ) {
F_13 ( L_27 , V_189 -> V_306 ) ;
F_75 ( V_187 , V_189 ) ;
return V_16 ;
}
V_196 [ V_190 + 1 ] = F_73 ( V_187 , V_190 + 1 ) + ( ( T_4 ) V_193 -> V_210 . V_211 ) ;
V_16 = F_80 ( V_187 , V_189 , V_193 -> V_17 ) ;
if ( V_16 ) {
return V_16 ;
}
break;
case V_309 :
if ( ( ( F_73 ( V_187 , V_190 + 1 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_13 ;
}
V_195 -> V_225 = F_73 ( V_187 , V_190 + 1 ) ;
V_195 -> V_310 = V_189 -> V_311 - 1 ;
V_16 = F_81 ( V_187 -> V_2 , V_195 ) ;
if ( V_16 ) {
return V_16 ;
}
break;
case V_312 :
if ( ( ( F_73 ( V_187 , V_190 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_13 ;
}
V_195 -> V_225 = F_73 ( V_187 , V_190 ) ;
V_195 -> V_310 = V_189 -> V_311 ;
V_16 = F_81 ( V_187 -> V_2 , V_195 ) ;
if ( V_16 ) {
return V_16 ;
}
break;
case V_313 :
V_195 -> V_225 = F_73 ( V_187 , V_190 + 1 ) ;
V_16 = F_81 ( V_187 -> V_2 , V_195 ) ;
if ( V_16 ) {
return V_16 ;
}
break;
case V_314 :
V_195 -> V_225 = F_73 ( V_187 , V_190 ) ;
V_16 = F_81 ( V_187 -> V_2 , V_195 ) ;
if ( V_16 ) {
return V_16 ;
}
break;
case V_315 :
V_195 -> V_225 = F_73 ( V_187 , V_190 + 1 ) ;
V_16 = F_81 ( V_187 -> V_2 , V_195 ) ;
if ( V_16 ) {
return V_16 ;
}
break;
case V_316 :
V_195 -> V_225 = F_73 ( V_187 , V_190 ) ;
V_16 = F_81 ( V_187 -> V_2 , V_195 ) ;
if ( V_16 ) {
return V_16 ;
}
break;
case V_317 :
case V_318 :
if ( V_187 -> V_2 -> V_290 != V_187 -> V_233 )
return - V_13 ;
break;
case V_319 :
if ( V_187 -> V_2 -> V_232 != V_187 -> V_233 )
return - V_13 ;
break;
case V_320 :
break;
default:
F_13 ( L_29 , V_189 -> V_306 ) ;
return - V_13 ;
}
return 0 ;
}
int F_82 ( struct V_186 * V_187 )
{
struct V_188 V_189 ;
struct V_194 * V_195 ;
int V_16 ;
V_195 = F_83 ( sizeof( * V_195 ) , V_321 ) ;
if ( V_195 == NULL )
return - V_322 ;
F_84 ( V_187 -> V_2 , V_195 ) ;
V_187 -> V_195 = V_195 ;
do {
V_16 = F_85 ( V_187 , & V_189 , V_187 -> V_190 ) ;
if ( V_16 ) {
return V_16 ;
}
V_187 -> V_190 += V_189 . V_311 + 2 ;
switch ( V_189 . type ) {
case V_323 :
V_16 = F_86 ( V_187 , & V_189 ,
V_187 -> V_2 -> V_54 . V_55 . V_324 ,
V_187 -> V_2 -> V_54 . V_55 . V_325 ,
& F_72 ) ;
break;
case V_326 :
break;
case V_327 :
V_16 = F_78 ( V_187 , & V_189 ) ;
break;
default:
F_13 ( L_30 , V_189 . type ) ;
return - V_13 ;
}
if ( V_16 ) {
return V_16 ;
}
} while ( V_187 -> V_190 < V_187 -> V_328 [ V_187 -> V_329 ] . V_330 );
return 0 ;
}
void F_87 ( struct V_1 * V_2 )
{
V_2 -> V_54 . V_55 . V_324 = V_331 ;
V_2 -> V_54 . V_55 . V_325 = F_88 ( V_331 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_134 V_135 ;
int V_16 ;
V_16 = F_90 ( V_2 ) ;
if ( V_16 ) {
F_16 ( V_2 -> V_23 , L_31 ) ;
}
F_48 ( V_2 , & V_135 ) ;
if ( V_2 -> V_152 & V_156 ) {
F_40 ( V_332 ,
F_91 ( V_2 -> V_26 . V_27 >> 16 ) |
F_92 ( V_2 -> V_26 . V_28 >> 16 ) ) ;
F_40 ( V_333 , F_6 ( V_2 -> V_26 . V_334 ) ) ;
F_40 ( V_335 ,
F_7 ( V_2 -> V_26 . V_334 ) & 0xff ) ;
} else {
F_40 ( V_332 , 0x0FFFFFFF ) ;
F_40 ( V_333 , 0 ) ;
F_40 ( V_335 , 0 ) ;
}
if ( F_37 ( V_2 ) )
F_19 ( L_32 ) ;
F_40 ( V_336 ,
F_93 ( V_2 -> V_26 . V_35 >> 16 ) |
F_94 ( V_2 -> V_26 . V_337 >> 16 ) ) ;
F_60 ( V_2 , & V_135 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
T_4 V_3 ;
if ( V_338 != - 1 && V_338 )
F_96 ( V_2 , 1 ) ;
V_3 = F_97 ( V_339 ) ;
V_3 |= F_98 ( 1 ) | F_99 ( 1 ) ;
if ( ( V_2 -> V_111 == V_303 ) || ( V_2 -> V_111 == V_340 ) )
V_3 |= F_100 ( 1 ) ;
F_101 ( V_339 , V_3 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_16 ;
F_103 ( V_2 ) ;
F_89 ( V_2 ) ;
F_95 ( V_2 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_152 & V_160 ) {
V_16 = F_15 ( V_2 ) ;
if ( V_16 )
return V_16 ;
}
if ( V_2 -> V_111 == V_112 ||
V_2 -> V_111 == V_122 ||
V_2 -> V_111 == V_303 )
F_57 ( V_2 ) ;
if ( V_2 -> V_152 & V_341 ) {
V_16 = F_104 ( V_2 ) ;
if ( V_16 )
return V_16 ;
}
V_16 = F_105 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_106 ( V_2 ) ;
V_2 -> V_54 . V_55 . V_56 = F_36 ( V_53 ) ;
V_16 = F_107 ( V_2 , 1024 * 1024 ) ;
if ( V_16 ) {
F_16 ( V_2 -> V_23 , L_33 , V_16 ) ;
return V_16 ;
}
V_16 = F_108 ( V_2 ) ;
if ( V_16 ) {
F_16 ( V_2 -> V_23 , L_34 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
int F_109 ( struct V_1 * V_2 )
{
if ( V_2 -> V_152 & V_160 )
F_20 ( V_2 ) ;
if ( V_2 -> V_152 & V_341 )
F_110 ( V_2 ) ;
F_95 ( V_2 ) ;
if ( F_111 ( V_2 ) ) {
F_112 ( V_2 -> V_23 , L_35 ,
F_36 ( V_129 ) ,
F_36 ( V_342 ) ) ;
}
F_113 ( V_2 -> V_343 ) ;
F_95 ( V_2 ) ;
F_114 ( V_2 ) ;
return F_102 ( V_2 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
if ( V_2 -> V_152 & V_160 )
F_20 ( V_2 ) ;
if ( V_2 -> V_152 & V_341 )
F_110 ( V_2 ) ;
return 0 ;
}
void F_119 ( struct V_1 * V_2 )
{
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
if ( V_2 -> V_152 & V_160 )
F_26 ( V_2 ) ;
if ( V_2 -> V_152 & V_341 )
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 -> V_344 ) ;
V_2 -> V_344 = NULL ;
}
int F_131 ( struct V_1 * V_2 )
{
int V_16 ;
F_132 ( V_2 ) ;
F_133 ( V_2 ) ;
F_114 ( V_2 ) ;
F_134 ( V_2 ) ;
if ( ! F_135 ( V_2 ) ) {
if ( F_136 ( V_2 ) )
return - V_13 ;
}
if ( V_2 -> V_345 ) {
F_16 ( V_2 -> V_23 , L_36 ) ;
return - V_13 ;
} else {
V_16 = F_137 ( V_2 ) ;
if ( V_16 )
return V_16 ;
}
if ( F_111 ( V_2 ) ) {
F_112 ( V_2 -> V_23 ,
L_35 ,
F_36 ( V_129 ) ,
F_36 ( V_342 ) ) ;
}
if ( F_138 ( V_2 ) == false )
return - V_13 ;
F_35 ( V_2 ) ;
F_139 ( V_2 -> V_343 ) ;
if ( V_2 -> V_152 & V_156 ) {
V_16 = F_140 ( V_2 ) ;
if ( V_16 ) {
F_141 ( V_2 ) ;
}
}
F_61 ( V_2 ) ;
V_16 = F_142 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_143 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_144 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_2 -> V_152 & V_160 ) {
V_16 = F_9 ( V_2 ) ;
if ( V_16 )
return V_16 ;
}
if ( V_2 -> V_152 & V_341 ) {
V_16 = F_145 ( V_2 ) ;
if ( V_16 )
return V_16 ;
}
F_87 ( V_2 ) ;
V_2 -> V_346 = true ;
V_16 = F_102 ( V_2 ) ;
if ( V_16 ) {
F_16 ( V_2 -> V_23 , L_37 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_126 ( V_2 ) ;
if ( V_2 -> V_152 & V_160 )
F_26 ( V_2 ) ;
if ( V_2 -> V_152 & V_341 )
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
V_2 -> V_346 = false ;
}
return 0 ;
}
