static inline unsigned int F_1 ( enum V_1 V_2 )
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
static inline unsigned int F_2 ( enum V_1 V_2 )
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
static bool F_3 ( const struct V_10 * V_11 )
{
switch ( V_11 -> V_2 ) {
case V_3 :
default:
return false ;
case V_4 :
case V_6 :
return true ;
}
}
void F_4 ( struct V_12 * V_13 , unsigned int V_14 ,
enum V_15 V_16 )
{
if ( V_16 < V_17 )
V_13 -> V_11 -> V_18 ( V_13 , V_14 , V_16 ) ;
}
unsigned int F_5 ( struct V_12 * V_13 , enum V_15 V_16 )
{
if ( V_16 < V_17 )
return V_13 -> V_11 -> V_19 ( V_13 , V_16 ) ;
return 0 ;
}
static void F_6 ( struct V_12 * V_13 )
{
unsigned int V_20 = V_13 -> V_21 ;
F_4 ( V_13 , F_7 ( V_20 ) , F_8 ( V_20 ) ) ;
}
static int F_9 ( const struct V_12 * V_13 ,
unsigned int V_22 ,
T_1 * V_23 )
{
T_1 V_24 ;
switch ( V_22 & V_25 ) {
case V_26 :
V_24 = 50000 ;
break;
case V_27 :
V_24 = 10000000 ;
break;
case V_28 :
V_24 = 12500 ;
break;
case V_29 :
V_24 = 100000 ;
break;
default:
* V_23 = V_13 -> V_24 ;
return 0 ;
}
switch ( V_22 & V_30 ) {
case V_31 :
break;
case V_32 :
V_24 *= 2 ;
break;
case V_33 :
V_24 *= 8 ;
break;
default:
return - V_34 ;
}
* V_23 = V_24 ;
return 0 ;
}
static void F_10 ( struct V_12 * V_13 ,
enum V_15 V_16 ,
unsigned int V_35 , unsigned int V_14 ,
unsigned int V_36 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned long V_37 ;
if ( V_16 < V_17 ) {
F_11 ( & V_11 -> V_38 , V_37 ) ;
V_11 -> V_39 [ V_16 ] &= ~ V_35 ;
V_11 -> V_39 [ V_16 ] |= ( V_14 & V_35 ) ;
F_4 ( V_13 , V_11 -> V_39 [ V_16 ] | V_36 , V_16 ) ;
F_12 () ;
F_13 ( & V_11 -> V_38 , V_37 ) ;
}
}
void F_14 ( struct V_12 * V_13 , enum V_15 V_16 ,
unsigned int V_35 , unsigned int V_14 )
{
F_10 ( V_13 , V_16 , V_35 , V_14 , 0x0 ) ;
}
unsigned int F_15 ( const struct V_12 * V_13 ,
enum V_15 V_16 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_14 = 0 ;
unsigned long V_37 ;
if ( V_16 < V_17 ) {
F_11 ( & V_11 -> V_38 , V_37 ) ;
V_14 = V_11 -> V_39 [ V_16 ] ;
F_13 ( & V_11 -> V_38 , V_37 ) ;
}
return V_14 ;
}
static unsigned int F_16 ( const struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_40 =
F_15 ( V_13 , F_17 ( V_20 ) ) ;
unsigned int V_41 = 0 ;
if ( F_15 ( V_13 , F_18 ( V_20 ) ) &
V_42 )
V_41 |= V_43 ;
if ( V_40 & F_1 ( V_11 -> V_2 ) )
V_41 |= V_32 ;
if ( V_40 & F_2 ( V_11 -> V_2 ) )
V_41 |= V_33 ;
return V_41 ;
}
static int F_19 ( const struct V_12 * V_13 ,
unsigned int * V_44 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_45 = F_20 ( V_20 ) ;
unsigned int V_46 = 0 ;
unsigned int V_47 ;
unsigned int V_48 ;
V_47 = F_21 ( F_15 ( V_13 ,
F_18 ( V_20 ) ) ) ;
switch ( V_47 ) {
case V_49 :
V_46 = V_26 ;
break;
case V_50 :
V_46 = V_27 ;
break;
case V_51 :
if ( V_11 -> V_39 [ V_45 ] & V_52 )
V_46 =
V_53 ;
else
V_46 = V_28 ;
break;
case V_54 :
V_46 = V_55 ;
break;
case V_56 :
if ( V_11 -> V_39 [ V_45 ] & V_52 )
V_46 = V_57 ;
else
V_46 = V_58 ;
break;
case V_59 :
V_46 = V_29 ;
break;
case V_60 :
V_46 = V_61 ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_62 ; ++ V_48 ) {
if ( V_47 == F_22 ( V_48 ) ) {
V_46 = F_23 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_62 )
break;
for ( V_48 = 0 ; V_48 <= V_63 ; ++ V_48 ) {
if ( V_47 == F_24 ( V_48 ) ) {
V_46 = F_25 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_63 )
break;
return - V_34 ;
}
V_46 |= F_16 ( V_13 ) ;
* V_44 = V_46 ;
return 0 ;
}
static int F_26 ( const struct V_12 * V_13 ,
unsigned int * V_44 )
{
unsigned int V_46 = 0 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_47 ;
unsigned int V_48 ;
V_47 = F_21 ( F_15 ( V_13 ,
F_18 ( V_20 ) ) ) ;
switch ( V_47 ) {
case V_64 :
V_46 = V_26 ;
break;
case V_65 :
V_46 = V_27 ;
break;
case V_66 :
V_46 = V_28 ;
break;
case V_67 :
V_46 = V_55 ;
break;
case V_68 :
V_46 = V_69 ;
break;
case V_70 :
V_46 = V_58 ;
break;
case V_71 :
V_46 = V_61 ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_72 ; ++ V_48 ) {
if ( V_47 == F_27 ( V_48 ) ) {
V_46 = F_23 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_72 )
break;
for ( V_48 = 0 ; V_48 <= V_73 ; ++ V_48 ) {
if ( V_47 == F_28 ( V_48 ) ) {
V_46 =
F_29 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_73 )
break;
return - V_34 ;
}
V_46 |= F_16 ( V_13 ) ;
* V_44 = V_46 ;
return 0 ;
}
static int F_30 ( const struct V_12 * V_13 ,
unsigned int * V_44 )
{
switch ( V_13 -> V_11 -> V_2 ) {
case V_3 :
case V_4 :
default:
return F_19 ( V_13 , V_44 ) ;
case V_6 :
return F_26 ( V_13 , V_44 ) ;
}
}
static void F_31 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
static const T_1 V_74 = 25000 ;
unsigned int V_35 = 0 ;
unsigned int V_41 = 0 ;
unsigned int V_16 ;
unsigned int V_75 ;
unsigned int V_44 ;
T_1 V_76 ;
bool V_77 ;
switch ( V_11 -> V_2 ) {
case V_3 :
default:
return;
case V_4 :
V_35 = V_78 ;
break;
case V_6 :
V_35 = V_79 ;
break;
}
V_16 = F_17 ( V_20 ) ;
V_75 = F_15 ( V_13 , V_16 ) ;
switch ( V_75 & V_80 ) {
case V_81 :
case V_82 :
case V_83 :
case V_84 :
V_77 = true ;
break;
default:
V_77 = false ;
break;
}
F_30 ( V_13 , & V_44 ) ;
F_9 ( V_13 , V_44 , & V_76 ) ;
if ( V_77 || ( V_76 && V_76 < V_74 ) )
V_41 = V_35 ;
F_14 ( V_13 , V_16 , V_35 , V_41 ) ;
}
static int F_32 ( struct V_12 * V_13 , unsigned int V_75 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_85 ;
unsigned int V_86 ;
unsigned int V_87 = 0 ;
static const unsigned int V_88 =
V_89 | V_90 |
V_91 | V_92 |
V_93 | V_94 |
V_95 | V_96 ;
V_85 = V_88 | V_97 ;
V_86 = V_75 & V_88 ;
switch ( V_75 & V_98 ) {
case V_99 :
break;
case V_100 :
V_86 |= V_97 ;
break;
case V_101 :
V_87 |= V_102 ;
V_85 |= V_103 ;
V_86 |= V_104 ;
break;
default:
break;
}
F_14 ( V_13 , F_33 ( V_20 ) ,
V_85 , V_86 ) ;
if ( F_34 ( V_11 ) ) {
unsigned int V_41 = 0 ;
V_41 |= F_35 ( V_75 >> V_105 ) ;
V_41 |= F_36 ( ( V_75 >> V_106 ) ) ;
if ( V_75 & V_107 )
V_41 |= V_108 ;
F_14 ( V_13 , F_17 ( V_20 ) ,
V_80 | V_109 |
V_108 , V_41 ) ;
F_31 ( V_13 ) ;
}
F_14 ( V_13 , F_37 ( V_20 ) , V_110 ,
F_38 ( V_75 >> V_111 ) ) ;
if ( V_75 & V_112 )
V_87 |= V_113 ;
if ( V_75 & V_114 )
V_87 |= V_115 ;
F_14 ( V_13 , F_18 ( V_20 ) ,
V_102 | V_113 |
V_115 , V_87 ) ;
return 0 ;
}
int F_39 ( struct V_12 * V_13 , bool V_116 , unsigned int V_117 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_118 = 0 ;
if ( V_116 ) {
unsigned int V_35 = 0 ;
unsigned int V_41 = 0 ;
switch ( V_11 -> V_2 ) {
case V_3 :
default:
break;
case V_4 :
V_35 = V_119 ;
break;
case V_6 :
V_35 = V_120 ;
break;
}
switch ( V_117 ) {
case V_121 :
V_118 |= V_122 ;
break;
case V_123 :
V_118 |= V_122 | V_124 ;
break;
default:
if ( V_35 && ( V_117 & V_125 ) ) {
V_41 |= V_126 |
( F_40 ( V_117 ) & V_35 ) ;
} else {
return - V_34 ;
}
break;
}
if ( V_35 )
F_14 ( V_13 , F_17 ( V_20 ) ,
V_126 | V_35 , V_41 ) ;
} else {
V_118 |= V_127 ;
}
F_10 ( V_13 , F_37 ( V_20 ) ,
0 , 0 , V_118 ) ;
return 0 ;
}
static int F_41 ( unsigned int V_46 , unsigned int * V_41 )
{
unsigned int V_44 = V_46 & V_25 ;
unsigned int V_128 ;
unsigned int V_48 ;
switch ( V_44 ) {
case V_26 :
V_128 = V_64 ;
break;
case V_27 :
V_128 = V_65 ;
break;
case V_28 :
V_128 = V_66 ;
break;
case V_55 :
V_128 = V_67 ;
break;
case V_69 :
V_128 = V_68 ;
break;
case V_58 :
V_128 = V_70 ;
break;
case V_61 :
V_128 = V_71 ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_72 ; ++ V_48 ) {
if ( V_44 == F_23 ( V_48 ) ) {
V_128 = F_27 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_72 )
break;
for ( V_48 = 0 ; V_48 <= V_73 ; ++ V_48 ) {
if ( V_44 == F_29 ( V_48 ) ) {
V_128 = F_28 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_73 )
break;
return - V_34 ;
}
* V_41 = F_42 ( V_128 ) ;
return 0 ;
}
static int F_43 ( unsigned int V_46 , unsigned int * V_41 )
{
unsigned int V_44 = V_46 & V_25 ;
unsigned int V_129 ;
unsigned int V_48 ;
switch ( V_44 ) {
case V_26 :
V_129 = V_49 ;
break;
case V_27 :
V_129 = V_50 ;
break;
case V_28 :
V_129 = V_51 ;
break;
case V_55 :
V_129 = V_54 ;
break;
case V_58 :
V_129 = V_56 ;
break;
case V_61 :
V_129 = V_60 ;
break;
case V_29 :
V_129 = V_59 ;
break;
case V_57 :
V_129 = V_130 ;
break;
case V_53 :
V_129 = V_131 ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_62 ; ++ V_48 ) {
if ( V_44 == F_23 ( V_48 ) ) {
V_129 = F_22 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_62 )
break;
for ( V_48 = 0 ; V_48 <= V_63 ; ++ V_48 ) {
if ( V_44 == F_25 ( V_48 ) ) {
V_129 = F_24 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_63 )
break;
return - V_34 ;
}
* V_41 = F_42 ( V_129 ) ;
return 0 ;
}
static void F_44 ( struct V_12 * V_13 ,
unsigned int V_46 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_45 = F_20 ( V_20 ) ;
if ( V_11 -> V_2 != V_4 )
return;
switch ( V_46 & V_25 ) {
case V_58 :
case V_28 :
V_11 -> V_39 [ V_45 ] &= ~ V_52 ;
break;
case V_53 :
case V_57 :
V_11 -> V_39 [ V_45 ] |= V_52 ;
break;
default:
return;
}
F_4 ( V_13 , V_11 -> V_39 [ V_45 ] ,
V_45 ) ;
}
static int F_45 ( struct V_12 * V_13 ,
unsigned int V_46 ,
unsigned int V_132 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_41 = 0 ;
int V_133 ;
switch ( V_11 -> V_2 ) {
case V_6 :
V_133 = F_41 ( V_46 , & V_41 ) ;
break;
case V_3 :
case V_4 :
default:
V_133 = F_43 ( V_46 , & V_41 ) ;
break;
}
if ( V_133 ) {
struct V_134 * V_135 = V_11 -> V_135 ;
F_46 ( V_135 -> V_136 , L_1 ,
V_46 ) ;
return V_133 ;
}
if ( V_46 & V_43 )
V_41 |= V_42 ;
F_14 ( V_13 , F_18 ( V_20 ) ,
V_137 | V_42 , V_41 ) ;
F_44 ( V_13 , V_46 ) ;
if ( F_34 ( V_11 ) ) {
V_41 = 0 ;
switch ( V_46 & V_30 ) {
case V_31 :
break;
case V_32 :
V_41 |= F_1 ( V_11 -> V_2 ) ;
break;
case V_33 :
V_41 |= F_2 ( V_11 -> V_2 ) ;
break;
default:
return - V_34 ;
}
F_14 ( V_13 , F_17 ( V_20 ) ,
F_1 ( V_11 -> V_2 ) |
F_2 ( V_11 -> V_2 ) , V_41 ) ;
}
V_13 -> V_24 = V_132 * 1000 ;
F_31 ( V_13 ) ;
return 0 ;
}
static int F_47 ( struct V_12 * V_13 ,
unsigned int * V_46 ,
unsigned int * V_132 )
{
T_1 V_138 ;
int V_133 ;
V_133 = F_30 ( V_13 , V_46 ) ;
if ( V_133 )
return V_133 ;
V_133 = F_9 ( V_13 , * V_46 , & V_138 ) ;
if ( V_133 )
return V_133 ;
F_48 ( V_138 , 1000 ) ;
* V_132 = V_138 ;
return 0 ;
}
static int F_49 ( struct V_12 * V_13 , unsigned int V_139 )
{
unsigned int V_140 = F_50 ( V_139 ) ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_141 ;
unsigned int V_48 ;
switch ( V_140 ) {
case V_142 :
V_141 = V_143 ;
break;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
V_141 = V_140 & 0x1f ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_72 ; ++ V_48 ) {
if ( V_140 == F_51 ( V_48 ) ) {
V_141 = V_140 & 0x1f ;
break;
}
}
if ( V_48 <= V_72 )
break;
for ( V_48 = 0 ; V_48 <= V_148 ; ++ V_48 ) {
if ( V_140 == F_52 ( V_48 ) ) {
V_141 = V_140 & 0x1f ;
break;
}
}
if ( V_48 <= V_148 )
break;
return - V_34 ;
}
F_14 ( V_13 , F_18 ( V_20 ) ,
V_149 , F_53 ( V_141 ) ) ;
return 0 ;
}
static int F_54 ( struct V_12 * V_13 , unsigned int V_139 )
{
unsigned int V_140 = F_50 ( V_139 ) ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_141 ;
unsigned int V_48 ;
switch ( V_140 ) {
case V_150 :
case V_151 :
case V_152 :
case V_144 :
case V_153 :
case V_142 :
case V_154 :
case V_145 :
V_141 = V_140 & 0x1f ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_62 ; ++ V_48 ) {
if ( V_140 == F_51 ( V_48 ) ) {
V_141 = V_140 & 0x1f ;
break;
}
}
if ( V_48 <= V_62 )
break;
for ( V_48 = 0 ; V_48 <= V_63 ; ++ V_48 ) {
if ( V_140 == F_55 ( V_48 ) ) {
V_141 = V_140 & 0x1f ;
break;
}
}
if ( V_48 <= V_63 )
break;
return - V_34 ;
}
F_14 ( V_13 , F_18 ( V_20 ) ,
V_149 , F_53 ( V_141 ) ) ;
return 0 ;
}
static int F_56 ( struct V_12 * V_13 , unsigned int V_139 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_140 = F_50 ( V_139 ) ;
unsigned int V_155 = F_20 ( V_20 ) ;
unsigned int V_156 ;
unsigned int V_48 ;
switch ( V_140 ) {
case V_146 :
case V_157 :
case V_158 :
case V_144 :
case V_145 :
V_156 = V_140 & 0x1f ;
break;
case V_142 :
V_156 = V_159 ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_72 ; ++ V_48 ) {
if ( V_140 == F_51 ( V_48 ) ) {
V_156 = V_140 & 0x1f ;
break;
}
}
if ( V_48 <= V_72 )
break;
for ( V_48 = 0 ; V_48 <= V_160 ; ++ V_48 ) {
if ( V_140 == F_57 ( V_48 ) ) {
V_156 = V_140 & 0x1f ;
break;
}
}
if ( V_48 <= V_160 )
break;
return - V_34 ;
}
V_11 -> V_39 [ V_155 ] |= V_161 ;
V_11 -> V_39 [ V_155 ] &= ~ V_162 ;
V_11 -> V_39 [ V_155 ] |= F_58 ( V_156 ) ;
F_4 ( V_13 , V_11 -> V_39 [ V_155 ] , V_155 ) ;
return 0 ;
}
static int F_59 ( struct V_12 * V_13 , unsigned int V_139 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_140 = F_50 ( V_139 ) ;
unsigned int V_155 = F_20 ( V_20 ) ;
unsigned int V_156 ;
switch ( V_140 ) {
default:
V_156 = V_140 & 0x1f ;
break;
}
V_11 -> V_39 [ V_155 ] |= V_161 ;
V_11 -> V_39 [ V_155 ] &= ~ V_162 ;
V_11 -> V_39 [ V_155 ] |= F_58 ( V_156 ) ;
F_4 ( V_13 , V_11 -> V_39 [ V_155 ] , V_155 ) ;
return 0 ;
}
int F_60 ( struct V_12 * V_13 ,
unsigned int V_163 , unsigned int V_47 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_140 = F_50 ( V_47 ) ;
unsigned int V_155 = F_20 ( V_20 ) ;
unsigned int V_75 = 0 ;
switch ( V_163 ) {
case 0 :
if ( V_140 == V_164 ) {
F_14 ( V_13 , F_33 ( V_20 ) ,
V_103 ,
V_165 ) ;
return 0 ;
}
if ( V_47 & V_166 )
V_75 |= V_167 ;
if ( V_47 & V_168 )
V_75 |= V_169 ;
else
V_75 |= V_104 ;
F_14 ( V_13 , F_33 ( V_20 ) ,
V_167 | V_103 ,
V_75 ) ;
switch ( V_11 -> V_2 ) {
case V_3 :
case V_4 :
default:
return F_54 ( V_13 , V_47 ) ;
case V_6 :
return F_49 ( V_13 , V_47 ) ;
}
break;
case 1 :
if ( ! F_3 ( V_11 ) )
return - V_34 ;
if ( V_140 == V_164 ) {
V_11 -> V_39 [ V_155 ] &= ~ V_161 ;
F_4 ( V_13 , V_11 -> V_39 [ V_155 ] ,
V_155 ) ;
return 0 ;
}
if ( V_47 & V_166 )
V_11 -> V_39 [ V_155 ] |= V_170 ;
else
V_11 -> V_39 [ V_155 ] &= ~ V_170 ;
switch ( V_11 -> V_2 ) {
case V_4 :
return F_59 ( V_13 , V_47 ) ;
case V_6 :
return F_56 ( V_13 , V_47 ) ;
default:
return - V_34 ;
}
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_61 ( struct V_12 * V_13 , unsigned int V_171 ,
unsigned int V_172 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_173 , V_174 , V_35 ;
if ( V_11 -> V_2 != V_4 )
return - V_34 ;
V_173 = F_62 ( V_20 ) ;
switch ( V_171 ) {
case V_175 :
V_174 = 10 ;
break;
case V_176 :
V_174 = 5 ;
break;
case V_177 :
V_174 = 0 ;
break;
default:
return - V_34 ;
}
V_35 = 0x1f << V_174 ;
if ( V_172 > 0x1f )
V_172 = 0x1f ;
V_11 -> V_39 [ V_173 ] &= ~ V_35 ;
V_11 -> V_39 [ V_173 ] |= ( V_172 << V_174 ) & V_35 ;
F_4 ( V_13 , V_11 -> V_39 [ V_173 ] , V_173 ) ;
return 0 ;
}
static int F_63 ( unsigned int V_163 , unsigned int * V_47 )
{
unsigned int V_172 ;
unsigned int V_48 ;
switch ( V_163 ) {
case V_178 :
V_172 = V_146 ;
break;
case V_179 :
V_172 = V_147 ;
break;
case V_143 :
V_172 = V_142 ;
break;
case V_180 :
V_172 = V_144 ;
break;
case V_181 :
V_172 = V_145 ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_72 ; ++ V_48 ) {
if ( V_163 == F_64 ( V_48 ) ) {
V_172 = F_51 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_72 )
break;
for ( V_48 = 0 ; V_48 <= V_148 ; ++ V_48 ) {
if ( V_163 == F_65 ( V_48 ) ) {
V_172 = F_52 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_148 )
break;
return - V_34 ;
}
* V_47 = V_172 ;
return 0 ;
}
static int F_66 ( unsigned int V_163 , unsigned int * V_47 )
{
unsigned int V_172 ;
unsigned int V_48 ;
switch ( V_163 ) {
case V_182 :
V_172 = V_150 ;
break;
case V_183 :
V_172 = V_151 ;
break;
case V_184 :
V_172 = V_152 ;
break;
case V_185 :
V_172 = V_144 ;
break;
case V_186 :
V_172 = V_153 ;
break;
case V_187 :
V_172 = V_142 ;
break;
case V_188 :
V_172 = V_154 ;
break;
case V_189 :
V_172 = V_145 ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_62 ; ++ V_48 ) {
if ( V_163 == F_67 ( V_48 ) ) {
V_172 = F_51 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_62 )
break;
for ( V_48 = 0 ; V_48 <= V_63 ; ++ V_48 ) {
if ( V_163 == F_68 ( V_48 ) ) {
V_172 = F_55 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_63 )
break;
return - V_34 ;
}
* V_47 = V_172 ;
return 0 ;
}
static int F_69 ( unsigned int V_163 , unsigned int * V_47 )
{
unsigned int V_172 ;
unsigned int V_48 ;
switch ( V_163 ) {
case V_190 :
V_172 = V_146 ;
break;
case V_191 :
V_172 = V_157 ;
break;
case V_159 :
V_172 = V_142 ;
break;
case V_192 :
V_172 = V_144 ;
break;
case V_193 :
V_172 = V_158 ;
break;
case V_194 :
V_172 = V_145 ;
break;
default:
for ( V_48 = 0 ; V_48 <= V_72 ; ++ V_48 ) {
if ( V_163 == F_70 ( V_48 ) ) {
V_172 = F_51 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_72 )
break;
for ( V_48 = 0 ; V_48 <= V_160 ; ++ V_48 ) {
if ( V_163 == F_71 ( V_48 ) ) {
V_172 = F_57 ( V_48 ) ;
break;
}
}
if ( V_48 <= V_160 )
break;
return - V_34 ;
}
* V_47 = V_172 ;
return 0 ;
}
static int F_72 ( unsigned int V_163 , unsigned int * V_47 )
{
* V_47 = V_163 ;
return 0 ;
}
static int F_73 ( struct V_12 * V_13 , unsigned int V_195 ,
unsigned int * V_139 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_75 ;
unsigned int V_16 ;
unsigned int V_163 ;
int V_133 ;
V_75 = F_15 ( V_13 , F_33 ( V_20 ) ) ;
if ( ( ( V_75 & V_103 ) == V_165 ) ||
( V_195 == 1 &&
! ( V_11 -> V_39 [ F_20 ( V_20 ) ] & V_161 ) ) ) {
* V_139 = V_164 ;
return 0 ;
}
switch ( V_195 ) {
case 0 :
V_16 = F_18 ( V_20 ) ;
V_163 = F_74 ( F_15 ( V_13 , V_16 ) ) ;
switch ( V_11 -> V_2 ) {
case V_3 :
case V_4 :
default:
V_133 = F_66 ( V_163 , V_139 ) ;
break;
case V_6 :
V_133 = F_63 ( V_163 , V_139 ) ;
break;
}
if ( V_133 )
return V_133 ;
if ( V_75 & V_167 )
* V_139 |= V_166 ;
if ( ( V_75 & V_103 ) != V_104 )
* V_139 |= V_168 ;
break;
case 1 :
V_16 = F_20 ( V_20 ) ;
V_163 = F_75 ( V_11 -> V_39 [ V_16 ] ) ;
switch ( V_11 -> V_2 ) {
case V_3 :
case V_4 :
default:
V_133 = F_72 ( V_163 , V_139 ) ;
break;
case V_6 :
V_133 = F_69 ( V_163 , V_139 ) ;
break;
}
if ( V_133 )
return V_133 ;
if ( V_11 -> V_39 [ V_16 ] & V_170 )
* V_139 |= V_166 ;
if ( ( V_75 & V_103 ) != V_104 )
* V_139 |= V_168 ;
break;
default:
return - V_34 ;
}
return 0 ;
}
int F_76 ( struct V_134 * V_135 ,
struct V_196 * V_197 ,
struct V_198 * V_199 ,
unsigned int * V_200 )
{
struct V_12 * V_13 = V_197 -> V_201 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_202 ;
int V_133 = 0 ;
switch ( V_200 [ 0 ] ) {
case V_203 :
V_133 = F_32 ( V_13 , V_200 [ 1 ] ) ;
break;
case V_204 :
V_133 = F_39 ( V_13 , true , V_200 [ 1 ] ) ;
break;
case V_205 :
V_133 = F_39 ( V_13 , false , 0 ) ;
break;
case V_206 :
V_200 [ 1 ] = 0 ;
V_202 = F_5 ( V_13 , F_77 ( V_20 ) ) ;
if ( V_202 & F_78 ( V_20 ) ) {
V_200 [ 1 ] |= V_207 ;
if ( V_202 & F_79 ( V_20 ) )
V_200 [ 1 ] |= V_208 ;
}
V_200 [ 2 ] = V_207 | V_208 ;
break;
case V_209 :
V_133 = F_45 ( V_13 , V_200 [ 1 ] , V_200 [ 2 ] ) ;
break;
case V_210 :
V_133 = F_47 ( V_13 , & V_200 [ 1 ] , & V_200 [ 2 ] ) ;
break;
case V_211 :
V_133 = F_60 ( V_13 , V_200 [ 1 ] , V_200 [ 2 ] ) ;
break;
case V_212 :
V_133 = F_73 ( V_13 , V_200 [ 1 ] , & V_200 [ 2 ] ) ;
break;
case V_213 :
V_133 = F_61 ( V_13 , V_200 [ 1 ] , V_200 [ 2 ] ) ;
break;
case V_214 :
F_6 ( V_13 ) ;
break;
default:
return - V_34 ;
}
return V_133 ? V_133 : V_199 -> V_215 ;
}
static unsigned int F_80 ( struct V_134 * V_135 ,
struct V_196 * V_197 )
{
struct V_12 * V_13 = V_197 -> V_201 ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_216 ;
F_14 ( V_13 , F_37 ( V_20 ) , V_217 , 0 ) ;
F_14 ( V_13 , F_37 ( V_20 ) ,
V_217 , V_217 ) ;
V_216 = F_5 ( V_13 , F_81 ( V_20 ) ) ;
if ( V_216 != F_5 ( V_13 , F_81 ( V_20 ) ) )
V_216 = F_5 ( V_13 , F_81 ( V_20 ) ) ;
return V_216 ;
}
int F_82 ( struct V_134 * V_135 ,
struct V_196 * V_197 ,
struct V_198 * V_199 ,
unsigned int * V_200 )
{
struct V_12 * V_13 = V_197 -> V_201 ;
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_218 = F_50 ( V_199 -> V_219 ) ;
unsigned int V_20 = V_13 -> V_21 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_199 -> V_215 ; V_48 ++ ) {
switch ( V_218 ) {
case 0 :
V_200 [ V_48 ] = F_80 ( V_135 , V_197 ) ;
break;
case 1 :
V_200 [ V_48 ] = V_11 -> V_39 [ F_83 ( V_20 ) ] ;
break;
case 2 :
V_200 [ V_48 ] = V_11 -> V_39 [ F_84 ( V_20 ) ] ;
break;
}
}
return V_199 -> V_215 ;
}
static unsigned int F_85 ( struct V_12 * V_13 )
{
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_41 = F_5 ( V_13 , F_77 ( V_20 ) ) ;
return ( V_41 & F_86 ( V_20 ) )
? F_84 ( V_20 )
: F_83 ( V_20 ) ;
}
int F_87 ( struct V_134 * V_135 ,
struct V_196 * V_197 ,
struct V_198 * V_199 ,
unsigned int * V_200 )
{
struct V_12 * V_13 = V_197 -> V_201 ;
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_218 = F_50 ( V_199 -> V_219 ) ;
unsigned int V_20 = V_13 -> V_21 ;
unsigned int V_220 ;
if ( V_199 -> V_215 < 1 )
return 0 ;
switch ( V_218 ) {
case 0 :
V_220 = F_85 ( V_13 ) ;
F_4 ( V_13 , V_200 [ 0 ] , V_220 ) ;
F_10 ( V_13 , F_37 ( V_20 ) ,
0 , 0 , V_221 ) ;
F_4 ( V_13 , V_11 -> V_39 [ V_220 ] , V_220 ) ;
break;
case 1 :
V_11 -> V_39 [ F_83 ( V_20 ) ] = V_200 [ 0 ] ;
F_4 ( V_13 , V_200 [ 0 ] , F_83 ( V_20 ) ) ;
break;
case 2 :
V_11 -> V_39 [ F_84 ( V_20 ) ] = V_200 [ 0 ] ;
F_4 ( V_13 , V_200 [ 0 ] , F_84 ( V_20 ) ) ;
break;
default:
return - V_34 ;
}
return 0 ;
}
void F_88 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_20 = V_13 -> V_21 ;
F_6 ( V_13 ) ;
V_11 -> V_39 [ F_89 ( V_20 ) ] = 0x0 ;
F_4 ( V_13 , 0x0 , F_89 ( V_20 ) ) ;
F_14 ( V_13 , F_37 ( V_20 ) ,
~ 0 , V_222 ) ;
F_14 ( V_13 , F_33 ( V_20 ) , ~ 0 , 0 ) ;
V_11 -> V_39 [ F_83 ( V_20 ) ] = 0x0 ;
F_4 ( V_13 , 0x0 , F_83 ( V_20 ) ) ;
V_11 -> V_39 [ F_84 ( V_20 ) ] = 0x0 ;
F_4 ( V_13 , 0x0 , F_84 ( V_20 ) ) ;
F_14 ( V_13 , F_18 ( V_20 ) , ~ 0 , 0 ) ;
if ( F_34 ( V_11 ) )
F_14 ( V_13 , F_17 ( V_20 ) , ~ 0 , 0 ) ;
if ( F_3 ( V_11 ) ) {
V_11 -> V_39 [ F_20 ( V_20 ) ] = 0x0 ;
F_4 ( V_13 , 0x0 , F_20 ( V_20 ) ) ;
}
F_14 ( V_13 , F_90 ( V_20 ) , ~ 0 , 0x0 ) ;
F_14 ( V_13 , F_91 ( V_20 ) , ~ 0 , 0x0 ) ;
}
void F_92 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_93 ( V_11 -> V_223 ) ;
F_93 ( V_11 ) ;
}
static int T_2 F_94 ( void )
{
return 0 ;
}
static void T_3 F_95 ( void )
{
}
