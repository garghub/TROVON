enum V_1 F_1 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int type = V_2 -> type ;
if ( type == V_6 ) {
struct V_7 * V_8 = F_2 ( V_4 ) -> V_9 ;
return V_8 -> V_1 ;
} else if ( type == V_10 || type == V_11 ||
type == V_12 || type == V_13 ) {
struct V_7 * V_8 =
F_3 ( V_4 ) ;
return V_8 -> V_1 ;
} else if ( type == V_14 ) {
return V_15 ;
} else {
F_4 ( L_1 , type ) ;
F_5 () ;
}
}
static void F_6 ( struct V_16 * V_17 , enum V_1 V_1 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
T_1 V_21 ;
int V_22 , V_23 , V_24 , V_25 , V_26 ,
V_27 ;
int V_28 = V_19 -> V_29 . V_30 [ V_1 ] . V_31 ;
const struct V_32 * V_33 ;
const struct V_32 * V_34 ;
const struct V_32 * V_35 ;
const struct V_32 * V_36 ;
const struct V_32 * V_37 ;
if ( F_7 ( V_17 ) ) {
V_33 = NULL ;
V_34 = V_38 ;
V_24 = F_8 ( V_38 ) ;
if ( V_19 -> V_29 . V_39 ) {
V_35 = V_40 ;
V_25 = F_8 ( V_40 ) ;
} else {
V_35 = V_38 ;
V_25 = F_8 ( V_38 ) ;
}
V_28 = 0 ;
V_36 = V_41 ;
V_23 = F_8 ( V_41 ) ;
V_26 = 0 ;
} else if ( F_9 ( V_17 ) ) {
V_33 = V_42 ;
V_34 = V_43 ;
V_35 = V_44 ;
V_36 = V_45 ;
V_25 = F_8 ( V_44 ) ;
V_24 = F_8 ( V_43 ) ;
V_23 = F_8 ( V_45 ) ;
V_26 = 7 ;
} else if ( F_10 ( V_17 ) ) {
V_33 = V_46 ;
V_34 = V_47 ;
V_35 = V_47 ;
V_36 = V_48 ;
V_24 = V_25 = F_8 ( V_47 ) ;
V_23 = F_8 ( V_48 ) ;
V_26 = 6 ;
} else {
F_11 ( 1 , L_2 ) ;
V_35 = V_43 ;
V_33 = V_42 ;
V_34 = V_43 ;
V_36 = V_45 ;
V_25 = F_8 ( V_44 ) ;
V_24 = F_8 ( V_43 ) ;
V_23 = F_8 ( V_45 ) ;
V_26 = 7 ;
}
switch ( V_1 ) {
case V_49 :
V_37 = V_35 ;
V_27 = V_25 ;
break;
case V_50 :
case V_51 :
V_37 = V_34 ;
V_27 = V_24 ;
break;
case V_52 :
if ( F_12 ( V_17 , V_52 ) ) {
V_37 = V_35 ;
V_27 = V_25 ;
} else {
V_37 = V_34 ;
V_27 = V_24 ;
}
break;
case V_15 :
if ( V_33 )
V_37 = V_33 ;
else
V_37 = V_34 ;
V_27 = V_24 ;
break;
default:
F_5 () ;
}
for ( V_22 = 0 , V_21 = F_13 ( V_1 ) ; V_22 < V_27 ; V_22 ++ ) {
F_14 ( V_21 , V_37 [ V_22 ] . V_53 ) ;
V_21 += 4 ;
F_14 ( V_21 , V_37 [ V_22 ] . V_54 ) ;
V_21 += 4 ;
}
if ( V_28 == V_55 ||
V_28 >= V_23 )
V_28 = V_26 ;
F_14 ( V_21 , V_36 [ V_28 ] . V_53 ) ;
V_21 += 4 ;
F_14 ( V_21 , V_36 [ V_28 ] . V_54 ) ;
V_21 += 4 ;
}
void F_15 ( struct V_16 * V_17 )
{
int V_1 ;
if ( ! F_16 ( V_17 ) )
return;
for ( V_1 = V_49 ; V_1 <= V_15 ; V_1 ++ )
F_6 ( V_17 , V_1 ) ;
}
static void F_17 ( struct V_18 * V_19 ,
enum V_1 V_1 )
{
T_2 V_21 = F_18 ( V_1 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
F_19 ( 1 ) ;
if ( F_20 ( V_21 ) & V_56 )
return;
}
F_4 ( L_3 , F_21 ( V_1 ) ) ;
}
void F_22 ( struct V_57 * V_58 )
{
struct V_16 * V_17 = V_58 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_59 * V_59 = F_23 ( V_58 ) ;
T_1 V_60 , V_22 , V_61 ;
F_14 ( V_62 , F_24 ( 2 ) |
F_25 ( 2 ) |
V_63 | V_64 ) ;
V_61 = V_19 -> V_65 | V_66 |
V_67 |
F_26 ( V_59 -> V_68 -> V_69 ) ;
F_14 ( V_70 , V_61 ) ;
F_27 ( V_70 ) ;
F_19 ( 220 ) ;
V_61 |= V_71 ;
F_14 ( V_70 , V_61 ) ;
F_14 ( F_28 ( V_15 ) , V_59 -> V_68 -> V_72 ) ;
F_29 ( V_59 -> V_68 -> V_72 != V_73 ) ;
for ( V_22 = 0 ; V_22 < F_8 ( V_46 ) * 2 ; V_22 ++ ) {
F_14 ( F_30 ( V_15 ) ,
V_74 |
V_75 |
V_76 |
V_77 ) ;
F_14 ( F_18 ( V_15 ) ,
V_78 |
( ( V_59 -> V_68 -> V_69 - 1 ) << 1 ) |
F_31 ( V_22 / 2 ) ) ;
F_27 ( F_18 ( V_15 ) ) ;
F_19 ( 600 ) ;
F_14 ( V_79 , F_32 ( 64 ) ) ;
V_61 |= V_80 | V_81 ;
F_14 ( V_70 , V_61 ) ;
F_27 ( V_70 ) ;
F_19 ( 30 ) ;
V_60 = F_20 ( V_62 ) ;
V_60 &= ~ ( V_82 | V_83 ) ;
F_14 ( V_62 , V_60 ) ;
F_27 ( V_62 ) ;
F_19 ( 5 ) ;
V_60 = F_20 ( F_33 ( V_15 ) ) ;
if ( V_60 & V_84 ) {
F_34 ( L_4 , V_22 ) ;
F_14 ( F_30 ( V_15 ) ,
V_74 |
V_85 |
V_75 |
V_77 ) ;
return;
}
V_60 = F_20 ( F_18 ( V_15 ) ) ;
V_60 &= ~ V_78 ;
F_14 ( F_18 ( V_15 ) , V_60 ) ;
F_27 ( F_18 ( V_15 ) ) ;
V_60 = F_20 ( F_30 ( V_15 ) ) ;
V_60 &= ~ ( V_77 | V_86 ) ;
V_60 |= V_76 ;
F_14 ( F_30 ( V_15 ) , V_60 ) ;
F_27 ( F_30 ( V_15 ) ) ;
F_17 ( V_19 , V_15 ) ;
V_61 &= ~ V_80 ;
F_14 ( V_70 , V_61 ) ;
F_27 ( V_70 ) ;
V_60 = F_20 ( V_62 ) ;
V_60 &= ~ ( V_82 | V_83 ) ;
V_60 |= F_24 ( 2 ) | F_25 ( 2 ) ;
F_14 ( V_62 , V_60 ) ;
F_27 ( V_62 ) ;
}
F_4 ( L_5 ) ;
}
void F_35 ( struct V_2 * V_4 )
{
struct V_87 * V_87 = F_36 ( & V_4 -> V_5 ) ;
struct V_7 * V_8 =
F_3 ( & V_4 -> V_5 ) ;
V_87 -> V_88 = V_8 -> V_89 |
V_78 | F_31 ( 0 ) ;
V_87 -> V_88 |= F_37 ( V_87 -> V_90 ) ;
}
static struct V_2 *
F_38 ( struct V_57 * V_58 )
{
struct V_16 * V_17 = V_58 -> V_17 ;
struct V_59 * V_59 = F_23 ( V_58 ) ;
struct V_2 * V_2 , * V_91 = NULL ;
int V_92 = 0 ;
F_39 (dev, crtc, intel_encoder) {
V_91 = V_2 ;
V_92 ++ ;
}
if ( V_92 != 1 )
F_11 ( 1 , L_6 , V_92 ,
F_40 ( V_59 -> V_93 ) ) ;
F_41 ( V_91 == NULL ) ;
return V_91 ;
}
static struct V_2 *
F_42 ( struct V_94 * V_95 )
{
struct V_59 * V_58 = F_23 ( V_95 -> V_5 . V_58 ) ;
struct V_2 * V_91 = NULL ;
struct V_96 * V_97 ;
int V_92 = 0 ;
int V_22 ;
V_97 = V_95 -> V_5 . V_97 ;
for ( V_22 = 0 ; V_22 < V_97 -> V_98 ; V_22 ++ ) {
if ( ! V_97 -> V_99 [ V_22 ] ||
V_97 -> V_100 [ V_22 ] -> V_58 != V_95 -> V_5 . V_58 )
continue;
V_91 = F_43 ( V_97 -> V_100 [ V_22 ] -> V_101 ) ;
V_92 ++ ;
}
F_11 ( V_92 != 1 , L_6 , V_92 ,
F_40 ( V_58 -> V_93 ) ) ;
F_41 ( V_91 == NULL ) ;
return V_91 ;
}
static unsigned F_44 ( int clock )
{
unsigned V_102 ;
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
V_102 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_102 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_102 = 2000 ;
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
V_102 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_102 = 5000 ;
break;
default:
V_102 = 1000 ;
break;
}
return V_102 ;
}
static void F_45 ( T_3 V_103 , unsigned V_102 ,
unsigned V_104 , unsigned V_105 , unsigned V_106 ,
struct V_107 * V_108 )
{
T_3 V_109 , V_110 , V_111 , V_112 , V_113 , V_114 ;
if ( V_108 -> V_106 == 0 ) {
V_108 -> V_106 = V_106 ;
V_108 -> V_105 = V_105 ;
V_108 -> V_104 = V_104 ;
return;
}
V_109 = V_103 * V_102 * V_106 * V_104 ;
V_110 = V_103 * V_102 * V_108 -> V_106 * V_108 -> V_104 ;
V_113 = F_46 ( V_103 * V_106 * V_104 , V_115 * V_105 ) ;
V_114 = F_46 ( V_103 * V_108 -> V_106 * V_108 -> V_104 ,
V_115 * V_108 -> V_105 ) ;
V_111 = 1000000 * V_113 ;
V_112 = 1000000 * V_114 ;
if ( V_109 < V_111 && V_110 < V_112 ) {
if ( V_108 -> V_106 * V_108 -> V_104 * V_113 < V_106 * V_104 * V_114 ) {
V_108 -> V_106 = V_106 ;
V_108 -> V_105 = V_105 ;
V_108 -> V_104 = V_104 ;
}
} else if ( V_109 >= V_111 && V_110 < V_112 ) {
V_108 -> V_106 = V_106 ;
V_108 -> V_105 = V_105 ;
V_108 -> V_104 = V_104 ;
} else if ( V_109 >= V_111 && V_110 >= V_112 ) {
if ( V_105 * V_108 -> V_104 * V_108 -> V_104 > V_108 -> V_105 * V_104 * V_104 ) {
V_108 -> V_106 = V_106 ;
V_108 -> V_105 = V_105 ;
V_108 -> V_104 = V_104 ;
}
}
}
static int F_47 ( struct V_18 * V_19 ,
int V_21 )
{
int V_116 = V_117 ;
int V_118 , V_106 , V_119 ;
T_1 V_120 ;
V_120 = F_20 ( V_21 ) ;
switch ( V_120 & V_121 ) {
case V_122 :
case V_123 :
V_116 = 135 ;
break;
case V_124 :
V_116 = V_117 ;
break;
default:
F_11 ( 1 , L_7 ) ;
return 0 ;
}
V_119 = V_120 & V_125 ;
V_106 = ( V_120 & V_126 ) >> V_127 ;
V_118 = ( V_120 & V_128 ) >> V_129 ;
return ( V_116 * V_118 * 100 ) / ( V_106 * V_119 ) ;
}
static int F_48 ( struct V_18 * V_19 ,
T_2 V_130 )
{
T_2 V_131 , V_132 ;
T_2 V_133 , V_134 ;
T_2 V_135 , V_136 , V_137 , V_138 ;
V_131 = F_49 ( V_130 ) ;
V_132 = F_50 ( V_130 ) ;
V_133 = F_20 ( V_131 ) ;
V_134 = F_20 ( V_132 ) ;
V_135 = V_134 & V_139 ;
V_137 = V_134 & V_140 ;
if ( V_134 & F_51 ( 1 ) )
V_136 = ( V_134 & V_141 ) >> 8 ;
else
V_136 = 1 ;
switch ( V_135 ) {
case V_142 :
V_135 = 1 ;
break;
case V_143 :
V_135 = 2 ;
break;
case V_144 :
V_135 = 3 ;
break;
case V_145 :
V_135 = 7 ;
break;
}
switch ( V_137 ) {
case V_146 :
V_137 = 5 ;
break;
case V_147 :
V_137 = 2 ;
break;
case V_148 :
V_137 = 3 ;
break;
case V_149 :
V_137 = 1 ;
break;
}
V_138 = ( V_133 & V_150 ) * 24 * 1000 ;
V_138 += ( ( ( V_133 & V_151 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_138 / ( V_135 * V_136 * V_137 * 5 ) ;
}
static void F_52 ( struct V_2 * V_4 ,
struct V_94 * V_152 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
int V_153 = 0 ;
T_2 V_154 , V_130 ;
V_130 = V_152 -> V_72 ;
V_154 = F_20 ( V_155 ) ;
if ( V_154 & F_53 ( V_130 ) ) {
V_153 = F_48 ( V_19 , V_130 ) ;
} else {
V_153 = V_154 & F_54 ( V_130 ) ;
V_153 >>= F_55 ( V_130 ) ;
switch ( V_153 ) {
case V_156 :
V_153 = 81000 ;
break;
case V_157 :
V_153 = 108000 ;
break;
case V_158 :
V_153 = 135000 ;
break;
case V_159 :
V_153 = 162000 ;
break;
case V_160 :
V_153 = 216000 ;
break;
case V_161 :
V_153 = 270000 ;
break;
default:
F_11 ( 1 , L_8 ) ;
break;
}
V_153 *= 2 ;
}
V_152 -> V_162 = V_153 ;
if ( V_152 -> V_163 )
V_152 -> V_5 . V_164 . V_165 =
F_56 ( V_152 -> V_162 ,
& V_152 -> V_166 ) ;
else
V_152 -> V_5 . V_164 . V_165 = V_152 -> V_162 ;
}
static void F_57 ( struct V_2 * V_4 ,
struct V_94 * V_152 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
int V_153 = 0 ;
T_1 V_167 , V_168 ;
V_167 = V_152 -> V_72 ;
switch ( V_167 & V_169 ) {
case V_170 :
V_153 = 81000 ;
break;
case V_171 :
V_153 = 135000 ;
break;
case V_172 :
V_153 = 270000 ;
break;
case V_173 :
V_153 = F_47 ( V_19 , V_174 ) ;
break;
case V_175 :
V_153 = F_47 ( V_19 , V_176 ) ;
break;
case V_73 :
V_168 = F_20 ( V_177 ) & V_178 ;
if ( V_168 == V_179 )
V_153 = 81000 ;
else if ( V_168 == V_180 )
V_153 = 135000 ;
else if ( V_168 == V_181 )
V_153 = 270000 ;
else {
F_11 ( 1 , L_9 ) ;
return;
}
break;
default:
F_11 ( 1 , L_10 ) ;
return;
}
V_152 -> V_162 = V_153 * 2 ;
if ( V_152 -> V_182 )
V_152 -> V_5 . V_164 . V_165 =
F_56 ( V_152 -> V_162 ,
& V_152 -> V_183 ) ;
else if ( V_152 -> V_163 )
V_152 -> V_5 . V_164 . V_165 =
F_56 ( V_152 -> V_162 ,
& V_152 -> V_166 ) ;
else
V_152 -> V_5 . V_164 . V_165 = V_152 -> V_162 ;
}
void F_58 ( struct V_2 * V_4 ,
struct V_94 * V_152 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_17 ;
if ( F_59 ( V_17 ) -> V_184 <= 8 )
F_57 ( V_4 , V_152 ) ;
else
F_52 ( V_4 , V_152 ) ;
}
static void
F_60 ( int clock ,
unsigned * V_185 , unsigned * V_186 , unsigned * V_187 )
{
T_3 V_103 ;
unsigned V_106 , V_105 , V_104 ;
struct V_107 V_108 = { 0 , 0 , 0 } ;
unsigned V_102 ;
V_103 = clock / 100 ;
V_102 = F_44 ( clock ) ;
if ( V_103 == 5400000 ) {
* V_186 = 2 ;
* V_187 = 1 ;
* V_185 = 2 ;
return;
}
for ( V_104 = V_117 * 2 / V_188 + 1 ;
V_104 <= V_117 * 2 / V_189 ;
V_104 ++ ) {
for ( V_105 = V_190 * V_104 / V_117 + 1 ;
V_105 <= V_191 * V_104 / V_117 ;
V_105 ++ ) {
for ( V_106 = V_192 ; V_106 <= V_193 ; V_106 += V_194 )
F_45 ( V_103 , V_102 ,
V_104 , V_105 , V_106 , & V_108 ) ;
}
}
* V_186 = V_108 . V_105 ;
* V_187 = V_108 . V_106 ;
* V_185 = V_108 . V_104 ;
}
static bool
F_61 ( struct V_59 * V_59 ,
struct V_94 * V_95 ,
struct V_2 * V_2 ,
int clock )
{
if ( V_2 -> type == V_12 ) {
struct V_195 * V_168 ;
T_2 V_167 ;
unsigned V_106 , V_105 , V_104 ;
F_60 ( clock * 1000 , & V_104 , & V_105 , & V_106 ) ;
V_167 = V_196 | V_124 |
F_62 ( V_104 ) | F_63 ( V_105 ) |
F_64 ( V_106 ) ;
V_95 -> V_197 . V_120 = V_167 ;
V_168 = F_65 ( V_59 , V_95 ) ;
if ( V_168 == NULL ) {
F_66 ( L_11 ,
F_40 ( V_59 -> V_93 ) ) ;
return false ;
}
V_95 -> V_72 = F_67 ( V_168 -> V_198 ) ;
}
return true ;
}
static void
F_68 ( int clock ,
struct V_199 * V_200 )
{
T_3 V_201 = clock * 5 ;
T_3 V_202 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
T_2 V_203 = 400 ;
T_2 V_204 = 3 ;
T_2 V_205 [ 4 ] = { 1 , 2 , 3 , 7 } ;
T_2 V_206 [ 4 ] = { 1 , 2 , 3 , 5 } ;
bool V_207 = false ;
T_2 V_208 = 0 ;
T_2 V_209 [ 3 ] = { 0 } , V_210 [ 3 ] = { 0 } ;
T_2 V_211 [ 3 ] = { 0 } ;
T_2 V_212 [ 3 ] ;
T_2 V_22 , V_213 , V_214 , V_215 ;
bool V_216 = false ;
T_3 V_138 ;
for ( V_215 = 0 ; V_215 < 3 ; V_215 ++ ) {
V_207 = false ;
V_208 =
F_69 ( V_202 [ V_215 ] , V_201 ) ;
if ( V_216 == false )
V_208 = ( V_208 % 2 == 0 ?
V_208 : V_208 + 1 ) ;
for ( V_213 = 1 ; V_213 < V_208 ; V_213 ++ ) {
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
if ( ! ( V_205 [ V_22 ] != 1 || V_213 == 1 ) )
continue;
for ( V_214 = 0 ; V_214 < 4 ; V_214 ++ ) {
if ( V_213 != 1 && V_206 [ V_214 ] != 2 )
continue;
if ( V_208 == V_205 [ V_22 ] * V_213 * V_206 [ V_214 ] ) {
V_207 = true ;
V_209 [ V_215 ] = V_205 [ V_22 ] ;
V_210 [ V_215 ] = V_213 ;
V_211 [ V_215 ] = V_206 [ V_214 ] ;
goto V_207;
}
}
}
}
V_207:
if ( V_207 ) {
V_212 [ V_215 ] =
F_69 ( 10000 *
F_46 ( ( V_208 * V_201 ) ,
V_202 [ V_215 ] ) ,
V_202 [ V_215 ] ) ;
if ( V_212 [ V_215 ] <
V_203 ) {
V_203 =
V_212 [ V_215 ] ;
V_204 = V_215 ;
}
}
if ( V_204 > 2 && V_215 == 2 ) {
V_216 = true ;
V_215 = 0 ;
}
}
if ( V_204 > 2 ) {
F_11 ( 1 , L_12 ) ;
} else {
V_200 -> V_217 = V_202 [ V_204 ] ;
switch ( V_202 [ V_204 ] ) {
case 9600000000ULL :
V_200 -> V_217 = 0 ;
break;
case 9000000000ULL :
V_200 -> V_217 = 1 ;
break;
case 8400000000ULL :
V_200 -> V_217 = 3 ;
}
switch ( V_209 [ V_204 ] ) {
case 1 :
V_200 -> V_218 = 0 ;
break;
case 2 :
V_200 -> V_218 = 1 ;
break;
case 3 :
V_200 -> V_218 = 2 ;
break;
case 7 :
V_200 -> V_218 = 4 ;
break;
default:
F_11 ( 1 , L_13 ) ;
}
switch ( V_211 [ V_204 ] ) {
case 5 :
V_200 -> V_219 = 0 ;
break;
case 2 :
V_200 -> V_219 = 1 ;
break;
case 3 :
V_200 -> V_219 = 2 ;
break;
case 1 :
V_200 -> V_219 = 3 ;
break;
default:
F_11 ( 1 , L_14 ) ;
}
V_200 -> V_220 = V_210 [ V_204 ] ;
V_200 -> V_221 =
( V_200 -> V_220 == 1 ) ? 0 : 1 ;
V_138 = V_209 [ V_204 ] *
V_210 [ V_204 ] *
V_211 [ V_204 ] * V_201 ;
V_200 -> V_222 = F_70 ( V_138 , ( 24 * F_71 ( 1 ) ) ) ;
V_200 -> V_223 =
F_70 ( ( ( F_70 ( V_138 , 24 ) -
V_200 -> V_222 * F_71 ( 1 ) ) * 0x8000 ) , F_71 ( 1 ) ) ;
}
}
static bool
F_72 ( struct V_59 * V_59 ,
struct V_94 * V_95 ,
struct V_2 * V_2 ,
int clock )
{
struct V_195 * V_168 ;
T_2 V_224 , V_225 , V_226 ;
V_224 = F_73 ( 0 ) ;
if ( V_2 -> type == V_12 ) {
struct V_199 V_200 = { 0 , } ;
V_224 |= F_53 ( 0 ) ;
F_68 ( clock * 1000 , & V_200 ) ;
V_225 = V_227 |
F_74 ( V_200 . V_223 ) |
V_200 . V_222 ;
V_226 = F_75 ( V_200 . V_220 ) |
F_51 ( V_200 . V_221 ) |
F_76 ( V_200 . V_219 ) |
F_77 ( V_200 . V_218 ) |
V_200 . V_217 ;
} else if ( V_2 -> type == V_10 ) {
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_87 * V_87 = F_36 ( V_4 ) ;
switch ( V_87 -> V_228 ) {
case V_229 :
V_224 |= F_78 ( V_156 , 0 ) ;
break;
case V_230 :
V_224 |= F_78 ( V_158 , 0 ) ;
break;
case V_231 :
V_224 |= F_78 ( V_161 , 0 ) ;
break;
}
V_225 = V_226 = 0 ;
} else
return true ;
V_95 -> V_197 . V_224 = V_224 ;
V_95 -> V_197 . V_225 = V_225 ;
V_95 -> V_197 . V_226 = V_226 ;
V_168 = F_65 ( V_59 , V_95 ) ;
if ( V_168 == NULL ) {
F_66 ( L_11 ,
F_40 ( V_59 -> V_93 ) ) ;
return false ;
}
V_95 -> V_72 = V_168 -> V_198 + 1 ;
return true ;
}
bool F_79 ( struct V_59 * V_59 ,
struct V_94 * V_95 )
{
struct V_16 * V_17 = V_59 -> V_5 . V_17 ;
struct V_2 * V_2 =
F_42 ( V_95 ) ;
int clock = V_95 -> V_162 ;
if ( F_7 ( V_17 ) )
return F_72 ( V_59 , V_95 ,
V_2 , clock ) ;
else
return F_61 ( V_59 , V_95 ,
V_2 , clock ) ;
}
void F_80 ( struct V_57 * V_58 )
{
struct V_18 * V_19 = V_58 -> V_17 -> V_20 ;
struct V_59 * V_59 = F_23 ( V_58 ) ;
struct V_2 * V_2 = F_38 ( V_58 ) ;
enum V_232 V_233 = V_59 -> V_68 -> V_233 ;
int type = V_2 -> type ;
T_2 V_60 ;
if ( type == V_10 || type == V_11 || type == V_6 ) {
V_60 = V_234 ;
switch ( V_59 -> V_68 -> V_235 ) {
case 18 :
V_60 |= V_236 ;
break;
case 24 :
V_60 |= V_237 ;
break;
case 30 :
V_60 |= V_238 ;
break;
case 36 :
V_60 |= V_239 ;
break;
default:
F_5 () ;
}
F_14 ( F_81 ( V_233 ) , V_60 ) ;
}
}
void F_82 ( struct V_57 * V_58 , bool V_97 )
{
struct V_59 * V_59 = F_23 ( V_58 ) ;
struct V_16 * V_17 = V_58 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_232 V_233 = V_59 -> V_68 -> V_233 ;
T_2 V_60 ;
V_60 = F_20 ( F_83 ( V_233 ) ) ;
if ( V_97 == true )
V_60 |= V_240 ;
else
V_60 &= ~ V_240 ;
F_14 ( F_83 ( V_233 ) , V_60 ) ;
}
void F_84 ( struct V_57 * V_58 )
{
struct V_59 * V_59 = F_23 ( V_58 ) ;
struct V_2 * V_2 = F_38 ( V_58 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_58 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_93 V_93 = V_59 -> V_93 ;
enum V_232 V_233 = V_59 -> V_68 -> V_233 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_60 ;
V_60 = V_241 ;
V_60 |= F_85 ( V_1 ) ;
switch ( V_59 -> V_68 -> V_235 ) {
case 18 :
V_60 |= V_242 ;
break;
case 24 :
V_60 |= V_243 ;
break;
case 30 :
V_60 |= V_244 ;
break;
case 36 :
V_60 |= V_245 ;
break;
default:
F_5 () ;
}
if ( V_59 -> V_68 -> V_5 . V_164 . V_246 & V_247 )
V_60 |= V_248 ;
if ( V_59 -> V_68 -> V_5 . V_164 . V_246 & V_249 )
V_60 |= V_250 ;
if ( V_233 == V_251 ) {
switch ( V_93 ) {
case V_252 :
if ( F_10 ( V_17 ) &&
( V_59 -> V_68 -> V_253 . V_254 ||
V_59 -> V_68 -> V_253 . V_255 ) )
V_60 |= V_256 ;
else
V_60 |= V_257 ;
break;
case V_258 :
V_60 |= V_259 ;
break;
case V_260 :
V_60 |= V_261 ;
break;
default:
F_5 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_59 -> V_68 -> V_262 )
V_60 |= V_263 ;
else
V_60 |= V_264 ;
} else if ( type == V_14 ) {
V_60 |= V_265 ;
V_60 |= ( V_59 -> V_68 -> V_69 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_87 * V_87 = F_36 ( V_4 ) ;
if ( V_87 -> V_266 ) {
V_60 |= V_267 ;
} else
V_60 |= V_268 ;
V_60 |= F_37 ( V_87 -> V_90 ) ;
} else if ( type == V_6 ) {
struct V_87 * V_87 = & F_2 ( V_4 ) -> V_9 -> V_269 ;
if ( V_87 -> V_266 ) {
V_60 |= V_267 ;
} else
V_60 |= V_268 ;
V_60 |= F_37 ( V_87 -> V_90 ) ;
} else {
F_11 ( 1 , L_15 ,
V_2 -> type , F_40 ( V_93 ) ) ;
}
F_14 ( F_83 ( V_233 ) , V_60 ) ;
}
void F_86 ( struct V_18 * V_19 ,
enum V_232 V_233 )
{
T_2 V_21 = F_83 ( V_233 ) ;
T_2 V_167 = F_20 ( V_21 ) ;
V_167 &= ~ ( V_241 | V_270 | V_240 ) ;
V_167 |= V_271 ;
F_14 ( V_21 , V_167 ) ;
}
bool F_87 ( struct V_272 * V_272 )
{
struct V_16 * V_17 = V_272 -> V_5 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_2 * V_2 = V_272 -> V_4 ;
int type = V_272 -> V_5 . V_273 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_93 V_93 = 0 ;
enum V_232 V_233 ;
enum V_274 V_275 ;
T_2 V_276 ;
V_275 = F_88 ( V_2 ) ;
if ( ! F_89 ( V_19 , V_275 ) )
return false ;
if ( ! V_2 -> V_277 ( V_2 , & V_93 ) )
return false ;
if ( V_1 == V_49 )
V_233 = V_251 ;
else
V_233 = (enum V_232 ) V_93 ;
V_276 = F_20 ( F_83 ( V_233 ) ) ;
switch ( V_276 & V_278 ) {
case V_263 :
case V_264 :
return ( type == V_279 ) ;
case V_268 :
if ( type == V_280 )
return true ;
return ( type == V_281 ) ;
case V_267 :
return false ;
case V_265 :
return ( type == V_282 ) ;
default:
return false ;
}
}
bool F_90 ( struct V_2 * V_4 ,
enum V_93 * V_93 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
enum V_274 V_275 ;
T_1 V_276 ;
int V_22 ;
V_275 = F_88 ( V_4 ) ;
if ( ! F_89 ( V_19 , V_275 ) )
return false ;
V_276 = F_20 ( F_18 ( V_1 ) ) ;
if ( ! ( V_276 & V_78 ) )
return false ;
if ( V_1 == V_49 ) {
V_276 = F_20 ( F_83 ( V_251 ) ) ;
switch ( V_276 & V_283 ) {
case V_257 :
case V_256 :
* V_93 = V_252 ;
break;
case V_259 :
* V_93 = V_258 ;
break;
case V_261 :
* V_93 = V_260 ;
break;
}
return true ;
} else {
for ( V_22 = V_284 ; V_22 <= V_285 ; V_22 ++ ) {
V_276 = F_20 ( F_83 ( V_22 ) ) ;
if ( ( V_276 & V_270 )
== F_85 ( V_1 ) ) {
if ( ( V_276 & V_278 ) == V_267 )
return false ;
* V_93 = V_22 ;
return true ;
}
}
}
F_34 ( L_16 , F_21 ( V_1 ) ) ;
return false ;
}
void F_91 ( struct V_59 * V_59 )
{
struct V_57 * V_58 = & V_59 -> V_5 ;
struct V_18 * V_19 = V_58 -> V_17 -> V_20 ;
struct V_2 * V_2 = F_38 ( V_58 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_232 V_233 = V_59 -> V_68 -> V_233 ;
if ( V_233 != V_251 )
F_14 ( F_92 ( V_233 ) ,
F_93 ( V_1 ) ) ;
}
void F_94 ( struct V_59 * V_59 )
{
struct V_18 * V_19 = V_59 -> V_5 . V_17 -> V_20 ;
enum V_232 V_233 = V_59 -> V_68 -> V_233 ;
if ( V_233 != V_251 )
F_14 ( F_92 ( V_233 ) ,
V_286 ) ;
}
static void F_95 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_59 * V_58 = F_23 ( V_4 -> V_58 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_11 ) {
struct V_87 * V_87 = F_36 ( V_4 ) ;
F_96 ( V_87 ) ;
}
if ( F_7 ( V_17 ) ) {
T_2 V_130 = V_58 -> V_68 -> V_72 ;
T_2 V_167 ;
if ( type == V_11 ) {
F_29 ( V_130 != V_287 ) ;
V_167 = F_20 ( V_155 ) ;
V_167 &= ~ ( F_53 ( V_130 ) |
F_97 ( V_130 ) |
F_54 ( V_130 ) ) ;
V_167 |= V_58 -> V_68 -> V_197 . V_224 << ( V_130 * 6 ) ;
F_14 ( V_155 , V_167 ) ;
F_27 ( V_155 ) ;
}
V_167 = F_20 ( V_288 ) ;
V_167 &= ~ ( F_98 ( V_1 ) |
F_99 ( V_1 ) ) ;
V_167 |= ( F_100 ( V_130 , V_1 ) |
F_101 ( V_1 ) ) ;
F_14 ( V_288 , V_167 ) ;
} else {
F_29 ( V_58 -> V_68 -> V_72 == V_289 ) ;
F_14 ( F_28 ( V_1 ) , V_58 -> V_68 -> V_72 ) ;
}
if ( type == V_10 || type == V_11 ) {
struct V_87 * V_87 = F_36 ( V_4 ) ;
F_35 ( V_2 ) ;
F_102 ( V_87 , V_290 ) ;
F_103 ( V_87 ) ;
F_104 ( V_87 ) ;
if ( V_1 != V_49 || F_59 ( V_17 ) -> V_184 >= 9 )
F_105 ( V_87 ) ;
} else if ( type == V_12 ) {
struct V_291 * V_291 = F_106 ( V_4 ) ;
V_291 -> V_292 ( V_4 ,
V_58 -> V_68 -> V_262 ,
& V_58 -> V_68 -> V_5 . V_164 ) ;
}
}
static void F_107 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_167 ;
bool V_293 = false ;
V_167 = F_20 ( F_18 ( V_1 ) ) ;
if ( V_167 & V_78 ) {
V_167 &= ~ V_78 ;
F_14 ( F_18 ( V_1 ) , V_167 ) ;
V_293 = true ;
}
V_167 = F_20 ( F_30 ( V_1 ) ) ;
V_167 &= ~ ( V_77 | V_86 ) ;
V_167 |= V_76 ;
F_14 ( F_30 ( V_1 ) , V_167 ) ;
if ( V_293 )
F_17 ( V_19 , V_1 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_87 * V_87 = F_36 ( V_4 ) ;
F_102 ( V_87 , V_294 ) ;
F_108 ( V_87 ) ;
F_109 ( V_87 ) ;
}
if ( F_7 ( V_17 ) )
F_14 ( V_288 , ( F_20 ( V_288 ) |
F_98 ( V_1 ) ) ) ;
else
F_14 ( F_28 ( V_1 ) , V_289 ) ;
}
static void F_110 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_57 * V_58 = V_4 -> V_58 ;
struct V_59 * V_59 = F_23 ( V_58 ) ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_12 ) {
struct V_7 * V_8 =
F_3 ( V_4 ) ;
F_14 ( F_18 ( V_1 ) ,
V_8 -> V_89 |
V_78 ) ;
} else if ( type == V_11 ) {
struct V_87 * V_87 = F_36 ( V_4 ) ;
if ( V_1 == V_49 && F_59 ( V_17 ) -> V_184 < 9 )
F_105 ( V_87 ) ;
F_111 ( V_87 ) ;
F_112 ( V_87 ) ;
F_113 ( V_87 ) ;
}
if ( V_59 -> V_68 -> V_295 ) {
F_114 ( V_19 , V_296 ) ;
F_115 ( V_2 ) ;
}
}
static void F_116 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_57 * V_58 = V_4 -> V_58 ;
struct V_59 * V_59 = F_23 ( V_58 ) ;
int type = V_2 -> type ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
if ( V_59 -> V_68 -> V_295 ) {
F_117 ( V_2 ) ;
F_118 ( V_19 , V_296 ) ;
}
if ( type == V_11 ) {
struct V_87 * V_87 = F_36 ( V_4 ) ;
F_119 ( V_87 ) ;
F_120 ( V_87 ) ;
F_121 ( V_87 ) ;
}
}
static int F_122 ( struct V_18 * V_19 )
{
T_2 V_297 = F_20 ( V_298 ) ;
T_2 V_299 = F_20 ( V_300 ) ;
T_2 V_301 ;
if ( ! ( V_297 & V_302 ) ) {
F_11 ( 1 , L_17 ) ;
return 24000 ;
}
if ( ( V_299 & V_303 ) == V_304 )
return 540000 ;
V_301 = ( F_20 ( V_155 ) &
F_54 ( V_287 ) ) >> 1 ;
if ( V_301 == V_160 ||
V_301 == V_157 ) {
switch ( V_299 & V_303 ) {
case V_305 :
return 432000 ;
case V_306 :
return 308570 ;
case V_307 :
return 617140 ;
default:
F_11 ( 1 , L_18 ) ;
}
} else {
switch ( V_299 & V_303 ) {
case V_305 :
return 450000 ;
case V_306 :
return 337500 ;
case V_307 :
return 675000 ;
default:
F_11 ( 1 , L_18 ) ;
}
}
return 24000 ;
}
static int F_123 ( struct V_18 * V_19 )
{
T_2 V_308 = F_20 ( V_309 ) ;
T_2 V_310 = V_308 & V_311 ;
if ( V_308 & V_312 )
return 800000 ;
else if ( F_20 ( V_313 ) & V_314 )
return 450000 ;
else if ( V_310 == V_315 )
return 450000 ;
else if ( V_310 == V_316 )
return 540000 ;
else if ( V_310 == V_317 )
return 337500 ;
else
return 675000 ;
}
static int F_124 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_17 ;
T_2 V_308 = F_20 ( V_309 ) ;
T_2 V_310 = V_308 & V_311 ;
if ( V_308 & V_312 )
return 800000 ;
else if ( F_20 ( V_313 ) & V_314 )
return 450000 ;
else if ( V_310 == V_315 )
return 450000 ;
else if ( F_125 ( V_17 ) )
return 337500 ;
else
return 540000 ;
}
int F_126 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_17 ;
if ( F_7 ( V_17 ) )
return F_122 ( V_19 ) ;
if ( F_9 ( V_17 ) )
return F_123 ( V_19 ) ;
return F_124 ( V_19 ) ;
}
static void F_127 ( struct V_18 * V_19 ,
struct V_195 * V_168 )
{
F_14 ( F_128 ( V_168 -> V_198 ) , V_168 -> V_68 . V_318 . V_120 ) ;
F_27 ( F_128 ( V_168 -> V_198 ) ) ;
F_19 ( 20 ) ;
}
static void F_129 ( struct V_18 * V_19 ,
struct V_195 * V_168 )
{
T_2 V_167 ;
V_167 = F_20 ( F_128 ( V_168 -> V_198 ) ) ;
F_14 ( F_128 ( V_168 -> V_198 ) , V_167 & ~ V_196 ) ;
F_27 ( F_128 ( V_168 -> V_198 ) ) ;
}
static bool F_130 ( struct V_18 * V_19 ,
struct V_195 * V_168 ,
struct V_319 * V_318 )
{
T_2 V_167 ;
if ( ! F_89 ( V_19 , V_320 ) )
return false ;
V_167 = F_20 ( F_128 ( V_168 -> V_198 ) ) ;
V_318 -> V_120 = V_167 ;
return V_167 & V_196 ;
}
static void F_131 ( struct V_18 * V_19 )
{
int V_22 ;
V_19 -> V_321 = 2 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_321 ; V_22 ++ ) {
V_19 -> V_322 [ V_22 ] . V_198 = V_22 ;
V_19 -> V_322 [ V_22 ] . V_323 = V_324 [ V_22 ] ;
V_19 -> V_322 [ V_22 ] . V_325 = F_129 ;
V_19 -> V_322 [ V_22 ] . V_326 = F_127 ;
V_19 -> V_322 [ V_22 ] . V_277 =
F_130 ;
}
}
static void F_132 ( struct V_18 * V_19 ,
struct V_195 * V_168 )
{
T_2 V_167 ;
unsigned int V_130 ;
const struct V_327 * V_328 = V_327 ;
V_130 = V_168 -> V_198 + 1 ;
V_167 = F_20 ( V_155 ) ;
V_167 &= ~ ( F_53 ( V_130 ) | F_97 ( V_130 ) |
F_54 ( V_130 ) ) ;
V_167 |= V_168 -> V_68 . V_318 . V_224 << ( V_130 * 6 ) ;
F_14 ( V_155 , V_167 ) ;
F_27 ( V_155 ) ;
F_14 ( V_328 [ V_168 -> V_198 ] . V_225 , V_168 -> V_68 . V_318 . V_225 ) ;
F_14 ( V_328 [ V_168 -> V_198 ] . V_226 , V_168 -> V_68 . V_318 . V_226 ) ;
F_27 ( V_328 [ V_168 -> V_198 ] . V_225 ) ;
F_27 ( V_328 [ V_168 -> V_198 ] . V_226 ) ;
F_14 ( V_328 [ V_168 -> V_198 ] . V_329 ,
F_20 ( V_328 [ V_168 -> V_198 ] . V_329 ) | V_302 ) ;
if ( F_133 ( F_20 ( V_330 ) & F_134 ( V_130 ) , 5 ) )
F_4 ( L_19 , V_130 ) ;
}
static void F_135 ( struct V_18 * V_19 ,
struct V_195 * V_168 )
{
const struct V_327 * V_328 = V_327 ;
F_14 ( V_328 [ V_168 -> V_198 ] . V_329 ,
F_20 ( V_328 [ V_168 -> V_198 ] . V_329 ) & ~ V_302 ) ;
F_27 ( V_328 [ V_168 -> V_198 ] . V_329 ) ;
}
static bool F_136 ( struct V_18 * V_19 ,
struct V_195 * V_168 ,
struct V_319 * V_318 )
{
T_2 V_167 ;
unsigned int V_130 ;
const struct V_327 * V_328 = V_327 ;
if ( ! F_89 ( V_19 , V_320 ) )
return false ;
V_130 = V_168 -> V_198 + 1 ;
V_167 = F_20 ( V_328 [ V_168 -> V_198 ] . V_329 ) ;
if ( ! ( V_167 & V_302 ) )
return false ;
V_167 = F_20 ( V_155 ) ;
V_318 -> V_224 = ( V_167 >> ( V_130 * 6 ) ) & 0x3f ;
if ( V_167 & F_53 ( V_130 ) ) {
V_318 -> V_225 = F_20 ( V_328 [ V_168 -> V_198 ] . V_225 ) ;
V_318 -> V_226 = F_20 ( V_328 [ V_168 -> V_198 ] . V_226 ) ;
}
return true ;
}
static void F_137 ( struct V_18 * V_19 )
{
int V_22 ;
V_19 -> V_321 = 3 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_321 ; V_22 ++ ) {
V_19 -> V_322 [ V_22 ] . V_198 = V_22 ;
V_19 -> V_322 [ V_22 ] . V_323 = V_331 [ V_22 ] ;
V_19 -> V_322 [ V_22 ] . V_325 = F_135 ;
V_19 -> V_322 [ V_22 ] . V_326 = F_132 ;
V_19 -> V_322 [ V_22 ] . V_277 =
F_136 ;
}
}
void F_138 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
T_2 V_167 = F_20 ( V_309 ) ;
if ( F_7 ( V_17 ) )
F_137 ( V_19 ) ;
else
F_131 ( V_19 ) ;
F_34 ( L_20 ,
F_126 ( V_19 ) ) ;
if ( F_7 ( V_17 ) ) {
if ( ! ( F_20 ( V_298 ) & V_302 ) )
F_4 ( L_21 ) ;
} else {
if ( V_167 & V_312 )
F_4 ( L_22 ) ;
if ( V_167 & V_332 )
F_4 ( L_23 ) ;
}
}
void F_139 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_87 * V_87 = & V_8 -> V_269 ;
struct V_18 * V_19 = V_4 -> V_17 -> V_20 ;
enum V_1 V_1 = V_8 -> V_1 ;
T_2 V_167 ;
bool V_293 = false ;
if ( F_20 ( F_30 ( V_1 ) ) & V_77 ) {
V_167 = F_20 ( F_18 ( V_1 ) ) ;
if ( V_167 & V_78 ) {
V_167 &= ~ V_78 ;
F_14 ( F_18 ( V_1 ) , V_167 ) ;
V_293 = true ;
}
V_167 = F_20 ( F_30 ( V_1 ) ) ;
V_167 &= ~ ( V_77 | V_86 ) ;
V_167 |= V_76 ;
F_14 ( F_30 ( V_1 ) , V_167 ) ;
F_27 ( F_30 ( V_1 ) ) ;
if ( V_293 )
F_17 ( V_19 , V_1 ) ;
}
V_167 = V_77 |
V_76 | V_333 ;
if ( V_87 -> V_266 )
V_167 |= V_334 ;
else {
V_167 |= V_335 ;
if ( F_140 ( V_87 -> V_336 ) )
V_167 |= V_75 ;
}
F_14 ( F_30 ( V_1 ) , V_167 ) ;
F_27 ( F_30 ( V_1 ) ) ;
V_87 -> V_88 |= V_78 ;
F_14 ( F_18 ( V_1 ) , V_87 -> V_88 ) ;
F_27 ( F_18 ( V_1 ) ) ;
F_19 ( 600 ) ;
}
void F_141 ( struct V_57 * V_58 )
{
struct V_18 * V_19 = V_58 -> V_17 -> V_20 ;
struct V_2 * V_2 = F_38 ( V_58 ) ;
T_2 V_167 ;
F_107 ( V_2 ) ;
V_167 = F_20 ( V_70 ) ;
V_167 &= ~ V_80 ;
F_14 ( V_70 , V_167 ) ;
V_167 = F_20 ( V_62 ) ;
V_167 &= ~ ( V_82 | V_83 ) ;
V_167 |= F_24 ( 2 ) | F_25 ( 2 ) ;
F_14 ( V_62 , V_167 ) ;
V_167 = F_20 ( V_70 ) ;
V_167 &= ~ V_71 ;
F_14 ( V_70 , V_167 ) ;
V_167 = F_20 ( V_70 ) ;
V_167 &= ~ V_67 ;
F_14 ( V_70 , V_167 ) ;
}
static void F_142 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_3 ( & V_2 -> V_5 ) ;
int type = V_8 -> V_5 . type ;
if ( type != V_10 &&
type != V_11 &&
type != V_13 ) {
return;
}
F_143 ( V_2 ) ;
}
void F_144 ( struct V_2 * V_4 ,
struct V_94 * V_152 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
struct V_59 * V_59 = F_23 ( V_4 -> V_5 . V_58 ) ;
enum V_232 V_233 = V_152 -> V_233 ;
struct V_291 * V_291 ;
T_1 V_60 , V_246 = 0 ;
V_60 = F_20 ( F_83 ( V_233 ) ) ;
if ( V_60 & V_250 )
V_246 |= V_249 ;
else
V_246 |= V_337 ;
if ( V_60 & V_248 )
V_246 |= V_247 ;
else
V_246 |= V_338 ;
V_152 -> V_5 . V_164 . V_246 |= V_246 ;
switch ( V_60 & V_339 ) {
case V_242 :
V_152 -> V_235 = 18 ;
break;
case V_243 :
V_152 -> V_235 = 24 ;
break;
case V_244 :
V_152 -> V_235 = 30 ;
break;
case V_245 :
V_152 -> V_235 = 36 ;
break;
default:
break;
}
switch ( V_60 & V_278 ) {
case V_263 :
V_152 -> V_262 = true ;
V_291 = F_106 ( & V_4 -> V_5 ) ;
if ( V_291 -> V_340 ( & V_4 -> V_5 ) )
V_152 -> V_341 = true ;
break;
case V_264 :
case V_265 :
break;
case V_268 :
case V_267 :
V_152 -> V_163 = true ;
F_145 ( V_59 , V_152 ) ;
break;
default:
break;
}
if ( F_89 ( V_19 , V_296 ) ) {
V_60 = F_20 ( V_342 ) ;
if ( V_60 & F_146 ( V_59 -> V_93 ) )
V_152 -> V_295 = true ;
}
if ( V_4 -> type == V_11 && V_19 -> V_29 . V_343 &&
V_152 -> V_235 > V_19 -> V_29 . V_343 ) {
F_34 ( L_24 ,
V_152 -> V_235 , V_19 -> V_29 . V_343 ) ;
V_19 -> V_29 . V_343 = V_152 -> V_235 ;
}
F_58 ( V_4 , V_152 ) ;
}
static void F_147 ( struct V_3 * V_4 )
{
F_148 ( V_4 ) ;
}
static bool F_149 ( struct V_2 * V_4 ,
struct V_94 * V_152 )
{
int type = V_4 -> type ;
int V_1 = F_1 ( V_4 ) ;
F_11 ( type == V_13 , L_25 ) ;
if ( V_1 == V_49 )
V_152 -> V_233 = V_251 ;
if ( type == V_12 )
return F_150 ( V_4 , V_152 ) ;
else
return F_151 ( V_4 , V_152 ) ;
}
static struct V_272 *
F_152 ( struct V_7 * V_8 )
{
struct V_272 * V_344 ;
enum V_1 V_1 = V_8 -> V_1 ;
V_344 = F_153 () ;
if ( ! V_344 )
return NULL ;
V_8 -> V_269 . V_345 = F_18 ( V_1 ) ;
if ( ! F_154 ( V_8 , V_344 ) ) {
F_155 ( V_344 ) ;
return NULL ;
}
return V_344 ;
}
static struct V_272 *
F_156 ( struct V_7 * V_8 )
{
struct V_272 * V_344 ;
enum V_1 V_1 = V_8 -> V_1 ;
V_344 = F_153 () ;
if ( ! V_344 )
return NULL ;
V_8 -> V_346 . V_347 = F_18 ( V_1 ) ;
F_157 ( V_8 , V_344 ) ;
return V_344 ;
}
void F_158 ( struct V_16 * V_17 , enum V_1 V_1 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_7 * V_8 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
bool V_348 , V_349 ;
V_348 = ( V_19 -> V_29 . V_30 [ V_1 ] . V_350 ||
V_19 -> V_29 . V_30 [ V_1 ] . V_351 ) ;
V_349 = V_19 -> V_29 . V_30 [ V_1 ] . V_352 ;
if ( ! V_349 && ! V_348 ) {
F_34 ( L_26 ,
F_21 ( V_1 ) ) ;
V_348 = true ;
V_349 = true ;
}
V_8 = F_159 ( sizeof( * V_8 ) , V_353 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_160 ( V_17 , V_4 , & V_354 ,
V_355 ) ;
V_2 -> V_356 = F_149 ;
V_2 -> V_326 = F_110 ;
V_2 -> V_357 = F_95 ;
V_2 -> V_325 = F_116 ;
V_2 -> V_358 = F_107 ;
V_2 -> V_277 = F_90 ;
V_2 -> V_359 = F_144 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_89 = F_20 ( F_18 ( V_1 ) ) &
( V_360 |
V_361 ) ;
V_2 -> type = V_13 ;
V_2 -> V_362 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_363 = 0 ;
V_2 -> V_364 = F_142 ;
if ( V_349 ) {
if ( ! F_152 ( V_8 ) )
goto V_365;
V_8 -> V_366 = V_367 ;
V_19 -> V_368 [ V_1 ] = V_8 ;
}
if ( V_2 -> type != V_11 && V_348 ) {
if ( ! F_156 ( V_8 ) )
goto V_365;
}
return;
V_365:
F_161 ( V_4 ) ;
F_155 ( V_8 ) ;
}
