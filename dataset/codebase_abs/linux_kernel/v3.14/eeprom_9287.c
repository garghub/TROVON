static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 . V_5 . V_6 >> 12 ) & 0xF ;
}
static int F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 . V_5 . V_6 ) & 0xFFF ;
}
static bool F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_3 . V_4 ;
T_1 * V_9 ;
int V_10 , V_11 = V_12 ;
V_9 = ( T_1 * ) V_8 ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
if ( ! F_4 ( V_2 , V_10 + V_11 , V_9 ) )
return false ;
V_9 ++ ;
}
return true ;
}
static bool F_5 ( struct V_1 * V_2 )
{
T_1 * V_9 = ( T_1 * ) & V_2 -> V_3 . V_4 ;
F_6 ( V_2 , V_9 ,
V_14 ,
V_13 ) ;
return true ;
}
static bool F_7 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_8 ( V_2 ) ;
if ( ! F_9 ( V_2 ) ) {
F_10 ( V_16 , V_17 , L_1 ) ;
}
if ( V_16 -> V_18 -> V_19 == V_20 )
return F_5 ( V_2 ) ;
else
return F_3 ( V_2 ) ;
}
static T_2 F_11 ( char * V_21 , T_2 V_22 , T_2 V_23 ,
struct V_24 * V_25 )
{
F_12 ( L_2 , V_25 -> V_26 [ 0 ] ) ;
F_12 ( L_3 , V_25 -> V_26 [ 1 ] ) ;
F_12 ( L_4 , V_25 -> V_27 ) ;
F_12 ( L_5 , V_25 -> V_28 [ 0 ] ) ;
F_12 ( L_6 , V_25 -> V_28 [ 1 ] ) ;
F_12 ( L_7 , V_25 -> V_29 ) ;
F_12 ( L_8 , V_25 -> V_30 [ 0 ] ) ;
F_12 ( L_9 , V_25 -> V_30 [ 1 ] ) ;
F_12 ( L_10 , V_25 -> V_31 [ 0 ] ) ;
F_12 ( L_11 , V_25 -> V_31 [ 1 ] ) ;
F_12 ( L_12 , V_25 -> V_32 ) ;
F_12 ( L_13 , V_25 -> V_33 ) ;
F_12 ( L_14 , V_25 -> V_34 ) ;
F_12 ( L_15 , V_25 -> V_35 ) ;
F_12 ( L_16 , V_25 -> V_36 ) ;
F_12 ( L_17 , V_25 -> V_37 [ 0 ] ) ;
F_12 ( L_18 , V_25 -> V_37 [ 1 ] ) ;
F_12 ( L_19 , V_25 -> V_38 ) ;
F_12 ( L_20 , V_25 -> V_39 ) ;
F_12 ( L_21 , V_25 -> V_40 [ 0 ] ) ;
F_12 ( L_22 , V_25 -> V_40 [ 1 ] ) ;
F_12 ( L_23 , V_25 -> V_41 [ 0 ] ) ;
F_12 ( L_24 , V_25 -> V_41 [ 1 ] ) ;
F_12 ( L_25 , V_25 -> V_42 ) ;
F_12 ( L_26 , V_25 -> V_43 ) ;
F_12 ( L_27 , V_25 -> V_44 ) ;
F_12 ( L_28 , V_25 -> V_45 ) ;
F_12 ( L_29 , V_25 -> V_46 ) ;
F_12 ( L_30 , V_25 -> V_47 [ 0 ] ) ;
F_12 ( L_31 , V_25 -> V_47 [ 1 ] ) ;
F_12 ( L_32 , V_25 -> V_48 [ 0 ] ) ;
F_12 ( L_33 , V_25 -> V_48 [ 1 ] ) ;
F_12 ( L_34 , V_25 -> V_49 ) ;
F_12 ( L_35 , V_25 -> V_6 ) ;
F_12 ( L_36 , V_25 -> V_50 ) ;
F_12 ( L_37 , V_25 -> V_50 ) ;
F_12 ( L_38 , V_25 -> V_51 ) ;
F_12 ( L_39 , V_25 -> V_52 ) ;
F_12 ( L_40 , V_25 -> V_53 ) ;
F_12 ( L_41 , V_25 -> V_54 ) ;
return V_22 ;
}
static T_2 F_13 ( struct V_1 * V_2 , bool V_55 ,
T_3 * V_21 , T_2 V_22 , T_2 V_23 )
{
struct V_7 * V_8 = & V_2 -> V_3 . V_4 ;
struct V_56 * V_57 = & V_8 -> V_5 ;
if ( ! V_55 ) {
V_22 += F_14 ( V_21 + V_22 , V_23 - V_22 ,
L_42 , L_43 ) ;
V_22 = F_11 ( V_21 , V_22 , V_23 ,
& V_8 -> V_58 ) ;
goto V_59;
}
F_12 ( L_44 , V_57 -> V_6 >> 12 ) ;
F_12 ( L_45 , V_57 -> V_6 & 0xFFF ) ;
F_12 ( L_46 , V_57 -> V_60 ) ;
F_12 ( L_47 , V_57 -> V_61 ) ;
F_12 ( L_48 , V_57 -> V_62 [ 0 ] ) ;
F_12 ( L_49 , V_57 -> V_62 [ 1 ] ) ;
F_12 ( L_50 , V_57 -> V_63 ) ;
F_12 ( L_51 , V_57 -> V_64 ) ;
F_12 ( L_52 , ! ! ( V_57 -> V_65 & V_66 ) ) ;
F_12 ( L_53 , ! ! ( V_57 -> V_65 & V_67 ) ) ;
F_12 ( L_54 , ! ! ( V_57 -> V_65 &
V_68 ) ) ;
F_12 ( L_55 , ! ! ( V_57 -> V_65 &
V_69 ) ) ;
F_12 ( L_56 , ! ! ( V_57 -> V_65 &
V_70 ) ) ;
F_12 ( L_57 , ! ! ( V_57 -> V_65 &
V_71 ) ) ;
F_12 ( L_58 , ! ! ( V_57 -> V_72 & 0x01 ) ) ;
F_12 ( L_59 , ( V_57 -> V_73 >> 24 ) & 0xFF ) ;
F_12 ( L_60 , ( V_57 -> V_73 >> 16 ) & 0xFF ) ;
F_12 ( L_61 , ( V_57 -> V_73 >> 8 ) & 0xFF ) ;
F_12 ( L_62 , V_57 -> V_74 ) ;
F_12 ( L_63 , V_57 -> V_75 ) ;
V_22 += F_14 ( V_21 + V_22 , V_23 - V_22 , L_64 , L_65 ,
V_57 -> V_76 ) ;
V_59:
if ( V_22 > V_23 )
V_22 = V_23 ;
return V_22 ;
}
static T_2 F_13 ( struct V_1 * V_2 , bool V_55 ,
T_3 * V_21 , T_2 V_22 , T_2 V_23 )
{
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_2 V_77 = 0 , V_78 , integer ;
T_1 V_79 , V_80 , V_81 , V_82 , * V_83 ;
int V_84 , V_10 ;
bool V_85 = false ;
struct V_7 * V_8 = & V_2 -> V_3 . V_4 ;
struct V_15 * V_16 = F_8 ( V_2 ) ;
if ( ! F_9 ( V_2 ) ) {
if ( ! F_4 ( V_2 , V_86 ,
& V_81 ) ) {
F_16 ( V_16 , L_66 ) ;
return false ;
}
F_10 ( V_16 , V_17 , L_67 , V_81 ) ;
if ( V_81 != V_87 ) {
V_82 = F_17 ( V_81 ) ;
if ( V_82 == V_87 ) {
V_85 = true ;
V_83 = ( T_1 * ) ( & V_2 -> V_3 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
V_79 = F_17 ( * V_83 ) ;
* V_83 = V_79 ;
V_83 ++ ;
}
} else {
F_16 ( V_16 ,
L_68 ) ;
return - V_88 ;
}
}
}
F_10 ( V_16 , V_17 , L_69 ,
V_85 ? L_70 : L_71 ) ;
if ( V_85 )
V_78 = F_17 ( V_2 -> V_3 . V_4 . V_5 . V_61 ) ;
else
V_78 = V_2 -> V_3 . V_4 . V_5 . V_61 ;
if ( V_78 > sizeof( struct V_7 ) )
V_78 = sizeof( struct V_7 ) / sizeof( T_1 ) ;
else
V_78 = V_78 / sizeof( T_1 ) ;
V_83 = ( T_1 * ) ( & V_2 -> V_3 ) ;
for ( V_84 = 0 ; V_84 < V_78 ; V_84 ++ )
V_77 ^= * V_83 ++ ;
if ( V_85 ) {
V_80 = F_17 ( V_8 -> V_5 . V_61 ) ;
V_8 -> V_5 . V_61 = V_80 ;
V_80 = F_17 ( V_8 -> V_5 . V_60 ) ;
V_8 -> V_5 . V_60 = V_80 ;
V_80 = F_17 ( V_8 -> V_5 . V_6 ) ;
V_8 -> V_5 . V_6 = V_80 ;
V_80 = F_17 ( V_8 -> V_5 . V_62 [ 0 ] ) ;
V_8 -> V_5 . V_62 [ 0 ] = V_80 ;
V_80 = F_17 ( V_8 -> V_5 . V_62 [ 1 ] ) ;
V_8 -> V_5 . V_62 [ 1 ] = V_80 ;
V_80 = F_17 ( V_8 -> V_5 . V_89 ) ;
V_8 -> V_5 . V_89 = V_80 ;
V_80 = F_17 ( V_8 -> V_5 . V_90 ) ;
V_8 -> V_5 . V_90 = V_80 ;
V_80 = F_17 ( V_8 -> V_5 . V_91 ) ;
V_8 -> V_5 . V_91 = V_80 ;
integer = F_18 ( V_8 -> V_58 . V_27 ) ;
V_8 -> V_58 . V_27 = integer ;
for ( V_84 = 0 ; V_84 < V_92 ; V_84 ++ ) {
integer = F_18 ( V_8 -> V_58 . V_26 [ V_84 ] ) ;
V_8 -> V_58 . V_26 [ V_84 ] = integer ;
}
for ( V_84 = 0 ; V_84 < V_93 ; V_84 ++ ) {
V_80 = F_17 ( V_8 -> V_58 . V_94 [ V_84 ] . V_95 ) ;
V_8 -> V_58 . V_94 [ V_84 ] . V_95 = V_80 ;
}
}
if ( V_77 != 0xffff || V_2 -> V_96 -> V_97 ( V_2 ) != V_98
|| V_2 -> V_96 -> V_99 ( V_2 ) < V_100 ) {
F_16 ( V_16 , L_72 ,
V_77 , V_2 -> V_96 -> V_97 ( V_2 ) ) ;
return - V_88 ;
}
return 0 ;
}
static T_2 F_19 ( struct V_1 * V_2 ,
enum V_101 V_102 )
{
struct V_7 * V_8 = & V_2 -> V_3 . V_4 ;
struct V_24 * V_103 = & V_8 -> V_58 ;
struct V_56 * V_57 = & V_8 -> V_5 ;
T_1 V_104 ;
V_104 = V_57 -> V_6 & V_105 ;
switch ( V_102 ) {
case V_106 :
return V_103 -> V_37 [ 0 ] ;
case V_107 :
return F_20 ( V_57 -> V_76 ) ;
case V_108 :
return F_20 ( V_57 -> V_76 + 2 ) ;
case V_109 :
return F_20 ( V_57 -> V_76 + 4 ) ;
case V_110 :
return V_57 -> V_62 [ 0 ] ;
case V_111 :
return V_57 -> V_91 ;
case V_112 :
return V_57 -> V_65 ;
case V_113 :
return V_57 -> V_89 ;
case V_114 :
return V_104 ;
case V_115 :
return V_57 -> V_63 ;
case V_116 :
return V_57 -> V_64 ;
case V_117 :
return V_57 -> V_118 ;
case V_119 :
return V_57 -> V_75 ;
case V_120 :
if ( V_104 >= V_121 )
return V_57 -> V_122 ;
else
return 0 ;
case V_123 :
if ( V_104 >= V_124 )
return V_57 -> V_125 ;
else
return 0 ;
case V_126 :
return F_21 ( T_3 , V_103 -> V_28 [ 0 ] ,
V_103 -> V_28 [ 1 ] ) ;
default:
return 0 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_127 * V_128 ,
struct V_129 * V_130 ,
T_3 * V_131 , T_1 V_132 , T_4 * V_133 )
{
T_1 V_134 = 0 , V_135 = 0 , V_136 ;
bool V_137 ;
struct V_138 V_139 ;
F_23 ( V_2 , V_128 , & V_139 ) ;
for ( V_136 = 0 ; V_136 < V_132 ; V_136 ++ ) {
if ( V_131 [ V_136 ] == V_140 )
break;
}
V_137 = F_24 (
( T_3 ) F_25 ( V_139 . V_141 , F_26 ( V_128 ) ) ,
V_131 , V_136 , & V_134 , & V_135 ) ;
if ( V_137 ) {
* V_133 = ( T_4 ) V_130 [ V_134 ] . V_142 [ 0 ] [ 0 ] ;
} else {
* V_133 = ( ( T_4 ) V_130 [ V_134 ] . V_142 [ 0 ] [ 0 ] +
( T_4 ) V_130 [ V_135 ] . V_142 [ 0 ] [ 0 ] ) / 2 ;
}
}
static void F_27 ( struct V_1 * V_2 ,
T_5 V_143 , T_1 V_144 )
{
T_2 V_145 ;
T_2 V_146 ;
V_145 = F_28 ( V_2 , 0xa270 ) ;
V_145 = V_145 & 0xFCFFFFFF ;
V_145 = V_145 | ( 0x3 << 24 ) ;
F_29 ( V_2 , 0xa270 , V_145 ) ;
V_145 = F_28 ( V_2 , 0xb270 ) ;
V_145 = V_145 & 0xFCFFFFFF ;
V_145 = V_145 | ( 0x3 << 24 ) ;
F_29 ( V_2 , 0xb270 , V_145 ) ;
if ( V_144 == 0 ) {
V_145 = F_28 ( V_2 , 0xa398 ) ;
V_145 = V_145 & 0xff00ffff ;
V_146 = ( V_143 ) & 0xff ;
V_145 = V_145 | ( V_146 << 16 ) ;
F_29 ( V_2 , 0xa398 , V_145 ) ;
}
if ( V_144 == 1 ) {
V_145 = F_28 ( V_2 , 0xb398 ) ;
V_145 = V_145 & 0xff00ffff ;
V_146 = ( V_143 ) & 0xff ;
V_145 = V_145 | ( V_146 << 16 ) ;
F_29 ( V_2 , 0xb398 , V_145 ) ;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_147 * V_148 ;
struct V_129 * V_149 ;
T_3 * V_150 = NULL ;
T_1 V_151 ;
T_3 V_152 [ V_153 ] ;
T_1 V_154 [ V_155 ] ;
T_1 V_136 = 0 , V_84 , V_156 ;
T_1 V_157 , V_158 ;
T_1 V_159 [ V_160 ] = { 0 , 0 , 0 , 0 } ;
T_2 V_161 , V_162 , V_163 , V_164 ;
T_6 V_165 = 0 ;
struct V_7 * V_166 = & V_2 -> V_3 . V_4 ;
V_158 = V_166 -> V_58 . V_38 ;
if ( ( V_166 -> V_5 . V_6 & V_105 ) >=
V_121 )
V_151 = V_166 -> V_58 . V_42 ;
else
V_151 = ( T_1 ) ( F_31 ( F_28 ( V_2 , V_167 ) ,
V_168 ) ) ;
if ( F_26 ( V_128 ) ) {
V_150 = V_166 -> V_169 ;
V_136 = V_170 ;
if ( F_19 ( V_2 , V_119 ) ) {
V_149 =
(struct V_129 * ) V_166 -> V_171 [ 0 ] ;
V_2 -> V_172 = V_149 -> V_173 [ 0 ] [ 0 ] ;
}
}
V_157 = 0 ;
for ( V_84 = 1 ; V_84 <= V_155 ; V_84 ++ ) {
if ( ( V_158 >> ( V_155 - V_84 ) ) & 1 ) {
if ( V_157 >= V_160 )
break;
V_159 [ V_157 ] =
( T_1 ) ( V_155 - V_84 ) ;
V_157 ++ ;
}
}
F_32 ( V_2 , V_174 , V_175 ,
( V_157 - 1 ) & 0x3 ) ;
F_32 ( V_2 , V_174 , V_176 ,
V_159 [ 0 ] ) ;
F_32 ( V_2 , V_174 , V_177 ,
V_159 [ 1 ] ) ;
F_32 ( V_2 , V_174 , V_178 ,
V_159 [ 2 ] ) ;
for ( V_84 = 0 ; V_84 < V_92 ; V_84 ++ ) {
V_163 = V_84 * 0x1000 ;
if ( V_166 -> V_5 . V_63 & ( 1 << V_84 ) ) {
V_149 =
(struct V_129 * ) V_166 -> V_171 [ V_84 ] ;
if ( F_19 ( V_2 , V_119 ) ) {
T_4 V_143 ;
F_22 ( V_2 , V_128 ,
V_149 ,
V_150 , V_136 ,
& V_143 ) ;
F_27 ( V_2 , V_143 , V_84 ) ;
} else {
V_148 =
(struct V_147 * )
V_166 -> V_171 [ V_84 ] ;
F_33 ( V_2 , V_128 ,
V_148 ,
V_150 , V_136 ,
V_151 ,
V_154 ,
V_152 ,
V_157 ) ;
}
F_34 ( V_2 ) ;
if ( V_84 == 0 ) {
if ( ! F_19 ( V_2 ,
V_119 ) ) {
V_164 = F_35 ( V_151 ,
V_168 )
| F_35 ( V_154 [ 0 ] ,
V_179 )
| F_35 ( V_154 [ 1 ] ,
V_180 )
| F_35 ( V_154 [ 2 ] ,
V_181 )
| F_35 ( V_154 [ 3 ] ,
V_182 ) ;
F_29 ( V_2 ,
V_167 + V_163 ,
V_164 ) ;
}
}
if ( ( T_5 ) V_183 !=
V_166 -> V_5 . V_74 ) {
V_165 = ( T_1 ) ( V_166 -> V_5 . V_74 -
( T_5 ) V_183 ) ;
V_165 *= 2 ;
for ( V_156 = 0 ; V_156 < ( ( T_1 ) V_153 - V_165 ) ; V_156 ++ )
V_152 [ V_156 ] = V_152 [ V_156 + V_165 ] ;
for ( V_156 = ( T_1 ) ( V_153 - V_165 ) ;
V_156 < V_153 ; V_156 ++ )
V_152 [ V_156 ] =
V_152 [ V_153 - V_165 ] ;
}
if ( ! F_19 ( V_2 , V_119 ) ) {
V_162 = V_184 +
( 672 << 2 ) + V_163 ;
for ( V_156 = 0 ; V_156 < 32 ; V_156 ++ ) {
V_161 = F_36 ( & V_152 [ 4 * V_156 ] ) ;
F_29 ( V_2 , V_162 , V_161 ) ;
V_162 += 4 ;
}
}
F_37 ( V_2 ) ;
}
}
}
static void F_38 ( struct V_1 * V_2 ,
struct V_127 * V_128 ,
T_6 * V_185 ,
T_1 V_186 ,
T_1 V_187 ,
T_1 V_188 )
{
#define F_39 \
(((cfgCtl & ~CTL_MODE_M) | (pCtlMode[ctlMode] & CTL_MODE_M)) == \
pEepData->ctlIndex[i])
#define F_40 \
(((cfgCtl & ~CTL_MODE_M) | (pCtlMode[ctlMode] & CTL_MODE_M)) == \
((pEepData->ctlIndex[i] & CTL_MODE_M) | SD_NO_CTL))
T_1 V_189 ;
int V_84 ;
struct V_190 * V_191 ;
struct V_192 V_193 = { 0 , { 0 , 0 , 0 , 0 } } ,
V_194 = { 0 , { 0 , 0 , 0 , 0 } } ;
struct V_192 V_195 = { 0 , { 0 , 0 , 0 , 0 } } ,
V_196 = { 0 , { 0 , 0 , 0 , 0 } } ;
struct V_197 V_198 ,
V_199 = { 0 , { 0 , 0 , 0 , 0 } } ;
T_1 V_200 = 0 , V_201 ;
static const T_1 V_202 [] = {
V_203 , V_204 , V_205 ,
V_206 , V_207 , V_208
} ;
T_1 V_209 = 0 ;
const T_1 * V_210 = NULL ;
T_1 V_211 , V_212 ;
struct V_138 V_139 ;
int V_213 ;
T_1 V_214 ;
struct V_7 * V_166 = & V_2 -> V_3 . V_4 ;
V_213 = V_2 -> V_215 ;
F_23 ( V_2 , V_128 , & V_139 ) ;
V_200 = F_41 ( V_2 , V_188 ,
V_187 ) ;
if ( F_26 ( V_128 ) ) {
V_209 =
F_42 ( V_202 ) - V_216 ;
V_210 = V_202 ;
F_43 ( V_2 , V_128 ,
V_166 -> V_217 ,
V_218 ,
& V_194 , 4 , false ) ;
F_43 ( V_2 , V_128 ,
V_166 -> V_219 ,
V_220 ,
& V_193 , 4 , false ) ;
F_44 ( V_2 , V_128 ,
V_166 -> V_221 ,
V_220 ,
& V_198 , 8 , false ) ;
if ( F_45 ( V_128 ) ) {
V_209 = F_42 ( V_202 ) ;
F_44 ( V_2 , V_128 ,
V_166 -> V_222 ,
V_223 ,
& V_199 , 8 , true ) ;
F_43 ( V_2 , V_128 ,
V_166 -> V_217 ,
V_218 ,
& V_196 , 4 , true ) ;
F_43 ( V_2 , V_128 ,
V_166 -> V_219 ,
V_220 ,
& V_195 , 4 , true ) ;
}
}
for ( V_211 = 0 ; V_211 < V_209 ; V_211 ++ ) {
bool V_224 =
( V_210 [ V_211 ] == V_208 ) ? true : false ;
if ( V_224 )
V_212 = V_139 . V_141 ;
else if ( V_210 [ V_211 ] & V_225 )
V_212 = V_139 . V_226 ;
else
V_212 = V_139 . V_227 ;
V_189 = V_228 ;
for ( V_84 = 0 ; ( V_84 < V_229 ) && V_166 -> V_230 [ V_84 ] ; V_84 ++ ) {
struct V_231 * V_232 ;
if ( F_39 || F_40 ) {
V_191 = & ( V_166 -> V_233 [ V_84 ] ) ;
V_232 =
V_191 -> V_234 [ F_46 ( V_213 ) - 1 ] ;
V_214 = F_47 ( V_212 ,
V_232 ,
F_26 ( V_128 ) ,
V_235 ) ;
if ( ( V_186 & ~ V_236 ) == V_237 ) {
V_189 = F_48 ( V_189 ,
V_214 ) ;
} else {
V_189 = V_214 ;
break;
}
}
}
V_201 = ( T_3 ) F_48 ( V_189 , V_200 ) ;
switch ( V_210 [ V_211 ] ) {
case V_203 :
for ( V_84 = 0 ; V_84 < F_42 ( V_194 . V_238 ) ; V_84 ++ ) {
V_194 . V_238 [ V_84 ] =
( T_3 ) F_48 ( ( T_1 ) V_194 . V_238 [ V_84 ] ,
V_201 ) ;
}
break;
case V_239 :
case V_204 :
for ( V_84 = 0 ; V_84 < F_42 ( V_193 . V_238 ) ; V_84 ++ ) {
V_193 . V_238 [ V_84 ] =
( T_3 ) F_48 ( ( T_1 ) V_193 . V_238 [ V_84 ] ,
V_201 ) ;
}
break;
case V_240 :
case V_205 :
for ( V_84 = 0 ; V_84 < F_42 ( V_198 . V_238 ) ; V_84 ++ ) {
V_198 . V_238 [ V_84 ] =
( T_3 ) F_48 ( ( T_1 ) V_198 . V_238 [ V_84 ] ,
V_201 ) ;
}
break;
case V_206 :
V_196 . V_238 [ 0 ] =
( T_3 ) F_48 ( ( T_1 ) V_196 . V_238 [ 0 ] ,
V_201 ) ;
break;
case V_241 :
case V_207 :
V_195 . V_238 [ 0 ] =
( T_3 ) F_48 ( ( T_1 ) V_195 . V_238 [ 0 ] ,
V_201 ) ;
break;
case V_242 :
case V_208 :
for ( V_84 = 0 ; V_84 < F_42 ( V_199 . V_238 ) ; V_84 ++ ) {
V_199 . V_238 [ V_84 ] =
( T_3 ) F_48 ( ( T_1 ) V_199 . V_238 [ V_84 ] ,
V_201 ) ;
}
break;
default:
break;
}
}
V_185 [ V_243 ] =
V_185 [ V_244 ] =
V_185 [ V_245 ] =
V_185 [ V_246 ] =
V_185 [ V_247 ] = V_193 . V_238 [ 0 ] ;
V_185 [ V_248 ] = V_193 . V_238 [ 1 ] ;
V_185 [ V_249 ] = V_193 . V_238 [ 2 ] ;
V_185 [ V_250 ] = V_193 . V_238 [ 3 ] ;
V_185 [ V_251 ] = V_193 . V_238 [ 0 ] ;
for ( V_84 = 0 ; V_84 < F_42 ( V_198 . V_238 ) ; V_84 ++ )
V_185 [ V_252 + V_84 ] = V_198 . V_238 [ V_84 ] ;
if ( F_26 ( V_128 ) ) {
V_185 [ V_253 ] = V_194 . V_238 [ 0 ] ;
V_185 [ V_254 ] =
V_185 [ V_255 ] = V_194 . V_238 [ 1 ] ;
V_185 [ V_256 ] =
V_185 [ V_257 ] = V_194 . V_238 [ 2 ] ;
V_185 [ V_258 ] =
V_185 [ V_259 ] = V_194 . V_238 [ 3 ] ;
}
if ( F_45 ( V_128 ) ) {
for ( V_84 = 0 ; V_84 < F_42 ( V_199 . V_238 ) ; V_84 ++ )
V_185 [ V_260 + V_84 ] = V_199 . V_238 [ V_84 ] ;
V_185 [ V_261 ] = V_199 . V_238 [ 0 ] ;
V_185 [ V_262 ] = V_199 . V_238 [ 0 ] ;
V_185 [ V_263 ] = V_195 . V_238 [ 0 ] ;
if ( F_26 ( V_128 ) )
V_185 [ V_264 ] = V_196 . V_238 [ 0 ] ;
}
#undef F_39
#undef F_40
}
static void F_49 ( struct V_1 * V_2 ,
struct V_127 * V_128 , T_1 V_186 ,
T_3 V_265 ,
T_3 V_188 , bool V_266 )
{
struct V_267 * V_268 = F_50 ( V_2 ) ;
struct V_7 * V_166 = & V_2 -> V_3 . V_4 ;
struct V_24 * V_103 = & V_166 -> V_58 ;
T_6 V_185 [ V_269 ] ;
T_3 V_46 = 2 ;
int V_84 ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
if ( ( V_166 -> V_5 . V_6 & V_105 ) >=
V_121 )
V_46 = V_103 -> V_46 ;
F_38 ( V_2 , V_128 ,
& V_185 [ 0 ] , V_186 ,
V_265 ,
V_188 ) ;
F_30 ( V_2 , V_128 ) ;
V_268 -> V_270 = 0 ;
for ( V_84 = 0 ; V_84 < F_42 ( V_185 ) ; V_84 ++ ) {
if ( V_185 [ V_84 ] > V_228 )
V_185 [ V_84 ] = V_228 ;
if ( V_185 [ V_84 ] > V_268 -> V_270 )
V_268 -> V_270 = V_185 [ V_84 ] ;
}
F_51 ( V_2 ) ;
if ( V_266 )
return;
for ( V_84 = 0 ; V_84 < V_269 ; V_84 ++ )
V_185 [ V_84 ] -= V_183 * 2 ;
F_34 ( V_2 ) ;
F_29 ( V_2 , V_271 ,
F_52 ( V_185 [ V_246 ] , 24 )
| F_52 ( V_185 [ V_245 ] , 16 )
| F_52 ( V_185 [ V_244 ] , 8 )
| F_52 ( V_185 [ V_243 ] , 0 ) ) ;
F_29 ( V_2 , V_272 ,
F_52 ( V_185 [ V_250 ] , 24 )
| F_52 ( V_185 [ V_249 ] , 16 )
| F_52 ( V_185 [ V_248 ] , 8 )
| F_52 ( V_185 [ V_247 ] , 0 ) ) ;
if ( F_26 ( V_128 ) ) {
F_29 ( V_2 , V_273 ,
F_52 ( V_185 [ V_254 ] , 24 )
| F_52 ( V_185 [ V_255 ] , 16 )
| F_52 ( V_185 [ V_251 ] , 8 )
| F_52 ( V_185 [ V_253 ] , 0 ) ) ;
F_29 ( V_2 , V_274 ,
F_52 ( V_185 [ V_258 ] , 24 )
| F_52 ( V_185 [ V_259 ] , 16 )
| F_52 ( V_185 [ V_256 ] , 8 )
| F_52 ( V_185 [ V_257 ] , 0 ) ) ;
}
F_29 ( V_2 , V_275 ,
F_52 ( V_185 [ V_276 ] , 24 )
| F_52 ( V_185 [ V_277 ] , 16 )
| F_52 ( V_185 [ V_278 ] , 8 )
| F_52 ( V_185 [ V_252 ] , 0 ) ) ;
F_29 ( V_2 , V_279 ,
F_52 ( V_185 [ V_280 ] , 24 )
| F_52 ( V_185 [ V_281 ] , 16 )
| F_52 ( V_185 [ V_282 ] , 8 )
| F_52 ( V_185 [ V_283 ] , 0 ) ) ;
if ( F_45 ( V_128 ) ) {
if ( F_19 ( V_2 , V_119 ) ) {
F_29 ( V_2 , V_284 ,
F_52 ( V_185 [ V_285 ] , 24 )
| F_52 ( V_185 [ V_286 ] , 16 )
| F_52 ( V_185 [ V_287 ] , 8 )
| F_52 ( V_185 [ V_260 ] , 0 ) ) ;
F_29 ( V_2 , V_288 ,
F_52 ( V_185 [ V_289 ] , 24 )
| F_52 ( V_185 [ V_290 ] , 16 )
| F_52 ( V_185 [ V_291 ] , 8 )
| F_52 ( V_185 [ V_292 ] , 0 ) ) ;
} else {
F_29 ( V_2 , V_284 ,
F_52 ( V_185 [ V_285 ] +
V_46 , 24 )
| F_52 ( V_185 [ V_286 ] +
V_46 , 16 )
| F_52 ( V_185 [ V_287 ] +
V_46 , 8 )
| F_52 ( V_185 [ V_260 ] +
V_46 , 0 ) ) ;
F_29 ( V_2 , V_288 ,
F_52 ( V_185 [ V_289 ] +
V_46 , 24 )
| F_52 ( V_185 [ V_290 ] +
V_46 , 16 )
| F_52 ( V_185 [ V_291 ] +
V_46 , 8 )
| F_52 ( V_185 [ V_292 ] +
V_46 , 0 ) ) ;
}
F_29 ( V_2 , V_293 ,
F_52 ( V_185 [ V_263 ] , 24 )
| F_52 ( V_185 [ V_264 ] , 16 )
| F_52 ( V_185 [ V_261 ] , 8 )
| F_52 ( V_185 [ V_262 ] , 0 ) ) ;
}
F_37 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_7 * V_8 = & V_2 -> V_3 . V_4 ;
struct V_24 * V_103 = & V_8 -> V_58 ;
T_2 V_163 , V_164 ;
T_3 V_294 ;
int V_84 ;
V_103 = & V_8 -> V_58 ;
F_29 ( V_2 , V_295 , V_103 -> V_27 ) ;
for ( V_84 = 0 ; V_84 < V_92 ; V_84 ++ ) {
V_163 = V_84 * 0x1000 ;
F_29 ( V_2 , V_296 + V_163 ,
V_103 -> V_26 [ V_84 ] ) ;
F_29 ( V_2 , F_54 ( 0 ) + V_163 ,
( F_28 ( V_2 , F_54 ( 0 ) + V_163 )
& ~ ( V_297 |
V_298 ) ) |
F_35 ( V_103 -> V_40 [ V_84 ] ,
V_298 ) |
F_35 ( V_103 -> V_41 [ V_84 ] ,
V_297 ) ) ;
V_294 = V_103 -> V_30 [ V_84 ] ;
F_32 ( V_2 , V_299 + V_163 ,
V_300 ,
V_103 -> V_48 [ V_84 ] ) ;
F_32 ( V_2 , V_299 + V_163 ,
V_301 ,
V_103 -> V_47 [ V_84 ] ) ;
F_32 ( V_2 , V_302 + V_163 ,
V_303 ,
V_294 ) ;
F_32 ( V_2 , V_302 + V_163 ,
V_304 ,
V_103 -> V_31 [ V_84 ] ) ;
}
if ( F_45 ( V_128 ) )
F_32 ( V_2 , V_305 ,
V_306 , V_103 -> V_49 ) ;
else
F_32 ( V_2 , V_305 ,
V_306 , V_103 -> V_29 ) ;
F_32 ( V_2 , V_307 ,
V_308 , V_103 -> V_32 ) ;
F_29 ( V_2 , V_309 ,
F_35 ( V_103 -> V_33 , V_310 )
| F_35 ( V_103 -> V_33 , V_311 )
| F_35 ( V_103 -> V_35 , V_312 )
| F_35 ( V_103 -> V_35 , V_313 ) ) ;
F_32 ( V_2 , V_314 ,
V_315 , V_103 -> V_34 ) ;
F_32 ( V_2 , V_316 ,
V_317 , V_103 -> V_36 ) ;
F_32 ( V_2 , V_318 ,
V_319 , V_103 -> V_36 ) ;
V_164 = F_28 ( V_2 , V_320 ) ;
V_164 &= ~ ( V_321 |
V_322 |
V_323 |
V_324 |
V_325 |
V_326 ) ;
V_164 |= ( F_35 ( V_103 -> V_50 , V_321 ) |
F_35 ( V_103 -> V_327 , V_322 ) |
F_35 ( V_103 -> V_51 , V_323 ) |
F_35 ( V_103 -> V_52 , V_324 ) |
F_35 ( V_103 -> V_53 , V_325 ) |
F_35 ( V_103 -> V_54 , V_326 ) ) ;
F_55 ( V_2 , V_320 , V_164 ) ;
V_164 = F_28 ( V_2 , V_328 ) ;
V_164 &= ~ ( V_321 |
V_322 |
V_323 |
V_324 |
V_325 |
V_326 ) ;
V_164 |= ( F_35 ( V_103 -> V_50 , V_321 ) |
F_35 ( V_103 -> V_327 , V_322 ) |
F_35 ( V_103 -> V_51 , V_323 ) |
F_35 ( V_103 -> V_52 , V_324 ) |
F_35 ( V_103 -> V_53 , V_325 ) |
F_35 ( V_103 -> V_54 , V_326 ) ) ;
F_55 ( V_2 , V_328 , V_164 ) ;
F_32 ( V_2 , V_329 ,
V_330 , V_103 -> V_44 ) ;
F_32 ( V_2 , V_329 ,
V_331 , V_103 -> V_45 ) ;
F_56 ( V_2 , V_332 ,
V_333 ,
V_334 ,
V_103 -> V_43 ) ;
}
static T_1 F_57 ( struct V_1 * V_2 ,
T_1 V_84 , bool V_335 )
{
return V_2 -> V_3 . V_4 . V_58 . V_94 [ V_84 ] . V_95 ;
}
