static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 . V_5 . V_6 . V_3 ) ;
return ( V_3 & V_7 ) >>
V_8 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 . V_5 . V_6 . V_3 ) ;
return V_3 & V_9 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_4 . V_5 ;
T_1 * V_12 ;
int V_13 , V_14 = V_15 ;
V_12 = ( T_1 * ) V_11 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( ! F_5 ( V_2 , V_13 + V_14 , V_12 ) )
return false ;
V_12 ++ ;
}
return true ;
}
static bool F_6 ( struct V_1 * V_2 )
{
T_1 * V_12 = ( T_1 * ) & V_2 -> V_4 . V_5 ;
F_7 ( V_2 , V_12 ,
V_17 ,
V_16 ) ;
return true ;
}
static bool F_8 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
if ( ! F_10 ( V_2 ) ) {
F_11 ( V_19 , V_20 , L_1 ) ;
}
if ( V_19 -> V_21 -> V_22 == V_23 )
return F_6 ( V_2 ) ;
else
return F_4 ( V_2 ) ;
}
static T_2 F_12 ( char * V_24 , T_2 V_25 , T_2 V_26 ,
struct V_27 * V_28 )
{
F_13 ( L_2 , F_2 ( V_28 -> V_29 [ 0 ] ) ) ;
F_13 ( L_3 , F_2 ( V_28 -> V_29 [ 1 ] ) ) ;
F_13 ( L_4 , F_14 ( V_28 -> V_30 ) ) ;
F_13 ( L_5 , V_28 -> V_31 [ 0 ] ) ;
F_13 ( L_6 , V_28 -> V_31 [ 1 ] ) ;
F_13 ( L_7 , V_28 -> V_32 ) ;
F_13 ( L_8 , V_28 -> V_33 [ 0 ] ) ;
F_13 ( L_9 , V_28 -> V_33 [ 1 ] ) ;
F_13 ( L_10 , V_28 -> V_34 [ 0 ] ) ;
F_13 ( L_11 , V_28 -> V_34 [ 1 ] ) ;
F_13 ( L_12 , V_28 -> V_35 ) ;
F_13 ( L_13 , V_28 -> V_36 ) ;
F_13 ( L_14 , V_28 -> V_37 ) ;
F_13 ( L_15 , V_28 -> V_38 ) ;
F_13 ( L_16 , V_28 -> V_39 ) ;
F_13 ( L_17 , V_28 -> V_40 [ 0 ] ) ;
F_13 ( L_18 , V_28 -> V_40 [ 1 ] ) ;
F_13 ( L_19 , V_28 -> V_41 ) ;
F_13 ( L_20 , V_28 -> V_42 ) ;
F_13 ( L_21 , V_28 -> V_43 [ 0 ] ) ;
F_13 ( L_22 , V_28 -> V_43 [ 1 ] ) ;
F_13 ( L_23 , V_28 -> V_44 [ 0 ] ) ;
F_13 ( L_24 , V_28 -> V_44 [ 1 ] ) ;
F_13 ( L_25 , V_28 -> V_45 ) ;
F_13 ( L_26 , V_28 -> V_46 ) ;
F_13 ( L_27 , V_28 -> V_47 ) ;
F_13 ( L_28 , V_28 -> V_48 ) ;
F_13 ( L_29 , V_28 -> V_49 ) ;
F_13 ( L_30 , V_28 -> V_50 [ 0 ] ) ;
F_13 ( L_31 , V_28 -> V_50 [ 1 ] ) ;
F_13 ( L_32 , V_28 -> V_51 [ 0 ] ) ;
F_13 ( L_33 , V_28 -> V_51 [ 1 ] ) ;
F_13 ( L_34 , V_28 -> V_52 ) ;
F_13 ( L_35 , V_28 -> V_3 ) ;
F_13 ( L_36 , V_28 -> V_53 ) ;
F_13 ( L_37 , V_28 -> V_53 ) ;
F_13 ( L_38 , V_28 -> V_54 ) ;
F_13 ( L_39 , V_28 -> V_55 ) ;
F_13 ( L_40 , V_28 -> V_56 ) ;
F_13 ( L_41 , V_28 -> V_57 ) ;
return V_25 ;
}
static T_2 F_15 ( struct V_1 * V_2 , bool V_58 ,
T_3 * V_24 , T_2 V_25 , T_2 V_26 )
{
struct V_10 * V_11 = & V_2 -> V_4 . V_5 ;
struct V_59 * V_60 = & V_11 -> V_6 ;
T_2 V_61 = F_14 ( V_60 -> V_61 ) ;
if ( ! V_58 ) {
V_25 += F_16 ( V_24 + V_25 , V_26 - V_25 ,
L_42 , L_43 ) ;
V_25 = F_12 ( V_24 , V_25 , V_26 ,
& V_11 -> V_62 ) ;
goto V_63;
}
F_13 ( L_44 , F_1 ( V_2 ) ) ;
F_13 ( L_45 , F_3 ( V_2 ) ) ;
F_13 ( L_46 , F_2 ( V_60 -> V_64 ) ) ;
F_13 ( L_47 , F_2 ( V_60 -> V_65 ) ) ;
F_13 ( L_48 , F_2 ( V_60 -> V_66 [ 0 ] ) ) ;
F_13 ( L_49 , F_2 ( V_60 -> V_66 [ 1 ] ) ) ;
F_13 ( L_50 , V_60 -> V_67 ) ;
F_13 ( L_51 , V_60 -> V_68 ) ;
F_13 ( L_52 , ! ! ( V_60 -> V_69 & V_70 ) ) ;
F_13 ( L_53 , ! ! ( V_60 -> V_69 & V_71 ) ) ;
F_13 ( L_54 , ! ! ( V_60 -> V_69 &
V_72 ) ) ;
F_13 ( L_55 , ! ! ( V_60 -> V_69 &
V_73 ) ) ;
F_13 ( L_56 , ! ! ( V_60 -> V_69 &
V_74 ) ) ;
F_13 ( L_57 , ! ! ( V_60 -> V_69 &
V_75 ) ) ;
F_13 ( L_58 , ! ! ( V_60 -> V_76 & V_77 ) ) ;
F_13 ( L_59 , ( V_61 >> 24 ) & 0xFF ) ;
F_13 ( L_60 , ( V_61 >> 16 ) & 0xFF ) ;
F_13 ( L_61 , ( V_61 >> 8 ) & 0xFF ) ;
F_13 ( L_62 , V_60 -> V_78 ) ;
F_13 ( L_63 , V_60 -> V_79 ) ;
V_25 += F_16 ( V_24 + V_25 , V_26 - V_25 , L_64 , L_65 ,
V_60 -> V_80 ) ;
V_63:
if ( V_25 > V_26 )
V_25 = V_26 ;
return V_25 ;
}
static T_2 F_15 ( struct V_1 * V_2 , bool V_58 ,
T_3 * V_24 , T_2 V_25 , T_2 V_26 )
{
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_81 ;
int V_82 , V_83 ;
bool V_84 ;
struct V_10 * V_11 = & V_2 -> V_4 . V_5 ;
V_83 = F_18 ( V_2 , & V_84 , V_16 ) ;
if ( V_83 )
return V_83 ;
if ( V_84 )
V_81 = F_19 ( ( V_85 T_1 ) V_11 -> V_6 . V_65 ) ;
else
V_81 = F_2 ( V_11 -> V_6 . V_65 ) ;
V_81 = F_20 ( V_81 / sizeof( T_1 ) , V_16 ) ;
if ( ! F_21 ( V_2 , V_81 ) )
return - V_86 ;
if ( V_84 ) {
F_22 ( V_11 -> V_6 . V_65 ) ;
F_22 ( V_11 -> V_6 . V_64 ) ;
F_22 ( V_11 -> V_6 . V_3 ) ;
F_22 ( V_11 -> V_6 . V_66 [ 0 ] ) ;
F_22 ( V_11 -> V_6 . V_66 [ 1 ] ) ;
F_22 ( V_11 -> V_6 . V_87 ) ;
F_22 ( V_11 -> V_6 . V_88 ) ;
F_22 ( V_11 -> V_6 . V_89 ) ;
F_23 ( V_11 -> V_62 . V_30 ) ;
for ( V_82 = 0 ; V_82 < V_90 ; V_82 ++ )
F_23 ( V_11 -> V_62 . V_29 [ V_82 ] ) ;
for ( V_82 = 0 ; V_82 < V_91 ; V_82 ++ )
F_22 (
V_11 -> V_62 . V_92 [ V_82 ] . V_93 ) ;
}
if ( ! F_24 ( V_2 , V_94 ,
V_95 ) )
return - V_86 ;
return 0 ;
}
static T_2 F_25 ( struct V_1 * V_2 ,
enum V_96 V_97 )
{
struct V_10 * V_11 = & V_2 -> V_4 . V_5 ;
struct V_27 * V_98 = & V_11 -> V_62 ;
struct V_59 * V_60 = & V_11 -> V_6 ;
T_1 V_99 = F_3 ( V_2 ) ;
switch ( V_97 ) {
case V_100 :
return V_98 -> V_40 [ 0 ] ;
case V_101 :
return F_26 ( V_60 -> V_80 ) ;
case V_102 :
return F_26 ( V_60 -> V_80 + 2 ) ;
case V_103 :
return F_26 ( V_60 -> V_80 + 4 ) ;
case V_104 :
return F_2 ( V_60 -> V_66 [ 0 ] ) ;
case V_105 :
return F_2 ( V_60 -> V_89 ) ;
case V_106 :
return V_60 -> V_69 ;
case V_107 :
return F_2 ( V_60 -> V_87 ) ;
case V_108 :
return V_60 -> V_67 ;
case V_109 :
return V_60 -> V_68 ;
case V_110 :
return V_60 -> V_111 ;
case V_112 :
return V_60 -> V_79 ;
case V_113 :
if ( V_99 >= V_114 )
return V_60 -> V_115 ;
else
return 0 ;
case V_116 :
if ( V_99 >= V_117 )
return V_60 -> V_118 ;
else
return 0 ;
case V_119 :
return F_27 ( T_3 , V_98 -> V_31 [ 0 ] ,
V_98 -> V_31 [ 1 ] ) ;
default:
return 0 ;
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
T_3 * V_124 , T_1 V_125 , T_4 * V_126 )
{
T_1 V_127 = 0 , V_128 = 0 , V_129 ;
bool V_130 ;
struct V_131 V_132 ;
F_29 ( V_2 , V_121 , & V_132 ) ;
for ( V_129 = 0 ; V_129 < V_125 ; V_129 ++ ) {
if ( V_124 [ V_129 ] == V_133 )
break;
}
V_130 = F_30 (
( T_3 ) F_31 ( V_132 . V_134 , F_32 ( V_121 ) ) ,
V_124 , V_129 , & V_127 , & V_128 ) ;
if ( V_130 ) {
* V_126 = ( T_4 ) V_123 [ V_127 ] . V_135 [ 0 ] [ 0 ] ;
} else {
* V_126 = ( ( T_4 ) V_123 [ V_127 ] . V_135 [ 0 ] [ 0 ] +
( T_4 ) V_123 [ V_128 ] . V_135 [ 0 ] [ 0 ] ) / 2 ;
}
}
static void F_33 ( struct V_1 * V_2 ,
T_5 V_136 , T_1 V_137 )
{
T_2 V_138 ;
T_2 V_139 ;
V_138 = F_34 ( V_2 , 0xa270 ) ;
V_138 = V_138 & 0xFCFFFFFF ;
V_138 = V_138 | ( 0x3 << 24 ) ;
F_35 ( V_2 , 0xa270 , V_138 ) ;
V_138 = F_34 ( V_2 , 0xb270 ) ;
V_138 = V_138 & 0xFCFFFFFF ;
V_138 = V_138 | ( 0x3 << 24 ) ;
F_35 ( V_2 , 0xb270 , V_138 ) ;
if ( V_137 == 0 ) {
V_138 = F_34 ( V_2 , 0xa398 ) ;
V_138 = V_138 & 0xff00ffff ;
V_139 = ( V_136 ) & 0xff ;
V_138 = V_138 | ( V_139 << 16 ) ;
F_35 ( V_2 , 0xa398 , V_138 ) ;
}
if ( V_137 == 1 ) {
V_138 = F_34 ( V_2 , 0xb398 ) ;
V_138 = V_138 & 0xff00ffff ;
V_139 = ( V_136 ) & 0xff ;
V_138 = V_138 | ( V_139 << 16 ) ;
F_35 ( V_2 , 0xb398 , V_138 ) ;
}
}
static void F_36 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_140 * V_141 ;
struct V_122 * V_142 ;
T_3 * V_143 = NULL ;
T_1 V_144 ;
T_3 V_145 [ V_146 ] ;
T_1 V_147 [ V_148 ] ;
T_1 V_129 = 0 , V_82 , V_149 ;
T_1 V_150 , V_151 ;
T_1 V_152 [ V_153 ] = { 0 , 0 , 0 , 0 } ;
T_2 V_154 , V_155 , V_156 , V_157 ;
T_6 V_158 = 0 ;
struct V_10 * V_159 = & V_2 -> V_4 . V_5 ;
V_151 = V_159 -> V_62 . V_41 ;
if ( F_3 ( V_2 ) >= V_114 )
V_144 = V_159 -> V_62 . V_45 ;
else
V_144 = ( T_1 ) ( F_37 ( F_34 ( V_2 , V_160 ) ,
V_161 ) ) ;
if ( F_32 ( V_121 ) ) {
V_143 = V_159 -> V_162 ;
V_129 = V_163 ;
if ( F_25 ( V_2 , V_112 ) ) {
V_142 =
(struct V_122 * ) V_159 -> V_164 [ 0 ] ;
V_2 -> V_165 = V_142 -> V_166 [ 0 ] [ 0 ] ;
}
}
V_150 = 0 ;
for ( V_82 = 1 ; V_82 <= V_148 ; V_82 ++ ) {
if ( ( V_151 >> ( V_148 - V_82 ) ) & 1 ) {
if ( V_150 >= V_153 )
break;
V_152 [ V_150 ] =
( T_1 ) ( V_148 - V_82 ) ;
V_150 ++ ;
}
}
F_38 ( V_2 , V_167 , V_168 ,
( V_150 - 1 ) & 0x3 ) ;
F_38 ( V_2 , V_167 , V_169 ,
V_152 [ 0 ] ) ;
F_38 ( V_2 , V_167 , V_170 ,
V_152 [ 1 ] ) ;
F_38 ( V_2 , V_167 , V_171 ,
V_152 [ 2 ] ) ;
for ( V_82 = 0 ; V_82 < V_90 ; V_82 ++ ) {
V_156 = V_82 * 0x1000 ;
if ( V_159 -> V_6 . V_67 & ( 1 << V_82 ) ) {
V_142 =
(struct V_122 * ) V_159 -> V_164 [ V_82 ] ;
if ( F_25 ( V_2 , V_112 ) ) {
T_4 V_136 ;
F_28 ( V_2 , V_121 ,
V_142 ,
V_143 , V_129 ,
& V_136 ) ;
F_33 ( V_2 , V_136 , V_82 ) ;
} else {
V_141 =
(struct V_140 * )
V_159 -> V_164 [ V_82 ] ;
F_39 ( V_2 , V_121 ,
V_141 ,
V_143 , V_129 ,
V_144 ,
V_147 ,
V_145 ,
V_150 ) ;
}
F_40 ( V_2 ) ;
if ( V_82 == 0 ) {
if ( ! F_25 ( V_2 ,
V_112 ) ) {
V_157 = F_41 ( V_144 ,
V_161 )
| F_41 ( V_147 [ 0 ] ,
V_172 )
| F_41 ( V_147 [ 1 ] ,
V_173 )
| F_41 ( V_147 [ 2 ] ,
V_174 )
| F_41 ( V_147 [ 3 ] ,
V_175 ) ;
F_35 ( V_2 ,
V_160 + V_156 ,
V_157 ) ;
}
}
if ( ( T_5 ) V_176 !=
V_159 -> V_6 . V_78 ) {
V_158 = ( T_1 ) ( V_159 -> V_6 . V_78 -
( T_5 ) V_176 ) ;
V_158 *= 2 ;
for ( V_149 = 0 ; V_149 < ( ( T_1 ) V_146 - V_158 ) ; V_149 ++ )
V_145 [ V_149 ] = V_145 [ V_149 + V_158 ] ;
for ( V_149 = ( T_1 ) ( V_146 - V_158 ) ;
V_149 < V_146 ; V_149 ++ )
V_145 [ V_149 ] =
V_145 [ V_146 - V_158 ] ;
}
if ( ! F_25 ( V_2 , V_112 ) ) {
V_155 = V_177 +
( 672 << 2 ) + V_156 ;
for ( V_149 = 0 ; V_149 < 32 ; V_149 ++ ) {
V_154 = F_42 ( & V_145 [ 4 * V_149 ] ) ;
F_35 ( V_2 , V_155 , V_154 ) ;
V_155 += 4 ;
}
}
F_43 ( V_2 ) ;
}
}
}
static void F_44 ( struct V_1 * V_2 ,
struct V_120 * V_121 ,
T_6 * V_178 ,
T_1 V_179 ,
T_1 V_180 ,
T_1 V_181 )
{
#define F_45 \
(((cfgCtl & ~CTL_MODE_M) | (pCtlMode[ctlMode] & CTL_MODE_M)) == \
pEepData->ctlIndex[i])
#define F_46 \
(((cfgCtl & ~CTL_MODE_M) | (pCtlMode[ctlMode] & CTL_MODE_M)) == \
((pEepData->ctlIndex[i] & CTL_MODE_M) | SD_NO_CTL))
T_1 V_182 ;
int V_82 ;
struct V_183 * V_184 ;
struct V_185 V_186 = { 0 , { 0 , 0 , 0 , 0 } } ,
V_187 = { 0 , { 0 , 0 , 0 , 0 } } ;
struct V_185 V_188 = { 0 , { 0 , 0 , 0 , 0 } } ,
V_189 = { 0 , { 0 , 0 , 0 , 0 } } ;
struct V_190 V_191 ,
V_192 = { 0 , { 0 , 0 , 0 , 0 } } ;
T_1 V_193 = 0 , V_194 ;
static const T_1 V_195 [] = {
V_196 , V_197 , V_198 ,
V_199 , V_200 , V_201
} ;
T_1 V_202 = 0 ;
const T_1 * V_203 = NULL ;
T_1 V_204 , V_205 ;
struct V_131 V_132 ;
int V_206 ;
T_1 V_207 ;
struct V_10 * V_159 = & V_2 -> V_4 . V_5 ;
V_206 = V_2 -> V_208 ;
F_29 ( V_2 , V_121 , & V_132 ) ;
V_193 = F_47 ( V_2 , V_181 ,
V_180 ) ;
if ( F_32 ( V_121 ) ) {
V_202 =
F_48 ( V_195 ) - V_209 ;
V_203 = V_195 ;
F_49 ( V_2 , V_121 ,
V_159 -> V_210 ,
V_211 ,
& V_187 , 4 , false ) ;
F_49 ( V_2 , V_121 ,
V_159 -> V_212 ,
V_213 ,
& V_186 , 4 , false ) ;
F_50 ( V_2 , V_121 ,
V_159 -> V_214 ,
V_213 ,
& V_191 , 8 , false ) ;
if ( F_51 ( V_121 ) ) {
V_202 = F_48 ( V_195 ) ;
F_50 ( V_2 , V_121 ,
V_159 -> V_215 ,
V_216 ,
& V_192 , 8 , true ) ;
F_49 ( V_2 , V_121 ,
V_159 -> V_210 ,
V_211 ,
& V_189 , 4 , true ) ;
F_49 ( V_2 , V_121 ,
V_159 -> V_212 ,
V_213 ,
& V_188 , 4 , true ) ;
}
}
for ( V_204 = 0 ; V_204 < V_202 ; V_204 ++ ) {
bool V_217 =
( V_203 [ V_204 ] == V_201 ) ? true : false ;
if ( V_217 )
V_205 = V_132 . V_134 ;
else if ( V_203 [ V_204 ] & V_218 )
V_205 = V_132 . V_219 ;
else
V_205 = V_132 . V_220 ;
V_182 = V_221 ;
for ( V_82 = 0 ; ( V_82 < V_222 ) && V_159 -> V_223 [ V_82 ] ; V_82 ++ ) {
struct V_224 * V_225 ;
if ( F_45 || F_46 ) {
V_184 = & ( V_159 -> V_226 [ V_82 ] ) ;
V_225 =
V_184 -> V_227 [ F_52 ( V_206 ) - 1 ] ;
V_207 = F_53 ( V_205 ,
V_225 ,
F_32 ( V_121 ) ,
V_228 ) ;
if ( ( V_179 & ~ V_229 ) == V_230 ) {
V_182 = F_20 ( V_182 ,
V_207 ) ;
} else {
V_182 = V_207 ;
break;
}
}
}
V_194 = ( T_3 ) F_20 ( V_182 , V_193 ) ;
switch ( V_203 [ V_204 ] ) {
case V_196 :
for ( V_82 = 0 ; V_82 < F_48 ( V_187 . V_231 ) ; V_82 ++ ) {
V_187 . V_231 [ V_82 ] =
( T_3 ) F_20 ( ( T_1 ) V_187 . V_231 [ V_82 ] ,
V_194 ) ;
}
break;
case V_232 :
case V_197 :
for ( V_82 = 0 ; V_82 < F_48 ( V_186 . V_231 ) ; V_82 ++ ) {
V_186 . V_231 [ V_82 ] =
( T_3 ) F_20 ( ( T_1 ) V_186 . V_231 [ V_82 ] ,
V_194 ) ;
}
break;
case V_233 :
case V_198 :
for ( V_82 = 0 ; V_82 < F_48 ( V_191 . V_231 ) ; V_82 ++ ) {
V_191 . V_231 [ V_82 ] =
( T_3 ) F_20 ( ( T_1 ) V_191 . V_231 [ V_82 ] ,
V_194 ) ;
}
break;
case V_199 :
V_189 . V_231 [ 0 ] =
( T_3 ) F_20 ( ( T_1 ) V_189 . V_231 [ 0 ] ,
V_194 ) ;
break;
case V_234 :
case V_200 :
V_188 . V_231 [ 0 ] =
( T_3 ) F_20 ( ( T_1 ) V_188 . V_231 [ 0 ] ,
V_194 ) ;
break;
case V_235 :
case V_201 :
for ( V_82 = 0 ; V_82 < F_48 ( V_192 . V_231 ) ; V_82 ++ ) {
V_192 . V_231 [ V_82 ] =
( T_3 ) F_20 ( ( T_1 ) V_192 . V_231 [ V_82 ] ,
V_194 ) ;
}
break;
default:
break;
}
}
V_178 [ V_236 ] =
V_178 [ V_237 ] =
V_178 [ V_238 ] =
V_178 [ V_239 ] =
V_178 [ V_240 ] = V_186 . V_231 [ 0 ] ;
V_178 [ V_241 ] = V_186 . V_231 [ 1 ] ;
V_178 [ V_242 ] = V_186 . V_231 [ 2 ] ;
V_178 [ V_243 ] = V_186 . V_231 [ 3 ] ;
V_178 [ V_244 ] = V_186 . V_231 [ 0 ] ;
for ( V_82 = 0 ; V_82 < F_48 ( V_191 . V_231 ) ; V_82 ++ )
V_178 [ V_245 + V_82 ] = V_191 . V_231 [ V_82 ] ;
if ( F_32 ( V_121 ) ) {
V_178 [ V_246 ] = V_187 . V_231 [ 0 ] ;
V_178 [ V_247 ] =
V_178 [ V_248 ] = V_187 . V_231 [ 1 ] ;
V_178 [ V_249 ] =
V_178 [ V_250 ] = V_187 . V_231 [ 2 ] ;
V_178 [ V_251 ] =
V_178 [ V_252 ] = V_187 . V_231 [ 3 ] ;
}
if ( F_51 ( V_121 ) ) {
for ( V_82 = 0 ; V_82 < F_48 ( V_192 . V_231 ) ; V_82 ++ )
V_178 [ V_253 + V_82 ] = V_192 . V_231 [ V_82 ] ;
V_178 [ V_254 ] = V_192 . V_231 [ 0 ] ;
V_178 [ V_255 ] = V_192 . V_231 [ 0 ] ;
V_178 [ V_256 ] = V_188 . V_231 [ 0 ] ;
if ( F_32 ( V_121 ) )
V_178 [ V_257 ] = V_189 . V_231 [ 0 ] ;
}
#undef F_45
#undef F_46
}
static void F_54 ( struct V_1 * V_2 ,
struct V_120 * V_121 , T_1 V_179 ,
T_3 V_258 ,
T_3 V_181 , bool V_259 )
{
struct V_260 * V_261 = F_55 ( V_2 ) ;
struct V_10 * V_159 = & V_2 -> V_4 . V_5 ;
struct V_27 * V_98 = & V_159 -> V_62 ;
T_6 V_178 [ V_262 ] ;
T_3 V_49 = 2 ;
int V_82 ;
memset ( V_178 , 0 , sizeof( V_178 ) ) ;
if ( F_3 ( V_2 ) >= V_114 )
V_49 = V_98 -> V_49 ;
F_44 ( V_2 , V_121 ,
& V_178 [ 0 ] , V_179 ,
V_258 ,
V_181 ) ;
F_36 ( V_2 , V_121 ) ;
V_261 -> V_263 = 0 ;
for ( V_82 = 0 ; V_82 < F_48 ( V_178 ) ; V_82 ++ ) {
if ( V_178 [ V_82 ] > V_221 )
V_178 [ V_82 ] = V_221 ;
if ( V_178 [ V_82 ] > V_261 -> V_263 )
V_261 -> V_263 = V_178 [ V_82 ] ;
}
F_56 ( V_2 ) ;
if ( V_259 )
return;
for ( V_82 = 0 ; V_82 < V_262 ; V_82 ++ )
V_178 [ V_82 ] -= V_176 * 2 ;
F_40 ( V_2 ) ;
F_35 ( V_2 , V_264 ,
F_57 ( V_178 [ V_239 ] , 24 )
| F_57 ( V_178 [ V_238 ] , 16 )
| F_57 ( V_178 [ V_237 ] , 8 )
| F_57 ( V_178 [ V_236 ] , 0 ) ) ;
F_35 ( V_2 , V_265 ,
F_57 ( V_178 [ V_243 ] , 24 )
| F_57 ( V_178 [ V_242 ] , 16 )
| F_57 ( V_178 [ V_241 ] , 8 )
| F_57 ( V_178 [ V_240 ] , 0 ) ) ;
if ( F_32 ( V_121 ) ) {
F_35 ( V_2 , V_266 ,
F_57 ( V_178 [ V_247 ] , 24 )
| F_57 ( V_178 [ V_248 ] , 16 )
| F_57 ( V_178 [ V_244 ] , 8 )
| F_57 ( V_178 [ V_246 ] , 0 ) ) ;
F_35 ( V_2 , V_267 ,
F_57 ( V_178 [ V_251 ] , 24 )
| F_57 ( V_178 [ V_252 ] , 16 )
| F_57 ( V_178 [ V_249 ] , 8 )
| F_57 ( V_178 [ V_250 ] , 0 ) ) ;
}
F_35 ( V_2 , V_268 ,
F_57 ( V_178 [ V_269 ] , 24 )
| F_57 ( V_178 [ V_270 ] , 16 )
| F_57 ( V_178 [ V_271 ] , 8 )
| F_57 ( V_178 [ V_245 ] , 0 ) ) ;
F_35 ( V_2 , V_272 ,
F_57 ( V_178 [ V_273 ] , 24 )
| F_57 ( V_178 [ V_274 ] , 16 )
| F_57 ( V_178 [ V_275 ] , 8 )
| F_57 ( V_178 [ V_276 ] , 0 ) ) ;
if ( F_51 ( V_121 ) ) {
if ( F_25 ( V_2 , V_112 ) ) {
F_35 ( V_2 , V_277 ,
F_57 ( V_178 [ V_278 ] , 24 )
| F_57 ( V_178 [ V_279 ] , 16 )
| F_57 ( V_178 [ V_280 ] , 8 )
| F_57 ( V_178 [ V_253 ] , 0 ) ) ;
F_35 ( V_2 , V_281 ,
F_57 ( V_178 [ V_282 ] , 24 )
| F_57 ( V_178 [ V_283 ] , 16 )
| F_57 ( V_178 [ V_284 ] , 8 )
| F_57 ( V_178 [ V_285 ] , 0 ) ) ;
} else {
F_35 ( V_2 , V_277 ,
F_57 ( V_178 [ V_278 ] +
V_49 , 24 )
| F_57 ( V_178 [ V_279 ] +
V_49 , 16 )
| F_57 ( V_178 [ V_280 ] +
V_49 , 8 )
| F_57 ( V_178 [ V_253 ] +
V_49 , 0 ) ) ;
F_35 ( V_2 , V_281 ,
F_57 ( V_178 [ V_282 ] +
V_49 , 24 )
| F_57 ( V_178 [ V_283 ] +
V_49 , 16 )
| F_57 ( V_178 [ V_284 ] +
V_49 , 8 )
| F_57 ( V_178 [ V_285 ] +
V_49 , 0 ) ) ;
}
F_35 ( V_2 , V_286 ,
F_57 ( V_178 [ V_256 ] , 24 )
| F_57 ( V_178 [ V_257 ] , 16 )
| F_57 ( V_178 [ V_254 ] , 8 )
| F_57 ( V_178 [ V_255 ] , 0 ) ) ;
}
if ( V_2 -> V_287 ) {
int V_288 ;
V_288 = ( F_51 ( V_121 ) ) ? V_49 : 0 ;
F_58 ( V_2 , V_178 , V_121 , V_288 ) ;
F_35 ( V_2 , V_289 ,
V_221 | V_290 ) ;
} else {
F_35 ( V_2 , V_289 , V_221 ) ;
}
F_43 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_10 * V_11 = & V_2 -> V_4 . V_5 ;
struct V_27 * V_98 = & V_11 -> V_62 ;
T_2 V_156 , V_157 ;
T_3 V_291 ;
int V_82 ;
V_98 = & V_11 -> V_62 ;
F_35 ( V_2 , V_292 , F_14 ( V_98 -> V_30 ) ) ;
for ( V_82 = 0 ; V_82 < V_90 ; V_82 ++ ) {
V_156 = V_82 * 0x1000 ;
F_35 ( V_2 , V_293 + V_156 ,
F_14 ( V_98 -> V_29 [ V_82 ] ) ) ;
F_35 ( V_2 , F_60 ( 0 ) + V_156 ,
( F_34 ( V_2 , F_60 ( 0 ) + V_156 )
& ~ ( V_294 |
V_295 ) ) |
F_41 ( V_98 -> V_43 [ V_82 ] ,
V_295 ) |
F_41 ( V_98 -> V_44 [ V_82 ] ,
V_294 ) ) ;
V_291 = V_98 -> V_33 [ V_82 ] ;
F_38 ( V_2 , V_296 + V_156 ,
V_297 ,
V_98 -> V_51 [ V_82 ] ) ;
F_38 ( V_2 , V_296 + V_156 ,
V_298 ,
V_98 -> V_50 [ V_82 ] ) ;
F_38 ( V_2 , V_299 + V_156 ,
V_300 ,
V_291 ) ;
F_38 ( V_2 , V_299 + V_156 ,
V_301 ,
V_98 -> V_34 [ V_82 ] ) ;
}
if ( F_51 ( V_121 ) )
F_38 ( V_2 , V_302 ,
V_303 , V_98 -> V_52 ) ;
else
F_38 ( V_2 , V_302 ,
V_303 , V_98 -> V_32 ) ;
F_38 ( V_2 , V_304 ,
V_305 , V_98 -> V_35 ) ;
F_35 ( V_2 , V_306 ,
F_41 ( V_98 -> V_36 , V_307 )
| F_41 ( V_98 -> V_36 , V_308 )
| F_41 ( V_98 -> V_38 , V_309 )
| F_41 ( V_98 -> V_38 , V_310 ) ) ;
F_38 ( V_2 , V_311 ,
V_312 , V_98 -> V_37 ) ;
F_38 ( V_2 , V_313 ,
V_314 , V_98 -> V_39 ) ;
F_38 ( V_2 , V_315 ,
V_316 , V_98 -> V_39 ) ;
V_157 = F_34 ( V_2 , V_317 ) ;
V_157 &= ~ ( V_318 |
V_319 |
V_320 |
V_321 |
V_322 |
V_323 ) ;
V_157 |= ( F_41 ( V_98 -> V_53 , V_318 ) |
F_41 ( V_98 -> V_324 , V_319 ) |
F_41 ( V_98 -> V_54 , V_320 ) |
F_41 ( V_98 -> V_55 , V_321 ) |
F_41 ( V_98 -> V_56 , V_322 ) |
F_41 ( V_98 -> V_57 , V_323 ) ) ;
F_61 ( V_2 , V_317 , V_157 ) ;
V_157 = F_34 ( V_2 , V_325 ) ;
V_157 &= ~ ( V_318 |
V_319 |
V_320 |
V_321 |
V_322 |
V_323 ) ;
V_157 |= ( F_41 ( V_98 -> V_53 , V_318 ) |
F_41 ( V_98 -> V_324 , V_319 ) |
F_41 ( V_98 -> V_54 , V_320 ) |
F_41 ( V_98 -> V_55 , V_321 ) |
F_41 ( V_98 -> V_56 , V_322 ) |
F_41 ( V_98 -> V_57 , V_323 ) ) ;
F_61 ( V_2 , V_325 , V_157 ) ;
F_38 ( V_2 , V_326 ,
V_327 , V_98 -> V_47 ) ;
F_38 ( V_2 , V_326 ,
V_328 , V_98 -> V_48 ) ;
F_62 ( V_2 , V_329 ,
V_330 ,
V_331 ,
V_98 -> V_46 ) ;
}
static T_1 F_63 ( struct V_1 * V_2 ,
T_1 V_82 , bool V_332 )
{
T_7 V_333 = V_2 -> V_4 . V_5 . V_62 . V_92 [ V_82 ] . V_93 ;
return F_2 ( V_333 ) ;
}
static T_3 F_64 ( struct V_1 * V_2 )
{
return V_2 -> V_4 . V_5 . V_6 . V_76 ;
}
