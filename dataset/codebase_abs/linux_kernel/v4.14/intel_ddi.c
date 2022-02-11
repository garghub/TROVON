enum V_1 F_1 ( struct V_2 * V_3 )
{
switch ( V_3 -> type ) {
case V_4 :
return F_2 ( & V_3 -> V_5 ) -> V_6 -> V_1 ;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return F_3 ( & V_3 -> V_5 ) -> V_1 ;
case V_11 :
return V_12 ;
default:
F_4 ( V_3 -> type ) ;
return V_13 ;
}
}
static const struct V_14 *
F_5 ( struct V_15 * V_16 , int * V_17 )
{
if ( V_16 -> V_18 . V_19 . V_20 ) {
* V_17 = F_6 ( V_21 ) ;
return V_21 ;
} else {
* V_17 = F_6 ( V_22 ) ;
return V_22 ;
}
}
static const struct V_14 *
F_7 ( struct V_15 * V_16 , int * V_17 )
{
if ( F_8 ( V_16 ) ) {
* V_17 = F_6 ( V_23 ) ;
return V_23 ;
} else if ( F_9 ( V_16 ) ) {
* V_17 = F_6 ( V_24 ) ;
return V_24 ;
} else {
* V_17 = F_6 ( V_25 ) ;
return V_25 ;
}
}
static const struct V_14 *
F_10 ( struct V_15 * V_16 , int * V_17 )
{
if ( F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_26 ) ;
return V_26 ;
} else if ( F_12 ( V_16 ) || F_13 ( V_16 ) ) {
* V_17 = F_6 ( V_27 ) ;
return V_27 ;
} else {
* V_17 = F_6 ( V_28 ) ;
return V_28 ;
}
}
static const struct V_14 *
F_14 ( struct V_15 * V_16 , int * V_17 )
{
if ( V_16 -> V_18 . V_19 . V_20 ) {
if ( F_8 ( V_16 ) || F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_29 ) ;
return V_29 ;
} else if ( F_9 ( V_16 ) || F_12 ( V_16 ) ||
F_13 ( V_16 ) ) {
* V_17 = F_6 ( V_30 ) ;
return V_30 ;
} else {
* V_17 = F_6 ( V_31 ) ;
return V_31 ;
}
}
if ( F_15 ( V_16 ) || F_16 ( V_16 ) )
return F_10 ( V_16 , V_17 ) ;
else
return F_7 ( V_16 , V_17 ) ;
}
static const struct V_14 *
F_17 ( struct V_15 * V_16 , int * V_17 )
{
if ( F_8 ( V_16 ) || F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_32 ) ;
return V_32 ;
} else {
* V_17 = F_6 ( V_33 ) ;
return V_33 ;
}
}
static int F_18 ( struct V_15 * V_16 , enum V_1 V_1 )
{
int V_34 ;
int V_35 ;
int V_36 ;
V_35 = V_16 -> V_18 . V_37 [ V_1 ] . V_38 ;
if ( F_19 ( V_16 ) )
return V_35 ;
if ( F_20 ( V_16 ) ) {
F_17 ( V_16 , & V_34 ) ;
V_36 = 8 ;
} else if ( F_21 ( V_16 ) ) {
V_34 = F_6 ( V_39 ) ;
V_36 = 7 ;
} else if ( F_22 ( V_16 ) ) {
V_34 = F_6 ( V_40 ) ;
V_36 = 6 ;
} else {
F_23 ( 1 , L_1 ) ;
V_34 = F_6 ( V_39 ) ;
V_36 = 7 ;
}
if ( V_35 == V_41 ||
V_35 >= V_34 )
V_35 = V_36 ;
return V_35 ;
}
static const struct V_14 *
F_24 ( struct V_15 * V_16 ,
int * V_17 )
{
if ( F_15 ( V_16 ) || F_16 ( V_16 ) ) {
return F_10 ( V_16 , V_17 ) ;
} else if ( F_25 ( V_16 ) ) {
return F_7 ( V_16 , V_17 ) ;
} else if ( F_21 ( V_16 ) ) {
* V_17 = F_6 ( V_22 ) ;
return V_22 ;
} else if ( F_22 ( V_16 ) ) {
* V_17 = F_6 ( V_42 ) ;
return V_42 ;
}
* V_17 = 0 ;
return NULL ;
}
static const struct V_14 *
F_26 ( struct V_15 * V_16 ,
int * V_17 )
{
if ( F_20 ( V_16 ) ) {
return F_14 ( V_16 , V_17 ) ;
} else if ( F_21 ( V_16 ) ) {
return F_5 ( V_16 , V_17 ) ;
} else if ( F_22 ( V_16 ) ) {
* V_17 = F_6 ( V_42 ) ;
return V_42 ;
}
* V_17 = 0 ;
return NULL ;
}
static const struct V_14 *
F_27 ( struct V_15 * V_16 ,
int * V_17 )
{
if ( F_21 ( V_16 ) ) {
* V_17 = F_6 ( V_43 ) ;
return V_43 ;
} else if ( F_22 ( V_16 ) ) {
* V_17 = F_6 ( V_44 ) ;
return V_44 ;
}
* V_17 = 0 ;
return NULL ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
T_1 V_46 = 0 ;
int V_47 , V_17 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_48 ;
if ( F_19 ( V_16 ) )
return;
switch ( V_3 -> type ) {
case V_8 :
V_48 = F_26 ( V_16 ,
& V_17 ) ;
break;
case V_7 :
V_48 = F_24 ( V_16 ,
& V_17 ) ;
break;
case V_11 :
V_48 = F_27 ( V_16 ,
& V_17 ) ;
break;
default:
F_4 ( V_3 -> type ) ;
return;
}
if ( F_20 ( V_16 ) ) {
if ( V_16 -> V_18 . V_37 [ V_1 ] . V_49 )
V_46 = V_50 ;
if ( F_30 ( V_3 -> type == V_8 &&
V_1 != V_13 && V_1 != V_12 &&
V_17 > 9 ) )
V_17 = 9 ;
}
for ( V_47 = 0 ; V_47 < V_17 ; V_47 ++ ) {
F_31 ( F_32 ( V_1 , V_47 ) ,
V_48 [ V_47 ] . V_51 | V_46 ) ;
F_31 ( F_33 ( V_1 , V_47 ) ,
V_48 [ V_47 ] . V_52 ) ;
}
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
T_1 V_46 = 0 ;
int V_34 , V_35 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_53 ;
if ( F_19 ( V_16 ) )
return;
V_35 = F_18 ( V_16 , V_1 ) ;
if ( F_20 ( V_16 ) ) {
V_53 = F_17 ( V_16 , & V_34 ) ;
if ( V_16 -> V_18 . V_37 [ V_1 ] . V_54 )
V_46 = V_50 ;
} else if ( F_21 ( V_16 ) ) {
V_53 = V_39 ;
V_34 = F_6 ( V_39 ) ;
} else if ( F_22 ( V_16 ) ) {
V_53 = V_40 ;
V_34 = F_6 ( V_40 ) ;
} else {
F_23 ( 1 , L_1 ) ;
V_53 = V_39 ;
V_34 = F_6 ( V_39 ) ;
}
F_31 ( F_32 ( V_1 , 9 ) ,
V_53 [ V_35 ] . V_51 | V_46 ) ;
F_31 ( F_33 ( V_1 , 9 ) ,
V_53 [ V_35 ] . V_52 ) ;
}
static void F_35 ( struct V_15 * V_16 ,
enum V_1 V_1 )
{
T_2 V_55 = F_36 ( V_1 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 16 ; V_47 ++ ) {
F_37 ( 1 ) ;
if ( F_38 ( V_55 ) & V_56 )
return;
}
F_39 ( L_2 , F_40 ( V_1 ) ) ;
}
static T_3 F_41 ( struct V_57 * V_58 )
{
switch ( V_58 -> V_59 ) {
case V_60 :
return V_61 ;
case V_62 :
return V_63 ;
case V_64 :
return V_65 ;
case V_66 :
return V_67 ;
case V_68 :
return V_69 ;
case V_70 :
return V_71 ;
default:
F_4 ( V_58 -> V_59 ) ;
return V_72 ;
}
}
void F_42 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_77 * V_45 = V_74 -> V_5 . V_45 ;
struct V_15 * V_16 = F_29 ( V_45 ) ;
struct V_2 * V_3 ;
T_1 V_78 , V_47 , V_79 , V_80 ;
F_43 (dev, &crtc->base, encoder) {
F_30 ( V_3 -> type != V_11 ) ;
F_28 ( V_3 ) ;
}
F_31 ( F_44 ( V_81 ) , F_45 ( 2 ) |
F_46 ( 2 ) |
V_82 | V_83 ) ;
V_79 = V_16 -> V_84 | V_85 |
V_86 |
F_47 ( V_76 -> V_87 ) ;
F_31 ( F_48 ( V_81 ) , V_79 ) ;
F_49 ( F_48 ( V_81 ) ) ;
F_37 ( 220 ) ;
V_79 |= V_88 ;
F_31 ( F_48 ( V_81 ) , V_79 ) ;
V_80 = F_41 ( V_76 -> V_89 ) ;
F_31 ( F_50 ( V_12 ) , V_80 ) ;
F_30 ( V_80 != V_65 ) ;
for ( V_47 = 0 ; V_47 < F_6 ( V_44 ) * 2 ; V_47 ++ ) {
F_31 ( F_51 ( V_12 ) ,
V_90 |
V_91 |
V_92 |
V_93 ) ;
F_31 ( F_36 ( V_12 ) ,
V_94 |
( ( V_76 -> V_87 - 1 ) << 1 ) |
F_52 ( V_47 / 2 ) ) ;
F_49 ( F_36 ( V_12 ) ) ;
F_37 ( 600 ) ;
F_31 ( F_53 ( V_81 ) , F_54 ( 64 ) ) ;
V_79 |= V_95 | V_96 ;
F_31 ( F_48 ( V_81 ) , V_79 ) ;
F_49 ( F_48 ( V_81 ) ) ;
F_37 ( 30 ) ;
V_78 = F_38 ( F_44 ( V_81 ) ) ;
V_78 &= ~ ( V_97 | V_98 ) ;
F_31 ( F_44 ( V_81 ) , V_78 ) ;
F_49 ( F_44 ( V_81 ) ) ;
F_37 ( 5 ) ;
V_78 = F_38 ( F_55 ( V_12 ) ) ;
if ( V_78 & V_99 ) {
F_56 ( L_3 , V_47 ) ;
break;
}
if ( V_47 == F_6 ( V_44 ) * 2 - 1 ) {
F_39 ( L_4 ) ;
break;
}
V_79 &= ~ V_95 ;
F_31 ( F_48 ( V_81 ) , V_79 ) ;
F_49 ( F_48 ( V_81 ) ) ;
V_78 = F_38 ( F_36 ( V_12 ) ) ;
V_78 &= ~ V_94 ;
F_31 ( F_36 ( V_12 ) , V_78 ) ;
F_49 ( F_36 ( V_12 ) ) ;
V_78 = F_38 ( F_51 ( V_12 ) ) ;
V_78 &= ~ ( V_93 | V_100 ) ;
V_78 |= V_92 ;
F_31 ( F_51 ( V_12 ) , V_78 ) ;
F_49 ( F_51 ( V_12 ) ) ;
F_35 ( V_16 , V_12 ) ;
V_78 = F_38 ( F_44 ( V_81 ) ) ;
V_78 &= ~ ( V_97 | V_98 ) ;
V_78 |= F_45 ( 2 ) | F_46 ( 2 ) ;
F_31 ( F_44 ( V_81 ) , V_78 ) ;
F_49 ( F_44 ( V_81 ) ) ;
}
F_31 ( F_51 ( V_12 ) ,
V_90 |
V_101 |
V_91 |
V_93 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_102 * V_102 = F_58 ( & V_3 -> V_5 ) ;
struct V_103 * V_104 =
F_3 ( & V_3 -> V_5 ) ;
V_102 -> V_105 = V_104 -> V_106 |
V_94 | F_52 ( 0 ) ;
V_102 -> V_105 |= F_59 ( V_102 -> V_107 ) ;
}
static struct V_2 *
F_60 ( struct V_73 * V_74 )
{
struct V_77 * V_45 = V_74 -> V_5 . V_45 ;
struct V_2 * V_3 , * V_108 = NULL ;
int V_109 = 0 ;
F_43 (dev, &crtc->base, encoder) {
V_108 = V_3 ;
V_109 ++ ;
}
if ( V_109 != 1 )
F_23 ( 1 , L_5 , V_109 ,
F_61 ( V_74 -> V_110 ) ) ;
F_62 ( V_108 == NULL ) ;
return V_108 ;
}
struct V_2 *
F_63 ( struct V_75 * V_76 )
{
struct V_73 * V_74 = F_64 ( V_76 -> V_5 . V_74 ) ;
struct V_2 * V_108 = NULL ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
int V_109 = 0 ;
int V_47 ;
V_112 = V_76 -> V_5 . V_112 ;
F_65 (state, connector, connector_state, i) {
if ( V_116 -> V_74 != V_76 -> V_5 . V_74 )
continue;
V_108 = F_66 ( V_116 -> V_117 ) ;
V_109 ++ ;
}
F_23 ( V_109 != 1 , L_5 , V_109 ,
F_61 ( V_74 -> V_110 ) ) ;
F_62 ( V_108 == NULL ) ;
return V_108 ;
}
static int F_67 ( struct V_15 * V_16 ,
T_2 V_55 )
{
int V_118 = V_119 ;
int V_120 , V_121 , V_122 ;
T_1 V_123 ;
V_123 = F_38 ( V_55 ) ;
switch ( V_123 & V_124 ) {
case V_125 :
case V_126 :
V_118 = 135 ;
break;
case V_127 :
V_118 = V_119 ;
break;
default:
F_23 ( 1 , L_6 ) ;
return 0 ;
}
V_122 = V_123 & V_128 ;
V_121 = ( V_123 & V_129 ) >> V_130 ;
V_120 = ( V_123 & V_131 ) >> V_132 ;
return ( V_118 * V_120 * 100 ) / ( V_121 * V_122 ) ;
}
static int F_68 ( struct V_15 * V_16 ,
T_3 V_133 )
{
T_2 V_134 , V_135 ;
T_3 V_136 , V_137 ;
T_3 V_138 , V_139 , V_140 , V_141 ;
V_134 = F_69 ( V_133 ) ;
V_135 = F_70 ( V_133 ) ;
V_136 = F_38 ( V_134 ) ;
V_137 = F_38 ( V_135 ) ;
V_138 = V_137 & V_142 ;
V_140 = V_137 & V_143 ;
if ( V_137 & F_71 ( 1 ) )
V_139 = ( V_137 & V_144 ) >> 8 ;
else
V_139 = 1 ;
switch ( V_138 ) {
case V_145 :
V_138 = 1 ;
break;
case V_146 :
V_138 = 2 ;
break;
case V_147 :
V_138 = 3 ;
break;
case V_148 :
V_138 = 7 ;
break;
}
switch ( V_140 ) {
case V_149 :
V_140 = 5 ;
break;
case V_150 :
V_140 = 2 ;
break;
case V_151 :
V_140 = 3 ;
break;
case V_152 :
V_140 = 1 ;
break;
}
V_141 = ( V_136 & V_153 ) * 24 * 1000 ;
V_141 += ( ( ( V_136 & V_154 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_141 / ( V_138 * V_139 * V_140 * 5 ) ;
}
static int F_72 ( struct V_15 * V_16 ,
T_3 V_155 )
{
T_3 V_156 , V_157 ;
T_3 V_138 , V_139 , V_140 , V_141 , V_158 ;
V_156 = F_38 ( F_73 ( V_155 ) ) ;
V_157 = F_38 ( F_74 ( V_155 ) ) ;
V_138 = V_157 & V_159 ;
V_140 = V_157 & V_160 ;
if ( V_157 & F_75 ( 1 ) )
V_139 = ( V_157 & V_161 ) >>
V_162 ;
else
V_139 = 1 ;
switch ( V_138 ) {
case V_163 :
V_138 = 2 ;
break;
case V_164 :
V_138 = 3 ;
break;
case V_165 :
V_138 = 5 ;
break;
case V_166 :
V_138 = 7 ;
break;
}
switch ( V_140 ) {
case V_167 :
V_140 = 1 ;
break;
case V_168 :
V_140 = 2 ;
break;
case V_169 :
V_140 = 4 ;
break;
}
V_158 = V_16 -> V_170 . V_171 . V_172 ;
V_141 = ( V_156 & V_173 ) * V_158 ;
V_141 += ( ( ( V_156 & V_174 ) >>
V_175 ) * V_158 ) / 0x8000 ;
return V_141 / ( V_138 * V_139 * V_140 * 5 ) ;
}
static void F_76 ( struct V_75 * V_176 )
{
int V_177 ;
if ( V_176 -> V_178 )
V_177 = F_77 ( V_176 -> V_179 ,
& V_176 -> V_180 ) ;
else if ( F_78 ( V_176 ) )
V_177 = F_77 ( V_176 -> V_179 ,
& V_176 -> V_181 ) ;
else if ( V_176 -> V_182 && V_176 -> V_183 == 36 )
V_177 = V_176 -> V_179 * 2 / 3 ;
else
V_177 = V_176 -> V_179 ;
if ( V_176 -> V_184 )
V_177 *= 2 ;
if ( V_176 -> V_185 )
V_177 /= V_176 -> V_185 ;
V_176 -> V_5 . V_186 . V_187 = V_177 ;
}
static void F_79 ( struct V_2 * V_3 ,
struct V_75 * V_176 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
int V_188 = 0 ;
T_3 V_156 , V_155 ;
V_155 = F_80 ( V_16 , V_176 -> V_89 ) ;
V_156 = F_38 ( F_73 ( V_155 ) ) ;
if ( V_156 & V_189 ) {
V_188 = F_72 ( V_16 , V_155 ) ;
} else {
V_188 = V_156 & V_190 ;
switch ( V_188 ) {
case V_191 :
V_188 = 81000 ;
break;
case V_192 :
V_188 = 108000 ;
break;
case V_193 :
V_188 = 135000 ;
break;
case V_194 :
V_188 = 162000 ;
break;
case V_195 :
V_188 = 216000 ;
break;
case V_196 :
V_188 = 270000 ;
break;
case V_197 :
V_188 = 324000 ;
break;
case V_198 :
V_188 = 405000 ;
break;
default:
F_23 ( 1 , L_7 ) ;
break;
}
V_188 *= 2 ;
}
V_176 -> V_179 = V_188 ;
F_76 ( V_176 ) ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_75 * V_176 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
int V_188 = 0 ;
T_3 V_199 , V_133 ;
V_133 = F_80 ( V_16 , V_176 -> V_89 ) ;
V_199 = F_38 ( V_200 ) ;
if ( V_199 & F_82 ( V_133 ) ) {
V_188 = F_68 ( V_16 , V_133 ) ;
} else {
V_188 = V_199 & F_83 ( V_133 ) ;
V_188 >>= F_84 ( V_133 ) ;
switch ( V_188 ) {
case V_201 :
V_188 = 81000 ;
break;
case V_202 :
V_188 = 108000 ;
break;
case V_203 :
V_188 = 135000 ;
break;
case V_204 :
V_188 = 162000 ;
break;
case V_205 :
V_188 = 216000 ;
break;
case V_206 :
V_188 = 270000 ;
break;
default:
F_23 ( 1 , L_7 ) ;
break;
}
V_188 *= 2 ;
}
V_176 -> V_179 = V_188 ;
F_76 ( V_176 ) ;
}
static void F_85 ( struct V_2 * V_3 ,
struct V_75 * V_176 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
int V_188 = 0 ;
T_1 V_207 , V_58 ;
V_207 = F_41 ( V_176 -> V_89 ) ;
switch ( V_207 & V_208 ) {
case V_67 :
V_188 = 81000 ;
break;
case V_69 :
V_188 = 135000 ;
break;
case V_71 :
V_188 = 270000 ;
break;
case V_61 :
V_188 = F_67 ( V_16 , F_86 ( 0 ) ) ;
break;
case V_63 :
V_188 = F_67 ( V_16 , F_86 ( 1 ) ) ;
break;
case V_65 :
V_58 = F_38 ( V_209 ) & V_210 ;
if ( V_58 == V_211 )
V_188 = 81000 ;
else if ( V_58 == V_212 )
V_188 = 135000 ;
else if ( V_58 == V_213 )
V_188 = 270000 ;
else {
F_23 ( 1 , L_8 ) ;
return;
}
break;
default:
F_23 ( 1 , L_9 ) ;
return;
}
V_176 -> V_179 = V_188 * 2 ;
F_76 ( V_176 ) ;
}
static int F_87 ( struct V_15 * V_16 ,
enum V_214 V_133 )
{
struct V_57 * V_58 ;
struct V_215 * V_112 ;
struct V_133 clock ;
if ( F_30 ( V_133 == V_216 ) )
return 0 ;
V_58 = & V_16 -> V_217 [ V_133 ] ;
V_112 = & V_58 -> V_112 . V_218 ;
clock . V_219 = 2 ;
clock . V_220 = ( V_112 -> V_221 & V_222 ) << 22 ;
if ( V_112 -> V_223 & V_224 )
clock . V_220 |= V_112 -> V_225 & V_226 ;
clock . V_120 = ( V_112 -> V_227 & V_228 ) >> V_229 ;
clock . V_139 = ( V_112 -> V_230 & V_231 ) >> V_232 ;
clock . V_140 = ( V_112 -> V_230 & V_233 ) >> V_234 ;
return F_88 ( 100000 , & clock ) ;
}
static void F_89 ( struct V_2 * V_3 ,
struct V_75 * V_176 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_3 V_133 = V_1 ;
V_176 -> V_179 = F_87 ( V_16 , V_133 ) ;
F_76 ( V_176 ) ;
}
void F_90 ( struct V_2 * V_3 ,
struct V_75 * V_176 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
if ( F_91 ( V_16 ) <= 8 )
F_85 ( V_3 , V_176 ) ;
else if ( F_20 ( V_16 ) )
F_81 ( V_3 , V_176 ) ;
else if ( F_19 ( V_16 ) )
F_89 ( V_3 , V_176 ) ;
else if ( F_92 ( V_16 ) )
F_79 ( V_3 , V_176 ) ;
}
void F_93 ( const struct V_75 * V_76 )
{
struct V_73 * V_74 = F_64 ( V_76 -> V_5 . V_74 ) ;
struct V_15 * V_16 = F_29 ( V_74 -> V_5 . V_45 ) ;
struct V_2 * V_3 = F_60 ( V_74 ) ;
enum V_235 V_236 = V_76 -> V_236 ;
int type = V_3 -> type ;
T_3 V_78 ;
if ( type == V_7 || type == V_8 || type == V_4 ) {
F_30 ( F_94 ( V_236 ) ) ;
V_78 = V_237 ;
switch ( V_76 -> V_183 ) {
case 18 :
V_78 |= V_238 ;
break;
case 24 :
V_78 |= V_239 ;
break;
case 30 :
V_78 |= V_240 ;
break;
case 36 :
V_78 |= V_241 ;
break;
default:
F_95 () ;
}
F_31 ( F_96 ( V_236 ) , V_78 ) ;
}
}
void F_97 ( const struct V_75 * V_76 ,
bool V_112 )
{
struct V_73 * V_74 = F_64 ( V_76 -> V_5 . V_74 ) ;
struct V_15 * V_16 = F_29 ( V_74 -> V_5 . V_45 ) ;
enum V_235 V_236 = V_76 -> V_236 ;
T_3 V_78 ;
V_78 = F_38 ( F_98 ( V_236 ) ) ;
if ( V_112 == true )
V_78 |= V_242 ;
else
V_78 &= ~ V_242 ;
F_31 ( F_98 ( V_236 ) , V_78 ) ;
}
void F_99 ( const struct V_75 * V_76 )
{
struct V_73 * V_74 = F_64 ( V_76 -> V_5 . V_74 ) ;
struct V_2 * V_3 = F_60 ( V_74 ) ;
struct V_15 * V_16 = F_29 ( V_74 -> V_5 . V_45 ) ;
enum V_110 V_110 = V_74 -> V_110 ;
enum V_235 V_236 = V_76 -> V_236 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int type = V_3 -> type ;
T_3 V_78 ;
V_78 = V_243 ;
V_78 |= F_100 ( V_1 ) ;
switch ( V_76 -> V_183 ) {
case 18 :
V_78 |= V_244 ;
break;
case 24 :
V_78 |= V_245 ;
break;
case 30 :
V_78 |= V_246 ;
break;
case 36 :
V_78 |= V_247 ;
break;
default:
F_95 () ;
}
if ( V_76 -> V_5 . V_186 . V_248 & V_249 )
V_78 |= V_250 ;
if ( V_76 -> V_5 . V_186 . V_248 & V_251 )
V_78 |= V_252 ;
if ( V_236 == V_253 ) {
switch ( V_110 ) {
case V_81 :
if ( F_22 ( V_16 ) &&
( V_76 -> V_254 . V_255 ||
V_76 -> V_254 . V_256 ) )
V_78 |= V_257 ;
else
V_78 |= V_258 ;
break;
case V_259 :
V_78 |= V_260 ;
break;
case V_261 :
V_78 |= V_262 ;
break;
default:
F_95 () ;
break;
}
}
if ( type == V_9 ) {
if ( V_76 -> V_182 )
V_78 |= V_263 ;
else
V_78 |= V_264 ;
if ( V_76 -> V_265 )
V_78 |= V_266 ;
if ( V_76 -> V_267 )
V_78 |= V_268 ;
} else if ( type == V_11 ) {
V_78 |= V_269 ;
V_78 |= ( V_76 -> V_87 - 1 ) << 1 ;
} else if ( type == V_7 ||
type == V_8 ) {
V_78 |= V_270 ;
V_78 |= F_59 ( V_76 -> V_107 ) ;
} else if ( type == V_4 ) {
V_78 |= V_271 ;
V_78 |= F_59 ( V_76 -> V_107 ) ;
} else {
F_23 ( 1 , L_10 ,
V_3 -> type , F_61 ( V_110 ) ) ;
}
F_31 ( F_98 ( V_236 ) , V_78 ) ;
}
void F_101 ( struct V_15 * V_16 ,
enum V_235 V_236 )
{
T_2 V_55 = F_98 ( V_236 ) ;
T_3 V_207 = F_38 ( V_55 ) ;
V_207 &= ~ ( V_243 | V_272 | V_242 ) ;
V_207 |= V_273 ;
F_31 ( V_55 , V_207 ) ;
}
bool F_102 ( struct V_274 * V_274 )
{
struct V_77 * V_45 = V_274 -> V_5 . V_45 ;
struct V_15 * V_16 = F_29 ( V_45 ) ;
struct V_2 * V_3 = V_274 -> V_3 ;
int type = V_274 -> V_5 . V_275 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
enum V_110 V_110 = 0 ;
enum V_235 V_236 ;
T_3 V_276 ;
bool V_108 ;
if ( ! F_103 ( V_16 ,
V_3 -> V_277 ) )
return false ;
if ( ! V_3 -> V_278 ( V_3 , & V_110 ) ) {
V_108 = false ;
goto V_279;
}
if ( V_1 == V_13 )
V_236 = V_253 ;
else
V_236 = (enum V_235 ) V_110 ;
V_276 = F_38 ( F_98 ( V_236 ) ) ;
switch ( V_276 & V_280 ) {
case V_263 :
case V_264 :
V_108 = type == V_281 ;
break;
case V_270 :
V_108 = type == V_282 ||
type == V_283 ;
break;
case V_271 :
V_108 = false ;
break;
case V_269 :
V_108 = type == V_284 ;
break;
default:
V_108 = false ;
break;
}
V_279:
F_104 ( V_16 , V_3 -> V_277 ) ;
return V_108 ;
}
bool F_105 ( struct V_2 * V_3 ,
enum V_110 * V_110 )
{
struct V_77 * V_45 = V_3 -> V_5 . V_45 ;
struct V_15 * V_16 = F_29 ( V_45 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_1 V_276 ;
int V_47 ;
bool V_108 ;
if ( ! F_103 ( V_16 ,
V_3 -> V_277 ) )
return false ;
V_108 = false ;
V_276 = F_38 ( F_36 ( V_1 ) ) ;
if ( ! ( V_276 & V_94 ) )
goto V_279;
if ( V_1 == V_13 ) {
V_276 = F_38 ( F_98 ( V_253 ) ) ;
switch ( V_276 & V_285 ) {
case V_258 :
case V_257 :
* V_110 = V_81 ;
break;
case V_260 :
* V_110 = V_259 ;
break;
case V_262 :
* V_110 = V_261 ;
break;
}
V_108 = true ;
goto V_279;
}
for ( V_47 = V_286 ; V_47 <= V_287 ; V_47 ++ ) {
V_276 = F_38 ( F_98 ( V_47 ) ) ;
if ( ( V_276 & V_272 ) == F_100 ( V_1 ) ) {
if ( ( V_276 & V_280 ) ==
V_271 )
goto V_279;
* V_110 = V_47 ;
V_108 = true ;
goto V_279;
}
}
F_56 ( L_11 , F_40 ( V_1 ) ) ;
V_279:
if ( V_108 && F_19 ( V_16 ) ) {
V_276 = F_38 ( F_106 ( V_1 ) ) ;
if ( ( V_276 & ( V_288 |
V_289 |
V_290 ) ) != V_290 )
F_39 ( L_12
L_13 , F_40 ( V_1 ) , V_276 ) ;
}
F_104 ( V_16 , V_3 -> V_277 ) ;
return V_108 ;
}
static T_4 F_107 ( struct V_2 * V_3 )
{
struct V_103 * V_291 = F_3 ( & V_3 -> V_5 ) ;
enum V_110 V_110 ;
if ( F_105 ( V_3 , & V_110 ) )
return F_108 ( V_291 -> V_292 ) ;
return 0 ;
}
void F_109 ( const struct V_75 * V_76 )
{
struct V_73 * V_74 = F_64 ( V_76 -> V_5 . V_74 ) ;
struct V_15 * V_16 = F_29 ( V_74 -> V_5 . V_45 ) ;
struct V_2 * V_3 = F_60 ( V_74 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
enum V_235 V_236 = V_76 -> V_236 ;
if ( V_236 != V_253 )
F_31 ( F_110 ( V_236 ) ,
F_111 ( V_1 ) ) ;
}
void F_112 ( const struct V_75 * V_76 )
{
struct V_15 * V_16 = F_29 ( V_76 -> V_5 . V_74 -> V_45 ) ;
enum V_235 V_236 = V_76 -> V_236 ;
if ( V_236 != V_253 )
F_31 ( F_110 ( V_236 ) ,
V_293 ) ;
}
static void F_113 ( struct V_15 * V_16 ,
enum V_1 V_1 , T_5 V_294 )
{
T_1 V_276 ;
V_276 = F_38 ( V_295 ) ;
V_276 &= ~ ( F_114 ( V_1 ) | F_115 ( V_1 ) ) ;
if ( V_294 )
V_276 |= V_294 << F_116 ( V_1 ) ;
else
V_276 |= F_115 ( V_1 ) ;
F_31 ( V_295 , V_276 ) ;
}
static void F_117 ( struct V_2 * V_3 , T_1 V_296 )
{
struct V_103 * V_104 = F_3 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_29 ( V_104 -> V_5 . V_5 . V_45 ) ;
enum V_1 V_1 = V_104 -> V_1 ;
int type = V_3 -> type ;
const struct V_14 * V_48 ;
T_5 V_294 ;
T_5 V_297 , V_298 ;
int V_17 ;
V_297 = V_16 -> V_18 . V_37 [ V_1 ] . V_49 ;
V_298 = V_16 -> V_18 . V_37 [ V_1 ] . V_54 ;
if ( type == V_7 ) {
if ( V_297 ) {
V_294 = V_297 ;
} else {
if ( F_15 ( V_16 ) || F_16 ( V_16 ) )
V_48 = F_10 ( V_16 ,
& V_17 ) ;
else
V_48 = F_7 ( V_16 ,
& V_17 ) ;
V_294 = V_48 [ V_296 ] . V_299 ;
}
} else if ( type == V_8 ) {
if ( V_297 ) {
V_294 = V_297 ;
} else {
V_48 = F_14 ( V_16 , & V_17 ) ;
if ( F_30 ( V_1 != V_13 &&
V_1 != V_12 && V_17 > 9 ) )
V_17 = 9 ;
V_294 = V_48 [ V_296 ] . V_299 ;
}
} else if ( type == V_9 ) {
if ( V_298 ) {
V_294 = V_298 ;
} else {
V_48 = F_17 ( V_16 , & V_17 ) ;
V_294 = V_48 [ V_296 ] . V_299 ;
}
} else {
return;
}
if ( V_294 && V_294 != 0x1 && V_294 != 0x3 && V_294 != 0x7 ) {
F_39 ( L_14 , V_294 ) ;
return;
}
F_113 ( V_16 , V_1 , V_294 ) ;
if ( V_1 == V_13 && V_104 -> V_300 == 4 )
F_113 ( V_16 , V_12 , V_294 ) ;
}
static void F_118 ( struct V_15 * V_16 ,
T_1 V_296 , enum V_1 V_1 , int type )
{
const struct V_301 * V_48 ;
T_1 V_17 , V_47 ;
if ( type == V_8 && V_16 -> V_18 . V_19 . V_20 ) {
V_17 = F_6 ( V_302 ) ;
V_48 = V_302 ;
} else if ( type == V_7
|| type == V_8 ) {
V_17 = F_6 ( V_303 ) ;
V_48 = V_303 ;
} else if ( type == V_9 ) {
V_17 = F_6 ( V_304 ) ;
V_48 = V_304 ;
} else {
F_56 ( L_15 ,
type ) ;
return;
}
if ( V_296 >= V_17 ||
( type == V_9 && V_296 == V_41 ) ) {
for ( V_47 = 0 ; V_47 < V_17 ; V_47 ++ ) {
if ( V_48 [ V_47 ] . V_305 ) {
V_296 = V_47 ;
break;
}
}
}
F_119 ( V_16 , V_1 ,
V_48 [ V_296 ] . V_306 ,
V_48 [ V_296 ] . V_307 ,
V_48 [ V_296 ] . V_308 ,
V_48 [ V_296 ] . V_309 ) ;
}
T_6 F_120 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
int V_17 ;
if ( V_3 -> type == V_8 )
F_26 ( V_16 , & V_17 ) ;
else
F_24 ( V_16 , & V_17 ) ;
if ( F_30 ( V_17 < 1 ) )
V_17 = 1 ;
if ( F_30 ( V_17 > F_6 ( V_310 ) ) )
V_17 = F_6 ( V_310 ) ;
return V_310 [ V_17 - 1 ] &
V_311 ;
}
static const struct V_312 *
F_121 ( struct V_15 * V_16 ,
T_1 V_313 , int * V_17 )
{
if ( V_313 == V_314 ) {
* V_17 = F_6 ( V_315 ) ;
return V_315 ;
} else if ( V_313 == V_316 ) {
* V_17 = F_6 ( V_317 ) ;
return V_317 ;
} else if ( V_313 == V_318 ) {
* V_17 = F_6 ( V_319 ) ;
return V_319 ;
}
return NULL ;
}
static const struct V_312 *
F_122 ( struct V_15 * V_16 ,
T_1 V_313 , int * V_17 )
{
if ( V_313 == V_314 ) {
* V_17 = F_6 ( V_320 ) ;
return V_320 ;
} else if ( V_313 == V_316 ) {
* V_17 = F_6 ( V_321 ) ;
return V_321 ;
} else if ( V_313 == V_318 ) {
* V_17 = F_6 ( V_322 ) ;
return V_322 ;
}
return NULL ;
}
static const struct V_312 *
F_123 ( struct V_15 * V_16 ,
T_1 V_313 , int * V_17 )
{
if ( V_16 -> V_18 . V_19 . V_20 ) {
if ( V_313 == V_314 ) {
* V_17 = F_6 ( V_323 ) ;
return V_323 ;
} else if ( V_313 == V_316 ) {
* V_17 = F_6 ( V_324 ) ;
return V_324 ;
} else if ( V_313 == V_318 ) {
* V_17 = F_6 ( V_325 ) ;
return V_325 ;
}
return NULL ;
} else {
return F_122 ( V_16 , V_313 , V_17 ) ;
}
}
static void F_124 ( struct V_15 * V_16 ,
T_1 V_296 , enum V_1 V_1 , int type )
{
const struct V_312 * V_48 = NULL ;
T_1 V_17 , V_207 , V_313 ;
int V_326 ;
V_313 = F_38 ( V_327 ) & V_328 ;
if ( type == V_9 ) {
V_48 = F_121 ( V_16 ,
V_313 , & V_17 ) ;
} else if ( type == V_7 ) {
V_48 = F_122 ( V_16 ,
V_313 , & V_17 ) ;
} else if ( type == V_8 ) {
V_48 = F_123 ( V_16 ,
V_313 , & V_17 ) ;
}
if ( V_48 == NULL ) {
F_4 ( V_313 ) ;
return;
}
if ( V_296 >= V_17 ) {
F_56 ( L_16 , V_296 , V_17 - 1 ) ;
V_296 = V_17 - 1 ;
}
V_207 = F_38 ( F_125 ( V_1 ) ) ;
V_207 &= ~ V_329 ;
V_207 |= F_126 ( 2 ) ;
F_31 ( F_127 ( V_1 ) , V_207 ) ;
V_207 = F_38 ( F_128 ( V_1 ) ) ;
V_207 &= ~ ( V_330 | V_331 |
V_332 ) ;
V_207 |= F_129 ( V_48 [ V_296 ] . V_333 ) ;
V_207 |= F_130 ( V_48 [ V_296 ] . V_333 ) ;
V_207 |= F_131 ( 0x98 ) ;
F_31 ( F_132 ( V_1 ) , V_207 ) ;
for ( V_326 = 0 ; V_326 < 4 ; V_326 ++ ) {
V_207 = F_38 ( F_133 ( V_1 , V_326 ) ) ;
V_207 &= ~ ( V_334 | V_335 |
V_336 ) ;
V_207 |= F_134 ( V_48 [ V_296 ] . V_337 ) ;
V_207 |= F_135 ( V_48 [ V_296 ] . V_338 ) ;
V_207 |= F_136 ( V_48 [ V_296 ] . V_339 ) ;
F_31 ( F_133 ( V_1 , V_326 ) , V_207 ) ;
}
V_207 = F_38 ( F_125 ( V_1 ) ) ;
V_207 &= ~ V_340 ;
V_207 |= F_137 ( 6 ) ;
V_207 |= V_341 ;
F_31 ( F_127 ( V_1 ) , V_207 ) ;
V_207 = F_38 ( F_138 ( V_1 ) ) ;
V_207 &= ~ V_342 ;
V_207 |= F_139 ( V_48 [ V_296 ] . V_343 ) ;
F_31 ( F_140 ( V_1 ) , V_207 ) ;
}
static void F_141 ( struct V_2 * V_3 , T_1 V_296 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
struct V_102 * V_102 = F_58 ( & V_3 -> V_5 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int type = V_3 -> type ;
int V_344 = 0 ;
int V_345 = 0 ;
T_1 V_207 ;
int V_326 = 0 ;
if ( ( V_102 ) && ( type == V_8 || type == V_7 ) ) {
V_344 = V_102 -> V_107 ;
V_345 = V_102 -> V_346 ;
} else if ( type == V_9 ) {
V_344 = 4 ;
} else {
F_4 ( type ) ;
return;
}
V_207 = F_38 ( F_142 ( V_1 ) ) ;
if ( type == V_8 || type == V_7 )
V_207 |= V_347 ;
else
V_207 &= ~ V_347 ;
F_31 ( F_143 ( V_1 ) , V_207 ) ;
for ( V_326 = 0 ; V_326 <= 3 ; V_326 ++ ) {
V_207 = F_38 ( F_133 ( V_1 , V_326 ) ) ;
V_207 &= ~ V_348 ;
if ( ( V_345 <= 600000 && V_344 == 4 && V_326 >= 1 ) ||
( V_345 <= 600000 && V_344 < 4 && ( V_326 == 1 || V_326 == 2 ) ) ) {
V_207 |= V_348 ;
}
F_31 ( F_133 ( V_1 , V_326 ) , V_207 ) ;
}
V_207 = F_38 ( V_349 ) ;
V_207 |= V_350 ;
F_31 ( V_349 , V_207 ) ;
V_207 = F_38 ( F_125 ( V_1 ) ) ;
V_207 &= ~ V_351 ;
F_31 ( F_127 ( V_1 ) , V_207 ) ;
F_124 ( V_16 , V_296 , V_1 , type ) ;
V_207 = F_38 ( F_125 ( V_1 ) ) ;
V_207 |= V_351 ;
F_31 ( F_127 ( V_1 ) , V_207 ) ;
}
static T_3 F_144 ( int V_352 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < F_6 ( V_310 ) ; V_47 ++ ) {
if ( V_310 [ V_47 ] == V_352 )
return V_47 ;
}
F_23 ( 1 , L_17 ,
V_352 ) ;
return 0 ;
}
T_3 F_145 ( struct V_102 * V_102 )
{
struct V_103 * V_353 = F_146 ( V_102 ) ;
struct V_15 * V_16 = F_29 ( V_353 -> V_5 . V_5 . V_45 ) ;
struct V_2 * V_3 = & V_353 -> V_5 ;
T_5 V_354 = V_102 -> V_354 [ 0 ] ;
int V_352 = V_354 & ( V_311 |
V_355 ) ;
enum V_1 V_1 = V_353 -> V_1 ;
T_3 V_296 ;
V_296 = F_144 ( V_352 ) ;
if ( F_20 ( V_16 ) )
F_117 ( V_3 , V_296 ) ;
else if ( F_19 ( V_16 ) )
F_118 ( V_16 , V_296 , V_1 , V_3 -> type ) ;
else if ( F_92 ( V_16 ) ) {
F_141 ( V_3 , V_296 ) ;
return 0 ;
}
return F_52 ( V_296 ) ;
}
static void F_147 ( struct V_2 * V_3 ,
struct V_57 * V_58 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_3 V_207 ;
if ( F_30 ( ! V_58 ) )
return;
if ( F_92 ( V_16 ) ) {
V_207 = F_38 ( V_356 ) ;
V_207 |= F_148 ( V_58 -> V_59 , V_1 ) ;
F_31 ( V_356 , V_207 ) ;
V_207 = F_38 ( V_356 ) ;
V_207 &= ~ F_149 ( V_1 ) ;
F_31 ( V_356 , V_207 ) ;
} else if ( F_20 ( V_16 ) ) {
V_207 = F_38 ( V_357 ) ;
V_207 &= ~ ( F_150 ( V_1 ) |
F_151 ( V_1 ) ) ;
V_207 |= ( F_152 ( V_58 -> V_59 , V_1 ) |
F_153 ( V_1 ) ) ;
F_31 ( V_357 , V_207 ) ;
} else if ( F_154 ( V_16 ) -> V_358 < 9 ) {
F_31 ( F_50 ( V_1 ) , F_41 ( V_58 ) ) ;
}
}
static void F_155 ( struct V_2 * V_3 ,
int V_346 , T_3 V_107 ,
struct V_57 * V_58 ,
bool V_359 )
{
struct V_102 * V_102 = F_58 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
struct V_103 * V_291 = F_3 ( & V_3 -> V_5 ) ;
F_30 ( V_359 && ( V_1 == V_13 || V_1 == V_12 ) ) ;
F_156 ( V_102 , V_346 , V_107 ,
V_359 ) ;
if ( V_3 -> type == V_8 )
F_157 ( V_102 ) ;
F_147 ( V_3 , V_58 ) ;
F_158 ( V_16 , V_291 -> V_292 ) ;
F_28 ( V_3 ) ;
F_57 ( V_3 ) ;
F_159 ( V_102 , V_360 ) ;
F_160 ( V_102 ) ;
if ( V_1 != V_13 || F_91 ( V_16 ) >= 9 )
F_161 ( V_102 ) ;
}
static void F_162 ( struct V_2 * V_3 ,
bool V_182 ,
const struct V_75 * V_76 ,
const struct V_115 * V_361 ,
struct V_57 * V_58 )
{
struct V_362 * V_362 = F_163 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
struct V_363 * V_363 = & V_3 -> V_5 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int V_296 = F_18 ( V_16 , V_1 ) ;
struct V_103 * V_291 = F_3 ( & V_3 -> V_5 ) ;
F_164 ( V_362 , true ) ;
F_147 ( V_3 , V_58 ) ;
F_158 ( V_16 , V_291 -> V_292 ) ;
F_34 ( V_3 ) ;
if ( F_20 ( V_16 ) )
F_117 ( V_3 , V_296 ) ;
else if ( F_19 ( V_16 ) )
F_118 ( V_16 , V_296 , V_1 ,
V_9 ) ;
else if ( F_92 ( V_16 ) )
F_141 ( V_3 , V_296 ) ;
V_362 -> V_364 ( V_363 ,
V_182 ,
V_76 , V_361 ) ;
}
static void F_165 ( struct V_2 * V_3 ,
struct V_75 * V_176 ,
struct V_115 * V_361 )
{
int type = V_3 -> type ;
if ( type == V_7 || type == V_8 ) {
F_155 ( V_3 ,
V_176 -> V_179 ,
V_176 -> V_107 ,
V_176 -> V_89 ,
F_166 ( V_176 ,
V_4 ) ) ;
}
if ( type == V_9 ) {
F_162 ( V_3 ,
V_176 -> V_182 ,
V_176 , V_361 ,
V_176 -> V_89 ) ;
}
}
static void F_167 ( struct V_2 * V_2 ,
struct V_75 * V_365 ,
struct V_115 * V_366 )
{
struct V_363 * V_3 = & V_2 -> V_5 ;
struct V_15 * V_16 = F_29 ( V_3 -> V_45 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
struct V_103 * V_291 = F_3 ( V_3 ) ;
struct V_102 * V_102 = NULL ;
int type = V_2 -> type ;
T_3 V_207 ;
bool V_367 = false ;
if ( type == V_7 || type == V_8 ) {
V_102 = F_58 ( V_3 ) ;
F_159 ( V_102 , V_368 ) ;
}
V_207 = F_38 ( F_36 ( V_1 ) ) ;
if ( V_207 & V_94 ) {
V_207 &= ~ V_94 ;
F_31 ( F_36 ( V_1 ) , V_207 ) ;
V_367 = true ;
}
V_207 = F_38 ( F_51 ( V_1 ) ) ;
V_207 &= ~ ( V_93 | V_100 ) ;
V_207 |= V_92 ;
F_31 ( F_51 ( V_1 ) , V_207 ) ;
if ( V_367 )
F_35 ( V_16 , V_1 ) ;
if ( V_102 ) {
F_168 ( V_102 ) ;
F_169 ( V_102 ) ;
}
if ( V_291 )
F_104 ( V_16 , V_291 -> V_292 ) ;
if ( F_92 ( V_16 ) )
F_31 ( V_356 , F_38 ( V_356 ) |
F_149 ( V_1 ) ) ;
else if ( F_20 ( V_16 ) )
F_31 ( V_357 , ( F_38 ( V_357 ) |
F_150 ( V_1 ) ) ) ;
else if ( F_91 ( V_16 ) < 9 )
F_31 ( F_50 ( V_1 ) , V_72 ) ;
if ( type == V_9 ) {
struct V_362 * V_362 = F_163 ( V_3 ) ;
F_164 ( V_362 , false ) ;
}
}
void F_170 ( struct V_2 * V_3 ,
struct V_75 * V_365 ,
struct V_115 * V_366 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
T_3 V_207 ;
V_207 = F_38 ( F_48 ( V_81 ) ) ;
V_207 &= ~ V_95 ;
F_31 ( F_48 ( V_81 ) , V_207 ) ;
F_167 ( V_3 , V_365 , V_366 ) ;
V_207 = F_38 ( F_44 ( V_81 ) ) ;
V_207 &= ~ ( V_97 | V_98 ) ;
V_207 |= F_45 ( 2 ) | F_46 ( 2 ) ;
F_31 ( F_44 ( V_81 ) , V_207 ) ;
V_207 = F_38 ( F_48 ( V_81 ) ) ;
V_207 &= ~ V_88 ;
F_31 ( F_48 ( V_81 ) , V_207 ) ;
V_207 = F_38 ( F_48 ( V_81 ) ) ;
V_207 &= ~ V_86 ;
F_31 ( F_48 ( V_81 ) , V_207 ) ;
}
static void F_171 ( struct V_2 * V_2 ,
struct V_75 * V_176 ,
struct V_115 * V_361 )
{
struct V_363 * V_3 = & V_2 -> V_5 ;
struct V_15 * V_16 = F_29 ( V_3 -> V_45 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_9 ) {
struct V_103 * V_104 =
F_3 ( V_3 ) ;
bool V_369 = V_176 -> V_267 ;
bool V_370 = V_176 -> V_265 ;
F_172 ( V_2 ,
V_361 -> V_114 ,
V_369 , V_370 ) ;
F_31 ( F_36 ( V_1 ) ,
V_104 -> V_106 |
V_94 ) ;
} else if ( type == V_8 ) {
struct V_102 * V_102 = F_58 ( V_3 ) ;
if ( V_1 == V_13 && F_91 ( V_16 ) < 9 )
F_161 ( V_102 ) ;
F_173 ( V_176 , V_361 ) ;
F_174 ( V_102 ) ;
F_175 ( V_102 , V_176 ) ;
}
if ( V_176 -> V_371 )
F_176 ( V_2 , V_176 , V_361 ) ;
}
static void F_177 ( struct V_2 * V_2 ,
struct V_75 * V_365 ,
struct V_115 * V_366 )
{
struct V_363 * V_3 = & V_2 -> V_5 ;
int type = V_2 -> type ;
if ( V_365 -> V_371 )
F_178 ( V_2 ) ;
if ( type == V_9 ) {
F_172 ( V_2 ,
V_366 -> V_114 ,
false , false ) ;
}
if ( type == V_8 ) {
struct V_102 * V_102 = F_58 ( V_3 ) ;
F_179 ( V_102 , V_365 ) ;
F_180 ( V_102 ) ;
F_181 ( V_366 ) ;
}
}
static void F_182 ( struct V_2 * V_3 ,
struct V_75 * V_176 ,
struct V_115 * V_361 )
{
T_5 V_372 = V_176 -> V_373 ;
F_183 ( V_3 , V_372 ) ;
}
void F_184 ( struct V_102 * V_102 )
{
struct V_103 * V_104 = F_146 ( V_102 ) ;
struct V_15 * V_16 =
F_29 ( V_104 -> V_5 . V_5 . V_45 ) ;
enum V_1 V_1 = V_104 -> V_1 ;
T_3 V_207 ;
bool V_367 = false ;
if ( F_38 ( F_51 ( V_1 ) ) & V_93 ) {
V_207 = F_38 ( F_36 ( V_1 ) ) ;
if ( V_207 & V_94 ) {
V_207 &= ~ V_94 ;
F_31 ( F_36 ( V_1 ) , V_207 ) ;
V_367 = true ;
}
V_207 = F_38 ( F_51 ( V_1 ) ) ;
V_207 &= ~ ( V_93 | V_100 ) ;
V_207 |= V_92 ;
F_31 ( F_51 ( V_1 ) , V_207 ) ;
F_49 ( F_51 ( V_1 ) ) ;
if ( V_367 )
F_35 ( V_16 , V_1 ) ;
}
V_207 = V_93 |
V_92 | V_374 ;
if ( V_102 -> V_359 )
V_207 |= V_375 ;
else {
V_207 |= V_376 ;
if ( F_185 ( V_102 -> V_377 ) )
V_207 |= V_91 ;
}
F_31 ( F_51 ( V_1 ) , V_207 ) ;
F_49 ( F_51 ( V_1 ) ) ;
V_102 -> V_105 |= V_94 ;
F_31 ( F_36 ( V_1 ) , V_102 -> V_105 ) ;
F_49 ( F_36 ( V_1 ) ) ;
F_37 ( 600 ) ;
}
bool F_186 ( struct V_15 * V_16 ,
struct V_73 * V_73 )
{
T_1 V_78 ;
if ( F_187 ( V_16 , V_378 ) ) {
V_78 = F_38 ( V_379 ) ;
if ( V_78 & F_188 ( V_73 -> V_110 ) )
return true ;
}
return false ;
}
void F_189 ( struct V_2 * V_3 ,
struct V_75 * V_176 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
struct V_73 * V_73 = F_64 ( V_3 -> V_5 . V_74 ) ;
enum V_235 V_236 = V_176 -> V_236 ;
struct V_362 * V_362 ;
T_1 V_78 , V_248 = 0 ;
if ( F_30 ( F_94 ( V_236 ) ) )
return;
V_78 = F_38 ( F_98 ( V_236 ) ) ;
if ( V_78 & V_252 )
V_248 |= V_251 ;
else
V_248 |= V_380 ;
if ( V_78 & V_250 )
V_248 |= V_249 ;
else
V_248 |= V_381 ;
V_176 -> V_5 . V_186 . V_248 |= V_248 ;
switch ( V_78 & V_382 ) {
case V_244 :
V_176 -> V_183 = 18 ;
break;
case V_245 :
V_176 -> V_183 = 24 ;
break;
case V_246 :
V_176 -> V_183 = 30 ;
break;
case V_247 :
V_176 -> V_183 = 36 ;
break;
default:
break;
}
switch ( V_78 & V_280 ) {
case V_263 :
V_176 -> V_182 = true ;
V_362 = F_163 ( & V_3 -> V_5 ) ;
if ( V_362 -> V_383 ( & V_3 -> V_5 , V_176 ) )
V_176 -> V_384 = true ;
if ( ( V_78 & V_266 ) ==
V_266 )
V_176 -> V_265 = true ;
if ( V_78 & V_268 )
V_176 -> V_267 = true ;
case V_264 :
V_176 -> V_107 = 4 ;
break;
case V_269 :
break;
case V_270 :
case V_271 :
V_176 -> V_107 =
( ( V_78 & V_385 ) >> V_386 ) + 1 ;
F_190 ( V_73 , V_176 ) ;
break;
default:
break;
}
V_176 -> V_371 =
F_186 ( V_16 , V_73 ) ;
if ( V_3 -> type == V_8 && V_16 -> V_18 . V_19 . V_387 &&
V_176 -> V_183 > V_16 -> V_18 . V_19 . V_387 ) {
F_56 ( L_18 ,
V_176 -> V_183 , V_16 -> V_18 . V_19 . V_387 ) ;
V_16 -> V_18 . V_19 . V_387 = V_176 -> V_183 ;
}
F_90 ( V_3 , V_176 ) ;
if ( F_19 ( V_16 ) )
V_176 -> V_373 =
F_191 ( V_3 ) ;
}
static bool F_192 ( struct V_2 * V_3 ,
struct V_75 * V_176 ,
struct V_115 * V_361 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_45 ) ;
int type = V_3 -> type ;
int V_1 = F_1 ( V_3 ) ;
int V_108 ;
F_23 ( type == V_10 , L_19 ) ;
if ( V_1 == V_13 )
V_176 -> V_236 = V_253 ;
if ( type == V_9 )
V_108 = F_193 ( V_3 , V_176 , V_361 ) ;
else
V_108 = F_194 ( V_3 , V_176 , V_361 ) ;
if ( F_19 ( V_16 ) && V_108 )
V_176 -> V_373 =
F_195 ( V_3 ,
V_176 -> V_107 ) ;
return V_108 ;
}
static struct V_274 *
F_196 ( struct V_103 * V_104 )
{
struct V_274 * V_114 ;
enum V_1 V_1 = V_104 -> V_1 ;
V_114 = F_197 () ;
if ( ! V_114 )
return NULL ;
V_104 -> V_388 . V_389 = F_36 ( V_1 ) ;
if ( ! F_198 ( V_104 , V_114 ) ) {
F_199 ( V_114 ) ;
return NULL ;
}
return V_114 ;
}
static struct V_274 *
F_200 ( struct V_103 * V_104 )
{
struct V_274 * V_114 ;
enum V_1 V_1 = V_104 -> V_1 ;
V_114 = F_197 () ;
if ( ! V_114 )
return NULL ;
V_104 -> V_390 . V_391 = F_36 ( V_1 ) ;
F_201 ( V_104 , V_114 ) ;
return V_114 ;
}
void F_202 ( struct V_15 * V_16 , enum V_1 V_1 )
{
struct V_103 * V_104 ;
struct V_2 * V_2 ;
struct V_363 * V_3 ;
bool V_392 , V_393 , V_394 = false ;
int V_300 ;
if ( F_38 ( F_36 ( V_13 ) ) & V_395 ) {
switch ( V_1 ) {
case V_13 :
V_300 = 4 ;
break;
case V_12 :
V_300 = 0 ;
break;
default:
V_300 = 4 ;
break;
}
} else {
switch ( V_1 ) {
case V_13 :
V_300 = 2 ;
break;
case V_12 :
V_300 = 2 ;
break;
default:
V_300 = 4 ;
break;
}
}
V_392 = ( V_16 -> V_18 . V_37 [ V_1 ] . V_396 ||
V_16 -> V_18 . V_37 [ V_1 ] . V_397 ) ;
V_393 = V_16 -> V_18 . V_37 [ V_1 ] . V_398 ;
if ( F_203 ( V_16 , V_1 ) ) {
V_393 = true ;
V_394 = true ;
V_392 = false ;
F_56 ( L_20 , F_40 ( V_1 ) ) ;
}
if ( ! V_393 && ! V_392 ) {
F_56 ( L_21 ,
F_40 ( V_1 ) ) ;
return;
}
V_104 = F_204 ( sizeof( * V_104 ) , V_399 ) ;
if ( ! V_104 )
return;
V_2 = & V_104 -> V_5 ;
V_3 = & V_2 -> V_5 ;
F_205 ( & V_16 -> V_400 , V_3 , & V_401 ,
V_402 , L_22 , F_40 ( V_1 ) ) ;
V_2 -> V_403 = F_192 ;
V_2 -> V_308 = F_171 ;
if ( F_19 ( V_16 ) )
V_2 -> V_404 = F_182 ;
V_2 -> V_405 = F_165 ;
V_2 -> V_406 = F_177 ;
V_2 -> V_407 = F_167 ;
V_2 -> V_278 = F_105 ;
V_2 -> V_408 = F_189 ;
V_2 -> V_409 = V_410 ;
V_2 -> V_411 = F_107 ;
V_104 -> V_1 = V_1 ;
V_104 -> V_106 = F_38 ( F_36 ( V_1 ) ) &
( V_412 |
V_395 ) ;
switch ( V_1 ) {
case V_13 :
V_104 -> V_292 =
V_413 ;
break;
case V_414 :
V_104 -> V_292 =
V_415 ;
break;
case V_416 :
V_104 -> V_292 =
V_417 ;
break;
case V_418 :
V_104 -> V_292 =
V_419 ;
break;
case V_12 :
V_104 -> V_292 =
V_420 ;
break;
default:
F_4 ( V_1 ) ;
}
if ( F_19 ( V_16 ) && V_1 == V_13 ) {
if ( ! ( V_104 -> V_106 & V_395 ) ) {
F_56 ( L_23 ) ;
V_104 -> V_106 |= V_395 ;
V_300 = 4 ;
}
}
V_104 -> V_300 = V_300 ;
V_2 -> type = V_10 ;
V_2 -> V_277 = F_206 ( V_1 ) ;
V_2 -> V_1 = V_1 ;
V_2 -> V_421 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_422 = 0 ;
if ( V_393 ) {
if ( ! F_196 ( V_104 ) )
goto V_423;
V_104 -> V_424 = V_425 ;
V_16 -> V_426 . V_427 [ V_1 ] = V_104 ;
}
if ( V_2 -> type != V_8 && V_392 ) {
if ( ! F_200 ( V_104 ) )
goto V_423;
}
if ( V_394 ) {
if ( F_207 ( V_104 ) )
F_56 ( L_24 ,
F_40 ( V_1 ) ) ;
else
F_39 ( L_25 ,
F_40 ( V_1 ) ) ;
}
return;
V_423:
F_208 ( V_3 ) ;
F_199 ( V_104 ) ;
}
