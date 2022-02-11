static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_2 -> V_11 ;
unsigned int V_12 = V_10 -> V_12 ;
unsigned int V_13 = V_10 -> V_13 ;
int V_14 = V_10 -> V_14 ;
unsigned int V_15 = ( 1 << F_4 ( V_14 ) ) - 1 ;
unsigned int V_16 = V_10 -> V_16 ;
unsigned short V_17 ;
struct V_18 V_19 ;
int V_20 , V_21 ;
V_17 = ( V_4 -> V_22 . integer . V_22 [ 0 ] & V_15 ) ;
V_15 = 0xf ;
if ( V_17 )
V_17 = V_15 ;
V_20 = ! ! V_17 ;
if ( V_16 )
V_17 = V_15 - V_17 ;
V_15 <<= V_13 ;
V_17 <<= V_13 ;
V_21 = F_5 ( V_6 , V_12 , V_15 , V_17 ) ;
if ( V_21 ) {
V_19 . V_2 = V_2 ;
V_19 . V_12 = V_12 ;
V_19 . V_15 = V_15 ;
V_19 . V_17 = V_17 ;
F_6 ( V_8 , V_2 , V_20 ,
& V_19 ) ;
}
return V_21 ;
}
static int F_7 ( struct V_23 * V_24 ,
struct V_1 * V_2 , int V_25 )
{
struct V_5 * V_6 = F_8 ( V_24 -> V_8 ) ;
struct V_26 * V_27 = F_9 ( V_6 ) ;
switch ( V_25 ) {
case V_28 :
F_10 ( V_6 , V_29 ,
V_30 ,
V_27 -> V_31 << V_32 ) ;
break;
case V_33 :
F_10 ( V_6 , V_29 ,
V_30 , 0 ) ;
break;
}
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = F_9 ( V_6 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_27 -> V_34 ) {
case V_35 :
case V_36 :
F_12 ( V_8 , V_37 ,
F_13 ( V_37 ) ) ;
F_14 ( V_8 , V_38 ,
F_13 ( V_38 ) ) ;
F_12 ( V_8 , V_39 ,
F_13 ( V_39 ) ) ;
F_14 ( V_8 , V_40 ,
F_13 ( V_40 ) ) ;
break;
case V_41 :
F_12 ( V_8 , V_37 ,
F_13 ( V_37 ) ) ;
F_14 ( V_8 , V_38 ,
F_13 ( V_38 ) ) ;
F_12 ( V_8 , V_42 ,
F_13 ( V_42 ) ) ;
F_14 ( V_8 , V_43 ,
F_13 ( V_43 ) ) ;
break;
case V_44 :
F_12 ( V_8 , V_45 ,
F_13 ( V_45 ) ) ;
F_14 ( V_8 , V_46 ,
F_13 ( V_46 ) ) ;
break;
}
return 0 ;
}
static int F_15 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_26 * V_27 = F_9 ( V_6 ) ;
int V_53 = 0 , V_54 = 0 , V_55 , V_56 = 0 ;
T_1 V_57 , V_58 , V_59 , V_60 , V_61 , V_62 = 1 , V_63 = 1 , V_64 = 1 ;
T_2 V_65 , V_66 = 1 ;
int V_67 ;
V_57 = F_16 ( V_6 , V_68 ) & ( ~ ( 0x3 << 4 ) ) ;
switch ( F_17 ( V_50 ) ) {
case 16 :
break;
case 20 :
V_57 |= ( 0x01 << 4 ) ;
break;
case 24 :
V_57 |= ( 0x02 << 4 ) ;
break;
case 32 :
V_57 |= ( 0x03 << 4 ) ;
break;
}
F_18 ( V_6 , V_68 , V_57 ) ;
V_55 = ( F_19 ( V_50 ) % 11025 == 0 ) ? 44100 : 48000 ;
for ( V_61 = 2 ; V_61 < 18 ; V_61 ++ )
if ( V_27 -> V_69 / ( 128 * V_61 ) == V_55 ) {
V_54 = 1 ;
break;
}
if ( V_54 ) {
V_61 &= 0xf ;
F_18 ( V_6 , V_70 , V_61 << V_71 ) ;
F_18 ( V_6 , V_72 , V_73 ) ;
F_10 ( V_6 , V_70 , V_74 , 0 ) ;
} else {
F_18 ( V_6 , V_72 , V_75 ) ;
F_10 ( V_6 , V_70 ,
V_74 , V_74 ) ;
}
V_57 = ( V_76 | V_77 ) ;
V_57 |= ( V_55 == 44100 ) ? V_78 : V_79 ;
if ( F_19 ( V_50 ) >= 64000 )
V_57 |= V_80 ;
F_18 ( V_6 , V_81 , V_57 ) ;
V_57 = ( V_55 * 20 ) / F_19 ( V_50 ) ;
if ( F_19 ( V_50 ) < 64000 )
V_57 /= 2 ;
V_57 /= 5 ;
V_57 -= 2 ;
V_57 |= ( V_57 << 4 ) ;
F_18 ( V_6 , V_82 , V_57 ) ;
if ( V_54 )
return 0 ;
V_53 = ( 2048 * V_55 ) / ( V_27 -> V_69 / 1000 ) ;
for ( V_59 = 1 ; V_59 <= 16 ; V_59 ++ )
for ( V_60 = 1 ; V_60 <= 8 ; V_60 ++ ) {
for ( V_58 = 4 ; V_58 <= 55 ; V_58 ++ ) {
int V_83 = ( 1000 * V_58 * V_59 ) / V_60 ;
if ( abs ( V_53 - V_83 ) <
abs ( V_53 - V_56 ) ) {
V_64 = V_58 ; V_66 = 0 ;
V_63 = V_59 ; V_62 = V_60 ;
V_56 = V_83 ;
}
if ( V_83 == V_53 )
goto V_84;
}
}
for ( V_60 = 1 ; V_60 <= 8 ; V_60 ++ ) {
V_58 = V_53 * V_60 / 1000 ;
if ( V_58 < 4 || V_58 > 11 )
continue;
V_65 = ( ( 2048 * V_60 * V_55 ) - V_58 * V_27 -> V_69 )
* 100 / ( V_27 -> V_69 / 100 ) ;
V_67 = ( 10000 * V_58 + V_65 ) / ( 10 * V_60 ) ;
if ( abs ( V_53 - V_67 ) < abs ( V_53 - V_56 ) ) {
V_64 = V_58 ; V_66 = V_65 ; V_63 = 1 ; V_62 = V_60 ;
V_56 = V_67 ;
}
if ( V_67 == V_53 )
goto V_84;
}
if ( V_56 == 0 ) {
F_20 ( V_85 L_1 , V_86 ) ;
return - V_87 ;
}
V_84:
F_10 ( V_6 , V_70 , V_88 , V_62 ) ;
F_18 ( V_6 , V_89 ,
V_63 << V_90 ) ;
F_18 ( V_6 , V_91 , V_64 << V_92 ) ;
F_18 ( V_6 , V_93 ,
( V_66 >> 6 ) << V_94 ) ;
F_18 ( V_6 , V_95 ,
( V_66 & 0x3F ) << V_96 ) ;
return 0 ;
}
static int F_21 ( struct V_47 * V_48 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_26 * V_27 = F_9 ( V_6 ) ;
int V_97 = 0 ;
if ( V_27 -> V_98 == V_99 )
V_97 += ( V_27 -> V_100 + 1 ) ;
else if ( V_27 -> V_98 == V_101 )
V_97 += V_27 -> V_100 ;
F_18 ( V_6 , V_102 , V_97 ) ;
return 0 ;
}
static int F_22 ( struct V_51 * V_52 , int V_103 )
{
struct V_5 * V_6 = V_52 -> V_6 ;
T_1 V_104 = F_16 ( V_6 , V_105 ) & ~ V_106 ;
T_1 V_107 = F_16 ( V_6 , V_108 ) & ~ V_106 ;
if ( V_103 ) {
F_18 ( V_6 , V_105 , V_104 | V_106 ) ;
F_18 ( V_6 , V_108 , V_107 | V_106 ) ;
} else {
F_18 ( V_6 , V_105 , V_104 ) ;
F_18 ( V_6 , V_108 , V_107 ) ;
}
return 0 ;
}
static int F_23 ( struct V_51 * V_109 ,
int V_110 , unsigned int V_111 , int V_112 )
{
struct V_5 * V_6 = V_109 -> V_6 ;
struct V_26 * V_27 = F_9 ( V_6 ) ;
F_10 ( V_6 , V_113 , V_114 ,
V_110 << V_115 ) ;
F_10 ( V_6 , V_113 , V_116 ,
V_110 << V_117 ) ;
V_27 -> V_69 = V_111 ;
return 0 ;
}
static int F_24 ( struct V_51 * V_109 ,
unsigned int V_118 )
{
struct V_5 * V_6 = V_109 -> V_6 ;
struct V_26 * V_27 = F_9 ( V_6 ) ;
T_1 V_119 , V_120 ;
V_119 = F_16 ( V_6 , V_121 ) & 0x3f ;
V_120 = F_16 ( V_6 , V_68 ) & 0x3f ;
switch ( V_118 & V_122 ) {
case V_123 :
V_27 -> V_124 = 1 ;
V_119 |= V_125 | V_126 ;
break;
case V_127 :
V_27 -> V_124 = 0 ;
V_119 &= ~ ( V_125 | V_126 ) ;
break;
default:
return - V_87 ;
}
switch ( V_118 & ( V_128 |
V_129 ) ) {
case ( V_130 | V_131 ) :
break;
case ( V_99 | V_132 ) :
case ( V_101 | V_132 ) :
V_120 |= ( 0x01 << 6 ) ;
break;
case ( V_133 | V_131 ) :
V_120 |= ( 0x02 << 6 ) ;
break;
case ( V_134 | V_131 ) :
V_120 |= ( 0x03 << 6 ) ;
break;
default:
return - V_87 ;
}
V_27 -> V_98 = V_118 & V_128 ;
F_18 ( V_6 , V_121 , V_119 ) ;
F_18 ( V_6 , V_68 , V_120 ) ;
return 0 ;
}
static int F_25 ( struct V_51 * V_109 ,
unsigned int V_135 , unsigned int V_136 ,
int V_137 , int V_138 )
{
struct V_5 * V_6 = V_109 -> V_6 ;
struct V_26 * V_27 = F_9 ( V_6 ) ;
unsigned int V_139 ;
if ( V_135 != V_136 ) {
F_26 ( V_6 -> V_140 , L_2 ) ;
return - V_87 ;
}
if ( F_27 ( ! V_135 ) ) {
F_26 ( V_6 -> V_140 , L_3 ) ;
return - V_87 ;
}
V_139 = F_28 ( V_135 ) ;
if ( ( V_139 + 1 ) != F_29 ( V_135 ) ) {
F_26 ( V_6 -> V_140 , L_4 ) ;
return - V_87 ;
}
V_27 -> V_100 = V_139 * V_138 ;
F_10 ( V_6 , V_121 ,
V_141 , V_141 ) ;
return 0 ;
}
static int F_30 ( struct V_142 * V_143 ,
unsigned long V_25 , void * V_57 )
{
struct V_144 * V_145 =
F_31 ( V_143 , struct V_144 , V_143 ) ;
struct V_26 * V_27 = V_145 -> V_27 ;
if ( V_25 & V_146 ) {
if ( F_32 ( V_27 -> V_147 ) )
F_33 ( V_27 -> V_147 , 0 ) ;
F_34 ( V_27 -> V_148 ) ;
}
return 0 ;
}
static int F_35 ( struct V_5 * V_6 , int V_149 )
{
struct V_26 * V_27 = F_9 ( V_6 ) ;
unsigned int V_150 , V_66 ;
int V_151 ;
if ( V_149 ) {
V_151 = F_36 ( F_13 ( V_27 -> V_152 ) ,
V_27 -> V_152 ) ;
if ( V_151 )
goto V_153;
V_27 -> V_149 = 1 ;
if ( F_32 ( V_27 -> V_147 ) ) {
F_37 ( 1 ) ;
F_33 ( V_27 -> V_147 , 1 ) ;
}
F_38 ( V_27 -> V_148 , false ) ;
F_39 ( V_27 -> V_148 ) ;
V_150 = F_16 ( V_6 , V_93 ) ;
V_66 = F_16 ( V_6 , V_95 ) ;
if ( V_150 == V_154 [ V_93 ] . V_155 ||
V_66 == V_154 [ V_95 ] . V_155 ) {
F_18 ( V_6 , V_93 , V_150 ) ;
F_18 ( V_6 , V_95 , V_66 ) ;
}
} else {
F_18 ( V_6 , V_156 , V_157 ) ;
F_34 ( V_27 -> V_148 ) ;
V_27 -> V_149 = 0 ;
F_38 ( V_27 -> V_148 , true ) ;
V_151 = F_40 ( F_13 ( V_27 -> V_152 ) ,
V_27 -> V_152 ) ;
}
V_153:
return V_151 ;
}
static int F_41 ( struct V_5 * V_6 ,
enum V_158 V_159 )
{
struct V_26 * V_27 = F_9 ( V_6 ) ;
switch ( V_159 ) {
case V_160 :
break;
case V_161 :
if ( F_42 ( V_6 ) == V_162 &&
V_27 -> V_124 ) {
F_10 ( V_6 , V_70 ,
V_74 , V_74 ) ;
}
break;
case V_162 :
if ( ! V_27 -> V_149 )
F_35 ( V_6 , 1 ) ;
if ( F_42 ( V_6 ) == V_161 &&
V_27 -> V_124 ) {
F_10 ( V_6 , V_70 ,
V_74 , 0 ) ;
}
break;
case V_163 :
if ( V_27 -> V_149 )
F_35 ( V_6 , 0 ) ;
break;
}
return 0 ;
}
static void F_43 ( struct V_5 * V_6 )
{
F_18 ( V_6 , V_164 , V_165 | V_166 ) ;
F_18 ( V_6 , V_167 , V_165 | V_166 ) ;
F_10 ( V_6 , V_168 , V_169 , V_169 ) ;
F_18 ( V_6 , V_170 , V_165 ) ;
F_18 ( V_6 , V_171 , V_165 ) ;
F_18 ( V_6 , V_172 , V_165 ) ;
F_18 ( V_6 , V_173 , V_165 ) ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = F_9 ( V_6 ) ;
F_18 ( V_6 , V_174 , V_175 ) ;
F_18 ( V_6 , V_156 , V_157 ) ;
F_18 ( V_6 , V_105 , V_165 | V_106 ) ;
F_18 ( V_6 , V_108 , V_165 | V_106 ) ;
F_18 ( V_6 , V_176 , V_165 | V_166 ) ;
F_18 ( V_6 , V_177 , V_165 | V_166 ) ;
F_18 ( V_6 , V_178 , V_165 | V_166 ) ;
F_18 ( V_6 , V_179 , V_165 | V_166 ) ;
F_18 ( V_6 , V_180 , V_165 | V_166 ) ;
F_18 ( V_6 , V_181 , V_165 | V_166 ) ;
F_10 ( V_6 , V_182 , V_169 , V_169 ) ;
F_10 ( V_6 , V_183 , V_169 , V_169 ) ;
F_10 ( V_6 , V_184 , V_169 , V_169 ) ;
F_10 ( V_6 , V_185 , V_169 , V_169 ) ;
F_10 ( V_6 , V_186 , V_169 , V_169 ) ;
F_10 ( V_6 , V_187 , V_169 , V_169 ) ;
F_18 ( V_6 , V_188 , V_189 ) ;
F_18 ( V_6 , V_190 , V_189 ) ;
F_18 ( V_6 , V_191 , 0x0 ) ;
F_18 ( V_6 , V_192 , 0x0 ) ;
F_18 ( V_6 , V_193 , V_165 ) ;
F_18 ( V_6 , V_194 , V_165 ) ;
F_18 ( V_6 , V_195 , V_165 ) ;
F_18 ( V_6 , V_196 , V_165 ) ;
F_18 ( V_6 , V_197 , V_165 ) ;
F_18 ( V_6 , V_198 , V_165 ) ;
if ( V_27 -> V_34 != V_44 ) {
F_18 ( V_6 , V_199 , V_165 ) ;
F_18 ( V_6 , V_200 , V_165 ) ;
F_18 ( V_6 , V_201 , V_165 ) ;
F_18 ( V_6 , V_202 , V_165 ) ;
F_18 ( V_6 , V_203 , V_165 ) ;
F_18 ( V_6 , V_204 , V_165 ) ;
}
switch ( V_27 -> V_34 ) {
case V_35 :
case V_36 :
F_43 ( V_6 ) ;
break;
case V_41 :
F_18 ( V_6 , V_205 , 0 ) ;
break;
}
return 0 ;
}
static bool F_45 ( struct V_26 * V_27 )
{
struct V_26 * V_206 ;
F_46 (a, &reset_list, list) {
if ( F_32 ( V_27 -> V_147 ) &&
V_27 -> V_147 == V_206 -> V_147 )
return true ;
}
return false ;
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = F_9 ( V_6 ) ;
int V_151 , V_207 ;
F_48 ( & V_27 -> V_208 ) ;
V_27 -> V_6 = V_6 ;
for ( V_207 = 0 ; V_207 < F_13 ( V_27 -> V_152 ) ; V_207 ++ ) {
V_27 -> V_145 [ V_207 ] . V_143 . V_209 = F_30 ;
V_27 -> V_145 [ V_207 ] . V_27 = V_27 ;
V_151 = F_49 ( V_27 -> V_152 [ V_207 ] . V_210 ,
& V_27 -> V_145 [ V_207 ] . V_143 ) ;
if ( V_151 ) {
F_26 ( V_6 -> V_140 ,
L_5 ,
V_151 ) ;
goto V_211;
}
}
F_34 ( V_27 -> V_148 ) ;
F_44 ( V_6 ) ;
if ( V_27 -> V_212 ) {
if ( V_27 -> V_34 != V_44 ) {
F_18 ( V_6 , V_213 ,
( V_27 -> V_212 -> V_214 [ 0 ] & 0xf ) << 4 ) ;
F_18 ( V_6 , V_215 ,
( V_27 -> V_212 -> V_214 [ 1 ] & 0xf ) << 4 ) ;
} else {
F_50 ( V_6 -> V_140 , L_6 ) ;
}
}
switch ( V_27 -> V_34 ) {
case V_35 :
case V_36 :
F_51 ( V_6 , V_216 ,
F_13 ( V_216 ) ) ;
F_51 ( V_6 , V_217 ,
F_13 ( V_217 ) ) ;
break;
case V_41 :
F_51 ( V_6 , V_216 ,
F_13 ( V_216 ) ) ;
F_51 ( V_6 ,
& V_218 , 1 ) ;
break;
case V_44 :
break;
}
switch ( V_27 -> V_31 ) {
case V_219 :
case V_220 :
case V_221 :
F_10 ( V_6 , V_29 ,
V_30 ,
( V_27 -> V_31 ) << V_32 ) ;
break;
case V_222 :
break;
}
F_11 ( V_6 ) ;
return 0 ;
V_211:
while ( V_207 -- )
F_52 ( V_27 -> V_152 [ V_207 ] . V_210 ,
& V_27 -> V_145 [ V_207 ] . V_143 ) ;
return V_151 ;
}
static int F_53 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = F_9 ( V_6 ) ;
int V_207 ;
F_54 ( & V_27 -> V_208 ) ;
for ( V_207 = 0 ; V_207 < F_13 ( V_27 -> V_152 ) ; V_207 ++ )
F_52 ( V_27 -> V_152 [ V_207 ] . V_210 ,
& V_27 -> V_145 [ V_207 ] . V_143 ) ;
return 0 ;
}
static int F_55 ( struct V_223 * V_224 ,
const struct V_225 * V_226 )
{
struct V_227 * V_228 = V_224 -> V_140 . V_229 ;
struct V_26 * V_27 ;
struct V_230 * V_231 ;
struct V_232 * V_233 = V_224 -> V_140 . V_234 ;
int V_151 , V_207 ;
T_3 V_22 ;
V_27 = F_56 ( & V_224 -> V_140 , sizeof( struct V_26 ) , V_235 ) ;
if ( ! V_27 )
return - V_236 ;
V_27 -> V_148 = F_57 ( V_224 , & V_237 ) ;
if ( F_58 ( V_27 -> V_148 ) ) {
V_151 = F_59 ( V_27 -> V_148 ) ;
return V_151 ;
}
F_38 ( V_27 -> V_148 , true ) ;
F_60 ( V_224 , V_27 ) ;
if ( V_228 ) {
V_27 -> V_147 = V_228 -> V_147 ;
V_27 -> V_212 = V_228 -> V_212 ;
V_27 -> V_31 = V_228 -> V_31 ;
} else if ( V_233 ) {
V_231 = F_56 ( & V_224 -> V_140 , sizeof( * V_231 ) ,
V_235 ) ;
if ( ! V_231 )
return - V_236 ;
V_151 = F_61 ( V_233 , L_7 , 0 ) ;
if ( V_151 >= 0 )
V_27 -> V_147 = V_151 ;
else
V_27 -> V_147 = - 1 ;
if ( F_62 ( V_233 , L_8 ,
V_231 -> V_214 , 2 ) >= 0 ) {
V_27 -> V_212 = V_231 ;
}
if ( ! F_63 ( V_233 , L_9 , & V_22 ) ) {
switch ( V_22 ) {
case 1 :
V_27 -> V_31 = V_219 ;
break;
case 2 :
V_27 -> V_31 = V_220 ;
break;
case 3 :
V_27 -> V_31 = V_221 ;
break;
default :
V_27 -> V_31 = V_222 ;
F_26 ( & V_224 -> V_140 , L_10
L_11 ) ;
}
} else {
V_27 -> V_31 = V_222 ;
}
} else {
V_27 -> V_147 = - 1 ;
}
V_27 -> V_34 = V_226 -> V_238 ;
if ( F_32 ( V_27 -> V_147 ) &&
! F_45 ( V_27 ) ) {
V_151 = F_64 ( V_27 -> V_147 , L_12 ) ;
if ( V_151 != 0 )
goto V_239;
F_65 ( V_27 -> V_147 , 0 ) ;
}
for ( V_207 = 0 ; V_207 < F_13 ( V_27 -> V_152 ) ; V_207 ++ )
V_27 -> V_152 [ V_207 ] . V_240 = V_241 [ V_207 ] ;
V_151 = F_66 ( & V_224 -> V_140 , F_13 ( V_27 -> V_152 ) ,
V_27 -> V_152 ) ;
if ( V_151 != 0 ) {
F_26 ( & V_224 -> V_140 , L_13 , V_151 ) ;
goto V_242;
}
if ( V_27 -> V_34 == V_41 ) {
V_151 = F_67 ( V_27 -> V_148 , V_243 ,
F_13 ( V_243 ) ) ;
if ( V_151 != 0 )
F_26 ( & V_224 -> V_140 , L_14 ,
V_151 ) ;
}
V_151 = F_68 ( & V_224 -> V_140 ,
& V_244 , & V_245 , 1 ) ;
if ( V_151 != 0 )
goto V_242;
F_69 ( & V_27 -> V_208 , & V_246 ) ;
return 0 ;
V_242:
if ( F_32 ( V_27 -> V_147 ) &&
! F_45 ( V_27 ) )
F_70 ( V_27 -> V_147 ) ;
V_239:
return V_151 ;
}
static int F_71 ( struct V_223 * V_247 )
{
struct V_26 * V_27 = F_72 ( V_247 ) ;
F_73 ( & V_247 -> V_140 ) ;
if ( F_32 ( V_27 -> V_147 ) &&
! F_45 ( V_27 ) ) {
F_33 ( V_27 -> V_147 , 0 ) ;
F_70 ( V_27 -> V_147 ) ;
}
return 0 ;
}
