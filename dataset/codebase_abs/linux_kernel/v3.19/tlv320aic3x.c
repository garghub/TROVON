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
static int F_19 ( struct V_42 * V_43 ,
struct V_46 * V_47 )
{
struct V_5 * V_6 = V_47 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_92 = 0 ;
if ( V_26 -> V_93 == V_94 )
V_92 += ( V_26 -> V_95 + 1 ) ;
else if ( V_26 -> V_93 == V_96 )
V_92 += V_26 -> V_95 ;
F_16 ( V_6 , V_97 , V_92 ) ;
return 0 ;
}
static int F_20 ( struct V_46 * V_47 , int V_98 )
{
struct V_5 * V_6 = V_47 -> V_6 ;
T_1 V_99 = F_14 ( V_6 , V_100 ) & ~ V_101 ;
T_1 V_102 = F_14 ( V_6 , V_103 ) & ~ V_101 ;
if ( V_98 ) {
F_16 ( V_6 , V_100 , V_99 | V_101 ) ;
F_16 ( V_6 , V_103 , V_102 | V_101 ) ;
} else {
F_16 ( V_6 , V_100 , V_99 ) ;
F_16 ( V_6 , V_103 , V_102 ) ;
}
return 0 ;
}
static int F_21 ( struct V_46 * V_104 ,
int V_105 , unsigned int V_106 , int V_107 )
{
struct V_5 * V_6 = V_104 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
F_8 ( V_6 , V_108 , V_109 ,
V_105 << V_110 ) ;
F_8 ( V_6 , V_108 , V_111 ,
V_105 << V_112 ) ;
V_26 -> V_64 = V_106 ;
return 0 ;
}
static int F_22 ( struct V_46 * V_104 ,
unsigned int V_113 )
{
struct V_5 * V_6 = V_104 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
T_1 V_114 , V_115 ;
V_114 = F_14 ( V_6 , V_116 ) & 0x3f ;
V_115 = F_14 ( V_6 , V_63 ) & 0x3f ;
switch ( V_113 & V_117 ) {
case V_118 :
V_26 -> V_119 = 1 ;
V_114 |= V_120 | V_121 ;
break;
case V_122 :
V_26 -> V_119 = 0 ;
V_114 &= ~ ( V_120 | V_121 ) ;
break;
default:
return - V_82 ;
}
switch ( V_113 & ( V_123 |
V_124 ) ) {
case ( V_125 | V_126 ) :
break;
case ( V_94 | V_127 ) :
case ( V_96 | V_127 ) :
V_115 |= ( 0x01 << 6 ) ;
break;
case ( V_128 | V_126 ) :
V_115 |= ( 0x02 << 6 ) ;
break;
case ( V_129 | V_126 ) :
V_115 |= ( 0x03 << 6 ) ;
break;
default:
return - V_82 ;
}
V_26 -> V_93 = V_113 & V_123 ;
F_16 ( V_6 , V_116 , V_114 ) ;
F_16 ( V_6 , V_63 , V_115 ) ;
return 0 ;
}
static int F_23 ( struct V_46 * V_104 ,
unsigned int V_130 , unsigned int V_131 ,
int V_132 , int V_133 )
{
struct V_5 * V_6 = V_104 -> V_6 ;
struct V_25 * V_26 = F_7 ( V_6 ) ;
unsigned int V_134 ;
if ( V_130 != V_131 ) {
F_24 ( V_6 -> V_135 , L_2 ) ;
return - V_82 ;
}
if ( F_25 ( ! V_130 ) ) {
F_24 ( V_6 -> V_135 , L_3 ) ;
return - V_82 ;
}
V_134 = F_26 ( V_130 ) ;
if ( ( V_134 + 1 ) != F_27 ( V_130 ) ) {
F_24 ( V_6 -> V_135 , L_4 ) ;
return - V_82 ;
}
V_26 -> V_95 = V_134 * V_133 ;
F_8 ( V_6 , V_116 ,
V_136 , V_136 ) ;
return 0 ;
}
static int F_28 ( struct V_137 * V_138 ,
unsigned long V_24 , void * V_52 )
{
struct V_139 * V_140 =
F_29 ( V_138 , struct V_139 , V_138 ) ;
struct V_25 * V_26 = V_140 -> V_26 ;
if ( V_24 & V_141 ) {
if ( F_30 ( V_26 -> V_142 ) )
F_31 ( V_26 -> V_142 , 0 ) ;
F_32 ( V_26 -> V_143 ) ;
}
return 0 ;
}
static int F_33 ( struct V_5 * V_6 , int V_144 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
unsigned int V_145 , V_61 ;
int V_146 ;
if ( V_144 ) {
V_146 = F_34 ( F_11 ( V_26 -> V_147 ) ,
V_26 -> V_147 ) ;
if ( V_146 )
goto V_148;
V_26 -> V_144 = 1 ;
if ( F_30 ( V_26 -> V_142 ) ) {
F_35 ( 1 ) ;
F_31 ( V_26 -> V_142 , 1 ) ;
}
F_36 ( V_26 -> V_143 , false ) ;
F_37 ( V_26 -> V_143 ) ;
V_145 = F_14 ( V_6 , V_88 ) ;
V_61 = F_14 ( V_6 , V_90 ) ;
if ( V_145 == V_149 [ V_88 ] . V_150 ||
V_61 == V_149 [ V_90 ] . V_150 ) {
F_16 ( V_6 , V_88 , V_145 ) ;
F_16 ( V_6 , V_90 , V_61 ) ;
}
} else {
F_16 ( V_6 , V_151 , V_152 ) ;
F_32 ( V_26 -> V_143 ) ;
V_26 -> V_144 = 0 ;
F_36 ( V_26 -> V_143 , true ) ;
V_146 = F_38 ( F_11 ( V_26 -> V_147 ) ,
V_26 -> V_147 ) ;
}
V_148:
return V_146 ;
}
static int F_39 ( struct V_5 * V_6 ,
enum V_153 V_154 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
switch ( V_154 ) {
case V_155 :
break;
case V_156 :
if ( V_6 -> V_21 . V_157 == V_158 &&
V_26 -> V_119 ) {
F_8 ( V_6 , V_65 ,
V_69 , V_69 ) ;
}
break;
case V_158 :
if ( ! V_26 -> V_144 )
F_33 ( V_6 , 1 ) ;
if ( V_6 -> V_21 . V_157 == V_156 &&
V_26 -> V_119 ) {
F_8 ( V_6 , V_65 ,
V_69 , 0 ) ;
}
break;
case V_159 :
if ( V_26 -> V_144 )
F_33 ( V_6 , 0 ) ;
break;
}
V_6 -> V_21 . V_157 = V_154 ;
return 0 ;
}
static void F_40 ( struct V_5 * V_6 )
{
F_16 ( V_6 , V_160 , V_161 | V_162 ) ;
F_16 ( V_6 , V_163 , V_161 | V_162 ) ;
F_8 ( V_6 , V_164 , V_165 , V_165 ) ;
F_16 ( V_6 , V_166 , V_161 ) ;
F_16 ( V_6 , V_167 , V_161 ) ;
F_16 ( V_6 , V_168 , V_161 ) ;
F_16 ( V_6 , V_169 , V_161 ) ;
}
static int F_41 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
F_16 ( V_6 , V_170 , V_171 ) ;
F_16 ( V_6 , V_151 , V_152 ) ;
F_16 ( V_6 , V_100 , V_161 | V_101 ) ;
F_16 ( V_6 , V_103 , V_161 | V_101 ) ;
F_16 ( V_6 , V_172 , V_161 | V_162 ) ;
F_16 ( V_6 , V_173 , V_161 | V_162 ) ;
F_16 ( V_6 , V_174 , V_161 | V_162 ) ;
F_16 ( V_6 , V_175 , V_161 | V_162 ) ;
F_16 ( V_6 , V_176 , V_161 | V_162 ) ;
F_16 ( V_6 , V_177 , V_161 | V_162 ) ;
F_8 ( V_6 , V_178 , V_165 , V_165 ) ;
F_8 ( V_6 , V_179 , V_165 , V_165 ) ;
F_8 ( V_6 , V_180 , V_165 , V_165 ) ;
F_8 ( V_6 , V_181 , V_165 , V_165 ) ;
F_8 ( V_6 , V_182 , V_165 , V_165 ) ;
F_8 ( V_6 , V_183 , V_165 , V_165 ) ;
F_16 ( V_6 , V_184 , V_185 ) ;
F_16 ( V_6 , V_186 , V_185 ) ;
F_16 ( V_6 , V_187 , 0x0 ) ;
F_16 ( V_6 , V_188 , 0x0 ) ;
F_16 ( V_6 , V_189 , V_161 ) ;
F_16 ( V_6 , V_190 , V_161 ) ;
F_16 ( V_6 , V_191 , V_161 ) ;
F_16 ( V_6 , V_192 , V_161 ) ;
F_16 ( V_6 , V_193 , V_161 ) ;
F_16 ( V_6 , V_194 , V_161 ) ;
F_16 ( V_6 , V_195 , V_161 ) ;
F_16 ( V_6 , V_196 , V_161 ) ;
F_16 ( V_6 , V_197 , V_161 ) ;
F_16 ( V_6 , V_198 , V_161 ) ;
F_16 ( V_6 , V_199 , V_161 ) ;
F_16 ( V_6 , V_200 , V_161 ) ;
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_40 ( V_6 ) ;
break;
case V_39 :
F_16 ( V_6 , V_201 , 0 ) ;
break;
}
return 0 ;
}
static bool F_42 ( struct V_25 * V_26 )
{
struct V_25 * V_202 ;
F_43 (a, &reset_list, list) {
if ( F_30 ( V_26 -> V_142 ) &&
V_26 -> V_142 == V_202 -> V_142 )
return true ;
}
return false ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_146 , V_203 ;
F_45 ( & V_26 -> V_204 ) ;
V_26 -> V_6 = V_6 ;
for ( V_203 = 0 ; V_203 < F_11 ( V_26 -> V_147 ) ; V_203 ++ ) {
V_26 -> V_140 [ V_203 ] . V_138 . V_205 = F_28 ;
V_26 -> V_140 [ V_203 ] . V_26 = V_26 ;
V_146 = F_46 ( V_26 -> V_147 [ V_203 ] . V_206 ,
& V_26 -> V_140 [ V_203 ] . V_138 ) ;
if ( V_146 ) {
F_24 ( V_6 -> V_135 ,
L_5 ,
V_146 ) ;
goto V_207;
}
}
F_32 ( V_26 -> V_143 ) ;
F_41 ( V_6 ) ;
if ( V_26 -> V_208 ) {
F_16 ( V_6 , V_209 ,
( V_26 -> V_208 -> V_210 [ 0 ] & 0xf ) << 4 ) ;
F_16 ( V_6 , V_211 ,
( V_26 -> V_208 -> V_210 [ 1 ] & 0xf ) << 4 ) ;
}
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_47 ( V_6 , V_212 ,
F_11 ( V_212 ) ) ;
break;
case V_39 :
F_47 ( V_6 ,
& V_213 , 1 ) ;
break;
}
switch ( V_26 -> V_30 ) {
case V_214 :
case V_215 :
case V_216 :
F_8 ( V_6 , V_28 ,
V_29 ,
( V_26 -> V_30 ) << V_31 ) ;
break;
case V_217 :
break;
}
F_9 ( V_6 ) ;
return 0 ;
V_207:
while ( V_203 -- )
F_48 ( V_26 -> V_147 [ V_203 ] . V_206 ,
& V_26 -> V_140 [ V_203 ] . V_138 ) ;
return V_146 ;
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_7 ( V_6 ) ;
int V_203 ;
F_50 ( & V_26 -> V_204 ) ;
for ( V_203 = 0 ; V_203 < F_11 ( V_26 -> V_147 ) ; V_203 ++ )
F_48 ( V_26 -> V_147 [ V_203 ] . V_206 ,
& V_26 -> V_140 [ V_203 ] . V_138 ) ;
return 0 ;
}
static int F_51 ( struct V_218 * V_219 ,
const struct V_220 * V_221 )
{
struct V_222 * V_223 = V_219 -> V_135 . V_224 ;
struct V_25 * V_26 ;
struct V_225 * V_226 ;
struct V_227 * V_228 = V_219 -> V_135 . V_229 ;
int V_146 , V_203 ;
T_3 V_20 ;
V_26 = F_52 ( & V_219 -> V_135 , sizeof( struct V_25 ) , V_230 ) ;
if ( ! V_26 )
return - V_231 ;
V_26 -> V_143 = F_53 ( V_219 , & V_232 ) ;
if ( F_54 ( V_26 -> V_143 ) ) {
V_146 = F_55 ( V_26 -> V_143 ) ;
return V_146 ;
}
F_36 ( V_26 -> V_143 , true ) ;
F_56 ( V_219 , V_26 ) ;
if ( V_223 ) {
V_26 -> V_142 = V_223 -> V_142 ;
V_26 -> V_208 = V_223 -> V_208 ;
V_26 -> V_30 = V_223 -> V_30 ;
} else if ( V_228 ) {
V_226 = F_52 ( & V_219 -> V_135 , sizeof( * V_226 ) ,
V_230 ) ;
if ( ! V_226 )
return - V_231 ;
V_146 = F_57 ( V_228 , L_6 , 0 ) ;
if ( V_146 >= 0 )
V_26 -> V_142 = V_146 ;
else
V_26 -> V_142 = - 1 ;
if ( F_58 ( V_228 , L_7 ,
V_226 -> V_210 , 2 ) >= 0 ) {
V_26 -> V_208 = V_226 ;
}
if ( ! F_59 ( V_228 , L_8 , & V_20 ) ) {
switch ( V_20 ) {
case 1 :
V_26 -> V_30 = V_214 ;
break;
case 2 :
V_26 -> V_30 = V_215 ;
break;
case 3 :
V_26 -> V_30 = V_216 ;
break;
default :
V_26 -> V_30 = V_217 ;
F_24 ( & V_219 -> V_135 , L_9
L_10 ) ;
}
} else {
V_26 -> V_30 = V_217 ;
}
} else {
V_26 -> V_142 = - 1 ;
}
V_26 -> V_34 = V_221 -> V_233 ;
if ( F_30 ( V_26 -> V_142 ) &&
! F_42 ( V_26 ) ) {
V_146 = F_60 ( V_26 -> V_142 , L_11 ) ;
if ( V_146 != 0 )
goto V_234;
F_61 ( V_26 -> V_142 , 0 ) ;
}
for ( V_203 = 0 ; V_203 < F_11 ( V_26 -> V_147 ) ; V_203 ++ )
V_26 -> V_147 [ V_203 ] . V_235 = V_236 [ V_203 ] ;
V_146 = F_62 ( & V_219 -> V_135 , F_11 ( V_26 -> V_147 ) ,
V_26 -> V_147 ) ;
if ( V_146 != 0 ) {
F_24 ( & V_219 -> V_135 , L_12 , V_146 ) ;
goto V_237;
}
if ( V_26 -> V_34 == V_39 ) {
V_146 = F_63 ( V_26 -> V_143 , V_238 ,
F_11 ( V_238 ) ) ;
if ( V_146 != 0 )
F_24 ( & V_219 -> V_135 , L_13 ,
V_146 ) ;
}
V_146 = F_64 ( & V_219 -> V_135 ,
& V_239 , & V_240 , 1 ) ;
if ( V_146 != 0 )
goto V_237;
F_65 ( & V_26 -> V_204 , & V_241 ) ;
return 0 ;
V_237:
if ( F_30 ( V_26 -> V_142 ) &&
! F_42 ( V_26 ) )
F_66 ( V_26 -> V_142 ) ;
V_234:
return V_146 ;
}
static int F_67 ( struct V_218 * V_242 )
{
struct V_25 * V_26 = F_68 ( V_242 ) ;
F_69 ( & V_242 -> V_135 ) ;
if ( F_30 ( V_26 -> V_142 ) &&
! F_42 ( V_26 ) ) {
F_31 ( V_26 -> V_142 , 0 ) ;
F_66 ( V_26 -> V_142 ) ;
}
return 0 ;
}
