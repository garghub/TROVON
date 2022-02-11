enum V_1 F_1 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int type = V_2 -> type ;
if ( type == V_6 || type == V_7 ||
type == V_8 || type == V_9 ) {
struct V_10 * V_11 =
F_2 ( V_4 ) ;
return V_11 -> V_1 ;
} else if ( type == V_12 ) {
return V_13 ;
} else {
F_3 ( L_1 , type ) ;
F_4 () ;
}
}
static void F_5 ( struct V_14 * V_15 , enum V_1 V_1 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
T_1 V_19 ;
int V_20 ;
int V_21 = V_17 -> V_22 . V_23 [ V_1 ] . V_24 ;
const T_1 * V_25 ;
const T_1 * V_26 ;
const T_1 * V_27 ;
const T_1 * V_28 ;
if ( F_6 ( V_15 ) ) {
V_25 = V_29 ;
V_26 = V_30 ;
V_27 = V_31 ;
} else if ( F_7 ( V_15 ) ) {
V_25 = V_32 ;
V_26 = V_33 ;
V_27 = V_33 ;
} else {
F_8 ( 1 , L_2 ) ;
V_27 = V_30 ;
V_25 = V_29 ;
V_26 = V_30 ;
}
switch ( V_1 ) {
case V_34 :
V_28 = V_27 ;
break;
case V_35 :
case V_36 :
V_28 = V_26 ;
break;
case V_37 :
if ( F_9 ( V_15 , V_37 ) )
V_28 = V_27 ;
else
V_28 = V_26 ;
break;
case V_13 :
V_28 = V_25 ;
break;
default:
F_4 () ;
}
for ( V_20 = 0 , V_19 = F_10 ( V_1 ) ;
V_20 < F_11 ( V_32 ) ; V_20 ++ ) {
F_12 ( V_19 , V_28 [ V_20 ] ) ;
V_19 += 4 ;
}
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
F_12 ( V_19 , V_38 [ V_21 * 2 + V_20 ] ) ;
V_19 += 4 ;
}
}
void F_13 ( struct V_14 * V_15 )
{
int V_1 ;
if ( ! F_14 ( V_15 ) )
return;
for ( V_1 = V_34 ; V_1 <= V_13 ; V_1 ++ )
F_5 ( V_15 , V_1 ) ;
}
static void F_15 ( struct V_16 * V_17 ,
enum V_1 V_1 )
{
T_2 V_19 = F_16 ( V_1 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
F_17 ( 1 ) ;
if ( F_18 ( V_19 ) & V_39 )
return;
}
F_3 ( L_3 , F_19 ( V_1 ) ) ;
}
void F_20 ( struct V_40 * V_41 )
{
struct V_14 * V_15 = V_41 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
T_1 V_43 , V_20 , V_44 ;
F_12 ( V_45 , F_22 ( 2 ) |
F_23 ( 2 ) |
V_46 | V_47 ) ;
V_44 = V_17 -> V_48 | V_49 |
V_50 |
F_24 ( V_42 -> V_51 . V_52 ) ;
F_12 ( V_53 , V_44 ) ;
F_25 ( V_53 ) ;
F_17 ( 220 ) ;
V_44 |= V_54 ;
F_12 ( V_53 , V_44 ) ;
F_12 ( F_26 ( V_13 ) , V_42 -> V_55 ) ;
for ( V_20 = 0 ; V_20 < F_11 ( V_56 ) * 2 ; V_20 ++ ) {
F_12 ( F_27 ( V_13 ) ,
V_57 |
V_58 |
V_59 |
V_60 ) ;
F_12 ( F_16 ( V_13 ) ,
V_61 |
( ( V_42 -> V_51 . V_52 - 1 ) << 1 ) |
V_56 [ V_20 / 2 ] ) ;
F_25 ( F_16 ( V_13 ) ) ;
F_17 ( 600 ) ;
F_12 ( V_62 , F_28 ( 64 ) ) ;
V_44 |= V_63 | V_64 ;
F_12 ( V_53 , V_44 ) ;
F_25 ( V_53 ) ;
F_17 ( 30 ) ;
V_43 = F_18 ( V_45 ) ;
V_43 &= ~ ( V_65 | V_66 ) ;
F_12 ( V_45 , V_43 ) ;
F_25 ( V_45 ) ;
F_17 ( 5 ) ;
V_43 = F_18 ( F_29 ( V_13 ) ) ;
if ( V_43 & V_67 ) {
F_30 ( L_4 , V_20 ) ;
F_12 ( F_27 ( V_13 ) ,
V_57 |
V_68 |
V_58 |
V_60 ) ;
return;
}
V_43 = F_18 ( F_16 ( V_13 ) ) ;
V_43 &= ~ V_61 ;
F_12 ( F_16 ( V_13 ) , V_43 ) ;
F_25 ( F_16 ( V_13 ) ) ;
V_43 = F_18 ( F_27 ( V_13 ) ) ;
V_43 &= ~ ( V_60 | V_69 ) ;
V_43 |= V_59 ;
F_12 ( F_27 ( V_13 ) , V_43 ) ;
F_25 ( F_27 ( V_13 ) ) ;
F_15 ( V_17 , V_13 ) ;
V_44 &= ~ V_63 ;
F_12 ( V_53 , V_44 ) ;
F_25 ( V_53 ) ;
V_43 = F_18 ( V_45 ) ;
V_43 &= ~ ( V_65 | V_66 ) ;
V_43 |= F_22 ( 2 ) | F_23 ( 2 ) ;
F_12 ( V_45 , V_43 ) ;
F_25 ( V_45 ) ;
}
F_3 ( L_5 ) ;
}
static struct V_2 *
F_31 ( struct V_40 * V_41 )
{
struct V_14 * V_15 = V_41 -> V_15 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
struct V_2 * V_2 , * V_70 = NULL ;
int V_71 = 0 ;
F_32 (dev, crtc, intel_encoder) {
V_70 = V_2 ;
V_71 ++ ;
}
if ( V_71 != 1 )
F_8 ( 1 , L_6 , V_71 ,
F_33 ( V_42 -> V_72 ) ) ;
F_34 ( V_70 == NULL ) ;
return V_70 ;
}
void F_35 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_73 * V_74 = & V_17 -> V_75 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
T_2 V_76 ;
switch ( V_42 -> V_55 ) {
case V_77 :
V_74 -> V_78 -- ;
if ( V_74 -> V_78 == 0 ) {
F_30 ( L_7 ) ;
V_76 = F_18 ( V_79 ) ;
F_36 ( ! ( V_76 & V_80 ) ) ;
F_12 ( V_79 , V_76 & ~ V_80 ) ;
F_25 ( V_79 ) ;
}
break;
case V_81 :
V_74 -> V_82 -- ;
if ( V_74 -> V_82 == 0 ) {
F_30 ( L_8 ) ;
V_76 = F_18 ( V_83 ) ;
F_36 ( ! ( V_76 & V_84 ) ) ;
F_12 ( V_83 , V_76 & ~ V_84 ) ;
F_25 ( V_83 ) ;
}
break;
case V_85 :
V_74 -> V_86 -- ;
if ( V_74 -> V_86 == 0 ) {
F_30 ( L_9 ) ;
V_76 = F_18 ( V_87 ) ;
F_36 ( ! ( V_76 & V_84 ) ) ;
F_12 ( V_87 , V_76 & ~ V_84 ) ;
F_25 ( V_87 ) ;
}
break;
}
F_8 ( V_74 -> V_78 < 0 , L_10 ) ;
F_8 ( V_74 -> V_82 < 0 , L_11 ) ;
F_8 ( V_74 -> V_86 < 0 , L_12 ) ;
V_42 -> V_55 = V_88 ;
}
static unsigned F_37 ( int clock )
{
unsigned V_89 ;
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
V_89 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_89 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_89 = 2000 ;
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
V_89 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_89 = 5000 ;
break;
default:
V_89 = 1000 ;
break;
}
return V_89 ;
}
static void F_38 ( T_3 V_90 , unsigned V_89 ,
unsigned V_91 , unsigned V_92 , unsigned V_93 ,
struct V_94 * V_95 )
{
T_3 V_96 , V_97 , V_98 , V_99 , V_100 , V_101 ;
if ( V_95 -> V_93 == 0 ) {
V_95 -> V_93 = V_93 ;
V_95 -> V_92 = V_92 ;
V_95 -> V_91 = V_91 ;
return;
}
V_96 = V_90 * V_89 * V_93 * V_91 ;
V_97 = V_90 * V_89 * V_95 -> V_93 * V_95 -> V_91 ;
V_100 = F_39 ( ( V_90 * V_93 * V_91 ) , ( V_102 * V_92 ) ) ;
V_101 = F_39 ( ( V_90 * V_95 -> V_93 * V_95 -> V_91 ) ,
( V_102 * V_95 -> V_92 ) ) ;
V_98 = 1000000 * V_100 ;
V_99 = 1000000 * V_101 ;
if ( V_96 < V_98 && V_97 < V_99 ) {
if ( V_95 -> V_93 * V_95 -> V_91 * V_100 < V_93 * V_91 * V_101 ) {
V_95 -> V_93 = V_93 ;
V_95 -> V_92 = V_92 ;
V_95 -> V_91 = V_91 ;
}
} else if ( V_96 >= V_98 && V_97 < V_99 ) {
V_95 -> V_93 = V_93 ;
V_95 -> V_92 = V_92 ;
V_95 -> V_91 = V_91 ;
} else if ( V_96 >= V_98 && V_97 >= V_99 ) {
if ( V_92 * V_95 -> V_91 * V_95 -> V_91 > V_95 -> V_92 * V_91 * V_91 ) {
V_95 -> V_93 = V_93 ;
V_95 -> V_92 = V_92 ;
V_95 -> V_91 = V_91 ;
}
}
}
static int F_40 ( struct V_16 * V_17 ,
int V_19 )
{
int V_103 = V_104 ;
int V_105 , V_93 , V_106 ;
T_1 V_107 ;
V_107 = F_18 ( V_19 ) ;
switch ( V_107 & V_108 ) {
case V_109 :
case V_110 :
V_103 = 135 ;
break;
case V_111 :
V_103 = V_104 ;
break;
default:
F_8 ( 1 , L_13 ) ;
return 0 ;
}
V_106 = V_107 & V_112 ;
V_93 = ( V_107 & V_113 ) >> V_114 ;
V_105 = ( V_107 & V_115 ) >> V_116 ;
return ( V_103 * V_105 * 100 ) / ( V_93 * V_106 ) ;
}
static void F_41 ( struct V_2 * V_4 ,
struct V_117 * V_118 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
int V_119 = 0 ;
T_1 V_76 , V_120 ;
V_76 = F_18 ( F_26 ( V_1 ) ) ;
switch ( V_76 & V_121 ) {
case V_122 :
V_119 = 81000 ;
break;
case V_123 :
V_119 = 135000 ;
break;
case V_124 :
V_119 = 270000 ;
break;
case V_81 :
V_119 = F_40 ( V_17 , V_83 ) ;
break;
case V_85 :
V_119 = F_40 ( V_17 , V_87 ) ;
break;
case V_77 :
V_120 = F_18 ( V_79 ) & V_125 ;
if ( V_120 == V_126 )
V_119 = 81000 ;
else if ( V_120 == V_127 )
V_119 = 135000 ;
else if ( V_120 == V_128 )
V_119 = 270000 ;
else {
F_8 ( 1 , L_14 ) ;
return;
}
break;
default:
F_8 ( 1 , L_15 ) ;
return;
}
V_118 -> V_129 = V_119 * 2 ;
if ( V_118 -> V_130 )
V_118 -> V_131 . V_132 =
F_42 ( V_118 -> V_129 ,
& V_118 -> V_133 ) ;
else if ( V_118 -> V_134 )
V_118 -> V_131 . V_132 =
F_42 ( V_118 -> V_129 ,
& V_118 -> V_135 ) ;
else
V_118 -> V_131 . V_132 = V_118 -> V_129 ;
}
static void
F_43 ( int clock ,
unsigned * V_136 , unsigned * V_137 , unsigned * V_138 )
{
T_3 V_90 ;
unsigned V_93 , V_92 , V_91 ;
struct V_94 V_95 = { 0 , 0 , 0 } ;
unsigned V_89 ;
V_90 = clock / 100 ;
V_89 = F_37 ( clock ) ;
if ( V_90 == 5400000 ) {
* V_137 = 2 ;
* V_138 = 1 ;
* V_136 = 2 ;
return;
}
for ( V_91 = V_104 * 2 / V_139 + 1 ;
V_91 <= V_104 * 2 / V_140 ;
V_91 ++ ) {
for ( V_92 = V_141 * V_91 / V_104 + 1 ;
V_92 <= V_142 * V_91 / V_104 ;
V_92 ++ ) {
for ( V_93 = V_143 ; V_93 <= V_144 ; V_93 += V_145 )
F_38 ( V_90 , V_89 ,
V_91 , V_92 , V_93 , & V_95 ) ;
}
}
* V_137 = V_95 . V_92 ;
* V_138 = V_95 . V_93 ;
* V_136 = V_95 . V_91 ;
}
bool F_44 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = & V_42 -> V_5 ;
struct V_2 * V_2 = F_31 ( V_41 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_73 * V_74 = & V_17 -> V_75 ;
int type = V_2 -> type ;
enum V_72 V_72 = V_42 -> V_72 ;
int clock = V_42 -> V_51 . V_129 ;
F_35 ( V_41 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_146 * V_146 = F_45 ( V_4 ) ;
switch ( V_146 -> V_147 ) {
case V_148 :
V_42 -> V_55 = V_122 ;
break;
case V_149 :
V_42 -> V_55 = V_123 ;
break;
case V_150 :
V_42 -> V_55 = V_124 ;
break;
default:
F_3 ( L_16 ,
V_146 -> V_147 ) ;
return false ;
}
} else if ( type == V_8 ) {
T_2 V_19 , V_76 ;
unsigned V_93 , V_92 , V_91 ;
F_43 ( clock * 1000 , & V_91 , & V_92 , & V_93 ) ;
V_76 = V_84 | V_151 |
F_46 ( V_91 ) | F_47 ( V_92 ) |
F_48 ( V_93 ) ;
if ( V_76 == F_18 ( V_83 ) ) {
F_30 ( L_17 ,
F_33 ( V_72 ) ) ;
V_19 = V_83 ;
} else if ( V_76 == F_18 ( V_87 ) ) {
F_30 ( L_18 ,
F_33 ( V_72 ) ) ;
V_19 = V_87 ;
} else if ( V_74 -> V_82 == 0 ) {
F_30 ( L_19 ,
F_33 ( V_72 ) ) ;
V_19 = V_83 ;
} else if ( V_74 -> V_86 == 0 ) {
F_30 ( L_20 ,
F_33 ( V_72 ) ) ;
V_19 = V_87 ;
} else {
F_3 ( L_21 ) ;
return false ;
}
F_30 ( L_22 ,
clock , V_93 , V_92 , V_91 ) ;
if ( V_19 == V_83 ) {
V_74 -> V_82 ++ ;
V_42 -> V_55 = V_81 ;
} else {
V_74 -> V_86 ++ ;
V_42 -> V_55 = V_85 ;
}
} else if ( type == V_12 ) {
if ( V_74 -> V_78 == 0 ) {
F_30 ( L_23 ,
F_33 ( V_72 ) ) ;
V_74 -> V_78 ++ ;
V_42 -> V_55 = V_77 ;
} else {
F_3 ( L_24 ) ;
return false ;
}
} else {
F_8 ( 1 , L_1 , type ) ;
return false ;
}
return true ;
}
void F_49 ( struct V_42 * V_41 )
{
struct V_14 * V_15 = V_41 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_73 * V_74 = & V_17 -> V_75 ;
int clock = V_41 -> V_51 . V_129 ;
T_2 V_19 , V_152 , V_153 ;
int V_154 ;
const char * V_155 ;
T_2 V_156 = ( 1 << 31 ) ;
unsigned int V_93 , V_92 , V_91 ;
F_50 ( V_156 != V_80 ) ;
F_50 ( V_156 != V_84 ) ;
switch ( V_41 -> V_55 ) {
case V_124 :
case V_123 :
case V_122 :
return;
case V_77 :
V_155 = L_25 ;
V_19 = V_79 ;
V_154 = V_74 -> V_78 ;
V_153 = V_80 | V_127 |
V_109 ;
break;
case V_81 :
case V_85 :
if ( V_41 -> V_55 == V_81 ) {
V_155 = L_26 ;
V_19 = V_83 ;
V_154 = V_74 -> V_82 ;
} else {
V_155 = L_27 ;
V_19 = V_87 ;
V_154 = V_74 -> V_86 ;
}
F_43 ( clock * 1000 , & V_91 , & V_92 , & V_93 ) ;
V_153 = V_84 | V_151 |
F_46 ( V_91 ) |
F_47 ( V_92 ) | F_48 ( V_93 ) ;
break;
case V_88 :
F_8 ( 1 , L_28 ) ;
return;
default:
F_8 ( 1 , L_29 , V_41 -> V_55 ) ;
return;
}
V_152 = F_18 ( V_19 ) ;
F_8 ( V_154 < 1 , L_30 , V_155 , V_154 ) ;
if ( V_154 == 1 ) {
F_8 ( V_152 & V_156 , L_31 , V_155 ) ;
F_12 ( V_19 , V_153 ) ;
F_25 ( V_19 ) ;
F_17 ( 20 ) ;
} else {
F_8 ( ( V_152 & V_156 ) == 0 , L_32 , V_155 ) ;
}
}
void F_51 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
struct V_2 * V_2 = F_31 ( V_41 ) ;
enum V_157 V_158 = V_42 -> V_51 . V_158 ;
int type = V_2 -> type ;
T_2 V_43 ;
if ( type == V_6 || type == V_7 ) {
V_43 = V_159 ;
switch ( V_42 -> V_51 . V_160 ) {
case 18 :
V_43 |= V_161 ;
break;
case 24 :
V_43 |= V_162 ;
break;
case 30 :
V_43 |= V_163 ;
break;
case 36 :
V_43 |= V_164 ;
break;
default:
F_4 () ;
}
F_12 ( F_52 ( V_158 ) , V_43 ) ;
}
}
void F_53 ( struct V_40 * V_41 )
{
struct V_42 * V_42 = F_21 ( V_41 ) ;
struct V_2 * V_2 = F_31 ( V_41 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_14 * V_15 = V_41 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_72 V_72 = V_42 -> V_72 ;
enum V_157 V_158 = V_42 -> V_51 . V_158 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_43 ;
V_43 = V_165 ;
V_43 |= F_54 ( V_1 ) ;
switch ( V_42 -> V_51 . V_160 ) {
case 18 :
V_43 |= V_166 ;
break;
case 24 :
V_43 |= V_167 ;
break;
case 30 :
V_43 |= V_168 ;
break;
case 36 :
V_43 |= V_169 ;
break;
default:
F_4 () ;
}
if ( V_42 -> V_51 . V_131 . V_170 & V_171 )
V_43 |= V_172 ;
if ( V_42 -> V_51 . V_131 . V_170 & V_173 )
V_43 |= V_174 ;
if ( V_158 == V_175 ) {
switch ( V_72 ) {
case V_176 :
if ( F_7 ( V_15 ) && V_42 -> V_51 . V_177 . V_178 )
V_43 |= V_179 ;
else
V_43 |= V_180 ;
break;
case V_181 :
V_43 |= V_182 ;
break;
case V_183 :
V_43 |= V_184 ;
break;
default:
F_4 () ;
break;
}
}
if ( type == V_8 ) {
if ( V_42 -> V_51 . V_185 )
V_43 |= V_186 ;
else
V_43 |= V_187 ;
} else if ( type == V_12 ) {
V_43 |= V_188 ;
V_43 |= ( V_42 -> V_51 . V_52 - 1 ) << 1 ;
} else if ( type == V_6 ||
type == V_7 ) {
struct V_146 * V_146 = F_45 ( V_4 ) ;
V_43 |= V_189 ;
V_43 |= F_55 ( V_146 -> V_190 ) ;
} else {
F_8 ( 1 , L_33 ,
V_2 -> type , F_33 ( V_72 ) ) ;
}
F_12 ( F_56 ( V_158 ) , V_43 ) ;
}
void F_57 ( struct V_16 * V_17 ,
enum V_157 V_158 )
{
T_2 V_19 = F_56 ( V_158 ) ;
T_2 V_76 = F_18 ( V_19 ) ;
V_76 &= ~ ( V_165 | V_191 ) ;
V_76 |= V_192 ;
F_12 ( V_19 , V_76 ) ;
}
bool F_58 ( struct V_193 * V_193 )
{
struct V_14 * V_15 = V_193 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_2 * V_2 = V_193 -> V_4 ;
int type = V_193 -> V_5 . V_194 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_72 V_72 = 0 ;
enum V_157 V_158 ;
enum V_195 V_196 ;
T_2 V_197 ;
V_196 = F_59 ( V_2 ) ;
if ( ! F_60 ( V_17 , V_196 ) )
return false ;
if ( ! V_2 -> V_198 ( V_2 , & V_72 ) )
return false ;
if ( V_1 == V_34 )
V_158 = V_175 ;
else
V_158 = (enum V_157 ) V_72 ;
V_197 = F_18 ( F_56 ( V_158 ) ) ;
switch ( V_197 & V_199 ) {
case V_186 :
case V_187 :
return ( type == V_200 ) ;
case V_189 :
if ( type == V_201 )
return true ;
case V_202 :
return ( type == V_203 ) ;
case V_188 :
return ( type == V_204 ) ;
default:
return false ;
}
}
bool F_61 ( struct V_2 * V_4 ,
enum V_72 * V_72 )
{
struct V_14 * V_15 = V_4 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
enum V_195 V_196 ;
T_1 V_197 ;
int V_20 ;
V_196 = F_59 ( V_4 ) ;
if ( ! F_60 ( V_17 , V_196 ) )
return false ;
V_197 = F_18 ( F_16 ( V_1 ) ) ;
if ( ! ( V_197 & V_61 ) )
return false ;
if ( V_1 == V_34 ) {
V_197 = F_18 ( F_56 ( V_175 ) ) ;
switch ( V_197 & V_205 ) {
case V_180 :
case V_179 :
* V_72 = V_176 ;
break;
case V_182 :
* V_72 = V_181 ;
break;
case V_184 :
* V_72 = V_183 ;
break;
}
return true ;
} else {
for ( V_20 = V_206 ; V_20 <= V_207 ; V_20 ++ ) {
V_197 = F_18 ( F_56 ( V_20 ) ) ;
if ( ( V_197 & V_191 )
== F_54 ( V_1 ) ) {
* V_72 = V_20 ;
return true ;
}
}
}
F_30 ( L_34 , F_19 ( V_1 ) ) ;
return false ;
}
static T_2 F_62 ( struct V_16 * V_17 ,
enum V_72 V_72 )
{
T_2 V_43 , V_70 ;
enum V_1 V_1 = V_208 ;
enum V_157 V_158 = F_63 ( V_17 ,
V_72 ) ;
int V_20 ;
if ( V_158 == V_175 ) {
V_1 = V_34 ;
} else {
V_43 = F_18 ( F_56 ( V_158 ) ) ;
V_43 &= V_191 ;
for ( V_20 = V_35 ; V_20 <= V_13 ; V_20 ++ )
if ( V_43 == F_54 ( V_20 ) )
V_1 = V_20 ;
}
if ( V_1 == V_208 ) {
F_8 ( 1 , L_35 ,
F_33 ( V_72 ) ) ;
V_70 = V_88 ;
} else {
V_70 = F_18 ( F_26 ( V_1 ) ) ;
F_30 ( L_36
L_37 , F_33 ( V_72 ) , F_19 ( V_1 ) ,
V_70 ) ;
}
return V_70 ;
}
void F_64 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_72 V_72 ;
struct V_42 * V_42 ;
V_17 -> V_75 . V_78 = 0 ;
V_17 -> V_75 . V_82 = 0 ;
V_17 -> V_75 . V_86 = 0 ;
F_65 (pipe) {
V_42 =
F_21 ( V_17 -> V_209 [ V_72 ] ) ;
if ( ! V_42 -> V_210 ) {
V_42 -> V_55 = V_88 ;
continue;
}
V_42 -> V_55 = F_62 ( V_17 ,
V_72 ) ;
switch ( V_42 -> V_55 ) {
case V_77 :
V_17 -> V_75 . V_78 ++ ;
break;
case V_81 :
V_17 -> V_75 . V_82 ++ ;
break;
case V_85 :
V_17 -> V_75 . V_86 ++ ;
break;
}
}
}
void F_66 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = & V_42 -> V_5 ;
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_2 * V_2 = F_31 ( V_41 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_157 V_158 = V_42 -> V_51 . V_158 ;
if ( V_158 != V_175 )
F_12 ( F_67 ( V_158 ) ,
F_68 ( V_1 ) ) ;
}
void F_69 ( struct V_42 * V_42 )
{
struct V_16 * V_17 = V_42 -> V_5 . V_15 -> V_18 ;
enum V_157 V_158 = V_42 -> V_51 . V_158 ;
if ( V_158 != V_175 )
F_12 ( F_67 ( V_158 ) ,
V_211 ) ;
}
static void F_70 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
struct V_42 * V_41 = F_21 ( V_4 -> V_41 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( V_41 -> V_51 . V_212 ) {
F_71 ( L_38 ,
F_33 ( V_41 -> V_72 ) ) ;
F_71 ( L_39 ) ;
F_72 ( V_4 , & V_41 -> V_51 . V_131 ) ;
}
if ( type == V_7 ) {
struct V_146 * V_146 = F_45 ( V_4 ) ;
F_73 ( V_146 ) ;
}
F_36 ( V_41 -> V_55 == V_88 ) ;
F_12 ( F_26 ( V_1 ) , V_41 -> V_55 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_146 * V_146 = F_45 ( V_4 ) ;
struct V_10 * V_11 =
F_2 ( V_4 ) ;
V_146 -> V_213 = V_11 -> V_214 |
V_61 | V_215 ;
V_146 -> V_213 |= F_55 ( V_146 -> V_190 ) ;
F_74 ( V_146 , V_216 ) ;
F_75 ( V_146 ) ;
F_76 ( V_146 ) ;
if ( V_1 != V_34 )
F_77 ( V_146 ) ;
} else if ( type == V_8 ) {
struct V_217 * V_217 = F_78 ( V_4 ) ;
V_217 -> V_218 ( V_4 ,
V_41 -> V_51 . V_185 ,
& V_41 -> V_51 . V_131 ) ;
}
}
static void F_79 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_76 ;
bool V_219 = false ;
V_76 = F_18 ( F_16 ( V_1 ) ) ;
if ( V_76 & V_61 ) {
V_76 &= ~ V_61 ;
F_12 ( F_16 ( V_1 ) , V_76 ) ;
V_219 = true ;
}
V_76 = F_18 ( F_27 ( V_1 ) ) ;
V_76 &= ~ ( V_60 | V_69 ) ;
V_76 |= V_59 ;
F_12 ( F_27 ( V_1 ) , V_76 ) ;
if ( V_219 )
F_15 ( V_17 , V_1 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_146 * V_146 = F_45 ( V_4 ) ;
F_74 ( V_146 , V_220 ) ;
F_80 ( V_146 ) ;
F_81 ( V_146 ) ;
}
F_12 ( F_26 ( V_1 ) , V_88 ) ;
}
static void F_82 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
int V_72 = V_42 -> V_72 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_197 ;
if ( type == V_8 ) {
struct V_10 * V_11 =
F_2 ( V_4 ) ;
F_12 ( F_16 ( V_1 ) ,
V_11 -> V_214 |
V_61 ) ;
} else if ( type == V_7 ) {
struct V_146 * V_146 = F_45 ( V_4 ) ;
if ( V_1 == V_34 )
F_77 ( V_146 ) ;
F_83 ( V_146 ) ;
F_84 ( V_146 ) ;
}
if ( V_42 -> V_51 . V_212 ) {
F_85 ( V_17 , V_221 ) ;
V_197 = F_18 ( V_222 ) ;
V_197 |= ( ( V_223 | V_224 ) << ( V_72 * 4 ) ) ;
F_12 ( V_222 , V_197 ) ;
}
}
static void F_86 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
int V_72 = V_42 -> V_72 ;
int type = V_2 -> type ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
T_2 V_197 ;
if ( V_42 -> V_51 . V_212 ) {
V_197 = F_18 ( V_222 ) ;
V_197 &= ~ ( ( V_223 | V_224 ) <<
( V_72 * 4 ) ) ;
F_12 ( V_222 , V_197 ) ;
F_87 ( V_17 , V_221 ) ;
}
if ( type == V_7 ) {
struct V_146 * V_146 = F_45 ( V_4 ) ;
F_88 ( V_146 ) ;
F_89 ( V_146 ) ;
}
}
int F_90 ( struct V_16 * V_17 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
T_2 V_225 = F_18 ( V_226 ) ;
T_2 V_227 = V_225 & V_228 ;
if ( V_225 & V_229 ) {
return 800000 ;
} else if ( F_18 ( V_230 ) & V_231 ) {
return 450000 ;
} else if ( V_227 == V_232 ) {
return 450000 ;
} else if ( F_7 ( V_15 ) ) {
if ( F_91 ( V_15 ) )
return 337500 ;
else
return 540000 ;
} else {
if ( V_227 == V_233 )
return 540000 ;
else if ( V_227 == V_234 )
return 337500 ;
else
return 675000 ;
}
}
void F_92 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
T_2 V_76 = F_18 ( V_226 ) ;
F_30 ( L_40 ,
F_90 ( V_17 ) ) ;
if ( V_76 & V_229 )
F_3 ( L_41 ) ;
if ( V_76 & V_235 )
F_3 ( L_42 ) ;
}
void F_93 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
struct V_146 * V_146 = & V_11 -> V_236 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
enum V_1 V_1 = V_11 -> V_1 ;
T_2 V_76 ;
bool V_219 = false ;
if ( F_18 ( F_27 ( V_1 ) ) & V_60 ) {
V_76 = F_18 ( F_16 ( V_1 ) ) ;
if ( V_76 & V_61 ) {
V_76 &= ~ V_61 ;
F_12 ( F_16 ( V_1 ) , V_76 ) ;
V_219 = true ;
}
V_76 = F_18 ( F_27 ( V_1 ) ) ;
V_76 &= ~ ( V_60 | V_69 ) ;
V_76 |= V_59 ;
F_12 ( F_27 ( V_1 ) , V_76 ) ;
F_25 ( F_27 ( V_1 ) ) ;
if ( V_219 )
F_15 ( V_17 , V_1 ) ;
}
V_76 = V_60 | V_237 |
V_59 | V_238 ;
if ( F_94 ( V_146 -> V_239 ) )
V_76 |= V_58 ;
F_12 ( F_27 ( V_1 ) , V_76 ) ;
F_25 ( F_27 ( V_1 ) ) ;
V_146 -> V_213 |= V_61 ;
F_12 ( F_16 ( V_1 ) , V_146 -> V_213 ) ;
F_25 ( F_16 ( V_1 ) ) ;
F_17 ( 600 ) ;
}
void F_95 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_2 * V_2 = F_31 ( V_41 ) ;
T_2 V_76 ;
F_79 ( V_2 ) ;
V_76 = F_18 ( V_53 ) ;
V_76 &= ~ V_63 ;
F_12 ( V_53 , V_76 ) ;
V_76 = F_18 ( V_45 ) ;
V_76 &= ~ ( V_65 | V_66 ) ;
V_76 |= F_22 ( 2 ) | F_23 ( 2 ) ;
F_12 ( V_45 , V_76 ) ;
V_76 = F_18 ( V_53 ) ;
V_76 &= ~ V_54 ;
F_12 ( V_53 , V_76 ) ;
V_76 = F_18 ( V_53 ) ;
V_76 &= ~ V_50 ;
F_12 ( V_53 , V_76 ) ;
}
static void F_96 ( struct V_2 * V_2 )
{
struct V_146 * V_146 = F_45 ( & V_2 -> V_5 ) ;
int type = V_2 -> type ;
if ( type == V_6 || type == V_7 )
F_97 ( V_146 ) ;
}
void F_98 ( struct V_2 * V_4 ,
struct V_117 * V_118 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_15 -> V_18 ;
struct V_42 * V_42 = F_21 ( V_4 -> V_5 . V_41 ) ;
enum V_157 V_158 = V_42 -> V_51 . V_158 ;
T_1 V_43 , V_170 = 0 ;
V_43 = F_18 ( F_56 ( V_158 ) ) ;
if ( V_43 & V_174 )
V_170 |= V_173 ;
else
V_170 |= V_240 ;
if ( V_43 & V_172 )
V_170 |= V_171 ;
else
V_170 |= V_241 ;
V_118 -> V_131 . V_170 |= V_170 ;
switch ( V_43 & V_242 ) {
case V_166 :
V_118 -> V_160 = 18 ;
break;
case V_167 :
V_118 -> V_160 = 24 ;
break;
case V_168 :
V_118 -> V_160 = 30 ;
break;
case V_169 :
V_118 -> V_160 = 36 ;
break;
default:
break;
}
switch ( V_43 & V_199 ) {
case V_186 :
V_118 -> V_185 = true ;
case V_187 :
case V_188 :
break;
case V_189 :
case V_202 :
V_118 -> V_134 = true ;
F_99 ( V_42 , V_118 ) ;
break;
default:
break;
}
if ( F_60 ( V_17 , V_221 ) ) {
V_43 = F_18 ( V_222 ) ;
if ( V_43 & ( V_223 << ( V_42 -> V_72 * 4 ) ) )
V_118 -> V_212 = true ;
}
if ( V_4 -> type == V_7 && V_17 -> V_22 . V_243 &&
V_118 -> V_160 > V_17 -> V_22 . V_243 ) {
F_30 ( L_43 ,
V_118 -> V_160 , V_17 -> V_22 . V_243 ) ;
V_17 -> V_22 . V_243 = V_118 -> V_160 ;
}
F_41 ( V_4 , V_118 ) ;
}
static void F_100 ( struct V_3 * V_4 )
{
F_101 ( V_4 ) ;
}
static bool F_102 ( struct V_2 * V_4 ,
struct V_117 * V_118 )
{
int type = V_4 -> type ;
int V_1 = F_1 ( V_4 ) ;
F_8 ( type == V_9 , L_44 ) ;
if ( V_1 == V_34 )
V_118 -> V_158 = V_175 ;
if ( type == V_8 )
return F_103 ( V_4 , V_118 ) ;
else
return F_104 ( V_4 , V_118 ) ;
}
static struct V_193 *
F_105 ( struct V_10 * V_11 )
{
struct V_193 * V_244 ;
enum V_1 V_1 = V_11 -> V_1 ;
V_244 = F_106 ( sizeof( * V_244 ) , V_245 ) ;
if ( ! V_244 )
return NULL ;
V_11 -> V_236 . V_246 = F_16 ( V_1 ) ;
if ( ! F_107 ( V_11 , V_244 ) ) {
F_108 ( V_244 ) ;
return NULL ;
}
return V_244 ;
}
static struct V_193 *
F_109 ( struct V_10 * V_11 )
{
struct V_193 * V_244 ;
enum V_1 V_1 = V_11 -> V_1 ;
V_244 = F_106 ( sizeof( * V_244 ) , V_245 ) ;
if ( ! V_244 )
return NULL ;
V_11 -> V_247 . V_248 = F_16 ( V_1 ) ;
F_110 ( V_11 , V_244 ) ;
return V_244 ;
}
void F_111 ( struct V_14 * V_15 , enum V_1 V_1 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_10 * V_11 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
struct V_193 * V_249 = NULL ;
struct V_193 * V_250 = NULL ;
bool V_251 , V_252 ;
V_251 = ( V_17 -> V_22 . V_23 [ V_1 ] . V_253 ||
V_17 -> V_22 . V_23 [ V_1 ] . V_254 ) ;
V_252 = V_17 -> V_22 . V_23 [ V_1 ] . V_255 ;
if ( ! V_252 && ! V_251 ) {
F_30 ( L_45 ,
F_19 ( V_1 ) ) ;
V_251 = true ;
V_252 = true ;
}
V_11 = F_106 ( sizeof( * V_11 ) , V_245 ) ;
if ( ! V_11 )
return;
V_2 = & V_11 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_112 ( V_15 , V_4 , & V_256 ,
V_257 ) ;
V_2 -> V_258 = F_102 ;
V_2 -> V_259 = F_82 ;
V_2 -> V_260 = F_70 ;
V_2 -> V_261 = F_86 ;
V_2 -> V_262 = F_79 ;
V_2 -> V_198 = F_61 ;
V_2 -> V_263 = F_98 ;
V_11 -> V_1 = V_1 ;
V_11 -> V_214 = F_18 ( F_16 ( V_1 ) ) &
( V_264 |
V_265 ) ;
V_2 -> type = V_9 ;
V_2 -> V_266 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_267 = 0 ;
V_2 -> V_268 = F_96 ;
if ( V_252 )
V_250 = F_105 ( V_11 ) ;
if ( V_2 -> type != V_7 && V_251 )
V_249 = F_109 ( V_11 ) ;
if ( ! V_250 && ! V_249 ) {
F_113 ( V_4 ) ;
F_108 ( V_11 ) ;
}
}
