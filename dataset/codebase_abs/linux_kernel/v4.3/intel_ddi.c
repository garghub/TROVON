static void F_1 ( struct V_1 * V_1 ,
struct V_2 * * V_3 ,
enum V_4 * V_4 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
int type = V_1 -> type ;
if ( type == V_8 ) {
* V_3 = F_2 ( V_6 ) -> V_9 ;
* V_4 = ( * V_3 ) -> V_4 ;
} else if ( type == V_10 || type == V_11 ||
type == V_12 || type == V_13 ) {
* V_3 = F_3 ( V_6 ) ;
* V_4 = ( * V_3 ) -> V_4 ;
} else if ( type == V_14 ) {
* V_3 = NULL ;
* V_4 = V_15 ;
} else {
F_4 ( L_1 , type ) ;
F_5 () ;
}
}
enum V_4 F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
enum V_4 V_4 ;
F_1 ( V_1 , & V_3 , & V_4 ) ;
return V_4 ;
}
static bool
F_7 ( const struct V_2 * V_16 )
{
return V_16 -> V_17 . V_18 ;
}
static const struct V_19 * F_8 ( struct V_20 * V_21 ,
int * V_22 )
{
const struct V_19 * V_23 ;
if ( F_9 ( V_21 ) ) {
V_23 = V_24 ;
* V_22 = F_10 ( V_24 ) ;
} else if ( F_11 ( V_21 ) ) {
V_23 = V_25 ;
* V_22 = F_10 ( V_25 ) ;
} else {
V_23 = V_26 ;
* V_22 = F_10 ( V_26 ) ;
}
return V_23 ;
}
static const struct V_19 * F_12 ( struct V_20 * V_21 ,
int * V_22 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
const struct V_19 * V_23 ;
if ( F_9 ( V_21 ) ) {
if ( V_28 -> V_30 ) {
V_23 = V_31 ;
* V_22 = F_10 ( V_31 ) ;
} else {
V_23 = V_24 ;
* V_22 = F_10 ( V_24 ) ;
}
} else if ( F_11 ( V_21 ) ) {
if ( V_28 -> V_30 ) {
V_23 = V_32 ;
* V_22 = F_10 ( V_32 ) ;
} else {
V_23 = V_25 ;
* V_22 = F_10 ( V_25 ) ;
}
} else {
if ( V_28 -> V_30 ) {
V_23 = V_33 ;
* V_22 = F_10 ( V_33 ) ;
} else {
V_23 = V_26 ;
* V_22 = F_10 ( V_26 ) ;
}
}
return V_23 ;
}
static const struct V_19 *
F_13 ( struct V_20 * V_21 ,
int * V_22 )
{
const struct V_19 * V_23 ;
if ( F_9 ( V_21 ) ) {
V_23 = V_34 ;
* V_22 = F_10 ( V_34 ) ;
} else {
V_23 = V_35 ;
* V_22 = F_10 ( V_35 ) ;
}
return V_23 ;
}
static void F_14 ( struct V_20 * V_21 , enum V_4 V_4 ,
bool V_36 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
T_1 V_37 ;
T_1 V_38 = 0 ;
int V_39 , V_40 , V_41 , V_42 , V_43 ,
V_44 ;
int V_45 = V_28 -> V_46 . V_47 [ V_4 ] . V_48 ;
const struct V_19 * V_49 ;
const struct V_19 * V_50 ;
const struct V_19 * V_51 ;
const struct V_19 * V_52 ;
const struct V_19 * V_23 ;
if ( F_15 ( V_21 ) ) {
if ( ! V_36 )
return;
F_16 ( V_21 , V_45 , V_4 ,
V_12 ) ;
return;
} else if ( F_17 ( V_21 ) ) {
V_49 = NULL ;
V_50 =
F_8 ( V_21 , & V_41 ) ;
V_51 =
F_12 ( V_21 , & V_42 ) ;
V_52 =
F_13 ( V_21 , & V_40 ) ;
V_43 = 8 ;
if ( V_28 -> V_46 . V_47 [ V_4 ] . V_53 ||
V_28 -> V_46 . V_47 [ V_4 ] . V_54 )
V_38 = 1 << 31 ;
} else if ( F_18 ( V_21 ) ) {
V_49 = V_55 ;
V_50 = V_56 ;
V_51 = V_57 ;
V_52 = V_58 ;
V_42 = F_10 ( V_57 ) ;
V_41 = F_10 ( V_56 ) ;
V_40 = F_10 ( V_58 ) ;
V_43 = 7 ;
} else if ( F_19 ( V_21 ) ) {
V_49 = V_59 ;
V_50 = V_60 ;
V_51 = V_60 ;
V_52 = V_61 ;
V_41 = V_42 = F_10 ( V_60 ) ;
V_40 = F_10 ( V_61 ) ;
V_43 = 6 ;
} else {
F_20 ( 1 , L_2 ) ;
V_51 = V_56 ;
V_49 = V_55 ;
V_50 = V_56 ;
V_52 = V_58 ;
V_42 = F_10 ( V_57 ) ;
V_41 = F_10 ( V_56 ) ;
V_40 = F_10 ( V_58 ) ;
V_43 = 7 ;
}
switch ( V_4 ) {
case V_62 :
V_23 = V_51 ;
V_44 = V_42 ;
break;
case V_63 :
case V_64 :
V_23 = V_50 ;
V_44 = V_41 ;
break;
case V_65 :
if ( F_21 ( V_21 , V_65 ) ) {
V_23 = V_51 ;
V_44 = V_42 ;
} else {
V_23 = V_50 ;
V_44 = V_41 ;
}
break;
case V_15 :
if ( V_49 )
V_23 = V_49 ;
else
V_23 = V_50 ;
V_44 = V_41 ;
break;
default:
F_5 () ;
}
for ( V_39 = 0 , V_37 = F_22 ( V_4 ) ; V_39 < V_44 ; V_39 ++ ) {
F_23 ( V_37 , V_23 [ V_39 ] . V_66 | V_38 ) ;
V_37 += 4 ;
F_23 ( V_37 , V_23 [ V_39 ] . V_67 ) ;
V_37 += 4 ;
}
if ( ! V_36 )
return;
if ( V_45 == V_68 ||
V_45 >= V_40 )
V_45 = V_43 ;
F_23 ( V_37 , V_52 [ V_45 ] . V_66 | V_38 ) ;
V_37 += 4 ;
F_23 ( V_37 , V_52 [ V_45 ] . V_67 ) ;
V_37 += 4 ;
}
void F_24 ( struct V_20 * V_21 )
{
struct V_1 * V_1 ;
bool V_69 [ V_70 ] = { 0 , } ;
if ( ! F_25 ( V_21 ) )
return;
F_26 (dev, intel_encoder) {
struct V_2 * V_16 ;
enum V_4 V_4 ;
bool V_36 ;
F_1 ( V_1 , & V_16 , & V_4 ) ;
if ( V_69 [ V_4 ] )
continue;
V_36 = V_16 &&
F_7 ( V_16 ) ;
F_14 ( V_21 , V_4 , V_36 ) ;
V_69 [ V_4 ] = true ;
}
}
static void F_27 ( struct V_27 * V_28 ,
enum V_4 V_4 )
{
T_2 V_37 = F_28 ( V_4 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 16 ; V_39 ++ ) {
F_29 ( 1 ) ;
if ( F_30 ( V_37 ) & V_71 )
return;
}
F_4 ( L_3 , F_31 ( V_4 ) ) ;
}
void F_32 ( struct V_72 * V_73 )
{
struct V_20 * V_21 = V_73 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_74 * V_74 = F_33 ( V_73 ) ;
T_1 V_75 , V_39 , V_76 ;
F_23 ( V_77 , F_34 ( 2 ) |
F_35 ( 2 ) |
V_78 | V_79 ) ;
V_76 = V_28 -> V_80 | V_81 |
V_82 |
F_36 ( V_74 -> V_83 -> V_84 ) ;
F_23 ( V_85 , V_76 ) ;
F_37 ( V_85 ) ;
F_29 ( 220 ) ;
V_76 |= V_86 ;
F_23 ( V_85 , V_76 ) ;
F_23 ( F_38 ( V_15 ) , V_74 -> V_83 -> V_87 ) ;
F_39 ( V_74 -> V_83 -> V_87 != V_88 ) ;
for ( V_39 = 0 ; V_39 < F_10 ( V_59 ) * 2 ; V_39 ++ ) {
F_23 ( F_40 ( V_15 ) ,
V_89 |
V_90 |
V_91 |
V_92 ) ;
F_23 ( F_28 ( V_15 ) ,
V_93 |
( ( V_74 -> V_83 -> V_84 - 1 ) << 1 ) |
F_41 ( V_39 / 2 ) ) ;
F_37 ( F_28 ( V_15 ) ) ;
F_29 ( 600 ) ;
F_23 ( V_94 , F_42 ( 64 ) ) ;
V_76 |= V_95 | V_96 ;
F_23 ( V_85 , V_76 ) ;
F_37 ( V_85 ) ;
F_29 ( 30 ) ;
V_75 = F_30 ( V_77 ) ;
V_75 &= ~ ( V_97 | V_98 ) ;
F_23 ( V_77 , V_75 ) ;
F_37 ( V_77 ) ;
F_29 ( 5 ) ;
V_75 = F_30 ( F_43 ( V_15 ) ) ;
if ( V_75 & V_99 ) {
F_44 ( L_4 , V_39 ) ;
F_23 ( F_40 ( V_15 ) ,
V_89 |
V_100 |
V_90 |
V_92 ) ;
return;
}
V_75 = F_30 ( F_28 ( V_15 ) ) ;
V_75 &= ~ V_93 ;
F_23 ( F_28 ( V_15 ) , V_75 ) ;
F_37 ( F_28 ( V_15 ) ) ;
V_75 = F_30 ( F_40 ( V_15 ) ) ;
V_75 &= ~ ( V_92 | V_101 ) ;
V_75 |= V_91 ;
F_23 ( F_40 ( V_15 ) , V_75 ) ;
F_37 ( F_40 ( V_15 ) ) ;
F_27 ( V_28 , V_15 ) ;
V_76 &= ~ V_95 ;
F_23 ( V_85 , V_76 ) ;
F_37 ( V_85 ) ;
V_75 = F_30 ( V_77 ) ;
V_75 &= ~ ( V_97 | V_98 ) ;
V_75 |= F_34 ( 2 ) | F_35 ( 2 ) ;
F_23 ( V_77 , V_75 ) ;
F_37 ( V_77 ) ;
}
F_4 ( L_5 ) ;
}
void F_45 ( struct V_1 * V_6 )
{
struct V_102 * V_102 = F_46 ( & V_6 -> V_7 ) ;
struct V_2 * V_16 =
F_3 ( & V_6 -> V_7 ) ;
V_102 -> V_103 = V_16 -> V_104 |
V_93 | F_41 ( 0 ) ;
V_102 -> V_103 |= F_47 ( V_102 -> V_105 ) ;
}
static struct V_1 *
F_48 ( struct V_72 * V_73 )
{
struct V_20 * V_21 = V_73 -> V_21 ;
struct V_74 * V_74 = F_33 ( V_73 ) ;
struct V_1 * V_1 , * V_106 = NULL ;
int V_107 = 0 ;
F_49 (dev, crtc, intel_encoder) {
V_106 = V_1 ;
V_107 ++ ;
}
if ( V_107 != 1 )
F_20 ( 1 , L_6 , V_107 ,
F_50 ( V_74 -> V_108 ) ) ;
F_51 ( V_106 == NULL ) ;
return V_106 ;
}
struct V_1 *
F_52 ( struct V_109 * V_110 )
{
struct V_74 * V_73 = F_33 ( V_110 -> V_7 . V_73 ) ;
struct V_1 * V_106 = NULL ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
int V_107 = 0 ;
int V_39 ;
V_112 = V_110 -> V_7 . V_112 ;
F_53 (state, connector, connector_state, i) {
if ( V_116 -> V_73 != V_110 -> V_7 . V_73 )
continue;
V_106 = F_54 ( V_116 -> V_117 ) ;
V_107 ++ ;
}
F_20 ( V_107 != 1 , L_6 , V_107 ,
F_50 ( V_73 -> V_108 ) ) ;
F_51 ( V_106 == NULL ) ;
return V_106 ;
}
static unsigned F_55 ( int clock )
{
unsigned V_118 ;
switch ( clock ) {
case 25175000 :
case 25200000 :
case 27000000 :
case 27027000 :
case 37762500 :
case 37800000 :
case 40500000 :
case 40541000 :
case 54000000 :
case 54054000 :
case 59341000 :
case 59400000 :
case 72000000 :
case 74176000 :
case 74250000 :
case 81000000 :
case 81081000 :
case 89012000 :
case 89100000 :
case 108000000 :
case 108108000 :
case 111264000 :
case 111375000 :
case 148352000 :
case 148500000 :
case 162000000 :
case 162162000 :
case 222525000 :
case 222750000 :
case 296703000 :
case 297000000 :
V_118 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_118 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_118 = 2000 ;
break;
case 256250000 :
case 262500000 :
case 270000000 :
case 272500000 :
case 273750000 :
case 280750000 :
case 281250000 :
case 286000000 :
case 291750000 :
V_118 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_118 = 5000 ;
break;
default:
V_118 = 1000 ;
break;
}
return V_118 ;
}
static void F_56 ( T_3 V_119 , unsigned V_118 ,
unsigned V_120 , unsigned V_121 , unsigned V_122 ,
struct V_123 * V_124 )
{
T_3 V_125 , V_126 , V_127 , V_128 , V_129 , V_130 ;
if ( V_124 -> V_122 == 0 ) {
V_124 -> V_122 = V_122 ;
V_124 -> V_121 = V_121 ;
V_124 -> V_120 = V_120 ;
return;
}
V_125 = V_119 * V_118 * V_122 * V_120 ;
V_126 = V_119 * V_118 * V_124 -> V_122 * V_124 -> V_120 ;
V_129 = F_57 ( V_119 * V_122 * V_120 , V_131 * V_121 ) ;
V_130 = F_57 ( V_119 * V_124 -> V_122 * V_124 -> V_120 ,
V_131 * V_124 -> V_121 ) ;
V_127 = 1000000 * V_129 ;
V_128 = 1000000 * V_130 ;
if ( V_125 < V_127 && V_126 < V_128 ) {
if ( V_124 -> V_122 * V_124 -> V_120 * V_129 < V_122 * V_120 * V_130 ) {
V_124 -> V_122 = V_122 ;
V_124 -> V_121 = V_121 ;
V_124 -> V_120 = V_120 ;
}
} else if ( V_125 >= V_127 && V_126 < V_128 ) {
V_124 -> V_122 = V_122 ;
V_124 -> V_121 = V_121 ;
V_124 -> V_120 = V_120 ;
} else if ( V_125 >= V_127 && V_126 >= V_128 ) {
if ( V_121 * V_124 -> V_120 * V_124 -> V_120 > V_124 -> V_121 * V_120 * V_120 ) {
V_124 -> V_122 = V_122 ;
V_124 -> V_121 = V_121 ;
V_124 -> V_120 = V_120 ;
}
}
}
static int F_58 ( struct V_27 * V_28 , int V_37 )
{
int V_132 = V_133 ;
int V_134 , V_122 , V_135 ;
T_1 V_136 ;
V_136 = F_30 ( V_37 ) ;
switch ( V_136 & V_137 ) {
case V_138 :
case V_139 :
V_132 = 135 ;
break;
case V_140 :
V_132 = V_133 ;
break;
default:
F_20 ( 1 , L_7 ) ;
return 0 ;
}
V_135 = V_136 & V_141 ;
V_122 = ( V_136 & V_142 ) >> V_143 ;
V_134 = ( V_136 & V_144 ) >> V_145 ;
return ( V_132 * V_134 * 100 ) / ( V_122 * V_135 ) ;
}
static int F_59 ( struct V_27 * V_28 ,
T_2 V_146 )
{
T_2 V_147 , V_148 ;
T_2 V_149 , V_150 ;
T_2 V_151 , V_152 , V_153 , V_154 ;
V_147 = F_60 ( V_146 ) ;
V_148 = F_61 ( V_146 ) ;
V_149 = F_30 ( V_147 ) ;
V_150 = F_30 ( V_148 ) ;
V_151 = V_150 & V_155 ;
V_153 = V_150 & V_156 ;
if ( V_150 & F_62 ( 1 ) )
V_152 = ( V_150 & V_157 ) >> 8 ;
else
V_152 = 1 ;
switch ( V_151 ) {
case V_158 :
V_151 = 1 ;
break;
case V_159 :
V_151 = 2 ;
break;
case V_160 :
V_151 = 3 ;
break;
case V_161 :
V_151 = 7 ;
break;
}
switch ( V_153 ) {
case V_162 :
V_153 = 5 ;
break;
case V_163 :
V_153 = 2 ;
break;
case V_164 :
V_153 = 3 ;
break;
case V_165 :
V_153 = 1 ;
break;
}
V_154 = ( V_149 & V_166 ) * 24 * 1000 ;
V_154 += ( ( ( V_149 & V_167 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_154 / ( V_151 * V_152 * V_153 * 5 ) ;
}
static void F_63 ( struct V_109 * V_168 )
{
int V_169 ;
if ( V_168 -> V_170 )
V_169 = F_64 ( V_168 -> V_171 ,
& V_168 -> V_172 ) ;
else if ( V_168 -> V_173 )
V_169 = F_64 ( V_168 -> V_171 ,
& V_168 -> V_174 ) ;
else if ( V_168 -> V_175 && V_168 -> V_176 == 36 )
V_169 = V_168 -> V_171 * 2 / 3 ;
else
V_169 = V_168 -> V_171 ;
if ( V_168 -> V_177 )
V_169 /= V_168 -> V_177 ;
V_168 -> V_7 . V_178 . V_179 = V_169 ;
}
static void F_65 ( struct V_1 * V_6 ,
struct V_109 * V_168 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
int V_180 = 0 ;
T_2 V_181 , V_146 ;
V_146 = V_168 -> V_87 ;
V_181 = F_30 ( V_182 ) ;
if ( V_181 & F_66 ( V_146 ) ) {
V_180 = F_59 ( V_28 , V_146 ) ;
} else {
V_180 = V_181 & F_67 ( V_146 ) ;
V_180 >>= F_68 ( V_146 ) ;
switch ( V_180 ) {
case V_183 :
V_180 = 81000 ;
break;
case V_184 :
V_180 = 108000 ;
break;
case V_185 :
V_180 = 135000 ;
break;
case V_186 :
V_180 = 162000 ;
break;
case V_187 :
V_180 = 216000 ;
break;
case V_188 :
V_180 = 270000 ;
break;
default:
F_20 ( 1 , L_8 ) ;
break;
}
V_180 *= 2 ;
}
V_168 -> V_171 = V_180 ;
F_63 ( V_168 ) ;
}
static void F_69 ( struct V_1 * V_6 ,
struct V_109 * V_168 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
int V_180 = 0 ;
T_1 V_189 , V_190 ;
V_189 = V_168 -> V_87 ;
switch ( V_189 & V_191 ) {
case V_192 :
V_180 = 81000 ;
break;
case V_193 :
V_180 = 135000 ;
break;
case V_194 :
V_180 = 270000 ;
break;
case V_195 :
V_180 = F_58 ( V_28 , V_196 ) ;
break;
case V_197 :
V_180 = F_58 ( V_28 , V_198 ) ;
break;
case V_88 :
V_190 = F_30 ( V_199 ) & V_200 ;
if ( V_190 == V_201 )
V_180 = 81000 ;
else if ( V_190 == V_202 )
V_180 = 135000 ;
else if ( V_190 == V_203 )
V_180 = 270000 ;
else {
F_20 ( 1 , L_9 ) ;
return;
}
break;
default:
F_20 ( 1 , L_10 ) ;
return;
}
V_168 -> V_171 = V_180 * 2 ;
F_63 ( V_168 ) ;
}
static int F_70 ( struct V_27 * V_28 ,
enum V_204 V_146 )
{
struct V_205 * V_190 ;
struct V_206 * V_112 ;
T_4 clock ;
if ( F_39 ( V_146 == V_207 ) )
return 0 ;
V_190 = & V_28 -> V_208 [ V_146 ] ;
V_112 = & V_190 -> V_83 . V_209 ;
clock . V_210 = 2 ;
clock . V_211 = ( V_112 -> V_212 & V_213 ) << 22 ;
if ( V_112 -> V_214 & V_215 )
clock . V_211 |= V_112 -> V_216 & V_217 ;
clock . V_134 = ( V_112 -> V_218 & V_219 ) >> V_220 ;
clock . V_152 = ( V_112 -> V_221 & V_222 ) >> V_223 ;
clock . V_153 = ( V_112 -> V_221 & V_224 ) >> V_225 ;
return F_71 ( 100000 , & clock ) ;
}
static void F_72 ( struct V_1 * V_6 ,
struct V_109 * V_168 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
enum V_4 V_4 = F_6 ( V_6 ) ;
T_2 V_146 = V_4 ;
V_168 -> V_171 = F_70 ( V_28 , V_146 ) ;
F_63 ( V_168 ) ;
}
void F_73 ( struct V_1 * V_6 ,
struct V_109 * V_168 )
{
struct V_20 * V_21 = V_6 -> V_7 . V_21 ;
if ( F_74 ( V_21 ) -> V_226 <= 8 )
F_69 ( V_6 , V_168 ) ;
else if ( F_17 ( V_21 ) )
F_65 ( V_6 , V_168 ) ;
else if ( F_15 ( V_21 ) )
F_72 ( V_6 , V_168 ) ;
}
static void
F_75 ( int clock ,
unsigned * V_227 , unsigned * V_228 , unsigned * V_229 )
{
T_3 V_119 ;
unsigned V_122 , V_121 , V_120 ;
struct V_123 V_124 = { 0 , 0 , 0 } ;
unsigned V_118 ;
V_119 = clock / 100 ;
V_118 = F_55 ( clock ) ;
if ( V_119 == 5400000 ) {
* V_228 = 2 ;
* V_229 = 1 ;
* V_227 = 2 ;
return;
}
for ( V_120 = V_133 * 2 / V_230 + 1 ;
V_120 <= V_133 * 2 / V_231 ;
V_120 ++ ) {
for ( V_121 = V_232 * V_120 / V_133 + 1 ;
V_121 <= V_233 * V_120 / V_133 ;
V_121 ++ ) {
for ( V_122 = V_234 ; V_122 <= V_235 ; V_122 += V_236 )
F_56 ( V_119 , V_118 ,
V_120 , V_121 , V_122 , & V_124 ) ;
}
}
* V_228 = V_124 . V_121 ;
* V_229 = V_124 . V_122 ;
* V_227 = V_124 . V_120 ;
}
static bool
F_76 ( struct V_74 * V_74 ,
struct V_109 * V_110 ,
struct V_1 * V_1 ,
int clock )
{
if ( V_1 -> type == V_12 ) {
struct V_205 * V_190 ;
T_2 V_189 ;
unsigned V_122 , V_121 , V_120 ;
F_75 ( clock * 1000 , & V_120 , & V_121 , & V_122 ) ;
V_189 = V_237 | V_140 |
F_77 ( V_120 ) | F_78 ( V_121 ) |
F_79 ( V_122 ) ;
memset ( & V_110 -> V_238 , 0 ,
sizeof( V_110 -> V_238 ) ) ;
V_110 -> V_238 . V_136 = V_189 ;
V_190 = F_80 ( V_74 , V_110 ) ;
if ( V_190 == NULL ) {
F_81 ( L_11 ,
F_50 ( V_74 -> V_108 ) ) ;
return false ;
}
V_110 -> V_87 = F_82 ( V_190 -> V_239 ) ;
}
return true ;
}
static void F_83 ( struct V_240 * V_241 )
{
memset ( V_241 , 0 , sizeof( * V_241 ) ) ;
V_241 -> V_242 = V_243 ;
}
static void F_84 ( struct V_240 * V_241 ,
T_3 V_244 ,
T_3 V_154 ,
unsigned int V_245 )
{
T_3 V_246 ;
V_246 = F_85 ( 10000 * F_57 ( V_154 , V_244 ) ,
V_244 ) ;
if ( V_154 >= V_244 ) {
if ( V_246 < V_247 &&
V_246 < V_241 -> V_242 ) {
V_241 -> V_242 = V_246 ;
V_241 -> V_244 = V_244 ;
V_241 -> V_154 = V_154 ;
V_241 -> V_122 = V_245 ;
}
} else if ( V_246 < V_248 &&
V_246 < V_241 -> V_242 ) {
V_241 -> V_242 = V_246 ;
V_241 -> V_244 = V_244 ;
V_241 -> V_154 = V_154 ;
V_241 -> V_122 = V_245 ;
}
}
static void F_86 ( unsigned int V_122 ,
unsigned int * V_151 ,
unsigned int * V_152 ,
unsigned int * V_153 )
{
if ( V_122 % 2 == 0 ) {
unsigned int V_249 = V_122 / 2 ;
if ( V_249 == 1 || V_249 == 2 || V_249 == 3 || V_249 == 5 ) {
* V_151 = 2 ;
* V_152 = 1 ;
* V_153 = V_249 ;
} else if ( V_249 % 2 == 0 ) {
* V_151 = 2 ;
* V_152 = V_249 / 2 ;
* V_153 = 2 ;
} else if ( V_249 % 3 == 0 ) {
* V_151 = 3 ;
* V_152 = V_249 / 3 ;
* V_153 = 2 ;
} else if ( V_249 % 7 == 0 ) {
* V_151 = 7 ;
* V_152 = V_249 / 7 ;
* V_153 = 2 ;
}
} else if ( V_122 == 3 || V_122 == 9 ) {
* V_151 = 3 ;
* V_152 = 1 ;
* V_153 = V_122 / 3 ;
} else if ( V_122 == 5 || V_122 == 7 ) {
* V_151 = V_122 ;
* V_152 = 1 ;
* V_153 = 1 ;
} else if ( V_122 == 15 ) {
* V_151 = 3 ;
* V_152 = 1 ;
* V_153 = 5 ;
} else if ( V_122 == 21 ) {
* V_151 = 7 ;
* V_152 = 1 ;
* V_153 = 3 ;
} else if ( V_122 == 35 ) {
* V_151 = 7 ;
* V_152 = 1 ;
* V_153 = 5 ;
}
}
static void F_87 ( struct V_250 * V_251 ,
T_3 V_252 ,
T_3 V_244 ,
T_2 V_151 , T_2 V_152 , T_2 V_153 )
{
T_3 V_154 ;
switch ( V_244 ) {
case 9600000000ULL :
V_251 -> V_244 = 0 ;
break;
case 9000000000ULL :
V_251 -> V_244 = 1 ;
break;
case 8400000000ULL :
V_251 -> V_244 = 3 ;
}
switch ( V_151 ) {
case 1 :
V_251 -> V_253 = 0 ;
break;
case 2 :
V_251 -> V_253 = 1 ;
break;
case 3 :
V_251 -> V_253 = 2 ;
break;
case 7 :
V_251 -> V_253 = 4 ;
break;
default:
F_20 ( 1 , L_12 ) ;
}
switch ( V_153 ) {
case 5 :
V_251 -> V_254 = 0 ;
break;
case 2 :
V_251 -> V_254 = 1 ;
break;
case 3 :
V_251 -> V_254 = 2 ;
break;
case 1 :
V_251 -> V_254 = 3 ;
break;
default:
F_20 ( 1 , L_13 ) ;
}
V_251 -> V_255 = V_152 ;
V_251 -> V_256 = ( V_251 -> V_255 == 1 ) ? 0 : 1 ;
V_154 = V_151 * V_152 * V_153 * V_252 ;
V_251 -> V_257 = F_88 ( V_154 , 24 * F_89 ( 1 ) ) ;
V_251 -> V_258 =
F_88 ( ( F_88 ( V_154 , 24 ) -
V_251 -> V_257 * F_89 ( 1 ) ) * 0x8000 , F_89 ( 1 ) ) ;
}
static bool
F_90 ( int clock ,
struct V_250 * V_259 )
{
T_3 V_252 = clock * 5 ;
T_3 V_260 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
static const int V_261 [] = { 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 ,
24 , 28 , 30 , 32 , 36 , 40 , 42 , 44 ,
48 , 52 , 54 , 56 , 60 , 64 , 66 , 68 ,
70 , 72 , 76 , 78 , 80 , 84 , 88 , 90 ,
92 , 96 , 98 } ;
static const int V_262 [] = { 3 , 5 , 7 , 9 , 15 , 21 , 35 } ;
static const struct {
const int * V_263 ;
int V_264 ;
} V_265 [] = {
{ V_261 , F_10 (even_dividers) } ,
{ V_262 , F_10 (odd_dividers) } ,
} ;
struct V_240 V_241 ;
unsigned int V_266 , V_128 , V_39 ;
unsigned int V_151 , V_152 , V_153 ;
F_83 ( & V_241 ) ;
for ( V_128 = 0 ; V_128 < F_10 ( V_265 ) ; V_128 ++ ) {
for ( V_266 = 0 ; V_266 < F_10 ( V_260 ) ; V_266 ++ ) {
for ( V_39 = 0 ; V_39 < V_265 [ V_128 ] . V_264 ; V_39 ++ ) {
unsigned int V_122 = V_265 [ V_128 ] . V_263 [ V_39 ] ;
T_3 V_154 = V_122 * V_252 ;
F_84 ( & V_241 ,
V_260 [ V_266 ] ,
V_154 ,
V_122 ) ;
if ( V_241 . V_242 == 0 )
goto V_267;
}
}
V_267:
if ( V_128 == 0 && V_241 . V_122 )
break;
}
if ( ! V_241 . V_122 ) {
F_81 ( L_14 , clock ) ;
return false ;
}
V_151 = V_152 = V_153 = 0 ;
F_86 ( V_241 . V_122 , & V_151 , & V_152 , & V_153 ) ;
F_87 ( V_259 , V_252 , V_241 . V_244 ,
V_151 , V_152 , V_153 ) ;
return true ;
}
static bool
F_91 ( struct V_74 * V_74 ,
struct V_109 * V_110 ,
struct V_1 * V_1 ,
int clock )
{
struct V_205 * V_190 ;
T_2 V_268 , V_269 , V_270 ;
V_268 = F_92 ( 0 ) ;
if ( V_1 -> type == V_12 ) {
struct V_250 V_259 = { 0 , } ;
V_268 |= F_66 ( 0 ) ;
if ( ! F_90 ( clock * 1000 , & V_259 ) )
return false ;
V_269 = V_271 |
F_93 ( V_259 . V_258 ) |
V_259 . V_257 ;
V_270 = F_94 ( V_259 . V_255 ) |
F_62 ( V_259 . V_256 ) |
F_95 ( V_259 . V_254 ) |
F_96 ( V_259 . V_253 ) |
V_259 . V_244 ;
} else if ( V_1 -> type == V_10 ) {
switch ( V_110 -> V_171 / 2 ) {
case 81000 :
V_268 |= F_97 ( V_183 , 0 ) ;
break;
case 135000 :
V_268 |= F_97 ( V_185 , 0 ) ;
break;
case 270000 :
V_268 |= F_97 ( V_188 , 0 ) ;
break;
}
V_269 = V_270 = 0 ;
} else
return true ;
memset ( & V_110 -> V_238 , 0 ,
sizeof( V_110 -> V_238 ) ) ;
V_110 -> V_238 . V_268 = V_268 ;
V_110 -> V_238 . V_269 = V_269 ;
V_110 -> V_238 . V_270 = V_270 ;
V_190 = F_80 ( V_74 , V_110 ) ;
if ( V_190 == NULL ) {
F_81 ( L_11 ,
F_50 ( V_74 -> V_108 ) ) ;
return false ;
}
V_110 -> V_87 = V_190 -> V_239 + 1 ;
return true ;
}
static bool
F_98 ( struct V_74 * V_74 ,
struct V_109 * V_110 ,
struct V_1 * V_1 ,
int clock )
{
struct V_205 * V_190 ;
struct V_272 V_273 = { 0 } ;
int V_274 = 0 ;
T_2 V_275 , V_276 , V_277 , V_278 ;
T_2 V_279 ;
if ( V_1 -> type == V_12 ) {
T_4 V_280 ;
if ( ! F_99 ( V_110 , clock , & V_280 ) ) {
F_81 ( L_15 ,
clock , F_50 ( V_74 -> V_108 ) ) ;
return false ;
}
V_273 . V_152 = V_280 . V_152 ;
V_273 . V_153 = V_280 . V_153 ;
F_39 ( V_280 . V_210 != 2 ) ;
V_273 . V_134 = V_280 . V_134 ;
V_273 . V_281 = V_280 . V_211 >> 22 ;
V_273 . V_282 = V_280 . V_211 & ( ( 1 << 22 ) - 1 ) ;
V_273 . V_283 = V_273 . V_282 != 0 ;
V_274 = V_280 . V_274 ;
} else if ( V_1 -> type == V_10 ||
V_1 -> type == V_11 ) {
int V_39 ;
V_273 = V_284 [ 0 ] ;
for ( V_39 = 0 ; V_39 < F_10 ( V_284 ) ; ++ V_39 ) {
if ( V_284 [ V_39 ] . clock == clock ) {
V_273 = V_284 [ V_39 ] ;
break;
}
}
V_274 = clock * 10 / 2 * V_273 . V_152 * V_273 . V_153 ;
}
if ( V_274 >= 6200000 && V_274 <= 6700000 ) {
V_275 = 4 ;
V_276 = 9 ;
V_277 = 3 ;
V_278 = 8 ;
} else if ( ( V_274 > 5400000 && V_274 < 6200000 ) ||
( V_274 >= 4800000 && V_274 < 5400000 ) ) {
V_275 = 5 ;
V_276 = 11 ;
V_277 = 3 ;
V_278 = 9 ;
} else if ( V_274 == 5400000 ) {
V_275 = 3 ;
V_276 = 8 ;
V_277 = 1 ;
V_278 = 9 ;
} else {
F_4 ( L_16 ) ;
return false ;
}
memset ( & V_110 -> V_238 , 0 ,
sizeof( V_110 -> V_238 ) ) ;
if ( clock > 270000 )
V_279 = 0x18 ;
else if ( clock > 135000 )
V_279 = 0x0d ;
else if ( clock > 67000 )
V_279 = 0x07 ;
else if ( clock > 33000 )
V_279 = 0x04 ;
else
V_279 = 0x02 ;
V_110 -> V_238 . V_221 =
F_100 ( V_273 . V_152 ) | F_101 ( V_273 . V_153 ) ;
V_110 -> V_238 . V_212 = V_273 . V_281 ;
V_110 -> V_238 . V_218 = F_102 ( V_273 . V_134 ) ;
V_110 -> V_238 . V_216 = V_273 . V_282 ;
if ( V_273 . V_283 )
V_110 -> V_238 . V_214 =
V_215 ;
V_110 -> V_238 . V_285 =
V_275 | F_103 ( V_276 ) ;
V_110 -> V_238 . V_285 |=
F_104 ( V_277 ) ;
V_110 -> V_238 . V_286 = V_278 ;
V_110 -> V_238 . V_287 = 5 << V_288 ;
V_110 -> V_238 . V_289 =
F_105 ( V_290 )
| V_291 ;
V_110 -> V_238 . V_292 = V_293 ;
V_110 -> V_238 . V_294 =
V_295 | V_279 ;
V_190 = F_80 ( V_74 , V_110 ) ;
if ( V_190 == NULL ) {
F_81 ( L_11 ,
F_50 ( V_74 -> V_108 ) ) ;
return false ;
}
V_110 -> V_87 = V_190 -> V_239 ;
return true ;
}
bool F_106 ( struct V_74 * V_74 ,
struct V_109 * V_110 )
{
struct V_20 * V_21 = V_74 -> V_7 . V_21 ;
struct V_1 * V_1 =
F_52 ( V_110 ) ;
int clock = V_110 -> V_171 ;
if ( F_17 ( V_21 ) )
return F_91 ( V_74 , V_110 ,
V_1 , clock ) ;
else if ( F_15 ( V_21 ) )
return F_98 ( V_74 , V_110 ,
V_1 , clock ) ;
else
return F_76 ( V_74 , V_110 ,
V_1 , clock ) ;
}
void F_107 ( struct V_72 * V_73 )
{
struct V_27 * V_28 = V_73 -> V_21 -> V_29 ;
struct V_74 * V_74 = F_33 ( V_73 ) ;
struct V_1 * V_1 = F_48 ( V_73 ) ;
enum V_296 V_297 = V_74 -> V_83 -> V_297 ;
int type = V_1 -> type ;
T_2 V_75 ;
if ( type == V_10 || type == V_11 || type == V_8 ) {
V_75 = V_298 ;
switch ( V_74 -> V_83 -> V_176 ) {
case 18 :
V_75 |= V_299 ;
break;
case 24 :
V_75 |= V_300 ;
break;
case 30 :
V_75 |= V_301 ;
break;
case 36 :
V_75 |= V_302 ;
break;
default:
F_5 () ;
}
F_23 ( F_108 ( V_297 ) , V_75 ) ;
}
}
void F_109 ( struct V_72 * V_73 , bool V_112 )
{
struct V_74 * V_74 = F_33 ( V_73 ) ;
struct V_20 * V_21 = V_73 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_296 V_297 = V_74 -> V_83 -> V_297 ;
T_2 V_75 ;
V_75 = F_30 ( F_110 ( V_297 ) ) ;
if ( V_112 == true )
V_75 |= V_303 ;
else
V_75 &= ~ V_303 ;
F_23 ( F_110 ( V_297 ) , V_75 ) ;
}
void F_111 ( struct V_72 * V_73 )
{
struct V_74 * V_74 = F_33 ( V_73 ) ;
struct V_1 * V_1 = F_48 ( V_73 ) ;
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_20 * V_21 = V_73 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_108 V_108 = V_74 -> V_108 ;
enum V_296 V_297 = V_74 -> V_83 -> V_297 ;
enum V_4 V_4 = F_6 ( V_1 ) ;
int type = V_1 -> type ;
T_2 V_75 ;
V_75 = V_304 ;
V_75 |= F_112 ( V_4 ) ;
switch ( V_74 -> V_83 -> V_176 ) {
case 18 :
V_75 |= V_305 ;
break;
case 24 :
V_75 |= V_306 ;
break;
case 30 :
V_75 |= V_307 ;
break;
case 36 :
V_75 |= V_308 ;
break;
default:
F_5 () ;
}
if ( V_74 -> V_83 -> V_7 . V_178 . V_309 & V_310 )
V_75 |= V_311 ;
if ( V_74 -> V_83 -> V_7 . V_178 . V_309 & V_312 )
V_75 |= V_313 ;
if ( V_297 == V_314 ) {
switch ( V_108 ) {
case V_315 :
if ( F_19 ( V_21 ) &&
( V_74 -> V_83 -> V_316 . V_317 ||
V_74 -> V_83 -> V_316 . V_318 ) )
V_75 |= V_319 ;
else
V_75 |= V_320 ;
break;
case V_321 :
V_75 |= V_322 ;
break;
case V_323 :
V_75 |= V_324 ;
break;
default:
F_5 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_74 -> V_83 -> V_175 )
V_75 |= V_325 ;
else
V_75 |= V_326 ;
} else if ( type == V_14 ) {
V_75 |= V_327 ;
V_75 |= ( V_74 -> V_83 -> V_84 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_102 * V_102 = F_46 ( V_6 ) ;
if ( V_102 -> V_328 ) {
V_75 |= V_329 ;
} else
V_75 |= V_330 ;
V_75 |= F_47 ( V_102 -> V_105 ) ;
} else if ( type == V_8 ) {
struct V_102 * V_102 = & F_2 ( V_6 ) -> V_9 -> V_331 ;
if ( V_102 -> V_328 ) {
V_75 |= V_329 ;
} else
V_75 |= V_330 ;
V_75 |= F_47 ( V_102 -> V_105 ) ;
} else {
F_20 ( 1 , L_17 ,
V_1 -> type , F_50 ( V_108 ) ) ;
}
F_23 ( F_110 ( V_297 ) , V_75 ) ;
}
void F_113 ( struct V_27 * V_28 ,
enum V_296 V_297 )
{
T_2 V_37 = F_110 ( V_297 ) ;
T_2 V_189 = F_30 ( V_37 ) ;
V_189 &= ~ ( V_304 | V_332 | V_303 ) ;
V_189 |= V_333 ;
F_23 ( V_37 , V_189 ) ;
}
bool F_114 ( struct V_334 * V_334 )
{
struct V_20 * V_21 = V_334 -> V_7 . V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_1 * V_1 = V_334 -> V_6 ;
int type = V_334 -> V_7 . V_335 ;
enum V_4 V_4 = F_6 ( V_1 ) ;
enum V_108 V_108 = 0 ;
enum V_296 V_297 ;
enum V_336 V_337 ;
T_2 V_338 ;
V_337 = F_115 ( V_1 ) ;
if ( ! F_116 ( V_28 , V_337 ) )
return false ;
if ( ! V_1 -> V_339 ( V_1 , & V_108 ) )
return false ;
if ( V_4 == V_62 )
V_297 = V_314 ;
else
V_297 = (enum V_296 ) V_108 ;
V_338 = F_30 ( F_110 ( V_297 ) ) ;
switch ( V_338 & V_340 ) {
case V_325 :
case V_326 :
return ( type == V_341 ) ;
case V_330 :
if ( type == V_342 )
return true ;
return ( type == V_343 ) ;
case V_329 :
return false ;
case V_327 :
return ( type == V_344 ) ;
default:
return false ;
}
}
bool F_117 ( struct V_1 * V_6 ,
enum V_108 * V_108 )
{
struct V_20 * V_21 = V_6 -> V_7 . V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_4 V_4 = F_6 ( V_6 ) ;
enum V_336 V_337 ;
T_1 V_338 ;
int V_39 ;
V_337 = F_115 ( V_6 ) ;
if ( ! F_116 ( V_28 , V_337 ) )
return false ;
V_338 = F_30 ( F_28 ( V_4 ) ) ;
if ( ! ( V_338 & V_93 ) )
return false ;
if ( V_4 == V_62 ) {
V_338 = F_30 ( F_110 ( V_314 ) ) ;
switch ( V_338 & V_345 ) {
case V_320 :
case V_319 :
* V_108 = V_315 ;
break;
case V_322 :
* V_108 = V_321 ;
break;
case V_324 :
* V_108 = V_323 ;
break;
}
return true ;
} else {
for ( V_39 = V_346 ; V_39 <= V_347 ; V_39 ++ ) {
V_338 = F_30 ( F_110 ( V_39 ) ) ;
if ( ( V_338 & V_332 )
== F_112 ( V_4 ) ) {
if ( ( V_338 & V_340 ) == V_329 )
return false ;
* V_108 = V_39 ;
return true ;
}
}
}
F_44 ( L_18 , F_31 ( V_4 ) ) ;
return false ;
}
void F_118 ( struct V_74 * V_74 )
{
struct V_72 * V_73 = & V_74 -> V_7 ;
struct V_27 * V_28 = V_73 -> V_21 -> V_29 ;
struct V_1 * V_1 = F_48 ( V_73 ) ;
enum V_4 V_4 = F_6 ( V_1 ) ;
enum V_296 V_297 = V_74 -> V_83 -> V_297 ;
if ( V_297 != V_314 )
F_23 ( F_119 ( V_297 ) ,
F_120 ( V_4 ) ) ;
}
void F_121 ( struct V_74 * V_74 )
{
struct V_27 * V_28 = V_74 -> V_7 . V_21 -> V_29 ;
enum V_296 V_297 = V_74 -> V_83 -> V_297 ;
if ( V_297 != V_314 )
F_23 ( F_119 ( V_297 ) ,
V_348 ) ;
}
static void F_122 ( struct V_20 * V_21 , T_1 V_349 ,
enum V_4 V_4 , int type )
{
struct V_27 * V_28 = V_21 -> V_29 ;
const struct V_19 * V_23 ;
T_5 V_350 ;
T_5 V_351 , V_352 ;
int V_22 ;
T_1 V_37 ;
V_351 = V_28 -> V_46 . V_47 [ V_4 ] . V_54 ;
V_352 = V_28 -> V_46 . V_47 [ V_4 ] . V_53 ;
if ( type == V_10 ) {
if ( V_351 ) {
V_350 = V_351 ;
} else {
V_23 = F_8 ( V_21 , & V_22 ) ;
V_350 = V_23 [ V_4 ] . V_353 ;
}
} else if ( type == V_11 ) {
if ( V_351 ) {
V_350 = V_351 ;
} else {
V_23 = F_12 ( V_21 , & V_22 ) ;
V_350 = V_23 [ V_4 ] . V_353 ;
}
} else if ( type == V_12 ) {
if ( V_352 ) {
V_350 = V_352 ;
} else {
V_23 = F_13 ( V_21 , & V_22 ) ;
V_350 = V_23 [ V_4 ] . V_353 ;
}
} else {
return;
}
if ( V_350 && V_350 != 0x1 && V_350 != 0x3 && V_350 != 0x7 ) {
F_4 ( L_19 , V_350 ) ;
return;
}
V_37 = F_30 ( V_354 ) ;
V_37 &= ~ F_123 ( V_4 ) ;
V_37 &= ~ ( 1 << ( V_355 + V_4 ) ) ;
if ( V_350 )
V_37 |= V_350 << F_124 ( V_4 ) ;
else
V_37 |= 1 << ( V_355 + V_4 ) ;
F_23 ( V_354 , V_37 ) ;
}
static void F_16 ( struct V_20 * V_21 , T_1 V_349 ,
enum V_4 V_4 , int type )
{
struct V_27 * V_28 = V_21 -> V_29 ;
const struct V_356 * V_23 ;
T_1 V_22 , V_39 ;
T_2 V_189 ;
if ( type == V_10 || type == V_11 ) {
V_22 = F_10 ( V_357 ) ;
V_23 = V_357 ;
} else if ( type == V_12 ) {
V_22 = F_10 ( V_358 ) ;
V_23 = V_358 ;
} else {
F_44 ( L_20 ,
type ) ;
return;
}
if ( V_349 >= V_22 ||
( type == V_12 && V_349 == V_68 ) ) {
for ( V_39 = 0 ; V_39 < V_22 ; V_39 ++ ) {
if ( V_23 [ V_39 ] . V_359 ) {
V_349 = V_39 ;
break;
}
}
}
V_189 = F_30 ( F_125 ( V_4 ) ) ;
V_189 &= ~ ( V_360 | V_361 ) ;
F_23 ( F_126 ( V_4 ) , V_189 ) ;
V_189 = F_30 ( F_127 ( V_4 ) ) ;
V_189 &= ~ ( V_362 | V_363 ) ;
V_189 |= V_23 [ V_349 ] . V_364 << V_365 |
V_23 [ V_349 ] . V_366 << V_367 ;
F_23 ( F_128 ( V_4 ) , V_189 ) ;
V_189 = F_30 ( F_129 ( V_4 ) ) ;
V_189 &= ~ V_368 ;
if ( V_23 [ V_349 ] . V_369 )
V_189 |= V_368 ;
F_23 ( F_130 ( V_4 ) , V_189 ) ;
V_189 = F_30 ( F_131 ( V_4 ) ) ;
V_189 &= ~ V_370 ;
V_189 |= V_23 [ V_349 ] . V_371 << V_372 ;
F_23 ( F_132 ( V_4 ) , V_189 ) ;
V_189 = F_30 ( F_125 ( V_4 ) ) ;
V_189 |= V_360 | V_361 ;
F_23 ( F_126 ( V_4 ) , V_189 ) ;
}
static T_2 F_133 ( int V_373 )
{
T_2 V_349 ;
switch ( V_373 ) {
default:
F_44 ( L_21 ,
V_373 ) ;
case V_374 | V_375 :
V_349 = 0 ;
break;
case V_374 | V_376 :
V_349 = 1 ;
break;
case V_374 | V_377 :
V_349 = 2 ;
break;
case V_374 | V_378 :
V_349 = 3 ;
break;
case V_379 | V_375 :
V_349 = 4 ;
break;
case V_379 | V_376 :
V_349 = 5 ;
break;
case V_379 | V_377 :
V_349 = 6 ;
break;
case V_380 | V_375 :
V_349 = 7 ;
break;
case V_380 | V_376 :
V_349 = 8 ;
break;
case V_381 | V_375 :
V_349 = 9 ;
break;
}
return V_349 ;
}
T_2 F_134 ( struct V_102 * V_102 )
{
struct V_2 * V_382 = F_135 ( V_102 ) ;
struct V_20 * V_21 = V_382 -> V_7 . V_7 . V_21 ;
struct V_1 * V_6 = & V_382 -> V_7 ;
T_5 V_383 = V_102 -> V_383 [ 0 ] ;
int V_373 = V_383 & ( V_384 |
V_385 ) ;
enum V_4 V_4 = V_382 -> V_4 ;
T_2 V_349 ;
V_349 = F_133 ( V_373 ) ;
if ( F_17 ( V_21 ) )
F_122 ( V_21 , V_349 , V_4 , V_6 -> type ) ;
else if ( F_15 ( V_21 ) )
F_16 ( V_21 , V_349 , V_4 , V_6 -> type ) ;
return F_41 ( V_349 ) ;
}
static void F_136 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_74 * V_73 = F_33 ( V_6 -> V_73 ) ;
enum V_4 V_4 = F_6 ( V_1 ) ;
int type = V_1 -> type ;
int V_45 ;
if ( type == V_11 ) {
struct V_102 * V_102 = F_46 ( V_6 ) ;
F_137 ( V_102 ) ;
}
if ( F_17 ( V_21 ) ) {
T_2 V_146 = V_73 -> V_83 -> V_87 ;
T_2 V_189 ;
if ( type == V_11 ) {
F_39 ( V_146 != V_386 ) ;
V_189 = F_30 ( V_182 ) ;
V_189 &= ~ ( F_66 ( V_146 ) |
F_138 ( V_146 ) |
F_67 ( V_146 ) ) ;
V_189 |= V_73 -> V_83 -> V_238 . V_268 << ( V_146 * 6 ) ;
F_23 ( V_182 , V_189 ) ;
F_37 ( V_182 ) ;
}
V_189 = F_30 ( V_387 ) ;
V_189 &= ~ ( F_139 ( V_4 ) |
F_140 ( V_4 ) ) ;
V_189 |= ( F_141 ( V_146 , V_4 ) |
F_142 ( V_4 ) ) ;
F_23 ( V_387 , V_189 ) ;
} else if ( F_74 ( V_21 ) -> V_226 < 9 ) {
F_39 ( V_73 -> V_83 -> V_87 == V_388 ) ;
F_23 ( F_38 ( V_4 ) , V_73 -> V_83 -> V_87 ) ;
}
if ( type == V_10 || type == V_11 ) {
struct V_102 * V_102 = F_46 ( V_6 ) ;
F_45 ( V_1 ) ;
F_143 ( V_102 , V_389 ) ;
F_144 ( V_102 ) ;
F_145 ( V_102 ) ;
if ( V_4 != V_62 || F_74 ( V_21 ) -> V_226 >= 9 )
F_146 ( V_102 ) ;
} else if ( type == V_12 ) {
struct V_390 * V_390 = F_147 ( V_6 ) ;
if ( F_15 ( V_21 ) ) {
V_45 = V_28 -> V_46 .
V_47 [ V_4 ] . V_48 ;
F_16 ( V_21 , V_45 , V_4 ,
V_12 ) ;
}
V_390 -> V_391 ( V_6 ,
V_73 -> V_83 -> V_175 ,
& V_73 -> V_83 -> V_7 . V_178 ) ;
}
}
static void F_148 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_4 V_4 = F_6 ( V_1 ) ;
int type = V_1 -> type ;
T_2 V_189 ;
bool V_392 = false ;
V_189 = F_30 ( F_28 ( V_4 ) ) ;
if ( V_189 & V_93 ) {
V_189 &= ~ V_93 ;
F_23 ( F_28 ( V_4 ) , V_189 ) ;
V_392 = true ;
}
V_189 = F_30 ( F_40 ( V_4 ) ) ;
V_189 &= ~ ( V_92 | V_101 ) ;
V_189 |= V_91 ;
F_23 ( F_40 ( V_4 ) , V_189 ) ;
if ( V_392 )
F_27 ( V_28 , V_4 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_102 * V_102 = F_46 ( V_6 ) ;
F_143 ( V_102 , V_393 ) ;
F_149 ( V_102 ) ;
F_150 ( V_102 ) ;
}
if ( F_17 ( V_21 ) )
F_23 ( V_387 , ( F_30 ( V_387 ) |
F_139 ( V_4 ) ) ) ;
else if ( F_74 ( V_21 ) -> V_226 < 9 )
F_23 ( F_38 ( V_4 ) , V_388 ) ;
}
static void F_151 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_72 * V_73 = V_6 -> V_73 ;
struct V_74 * V_74 = F_33 ( V_73 ) ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_4 V_4 = F_6 ( V_1 ) ;
int type = V_1 -> type ;
if ( type == V_12 ) {
struct V_2 * V_16 =
F_3 ( V_6 ) ;
F_23 ( F_28 ( V_4 ) ,
V_16 -> V_104 |
V_93 ) ;
} else if ( type == V_11 ) {
struct V_102 * V_102 = F_46 ( V_6 ) ;
if ( V_4 == V_62 && F_74 ( V_21 ) -> V_226 < 9 )
F_146 ( V_102 ) ;
F_152 ( V_102 ) ;
F_153 ( V_102 ) ;
F_154 ( V_102 ) ;
}
if ( V_74 -> V_83 -> V_394 ) {
F_155 ( V_28 , V_395 ) ;
F_156 ( V_1 ) ;
}
}
static void F_157 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_72 * V_73 = V_6 -> V_73 ;
struct V_74 * V_74 = F_33 ( V_73 ) ;
int type = V_1 -> type ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
if ( V_74 -> V_83 -> V_394 ) {
F_158 ( V_1 ) ;
F_159 ( V_28 , V_395 ) ;
}
if ( type == V_11 ) {
struct V_102 * V_102 = F_46 ( V_6 ) ;
F_160 ( V_102 ) ;
F_161 ( V_102 ) ;
F_162 ( V_102 ) ;
}
}
static void F_163 ( struct V_27 * V_28 ,
struct V_205 * V_190 )
{
F_23 ( F_164 ( V_190 -> V_239 ) , V_190 -> V_83 . V_209 . V_136 ) ;
F_37 ( F_164 ( V_190 -> V_239 ) ) ;
F_29 ( 20 ) ;
}
static void F_165 ( struct V_27 * V_28 ,
struct V_205 * V_190 )
{
T_2 V_189 ;
V_189 = F_30 ( F_164 ( V_190 -> V_239 ) ) ;
F_23 ( F_164 ( V_190 -> V_239 ) , V_189 & ~ V_237 ) ;
F_37 ( F_164 ( V_190 -> V_239 ) ) ;
}
static bool F_166 ( struct V_27 * V_28 ,
struct V_205 * V_190 ,
struct V_206 * V_209 )
{
T_2 V_189 ;
if ( ! F_116 ( V_28 , V_396 ) )
return false ;
V_189 = F_30 ( F_164 ( V_190 -> V_239 ) ) ;
V_209 -> V_136 = V_189 ;
return V_189 & V_237 ;
}
static void F_167 ( struct V_27 * V_28 )
{
int V_39 ;
V_28 -> V_397 = 2 ;
for ( V_39 = 0 ; V_39 < V_28 -> V_397 ; V_39 ++ ) {
V_28 -> V_208 [ V_39 ] . V_239 = V_39 ;
V_28 -> V_208 [ V_39 ] . V_398 = V_399 [ V_39 ] ;
V_28 -> V_208 [ V_39 ] . V_400 = F_165 ;
V_28 -> V_208 [ V_39 ] . V_369 = F_163 ;
V_28 -> V_208 [ V_39 ] . V_339 =
F_166 ;
}
}
static void F_168 ( struct V_27 * V_28 ,
struct V_205 * V_190 )
{
T_2 V_189 ;
unsigned int V_146 ;
const struct V_401 * V_402 = V_401 ;
V_146 = V_190 -> V_239 + 1 ;
V_189 = F_30 ( V_182 ) ;
V_189 &= ~ ( F_66 ( V_146 ) | F_138 ( V_146 ) |
F_67 ( V_146 ) ) ;
V_189 |= V_190 -> V_83 . V_209 . V_268 << ( V_146 * 6 ) ;
F_23 ( V_182 , V_189 ) ;
F_37 ( V_182 ) ;
F_23 ( V_402 [ V_190 -> V_239 ] . V_269 , V_190 -> V_83 . V_209 . V_269 ) ;
F_23 ( V_402 [ V_190 -> V_239 ] . V_270 , V_190 -> V_83 . V_209 . V_270 ) ;
F_37 ( V_402 [ V_190 -> V_239 ] . V_269 ) ;
F_37 ( V_402 [ V_190 -> V_239 ] . V_270 ) ;
F_23 ( V_402 [ V_190 -> V_239 ] . V_403 ,
F_30 ( V_402 [ V_190 -> V_239 ] . V_403 ) | V_404 ) ;
if ( F_169 ( F_30 ( V_405 ) & F_170 ( V_146 ) , 5 ) )
F_4 ( L_22 , V_146 ) ;
}
static void F_171 ( struct V_27 * V_28 ,
struct V_205 * V_190 )
{
const struct V_401 * V_402 = V_401 ;
F_23 ( V_402 [ V_190 -> V_239 ] . V_403 ,
F_30 ( V_402 [ V_190 -> V_239 ] . V_403 ) & ~ V_404 ) ;
F_37 ( V_402 [ V_190 -> V_239 ] . V_403 ) ;
}
static bool F_172 ( struct V_27 * V_28 ,
struct V_205 * V_190 ,
struct V_206 * V_209 )
{
T_2 V_189 ;
unsigned int V_146 ;
const struct V_401 * V_402 = V_401 ;
if ( ! F_116 ( V_28 , V_396 ) )
return false ;
V_146 = V_190 -> V_239 + 1 ;
V_189 = F_30 ( V_402 [ V_190 -> V_239 ] . V_403 ) ;
if ( ! ( V_189 & V_404 ) )
return false ;
V_189 = F_30 ( V_182 ) ;
V_209 -> V_268 = ( V_189 >> ( V_146 * 6 ) ) & 0x3f ;
if ( V_189 & F_66 ( V_146 ) ) {
V_209 -> V_269 = F_30 ( V_402 [ V_190 -> V_239 ] . V_269 ) ;
V_209 -> V_270 = F_30 ( V_402 [ V_190 -> V_239 ] . V_270 ) ;
}
return true ;
}
static void F_173 ( struct V_27 * V_28 )
{
int V_39 ;
V_28 -> V_397 = 3 ;
for ( V_39 = 0 ; V_39 < V_28 -> V_397 ; V_39 ++ ) {
V_28 -> V_208 [ V_39 ] . V_239 = V_39 ;
V_28 -> V_208 [ V_39 ] . V_398 = V_406 [ V_39 ] ;
V_28 -> V_208 [ V_39 ] . V_400 = F_171 ;
V_28 -> V_208 [ V_39 ] . V_369 = F_168 ;
V_28 -> V_208 [ V_39 ] . V_339 =
F_172 ;
}
}
static void F_174 ( struct V_27 * V_28 ,
enum V_407 V_408 )
{
enum V_4 V_4 ;
T_2 V_189 ;
V_189 = F_30 ( V_409 ) ;
V_189 |= F_175 ( V_408 ) ;
F_23 ( V_409 , V_189 ) ;
if ( F_169 ( F_30 ( F_176 ( V_408 ) ) & V_410 , 10 ) )
F_4 ( L_23 , V_408 ) ;
for ( V_4 = ( V_408 == V_411 ? V_63 : V_62 ) ;
V_4 <= ( V_408 == V_411 ? V_64 : V_62 ) ; V_4 ++ ) {
int V_412 ;
for ( V_412 = 0 ; V_412 < 4 ; V_412 ++ ) {
V_189 = F_30 ( F_177 ( V_4 , V_412 ) ) ;
V_189 &= ~ V_413 ;
if ( V_412 != 1 )
V_189 |= V_413 ;
F_23 ( F_177 ( V_4 , V_412 ) , V_189 ) ;
}
}
V_189 = F_30 ( F_178 ( V_408 ) ) ;
V_189 &= ~ V_414 ;
V_189 |= 0xE4 << V_415 ;
F_23 ( F_178 ( V_408 ) , V_189 ) ;
V_189 = F_30 ( F_179 ( V_408 ) ) ;
V_189 &= ~ V_416 ;
V_189 |= 0xE4 << V_417 ;
F_23 ( F_179 ( V_408 ) , V_189 ) ;
V_189 = F_30 ( F_180 ( V_408 ) ) ;
V_189 |= V_418 | V_419 |
V_420 ;
F_23 ( F_180 ( V_408 ) , V_189 ) ;
if ( V_408 == V_411 ) {
V_189 = F_30 ( V_421 ) ;
V_189 |= V_422 ;
F_23 ( V_421 , V_189 ) ;
}
V_189 = F_30 ( F_181 ( V_408 ) ) ;
V_189 &= ~ V_423 ;
if ( V_408 == V_424 )
V_189 |= V_423 ;
F_23 ( F_181 ( V_408 ) , V_189 ) ;
if ( V_408 == V_411 ) {
T_2 V_425 ;
if ( F_169 ( F_30 ( F_182 ( V_424 ) ) & V_426 ,
10 ) )
F_4 ( L_24 ) ;
V_189 = F_30 ( F_183 ( V_424 ) ) ;
V_189 = ( V_189 & V_427 ) >> V_428 ;
V_425 = V_189 << V_429 |
V_189 << V_430 |
V_189 ;
F_23 ( F_183 ( V_411 ) , V_425 ) ;
V_189 = F_30 ( F_184 ( V_411 ) ) ;
V_189 |= V_431 | V_432 ;
F_23 ( F_184 ( V_411 ) , V_189 ) ;
}
V_189 = F_30 ( F_185 ( V_408 ) ) ;
V_189 |= V_433 ;
F_23 ( F_185 ( V_408 ) , V_189 ) ;
}
void F_186 ( struct V_20 * V_21 )
{
F_174 ( V_21 -> V_29 , V_424 ) ;
F_174 ( V_21 -> V_29 , V_411 ) ;
}
static void F_187 ( struct V_27 * V_28 ,
enum V_407 V_408 )
{
T_2 V_189 ;
V_189 = F_30 ( F_185 ( V_408 ) ) ;
V_189 &= ~ V_433 ;
F_23 ( F_185 ( V_408 ) , V_189 ) ;
}
void F_188 ( struct V_20 * V_21 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
F_187 ( V_28 , V_424 ) ;
F_187 ( V_28 , V_411 ) ;
F_23 ( V_409 , 0 ) ;
}
static void F_189 ( struct V_27 * V_28 ,
struct V_205 * V_190 )
{
T_2 V_75 ;
enum V_4 V_4 = (enum V_4 ) V_190 -> V_239 ;
V_75 = F_30 ( F_190 ( V_4 ) ) ;
V_75 &= ~ V_434 ;
F_23 ( F_190 ( V_4 ) , V_75 ) ;
V_75 = F_30 ( F_191 ( V_4 ) ) ;
V_75 &= ~ V_293 ;
F_23 ( F_191 ( V_4 ) , V_75 ) ;
V_75 = F_30 ( F_192 ( V_4 ) ) ;
V_75 &= ~ ( V_222 | V_224 ) ;
V_75 |= V_190 -> V_83 . V_209 . V_221 ;
F_23 ( F_192 ( V_4 ) , V_75 ) ;
V_75 = F_30 ( F_193 ( V_4 , 0 ) ) ;
V_75 &= ~ V_213 ;
V_75 |= V_190 -> V_83 . V_209 . V_212 ;
F_23 ( F_193 ( V_4 , 0 ) , V_75 ) ;
V_75 = F_30 ( F_193 ( V_4 , 1 ) ) ;
V_75 &= ~ V_219 ;
V_75 |= V_190 -> V_83 . V_209 . V_218 ;
F_23 ( F_193 ( V_4 , 1 ) , V_75 ) ;
V_75 = F_30 ( F_193 ( V_4 , 2 ) ) ;
V_75 &= ~ V_217 ;
V_75 |= V_190 -> V_83 . V_209 . V_216 ;
F_23 ( F_193 ( V_4 , 2 ) , V_75 ) ;
V_75 = F_30 ( F_193 ( V_4 , 3 ) ) ;
V_75 &= ~ V_215 ;
V_75 |= V_190 -> V_83 . V_209 . V_214 ;
F_23 ( F_193 ( V_4 , 3 ) , V_75 ) ;
V_75 = F_30 ( F_193 ( V_4 , 6 ) ) ;
V_75 &= ~ V_435 ;
V_75 &= ~ V_436 ;
V_75 &= ~ V_437 ;
V_75 |= V_190 -> V_83 . V_209 . V_285 ;
F_23 ( F_193 ( V_4 , 6 ) , V_75 ) ;
V_75 = F_30 ( F_193 ( V_4 , 8 ) ) ;
V_75 &= ~ V_438 ;
V_75 |= V_190 -> V_83 . V_209 . V_286 ;
F_23 ( F_193 ( V_4 , 8 ) , V_75 ) ;
V_75 = F_30 ( F_193 ( V_4 , 9 ) ) ;
V_75 &= ~ V_439 ;
V_75 |= V_190 -> V_83 . V_209 . V_287 ;
F_23 ( F_193 ( V_4 , 9 ) , V_75 ) ;
V_75 = F_30 ( F_193 ( V_4 , 10 ) ) ;
V_75 &= ~ V_291 ;
V_75 &= ~ V_440 ;
V_75 |= V_190 -> V_83 . V_209 . V_289 ;
F_23 ( F_193 ( V_4 , 10 ) , V_75 ) ;
V_75 = F_30 ( F_191 ( V_4 ) ) ;
V_75 |= V_441 ;
F_23 ( F_191 ( V_4 ) , V_75 ) ;
V_75 &= ~ V_293 ;
V_75 |= V_190 -> V_83 . V_209 . V_292 ;
F_23 ( F_191 ( V_4 ) , V_75 ) ;
V_75 = F_30 ( F_190 ( V_4 ) ) ;
V_75 |= V_442 ;
F_23 ( F_190 ( V_4 ) , V_75 ) ;
F_37 ( F_190 ( V_4 ) ) ;
if ( F_194 ( ( F_30 ( F_190 ( V_4 ) ) &
V_443 ) , 200 ) )
F_4 ( L_25 , V_4 ) ;
V_75 = F_30 ( F_195 ( V_4 ) ) ;
V_75 &= ~ V_444 ;
V_75 &= ~ V_295 ;
V_75 |= V_190 -> V_83 . V_209 . V_294 ;
F_23 ( F_196 ( V_4 ) , V_75 ) ;
}
static void F_197 ( struct V_27 * V_28 ,
struct V_205 * V_190 )
{
enum V_4 V_4 = (enum V_4 ) V_190 -> V_239 ;
T_2 V_75 ;
V_75 = F_30 ( F_190 ( V_4 ) ) ;
V_75 &= ~ V_442 ;
F_23 ( F_190 ( V_4 ) , V_75 ) ;
F_37 ( F_190 ( V_4 ) ) ;
}
static bool F_198 ( struct V_27 * V_28 ,
struct V_205 * V_190 ,
struct V_206 * V_209 )
{
enum V_4 V_4 = (enum V_4 ) V_190 -> V_239 ;
T_2 V_189 ;
if ( ! F_116 ( V_28 , V_396 ) )
return false ;
V_189 = F_30 ( F_190 ( V_4 ) ) ;
if ( ! ( V_189 & V_442 ) )
return false ;
V_209 -> V_221 = F_30 ( F_192 ( V_4 ) ) ;
V_209 -> V_221 &= V_222 | V_224 ;
V_209 -> V_292 = F_30 ( F_191 ( V_4 ) ) ;
V_209 -> V_292 &= V_293 ;
V_209 -> V_212 = F_30 ( F_193 ( V_4 , 0 ) ) ;
V_209 -> V_212 &= V_213 ;
V_209 -> V_218 = F_30 ( F_193 ( V_4 , 1 ) ) ;
V_209 -> V_218 &= V_219 ;
V_209 -> V_216 = F_30 ( F_193 ( V_4 , 2 ) ) ;
V_209 -> V_216 &= V_217 ;
V_209 -> V_214 = F_30 ( F_193 ( V_4 , 3 ) ) ;
V_209 -> V_214 &= V_215 ;
V_209 -> V_285 = F_30 ( F_193 ( V_4 , 6 ) ) ;
V_209 -> V_285 &= V_435 |
V_436 |
V_437 ;
V_209 -> V_286 = F_30 ( F_193 ( V_4 , 8 ) ) ;
V_209 -> V_286 &= V_438 ;
V_209 -> V_287 = F_30 ( F_193 ( V_4 , 9 ) ) ;
V_209 -> V_287 &= V_439 ;
V_209 -> V_289 = F_30 ( F_193 ( V_4 , 10 ) ) ;
V_209 -> V_289 &= V_291 |
V_440 ;
V_209 -> V_294 = F_30 ( F_195 ( V_4 ) ) ;
if ( F_30 ( F_199 ( V_4 ) != V_209 -> V_294 ) )
F_81 ( L_26 ,
V_209 -> V_294 ,
F_30 ( F_199 ( V_4 ) ) ) ;
V_209 -> V_294 &= V_444 | V_295 ;
return true ;
}
static void F_200 ( struct V_27 * V_28 )
{
int V_39 ;
V_28 -> V_397 = 3 ;
for ( V_39 = 0 ; V_39 < V_28 -> V_397 ; V_39 ++ ) {
V_28 -> V_208 [ V_39 ] . V_239 = V_39 ;
V_28 -> V_208 [ V_39 ] . V_398 = V_445 [ V_39 ] ;
V_28 -> V_208 [ V_39 ] . V_400 = F_197 ;
V_28 -> V_208 [ V_39 ] . V_369 = F_189 ;
V_28 -> V_208 [ V_39 ] . V_339 =
F_198 ;
}
}
void F_201 ( struct V_20 * V_21 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
T_2 V_189 = F_30 ( V_446 ) ;
if ( F_17 ( V_21 ) )
F_173 ( V_28 ) ;
else if ( F_15 ( V_21 ) )
F_200 ( V_28 ) ;
else
F_167 ( V_28 ) ;
if ( F_17 ( V_21 ) ) {
int V_447 ;
V_447 = V_28 -> V_448 . V_449 ( V_21 ) ;
V_28 -> V_450 = V_447 ;
if ( ! ( F_30 ( V_451 ) & V_404 ) )
F_4 ( L_27 ) ;
else
F_155 ( V_28 , V_396 ) ;
} else if ( F_15 ( V_21 ) ) {
F_202 ( V_21 ) ;
F_186 ( V_21 ) ;
} else {
if ( V_189 & V_452 )
F_4 ( L_28 ) ;
if ( V_189 & V_453 )
F_4 ( L_29 ) ;
}
}
void F_203 ( struct V_5 * V_6 )
{
struct V_2 * V_16 = F_3 ( V_6 ) ;
struct V_102 * V_102 = & V_16 -> V_331 ;
struct V_27 * V_28 = V_6 -> V_21 -> V_29 ;
enum V_4 V_4 = V_16 -> V_4 ;
T_2 V_189 ;
bool V_392 = false ;
if ( F_30 ( F_40 ( V_4 ) ) & V_92 ) {
V_189 = F_30 ( F_28 ( V_4 ) ) ;
if ( V_189 & V_93 ) {
V_189 &= ~ V_93 ;
F_23 ( F_28 ( V_4 ) , V_189 ) ;
V_392 = true ;
}
V_189 = F_30 ( F_40 ( V_4 ) ) ;
V_189 &= ~ ( V_92 | V_101 ) ;
V_189 |= V_91 ;
F_23 ( F_40 ( V_4 ) , V_189 ) ;
F_37 ( F_40 ( V_4 ) ) ;
if ( V_392 )
F_27 ( V_28 , V_4 ) ;
}
V_189 = V_92 |
V_91 | V_454 ;
if ( V_102 -> V_328 )
V_189 |= V_455 ;
else {
V_189 |= V_456 ;
if ( F_204 ( V_102 -> V_457 ) )
V_189 |= V_90 ;
}
F_23 ( F_40 ( V_4 ) , V_189 ) ;
F_37 ( F_40 ( V_4 ) ) ;
V_102 -> V_103 |= V_93 ;
F_23 ( F_28 ( V_4 ) , V_102 -> V_103 ) ;
F_37 ( F_28 ( V_4 ) ) ;
F_29 ( 600 ) ;
}
void F_205 ( struct V_72 * V_73 )
{
struct V_27 * V_28 = V_73 -> V_21 -> V_29 ;
struct V_1 * V_1 = F_48 ( V_73 ) ;
T_2 V_189 ;
F_148 ( V_1 ) ;
V_189 = F_30 ( V_85 ) ;
V_189 &= ~ V_95 ;
F_23 ( V_85 , V_189 ) ;
V_189 = F_30 ( V_77 ) ;
V_189 &= ~ ( V_97 | V_98 ) ;
V_189 |= F_34 ( 2 ) | F_35 ( 2 ) ;
F_23 ( V_77 , V_189 ) ;
V_189 = F_30 ( V_85 ) ;
V_189 &= ~ V_86 ;
F_23 ( V_85 , V_189 ) ;
V_189 = F_30 ( V_85 ) ;
V_189 &= ~ V_82 ;
F_23 ( V_85 , V_189 ) ;
}
void F_206 ( struct V_1 * V_6 ,
struct V_109 * V_168 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
struct V_74 * V_74 = F_33 ( V_6 -> V_7 . V_73 ) ;
enum V_296 V_297 = V_168 -> V_297 ;
struct V_390 * V_390 ;
T_1 V_75 , V_309 = 0 ;
V_75 = F_30 ( F_110 ( V_297 ) ) ;
if ( V_75 & V_313 )
V_309 |= V_312 ;
else
V_309 |= V_458 ;
if ( V_75 & V_311 )
V_309 |= V_310 ;
else
V_309 |= V_459 ;
V_168 -> V_7 . V_178 . V_309 |= V_309 ;
switch ( V_75 & V_460 ) {
case V_305 :
V_168 -> V_176 = 18 ;
break;
case V_306 :
V_168 -> V_176 = 24 ;
break;
case V_307 :
V_168 -> V_176 = 30 ;
break;
case V_308 :
V_168 -> V_176 = 36 ;
break;
default:
break;
}
switch ( V_75 & V_340 ) {
case V_325 :
V_168 -> V_175 = true ;
V_390 = F_147 ( & V_6 -> V_7 ) ;
if ( V_390 -> V_461 ( & V_6 -> V_7 ) )
V_168 -> V_462 = true ;
break;
case V_326 :
case V_327 :
break;
case V_330 :
case V_329 :
V_168 -> V_173 = true ;
F_207 ( V_74 , V_168 ) ;
break;
default:
break;
}
if ( F_116 ( V_28 , V_395 ) ) {
V_75 = F_30 ( V_463 ) ;
if ( V_75 & F_208 ( V_74 -> V_108 ) )
V_168 -> V_394 = true ;
}
if ( V_6 -> type == V_11 && V_28 -> V_46 . V_464 &&
V_168 -> V_176 > V_28 -> V_46 . V_464 ) {
F_44 ( L_30 ,
V_168 -> V_176 , V_28 -> V_46 . V_464 ) ;
V_28 -> V_46 . V_464 = V_168 -> V_176 ;
}
F_73 ( V_6 , V_168 ) ;
}
static void F_209 ( struct V_5 * V_6 )
{
F_210 ( V_6 ) ;
}
static bool F_211 ( struct V_1 * V_6 ,
struct V_109 * V_168 )
{
int type = V_6 -> type ;
int V_4 = F_6 ( V_6 ) ;
F_20 ( type == V_13 , L_31 ) ;
if ( V_4 == V_62 )
V_168 -> V_297 = V_314 ;
if ( type == V_12 )
return F_212 ( V_6 , V_168 ) ;
else
return F_213 ( V_6 , V_168 ) ;
}
static struct V_334 *
F_214 ( struct V_2 * V_16 )
{
struct V_334 * V_114 ;
enum V_4 V_4 = V_16 -> V_4 ;
V_114 = F_215 () ;
if ( ! V_114 )
return NULL ;
V_16 -> V_331 . V_465 = F_28 ( V_4 ) ;
if ( ! F_216 ( V_16 , V_114 ) ) {
F_217 ( V_114 ) ;
return NULL ;
}
return V_114 ;
}
static struct V_334 *
F_218 ( struct V_2 * V_16 )
{
struct V_334 * V_114 ;
enum V_4 V_4 = V_16 -> V_4 ;
V_114 = F_215 () ;
if ( ! V_114 )
return NULL ;
V_16 -> V_17 . V_18 = F_28 ( V_4 ) ;
F_219 ( V_16 , V_114 ) ;
return V_114 ;
}
void F_220 ( struct V_20 * V_21 , enum V_4 V_4 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_2 * V_16 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
bool V_466 , V_467 ;
V_466 = ( V_28 -> V_46 . V_47 [ V_4 ] . V_468 ||
V_28 -> V_46 . V_47 [ V_4 ] . V_36 ) ;
V_467 = V_28 -> V_46 . V_47 [ V_4 ] . V_469 ;
if ( ! V_467 && ! V_466 ) {
F_44 ( L_32 ,
F_31 ( V_4 ) ) ;
return;
}
V_16 = F_221 ( sizeof( * V_16 ) , V_470 ) ;
if ( ! V_16 )
return;
V_1 = & V_16 -> V_7 ;
V_6 = & V_1 -> V_7 ;
F_222 ( V_21 , V_6 , & V_471 ,
V_472 ) ;
V_1 -> V_473 = F_211 ;
V_1 -> V_369 = F_151 ;
V_1 -> V_474 = F_136 ;
V_1 -> V_400 = F_157 ;
V_1 -> V_475 = F_148 ;
V_1 -> V_339 = F_117 ;
V_1 -> V_476 = F_206 ;
V_16 -> V_4 = V_4 ;
V_16 -> V_104 = F_30 ( F_28 ( V_4 ) ) &
( V_477 |
V_478 ) ;
V_1 -> type = V_13 ;
V_1 -> V_479 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_1 -> V_480 = 0 ;
if ( V_467 ) {
if ( ! F_214 ( V_16 ) )
goto V_481;
V_16 -> V_482 = V_483 ;
V_28 -> V_484 . V_485 [ V_4 ] = V_16 ;
}
if ( V_1 -> type != V_11 && V_466 ) {
if ( ! F_218 ( V_16 ) )
goto V_481;
}
return;
V_481:
F_223 ( V_6 ) ;
F_217 ( V_16 ) ;
}
