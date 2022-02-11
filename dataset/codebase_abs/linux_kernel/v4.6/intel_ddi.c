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
static const struct V_16 *
F_6 ( struct V_17 * V_18 , int * V_19 )
{
if ( F_7 ( V_18 ) || F_8 ( V_18 ) ) {
* V_19 = F_9 ( V_20 ) ;
return V_20 ;
} else if ( F_10 ( V_18 ) || F_11 ( V_18 ) ) {
* V_19 = F_9 ( V_21 ) ;
return V_21 ;
} else {
* V_19 = F_9 ( V_22 ) ;
return V_22 ;
}
}
static const struct V_16 *
F_12 ( struct V_17 * V_18 , int * V_19 )
{
if ( V_18 -> V_23 ) {
if ( F_7 ( V_18 ) || F_8 ( V_18 ) ) {
* V_19 = F_9 ( V_24 ) ;
return V_24 ;
} else if ( F_10 ( V_18 ) || F_11 ( V_18 ) ) {
* V_19 = F_9 ( V_25 ) ;
return V_25 ;
} else {
* V_19 = F_9 ( V_26 ) ;
return V_26 ;
}
}
return F_6 ( V_18 , V_19 ) ;
}
static const struct V_16 *
F_13 ( struct V_17 * V_18 , int * V_19 )
{
if ( F_7 ( V_18 ) || F_8 ( V_18 ) ) {
* V_19 = F_9 ( V_27 ) ;
return V_27 ;
} else {
* V_19 = F_9 ( V_28 ) ;
return V_28 ;
}
}
void F_14 ( struct V_1 * V_6 )
{
struct V_17 * V_18 = F_15 ( V_6 -> V_7 . V_29 ) ;
T_1 V_30 = 0 ;
int V_31 , V_32 , V_33 , V_34 , V_35 ,
V_36 ;
int V_37 ;
enum V_4 V_4 ;
const struct V_16 * V_38 ;
const struct V_16 * V_39 ;
const struct V_16 * V_40 ;
const struct V_16 * V_41 ;
const struct V_16 * V_42 ;
V_4 = F_5 ( V_6 ) ;
V_37 = V_18 -> V_43 . V_44 [ V_4 ] . V_45 ;
if ( F_16 ( V_18 ) ) {
if ( V_6 -> type != V_12 )
return;
F_17 ( V_18 , V_37 , V_4 ,
V_12 ) ;
return;
}
if ( F_18 ( V_18 ) || F_19 ( V_18 ) ) {
V_38 = NULL ;
V_39 =
F_6 ( V_18 , & V_33 ) ;
V_40 =
F_12 ( V_18 , & V_34 ) ;
V_41 =
F_13 ( V_18 , & V_32 ) ;
V_35 = 8 ;
if ( V_18 -> V_43 . V_44 [ V_4 ] . V_46 ||
V_18 -> V_43 . V_44 [ V_4 ] . V_47 )
V_30 = 1 << 31 ;
if ( F_20 ( V_6 -> type == V_11 &&
V_4 != V_48 && V_4 != V_15 &&
V_34 > 9 ) )
V_34 = 9 ;
} else if ( F_21 ( V_18 ) ) {
V_38 = V_49 ;
V_39 = V_50 ;
if ( V_18 -> V_23 ) {
V_40 = V_51 ;
V_34 = F_9 ( V_51 ) ;
} else {
V_40 = V_50 ;
V_34 = F_9 ( V_50 ) ;
}
V_41 = V_52 ;
V_33 = F_9 ( V_50 ) ;
V_32 = F_9 ( V_52 ) ;
V_35 = 7 ;
} else if ( F_22 ( V_18 ) ) {
V_38 = V_53 ;
V_39 = V_54 ;
V_40 = V_54 ;
V_41 = V_55 ;
V_33 = V_34 = F_9 ( V_54 ) ;
V_32 = F_9 ( V_55 ) ;
V_35 = 6 ;
} else {
F_4 ( 1 , L_2 ) ;
V_40 = V_50 ;
V_38 = V_49 ;
V_39 = V_50 ;
V_41 = V_52 ;
V_34 = F_9 ( V_51 ) ;
V_33 = F_9 ( V_50 ) ;
V_32 = F_9 ( V_52 ) ;
V_35 = 7 ;
}
switch ( V_6 -> type ) {
case V_11 :
V_42 = V_40 ;
V_36 = V_34 ;
break;
case V_10 :
case V_12 :
V_42 = V_39 ;
V_36 = V_33 ;
break;
case V_14 :
V_42 = V_38 ;
V_36 = V_33 ;
break;
default:
F_23 () ;
}
for ( V_31 = 0 ; V_31 < V_36 ; V_31 ++ ) {
F_24 ( F_25 ( V_4 , V_31 ) ,
V_42 [ V_31 ] . V_56 | V_30 ) ;
F_24 ( F_26 ( V_4 , V_31 ) ,
V_42 [ V_31 ] . V_57 ) ;
}
if ( V_6 -> type != V_12 )
return;
if ( V_37 == V_58 ||
V_37 >= V_32 )
V_37 = V_35 ;
F_24 ( F_25 ( V_4 , V_31 ) ,
V_41 [ V_37 ] . V_56 | V_30 ) ;
F_24 ( F_26 ( V_4 , V_31 ) ,
V_41 [ V_37 ] . V_57 ) ;
}
static void F_27 ( struct V_17 * V_18 ,
enum V_4 V_4 )
{
T_2 V_59 = F_28 ( V_4 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < 16 ; V_31 ++ ) {
F_29 ( 1 ) ;
if ( F_30 ( V_59 ) & V_60 )
return;
}
F_31 ( L_3 , F_32 ( V_4 ) ) ;
}
void F_33 ( struct V_61 * V_62 )
{
struct V_63 * V_29 = V_62 -> V_29 ;
struct V_17 * V_18 = V_29 -> V_64 ;
struct V_65 * V_65 = F_34 ( V_62 ) ;
struct V_1 * V_6 ;
T_1 V_66 , V_31 , V_67 ;
F_35 (dev, crtc, encoder) {
F_20 ( V_6 -> type != V_14 ) ;
F_14 ( V_6 ) ;
}
F_24 ( F_36 ( V_68 ) , F_37 ( 2 ) |
F_38 ( 2 ) |
V_69 | V_70 ) ;
V_67 = V_18 -> V_71 | V_72 |
V_73 |
F_39 ( V_65 -> V_74 -> V_75 ) ;
F_24 ( F_40 ( V_68 ) , V_67 ) ;
F_41 ( F_40 ( V_68 ) ) ;
F_29 ( 220 ) ;
V_67 |= V_76 ;
F_24 ( F_40 ( V_68 ) , V_67 ) ;
F_24 ( F_42 ( V_15 ) , V_65 -> V_74 -> V_77 ) ;
F_20 ( V_65 -> V_74 -> V_77 != V_78 ) ;
for ( V_31 = 0 ; V_31 < F_9 ( V_53 ) * 2 ; V_31 ++ ) {
F_24 ( F_43 ( V_15 ) ,
V_79 |
V_80 |
V_81 |
V_82 ) ;
F_24 ( F_28 ( V_15 ) ,
V_83 |
( ( V_65 -> V_74 -> V_75 - 1 ) << 1 ) |
F_44 ( V_31 / 2 ) ) ;
F_41 ( F_28 ( V_15 ) ) ;
F_29 ( 600 ) ;
F_24 ( F_45 ( V_68 ) , F_46 ( 64 ) ) ;
V_67 |= V_84 | V_85 ;
F_24 ( F_40 ( V_68 ) , V_67 ) ;
F_41 ( F_40 ( V_68 ) ) ;
F_29 ( 30 ) ;
V_66 = F_30 ( F_36 ( V_68 ) ) ;
V_66 &= ~ ( V_86 | V_87 ) ;
F_24 ( F_36 ( V_68 ) , V_66 ) ;
F_41 ( F_36 ( V_68 ) ) ;
F_29 ( 5 ) ;
V_66 = F_30 ( F_47 ( V_15 ) ) ;
if ( V_66 & V_88 ) {
F_48 ( L_4 , V_31 ) ;
break;
}
if ( V_31 == F_9 ( V_53 ) * 2 - 1 ) {
F_31 ( L_5 ) ;
break;
}
V_66 = F_30 ( F_28 ( V_15 ) ) ;
V_66 &= ~ V_83 ;
F_24 ( F_28 ( V_15 ) , V_66 ) ;
F_41 ( F_28 ( V_15 ) ) ;
V_66 = F_30 ( F_43 ( V_15 ) ) ;
V_66 &= ~ ( V_82 | V_89 ) ;
V_66 |= V_81 ;
F_24 ( F_43 ( V_15 ) , V_66 ) ;
F_41 ( F_43 ( V_15 ) ) ;
F_27 ( V_18 , V_15 ) ;
V_67 &= ~ V_84 ;
F_24 ( F_40 ( V_68 ) , V_67 ) ;
F_41 ( F_40 ( V_68 ) ) ;
V_66 = F_30 ( F_36 ( V_68 ) ) ;
V_66 &= ~ ( V_86 | V_87 ) ;
V_66 |= F_37 ( 2 ) | F_38 ( 2 ) ;
F_24 ( F_36 ( V_68 ) , V_66 ) ;
F_41 ( F_36 ( V_68 ) ) ;
}
F_24 ( F_43 ( V_15 ) ,
V_79 |
V_90 |
V_80 |
V_82 ) ;
}
void F_49 ( struct V_1 * V_6 )
{
struct V_91 * V_91 = F_50 ( & V_6 -> V_7 ) ;
struct V_2 * V_92 =
F_3 ( & V_6 -> V_7 ) ;
V_91 -> V_93 = V_92 -> V_94 |
V_83 | F_44 ( 0 ) ;
V_91 -> V_93 |= F_51 ( V_91 -> V_95 ) ;
}
static struct V_1 *
F_52 ( struct V_61 * V_62 )
{
struct V_63 * V_29 = V_62 -> V_29 ;
struct V_65 * V_65 = F_34 ( V_62 ) ;
struct V_1 * V_1 , * V_96 = NULL ;
int V_97 = 0 ;
F_35 (dev, crtc, intel_encoder) {
V_96 = V_1 ;
V_97 ++ ;
}
if ( V_97 != 1 )
F_4 ( 1 , L_6 , V_97 ,
F_53 ( V_65 -> V_98 ) ) ;
F_54 ( V_96 == NULL ) ;
return V_96 ;
}
struct V_1 *
F_55 ( struct V_99 * V_100 )
{
struct V_65 * V_62 = F_34 ( V_100 -> V_7 . V_62 ) ;
struct V_1 * V_96 = NULL ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_97 = 0 ;
int V_31 ;
V_102 = V_100 -> V_7 . V_102 ;
F_56 (state, connector, connector_state, i) {
if ( V_106 -> V_62 != V_100 -> V_7 . V_62 )
continue;
V_96 = F_57 ( V_106 -> V_107 ) ;
V_97 ++ ;
}
F_4 ( V_97 != 1 , L_6 , V_97 ,
F_53 ( V_62 -> V_98 ) ) ;
F_54 ( V_96 == NULL ) ;
return V_96 ;
}
static unsigned F_58 ( int clock )
{
unsigned V_108 ;
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
V_108 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_108 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_108 = 2000 ;
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
V_108 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_108 = 5000 ;
break;
default:
V_108 = 1000 ;
break;
}
return V_108 ;
}
static void F_59 ( T_3 V_109 , unsigned V_108 ,
unsigned V_110 , unsigned V_111 , unsigned V_112 ,
struct V_113 * V_114 )
{
T_3 V_115 , V_116 , V_117 , V_118 , V_119 , V_120 ;
if ( V_114 -> V_112 == 0 ) {
V_114 -> V_112 = V_112 ;
V_114 -> V_111 = V_111 ;
V_114 -> V_110 = V_110 ;
return;
}
V_115 = V_109 * V_108 * V_112 * V_110 ;
V_116 = V_109 * V_108 * V_114 -> V_112 * V_114 -> V_110 ;
V_119 = F_60 ( V_109 * V_112 * V_110 , V_121 * V_111 ) ;
V_120 = F_60 ( V_109 * V_114 -> V_112 * V_114 -> V_110 ,
V_121 * V_114 -> V_111 ) ;
V_117 = 1000000 * V_119 ;
V_118 = 1000000 * V_120 ;
if ( V_115 < V_117 && V_116 < V_118 ) {
if ( V_114 -> V_112 * V_114 -> V_110 * V_119 < V_112 * V_110 * V_120 ) {
V_114 -> V_112 = V_112 ;
V_114 -> V_111 = V_111 ;
V_114 -> V_110 = V_110 ;
}
} else if ( V_115 >= V_117 && V_116 < V_118 ) {
V_114 -> V_112 = V_112 ;
V_114 -> V_111 = V_111 ;
V_114 -> V_110 = V_110 ;
} else if ( V_115 >= V_117 && V_116 >= V_118 ) {
if ( V_111 * V_114 -> V_110 * V_114 -> V_110 > V_114 -> V_111 * V_110 * V_110 ) {
V_114 -> V_112 = V_112 ;
V_114 -> V_111 = V_111 ;
V_114 -> V_110 = V_110 ;
}
}
}
static int F_61 ( struct V_17 * V_18 ,
T_2 V_59 )
{
int V_122 = V_123 ;
int V_124 , V_112 , V_125 ;
T_1 V_126 ;
V_126 = F_30 ( V_59 ) ;
switch ( V_126 & V_127 ) {
case V_128 :
case V_129 :
V_122 = 135 ;
break;
case V_130 :
V_122 = V_123 ;
break;
default:
F_4 ( 1 , L_7 ) ;
return 0 ;
}
V_125 = V_126 & V_131 ;
V_112 = ( V_126 & V_132 ) >> V_133 ;
V_124 = ( V_126 & V_134 ) >> V_135 ;
return ( V_122 * V_124 * 100 ) / ( V_112 * V_125 ) ;
}
static int F_62 ( struct V_17 * V_18 ,
T_4 V_136 )
{
T_2 V_137 , V_138 ;
T_4 V_139 , V_140 ;
T_4 V_141 , V_142 , V_143 , V_144 ;
V_137 = F_63 ( V_136 ) ;
V_138 = F_64 ( V_136 ) ;
V_139 = F_30 ( V_137 ) ;
V_140 = F_30 ( V_138 ) ;
V_141 = V_140 & V_145 ;
V_143 = V_140 & V_146 ;
if ( V_140 & F_65 ( 1 ) )
V_142 = ( V_140 & V_147 ) >> 8 ;
else
V_142 = 1 ;
switch ( V_141 ) {
case V_148 :
V_141 = 1 ;
break;
case V_149 :
V_141 = 2 ;
break;
case V_150 :
V_141 = 3 ;
break;
case V_151 :
V_141 = 7 ;
break;
}
switch ( V_143 ) {
case V_152 :
V_143 = 5 ;
break;
case V_153 :
V_143 = 2 ;
break;
case V_154 :
V_143 = 3 ;
break;
case V_155 :
V_143 = 1 ;
break;
}
V_144 = ( V_139 & V_156 ) * 24 * 1000 ;
V_144 += ( ( ( V_139 & V_157 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_144 / ( V_141 * V_142 * V_143 * 5 ) ;
}
static void F_66 ( struct V_99 * V_158 )
{
int V_159 ;
if ( V_158 -> V_160 )
V_159 = F_67 ( V_158 -> V_161 ,
& V_158 -> V_162 ) ;
else if ( V_158 -> V_163 )
V_159 = F_67 ( V_158 -> V_161 ,
& V_158 -> V_164 ) ;
else if ( V_158 -> V_165 && V_158 -> V_166 == 36 )
V_159 = V_158 -> V_161 * 2 / 3 ;
else
V_159 = V_158 -> V_161 ;
if ( V_158 -> V_167 )
V_159 /= V_158 -> V_167 ;
V_158 -> V_7 . V_168 . V_169 = V_159 ;
}
static void F_68 ( struct V_1 * V_6 ,
struct V_99 * V_158 )
{
struct V_17 * V_18 = V_6 -> V_7 . V_29 -> V_64 ;
int V_170 = 0 ;
T_4 V_171 , V_136 ;
V_136 = V_158 -> V_77 ;
V_171 = F_30 ( V_172 ) ;
if ( V_171 & F_69 ( V_136 ) ) {
V_170 = F_62 ( V_18 , V_136 ) ;
} else {
V_170 = V_171 & F_70 ( V_136 ) ;
V_170 >>= F_71 ( V_136 ) ;
switch ( V_170 ) {
case V_173 :
V_170 = 81000 ;
break;
case V_174 :
V_170 = 108000 ;
break;
case V_175 :
V_170 = 135000 ;
break;
case V_176 :
V_170 = 162000 ;
break;
case V_177 :
V_170 = 216000 ;
break;
case V_178 :
V_170 = 270000 ;
break;
default:
F_4 ( 1 , L_8 ) ;
break;
}
V_170 *= 2 ;
}
V_158 -> V_161 = V_170 ;
F_66 ( V_158 ) ;
}
static void F_72 ( struct V_1 * V_6 ,
struct V_99 * V_158 )
{
struct V_17 * V_18 = V_6 -> V_7 . V_29 -> V_64 ;
int V_170 = 0 ;
T_1 V_179 , V_180 ;
V_179 = V_158 -> V_77 ;
switch ( V_179 & V_181 ) {
case V_182 :
V_170 = 81000 ;
break;
case V_183 :
V_170 = 135000 ;
break;
case V_184 :
V_170 = 270000 ;
break;
case V_185 :
V_170 = F_61 ( V_18 , F_73 ( 0 ) ) ;
break;
case V_186 :
V_170 = F_61 ( V_18 , F_73 ( 1 ) ) ;
break;
case V_78 :
V_180 = F_30 ( V_187 ) & V_188 ;
if ( V_180 == V_189 )
V_170 = 81000 ;
else if ( V_180 == V_190 )
V_170 = 135000 ;
else if ( V_180 == V_191 )
V_170 = 270000 ;
else {
F_4 ( 1 , L_9 ) ;
return;
}
break;
default:
F_4 ( 1 , L_10 ) ;
return;
}
V_158 -> V_161 = V_170 * 2 ;
F_66 ( V_158 ) ;
}
static int F_74 ( struct V_17 * V_18 ,
enum V_192 V_136 )
{
struct V_193 * V_180 ;
struct V_194 * V_102 ;
T_5 clock ;
if ( F_20 ( V_136 == V_195 ) )
return 0 ;
V_180 = & V_18 -> V_196 [ V_136 ] ;
V_102 = & V_180 -> V_74 . V_197 ;
clock . V_198 = 2 ;
clock . V_199 = ( V_102 -> V_200 & V_201 ) << 22 ;
if ( V_102 -> V_202 & V_203 )
clock . V_199 |= V_102 -> V_204 & V_205 ;
clock . V_124 = ( V_102 -> V_206 & V_207 ) >> V_208 ;
clock . V_142 = ( V_102 -> V_209 & V_210 ) >> V_211 ;
clock . V_143 = ( V_102 -> V_209 & V_212 ) >> V_213 ;
return F_75 ( 100000 , & clock ) ;
}
static void F_76 ( struct V_1 * V_6 ,
struct V_99 * V_158 )
{
struct V_17 * V_18 = V_6 -> V_7 . V_29 -> V_64 ;
enum V_4 V_4 = F_5 ( V_6 ) ;
T_4 V_136 = V_4 ;
V_158 -> V_161 = F_74 ( V_18 , V_136 ) ;
F_66 ( V_158 ) ;
}
void F_77 ( struct V_1 * V_6 ,
struct V_99 * V_158 )
{
struct V_63 * V_29 = V_6 -> V_7 . V_29 ;
if ( F_78 ( V_29 ) -> V_214 <= 8 )
F_72 ( V_6 , V_158 ) ;
else if ( F_18 ( V_29 ) || F_19 ( V_29 ) )
F_68 ( V_6 , V_158 ) ;
else if ( F_16 ( V_29 ) )
F_76 ( V_6 , V_158 ) ;
}
static void
F_79 ( int clock ,
unsigned * V_215 , unsigned * V_216 , unsigned * V_217 )
{
T_3 V_109 ;
unsigned V_112 , V_111 , V_110 ;
struct V_113 V_114 = { 0 , 0 , 0 } ;
unsigned V_108 ;
V_109 = clock / 100 ;
V_108 = F_58 ( clock ) ;
if ( V_109 == 5400000 ) {
* V_216 = 2 ;
* V_217 = 1 ;
* V_215 = 2 ;
return;
}
for ( V_110 = V_123 * 2 / V_218 + 1 ;
V_110 <= V_123 * 2 / V_219 ;
V_110 ++ ) {
for ( V_111 = V_220 * V_110 / V_123 + 1 ;
V_111 <= V_221 * V_110 / V_123 ;
V_111 ++ ) {
for ( V_112 = V_222 ; V_112 <= V_223 ; V_112 += V_224 )
F_59 ( V_109 , V_108 ,
V_110 , V_111 , V_112 , & V_114 ) ;
}
}
* V_216 = V_114 . V_111 ;
* V_217 = V_114 . V_112 ;
* V_215 = V_114 . V_110 ;
}
static bool
F_80 ( struct V_65 * V_65 ,
struct V_99 * V_100 ,
struct V_1 * V_1 )
{
int clock = V_100 -> V_161 ;
if ( V_1 -> type == V_12 ) {
struct V_193 * V_180 ;
T_4 V_179 ;
unsigned V_112 , V_111 , V_110 ;
F_79 ( clock * 1000 , & V_110 , & V_111 , & V_112 ) ;
V_179 = V_225 | V_130 |
F_81 ( V_110 ) | F_82 ( V_111 ) |
F_83 ( V_112 ) ;
memset ( & V_100 -> V_226 , 0 ,
sizeof( V_100 -> V_226 ) ) ;
V_100 -> V_226 . V_126 = V_179 ;
V_180 = F_84 ( V_65 , V_100 ) ;
if ( V_180 == NULL ) {
F_85 ( L_11 ,
F_53 ( V_65 -> V_98 ) ) ;
return false ;
}
V_100 -> V_77 = F_86 ( V_180 -> V_227 ) ;
} else if ( V_100 -> V_77 == V_78 ) {
struct V_101 * V_102 = V_100 -> V_7 . V_102 ;
struct V_228 * V_229 =
& F_87 ( V_102 ) [ V_230 ] ;
if ( V_229 -> V_231 &&
F_20 ( V_229 -> V_197 . V_229 != V_100 -> V_226 . V_229 ) )
return false ;
V_100 -> V_232 = V_230 ;
V_229 -> V_197 . V_229 = V_100 -> V_226 . V_229 ;
V_229 -> V_231 |= 1 << V_65 -> V_98 ;
}
return true ;
}
static void F_88 ( struct V_233 * V_234 )
{
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
V_234 -> V_235 = V_236 ;
}
static void F_89 ( struct V_233 * V_234 ,
T_3 V_237 ,
T_3 V_144 ,
unsigned int V_238 )
{
T_3 V_239 ;
V_239 = F_90 ( 10000 * F_60 ( V_144 , V_237 ) ,
V_237 ) ;
if ( V_144 >= V_237 ) {
if ( V_239 < V_240 &&
V_239 < V_234 -> V_235 ) {
V_234 -> V_235 = V_239 ;
V_234 -> V_237 = V_237 ;
V_234 -> V_144 = V_144 ;
V_234 -> V_112 = V_238 ;
}
} else if ( V_239 < V_241 &&
V_239 < V_234 -> V_235 ) {
V_234 -> V_235 = V_239 ;
V_234 -> V_237 = V_237 ;
V_234 -> V_144 = V_144 ;
V_234 -> V_112 = V_238 ;
}
}
static void F_91 ( unsigned int V_112 ,
unsigned int * V_141 ,
unsigned int * V_142 ,
unsigned int * V_143 )
{
if ( V_112 % 2 == 0 ) {
unsigned int V_242 = V_112 / 2 ;
if ( V_242 == 1 || V_242 == 2 || V_242 == 3 || V_242 == 5 ) {
* V_141 = 2 ;
* V_142 = 1 ;
* V_143 = V_242 ;
} else if ( V_242 % 2 == 0 ) {
* V_141 = 2 ;
* V_142 = V_242 / 2 ;
* V_143 = 2 ;
} else if ( V_242 % 3 == 0 ) {
* V_141 = 3 ;
* V_142 = V_242 / 3 ;
* V_143 = 2 ;
} else if ( V_242 % 7 == 0 ) {
* V_141 = 7 ;
* V_142 = V_242 / 7 ;
* V_143 = 2 ;
}
} else if ( V_112 == 3 || V_112 == 9 ) {
* V_141 = 3 ;
* V_142 = 1 ;
* V_143 = V_112 / 3 ;
} else if ( V_112 == 5 || V_112 == 7 ) {
* V_141 = V_112 ;
* V_142 = 1 ;
* V_143 = 1 ;
} else if ( V_112 == 15 ) {
* V_141 = 3 ;
* V_142 = 1 ;
* V_143 = 5 ;
} else if ( V_112 == 21 ) {
* V_141 = 7 ;
* V_142 = 1 ;
* V_143 = 3 ;
} else if ( V_112 == 35 ) {
* V_141 = 7 ;
* V_142 = 1 ;
* V_143 = 5 ;
}
}
static void F_92 ( struct V_243 * V_244 ,
T_3 V_245 ,
T_3 V_237 ,
T_4 V_141 , T_4 V_142 , T_4 V_143 )
{
T_3 V_144 ;
switch ( V_237 ) {
case 9600000000ULL :
V_244 -> V_237 = 0 ;
break;
case 9000000000ULL :
V_244 -> V_237 = 1 ;
break;
case 8400000000ULL :
V_244 -> V_237 = 3 ;
}
switch ( V_141 ) {
case 1 :
V_244 -> V_246 = 0 ;
break;
case 2 :
V_244 -> V_246 = 1 ;
break;
case 3 :
V_244 -> V_246 = 2 ;
break;
case 7 :
V_244 -> V_246 = 4 ;
break;
default:
F_4 ( 1 , L_12 ) ;
}
switch ( V_143 ) {
case 5 :
V_244 -> V_247 = 0 ;
break;
case 2 :
V_244 -> V_247 = 1 ;
break;
case 3 :
V_244 -> V_247 = 2 ;
break;
case 1 :
V_244 -> V_247 = 3 ;
break;
default:
F_4 ( 1 , L_13 ) ;
}
V_244 -> V_248 = V_142 ;
V_244 -> V_249 = ( V_244 -> V_248 == 1 ) ? 0 : 1 ;
V_144 = V_141 * V_142 * V_143 * V_245 ;
V_244 -> V_250 = F_93 ( V_144 , 24 * F_94 ( 1 ) ) ;
V_244 -> V_251 =
F_93 ( ( F_93 ( V_144 , 24 ) -
V_244 -> V_250 * F_94 ( 1 ) ) * 0x8000 , F_94 ( 1 ) ) ;
}
static bool
F_95 ( int clock ,
struct V_243 * V_252 )
{
T_3 V_245 = clock * 5 ;
T_3 V_253 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
static const int V_254 [] = { 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 ,
24 , 28 , 30 , 32 , 36 , 40 , 42 , 44 ,
48 , 52 , 54 , 56 , 60 , 64 , 66 , 68 ,
70 , 72 , 76 , 78 , 80 , 84 , 88 , 90 ,
92 , 96 , 98 } ;
static const int V_255 [] = { 3 , 5 , 7 , 9 , 15 , 21 , 35 } ;
static const struct {
const int * V_256 ;
int V_257 ;
} V_258 [] = {
{ V_254 , F_9 (even_dividers) } ,
{ V_255 , F_9 (odd_dividers) } ,
} ;
struct V_233 V_234 ;
unsigned int V_259 , V_118 , V_31 ;
unsigned int V_141 , V_142 , V_143 ;
F_88 ( & V_234 ) ;
for ( V_118 = 0 ; V_118 < F_9 ( V_258 ) ; V_118 ++ ) {
for ( V_259 = 0 ; V_259 < F_9 ( V_253 ) ; V_259 ++ ) {
for ( V_31 = 0 ; V_31 < V_258 [ V_118 ] . V_257 ; V_31 ++ ) {
unsigned int V_112 = V_258 [ V_118 ] . V_256 [ V_31 ] ;
T_3 V_144 = V_112 * V_245 ;
F_89 ( & V_234 ,
V_253 [ V_259 ] ,
V_144 ,
V_112 ) ;
if ( V_234 . V_235 == 0 )
goto V_260;
}
}
V_260:
if ( V_118 == 0 && V_234 . V_112 )
break;
}
if ( ! V_234 . V_112 ) {
F_85 ( L_14 , clock ) ;
return false ;
}
V_141 = V_142 = V_143 = 0 ;
F_91 ( V_234 . V_112 , & V_141 , & V_142 , & V_143 ) ;
F_92 ( V_252 , V_245 , V_234 . V_237 ,
V_141 , V_142 , V_143 ) ;
return true ;
}
static bool
F_96 ( struct V_65 * V_65 ,
struct V_99 * V_100 ,
struct V_1 * V_1 )
{
struct V_193 * V_180 ;
T_4 V_261 , V_262 , V_263 ;
int clock = V_100 -> V_161 ;
V_261 = F_97 ( 0 ) ;
if ( V_1 -> type == V_12 ) {
struct V_243 V_252 = { 0 , } ;
V_261 |= F_69 ( 0 ) ;
if ( ! F_95 ( clock * 1000 , & V_252 ) )
return false ;
V_262 = V_264 |
F_98 ( V_252 . V_251 ) |
V_252 . V_250 ;
V_263 = F_99 ( V_252 . V_248 ) |
F_65 ( V_252 . V_249 ) |
F_100 ( V_252 . V_247 ) |
F_101 ( V_252 . V_246 ) |
V_252 . V_237 ;
} else if ( V_1 -> type == V_10 ||
V_1 -> type == V_8 ) {
switch ( V_100 -> V_161 / 2 ) {
case 81000 :
V_261 |= F_102 ( V_173 , 0 ) ;
break;
case 135000 :
V_261 |= F_102 ( V_175 , 0 ) ;
break;
case 270000 :
V_261 |= F_102 ( V_178 , 0 ) ;
break;
}
V_262 = V_263 = 0 ;
} else if ( V_1 -> type == V_11 ) {
return true ;
} else
return false ;
memset ( & V_100 -> V_226 , 0 ,
sizeof( V_100 -> V_226 ) ) ;
V_100 -> V_226 . V_261 = V_261 ;
V_100 -> V_226 . V_262 = V_262 ;
V_100 -> V_226 . V_263 = V_263 ;
V_180 = F_84 ( V_65 , V_100 ) ;
if ( V_180 == NULL ) {
F_85 ( L_11 ,
F_53 ( V_65 -> V_98 ) ) ;
return false ;
}
V_100 -> V_77 = V_180 -> V_227 + 1 ;
return true ;
}
static bool
F_103 ( struct V_65 * V_65 ,
struct V_99 * V_100 ,
struct V_1 * V_1 )
{
struct V_193 * V_180 ;
struct V_265 V_266 = { 0 } ;
int V_267 = 0 ;
T_4 V_268 , V_269 , V_270 , V_271 ;
T_4 V_272 ;
int clock = V_100 -> V_161 ;
if ( V_1 -> type == V_12 ) {
T_5 V_273 ;
if ( ! F_104 ( V_100 , clock , & V_273 ) ) {
F_85 ( L_15 ,
clock , F_53 ( V_65 -> V_98 ) ) ;
return false ;
}
V_266 . V_142 = V_273 . V_142 ;
V_266 . V_143 = V_273 . V_143 ;
F_20 ( V_273 . V_198 != 2 ) ;
V_266 . V_124 = V_273 . V_124 ;
V_266 . V_274 = V_273 . V_199 >> 22 ;
V_266 . V_275 = V_273 . V_199 & ( ( 1 << 22 ) - 1 ) ;
V_266 . V_276 = V_266 . V_275 != 0 ;
V_267 = V_273 . V_267 ;
} else if ( V_1 -> type == V_10 ||
V_1 -> type == V_11 ) {
int V_31 ;
V_266 = V_277 [ 0 ] ;
for ( V_31 = 0 ; V_31 < F_9 ( V_277 ) ; ++ V_31 ) {
if ( V_277 [ V_31 ] . clock == clock ) {
V_266 = V_277 [ V_31 ] ;
break;
}
}
V_267 = clock * 10 / 2 * V_266 . V_142 * V_266 . V_143 ;
}
if ( V_267 >= 6200000 && V_267 <= 6700000 ) {
V_268 = 4 ;
V_269 = 9 ;
V_270 = 3 ;
V_271 = 8 ;
} else if ( ( V_267 > 5400000 && V_267 < 6200000 ) ||
( V_267 >= 4800000 && V_267 < 5400000 ) ) {
V_268 = 5 ;
V_269 = 11 ;
V_270 = 3 ;
V_271 = 9 ;
} else if ( V_267 == 5400000 ) {
V_268 = 3 ;
V_269 = 8 ;
V_270 = 1 ;
V_271 = 9 ;
} else {
F_31 ( L_16 ) ;
return false ;
}
memset ( & V_100 -> V_226 , 0 ,
sizeof( V_100 -> V_226 ) ) ;
if ( clock > 270000 )
V_272 = 0x18 ;
else if ( clock > 135000 )
V_272 = 0x0d ;
else if ( clock > 67000 )
V_272 = 0x07 ;
else if ( clock > 33000 )
V_272 = 0x04 ;
else
V_272 = 0x02 ;
V_100 -> V_226 . V_209 =
F_105 ( V_266 . V_142 ) | F_106 ( V_266 . V_143 ) ;
V_100 -> V_226 . V_200 = V_266 . V_274 ;
V_100 -> V_226 . V_206 = F_107 ( V_266 . V_124 ) ;
V_100 -> V_226 . V_204 = V_266 . V_275 ;
if ( V_266 . V_276 )
V_100 -> V_226 . V_202 =
V_203 ;
V_100 -> V_226 . V_278 =
V_268 | F_108 ( V_269 ) ;
V_100 -> V_226 . V_278 |=
F_109 ( V_270 ) ;
V_100 -> V_226 . V_279 = V_271 ;
V_100 -> V_226 . V_280 = 5 << V_281 ;
V_100 -> V_226 . V_282 =
F_110 ( V_283 )
| V_284 ;
V_100 -> V_226 . V_285 = V_286 ;
V_100 -> V_226 . V_287 =
V_288 | V_272 ;
V_180 = F_84 ( V_65 , V_100 ) ;
if ( V_180 == NULL ) {
F_85 ( L_11 ,
F_53 ( V_65 -> V_98 ) ) ;
return false ;
}
V_100 -> V_77 = V_180 -> V_227 ;
return true ;
}
bool F_111 ( struct V_65 * V_65 ,
struct V_99 * V_100 )
{
struct V_63 * V_29 = V_65 -> V_7 . V_29 ;
struct V_1 * V_1 =
F_55 ( V_100 ) ;
if ( F_18 ( V_29 ) || F_19 ( V_29 ) )
return F_96 ( V_65 , V_100 ,
V_1 ) ;
else if ( F_16 ( V_29 ) )
return F_103 ( V_65 , V_100 ,
V_1 ) ;
else
return F_80 ( V_65 , V_100 ,
V_1 ) ;
}
void F_112 ( struct V_61 * V_62 )
{
struct V_17 * V_18 = V_62 -> V_29 -> V_64 ;
struct V_65 * V_65 = F_34 ( V_62 ) ;
struct V_1 * V_1 = F_52 ( V_62 ) ;
enum V_289 V_290 = V_65 -> V_74 -> V_290 ;
int type = V_1 -> type ;
T_4 V_66 ;
if ( type == V_10 || type == V_11 || type == V_8 ) {
V_66 = V_291 ;
switch ( V_65 -> V_74 -> V_166 ) {
case 18 :
V_66 |= V_292 ;
break;
case 24 :
V_66 |= V_293 ;
break;
case 30 :
V_66 |= V_294 ;
break;
case 36 :
V_66 |= V_295 ;
break;
default:
F_23 () ;
}
F_24 ( F_113 ( V_290 ) , V_66 ) ;
}
}
void F_114 ( struct V_61 * V_62 , bool V_102 )
{
struct V_65 * V_65 = F_34 ( V_62 ) ;
struct V_63 * V_29 = V_62 -> V_29 ;
struct V_17 * V_18 = V_29 -> V_64 ;
enum V_289 V_290 = V_65 -> V_74 -> V_290 ;
T_4 V_66 ;
V_66 = F_30 ( F_115 ( V_290 ) ) ;
if ( V_102 == true )
V_66 |= V_296 ;
else
V_66 &= ~ V_296 ;
F_24 ( F_115 ( V_290 ) , V_66 ) ;
}
void F_116 ( struct V_61 * V_62 )
{
struct V_65 * V_65 = F_34 ( V_62 ) ;
struct V_1 * V_1 = F_52 ( V_62 ) ;
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_63 * V_29 = V_62 -> V_29 ;
struct V_17 * V_18 = V_29 -> V_64 ;
enum V_98 V_98 = V_65 -> V_98 ;
enum V_289 V_290 = V_65 -> V_74 -> V_290 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_4 V_66 ;
V_66 = V_297 ;
V_66 |= F_117 ( V_4 ) ;
switch ( V_65 -> V_74 -> V_166 ) {
case 18 :
V_66 |= V_298 ;
break;
case 24 :
V_66 |= V_299 ;
break;
case 30 :
V_66 |= V_300 ;
break;
case 36 :
V_66 |= V_301 ;
break;
default:
F_23 () ;
}
if ( V_65 -> V_74 -> V_7 . V_168 . V_302 & V_303 )
V_66 |= V_304 ;
if ( V_65 -> V_74 -> V_7 . V_168 . V_302 & V_305 )
V_66 |= V_306 ;
if ( V_290 == V_307 ) {
switch ( V_98 ) {
case V_68 :
if ( F_22 ( V_29 ) &&
( V_65 -> V_74 -> V_308 . V_309 ||
V_65 -> V_74 -> V_308 . V_310 ) )
V_66 |= V_311 ;
else
V_66 |= V_312 ;
break;
case V_313 :
V_66 |= V_314 ;
break;
case V_315 :
V_66 |= V_316 ;
break;
default:
F_23 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_65 -> V_74 -> V_165 )
V_66 |= V_317 ;
else
V_66 |= V_318 ;
} else if ( type == V_14 ) {
V_66 |= V_319 ;
V_66 |= ( V_65 -> V_74 -> V_75 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_91 * V_91 = F_50 ( V_6 ) ;
if ( V_91 -> V_320 ) {
V_66 |= V_321 ;
} else
V_66 |= V_322 ;
V_66 |= F_51 ( V_65 -> V_74 -> V_95 ) ;
} else if ( type == V_8 ) {
struct V_91 * V_91 = & F_2 ( V_6 ) -> V_9 -> V_323 ;
if ( V_91 -> V_320 ) {
V_66 |= V_321 ;
} else
V_66 |= V_322 ;
V_66 |= F_51 ( V_65 -> V_74 -> V_95 ) ;
} else {
F_4 ( 1 , L_17 ,
V_1 -> type , F_53 ( V_98 ) ) ;
}
F_24 ( F_115 ( V_290 ) , V_66 ) ;
}
void F_118 ( struct V_17 * V_18 ,
enum V_289 V_290 )
{
T_2 V_59 = F_115 ( V_290 ) ;
T_4 V_179 = F_30 ( V_59 ) ;
V_179 &= ~ ( V_297 | V_324 | V_296 ) ;
V_179 |= V_325 ;
F_24 ( V_59 , V_179 ) ;
}
bool F_119 ( struct V_326 * V_326 )
{
struct V_63 * V_29 = V_326 -> V_7 . V_29 ;
struct V_17 * V_18 = V_29 -> V_64 ;
struct V_1 * V_1 = V_326 -> V_6 ;
int type = V_326 -> V_7 . V_327 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_98 V_98 = 0 ;
enum V_289 V_290 ;
enum V_328 V_329 ;
T_4 V_330 ;
bool V_96 ;
V_329 = F_120 ( V_1 ) ;
if ( ! F_121 ( V_18 , V_329 ) )
return false ;
if ( ! V_1 -> V_331 ( V_1 , & V_98 ) ) {
V_96 = false ;
goto V_332;
}
if ( V_4 == V_48 )
V_290 = V_307 ;
else
V_290 = (enum V_289 ) V_98 ;
V_330 = F_30 ( F_115 ( V_290 ) ) ;
switch ( V_330 & V_333 ) {
case V_317 :
case V_318 :
V_96 = type == V_334 ;
break;
case V_322 :
V_96 = type == V_335 ||
type == V_336 ;
break;
case V_321 :
V_96 = false ;
break;
case V_319 :
V_96 = type == V_337 ;
break;
default:
V_96 = false ;
break;
}
V_332:
F_122 ( V_18 , V_329 ) ;
return V_96 ;
}
bool F_123 ( struct V_1 * V_6 ,
enum V_98 * V_98 )
{
struct V_63 * V_29 = V_6 -> V_7 . V_29 ;
struct V_17 * V_18 = V_29 -> V_64 ;
enum V_4 V_4 = F_5 ( V_6 ) ;
enum V_328 V_329 ;
T_1 V_330 ;
int V_31 ;
bool V_96 ;
V_329 = F_120 ( V_6 ) ;
if ( ! F_121 ( V_18 , V_329 ) )
return false ;
V_96 = false ;
V_330 = F_30 ( F_28 ( V_4 ) ) ;
if ( ! ( V_330 & V_83 ) )
goto V_332;
if ( V_4 == V_48 ) {
V_330 = F_30 ( F_115 ( V_307 ) ) ;
switch ( V_330 & V_338 ) {
case V_312 :
case V_311 :
* V_98 = V_68 ;
break;
case V_314 :
* V_98 = V_313 ;
break;
case V_316 :
* V_98 = V_315 ;
break;
}
V_96 = true ;
goto V_332;
}
for ( V_31 = V_339 ; V_31 <= V_340 ; V_31 ++ ) {
V_330 = F_30 ( F_115 ( V_31 ) ) ;
if ( ( V_330 & V_324 ) == F_117 ( V_4 ) ) {
if ( ( V_330 & V_333 ) ==
V_321 )
goto V_332;
* V_98 = V_31 ;
V_96 = true ;
goto V_332;
}
}
F_48 ( L_18 , F_32 ( V_4 ) ) ;
V_332:
F_122 ( V_18 , V_329 ) ;
return V_96 ;
}
void F_124 ( struct V_65 * V_65 )
{
struct V_61 * V_62 = & V_65 -> V_7 ;
struct V_63 * V_29 = V_62 -> V_29 ;
struct V_17 * V_18 = V_29 -> V_64 ;
struct V_1 * V_1 = F_52 ( V_62 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_289 V_290 = V_65 -> V_74 -> V_290 ;
if ( V_290 != V_307 )
F_24 ( F_125 ( V_290 ) ,
F_126 ( V_4 ) ) ;
}
void F_127 ( struct V_65 * V_65 )
{
struct V_17 * V_18 = V_65 -> V_7 . V_29 -> V_64 ;
enum V_289 V_290 = V_65 -> V_74 -> V_290 ;
if ( V_290 != V_307 )
F_24 ( F_125 ( V_290 ) ,
V_341 ) ;
}
static void F_128 ( struct V_17 * V_18 ,
T_1 V_342 , enum V_4 V_4 , int type )
{
const struct V_16 * V_42 ;
T_6 V_343 ;
T_6 V_344 , V_345 ;
int V_19 ;
T_1 V_59 ;
V_344 = V_18 -> V_43 . V_44 [ V_4 ] . V_47 ;
V_345 = V_18 -> V_43 . V_44 [ V_4 ] . V_46 ;
if ( type == V_10 ) {
if ( V_344 ) {
V_343 = V_344 ;
} else {
V_42 = F_6 ( V_18 , & V_19 ) ;
V_343 = V_42 [ V_342 ] . V_346 ;
}
} else if ( type == V_11 ) {
if ( V_344 ) {
V_343 = V_344 ;
} else {
V_42 = F_12 ( V_18 , & V_19 ) ;
if ( F_20 ( V_4 != V_48 &&
V_4 != V_15 && V_19 > 9 ) )
V_19 = 9 ;
V_343 = V_42 [ V_342 ] . V_346 ;
}
} else if ( type == V_12 ) {
if ( V_345 ) {
V_343 = V_345 ;
} else {
V_42 = F_13 ( V_18 , & V_19 ) ;
V_343 = V_42 [ V_342 ] . V_346 ;
}
} else {
return;
}
if ( V_343 && V_343 != 0x1 && V_343 != 0x3 && V_343 != 0x7 ) {
F_31 ( L_19 , V_343 ) ;
return;
}
V_59 = F_30 ( V_347 ) ;
V_59 &= ~ F_129 ( V_4 ) ;
V_59 &= ~ ( 1 << ( V_348 + V_4 ) ) ;
if ( V_343 )
V_59 |= V_343 << F_130 ( V_4 ) ;
else
V_59 |= 1 << ( V_348 + V_4 ) ;
F_24 ( V_347 , V_59 ) ;
}
static void F_17 ( struct V_17 * V_18 ,
T_1 V_342 , enum V_4 V_4 , int type )
{
const struct V_349 * V_42 ;
T_1 V_19 , V_31 ;
T_4 V_179 ;
if ( type == V_11 && V_18 -> V_23 ) {
V_19 = F_9 ( V_350 ) ;
V_42 = V_350 ;
} else if ( type == V_10
|| type == V_11 ) {
V_19 = F_9 ( V_351 ) ;
V_42 = V_351 ;
} else if ( type == V_12 ) {
V_19 = F_9 ( V_352 ) ;
V_42 = V_352 ;
} else {
F_48 ( L_20 ,
type ) ;
return;
}
if ( V_342 >= V_19 ||
( type == V_12 && V_342 == V_58 ) ) {
for ( V_31 = 0 ; V_31 < V_19 ; V_31 ++ ) {
if ( V_42 [ V_31 ] . V_353 ) {
V_342 = V_31 ;
break;
}
}
}
V_179 = F_30 ( F_131 ( V_4 ) ) ;
V_179 &= ~ ( V_354 | V_355 ) ;
F_24 ( F_132 ( V_4 ) , V_179 ) ;
V_179 = F_30 ( F_133 ( V_4 ) ) ;
V_179 &= ~ ( V_356 | V_357 ) ;
V_179 |= V_42 [ V_342 ] . V_358 << V_359 |
V_42 [ V_342 ] . V_360 << V_361 ;
F_24 ( F_134 ( V_4 ) , V_179 ) ;
V_179 = F_30 ( F_135 ( V_4 ) ) ;
V_179 &= ~ V_362 ;
if ( V_42 [ V_342 ] . V_363 )
V_179 |= V_362 ;
if ( ( V_179 & V_364 ) && ! ( V_179 & V_362 ) )
F_31 ( L_21 ) ;
F_24 ( F_136 ( V_4 ) , V_179 ) ;
V_179 = F_30 ( F_137 ( V_4 ) ) ;
V_179 &= ~ V_365 ;
V_179 |= V_42 [ V_342 ] . V_366 << V_367 ;
F_24 ( F_138 ( V_4 ) , V_179 ) ;
V_179 = F_30 ( F_131 ( V_4 ) ) ;
V_179 |= V_354 | V_355 ;
F_24 ( F_132 ( V_4 ) , V_179 ) ;
}
static T_4 F_139 ( int V_368 )
{
T_4 V_342 ;
switch ( V_368 ) {
default:
F_48 ( L_22 ,
V_368 ) ;
case V_369 | V_370 :
V_342 = 0 ;
break;
case V_369 | V_371 :
V_342 = 1 ;
break;
case V_369 | V_372 :
V_342 = 2 ;
break;
case V_369 | V_373 :
V_342 = 3 ;
break;
case V_374 | V_370 :
V_342 = 4 ;
break;
case V_374 | V_371 :
V_342 = 5 ;
break;
case V_374 | V_372 :
V_342 = 6 ;
break;
case V_375 | V_370 :
V_342 = 7 ;
break;
case V_375 | V_371 :
V_342 = 8 ;
break;
case V_376 | V_370 :
V_342 = 9 ;
break;
}
return V_342 ;
}
T_4 F_140 ( struct V_91 * V_91 )
{
struct V_2 * V_377 = F_141 ( V_91 ) ;
struct V_17 * V_18 = F_15 ( V_377 -> V_7 . V_7 . V_29 ) ;
struct V_1 * V_6 = & V_377 -> V_7 ;
T_6 V_378 = V_91 -> V_378 [ 0 ] ;
int V_368 = V_378 & ( V_379 |
V_380 ) ;
enum V_4 V_4 = V_377 -> V_4 ;
T_4 V_342 ;
V_342 = F_139 ( V_368 ) ;
if ( F_18 ( V_18 ) || F_19 ( V_18 ) )
F_128 ( V_18 , V_342 , V_4 , V_6 -> type ) ;
else if ( F_16 ( V_18 ) )
F_17 ( V_18 , V_342 , V_4 , V_6 -> type ) ;
return F_44 ( V_342 ) ;
}
void F_142 ( struct V_1 * V_6 ,
const struct V_99 * V_158 )
{
struct V_17 * V_18 = F_15 ( V_6 -> V_7 . V_29 ) ;
enum V_4 V_4 = F_5 ( V_6 ) ;
if ( F_18 ( V_18 ) || F_19 ( V_18 ) ) {
T_4 V_136 = V_158 -> V_77 ;
T_4 V_179 ;
if ( V_6 -> type == V_11 ) {
F_20 ( V_136 != V_381 ) ;
V_179 = F_30 ( V_172 ) ;
V_179 &= ~ ( F_69 ( V_136 ) |
F_143 ( V_136 ) |
F_70 ( V_136 ) ) ;
V_179 |= V_158 -> V_226 . V_261 << ( V_136 * 6 ) ;
F_24 ( V_172 , V_179 ) ;
F_41 ( V_172 ) ;
}
V_179 = F_30 ( V_382 ) ;
V_179 &= ~ ( F_144 ( V_4 ) |
F_145 ( V_4 ) ) ;
V_179 |= ( F_146 ( V_136 , V_4 ) |
F_147 ( V_4 ) ) ;
F_24 ( V_382 , V_179 ) ;
} else if ( F_78 ( V_18 ) -> V_214 < 9 ) {
F_20 ( V_158 -> V_77 == V_383 ) ;
F_24 ( F_42 ( V_4 ) , V_158 -> V_77 ) ;
}
}
static void F_148 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_17 * V_18 = F_15 ( V_6 -> V_29 ) ;
struct V_65 * V_62 = F_34 ( V_6 -> V_62 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
F_14 ( V_1 ) ;
if ( type == V_11 ) {
struct V_91 * V_91 = F_50 ( V_6 ) ;
F_149 ( V_91 ) ;
}
F_142 ( V_1 , V_62 -> V_74 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_91 * V_91 = F_50 ( V_6 ) ;
F_150 ( V_91 , V_62 -> V_74 ) ;
F_49 ( V_1 ) ;
F_151 ( V_91 , V_384 ) ;
F_152 ( V_91 ) ;
if ( V_4 != V_48 || F_78 ( V_18 ) -> V_214 >= 9 )
F_153 ( V_91 ) ;
} else if ( type == V_12 ) {
struct V_385 * V_385 = F_154 ( V_6 ) ;
V_385 -> V_386 ( V_6 ,
V_62 -> V_74 -> V_165 ,
& V_62 -> V_74 -> V_7 . V_168 ) ;
}
}
static void F_155 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_63 * V_29 = V_6 -> V_29 ;
struct V_17 * V_18 = V_29 -> V_64 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_4 V_179 ;
bool V_387 = false ;
V_179 = F_30 ( F_28 ( V_4 ) ) ;
if ( V_179 & V_83 ) {
V_179 &= ~ V_83 ;
F_24 ( F_28 ( V_4 ) , V_179 ) ;
V_387 = true ;
}
V_179 = F_30 ( F_43 ( V_4 ) ) ;
V_179 &= ~ ( V_82 | V_89 ) ;
V_179 |= V_81 ;
F_24 ( F_43 ( V_4 ) , V_179 ) ;
if ( V_387 )
F_27 ( V_18 , V_4 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_91 * V_91 = F_50 ( V_6 ) ;
F_151 ( V_91 , V_388 ) ;
F_156 ( V_91 ) ;
F_157 ( V_91 ) ;
}
if ( F_18 ( V_29 ) || F_19 ( V_29 ) )
F_24 ( V_382 , ( F_30 ( V_382 ) |
F_144 ( V_4 ) ) ) ;
else if ( F_78 ( V_29 ) -> V_214 < 9 )
F_24 ( F_42 ( V_4 ) , V_383 ) ;
}
static void F_158 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_61 * V_62 = V_6 -> V_62 ;
struct V_65 * V_65 = F_34 ( V_62 ) ;
struct V_63 * V_29 = V_6 -> V_29 ;
struct V_17 * V_18 = V_29 -> V_64 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
if ( type == V_12 ) {
struct V_2 * V_92 =
F_3 ( V_6 ) ;
F_24 ( F_28 ( V_4 ) ,
V_92 -> V_94 |
V_83 ) ;
} else if ( type == V_11 ) {
struct V_91 * V_91 = F_50 ( V_6 ) ;
if ( V_4 == V_48 && F_78 ( V_29 ) -> V_214 < 9 )
F_153 ( V_91 ) ;
F_159 ( V_91 ) ;
F_160 ( V_91 ) ;
F_161 ( V_91 ) ;
}
if ( V_65 -> V_74 -> V_389 ) {
F_162 ( V_18 , V_390 ) ;
F_163 ( V_1 ) ;
}
}
static void F_164 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_61 * V_62 = V_6 -> V_62 ;
struct V_65 * V_65 = F_34 ( V_62 ) ;
int type = V_1 -> type ;
struct V_63 * V_29 = V_6 -> V_29 ;
struct V_17 * V_18 = V_29 -> V_64 ;
if ( V_65 -> V_74 -> V_389 ) {
F_165 ( V_1 ) ;
F_122 ( V_18 , V_390 ) ;
}
if ( type == V_11 ) {
struct V_91 * V_91 = F_50 ( V_6 ) ;
F_166 ( V_91 ) ;
F_167 ( V_91 ) ;
F_168 ( V_91 ) ;
}
}
static void F_169 ( struct V_17 * V_18 ,
struct V_193 * V_180 )
{
F_24 ( F_73 ( V_180 -> V_227 ) , V_180 -> V_74 . V_197 . V_126 ) ;
F_41 ( F_73 ( V_180 -> V_227 ) ) ;
F_29 ( 20 ) ;
}
static void F_170 ( struct V_17 * V_18 ,
struct V_193 * V_180 )
{
F_24 ( V_187 , V_180 -> V_74 . V_197 . V_229 ) ;
F_41 ( V_187 ) ;
F_29 ( 20 ) ;
}
static void F_171 ( struct V_17 * V_18 ,
struct V_193 * V_180 )
{
T_4 V_179 ;
V_179 = F_30 ( F_73 ( V_180 -> V_227 ) ) ;
F_24 ( F_73 ( V_180 -> V_227 ) , V_179 & ~ V_225 ) ;
F_41 ( F_73 ( V_180 -> V_227 ) ) ;
}
static void F_172 ( struct V_17 * V_18 ,
struct V_193 * V_180 )
{
T_4 V_179 ;
V_179 = F_30 ( V_187 ) ;
F_24 ( V_187 , V_179 & ~ V_391 ) ;
F_41 ( V_187 ) ;
}
static bool F_173 ( struct V_17 * V_18 ,
struct V_193 * V_180 ,
struct V_194 * V_197 )
{
T_4 V_179 ;
if ( ! F_121 ( V_18 , V_392 ) )
return false ;
V_179 = F_30 ( F_73 ( V_180 -> V_227 ) ) ;
V_197 -> V_126 = V_179 ;
F_122 ( V_18 , V_392 ) ;
return V_179 & V_225 ;
}
static bool F_174 ( struct V_17 * V_18 ,
struct V_193 * V_180 ,
struct V_194 * V_197 )
{
T_4 V_179 ;
if ( ! F_121 ( V_18 , V_392 ) )
return false ;
V_179 = F_30 ( V_187 ) ;
V_197 -> V_229 = V_179 ;
F_122 ( V_18 , V_392 ) ;
return V_179 & V_391 ;
}
static void F_175 ( struct V_17 * V_18 )
{
int V_31 ;
V_18 -> V_393 = 3 ;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
V_18 -> V_196 [ V_31 ] . V_227 = V_31 ;
V_18 -> V_196 [ V_31 ] . V_394 = V_395 [ V_31 ] ;
V_18 -> V_196 [ V_31 ] . V_396 = F_171 ;
V_18 -> V_196 [ V_31 ] . V_363 = F_169 ;
V_18 -> V_196 [ V_31 ] . V_331 =
F_173 ;
}
V_18 -> V_196 [ V_31 ] . V_227 = V_31 ;
V_18 -> V_196 [ V_31 ] . V_394 = V_395 [ V_31 ] ;
V_18 -> V_196 [ V_31 ] . V_396 = F_172 ;
V_18 -> V_196 [ V_31 ] . V_363 = F_170 ;
V_18 -> V_196 [ V_31 ] . V_331 = F_174 ;
}
static void F_176 ( struct V_17 * V_18 ,
struct V_193 * V_180 )
{
T_4 V_179 ;
unsigned int V_136 ;
const struct V_397 * V_398 = V_397 ;
V_136 = V_180 -> V_227 + 1 ;
V_179 = F_30 ( V_172 ) ;
V_179 &= ~ ( F_69 ( V_136 ) | F_143 ( V_136 ) |
F_70 ( V_136 ) ) ;
V_179 |= V_180 -> V_74 . V_197 . V_261 << ( V_136 * 6 ) ;
F_24 ( V_172 , V_179 ) ;
F_41 ( V_172 ) ;
F_24 ( V_398 [ V_180 -> V_227 ] . V_262 , V_180 -> V_74 . V_197 . V_262 ) ;
F_24 ( V_398 [ V_180 -> V_227 ] . V_263 , V_180 -> V_74 . V_197 . V_263 ) ;
F_41 ( V_398 [ V_180 -> V_227 ] . V_262 ) ;
F_41 ( V_398 [ V_180 -> V_227 ] . V_263 ) ;
F_24 ( V_398 [ V_180 -> V_227 ] . V_399 ,
F_30 ( V_398 [ V_180 -> V_227 ] . V_399 ) | V_400 ) ;
if ( F_177 ( F_30 ( V_401 ) & F_178 ( V_136 ) , 5 ) )
F_31 ( L_23 , V_136 ) ;
}
static void F_179 ( struct V_17 * V_18 ,
struct V_193 * V_180 )
{
const struct V_397 * V_398 = V_397 ;
F_24 ( V_398 [ V_180 -> V_227 ] . V_399 ,
F_30 ( V_398 [ V_180 -> V_227 ] . V_399 ) & ~ V_400 ) ;
F_41 ( V_398 [ V_180 -> V_227 ] . V_399 ) ;
}
static bool F_180 ( struct V_17 * V_18 ,
struct V_193 * V_180 ,
struct V_194 * V_197 )
{
T_4 V_179 ;
unsigned int V_136 ;
const struct V_397 * V_398 = V_397 ;
bool V_96 ;
if ( ! F_121 ( V_18 , V_392 ) )
return false ;
V_96 = false ;
V_136 = V_180 -> V_227 + 1 ;
V_179 = F_30 ( V_398 [ V_180 -> V_227 ] . V_399 ) ;
if ( ! ( V_179 & V_400 ) )
goto V_332;
V_179 = F_30 ( V_172 ) ;
V_197 -> V_261 = ( V_179 >> ( V_136 * 6 ) ) & 0x3f ;
if ( V_179 & F_69 ( V_136 ) ) {
V_197 -> V_262 = F_30 ( V_398 [ V_180 -> V_227 ] . V_262 ) ;
V_197 -> V_263 = F_30 ( V_398 [ V_180 -> V_227 ] . V_263 ) ;
}
V_96 = true ;
V_332:
F_122 ( V_18 , V_392 ) ;
return V_96 ;
}
static void F_181 ( struct V_17 * V_18 )
{
int V_31 ;
V_18 -> V_393 = 3 ;
for ( V_31 = 0 ; V_31 < V_18 -> V_393 ; V_31 ++ ) {
V_18 -> V_196 [ V_31 ] . V_227 = V_31 ;
V_18 -> V_196 [ V_31 ] . V_394 = V_402 [ V_31 ] ;
V_18 -> V_196 [ V_31 ] . V_396 = F_179 ;
V_18 -> V_196 [ V_31 ] . V_363 = F_176 ;
V_18 -> V_196 [ V_31 ] . V_331 =
F_180 ;
}
}
static void F_182 ( struct V_17 * V_18 ,
enum V_403 V_404 )
{
enum V_4 V_4 ;
T_4 V_179 ;
V_179 = F_30 ( V_405 ) ;
V_179 |= F_183 ( V_404 ) ;
F_24 ( V_405 , V_179 ) ;
if ( F_177 ( F_30 ( F_184 ( V_404 ) ) & V_406 , 10 ) )
F_31 ( L_24 , V_404 ) ;
for ( V_4 = ( V_404 == V_407 ? V_408 : V_48 ) ;
V_4 <= ( V_404 == V_407 ? V_409 : V_48 ) ; V_4 ++ ) {
int V_410 ;
for ( V_410 = 0 ; V_410 < 4 ; V_410 ++ ) {
V_179 = F_30 ( F_185 ( V_4 , V_410 ) ) ;
V_179 &= ~ V_411 ;
if ( V_410 != 1 )
V_179 |= V_411 ;
F_24 ( F_185 ( V_4 , V_410 ) , V_179 ) ;
}
}
V_179 = F_30 ( F_186 ( V_404 ) ) ;
V_179 &= ~ V_412 ;
V_179 |= 0xE4 << V_413 ;
F_24 ( F_186 ( V_404 ) , V_179 ) ;
V_179 = F_30 ( F_187 ( V_404 ) ) ;
V_179 &= ~ V_414 ;
V_179 |= 0xE4 << V_415 ;
F_24 ( F_187 ( V_404 ) , V_179 ) ;
V_179 = F_30 ( F_188 ( V_404 ) ) ;
V_179 |= V_416 | V_417 |
V_418 ;
F_24 ( F_188 ( V_404 ) , V_179 ) ;
if ( V_404 == V_407 ) {
V_179 = F_30 ( V_419 ) ;
V_179 |= V_420 ;
F_24 ( V_419 , V_179 ) ;
}
V_179 = F_30 ( F_189 ( V_404 ) ) ;
V_179 &= ~ V_421 ;
if ( V_404 == V_422 )
V_179 |= V_421 ;
F_24 ( F_189 ( V_404 ) , V_179 ) ;
if ( V_404 == V_407 ) {
T_4 V_423 ;
if ( F_177 ( F_30 ( F_190 ( V_422 ) ) & V_424 ,
10 ) )
F_31 ( L_25 ) ;
V_179 = F_30 ( F_191 ( V_422 ) ) ;
V_179 = ( V_179 & V_425 ) >> V_426 ;
V_423 = V_179 << V_427 |
V_179 << V_428 |
V_179 ;
F_24 ( F_191 ( V_407 ) , V_423 ) ;
V_179 = F_30 ( F_192 ( V_407 ) ) ;
V_179 |= V_429 | V_430 ;
F_24 ( F_192 ( V_407 ) , V_179 ) ;
}
V_179 = F_30 ( F_193 ( V_404 ) ) ;
V_179 |= V_431 ;
F_24 ( F_193 ( V_404 ) , V_179 ) ;
}
void F_194 ( struct V_63 * V_29 )
{
F_182 ( V_29 -> V_64 , V_422 ) ;
F_182 ( V_29 -> V_64 , V_407 ) ;
}
static void F_195 ( struct V_17 * V_18 ,
enum V_403 V_404 )
{
T_4 V_179 ;
V_179 = F_30 ( F_193 ( V_404 ) ) ;
V_179 &= ~ V_431 ;
F_24 ( F_193 ( V_404 ) , V_179 ) ;
}
void F_196 ( struct V_63 * V_29 )
{
struct V_17 * V_18 = V_29 -> V_64 ;
F_195 ( V_18 , V_422 ) ;
F_195 ( V_18 , V_407 ) ;
F_24 ( V_405 , 0 ) ;
}
static void F_197 ( struct V_17 * V_18 ,
struct V_193 * V_180 )
{
T_4 V_66 ;
enum V_4 V_4 = (enum V_4 ) V_180 -> V_227 ;
V_66 = F_30 ( F_198 ( V_4 ) ) ;
V_66 &= ~ V_432 ;
F_24 ( F_198 ( V_4 ) , V_66 ) ;
V_66 = F_30 ( F_199 ( V_4 ) ) ;
V_66 &= ~ V_286 ;
F_24 ( F_199 ( V_4 ) , V_66 ) ;
V_66 = F_30 ( F_200 ( V_4 ) ) ;
V_66 &= ~ ( V_210 | V_212 ) ;
V_66 |= V_180 -> V_74 . V_197 . V_209 ;
F_24 ( F_200 ( V_4 ) , V_66 ) ;
V_66 = F_30 ( F_201 ( V_4 , 0 ) ) ;
V_66 &= ~ V_201 ;
V_66 |= V_180 -> V_74 . V_197 . V_200 ;
F_24 ( F_201 ( V_4 , 0 ) , V_66 ) ;
V_66 = F_30 ( F_201 ( V_4 , 1 ) ) ;
V_66 &= ~ V_207 ;
V_66 |= V_180 -> V_74 . V_197 . V_206 ;
F_24 ( F_201 ( V_4 , 1 ) , V_66 ) ;
V_66 = F_30 ( F_201 ( V_4 , 2 ) ) ;
V_66 &= ~ V_205 ;
V_66 |= V_180 -> V_74 . V_197 . V_204 ;
F_24 ( F_201 ( V_4 , 2 ) , V_66 ) ;
V_66 = F_30 ( F_201 ( V_4 , 3 ) ) ;
V_66 &= ~ V_203 ;
V_66 |= V_180 -> V_74 . V_197 . V_202 ;
F_24 ( F_201 ( V_4 , 3 ) , V_66 ) ;
V_66 = F_30 ( F_201 ( V_4 , 6 ) ) ;
V_66 &= ~ V_433 ;
V_66 &= ~ V_434 ;
V_66 &= ~ V_435 ;
V_66 |= V_180 -> V_74 . V_197 . V_278 ;
F_24 ( F_201 ( V_4 , 6 ) , V_66 ) ;
V_66 = F_30 ( F_201 ( V_4 , 8 ) ) ;
V_66 &= ~ V_436 ;
V_66 |= V_180 -> V_74 . V_197 . V_279 ;
F_24 ( F_201 ( V_4 , 8 ) , V_66 ) ;
V_66 = F_30 ( F_201 ( V_4 , 9 ) ) ;
V_66 &= ~ V_437 ;
V_66 |= V_180 -> V_74 . V_197 . V_280 ;
F_24 ( F_201 ( V_4 , 9 ) , V_66 ) ;
V_66 = F_30 ( F_201 ( V_4 , 10 ) ) ;
V_66 &= ~ V_284 ;
V_66 &= ~ V_438 ;
V_66 |= V_180 -> V_74 . V_197 . V_282 ;
F_24 ( F_201 ( V_4 , 10 ) , V_66 ) ;
V_66 = F_30 ( F_199 ( V_4 ) ) ;
V_66 |= V_439 ;
F_24 ( F_199 ( V_4 ) , V_66 ) ;
V_66 &= ~ V_286 ;
V_66 |= V_180 -> V_74 . V_197 . V_285 ;
F_24 ( F_199 ( V_4 ) , V_66 ) ;
V_66 = F_30 ( F_198 ( V_4 ) ) ;
V_66 |= V_440 ;
F_24 ( F_198 ( V_4 ) , V_66 ) ;
F_41 ( F_198 ( V_4 ) ) ;
if ( F_202 ( ( F_30 ( F_198 ( V_4 ) ) &
V_441 ) , 200 ) )
F_31 ( L_26 , V_4 ) ;
V_66 = F_30 ( F_203 ( V_4 ) ) ;
V_66 &= ~ V_442 ;
V_66 &= ~ V_288 ;
V_66 |= V_180 -> V_74 . V_197 . V_287 ;
F_24 ( F_204 ( V_4 ) , V_66 ) ;
}
static void F_205 ( struct V_17 * V_18 ,
struct V_193 * V_180 )
{
enum V_4 V_4 = (enum V_4 ) V_180 -> V_227 ;
T_4 V_66 ;
V_66 = F_30 ( F_198 ( V_4 ) ) ;
V_66 &= ~ V_440 ;
F_24 ( F_198 ( V_4 ) , V_66 ) ;
F_41 ( F_198 ( V_4 ) ) ;
}
static bool F_206 ( struct V_17 * V_18 ,
struct V_193 * V_180 ,
struct V_194 * V_197 )
{
enum V_4 V_4 = (enum V_4 ) V_180 -> V_227 ;
T_4 V_179 ;
bool V_96 ;
if ( ! F_121 ( V_18 , V_392 ) )
return false ;
V_96 = false ;
V_179 = F_30 ( F_198 ( V_4 ) ) ;
if ( ! ( V_179 & V_440 ) )
goto V_332;
V_197 -> V_209 = F_30 ( F_200 ( V_4 ) ) ;
V_197 -> V_209 &= V_210 | V_212 ;
V_197 -> V_285 = F_30 ( F_199 ( V_4 ) ) ;
V_197 -> V_285 &= V_286 ;
V_197 -> V_200 = F_30 ( F_201 ( V_4 , 0 ) ) ;
V_197 -> V_200 &= V_201 ;
V_197 -> V_206 = F_30 ( F_201 ( V_4 , 1 ) ) ;
V_197 -> V_206 &= V_207 ;
V_197 -> V_204 = F_30 ( F_201 ( V_4 , 2 ) ) ;
V_197 -> V_204 &= V_205 ;
V_197 -> V_202 = F_30 ( F_201 ( V_4 , 3 ) ) ;
V_197 -> V_202 &= V_203 ;
V_197 -> V_278 = F_30 ( F_201 ( V_4 , 6 ) ) ;
V_197 -> V_278 &= V_433 |
V_434 |
V_435 ;
V_197 -> V_279 = F_30 ( F_201 ( V_4 , 8 ) ) ;
V_197 -> V_279 &= V_436 ;
V_197 -> V_280 = F_30 ( F_201 ( V_4 , 9 ) ) ;
V_197 -> V_280 &= V_437 ;
V_197 -> V_282 = F_30 ( F_201 ( V_4 , 10 ) ) ;
V_197 -> V_282 &= V_284 |
V_438 ;
V_197 -> V_287 = F_30 ( F_203 ( V_4 ) ) ;
if ( F_30 ( F_207 ( V_4 ) ) != V_197 -> V_287 )
F_85 ( L_27 ,
V_197 -> V_287 ,
F_30 ( F_207 ( V_4 ) ) ) ;
V_197 -> V_287 &= V_442 | V_288 ;
V_96 = true ;
V_332:
F_122 ( V_18 , V_392 ) ;
return V_96 ;
}
static void F_208 ( struct V_17 * V_18 )
{
int V_31 ;
V_18 -> V_393 = 3 ;
for ( V_31 = 0 ; V_31 < V_18 -> V_393 ; V_31 ++ ) {
V_18 -> V_196 [ V_31 ] . V_227 = V_31 ;
V_18 -> V_196 [ V_31 ] . V_394 = V_443 [ V_31 ] ;
V_18 -> V_196 [ V_31 ] . V_396 = F_205 ;
V_18 -> V_196 [ V_31 ] . V_363 = F_197 ;
V_18 -> V_196 [ V_31 ] . V_331 =
F_206 ;
}
}
void F_209 ( struct V_63 * V_29 )
{
struct V_17 * V_18 = V_29 -> V_64 ;
T_4 V_179 = F_30 ( V_444 ) ;
if ( F_18 ( V_29 ) || F_19 ( V_29 ) )
F_181 ( V_18 ) ;
else if ( F_16 ( V_29 ) )
F_208 ( V_18 ) ;
else
F_175 ( V_18 ) ;
if ( F_18 ( V_29 ) || F_19 ( V_29 ) ) {
int V_445 ;
V_445 = V_18 -> V_446 . V_447 ( V_29 ) ;
V_18 -> V_448 = V_445 ;
if ( F_210 ( V_18 ) )
F_48 ( L_28 ) ;
if ( ! ( F_30 ( V_449 ) & V_400 ) )
F_31 ( L_29 ) ;
} else if ( F_16 ( V_29 ) ) {
F_211 ( V_29 ) ;
F_194 ( V_29 ) ;
} else {
if ( V_179 & V_450 )
F_31 ( L_30 ) ;
if ( V_179 & V_451 )
F_31 ( L_31 ) ;
}
}
void F_212 ( struct V_91 * V_91 )
{
struct V_2 * V_92 = F_141 ( V_91 ) ;
struct V_17 * V_18 =
F_15 ( V_92 -> V_7 . V_7 . V_29 ) ;
enum V_4 V_4 = V_92 -> V_4 ;
T_4 V_179 ;
bool V_387 = false ;
if ( F_30 ( F_43 ( V_4 ) ) & V_82 ) {
V_179 = F_30 ( F_28 ( V_4 ) ) ;
if ( V_179 & V_83 ) {
V_179 &= ~ V_83 ;
F_24 ( F_28 ( V_4 ) , V_179 ) ;
V_387 = true ;
}
V_179 = F_30 ( F_43 ( V_4 ) ) ;
V_179 &= ~ ( V_82 | V_89 ) ;
V_179 |= V_81 ;
F_24 ( F_43 ( V_4 ) , V_179 ) ;
F_41 ( F_43 ( V_4 ) ) ;
if ( V_387 )
F_27 ( V_18 , V_4 ) ;
}
V_179 = V_82 |
V_81 | V_452 ;
if ( V_91 -> V_320 )
V_179 |= V_453 ;
else {
V_179 |= V_454 ;
if ( F_213 ( V_91 -> V_455 ) )
V_179 |= V_80 ;
}
F_24 ( F_43 ( V_4 ) , V_179 ) ;
F_41 ( F_43 ( V_4 ) ) ;
V_91 -> V_93 |= V_83 ;
F_24 ( F_28 ( V_4 ) , V_91 -> V_93 ) ;
F_41 ( F_28 ( V_4 ) ) ;
F_29 ( 600 ) ;
}
void F_214 ( struct V_61 * V_62 )
{
struct V_17 * V_18 = V_62 -> V_29 -> V_64 ;
struct V_1 * V_1 = F_52 ( V_62 ) ;
T_4 V_179 ;
F_155 ( V_1 ) ;
V_179 = F_30 ( F_40 ( V_68 ) ) ;
V_179 &= ~ V_84 ;
F_24 ( F_40 ( V_68 ) , V_179 ) ;
V_179 = F_30 ( F_36 ( V_68 ) ) ;
V_179 &= ~ ( V_86 | V_87 ) ;
V_179 |= F_37 ( 2 ) | F_38 ( 2 ) ;
F_24 ( F_36 ( V_68 ) , V_179 ) ;
V_179 = F_30 ( F_40 ( V_68 ) ) ;
V_179 &= ~ V_76 ;
F_24 ( F_40 ( V_68 ) , V_179 ) ;
V_179 = F_30 ( F_40 ( V_68 ) ) ;
V_179 &= ~ V_73 ;
F_24 ( F_40 ( V_68 ) , V_179 ) ;
}
void F_215 ( struct V_1 * V_6 ,
struct V_99 * V_158 )
{
struct V_17 * V_18 = V_6 -> V_7 . V_29 -> V_64 ;
struct V_65 * V_65 = F_34 ( V_6 -> V_7 . V_62 ) ;
enum V_289 V_290 = V_158 -> V_290 ;
struct V_385 * V_385 ;
T_1 V_66 , V_302 = 0 ;
V_66 = F_30 ( F_115 ( V_290 ) ) ;
if ( V_66 & V_306 )
V_302 |= V_305 ;
else
V_302 |= V_456 ;
if ( V_66 & V_304 )
V_302 |= V_303 ;
else
V_302 |= V_457 ;
V_158 -> V_7 . V_168 . V_302 |= V_302 ;
switch ( V_66 & V_458 ) {
case V_298 :
V_158 -> V_166 = 18 ;
break;
case V_299 :
V_158 -> V_166 = 24 ;
break;
case V_300 :
V_158 -> V_166 = 30 ;
break;
case V_301 :
V_158 -> V_166 = 36 ;
break;
default:
break;
}
switch ( V_66 & V_333 ) {
case V_317 :
V_158 -> V_165 = true ;
V_385 = F_154 ( & V_6 -> V_7 ) ;
if ( V_385 -> V_459 ( & V_6 -> V_7 , V_158 ) )
V_158 -> V_460 = true ;
break;
case V_318 :
case V_319 :
break;
case V_322 :
case V_321 :
V_158 -> V_163 = true ;
V_158 -> V_95 =
( ( V_66 & V_461 ) >> V_462 ) + 1 ;
F_216 ( V_65 , V_158 ) ;
break;
default:
break;
}
if ( F_217 ( V_18 , V_390 ) ) {
V_66 = F_30 ( V_463 ) ;
if ( V_66 & F_218 ( V_65 -> V_98 ) )
V_158 -> V_389 = true ;
}
if ( V_6 -> type == V_11 && V_18 -> V_43 . V_464 &&
V_158 -> V_166 > V_18 -> V_43 . V_464 ) {
F_48 ( L_32 ,
V_158 -> V_166 , V_18 -> V_43 . V_464 ) ;
V_18 -> V_43 . V_464 = V_158 -> V_166 ;
}
F_77 ( V_6 , V_158 ) ;
}
static bool F_219 ( struct V_1 * V_6 ,
struct V_99 * V_158 )
{
int type = V_6 -> type ;
int V_4 = F_5 ( V_6 ) ;
F_4 ( type == V_13 , L_33 ) ;
if ( V_4 == V_48 )
V_158 -> V_290 = V_307 ;
if ( type == V_12 )
return F_220 ( V_6 , V_158 ) ;
else
return F_221 ( V_6 , V_158 ) ;
}
static struct V_326 *
F_222 ( struct V_2 * V_92 )
{
struct V_326 * V_104 ;
enum V_4 V_4 = V_92 -> V_4 ;
V_104 = F_223 () ;
if ( ! V_104 )
return NULL ;
V_92 -> V_323 . V_465 = F_28 ( V_4 ) ;
if ( ! F_224 ( V_92 , V_104 ) ) {
F_225 ( V_104 ) ;
return NULL ;
}
return V_104 ;
}
static struct V_326 *
F_226 ( struct V_2 * V_92 )
{
struct V_326 * V_104 ;
enum V_4 V_4 = V_92 -> V_4 ;
V_104 = F_223 () ;
if ( ! V_104 )
return NULL ;
V_92 -> V_466 . V_467 = F_28 ( V_4 ) ;
F_227 ( V_92 , V_104 ) ;
return V_104 ;
}
void F_228 ( struct V_63 * V_29 , enum V_4 V_4 )
{
struct V_17 * V_18 = V_29 -> V_64 ;
struct V_2 * V_92 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
bool V_468 , V_469 ;
int V_470 ;
if ( F_30 ( F_28 ( V_48 ) ) & V_471 ) {
switch ( V_4 ) {
case V_48 :
V_470 = 4 ;
break;
case V_15 :
V_470 = 0 ;
break;
default:
V_470 = 4 ;
break;
}
} else {
switch ( V_4 ) {
case V_48 :
V_470 = 2 ;
break;
case V_15 :
V_470 = 2 ;
break;
default:
V_470 = 4 ;
break;
}
}
V_468 = ( V_18 -> V_43 . V_44 [ V_4 ] . V_472 ||
V_18 -> V_43 . V_44 [ V_4 ] . V_473 ) ;
V_469 = V_18 -> V_43 . V_44 [ V_4 ] . V_474 ;
if ( ! V_469 && ! V_468 ) {
F_48 ( L_34 ,
F_32 ( V_4 ) ) ;
return;
}
V_92 = F_229 ( sizeof( * V_92 ) , V_475 ) ;
if ( ! V_92 )
return;
V_1 = & V_92 -> V_7 ;
V_6 = & V_1 -> V_7 ;
F_230 ( V_29 , V_6 , & V_476 ,
V_477 , NULL ) ;
V_1 -> V_478 = F_219 ;
V_1 -> V_363 = F_158 ;
V_1 -> V_479 = F_148 ;
V_1 -> V_396 = F_164 ;
V_1 -> V_480 = F_155 ;
V_1 -> V_331 = F_123 ;
V_1 -> V_481 = F_215 ;
V_1 -> V_482 = V_483 ;
V_92 -> V_4 = V_4 ;
V_92 -> V_94 = F_30 ( F_28 ( V_4 ) ) &
( V_484 |
V_471 ) ;
if ( F_16 ( V_29 ) && V_4 == V_48 ) {
if ( ! ( V_92 -> V_94 & V_471 ) ) {
F_48 ( L_35 ) ;
V_92 -> V_94 |= V_471 ;
V_470 = 4 ;
}
}
V_92 -> V_470 = V_470 ;
V_1 -> type = V_13 ;
V_1 -> V_231 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_1 -> V_485 = 0 ;
if ( V_469 ) {
if ( ! F_222 ( V_92 ) )
goto V_486;
V_92 -> V_487 = V_488 ;
if ( F_231 ( V_29 , 0 , V_489 ) && V_4 == V_408 )
V_18 -> V_490 . V_491 [ V_48 ] = V_92 ;
else
V_18 -> V_490 . V_491 [ V_4 ] = V_92 ;
}
if ( V_1 -> type != V_11 && V_468 ) {
if ( ! F_226 ( V_92 ) )
goto V_486;
}
return;
V_486:
F_232 ( V_6 ) ;
F_225 ( V_92 ) ;
}
