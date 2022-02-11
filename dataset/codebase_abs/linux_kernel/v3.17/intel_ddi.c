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
int V_22 ;
int V_23 = V_19 -> V_24 . V_25 [ V_1 ] . V_26 ;
const T_1 * V_27 ;
const T_1 * V_28 ;
const T_1 * V_29 ;
const T_1 * V_30 ;
if ( F_7 ( V_17 ) ) {
V_27 = V_31 ;
V_28 = V_32 ;
V_29 = V_33 ;
} else if ( F_8 ( V_17 ) ) {
V_27 = V_34 ;
V_28 = V_35 ;
V_29 = V_35 ;
} else {
F_9 ( 1 , L_2 ) ;
V_29 = V_32 ;
V_27 = V_31 ;
V_28 = V_32 ;
}
switch ( V_1 ) {
case V_36 :
V_30 = V_29 ;
break;
case V_37 :
case V_38 :
V_30 = V_28 ;
break;
case V_39 :
if ( F_10 ( V_17 , V_39 ) )
V_30 = V_29 ;
else
V_30 = V_28 ;
break;
case V_15 :
V_30 = V_27 ;
break;
default:
F_5 () ;
}
for ( V_22 = 0 , V_21 = F_11 ( V_1 ) ;
V_22 < F_12 ( V_34 ) ; V_22 ++ ) {
F_13 ( V_21 , V_30 [ V_22 ] ) ;
V_21 += 4 ;
}
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
F_13 ( V_21 , V_40 [ V_23 * 2 + V_22 ] ) ;
V_21 += 4 ;
}
}
void F_14 ( struct V_16 * V_17 )
{
int V_1 ;
if ( ! F_15 ( V_17 ) )
return;
for ( V_1 = V_36 ; V_1 <= V_15 ; V_1 ++ )
F_6 ( V_17 , V_1 ) ;
}
static void F_16 ( struct V_18 * V_19 ,
enum V_1 V_1 )
{
T_2 V_21 = F_17 ( V_1 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
F_18 ( 1 ) ;
if ( F_19 ( V_21 ) & V_41 )
return;
}
F_4 ( L_3 , F_20 ( V_1 ) ) ;
}
void F_21 ( struct V_42 * V_43 )
{
struct V_16 * V_17 = V_43 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_44 * V_44 = F_22 ( V_43 ) ;
T_1 V_45 , V_22 , V_46 ;
F_13 ( V_47 , F_23 ( 2 ) |
F_24 ( 2 ) |
V_48 | V_49 ) ;
V_46 = V_19 -> V_50 | V_51 |
V_52 |
F_25 ( V_44 -> V_53 . V_54 ) ;
F_13 ( V_55 , V_46 ) ;
F_26 ( V_55 ) ;
F_18 ( 220 ) ;
V_46 |= V_56 ;
F_13 ( V_55 , V_46 ) ;
F_13 ( F_27 ( V_15 ) , V_44 -> V_53 . V_57 ) ;
F_28 ( V_44 -> V_53 . V_57 != V_58 ) ;
for ( V_22 = 0 ; V_22 < F_12 ( V_59 ) * 2 ; V_22 ++ ) {
F_13 ( F_29 ( V_15 ) ,
V_60 |
V_61 |
V_62 |
V_63 ) ;
F_13 ( F_17 ( V_15 ) ,
V_64 |
( ( V_44 -> V_53 . V_54 - 1 ) << 1 ) |
V_59 [ V_22 / 2 ] ) ;
F_26 ( F_17 ( V_15 ) ) ;
F_18 ( 600 ) ;
F_13 ( V_65 , F_30 ( 64 ) ) ;
V_46 |= V_66 | V_67 ;
F_13 ( V_55 , V_46 ) ;
F_26 ( V_55 ) ;
F_18 ( 30 ) ;
V_45 = F_19 ( V_47 ) ;
V_45 &= ~ ( V_68 | V_69 ) ;
F_13 ( V_47 , V_45 ) ;
F_26 ( V_47 ) ;
F_18 ( 5 ) ;
V_45 = F_19 ( F_31 ( V_15 ) ) ;
if ( V_45 & V_70 ) {
F_32 ( L_4 , V_22 ) ;
F_13 ( F_29 ( V_15 ) ,
V_60 |
V_71 |
V_61 |
V_63 ) ;
return;
}
V_45 = F_19 ( F_17 ( V_15 ) ) ;
V_45 &= ~ V_64 ;
F_13 ( F_17 ( V_15 ) , V_45 ) ;
F_26 ( F_17 ( V_15 ) ) ;
V_45 = F_19 ( F_29 ( V_15 ) ) ;
V_45 &= ~ ( V_63 | V_72 ) ;
V_45 |= V_62 ;
F_13 ( F_29 ( V_15 ) , V_45 ) ;
F_26 ( F_29 ( V_15 ) ) ;
F_16 ( V_19 , V_15 ) ;
V_46 &= ~ V_66 ;
F_13 ( V_55 , V_46 ) ;
F_26 ( V_55 ) ;
V_45 = F_19 ( V_47 ) ;
V_45 &= ~ ( V_68 | V_69 ) ;
V_45 |= F_23 ( 2 ) | F_24 ( 2 ) ;
F_13 ( V_47 , V_45 ) ;
F_26 ( V_47 ) ;
}
F_4 ( L_5 ) ;
}
void F_33 ( struct V_2 * V_4 )
{
struct V_73 * V_73 = F_34 ( & V_4 -> V_5 ) ;
struct V_7 * V_8 =
F_3 ( & V_4 -> V_5 ) ;
V_73 -> V_74 = V_8 -> V_75 |
V_64 | V_76 ;
V_73 -> V_74 |= F_35 ( V_73 -> V_77 ) ;
}
static struct V_2 *
F_36 ( struct V_42 * V_43 )
{
struct V_16 * V_17 = V_43 -> V_17 ;
struct V_44 * V_44 = F_22 ( V_43 ) ;
struct V_2 * V_2 , * V_78 = NULL ;
int V_79 = 0 ;
F_37 (dev, crtc, intel_encoder) {
V_78 = V_2 ;
V_79 ++ ;
}
if ( V_79 != 1 )
F_9 ( 1 , L_6 , V_79 ,
F_38 ( V_44 -> V_80 ) ) ;
F_39 ( V_78 == NULL ) ;
return V_78 ;
}
static unsigned F_40 ( int clock )
{
unsigned V_81 ;
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
V_81 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_81 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_81 = 2000 ;
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
V_81 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_81 = 5000 ;
break;
default:
V_81 = 1000 ;
break;
}
return V_81 ;
}
static void F_41 ( T_3 V_82 , unsigned V_81 ,
unsigned V_83 , unsigned V_84 , unsigned V_85 ,
struct V_86 * V_87 )
{
T_3 V_88 , V_89 , V_90 , V_91 , V_92 , V_93 ;
if ( V_87 -> V_85 == 0 ) {
V_87 -> V_85 = V_85 ;
V_87 -> V_84 = V_84 ;
V_87 -> V_83 = V_83 ;
return;
}
V_88 = V_82 * V_81 * V_85 * V_83 ;
V_89 = V_82 * V_81 * V_87 -> V_85 * V_87 -> V_83 ;
V_92 = F_42 ( ( V_82 * V_85 * V_83 ) , ( V_94 * V_84 ) ) ;
V_93 = F_42 ( ( V_82 * V_87 -> V_85 * V_87 -> V_83 ) ,
( V_94 * V_87 -> V_84 ) ) ;
V_90 = 1000000 * V_92 ;
V_91 = 1000000 * V_93 ;
if ( V_88 < V_90 && V_89 < V_91 ) {
if ( V_87 -> V_85 * V_87 -> V_83 * V_92 < V_85 * V_83 * V_93 ) {
V_87 -> V_85 = V_85 ;
V_87 -> V_84 = V_84 ;
V_87 -> V_83 = V_83 ;
}
} else if ( V_88 >= V_90 && V_89 < V_91 ) {
V_87 -> V_85 = V_85 ;
V_87 -> V_84 = V_84 ;
V_87 -> V_83 = V_83 ;
} else if ( V_88 >= V_90 && V_89 >= V_91 ) {
if ( V_84 * V_87 -> V_83 * V_87 -> V_83 > V_87 -> V_84 * V_83 * V_83 ) {
V_87 -> V_85 = V_85 ;
V_87 -> V_84 = V_84 ;
V_87 -> V_83 = V_83 ;
}
}
}
static int F_43 ( struct V_18 * V_19 ,
int V_21 )
{
int V_95 = V_96 ;
int V_97 , V_85 , V_98 ;
T_1 V_99 ;
V_99 = F_19 ( V_21 ) ;
switch ( V_99 & V_100 ) {
case V_101 :
case V_102 :
V_95 = 135 ;
break;
case V_103 :
V_95 = V_96 ;
break;
default:
F_9 ( 1 , L_7 ) ;
return 0 ;
}
V_98 = V_99 & V_104 ;
V_85 = ( V_99 & V_105 ) >> V_106 ;
V_97 = ( V_99 & V_107 ) >> V_108 ;
return ( V_95 * V_97 * 100 ) / ( V_85 * V_98 ) ;
}
void F_44 ( struct V_2 * V_4 ,
struct V_109 * V_110 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
int V_111 = 0 ;
T_1 V_112 , V_113 ;
V_112 = V_110 -> V_57 ;
switch ( V_112 & V_114 ) {
case V_115 :
V_111 = 81000 ;
break;
case V_116 :
V_111 = 135000 ;
break;
case V_117 :
V_111 = 270000 ;
break;
case V_118 :
V_111 = F_43 ( V_19 , V_119 ) ;
break;
case V_120 :
V_111 = F_43 ( V_19 , V_121 ) ;
break;
case V_58 :
V_113 = F_19 ( V_122 ) & V_123 ;
if ( V_113 == V_124 )
V_111 = 81000 ;
else if ( V_113 == V_125 )
V_111 = 135000 ;
else if ( V_113 == V_126 )
V_111 = 270000 ;
else {
F_9 ( 1 , L_8 ) ;
return;
}
break;
default:
F_9 ( 1 , L_9 ) ;
return;
}
V_110 -> V_127 = V_111 * 2 ;
if ( V_110 -> V_128 )
V_110 -> V_129 . V_130 =
F_45 ( V_110 -> V_127 ,
& V_110 -> V_131 ) ;
else if ( V_110 -> V_132 )
V_110 -> V_129 . V_130 =
F_45 ( V_110 -> V_127 ,
& V_110 -> V_133 ) ;
else
V_110 -> V_129 . V_130 = V_110 -> V_127 ;
}
static void
F_46 ( int clock ,
unsigned * V_134 , unsigned * V_135 , unsigned * V_136 )
{
T_3 V_82 ;
unsigned V_85 , V_84 , V_83 ;
struct V_86 V_87 = { 0 , 0 , 0 } ;
unsigned V_81 ;
V_82 = clock / 100 ;
V_81 = F_40 ( clock ) ;
if ( V_82 == 5400000 ) {
* V_135 = 2 ;
* V_136 = 1 ;
* V_134 = 2 ;
return;
}
for ( V_83 = V_96 * 2 / V_137 + 1 ;
V_83 <= V_96 * 2 / V_138 ;
V_83 ++ ) {
for ( V_84 = V_139 * V_83 / V_96 + 1 ;
V_84 <= V_140 * V_83 / V_96 ;
V_84 ++ ) {
for ( V_85 = V_141 ; V_85 <= V_142 ; V_85 += V_143 )
F_41 ( V_82 , V_81 ,
V_83 , V_84 , V_85 , & V_87 ) ;
}
}
* V_135 = V_87 . V_84 ;
* V_136 = V_87 . V_85 ;
* V_134 = V_87 . V_83 ;
}
bool F_47 ( struct V_44 * V_44 )
{
struct V_42 * V_43 = & V_44 -> V_5 ;
struct V_2 * V_2 = F_36 ( V_43 ) ;
int type = V_2 -> type ;
int clock = V_44 -> V_53 . V_127 ;
F_48 ( V_44 ) ;
if ( type == V_12 ) {
struct V_144 * V_113 ;
T_2 V_112 ;
unsigned V_85 , V_84 , V_83 ;
F_46 ( clock * 1000 , & V_83 , & V_84 , & V_85 ) ;
V_112 = V_145 | V_103 |
F_49 ( V_83 ) | F_50 ( V_84 ) |
F_51 ( V_85 ) ;
V_44 -> V_53 . V_146 . V_99 = V_112 ;
V_113 = F_52 ( V_44 ) ;
if ( V_113 == NULL ) {
F_53 ( L_10 ,
F_38 ( V_44 -> V_80 ) ) ;
return false ;
}
V_44 -> V_53 . V_57 = F_54 ( V_113 -> V_147 ) ;
}
return true ;
}
void F_55 ( struct V_42 * V_43 )
{
struct V_18 * V_19 = V_43 -> V_17 -> V_20 ;
struct V_44 * V_44 = F_22 ( V_43 ) ;
struct V_2 * V_2 = F_36 ( V_43 ) ;
enum V_148 V_149 = V_44 -> V_53 . V_149 ;
int type = V_2 -> type ;
T_2 V_45 ;
if ( type == V_10 || type == V_11 || type == V_6 ) {
V_45 = V_150 ;
switch ( V_44 -> V_53 . V_151 ) {
case 18 :
V_45 |= V_152 ;
break;
case 24 :
V_45 |= V_153 ;
break;
case 30 :
V_45 |= V_154 ;
break;
case 36 :
V_45 |= V_155 ;
break;
default:
F_5 () ;
}
F_13 ( F_56 ( V_149 ) , V_45 ) ;
}
}
void F_57 ( struct V_42 * V_43 , bool V_156 )
{
struct V_44 * V_44 = F_22 ( V_43 ) ;
struct V_16 * V_17 = V_43 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_148 V_149 = V_44 -> V_53 . V_149 ;
T_2 V_45 ;
V_45 = F_19 ( F_58 ( V_149 ) ) ;
if ( V_156 == true )
V_45 |= V_157 ;
else
V_45 &= ~ V_157 ;
F_13 ( F_58 ( V_149 ) , V_45 ) ;
}
void F_59 ( struct V_42 * V_43 )
{
struct V_44 * V_44 = F_22 ( V_43 ) ;
struct V_2 * V_2 = F_36 ( V_43 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_16 * V_17 = V_43 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_80 V_80 = V_44 -> V_80 ;
enum V_148 V_149 = V_44 -> V_53 . V_149 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_45 ;
V_45 = V_158 ;
V_45 |= F_60 ( V_1 ) ;
switch ( V_44 -> V_53 . V_151 ) {
case 18 :
V_45 |= V_159 ;
break;
case 24 :
V_45 |= V_160 ;
break;
case 30 :
V_45 |= V_161 ;
break;
case 36 :
V_45 |= V_162 ;
break;
default:
F_5 () ;
}
if ( V_44 -> V_53 . V_129 . V_163 & V_164 )
V_45 |= V_165 ;
if ( V_44 -> V_53 . V_129 . V_163 & V_166 )
V_45 |= V_167 ;
if ( V_149 == V_168 ) {
switch ( V_80 ) {
case V_169 :
if ( F_8 ( V_17 ) &&
( V_44 -> V_53 . V_170 . V_171 ||
V_44 -> V_53 . V_170 . V_172 ) )
V_45 |= V_173 ;
else
V_45 |= V_174 ;
break;
case V_175 :
V_45 |= V_176 ;
break;
case V_177 :
V_45 |= V_178 ;
break;
default:
F_5 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_44 -> V_53 . V_179 )
V_45 |= V_180 ;
else
V_45 |= V_181 ;
} else if ( type == V_14 ) {
V_45 |= V_182 ;
V_45 |= ( V_44 -> V_53 . V_54 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_73 * V_73 = F_34 ( V_4 ) ;
if ( V_73 -> V_183 ) {
V_45 |= V_184 ;
} else
V_45 |= V_185 ;
V_45 |= F_35 ( V_73 -> V_77 ) ;
} else if ( type == V_6 ) {
struct V_73 * V_73 = & F_2 ( V_4 ) -> V_9 -> V_186 ;
if ( V_73 -> V_183 ) {
V_45 |= V_184 ;
} else
V_45 |= V_185 ;
V_45 |= F_35 ( V_73 -> V_77 ) ;
} else {
F_9 ( 1 , L_11 ,
V_2 -> type , F_38 ( V_80 ) ) ;
}
F_13 ( F_58 ( V_149 ) , V_45 ) ;
}
void F_61 ( struct V_18 * V_19 ,
enum V_148 V_149 )
{
T_2 V_21 = F_58 ( V_149 ) ;
T_2 V_112 = F_19 ( V_21 ) ;
V_112 &= ~ ( V_158 | V_187 | V_157 ) ;
V_112 |= V_188 ;
F_13 ( V_21 , V_112 ) ;
}
bool F_62 ( struct V_189 * V_189 )
{
struct V_16 * V_17 = V_189 -> V_5 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_2 * V_2 = V_189 -> V_4 ;
int type = V_189 -> V_5 . V_190 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_80 V_80 = 0 ;
enum V_148 V_149 ;
enum V_191 V_192 ;
T_2 V_193 ;
V_192 = F_63 ( V_2 ) ;
if ( ! F_64 ( V_19 , V_192 ) )
return false ;
if ( ! V_2 -> V_194 ( V_2 , & V_80 ) )
return false ;
if ( V_1 == V_36 )
V_149 = V_168 ;
else
V_149 = (enum V_148 ) V_80 ;
V_193 = F_19 ( F_58 ( V_149 ) ) ;
switch ( V_193 & V_195 ) {
case V_180 :
case V_181 :
return ( type == V_196 ) ;
case V_185 :
if ( type == V_197 )
return true ;
return ( type == V_198 ) ;
case V_184 :
return false ;
case V_182 :
return ( type == V_199 ) ;
default:
return false ;
}
}
bool F_65 ( struct V_2 * V_4 ,
enum V_80 * V_80 )
{
struct V_16 * V_17 = V_4 -> V_5 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
enum V_191 V_192 ;
T_1 V_193 ;
int V_22 ;
V_192 = F_63 ( V_4 ) ;
if ( ! F_64 ( V_19 , V_192 ) )
return false ;
V_193 = F_19 ( F_17 ( V_1 ) ) ;
if ( ! ( V_193 & V_64 ) )
return false ;
if ( V_1 == V_36 ) {
V_193 = F_19 ( F_58 ( V_168 ) ) ;
switch ( V_193 & V_200 ) {
case V_174 :
case V_173 :
* V_80 = V_169 ;
break;
case V_176 :
* V_80 = V_175 ;
break;
case V_178 :
* V_80 = V_177 ;
break;
}
return true ;
} else {
for ( V_22 = V_201 ; V_22 <= V_202 ; V_22 ++ ) {
V_193 = F_19 ( F_58 ( V_22 ) ) ;
if ( ( V_193 & V_187 )
== F_60 ( V_1 ) ) {
if ( ( V_193 & V_195 ) == V_184 )
return false ;
* V_80 = V_22 ;
return true ;
}
}
}
F_32 ( L_12 , F_20 ( V_1 ) ) ;
return false ;
}
void F_66 ( struct V_44 * V_44 )
{
struct V_42 * V_43 = & V_44 -> V_5 ;
struct V_18 * V_19 = V_43 -> V_17 -> V_20 ;
struct V_2 * V_2 = F_36 ( V_43 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_148 V_149 = V_44 -> V_53 . V_149 ;
if ( V_149 != V_168 )
F_13 ( F_67 ( V_149 ) ,
F_68 ( V_1 ) ) ;
}
void F_69 ( struct V_44 * V_44 )
{
struct V_18 * V_19 = V_44 -> V_5 . V_17 -> V_20 ;
enum V_148 V_149 = V_44 -> V_53 . V_149 ;
if ( V_149 != V_168 )
F_13 ( F_67 ( V_149 ) ,
V_203 ) ;
}
static void F_70 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_18 * V_19 = V_4 -> V_17 -> V_20 ;
struct V_44 * V_43 = F_22 ( V_4 -> V_43 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( V_43 -> V_53 . V_204 ) {
F_53 ( L_13 ,
F_38 ( V_43 -> V_80 ) ) ;
F_53 ( L_14 ) ;
F_71 ( V_4 , & V_43 -> V_53 . V_129 ) ;
}
if ( type == V_11 ) {
struct V_73 * V_73 = F_34 ( V_4 ) ;
F_72 ( V_73 ) ;
}
F_28 ( V_43 -> V_53 . V_57 == V_205 ) ;
F_13 ( F_27 ( V_1 ) , V_43 -> V_53 . V_57 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_73 * V_73 = F_34 ( V_4 ) ;
F_33 ( V_2 ) ;
F_73 ( V_73 , V_206 ) ;
F_74 ( V_73 ) ;
F_75 ( V_73 ) ;
if ( V_1 != V_36 )
F_76 ( V_73 ) ;
} else if ( type == V_12 ) {
struct V_207 * V_207 = F_77 ( V_4 ) ;
V_207 -> V_208 ( V_4 ,
V_43 -> V_53 . V_179 ,
& V_43 -> V_53 . V_129 ) ;
}
}
static void F_78 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_18 * V_19 = V_4 -> V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_112 ;
bool V_209 = false ;
V_112 = F_19 ( F_17 ( V_1 ) ) ;
if ( V_112 & V_64 ) {
V_112 &= ~ V_64 ;
F_13 ( F_17 ( V_1 ) , V_112 ) ;
V_209 = true ;
}
V_112 = F_19 ( F_29 ( V_1 ) ) ;
V_112 &= ~ ( V_63 | V_72 ) ;
V_112 |= V_62 ;
F_13 ( F_29 ( V_1 ) , V_112 ) ;
if ( V_209 )
F_16 ( V_19 , V_1 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_73 * V_73 = F_34 ( V_4 ) ;
F_73 ( V_73 , V_210 ) ;
F_79 ( V_73 ) ;
F_80 ( V_73 ) ;
}
F_13 ( F_27 ( V_1 ) , V_205 ) ;
}
static void F_81 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_42 * V_43 = V_4 -> V_43 ;
struct V_44 * V_44 = F_22 ( V_43 ) ;
int V_80 = V_44 -> V_80 ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_193 ;
if ( type == V_12 ) {
struct V_7 * V_8 =
F_3 ( V_4 ) ;
F_13 ( F_17 ( V_1 ) ,
V_8 -> V_75 |
V_64 ) ;
} else if ( type == V_11 ) {
struct V_73 * V_73 = F_34 ( V_4 ) ;
if ( V_1 == V_36 )
F_76 ( V_73 ) ;
F_82 ( V_73 ) ;
F_83 ( V_73 ) ;
}
if ( V_44 -> V_53 . V_204 ) {
F_84 ( V_19 , V_211 ) ;
V_193 = F_19 ( V_212 ) ;
V_193 |= ( ( V_213 | V_214 ) << ( V_80 * 4 ) ) ;
F_13 ( V_212 , V_193 ) ;
}
}
static void F_85 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_42 * V_43 = V_4 -> V_43 ;
struct V_44 * V_44 = F_22 ( V_43 ) ;
int V_80 = V_44 -> V_80 ;
int type = V_2 -> type ;
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
T_2 V_193 ;
if ( V_44 -> V_53 . V_204 ) {
V_193 = F_19 ( V_212 ) ;
V_193 &= ~ ( ( V_213 | V_214 ) <<
( V_80 * 4 ) ) ;
F_13 ( V_212 , V_193 ) ;
F_86 ( V_19 , V_211 ) ;
}
if ( type == V_11 ) {
struct V_73 * V_73 = F_34 ( V_4 ) ;
F_87 ( V_73 ) ;
F_88 ( V_73 ) ;
}
}
int F_89 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_17 ;
T_2 V_215 = F_19 ( V_216 ) ;
T_2 V_217 = V_215 & V_218 ;
if ( V_215 & V_219 ) {
return 800000 ;
} else if ( F_19 ( V_220 ) & V_221 ) {
return 450000 ;
} else if ( V_217 == V_222 ) {
return 450000 ;
} else if ( F_8 ( V_17 ) ) {
if ( F_90 ( V_17 ) )
return 337500 ;
else
return 540000 ;
} else {
if ( V_217 == V_223 )
return 540000 ;
else if ( V_217 == V_224 )
return 337500 ;
else
return 675000 ;
}
}
static void F_91 ( struct V_18 * V_19 ,
struct V_144 * V_113 )
{
F_13 ( F_92 ( V_113 -> V_147 ) , V_113 -> V_225 . V_99 ) ;
F_26 ( F_92 ( V_113 -> V_147 ) ) ;
F_18 ( 20 ) ;
}
static void F_93 ( struct V_18 * V_19 ,
struct V_144 * V_113 )
{
T_2 V_112 ;
V_112 = F_19 ( F_92 ( V_113 -> V_147 ) ) ;
F_13 ( F_92 ( V_113 -> V_147 ) , V_112 & ~ V_145 ) ;
F_26 ( F_92 ( V_113 -> V_147 ) ) ;
}
static bool F_94 ( struct V_18 * V_19 ,
struct V_144 * V_113 ,
struct V_226 * V_225 )
{
T_2 V_112 ;
if ( ! F_64 ( V_19 , V_227 ) )
return false ;
V_112 = F_19 ( F_92 ( V_113 -> V_147 ) ) ;
V_225 -> V_99 = V_112 ;
return V_112 & V_145 ;
}
void F_95 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
T_2 V_112 = F_19 ( V_216 ) ;
int V_22 ;
V_19 -> V_228 = 2 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_228 ; V_22 ++ ) {
V_19 -> V_229 [ V_22 ] . V_147 = V_22 ;
V_19 -> V_229 [ V_22 ] . V_230 = V_231 [ V_22 ] ;
V_19 -> V_229 [ V_22 ] . V_232 = F_93 ;
V_19 -> V_229 [ V_22 ] . V_233 = F_91 ;
V_19 -> V_229 [ V_22 ] . V_194 =
F_94 ;
}
F_32 ( L_15 ,
F_89 ( V_19 ) ) ;
if ( V_112 & V_219 )
F_4 ( L_16 ) ;
if ( V_112 & V_234 )
F_4 ( L_17 ) ;
}
void F_96 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_73 * V_73 = & V_8 -> V_186 ;
struct V_18 * V_19 = V_4 -> V_17 -> V_20 ;
enum V_1 V_1 = V_8 -> V_1 ;
T_2 V_112 ;
bool V_209 = false ;
if ( F_19 ( F_29 ( V_1 ) ) & V_63 ) {
V_112 = F_19 ( F_17 ( V_1 ) ) ;
if ( V_112 & V_64 ) {
V_112 &= ~ V_64 ;
F_13 ( F_17 ( V_1 ) , V_112 ) ;
V_209 = true ;
}
V_112 = F_19 ( F_29 ( V_1 ) ) ;
V_112 &= ~ ( V_63 | V_72 ) ;
V_112 |= V_62 ;
F_13 ( F_29 ( V_1 ) , V_112 ) ;
F_26 ( F_29 ( V_1 ) ) ;
if ( V_209 )
F_16 ( V_19 , V_1 ) ;
}
V_112 = V_63 |
V_62 | V_235 ;
if ( V_73 -> V_183 )
V_112 |= V_236 ;
else {
V_112 |= V_237 ;
if ( F_97 ( V_73 -> V_238 ) )
V_112 |= V_61 ;
}
F_13 ( F_29 ( V_1 ) , V_112 ) ;
F_26 ( F_29 ( V_1 ) ) ;
V_73 -> V_74 |= V_64 ;
F_13 ( F_17 ( V_1 ) , V_73 -> V_74 ) ;
F_26 ( F_17 ( V_1 ) ) ;
F_18 ( 600 ) ;
}
void F_98 ( struct V_42 * V_43 )
{
struct V_18 * V_19 = V_43 -> V_17 -> V_20 ;
struct V_2 * V_2 = F_36 ( V_43 ) ;
T_2 V_112 ;
F_78 ( V_2 ) ;
V_112 = F_19 ( V_55 ) ;
V_112 &= ~ V_66 ;
F_13 ( V_55 , V_112 ) ;
V_112 = F_19 ( V_47 ) ;
V_112 &= ~ ( V_68 | V_69 ) ;
V_112 |= F_23 ( 2 ) | F_24 ( 2 ) ;
F_13 ( V_47 , V_112 ) ;
V_112 = F_19 ( V_55 ) ;
V_112 &= ~ V_56 ;
F_13 ( V_55 , V_112 ) ;
V_112 = F_19 ( V_55 ) ;
V_112 &= ~ V_52 ;
F_13 ( V_55 , V_112 ) ;
}
static void F_99 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_3 ( & V_2 -> V_5 ) ;
int type = V_8 -> V_5 . type ;
if ( type != V_10 &&
type != V_11 &&
type != V_13 ) {
return;
}
F_100 ( V_2 ) ;
}
void F_101 ( struct V_2 * V_4 ,
struct V_109 * V_110 )
{
struct V_18 * V_19 = V_4 -> V_5 . V_17 -> V_20 ;
struct V_44 * V_44 = F_22 ( V_4 -> V_5 . V_43 ) ;
enum V_148 V_149 = V_44 -> V_53 . V_149 ;
T_1 V_45 , V_163 = 0 ;
V_45 = F_19 ( F_58 ( V_149 ) ) ;
if ( V_45 & V_167 )
V_163 |= V_166 ;
else
V_163 |= V_239 ;
if ( V_45 & V_165 )
V_163 |= V_164 ;
else
V_163 |= V_240 ;
V_110 -> V_129 . V_163 |= V_163 ;
switch ( V_45 & V_241 ) {
case V_159 :
V_110 -> V_151 = 18 ;
break;
case V_160 :
V_110 -> V_151 = 24 ;
break;
case V_161 :
V_110 -> V_151 = 30 ;
break;
case V_162 :
V_110 -> V_151 = 36 ;
break;
default:
break;
}
switch ( V_45 & V_195 ) {
case V_180 :
V_110 -> V_179 = true ;
case V_181 :
case V_182 :
break;
case V_185 :
case V_184 :
V_110 -> V_132 = true ;
F_102 ( V_44 , V_110 ) ;
break;
default:
break;
}
if ( F_64 ( V_19 , V_211 ) ) {
V_45 = F_19 ( V_212 ) ;
if ( V_45 & ( V_213 << ( V_44 -> V_80 * 4 ) ) )
V_110 -> V_204 = true ;
}
if ( V_4 -> type == V_11 && V_19 -> V_24 . V_242 &&
V_110 -> V_151 > V_19 -> V_24 . V_242 ) {
F_32 ( L_18 ,
V_110 -> V_151 , V_19 -> V_24 . V_242 ) ;
V_19 -> V_24 . V_242 = V_110 -> V_151 ;
}
F_44 ( V_4 , V_110 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
F_104 ( V_4 ) ;
}
static bool F_105 ( struct V_2 * V_4 ,
struct V_109 * V_110 )
{
int type = V_4 -> type ;
int V_1 = F_1 ( V_4 ) ;
F_9 ( type == V_13 , L_19 ) ;
if ( V_1 == V_36 )
V_110 -> V_149 = V_168 ;
if ( type == V_12 )
return F_106 ( V_4 , V_110 ) ;
else
return F_107 ( V_4 , V_110 ) ;
}
static struct V_189 *
F_108 ( struct V_7 * V_8 )
{
struct V_189 * V_243 ;
enum V_1 V_1 = V_8 -> V_1 ;
V_243 = F_109 ( sizeof( * V_243 ) , V_244 ) ;
if ( ! V_243 )
return NULL ;
V_8 -> V_186 . V_245 = F_17 ( V_1 ) ;
if ( ! F_110 ( V_8 , V_243 ) ) {
F_111 ( V_243 ) ;
return NULL ;
}
return V_243 ;
}
static struct V_189 *
F_112 ( struct V_7 * V_8 )
{
struct V_189 * V_243 ;
enum V_1 V_1 = V_8 -> V_1 ;
V_243 = F_109 ( sizeof( * V_243 ) , V_244 ) ;
if ( ! V_243 )
return NULL ;
V_8 -> V_246 . V_247 = F_17 ( V_1 ) ;
F_113 ( V_8 , V_243 ) ;
return V_243 ;
}
void F_114 ( struct V_16 * V_17 , enum V_1 V_1 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_7 * V_8 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
bool V_248 , V_249 ;
V_248 = ( V_19 -> V_24 . V_25 [ V_1 ] . V_250 ||
V_19 -> V_24 . V_25 [ V_1 ] . V_251 ) ;
V_249 = V_19 -> V_24 . V_25 [ V_1 ] . V_252 ;
if ( ! V_249 && ! V_248 ) {
F_32 ( L_20 ,
F_20 ( V_1 ) ) ;
V_248 = true ;
V_249 = true ;
}
V_8 = F_109 ( sizeof( * V_8 ) , V_244 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_115 ( V_17 , V_4 , & V_253 ,
V_254 ) ;
V_2 -> V_255 = F_105 ;
V_2 -> V_233 = F_81 ;
V_2 -> V_256 = F_70 ;
V_2 -> V_232 = F_85 ;
V_2 -> V_257 = F_78 ;
V_2 -> V_194 = F_65 ;
V_2 -> V_258 = F_101 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_75 = F_19 ( F_17 ( V_1 ) ) &
( V_259 |
V_260 ) ;
V_2 -> type = V_13 ;
V_2 -> V_261 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_262 = 0 ;
V_2 -> V_263 = F_99 ;
if ( V_249 ) {
if ( ! F_108 ( V_8 ) )
goto V_264;
V_8 -> V_265 = V_266 ;
V_19 -> V_267 [ V_1 ] = V_8 ;
}
if ( V_2 -> type != V_11 && V_248 ) {
if ( ! F_112 ( V_8 ) )
goto V_264;
}
return;
V_264:
F_116 ( V_4 ) ;
F_111 ( V_8 ) ;
}
