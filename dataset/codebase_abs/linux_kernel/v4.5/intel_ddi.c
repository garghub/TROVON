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
return F_7 ( V_16 -> V_17 . V_18 ) ;
}
static const struct V_19 * F_8 ( struct V_20 * V_21 ,
int * V_22 )
{
const struct V_19 * V_23 ;
if ( F_9 ( V_21 ) || F_10 ( V_21 ) ) {
V_23 = V_24 ;
* V_22 = F_11 ( V_24 ) ;
} else if ( F_12 ( V_21 ) || F_13 ( V_21 ) ) {
V_23 = V_25 ;
* V_22 = F_11 ( V_25 ) ;
} else {
V_23 = V_26 ;
* V_22 = F_11 ( V_26 ) ;
}
return V_23 ;
}
static const struct V_19 * F_14 ( struct V_20 * V_21 ,
int * V_22 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
const struct V_19 * V_23 ;
if ( F_9 ( V_21 ) || F_10 ( V_21 ) ) {
if ( V_28 -> V_30 ) {
V_23 = V_31 ;
* V_22 = F_11 ( V_31 ) ;
} else {
V_23 = V_24 ;
* V_22 = F_11 ( V_24 ) ;
}
} else if ( F_12 ( V_21 ) || F_13 ( V_21 ) ) {
if ( V_28 -> V_30 ) {
V_23 = V_32 ;
* V_22 = F_11 ( V_32 ) ;
} else {
V_23 = V_25 ;
* V_22 = F_11 ( V_25 ) ;
}
} else {
if ( V_28 -> V_30 ) {
V_23 = V_33 ;
* V_22 = F_11 ( V_33 ) ;
} else {
V_23 = V_26 ;
* V_22 = F_11 ( V_26 ) ;
}
}
return V_23 ;
}
static const struct V_19 *
F_15 ( struct V_20 * V_21 ,
int * V_22 )
{
const struct V_19 * V_23 ;
if ( F_9 ( V_21 ) || F_10 ( V_21 ) ) {
V_23 = V_34 ;
* V_22 = F_11 ( V_34 ) ;
} else {
V_23 = V_35 ;
* V_22 = F_11 ( V_35 ) ;
}
return V_23 ;
}
static void F_16 ( struct V_20 * V_21 , enum V_4 V_4 ,
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
if ( F_17 ( V_21 ) ) {
if ( ! V_36 )
return;
F_18 ( V_21 , V_44 , V_4 ,
V_12 ) ;
return;
} else if ( F_19 ( V_21 ) || F_20 ( V_21 ) ) {
V_48 = NULL ;
V_49 =
F_8 ( V_21 , & V_40 ) ;
V_50 =
F_14 ( V_21 , & V_41 ) ;
V_51 =
F_15 ( V_21 , & V_39 ) ;
V_42 = 8 ;
if ( V_28 -> V_45 . V_46 [ V_4 ] . V_52 ||
V_28 -> V_45 . V_46 [ V_4 ] . V_53 )
V_37 = 1 << 31 ;
} else if ( F_21 ( V_21 ) ) {
V_48 = V_54 ;
V_49 = V_55 ;
V_50 = V_56 ;
V_51 = V_57 ;
V_41 = F_11 ( V_56 ) ;
V_40 = F_11 ( V_55 ) ;
V_39 = F_11 ( V_57 ) ;
V_42 = 7 ;
} else if ( F_22 ( V_21 ) ) {
V_48 = V_58 ;
V_49 = V_59 ;
V_50 = V_59 ;
V_51 = V_60 ;
V_40 = V_41 = F_11 ( V_59 ) ;
V_39 = F_11 ( V_60 ) ;
V_42 = 6 ;
} else {
F_4 ( 1 , L_2 ) ;
V_50 = V_55 ;
V_48 = V_54 ;
V_49 = V_55 ;
V_51 = V_57 ;
V_41 = F_11 ( V_56 ) ;
V_40 = F_11 ( V_55 ) ;
V_39 = F_11 ( V_57 ) ;
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
if ( F_23 ( V_21 , V_64 ) ) {
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
F_24 () ;
}
for ( V_38 = 0 ; V_38 < V_43 ; V_38 ++ ) {
F_25 ( F_26 ( V_4 , V_38 ) ,
V_23 [ V_38 ] . V_65 | V_37 ) ;
F_25 ( F_27 ( V_4 , V_38 ) ,
V_23 [ V_38 ] . V_66 ) ;
}
if ( ! V_36 )
return;
if ( V_44 == V_67 ||
V_44 >= V_39 )
V_44 = V_42 ;
F_25 ( F_26 ( V_4 , V_38 ) ,
V_51 [ V_44 ] . V_65 | V_37 ) ;
F_25 ( F_27 ( V_4 , V_38 ) ,
V_51 [ V_44 ] . V_66 ) ;
}
void F_28 ( struct V_20 * V_21 )
{
struct V_1 * V_1 ;
bool V_68 [ V_69 ] = { 0 , } ;
if ( ! F_29 ( V_21 ) )
return;
F_30 (dev, intel_encoder) {
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
F_16 ( V_21 , V_4 , V_36 ) ;
V_68 [ V_4 ] = true ;
}
}
static void F_31 ( struct V_27 * V_28 ,
enum V_4 V_4 )
{
T_2 V_71 = F_32 ( V_4 ) ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 16 ; V_38 ++ ) {
F_33 ( 1 ) ;
if ( F_34 ( V_71 ) & V_72 )
return;
}
F_35 ( L_3 , F_36 ( V_4 ) ) ;
}
void F_37 ( struct V_73 * V_74 )
{
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_75 * V_75 = F_38 ( V_74 ) ;
T_1 V_76 , V_38 , V_77 ;
F_25 ( F_39 ( V_78 ) , F_40 ( 2 ) |
F_41 ( 2 ) |
V_79 | V_80 ) ;
V_77 = V_28 -> V_81 | V_82 |
V_83 |
F_42 ( V_75 -> V_84 -> V_85 ) ;
F_25 ( F_43 ( V_78 ) , V_77 ) ;
F_44 ( F_43 ( V_78 ) ) ;
F_33 ( 220 ) ;
V_77 |= V_86 ;
F_25 ( F_43 ( V_78 ) , V_77 ) ;
F_25 ( F_45 ( V_15 ) , V_75 -> V_84 -> V_87 ) ;
F_46 ( V_75 -> V_84 -> V_87 != V_88 ) ;
for ( V_38 = 0 ; V_38 < F_11 ( V_58 ) * 2 ; V_38 ++ ) {
F_25 ( F_47 ( V_15 ) ,
V_89 |
V_90 |
V_91 |
V_92 ) ;
F_25 ( F_32 ( V_15 ) ,
V_93 |
( ( V_75 -> V_84 -> V_85 - 1 ) << 1 ) |
F_48 ( V_38 / 2 ) ) ;
F_44 ( F_32 ( V_15 ) ) ;
F_33 ( 600 ) ;
F_25 ( F_49 ( V_78 ) , F_50 ( 64 ) ) ;
V_77 |= V_94 | V_95 ;
F_25 ( F_43 ( V_78 ) , V_77 ) ;
F_44 ( F_43 ( V_78 ) ) ;
F_33 ( 30 ) ;
V_76 = F_34 ( F_39 ( V_78 ) ) ;
V_76 &= ~ ( V_96 | V_97 ) ;
F_25 ( F_39 ( V_78 ) , V_76 ) ;
F_44 ( F_39 ( V_78 ) ) ;
F_33 ( 5 ) ;
V_76 = F_34 ( F_51 ( V_15 ) ) ;
if ( V_76 & V_98 ) {
F_52 ( L_4 , V_38 ) ;
break;
}
if ( V_38 == F_11 ( V_58 ) * 2 - 1 ) {
F_35 ( L_5 ) ;
break;
}
V_76 = F_34 ( F_32 ( V_15 ) ) ;
V_76 &= ~ V_93 ;
F_25 ( F_32 ( V_15 ) , V_76 ) ;
F_44 ( F_32 ( V_15 ) ) ;
V_76 = F_34 ( F_47 ( V_15 ) ) ;
V_76 &= ~ ( V_92 | V_99 ) ;
V_76 |= V_91 ;
F_25 ( F_47 ( V_15 ) , V_76 ) ;
F_44 ( F_47 ( V_15 ) ) ;
F_31 ( V_28 , V_15 ) ;
V_77 &= ~ V_94 ;
F_25 ( F_43 ( V_78 ) , V_77 ) ;
F_44 ( F_43 ( V_78 ) ) ;
V_76 = F_34 ( F_39 ( V_78 ) ) ;
V_76 &= ~ ( V_96 | V_97 ) ;
V_76 |= F_40 ( 2 ) | F_41 ( 2 ) ;
F_25 ( F_39 ( V_78 ) , V_76 ) ;
F_44 ( F_39 ( V_78 ) ) ;
}
F_25 ( F_47 ( V_15 ) ,
V_89 |
V_100 |
V_90 |
V_92 ) ;
}
void F_53 ( struct V_1 * V_6 )
{
struct V_101 * V_101 = F_54 ( & V_6 -> V_7 ) ;
struct V_2 * V_16 =
F_3 ( & V_6 -> V_7 ) ;
V_101 -> V_102 = V_16 -> V_103 |
V_93 | F_48 ( 0 ) ;
V_101 -> V_102 |= F_55 ( V_101 -> V_104 ) ;
}
static struct V_1 *
F_56 ( struct V_73 * V_74 )
{
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_75 * V_75 = F_38 ( V_74 ) ;
struct V_1 * V_1 , * V_105 = NULL ;
int V_106 = 0 ;
F_57 (dev, crtc, intel_encoder) {
V_105 = V_1 ;
V_106 ++ ;
}
if ( V_106 != 1 )
F_4 ( 1 , L_6 , V_106 ,
F_58 ( V_75 -> V_107 ) ) ;
F_59 ( V_105 == NULL ) ;
return V_105 ;
}
struct V_1 *
F_60 ( struct V_108 * V_109 )
{
struct V_75 * V_74 = F_38 ( V_109 -> V_7 . V_74 ) ;
struct V_1 * V_105 = NULL ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
int V_106 = 0 ;
int V_38 ;
V_111 = V_109 -> V_7 . V_111 ;
F_61 (state, connector, connector_state, i) {
if ( V_115 -> V_74 != V_109 -> V_7 . V_74 )
continue;
V_105 = F_62 ( V_115 -> V_116 ) ;
V_106 ++ ;
}
F_4 ( V_106 != 1 , L_6 , V_106 ,
F_58 ( V_74 -> V_107 ) ) ;
F_59 ( V_105 == NULL ) ;
return V_105 ;
}
static unsigned F_63 ( int clock )
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
static void F_64 ( T_3 V_118 , unsigned V_117 ,
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
V_128 = F_65 ( V_118 * V_121 * V_119 , V_130 * V_120 ) ;
V_129 = F_65 ( V_118 * V_123 -> V_121 * V_123 -> V_119 ,
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
static int F_66 ( struct V_27 * V_28 ,
T_2 V_71 )
{
int V_131 = V_132 ;
int V_133 , V_121 , V_134 ;
T_1 V_135 ;
V_135 = F_34 ( V_71 ) ;
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
static int F_67 ( struct V_27 * V_28 ,
T_4 V_145 )
{
T_2 V_146 , V_147 ;
T_4 V_148 , V_149 ;
T_4 V_150 , V_151 , V_152 , V_153 ;
V_146 = F_68 ( V_145 ) ;
V_147 = F_69 ( V_145 ) ;
V_148 = F_34 ( V_146 ) ;
V_149 = F_34 ( V_147 ) ;
V_150 = V_149 & V_154 ;
V_152 = V_149 & V_155 ;
if ( V_149 & F_70 ( 1 ) )
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
static void F_71 ( struct V_108 * V_167 )
{
int V_168 ;
if ( V_167 -> V_169 )
V_168 = F_72 ( V_167 -> V_170 ,
& V_167 -> V_171 ) ;
else if ( V_167 -> V_172 )
V_168 = F_72 ( V_167 -> V_170 ,
& V_167 -> V_173 ) ;
else if ( V_167 -> V_174 && V_167 -> V_175 == 36 )
V_168 = V_167 -> V_170 * 2 / 3 ;
else
V_168 = V_167 -> V_170 ;
if ( V_167 -> V_176 )
V_168 /= V_167 -> V_176 ;
V_167 -> V_7 . V_177 . V_178 = V_168 ;
}
static void F_73 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
int V_179 = 0 ;
T_4 V_180 , V_145 ;
V_145 = V_167 -> V_87 ;
V_180 = F_34 ( V_181 ) ;
if ( V_180 & F_74 ( V_145 ) ) {
V_179 = F_67 ( V_28 , V_145 ) ;
} else {
V_179 = V_180 & F_75 ( V_145 ) ;
V_179 >>= F_76 ( V_145 ) ;
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
F_71 ( V_167 ) ;
}
static void F_77 ( struct V_1 * V_6 ,
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
V_179 = F_66 ( V_28 , F_78 ( 0 ) ) ;
break;
case V_195 :
V_179 = F_66 ( V_28 , F_78 ( 1 ) ) ;
break;
case V_88 :
V_189 = F_34 ( V_196 ) & V_197 ;
if ( V_189 == V_198 )
V_179 = 81000 ;
else if ( V_189 == V_199 )
V_179 = 135000 ;
else if ( V_189 == V_200 )
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
F_71 ( V_167 ) ;
}
static int F_79 ( struct V_27 * V_28 ,
enum V_201 V_145 )
{
struct V_202 * V_189 ;
struct V_203 * V_111 ;
T_5 clock ;
if ( F_46 ( V_145 == V_204 ) )
return 0 ;
V_189 = & V_28 -> V_205 [ V_145 ] ;
V_111 = & V_189 -> V_84 . V_206 ;
clock . V_207 = 2 ;
clock . V_208 = ( V_111 -> V_209 & V_210 ) << 22 ;
if ( V_111 -> V_211 & V_212 )
clock . V_208 |= V_111 -> V_213 & V_214 ;
clock . V_133 = ( V_111 -> V_215 & V_216 ) >> V_217 ;
clock . V_151 = ( V_111 -> V_218 & V_219 ) >> V_220 ;
clock . V_152 = ( V_111 -> V_218 & V_221 ) >> V_222 ;
return F_80 ( 100000 , & clock ) ;
}
static void F_81 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
enum V_4 V_4 = F_5 ( V_6 ) ;
T_4 V_145 = V_4 ;
V_167 -> V_170 = F_79 ( V_28 , V_145 ) ;
F_71 ( V_167 ) ;
}
void F_82 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
struct V_20 * V_21 = V_6 -> V_7 . V_21 ;
if ( F_83 ( V_21 ) -> V_223 <= 8 )
F_77 ( V_6 , V_167 ) ;
else if ( F_19 ( V_21 ) || F_20 ( V_21 ) )
F_73 ( V_6 , V_167 ) ;
else if ( F_17 ( V_21 ) )
F_81 ( V_6 , V_167 ) ;
}
static void
F_84 ( int clock ,
unsigned * V_224 , unsigned * V_225 , unsigned * V_226 )
{
T_3 V_118 ;
unsigned V_121 , V_120 , V_119 ;
struct V_122 V_123 = { 0 , 0 , 0 } ;
unsigned V_117 ;
V_118 = clock / 100 ;
V_117 = F_63 ( clock ) ;
if ( V_118 == 5400000 ) {
* V_225 = 2 ;
* V_226 = 1 ;
* V_224 = 2 ;
return;
}
for ( V_119 = V_132 * 2 / V_227 + 1 ;
V_119 <= V_132 * 2 / V_228 ;
V_119 ++ ) {
for ( V_120 = V_229 * V_119 / V_132 + 1 ;
V_120 <= V_230 * V_119 / V_132 ;
V_120 ++ ) {
for ( V_121 = V_231 ; V_121 <= V_232 ; V_121 += V_233 )
F_64 ( V_118 , V_117 ,
V_119 , V_120 , V_121 , & V_123 ) ;
}
}
* V_225 = V_123 . V_120 ;
* V_226 = V_123 . V_121 ;
* V_224 = V_123 . V_119 ;
}
static bool
F_85 ( struct V_75 * V_75 ,
struct V_108 * V_109 ,
struct V_1 * V_1 )
{
int clock = V_109 -> V_170 ;
if ( V_1 -> type == V_12 ) {
struct V_202 * V_189 ;
T_4 V_188 ;
unsigned V_121 , V_120 , V_119 ;
F_84 ( clock * 1000 , & V_119 , & V_120 , & V_121 ) ;
V_188 = V_234 | V_139 |
F_86 ( V_119 ) | F_87 ( V_120 ) |
F_88 ( V_121 ) ;
memset ( & V_109 -> V_235 , 0 ,
sizeof( V_109 -> V_235 ) ) ;
V_109 -> V_235 . V_135 = V_188 ;
V_189 = F_89 ( V_75 , V_109 ) ;
if ( V_189 == NULL ) {
F_90 ( L_11 ,
F_58 ( V_75 -> V_107 ) ) ;
return false ;
}
V_109 -> V_87 = F_91 ( V_189 -> V_236 ) ;
} else if ( V_109 -> V_87 == V_88 ) {
struct V_110 * V_111 = V_109 -> V_7 . V_111 ;
struct V_237 * V_238 =
& F_92 ( V_111 ) [ V_239 ] ;
if ( V_238 -> V_240 &&
F_46 ( V_238 -> V_206 . V_238 != V_109 -> V_235 . V_238 ) )
return false ;
V_109 -> V_241 = V_239 ;
V_238 -> V_206 . V_238 = V_109 -> V_235 . V_238 ;
V_238 -> V_240 |= 1 << V_75 -> V_107 ;
}
return true ;
}
static void F_93 ( struct V_242 * V_243 )
{
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
V_243 -> V_244 = V_245 ;
}
static void F_94 ( struct V_242 * V_243 ,
T_3 V_246 ,
T_3 V_153 ,
unsigned int V_247 )
{
T_3 V_248 ;
V_248 = F_95 ( 10000 * F_65 ( V_153 , V_246 ) ,
V_246 ) ;
if ( V_153 >= V_246 ) {
if ( V_248 < V_249 &&
V_248 < V_243 -> V_244 ) {
V_243 -> V_244 = V_248 ;
V_243 -> V_246 = V_246 ;
V_243 -> V_153 = V_153 ;
V_243 -> V_121 = V_247 ;
}
} else if ( V_248 < V_250 &&
V_248 < V_243 -> V_244 ) {
V_243 -> V_244 = V_248 ;
V_243 -> V_246 = V_246 ;
V_243 -> V_153 = V_153 ;
V_243 -> V_121 = V_247 ;
}
}
static void F_96 ( unsigned int V_121 ,
unsigned int * V_150 ,
unsigned int * V_151 ,
unsigned int * V_152 )
{
if ( V_121 % 2 == 0 ) {
unsigned int V_251 = V_121 / 2 ;
if ( V_251 == 1 || V_251 == 2 || V_251 == 3 || V_251 == 5 ) {
* V_150 = 2 ;
* V_151 = 1 ;
* V_152 = V_251 ;
} else if ( V_251 % 2 == 0 ) {
* V_150 = 2 ;
* V_151 = V_251 / 2 ;
* V_152 = 2 ;
} else if ( V_251 % 3 == 0 ) {
* V_150 = 3 ;
* V_151 = V_251 / 3 ;
* V_152 = 2 ;
} else if ( V_251 % 7 == 0 ) {
* V_150 = 7 ;
* V_151 = V_251 / 7 ;
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
static void F_97 ( struct V_252 * V_253 ,
T_3 V_254 ,
T_3 V_246 ,
T_4 V_150 , T_4 V_151 , T_4 V_152 )
{
T_3 V_153 ;
switch ( V_246 ) {
case 9600000000ULL :
V_253 -> V_246 = 0 ;
break;
case 9000000000ULL :
V_253 -> V_246 = 1 ;
break;
case 8400000000ULL :
V_253 -> V_246 = 3 ;
}
switch ( V_150 ) {
case 1 :
V_253 -> V_255 = 0 ;
break;
case 2 :
V_253 -> V_255 = 1 ;
break;
case 3 :
V_253 -> V_255 = 2 ;
break;
case 7 :
V_253 -> V_255 = 4 ;
break;
default:
F_4 ( 1 , L_12 ) ;
}
switch ( V_152 ) {
case 5 :
V_253 -> V_256 = 0 ;
break;
case 2 :
V_253 -> V_256 = 1 ;
break;
case 3 :
V_253 -> V_256 = 2 ;
break;
case 1 :
V_253 -> V_256 = 3 ;
break;
default:
F_4 ( 1 , L_13 ) ;
}
V_253 -> V_257 = V_151 ;
V_253 -> V_258 = ( V_253 -> V_257 == 1 ) ? 0 : 1 ;
V_153 = V_150 * V_151 * V_152 * V_254 ;
V_253 -> V_259 = F_98 ( V_153 , 24 * F_99 ( 1 ) ) ;
V_253 -> V_260 =
F_98 ( ( F_98 ( V_153 , 24 ) -
V_253 -> V_259 * F_99 ( 1 ) ) * 0x8000 , F_99 ( 1 ) ) ;
}
static bool
F_100 ( int clock ,
struct V_252 * V_261 )
{
T_3 V_254 = clock * 5 ;
T_3 V_262 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
static const int V_263 [] = { 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 ,
24 , 28 , 30 , 32 , 36 , 40 , 42 , 44 ,
48 , 52 , 54 , 56 , 60 , 64 , 66 , 68 ,
70 , 72 , 76 , 78 , 80 , 84 , 88 , 90 ,
92 , 96 , 98 } ;
static const int V_264 [] = { 3 , 5 , 7 , 9 , 15 , 21 , 35 } ;
static const struct {
const int * V_265 ;
int V_266 ;
} V_267 [] = {
{ V_263 , F_11 (even_dividers) } ,
{ V_264 , F_11 (odd_dividers) } ,
} ;
struct V_242 V_243 ;
unsigned int V_268 , V_127 , V_38 ;
unsigned int V_150 , V_151 , V_152 ;
F_93 ( & V_243 ) ;
for ( V_127 = 0 ; V_127 < F_11 ( V_267 ) ; V_127 ++ ) {
for ( V_268 = 0 ; V_268 < F_11 ( V_262 ) ; V_268 ++ ) {
for ( V_38 = 0 ; V_38 < V_267 [ V_127 ] . V_266 ; V_38 ++ ) {
unsigned int V_121 = V_267 [ V_127 ] . V_265 [ V_38 ] ;
T_3 V_153 = V_121 * V_254 ;
F_94 ( & V_243 ,
V_262 [ V_268 ] ,
V_153 ,
V_121 ) ;
if ( V_243 . V_244 == 0 )
goto V_269;
}
}
V_269:
if ( V_127 == 0 && V_243 . V_121 )
break;
}
if ( ! V_243 . V_121 ) {
F_90 ( L_14 , clock ) ;
return false ;
}
V_150 = V_151 = V_152 = 0 ;
F_96 ( V_243 . V_121 , & V_150 , & V_151 , & V_152 ) ;
F_97 ( V_261 , V_254 , V_243 . V_246 ,
V_150 , V_151 , V_152 ) ;
return true ;
}
static bool
F_101 ( struct V_75 * V_75 ,
struct V_108 * V_109 ,
struct V_1 * V_1 )
{
struct V_202 * V_189 ;
T_4 V_270 , V_271 , V_272 ;
int clock = V_109 -> V_170 ;
V_270 = F_102 ( 0 ) ;
if ( V_1 -> type == V_12 ) {
struct V_252 V_261 = { 0 , } ;
V_270 |= F_74 ( 0 ) ;
if ( ! F_100 ( clock * 1000 , & V_261 ) )
return false ;
V_271 = V_273 |
F_103 ( V_261 . V_260 ) |
V_261 . V_259 ;
V_272 = F_104 ( V_261 . V_257 ) |
F_70 ( V_261 . V_258 ) |
F_105 ( V_261 . V_256 ) |
F_106 ( V_261 . V_255 ) |
V_261 . V_246 ;
} else if ( V_1 -> type == V_10 ||
V_1 -> type == V_8 ) {
switch ( V_109 -> V_170 / 2 ) {
case 81000 :
V_270 |= F_107 ( V_182 , 0 ) ;
break;
case 135000 :
V_270 |= F_107 ( V_184 , 0 ) ;
break;
case 270000 :
V_270 |= F_107 ( V_187 , 0 ) ;
break;
}
V_271 = V_272 = 0 ;
} else
return true ;
memset ( & V_109 -> V_235 , 0 ,
sizeof( V_109 -> V_235 ) ) ;
V_109 -> V_235 . V_270 = V_270 ;
V_109 -> V_235 . V_271 = V_271 ;
V_109 -> V_235 . V_272 = V_272 ;
V_189 = F_89 ( V_75 , V_109 ) ;
if ( V_189 == NULL ) {
F_90 ( L_11 ,
F_58 ( V_75 -> V_107 ) ) ;
return false ;
}
V_109 -> V_87 = V_189 -> V_236 + 1 ;
return true ;
}
static bool
F_108 ( struct V_75 * V_75 ,
struct V_108 * V_109 ,
struct V_1 * V_1 )
{
struct V_202 * V_189 ;
struct V_274 V_275 = { 0 } ;
int V_276 = 0 ;
T_4 V_277 , V_278 , V_279 , V_280 ;
T_4 V_281 ;
int clock = V_109 -> V_170 ;
if ( V_1 -> type == V_12 ) {
T_5 V_282 ;
if ( ! F_109 ( V_109 , clock , & V_282 ) ) {
F_90 ( L_15 ,
clock , F_58 ( V_75 -> V_107 ) ) ;
return false ;
}
V_275 . V_151 = V_282 . V_151 ;
V_275 . V_152 = V_282 . V_152 ;
F_46 ( V_282 . V_207 != 2 ) ;
V_275 . V_133 = V_282 . V_133 ;
V_275 . V_283 = V_282 . V_208 >> 22 ;
V_275 . V_284 = V_282 . V_208 & ( ( 1 << 22 ) - 1 ) ;
V_275 . V_285 = V_275 . V_284 != 0 ;
V_276 = V_282 . V_276 ;
} else if ( V_1 -> type == V_10 ||
V_1 -> type == V_11 ) {
int V_38 ;
V_275 = V_286 [ 0 ] ;
for ( V_38 = 0 ; V_38 < F_11 ( V_286 ) ; ++ V_38 ) {
if ( V_286 [ V_38 ] . clock == clock ) {
V_275 = V_286 [ V_38 ] ;
break;
}
}
V_276 = clock * 10 / 2 * V_275 . V_151 * V_275 . V_152 ;
}
if ( V_276 >= 6200000 && V_276 <= 6700000 ) {
V_277 = 4 ;
V_278 = 9 ;
V_279 = 3 ;
V_280 = 8 ;
} else if ( ( V_276 > 5400000 && V_276 < 6200000 ) ||
( V_276 >= 4800000 && V_276 < 5400000 ) ) {
V_277 = 5 ;
V_278 = 11 ;
V_279 = 3 ;
V_280 = 9 ;
} else if ( V_276 == 5400000 ) {
V_277 = 3 ;
V_278 = 8 ;
V_279 = 1 ;
V_280 = 9 ;
} else {
F_35 ( L_16 ) ;
return false ;
}
memset ( & V_109 -> V_235 , 0 ,
sizeof( V_109 -> V_235 ) ) ;
if ( clock > 270000 )
V_281 = 0x18 ;
else if ( clock > 135000 )
V_281 = 0x0d ;
else if ( clock > 67000 )
V_281 = 0x07 ;
else if ( clock > 33000 )
V_281 = 0x04 ;
else
V_281 = 0x02 ;
V_109 -> V_235 . V_218 =
F_110 ( V_275 . V_151 ) | F_111 ( V_275 . V_152 ) ;
V_109 -> V_235 . V_209 = V_275 . V_283 ;
V_109 -> V_235 . V_215 = F_112 ( V_275 . V_133 ) ;
V_109 -> V_235 . V_213 = V_275 . V_284 ;
if ( V_275 . V_285 )
V_109 -> V_235 . V_211 =
V_212 ;
V_109 -> V_235 . V_287 =
V_277 | F_113 ( V_278 ) ;
V_109 -> V_235 . V_287 |=
F_114 ( V_279 ) ;
V_109 -> V_235 . V_288 = V_280 ;
V_109 -> V_235 . V_289 = 5 << V_290 ;
V_109 -> V_235 . V_291 =
F_115 ( V_292 )
| V_293 ;
V_109 -> V_235 . V_294 = V_295 ;
V_109 -> V_235 . V_296 =
V_297 | V_281 ;
V_189 = F_89 ( V_75 , V_109 ) ;
if ( V_189 == NULL ) {
F_90 ( L_11 ,
F_58 ( V_75 -> V_107 ) ) ;
return false ;
}
V_109 -> V_87 = V_189 -> V_236 ;
return true ;
}
bool F_116 ( struct V_75 * V_75 ,
struct V_108 * V_109 )
{
struct V_20 * V_21 = V_75 -> V_7 . V_21 ;
struct V_1 * V_1 =
F_60 ( V_109 ) ;
if ( F_19 ( V_21 ) || F_20 ( V_21 ) )
return F_101 ( V_75 , V_109 ,
V_1 ) ;
else if ( F_17 ( V_21 ) )
return F_108 ( V_75 , V_109 ,
V_1 ) ;
else
return F_85 ( V_75 , V_109 ,
V_1 ) ;
}
void F_117 ( struct V_73 * V_74 )
{
struct V_27 * V_28 = V_74 -> V_21 -> V_29 ;
struct V_75 * V_75 = F_38 ( V_74 ) ;
struct V_1 * V_1 = F_56 ( V_74 ) ;
enum V_298 V_299 = V_75 -> V_84 -> V_299 ;
int type = V_1 -> type ;
T_4 V_76 ;
if ( type == V_10 || type == V_11 || type == V_8 ) {
V_76 = V_300 ;
switch ( V_75 -> V_84 -> V_175 ) {
case 18 :
V_76 |= V_301 ;
break;
case 24 :
V_76 |= V_302 ;
break;
case 30 :
V_76 |= V_303 ;
break;
case 36 :
V_76 |= V_304 ;
break;
default:
F_24 () ;
}
F_25 ( F_118 ( V_299 ) , V_76 ) ;
}
}
void F_119 ( struct V_73 * V_74 , bool V_111 )
{
struct V_75 * V_75 = F_38 ( V_74 ) ;
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_298 V_299 = V_75 -> V_84 -> V_299 ;
T_4 V_76 ;
V_76 = F_34 ( F_120 ( V_299 ) ) ;
if ( V_111 == true )
V_76 |= V_305 ;
else
V_76 &= ~ V_305 ;
F_25 ( F_120 ( V_299 ) , V_76 ) ;
}
void F_121 ( struct V_73 * V_74 )
{
struct V_75 * V_75 = F_38 ( V_74 ) ;
struct V_1 * V_1 = F_56 ( V_74 ) ;
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_107 V_107 = V_75 -> V_107 ;
enum V_298 V_299 = V_75 -> V_84 -> V_299 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_4 V_76 ;
V_76 = V_306 ;
V_76 |= F_122 ( V_4 ) ;
switch ( V_75 -> V_84 -> V_175 ) {
case 18 :
V_76 |= V_307 ;
break;
case 24 :
V_76 |= V_308 ;
break;
case 30 :
V_76 |= V_309 ;
break;
case 36 :
V_76 |= V_310 ;
break;
default:
F_24 () ;
}
if ( V_75 -> V_84 -> V_7 . V_177 . V_311 & V_312 )
V_76 |= V_313 ;
if ( V_75 -> V_84 -> V_7 . V_177 . V_311 & V_314 )
V_76 |= V_315 ;
if ( V_299 == V_316 ) {
switch ( V_107 ) {
case V_78 :
if ( F_22 ( V_21 ) &&
( V_75 -> V_84 -> V_317 . V_318 ||
V_75 -> V_84 -> V_317 . V_319 ) )
V_76 |= V_320 ;
else
V_76 |= V_321 ;
break;
case V_322 :
V_76 |= V_323 ;
break;
case V_324 :
V_76 |= V_325 ;
break;
default:
F_24 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_75 -> V_84 -> V_174 )
V_76 |= V_326 ;
else
V_76 |= V_327 ;
} else if ( type == V_14 ) {
V_76 |= V_328 ;
V_76 |= ( V_75 -> V_84 -> V_85 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_101 * V_101 = F_54 ( V_6 ) ;
if ( V_101 -> V_329 ) {
V_76 |= V_330 ;
} else
V_76 |= V_331 ;
V_76 |= F_55 ( V_75 -> V_84 -> V_104 ) ;
} else if ( type == V_8 ) {
struct V_101 * V_101 = & F_2 ( V_6 ) -> V_9 -> V_332 ;
if ( V_101 -> V_329 ) {
V_76 |= V_330 ;
} else
V_76 |= V_331 ;
V_76 |= F_55 ( V_75 -> V_84 -> V_104 ) ;
} else {
F_4 ( 1 , L_17 ,
V_1 -> type , F_58 ( V_107 ) ) ;
}
F_25 ( F_120 ( V_299 ) , V_76 ) ;
}
void F_123 ( struct V_27 * V_28 ,
enum V_298 V_299 )
{
T_2 V_71 = F_120 ( V_299 ) ;
T_4 V_188 = F_34 ( V_71 ) ;
V_188 &= ~ ( V_306 | V_333 | V_305 ) ;
V_188 |= V_334 ;
F_25 ( V_71 , V_188 ) ;
}
bool F_124 ( struct V_335 * V_335 )
{
struct V_20 * V_21 = V_335 -> V_7 . V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_1 * V_1 = V_335 -> V_6 ;
int type = V_335 -> V_7 . V_336 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_107 V_107 = 0 ;
enum V_298 V_299 ;
enum V_337 V_338 ;
T_4 V_339 ;
bool V_105 ;
V_338 = F_125 ( V_1 ) ;
if ( ! F_126 ( V_28 , V_338 ) )
return false ;
if ( ! V_1 -> V_340 ( V_1 , & V_107 ) ) {
V_105 = false ;
goto V_341;
}
if ( V_4 == V_61 )
V_299 = V_316 ;
else
V_299 = (enum V_298 ) V_107 ;
V_339 = F_34 ( F_120 ( V_299 ) ) ;
switch ( V_339 & V_342 ) {
case V_326 :
case V_327 :
V_105 = type == V_343 ;
break;
case V_331 :
V_105 = type == V_344 ||
type == V_345 ;
break;
case V_330 :
V_105 = false ;
break;
case V_328 :
V_105 = type == V_346 ;
break;
default:
V_105 = false ;
break;
}
V_341:
F_127 ( V_28 , V_338 ) ;
return V_105 ;
}
bool F_128 ( struct V_1 * V_6 ,
enum V_107 * V_107 )
{
struct V_20 * V_21 = V_6 -> V_7 . V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_4 V_4 = F_5 ( V_6 ) ;
enum V_337 V_338 ;
T_1 V_339 ;
int V_38 ;
bool V_105 ;
V_338 = F_125 ( V_6 ) ;
if ( ! F_126 ( V_28 , V_338 ) )
return false ;
V_105 = false ;
V_339 = F_34 ( F_32 ( V_4 ) ) ;
if ( ! ( V_339 & V_93 ) )
goto V_341;
if ( V_4 == V_61 ) {
V_339 = F_34 ( F_120 ( V_316 ) ) ;
switch ( V_339 & V_347 ) {
case V_321 :
case V_320 :
* V_107 = V_78 ;
break;
case V_323 :
* V_107 = V_322 ;
break;
case V_325 :
* V_107 = V_324 ;
break;
}
V_105 = true ;
goto V_341;
}
for ( V_38 = V_348 ; V_38 <= V_349 ; V_38 ++ ) {
V_339 = F_34 ( F_120 ( V_38 ) ) ;
if ( ( V_339 & V_333 ) == F_122 ( V_4 ) ) {
if ( ( V_339 & V_342 ) ==
V_330 )
goto V_341;
* V_107 = V_38 ;
V_105 = true ;
goto V_341;
}
}
F_52 ( L_18 , F_36 ( V_4 ) ) ;
V_341:
F_127 ( V_28 , V_338 ) ;
return V_105 ;
}
void F_129 ( struct V_75 * V_75 )
{
struct V_73 * V_74 = & V_75 -> V_7 ;
struct V_20 * V_21 = V_74 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_1 * V_1 = F_56 ( V_74 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_298 V_299 = V_75 -> V_84 -> V_299 ;
if ( V_299 != V_316 )
F_25 ( F_130 ( V_299 ) ,
F_131 ( V_4 ) ) ;
}
void F_132 ( struct V_75 * V_75 )
{
struct V_27 * V_28 = V_75 -> V_7 . V_21 -> V_29 ;
enum V_298 V_299 = V_75 -> V_84 -> V_299 ;
if ( V_299 != V_316 )
F_25 ( F_130 ( V_299 ) ,
V_350 ) ;
}
static void F_133 ( struct V_20 * V_21 , T_1 V_351 ,
enum V_4 V_4 , int type )
{
struct V_27 * V_28 = V_21 -> V_29 ;
const struct V_19 * V_23 ;
T_6 V_352 ;
T_6 V_353 , V_354 ;
int V_22 ;
T_1 V_71 ;
V_353 = V_28 -> V_45 . V_46 [ V_4 ] . V_53 ;
V_354 = V_28 -> V_45 . V_46 [ V_4 ] . V_52 ;
if ( type == V_10 ) {
if ( V_353 ) {
V_352 = V_353 ;
} else {
V_23 = F_8 ( V_21 , & V_22 ) ;
V_352 = V_23 [ V_351 ] . V_355 ;
}
} else if ( type == V_11 ) {
if ( V_353 ) {
V_352 = V_353 ;
} else {
V_23 = F_14 ( V_21 , & V_22 ) ;
V_352 = V_23 [ V_351 ] . V_355 ;
}
} else if ( type == V_12 ) {
if ( V_354 ) {
V_352 = V_354 ;
} else {
V_23 = F_15 ( V_21 , & V_22 ) ;
V_352 = V_23 [ V_351 ] . V_355 ;
}
} else {
return;
}
if ( V_352 && V_352 != 0x1 && V_352 != 0x3 && V_352 != 0x7 ) {
F_35 ( L_19 , V_352 ) ;
return;
}
V_71 = F_34 ( V_356 ) ;
V_71 &= ~ F_134 ( V_4 ) ;
V_71 &= ~ ( 1 << ( V_357 + V_4 ) ) ;
if ( V_352 )
V_71 |= V_352 << F_135 ( V_4 ) ;
else
V_71 |= 1 << ( V_357 + V_4 ) ;
F_25 ( V_356 , V_71 ) ;
}
static void F_18 ( struct V_20 * V_21 , T_1 V_351 ,
enum V_4 V_4 , int type )
{
struct V_27 * V_28 = V_21 -> V_29 ;
const struct V_358 * V_23 ;
T_1 V_22 , V_38 ;
T_4 V_188 ;
if ( type == V_11 && V_28 -> V_30 ) {
V_22 = F_11 ( V_359 ) ;
V_23 = V_359 ;
} else if ( type == V_10
|| type == V_11 ) {
V_22 = F_11 ( V_360 ) ;
V_23 = V_360 ;
} else if ( type == V_12 ) {
V_22 = F_11 ( V_361 ) ;
V_23 = V_361 ;
} else {
F_52 ( L_20 ,
type ) ;
return;
}
if ( V_351 >= V_22 ||
( type == V_12 && V_351 == V_67 ) ) {
for ( V_38 = 0 ; V_38 < V_22 ; V_38 ++ ) {
if ( V_23 [ V_38 ] . V_362 ) {
V_351 = V_38 ;
break;
}
}
}
V_188 = F_34 ( F_136 ( V_4 ) ) ;
V_188 &= ~ ( V_363 | V_364 ) ;
F_25 ( F_137 ( V_4 ) , V_188 ) ;
V_188 = F_34 ( F_138 ( V_4 ) ) ;
V_188 &= ~ ( V_365 | V_366 ) ;
V_188 |= V_23 [ V_351 ] . V_367 << V_368 |
V_23 [ V_351 ] . V_369 << V_370 ;
F_25 ( F_139 ( V_4 ) , V_188 ) ;
V_188 = F_34 ( F_140 ( V_4 ) ) ;
V_188 &= ~ V_371 ;
if ( V_23 [ V_351 ] . V_372 )
V_188 |= V_371 ;
if ( ( V_188 & V_373 ) && ! ( V_188 & V_371 ) )
F_35 ( L_21 ) ;
F_25 ( F_141 ( V_4 ) , V_188 ) ;
V_188 = F_34 ( F_142 ( V_4 ) ) ;
V_188 &= ~ V_374 ;
V_188 |= V_23 [ V_351 ] . V_375 << V_376 ;
F_25 ( F_143 ( V_4 ) , V_188 ) ;
V_188 = F_34 ( F_136 ( V_4 ) ) ;
V_188 |= V_363 | V_364 ;
F_25 ( F_137 ( V_4 ) , V_188 ) ;
}
static T_4 F_144 ( int V_377 )
{
T_4 V_351 ;
switch ( V_377 ) {
default:
F_52 ( L_22 ,
V_377 ) ;
case V_378 | V_379 :
V_351 = 0 ;
break;
case V_378 | V_380 :
V_351 = 1 ;
break;
case V_378 | V_381 :
V_351 = 2 ;
break;
case V_378 | V_382 :
V_351 = 3 ;
break;
case V_383 | V_379 :
V_351 = 4 ;
break;
case V_383 | V_380 :
V_351 = 5 ;
break;
case V_383 | V_381 :
V_351 = 6 ;
break;
case V_384 | V_379 :
V_351 = 7 ;
break;
case V_384 | V_380 :
V_351 = 8 ;
break;
case V_385 | V_379 :
V_351 = 9 ;
break;
}
return V_351 ;
}
T_4 F_145 ( struct V_101 * V_101 )
{
struct V_2 * V_386 = F_146 ( V_101 ) ;
struct V_20 * V_21 = V_386 -> V_7 . V_7 . V_21 ;
struct V_1 * V_6 = & V_386 -> V_7 ;
T_6 V_387 = V_101 -> V_387 [ 0 ] ;
int V_377 = V_387 & ( V_388 |
V_389 ) ;
enum V_4 V_4 = V_386 -> V_4 ;
T_4 V_351 ;
V_351 = F_144 ( V_377 ) ;
if ( F_19 ( V_21 ) || F_20 ( V_21 ) )
F_133 ( V_21 , V_351 , V_4 , V_6 -> type ) ;
else if ( F_17 ( V_21 ) )
F_18 ( V_21 , V_351 , V_4 , V_6 -> type ) ;
return F_48 ( V_351 ) ;
}
void F_147 ( struct V_1 * V_6 ,
const struct V_108 * V_167 )
{
struct V_27 * V_28 = F_148 ( V_6 -> V_7 . V_21 ) ;
enum V_4 V_4 = F_5 ( V_6 ) ;
if ( F_19 ( V_28 ) || F_20 ( V_28 ) ) {
T_4 V_145 = V_167 -> V_87 ;
T_4 V_188 ;
if ( V_6 -> type == V_11 ) {
F_46 ( V_145 != V_390 ) ;
V_188 = F_34 ( V_181 ) ;
V_188 &= ~ ( F_74 ( V_145 ) |
F_149 ( V_145 ) |
F_75 ( V_145 ) ) ;
V_188 |= V_167 -> V_235 . V_270 << ( V_145 * 6 ) ;
F_25 ( V_181 , V_188 ) ;
F_44 ( V_181 ) ;
}
V_188 = F_34 ( V_391 ) ;
V_188 &= ~ ( F_150 ( V_4 ) |
F_151 ( V_4 ) ) ;
V_188 |= ( F_152 ( V_145 , V_4 ) |
F_153 ( V_4 ) ) ;
F_25 ( V_391 , V_188 ) ;
} else if ( F_83 ( V_28 ) -> V_223 < 9 ) {
F_46 ( V_167 -> V_87 == V_392 ) ;
F_25 ( F_45 ( V_4 ) , V_167 -> V_87 ) ;
}
}
static void F_154 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_75 * V_74 = F_38 ( V_6 -> V_74 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
int V_44 ;
if ( type == V_11 ) {
struct V_101 * V_101 = F_54 ( V_6 ) ;
F_155 ( V_101 ) ;
}
F_147 ( V_1 , V_74 -> V_84 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_101 * V_101 = F_54 ( V_6 ) ;
F_156 ( V_101 , V_74 -> V_84 ) ;
F_53 ( V_1 ) ;
F_157 ( V_101 , V_393 ) ;
F_158 ( V_101 ) ;
if ( V_4 != V_61 || F_83 ( V_21 ) -> V_223 >= 9 )
F_159 ( V_101 ) ;
} else if ( type == V_12 ) {
struct V_394 * V_394 = F_160 ( V_6 ) ;
if ( F_17 ( V_21 ) ) {
V_44 = V_28 -> V_45 .
V_46 [ V_4 ] . V_47 ;
F_18 ( V_21 , V_44 , V_4 ,
V_12 ) ;
}
V_394 -> V_395 ( V_6 ,
V_74 -> V_84 -> V_174 ,
& V_74 -> V_84 -> V_7 . V_177 ) ;
}
}
static void F_161 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_4 V_188 ;
bool V_396 = false ;
V_188 = F_34 ( F_32 ( V_4 ) ) ;
if ( V_188 & V_93 ) {
V_188 &= ~ V_93 ;
F_25 ( F_32 ( V_4 ) , V_188 ) ;
V_396 = true ;
}
V_188 = F_34 ( F_47 ( V_4 ) ) ;
V_188 &= ~ ( V_92 | V_99 ) ;
V_188 |= V_91 ;
F_25 ( F_47 ( V_4 ) , V_188 ) ;
if ( V_396 )
F_31 ( V_28 , V_4 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_101 * V_101 = F_54 ( V_6 ) ;
F_157 ( V_101 , V_397 ) ;
F_162 ( V_101 ) ;
F_163 ( V_101 ) ;
}
if ( F_19 ( V_21 ) || F_20 ( V_21 ) )
F_25 ( V_391 , ( F_34 ( V_391 ) |
F_150 ( V_4 ) ) ) ;
else if ( F_83 ( V_21 ) -> V_223 < 9 )
F_25 ( F_45 ( V_4 ) , V_392 ) ;
}
static void F_164 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_73 * V_74 = V_6 -> V_74 ;
struct V_75 * V_75 = F_38 ( V_74 ) ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
if ( type == V_12 ) {
struct V_2 * V_16 =
F_3 ( V_6 ) ;
F_25 ( F_32 ( V_4 ) ,
V_16 -> V_103 |
V_93 ) ;
} else if ( type == V_11 ) {
struct V_101 * V_101 = F_54 ( V_6 ) ;
if ( V_4 == V_61 && F_83 ( V_21 ) -> V_223 < 9 )
F_159 ( V_101 ) ;
F_165 ( V_101 ) ;
F_166 ( V_101 ) ;
F_167 ( V_101 ) ;
}
if ( V_75 -> V_84 -> V_398 ) {
F_168 ( V_28 , V_399 ) ;
F_169 ( V_1 ) ;
}
}
static void F_170 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_73 * V_74 = V_6 -> V_74 ;
struct V_75 * V_75 = F_38 ( V_74 ) ;
int type = V_1 -> type ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_27 * V_28 = V_21 -> V_29 ;
if ( V_75 -> V_84 -> V_398 ) {
F_171 ( V_1 ) ;
F_127 ( V_28 , V_399 ) ;
}
if ( type == V_11 ) {
struct V_101 * V_101 = F_54 ( V_6 ) ;
F_172 ( V_101 ) ;
F_173 ( V_101 ) ;
F_174 ( V_101 ) ;
}
}
static void F_175 ( struct V_27 * V_28 ,
struct V_202 * V_189 )
{
F_25 ( F_78 ( V_189 -> V_236 ) , V_189 -> V_84 . V_206 . V_135 ) ;
F_44 ( F_78 ( V_189 -> V_236 ) ) ;
F_33 ( 20 ) ;
}
static void F_176 ( struct V_27 * V_28 ,
struct V_202 * V_189 )
{
F_25 ( V_196 , V_189 -> V_84 . V_206 . V_238 ) ;
F_44 ( V_196 ) ;
F_33 ( 20 ) ;
}
static void F_177 ( struct V_27 * V_28 ,
struct V_202 * V_189 )
{
T_4 V_188 ;
V_188 = F_34 ( F_78 ( V_189 -> V_236 ) ) ;
F_25 ( F_78 ( V_189 -> V_236 ) , V_188 & ~ V_234 ) ;
F_44 ( F_78 ( V_189 -> V_236 ) ) ;
}
static void F_178 ( struct V_27 * V_28 ,
struct V_202 * V_189 )
{
T_4 V_188 ;
V_188 = F_34 ( V_196 ) ;
F_25 ( V_196 , V_188 & ~ V_400 ) ;
F_44 ( V_196 ) ;
}
static bool F_179 ( struct V_27 * V_28 ,
struct V_202 * V_189 ,
struct V_203 * V_206 )
{
T_4 V_188 ;
if ( ! F_126 ( V_28 , V_401 ) )
return false ;
V_188 = F_34 ( F_78 ( V_189 -> V_236 ) ) ;
V_206 -> V_135 = V_188 ;
F_127 ( V_28 , V_401 ) ;
return V_188 & V_234 ;
}
static bool F_180 ( struct V_27 * V_28 ,
struct V_202 * V_189 ,
struct V_203 * V_206 )
{
T_4 V_188 ;
if ( ! F_126 ( V_28 , V_401 ) )
return false ;
V_188 = F_34 ( V_196 ) ;
V_206 -> V_238 = V_188 ;
F_127 ( V_28 , V_401 ) ;
return V_188 & V_400 ;
}
static void F_181 ( struct V_27 * V_28 )
{
int V_38 ;
V_28 -> V_402 = 3 ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
V_28 -> V_205 [ V_38 ] . V_236 = V_38 ;
V_28 -> V_205 [ V_38 ] . V_403 = V_404 [ V_38 ] ;
V_28 -> V_205 [ V_38 ] . V_405 = F_177 ;
V_28 -> V_205 [ V_38 ] . V_372 = F_175 ;
V_28 -> V_205 [ V_38 ] . V_340 =
F_179 ;
}
V_28 -> V_205 [ V_38 ] . V_236 = V_38 ;
V_28 -> V_205 [ V_38 ] . V_403 = V_404 [ V_38 ] ;
V_28 -> V_205 [ V_38 ] . V_405 = F_178 ;
V_28 -> V_205 [ V_38 ] . V_372 = F_176 ;
V_28 -> V_205 [ V_38 ] . V_340 = F_180 ;
}
static void F_182 ( struct V_27 * V_28 ,
struct V_202 * V_189 )
{
T_4 V_188 ;
unsigned int V_145 ;
const struct V_406 * V_407 = V_406 ;
V_145 = V_189 -> V_236 + 1 ;
V_188 = F_34 ( V_181 ) ;
V_188 &= ~ ( F_74 ( V_145 ) | F_149 ( V_145 ) |
F_75 ( V_145 ) ) ;
V_188 |= V_189 -> V_84 . V_206 . V_270 << ( V_145 * 6 ) ;
F_25 ( V_181 , V_188 ) ;
F_44 ( V_181 ) ;
F_25 ( V_407 [ V_189 -> V_236 ] . V_271 , V_189 -> V_84 . V_206 . V_271 ) ;
F_25 ( V_407 [ V_189 -> V_236 ] . V_272 , V_189 -> V_84 . V_206 . V_272 ) ;
F_44 ( V_407 [ V_189 -> V_236 ] . V_271 ) ;
F_44 ( V_407 [ V_189 -> V_236 ] . V_272 ) ;
F_25 ( V_407 [ V_189 -> V_236 ] . V_408 ,
F_34 ( V_407 [ V_189 -> V_236 ] . V_408 ) | V_409 ) ;
if ( F_183 ( F_34 ( V_410 ) & F_184 ( V_145 ) , 5 ) )
F_35 ( L_23 , V_145 ) ;
}
static void F_185 ( struct V_27 * V_28 ,
struct V_202 * V_189 )
{
const struct V_406 * V_407 = V_406 ;
F_25 ( V_407 [ V_189 -> V_236 ] . V_408 ,
F_34 ( V_407 [ V_189 -> V_236 ] . V_408 ) & ~ V_409 ) ;
F_44 ( V_407 [ V_189 -> V_236 ] . V_408 ) ;
}
static bool F_186 ( struct V_27 * V_28 ,
struct V_202 * V_189 ,
struct V_203 * V_206 )
{
T_4 V_188 ;
unsigned int V_145 ;
const struct V_406 * V_407 = V_406 ;
bool V_105 ;
if ( ! F_126 ( V_28 , V_401 ) )
return false ;
V_105 = false ;
V_145 = V_189 -> V_236 + 1 ;
V_188 = F_34 ( V_407 [ V_189 -> V_236 ] . V_408 ) ;
if ( ! ( V_188 & V_409 ) )
goto V_341;
V_188 = F_34 ( V_181 ) ;
V_206 -> V_270 = ( V_188 >> ( V_145 * 6 ) ) & 0x3f ;
if ( V_188 & F_74 ( V_145 ) ) {
V_206 -> V_271 = F_34 ( V_407 [ V_189 -> V_236 ] . V_271 ) ;
V_206 -> V_272 = F_34 ( V_407 [ V_189 -> V_236 ] . V_272 ) ;
}
V_105 = true ;
V_341:
F_127 ( V_28 , V_401 ) ;
return V_105 ;
}
static void F_187 ( struct V_27 * V_28 )
{
int V_38 ;
V_28 -> V_402 = 3 ;
for ( V_38 = 0 ; V_38 < V_28 -> V_402 ; V_38 ++ ) {
V_28 -> V_205 [ V_38 ] . V_236 = V_38 ;
V_28 -> V_205 [ V_38 ] . V_403 = V_411 [ V_38 ] ;
V_28 -> V_205 [ V_38 ] . V_405 = F_185 ;
V_28 -> V_205 [ V_38 ] . V_372 = F_182 ;
V_28 -> V_205 [ V_38 ] . V_340 =
F_186 ;
}
}
static void F_188 ( struct V_27 * V_28 ,
enum V_412 V_413 )
{
enum V_4 V_4 ;
T_4 V_188 ;
V_188 = F_34 ( V_414 ) ;
V_188 |= F_189 ( V_413 ) ;
F_25 ( V_414 , V_188 ) ;
if ( F_183 ( F_34 ( F_190 ( V_413 ) ) & V_415 , 10 ) )
F_35 ( L_24 , V_413 ) ;
for ( V_4 = ( V_413 == V_416 ? V_62 : V_61 ) ;
V_4 <= ( V_413 == V_416 ? V_63 : V_61 ) ; V_4 ++ ) {
int V_417 ;
for ( V_417 = 0 ; V_417 < 4 ; V_417 ++ ) {
V_188 = F_34 ( F_191 ( V_4 , V_417 ) ) ;
V_188 &= ~ V_418 ;
if ( V_417 != 1 )
V_188 |= V_418 ;
F_25 ( F_191 ( V_4 , V_417 ) , V_188 ) ;
}
}
V_188 = F_34 ( F_192 ( V_413 ) ) ;
V_188 &= ~ V_419 ;
V_188 |= 0xE4 << V_420 ;
F_25 ( F_192 ( V_413 ) , V_188 ) ;
V_188 = F_34 ( F_193 ( V_413 ) ) ;
V_188 &= ~ V_421 ;
V_188 |= 0xE4 << V_422 ;
F_25 ( F_193 ( V_413 ) , V_188 ) ;
V_188 = F_34 ( F_194 ( V_413 ) ) ;
V_188 |= V_423 | V_424 |
V_425 ;
F_25 ( F_194 ( V_413 ) , V_188 ) ;
if ( V_413 == V_416 ) {
V_188 = F_34 ( V_426 ) ;
V_188 |= V_427 ;
F_25 ( V_426 , V_188 ) ;
}
V_188 = F_34 ( F_195 ( V_413 ) ) ;
V_188 &= ~ V_428 ;
if ( V_413 == V_429 )
V_188 |= V_428 ;
F_25 ( F_195 ( V_413 ) , V_188 ) ;
if ( V_413 == V_416 ) {
T_4 V_430 ;
if ( F_183 ( F_34 ( F_196 ( V_429 ) ) & V_431 ,
10 ) )
F_35 ( L_25 ) ;
V_188 = F_34 ( F_197 ( V_429 ) ) ;
V_188 = ( V_188 & V_432 ) >> V_433 ;
V_430 = V_188 << V_434 |
V_188 << V_435 |
V_188 ;
F_25 ( F_197 ( V_416 ) , V_430 ) ;
V_188 = F_34 ( F_198 ( V_416 ) ) ;
V_188 |= V_436 | V_437 ;
F_25 ( F_198 ( V_416 ) , V_188 ) ;
}
V_188 = F_34 ( F_199 ( V_413 ) ) ;
V_188 |= V_438 ;
F_25 ( F_199 ( V_413 ) , V_188 ) ;
}
void F_200 ( struct V_20 * V_21 )
{
F_188 ( V_21 -> V_29 , V_429 ) ;
F_188 ( V_21 -> V_29 , V_416 ) ;
}
static void F_201 ( struct V_27 * V_28 ,
enum V_412 V_413 )
{
T_4 V_188 ;
V_188 = F_34 ( F_199 ( V_413 ) ) ;
V_188 &= ~ V_438 ;
F_25 ( F_199 ( V_413 ) , V_188 ) ;
}
void F_202 ( struct V_20 * V_21 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
F_201 ( V_28 , V_429 ) ;
F_201 ( V_28 , V_416 ) ;
F_25 ( V_414 , 0 ) ;
}
static void F_203 ( struct V_27 * V_28 ,
struct V_202 * V_189 )
{
T_4 V_76 ;
enum V_4 V_4 = (enum V_4 ) V_189 -> V_236 ;
V_76 = F_34 ( F_204 ( V_4 ) ) ;
V_76 &= ~ V_439 ;
F_25 ( F_204 ( V_4 ) , V_76 ) ;
V_76 = F_34 ( F_205 ( V_4 ) ) ;
V_76 &= ~ V_295 ;
F_25 ( F_205 ( V_4 ) , V_76 ) ;
V_76 = F_34 ( F_206 ( V_4 ) ) ;
V_76 &= ~ ( V_219 | V_221 ) ;
V_76 |= V_189 -> V_84 . V_206 . V_218 ;
F_25 ( F_206 ( V_4 ) , V_76 ) ;
V_76 = F_34 ( F_207 ( V_4 , 0 ) ) ;
V_76 &= ~ V_210 ;
V_76 |= V_189 -> V_84 . V_206 . V_209 ;
F_25 ( F_207 ( V_4 , 0 ) , V_76 ) ;
V_76 = F_34 ( F_207 ( V_4 , 1 ) ) ;
V_76 &= ~ V_216 ;
V_76 |= V_189 -> V_84 . V_206 . V_215 ;
F_25 ( F_207 ( V_4 , 1 ) , V_76 ) ;
V_76 = F_34 ( F_207 ( V_4 , 2 ) ) ;
V_76 &= ~ V_214 ;
V_76 |= V_189 -> V_84 . V_206 . V_213 ;
F_25 ( F_207 ( V_4 , 2 ) , V_76 ) ;
V_76 = F_34 ( F_207 ( V_4 , 3 ) ) ;
V_76 &= ~ V_212 ;
V_76 |= V_189 -> V_84 . V_206 . V_211 ;
F_25 ( F_207 ( V_4 , 3 ) , V_76 ) ;
V_76 = F_34 ( F_207 ( V_4 , 6 ) ) ;
V_76 &= ~ V_440 ;
V_76 &= ~ V_441 ;
V_76 &= ~ V_442 ;
V_76 |= V_189 -> V_84 . V_206 . V_287 ;
F_25 ( F_207 ( V_4 , 6 ) , V_76 ) ;
V_76 = F_34 ( F_207 ( V_4 , 8 ) ) ;
V_76 &= ~ V_443 ;
V_76 |= V_189 -> V_84 . V_206 . V_288 ;
F_25 ( F_207 ( V_4 , 8 ) , V_76 ) ;
V_76 = F_34 ( F_207 ( V_4 , 9 ) ) ;
V_76 &= ~ V_444 ;
V_76 |= V_189 -> V_84 . V_206 . V_289 ;
F_25 ( F_207 ( V_4 , 9 ) , V_76 ) ;
V_76 = F_34 ( F_207 ( V_4 , 10 ) ) ;
V_76 &= ~ V_293 ;
V_76 &= ~ V_445 ;
V_76 |= V_189 -> V_84 . V_206 . V_291 ;
F_25 ( F_207 ( V_4 , 10 ) , V_76 ) ;
V_76 = F_34 ( F_205 ( V_4 ) ) ;
V_76 |= V_446 ;
F_25 ( F_205 ( V_4 ) , V_76 ) ;
V_76 &= ~ V_295 ;
V_76 |= V_189 -> V_84 . V_206 . V_294 ;
F_25 ( F_205 ( V_4 ) , V_76 ) ;
V_76 = F_34 ( F_204 ( V_4 ) ) ;
V_76 |= V_447 ;
F_25 ( F_204 ( V_4 ) , V_76 ) ;
F_44 ( F_204 ( V_4 ) ) ;
if ( F_208 ( ( F_34 ( F_204 ( V_4 ) ) &
V_448 ) , 200 ) )
F_35 ( L_26 , V_4 ) ;
V_76 = F_34 ( F_209 ( V_4 ) ) ;
V_76 &= ~ V_449 ;
V_76 &= ~ V_297 ;
V_76 |= V_189 -> V_84 . V_206 . V_296 ;
F_25 ( F_210 ( V_4 ) , V_76 ) ;
}
static void F_211 ( struct V_27 * V_28 ,
struct V_202 * V_189 )
{
enum V_4 V_4 = (enum V_4 ) V_189 -> V_236 ;
T_4 V_76 ;
V_76 = F_34 ( F_204 ( V_4 ) ) ;
V_76 &= ~ V_447 ;
F_25 ( F_204 ( V_4 ) , V_76 ) ;
F_44 ( F_204 ( V_4 ) ) ;
}
static bool F_212 ( struct V_27 * V_28 ,
struct V_202 * V_189 ,
struct V_203 * V_206 )
{
enum V_4 V_4 = (enum V_4 ) V_189 -> V_236 ;
T_4 V_188 ;
bool V_105 ;
if ( ! F_126 ( V_28 , V_401 ) )
return false ;
V_105 = false ;
V_188 = F_34 ( F_204 ( V_4 ) ) ;
if ( ! ( V_188 & V_447 ) )
goto V_341;
V_206 -> V_218 = F_34 ( F_206 ( V_4 ) ) ;
V_206 -> V_218 &= V_219 | V_221 ;
V_206 -> V_294 = F_34 ( F_205 ( V_4 ) ) ;
V_206 -> V_294 &= V_295 ;
V_206 -> V_209 = F_34 ( F_207 ( V_4 , 0 ) ) ;
V_206 -> V_209 &= V_210 ;
V_206 -> V_215 = F_34 ( F_207 ( V_4 , 1 ) ) ;
V_206 -> V_215 &= V_216 ;
V_206 -> V_213 = F_34 ( F_207 ( V_4 , 2 ) ) ;
V_206 -> V_213 &= V_214 ;
V_206 -> V_211 = F_34 ( F_207 ( V_4 , 3 ) ) ;
V_206 -> V_211 &= V_212 ;
V_206 -> V_287 = F_34 ( F_207 ( V_4 , 6 ) ) ;
V_206 -> V_287 &= V_440 |
V_441 |
V_442 ;
V_206 -> V_288 = F_34 ( F_207 ( V_4 , 8 ) ) ;
V_206 -> V_288 &= V_443 ;
V_206 -> V_289 = F_34 ( F_207 ( V_4 , 9 ) ) ;
V_206 -> V_289 &= V_444 ;
V_206 -> V_291 = F_34 ( F_207 ( V_4 , 10 ) ) ;
V_206 -> V_291 &= V_293 |
V_445 ;
V_206 -> V_296 = F_34 ( F_209 ( V_4 ) ) ;
if ( F_34 ( F_213 ( V_4 ) ) != V_206 -> V_296 )
F_90 ( L_27 ,
V_206 -> V_296 ,
F_34 ( F_213 ( V_4 ) ) ) ;
V_206 -> V_296 &= V_449 | V_297 ;
V_105 = true ;
V_341:
F_127 ( V_28 , V_401 ) ;
return V_105 ;
}
static void F_214 ( struct V_27 * V_28 )
{
int V_38 ;
V_28 -> V_402 = 3 ;
for ( V_38 = 0 ; V_38 < V_28 -> V_402 ; V_38 ++ ) {
V_28 -> V_205 [ V_38 ] . V_236 = V_38 ;
V_28 -> V_205 [ V_38 ] . V_403 = V_450 [ V_38 ] ;
V_28 -> V_205 [ V_38 ] . V_405 = F_211 ;
V_28 -> V_205 [ V_38 ] . V_372 = F_203 ;
V_28 -> V_205 [ V_38 ] . V_340 =
F_212 ;
}
}
void F_215 ( struct V_20 * V_21 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
T_4 V_188 = F_34 ( V_451 ) ;
if ( F_19 ( V_21 ) || F_20 ( V_21 ) )
F_187 ( V_28 ) ;
else if ( F_17 ( V_21 ) )
F_214 ( V_28 ) ;
else
F_181 ( V_28 ) ;
if ( F_19 ( V_21 ) || F_20 ( V_21 ) ) {
int V_452 ;
V_452 = V_28 -> V_453 . V_454 ( V_21 ) ;
V_28 -> V_455 = V_452 ;
if ( F_216 ( V_28 ) )
F_52 ( L_28 ) ;
if ( ! ( F_34 ( V_456 ) & V_409 ) )
F_35 ( L_29 ) ;
} else if ( F_17 ( V_21 ) ) {
F_217 ( V_21 ) ;
F_200 ( V_21 ) ;
} else {
if ( V_188 & V_457 )
F_35 ( L_30 ) ;
if ( V_188 & V_458 )
F_35 ( L_31 ) ;
}
}
void F_218 ( struct V_101 * V_101 )
{
struct V_2 * V_16 = F_146 ( V_101 ) ;
struct V_27 * V_28 =
F_148 ( V_16 -> V_7 . V_7 . V_21 ) ;
enum V_4 V_4 = V_16 -> V_4 ;
T_4 V_188 ;
bool V_396 = false ;
if ( F_34 ( F_47 ( V_4 ) ) & V_92 ) {
V_188 = F_34 ( F_32 ( V_4 ) ) ;
if ( V_188 & V_93 ) {
V_188 &= ~ V_93 ;
F_25 ( F_32 ( V_4 ) , V_188 ) ;
V_396 = true ;
}
V_188 = F_34 ( F_47 ( V_4 ) ) ;
V_188 &= ~ ( V_92 | V_99 ) ;
V_188 |= V_91 ;
F_25 ( F_47 ( V_4 ) , V_188 ) ;
F_44 ( F_47 ( V_4 ) ) ;
if ( V_396 )
F_31 ( V_28 , V_4 ) ;
}
V_188 = V_92 |
V_91 | V_459 ;
if ( V_101 -> V_329 )
V_188 |= V_460 ;
else {
V_188 |= V_461 ;
if ( F_219 ( V_101 -> V_462 ) )
V_188 |= V_90 ;
}
F_25 ( F_47 ( V_4 ) , V_188 ) ;
F_44 ( F_47 ( V_4 ) ) ;
V_101 -> V_102 |= V_93 ;
F_25 ( F_32 ( V_4 ) , V_101 -> V_102 ) ;
F_44 ( F_32 ( V_4 ) ) ;
F_33 ( 600 ) ;
}
void F_220 ( struct V_73 * V_74 )
{
struct V_27 * V_28 = V_74 -> V_21 -> V_29 ;
struct V_1 * V_1 = F_56 ( V_74 ) ;
T_4 V_188 ;
F_161 ( V_1 ) ;
V_188 = F_34 ( F_43 ( V_78 ) ) ;
V_188 &= ~ V_94 ;
F_25 ( F_43 ( V_78 ) , V_188 ) ;
V_188 = F_34 ( F_39 ( V_78 ) ) ;
V_188 &= ~ ( V_96 | V_97 ) ;
V_188 |= F_40 ( 2 ) | F_41 ( 2 ) ;
F_25 ( F_39 ( V_78 ) , V_188 ) ;
V_188 = F_34 ( F_43 ( V_78 ) ) ;
V_188 &= ~ V_86 ;
F_25 ( F_43 ( V_78 ) , V_188 ) ;
V_188 = F_34 ( F_43 ( V_78 ) ) ;
V_188 &= ~ V_83 ;
F_25 ( F_43 ( V_78 ) , V_188 ) ;
}
bool F_221 ( struct V_27 * V_28 ,
struct V_75 * V_75 )
{
T_1 V_76 ;
if ( F_126 ( V_28 , V_399 ) ) {
V_76 = F_34 ( V_463 ) ;
F_127 ( V_28 , V_399 ) ;
if ( V_76 & F_222 ( V_75 -> V_107 ) )
return true ;
}
return false ;
}
void F_223 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
struct V_27 * V_28 = V_6 -> V_7 . V_21 -> V_29 ;
struct V_75 * V_75 = F_38 ( V_6 -> V_7 . V_74 ) ;
enum V_298 V_299 = V_167 -> V_299 ;
struct V_394 * V_394 ;
T_1 V_76 , V_311 = 0 ;
V_76 = F_34 ( F_120 ( V_299 ) ) ;
if ( V_76 & V_315 )
V_311 |= V_314 ;
else
V_311 |= V_464 ;
if ( V_76 & V_313 )
V_311 |= V_312 ;
else
V_311 |= V_465 ;
V_167 -> V_7 . V_177 . V_311 |= V_311 ;
switch ( V_76 & V_466 ) {
case V_307 :
V_167 -> V_175 = 18 ;
break;
case V_308 :
V_167 -> V_175 = 24 ;
break;
case V_309 :
V_167 -> V_175 = 30 ;
break;
case V_310 :
V_167 -> V_175 = 36 ;
break;
default:
break;
}
switch ( V_76 & V_342 ) {
case V_326 :
V_167 -> V_174 = true ;
V_394 = F_160 ( & V_6 -> V_7 ) ;
if ( V_394 -> V_467 ( & V_6 -> V_7 , V_167 ) )
V_167 -> V_468 = true ;
break;
case V_327 :
case V_328 :
break;
case V_331 :
case V_330 :
V_167 -> V_172 = true ;
V_167 -> V_104 =
( ( V_76 & V_469 ) >> V_470 ) + 1 ;
F_224 ( V_75 , V_167 ) ;
break;
default:
break;
}
V_167 -> V_398 =
F_221 ( V_28 , V_75 ) ;
if ( V_6 -> type == V_11 && V_28 -> V_45 . V_471 &&
V_167 -> V_175 > V_28 -> V_45 . V_471 ) {
F_52 ( L_32 ,
V_167 -> V_175 , V_28 -> V_45 . V_471 ) ;
V_28 -> V_45 . V_471 = V_167 -> V_175 ;
}
F_82 ( V_6 , V_167 ) ;
}
static void F_225 ( struct V_5 * V_6 )
{
F_226 ( V_6 ) ;
}
static bool F_227 ( struct V_1 * V_6 ,
struct V_108 * V_167 )
{
int type = V_6 -> type ;
int V_4 = F_5 ( V_6 ) ;
F_4 ( type == V_13 , L_33 ) ;
if ( V_4 == V_61 )
V_167 -> V_299 = V_316 ;
if ( type == V_12 )
return F_228 ( V_6 , V_167 ) ;
else
return F_229 ( V_6 , V_167 ) ;
}
static struct V_335 *
F_230 ( struct V_2 * V_16 )
{
struct V_335 * V_113 ;
enum V_4 V_4 = V_16 -> V_4 ;
V_113 = F_231 () ;
if ( ! V_113 )
return NULL ;
V_16 -> V_332 . V_472 = F_32 ( V_4 ) ;
if ( ! F_232 ( V_16 , V_113 ) ) {
F_233 ( V_113 ) ;
return NULL ;
}
return V_113 ;
}
static struct V_335 *
F_234 ( struct V_2 * V_16 )
{
struct V_335 * V_113 ;
enum V_4 V_4 = V_16 -> V_4 ;
V_113 = F_231 () ;
if ( ! V_113 )
return NULL ;
V_16 -> V_17 . V_18 = F_32 ( V_4 ) ;
F_235 ( V_16 , V_113 ) ;
return V_113 ;
}
void F_236 ( struct V_20 * V_21 , enum V_4 V_4 )
{
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_2 * V_16 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
bool V_473 , V_474 ;
V_473 = ( V_28 -> V_45 . V_46 [ V_4 ] . V_475 ||
V_28 -> V_45 . V_46 [ V_4 ] . V_36 ) ;
V_474 = V_28 -> V_45 . V_46 [ V_4 ] . V_476 ;
if ( ! V_474 && ! V_473 ) {
F_52 ( L_34 ,
F_36 ( V_4 ) ) ;
return;
}
V_16 = F_237 ( sizeof( * V_16 ) , V_477 ) ;
if ( ! V_16 )
return;
V_1 = & V_16 -> V_7 ;
V_6 = & V_1 -> V_7 ;
F_238 ( V_21 , V_6 , & V_478 ,
V_479 , NULL ) ;
V_1 -> V_480 = F_227 ;
V_1 -> V_372 = F_164 ;
V_1 -> V_481 = F_154 ;
V_1 -> V_405 = F_170 ;
V_1 -> V_482 = F_161 ;
V_1 -> V_340 = F_128 ;
V_1 -> V_483 = F_223 ;
V_16 -> V_4 = V_4 ;
V_16 -> V_103 = F_34 ( F_32 ( V_4 ) ) &
( V_484 |
V_485 ) ;
if ( F_17 ( V_21 ) && V_4 == V_61 ) {
if ( ! ( V_16 -> V_103 & V_485 ) ) {
F_52 ( L_35 ) ;
V_16 -> V_103 |= V_485 ;
}
}
V_1 -> type = V_13 ;
V_1 -> V_240 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_1 -> V_486 = 0 ;
if ( V_474 ) {
if ( ! F_230 ( V_16 ) )
goto V_487;
V_16 -> V_488 = V_489 ;
if ( F_239 ( V_21 , 0 , V_490 ) && V_4 == V_62 )
V_28 -> V_491 . V_492 [ V_61 ] = V_16 ;
else
V_28 -> V_491 . V_492 [ V_4 ] = V_16 ;
}
if ( V_1 -> type != V_11 && V_473 ) {
if ( ! F_234 ( V_16 ) )
goto V_487;
}
return;
V_487:
F_240 ( V_6 ) ;
F_233 ( V_16 ) ;
}
