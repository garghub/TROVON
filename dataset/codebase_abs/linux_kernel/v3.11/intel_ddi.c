static enum V_1 F_1 ( struct V_2 * V_2 )
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
static void F_5 ( struct V_14 * V_15 , enum V_1 V_1 ,
bool V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
T_1 V_20 ;
int V_21 ;
const T_1 * V_22 = ( ( V_16 ) ?
V_23 :
V_24 ) ;
F_6 ( L_2 ,
F_7 ( V_1 ) ,
V_16 ? L_3 : L_4 ) ;
F_8 ( ( V_16 && ( V_1 != V_13 ) ) ,
L_5 ,
F_7 ( V_1 ) ) ;
for ( V_21 = 0 , V_20 = F_9 ( V_1 ) ; V_21 < F_10 ( V_23 ) ; V_21 ++ ) {
F_11 ( V_20 , V_22 [ V_21 ] ) ;
V_20 += 4 ;
}
}
void F_12 ( struct V_14 * V_15 )
{
int V_1 ;
if ( ! F_13 ( V_15 ) )
return;
for ( V_1 = V_25 ; V_1 < V_13 ; V_1 ++ )
F_5 ( V_15 , V_1 , false ) ;
F_5 ( V_15 , V_13 , true ) ;
}
static void F_14 ( struct V_17 * V_18 ,
enum V_1 V_1 )
{
T_2 V_20 = F_15 ( V_1 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
F_16 ( 1 ) ;
if ( F_17 ( V_20 ) & V_26 )
return;
}
F_3 ( L_6 , F_7 ( V_1 ) ) ;
}
void F_18 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
T_1 V_30 , V_21 , V_31 ;
F_11 ( V_32 , F_20 ( 2 ) |
F_21 ( 2 ) |
V_33 | V_34 ) ;
V_31 = V_18 -> V_35 | V_36 |
V_37 |
F_22 ( V_29 -> V_38 . V_39 ) ;
F_11 ( V_40 , V_31 ) ;
F_23 ( V_40 ) ;
F_16 ( 220 ) ;
V_31 |= V_41 ;
F_11 ( V_40 , V_31 ) ;
F_11 ( F_24 ( V_13 ) , V_29 -> V_42 ) ;
for ( V_21 = 0 ; V_21 < F_10 ( V_43 ) * 2 ; V_21 ++ ) {
F_11 ( F_25 ( V_13 ) ,
V_44 |
V_45 |
V_46 |
V_47 ) ;
F_11 ( F_15 ( V_13 ) ,
V_48 |
( ( V_29 -> V_38 . V_39 - 1 ) << 1 ) |
V_43 [ V_21 / 2 ] ) ;
F_23 ( F_15 ( V_13 ) ) ;
F_16 ( 600 ) ;
F_11 ( V_49 , F_26 ( 64 ) ) ;
V_31 |= V_50 | V_51 ;
F_11 ( V_40 , V_31 ) ;
F_23 ( V_40 ) ;
F_16 ( 30 ) ;
V_30 = F_17 ( V_32 ) ;
V_30 &= ~ ( V_52 | V_53 ) ;
F_11 ( V_32 , V_30 ) ;
F_23 ( V_32 ) ;
F_16 ( 5 ) ;
V_30 = F_17 ( F_27 ( V_13 ) ) ;
if ( V_30 & V_54 ) {
F_28 ( L_7 , V_21 ) ;
F_11 ( F_25 ( V_13 ) ,
V_44 |
V_55 |
V_45 |
V_47 ) ;
return;
}
V_30 = F_17 ( F_15 ( V_13 ) ) ;
V_30 &= ~ V_48 ;
F_11 ( F_15 ( V_13 ) , V_30 ) ;
F_23 ( F_15 ( V_13 ) ) ;
V_30 = F_17 ( F_25 ( V_13 ) ) ;
V_30 &= ~ ( V_47 | V_56 ) ;
V_30 |= V_46 ;
F_11 ( F_25 ( V_13 ) , V_30 ) ;
F_23 ( F_25 ( V_13 ) ) ;
F_14 ( V_18 , V_13 ) ;
V_31 &= ~ V_50 ;
F_11 ( V_40 , V_31 ) ;
F_23 ( V_40 ) ;
V_30 = F_17 ( V_32 ) ;
V_30 &= ~ ( V_52 | V_53 ) ;
V_30 |= F_20 ( 2 ) | F_21 ( 2 ) ;
F_11 ( V_32 , V_30 ) ;
F_23 ( V_32 ) ;
}
F_3 ( L_8 ) ;
}
static void F_29 ( struct V_3 * V_4 ,
struct V_57 * V_58 ,
struct V_57 * V_59 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_30 ( V_4 ) ;
int V_1 = F_1 ( V_2 ) ;
int V_60 = V_29 -> V_60 ;
int type = V_2 -> type ;
F_28 ( L_9 ,
F_7 ( V_1 ) , F_31 ( V_60 ) ) ;
V_29 -> V_61 = false ;
if ( type == V_6 || type == V_7 ) {
struct V_62 * V_62 = F_32 ( V_4 ) ;
struct V_10 * V_11 =
F_2 ( V_4 ) ;
V_62 -> V_63 = V_11 -> V_64 |
V_48 | V_65 ;
V_62 -> V_63 |= F_33 ( V_62 -> V_66 ) ;
if ( V_62 -> V_67 ) {
F_6 ( L_10 ,
F_31 ( V_29 -> V_60 ) ) ;
F_6 ( L_11 ) ;
F_34 ( V_4 , V_59 ) ;
}
F_35 ( V_62 ) ;
} else if ( type == V_8 ) {
struct V_68 * V_68 = F_36 ( V_4 ) ;
if ( V_68 -> V_67 ) {
F_6 ( L_12 ,
F_31 ( V_29 -> V_60 ) ) ;
F_6 ( L_13 ) ;
F_34 ( V_4 , V_59 ) ;
}
V_68 -> V_69 ( V_4 , V_59 ) ;
}
}
static struct V_2 *
F_37 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 , * V_70 = NULL ;
int V_71 = 0 ;
F_38 (dev, crtc, intel_encoder) {
V_70 = V_2 ;
V_71 ++ ;
}
if ( V_71 != 1 )
F_8 ( 1 , L_14 , V_71 ,
F_31 ( V_29 -> V_60 ) ) ;
F_39 ( V_70 == NULL ) ;
return V_70 ;
}
void F_40 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_72 * V_73 = & V_18 -> V_74 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
T_2 V_75 ;
switch ( V_29 -> V_42 ) {
case V_76 :
V_73 -> V_77 -- ;
if ( V_73 -> V_77 == 0 ) {
F_28 ( L_15 ) ;
V_75 = F_17 ( V_78 ) ;
F_41 ( ! ( V_75 & V_79 ) ) ;
F_11 ( V_78 , V_75 & ~ V_79 ) ;
F_23 ( V_78 ) ;
}
break;
case V_80 :
V_73 -> V_81 -- ;
if ( V_73 -> V_81 == 0 ) {
F_28 ( L_16 ) ;
V_75 = F_17 ( V_82 ) ;
F_41 ( ! ( V_75 & V_83 ) ) ;
F_11 ( V_82 , V_75 & ~ V_83 ) ;
F_23 ( V_82 ) ;
}
break;
case V_84 :
V_73 -> V_85 -- ;
if ( V_73 -> V_85 == 0 ) {
F_28 ( L_17 ) ;
V_75 = F_17 ( V_86 ) ;
F_41 ( ! ( V_75 & V_83 ) ) ;
F_11 ( V_86 , V_75 & ~ V_83 ) ;
F_23 ( V_86 ) ;
}
break;
}
F_8 ( V_73 -> V_77 < 0 , L_18 ) ;
F_8 ( V_73 -> V_81 < 0 , L_19 ) ;
F_8 ( V_73 -> V_85 < 0 , L_20 ) ;
V_29 -> V_42 = V_87 ;
}
static unsigned F_42 ( int clock )
{
unsigned V_88 ;
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
V_88 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_88 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_88 = 2000 ;
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
V_88 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_88 = 5000 ;
break;
default:
V_88 = 1000 ;
break;
}
return V_88 ;
}
static void F_43 ( T_3 V_89 , unsigned V_88 ,
unsigned V_90 , unsigned V_91 , unsigned V_92 ,
struct V_93 * V_94 )
{
T_3 V_95 , V_96 , V_97 , V_98 , V_99 , V_100 ;
if ( V_94 -> V_92 == 0 ) {
V_94 -> V_92 = V_92 ;
V_94 -> V_91 = V_91 ;
V_94 -> V_90 = V_90 ;
return;
}
V_95 = V_89 * V_88 * V_92 * V_90 ;
V_96 = V_89 * V_88 * V_94 -> V_92 * V_94 -> V_90 ;
V_99 = F_44 ( ( V_89 * V_92 * V_90 ) , ( V_101 * V_91 ) ) ;
V_100 = F_44 ( ( V_89 * V_94 -> V_92 * V_94 -> V_90 ) ,
( V_101 * V_94 -> V_91 ) ) ;
V_97 = 1000000 * V_99 ;
V_98 = 1000000 * V_100 ;
if ( V_95 < V_97 && V_96 < V_98 ) {
if ( V_94 -> V_92 * V_94 -> V_90 * V_99 < V_92 * V_90 * V_100 ) {
V_94 -> V_92 = V_92 ;
V_94 -> V_91 = V_91 ;
V_94 -> V_90 = V_90 ;
}
} else if ( V_95 >= V_97 && V_96 < V_98 ) {
V_94 -> V_92 = V_92 ;
V_94 -> V_91 = V_91 ;
V_94 -> V_90 = V_90 ;
} else if ( V_95 >= V_97 && V_96 >= V_98 ) {
if ( V_91 * V_94 -> V_90 * V_94 -> V_90 > V_94 -> V_91 * V_90 * V_90 ) {
V_94 -> V_92 = V_92 ;
V_94 -> V_91 = V_91 ;
V_94 -> V_90 = V_90 ;
}
}
}
static void
F_45 ( int clock ,
unsigned * V_102 , unsigned * V_103 , unsigned * V_104 )
{
T_3 V_89 ;
unsigned V_92 , V_91 , V_90 ;
struct V_93 V_94 = { 0 , 0 , 0 } ;
unsigned V_88 ;
V_89 = clock / 100 ;
V_88 = F_42 ( clock ) ;
if ( V_89 == 5400000 ) {
* V_103 = 2 ;
* V_104 = 1 ;
* V_102 = 2 ;
return;
}
for ( V_90 = V_105 * 2 / V_106 + 1 ;
V_90 <= V_105 * 2 / V_107 ;
V_90 ++ ) {
for ( V_91 = V_108 * V_90 / V_105 + 1 ;
V_91 <= V_109 * V_90 / V_105 ;
V_91 ++ ) {
for ( V_92 = V_110 ; V_92 <= V_111 ; V_92 += V_112 )
F_43 ( V_89 , V_88 ,
V_90 , V_91 , V_92 , & V_94 ) ;
}
}
* V_103 = V_94 . V_91 ;
* V_104 = V_94 . V_92 ;
* V_102 = V_94 . V_90 ;
F_28 ( L_21 ,
clock , * V_104 , * V_103 , * V_102 ) ;
}
bool F_46 ( struct V_27 * V_28 )
{
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_37 ( V_28 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_72 * V_73 = & V_18 -> V_74 ;
int type = V_2 -> type ;
enum V_60 V_60 = V_29 -> V_60 ;
T_2 V_20 , V_75 ;
int clock = V_29 -> V_38 . V_113 ;
F_40 ( V_28 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_62 * V_62 = F_32 ( V_4 ) ;
switch ( V_62 -> V_114 ) {
case V_115 :
V_29 -> V_42 = V_116 ;
break;
case V_117 :
V_29 -> V_42 = V_118 ;
break;
case V_119 :
V_29 -> V_42 = V_120 ;
break;
default:
F_3 ( L_22 ,
V_62 -> V_114 ) ;
return false ;
}
return true ;
} else if ( type == V_8 ) {
unsigned V_92 , V_91 , V_90 ;
if ( V_73 -> V_81 == 0 ) {
F_28 ( L_23 ,
F_31 ( V_60 ) ) ;
V_73 -> V_81 ++ ;
V_20 = V_82 ;
V_29 -> V_42 = V_80 ;
} else if ( V_73 -> V_85 == 0 ) {
F_28 ( L_24 ,
F_31 ( V_60 ) ) ;
V_73 -> V_85 ++ ;
V_20 = V_86 ;
V_29 -> V_42 = V_84 ;
} else {
F_3 ( L_25 ) ;
return false ;
}
F_8 ( F_17 ( V_20 ) & V_83 ,
L_26 ) ;
F_45 ( clock * 1000 , & V_90 , & V_91 , & V_92 ) ;
V_75 = V_83 | V_121 |
F_47 ( V_90 ) | F_48 ( V_91 ) |
F_49 ( V_92 ) ;
} else if ( type == V_12 ) {
if ( V_73 -> V_77 == 0 ) {
F_28 ( L_27 ,
F_31 ( V_60 ) ) ;
V_73 -> V_77 ++ ;
V_20 = V_78 ;
V_29 -> V_42 = V_76 ;
} else {
F_3 ( L_28 ) ;
return false ;
}
F_8 ( F_17 ( V_20 ) & V_79 ,
L_29 ) ;
V_75 = V_79 | V_122 | V_123 ;
} else {
F_8 ( 1 , L_1 , type ) ;
return false ;
}
F_11 ( V_20 , V_75 ) ;
F_16 ( 20 ) ;
return true ;
}
void F_50 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_37 ( V_28 ) ;
enum V_124 V_125 = V_29 -> V_38 . V_125 ;
int type = V_2 -> type ;
T_2 V_30 ;
if ( type == V_6 || type == V_7 ) {
V_30 = V_126 ;
switch ( V_29 -> V_38 . V_127 ) {
case 18 :
V_30 |= V_128 ;
break;
case 24 :
V_30 |= V_129 ;
break;
case 30 :
V_30 |= V_130 ;
break;
case 36 :
V_30 |= V_131 ;
break;
default:
F_4 () ;
}
F_11 ( F_51 ( V_125 ) , V_30 ) ;
}
}
void F_52 ( struct V_27 * V_28 )
{
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_37 ( V_28 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
enum V_60 V_60 = V_29 -> V_60 ;
enum V_124 V_125 = V_29 -> V_38 . V_125 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_30 ;
V_30 = V_132 ;
V_30 |= F_53 ( V_1 ) ;
switch ( V_29 -> V_38 . V_127 ) {
case 18 :
V_30 |= V_133 ;
break;
case 24 :
V_30 |= V_134 ;
break;
case 30 :
V_30 |= V_135 ;
break;
case 36 :
V_30 |= V_136 ;
break;
default:
F_4 () ;
}
if ( V_28 -> V_58 . V_137 & V_138 )
V_30 |= V_139 ;
if ( V_28 -> V_58 . V_137 & V_140 )
V_30 |= V_141 ;
if ( V_125 == V_142 ) {
switch ( V_60 ) {
case V_143 :
if ( V_29 -> V_38 . V_144 . V_145 )
V_30 |= V_146 ;
else
V_30 |= V_147 ;
break;
case V_148 :
V_30 |= V_149 ;
break;
case V_150 :
V_30 |= V_151 ;
break;
default:
F_4 () ;
break;
}
}
if ( type == V_8 ) {
struct V_68 * V_68 = F_36 ( V_4 ) ;
if ( V_68 -> V_152 )
V_30 |= V_153 ;
else
V_30 |= V_154 ;
} else if ( type == V_12 ) {
V_30 |= V_155 ;
V_30 |= ( V_29 -> V_38 . V_39 - 1 ) << 1 ;
} else if ( type == V_6 ||
type == V_7 ) {
struct V_62 * V_62 = F_32 ( V_4 ) ;
V_30 |= V_156 ;
V_30 |= F_33 ( V_62 -> V_66 ) ;
} else {
F_8 ( 1 , L_30 ,
V_2 -> type , F_31 ( V_60 ) ) ;
}
F_11 ( F_54 ( V_125 ) , V_30 ) ;
}
void F_55 ( struct V_17 * V_18 ,
enum V_124 V_125 )
{
T_2 V_20 = F_54 ( V_125 ) ;
T_2 V_75 = F_17 ( V_20 ) ;
V_75 &= ~ ( V_132 | V_157 ) ;
V_75 |= V_158 ;
F_11 ( V_20 , V_75 ) ;
}
bool F_56 ( struct V_159 * V_159 )
{
struct V_14 * V_15 = V_159 -> V_5 . V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_2 * V_2 = V_159 -> V_4 ;
int type = V_159 -> V_5 . V_160 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_60 V_60 = 0 ;
enum V_124 V_125 ;
T_2 V_161 ;
if ( ! V_2 -> V_162 ( V_2 , & V_60 ) )
return false ;
if ( V_1 == V_25 )
V_125 = V_142 ;
else
V_125 = (enum V_124 ) V_60 ;
V_161 = F_17 ( F_54 ( V_125 ) ) ;
switch ( V_161 & V_163 ) {
case V_153 :
case V_154 :
return ( type == V_164 ) ;
case V_156 :
if ( type == V_165 )
return true ;
case V_166 :
return ( type == V_167 ) ;
case V_155 :
return ( type == V_168 ) ;
default:
return false ;
}
}
bool F_57 ( struct V_2 * V_4 ,
enum V_60 * V_60 )
{
struct V_14 * V_15 = V_4 -> V_5 . V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
T_1 V_161 ;
int V_21 ;
V_161 = F_17 ( F_15 ( V_1 ) ) ;
if ( ! ( V_161 & V_48 ) )
return false ;
if ( V_1 == V_25 ) {
V_161 = F_17 ( F_54 ( V_142 ) ) ;
switch ( V_161 & V_169 ) {
case V_147 :
case V_146 :
* V_60 = V_143 ;
break;
case V_149 :
* V_60 = V_148 ;
break;
case V_151 :
* V_60 = V_150 ;
break;
}
return true ;
} else {
for ( V_21 = V_170 ; V_21 <= V_171 ; V_21 ++ ) {
V_161 = F_17 ( F_54 ( V_21 ) ) ;
if ( ( V_161 & V_157 )
== F_53 ( V_1 ) ) {
* V_60 = V_21 ;
return true ;
}
}
}
F_28 ( L_31 , F_7 ( V_1 ) ) ;
return false ;
}
static T_2 F_58 ( struct V_17 * V_18 ,
enum V_60 V_60 )
{
T_2 V_30 , V_70 ;
enum V_1 V_1 = V_172 ;
enum V_124 V_125 = F_59 ( V_18 ,
V_60 ) ;
int V_21 ;
if ( V_125 == V_142 ) {
V_1 = V_25 ;
} else {
V_30 = F_17 ( F_54 ( V_125 ) ) ;
V_30 &= V_157 ;
for ( V_21 = V_173 ; V_21 <= V_13 ; V_21 ++ )
if ( V_30 == F_53 ( V_21 ) )
V_1 = V_21 ;
}
if ( V_1 == V_172 ) {
F_8 ( 1 , L_32 ,
F_31 ( V_60 ) ) ;
V_70 = V_87 ;
} else {
V_70 = F_17 ( F_24 ( V_1 ) ) ;
F_28 ( L_33
L_34 , F_31 ( V_60 ) , F_7 ( V_1 ) ,
V_70 ) ;
}
return V_70 ;
}
void F_60 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
enum V_60 V_60 ;
struct V_29 * V_29 ;
F_61 (pipe) {
V_29 =
F_19 ( V_18 -> V_174 [ V_60 ] ) ;
if ( ! V_29 -> V_175 )
continue;
V_29 -> V_42 = F_58 ( V_18 ,
V_60 ) ;
switch ( V_29 -> V_42 ) {
case V_76 :
V_18 -> V_74 . V_77 ++ ;
break;
case V_80 :
V_18 -> V_74 . V_81 ++ ;
break;
case V_84 :
V_18 -> V_74 . V_85 ++ ;
break;
}
}
}
void F_62 ( struct V_29 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_5 ;
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_2 * V_2 = F_37 ( V_28 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_124 V_125 = V_29 -> V_38 . V_125 ;
if ( V_125 != V_142 )
F_11 ( F_63 ( V_125 ) ,
F_64 ( V_1 ) ) ;
}
void F_65 ( struct V_29 * V_29 )
{
struct V_17 * V_18 = V_29 -> V_5 . V_15 -> V_19 ;
enum V_124 V_125 = V_29 -> V_38 . V_125 ;
if ( V_125 != V_142 )
F_11 ( F_63 ( V_125 ) ,
V_176 ) ;
}
static void F_66 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_17 * V_18 = V_4 -> V_15 -> V_19 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_7 ) {
struct V_62 * V_62 = F_32 ( V_4 ) ;
F_67 ( V_62 ) ;
F_68 ( V_62 ) ;
F_69 ( V_62 , true ) ;
}
F_41 ( V_29 -> V_42 == V_87 ) ;
F_11 ( F_24 ( V_1 ) , V_29 -> V_42 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_62 * V_62 = F_32 ( V_4 ) ;
F_70 ( V_62 , V_177 ) ;
F_71 ( V_62 ) ;
F_72 ( V_62 ) ;
if ( V_1 != V_25 )
F_73 ( V_62 ) ;
}
}
static void F_74 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * V_18 = V_4 -> V_15 -> V_19 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_75 ;
bool V_178 = false ;
V_75 = F_17 ( F_15 ( V_1 ) ) ;
if ( V_75 & V_48 ) {
V_75 &= ~ V_48 ;
F_11 ( F_15 ( V_1 ) , V_75 ) ;
V_178 = true ;
}
V_75 = F_17 ( F_25 ( V_1 ) ) ;
V_75 &= ~ ( V_47 | V_56 ) ;
V_75 |= V_46 ;
F_11 ( F_25 ( V_1 ) , V_75 ) ;
if ( V_178 )
F_14 ( V_18 , V_1 ) ;
if ( type == V_7 ) {
struct V_62 * V_62 = F_32 ( V_4 ) ;
F_67 ( V_62 ) ;
F_75 ( V_62 ) ;
}
F_11 ( F_24 ( V_1 ) , V_87 ) ;
}
static void F_76 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
int V_60 = V_29 -> V_60 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_161 ;
if ( type == V_8 ) {
struct V_10 * V_11 =
F_2 ( V_4 ) ;
F_11 ( F_15 ( V_1 ) ,
V_11 -> V_64 |
V_48 ) ;
} else if ( type == V_7 ) {
struct V_62 * V_62 = F_32 ( V_4 ) ;
if ( V_1 == V_25 )
F_73 ( V_62 ) ;
F_77 ( V_62 ) ;
}
if ( V_29 -> V_61 && type != V_7 ) {
V_161 = F_17 ( V_179 ) ;
V_161 |= ( ( V_180 | V_181 ) << ( V_60 * 4 ) ) ;
F_11 ( V_179 , V_161 ) ;
}
}
static void F_78 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
int V_60 = V_29 -> V_60 ;
int type = V_2 -> type ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
T_2 V_161 ;
if ( V_29 -> V_61 && type != V_7 ) {
V_161 = F_17 ( V_179 ) ;
V_161 &= ~ ( ( V_180 | V_181 ) <<
( V_60 * 4 ) ) ;
F_11 ( V_179 , V_161 ) ;
}
if ( type == V_7 ) {
struct V_62 * V_62 = F_32 ( V_4 ) ;
F_79 ( V_62 ) ;
}
}
int F_80 ( struct V_17 * V_18 )
{
if ( F_17 ( V_182 ) & V_183 )
return 450000 ;
else if ( ( F_17 ( V_184 ) & V_185 ) ==
V_186 )
return 450000 ;
else if ( F_81 ( V_18 -> V_15 ) )
return 337500 ;
else
return 540000 ;
}
void F_82 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
T_2 V_75 = F_17 ( V_184 ) ;
F_28 ( L_35 ,
F_80 ( V_18 ) ) ;
if ( V_75 & V_187 )
F_3 ( L_36 ) ;
if ( V_75 & V_188 )
F_3 ( L_37 ) ;
}
void F_83 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
struct V_62 * V_62 = & V_11 -> V_189 ;
struct V_17 * V_18 = V_4 -> V_15 -> V_19 ;
enum V_1 V_1 = V_11 -> V_1 ;
T_2 V_75 ;
bool V_178 = false ;
if ( F_17 ( F_25 ( V_1 ) ) & V_47 ) {
V_75 = F_17 ( F_15 ( V_1 ) ) ;
if ( V_75 & V_48 ) {
V_75 &= ~ V_48 ;
F_11 ( F_15 ( V_1 ) , V_75 ) ;
V_178 = true ;
}
V_75 = F_17 ( F_25 ( V_1 ) ) ;
V_75 &= ~ ( V_47 | V_56 ) ;
V_75 |= V_46 ;
F_11 ( F_25 ( V_1 ) , V_75 ) ;
F_23 ( F_25 ( V_1 ) ) ;
if ( V_178 )
F_14 ( V_18 , V_1 ) ;
}
V_75 = V_47 | V_190 |
V_46 | V_191 ;
if ( V_62 -> V_192 [ 1 ] & V_193 )
V_75 |= V_45 ;
F_11 ( F_25 ( V_1 ) , V_75 ) ;
F_23 ( F_25 ( V_1 ) ) ;
V_62 -> V_63 |= V_48 ;
F_11 ( F_15 ( V_1 ) , V_62 -> V_63 ) ;
F_23 ( F_15 ( V_1 ) ) ;
F_16 ( 600 ) ;
}
void F_84 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_2 * V_2 = F_37 ( V_28 ) ;
T_2 V_75 ;
F_74 ( V_2 ) ;
V_75 = F_17 ( V_40 ) ;
V_75 &= ~ V_50 ;
F_11 ( V_40 , V_75 ) ;
V_75 = F_17 ( V_32 ) ;
V_75 &= ~ ( V_52 | V_53 ) ;
V_75 |= F_20 ( 2 ) | F_21 ( 2 ) ;
F_11 ( V_32 , V_75 ) ;
V_75 = F_17 ( V_40 ) ;
V_75 &= ~ V_41 ;
F_11 ( V_40 , V_75 ) ;
V_75 = F_17 ( V_40 ) ;
V_75 &= ~ V_37 ;
F_11 ( V_40 , V_75 ) ;
}
static void F_85 ( struct V_2 * V_2 )
{
struct V_62 * V_62 = F_32 ( & V_2 -> V_5 ) ;
int type = V_2 -> type ;
if ( type == V_6 || type == V_7 )
F_86 ( V_62 ) ;
}
static void F_87 ( struct V_2 * V_4 ,
struct V_194 * V_195 )
{
struct V_17 * V_18 = V_4 -> V_5 . V_15 -> V_19 ;
struct V_29 * V_29 = F_19 ( V_4 -> V_5 . V_28 ) ;
enum V_124 V_125 = V_29 -> V_38 . V_125 ;
T_1 V_30 , V_137 = 0 ;
V_30 = F_17 ( F_54 ( V_125 ) ) ;
if ( V_30 & V_141 )
V_137 |= V_140 ;
else
V_137 |= V_196 ;
if ( V_30 & V_139 )
V_137 |= V_138 ;
else
V_137 |= V_197 ;
V_195 -> V_59 . V_137 |= V_137 ;
}
static void F_88 ( struct V_3 * V_4 )
{
F_89 ( V_4 ) ;
}
static bool F_90 ( struct V_2 * V_4 ,
struct V_194 * V_195 )
{
int type = V_4 -> type ;
int V_1 = F_1 ( V_4 ) ;
F_8 ( type == V_9 , L_38 ) ;
if ( V_1 == V_25 )
V_195 -> V_125 = V_142 ;
if ( type == V_8 )
return F_91 ( V_4 , V_195 ) ;
else
return F_92 ( V_4 , V_195 ) ;
}
void F_93 ( struct V_14 * V_15 , enum V_1 V_1 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_10 * V_11 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
struct V_159 * V_198 = NULL ;
struct V_159 * V_199 = NULL ;
V_11 = F_94 ( sizeof( struct V_10 ) , V_200 ) ;
if ( ! V_11 )
return;
V_199 = F_94 ( sizeof( struct V_159 ) , V_200 ) ;
if ( ! V_199 ) {
F_95 ( V_11 ) ;
return;
}
V_2 = & V_11 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_96 ( V_15 , V_4 , & V_201 ,
V_202 ) ;
F_97 ( V_4 , & V_203 ) ;
V_2 -> V_204 = F_90 ;
V_2 -> V_205 = F_76 ;
V_2 -> V_206 = F_66 ;
V_2 -> V_207 = F_78 ;
V_2 -> V_208 = F_74 ;
V_2 -> V_162 = F_57 ;
V_2 -> V_209 = F_87 ;
V_11 -> V_1 = V_1 ;
V_11 -> V_64 = F_17 ( F_15 ( V_1 ) ) &
( V_210 |
V_211 ) ;
V_11 -> V_189 . V_212 = F_15 ( V_1 ) ;
V_2 -> type = V_9 ;
V_2 -> V_213 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_214 = false ;
V_2 -> V_215 = F_85 ;
if ( ! F_98 ( V_11 , V_199 ) ) {
F_99 ( V_4 ) ;
F_95 ( V_11 ) ;
F_95 ( V_199 ) ;
return;
}
if ( V_2 -> type != V_7 ) {
V_198 = F_94 ( sizeof( struct V_159 ) ,
V_200 ) ;
if ( ! V_198 ) {
return;
}
V_11 -> V_216 . V_217 = F_15 ( V_1 ) ;
F_100 ( V_11 , V_198 ) ;
}
}
