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
V_30 = V_35 ;
V_31 = V_36 ;
V_32 = V_37 ;
V_33 = V_38 ;
V_23 = F_8 ( V_38 ) ;
V_24 = 7 ;
} else if ( F_9 ( V_17 ) ) {
V_30 = V_39 ;
V_31 = V_40 ;
V_32 = V_40 ;
V_33 = V_41 ;
V_23 = F_8 ( V_41 ) ;
V_24 = 6 ;
} else {
F_10 ( 1 , L_2 ) ;
V_32 = V_36 ;
V_30 = V_35 ;
V_31 = V_36 ;
V_33 = V_38 ;
V_23 = F_8 ( V_38 ) ;
V_24 = 7 ;
}
switch ( V_1 ) {
case V_42 :
V_34 = V_32 ;
break;
case V_43 :
case V_44 :
V_34 = V_31 ;
break;
case V_45 :
if ( F_11 ( V_17 , V_45 ) )
V_34 = V_32 ;
else
V_34 = V_31 ;
break;
case V_15 :
V_34 = V_30 ;
break;
default:
F_5 () ;
}
for ( V_22 = 0 , V_21 = F_12 ( V_1 ) ;
V_22 < F_8 ( V_39 ) ; V_22 ++ ) {
F_13 ( V_21 , V_34 [ V_22 ] . V_46 ) ;
V_21 += 4 ;
F_13 ( V_21 , V_34 [ V_22 ] . V_47 ) ;
V_21 += 4 ;
}
if ( V_25 == V_48 ||
V_25 >= V_23 )
V_25 = V_24 ;
F_13 ( V_21 , V_33 [ V_25 ] . V_46 ) ;
V_21 += 4 ;
F_13 ( V_21 , V_33 [ V_25 ] . V_47 ) ;
V_21 += 4 ;
}
void F_14 ( struct V_16 * V_17 )
{
int V_1 ;
if ( ! F_15 ( V_17 ) )
return;
for ( V_1 = V_42 ; V_1 <= V_15 ; V_1 ++ )
F_6 ( V_17 , V_1 ) ;
}
static void F_16 ( struct V_18 * V_19 ,
enum V_1 V_1 )
{
T_2 V_21 = F_17 ( V_1 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
F_18 ( 1 ) ;
if ( F_19 ( V_21 ) & V_49 )
return;
}
F_4 ( L_3 , F_20 ( V_1 ) ) ;
}
void F_21 ( struct V_50 * V_51 )
{
struct V_16 * V_17 = V_51 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_52 * V_52 = F_22 ( V_51 ) ;
T_1 V_53 , V_22 , V_54 ;
F_13 ( V_55 , F_23 ( 2 ) |
F_24 ( 2 ) |
V_56 | V_57 ) ;
V_54 = V_19 -> V_58 | V_59 |
V_60 |
F_25 ( V_52 -> V_61 . V_62 ) ;
F_13 ( V_63 , V_54 ) ;
F_26 ( V_63 ) ;
F_18 ( 220 ) ;
V_54 |= V_64 ;
F_13 ( V_63 , V_54 ) ;
F_13 ( F_27 ( V_15 ) , V_52 -> V_61 . V_65 ) ;
F_28 ( V_52 -> V_61 . V_65 != V_66 ) ;
for ( V_22 = 0 ; V_22 < F_8 ( V_39 ) * 2 ; V_22 ++ ) {
F_13 ( F_29 ( V_15 ) ,
V_67 |
V_68 |
V_69 |
V_70 ) ;
F_13 ( F_17 ( V_15 ) ,
V_71 |
( ( V_52 -> V_61 . V_62 - 1 ) << 1 ) |
F_30 ( V_22 / 2 ) ) ;
F_26 ( F_17 ( V_15 ) ) ;
F_18 ( 600 ) ;
F_13 ( V_72 , F_31 ( 64 ) ) ;
V_54 |= V_73 | V_74 ;
F_13 ( V_63 , V_54 ) ;
F_26 ( V_63 ) ;
F_18 ( 30 ) ;
V_53 = F_19 ( V_55 ) ;
V_53 &= ~ ( V_75 | V_76 ) ;
F_13 ( V_55 , V_53 ) ;
F_26 ( V_55 ) ;
F_18 ( 5 ) ;
V_53 = F_19 ( F_32 ( V_15 ) ) ;
if ( V_53 & V_77 ) {
F_33 ( L_4 , V_22 ) ;
F_13 ( F_29 ( V_15 ) ,
V_67 |
V_78 |
V_68 |
V_70 ) ;
return;
}
V_53 = F_19 ( F_17 ( V_15 ) ) ;
V_53 &= ~ V_71 ;
F_13 ( F_17 ( V_15 ) , V_53 ) ;
F_26 ( F_17 ( V_15 ) ) ;
V_53 = F_19 ( F_29 ( V_15 ) ) ;
V_53 &= ~ ( V_70 | V_79 ) ;
V_53 |= V_69 ;
F_13 ( F_29 ( V_15 ) , V_53 ) ;
F_26 ( F_29 ( V_15 ) ) ;
F_16 ( V_19 , V_15 ) ;
V_54 &= ~ V_73 ;
F_13 ( V_63 , V_54 ) ;
F_26 ( V_63 ) ;
V_53 = F_19 ( V_55 ) ;
V_53 &= ~ ( V_75 | V_76 ) ;
V_53 |= F_23 ( 2 ) | F_24 ( 2 ) ;
F_13 ( V_55 , V_53 ) ;
F_26 ( V_55 ) ;
}
F_4 ( L_5 ) ;
}
void F_34 ( struct V_2 * V_4 )
{
struct V_80 * V_80 = F_35 ( & V_4 -> V_5 ) ;
struct V_7 * V_8 =
F_3 ( & V_4 -> V_5 ) ;
V_80 -> V_81 = V_8 -> V_82 |
V_71 | F_30 ( 0 ) ;
V_80 -> V_81 |= F_36 ( V_80 -> V_83 ) ;
}
static struct V_2 *
F_37 ( struct V_50 * V_51 )
{
struct V_16 * V_17 = V_51 -> V_17 ;
struct V_52 * V_52 = F_22 ( V_51 ) ;
struct V_2 * V_2 , * V_84 = NULL ;
int V_85 = 0 ;
F_38 (dev, crtc, intel_encoder) {
V_84 = V_2 ;
V_85 ++ ;
}
if ( V_85 != 1 )
F_10 ( 1 , L_6 , V_85 ,
F_39 ( V_52 -> V_86 ) ) ;
F_40 ( V_84 == NULL ) ;
return V_84 ;
}
static unsigned F_41 ( int clock )
{
unsigned V_87 ;
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
V_87 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_87 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_87 = 2000 ;
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
V_87 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_87 = 5000 ;
break;
default:
V_87 = 1000 ;
break;
}
return V_87 ;
}
static void F_42 ( T_3 V_88 , unsigned V_87 ,
unsigned V_89 , unsigned V_90 , unsigned V_91 ,
struct V_92 * V_93 )
{
T_3 V_94 , V_95 , V_96 , V_97 , V_98 , V_99 ;
if ( V_93 -> V_91 == 0 ) {
V_93 -> V_91 = V_91 ;
V_93 -> V_90 = V_90 ;
V_93 -> V_89 = V_89 ;
return;
}
V_94 = V_88 * V_87 * V_91 * V_89 ;
V_95 = V_88 * V_87 * V_93 -> V_91 * V_93 -> V_89 ;
V_98 = F_43 ( V_88 * V_91 * V_89 , V_100 * V_90 ) ;
V_99 = F_43 ( V_88 * V_93 -> V_91 * V_93 -> V_89 ,
V_100 * V_93 -> V_90 ) ;
V_96 = 1000000 * V_98 ;
V_97 = 1000000 * V_99 ;
if ( V_94 < V_96 && V_95 < V_97 ) {
if ( V_93 -> V_91 * V_93 -> V_89 * V_98 < V_91 * V_89 * V_99 ) {
V_93 -> V_91 = V_91 ;
V_93 -> V_90 = V_90 ;
V_93 -> V_89 = V_89 ;
}
} else if ( V_94 >= V_96 && V_95 < V_97 ) {
V_93 -> V_91 = V_91 ;
V_93 -> V_90 = V_90 ;
V_93 -> V_89 = V_89 ;
} else if ( V_94 >= V_96 && V_95 >= V_97 ) {
if ( V_90 * V_93 -> V_89 * V_93 -> V_89 > V_93 -> V_90 * V_89 * V_89 ) {
V_93 -> V_91 = V_91 ;
V_93 -> V_90 = V_90 ;
V_93 -> V_89 = V_89 ;
}
}
}
static int F_44 ( struct V_18 * V_19 ,
int V_21 )
{
int V_101 = V_102 ;
int V_103 , V_91 , V_104 ;
T_1 V_105 ;
V_105 = F_19 ( V_21 ) ;
switch ( V_105 & V_106 ) {
case V_107 :
case V_108 :
V_101 = 135 ;
break;
case V_109 :
V_101 = V_102 ;
break;
default:
F_10 ( 1 , L_7 ) ;
return 0 ;
}
V_104 = V_105 & V_110 ;
V_91 = ( V_105 & V_111 ) >> V_112 ;
V_103 = ( V_105 & V_113 ) >> V_114 ;
return ( V_101 * V_103 * 100 ) / ( V_91 * V_104 ) ;
}
static void F_45 ( struct V_2 * V_4 ,
struct V_115 * V_116 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
int V_117 = 0 ;
T_1 V_118 , V_119 ;
V_118 = V_116 -> V_65 ;
switch ( V_118 & V_120 ) {
case V_121 :
V_117 = 81000 ;
break;
case V_122 :
V_117 = 135000 ;
break;
case V_123 :
V_117 = 270000 ;
break;
case V_124 :
V_117 = F_44 ( V_19 , V_125 ) ;
break;
case V_126 :
V_117 = F_44 ( V_19 , V_127 ) ;
break;
case V_66 :
V_119 = F_19 ( V_128 ) & V_129 ;
if ( V_119 == V_130 )
V_117 = 81000 ;
else if ( V_119 == V_131 )
V_117 = 135000 ;
else if ( V_119 == V_132 )
V_117 = 270000 ;
else {
F_10 ( 1 , L_8 ) ;
return;
}
break;
default:
F_10 ( 1 , L_9 ) ;
return;
}
V_116 -> V_133 = V_117 * 2 ;
if ( V_116 -> V_134 )
V_116 -> V_135 . V_136 =
F_46 ( V_116 -> V_133 ,
& V_116 -> V_137 ) ;
else if ( V_116 -> V_138 )
V_116 -> V_135 . V_136 =
F_46 ( V_116 -> V_133 ,
& V_116 -> V_139 ) ;
else
V_116 -> V_135 . V_136 = V_116 -> V_133 ;
}
void F_47 ( struct V_2 * V_4 ,
struct V_115 * V_116 )
{
F_45 ( V_4 , V_116 ) ;
}
static void
F_48 ( int clock ,
unsigned * V_140 , unsigned * V_141 , unsigned * V_142 )
{
T_3 V_88 ;
unsigned V_91 , V_90 , V_89 ;
struct V_92 V_93 = { 0 , 0 , 0 } ;
unsigned V_87 ;
V_88 = clock / 100 ;
V_87 = F_41 ( clock ) ;
if ( V_88 == 5400000 ) {
* V_141 = 2 ;
* V_142 = 1 ;
* V_140 = 2 ;
return;
}
for ( V_89 = V_102 * 2 / V_143 + 1 ;
V_89 <= V_102 * 2 / V_144 ;
V_89 ++ ) {
for ( V_90 = V_145 * V_89 / V_102 + 1 ;
V_90 <= V_146 * V_89 / V_102 ;
V_90 ++ ) {
for ( V_91 = V_147 ; V_91 <= V_148 ; V_91 += V_149 )
F_42 ( V_88 , V_87 ,
V_89 , V_90 , V_91 , & V_93 ) ;
}
}
* V_141 = V_93 . V_90 ;
* V_142 = V_93 . V_91 ;
* V_140 = V_93 . V_89 ;
}
static bool
F_49 ( struct V_52 * V_52 ,
struct V_2 * V_2 ,
int clock )
{
if ( V_2 -> type == V_12 ) {
struct V_150 * V_119 ;
T_2 V_118 ;
unsigned V_91 , V_90 , V_89 ;
F_48 ( clock * 1000 , & V_89 , & V_90 , & V_91 ) ;
V_118 = V_151 | V_109 |
F_50 ( V_89 ) | F_51 ( V_90 ) |
F_52 ( V_91 ) ;
V_52 -> V_61 . V_152 . V_105 = V_118 ;
V_119 = F_53 ( V_52 ) ;
if ( V_119 == NULL ) {
F_54 ( L_10 ,
F_39 ( V_52 -> V_86 ) ) ;
return false ;
}
V_52 -> V_61 . V_65 = F_55 ( V_119 -> V_153 ) ;
}
return true ;
}
bool F_56 ( struct V_52 * V_52 )
{
struct V_50 * V_51 = & V_52 -> V_5 ;
struct V_2 * V_2 = F_37 ( V_51 ) ;
int clock = V_52 -> V_61 . V_133 ;
F_57 ( V_52 ) ;
return F_49 ( V_52 , V_2 , clock ) ;
}
void F_58 ( struct V_50 * V_51 )
{
struct V_18 * V_19 = V_51 -> V_17 -> V_20 ;
struct V_52 * V_52 = F_22 ( V_51 ) ;
struct V_2 * V_2 = F_37 ( V_51 ) ;
enum V_154 V_155 = V_52 -> V_61 . V_155 ;
int type = V_2 -> type ;
T_2 V_53 ;
if ( type == V_10 || type == V_11 || type == V_6 ) {
V_53 = V_156 ;
switch ( V_52 -> V_61 . V_157 ) {
case 18 :
V_53 |= V_158 ;
break;
case 24 :
V_53 |= V_159 ;
break;
case 30 :
V_53 |= V_160 ;
break;
case 36 :
V_53 |= V_161 ;
break;
default:
F_5 () ;
}
F_13 ( F_59 ( V_155 ) , V_53 ) ;
}
}
void F_60 ( struct V_50 * V_51 , bool V_162 )
{
struct V_52 * V_52 = F_22 ( V_51 ) ;
struct V_16 * V_17 = V_51 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_154 V_155 = V_52 -> V_61 . V_155 ;
T_2 V_53 ;
V_53 = F_19 ( F_61 ( V_155 ) ) ;
if ( V_162 == true )
V_53 |= V_163 ;
else
V_53 &= ~ V_163 ;
F_13 ( F_61 ( V_155 ) , V_53 ) ;
}
void F_62 ( struct V_50 * V_51 )
{
struct V_52 * V_52 = F_22 ( V_51 ) ;
struct V_2 * V_2 = F_37 ( V_51 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_51 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_86 V_86 = V_52 -> V_86 ;
enum V_154 V_155 = V_52 -> V_61 . V_155 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_53 ;
V_53 = V_164 ;
V_53 |= F_63 ( V_1 ) ;
switch ( V_52 -> V_61 . V_157 ) {
case 18 :
V_53 |= V_165 ;
break;
case 24 :
V_53 |= V_166 ;
break;
case 30 :
V_53 |= V_167 ;
break;
case 36 :
V_53 |= V_168 ;
break;
default:
F_5 () ;
}
if ( V_52 -> V_61 . V_135 . V_169 & V_170 )
V_53 |= V_171 ;
if ( V_52 -> V_61 . V_135 . V_169 & V_172 )
V_53 |= V_173 ;
if ( V_155 == V_174 ) {
switch ( V_86 ) {
case V_175 :
if ( F_9 ( V_17 ) &&
( V_52 -> V_61 . V_176 . V_177 ||
V_52 -> V_61 . V_176 . V_178 ) )
V_53 |= V_179 ;
else
V_53 |= V_180 ;
break;
case V_181 :
V_53 |= V_182 ;
break;
case V_183 :
V_53 |= V_184 ;
break;
default:
F_5 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_52 -> V_61 . V_185 )
V_53 |= V_186 ;
else
V_53 |= V_187 ;
} else if ( type == V_14 ) {
V_53 |= V_188 ;
V_53 |= ( V_52 -> V_61 . V_62 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_80 * V_80 = F_35 ( V_4 ) ;
if ( V_80 -> V_189 ) {
V_53 |= V_190 ;
} else
V_53 |= V_191 ;
V_53 |= F_36 ( V_80 -> V_83 ) ;
} else if ( type == V_6 ) {
struct V_80 * V_80 = & F_2 ( V_4 ) -> V_9 -> V_192 ;
if ( V_80 -> V_189 ) {
V_53 |= V_190 ;
} else
V_53 |= V_191 ;
V_53 |= F_36 ( V_80 -> V_83 ) ;
} else {
F_10 ( 1 , L_11 ,
V_2 -> type , F_39 ( V_86 ) ) ;
}
F_13 ( F_61 ( V_155 ) , V_53 ) ;
}
void F_64 ( struct V_18 * V_19 ,
enum V_154 V_155 )
{
T_2 V_21 = F_61 ( V_155 ) ;
T_2 V_118 = F_19 ( V_21 ) ;
V_118 &= ~ ( V_164 | V_193 | V_163 ) ;
V_118 |= V_194 ;
F_13 ( V_21 , V_118 ) ;
}
bool F_65 ( struct V_195 * V_195 )
{
struct V_16 * V_17 = V_195 -> V_5 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_2 * V_2 = V_195 -> V_4 ;
int type = V_195 -> V_5 . V_196 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_86 V_86 = 0 ;
enum V_154 V_155 ;
enum V_197 V_198 ;
T_2 V_199 ;
V_198 = F_66 ( V_2 ) ;
if ( ! F_67 ( V_19 , V_198 ) )
return false ;
if ( ! V_2 -> V_200 ( V_2 , & V_86 ) )
return false ;
if ( V_1 == V_42 )
V_155 = V_174 ;
else
V_155 = (enum V_154 ) V_86 ;
V_199 = F_19 ( F_61 ( V_155 ) ) ;
switch ( V_199 & V_201 ) {
case V_186 :
case V_187 :
return ( type == V_202 ) ;
case V_191 :
if ( type == V_203 )
return true ;
return ( type == V_204 ) ;
case V_190 :
return false ;
case V_188 :
return ( type == V_205 ) ;
default:
return false ;
}
}
bool F_68 ( struct V_2 * V_4 ,
enum V_86 * V_86 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
enum V_197 V_198 ;
T_1 V_199 ;
int V_22 ;
V_198 = F_66 ( V_4 ) ;
if ( ! F_67 ( V_19 , V_198 ) )
return false ;
V_199 = F_19 ( F_17 ( V_1 ) ) ;
if ( ! ( V_199 & V_71 ) )
return false ;
if ( V_1 == V_42 ) {
V_199 = F_19 ( F_61 ( V_174 ) ) ;
switch ( V_199 & V_206 ) {
case V_180 :
case V_179 :
* V_86 = V_175 ;
break;
case V_182 :
* V_86 = V_181 ;
break;
case V_184 :
* V_86 = V_183 ;
break;
}
return true ;
} else {
for ( V_22 = V_207 ; V_22 <= V_208 ; V_22 ++ ) {
V_199 = F_19 ( F_61 ( V_22 ) ) ;
if ( ( V_199 & V_193 )
== F_63 ( V_1 ) ) {
if ( ( V_199 & V_201 ) == V_190 )
return false ;
* V_86 = V_22 ;
return true ;
}
}
}
F_33 ( L_12 , F_20 ( V_1 ) ) ;
return false ;
}
void F_69 ( struct V_52 * V_52 )
{
struct V_50 * V_51 = & V_52 -> V_5 ;
struct V_18 * V_19 = V_51 -> V_17 -> V_20 ;
struct V_2 * V_2 = F_37 ( V_51 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_154 V_155 = V_52 -> V_61 . V_155 ;
if ( V_155 != V_174 )
F_13 ( F_70 ( V_155 ) ,
F_71 ( V_1 ) ) ;
}
void F_72 ( struct V_52 * V_52 )
{
struct V_18 * V_19 = V_52 -> V_5 . V_17 -> V_20 ;
enum V_154 V_155 = V_52 -> V_61 . V_155 ;
if ( V_155 != V_174 )
F_13 ( F_70 ( V_155 ) ,
V_209 ) ;
}
static void F_73 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_18 * V_19 = V_4 -> V_17 -> V_20 ;
struct V_52 * V_51 = F_22 ( V_4 -> V_51 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( V_51 -> V_61 . V_210 ) {
F_54 ( L_13 ,
F_39 ( V_51 -> V_86 ) ) ;
F_54 ( L_14 ) ;
F_74 ( V_4 , & V_51 -> V_61 . V_135 ) ;
}
if ( type == V_11 ) {
struct V_80 * V_80 = F_35 ( V_4 ) ;
F_75 ( V_80 ) ;
}
F_28 ( V_51 -> V_61 . V_65 == V_211 ) ;
F_13 ( F_27 ( V_1 ) , V_51 -> V_61 . V_65 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_80 * V_80 = F_35 ( V_4 ) ;
F_34 ( V_2 ) ;
F_76 ( V_80 , V_212 ) ;
F_77 ( V_80 ) ;
F_78 ( V_80 ) ;
if ( V_1 != V_42 )
F_79 ( V_80 ) ;
} else if ( type == V_12 ) {
struct V_213 * V_213 = F_80 ( V_4 ) ;
V_213 -> V_214 ( V_4 ,
V_51 -> V_61 . V_185 ,
& V_51 -> V_61 . V_135 ) ;
}
}
static void F_81 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_18 * V_19 = V_4 -> V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_118 ;
bool V_215 = false ;
V_118 = F_19 ( F_17 ( V_1 ) ) ;
if ( V_118 & V_71 ) {
V_118 &= ~ V_71 ;
F_13 ( F_17 ( V_1 ) , V_118 ) ;
V_215 = true ;
}
V_118 = F_19 ( F_29 ( V_1 ) ) ;
V_118 &= ~ ( V_70 | V_79 ) ;
V_118 |= V_69 ;
F_13 ( F_29 ( V_1 ) , V_118 ) ;
if ( V_215 )
F_16 ( V_19 , V_1 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_80 * V_80 = F_35 ( V_4 ) ;
F_76 ( V_80 , V_216 ) ;
F_82 ( V_80 ) ;
F_83 ( V_80 ) ;
}
F_13 ( F_27 ( V_1 ) , V_211 ) ;
}
static void F_84 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_50 * V_51 = V_4 -> V_51 ;
struct V_52 * V_52 = F_22 ( V_51 ) ;
int V_86 = V_52 -> V_86 ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_199 ;
if ( type == V_12 ) {
struct V_7 * V_8 =
F_3 ( V_4 ) ;
F_13 ( F_17 ( V_1 ) ,
V_8 -> V_82 |
V_71 ) ;
} else if ( type == V_11 ) {
struct V_80 * V_80 = F_35 ( V_4 ) ;
if ( V_1 == V_42 )
F_79 ( V_80 ) ;
F_85 ( V_80 ) ;
F_86 ( V_80 ) ;
}
if ( V_52 -> V_61 . V_210 ) {
F_87 ( V_19 , V_217 ) ;
V_199 = F_19 ( V_218 ) ;
V_199 |= ( ( V_219 | V_220 ) << ( V_86 * 4 ) ) ;
F_13 ( V_218 , V_199 ) ;
}
}
static void F_88 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_50 * V_51 = V_4 -> V_51 ;
struct V_52 * V_52 = F_22 ( V_51 ) ;
int V_86 = V_52 -> V_86 ;
int type = V_2 -> type ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
T_2 V_199 ;
if ( V_52 -> V_61 . V_210 ) {
V_199 = F_19 ( V_218 ) ;
V_199 &= ~ ( ( V_219 | V_220 ) <<
( V_86 * 4 ) ) ;
F_13 ( V_218 , V_199 ) ;
F_89 ( V_19 , V_217 ) ;
}
if ( type == V_11 ) {
struct V_80 * V_80 = F_35 ( V_4 ) ;
F_90 ( V_80 ) ;
F_91 ( V_80 ) ;
}
}
static int F_92 ( struct V_18 * V_19 )
{
T_2 V_221 = F_19 ( V_222 ) ;
T_2 V_223 = V_221 & V_224 ;
if ( V_221 & V_225 )
return 800000 ;
else if ( F_19 ( V_226 ) & V_227 )
return 450000 ;
else if ( V_223 == V_228 )
return 450000 ;
else if ( V_223 == V_229 )
return 540000 ;
else if ( V_223 == V_230 )
return 337500 ;
else
return 675000 ;
}
static int F_93 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_17 ;
T_2 V_221 = F_19 ( V_222 ) ;
T_2 V_223 = V_221 & V_224 ;
if ( V_221 & V_225 )
return 800000 ;
else if ( F_19 ( V_226 ) & V_227 )
return 450000 ;
else if ( V_223 == V_228 )
return 450000 ;
else if ( F_94 ( V_17 ) )
return 337500 ;
else
return 540000 ;
}
int F_95 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_17 ;
if ( F_7 ( V_17 ) )
return F_92 ( V_19 ) ;
return F_93 ( V_19 ) ;
}
static void F_96 ( struct V_18 * V_19 ,
struct V_150 * V_119 )
{
F_13 ( F_97 ( V_119 -> V_153 ) , V_119 -> V_231 . V_105 ) ;
F_26 ( F_97 ( V_119 -> V_153 ) ) ;
F_18 ( 20 ) ;
}
static void F_98 ( struct V_18 * V_19 ,
struct V_150 * V_119 )
{
T_2 V_118 ;
V_118 = F_19 ( F_97 ( V_119 -> V_153 ) ) ;
F_13 ( F_97 ( V_119 -> V_153 ) , V_118 & ~ V_151 ) ;
F_26 ( F_97 ( V_119 -> V_153 ) ) ;
}
static bool F_99 ( struct V_18 * V_19 ,
struct V_150 * V_119 ,
struct V_232 * V_231 )
{
T_2 V_118 ;
if ( ! F_67 ( V_19 , V_233 ) )
return false ;
V_118 = F_19 ( F_97 ( V_119 -> V_153 ) ) ;
V_231 -> V_105 = V_118 ;
return V_118 & V_151 ;
}
static void F_100 ( struct V_18 * V_19 )
{
int V_22 ;
V_19 -> V_234 = 2 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_234 ; V_22 ++ ) {
V_19 -> V_235 [ V_22 ] . V_153 = V_22 ;
V_19 -> V_235 [ V_22 ] . V_236 = V_237 [ V_22 ] ;
V_19 -> V_235 [ V_22 ] . V_238 = F_98 ;
V_19 -> V_235 [ V_22 ] . V_239 = F_96 ;
V_19 -> V_235 [ V_22 ] . V_200 =
F_99 ;
}
}
void F_101 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
T_2 V_118 = F_19 ( V_222 ) ;
F_100 ( V_19 ) ;
F_33 ( L_15 ,
F_95 ( V_19 ) ) ;
if ( V_118 & V_225 )
F_4 ( L_16 ) ;
if ( V_118 & V_240 )
F_4 ( L_17 ) ;
}
void F_102 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_80 * V_80 = & V_8 -> V_192 ;
struct V_18 * V_19 = V_4 -> V_17 -> V_20 ;
enum V_1 V_1 = V_8 -> V_1 ;
T_2 V_118 ;
bool V_215 = false ;
if ( F_19 ( F_29 ( V_1 ) ) & V_70 ) {
V_118 = F_19 ( F_17 ( V_1 ) ) ;
if ( V_118 & V_71 ) {
V_118 &= ~ V_71 ;
F_13 ( F_17 ( V_1 ) , V_118 ) ;
V_215 = true ;
}
V_118 = F_19 ( F_29 ( V_1 ) ) ;
V_118 &= ~ ( V_70 | V_79 ) ;
V_118 |= V_69 ;
F_13 ( F_29 ( V_1 ) , V_118 ) ;
F_26 ( F_29 ( V_1 ) ) ;
if ( V_215 )
F_16 ( V_19 , V_1 ) ;
}
V_118 = V_70 |
V_69 | V_241 ;
if ( V_80 -> V_189 )
V_118 |= V_242 ;
else {
V_118 |= V_243 ;
if ( F_103 ( V_80 -> V_244 ) )
V_118 |= V_68 ;
}
F_13 ( F_29 ( V_1 ) , V_118 ) ;
F_26 ( F_29 ( V_1 ) ) ;
V_80 -> V_81 |= V_71 ;
F_13 ( F_17 ( V_1 ) , V_80 -> V_81 ) ;
F_26 ( F_17 ( V_1 ) ) ;
F_18 ( 600 ) ;
}
void F_104 ( struct V_50 * V_51 )
{
struct V_18 * V_19 = V_51 -> V_17 -> V_20 ;
struct V_2 * V_2 = F_37 ( V_51 ) ;
T_2 V_118 ;
F_81 ( V_2 ) ;
V_118 = F_19 ( V_63 ) ;
V_118 &= ~ V_73 ;
F_13 ( V_63 , V_118 ) ;
V_118 = F_19 ( V_55 ) ;
V_118 &= ~ ( V_75 | V_76 ) ;
V_118 |= F_23 ( 2 ) | F_24 ( 2 ) ;
F_13 ( V_55 , V_118 ) ;
V_118 = F_19 ( V_63 ) ;
V_118 &= ~ V_64 ;
F_13 ( V_63 , V_118 ) ;
V_118 = F_19 ( V_63 ) ;
V_118 &= ~ V_60 ;
F_13 ( V_63 , V_118 ) ;
}
static void F_105 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_3 ( & V_2 -> V_5 ) ;
int type = V_8 -> V_5 . type ;
if ( type != V_10 &&
type != V_11 &&
type != V_13 ) {
return;
}
F_106 ( V_2 ) ;
}
void F_107 ( struct V_2 * V_4 ,
struct V_115 * V_116 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
struct V_52 * V_52 = F_22 ( V_4 -> V_5 . V_51 ) ;
enum V_154 V_155 = V_52 -> V_61 . V_155 ;
T_1 V_53 , V_169 = 0 ;
V_53 = F_19 ( F_61 ( V_155 ) ) ;
if ( V_53 & V_173 )
V_169 |= V_172 ;
else
V_169 |= V_245 ;
if ( V_53 & V_171 )
V_169 |= V_170 ;
else
V_169 |= V_246 ;
V_116 -> V_135 . V_169 |= V_169 ;
switch ( V_53 & V_247 ) {
case V_165 :
V_116 -> V_157 = 18 ;
break;
case V_166 :
V_116 -> V_157 = 24 ;
break;
case V_167 :
V_116 -> V_157 = 30 ;
break;
case V_168 :
V_116 -> V_157 = 36 ;
break;
default:
break;
}
switch ( V_53 & V_201 ) {
case V_186 :
V_116 -> V_185 = true ;
case V_187 :
case V_188 :
break;
case V_191 :
case V_190 :
V_116 -> V_138 = true ;
F_108 ( V_52 , V_116 ) ;
break;
default:
break;
}
if ( F_67 ( V_19 , V_217 ) ) {
V_53 = F_19 ( V_218 ) ;
if ( V_53 & ( V_219 << ( V_52 -> V_86 * 4 ) ) )
V_116 -> V_210 = true ;
}
if ( V_4 -> type == V_11 && V_19 -> V_26 . V_248 &&
V_116 -> V_157 > V_19 -> V_26 . V_248 ) {
F_33 ( L_18 ,
V_116 -> V_157 , V_19 -> V_26 . V_248 ) ;
V_19 -> V_26 . V_248 = V_116 -> V_157 ;
}
F_45 ( V_4 , V_116 ) ;
}
static void F_109 ( struct V_3 * V_4 )
{
F_110 ( V_4 ) ;
}
static bool F_111 ( struct V_2 * V_4 ,
struct V_115 * V_116 )
{
int type = V_4 -> type ;
int V_1 = F_1 ( V_4 ) ;
F_10 ( type == V_13 , L_19 ) ;
if ( V_1 == V_42 )
V_116 -> V_155 = V_174 ;
if ( type == V_12 )
return F_112 ( V_4 , V_116 ) ;
else
return F_113 ( V_4 , V_116 ) ;
}
static struct V_195 *
F_114 ( struct V_7 * V_8 )
{
struct V_195 * V_249 ;
enum V_1 V_1 = V_8 -> V_1 ;
V_249 = F_115 ( sizeof( * V_249 ) , V_250 ) ;
if ( ! V_249 )
return NULL ;
V_8 -> V_192 . V_251 = F_17 ( V_1 ) ;
if ( ! F_116 ( V_8 , V_249 ) ) {
F_117 ( V_249 ) ;
return NULL ;
}
return V_249 ;
}
static struct V_195 *
F_118 ( struct V_7 * V_8 )
{
struct V_195 * V_249 ;
enum V_1 V_1 = V_8 -> V_1 ;
V_249 = F_115 ( sizeof( * V_249 ) , V_250 ) ;
if ( ! V_249 )
return NULL ;
V_8 -> V_252 . V_253 = F_17 ( V_1 ) ;
F_119 ( V_8 , V_249 ) ;
return V_249 ;
}
void F_120 ( struct V_16 * V_17 , enum V_1 V_1 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_7 * V_8 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
bool V_254 , V_255 ;
V_254 = ( V_19 -> V_26 . V_27 [ V_1 ] . V_256 ||
V_19 -> V_26 . V_27 [ V_1 ] . V_257 ) ;
V_255 = V_19 -> V_26 . V_27 [ V_1 ] . V_258 ;
if ( ! V_255 && ! V_254 ) {
F_33 ( L_20 ,
F_20 ( V_1 ) ) ;
V_254 = true ;
V_255 = true ;
}
V_8 = F_115 ( sizeof( * V_8 ) , V_250 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_121 ( V_17 , V_4 , & V_259 ,
V_260 ) ;
V_2 -> V_261 = F_111 ;
V_2 -> V_239 = F_84 ;
V_2 -> V_262 = F_73 ;
V_2 -> V_238 = F_88 ;
V_2 -> V_263 = F_81 ;
V_2 -> V_200 = F_68 ;
V_2 -> V_264 = F_107 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_82 = F_19 ( F_17 ( V_1 ) ) &
( V_265 |
V_266 ) ;
V_2 -> type = V_13 ;
V_2 -> V_267 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_268 = 0 ;
V_2 -> V_269 = F_105 ;
if ( V_255 ) {
if ( ! F_114 ( V_8 ) )
goto V_270;
V_8 -> V_271 = V_272 ;
V_19 -> V_273 [ V_1 ] = V_8 ;
}
if ( V_2 -> type != V_11 && V_254 ) {
if ( ! F_118 ( V_8 ) )
goto V_270;
}
return;
V_270:
F_122 ( V_4 ) ;
F_117 ( V_8 ) ;
}
