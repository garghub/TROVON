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
static void F_5 ( struct V_14 * V_15 , enum V_1 V_1 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
T_1 V_19 ;
int V_20 ;
const T_1 * V_21 = ( V_1 == V_13 ) ?
V_22 :
V_23 ;
for ( V_20 = 0 , V_19 = F_6 ( V_1 ) ;
V_20 < F_7 ( V_22 ) ; V_20 ++ ) {
F_8 ( V_19 , V_21 [ V_20 ] ) ;
V_19 += 4 ;
}
}
void F_9 ( struct V_14 * V_15 )
{
int V_1 ;
if ( ! F_10 ( V_15 ) )
return;
for ( V_1 = V_24 ; V_1 <= V_13 ; V_1 ++ )
F_5 ( V_15 , V_1 ) ;
}
static void F_11 ( struct V_16 * V_17 ,
enum V_1 V_1 )
{
T_2 V_19 = F_12 ( V_1 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
F_13 ( 1 ) ;
if ( F_14 ( V_19 ) & V_25 )
return;
}
F_3 ( L_2 , F_15 ( V_1 ) ) ;
}
void F_16 ( struct V_26 * V_27 )
{
struct V_14 * V_15 = V_27 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_28 * V_28 = F_17 ( V_27 ) ;
T_1 V_29 , V_20 , V_30 ;
F_8 ( V_31 , F_18 ( 2 ) |
F_19 ( 2 ) |
V_32 | V_33 ) ;
V_30 = V_17 -> V_34 | V_35 |
V_36 |
F_20 ( V_28 -> V_37 . V_38 ) ;
F_8 ( V_39 , V_30 ) ;
F_21 ( V_39 ) ;
F_13 ( 220 ) ;
V_30 |= V_40 ;
F_8 ( V_39 , V_30 ) ;
F_8 ( F_22 ( V_13 ) , V_28 -> V_41 ) ;
for ( V_20 = 0 ; V_20 < F_7 ( V_42 ) * 2 ; V_20 ++ ) {
F_8 ( F_23 ( V_13 ) ,
V_43 |
V_44 |
V_45 |
V_46 ) ;
F_8 ( F_12 ( V_13 ) ,
V_47 |
( ( V_28 -> V_37 . V_38 - 1 ) << 1 ) |
V_42 [ V_20 / 2 ] ) ;
F_21 ( F_12 ( V_13 ) ) ;
F_13 ( 600 ) ;
F_8 ( V_48 , F_24 ( 64 ) ) ;
V_30 |= V_49 | V_50 ;
F_8 ( V_39 , V_30 ) ;
F_21 ( V_39 ) ;
F_13 ( 30 ) ;
V_29 = F_14 ( V_31 ) ;
V_29 &= ~ ( V_51 | V_52 ) ;
F_8 ( V_31 , V_29 ) ;
F_21 ( V_31 ) ;
F_13 ( 5 ) ;
V_29 = F_14 ( F_25 ( V_13 ) ) ;
if ( V_29 & V_53 ) {
F_26 ( L_3 , V_20 ) ;
F_8 ( F_23 ( V_13 ) ,
V_43 |
V_54 |
V_44 |
V_46 ) ;
return;
}
V_29 = F_14 ( F_12 ( V_13 ) ) ;
V_29 &= ~ V_47 ;
F_8 ( F_12 ( V_13 ) , V_29 ) ;
F_21 ( F_12 ( V_13 ) ) ;
V_29 = F_14 ( F_23 ( V_13 ) ) ;
V_29 &= ~ ( V_46 | V_55 ) ;
V_29 |= V_45 ;
F_8 ( F_23 ( V_13 ) , V_29 ) ;
F_21 ( F_23 ( V_13 ) ) ;
F_11 ( V_17 , V_13 ) ;
V_30 &= ~ V_49 ;
F_8 ( V_39 , V_30 ) ;
F_21 ( V_39 ) ;
V_29 = F_14 ( V_31 ) ;
V_29 &= ~ ( V_51 | V_52 ) ;
V_29 |= F_18 ( 2 ) | F_19 ( 2 ) ;
F_8 ( V_31 , V_29 ) ;
F_21 ( V_31 ) ;
}
F_3 ( L_4 ) ;
}
static void F_27 ( struct V_2 * V_4 )
{
struct V_28 * V_27 = F_17 ( V_4 -> V_5 . V_27 ) ;
int V_1 = F_1 ( V_4 ) ;
int V_56 = V_27 -> V_56 ;
int type = V_4 -> type ;
struct V_57 * V_58 = & V_27 -> V_37 . V_58 ;
F_26 ( L_5 ,
F_15 ( V_1 ) , F_28 ( V_56 ) ) ;
V_27 -> V_59 = false ;
if ( type == V_6 || type == V_7 ) {
struct V_60 * V_60 = F_29 ( & V_4 -> V_5 ) ;
struct V_10 * V_11 =
F_2 ( & V_4 -> V_5 ) ;
V_60 -> V_61 = V_11 -> V_62 |
V_47 | V_63 ;
V_60 -> V_61 |= F_30 ( V_60 -> V_64 ) ;
if ( V_60 -> V_65 ) {
F_31 ( L_6 ,
F_28 ( V_27 -> V_56 ) ) ;
F_31 ( L_7 ) ;
F_32 ( & V_4 -> V_5 , V_58 ) ;
}
F_33 ( V_60 ) ;
} else if ( type == V_8 ) {
struct V_66 * V_66 = F_34 ( & V_4 -> V_5 ) ;
if ( V_66 -> V_65 ) {
F_31 ( L_8 ,
F_28 ( V_27 -> V_56 ) ) ;
F_31 ( L_9 ) ;
F_32 ( & V_4 -> V_5 , V_58 ) ;
}
V_66 -> V_67 ( & V_4 -> V_5 , V_58 ) ;
}
}
static struct V_2 *
F_35 ( struct V_26 * V_27 )
{
struct V_14 * V_15 = V_27 -> V_15 ;
struct V_28 * V_28 = F_17 ( V_27 ) ;
struct V_2 * V_2 , * V_68 = NULL ;
int V_69 = 0 ;
F_36 (dev, crtc, intel_encoder) {
V_68 = V_2 ;
V_69 ++ ;
}
if ( V_69 != 1 )
F_37 ( 1 , L_10 , V_69 ,
F_28 ( V_28 -> V_56 ) ) ;
F_38 ( V_68 == NULL ) ;
return V_68 ;
}
void F_39 ( struct V_26 * V_27 )
{
struct V_16 * V_17 = V_27 -> V_15 -> V_18 ;
struct V_70 * V_71 = & V_17 -> V_72 ;
struct V_28 * V_28 = F_17 ( V_27 ) ;
T_2 V_73 ;
switch ( V_28 -> V_41 ) {
case V_74 :
V_71 -> V_75 -- ;
if ( V_71 -> V_75 == 0 ) {
F_26 ( L_11 ) ;
V_73 = F_14 ( V_76 ) ;
F_40 ( ! ( V_73 & V_77 ) ) ;
F_8 ( V_76 , V_73 & ~ V_77 ) ;
F_21 ( V_76 ) ;
}
break;
case V_78 :
V_71 -> V_79 -- ;
if ( V_71 -> V_79 == 0 ) {
F_26 ( L_12 ) ;
V_73 = F_14 ( V_80 ) ;
F_40 ( ! ( V_73 & V_81 ) ) ;
F_8 ( V_80 , V_73 & ~ V_81 ) ;
F_21 ( V_80 ) ;
}
break;
case V_82 :
V_71 -> V_83 -- ;
if ( V_71 -> V_83 == 0 ) {
F_26 ( L_13 ) ;
V_73 = F_14 ( V_84 ) ;
F_40 ( ! ( V_73 & V_81 ) ) ;
F_8 ( V_84 , V_73 & ~ V_81 ) ;
F_21 ( V_84 ) ;
}
break;
}
F_37 ( V_71 -> V_75 < 0 , L_14 ) ;
F_37 ( V_71 -> V_79 < 0 , L_15 ) ;
F_37 ( V_71 -> V_83 < 0 , L_16 ) ;
V_28 -> V_41 = V_85 ;
}
static unsigned F_41 ( int clock )
{
unsigned V_86 ;
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
V_86 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_86 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_86 = 2000 ;
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
V_86 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_86 = 5000 ;
break;
default:
V_86 = 1000 ;
break;
}
return V_86 ;
}
static void F_42 ( T_3 V_87 , unsigned V_86 ,
unsigned V_88 , unsigned V_89 , unsigned V_90 ,
struct V_91 * V_92 )
{
T_3 V_93 , V_94 , V_95 , V_96 , V_97 , V_98 ;
if ( V_92 -> V_90 == 0 ) {
V_92 -> V_90 = V_90 ;
V_92 -> V_89 = V_89 ;
V_92 -> V_88 = V_88 ;
return;
}
V_93 = V_87 * V_86 * V_90 * V_88 ;
V_94 = V_87 * V_86 * V_92 -> V_90 * V_92 -> V_88 ;
V_97 = F_43 ( ( V_87 * V_90 * V_88 ) , ( V_99 * V_89 ) ) ;
V_98 = F_43 ( ( V_87 * V_92 -> V_90 * V_92 -> V_88 ) ,
( V_99 * V_92 -> V_89 ) ) ;
V_95 = 1000000 * V_97 ;
V_96 = 1000000 * V_98 ;
if ( V_93 < V_95 && V_94 < V_96 ) {
if ( V_92 -> V_90 * V_92 -> V_88 * V_97 < V_90 * V_88 * V_98 ) {
V_92 -> V_90 = V_90 ;
V_92 -> V_89 = V_89 ;
V_92 -> V_88 = V_88 ;
}
} else if ( V_93 >= V_95 && V_94 < V_96 ) {
V_92 -> V_90 = V_90 ;
V_92 -> V_89 = V_89 ;
V_92 -> V_88 = V_88 ;
} else if ( V_93 >= V_95 && V_94 >= V_96 ) {
if ( V_89 * V_92 -> V_88 * V_92 -> V_88 > V_92 -> V_89 * V_88 * V_88 ) {
V_92 -> V_90 = V_90 ;
V_92 -> V_89 = V_89 ;
V_92 -> V_88 = V_88 ;
}
}
}
static void
F_44 ( int clock ,
unsigned * V_100 , unsigned * V_101 , unsigned * V_102 )
{
T_3 V_87 ;
unsigned V_90 , V_89 , V_88 ;
struct V_91 V_92 = { 0 , 0 , 0 } ;
unsigned V_86 ;
V_87 = clock / 100 ;
V_86 = F_41 ( clock ) ;
if ( V_87 == 5400000 ) {
* V_101 = 2 ;
* V_102 = 1 ;
* V_100 = 2 ;
return;
}
for ( V_88 = V_103 * 2 / V_104 + 1 ;
V_88 <= V_103 * 2 / V_105 ;
V_88 ++ ) {
for ( V_89 = V_106 * V_88 / V_103 + 1 ;
V_89 <= V_107 * V_88 / V_103 ;
V_89 ++ ) {
for ( V_90 = V_108 ; V_90 <= V_109 ; V_90 += V_110 )
F_42 ( V_87 , V_86 ,
V_88 , V_89 , V_90 , & V_92 ) ;
}
}
* V_101 = V_92 . V_89 ;
* V_102 = V_92 . V_90 ;
* V_100 = V_92 . V_88 ;
F_26 ( L_17 ,
clock , * V_102 , * V_101 , * V_100 ) ;
}
bool F_45 ( struct V_26 * V_27 )
{
struct V_28 * V_28 = F_17 ( V_27 ) ;
struct V_2 * V_2 = F_35 ( V_27 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_27 -> V_15 -> V_18 ;
struct V_70 * V_71 = & V_17 -> V_72 ;
int type = V_2 -> type ;
enum V_56 V_56 = V_28 -> V_56 ;
T_2 V_19 , V_73 ;
int clock = V_28 -> V_37 . V_111 ;
F_39 ( V_27 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_60 * V_60 = F_29 ( V_4 ) ;
switch ( V_60 -> V_112 ) {
case V_113 :
V_28 -> V_41 = V_114 ;
break;
case V_115 :
V_28 -> V_41 = V_116 ;
break;
case V_117 :
V_28 -> V_41 = V_118 ;
break;
default:
F_3 ( L_18 ,
V_60 -> V_112 ) ;
return false ;
}
return true ;
} else if ( type == V_8 ) {
unsigned V_90 , V_89 , V_88 ;
if ( V_71 -> V_79 == 0 ) {
F_26 ( L_19 ,
F_28 ( V_56 ) ) ;
V_71 -> V_79 ++ ;
V_19 = V_80 ;
V_28 -> V_41 = V_78 ;
} else if ( V_71 -> V_83 == 0 ) {
F_26 ( L_20 ,
F_28 ( V_56 ) ) ;
V_71 -> V_83 ++ ;
V_19 = V_84 ;
V_28 -> V_41 = V_82 ;
} else {
F_3 ( L_21 ) ;
return false ;
}
F_37 ( F_14 ( V_19 ) & V_81 ,
L_22 ) ;
F_44 ( clock * 1000 , & V_88 , & V_89 , & V_90 ) ;
V_73 = V_81 | V_119 |
F_46 ( V_88 ) | F_47 ( V_89 ) |
F_48 ( V_90 ) ;
} else if ( type == V_12 ) {
if ( V_71 -> V_75 == 0 ) {
F_26 ( L_23 ,
F_28 ( V_56 ) ) ;
V_71 -> V_75 ++ ;
V_19 = V_76 ;
V_28 -> V_41 = V_74 ;
} else {
F_3 ( L_24 ) ;
return false ;
}
F_37 ( F_14 ( V_19 ) & V_77 ,
L_25 ) ;
V_73 = V_77 | V_120 | V_121 ;
} else {
F_37 ( 1 , L_1 , type ) ;
return false ;
}
F_8 ( V_19 , V_73 ) ;
F_13 ( 20 ) ;
return true ;
}
void F_49 ( struct V_26 * V_27 )
{
struct V_16 * V_17 = V_27 -> V_15 -> V_18 ;
struct V_28 * V_28 = F_17 ( V_27 ) ;
struct V_2 * V_2 = F_35 ( V_27 ) ;
enum V_122 V_123 = V_28 -> V_37 . V_123 ;
int type = V_2 -> type ;
T_2 V_29 ;
if ( type == V_6 || type == V_7 ) {
V_29 = V_124 ;
switch ( V_28 -> V_37 . V_125 ) {
case 18 :
V_29 |= V_126 ;
break;
case 24 :
V_29 |= V_127 ;
break;
case 30 :
V_29 |= V_128 ;
break;
case 36 :
V_29 |= V_129 ;
break;
default:
F_4 () ;
}
F_8 ( F_50 ( V_123 ) , V_29 ) ;
}
}
void F_51 ( struct V_26 * V_27 )
{
struct V_28 * V_28 = F_17 ( V_27 ) ;
struct V_2 * V_2 = F_35 ( V_27 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_27 -> V_15 -> V_18 ;
enum V_56 V_56 = V_28 -> V_56 ;
enum V_122 V_123 = V_28 -> V_37 . V_123 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_29 ;
V_29 = V_130 ;
V_29 |= F_52 ( V_1 ) ;
switch ( V_28 -> V_37 . V_125 ) {
case 18 :
V_29 |= V_131 ;
break;
case 24 :
V_29 |= V_132 ;
break;
case 30 :
V_29 |= V_133 ;
break;
case 36 :
V_29 |= V_134 ;
break;
default:
F_4 () ;
}
if ( V_27 -> V_135 . V_136 & V_137 )
V_29 |= V_138 ;
if ( V_27 -> V_135 . V_136 & V_139 )
V_29 |= V_140 ;
if ( V_123 == V_141 ) {
switch ( V_56 ) {
case V_142 :
if ( V_28 -> V_37 . V_143 . V_144 )
V_29 |= V_145 ;
else
V_29 |= V_146 ;
break;
case V_147 :
V_29 |= V_148 ;
break;
case V_149 :
V_29 |= V_150 ;
break;
default:
F_4 () ;
break;
}
}
if ( type == V_8 ) {
struct V_66 * V_66 = F_34 ( V_4 ) ;
if ( V_66 -> V_151 )
V_29 |= V_152 ;
else
V_29 |= V_153 ;
} else if ( type == V_12 ) {
V_29 |= V_154 ;
V_29 |= ( V_28 -> V_37 . V_38 - 1 ) << 1 ;
} else if ( type == V_6 ||
type == V_7 ) {
struct V_60 * V_60 = F_29 ( V_4 ) ;
V_29 |= V_155 ;
V_29 |= F_30 ( V_60 -> V_64 ) ;
} else {
F_37 ( 1 , L_26 ,
V_2 -> type , F_28 ( V_56 ) ) ;
}
F_8 ( F_53 ( V_123 ) , V_29 ) ;
}
void F_54 ( struct V_16 * V_17 ,
enum V_122 V_123 )
{
T_2 V_19 = F_53 ( V_123 ) ;
T_2 V_73 = F_14 ( V_19 ) ;
V_73 &= ~ ( V_130 | V_156 ) ;
V_73 |= V_157 ;
F_8 ( V_19 , V_73 ) ;
}
bool F_55 ( struct V_158 * V_158 )
{
struct V_14 * V_15 = V_158 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_2 * V_2 = V_158 -> V_4 ;
int type = V_158 -> V_5 . V_159 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_56 V_56 = 0 ;
enum V_122 V_123 ;
T_2 V_160 ;
if ( ! V_2 -> V_161 ( V_2 , & V_56 ) )
return false ;
if ( V_1 == V_24 )
V_123 = V_141 ;
else
V_123 = (enum V_122 ) V_56 ;
V_160 = F_14 ( F_53 ( V_123 ) ) ;
switch ( V_160 & V_162 ) {
case V_152 :
case V_153 :
return ( type == V_163 ) ;
case V_155 :
if ( type == V_164 )
return true ;
case V_165 :
return ( type == V_166 ) ;
case V_154 :
return ( type == V_167 ) ;
default:
return false ;
}
}
bool F_56 ( struct V_2 * V_4 ,
enum V_56 * V_56 )
{
struct V_14 * V_15 = V_4 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
T_1 V_160 ;
int V_20 ;
V_160 = F_14 ( F_12 ( V_1 ) ) ;
if ( ! ( V_160 & V_47 ) )
return false ;
if ( V_1 == V_24 ) {
V_160 = F_14 ( F_53 ( V_141 ) ) ;
switch ( V_160 & V_168 ) {
case V_146 :
case V_145 :
* V_56 = V_142 ;
break;
case V_148 :
* V_56 = V_147 ;
break;
case V_150 :
* V_56 = V_149 ;
break;
}
return true ;
} else {
for ( V_20 = V_169 ; V_20 <= V_170 ; V_20 ++ ) {
V_160 = F_14 ( F_53 ( V_20 ) ) ;
if ( ( V_160 & V_156 )
== F_52 ( V_1 ) ) {
* V_56 = V_20 ;
return true ;
}
}
}
F_26 ( L_27 , F_15 ( V_1 ) ) ;
return false ;
}
static T_2 F_57 ( struct V_16 * V_17 ,
enum V_56 V_56 )
{
T_2 V_29 , V_68 ;
enum V_1 V_1 = V_171 ;
enum V_122 V_123 = F_58 ( V_17 ,
V_56 ) ;
int V_20 ;
if ( V_123 == V_141 ) {
V_1 = V_24 ;
} else {
V_29 = F_14 ( F_53 ( V_123 ) ) ;
V_29 &= V_156 ;
for ( V_20 = V_172 ; V_20 <= V_13 ; V_20 ++ )
if ( V_29 == F_52 ( V_20 ) )
V_1 = V_20 ;
}
if ( V_1 == V_171 ) {
F_37 ( 1 , L_28 ,
F_28 ( V_56 ) ) ;
V_68 = V_85 ;
} else {
V_68 = F_14 ( F_22 ( V_1 ) ) ;
F_26 ( L_29
L_30 , F_28 ( V_56 ) , F_15 ( V_1 ) ,
V_68 ) ;
}
return V_68 ;
}
void F_59 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_56 V_56 ;
struct V_28 * V_28 ;
F_60 (pipe) {
V_28 =
F_17 ( V_17 -> V_173 [ V_56 ] ) ;
if ( ! V_28 -> V_174 )
continue;
V_28 -> V_41 = F_57 ( V_17 ,
V_56 ) ;
switch ( V_28 -> V_41 ) {
case V_74 :
V_17 -> V_72 . V_75 ++ ;
break;
case V_78 :
V_17 -> V_72 . V_79 ++ ;
break;
case V_82 :
V_17 -> V_72 . V_83 ++ ;
break;
}
}
}
void F_61 ( struct V_28 * V_28 )
{
struct V_26 * V_27 = & V_28 -> V_5 ;
struct V_16 * V_17 = V_27 -> V_15 -> V_18 ;
struct V_2 * V_2 = F_35 ( V_27 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_122 V_123 = V_28 -> V_37 . V_123 ;
if ( V_123 != V_141 )
F_8 ( F_62 ( V_123 ) ,
F_63 ( V_1 ) ) ;
}
void F_64 ( struct V_28 * V_28 )
{
struct V_16 * V_17 = V_28 -> V_5 . V_15 -> V_18 ;
enum V_122 V_123 = V_28 -> V_37 . V_123 ;
if ( V_123 != V_141 )
F_8 ( F_62 ( V_123 ) ,
V_175 ) ;
}
static void F_65 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_26 * V_27 = V_4 -> V_27 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
struct V_28 * V_28 = F_17 ( V_27 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_7 ) {
struct V_60 * V_60 = F_29 ( V_4 ) ;
F_66 ( V_60 ) ;
F_67 ( V_60 ) ;
F_68 ( V_60 , true ) ;
}
F_40 ( V_28 -> V_41 == V_85 ) ;
F_8 ( F_22 ( V_1 ) , V_28 -> V_41 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_60 * V_60 = F_29 ( V_4 ) ;
F_69 ( V_60 , V_176 ) ;
F_70 ( V_60 ) ;
F_71 ( V_60 ) ;
if ( V_1 != V_24 )
F_72 ( V_60 ) ;
}
}
static void F_73 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_73 ;
bool V_177 = false ;
V_73 = F_14 ( F_12 ( V_1 ) ) ;
if ( V_73 & V_47 ) {
V_73 &= ~ V_47 ;
F_8 ( F_12 ( V_1 ) , V_73 ) ;
V_177 = true ;
}
V_73 = F_14 ( F_23 ( V_1 ) ) ;
V_73 &= ~ ( V_46 | V_55 ) ;
V_73 |= V_45 ;
F_8 ( F_23 ( V_1 ) , V_73 ) ;
if ( V_177 )
F_11 ( V_17 , V_1 ) ;
if ( type == V_7 ) {
struct V_60 * V_60 = F_29 ( V_4 ) ;
F_66 ( V_60 ) ;
F_74 ( V_60 ) ;
}
F_8 ( F_22 ( V_1 ) , V_85 ) ;
}
static void F_75 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_26 * V_27 = V_4 -> V_27 ;
struct V_28 * V_28 = F_17 ( V_27 ) ;
int V_56 = V_28 -> V_56 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_160 ;
if ( type == V_8 ) {
struct V_10 * V_11 =
F_2 ( V_4 ) ;
F_8 ( F_12 ( V_1 ) ,
V_11 -> V_62 |
V_47 ) ;
} else if ( type == V_7 ) {
struct V_60 * V_60 = F_29 ( V_4 ) ;
if ( V_1 == V_24 )
F_72 ( V_60 ) ;
F_76 ( V_60 ) ;
F_77 ( V_60 ) ;
}
if ( V_28 -> V_59 && type != V_7 ) {
V_160 = F_14 ( V_178 ) ;
V_160 |= ( ( V_179 | V_180 ) << ( V_56 * 4 ) ) ;
F_8 ( V_178 , V_160 ) ;
}
}
static void F_78 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_26 * V_27 = V_4 -> V_27 ;
struct V_28 * V_28 = F_17 ( V_27 ) ;
int V_56 = V_28 -> V_56 ;
int type = V_2 -> type ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
T_2 V_160 ;
if ( V_28 -> V_59 && type != V_7 ) {
V_160 = F_14 ( V_178 ) ;
V_160 &= ~ ( ( V_179 | V_180 ) <<
( V_56 * 4 ) ) ;
F_8 ( V_178 , V_160 ) ;
}
if ( type == V_7 ) {
struct V_60 * V_60 = F_29 ( V_4 ) ;
F_79 ( V_60 ) ;
F_80 ( V_60 ) ;
}
}
int F_81 ( struct V_16 * V_17 )
{
T_2 V_181 = F_14 ( V_182 ) ;
if ( V_181 & V_183 )
return 800000 ;
else if ( F_14 ( V_184 ) & V_185 )
return 450000 ;
else if ( ( V_181 & V_186 ) == V_187 )
return 450000 ;
else if ( F_82 ( V_17 -> V_15 ) )
return 337500 ;
else
return 540000 ;
}
void F_83 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
T_2 V_73 = F_14 ( V_182 ) ;
F_26 ( L_31 ,
F_81 ( V_17 ) ) ;
if ( V_73 & V_183 )
F_3 ( L_32 ) ;
if ( V_73 & V_188 )
F_3 ( L_33 ) ;
}
void F_84 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
struct V_60 * V_60 = & V_11 -> V_189 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
enum V_1 V_1 = V_11 -> V_1 ;
T_2 V_73 ;
bool V_177 = false ;
if ( F_14 ( F_23 ( V_1 ) ) & V_46 ) {
V_73 = F_14 ( F_12 ( V_1 ) ) ;
if ( V_73 & V_47 ) {
V_73 &= ~ V_47 ;
F_8 ( F_12 ( V_1 ) , V_73 ) ;
V_177 = true ;
}
V_73 = F_14 ( F_23 ( V_1 ) ) ;
V_73 &= ~ ( V_46 | V_55 ) ;
V_73 |= V_45 ;
F_8 ( F_23 ( V_1 ) , V_73 ) ;
F_21 ( F_23 ( V_1 ) ) ;
if ( V_177 )
F_11 ( V_17 , V_1 ) ;
}
V_73 = V_46 | V_190 |
V_45 | V_191 ;
if ( V_60 -> V_192 [ 1 ] & V_193 )
V_73 |= V_44 ;
F_8 ( F_23 ( V_1 ) , V_73 ) ;
F_21 ( F_23 ( V_1 ) ) ;
V_60 -> V_61 |= V_47 ;
F_8 ( F_12 ( V_1 ) , V_60 -> V_61 ) ;
F_21 ( F_12 ( V_1 ) ) ;
F_13 ( 600 ) ;
}
void F_85 ( struct V_26 * V_27 )
{
struct V_16 * V_17 = V_27 -> V_15 -> V_18 ;
struct V_2 * V_2 = F_35 ( V_27 ) ;
T_2 V_73 ;
F_73 ( V_2 ) ;
V_73 = F_14 ( V_39 ) ;
V_73 &= ~ V_49 ;
F_8 ( V_39 , V_73 ) ;
V_73 = F_14 ( V_31 ) ;
V_73 &= ~ ( V_51 | V_52 ) ;
V_73 |= F_18 ( 2 ) | F_19 ( 2 ) ;
F_8 ( V_31 , V_73 ) ;
V_73 = F_14 ( V_39 ) ;
V_73 &= ~ V_40 ;
F_8 ( V_39 , V_73 ) ;
V_73 = F_14 ( V_39 ) ;
V_73 &= ~ V_36 ;
F_8 ( V_39 , V_73 ) ;
}
static void F_86 ( struct V_2 * V_2 )
{
struct V_60 * V_60 = F_29 ( & V_2 -> V_5 ) ;
int type = V_2 -> type ;
if ( type == V_6 || type == V_7 )
F_87 ( V_60 ) ;
}
void F_88 ( struct V_2 * V_4 ,
struct V_194 * V_195 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_15 -> V_18 ;
struct V_28 * V_28 = F_17 ( V_4 -> V_5 . V_27 ) ;
enum V_122 V_123 = V_28 -> V_37 . V_123 ;
T_1 V_29 , V_136 = 0 ;
V_29 = F_14 ( F_53 ( V_123 ) ) ;
if ( V_29 & V_140 )
V_136 |= V_139 ;
else
V_136 |= V_196 ;
if ( V_29 & V_138 )
V_136 |= V_137 ;
else
V_136 |= V_197 ;
V_195 -> V_58 . V_136 |= V_136 ;
switch ( V_29 & V_198 ) {
case V_131 :
V_195 -> V_125 = 18 ;
break;
case V_132 :
V_195 -> V_125 = 24 ;
break;
case V_133 :
V_195 -> V_125 = 30 ;
break;
case V_134 :
V_195 -> V_125 = 36 ;
break;
default:
break;
}
}
static void F_89 ( struct V_3 * V_4 )
{
F_90 ( V_4 ) ;
}
static bool F_91 ( struct V_2 * V_4 ,
struct V_194 * V_195 )
{
int type = V_4 -> type ;
int V_1 = F_1 ( V_4 ) ;
F_37 ( type == V_9 , L_34 ) ;
if ( V_1 == V_24 )
V_195 -> V_123 = V_141 ;
if ( type == V_8 )
return F_92 ( V_4 , V_195 ) ;
else
return F_93 ( V_4 , V_195 ) ;
}
void F_94 ( struct V_14 * V_15 , enum V_1 V_1 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_10 * V_11 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
struct V_158 * V_199 = NULL ;
struct V_158 * V_200 = NULL ;
V_11 = F_95 ( sizeof( struct V_10 ) , V_201 ) ;
if ( ! V_11 )
return;
V_200 = F_95 ( sizeof( struct V_158 ) , V_201 ) ;
if ( ! V_200 ) {
F_96 ( V_11 ) ;
return;
}
V_2 = & V_11 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_97 ( V_15 , V_4 , & V_202 ,
V_203 ) ;
V_2 -> V_204 = F_91 ;
V_2 -> V_205 = F_27 ;
V_2 -> V_206 = F_75 ;
V_2 -> V_207 = F_65 ;
V_2 -> V_208 = F_78 ;
V_2 -> V_209 = F_73 ;
V_2 -> V_161 = F_56 ;
V_2 -> V_210 = F_88 ;
V_11 -> V_1 = V_1 ;
V_11 -> V_62 = F_14 ( F_12 ( V_1 ) ) &
( V_211 |
V_212 ) ;
V_11 -> V_189 . V_213 = F_12 ( V_1 ) ;
V_2 -> type = V_9 ;
V_2 -> V_214 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_215 = false ;
V_2 -> V_216 = F_86 ;
if ( ! F_98 ( V_11 , V_200 ) ) {
F_99 ( V_4 ) ;
F_96 ( V_11 ) ;
F_96 ( V_200 ) ;
return;
}
if ( V_2 -> type != V_7 ) {
V_199 = F_95 ( sizeof( struct V_158 ) ,
V_201 ) ;
if ( ! V_199 ) {
return;
}
V_11 -> V_217 . V_218 = F_12 ( V_1 ) ;
F_100 ( V_11 , V_199 ) ;
}
}
