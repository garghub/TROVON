static void F_1 ( struct V_1 * V_1 ,
struct V_2 * * V_3 ,
enum V_4 * V_4 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
switch ( V_1 -> type ) {
case V_8 :
* V_3 = F_2 ( V_6 ) -> V_9 ;
* V_4 = ( * V_3 ) -> V_4 ;
break;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
* V_3 = F_3 ( V_6 ) ;
* V_4 = ( * V_3 ) -> V_4 ;
break;
case V_14 :
* V_3 = NULL ;
* V_4 = V_15 ;
break;
default:
F_4 ( 1 , L_1 , V_1 -> type ) ;
break;
}
}
enum V_4 F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
enum V_4 V_4 ;
F_1 ( V_1 , & V_3 , & V_4 ) ;
return V_4 ;
}
static bool
F_6 ( const struct V_2 * V_16 )
{
return V_16 -> V_17 . V_18 ;
}
static const struct V_19 * F_7 ( struct V_20 * V_21 ,
int * V_22 )
{
const struct V_19 * V_23 ;
if ( F_8 ( V_21 ) ) {
V_23 = V_24 ;
* V_22 = F_9 ( V_24 ) ;
} else if ( F_10 ( V_21 ) ) {
V_23 = V_25 ;
* V_22 = F_9 ( V_25 ) ;
} else {
V_23 = V_26 ;
* V_22 = F_9 ( V_26 ) ;
}
return V_23 ;
}
static const struct V_19 * F_11 ( struct V_20 * V_21 ,
int * V_22 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
const struct V_19 * V_23 ;
if ( F_8 ( V_21 ) ) {
if ( V_28 -> V_30 ) {
V_23 = V_31 ;
* V_22 = F_9 ( V_31 ) ;
} else {
V_23 = V_24 ;
* V_22 = F_9 ( V_24 ) ;
}
} else if ( F_10 ( V_21 ) ) {
if ( V_28 -> V_30 ) {
V_23 = V_32 ;
* V_22 = F_9 ( V_32 ) ;
} else {
V_23 = V_25 ;
* V_22 = F_9 ( V_25 ) ;
}
} else {
if ( V_28 -> V_30 ) {
V_23 = V_33 ;
* V_22 = F_9 ( V_33 ) ;
} else {
V_23 = V_26 ;
* V_22 = F_9 ( V_26 ) ;
}
}
return V_23 ;
}
static const struct V_19 *
F_12 ( struct V_20 * V_21 ,
int * V_22 )
{
const struct V_19 * V_23 ;
if ( F_8 ( V_21 ) ) {
V_23 = V_34 ;
* V_22 = F_9 ( V_34 ) ;
} else {
V_23 = V_35 ;
* V_22 = F_9 ( V_35 ) ;
}
return V_23 ;
}
static void F_13 ( struct V_20 * V_21 , enum V_4 V_4 ,
bool V_36 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
T_1 V_37 = 0 ;
int V_38 , V_39 , V_40 , V_41 , V_42 ,
V_43 ;
int V_44 = V_28 -> V_45 . V_46 [ V_4 ] . V_47 ;
const struct V_19 * V_48 ;
const struct V_19 * V_49 ;
const struct V_19 * V_50 ;
const struct V_19 * V_51 ;
const struct V_19 * V_23 ;
if ( F_14 ( V_21 ) ) {
if ( ! V_36 )
return;
F_15 ( V_21 , V_44 , V_4 ,
V_12 ) ;
return;
} else if ( F_16 ( V_21 ) ) {
V_48 = NULL ;
V_49 =
F_7 ( V_21 , & V_40 ) ;
V_50 =
F_11 ( V_21 , & V_41 ) ;
V_51 =
F_12 ( V_21 , & V_39 ) ;
V_42 = 8 ;
if ( V_28 -> V_45 . V_46 [ V_4 ] . V_52 ||
V_28 -> V_45 . V_46 [ V_4 ] . V_53 )
V_37 = 1 << 31 ;
} else if ( F_17 ( V_21 ) ) {
V_48 = V_54 ;
V_49 = V_55 ;
V_50 = V_56 ;
V_51 = V_57 ;
V_41 = F_9 ( V_56 ) ;
V_40 = F_9 ( V_55 ) ;
V_39 = F_9 ( V_57 ) ;
V_42 = 7 ;
} else if ( F_18 ( V_21 ) ) {
V_48 = V_58 ;
V_49 = V_59 ;
V_50 = V_59 ;
V_51 = V_60 ;
V_40 = V_41 = F_9 ( V_59 ) ;
V_39 = F_9 ( V_60 ) ;
V_42 = 6 ;
} else {
F_4 ( 1 , L_2 ) ;
V_50 = V_55 ;
V_48 = V_54 ;
V_49 = V_55 ;
V_51 = V_57 ;
V_41 = F_9 ( V_56 ) ;
V_40 = F_9 ( V_55 ) ;
V_39 = F_9 ( V_57 ) ;
V_42 = 7 ;
}
switch ( V_4 ) {
case V_61 :
V_23 = V_50 ;
V_43 = V_41 ;
break;
case V_62 :
case V_63 :
V_23 = V_49 ;
V_43 = V_40 ;
break;
case V_64 :
if ( F_19 ( V_21 , V_64 ) ) {
V_23 = V_50 ;
V_43 = V_41 ;
} else {
V_23 = V_49 ;
V_43 = V_40 ;
}
break;
case V_15 :
if ( V_48 )
V_23 = V_48 ;
else
V_23 = V_49 ;
V_43 = V_40 ;
break;
default:
F_20 () ;
}
for ( V_38 = 0 ; V_38 < V_43 ; V_38 ++ ) {
F_21 ( F_22 ( V_4 , V_38 ) ,
V_23 [ V_38 ] . V_65 | V_37 ) ;
F_21 ( F_23 ( V_4 , V_38 ) ,
V_23 [ V_38 ] . V_66 ) ;
}
if ( ! V_36 )
return;
if ( V_44 == V_67 ||
V_44 >= V_39 )
V_44 = V_42 ;
F_21 ( F_22 ( V_4 , V_38 ) ,
V_51 [ V_44 ] . V_65 | V_37 ) ;
F_21 ( F_23 ( V_4 , V_38 ) ,
V_51 [ V_44 ] . V_66 ) ;
}
void F_24 ( struct V_20 * V_21 )
{
struct V_1 * V_1 ;
bool V_68 [ V_69 ] = { 0 , } ;
if ( ! F_25 ( V_21 ) )
return;
F_26 (dev, intel_encoder) {
struct V_2 * V_16 ;
enum V_4 V_4 ;
bool V_36 ;
if ( V_1 -> type == V_70 )
continue;
F_1 ( V_1 , & V_16 , & V_4 ) ;
if ( V_68 [ V_4 ] )
continue;
V_36 = V_16 &&
F_6 ( V_16 ) ;
F_13 ( V_21 , V_4 , V_36 ) ;
V_68 [ V_4 ] = true ;
}
}
static void F_27 ( struct V_27 * V_28 ,
enum V_4 V_4 )
{
T_2 V_71 = F_28 ( V_4 ) ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 16 ; V_38 ++ ) {
F_29 ( 1 ) ;
if ( F_30 ( V_71 ) & V_72 )
return;
}
F_31 ( L_3 , F_32 ( V_4 ) ) ;
}
void F_33 ( struct V_73 * V_74 )
{
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_75 * V_75 = F_34 ( V_74 ) ;
T_1 V_76 , V_38 , V_77 ;
F_21 ( F_35 ( V_78 ) , F_36 ( 2 ) |
F_37 ( 2 ) |
V_79 | V_80 ) ;
V_77 = V_28 -> V_81 | V_82 |
V_83 |
F_38 ( V_75 -> V_84 -> V_85 ) ;
F_21 ( F_39 ( V_78 ) , V_77 ) ;
F_40 ( F_39 ( V_78 ) ) ;
F_29 ( 220 ) ;
V_77 |= V_86 ;
F_21 ( F_39 ( V_78 ) , V_77 ) ;
F_21 ( F_41 ( V_15 ) , V_75 -> V_84 -> V_87 ) ;
F_42 ( V_75 -> V_84 -> V_87 != V_88 ) ;
for ( V_38 = 0 ; V_38 < F_9 ( V_58 ) * 2 ; V_38 ++ ) {
F_21 ( F_43 ( V_15 ) ,
V_89 |
V_90 |
V_91 |
V_92 ) ;
F_21 ( F_28 ( V_15 ) ,
V_93 |
( ( V_75 -> V_84 -> V_85 - 1 ) << 1 ) |
F_44 ( V_38 / 2 ) ) ;
F_40 ( F_28 ( V_15 ) ) ;
F_29 ( 600 ) ;
F_21 ( F_45 ( V_78 ) , F_46 ( 64 ) ) ;
V_77 |= V_94 | V_95 ;
F_21 ( F_39 ( V_78 ) , V_77 ) ;
F_40 ( F_39 ( V_78 ) ) ;
F_29 ( 30 ) ;
V_76 = F_30 ( F_35 ( V_78 ) ) ;
V_76 &= ~ ( V_96 | V_97 ) ;
F_21 ( F_35 ( V_78 ) , V_76 ) ;
F_40 ( F_35 ( V_78 ) ) ;
F_29 ( 5 ) ;
V_76 = F_30 ( F_47 ( V_15 ) ) ;
if ( V_76 & V_98 ) {
F_48 ( L_4 , V_38 ) ;
F_21 ( F_43 ( V_15 ) ,
V_89 |
V_99 |
V_90 |
V_92 ) ;
return;
}
V_76 = F_30 ( F_28 ( V_15 ) ) ;
V_76 &= ~ V_93 ;
F_21 ( F_28 ( V_15 ) , V_76 ) ;
F_40 ( F_28 ( V_15 ) ) ;
V_76 = F_30 ( F_43 ( V_15 ) ) ;
V_76 &= ~ ( V_92 | V_100 ) ;
V_76 |= V_91 ;
F_21 ( F_43 ( V_15 ) , V_76 ) ;
F_40 ( F_43 ( V_15 ) ) ;
F_27 ( V_28 , V_15 ) ;
V_77 &= ~ V_94 ;
F_21 ( F_39 ( V_78 ) , V_77 ) ;
F_40 ( F_39 ( V_78 ) ) ;
V_76 = F_30 ( F_35 ( V_78 ) ) ;
V_76 &= ~ ( V_96 | V_97 ) ;
V_76 |= F_36 ( 2 ) | F_37 ( 2 ) ;
F_21 ( F_35 ( V_78 ) , V_76 ) ;
F_40 ( F_35 ( V_78 ) ) ;
}
F_31 ( L_5 ) ;
}
void F_49 ( struct V_1 * V_6 )
{
struct V_101 * V_101 = F_50 ( & V_6 -> V_7 ) ;
struct V_2 * V_16 =
F_3 ( & V_6 -> V_7 ) ;
V_101 -> V_102 = V_16 -> V_103 |
V_93 | F_44 ( 0 ) ;
V_101 -> V_102 |= F_51 ( V_101 -> V_104 ) ;
}
static struct V_1 *
F_52 ( struct V_73 * V_74 )
{
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_75 * V_75 = F_34 ( V_74 ) ;
struct V_1 * V_1 , * V_105 = NULL ;
int V_106 = 0 ;
F_53 (dev, crtc, intel_encoder) {
V_105 = V_1 ;
V_106 ++ ;
}
if ( V_106 != 1 )
F_4 ( 1 , L_6 , V_106 ,
F_54 ( V_75 -> V_107 ) ) ;
F_55 ( V_105 == NULL ) ;
return V_105 ;
}
struct V_1 *
F_56 ( struct V_108 * V_109 )
{
struct V_75 * V_74 = F_34 ( V_109 -> V_7 . V_74 ) ;
struct V_1 * V_105 = NULL ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
int V_106 = 0 ;
int V_38 ;
V_111 = V_109 -> V_7 . V_111 ;
F_57 (state, connector, connector_state, i) {
if ( V_115 -> V_74 != V_109 -> V_7 . V_74 )
continue;
V_105 = F_58 ( V_115 -> V_116 ) ;
V_106 ++ ;
}
F_4 ( V_106 != 1 , L_6 , V_106 ,
F_54 ( V_74 -> V_107 ) ) ;
F_55 ( V_105 == NULL ) ;
return V_105 ;
}
static unsigned F_59 ( int clock )
{
unsigned V_117 ;
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
V_117 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_117 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_117 = 2000 ;
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
V_117 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_117 = 5000 ;
break;
default:
V_117 = 1000 ;
break;
}
return V_117 ;
}
static void F_60 ( T_3 V_118 , unsigned V_117 ,
unsigned V_119 , unsigned V_120 , unsigned V_121 ,
struct V_122 * V_123 )
{
T_3 V_124 , V_125 , V_126 , V_127 , V_128 , V_129 ;
if ( V_123 -> V_121 == 0 ) {
V_123 -> V_121 = V_121 ;
V_123 -> V_120 = V_120 ;
V_123 -> V_119 = V_119 ;
return;
}
V_124 = V_118 * V_117 * V_121 * V_119 ;
V_125 = V_118 * V_117 * V_123 -> V_121 * V_123 -> V_119 ;
V_128 = F_61 ( V_118 * V_121 * V_119 , V_130 * V_120 ) ;
V_129 = F_61 ( V_118 * V_123 -> V_121 * V_123 -> V_119 ,
V_130 * V_123 -> V_120 ) ;
V_126 = 1000000 * V_128 ;
V_127 = 1000000 * V_129 ;
if ( V_124 < V_126 && V_125 < V_127 ) {
if ( V_123 -> V_121 * V_123 -> V_119 * V_128 < V_121 * V_119 * V_129 ) {
V_123 -> V_121 = V_121 ;
V_123 -> V_120 = V_120 ;
V_123 -> V_119 = V_119 ;
}
} else if ( V_124 >= V_126 && V_125 < V_127 ) {
V_123 -> V_121 = V_121 ;
V_123 -> V_120 = V_120 ;
V_123 -> V_119 = V_119 ;
} else if ( V_124 >= V_126 && V_125 >= V_127 ) {
if ( V_120 * V_123 -> V_119 * V_123 -> V_119 > V_123 -> V_120 * V_119 * V_119 ) {
V_123 -> V_121 = V_121 ;
V_123 -> V_120 = V_120 ;
V_123 -> V_119 = V_119 ;
}
}
}
static int F_62 ( struct V_27 * V_28 , int V_71 )
{
int V_131 = V_132 ;
int V_133 , V_121 , V_134 ;
T_1 V_135 ;
V_135 = F_30 ( V_71 ) ;
switch ( V_135 & V_136 ) {
case V_137 :
case V_138 :
V_131 = 135 ;
break;
case V_139 :
V_131 = V_132 ;
break;
default:
F_4 ( 1 , L_7 ) ;
return 0 ;
}
V_134 = V_135 & V_140 ;
V_121 = ( V_135 & V_141 ) >> V_142 ;
V_133 = ( V_135 & V_143 ) >> V_144 ;
return ( V_131 * V_133 * 100 ) / ( V_121 * V_134 ) ;
}
static int F_63 ( struct V_27 * V_28 ,
T_2 V_145 )
{
T_2 V_146 , V_147 ;
T_2 V_148 , V_149 ;
T_2 V_150 , V_151 , V_152 , V_153 ;
V_146 = F_64 ( V_145 ) ;
V_147 = F_65 ( V_145 ) ;
V_148 = F_30 ( V_146 ) ;
V_149 = F_30 ( V_147 ) ;
V_150 = V_149 & V_154 ;
V_152 = V_149 & V_155 ;
if ( V_149 & F_66 ( 1 ) )
V_151 = ( V_149 & V_156 ) >> 8 ;
else
V_151 = 1 ;
switch ( V_150 ) {
case V_157 :
V_150 = 1 ;
break;
case V_158 :
V_150 = 2 ;
break;
case V_159 :
V_150 = 3 ;
break;
case V_160 :
V_150 = 7 ;
break;
}
switch ( V_152 ) {
case V_161 :
V_152 = 5 ;
break;
case V_162 :
V_152 = 2 ;
break;
case V_163 :
V_152 = 3 ;
break;
case V_164 :
V_152 = 1 ;
break;
}
V_153 = ( V_148 & V_165 ) * 24 * 1000 ;
V_153 += ( ( ( V_148 & V_166 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_153 / ( V_150 * V_151 * V_152 * 5 ) ;
}
static void F_67 ( struct V_108 * V_167 )
{
int V_168 ;
if ( V_167 -> V_169 )
V_168 = F_68 ( V_167 -> V_170 ,
& V_167 -> V_171 ) ;
else if ( V_167 -> V_172 )
V_168 = F_68 ( V_167 -> V_170 ,
& V_167 -> V_173 ) ;
else if ( V_167 -> V_174 && V_167 -> V_175 == 36 )
V_168 = V_167 -> V_170 * 2 / 3 ;
else
V_168 = V_167 -> V_170 ;
if ( V_167 -> V_176 )
V_168 /= V_167 -> V_176 ;
V_167 -> V_7 . V_177 . V_178 = V_168 ;
}
static void F_69 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
int V_179 = 0 ;
T_2 V_180 , V_145 ;
V_145 = V_167 -> V_87 ;
V_180 = F_30 ( V_181 ) ;
if ( V_180 & F_70 ( V_145 ) ) {
V_179 = F_63 ( V_28 , V_145 ) ;
} else {
V_179 = V_180 & F_71 ( V_145 ) ;
V_179 >>= F_72 ( V_145 ) ;
switch ( V_179 ) {
case V_182 :
V_179 = 81000 ;
break;
case V_183 :
V_179 = 108000 ;
break;
case V_184 :
V_179 = 135000 ;
break;
case V_185 :
V_179 = 162000 ;
break;
case V_186 :
V_179 = 216000 ;
break;
case V_187 :
V_179 = 270000 ;
break;
default:
F_4 ( 1 , L_8 ) ;
break;
}
V_179 *= 2 ;
}
V_167 -> V_170 = V_179 ;
F_67 ( V_167 ) ;
}
static void F_73 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
int V_179 = 0 ;
T_1 V_188 , V_189 ;
V_188 = V_167 -> V_87 ;
switch ( V_188 & V_190 ) {
case V_191 :
V_179 = 81000 ;
break;
case V_192 :
V_179 = 135000 ;
break;
case V_193 :
V_179 = 270000 ;
break;
case V_194 :
V_179 = F_62 ( V_28 , V_195 ) ;
break;
case V_196 :
V_179 = F_62 ( V_28 , V_197 ) ;
break;
case V_88 :
V_189 = F_30 ( V_198 ) & V_199 ;
if ( V_189 == V_200 )
V_179 = 81000 ;
else if ( V_189 == V_201 )
V_179 = 135000 ;
else if ( V_189 == V_202 )
V_179 = 270000 ;
else {
F_4 ( 1 , L_9 ) ;
return;
}
break;
default:
F_4 ( 1 , L_10 ) ;
return;
}
V_167 -> V_170 = V_179 * 2 ;
F_67 ( V_167 ) ;
}
static int F_74 ( struct V_27 * V_28 ,
enum V_203 V_145 )
{
struct V_204 * V_189 ;
struct V_205 * V_111 ;
T_4 clock ;
if ( F_42 ( V_145 == V_206 ) )
return 0 ;
V_189 = & V_28 -> V_207 [ V_145 ] ;
V_111 = & V_189 -> V_84 . V_208 ;
clock . V_209 = 2 ;
clock . V_210 = ( V_111 -> V_211 & V_212 ) << 22 ;
if ( V_111 -> V_213 & V_214 )
clock . V_210 |= V_111 -> V_215 & V_216 ;
clock . V_133 = ( V_111 -> V_217 & V_218 ) >> V_219 ;
clock . V_151 = ( V_111 -> V_220 & V_221 ) >> V_222 ;
clock . V_152 = ( V_111 -> V_220 & V_223 ) >> V_224 ;
return F_75 ( 100000 , & clock ) ;
}
static void F_76 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
enum V_4 V_4 = F_5 ( V_6 ) ;
T_2 V_145 = V_4 ;
V_167 -> V_170 = F_74 ( V_28 , V_145 ) ;
F_67 ( V_167 ) ;
}
void F_77 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
struct V_20 * V_21 = V_6 -> V_7 . V_21 ;
if ( F_78 ( V_21 ) -> V_225 <= 8 )
F_73 ( V_6 , V_167 ) ;
else if ( F_16 ( V_21 ) )
F_69 ( V_6 , V_167 ) ;
else if ( F_14 ( V_21 ) )
F_76 ( V_6 , V_167 ) ;
}
static void
F_79 ( int clock ,
unsigned * V_226 , unsigned * V_227 , unsigned * V_228 )
{
T_3 V_118 ;
unsigned V_121 , V_120 , V_119 ;
struct V_122 V_123 = { 0 , 0 , 0 } ;
unsigned V_117 ;
V_118 = clock / 100 ;
V_117 = F_59 ( clock ) ;
if ( V_118 == 5400000 ) {
* V_227 = 2 ;
* V_228 = 1 ;
* V_226 = 2 ;
return;
}
for ( V_119 = V_132 * 2 / V_229 + 1 ;
V_119 <= V_132 * 2 / V_230 ;
V_119 ++ ) {
for ( V_120 = V_231 * V_119 / V_132 + 1 ;
V_120 <= V_232 * V_119 / V_132 ;
V_120 ++ ) {
for ( V_121 = V_233 ; V_121 <= V_234 ; V_121 += V_235 )
F_60 ( V_118 , V_117 ,
V_119 , V_120 , V_121 , & V_123 ) ;
}
}
* V_227 = V_123 . V_120 ;
* V_228 = V_123 . V_121 ;
* V_226 = V_123 . V_119 ;
}
static bool
F_80 ( struct V_75 * V_75 ,
struct V_108 * V_109 ,
struct V_1 * V_1 )
{
int clock = V_109 -> V_170 ;
if ( V_1 -> type == V_12 ) {
struct V_204 * V_189 ;
T_2 V_188 ;
unsigned V_121 , V_120 , V_119 ;
F_79 ( clock * 1000 , & V_119 , & V_120 , & V_121 ) ;
V_188 = V_236 | V_139 |
F_81 ( V_119 ) | F_82 ( V_120 ) |
F_83 ( V_121 ) ;
memset ( & V_109 -> V_237 , 0 ,
sizeof( V_109 -> V_237 ) ) ;
V_109 -> V_237 . V_135 = V_188 ;
V_189 = F_84 ( V_75 , V_109 ) ;
if ( V_189 == NULL ) {
F_85 ( L_11 ,
F_54 ( V_75 -> V_107 ) ) ;
return false ;
}
V_109 -> V_87 = F_86 ( V_189 -> V_238 ) ;
} else if ( V_109 -> V_87 == V_88 ) {
struct V_110 * V_111 = V_109 -> V_7 . V_111 ;
struct V_239 * V_240 =
& F_87 ( V_111 ) [ V_241 ] ;
if ( V_240 -> V_242 &&
F_42 ( V_240 -> V_208 . V_240 != V_109 -> V_237 . V_240 ) )
return false ;
V_109 -> V_243 = V_241 ;
V_240 -> V_208 . V_240 = V_109 -> V_237 . V_240 ;
V_240 -> V_242 |= 1 << V_75 -> V_107 ;
}
return true ;
}
static void F_88 ( struct V_244 * V_245 )
{
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
V_245 -> V_246 = V_247 ;
}
static void F_89 ( struct V_244 * V_245 ,
T_3 V_248 ,
T_3 V_153 ,
unsigned int V_249 )
{
T_3 V_250 ;
V_250 = F_90 ( 10000 * F_61 ( V_153 , V_248 ) ,
V_248 ) ;
if ( V_153 >= V_248 ) {
if ( V_250 < V_251 &&
V_250 < V_245 -> V_246 ) {
V_245 -> V_246 = V_250 ;
V_245 -> V_248 = V_248 ;
V_245 -> V_153 = V_153 ;
V_245 -> V_121 = V_249 ;
}
} else if ( V_250 < V_252 &&
V_250 < V_245 -> V_246 ) {
V_245 -> V_246 = V_250 ;
V_245 -> V_248 = V_248 ;
V_245 -> V_153 = V_153 ;
V_245 -> V_121 = V_249 ;
}
}
static void F_91 ( unsigned int V_121 ,
unsigned int * V_150 ,
unsigned int * V_151 ,
unsigned int * V_152 )
{
if ( V_121 % 2 == 0 ) {
unsigned int V_253 = V_121 / 2 ;
if ( V_253 == 1 || V_253 == 2 || V_253 == 3 || V_253 == 5 ) {
* V_150 = 2 ;
* V_151 = 1 ;
* V_152 = V_253 ;
} else if ( V_253 % 2 == 0 ) {
* V_150 = 2 ;
* V_151 = V_253 / 2 ;
* V_152 = 2 ;
} else if ( V_253 % 3 == 0 ) {
* V_150 = 3 ;
* V_151 = V_253 / 3 ;
* V_152 = 2 ;
} else if ( V_253 % 7 == 0 ) {
* V_150 = 7 ;
* V_151 = V_253 / 7 ;
* V_152 = 2 ;
}
} else if ( V_121 == 3 || V_121 == 9 ) {
* V_150 = 3 ;
* V_151 = 1 ;
* V_152 = V_121 / 3 ;
} else if ( V_121 == 5 || V_121 == 7 ) {
* V_150 = V_121 ;
* V_151 = 1 ;
* V_152 = 1 ;
} else if ( V_121 == 15 ) {
* V_150 = 3 ;
* V_151 = 1 ;
* V_152 = 5 ;
} else if ( V_121 == 21 ) {
* V_150 = 7 ;
* V_151 = 1 ;
* V_152 = 3 ;
} else if ( V_121 == 35 ) {
* V_150 = 7 ;
* V_151 = 1 ;
* V_152 = 5 ;
}
}
static void F_92 ( struct V_254 * V_255 ,
T_3 V_256 ,
T_3 V_248 ,
T_2 V_150 , T_2 V_151 , T_2 V_152 )
{
T_3 V_153 ;
switch ( V_248 ) {
case 9600000000ULL :
V_255 -> V_248 = 0 ;
break;
case 9000000000ULL :
V_255 -> V_248 = 1 ;
break;
case 8400000000ULL :
V_255 -> V_248 = 3 ;
}
switch ( V_150 ) {
case 1 :
V_255 -> V_257 = 0 ;
break;
case 2 :
V_255 -> V_257 = 1 ;
break;
case 3 :
V_255 -> V_257 = 2 ;
break;
case 7 :
V_255 -> V_257 = 4 ;
break;
default:
F_4 ( 1 , L_12 ) ;
}
switch ( V_152 ) {
case 5 :
V_255 -> V_258 = 0 ;
break;
case 2 :
V_255 -> V_258 = 1 ;
break;
case 3 :
V_255 -> V_258 = 2 ;
break;
case 1 :
V_255 -> V_258 = 3 ;
break;
default:
F_4 ( 1 , L_13 ) ;
}
V_255 -> V_259 = V_151 ;
V_255 -> V_260 = ( V_255 -> V_259 == 1 ) ? 0 : 1 ;
V_153 = V_150 * V_151 * V_152 * V_256 ;
V_255 -> V_261 = F_93 ( V_153 , 24 * F_94 ( 1 ) ) ;
V_255 -> V_262 =
F_93 ( ( F_93 ( V_153 , 24 ) -
V_255 -> V_261 * F_94 ( 1 ) ) * 0x8000 , F_94 ( 1 ) ) ;
}
static bool
F_95 ( int clock ,
struct V_254 * V_263 )
{
T_3 V_256 = clock * 5 ;
T_3 V_264 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
static const int V_265 [] = { 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 ,
24 , 28 , 30 , 32 , 36 , 40 , 42 , 44 ,
48 , 52 , 54 , 56 , 60 , 64 , 66 , 68 ,
70 , 72 , 76 , 78 , 80 , 84 , 88 , 90 ,
92 , 96 , 98 } ;
static const int V_266 [] = { 3 , 5 , 7 , 9 , 15 , 21 , 35 } ;
static const struct {
const int * V_267 ;
int V_268 ;
} V_269 [] = {
{ V_265 , F_9 (even_dividers) } ,
{ V_266 , F_9 (odd_dividers) } ,
} ;
struct V_244 V_245 ;
unsigned int V_270 , V_127 , V_38 ;
unsigned int V_150 , V_151 , V_152 ;
F_88 ( & V_245 ) ;
for ( V_127 = 0 ; V_127 < F_9 ( V_269 ) ; V_127 ++ ) {
for ( V_270 = 0 ; V_270 < F_9 ( V_264 ) ; V_270 ++ ) {
for ( V_38 = 0 ; V_38 < V_269 [ V_127 ] . V_268 ; V_38 ++ ) {
unsigned int V_121 = V_269 [ V_127 ] . V_267 [ V_38 ] ;
T_3 V_153 = V_121 * V_256 ;
F_89 ( & V_245 ,
V_264 [ V_270 ] ,
V_153 ,
V_121 ) ;
if ( V_245 . V_246 == 0 )
goto V_271;
}
}
V_271:
if ( V_127 == 0 && V_245 . V_121 )
break;
}
if ( ! V_245 . V_121 ) {
F_85 ( L_14 , clock ) ;
return false ;
}
V_150 = V_151 = V_152 = 0 ;
F_91 ( V_245 . V_121 , & V_150 , & V_151 , & V_152 ) ;
F_92 ( V_263 , V_256 , V_245 . V_248 ,
V_150 , V_151 , V_152 ) ;
return true ;
}
static bool
F_96 ( struct V_75 * V_75 ,
struct V_108 * V_109 ,
struct V_1 * V_1 )
{
struct V_204 * V_189 ;
T_2 V_272 , V_273 , V_274 ;
int clock = V_109 -> V_170 ;
V_272 = F_97 ( 0 ) ;
if ( V_1 -> type == V_12 ) {
struct V_254 V_263 = { 0 , } ;
V_272 |= F_70 ( 0 ) ;
if ( ! F_95 ( clock * 1000 , & V_263 ) )
return false ;
V_273 = V_275 |
F_98 ( V_263 . V_262 ) |
V_263 . V_261 ;
V_274 = F_99 ( V_263 . V_259 ) |
F_66 ( V_263 . V_260 ) |
F_100 ( V_263 . V_258 ) |
F_101 ( V_263 . V_257 ) |
V_263 . V_248 ;
} else if ( V_1 -> type == V_10 ) {
switch ( V_109 -> V_170 / 2 ) {
case 81000 :
V_272 |= F_102 ( V_182 , 0 ) ;
break;
case 135000 :
V_272 |= F_102 ( V_184 , 0 ) ;
break;
case 270000 :
V_272 |= F_102 ( V_187 , 0 ) ;
break;
}
V_273 = V_274 = 0 ;
} else
return true ;
memset ( & V_109 -> V_237 , 0 ,
sizeof( V_109 -> V_237 ) ) ;
V_109 -> V_237 . V_272 = V_272 ;
V_109 -> V_237 . V_273 = V_273 ;
V_109 -> V_237 . V_274 = V_274 ;
V_189 = F_84 ( V_75 , V_109 ) ;
if ( V_189 == NULL ) {
F_85 ( L_11 ,
F_54 ( V_75 -> V_107 ) ) ;
return false ;
}
V_109 -> V_87 = V_189 -> V_238 + 1 ;
return true ;
}
static bool
F_103 ( struct V_75 * V_75 ,
struct V_108 * V_109 ,
struct V_1 * V_1 )
{
struct V_204 * V_189 ;
struct V_276 V_277 = { 0 } ;
int V_278 = 0 ;
T_2 V_279 , V_280 , V_281 , V_282 ;
T_2 V_283 ;
int clock = V_109 -> V_170 ;
if ( V_1 -> type == V_12 ) {
T_4 V_284 ;
if ( ! F_104 ( V_109 , clock , & V_284 ) ) {
F_85 ( L_15 ,
clock , F_54 ( V_75 -> V_107 ) ) ;
return false ;
}
V_277 . V_151 = V_284 . V_151 ;
V_277 . V_152 = V_284 . V_152 ;
F_42 ( V_284 . V_209 != 2 ) ;
V_277 . V_133 = V_284 . V_133 ;
V_277 . V_285 = V_284 . V_210 >> 22 ;
V_277 . V_286 = V_284 . V_210 & ( ( 1 << 22 ) - 1 ) ;
V_277 . V_287 = V_277 . V_286 != 0 ;
V_278 = V_284 . V_278 ;
} else if ( V_1 -> type == V_10 ||
V_1 -> type == V_11 ) {
int V_38 ;
V_277 = V_288 [ 0 ] ;
for ( V_38 = 0 ; V_38 < F_9 ( V_288 ) ; ++ V_38 ) {
if ( V_288 [ V_38 ] . clock == clock ) {
V_277 = V_288 [ V_38 ] ;
break;
}
}
V_278 = clock * 10 / 2 * V_277 . V_151 * V_277 . V_152 ;
}
if ( V_278 >= 6200000 && V_278 <= 6700000 ) {
V_279 = 4 ;
V_280 = 9 ;
V_281 = 3 ;
V_282 = 8 ;
} else if ( ( V_278 > 5400000 && V_278 < 6200000 ) ||
( V_278 >= 4800000 && V_278 < 5400000 ) ) {
V_279 = 5 ;
V_280 = 11 ;
V_281 = 3 ;
V_282 = 9 ;
} else if ( V_278 == 5400000 ) {
V_279 = 3 ;
V_280 = 8 ;
V_281 = 1 ;
V_282 = 9 ;
} else {
F_31 ( L_16 ) ;
return false ;
}
memset ( & V_109 -> V_237 , 0 ,
sizeof( V_109 -> V_237 ) ) ;
if ( clock > 270000 )
V_283 = 0x18 ;
else if ( clock > 135000 )
V_283 = 0x0d ;
else if ( clock > 67000 )
V_283 = 0x07 ;
else if ( clock > 33000 )
V_283 = 0x04 ;
else
V_283 = 0x02 ;
V_109 -> V_237 . V_220 =
F_105 ( V_277 . V_151 ) | F_106 ( V_277 . V_152 ) ;
V_109 -> V_237 . V_211 = V_277 . V_285 ;
V_109 -> V_237 . V_217 = F_107 ( V_277 . V_133 ) ;
V_109 -> V_237 . V_215 = V_277 . V_286 ;
if ( V_277 . V_287 )
V_109 -> V_237 . V_213 =
V_214 ;
V_109 -> V_237 . V_289 =
V_279 | F_108 ( V_280 ) ;
V_109 -> V_237 . V_289 |=
F_109 ( V_281 ) ;
V_109 -> V_237 . V_290 = V_282 ;
V_109 -> V_237 . V_291 = 5 << V_292 ;
V_109 -> V_237 . V_293 =
F_110 ( V_294 )
| V_295 ;
V_109 -> V_237 . V_296 = V_297 ;
V_109 -> V_237 . V_298 =
V_299 | V_283 ;
V_189 = F_84 ( V_75 , V_109 ) ;
if ( V_189 == NULL ) {
F_85 ( L_11 ,
F_54 ( V_75 -> V_107 ) ) ;
return false ;
}
V_109 -> V_87 = V_189 -> V_238 ;
return true ;
}
bool F_111 ( struct V_75 * V_75 ,
struct V_108 * V_109 )
{
struct V_20 * V_21 = V_75 -> V_7 . V_21 ;
struct V_1 * V_1 =
F_56 ( V_109 ) ;
if ( F_16 ( V_21 ) )
return F_96 ( V_75 , V_109 ,
V_1 ) ;
else if ( F_14 ( V_21 ) )
return F_103 ( V_75 , V_109 ,
V_1 ) ;
else
return F_80 ( V_75 , V_109 ,
V_1 ) ;
}
void F_112 ( struct V_73 * V_74 )
{
struct V_27 * V_28 = V_74 -> V_21 -> V_29 ;
struct V_75 * V_75 = F_34 ( V_74 ) ;
struct V_1 * V_1 = F_52 ( V_74 ) ;
enum V_300 V_301 = V_75 -> V_84 -> V_301 ;
int type = V_1 -> type ;
T_2 V_76 ;
if ( type == V_10 || type == V_11 || type == V_8 ) {
V_76 = V_302 ;
switch ( V_75 -> V_84 -> V_175 ) {
case 18 :
V_76 |= V_303 ;
break;
case 24 :
V_76 |= V_304 ;
break;
case 30 :
V_76 |= V_305 ;
break;
case 36 :
V_76 |= V_306 ;
break;
default:
F_20 () ;
}
F_21 ( F_113 ( V_301 ) , V_76 ) ;
}
}
void F_114 ( struct V_73 * V_74 , bool V_111 )
{
struct V_75 * V_75 = F_34 ( V_74 ) ;
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_300 V_301 = V_75 -> V_84 -> V_301 ;
T_2 V_76 ;
V_76 = F_30 ( F_115 ( V_301 ) ) ;
if ( V_111 == true )
V_76 |= V_307 ;
else
V_76 &= ~ V_307 ;
F_21 ( F_115 ( V_301 ) , V_76 ) ;
}
void F_116 ( struct V_73 * V_74 )
{
struct V_75 * V_75 = F_34 ( V_74 ) ;
struct V_1 * V_1 = F_52 ( V_74 ) ;
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_107 V_107 = V_75 -> V_107 ;
enum V_300 V_301 = V_75 -> V_84 -> V_301 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_2 V_76 ;
V_76 = V_308 ;
V_76 |= F_117 ( V_4 ) ;
switch ( V_75 -> V_84 -> V_175 ) {
case 18 :
V_76 |= V_309 ;
break;
case 24 :
V_76 |= V_310 ;
break;
case 30 :
V_76 |= V_311 ;
break;
case 36 :
V_76 |= V_312 ;
break;
default:
F_20 () ;
}
if ( V_75 -> V_84 -> V_7 . V_177 . V_313 & V_314 )
V_76 |= V_315 ;
if ( V_75 -> V_84 -> V_7 . V_177 . V_313 & V_316 )
V_76 |= V_317 ;
if ( V_301 == V_318 ) {
switch ( V_107 ) {
case V_78 :
if ( F_18 ( V_21 ) &&
( V_75 -> V_84 -> V_319 . V_320 ||
V_75 -> V_84 -> V_319 . V_321 ) )
V_76 |= V_322 ;
else
V_76 |= V_323 ;
break;
case V_324 :
V_76 |= V_325 ;
break;
case V_326 :
V_76 |= V_327 ;
break;
default:
F_20 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_75 -> V_84 -> V_174 )
V_76 |= V_328 ;
else
V_76 |= V_329 ;
} else if ( type == V_14 ) {
V_76 |= V_330 ;
V_76 |= ( V_75 -> V_84 -> V_85 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_101 * V_101 = F_50 ( V_6 ) ;
if ( V_101 -> V_331 ) {
V_76 |= V_332 ;
} else
V_76 |= V_333 ;
V_76 |= F_51 ( V_75 -> V_84 -> V_104 ) ;
} else if ( type == V_8 ) {
struct V_101 * V_101 = & F_2 ( V_6 ) -> V_9 -> V_334 ;
if ( V_101 -> V_331 ) {
V_76 |= V_332 ;
} else
V_76 |= V_333 ;
V_76 |= F_51 ( V_75 -> V_84 -> V_104 ) ;
} else {
F_4 ( 1 , L_17 ,
V_1 -> type , F_54 ( V_107 ) ) ;
}
F_21 ( F_115 ( V_301 ) , V_76 ) ;
}
void F_118 ( struct V_27 * V_28 ,
enum V_300 V_301 )
{
T_2 V_71 = F_115 ( V_301 ) ;
T_2 V_188 = F_30 ( V_71 ) ;
V_188 &= ~ ( V_308 | V_335 | V_307 ) ;
V_188 |= V_336 ;
F_21 ( V_71 , V_188 ) ;
}
bool F_119 ( struct V_337 * V_337 )
{
struct V_20 * V_21 = V_337 -> V_7 . V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_1 * V_1 = V_337 -> V_6 ;
int type = V_337 -> V_7 . V_338 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_107 V_107 = 0 ;
enum V_300 V_301 ;
enum V_339 V_340 ;
T_2 V_341 ;
V_340 = F_120 ( V_1 ) ;
if ( ! F_121 ( V_28 , V_340 ) )
return false ;
if ( ! V_1 -> V_342 ( V_1 , & V_107 ) )
return false ;
if ( V_4 == V_61 )
V_301 = V_318 ;
else
V_301 = (enum V_300 ) V_107 ;
V_341 = F_30 ( F_115 ( V_301 ) ) ;
switch ( V_341 & V_343 ) {
case V_328 :
case V_329 :
return ( type == V_344 ) ;
case V_333 :
if ( type == V_345 )
return true ;
return ( type == V_346 ) ;
case V_332 :
return false ;
case V_330 :
return ( type == V_347 ) ;
default:
return false ;
}
}
bool F_122 ( struct V_1 * V_6 ,
enum V_107 * V_107 )
{
struct V_20 * V_21 = V_6 -> V_7 . V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_4 V_4 = F_5 ( V_6 ) ;
enum V_339 V_340 ;
T_1 V_341 ;
int V_38 ;
V_340 = F_120 ( V_6 ) ;
if ( ! F_121 ( V_28 , V_340 ) )
return false ;
V_341 = F_30 ( F_28 ( V_4 ) ) ;
if ( ! ( V_341 & V_93 ) )
return false ;
if ( V_4 == V_61 ) {
V_341 = F_30 ( F_115 ( V_318 ) ) ;
switch ( V_341 & V_348 ) {
case V_323 :
case V_322 :
* V_107 = V_78 ;
break;
case V_325 :
* V_107 = V_324 ;
break;
case V_327 :
* V_107 = V_326 ;
break;
}
return true ;
} else {
for ( V_38 = V_349 ; V_38 <= V_350 ; V_38 ++ ) {
V_341 = F_30 ( F_115 ( V_38 ) ) ;
if ( ( V_341 & V_335 )
== F_117 ( V_4 ) ) {
if ( ( V_341 & V_343 ) == V_332 )
return false ;
* V_107 = V_38 ;
return true ;
}
}
}
F_48 ( L_18 , F_32 ( V_4 ) ) ;
return false ;
}
void F_123 ( struct V_75 * V_75 )
{
struct V_73 * V_74 = & V_75 -> V_7 ;
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_1 * V_1 = F_52 ( V_74 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_300 V_301 = V_75 -> V_84 -> V_301 ;
if ( V_301 != V_318 )
F_21 ( F_124 ( V_301 ) ,
F_125 ( V_4 ) ) ;
}
void F_126 ( struct V_75 * V_75 )
{
struct V_27 * V_28 = V_75 -> V_7 . V_21 -> V_29 ;
enum V_300 V_301 = V_75 -> V_84 -> V_301 ;
if ( V_301 != V_318 )
F_21 ( F_124 ( V_301 ) ,
V_351 ) ;
}
static void F_127 ( struct V_20 * V_21 , T_1 V_352 ,
enum V_4 V_4 , int type )
{
struct V_27 * V_28 = V_21 -> V_29 ;
const struct V_19 * V_23 ;
T_5 V_353 ;
T_5 V_354 , V_355 ;
int V_22 ;
T_1 V_71 ;
V_354 = V_28 -> V_45 . V_46 [ V_4 ] . V_53 ;
V_355 = V_28 -> V_45 . V_46 [ V_4 ] . V_52 ;
if ( type == V_10 ) {
if ( V_354 ) {
V_353 = V_354 ;
} else {
V_23 = F_7 ( V_21 , & V_22 ) ;
V_353 = V_23 [ V_4 ] . V_356 ;
}
} else if ( type == V_11 ) {
if ( V_354 ) {
V_353 = V_354 ;
} else {
V_23 = F_11 ( V_21 , & V_22 ) ;
V_353 = V_23 [ V_4 ] . V_356 ;
}
} else if ( type == V_12 ) {
if ( V_355 ) {
V_353 = V_355 ;
} else {
V_23 = F_12 ( V_21 , & V_22 ) ;
V_353 = V_23 [ V_4 ] . V_356 ;
}
} else {
return;
}
if ( V_353 && V_353 != 0x1 && V_353 != 0x3 && V_353 != 0x7 ) {
F_31 ( L_19 , V_353 ) ;
return;
}
V_71 = F_30 ( V_357 ) ;
V_71 &= ~ F_128 ( V_4 ) ;
V_71 &= ~ ( 1 << ( V_358 + V_4 ) ) ;
if ( V_353 )
V_71 |= V_353 << F_129 ( V_4 ) ;
else
V_71 |= 1 << ( V_358 + V_4 ) ;
F_21 ( V_357 , V_71 ) ;
}
static void F_15 ( struct V_20 * V_21 , T_1 V_352 ,
enum V_4 V_4 , int type )
{
struct V_27 * V_28 = V_21 -> V_29 ;
const struct V_359 * V_23 ;
T_1 V_22 , V_38 ;
T_2 V_188 ;
if ( type == V_11 && V_28 -> V_30 ) {
V_22 = F_9 ( V_360 ) ;
V_23 = V_360 ;
} else if ( type == V_10
|| type == V_11 ) {
V_22 = F_9 ( V_361 ) ;
V_23 = V_361 ;
} else if ( type == V_12 ) {
V_22 = F_9 ( V_362 ) ;
V_23 = V_362 ;
} else {
F_48 ( L_20 ,
type ) ;
return;
}
if ( V_352 >= V_22 ||
( type == V_12 && V_352 == V_67 ) ) {
for ( V_38 = 0 ; V_38 < V_22 ; V_38 ++ ) {
if ( V_23 [ V_38 ] . V_363 ) {
V_352 = V_38 ;
break;
}
}
}
V_188 = F_30 ( F_130 ( V_4 ) ) ;
V_188 &= ~ ( V_364 | V_365 ) ;
F_21 ( F_131 ( V_4 ) , V_188 ) ;
V_188 = F_30 ( F_132 ( V_4 ) ) ;
V_188 &= ~ ( V_366 | V_367 ) ;
V_188 |= V_23 [ V_352 ] . V_368 << V_369 |
V_23 [ V_352 ] . V_370 << V_371 ;
F_21 ( F_133 ( V_4 ) , V_188 ) ;
V_188 = F_30 ( F_134 ( V_4 ) ) ;
V_188 &= ~ V_372 ;
if ( V_23 [ V_352 ] . V_373 )
V_188 |= V_372 ;
if ( ( V_188 & V_374 ) && ! ( V_188 & V_372 ) )
F_31 ( L_21 ) ;
F_21 ( F_135 ( V_4 ) , V_188 ) ;
V_188 = F_30 ( F_136 ( V_4 ) ) ;
V_188 &= ~ V_375 ;
V_188 |= V_23 [ V_352 ] . V_376 << V_377 ;
F_21 ( F_137 ( V_4 ) , V_188 ) ;
V_188 = F_30 ( F_130 ( V_4 ) ) ;
V_188 |= V_364 | V_365 ;
F_21 ( F_131 ( V_4 ) , V_188 ) ;
}
static T_2 F_138 ( int V_378 )
{
T_2 V_352 ;
switch ( V_378 ) {
default:
F_48 ( L_22 ,
V_378 ) ;
case V_379 | V_380 :
V_352 = 0 ;
break;
case V_379 | V_381 :
V_352 = 1 ;
break;
case V_379 | V_382 :
V_352 = 2 ;
break;
case V_379 | V_383 :
V_352 = 3 ;
break;
case V_384 | V_380 :
V_352 = 4 ;
break;
case V_384 | V_381 :
V_352 = 5 ;
break;
case V_384 | V_382 :
V_352 = 6 ;
break;
case V_385 | V_380 :
V_352 = 7 ;
break;
case V_385 | V_381 :
V_352 = 8 ;
break;
case V_386 | V_380 :
V_352 = 9 ;
break;
}
return V_352 ;
}
T_2 F_139 ( struct V_101 * V_101 )
{
struct V_2 * V_387 = F_140 ( V_101 ) ;
struct V_20 * V_21 = V_387 -> V_7 . V_7 . V_21 ;
struct V_1 * V_6 = & V_387 -> V_7 ;
T_5 V_388 = V_101 -> V_388 [ 0 ] ;
int V_378 = V_388 & ( V_389 |
V_390 ) ;
enum V_4 V_4 = V_387 -> V_4 ;
T_2 V_352 ;
V_352 = F_138 ( V_378 ) ;
if ( F_16 ( V_21 ) )
F_127 ( V_21 , V_352 , V_4 , V_6 -> type ) ;
else if ( F_14 ( V_21 ) )
F_15 ( V_21 , V_352 , V_4 , V_6 -> type ) ;
return F_44 ( V_352 ) ;
}
static void F_141 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_75 * V_74 = F_34 ( V_6 -> V_74 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
int V_44 ;
if ( type == V_11 ) {
struct V_101 * V_101 = F_50 ( V_6 ) ;
F_142 ( V_101 ) ;
}
if ( F_16 ( V_21 ) ) {
T_2 V_145 = V_74 -> V_84 -> V_87 ;
T_2 V_188 ;
if ( type == V_11 ) {
F_42 ( V_145 != V_391 ) ;
V_188 = F_30 ( V_181 ) ;
V_188 &= ~ ( F_70 ( V_145 ) |
F_143 ( V_145 ) |
F_71 ( V_145 ) ) ;
V_188 |= V_74 -> V_84 -> V_237 . V_272 << ( V_145 * 6 ) ;
F_21 ( V_181 , V_188 ) ;
F_40 ( V_181 ) ;
}
V_188 = F_30 ( V_392 ) ;
V_188 &= ~ ( F_144 ( V_4 ) |
F_145 ( V_4 ) ) ;
V_188 |= ( F_146 ( V_145 , V_4 ) |
F_147 ( V_4 ) ) ;
F_21 ( V_392 , V_188 ) ;
} else if ( F_78 ( V_21 ) -> V_225 < 9 ) {
F_42 ( V_74 -> V_84 -> V_87 == V_393 ) ;
F_21 ( F_41 ( V_4 ) , V_74 -> V_84 -> V_87 ) ;
}
if ( type == V_10 || type == V_11 ) {
struct V_101 * V_101 = F_50 ( V_6 ) ;
F_148 ( V_101 , V_74 -> V_84 ) ;
F_49 ( V_1 ) ;
F_149 ( V_101 , V_394 ) ;
F_150 ( V_101 ) ;
if ( V_4 != V_61 || F_78 ( V_21 ) -> V_225 >= 9 )
F_151 ( V_101 ) ;
} else if ( type == V_12 ) {
struct V_395 * V_395 = F_152 ( V_6 ) ;
if ( F_14 ( V_21 ) ) {
V_44 = V_28 -> V_45 .
V_46 [ V_4 ] . V_47 ;
F_15 ( V_21 , V_44 , V_4 ,
V_12 ) ;
}
V_395 -> V_396 ( V_6 ,
V_74 -> V_84 -> V_174 ,
& V_74 -> V_84 -> V_7 . V_177 ) ;
}
}
static void F_153 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_2 V_188 ;
bool V_397 = false ;
V_188 = F_30 ( F_28 ( V_4 ) ) ;
if ( V_188 & V_93 ) {
V_188 &= ~ V_93 ;
F_21 ( F_28 ( V_4 ) , V_188 ) ;
V_397 = true ;
}
V_188 = F_30 ( F_43 ( V_4 ) ) ;
V_188 &= ~ ( V_92 | V_100 ) ;
V_188 |= V_91 ;
F_21 ( F_43 ( V_4 ) , V_188 ) ;
if ( V_397 )
F_27 ( V_28 , V_4 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_101 * V_101 = F_50 ( V_6 ) ;
F_149 ( V_101 , V_398 ) ;
F_154 ( V_101 ) ;
F_155 ( V_101 ) ;
}
if ( F_16 ( V_21 ) )
F_21 ( V_392 , ( F_30 ( V_392 ) |
F_144 ( V_4 ) ) ) ;
else if ( F_78 ( V_21 ) -> V_225 < 9 )
F_21 ( F_41 ( V_4 ) , V_393 ) ;
}
static void F_156 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_73 * V_74 = V_6 -> V_74 ;
struct V_75 * V_75 = F_34 ( V_74 ) ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
if ( type == V_12 ) {
struct V_2 * V_16 =
F_3 ( V_6 ) ;
F_21 ( F_28 ( V_4 ) ,
V_16 -> V_103 |
V_93 ) ;
} else if ( type == V_11 ) {
struct V_101 * V_101 = F_50 ( V_6 ) ;
if ( V_4 == V_61 && F_78 ( V_21 ) -> V_225 < 9 )
F_151 ( V_101 ) ;
F_157 ( V_101 ) ;
F_158 ( V_101 ) ;
F_159 ( V_101 ) ;
}
if ( V_75 -> V_84 -> V_399 ) {
F_160 ( V_28 , V_400 ) ;
F_161 ( V_1 ) ;
}
}
static void F_162 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_73 * V_74 = V_6 -> V_74 ;
struct V_75 * V_75 = F_34 ( V_74 ) ;
int type = V_1 -> type ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
if ( V_75 -> V_84 -> V_399 ) {
F_163 ( V_1 ) ;
F_164 ( V_28 , V_400 ) ;
}
if ( type == V_11 ) {
struct V_101 * V_101 = F_50 ( V_6 ) ;
F_165 ( V_101 ) ;
F_166 ( V_101 ) ;
F_167 ( V_101 ) ;
}
}
static void F_168 ( struct V_27 * V_28 ,
struct V_204 * V_189 )
{
F_21 ( F_169 ( V_189 -> V_238 ) , V_189 -> V_84 . V_208 . V_135 ) ;
F_40 ( F_169 ( V_189 -> V_238 ) ) ;
F_29 ( 20 ) ;
}
static void F_170 ( struct V_27 * V_28 ,
struct V_204 * V_189 )
{
F_21 ( V_198 , V_189 -> V_84 . V_208 . V_240 ) ;
F_40 ( V_198 ) ;
F_29 ( 20 ) ;
}
static void F_171 ( struct V_27 * V_28 ,
struct V_204 * V_189 )
{
T_2 V_188 ;
V_188 = F_30 ( F_169 ( V_189 -> V_238 ) ) ;
F_21 ( F_169 ( V_189 -> V_238 ) , V_188 & ~ V_236 ) ;
F_40 ( F_169 ( V_189 -> V_238 ) ) ;
}
static void F_172 ( struct V_27 * V_28 ,
struct V_204 * V_189 )
{
T_2 V_188 ;
V_188 = F_30 ( V_198 ) ;
F_21 ( V_198 , V_188 & ~ V_401 ) ;
F_40 ( V_198 ) ;
}
static bool F_173 ( struct V_27 * V_28 ,
struct V_204 * V_189 ,
struct V_205 * V_208 )
{
T_2 V_188 ;
if ( ! F_121 ( V_28 , V_402 ) )
return false ;
V_188 = F_30 ( F_169 ( V_189 -> V_238 ) ) ;
V_208 -> V_135 = V_188 ;
return V_188 & V_236 ;
}
static bool F_174 ( struct V_27 * V_28 ,
struct V_204 * V_189 ,
struct V_205 * V_208 )
{
T_2 V_188 ;
if ( ! F_121 ( V_28 , V_402 ) )
return false ;
V_188 = F_30 ( V_198 ) ;
V_208 -> V_240 = V_188 ;
return V_188 & V_401 ;
}
static void F_175 ( struct V_27 * V_28 )
{
int V_38 ;
V_28 -> V_403 = 3 ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
V_28 -> V_207 [ V_38 ] . V_238 = V_38 ;
V_28 -> V_207 [ V_38 ] . V_404 = V_405 [ V_38 ] ;
V_28 -> V_207 [ V_38 ] . V_406 = F_171 ;
V_28 -> V_207 [ V_38 ] . V_373 = F_168 ;
V_28 -> V_207 [ V_38 ] . V_342 =
F_173 ;
}
V_28 -> V_207 [ V_38 ] . V_238 = V_38 ;
V_28 -> V_207 [ V_38 ] . V_404 = V_405 [ V_38 ] ;
V_28 -> V_207 [ V_38 ] . V_406 = F_172 ;
V_28 -> V_207 [ V_38 ] . V_373 = F_170 ;
V_28 -> V_207 [ V_38 ] . V_342 = F_174 ;
}
static void F_176 ( struct V_27 * V_28 ,
struct V_204 * V_189 )
{
T_2 V_188 ;
unsigned int V_145 ;
const struct V_407 * V_408 = V_407 ;
V_145 = V_189 -> V_238 + 1 ;
V_188 = F_30 ( V_181 ) ;
V_188 &= ~ ( F_70 ( V_145 ) | F_143 ( V_145 ) |
F_71 ( V_145 ) ) ;
V_188 |= V_189 -> V_84 . V_208 . V_272 << ( V_145 * 6 ) ;
F_21 ( V_181 , V_188 ) ;
F_40 ( V_181 ) ;
F_21 ( V_408 [ V_189 -> V_238 ] . V_273 , V_189 -> V_84 . V_208 . V_273 ) ;
F_21 ( V_408 [ V_189 -> V_238 ] . V_274 , V_189 -> V_84 . V_208 . V_274 ) ;
F_40 ( V_408 [ V_189 -> V_238 ] . V_273 ) ;
F_40 ( V_408 [ V_189 -> V_238 ] . V_274 ) ;
F_21 ( V_408 [ V_189 -> V_238 ] . V_409 ,
F_30 ( V_408 [ V_189 -> V_238 ] . V_409 ) | V_410 ) ;
if ( F_177 ( F_30 ( V_411 ) & F_178 ( V_145 ) , 5 ) )
F_31 ( L_23 , V_145 ) ;
}
static void F_179 ( struct V_27 * V_28 ,
struct V_204 * V_189 )
{
const struct V_407 * V_408 = V_407 ;
F_21 ( V_408 [ V_189 -> V_238 ] . V_409 ,
F_30 ( V_408 [ V_189 -> V_238 ] . V_409 ) & ~ V_410 ) ;
F_40 ( V_408 [ V_189 -> V_238 ] . V_409 ) ;
}
static bool F_180 ( struct V_27 * V_28 ,
struct V_204 * V_189 ,
struct V_205 * V_208 )
{
T_2 V_188 ;
unsigned int V_145 ;
const struct V_407 * V_408 = V_407 ;
if ( ! F_121 ( V_28 , V_402 ) )
return false ;
V_145 = V_189 -> V_238 + 1 ;
V_188 = F_30 ( V_408 [ V_189 -> V_238 ] . V_409 ) ;
if ( ! ( V_188 & V_410 ) )
return false ;
V_188 = F_30 ( V_181 ) ;
V_208 -> V_272 = ( V_188 >> ( V_145 * 6 ) ) & 0x3f ;
if ( V_188 & F_70 ( V_145 ) ) {
V_208 -> V_273 = F_30 ( V_408 [ V_189 -> V_238 ] . V_273 ) ;
V_208 -> V_274 = F_30 ( V_408 [ V_189 -> V_238 ] . V_274 ) ;
}
return true ;
}
static void F_181 ( struct V_27 * V_28 )
{
int V_38 ;
V_28 -> V_403 = 3 ;
for ( V_38 = 0 ; V_38 < V_28 -> V_403 ; V_38 ++ ) {
V_28 -> V_207 [ V_38 ] . V_238 = V_38 ;
V_28 -> V_207 [ V_38 ] . V_404 = V_412 [ V_38 ] ;
V_28 -> V_207 [ V_38 ] . V_406 = F_179 ;
V_28 -> V_207 [ V_38 ] . V_373 = F_176 ;
V_28 -> V_207 [ V_38 ] . V_342 =
F_180 ;
}
}
static void F_182 ( struct V_27 * V_28 ,
enum V_413 V_414 )
{
enum V_4 V_4 ;
T_2 V_188 ;
V_188 = F_30 ( V_415 ) ;
V_188 |= F_183 ( V_414 ) ;
F_21 ( V_415 , V_188 ) ;
if ( F_177 ( F_30 ( F_184 ( V_414 ) ) & V_416 , 10 ) )
F_31 ( L_24 , V_414 ) ;
for ( V_4 = ( V_414 == V_417 ? V_62 : V_61 ) ;
V_4 <= ( V_414 == V_417 ? V_63 : V_61 ) ; V_4 ++ ) {
int V_418 ;
for ( V_418 = 0 ; V_418 < 4 ; V_418 ++ ) {
V_188 = F_30 ( F_185 ( V_4 , V_418 ) ) ;
V_188 &= ~ V_419 ;
if ( V_418 != 1 )
V_188 |= V_419 ;
F_21 ( F_185 ( V_4 , V_418 ) , V_188 ) ;
}
}
V_188 = F_30 ( F_186 ( V_414 ) ) ;
V_188 &= ~ V_420 ;
V_188 |= 0xE4 << V_421 ;
F_21 ( F_186 ( V_414 ) , V_188 ) ;
V_188 = F_30 ( F_187 ( V_414 ) ) ;
V_188 &= ~ V_422 ;
V_188 |= 0xE4 << V_423 ;
F_21 ( F_187 ( V_414 ) , V_188 ) ;
V_188 = F_30 ( F_188 ( V_414 ) ) ;
V_188 |= V_424 | V_425 |
V_426 ;
F_21 ( F_188 ( V_414 ) , V_188 ) ;
if ( V_414 == V_417 ) {
V_188 = F_30 ( V_427 ) ;
V_188 |= V_428 ;
F_21 ( V_427 , V_188 ) ;
}
V_188 = F_30 ( F_189 ( V_414 ) ) ;
V_188 &= ~ V_429 ;
if ( V_414 == V_430 )
V_188 |= V_429 ;
F_21 ( F_189 ( V_414 ) , V_188 ) ;
if ( V_414 == V_417 ) {
T_2 V_431 ;
if ( F_177 ( F_30 ( F_190 ( V_430 ) ) & V_432 ,
10 ) )
F_31 ( L_25 ) ;
V_188 = F_30 ( F_191 ( V_430 ) ) ;
V_188 = ( V_188 & V_433 ) >> V_434 ;
V_431 = V_188 << V_435 |
V_188 << V_436 |
V_188 ;
F_21 ( F_191 ( V_417 ) , V_431 ) ;
V_188 = F_30 ( F_192 ( V_417 ) ) ;
V_188 |= V_437 | V_438 ;
F_21 ( F_192 ( V_417 ) , V_188 ) ;
}
V_188 = F_30 ( F_193 ( V_414 ) ) ;
V_188 |= V_439 ;
F_21 ( F_193 ( V_414 ) , V_188 ) ;
}
void F_194 ( struct V_20 * V_21 )
{
F_182 ( V_21 -> V_29 , V_430 ) ;
F_182 ( V_21 -> V_29 , V_417 ) ;
}
static void F_195 ( struct V_27 * V_28 ,
enum V_413 V_414 )
{
T_2 V_188 ;
V_188 = F_30 ( F_193 ( V_414 ) ) ;
V_188 &= ~ V_439 ;
F_21 ( F_193 ( V_414 ) , V_188 ) ;
}
void F_196 ( struct V_20 * V_21 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
F_195 ( V_28 , V_430 ) ;
F_195 ( V_28 , V_417 ) ;
F_21 ( V_415 , 0 ) ;
}
static void F_197 ( struct V_27 * V_28 ,
struct V_204 * V_189 )
{
T_2 V_76 ;
enum V_4 V_4 = (enum V_4 ) V_189 -> V_238 ;
V_76 = F_30 ( F_198 ( V_4 ) ) ;
V_76 &= ~ V_440 ;
F_21 ( F_198 ( V_4 ) , V_76 ) ;
V_76 = F_30 ( F_199 ( V_4 ) ) ;
V_76 &= ~ V_297 ;
F_21 ( F_199 ( V_4 ) , V_76 ) ;
V_76 = F_30 ( F_200 ( V_4 ) ) ;
V_76 &= ~ ( V_221 | V_223 ) ;
V_76 |= V_189 -> V_84 . V_208 . V_220 ;
F_21 ( F_200 ( V_4 ) , V_76 ) ;
V_76 = F_30 ( F_201 ( V_4 , 0 ) ) ;
V_76 &= ~ V_212 ;
V_76 |= V_189 -> V_84 . V_208 . V_211 ;
F_21 ( F_201 ( V_4 , 0 ) , V_76 ) ;
V_76 = F_30 ( F_201 ( V_4 , 1 ) ) ;
V_76 &= ~ V_218 ;
V_76 |= V_189 -> V_84 . V_208 . V_217 ;
F_21 ( F_201 ( V_4 , 1 ) , V_76 ) ;
V_76 = F_30 ( F_201 ( V_4 , 2 ) ) ;
V_76 &= ~ V_216 ;
V_76 |= V_189 -> V_84 . V_208 . V_215 ;
F_21 ( F_201 ( V_4 , 2 ) , V_76 ) ;
V_76 = F_30 ( F_201 ( V_4 , 3 ) ) ;
V_76 &= ~ V_214 ;
V_76 |= V_189 -> V_84 . V_208 . V_213 ;
F_21 ( F_201 ( V_4 , 3 ) , V_76 ) ;
V_76 = F_30 ( F_201 ( V_4 , 6 ) ) ;
V_76 &= ~ V_441 ;
V_76 &= ~ V_442 ;
V_76 &= ~ V_443 ;
V_76 |= V_189 -> V_84 . V_208 . V_289 ;
F_21 ( F_201 ( V_4 , 6 ) , V_76 ) ;
V_76 = F_30 ( F_201 ( V_4 , 8 ) ) ;
V_76 &= ~ V_444 ;
V_76 |= V_189 -> V_84 . V_208 . V_290 ;
F_21 ( F_201 ( V_4 , 8 ) , V_76 ) ;
V_76 = F_30 ( F_201 ( V_4 , 9 ) ) ;
V_76 &= ~ V_445 ;
V_76 |= V_189 -> V_84 . V_208 . V_291 ;
F_21 ( F_201 ( V_4 , 9 ) , V_76 ) ;
V_76 = F_30 ( F_201 ( V_4 , 10 ) ) ;
V_76 &= ~ V_295 ;
V_76 &= ~ V_446 ;
V_76 |= V_189 -> V_84 . V_208 . V_293 ;
F_21 ( F_201 ( V_4 , 10 ) , V_76 ) ;
V_76 = F_30 ( F_199 ( V_4 ) ) ;
V_76 |= V_447 ;
F_21 ( F_199 ( V_4 ) , V_76 ) ;
V_76 &= ~ V_297 ;
V_76 |= V_189 -> V_84 . V_208 . V_296 ;
F_21 ( F_199 ( V_4 ) , V_76 ) ;
V_76 = F_30 ( F_198 ( V_4 ) ) ;
V_76 |= V_448 ;
F_21 ( F_198 ( V_4 ) , V_76 ) ;
F_40 ( F_198 ( V_4 ) ) ;
if ( F_202 ( ( F_30 ( F_198 ( V_4 ) ) &
V_449 ) , 200 ) )
F_31 ( L_26 , V_4 ) ;
V_76 = F_30 ( F_203 ( V_4 ) ) ;
V_76 &= ~ V_450 ;
V_76 &= ~ V_299 ;
V_76 |= V_189 -> V_84 . V_208 . V_298 ;
F_21 ( F_204 ( V_4 ) , V_76 ) ;
}
static void F_205 ( struct V_27 * V_28 ,
struct V_204 * V_189 )
{
enum V_4 V_4 = (enum V_4 ) V_189 -> V_238 ;
T_2 V_76 ;
V_76 = F_30 ( F_198 ( V_4 ) ) ;
V_76 &= ~ V_448 ;
F_21 ( F_198 ( V_4 ) , V_76 ) ;
F_40 ( F_198 ( V_4 ) ) ;
}
static bool F_206 ( struct V_27 * V_28 ,
struct V_204 * V_189 ,
struct V_205 * V_208 )
{
enum V_4 V_4 = (enum V_4 ) V_189 -> V_238 ;
T_2 V_188 ;
if ( ! F_121 ( V_28 , V_402 ) )
return false ;
V_188 = F_30 ( F_198 ( V_4 ) ) ;
if ( ! ( V_188 & V_448 ) )
return false ;
V_208 -> V_220 = F_30 ( F_200 ( V_4 ) ) ;
V_208 -> V_220 &= V_221 | V_223 ;
V_208 -> V_296 = F_30 ( F_199 ( V_4 ) ) ;
V_208 -> V_296 &= V_297 ;
V_208 -> V_211 = F_30 ( F_201 ( V_4 , 0 ) ) ;
V_208 -> V_211 &= V_212 ;
V_208 -> V_217 = F_30 ( F_201 ( V_4 , 1 ) ) ;
V_208 -> V_217 &= V_218 ;
V_208 -> V_215 = F_30 ( F_201 ( V_4 , 2 ) ) ;
V_208 -> V_215 &= V_216 ;
V_208 -> V_213 = F_30 ( F_201 ( V_4 , 3 ) ) ;
V_208 -> V_213 &= V_214 ;
V_208 -> V_289 = F_30 ( F_201 ( V_4 , 6 ) ) ;
V_208 -> V_289 &= V_441 |
V_442 |
V_443 ;
V_208 -> V_290 = F_30 ( F_201 ( V_4 , 8 ) ) ;
V_208 -> V_290 &= V_444 ;
V_208 -> V_291 = F_30 ( F_201 ( V_4 , 9 ) ) ;
V_208 -> V_291 &= V_445 ;
V_208 -> V_293 = F_30 ( F_201 ( V_4 , 10 ) ) ;
V_208 -> V_293 &= V_295 |
V_446 ;
V_208 -> V_298 = F_30 ( F_203 ( V_4 ) ) ;
if ( F_30 ( F_207 ( V_4 ) ) != V_208 -> V_298 )
F_85 ( L_27 ,
V_208 -> V_298 ,
F_30 ( F_207 ( V_4 ) ) ) ;
V_208 -> V_298 &= V_450 | V_299 ;
return true ;
}
static void F_208 ( struct V_27 * V_28 )
{
int V_38 ;
V_28 -> V_403 = 3 ;
for ( V_38 = 0 ; V_38 < V_28 -> V_403 ; V_38 ++ ) {
V_28 -> V_207 [ V_38 ] . V_238 = V_38 ;
V_28 -> V_207 [ V_38 ] . V_404 = V_451 [ V_38 ] ;
V_28 -> V_207 [ V_38 ] . V_406 = F_205 ;
V_28 -> V_207 [ V_38 ] . V_373 = F_197 ;
V_28 -> V_207 [ V_38 ] . V_342 =
F_206 ;
}
}
void F_209 ( struct V_20 * V_21 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
T_2 V_188 = F_30 ( V_452 ) ;
if ( F_16 ( V_21 ) )
F_181 ( V_28 ) ;
else if ( F_14 ( V_21 ) )
F_208 ( V_28 ) ;
else
F_175 ( V_28 ) ;
if ( F_16 ( V_21 ) ) {
int V_453 ;
V_453 = V_28 -> V_454 . V_455 ( V_21 ) ;
V_28 -> V_456 = V_453 ;
if ( ! ( F_30 ( V_457 ) & V_410 ) )
F_31 ( L_28 ) ;
else
F_160 ( V_28 , V_402 ) ;
} else if ( F_14 ( V_21 ) ) {
F_210 ( V_21 ) ;
F_194 ( V_21 ) ;
} else {
if ( V_188 & V_458 )
F_31 ( L_29 ) ;
if ( V_188 & V_459 )
F_31 ( L_30 ) ;
}
}
void F_211 ( struct V_5 * V_6 )
{
struct V_2 * V_16 = F_3 ( V_6 ) ;
struct V_101 * V_101 = & V_16 -> V_334 ;
struct V_27 * V_28 = V_6 -> V_21 -> V_29 ;
enum V_4 V_4 = V_16 -> V_4 ;
T_2 V_188 ;
bool V_397 = false ;
if ( F_30 ( F_43 ( V_4 ) ) & V_92 ) {
V_188 = F_30 ( F_28 ( V_4 ) ) ;
if ( V_188 & V_93 ) {
V_188 &= ~ V_93 ;
F_21 ( F_28 ( V_4 ) , V_188 ) ;
V_397 = true ;
}
V_188 = F_30 ( F_43 ( V_4 ) ) ;
V_188 &= ~ ( V_92 | V_100 ) ;
V_188 |= V_91 ;
F_21 ( F_43 ( V_4 ) , V_188 ) ;
F_40 ( F_43 ( V_4 ) ) ;
if ( V_397 )
F_27 ( V_28 , V_4 ) ;
}
V_188 = V_92 |
V_91 | V_460 ;
if ( V_101 -> V_331 )
V_188 |= V_461 ;
else {
V_188 |= V_462 ;
if ( F_212 ( V_101 -> V_463 ) )
V_188 |= V_90 ;
}
F_21 ( F_43 ( V_4 ) , V_188 ) ;
F_40 ( F_43 ( V_4 ) ) ;
V_101 -> V_102 |= V_93 ;
F_21 ( F_28 ( V_4 ) , V_101 -> V_102 ) ;
F_40 ( F_28 ( V_4 ) ) ;
F_29 ( 600 ) ;
}
void F_213 ( struct V_73 * V_74 )
{
struct V_27 * V_28 = V_74 -> V_21 -> V_29 ;
struct V_1 * V_1 = F_52 ( V_74 ) ;
T_2 V_188 ;
F_153 ( V_1 ) ;
V_188 = F_30 ( F_39 ( V_78 ) ) ;
V_188 &= ~ V_94 ;
F_21 ( F_39 ( V_78 ) , V_188 ) ;
V_188 = F_30 ( F_35 ( V_78 ) ) ;
V_188 &= ~ ( V_96 | V_97 ) ;
V_188 |= F_36 ( 2 ) | F_37 ( 2 ) ;
F_21 ( F_35 ( V_78 ) , V_188 ) ;
V_188 = F_30 ( F_39 ( V_78 ) ) ;
V_188 &= ~ V_86 ;
F_21 ( F_39 ( V_78 ) , V_188 ) ;
V_188 = F_30 ( F_39 ( V_78 ) ) ;
V_188 &= ~ V_83 ;
F_21 ( F_39 ( V_78 ) , V_188 ) ;
}
void F_214 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
struct V_75 * V_75 = F_34 ( V_6 -> V_7 . V_74 ) ;
enum V_300 V_301 = V_167 -> V_301 ;
struct V_395 * V_395 ;
T_1 V_76 , V_313 = 0 ;
V_76 = F_30 ( F_115 ( V_301 ) ) ;
if ( V_76 & V_317 )
V_313 |= V_316 ;
else
V_313 |= V_464 ;
if ( V_76 & V_315 )
V_313 |= V_314 ;
else
V_313 |= V_465 ;
V_167 -> V_7 . V_177 . V_313 |= V_313 ;
switch ( V_76 & V_466 ) {
case V_309 :
V_167 -> V_175 = 18 ;
break;
case V_310 :
V_167 -> V_175 = 24 ;
break;
case V_311 :
V_167 -> V_175 = 30 ;
break;
case V_312 :
V_167 -> V_175 = 36 ;
break;
default:
break;
}
switch ( V_76 & V_343 ) {
case V_328 :
V_167 -> V_174 = true ;
V_395 = F_152 ( & V_6 -> V_7 ) ;
if ( V_395 -> V_467 ( & V_6 -> V_7 ) )
V_167 -> V_468 = true ;
break;
case V_329 :
case V_330 :
break;
case V_333 :
case V_332 :
V_167 -> V_172 = true ;
V_167 -> V_104 =
( ( V_76 & V_469 ) >> V_470 ) + 1 ;
F_215 ( V_75 , V_167 ) ;
break;
default:
break;
}
if ( F_121 ( V_28 , V_400 ) ) {
V_76 = F_30 ( V_471 ) ;
if ( V_76 & F_216 ( V_75 -> V_107 ) )
V_167 -> V_399 = true ;
}
if ( V_6 -> type == V_11 && V_28 -> V_45 . V_472 &&
V_167 -> V_175 > V_28 -> V_45 . V_472 ) {
F_48 ( L_31 ,
V_167 -> V_175 , V_28 -> V_45 . V_472 ) ;
V_28 -> V_45 . V_472 = V_167 -> V_175 ;
}
F_77 ( V_6 , V_167 ) ;
}
static void F_217 ( struct V_5 * V_6 )
{
F_218 ( V_6 ) ;
}
static bool F_219 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
int type = V_6 -> type ;
int V_4 = F_5 ( V_6 ) ;
F_4 ( type == V_13 , L_32 ) ;
if ( V_4 == V_61 )
V_167 -> V_301 = V_318 ;
if ( type == V_12 )
return F_220 ( V_6 , V_167 ) ;
else
return F_221 ( V_6 , V_167 ) ;
}
static struct V_337 *
F_222 ( struct V_2 * V_16 )
{
struct V_337 * V_113 ;
enum V_4 V_4 = V_16 -> V_4 ;
V_113 = F_223 () ;
if ( ! V_113 )
return NULL ;
V_16 -> V_334 . V_473 = F_28 ( V_4 ) ;
if ( ! F_224 ( V_16 , V_113 ) ) {
F_225 ( V_113 ) ;
return NULL ;
}
return V_113 ;
}
static struct V_337 *
F_226 ( struct V_2 * V_16 )
{
struct V_337 * V_113 ;
enum V_4 V_4 = V_16 -> V_4 ;
V_113 = F_223 () ;
if ( ! V_113 )
return NULL ;
V_16 -> V_17 . V_18 = F_28 ( V_4 ) ;
F_227 ( V_16 , V_113 ) ;
return V_113 ;
}
void F_228 ( struct V_20 * V_21 , enum V_4 V_4 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_2 * V_16 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
bool V_474 , V_475 ;
V_474 = ( V_28 -> V_45 . V_46 [ V_4 ] . V_476 ||
V_28 -> V_45 . V_46 [ V_4 ] . V_36 ) ;
V_475 = V_28 -> V_45 . V_46 [ V_4 ] . V_477 ;
if ( ! V_475 && ! V_474 ) {
F_48 ( L_33 ,
F_32 ( V_4 ) ) ;
return;
}
V_16 = F_229 ( sizeof( * V_16 ) , V_478 ) ;
if ( ! V_16 )
return;
V_1 = & V_16 -> V_7 ;
V_6 = & V_1 -> V_7 ;
F_230 ( V_21 , V_6 , & V_479 ,
V_480 ) ;
V_1 -> V_481 = F_219 ;
V_1 -> V_373 = F_156 ;
V_1 -> V_482 = F_141 ;
V_1 -> V_406 = F_162 ;
V_1 -> V_483 = F_153 ;
V_1 -> V_342 = F_122 ;
V_1 -> V_484 = F_214 ;
V_16 -> V_4 = V_4 ;
V_16 -> V_103 = F_30 ( F_28 ( V_4 ) ) &
( V_485 |
V_486 ) ;
V_1 -> type = V_13 ;
V_1 -> V_242 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_1 -> V_487 = 0 ;
if ( V_475 ) {
if ( ! F_222 ( V_16 ) )
goto V_488;
V_16 -> V_489 = V_490 ;
if ( F_14 ( V_28 ) && ( F_231 ( V_21 ) < V_491 )
&& V_4 == V_62 )
V_28 -> V_492 . V_493 [ V_61 ] = V_16 ;
else
V_28 -> V_492 . V_493 [ V_4 ] = V_16 ;
}
if ( V_1 -> type != V_11 && V_474 ) {
if ( ! F_226 ( V_16 ) )
goto V_488;
}
return;
V_488:
F_232 ( V_6 ) ;
F_225 ( V_16 ) ;
}
