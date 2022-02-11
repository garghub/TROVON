static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 = F_2 ( V_3 ) ;
if ( V_4 == 0 )
return;
F_3 ( 1 , L_1 ,
F_4 ( V_3 ) , V_4 ) ;
F_5 ( V_3 , 0xffffffff ) ;
F_6 ( V_3 ) ;
F_5 ( V_3 , 0xffffffff ) ;
F_6 ( V_3 ) ;
}
static inline void
F_7 ( struct V_1 * V_2 ,
T_3 V_5 ,
T_3 V_6 )
{
T_3 V_4 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_6 & ~ V_5 ) ;
V_4 = F_2 ( V_8 ) ;
V_4 &= ~ V_5 ;
V_4 |= V_6 ;
F_5 ( V_8 , V_4 ) ;
}
void F_10 ( struct V_1 * V_2 ,
T_3 V_5 ,
T_3 V_6 )
{
F_11 ( & V_2 -> V_7 ) ;
F_7 ( V_2 , V_5 , V_6 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_13 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_11 = V_2 -> V_12 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_12 ) {
V_2 -> V_12 = V_11 ;
F_5 ( V_13 , V_2 -> V_12 ) ;
F_6 ( V_13 ) ;
}
}
static void F_15 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_2 -> V_14 &= ~ V_9 ;
V_2 -> V_14 |= ( ~ V_10 & V_9 ) ;
F_5 ( V_15 , V_2 -> V_14 ) ;
F_6 ( V_15 ) ;
}
void F_16 ( struct V_1 * V_2 , T_3 V_5 )
{
F_15 ( V_2 , V_5 , V_5 ) ;
}
void F_17 ( struct V_1 * V_2 , T_3 V_5 )
{
F_15 ( V_2 , V_5 , 0 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
return F_19 ( V_2 ) -> V_16 >= 8 ? F_20 ( 2 ) : V_17 ;
}
static T_1 F_21 ( struct V_1 * V_2 )
{
return F_19 ( V_2 ) -> V_16 >= 8 ? F_22 ( 2 ) : V_18 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
return F_19 ( V_2 ) -> V_16 >= 8 ? F_24 ( 2 ) : V_19 ;
}
static void F_25 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
F_9 ( V_10 & ~ V_9 ) ;
F_8 ( & V_2 -> V_7 ) ;
V_11 = V_2 -> V_20 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_20 ) {
V_2 -> V_20 = V_11 ;
F_5 ( F_21 ( V_2 ) , V_2 -> V_20 ) ;
F_6 ( F_21 ( V_2 ) ) ;
}
}
void F_26 ( struct V_1 * V_2 , T_3 V_5 )
{
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_25 ( V_2 , V_5 , V_5 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
T_3 V_5 )
{
F_25 ( V_2 , V_5 , 0 ) ;
}
void F_28 ( struct V_1 * V_2 , T_3 V_5 )
{
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_27 ( V_2 , V_5 ) ;
}
void F_29 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_3 = F_18 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_5 ( V_3 , V_2 -> V_24 ) ;
F_5 ( V_3 , V_2 -> V_24 ) ;
F_6 ( V_3 ) ;
V_2 -> V_25 . V_26 = 0 ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_30 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_11 ( & V_2 -> V_7 ) ;
F_9 ( V_2 -> V_25 . V_26 ) ;
F_9 ( F_2 ( F_18 ( V_2 ) ) & V_2 -> V_24 ) ;
V_2 -> V_25 . V_27 = true ;
F_5 ( F_23 ( V_2 ) , F_2 ( F_23 ( V_2 ) ) |
V_2 -> V_24 ) ;
F_26 ( V_2 , V_2 -> V_24 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
T_2 F_31 ( struct V_1 * V_2 , T_2 V_5 )
{
if ( F_19 ( V_2 ) -> V_16 <= 7 && ! F_32 ( V_2 ) )
V_5 &= ~ V_28 ;
if ( F_19 ( V_2 ) -> V_16 >= 8 )
V_5 &= ~ V_29 ;
return V_5 ;
}
void F_33 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_11 ( & V_2 -> V_7 ) ;
V_2 -> V_25 . V_27 = false ;
F_12 ( & V_2 -> V_7 ) ;
F_34 ( & V_2 -> V_25 . V_30 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_5 ( V_31 , F_31 ( V_2 , ~ 0 ) ) ;
F_27 ( V_2 , V_2 -> V_24 ) ;
F_5 ( F_23 ( V_2 ) , F_2 ( F_23 ( V_2 ) ) &
~ V_2 -> V_24 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_35 ( V_22 -> V_32 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
T_3 V_33 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_33 = F_2 ( V_34 ) ;
V_11 = V_33 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_33 ) {
F_5 ( V_34 , V_11 ) ;
F_6 ( V_34 ) ;
}
}
void F_37 ( struct V_1 * V_2 ,
enum V_35 V_35 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_11 = V_2 -> V_36 [ V_35 ] ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_36 [ V_35 ] ) {
V_2 -> V_36 [ V_35 ] = V_11 ;
F_5 ( F_38 ( V_35 ) , V_2 -> V_36 [ V_35 ] ) ;
F_6 ( F_38 ( V_35 ) ) ;
}
}
void F_39 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_37 = F_2 ( V_38 ) ;
V_37 &= ~ V_9 ;
V_37 |= ( ~ V_10 & V_9 ) ;
F_9 ( V_10 & ~ V_9 ) ;
F_8 ( & V_2 -> V_7 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_5 ( V_38 , V_37 ) ;
F_6 ( V_38 ) ;
}
static void
F_40 ( struct V_1 * V_2 , enum V_35 V_35 ,
T_2 V_39 , T_2 V_40 )
{
T_1 V_3 = F_41 ( V_35 ) ;
T_2 V_41 = F_2 ( V_3 ) & V_42 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_42 ( V_39 & ~ V_42 ||
V_40 & ~ V_43 ,
L_2 ,
F_43 ( V_35 ) , V_39 , V_40 ) )
return;
if ( ( V_41 & V_39 ) == V_39 )
return;
V_2 -> V_44 [ V_35 ] |= V_40 ;
V_41 |= V_39 | V_40 ;
F_5 ( V_3 , V_41 ) ;
F_6 ( V_3 ) ;
}
static void
F_44 ( struct V_1 * V_2 , enum V_35 V_35 ,
T_2 V_39 , T_2 V_40 )
{
T_1 V_3 = F_41 ( V_35 ) ;
T_2 V_41 = F_2 ( V_3 ) & V_42 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_42 ( V_39 & ~ V_42 ||
V_40 & ~ V_43 ,
L_2 ,
F_43 ( V_35 ) , V_39 , V_40 ) )
return;
if ( ( V_41 & V_39 ) == 0 )
return;
V_2 -> V_44 [ V_35 ] &= ~ V_40 ;
V_41 &= ~ V_39 ;
F_5 ( V_3 , V_41 ) ;
F_6 ( V_3 ) ;
}
static T_2 F_45 ( struct V_21 * V_22 , T_2 V_40 )
{
T_2 V_39 = V_40 << 16 ;
if ( F_46 ( V_40 & V_45 ) )
return 0 ;
if ( F_46 ( V_40 & V_46 ) )
return 0 ;
V_39 &= ~ ( V_47 |
V_48 |
V_49 ) ;
if ( V_40 & V_50 )
V_39 |= V_48 ;
if ( V_40 & V_51 )
V_39 |= V_49 ;
return V_39 ;
}
void
F_47 ( struct V_1 * V_2 , enum V_35 V_35 ,
T_2 V_40 )
{
T_2 V_39 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) )
V_39 = F_45 ( V_2 -> V_22 ,
V_40 ) ;
else
V_39 = V_40 << 16 ;
F_40 ( V_2 , V_35 , V_39 , V_40 ) ;
}
void
F_50 ( struct V_1 * V_2 , enum V_35 V_35 ,
T_2 V_40 )
{
T_2 V_39 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) )
V_39 = F_45 ( V_2 -> V_22 ,
V_40 ) ;
else
V_39 = V_40 << 16 ;
F_44 ( V_2 , V_35 , V_39 , V_40 ) ;
}
static void F_51 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 -> V_52 . V_53 || ! F_52 ( V_22 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
F_47 ( V_2 , V_54 , V_55 ) ;
if ( F_19 ( V_22 ) -> V_16 >= 4 )
F_47 ( V_2 , V_56 ,
V_55 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static T_2 F_53 ( struct V_21 * V_22 , unsigned int V_35 )
{
return 0 ;
}
static T_2 F_54 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_57 , V_58 ;
T_2 V_59 , V_60 , V_61 , V_62 , V_63 , V_64 , V_65 ;
struct V_66 * V_66 =
F_55 ( V_2 -> V_67 [ V_35 ] ) ;
const struct V_68 * V_69 = & V_66 -> V_70 . V_71 ;
V_65 = V_69 -> V_72 ;
V_64 = V_69 -> V_73 ;
V_63 = V_69 -> V_74 ;
if ( V_69 -> V_75 & V_76 )
V_63 = F_56 ( V_63 , 2 ) ;
V_63 *= V_65 ;
V_63 -= V_65 - V_64 ;
V_57 = F_57 ( V_35 ) ;
V_58 = F_58 ( V_35 ) ;
do {
V_59 = F_2 ( V_57 ) & V_77 ;
V_61 = F_2 ( V_58 ) ;
V_60 = F_2 ( V_57 ) & V_77 ;
} while ( V_59 != V_60 );
V_59 >>= V_78 ;
V_62 = V_61 & V_79 ;
V_61 >>= V_80 ;
return ( ( ( V_59 << 8 ) | V_61 ) + ( V_62 >= V_63 ) ) & 0xffffff ;
}
static T_2 F_59 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
return F_2 ( F_60 ( V_35 ) ) ;
}
static int F_61 ( struct V_66 * V_81 )
{
struct V_21 * V_22 = V_81 -> V_70 . V_22 ;
struct V_1 * V_2 = V_22 -> V_23 ;
const struct V_68 * V_69 = & V_81 -> V_70 . V_71 ;
enum V_35 V_35 = V_81 -> V_35 ;
int V_82 , V_83 ;
V_83 = V_69 -> V_84 ;
if ( V_69 -> V_75 & V_76 )
V_83 /= 2 ;
if ( F_62 ( V_22 ) )
V_82 = F_63 ( F_64 ( V_35 ) ) & V_85 ;
else
V_82 = F_63 ( F_64 ( V_35 ) ) & V_86 ;
if ( F_65 ( V_22 ) && ! V_82 ) {
int V_87 , V_88 ;
for ( V_87 = 0 ; V_87 < 100 ; V_87 ++ ) {
F_66 ( 1 ) ;
V_88 = F_67 ( V_2 , F_64 ( V_35 ) ) &
V_86 ;
if ( V_88 != V_82 ) {
V_82 = V_88 ;
break;
}
}
}
return ( V_82 + V_81 -> V_89 ) % V_83 ;
}
static int F_68 ( struct V_21 * V_22 , unsigned int V_35 ,
unsigned int V_75 , int * V_90 , int * V_91 ,
T_4 * V_92 , T_4 * V_93 ,
const struct V_68 * V_69 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_94 * V_81 = V_2 -> V_67 [ V_35 ] ;
struct V_66 * V_66 = F_55 ( V_81 ) ;
int V_82 ;
int V_63 , V_95 , V_64 , V_65 , V_83 ;
bool V_96 = true ;
int V_97 = 0 ;
unsigned long V_98 ;
if ( F_9 ( ! V_69 -> V_99 ) ) {
F_69 ( L_3
L_4 , F_43 ( V_35 ) ) ;
return 0 ;
}
V_65 = V_69 -> V_72 ;
V_64 = V_69 -> V_73 ;
V_83 = V_69 -> V_84 ;
V_63 = V_69 -> V_74 ;
V_95 = V_69 -> V_100 ;
if ( V_69 -> V_75 & V_76 ) {
V_63 = F_56 ( V_63 , 2 ) ;
V_95 /= 2 ;
V_83 /= 2 ;
}
V_97 |= V_101 | V_102 ;
F_70 ( & V_2 -> V_103 . V_104 , V_98 ) ;
if ( V_92 )
* V_92 = F_71 () ;
if ( F_62 ( V_22 ) || F_72 ( V_22 ) || F_19 ( V_22 ) -> V_16 >= 5 ) {
V_82 = F_61 ( V_66 ) ;
} else {
V_82 = ( F_63 ( F_58 ( V_35 ) ) & V_79 ) >> V_105 ;
V_63 *= V_65 ;
V_95 *= V_65 ;
V_83 *= V_65 ;
if ( V_82 >= V_83 )
V_82 = V_83 - 1 ;
V_82 = ( V_82 + V_65 - V_64 ) % V_83 ;
}
if ( V_93 )
* V_93 = F_71 () ;
F_73 ( & V_2 -> V_103 . V_104 , V_98 ) ;
V_96 = V_82 >= V_63 && V_82 < V_95 ;
if ( V_82 >= V_63 )
V_82 -= V_95 ;
else
V_82 += V_83 - V_95 ;
if ( F_62 ( V_22 ) || F_72 ( V_22 ) || F_19 ( V_22 ) -> V_16 >= 5 ) {
* V_90 = V_82 ;
* V_91 = 0 ;
} else {
* V_90 = V_82 / V_65 ;
* V_91 = V_82 - ( * V_90 * V_65 ) ;
}
if ( V_96 )
V_97 |= V_106 ;
return V_97 ;
}
int F_74 ( struct V_66 * V_81 )
{
struct V_1 * V_2 = V_81 -> V_70 . V_22 -> V_23 ;
unsigned long V_98 ;
int V_82 ;
F_70 ( & V_2 -> V_103 . V_104 , V_98 ) ;
V_82 = F_61 ( V_81 ) ;
F_73 ( & V_2 -> V_103 . V_104 , V_98 ) ;
return V_82 ;
}
static int F_75 ( struct V_21 * V_22 , unsigned int V_35 ,
int * V_107 ,
struct V_108 * V_109 ,
unsigned V_75 )
{
struct V_94 * V_81 ;
if ( V_35 >= F_19 ( V_22 ) -> V_110 ) {
F_76 ( L_5 , V_35 ) ;
return - V_111 ;
}
V_81 = F_77 ( V_22 , V_35 ) ;
if ( V_81 == NULL ) {
F_76 ( L_5 , V_35 ) ;
return - V_111 ;
}
if ( ! V_81 -> V_71 . V_99 ) {
F_78 ( L_6 , V_35 ) ;
return - V_112 ;
}
return F_79 ( V_22 , V_35 , V_107 ,
V_109 , V_75 ,
& V_81 -> V_71 ) ;
}
static void F_80 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_113 , V_114 , V_115 , V_116 ;
T_5 V_117 ;
F_81 ( & V_118 ) ;
F_82 ( V_119 , F_2 ( V_119 ) ) ;
V_117 = V_2 -> V_120 . V_121 ;
F_82 ( V_119 , V_122 ) ;
V_113 = F_2 ( V_123 ) ;
V_114 = F_2 ( V_124 ) ;
V_115 = F_2 ( V_125 ) ;
V_116 = F_2 ( V_126 ) ;
if ( V_113 > V_115 ) {
if ( V_2 -> V_120 . V_121 != V_2 -> V_120 . V_127 )
V_117 = V_2 -> V_120 . V_121 - 1 ;
if ( V_117 < V_2 -> V_120 . V_127 )
V_117 = V_2 -> V_120 . V_127 ;
} else if ( V_114 < V_116 ) {
if ( V_2 -> V_120 . V_121 != V_2 -> V_120 . V_128 )
V_117 = V_2 -> V_120 . V_121 + 1 ;
if ( V_117 > V_2 -> V_120 . V_128 )
V_117 = V_2 -> V_120 . V_128 ;
}
if ( F_83 ( V_22 , V_117 ) )
V_2 -> V_120 . V_121 = V_117 ;
F_84 ( & V_118 ) ;
return;
}
static void F_85 ( struct V_129 * V_130 )
{
if ( ! F_86 ( V_130 ) )
return;
F_87 ( V_130 ) ;
F_88 ( & V_130 -> V_131 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
V_133 -> V_134 = F_90 ( V_2 , V_135 ) ;
V_133 -> V_136 = F_2 ( V_137 ) ;
V_133 -> V_138 = F_2 ( V_139 ) ;
}
static bool F_91 ( struct V_1 * V_2 ,
const struct V_132 * V_140 ,
const struct V_132 * V_141 ,
int V_142 )
{
T_6 time , V_143 ;
unsigned int V_144 = 100 ;
if ( V_140 -> V_134 == 0 )
return false ;
if ( F_2 ( V_145 ) & V_146 )
V_144 <<= 8 ;
time = V_141 -> V_134 - V_140 -> V_134 ;
time *= V_142 * V_2 -> V_147 ;
V_143 = V_141 -> V_136 - V_140 -> V_136 ;
V_143 += V_141 -> V_138 - V_140 -> V_138 ;
V_143 *= V_144 * V_148 ;
return V_143 >= time ;
}
void F_92 ( struct V_1 * V_2 )
{
F_89 ( V_2 , & V_2 -> V_25 . V_149 ) ;
V_2 -> V_25 . V_150 = V_2 -> V_25 . V_149 ;
}
static T_2 F_93 ( struct V_1 * V_2 , T_2 V_26 )
{
struct V_132 V_141 ;
T_2 V_151 = 0 ;
if ( ( V_26 & ( V_152 | V_28 ) ) == 0 )
return 0 ;
F_89 ( V_2 , & V_141 ) ;
if ( V_141 . V_134 == 0 )
return 0 ;
if ( V_26 & V_152 ) {
if ( ! F_91 ( V_2 ,
& V_2 -> V_25 . V_149 , & V_141 ,
V_2 -> V_25 . V_153 ) )
V_151 |= V_154 ;
V_2 -> V_25 . V_149 = V_141 ;
}
if ( V_26 & V_28 ) {
if ( F_91 ( V_2 ,
& V_2 -> V_25 . V_150 , & V_141 ,
V_2 -> V_25 . V_155 ) )
V_151 |= V_156 ;
V_2 -> V_25 . V_150 = V_141 ;
}
return V_151 ;
}
static bool F_94 ( struct V_1 * V_2 )
{
struct V_129 * V_130 ;
int V_87 ;
F_95 (ring, dev_priv, i)
if ( V_130 -> V_157 )
return true ;
return false ;
}
static void F_96 ( struct V_158 * V_30 )
{
struct V_1 * V_2 =
F_97 ( V_30 , struct V_1 , V_25 . V_30 ) ;
bool V_159 ;
int V_117 , V_160 , V_161 , V_162 ;
T_2 V_26 ;
F_11 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_25 . V_27 ) {
F_12 ( & V_2 -> V_7 ) ;
return;
}
F_98 ( V_2 ) ;
V_26 = V_2 -> V_25 . V_26 ;
V_2 -> V_25 . V_26 = 0 ;
F_26 ( V_2 , V_2 -> V_24 ) ;
V_159 = V_2 -> V_25 . V_159 ;
V_2 -> V_25 . V_159 = false ;
F_12 ( & V_2 -> V_7 ) ;
F_9 ( V_26 & ~ V_2 -> V_24 ) ;
if ( ( V_26 & V_2 -> V_24 ) == 0 && ! V_159 )
goto V_163;
F_99 ( & V_2 -> V_25 . V_164 ) ;
V_26 |= F_93 ( V_2 , V_26 ) ;
V_160 = V_2 -> V_25 . V_165 ;
V_117 = V_2 -> V_25 . V_166 ;
V_161 = V_2 -> V_25 . V_167 ;
V_162 = V_2 -> V_25 . V_168 ;
if ( V_159 ) {
V_117 = V_2 -> V_25 . V_168 ;
V_160 = 0 ;
} else if ( V_26 & V_156 ) {
if ( V_160 > 0 )
V_160 *= 2 ;
else
V_160 = F_49 ( V_2 ) ? 2 : 1 ;
if ( V_117 < V_2 -> V_25 . V_169 - V_160 ) {
V_117 = V_2 -> V_25 . V_169 ;
V_160 = 0 ;
}
} else if ( F_94 ( V_2 ) ) {
V_160 = 0 ;
} else if ( V_26 & V_170 ) {
if ( V_2 -> V_25 . V_166 > V_2 -> V_25 . V_169 )
V_117 = V_2 -> V_25 . V_169 ;
else
V_117 = V_2 -> V_25 . V_167 ;
V_160 = 0 ;
} else if ( V_26 & V_154 ) {
if ( V_160 < 0 )
V_160 *= 2 ;
else
V_160 = F_49 ( V_2 ) ? - 2 : - 1 ;
} else {
V_160 = 0 ;
}
V_2 -> V_25 . V_165 = V_160 ;
V_117 += V_160 ;
V_117 = F_100 ( int , V_117 , V_161 , V_162 ) ;
F_101 ( V_2 -> V_22 , V_117 ) ;
F_102 ( & V_2 -> V_25 . V_164 ) ;
V_163:
F_103 ( V_2 ) ;
}
static void F_104 ( struct V_158 * V_30 )
{
struct V_1 * V_2 =
F_97 ( V_30 , struct V_1 , V_171 . V_172 ) ;
T_2 V_173 , V_174 , V_175 , V_176 ;
char * V_177 [ 6 ] ;
T_3 V_178 ;
T_7 V_179 = 0 ;
F_99 ( & V_2 -> V_22 -> V_180 ) ;
if ( F_9 ( ! V_2 -> V_171 . V_181 ) )
goto V_163;
V_178 = F_2 ( V_182 ) ;
F_5 ( V_182 , V_178 & ~ V_183 ) ;
F_6 ( V_182 ) ;
while ( ( V_179 = F_105 ( V_2 -> V_171 . V_181 ) ) != 0 ) {
T_1 V_3 ;
V_179 -- ;
if ( F_46 ( V_179 >= F_106 ( V_2 -> V_22 ) ) )
break;
V_2 -> V_171 . V_181 &= ~ ( 1 << V_179 ) ;
V_3 = F_107 ( V_179 ) ;
V_173 = F_2 ( V_3 ) ;
V_174 = F_108 ( V_173 ) ;
V_175 = F_109 ( V_173 ) ;
V_176 = F_110 ( V_173 ) ;
F_5 ( V_3 , V_184 | V_185 ) ;
F_6 ( V_3 ) ;
V_177 [ 0 ] = V_186 L_7 ;
V_177 [ 1 ] = F_111 ( V_187 , L_8 , V_174 ) ;
V_177 [ 2 ] = F_111 ( V_187 , L_9 , V_175 ) ;
V_177 [ 3 ] = F_111 ( V_187 , L_10 , V_176 ) ;
V_177 [ 4 ] = F_111 ( V_187 , L_11 , V_179 ) ;
V_177 [ 5 ] = NULL ;
F_112 ( & V_2 -> V_22 -> V_188 -> V_189 -> V_190 ,
V_191 , V_177 ) ;
F_113 ( L_12 ,
V_179 , V_174 , V_175 , V_176 ) ;
F_114 ( V_177 [ 4 ] ) ;
F_114 ( V_177 [ 3 ] ) ;
F_114 ( V_177 [ 2 ] ) ;
F_114 ( V_177 [ 1 ] ) ;
}
F_5 ( V_182 , V_178 ) ;
V_163:
F_9 ( V_2 -> V_171 . V_181 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_16 ( V_2 , F_115 ( V_2 -> V_22 ) ) ;
F_12 ( & V_2 -> V_7 ) ;
F_102 ( & V_2 -> V_22 -> V_180 ) ;
}
static void F_116 ( struct V_21 * V_22 , T_2 V_192 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! F_117 ( V_22 ) )
return;
F_81 ( & V_2 -> V_7 ) ;
F_17 ( V_2 , F_115 ( V_22 ) ) ;
F_84 ( & V_2 -> V_7 ) ;
V_192 &= F_115 ( V_22 ) ;
if ( V_192 & V_193 )
V_2 -> V_171 . V_181 |= 1 << 1 ;
if ( V_192 & V_194 )
V_2 -> V_171 . V_181 |= 1 << 0 ;
F_118 ( V_2 -> V_195 , & V_2 -> V_171 . V_172 ) ;
}
static void F_119 ( struct V_21 * V_22 ,
struct V_1 * V_2 ,
T_2 V_196 )
{
if ( V_196 &
( V_197 | V_198 ) )
F_85 ( & V_2 -> V_130 [ V_199 ] ) ;
if ( V_196 & V_200 )
F_85 ( & V_2 -> V_130 [ V_201 ] ) ;
}
static void F_120 ( struct V_21 * V_22 ,
struct V_1 * V_2 ,
T_2 V_196 )
{
if ( V_196 &
( V_197 | V_198 ) )
F_85 ( & V_2 -> V_130 [ V_199 ] ) ;
if ( V_196 & V_202 )
F_85 ( & V_2 -> V_130 [ V_201 ] ) ;
if ( V_196 & V_203 )
F_85 ( & V_2 -> V_130 [ V_204 ] ) ;
if ( V_196 & ( V_205 |
V_206 |
V_207 ) )
F_113 ( L_13 , V_196 ) ;
if ( V_196 & F_115 ( V_22 ) )
F_116 ( V_22 , V_196 ) ;
}
static T_8 void
F_121 ( struct V_129 * V_130 , T_2 V_192 , int V_208 )
{
if ( V_192 & ( V_197 << V_208 ) )
F_85 ( V_130 ) ;
if ( V_192 & ( V_209 << V_208 ) )
F_122 ( V_130 ) ;
}
static T_9 F_123 ( struct V_1 * V_2 ,
T_2 V_210 )
{
T_9 V_97 = V_211 ;
if ( V_210 & ( V_212 | V_213 ) ) {
T_2 V_192 = F_63 ( F_20 ( 0 ) ) ;
if ( V_192 ) {
F_124 ( F_20 ( 0 ) , V_192 ) ;
V_97 = V_214 ;
F_121 ( & V_2 -> V_130 [ V_199 ] ,
V_192 , V_215 ) ;
F_121 ( & V_2 -> V_130 [ V_204 ] ,
V_192 , V_216 ) ;
} else
F_76 ( L_14 ) ;
}
if ( V_210 & ( V_217 | V_218 ) ) {
T_2 V_192 = F_63 ( F_20 ( 1 ) ) ;
if ( V_192 ) {
F_124 ( F_20 ( 1 ) , V_192 ) ;
V_97 = V_214 ;
F_121 ( & V_2 -> V_130 [ V_201 ] ,
V_192 , V_219 ) ;
F_121 ( & V_2 -> V_130 [ V_220 ] ,
V_192 , V_221 ) ;
} else
F_76 ( L_15 ) ;
}
if ( V_210 & V_222 ) {
T_2 V_192 = F_63 ( F_20 ( 3 ) ) ;
if ( V_192 ) {
F_124 ( F_20 ( 3 ) , V_192 ) ;
V_97 = V_214 ;
F_121 ( & V_2 -> V_130 [ V_223 ] ,
V_192 , V_224 ) ;
} else
F_76 ( L_16 ) ;
}
if ( V_210 & V_225 ) {
T_2 V_192 = F_63 ( F_20 ( 2 ) ) ;
if ( V_192 & V_2 -> V_24 ) {
F_124 ( F_20 ( 2 ) ,
V_192 & V_2 -> V_24 ) ;
V_97 = V_214 ;
F_125 ( V_2 , V_192 ) ;
} else
F_76 ( L_17 ) ;
}
return V_97 ;
}
static bool F_126 ( enum V_226 V_226 , T_2 V_4 )
{
switch ( V_226 ) {
case V_227 :
return V_4 & V_228 ;
case V_229 :
return V_4 & V_230 ;
case V_231 :
return V_4 & V_232 ;
default:
return false ;
}
}
static bool F_127 ( enum V_226 V_226 , T_2 V_4 )
{
switch ( V_226 ) {
case V_233 :
return V_4 & V_234 ;
default:
return false ;
}
}
static bool F_128 ( enum V_226 V_226 , T_2 V_4 )
{
switch ( V_226 ) {
case V_227 :
return V_4 & V_228 ;
case V_229 :
return V_4 & V_230 ;
case V_231 :
return V_4 & V_232 ;
case V_235 :
return V_4 & V_236 ;
default:
return false ;
}
}
static bool F_129 ( enum V_226 V_226 , T_2 V_4 )
{
switch ( V_226 ) {
case V_227 :
return V_4 & V_237 ;
default:
return false ;
}
}
static bool F_130 ( enum V_226 V_226 , T_2 V_4 )
{
switch ( V_226 ) {
case V_229 :
return V_4 & V_230 ;
case V_231 :
return V_4 & V_232 ;
case V_235 :
return V_4 & V_236 ;
default:
return false ;
}
}
static bool F_131 ( enum V_226 V_226 , T_2 V_4 )
{
switch ( V_226 ) {
case V_229 :
return V_4 & V_238 ;
case V_231 :
return V_4 & V_239 ;
case V_235 :
return V_4 & V_240 ;
default:
return false ;
}
}
static void F_132 ( T_2 * V_241 , T_2 * V_242 ,
T_2 V_243 , T_2 V_244 ,
const T_2 V_245 [ V_246 ] ,
bool F_133 ( enum V_226 V_226 , T_2 V_4 ) )
{
enum V_226 V_226 ;
int V_87 ;
F_134 (i) {
if ( ( V_245 [ V_87 ] & V_243 ) == 0 )
continue;
* V_241 |= F_135 ( V_87 ) ;
if ( ! F_136 ( V_87 , & V_226 ) )
continue;
if ( F_133 ( V_226 , V_244 ) )
* V_242 |= F_135 ( V_87 ) ;
}
F_69 ( L_18 ,
V_243 , V_244 , * V_241 ) ;
}
static void F_137 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_88 ( & V_2 -> V_247 ) ;
}
static void F_138 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_88 ( & V_2 -> V_247 ) ;
}
static void F_139 ( struct V_21 * V_22 , enum V_35 V_35 ,
T_3 V_248 , T_3 V_249 ,
T_3 V_250 , T_3 V_251 ,
T_3 V_252 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_253 * V_254 = & V_2 -> V_254 [ V_35 ] ;
struct V_255 * V_256 ;
int V_257 , V_258 ;
F_81 ( & V_254 -> V_104 ) ;
if ( ! V_254 -> V_259 ) {
F_84 ( & V_254 -> V_104 ) ;
F_78 ( L_19 ) ;
return;
}
V_257 = V_254 -> V_257 ;
V_258 = V_254 -> V_258 ;
if ( F_140 ( V_257 , V_258 , V_260 ) < 1 ) {
F_84 ( & V_254 -> V_104 ) ;
F_76 ( L_20 ) ;
return;
}
V_256 = & V_254 -> V_259 [ V_257 ] ;
V_256 -> V_261 = V_22 -> V_262 -> V_263 ( V_22 , V_35 ) ;
V_256 -> V_264 [ 0 ] = V_248 ;
V_256 -> V_264 [ 1 ] = V_249 ;
V_256 -> V_264 [ 2 ] = V_250 ;
V_256 -> V_264 [ 3 ] = V_251 ;
V_256 -> V_264 [ 4 ] = V_252 ;
V_257 = ( V_257 + 1 ) & ( V_260 - 1 ) ;
V_254 -> V_257 = V_257 ;
F_84 ( & V_254 -> V_104 ) ;
F_141 ( & V_254 -> V_195 ) ;
}
static inline void
F_139 ( struct V_21 * V_22 , enum V_35 V_35 ,
T_3 V_248 , T_3 V_249 ,
T_3 V_250 , T_3 V_251 ,
T_3 V_252 ) {}
static void F_142 ( struct V_21 * V_22 , enum V_35 V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_139 ( V_22 , V_35 ,
F_2 ( F_143 ( V_35 ) ) ,
0 , 0 , 0 , 0 ) ;
}
static void F_144 ( struct V_21 * V_22 , enum V_35 V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_139 ( V_22 , V_35 ,
F_2 ( F_143 ( V_35 ) ) ,
F_2 ( F_145 ( V_35 ) ) ,
F_2 ( F_146 ( V_35 ) ) ,
F_2 ( F_147 ( V_35 ) ) ,
F_2 ( F_148 ( V_35 ) ) ) ;
}
static void F_149 ( struct V_21 * V_22 , enum V_35 V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_3 V_265 , V_266 ;
if ( F_19 ( V_22 ) -> V_16 >= 3 )
V_265 = F_2 ( F_150 ( V_35 ) ) ;
else
V_265 = 0 ;
if ( F_19 ( V_22 ) -> V_16 >= 5 || F_72 ( V_22 ) )
V_266 = F_2 ( F_151 ( V_35 ) ) ;
else
V_266 = 0 ;
F_139 ( V_22 , V_35 ,
F_2 ( F_152 ( V_35 ) ) ,
F_2 ( F_153 ( V_35 ) ) ,
F_2 ( F_154 ( V_35 ) ) ,
V_265 , V_266 ) ;
}
static void F_125 ( struct V_1 * V_2 , T_2 V_26 )
{
if ( V_26 & V_2 -> V_24 ) {
F_81 ( & V_2 -> V_7 ) ;
F_28 ( V_2 , V_26 & V_2 -> V_24 ) ;
if ( V_2 -> V_25 . V_27 ) {
V_2 -> V_25 . V_26 |= V_26 & V_2 -> V_24 ;
F_118 ( V_2 -> V_195 , & V_2 -> V_25 . V_30 ) ;
}
F_84 ( & V_2 -> V_7 ) ;
}
if ( F_19 ( V_2 ) -> V_16 >= 8 )
return;
if ( F_155 ( V_2 -> V_22 ) ) {
if ( V_26 & V_267 )
F_85 ( & V_2 -> V_130 [ V_223 ] ) ;
if ( V_26 & V_268 )
F_113 ( L_21 , V_26 ) ;
}
}
static bool F_156 ( struct V_21 * V_22 , enum V_35 V_35 )
{
if ( ! F_157 ( V_22 , V_35 ) )
return false ;
return true ;
}
static void F_158 ( struct V_21 * V_22 , T_2 V_192 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_269 [ V_270 ] = { } ;
int V_35 ;
F_81 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_271 ) {
F_84 ( & V_2 -> V_7 ) ;
return;
}
F_159 (dev_priv, pipe) {
T_1 V_3 ;
T_2 V_5 , V_272 = 0 ;
V_5 = V_47 ;
switch ( V_35 ) {
case V_56 :
V_272 = V_273 ;
break;
case V_54 :
V_272 = V_274 ;
break;
case V_275 :
V_272 = V_276 ;
break;
}
if ( V_192 & V_272 )
V_5 |= V_2 -> V_44 [ V_35 ] ;
if ( ! V_5 )
continue;
V_3 = F_41 ( V_35 ) ;
V_5 |= V_42 ;
V_269 [ V_35 ] = F_2 ( V_3 ) & V_5 ;
if ( V_269 [ V_35 ] & ( V_47 |
V_43 ) )
F_5 ( V_3 , V_269 [ V_35 ] ) ;
}
F_84 ( & V_2 -> V_7 ) ;
F_159 (dev_priv, pipe) {
if ( V_269 [ V_35 ] & V_277 &&
F_156 ( V_22 , V_35 ) )
F_160 ( V_22 , V_35 ) ;
if ( V_269 [ V_35 ] & V_278 ) {
F_161 ( V_22 , V_35 ) ;
F_162 ( V_22 , V_35 ) ;
}
if ( V_269 [ V_35 ] & V_279 )
F_149 ( V_22 , V_35 ) ;
if ( V_269 [ V_35 ] & V_47 )
F_163 ( V_2 , V_35 ) ;
}
if ( V_269 [ 0 ] & V_280 )
F_137 ( V_22 ) ;
}
static void F_164 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_281 = F_2 ( V_282 ) ;
T_2 V_241 = 0 , V_242 = 0 ;
if ( ! V_281 )
return;
F_5 ( V_282 , V_281 ) ;
F_6 ( V_282 ) ;
if ( F_72 ( V_22 ) || F_48 ( V_22 ) || F_49 ( V_22 ) ) {
T_2 V_243 = V_281 & V_283 ;
if ( V_243 ) {
F_132 ( & V_241 , & V_242 , V_243 ,
V_243 , V_284 ,
F_131 ) ;
F_165 ( V_22 , V_241 , V_242 ) ;
}
if ( V_281 & V_285 )
F_138 ( V_22 ) ;
} else {
T_2 V_243 = V_281 & V_286 ;
if ( V_243 ) {
F_132 ( & V_241 , & V_242 , V_243 ,
V_243 , V_287 ,
F_131 ) ;
F_165 ( V_22 , V_241 , V_242 ) ;
}
}
}
static T_9 F_166 ( int V_32 , void * V_288 )
{
struct V_21 * V_22 = V_288 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_192 , V_196 , V_26 ;
T_9 V_97 = V_211 ;
if ( ! F_14 ( V_2 ) )
return V_211 ;
F_167 ( V_2 ) ;
while ( true ) {
V_196 = F_2 ( V_289 ) ;
if ( V_196 )
F_5 ( V_289 , V_196 ) ;
V_26 = F_2 ( V_17 ) ;
if ( V_26 )
F_5 ( V_17 , V_26 ) ;
V_192 = F_2 ( V_290 ) ;
if ( V_192 ) {
if ( V_192 & V_291 )
F_164 ( V_22 ) ;
F_5 ( V_290 , V_192 ) ;
}
if ( V_196 == 0 && V_26 == 0 && V_192 == 0 )
goto V_163;
V_97 = V_214 ;
if ( V_196 )
F_120 ( V_22 , V_2 , V_196 ) ;
if ( V_26 )
F_125 ( V_2 , V_26 ) ;
F_158 ( V_22 , V_192 ) ;
}
V_163:
F_168 ( V_2 ) ;
return V_97 ;
}
static T_9 F_169 ( int V_32 , void * V_288 )
{
struct V_21 * V_22 = V_288 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_210 , V_192 ;
T_9 V_97 = V_211 ;
if ( ! F_14 ( V_2 ) )
return V_211 ;
F_167 ( V_2 ) ;
do {
V_210 = F_2 ( V_292 ) & ~ V_293 ;
V_192 = F_2 ( V_290 ) ;
if ( V_210 == 0 && V_192 == 0 )
break;
V_97 = V_214 ;
F_5 ( V_292 , 0 ) ;
if ( V_192 ) {
if ( V_192 & V_291 )
F_164 ( V_22 ) ;
F_5 ( V_290 , V_192 ) ;
}
F_123 ( V_2 , V_210 ) ;
F_158 ( V_22 , V_192 ) ;
F_5 ( V_292 , V_294 ) ;
F_6 ( V_292 ) ;
} while ( 0 );
F_168 ( V_2 ) ;
return V_97 ;
}
static void F_170 ( struct V_21 * V_22 , T_2 V_243 ,
const T_2 V_245 [ V_246 ] )
{
struct V_1 * V_2 = F_171 ( V_22 ) ;
T_2 V_244 , V_241 = 0 , V_242 = 0 ;
V_244 = F_2 ( V_295 ) ;
if ( ! V_243 ) {
T_2 V_5 = V_296 |
V_297 |
V_298 |
V_299 ;
V_244 &= ~ V_5 ;
}
F_5 ( V_295 , V_244 ) ;
if ( ! V_243 )
return;
F_132 ( & V_241 , & V_242 , V_243 ,
V_244 , V_245 ,
F_130 ) ;
F_165 ( V_22 , V_241 , V_242 ) ;
}
static void F_172 ( struct V_21 * V_22 , T_2 V_300 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_35 ;
T_2 V_243 = V_300 & V_301 ;
F_170 ( V_22 , V_243 , V_302 ) ;
if ( V_300 & V_303 ) {
int V_226 = F_105 ( ( V_300 & V_303 ) >>
V_304 ) ;
F_69 ( L_22 ,
F_173 ( V_226 ) ) ;
}
if ( V_300 & V_305 )
F_138 ( V_22 ) ;
if ( V_300 & V_306 )
F_137 ( V_22 ) ;
if ( V_300 & V_307 )
F_69 ( L_23 ) ;
if ( V_300 & V_308 )
F_69 ( L_24 ) ;
if ( V_300 & V_309 )
F_76 ( L_25 ) ;
if ( V_300 & V_310 )
F_159 (dev_priv, pipe)
F_69 ( L_26 ,
F_43 ( V_35 ) ,
F_2 ( F_174 ( V_35 ) ) ) ;
if ( V_300 & ( V_311 | V_312 ) )
F_69 ( L_27 ) ;
if ( V_300 & ( V_313 | V_314 ) )
F_69 ( L_28 ) ;
if ( V_300 & V_315 )
F_175 ( V_2 , V_316 ) ;
if ( V_300 & V_317 )
F_175 ( V_2 , V_318 ) ;
}
static void F_176 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_319 = F_2 ( V_320 ) ;
enum V_35 V_35 ;
if ( V_319 & V_321 )
F_76 ( L_29 ) ;
F_159 (dev_priv, pipe) {
if ( V_319 & F_177 ( V_35 ) )
F_163 ( V_2 , V_35 ) ;
if ( V_319 & F_178 ( V_35 ) ) {
if ( F_179 ( V_22 ) )
F_144 ( V_22 , V_35 ) ;
else
F_142 ( V_22 , V_35 ) ;
}
}
F_5 ( V_320 , V_319 ) ;
}
static void F_180 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_322 = F_2 ( V_323 ) ;
if ( V_322 & V_324 )
F_76 ( L_25 ) ;
if ( V_322 & V_325 )
F_175 ( V_2 , V_316 ) ;
if ( V_322 & V_326 )
F_175 ( V_2 , V_318 ) ;
if ( V_322 & V_327 )
F_175 ( V_2 , V_328 ) ;
F_5 ( V_323 , V_322 ) ;
}
static void F_181 ( struct V_21 * V_22 , T_2 V_300 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_35 ;
T_2 V_243 = V_300 & V_329 ;
F_170 ( V_22 , V_243 , V_330 ) ;
if ( V_300 & V_331 ) {
int V_226 = F_105 ( ( V_300 & V_331 ) >>
V_332 ) ;
F_69 ( L_30 ,
F_173 ( V_226 ) ) ;
}
if ( V_300 & V_333 )
F_138 ( V_22 ) ;
if ( V_300 & V_334 )
F_137 ( V_22 ) ;
if ( V_300 & V_335 )
F_69 ( L_31 ) ;
if ( V_300 & V_336 )
F_69 ( L_32 ) ;
if ( V_300 & V_337 )
F_159 (dev_priv, pipe)
F_69 ( L_26 ,
F_43 ( V_35 ) ,
F_2 ( F_174 ( V_35 ) ) ) ;
if ( V_300 & V_338 )
F_180 ( V_22 ) ;
}
static void F_182 ( struct V_21 * V_22 , T_2 V_300 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_243 = V_300 & V_339 &
~ V_340 ;
T_2 V_341 = V_300 & V_340 ;
T_2 V_241 = 0 , V_242 = 0 ;
if ( V_243 ) {
T_2 V_244 ;
V_244 = F_2 ( V_295 ) ;
F_5 ( V_295 , V_244 ) ;
F_132 ( & V_241 , & V_242 , V_243 ,
V_244 , V_342 ,
F_128 ) ;
}
if ( V_341 ) {
T_2 V_244 ;
V_244 = F_2 ( V_343 ) ;
F_5 ( V_343 , V_244 ) ;
F_132 ( & V_241 , & V_242 , V_341 ,
V_244 , V_342 ,
F_127 ) ;
}
if ( V_241 )
F_165 ( V_22 , V_241 , V_242 ) ;
if ( V_300 & V_334 )
F_137 ( V_22 ) ;
}
static void F_183 ( struct V_21 * V_22 , T_2 V_243 ,
const T_2 V_245 [ V_246 ] )
{
struct V_1 * V_2 = F_171 ( V_22 ) ;
T_2 V_244 , V_241 = 0 , V_242 = 0 ;
V_244 = F_2 ( V_344 ) ;
F_5 ( V_344 , V_244 ) ;
F_132 ( & V_241 , & V_242 , V_243 ,
V_244 , V_245 ,
F_129 ) ;
F_165 ( V_22 , V_241 , V_242 ) ;
}
static void F_184 ( struct V_21 * V_22 , T_2 V_345 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
enum V_35 V_35 ;
T_2 V_243 = V_345 & V_346 ;
if ( V_243 )
F_183 ( V_22 , V_243 , V_347 ) ;
if ( V_345 & V_348 )
F_138 ( V_22 ) ;
if ( V_345 & V_349 )
F_185 ( V_22 ) ;
if ( V_345 & V_350 )
F_76 ( L_29 ) ;
F_159 (dev_priv, pipe) {
if ( V_345 & F_186 ( V_35 ) &&
F_156 ( V_22 , V_35 ) )
F_160 ( V_22 , V_35 ) ;
if ( V_345 & F_187 ( V_35 ) )
F_163 ( V_2 , V_35 ) ;
if ( V_345 & F_188 ( V_35 ) )
F_149 ( V_22 , V_35 ) ;
if ( V_345 & F_189 ( V_35 ) ) {
F_161 ( V_22 , V_35 ) ;
F_190 ( V_22 , V_35 ) ;
}
}
if ( V_345 & V_351 ) {
T_2 V_300 = F_2 ( V_352 ) ;
if ( F_191 ( V_22 ) )
F_181 ( V_22 , V_300 ) ;
else
F_172 ( V_22 , V_300 ) ;
F_5 ( V_352 , V_300 ) ;
}
if ( F_192 ( V_22 ) && V_345 & V_353 )
F_80 ( V_22 ) ;
}
static void F_193 ( struct V_21 * V_22 , T_2 V_345 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
enum V_35 V_35 ;
T_2 V_243 = V_345 & V_354 ;
if ( V_243 )
F_183 ( V_22 , V_243 , V_355 ) ;
if ( V_345 & V_356 )
F_176 ( V_22 ) ;
if ( V_345 & V_357 )
F_138 ( V_22 ) ;
if ( V_345 & V_358 )
F_185 ( V_22 ) ;
F_159 (dev_priv, pipe) {
if ( V_345 & ( F_194 ( V_35 ) ) &&
F_156 ( V_22 , V_35 ) )
F_160 ( V_22 , V_35 ) ;
if ( V_345 & F_195 ( V_35 ) ) {
F_161 ( V_22 , V_35 ) ;
F_190 ( V_22 , V_35 ) ;
}
}
if ( ! F_196 ( V_22 ) && ( V_345 & V_359 ) ) {
T_2 V_300 = F_2 ( V_352 ) ;
F_181 ( V_22 , V_300 ) ;
F_5 ( V_352 , V_300 ) ;
}
}
static T_9 F_197 ( int V_32 , void * V_288 )
{
struct V_21 * V_22 = V_288 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_345 , V_196 , V_360 , V_361 = 0 ;
T_9 V_97 = V_211 ;
if ( ! F_14 ( V_2 ) )
return V_211 ;
F_167 ( V_2 ) ;
V_360 = F_2 ( V_362 ) ;
F_5 ( V_362 , V_360 & ~ V_294 ) ;
F_6 ( V_362 ) ;
if ( ! F_196 ( V_22 ) ) {
V_361 = F_2 ( V_363 ) ;
F_5 ( V_363 , 0 ) ;
F_6 ( V_363 ) ;
}
V_196 = F_2 ( V_289 ) ;
if ( V_196 ) {
F_5 ( V_289 , V_196 ) ;
V_97 = V_214 ;
if ( F_19 ( V_22 ) -> V_16 >= 6 )
F_120 ( V_22 , V_2 , V_196 ) ;
else
F_119 ( V_22 , V_2 , V_196 ) ;
}
V_345 = F_2 ( V_364 ) ;
if ( V_345 ) {
F_5 ( V_364 , V_345 ) ;
V_97 = V_214 ;
if ( F_19 ( V_22 ) -> V_16 >= 7 )
F_193 ( V_22 , V_345 ) ;
else
F_184 ( V_22 , V_345 ) ;
}
if ( F_19 ( V_22 ) -> V_16 >= 6 ) {
T_2 V_26 = F_2 ( V_17 ) ;
if ( V_26 ) {
F_5 ( V_17 , V_26 ) ;
V_97 = V_214 ;
F_125 ( V_2 , V_26 ) ;
}
}
F_5 ( V_362 , V_360 ) ;
F_6 ( V_362 ) ;
if ( ! F_196 ( V_22 ) ) {
F_5 ( V_363 , V_361 ) ;
F_6 ( V_363 ) ;
}
F_168 ( V_2 ) ;
return V_97 ;
}
static void F_198 ( struct V_21 * V_22 , T_2 V_243 ,
const T_2 V_245 [ V_246 ] )
{
struct V_1 * V_2 = F_171 ( V_22 ) ;
T_2 V_244 , V_241 = 0 , V_242 = 0 ;
V_244 = F_2 ( V_295 ) ;
F_5 ( V_295 , V_244 ) ;
F_132 ( & V_241 , & V_242 , V_243 ,
V_244 , V_245 ,
F_126 ) ;
F_165 ( V_22 , V_241 , V_242 ) ;
}
static T_9
F_199 ( struct V_1 * V_2 , T_2 V_210 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_9 V_97 = V_211 ;
T_2 V_192 ;
enum V_35 V_35 ;
if ( V_210 & V_365 ) {
V_192 = F_2 ( V_366 ) ;
if ( V_192 ) {
F_5 ( V_366 , V_192 ) ;
V_97 = V_214 ;
if ( V_192 & V_367 )
F_185 ( V_22 ) ;
else
F_76 ( L_33 ) ;
}
else
F_76 ( L_34 ) ;
}
if ( V_210 & V_368 ) {
V_192 = F_2 ( V_369 ) ;
if ( V_192 ) {
T_2 V_370 ;
bool V_371 = false ;
F_5 ( V_369 , V_192 ) ;
V_97 = V_214 ;
V_370 = V_372 ;
if ( F_19 ( V_2 ) -> V_16 >= 9 )
V_370 |= V_373 |
V_374 |
V_375 ;
if ( V_192 & V_370 ) {
F_138 ( V_22 ) ;
V_371 = true ;
}
if ( F_200 ( V_2 ) ) {
V_370 = V_192 & V_376 ;
if ( V_370 ) {
F_198 ( V_22 , V_370 , V_377 ) ;
V_371 = true ;
}
} else if ( F_201 ( V_2 ) ) {
V_370 = V_192 & V_378 ;
if ( V_370 ) {
F_183 ( V_22 , V_370 , V_379 ) ;
V_371 = true ;
}
}
if ( F_200 ( V_22 ) && ( V_192 & V_380 ) ) {
F_137 ( V_22 ) ;
V_371 = true ;
}
if ( ! V_371 )
F_76 ( L_35 ) ;
}
else
F_76 ( L_36 ) ;
}
F_159 (dev_priv, pipe) {
T_2 V_381 , V_382 ;
if ( ! ( V_210 & F_202 ( V_35 ) ) )
continue;
V_192 = F_2 ( F_203 ( V_35 ) ) ;
if ( ! V_192 ) {
F_76 ( L_37 ) ;
continue;
}
V_97 = V_214 ;
F_5 ( F_203 ( V_35 ) , V_192 ) ;
if ( V_192 & V_383 &&
F_156 ( V_22 , V_35 ) )
F_160 ( V_22 , V_35 ) ;
V_381 = V_192 ;
if ( F_19 ( V_2 ) -> V_16 >= 9 )
V_381 &= V_384 ;
else
V_381 &= V_385 ;
if ( V_381 ) {
F_161 ( V_22 , V_35 ) ;
F_190 ( V_22 , V_35 ) ;
}
if ( V_192 & V_386 )
F_142 ( V_22 , V_35 ) ;
if ( V_192 & V_387 )
F_163 ( V_2 , V_35 ) ;
V_382 = V_192 ;
if ( F_19 ( V_2 ) -> V_16 >= 9 )
V_382 &= V_388 ;
else
V_382 &= V_389 ;
if ( V_382 )
F_76 ( L_38 ,
F_43 ( V_35 ) ,
V_382 ) ;
}
if ( F_204 ( V_22 ) && ! F_196 ( V_22 ) &&
V_210 & V_390 ) {
V_192 = F_2 ( V_352 ) ;
if ( V_192 ) {
F_5 ( V_352 , V_192 ) ;
V_97 = V_214 ;
if ( F_205 ( V_2 ) )
F_182 ( V_22 , V_192 ) ;
else
F_181 ( V_22 , V_192 ) ;
} else {
F_69 ( L_39 ) ;
}
}
return V_97 ;
}
static T_9 F_206 ( int V_32 , void * V_288 )
{
struct V_21 * V_22 = V_288 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_210 ;
T_9 V_97 ;
if ( ! F_14 ( V_2 ) )
return V_211 ;
V_210 = F_63 ( V_292 ) ;
V_210 &= ~ V_293 ;
if ( ! V_210 )
return V_211 ;
F_124 ( V_292 , 0 ) ;
F_167 ( V_2 ) ;
V_97 = F_123 ( V_2 , V_210 ) ;
V_97 |= F_199 ( V_2 , V_210 ) ;
F_124 ( V_292 , V_293 ) ;
F_207 ( V_292 ) ;
F_168 ( V_2 ) ;
return V_97 ;
}
static void F_208 ( struct V_1 * V_2 ,
bool V_391 )
{
struct V_129 * V_130 ;
int V_87 ;
F_95 (ring, dev_priv, i)
F_88 ( & V_130 -> V_131 ) ;
F_88 ( & V_2 -> V_392 ) ;
if ( V_391 )
F_88 ( & V_2 -> V_393 . V_394 ) ;
}
static void F_209 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_171 ( V_22 ) ;
struct V_395 * error = & V_2 -> V_393 ;
char * V_396 [] = { V_397 L_7 , NULL } ;
char * V_398 [] = { V_399 L_7 , NULL } ;
char * V_400 [] = { V_397 L_40 , NULL } ;
int V_97 ;
F_112 ( & V_22 -> V_188 -> V_189 -> V_190 , V_191 , V_396 ) ;
if ( F_210 ( error ) && ! F_211 ( error ) ) {
F_69 ( L_41 ) ;
F_112 ( & V_22 -> V_188 -> V_189 -> V_190 , V_191 ,
V_398 ) ;
F_212 ( V_2 ) ;
F_213 ( V_22 ) ;
V_97 = F_214 ( V_22 ) ;
F_215 ( V_22 ) ;
F_216 ( V_2 ) ;
if ( V_97 == 0 ) {
F_217 () ;
F_218 ( & V_2 -> V_393 . V_401 ) ;
F_112 ( & V_22 -> V_188 -> V_189 -> V_190 ,
V_191 , V_400 ) ;
} else {
F_219 ( V_402 , & error -> V_401 ) ;
}
F_208 ( V_2 , true ) ;
}
}
static void F_220 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_3 V_403 [ V_404 ] ;
T_2 V_405 = F_2 ( V_406 ) ;
int V_35 , V_87 ;
if ( ! V_405 )
return;
F_221 ( L_42 , V_405 ) ;
F_222 ( V_22 , V_403 ) ;
if ( F_72 ( V_22 ) ) {
if ( V_405 & ( V_407 | V_408 ) ) {
T_2 V_409 = F_2 ( V_410 ) ;
F_221 ( L_43 , F_2 ( V_410 ) ) ;
F_221 ( L_44 , F_2 ( V_411 ) ) ;
for ( V_87 = 0 ; V_87 < F_223 ( V_403 ) ; V_87 ++ )
F_221 ( L_45 , V_87 , V_403 [ V_87 ] ) ;
F_221 ( L_46 , F_2 ( V_412 ) ) ;
F_221 ( L_47 , F_2 ( V_413 ) ) ;
F_5 ( V_410 , V_409 ) ;
F_6 ( V_410 ) ;
}
if ( V_405 & V_414 ) {
T_2 V_415 = F_2 ( V_416 ) ;
F_221 ( L_48 ) ;
F_221 ( L_49 , V_415 ) ;
F_5 ( V_416 , V_415 ) ;
F_6 ( V_416 ) ;
}
}
if ( ! F_62 ( V_22 ) ) {
if ( V_405 & V_417 ) {
T_2 V_415 = F_2 ( V_416 ) ;
F_221 ( L_48 ) ;
F_221 ( L_49 , V_415 ) ;
F_5 ( V_416 , V_415 ) ;
F_6 ( V_416 ) ;
}
}
if ( V_405 & V_418 ) {
F_221 ( L_50 ) ;
F_159 (dev_priv, pipe)
F_221 ( L_51 ,
F_43 ( V_35 ) , F_2 ( F_41 ( V_35 ) ) ) ;
}
if ( V_405 & V_419 ) {
F_221 ( L_52 ) ;
F_221 ( L_53 , F_2 ( V_420 ) ) ;
for ( V_87 = 0 ; V_87 < F_223 ( V_403 ) ; V_87 ++ )
F_221 ( L_45 , V_87 , V_403 [ V_87 ] ) ;
if ( F_19 ( V_22 ) -> V_16 < 4 ) {
T_2 V_409 = F_2 ( V_421 ) ;
F_221 ( L_43 , F_2 ( V_421 ) ) ;
F_221 ( L_44 , F_2 ( V_422 ) ) ;
F_221 ( L_47 , F_2 ( V_423 ) ) ;
F_5 ( V_421 , V_409 ) ;
F_6 ( V_421 ) ;
} else {
T_2 V_409 = F_2 ( V_410 ) ;
F_221 ( L_43 , F_2 ( V_410 ) ) ;
F_221 ( L_44 , F_2 ( V_411 ) ) ;
F_221 ( L_46 , F_2 ( V_412 ) ) ;
F_221 ( L_47 , F_2 ( V_413 ) ) ;
F_5 ( V_410 , V_409 ) ;
F_6 ( V_410 ) ;
}
}
F_5 ( V_406 , V_405 ) ;
F_6 ( V_406 ) ;
V_405 = F_2 ( V_406 ) ;
if ( V_405 ) {
F_76 ( L_54 , V_405 ) ;
F_5 ( V_424 , F_2 ( V_424 ) | V_405 ) ;
F_5 ( V_425 , V_426 ) ;
}
}
void F_224 ( struct V_21 * V_22 , bool V_427 ,
const char * V_428 , ... )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_10 args ;
char V_429 [ 80 ] ;
va_start ( args , V_428 ) ;
F_225 ( V_429 , sizeof( V_429 ) , V_428 , args ) ;
va_end ( args ) ;
F_226 ( V_22 , V_427 , V_429 ) ;
F_220 ( V_22 ) ;
if ( V_427 ) {
F_219 ( V_430 ,
& V_2 -> V_393 . V_401 ) ;
F_208 ( V_2 , false ) ;
}
F_209 ( V_22 ) ;
}
static int F_227 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_98 ;
F_70 ( & V_2 -> V_7 , V_98 ) ;
if ( F_19 ( V_22 ) -> V_16 >= 4 )
F_47 ( V_2 , V_35 ,
V_277 ) ;
else
F_47 ( V_2 , V_35 ,
V_431 ) ;
F_73 ( & V_2 -> V_7 , V_98 ) ;
return 0 ;
}
static int F_228 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_98 ;
T_3 V_432 = ( F_19 ( V_22 ) -> V_16 >= 7 ) ? F_194 ( V_35 ) :
F_186 ( V_35 ) ;
F_70 ( & V_2 -> V_7 , V_98 ) ;
F_229 ( V_2 , V_432 ) ;
F_73 ( & V_2 -> V_7 , V_98 ) ;
return 0 ;
}
static int F_230 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_98 ;
F_70 ( & V_2 -> V_7 , V_98 ) ;
F_47 ( V_2 , V_35 ,
V_277 ) ;
F_73 ( & V_2 -> V_7 , V_98 ) ;
return 0 ;
}
static int F_231 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_98 ;
F_70 ( & V_2 -> V_7 , V_98 ) ;
F_232 ( V_2 , V_35 , V_383 ) ;
F_73 ( & V_2 -> V_7 , V_98 ) ;
return 0 ;
}
static void F_233 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_98 ;
F_70 ( & V_2 -> V_7 , V_98 ) ;
F_50 ( V_2 , V_35 ,
V_431 |
V_277 ) ;
F_73 ( & V_2 -> V_7 , V_98 ) ;
}
static void F_234 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_98 ;
T_3 V_432 = ( F_19 ( V_22 ) -> V_16 >= 7 ) ? F_194 ( V_35 ) :
F_186 ( V_35 ) ;
F_70 ( & V_2 -> V_7 , V_98 ) ;
F_235 ( V_2 , V_432 ) ;
F_73 ( & V_2 -> V_7 , V_98 ) ;
}
static void F_236 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_98 ;
F_70 ( & V_2 -> V_7 , V_98 ) ;
F_50 ( V_2 , V_35 ,
V_277 ) ;
F_73 ( & V_2 -> V_7 , V_98 ) ;
}
static void F_237 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_98 ;
F_70 ( & V_2 -> V_7 , V_98 ) ;
F_238 ( V_2 , V_35 , V_383 ) ;
F_73 ( & V_2 -> V_7 , V_98 ) ;
}
static bool
F_239 ( struct V_129 * V_130 , T_2 V_433 )
{
return ( F_240 ( & V_130 -> V_434 ) ||
F_241 ( V_433 , V_130 -> V_435 ) ) ;
}
static bool
F_242 ( struct V_21 * V_22 , T_2 V_436 )
{
if ( F_19 ( V_22 ) -> V_16 >= 8 ) {
return ( V_436 >> 23 ) == 0x1c ;
} else {
V_436 &= ~ V_437 ;
return V_436 == ( V_438 | V_439 |
V_440 ) ;
}
}
static struct V_129 *
F_243 ( struct V_129 * V_130 , T_2 V_436 , T_6 V_441 )
{
struct V_1 * V_2 = V_130 -> V_22 -> V_23 ;
struct V_129 * V_442 ;
int V_87 ;
if ( F_19 ( V_2 -> V_22 ) -> V_16 >= 8 ) {
F_95 (signaller, dev_priv, i) {
if ( V_130 == V_442 )
continue;
if ( V_441 == V_442 -> V_443 . V_444 [ V_130 -> V_445 ] )
return V_442 ;
}
} else {
T_2 V_446 = V_436 & V_437 ;
F_95 (signaller, dev_priv, i) {
if( V_130 == V_442 )
continue;
if ( V_446 == V_442 -> V_443 . V_447 . V_448 [ V_130 -> V_445 ] )
return V_442 ;
}
}
F_76 ( L_55 ,
V_130 -> V_445 , V_436 , V_441 ) ;
return NULL ;
}
static struct V_129 *
F_244 ( struct V_129 * V_130 , T_2 * V_433 )
{
struct V_1 * V_2 = V_130 -> V_22 -> V_23 ;
T_2 V_449 , V_436 , V_257 ;
T_6 V_441 = 0 ;
int V_87 , V_450 ;
if ( V_130 -> V_451 == NULL )
return NULL ;
V_436 = F_2 ( F_245 ( V_130 -> V_452 ) ) ;
if ( ! F_242 ( V_130 -> V_22 , V_436 ) )
return NULL ;
V_257 = F_246 ( V_130 ) & V_453 ;
V_450 = ( F_19 ( V_130 -> V_22 ) -> V_16 >= 8 ) ? 5 : 4 ;
for ( V_87 = V_450 ; V_87 ; -- V_87 ) {
V_257 &= V_130 -> V_451 -> V_454 - 1 ;
V_449 = F_247 ( V_130 -> V_451 -> V_455 + V_257 ) ;
if ( V_449 == V_436 )
break;
V_257 -= 4 ;
}
if ( ! V_87 )
return NULL ;
* V_433 = F_247 ( V_130 -> V_451 -> V_455 + V_257 + 4 ) + 1 ;
if ( F_19 ( V_130 -> V_22 ) -> V_16 >= 8 ) {
V_441 = F_247 ( V_130 -> V_451 -> V_455 + V_257 + 12 ) ;
V_441 <<= 32 ;
V_441 = F_247 ( V_130 -> V_451 -> V_455 + V_257 + 8 ) ;
}
return F_243 ( V_130 , V_436 , V_441 ) ;
}
static int F_248 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = V_130 -> V_22 -> V_23 ;
struct V_129 * V_442 ;
T_2 V_433 ;
V_130 -> V_456 . V_457 ++ ;
V_442 = F_244 ( V_130 , & V_433 ) ;
if ( V_442 == NULL )
return - 1 ;
if ( V_442 -> V_456 . V_457 >= V_458 )
return - 1 ;
if ( F_241 ( V_442 -> V_459 ( V_442 , false ) , V_433 ) )
return 1 ;
if ( F_249 ( V_442 ) & V_460 &&
F_248 ( V_442 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_129 * V_130 ;
int V_87 ;
F_95 (ring, dev_priv, i)
V_130 -> V_456 . V_457 = 0 ;
}
static bool F_251 ( struct V_129 * V_130 )
{
T_2 V_403 [ V_404 ] ;
bool V_461 ;
int V_87 ;
if ( V_130 -> V_445 != V_199 )
return true ;
F_222 ( V_130 -> V_22 , V_403 ) ;
V_461 = true ;
for ( V_87 = 0 ; V_87 < V_404 ; V_87 ++ ) {
const T_2 V_462 = V_403 [ V_87 ] | V_130 -> V_456 . V_403 [ V_87 ] ;
if ( V_462 != V_130 -> V_456 . V_403 [ V_87 ] )
V_461 = false ;
V_130 -> V_456 . V_403 [ V_87 ] |= V_462 ;
}
return V_461 ;
}
static enum V_463
F_252 ( struct V_129 * V_130 , T_6 V_464 )
{
if ( V_464 != V_130 -> V_456 . V_464 ) {
memset ( V_130 -> V_456 . V_403 , 0 ,
sizeof( V_130 -> V_456 . V_403 ) ) ;
if ( V_464 > V_130 -> V_456 . V_465 ) {
V_130 -> V_456 . V_465 = V_464 ;
return V_466 ;
}
return V_467 ;
}
if ( ! F_251 ( V_130 ) )
return V_466 ;
return V_468 ;
}
static enum V_463
F_253 ( struct V_129 * V_130 , T_6 V_464 )
{
struct V_21 * V_22 = V_130 -> V_22 ;
struct V_1 * V_2 = V_22 -> V_23 ;
enum V_463 V_469 ;
T_2 V_462 ;
V_469 = F_252 ( V_130 , V_464 ) ;
if ( V_469 != V_468 )
return V_469 ;
if ( F_62 ( V_22 ) )
return V_468 ;
V_462 = F_249 ( V_130 ) ;
if ( V_462 & V_470 ) {
F_224 ( V_22 , false ,
L_56 ,
V_130 -> V_471 ) ;
F_254 ( V_130 , V_462 ) ;
return V_472 ;
}
if ( F_19 ( V_22 ) -> V_16 >= 6 && V_462 & V_460 ) {
switch ( F_248 ( V_130 ) ) {
default:
return V_468 ;
case 1 :
F_224 ( V_22 , false ,
L_57 ,
V_130 -> V_471 ) ;
F_254 ( V_130 , V_462 ) ;
return V_472 ;
case 0 :
return V_473 ;
}
}
return V_468 ;
}
static void F_255 ( struct V_158 * V_30 )
{
struct V_1 * V_2 =
F_97 ( V_30 , F_256 ( * V_2 ) ,
V_393 . V_474 . V_30 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_129 * V_130 ;
int V_87 ;
int V_475 = 0 , V_476 = 0 ;
bool V_461 [ V_458 ] = { 0 } ;
#define F_257 1
#define F_258 5
#define F_259 20
if ( ! V_477 . V_478 )
return;
F_98 ( V_2 ) ;
F_260 ( V_2 ) ;
F_95 (ring, dev_priv, i) {
T_6 V_464 ;
T_2 V_433 ;
bool V_479 = true ;
F_250 ( V_2 ) ;
V_433 = V_130 -> V_459 ( V_130 , false ) ;
V_464 = F_261 ( V_130 ) ;
if ( V_130 -> V_456 . V_433 == V_433 ) {
if ( F_239 ( V_130 , V_433 ) ) {
V_130 -> V_456 . V_480 = V_481 ;
if ( F_262 ( & V_130 -> V_131 ) ) {
if ( ! F_263 ( V_130 -> V_445 , & V_2 -> V_393 . V_482 ) ) {
if ( ! ( V_2 -> V_393 . V_483 & F_264 ( V_130 ) ) )
F_76 ( L_58 ,
V_130 -> V_471 ) ;
else
F_265 ( L_59 ,
V_130 -> V_471 ) ;
F_88 ( & V_130 -> V_131 ) ;
}
V_130 -> V_456 . V_484 += F_257 ;
} else
V_479 = false ;
} else {
V_130 -> V_456 . V_480 = F_253 ( V_130 ,
V_464 ) ;
switch ( V_130 -> V_456 . V_480 ) {
case V_481 :
case V_473 :
case V_466 :
break;
case V_467 :
V_130 -> V_456 . V_484 += F_257 ;
break;
case V_472 :
V_130 -> V_456 . V_484 += F_258 ;
break;
case V_468 :
V_130 -> V_456 . V_484 += F_259 ;
V_461 [ V_87 ] = true ;
break;
}
}
} else {
V_130 -> V_456 . V_480 = V_466 ;
if ( V_130 -> V_456 . V_484 > 0 )
V_130 -> V_456 . V_484 -- ;
V_130 -> V_456 . V_464 = V_130 -> V_456 . V_465 = 0 ;
memset ( V_130 -> V_456 . V_403 , 0 ,
sizeof( V_130 -> V_456 . V_403 ) ) ;
}
V_130 -> V_456 . V_433 = V_433 ;
V_130 -> V_456 . V_464 = V_464 ;
V_475 += V_479 ;
}
F_95 (ring, dev_priv, i) {
if ( V_130 -> V_456 . V_484 >= V_485 ) {
F_265 ( L_60 ,
V_461 [ V_87 ] ? L_61 : L_62 ,
V_130 -> V_471 ) ;
V_476 ++ ;
}
}
if ( V_476 ) {
F_224 ( V_22 , true , L_63 ) ;
goto V_163;
}
if ( V_475 )
F_266 ( V_22 ) ;
V_163:
F_103 ( V_2 ) ;
}
void F_266 ( struct V_21 * V_22 )
{
struct V_395 * V_486 = & F_171 ( V_22 ) -> V_393 ;
if ( ! V_477 . V_478 )
return;
F_267 ( V_486 -> V_487 , & V_486 -> V_474 ,
F_268 ( V_488 ) ) ;
}
static void F_269 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( F_196 ( V_22 ) )
return;
F_270 ( V_489 ) ;
if ( F_191 ( V_22 ) || F_271 ( V_22 ) )
F_5 ( V_323 , 0xffffffff ) ;
}
static void F_272 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( F_196 ( V_22 ) )
return;
F_9 ( F_2 ( V_363 ) != 0 ) ;
F_5 ( V_363 , 0xffffffff ) ;
F_6 ( V_363 ) ;
}
static void F_273 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_270 ( V_490 ) ;
if ( F_19 ( V_22 ) -> V_16 >= 6 )
F_270 ( V_491 ) ;
}
static void F_274 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_5 ( V_492 , 0xffffffff ) ;
F_270 ( V_493 ) ;
if ( F_275 ( V_22 ) )
F_5 ( V_320 , 0xffffffff ) ;
F_273 ( V_22 ) ;
F_269 ( V_22 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
enum V_35 V_35 ;
F_10 ( V_2 , 0xFFFFFFFF , 0 ) ;
F_5 ( V_282 , F_2 ( V_282 ) ) ;
F_159 (dev_priv, pipe)
F_5 ( F_41 ( V_35 ) , 0xffff ) ;
F_270 ( V_494 ) ;
}
static void F_277 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_5 ( V_495 , 0 ) ;
F_5 ( F_278 ( V_496 ) , 0 ) ;
F_5 ( F_278 ( V_497 ) , 0 ) ;
F_5 ( F_278 ( V_498 ) , 0 ) ;
F_273 ( V_22 ) ;
F_5 ( V_499 , V_500 ) ;
F_276 ( V_2 ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
F_280 ( V_490 , 0 ) ;
F_280 ( V_490 , 1 ) ;
F_280 ( V_490 , 2 ) ;
F_280 ( V_490 , 3 ) ;
}
static void F_281 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_35 ;
F_5 ( V_292 , 0 ) ;
F_6 ( V_292 ) ;
F_279 ( V_2 ) ;
F_159 (dev_priv, pipe)
if ( F_282 ( V_2 ,
F_283 ( V_35 ) ) )
F_280 ( V_501 , V_35 ) ;
F_270 ( V_502 ) ;
F_270 ( V_503 ) ;
F_270 ( V_504 ) ;
if ( F_204 ( V_22 ) )
F_269 ( V_22 ) ;
}
void F_284 ( struct V_1 * V_2 ,
unsigned int V_505 )
{
T_3 V_506 = V_383 | V_387 ;
enum V_35 V_35 ;
F_11 ( & V_2 -> V_7 ) ;
F_285 (dev_priv, pipe, pipe_mask)
F_286 ( V_501 , V_35 ,
V_2 -> V_36 [ V_35 ] ,
~ V_2 -> V_36 [ V_35 ] | V_506 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_287 ( struct V_1 * V_2 ,
unsigned int V_505 )
{
enum V_35 V_35 ;
F_11 ( & V_2 -> V_7 ) ;
F_285 (dev_priv, pipe, pipe_mask)
F_280 ( V_501 , V_35 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_35 ( V_2 -> V_22 -> V_32 ) ;
}
static void F_288 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_5 ( V_292 , 0 ) ;
F_6 ( V_292 ) ;
F_279 ( V_2 ) ;
F_270 ( V_504 ) ;
F_5 ( V_499 , V_507 ) ;
F_276 ( V_2 ) ;
}
static T_2 F_289 ( struct V_21 * V_22 ,
const T_2 V_245 [ V_246 ] )
{
struct V_1 * V_2 = F_171 ( V_22 ) ;
struct V_508 * V_509 ;
T_2 V_510 = 0 ;
F_290 (dev, encoder)
if ( V_2 -> V_511 . V_512 [ V_509 -> V_513 ] . V_514 == V_515 )
V_510 |= V_245 [ V_509 -> V_513 ] ;
return V_510 ;
}
static void F_291 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_516 , V_511 , V_510 ;
if ( F_292 ( V_22 ) ) {
V_516 = V_301 ;
V_510 = F_289 ( V_22 , V_302 ) ;
} else {
V_516 = V_329 ;
V_510 = F_289 ( V_22 , V_330 ) ;
}
F_39 ( V_2 , V_516 , V_510 ) ;
V_511 = F_2 ( V_295 ) ;
V_511 &= ~ ( V_517 | V_518 | V_519 ) ;
V_511 |= V_520 | V_521 ;
V_511 |= V_522 | V_523 ;
V_511 |= V_524 | V_525 ;
if ( F_293 ( V_22 ) )
V_511 |= V_526 ;
F_5 ( V_295 , V_511 ) ;
}
static void F_294 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_516 , V_511 , V_510 ;
V_516 = V_339 ;
V_510 = F_289 ( V_22 , V_342 ) ;
F_39 ( V_2 , V_516 , V_510 ) ;
V_511 = F_2 ( V_295 ) ;
V_511 |= V_520 | V_522 |
V_524 | V_526 ;
F_5 ( V_295 , V_511 ) ;
V_511 = F_2 ( V_343 ) ;
V_511 |= V_527 ;
F_5 ( V_343 , V_511 ) ;
}
static void F_295 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_516 , V_511 , V_510 ;
if ( F_19 ( V_22 ) -> V_16 >= 8 ) {
V_516 = V_378 ;
V_510 = F_289 ( V_22 , V_379 ) ;
F_36 ( V_2 , V_516 , V_510 ) ;
} else if ( F_19 ( V_22 ) -> V_16 >= 7 ) {
V_516 = V_354 ;
V_510 = F_289 ( V_22 , V_355 ) ;
F_13 ( V_2 , V_516 , V_510 ) ;
} else {
V_516 = V_346 ;
V_510 = F_289 ( V_22 , V_347 ) ;
F_13 ( V_2 , V_516 , V_510 ) ;
}
V_511 = F_2 ( V_344 ) ;
V_511 &= ~ V_528 ;
V_511 |= V_529 | V_530 ;
F_5 ( V_344 , V_511 ) ;
F_291 ( V_22 ) ;
}
static void F_296 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_516 , V_511 , V_510 ;
V_510 = F_289 ( V_22 , V_377 ) ;
V_516 = V_376 ;
F_36 ( V_2 , V_516 , V_510 ) ;
V_511 = F_2 ( V_295 ) ;
V_511 |= V_522 | V_524 |
V_526 ;
F_5 ( V_295 , V_511 ) ;
}
static void F_297 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_5 ;
if ( F_196 ( V_22 ) )
return;
if ( F_292 ( V_22 ) )
V_5 = V_306 | V_305 | V_309 ;
else
V_5 = V_334 | V_333 ;
F_1 ( V_2 , V_352 ) ;
F_5 ( V_38 , ~ V_5 ) ;
}
static void F_298 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_531 , V_532 ;
V_531 = V_532 = 0 ;
V_2 -> V_14 = ~ 0 ;
if ( F_117 ( V_22 ) ) {
V_2 -> V_14 = ~ F_115 ( V_22 ) ;
V_532 |= F_115 ( V_22 ) ;
}
V_532 |= V_197 ;
if ( F_192 ( V_22 ) ) {
V_532 |= V_198 |
V_200 ;
} else {
V_532 |= V_203 | V_202 ;
}
F_299 ( V_490 , V_2 -> V_14 , V_532 ) ;
if ( F_19 ( V_22 ) -> V_16 >= 6 ) {
if ( F_155 ( V_22 ) )
V_531 |= V_267 ;
V_2 -> V_20 = 0xffffffff ;
F_299 ( V_491 , V_2 -> V_20 , V_531 ) ;
}
}
static int F_300 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_533 , V_534 ;
if ( F_19 ( V_22 ) -> V_16 >= 7 ) {
V_533 = ( V_294 | V_358 |
V_359 | V_535 |
V_536 |
V_537 | V_357 ) ;
V_534 = ( V_538 | V_539 |
V_540 | V_356 |
V_354 ) ;
} else {
V_533 = ( V_294 | V_349 | V_351 |
V_541 | V_542 |
V_348 |
V_543 | V_544 |
V_350 ) ;
V_534 = ( V_545 | V_546 | V_353 |
V_547 | V_548 |
V_346 ) ;
}
V_2 -> V_12 = ~ V_533 ;
F_5 ( V_492 , 0xeffe ) ;
F_272 ( V_22 ) ;
F_299 ( V_493 , V_2 -> V_12 , V_533 | V_534 ) ;
F_298 ( V_22 ) ;
F_297 ( V_22 ) ;
if ( F_301 ( V_22 ) ) {
F_11 ( & V_2 -> V_7 ) ;
F_229 ( V_2 , V_353 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
return 0 ;
}
static void F_302 ( struct V_1 * V_2 )
{
T_2 V_549 ;
T_2 V_550 ;
enum V_35 V_35 ;
V_549 = V_43 |
V_47 ;
F_159 (dev_priv, pipe)
F_5 ( F_41 ( V_35 ) , V_549 ) ;
F_6 ( F_41 ( V_56 ) ) ;
V_549 = V_278 |
V_279 ;
F_47 ( V_2 , V_56 , V_280 ) ;
F_159 (dev_priv, pipe)
F_47 ( V_2 , V_35 , V_549 ) ;
V_550 = V_291 |
V_273 |
V_274 ;
if ( F_49 ( V_2 ) )
V_550 |= V_276 ;
V_2 -> V_12 &= ~ V_550 ;
F_5 ( V_290 , V_550 ) ;
F_5 ( V_290 , V_550 ) ;
F_5 ( V_551 , ~ V_2 -> V_12 ) ;
F_5 ( V_495 , V_2 -> V_12 ) ;
F_6 ( V_495 ) ;
}
static void F_303 ( struct V_1 * V_2 )
{
T_2 V_549 ;
T_2 V_550 ;
enum V_35 V_35 ;
V_550 = V_291 |
V_273 |
V_274 ;
if ( F_49 ( V_2 ) )
V_550 |= V_276 ;
V_2 -> V_12 |= V_550 ;
F_5 ( V_495 , V_2 -> V_12 ) ;
F_5 ( V_551 , ~ V_2 -> V_12 ) ;
F_5 ( V_290 , V_550 ) ;
F_5 ( V_290 , V_550 ) ;
F_6 ( V_290 ) ;
V_549 = V_278 |
V_279 ;
F_50 ( V_2 , V_56 , V_280 ) ;
F_159 (dev_priv, pipe)
F_50 ( V_2 , V_35 , V_549 ) ;
V_549 = V_43 |
V_47 ;
F_159 (dev_priv, pipe)
F_5 ( F_41 ( V_35 ) , V_549 ) ;
F_6 ( F_41 ( V_56 ) ) ;
}
void F_304 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_271 )
return;
V_2 -> V_271 = true ;
if ( F_14 ( V_2 ) )
F_302 ( V_2 ) ;
}
void F_305 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_271 )
return;
V_2 -> V_271 = false ;
if ( F_14 ( V_2 ) )
F_303 ( V_2 ) ;
}
static void F_306 ( struct V_1 * V_2 )
{
V_2 -> V_12 = ~ 0 ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
F_5 ( V_290 , 0xffffffff ) ;
F_5 ( V_290 , 0xffffffff ) ;
F_5 ( V_551 , ~ V_2 -> V_12 ) ;
F_5 ( V_495 , V_2 -> V_12 ) ;
F_6 ( V_495 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_271 )
F_302 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static int F_307 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_306 ( V_2 ) ;
F_298 ( V_22 ) ;
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
F_5 ( V_552 , V_553 ) ;
return 0 ;
}
static void F_308 ( struct V_1 * V_2 )
{
T_3 V_554 [] = {
V_197 << V_215 |
V_209 << V_215 |
V_194 |
V_197 << V_216 |
V_209 << V_216 ,
V_197 << V_219 |
V_209 << V_219 |
V_197 << V_221 |
V_209 << V_221 ,
0 ,
V_197 << V_224 |
V_209 << V_224
} ;
V_2 -> V_20 = 0xffffffff ;
F_286 ( V_490 , 0 , ~ V_554 [ 0 ] , V_554 [ 0 ] ) ;
F_286 ( V_490 , 1 , ~ V_554 [ 1 ] , V_554 [ 1 ] ) ;
F_286 ( V_490 , 2 , V_2 -> V_20 , 0 ) ;
F_286 ( V_490 , 3 , ~ V_554 [ 3 ] , V_554 [ 3 ] ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
T_3 V_555 = V_386 ;
T_3 V_556 ;
T_2 V_557 = V_372 ;
T_2 V_558 ;
enum V_35 V_35 ;
if ( F_19 ( V_2 ) -> V_16 >= 9 ) {
V_555 |= V_384 |
V_388 ;
V_557 |= V_373 | V_374 |
V_375 ;
if ( F_200 ( V_2 ) )
V_557 |= V_380 ;
} else {
V_555 |= V_385 |
V_389 ;
}
V_556 = V_555 | V_383 |
V_387 ;
V_558 = V_557 ;
if ( F_200 ( V_2 ) )
V_558 |= V_376 ;
else if ( F_201 ( V_2 ) )
V_558 |= V_378 ;
V_2 -> V_36 [ V_56 ] = ~ V_555 ;
V_2 -> V_36 [ V_54 ] = ~ V_555 ;
V_2 -> V_36 [ V_275 ] = ~ V_555 ;
F_159 (dev_priv, pipe)
if ( F_282 ( V_2 ,
F_283 ( V_35 ) ) )
F_286 ( V_501 , V_35 ,
V_2 -> V_36 [ V_35 ] ,
V_556 ) ;
F_299 ( V_502 , ~ V_557 , V_558 ) ;
}
static int F_310 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( F_204 ( V_22 ) )
F_272 ( V_22 ) ;
F_308 ( V_2 ) ;
F_309 ( V_2 ) ;
if ( F_204 ( V_22 ) )
F_297 ( V_22 ) ;
F_5 ( V_292 , V_294 ) ;
F_6 ( V_292 ) ;
return 0 ;
}
static int F_311 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_306 ( V_2 ) ;
F_308 ( V_2 ) ;
F_5 ( V_292 , V_553 ) ;
F_6 ( V_292 ) ;
return 0 ;
}
static void F_312 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 )
return;
F_281 ( V_22 ) ;
}
static void F_313 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_271 )
F_303 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_276 ( V_2 ) ;
V_2 -> V_12 = ~ 0 ;
}
static void F_314 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 )
return;
F_5 ( V_552 , 0 ) ;
F_273 ( V_22 ) ;
F_5 ( V_492 , 0xffffffff ) ;
F_313 ( V_2 ) ;
}
static void F_315 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 )
return;
F_5 ( V_292 , 0 ) ;
F_6 ( V_292 ) ;
F_279 ( V_2 ) ;
F_270 ( V_504 ) ;
F_313 ( V_2 ) ;
}
static void F_316 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 )
return;
F_274 ( V_22 ) ;
}
static void F_317 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_35 ;
F_159 (dev_priv, pipe)
F_5 ( F_41 ( V_35 ) , 0 ) ;
F_82 ( V_559 , 0xffff ) ;
F_82 ( V_560 , 0x0 ) ;
F_318 ( V_560 ) ;
}
static int F_319 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_82 ( V_424 ,
~ ( V_417 | V_418 ) ) ;
V_2 -> V_12 =
~ ( V_273 |
V_274 |
V_561 |
V_562 ) ;
F_82 ( V_559 , V_2 -> V_12 ) ;
F_82 ( V_560 ,
V_273 |
V_274 |
V_563 ) ;
F_318 ( V_560 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_47 ( V_2 , V_56 , V_279 ) ;
F_47 ( V_2 , V_54 , V_279 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_320 ( struct V_21 * V_22 ,
int V_564 , int V_35 , T_2 V_192 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_11 V_565 = F_321 ( V_564 ) ;
if ( ! F_156 ( V_22 , V_35 ) )
return false ;
if ( ( V_192 & V_565 ) == 0 )
goto V_566;
if ( F_322 ( V_567 ) & V_565 )
goto V_566;
F_161 ( V_22 , V_564 ) ;
F_162 ( V_22 , V_35 ) ;
return true ;
V_566:
F_160 ( V_22 , V_35 ) ;
return false ;
}
static T_9 F_323 ( int V_32 , void * V_288 )
{
struct V_21 * V_22 = V_288 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_11 V_192 , V_568 ;
T_2 V_269 [ 2 ] ;
int V_35 ;
T_11 V_569 =
V_561 |
V_562 ;
T_9 V_97 ;
if ( ! F_14 ( V_2 ) )
return V_211 ;
F_167 ( V_2 ) ;
V_97 = V_211 ;
V_192 = F_322 ( V_425 ) ;
if ( V_192 == 0 )
goto V_163;
while ( V_192 & ~ V_569 ) {
F_81 ( & V_2 -> V_7 ) ;
if ( V_192 & V_426 )
F_113 ( L_64 , V_192 ) ;
F_159 (dev_priv, pipe) {
T_1 V_3 = F_41 ( V_35 ) ;
V_269 [ V_35 ] = F_2 ( V_3 ) ;
if ( V_269 [ V_35 ] & 0x8000ffff )
F_5 ( V_3 , V_269 [ V_35 ] ) ;
}
F_84 ( & V_2 -> V_7 ) ;
F_82 ( V_425 , V_192 & ~ V_569 ) ;
V_568 = F_322 ( V_425 ) ;
if ( V_192 & V_563 )
F_85 ( & V_2 -> V_130 [ V_199 ] ) ;
F_159 (dev_priv, pipe) {
int V_564 = V_35 ;
if ( F_324 ( V_22 ) )
V_564 = ! V_564 ;
if ( V_269 [ V_35 ] & V_431 &&
F_320 ( V_22 , V_564 , V_35 , V_192 ) )
V_569 &= ~ F_321 ( V_564 ) ;
if ( V_269 [ V_35 ] & V_279 )
F_149 ( V_22 , V_35 ) ;
if ( V_269 [ V_35 ] & V_47 )
F_163 ( V_2 ,
V_35 ) ;
}
V_192 = V_568 ;
}
V_97 = V_214 ;
V_163:
F_168 ( V_2 ) ;
return V_97 ;
}
static void F_325 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_35 ;
F_159 (dev_priv, pipe) {
F_5 ( F_41 ( V_35 ) , 0 ) ;
F_5 ( F_41 ( V_35 ) , F_2 ( F_41 ( V_35 ) ) ) ;
}
F_82 ( V_559 , 0xffff ) ;
F_82 ( V_560 , 0x0 ) ;
F_82 ( V_425 , F_322 ( V_425 ) ) ;
}
static void F_326 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_35 ;
if ( F_327 ( V_22 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_282 , F_2 ( V_282 ) ) ;
}
F_82 ( V_492 , 0xeffe ) ;
F_159 (dev_priv, pipe)
F_5 ( F_41 ( V_35 ) , 0 ) ;
F_5 ( V_559 , 0xffffffff ) ;
F_5 ( V_560 , 0x0 ) ;
F_6 ( V_560 ) ;
}
static int F_328 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_39 ;
F_5 ( V_424 , ~ ( V_417 | V_418 ) ) ;
V_2 -> V_12 =
~ ( V_570 |
V_273 |
V_274 |
V_561 |
V_562 ) ;
V_39 =
V_570 |
V_273 |
V_274 |
V_563 ;
if ( F_327 ( V_22 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
V_39 |= V_291 ;
V_2 -> V_12 &= ~ V_291 ;
}
F_5 ( V_559 , V_2 -> V_12 ) ;
F_5 ( V_560 , V_39 ) ;
F_6 ( V_560 ) ;
F_51 ( V_22 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_47 ( V_2 , V_56 , V_279 ) ;
F_47 ( V_2 , V_54 , V_279 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_329 ( struct V_21 * V_22 ,
int V_564 , int V_35 , T_2 V_192 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_565 = F_321 ( V_564 ) ;
if ( ! F_156 ( V_22 , V_35 ) )
return false ;
if ( ( V_192 & V_565 ) == 0 )
goto V_566;
if ( F_2 ( V_567 ) & V_565 )
goto V_566;
F_161 ( V_22 , V_564 ) ;
F_162 ( V_22 , V_35 ) ;
return true ;
V_566:
F_160 ( V_22 , V_35 ) ;
return false ;
}
static T_9 F_330 ( int V_32 , void * V_288 )
{
struct V_21 * V_22 = V_288 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_192 , V_568 , V_269 [ V_270 ] ;
T_2 V_569 =
V_561 |
V_562 ;
int V_35 , V_97 = V_211 ;
if ( ! F_14 ( V_2 ) )
return V_211 ;
F_167 ( V_2 ) ;
V_192 = F_2 ( V_425 ) ;
do {
bool V_571 = ( V_192 & ~ V_569 ) != 0 ;
bool V_572 = false ;
F_81 ( & V_2 -> V_7 ) ;
if ( V_192 & V_426 )
F_113 ( L_64 , V_192 ) ;
F_159 (dev_priv, pipe) {
T_1 V_3 = F_41 ( V_35 ) ;
V_269 [ V_35 ] = F_2 ( V_3 ) ;
if ( V_269 [ V_35 ] & 0x8000ffff ) {
F_5 ( V_3 , V_269 [ V_35 ] ) ;
V_571 = true ;
}
}
F_84 ( & V_2 -> V_7 ) ;
if ( ! V_571 )
break;
if ( F_327 ( V_22 ) &&
V_192 & V_291 )
F_164 ( V_22 ) ;
F_5 ( V_425 , V_192 & ~ V_569 ) ;
V_568 = F_2 ( V_425 ) ;
if ( V_192 & V_563 )
F_85 ( & V_2 -> V_130 [ V_199 ] ) ;
F_159 (dev_priv, pipe) {
int V_564 = V_35 ;
if ( F_324 ( V_22 ) )
V_564 = ! V_564 ;
if ( V_269 [ V_35 ] & V_431 &&
F_329 ( V_22 , V_564 , V_35 , V_192 ) )
V_569 &= ~ F_321 ( V_564 ) ;
if ( V_269 [ V_35 ] & V_55 )
V_572 = true ;
if ( V_269 [ V_35 ] & V_279 )
F_149 ( V_22 , V_35 ) ;
if ( V_269 [ V_35 ] & V_47 )
F_163 ( V_2 ,
V_35 ) ;
}
if ( V_572 || ( V_192 & V_570 ) )
F_185 ( V_22 ) ;
V_97 = V_214 ;
V_192 = V_568 ;
} while ( V_192 & ~ V_569 );
F_168 ( V_2 ) ;
return V_97 ;
}
static void F_331 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_35 ;
if ( F_327 ( V_22 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_282 , F_2 ( V_282 ) ) ;
}
F_82 ( V_492 , 0xffff ) ;
F_159 (dev_priv, pipe) {
F_5 ( F_41 ( V_35 ) , 0 ) ;
F_5 ( F_41 ( V_35 ) , F_2 ( F_41 ( V_35 ) ) ) ;
}
F_5 ( V_559 , 0xffffffff ) ;
F_5 ( V_560 , 0x0 ) ;
F_5 ( V_425 , F_2 ( V_425 ) ) ;
}
static void F_332 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_35 ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_282 , F_2 ( V_282 ) ) ;
F_5 ( V_492 , 0xeffe ) ;
F_159 (dev_priv, pipe)
F_5 ( F_41 ( V_35 ) , 0 ) ;
F_5 ( V_559 , 0xffffffff ) ;
F_5 ( V_560 , 0x0 ) ;
F_6 ( V_560 ) ;
}
static int F_333 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_39 ;
T_2 V_573 ;
V_2 -> V_12 = ~ ( V_570 |
V_291 |
V_273 |
V_274 |
V_561 |
V_562 |
V_426 ) ;
V_39 = ~ V_2 -> V_12 ;
V_39 &= ~ ( V_561 |
V_562 ) ;
V_39 |= V_563 ;
if ( F_72 ( V_22 ) )
V_39 |= V_574 ;
F_11 ( & V_2 -> V_7 ) ;
F_47 ( V_2 , V_56 , V_280 ) ;
F_47 ( V_2 , V_56 , V_279 ) ;
F_47 ( V_2 , V_54 , V_279 ) ;
F_12 ( & V_2 -> V_7 ) ;
if ( F_72 ( V_22 ) ) {
V_573 = ~ ( V_414 |
V_407 |
V_408 |
V_418 ) ;
} else {
V_573 = ~ ( V_417 |
V_418 ) ;
}
F_5 ( V_424 , V_573 ) ;
F_5 ( V_559 , V_2 -> V_12 ) ;
F_5 ( V_560 , V_39 ) ;
F_6 ( V_560 ) ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
F_51 ( V_22 ) ;
return 0 ;
}
static void F_334 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_575 ;
F_8 ( & V_2 -> V_7 ) ;
V_575 = F_289 ( V_22 , V_576 ) ;
if ( F_72 ( V_22 ) )
V_575 |= V_577 ;
V_575 |= V_578 ;
F_7 ( V_2 ,
V_579 |
V_580 |
V_577 ,
V_575 ) ;
}
static T_9 F_335 ( int V_32 , void * V_288 )
{
struct V_21 * V_22 = V_288 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_192 , V_568 ;
T_2 V_269 [ V_270 ] ;
int V_97 = V_211 , V_35 ;
T_2 V_569 =
V_561 |
V_562 ;
if ( ! F_14 ( V_2 ) )
return V_211 ;
F_167 ( V_2 ) ;
V_192 = F_2 ( V_425 ) ;
for (; ; ) {
bool V_571 = ( V_192 & ~ V_569 ) != 0 ;
bool V_572 = false ;
F_81 ( & V_2 -> V_7 ) ;
if ( V_192 & V_426 )
F_113 ( L_64 , V_192 ) ;
F_159 (dev_priv, pipe) {
T_1 V_3 = F_41 ( V_35 ) ;
V_269 [ V_35 ] = F_2 ( V_3 ) ;
if ( V_269 [ V_35 ] & 0x8000ffff ) {
F_5 ( V_3 , V_269 [ V_35 ] ) ;
V_571 = true ;
}
}
F_84 ( & V_2 -> V_7 ) ;
if ( ! V_571 )
break;
V_97 = V_214 ;
if ( V_192 & V_291 )
F_164 ( V_22 ) ;
F_5 ( V_425 , V_192 & ~ V_569 ) ;
V_568 = F_2 ( V_425 ) ;
if ( V_192 & V_563 )
F_85 ( & V_2 -> V_130 [ V_199 ] ) ;
if ( V_192 & V_574 )
F_85 ( & V_2 -> V_130 [ V_201 ] ) ;
F_159 (dev_priv, pipe) {
if ( V_269 [ V_35 ] & V_277 &&
F_329 ( V_22 , V_35 , V_35 , V_192 ) )
V_569 &= ~ F_321 ( V_35 ) ;
if ( V_269 [ V_35 ] & V_55 )
V_572 = true ;
if ( V_269 [ V_35 ] & V_279 )
F_149 ( V_22 , V_35 ) ;
if ( V_269 [ V_35 ] & V_47 )
F_163 ( V_2 , V_35 ) ;
}
if ( V_572 || ( V_192 & V_570 ) )
F_185 ( V_22 ) ;
if ( V_269 [ 0 ] & V_280 )
F_137 ( V_22 ) ;
V_192 = V_568 ;
}
F_168 ( V_2 ) ;
return V_97 ;
}
static void F_336 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_35 ;
if ( ! V_2 )
return;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_282 , F_2 ( V_282 ) ) ;
F_5 ( V_492 , 0xffffffff ) ;
F_159 (dev_priv, pipe)
F_5 ( F_41 ( V_35 ) , 0 ) ;
F_5 ( V_559 , 0xffffffff ) ;
F_5 ( V_560 , 0x0 ) ;
F_159 (dev_priv, pipe)
F_5 ( F_41 ( V_35 ) ,
F_2 ( F_41 ( V_35 ) ) & 0x8000ffff ) ;
F_5 ( V_425 , F_2 ( V_425 ) ) ;
}
void F_337 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
F_338 ( V_2 ) ;
F_339 ( & V_2 -> V_25 . V_30 , F_96 ) ;
F_339 ( & V_2 -> V_171 . V_172 , F_104 ) ;
if ( F_48 ( V_2 ) )
V_2 -> V_24 = V_152 | V_28 ;
else
V_2 -> V_24 = V_581 ;
F_340 ( & V_2 -> V_393 . V_474 ,
F_255 ) ;
F_341 ( & V_2 -> V_582 , V_583 , V_584 ) ;
if ( F_62 ( V_2 ) ) {
V_22 -> V_585 = 0 ;
V_22 -> V_262 -> V_263 = F_53 ;
} else if ( F_72 ( V_2 ) || F_19 ( V_2 ) -> V_16 >= 5 ) {
V_22 -> V_585 = 0xffffffff ;
V_22 -> V_262 -> V_263 = F_59 ;
} else {
V_22 -> V_262 -> V_263 = F_54 ;
V_22 -> V_585 = 0xffffff ;
}
if ( ! F_62 ( V_2 ) )
V_22 -> V_586 = true ;
V_22 -> V_262 -> V_587 = F_75 ;
V_22 -> V_262 -> V_588 = F_68 ;
if ( F_49 ( V_2 ) ) {
V_22 -> V_262 -> V_589 = F_169 ;
V_22 -> V_262 -> V_590 = F_288 ;
V_22 -> V_262 -> V_591 = F_311 ;
V_22 -> V_262 -> V_592 = F_315 ;
V_22 -> V_262 -> V_593 = F_230 ;
V_22 -> V_262 -> V_594 = F_236 ;
V_2 -> V_595 . V_596 = F_334 ;
} else if ( F_48 ( V_2 ) ) {
V_22 -> V_262 -> V_589 = F_166 ;
V_22 -> V_262 -> V_590 = F_277 ;
V_22 -> V_262 -> V_591 = F_307 ;
V_22 -> V_262 -> V_592 = F_314 ;
V_22 -> V_262 -> V_593 = F_230 ;
V_22 -> V_262 -> V_594 = F_236 ;
V_2 -> V_595 . V_596 = F_334 ;
} else if ( F_19 ( V_2 ) -> V_16 >= 8 ) {
V_22 -> V_262 -> V_589 = F_206 ;
V_22 -> V_262 -> V_590 = F_281 ;
V_22 -> V_262 -> V_591 = F_310 ;
V_22 -> V_262 -> V_592 = F_312 ;
V_22 -> V_262 -> V_593 = F_231 ;
V_22 -> V_262 -> V_594 = F_237 ;
if ( F_200 ( V_22 ) )
V_2 -> V_595 . V_596 = F_296 ;
else if ( F_205 ( V_22 ) )
V_2 -> V_595 . V_596 = F_294 ;
else
V_2 -> V_595 . V_596 = F_295 ;
} else if ( F_204 ( V_22 ) ) {
V_22 -> V_262 -> V_589 = F_197 ;
V_22 -> V_262 -> V_590 = F_274 ;
V_22 -> V_262 -> V_591 = F_300 ;
V_22 -> V_262 -> V_592 = F_316 ;
V_22 -> V_262 -> V_593 = F_228 ;
V_22 -> V_262 -> V_594 = F_234 ;
V_2 -> V_595 . V_596 = F_295 ;
} else {
if ( F_19 ( V_2 ) -> V_16 == 2 ) {
V_22 -> V_262 -> V_590 = F_317 ;
V_22 -> V_262 -> V_591 = F_319 ;
V_22 -> V_262 -> V_589 = F_323 ;
V_22 -> V_262 -> V_592 = F_325 ;
} else if ( F_19 ( V_2 ) -> V_16 == 3 ) {
V_22 -> V_262 -> V_590 = F_326 ;
V_22 -> V_262 -> V_591 = F_328 ;
V_22 -> V_262 -> V_592 = F_331 ;
V_22 -> V_262 -> V_589 = F_330 ;
} else {
V_22 -> V_262 -> V_590 = F_332 ;
V_22 -> V_262 -> V_591 = F_333 ;
V_22 -> V_262 -> V_592 = F_336 ;
V_22 -> V_262 -> V_589 = F_335 ;
}
if ( F_327 ( V_2 ) )
V_2 -> V_595 . V_596 = F_334 ;
V_22 -> V_262 -> V_593 = F_227 ;
V_22 -> V_262 -> V_594 = F_233 ;
}
}
int F_342 ( struct V_1 * V_2 )
{
V_2 -> V_597 . V_598 = true ;
return F_343 ( V_2 -> V_22 , V_2 -> V_22 -> V_599 -> V_32 ) ;
}
void F_344 ( struct V_1 * V_2 )
{
F_345 ( V_2 -> V_22 ) ;
F_346 ( V_2 ) ;
V_2 -> V_597 . V_598 = false ;
}
void F_347 ( struct V_1 * V_2 )
{
V_2 -> V_22 -> V_262 -> V_592 ( V_2 -> V_22 ) ;
V_2 -> V_597 . V_598 = false ;
F_35 ( V_2 -> V_22 -> V_32 ) ;
}
void F_348 ( struct V_1 * V_2 )
{
V_2 -> V_597 . V_598 = true ;
V_2 -> V_22 -> V_262 -> V_590 ( V_2 -> V_22 ) ;
V_2 -> V_22 -> V_262 -> V_591 ( V_2 -> V_22 ) ;
}
