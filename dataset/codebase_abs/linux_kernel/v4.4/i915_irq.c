static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_3 ) ;
if ( V_4 == 0 )
return;
F_3 ( 1 , L_1 ,
V_3 , V_4 ) ;
F_4 ( V_3 , 0xffffffff ) ;
F_5 ( V_3 ) ;
F_4 ( V_3 , 0xffffffff ) ;
F_5 ( V_3 ) ;
}
static inline void
F_6 ( struct V_1 * V_2 ,
T_2 V_5 ,
T_2 V_6 )
{
T_2 V_4 ;
F_7 ( & V_2 -> V_7 ) ;
F_8 ( V_6 & ~ V_5 ) ;
V_4 = F_2 ( V_8 ) ;
V_4 &= ~ V_5 ;
V_4 |= V_6 ;
F_4 ( V_8 , V_4 ) ;
}
void F_9 ( struct V_1 * V_2 ,
T_2 V_5 ,
T_2 V_6 )
{
F_10 ( & V_2 -> V_7 ) ;
F_6 ( V_2 , V_5 , V_6 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_2 V_10 )
{
T_2 V_11 ;
F_7 ( & V_2 -> V_7 ) ;
F_8 ( V_10 & ~ V_9 ) ;
if ( F_8 ( ! F_13 ( V_2 ) ) )
return;
V_11 = V_2 -> V_12 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_12 ) {
V_2 -> V_12 = V_11 ;
F_4 ( V_13 , V_2 -> V_12 ) ;
F_5 ( V_13 ) ;
}
}
void
F_14 ( struct V_1 * V_2 , T_1 V_5 )
{
F_12 ( V_2 , V_5 , V_5 ) ;
}
void
F_15 ( struct V_1 * V_2 , T_1 V_5 )
{
F_12 ( V_2 , V_5 , 0 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_2 V_10 )
{
F_7 ( & V_2 -> V_7 ) ;
F_8 ( V_10 & ~ V_9 ) ;
if ( F_8 ( ! F_13 ( V_2 ) ) )
return;
V_2 -> V_14 &= ~ V_9 ;
V_2 -> V_14 |= ( ~ V_10 & V_9 ) ;
F_4 ( V_15 , V_2 -> V_14 ) ;
F_5 ( V_15 ) ;
}
void F_17 ( struct V_1 * V_2 , T_2 V_5 )
{
F_16 ( V_2 , V_5 , V_5 ) ;
}
void F_18 ( struct V_1 * V_2 , T_2 V_5 )
{
F_16 ( V_2 , V_5 , 0 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ) -> V_16 >= 8 ? F_21 ( 2 ) : V_17 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ) -> V_16 >= 8 ? F_23 ( 2 ) : V_18 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ) -> V_16 >= 8 ? F_25 ( 2 ) : V_19 ;
}
static void F_26 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_2 V_10 )
{
T_2 V_11 ;
F_8 ( V_10 & ~ V_9 ) ;
F_7 ( & V_2 -> V_7 ) ;
V_11 = V_2 -> V_20 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_20 ) {
V_2 -> V_20 = V_11 ;
F_4 ( F_22 ( V_2 ) , V_2 -> V_20 ) ;
F_5 ( F_22 ( V_2 ) ) ;
}
}
void F_27 ( struct V_1 * V_2 , T_2 V_5 )
{
if ( F_8 ( ! F_13 ( V_2 ) ) )
return;
F_26 ( V_2 , V_5 , V_5 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
T_2 V_5 )
{
F_26 ( V_2 , V_5 , 0 ) ;
}
void F_29 ( struct V_1 * V_2 , T_2 V_5 )
{
if ( F_8 ( ! F_13 ( V_2 ) ) )
return;
F_28 ( V_2 , V_5 ) ;
}
void F_30 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_3 = F_19 ( V_2 ) ;
F_10 ( & V_2 -> V_7 ) ;
F_4 ( V_3 , V_2 -> V_24 ) ;
F_4 ( V_3 , V_2 -> V_24 ) ;
F_5 ( V_3 ) ;
V_2 -> V_25 . V_26 = 0 ;
F_11 ( & V_2 -> V_7 ) ;
}
void F_31 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_10 ( & V_2 -> V_7 ) ;
F_8 ( V_2 -> V_25 . V_26 ) ;
F_8 ( F_2 ( F_19 ( V_2 ) ) & V_2 -> V_24 ) ;
V_2 -> V_25 . V_27 = true ;
F_4 ( F_24 ( V_2 ) , F_2 ( F_24 ( V_2 ) ) |
V_2 -> V_24 ) ;
F_27 ( V_2 , V_2 -> V_24 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
T_1 F_32 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( F_20 ( V_2 ) -> V_16 <= 7 && ! F_33 ( V_2 ) )
V_5 &= ~ V_28 ;
if ( F_20 ( V_2 ) -> V_16 >= 8 )
V_5 &= ~ V_29 ;
return V_5 ;
}
void F_34 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_10 ( & V_2 -> V_7 ) ;
V_2 -> V_25 . V_27 = false ;
F_11 ( & V_2 -> V_7 ) ;
F_35 ( & V_2 -> V_25 . V_30 ) ;
F_10 ( & V_2 -> V_7 ) ;
F_4 ( V_31 , F_32 ( V_2 , ~ 0 ) ) ;
F_28 ( V_2 , V_2 -> V_24 ) ;
F_4 ( F_24 ( V_2 ) , F_2 ( F_24 ( V_2 ) ) &
~ V_2 -> V_24 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_36 ( V_22 -> V_32 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_2 V_10 )
{
T_2 V_11 ;
T_2 V_33 ;
F_7 ( & V_2 -> V_7 ) ;
F_8 ( V_10 & ~ V_9 ) ;
if ( F_8 ( ! F_13 ( V_2 ) ) )
return;
V_33 = F_2 ( V_34 ) ;
V_11 = V_33 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_33 ) {
F_4 ( V_34 , V_11 ) ;
F_5 ( V_34 ) ;
}
}
void F_38 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_2 V_10 )
{
T_2 V_35 = F_2 ( V_36 ) ;
V_35 &= ~ V_9 ;
V_35 |= ( ~ V_10 & V_9 ) ;
F_8 ( V_10 & ~ V_9 ) ;
F_7 ( & V_2 -> V_7 ) ;
if ( F_8 ( ! F_13 ( V_2 ) ) )
return;
F_4 ( V_36 , V_35 ) ;
F_5 ( V_36 ) ;
}
static void
F_39 ( struct V_1 * V_2 , enum V_37 V_37 ,
T_1 V_38 , T_1 V_39 )
{
T_1 V_3 = F_40 ( V_37 ) ;
T_1 V_40 = F_2 ( V_3 ) & V_41 ;
F_7 ( & V_2 -> V_7 ) ;
F_8 ( ! F_13 ( V_2 ) ) ;
if ( F_41 ( V_38 & ~ V_41 ||
V_39 & ~ V_42 ,
L_2 ,
F_42 ( V_37 ) , V_38 , V_39 ) )
return;
if ( ( V_40 & V_38 ) == V_38 )
return;
V_2 -> V_43 [ V_37 ] |= V_39 ;
V_40 |= V_38 | V_39 ;
F_4 ( V_3 , V_40 ) ;
F_5 ( V_3 ) ;
}
static void
F_43 ( struct V_1 * V_2 , enum V_37 V_37 ,
T_1 V_38 , T_1 V_39 )
{
T_1 V_3 = F_40 ( V_37 ) ;
T_1 V_40 = F_2 ( V_3 ) & V_41 ;
F_7 ( & V_2 -> V_7 ) ;
F_8 ( ! F_13 ( V_2 ) ) ;
if ( F_41 ( V_38 & ~ V_41 ||
V_39 & ~ V_42 ,
L_2 ,
F_42 ( V_37 ) , V_38 , V_39 ) )
return;
if ( ( V_40 & V_38 ) == 0 )
return;
V_2 -> V_43 [ V_37 ] &= ~ V_39 ;
V_40 &= ~ V_38 ;
F_4 ( V_3 , V_40 ) ;
F_5 ( V_3 ) ;
}
static T_1 F_44 ( struct V_21 * V_22 , T_1 V_39 )
{
T_1 V_38 = V_39 << 16 ;
if ( F_45 ( V_39 & V_44 ) )
return 0 ;
if ( F_45 ( V_39 & V_45 ) )
return 0 ;
V_38 &= ~ ( V_46 |
V_47 |
V_48 ) ;
if ( V_39 & V_49 )
V_38 |= V_47 ;
if ( V_39 & V_50 )
V_38 |= V_48 ;
return V_38 ;
}
void
F_46 ( struct V_1 * V_2 , enum V_37 V_37 ,
T_1 V_39 )
{
T_1 V_38 ;
if ( F_47 ( V_2 -> V_22 ) )
V_38 = F_44 ( V_2 -> V_22 ,
V_39 ) ;
else
V_38 = V_39 << 16 ;
F_39 ( V_2 , V_37 , V_38 , V_39 ) ;
}
void
F_48 ( struct V_1 * V_2 , enum V_37 V_37 ,
T_1 V_39 )
{
T_1 V_38 ;
if ( F_47 ( V_2 -> V_22 ) )
V_38 = F_44 ( V_2 -> V_22 ,
V_39 ) ;
else
V_38 = V_39 << 16 ;
F_43 ( V_2 , V_37 , V_38 , V_39 ) ;
}
static void F_49 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 -> V_51 . V_52 || ! F_50 ( V_22 ) )
return;
F_10 ( & V_2 -> V_7 ) ;
F_46 ( V_2 , V_53 , V_54 ) ;
if ( F_20 ( V_22 ) -> V_16 >= 4 )
F_46 ( V_2 , V_55 ,
V_54 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
static T_1 F_51 ( struct V_21 * V_22 , unsigned int V_37 )
{
return 0 ;
}
static T_1 F_52 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_56 ;
unsigned long V_57 ;
T_1 V_58 , V_59 , V_60 , V_61 , V_62 , V_63 , V_64 ;
struct V_65 * V_65 =
F_53 ( V_2 -> V_66 [ V_37 ] ) ;
const struct V_67 * V_68 = & V_65 -> V_69 . V_70 ;
V_64 = V_68 -> V_71 ;
V_63 = V_68 -> V_72 ;
V_62 = V_68 -> V_73 ;
if ( V_68 -> V_74 & V_75 )
V_62 = F_54 ( V_62 , 2 ) ;
V_62 *= V_64 ;
V_62 -= V_64 - V_63 ;
V_56 = F_55 ( V_37 ) ;
V_57 = F_56 ( V_37 ) ;
do {
V_58 = F_2 ( V_56 ) & V_76 ;
V_60 = F_2 ( V_57 ) ;
V_59 = F_2 ( V_56 ) & V_76 ;
} while ( V_58 != V_59 );
V_58 >>= V_77 ;
V_61 = V_60 & V_78 ;
V_60 >>= V_79 ;
return ( ( ( V_58 << 8 ) | V_60 ) + ( V_61 >= V_62 ) ) & 0xffffff ;
}
static T_1 F_57 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
return F_2 ( F_58 ( V_37 ) ) ;
}
static int F_59 ( struct V_65 * V_80 )
{
struct V_21 * V_22 = V_80 -> V_69 . V_22 ;
struct V_1 * V_2 = V_22 -> V_23 ;
const struct V_67 * V_68 = & V_80 -> V_69 . V_70 ;
enum V_37 V_37 = V_80 -> V_37 ;
int V_81 , V_82 ;
V_82 = V_68 -> V_83 ;
if ( V_68 -> V_74 & V_75 )
V_82 /= 2 ;
if ( F_60 ( V_22 ) )
V_81 = F_61 ( V_2 , F_62 ( V_37 ) ) & V_84 ;
else
V_81 = F_61 ( V_2 , F_62 ( V_37 ) ) & V_85 ;
if ( F_63 ( V_22 ) && ! V_81 ) {
int V_86 , V_87 ;
for ( V_86 = 0 ; V_86 < 100 ; V_86 ++ ) {
F_64 ( 1 ) ;
V_87 = F_61 ( V_2 , F_62 ( V_37 ) ) &
V_85 ;
if ( V_87 != V_81 ) {
V_81 = V_87 ;
break;
}
}
}
return ( V_81 + V_80 -> V_88 ) % V_82 ;
}
static int F_65 ( struct V_21 * V_22 , unsigned int V_37 ,
unsigned int V_74 , int * V_89 , int * V_90 ,
T_3 * V_91 , T_3 * V_92 ,
const struct V_67 * V_68 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_93 * V_80 = V_2 -> V_66 [ V_37 ] ;
struct V_65 * V_65 = F_53 ( V_80 ) ;
int V_81 ;
int V_62 , V_94 , V_63 , V_64 , V_82 ;
bool V_95 = true ;
int V_96 = 0 ;
unsigned long V_97 ;
if ( F_8 ( ! V_68 -> V_98 ) ) {
F_66 ( L_3
L_4 , F_42 ( V_37 ) ) ;
return 0 ;
}
V_64 = V_68 -> V_71 ;
V_63 = V_68 -> V_72 ;
V_82 = V_68 -> V_83 ;
V_62 = V_68 -> V_73 ;
V_94 = V_68 -> V_99 ;
if ( V_68 -> V_74 & V_75 ) {
V_62 = F_54 ( V_62 , 2 ) ;
V_94 /= 2 ;
V_82 /= 2 ;
}
V_96 |= V_100 | V_101 ;
F_67 ( & V_2 -> V_102 . V_103 , V_97 ) ;
if ( V_91 )
* V_91 = F_68 () ;
if ( F_60 ( V_22 ) || F_69 ( V_22 ) || F_20 ( V_22 ) -> V_16 >= 5 ) {
V_81 = F_59 ( V_65 ) ;
} else {
V_81 = ( F_61 ( V_2 , F_56 ( V_37 ) ) & V_78 ) >> V_104 ;
V_62 *= V_64 ;
V_94 *= V_64 ;
V_82 *= V_64 ;
if ( V_81 >= V_82 )
V_81 = V_82 - 1 ;
V_81 = ( V_81 + V_64 - V_63 ) % V_82 ;
}
if ( V_92 )
* V_92 = F_68 () ;
F_70 ( & V_2 -> V_102 . V_103 , V_97 ) ;
V_95 = V_81 >= V_62 && V_81 < V_94 ;
if ( V_81 >= V_62 )
V_81 -= V_94 ;
else
V_81 += V_82 - V_94 ;
if ( F_60 ( V_22 ) || F_69 ( V_22 ) || F_20 ( V_22 ) -> V_16 >= 5 ) {
* V_89 = V_81 ;
* V_90 = 0 ;
} else {
* V_89 = V_81 / V_64 ;
* V_90 = V_81 - ( * V_89 * V_64 ) ;
}
if ( V_95 )
V_96 |= V_105 ;
return V_96 ;
}
int F_71 ( struct V_65 * V_80 )
{
struct V_1 * V_2 = V_80 -> V_69 . V_22 -> V_23 ;
unsigned long V_97 ;
int V_81 ;
F_67 ( & V_2 -> V_102 . V_103 , V_97 ) ;
V_81 = F_59 ( V_80 ) ;
F_70 ( & V_2 -> V_102 . V_103 , V_97 ) ;
return V_81 ;
}
static int F_72 ( struct V_21 * V_22 , unsigned int V_37 ,
int * V_106 ,
struct V_107 * V_108 ,
unsigned V_74 )
{
struct V_93 * V_80 ;
if ( V_37 >= F_20 ( V_22 ) -> V_109 ) {
F_73 ( L_5 , V_37 ) ;
return - V_110 ;
}
V_80 = F_74 ( V_22 , V_37 ) ;
if ( V_80 == NULL ) {
F_73 ( L_5 , V_37 ) ;
return - V_110 ;
}
if ( ! V_80 -> V_70 . V_98 ) {
F_75 ( L_6 , V_37 ) ;
return - V_111 ;
}
return F_76 ( V_22 , V_37 , V_106 ,
V_108 , V_74 ,
& V_80 -> V_70 ) ;
}
static void F_77 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_112 , V_113 , V_114 , V_115 ;
T_4 V_116 ;
F_78 ( & V_117 ) ;
F_79 ( V_118 , F_2 ( V_118 ) ) ;
V_116 = V_2 -> V_119 . V_120 ;
F_79 ( V_118 , V_121 ) ;
V_112 = F_2 ( V_122 ) ;
V_113 = F_2 ( V_123 ) ;
V_114 = F_2 ( V_124 ) ;
V_115 = F_2 ( V_125 ) ;
if ( V_112 > V_114 ) {
if ( V_2 -> V_119 . V_120 != V_2 -> V_119 . V_126 )
V_116 = V_2 -> V_119 . V_120 - 1 ;
if ( V_116 < V_2 -> V_119 . V_126 )
V_116 = V_2 -> V_119 . V_126 ;
} else if ( V_113 < V_115 ) {
if ( V_2 -> V_119 . V_120 != V_2 -> V_119 . V_127 )
V_116 = V_2 -> V_119 . V_120 + 1 ;
if ( V_116 > V_2 -> V_119 . V_127 )
V_116 = V_2 -> V_119 . V_127 ;
}
if ( F_80 ( V_22 , V_116 ) )
V_2 -> V_119 . V_120 = V_116 ;
F_81 ( & V_117 ) ;
return;
}
static void F_82 ( struct V_128 * V_129 )
{
if ( ! F_83 ( V_129 ) )
return;
F_84 ( V_129 ) ;
F_85 ( & V_129 -> V_130 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
V_132 -> V_133 = F_87 ( V_2 , V_134 ) ;
V_132 -> V_135 = F_2 ( V_136 ) ;
V_132 -> V_137 = F_2 ( V_138 ) ;
}
static bool F_88 ( struct V_1 * V_2 ,
const struct V_131 * V_139 ,
const struct V_131 * V_140 ,
int V_141 )
{
T_5 time , V_142 ;
unsigned int V_143 = 100 ;
if ( V_139 -> V_133 == 0 )
return false ;
if ( F_2 ( V_144 ) & V_145 )
V_143 <<= 8 ;
time = V_140 -> V_133 - V_139 -> V_133 ;
time *= V_141 * V_2 -> V_146 ;
V_142 = V_140 -> V_135 - V_139 -> V_135 ;
V_142 += V_140 -> V_137 - V_139 -> V_137 ;
V_142 *= V_143 * V_147 ;
return V_142 >= time ;
}
void F_89 ( struct V_1 * V_2 )
{
F_86 ( V_2 , & V_2 -> V_25 . V_148 ) ;
V_2 -> V_25 . V_149 = V_2 -> V_25 . V_148 ;
}
static T_1 F_90 ( struct V_1 * V_2 , T_1 V_26 )
{
struct V_131 V_140 ;
T_1 V_150 = 0 ;
if ( ( V_26 & ( V_151 | V_28 ) ) == 0 )
return 0 ;
F_86 ( V_2 , & V_140 ) ;
if ( V_140 . V_133 == 0 )
return 0 ;
if ( V_26 & V_151 ) {
if ( ! F_88 ( V_2 ,
& V_2 -> V_25 . V_148 , & V_140 ,
V_2 -> V_25 . V_152 ) )
V_150 |= V_153 ;
V_2 -> V_25 . V_148 = V_140 ;
}
if ( V_26 & V_28 ) {
if ( F_88 ( V_2 ,
& V_2 -> V_25 . V_149 , & V_140 ,
V_2 -> V_25 . V_154 ) )
V_150 |= V_155 ;
V_2 -> V_25 . V_149 = V_140 ;
}
return V_150 ;
}
static bool F_91 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
int V_86 ;
F_92 (ring, dev_priv, i)
if ( V_129 -> V_156 )
return true ;
return false ;
}
static void F_93 ( struct V_157 * V_30 )
{
struct V_1 * V_2 =
F_94 ( V_30 , struct V_1 , V_25 . V_30 ) ;
bool V_158 ;
int V_116 , V_159 , V_160 , V_161 ;
T_1 V_26 ;
F_10 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_25 . V_27 ) {
F_11 ( & V_2 -> V_7 ) ;
return;
}
V_26 = V_2 -> V_25 . V_26 ;
V_2 -> V_25 . V_26 = 0 ;
F_27 ( V_2 , V_2 -> V_24 ) ;
V_158 = V_2 -> V_25 . V_158 ;
V_2 -> V_25 . V_158 = false ;
F_11 ( & V_2 -> V_7 ) ;
F_8 ( V_26 & ~ V_2 -> V_24 ) ;
if ( ( V_26 & V_2 -> V_24 ) == 0 && ! V_158 )
return;
F_95 ( & V_2 -> V_25 . V_162 ) ;
V_26 |= F_90 ( V_2 , V_26 ) ;
V_159 = V_2 -> V_25 . V_163 ;
V_116 = V_2 -> V_25 . V_164 ;
V_160 = V_2 -> V_25 . V_165 ;
V_161 = V_2 -> V_25 . V_166 ;
if ( V_158 ) {
V_116 = V_2 -> V_25 . V_166 ;
V_159 = 0 ;
} else if ( V_26 & V_155 ) {
if ( V_159 > 0 )
V_159 *= 2 ;
else
V_159 = F_96 ( V_2 ) ? 2 : 1 ;
if ( V_116 < V_2 -> V_25 . V_167 - V_159 ) {
V_116 = V_2 -> V_25 . V_167 ;
V_159 = 0 ;
}
} else if ( F_91 ( V_2 ) ) {
V_159 = 0 ;
} else if ( V_26 & V_168 ) {
if ( V_2 -> V_25 . V_164 > V_2 -> V_25 . V_167 )
V_116 = V_2 -> V_25 . V_167 ;
else
V_116 = V_2 -> V_25 . V_165 ;
V_159 = 0 ;
} else if ( V_26 & V_153 ) {
if ( V_159 < 0 )
V_159 *= 2 ;
else
V_159 = F_96 ( V_2 ) ? - 2 : - 1 ;
} else {
V_159 = 0 ;
}
V_2 -> V_25 . V_163 = V_159 ;
V_116 += V_159 ;
V_116 = F_97 ( int , V_116 , V_160 , V_161 ) ;
F_98 ( V_2 -> V_22 , V_116 ) ;
F_99 ( & V_2 -> V_25 . V_162 ) ;
}
static void F_100 ( struct V_157 * V_30 )
{
struct V_1 * V_2 =
F_94 ( V_30 , struct V_1 , V_169 . V_170 ) ;
T_1 V_171 , V_172 , V_173 , V_174 ;
char * V_175 [ 6 ] ;
T_2 V_176 ;
T_6 V_177 = 0 ;
F_95 ( & V_2 -> V_22 -> V_178 ) ;
if ( F_8 ( ! V_2 -> V_169 . V_179 ) )
goto V_180;
V_176 = F_2 ( V_181 ) ;
F_4 ( V_181 , V_176 & ~ V_182 ) ;
F_5 ( V_181 ) ;
while ( ( V_177 = F_101 ( V_2 -> V_169 . V_179 ) ) != 0 ) {
T_1 V_3 ;
V_177 -- ;
if ( F_45 ( V_177 >= F_102 ( V_2 -> V_22 ) ) )
break;
V_2 -> V_169 . V_179 &= ~ ( 1 << V_177 ) ;
V_3 = V_183 + ( V_177 * 0x200 ) ;
V_171 = F_2 ( V_3 ) ;
V_172 = F_103 ( V_171 ) ;
V_173 = F_104 ( V_171 ) ;
V_174 = F_105 ( V_171 ) ;
F_4 ( V_3 , V_184 | V_185 ) ;
F_5 ( V_3 ) ;
V_175 [ 0 ] = V_186 L_7 ;
V_175 [ 1 ] = F_106 ( V_187 , L_8 , V_172 ) ;
V_175 [ 2 ] = F_106 ( V_187 , L_9 , V_173 ) ;
V_175 [ 3 ] = F_106 ( V_187 , L_10 , V_174 ) ;
V_175 [ 4 ] = F_106 ( V_187 , L_11 , V_177 ) ;
V_175 [ 5 ] = NULL ;
F_107 ( & V_2 -> V_22 -> V_188 -> V_189 -> V_190 ,
V_191 , V_175 ) ;
F_108 ( L_12 ,
V_177 , V_172 , V_173 , V_174 ) ;
F_109 ( V_175 [ 4 ] ) ;
F_109 ( V_175 [ 3 ] ) ;
F_109 ( V_175 [ 2 ] ) ;
F_109 ( V_175 [ 1 ] ) ;
}
F_4 ( V_181 , V_176 ) ;
V_180:
F_8 ( V_2 -> V_169 . V_179 ) ;
F_10 ( & V_2 -> V_7 ) ;
F_17 ( V_2 , F_110 ( V_2 -> V_22 ) ) ;
F_11 ( & V_2 -> V_7 ) ;
F_99 ( & V_2 -> V_22 -> V_178 ) ;
}
static void F_111 ( struct V_21 * V_22 , T_1 V_192 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! F_112 ( V_22 ) )
return;
F_78 ( & V_2 -> V_7 ) ;
F_18 ( V_2 , F_110 ( V_22 ) ) ;
F_81 ( & V_2 -> V_7 ) ;
V_192 &= F_110 ( V_22 ) ;
if ( V_192 & V_193 )
V_2 -> V_169 . V_179 |= 1 << 1 ;
if ( V_192 & V_194 )
V_2 -> V_169 . V_179 |= 1 << 0 ;
F_113 ( V_2 -> V_195 , & V_2 -> V_169 . V_170 ) ;
}
static void F_114 ( struct V_21 * V_22 ,
struct V_1 * V_2 ,
T_1 V_196 )
{
if ( V_196 &
( V_197 | V_198 ) )
F_82 ( & V_2 -> V_129 [ V_199 ] ) ;
if ( V_196 & V_200 )
F_82 ( & V_2 -> V_129 [ V_201 ] ) ;
}
static void F_115 ( struct V_21 * V_22 ,
struct V_1 * V_2 ,
T_1 V_196 )
{
if ( V_196 &
( V_197 | V_198 ) )
F_82 ( & V_2 -> V_129 [ V_199 ] ) ;
if ( V_196 & V_202 )
F_82 ( & V_2 -> V_129 [ V_201 ] ) ;
if ( V_196 & V_203 )
F_82 ( & V_2 -> V_129 [ V_204 ] ) ;
if ( V_196 & ( V_205 |
V_206 |
V_207 ) )
F_108 ( L_13 , V_196 ) ;
if ( V_196 & F_110 ( V_22 ) )
F_111 ( V_22 , V_196 ) ;
}
static T_7 F_116 ( struct V_1 * V_2 ,
T_1 V_208 )
{
T_7 V_96 = V_209 ;
if ( V_208 & ( V_210 | V_211 ) ) {
T_1 V_212 = F_117 ( F_21 ( 0 ) ) ;
if ( V_212 ) {
F_118 ( F_21 ( 0 ) , V_212 ) ;
V_96 = V_213 ;
if ( V_212 & ( V_214 << V_215 ) )
F_119 ( & V_2 -> V_129 [ V_199 ] ) ;
if ( V_212 & ( V_197 << V_215 ) )
F_82 ( & V_2 -> V_129 [ V_199 ] ) ;
if ( V_212 & ( V_214 << V_216 ) )
F_119 ( & V_2 -> V_129 [ V_204 ] ) ;
if ( V_212 & ( V_197 << V_216 ) )
F_82 ( & V_2 -> V_129 [ V_204 ] ) ;
} else
F_73 ( L_14 ) ;
}
if ( V_208 & ( V_217 | V_218 ) ) {
T_1 V_212 = F_117 ( F_21 ( 1 ) ) ;
if ( V_212 ) {
F_118 ( F_21 ( 1 ) , V_212 ) ;
V_96 = V_213 ;
if ( V_212 & ( V_214 << V_219 ) )
F_119 ( & V_2 -> V_129 [ V_201 ] ) ;
if ( V_212 & ( V_197 << V_219 ) )
F_82 ( & V_2 -> V_129 [ V_201 ] ) ;
if ( V_212 & ( V_214 << V_220 ) )
F_119 ( & V_2 -> V_129 [ V_221 ] ) ;
if ( V_212 & ( V_197 << V_220 ) )
F_82 ( & V_2 -> V_129 [ V_221 ] ) ;
} else
F_73 ( L_15 ) ;
}
if ( V_208 & V_222 ) {
T_1 V_212 = F_117 ( F_21 ( 3 ) ) ;
if ( V_212 ) {
F_118 ( F_21 ( 3 ) , V_212 ) ;
V_96 = V_213 ;
if ( V_212 & ( V_214 << V_223 ) )
F_119 ( & V_2 -> V_129 [ V_224 ] ) ;
if ( V_212 & ( V_197 << V_223 ) )
F_82 ( & V_2 -> V_129 [ V_224 ] ) ;
} else
F_73 ( L_16 ) ;
}
if ( V_208 & V_225 ) {
T_1 V_212 = F_117 ( F_21 ( 2 ) ) ;
if ( V_212 & V_2 -> V_24 ) {
F_118 ( F_21 ( 2 ) ,
V_212 & V_2 -> V_24 ) ;
V_96 = V_213 ;
F_120 ( V_2 , V_212 ) ;
} else
F_73 ( L_17 ) ;
}
return V_96 ;
}
static bool F_121 ( enum V_226 V_226 , T_1 V_4 )
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
static bool F_122 ( enum V_226 V_226 , T_1 V_4 )
{
switch ( V_226 ) {
case V_233 :
return V_4 & V_234 ;
default:
return false ;
}
}
static bool F_123 ( enum V_226 V_226 , T_1 V_4 )
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
static bool F_124 ( enum V_226 V_226 , T_1 V_4 )
{
switch ( V_226 ) {
case V_227 :
return V_4 & V_237 ;
default:
return false ;
}
}
static bool F_125 ( enum V_226 V_226 , T_1 V_4 )
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
static bool F_126 ( enum V_226 V_226 , T_1 V_4 )
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
static void F_127 ( T_1 * V_241 , T_1 * V_242 ,
T_1 V_243 , T_1 V_244 ,
const T_1 V_245 [ V_246 ] ,
bool F_128 ( enum V_226 V_226 , T_1 V_4 ) )
{
enum V_226 V_226 ;
int V_86 ;
F_129 (i) {
if ( ( V_245 [ V_86 ] & V_243 ) == 0 )
continue;
* V_241 |= F_130 ( V_86 ) ;
if ( ! F_131 ( V_86 , & V_226 ) )
continue;
if ( F_128 ( V_226 , V_244 ) )
* V_242 |= F_130 ( V_86 ) ;
}
F_66 ( L_18 ,
V_243 , V_244 , * V_241 ) ;
}
static void F_132 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_85 ( & V_2 -> V_247 ) ;
}
static void F_133 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_85 ( & V_2 -> V_247 ) ;
}
static void F_134 ( struct V_21 * V_22 , enum V_37 V_37 ,
T_2 V_248 , T_2 V_249 ,
T_2 V_250 , T_2 V_251 ,
T_2 V_252 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_253 * V_254 = & V_2 -> V_254 [ V_37 ] ;
struct V_255 * V_256 ;
int V_257 , V_258 ;
F_78 ( & V_254 -> V_103 ) ;
if ( ! V_254 -> V_259 ) {
F_81 ( & V_254 -> V_103 ) ;
F_75 ( L_19 ) ;
return;
}
V_257 = V_254 -> V_257 ;
V_258 = V_254 -> V_258 ;
if ( F_135 ( V_257 , V_258 , V_260 ) < 1 ) {
F_81 ( & V_254 -> V_103 ) ;
F_73 ( L_20 ) ;
return;
}
V_256 = & V_254 -> V_259 [ V_257 ] ;
V_256 -> V_261 = V_22 -> V_262 -> V_263 ( V_22 , V_37 ) ;
V_256 -> V_264 [ 0 ] = V_248 ;
V_256 -> V_264 [ 1 ] = V_249 ;
V_256 -> V_264 [ 2 ] = V_250 ;
V_256 -> V_264 [ 3 ] = V_251 ;
V_256 -> V_264 [ 4 ] = V_252 ;
V_257 = ( V_257 + 1 ) & ( V_260 - 1 ) ;
V_254 -> V_257 = V_257 ;
F_81 ( & V_254 -> V_103 ) ;
F_136 ( & V_254 -> V_195 ) ;
}
static inline void
F_134 ( struct V_21 * V_22 , enum V_37 V_37 ,
T_2 V_248 , T_2 V_249 ,
T_2 V_250 , T_2 V_251 ,
T_2 V_252 ) {}
static void F_137 ( struct V_21 * V_22 , enum V_37 V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_134 ( V_22 , V_37 ,
F_2 ( F_138 ( V_37 ) ) ,
0 , 0 , 0 , 0 ) ;
}
static void F_139 ( struct V_21 * V_22 , enum V_37 V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_134 ( V_22 , V_37 ,
F_2 ( F_138 ( V_37 ) ) ,
F_2 ( F_140 ( V_37 ) ) ,
F_2 ( F_141 ( V_37 ) ) ,
F_2 ( F_142 ( V_37 ) ) ,
F_2 ( F_143 ( V_37 ) ) ) ;
}
static void F_144 ( struct V_21 * V_22 , enum V_37 V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_265 , V_266 ;
if ( F_20 ( V_22 ) -> V_16 >= 3 )
V_265 = F_2 ( F_145 ( V_37 ) ) ;
else
V_265 = 0 ;
if ( F_20 ( V_22 ) -> V_16 >= 5 || F_69 ( V_22 ) )
V_266 = F_2 ( F_146 ( V_37 ) ) ;
else
V_266 = 0 ;
F_134 ( V_22 , V_37 ,
F_2 ( F_147 ( V_37 ) ) ,
F_2 ( F_148 ( V_37 ) ) ,
F_2 ( F_149 ( V_37 ) ) ,
V_265 , V_266 ) ;
}
static void F_120 ( struct V_1 * V_2 , T_1 V_26 )
{
if ( V_26 & V_2 -> V_24 ) {
F_78 ( & V_2 -> V_7 ) ;
F_29 ( V_2 , V_26 & V_2 -> V_24 ) ;
if ( V_2 -> V_25 . V_27 ) {
V_2 -> V_25 . V_26 |= V_26 & V_2 -> V_24 ;
F_113 ( V_2 -> V_195 , & V_2 -> V_25 . V_30 ) ;
}
F_81 ( & V_2 -> V_7 ) ;
}
if ( F_20 ( V_2 ) -> V_16 >= 8 )
return;
if ( F_150 ( V_2 -> V_22 ) ) {
if ( V_26 & V_267 )
F_82 ( & V_2 -> V_129 [ V_224 ] ) ;
if ( V_26 & V_268 )
F_108 ( L_21 , V_26 ) ;
}
}
static bool F_151 ( struct V_21 * V_22 , enum V_37 V_37 )
{
if ( ! F_152 ( V_22 , V_37 ) )
return false ;
return true ;
}
static void F_153 ( struct V_21 * V_22 , T_1 V_192 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_269 [ V_270 ] = { } ;
int V_37 ;
F_78 ( & V_2 -> V_7 ) ;
F_154 (dev_priv, pipe) {
int V_3 ;
T_1 V_5 , V_271 = 0 ;
V_5 = V_46 ;
switch ( V_37 ) {
case V_55 :
V_271 = V_272 ;
break;
case V_53 :
V_271 = V_273 ;
break;
case V_274 :
V_271 = V_275 ;
break;
}
if ( V_192 & V_271 )
V_5 |= V_2 -> V_43 [ V_37 ] ;
if ( ! V_5 )
continue;
V_3 = F_40 ( V_37 ) ;
V_5 |= V_41 ;
V_269 [ V_37 ] = F_2 ( V_3 ) & V_5 ;
if ( V_269 [ V_37 ] & ( V_46 |
V_42 ) )
F_4 ( V_3 , V_269 [ V_37 ] ) ;
}
F_81 ( & V_2 -> V_7 ) ;
F_154 (dev_priv, pipe) {
if ( V_269 [ V_37 ] & V_276 &&
F_151 ( V_22 , V_37 ) )
F_155 ( V_22 , V_37 ) ;
if ( V_269 [ V_37 ] & V_277 ) {
F_156 ( V_22 , V_37 ) ;
F_157 ( V_22 , V_37 ) ;
}
if ( V_269 [ V_37 ] & V_278 )
F_144 ( V_22 , V_37 ) ;
if ( V_269 [ V_37 ] & V_46 )
F_158 ( V_2 , V_37 ) ;
}
if ( V_269 [ 0 ] & V_279 )
F_132 ( V_22 ) ;
}
static void F_159 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_280 = F_2 ( V_281 ) ;
T_1 V_241 = 0 , V_242 = 0 ;
if ( ! V_280 )
return;
F_4 ( V_281 , V_280 ) ;
F_5 ( V_281 ) ;
if ( F_69 ( V_22 ) || F_47 ( V_22 ) ) {
T_1 V_243 = V_280 & V_282 ;
if ( V_243 ) {
F_127 ( & V_241 , & V_242 , V_243 ,
V_243 , V_283 ,
F_126 ) ;
F_160 ( V_22 , V_241 , V_242 ) ;
}
if ( V_280 & V_284 )
F_133 ( V_22 ) ;
} else {
T_1 V_243 = V_280 & V_285 ;
if ( V_243 ) {
F_127 ( & V_241 , & V_242 , V_243 ,
V_243 , V_286 ,
F_126 ) ;
F_160 ( V_22 , V_241 , V_242 ) ;
}
}
}
static T_7 F_161 ( int V_32 , void * V_287 )
{
struct V_21 * V_22 = V_287 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_192 , V_196 , V_26 ;
T_7 V_96 = V_209 ;
if ( ! F_13 ( V_2 ) )
return V_209 ;
while ( true ) {
V_196 = F_2 ( V_288 ) ;
if ( V_196 )
F_4 ( V_288 , V_196 ) ;
V_26 = F_2 ( V_17 ) ;
if ( V_26 )
F_4 ( V_17 , V_26 ) ;
V_192 = F_2 ( V_289 ) ;
if ( V_192 ) {
if ( V_192 & V_290 )
F_159 ( V_22 ) ;
F_4 ( V_289 , V_192 ) ;
}
if ( V_196 == 0 && V_26 == 0 && V_192 == 0 )
goto V_180;
V_96 = V_213 ;
if ( V_196 )
F_115 ( V_22 , V_2 , V_196 ) ;
if ( V_26 )
F_120 ( V_2 , V_26 ) ;
F_153 ( V_22 , V_192 ) ;
}
V_180:
return V_96 ;
}
static T_7 F_162 ( int V_32 , void * V_287 )
{
struct V_21 * V_22 = V_287 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_208 , V_192 ;
T_7 V_96 = V_209 ;
if ( ! F_13 ( V_2 ) )
return V_209 ;
for (; ; ) {
V_208 = F_2 ( V_291 ) & ~ V_292 ;
V_192 = F_2 ( V_289 ) ;
if ( V_208 == 0 && V_192 == 0 )
break;
V_96 = V_213 ;
F_4 ( V_291 , 0 ) ;
if ( V_192 ) {
if ( V_192 & V_290 )
F_159 ( V_22 ) ;
F_4 ( V_289 , V_192 ) ;
}
F_116 ( V_2 , V_208 ) ;
F_153 ( V_22 , V_192 ) ;
F_4 ( V_291 , V_293 ) ;
F_5 ( V_291 ) ;
}
return V_96 ;
}
static void F_163 ( struct V_21 * V_22 , T_1 V_243 ,
const T_1 V_245 [ V_246 ] )
{
struct V_1 * V_2 = F_164 ( V_22 ) ;
T_1 V_244 , V_241 = 0 , V_242 = 0 ;
V_244 = F_2 ( V_294 ) ;
F_4 ( V_294 , V_244 ) ;
F_127 ( & V_241 , & V_242 , V_243 ,
V_244 , V_245 ,
F_125 ) ;
F_160 ( V_22 , V_241 , V_242 ) ;
}
static void F_165 ( struct V_21 * V_22 , T_1 V_295 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
T_1 V_243 = V_295 & V_296 ;
if ( V_243 )
F_163 ( V_22 , V_243 , V_297 ) ;
if ( V_295 & V_298 ) {
int V_226 = F_101 ( ( V_295 & V_298 ) >>
V_299 ) ;
F_66 ( L_22 ,
F_166 ( V_226 ) ) ;
}
if ( V_295 & V_300 )
F_133 ( V_22 ) ;
if ( V_295 & V_301 )
F_132 ( V_22 ) ;
if ( V_295 & V_302 )
F_66 ( L_23 ) ;
if ( V_295 & V_303 )
F_66 ( L_24 ) ;
if ( V_295 & V_304 )
F_73 ( L_25 ) ;
if ( V_295 & V_305 )
F_154 (dev_priv, pipe)
F_66 ( L_26 ,
F_42 ( V_37 ) ,
F_2 ( F_167 ( V_37 ) ) ) ;
if ( V_295 & ( V_306 | V_307 ) )
F_66 ( L_27 ) ;
if ( V_295 & ( V_308 | V_309 ) )
F_66 ( L_28 ) ;
if ( V_295 & V_310 )
F_168 ( V_2 , V_311 ) ;
if ( V_295 & V_312 )
F_168 ( V_2 , V_313 ) ;
}
static void F_169 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_314 = F_2 ( V_315 ) ;
enum V_37 V_37 ;
if ( V_314 & V_316 )
F_73 ( L_29 ) ;
F_154 (dev_priv, pipe) {
if ( V_314 & F_170 ( V_37 ) )
F_158 ( V_2 , V_37 ) ;
if ( V_314 & F_171 ( V_37 ) ) {
if ( F_172 ( V_22 ) )
F_139 ( V_22 , V_37 ) ;
else
F_137 ( V_22 , V_37 ) ;
}
}
F_4 ( V_315 , V_314 ) ;
}
static void F_173 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_317 = F_2 ( V_318 ) ;
if ( V_317 & V_319 )
F_73 ( L_25 ) ;
if ( V_317 & V_320 )
F_168 ( V_2 , V_311 ) ;
if ( V_317 & V_321 )
F_168 ( V_2 , V_313 ) ;
if ( V_317 & V_322 )
F_168 ( V_2 , V_323 ) ;
F_4 ( V_318 , V_317 ) ;
}
static void F_174 ( struct V_21 * V_22 , T_1 V_295 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
T_1 V_243 = V_295 & V_324 ;
if ( V_243 )
F_163 ( V_22 , V_243 , V_325 ) ;
if ( V_295 & V_326 ) {
int V_226 = F_101 ( ( V_295 & V_326 ) >>
V_327 ) ;
F_66 ( L_30 ,
F_166 ( V_226 ) ) ;
}
if ( V_295 & V_328 )
F_133 ( V_22 ) ;
if ( V_295 & V_329 )
F_132 ( V_22 ) ;
if ( V_295 & V_330 )
F_66 ( L_31 ) ;
if ( V_295 & V_331 )
F_66 ( L_32 ) ;
if ( V_295 & V_332 )
F_154 (dev_priv, pipe)
F_66 ( L_26 ,
F_42 ( V_37 ) ,
F_2 ( F_167 ( V_37 ) ) ) ;
if ( V_295 & V_333 )
F_173 ( V_22 ) ;
}
static void F_175 ( struct V_21 * V_22 , T_1 V_295 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_243 = V_295 & V_334 &
~ V_335 ;
T_1 V_336 = V_295 & V_335 ;
T_1 V_241 = 0 , V_242 = 0 ;
if ( V_243 ) {
T_1 V_244 ;
V_244 = F_2 ( V_294 ) ;
F_4 ( V_294 , V_244 ) ;
F_127 ( & V_241 , & V_242 , V_243 ,
V_244 , V_337 ,
F_123 ) ;
}
if ( V_336 ) {
T_1 V_244 ;
V_244 = F_2 ( V_338 ) ;
F_4 ( V_338 , V_244 ) ;
F_127 ( & V_241 , & V_242 , V_336 ,
V_244 , V_337 ,
F_122 ) ;
}
if ( V_241 )
F_160 ( V_22 , V_241 , V_242 ) ;
if ( V_295 & V_329 )
F_132 ( V_22 ) ;
}
static void F_176 ( struct V_21 * V_22 , T_1 V_243 ,
const T_1 V_245 [ V_246 ] )
{
struct V_1 * V_2 = F_164 ( V_22 ) ;
T_1 V_244 , V_241 = 0 , V_242 = 0 ;
V_244 = F_2 ( V_339 ) ;
F_4 ( V_339 , V_244 ) ;
F_127 ( & V_241 , & V_242 , V_243 ,
V_244 , V_245 ,
F_124 ) ;
F_160 ( V_22 , V_241 , V_242 ) ;
}
static void F_177 ( struct V_21 * V_22 , T_1 V_340 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
enum V_37 V_37 ;
T_1 V_243 = V_340 & V_341 ;
if ( V_243 )
F_176 ( V_22 , V_243 , V_342 ) ;
if ( V_340 & V_343 )
F_133 ( V_22 ) ;
if ( V_340 & V_344 )
F_178 ( V_22 ) ;
if ( V_340 & V_345 )
F_73 ( L_29 ) ;
F_154 (dev_priv, pipe) {
if ( V_340 & F_179 ( V_37 ) &&
F_151 ( V_22 , V_37 ) )
F_155 ( V_22 , V_37 ) ;
if ( V_340 & F_180 ( V_37 ) )
F_158 ( V_2 , V_37 ) ;
if ( V_340 & F_181 ( V_37 ) )
F_144 ( V_22 , V_37 ) ;
if ( V_340 & F_182 ( V_37 ) ) {
F_156 ( V_22 , V_37 ) ;
F_183 ( V_22 , V_37 ) ;
}
}
if ( V_340 & V_346 ) {
T_1 V_295 = F_2 ( V_347 ) ;
if ( F_184 ( V_22 ) )
F_174 ( V_22 , V_295 ) ;
else
F_165 ( V_22 , V_295 ) ;
F_4 ( V_347 , V_295 ) ;
}
if ( F_185 ( V_22 ) && V_340 & V_348 )
F_77 ( V_22 ) ;
}
static void F_186 ( struct V_21 * V_22 , T_1 V_340 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
enum V_37 V_37 ;
T_1 V_243 = V_340 & V_349 ;
if ( V_243 )
F_176 ( V_22 , V_243 , V_350 ) ;
if ( V_340 & V_351 )
F_169 ( V_22 ) ;
if ( V_340 & V_352 )
F_133 ( V_22 ) ;
if ( V_340 & V_353 )
F_178 ( V_22 ) ;
F_154 (dev_priv, pipe) {
if ( V_340 & ( F_187 ( V_37 ) ) &&
F_151 ( V_22 , V_37 ) )
F_155 ( V_22 , V_37 ) ;
if ( V_340 & F_188 ( V_37 ) ) {
F_156 ( V_22 , V_37 ) ;
F_183 ( V_22 , V_37 ) ;
}
}
if ( ! F_189 ( V_22 ) && ( V_340 & V_354 ) ) {
T_1 V_295 = F_2 ( V_347 ) ;
F_174 ( V_22 , V_295 ) ;
F_4 ( V_347 , V_295 ) ;
}
}
static T_7 F_190 ( int V_32 , void * V_287 )
{
struct V_21 * V_22 = V_287 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_340 , V_196 , V_355 , V_356 = 0 ;
T_7 V_96 = V_209 ;
if ( ! F_13 ( V_2 ) )
return V_209 ;
F_191 ( V_22 ) ;
V_355 = F_2 ( V_357 ) ;
F_4 ( V_357 , V_355 & ~ V_293 ) ;
F_5 ( V_357 ) ;
if ( ! F_189 ( V_22 ) ) {
V_356 = F_2 ( V_358 ) ;
F_4 ( V_358 , 0 ) ;
F_5 ( V_358 ) ;
}
V_196 = F_2 ( V_288 ) ;
if ( V_196 ) {
F_4 ( V_288 , V_196 ) ;
V_96 = V_213 ;
if ( F_20 ( V_22 ) -> V_16 >= 6 )
F_115 ( V_22 , V_2 , V_196 ) ;
else
F_114 ( V_22 , V_2 , V_196 ) ;
}
V_340 = F_2 ( V_359 ) ;
if ( V_340 ) {
F_4 ( V_359 , V_340 ) ;
V_96 = V_213 ;
if ( F_20 ( V_22 ) -> V_16 >= 7 )
F_186 ( V_22 , V_340 ) ;
else
F_177 ( V_22 , V_340 ) ;
}
if ( F_20 ( V_22 ) -> V_16 >= 6 ) {
T_1 V_26 = F_2 ( V_17 ) ;
if ( V_26 ) {
F_4 ( V_17 , V_26 ) ;
V_96 = V_213 ;
F_120 ( V_2 , V_26 ) ;
}
}
F_4 ( V_357 , V_355 ) ;
F_5 ( V_357 ) ;
if ( ! F_189 ( V_22 ) ) {
F_4 ( V_358 , V_356 ) ;
F_5 ( V_358 ) ;
}
return V_96 ;
}
static void F_192 ( struct V_21 * V_22 , T_1 V_243 ,
const T_1 V_245 [ V_246 ] )
{
struct V_1 * V_2 = F_164 ( V_22 ) ;
T_1 V_244 , V_241 = 0 , V_242 = 0 ;
V_244 = F_2 ( V_294 ) ;
F_4 ( V_294 , V_244 ) ;
F_127 ( & V_241 , & V_242 , V_243 ,
V_244 , V_245 ,
F_121 ) ;
F_160 ( V_22 , V_241 , V_242 ) ;
}
static T_7 F_193 ( int V_32 , void * V_287 )
{
struct V_21 * V_22 = V_287 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_208 ;
T_7 V_96 = V_209 ;
T_2 V_212 = 0 ;
enum V_37 V_37 ;
T_1 V_360 = V_361 ;
if ( ! F_13 ( V_2 ) )
return V_209 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_360 |= V_362 | V_363 |
V_364 ;
V_208 = F_117 ( V_291 ) ;
V_208 &= ~ V_292 ;
if ( ! V_208 )
return V_209 ;
F_118 ( V_291 , 0 ) ;
V_96 = F_116 ( V_2 , V_208 ) ;
if ( V_208 & V_365 ) {
V_212 = F_2 ( V_366 ) ;
if ( V_212 ) {
F_4 ( V_366 , V_212 ) ;
V_96 = V_213 ;
if ( V_212 & V_367 )
F_178 ( V_22 ) ;
else
F_73 ( L_33 ) ;
}
else
F_73 ( L_34 ) ;
}
if ( V_208 & V_368 ) {
V_212 = F_2 ( V_369 ) ;
if ( V_212 ) {
bool V_370 = false ;
T_1 V_243 = 0 ;
if ( F_194 ( V_2 ) )
V_243 = V_212 & V_371 ;
else if ( F_195 ( V_2 ) )
V_243 = V_212 & V_372 ;
F_4 ( V_369 , V_212 ) ;
V_96 = V_213 ;
if ( V_212 & V_360 ) {
F_133 ( V_22 ) ;
V_370 = true ;
}
if ( V_243 ) {
if ( F_194 ( V_22 ) )
F_192 ( V_22 , V_243 , V_373 ) ;
else
F_176 ( V_22 , V_243 , V_374 ) ;
V_370 = true ;
}
if ( F_194 ( V_22 ) && ( V_212 & V_375 ) ) {
F_132 ( V_22 ) ;
V_370 = true ;
}
if ( ! V_370 )
F_73 ( L_35 ) ;
}
else
F_73 ( L_36 ) ;
}
F_154 (dev_priv, pipe) {
T_2 V_376 , V_377 = 0 , V_378 = 0 ;
if ( ! ( V_208 & F_196 ( V_37 ) ) )
continue;
V_376 = F_2 ( F_197 ( V_37 ) ) ;
if ( V_376 ) {
V_96 = V_213 ;
F_4 ( F_197 ( V_37 ) , V_376 ) ;
if ( V_376 & V_379 &&
F_151 ( V_22 , V_37 ) )
F_155 ( V_22 , V_37 ) ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_377 = V_376 & V_380 ;
else
V_377 = V_376 & V_381 ;
if ( V_377 ) {
F_156 ( V_22 , V_37 ) ;
F_183 ( V_22 , V_37 ) ;
}
if ( V_376 & V_382 )
F_137 ( V_22 , V_37 ) ;
if ( V_376 & V_383 )
F_158 ( V_2 ,
V_37 ) ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_378 = V_376 & V_384 ;
else
V_378 = V_376 & V_385 ;
if ( V_378 )
F_73 ( L_37 ,
F_42 ( V_37 ) ,
V_376 & V_385 ) ;
} else
F_73 ( L_38 ) ;
}
if ( F_198 ( V_22 ) && ! F_189 ( V_22 ) &&
V_208 & V_386 ) {
T_1 V_295 = F_2 ( V_347 ) ;
if ( V_295 ) {
F_4 ( V_347 , V_295 ) ;
V_96 = V_213 ;
if ( F_199 ( V_2 ) )
F_175 ( V_22 , V_295 ) ;
else
F_174 ( V_22 , V_295 ) ;
} else
F_73 ( L_39 ) ;
}
F_118 ( V_291 , V_292 ) ;
F_200 ( V_291 ) ;
return V_96 ;
}
static void F_201 ( struct V_1 * V_2 ,
bool V_387 )
{
struct V_128 * V_129 ;
int V_86 ;
F_92 (ring, dev_priv, i)
F_85 ( & V_129 -> V_130 ) ;
F_85 ( & V_2 -> V_388 ) ;
if ( V_387 )
F_85 ( & V_2 -> V_389 . V_390 ) ;
}
static void F_202 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_164 ( V_22 ) ;
struct V_391 * error = & V_2 -> V_389 ;
char * V_392 [] = { V_393 L_7 , NULL } ;
char * V_394 [] = { V_395 L_7 , NULL } ;
char * V_396 [] = { V_393 L_40 , NULL } ;
int V_96 ;
F_107 ( & V_22 -> V_188 -> V_189 -> V_190 , V_191 , V_392 ) ;
if ( F_203 ( error ) && ! F_204 ( error ) ) {
F_66 ( L_41 ) ;
F_107 ( & V_22 -> V_188 -> V_189 -> V_190 , V_191 ,
V_394 ) ;
F_205 ( V_2 ) ;
F_206 ( V_22 ) ;
V_96 = F_207 ( V_22 ) ;
F_208 ( V_22 ) ;
F_209 ( V_2 ) ;
if ( V_96 == 0 ) {
F_210 () ;
F_211 ( & V_2 -> V_389 . V_397 ) ;
F_107 ( & V_22 -> V_188 -> V_189 -> V_190 ,
V_191 , V_396 ) ;
} else {
F_212 ( V_398 , & error -> V_397 ) ;
}
F_201 ( V_2 , true ) ;
}
}
static void F_213 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_399 [ V_400 ] ;
T_1 V_401 = F_2 ( V_402 ) ;
int V_37 , V_86 ;
if ( ! V_401 )
return;
F_214 ( L_42 , V_401 ) ;
F_215 ( V_22 , V_399 ) ;
if ( F_69 ( V_22 ) ) {
if ( V_401 & ( V_403 | V_404 ) ) {
T_1 V_405 = F_2 ( V_406 ) ;
F_214 ( L_43 , F_2 ( V_406 ) ) ;
F_214 ( L_44 , F_2 ( V_407 ) ) ;
for ( V_86 = 0 ; V_86 < F_216 ( V_399 ) ; V_86 ++ )
F_214 ( L_45 , V_86 , V_399 [ V_86 ] ) ;
F_214 ( L_46 , F_2 ( V_408 ) ) ;
F_214 ( L_47 , F_2 ( V_409 ) ) ;
F_4 ( V_406 , V_405 ) ;
F_5 ( V_406 ) ;
}
if ( V_401 & V_410 ) {
T_1 V_411 = F_2 ( V_412 ) ;
F_214 ( L_48 ) ;
F_214 ( L_49 , V_411 ) ;
F_4 ( V_412 , V_411 ) ;
F_5 ( V_412 ) ;
}
}
if ( ! F_60 ( V_22 ) ) {
if ( V_401 & V_413 ) {
T_1 V_411 = F_2 ( V_412 ) ;
F_214 ( L_48 ) ;
F_214 ( L_49 , V_411 ) ;
F_4 ( V_412 , V_411 ) ;
F_5 ( V_412 ) ;
}
}
if ( V_401 & V_414 ) {
F_214 ( L_50 ) ;
F_154 (dev_priv, pipe)
F_214 ( L_51 ,
F_42 ( V_37 ) , F_2 ( F_40 ( V_37 ) ) ) ;
}
if ( V_401 & V_415 ) {
F_214 ( L_52 ) ;
F_214 ( L_53 , F_2 ( V_416 ) ) ;
for ( V_86 = 0 ; V_86 < F_216 ( V_399 ) ; V_86 ++ )
F_214 ( L_45 , V_86 , V_399 [ V_86 ] ) ;
if ( F_20 ( V_22 ) -> V_16 < 4 ) {
T_1 V_405 = F_2 ( V_417 ) ;
F_214 ( L_43 , F_2 ( V_417 ) ) ;
F_214 ( L_44 , F_2 ( V_418 ) ) ;
F_214 ( L_47 , F_2 ( V_419 ) ) ;
F_4 ( V_417 , V_405 ) ;
F_5 ( V_417 ) ;
} else {
T_1 V_405 = F_2 ( V_406 ) ;
F_214 ( L_43 , F_2 ( V_406 ) ) ;
F_214 ( L_44 , F_2 ( V_407 ) ) ;
F_214 ( L_46 , F_2 ( V_408 ) ) ;
F_214 ( L_47 , F_2 ( V_409 ) ) ;
F_4 ( V_406 , V_405 ) ;
F_5 ( V_406 ) ;
}
}
F_4 ( V_402 , V_401 ) ;
F_5 ( V_402 ) ;
V_401 = F_2 ( V_402 ) ;
if ( V_401 ) {
F_73 ( L_54 , V_401 ) ;
F_4 ( V_420 , F_2 ( V_420 ) | V_401 ) ;
F_4 ( V_421 , V_422 ) ;
}
}
void F_217 ( struct V_21 * V_22 , bool V_423 ,
const char * V_424 , ... )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_8 args ;
char V_425 [ 80 ] ;
va_start ( args , V_424 ) ;
F_218 ( V_425 , sizeof( V_425 ) , V_424 , args ) ;
va_end ( args ) ;
F_219 ( V_22 , V_423 , V_425 ) ;
F_213 ( V_22 ) ;
if ( V_423 ) {
F_212 ( V_426 ,
& V_2 -> V_389 . V_397 ) ;
F_201 ( V_2 , false ) ;
}
F_202 ( V_22 ) ;
}
static int F_220 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_97 ;
F_67 ( & V_2 -> V_7 , V_97 ) ;
if ( F_20 ( V_22 ) -> V_16 >= 4 )
F_46 ( V_2 , V_37 ,
V_276 ) ;
else
F_46 ( V_2 , V_37 ,
V_427 ) ;
F_70 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static int F_221 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_97 ;
T_2 V_428 = ( F_20 ( V_22 ) -> V_16 >= 7 ) ? F_187 ( V_37 ) :
F_179 ( V_37 ) ;
F_67 ( & V_2 -> V_7 , V_97 ) ;
F_14 ( V_2 , V_428 ) ;
F_70 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static int F_222 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_97 ;
F_67 ( & V_2 -> V_7 , V_97 ) ;
F_46 ( V_2 , V_37 ,
V_276 ) ;
F_70 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static int F_223 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_97 ;
F_67 ( & V_2 -> V_7 , V_97 ) ;
V_2 -> V_429 [ V_37 ] &= ~ V_379 ;
F_4 ( F_224 ( V_37 ) , V_2 -> V_429 [ V_37 ] ) ;
F_5 ( F_224 ( V_37 ) ) ;
F_70 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static void F_225 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_97 ;
F_67 ( & V_2 -> V_7 , V_97 ) ;
F_48 ( V_2 , V_37 ,
V_427 |
V_276 ) ;
F_70 ( & V_2 -> V_7 , V_97 ) ;
}
static void F_226 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_97 ;
T_2 V_428 = ( F_20 ( V_22 ) -> V_16 >= 7 ) ? F_187 ( V_37 ) :
F_179 ( V_37 ) ;
F_67 ( & V_2 -> V_7 , V_97 ) ;
F_15 ( V_2 , V_428 ) ;
F_70 ( & V_2 -> V_7 , V_97 ) ;
}
static void F_227 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_97 ;
F_67 ( & V_2 -> V_7 , V_97 ) ;
F_48 ( V_2 , V_37 ,
V_276 ) ;
F_70 ( & V_2 -> V_7 , V_97 ) ;
}
static void F_228 ( struct V_21 * V_22 , unsigned int V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
unsigned long V_97 ;
F_67 ( & V_2 -> V_7 , V_97 ) ;
V_2 -> V_429 [ V_37 ] |= V_379 ;
F_4 ( F_224 ( V_37 ) , V_2 -> V_429 [ V_37 ] ) ;
F_5 ( F_224 ( V_37 ) ) ;
F_70 ( & V_2 -> V_7 , V_97 ) ;
}
static bool
F_229 ( struct V_128 * V_129 , T_1 V_430 )
{
return ( F_230 ( & V_129 -> V_431 ) ||
F_231 ( V_430 , V_129 -> V_432 ) ) ;
}
static bool
F_232 ( struct V_21 * V_22 , T_1 V_433 )
{
if ( F_20 ( V_22 ) -> V_16 >= 8 ) {
return ( V_433 >> 23 ) == 0x1c ;
} else {
V_433 &= ~ V_434 ;
return V_433 == ( V_435 | V_436 |
V_437 ) ;
}
}
static struct V_128 *
F_233 ( struct V_128 * V_129 , T_1 V_433 , T_5 V_438 )
{
struct V_1 * V_2 = V_129 -> V_22 -> V_23 ;
struct V_128 * V_439 ;
int V_86 ;
if ( F_20 ( V_2 -> V_22 ) -> V_16 >= 8 ) {
F_92 (signaller, dev_priv, i) {
if ( V_129 == V_439 )
continue;
if ( V_438 == V_439 -> V_440 . V_441 [ V_129 -> V_442 ] )
return V_439 ;
}
} else {
T_1 V_443 = V_433 & V_434 ;
F_92 (signaller, dev_priv, i) {
if( V_129 == V_439 )
continue;
if ( V_443 == V_439 -> V_440 . V_444 . V_445 [ V_129 -> V_442 ] )
return V_439 ;
}
}
F_73 ( L_55 ,
V_129 -> V_442 , V_433 , V_438 ) ;
return NULL ;
}
static struct V_128 *
F_234 ( struct V_128 * V_129 , T_1 * V_430 )
{
struct V_1 * V_2 = V_129 -> V_22 -> V_23 ;
T_1 V_446 , V_433 , V_257 ;
T_5 V_438 = 0 ;
int V_86 , V_447 ;
if ( V_129 -> V_448 == NULL )
return NULL ;
V_433 = F_2 ( F_235 ( V_129 -> V_449 ) ) ;
if ( ! F_232 ( V_129 -> V_22 , V_433 ) )
return NULL ;
V_257 = F_236 ( V_129 ) & V_450 ;
V_447 = ( F_20 ( V_129 -> V_22 ) -> V_16 >= 8 ) ? 5 : 4 ;
for ( V_86 = V_447 ; V_86 ; -- V_86 ) {
V_257 &= V_129 -> V_448 -> V_451 - 1 ;
V_446 = F_237 ( V_129 -> V_448 -> V_452 + V_257 ) ;
if ( V_446 == V_433 )
break;
V_257 -= 4 ;
}
if ( ! V_86 )
return NULL ;
* V_430 = F_237 ( V_129 -> V_448 -> V_452 + V_257 + 4 ) + 1 ;
if ( F_20 ( V_129 -> V_22 ) -> V_16 >= 8 ) {
V_438 = F_237 ( V_129 -> V_448 -> V_452 + V_257 + 12 ) ;
V_438 <<= 32 ;
V_438 = F_237 ( V_129 -> V_448 -> V_452 + V_257 + 8 ) ;
}
return F_233 ( V_129 , V_433 , V_438 ) ;
}
static int F_238 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_22 -> V_23 ;
struct V_128 * V_439 ;
T_1 V_430 ;
V_129 -> V_453 . V_454 ++ ;
V_439 = F_234 ( V_129 , & V_430 ) ;
if ( V_439 == NULL )
return - 1 ;
if ( V_439 -> V_453 . V_454 >= V_455 )
return - 1 ;
if ( F_231 ( V_439 -> V_456 ( V_439 , false ) , V_430 ) )
return 1 ;
if ( F_239 ( V_439 ) & V_457 &&
F_238 ( V_439 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
int V_86 ;
F_92 (ring, dev_priv, i)
V_129 -> V_453 . V_454 = 0 ;
}
static enum V_458
F_241 ( struct V_128 * V_129 , T_5 V_459 )
{
struct V_21 * V_22 = V_129 -> V_22 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_212 ;
if ( V_459 != V_129 -> V_453 . V_459 ) {
if ( V_459 > V_129 -> V_453 . V_460 ) {
V_129 -> V_453 . V_460 = V_459 ;
return V_461 ;
}
return V_462 ;
}
if ( F_60 ( V_22 ) )
return V_463 ;
V_212 = F_239 ( V_129 ) ;
if ( V_212 & V_464 ) {
F_217 ( V_22 , false ,
L_56 ,
V_129 -> V_465 ) ;
F_242 ( V_129 , V_212 ) ;
return V_466 ;
}
if ( F_20 ( V_22 ) -> V_16 >= 6 && V_212 & V_457 ) {
switch ( F_238 ( V_129 ) ) {
default:
return V_463 ;
case 1 :
F_217 ( V_22 , false ,
L_57 ,
V_129 -> V_465 ) ;
F_242 ( V_129 , V_212 ) ;
return V_466 ;
case 0 :
return V_467 ;
}
}
return V_463 ;
}
static void F_243 ( struct V_157 * V_30 )
{
struct V_1 * V_2 =
F_94 ( V_30 , F_244 ( * V_2 ) ,
V_389 . V_468 . V_30 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_128 * V_129 ;
int V_86 ;
int V_469 = 0 , V_470 = 0 ;
bool V_471 [ V_455 ] = { 0 } ;
#define F_245 1
#define F_246 5
#define F_247 20
if ( ! V_472 . V_473 )
return;
F_92 (ring, dev_priv, i) {
T_5 V_459 ;
T_1 V_430 ;
bool V_474 = true ;
F_240 ( V_2 ) ;
V_430 = V_129 -> V_456 ( V_129 , false ) ;
V_459 = F_248 ( V_129 ) ;
if ( V_129 -> V_453 . V_430 == V_430 ) {
if ( F_229 ( V_129 , V_430 ) ) {
V_129 -> V_453 . V_475 = V_476 ;
if ( F_249 ( & V_129 -> V_130 ) ) {
if ( ! F_250 ( V_129 -> V_442 , & V_2 -> V_389 . V_477 ) ) {
if ( ! ( V_2 -> V_389 . V_478 & F_251 ( V_129 ) ) )
F_73 ( L_58 ,
V_129 -> V_465 ) ;
else
F_252 ( L_59 ,
V_129 -> V_465 ) ;
F_85 ( & V_129 -> V_130 ) ;
}
V_129 -> V_453 . V_479 += F_245 ;
} else
V_474 = false ;
} else {
V_129 -> V_453 . V_475 = F_241 ( V_129 ,
V_459 ) ;
switch ( V_129 -> V_453 . V_475 ) {
case V_476 :
case V_467 :
case V_461 :
break;
case V_462 :
V_129 -> V_453 . V_479 += F_245 ;
break;
case V_466 :
V_129 -> V_453 . V_479 += F_246 ;
break;
case V_463 :
V_129 -> V_453 . V_479 += F_247 ;
V_471 [ V_86 ] = true ;
break;
}
}
} else {
V_129 -> V_453 . V_475 = V_461 ;
if ( V_129 -> V_453 . V_479 > 0 )
V_129 -> V_453 . V_479 -- ;
V_129 -> V_453 . V_459 = V_129 -> V_453 . V_460 = 0 ;
}
V_129 -> V_453 . V_430 = V_430 ;
V_129 -> V_453 . V_459 = V_459 ;
V_469 += V_474 ;
}
F_92 (ring, dev_priv, i) {
if ( V_129 -> V_453 . V_479 >= V_480 ) {
F_252 ( L_60 ,
V_471 [ V_86 ] ? L_61 : L_62 ,
V_129 -> V_465 ) ;
V_470 ++ ;
}
}
if ( V_470 )
return F_217 ( V_22 , true , L_63 ) ;
if ( V_469 )
F_253 ( V_22 ) ;
}
void F_253 ( struct V_21 * V_22 )
{
struct V_391 * V_481 = & F_164 ( V_22 ) -> V_389 ;
if ( ! V_472 . V_473 )
return;
F_254 ( V_481 -> V_482 , & V_481 -> V_468 ,
F_255 ( V_483 ) ) ;
}
static void F_256 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( F_189 ( V_22 ) )
return;
F_257 ( V_484 ) ;
if ( F_184 ( V_22 ) || F_258 ( V_22 ) )
F_4 ( V_318 , 0xffffffff ) ;
}
static void F_259 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( F_189 ( V_22 ) )
return;
F_8 ( F_2 ( V_358 ) != 0 ) ;
F_4 ( V_358 , 0xffffffff ) ;
F_5 ( V_358 ) ;
}
static void F_260 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_257 ( V_485 ) ;
if ( F_20 ( V_22 ) -> V_16 >= 6 )
F_257 ( V_486 ) ;
}
static void F_261 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_4 ( V_487 , 0xffffffff ) ;
F_257 ( V_488 ) ;
if ( F_262 ( V_22 ) )
F_4 ( V_315 , 0xffffffff ) ;
F_260 ( V_22 ) ;
F_256 ( V_22 ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
enum V_37 V_37 ;
F_9 ( V_2 , 0xFFFFFFFF , 0 ) ;
F_4 ( V_281 , F_2 ( V_281 ) ) ;
F_154 (dev_priv, pipe)
F_4 ( F_40 ( V_37 ) , 0xffff ) ;
F_257 ( V_489 ) ;
}
static void F_264 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_4 ( V_490 , 0 ) ;
F_4 ( F_265 ( V_491 ) , 0 ) ;
F_4 ( F_265 ( V_492 ) , 0 ) ;
F_4 ( F_265 ( V_493 ) , 0 ) ;
F_260 ( V_22 ) ;
F_4 ( V_494 , V_495 ) ;
F_263 ( V_2 ) ;
}
static void F_266 ( struct V_1 * V_2 )
{
F_267 ( V_485 , 0 ) ;
F_267 ( V_485 , 1 ) ;
F_267 ( V_485 , 2 ) ;
F_267 ( V_485 , 3 ) ;
}
static void F_268 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
F_4 ( V_291 , 0 ) ;
F_5 ( V_291 ) ;
F_266 ( V_2 ) ;
F_154 (dev_priv, pipe)
if ( F_269 ( V_2 ,
F_270 ( V_37 ) ) )
F_267 ( V_496 , V_37 ) ;
F_257 ( V_497 ) ;
F_257 ( V_498 ) ;
F_257 ( V_499 ) ;
if ( F_198 ( V_22 ) )
F_256 ( V_22 ) ;
}
void F_271 ( struct V_1 * V_2 ,
unsigned int V_500 )
{
T_2 V_501 = V_379 | V_383 ;
F_10 ( & V_2 -> V_7 ) ;
if ( V_500 & 1 << V_55 )
F_272 ( V_496 , V_55 ,
V_2 -> V_429 [ V_55 ] ,
~ V_2 -> V_429 [ V_55 ] | V_501 ) ;
if ( V_500 & 1 << V_53 )
F_272 ( V_496 , V_53 ,
V_2 -> V_429 [ V_53 ] ,
~ V_2 -> V_429 [ V_53 ] | V_501 ) ;
if ( V_500 & 1 << V_274 )
F_272 ( V_496 , V_274 ,
V_2 -> V_429 [ V_274 ] ,
~ V_2 -> V_429 [ V_274 ] | V_501 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
static void F_273 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_4 ( V_291 , 0 ) ;
F_5 ( V_291 ) ;
F_266 ( V_2 ) ;
F_257 ( V_499 ) ;
F_4 ( V_494 , V_502 ) ;
F_263 ( V_2 ) ;
}
static T_1 F_274 ( struct V_21 * V_22 ,
const T_1 V_245 [ V_246 ] )
{
struct V_1 * V_2 = F_164 ( V_22 ) ;
struct V_503 * V_504 ;
T_1 V_505 = 0 ;
F_275 (dev, encoder)
if ( V_2 -> V_506 . V_507 [ V_504 -> V_508 ] . V_509 == V_510 )
V_505 |= V_245 [ V_504 -> V_508 ] ;
return V_505 ;
}
static void F_276 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_511 , V_506 , V_505 ;
if ( F_277 ( V_22 ) ) {
V_511 = V_296 ;
V_505 = F_274 ( V_22 , V_297 ) ;
} else {
V_511 = V_324 ;
V_505 = F_274 ( V_22 , V_325 ) ;
}
F_38 ( V_2 , V_511 , V_505 ) ;
V_506 = F_2 ( V_294 ) ;
V_506 &= ~ ( V_512 | V_513 | V_514 ) ;
V_506 |= V_515 | V_516 ;
V_506 |= V_517 | V_518 ;
V_506 |= V_519 | V_520 ;
if ( F_278 ( V_22 ) )
V_506 |= V_521 ;
F_4 ( V_294 , V_506 ) ;
}
static void F_279 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_511 , V_506 , V_505 ;
V_511 = V_334 ;
V_505 = F_274 ( V_22 , V_337 ) ;
F_38 ( V_2 , V_511 , V_505 ) ;
V_506 = F_2 ( V_294 ) ;
V_506 |= V_515 | V_517 |
V_519 | V_521 ;
F_4 ( V_294 , V_506 ) ;
V_506 = F_2 ( V_338 ) ;
V_506 |= V_522 ;
F_4 ( V_338 , V_506 ) ;
}
static void F_280 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_511 , V_506 , V_505 ;
if ( F_20 ( V_22 ) -> V_16 >= 8 ) {
V_511 = V_372 ;
V_505 = F_274 ( V_22 , V_374 ) ;
F_37 ( V_2 , V_511 , V_505 ) ;
} else if ( F_20 ( V_22 ) -> V_16 >= 7 ) {
V_511 = V_349 ;
V_505 = F_274 ( V_22 , V_350 ) ;
F_12 ( V_2 , V_511 , V_505 ) ;
} else {
V_511 = V_341 ;
V_505 = F_274 ( V_22 , V_342 ) ;
F_12 ( V_2 , V_511 , V_505 ) ;
}
V_506 = F_2 ( V_339 ) ;
V_506 &= ~ V_523 ;
V_506 |= V_524 | V_525 ;
F_4 ( V_339 , V_506 ) ;
F_276 ( V_22 ) ;
}
static void F_281 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_511 , V_506 , V_505 ;
V_505 = F_274 ( V_22 , V_373 ) ;
V_511 = V_371 ;
F_37 ( V_2 , V_511 , V_505 ) ;
V_506 = F_2 ( V_294 ) ;
V_506 |= V_517 | V_519 |
V_521 ;
F_4 ( V_294 , V_506 ) ;
}
static void F_282 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_5 ;
if ( F_189 ( V_22 ) )
return;
if ( F_277 ( V_22 ) )
V_5 = V_301 | V_300 | V_304 ;
else
V_5 = V_329 | V_328 ;
F_1 ( V_2 , V_347 ) ;
F_4 ( V_36 , ~ V_5 ) ;
}
static void F_283 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_526 , V_527 ;
V_526 = V_527 = 0 ;
V_2 -> V_14 = ~ 0 ;
if ( F_112 ( V_22 ) ) {
V_2 -> V_14 = ~ F_110 ( V_22 ) ;
V_527 |= F_110 ( V_22 ) ;
}
V_527 |= V_197 ;
if ( F_185 ( V_22 ) ) {
V_527 |= V_198 |
V_200 ;
} else {
V_527 |= V_203 | V_202 ;
}
F_284 ( V_485 , V_2 -> V_14 , V_527 ) ;
if ( F_20 ( V_22 ) -> V_16 >= 6 ) {
if ( F_150 ( V_22 ) )
V_526 |= V_267 ;
V_2 -> V_20 = 0xffffffff ;
F_284 ( V_486 , V_2 -> V_20 , V_526 ) ;
}
}
static int F_285 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_528 , V_529 ;
if ( F_20 ( V_22 ) -> V_16 >= 7 ) {
V_528 = ( V_293 | V_353 |
V_354 | V_530 |
V_531 |
V_532 | V_352 ) ;
V_529 = ( V_533 | V_534 |
V_535 | V_351 |
V_349 ) ;
} else {
V_528 = ( V_293 | V_344 | V_346 |
V_536 | V_537 |
V_343 |
V_538 | V_539 |
V_345 ) ;
V_529 = ( V_540 | V_541 | V_348 |
V_542 | V_543 |
V_341 ) ;
}
V_2 -> V_12 = ~ V_528 ;
F_4 ( V_487 , 0xeffe ) ;
F_259 ( V_22 ) ;
F_284 ( V_488 , V_2 -> V_12 , V_528 | V_529 ) ;
F_283 ( V_22 ) ;
F_282 ( V_22 ) ;
if ( F_286 ( V_22 ) ) {
F_10 ( & V_2 -> V_7 ) ;
F_14 ( V_2 , V_348 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
return 0 ;
}
static void F_287 ( struct V_1 * V_2 )
{
T_1 V_544 ;
T_1 V_545 ;
enum V_37 V_37 ;
V_544 = V_42 |
V_46 ;
F_154 (dev_priv, pipe)
F_4 ( F_40 ( V_37 ) , V_544 ) ;
F_5 ( F_40 ( V_55 ) ) ;
V_544 = V_277 |
V_278 ;
F_46 ( V_2 , V_55 , V_279 ) ;
F_154 (dev_priv, pipe)
F_46 ( V_2 , V_37 , V_544 ) ;
V_545 = V_290 |
V_272 |
V_273 ;
if ( F_96 ( V_2 ) )
V_545 |= V_275 ;
V_2 -> V_12 &= ~ V_545 ;
F_4 ( V_289 , V_545 ) ;
F_4 ( V_289 , V_545 ) ;
F_4 ( V_546 , ~ V_2 -> V_12 ) ;
F_4 ( V_490 , V_2 -> V_12 ) ;
F_5 ( V_490 ) ;
}
static void F_288 ( struct V_1 * V_2 )
{
T_1 V_544 ;
T_1 V_545 ;
enum V_37 V_37 ;
V_545 = V_290 |
V_272 |
V_273 ;
if ( F_96 ( V_2 ) )
V_545 |= V_275 ;
V_2 -> V_12 |= V_545 ;
F_4 ( V_490 , V_2 -> V_12 ) ;
F_4 ( V_546 , ~ V_2 -> V_12 ) ;
F_4 ( V_289 , V_545 ) ;
F_4 ( V_289 , V_545 ) ;
F_5 ( V_289 ) ;
V_544 = V_277 |
V_278 ;
F_48 ( V_2 , V_55 , V_279 ) ;
F_154 (dev_priv, pipe)
F_48 ( V_2 , V_37 , V_544 ) ;
V_544 = V_42 |
V_46 ;
F_154 (dev_priv, pipe)
F_4 ( F_40 ( V_37 ) , V_544 ) ;
F_5 ( F_40 ( V_55 ) ) ;
}
void F_289 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_547 )
return;
V_2 -> V_547 = true ;
if ( F_13 ( V_2 ) )
F_287 ( V_2 ) ;
}
void F_290 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_547 )
return;
V_2 -> V_547 = false ;
if ( F_13 ( V_2 ) )
F_288 ( V_2 ) ;
}
static void F_291 ( struct V_1 * V_2 )
{
V_2 -> V_12 = ~ 0 ;
F_9 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_8 ) ;
F_4 ( V_289 , 0xffffffff ) ;
F_4 ( V_289 , 0xffffffff ) ;
F_4 ( V_546 , ~ V_2 -> V_12 ) ;
F_4 ( V_490 , V_2 -> V_12 ) ;
F_5 ( V_490 ) ;
F_10 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_547 )
F_287 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
static int F_292 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_291 ( V_2 ) ;
F_283 ( V_22 ) ;
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
F_4 ( V_548 , V_549 ) ;
return 0 ;
}
static void F_293 ( struct V_1 * V_2 )
{
T_2 V_550 [] = {
V_197 << V_215 |
V_214 << V_215 |
V_194 |
V_197 << V_216 |
V_214 << V_216 ,
V_197 << V_219 |
V_214 << V_219 |
V_197 << V_220 |
V_214 << V_220 ,
0 ,
V_197 << V_223 |
V_214 << V_223
} ;
V_2 -> V_20 = 0xffffffff ;
F_272 ( V_485 , 0 , ~ V_550 [ 0 ] , V_550 [ 0 ] ) ;
F_272 ( V_485 , 1 , ~ V_550 [ 1 ] , V_550 [ 1 ] ) ;
F_272 ( V_485 , 2 , V_2 -> V_20 , 0 ) ;
F_272 ( V_485 , 3 , ~ V_550 [ 3 ] , V_550 [ 3 ] ) ;
}
static void F_294 ( struct V_1 * V_2 )
{
T_2 V_551 = V_382 ;
T_2 V_552 ;
T_1 V_553 = V_361 ;
T_1 V_554 ;
enum V_37 V_37 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 ) {
V_551 |= V_380 |
V_384 ;
V_553 |= V_362 | V_363 |
V_364 ;
if ( F_194 ( V_2 ) )
V_553 |= V_375 ;
} else {
V_551 |= V_381 |
V_385 ;
}
V_552 = V_551 | V_379 |
V_383 ;
V_554 = V_553 ;
if ( F_194 ( V_2 ) )
V_554 |= V_371 ;
else if ( F_195 ( V_2 ) )
V_554 |= V_372 ;
V_2 -> V_429 [ V_55 ] = ~ V_551 ;
V_2 -> V_429 [ V_53 ] = ~ V_551 ;
V_2 -> V_429 [ V_274 ] = ~ V_551 ;
F_154 (dev_priv, pipe)
if ( F_269 ( V_2 ,
F_270 ( V_37 ) ) )
F_272 ( V_496 , V_37 ,
V_2 -> V_429 [ V_37 ] ,
V_552 ) ;
F_284 ( V_497 , ~ V_553 , V_554 ) ;
}
static int F_295 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( F_198 ( V_22 ) )
F_259 ( V_22 ) ;
F_293 ( V_2 ) ;
F_294 ( V_2 ) ;
if ( F_198 ( V_22 ) )
F_282 ( V_22 ) ;
F_4 ( V_291 , V_293 ) ;
F_5 ( V_291 ) ;
return 0 ;
}
static int F_296 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_291 ( V_2 ) ;
F_293 ( V_2 ) ;
F_4 ( V_291 , V_549 ) ;
F_5 ( V_291 ) ;
return 0 ;
}
static void F_297 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 )
return;
F_268 ( V_22 ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_547 )
F_288 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_263 ( V_2 ) ;
V_2 -> V_12 = ~ 0 ;
}
static void F_299 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 )
return;
F_4 ( V_548 , 0 ) ;
F_260 ( V_22 ) ;
F_4 ( V_487 , 0xffffffff ) ;
F_298 ( V_2 ) ;
}
static void F_300 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 )
return;
F_4 ( V_291 , 0 ) ;
F_5 ( V_291 ) ;
F_266 ( V_2 ) ;
F_257 ( V_499 ) ;
F_298 ( V_2 ) ;
}
static void F_301 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
if ( ! V_2 )
return;
F_261 ( V_22 ) ;
}
static void F_302 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
F_154 (dev_priv, pipe)
F_4 ( F_40 ( V_37 ) , 0 ) ;
F_79 ( V_555 , 0xffff ) ;
F_79 ( V_556 , 0x0 ) ;
F_303 ( V_556 ) ;
}
static int F_304 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_79 ( V_420 ,
~ ( V_413 | V_414 ) ) ;
V_2 -> V_12 =
~ ( V_272 |
V_273 |
V_557 |
V_558 ) ;
F_79 ( V_555 , V_2 -> V_12 ) ;
F_79 ( V_556 ,
V_272 |
V_273 |
V_559 ) ;
F_303 ( V_556 ) ;
F_10 ( & V_2 -> V_7 ) ;
F_46 ( V_2 , V_55 , V_278 ) ;
F_46 ( V_2 , V_53 , V_278 ) ;
F_11 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_305 ( struct V_21 * V_22 ,
int V_560 , int V_37 , T_1 V_192 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_9 V_561 = F_306 ( V_560 ) ;
if ( ! F_151 ( V_22 , V_37 ) )
return false ;
if ( ( V_192 & V_561 ) == 0 )
goto V_562;
if ( F_307 ( V_563 ) & V_561 )
goto V_562;
F_156 ( V_22 , V_560 ) ;
F_157 ( V_22 , V_37 ) ;
return true ;
V_562:
F_155 ( V_22 , V_37 ) ;
return false ;
}
static T_7 F_308 ( int V_32 , void * V_287 )
{
struct V_21 * V_22 = V_287 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_9 V_192 , V_564 ;
T_1 V_269 [ 2 ] ;
int V_37 ;
T_9 V_565 =
V_557 |
V_558 ;
if ( ! F_13 ( V_2 ) )
return V_209 ;
V_192 = F_307 ( V_421 ) ;
if ( V_192 == 0 )
return V_209 ;
while ( V_192 & ~ V_565 ) {
F_78 ( & V_2 -> V_7 ) ;
if ( V_192 & V_422 )
F_108 ( L_64 , V_192 ) ;
F_154 (dev_priv, pipe) {
int V_3 = F_40 ( V_37 ) ;
V_269 [ V_37 ] = F_2 ( V_3 ) ;
if ( V_269 [ V_37 ] & 0x8000ffff )
F_4 ( V_3 , V_269 [ V_37 ] ) ;
}
F_81 ( & V_2 -> V_7 ) ;
F_79 ( V_421 , V_192 & ~ V_565 ) ;
V_564 = F_307 ( V_421 ) ;
if ( V_192 & V_559 )
F_82 ( & V_2 -> V_129 [ V_199 ] ) ;
F_154 (dev_priv, pipe) {
int V_560 = V_37 ;
if ( F_309 ( V_22 ) )
V_560 = ! V_560 ;
if ( V_269 [ V_37 ] & V_427 &&
F_305 ( V_22 , V_560 , V_37 , V_192 ) )
V_565 &= ~ F_306 ( V_560 ) ;
if ( V_269 [ V_37 ] & V_278 )
F_144 ( V_22 , V_37 ) ;
if ( V_269 [ V_37 ] & V_46 )
F_158 ( V_2 ,
V_37 ) ;
}
V_192 = V_564 ;
}
return V_213 ;
}
static void F_310 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
F_154 (dev_priv, pipe) {
F_4 ( F_40 ( V_37 ) , 0 ) ;
F_4 ( F_40 ( V_37 ) , F_2 ( F_40 ( V_37 ) ) ) ;
}
F_79 ( V_555 , 0xffff ) ;
F_79 ( V_556 , 0x0 ) ;
F_79 ( V_421 , F_307 ( V_421 ) ) ;
}
static void F_311 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
if ( F_312 ( V_22 ) ) {
F_9 ( V_2 , 0xffffffff , 0 ) ;
F_4 ( V_281 , F_2 ( V_281 ) ) ;
}
F_79 ( V_487 , 0xeffe ) ;
F_154 (dev_priv, pipe)
F_4 ( F_40 ( V_37 ) , 0 ) ;
F_4 ( V_555 , 0xffffffff ) ;
F_4 ( V_556 , 0x0 ) ;
F_5 ( V_556 ) ;
}
static int F_313 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_38 ;
F_4 ( V_420 , ~ ( V_413 | V_414 ) ) ;
V_2 -> V_12 =
~ ( V_566 |
V_272 |
V_273 |
V_557 |
V_558 ) ;
V_38 =
V_566 |
V_272 |
V_273 |
V_559 ;
if ( F_312 ( V_22 ) ) {
F_9 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_8 ) ;
V_38 |= V_290 ;
V_2 -> V_12 &= ~ V_290 ;
}
F_4 ( V_555 , V_2 -> V_12 ) ;
F_4 ( V_556 , V_38 ) ;
F_5 ( V_556 ) ;
F_49 ( V_22 ) ;
F_10 ( & V_2 -> V_7 ) ;
F_46 ( V_2 , V_55 , V_278 ) ;
F_46 ( V_2 , V_53 , V_278 ) ;
F_11 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_314 ( struct V_21 * V_22 ,
int V_560 , int V_37 , T_1 V_192 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_561 = F_306 ( V_560 ) ;
if ( ! F_151 ( V_22 , V_37 ) )
return false ;
if ( ( V_192 & V_561 ) == 0 )
goto V_562;
if ( F_2 ( V_563 ) & V_561 )
goto V_562;
F_156 ( V_22 , V_560 ) ;
F_157 ( V_22 , V_37 ) ;
return true ;
V_562:
F_155 ( V_22 , V_37 ) ;
return false ;
}
static T_7 F_315 ( int V_32 , void * V_287 )
{
struct V_21 * V_22 = V_287 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_192 , V_564 , V_269 [ V_270 ] ;
T_1 V_565 =
V_557 |
V_558 ;
int V_37 , V_96 = V_209 ;
if ( ! F_13 ( V_2 ) )
return V_209 ;
V_192 = F_2 ( V_421 ) ;
do {
bool V_567 = ( V_192 & ~ V_565 ) != 0 ;
bool V_568 = false ;
F_78 ( & V_2 -> V_7 ) ;
if ( V_192 & V_422 )
F_108 ( L_64 , V_192 ) ;
F_154 (dev_priv, pipe) {
int V_3 = F_40 ( V_37 ) ;
V_269 [ V_37 ] = F_2 ( V_3 ) ;
if ( V_269 [ V_37 ] & 0x8000ffff ) {
F_4 ( V_3 , V_269 [ V_37 ] ) ;
V_567 = true ;
}
}
F_81 ( & V_2 -> V_7 ) ;
if ( ! V_567 )
break;
if ( F_312 ( V_22 ) &&
V_192 & V_290 )
F_159 ( V_22 ) ;
F_4 ( V_421 , V_192 & ~ V_565 ) ;
V_564 = F_2 ( V_421 ) ;
if ( V_192 & V_559 )
F_82 ( & V_2 -> V_129 [ V_199 ] ) ;
F_154 (dev_priv, pipe) {
int V_560 = V_37 ;
if ( F_309 ( V_22 ) )
V_560 = ! V_560 ;
if ( V_269 [ V_37 ] & V_427 &&
F_314 ( V_22 , V_560 , V_37 , V_192 ) )
V_565 &= ~ F_306 ( V_560 ) ;
if ( V_269 [ V_37 ] & V_54 )
V_568 = true ;
if ( V_269 [ V_37 ] & V_278 )
F_144 ( V_22 , V_37 ) ;
if ( V_269 [ V_37 ] & V_46 )
F_158 ( V_2 ,
V_37 ) ;
}
if ( V_568 || ( V_192 & V_566 ) )
F_178 ( V_22 ) ;
V_96 = V_213 ;
V_192 = V_564 ;
} while ( V_192 & ~ V_565 );
return V_96 ;
}
static void F_316 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
if ( F_312 ( V_22 ) ) {
F_9 ( V_2 , 0xffffffff , 0 ) ;
F_4 ( V_281 , F_2 ( V_281 ) ) ;
}
F_79 ( V_487 , 0xffff ) ;
F_154 (dev_priv, pipe) {
F_4 ( F_40 ( V_37 ) , 0 ) ;
F_4 ( F_40 ( V_37 ) , F_2 ( F_40 ( V_37 ) ) ) ;
}
F_4 ( V_555 , 0xffffffff ) ;
F_4 ( V_556 , 0x0 ) ;
F_4 ( V_421 , F_2 ( V_421 ) ) ;
}
static void F_317 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
F_9 ( V_2 , 0xffffffff , 0 ) ;
F_4 ( V_281 , F_2 ( V_281 ) ) ;
F_4 ( V_487 , 0xeffe ) ;
F_154 (dev_priv, pipe)
F_4 ( F_40 ( V_37 ) , 0 ) ;
F_4 ( V_555 , 0xffffffff ) ;
F_4 ( V_556 , 0x0 ) ;
F_5 ( V_556 ) ;
}
static int F_318 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_38 ;
T_1 V_569 ;
V_2 -> V_12 = ~ ( V_566 |
V_290 |
V_272 |
V_273 |
V_557 |
V_558 |
V_422 ) ;
V_38 = ~ V_2 -> V_12 ;
V_38 &= ~ ( V_557 |
V_558 ) ;
V_38 |= V_559 ;
if ( F_69 ( V_22 ) )
V_38 |= V_570 ;
F_10 ( & V_2 -> V_7 ) ;
F_46 ( V_2 , V_55 , V_279 ) ;
F_46 ( V_2 , V_55 , V_278 ) ;
F_46 ( V_2 , V_53 , V_278 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( F_69 ( V_22 ) ) {
V_569 = ~ ( V_410 |
V_403 |
V_404 |
V_414 ) ;
} else {
V_569 = ~ ( V_413 |
V_414 ) ;
}
F_4 ( V_420 , V_569 ) ;
F_4 ( V_555 , V_2 -> V_12 ) ;
F_4 ( V_556 , V_38 ) ;
F_5 ( V_556 ) ;
F_9 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_8 ) ;
F_49 ( V_22 ) ;
return 0 ;
}
static void F_319 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_571 ;
F_7 ( & V_2 -> V_7 ) ;
V_571 = F_274 ( V_22 , V_572 ) ;
if ( F_69 ( V_22 ) )
V_571 |= V_573 ;
V_571 |= V_574 ;
F_6 ( V_2 ,
V_575 |
V_576 |
V_573 ,
V_571 ) ;
}
static T_7 F_320 ( int V_32 , void * V_287 )
{
struct V_21 * V_22 = V_287 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_192 , V_564 ;
T_1 V_269 [ V_270 ] ;
int V_96 = V_209 , V_37 ;
T_1 V_565 =
V_557 |
V_558 ;
if ( ! F_13 ( V_2 ) )
return V_209 ;
V_192 = F_2 ( V_421 ) ;
for (; ; ) {
bool V_567 = ( V_192 & ~ V_565 ) != 0 ;
bool V_568 = false ;
F_78 ( & V_2 -> V_7 ) ;
if ( V_192 & V_422 )
F_108 ( L_64 , V_192 ) ;
F_154 (dev_priv, pipe) {
int V_3 = F_40 ( V_37 ) ;
V_269 [ V_37 ] = F_2 ( V_3 ) ;
if ( V_269 [ V_37 ] & 0x8000ffff ) {
F_4 ( V_3 , V_269 [ V_37 ] ) ;
V_567 = true ;
}
}
F_81 ( & V_2 -> V_7 ) ;
if ( ! V_567 )
break;
V_96 = V_213 ;
if ( V_192 & V_290 )
F_159 ( V_22 ) ;
F_4 ( V_421 , V_192 & ~ V_565 ) ;
V_564 = F_2 ( V_421 ) ;
if ( V_192 & V_559 )
F_82 ( & V_2 -> V_129 [ V_199 ] ) ;
if ( V_192 & V_570 )
F_82 ( & V_2 -> V_129 [ V_201 ] ) ;
F_154 (dev_priv, pipe) {
if ( V_269 [ V_37 ] & V_276 &&
F_314 ( V_22 , V_37 , V_37 , V_192 ) )
V_565 &= ~ F_306 ( V_37 ) ;
if ( V_269 [ V_37 ] & V_54 )
V_568 = true ;
if ( V_269 [ V_37 ] & V_278 )
F_144 ( V_22 , V_37 ) ;
if ( V_269 [ V_37 ] & V_46 )
F_158 ( V_2 , V_37 ) ;
}
if ( V_568 || ( V_192 & V_566 ) )
F_178 ( V_22 ) ;
if ( V_269 [ 0 ] & V_279 )
F_132 ( V_22 ) ;
V_192 = V_564 ;
}
return V_96 ;
}
static void F_321 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
if ( ! V_2 )
return;
F_9 ( V_2 , 0xffffffff , 0 ) ;
F_4 ( V_281 , F_2 ( V_281 ) ) ;
F_4 ( V_487 , 0xffffffff ) ;
F_154 (dev_priv, pipe)
F_4 ( F_40 ( V_37 ) , 0 ) ;
F_4 ( V_555 , 0xffffffff ) ;
F_4 ( V_556 , 0x0 ) ;
F_154 (dev_priv, pipe)
F_4 ( F_40 ( V_37 ) ,
F_2 ( F_40 ( V_37 ) ) & 0x8000ffff ) ;
F_4 ( V_421 , F_2 ( V_421 ) ) ;
}
void F_322 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
F_323 ( V_2 ) ;
F_324 ( & V_2 -> V_25 . V_30 , F_93 ) ;
F_324 ( & V_2 -> V_169 . V_170 , F_100 ) ;
if ( F_47 ( V_2 ) && ! F_96 ( V_2 ) )
V_2 -> V_24 = V_151 | V_28 ;
else
V_2 -> V_24 = V_577 ;
F_325 ( & V_2 -> V_389 . V_468 ,
F_243 ) ;
F_326 ( & V_2 -> V_578 , V_579 , V_580 ) ;
if ( F_60 ( V_2 ) ) {
V_22 -> V_581 = 0 ;
V_22 -> V_262 -> V_263 = F_51 ;
} else if ( F_69 ( V_2 ) || F_20 ( V_2 ) -> V_16 >= 5 ) {
V_22 -> V_581 = 0xffffffff ;
V_22 -> V_262 -> V_263 = F_57 ;
} else {
V_22 -> V_262 -> V_263 = F_52 ;
V_22 -> V_581 = 0xffffff ;
}
if ( ! F_60 ( V_2 ) )
V_22 -> V_582 = true ;
V_22 -> V_262 -> V_583 = F_72 ;
V_22 -> V_262 -> V_584 = F_65 ;
if ( F_96 ( V_2 ) ) {
V_22 -> V_262 -> V_585 = F_162 ;
V_22 -> V_262 -> V_586 = F_273 ;
V_22 -> V_262 -> V_587 = F_296 ;
V_22 -> V_262 -> V_588 = F_300 ;
V_22 -> V_262 -> V_589 = F_222 ;
V_22 -> V_262 -> V_590 = F_227 ;
V_2 -> V_591 . V_592 = F_319 ;
} else if ( F_47 ( V_2 ) ) {
V_22 -> V_262 -> V_585 = F_161 ;
V_22 -> V_262 -> V_586 = F_264 ;
V_22 -> V_262 -> V_587 = F_292 ;
V_22 -> V_262 -> V_588 = F_299 ;
V_22 -> V_262 -> V_589 = F_222 ;
V_22 -> V_262 -> V_590 = F_227 ;
V_2 -> V_591 . V_592 = F_319 ;
} else if ( F_20 ( V_2 ) -> V_16 >= 8 ) {
V_22 -> V_262 -> V_585 = F_193 ;
V_22 -> V_262 -> V_586 = F_268 ;
V_22 -> V_262 -> V_587 = F_295 ;
V_22 -> V_262 -> V_588 = F_297 ;
V_22 -> V_262 -> V_589 = F_223 ;
V_22 -> V_262 -> V_590 = F_228 ;
if ( F_194 ( V_22 ) )
V_2 -> V_591 . V_592 = F_281 ;
else if ( F_199 ( V_22 ) )
V_2 -> V_591 . V_592 = F_279 ;
else
V_2 -> V_591 . V_592 = F_280 ;
} else if ( F_198 ( V_22 ) ) {
V_22 -> V_262 -> V_585 = F_190 ;
V_22 -> V_262 -> V_586 = F_261 ;
V_22 -> V_262 -> V_587 = F_285 ;
V_22 -> V_262 -> V_588 = F_301 ;
V_22 -> V_262 -> V_589 = F_221 ;
V_22 -> V_262 -> V_590 = F_226 ;
V_2 -> V_591 . V_592 = F_280 ;
} else {
if ( F_20 ( V_2 ) -> V_16 == 2 ) {
V_22 -> V_262 -> V_586 = F_302 ;
V_22 -> V_262 -> V_587 = F_304 ;
V_22 -> V_262 -> V_585 = F_308 ;
V_22 -> V_262 -> V_588 = F_310 ;
} else if ( F_20 ( V_2 ) -> V_16 == 3 ) {
V_22 -> V_262 -> V_586 = F_311 ;
V_22 -> V_262 -> V_587 = F_313 ;
V_22 -> V_262 -> V_588 = F_316 ;
V_22 -> V_262 -> V_585 = F_315 ;
} else {
V_22 -> V_262 -> V_586 = F_317 ;
V_22 -> V_262 -> V_587 = F_318 ;
V_22 -> V_262 -> V_588 = F_321 ;
V_22 -> V_262 -> V_585 = F_320 ;
}
if ( F_312 ( V_2 ) )
V_2 -> V_591 . V_592 = F_319 ;
V_22 -> V_262 -> V_589 = F_220 ;
V_22 -> V_262 -> V_590 = F_225 ;
}
}
int F_327 ( struct V_1 * V_2 )
{
V_2 -> V_593 . V_594 = true ;
return F_328 ( V_2 -> V_22 , V_2 -> V_22 -> V_595 -> V_32 ) ;
}
void F_329 ( struct V_1 * V_2 )
{
F_330 ( V_2 -> V_22 ) ;
F_331 ( V_2 ) ;
V_2 -> V_593 . V_594 = false ;
}
void F_332 ( struct V_1 * V_2 )
{
V_2 -> V_22 -> V_262 -> V_588 ( V_2 -> V_22 ) ;
V_2 -> V_593 . V_594 = false ;
F_36 ( V_2 -> V_22 -> V_32 ) ;
}
void F_333 ( struct V_1 * V_2 )
{
V_2 -> V_593 . V_594 = true ;
V_2 -> V_22 -> V_262 -> V_586 ( V_2 -> V_22 ) ;
V_2 -> V_22 -> V_262 -> V_587 ( V_2 -> V_22 ) ;
}
