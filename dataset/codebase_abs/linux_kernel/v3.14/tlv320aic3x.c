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
V_19 = F_4 ( V_6 , V_15 , V_13 , V_10 ) ;
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
case V_64 :
break;
case V_65 :
V_52 |= ( 0x01 << 4 ) ;
break;
case V_66 :
V_52 |= ( 0x02 << 4 ) ;
break;
case V_67 :
V_52 |= ( 0x03 << 4 ) ;
break;
}
F_16 ( V_6 , V_63 , V_52 ) ;
V_50 = ( F_17 ( V_45 ) % 11025 == 0 ) ? 44100 : 48000 ;
for ( V_56 = 2 ; V_56 < 18 ; V_56 ++ )
if ( V_26 -> V_68 / ( 128 * V_56 ) == V_50 ) {
V_49 = 1 ;
break;
}
if ( V_49 ) {
V_56 &= 0xf ;
F_16 ( V_6 , V_69 , V_56 << V_70 ) ;
F_16 ( V_6 , V_71 , V_72 ) ;
F_8 ( V_6 , V_69 , V_73 , 0 ) ;
} else {
F_16 ( V_6 , V_71 , V_74 ) ;
F_8 ( V_6 , V_69 ,
V_73 , V_73 ) ;
}
V_52 = ( V_75 | V_76 ) ;
V_52 |= ( V_50 == 44100 ) ? V_77 : V_78 ;
if ( F_17 ( V_45 ) >= 64000 )
V_52 |= V_79 ;
F_16 ( V_6 , V_80 , V_52 ) ;
V_52 = ( V_50 * 20 ) / F_17 ( V_45 ) ;
if ( F_17 ( V_45 ) < 64000 )
V_52 /= 2 ;
V_52 /= 5 ;
V_52 -= 2 ;
V_52 |= ( V_52 << 4 ) ;
F_16 ( V_6 , V_81 , V_52 ) ;
if ( V_49 )
return 0 ;
V_48 = ( 2048 * V_50 ) / ( V_26 -> V_68 / 1000 ) ;
for ( V_54 = 1 ; V_54 <= 16 ; V_54 ++ )
for ( V_55 = 1 ; V_55 <= 8 ; V_55 ++ ) {
for ( V_53 = 4 ; V_53 <= 55 ; V_53 ++ ) {
int V_82 = ( 1000 * V_53 * V_54 ) / V_55 ;
if ( abs ( V_48 - V_82 ) <
abs ( V_48 - V_51 ) ) {
V_59 = V_53 ; V_61 = 0 ;
V_58 = V_54 ; V_57 = V_55 ;
V_51 = V_82 ;
}
if ( V_82 == V_48 )
goto V_83;
}
}
for ( V_55 = 1 ; V_55 <= 8 ; V_55 ++ ) {
V_53 = V_48 * V_55 / 1000 ;
if ( V_53 < 4 || V_53 > 11 )
continue;
V_60 = ( ( 2048 * V_55 * V_50 ) - V_53 * V_26 -> V_68 )
* 100 / ( V_26 -> V_68 / 100 ) ;
V_62 = ( 10000 * V_53 + V_60 ) / ( 10 * V_55 ) ;
if ( abs ( V_48 - V_62 ) < abs ( V_48 - V_51 ) ) {
V_59 = V_53 ; V_61 = V_60 ; V_58 = 1 ; V_57 = V_55 ;
V_51 = V_62 ;
}
if ( V_62 == V_48 )
goto V_83;
}
if ( V_51 == 0 ) {
F_18 ( V_84 L_1 , V_85 ) ;
return - V_86 ;
}
V_83:
F_8 ( V_6 , V_69 , V_87 , V_57 ) ;
F_16 ( V_6 , V_88 ,
V_58 << V_89 ) ;
F_16 ( V_6 , V_90 , V_59 << V_91 ) ;
F_16 ( V_6 , V_92 ,
( V_61 >> 6 ) << V_93 ) ;
F_16 ( V_6 , V_94 ,
( V_61 & 0x3F ) << V_95 ) ;
return 0 ;
}
static int F_19 ( struct V_46 * V_47 , int V_96 )
{
struct V_5 * V_6 = V_47 -> V_6 ;
T_1 V_97 = F_14 ( V_6 , V_98 ) & ~ V_99 ;
T_1 V_100 = F_14 ( V_6 , V_101 ) & ~ V_99 ;
if ( V_96 ) {
F_16 ( V_6 , V_98 , V_97 | V_99 ) ;
F_16 ( V_6 , V_101 , V_100 | V_99 ) ;
} else {
F_16 ( V_6 , V_98 , V_97 ) ;
F_16 ( V_6 , V_101 , V_100 ) ;
}
return 0 ;
}
static int F_20 ( struct V_46 * V_102 ,
int V_103 , unsigned int V_104 , int V_105 )
{
struct V_5 * V_6 = V_102 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
F_8 ( V_6 , V_106 , V_107 ,
V_103 << V_108 ) ;
F_8 ( V_6 , V_106 , V_109 ,
V_103 << V_110 ) ;
V_26 -> V_68 = V_104 ;
return 0 ;
}
static int F_21 ( struct V_46 * V_102 ,
unsigned int V_111 )
{
struct V_5 * V_6 = V_102 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
T_1 V_112 , V_113 ;
int V_114 = 0 ;
V_112 = F_14 ( V_6 , V_115 ) & 0x3f ;
V_113 = F_14 ( V_6 , V_63 ) & 0x3f ;
switch ( V_111 & V_116 ) {
case V_117 :
V_26 -> V_118 = 1 ;
V_112 |= V_119 | V_120 ;
break;
case V_121 :
V_26 -> V_118 = 0 ;
V_112 &= ~ ( V_119 | V_120 ) ;
break;
default:
return - V_86 ;
}
switch ( V_111 & ( V_122 |
V_123 ) ) {
case ( V_124 | V_125 ) :
break;
case ( V_126 | V_127 ) :
V_114 = 1 ;
case ( V_128 | V_127 ) :
V_113 |= ( 0x01 << 6 ) ;
break;
case ( V_129 | V_125 ) :
V_113 |= ( 0x02 << 6 ) ;
break;
case ( V_130 | V_125 ) :
V_113 |= ( 0x03 << 6 ) ;
break;
default:
return - V_86 ;
}
F_16 ( V_6 , V_115 , V_112 ) ;
F_16 ( V_6 , V_63 , V_113 ) ;
F_16 ( V_6 , V_131 , V_114 ) ;
return 0 ;
}
static int F_22 ( struct V_132 * V_133 ,
unsigned long V_24 , void * V_52 )
{
struct V_134 * V_135 =
F_23 ( V_133 , struct V_134 , V_133 ) ;
struct V_25 * V_26 = V_135 -> V_26 ;
if ( V_24 & V_136 ) {
if ( F_24 ( V_26 -> V_137 ) )
F_25 ( V_26 -> V_137 , 0 ) ;
F_26 ( V_26 -> V_138 ) ;
}
return 0 ;
}
static int F_27 ( struct V_5 * V_6 , int V_139 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_140 ;
if ( V_139 ) {
V_140 = F_28 ( F_11 ( V_26 -> V_141 ) ,
V_26 -> V_141 ) ;
if ( V_140 )
goto V_142;
V_26 -> V_139 = 1 ;
if ( F_24 ( V_26 -> V_137 ) ) {
F_29 ( 1 ) ;
F_25 ( V_26 -> V_137 , 1 ) ;
}
F_30 ( V_26 -> V_138 , false ) ;
F_31 ( V_26 -> V_138 ) ;
} else {
F_16 ( V_6 , V_143 , V_144 ) ;
F_26 ( V_26 -> V_138 ) ;
V_26 -> V_139 = 0 ;
F_30 ( V_26 -> V_138 , true ) ;
V_140 = F_32 ( F_11 ( V_26 -> V_141 ) ,
V_26 -> V_141 ) ;
}
V_142:
return V_140 ;
}
static int F_33 ( struct V_5 * V_6 ,
enum V_145 V_146 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
switch ( V_146 ) {
case V_147 :
break;
case V_148 :
if ( V_6 -> V_21 . V_149 == V_150 &&
V_26 -> V_118 ) {
F_8 ( V_6 , V_69 ,
V_73 , V_73 ) ;
}
break;
case V_150 :
if ( ! V_26 -> V_139 )
F_27 ( V_6 , 1 ) ;
if ( V_6 -> V_21 . V_149 == V_148 &&
V_26 -> V_118 ) {
F_8 ( V_6 , V_69 ,
V_73 , 0 ) ;
}
break;
case V_151 :
if ( V_26 -> V_139 )
F_27 ( V_6 , 0 ) ;
break;
}
V_6 -> V_21 . V_149 = V_146 ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 )
{
F_33 ( V_6 , V_151 ) ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 )
{
F_33 ( V_6 , V_150 ) ;
return 0 ;
}
static void F_36 ( struct V_5 * V_6 )
{
F_16 ( V_6 , V_152 , V_153 | V_154 ) ;
F_16 ( V_6 , V_155 , V_153 | V_154 ) ;
F_8 ( V_6 , V_156 , V_157 , V_157 ) ;
F_16 ( V_6 , V_158 , V_153 ) ;
F_16 ( V_6 , V_159 , V_153 ) ;
F_16 ( V_6 , V_160 , V_153 ) ;
F_16 ( V_6 , V_161 , V_153 ) ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
F_16 ( V_6 , V_162 , V_163 ) ;
F_16 ( V_6 , V_143 , V_144 ) ;
F_16 ( V_6 , V_98 , V_153 | V_99 ) ;
F_16 ( V_6 , V_101 , V_153 | V_99 ) ;
F_16 ( V_6 , V_164 , V_153 | V_154 ) ;
F_16 ( V_6 , V_165 , V_153 | V_154 ) ;
F_16 ( V_6 , V_166 , V_153 | V_154 ) ;
F_16 ( V_6 , V_167 , V_153 | V_154 ) ;
F_16 ( V_6 , V_168 , V_153 | V_154 ) ;
F_16 ( V_6 , V_169 , V_153 | V_154 ) ;
F_8 ( V_6 , V_170 , V_157 , V_157 ) ;
F_8 ( V_6 , V_171 , V_157 , V_157 ) ;
F_8 ( V_6 , V_172 , V_157 , V_157 ) ;
F_8 ( V_6 , V_173 , V_157 , V_157 ) ;
F_8 ( V_6 , V_174 , V_157 , V_157 ) ;
F_8 ( V_6 , V_175 , V_157 , V_157 ) ;
F_16 ( V_6 , V_176 , V_177 ) ;
F_16 ( V_6 , V_178 , V_177 ) ;
F_16 ( V_6 , V_179 , 0x0 ) ;
F_16 ( V_6 , V_180 , 0x0 ) ;
F_16 ( V_6 , V_181 , V_153 ) ;
F_16 ( V_6 , V_182 , V_153 ) ;
F_16 ( V_6 , V_183 , V_153 ) ;
F_16 ( V_6 , V_184 , V_153 ) ;
F_16 ( V_6 , V_185 , V_153 ) ;
F_16 ( V_6 , V_186 , V_153 ) ;
F_16 ( V_6 , V_187 , V_153 ) ;
F_16 ( V_6 , V_188 , V_153 ) ;
F_16 ( V_6 , V_189 , V_153 ) ;
F_16 ( V_6 , V_190 , V_153 ) ;
F_16 ( V_6 , V_191 , V_153 ) ;
F_16 ( V_6 , V_192 , V_153 ) ;
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_36 ( V_6 ) ;
break;
case V_39 :
F_16 ( V_6 , V_193 , 0 ) ;
break;
}
return 0 ;
}
static bool F_38 ( struct V_25 * V_26 )
{
struct V_25 * V_194 ;
F_39 (a, &reset_list, list) {
if ( F_24 ( V_26 -> V_137 ) &&
V_26 -> V_137 == V_194 -> V_137 )
return true ;
}
return false ;
}
static int F_40 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_140 , V_195 ;
F_41 ( & V_26 -> V_196 ) ;
V_26 -> V_6 = V_6 ;
V_140 = F_42 ( V_6 , 8 , 8 , V_197 ) ;
if ( V_140 != 0 ) {
F_43 ( V_6 -> V_198 , L_2 , V_140 ) ;
return V_140 ;
}
for ( V_195 = 0 ; V_195 < F_11 ( V_26 -> V_141 ) ; V_195 ++ ) {
V_26 -> V_135 [ V_195 ] . V_133 . V_199 = F_22 ;
V_26 -> V_135 [ V_195 ] . V_26 = V_26 ;
V_140 = F_44 ( V_26 -> V_141 [ V_195 ] . V_200 ,
& V_26 -> V_135 [ V_195 ] . V_133 ) ;
if ( V_140 ) {
F_43 ( V_6 -> V_198 ,
L_3 ,
V_140 ) ;
goto V_201;
}
}
F_26 ( V_26 -> V_138 ) ;
F_37 ( V_6 ) ;
if ( V_26 -> V_202 ) {
F_16 ( V_6 , V_203 ,
( V_26 -> V_202 -> V_204 [ 0 ] & 0xf ) << 4 ) ;
F_16 ( V_6 , V_205 ,
( V_26 -> V_202 -> V_204 [ 1 ] & 0xf ) << 4 ) ;
}
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_45 ( V_6 , V_206 ,
F_11 ( V_206 ) ) ;
break;
case V_39 :
F_45 ( V_6 ,
& V_207 , 1 ) ;
break;
}
switch ( V_26 -> V_30 ) {
case V_208 :
case V_209 :
case V_210 :
F_8 ( V_6 , V_28 ,
V_29 ,
( V_26 -> V_30 ) << V_31 ) ;
break;
case V_211 :
break;
}
F_9 ( V_6 ) ;
F_46 ( & V_26 -> V_196 , & V_212 ) ;
return 0 ;
V_201:
while ( V_195 -- )
F_47 ( V_26 -> V_141 [ V_195 ] . V_200 ,
& V_26 -> V_135 [ V_195 ] . V_133 ) ;
return V_140 ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_195 ;
F_33 ( V_6 , V_151 ) ;
F_49 ( & V_26 -> V_196 ) ;
for ( V_195 = 0 ; V_195 < F_11 ( V_26 -> V_141 ) ; V_195 ++ )
F_47 ( V_26 -> V_141 [ V_195 ] . V_200 ,
& V_26 -> V_135 [ V_195 ] . V_133 ) ;
return 0 ;
}
static int F_50 ( struct V_213 * V_214 ,
const struct V_215 * V_216 )
{
struct V_217 * V_218 = V_214 -> V_198 . V_219 ;
struct V_25 * V_26 ;
struct V_220 * V_221 ;
struct V_222 * V_223 = V_214 -> V_198 . V_224 ;
int V_140 , V_195 ;
T_3 V_20 ;
V_26 = F_51 ( & V_214 -> V_198 , sizeof( struct V_25 ) , V_225 ) ;
if ( V_26 == NULL ) {
F_43 ( & V_214 -> V_198 , L_4 ) ;
return - V_226 ;
}
V_26 -> V_138 = F_52 ( V_214 , & V_227 ) ;
if ( F_53 ( V_26 -> V_138 ) ) {
V_140 = F_54 ( V_26 -> V_138 ) ;
return V_140 ;
}
F_30 ( V_26 -> V_138 , true ) ;
F_55 ( V_214 , V_26 ) ;
if ( V_218 ) {
V_26 -> V_137 = V_218 -> V_137 ;
V_26 -> V_202 = V_218 -> V_202 ;
V_26 -> V_30 = V_218 -> V_30 ;
} else if ( V_223 ) {
V_221 = F_51 ( & V_214 -> V_198 , sizeof( * V_221 ) ,
V_225 ) ;
if ( V_221 == NULL ) {
F_43 ( & V_214 -> V_198 , L_4 ) ;
return - V_226 ;
}
V_140 = F_56 ( V_223 , L_5 , 0 ) ;
if ( V_140 >= 0 )
V_26 -> V_137 = V_140 ;
else
V_26 -> V_137 = - 1 ;
if ( F_57 ( V_223 , L_6 ,
V_221 -> V_204 , 2 ) >= 0 ) {
V_26 -> V_202 = V_221 ;
}
if ( ! F_58 ( V_223 , L_7 , & V_20 ) ) {
switch ( V_20 ) {
case 1 :
V_26 -> V_30 = V_208 ;
break;
case 2 :
V_26 -> V_30 = V_209 ;
break;
case 3 :
V_26 -> V_30 = V_210 ;
break;
default :
V_26 -> V_30 = V_211 ;
F_43 ( & V_214 -> V_198 , L_8
L_9 ) ;
}
} else {
V_26 -> V_30 = V_211 ;
}
} else {
V_26 -> V_137 = - 1 ;
}
V_26 -> V_34 = V_216 -> V_228 ;
if ( F_24 ( V_26 -> V_137 ) &&
! F_38 ( V_26 ) ) {
V_140 = F_59 ( V_26 -> V_137 , L_10 ) ;
if ( V_140 != 0 )
goto V_229;
F_60 ( V_26 -> V_137 , 0 ) ;
}
for ( V_195 = 0 ; V_195 < F_11 ( V_26 -> V_141 ) ; V_195 ++ )
V_26 -> V_141 [ V_195 ] . V_230 = V_231 [ V_195 ] ;
V_140 = F_61 ( & V_214 -> V_198 , F_11 ( V_26 -> V_141 ) ,
V_26 -> V_141 ) ;
if ( V_140 != 0 ) {
F_43 ( & V_214 -> V_198 , L_11 , V_140 ) ;
goto V_232;
}
if ( V_26 -> V_34 == V_39 ) {
V_140 = F_62 ( V_26 -> V_138 , V_233 ,
F_11 ( V_233 ) ) ;
if ( V_140 != 0 )
F_43 ( & V_214 -> V_198 , L_12 ,
V_140 ) ;
}
V_140 = F_63 ( & V_214 -> V_198 ,
& V_234 , & V_235 , 1 ) ;
return V_140 ;
V_232:
if ( F_24 ( V_26 -> V_137 ) &&
! F_38 ( V_26 ) )
F_64 ( V_26 -> V_137 ) ;
V_229:
return V_140 ;
}
static int F_65 ( struct V_213 * V_236 )
{
struct V_25 * V_26 = F_66 ( V_236 ) ;
F_67 ( & V_236 -> V_198 ) ;
if ( F_24 ( V_26 -> V_137 ) &&
! F_38 ( V_26 ) ) {
F_25 ( V_26 -> V_137 , 0 ) ;
F_64 ( V_26 -> V_137 ) ;
}
return 0 ;
}
