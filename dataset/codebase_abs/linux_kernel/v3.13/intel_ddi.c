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
static void
F_46 ( int clock ,
unsigned * V_114 , unsigned * V_115 , unsigned * V_116 )
{
T_3 V_101 ;
unsigned V_104 , V_103 , V_102 ;
struct V_105 V_106 = { 0 , 0 , 0 } ;
unsigned V_100 ;
V_101 = clock / 100 ;
V_100 = F_43 ( clock ) ;
if ( V_101 == 5400000 ) {
* V_115 = 2 ;
* V_116 = 1 ;
* V_114 = 2 ;
return;
}
for ( V_102 = V_117 * 2 / V_118 + 1 ;
V_102 <= V_117 * 2 / V_119 ;
V_102 ++ ) {
for ( V_103 = V_120 * V_102 / V_117 + 1 ;
V_103 <= V_121 * V_102 / V_117 ;
V_103 ++ ) {
for ( V_104 = V_122 ; V_104 <= V_123 ; V_104 += V_124 )
F_44 ( V_101 , V_100 ,
V_102 , V_103 , V_104 , & V_106 ) ;
}
}
* V_115 = V_106 . V_103 ;
* V_116 = V_106 . V_104 ;
* V_114 = V_106 . V_102 ;
F_30 ( L_18 ,
clock , * V_116 , * V_115 , * V_114 ) ;
}
bool F_47 ( struct V_40 * V_41 )
{
struct V_42 * V_42 = F_21 ( V_41 ) ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_84 * V_85 = & V_17 -> V_86 ;
int type = V_2 -> type ;
enum V_70 V_70 = V_42 -> V_70 ;
T_2 V_19 , V_87 ;
int clock = V_42 -> V_51 . V_125 ;
F_41 ( V_41 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
switch ( V_74 -> V_126 ) {
case V_127 :
V_42 -> V_55 = V_128 ;
break;
case V_129 :
V_42 -> V_55 = V_130 ;
break;
case V_131 :
V_42 -> V_55 = V_132 ;
break;
default:
F_3 ( L_19 ,
V_74 -> V_126 ) ;
return false ;
}
return true ;
} else if ( type == V_8 ) {
unsigned V_104 , V_103 , V_102 ;
if ( V_85 -> V_93 == 0 ) {
F_30 ( L_20 ,
F_32 ( V_70 ) ) ;
V_85 -> V_93 ++ ;
V_19 = V_94 ;
V_42 -> V_55 = V_92 ;
} else if ( V_85 -> V_97 == 0 ) {
F_30 ( L_21 ,
F_32 ( V_70 ) ) ;
V_85 -> V_97 ++ ;
V_19 = V_98 ;
V_42 -> V_55 = V_96 ;
} else {
F_3 ( L_22 ) ;
return false ;
}
F_8 ( F_18 ( V_19 ) & V_95 ,
L_23 ) ;
F_46 ( clock * 1000 , & V_102 , & V_103 , & V_104 ) ;
V_87 = V_95 | V_133 |
F_48 ( V_102 ) | F_49 ( V_103 ) |
F_50 ( V_104 ) ;
} else if ( type == V_12 ) {
if ( V_85 -> V_89 == 0 ) {
F_30 ( L_24 ,
F_32 ( V_70 ) ) ;
V_85 -> V_89 ++ ;
V_19 = V_90 ;
V_42 -> V_55 = V_88 ;
} else {
F_3 ( L_25 ) ;
return false ;
}
F_8 ( F_18 ( V_19 ) & V_91 ,
L_26 ) ;
V_87 = V_91 | V_134 | V_135 ;
} else {
F_8 ( 1 , L_1 , type ) ;
return false ;
}
F_12 ( V_19 , V_87 ) ;
F_17 ( 20 ) ;
return true ;
}
void F_51 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
enum V_136 V_137 = V_42 -> V_51 . V_137 ;
int type = V_2 -> type ;
T_2 V_43 ;
if ( type == V_6 || type == V_7 ) {
V_43 = V_138 ;
switch ( V_42 -> V_51 . V_139 ) {
case 18 :
V_43 |= V_140 ;
break;
case 24 :
V_43 |= V_141 ;
break;
case 30 :
V_43 |= V_142 ;
break;
case 36 :
V_43 |= V_143 ;
break;
default:
F_4 () ;
}
F_12 ( F_52 ( V_137 ) , V_43 ) ;
}
}
void F_53 ( struct V_40 * V_41 )
{
struct V_42 * V_42 = F_21 ( V_41 ) ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_14 * V_15 = V_41 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_70 V_70 = V_42 -> V_70 ;
enum V_136 V_137 = V_42 -> V_51 . V_137 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_43 ;
V_43 = V_144 ;
V_43 |= F_54 ( V_1 ) ;
switch ( V_42 -> V_51 . V_139 ) {
case 18 :
V_43 |= V_145 ;
break;
case 24 :
V_43 |= V_146 ;
break;
case 30 :
V_43 |= V_147 ;
break;
case 36 :
V_43 |= V_148 ;
break;
default:
F_4 () ;
}
if ( V_42 -> V_51 . V_72 . V_149 & V_150 )
V_43 |= V_151 ;
if ( V_42 -> V_51 . V_72 . V_149 & V_152 )
V_43 |= V_153 ;
if ( V_137 == V_154 ) {
switch ( V_70 ) {
case V_155 :
if ( F_7 ( V_15 ) && V_42 -> V_51 . V_156 . V_157 )
V_43 |= V_158 ;
else
V_43 |= V_159 ;
break;
case V_160 :
V_43 |= V_161 ;
break;
case V_162 :
V_43 |= V_163 ;
break;
default:
F_4 () ;
break;
}
}
if ( type == V_8 ) {
struct V_80 * V_80 = F_37 ( V_4 ) ;
if ( V_80 -> V_164 )
V_43 |= V_165 ;
else
V_43 |= V_166 ;
} else if ( type == V_12 ) {
V_43 |= V_167 ;
V_43 |= ( V_42 -> V_51 . V_52 - 1 ) << 1 ;
} else if ( type == V_6 ||
type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
V_43 |= V_168 ;
V_43 |= F_34 ( V_74 -> V_78 ) ;
} else {
F_8 ( 1 , L_27 ,
V_2 -> type , F_32 ( V_70 ) ) ;
}
F_12 ( F_55 ( V_137 ) , V_43 ) ;
}
void F_56 ( struct V_16 * V_17 ,
enum V_136 V_137 )
{
T_2 V_19 = F_55 ( V_137 ) ;
T_2 V_87 = F_18 ( V_19 ) ;
V_87 &= ~ ( V_144 | V_169 ) ;
V_87 |= V_170 ;
F_12 ( V_19 , V_87 ) ;
}
bool F_57 ( struct V_171 * V_171 )
{
struct V_14 * V_15 = V_171 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_2 * V_2 = V_171 -> V_4 ;
int type = V_171 -> V_5 . V_172 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_70 V_70 = 0 ;
enum V_136 V_137 ;
T_2 V_173 ;
if ( ! V_2 -> V_174 ( V_2 , & V_70 ) )
return false ;
if ( V_1 == V_34 )
V_137 = V_154 ;
else
V_137 = (enum V_136 ) V_70 ;
V_173 = F_18 ( F_55 ( V_137 ) ) ;
switch ( V_173 & V_175 ) {
case V_165 :
case V_166 :
return ( type == V_176 ) ;
case V_168 :
if ( type == V_177 )
return true ;
case V_178 :
return ( type == V_179 ) ;
case V_167 :
return ( type == V_180 ) ;
default:
return false ;
}
}
bool F_58 ( struct V_2 * V_4 ,
enum V_70 * V_70 )
{
struct V_14 * V_15 = V_4 -> V_5 . V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
T_1 V_173 ;
int V_20 ;
V_173 = F_18 ( F_16 ( V_1 ) ) ;
if ( ! ( V_173 & V_61 ) )
return false ;
if ( V_1 == V_34 ) {
V_173 = F_18 ( F_55 ( V_154 ) ) ;
switch ( V_173 & V_181 ) {
case V_159 :
case V_158 :
* V_70 = V_155 ;
break;
case V_161 :
* V_70 = V_160 ;
break;
case V_163 :
* V_70 = V_162 ;
break;
}
return true ;
} else {
for ( V_20 = V_182 ; V_20 <= V_183 ; V_20 ++ ) {
V_173 = F_18 ( F_55 ( V_20 ) ) ;
if ( ( V_173 & V_169 )
== F_54 ( V_1 ) ) {
* V_70 = V_20 ;
return true ;
}
}
}
F_30 ( L_28 , F_19 ( V_1 ) ) ;
return false ;
}
static T_2 F_59 ( struct V_16 * V_17 ,
enum V_70 V_70 )
{
T_2 V_43 , V_82 ;
enum V_1 V_1 = V_184 ;
enum V_136 V_137 = F_60 ( V_17 ,
V_70 ) ;
int V_20 ;
if ( V_137 == V_154 ) {
V_1 = V_34 ;
} else {
V_43 = F_18 ( F_55 ( V_137 ) ) ;
V_43 &= V_169 ;
for ( V_20 = V_35 ; V_20 <= V_13 ; V_20 ++ )
if ( V_43 == F_54 ( V_20 ) )
V_1 = V_20 ;
}
if ( V_1 == V_184 ) {
F_8 ( 1 , L_29 ,
F_32 ( V_70 ) ) ;
V_82 = V_99 ;
} else {
V_82 = F_18 ( F_26 ( V_1 ) ) ;
F_30 ( L_30
L_31 , F_32 ( V_70 ) , F_19 ( V_1 ) ,
V_82 ) ;
}
return V_82 ;
}
void F_61 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_70 V_70 ;
struct V_42 * V_42 ;
V_17 -> V_86 . V_89 = 0 ;
V_17 -> V_86 . V_93 = 0 ;
V_17 -> V_86 . V_97 = 0 ;
F_62 (pipe) {
V_42 =
F_21 ( V_17 -> V_185 [ V_70 ] ) ;
if ( ! V_42 -> V_186 ) {
V_42 -> V_55 = V_99 ;
continue;
}
V_42 -> V_55 = F_59 ( V_17 ,
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
void F_63 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = & V_42 -> V_5 ;
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_136 V_137 = V_42 -> V_51 . V_137 ;
if ( V_137 != V_154 )
F_12 ( F_64 ( V_137 ) ,
F_65 ( V_1 ) ) ;
}
void F_66 ( struct V_42 * V_42 )
{
struct V_16 * V_17 = V_42 -> V_5 . V_15 -> V_18 ;
enum V_136 V_137 = V_42 -> V_51 . V_137 ;
if ( V_137 != V_154 )
F_12 ( F_64 ( V_137 ) ,
V_187 ) ;
}
static void F_67 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
F_68 ( V_74 ) ;
F_69 ( V_74 ) ;
F_70 ( V_74 , true ) ;
}
F_42 ( V_42 -> V_55 == V_99 ) ;
F_12 ( F_26 ( V_1 ) , V_42 -> V_55 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
F_71 ( V_74 , V_188 ) ;
F_72 ( V_74 ) ;
F_73 ( V_74 ) ;
if ( V_1 != V_34 )
F_74 ( V_74 ) ;
}
}
static void F_75 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_87 ;
bool V_189 = false ;
V_87 = F_18 ( F_16 ( V_1 ) ) ;
if ( V_87 & V_61 ) {
V_87 &= ~ V_61 ;
F_12 ( F_16 ( V_1 ) , V_87 ) ;
V_189 = true ;
}
V_87 = F_18 ( F_27 ( V_1 ) ) ;
V_87 &= ~ ( V_60 | V_69 ) ;
V_87 |= V_59 ;
F_12 ( F_27 ( V_1 ) , V_87 ) ;
if ( V_189 )
F_15 ( V_17 , V_1 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
F_68 ( V_74 ) ;
F_71 ( V_74 , V_190 ) ;
F_76 ( V_74 ) ;
}
F_12 ( F_26 ( V_1 ) , V_99 ) ;
}
static void F_77 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
int V_70 = V_42 -> V_70 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_173 ;
if ( type == V_8 ) {
struct V_10 * V_11 =
F_2 ( V_4 ) ;
F_12 ( F_16 ( V_1 ) ,
V_11 -> V_76 |
V_61 ) ;
} else if ( type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
if ( V_1 == V_34 )
F_74 ( V_74 ) ;
F_78 ( V_74 ) ;
F_79 ( V_74 ) ;
}
if ( V_42 -> V_73 && type != V_7 ) {
V_173 = F_18 ( V_191 ) ;
V_173 |= ( ( V_192 | V_193 ) << ( V_70 * 4 ) ) ;
F_12 ( V_191 , V_173 ) ;
}
}
static void F_80 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_42 * V_42 = F_21 ( V_41 ) ;
int V_70 = V_42 -> V_70 ;
int type = V_2 -> type ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
T_2 V_173 ;
if ( V_42 -> V_73 && type != V_7 ) {
V_173 = F_18 ( V_191 ) ;
V_173 &= ~ ( ( V_192 | V_193 ) <<
( V_70 * 4 ) ) ;
F_12 ( V_191 , V_173 ) ;
}
if ( type == V_7 ) {
struct V_74 * V_74 = F_33 ( V_4 ) ;
F_81 ( V_74 ) ;
F_82 ( V_74 ) ;
}
}
int F_83 ( struct V_16 * V_17 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
T_2 V_194 = F_18 ( V_195 ) ;
T_2 V_196 = V_194 & V_197 ;
if ( V_194 & V_198 ) {
return 800000 ;
} else if ( F_18 ( V_199 ) & V_200 ) {
return 450000 ;
} else if ( V_196 == V_201 ) {
return 450000 ;
} else if ( F_7 ( V_15 ) ) {
if ( F_84 ( V_15 ) )
return 337500 ;
else
return 540000 ;
} else {
if ( V_196 == V_202 )
return 540000 ;
else if ( V_196 == V_203 )
return 337500 ;
else
return 675000 ;
}
}
void F_85 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
T_2 V_87 = F_18 ( V_195 ) ;
F_30 ( L_32 ,
F_83 ( V_17 ) ) ;
if ( V_87 & V_198 )
F_3 ( L_33 ) ;
if ( V_87 & V_204 )
F_3 ( L_34 ) ;
}
void F_86 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
struct V_74 * V_74 = & V_11 -> V_205 ;
struct V_16 * V_17 = V_4 -> V_15 -> V_18 ;
enum V_1 V_1 = V_11 -> V_1 ;
T_2 V_87 ;
bool V_189 = false ;
if ( F_18 ( F_27 ( V_1 ) ) & V_60 ) {
V_87 = F_18 ( F_16 ( V_1 ) ) ;
if ( V_87 & V_61 ) {
V_87 &= ~ V_61 ;
F_12 ( F_16 ( V_1 ) , V_87 ) ;
V_189 = true ;
}
V_87 = F_18 ( F_27 ( V_1 ) ) ;
V_87 &= ~ ( V_60 | V_69 ) ;
V_87 |= V_59 ;
F_12 ( F_27 ( V_1 ) , V_87 ) ;
F_25 ( F_27 ( V_1 ) ) ;
if ( V_189 )
F_15 ( V_17 , V_1 ) ;
}
V_87 = V_60 | V_206 |
V_59 | V_207 ;
if ( F_87 ( V_74 -> V_208 ) )
V_87 |= V_58 ;
F_12 ( F_27 ( V_1 ) , V_87 ) ;
F_25 ( F_27 ( V_1 ) ) ;
V_74 -> V_75 |= V_61 ;
F_12 ( F_16 ( V_1 ) , V_74 -> V_75 ) ;
F_25 ( F_16 ( V_1 ) ) ;
F_17 ( 600 ) ;
}
void F_88 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_15 -> V_18 ;
struct V_2 * V_2 = F_38 ( V_41 ) ;
T_2 V_87 ;
F_75 ( V_2 ) ;
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
static void F_89 ( struct V_2 * V_2 )
{
struct V_74 * V_74 = F_33 ( & V_2 -> V_5 ) ;
int type = V_2 -> type ;
if ( type == V_6 || type == V_7 )
F_90 ( V_74 ) ;
}
void F_91 ( struct V_2 * V_4 ,
struct V_209 * V_210 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_15 -> V_18 ;
struct V_42 * V_42 = F_21 ( V_4 -> V_5 . V_41 ) ;
enum V_136 V_137 = V_42 -> V_51 . V_137 ;
T_1 V_43 , V_149 = 0 ;
V_43 = F_18 ( F_55 ( V_137 ) ) ;
if ( V_43 & V_153 )
V_149 |= V_152 ;
else
V_149 |= V_211 ;
if ( V_43 & V_151 )
V_149 |= V_150 ;
else
V_149 |= V_212 ;
V_210 -> V_72 . V_149 |= V_149 ;
switch ( V_43 & V_213 ) {
case V_145 :
V_210 -> V_139 = 18 ;
break;
case V_146 :
V_210 -> V_139 = 24 ;
break;
case V_147 :
V_210 -> V_139 = 30 ;
break;
case V_148 :
V_210 -> V_139 = 36 ;
break;
default:
break;
}
switch ( V_43 & V_175 ) {
case V_165 :
case V_166 :
case V_167 :
break;
case V_168 :
case V_178 :
V_210 -> V_214 = true ;
F_92 ( V_42 , V_210 ) ;
break;
default:
break;
}
if ( V_4 -> type == V_7 && V_17 -> V_22 . V_215 &&
V_210 -> V_139 > V_17 -> V_22 . V_215 ) {
F_30 ( L_35 ,
V_210 -> V_139 , V_17 -> V_22 . V_215 ) ;
V_17 -> V_22 . V_215 = V_210 -> V_139 ;
}
}
static void F_93 ( struct V_3 * V_4 )
{
F_94 ( V_4 ) ;
}
static bool F_95 ( struct V_2 * V_4 ,
struct V_209 * V_210 )
{
int type = V_4 -> type ;
int V_1 = F_1 ( V_4 ) ;
F_8 ( type == V_9 , L_36 ) ;
if ( V_1 == V_34 )
V_210 -> V_137 = V_154 ;
if ( type == V_8 )
return F_96 ( V_4 , V_210 ) ;
else
return F_97 ( V_4 , V_210 ) ;
}
static struct V_171 *
F_98 ( struct V_10 * V_11 )
{
struct V_171 * V_216 ;
enum V_1 V_1 = V_11 -> V_1 ;
V_216 = F_99 ( sizeof( * V_216 ) , V_217 ) ;
if ( ! V_216 )
return NULL ;
V_11 -> V_205 . V_218 = F_16 ( V_1 ) ;
if ( ! F_100 ( V_11 , V_216 ) ) {
F_101 ( V_216 ) ;
return NULL ;
}
return V_216 ;
}
static struct V_171 *
F_102 ( struct V_10 * V_11 )
{
struct V_171 * V_216 ;
enum V_1 V_1 = V_11 -> V_1 ;
V_216 = F_99 ( sizeof( * V_216 ) , V_217 ) ;
if ( ! V_216 )
return NULL ;
V_11 -> V_219 . V_220 = F_16 ( V_1 ) ;
F_103 ( V_11 , V_216 ) ;
return V_216 ;
}
void F_104 ( struct V_14 * V_15 , enum V_1 V_1 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_10 * V_11 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
struct V_171 * V_221 = NULL ;
struct V_171 * V_222 = NULL ;
bool V_223 , V_224 ;
V_223 = ( V_17 -> V_22 . V_23 [ V_1 ] . V_225 ||
V_17 -> V_22 . V_23 [ V_1 ] . V_226 ) ;
V_224 = V_17 -> V_22 . V_23 [ V_1 ] . V_227 ;
if ( ! V_224 && ! V_223 ) {
F_30 ( L_37 ,
F_19 ( V_1 ) ) ;
V_223 = true ;
V_224 = true ;
}
V_11 = F_99 ( sizeof( * V_11 ) , V_217 ) ;
if ( ! V_11 )
return;
V_2 = & V_11 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_105 ( V_15 , V_4 , & V_228 ,
V_229 ) ;
V_2 -> V_230 = F_95 ;
V_2 -> V_231 = F_31 ;
V_2 -> V_232 = F_77 ;
V_2 -> V_233 = F_67 ;
V_2 -> V_234 = F_80 ;
V_2 -> V_235 = F_75 ;
V_2 -> V_174 = F_58 ;
V_2 -> V_236 = F_91 ;
V_11 -> V_1 = V_1 ;
V_11 -> V_76 = F_18 ( F_16 ( V_1 ) ) &
( V_237 |
V_238 ) ;
V_2 -> type = V_9 ;
V_2 -> V_239 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_240 = false ;
V_2 -> V_241 = F_89 ;
if ( V_224 )
V_222 = F_98 ( V_11 ) ;
if ( V_2 -> type != V_7 && V_223 )
V_221 = F_102 ( V_11 ) ;
if ( ! V_222 && ! V_221 ) {
F_106 ( V_4 ) ;
F_101 ( V_11 ) ;
}
}
