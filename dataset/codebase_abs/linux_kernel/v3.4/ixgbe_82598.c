static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = F_2 ( V_2 , V_7 ) ;
T_2 V_8 ;
if ( V_6 & V_9 )
goto V_10;
if ( ! ( V_6 & V_11 ) ) {
V_6 |= V_12 ;
goto V_10;
}
F_3 ( V_4 -> V_13 ,
V_14 , & V_8 ) ;
V_8 |= V_15 ;
F_4 ( V_4 -> V_13 ,
V_14 , V_8 ) ;
V_10:
V_6 &= ~ V_16 ;
F_5 ( V_2 , V_7 , V_6 ) ;
}
static T_2 F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_17 ;
F_3 ( V_4 -> V_13 , V_18 ,
& V_17 ) ;
V_17 &= V_19 ;
V_17 ++ ;
return V_17 ;
}
static T_3 F_7 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
F_8 ( V_2 ) ;
V_21 -> V_22 = V_23 ;
V_21 -> V_24 = V_25 ;
V_21 -> V_26 = V_27 ;
V_21 -> V_28 = V_29 ;
V_21 -> V_30 = V_31 ;
V_21 -> V_32 = F_6 ( V_2 ) ;
return 0 ;
}
static T_3 F_9 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
struct V_33 * V_34 = & V_2 -> V_34 ;
T_3 V_35 = 0 ;
T_2 V_36 , V_37 ;
V_34 -> V_38 . V_39 ( V_2 ) ;
if ( V_21 -> V_38 . V_40 ( V_2 ) == V_41 ) {
V_21 -> V_38 . V_42 = & V_43 ;
V_21 -> V_38 . V_44 =
& V_45 ;
}
switch ( V_2 -> V_34 . type ) {
case V_46 :
V_34 -> V_38 . V_42 = & V_47 ;
V_34 -> V_38 . V_48 = & V_49 ;
V_34 -> V_38 . V_50 =
& V_51 ;
break;
case V_52 :
V_34 -> V_38 . V_53 = & V_54 ;
V_35 = V_34 -> V_38 . V_55 ( V_2 ) ;
if ( V_35 != 0 )
goto V_10;
else if ( V_2 -> V_34 . V_56 == V_57 ) {
V_35 = V_58 ;
goto V_10;
}
V_35 = F_10 ( V_2 ,
& V_36 ,
& V_37 ) ;
if ( V_35 != 0 ) {
V_35 = V_58 ;
goto V_10;
}
break;
default:
break;
}
V_10:
return V_35 ;
}
static T_3 F_11 ( struct V_1 * V_2 )
{
T_1 V_59 ;
T_1 V_60 ;
T_3 V_35 = 0 ;
V_35 = F_12 ( V_2 ) ;
for ( V_60 = 0 ; ( ( V_60 < V_2 -> V_21 . V_30 ) &&
( V_60 < V_61 ) ) ; V_60 ++ ) {
V_59 = F_2 ( V_2 , F_13 ( V_60 ) ) ;
V_59 &= ~ V_62 ;
F_5 ( V_2 , F_13 ( V_60 ) , V_59 ) ;
}
for ( V_60 = 0 ; ( ( V_60 < V_2 -> V_21 . V_28 ) &&
( V_60 < V_61 ) ) ; V_60 ++ ) {
V_59 = F_2 ( V_2 , F_14 ( V_60 ) ) ;
V_59 &= ~ ( V_63 |
V_64 ) ;
F_5 ( V_2 , F_14 ( V_60 ) , V_59 ) ;
}
V_2 -> V_21 . V_65 = V_66 ;
if ( V_35 == 0 )
F_1 ( V_2 ) ;
return V_35 ;
}
static T_3 F_15 ( struct V_1 * V_2 ,
T_4 * V_67 ,
bool * V_68 )
{
T_3 V_69 = 0 ;
T_1 V_70 = 0 ;
if ( V_2 -> V_21 . V_71 )
V_70 = V_2 -> V_21 . V_72 ;
else
V_70 = F_2 ( V_2 , V_73 ) ;
switch ( V_70 & V_74 ) {
case V_75 :
* V_67 = V_76 ;
* V_68 = false ;
break;
case V_77 :
* V_67 = V_78 ;
* V_68 = false ;
break;
case V_79 :
* V_67 = V_76 ;
* V_68 = true ;
break;
case V_80 :
case V_81 :
* V_67 = V_82 ;
if ( V_70 & V_83 )
* V_67 |= V_78 ;
if ( V_70 & V_84 )
* V_67 |= V_76 ;
* V_68 = true ;
break;
default:
V_69 = V_85 ;
break;
}
return V_69 ;
}
static enum V_86 F_16 ( struct V_1 * V_2 )
{
enum V_86 V_87 ;
switch ( V_2 -> V_34 . type ) {
case V_88 :
case V_46 :
V_87 = V_41 ;
goto V_10;
default:
break;
}
switch ( V_2 -> V_89 ) {
case V_90 :
case V_91 :
V_87 = V_92 ;
break;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
V_87 = V_99 ;
break;
case V_100 :
case V_101 :
V_87 = V_102 ;
break;
case V_103 :
case V_104 :
V_87 = V_41 ;
break;
default:
V_87 = V_105 ;
break;
}
V_10:
return V_87 ;
}
static T_3 F_17 ( struct V_1 * V_2 , T_3 V_106 )
{
T_3 V_35 = 0 ;
T_1 V_107 ;
T_1 V_108 ;
T_1 V_109 ;
T_1 V_110 = 0 ;
bool V_111 ;
#ifdef F_18
if ( V_2 -> V_112 . V_113 == V_114 )
goto V_10;
#endif
V_2 -> V_21 . V_38 . V_48 ( V_2 , & V_110 , & V_111 , false ) ;
if ( V_111 && V_110 == V_76 ) {
switch ( V_2 -> V_112 . V_113 ) {
case V_115 :
V_2 -> V_112 . V_113 = V_116 ;
break;
case V_117 :
V_2 -> V_112 . V_113 = V_118 ;
break;
default:
break;
}
}
V_35 = F_19 ( V_2 ) ;
if ( V_35 == V_119 )
goto V_10;
V_107 = F_2 ( V_2 , V_120 ) ;
V_107 &= ~ ( V_121 | V_122 ) ;
V_108 = F_2 ( V_2 , V_123 ) ;
V_108 &= ~ ( V_124 | V_125 ) ;
switch ( V_2 -> V_112 . V_126 ) {
case V_118 :
break;
case V_117 :
V_107 |= V_121 ;
break;
case V_116 :
V_108 |= V_125 ;
break;
case V_115 :
V_107 |= V_121 ;
V_108 |= V_125 ;
break;
#ifdef F_18
case V_114 :
goto V_10;
break;
#endif
default:
F_20 ( V_2 , L_1 ) ;
V_35 = V_127 ;
goto V_10;
break;
}
V_107 |= V_128 ;
F_5 ( V_2 , V_120 , V_107 ) ;
F_5 ( V_2 , V_123 , V_108 ) ;
if ( V_2 -> V_112 . V_126 & V_116 ) {
V_109 = V_2 -> V_112 . V_129 << 6 ;
if ( V_2 -> V_112 . V_130 )
V_109 |= V_131 ;
F_5 ( V_2 , F_21 ( V_106 ) , V_109 ) ;
V_109 = V_2 -> V_112 . V_132 [ V_106 ] << 6 ;
V_109 |= V_133 ;
F_5 ( V_2 , F_22 ( V_106 ) , V_109 ) ;
}
V_109 = F_2 ( V_2 , F_23 ( V_106 / 2 ) ) ;
if ( ( V_106 & 1 ) == 0 )
V_109 = ( V_109 & 0xFFFF0000 ) | V_2 -> V_112 . V_134 ;
else
V_109 = ( V_109 & 0x0000FFFF ) | ( V_2 -> V_112 . V_134 << 16 ) ;
F_5 ( V_2 , F_23 ( V_106 / 2 ) , V_109 ) ;
F_5 ( V_2 , V_135 , ( V_2 -> V_112 . V_134 >> 1 ) ) ;
V_10:
return V_35 ;
}
static T_3 F_24 ( struct V_1 * V_2 ,
bool V_136 )
{
T_1 V_137 ;
T_1 V_138 ;
T_1 V_60 ;
T_3 V_69 = 0 ;
V_137 = F_2 ( V_2 , V_73 ) ;
V_137 |= V_139 ;
F_5 ( V_2 , V_73 , V_137 ) ;
if ( V_136 ) {
if ( ( V_137 & V_74 ) ==
V_80 ||
( V_137 & V_74 ) ==
V_81 ) {
V_138 = 0 ;
for ( V_60 = 0 ; V_60 < V_140 ; V_60 ++ ) {
V_138 = F_2 ( V_2 , V_141 ) ;
if ( V_138 & V_142 )
break;
F_25 ( 100 ) ;
}
if ( ! ( V_138 & V_142 ) ) {
V_69 = V_143 ;
F_20 ( V_2 , L_2 ) ;
}
}
}
F_25 ( 50 ) ;
return V_69 ;
}
static T_3 F_26 ( struct V_1 * V_2 )
{
T_1 V_144 ;
T_2 V_145 ;
if ( V_2 -> V_89 != V_104 )
return 0 ;
for ( V_144 = 0 ;
V_144 < V_146 ; V_144 ++ ) {
V_2 -> V_34 . V_38 . V_147 ( V_2 , V_148 , V_149 , & V_145 ) ;
if ( ( V_145 & V_150 ) &&
( V_145 & V_151 ) )
break;
F_25 ( 100 ) ;
}
if ( V_144 == V_146 ) {
F_20 ( V_2 , L_3 ) ;
return V_85 ;
}
return 0 ;
}
static T_3 F_27 ( struct V_1 * V_2 ,
T_4 * V_67 , bool * V_111 ,
bool V_152 )
{
T_1 V_138 ;
T_1 V_60 ;
T_2 V_153 , V_154 ;
if ( V_2 -> V_34 . type == V_52 ) {
V_2 -> V_34 . V_38 . V_147 ( V_2 , 0xC79F , V_155 , & V_153 ) ;
V_2 -> V_34 . V_38 . V_147 ( V_2 , 0xC79F , V_155 , & V_153 ) ;
V_2 -> V_34 . V_38 . V_147 ( V_2 , 0xC00C , V_155 ,
& V_154 ) ;
if ( V_152 ) {
for ( V_60 = 0 ; V_60 < V_156 ; V_60 ++ ) {
if ( ( V_153 & 1 ) &&
( ( V_154 & 1 ) == 0 ) ) {
* V_111 = true ;
break;
} else {
* V_111 = false ;
}
F_25 ( 100 ) ;
V_2 -> V_34 . V_38 . V_147 ( V_2 , 0xC79F ,
V_155 ,
& V_153 ) ;
V_2 -> V_34 . V_38 . V_147 ( V_2 , 0xC00C ,
V_155 ,
& V_154 ) ;
}
} else {
if ( ( V_153 & 1 ) && ( ( V_154 & 1 ) == 0 ) )
* V_111 = true ;
else
* V_111 = false ;
}
if ( ! * V_111 )
goto V_10;
}
V_138 = F_2 ( V_2 , V_141 ) ;
if ( V_152 ) {
for ( V_60 = 0 ; V_60 < V_156 ; V_60 ++ ) {
if ( V_138 & V_157 ) {
* V_111 = true ;
break;
} else {
* V_111 = false ;
}
F_25 ( 100 ) ;
V_138 = F_2 ( V_2 , V_141 ) ;
}
} else {
if ( V_138 & V_157 )
* V_111 = true ;
else
* V_111 = false ;
}
if ( V_138 & V_158 )
* V_67 = V_78 ;
else
* V_67 = V_76 ;
if ( ( V_2 -> V_89 == V_104 ) && * V_111 &&
( F_26 ( V_2 ) != 0 ) )
* V_111 = false ;
V_10:
return 0 ;
}
static T_3 F_28 ( struct V_1 * V_2 ,
T_4 V_67 , bool V_68 ,
bool V_136 )
{
T_3 V_69 = 0 ;
T_4 V_159 = V_82 ;
T_1 V_160 = F_2 ( V_2 , V_73 ) ;
T_1 V_70 = V_160 ;
T_1 V_161 = V_70 & V_74 ;
F_15 ( V_2 , & V_159 , & V_68 ) ;
V_67 &= V_159 ;
if ( V_67 == V_82 )
V_69 = V_85 ;
else if ( V_161 == V_80 ||
V_161 == V_81 ) {
V_70 &= ~ V_162 ;
if ( V_67 & V_78 )
V_70 |= V_83 ;
if ( V_67 & V_76 )
V_70 |= V_84 ;
if ( V_70 != V_160 )
F_5 ( V_2 , V_73 , V_70 ) ;
}
if ( V_69 == 0 ) {
V_69 = F_24 ( V_2 ,
V_136 ) ;
}
return V_69 ;
}
static T_3 V_43 ( struct V_1 * V_2 ,
T_4 V_67 ,
bool V_68 ,
bool V_136 )
{
T_3 V_69 ;
V_69 = V_2 -> V_34 . V_38 . V_163 ( V_2 , V_67 , V_68 ,
V_136 ) ;
F_24 ( V_2 , V_136 ) ;
return V_69 ;
}
static T_3 F_29 ( struct V_1 * V_2 )
{
T_3 V_69 = 0 ;
T_3 V_164 = 0 ;
T_1 V_165 ;
T_1 V_166 ;
T_1 V_60 ;
T_1 V_70 ;
T_5 V_167 ;
V_69 = V_2 -> V_21 . V_38 . V_168 ( V_2 ) ;
if ( V_69 != 0 )
goto V_169;
V_2 -> V_21 . V_38 . V_170 ( V_2 , V_171 , & V_167 ) ;
if ( V_167 & V_172 ) {
V_2 -> V_21 . V_38 . V_170 ( V_2 , V_171 ,
& V_167 ) ;
V_167 &= ~ V_172 ;
V_2 -> V_21 . V_38 . V_173 ( V_2 , V_171 ,
V_167 ) ;
V_2 -> V_21 . V_38 . V_170 ( V_2 , V_174 ,
& V_167 ) ;
V_167 &= ~ V_175 ;
V_2 -> V_21 . V_38 . V_173 ( V_2 , V_174 ,
V_167 ) ;
V_2 -> V_21 . V_38 . V_170 ( V_2 , V_176 ,
& V_167 ) ;
V_167 &= ~ V_177 ;
V_2 -> V_21 . V_38 . V_173 ( V_2 , V_176 ,
V_167 ) ;
V_2 -> V_21 . V_38 . V_170 ( V_2 , V_178 ,
& V_167 ) ;
V_167 &= ~ V_179 ;
V_2 -> V_21 . V_38 . V_173 ( V_2 , V_178 ,
V_167 ) ;
}
if ( V_2 -> V_34 . V_180 == false ) {
V_164 = V_2 -> V_34 . V_38 . V_181 ( V_2 ) ;
if ( V_164 == V_58 )
goto V_169;
if ( V_164 == V_182 )
goto V_183;
V_2 -> V_34 . V_38 . V_53 ( V_2 ) ;
}
V_183:
V_165 = F_2 ( V_2 , V_184 ) | V_185 ;
F_5 ( V_2 , V_184 , V_165 ) ;
F_30 ( V_2 ) ;
for ( V_60 = 0 ; V_60 < 10 ; V_60 ++ ) {
F_31 ( 1 ) ;
V_165 = F_2 ( V_2 , V_184 ) ;
if ( ! ( V_165 & V_185 ) )
break;
}
if ( V_165 & V_185 ) {
V_69 = V_186 ;
F_20 ( V_2 , L_4 ) ;
}
F_25 ( 50 ) ;
if ( V_2 -> V_21 . V_187 & V_188 ) {
V_2 -> V_21 . V_187 &= ~ V_188 ;
goto V_183;
}
V_166 = F_2 ( V_2 , V_189 ) ;
V_166 &= ~ ( ( 1 << 21 ) | ( 1 << 18 ) | ( 1 << 9 ) | ( 1 << 6 ) ) ;
F_5 ( V_2 , V_189 , V_166 ) ;
V_70 = F_2 ( V_2 , V_73 ) ;
if ( V_2 -> V_21 . V_71 == false ) {
V_2 -> V_21 . V_72 = V_70 ;
V_2 -> V_21 . V_71 = true ;
} else if ( V_70 != V_2 -> V_21 . V_72 ) {
F_5 ( V_2 , V_73 , V_2 -> V_21 . V_72 ) ;
}
V_2 -> V_21 . V_38 . V_190 ( V_2 , V_2 -> V_21 . V_191 ) ;
V_2 -> V_21 . V_38 . V_192 ( V_2 ) ;
V_169:
if ( V_164 )
V_69 = V_164 ;
return V_69 ;
}
static T_3 F_32 ( struct V_1 * V_2 , T_1 V_193 , T_1 V_194 )
{
T_1 V_195 ;
T_1 V_196 = V_2 -> V_21 . V_26 ;
if ( V_193 >= V_196 ) {
F_20 ( V_2 , L_5 , V_193 ) ;
return V_197 ;
}
V_195 = F_2 ( V_2 , F_33 ( V_193 ) ) ;
V_195 &= ~ V_198 ;
V_195 |= ( ( V_194 << V_199 ) & V_198 ) ;
F_5 ( V_2 , F_33 ( V_193 ) , V_195 ) ;
return 0 ;
}
static T_3 F_34 ( struct V_1 * V_2 , T_1 V_193 , T_1 V_194 )
{
T_1 V_195 ;
T_1 V_196 = V_2 -> V_21 . V_26 ;
if ( V_193 >= V_196 ) {
F_20 ( V_2 , L_5 , V_193 ) ;
return V_197 ;
}
V_195 = F_2 ( V_2 , F_33 ( V_193 ) ) ;
if ( V_195 & V_198 ) {
V_195 &= ~ V_198 ;
F_5 ( V_2 , F_33 ( V_193 ) , V_195 ) ;
}
return 0 ;
}
static T_3 F_35 ( struct V_1 * V_2 , T_1 V_200 , T_1 V_201 ,
bool V_202 )
{
T_1 V_203 ;
T_1 V_204 ;
T_1 V_205 ;
T_1 V_206 ;
if ( V_200 > 4095 )
return V_207 ;
V_203 = ( V_200 >> 5 ) & 0x7F ;
V_206 = ( ( V_200 >> 3 ) & 0x03 ) ;
V_204 = ( V_200 & 0x7 ) << 2 ;
V_205 = F_2 ( V_2 , F_36 ( V_206 , V_203 ) ) ;
V_205 &= ( ~ ( 0x0F << V_204 ) ) ;
V_205 |= ( V_201 << V_204 ) ;
F_5 ( V_2 , F_36 ( V_206 , V_203 ) , V_205 ) ;
V_204 = V_200 & 0x1F ;
V_205 = F_2 ( V_2 , F_37 ( V_203 ) ) ;
if ( V_202 )
V_205 |= ( 1 << V_204 ) ;
else
V_205 &= ~ ( 1 << V_204 ) ;
F_5 ( V_2 , F_37 ( V_203 ) , V_205 ) ;
return 0 ;
}
static T_3 F_38 ( struct V_1 * V_2 )
{
T_1 V_208 ;
T_1 V_209 ;
for ( V_208 = 0 ; V_208 < V_2 -> V_21 . V_24 ; V_208 ++ )
F_5 ( V_2 , F_37 ( V_208 ) , 0 ) ;
for ( V_209 = 0 ; V_209 < 4 ; V_209 ++ )
for ( V_208 = 0 ; V_208 < V_2 -> V_21 . V_24 ; V_208 ++ )
F_5 ( V_2 , F_36 ( V_209 , V_208 ) ,
0 ) ;
return 0 ;
}
static T_3 F_39 ( struct V_1 * V_2 , T_1 V_109 , T_5 * V_210 )
{
T_1 V_211 ;
F_5 ( V_2 , V_212 ,
V_213 | ( V_109 << 8 ) ) ;
F_30 ( V_2 ) ;
F_31 ( 10 ) ;
V_211 = F_2 ( V_2 , V_212 ) ;
* V_210 = ( T_5 ) V_211 ;
return 0 ;
}
static T_3 F_40 ( struct V_1 * V_2 , T_1 V_109 , T_5 V_210 )
{
T_1 V_211 ;
V_211 = ( V_109 << 8 ) | V_210 ;
F_5 ( V_2 , V_212 , V_211 ) ;
F_30 ( V_2 ) ;
F_31 ( 10 ) ;
return 0 ;
}
static T_3 F_41 ( struct V_1 * V_2 , T_5 V_214 ,
T_5 * V_215 )
{
T_3 V_69 = 0 ;
T_2 V_216 = 0 ;
T_2 V_217 = 0 ;
T_2 V_218 = 0 ;
T_1 V_60 ;
if ( V_2 -> V_34 . type == V_52 ) {
V_216 = ( V_219 << 8 ) + V_214 ;
V_216 = ( V_216 | V_220 ) ;
V_2 -> V_34 . V_38 . V_221 ( V_2 ,
V_222 ,
V_155 ,
V_216 ) ;
for ( V_60 = 0 ; V_60 < 100 ; V_60 ++ ) {
V_2 -> V_34 . V_38 . V_147 ( V_2 ,
V_223 ,
V_155 ,
& V_218 ) ;
V_218 = V_218 & V_224 ;
if ( V_218 != V_225 )
break;
F_42 ( 10000 , 20000 ) ;
}
if ( V_218 != V_226 ) {
F_20 ( V_2 , L_6 ) ;
V_69 = V_182 ;
goto V_10;
}
V_2 -> V_34 . V_38 . V_147 ( V_2 , V_227 ,
V_155 , & V_217 ) ;
* V_215 = ( T_5 ) ( V_217 >> 8 ) ;
} else {
V_69 = V_228 ;
goto V_10;
}
V_10:
return V_69 ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
T_1 V_229 = V_230 ;
T_1 V_70 = F_2 ( V_2 , V_73 ) ;
T_1 V_231 = V_70 & V_232 ;
T_1 V_233 = V_70 & V_234 ;
T_2 V_235 = 0 ;
V_2 -> V_34 . V_38 . V_39 ( V_2 ) ;
switch ( V_2 -> V_34 . type ) {
case V_46 :
case V_88 :
V_2 -> V_34 . V_38 . V_147 ( V_2 , V_236 ,
V_155 , & V_235 ) ;
if ( V_235 & V_237 )
V_229 |= V_238 ;
if ( V_235 & V_239 )
V_229 |= V_240 ;
if ( V_235 & V_241 )
V_229 |= V_242 ;
goto V_10;
default:
break;
}
switch ( V_70 & V_74 ) {
case V_79 :
case V_75 :
if ( V_233 == V_243 )
V_229 = V_244 ;
else
V_229 = V_245 ;
break;
case V_77 :
if ( V_231 == V_246 )
V_229 = V_247 ;
else if ( V_231 == V_248 )
V_229 = V_249 ;
else
V_229 = V_230 ;
break;
case V_80 :
case V_81 :
if ( V_70 & V_84 )
V_229 |= V_244 ;
if ( V_70 & V_83 )
V_229 |= V_249 ;
break;
default:
break;
}
if ( V_2 -> V_34 . type == V_52 ) {
V_2 -> V_34 . V_38 . V_55 ( V_2 ) ;
switch ( V_2 -> V_34 . V_56 ) {
case V_250 :
V_229 = V_251 ;
break;
case V_252 :
V_229 = V_253 ;
break;
case V_254 :
V_229 = V_255 ;
break;
default:
V_229 = V_230 ;
break;
}
}
switch ( V_2 -> V_89 ) {
case V_95 :
V_229 = V_251 ;
break;
case V_93 :
case V_94 :
case V_96 :
V_229 = V_253 ;
break;
case V_97 :
V_229 = V_255 ;
break;
default:
break;
}
V_10:
return V_229 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_256 * V_257 = & V_2 -> V_257 ;
T_2 V_258 = 0 ;
T_2 V_259 = 0 ;
F_45 ( V_2 ) ;
V_2 -> V_260 . V_38 . V_261 ( V_2 , V_262 , & V_258 ) ;
if ( ( V_258 != 0 ) && ( V_258 != 0xFFFF ) ) {
V_2 -> V_260 . V_38 . V_261 ( V_2 , V_258 + V_263 , & V_259 ) ;
if ( ( V_259 & V_264 ) &&
! ( V_259 & V_265 ) &&
! ( V_259 & V_266 ) ) {
V_257 -> V_267 = 0 ;
}
}
}
static void F_46 ( struct V_1 * V_2 , int V_268 , T_1 V_269 ,
int V_270 )
{
T_1 V_271 = V_272 ;
T_5 V_60 = 0 ;
if ( ! V_268 )
return;
switch ( V_270 ) {
case V_273 :
V_271 = V_274 ;
for (; V_60 < 4 ; V_60 ++ )
F_5 ( V_2 , F_47 ( V_60 ) , V_271 ) ;
V_271 = V_275 ;
case V_276 :
default:
for (; V_60 < V_277 ; V_60 ++ )
F_5 ( V_2 , F_47 ( V_60 ) , V_271 ) ;
break;
}
for ( V_60 = 0 ; V_60 < V_277 ; V_60 ++ )
F_5 ( V_2 , F_48 ( V_60 ) , V_278 ) ;
return;
}
