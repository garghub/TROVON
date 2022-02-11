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
static void F_31 ( struct V_2 * V_4 )
{
struct V_42 * V_41 = F_21 ( V_4 -> V_5 . V_41 ) ;
int V_1 = F_1 ( V_4 ) ;
int V_70 = V_41 -> V_70 ;
int type = V_4 -> type ;
struct V_71 * V_72 = & V_41 -> V_51 . V_72 ;
F_30 ( L_6 ,
F_19 ( V_1 ) , F_32 ( V_70 ) ) ;
V_41 -> V_73 = false ;
if ( type == V_6 || type == V_7 ) {
struct V_74 * V_74 = F_33 ( & V_4 -> V_5 ) ;
struct V_10 * V_11 =
F_2 ( & V_4 -> V_5 ) ;
V_74 -> V_75 = V_11 -> V_76 |
V_61 | V_77 ;
V_74 -> V_75 |= F_34 ( V_74 -> V_78 ) ;
if ( V_74 -> V_79 ) {
F_35 ( L_7 ,
F_32 ( V_41 -> V_70 ) ) ;
F_35 ( L_8 ) ;
F_36 ( & V_4 -> V_5 , V_72 ) ;
}
} else if ( type == V_8 ) {
struct V_80 * V_80 = F_37 ( & V_4 -> V_5 ) ;
if ( V_80 -> V_79 ) {
F_35 ( L_9 ,
F_32 ( V_41 -> V_70 ) ) ;
F_35 ( L_10 ) ;
F_36 ( & V_4 -> V_5 , V_72 ) ;
}
V_80 -> V_81 ( & V_4 -> V_5 , V_72 ) ;
}
}
static struct V_2 *
F_38 ( struct V_40 * V_41 )
{
struct V_14 * V_15 = V_41 -> V_15 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
struct V_2 * V_2 , * V_82 = NULL ;
int V_83 = 0 ;
F_39 (dev, crtc, intel_encoder) {
V_82 = V_2 ;
V_83 ++ ;
}
if ( V_83 != 1 )
F_8 ( 1 , L_11 , V_83 ,
F_32 ( V_42 -> V_70 ) ) ;
F_40 ( V_82 == NULL ) ;
return V_82 ;
}
void F_41 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_84 * V_85 = & V_17 -> V_86 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
T_2 V_87 ;
switch ( V_42 -> V_55 ) {
case V_88 :
V_85 -> V_89 -- ;
if ( V_85 -> V_89 == 0 ) {
F_30 ( L_12 ) ;
V_87 = F_18 ( V_90 ) ;
F_42 ( ! ( V_87 & V_91 ) ) ;
F_12 ( V_90 , V_87 & ~ V_91 ) ;
F_25 ( V_90 ) ;
}
break;
case V_92 :
V_85 -> V_93 -- ;
if ( V_85 -> V_93 == 0 ) {
F_30 ( L_13 ) ;
V_87 = F_18 ( V_94 ) ;
F_42 ( ! ( V_87 & V_95 ) ) ;
F_12 ( V_94 , V_87 & ~ V_95 ) ;
F_25 ( V_94 ) ;
}
break;
case V_96 :
V_85 -> V_97 -- ;
if ( V_85 -> V_97 == 0 ) {
F_30 ( L_14 ) ;
V_87 = F_18 ( V_98 ) ;
F_42 ( ! ( V_87 & V_95 ) ) ;
F_12 ( V_98 , V_87 & ~ V_95 ) ;
F_25 ( V_98 ) ;
}
break;
}
F_8 ( V_85 -> V_89 < 0 , L_15 ) ;
F_8 ( V_85 -> V_93 < 0 , L_16 ) ;
F_8 ( V_85 -> V_97 < 0 , L_17 ) ;
V_42 -> V_55 = V_99 ;
}
static unsigned F_43 ( int clock )
{
unsigned V_100 ;
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
V_100 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_100 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_100 = 2000 ;
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
V_100 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_100 = 5000 ;
break;
default:
V_100 = 1000 ;
break;
}
return V_100 ;
}
static void F_44 ( T_3 V_101 , unsigned V_100 ,
unsigned V_102 , unsigned V_103 , unsigned V_104 ,
struct V_105 * V_106 )
{
T_3 V_107 , V_108 , V_109 , V_110 , V_111 , V_112 ;
if ( V_106 -> V_104 == 0 ) {
V_106 -> V_104 = V_104 ;
V_106 -> V_103 = V_103 ;
V_106 -> V_102 = V_102 ;
return;
}
V_107 = V_101 * V_100 * V_104 * V_102 ;
V_108 = V_101 * V_100 * V_106 -> V_104 * V_106 -> V_102 ;
V_111 = F_45 ( ( V_101 * V_104 * V_102 ) , ( V_113 * V_103 ) ) ;
V_112 = F_45 ( ( V_101 * V_106 -> V_104 * V_106 -> V_102 ) ,
( V_113 * V_106 -> V_103 ) ) ;
V_109 = 1000000 * V_111 ;
V_110 = 1000000 * V_112 ;
if ( V_107 < V_109 && V_108 < V_110 ) {
if ( V_106 -> V_104 * V_106 -> V_102 * V_111 < V_104 * V_102 * V_112 ) {
V_106 -> V_104 = V_104 ;
V_106 -> V_103 = V_103 ;
V_106 -> V_102 = V_102 ;
}
} else if ( V_107 >= V_109 && V_108 < V_110 ) {
V_106 -> V_104 = V_104 ;
V_106 -> V_103 = V_103 ;
V_106 -> V_102 = V_102 ;
} else if ( V_107 >= V_109 && V_108 >= V_110 ) {
if ( V_103 * V_106 -> V_102 * V_106 -> V_102 > V_106 -> V_103 * V_102 * V_102 ) {
V_106 -> V_104 = V_104 ;
V_106 -> V_103 = V_103 ;
V_106 -> V_102 = V_102 ;
}
}
}
static int F_46 ( struct V_16 * V_17 ,
int V_19 )
{
int V_114 = V_115 ;
int V_116 , V_104 , V_117 ;
T_1 V_118 ;
V_118 = F_18 ( V_19 ) ;
switch ( V_118 & V_119 ) {
case V_120 :
case V_121 :
V_114 = 135 ;
break;
case V_122 :
V_114 = V_115 ;
break;
default:
F_8 ( 1 , L_18 ) ;
return 0 ;
}
V_117 = V_118 & V_123 ;
V_104 = ( V_118 & V_124 ) >> V_125 ;
V_116 = ( V_118 & V_126 ) >> V_127 ;
return ( V_114 * V_116 * 100 ) / ( V_104 * V_117 ) ;
}
static void F_47 ( struct V_2 * V_4 ,
struct V_128 * V_129 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
int V_130 = 0 ;
T_1 V_87 , V_131 ;
V_87 = F_18 ( F_26 ( V_1 ) ) ;
switch ( V_87 & V_132 ) {
case V_133 :
V_130 = 81000 ;
break;
case V_134 :
V_130 = 135000 ;
break;
case V_135 :
V_130 = 270000 ;
break;
case V_92 :
V_130 = F_46 ( V_17 , V_94 ) ;
break;
case V_96 :
V_130 = F_46 ( V_17 , V_98 ) ;
break;
case V_88 :
V_131 = F_18 ( V_90 ) & V_136 ;
if ( V_131 == V_137 )
V_130 = 81000 ;
else if ( V_131 == V_138 )
V_130 = 135000 ;
else if ( V_131 == V_139 )
V_130 = 270000 ;
else {
F_8 ( 1 , L_19 ) ;
return;
}
break;
default:
F_8 ( 1 , L_20 ) ;
return;
}
V_129 -> V_140 = V_130 * 2 ;
if ( V_129 -> V_141 )
V_129 -> V_72 . V_142 =
F_48 ( V_129 -> V_140 ,
& V_129 -> V_143 ) ;
else if ( V_129 -> V_144 )
V_129 -> V_72 . V_142 =
F_48 ( V_129 -> V_140 ,
& V_129 -> V_145 ) ;
else
V_129 -> V_72 . V_142 = V_129 -> V_140 ;
}
static void
F_49 ( int clock ,
unsigned * V_146 , unsigned * V_147 , unsigned * V_148 )
{
T_3 V_101 ;
unsigned V_104 , V_103 , V_102 ;
struct V_105 V_106 = { 0 , 0 , 0 } ;
unsigned V_100 ;
V_101 = clock / 100 ;
V_100 = F_43 ( clock ) ;
if ( V_101 == 5400000 ) {
* V_147 = 2 ;
* V_148 = 1 ;
* V_146 = 2 ;
return;
}
for ( V_102 = V_115 * 2 / V_149 + 1 ;
V_102 <= V_115 * 2 / V_150 ;
V_102 ++ ) {
for ( V_103 = V_151 * V_102 / V_115 + 1 ;
V_103 <= V_152 * V_102 / V_115 ;
V_103 ++ ) {
for ( V_104 = V_153 ; V_104 <= V_154 ; V_104 += V_155 )
F_44 ( V_101 , V_100 ,
V_102 , V_103 , V_104 , & V_106 ) ;
}
}
* V_147 = V_106 . V_103 ;
* V_148 = V_106 . V_104 ;
* V_146 = V_106 . V_102 ;
}
bool F_50 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = & V_42 -> V_5 ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_84 * V_85 = & V_17 -> V_86 ;
int type = V_2 -> type ;
enum V_70 V_70 = V_42 -> V_70 ;
int clock = V_42 -> V_51 . V_140 ;
F_41 ( V_41 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
switch ( V_74 -> V_156 ) {
case V_157 :
V_42 -> V_55 = V_133 ;
break;
case V_158 :
V_42 -> V_55 = V_134 ;
break;
case V_159 :
V_42 -> V_55 = V_135 ;
break;
default:
F_3 ( L_21 ,
V_74 -> V_156 ) ;
return false ;
}
} else if ( type == V_8 ) {
T_2 V_19 , V_87 ;
unsigned V_104 , V_103 , V_102 ;
F_49 ( clock * 1000 , & V_102 , & V_103 , & V_104 ) ;
V_87 = V_95 | V_160 |
F_51 ( V_102 ) | F_52 ( V_103 ) |
F_53 ( V_104 ) ;
if ( V_87 == F_18 ( V_94 ) ) {
F_30 ( L_22 ,
F_32 ( V_70 ) ) ;
V_19 = V_94 ;
} else if ( V_87 == F_18 ( V_98 ) ) {
F_30 ( L_23 ,
F_32 ( V_70 ) ) ;
V_19 = V_98 ;
} else if ( V_85 -> V_93 == 0 ) {
F_30 ( L_24 ,
F_32 ( V_70 ) ) ;
V_19 = V_94 ;
} else if ( V_85 -> V_97 == 0 ) {
F_30 ( L_25 ,
F_32 ( V_70 ) ) ;
V_19 = V_98 ;
} else {
F_3 ( L_26 ) ;
return false ;
}
F_30 ( L_27 ,
clock , V_104 , V_103 , V_102 ) ;
if ( V_19 == V_94 ) {
V_85 -> V_93 ++ ;
V_42 -> V_55 = V_92 ;
} else {
V_85 -> V_97 ++ ;
V_42 -> V_55 = V_96 ;
}
} else if ( type == V_12 ) {
if ( V_85 -> V_89 == 0 ) {
F_30 ( L_28 ,
F_32 ( V_70 ) ) ;
V_85 -> V_89 ++ ;
V_42 -> V_55 = V_88 ;
} else {
F_3 ( L_29 ) ;
return false ;
}
} else {
F_8 ( 1 , L_1 , type ) ;
return false ;
}
return true ;
}
void F_54 ( struct V_42 * V_41 )
{
struct V_14 * V_15 = V_41 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_84 * V_85 = & V_17 -> V_86 ;
int clock = V_41 -> V_51 . V_140 ;
T_2 V_19 , V_161 , V_162 ;
int V_163 ;
const char * V_164 ;
T_2 V_165 = ( 1 << 31 ) ;
unsigned int V_104 , V_103 , V_102 ;
F_55 ( V_165 != V_91 ) ;
F_55 ( V_165 != V_95 ) ;
switch ( V_41 -> V_55 ) {
case V_135 :
case V_134 :
case V_133 :
return;
case V_88 :
V_164 = L_30 ;
V_19 = V_90 ;
V_163 = V_85 -> V_89 ;
V_162 = V_91 | V_138 |
V_120 ;
break;
case V_92 :
case V_96 :
if ( V_41 -> V_55 == V_92 ) {
V_164 = L_31 ;
V_19 = V_94 ;
V_163 = V_85 -> V_93 ;
} else {
V_164 = L_32 ;
V_19 = V_98 ;
V_163 = V_85 -> V_97 ;
}
F_49 ( clock * 1000 , & V_102 , & V_103 , & V_104 ) ;
V_162 = V_95 | V_160 |
F_51 ( V_102 ) |
F_52 ( V_103 ) | F_53 ( V_104 ) ;
break;
case V_99 :
F_8 ( 1 , L_33 ) ;
return;
default:
F_8 ( 1 , L_34 , V_41 -> V_55 ) ;
return;
}
V_161 = F_18 ( V_19 ) ;
F_8 ( V_163 < 1 , L_35 , V_164 , V_163 ) ;
if ( V_163 == 1 ) {
F_8 ( V_161 & V_165 , L_36 , V_164 ) ;
F_12 ( V_19 , V_162 ) ;
F_25 ( V_19 ) ;
F_17 ( 20 ) ;
} else {
F_8 ( ( V_161 & V_165 ) == 0 , L_37 , V_164 ) ;
}
}
void F_56 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
enum V_166 V_167 = V_42 -> V_51 . V_167 ;
int type = V_2 -> type ;
T_2 V_43 ;
if ( type == V_6 || type == V_7 ) {
V_43 = V_168 ;
switch ( V_42 -> V_51 . V_169 ) {
case 18 :
V_43 |= V_170 ;
break;
case 24 :
V_43 |= V_171 ;
break;
case 30 :
V_43 |= V_172 ;
break;
case 36 :
V_43 |= V_173 ;
break;
default:
F_4 () ;
}
F_12 ( F_57 ( V_167 ) , V_43 ) ;
}
}
void F_58 ( struct V_40 * V_41 )
{
struct V_42 * V_42 = F_21 ( V_41 ) ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_14 * V_15 = V_41 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_70 V_70 = V_42 -> V_70 ;
enum V_166 V_167 = V_42 -> V_51 . V_167 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_43 ;
V_43 = V_174 ;
V_43 |= F_59 ( V_1 ) ;
switch ( V_42 -> V_51 . V_169 ) {
case 18 :
V_43 |= V_175 ;
break;
case 24 :
V_43 |= V_176 ;
break;
case 30 :
V_43 |= V_177 ;
break;
case 36 :
V_43 |= V_178 ;
break;
default:
F_4 () ;
}
if ( V_42 -> V_51 . V_72 . V_179 & V_180 )
V_43 |= V_181 ;
if ( V_42 -> V_51 . V_72 . V_179 & V_182 )
V_43 |= V_183 ;
if ( V_167 == V_184 ) {
switch ( V_70 ) {
case V_185 :
if ( F_7 ( V_15 ) && V_42 -> V_51 . V_186 . V_187 )
V_43 |= V_188 ;
else
V_43 |= V_189 ;
break;
case V_190 :
V_43 |= V_191 ;
break;
case V_192 :
V_43 |= V_193 ;
break;
default:
F_4 () ;
break;
}
}
if ( type == V_8 ) {
struct V_80 * V_80 = F_37 ( V_4 ) ;
if ( V_80 -> V_194 )
V_43 |= V_195 ;
else
V_43 |= V_196 ;
} else if ( type == V_12 ) {
V_43 |= V_197 ;
V_43 |= ( V_42 -> V_51 . V_52 - 1 ) << 1 ;
} else if ( type == V_6 ||
type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
V_43 |= V_198 ;
V_43 |= F_34 ( V_74 -> V_78 ) ;
} else {
F_8 ( 1 , L_38 ,
V_2 -> type , F_32 ( V_70 ) ) ;
}
F_12 ( F_60 ( V_167 ) , V_43 ) ;
}
void F_61 ( struct V_16 * V_17 ,
enum V_166 V_167 )
{
T_2 V_19 = F_60 ( V_167 ) ;
T_2 V_87 = F_18 ( V_19 ) ;
V_87 &= ~ ( V_174 | V_199 ) ;
V_87 |= V_200 ;
F_12 ( V_19 , V_87 ) ;
}
bool F_62 ( struct V_201 * V_201 )
{
struct V_14 * V_15 = V_201 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_2 * V_2 = V_201 -> V_4 ;
int type = V_201 -> V_5 . V_202 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_70 V_70 = 0 ;
enum V_166 V_167 ;
enum V_203 V_204 ;
T_2 V_205 ;
V_204 = F_63 ( V_2 ) ;
if ( ! F_64 ( V_17 , V_204 ) )
return false ;
if ( ! V_2 -> V_206 ( V_2 , & V_70 ) )
return false ;
if ( V_1 == V_34 )
V_167 = V_184 ;
else
V_167 = (enum V_166 ) V_70 ;
V_205 = F_18 ( F_60 ( V_167 ) ) ;
switch ( V_205 & V_207 ) {
case V_195 :
case V_196 :
return ( type == V_208 ) ;
case V_198 :
if ( type == V_209 )
return true ;
case V_210 :
return ( type == V_211 ) ;
case V_197 :
return ( type == V_212 ) ;
default:
return false ;
}
}
bool F_65 ( struct V_2 * V_4 ,
enum V_70 * V_70 )
{
struct V_14 * V_15 = V_4 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
enum V_203 V_204 ;
T_1 V_205 ;
int V_20 ;
V_204 = F_63 ( V_4 ) ;
if ( ! F_64 ( V_17 , V_204 ) )
return false ;
V_205 = F_18 ( F_16 ( V_1 ) ) ;
if ( ! ( V_205 & V_61 ) )
return false ;
if ( V_1 == V_34 ) {
V_205 = F_18 ( F_60 ( V_184 ) ) ;
switch ( V_205 & V_213 ) {
case V_189 :
case V_188 :
* V_70 = V_185 ;
break;
case V_191 :
* V_70 = V_190 ;
break;
case V_193 :
* V_70 = V_192 ;
break;
}
return true ;
} else {
for ( V_20 = V_214 ; V_20 <= V_215 ; V_20 ++ ) {
V_205 = F_18 ( F_60 ( V_20 ) ) ;
if ( ( V_205 & V_199 )
== F_59 ( V_1 ) ) {
* V_70 = V_20 ;
return true ;
}
}
}
F_30 ( L_39 , F_19 ( V_1 ) ) ;
return false ;
}
static T_2 F_66 ( struct V_16 * V_17 ,
enum V_70 V_70 )
{
T_2 V_43 , V_82 ;
enum V_1 V_1 = V_216 ;
enum V_166 V_167 = F_67 ( V_17 ,
V_70 ) ;
int V_20 ;
if ( V_167 == V_184 ) {
V_1 = V_34 ;
} else {
V_43 = F_18 ( F_60 ( V_167 ) ) ;
V_43 &= V_199 ;
for ( V_20 = V_35 ; V_20 <= V_13 ; V_20 ++ )
if ( V_43 == F_59 ( V_20 ) )
V_1 = V_20 ;
}
if ( V_1 == V_216 ) {
F_8 ( 1 , L_40 ,
F_32 ( V_70 ) ) ;
V_82 = V_99 ;
} else {
V_82 = F_18 ( F_26 ( V_1 ) ) ;
F_30 ( L_41
L_42 , F_32 ( V_70 ) , F_19 ( V_1 ) ,
V_82 ) ;
}
return V_82 ;
}
void F_68 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_70 V_70 ;
struct V_42 * V_42 ;
V_17 -> V_86 . V_89 = 0 ;
V_17 -> V_86 . V_93 = 0 ;
V_17 -> V_86 . V_97 = 0 ;
F_69 (pipe) {
V_42 =
F_21 ( V_17 -> V_217 [ V_70 ] ) ;
if ( ! V_42 -> V_218 ) {
V_42 -> V_55 = V_99 ;
continue;
}
V_42 -> V_55 = F_66 ( V_17 ,
V_70 ) ;
switch ( V_42 -> V_55 ) {
case V_88 :
V_17 -> V_86 . V_89 ++ ;
break;
case V_92 :
V_17 -> V_86 . V_93 ++ ;
break;
case V_96 :
V_17 -> V_86 . V_97 ++ ;
break;
}
}
}
void F_70 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = & V_42 -> V_5 ;
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_166 V_167 = V_42 -> V_51 . V_167 ;
if ( V_167 != V_184 )
F_12 ( F_71 ( V_167 ) ,
F_72 ( V_1 ) ) ;
}
void F_73 ( struct V_42 * V_42 )
{
struct V_16 * V_17 = V_42 -> V_5 . V_15 -> V_18 ;
enum V_166 V_167 = V_42 -> V_51 . V_167 ;
if ( V_167 != V_184 )
F_12 ( F_71 ( V_167 ) ,
V_219 ) ;
}
static void F_74 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
F_75 ( V_74 ) ;
}
F_42 ( V_42 -> V_55 == V_99 ) ;
F_12 ( F_26 ( V_1 ) , V_42 -> V_55 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
F_76 ( V_74 , V_220 ) ;
F_77 ( V_74 ) ;
F_78 ( V_74 ) ;
if ( V_1 != V_34 )
F_79 ( V_74 ) ;
}
}
static void F_80 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_87 ;
bool V_221 = false ;
V_87 = F_18 ( F_16 ( V_1 ) ) ;
if ( V_87 & V_61 ) {
V_87 &= ~ V_61 ;
F_12 ( F_16 ( V_1 ) , V_87 ) ;
V_221 = true ;
}
V_87 = F_18 ( F_27 ( V_1 ) ) ;
V_87 &= ~ ( V_60 | V_69 ) ;
V_87 |= V_59 ;
F_12 ( F_27 ( V_1 ) , V_87 ) ;
if ( V_221 )
F_15 ( V_17 , V_1 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
F_76 ( V_74 , V_222 ) ;
F_81 ( V_74 ) ;
F_82 ( V_74 ) ;
}
F_12 ( F_26 ( V_1 ) , V_99 ) ;
}
static void F_83 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
int V_70 = V_42 -> V_70 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_205 ;
if ( type == V_8 ) {
struct V_10 * V_11 =
F_2 ( V_4 ) ;
F_12 ( F_16 ( V_1 ) ,
V_11 -> V_76 |
V_61 ) ;
} else if ( type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
if ( V_1 == V_34 )
F_79 ( V_74 ) ;
F_84 ( V_74 ) ;
F_85 ( V_74 ) ;
}
if ( V_42 -> V_73 && type != V_7 ) {
V_205 = F_18 ( V_223 ) ;
V_205 |= ( ( V_224 | V_225 ) << ( V_70 * 4 ) ) ;
F_12 ( V_223 , V_205 ) ;
}
}
static void F_86 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
int V_70 = V_42 -> V_70 ;
int type = V_2 -> type ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
T_2 V_205 ;
if ( V_42 -> V_73 && type != V_7 ) {
V_205 = F_18 ( V_223 ) ;
V_205 &= ~ ( ( V_224 | V_225 ) <<
( V_70 * 4 ) ) ;
F_12 ( V_223 , V_205 ) ;
}
if ( type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
F_87 ( V_74 ) ;
F_88 ( V_74 ) ;
}
}
int F_89 ( struct V_16 * V_17 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
T_2 V_226 = F_18 ( V_227 ) ;
T_2 V_228 = V_226 & V_229 ;
if ( V_226 & V_230 ) {
return 800000 ;
} else if ( F_18 ( V_231 ) & V_232 ) {
return 450000 ;
} else if ( V_228 == V_233 ) {
return 450000 ;
} else if ( F_7 ( V_15 ) ) {
if ( F_90 ( V_15 ) )
return 337500 ;
else
return 540000 ;
} else {
if ( V_228 == V_234 )
return 540000 ;
else if ( V_228 == V_235 )
return 337500 ;
else
return 675000 ;
}
}
void F_91 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
T_2 V_87 = F_18 ( V_227 ) ;
F_30 ( L_43 ,
F_89 ( V_17 ) ) ;
if ( V_87 & V_230 )
F_3 ( L_44 ) ;
if ( V_87 & V_236 )
F_3 ( L_45 ) ;
}
void F_92 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
struct V_74 * V_74 = & V_11 -> V_237 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
enum V_1 V_1 = V_11 -> V_1 ;
T_2 V_87 ;
bool V_221 = false ;
if ( F_18 ( F_27 ( V_1 ) ) & V_60 ) {
V_87 = F_18 ( F_16 ( V_1 ) ) ;
if ( V_87 & V_61 ) {
V_87 &= ~ V_61 ;
F_12 ( F_16 ( V_1 ) , V_87 ) ;
V_221 = true ;
}
V_87 = F_18 ( F_27 ( V_1 ) ) ;
V_87 &= ~ ( V_60 | V_69 ) ;
V_87 |= V_59 ;
F_12 ( F_27 ( V_1 ) , V_87 ) ;
F_25 ( F_27 ( V_1 ) ) ;
if ( V_221 )
F_15 ( V_17 , V_1 ) ;
}
V_87 = V_60 | V_238 |
V_59 | V_239 ;
if ( F_93 ( V_74 -> V_240 ) )
V_87 |= V_58 ;
F_12 ( F_27 ( V_1 ) , V_87 ) ;
F_25 ( F_27 ( V_1 ) ) ;
V_74 -> V_75 |= V_61 ;
F_12 ( F_16 ( V_1 ) , V_74 -> V_75 ) ;
F_25 ( F_16 ( V_1 ) ) ;
F_17 ( 600 ) ;
}
void F_94 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
T_2 V_87 ;
F_80 ( V_2 ) ;
V_87 = F_18 ( V_53 ) ;
V_87 &= ~ V_63 ;
F_12 ( V_53 , V_87 ) ;
V_87 = F_18 ( V_45 ) ;
V_87 &= ~ ( V_65 | V_66 ) ;
V_87 |= F_22 ( 2 ) | F_23 ( 2 ) ;
F_12 ( V_45 , V_87 ) ;
V_87 = F_18 ( V_53 ) ;
V_87 &= ~ V_54 ;
F_12 ( V_53 , V_87 ) ;
V_87 = F_18 ( V_53 ) ;
V_87 &= ~ V_50 ;
F_12 ( V_53 , V_87 ) ;
}
static void F_95 ( struct V_2 * V_2 )
{
struct V_74 * V_74 = F_33 ( & V_2 -> V_5 ) ;
int type = V_2 -> type ;
if ( type == V_6 || type == V_7 )
F_96 ( V_74 ) ;
}
void F_97 ( struct V_2 * V_4 ,
struct V_128 * V_129 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_15 -> V_18 ;
struct V_42 * V_42 = F_21 ( V_4 -> V_5 . V_41 ) ;
enum V_166 V_167 = V_42 -> V_51 . V_167 ;
T_1 V_43 , V_179 = 0 ;
V_43 = F_18 ( F_60 ( V_167 ) ) ;
if ( V_43 & V_183 )
V_179 |= V_182 ;
else
V_179 |= V_241 ;
if ( V_43 & V_181 )
V_179 |= V_180 ;
else
V_179 |= V_242 ;
V_129 -> V_72 . V_179 |= V_179 ;
switch ( V_43 & V_243 ) {
case V_175 :
V_129 -> V_169 = 18 ;
break;
case V_176 :
V_129 -> V_169 = 24 ;
break;
case V_177 :
V_129 -> V_169 = 30 ;
break;
case V_178 :
V_129 -> V_169 = 36 ;
break;
default:
break;
}
switch ( V_43 & V_207 ) {
case V_195 :
case V_196 :
case V_197 :
break;
case V_198 :
case V_210 :
V_129 -> V_144 = true ;
F_98 ( V_42 , V_129 ) ;
break;
default:
break;
}
if ( V_4 -> type == V_7 && V_17 -> V_22 . V_244 &&
V_129 -> V_169 > V_17 -> V_22 . V_244 ) {
F_30 ( L_46 ,
V_129 -> V_169 , V_17 -> V_22 . V_244 ) ;
V_17 -> V_22 . V_244 = V_129 -> V_169 ;
}
F_47 ( V_4 , V_129 ) ;
}
static void F_99 ( struct V_3 * V_4 )
{
F_100 ( V_4 ) ;
}
static bool F_101 ( struct V_2 * V_4 ,
struct V_128 * V_129 )
{
int type = V_4 -> type ;
int V_1 = F_1 ( V_4 ) ;
F_8 ( type == V_9 , L_47 ) ;
if ( V_1 == V_34 )
V_129 -> V_167 = V_184 ;
if ( type == V_8 )
return F_102 ( V_4 , V_129 ) ;
else
return F_103 ( V_4 , V_129 ) ;
}
static struct V_201 *
F_104 ( struct V_10 * V_11 )
{
struct V_201 * V_245 ;
enum V_1 V_1 = V_11 -> V_1 ;
V_245 = F_105 ( sizeof( * V_245 ) , V_246 ) ;
if ( ! V_245 )
return NULL ;
V_11 -> V_237 . V_247 = F_16 ( V_1 ) ;
if ( ! F_106 ( V_11 , V_245 ) ) {
F_107 ( V_245 ) ;
return NULL ;
}
return V_245 ;
}
static struct V_201 *
F_108 ( struct V_10 * V_11 )
{
struct V_201 * V_245 ;
enum V_1 V_1 = V_11 -> V_1 ;
V_245 = F_105 ( sizeof( * V_245 ) , V_246 ) ;
if ( ! V_245 )
return NULL ;
V_11 -> V_248 . V_249 = F_16 ( V_1 ) ;
F_109 ( V_11 , V_245 ) ;
return V_245 ;
}
void F_110 ( struct V_14 * V_15 , enum V_1 V_1 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_10 * V_11 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
struct V_201 * V_250 = NULL ;
struct V_201 * V_251 = NULL ;
bool V_252 , V_253 ;
V_252 = ( V_17 -> V_22 . V_23 [ V_1 ] . V_254 ||
V_17 -> V_22 . V_23 [ V_1 ] . V_255 ) ;
V_253 = V_17 -> V_22 . V_23 [ V_1 ] . V_256 ;
if ( ! V_253 && ! V_252 ) {
F_30 ( L_48 ,
F_19 ( V_1 ) ) ;
V_252 = true ;
V_253 = true ;
}
V_11 = F_105 ( sizeof( * V_11 ) , V_246 ) ;
if ( ! V_11 )
return;
V_2 = & V_11 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_111 ( V_15 , V_4 , & V_257 ,
V_258 ) ;
V_2 -> V_259 = F_101 ;
V_2 -> V_260 = F_31 ;
V_2 -> V_261 = F_83 ;
V_2 -> V_262 = F_74 ;
V_2 -> V_263 = F_86 ;
V_2 -> V_264 = F_80 ;
V_2 -> V_206 = F_65 ;
V_2 -> V_265 = F_97 ;
V_11 -> V_1 = V_1 ;
V_11 -> V_76 = F_18 ( F_16 ( V_1 ) ) &
( V_266 |
V_267 ) ;
V_2 -> type = V_9 ;
V_2 -> V_268 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_269 = 0 ;
V_2 -> V_270 = F_95 ;
if ( V_253 )
V_251 = F_104 ( V_11 ) ;
if ( V_2 -> type != V_7 && V_252 )
V_250 = F_108 ( V_11 ) ;
if ( ! V_251 && ! V_250 ) {
F_112 ( V_4 ) ;
F_107 ( V_11 ) ;
}
}
