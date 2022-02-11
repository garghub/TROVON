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
struct V_5 * V_6 = F_7 ( V_23 -> V_21 ) ;
struct V_25 * V_26 = F_8 ( V_6 ) ;
switch ( V_24 ) {
case V_27 :
F_9 ( V_6 , V_28 ,
V_29 ,
V_26 -> V_30 << V_31 ) ;
break;
case V_32 :
F_9 ( V_6 , V_28 ,
V_29 , 0 ) ;
break;
}
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_8 ( V_6 ) ;
struct V_33 * V_21 = & V_6 -> V_21 ;
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_11 ( V_21 , V_37 ,
F_12 ( V_37 ) ) ;
F_13 ( V_21 , V_38 ,
F_12 ( V_38 ) ) ;
F_11 ( V_21 , V_39 ,
F_12 ( V_39 ) ) ;
F_13 ( V_21 , V_40 ,
F_12 ( V_40 ) ) ;
break;
case V_41 :
F_11 ( V_21 , V_37 ,
F_12 ( V_37 ) ) ;
F_13 ( V_21 , V_38 ,
F_12 ( V_38 ) ) ;
F_11 ( V_21 , V_42 ,
F_12 ( V_42 ) ) ;
F_13 ( V_21 , V_43 ,
F_12 ( V_43 ) ) ;
break;
case V_44 :
F_11 ( V_21 , V_45 ,
F_12 ( V_45 ) ) ;
F_13 ( V_21 , V_46 ,
F_12 ( V_46 ) ) ;
break;
}
return 0 ;
}
static int F_14 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_25 * V_26 = F_8 ( V_6 ) ;
int V_53 = 0 , V_54 = 0 , V_55 , V_56 = 0 ;
T_1 V_57 , V_58 , V_59 , V_60 , V_61 , V_62 = 1 , V_63 = 1 , V_64 = 1 ;
T_2 V_65 , V_66 = 1 ;
int V_67 ;
V_57 = F_15 ( V_6 , V_68 ) & ( ~ ( 0x3 << 4 ) ) ;
switch ( F_16 ( V_50 ) ) {
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
F_17 ( V_6 , V_68 , V_57 ) ;
V_55 = ( F_18 ( V_50 ) % 11025 == 0 ) ? 44100 : 48000 ;
for ( V_61 = 2 ; V_61 < 18 ; V_61 ++ )
if ( V_26 -> V_69 / ( 128 * V_61 ) == V_55 ) {
V_54 = 1 ;
break;
}
if ( V_54 ) {
V_61 &= 0xf ;
F_17 ( V_6 , V_70 , V_61 << V_71 ) ;
F_17 ( V_6 , V_72 , V_73 ) ;
F_9 ( V_6 , V_70 , V_74 , 0 ) ;
} else {
F_17 ( V_6 , V_72 , V_75 ) ;
F_9 ( V_6 , V_70 ,
V_74 , V_74 ) ;
}
V_57 = ( V_76 | V_77 ) ;
V_57 |= ( V_55 == 44100 ) ? V_78 : V_79 ;
if ( F_18 ( V_50 ) >= 64000 )
V_57 |= V_80 ;
F_17 ( V_6 , V_81 , V_57 ) ;
V_57 = ( V_55 * 20 ) / F_18 ( V_50 ) ;
if ( F_18 ( V_50 ) < 64000 )
V_57 /= 2 ;
V_57 /= 5 ;
V_57 -= 2 ;
V_57 |= ( V_57 << 4 ) ;
F_17 ( V_6 , V_82 , V_57 ) ;
if ( V_54 )
return 0 ;
V_53 = ( 2048 * V_55 ) / ( V_26 -> V_69 / 1000 ) ;
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
V_65 = ( ( 2048 * V_60 * V_55 ) - V_58 * V_26 -> V_69 )
* 100 / ( V_26 -> V_69 / 100 ) ;
V_67 = ( 10000 * V_58 + V_65 ) / ( 10 * V_60 ) ;
if ( abs ( V_53 - V_67 ) < abs ( V_53 - V_56 ) ) {
V_64 = V_58 ; V_66 = V_65 ; V_63 = 1 ; V_62 = V_60 ;
V_56 = V_67 ;
}
if ( V_67 == V_53 )
goto V_84;
}
if ( V_56 == 0 ) {
F_19 ( V_85 L_1 , V_86 ) ;
return - V_87 ;
}
V_84:
F_9 ( V_6 , V_70 , V_88 , V_62 ) ;
F_17 ( V_6 , V_89 ,
V_63 << V_90 ) ;
F_17 ( V_6 , V_91 , V_64 << V_92 ) ;
F_17 ( V_6 , V_93 ,
( V_66 >> 6 ) << V_94 ) ;
F_17 ( V_6 , V_95 ,
( V_66 & 0x3F ) << V_96 ) ;
return 0 ;
}
static int F_20 ( struct V_47 * V_48 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_25 * V_26 = F_8 ( V_6 ) ;
int V_97 = 0 ;
if ( V_26 -> V_98 == V_99 )
V_97 += ( V_26 -> V_100 + 1 ) ;
else if ( V_26 -> V_98 == V_101 )
V_97 += V_26 -> V_100 ;
F_17 ( V_6 , V_102 , V_97 ) ;
return 0 ;
}
static int F_21 ( struct V_51 * V_52 , int V_103 )
{
struct V_5 * V_6 = V_52 -> V_6 ;
T_1 V_104 = F_15 ( V_6 , V_105 ) & ~ V_106 ;
T_1 V_107 = F_15 ( V_6 , V_108 ) & ~ V_106 ;
if ( V_103 ) {
F_17 ( V_6 , V_105 , V_104 | V_106 ) ;
F_17 ( V_6 , V_108 , V_107 | V_106 ) ;
} else {
F_17 ( V_6 , V_105 , V_104 ) ;
F_17 ( V_6 , V_108 , V_107 ) ;
}
return 0 ;
}
static int F_22 ( struct V_51 * V_109 ,
int V_110 , unsigned int V_111 , int V_112 )
{
struct V_5 * V_6 = V_109 -> V_6 ;
struct V_25 * V_26 = F_8 ( V_6 ) ;
F_9 ( V_6 , V_113 , V_114 ,
V_110 << V_115 ) ;
F_9 ( V_6 , V_113 , V_116 ,
V_110 << V_117 ) ;
V_26 -> V_69 = V_111 ;
return 0 ;
}
static int F_23 ( struct V_51 * V_109 ,
unsigned int V_118 )
{
struct V_5 * V_6 = V_109 -> V_6 ;
struct V_25 * V_26 = F_8 ( V_6 ) ;
T_1 V_119 , V_120 ;
V_119 = F_15 ( V_6 , V_121 ) & 0x3f ;
V_120 = F_15 ( V_6 , V_68 ) & 0x3f ;
switch ( V_118 & V_122 ) {
case V_123 :
V_26 -> V_124 = 1 ;
V_119 |= V_125 | V_126 ;
break;
case V_127 :
V_26 -> V_124 = 0 ;
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
V_26 -> V_98 = V_118 & V_128 ;
F_17 ( V_6 , V_121 , V_119 ) ;
F_17 ( V_6 , V_68 , V_120 ) ;
return 0 ;
}
static int F_24 ( struct V_51 * V_109 ,
unsigned int V_135 , unsigned int V_136 ,
int V_137 , int V_138 )
{
struct V_5 * V_6 = V_109 -> V_6 ;
struct V_25 * V_26 = F_8 ( V_6 ) ;
unsigned int V_139 ;
if ( V_135 != V_136 ) {
F_25 ( V_6 -> V_140 , L_2 ) ;
return - V_87 ;
}
if ( F_26 ( ! V_135 ) ) {
F_25 ( V_6 -> V_140 , L_3 ) ;
return - V_87 ;
}
V_139 = F_27 ( V_135 ) ;
if ( ( V_139 + 1 ) != F_28 ( V_135 ) ) {
F_25 ( V_6 -> V_140 , L_4 ) ;
return - V_87 ;
}
V_26 -> V_100 = V_139 * V_138 ;
F_9 ( V_6 , V_121 ,
V_141 , V_141 ) ;
return 0 ;
}
static int F_29 ( struct V_142 * V_143 ,
unsigned long V_24 , void * V_57 )
{
struct V_144 * V_145 =
F_30 ( V_143 , struct V_144 , V_143 ) ;
struct V_25 * V_26 = V_145 -> V_26 ;
if ( V_24 & V_146 ) {
if ( F_31 ( V_26 -> V_147 ) )
F_32 ( V_26 -> V_147 , 0 ) ;
F_33 ( V_26 -> V_148 ) ;
}
return 0 ;
}
static int F_34 ( struct V_5 * V_6 , int V_149 )
{
struct V_25 * V_26 = F_8 ( V_6 ) ;
unsigned int V_150 , V_66 ;
int V_151 ;
if ( V_149 ) {
V_151 = F_35 ( F_12 ( V_26 -> V_152 ) ,
V_26 -> V_152 ) ;
if ( V_151 )
goto V_153;
V_26 -> V_149 = 1 ;
if ( F_31 ( V_26 -> V_147 ) ) {
F_36 ( 1 ) ;
F_32 ( V_26 -> V_147 , 1 ) ;
}
F_37 ( V_26 -> V_148 , false ) ;
F_38 ( V_26 -> V_148 ) ;
V_150 = F_15 ( V_6 , V_93 ) ;
V_66 = F_15 ( V_6 , V_95 ) ;
if ( V_150 == V_154 [ V_93 ] . V_155 ||
V_66 == V_154 [ V_95 ] . V_155 ) {
F_17 ( V_6 , V_93 , V_150 ) ;
F_17 ( V_6 , V_95 , V_66 ) ;
}
} else {
F_17 ( V_6 , V_156 , V_157 ) ;
F_33 ( V_26 -> V_148 ) ;
V_26 -> V_149 = 0 ;
F_37 ( V_26 -> V_148 , true ) ;
V_151 = F_39 ( F_12 ( V_26 -> V_152 ) ,
V_26 -> V_152 ) ;
}
V_153:
return V_151 ;
}
static int F_40 ( struct V_5 * V_6 ,
enum V_158 V_159 )
{
struct V_25 * V_26 = F_8 ( V_6 ) ;
switch ( V_159 ) {
case V_160 :
break;
case V_161 :
if ( V_6 -> V_21 . V_162 == V_163 &&
V_26 -> V_124 ) {
F_9 ( V_6 , V_70 ,
V_74 , V_74 ) ;
}
break;
case V_163 :
if ( ! V_26 -> V_149 )
F_34 ( V_6 , 1 ) ;
if ( V_6 -> V_21 . V_162 == V_161 &&
V_26 -> V_124 ) {
F_9 ( V_6 , V_70 ,
V_74 , 0 ) ;
}
break;
case V_164 :
if ( V_26 -> V_149 )
F_34 ( V_6 , 0 ) ;
break;
}
V_6 -> V_21 . V_162 = V_159 ;
return 0 ;
}
static void F_41 ( struct V_5 * V_6 )
{
F_17 ( V_6 , V_165 , V_166 | V_167 ) ;
F_17 ( V_6 , V_168 , V_166 | V_167 ) ;
F_9 ( V_6 , V_169 , V_170 , V_170 ) ;
F_17 ( V_6 , V_171 , V_166 ) ;
F_17 ( V_6 , V_172 , V_166 ) ;
F_17 ( V_6 , V_173 , V_166 ) ;
F_17 ( V_6 , V_174 , V_166 ) ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_8 ( V_6 ) ;
F_17 ( V_6 , V_175 , V_176 ) ;
F_17 ( V_6 , V_156 , V_157 ) ;
F_17 ( V_6 , V_105 , V_166 | V_106 ) ;
F_17 ( V_6 , V_108 , V_166 | V_106 ) ;
F_17 ( V_6 , V_177 , V_166 | V_167 ) ;
F_17 ( V_6 , V_178 , V_166 | V_167 ) ;
F_17 ( V_6 , V_179 , V_166 | V_167 ) ;
F_17 ( V_6 , V_180 , V_166 | V_167 ) ;
F_17 ( V_6 , V_181 , V_166 | V_167 ) ;
F_17 ( V_6 , V_182 , V_166 | V_167 ) ;
F_9 ( V_6 , V_183 , V_170 , V_170 ) ;
F_9 ( V_6 , V_184 , V_170 , V_170 ) ;
F_9 ( V_6 , V_185 , V_170 , V_170 ) ;
F_9 ( V_6 , V_186 , V_170 , V_170 ) ;
F_9 ( V_6 , V_187 , V_170 , V_170 ) ;
F_9 ( V_6 , V_188 , V_170 , V_170 ) ;
F_17 ( V_6 , V_189 , V_190 ) ;
F_17 ( V_6 , V_191 , V_190 ) ;
F_17 ( V_6 , V_192 , 0x0 ) ;
F_17 ( V_6 , V_193 , 0x0 ) ;
F_17 ( V_6 , V_194 , V_166 ) ;
F_17 ( V_6 , V_195 , V_166 ) ;
F_17 ( V_6 , V_196 , V_166 ) ;
F_17 ( V_6 , V_197 , V_166 ) ;
F_17 ( V_6 , V_198 , V_166 ) ;
F_17 ( V_6 , V_199 , V_166 ) ;
F_17 ( V_6 , V_200 , V_166 ) ;
F_17 ( V_6 , V_201 , V_166 ) ;
F_17 ( V_6 , V_202 , V_166 ) ;
F_17 ( V_6 , V_203 , V_166 ) ;
F_17 ( V_6 , V_204 , V_166 ) ;
F_17 ( V_6 , V_205 , V_166 ) ;
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_41 ( V_6 ) ;
break;
case V_41 :
F_17 ( V_6 , V_206 , 0 ) ;
break;
}
return 0 ;
}
static bool F_43 ( struct V_25 * V_26 )
{
struct V_25 * V_207 ;
F_44 (a, &reset_list, list) {
if ( F_31 ( V_26 -> V_147 ) &&
V_26 -> V_147 == V_207 -> V_147 )
return true ;
}
return false ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_8 ( V_6 ) ;
int V_151 , V_208 ;
F_46 ( & V_26 -> V_209 ) ;
V_26 -> V_6 = V_6 ;
for ( V_208 = 0 ; V_208 < F_12 ( V_26 -> V_152 ) ; V_208 ++ ) {
V_26 -> V_145 [ V_208 ] . V_143 . V_210 = F_29 ;
V_26 -> V_145 [ V_208 ] . V_26 = V_26 ;
V_151 = F_47 ( V_26 -> V_152 [ V_208 ] . V_211 ,
& V_26 -> V_145 [ V_208 ] . V_143 ) ;
if ( V_151 ) {
F_25 ( V_6 -> V_140 ,
L_5 ,
V_151 ) ;
goto V_212;
}
}
F_33 ( V_26 -> V_148 ) ;
F_42 ( V_6 ) ;
if ( V_26 -> V_213 ) {
if ( V_26 -> V_34 != V_44 ) {
F_17 ( V_6 , V_214 ,
( V_26 -> V_213 -> V_215 [ 0 ] & 0xf ) << 4 ) ;
F_17 ( V_6 , V_216 ,
( V_26 -> V_213 -> V_215 [ 1 ] & 0xf ) << 4 ) ;
} else {
F_48 ( V_6 -> V_140 , L_6 ) ;
}
}
switch ( V_26 -> V_34 ) {
case V_35 :
case V_36 :
F_49 ( V_6 , V_217 ,
F_12 ( V_217 ) ) ;
F_49 ( V_6 , V_218 ,
F_12 ( V_218 ) ) ;
break;
case V_41 :
F_49 ( V_6 , V_217 ,
F_12 ( V_217 ) ) ;
F_49 ( V_6 ,
& V_219 , 1 ) ;
break;
case V_44 :
break;
}
switch ( V_26 -> V_30 ) {
case V_220 :
case V_221 :
case V_222 :
F_9 ( V_6 , V_28 ,
V_29 ,
( V_26 -> V_30 ) << V_31 ) ;
break;
case V_223 :
break;
}
F_10 ( V_6 ) ;
return 0 ;
V_212:
while ( V_208 -- )
F_50 ( V_26 -> V_152 [ V_208 ] . V_211 ,
& V_26 -> V_145 [ V_208 ] . V_143 ) ;
return V_151 ;
}
static int F_51 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_8 ( V_6 ) ;
int V_208 ;
F_52 ( & V_26 -> V_209 ) ;
for ( V_208 = 0 ; V_208 < F_12 ( V_26 -> V_152 ) ; V_208 ++ )
F_50 ( V_26 -> V_152 [ V_208 ] . V_211 ,
& V_26 -> V_145 [ V_208 ] . V_143 ) ;
return 0 ;
}
static int F_53 ( struct V_224 * V_225 ,
const struct V_226 * V_227 )
{
struct V_228 * V_229 = V_225 -> V_140 . V_230 ;
struct V_25 * V_26 ;
struct V_231 * V_232 ;
struct V_233 * V_234 = V_225 -> V_140 . V_235 ;
int V_151 , V_208 ;
T_3 V_20 ;
V_26 = F_54 ( & V_225 -> V_140 , sizeof( struct V_25 ) , V_236 ) ;
if ( ! V_26 )
return - V_237 ;
V_26 -> V_148 = F_55 ( V_225 , & V_238 ) ;
if ( F_56 ( V_26 -> V_148 ) ) {
V_151 = F_57 ( V_26 -> V_148 ) ;
return V_151 ;
}
F_37 ( V_26 -> V_148 , true ) ;
F_58 ( V_225 , V_26 ) ;
if ( V_229 ) {
V_26 -> V_147 = V_229 -> V_147 ;
V_26 -> V_213 = V_229 -> V_213 ;
V_26 -> V_30 = V_229 -> V_30 ;
} else if ( V_234 ) {
V_232 = F_54 ( & V_225 -> V_140 , sizeof( * V_232 ) ,
V_236 ) ;
if ( ! V_232 )
return - V_237 ;
V_151 = F_59 ( V_234 , L_7 , 0 ) ;
if ( V_151 >= 0 )
V_26 -> V_147 = V_151 ;
else
V_26 -> V_147 = - 1 ;
if ( F_60 ( V_234 , L_8 ,
V_232 -> V_215 , 2 ) >= 0 ) {
V_26 -> V_213 = V_232 ;
}
if ( ! F_61 ( V_234 , L_9 , & V_20 ) ) {
switch ( V_20 ) {
case 1 :
V_26 -> V_30 = V_220 ;
break;
case 2 :
V_26 -> V_30 = V_221 ;
break;
case 3 :
V_26 -> V_30 = V_222 ;
break;
default :
V_26 -> V_30 = V_223 ;
F_25 ( & V_225 -> V_140 , L_10
L_11 ) ;
}
} else {
V_26 -> V_30 = V_223 ;
}
} else {
V_26 -> V_147 = - 1 ;
}
V_26 -> V_34 = V_227 -> V_239 ;
if ( F_31 ( V_26 -> V_147 ) &&
! F_43 ( V_26 ) ) {
V_151 = F_62 ( V_26 -> V_147 , L_12 ) ;
if ( V_151 != 0 )
goto V_240;
F_63 ( V_26 -> V_147 , 0 ) ;
}
for ( V_208 = 0 ; V_208 < F_12 ( V_26 -> V_152 ) ; V_208 ++ )
V_26 -> V_152 [ V_208 ] . V_241 = V_242 [ V_208 ] ;
V_151 = F_64 ( & V_225 -> V_140 , F_12 ( V_26 -> V_152 ) ,
V_26 -> V_152 ) ;
if ( V_151 != 0 ) {
F_25 ( & V_225 -> V_140 , L_13 , V_151 ) ;
goto V_243;
}
if ( V_26 -> V_34 == V_41 ) {
V_151 = F_65 ( V_26 -> V_148 , V_244 ,
F_12 ( V_244 ) ) ;
if ( V_151 != 0 )
F_25 ( & V_225 -> V_140 , L_14 ,
V_151 ) ;
}
V_151 = F_66 ( & V_225 -> V_140 ,
& V_245 , & V_246 , 1 ) ;
if ( V_151 != 0 )
goto V_243;
F_67 ( & V_26 -> V_209 , & V_247 ) ;
return 0 ;
V_243:
if ( F_31 ( V_26 -> V_147 ) &&
! F_43 ( V_26 ) )
F_68 ( V_26 -> V_147 ) ;
V_240:
return V_151 ;
}
static int F_69 ( struct V_224 * V_248 )
{
struct V_25 * V_26 = F_70 ( V_248 ) ;
F_71 ( & V_248 -> V_140 ) ;
if ( F_31 ( V_26 -> V_147 ) &&
! F_43 ( V_26 ) ) {
F_32 ( V_26 -> V_147 , 0 ) ;
F_68 ( V_26 -> V_147 ) ;
}
return 0 ;
}
