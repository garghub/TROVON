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
case V_89 :
V_87 = V_41 ;
goto V_10;
default:
break;
}
switch ( V_2 -> V_90 ) {
case V_91 :
case V_92 :
V_87 = V_93 ;
break;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_87 = V_100 ;
break;
case V_101 :
case V_102 :
V_87 = V_103 ;
break;
case V_104 :
case V_105 :
V_87 = V_41 ;
break;
default:
V_87 = V_106 ;
break;
}
V_10:
return V_87 ;
}
static T_3 F_17 ( struct V_1 * V_2 , T_3 V_107 )
{
T_3 V_35 = 0 ;
T_1 V_108 ;
T_1 V_109 ;
T_1 V_110 ;
T_1 V_111 ;
T_1 V_112 = 0 ;
bool V_113 ;
#ifdef F_18
if ( V_2 -> V_114 . V_115 == V_116 )
goto V_10;
#endif
V_2 -> V_21 . V_38 . V_48 ( V_2 , & V_112 , & V_113 , false ) ;
if ( V_113 && V_112 == V_76 ) {
switch ( V_2 -> V_114 . V_115 ) {
case V_117 :
V_2 -> V_114 . V_115 = V_118 ;
break;
case V_119 :
V_2 -> V_114 . V_115 = V_120 ;
break;
default:
break;
}
}
V_35 = F_19 ( V_2 ) ;
if ( V_35 == V_121 )
goto V_10;
V_108 = F_2 ( V_2 , V_122 ) ;
V_108 &= ~ ( V_123 | V_124 ) ;
V_109 = F_2 ( V_2 , V_125 ) ;
V_109 &= ~ ( V_126 | V_127 ) ;
switch ( V_2 -> V_114 . V_128 ) {
case V_120 :
break;
case V_119 :
V_108 |= V_123 ;
break;
case V_118 :
V_109 |= V_127 ;
break;
case V_117 :
V_108 |= V_123 ;
V_109 |= V_127 ;
break;
#ifdef F_18
case V_116 :
goto V_10;
break;
#endif
default:
F_20 ( V_2 , L_1 ) ;
V_35 = V_129 ;
goto V_10;
break;
}
V_108 |= V_130 ;
F_5 ( V_2 , V_122 , V_108 ) ;
F_5 ( V_2 , V_125 , V_109 ) ;
if ( V_2 -> V_114 . V_128 & V_118 ) {
V_111 = F_2 ( V_2 , F_21 ( V_107 ) ) ;
V_111 >>= V_131 ;
V_110 = ( V_111 - V_2 -> V_114 . V_132 ) << 6 ;
if ( V_2 -> V_114 . V_133 )
V_110 |= V_134 ;
F_5 ( V_2 , F_22 ( V_107 ) , V_110 ) ;
V_110 = ( V_111 - V_2 -> V_114 . V_135 ) << 6 ;
V_110 |= V_136 ;
F_5 ( V_2 , F_23 ( V_107 ) , V_110 ) ;
}
V_110 = F_2 ( V_2 , F_24 ( V_107 / 2 ) ) ;
if ( ( V_107 & 1 ) == 0 )
V_110 = ( V_110 & 0xFFFF0000 ) | V_2 -> V_114 . V_137 ;
else
V_110 = ( V_110 & 0x0000FFFF ) | ( V_2 -> V_114 . V_137 << 16 ) ;
F_5 ( V_2 , F_24 ( V_107 / 2 ) , V_110 ) ;
F_5 ( V_2 , V_138 , ( V_2 -> V_114 . V_137 >> 1 ) ) ;
V_10:
return V_35 ;
}
static T_3 F_25 ( struct V_1 * V_2 ,
bool V_139 )
{
T_1 V_140 ;
T_1 V_141 ;
T_1 V_60 ;
T_3 V_69 = 0 ;
V_140 = F_2 ( V_2 , V_73 ) ;
V_140 |= V_142 ;
F_5 ( V_2 , V_73 , V_140 ) ;
if ( V_139 ) {
if ( ( V_140 & V_74 ) ==
V_80 ||
( V_140 & V_74 ) ==
V_81 ) {
V_141 = 0 ;
for ( V_60 = 0 ; V_60 < V_143 ; V_60 ++ ) {
V_141 = F_2 ( V_2 , V_144 ) ;
if ( V_141 & V_145 )
break;
F_26 ( 100 ) ;
}
if ( ! ( V_141 & V_145 ) ) {
V_69 = V_146 ;
F_20 ( V_2 , L_2 ) ;
}
}
}
F_26 ( 50 ) ;
return V_69 ;
}
static T_3 F_27 ( struct V_1 * V_2 )
{
T_1 V_147 ;
T_2 V_148 ;
if ( V_2 -> V_90 != V_105 )
return 0 ;
for ( V_147 = 0 ;
V_147 < V_149 ; V_147 ++ ) {
V_2 -> V_34 . V_38 . V_150 ( V_2 , V_151 , V_152 , & V_148 ) ;
if ( ( V_148 & V_153 ) &&
( V_148 & V_154 ) )
break;
F_26 ( 100 ) ;
}
if ( V_147 == V_149 ) {
F_20 ( V_2 , L_3 ) ;
return V_85 ;
}
return 0 ;
}
static T_3 F_28 ( struct V_1 * V_2 ,
T_4 * V_67 , bool * V_113 ,
bool V_155 )
{
T_1 V_141 ;
T_1 V_60 ;
T_2 V_156 , V_157 ;
if ( V_2 -> V_34 . type == V_52 ) {
V_2 -> V_34 . V_38 . V_150 ( V_2 , 0xC79F , V_158 , & V_156 ) ;
V_2 -> V_34 . V_38 . V_150 ( V_2 , 0xC79F , V_158 , & V_156 ) ;
V_2 -> V_34 . V_38 . V_150 ( V_2 , 0xC00C , V_158 ,
& V_157 ) ;
if ( V_155 ) {
for ( V_60 = 0 ; V_60 < V_159 ; V_60 ++ ) {
if ( ( V_156 & 1 ) &&
( ( V_157 & 1 ) == 0 ) ) {
* V_113 = true ;
break;
} else {
* V_113 = false ;
}
F_26 ( 100 ) ;
V_2 -> V_34 . V_38 . V_150 ( V_2 , 0xC79F ,
V_158 ,
& V_156 ) ;
V_2 -> V_34 . V_38 . V_150 ( V_2 , 0xC00C ,
V_158 ,
& V_157 ) ;
}
} else {
if ( ( V_156 & 1 ) && ( ( V_157 & 1 ) == 0 ) )
* V_113 = true ;
else
* V_113 = false ;
}
if ( * V_113 == false )
goto V_10;
}
V_141 = F_2 ( V_2 , V_144 ) ;
if ( V_155 ) {
for ( V_60 = 0 ; V_60 < V_159 ; V_60 ++ ) {
if ( V_141 & V_160 ) {
* V_113 = true ;
break;
} else {
* V_113 = false ;
}
F_26 ( 100 ) ;
V_141 = F_2 ( V_2 , V_144 ) ;
}
} else {
if ( V_141 & V_160 )
* V_113 = true ;
else
* V_113 = false ;
}
if ( V_141 & V_161 )
* V_67 = V_78 ;
else
* V_67 = V_76 ;
if ( ( V_2 -> V_90 == V_105 ) && ( * V_113 == true ) &&
( F_27 ( V_2 ) != 0 ) )
* V_113 = false ;
if ( * V_113 == false ) {
V_2 -> V_114 . V_128 = V_120 ;
V_2 -> V_114 . V_162 = false ;
}
V_10:
return 0 ;
}
static T_3 F_29 ( struct V_1 * V_2 ,
T_4 V_67 , bool V_68 ,
bool V_139 )
{
T_3 V_69 = 0 ;
T_4 V_163 = V_82 ;
T_1 V_164 = F_2 ( V_2 , V_73 ) ;
T_1 V_70 = V_164 ;
T_1 V_165 = V_70 & V_74 ;
F_15 ( V_2 , & V_163 , & V_68 ) ;
V_67 &= V_163 ;
if ( V_67 == V_82 )
V_69 = V_85 ;
else if ( V_165 == V_80 ||
V_165 == V_81 ) {
V_70 &= ~ V_166 ;
if ( V_67 & V_78 )
V_70 |= V_83 ;
if ( V_67 & V_76 )
V_70 |= V_84 ;
if ( V_70 != V_164 )
F_5 ( V_2 , V_73 , V_70 ) ;
}
if ( V_69 == 0 ) {
V_69 = F_25 ( V_2 ,
V_139 ) ;
}
return V_69 ;
}
static T_3 V_43 ( struct V_1 * V_2 ,
T_4 V_67 ,
bool V_68 ,
bool V_139 )
{
T_3 V_69 ;
V_69 = V_2 -> V_34 . V_38 . V_167 ( V_2 , V_67 , V_68 ,
V_139 ) ;
F_25 ( V_2 , V_139 ) ;
return V_69 ;
}
static T_3 F_30 ( struct V_1 * V_2 )
{
T_3 V_69 = 0 ;
T_3 V_168 = 0 ;
T_1 V_169 ;
T_1 V_170 ;
T_1 V_60 ;
T_1 V_70 ;
T_5 V_171 ;
V_2 -> V_21 . V_38 . V_172 ( V_2 ) ;
V_2 -> V_21 . V_38 . V_173 ( V_2 , V_174 , & V_171 ) ;
if ( V_171 & V_175 ) {
V_2 -> V_21 . V_38 . V_173 ( V_2 , V_174 ,
& V_171 ) ;
V_171 &= ~ V_175 ;
V_2 -> V_21 . V_38 . V_176 ( V_2 , V_174 ,
V_171 ) ;
V_2 -> V_21 . V_38 . V_173 ( V_2 , V_177 ,
& V_171 ) ;
V_171 &= ~ V_178 ;
V_2 -> V_21 . V_38 . V_176 ( V_2 , V_177 ,
V_171 ) ;
V_2 -> V_21 . V_38 . V_173 ( V_2 , V_179 ,
& V_171 ) ;
V_171 &= ~ V_180 ;
V_2 -> V_21 . V_38 . V_176 ( V_2 , V_179 ,
V_171 ) ;
V_2 -> V_21 . V_38 . V_173 ( V_2 , V_181 ,
& V_171 ) ;
V_171 &= ~ V_182 ;
V_2 -> V_21 . V_38 . V_176 ( V_2 , V_181 ,
V_171 ) ;
}
if ( V_2 -> V_34 . V_183 == false ) {
V_168 = V_2 -> V_34 . V_38 . V_184 ( V_2 ) ;
if ( V_168 == V_58 )
goto V_185;
else if ( V_168 == V_186 )
goto V_187;
V_2 -> V_34 . V_38 . V_53 ( V_2 ) ;
}
V_187:
F_31 ( V_2 ) ;
V_188:
V_169 = F_2 ( V_2 , V_189 ) ;
F_5 ( V_2 , V_189 , ( V_169 | V_190 ) ) ;
F_32 ( V_2 ) ;
for ( V_60 = 0 ; V_60 < 10 ; V_60 ++ ) {
F_33 ( 1 ) ;
V_169 = F_2 ( V_2 , V_189 ) ;
if ( ! ( V_169 & V_190 ) )
break;
}
if ( V_169 & V_190 ) {
V_69 = V_191 ;
F_20 ( V_2 , L_4 ) ;
}
if ( V_2 -> V_21 . V_192 & V_193 ) {
V_2 -> V_21 . V_192 &= ~ V_193 ;
F_33 ( 1 ) ;
goto V_188;
}
F_26 ( 50 ) ;
V_170 = F_2 ( V_2 , V_194 ) ;
V_170 &= ~ ( ( 1 << 21 ) | ( 1 << 18 ) | ( 1 << 9 ) | ( 1 << 6 ) ) ;
F_5 ( V_2 , V_194 , V_170 ) ;
V_70 = F_2 ( V_2 , V_73 ) ;
if ( V_2 -> V_21 . V_71 == false ) {
V_2 -> V_21 . V_72 = V_70 ;
V_2 -> V_21 . V_71 = true ;
} else if ( V_70 != V_2 -> V_21 . V_72 ) {
F_5 ( V_2 , V_73 , V_2 -> V_21 . V_72 ) ;
}
V_2 -> V_21 . V_38 . V_195 ( V_2 , V_2 -> V_21 . V_196 ) ;
V_2 -> V_21 . V_38 . V_197 ( V_2 ) ;
V_185:
if ( V_168 )
V_69 = V_168 ;
return V_69 ;
}
static T_3 F_34 ( struct V_1 * V_2 , T_1 V_198 , T_1 V_199 )
{
T_1 V_200 ;
T_1 V_201 = V_2 -> V_21 . V_26 ;
if ( V_198 >= V_201 ) {
F_20 ( V_2 , L_5 , V_198 ) ;
return V_202 ;
}
V_200 = F_2 ( V_2 , F_35 ( V_198 ) ) ;
V_200 &= ~ V_203 ;
V_200 |= ( ( V_199 << V_204 ) & V_203 ) ;
F_5 ( V_2 , F_35 ( V_198 ) , V_200 ) ;
return 0 ;
}
static T_3 F_36 ( struct V_1 * V_2 , T_1 V_198 , T_1 V_199 )
{
T_1 V_200 ;
T_1 V_201 = V_2 -> V_21 . V_26 ;
if ( V_198 >= V_201 ) {
F_20 ( V_2 , L_5 , V_198 ) ;
return V_202 ;
}
V_200 = F_2 ( V_2 , F_35 ( V_198 ) ) ;
if ( V_200 & V_203 ) {
V_200 &= ~ V_203 ;
F_5 ( V_2 , F_35 ( V_198 ) , V_200 ) ;
}
return 0 ;
}
static T_3 F_37 ( struct V_1 * V_2 , T_1 V_205 , T_1 V_206 ,
bool V_207 )
{
T_1 V_208 ;
T_1 V_209 ;
T_1 V_210 ;
T_1 V_211 ;
if ( V_205 > 4095 )
return V_212 ;
V_208 = ( V_205 >> 5 ) & 0x7F ;
V_211 = ( ( V_205 >> 3 ) & 0x03 ) ;
V_209 = ( V_205 & 0x7 ) << 2 ;
V_210 = F_2 ( V_2 , F_38 ( V_211 , V_208 ) ) ;
V_210 &= ( ~ ( 0x0F << V_209 ) ) ;
V_210 |= ( V_206 << V_209 ) ;
F_5 ( V_2 , F_38 ( V_211 , V_208 ) , V_210 ) ;
V_209 = V_205 & 0x1F ;
V_210 = F_2 ( V_2 , F_39 ( V_208 ) ) ;
if ( V_207 )
V_210 |= ( 1 << V_209 ) ;
else
V_210 &= ~ ( 1 << V_209 ) ;
F_5 ( V_2 , F_39 ( V_208 ) , V_210 ) ;
return 0 ;
}
static T_3 F_40 ( struct V_1 * V_2 )
{
T_1 V_213 ;
T_1 V_214 ;
for ( V_213 = 0 ; V_213 < V_2 -> V_21 . V_24 ; V_213 ++ )
F_5 ( V_2 , F_39 ( V_213 ) , 0 ) ;
for ( V_214 = 0 ; V_214 < 4 ; V_214 ++ )
for ( V_213 = 0 ; V_213 < V_2 -> V_21 . V_24 ; V_213 ++ )
F_5 ( V_2 , F_38 ( V_214 , V_213 ) ,
0 ) ;
return 0 ;
}
static T_3 F_41 ( struct V_1 * V_2 , T_1 V_110 , T_5 * V_215 )
{
T_1 V_216 ;
F_5 ( V_2 , V_217 ,
V_218 | ( V_110 << 8 ) ) ;
F_32 ( V_2 ) ;
F_33 ( 10 ) ;
V_216 = F_2 ( V_2 , V_217 ) ;
* V_215 = ( T_5 ) V_216 ;
return 0 ;
}
static T_3 F_42 ( struct V_1 * V_2 , T_1 V_110 , T_5 V_215 )
{
T_1 V_216 ;
V_216 = ( V_110 << 8 ) | V_215 ;
F_5 ( V_2 , V_217 , V_216 ) ;
F_32 ( V_2 ) ;
F_33 ( 10 ) ;
return 0 ;
}
static T_3 F_43 ( struct V_1 * V_2 , T_5 V_219 ,
T_5 * V_220 )
{
T_3 V_69 = 0 ;
T_2 V_221 = 0 ;
T_2 V_222 = 0 ;
T_2 V_223 = 0 ;
T_1 V_60 ;
if ( V_2 -> V_34 . type == V_52 ) {
V_221 = ( V_224 << 8 ) + V_219 ;
V_221 = ( V_221 | V_225 ) ;
V_2 -> V_34 . V_38 . V_226 ( V_2 ,
V_227 ,
V_158 ,
V_221 ) ;
for ( V_60 = 0 ; V_60 < 100 ; V_60 ++ ) {
V_2 -> V_34 . V_38 . V_150 ( V_2 ,
V_228 ,
V_158 ,
& V_223 ) ;
V_223 = V_223 & V_229 ;
if ( V_223 != V_230 )
break;
F_44 ( 10000 , 20000 ) ;
}
if ( V_223 != V_231 ) {
F_20 ( V_2 , L_6 ) ;
V_69 = V_186 ;
goto V_10;
}
V_2 -> V_34 . V_38 . V_150 ( V_2 , V_232 ,
V_158 , & V_222 ) ;
* V_220 = ( T_5 ) ( V_222 >> 8 ) ;
} else {
V_69 = V_233 ;
goto V_10;
}
V_10:
return V_69 ;
}
static T_1 F_45 ( struct V_1 * V_2 )
{
T_1 V_234 = V_235 ;
T_1 V_70 = F_2 ( V_2 , V_73 ) ;
T_1 V_236 = V_70 & V_237 ;
T_1 V_238 = V_70 & V_239 ;
T_2 V_240 = 0 ;
V_2 -> V_34 . V_38 . V_39 ( V_2 ) ;
switch ( V_2 -> V_34 . type ) {
case V_46 :
case V_89 :
case V_88 :
V_2 -> V_34 . V_38 . V_150 ( V_2 , V_241 ,
V_158 , & V_240 ) ;
if ( V_240 & V_242 )
V_234 |= V_243 ;
if ( V_240 & V_244 )
V_234 |= V_245 ;
if ( V_240 & V_246 )
V_234 |= V_247 ;
goto V_10;
default:
break;
}
switch ( V_70 & V_74 ) {
case V_79 :
case V_75 :
if ( V_238 == V_248 )
V_234 = V_249 ;
else
V_234 = V_250 ;
break;
case V_77 :
if ( V_236 == V_251 )
V_234 = V_252 ;
else if ( V_236 == V_253 )
V_234 = V_254 ;
else
V_234 = V_235 ;
break;
case V_80 :
case V_81 :
if ( V_70 & V_84 )
V_234 |= V_249 ;
if ( V_70 & V_83 )
V_234 |= V_254 ;
break;
default:
break;
}
if ( V_2 -> V_34 . type == V_52 ) {
V_2 -> V_34 . V_38 . V_55 ( V_2 ) ;
switch ( V_2 -> V_34 . V_56 ) {
case V_255 :
V_234 = V_256 ;
break;
case V_257 :
V_234 = V_258 ;
break;
case V_259 :
V_234 = V_260 ;
break;
default:
V_234 = V_235 ;
break;
}
}
switch ( V_2 -> V_90 ) {
case V_96 :
V_234 = V_256 ;
break;
case V_94 :
case V_95 :
case V_97 :
V_234 = V_258 ;
break;
case V_98 :
V_234 = V_260 ;
break;
default:
break;
}
V_10:
return V_234 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_261 * V_262 = & V_2 -> V_262 ;
T_2 V_263 = 0 ;
T_2 V_264 = 0 ;
F_47 ( V_2 ) ;
V_2 -> V_265 . V_38 . V_266 ( V_2 , V_267 , & V_263 ) ;
if ( ( V_263 != 0 ) && ( V_263 != 0xFFFF ) ) {
V_2 -> V_265 . V_38 . V_266 ( V_2 , V_263 + V_268 , & V_264 ) ;
if ( ( V_264 & V_269 ) &&
! ( V_264 & V_270 ) &&
! ( V_264 & V_271 ) ) {
V_262 -> V_272 = 0 ;
}
}
}
static void F_48 ( struct V_1 * V_2 , int V_273 , T_1 V_274 ,
int V_275 )
{
T_1 V_276 = V_277 ;
T_5 V_60 = 0 ;
if ( ! V_273 )
return;
switch ( V_275 ) {
case V_278 :
V_276 = V_279 ;
for (; V_60 < 4 ; V_60 ++ )
F_5 ( V_2 , F_21 ( V_60 ) , V_276 ) ;
V_276 = V_280 ;
case V_281 :
default:
for (; V_60 < V_282 ; V_60 ++ )
F_5 ( V_2 , F_21 ( V_60 ) , V_276 ) ;
break;
}
for ( V_60 = 0 ; V_60 < V_282 ; V_60 ++ )
F_5 ( V_2 , F_49 ( V_60 ) , V_283 ) ;
return;
}
