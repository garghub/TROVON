static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_4 ) ;
T_2 V_5 ;
if ( F_3 ( V_2 -> V_6 ) )
return;
if ( V_3 & V_7 )
goto V_8;
if ( ! ( V_3 & V_9 ) ) {
V_3 |= V_10 ;
goto V_8;
}
V_5 = F_4 ( V_2 , V_11 ) ;
V_5 |= V_12 ;
F_5 ( V_2 , V_11 , V_5 ) ;
V_8:
V_3 &= ~ V_13 ;
F_6 ( V_2 , V_4 , V_3 ) ;
}
static T_3 F_7 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
F_8 ( V_2 ) ;
V_15 -> V_16 = V_17 ;
V_15 -> V_18 = V_19 ;
V_15 -> V_20 = V_21 ;
V_15 -> V_22 = V_23 ;
V_15 -> V_24 = V_25 ;
V_15 -> V_26 = V_27 ;
V_15 -> V_28 = F_9 ( V_2 ) ;
return 0 ;
}
static T_3 F_10 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
struct V_29 * V_30 = & V_2 -> V_30 ;
T_3 V_31 = 0 ;
T_2 V_32 , V_33 ;
V_30 -> V_34 . V_35 ( V_2 ) ;
if ( V_15 -> V_34 . V_36 ( V_2 ) == V_37 ) {
V_15 -> V_34 . V_38 = & V_39 ;
V_15 -> V_34 . V_40 =
& V_41 ;
}
switch ( V_2 -> V_30 . type ) {
case V_42 :
V_30 -> V_34 . V_38 = & V_43 ;
V_30 -> V_34 . V_44 = & V_45 ;
V_30 -> V_34 . V_46 =
& V_47 ;
break;
case V_48 :
V_30 -> V_34 . V_49 = & V_50 ;
V_31 = V_30 -> V_34 . V_51 ( V_2 ) ;
if ( V_31 != 0 )
goto V_8;
else if ( V_2 -> V_30 . V_52 == V_53 ) {
V_31 = V_54 ;
goto V_8;
}
V_31 = F_11 ( V_2 ,
& V_32 ,
& V_33 ) ;
if ( V_31 != 0 ) {
V_31 = V_54 ;
goto V_8;
}
break;
default:
break;
}
V_8:
return V_31 ;
}
static T_3 F_12 ( struct V_1 * V_2 )
{
T_1 V_55 ;
T_1 V_56 ;
T_3 V_31 = 0 ;
V_31 = F_13 ( V_2 ) ;
for ( V_56 = 0 ; ( ( V_56 < V_2 -> V_15 . V_26 ) &&
( V_56 < V_57 ) ) ; V_56 ++ ) {
V_55 = F_2 ( V_2 , F_14 ( V_56 ) ) ;
V_55 &= ~ V_58 ;
F_6 ( V_2 , F_14 ( V_56 ) , V_55 ) ;
}
for ( V_56 = 0 ; ( ( V_56 < V_2 -> V_15 . V_24 ) &&
( V_56 < V_57 ) ) ; V_56 ++ ) {
V_55 = F_2 ( V_2 , F_15 ( V_56 ) ) ;
V_55 &= ~ ( V_59 |
V_60 ) ;
F_6 ( V_2 , F_15 ( V_56 ) , V_55 ) ;
}
if ( V_31 == 0 )
F_1 ( V_2 ) ;
return V_31 ;
}
static T_3 F_16 ( struct V_1 * V_2 ,
T_4 * V_61 ,
bool * V_62 )
{
T_3 V_63 = 0 ;
T_1 V_64 = 0 ;
if ( V_2 -> V_15 . V_65 )
V_64 = V_2 -> V_15 . V_66 ;
else
V_64 = F_2 ( V_2 , V_67 ) ;
switch ( V_64 & V_68 ) {
case V_69 :
* V_61 = V_70 ;
* V_62 = false ;
break;
case V_71 :
* V_61 = V_72 ;
* V_62 = false ;
break;
case V_73 :
* V_61 = V_70 ;
* V_62 = true ;
break;
case V_74 :
case V_75 :
* V_61 = V_76 ;
if ( V_64 & V_77 )
* V_61 |= V_72 ;
if ( V_64 & V_78 )
* V_61 |= V_70 ;
* V_62 = true ;
break;
default:
V_63 = V_79 ;
break;
}
return V_63 ;
}
static enum V_80 F_17 ( struct V_1 * V_2 )
{
enum V_80 V_81 ;
switch ( V_2 -> V_30 . type ) {
case V_82 :
case V_42 :
V_81 = V_37 ;
goto V_8;
default:
break;
}
switch ( V_2 -> V_83 ) {
case V_84 :
case V_85 :
V_81 = V_86 ;
break;
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
V_81 = V_93 ;
break;
case V_94 :
case V_95 :
V_81 = V_96 ;
break;
case V_97 :
case V_98 :
V_81 = V_37 ;
break;
default:
V_81 = V_99 ;
break;
}
V_8:
return V_81 ;
}
static T_3 F_18 ( struct V_1 * V_2 )
{
T_3 V_31 = 0 ;
T_1 V_100 ;
T_1 V_101 ;
T_1 V_102 ;
T_1 V_103 , V_104 ;
T_1 V_105 = 0 ;
int V_56 ;
bool V_106 ;
if ( ! V_2 -> V_107 . V_108 ) {
V_31 = V_109 ;
goto V_8;
}
for ( V_56 = 0 ; V_56 < V_110 ; V_56 ++ ) {
if ( ( V_2 -> V_107 . V_111 & V_112 ) &&
V_2 -> V_107 . V_113 [ V_56 ] ) {
if ( ! V_2 -> V_107 . V_114 [ V_56 ] ||
V_2 -> V_107 . V_114 [ V_56 ] >= V_2 -> V_107 . V_113 [ V_56 ] ) {
F_19 ( V_2 , L_1 ) ;
V_31 = V_109 ;
goto V_8;
}
}
}
V_2 -> V_15 . V_34 . V_44 ( V_2 , & V_105 , & V_106 , false ) ;
if ( V_106 && V_105 == V_70 ) {
switch ( V_2 -> V_107 . V_115 ) {
case V_116 :
V_2 -> V_107 . V_115 = V_112 ;
break;
case V_117 :
V_2 -> V_107 . V_115 = V_118 ;
break;
default:
break;
}
}
F_20 ( V_2 ) ;
V_100 = F_2 ( V_2 , V_119 ) ;
V_100 &= ~ ( V_120 | V_121 ) ;
V_101 = F_2 ( V_2 , V_122 ) ;
V_101 &= ~ ( V_123 | V_124 ) ;
switch ( V_2 -> V_107 . V_111 ) {
case V_118 :
break;
case V_117 :
V_100 |= V_120 ;
break;
case V_112 :
V_101 |= V_124 ;
break;
case V_116 :
V_100 |= V_120 ;
V_101 |= V_124 ;
break;
default:
F_19 ( V_2 , L_2 ) ;
V_31 = V_125 ;
goto V_8;
break;
}
V_100 |= V_126 ;
F_6 ( V_2 , V_119 , V_100 ) ;
F_6 ( V_2 , V_122 , V_101 ) ;
for ( V_56 = 0 ; V_56 < V_110 ; V_56 ++ ) {
if ( ( V_2 -> V_107 . V_111 & V_112 ) &&
V_2 -> V_107 . V_113 [ V_56 ] ) {
V_103 = ( V_2 -> V_107 . V_114 [ V_56 ] << 10 ) | V_127 ;
V_104 = ( V_2 -> V_107 . V_113 [ V_56 ] << 10 ) | V_128 ;
F_6 ( V_2 , F_21 ( V_56 ) , V_103 ) ;
F_6 ( V_2 , F_22 ( V_56 ) , V_104 ) ;
} else {
F_6 ( V_2 , F_21 ( V_56 ) , 0 ) ;
F_6 ( V_2 , F_22 ( V_56 ) , 0 ) ;
}
}
V_102 = V_2 -> V_107 . V_108 * 0x00010001 ;
for ( V_56 = 0 ; V_56 < ( V_110 / 2 ) ; V_56 ++ )
F_6 ( V_2 , F_23 ( V_56 ) , V_102 ) ;
F_6 ( V_2 , V_129 , V_2 -> V_107 . V_108 / 2 ) ;
V_8:
return V_31 ;
}
static T_3 F_24 ( struct V_1 * V_2 ,
bool V_130 )
{
T_1 V_131 ;
T_1 V_132 ;
T_1 V_56 ;
T_3 V_63 = 0 ;
V_131 = F_2 ( V_2 , V_67 ) ;
V_131 |= V_133 ;
F_6 ( V_2 , V_67 , V_131 ) ;
if ( V_130 ) {
if ( ( V_131 & V_68 ) ==
V_74 ||
( V_131 & V_68 ) ==
V_75 ) {
V_132 = 0 ;
for ( V_56 = 0 ; V_56 < V_134 ; V_56 ++ ) {
V_132 = F_2 ( V_2 , V_135 ) ;
if ( V_132 & V_136 )
break;
F_25 ( 100 ) ;
}
if ( ! ( V_132 & V_136 ) ) {
V_63 = V_137 ;
F_19 ( V_2 , L_3 ) ;
}
}
}
F_25 ( 50 ) ;
return V_63 ;
}
static T_3 F_26 ( struct V_1 * V_2 )
{
T_1 V_138 ;
T_2 V_139 ;
if ( V_2 -> V_83 != V_98 )
return 0 ;
for ( V_138 = 0 ;
V_138 < V_140 ; V_138 ++ ) {
V_2 -> V_30 . V_34 . V_141 ( V_2 , V_142 , V_143 , & V_139 ) ;
if ( ( V_139 & V_144 ) &&
( V_139 & V_145 ) )
break;
F_25 ( 100 ) ;
}
if ( V_138 == V_140 ) {
F_19 ( V_2 , L_4 ) ;
return V_79 ;
}
return 0 ;
}
static T_3 F_27 ( struct V_1 * V_2 ,
T_4 * V_61 , bool * V_106 ,
bool V_146 )
{
T_1 V_132 ;
T_1 V_56 ;
T_2 V_147 , V_148 ;
if ( V_2 -> V_30 . type == V_48 ) {
V_2 -> V_30 . V_34 . V_141 ( V_2 , 0xC79F , V_149 , & V_147 ) ;
V_2 -> V_30 . V_34 . V_141 ( V_2 , 0xC79F , V_149 , & V_147 ) ;
V_2 -> V_30 . V_34 . V_141 ( V_2 , 0xC00C , V_149 ,
& V_148 ) ;
if ( V_146 ) {
for ( V_56 = 0 ; V_56 < V_150 ; V_56 ++ ) {
if ( ( V_147 & 1 ) &&
( ( V_148 & 1 ) == 0 ) ) {
* V_106 = true ;
break;
} else {
* V_106 = false ;
}
F_25 ( 100 ) ;
V_2 -> V_30 . V_34 . V_141 ( V_2 , 0xC79F ,
V_149 ,
& V_147 ) ;
V_2 -> V_30 . V_34 . V_141 ( V_2 , 0xC00C ,
V_149 ,
& V_148 ) ;
}
} else {
if ( ( V_147 & 1 ) && ( ( V_148 & 1 ) == 0 ) )
* V_106 = true ;
else
* V_106 = false ;
}
if ( ! * V_106 )
goto V_8;
}
V_132 = F_2 ( V_2 , V_135 ) ;
if ( V_146 ) {
for ( V_56 = 0 ; V_56 < V_150 ; V_56 ++ ) {
if ( V_132 & V_151 ) {
* V_106 = true ;
break;
} else {
* V_106 = false ;
}
F_25 ( 100 ) ;
V_132 = F_2 ( V_2 , V_135 ) ;
}
} else {
if ( V_132 & V_151 )
* V_106 = true ;
else
* V_106 = false ;
}
if ( V_132 & V_152 )
* V_61 = V_72 ;
else
* V_61 = V_70 ;
if ( ( V_2 -> V_83 == V_98 ) && * V_106 &&
( F_26 ( V_2 ) != 0 ) )
* V_106 = false ;
V_8:
return 0 ;
}
static T_3 F_28 ( struct V_1 * V_2 ,
T_4 V_61 ,
bool V_130 )
{
bool V_62 = false ;
T_3 V_63 = 0 ;
T_4 V_153 = V_76 ;
T_1 V_154 = F_2 ( V_2 , V_67 ) ;
T_1 V_64 = V_154 ;
T_1 V_155 = V_64 & V_68 ;
F_16 ( V_2 , & V_153 , & V_62 ) ;
V_61 &= V_153 ;
if ( V_61 == V_76 )
V_63 = V_79 ;
else if ( V_155 == V_74 ||
V_155 == V_75 ) {
V_64 &= ~ V_156 ;
if ( V_61 & V_72 )
V_64 |= V_77 ;
if ( V_61 & V_70 )
V_64 |= V_78 ;
if ( V_64 != V_154 )
F_6 ( V_2 , V_67 , V_64 ) ;
}
if ( V_63 == 0 ) {
V_63 = F_24 ( V_2 ,
V_130 ) ;
}
return V_63 ;
}
static T_3 V_39 ( struct V_1 * V_2 ,
T_4 V_61 ,
bool V_130 )
{
T_3 V_63 ;
V_63 = V_2 -> V_30 . V_34 . V_157 ( V_2 , V_61 ,
V_130 ) ;
F_24 ( V_2 , V_130 ) ;
return V_63 ;
}
static T_3 F_29 ( struct V_1 * V_2 )
{
T_3 V_63 = 0 ;
T_3 V_158 = 0 ;
T_1 V_159 ;
T_1 V_160 ;
T_1 V_56 ;
T_1 V_64 ;
T_5 V_161 ;
V_63 = V_2 -> V_15 . V_34 . V_162 ( V_2 ) ;
if ( V_63 != 0 )
goto V_163;
V_2 -> V_15 . V_34 . V_164 ( V_2 , V_165 , & V_161 ) ;
if ( V_161 & V_166 ) {
V_2 -> V_15 . V_34 . V_164 ( V_2 , V_165 ,
& V_161 ) ;
V_161 &= ~ V_166 ;
V_2 -> V_15 . V_34 . V_167 ( V_2 , V_165 ,
V_161 ) ;
V_2 -> V_15 . V_34 . V_164 ( V_2 , V_168 ,
& V_161 ) ;
V_161 &= ~ V_169 ;
V_2 -> V_15 . V_34 . V_167 ( V_2 , V_168 ,
V_161 ) ;
V_2 -> V_15 . V_34 . V_164 ( V_2 , V_170 ,
& V_161 ) ;
V_161 &= ~ V_171 ;
V_2 -> V_15 . V_34 . V_167 ( V_2 , V_170 ,
V_161 ) ;
V_2 -> V_15 . V_34 . V_164 ( V_2 , V_172 ,
& V_161 ) ;
V_161 &= ~ V_173 ;
V_2 -> V_15 . V_34 . V_167 ( V_2 , V_172 ,
V_161 ) ;
}
if ( V_2 -> V_30 . V_174 == false ) {
V_158 = V_2 -> V_30 . V_34 . V_175 ( V_2 ) ;
if ( V_158 == V_54 )
goto V_163;
if ( V_158 == V_176 )
goto V_177;
V_2 -> V_30 . V_34 . V_49 ( V_2 ) ;
}
V_177:
V_159 = F_2 ( V_2 , V_178 ) | V_179 ;
F_6 ( V_2 , V_178 , V_159 ) ;
F_30 ( V_2 ) ;
for ( V_56 = 0 ; V_56 < 10 ; V_56 ++ ) {
F_31 ( 1 ) ;
V_159 = F_2 ( V_2 , V_178 ) ;
if ( ! ( V_159 & V_179 ) )
break;
}
if ( V_159 & V_179 ) {
V_63 = V_180 ;
F_19 ( V_2 , L_5 ) ;
}
F_25 ( 50 ) ;
if ( V_2 -> V_15 . V_181 & V_182 ) {
V_2 -> V_15 . V_181 &= ~ V_182 ;
goto V_177;
}
V_160 = F_2 ( V_2 , V_183 ) ;
V_160 &= ~ ( ( 1 << 21 ) | ( 1 << 18 ) | ( 1 << 9 ) | ( 1 << 6 ) ) ;
F_6 ( V_2 , V_183 , V_160 ) ;
V_64 = F_2 ( V_2 , V_67 ) ;
if ( V_2 -> V_15 . V_65 == false ) {
V_2 -> V_15 . V_66 = V_64 ;
V_2 -> V_15 . V_65 = true ;
} else if ( V_64 != V_2 -> V_15 . V_66 ) {
F_6 ( V_2 , V_67 , V_2 -> V_15 . V_66 ) ;
}
V_2 -> V_15 . V_34 . V_184 ( V_2 , V_2 -> V_15 . V_185 ) ;
V_2 -> V_15 . V_34 . V_186 ( V_2 ) ;
V_163:
if ( V_158 )
V_63 = V_158 ;
return V_63 ;
}
static T_3 F_32 ( struct V_1 * V_2 , T_1 V_187 , T_1 V_188 )
{
T_1 V_189 ;
T_1 V_190 = V_2 -> V_15 . V_20 ;
if ( V_187 >= V_190 ) {
F_19 ( V_2 , L_6 , V_187 ) ;
return V_191 ;
}
V_189 = F_2 ( V_2 , F_33 ( V_187 ) ) ;
V_189 &= ~ V_192 ;
V_189 |= ( ( V_188 << V_193 ) & V_192 ) ;
F_6 ( V_2 , F_33 ( V_187 ) , V_189 ) ;
return 0 ;
}
static T_3 F_34 ( struct V_1 * V_2 , T_1 V_187 , T_1 V_188 )
{
T_1 V_189 ;
T_1 V_190 = V_2 -> V_15 . V_20 ;
if ( V_187 >= V_190 ) {
F_19 ( V_2 , L_6 , V_187 ) ;
return V_191 ;
}
V_189 = F_2 ( V_2 , F_33 ( V_187 ) ) ;
if ( V_189 & V_192 ) {
V_189 &= ~ V_192 ;
F_6 ( V_2 , F_33 ( V_187 ) , V_189 ) ;
}
return 0 ;
}
static T_3 F_35 ( struct V_1 * V_2 , T_1 V_194 , T_1 V_195 ,
bool V_196 )
{
T_1 V_197 ;
T_1 V_198 ;
T_1 V_199 ;
T_1 V_200 ;
if ( V_194 > 4095 )
return V_201 ;
V_197 = ( V_194 >> 5 ) & 0x7F ;
V_200 = ( ( V_194 >> 3 ) & 0x03 ) ;
V_198 = ( V_194 & 0x7 ) << 2 ;
V_199 = F_2 ( V_2 , F_36 ( V_200 , V_197 ) ) ;
V_199 &= ( ~ ( 0x0F << V_198 ) ) ;
V_199 |= ( V_195 << V_198 ) ;
F_6 ( V_2 , F_36 ( V_200 , V_197 ) , V_199 ) ;
V_198 = V_194 & 0x1F ;
V_199 = F_2 ( V_2 , F_37 ( V_197 ) ) ;
if ( V_196 )
V_199 |= ( 1 << V_198 ) ;
else
V_199 &= ~ ( 1 << V_198 ) ;
F_6 ( V_2 , F_37 ( V_197 ) , V_199 ) ;
return 0 ;
}
static T_3 F_38 ( struct V_1 * V_2 )
{
T_1 V_202 ;
T_1 V_203 ;
for ( V_202 = 0 ; V_202 < V_2 -> V_15 . V_18 ; V_202 ++ )
F_6 ( V_2 , F_37 ( V_202 ) , 0 ) ;
for ( V_203 = 0 ; V_203 < 4 ; V_203 ++ )
for ( V_202 = 0 ; V_202 < V_2 -> V_15 . V_18 ; V_202 ++ )
F_6 ( V_2 , F_36 ( V_203 , V_202 ) ,
0 ) ;
return 0 ;
}
static T_3 F_39 ( struct V_1 * V_2 , T_1 V_102 , T_5 * V_204 )
{
T_1 V_205 ;
F_6 ( V_2 , V_206 ,
V_207 | ( V_102 << 8 ) ) ;
F_30 ( V_2 ) ;
F_31 ( 10 ) ;
V_205 = F_2 ( V_2 , V_206 ) ;
* V_204 = ( T_5 ) V_205 ;
return 0 ;
}
static T_3 F_40 ( struct V_1 * V_2 , T_1 V_102 , T_5 V_204 )
{
T_1 V_205 ;
V_205 = ( V_102 << 8 ) | V_204 ;
F_6 ( V_2 , V_206 , V_205 ) ;
F_30 ( V_2 ) ;
F_31 ( 10 ) ;
return 0 ;
}
static T_3 F_41 ( struct V_1 * V_2 , T_5 V_208 ,
T_5 V_209 , T_5 * V_210 )
{
T_3 V_63 = 0 ;
T_2 V_211 = 0 ;
T_2 V_212 = 0 ;
T_2 V_213 = 0 ;
T_2 V_214 ;
T_1 V_56 ;
if ( F_2 ( V_2 , V_215 ) & V_216 )
V_214 = V_217 ;
else
V_214 = V_218 ;
if ( V_2 -> V_15 . V_34 . V_219 ( V_2 , V_214 ) != 0 )
return V_220 ;
if ( V_2 -> V_30 . type == V_48 ) {
V_211 = ( V_208 << 8 ) + V_209 ;
V_211 = ( V_211 | V_221 ) ;
V_2 -> V_30 . V_34 . V_222 ( V_2 ,
V_223 ,
V_149 ,
V_211 ) ;
for ( V_56 = 0 ; V_56 < 100 ; V_56 ++ ) {
V_2 -> V_30 . V_34 . V_224 ( V_2 ,
V_225 ,
V_149 ,
& V_213 ) ;
V_213 = V_213 & V_226 ;
if ( V_213 != V_227 )
break;
F_42 ( 10000 , 20000 ) ;
}
if ( V_213 != V_228 ) {
F_19 ( V_2 , L_7 ) ;
V_63 = V_176 ;
goto V_8;
}
V_2 -> V_30 . V_34 . V_224 ( V_2 , V_229 ,
V_149 , & V_212 ) ;
* V_210 = ( T_5 ) ( V_212 >> 8 ) ;
} else {
V_63 = V_230 ;
}
V_8:
V_2 -> V_15 . V_34 . V_231 ( V_2 , V_214 ) ;
return V_63 ;
}
static T_3 F_43 ( struct V_1 * V_2 , T_5 V_209 ,
T_5 * V_210 )
{
return F_41 ( V_2 , V_232 ,
V_209 , V_210 ) ;
}
static T_3 F_44 ( struct V_1 * V_2 , T_5 V_209 ,
T_5 * V_233 )
{
return F_41 ( V_2 , V_234 ,
V_209 , V_233 ) ;
}
static T_1 F_45 ( struct V_1 * V_2 )
{
T_1 V_235 = V_236 ;
T_1 V_64 = F_2 ( V_2 , V_67 ) ;
T_1 V_237 = V_64 & V_238 ;
T_1 V_239 = V_64 & V_240 ;
T_2 V_241 = 0 ;
V_2 -> V_30 . V_34 . V_35 ( V_2 ) ;
switch ( V_2 -> V_30 . type ) {
case V_42 :
case V_82 :
V_2 -> V_30 . V_34 . V_141 ( V_2 , V_242 ,
V_149 , & V_241 ) ;
if ( V_241 & V_243 )
V_235 |= V_244 ;
if ( V_241 & V_245 )
V_235 |= V_246 ;
if ( V_241 & V_247 )
V_235 |= V_248 ;
goto V_8;
default:
break;
}
switch ( V_64 & V_68 ) {
case V_73 :
case V_69 :
if ( V_239 == V_249 )
V_235 = V_250 ;
else
V_235 = V_251 ;
break;
case V_71 :
if ( V_237 == V_252 )
V_235 = V_253 ;
else if ( V_237 == V_254 )
V_235 = V_255 ;
else
V_235 = V_236 ;
break;
case V_74 :
case V_75 :
if ( V_64 & V_78 )
V_235 |= V_250 ;
if ( V_64 & V_77 )
V_235 |= V_255 ;
break;
default:
break;
}
if ( V_2 -> V_30 . type == V_48 ) {
V_2 -> V_30 . V_34 . V_51 ( V_2 ) ;
switch ( V_2 -> V_30 . V_52 ) {
case V_256 :
V_235 = V_257 ;
break;
case V_258 :
V_235 = V_259 ;
break;
case V_260 :
V_235 = V_261 ;
break;
default:
V_235 = V_236 ;
break;
}
}
switch ( V_2 -> V_83 ) {
case V_89 :
V_235 = V_257 ;
break;
case V_87 :
case V_88 :
case V_90 :
V_235 = V_259 ;
break;
case V_91 :
V_235 = V_261 ;
break;
default:
break;
}
V_8:
return V_235 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_262 * V_263 = & V_2 -> V_263 ;
T_2 V_264 = 0 ;
T_2 V_265 = 0 ;
F_47 ( V_2 ) ;
V_2 -> V_266 . V_34 . V_267 ( V_2 , V_268 , & V_264 ) ;
if ( ( V_264 != 0 ) && ( V_264 != 0xFFFF ) ) {
V_2 -> V_266 . V_34 . V_267 ( V_2 , V_264 + V_269 , & V_265 ) ;
if ( ( V_265 & V_270 ) &&
! ( V_265 & V_271 ) &&
! ( V_265 & V_272 ) ) {
V_263 -> V_273 = 0 ;
}
}
}
static void F_48 ( struct V_1 * V_2 , int V_274 ,
T_1 V_275 , int V_276 )
{
T_1 V_277 = V_278 ;
T_5 V_56 = 0 ;
if ( ! V_274 )
return;
switch ( V_276 ) {
case V_279 :
V_277 = V_280 ;
for (; V_56 < 4 ; V_56 ++ )
F_6 ( V_2 , F_49 ( V_56 ) , V_277 ) ;
V_277 = V_281 ;
case V_282 :
default:
for (; V_56 < V_283 ; V_56 ++ )
F_6 ( V_2 , F_49 ( V_56 ) , V_277 ) ;
break;
}
for ( V_56 = 0 ; V_56 < V_283 ; V_56 ++ )
F_6 ( V_2 , F_50 ( V_56 ) , V_284 ) ;
}
