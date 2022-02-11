static inline unsigned F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
default:
return 0 ;
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
}
}
static inline unsigned F_2 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
default:
return 0 ;
case V_4 :
return V_8 ;
case V_6 :
return V_9 ;
}
}
static inline unsigned F_3 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
default:
return 0 ;
case V_4 :
return V_10 ;
case V_6 :
return V_11 ;
}
}
static inline unsigned F_4 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
default:
return 0 ;
case V_4 :
return V_12 ;
case V_6 :
return V_13 ;
}
}
static bool F_5 ( const struct V_14 * V_15 )
{
switch ( V_15 -> V_2 ) {
case V_3 :
default:
return false ;
case V_4 :
case V_6 :
return true ;
}
}
static void F_6 ( struct V_16 * V_17 )
{
unsigned V_18 = V_17 -> V_19 ;
F_7 ( V_17 , F_8 ( V_18 ) , F_9 ( V_18 ) ) ;
}
static T_1 F_10 ( const struct V_16 * V_17 ,
unsigned V_20 )
{
T_1 V_21 ;
switch ( V_20 & V_22 ) {
case V_23 :
V_21 = 50000 ;
break;
case V_24 :
V_21 = 10000000 ;
break;
case V_25 :
V_21 = 12500 ;
break;
case V_26 :
V_21 = 100000 ;
break;
default:
return V_17 -> V_21 ;
}
switch ( V_20 & V_27 ) {
case V_28 :
break;
case V_29 :
V_21 *= 2 ;
break;
case V_30 :
V_21 *= 8 ;
break;
default:
F_11 () ;
break;
}
return V_21 ;
}
static unsigned F_12 ( const struct V_16 * V_17 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
const unsigned V_31 =
F_13 ( V_17 , F_14 ( V_18 ) ) ;
unsigned V_32 = 0 ;
if ( F_13 ( V_17 , F_15 ( V_18 ) ) &
V_33 )
V_32 |= V_34 ;
if ( V_31 & F_2 ( V_15 -> V_2 ) )
V_32 |= V_29 ;
if ( V_31 & F_3 ( V_15 -> V_2 ) )
V_32 |= V_30 ;
return V_32 ;
}
static unsigned F_16 ( const struct V_16 * V_17 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
const unsigned V_35 = F_17 ( V_18 ) ;
unsigned V_36 = 0 ;
unsigned V_37 ;
unsigned V_38 ;
V_37 = F_18 ( F_13 ( V_17 ,
F_15 ( V_18 ) ) ) ;
switch ( V_37 ) {
case V_39 :
V_36 = V_23 ;
break;
case V_40 :
V_36 = V_24 ;
break;
case V_41 :
if ( V_15 -> V_42 [ V_35 ] & V_43 )
V_36 =
V_44 ;
else
V_36 = V_25 ;
break;
case V_45 :
V_36 = V_46 ;
break;
case V_47 :
if ( V_15 -> V_42 [ V_35 ] & V_43 )
V_36 = V_48 ;
else
V_36 = V_49 ;
break;
case V_50 :
V_36 = V_26 ;
break;
case V_51 :
V_36 = V_52 ;
break;
default:
for ( V_38 = 0 ; V_38 <= V_53 ; ++ V_38 ) {
if ( V_37 == F_19 ( V_38 ) ) {
V_36 = F_20 ( V_38 ) ;
break;
}
}
if ( V_38 <= V_53 )
break;
for ( V_38 = 0 ; V_38 <= V_54 ; ++ V_38 ) {
if ( V_37 == F_21 ( V_38 ) ) {
V_36 = F_22 ( V_38 ) ;
break;
}
}
if ( V_38 <= V_54 )
break;
F_11 () ;
break;
}
V_36 |= F_12 ( V_17 ) ;
return V_36 ;
}
static unsigned F_23 ( const struct V_16 * V_17 )
{
unsigned V_36 = 0 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned V_37 ;
unsigned V_38 ;
V_37 = F_18 ( F_13 ( V_17 ,
F_15 ( V_18 ) ) ) ;
switch ( V_37 ) {
case V_55 :
V_36 = V_23 ;
break;
case V_56 :
V_36 = V_24 ;
break;
case V_57 :
V_36 = V_25 ;
break;
case V_58 :
V_36 = V_46 ;
break;
case V_59 :
V_36 = V_60 ;
break;
case V_61 :
V_36 = V_49 ;
break;
case V_62 :
V_36 = V_52 ;
break;
default:
for ( V_38 = 0 ; V_38 <= V_63 ; ++ V_38 ) {
if ( V_37 == F_24 ( V_38 ) ) {
V_36 = F_20 ( V_38 ) ;
break;
}
}
if ( V_38 <= V_63 )
break;
for ( V_38 = 0 ; V_38 <= V_64 ; ++ V_38 ) {
if ( V_37 == F_25 ( V_38 ) ) {
V_36 =
F_26 ( V_38 ) ;
break;
}
}
if ( V_38 <= V_64 )
break;
F_11 () ;
break;
}
V_36 |= F_12 ( V_17 ) ;
return V_36 ;
}
static unsigned F_27 ( const struct V_16 * V_17 )
{
switch ( V_17 -> V_15 -> V_2 ) {
case V_3 :
case V_4 :
default:
return F_16 ( V_17 ) ;
case V_6 :
return F_23 ( V_17 ) ;
}
}
static void F_28 ( struct V_16 * V_17 , int V_65 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
const unsigned V_66 = F_14 ( V_18 ) ;
static const T_1 V_67 = 25000 ;
unsigned V_68 ;
T_1 V_21 ;
if ( F_29 ( V_15 ) == 0 )
return;
V_68 = F_13 ( V_17 , V_66 ) ;
switch ( V_68 & V_69 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_65 = 1 ;
break;
default:
break;
}
V_21 = F_10 ( V_17 ,
F_27 ( V_17 ) ) ;
if ( V_65 ||
( V_21 && V_21 < V_67 ) ) {
F_30 ( V_17 , V_66 ,
F_1 ( V_15 -> V_2 ) ,
F_1 ( V_15 -> V_2 ) ) ;
} else {
F_30 ( V_17 , V_66 ,
F_1 ( V_15 -> V_2 ) ,
0x0 ) ;
}
}
static int F_31 ( struct V_16 * V_17 , unsigned V_68 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned V_74 ;
unsigned V_75 ;
unsigned V_76 = 0 ;
static const unsigned V_77 =
V_78 | V_79 |
V_80 | V_81 |
V_82 | V_83 |
V_84 | V_85 ;
V_74 = V_77 | V_86 ;
V_75 = V_68 & V_77 ;
switch ( V_68 & V_87 ) {
case V_88 :
break;
case V_89 :
V_75 |= V_86 ;
break;
case V_90 :
V_76 |= V_91 ;
V_74 |= V_92 ;
V_75 |= V_93 ;
break;
default:
break;
}
F_30 ( V_17 , F_32 ( V_18 ) ,
V_74 , V_75 ) ;
if ( F_29 ( V_15 ) ) {
unsigned V_32 = 0 ;
V_32 |= F_33 ( V_68 >> V_94 ) ;
V_32 |= F_34 ( ( V_68 >> V_95 ) ) ;
if ( V_68 & V_96 )
V_32 |= V_97 ;
F_30 ( V_17 , F_14 ( V_18 ) ,
V_69 | V_98 |
V_97 , V_32 ) ;
F_28 ( V_17 , 0 ) ;
}
F_30 ( V_17 , F_35 ( V_18 ) , V_99 ,
F_36 ( V_68 >> V_100 ) ) ;
if ( V_68 & V_101 )
V_76 |= V_102 ;
if ( V_68 & V_103 )
V_76 |= V_104 ;
F_30 ( V_17 , F_15 ( V_18 ) ,
V_91 | V_102 |
V_104 , V_76 ) ;
return 0 ;
}
int F_37 ( struct V_16 * V_17 , int V_105 , unsigned V_106 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned V_107 = 0 ;
if ( V_105 ) {
switch ( V_106 ) {
case V_108 :
V_107 |= V_109 ;
break;
case V_110 :
V_107 |= V_109 | V_111 ;
break;
default:
break;
}
if ( F_29 ( V_15 ) ) {
unsigned V_32 = 0 ;
unsigned V_112 ;
V_112 = F_4 ( V_15 -> V_2 ) ;
switch ( V_106 ) {
case V_108 :
case V_110 :
break;
default:
if ( V_106 & V_113 ) {
V_32 |= V_114 |
( F_38 ( V_106 ) &
V_112 ) ;
} else {
return - V_115 ;
}
break;
}
F_30 ( V_17 , F_14 ( V_18 ) ,
V_114 | V_112 , V_32 ) ;
}
} else {
V_107 |= V_116 ;
}
F_39 ( V_17 , F_35 ( V_18 ) ,
0 , 0 , V_107 ) ;
return 0 ;
}
static unsigned F_40 ( unsigned int V_36 )
{
unsigned V_117 = V_36 & V_22 ;
unsigned V_118 ;
unsigned V_38 ;
switch ( V_117 ) {
case V_23 :
V_118 = V_55 ;
break;
case V_24 :
V_118 = V_56 ;
break;
case V_25 :
V_118 = V_57 ;
break;
case V_46 :
V_118 = V_58 ;
break;
case V_60 :
V_118 = V_59 ;
break;
case V_49 :
V_118 = V_61 ;
break;
case V_52 :
V_118 = V_62 ;
break;
default:
for ( V_38 = 0 ; V_38 <= V_63 ; ++ V_38 ) {
if ( V_117 == F_20 ( V_38 ) ) {
V_118 = F_24 ( V_38 ) ;
break;
}
}
if ( V_38 <= V_63 )
break;
for ( V_38 = 0 ; V_38 <= V_64 ; ++ V_38 ) {
if ( V_117 == F_26 ( V_38 ) ) {
V_118 = F_25 ( V_38 ) ;
break;
}
}
if ( V_38 <= V_64 )
break;
V_118 = 0 ;
F_11 () ;
break;
}
return F_41 ( V_118 ) ;
}
static unsigned F_42 ( unsigned int V_36 )
{
unsigned V_117 = V_36 & V_22 ;
unsigned V_119 ;
unsigned V_38 ;
switch ( V_117 ) {
case V_23 :
V_119 = V_39 ;
break;
case V_24 :
V_119 = V_40 ;
break;
case V_25 :
V_119 = V_41 ;
break;
case V_46 :
V_119 = V_45 ;
break;
case V_49 :
V_119 = V_47 ;
break;
case V_52 :
V_119 = V_51 ;
break;
case V_26 :
V_119 = V_50 ;
break;
case V_48 :
V_119 = V_120 ;
break;
case V_44 :
V_119 = V_121 ;
break;
default:
for ( V_38 = 0 ; V_38 <= V_53 ; ++ V_38 ) {
if ( V_117 == F_20 ( V_38 ) ) {
V_119 = F_19 ( V_38 ) ;
break;
}
}
if ( V_38 <= V_53 )
break;
for ( V_38 = 0 ; V_38 <= V_54 ; ++ V_38 ) {
if ( V_117 == F_22 ( V_38 ) ) {
V_119 = F_21 ( V_38 ) ;
break;
}
}
if ( V_38 <= V_54 )
break;
F_43 ( L_1 ,
( unsigned long ) V_36 ) ;
F_11 () ;
V_119 = 0 ;
break;
}
return F_41 ( V_119 ) ;
}
static void F_44 ( struct V_16 * V_17 ,
unsigned int V_36 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
const unsigned V_35 = F_17 ( V_18 ) ;
if ( V_15 -> V_2 != V_4 )
return;
switch ( V_36 & V_22 ) {
case V_49 :
case V_25 :
V_15 -> V_42 [ V_35 ] &= ~ V_43 ;
break;
case V_44 :
case V_48 :
V_15 -> V_42 [ V_35 ] |= V_43 ;
break;
default:
return;
}
F_7 ( V_17 , V_15 -> V_42 [ V_35 ] ,
V_35 ) ;
}
static int F_45 ( struct V_16 * V_17 ,
unsigned int V_36 ,
unsigned int V_122 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned V_32 = 0 ;
switch ( V_15 -> V_2 ) {
case V_6 :
V_32 |= F_40 ( V_36 ) ;
break;
case V_3 :
case V_4 :
default:
V_32 |= F_42 ( V_36 ) ;
break;
}
if ( V_36 & V_34 )
V_32 |= V_33 ;
F_30 ( V_17 , F_15 ( V_18 ) ,
V_123 | V_33 , V_32 ) ;
F_44 ( V_17 , V_36 ) ;
if ( F_29 ( V_15 ) ) {
V_32 = 0 ;
switch ( V_36 & V_27 ) {
case V_28 :
break;
case V_29 :
V_32 |= F_2 ( V_15 -> V_2 ) ;
break;
case V_30 :
V_32 |= F_3 ( V_15 -> V_2 ) ;
break;
default:
return - V_115 ;
}
F_30 ( V_17 , F_14 ( V_18 ) ,
F_2 ( V_15 -> V_2 ) |
F_3 ( V_15 -> V_2 ) , V_32 ) ;
}
V_17 -> V_21 = V_122 * 1000 ;
F_28 ( V_17 , 0 ) ;
return 0 ;
}
static void F_46 ( struct V_16 * V_17 ,
unsigned int * V_36 ,
unsigned int * V_122 )
{
T_1 V_124 ;
* V_36 = F_27 ( V_17 ) ;
V_124 = F_10 ( V_17 , * V_36 ) ;
F_47 ( V_124 , 1000 ) ;
* V_122 = V_124 ;
}
static int F_48 ( struct V_16 * V_17 , unsigned int V_125 )
{
unsigned int V_126 = F_49 ( V_125 ) ;
unsigned V_18 = V_17 -> V_19 ;
unsigned V_127 ;
unsigned V_38 ;
switch ( V_126 ) {
case V_128 :
V_127 = V_129 ;
break;
case V_130 :
case V_131 :
case V_132 :
case V_133 :
V_127 = V_126 & 0x1f ;
break;
default:
for ( V_38 = 0 ; V_38 <= V_63 ; ++ V_38 ) {
if ( V_126 == F_50 ( V_38 ) ) {
V_127 = V_126 & 0x1f ;
break;
}
}
if ( V_38 <= V_63 )
break;
for ( V_38 = 0 ; V_38 <= V_134 ; ++ V_38 ) {
if ( V_126 == F_51 ( V_38 ) ) {
V_127 = V_126 & 0x1f ;
break;
}
}
if ( V_38 <= V_134 )
break;
return - V_115 ;
}
F_30 ( V_17 , F_15 ( V_18 ) ,
V_135 , F_52 ( V_127 ) ) ;
return 0 ;
}
static int F_53 ( struct V_16 * V_17 , unsigned int V_125 )
{
unsigned int V_126 = F_49 ( V_125 ) ;
unsigned V_18 = V_17 -> V_19 ;
unsigned V_127 ;
unsigned V_38 ;
switch ( V_126 ) {
case V_136 :
case V_137 :
case V_138 :
case V_130 :
case V_139 :
case V_128 :
case V_140 :
case V_131 :
V_127 = V_126 & 0x1f ;
break;
default:
for ( V_38 = 0 ; V_38 <= V_53 ; ++ V_38 ) {
if ( V_126 == F_50 ( V_38 ) ) {
V_127 = V_126 & 0x1f ;
break;
}
}
if ( V_38 <= V_53 )
break;
for ( V_38 = 0 ; V_38 <= V_54 ; ++ V_38 ) {
if ( V_126 == F_54 ( V_38 ) ) {
V_127 = V_126 & 0x1f ;
break;
}
}
if ( V_38 <= V_54 )
break;
return - V_115 ;
}
F_30 ( V_17 , F_15 ( V_18 ) ,
V_135 , F_52 ( V_127 ) ) ;
return 0 ;
}
static int F_55 ( struct V_16 * V_17 , unsigned int V_125 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned int V_126 = F_49 ( V_125 ) ;
unsigned V_141 = F_17 ( V_18 ) ;
unsigned V_142 ;
unsigned V_38 ;
switch ( V_126 ) {
case V_132 :
case V_143 :
case V_144 :
case V_130 :
case V_131 :
V_142 = V_126 & 0x1f ;
break;
case V_128 :
V_142 = V_145 ;
break;
default:
for ( V_38 = 0 ; V_38 <= V_63 ; ++ V_38 ) {
if ( V_126 == F_50 ( V_38 ) ) {
V_142 = V_126 & 0x1f ;
break;
}
}
if ( V_38 <= V_63 )
break;
for ( V_38 = 0 ; V_38 <= V_146 ; ++ V_38 ) {
if ( V_126 == F_56 ( V_38 ) ) {
V_142 = V_126 & 0x1f ;
break;
}
}
if ( V_38 <= V_146 )
break;
return - V_115 ;
}
V_15 -> V_42 [ V_141 ] |= V_147 ;
V_15 -> V_42 [ V_141 ] &= ~ V_148 ;
V_15 -> V_42 [ V_141 ] |= F_57 ( V_142 ) ;
F_7 ( V_17 , V_15 -> V_42 [ V_141 ] , V_141 ) ;
return 0 ;
}
static int F_58 ( struct V_16 * V_17 , unsigned int V_125 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned int V_126 = F_49 ( V_125 ) ;
unsigned V_141 = F_17 ( V_18 ) ;
unsigned V_142 ;
switch ( V_126 ) {
default:
V_142 = V_126 & 0x1f ;
break;
}
V_15 -> V_42 [ V_141 ] |= V_147 ;
V_15 -> V_42 [ V_141 ] &= ~ V_148 ;
V_15 -> V_42 [ V_141 ] |= F_57 ( V_142 ) ;
F_7 ( V_17 , V_15 -> V_42 [ V_141 ] , V_141 ) ;
return 0 ;
}
int F_59 ( struct V_16 * V_17 , unsigned V_149 ,
unsigned int V_125 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned int V_126 = F_49 ( V_125 ) ;
unsigned V_141 = F_17 ( V_18 ) ;
unsigned V_68 = 0 ;
switch ( V_149 ) {
case 0 :
if ( V_126 == V_150 ) {
F_30 ( V_17 , F_32 ( V_18 ) ,
V_92 ,
V_151 ) ;
return 0 ;
}
if ( V_125 & V_152 )
V_68 |= V_153 ;
if ( V_125 & V_154 )
V_68 |= V_155 ;
else
V_68 |= V_93 ;
F_30 ( V_17 , F_32 ( V_18 ) ,
V_153 | V_92 ,
V_68 ) ;
switch ( V_15 -> V_2 ) {
case V_3 :
case V_4 :
default:
return F_53 ( V_17 , V_125 ) ;
case V_6 :
return F_48 ( V_17 , V_125 ) ;
}
break;
case 1 :
if ( ! F_5 ( V_15 ) )
return - V_115 ;
if ( V_126 == V_150 ) {
V_15 -> V_42 [ V_141 ] &= ~ V_147 ;
F_7 ( V_17 , V_15 -> V_42 [ V_141 ] ,
V_141 ) ;
return 0 ;
}
if ( V_125 & V_152 )
V_15 -> V_42 [ V_141 ] |= V_156 ;
else
V_15 -> V_42 [ V_141 ] &= ~ V_156 ;
switch ( V_15 -> V_2 ) {
case V_4 :
return F_58 ( V_17 , V_125 ) ;
case V_6 :
return F_55 ( V_17 , V_125 ) ;
default:
F_11 () ;
break;
}
break;
default:
return - V_115 ;
}
return 0 ;
}
static int F_60 ( struct V_16 * V_17 , unsigned V_157 ,
unsigned int V_158 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned int V_159 , V_160 , V_161 ;
if ( V_15 -> V_2 != V_4 )
return - V_115 ;
V_159 = F_61 ( V_18 ) ;
switch ( V_157 ) {
case V_162 :
V_160 = 10 ;
break;
case V_163 :
V_160 = 5 ;
break;
case V_164 :
V_160 = 0 ;
break;
default:
return - V_115 ;
}
V_161 = 0x1f << V_160 ;
if ( V_158 > 0x1f )
V_158 = 0x1f ;
V_15 -> V_42 [ V_159 ] &= ~ V_161 ;
V_15 -> V_42 [ V_159 ] |= ( V_158 << V_160 ) & V_161 ;
F_7 ( V_17 , V_15 -> V_42 [ V_159 ] , V_159 ) ;
return 0 ;
}
static unsigned F_62 ( unsigned V_165 )
{
unsigned V_38 ;
switch ( V_165 ) {
case V_166 :
return V_132 ;
case V_167 :
return V_133 ;
case V_129 :
return V_128 ;
case V_168 :
return V_130 ;
case V_169 :
return V_131 ;
default:
for ( V_38 = 0 ; V_38 <= V_63 ; ++ V_38 ) {
if ( V_165 == F_63 ( V_38 ) )
return F_50 ( V_38 ) ;
}
for ( V_38 = 0 ; V_38 <= V_134 ; ++ V_38 ) {
if ( V_165 == F_64 ( V_38 ) )
return F_51 ( V_38 ) ;
}
F_11 () ;
break;
}
return 0 ;
}
static unsigned F_65 ( unsigned V_165 )
{
unsigned V_38 ;
switch ( V_165 ) {
case V_170 :
return V_136 ;
case V_171 :
return V_137 ;
case V_172 :
return V_138 ;
case V_173 :
return V_130 ;
case V_174 :
return V_139 ;
case V_175 :
return V_128 ;
case V_176 :
return V_140 ;
case V_177 :
return V_131 ;
default:
for ( V_38 = 0 ; V_38 <= V_53 ; ++ V_38 ) {
if ( V_165 == F_66 ( V_38 ) )
return F_50 ( V_38 ) ;
}
for ( V_38 = 0 ; V_38 <= V_54 ; ++ V_38 ) {
if ( V_165 == F_67 ( V_38 ) )
return F_54 ( V_38 ) ;
}
F_11 () ;
break;
}
return 0 ;
}
static unsigned F_68 ( unsigned V_165 )
{
unsigned V_38 ;
switch ( V_165 ) {
case V_178 :
return V_132 ;
case V_179 :
return V_143 ;
case V_145 :
return V_128 ;
case V_180 :
return V_130 ;
case V_181 :
return V_144 ;
case V_182 :
return V_131 ;
default:
for ( V_38 = 0 ; V_38 <= V_63 ; ++ V_38 ) {
if ( V_165 == F_69 ( V_38 ) )
return F_50 ( V_38 ) ;
}
for ( V_38 = 0 ; V_38 <= V_146 ; ++ V_38 ) {
if ( V_165 == F_70 ( V_38 ) )
return F_56 ( V_38 ) ;
}
F_11 () ;
break;
}
return 0 ;
}
static unsigned F_71 ( unsigned V_165 )
{
switch ( V_165 ) {
default:
return V_165 ;
}
return 0 ;
}
static int F_72 ( struct V_16 * V_17 , unsigned V_149 ,
unsigned int * V_125 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned V_68 = F_13 ( V_17 , F_32 ( V_18 ) ) ;
unsigned V_141 = F_17 ( V_18 ) ;
unsigned V_165 ;
switch ( V_149 ) {
case 0 :
if ( ( V_68 & V_92 ) == V_151 ) {
* V_125 = V_150 ;
return 0 ;
}
V_165 = F_73 ( F_13 ( V_17 ,
F_15 ( V_18 ) ) ) ;
switch ( V_15 -> V_2 ) {
case V_3 :
case V_4 :
default:
* V_125 = F_65 ( V_165 ) ;
break;
case V_6 :
* V_125 = F_62 ( V_165 ) ;
break;
}
if ( V_68 & V_153 )
* V_125 |= V_152 ;
if ( ( V_68 & V_92 ) != V_93 )
* V_125 |= V_154 ;
break;
case 1 :
if ( ( V_68 & V_92 ) == V_151 ||
! ( V_15 -> V_42 [ V_141 ] & V_147 ) ) {
* V_125 = V_150 ;
return 0 ;
}
V_165 = F_74 ( V_15 -> V_42 [ V_141 ] ) ;
switch ( V_15 -> V_2 ) {
case V_3 :
case V_4 :
default:
* V_125 = F_71 ( V_165 ) ;
break;
case V_6 :
* V_125 = F_68 ( V_165 ) ;
break;
}
if ( V_15 -> V_42 [ V_141 ] & V_156 )
* V_125 |= V_152 ;
if ( ( V_68 & V_92 ) != V_93 )
* V_125 |= V_154 ;
break;
default:
return - V_115 ;
}
return 0 ;
}
int F_75 ( struct V_183 * V_184 ,
struct V_185 * V_186 ,
struct V_187 * V_188 ,
unsigned int * V_189 )
{
struct V_16 * V_17 = V_186 -> V_190 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned V_191 ;
switch ( V_189 [ 0 ] ) {
case V_192 :
return F_31 ( V_17 , V_189 [ 1 ] ) ;
case V_193 :
return F_37 ( V_17 , 1 , V_189 [ 1 ] ) ;
case V_194 :
F_37 ( V_17 , 0 , 0 ) ;
return 0 ;
case V_195 :
V_189 [ 1 ] = 0 ;
V_191 = F_76 ( V_17 , F_77 ( V_18 ) ) ;
if ( V_191 & F_78 ( V_18 ) ) {
V_189 [ 1 ] |= V_196 ;
if ( V_191 & F_79 ( V_18 ) )
V_189 [ 1 ] |= V_197 ;
}
V_189 [ 2 ] = V_196 | V_197 ;
return 0 ;
case V_198 :
return F_45 ( V_17 , V_189 [ 1 ] , V_189 [ 2 ] ) ;
case V_199 :
F_46 ( V_17 , & V_189 [ 1 ] , & V_189 [ 2 ] ) ;
return 0 ;
case V_200 :
return F_59 ( V_17 , V_189 [ 1 ] , V_189 [ 2 ] ) ;
case V_201 :
return F_72 ( V_17 , V_189 [ 1 ] , & V_189 [ 2 ] ) ;
case V_202 :
return F_60 ( V_17 , V_189 [ 1 ] , V_189 [ 2 ] ) ;
case V_203 :
F_6 ( V_17 ) ;
return 0 ;
default:
break;
}
return - V_115 ;
}
static unsigned int F_80 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_16 * V_17 = V_186 -> V_190 ;
unsigned V_18 = V_17 -> V_19 ;
unsigned int V_204 ;
F_30 ( V_17 , F_35 ( V_18 ) , V_205 , 0 ) ;
F_30 ( V_17 , F_35 ( V_18 ) ,
V_205 , V_205 ) ;
V_204 = F_76 ( V_17 , F_81 ( V_18 ) ) ;
if ( V_204 != F_76 ( V_17 , F_81 ( V_18 ) ) )
V_204 = F_76 ( V_17 , F_81 ( V_18 ) ) ;
return V_204 ;
}
int F_82 ( struct V_183 * V_184 ,
struct V_185 * V_186 ,
struct V_187 * V_188 ,
unsigned int * V_189 )
{
struct V_16 * V_17 = V_186 -> V_190 ;
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned int V_206 = F_49 ( V_188 -> V_207 ) ;
unsigned V_18 = V_17 -> V_19 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_188 -> V_208 ; V_38 ++ ) {
switch ( V_206 ) {
case 0 :
V_189 [ V_38 ] = F_80 ( V_184 , V_186 ) ;
break;
case 1 :
V_189 [ V_38 ] = V_15 -> V_42 [ F_83 ( V_18 ) ] ;
break;
case 2 :
V_189 [ V_38 ] = V_15 -> V_42 [ F_84 ( V_18 ) ] ;
break;
}
}
return V_188 -> V_208 ;
}
static unsigned F_85 ( struct V_16 * V_17 )
{
unsigned V_18 = V_17 -> V_19 ;
const unsigned V_32 =
F_76 ( V_17 , F_77 ( V_18 ) ) ;
return ( V_32 & F_86 ( V_18 ) )
? F_84 ( V_18 )
: F_83 ( V_18 ) ;
}
int F_87 ( struct V_183 * V_184 ,
struct V_185 * V_186 ,
struct V_187 * V_188 ,
unsigned int * V_189 )
{
struct V_16 * V_17 = V_186 -> V_190 ;
struct V_14 * V_15 = V_17 -> V_15 ;
const unsigned V_206 = F_49 ( V_188 -> V_207 ) ;
unsigned V_18 = V_17 -> V_19 ;
unsigned V_209 ;
if ( V_188 -> V_208 < 1 )
return 0 ;
switch ( V_206 ) {
case 0 :
V_209 = F_85 ( V_17 ) ;
F_7 ( V_17 , V_189 [ 0 ] , V_209 ) ;
F_39 ( V_17 , F_35 ( V_18 ) ,
0 , 0 , V_210 ) ;
F_7 ( V_17 , V_15 -> V_42 [ V_209 ] , V_209 ) ;
break;
case 1 :
V_15 -> V_42 [ F_83 ( V_18 ) ] = V_189 [ 0 ] ;
F_7 ( V_17 , V_189 [ 0 ] , F_83 ( V_18 ) ) ;
break;
case 2 :
V_15 -> V_42 [ F_84 ( V_18 ) ] = V_189 [ 0 ] ;
F_7 ( V_17 , V_189 [ 0 ] , F_84 ( V_18 ) ) ;
break;
default:
return - V_115 ;
}
return 0 ;
}
void F_88 ( struct V_16 * V_17 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned V_18 = V_17 -> V_19 ;
F_6 ( V_17 ) ;
V_15 -> V_42 [ F_89 ( V_18 ) ] = 0x0 ;
F_7 ( V_17 , 0x0 , F_89 ( V_18 ) ) ;
F_30 ( V_17 , F_35 ( V_18 ) ,
~ 0 , V_211 ) ;
F_30 ( V_17 , F_32 ( V_18 ) , ~ 0 , 0 ) ;
V_15 -> V_42 [ F_83 ( V_18 ) ] = 0x0 ;
F_7 ( V_17 , 0x0 , F_83 ( V_18 ) ) ;
V_15 -> V_42 [ F_84 ( V_18 ) ] = 0x0 ;
F_7 ( V_17 , 0x0 , F_84 ( V_18 ) ) ;
F_30 ( V_17 , F_15 ( V_18 ) , ~ 0 , 0 ) ;
if ( F_29 ( V_15 ) )
F_30 ( V_17 , F_14 ( V_18 ) , ~ 0 , 0 ) ;
if ( F_5 ( V_15 ) ) {
V_15 -> V_42 [ F_17 ( V_18 ) ] = 0x0 ;
F_7 ( V_17 , 0x0 , F_17 ( V_18 ) ) ;
}
F_30 ( V_17 , F_90 ( V_18 ) , ~ 0 , 0x0 ) ;
F_30 ( V_17 , F_91 ( V_18 ) , ~ 0 , 0x0 ) ;
}
struct V_14 *
F_92 ( struct V_183 * V_184 ,
void (* F_7)( struct V_16 * V_17 ,
unsigned V_32 ,
enum V_212 V_213 ) ,
unsigned (* F_76)( struct V_16 * V_17 ,
enum V_212 V_213 ) ,
enum V_1 V_2 ,
unsigned V_214 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
unsigned V_38 ;
if ( V_214 == 0 )
return NULL ;
V_15 = F_93 ( sizeof( * V_15 ) , V_215 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_184 = V_184 ;
V_15 -> F_7 = F_7 ;
V_15 -> F_76 = F_76 ;
V_15 -> V_2 = V_2 ;
F_94 ( & V_15 -> V_216 ) ;
V_15 -> V_217 = F_95 ( V_214 , sizeof( * V_17 ) ,
V_215 ) ;
if ( ! V_15 -> V_217 ) {
F_96 ( V_15 ) ;
return NULL ;
}
for ( V_38 = 0 ; V_38 < V_214 ; ++ V_38 ) {
V_17 = & V_15 -> V_217 [ V_38 ] ;
V_17 -> V_15 = V_15 ;
F_94 ( & V_17 -> V_218 ) ;
}
V_15 -> V_214 = V_214 ;
return V_15 ;
}
void F_97 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_217 )
return;
F_96 ( V_15 -> V_217 ) ;
F_96 ( V_15 ) ;
}
static int T_2 F_98 ( void )
{
return 0 ;
}
static void T_3 F_99 ( void )
{
}
