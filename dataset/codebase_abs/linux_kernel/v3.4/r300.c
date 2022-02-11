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
V_2 -> V_17 -> V_9 . V_18 = & F_1 ;
V_2 -> V_17 -> V_9 . V_19 = & F_5 ;
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
void F_28 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
unsigned V_63 ;
int V_14 ;
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
V_14 = F_29 ( V_2 , V_42 , 64 ) ;
if ( V_14 ) {
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
void F_31 ( struct V_1 * V_2 )
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
void F_35 ( struct V_1 * V_2 )
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
bool F_39 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
T_4 V_128 ;
int V_14 ;
V_128 = F_32 ( V_129 ) ;
if ( ! F_40 ( V_128 ) ) {
F_41 ( & V_2 -> V_54 . V_55 . V_130 , V_42 ) ;
return false ;
}
V_14 = F_29 ( V_2 , V_42 , 2 ) ;
if ( ! V_14 ) {
F_26 ( V_42 , 0x80000000 ) ;
F_26 ( V_42 , 0x80000000 ) ;
F_30 ( V_2 , V_42 ) ;
}
V_42 -> V_131 = F_32 ( V_132 ) ;
return F_42 ( V_2 , & V_2 -> V_54 . V_55 . V_130 , V_42 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_133 V_134 ;
T_4 V_135 , V_3 ;
int V_136 = 0 ;
V_135 = F_32 ( V_129 ) ;
if ( ! F_40 ( V_135 ) ) {
return 0 ;
}
F_44 ( V_2 , & V_134 ) ;
V_135 = F_32 ( V_129 ) ;
F_45 ( V_2 -> V_21 , L_9 , V_137 , __LINE__ , V_135 ) ;
F_36 ( V_138 , 0 ) ;
V_3 = F_32 ( V_139 ) ;
F_36 ( V_139 , V_3 | V_140 ) ;
F_36 ( V_141 , 0 ) ;
F_36 ( V_142 , 0 ) ;
F_36 ( V_139 , V_3 ) ;
F_46 ( V_2 -> V_120 ) ;
F_47 ( V_2 ) ;
F_36 ( V_143 , F_48 ( 1 ) |
F_49 ( 1 ) ) ;
F_32 ( V_143 ) ;
F_50 ( 500 ) ;
F_36 ( V_143 , 0 ) ;
F_50 ( 1 ) ;
V_135 = F_32 ( V_129 ) ;
F_45 ( V_2 -> V_21 , L_9 , V_137 , __LINE__ , V_135 ) ;
F_36 ( V_143 , F_51 ( 1 ) ) ;
F_32 ( V_143 ) ;
F_50 ( 500 ) ;
F_36 ( V_143 , 0 ) ;
F_50 ( 1 ) ;
V_135 = F_32 ( V_129 ) ;
F_45 ( V_2 -> V_21 , L_9 , V_137 , __LINE__ , V_135 ) ;
F_52 ( V_2 -> V_120 ) ;
F_53 ( V_2 ) ;
if ( F_54 ( V_135 ) || F_55 ( V_135 ) ) {
F_16 ( V_2 -> V_21 , L_10 ) ;
V_2 -> V_144 = true ;
V_136 = - 1 ;
} else
F_45 ( V_2 -> V_21 , L_11 ) ;
F_56 ( V_2 , & V_134 ) ;
return V_136 ;
}
void F_57 ( struct V_1 * V_2 )
{
T_5 V_145 ;
T_4 V_3 ;
V_2 -> V_24 . V_146 = true ;
V_3 = F_32 ( V_147 ) ;
V_3 &= V_148 ;
switch ( V_3 ) {
case 0 : V_2 -> V_24 . V_149 = 64 ; break;
case 1 : V_2 -> V_24 . V_149 = 128 ; break;
case 2 : V_2 -> V_24 . V_149 = 256 ; break;
default: V_2 -> V_24 . V_149 = 128 ; break;
}
F_58 ( V_2 ) ;
V_145 = V_2 -> V_24 . V_150 ;
if ( V_2 -> V_151 & V_152 )
V_145 = ( F_32 ( V_153 ) & 0xffff ) << 16 ;
F_59 ( V_2 , & V_2 -> V_24 , V_145 ) ;
V_2 -> V_24 . V_154 = 0 ;
if ( ! ( V_2 -> V_151 & V_155 ) )
F_60 ( V_2 , & V_2 -> V_24 ) ;
F_61 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 , int V_156 )
{
T_1 V_157 , V_158 ;
if ( V_2 -> V_151 & V_152 )
return;
if ( ! ( V_2 -> V_151 & V_159 ) )
return;
switch ( V_156 ) {
case 0 :
V_158 = V_160 ;
break;
case 1 :
V_158 = V_161 ;
break;
case 2 :
V_158 = V_162 ;
break;
case 4 :
V_158 = V_163 ;
break;
case 8 :
V_158 = V_164 ;
break;
case 12 :
V_158 = V_165 ;
break;
case 16 :
default:
V_158 = V_166 ;
break;
}
V_157 = F_2 ( V_167 ) ;
if ( ( V_157 & V_168 ) ==
( V_158 << V_169 ) )
return;
V_157 &= ~ ( V_170 |
V_171 |
V_172 |
V_173 ) ;
V_157 |= V_158 ;
F_3 ( V_167 , V_157 ) ;
F_3 ( V_167 , ( V_157 |
V_171 ) ) ;
V_157 = F_2 ( V_167 ) ;
while ( V_157 == 0xffffffff )
V_157 = F_2 ( V_167 ) ;
}
int F_63 ( struct V_1 * V_2 )
{
T_4 V_157 ;
if ( V_2 -> V_151 & V_152 )
return 0 ;
if ( ! ( V_2 -> V_151 & V_159 ) )
return 0 ;
V_157 = F_2 ( V_167 ) ;
switch ( ( V_157 & V_168 ) >> V_169 ) {
case V_160 :
return 0 ;
case V_161 :
return 1 ;
case V_162 :
return 2 ;
case V_163 :
return 4 ;
case V_164 :
return 8 ;
case V_166 :
default:
return 16 ;
}
}
static int F_64 ( struct V_174 * V_175 , void * V_176 )
{
struct V_177 * V_178 = (struct V_177 * ) V_175 -> V_179 ;
struct V_180 * V_21 = V_178 -> V_181 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_182 ;
T_1 V_3 ;
V_3 = F_2 ( V_5 ) ;
F_65 ( V_175 , L_12 , V_3 ) ;
V_3 = F_2 ( V_31 ) ;
F_65 ( V_175 , L_13 , V_3 ) ;
V_3 = F_2 ( V_23 ) ;
F_65 ( V_175 , L_14 , V_3 ) ;
V_3 = F_2 ( V_29 ) ;
F_65 ( V_175 , L_15 , V_3 ) ;
V_3 = F_2 ( V_28 ) ;
F_65 ( V_175 , L_16 , V_3 ) ;
V_3 = F_2 ( V_30 ) ;
F_65 ( V_175 , L_17 , V_3 ) ;
V_3 = F_2 ( V_35 ) ;
F_65 ( V_175 , L_18 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
#if F_66 ( V_183 )
return F_67 ( V_2 , V_184 , 1 ) ;
#else
return 0 ;
#endif
}
static int F_68 ( struct V_185 * V_186 ,
struct V_187 * V_188 ,
unsigned V_189 , unsigned V_190 )
{
struct V_191 * V_192 ;
struct V_193 * V_194 ;
volatile T_1 * V_195 ;
T_1 V_3 , V_196 = 0 ;
unsigned V_4 ;
int V_14 ;
T_4 V_197 ;
V_195 = V_186 -> V_195 -> V_8 ;
V_194 = (struct V_193 * ) V_186 -> V_194 ;
V_197 = F_69 ( V_186 , V_189 ) ;
switch( V_190 ) {
case V_198 :
case V_199 :
V_14 = F_70 ( V_186 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_189 , V_190 ) ;
F_71 ( V_186 , V_188 ) ;
return V_14 ;
}
break;
case V_200 :
case V_201 :
V_14 = F_72 ( V_186 , V_188 , V_189 , V_190 ) ;
if ( V_14 )
return V_14 ;
break;
case V_202 :
case V_203 :
case V_204 :
case V_205 :
V_4 = ( V_190 - V_202 ) >> 2 ;
V_14 = F_73 ( V_186 , & V_192 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_189 , V_190 ) ;
F_71 ( V_186 , V_188 ) ;
return V_14 ;
}
V_194 -> V_206 [ V_4 ] . V_15 = V_192 -> V_15 ;
V_194 -> V_206 [ V_4 ] . V_207 = V_197 ;
V_194 -> V_208 = true ;
V_195 [ V_189 ] = V_197 + ( ( T_4 ) V_192 -> V_209 . V_210 ) ;
break;
case V_211 :
V_14 = F_73 ( V_186 , & V_192 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_189 , V_190 ) ;
F_71 ( V_186 , V_188 ) ;
return V_14 ;
}
V_194 -> V_212 . V_15 = V_192 -> V_15 ;
V_194 -> V_212 . V_207 = V_197 ;
V_194 -> V_213 = true ;
V_195 [ V_189 ] = V_197 + ( ( T_4 ) V_192 -> V_209 . V_210 ) ;
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
V_4 = ( V_190 - V_214 ) >> 2 ;
V_14 = F_73 ( V_186 , & V_192 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_189 , V_190 ) ;
F_71 ( V_186 , V_188 ) ;
return V_14 ;
}
if ( V_186 -> V_215 & V_216 ) {
V_195 [ V_189 ] = ( V_197 & 31 ) |
( ( V_197 & ~ 31 ) + ( T_4 ) V_192 -> V_209 . V_210 ) ;
} else {
if ( V_192 -> V_209 . V_217 & V_218 )
V_196 |= V_219 ;
if ( V_192 -> V_209 . V_217 & V_220 )
V_196 |= V_221 ;
else if ( V_192 -> V_209 . V_217 & V_222 )
V_196 |= V_223 ;
V_3 = V_197 + ( ( T_4 ) V_192 -> V_209 . V_210 ) ;
V_3 |= V_196 ;
V_195 [ V_189 ] = V_3 ;
}
V_194 -> V_224 [ V_4 ] . V_15 = V_192 -> V_15 ;
V_194 -> V_225 = true ;
break;
case 0x2084 :
V_194 -> V_226 = V_197 ;
break;
case 0x20B4 :
V_194 -> V_227 = V_197 & 0x7F ;
break;
case 0x2134 :
V_194 -> V_228 = V_197 & 0x00FFFFFFUL ;
break;
case 0x2088 :
if ( V_186 -> V_2 -> V_111 < V_229 )
goto V_230;
V_194 -> V_231 = V_197 & 0xFFFFFF ;
break;
case 0x43E4 :
V_194 -> V_232 = ( ( V_197 >> 13 ) & 0x1FFF ) + 1 ;
if ( V_186 -> V_2 -> V_111 < V_229 ) {
V_194 -> V_232 -= 1440 ;
}
V_194 -> V_208 = true ;
V_194 -> V_213 = true ;
break;
case 0x4E00 :
if ( ( V_197 & ( 1 << 10 ) ) &&
V_186 -> V_2 -> V_233 != V_186 -> V_234 ) {
F_13 ( L_20 ) ;
return - V_11 ;
}
V_194 -> V_235 = ( ( V_197 >> 5 ) & 0x3 ) + 1 ;
V_194 -> V_208 = true ;
break;
case 0x4E38 :
case 0x4E3C :
case 0x4E40 :
case 0x4E44 :
if ( ! ( V_186 -> V_215 & V_216 ) ) {
V_14 = F_73 ( V_186 , & V_192 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_189 , V_190 ) ;
F_71 ( V_186 , V_188 ) ;
return V_14 ;
}
if ( V_192 -> V_209 . V_217 & V_218 )
V_196 |= V_236 ;
if ( V_192 -> V_209 . V_217 & V_220 )
V_196 |= V_237 ;
else if ( V_192 -> V_209 . V_217 & V_222 )
V_196 |= V_238 ;
V_3 = V_197 & ~ ( 0x7 << 16 ) ;
V_3 |= V_196 ;
V_195 [ V_189 ] = V_3 ;
}
V_4 = ( V_190 - 0x4E38 ) >> 2 ;
V_194 -> V_206 [ V_4 ] . V_239 = V_197 & 0x3FFE ;
switch ( ( ( V_197 >> 21 ) & 0xF ) ) {
case 9 :
case 11 :
case 12 :
V_194 -> V_206 [ V_4 ] . V_240 = 1 ;
break;
case 3 :
case 4 :
case 13 :
case 15 :
V_194 -> V_206 [ V_4 ] . V_240 = 2 ;
break;
case 5 :
if ( V_186 -> V_2 -> V_111 < V_229 ) {
F_13 ( L_21 ,
( ( V_197 >> 21 ) & 0xF ) ) ;
return - V_11 ;
}
case 6 :
V_194 -> V_206 [ V_4 ] . V_240 = 4 ;
break;
case 10 :
V_194 -> V_206 [ V_4 ] . V_240 = 8 ;
break;
case 7 :
V_194 -> V_206 [ V_4 ] . V_240 = 16 ;
break;
default:
F_13 ( L_22 ,
( ( V_197 >> 21 ) & 0xF ) ) ;
return - V_11 ;
}
V_194 -> V_208 = true ;
break;
case 0x4F00 :
if ( V_197 & 2 ) {
V_194 -> V_241 = true ;
} else {
V_194 -> V_241 = false ;
}
V_194 -> V_213 = true ;
break;
case 0x4F10 :
switch ( ( V_197 & 0xF ) ) {
case 0 :
case 1 :
V_194 -> V_212 . V_240 = 2 ;
break;
case 2 :
V_194 -> V_212 . V_240 = 4 ;
break;
default:
F_13 ( L_23 ,
( V_197 & 0xF ) ) ;
return - V_11 ;
}
V_194 -> V_213 = true ;
break;
case 0x4F24 :
if ( ! ( V_186 -> V_215 & V_216 ) ) {
V_14 = F_73 ( V_186 , & V_192 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_189 , V_190 ) ;
F_71 ( V_186 , V_188 ) ;
return V_14 ;
}
if ( V_192 -> V_209 . V_217 & V_218 )
V_196 |= V_242 ;
if ( V_192 -> V_209 . V_217 & V_220 )
V_196 |= V_243 ;
else if ( V_192 -> V_209 . V_217 & V_222 )
V_196 |= V_244 ;
V_3 = V_197 & ~ ( 0x7 << 16 ) ;
V_3 |= V_196 ;
V_195 [ V_189 ] = V_3 ;
}
V_194 -> V_212 . V_239 = V_197 & 0x3FFC ;
V_194 -> V_213 = true ;
break;
case 0x4104 :
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
bool V_245 ;
V_245 = ! ! ( V_197 & ( 1 << V_4 ) ) ;
V_194 -> V_224 [ V_4 ] . V_245 = V_245 ;
}
V_194 -> V_225 = true ;
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
V_4 = ( V_190 - 0x44C0 ) >> 2 ;
V_3 = ( V_197 >> 25 ) & 0x3 ;
V_194 -> V_224 [ V_4 ] . V_246 = V_3 ;
switch ( ( V_197 & 0x1F ) ) {
case V_247 :
case V_248 :
case V_249 :
V_194 -> V_224 [ V_4 ] . V_240 = 1 ;
V_194 -> V_224 [ V_4 ] . V_250 = V_251 ;
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
V_194 -> V_224 [ V_4 ] . V_240 = 2 ;
V_194 -> V_224 [ V_4 ] . V_250 = V_251 ;
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
V_194 -> V_224 [ V_4 ] . V_240 = 4 ;
V_194 -> V_224 [ V_4 ] . V_250 = V_251 ;
break;
case V_269 :
case V_270 :
case V_271 :
V_194 -> V_224 [ V_4 ] . V_240 = 8 ;
V_194 -> V_224 [ V_4 ] . V_250 = V_251 ;
break;
case V_272 :
V_194 -> V_224 [ V_4 ] . V_240 = 16 ;
V_194 -> V_224 [ V_4 ] . V_250 = V_251 ;
break;
case V_273 :
V_194 -> V_224 [ V_4 ] . V_240 = 1 ;
V_194 -> V_224 [ V_4 ] . V_250 = V_274 ;
break;
case V_275 :
if ( V_186 -> V_2 -> V_111 < V_276 ) {
F_13 ( L_24 ,
( V_197 & 0x1F ) ) ;
return - V_11 ;
}
case V_277 :
case V_278 :
V_194 -> V_224 [ V_4 ] . V_240 = 1 ;
V_194 -> V_224 [ V_4 ] . V_250 = V_279 ;
break;
default:
F_13 ( L_24 ,
( V_197 & 0x1F ) ) ;
return - V_11 ;
}
V_194 -> V_225 = true ;
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
V_4 = ( V_190 - 0x4400 ) >> 2 ;
V_3 = V_197 & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_194 -> V_224 [ V_4 ] . V_280 = false ;
}
V_3 = ( V_197 >> 3 ) & 0x7 ;
if ( V_3 == 2 || V_3 == 4 || V_3 == 6 ) {
V_194 -> V_224 [ V_4 ] . V_281 = false ;
}
V_194 -> V_225 = true ;
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
V_4 = ( V_190 - 0x4500 ) >> 2 ;
V_3 = V_197 & 0x3FFF ;
V_194 -> V_224 [ V_4 ] . V_239 = V_3 + 1 ;
if ( V_186 -> V_2 -> V_111 >= V_229 ) {
V_3 = ( ( V_197 >> 15 ) & 1 ) << 11 ;
V_194 -> V_224 [ V_4 ] . V_282 = V_3 ;
V_3 = ( ( V_197 >> 16 ) & 1 ) << 11 ;
V_194 -> V_224 [ V_4 ] . V_283 = V_3 ;
if ( V_197 & ( 1 << 14 ) ) {
V_194 -> V_224 [ V_4 ] . V_250 =
V_274 ;
}
} else if ( V_197 & ( 1 << 14 ) ) {
F_13 ( L_25 ) ;
return - V_11 ;
}
V_194 -> V_225 = true ;
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
V_4 = ( V_190 - 0x4480 ) >> 2 ;
V_3 = V_197 & 0x7FF ;
V_194 -> V_224 [ V_4 ] . V_284 = V_3 + 1 ;
V_3 = ( V_197 >> 11 ) & 0x7FF ;
V_194 -> V_224 [ V_4 ] . V_285 = V_3 + 1 ;
V_3 = ( V_197 >> 26 ) & 0xF ;
V_194 -> V_224 [ V_4 ] . V_286 = V_3 ;
V_3 = V_197 & ( 1 << 31 ) ;
V_194 -> V_224 [ V_4 ] . V_287 = ! ! V_3 ;
V_3 = ( V_197 >> 22 ) & 0xF ;
V_194 -> V_224 [ V_4 ] . V_288 = V_3 ;
V_194 -> V_225 = true ;
break;
case V_289 :
V_14 = F_73 ( V_186 , & V_192 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_189 , V_190 ) ;
F_71 ( V_186 , V_188 ) ;
return V_14 ;
}
V_195 [ V_189 ] = V_197 + ( ( T_4 ) V_192 -> V_209 . V_210 ) ;
break;
case 0x4e0c :
V_194 -> V_290 = V_197 ;
V_194 -> V_208 = true ;
break;
case 0x43a4 :
if ( V_186 -> V_2 -> V_291 != V_186 -> V_234 ) {
if ( V_197 & 0x1 )
V_195 [ V_189 ] = V_197 & ~ 1 ;
}
break;
case 0x4f1c :
V_194 -> V_292 = ! ! ( V_197 & ( 1 << 5 ) ) ;
V_194 -> V_208 = true ;
V_194 -> V_213 = true ;
if ( V_186 -> V_2 -> V_291 != V_186 -> V_234 ) {
if ( V_197 & ( V_293 |
V_294 |
V_295 |
V_296 ) )
goto V_230;
}
break;
case 0x4e04 :
V_194 -> V_297 = ! ! ( V_197 & ( 1 << 2 ) ) ;
V_194 -> V_208 = true ;
break;
case V_298 :
V_14 = F_73 ( V_186 , & V_192 ) ;
if ( V_14 ) {
F_13 ( L_19 ,
V_189 , V_190 ) ;
F_71 ( V_186 , V_188 ) ;
return V_14 ;
}
V_194 -> V_299 . V_15 = V_192 -> V_15 ;
V_194 -> V_299 . V_207 = V_197 ;
V_194 -> V_300 = true ;
V_195 [ V_189 ] = V_197 + ( ( T_4 ) V_192 -> V_209 . V_210 ) ;
break;
case V_301 :
V_194 -> V_299 . V_239 = V_197 & 0x3FFE ;
V_194 -> V_300 = true ;
break;
case V_302 :
V_194 -> V_303 = V_197 & 0x1 ;
V_194 -> V_300 = true ;
break;
case 0x4f30 :
case 0x4f34 :
case 0x4f44 :
case 0x4f54 :
if ( V_197 && ( V_186 -> V_2 -> V_291 != V_186 -> V_234 ) )
goto V_230;
break;
case 0x4028 :
if ( V_197 && ( V_186 -> V_2 -> V_291 != V_186 -> V_234 ) )
goto V_230;
if ( V_186 -> V_2 -> V_111 >= V_304 )
break;
goto V_230;
break;
case 0x4be8 :
if ( V_186 -> V_2 -> V_111 == V_305 )
break;
default:
goto V_230;
}
return 0 ;
V_230:
F_38 ( V_306 L_26 ,
V_190 , V_189 , V_197 ) ;
return - V_11 ;
}
static int F_74 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_191 * V_192 ;
struct V_193 * V_194 ;
volatile T_1 * V_195 ;
unsigned V_189 ;
int V_14 ;
V_195 = V_186 -> V_195 -> V_8 ;
V_189 = V_188 -> V_189 + 1 ;
V_194 = (struct V_193 * ) V_186 -> V_194 ;
switch( V_188 -> V_307 ) {
case V_308 :
V_14 = F_75 ( V_186 , V_188 , V_189 ) ;
if ( V_14 )
return V_14 ;
break;
case V_309 :
V_14 = F_73 ( V_186 , & V_192 ) ;
if ( V_14 ) {
F_13 ( L_27 , V_188 -> V_307 ) ;
F_71 ( V_186 , V_188 ) ;
return V_14 ;
}
V_195 [ V_189 + 1 ] = F_69 ( V_186 , V_189 + 1 ) + ( ( T_4 ) V_192 -> V_209 . V_210 ) ;
V_14 = F_76 ( V_186 , V_188 , V_192 -> V_15 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_310 :
if ( ( ( F_69 ( V_186 , V_189 + 1 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_11 ;
}
V_194 -> V_226 = F_69 ( V_186 , V_189 + 1 ) ;
V_194 -> V_311 = V_188 -> V_312 - 1 ;
V_14 = F_77 ( V_186 -> V_2 , V_194 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_313 :
if ( ( ( F_69 ( V_186 , V_189 ) >> 4 ) & 0x3 ) != 3 ) {
F_13 ( L_28 ) ;
return - V_11 ;
}
V_194 -> V_226 = F_69 ( V_186 , V_189 ) ;
V_194 -> V_311 = V_188 -> V_312 ;
V_14 = F_77 ( V_186 -> V_2 , V_194 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_314 :
V_194 -> V_226 = F_69 ( V_186 , V_189 + 1 ) ;
V_14 = F_77 ( V_186 -> V_2 , V_194 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_315 :
V_194 -> V_226 = F_69 ( V_186 , V_189 ) ;
V_14 = F_77 ( V_186 -> V_2 , V_194 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_316 :
V_194 -> V_226 = F_69 ( V_186 , V_189 + 1 ) ;
V_14 = F_77 ( V_186 -> V_2 , V_194 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_317 :
V_194 -> V_226 = F_69 ( V_186 , V_189 ) ;
V_14 = F_77 ( V_186 -> V_2 , V_194 ) ;
if ( V_14 ) {
return V_14 ;
}
break;
case V_318 :
case V_319 :
if ( V_186 -> V_2 -> V_291 != V_186 -> V_234 )
return - V_11 ;
break;
case V_320 :
if ( V_186 -> V_2 -> V_233 != V_186 -> V_234 )
return - V_11 ;
break;
case V_321 :
break;
default:
F_13 ( L_29 , V_188 -> V_307 ) ;
return - V_11 ;
}
return 0 ;
}
int F_78 ( struct V_185 * V_186 )
{
struct V_187 V_188 ;
struct V_193 * V_194 ;
int V_14 ;
V_194 = F_79 ( sizeof( * V_194 ) , V_322 ) ;
if ( V_194 == NULL )
return - V_323 ;
F_80 ( V_186 -> V_2 , V_194 ) ;
V_186 -> V_194 = V_194 ;
do {
V_14 = F_81 ( V_186 , & V_188 , V_186 -> V_189 ) ;
if ( V_14 ) {
return V_14 ;
}
V_186 -> V_189 += V_188 . V_312 + 2 ;
switch ( V_188 . type ) {
case V_324 :
V_14 = F_82 ( V_186 , & V_188 ,
V_186 -> V_2 -> V_54 . V_55 . V_325 ,
V_186 -> V_2 -> V_54 . V_55 . V_326 ,
& F_68 ) ;
break;
case V_327 :
break;
case V_328 :
V_14 = F_74 ( V_186 , & V_188 ) ;
break;
default:
F_13 ( L_30 , V_188 . type ) ;
return - V_11 ;
}
if ( V_14 ) {
return V_14 ;
}
} while ( V_186 -> V_189 < V_186 -> V_329 [ V_186 -> V_330 ] . V_331 );
return 0 ;
}
void F_83 ( struct V_1 * V_2 )
{
V_2 -> V_54 . V_55 . V_325 = V_332 ;
V_2 -> V_54 . V_55 . V_326 = F_84 ( V_332 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_133 V_134 ;
int V_14 ;
V_14 = F_86 ( V_2 ) ;
if ( V_14 ) {
F_16 ( V_2 -> V_21 , L_31 ) ;
}
F_44 ( V_2 , & V_134 ) ;
if ( V_2 -> V_151 & V_155 ) {
F_36 ( V_333 ,
F_87 ( V_2 -> V_24 . V_25 >> 16 ) |
F_88 ( V_2 -> V_24 . V_26 >> 16 ) ) ;
F_36 ( V_334 , F_6 ( V_2 -> V_24 . V_335 ) ) ;
F_36 ( V_336 ,
F_7 ( V_2 -> V_24 . V_335 ) & 0xff ) ;
} else {
F_36 ( V_333 , 0x0FFFFFFF ) ;
F_36 ( V_334 , 0 ) ;
F_36 ( V_336 , 0 ) ;
}
if ( F_33 ( V_2 ) )
F_19 ( L_32 ) ;
F_36 ( V_337 ,
F_89 ( V_2 -> V_24 . V_33 >> 16 ) |
F_90 ( V_2 -> V_24 . V_338 >> 16 ) ) ;
F_56 ( V_2 , & V_134 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
T_4 V_3 ;
if ( V_339 != - 1 && V_339 )
F_92 ( V_2 , 1 ) ;
V_3 = F_93 ( V_340 ) ;
V_3 |= F_94 ( 1 ) | F_95 ( 1 ) ;
if ( ( V_2 -> V_111 == V_304 ) || ( V_2 -> V_111 == V_341 ) )
V_3 |= F_96 ( 1 ) ;
F_97 ( V_340 , V_3 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_14 ;
F_99 ( V_2 ) ;
F_85 ( V_2 ) ;
F_91 ( V_2 ) ;
F_35 ( V_2 ) ;
if ( V_2 -> V_151 & V_159 ) {
V_14 = F_15 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_111 == V_112 ||
V_2 -> V_111 == V_122 ||
V_2 -> V_111 == V_304 )
F_53 ( V_2 ) ;
if ( V_2 -> V_151 & V_342 ) {
V_14 = F_100 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_101 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_102 ( V_2 , V_343 ) ;
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
V_14 = F_106 ( V_2 , V_343 , & V_2 -> V_42 [ V_343 ] ) ;
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
if ( V_2 -> V_151 & V_159 )
F_20 ( V_2 ) ;
if ( V_2 -> V_151 & V_342 )
F_108 ( V_2 ) ;
F_91 ( V_2 ) ;
if ( F_109 ( V_2 ) ) {
F_110 ( V_2 -> V_21 , L_36 ,
F_32 ( V_129 ) ,
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
if ( V_2 -> V_151 & V_159 )
F_20 ( V_2 ) ;
if ( V_2 -> V_151 & V_342 )
F_108 ( V_2 ) ;
return 0 ;
}
void F_118 ( struct V_1 * V_2 )
{
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
if ( V_2 -> V_151 & V_159 )
F_22 ( V_2 ) ;
if ( V_2 -> V_151 & V_342 )
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
F_32 ( V_129 ) ,
F_32 ( V_345 ) ) ;
}
if ( F_137 ( V_2 ) == false )
return - V_11 ;
F_31 ( V_2 ) ;
F_138 ( V_2 -> V_346 ) ;
if ( V_2 -> V_151 & V_155 ) {
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
if ( V_2 -> V_151 & V_159 ) {
V_14 = F_9 ( V_2 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 -> V_151 & V_342 ) {
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
if ( V_2 -> V_151 & V_159 )
F_22 ( V_2 ) ;
if ( V_2 -> V_151 & V_342 )
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
V_2 -> V_344 = false ;
}
return 0 ;
}
