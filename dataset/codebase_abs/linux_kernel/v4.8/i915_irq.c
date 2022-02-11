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
}
void F_16 ( struct V_1 * V_2 , T_3 V_5 )
{
F_15 ( V_2 , V_5 , V_5 ) ;
F_17 ( V_15 ) ;
}
void F_18 ( struct V_1 * V_2 , T_3 V_5 )
{
F_15 ( V_2 , V_5 , 0 ) ;
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
F_5 ( F_22 ( V_2 ) , V_2 -> V_20 ) ;
F_6 ( F_22 ( V_2 ) ) ;
}
}
void F_27 ( struct V_1 * V_2 , T_3 V_5 )
{
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_26 ( V_2 , V_5 , V_5 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
T_3 V_5 )
{
F_26 ( V_2 , V_5 , 0 ) ;
}
void F_29 ( struct V_1 * V_2 , T_3 V_5 )
{
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_28 ( V_2 , V_5 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
T_1 V_3 = F_19 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_5 ( V_3 , V_2 -> V_21 ) ;
F_5 ( V_3 , V_2 -> V_21 ) ;
F_6 ( V_3 ) ;
V_2 -> V_22 . V_23 = 0 ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
F_32 ( V_2 -> V_22 . V_23 ) ;
F_32 ( F_2 ( F_19 ( V_2 ) ) & V_2 -> V_21 ) ;
V_2 -> V_22 . V_24 = true ;
F_5 ( F_24 ( V_2 ) , F_2 ( F_24 ( V_2 ) ) |
V_2 -> V_21 ) ;
F_27 ( V_2 , V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
T_2 F_33 ( struct V_1 * V_2 , T_2 V_5 )
{
return ( V_5 & ~ V_2 -> V_22 . V_25 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
V_2 -> V_22 . V_24 = false ;
F_5 ( V_26 , F_33 ( V_2 , ~ 0 ) ) ;
F_28 ( V_2 , V_2 -> V_21 ) ;
F_5 ( F_24 ( V_2 ) , F_2 ( F_24 ( V_2 ) ) &
~ V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_35 ( V_2 -> V_27 . V_28 ) ;
F_36 ( & V_2 -> V_22 . V_29 ) ;
F_30 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
T_3 V_30 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_30 = F_2 ( V_31 ) ;
V_11 = V_30 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_30 ) {
F_5 ( V_31 , V_11 ) ;
F_6 ( V_31 ) ;
}
}
void F_38 ( struct V_1 * V_2 ,
enum V_32 V_32 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_11 = V_2 -> V_33 [ V_32 ] ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_33 [ V_32 ] ) {
V_2 -> V_33 [ V_32 ] = V_11 ;
F_5 ( F_39 ( V_32 ) , V_2 -> V_33 [ V_32 ] ) ;
F_6 ( F_39 ( V_32 ) ) ;
}
}
void F_40 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_34 = F_2 ( V_35 ) ;
V_34 &= ~ V_9 ;
V_34 |= ( ~ V_10 & V_9 ) ;
F_9 ( V_10 & ~ V_9 ) ;
F_8 ( & V_2 -> V_7 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_5 ( V_35 , V_34 ) ;
F_6 ( V_35 ) ;
}
static void
F_41 ( struct V_1 * V_2 , enum V_32 V_32 ,
T_2 V_36 , T_2 V_37 )
{
T_1 V_3 = F_42 ( V_32 ) ;
T_2 V_38 = F_2 ( V_3 ) & V_39 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_43 ( V_36 & ~ V_39 ||
V_37 & ~ V_40 ,
L_2 ,
F_44 ( V_32 ) , V_36 , V_37 ) )
return;
if ( ( V_38 & V_36 ) == V_36 )
return;
V_2 -> V_41 [ V_32 ] |= V_37 ;
V_38 |= V_36 | V_37 ;
F_5 ( V_3 , V_38 ) ;
F_6 ( V_3 ) ;
}
static void
F_45 ( struct V_1 * V_2 , enum V_32 V_32 ,
T_2 V_36 , T_2 V_37 )
{
T_1 V_3 = F_42 ( V_32 ) ;
T_2 V_38 = F_2 ( V_3 ) & V_39 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_43 ( V_36 & ~ V_39 ||
V_37 & ~ V_40 ,
L_2 ,
F_44 ( V_32 ) , V_36 , V_37 ) )
return;
if ( ( V_38 & V_36 ) == 0 )
return;
V_2 -> V_41 [ V_32 ] &= ~ V_37 ;
V_38 &= ~ V_36 ;
F_5 ( V_3 , V_38 ) ;
F_6 ( V_3 ) ;
}
static T_2 F_46 ( struct V_42 * V_43 , T_2 V_37 )
{
T_2 V_36 = V_37 << 16 ;
if ( F_32 ( V_37 & V_44 ) )
return 0 ;
if ( F_32 ( V_37 & V_45 ) )
return 0 ;
V_36 &= ~ ( V_46 |
V_47 |
V_48 ) ;
if ( V_37 & V_49 )
V_36 |= V_47 ;
if ( V_37 & V_50 )
V_36 |= V_48 ;
return V_36 ;
}
void
F_47 ( struct V_1 * V_2 , enum V_32 V_32 ,
T_2 V_37 )
{
T_2 V_36 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) )
V_36 = F_46 ( & V_2 -> V_27 ,
V_37 ) ;
else
V_36 = V_37 << 16 ;
F_41 ( V_2 , V_32 , V_36 , V_37 ) ;
}
void
F_50 ( struct V_1 * V_2 , enum V_32 V_32 ,
T_2 V_37 )
{
T_2 V_36 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) )
V_36 = F_46 ( & V_2 -> V_27 ,
V_37 ) ;
else
V_36 = V_37 << 16 ;
F_45 ( V_2 , V_32 , V_36 , V_37 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_51 . V_52 || ! F_52 ( V_2 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
F_47 ( V_2 , V_53 , V_54 ) ;
if ( F_53 ( V_2 ) >= 4 )
F_47 ( V_2 , V_55 ,
V_54 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static T_2 F_54 ( struct V_42 * V_43 , unsigned int V_32 )
{
return 0 ;
}
static T_2 F_55 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_1 V_56 , V_57 ;
T_2 V_58 , V_59 , V_60 , V_61 , V_62 , V_63 , V_64 ;
struct V_65 * V_65 =
F_57 ( V_2 -> V_66 [ V_32 ] ) ;
const struct V_67 * V_68 = & V_65 -> V_69 . V_70 ;
V_64 = V_68 -> V_71 ;
V_63 = V_68 -> V_72 ;
V_62 = V_68 -> V_73 ;
if ( V_68 -> V_74 & V_75 )
V_62 = F_58 ( V_62 , 2 ) ;
V_62 *= V_64 ;
V_62 -= V_64 - V_63 ;
V_56 = F_59 ( V_32 ) ;
V_57 = F_60 ( V_32 ) ;
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
static T_2 F_61 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
return F_2 ( F_62 ( V_32 ) ) ;
}
static int F_63 ( struct V_65 * V_80 )
{
struct V_42 * V_43 = V_80 -> V_69 . V_43 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
const struct V_67 * V_68 = & V_80 -> V_69 . V_70 ;
enum V_32 V_32 = V_80 -> V_32 ;
int V_81 , V_82 ;
V_82 = V_68 -> V_83 ;
if ( V_68 -> V_74 & V_75 )
V_82 /= 2 ;
if ( F_64 ( V_2 ) )
V_81 = F_65 ( F_66 ( V_32 ) ) & V_84 ;
else
V_81 = F_65 ( F_66 ( V_32 ) ) & V_85 ;
if ( F_67 ( V_2 ) && ! V_81 ) {
int V_86 , V_87 ;
for ( V_86 = 0 ; V_86 < 100 ; V_86 ++ ) {
F_68 ( 1 ) ;
V_87 = F_69 ( V_2 , F_66 ( V_32 ) ) &
V_85 ;
if ( V_87 != V_81 ) {
V_81 = V_87 ;
break;
}
}
}
return ( V_81 + V_80 -> V_88 ) % V_82 ;
}
static int F_70 ( struct V_42 * V_43 , unsigned int V_32 ,
unsigned int V_74 , int * V_89 , int * V_90 ,
T_4 * V_91 , T_4 * V_92 ,
const struct V_67 * V_68 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
struct V_93 * V_80 = V_2 -> V_66 [ V_32 ] ;
struct V_65 * V_65 = F_57 ( V_80 ) ;
int V_81 ;
int V_62 , V_94 , V_63 , V_64 , V_82 ;
bool V_95 = true ;
int V_96 = 0 ;
unsigned long V_97 ;
if ( F_9 ( ! V_68 -> V_98 ) ) {
F_71 ( L_3
L_4 , F_44 ( V_32 ) ) ;
return 0 ;
}
V_64 = V_68 -> V_71 ;
V_63 = V_68 -> V_72 ;
V_82 = V_68 -> V_83 ;
V_62 = V_68 -> V_73 ;
V_94 = V_68 -> V_99 ;
if ( V_68 -> V_74 & V_75 ) {
V_62 = F_58 ( V_62 , 2 ) ;
V_94 /= 2 ;
V_82 /= 2 ;
}
V_96 |= V_100 | V_101 ;
F_72 ( & V_2 -> V_102 . V_103 , V_97 ) ;
if ( V_91 )
* V_91 = F_73 () ;
if ( F_64 ( V_2 ) || F_74 ( V_2 ) || F_53 ( V_2 ) >= 5 ) {
V_81 = F_63 ( V_65 ) ;
} else {
V_81 = ( F_65 ( F_60 ( V_32 ) ) & V_78 ) >> V_104 ;
V_62 *= V_64 ;
V_94 *= V_64 ;
V_82 *= V_64 ;
if ( V_81 >= V_82 )
V_81 = V_82 - 1 ;
V_81 = ( V_81 + V_64 - V_63 ) % V_82 ;
}
if ( V_92 )
* V_92 = F_73 () ;
F_75 ( & V_2 -> V_102 . V_103 , V_97 ) ;
V_95 = V_81 >= V_62 && V_81 < V_94 ;
if ( V_81 >= V_62 )
V_81 -= V_94 ;
else
V_81 += V_82 - V_94 ;
if ( F_64 ( V_2 ) || F_74 ( V_2 ) || F_53 ( V_2 ) >= 5 ) {
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
int F_76 ( struct V_65 * V_80 )
{
struct V_1 * V_2 = F_56 ( V_80 -> V_69 . V_43 ) ;
unsigned long V_97 ;
int V_81 ;
F_72 ( & V_2 -> V_102 . V_103 , V_97 ) ;
V_81 = F_63 ( V_80 ) ;
F_75 ( & V_2 -> V_102 . V_103 , V_97 ) ;
return V_81 ;
}
static int F_77 ( struct V_42 * V_43 , unsigned int V_32 ,
int * V_106 ,
struct V_107 * V_108 ,
unsigned V_74 )
{
struct V_93 * V_80 ;
if ( V_32 >= F_20 ( V_43 ) -> V_109 ) {
F_78 ( L_5 , V_32 ) ;
return - V_110 ;
}
V_80 = F_79 ( V_43 , V_32 ) ;
if ( V_80 == NULL ) {
F_78 ( L_5 , V_32 ) ;
return - V_110 ;
}
if ( ! V_80 -> V_70 . V_98 ) {
F_80 ( L_6 , V_32 ) ;
return - V_111 ;
}
return F_81 ( V_43 , V_32 , V_106 ,
V_108 , V_74 ,
& V_80 -> V_70 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
T_2 V_112 , V_113 , V_114 , V_115 ;
T_5 V_116 ;
F_83 ( & V_117 ) ;
F_84 ( V_118 , F_2 ( V_118 ) ) ;
V_116 = V_2 -> V_119 . V_120 ;
F_84 ( V_118 , V_121 ) ;
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
if ( F_85 ( V_2 , V_116 ) )
V_2 -> V_119 . V_120 = V_116 ;
F_86 ( & V_117 ) ;
return;
}
static void F_87 ( struct V_128 * V_129 )
{
F_88 ( V_129 -> V_130 . V_131 , true ) ;
if ( F_89 ( V_129 ) ) {
F_90 ( V_129 ) ;
V_129 -> V_130 . V_132 ++ ;
}
}
static void F_91 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
V_134 -> V_135 = F_92 ( V_2 , V_136 ) ;
V_134 -> V_137 = F_2 ( V_138 ) ;
V_134 -> V_139 = F_2 ( V_140 ) ;
}
static bool F_93 ( struct V_1 * V_2 ,
const struct V_133 * V_141 ,
const struct V_133 * V_142 ,
int V_143 )
{
T_6 time , V_144 ;
unsigned int V_145 = 100 ;
if ( V_141 -> V_135 == 0 )
return false ;
if ( F_2 ( V_146 ) & V_147 )
V_145 <<= 8 ;
time = V_142 -> V_135 - V_141 -> V_135 ;
time *= V_143 * V_2 -> V_148 ;
V_144 = V_142 -> V_137 - V_141 -> V_137 ;
V_144 += V_142 -> V_139 - V_141 -> V_139 ;
V_144 *= V_145 * V_149 ;
return V_144 >= time ;
}
void F_94 ( struct V_1 * V_2 )
{
F_91 ( V_2 , & V_2 -> V_22 . V_150 ) ;
V_2 -> V_22 . V_151 = V_2 -> V_22 . V_150 ;
}
static T_2 F_95 ( struct V_1 * V_2 , T_2 V_23 )
{
struct V_133 V_142 ;
T_2 V_152 = 0 ;
if ( ( V_23 & ( V_153 | V_154 ) ) == 0 )
return 0 ;
F_91 ( V_2 , & V_142 ) ;
if ( V_142 . V_135 == 0 )
return 0 ;
if ( V_23 & V_153 ) {
if ( ! F_93 ( V_2 ,
& V_2 -> V_22 . V_150 , & V_142 ,
V_2 -> V_22 . V_155 ) )
V_152 |= V_156 ;
V_2 -> V_22 . V_150 = V_142 ;
}
if ( V_23 & V_154 ) {
if ( F_93 ( V_2 ,
& V_2 -> V_22 . V_151 , & V_142 ,
V_2 -> V_22 . V_157 ) )
V_152 |= V_158 ;
V_2 -> V_22 . V_151 = V_142 ;
}
return V_152 ;
}
static bool F_96 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
F_97 (engine, dev_priv)
if ( F_98 ( V_129 ) )
return true ;
return false ;
}
static void F_99 ( struct V_159 * V_29 )
{
struct V_1 * V_2 =
F_100 ( V_29 , struct V_1 , V_22 . V_29 ) ;
bool V_160 ;
int V_116 , V_161 , V_162 , V_163 ;
T_2 V_23 ;
F_11 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_22 . V_24 ) {
F_12 ( & V_2 -> V_7 ) ;
return;
}
V_23 = V_2 -> V_22 . V_23 ;
V_2 -> V_22 . V_23 = 0 ;
F_27 ( V_2 , V_2 -> V_21 ) ;
V_160 = V_2 -> V_22 . V_160 ;
V_2 -> V_22 . V_160 = false ;
F_12 ( & V_2 -> V_7 ) ;
F_9 ( V_23 & ~ V_2 -> V_21 ) ;
if ( ( V_23 & V_2 -> V_21 ) == 0 && ! V_160 )
return;
F_101 ( & V_2 -> V_22 . V_164 ) ;
V_23 |= F_95 ( V_2 , V_23 ) ;
V_161 = V_2 -> V_22 . V_165 ;
V_116 = V_2 -> V_22 . V_166 ;
V_162 = V_2 -> V_22 . V_167 ;
V_163 = V_2 -> V_22 . V_168 ;
if ( V_160 ) {
V_116 = V_2 -> V_22 . V_168 ;
V_161 = 0 ;
} else if ( V_23 & V_158 ) {
if ( V_161 > 0 )
V_161 *= 2 ;
else
V_161 = F_49 ( V_2 ) ? 2 : 1 ;
if ( V_116 < V_2 -> V_22 . V_169 - V_161 ) {
V_116 = V_2 -> V_22 . V_169 ;
V_161 = 0 ;
}
} else if ( F_96 ( V_2 ) ) {
V_161 = 0 ;
} else if ( V_23 & V_170 ) {
if ( V_2 -> V_22 . V_166 > V_2 -> V_22 . V_169 )
V_116 = V_2 -> V_22 . V_169 ;
else
V_116 = V_2 -> V_22 . V_167 ;
V_161 = 0 ;
} else if ( V_23 & V_156 ) {
if ( V_161 < 0 )
V_161 *= 2 ;
else
V_161 = F_49 ( V_2 ) ? - 2 : - 1 ;
} else {
V_161 = 0 ;
}
V_2 -> V_22 . V_165 = V_161 ;
V_116 += V_161 ;
V_116 = F_102 ( int , V_116 , V_162 , V_163 ) ;
F_103 ( V_2 , V_116 ) ;
F_104 ( & V_2 -> V_22 . V_164 ) ;
}
static void F_105 ( struct V_159 * V_29 )
{
struct V_1 * V_2 =
F_100 ( V_29 , struct V_1 , V_171 . V_172 ) ;
T_2 V_173 , V_174 , V_175 , V_176 ;
char * V_177 [ 6 ] ;
T_3 V_178 ;
T_7 V_179 = 0 ;
F_101 ( & V_2 -> V_27 . V_180 ) ;
if ( F_9 ( ! V_2 -> V_171 . V_181 ) )
goto V_182;
V_178 = F_2 ( V_183 ) ;
F_5 ( V_183 , V_178 & ~ V_184 ) ;
F_6 ( V_183 ) ;
while ( ( V_179 = F_106 ( V_2 -> V_171 . V_181 ) ) != 0 ) {
T_1 V_3 ;
V_179 -- ;
if ( F_32 ( V_179 >= F_107 ( V_2 ) ) )
break;
V_2 -> V_171 . V_181 &= ~ ( 1 << V_179 ) ;
V_3 = F_108 ( V_179 ) ;
V_173 = F_2 ( V_3 ) ;
V_174 = F_109 ( V_173 ) ;
V_175 = F_110 ( V_173 ) ;
V_176 = F_111 ( V_173 ) ;
F_5 ( V_3 , V_185 | V_186 ) ;
F_6 ( V_3 ) ;
V_177 [ 0 ] = V_187 L_7 ;
V_177 [ 1 ] = F_112 ( V_188 , L_8 , V_174 ) ;
V_177 [ 2 ] = F_112 ( V_188 , L_9 , V_175 ) ;
V_177 [ 3 ] = F_112 ( V_188 , L_10 , V_176 ) ;
V_177 [ 4 ] = F_112 ( V_188 , L_11 , V_179 ) ;
V_177 [ 5 ] = NULL ;
F_113 ( & V_2 -> V_27 . V_189 -> V_190 -> V_191 ,
V_192 , V_177 ) ;
F_114 ( L_12 ,
V_179 , V_174 , V_175 , V_176 ) ;
F_115 ( V_177 [ 4 ] ) ;
F_115 ( V_177 [ 3 ] ) ;
F_115 ( V_177 [ 2 ] ) ;
F_115 ( V_177 [ 1 ] ) ;
}
F_5 ( V_183 , V_178 ) ;
V_182:
F_9 ( V_2 -> V_171 . V_181 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_16 ( V_2 , F_116 ( V_2 ) ) ;
F_12 ( & V_2 -> V_7 ) ;
F_104 ( & V_2 -> V_27 . V_180 ) ;
}
static void F_117 ( struct V_1 * V_2 ,
T_2 V_193 )
{
if ( ! F_118 ( V_2 ) )
return;
F_83 ( & V_2 -> V_7 ) ;
F_18 ( V_2 , F_116 ( V_2 ) ) ;
F_86 ( & V_2 -> V_7 ) ;
V_193 &= F_116 ( V_2 ) ;
if ( V_193 & V_194 )
V_2 -> V_171 . V_181 |= 1 << 1 ;
if ( V_193 & V_195 )
V_2 -> V_171 . V_181 |= 1 << 0 ;
F_119 ( V_2 -> V_196 , & V_2 -> V_171 . V_172 ) ;
}
static void F_120 ( struct V_1 * V_2 ,
T_2 V_197 )
{
if ( V_197 & V_198 )
F_87 ( & V_2 -> V_129 [ V_199 ] ) ;
if ( V_197 & V_200 )
F_87 ( & V_2 -> V_129 [ V_201 ] ) ;
}
static void F_121 ( struct V_1 * V_2 ,
T_2 V_197 )
{
if ( V_197 & V_198 )
F_87 ( & V_2 -> V_129 [ V_199 ] ) ;
if ( V_197 & V_202 )
F_87 ( & V_2 -> V_129 [ V_201 ] ) ;
if ( V_197 & V_203 )
F_87 ( & V_2 -> V_129 [ V_204 ] ) ;
if ( V_197 & ( V_205 |
V_206 |
V_207 ) )
F_114 ( L_13 , V_197 ) ;
if ( V_197 & F_116 ( V_2 ) )
F_117 ( V_2 , V_197 ) ;
}
static T_8 void
F_122 ( struct V_128 * V_129 , T_2 V_193 , int V_208 )
{
if ( V_193 & ( V_198 << V_208 ) )
F_87 ( V_129 ) ;
if ( V_193 & ( V_209 << V_208 ) )
F_123 ( & V_129 -> V_210 ) ;
}
static T_9 F_124 ( struct V_1 * V_2 ,
T_2 V_211 ,
T_2 V_197 [ 4 ] )
{
T_9 V_96 = V_212 ;
if ( V_211 & ( V_213 | V_214 ) ) {
V_197 [ 0 ] = F_65 ( F_21 ( 0 ) ) ;
if ( V_197 [ 0 ] ) {
F_125 ( F_21 ( 0 ) , V_197 [ 0 ] ) ;
V_96 = V_215 ;
} else
F_78 ( L_14 ) ;
}
if ( V_211 & ( V_216 | V_217 ) ) {
V_197 [ 1 ] = F_65 ( F_21 ( 1 ) ) ;
if ( V_197 [ 1 ] ) {
F_125 ( F_21 ( 1 ) , V_197 [ 1 ] ) ;
V_96 = V_215 ;
} else
F_78 ( L_15 ) ;
}
if ( V_211 & V_218 ) {
V_197 [ 3 ] = F_65 ( F_21 ( 3 ) ) ;
if ( V_197 [ 3 ] ) {
F_125 ( F_21 ( 3 ) , V_197 [ 3 ] ) ;
V_96 = V_215 ;
} else
F_78 ( L_16 ) ;
}
if ( V_211 & V_219 ) {
V_197 [ 2 ] = F_65 ( F_21 ( 2 ) ) ;
if ( V_197 [ 2 ] & V_2 -> V_21 ) {
F_125 ( F_21 ( 2 ) ,
V_197 [ 2 ] & V_2 -> V_21 ) ;
V_96 = V_215 ;
} else
F_78 ( L_17 ) ;
}
return V_96 ;
}
static void F_126 ( struct V_1 * V_2 ,
T_2 V_197 [ 4 ] )
{
if ( V_197 [ 0 ] ) {
F_122 ( & V_2 -> V_129 [ V_199 ] ,
V_197 [ 0 ] , V_220 ) ;
F_122 ( & V_2 -> V_129 [ V_204 ] ,
V_197 [ 0 ] , V_221 ) ;
}
if ( V_197 [ 1 ] ) {
F_122 ( & V_2 -> V_129 [ V_201 ] ,
V_197 [ 1 ] , V_222 ) ;
F_122 ( & V_2 -> V_129 [ V_223 ] ,
V_197 [ 1 ] , V_224 ) ;
}
if ( V_197 [ 3 ] )
F_122 ( & V_2 -> V_129 [ V_225 ] ,
V_197 [ 3 ] , V_226 ) ;
if ( V_197 [ 2 ] & V_2 -> V_21 )
F_127 ( V_2 , V_197 [ 2 ] ) ;
}
static bool F_128 ( enum V_227 V_227 , T_2 V_4 )
{
switch ( V_227 ) {
case V_228 :
return V_4 & V_229 ;
case V_230 :
return V_4 & V_231 ;
case V_232 :
return V_4 & V_233 ;
default:
return false ;
}
}
static bool F_129 ( enum V_227 V_227 , T_2 V_4 )
{
switch ( V_227 ) {
case V_234 :
return V_4 & V_235 ;
default:
return false ;
}
}
static bool F_130 ( enum V_227 V_227 , T_2 V_4 )
{
switch ( V_227 ) {
case V_228 :
return V_4 & V_229 ;
case V_230 :
return V_4 & V_231 ;
case V_232 :
return V_4 & V_233 ;
case V_236 :
return V_4 & V_237 ;
default:
return false ;
}
}
static bool F_131 ( enum V_227 V_227 , T_2 V_4 )
{
switch ( V_227 ) {
case V_228 :
return V_4 & V_238 ;
default:
return false ;
}
}
static bool F_132 ( enum V_227 V_227 , T_2 V_4 )
{
switch ( V_227 ) {
case V_230 :
return V_4 & V_231 ;
case V_232 :
return V_4 & V_233 ;
case V_236 :
return V_4 & V_237 ;
default:
return false ;
}
}
static bool F_133 ( enum V_227 V_227 , T_2 V_4 )
{
switch ( V_227 ) {
case V_230 :
return V_4 & V_239 ;
case V_232 :
return V_4 & V_240 ;
case V_236 :
return V_4 & V_241 ;
default:
return false ;
}
}
static void F_134 ( T_2 * V_242 , T_2 * V_243 ,
T_2 V_244 , T_2 V_245 ,
const T_2 V_246 [ V_247 ] ,
bool F_135 ( enum V_227 V_227 , T_2 V_4 ) )
{
enum V_227 V_227 ;
int V_86 ;
F_136 (i) {
if ( ( V_246 [ V_86 ] & V_244 ) == 0 )
continue;
* V_242 |= F_137 ( V_86 ) ;
if ( ! F_138 ( V_86 , & V_227 ) )
continue;
if ( F_135 ( V_227 , V_245 ) )
* V_243 |= F_137 ( V_86 ) ;
}
F_71 ( L_18 ,
V_244 , V_245 , * V_242 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_140 ( & V_2 -> V_248 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
F_140 ( & V_2 -> V_248 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
enum V_32 V_32 ,
T_3 V_249 , T_3 V_250 ,
T_3 V_251 , T_3 V_252 ,
T_3 V_253 )
{
struct V_254 * V_255 = & V_2 -> V_255 [ V_32 ] ;
struct V_256 * V_257 ;
int V_258 , V_259 ;
F_83 ( & V_255 -> V_103 ) ;
if ( ! V_255 -> V_260 ) {
F_86 ( & V_255 -> V_103 ) ;
F_80 ( L_19 ) ;
return;
}
V_258 = V_255 -> V_258 ;
V_259 = V_255 -> V_259 ;
if ( F_143 ( V_258 , V_259 , V_261 ) < 1 ) {
F_86 ( & V_255 -> V_103 ) ;
F_78 ( L_20 ) ;
return;
}
V_257 = & V_255 -> V_260 [ V_258 ] ;
V_257 -> V_262 = V_2 -> V_27 . V_263 -> V_264 ( & V_2 -> V_27 ,
V_32 ) ;
V_257 -> V_265 [ 0 ] = V_249 ;
V_257 -> V_265 [ 1 ] = V_250 ;
V_257 -> V_265 [ 2 ] = V_251 ;
V_257 -> V_265 [ 3 ] = V_252 ;
V_257 -> V_265 [ 4 ] = V_253 ;
V_258 = ( V_258 + 1 ) & ( V_261 - 1 ) ;
V_255 -> V_258 = V_258 ;
F_86 ( & V_255 -> V_103 ) ;
F_144 ( & V_255 -> V_196 ) ;
}
static inline void
F_142 ( struct V_1 * V_2 ,
enum V_32 V_32 ,
T_3 V_249 , T_3 V_250 ,
T_3 V_251 , T_3 V_252 ,
T_3 V_253 ) {}
static void F_145 ( struct V_1 * V_2 ,
enum V_32 V_32 )
{
F_142 ( V_2 , V_32 ,
F_2 ( F_146 ( V_32 ) ) ,
0 , 0 , 0 , 0 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
enum V_32 V_32 )
{
F_142 ( V_2 , V_32 ,
F_2 ( F_146 ( V_32 ) ) ,
F_2 ( F_148 ( V_32 ) ) ,
F_2 ( F_149 ( V_32 ) ) ,
F_2 ( F_150 ( V_32 ) ) ,
F_2 ( F_151 ( V_32 ) ) ) ;
}
static void F_152 ( struct V_1 * V_2 ,
enum V_32 V_32 )
{
T_3 V_266 , V_267 ;
if ( F_53 ( V_2 ) >= 3 )
V_266 = F_2 ( F_153 ( V_32 ) ) ;
else
V_266 = 0 ;
if ( F_53 ( V_2 ) >= 5 || F_74 ( V_2 ) )
V_267 = F_2 ( F_154 ( V_32 ) ) ;
else
V_267 = 0 ;
F_142 ( V_2 , V_32 ,
F_2 ( F_155 ( V_32 ) ) ,
F_2 ( F_156 ( V_32 ) ) ,
F_2 ( F_157 ( V_32 ) ) ,
V_266 , V_267 ) ;
}
static void F_127 ( struct V_1 * V_2 , T_2 V_23 )
{
if ( V_23 & V_2 -> V_21 ) {
F_83 ( & V_2 -> V_7 ) ;
F_29 ( V_2 , V_23 & V_2 -> V_21 ) ;
if ( V_2 -> V_22 . V_24 ) {
V_2 -> V_22 . V_23 |= V_23 & V_2 -> V_21 ;
F_158 ( & V_2 -> V_22 . V_29 ) ;
}
F_86 ( & V_2 -> V_7 ) ;
}
if ( F_20 ( V_2 ) -> V_16 >= 8 )
return;
if ( F_159 ( V_2 ) ) {
if ( V_23 & V_268 )
F_87 ( & V_2 -> V_129 [ V_225 ] ) ;
if ( V_23 & V_269 )
F_114 ( L_21 , V_23 ) ;
}
}
static bool F_160 ( struct V_1 * V_2 ,
enum V_32 V_32 )
{
bool V_96 ;
V_96 = F_161 ( & V_2 -> V_27 , V_32 ) ;
if ( V_96 )
F_162 ( V_2 , V_32 ) ;
return V_96 ;
}
static void F_163 ( struct V_1 * V_2 ,
T_2 V_193 , T_2 V_270 [ V_271 ] )
{
int V_32 ;
F_83 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_272 ) {
F_86 ( & V_2 -> V_7 ) ;
return;
}
F_164 (dev_priv, pipe) {
T_1 V_3 ;
T_2 V_5 , V_273 = 0 ;
V_5 = V_46 ;
switch ( V_32 ) {
case V_55 :
V_273 = V_274 ;
break;
case V_53 :
V_273 = V_275 ;
break;
case V_276 :
V_273 = V_277 ;
break;
}
if ( V_193 & V_273 )
V_5 |= V_2 -> V_41 [ V_32 ] ;
if ( ! V_5 )
continue;
V_3 = F_42 ( V_32 ) ;
V_5 |= V_39 ;
V_270 [ V_32 ] = F_2 ( V_3 ) & V_5 ;
if ( V_270 [ V_32 ] & ( V_46 |
V_40 ) )
F_5 ( V_3 , V_270 [ V_32 ] ) ;
}
F_86 ( & V_2 -> V_7 ) ;
}
static void F_165 ( struct V_1 * V_2 ,
T_2 V_270 [ V_271 ] )
{
enum V_32 V_32 ;
F_164 (dev_priv, pipe) {
if ( V_270 [ V_32 ] & V_278 &&
F_160 ( V_2 , V_32 ) )
F_166 ( V_2 , V_32 ) ;
if ( V_270 [ V_32 ] & V_279 )
F_167 ( V_2 , V_32 ) ;
if ( V_270 [ V_32 ] & V_280 )
F_152 ( V_2 , V_32 ) ;
if ( V_270 [ V_32 ] & V_46 )
F_168 ( V_2 , V_32 ) ;
}
if ( V_270 [ 0 ] & V_281 )
F_139 ( V_2 ) ;
}
static T_2 F_169 ( struct V_1 * V_2 )
{
T_2 V_282 = F_2 ( V_283 ) ;
if ( V_282 )
F_5 ( V_283 , V_282 ) ;
return V_282 ;
}
static void F_170 ( struct V_1 * V_2 ,
T_2 V_282 )
{
T_2 V_242 = 0 , V_243 = 0 ;
if ( F_74 ( V_2 ) || F_48 ( V_2 ) ||
F_49 ( V_2 ) ) {
T_2 V_244 = V_282 & V_284 ;
if ( V_244 ) {
F_134 ( & V_242 , & V_243 , V_244 ,
V_244 , V_285 ,
F_133 ) ;
F_171 ( V_2 , V_242 , V_243 ) ;
}
if ( V_282 & V_286 )
F_141 ( V_2 ) ;
} else {
T_2 V_244 = V_282 & V_287 ;
if ( V_244 ) {
F_134 ( & V_242 , & V_243 , V_244 ,
V_244 , V_288 ,
F_133 ) ;
F_171 ( V_2 , V_242 , V_243 ) ;
}
}
}
static T_9 F_172 ( int V_28 , void * V_289 )
{
struct V_42 * V_43 = V_289 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_9 V_96 = V_212 ;
if ( ! F_14 ( V_2 ) )
return V_212 ;
F_173 ( V_2 ) ;
do {
T_2 V_193 , V_197 , V_23 ;
T_2 V_270 [ V_271 ] = {} ;
T_2 V_282 = 0 ;
T_2 V_290 = 0 ;
V_197 = F_2 ( V_291 ) ;
V_23 = F_2 ( V_17 ) ;
V_193 = F_2 ( V_292 ) ;
if ( V_197 == 0 && V_23 == 0 && V_193 == 0 )
break;
V_96 = V_215 ;
F_5 ( V_293 , 0 ) ;
V_290 = F_2 ( V_294 ) ;
F_5 ( V_294 , 0 ) ;
if ( V_197 )
F_5 ( V_291 , V_197 ) ;
if ( V_23 )
F_5 ( V_17 , V_23 ) ;
if ( V_193 & V_295 )
V_282 = F_169 ( V_2 ) ;
F_163 ( V_2 , V_193 , V_270 ) ;
if ( V_193 )
F_5 ( V_292 , V_193 ) ;
F_5 ( V_294 , V_290 ) ;
F_5 ( V_293 , V_296 ) ;
F_6 ( V_293 ) ;
if ( V_197 )
F_121 ( V_2 , V_197 ) ;
if ( V_23 )
F_127 ( V_2 , V_23 ) ;
if ( V_282 )
F_170 ( V_2 , V_282 ) ;
F_165 ( V_2 , V_270 ) ;
} while ( 0 );
F_174 ( V_2 ) ;
return V_96 ;
}
static T_9 F_175 ( int V_28 , void * V_289 )
{
struct V_42 * V_43 = V_289 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_9 V_96 = V_212 ;
if ( ! F_14 ( V_2 ) )
return V_212 ;
F_173 ( V_2 ) ;
do {
T_2 V_211 , V_193 ;
T_2 V_197 [ 4 ] = {} ;
T_2 V_270 [ V_271 ] = {} ;
T_2 V_282 = 0 ;
T_2 V_290 = 0 ;
V_211 = F_2 ( V_297 ) & ~ V_298 ;
V_193 = F_2 ( V_292 ) ;
if ( V_211 == 0 && V_193 == 0 )
break;
V_96 = V_215 ;
F_5 ( V_297 , 0 ) ;
V_290 = F_2 ( V_294 ) ;
F_5 ( V_294 , 0 ) ;
F_124 ( V_2 , V_211 , V_197 ) ;
if ( V_193 & V_295 )
V_282 = F_169 ( V_2 ) ;
F_163 ( V_2 , V_193 , V_270 ) ;
if ( V_193 )
F_5 ( V_292 , V_193 ) ;
F_5 ( V_294 , V_290 ) ;
F_5 ( V_297 , V_298 ) ;
F_6 ( V_297 ) ;
F_126 ( V_2 , V_197 ) ;
if ( V_282 )
F_170 ( V_2 , V_282 ) ;
F_165 ( V_2 , V_270 ) ;
} while ( 0 );
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_176 ( struct V_1 * V_2 ,
T_2 V_244 ,
const T_2 V_246 [ V_247 ] )
{
T_2 V_245 , V_242 = 0 , V_243 = 0 ;
V_245 = F_2 ( V_299 ) ;
if ( ! V_244 ) {
T_2 V_5 = V_300 |
V_301 |
V_302 |
V_303 ;
V_245 &= ~ V_5 ;
}
F_5 ( V_299 , V_245 ) ;
if ( ! V_244 )
return;
F_134 ( & V_242 , & V_243 , V_244 ,
V_245 , V_246 ,
F_132 ) ;
F_171 ( V_2 , V_242 , V_243 ) ;
}
static void F_177 ( struct V_1 * V_2 , T_2 V_304 )
{
int V_32 ;
T_2 V_244 = V_304 & V_305 ;
F_176 ( V_2 , V_244 , V_306 ) ;
if ( V_304 & V_307 ) {
int V_227 = F_106 ( ( V_304 & V_307 ) >>
V_308 ) ;
F_71 ( L_22 ,
F_178 ( V_227 ) ) ;
}
if ( V_304 & V_309 )
F_141 ( V_2 ) ;
if ( V_304 & V_310 )
F_139 ( V_2 ) ;
if ( V_304 & V_311 )
F_71 ( L_23 ) ;
if ( V_304 & V_312 )
F_71 ( L_24 ) ;
if ( V_304 & V_313 )
F_78 ( L_25 ) ;
if ( V_304 & V_314 )
F_164 (dev_priv, pipe)
F_71 ( L_26 ,
F_44 ( V_32 ) ,
F_2 ( F_179 ( V_32 ) ) ) ;
if ( V_304 & ( V_315 | V_316 ) )
F_71 ( L_27 ) ;
if ( V_304 & ( V_317 | V_318 ) )
F_71 ( L_28 ) ;
if ( V_304 & V_319 )
F_180 ( V_2 , V_320 ) ;
if ( V_304 & V_321 )
F_180 ( V_2 , V_322 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
T_2 V_323 = F_2 ( V_324 ) ;
enum V_32 V_32 ;
if ( V_323 & V_325 )
F_78 ( L_29 ) ;
F_164 (dev_priv, pipe) {
if ( V_323 & F_182 ( V_32 ) )
F_168 ( V_2 , V_32 ) ;
if ( V_323 & F_183 ( V_32 ) ) {
if ( F_184 ( V_2 ) )
F_147 ( V_2 , V_32 ) ;
else
F_145 ( V_2 , V_32 ) ;
}
}
F_5 ( V_324 , V_323 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
T_2 V_326 = F_2 ( V_327 ) ;
if ( V_326 & V_328 )
F_78 ( L_25 ) ;
if ( V_326 & V_329 )
F_180 ( V_2 , V_320 ) ;
if ( V_326 & V_330 )
F_180 ( V_2 , V_322 ) ;
if ( V_326 & V_331 )
F_180 ( V_2 , V_332 ) ;
F_5 ( V_327 , V_326 ) ;
}
static void F_186 ( struct V_1 * V_2 , T_2 V_304 )
{
int V_32 ;
T_2 V_244 = V_304 & V_333 ;
F_176 ( V_2 , V_244 , V_334 ) ;
if ( V_304 & V_335 ) {
int V_227 = F_106 ( ( V_304 & V_335 ) >>
V_336 ) ;
F_71 ( L_30 ,
F_178 ( V_227 ) ) ;
}
if ( V_304 & V_337 )
F_141 ( V_2 ) ;
if ( V_304 & V_338 )
F_139 ( V_2 ) ;
if ( V_304 & V_339 )
F_71 ( L_31 ) ;
if ( V_304 & V_340 )
F_71 ( L_32 ) ;
if ( V_304 & V_341 )
F_164 (dev_priv, pipe)
F_71 ( L_26 ,
F_44 ( V_32 ) ,
F_2 ( F_179 ( V_32 ) ) ) ;
if ( V_304 & V_342 )
F_185 ( V_2 ) ;
}
static void F_187 ( struct V_1 * V_2 , T_2 V_304 )
{
T_2 V_244 = V_304 & V_343 &
~ V_344 ;
T_2 V_345 = V_304 & V_344 ;
T_2 V_242 = 0 , V_243 = 0 ;
if ( V_244 ) {
T_2 V_245 ;
V_245 = F_2 ( V_299 ) ;
F_5 ( V_299 , V_245 ) ;
F_134 ( & V_242 , & V_243 , V_244 ,
V_245 , V_346 ,
F_130 ) ;
}
if ( V_345 ) {
T_2 V_245 ;
V_245 = F_2 ( V_347 ) ;
F_5 ( V_347 , V_245 ) ;
F_134 ( & V_242 , & V_243 , V_345 ,
V_245 , V_346 ,
F_129 ) ;
}
if ( V_242 )
F_171 ( V_2 , V_242 , V_243 ) ;
if ( V_304 & V_338 )
F_139 ( V_2 ) ;
}
static void F_188 ( struct V_1 * V_2 ,
T_2 V_244 ,
const T_2 V_246 [ V_247 ] )
{
T_2 V_245 , V_242 = 0 , V_243 = 0 ;
V_245 = F_2 ( V_348 ) ;
F_5 ( V_348 , V_245 ) ;
F_134 ( & V_242 , & V_243 , V_244 ,
V_245 , V_246 ,
F_131 ) ;
F_171 ( V_2 , V_242 , V_243 ) ;
}
static void F_189 ( struct V_1 * V_2 ,
T_2 V_349 )
{
enum V_32 V_32 ;
T_2 V_244 = V_349 & V_350 ;
if ( V_244 )
F_188 ( V_2 , V_244 , V_351 ) ;
if ( V_349 & V_352 )
F_141 ( V_2 ) ;
if ( V_349 & V_353 )
F_190 ( V_2 ) ;
if ( V_349 & V_354 )
F_78 ( L_29 ) ;
F_164 (dev_priv, pipe) {
if ( V_349 & F_191 ( V_32 ) &&
F_160 ( V_2 , V_32 ) )
F_166 ( V_2 , V_32 ) ;
if ( V_349 & F_192 ( V_32 ) )
F_168 ( V_2 , V_32 ) ;
if ( V_349 & F_193 ( V_32 ) )
F_152 ( V_2 , V_32 ) ;
if ( V_349 & F_194 ( V_32 ) )
F_167 ( V_2 , V_32 ) ;
}
if ( V_349 & V_355 ) {
T_2 V_304 = F_2 ( V_356 ) ;
if ( F_195 ( V_2 ) )
F_186 ( V_2 , V_304 ) ;
else
F_177 ( V_2 , V_304 ) ;
F_5 ( V_356 , V_304 ) ;
}
if ( F_196 ( V_2 ) && V_349 & V_357 )
F_82 ( V_2 ) ;
}
static void F_197 ( struct V_1 * V_2 ,
T_2 V_349 )
{
enum V_32 V_32 ;
T_2 V_244 = V_349 & V_358 ;
if ( V_244 )
F_188 ( V_2 , V_244 , V_359 ) ;
if ( V_349 & V_360 )
F_181 ( V_2 ) ;
if ( V_349 & V_361 )
F_141 ( V_2 ) ;
if ( V_349 & V_362 )
F_190 ( V_2 ) ;
F_164 (dev_priv, pipe) {
if ( V_349 & ( F_198 ( V_32 ) ) &&
F_160 ( V_2 , V_32 ) )
F_166 ( V_2 , V_32 ) ;
if ( V_349 & F_199 ( V_32 ) )
F_167 ( V_2 , V_32 ) ;
}
if ( ! F_200 ( V_2 ) && ( V_349 & V_363 ) ) {
T_2 V_304 = F_2 ( V_356 ) ;
F_186 ( V_2 , V_304 ) ;
F_5 ( V_356 , V_304 ) ;
}
}
static T_9 F_201 ( int V_28 , void * V_289 )
{
struct V_42 * V_43 = V_289 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_349 , V_197 , V_364 , V_365 = 0 ;
T_9 V_96 = V_212 ;
if ( ! F_14 ( V_2 ) )
return V_212 ;
F_173 ( V_2 ) ;
V_364 = F_2 ( V_366 ) ;
F_5 ( V_366 , V_364 & ~ V_367 ) ;
F_6 ( V_366 ) ;
if ( ! F_200 ( V_2 ) ) {
V_365 = F_2 ( V_368 ) ;
F_5 ( V_368 , 0 ) ;
F_6 ( V_368 ) ;
}
V_197 = F_2 ( V_291 ) ;
if ( V_197 ) {
F_5 ( V_291 , V_197 ) ;
V_96 = V_215 ;
if ( F_53 ( V_2 ) >= 6 )
F_121 ( V_2 , V_197 ) ;
else
F_120 ( V_2 , V_197 ) ;
}
V_349 = F_2 ( V_369 ) ;
if ( V_349 ) {
F_5 ( V_369 , V_349 ) ;
V_96 = V_215 ;
if ( F_53 ( V_2 ) >= 7 )
F_197 ( V_2 , V_349 ) ;
else
F_189 ( V_2 , V_349 ) ;
}
if ( F_53 ( V_2 ) >= 6 ) {
T_2 V_23 = F_2 ( V_17 ) ;
if ( V_23 ) {
F_5 ( V_17 , V_23 ) ;
V_96 = V_215 ;
F_127 ( V_2 , V_23 ) ;
}
}
F_5 ( V_366 , V_364 ) ;
F_6 ( V_366 ) ;
if ( ! F_200 ( V_2 ) ) {
F_5 ( V_368 , V_365 ) ;
F_6 ( V_368 ) ;
}
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_202 ( struct V_1 * V_2 ,
T_2 V_244 ,
const T_2 V_246 [ V_247 ] )
{
T_2 V_245 , V_242 = 0 , V_243 = 0 ;
V_245 = F_2 ( V_299 ) ;
F_5 ( V_299 , V_245 ) ;
F_134 ( & V_242 , & V_243 , V_244 ,
V_245 , V_246 ,
F_128 ) ;
F_171 ( V_2 , V_242 , V_243 ) ;
}
static T_9
F_203 ( struct V_1 * V_2 , T_2 V_211 )
{
T_9 V_96 = V_212 ;
T_2 V_193 ;
enum V_32 V_32 ;
if ( V_211 & V_370 ) {
V_193 = F_2 ( V_371 ) ;
if ( V_193 ) {
F_5 ( V_371 , V_193 ) ;
V_96 = V_215 ;
if ( V_193 & V_372 )
F_190 ( V_2 ) ;
else
F_78 ( L_33 ) ;
}
else
F_78 ( L_34 ) ;
}
if ( V_211 & V_373 ) {
V_193 = F_2 ( V_374 ) ;
if ( V_193 ) {
T_2 V_375 ;
bool V_376 = false ;
F_5 ( V_374 , V_193 ) ;
V_96 = V_215 ;
V_375 = V_377 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_375 |= V_378 |
V_379 |
V_380 ;
if ( V_193 & V_375 ) {
F_141 ( V_2 ) ;
V_376 = true ;
}
if ( F_204 ( V_2 ) ) {
V_375 = V_193 & V_381 ;
if ( V_375 ) {
F_202 ( V_2 , V_375 ,
V_382 ) ;
V_376 = true ;
}
} else if ( F_205 ( V_2 ) ) {
V_375 = V_193 & V_383 ;
if ( V_375 ) {
F_188 ( V_2 ,
V_375 , V_384 ) ;
V_376 = true ;
}
}
if ( F_204 ( V_2 ) && ( V_193 & V_385 ) ) {
F_139 ( V_2 ) ;
V_376 = true ;
}
if ( ! V_376 )
F_78 ( L_35 ) ;
}
else
F_78 ( L_36 ) ;
}
F_164 (dev_priv, pipe) {
T_2 V_386 , V_387 ;
if ( ! ( V_211 & F_206 ( V_32 ) ) )
continue;
V_193 = F_2 ( F_207 ( V_32 ) ) ;
if ( ! V_193 ) {
F_78 ( L_37 ) ;
continue;
}
V_96 = V_215 ;
F_5 ( F_207 ( V_32 ) , V_193 ) ;
if ( V_193 & V_388 &&
F_160 ( V_2 , V_32 ) )
F_166 ( V_2 , V_32 ) ;
V_386 = V_193 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_386 &= V_389 ;
else
V_386 &= V_390 ;
if ( V_386 )
F_167 ( V_2 , V_32 ) ;
if ( V_193 & V_391 )
F_145 ( V_2 , V_32 ) ;
if ( V_193 & V_392 )
F_168 ( V_2 , V_32 ) ;
V_387 = V_193 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_387 &= V_393 ;
else
V_387 &= V_394 ;
if ( V_387 )
F_78 ( L_38 ,
F_44 ( V_32 ) ,
V_387 ) ;
}
if ( F_208 ( V_2 ) && ! F_200 ( V_2 ) &&
V_211 & V_395 ) {
V_193 = F_2 ( V_356 ) ;
if ( V_193 ) {
F_5 ( V_356 , V_193 ) ;
V_96 = V_215 ;
if ( F_209 ( V_2 ) || F_210 ( V_2 ) )
F_187 ( V_2 , V_193 ) ;
else
F_186 ( V_2 , V_193 ) ;
} else {
F_71 ( L_39 ) ;
}
}
return V_96 ;
}
static T_9 F_211 ( int V_28 , void * V_289 )
{
struct V_42 * V_43 = V_289 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_211 ;
T_2 V_197 [ 4 ] = {} ;
T_9 V_96 ;
if ( ! F_14 ( V_2 ) )
return V_212 ;
V_211 = F_65 ( V_297 ) ;
V_211 &= ~ V_298 ;
if ( ! V_211 )
return V_212 ;
F_125 ( V_297 , 0 ) ;
F_173 ( V_2 ) ;
V_96 = F_124 ( V_2 , V_211 , V_197 ) ;
F_126 ( V_2 , V_197 ) ;
V_96 |= F_203 ( V_2 , V_211 ) ;
F_125 ( V_297 , V_298 ) ;
F_17 ( V_297 ) ;
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_212 ( struct V_1 * V_2 )
{
F_140 ( & V_2 -> V_396 . V_397 ) ;
F_140 ( & V_2 -> V_398 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_399 * V_191 = & V_2 -> V_27 . V_189 -> V_190 -> V_191 ;
char * V_400 [] = { V_401 L_7 , NULL } ;
char * V_402 [] = { V_403 L_7 , NULL } ;
char * V_404 [] = { V_401 L_40 , NULL } ;
int V_96 ;
F_113 ( V_191 , V_192 , V_400 ) ;
if ( F_214 ( & V_2 -> V_396 ) ) {
F_71 ( L_41 ) ;
F_113 ( V_191 , V_192 , V_402 ) ;
F_215 ( V_2 ) ;
F_216 ( V_2 ) ;
V_96 = F_217 ( V_2 ) ;
F_218 ( V_2 ) ;
F_219 ( V_2 ) ;
if ( V_96 == 0 )
F_113 ( V_191 ,
V_192 , V_404 ) ;
F_140 ( & V_2 -> V_396 . V_405 ) ;
}
}
static void F_220 ( struct V_1 * V_2 )
{
T_3 V_406 [ V_407 ] ;
T_2 V_408 = F_2 ( V_409 ) ;
int V_32 , V_86 ;
if ( ! V_408 )
return;
F_221 ( L_42 , V_408 ) ;
F_222 ( V_2 , V_406 ) ;
if ( F_74 ( V_2 ) ) {
if ( V_408 & ( V_410 | V_411 ) ) {
T_2 V_412 = F_2 ( V_413 ) ;
F_221 ( L_43 , F_2 ( V_413 ) ) ;
F_221 ( L_44 , F_2 ( V_414 ) ) ;
for ( V_86 = 0 ; V_86 < F_223 ( V_406 ) ; V_86 ++ )
F_221 ( L_45 , V_86 , V_406 [ V_86 ] ) ;
F_221 ( L_46 , F_2 ( V_415 ) ) ;
F_221 ( L_47 , F_2 ( V_416 ) ) ;
F_5 ( V_413 , V_412 ) ;
F_6 ( V_413 ) ;
}
if ( V_408 & V_417 ) {
T_2 V_418 = F_2 ( V_419 ) ;
F_221 ( L_48 ) ;
F_221 ( L_49 , V_418 ) ;
F_5 ( V_419 , V_418 ) ;
F_6 ( V_419 ) ;
}
}
if ( ! F_64 ( V_2 ) ) {
if ( V_408 & V_420 ) {
T_2 V_418 = F_2 ( V_419 ) ;
F_221 ( L_48 ) ;
F_221 ( L_49 , V_418 ) ;
F_5 ( V_419 , V_418 ) ;
F_6 ( V_419 ) ;
}
}
if ( V_408 & V_421 ) {
F_221 ( L_50 ) ;
F_164 (dev_priv, pipe)
F_221 ( L_51 ,
F_44 ( V_32 ) , F_2 ( F_42 ( V_32 ) ) ) ;
}
if ( V_408 & V_422 ) {
F_221 ( L_52 ) ;
F_221 ( L_53 , F_2 ( V_423 ) ) ;
for ( V_86 = 0 ; V_86 < F_223 ( V_406 ) ; V_86 ++ )
F_221 ( L_45 , V_86 , V_406 [ V_86 ] ) ;
if ( F_53 ( V_2 ) < 4 ) {
T_2 V_412 = F_2 ( V_424 ) ;
F_221 ( L_43 , F_2 ( V_424 ) ) ;
F_221 ( L_44 , F_2 ( V_425 ) ) ;
F_221 ( L_47 , F_2 ( V_426 ) ) ;
F_5 ( V_424 , V_412 ) ;
F_6 ( V_424 ) ;
} else {
T_2 V_412 = F_2 ( V_413 ) ;
F_221 ( L_43 , F_2 ( V_413 ) ) ;
F_221 ( L_44 , F_2 ( V_414 ) ) ;
F_221 ( L_46 , F_2 ( V_415 ) ) ;
F_221 ( L_47 , F_2 ( V_416 ) ) ;
F_5 ( V_413 , V_412 ) ;
F_6 ( V_413 ) ;
}
}
F_5 ( V_409 , V_408 ) ;
F_6 ( V_409 ) ;
V_408 = F_2 ( V_409 ) ;
if ( V_408 ) {
F_78 ( L_54 , V_408 ) ;
F_5 ( V_427 , F_2 ( V_427 ) | V_408 ) ;
F_5 ( V_428 , V_429 ) ;
}
}
void F_224 ( struct V_1 * V_2 ,
T_2 V_430 ,
const char * V_431 , ... )
{
T_10 args ;
char V_432 [ 80 ] ;
va_start ( args , V_431 ) ;
F_225 ( V_432 , sizeof( V_432 ) , V_431 , args ) ;
va_end ( args ) ;
F_226 ( V_2 , V_430 , V_432 ) ;
F_220 ( V_2 ) ;
if ( V_430 ) {
F_227 ( V_433 ,
& V_2 -> V_396 . V_434 ) ;
F_212 ( V_2 ) ;
}
F_213 ( V_2 ) ;
}
static int F_228 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
if ( F_20 ( V_43 ) -> V_16 >= 4 )
F_47 ( V_2 , V_32 ,
V_278 ) ;
else
F_47 ( V_2 , V_32 ,
V_435 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static int F_229 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
T_3 V_436 = ( F_20 ( V_43 ) -> V_16 >= 7 ) ? F_198 ( V_32 ) :
F_191 ( V_32 ) ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_230 ( V_2 , V_436 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static int F_231 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_47 ( V_2 , V_32 ,
V_278 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static int F_232 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_233 ( V_2 , V_32 , V_388 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static void F_234 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_50 ( V_2 , V_32 ,
V_435 |
V_278 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
}
static void F_235 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
T_3 V_436 = ( F_20 ( V_43 ) -> V_16 >= 7 ) ? F_198 ( V_32 ) :
F_191 ( V_32 ) ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_236 ( V_2 , V_436 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
}
static void F_237 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_50 ( V_2 , V_32 ,
V_278 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
}
static void F_238 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_239 ( V_2 , V_32 , V_388 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
}
static bool
F_240 ( struct V_128 * V_129 , T_2 V_437 )
{
return F_241 ( V_437 ,
F_242 ( V_129 -> V_438 ) ) ;
}
static bool
F_243 ( struct V_128 * V_129 , T_2 V_439 )
{
if ( F_53 ( V_129 -> V_440 ) >= 8 ) {
return ( V_439 >> 23 ) == 0x1c ;
} else {
V_439 &= ~ V_441 ;
return V_439 == ( V_442 | V_443 |
V_444 ) ;
}
}
static struct V_128 *
F_244 ( struct V_128 * V_129 , T_2 V_439 ,
T_6 V_445 )
{
struct V_1 * V_2 = V_129 -> V_440 ;
struct V_128 * V_446 ;
if ( F_53 ( V_2 ) >= 8 ) {
F_97 (signaller, dev_priv) {
if ( V_129 == V_446 )
continue;
if ( V_445 == V_446 -> V_447 . V_448 [ V_129 -> V_449 ] )
return V_446 ;
}
} else {
T_2 V_450 = V_439 & V_441 ;
F_97 (signaller, dev_priv) {
if( V_129 == V_446 )
continue;
if ( V_450 == V_446 -> V_447 . V_451 . V_452 [ V_129 -> V_449 ] )
return V_446 ;
}
}
F_78 ( L_55 ,
V_129 -> V_449 , V_439 , V_445 ) ;
return NULL ;
}
static struct V_128 *
F_245 ( struct V_128 * V_129 , T_2 * V_437 )
{
struct V_1 * V_2 = V_129 -> V_440 ;
T_2 V_453 , V_439 , V_258 ;
T_6 V_445 = 0 ;
int V_86 , V_454 ;
if ( V_129 -> V_455 == NULL )
return NULL ;
V_439 = F_2 ( F_246 ( V_129 -> V_456 ) ) ;
if ( ! F_243 ( V_129 , V_439 ) )
return NULL ;
V_258 = F_247 ( V_129 ) & V_457 ;
V_454 = ( F_53 ( V_2 ) >= 8 ) ? 5 : 4 ;
for ( V_86 = V_454 ; V_86 ; -- V_86 ) {
V_258 &= V_129 -> V_455 -> V_458 - 1 ;
V_453 = F_248 ( V_129 -> V_455 -> V_459 + V_258 ) ;
if ( V_453 == V_439 )
break;
V_258 -= 4 ;
}
if ( ! V_86 )
return NULL ;
* V_437 = F_248 ( V_129 -> V_455 -> V_459 + V_258 + 4 ) + 1 ;
if ( F_53 ( V_2 ) >= 8 ) {
V_445 = F_248 ( V_129 -> V_455 -> V_459 + V_258 + 12 ) ;
V_445 <<= 32 ;
V_445 = F_248 ( V_129 -> V_455 -> V_459 + V_258 + 8 ) ;
}
return F_244 ( V_129 , V_439 , V_445 ) ;
}
static int F_249 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_440 ;
struct V_128 * V_446 ;
T_2 V_437 ;
V_129 -> V_460 . V_461 ++ ;
V_446 = F_245 ( V_129 , & V_437 ) ;
if ( V_446 == NULL )
return - 1 ;
if ( V_446 -> V_460 . V_461 >= V_462 )
return - 1 ;
if ( F_241 ( F_250 ( V_446 ) , V_437 ) )
return 1 ;
if ( F_251 ( V_446 ) & V_463 &&
F_249 ( V_446 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
F_97 (engine, dev_priv)
V_129 -> V_460 . V_461 = 0 ;
}
static bool F_253 ( struct V_128 * V_129 )
{
T_2 V_406 [ V_407 ] ;
bool V_464 ;
int V_86 ;
if ( V_129 -> V_449 != V_199 )
return true ;
F_222 ( V_129 -> V_440 , V_406 ) ;
V_464 = true ;
for ( V_86 = 0 ; V_86 < V_407 ; V_86 ++ ) {
const T_2 V_465 = V_406 [ V_86 ] | V_129 -> V_460 . V_406 [ V_86 ] ;
if ( V_465 != V_129 -> V_460 . V_406 [ V_86 ] )
V_464 = false ;
V_129 -> V_460 . V_406 [ V_86 ] |= V_465 ;
}
return V_464 ;
}
static enum V_466
F_254 ( struct V_128 * V_129 , T_6 V_467 )
{
if ( V_467 != V_129 -> V_460 . V_467 ) {
memset ( V_129 -> V_460 . V_406 , 0 ,
sizeof( V_129 -> V_460 . V_406 ) ) ;
return V_468 ;
}
if ( ! F_253 ( V_129 ) )
return V_468 ;
return V_469 ;
}
static enum V_466
F_255 ( struct V_128 * V_129 , T_6 V_467 )
{
struct V_1 * V_2 = V_129 -> V_440 ;
enum V_466 V_470 ;
T_2 V_465 ;
V_470 = F_254 ( V_129 , V_467 ) ;
if ( V_470 != V_469 )
return V_470 ;
if ( F_64 ( V_2 ) )
return V_469 ;
V_465 = F_251 ( V_129 ) ;
if ( V_465 & V_471 ) {
F_224 ( V_2 , 0 ,
L_56 ,
V_129 -> V_472 ) ;
F_256 ( V_129 , V_465 ) ;
return V_473 ;
}
if ( F_53 ( V_2 ) >= 6 && V_465 & V_463 ) {
switch ( F_249 ( V_129 ) ) {
default:
return V_469 ;
case 1 :
F_224 ( V_2 , 0 ,
L_57 ,
V_129 -> V_472 ) ;
F_256 ( V_129 , V_465 ) ;
return V_473 ;
case 0 :
return V_474 ;
}
}
return V_469 ;
}
static unsigned long F_257 ( struct V_128 * V_129 )
{
struct V_1 * V_440 = V_129 -> V_440 ;
unsigned long V_475 = F_242 ( V_129 -> V_130 . V_132 ) ;
if ( V_129 -> V_460 . V_476 == V_475 &&
! F_258 ( V_129 -> V_449 , & V_440 -> V_396 . V_477 ) ) {
if ( ! F_259 ( V_129 -> V_449 , & V_440 -> V_396 . V_478 ) )
F_78 ( L_58 ,
V_129 -> V_472 ) ;
F_260 ( V_129 ) ;
}
return V_475 ;
}
static void F_261 ( struct V_159 * V_29 )
{
struct V_1 * V_2 =
F_100 ( V_29 , F_262 ( * V_2 ) ,
V_396 . V_479 . V_29 ) ;
struct V_128 * V_129 ;
unsigned int V_480 = 0 , V_464 = 0 ;
int V_481 = 0 ;
#define F_263 1
#define F_264 5
#define F_265 20
#define F_266 15
if ( ! V_440 . V_482 )
return;
if ( ! F_242 ( V_2 -> V_483 . V_484 ) )
return;
F_267 ( V_2 ) ;
F_97 (engine, dev_priv) {
bool V_485 = F_98 ( V_129 ) ;
T_6 V_467 ;
T_2 V_437 ;
unsigned V_476 ;
F_252 ( V_2 ) ;
if ( V_129 -> V_486 )
V_129 -> V_486 ( V_129 ) ;
V_467 = F_268 ( V_129 ) ;
V_437 = F_250 ( V_129 ) ;
V_476 = 0 ;
if ( V_129 -> V_460 . V_437 == V_437 ) {
if ( F_240 ( V_129 , V_437 ) ) {
V_129 -> V_460 . V_487 = V_488 ;
if ( V_485 ) {
V_476 = F_257 ( V_129 ) ;
V_129 -> V_460 . V_489 += F_263 ;
}
} else {
V_129 -> V_460 . V_487 = F_255 ( V_129 ,
V_467 ) ;
switch ( V_129 -> V_460 . V_487 ) {
case V_488 :
case V_474 :
break;
case V_468 :
V_129 -> V_460 . V_489 += F_263 ;
break;
case V_473 :
V_129 -> V_460 . V_489 += F_264 ;
break;
case V_469 :
V_129 -> V_460 . V_489 += F_265 ;
break;
}
}
if ( V_129 -> V_460 . V_489 >= V_490 ) {
V_480 |= F_269 ( V_129 ) ;
if ( V_129 -> V_460 . V_487 != V_469 )
V_464 |= F_269 ( V_129 ) ;
}
} else {
V_129 -> V_460 . V_487 = V_468 ;
if ( V_129 -> V_460 . V_489 > 0 )
V_129 -> V_460 . V_489 -= F_266 ;
if ( V_129 -> V_460 . V_489 < 0 )
V_129 -> V_460 . V_489 = 0 ;
V_467 = 0 ;
memset ( V_129 -> V_460 . V_406 , 0 ,
sizeof( V_129 -> V_460 . V_406 ) ) ;
}
V_129 -> V_460 . V_437 = V_437 ;
V_129 -> V_460 . V_467 = V_467 ;
V_129 -> V_460 . V_476 = V_476 ;
V_481 += V_485 ;
}
if ( V_480 ) {
char V_491 [ 80 ] ;
int V_492 ;
if ( V_464 != V_480 )
V_480 &= ~ V_464 ;
V_492 = F_270 ( V_491 , sizeof( V_491 ) ,
L_59 , V_464 == V_480 ? L_60 : L_61 ) ;
F_271 (engine, dev_priv, hung)
V_492 += F_270 ( V_491 + V_492 , sizeof( V_491 ) - V_492 ,
L_62 , V_129 -> V_472 ) ;
V_491 [ V_492 - 2 ] = '\0' ;
return F_224 ( V_2 , V_480 , V_491 ) ;
}
if ( V_481 )
F_272 ( V_2 ) ;
}
static void F_273 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( F_200 ( V_43 ) )
return;
F_274 ( V_493 ) ;
if ( F_195 ( V_43 ) || F_275 ( V_43 ) )
F_5 ( V_327 , 0xffffffff ) ;
}
static void F_276 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( F_200 ( V_43 ) )
return;
F_9 ( F_2 ( V_368 ) != 0 ) ;
F_5 ( V_368 , 0xffffffff ) ;
F_6 ( V_368 ) ;
}
static void F_277 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_274 ( V_494 ) ;
if ( F_20 ( V_43 ) -> V_16 >= 6 )
F_274 ( V_495 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
enum V_32 V_32 ;
if ( F_49 ( V_2 ) )
F_5 ( V_496 , V_497 ) ;
else
F_5 ( V_496 , V_498 ) ;
F_7 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_283 , F_2 ( V_283 ) ) ;
F_164 (dev_priv, pipe) {
F_5 ( F_42 ( V_32 ) ,
V_46 |
V_40 ) ;
V_2 -> V_41 [ V_32 ] = 0 ;
}
F_274 ( V_499 ) ;
V_2 -> V_12 = ~ 0 ;
}
static void F_279 ( struct V_1 * V_2 )
{
T_2 V_500 ;
T_2 V_36 ;
enum V_32 V_32 ;
V_500 = V_279 |
V_280 ;
F_47 ( V_2 , V_55 , V_281 ) ;
F_164 (dev_priv, pipe)
F_47 ( V_2 , V_32 , V_500 ) ;
V_36 = V_295 |
V_274 |
V_275 ;
if ( F_49 ( V_2 ) )
V_36 |= V_277 ;
F_9 ( V_2 -> V_12 != ~ 0 ) ;
V_2 -> V_12 = ~ V_36 ;
F_280 ( V_499 , V_2 -> V_12 , V_36 ) ;
}
static void F_281 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_5 ( V_501 , 0xffffffff ) ;
F_274 ( V_502 ) ;
if ( F_282 ( V_43 ) )
F_5 ( V_324 , 0xffffffff ) ;
F_277 ( V_43 ) ;
F_273 ( V_43 ) ;
}
static void F_283 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_5 ( V_293 , 0 ) ;
F_6 ( V_293 ) ;
F_277 ( V_43 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_272 )
F_278 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_284 ( struct V_1 * V_2 )
{
F_285 ( V_494 , 0 ) ;
F_285 ( V_494 , 1 ) ;
F_285 ( V_494 , 2 ) ;
F_285 ( V_494 , 3 ) ;
}
static void F_286 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
F_5 ( V_297 , 0 ) ;
F_6 ( V_297 ) ;
F_284 ( V_2 ) ;
F_164 (dev_priv, pipe)
if ( F_287 ( V_2 ,
F_288 ( V_32 ) ) )
F_285 ( V_503 , V_32 ) ;
F_274 ( V_504 ) ;
F_274 ( V_505 ) ;
F_274 ( V_506 ) ;
if ( F_208 ( V_43 ) )
F_273 ( V_43 ) ;
}
void F_289 ( struct V_1 * V_2 ,
unsigned int V_507 )
{
T_3 V_508 = V_388 | V_392 ;
enum V_32 V_32 ;
F_11 ( & V_2 -> V_7 ) ;
F_290 (dev_priv, pipe, pipe_mask)
F_291 ( V_503 , V_32 ,
V_2 -> V_33 [ V_32 ] ,
~ V_2 -> V_33 [ V_32 ] | V_508 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_292 ( struct V_1 * V_2 ,
unsigned int V_507 )
{
enum V_32 V_32 ;
F_11 ( & V_2 -> V_7 ) ;
F_290 (dev_priv, pipe, pipe_mask)
F_285 ( V_503 , V_32 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_35 ( V_2 -> V_27 . V_28 ) ;
}
static void F_293 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_5 ( V_297 , 0 ) ;
F_6 ( V_297 ) ;
F_284 ( V_2 ) ;
F_274 ( V_506 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_272 )
F_278 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static T_2 F_294 ( struct V_1 * V_2 ,
const T_2 V_246 [ V_247 ] )
{
struct V_509 * V_510 ;
T_2 V_511 = 0 ;
F_295 (&dev_priv->drm, encoder)
if ( V_2 -> V_512 . V_513 [ V_510 -> V_514 ] . V_515 == V_516 )
V_511 |= V_246 [ V_510 -> V_514 ] ;
return V_511 ;
}
static void F_296 ( struct V_1 * V_2 )
{
T_2 V_517 , V_512 , V_511 ;
if ( F_297 ( V_2 ) ) {
V_517 = V_305 ;
V_511 = F_294 ( V_2 , V_306 ) ;
} else {
V_517 = V_333 ;
V_511 = F_294 ( V_2 , V_334 ) ;
}
F_40 ( V_2 , V_517 , V_511 ) ;
V_512 = F_2 ( V_299 ) ;
V_512 &= ~ ( V_518 | V_519 | V_520 ) ;
V_512 |= V_521 | V_522 ;
V_512 |= V_523 | V_524 ;
V_512 |= V_525 | V_526 ;
if ( F_298 ( V_2 ) )
V_512 |= V_527 ;
F_5 ( V_299 , V_512 ) ;
}
static void F_299 ( struct V_1 * V_2 )
{
T_2 V_517 , V_512 , V_511 ;
V_517 = V_343 ;
V_511 = F_294 ( V_2 , V_346 ) ;
F_40 ( V_2 , V_517 , V_511 ) ;
V_512 = F_2 ( V_299 ) ;
V_512 |= V_521 | V_523 |
V_525 | V_527 ;
F_5 ( V_299 , V_512 ) ;
V_512 = F_2 ( V_347 ) ;
V_512 |= V_528 ;
F_5 ( V_347 , V_512 ) ;
}
static void F_300 ( struct V_1 * V_2 )
{
T_2 V_517 , V_512 , V_511 ;
if ( F_53 ( V_2 ) >= 8 ) {
V_517 = V_383 ;
V_511 = F_294 ( V_2 , V_384 ) ;
F_37 ( V_2 , V_517 , V_511 ) ;
} else if ( F_53 ( V_2 ) >= 7 ) {
V_517 = V_358 ;
V_511 = F_294 ( V_2 , V_359 ) ;
F_13 ( V_2 , V_517 , V_511 ) ;
} else {
V_517 = V_350 ;
V_511 = F_294 ( V_2 , V_351 ) ;
F_13 ( V_2 , V_517 , V_511 ) ;
}
V_512 = F_2 ( V_348 ) ;
V_512 &= ~ V_529 ;
V_512 |= V_530 | V_531 ;
F_5 ( V_348 , V_512 ) ;
F_296 ( V_2 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
T_2 V_517 , V_512 , V_511 ;
V_511 = F_294 ( V_2 , V_382 ) ;
V_517 = V_381 ;
F_37 ( V_2 , V_517 , V_511 ) ;
V_512 = F_2 ( V_299 ) ;
V_512 |= V_523 | V_525 |
V_527 ;
F_80 ( L_63 ,
V_512 , V_511 ) ;
V_512 &= ~ V_532 ;
if ( ( V_511 & V_533 ) &&
F_302 ( V_2 , V_228 ) )
V_512 |= V_534 ;
if ( ( V_511 & V_535 ) &&
F_302 ( V_2 , V_230 ) )
V_512 |= V_536 ;
if ( ( V_511 & V_537 ) &&
F_302 ( V_2 , V_232 ) )
V_512 |= V_538 ;
F_5 ( V_299 , V_512 ) ;
}
static void F_303 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_5 ;
if ( F_200 ( V_43 ) )
return;
if ( F_297 ( V_43 ) )
V_5 = V_310 | V_309 | V_313 ;
else
V_5 = V_338 | V_337 ;
F_1 ( V_2 , V_356 ) ;
F_5 ( V_35 , ~ V_5 ) ;
}
static void F_304 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_539 , V_540 ;
V_539 = V_540 = 0 ;
V_2 -> V_14 = ~ 0 ;
if ( F_118 ( V_43 ) ) {
V_2 -> V_14 = ~ F_116 ( V_43 ) ;
V_540 |= F_116 ( V_43 ) ;
}
V_540 |= V_198 ;
if ( F_196 ( V_43 ) ) {
V_540 |= V_200 ;
} else {
V_540 |= V_203 | V_202 ;
}
F_280 ( V_494 , V_2 -> V_14 , V_540 ) ;
if ( F_20 ( V_43 ) -> V_16 >= 6 ) {
if ( F_159 ( V_43 ) )
V_539 |= V_268 ;
V_2 -> V_20 = 0xffffffff ;
F_280 ( V_495 , V_2 -> V_20 , V_539 ) ;
}
}
static int F_305 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_541 , V_542 ;
if ( F_20 ( V_43 ) -> V_16 >= 7 ) {
V_541 = ( V_367 | V_362 |
V_363 | V_543 |
V_544 |
V_545 | V_361 ) ;
V_542 = ( V_546 | V_547 |
V_548 | V_360 |
V_358 ) ;
} else {
V_541 = ( V_367 | V_353 | V_355 |
V_549 | V_550 |
V_352 |
V_551 | V_552 |
V_354 ) ;
V_542 = ( V_553 | V_554 | V_357 |
V_555 | V_556 |
V_350 ) ;
}
V_2 -> V_12 = ~ V_541 ;
F_5 ( V_501 , 0xeffe ) ;
F_276 ( V_43 ) ;
F_280 ( V_502 , V_2 -> V_12 , V_541 | V_542 ) ;
F_304 ( V_43 ) ;
F_303 ( V_43 ) ;
if ( F_306 ( V_43 ) ) {
F_11 ( & V_2 -> V_7 ) ;
F_230 ( V_2 , V_357 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
return 0 ;
}
void F_307 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_272 )
return;
V_2 -> V_272 = true ;
if ( F_14 ( V_2 ) ) {
F_278 ( V_2 ) ;
F_279 ( V_2 ) ;
}
}
void F_308 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_272 )
return;
V_2 -> V_272 = false ;
if ( F_14 ( V_2 ) )
F_278 ( V_2 ) ;
}
static int F_309 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_304 ( V_43 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_272 )
F_279 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_5 ( V_293 , V_296 ) ;
F_6 ( V_293 ) ;
return 0 ;
}
static void F_310 ( struct V_1 * V_2 )
{
T_3 V_557 [] = {
V_198 << V_220 |
V_209 << V_220 |
V_198 << V_221 |
V_209 << V_221 ,
V_198 << V_222 |
V_209 << V_222 |
V_198 << V_224 |
V_209 << V_224 ,
0 ,
V_198 << V_226 |
V_209 << V_226
} ;
if ( F_118 ( V_2 ) )
V_557 [ 0 ] |= V_195 ;
V_2 -> V_20 = 0xffffffff ;
F_291 ( V_494 , 0 , ~ V_557 [ 0 ] , V_557 [ 0 ] ) ;
F_291 ( V_494 , 1 , ~ V_557 [ 1 ] , V_557 [ 1 ] ) ;
F_291 ( V_494 , 2 , V_2 -> V_20 , 0 ) ;
F_291 ( V_494 , 3 , ~ V_557 [ 3 ] , V_557 [ 3 ] ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
T_3 V_558 = V_391 ;
T_3 V_559 ;
T_2 V_560 = V_377 ;
T_2 V_561 ;
T_2 V_562 = V_372 ;
enum V_32 V_32 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 ) {
V_558 |= V_389 |
V_393 ;
V_560 |= V_378 | V_379 |
V_380 ;
if ( F_204 ( V_2 ) )
V_560 |= V_385 ;
} else {
V_558 |= V_390 |
V_394 ;
}
V_559 = V_558 | V_388 |
V_392 ;
V_561 = V_560 ;
if ( F_204 ( V_2 ) )
V_561 |= V_381 ;
else if ( F_205 ( V_2 ) )
V_561 |= V_383 ;
V_2 -> V_33 [ V_55 ] = ~ V_558 ;
V_2 -> V_33 [ V_53 ] = ~ V_558 ;
V_2 -> V_33 [ V_276 ] = ~ V_558 ;
F_164 (dev_priv, pipe)
if ( F_287 ( V_2 ,
F_288 ( V_32 ) ) )
F_291 ( V_503 , V_32 ,
V_2 -> V_33 [ V_32 ] ,
V_559 ) ;
F_280 ( V_504 , ~ V_560 , V_561 ) ;
F_280 ( V_505 , ~ V_562 , V_562 ) ;
}
static int F_312 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( F_208 ( V_43 ) )
F_276 ( V_43 ) ;
F_310 ( V_2 ) ;
F_311 ( V_2 ) ;
if ( F_208 ( V_43 ) )
F_303 ( V_43 ) ;
F_5 ( V_297 , V_298 ) ;
F_6 ( V_297 ) ;
return 0 ;
}
static int F_313 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_310 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_272 )
F_279 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_5 ( V_297 , V_298 ) ;
F_6 ( V_297 ) ;
return 0 ;
}
static void F_314 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( ! V_2 )
return;
F_286 ( V_43 ) ;
}
static void F_315 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( ! V_2 )
return;
F_5 ( V_293 , 0 ) ;
F_6 ( V_293 ) ;
F_277 ( V_43 ) ;
F_5 ( V_501 , 0xffffffff ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_272 )
F_278 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_316 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( ! V_2 )
return;
F_5 ( V_297 , 0 ) ;
F_6 ( V_297 ) ;
F_284 ( V_2 ) ;
F_274 ( V_506 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_272 )
F_278 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_317 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( ! V_2 )
return;
F_281 ( V_43 ) ;
}
static void F_318 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
F_164 (dev_priv, pipe)
F_5 ( F_42 ( V_32 ) , 0 ) ;
F_84 ( V_563 , 0xffff ) ;
F_84 ( V_564 , 0x0 ) ;
F_319 ( V_564 ) ;
}
static int F_320 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_84 ( V_427 ,
~ ( V_420 | V_421 ) ) ;
V_2 -> V_12 =
~ ( V_274 |
V_275 |
V_565 |
V_566 ) ;
F_84 ( V_563 , V_2 -> V_12 ) ;
F_84 ( V_564 ,
V_274 |
V_275 |
V_567 ) ;
F_319 ( V_564 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_47 ( V_2 , V_55 , V_280 ) ;
F_47 ( V_2 , V_53 , V_280 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_321 ( struct V_1 * V_2 ,
int V_568 , int V_32 , T_2 V_193 )
{
T_11 V_569 = F_322 ( V_568 ) ;
if ( ! F_160 ( V_2 , V_32 ) )
return false ;
if ( ( V_193 & V_569 ) == 0 )
goto V_570;
if ( F_323 ( V_571 ) & V_569 )
goto V_570;
F_167 ( V_2 , V_32 ) ;
return true ;
V_570:
F_166 ( V_2 , V_32 ) ;
return false ;
}
static T_9 F_324 ( int V_28 , void * V_289 )
{
struct V_42 * V_43 = V_289 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_11 V_193 , V_572 ;
T_2 V_270 [ 2 ] ;
int V_32 ;
T_11 V_573 =
V_565 |
V_566 ;
T_9 V_96 ;
if ( ! F_14 ( V_2 ) )
return V_212 ;
F_173 ( V_2 ) ;
V_96 = V_212 ;
V_193 = F_323 ( V_428 ) ;
if ( V_193 == 0 )
goto V_182;
while ( V_193 & ~ V_573 ) {
F_83 ( & V_2 -> V_7 ) ;
if ( V_193 & V_429 )
F_114 ( L_64 , V_193 ) ;
F_164 (dev_priv, pipe) {
T_1 V_3 = F_42 ( V_32 ) ;
V_270 [ V_32 ] = F_2 ( V_3 ) ;
if ( V_270 [ V_32 ] & 0x8000ffff )
F_5 ( V_3 , V_270 [ V_32 ] ) ;
}
F_86 ( & V_2 -> V_7 ) ;
F_84 ( V_428 , V_193 & ~ V_573 ) ;
V_572 = F_323 ( V_428 ) ;
if ( V_193 & V_567 )
F_87 ( & V_2 -> V_129 [ V_199 ] ) ;
F_164 (dev_priv, pipe) {
int V_568 = V_32 ;
if ( F_325 ( V_2 ) )
V_568 = ! V_568 ;
if ( V_270 [ V_32 ] & V_435 &&
F_321 ( V_2 , V_568 , V_32 , V_193 ) )
V_573 &= ~ F_322 ( V_568 ) ;
if ( V_270 [ V_32 ] & V_280 )
F_152 ( V_2 , V_32 ) ;
if ( V_270 [ V_32 ] & V_46 )
F_168 ( V_2 ,
V_32 ) ;
}
V_193 = V_572 ;
}
V_96 = V_215 ;
V_182:
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_326 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
F_164 (dev_priv, pipe) {
F_5 ( F_42 ( V_32 ) , 0 ) ;
F_5 ( F_42 ( V_32 ) , F_2 ( F_42 ( V_32 ) ) ) ;
}
F_84 ( V_563 , 0xffff ) ;
F_84 ( V_564 , 0x0 ) ;
F_84 ( V_428 , F_323 ( V_428 ) ) ;
}
static void F_327 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
if ( F_328 ( V_43 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_283 , F_2 ( V_283 ) ) ;
}
F_84 ( V_501 , 0xeffe ) ;
F_164 (dev_priv, pipe)
F_5 ( F_42 ( V_32 ) , 0 ) ;
F_5 ( V_563 , 0xffffffff ) ;
F_5 ( V_564 , 0x0 ) ;
F_6 ( V_564 ) ;
}
static int F_329 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_36 ;
F_5 ( V_427 , ~ ( V_420 | V_421 ) ) ;
V_2 -> V_12 =
~ ( V_574 |
V_274 |
V_275 |
V_565 |
V_566 ) ;
V_36 =
V_574 |
V_274 |
V_275 |
V_567 ;
if ( F_328 ( V_43 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
V_36 |= V_295 ;
V_2 -> V_12 &= ~ V_295 ;
}
F_5 ( V_563 , V_2 -> V_12 ) ;
F_5 ( V_564 , V_36 ) ;
F_6 ( V_564 ) ;
F_51 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_47 ( V_2 , V_55 , V_280 ) ;
F_47 ( V_2 , V_53 , V_280 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_330 ( struct V_1 * V_2 ,
int V_568 , int V_32 , T_2 V_193 )
{
T_2 V_569 = F_322 ( V_568 ) ;
if ( ! F_160 ( V_2 , V_32 ) )
return false ;
if ( ( V_193 & V_569 ) == 0 )
goto V_570;
if ( F_2 ( V_571 ) & V_569 )
goto V_570;
F_167 ( V_2 , V_32 ) ;
return true ;
V_570:
F_166 ( V_2 , V_32 ) ;
return false ;
}
static T_9 F_331 ( int V_28 , void * V_289 )
{
struct V_42 * V_43 = V_289 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_193 , V_572 , V_270 [ V_271 ] ;
T_2 V_573 =
V_565 |
V_566 ;
int V_32 , V_96 = V_212 ;
if ( ! F_14 ( V_2 ) )
return V_212 ;
F_173 ( V_2 ) ;
V_193 = F_2 ( V_428 ) ;
do {
bool V_575 = ( V_193 & ~ V_573 ) != 0 ;
bool V_576 = false ;
F_83 ( & V_2 -> V_7 ) ;
if ( V_193 & V_429 )
F_114 ( L_64 , V_193 ) ;
F_164 (dev_priv, pipe) {
T_1 V_3 = F_42 ( V_32 ) ;
V_270 [ V_32 ] = F_2 ( V_3 ) ;
if ( V_270 [ V_32 ] & 0x8000ffff ) {
F_5 ( V_3 , V_270 [ V_32 ] ) ;
V_575 = true ;
}
}
F_86 ( & V_2 -> V_7 ) ;
if ( ! V_575 )
break;
if ( F_328 ( V_2 ) &&
V_193 & V_295 ) {
T_2 V_282 = F_169 ( V_2 ) ;
if ( V_282 )
F_170 ( V_2 , V_282 ) ;
}
F_5 ( V_428 , V_193 & ~ V_573 ) ;
V_572 = F_2 ( V_428 ) ;
if ( V_193 & V_567 )
F_87 ( & V_2 -> V_129 [ V_199 ] ) ;
F_164 (dev_priv, pipe) {
int V_568 = V_32 ;
if ( F_325 ( V_2 ) )
V_568 = ! V_568 ;
if ( V_270 [ V_32 ] & V_435 &&
F_330 ( V_2 , V_568 , V_32 , V_193 ) )
V_573 &= ~ F_322 ( V_568 ) ;
if ( V_270 [ V_32 ] & V_54 )
V_576 = true ;
if ( V_270 [ V_32 ] & V_280 )
F_152 ( V_2 , V_32 ) ;
if ( V_270 [ V_32 ] & V_46 )
F_168 ( V_2 ,
V_32 ) ;
}
if ( V_576 || ( V_193 & V_574 ) )
F_190 ( V_2 ) ;
V_96 = V_215 ;
V_193 = V_572 ;
} while ( V_193 & ~ V_573 );
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_332 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
if ( F_328 ( V_43 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_283 , F_2 ( V_283 ) ) ;
}
F_84 ( V_501 , 0xffff ) ;
F_164 (dev_priv, pipe) {
F_5 ( F_42 ( V_32 ) , 0 ) ;
F_5 ( F_42 ( V_32 ) , F_2 ( F_42 ( V_32 ) ) ) ;
}
F_5 ( V_563 , 0xffffffff ) ;
F_5 ( V_564 , 0x0 ) ;
F_5 ( V_428 , F_2 ( V_428 ) ) ;
}
static void F_333 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_283 , F_2 ( V_283 ) ) ;
F_5 ( V_501 , 0xeffe ) ;
F_164 (dev_priv, pipe)
F_5 ( F_42 ( V_32 ) , 0 ) ;
F_5 ( V_563 , 0xffffffff ) ;
F_5 ( V_564 , 0x0 ) ;
F_6 ( V_564 ) ;
}
static int F_334 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_36 ;
T_2 V_577 ;
V_2 -> V_12 = ~ ( V_574 |
V_295 |
V_274 |
V_275 |
V_565 |
V_566 |
V_429 ) ;
V_36 = ~ V_2 -> V_12 ;
V_36 &= ~ ( V_565 |
V_566 ) ;
V_36 |= V_567 ;
if ( F_74 ( V_2 ) )
V_36 |= V_578 ;
F_11 ( & V_2 -> V_7 ) ;
F_47 ( V_2 , V_55 , V_281 ) ;
F_47 ( V_2 , V_55 , V_280 ) ;
F_47 ( V_2 , V_53 , V_280 ) ;
F_12 ( & V_2 -> V_7 ) ;
if ( F_74 ( V_2 ) ) {
V_577 = ~ ( V_417 |
V_410 |
V_411 |
V_421 ) ;
} else {
V_577 = ~ ( V_420 |
V_421 ) ;
}
F_5 ( V_427 , V_577 ) ;
F_5 ( V_563 , V_2 -> V_12 ) ;
F_5 ( V_564 , V_36 ) ;
F_6 ( V_564 ) ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static void F_335 ( struct V_1 * V_2 )
{
T_2 V_579 ;
F_8 ( & V_2 -> V_7 ) ;
V_579 = F_294 ( V_2 , V_580 ) ;
if ( F_74 ( V_2 ) )
V_579 |= V_581 ;
V_579 |= V_582 ;
F_7 ( V_2 ,
V_583 |
V_584 |
V_581 ,
V_579 ) ;
}
static T_9 F_336 ( int V_28 , void * V_289 )
{
struct V_42 * V_43 = V_289 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_193 , V_572 ;
T_2 V_270 [ V_271 ] ;
int V_96 = V_212 , V_32 ;
T_2 V_573 =
V_565 |
V_566 ;
if ( ! F_14 ( V_2 ) )
return V_212 ;
F_173 ( V_2 ) ;
V_193 = F_2 ( V_428 ) ;
for (; ; ) {
bool V_575 = ( V_193 & ~ V_573 ) != 0 ;
bool V_576 = false ;
F_83 ( & V_2 -> V_7 ) ;
if ( V_193 & V_429 )
F_114 ( L_64 , V_193 ) ;
F_164 (dev_priv, pipe) {
T_1 V_3 = F_42 ( V_32 ) ;
V_270 [ V_32 ] = F_2 ( V_3 ) ;
if ( V_270 [ V_32 ] & 0x8000ffff ) {
F_5 ( V_3 , V_270 [ V_32 ] ) ;
V_575 = true ;
}
}
F_86 ( & V_2 -> V_7 ) ;
if ( ! V_575 )
break;
V_96 = V_215 ;
if ( V_193 & V_295 ) {
T_2 V_282 = F_169 ( V_2 ) ;
if ( V_282 )
F_170 ( V_2 , V_282 ) ;
}
F_5 ( V_428 , V_193 & ~ V_573 ) ;
V_572 = F_2 ( V_428 ) ;
if ( V_193 & V_567 )
F_87 ( & V_2 -> V_129 [ V_199 ] ) ;
if ( V_193 & V_578 )
F_87 ( & V_2 -> V_129 [ V_201 ] ) ;
F_164 (dev_priv, pipe) {
if ( V_270 [ V_32 ] & V_278 &&
F_330 ( V_2 , V_32 , V_32 , V_193 ) )
V_573 &= ~ F_322 ( V_32 ) ;
if ( V_270 [ V_32 ] & V_54 )
V_576 = true ;
if ( V_270 [ V_32 ] & V_280 )
F_152 ( V_2 , V_32 ) ;
if ( V_270 [ V_32 ] & V_46 )
F_168 ( V_2 , V_32 ) ;
}
if ( V_576 || ( V_193 & V_574 ) )
F_190 ( V_2 ) ;
if ( V_270 [ 0 ] & V_281 )
F_139 ( V_2 ) ;
V_193 = V_572 ;
}
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_337 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
if ( ! V_2 )
return;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_283 , F_2 ( V_283 ) ) ;
F_5 ( V_501 , 0xffffffff ) ;
F_164 (dev_priv, pipe)
F_5 ( F_42 ( V_32 ) , 0 ) ;
F_5 ( V_563 , 0xffffffff ) ;
F_5 ( V_564 , 0x0 ) ;
F_164 (dev_priv, pipe)
F_5 ( F_42 ( V_32 ) ,
F_2 ( F_42 ( V_32 ) ) & 0x8000ffff ) ;
F_5 ( V_428 , F_2 ( V_428 ) ) ;
}
void F_338 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = & V_2 -> V_27 ;
F_339 ( V_2 ) ;
F_340 ( & V_2 -> V_22 . V_29 , F_99 ) ;
F_340 ( & V_2 -> V_171 . V_172 , F_105 ) ;
if ( F_48 ( V_2 ) )
V_2 -> V_21 = V_153 | V_154 ;
else
V_2 -> V_21 = V_585 ;
V_2 -> V_22 . V_25 = 0 ;
if ( F_20 ( V_2 ) -> V_16 <= 7 && ! F_341 ( V_2 ) )
V_2 -> V_22 . V_25 |= V_154 ;
if ( F_20 ( V_2 ) -> V_16 >= 8 )
V_2 -> V_22 . V_25 |= V_586 ;
F_342 ( & V_2 -> V_396 . V_479 ,
F_261 ) ;
if ( F_64 ( V_2 ) ) {
V_43 -> V_587 = 0 ;
V_43 -> V_263 -> V_264 = F_54 ;
} else if ( F_74 ( V_2 ) || F_20 ( V_2 ) -> V_16 >= 5 ) {
V_43 -> V_587 = 0xffffffff ;
V_43 -> V_263 -> V_264 = F_61 ;
} else {
V_43 -> V_263 -> V_264 = F_55 ;
V_43 -> V_587 = 0xffffff ;
}
if ( ! F_64 ( V_2 ) )
V_43 -> V_588 = true ;
V_43 -> V_263 -> V_589 = F_77 ;
V_43 -> V_263 -> V_590 = F_70 ;
if ( F_49 ( V_2 ) ) {
V_43 -> V_263 -> V_591 = F_175 ;
V_43 -> V_263 -> V_592 = F_293 ;
V_43 -> V_263 -> V_593 = F_313 ;
V_43 -> V_263 -> V_594 = F_316 ;
V_43 -> V_263 -> V_595 = F_231 ;
V_43 -> V_263 -> V_596 = F_237 ;
V_2 -> V_597 . V_598 = F_335 ;
} else if ( F_48 ( V_2 ) ) {
V_43 -> V_263 -> V_591 = F_172 ;
V_43 -> V_263 -> V_592 = F_283 ;
V_43 -> V_263 -> V_593 = F_309 ;
V_43 -> V_263 -> V_594 = F_315 ;
V_43 -> V_263 -> V_595 = F_231 ;
V_43 -> V_263 -> V_596 = F_237 ;
V_2 -> V_597 . V_598 = F_335 ;
} else if ( F_20 ( V_2 ) -> V_16 >= 8 ) {
V_43 -> V_263 -> V_591 = F_211 ;
V_43 -> V_263 -> V_592 = F_286 ;
V_43 -> V_263 -> V_593 = F_312 ;
V_43 -> V_263 -> V_594 = F_314 ;
V_43 -> V_263 -> V_595 = F_232 ;
V_43 -> V_263 -> V_596 = F_238 ;
if ( F_204 ( V_43 ) )
V_2 -> V_597 . V_598 = F_301 ;
else if ( F_209 ( V_43 ) || F_210 ( V_43 ) )
V_2 -> V_597 . V_598 = F_299 ;
else
V_2 -> V_597 . V_598 = F_300 ;
} else if ( F_208 ( V_43 ) ) {
V_43 -> V_263 -> V_591 = F_201 ;
V_43 -> V_263 -> V_592 = F_281 ;
V_43 -> V_263 -> V_593 = F_305 ;
V_43 -> V_263 -> V_594 = F_317 ;
V_43 -> V_263 -> V_595 = F_229 ;
V_43 -> V_263 -> V_596 = F_235 ;
V_2 -> V_597 . V_598 = F_300 ;
} else {
if ( F_64 ( V_2 ) ) {
V_43 -> V_263 -> V_592 = F_318 ;
V_43 -> V_263 -> V_593 = F_320 ;
V_43 -> V_263 -> V_591 = F_324 ;
V_43 -> V_263 -> V_594 = F_326 ;
} else if ( F_343 ( V_2 ) ) {
V_43 -> V_263 -> V_592 = F_327 ;
V_43 -> V_263 -> V_593 = F_329 ;
V_43 -> V_263 -> V_594 = F_332 ;
V_43 -> V_263 -> V_591 = F_331 ;
} else {
V_43 -> V_263 -> V_592 = F_333 ;
V_43 -> V_263 -> V_593 = F_334 ;
V_43 -> V_263 -> V_594 = F_337 ;
V_43 -> V_263 -> V_591 = F_336 ;
}
if ( F_328 ( V_2 ) )
V_2 -> V_597 . V_598 = F_335 ;
V_43 -> V_263 -> V_595 = F_228 ;
V_43 -> V_263 -> V_596 = F_234 ;
}
}
int F_344 ( struct V_1 * V_2 )
{
V_2 -> V_599 . V_600 = true ;
return F_345 ( & V_2 -> V_27 , V_2 -> V_27 . V_601 -> V_28 ) ;
}
void F_346 ( struct V_1 * V_2 )
{
F_347 ( & V_2 -> V_27 ) ;
F_348 ( V_2 ) ;
V_2 -> V_599 . V_600 = false ;
}
void F_349 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_263 -> V_594 ( & V_2 -> V_27 ) ;
V_2 -> V_599 . V_600 = false ;
F_35 ( V_2 -> V_27 . V_28 ) ;
}
void F_350 ( struct V_1 * V_2 )
{
V_2 -> V_599 . V_600 = true ;
V_2 -> V_27 . V_263 -> V_592 ( & V_2 -> V_27 ) ;
V_2 -> V_27 . V_263 -> V_593 ( & V_2 -> V_27 ) ;
}
