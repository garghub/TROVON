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
int V_22 , V_23 , V_24 ;
int V_25 = V_19 -> V_26 . V_27 [ V_1 ] . V_28 ;
const struct V_29 * V_30 ;
const struct V_29 * V_31 ;
const struct V_29 * V_32 ;
const struct V_29 * V_33 ;
const struct V_29 * V_34 ;
if ( F_7 ( V_17 ) ) {
V_30 = NULL ;
V_31 = V_35 ;
V_32 = V_35 ;
V_33 = V_36 ;
V_23 = F_8 ( V_36 ) ;
V_24 = 7 ;
} else if ( F_9 ( V_17 ) ) {
V_30 = V_37 ;
V_31 = V_38 ;
V_32 = V_39 ;
V_33 = V_40 ;
V_23 = F_8 ( V_40 ) ;
V_24 = 7 ;
} else if ( F_10 ( V_17 ) ) {
V_30 = V_41 ;
V_31 = V_42 ;
V_32 = V_42 ;
V_33 = V_43 ;
V_23 = F_8 ( V_43 ) ;
V_24 = 6 ;
} else {
F_11 ( 1 , L_2 ) ;
V_32 = V_38 ;
V_30 = V_37 ;
V_31 = V_38 ;
V_33 = V_40 ;
V_23 = F_8 ( V_40 ) ;
V_24 = 7 ;
}
switch ( V_1 ) {
case V_44 :
V_34 = V_32 ;
break;
case V_45 :
case V_46 :
V_34 = V_31 ;
break;
case V_47 :
if ( F_12 ( V_17 , V_47 ) )
V_34 = V_32 ;
else
V_34 = V_31 ;
break;
case V_15 :
if ( V_30 )
V_34 = V_30 ;
else
V_34 = V_31 ;
break;
default:
F_5 () ;
}
for ( V_22 = 0 , V_21 = F_13 ( V_1 ) ;
V_22 < F_8 ( V_41 ) ; V_22 ++ ) {
F_14 ( V_21 , V_34 [ V_22 ] . V_48 ) ;
V_21 += 4 ;
F_14 ( V_21 , V_34 [ V_22 ] . V_49 ) ;
V_21 += 4 ;
}
if ( V_25 == V_50 ||
V_25 >= V_23 )
V_25 = V_24 ;
F_14 ( V_21 , V_33 [ V_25 ] . V_48 ) ;
V_21 += 4 ;
F_14 ( V_21 , V_33 [ V_25 ] . V_49 ) ;
V_21 += 4 ;
}
void F_15 ( struct V_16 * V_17 )
{
int V_1 ;
if ( ! F_16 ( V_17 ) )
return;
for ( V_1 = V_44 ; V_1 <= V_15 ; V_1 ++ )
F_6 ( V_17 , V_1 ) ;
}
static void F_17 ( struct V_18 * V_19 ,
enum V_1 V_1 )
{
T_2 V_21 = F_18 ( V_1 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
F_19 ( 1 ) ;
if ( F_20 ( V_21 ) & V_51 )
return;
}
F_4 ( L_3 , F_21 ( V_1 ) ) ;
}
void F_22 ( struct V_52 * V_53 )
{
struct V_16 * V_17 = V_53 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_54 * V_54 = F_23 ( V_53 ) ;
T_1 V_55 , V_22 , V_56 ;
F_14 ( V_57 , F_24 ( 2 ) |
F_25 ( 2 ) |
V_58 | V_59 ) ;
V_56 = V_19 -> V_60 | V_61 |
V_62 |
F_26 ( V_54 -> V_63 -> V_64 ) ;
F_14 ( V_65 , V_56 ) ;
F_27 ( V_65 ) ;
F_19 ( 220 ) ;
V_56 |= V_66 ;
F_14 ( V_65 , V_56 ) ;
F_14 ( F_28 ( V_15 ) , V_54 -> V_63 -> V_67 ) ;
F_29 ( V_54 -> V_63 -> V_67 != V_68 ) ;
for ( V_22 = 0 ; V_22 < F_8 ( V_41 ) * 2 ; V_22 ++ ) {
F_14 ( F_30 ( V_15 ) ,
V_69 |
V_70 |
V_71 |
V_72 ) ;
F_14 ( F_18 ( V_15 ) ,
V_73 |
( ( V_54 -> V_63 -> V_64 - 1 ) << 1 ) |
F_31 ( V_22 / 2 ) ) ;
F_27 ( F_18 ( V_15 ) ) ;
F_19 ( 600 ) ;
F_14 ( V_74 , F_32 ( 64 ) ) ;
V_56 |= V_75 | V_76 ;
F_14 ( V_65 , V_56 ) ;
F_27 ( V_65 ) ;
F_19 ( 30 ) ;
V_55 = F_20 ( V_57 ) ;
V_55 &= ~ ( V_77 | V_78 ) ;
F_14 ( V_57 , V_55 ) ;
F_27 ( V_57 ) ;
F_19 ( 5 ) ;
V_55 = F_20 ( F_33 ( V_15 ) ) ;
if ( V_55 & V_79 ) {
F_34 ( L_4 , V_22 ) ;
F_14 ( F_30 ( V_15 ) ,
V_69 |
V_80 |
V_70 |
V_72 ) ;
return;
}
V_55 = F_20 ( F_18 ( V_15 ) ) ;
V_55 &= ~ V_73 ;
F_14 ( F_18 ( V_15 ) , V_55 ) ;
F_27 ( F_18 ( V_15 ) ) ;
V_55 = F_20 ( F_30 ( V_15 ) ) ;
V_55 &= ~ ( V_72 | V_81 ) ;
V_55 |= V_71 ;
F_14 ( F_30 ( V_15 ) , V_55 ) ;
F_27 ( F_30 ( V_15 ) ) ;
F_17 ( V_19 , V_15 ) ;
V_56 &= ~ V_75 ;
F_14 ( V_65 , V_56 ) ;
F_27 ( V_65 ) ;
V_55 = F_20 ( V_57 ) ;
V_55 &= ~ ( V_77 | V_78 ) ;
V_55 |= F_24 ( 2 ) | F_25 ( 2 ) ;
F_14 ( V_57 , V_55 ) ;
F_27 ( V_57 ) ;
}
F_4 ( L_5 ) ;
}
void F_35 ( struct V_2 * V_4 )
{
struct V_82 * V_82 = F_36 ( & V_4 -> V_5 ) ;
struct V_7 * V_8 =
F_3 ( & V_4 -> V_5 ) ;
V_82 -> V_83 = V_8 -> V_84 |
V_73 | F_31 ( 0 ) ;
V_82 -> V_83 |= F_37 ( V_82 -> V_85 ) ;
}
static struct V_2 *
F_38 ( struct V_52 * V_53 )
{
struct V_16 * V_17 = V_53 -> V_17 ;
struct V_54 * V_54 = F_23 ( V_53 ) ;
struct V_2 * V_2 , * V_86 = NULL ;
int V_87 = 0 ;
F_39 (dev, crtc, intel_encoder) {
V_86 = V_2 ;
V_87 ++ ;
}
if ( V_87 != 1 )
F_11 ( 1 , L_6 , V_87 ,
F_40 ( V_54 -> V_88 ) ) ;
F_41 ( V_86 == NULL ) ;
return V_86 ;
}
static struct V_2 *
F_42 ( struct V_54 * V_53 )
{
struct V_16 * V_17 = V_53 -> V_5 . V_17 ;
struct V_2 * V_2 , * V_86 = NULL ;
int V_87 = 0 ;
F_43 (dev, intel_encoder) {
if ( V_2 -> V_89 == V_53 ) {
V_86 = V_2 ;
V_87 ++ ;
}
}
F_11 ( V_87 != 1 , L_6 , V_87 ,
F_40 ( V_53 -> V_88 ) ) ;
F_41 ( V_86 == NULL ) ;
return V_86 ;
}
static unsigned F_44 ( int clock )
{
unsigned V_90 ;
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
V_90 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_90 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_90 = 2000 ;
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
V_90 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_90 = 5000 ;
break;
default:
V_90 = 1000 ;
break;
}
return V_90 ;
}
static void F_45 ( T_3 V_91 , unsigned V_90 ,
unsigned V_92 , unsigned V_93 , unsigned V_94 ,
struct V_95 * V_96 )
{
T_3 V_97 , V_98 , V_99 , V_100 , V_101 , V_102 ;
if ( V_96 -> V_94 == 0 ) {
V_96 -> V_94 = V_94 ;
V_96 -> V_93 = V_93 ;
V_96 -> V_92 = V_92 ;
return;
}
V_97 = V_91 * V_90 * V_94 * V_92 ;
V_98 = V_91 * V_90 * V_96 -> V_94 * V_96 -> V_92 ;
V_101 = F_46 ( V_91 * V_94 * V_92 , V_103 * V_93 ) ;
V_102 = F_46 ( V_91 * V_96 -> V_94 * V_96 -> V_92 ,
V_103 * V_96 -> V_93 ) ;
V_99 = 1000000 * V_101 ;
V_100 = 1000000 * V_102 ;
if ( V_97 < V_99 && V_98 < V_100 ) {
if ( V_96 -> V_94 * V_96 -> V_92 * V_101 < V_94 * V_92 * V_102 ) {
V_96 -> V_94 = V_94 ;
V_96 -> V_93 = V_93 ;
V_96 -> V_92 = V_92 ;
}
} else if ( V_97 >= V_99 && V_98 < V_100 ) {
V_96 -> V_94 = V_94 ;
V_96 -> V_93 = V_93 ;
V_96 -> V_92 = V_92 ;
} else if ( V_97 >= V_99 && V_98 >= V_100 ) {
if ( V_93 * V_96 -> V_92 * V_96 -> V_92 > V_96 -> V_93 * V_92 * V_92 ) {
V_96 -> V_94 = V_94 ;
V_96 -> V_93 = V_93 ;
V_96 -> V_92 = V_92 ;
}
}
}
static int F_47 ( struct V_18 * V_19 ,
int V_21 )
{
int V_104 = V_105 ;
int V_106 , V_94 , V_107 ;
T_1 V_108 ;
V_108 = F_20 ( V_21 ) ;
switch ( V_108 & V_109 ) {
case V_110 :
case V_111 :
V_104 = 135 ;
break;
case V_112 :
V_104 = V_105 ;
break;
default:
F_11 ( 1 , L_7 ) ;
return 0 ;
}
V_107 = V_108 & V_113 ;
V_94 = ( V_108 & V_114 ) >> V_115 ;
V_106 = ( V_108 & V_116 ) >> V_117 ;
return ( V_104 * V_106 * 100 ) / ( V_94 * V_107 ) ;
}
static int F_48 ( struct V_18 * V_19 ,
T_2 V_118 )
{
T_2 V_119 , V_120 ;
T_2 V_121 , V_122 ;
T_2 V_123 , V_124 , V_125 , V_126 ;
V_119 = F_49 ( V_118 ) ;
V_120 = F_50 ( V_118 ) ;
V_121 = F_20 ( V_119 ) ;
V_122 = F_20 ( V_120 ) ;
V_123 = V_122 & V_127 ;
V_125 = V_122 & V_128 ;
if ( V_122 & F_51 ( 1 ) )
V_124 = ( V_122 & V_129 ) >> 8 ;
else
V_124 = 1 ;
switch ( V_123 ) {
case V_130 :
V_123 = 1 ;
break;
case V_131 :
V_123 = 2 ;
break;
case V_132 :
V_123 = 3 ;
break;
case V_133 :
V_123 = 7 ;
break;
}
switch ( V_125 ) {
case V_134 :
V_125 = 5 ;
break;
case V_135 :
V_125 = 2 ;
break;
case V_136 :
V_125 = 3 ;
break;
case V_137 :
V_125 = 1 ;
break;
}
V_126 = ( V_121 & V_138 ) * 24 * 1000 ;
V_126 += ( ( ( V_121 & V_139 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_126 / ( V_123 * V_124 * V_125 * 5 ) ;
}
static void F_52 ( struct V_2 * V_4 ,
struct V_140 * V_141 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
int V_142 = 0 ;
T_2 V_143 , V_118 ;
V_118 = V_141 -> V_67 ;
V_143 = F_20 ( V_144 ) ;
if ( V_143 & F_53 ( V_118 ) ) {
V_142 = F_48 ( V_19 , V_118 ) ;
} else {
V_142 = V_143 & F_54 ( V_118 ) ;
V_142 >>= F_55 ( V_118 ) ;
switch ( V_142 ) {
case V_145 :
V_142 = 81000 ;
break;
case V_146 :
V_142 = 135000 ;
break;
case V_147 :
V_142 = 270000 ;
break;
default:
F_11 ( 1 , L_8 ) ;
break;
}
V_142 *= 2 ;
}
V_141 -> V_148 = V_142 ;
if ( V_141 -> V_149 )
V_141 -> V_5 . V_150 . V_151 =
F_56 ( V_141 -> V_148 ,
& V_141 -> V_152 ) ;
else
V_141 -> V_5 . V_150 . V_151 = V_141 -> V_148 ;
}
static void F_57 ( struct V_2 * V_4 ,
struct V_140 * V_141 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
int V_142 = 0 ;
T_1 V_153 , V_154 ;
V_153 = V_141 -> V_67 ;
switch ( V_153 & V_155 ) {
case V_156 :
V_142 = 81000 ;
break;
case V_157 :
V_142 = 135000 ;
break;
case V_158 :
V_142 = 270000 ;
break;
case V_159 :
V_142 = F_47 ( V_19 , V_160 ) ;
break;
case V_161 :
V_142 = F_47 ( V_19 , V_162 ) ;
break;
case V_68 :
V_154 = F_20 ( V_163 ) & V_164 ;
if ( V_154 == V_165 )
V_142 = 81000 ;
else if ( V_154 == V_166 )
V_142 = 135000 ;
else if ( V_154 == V_167 )
V_142 = 270000 ;
else {
F_11 ( 1 , L_9 ) ;
return;
}
break;
default:
F_11 ( 1 , L_10 ) ;
return;
}
V_141 -> V_148 = V_142 * 2 ;
if ( V_141 -> V_168 )
V_141 -> V_5 . V_150 . V_151 =
F_56 ( V_141 -> V_148 ,
& V_141 -> V_169 ) ;
else if ( V_141 -> V_149 )
V_141 -> V_5 . V_150 . V_151 =
F_56 ( V_141 -> V_148 ,
& V_141 -> V_152 ) ;
else
V_141 -> V_5 . V_150 . V_151 = V_141 -> V_148 ;
}
void F_58 ( struct V_2 * V_4 ,
struct V_140 * V_141 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_17 ;
if ( F_59 ( V_17 ) -> V_170 <= 8 )
F_57 ( V_4 , V_141 ) ;
else
F_52 ( V_4 , V_141 ) ;
}
static void
F_60 ( int clock ,
unsigned * V_171 , unsigned * V_172 , unsigned * V_173 )
{
T_3 V_91 ;
unsigned V_94 , V_93 , V_92 ;
struct V_95 V_96 = { 0 , 0 , 0 } ;
unsigned V_90 ;
V_91 = clock / 100 ;
V_90 = F_44 ( clock ) ;
if ( V_91 == 5400000 ) {
* V_172 = 2 ;
* V_173 = 1 ;
* V_171 = 2 ;
return;
}
for ( V_92 = V_105 * 2 / V_174 + 1 ;
V_92 <= V_105 * 2 / V_175 ;
V_92 ++ ) {
for ( V_93 = V_176 * V_92 / V_105 + 1 ;
V_93 <= V_177 * V_92 / V_105 ;
V_93 ++ ) {
for ( V_94 = V_178 ; V_94 <= V_179 ; V_94 += V_180 )
F_45 ( V_91 , V_90 ,
V_92 , V_93 , V_94 , & V_96 ) ;
}
}
* V_172 = V_96 . V_93 ;
* V_173 = V_96 . V_94 ;
* V_171 = V_96 . V_92 ;
}
static bool
F_61 ( struct V_54 * V_54 ,
struct V_140 * V_181 ,
struct V_2 * V_2 ,
int clock )
{
if ( V_2 -> type == V_12 ) {
struct V_182 * V_154 ;
T_2 V_153 ;
unsigned V_94 , V_93 , V_92 ;
F_60 ( clock * 1000 , & V_92 , & V_93 , & V_94 ) ;
V_153 = V_183 | V_112 |
F_62 ( V_92 ) | F_63 ( V_93 ) |
F_64 ( V_94 ) ;
V_181 -> V_184 . V_108 = V_153 ;
V_154 = F_65 ( V_54 , V_181 ) ;
if ( V_154 == NULL ) {
F_66 ( L_11 ,
F_40 ( V_54 -> V_88 ) ) ;
return false ;
}
V_181 -> V_67 = F_67 ( V_154 -> V_185 ) ;
}
return true ;
}
static void
F_68 ( int clock ,
struct V_186 * V_187 )
{
T_3 V_188 = clock * 5 ;
T_3 V_189 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
T_2 V_190 = 400 ;
T_2 V_191 = 3 ;
T_2 V_192 [ 4 ] = { 1 , 2 , 3 , 7 } ;
T_2 V_193 [ 4 ] = { 1 , 2 , 3 , 5 } ;
bool V_194 = false ;
T_2 V_195 = 0 ;
T_2 V_196 [ 3 ] = { 0 } , V_197 [ 3 ] = { 0 } ;
T_2 V_198 [ 3 ] = { 0 } ;
T_2 V_199 [ 3 ] ;
T_2 V_22 , V_200 , V_201 , V_202 ;
bool V_203 = false ;
T_3 V_126 ;
for ( V_202 = 0 ; V_202 < 3 ; V_202 ++ ) {
V_194 = false ;
V_195 =
F_69 ( V_189 [ V_202 ] , V_188 ) ;
if ( V_203 == false )
V_195 = ( V_195 % 2 == 0 ?
V_195 : V_195 + 1 ) ;
for ( V_200 = 1 ; V_200 < V_195 ; V_200 ++ ) {
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
if ( ! ( V_192 [ V_22 ] != 1 || V_200 == 1 ) )
continue;
for ( V_201 = 0 ; V_201 < 4 ; V_201 ++ ) {
if ( V_200 != 1 && V_193 [ V_201 ] != 2 )
continue;
if ( V_195 == V_192 [ V_22 ] * V_200 * V_193 [ V_201 ] ) {
V_194 = true ;
V_196 [ V_202 ] = V_192 [ V_22 ] ;
V_197 [ V_202 ] = V_200 ;
V_198 [ V_202 ] = V_193 [ V_201 ] ;
goto V_194;
}
}
}
}
V_194:
if ( V_194 ) {
V_199 [ V_202 ] =
F_69 ( 10000 *
F_46 ( ( V_195 * V_188 ) ,
V_189 [ V_202 ] ) ,
V_189 [ V_202 ] ) ;
if ( V_199 [ V_202 ] <
V_190 ) {
V_190 =
V_199 [ V_202 ] ;
V_191 = V_202 ;
}
}
if ( V_191 > 2 && V_202 == 2 ) {
V_203 = true ;
V_202 = 0 ;
}
}
if ( V_191 > 2 ) {
F_11 ( 1 , L_12 ) ;
} else {
V_187 -> V_204 = V_189 [ V_191 ] ;
switch ( V_189 [ V_191 ] ) {
case 9600000000ULL :
V_187 -> V_204 = 0 ;
break;
case 9000000000ULL :
V_187 -> V_204 = 1 ;
break;
case 8400000000ULL :
V_187 -> V_204 = 3 ;
}
switch ( V_196 [ V_191 ] ) {
case 1 :
V_187 -> V_205 = 0 ;
break;
case 2 :
V_187 -> V_205 = 1 ;
break;
case 3 :
V_187 -> V_205 = 2 ;
break;
case 7 :
V_187 -> V_205 = 4 ;
break;
default:
F_11 ( 1 , L_13 ) ;
}
switch ( V_198 [ V_191 ] ) {
case 5 :
V_187 -> V_206 = 0 ;
break;
case 2 :
V_187 -> V_206 = 1 ;
break;
case 3 :
V_187 -> V_206 = 2 ;
break;
case 1 :
V_187 -> V_206 = 3 ;
break;
default:
F_11 ( 1 , L_14 ) ;
}
V_187 -> V_207 = V_197 [ V_191 ] ;
V_187 -> V_208 =
( V_187 -> V_207 == 1 ) ? 0 : 1 ;
V_126 = V_196 [ V_191 ] *
V_197 [ V_191 ] *
V_198 [ V_191 ] * V_188 ;
V_187 -> V_209 = F_70 ( V_126 , ( 24 * F_71 ( 1 ) ) ) ;
V_187 -> V_210 =
F_70 ( ( ( F_70 ( V_126 , 24 ) -
V_187 -> V_209 * F_71 ( 1 ) ) * 0x8000 ) , F_71 ( 1 ) ) ;
}
}
static bool
F_72 ( struct V_54 * V_54 ,
struct V_140 * V_181 ,
struct V_2 * V_2 ,
int clock )
{
struct V_182 * V_154 ;
T_2 V_211 , V_212 , V_213 ;
V_211 = F_73 ( 0 ) ;
if ( V_2 -> type == V_12 ) {
struct V_186 V_187 = { 0 , } ;
V_211 |= F_53 ( 0 ) ;
F_68 ( clock * 1000 , & V_187 ) ;
V_212 = V_214 |
F_74 ( V_187 . V_210 ) |
V_187 . V_209 ;
V_213 = F_75 ( V_187 . V_207 ) |
F_51 ( V_187 . V_208 ) |
F_76 ( V_187 . V_206 ) |
F_77 ( V_187 . V_205 ) |
V_187 . V_204 ;
} else if ( V_2 -> type == V_10 ) {
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_82 * V_82 = F_36 ( V_4 ) ;
switch ( V_82 -> V_215 ) {
case V_216 :
V_211 |= F_78 ( V_145 , 0 ) ;
break;
case V_217 :
V_211 |= F_78 ( V_146 , 0 ) ;
break;
case V_218 :
V_211 |= F_78 ( V_147 , 0 ) ;
break;
}
V_212 = V_213 = 0 ;
} else
return true ;
V_181 -> V_184 . V_211 = V_211 ;
V_181 -> V_184 . V_212 = V_212 ;
V_181 -> V_184 . V_213 = V_213 ;
V_154 = F_65 ( V_54 , V_181 ) ;
if ( V_154 == NULL ) {
F_66 ( L_11 ,
F_40 ( V_54 -> V_88 ) ) ;
return false ;
}
V_181 -> V_67 = V_154 -> V_185 + 1 ;
return true ;
}
bool F_79 ( struct V_54 * V_54 ,
struct V_140 * V_181 )
{
struct V_16 * V_17 = V_54 -> V_5 . V_17 ;
struct V_2 * V_2 =
F_42 ( V_54 ) ;
int clock = V_181 -> V_148 ;
if ( F_7 ( V_17 ) )
return F_72 ( V_54 , V_181 ,
V_2 , clock ) ;
else
return F_61 ( V_54 , V_181 ,
V_2 , clock ) ;
}
void F_80 ( struct V_52 * V_53 )
{
struct V_18 * V_19 = V_53 -> V_17 -> V_20 ;
struct V_54 * V_54 = F_23 ( V_53 ) ;
struct V_2 * V_2 = F_38 ( V_53 ) ;
enum V_219 V_220 = V_54 -> V_63 -> V_220 ;
int type = V_2 -> type ;
T_2 V_55 ;
if ( type == V_10 || type == V_11 || type == V_6 ) {
V_55 = V_221 ;
switch ( V_54 -> V_63 -> V_222 ) {
case 18 :
V_55 |= V_223 ;
break;
case 24 :
V_55 |= V_224 ;
break;
case 30 :
V_55 |= V_225 ;
break;
case 36 :
V_55 |= V_226 ;
break;
default:
F_5 () ;
}
F_14 ( F_81 ( V_220 ) , V_55 ) ;
}
}
void F_82 ( struct V_52 * V_53 , bool V_227 )
{
struct V_54 * V_54 = F_23 ( V_53 ) ;
struct V_16 * V_17 = V_53 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_219 V_220 = V_54 -> V_63 -> V_220 ;
T_2 V_55 ;
V_55 = F_20 ( F_83 ( V_220 ) ) ;
if ( V_227 == true )
V_55 |= V_228 ;
else
V_55 &= ~ V_228 ;
F_14 ( F_83 ( V_220 ) , V_55 ) ;
}
void F_84 ( struct V_52 * V_53 )
{
struct V_54 * V_54 = F_23 ( V_53 ) ;
struct V_2 * V_2 = F_38 ( V_53 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_53 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_88 V_88 = V_54 -> V_88 ;
enum V_219 V_220 = V_54 -> V_63 -> V_220 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_55 ;
V_55 = V_229 ;
V_55 |= F_85 ( V_1 ) ;
switch ( V_54 -> V_63 -> V_222 ) {
case 18 :
V_55 |= V_230 ;
break;
case 24 :
V_55 |= V_231 ;
break;
case 30 :
V_55 |= V_232 ;
break;
case 36 :
V_55 |= V_233 ;
break;
default:
F_5 () ;
}
if ( V_54 -> V_63 -> V_5 . V_150 . V_234 & V_235 )
V_55 |= V_236 ;
if ( V_54 -> V_63 -> V_5 . V_150 . V_234 & V_237 )
V_55 |= V_238 ;
if ( V_220 == V_239 ) {
switch ( V_88 ) {
case V_240 :
if ( F_10 ( V_17 ) &&
( V_54 -> V_63 -> V_241 . V_242 ||
V_54 -> V_63 -> V_241 . V_243 ) )
V_55 |= V_244 ;
else
V_55 |= V_245 ;
break;
case V_246 :
V_55 |= V_247 ;
break;
case V_248 :
V_55 |= V_249 ;
break;
default:
F_5 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_54 -> V_63 -> V_250 )
V_55 |= V_251 ;
else
V_55 |= V_252 ;
} else if ( type == V_14 ) {
V_55 |= V_253 ;
V_55 |= ( V_54 -> V_63 -> V_64 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_82 * V_82 = F_36 ( V_4 ) ;
if ( V_82 -> V_254 ) {
V_55 |= V_255 ;
} else
V_55 |= V_256 ;
V_55 |= F_37 ( V_82 -> V_85 ) ;
} else if ( type == V_6 ) {
struct V_82 * V_82 = & F_2 ( V_4 ) -> V_9 -> V_257 ;
if ( V_82 -> V_254 ) {
V_55 |= V_255 ;
} else
V_55 |= V_256 ;
V_55 |= F_37 ( V_82 -> V_85 ) ;
} else {
F_11 ( 1 , L_15 ,
V_2 -> type , F_40 ( V_88 ) ) ;
}
F_14 ( F_83 ( V_220 ) , V_55 ) ;
}
void F_86 ( struct V_18 * V_19 ,
enum V_219 V_220 )
{
T_2 V_21 = F_83 ( V_220 ) ;
T_2 V_153 = F_20 ( V_21 ) ;
V_153 &= ~ ( V_229 | V_258 | V_228 ) ;
V_153 |= V_259 ;
F_14 ( V_21 , V_153 ) ;
}
bool F_87 ( struct V_260 * V_260 )
{
struct V_16 * V_17 = V_260 -> V_5 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_2 * V_2 = V_260 -> V_4 ;
int type = V_260 -> V_5 . V_261 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_88 V_88 = 0 ;
enum V_219 V_220 ;
enum V_262 V_263 ;
T_2 V_264 ;
V_263 = F_88 ( V_2 ) ;
if ( ! F_89 ( V_19 , V_263 ) )
return false ;
if ( ! V_2 -> V_265 ( V_2 , & V_88 ) )
return false ;
if ( V_1 == V_44 )
V_220 = V_239 ;
else
V_220 = (enum V_219 ) V_88 ;
V_264 = F_20 ( F_83 ( V_220 ) ) ;
switch ( V_264 & V_266 ) {
case V_251 :
case V_252 :
return ( type == V_267 ) ;
case V_256 :
if ( type == V_268 )
return true ;
return ( type == V_269 ) ;
case V_255 :
return false ;
case V_253 :
return ( type == V_270 ) ;
default:
return false ;
}
}
bool F_90 ( struct V_2 * V_4 ,
enum V_88 * V_88 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
enum V_262 V_263 ;
T_1 V_264 ;
int V_22 ;
V_263 = F_88 ( V_4 ) ;
if ( ! F_89 ( V_19 , V_263 ) )
return false ;
V_264 = F_20 ( F_18 ( V_1 ) ) ;
if ( ! ( V_264 & V_73 ) )
return false ;
if ( V_1 == V_44 ) {
V_264 = F_20 ( F_83 ( V_239 ) ) ;
switch ( V_264 & V_271 ) {
case V_245 :
case V_244 :
* V_88 = V_240 ;
break;
case V_247 :
* V_88 = V_246 ;
break;
case V_249 :
* V_88 = V_248 ;
break;
}
return true ;
} else {
for ( V_22 = V_272 ; V_22 <= V_273 ; V_22 ++ ) {
V_264 = F_20 ( F_83 ( V_22 ) ) ;
if ( ( V_264 & V_258 )
== F_85 ( V_1 ) ) {
if ( ( V_264 & V_266 ) == V_255 )
return false ;
* V_88 = V_22 ;
return true ;
}
}
}
F_34 ( L_16 , F_21 ( V_1 ) ) ;
return false ;
}
void F_91 ( struct V_54 * V_54 )
{
struct V_52 * V_53 = & V_54 -> V_5 ;
struct V_18 * V_19 = V_53 -> V_17 -> V_20 ;
struct V_2 * V_2 = F_38 ( V_53 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_219 V_220 = V_54 -> V_63 -> V_220 ;
if ( V_220 != V_239 )
F_14 ( F_92 ( V_220 ) ,
F_93 ( V_1 ) ) ;
}
void F_94 ( struct V_54 * V_54 )
{
struct V_18 * V_19 = V_54 -> V_5 . V_17 -> V_20 ;
enum V_219 V_220 = V_54 -> V_63 -> V_220 ;
if ( V_220 != V_239 )
F_14 ( F_92 ( V_220 ) ,
V_274 ) ;
}
static void F_95 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_54 * V_53 = F_23 ( V_4 -> V_53 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_11 ) {
struct V_82 * V_82 = F_36 ( V_4 ) ;
F_96 ( V_82 ) ;
}
if ( F_7 ( V_17 ) ) {
T_2 V_118 = V_53 -> V_63 -> V_67 ;
T_2 V_153 ;
if ( type == V_11 ) {
F_29 ( V_118 != V_275 ) ;
V_153 = F_20 ( V_144 ) ;
V_153 &= ~ ( F_53 ( V_118 ) |
F_97 ( V_118 ) |
F_54 ( V_118 ) ) ;
V_153 |= V_53 -> V_63 -> V_184 . V_211 << ( V_118 * 6 ) ;
F_14 ( V_144 , V_153 ) ;
F_27 ( V_144 ) ;
}
V_153 = F_20 ( V_276 ) ;
V_153 &= ~ ( F_98 ( V_1 ) |
F_99 ( V_1 ) ) ;
V_153 |= ( F_100 ( V_118 , V_1 ) |
F_101 ( V_1 ) ) ;
F_14 ( V_276 , V_153 ) ;
} else {
F_29 ( V_53 -> V_63 -> V_67 == V_277 ) ;
F_14 ( F_28 ( V_1 ) , V_53 -> V_63 -> V_67 ) ;
}
if ( type == V_10 || type == V_11 ) {
struct V_82 * V_82 = F_36 ( V_4 ) ;
F_35 ( V_2 ) ;
F_102 ( V_82 , V_278 ) ;
F_103 ( V_82 ) ;
F_104 ( V_82 ) ;
if ( V_1 != V_44 || F_59 ( V_17 ) -> V_170 >= 9 )
F_105 ( V_82 ) ;
} else if ( type == V_12 ) {
struct V_279 * V_279 = F_106 ( V_4 ) ;
V_279 -> V_280 ( V_4 ,
V_53 -> V_63 -> V_250 ,
& V_53 -> V_63 -> V_5 . V_150 ) ;
}
}
static void F_107 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_153 ;
bool V_281 = false ;
V_153 = F_20 ( F_18 ( V_1 ) ) ;
if ( V_153 & V_73 ) {
V_153 &= ~ V_73 ;
F_14 ( F_18 ( V_1 ) , V_153 ) ;
V_281 = true ;
}
V_153 = F_20 ( F_30 ( V_1 ) ) ;
V_153 &= ~ ( V_72 | V_81 ) ;
V_153 |= V_71 ;
F_14 ( F_30 ( V_1 ) , V_153 ) ;
if ( V_281 )
F_17 ( V_19 , V_1 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_82 * V_82 = F_36 ( V_4 ) ;
F_102 ( V_82 , V_282 ) ;
F_108 ( V_82 ) ;
F_109 ( V_82 ) ;
}
if ( F_7 ( V_17 ) )
F_14 ( V_276 , ( F_20 ( V_276 ) |
F_98 ( V_1 ) ) ) ;
else
F_14 ( F_28 ( V_1 ) , V_277 ) ;
}
static void F_110 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_52 * V_53 = V_4 -> V_53 ;
struct V_54 * V_54 = F_23 ( V_53 ) ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_12 ) {
struct V_7 * V_8 =
F_3 ( V_4 ) ;
F_14 ( F_18 ( V_1 ) ,
V_8 -> V_84 |
V_73 ) ;
} else if ( type == V_11 ) {
struct V_82 * V_82 = F_36 ( V_4 ) ;
if ( V_1 == V_44 && F_59 ( V_17 ) -> V_170 < 9 )
F_105 ( V_82 ) ;
F_111 ( V_82 ) ;
F_112 ( V_82 ) ;
F_113 ( V_82 ) ;
}
if ( V_54 -> V_63 -> V_283 ) {
F_114 ( V_19 , V_284 ) ;
F_115 ( V_2 ) ;
}
}
static void F_116 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_52 * V_53 = V_4 -> V_53 ;
struct V_54 * V_54 = F_23 ( V_53 ) ;
int type = V_2 -> type ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
if ( V_54 -> V_63 -> V_283 ) {
F_117 ( V_2 ) ;
F_118 ( V_19 , V_284 ) ;
}
if ( type == V_11 ) {
struct V_82 * V_82 = F_36 ( V_4 ) ;
F_119 ( V_82 ) ;
F_120 ( V_82 ) ;
F_121 ( V_82 ) ;
}
}
static int F_122 ( struct V_18 * V_19 )
{
T_2 V_285 = F_20 ( V_286 ) ;
T_2 V_287 = F_20 ( V_288 ) ;
T_2 V_289 ;
if ( ! ( V_285 & V_290 ) ) {
F_11 ( 1 , L_17 ) ;
return 24000 ;
}
if ( ( V_287 & V_291 ) == V_292 )
return 540000 ;
V_289 = ( F_20 ( V_144 ) &
F_54 ( V_275 ) ) >> 1 ;
if ( V_289 == V_293 ||
V_289 == V_294 ) {
switch ( V_287 & V_291 ) {
case V_295 :
return 432000 ;
case V_296 :
return 308570 ;
case V_297 :
return 617140 ;
default:
F_11 ( 1 , L_18 ) ;
}
} else {
switch ( V_287 & V_291 ) {
case V_295 :
return 450000 ;
case V_296 :
return 337500 ;
case V_297 :
return 675000 ;
default:
F_11 ( 1 , L_18 ) ;
}
}
return 24000 ;
}
static int F_123 ( struct V_18 * V_19 )
{
T_2 V_298 = F_20 ( V_299 ) ;
T_2 V_300 = V_298 & V_301 ;
if ( V_298 & V_302 )
return 800000 ;
else if ( F_20 ( V_303 ) & V_304 )
return 450000 ;
else if ( V_300 == V_305 )
return 450000 ;
else if ( V_300 == V_306 )
return 540000 ;
else if ( V_300 == V_307 )
return 337500 ;
else
return 675000 ;
}
static int F_124 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_17 ;
T_2 V_298 = F_20 ( V_299 ) ;
T_2 V_300 = V_298 & V_301 ;
if ( V_298 & V_302 )
return 800000 ;
else if ( F_20 ( V_303 ) & V_304 )
return 450000 ;
else if ( V_300 == V_305 )
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
struct V_182 * V_154 )
{
F_14 ( F_128 ( V_154 -> V_185 ) , V_154 -> V_63 . V_308 . V_108 ) ;
F_27 ( F_128 ( V_154 -> V_185 ) ) ;
F_19 ( 20 ) ;
}
static void F_129 ( struct V_18 * V_19 ,
struct V_182 * V_154 )
{
T_2 V_153 ;
V_153 = F_20 ( F_128 ( V_154 -> V_185 ) ) ;
F_14 ( F_128 ( V_154 -> V_185 ) , V_153 & ~ V_183 ) ;
F_27 ( F_128 ( V_154 -> V_185 ) ) ;
}
static bool F_130 ( struct V_18 * V_19 ,
struct V_182 * V_154 ,
struct V_309 * V_308 )
{
T_2 V_153 ;
if ( ! F_89 ( V_19 , V_310 ) )
return false ;
V_153 = F_20 ( F_128 ( V_154 -> V_185 ) ) ;
V_308 -> V_108 = V_153 ;
return V_153 & V_183 ;
}
static void F_131 ( struct V_18 * V_19 )
{
int V_22 ;
V_19 -> V_311 = 2 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_311 ; V_22 ++ ) {
V_19 -> V_312 [ V_22 ] . V_185 = V_22 ;
V_19 -> V_312 [ V_22 ] . V_313 = V_314 [ V_22 ] ;
V_19 -> V_312 [ V_22 ] . V_315 = F_129 ;
V_19 -> V_312 [ V_22 ] . V_316 = F_127 ;
V_19 -> V_312 [ V_22 ] . V_265 =
F_130 ;
}
}
static void F_132 ( struct V_18 * V_19 ,
struct V_182 * V_154 )
{
T_2 V_153 ;
unsigned int V_118 ;
const struct V_317 * V_318 = V_317 ;
V_118 = V_154 -> V_185 + 1 ;
V_153 = F_20 ( V_144 ) ;
V_153 &= ~ ( F_53 ( V_118 ) | F_97 ( V_118 ) |
F_54 ( V_118 ) ) ;
V_153 |= V_154 -> V_63 . V_308 . V_211 << ( V_118 * 6 ) ;
F_14 ( V_144 , V_153 ) ;
F_27 ( V_144 ) ;
F_14 ( V_318 [ V_154 -> V_185 ] . V_212 , V_154 -> V_63 . V_308 . V_212 ) ;
F_14 ( V_318 [ V_154 -> V_185 ] . V_213 , V_154 -> V_63 . V_308 . V_213 ) ;
F_27 ( V_318 [ V_154 -> V_185 ] . V_212 ) ;
F_27 ( V_318 [ V_154 -> V_185 ] . V_213 ) ;
F_14 ( V_318 [ V_154 -> V_185 ] . V_319 ,
F_20 ( V_318 [ V_154 -> V_185 ] . V_319 ) | V_290 ) ;
if ( F_133 ( F_20 ( V_320 ) & F_134 ( V_118 ) , 5 ) )
F_4 ( L_19 , V_118 ) ;
}
static void F_135 ( struct V_18 * V_19 ,
struct V_182 * V_154 )
{
const struct V_317 * V_318 = V_317 ;
F_14 ( V_318 [ V_154 -> V_185 ] . V_319 ,
F_20 ( V_318 [ V_154 -> V_185 ] . V_319 ) & ~ V_290 ) ;
F_27 ( V_318 [ V_154 -> V_185 ] . V_319 ) ;
}
static bool F_136 ( struct V_18 * V_19 ,
struct V_182 * V_154 ,
struct V_309 * V_308 )
{
T_2 V_153 ;
unsigned int V_118 ;
const struct V_317 * V_318 = V_317 ;
if ( ! F_89 ( V_19 , V_310 ) )
return false ;
V_118 = V_154 -> V_185 + 1 ;
V_153 = F_20 ( V_318 [ V_154 -> V_185 ] . V_319 ) ;
if ( ! ( V_153 & V_290 ) )
return false ;
V_153 = F_20 ( V_144 ) ;
V_308 -> V_211 = ( V_153 >> ( V_118 * 6 ) ) & 0x3f ;
if ( V_153 & F_53 ( V_118 ) ) {
V_308 -> V_212 = F_20 ( V_318 [ V_154 -> V_185 ] . V_212 ) ;
V_308 -> V_213 = F_20 ( V_318 [ V_154 -> V_185 ] . V_213 ) ;
}
return true ;
}
static void F_137 ( struct V_18 * V_19 )
{
int V_22 ;
V_19 -> V_311 = 3 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_311 ; V_22 ++ ) {
V_19 -> V_312 [ V_22 ] . V_185 = V_22 ;
V_19 -> V_312 [ V_22 ] . V_313 = V_321 [ V_22 ] ;
V_19 -> V_312 [ V_22 ] . V_315 = F_135 ;
V_19 -> V_312 [ V_22 ] . V_316 = F_132 ;
V_19 -> V_312 [ V_22 ] . V_265 =
F_136 ;
}
}
void F_138 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
T_2 V_153 = F_20 ( V_299 ) ;
if ( F_7 ( V_17 ) )
F_137 ( V_19 ) ;
else
F_131 ( V_19 ) ;
F_34 ( L_20 ,
F_126 ( V_19 ) ) ;
if ( F_7 ( V_17 ) ) {
if ( ! ( F_20 ( V_286 ) & V_290 ) )
F_4 ( L_21 ) ;
} else {
if ( V_153 & V_302 )
F_4 ( L_22 ) ;
if ( V_153 & V_322 )
F_4 ( L_23 ) ;
}
}
void F_139 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_82 * V_82 = & V_8 -> V_257 ;
struct V_18 * V_19 = V_4 -> V_17 -> V_20 ;
enum V_1 V_1 = V_8 -> V_1 ;
T_2 V_153 ;
bool V_281 = false ;
if ( F_20 ( F_30 ( V_1 ) ) & V_72 ) {
V_153 = F_20 ( F_18 ( V_1 ) ) ;
if ( V_153 & V_73 ) {
V_153 &= ~ V_73 ;
F_14 ( F_18 ( V_1 ) , V_153 ) ;
V_281 = true ;
}
V_153 = F_20 ( F_30 ( V_1 ) ) ;
V_153 &= ~ ( V_72 | V_81 ) ;
V_153 |= V_71 ;
F_14 ( F_30 ( V_1 ) , V_153 ) ;
F_27 ( F_30 ( V_1 ) ) ;
if ( V_281 )
F_17 ( V_19 , V_1 ) ;
}
V_153 = V_72 |
V_71 | V_323 ;
if ( V_82 -> V_254 )
V_153 |= V_324 ;
else {
V_153 |= V_325 ;
if ( F_140 ( V_82 -> V_326 ) )
V_153 |= V_70 ;
}
F_14 ( F_30 ( V_1 ) , V_153 ) ;
F_27 ( F_30 ( V_1 ) ) ;
V_82 -> V_83 |= V_73 ;
F_14 ( F_18 ( V_1 ) , V_82 -> V_83 ) ;
F_27 ( F_18 ( V_1 ) ) ;
F_19 ( 600 ) ;
}
void F_141 ( struct V_52 * V_53 )
{
struct V_18 * V_19 = V_53 -> V_17 -> V_20 ;
struct V_2 * V_2 = F_38 ( V_53 ) ;
T_2 V_153 ;
F_107 ( V_2 ) ;
V_153 = F_20 ( V_65 ) ;
V_153 &= ~ V_75 ;
F_14 ( V_65 , V_153 ) ;
V_153 = F_20 ( V_57 ) ;
V_153 &= ~ ( V_77 | V_78 ) ;
V_153 |= F_24 ( 2 ) | F_25 ( 2 ) ;
F_14 ( V_57 , V_153 ) ;
V_153 = F_20 ( V_65 ) ;
V_153 &= ~ V_66 ;
F_14 ( V_65 , V_153 ) ;
V_153 = F_20 ( V_65 ) ;
V_153 &= ~ V_62 ;
F_14 ( V_65 , V_153 ) ;
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
struct V_140 * V_141 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
struct V_54 * V_54 = F_23 ( V_4 -> V_5 . V_53 ) ;
enum V_219 V_220 = V_141 -> V_220 ;
struct V_279 * V_279 ;
T_1 V_55 , V_234 = 0 ;
V_55 = F_20 ( F_83 ( V_220 ) ) ;
if ( V_55 & V_238 )
V_234 |= V_237 ;
else
V_234 |= V_327 ;
if ( V_55 & V_236 )
V_234 |= V_235 ;
else
V_234 |= V_328 ;
V_141 -> V_5 . V_150 . V_234 |= V_234 ;
switch ( V_55 & V_329 ) {
case V_230 :
V_141 -> V_222 = 18 ;
break;
case V_231 :
V_141 -> V_222 = 24 ;
break;
case V_232 :
V_141 -> V_222 = 30 ;
break;
case V_233 :
V_141 -> V_222 = 36 ;
break;
default:
break;
}
switch ( V_55 & V_266 ) {
case V_251 :
V_141 -> V_250 = true ;
V_279 = F_106 ( & V_4 -> V_5 ) ;
if ( V_279 -> V_330 ( & V_4 -> V_5 ) )
V_141 -> V_331 = true ;
break;
case V_252 :
case V_253 :
break;
case V_256 :
case V_255 :
V_141 -> V_149 = true ;
F_145 ( V_54 , V_141 ) ;
break;
default:
break;
}
if ( F_89 ( V_19 , V_284 ) ) {
V_55 = F_20 ( V_332 ) ;
if ( V_55 & F_146 ( V_54 -> V_88 ) )
V_141 -> V_283 = true ;
}
if ( V_4 -> type == V_11 && V_19 -> V_26 . V_333 &&
V_141 -> V_222 > V_19 -> V_26 . V_333 ) {
F_34 ( L_24 ,
V_141 -> V_222 , V_19 -> V_26 . V_333 ) ;
V_19 -> V_26 . V_333 = V_141 -> V_222 ;
}
F_58 ( V_4 , V_141 ) ;
}
static void F_147 ( struct V_3 * V_4 )
{
F_148 ( V_4 ) ;
}
static bool F_149 ( struct V_2 * V_4 ,
struct V_140 * V_141 )
{
int type = V_4 -> type ;
int V_1 = F_1 ( V_4 ) ;
F_11 ( type == V_13 , L_25 ) ;
if ( V_1 == V_44 )
V_141 -> V_220 = V_239 ;
if ( type == V_12 )
return F_150 ( V_4 , V_141 ) ;
else
return F_151 ( V_4 , V_141 ) ;
}
static struct V_260 *
F_152 ( struct V_7 * V_8 )
{
struct V_260 * V_334 ;
enum V_1 V_1 = V_8 -> V_1 ;
V_334 = F_153 ( sizeof( * V_334 ) , V_335 ) ;
if ( ! V_334 )
return NULL ;
V_8 -> V_257 . V_336 = F_18 ( V_1 ) ;
if ( ! F_154 ( V_8 , V_334 ) ) {
F_155 ( V_334 ) ;
return NULL ;
}
return V_334 ;
}
static struct V_260 *
F_156 ( struct V_7 * V_8 )
{
struct V_260 * V_334 ;
enum V_1 V_1 = V_8 -> V_1 ;
V_334 = F_153 ( sizeof( * V_334 ) , V_335 ) ;
if ( ! V_334 )
return NULL ;
V_8 -> V_337 . V_338 = F_18 ( V_1 ) ;
F_157 ( V_8 , V_334 ) ;
return V_334 ;
}
void F_158 ( struct V_16 * V_17 , enum V_1 V_1 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_7 * V_8 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
bool V_339 , V_340 ;
V_339 = ( V_19 -> V_26 . V_27 [ V_1 ] . V_341 ||
V_19 -> V_26 . V_27 [ V_1 ] . V_342 ) ;
V_340 = V_19 -> V_26 . V_27 [ V_1 ] . V_343 ;
if ( ! V_340 && ! V_339 ) {
F_34 ( L_26 ,
F_21 ( V_1 ) ) ;
V_339 = true ;
V_340 = true ;
}
V_8 = F_153 ( sizeof( * V_8 ) , V_335 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_159 ( V_17 , V_4 , & V_344 ,
V_345 ) ;
V_2 -> V_346 = F_149 ;
V_2 -> V_316 = F_110 ;
V_2 -> V_347 = F_95 ;
V_2 -> V_315 = F_116 ;
V_2 -> V_348 = F_107 ;
V_2 -> V_265 = F_90 ;
V_2 -> V_349 = F_144 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_84 = F_20 ( F_18 ( V_1 ) ) &
( V_350 |
V_351 ) ;
V_2 -> type = V_13 ;
V_2 -> V_352 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_353 = 0 ;
V_2 -> V_354 = F_142 ;
if ( V_340 ) {
if ( ! F_152 ( V_8 ) )
goto V_355;
V_8 -> V_356 = V_357 ;
V_19 -> V_358 [ V_1 ] = V_8 ;
}
if ( V_2 -> type != V_11 && V_339 ) {
if ( ! F_156 ( V_8 ) )
goto V_355;
}
return;
V_355:
F_160 ( V_4 ) ;
F_155 ( V_8 ) ;
}
