static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 [ 0 ] ;
struct V_10 * V_11 =
(struct V_10 * ) V_2 -> V_12 ;
unsigned int V_13 = V_11 -> V_13 ;
unsigned int V_14 = V_11 -> V_14 ;
int V_15 = V_11 -> V_15 ;
unsigned int V_16 = ( 1 << F_3 ( V_15 ) ) - 1 ;
unsigned int V_17 = V_11 -> V_17 ;
unsigned short V_18 , V_19 ;
int V_20 ;
struct V_21 * V_22 ;
int V_23 = 0 ;
V_18 = ( V_4 -> V_24 . integer . V_24 [ 0 ] & V_16 ) ;
V_16 = 0xf ;
if ( V_18 )
V_18 = V_16 ;
if ( V_17 )
V_18 = V_16 - V_18 ;
V_19 = V_16 << V_14 ;
V_18 = V_18 << V_14 ;
F_4 ( & V_8 -> V_25 -> V_26 ) ;
if ( F_5 ( V_8 -> V_25 , V_13 , V_19 , V_18 ) ) {
F_6 (path, &widget->dapm->card->paths, list) {
if ( V_22 -> V_2 != V_2 )
continue;
V_23 = 1 ;
if ( V_18 )
V_22 -> V_27 = V_17 ? 0 : 1 ;
else
V_22 -> V_27 = V_17 ? 1 : 0 ;
F_7 ( V_22 -> V_28 , L_1 ) ;
F_7 ( V_22 -> V_29 , L_2 ) ;
break;
}
if ( V_23 )
F_8 ( V_8 -> V_30 ) ;
}
V_20 = F_9 ( V_8 -> V_25 , V_13 , V_19 , V_18 ) ;
F_10 ( & V_8 -> V_25 -> V_26 ) ;
return V_20 ;
}
static int F_11 ( struct V_31 * V_25 )
{
struct V_32 * V_33 = F_12 ( V_25 ) ;
struct V_34 * V_30 = & V_25 -> V_30 ;
F_13 ( V_30 , V_35 ,
F_14 ( V_35 ) ) ;
F_15 ( V_30 , V_36 , F_14 ( V_36 ) ) ;
if ( V_33 -> V_37 == V_38 ) {
F_13 ( V_30 , V_39 ,
F_14 ( V_39 ) ) ;
F_15 ( V_30 , V_40 ,
F_14 ( V_40 ) ) ;
}
return 0 ;
}
static int F_16 ( struct V_41 * V_42 ,
struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_31 * V_25 = V_46 -> V_25 ;
struct V_32 * V_33 = F_12 ( V_25 ) ;
int V_47 = 0 , V_48 = 0 , V_49 , V_50 = 0 ;
T_1 V_51 , V_52 , V_53 , V_54 , V_55 , V_56 = 1 , V_57 = 1 , V_58 = 1 ;
T_2 V_59 , V_60 = 1 ;
int V_61 ;
V_51 = F_17 ( V_25 , V_62 ) & ( ~ ( 0x3 << 4 ) ) ;
switch ( F_18 ( V_44 ) ) {
case V_63 :
break;
case V_64 :
V_51 |= ( 0x01 << 4 ) ;
break;
case V_65 :
V_51 |= ( 0x02 << 4 ) ;
break;
case V_66 :
V_51 |= ( 0x03 << 4 ) ;
break;
}
F_19 ( V_25 , V_62 , V_51 ) ;
V_49 = ( F_20 ( V_44 ) % 11025 == 0 ) ? 44100 : 48000 ;
for ( V_55 = 2 ; V_55 < 18 ; V_55 ++ )
if ( V_33 -> V_67 / ( 128 * V_55 ) == V_49 ) {
V_48 = 1 ;
break;
}
if ( V_48 ) {
V_55 &= 0xf ;
F_19 ( V_25 , V_68 , V_55 << V_69 ) ;
F_19 ( V_25 , V_70 , V_71 ) ;
F_9 ( V_25 , V_68 , V_72 , 0 ) ;
} else {
F_19 ( V_25 , V_70 , V_73 ) ;
F_9 ( V_25 , V_68 ,
V_72 , V_72 ) ;
}
V_51 = ( V_74 | V_75 ) ;
V_51 |= ( V_49 == 44100 ) ? V_76 : V_77 ;
if ( F_20 ( V_44 ) >= 64000 )
V_51 |= V_78 ;
F_19 ( V_25 , V_79 , V_51 ) ;
V_51 = ( V_49 * 20 ) / F_20 ( V_44 ) ;
if ( F_20 ( V_44 ) < 64000 )
V_51 /= 2 ;
V_51 /= 5 ;
V_51 -= 2 ;
V_51 |= ( V_51 << 4 ) ;
F_19 ( V_25 , V_80 , V_51 ) ;
if ( V_48 )
return 0 ;
V_47 = ( 2048 * V_49 ) / ( V_33 -> V_67 / 1000 ) ;
for ( V_53 = 1 ; V_53 <= 16 ; V_53 ++ )
for ( V_54 = 1 ; V_54 <= 8 ; V_54 ++ ) {
for ( V_52 = 4 ; V_52 <= 55 ; V_52 ++ ) {
int V_81 = ( 1000 * V_52 * V_53 ) / V_54 ;
if ( abs ( V_47 - V_81 ) <
abs ( V_47 - V_50 ) ) {
V_58 = V_52 ; V_60 = 0 ;
V_57 = V_53 ; V_56 = V_54 ;
V_50 = V_81 ;
}
if ( V_81 == V_47 )
goto V_23;
}
}
for ( V_54 = 1 ; V_54 <= 8 ; V_54 ++ ) {
V_52 = V_47 * V_54 / 1000 ;
if ( V_52 < 4 || V_52 > 11 )
continue;
V_59 = ( ( 2048 * V_54 * V_49 ) - V_52 * V_33 -> V_67 )
* 100 / ( V_33 -> V_67 / 100 ) ;
V_61 = ( 10000 * V_52 + V_59 ) / ( 10 * V_54 ) ;
if ( abs ( V_47 - V_61 ) < abs ( V_47 - V_50 ) ) {
V_58 = V_52 ; V_60 = V_59 ; V_57 = 1 ; V_56 = V_54 ;
V_50 = V_61 ;
}
if ( V_61 == V_47 )
goto V_23;
}
if ( V_50 == 0 ) {
F_21 ( V_82 L_3 , V_83 ) ;
return - V_84 ;
}
V_23:
F_9 ( V_25 , V_68 , V_85 , V_56 ) ;
F_19 ( V_25 , V_86 ,
V_57 << V_87 ) ;
F_19 ( V_25 , V_88 , V_58 << V_89 ) ;
F_19 ( V_25 , V_90 ,
( V_60 >> 6 ) << V_91 ) ;
F_19 ( V_25 , V_92 ,
( V_60 & 0x3F ) << V_93 ) ;
return 0 ;
}
static int F_22 ( struct V_45 * V_46 , int V_94 )
{
struct V_31 * V_25 = V_46 -> V_25 ;
T_1 V_95 = F_17 ( V_25 , V_96 ) & ~ V_97 ;
T_1 V_98 = F_17 ( V_25 , V_99 ) & ~ V_97 ;
if ( V_94 ) {
F_19 ( V_25 , V_96 , V_95 | V_97 ) ;
F_19 ( V_25 , V_99 , V_98 | V_97 ) ;
} else {
F_19 ( V_25 , V_96 , V_95 ) ;
F_19 ( V_25 , V_99 , V_98 ) ;
}
return 0 ;
}
static int F_23 ( struct V_45 * V_100 ,
int V_101 , unsigned int V_102 , int V_103 )
{
struct V_31 * V_25 = V_100 -> V_25 ;
struct V_32 * V_33 = F_12 ( V_25 ) ;
F_9 ( V_25 , V_104 , V_105 ,
V_101 << V_106 ) ;
F_9 ( V_25 , V_104 , V_107 ,
V_101 << V_108 ) ;
V_33 -> V_67 = V_102 ;
return 0 ;
}
static int F_24 ( struct V_45 * V_100 ,
unsigned int V_109 )
{
struct V_31 * V_25 = V_100 -> V_25 ;
struct V_32 * V_33 = F_12 ( V_25 ) ;
T_1 V_110 , V_111 ;
int V_112 = 0 ;
V_110 = F_17 ( V_25 , V_113 ) & 0x3f ;
V_111 = F_17 ( V_25 , V_62 ) & 0x3f ;
switch ( V_109 & V_114 ) {
case V_115 :
V_33 -> V_116 = 1 ;
V_110 |= V_117 | V_118 ;
break;
case V_119 :
V_33 -> V_116 = 0 ;
V_110 &= ~ ( V_117 | V_118 ) ;
break;
default:
return - V_84 ;
}
switch ( V_109 & ( V_120 |
V_121 ) ) {
case ( V_122 | V_123 ) :
break;
case ( V_124 | V_125 ) :
V_112 = 1 ;
case ( V_126 | V_125 ) :
V_111 |= ( 0x01 << 6 ) ;
break;
case ( V_127 | V_123 ) :
V_111 |= ( 0x02 << 6 ) ;
break;
case ( V_128 | V_123 ) :
V_111 |= ( 0x03 << 6 ) ;
break;
default:
return - V_84 ;
}
F_19 ( V_25 , V_113 , V_110 ) ;
F_19 ( V_25 , V_62 , V_111 ) ;
F_19 ( V_25 , V_129 , V_112 ) ;
return 0 ;
}
static int F_25 ( struct V_31 * V_25 )
{
T_1 V_130 , V_131 , * V_132 = V_25 -> V_133 ;
V_130 = V_132 [ 0xD ] ;
V_131 = V_132 [ 0x8 ] ;
F_19 ( V_25 , V_134 , 0x0D ) ;
F_19 ( V_25 , 0xD , 0x0D ) ;
F_19 ( V_25 , 0x8 , 0x5C ) ;
F_19 ( V_25 , 0x8 , 0x5D ) ;
F_19 ( V_25 , 0x8 , 0x5C ) ;
F_19 ( V_25 , V_134 , 0x00 ) ;
V_132 [ 0xD ] = V_130 ;
V_132 [ 0x8 ] = V_131 ;
return 0 ;
}
static int F_26 ( struct V_135 * V_136 ,
unsigned long V_137 , void * V_51 )
{
struct V_138 * V_139 =
F_27 ( V_136 , struct V_138 , V_136 ) ;
struct V_32 * V_33 = V_139 -> V_33 ;
if ( V_137 & V_140 ) {
if ( F_28 ( V_33 -> V_141 ) )
F_29 ( V_33 -> V_141 , 0 ) ;
V_33 -> V_25 -> V_142 = 1 ;
}
return 0 ;
}
static int F_30 ( struct V_31 * V_25 , int V_143 )
{
struct V_32 * V_33 = F_12 ( V_25 ) ;
int V_144 , V_20 ;
T_1 * V_132 = V_25 -> V_133 ;
if ( V_143 ) {
V_20 = F_31 ( F_14 ( V_33 -> V_145 ) ,
V_33 -> V_145 ) ;
if ( V_20 )
goto V_146;
V_33 -> V_143 = 1 ;
if ( ! V_25 -> V_142 )
goto V_146;
if ( F_28 ( V_33 -> V_141 ) ) {
F_32 ( 1 ) ;
F_29 ( V_33 -> V_141 , 1 ) ;
}
V_25 -> V_147 = 0 ;
for ( V_144 = V_80 ; V_144 < F_14 ( V_148 ) ; V_144 ++ )
F_19 ( V_25 , V_144 , V_132 [ V_144 ] ) ;
if ( V_33 -> V_37 == V_38 )
F_25 ( V_25 ) ;
V_25 -> V_142 = 0 ;
} else {
F_19 ( V_25 , V_149 , V_150 ) ;
V_25 -> V_142 = 1 ;
V_33 -> V_143 = 0 ;
V_25 -> V_147 = 1 ;
V_20 = F_33 ( F_14 ( V_33 -> V_145 ) ,
V_33 -> V_145 ) ;
}
V_146:
return V_20 ;
}
static int F_34 ( struct V_31 * V_25 ,
enum V_151 V_152 )
{
struct V_32 * V_33 = F_12 ( V_25 ) ;
switch ( V_152 ) {
case V_153 :
break;
case V_154 :
if ( V_25 -> V_30 . V_155 == V_156 &&
V_33 -> V_116 ) {
F_9 ( V_25 , V_68 ,
V_72 , V_72 ) ;
}
break;
case V_156 :
if ( ! V_33 -> V_143 )
F_30 ( V_25 , 1 ) ;
if ( V_25 -> V_30 . V_155 == V_154 &&
V_33 -> V_116 ) {
F_9 ( V_25 , V_68 ,
V_72 , 0 ) ;
}
break;
case V_157 :
if ( V_33 -> V_143 )
F_30 ( V_25 , 0 ) ;
break;
}
V_25 -> V_30 . V_155 = V_152 ;
return 0 ;
}
static int F_35 ( struct V_31 * V_25 )
{
F_34 ( V_25 , V_157 ) ;
return 0 ;
}
static int F_36 ( struct V_31 * V_25 )
{
F_34 ( V_25 , V_156 ) ;
return 0 ;
}
static int F_37 ( struct V_31 * V_25 )
{
struct V_32 * V_33 = F_12 ( V_25 ) ;
F_19 ( V_25 , V_134 , V_158 ) ;
F_19 ( V_25 , V_149 , V_150 ) ;
F_19 ( V_25 , V_96 , V_159 | V_97 ) ;
F_19 ( V_25 , V_99 , V_159 | V_97 ) ;
F_19 ( V_25 , V_160 , V_159 | V_161 ) ;
F_19 ( V_25 , V_162 , V_159 | V_161 ) ;
F_19 ( V_25 , V_163 , V_159 | V_161 ) ;
F_19 ( V_25 , V_164 , V_159 | V_161 ) ;
F_19 ( V_25 , V_165 , V_159 | V_161 ) ;
F_19 ( V_25 , V_166 , V_159 | V_161 ) ;
F_19 ( V_25 , V_167 , V_159 | V_161 ) ;
F_19 ( V_25 , V_168 , V_159 | V_161 ) ;
F_9 ( V_25 , V_169 , V_170 , V_170 ) ;
F_9 ( V_25 , V_171 , V_170 , V_170 ) ;
F_9 ( V_25 , V_172 , V_170 , V_170 ) ;
F_9 ( V_25 , V_173 , V_170 , V_170 ) ;
F_9 ( V_25 , V_174 , V_170 , V_170 ) ;
F_9 ( V_25 , V_175 , V_170 , V_170 ) ;
F_9 ( V_25 , V_176 , V_170 , V_170 ) ;
F_19 ( V_25 , V_177 , V_178 ) ;
F_19 ( V_25 , V_179 , V_178 ) ;
F_19 ( V_25 , V_180 , 0x0 ) ;
F_19 ( V_25 , V_181 , 0x0 ) ;
F_19 ( V_25 , V_182 , V_159 ) ;
F_19 ( V_25 , V_183 , V_159 ) ;
F_19 ( V_25 , V_184 , V_159 ) ;
F_19 ( V_25 , V_185 , V_159 ) ;
F_19 ( V_25 , V_186 , V_159 ) ;
F_19 ( V_25 , V_187 , V_159 ) ;
F_19 ( V_25 , V_188 , V_159 ) ;
F_19 ( V_25 , V_189 , V_159 ) ;
F_19 ( V_25 , V_190 , V_159 ) ;
F_19 ( V_25 , V_191 , V_159 ) ;
F_19 ( V_25 , V_192 , V_159 ) ;
F_19 ( V_25 , V_193 , V_159 ) ;
F_19 ( V_25 , V_194 , V_159 ) ;
F_19 ( V_25 , V_195 , V_159 ) ;
F_19 ( V_25 , V_196 , V_159 ) ;
F_19 ( V_25 , V_197 , V_159 ) ;
if ( V_33 -> V_37 == V_38 ) {
F_25 ( V_25 ) ;
F_19 ( V_25 , V_198 , 0 ) ;
}
return 0 ;
}
static bool F_38 ( struct V_32 * V_33 )
{
struct V_32 * V_199 ;
F_6 (a, &reset_list, list) {
if ( F_28 ( V_33 -> V_141 ) &&
V_33 -> V_141 == V_199 -> V_141 )
return true ;
}
return false ;
}
static int F_39 ( struct V_31 * V_25 )
{
struct V_32 * V_33 = F_12 ( V_25 ) ;
int V_20 , V_144 ;
F_40 ( & V_33 -> V_200 ) ;
V_33 -> V_25 = V_25 ;
V_20 = F_41 ( V_25 , 8 , 8 , V_33 -> V_201 ) ;
if ( V_20 != 0 ) {
F_42 ( V_25 -> V_202 , L_4 , V_20 ) ;
return V_20 ;
}
if ( F_28 ( V_33 -> V_141 ) &&
! F_38 ( V_33 ) ) {
V_20 = F_43 ( V_33 -> V_141 , L_5 ) ;
if ( V_20 != 0 )
goto V_203;
F_44 ( V_33 -> V_141 , 0 ) ;
}
for ( V_144 = 0 ; V_144 < F_14 ( V_33 -> V_145 ) ; V_144 ++ )
V_33 -> V_145 [ V_144 ] . V_204 = V_205 [ V_144 ] ;
V_20 = F_45 ( V_25 -> V_202 , F_14 ( V_33 -> V_145 ) ,
V_33 -> V_145 ) ;
if ( V_20 != 0 ) {
F_42 ( V_25 -> V_202 , L_6 , V_20 ) ;
goto V_206;
}
for ( V_144 = 0 ; V_144 < F_14 ( V_33 -> V_145 ) ; V_144 ++ ) {
V_33 -> V_139 [ V_144 ] . V_136 . V_207 = F_26 ;
V_33 -> V_139 [ V_144 ] . V_33 = V_33 ;
V_20 = F_46 ( V_33 -> V_145 [ V_144 ] . V_208 ,
& V_33 -> V_139 [ V_144 ] . V_136 ) ;
if ( V_20 ) {
F_42 ( V_25 -> V_202 ,
L_7 ,
V_20 ) ;
goto V_209;
}
}
V_25 -> V_147 = 1 ;
F_37 ( V_25 ) ;
if ( V_33 -> V_210 ) {
F_19 ( V_25 , V_211 ,
( V_33 -> V_210 -> V_212 [ 0 ] & 0xf ) << 4 ) ;
F_19 ( V_25 , V_213 ,
( V_33 -> V_210 -> V_212 [ 1 ] & 0xf ) << 4 ) ;
}
F_47 ( V_25 , V_214 ,
F_14 ( V_214 ) ) ;
if ( V_33 -> V_37 == V_38 )
F_47 ( V_25 , & V_215 , 1 ) ;
F_11 ( V_25 ) ;
F_48 ( & V_33 -> V_200 , & V_216 ) ;
return 0 ;
V_209:
while ( V_144 -- )
F_49 ( V_33 -> V_145 [ V_144 ] . V_208 ,
& V_33 -> V_139 [ V_144 ] . V_136 ) ;
F_50 ( F_14 ( V_33 -> V_145 ) , V_33 -> V_145 ) ;
V_206:
if ( F_28 ( V_33 -> V_141 ) &&
! F_38 ( V_33 ) )
F_51 ( V_33 -> V_141 ) ;
V_203:
return V_20 ;
}
static int F_52 ( struct V_31 * V_25 )
{
struct V_32 * V_33 = F_12 ( V_25 ) ;
int V_144 ;
F_34 ( V_25 , V_157 ) ;
F_53 ( & V_33 -> V_200 ) ;
if ( F_28 ( V_33 -> V_141 ) &&
! F_38 ( V_33 ) ) {
F_29 ( V_33 -> V_141 , 0 ) ;
F_51 ( V_33 -> V_141 ) ;
}
for ( V_144 = 0 ; V_144 < F_14 ( V_33 -> V_145 ) ; V_144 ++ )
F_49 ( V_33 -> V_145 [ V_144 ] . V_208 ,
& V_33 -> V_139 [ V_144 ] . V_136 ) ;
F_50 ( F_14 ( V_33 -> V_145 ) , V_33 -> V_145 ) ;
return 0 ;
}
static int F_54 ( struct V_217 * V_218 ,
const struct V_219 * V_220 )
{
struct V_221 * V_222 = V_218 -> V_202 . V_223 ;
struct V_32 * V_33 ;
int V_20 ;
V_33 = F_55 ( & V_218 -> V_202 , sizeof( struct V_32 ) , V_224 ) ;
if ( V_33 == NULL ) {
F_42 ( & V_218 -> V_202 , L_8 ) ;
return - V_225 ;
}
V_33 -> V_201 = V_226 ;
F_56 ( V_218 , V_33 ) ;
if ( V_222 ) {
V_33 -> V_141 = V_222 -> V_141 ;
V_33 -> V_210 = V_222 -> V_210 ;
} else {
V_33 -> V_141 = - 1 ;
}
V_33 -> V_37 = V_220 -> V_227 ;
V_20 = F_57 ( & V_218 -> V_202 ,
& V_228 , & V_229 , 1 ) ;
return V_20 ;
}
static int F_58 ( struct V_217 * V_230 )
{
F_59 ( & V_230 -> V_202 ) ;
return 0 ;
}
static int T_3 F_60 ( void )
{
int V_20 = 0 ;
V_20 = F_61 ( & V_231 ) ;
if ( V_20 != 0 ) {
F_21 ( V_82 L_9 ,
V_20 ) ;
}
return V_20 ;
}
static void T_4 F_62 ( void )
{
F_63 ( & V_231 ) ;
}
