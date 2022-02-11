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
static void F_8 ( struct V_19 * V_20 , enum V_4 V_4 ,
bool V_21 )
{
struct V_22 * V_23 = V_20 -> V_24 ;
T_1 V_25 ;
int V_26 , V_27 , V_28 , V_29 , V_30 ,
V_31 ;
int V_32 = V_23 -> V_33 . V_34 [ V_4 ] . V_35 ;
const struct V_36 * V_37 ;
const struct V_36 * V_38 ;
const struct V_36 * V_39 ;
const struct V_36 * V_40 ;
const struct V_36 * V_41 ;
if ( F_9 ( V_20 ) ) {
if ( ! V_21 )
return;
F_10 ( V_20 , V_32 , V_4 ,
V_12 ) ;
return;
} else if ( F_11 ( V_20 ) ) {
V_37 = NULL ;
V_38 = V_42 ;
V_28 = F_12 ( V_42 ) ;
if ( V_23 -> V_43 ) {
V_39 = V_44 ;
V_29 = F_12 ( V_44 ) ;
} else {
V_39 = V_42 ;
V_29 = F_12 ( V_42 ) ;
}
V_40 = V_45 ;
V_27 = F_12 ( V_45 ) ;
V_30 = 7 ;
} else if ( F_13 ( V_20 ) ) {
V_37 = V_46 ;
V_38 = V_47 ;
V_39 = V_48 ;
V_40 = V_49 ;
V_29 = F_12 ( V_48 ) ;
V_28 = F_12 ( V_47 ) ;
V_27 = F_12 ( V_49 ) ;
V_30 = 7 ;
} else if ( F_14 ( V_20 ) ) {
V_37 = V_50 ;
V_38 = V_51 ;
V_39 = V_51 ;
V_40 = V_52 ;
V_28 = V_29 = F_12 ( V_51 ) ;
V_27 = F_12 ( V_52 ) ;
V_30 = 6 ;
} else {
F_15 ( 1 , L_2 ) ;
V_39 = V_47 ;
V_37 = V_46 ;
V_38 = V_47 ;
V_40 = V_49 ;
V_29 = F_12 ( V_48 ) ;
V_28 = F_12 ( V_47 ) ;
V_27 = F_12 ( V_49 ) ;
V_30 = 7 ;
}
switch ( V_4 ) {
case V_53 :
V_41 = V_39 ;
V_31 = V_29 ;
break;
case V_54 :
case V_55 :
V_41 = V_38 ;
V_31 = V_28 ;
break;
case V_56 :
if ( F_16 ( V_20 , V_56 ) ) {
V_41 = V_39 ;
V_31 = V_29 ;
} else {
V_41 = V_38 ;
V_31 = V_28 ;
}
break;
case V_15 :
if ( V_37 )
V_41 = V_37 ;
else
V_41 = V_38 ;
V_31 = V_28 ;
break;
default:
F_5 () ;
}
for ( V_26 = 0 , V_25 = F_17 ( V_4 ) ; V_26 < V_31 ; V_26 ++ ) {
F_18 ( V_25 , V_41 [ V_26 ] . V_57 ) ;
V_25 += 4 ;
F_18 ( V_25 , V_41 [ V_26 ] . V_58 ) ;
V_25 += 4 ;
}
if ( ! V_21 )
return;
if ( V_32 == V_59 ||
V_32 >= V_27 )
V_32 = V_30 ;
F_18 ( V_25 , V_40 [ V_32 ] . V_57 ) ;
V_25 += 4 ;
F_18 ( V_25 , V_40 [ V_32 ] . V_58 ) ;
V_25 += 4 ;
}
void F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_1 ;
bool V_60 [ V_61 ] = { 0 , } ;
if ( ! F_20 ( V_20 ) )
return;
F_21 (dev, intel_encoder) {
struct V_2 * V_16 ;
enum V_4 V_4 ;
bool V_21 ;
F_1 ( V_1 , & V_16 , & V_4 ) ;
if ( V_60 [ V_4 ] )
continue;
V_21 = V_16 &&
F_7 ( V_16 ) ;
F_8 ( V_20 , V_4 , V_21 ) ;
V_60 [ V_4 ] = true ;
}
}
static void F_22 ( struct V_22 * V_23 ,
enum V_4 V_4 )
{
T_2 V_25 = F_23 ( V_4 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ ) {
F_24 ( 1 ) ;
if ( F_25 ( V_25 ) & V_62 )
return;
}
F_4 ( L_3 , F_26 ( V_4 ) ) ;
}
void F_27 ( struct V_63 * V_64 )
{
struct V_19 * V_20 = V_64 -> V_20 ;
struct V_22 * V_23 = V_20 -> V_24 ;
struct V_65 * V_65 = F_28 ( V_64 ) ;
T_1 V_66 , V_26 , V_67 ;
F_18 ( V_68 , F_29 ( 2 ) |
F_30 ( 2 ) |
V_69 | V_70 ) ;
V_67 = V_23 -> V_71 | V_72 |
V_73 |
F_31 ( V_65 -> V_74 -> V_75 ) ;
F_18 ( V_76 , V_67 ) ;
F_32 ( V_76 ) ;
F_24 ( 220 ) ;
V_67 |= V_77 ;
F_18 ( V_76 , V_67 ) ;
F_18 ( F_33 ( V_15 ) , V_65 -> V_74 -> V_78 ) ;
F_34 ( V_65 -> V_74 -> V_78 != V_79 ) ;
for ( V_26 = 0 ; V_26 < F_12 ( V_50 ) * 2 ; V_26 ++ ) {
F_18 ( F_35 ( V_15 ) ,
V_80 |
V_81 |
V_82 |
V_83 ) ;
F_18 ( F_23 ( V_15 ) ,
V_84 |
( ( V_65 -> V_74 -> V_75 - 1 ) << 1 ) |
F_36 ( V_26 / 2 ) ) ;
F_32 ( F_23 ( V_15 ) ) ;
F_24 ( 600 ) ;
F_18 ( V_85 , F_37 ( 64 ) ) ;
V_67 |= V_86 | V_87 ;
F_18 ( V_76 , V_67 ) ;
F_32 ( V_76 ) ;
F_24 ( 30 ) ;
V_66 = F_25 ( V_68 ) ;
V_66 &= ~ ( V_88 | V_89 ) ;
F_18 ( V_68 , V_66 ) ;
F_32 ( V_68 ) ;
F_24 ( 5 ) ;
V_66 = F_25 ( F_38 ( V_15 ) ) ;
if ( V_66 & V_90 ) {
F_39 ( L_4 , V_26 ) ;
F_18 ( F_35 ( V_15 ) ,
V_80 |
V_91 |
V_81 |
V_83 ) ;
return;
}
V_66 = F_25 ( F_23 ( V_15 ) ) ;
V_66 &= ~ V_84 ;
F_18 ( F_23 ( V_15 ) , V_66 ) ;
F_32 ( F_23 ( V_15 ) ) ;
V_66 = F_25 ( F_35 ( V_15 ) ) ;
V_66 &= ~ ( V_83 | V_92 ) ;
V_66 |= V_82 ;
F_18 ( F_35 ( V_15 ) , V_66 ) ;
F_32 ( F_35 ( V_15 ) ) ;
F_22 ( V_23 , V_15 ) ;
V_67 &= ~ V_86 ;
F_18 ( V_76 , V_67 ) ;
F_32 ( V_76 ) ;
V_66 = F_25 ( V_68 ) ;
V_66 &= ~ ( V_88 | V_89 ) ;
V_66 |= F_29 ( 2 ) | F_30 ( 2 ) ;
F_18 ( V_68 , V_66 ) ;
F_32 ( V_68 ) ;
}
F_4 ( L_5 ) ;
}
void F_40 ( struct V_1 * V_6 )
{
struct V_93 * V_93 = F_41 ( & V_6 -> V_7 ) ;
struct V_2 * V_16 =
F_3 ( & V_6 -> V_7 ) ;
V_93 -> V_94 = V_16 -> V_95 |
V_84 | F_36 ( 0 ) ;
V_93 -> V_94 |= F_42 ( V_93 -> V_96 ) ;
}
static struct V_1 *
F_43 ( struct V_63 * V_64 )
{
struct V_19 * V_20 = V_64 -> V_20 ;
struct V_65 * V_65 = F_28 ( V_64 ) ;
struct V_1 * V_1 , * V_97 = NULL ;
int V_98 = 0 ;
F_44 (dev, crtc, intel_encoder) {
V_97 = V_1 ;
V_98 ++ ;
}
if ( V_98 != 1 )
F_15 ( 1 , L_6 , V_98 ,
F_45 ( V_65 -> V_99 ) ) ;
F_46 ( V_97 == NULL ) ;
return V_97 ;
}
struct V_1 *
F_47 ( struct V_100 * V_101 )
{
struct V_65 * V_64 = F_28 ( V_101 -> V_7 . V_64 ) ;
struct V_1 * V_97 = NULL ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
int V_98 = 0 ;
int V_26 ;
V_103 = V_101 -> V_7 . V_103 ;
F_48 (state, connector, connector_state, i) {
if ( V_107 -> V_64 != V_101 -> V_7 . V_64 )
continue;
V_97 = F_49 ( V_107 -> V_108 ) ;
V_98 ++ ;
}
F_15 ( V_98 != 1 , L_6 , V_98 ,
F_45 ( V_64 -> V_99 ) ) ;
F_46 ( V_97 == NULL ) ;
return V_97 ;
}
static unsigned F_50 ( int clock )
{
unsigned V_109 ;
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
V_109 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_109 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_109 = 2000 ;
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
V_109 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_109 = 5000 ;
break;
default:
V_109 = 1000 ;
break;
}
return V_109 ;
}
static void F_51 ( T_3 V_110 , unsigned V_109 ,
unsigned V_111 , unsigned V_112 , unsigned V_113 ,
struct V_114 * V_115 )
{
T_3 V_116 , V_117 , V_118 , V_119 , V_120 , V_121 ;
if ( V_115 -> V_113 == 0 ) {
V_115 -> V_113 = V_113 ;
V_115 -> V_112 = V_112 ;
V_115 -> V_111 = V_111 ;
return;
}
V_116 = V_110 * V_109 * V_113 * V_111 ;
V_117 = V_110 * V_109 * V_115 -> V_113 * V_115 -> V_111 ;
V_120 = F_52 ( V_110 * V_113 * V_111 , V_122 * V_112 ) ;
V_121 = F_52 ( V_110 * V_115 -> V_113 * V_115 -> V_111 ,
V_122 * V_115 -> V_112 ) ;
V_118 = 1000000 * V_120 ;
V_119 = 1000000 * V_121 ;
if ( V_116 < V_118 && V_117 < V_119 ) {
if ( V_115 -> V_113 * V_115 -> V_111 * V_120 < V_113 * V_111 * V_121 ) {
V_115 -> V_113 = V_113 ;
V_115 -> V_112 = V_112 ;
V_115 -> V_111 = V_111 ;
}
} else if ( V_116 >= V_118 && V_117 < V_119 ) {
V_115 -> V_113 = V_113 ;
V_115 -> V_112 = V_112 ;
V_115 -> V_111 = V_111 ;
} else if ( V_116 >= V_118 && V_117 >= V_119 ) {
if ( V_112 * V_115 -> V_111 * V_115 -> V_111 > V_115 -> V_112 * V_111 * V_111 ) {
V_115 -> V_113 = V_113 ;
V_115 -> V_112 = V_112 ;
V_115 -> V_111 = V_111 ;
}
}
}
static int F_53 ( struct V_22 * V_23 ,
int V_25 )
{
int V_123 = V_124 ;
int V_125 , V_113 , V_126 ;
T_1 V_127 ;
V_127 = F_25 ( V_25 ) ;
switch ( V_127 & V_128 ) {
case V_129 :
case V_130 :
V_123 = 135 ;
break;
case V_131 :
V_123 = V_124 ;
break;
default:
F_15 ( 1 , L_7 ) ;
return 0 ;
}
V_126 = V_127 & V_132 ;
V_113 = ( V_127 & V_133 ) >> V_134 ;
V_125 = ( V_127 & V_135 ) >> V_136 ;
return ( V_123 * V_125 * 100 ) / ( V_113 * V_126 ) ;
}
static int F_54 ( struct V_22 * V_23 ,
T_2 V_137 )
{
T_2 V_138 , V_139 ;
T_2 V_140 , V_141 ;
T_2 V_142 , V_143 , V_144 , V_145 ;
V_138 = F_55 ( V_137 ) ;
V_139 = F_56 ( V_137 ) ;
V_140 = F_25 ( V_138 ) ;
V_141 = F_25 ( V_139 ) ;
V_142 = V_141 & V_146 ;
V_144 = V_141 & V_147 ;
if ( V_141 & F_57 ( 1 ) )
V_143 = ( V_141 & V_148 ) >> 8 ;
else
V_143 = 1 ;
switch ( V_142 ) {
case V_149 :
V_142 = 1 ;
break;
case V_150 :
V_142 = 2 ;
break;
case V_151 :
V_142 = 3 ;
break;
case V_152 :
V_142 = 7 ;
break;
}
switch ( V_144 ) {
case V_153 :
V_144 = 5 ;
break;
case V_154 :
V_144 = 2 ;
break;
case V_155 :
V_144 = 3 ;
break;
case V_156 :
V_144 = 1 ;
break;
}
V_145 = ( V_140 & V_157 ) * 24 * 1000 ;
V_145 += ( ( ( V_140 & V_158 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_145 / ( V_142 * V_143 * V_144 * 5 ) ;
}
static void F_58 ( struct V_1 * V_6 ,
struct V_100 * V_159 )
{
struct V_22 * V_23 = V_6 -> V_7 . V_20 -> V_24 ;
int V_160 = 0 ;
T_2 V_161 , V_137 ;
V_137 = V_159 -> V_78 ;
V_161 = F_25 ( V_162 ) ;
if ( V_161 & F_59 ( V_137 ) ) {
V_160 = F_54 ( V_23 , V_137 ) ;
} else {
V_160 = V_161 & F_60 ( V_137 ) ;
V_160 >>= F_61 ( V_137 ) ;
switch ( V_160 ) {
case V_163 :
V_160 = 81000 ;
break;
case V_164 :
V_160 = 108000 ;
break;
case V_165 :
V_160 = 135000 ;
break;
case V_166 :
V_160 = 162000 ;
break;
case V_167 :
V_160 = 216000 ;
break;
case V_168 :
V_160 = 270000 ;
break;
default:
F_15 ( 1 , L_8 ) ;
break;
}
V_160 *= 2 ;
}
V_159 -> V_169 = V_160 ;
if ( V_159 -> V_170 )
V_159 -> V_7 . V_171 . V_172 =
F_62 ( V_159 -> V_169 ,
& V_159 -> V_173 ) ;
else
V_159 -> V_7 . V_171 . V_172 = V_159 -> V_169 ;
}
static void F_63 ( struct V_1 * V_6 ,
struct V_100 * V_159 )
{
struct V_22 * V_23 = V_6 -> V_7 . V_20 -> V_24 ;
int V_160 = 0 ;
T_1 V_174 , V_175 ;
V_174 = V_159 -> V_78 ;
switch ( V_174 & V_176 ) {
case V_177 :
V_160 = 81000 ;
break;
case V_178 :
V_160 = 135000 ;
break;
case V_179 :
V_160 = 270000 ;
break;
case V_180 :
V_160 = F_53 ( V_23 , V_181 ) ;
break;
case V_182 :
V_160 = F_53 ( V_23 , V_183 ) ;
break;
case V_79 :
V_175 = F_25 ( V_184 ) & V_185 ;
if ( V_175 == V_186 )
V_160 = 81000 ;
else if ( V_175 == V_187 )
V_160 = 135000 ;
else if ( V_175 == V_188 )
V_160 = 270000 ;
else {
F_15 ( 1 , L_9 ) ;
return;
}
break;
default:
F_15 ( 1 , L_10 ) ;
return;
}
V_159 -> V_169 = V_160 * 2 ;
if ( V_159 -> V_189 )
V_159 -> V_7 . V_171 . V_172 =
F_62 ( V_159 -> V_169 ,
& V_159 -> V_190 ) ;
else if ( V_159 -> V_170 )
V_159 -> V_7 . V_171 . V_172 =
F_62 ( V_159 -> V_169 ,
& V_159 -> V_173 ) ;
else
V_159 -> V_7 . V_171 . V_172 = V_159 -> V_169 ;
}
static int F_64 ( struct V_22 * V_23 ,
enum V_191 V_137 )
{
return 0 ;
}
static void F_65 ( struct V_1 * V_6 ,
struct V_100 * V_159 )
{
struct V_22 * V_23 = V_6 -> V_7 . V_20 -> V_24 ;
enum V_4 V_4 = F_6 ( V_6 ) ;
T_2 V_137 = V_4 ;
V_159 -> V_169 =
F_64 ( V_23 , V_137 ) ;
if ( V_159 -> V_170 )
V_159 -> V_7 . V_171 . V_172 =
F_62 ( V_159 -> V_169 ,
& V_159 -> V_173 ) ;
else
V_159 -> V_7 . V_171 . V_172 =
V_159 -> V_169 ;
}
void F_66 ( struct V_1 * V_6 ,
struct V_100 * V_159 )
{
struct V_19 * V_20 = V_6 -> V_7 . V_20 ;
if ( F_67 ( V_20 ) -> V_192 <= 8 )
F_63 ( V_6 , V_159 ) ;
else if ( F_11 ( V_20 ) )
F_58 ( V_6 , V_159 ) ;
else if ( F_9 ( V_20 ) )
F_65 ( V_6 , V_159 ) ;
}
static void
F_68 ( int clock ,
unsigned * V_193 , unsigned * V_194 , unsigned * V_195 )
{
T_3 V_110 ;
unsigned V_113 , V_112 , V_111 ;
struct V_114 V_115 = { 0 , 0 , 0 } ;
unsigned V_109 ;
V_110 = clock / 100 ;
V_109 = F_50 ( clock ) ;
if ( V_110 == 5400000 ) {
* V_194 = 2 ;
* V_195 = 1 ;
* V_193 = 2 ;
return;
}
for ( V_111 = V_124 * 2 / V_196 + 1 ;
V_111 <= V_124 * 2 / V_197 ;
V_111 ++ ) {
for ( V_112 = V_198 * V_111 / V_124 + 1 ;
V_112 <= V_199 * V_111 / V_124 ;
V_112 ++ ) {
for ( V_113 = V_200 ; V_113 <= V_201 ; V_113 += V_202 )
F_51 ( V_110 , V_109 ,
V_111 , V_112 , V_113 , & V_115 ) ;
}
}
* V_194 = V_115 . V_112 ;
* V_195 = V_115 . V_113 ;
* V_193 = V_115 . V_111 ;
}
static bool
F_69 ( struct V_65 * V_65 ,
struct V_100 * V_101 ,
struct V_1 * V_1 ,
int clock )
{
if ( V_1 -> type == V_12 ) {
struct V_203 * V_175 ;
T_2 V_174 ;
unsigned V_113 , V_112 , V_111 ;
F_68 ( clock * 1000 , & V_111 , & V_112 , & V_113 ) ;
V_174 = V_204 | V_131 |
F_70 ( V_111 ) | F_71 ( V_112 ) |
F_72 ( V_113 ) ;
memset ( & V_101 -> V_205 , 0 ,
sizeof( V_101 -> V_205 ) ) ;
V_101 -> V_205 . V_127 = V_174 ;
V_175 = F_73 ( V_65 , V_101 ) ;
if ( V_175 == NULL ) {
F_74 ( L_11 ,
F_45 ( V_65 -> V_99 ) ) ;
return false ;
}
V_101 -> V_78 = F_75 ( V_175 -> V_206 ) ;
}
return true ;
}
static void
F_76 ( int clock ,
struct V_207 * V_208 )
{
T_3 V_209 = clock * 5 ;
T_3 V_210 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
T_2 V_211 = 400 ;
T_2 V_212 = 3 ;
T_2 V_213 [ 4 ] = { 1 , 2 , 3 , 7 } ;
T_2 V_214 [ 4 ] = { 1 , 2 , 3 , 5 } ;
bool V_215 = false ;
T_2 V_216 = 0 ;
T_2 V_217 [ 3 ] = { 0 } , V_218 [ 3 ] = { 0 } ;
T_2 V_219 [ 3 ] = { 0 } ;
T_2 V_220 [ 3 ] ;
T_2 V_26 , V_221 , V_222 , V_223 ;
bool V_224 = false ;
T_3 V_145 ;
for ( V_223 = 0 ; V_223 < 3 ; V_223 ++ ) {
V_215 = false ;
V_216 =
F_77 ( V_210 [ V_223 ] , V_209 ) ;
if ( V_224 == false )
V_216 = ( V_216 % 2 == 0 ?
V_216 : V_216 + 1 ) ;
for ( V_221 = 1 ; V_221 < V_216 ; V_221 ++ ) {
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
if ( ! ( V_213 [ V_26 ] != 1 || V_221 == 1 ) )
continue;
for ( V_222 = 0 ; V_222 < 4 ; V_222 ++ ) {
if ( V_221 != 1 && V_214 [ V_222 ] != 2 )
continue;
if ( V_216 == V_213 [ V_26 ] * V_221 * V_214 [ V_222 ] ) {
V_215 = true ;
V_217 [ V_223 ] = V_213 [ V_26 ] ;
V_218 [ V_223 ] = V_221 ;
V_219 [ V_223 ] = V_214 [ V_222 ] ;
goto V_215;
}
}
}
}
V_215:
if ( V_215 ) {
V_220 [ V_223 ] =
F_77 ( 10000 *
F_52 ( ( V_216 * V_209 ) ,
V_210 [ V_223 ] ) ,
V_210 [ V_223 ] ) ;
if ( V_220 [ V_223 ] <
V_211 ) {
V_211 =
V_220 [ V_223 ] ;
V_212 = V_223 ;
}
}
if ( V_212 > 2 && V_223 == 2 ) {
V_224 = true ;
V_223 = 0 ;
}
}
if ( V_212 > 2 ) {
F_15 ( 1 , L_12 ) ;
} else {
V_208 -> V_225 = V_210 [ V_212 ] ;
switch ( V_210 [ V_212 ] ) {
case 9600000000ULL :
V_208 -> V_225 = 0 ;
break;
case 9000000000ULL :
V_208 -> V_225 = 1 ;
break;
case 8400000000ULL :
V_208 -> V_225 = 3 ;
}
switch ( V_217 [ V_212 ] ) {
case 1 :
V_208 -> V_226 = 0 ;
break;
case 2 :
V_208 -> V_226 = 1 ;
break;
case 3 :
V_208 -> V_226 = 2 ;
break;
case 7 :
V_208 -> V_226 = 4 ;
break;
default:
F_15 ( 1 , L_13 ) ;
}
switch ( V_219 [ V_212 ] ) {
case 5 :
V_208 -> V_227 = 0 ;
break;
case 2 :
V_208 -> V_227 = 1 ;
break;
case 3 :
V_208 -> V_227 = 2 ;
break;
case 1 :
V_208 -> V_227 = 3 ;
break;
default:
F_15 ( 1 , L_14 ) ;
}
V_208 -> V_228 = V_218 [ V_212 ] ;
V_208 -> V_229 =
( V_208 -> V_228 == 1 ) ? 0 : 1 ;
V_145 = V_217 [ V_212 ] *
V_218 [ V_212 ] *
V_219 [ V_212 ] * V_209 ;
V_208 -> V_230 = F_78 ( V_145 , ( 24 * F_79 ( 1 ) ) ) ;
V_208 -> V_231 =
F_78 ( ( ( F_78 ( V_145 , 24 ) -
V_208 -> V_230 * F_79 ( 1 ) ) * 0x8000 ) , F_79 ( 1 ) ) ;
}
}
static bool
F_80 ( struct V_65 * V_65 ,
struct V_100 * V_101 ,
struct V_1 * V_1 ,
int clock )
{
struct V_203 * V_175 ;
T_2 V_232 , V_233 , V_234 ;
V_232 = F_81 ( 0 ) ;
if ( V_1 -> type == V_12 ) {
struct V_207 V_208 = { 0 , } ;
V_232 |= F_59 ( 0 ) ;
F_76 ( clock * 1000 , & V_208 ) ;
V_233 = V_235 |
F_82 ( V_208 . V_231 ) |
V_208 . V_230 ;
V_234 = F_83 ( V_208 . V_228 ) |
F_57 ( V_208 . V_229 ) |
F_84 ( V_208 . V_227 ) |
F_85 ( V_208 . V_226 ) |
V_208 . V_225 ;
} else if ( V_1 -> type == V_10 ) {
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_93 * V_93 = F_41 ( V_6 ) ;
switch ( V_93 -> V_236 ) {
case V_237 :
V_232 |= F_86 ( V_163 , 0 ) ;
break;
case V_238 :
V_232 |= F_86 ( V_165 , 0 ) ;
break;
case V_239 :
V_232 |= F_86 ( V_168 , 0 ) ;
break;
}
V_233 = V_234 = 0 ;
} else
return true ;
memset ( & V_101 -> V_205 , 0 ,
sizeof( V_101 -> V_205 ) ) ;
V_101 -> V_205 . V_232 = V_232 ;
V_101 -> V_205 . V_233 = V_233 ;
V_101 -> V_205 . V_234 = V_234 ;
V_175 = F_73 ( V_65 , V_101 ) ;
if ( V_175 == NULL ) {
F_74 ( L_11 ,
F_45 ( V_65 -> V_99 ) ) ;
return false ;
}
V_101 -> V_78 = V_175 -> V_206 + 1 ;
return true ;
}
static bool
F_87 ( struct V_65 * V_65 ,
struct V_100 * V_101 ,
struct V_1 * V_1 ,
int clock )
{
struct V_203 * V_175 ;
struct V_240 V_241 = { 0 } ;
int V_242 = 0 ;
T_2 V_243 , V_244 , V_245 , V_246 ;
T_2 V_247 , V_248 , V_249 ;
if ( V_1 -> type == V_12 ) {
T_4 V_250 ;
if ( ! F_88 ( V_101 , clock , & V_250 ) ) {
F_74 ( L_15 ,
clock , F_45 ( V_65 -> V_99 ) ) ;
return false ;
}
V_241 . V_143 = V_250 . V_143 ;
V_241 . V_144 = V_250 . V_144 ;
F_34 ( V_250 . V_251 != 2 ) ;
V_241 . V_125 = V_250 . V_125 ;
V_241 . V_252 = V_250 . V_253 >> 22 ;
V_241 . V_254 = V_250 . V_253 & ( ( 1 << 22 ) - 1 ) ;
V_241 . V_255 = V_241 . V_254 != 0 ;
V_242 = V_250 . V_242 ;
} else if ( V_1 -> type == V_10 ||
V_1 -> type == V_11 ) {
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_93 * V_93 = F_41 ( V_6 ) ;
switch ( V_93 -> V_236 ) {
case V_237 :
V_241 = V_256 [ 0 ] ;
break;
case V_238 :
V_241 = V_256 [ 1 ] ;
break;
case V_239 :
V_241 = V_256 [ 2 ] ;
break;
default:
V_241 = V_256 [ 0 ] ;
F_4 ( L_16 ) ;
}
V_242 = clock * 10 / 2 * V_241 . V_143 * V_241 . V_144 ;
}
V_248 = 15 ;
V_247 = 0 ;
if ( V_242 >= 6200000 && V_242 <= 6480000 ) {
V_243 = 4 ;
V_244 = 9 ;
V_245 = 3 ;
V_246 = 8 ;
} else if ( ( V_242 > 5400000 && V_242 < 6200000 ) ||
( V_242 >= 4800000 && V_242 < 5400000 ) ) {
V_243 = 5 ;
V_244 = 11 ;
V_245 = 3 ;
V_246 = 9 ;
if ( V_242 >= 4800000 && V_242 < 5400000 )
V_247 = 1 ;
} else if ( V_242 == 5400000 ) {
V_243 = 3 ;
V_244 = 8 ;
V_245 = 1 ;
V_246 = 9 ;
} else {
F_4 ( L_17 ) ;
return false ;
}
memset ( & V_101 -> V_205 , 0 ,
sizeof( V_101 -> V_205 ) ) ;
if ( clock > 270000 )
V_249 = 0x18 ;
else if ( clock > 135000 )
V_249 = 0x0d ;
else if ( clock > 67000 )
V_249 = 0x07 ;
else if ( clock > 33000 )
V_249 = 0x04 ;
else
V_249 = 0x02 ;
V_101 -> V_205 . V_257 =
F_89 ( V_241 . V_143 ) | F_90 ( V_241 . V_144 ) ;
V_101 -> V_205 . V_258 = V_241 . V_252 ;
V_101 -> V_205 . V_259 = F_91 ( V_241 . V_125 ) ;
V_101 -> V_205 . V_260 = V_241 . V_254 ;
if ( V_241 . V_255 )
V_101 -> V_205 . V_261 =
V_262 ;
V_101 -> V_205 . V_263 =
V_243 | F_92 ( V_244 ) ;
V_101 -> V_205 . V_263 |=
F_93 ( V_245 ) ;
V_101 -> V_205 . V_264 = V_246 ;
if ( V_247 )
V_101 -> V_205 . V_265 = V_266 ;
V_101 -> V_205 . V_265 |= F_94 ( V_248 ) ;
V_101 -> V_205 . V_267 =
V_268 | V_249 ;
V_175 = F_73 ( V_65 , V_101 ) ;
if ( V_175 == NULL ) {
F_74 ( L_11 ,
F_45 ( V_65 -> V_99 ) ) ;
return false ;
}
V_101 -> V_78 = V_175 -> V_206 ;
return true ;
}
bool F_95 ( struct V_65 * V_65 ,
struct V_100 * V_101 )
{
struct V_19 * V_20 = V_65 -> V_7 . V_20 ;
struct V_1 * V_1 =
F_47 ( V_101 ) ;
int clock = V_101 -> V_169 ;
if ( F_11 ( V_20 ) )
return F_80 ( V_65 , V_101 ,
V_1 , clock ) ;
else if ( F_9 ( V_20 ) )
return F_87 ( V_65 , V_101 ,
V_1 , clock ) ;
else
return F_69 ( V_65 , V_101 ,
V_1 , clock ) ;
}
void F_96 ( struct V_63 * V_64 )
{
struct V_22 * V_23 = V_64 -> V_20 -> V_24 ;
struct V_65 * V_65 = F_28 ( V_64 ) ;
struct V_1 * V_1 = F_43 ( V_64 ) ;
enum V_269 V_270 = V_65 -> V_74 -> V_270 ;
int type = V_1 -> type ;
T_2 V_66 ;
if ( type == V_10 || type == V_11 || type == V_8 ) {
V_66 = V_271 ;
switch ( V_65 -> V_74 -> V_272 ) {
case 18 :
V_66 |= V_273 ;
break;
case 24 :
V_66 |= V_274 ;
break;
case 30 :
V_66 |= V_275 ;
break;
case 36 :
V_66 |= V_276 ;
break;
default:
F_5 () ;
}
F_18 ( F_97 ( V_270 ) , V_66 ) ;
}
}
void F_98 ( struct V_63 * V_64 , bool V_103 )
{
struct V_65 * V_65 = F_28 ( V_64 ) ;
struct V_19 * V_20 = V_64 -> V_20 ;
struct V_22 * V_23 = V_20 -> V_24 ;
enum V_269 V_270 = V_65 -> V_74 -> V_270 ;
T_2 V_66 ;
V_66 = F_25 ( F_99 ( V_270 ) ) ;
if ( V_103 == true )
V_66 |= V_277 ;
else
V_66 &= ~ V_277 ;
F_18 ( F_99 ( V_270 ) , V_66 ) ;
}
void F_100 ( struct V_63 * V_64 )
{
struct V_65 * V_65 = F_28 ( V_64 ) ;
struct V_1 * V_1 = F_43 ( V_64 ) ;
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_19 * V_20 = V_64 -> V_20 ;
struct V_22 * V_23 = V_20 -> V_24 ;
enum V_99 V_99 = V_65 -> V_99 ;
enum V_269 V_270 = V_65 -> V_74 -> V_270 ;
enum V_4 V_4 = F_6 ( V_1 ) ;
int type = V_1 -> type ;
T_2 V_66 ;
V_66 = V_278 ;
V_66 |= F_101 ( V_4 ) ;
switch ( V_65 -> V_74 -> V_272 ) {
case 18 :
V_66 |= V_279 ;
break;
case 24 :
V_66 |= V_280 ;
break;
case 30 :
V_66 |= V_281 ;
break;
case 36 :
V_66 |= V_282 ;
break;
default:
F_5 () ;
}
if ( V_65 -> V_74 -> V_7 . V_171 . V_283 & V_284 )
V_66 |= V_285 ;
if ( V_65 -> V_74 -> V_7 . V_171 . V_283 & V_286 )
V_66 |= V_287 ;
if ( V_270 == V_288 ) {
switch ( V_99 ) {
case V_289 :
if ( F_14 ( V_20 ) &&
( V_65 -> V_74 -> V_290 . V_291 ||
V_65 -> V_74 -> V_290 . V_292 ) )
V_66 |= V_293 ;
else
V_66 |= V_294 ;
break;
case V_295 :
V_66 |= V_296 ;
break;
case V_297 :
V_66 |= V_298 ;
break;
default:
F_5 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_65 -> V_74 -> V_299 )
V_66 |= V_300 ;
else
V_66 |= V_301 ;
} else if ( type == V_14 ) {
V_66 |= V_302 ;
V_66 |= ( V_65 -> V_74 -> V_75 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_93 * V_93 = F_41 ( V_6 ) ;
if ( V_93 -> V_303 ) {
V_66 |= V_304 ;
} else
V_66 |= V_305 ;
V_66 |= F_42 ( V_93 -> V_96 ) ;
} else if ( type == V_8 ) {
struct V_93 * V_93 = & F_2 ( V_6 ) -> V_9 -> V_306 ;
if ( V_93 -> V_303 ) {
V_66 |= V_304 ;
} else
V_66 |= V_305 ;
V_66 |= F_42 ( V_93 -> V_96 ) ;
} else {
F_15 ( 1 , L_18 ,
V_1 -> type , F_45 ( V_99 ) ) ;
}
F_18 ( F_99 ( V_270 ) , V_66 ) ;
}
void F_102 ( struct V_22 * V_23 ,
enum V_269 V_270 )
{
T_2 V_25 = F_99 ( V_270 ) ;
T_2 V_174 = F_25 ( V_25 ) ;
V_174 &= ~ ( V_278 | V_307 | V_277 ) ;
V_174 |= V_308 ;
F_18 ( V_25 , V_174 ) ;
}
bool F_103 ( struct V_309 * V_309 )
{
struct V_19 * V_20 = V_309 -> V_7 . V_20 ;
struct V_22 * V_23 = V_20 -> V_24 ;
struct V_1 * V_1 = V_309 -> V_6 ;
int type = V_309 -> V_7 . V_310 ;
enum V_4 V_4 = F_6 ( V_1 ) ;
enum V_99 V_99 = 0 ;
enum V_269 V_270 ;
enum V_311 V_312 ;
T_2 V_313 ;
V_312 = F_104 ( V_1 ) ;
if ( ! F_105 ( V_23 , V_312 ) )
return false ;
if ( ! V_1 -> V_314 ( V_1 , & V_99 ) )
return false ;
if ( V_4 == V_53 )
V_270 = V_288 ;
else
V_270 = (enum V_269 ) V_99 ;
V_313 = F_25 ( F_99 ( V_270 ) ) ;
switch ( V_313 & V_315 ) {
case V_300 :
case V_301 :
return ( type == V_316 ) ;
case V_305 :
if ( type == V_317 )
return true ;
return ( type == V_318 ) ;
case V_304 :
return false ;
case V_302 :
return ( type == V_319 ) ;
default:
return false ;
}
}
bool F_106 ( struct V_1 * V_6 ,
enum V_99 * V_99 )
{
struct V_19 * V_20 = V_6 -> V_7 . V_20 ;
struct V_22 * V_23 = V_20 -> V_24 ;
enum V_4 V_4 = F_6 ( V_6 ) ;
enum V_311 V_312 ;
T_1 V_313 ;
int V_26 ;
V_312 = F_104 ( V_6 ) ;
if ( ! F_105 ( V_23 , V_312 ) )
return false ;
V_313 = F_25 ( F_23 ( V_4 ) ) ;
if ( ! ( V_313 & V_84 ) )
return false ;
if ( V_4 == V_53 ) {
V_313 = F_25 ( F_99 ( V_288 ) ) ;
switch ( V_313 & V_320 ) {
case V_294 :
case V_293 :
* V_99 = V_289 ;
break;
case V_296 :
* V_99 = V_295 ;
break;
case V_298 :
* V_99 = V_297 ;
break;
}
return true ;
} else {
for ( V_26 = V_321 ; V_26 <= V_322 ; V_26 ++ ) {
V_313 = F_25 ( F_99 ( V_26 ) ) ;
if ( ( V_313 & V_307 )
== F_101 ( V_4 ) ) {
if ( ( V_313 & V_315 ) == V_304 )
return false ;
* V_99 = V_26 ;
return true ;
}
}
}
F_39 ( L_19 , F_26 ( V_4 ) ) ;
return false ;
}
void F_107 ( struct V_65 * V_65 )
{
struct V_63 * V_64 = & V_65 -> V_7 ;
struct V_22 * V_23 = V_64 -> V_20 -> V_24 ;
struct V_1 * V_1 = F_43 ( V_64 ) ;
enum V_4 V_4 = F_6 ( V_1 ) ;
enum V_269 V_270 = V_65 -> V_74 -> V_270 ;
if ( V_270 != V_288 )
F_18 ( F_108 ( V_270 ) ,
F_109 ( V_4 ) ) ;
}
void F_110 ( struct V_65 * V_65 )
{
struct V_22 * V_23 = V_65 -> V_7 . V_20 -> V_24 ;
enum V_269 V_270 = V_65 -> V_74 -> V_270 ;
if ( V_270 != V_288 )
F_18 ( F_108 ( V_270 ) ,
V_323 ) ;
}
void F_10 ( struct V_19 * V_20 , T_1 V_324 ,
enum V_4 V_4 , int type )
{
struct V_22 * V_23 = V_20 -> V_24 ;
const struct V_325 * V_41 ;
T_1 V_326 , V_26 ;
T_2 V_174 ;
if ( type == V_10 || type == V_11 ) {
V_326 = F_12 ( V_327 ) ;
V_41 = V_327 ;
} else if ( type == V_12 ) {
V_326 = F_12 ( V_328 ) ;
V_41 = V_328 ;
} else {
F_39 ( L_20 ,
type ) ;
return;
}
if ( V_324 >= V_326 ||
( type == V_12 && V_324 == V_59 ) ) {
for ( V_26 = 0 ; V_26 < V_326 ; V_26 ++ ) {
if ( V_41 [ V_26 ] . V_329 ) {
V_324 = V_26 ;
break;
}
}
}
V_174 = F_25 ( F_111 ( V_4 ) ) ;
V_174 &= ~ ( V_330 | V_331 ) ;
F_18 ( F_112 ( V_4 ) , V_174 ) ;
V_174 = F_25 ( F_113 ( V_4 ) ) ;
V_174 &= ~ ( V_332 | V_333 ) ;
V_174 |= V_41 [ V_324 ] . V_334 << V_335 |
V_41 [ V_324 ] . V_336 << V_337 ;
F_18 ( F_114 ( V_4 ) , V_174 ) ;
V_174 = F_25 ( F_115 ( V_4 ) ) ;
V_174 &= ~ V_338 ;
if ( V_41 [ V_324 ] . V_339 )
V_174 |= V_338 ;
F_18 ( F_116 ( V_4 ) , V_174 ) ;
V_174 = F_25 ( F_117 ( V_4 ) ) ;
V_174 &= ~ V_340 ;
V_174 |= V_41 [ V_324 ] . V_341 << V_342 ;
F_18 ( F_118 ( V_4 ) , V_174 ) ;
V_174 = F_25 ( F_111 ( V_4 ) ) ;
V_174 |= V_330 | V_331 ;
F_18 ( F_112 ( V_4 ) , V_174 ) ;
}
static void F_119 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_22 * V_23 = V_20 -> V_24 ;
struct V_65 * V_64 = F_28 ( V_6 -> V_64 ) ;
enum V_4 V_4 = F_6 ( V_1 ) ;
int type = V_1 -> type ;
int V_32 ;
if ( type == V_11 ) {
struct V_93 * V_93 = F_41 ( V_6 ) ;
F_120 ( V_93 ) ;
}
if ( F_11 ( V_20 ) ) {
T_2 V_137 = V_64 -> V_74 -> V_78 ;
T_2 V_174 ;
if ( type == V_11 ) {
F_34 ( V_137 != V_343 ) ;
V_174 = F_25 ( V_162 ) ;
V_174 &= ~ ( F_59 ( V_137 ) |
F_121 ( V_137 ) |
F_60 ( V_137 ) ) ;
V_174 |= V_64 -> V_74 -> V_205 . V_232 << ( V_137 * 6 ) ;
F_18 ( V_162 , V_174 ) ;
F_32 ( V_162 ) ;
}
V_174 = F_25 ( V_344 ) ;
V_174 &= ~ ( F_122 ( V_4 ) |
F_123 ( V_4 ) ) ;
V_174 |= ( F_124 ( V_137 , V_4 ) |
F_125 ( V_4 ) ) ;
F_18 ( V_344 , V_174 ) ;
} else if ( F_67 ( V_20 ) -> V_192 < 9 ) {
F_34 ( V_64 -> V_74 -> V_78 == V_345 ) ;
F_18 ( F_33 ( V_4 ) , V_64 -> V_74 -> V_78 ) ;
}
if ( type == V_10 || type == V_11 ) {
struct V_93 * V_93 = F_41 ( V_6 ) ;
F_40 ( V_1 ) ;
F_126 ( V_93 , V_346 ) ;
F_127 ( V_93 ) ;
F_128 ( V_93 ) ;
if ( V_4 != V_53 || F_67 ( V_20 ) -> V_192 >= 9 )
F_129 ( V_93 ) ;
} else if ( type == V_12 ) {
struct V_347 * V_347 = F_130 ( V_6 ) ;
if ( F_9 ( V_20 ) ) {
V_32 = V_23 -> V_33 .
V_34 [ V_4 ] . V_35 ;
F_10 ( V_20 , V_32 , V_4 ,
V_12 ) ;
}
V_347 -> V_348 ( V_6 ,
V_64 -> V_74 -> V_299 ,
& V_64 -> V_74 -> V_7 . V_171 ) ;
}
}
static void F_131 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_22 * V_23 = V_20 -> V_24 ;
enum V_4 V_4 = F_6 ( V_1 ) ;
int type = V_1 -> type ;
T_2 V_174 ;
bool V_349 = false ;
V_174 = F_25 ( F_23 ( V_4 ) ) ;
if ( V_174 & V_84 ) {
V_174 &= ~ V_84 ;
F_18 ( F_23 ( V_4 ) , V_174 ) ;
V_349 = true ;
}
V_174 = F_25 ( F_35 ( V_4 ) ) ;
V_174 &= ~ ( V_83 | V_92 ) ;
V_174 |= V_82 ;
F_18 ( F_35 ( V_4 ) , V_174 ) ;
if ( V_349 )
F_22 ( V_23 , V_4 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_93 * V_93 = F_41 ( V_6 ) ;
F_126 ( V_93 , V_350 ) ;
F_132 ( V_93 ) ;
F_133 ( V_93 ) ;
}
if ( F_11 ( V_20 ) )
F_18 ( V_344 , ( F_25 ( V_344 ) |
F_122 ( V_4 ) ) ) ;
else if ( F_67 ( V_20 ) -> V_192 < 9 )
F_18 ( F_33 ( V_4 ) , V_345 ) ;
}
static void F_134 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_63 * V_64 = V_6 -> V_64 ;
struct V_65 * V_65 = F_28 ( V_64 ) ;
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_22 * V_23 = V_20 -> V_24 ;
enum V_4 V_4 = F_6 ( V_1 ) ;
int type = V_1 -> type ;
if ( type == V_12 ) {
struct V_2 * V_16 =
F_3 ( V_6 ) ;
F_18 ( F_23 ( V_4 ) ,
V_16 -> V_95 |
V_84 ) ;
} else if ( type == V_11 ) {
struct V_93 * V_93 = F_41 ( V_6 ) ;
if ( V_4 == V_53 && F_67 ( V_20 ) -> V_192 < 9 )
F_129 ( V_93 ) ;
F_135 ( V_93 ) ;
F_136 ( V_93 ) ;
F_137 ( V_93 ) ;
}
if ( V_65 -> V_74 -> V_351 ) {
F_138 ( V_23 , V_352 ) ;
F_139 ( V_1 ) ;
}
}
static void F_140 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_63 * V_64 = V_6 -> V_64 ;
struct V_65 * V_65 = F_28 ( V_64 ) ;
int type = V_1 -> type ;
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_22 * V_23 = V_20 -> V_24 ;
if ( V_65 -> V_74 -> V_351 ) {
F_141 ( V_1 ) ;
F_142 ( V_23 , V_352 ) ;
}
if ( type == V_11 ) {
struct V_93 * V_93 = F_41 ( V_6 ) ;
F_143 ( V_93 ) ;
F_144 ( V_93 ) ;
F_145 ( V_93 ) ;
}
}
static void F_146 ( struct V_22 * V_23 ,
struct V_203 * V_175 )
{
F_18 ( F_147 ( V_175 -> V_206 ) , V_175 -> V_74 . V_353 . V_127 ) ;
F_32 ( F_147 ( V_175 -> V_206 ) ) ;
F_24 ( 20 ) ;
}
static void F_148 ( struct V_22 * V_23 ,
struct V_203 * V_175 )
{
T_2 V_174 ;
V_174 = F_25 ( F_147 ( V_175 -> V_206 ) ) ;
F_18 ( F_147 ( V_175 -> V_206 ) , V_174 & ~ V_204 ) ;
F_32 ( F_147 ( V_175 -> V_206 ) ) ;
}
static bool F_149 ( struct V_22 * V_23 ,
struct V_203 * V_175 ,
struct V_354 * V_353 )
{
T_2 V_174 ;
if ( ! F_105 ( V_23 , V_355 ) )
return false ;
V_174 = F_25 ( F_147 ( V_175 -> V_206 ) ) ;
V_353 -> V_127 = V_174 ;
return V_174 & V_204 ;
}
static void F_150 ( struct V_22 * V_23 )
{
int V_26 ;
V_23 -> V_356 = 2 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_356 ; V_26 ++ ) {
V_23 -> V_357 [ V_26 ] . V_206 = V_26 ;
V_23 -> V_357 [ V_26 ] . V_358 = V_359 [ V_26 ] ;
V_23 -> V_357 [ V_26 ] . V_360 = F_148 ;
V_23 -> V_357 [ V_26 ] . V_339 = F_146 ;
V_23 -> V_357 [ V_26 ] . V_314 =
F_149 ;
}
}
static void F_151 ( struct V_22 * V_23 ,
struct V_203 * V_175 )
{
T_2 V_174 ;
unsigned int V_137 ;
const struct V_361 * V_362 = V_361 ;
V_137 = V_175 -> V_206 + 1 ;
V_174 = F_25 ( V_162 ) ;
V_174 &= ~ ( F_59 ( V_137 ) | F_121 ( V_137 ) |
F_60 ( V_137 ) ) ;
V_174 |= V_175 -> V_74 . V_353 . V_232 << ( V_137 * 6 ) ;
F_18 ( V_162 , V_174 ) ;
F_32 ( V_162 ) ;
F_18 ( V_362 [ V_175 -> V_206 ] . V_233 , V_175 -> V_74 . V_353 . V_233 ) ;
F_18 ( V_362 [ V_175 -> V_206 ] . V_234 , V_175 -> V_74 . V_353 . V_234 ) ;
F_32 ( V_362 [ V_175 -> V_206 ] . V_233 ) ;
F_32 ( V_362 [ V_175 -> V_206 ] . V_234 ) ;
F_18 ( V_362 [ V_175 -> V_206 ] . V_363 ,
F_25 ( V_362 [ V_175 -> V_206 ] . V_363 ) | V_364 ) ;
if ( F_152 ( F_25 ( V_365 ) & F_153 ( V_137 ) , 5 ) )
F_4 ( L_21 , V_137 ) ;
}
static void F_154 ( struct V_22 * V_23 ,
struct V_203 * V_175 )
{
const struct V_361 * V_362 = V_361 ;
F_18 ( V_362 [ V_175 -> V_206 ] . V_363 ,
F_25 ( V_362 [ V_175 -> V_206 ] . V_363 ) & ~ V_364 ) ;
F_32 ( V_362 [ V_175 -> V_206 ] . V_363 ) ;
}
static bool F_155 ( struct V_22 * V_23 ,
struct V_203 * V_175 ,
struct V_354 * V_353 )
{
T_2 V_174 ;
unsigned int V_137 ;
const struct V_361 * V_362 = V_361 ;
if ( ! F_105 ( V_23 , V_355 ) )
return false ;
V_137 = V_175 -> V_206 + 1 ;
V_174 = F_25 ( V_362 [ V_175 -> V_206 ] . V_363 ) ;
if ( ! ( V_174 & V_364 ) )
return false ;
V_174 = F_25 ( V_162 ) ;
V_353 -> V_232 = ( V_174 >> ( V_137 * 6 ) ) & 0x3f ;
if ( V_174 & F_59 ( V_137 ) ) {
V_353 -> V_233 = F_25 ( V_362 [ V_175 -> V_206 ] . V_233 ) ;
V_353 -> V_234 = F_25 ( V_362 [ V_175 -> V_206 ] . V_234 ) ;
}
return true ;
}
static void F_156 ( struct V_22 * V_23 )
{
int V_26 ;
V_23 -> V_356 = 3 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_356 ; V_26 ++ ) {
V_23 -> V_357 [ V_26 ] . V_206 = V_26 ;
V_23 -> V_357 [ V_26 ] . V_358 = V_366 [ V_26 ] ;
V_23 -> V_357 [ V_26 ] . V_360 = F_154 ;
V_23 -> V_357 [ V_26 ] . V_339 = F_151 ;
V_23 -> V_357 [ V_26 ] . V_314 =
F_155 ;
}
}
static void F_157 ( struct V_22 * V_23 ,
enum V_367 V_368 )
{
enum V_4 V_4 ;
T_2 V_174 ;
V_174 = F_25 ( V_369 ) ;
V_174 |= F_158 ( V_368 ) ;
F_18 ( V_369 , V_174 ) ;
if ( F_152 ( F_25 ( F_159 ( V_368 ) ) & V_370 , 10 ) )
F_4 ( L_22 , V_368 ) ;
for ( V_4 = ( V_368 == V_371 ? V_54 : V_53 ) ;
V_4 <= ( V_368 == V_371 ? V_55 : V_53 ) ; V_4 ++ ) {
int V_372 ;
for ( V_372 = 0 ; V_372 < 4 ; V_372 ++ ) {
V_174 = F_25 ( F_160 ( V_4 , V_372 ) ) ;
V_174 &= ~ V_373 ;
if ( V_372 != 1 )
V_174 |= V_373 ;
F_18 ( F_160 ( V_4 , V_372 ) , V_174 ) ;
}
}
V_174 = F_25 ( F_161 ( V_368 ) ) ;
V_174 &= ~ V_374 ;
V_174 |= 0xE4 << V_375 ;
F_18 ( F_161 ( V_368 ) , V_174 ) ;
V_174 = F_25 ( F_162 ( V_368 ) ) ;
V_174 &= ~ V_376 ;
V_174 |= 0xE4 << V_377 ;
F_18 ( F_162 ( V_368 ) , V_174 ) ;
V_174 = F_25 ( F_163 ( V_368 ) ) ;
V_174 |= V_378 | V_379 |
V_380 ;
F_18 ( F_163 ( V_368 ) , V_174 ) ;
if ( V_368 == V_371 ) {
V_174 = F_25 ( V_381 ) ;
V_174 |= V_382 ;
F_18 ( V_381 , V_174 ) ;
}
V_174 = F_25 ( F_164 ( V_368 ) ) ;
V_174 &= ~ V_383 ;
if ( V_368 == V_384 )
V_174 |= V_383 ;
F_18 ( F_164 ( V_368 ) , V_174 ) ;
if ( V_368 == V_371 ) {
T_2 V_385 ;
if ( F_152 ( F_25 ( F_165 ( V_384 ) ) & V_386 ,
10 ) )
F_4 ( L_23 ) ;
V_174 = F_25 ( F_166 ( V_384 ) ) ;
V_174 = ( V_174 & V_387 ) >> V_388 ;
V_385 = V_174 << V_389 |
V_174 << V_390 |
V_174 ;
F_18 ( F_166 ( V_371 ) , V_385 ) ;
V_174 = F_25 ( F_167 ( V_371 ) ) ;
V_174 |= V_391 | V_392 ;
F_18 ( F_167 ( V_371 ) , V_174 ) ;
}
V_174 = F_25 ( F_168 ( V_368 ) ) ;
V_174 |= V_393 ;
F_18 ( F_168 ( V_368 ) , V_174 ) ;
}
void F_169 ( struct V_19 * V_20 )
{
F_157 ( V_20 -> V_24 , V_384 ) ;
F_157 ( V_20 -> V_24 , V_371 ) ;
}
static void F_170 ( struct V_22 * V_23 ,
enum V_367 V_368 )
{
T_2 V_174 ;
V_174 = F_25 ( F_168 ( V_368 ) ) ;
V_174 &= ~ V_393 ;
F_18 ( F_168 ( V_368 ) , V_174 ) ;
}
void F_171 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = V_20 -> V_24 ;
F_170 ( V_23 , V_384 ) ;
F_170 ( V_23 , V_371 ) ;
F_18 ( V_369 , 0 ) ;
}
static void F_172 ( struct V_22 * V_23 ,
struct V_203 * V_175 )
{
T_2 V_66 ;
enum V_4 V_4 = (enum V_4 ) V_175 -> V_206 ;
V_66 = F_25 ( F_173 ( V_4 ) ) ;
V_66 &= ~ V_394 ;
F_18 ( F_173 ( V_4 ) , V_66 ) ;
V_66 = F_25 ( F_174 ( V_4 ) ) ;
V_66 &= ~ V_395 ;
F_18 ( F_174 ( V_4 ) , V_66 ) ;
V_66 = F_25 ( F_175 ( V_4 ) ) ;
V_66 &= ~ ( V_396 | V_397 ) ;
V_66 |= V_175 -> V_74 . V_353 . V_257 ;
F_18 ( F_175 ( V_4 ) , V_66 ) ;
V_66 = F_25 ( F_176 ( V_4 , 0 ) ) ;
V_66 &= ~ V_398 ;
V_66 |= V_175 -> V_74 . V_353 . V_258 ;
F_18 ( F_176 ( V_4 , 0 ) , V_66 ) ;
V_66 = F_25 ( F_176 ( V_4 , 1 ) ) ;
V_66 &= ~ V_399 ;
V_66 |= V_175 -> V_74 . V_353 . V_259 ;
F_18 ( F_176 ( V_4 , 1 ) , V_66 ) ;
V_66 = F_25 ( F_176 ( V_4 , 2 ) ) ;
V_66 &= ~ V_400 ;
V_66 |= V_175 -> V_74 . V_353 . V_260 ;
F_18 ( F_176 ( V_4 , 2 ) , V_66 ) ;
V_66 = F_25 ( F_176 ( V_4 , 3 ) ) ;
V_66 &= ~ V_262 ;
V_66 |= V_175 -> V_74 . V_353 . V_261 ;
F_18 ( F_176 ( V_4 , 3 ) , V_66 ) ;
V_66 = F_25 ( F_176 ( V_4 , 6 ) ) ;
V_66 &= ~ V_401 ;
V_66 &= ~ V_402 ;
V_66 &= ~ V_403 ;
V_66 |= V_175 -> V_74 . V_353 . V_263 ;
F_18 ( F_176 ( V_4 , 6 ) , V_66 ) ;
V_66 = F_25 ( F_176 ( V_4 , 8 ) ) ;
V_66 &= ~ V_404 ;
V_66 |= V_175 -> V_74 . V_353 . V_264 ;
F_18 ( F_176 ( V_4 , 8 ) , V_66 ) ;
V_66 = F_25 ( F_176 ( V_4 , 9 ) ) ;
V_66 &= ~ V_405 ;
V_66 |= ( 5 << 1 ) ;
F_18 ( F_176 ( V_4 , 9 ) , V_66 ) ;
V_66 = F_25 ( F_176 ( V_4 , 10 ) ) ;
V_66 &= ~ V_266 ;
V_66 &= ~ V_406 ;
V_66 |= V_175 -> V_74 . V_353 . V_265 ;
F_18 ( F_176 ( V_4 , 10 ) , V_66 ) ;
V_66 = F_25 ( F_174 ( V_4 ) ) ;
V_66 |= V_407 ;
F_18 ( F_174 ( V_4 ) , V_66 ) ;
V_66 |= V_395 ;
F_18 ( F_174 ( V_4 ) , V_66 ) ;
V_66 = F_25 ( F_173 ( V_4 ) ) ;
V_66 |= V_408 ;
F_18 ( F_173 ( V_4 ) , V_66 ) ;
F_32 ( F_173 ( V_4 ) ) ;
if ( F_177 ( ( F_25 ( F_173 ( V_4 ) ) &
V_409 ) , 200 ) )
F_4 ( L_24 , V_4 ) ;
V_66 = F_25 ( F_178 ( V_4 ) ) ;
V_66 &= ~ V_410 ;
V_66 &= ~ V_268 ;
V_66 |= V_175 -> V_74 . V_353 . V_267 ;
F_18 ( F_179 ( V_4 ) , V_66 ) ;
}
static void F_180 ( struct V_22 * V_23 ,
struct V_203 * V_175 )
{
enum V_4 V_4 = (enum V_4 ) V_175 -> V_206 ;
T_2 V_66 ;
V_66 = F_25 ( F_173 ( V_4 ) ) ;
V_66 &= ~ V_408 ;
F_18 ( F_173 ( V_4 ) , V_66 ) ;
F_32 ( F_173 ( V_4 ) ) ;
}
static bool F_181 ( struct V_22 * V_23 ,
struct V_203 * V_175 ,
struct V_354 * V_353 )
{
enum V_4 V_4 = (enum V_4 ) V_175 -> V_206 ;
T_2 V_174 ;
if ( ! F_105 ( V_23 , V_355 ) )
return false ;
V_174 = F_25 ( F_173 ( V_4 ) ) ;
if ( ! ( V_174 & V_408 ) )
return false ;
V_353 -> V_257 = F_25 ( F_175 ( V_4 ) ) ;
V_353 -> V_258 = F_25 ( F_176 ( V_4 , 0 ) ) ;
V_353 -> V_259 = F_25 ( F_176 ( V_4 , 1 ) ) ;
V_353 -> V_260 = F_25 ( F_176 ( V_4 , 2 ) ) ;
V_353 -> V_261 = F_25 ( F_176 ( V_4 , 3 ) ) ;
V_353 -> V_263 = F_25 ( F_176 ( V_4 , 6 ) ) ;
V_353 -> V_264 = F_25 ( F_176 ( V_4 , 8 ) ) ;
V_353 -> V_265 = F_25 ( F_176 ( V_4 , 10 ) ) ;
V_353 -> V_267 = F_25 ( F_178 ( V_4 ) ) ;
if ( F_25 ( F_182 ( V_4 ) != V_353 -> V_267 ) )
F_74 ( L_25 ,
V_353 -> V_267 ,
F_25 ( F_182 ( V_4 ) ) ) ;
return true ;
}
static void F_183 ( struct V_22 * V_23 )
{
int V_26 ;
V_23 -> V_356 = 3 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_356 ; V_26 ++ ) {
V_23 -> V_357 [ V_26 ] . V_206 = V_26 ;
V_23 -> V_357 [ V_26 ] . V_358 = V_411 [ V_26 ] ;
V_23 -> V_357 [ V_26 ] . V_360 = F_180 ;
V_23 -> V_357 [ V_26 ] . V_339 = F_172 ;
V_23 -> V_357 [ V_26 ] . V_314 =
F_181 ;
}
}
void F_184 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = V_20 -> V_24 ;
T_2 V_174 = F_25 ( V_412 ) ;
int V_413 ;
if ( F_11 ( V_20 ) )
F_156 ( V_23 ) ;
else if ( F_9 ( V_20 ) )
F_183 ( V_23 ) ;
else
F_150 ( V_23 ) ;
V_413 = V_23 -> V_414 . V_415 ( V_20 ) ;
F_39 ( L_26 , V_413 ) ;
if ( F_11 ( V_20 ) ) {
V_23 -> V_416 = V_413 ;
if ( ! ( F_25 ( V_417 ) & V_364 ) )
F_4 ( L_27 ) ;
else
F_138 ( V_23 , V_355 ) ;
} else if ( F_9 ( V_20 ) ) {
F_185 ( V_20 ) ;
F_169 ( V_20 ) ;
} else {
if ( V_174 & V_418 )
F_4 ( L_28 ) ;
if ( V_174 & V_419 )
F_4 ( L_29 ) ;
}
}
void F_186 ( struct V_5 * V_6 )
{
struct V_2 * V_16 = F_3 ( V_6 ) ;
struct V_93 * V_93 = & V_16 -> V_306 ;
struct V_22 * V_23 = V_6 -> V_20 -> V_24 ;
enum V_4 V_4 = V_16 -> V_4 ;
T_2 V_174 ;
bool V_349 = false ;
if ( F_25 ( F_35 ( V_4 ) ) & V_83 ) {
V_174 = F_25 ( F_23 ( V_4 ) ) ;
if ( V_174 & V_84 ) {
V_174 &= ~ V_84 ;
F_18 ( F_23 ( V_4 ) , V_174 ) ;
V_349 = true ;
}
V_174 = F_25 ( F_35 ( V_4 ) ) ;
V_174 &= ~ ( V_83 | V_92 ) ;
V_174 |= V_82 ;
F_18 ( F_35 ( V_4 ) , V_174 ) ;
F_32 ( F_35 ( V_4 ) ) ;
if ( V_349 )
F_22 ( V_23 , V_4 ) ;
}
V_174 = V_83 |
V_82 | V_420 ;
if ( V_93 -> V_303 )
V_174 |= V_421 ;
else {
V_174 |= V_422 ;
if ( F_187 ( V_93 -> V_423 ) )
V_174 |= V_81 ;
}
F_18 ( F_35 ( V_4 ) , V_174 ) ;
F_32 ( F_35 ( V_4 ) ) ;
V_93 -> V_94 |= V_84 ;
F_18 ( F_23 ( V_4 ) , V_93 -> V_94 ) ;
F_32 ( F_23 ( V_4 ) ) ;
F_24 ( 600 ) ;
}
void F_188 ( struct V_63 * V_64 )
{
struct V_22 * V_23 = V_64 -> V_20 -> V_24 ;
struct V_1 * V_1 = F_43 ( V_64 ) ;
T_2 V_174 ;
F_131 ( V_1 ) ;
V_174 = F_25 ( V_76 ) ;
V_174 &= ~ V_86 ;
F_18 ( V_76 , V_174 ) ;
V_174 = F_25 ( V_68 ) ;
V_174 &= ~ ( V_88 | V_89 ) ;
V_174 |= F_29 ( 2 ) | F_30 ( 2 ) ;
F_18 ( V_68 , V_174 ) ;
V_174 = F_25 ( V_76 ) ;
V_174 &= ~ V_77 ;
F_18 ( V_76 , V_174 ) ;
V_174 = F_25 ( V_76 ) ;
V_174 &= ~ V_73 ;
F_18 ( V_76 , V_174 ) ;
}
static void F_189 ( struct V_1 * V_1 )
{
struct V_2 * V_16 = F_3 ( & V_1 -> V_7 ) ;
int type = V_16 -> V_7 . type ;
if ( type != V_10 &&
type != V_11 &&
type != V_13 ) {
return;
}
F_190 ( V_1 ) ;
}
void F_191 ( struct V_1 * V_6 ,
struct V_100 * V_159 )
{
struct V_22 * V_23 = V_6 -> V_7 . V_20 -> V_24 ;
struct V_65 * V_65 = F_28 ( V_6 -> V_7 . V_64 ) ;
enum V_269 V_270 = V_159 -> V_270 ;
struct V_347 * V_347 ;
T_1 V_66 , V_283 = 0 ;
V_66 = F_25 ( F_99 ( V_270 ) ) ;
if ( V_66 & V_287 )
V_283 |= V_286 ;
else
V_283 |= V_424 ;
if ( V_66 & V_285 )
V_283 |= V_284 ;
else
V_283 |= V_425 ;
V_159 -> V_7 . V_171 . V_283 |= V_283 ;
switch ( V_66 & V_426 ) {
case V_279 :
V_159 -> V_272 = 18 ;
break;
case V_280 :
V_159 -> V_272 = 24 ;
break;
case V_281 :
V_159 -> V_272 = 30 ;
break;
case V_282 :
V_159 -> V_272 = 36 ;
break;
default:
break;
}
switch ( V_66 & V_315 ) {
case V_300 :
V_159 -> V_299 = true ;
V_347 = F_130 ( & V_6 -> V_7 ) ;
if ( V_347 -> V_427 ( & V_6 -> V_7 ) )
V_159 -> V_428 = true ;
break;
case V_301 :
case V_302 :
break;
case V_305 :
case V_304 :
V_159 -> V_170 = true ;
F_192 ( V_65 , V_159 ) ;
break;
default:
break;
}
if ( F_105 ( V_23 , V_352 ) ) {
V_66 = F_25 ( V_429 ) ;
if ( V_66 & F_193 ( V_65 -> V_99 ) )
V_159 -> V_351 = true ;
}
if ( V_6 -> type == V_11 && V_23 -> V_33 . V_430 &&
V_159 -> V_272 > V_23 -> V_33 . V_430 ) {
F_39 ( L_30 ,
V_159 -> V_272 , V_23 -> V_33 . V_430 ) ;
V_23 -> V_33 . V_430 = V_159 -> V_272 ;
}
F_66 ( V_6 , V_159 ) ;
}
static void F_194 ( struct V_5 * V_6 )
{
F_195 ( V_6 ) ;
}
static bool F_196 ( struct V_1 * V_6 ,
struct V_100 * V_159 )
{
int type = V_6 -> type ;
int V_4 = F_6 ( V_6 ) ;
F_15 ( type == V_13 , L_31 ) ;
if ( V_4 == V_53 )
V_159 -> V_270 = V_288 ;
if ( type == V_12 )
return F_197 ( V_6 , V_159 ) ;
else
return F_198 ( V_6 , V_159 ) ;
}
static struct V_309 *
F_199 ( struct V_2 * V_16 )
{
struct V_309 * V_105 ;
enum V_4 V_4 = V_16 -> V_4 ;
V_105 = F_200 () ;
if ( ! V_105 )
return NULL ;
V_16 -> V_306 . V_431 = F_23 ( V_4 ) ;
if ( ! F_201 ( V_16 , V_105 ) ) {
F_202 ( V_105 ) ;
return NULL ;
}
return V_105 ;
}
static struct V_309 *
F_203 ( struct V_2 * V_16 )
{
struct V_309 * V_105 ;
enum V_4 V_4 = V_16 -> V_4 ;
V_105 = F_200 () ;
if ( ! V_105 )
return NULL ;
V_16 -> V_17 . V_18 = F_23 ( V_4 ) ;
F_204 ( V_16 , V_105 ) ;
return V_105 ;
}
void F_205 ( struct V_19 * V_20 , enum V_4 V_4 )
{
struct V_22 * V_23 = V_20 -> V_24 ;
struct V_2 * V_16 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
bool V_432 , V_433 ;
V_432 = ( V_23 -> V_33 . V_34 [ V_4 ] . V_434 ||
V_23 -> V_33 . V_34 [ V_4 ] . V_21 ) ;
V_433 = V_23 -> V_33 . V_34 [ V_4 ] . V_435 ;
if ( ! V_433 && ! V_432 ) {
F_39 ( L_32 ,
F_26 ( V_4 ) ) ;
V_432 = true ;
V_433 = true ;
}
V_16 = F_206 ( sizeof( * V_16 ) , V_436 ) ;
if ( ! V_16 )
return;
V_1 = & V_16 -> V_7 ;
V_6 = & V_1 -> V_7 ;
F_207 ( V_20 , V_6 , & V_437 ,
V_438 ) ;
V_1 -> V_439 = F_196 ;
V_1 -> V_339 = F_134 ;
V_1 -> V_440 = F_119 ;
V_1 -> V_360 = F_140 ;
V_1 -> V_441 = F_131 ;
V_1 -> V_314 = F_106 ;
V_1 -> V_442 = F_191 ;
V_16 -> V_4 = V_4 ;
V_16 -> V_95 = F_25 ( F_23 ( V_4 ) ) &
( V_443 |
V_444 ) ;
V_1 -> type = V_13 ;
V_1 -> V_445 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_1 -> V_446 = 0 ;
V_1 -> V_447 = F_189 ;
if ( V_433 ) {
if ( ! F_199 ( V_16 ) )
goto V_448;
V_16 -> V_449 = V_450 ;
V_23 -> V_451 [ V_4 ] = V_16 ;
}
if ( V_1 -> type != V_11 && V_432 ) {
if ( ! F_203 ( V_16 ) )
goto V_448;
}
return;
V_448:
F_208 ( V_6 ) ;
F_202 ( V_16 ) ;
}
