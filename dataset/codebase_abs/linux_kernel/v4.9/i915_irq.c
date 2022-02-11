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
if ( F_32 ( V_2 -> V_22 . V_24 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
F_33 ( V_2 -> V_22 . V_23 ) ;
F_33 ( F_2 ( F_19 ( V_2 ) ) & V_2 -> V_21 ) ;
V_2 -> V_22 . V_24 = true ;
F_5 ( F_24 ( V_2 ) , F_2 ( F_24 ( V_2 ) ) |
V_2 -> V_21 ) ;
F_27 ( V_2 , V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
T_2 F_34 ( struct V_1 * V_2 , T_2 V_5 )
{
return ( V_5 & ~ V_2 -> V_22 . V_25 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( ! F_32 ( V_2 -> V_22 . V_24 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
V_2 -> V_22 . V_24 = false ;
F_5 ( V_26 , F_34 ( V_2 , ~ 0u ) ) ;
F_28 ( V_2 , V_2 -> V_21 ) ;
F_5 ( F_24 ( V_2 ) , F_2 ( F_24 ( V_2 ) ) &
~ V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_36 ( V_2 -> V_27 . V_28 ) ;
F_37 ( & V_2 -> V_22 . V_29 ) ;
F_30 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
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
void F_39 ( struct V_1 * V_2 ,
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
F_5 ( F_40 ( V_32 ) , V_2 -> V_33 [ V_32 ] ) ;
F_6 ( F_40 ( V_32 ) ) ;
}
}
void F_41 ( struct V_1 * V_2 ,
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
F_42 ( struct V_1 * V_2 , enum V_32 V_32 ,
T_2 V_36 , T_2 V_37 )
{
T_1 V_3 = F_43 ( V_32 ) ;
T_2 V_38 = F_2 ( V_3 ) & V_39 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_44 ( V_36 & ~ V_39 ||
V_37 & ~ V_40 ,
L_2 ,
F_45 ( V_32 ) , V_36 , V_37 ) )
return;
if ( ( V_38 & V_36 ) == V_36 )
return;
V_2 -> V_41 [ V_32 ] |= V_37 ;
V_38 |= V_36 | V_37 ;
F_5 ( V_3 , V_38 ) ;
F_6 ( V_3 ) ;
}
static void
F_46 ( struct V_1 * V_2 , enum V_32 V_32 ,
T_2 V_36 , T_2 V_37 )
{
T_1 V_3 = F_43 ( V_32 ) ;
T_2 V_38 = F_2 ( V_3 ) & V_39 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_44 ( V_36 & ~ V_39 ||
V_37 & ~ V_40 ,
L_2 ,
F_45 ( V_32 ) , V_36 , V_37 ) )
return;
if ( ( V_38 & V_36 ) == 0 )
return;
V_2 -> V_41 [ V_32 ] &= ~ V_37 ;
V_38 &= ~ V_36 ;
F_5 ( V_3 , V_38 ) ;
F_6 ( V_3 ) ;
}
static T_2 F_47 ( struct V_42 * V_43 , T_2 V_37 )
{
T_2 V_36 = V_37 << 16 ;
if ( F_33 ( V_37 & V_44 ) )
return 0 ;
if ( F_33 ( V_37 & V_45 ) )
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
F_48 ( struct V_1 * V_2 , enum V_32 V_32 ,
T_2 V_37 )
{
T_2 V_36 ;
if ( F_49 ( V_2 ) || F_50 ( V_2 ) )
V_36 = F_47 ( & V_2 -> V_27 ,
V_37 ) ;
else
V_36 = V_37 << 16 ;
F_42 ( V_2 , V_32 , V_36 , V_37 ) ;
}
void
F_51 ( struct V_1 * V_2 , enum V_32 V_32 ,
T_2 V_37 )
{
T_2 V_36 ;
if ( F_49 ( V_2 ) || F_50 ( V_2 ) )
V_36 = F_47 ( & V_2 -> V_27 ,
V_37 ) ;
else
V_36 = V_37 << 16 ;
F_46 ( V_2 , V_32 , V_36 , V_37 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_51 . V_52 || ! F_53 ( V_2 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
F_48 ( V_2 , V_53 , V_54 ) ;
if ( F_54 ( V_2 ) >= 4 )
F_48 ( V_2 , V_55 ,
V_54 ) ;
F_12 ( & V_2 -> V_7 ) ;
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
L_4 , F_45 ( V_32 ) ) ;
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
if ( F_64 ( V_2 ) || F_74 ( V_2 ) || F_54 ( V_2 ) >= 5 ) {
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
if ( F_64 ( V_2 ) || F_74 ( V_2 ) || F_54 ( V_2 ) >= 5 ) {
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
if ( F_89 ( V_129 ) )
F_90 ( V_129 ) ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
V_133 -> V_134 = F_92 ( V_2 , V_135 ) ;
V_133 -> V_136 = F_2 ( V_137 ) ;
V_133 -> V_138 = F_2 ( V_139 ) ;
}
static bool F_93 ( struct V_1 * V_2 ,
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
void F_94 ( struct V_1 * V_2 )
{
F_91 ( V_2 , & V_2 -> V_22 . V_149 ) ;
V_2 -> V_22 . V_150 = V_2 -> V_22 . V_149 ;
}
static T_2 F_95 ( struct V_1 * V_2 , T_2 V_23 )
{
struct V_132 V_141 ;
T_2 V_151 = 0 ;
if ( ( V_23 & ( V_152 | V_153 ) ) == 0 )
return 0 ;
F_91 ( V_2 , & V_141 ) ;
if ( V_141 . V_134 == 0 )
return 0 ;
if ( V_23 & V_152 ) {
if ( ! F_93 ( V_2 ,
& V_2 -> V_22 . V_149 , & V_141 ,
V_2 -> V_22 . V_154 ) )
V_151 |= V_155 ;
V_2 -> V_22 . V_149 = V_141 ;
}
if ( V_23 & V_153 ) {
if ( F_93 ( V_2 ,
& V_2 -> V_22 . V_150 , & V_141 ,
V_2 -> V_22 . V_156 ) )
V_151 |= V_157 ;
V_2 -> V_22 . V_150 = V_141 ;
}
return V_151 ;
}
static bool F_96 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
F_97 (engine, dev_priv)
if ( F_98 ( V_129 ) )
return true ;
return false ;
}
static void F_99 ( struct V_158 * V_29 )
{
struct V_1 * V_2 =
F_100 ( V_29 , struct V_1 , V_22 . V_29 ) ;
bool V_159 ;
int V_116 , V_160 , V_161 , V_162 ;
T_2 V_23 ;
F_11 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_22 . V_24 ) {
F_12 ( & V_2 -> V_7 ) ;
return;
}
V_23 = V_2 -> V_22 . V_23 ;
V_2 -> V_22 . V_23 = 0 ;
F_27 ( V_2 , V_2 -> V_21 ) ;
V_159 = V_2 -> V_22 . V_159 ;
V_2 -> V_22 . V_159 = false ;
F_12 ( & V_2 -> V_7 ) ;
F_9 ( V_23 & ~ V_2 -> V_21 ) ;
if ( ( V_23 & V_2 -> V_21 ) == 0 && ! V_159 )
return;
F_101 ( & V_2 -> V_22 . V_163 ) ;
V_23 |= F_95 ( V_2 , V_23 ) ;
V_160 = V_2 -> V_22 . V_164 ;
V_116 = V_2 -> V_22 . V_165 ;
V_161 = V_2 -> V_22 . V_166 ;
V_162 = V_2 -> V_22 . V_167 ;
if ( V_159 || F_96 ( V_2 ) )
V_162 = V_2 -> V_22 . V_168 ;
if ( V_159 && V_116 < V_2 -> V_22 . V_169 ) {
V_116 = V_2 -> V_22 . V_169 ;
V_160 = 0 ;
} else if ( V_23 & V_157 ) {
if ( V_160 > 0 )
V_160 *= 2 ;
else
V_160 = F_50 ( V_2 ) ? 2 : 1 ;
if ( V_116 < V_2 -> V_22 . V_170 - V_160 ) {
V_116 = V_2 -> V_22 . V_170 ;
V_160 = 0 ;
}
} else if ( V_159 || F_96 ( V_2 ) ) {
V_160 = 0 ;
} else if ( V_23 & V_171 ) {
if ( V_2 -> V_22 . V_165 > V_2 -> V_22 . V_170 )
V_116 = V_2 -> V_22 . V_170 ;
else
V_116 = V_2 -> V_22 . V_166 ;
V_160 = 0 ;
} else if ( V_23 & V_155 ) {
if ( V_160 < 0 )
V_160 *= 2 ;
else
V_160 = F_50 ( V_2 ) ? - 2 : - 1 ;
} else {
V_160 = 0 ;
}
V_2 -> V_22 . V_164 = V_160 ;
V_116 += V_160 ;
V_116 = F_102 ( int , V_116 , V_161 , V_162 ) ;
F_103 ( V_2 , V_116 ) ;
F_104 ( & V_2 -> V_22 . V_163 ) ;
}
static void F_105 ( struct V_158 * V_29 )
{
struct V_1 * V_2 =
F_100 ( V_29 , struct V_1 , V_172 . V_173 ) ;
T_2 V_174 , V_175 , V_176 , V_177 ;
char * V_178 [ 6 ] ;
T_3 V_179 ;
T_7 V_180 = 0 ;
F_101 ( & V_2 -> V_27 . V_181 ) ;
if ( F_9 ( ! V_2 -> V_172 . V_182 ) )
goto V_183;
V_179 = F_2 ( V_184 ) ;
F_5 ( V_184 , V_179 & ~ V_185 ) ;
F_6 ( V_184 ) ;
while ( ( V_180 = F_106 ( V_2 -> V_172 . V_182 ) ) != 0 ) {
T_1 V_3 ;
V_180 -- ;
if ( F_33 ( V_180 >= F_107 ( V_2 ) ) )
break;
V_2 -> V_172 . V_182 &= ~ ( 1 << V_180 ) ;
V_3 = F_108 ( V_180 ) ;
V_174 = F_2 ( V_3 ) ;
V_175 = F_109 ( V_174 ) ;
V_176 = F_110 ( V_174 ) ;
V_177 = F_111 ( V_174 ) ;
F_5 ( V_3 , V_186 | V_187 ) ;
F_6 ( V_3 ) ;
V_178 [ 0 ] = V_188 L_7 ;
V_178 [ 1 ] = F_112 ( V_189 , L_8 , V_175 ) ;
V_178 [ 2 ] = F_112 ( V_189 , L_9 , V_176 ) ;
V_178 [ 3 ] = F_112 ( V_189 , L_10 , V_177 ) ;
V_178 [ 4 ] = F_112 ( V_189 , L_11 , V_180 ) ;
V_178 [ 5 ] = NULL ;
F_113 ( & V_2 -> V_27 . V_190 -> V_191 -> V_192 ,
V_193 , V_178 ) ;
F_114 ( L_12 ,
V_180 , V_175 , V_176 , V_177 ) ;
F_115 ( V_178 [ 4 ] ) ;
F_115 ( V_178 [ 3 ] ) ;
F_115 ( V_178 [ 2 ] ) ;
F_115 ( V_178 [ 1 ] ) ;
}
F_5 ( V_184 , V_179 ) ;
V_183:
F_9 ( V_2 -> V_172 . V_182 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_16 ( V_2 , F_116 ( V_2 ) ) ;
F_12 ( & V_2 -> V_7 ) ;
F_104 ( & V_2 -> V_27 . V_181 ) ;
}
static void F_117 ( struct V_1 * V_2 ,
T_2 V_194 )
{
if ( ! F_118 ( V_2 ) )
return;
F_83 ( & V_2 -> V_7 ) ;
F_18 ( V_2 , F_116 ( V_2 ) ) ;
F_86 ( & V_2 -> V_7 ) ;
V_194 &= F_116 ( V_2 ) ;
if ( V_194 & V_195 )
V_2 -> V_172 . V_182 |= 1 << 1 ;
if ( V_194 & V_196 )
V_2 -> V_172 . V_182 |= 1 << 0 ;
F_119 ( V_2 -> V_197 , & V_2 -> V_172 . V_173 ) ;
}
static void F_120 ( struct V_1 * V_2 ,
T_2 V_198 )
{
if ( V_198 & V_199 )
F_87 ( & V_2 -> V_129 [ V_200 ] ) ;
if ( V_198 & V_201 )
F_87 ( & V_2 -> V_129 [ V_202 ] ) ;
}
static void F_121 ( struct V_1 * V_2 ,
T_2 V_198 )
{
if ( V_198 & V_199 )
F_87 ( & V_2 -> V_129 [ V_200 ] ) ;
if ( V_198 & V_203 )
F_87 ( & V_2 -> V_129 [ V_202 ] ) ;
if ( V_198 & V_204 )
F_87 ( & V_2 -> V_129 [ V_205 ] ) ;
if ( V_198 & ( V_206 |
V_207 |
V_208 ) )
F_114 ( L_13 , V_198 ) ;
if ( V_198 & F_116 ( V_2 ) )
F_117 ( V_2 , V_198 ) ;
}
static T_8 void
F_122 ( struct V_128 * V_129 , T_2 V_194 , int V_209 )
{
if ( V_194 & ( V_199 << V_209 ) )
F_87 ( V_129 ) ;
if ( V_194 & ( V_210 << V_209 ) )
F_123 ( & V_129 -> V_211 ) ;
}
static T_9 F_124 ( struct V_1 * V_2 ,
T_2 V_212 ,
T_2 V_198 [ 4 ] )
{
T_9 V_96 = V_213 ;
if ( V_212 & ( V_214 | V_215 ) ) {
V_198 [ 0 ] = F_65 ( F_21 ( 0 ) ) ;
if ( V_198 [ 0 ] ) {
F_125 ( F_21 ( 0 ) , V_198 [ 0 ] ) ;
V_96 = V_216 ;
} else
F_78 ( L_14 ) ;
}
if ( V_212 & ( V_217 | V_218 ) ) {
V_198 [ 1 ] = F_65 ( F_21 ( 1 ) ) ;
if ( V_198 [ 1 ] ) {
F_125 ( F_21 ( 1 ) , V_198 [ 1 ] ) ;
V_96 = V_216 ;
} else
F_78 ( L_15 ) ;
}
if ( V_212 & V_219 ) {
V_198 [ 3 ] = F_65 ( F_21 ( 3 ) ) ;
if ( V_198 [ 3 ] ) {
F_125 ( F_21 ( 3 ) , V_198 [ 3 ] ) ;
V_96 = V_216 ;
} else
F_78 ( L_16 ) ;
}
if ( V_212 & V_220 ) {
V_198 [ 2 ] = F_65 ( F_21 ( 2 ) ) ;
if ( V_198 [ 2 ] & V_2 -> V_21 ) {
F_125 ( F_21 ( 2 ) ,
V_198 [ 2 ] & V_2 -> V_21 ) ;
V_96 = V_216 ;
} else
F_78 ( L_17 ) ;
}
return V_96 ;
}
static void F_126 ( struct V_1 * V_2 ,
T_2 V_198 [ 4 ] )
{
if ( V_198 [ 0 ] ) {
F_122 ( & V_2 -> V_129 [ V_200 ] ,
V_198 [ 0 ] , V_221 ) ;
F_122 ( & V_2 -> V_129 [ V_205 ] ,
V_198 [ 0 ] , V_222 ) ;
}
if ( V_198 [ 1 ] ) {
F_122 ( & V_2 -> V_129 [ V_202 ] ,
V_198 [ 1 ] , V_223 ) ;
F_122 ( & V_2 -> V_129 [ V_224 ] ,
V_198 [ 1 ] , V_225 ) ;
}
if ( V_198 [ 3 ] )
F_122 ( & V_2 -> V_129 [ V_226 ] ,
V_198 [ 3 ] , V_227 ) ;
if ( V_198 [ 2 ] & V_2 -> V_21 )
F_127 ( V_2 , V_198 [ 2 ] ) ;
}
static bool F_128 ( enum V_228 V_228 , T_2 V_4 )
{
switch ( V_228 ) {
case V_229 :
return V_4 & V_230 ;
case V_231 :
return V_4 & V_232 ;
case V_233 :
return V_4 & V_234 ;
default:
return false ;
}
}
static bool F_129 ( enum V_228 V_228 , T_2 V_4 )
{
switch ( V_228 ) {
case V_235 :
return V_4 & V_236 ;
default:
return false ;
}
}
static bool F_130 ( enum V_228 V_228 , T_2 V_4 )
{
switch ( V_228 ) {
case V_229 :
return V_4 & V_230 ;
case V_231 :
return V_4 & V_232 ;
case V_233 :
return V_4 & V_234 ;
case V_237 :
return V_4 & V_238 ;
default:
return false ;
}
}
static bool F_131 ( enum V_228 V_228 , T_2 V_4 )
{
switch ( V_228 ) {
case V_229 :
return V_4 & V_239 ;
default:
return false ;
}
}
static bool F_132 ( enum V_228 V_228 , T_2 V_4 )
{
switch ( V_228 ) {
case V_231 :
return V_4 & V_232 ;
case V_233 :
return V_4 & V_234 ;
case V_237 :
return V_4 & V_238 ;
default:
return false ;
}
}
static bool F_133 ( enum V_228 V_228 , T_2 V_4 )
{
switch ( V_228 ) {
case V_231 :
return V_4 & V_240 ;
case V_233 :
return V_4 & V_241 ;
case V_237 :
return V_4 & V_242 ;
default:
return false ;
}
}
static void F_134 ( T_2 * V_243 , T_2 * V_244 ,
T_2 V_245 , T_2 V_246 ,
const T_2 V_247 [ V_248 ] ,
bool F_135 ( enum V_228 V_228 , T_2 V_4 ) )
{
enum V_228 V_228 ;
int V_86 ;
F_136 (i) {
if ( ( V_247 [ V_86 ] & V_245 ) == 0 )
continue;
* V_243 |= F_137 ( V_86 ) ;
if ( ! F_138 ( V_86 , & V_228 ) )
continue;
if ( F_135 ( V_228 , V_246 ) )
* V_244 |= F_137 ( V_86 ) ;
}
F_71 ( L_18 ,
V_245 , V_246 , * V_243 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_140 ( & V_2 -> V_249 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
F_140 ( & V_2 -> V_249 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
enum V_32 V_32 ,
T_3 V_250 , T_3 V_251 ,
T_3 V_252 , T_3 V_253 ,
T_3 V_254 )
{
struct V_255 * V_256 = & V_2 -> V_256 [ V_32 ] ;
struct V_257 * V_258 ;
int V_259 , V_260 ;
F_83 ( & V_256 -> V_103 ) ;
if ( ! V_256 -> V_261 ) {
F_86 ( & V_256 -> V_103 ) ;
F_80 ( L_19 ) ;
return;
}
V_259 = V_256 -> V_259 ;
V_260 = V_256 -> V_260 ;
if ( F_143 ( V_259 , V_260 , V_262 ) < 1 ) {
F_86 ( & V_256 -> V_103 ) ;
F_78 ( L_20 ) ;
return;
}
V_258 = & V_256 -> V_261 [ V_259 ] ;
V_258 -> V_263 = V_2 -> V_27 . V_264 -> V_265 ( & V_2 -> V_27 ,
V_32 ) ;
V_258 -> V_266 [ 0 ] = V_250 ;
V_258 -> V_266 [ 1 ] = V_251 ;
V_258 -> V_266 [ 2 ] = V_252 ;
V_258 -> V_266 [ 3 ] = V_253 ;
V_258 -> V_266 [ 4 ] = V_254 ;
V_259 = ( V_259 + 1 ) & ( V_262 - 1 ) ;
V_256 -> V_259 = V_259 ;
F_86 ( & V_256 -> V_103 ) ;
F_144 ( & V_256 -> V_197 ) ;
}
static inline void
F_142 ( struct V_1 * V_2 ,
enum V_32 V_32 ,
T_3 V_250 , T_3 V_251 ,
T_3 V_252 , T_3 V_253 ,
T_3 V_254 ) {}
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
T_3 V_267 , V_268 ;
if ( F_54 ( V_2 ) >= 3 )
V_267 = F_2 ( F_153 ( V_32 ) ) ;
else
V_267 = 0 ;
if ( F_54 ( V_2 ) >= 5 || F_74 ( V_2 ) )
V_268 = F_2 ( F_154 ( V_32 ) ) ;
else
V_268 = 0 ;
F_142 ( V_2 , V_32 ,
F_2 ( F_155 ( V_32 ) ) ,
F_2 ( F_156 ( V_32 ) ) ,
F_2 ( F_157 ( V_32 ) ) ,
V_267 , V_268 ) ;
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
if ( V_23 & V_269 )
F_87 ( & V_2 -> V_129 [ V_226 ] ) ;
if ( V_23 & V_270 )
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
T_2 V_194 , T_2 V_271 [ V_272 ] )
{
int V_32 ;
F_83 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_273 ) {
F_86 ( & V_2 -> V_7 ) ;
return;
}
F_164 (dev_priv, pipe) {
T_1 V_3 ;
T_2 V_5 , V_274 = 0 ;
V_5 = V_46 ;
switch ( V_32 ) {
case V_55 :
V_274 = V_275 ;
break;
case V_53 :
V_274 = V_276 ;
break;
case V_277 :
V_274 = V_278 ;
break;
}
if ( V_194 & V_274 )
V_5 |= V_2 -> V_41 [ V_32 ] ;
if ( ! V_5 )
continue;
V_3 = F_43 ( V_32 ) ;
V_5 |= V_39 ;
V_271 [ V_32 ] = F_2 ( V_3 ) & V_5 ;
if ( V_271 [ V_32 ] & ( V_46 |
V_40 ) )
F_5 ( V_3 , V_271 [ V_32 ] ) ;
}
F_86 ( & V_2 -> V_7 ) ;
}
static void F_165 ( struct V_1 * V_2 ,
T_2 V_271 [ V_272 ] )
{
enum V_32 V_32 ;
F_164 (dev_priv, pipe) {
if ( V_271 [ V_32 ] & V_279 &&
F_160 ( V_2 , V_32 ) )
F_166 ( V_2 , V_32 ) ;
if ( V_271 [ V_32 ] & V_280 )
F_167 ( V_2 , V_32 ) ;
if ( V_271 [ V_32 ] & V_281 )
F_152 ( V_2 , V_32 ) ;
if ( V_271 [ V_32 ] & V_46 )
F_168 ( V_2 , V_32 ) ;
}
if ( V_271 [ 0 ] & V_282 )
F_139 ( V_2 ) ;
}
static T_2 F_169 ( struct V_1 * V_2 )
{
T_2 V_283 = F_2 ( V_284 ) ;
if ( V_283 )
F_5 ( V_284 , V_283 ) ;
return V_283 ;
}
static void F_170 ( struct V_1 * V_2 ,
T_2 V_283 )
{
T_2 V_243 = 0 , V_244 = 0 ;
if ( F_74 ( V_2 ) || F_49 ( V_2 ) ||
F_50 ( V_2 ) ) {
T_2 V_245 = V_283 & V_285 ;
if ( V_245 ) {
F_134 ( & V_243 , & V_244 , V_245 ,
V_245 , V_286 ,
F_133 ) ;
F_171 ( V_2 , V_243 , V_244 ) ;
}
if ( V_283 & V_287 )
F_141 ( V_2 ) ;
} else {
T_2 V_245 = V_283 & V_288 ;
if ( V_245 ) {
F_134 ( & V_243 , & V_244 , V_245 ,
V_245 , V_289 ,
F_133 ) ;
F_171 ( V_2 , V_243 , V_244 ) ;
}
}
}
static T_9 F_172 ( int V_28 , void * V_290 )
{
struct V_42 * V_43 = V_290 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_9 V_96 = V_213 ;
if ( ! F_14 ( V_2 ) )
return V_213 ;
F_173 ( V_2 ) ;
do {
T_2 V_194 , V_198 , V_23 ;
T_2 V_271 [ V_272 ] = {} ;
T_2 V_283 = 0 ;
T_2 V_291 = 0 ;
V_198 = F_2 ( V_292 ) ;
V_23 = F_2 ( V_17 ) ;
V_194 = F_2 ( V_293 ) ;
if ( V_198 == 0 && V_23 == 0 && V_194 == 0 )
break;
V_96 = V_216 ;
F_5 ( V_294 , 0 ) ;
V_291 = F_2 ( V_295 ) ;
F_5 ( V_295 , 0 ) ;
if ( V_198 )
F_5 ( V_292 , V_198 ) ;
if ( V_23 )
F_5 ( V_17 , V_23 ) ;
if ( V_194 & V_296 )
V_283 = F_169 ( V_2 ) ;
F_163 ( V_2 , V_194 , V_271 ) ;
if ( V_194 )
F_5 ( V_293 , V_194 ) ;
F_5 ( V_295 , V_291 ) ;
F_5 ( V_294 , V_297 ) ;
F_6 ( V_294 ) ;
if ( V_198 )
F_121 ( V_2 , V_198 ) ;
if ( V_23 )
F_127 ( V_2 , V_23 ) ;
if ( V_283 )
F_170 ( V_2 , V_283 ) ;
F_165 ( V_2 , V_271 ) ;
} while ( 0 );
F_174 ( V_2 ) ;
return V_96 ;
}
static T_9 F_175 ( int V_28 , void * V_290 )
{
struct V_42 * V_43 = V_290 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_9 V_96 = V_213 ;
if ( ! F_14 ( V_2 ) )
return V_213 ;
F_173 ( V_2 ) ;
do {
T_2 V_212 , V_194 ;
T_2 V_198 [ 4 ] = {} ;
T_2 V_271 [ V_272 ] = {} ;
T_2 V_283 = 0 ;
T_2 V_291 = 0 ;
V_212 = F_2 ( V_298 ) & ~ V_299 ;
V_194 = F_2 ( V_293 ) ;
if ( V_212 == 0 && V_194 == 0 )
break;
V_96 = V_216 ;
F_5 ( V_298 , 0 ) ;
V_291 = F_2 ( V_295 ) ;
F_5 ( V_295 , 0 ) ;
F_124 ( V_2 , V_212 , V_198 ) ;
if ( V_194 & V_296 )
V_283 = F_169 ( V_2 ) ;
F_163 ( V_2 , V_194 , V_271 ) ;
if ( V_194 )
F_5 ( V_293 , V_194 ) ;
F_5 ( V_295 , V_291 ) ;
F_5 ( V_298 , V_299 ) ;
F_6 ( V_298 ) ;
F_126 ( V_2 , V_198 ) ;
if ( V_283 )
F_170 ( V_2 , V_283 ) ;
F_165 ( V_2 , V_271 ) ;
} while ( 0 );
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_176 ( struct V_1 * V_2 ,
T_2 V_245 ,
const T_2 V_247 [ V_248 ] )
{
T_2 V_246 , V_243 = 0 , V_244 = 0 ;
V_246 = F_2 ( V_300 ) ;
if ( ! V_245 ) {
T_2 V_5 = V_301 |
V_302 |
V_303 |
V_304 ;
V_246 &= ~ V_5 ;
}
F_5 ( V_300 , V_246 ) ;
if ( ! V_245 )
return;
F_134 ( & V_243 , & V_244 , V_245 ,
V_246 , V_247 ,
F_132 ) ;
F_171 ( V_2 , V_243 , V_244 ) ;
}
static void F_177 ( struct V_1 * V_2 , T_2 V_305 )
{
int V_32 ;
T_2 V_245 = V_305 & V_306 ;
F_176 ( V_2 , V_245 , V_307 ) ;
if ( V_305 & V_308 ) {
int V_228 = F_106 ( ( V_305 & V_308 ) >>
V_309 ) ;
F_71 ( L_22 ,
F_178 ( V_228 ) ) ;
}
if ( V_305 & V_310 )
F_141 ( V_2 ) ;
if ( V_305 & V_311 )
F_139 ( V_2 ) ;
if ( V_305 & V_312 )
F_71 ( L_23 ) ;
if ( V_305 & V_313 )
F_71 ( L_24 ) ;
if ( V_305 & V_314 )
F_78 ( L_25 ) ;
if ( V_305 & V_315 )
F_164 (dev_priv, pipe)
F_71 ( L_26 ,
F_45 ( V_32 ) ,
F_2 ( F_179 ( V_32 ) ) ) ;
if ( V_305 & ( V_316 | V_317 ) )
F_71 ( L_27 ) ;
if ( V_305 & ( V_318 | V_319 ) )
F_71 ( L_28 ) ;
if ( V_305 & V_320 )
F_180 ( V_2 , V_321 ) ;
if ( V_305 & V_322 )
F_180 ( V_2 , V_323 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
T_2 V_324 = F_2 ( V_325 ) ;
enum V_32 V_32 ;
if ( V_324 & V_326 )
F_78 ( L_29 ) ;
F_164 (dev_priv, pipe) {
if ( V_324 & F_182 ( V_32 ) )
F_168 ( V_2 , V_32 ) ;
if ( V_324 & F_183 ( V_32 ) ) {
if ( F_184 ( V_2 ) )
F_147 ( V_2 , V_32 ) ;
else
F_145 ( V_2 , V_32 ) ;
}
}
F_5 ( V_325 , V_324 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
T_2 V_327 = F_2 ( V_328 ) ;
if ( V_327 & V_329 )
F_78 ( L_25 ) ;
if ( V_327 & V_330 )
F_180 ( V_2 , V_321 ) ;
if ( V_327 & V_331 )
F_180 ( V_2 , V_323 ) ;
if ( V_327 & V_332 )
F_180 ( V_2 , V_333 ) ;
F_5 ( V_328 , V_327 ) ;
}
static void F_186 ( struct V_1 * V_2 , T_2 V_305 )
{
int V_32 ;
T_2 V_245 = V_305 & V_334 ;
F_176 ( V_2 , V_245 , V_335 ) ;
if ( V_305 & V_336 ) {
int V_228 = F_106 ( ( V_305 & V_336 ) >>
V_337 ) ;
F_71 ( L_30 ,
F_178 ( V_228 ) ) ;
}
if ( V_305 & V_338 )
F_141 ( V_2 ) ;
if ( V_305 & V_339 )
F_139 ( V_2 ) ;
if ( V_305 & V_340 )
F_71 ( L_31 ) ;
if ( V_305 & V_341 )
F_71 ( L_32 ) ;
if ( V_305 & V_342 )
F_164 (dev_priv, pipe)
F_71 ( L_26 ,
F_45 ( V_32 ) ,
F_2 ( F_179 ( V_32 ) ) ) ;
if ( V_305 & V_343 )
F_185 ( V_2 ) ;
}
static void F_187 ( struct V_1 * V_2 , T_2 V_305 )
{
T_2 V_245 = V_305 & V_344 &
~ V_345 ;
T_2 V_346 = V_305 & V_345 ;
T_2 V_243 = 0 , V_244 = 0 ;
if ( V_245 ) {
T_2 V_246 ;
V_246 = F_2 ( V_300 ) ;
F_5 ( V_300 , V_246 ) ;
F_134 ( & V_243 , & V_244 , V_245 ,
V_246 , V_347 ,
F_130 ) ;
}
if ( V_346 ) {
T_2 V_246 ;
V_246 = F_2 ( V_348 ) ;
F_5 ( V_348 , V_246 ) ;
F_134 ( & V_243 , & V_244 , V_346 ,
V_246 , V_347 ,
F_129 ) ;
}
if ( V_243 )
F_171 ( V_2 , V_243 , V_244 ) ;
if ( V_305 & V_339 )
F_139 ( V_2 ) ;
}
static void F_188 ( struct V_1 * V_2 ,
T_2 V_245 ,
const T_2 V_247 [ V_248 ] )
{
T_2 V_246 , V_243 = 0 , V_244 = 0 ;
V_246 = F_2 ( V_349 ) ;
F_5 ( V_349 , V_246 ) ;
F_134 ( & V_243 , & V_244 , V_245 ,
V_246 , V_247 ,
F_131 ) ;
F_171 ( V_2 , V_243 , V_244 ) ;
}
static void F_189 ( struct V_1 * V_2 ,
T_2 V_350 )
{
enum V_32 V_32 ;
T_2 V_245 = V_350 & V_351 ;
if ( V_245 )
F_188 ( V_2 , V_245 , V_352 ) ;
if ( V_350 & V_353 )
F_141 ( V_2 ) ;
if ( V_350 & V_354 )
F_190 ( V_2 ) ;
if ( V_350 & V_355 )
F_78 ( L_29 ) ;
F_164 (dev_priv, pipe) {
if ( V_350 & F_191 ( V_32 ) &&
F_160 ( V_2 , V_32 ) )
F_166 ( V_2 , V_32 ) ;
if ( V_350 & F_192 ( V_32 ) )
F_168 ( V_2 , V_32 ) ;
if ( V_350 & F_193 ( V_32 ) )
F_152 ( V_2 , V_32 ) ;
if ( V_350 & F_194 ( V_32 ) )
F_167 ( V_2 , V_32 ) ;
}
if ( V_350 & V_356 ) {
T_2 V_305 = F_2 ( V_357 ) ;
if ( F_195 ( V_2 ) )
F_186 ( V_2 , V_305 ) ;
else
F_177 ( V_2 , V_305 ) ;
F_5 ( V_357 , V_305 ) ;
}
if ( F_196 ( V_2 ) && V_350 & V_358 )
F_82 ( V_2 ) ;
}
static void F_197 ( struct V_1 * V_2 ,
T_2 V_350 )
{
enum V_32 V_32 ;
T_2 V_245 = V_350 & V_359 ;
if ( V_245 )
F_188 ( V_2 , V_245 , V_360 ) ;
if ( V_350 & V_361 )
F_181 ( V_2 ) ;
if ( V_350 & V_362 )
F_141 ( V_2 ) ;
if ( V_350 & V_363 )
F_190 ( V_2 ) ;
F_164 (dev_priv, pipe) {
if ( V_350 & ( F_198 ( V_32 ) ) &&
F_160 ( V_2 , V_32 ) )
F_166 ( V_2 , V_32 ) ;
if ( V_350 & F_199 ( V_32 ) )
F_167 ( V_2 , V_32 ) ;
}
if ( ! F_200 ( V_2 ) && ( V_350 & V_364 ) ) {
T_2 V_305 = F_2 ( V_357 ) ;
F_186 ( V_2 , V_305 ) ;
F_5 ( V_357 , V_305 ) ;
}
}
static T_9 F_201 ( int V_28 , void * V_290 )
{
struct V_42 * V_43 = V_290 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_350 , V_198 , V_365 , V_366 = 0 ;
T_9 V_96 = V_213 ;
if ( ! F_14 ( V_2 ) )
return V_213 ;
F_173 ( V_2 ) ;
V_365 = F_2 ( V_367 ) ;
F_5 ( V_367 , V_365 & ~ V_368 ) ;
F_6 ( V_367 ) ;
if ( ! F_200 ( V_2 ) ) {
V_366 = F_2 ( V_369 ) ;
F_5 ( V_369 , 0 ) ;
F_6 ( V_369 ) ;
}
V_198 = F_2 ( V_292 ) ;
if ( V_198 ) {
F_5 ( V_292 , V_198 ) ;
V_96 = V_216 ;
if ( F_54 ( V_2 ) >= 6 )
F_121 ( V_2 , V_198 ) ;
else
F_120 ( V_2 , V_198 ) ;
}
V_350 = F_2 ( V_370 ) ;
if ( V_350 ) {
F_5 ( V_370 , V_350 ) ;
V_96 = V_216 ;
if ( F_54 ( V_2 ) >= 7 )
F_197 ( V_2 , V_350 ) ;
else
F_189 ( V_2 , V_350 ) ;
}
if ( F_54 ( V_2 ) >= 6 ) {
T_2 V_23 = F_2 ( V_17 ) ;
if ( V_23 ) {
F_5 ( V_17 , V_23 ) ;
V_96 = V_216 ;
F_127 ( V_2 , V_23 ) ;
}
}
F_5 ( V_367 , V_365 ) ;
F_6 ( V_367 ) ;
if ( ! F_200 ( V_2 ) ) {
F_5 ( V_369 , V_366 ) ;
F_6 ( V_369 ) ;
}
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_202 ( struct V_1 * V_2 ,
T_2 V_245 ,
const T_2 V_247 [ V_248 ] )
{
T_2 V_246 , V_243 = 0 , V_244 = 0 ;
V_246 = F_2 ( V_300 ) ;
F_5 ( V_300 , V_246 ) ;
F_134 ( & V_243 , & V_244 , V_245 ,
V_246 , V_247 ,
F_128 ) ;
F_171 ( V_2 , V_243 , V_244 ) ;
}
static T_9
F_203 ( struct V_1 * V_2 , T_2 V_212 )
{
T_9 V_96 = V_213 ;
T_2 V_194 ;
enum V_32 V_32 ;
if ( V_212 & V_371 ) {
V_194 = F_2 ( V_372 ) ;
if ( V_194 ) {
F_5 ( V_372 , V_194 ) ;
V_96 = V_216 ;
if ( V_194 & V_373 )
F_190 ( V_2 ) ;
else
F_78 ( L_33 ) ;
}
else
F_78 ( L_34 ) ;
}
if ( V_212 & V_374 ) {
V_194 = F_2 ( V_375 ) ;
if ( V_194 ) {
T_2 V_376 ;
bool V_377 = false ;
F_5 ( V_375 , V_194 ) ;
V_96 = V_216 ;
V_376 = V_378 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_376 |= V_379 |
V_380 |
V_381 ;
if ( V_194 & V_376 ) {
F_141 ( V_2 ) ;
V_377 = true ;
}
if ( F_204 ( V_2 ) ) {
V_376 = V_194 & V_382 ;
if ( V_376 ) {
F_202 ( V_2 , V_376 ,
V_383 ) ;
V_377 = true ;
}
} else if ( F_205 ( V_2 ) ) {
V_376 = V_194 & V_384 ;
if ( V_376 ) {
F_188 ( V_2 ,
V_376 , V_385 ) ;
V_377 = true ;
}
}
if ( F_204 ( V_2 ) && ( V_194 & V_386 ) ) {
F_139 ( V_2 ) ;
V_377 = true ;
}
if ( ! V_377 )
F_78 ( L_35 ) ;
}
else
F_78 ( L_36 ) ;
}
F_164 (dev_priv, pipe) {
T_2 V_387 , V_388 ;
if ( ! ( V_212 & F_206 ( V_32 ) ) )
continue;
V_194 = F_2 ( F_207 ( V_32 ) ) ;
if ( ! V_194 ) {
F_78 ( L_37 ) ;
continue;
}
V_96 = V_216 ;
F_5 ( F_207 ( V_32 ) , V_194 ) ;
if ( V_194 & V_389 &&
F_160 ( V_2 , V_32 ) )
F_166 ( V_2 , V_32 ) ;
V_387 = V_194 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_387 &= V_390 ;
else
V_387 &= V_391 ;
if ( V_387 )
F_167 ( V_2 , V_32 ) ;
if ( V_194 & V_392 )
F_145 ( V_2 , V_32 ) ;
if ( V_194 & V_393 )
F_168 ( V_2 , V_32 ) ;
V_388 = V_194 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_388 &= V_394 ;
else
V_388 &= V_395 ;
if ( V_388 )
F_78 ( L_38 ,
F_45 ( V_32 ) ,
V_388 ) ;
}
if ( F_208 ( V_2 ) && ! F_200 ( V_2 ) &&
V_212 & V_396 ) {
V_194 = F_2 ( V_357 ) ;
if ( V_194 ) {
F_5 ( V_357 , V_194 ) ;
V_96 = V_216 ;
if ( F_209 ( V_2 ) || F_210 ( V_2 ) )
F_187 ( V_2 , V_194 ) ;
else
F_186 ( V_2 , V_194 ) ;
} else {
F_71 ( L_39 ) ;
}
}
return V_96 ;
}
static T_9 F_211 ( int V_28 , void * V_290 )
{
struct V_42 * V_43 = V_290 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_212 ;
T_2 V_198 [ 4 ] = {} ;
T_9 V_96 ;
if ( ! F_14 ( V_2 ) )
return V_213 ;
V_212 = F_65 ( V_298 ) ;
V_212 &= ~ V_299 ;
if ( ! V_212 )
return V_213 ;
F_125 ( V_298 , 0 ) ;
F_173 ( V_2 ) ;
V_96 = F_124 ( V_2 , V_212 , V_198 ) ;
F_126 ( V_2 , V_198 ) ;
V_96 |= F_203 ( V_2 , V_212 ) ;
F_125 ( V_298 , V_299 ) ;
F_17 ( V_298 ) ;
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_212 ( struct V_1 * V_2 )
{
F_140 ( & V_2 -> V_397 . V_398 ) ;
F_140 ( & V_2 -> V_399 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_400 * V_192 = & V_2 -> V_27 . V_190 -> V_191 -> V_192 ;
char * V_401 [] = { V_402 L_7 , NULL } ;
char * V_403 [] = { V_404 L_7 , NULL } ;
char * V_405 [] = { V_402 L_40 , NULL } ;
F_113 ( V_192 , V_193 , V_401 ) ;
F_71 ( L_41 ) ;
F_113 ( V_192 , V_193 , V_403 ) ;
F_214 ( V_2 ) ;
F_215 ( V_2 ) ;
do {
if ( F_216 ( & V_2 -> V_27 . V_181 ) ) {
F_217 ( V_2 ) ;
F_104 ( & V_2 -> V_27 . V_181 ) ;
}
} while ( F_218 ( & V_2 -> V_397 . V_74 ,
V_406 ,
V_407 ,
V_408 ) );
F_219 ( V_2 ) ;
F_220 ( V_2 ) ;
if ( ! F_221 ( V_409 , & V_2 -> V_397 . V_74 ) )
F_113 ( V_192 ,
V_193 , V_405 ) ;
F_140 ( & V_2 -> V_397 . V_410 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
T_3 V_411 [ V_412 ] ;
T_2 V_413 = F_2 ( V_414 ) ;
int V_32 , V_86 ;
if ( ! V_413 )
return;
F_223 ( L_42 , V_413 ) ;
F_224 ( V_2 , V_411 ) ;
if ( F_74 ( V_2 ) ) {
if ( V_413 & ( V_415 | V_416 ) ) {
T_2 V_417 = F_2 ( V_418 ) ;
F_223 ( L_43 , F_2 ( V_418 ) ) ;
F_223 ( L_44 , F_2 ( V_419 ) ) ;
for ( V_86 = 0 ; V_86 < F_225 ( V_411 ) ; V_86 ++ )
F_223 ( L_45 , V_86 , V_411 [ V_86 ] ) ;
F_223 ( L_46 , F_2 ( V_420 ) ) ;
F_223 ( L_47 , F_2 ( V_421 ) ) ;
F_5 ( V_418 , V_417 ) ;
F_6 ( V_418 ) ;
}
if ( V_413 & V_422 ) {
T_2 V_423 = F_2 ( V_424 ) ;
F_223 ( L_48 ) ;
F_223 ( L_49 , V_423 ) ;
F_5 ( V_424 , V_423 ) ;
F_6 ( V_424 ) ;
}
}
if ( ! F_64 ( V_2 ) ) {
if ( V_413 & V_425 ) {
T_2 V_423 = F_2 ( V_424 ) ;
F_223 ( L_48 ) ;
F_223 ( L_49 , V_423 ) ;
F_5 ( V_424 , V_423 ) ;
F_6 ( V_424 ) ;
}
}
if ( V_413 & V_426 ) {
F_223 ( L_50 ) ;
F_164 (dev_priv, pipe)
F_223 ( L_51 ,
F_45 ( V_32 ) , F_2 ( F_43 ( V_32 ) ) ) ;
}
if ( V_413 & V_427 ) {
F_223 ( L_52 ) ;
F_223 ( L_53 , F_2 ( V_428 ) ) ;
for ( V_86 = 0 ; V_86 < F_225 ( V_411 ) ; V_86 ++ )
F_223 ( L_45 , V_86 , V_411 [ V_86 ] ) ;
if ( F_54 ( V_2 ) < 4 ) {
T_2 V_417 = F_2 ( V_429 ) ;
F_223 ( L_43 , F_2 ( V_429 ) ) ;
F_223 ( L_44 , F_2 ( V_430 ) ) ;
F_223 ( L_47 , F_2 ( V_431 ) ) ;
F_5 ( V_429 , V_417 ) ;
F_6 ( V_429 ) ;
} else {
T_2 V_417 = F_2 ( V_418 ) ;
F_223 ( L_43 , F_2 ( V_418 ) ) ;
F_223 ( L_44 , F_2 ( V_419 ) ) ;
F_223 ( L_46 , F_2 ( V_420 ) ) ;
F_223 ( L_47 , F_2 ( V_421 ) ) ;
F_5 ( V_418 , V_417 ) ;
F_6 ( V_418 ) ;
}
}
F_5 ( V_414 , V_413 ) ;
F_6 ( V_414 ) ;
V_413 = F_2 ( V_414 ) ;
if ( V_413 ) {
F_78 ( L_54 , V_413 ) ;
F_5 ( V_432 , F_2 ( V_432 ) | V_413 ) ;
F_5 ( V_433 , V_434 ) ;
}
}
void F_226 ( struct V_1 * V_2 ,
T_2 V_435 ,
const char * V_436 , ... )
{
T_10 args ;
char V_437 [ 80 ] ;
va_start ( args , V_436 ) ;
F_227 ( V_437 , sizeof( V_437 ) , V_436 , args ) ;
va_end ( args ) ;
F_228 ( V_2 , V_435 , V_437 ) ;
F_222 ( V_2 ) ;
if ( ! V_435 )
return;
if ( F_229 ( V_406 ,
& V_2 -> V_397 . V_74 ) )
return;
F_212 ( V_2 ) ;
F_213 ( V_2 ) ;
}
static int F_230 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
if ( F_20 ( V_43 ) -> V_16 >= 4 )
F_48 ( V_2 , V_32 ,
V_279 ) ;
else
F_48 ( V_2 , V_32 ,
V_438 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static int F_231 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
T_3 V_439 = ( F_20 ( V_43 ) -> V_16 >= 7 ) ? F_198 ( V_32 ) :
F_191 ( V_32 ) ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_232 ( V_2 , V_439 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static int F_233 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_48 ( V_2 , V_32 ,
V_279 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static int F_234 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_235 ( V_2 , V_32 , V_389 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
return 0 ;
}
static void F_236 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_51 ( V_2 , V_32 ,
V_438 |
V_279 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
}
static void F_237 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
T_3 V_439 = ( F_20 ( V_43 ) -> V_16 >= 7 ) ? F_198 ( V_32 ) :
F_191 ( V_32 ) ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_238 ( V_2 , V_439 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
}
static void F_239 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_51 ( V_2 , V_32 ,
V_279 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
}
static void F_240 ( struct V_42 * V_43 , unsigned int V_32 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
unsigned long V_97 ;
F_72 ( & V_2 -> V_7 , V_97 ) ;
F_241 ( V_2 , V_32 , V_389 ) ;
F_75 ( & V_2 -> V_7 , V_97 ) ;
}
static bool
F_242 ( struct V_128 * V_129 , T_2 V_440 )
{
if ( F_54 ( V_129 -> V_441 ) >= 8 ) {
return ( V_440 >> 23 ) == 0x1c ;
} else {
V_440 &= ~ V_442 ;
return V_440 == ( V_443 | V_444 |
V_445 ) ;
}
}
static struct V_128 *
F_243 ( struct V_128 * V_129 , T_2 V_440 ,
T_6 V_446 )
{
struct V_1 * V_2 = V_129 -> V_441 ;
struct V_128 * V_447 ;
if ( F_54 ( V_2 ) >= 8 ) {
F_97 (signaller, dev_priv) {
if ( V_129 == V_447 )
continue;
if ( V_446 == V_447 -> V_448 . V_449 [ V_129 -> V_450 ] )
return V_447 ;
}
} else {
T_2 V_451 = V_440 & V_442 ;
F_97 (signaller, dev_priv) {
if( V_129 == V_447 )
continue;
if ( V_451 == V_447 -> V_448 . V_452 . V_453 [ V_129 -> V_450 ] )
return V_447 ;
}
}
F_71 ( L_55 ,
V_129 -> V_454 , V_440 , V_446 ) ;
return F_244 ( - V_455 ) ;
}
static struct V_128 *
F_245 ( struct V_128 * V_129 , T_2 * V_456 )
{
struct V_1 * V_2 = V_129 -> V_441 ;
void T_11 * V_457 ;
T_2 V_458 , V_440 , V_259 ;
T_6 V_446 = 0 ;
int V_86 , V_459 ;
if ( V_129 -> V_460 == NULL )
return NULL ;
V_440 = F_2 ( F_246 ( V_129 -> V_461 ) ) ;
if ( ! F_242 ( V_129 , V_440 ) )
return NULL ;
V_259 = F_247 ( V_129 ) & V_462 ;
V_459 = ( F_54 ( V_2 ) >= 8 ) ? 5 : 4 ;
V_457 = ( void T_11 * ) V_129 -> V_460 -> V_457 ;
for ( V_86 = V_459 ; V_86 ; -- V_86 ) {
V_259 &= V_129 -> V_460 -> V_463 - 1 ;
V_458 = F_248 ( V_457 + V_259 ) ;
if ( V_458 == V_440 )
break;
V_259 -= 4 ;
}
if ( ! V_86 )
return NULL ;
* V_456 = F_248 ( V_457 + V_259 + 4 ) + 1 ;
if ( F_54 ( V_2 ) >= 8 ) {
V_446 = F_248 ( V_457 + V_259 + 12 ) ;
V_446 <<= 32 ;
V_446 |= F_248 ( V_457 + V_259 + 8 ) ;
}
return F_243 ( V_129 , V_440 , V_446 ) ;
}
static int F_249 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_441 ;
struct V_128 * V_447 ;
T_2 V_456 ;
V_129 -> V_464 . V_465 ++ ;
V_447 = F_245 ( V_129 , & V_456 ) ;
if ( V_447 == NULL )
return - 1 ;
if ( F_250 ( V_447 ) )
return 0 ;
if ( V_447 -> V_464 . V_465 >= V_466 )
return - 1 ;
if ( F_251 ( F_252 ( V_447 ) , V_456 ) )
return 1 ;
if ( F_253 ( V_447 ) & V_467 &&
F_249 ( V_447 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
F_97 (engine, dev_priv)
V_129 -> V_464 . V_465 = 0 ;
}
static bool F_255 ( struct V_128 * V_129 )
{
T_2 V_411 [ V_412 ] ;
bool V_468 ;
int V_86 ;
if ( V_129 -> V_469 != V_200 )
return true ;
F_224 ( V_129 -> V_441 , V_411 ) ;
V_468 = true ;
for ( V_86 = 0 ; V_86 < V_412 ; V_86 ++ ) {
const T_2 V_470 = V_411 [ V_86 ] | V_129 -> V_464 . V_411 [ V_86 ] ;
if ( V_470 != V_129 -> V_464 . V_411 [ V_86 ] )
V_468 = false ;
V_129 -> V_464 . V_411 [ V_86 ] |= V_470 ;
}
return V_468 ;
}
static enum V_471
F_256 ( struct V_128 * V_129 , T_6 V_472 )
{
if ( V_472 != V_129 -> V_464 . V_472 ) {
memset ( V_129 -> V_464 . V_411 , 0 ,
sizeof( V_129 -> V_464 . V_411 ) ) ;
return V_473 ;
}
if ( ! F_255 ( V_129 ) )
return V_473 ;
return V_474 ;
}
static enum V_471
F_257 ( struct V_128 * V_129 , T_6 V_472 )
{
struct V_1 * V_2 = V_129 -> V_441 ;
enum V_471 V_475 ;
T_2 V_470 ;
V_475 = F_256 ( V_129 , V_472 ) ;
if ( V_475 != V_474 )
return V_475 ;
if ( F_64 ( V_2 ) )
return V_474 ;
V_470 = F_253 ( V_129 ) ;
if ( V_470 & V_476 ) {
F_226 ( V_2 , 0 ,
L_56 ,
V_129 -> V_454 ) ;
F_258 ( V_129 , V_470 ) ;
return V_477 ;
}
if ( F_54 ( V_2 ) >= 6 && V_470 & V_467 ) {
switch ( F_249 ( V_129 ) ) {
default:
return V_474 ;
case 1 :
F_226 ( V_2 , 0 ,
L_57 ,
V_129 -> V_454 ) ;
F_258 ( V_129 , V_470 ) ;
return V_477 ;
case 0 :
return V_478 ;
}
}
return V_474 ;
}
static void F_259 ( struct V_158 * V_29 )
{
struct V_1 * V_2 =
F_100 ( V_29 , F_260 ( * V_2 ) ,
V_397 . V_479 . V_29 ) ;
struct V_128 * V_129 ;
unsigned int V_480 = 0 , V_468 = 0 ;
int V_481 = 0 ;
#define F_261 1
#define F_262 5
#define F_263 20
#define F_264 15
if ( ! V_441 . V_482 )
return;
if ( ! F_32 ( V_2 -> V_483 . V_484 ) )
return;
F_265 ( V_2 ) ;
F_97 (engine, dev_priv) {
bool V_485 = F_98 ( V_129 ) ;
T_6 V_472 ;
T_2 V_456 ;
T_2 V_486 ;
F_254 ( V_2 ) ;
if ( V_129 -> V_487 )
V_129 -> V_487 ( V_129 ) ;
V_472 = F_266 ( V_129 ) ;
V_456 = F_252 ( V_129 ) ;
V_486 = F_32 ( V_129 -> V_488 ) ;
if ( V_129 -> V_464 . V_456 == V_456 ) {
if ( F_251 ( V_456 , V_486 ) ) {
V_129 -> V_464 . V_489 = V_490 ;
} else {
V_129 -> V_464 . V_489 =
F_257 ( V_129 , V_472 ) ;
switch ( V_129 -> V_464 . V_489 ) {
case V_490 :
case V_478 :
break;
case V_473 :
V_129 -> V_464 . V_491 += F_261 ;
break;
case V_477 :
V_129 -> V_464 . V_491 += F_262 ;
break;
case V_474 :
V_129 -> V_464 . V_491 += F_263 ;
break;
}
}
if ( V_129 -> V_464 . V_491 >= V_492 ) {
V_480 |= F_267 ( V_129 ) ;
if ( V_129 -> V_464 . V_489 != V_474 )
V_468 |= F_267 ( V_129 ) ;
}
} else {
V_129 -> V_464 . V_489 = V_473 ;
if ( V_129 -> V_464 . V_491 > 0 )
V_129 -> V_464 . V_491 -= F_264 ;
if ( V_129 -> V_464 . V_491 < 0 )
V_129 -> V_464 . V_491 = 0 ;
V_472 = 0 ;
memset ( V_129 -> V_464 . V_411 , 0 ,
sizeof( V_129 -> V_464 . V_411 ) ) ;
}
V_129 -> V_464 . V_456 = V_456 ;
V_129 -> V_464 . V_472 = V_472 ;
V_481 += V_485 ;
}
if ( V_480 ) {
char V_493 [ 80 ] ;
unsigned int V_470 ;
int V_494 ;
if ( V_468 != V_480 )
V_480 &= ~ V_468 ;
V_494 = F_268 ( V_493 , sizeof( V_493 ) ,
L_58 , V_468 == V_480 ? L_59 : L_60 ) ;
F_269 (engine, dev_priv, hung, tmp)
V_494 += F_268 ( V_493 + V_494 , sizeof( V_493 ) - V_494 ,
L_61 , V_129 -> V_454 ) ;
V_493 [ V_494 - 2 ] = '\0' ;
return F_226 ( V_2 , V_480 , V_493 ) ;
}
if ( V_481 )
F_270 ( V_2 ) ;
}
static void F_271 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( F_200 ( V_43 ) )
return;
F_272 ( V_495 ) ;
if ( F_195 ( V_43 ) || F_273 ( V_43 ) )
F_5 ( V_328 , 0xffffffff ) ;
}
static void F_274 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( F_200 ( V_43 ) )
return;
F_9 ( F_2 ( V_369 ) != 0 ) ;
F_5 ( V_369 , 0xffffffff ) ;
F_6 ( V_369 ) ;
}
static void F_275 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_272 ( V_496 ) ;
if ( F_20 ( V_43 ) -> V_16 >= 6 )
F_272 ( V_497 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
enum V_32 V_32 ;
if ( F_50 ( V_2 ) )
F_5 ( V_498 , V_499 ) ;
else
F_5 ( V_498 , V_500 ) ;
F_7 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_284 , F_2 ( V_284 ) ) ;
F_164 (dev_priv, pipe) {
F_5 ( F_43 ( V_32 ) ,
V_46 |
V_40 ) ;
V_2 -> V_41 [ V_32 ] = 0 ;
}
F_272 ( V_501 ) ;
V_2 -> V_12 = ~ 0 ;
}
static void F_277 ( struct V_1 * V_2 )
{
T_2 V_502 ;
T_2 V_36 ;
enum V_32 V_32 ;
V_502 = V_280 |
V_281 ;
F_48 ( V_2 , V_55 , V_282 ) ;
F_164 (dev_priv, pipe)
F_48 ( V_2 , V_32 , V_502 ) ;
V_36 = V_296 |
V_275 |
V_276 ;
if ( F_50 ( V_2 ) )
V_36 |= V_278 ;
F_9 ( V_2 -> V_12 != ~ 0 ) ;
V_2 -> V_12 = ~ V_36 ;
F_278 ( V_501 , V_2 -> V_12 , V_36 ) ;
}
static void F_279 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_5 ( V_503 , 0xffffffff ) ;
F_272 ( V_504 ) ;
if ( F_280 ( V_43 ) )
F_5 ( V_325 , 0xffffffff ) ;
F_275 ( V_43 ) ;
F_271 ( V_43 ) ;
}
static void F_281 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_5 ( V_294 , 0 ) ;
F_6 ( V_294 ) ;
F_275 ( V_43 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_273 )
F_276 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
F_283 ( V_496 , 0 ) ;
F_283 ( V_496 , 1 ) ;
F_283 ( V_496 , 2 ) ;
F_283 ( V_496 , 3 ) ;
}
static void F_284 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
F_5 ( V_298 , 0 ) ;
F_6 ( V_298 ) ;
F_282 ( V_2 ) ;
F_164 (dev_priv, pipe)
if ( F_285 ( V_2 ,
F_286 ( V_32 ) ) )
F_283 ( V_505 , V_32 ) ;
F_272 ( V_506 ) ;
F_272 ( V_507 ) ;
F_272 ( V_508 ) ;
if ( F_208 ( V_43 ) )
F_271 ( V_43 ) ;
}
void F_287 ( struct V_1 * V_2 ,
unsigned int V_509 )
{
T_3 V_510 = V_389 | V_393 ;
enum V_32 V_32 ;
F_11 ( & V_2 -> V_7 ) ;
F_288 (dev_priv, pipe, pipe_mask)
F_289 ( V_505 , V_32 ,
V_2 -> V_33 [ V_32 ] ,
~ V_2 -> V_33 [ V_32 ] | V_510 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_290 ( struct V_1 * V_2 ,
unsigned int V_509 )
{
enum V_32 V_32 ;
F_11 ( & V_2 -> V_7 ) ;
F_288 (dev_priv, pipe, pipe_mask)
F_283 ( V_505 , V_32 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_36 ( V_2 -> V_27 . V_28 ) ;
}
static void F_291 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_5 ( V_298 , 0 ) ;
F_6 ( V_298 ) ;
F_282 ( V_2 ) ;
F_272 ( V_508 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_273 )
F_276 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static T_2 F_292 ( struct V_1 * V_2 ,
const T_2 V_247 [ V_248 ] )
{
struct V_511 * V_512 ;
T_2 V_513 = 0 ;
F_293 (&dev_priv->drm, encoder)
if ( V_2 -> V_514 . V_515 [ V_512 -> V_516 ] . V_517 == V_518 )
V_513 |= V_247 [ V_512 -> V_516 ] ;
return V_513 ;
}
static void F_294 ( struct V_1 * V_2 )
{
T_2 V_519 , V_514 , V_513 ;
if ( F_295 ( V_2 ) ) {
V_519 = V_306 ;
V_513 = F_292 ( V_2 , V_307 ) ;
} else {
V_519 = V_334 ;
V_513 = F_292 ( V_2 , V_335 ) ;
}
F_41 ( V_2 , V_519 , V_513 ) ;
V_514 = F_2 ( V_300 ) ;
V_514 &= ~ ( V_520 | V_521 | V_522 ) ;
V_514 |= V_523 | V_524 ;
V_514 |= V_525 | V_526 ;
V_514 |= V_527 | V_528 ;
if ( F_296 ( V_2 ) )
V_514 |= V_529 ;
F_5 ( V_300 , V_514 ) ;
}
static void F_297 ( struct V_1 * V_2 )
{
T_2 V_519 , V_514 , V_513 ;
V_519 = V_344 ;
V_513 = F_292 ( V_2 , V_347 ) ;
F_41 ( V_2 , V_519 , V_513 ) ;
V_514 = F_2 ( V_300 ) ;
V_514 |= V_523 | V_525 |
V_527 | V_529 ;
F_5 ( V_300 , V_514 ) ;
V_514 = F_2 ( V_348 ) ;
V_514 |= V_530 ;
F_5 ( V_348 , V_514 ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
T_2 V_519 , V_514 , V_513 ;
if ( F_54 ( V_2 ) >= 8 ) {
V_519 = V_384 ;
V_513 = F_292 ( V_2 , V_385 ) ;
F_38 ( V_2 , V_519 , V_513 ) ;
} else if ( F_54 ( V_2 ) >= 7 ) {
V_519 = V_359 ;
V_513 = F_292 ( V_2 , V_360 ) ;
F_13 ( V_2 , V_519 , V_513 ) ;
} else {
V_519 = V_351 ;
V_513 = F_292 ( V_2 , V_352 ) ;
F_13 ( V_2 , V_519 , V_513 ) ;
}
V_514 = F_2 ( V_349 ) ;
V_514 &= ~ V_531 ;
V_514 |= V_532 | V_533 ;
F_5 ( V_349 , V_514 ) ;
F_294 ( V_2 ) ;
}
static void F_299 ( struct V_1 * V_2 )
{
T_2 V_519 , V_514 , V_513 ;
V_513 = F_292 ( V_2 , V_383 ) ;
V_519 = V_382 ;
F_38 ( V_2 , V_519 , V_513 ) ;
V_514 = F_2 ( V_300 ) ;
V_514 |= V_525 | V_527 |
V_529 ;
F_80 ( L_62 ,
V_514 , V_513 ) ;
V_514 &= ~ V_534 ;
if ( ( V_513 & V_535 ) &&
F_300 ( V_2 , V_229 ) )
V_514 |= V_536 ;
if ( ( V_513 & V_537 ) &&
F_300 ( V_2 , V_231 ) )
V_514 |= V_538 ;
if ( ( V_513 & V_539 ) &&
F_300 ( V_2 , V_233 ) )
V_514 |= V_540 ;
F_5 ( V_300 , V_514 ) ;
}
static void F_301 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_5 ;
if ( F_200 ( V_43 ) )
return;
if ( F_295 ( V_43 ) )
V_5 = V_311 | V_310 | V_314 ;
else
V_5 = V_339 | V_338 ;
F_1 ( V_2 , V_357 ) ;
F_5 ( V_35 , ~ V_5 ) ;
}
static void F_302 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_541 , V_542 ;
V_541 = V_542 = 0 ;
V_2 -> V_14 = ~ 0 ;
if ( F_118 ( V_43 ) ) {
V_2 -> V_14 = ~ F_116 ( V_43 ) ;
V_542 |= F_116 ( V_43 ) ;
}
V_542 |= V_199 ;
if ( F_196 ( V_43 ) ) {
V_542 |= V_201 ;
} else {
V_542 |= V_204 | V_203 ;
}
F_278 ( V_496 , V_2 -> V_14 , V_542 ) ;
if ( F_20 ( V_43 ) -> V_16 >= 6 ) {
if ( F_159 ( V_43 ) )
V_541 |= V_269 ;
V_2 -> V_20 = 0xffffffff ;
F_278 ( V_497 , V_2 -> V_20 , V_541 ) ;
}
}
static int F_303 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_543 , V_544 ;
if ( F_20 ( V_43 ) -> V_16 >= 7 ) {
V_543 = ( V_368 | V_363 |
V_364 | V_545 |
V_546 |
V_547 | V_362 ) ;
V_544 = ( V_548 | V_549 |
V_550 | V_361 |
V_359 ) ;
} else {
V_543 = ( V_368 | V_354 | V_356 |
V_551 | V_552 |
V_353 |
V_553 | V_554 |
V_355 ) ;
V_544 = ( V_555 | V_556 | V_358 |
V_557 | V_558 |
V_351 ) ;
}
V_2 -> V_12 = ~ V_543 ;
F_5 ( V_503 , 0xeffe ) ;
F_274 ( V_43 ) ;
F_278 ( V_504 , V_2 -> V_12 , V_543 | V_544 ) ;
F_302 ( V_43 ) ;
F_301 ( V_43 ) ;
if ( F_304 ( V_43 ) ) {
F_11 ( & V_2 -> V_7 ) ;
F_232 ( V_2 , V_358 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
return 0 ;
}
void F_305 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_273 )
return;
V_2 -> V_273 = true ;
if ( F_14 ( V_2 ) ) {
F_276 ( V_2 ) ;
F_277 ( V_2 ) ;
}
}
void F_306 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_273 )
return;
V_2 -> V_273 = false ;
if ( F_14 ( V_2 ) )
F_276 ( V_2 ) ;
}
static int F_307 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_302 ( V_43 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_273 )
F_277 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_5 ( V_294 , V_297 ) ;
F_6 ( V_294 ) ;
return 0 ;
}
static void F_308 ( struct V_1 * V_2 )
{
T_3 V_559 [] = {
V_199 << V_221 |
V_210 << V_221 |
V_199 << V_222 |
V_210 << V_222 ,
V_199 << V_223 |
V_210 << V_223 |
V_199 << V_225 |
V_210 << V_225 ,
0 ,
V_199 << V_227 |
V_210 << V_227
} ;
if ( F_118 ( V_2 ) )
V_559 [ 0 ] |= V_196 ;
V_2 -> V_20 = 0xffffffff ;
F_289 ( V_496 , 0 , ~ V_559 [ 0 ] , V_559 [ 0 ] ) ;
F_289 ( V_496 , 1 , ~ V_559 [ 1 ] , V_559 [ 1 ] ) ;
F_289 ( V_496 , 2 , V_2 -> V_20 , 0 ) ;
F_289 ( V_496 , 3 , ~ V_559 [ 3 ] , V_559 [ 3 ] ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
T_3 V_560 = V_392 ;
T_3 V_561 ;
T_2 V_562 = V_378 ;
T_2 V_563 ;
T_2 V_564 = V_373 ;
enum V_32 V_32 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 ) {
V_560 |= V_390 |
V_394 ;
V_562 |= V_379 | V_380 |
V_381 ;
if ( F_204 ( V_2 ) )
V_562 |= V_386 ;
} else {
V_560 |= V_391 |
V_395 ;
}
V_561 = V_560 | V_389 |
V_393 ;
V_563 = V_562 ;
if ( F_204 ( V_2 ) )
V_563 |= V_382 ;
else if ( F_205 ( V_2 ) )
V_563 |= V_384 ;
V_2 -> V_33 [ V_55 ] = ~ V_560 ;
V_2 -> V_33 [ V_53 ] = ~ V_560 ;
V_2 -> V_33 [ V_277 ] = ~ V_560 ;
F_164 (dev_priv, pipe)
if ( F_285 ( V_2 ,
F_286 ( V_32 ) ) )
F_289 ( V_505 , V_32 ,
V_2 -> V_33 [ V_32 ] ,
V_561 ) ;
F_278 ( V_506 , ~ V_562 , V_563 ) ;
F_278 ( V_507 , ~ V_564 , V_564 ) ;
}
static int F_310 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( F_208 ( V_43 ) )
F_274 ( V_43 ) ;
F_308 ( V_2 ) ;
F_309 ( V_2 ) ;
if ( F_208 ( V_43 ) )
F_301 ( V_43 ) ;
F_5 ( V_298 , V_299 ) ;
F_6 ( V_298 ) ;
return 0 ;
}
static int F_311 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_308 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_273 )
F_277 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_5 ( V_298 , V_299 ) ;
F_6 ( V_298 ) ;
return 0 ;
}
static void F_312 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( ! V_2 )
return;
F_284 ( V_43 ) ;
}
static void F_313 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( ! V_2 )
return;
F_5 ( V_294 , 0 ) ;
F_6 ( V_294 ) ;
F_275 ( V_43 ) ;
F_5 ( V_503 , 0xffffffff ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_273 )
F_276 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_314 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( ! V_2 )
return;
F_5 ( V_298 , 0 ) ;
F_6 ( V_298 ) ;
F_282 ( V_2 ) ;
F_272 ( V_508 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_273 )
F_276 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_315 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
if ( ! V_2 )
return;
F_279 ( V_43 ) ;
}
static void F_316 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
F_164 (dev_priv, pipe)
F_5 ( F_43 ( V_32 ) , 0 ) ;
F_84 ( V_565 , 0xffff ) ;
F_84 ( V_566 , 0x0 ) ;
F_317 ( V_566 ) ;
}
static int F_318 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
F_84 ( V_432 ,
~ ( V_425 | V_426 ) ) ;
V_2 -> V_12 =
~ ( V_275 |
V_276 |
V_567 |
V_568 ) ;
F_84 ( V_565 , V_2 -> V_12 ) ;
F_84 ( V_566 ,
V_275 |
V_276 |
V_569 ) ;
F_317 ( V_566 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_48 ( V_2 , V_55 , V_281 ) ;
F_48 ( V_2 , V_53 , V_281 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_319 ( struct V_1 * V_2 ,
int V_570 , int V_32 , T_2 V_194 )
{
T_12 V_571 = F_320 ( V_570 ) ;
if ( ! F_160 ( V_2 , V_32 ) )
return false ;
if ( ( V_194 & V_571 ) == 0 )
goto V_572;
if ( F_321 ( V_573 ) & V_571 )
goto V_572;
F_167 ( V_2 , V_32 ) ;
return true ;
V_572:
F_166 ( V_2 , V_32 ) ;
return false ;
}
static T_9 F_322 ( int V_28 , void * V_290 )
{
struct V_42 * V_43 = V_290 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_12 V_194 , V_574 ;
T_2 V_271 [ 2 ] ;
int V_32 ;
T_12 V_575 =
V_567 |
V_568 ;
T_9 V_96 ;
if ( ! F_14 ( V_2 ) )
return V_213 ;
F_173 ( V_2 ) ;
V_96 = V_213 ;
V_194 = F_321 ( V_433 ) ;
if ( V_194 == 0 )
goto V_183;
while ( V_194 & ~ V_575 ) {
F_83 ( & V_2 -> V_7 ) ;
if ( V_194 & V_434 )
F_114 ( L_63 , V_194 ) ;
F_164 (dev_priv, pipe) {
T_1 V_3 = F_43 ( V_32 ) ;
V_271 [ V_32 ] = F_2 ( V_3 ) ;
if ( V_271 [ V_32 ] & 0x8000ffff )
F_5 ( V_3 , V_271 [ V_32 ] ) ;
}
F_86 ( & V_2 -> V_7 ) ;
F_84 ( V_433 , V_194 & ~ V_575 ) ;
V_574 = F_321 ( V_433 ) ;
if ( V_194 & V_569 )
F_87 ( & V_2 -> V_129 [ V_200 ] ) ;
F_164 (dev_priv, pipe) {
int V_570 = V_32 ;
if ( F_323 ( V_2 ) )
V_570 = ! V_570 ;
if ( V_271 [ V_32 ] & V_438 &&
F_319 ( V_2 , V_570 , V_32 , V_194 ) )
V_575 &= ~ F_320 ( V_570 ) ;
if ( V_271 [ V_32 ] & V_281 )
F_152 ( V_2 , V_32 ) ;
if ( V_271 [ V_32 ] & V_46 )
F_168 ( V_2 ,
V_32 ) ;
}
V_194 = V_574 ;
}
V_96 = V_216 ;
V_183:
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_324 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
F_164 (dev_priv, pipe) {
F_5 ( F_43 ( V_32 ) , 0 ) ;
F_5 ( F_43 ( V_32 ) , F_2 ( F_43 ( V_32 ) ) ) ;
}
F_84 ( V_565 , 0xffff ) ;
F_84 ( V_566 , 0x0 ) ;
F_84 ( V_433 , F_321 ( V_433 ) ) ;
}
static void F_325 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
if ( F_326 ( V_43 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_284 , F_2 ( V_284 ) ) ;
}
F_84 ( V_503 , 0xeffe ) ;
F_164 (dev_priv, pipe)
F_5 ( F_43 ( V_32 ) , 0 ) ;
F_5 ( V_565 , 0xffffffff ) ;
F_5 ( V_566 , 0x0 ) ;
F_6 ( V_566 ) ;
}
static int F_327 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_36 ;
F_5 ( V_432 , ~ ( V_425 | V_426 ) ) ;
V_2 -> V_12 =
~ ( V_576 |
V_275 |
V_276 |
V_567 |
V_568 ) ;
V_36 =
V_576 |
V_275 |
V_276 |
V_569 ;
if ( F_326 ( V_43 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
V_36 |= V_296 ;
V_2 -> V_12 &= ~ V_296 ;
}
F_5 ( V_565 , V_2 -> V_12 ) ;
F_5 ( V_566 , V_36 ) ;
F_6 ( V_566 ) ;
F_52 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_48 ( V_2 , V_55 , V_281 ) ;
F_48 ( V_2 , V_53 , V_281 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_328 ( struct V_1 * V_2 ,
int V_570 , int V_32 , T_2 V_194 )
{
T_2 V_571 = F_320 ( V_570 ) ;
if ( ! F_160 ( V_2 , V_32 ) )
return false ;
if ( ( V_194 & V_571 ) == 0 )
goto V_572;
if ( F_2 ( V_573 ) & V_571 )
goto V_572;
F_167 ( V_2 , V_32 ) ;
return true ;
V_572:
F_166 ( V_2 , V_32 ) ;
return false ;
}
static T_9 F_329 ( int V_28 , void * V_290 )
{
struct V_42 * V_43 = V_290 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_194 , V_574 , V_271 [ V_272 ] ;
T_2 V_575 =
V_567 |
V_568 ;
int V_32 , V_96 = V_213 ;
if ( ! F_14 ( V_2 ) )
return V_213 ;
F_173 ( V_2 ) ;
V_194 = F_2 ( V_433 ) ;
do {
bool V_577 = ( V_194 & ~ V_575 ) != 0 ;
bool V_578 = false ;
F_83 ( & V_2 -> V_7 ) ;
if ( V_194 & V_434 )
F_114 ( L_63 , V_194 ) ;
F_164 (dev_priv, pipe) {
T_1 V_3 = F_43 ( V_32 ) ;
V_271 [ V_32 ] = F_2 ( V_3 ) ;
if ( V_271 [ V_32 ] & 0x8000ffff ) {
F_5 ( V_3 , V_271 [ V_32 ] ) ;
V_577 = true ;
}
}
F_86 ( & V_2 -> V_7 ) ;
if ( ! V_577 )
break;
if ( F_326 ( V_2 ) &&
V_194 & V_296 ) {
T_2 V_283 = F_169 ( V_2 ) ;
if ( V_283 )
F_170 ( V_2 , V_283 ) ;
}
F_5 ( V_433 , V_194 & ~ V_575 ) ;
V_574 = F_2 ( V_433 ) ;
if ( V_194 & V_569 )
F_87 ( & V_2 -> V_129 [ V_200 ] ) ;
F_164 (dev_priv, pipe) {
int V_570 = V_32 ;
if ( F_323 ( V_2 ) )
V_570 = ! V_570 ;
if ( V_271 [ V_32 ] & V_438 &&
F_328 ( V_2 , V_570 , V_32 , V_194 ) )
V_575 &= ~ F_320 ( V_570 ) ;
if ( V_271 [ V_32 ] & V_54 )
V_578 = true ;
if ( V_271 [ V_32 ] & V_281 )
F_152 ( V_2 , V_32 ) ;
if ( V_271 [ V_32 ] & V_46 )
F_168 ( V_2 ,
V_32 ) ;
}
if ( V_578 || ( V_194 & V_576 ) )
F_190 ( V_2 ) ;
V_96 = V_216 ;
V_194 = V_574 ;
} while ( V_194 & ~ V_575 );
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_330 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
if ( F_326 ( V_43 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_284 , F_2 ( V_284 ) ) ;
}
F_84 ( V_503 , 0xffff ) ;
F_164 (dev_priv, pipe) {
F_5 ( F_43 ( V_32 ) , 0 ) ;
F_5 ( F_43 ( V_32 ) , F_2 ( F_43 ( V_32 ) ) ) ;
}
F_5 ( V_565 , 0xffffffff ) ;
F_5 ( V_566 , 0x0 ) ;
F_5 ( V_433 , F_2 ( V_433 ) ) ;
}
static void F_331 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_284 , F_2 ( V_284 ) ) ;
F_5 ( V_503 , 0xeffe ) ;
F_164 (dev_priv, pipe)
F_5 ( F_43 ( V_32 ) , 0 ) ;
F_5 ( V_565 , 0xffffffff ) ;
F_5 ( V_566 , 0x0 ) ;
F_6 ( V_566 ) ;
}
static int F_332 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_36 ;
T_2 V_579 ;
V_2 -> V_12 = ~ ( V_576 |
V_296 |
V_275 |
V_276 |
V_567 |
V_568 |
V_434 ) ;
V_36 = ~ V_2 -> V_12 ;
V_36 &= ~ ( V_567 |
V_568 ) ;
V_36 |= V_569 ;
if ( F_74 ( V_2 ) )
V_36 |= V_580 ;
F_11 ( & V_2 -> V_7 ) ;
F_48 ( V_2 , V_55 , V_282 ) ;
F_48 ( V_2 , V_55 , V_281 ) ;
F_48 ( V_2 , V_53 , V_281 ) ;
F_12 ( & V_2 -> V_7 ) ;
if ( F_74 ( V_2 ) ) {
V_579 = ~ ( V_422 |
V_415 |
V_416 |
V_426 ) ;
} else {
V_579 = ~ ( V_425 |
V_426 ) ;
}
F_5 ( V_432 , V_579 ) ;
F_5 ( V_565 , V_2 -> V_12 ) ;
F_5 ( V_566 , V_36 ) ;
F_6 ( V_566 ) ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
static void F_333 ( struct V_1 * V_2 )
{
T_2 V_581 ;
F_8 ( & V_2 -> V_7 ) ;
V_581 = F_292 ( V_2 , V_582 ) ;
if ( F_74 ( V_2 ) )
V_581 |= V_583 ;
V_581 |= V_584 ;
F_7 ( V_2 ,
V_585 |
V_586 |
V_583 ,
V_581 ) ;
}
static T_9 F_334 ( int V_28 , void * V_290 )
{
struct V_42 * V_43 = V_290 ;
struct V_1 * V_2 = F_56 ( V_43 ) ;
T_2 V_194 , V_574 ;
T_2 V_271 [ V_272 ] ;
int V_96 = V_213 , V_32 ;
T_2 V_575 =
V_567 |
V_568 ;
if ( ! F_14 ( V_2 ) )
return V_213 ;
F_173 ( V_2 ) ;
V_194 = F_2 ( V_433 ) ;
for (; ; ) {
bool V_577 = ( V_194 & ~ V_575 ) != 0 ;
bool V_578 = false ;
F_83 ( & V_2 -> V_7 ) ;
if ( V_194 & V_434 )
F_114 ( L_63 , V_194 ) ;
F_164 (dev_priv, pipe) {
T_1 V_3 = F_43 ( V_32 ) ;
V_271 [ V_32 ] = F_2 ( V_3 ) ;
if ( V_271 [ V_32 ] & 0x8000ffff ) {
F_5 ( V_3 , V_271 [ V_32 ] ) ;
V_577 = true ;
}
}
F_86 ( & V_2 -> V_7 ) ;
if ( ! V_577 )
break;
V_96 = V_216 ;
if ( V_194 & V_296 ) {
T_2 V_283 = F_169 ( V_2 ) ;
if ( V_283 )
F_170 ( V_2 , V_283 ) ;
}
F_5 ( V_433 , V_194 & ~ V_575 ) ;
V_574 = F_2 ( V_433 ) ;
if ( V_194 & V_569 )
F_87 ( & V_2 -> V_129 [ V_200 ] ) ;
if ( V_194 & V_580 )
F_87 ( & V_2 -> V_129 [ V_202 ] ) ;
F_164 (dev_priv, pipe) {
if ( V_271 [ V_32 ] & V_279 &&
F_328 ( V_2 , V_32 , V_32 , V_194 ) )
V_575 &= ~ F_320 ( V_32 ) ;
if ( V_271 [ V_32 ] & V_54 )
V_578 = true ;
if ( V_271 [ V_32 ] & V_281 )
F_152 ( V_2 , V_32 ) ;
if ( V_271 [ V_32 ] & V_46 )
F_168 ( V_2 , V_32 ) ;
}
if ( V_578 || ( V_194 & V_576 ) )
F_190 ( V_2 ) ;
if ( V_271 [ 0 ] & V_282 )
F_139 ( V_2 ) ;
V_194 = V_574 ;
}
F_174 ( V_2 ) ;
return V_96 ;
}
static void F_335 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_56 ( V_43 ) ;
int V_32 ;
if ( ! V_2 )
return;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_284 , F_2 ( V_284 ) ) ;
F_5 ( V_503 , 0xffffffff ) ;
F_164 (dev_priv, pipe)
F_5 ( F_43 ( V_32 ) , 0 ) ;
F_5 ( V_565 , 0xffffffff ) ;
F_5 ( V_566 , 0x0 ) ;
F_164 (dev_priv, pipe)
F_5 ( F_43 ( V_32 ) ,
F_2 ( F_43 ( V_32 ) ) & 0x8000ffff ) ;
F_5 ( V_433 , F_2 ( V_433 ) ) ;
}
void F_336 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = & V_2 -> V_27 ;
F_337 ( V_2 ) ;
F_338 ( & V_2 -> V_22 . V_29 , F_99 ) ;
F_338 ( & V_2 -> V_172 . V_173 , F_105 ) ;
if ( F_49 ( V_2 ) )
V_2 -> V_21 = V_152 | V_153 ;
else
V_2 -> V_21 = V_587 ;
V_2 -> V_22 . V_25 = 0 ;
if ( F_20 ( V_2 ) -> V_16 <= 7 && ! F_339 ( V_2 ) )
V_2 -> V_22 . V_25 |= V_153 ;
if ( F_20 ( V_2 ) -> V_16 >= 8 )
V_2 -> V_22 . V_25 |= V_588 ;
F_340 ( & V_2 -> V_397 . V_479 ,
F_259 ) ;
if ( F_64 ( V_2 ) ) {
V_43 -> V_589 = 0 ;
V_43 -> V_264 -> V_265 = V_590 ;
} else if ( F_74 ( V_2 ) || F_20 ( V_2 ) -> V_16 >= 5 ) {
V_43 -> V_589 = 0xffffffff ;
V_43 -> V_264 -> V_265 = F_61 ;
} else {
V_43 -> V_264 -> V_265 = F_55 ;
V_43 -> V_589 = 0xffffff ;
}
if ( ! F_64 ( V_2 ) )
V_43 -> V_591 = true ;
V_43 -> V_264 -> V_592 = F_77 ;
V_43 -> V_264 -> V_593 = F_70 ;
if ( F_50 ( V_2 ) ) {
V_43 -> V_264 -> V_594 = F_175 ;
V_43 -> V_264 -> V_595 = F_291 ;
V_43 -> V_264 -> V_596 = F_311 ;
V_43 -> V_264 -> V_597 = F_314 ;
V_43 -> V_264 -> V_598 = F_233 ;
V_43 -> V_264 -> V_599 = F_239 ;
V_2 -> V_600 . V_601 = F_333 ;
} else if ( F_49 ( V_2 ) ) {
V_43 -> V_264 -> V_594 = F_172 ;
V_43 -> V_264 -> V_595 = F_281 ;
V_43 -> V_264 -> V_596 = F_307 ;
V_43 -> V_264 -> V_597 = F_313 ;
V_43 -> V_264 -> V_598 = F_233 ;
V_43 -> V_264 -> V_599 = F_239 ;
V_2 -> V_600 . V_601 = F_333 ;
} else if ( F_20 ( V_2 ) -> V_16 >= 8 ) {
V_43 -> V_264 -> V_594 = F_211 ;
V_43 -> V_264 -> V_595 = F_284 ;
V_43 -> V_264 -> V_596 = F_310 ;
V_43 -> V_264 -> V_597 = F_312 ;
V_43 -> V_264 -> V_598 = F_234 ;
V_43 -> V_264 -> V_599 = F_240 ;
if ( F_204 ( V_43 ) )
V_2 -> V_600 . V_601 = F_299 ;
else if ( F_209 ( V_43 ) || F_210 ( V_43 ) )
V_2 -> V_600 . V_601 = F_297 ;
else
V_2 -> V_600 . V_601 = F_298 ;
} else if ( F_208 ( V_43 ) ) {
V_43 -> V_264 -> V_594 = F_201 ;
V_43 -> V_264 -> V_595 = F_279 ;
V_43 -> V_264 -> V_596 = F_303 ;
V_43 -> V_264 -> V_597 = F_315 ;
V_43 -> V_264 -> V_598 = F_231 ;
V_43 -> V_264 -> V_599 = F_237 ;
V_2 -> V_600 . V_601 = F_298 ;
} else {
if ( F_64 ( V_2 ) ) {
V_43 -> V_264 -> V_595 = F_316 ;
V_43 -> V_264 -> V_596 = F_318 ;
V_43 -> V_264 -> V_594 = F_322 ;
V_43 -> V_264 -> V_597 = F_324 ;
} else if ( F_341 ( V_2 ) ) {
V_43 -> V_264 -> V_595 = F_325 ;
V_43 -> V_264 -> V_596 = F_327 ;
V_43 -> V_264 -> V_597 = F_330 ;
V_43 -> V_264 -> V_594 = F_329 ;
} else {
V_43 -> V_264 -> V_595 = F_331 ;
V_43 -> V_264 -> V_596 = F_332 ;
V_43 -> V_264 -> V_597 = F_335 ;
V_43 -> V_264 -> V_594 = F_334 ;
}
if ( F_326 ( V_2 ) )
V_2 -> V_600 . V_601 = F_333 ;
V_43 -> V_264 -> V_598 = F_230 ;
V_43 -> V_264 -> V_599 = F_236 ;
}
}
int F_342 ( struct V_1 * V_2 )
{
V_2 -> V_602 . V_603 = true ;
return F_343 ( & V_2 -> V_27 , V_2 -> V_27 . V_604 -> V_28 ) ;
}
void F_344 ( struct V_1 * V_2 )
{
F_345 ( & V_2 -> V_27 ) ;
F_346 ( V_2 ) ;
V_2 -> V_602 . V_603 = false ;
}
void F_347 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_264 -> V_597 ( & V_2 -> V_27 ) ;
V_2 -> V_602 . V_603 = false ;
F_36 ( V_2 -> V_27 . V_28 ) ;
}
void F_348 ( struct V_1 * V_2 )
{
V_2 -> V_602 . V_603 = true ;
V_2 -> V_27 . V_264 -> V_595 ( & V_2 -> V_27 ) ;
V_2 -> V_27 . V_264 -> V_596 ( & V_2 -> V_27 ) ;
}
