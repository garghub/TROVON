static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 =
(struct V_7 * ) V_2 -> V_9 ;
unsigned int V_10 = V_8 -> V_10 ;
unsigned int V_11 = V_8 -> V_11 ;
int V_12 = V_8 -> V_12 ;
unsigned int V_13 = ( 1 << F_3 ( V_12 ) ) - 1 ;
unsigned int V_14 = V_8 -> V_14 ;
unsigned short V_15 ;
struct V_16 V_17 ;
int V_18 , V_19 ;
V_15 = ( V_4 -> V_20 . integer . V_20 [ 0 ] & V_13 ) ;
V_13 = 0xf ;
if ( V_15 )
V_15 = V_13 ;
V_18 = ! ! V_15 ;
if ( V_14 )
V_15 = V_13 - V_15 ;
V_13 <<= V_11 ;
V_15 <<= V_11 ;
V_19 = F_4 ( V_6 , V_10 , V_13 , V_15 ) ;
if ( V_19 ) {
V_17 . V_2 = V_2 ;
V_17 . V_10 = V_10 ;
V_17 . V_13 = V_13 ;
V_17 . V_15 = V_15 ;
F_5 ( & V_6 -> V_21 , V_2 , V_18 ,
& V_17 ) ;
}
return V_19 ;
}
static int F_6 ( struct V_22 * V_23 ,
struct V_1 * V_2 , int V_24 )
{
struct V_5 * V_6 = V_23 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
switch ( V_24 ) {
case V_27 :
F_8 ( V_6 , V_28 ,
V_29 ,
V_26 -> V_30 << V_31 ) ;
break;
case V_32 :
F_8 ( V_6 , V_28 ,
V_29 , 0 ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
struct V_33 * V_21 = & V_6 -> V_21 ;
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_10 ( V_21 , V_37 ,
F_11 ( V_37 ) ) ;
F_12 ( V_21 , V_38 ,
F_11 ( V_38 ) ) ;
break;
case V_39 :
F_10 ( V_21 , V_40 ,
F_11 ( V_40 ) ) ;
F_12 ( V_21 , V_41 ,
F_11 ( V_41 ) ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_5 * V_6 = V_47 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_48 = 0 , V_49 = 0 , V_50 , V_51 = 0 ;
T_1 V_52 , V_53 , V_54 , V_55 , V_56 , V_57 = 1 , V_58 = 1 , V_59 = 1 ;
T_2 V_60 , V_61 = 1 ;
int V_62 ;
V_52 = F_14 ( V_6 , V_63 ) & ( ~ ( 0x3 << 4 ) ) ;
switch ( F_15 ( V_45 ) ) {
case 16 :
break;
case 20 :
V_52 |= ( 0x01 << 4 ) ;
break;
case 24 :
V_52 |= ( 0x02 << 4 ) ;
break;
case 32 :
V_52 |= ( 0x03 << 4 ) ;
break;
}
F_16 ( V_6 , V_63 , V_52 ) ;
V_50 = ( F_17 ( V_45 ) % 11025 == 0 ) ? 44100 : 48000 ;
for ( V_56 = 2 ; V_56 < 18 ; V_56 ++ )
if ( V_26 -> V_64 / ( 128 * V_56 ) == V_50 ) {
V_49 = 1 ;
break;
}
if ( V_49 ) {
V_56 &= 0xf ;
F_16 ( V_6 , V_65 , V_56 << V_66 ) ;
F_16 ( V_6 , V_67 , V_68 ) ;
F_8 ( V_6 , V_65 , V_69 , 0 ) ;
} else {
F_16 ( V_6 , V_67 , V_70 ) ;
F_8 ( V_6 , V_65 ,
V_69 , V_69 ) ;
}
V_52 = ( V_71 | V_72 ) ;
V_52 |= ( V_50 == 44100 ) ? V_73 : V_74 ;
if ( F_17 ( V_45 ) >= 64000 )
V_52 |= V_75 ;
F_16 ( V_6 , V_76 , V_52 ) ;
V_52 = ( V_50 * 20 ) / F_17 ( V_45 ) ;
if ( F_17 ( V_45 ) < 64000 )
V_52 /= 2 ;
V_52 /= 5 ;
V_52 -= 2 ;
V_52 |= ( V_52 << 4 ) ;
F_16 ( V_6 , V_77 , V_52 ) ;
if ( V_49 )
return 0 ;
V_48 = ( 2048 * V_50 ) / ( V_26 -> V_64 / 1000 ) ;
for ( V_54 = 1 ; V_54 <= 16 ; V_54 ++ )
for ( V_55 = 1 ; V_55 <= 8 ; V_55 ++ ) {
for ( V_53 = 4 ; V_53 <= 55 ; V_53 ++ ) {
int V_78 = ( 1000 * V_53 * V_54 ) / V_55 ;
if ( abs ( V_48 - V_78 ) <
abs ( V_48 - V_51 ) ) {
V_59 = V_53 ; V_61 = 0 ;
V_58 = V_54 ; V_57 = V_55 ;
V_51 = V_78 ;
}
if ( V_78 == V_48 )
goto V_79;
}
}
for ( V_55 = 1 ; V_55 <= 8 ; V_55 ++ ) {
V_53 = V_48 * V_55 / 1000 ;
if ( V_53 < 4 || V_53 > 11 )
continue;
V_60 = ( ( 2048 * V_55 * V_50 ) - V_53 * V_26 -> V_64 )
* 100 / ( V_26 -> V_64 / 100 ) ;
V_62 = ( 10000 * V_53 + V_60 ) / ( 10 * V_55 ) ;
if ( abs ( V_48 - V_62 ) < abs ( V_48 - V_51 ) ) {
V_59 = V_53 ; V_61 = V_60 ; V_58 = 1 ; V_57 = V_55 ;
V_51 = V_62 ;
}
if ( V_62 == V_48 )
goto V_79;
}
if ( V_51 == 0 ) {
F_18 ( V_80 L_1 , V_81 ) ;
return - V_82 ;
}
V_79:
F_8 ( V_6 , V_65 , V_83 , V_57 ) ;
F_16 ( V_6 , V_84 ,
V_58 << V_85 ) ;
F_16 ( V_6 , V_86 , V_59 << V_87 ) ;
F_16 ( V_6 , V_88 ,
( V_61 >> 6 ) << V_89 ) ;
F_16 ( V_6 , V_90 ,
( V_61 & 0x3F ) << V_91 ) ;
return 0 ;
}
static int F_19 ( struct V_46 * V_47 , int V_92 )
{
struct V_5 * V_6 = V_47 -> V_6 ;
T_1 V_93 = F_14 ( V_6 , V_94 ) & ~ V_95 ;
T_1 V_96 = F_14 ( V_6 , V_97 ) & ~ V_95 ;
if ( V_92 ) {
F_16 ( V_6 , V_94 , V_93 | V_95 ) ;
F_16 ( V_6 , V_97 , V_96 | V_95 ) ;
} else {
F_16 ( V_6 , V_94 , V_93 ) ;
F_16 ( V_6 , V_97 , V_96 ) ;
}
return 0 ;
}
static int F_20 ( struct V_46 * V_98 ,
int V_99 , unsigned int V_100 , int V_101 )
{
struct V_5 * V_6 = V_98 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
F_8 ( V_6 , V_102 , V_103 ,
V_99 << V_104 ) ;
F_8 ( V_6 , V_102 , V_105 ,
V_99 << V_106 ) ;
V_26 -> V_64 = V_100 ;
return 0 ;
}
static int F_21 ( struct V_46 * V_98 ,
unsigned int V_107 )
{
struct V_5 * V_6 = V_98 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
T_1 V_108 , V_109 ;
int V_110 = 0 ;
V_108 = F_14 ( V_6 , V_111 ) & 0x3f ;
V_109 = F_14 ( V_6 , V_63 ) & 0x3f ;
switch ( V_107 & V_112 ) {
case V_113 :
V_26 -> V_114 = 1 ;
V_108 |= V_115 | V_116 ;
break;
case V_117 :
V_26 -> V_114 = 0 ;
V_108 &= ~ ( V_115 | V_116 ) ;
break;
default:
return - V_82 ;
}
switch ( V_107 & ( V_118 |
V_119 ) ) {
case ( V_120 | V_121 ) :
break;
case ( V_122 | V_123 ) :
V_110 = 1 ;
case ( V_124 | V_123 ) :
V_109 |= ( 0x01 << 6 ) ;
break;
case ( V_125 | V_121 ) :
V_109 |= ( 0x02 << 6 ) ;
break;
case ( V_126 | V_121 ) :
V_109 |= ( 0x03 << 6 ) ;
break;
default:
return - V_82 ;
}
F_16 ( V_6 , V_111 , V_108 ) ;
F_16 ( V_6 , V_63 , V_109 ) ;
F_16 ( V_6 , V_127 , V_110 ) ;
return 0 ;
}
static int F_22 ( struct V_128 * V_129 ,
unsigned long V_24 , void * V_52 )
{
struct V_130 * V_131 =
F_23 ( V_129 , struct V_130 , V_129 ) ;
struct V_25 * V_26 = V_131 -> V_26 ;
if ( V_24 & V_132 ) {
if ( F_24 ( V_26 -> V_133 ) )
F_25 ( V_26 -> V_133 , 0 ) ;
F_26 ( V_26 -> V_134 ) ;
}
return 0 ;
}
static int F_27 ( struct V_5 * V_6 , int V_135 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_136 ;
if ( V_135 ) {
V_136 = F_28 ( F_11 ( V_26 -> V_137 ) ,
V_26 -> V_137 ) ;
if ( V_136 )
goto V_138;
V_26 -> V_135 = 1 ;
if ( F_24 ( V_26 -> V_133 ) ) {
F_29 ( 1 ) ;
F_25 ( V_26 -> V_133 , 1 ) ;
}
F_30 ( V_26 -> V_134 , false ) ;
F_31 ( V_26 -> V_134 ) ;
} else {
F_16 ( V_6 , V_139 , V_140 ) ;
F_26 ( V_26 -> V_134 ) ;
V_26 -> V_135 = 0 ;
F_30 ( V_26 -> V_134 , true ) ;
V_136 = F_32 ( F_11 ( V_26 -> V_137 ) ,
V_26 -> V_137 ) ;
}
V_138:
return V_136 ;
}
static int F_33 ( struct V_5 * V_6 ,
enum V_141 V_142 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
switch ( V_142 ) {
case V_143 :
break;
case V_144 :
if ( V_6 -> V_21 . V_145 == V_146 &&
V_26 -> V_114 ) {
F_8 ( V_6 , V_65 ,
V_69 , V_69 ) ;
}
break;
case V_146 :
if ( ! V_26 -> V_135 )
F_27 ( V_6 , 1 ) ;
if ( V_6 -> V_21 . V_145 == V_144 &&
V_26 -> V_114 ) {
F_8 ( V_6 , V_65 ,
V_69 , 0 ) ;
}
break;
case V_147 :
if ( V_26 -> V_135 )
F_27 ( V_6 , 0 ) ;
break;
}
V_6 -> V_21 . V_145 = V_142 ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 )
{
F_33 ( V_6 , V_147 ) ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 )
{
F_33 ( V_6 , V_146 ) ;
return 0 ;
}
static void F_36 ( struct V_5 * V_6 )
{
F_16 ( V_6 , V_148 , V_149 | V_150 ) ;
F_16 ( V_6 , V_151 , V_149 | V_150 ) ;
F_8 ( V_6 , V_152 , V_153 , V_153 ) ;
F_16 ( V_6 , V_154 , V_149 ) ;
F_16 ( V_6 , V_155 , V_149 ) ;
F_16 ( V_6 , V_156 , V_149 ) ;
F_16 ( V_6 , V_157 , V_149 ) ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
F_16 ( V_6 , V_158 , V_159 ) ;
F_16 ( V_6 , V_139 , V_140 ) ;
F_16 ( V_6 , V_94 , V_149 | V_95 ) ;
F_16 ( V_6 , V_97 , V_149 | V_95 ) ;
F_16 ( V_6 , V_160 , V_149 | V_150 ) ;
F_16 ( V_6 , V_161 , V_149 | V_150 ) ;
F_16 ( V_6 , V_162 , V_149 | V_150 ) ;
F_16 ( V_6 , V_163 , V_149 | V_150 ) ;
F_16 ( V_6 , V_164 , V_149 | V_150 ) ;
F_16 ( V_6 , V_165 , V_149 | V_150 ) ;
F_8 ( V_6 , V_166 , V_153 , V_153 ) ;
F_8 ( V_6 , V_167 , V_153 , V_153 ) ;
F_8 ( V_6 , V_168 , V_153 , V_153 ) ;
F_8 ( V_6 , V_169 , V_153 , V_153 ) ;
F_8 ( V_6 , V_170 , V_153 , V_153 ) ;
F_8 ( V_6 , V_171 , V_153 , V_153 ) ;
F_16 ( V_6 , V_172 , V_173 ) ;
F_16 ( V_6 , V_174 , V_173 ) ;
F_16 ( V_6 , V_175 , 0x0 ) ;
F_16 ( V_6 , V_176 , 0x0 ) ;
F_16 ( V_6 , V_177 , V_149 ) ;
F_16 ( V_6 , V_178 , V_149 ) ;
F_16 ( V_6 , V_179 , V_149 ) ;
F_16 ( V_6 , V_180 , V_149 ) ;
F_16 ( V_6 , V_181 , V_149 ) ;
F_16 ( V_6 , V_182 , V_149 ) ;
F_16 ( V_6 , V_183 , V_149 ) ;
F_16 ( V_6 , V_184 , V_149 ) ;
F_16 ( V_6 , V_185 , V_149 ) ;
F_16 ( V_6 , V_186 , V_149 ) ;
F_16 ( V_6 , V_187 , V_149 ) ;
F_16 ( V_6 , V_188 , V_149 ) ;
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_36 ( V_6 ) ;
break;
case V_39 :
F_16 ( V_6 , V_189 , 0 ) ;
break;
}
return 0 ;
}
static bool F_38 ( struct V_25 * V_26 )
{
struct V_25 * V_190 ;
F_39 (a, &reset_list, list) {
if ( F_24 ( V_26 -> V_133 ) &&
V_26 -> V_133 == V_190 -> V_133 )
return true ;
}
return false ;
}
static int F_40 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_136 , V_191 ;
F_41 ( & V_26 -> V_192 ) ;
V_26 -> V_6 = V_6 ;
for ( V_191 = 0 ; V_191 < F_11 ( V_26 -> V_137 ) ; V_191 ++ ) {
V_26 -> V_131 [ V_191 ] . V_129 . V_193 = F_22 ;
V_26 -> V_131 [ V_191 ] . V_26 = V_26 ;
V_136 = F_42 ( V_26 -> V_137 [ V_191 ] . V_194 ,
& V_26 -> V_131 [ V_191 ] . V_129 ) ;
if ( V_136 ) {
F_43 ( V_6 -> V_195 ,
L_2 ,
V_136 ) ;
goto V_196;
}
}
F_26 ( V_26 -> V_134 ) ;
F_37 ( V_6 ) ;
if ( V_26 -> V_197 ) {
F_16 ( V_6 , V_198 ,
( V_26 -> V_197 -> V_199 [ 0 ] & 0xf ) << 4 ) ;
F_16 ( V_6 , V_200 ,
( V_26 -> V_197 -> V_199 [ 1 ] & 0xf ) << 4 ) ;
}
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_44 ( V_6 , V_201 ,
F_11 ( V_201 ) ) ;
break;
case V_39 :
F_44 ( V_6 ,
& V_202 , 1 ) ;
break;
}
switch ( V_26 -> V_30 ) {
case V_203 :
case V_204 :
case V_205 :
F_8 ( V_6 , V_28 ,
V_29 ,
( V_26 -> V_30 ) << V_31 ) ;
break;
case V_206 :
break;
}
F_9 ( V_6 ) ;
return 0 ;
V_196:
while ( V_191 -- )
F_45 ( V_26 -> V_137 [ V_191 ] . V_194 ,
& V_26 -> V_131 [ V_191 ] . V_129 ) ;
return V_136 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_191 ;
F_33 ( V_6 , V_147 ) ;
F_47 ( & V_26 -> V_192 ) ;
for ( V_191 = 0 ; V_191 < F_11 ( V_26 -> V_137 ) ; V_191 ++ )
F_45 ( V_26 -> V_137 [ V_191 ] . V_194 ,
& V_26 -> V_131 [ V_191 ] . V_129 ) ;
return 0 ;
}
static int F_48 ( struct V_207 * V_208 ,
const struct V_209 * V_210 )
{
struct V_211 * V_212 = V_208 -> V_195 . V_213 ;
struct V_25 * V_26 ;
struct V_214 * V_215 ;
struct V_216 * V_217 = V_208 -> V_195 . V_218 ;
int V_136 , V_191 ;
T_3 V_20 ;
V_26 = F_49 ( & V_208 -> V_195 , sizeof( struct V_25 ) , V_219 ) ;
if ( ! V_26 )
return - V_220 ;
V_26 -> V_134 = F_50 ( V_208 , & V_221 ) ;
if ( F_51 ( V_26 -> V_134 ) ) {
V_136 = F_52 ( V_26 -> V_134 ) ;
return V_136 ;
}
F_30 ( V_26 -> V_134 , true ) ;
F_53 ( V_208 , V_26 ) ;
if ( V_212 ) {
V_26 -> V_133 = V_212 -> V_133 ;
V_26 -> V_197 = V_212 -> V_197 ;
V_26 -> V_30 = V_212 -> V_30 ;
} else if ( V_217 ) {
V_215 = F_49 ( & V_208 -> V_195 , sizeof( * V_215 ) ,
V_219 ) ;
if ( ! V_215 )
return - V_220 ;
V_136 = F_54 ( V_217 , L_3 , 0 ) ;
if ( V_136 >= 0 )
V_26 -> V_133 = V_136 ;
else
V_26 -> V_133 = - 1 ;
if ( F_55 ( V_217 , L_4 ,
V_215 -> V_199 , 2 ) >= 0 ) {
V_26 -> V_197 = V_215 ;
}
if ( ! F_56 ( V_217 , L_5 , & V_20 ) ) {
switch ( V_20 ) {
case 1 :
V_26 -> V_30 = V_203 ;
break;
case 2 :
V_26 -> V_30 = V_204 ;
break;
case 3 :
V_26 -> V_30 = V_205 ;
break;
default :
V_26 -> V_30 = V_206 ;
F_43 ( & V_208 -> V_195 , L_6
L_7 ) ;
}
} else {
V_26 -> V_30 = V_206 ;
}
} else {
V_26 -> V_133 = - 1 ;
}
V_26 -> V_34 = V_210 -> V_222 ;
if ( F_24 ( V_26 -> V_133 ) &&
! F_38 ( V_26 ) ) {
V_136 = F_57 ( V_26 -> V_133 , L_8 ) ;
if ( V_136 != 0 )
goto V_223;
F_58 ( V_26 -> V_133 , 0 ) ;
}
for ( V_191 = 0 ; V_191 < F_11 ( V_26 -> V_137 ) ; V_191 ++ )
V_26 -> V_137 [ V_191 ] . V_224 = V_225 [ V_191 ] ;
V_136 = F_59 ( & V_208 -> V_195 , F_11 ( V_26 -> V_137 ) ,
V_26 -> V_137 ) ;
if ( V_136 != 0 ) {
F_43 ( & V_208 -> V_195 , L_9 , V_136 ) ;
goto V_226;
}
if ( V_26 -> V_34 == V_39 ) {
V_136 = F_60 ( V_26 -> V_134 , V_227 ,
F_11 ( V_227 ) ) ;
if ( V_136 != 0 )
F_43 ( & V_208 -> V_195 , L_10 ,
V_136 ) ;
}
V_136 = F_61 ( & V_208 -> V_195 ,
& V_228 , & V_229 , 1 ) ;
if ( V_136 != 0 )
goto V_226;
F_62 ( & V_26 -> V_192 , & V_230 ) ;
return 0 ;
V_226:
if ( F_24 ( V_26 -> V_133 ) &&
! F_38 ( V_26 ) )
F_63 ( V_26 -> V_133 ) ;
V_223:
return V_136 ;
}
static int F_64 ( struct V_207 * V_231 )
{
struct V_25 * V_26 = F_65 ( V_231 ) ;
F_66 ( & V_231 -> V_195 ) ;
if ( F_24 ( V_26 -> V_133 ) &&
! F_38 ( V_26 ) ) {
F_25 ( V_26 -> V_133 , 0 ) ;
F_63 ( V_26 -> V_133 ) ;
}
return 0 ;
}
