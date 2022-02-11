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
void F_27 ( struct V_1 * V_2 , T_2 V_5 )
{
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_26 ( V_2 , V_5 , V_5 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_5 )
{
F_26 ( V_2 , V_5 , 0 ) ;
}
void F_29 ( struct V_1 * V_2 , T_2 V_5 )
{
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_28 ( V_2 , V_5 ) ;
}
void F_30 ( struct V_1 * V_2 , T_2 V_21 )
{
T_1 V_3 = F_19 ( V_2 ) ;
F_8 ( & V_2 -> V_7 ) ;
F_5 ( V_3 , V_21 ) ;
F_5 ( V_3 , V_21 ) ;
F_6 ( V_3 ) ;
}
void F_31 ( struct V_1 * V_2 , T_2 V_22 )
{
F_8 ( & V_2 -> V_7 ) ;
V_2 -> V_23 |= V_22 ;
F_5 ( F_24 ( V_2 ) , V_2 -> V_23 ) ;
F_27 ( V_2 , V_22 ) ;
}
void F_32 ( struct V_1 * V_2 , T_2 V_24 )
{
F_8 ( & V_2 -> V_7 ) ;
V_2 -> V_23 &= ~ V_24 ;
F_28 ( V_2 , V_24 ) ;
F_5 ( F_24 ( V_2 ) , V_2 -> V_23 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
F_30 ( V_2 , V_2 -> V_25 ) ;
V_2 -> V_26 . V_27 = 0 ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( F_35 ( V_2 -> V_26 . V_28 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
F_36 ( V_2 -> V_26 . V_27 ) ;
F_36 ( F_2 ( F_19 ( V_2 ) ) & V_2 -> V_25 ) ;
V_2 -> V_26 . V_28 = true ;
F_31 ( V_2 , V_2 -> V_25 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
T_2 F_37 ( struct V_1 * V_2 , T_2 V_5 )
{
return ( V_5 & ~ V_2 -> V_26 . V_29 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( ! F_35 ( V_2 -> V_26 . V_28 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
V_2 -> V_26 . V_28 = false ;
F_5 ( V_30 , F_37 ( V_2 , ~ 0u ) ) ;
F_32 ( V_2 , V_2 -> V_25 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_39 ( V_2 -> V_31 . V_32 ) ;
F_40 ( & V_2 -> V_26 . V_33 ) ;
F_33 ( V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
F_30 ( V_2 , V_2 -> V_34 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_35 . V_28 ) {
F_36 ( F_2 ( F_19 ( V_2 ) ) &
V_2 -> V_34 ) ;
V_2 -> V_35 . V_28 = true ;
F_31 ( V_2 , V_2 -> V_34 ) ;
}
F_12 ( & V_2 -> V_7 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
V_2 -> V_35 . V_28 = false ;
F_32 ( V_2 , V_2 -> V_34 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_39 ( V_2 -> V_31 . V_32 ) ;
F_41 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
T_3 V_36 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_36 = F_2 ( V_37 ) ;
V_11 = V_36 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_36 ) {
F_5 ( V_37 , V_11 ) ;
F_6 ( V_37 ) ;
}
}
void F_45 ( struct V_1 * V_2 ,
enum V_38 V_38 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_11 = V_2 -> V_39 [ V_38 ] ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_39 [ V_38 ] ) {
V_2 -> V_39 [ V_38 ] = V_11 ;
F_5 ( F_46 ( V_38 ) , V_2 -> V_39 [ V_38 ] ) ;
F_6 ( F_46 ( V_38 ) ) ;
}
}
void F_47 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_40 = F_2 ( V_41 ) ;
V_40 &= ~ V_9 ;
V_40 |= ( ~ V_10 & V_9 ) ;
F_9 ( V_10 & ~ V_9 ) ;
F_8 ( & V_2 -> V_7 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_5 ( V_41 , V_40 ) ;
F_6 ( V_41 ) ;
}
static void
F_48 ( struct V_1 * V_2 , enum V_38 V_38 ,
T_2 V_22 , T_2 V_42 )
{
T_1 V_3 = F_49 ( V_38 ) ;
T_2 V_43 = F_2 ( V_3 ) & V_44 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_50 ( V_22 & ~ V_44 ||
V_42 & ~ V_45 ,
L_2 ,
F_51 ( V_38 ) , V_22 , V_42 ) )
return;
if ( ( V_43 & V_22 ) == V_22 )
return;
V_2 -> V_46 [ V_38 ] |= V_42 ;
V_43 |= V_22 | V_42 ;
F_5 ( V_3 , V_43 ) ;
F_6 ( V_3 ) ;
}
static void
F_52 ( struct V_1 * V_2 , enum V_38 V_38 ,
T_2 V_22 , T_2 V_42 )
{
T_1 V_3 = F_49 ( V_38 ) ;
T_2 V_43 = F_2 ( V_3 ) & V_44 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_50 ( V_22 & ~ V_44 ||
V_42 & ~ V_45 ,
L_2 ,
F_51 ( V_38 ) , V_22 , V_42 ) )
return;
if ( ( V_43 & V_22 ) == 0 )
return;
V_2 -> V_46 [ V_38 ] &= ~ V_42 ;
V_43 &= ~ V_22 ;
F_5 ( V_3 , V_43 ) ;
F_6 ( V_3 ) ;
}
static T_2 F_53 ( struct V_47 * V_48 , T_2 V_42 )
{
T_2 V_22 = V_42 << 16 ;
if ( F_36 ( V_42 & V_49 ) )
return 0 ;
if ( F_36 ( V_42 & V_50 ) )
return 0 ;
V_22 &= ~ ( V_51 |
V_52 |
V_53 ) ;
if ( V_42 & V_54 )
V_22 |= V_52 ;
if ( V_42 & V_55 )
V_22 |= V_53 ;
return V_22 ;
}
void
F_54 ( struct V_1 * V_2 , enum V_38 V_38 ,
T_2 V_42 )
{
T_2 V_22 ;
if ( F_55 ( V_2 ) || F_56 ( V_2 ) )
V_22 = F_53 ( & V_2 -> V_31 ,
V_42 ) ;
else
V_22 = V_42 << 16 ;
F_48 ( V_2 , V_38 , V_22 , V_42 ) ;
}
void
F_57 ( struct V_1 * V_2 , enum V_38 V_38 ,
T_2 V_42 )
{
T_2 V_22 ;
if ( F_55 ( V_2 ) || F_56 ( V_2 ) )
V_22 = F_53 ( & V_2 -> V_31 ,
V_42 ) ;
else
V_22 = V_42 << 16 ;
F_52 ( V_2 , V_38 , V_22 , V_42 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_56 . V_57 || ! F_59 ( V_2 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
F_54 ( V_2 , V_58 , V_59 ) ;
if ( F_60 ( V_2 ) >= 4 )
F_54 ( V_2 , V_60 ,
V_59 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static T_2 F_61 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_1 V_61 , V_62 ;
T_2 V_63 , V_64 , V_65 , V_66 , V_67 , V_68 , V_69 ;
struct V_70 * V_70 = F_63 ( V_2 ,
V_38 ) ;
const struct V_71 * V_72 = & V_70 -> V_73 . V_74 ;
V_69 = V_72 -> V_75 ;
V_68 = V_72 -> V_76 ;
V_67 = V_72 -> V_77 ;
if ( V_72 -> V_78 & V_79 )
V_67 = F_64 ( V_67 , 2 ) ;
V_67 *= V_69 ;
V_67 -= V_69 - V_68 ;
V_61 = F_65 ( V_38 ) ;
V_62 = F_66 ( V_38 ) ;
do {
V_63 = F_2 ( V_61 ) & V_80 ;
V_65 = F_2 ( V_62 ) ;
V_64 = F_2 ( V_61 ) & V_80 ;
} while ( V_63 != V_64 );
V_63 >>= V_81 ;
V_66 = V_65 & V_82 ;
V_65 >>= V_83 ;
return ( ( ( V_63 << 8 ) | V_65 ) + ( V_66 >= V_67 ) ) & 0xffffff ;
}
static T_2 F_67 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
return F_2 ( F_68 ( V_38 ) ) ;
}
static int F_69 ( struct V_70 * V_84 )
{
struct V_47 * V_48 = V_84 -> V_73 . V_48 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
const struct V_71 * V_72 = & V_84 -> V_73 . V_74 ;
enum V_38 V_38 = V_84 -> V_38 ;
int V_85 , V_86 ;
V_86 = V_72 -> V_87 ;
if ( V_72 -> V_78 & V_79 )
V_86 /= 2 ;
if ( F_70 ( V_2 ) )
V_85 = F_71 ( F_72 ( V_38 ) ) & V_88 ;
else
V_85 = F_71 ( F_72 ( V_38 ) ) & V_89 ;
if ( F_73 ( V_2 ) && ! V_85 ) {
int V_90 , V_91 ;
for ( V_90 = 0 ; V_90 < 100 ; V_90 ++ ) {
F_74 ( 1 ) ;
V_91 = F_75 ( V_2 , F_72 ( V_38 ) ) &
V_89 ;
if ( V_91 != V_85 ) {
V_85 = V_91 ;
break;
}
}
}
return ( V_85 + V_84 -> V_92 ) % V_86 ;
}
static int F_76 ( struct V_47 * V_48 , unsigned int V_38 ,
unsigned int V_78 , int * V_93 , int * V_94 ,
T_4 * V_95 , T_4 * V_96 ,
const struct V_71 * V_72 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
struct V_70 * V_70 = F_63 ( V_2 ,
V_38 ) ;
int V_85 ;
int V_67 , V_97 , V_68 , V_69 , V_86 ;
bool V_98 = true ;
int V_99 = 0 ;
unsigned long V_100 ;
if ( F_9 ( ! V_72 -> V_101 ) ) {
F_77 ( L_3
L_4 , F_51 ( V_38 ) ) ;
return 0 ;
}
V_69 = V_72 -> V_75 ;
V_68 = V_72 -> V_76 ;
V_86 = V_72 -> V_87 ;
V_67 = V_72 -> V_77 ;
V_97 = V_72 -> V_102 ;
if ( V_72 -> V_78 & V_79 ) {
V_67 = F_64 ( V_67 , 2 ) ;
V_97 /= 2 ;
V_86 /= 2 ;
}
V_99 |= V_103 | V_104 ;
F_78 ( & V_2 -> V_105 . V_106 , V_100 ) ;
if ( V_95 )
* V_95 = F_79 () ;
if ( F_70 ( V_2 ) || F_80 ( V_2 ) || F_60 ( V_2 ) >= 5 ) {
V_85 = F_69 ( V_70 ) ;
} else {
V_85 = ( F_71 ( F_66 ( V_38 ) ) & V_82 ) >> V_107 ;
V_67 *= V_69 ;
V_97 *= V_69 ;
V_86 *= V_69 ;
if ( V_85 >= V_86 )
V_85 = V_86 - 1 ;
V_85 = ( V_85 + V_69 - V_68 ) % V_86 ;
}
if ( V_96 )
* V_96 = F_79 () ;
F_81 ( & V_2 -> V_105 . V_106 , V_100 ) ;
V_98 = V_85 >= V_67 && V_85 < V_97 ;
if ( V_85 >= V_67 )
V_85 -= V_97 ;
else
V_85 += V_86 - V_97 ;
if ( F_70 ( V_2 ) || F_80 ( V_2 ) || F_60 ( V_2 ) >= 5 ) {
* V_93 = V_85 ;
* V_94 = 0 ;
} else {
* V_93 = V_85 / V_69 ;
* V_94 = V_85 - ( * V_93 * V_69 ) ;
}
if ( V_98 )
V_99 |= V_108 ;
return V_99 ;
}
int F_82 ( struct V_70 * V_84 )
{
struct V_1 * V_2 = F_62 ( V_84 -> V_73 . V_48 ) ;
unsigned long V_100 ;
int V_85 ;
F_78 ( & V_2 -> V_105 . V_106 , V_100 ) ;
V_85 = F_69 ( V_84 ) ;
F_81 ( & V_2 -> V_105 . V_106 , V_100 ) ;
return V_85 ;
}
static int F_83 ( struct V_47 * V_48 , unsigned int V_38 ,
int * V_109 ,
struct V_110 * V_111 ,
unsigned V_78 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
struct V_70 * V_84 ;
if ( V_38 >= F_20 ( V_2 ) -> V_112 ) {
F_84 ( L_5 , V_38 ) ;
return - V_113 ;
}
V_84 = F_63 ( V_2 , V_38 ) ;
if ( V_84 == NULL ) {
F_84 ( L_5 , V_38 ) ;
return - V_113 ;
}
if ( ! V_84 -> V_73 . V_74 . V_101 ) {
F_85 ( L_6 , V_38 ) ;
return - V_114 ;
}
return F_86 ( V_48 , V_38 , V_109 ,
V_111 , V_78 ,
& V_84 -> V_73 . V_74 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
T_2 V_115 , V_116 , V_117 , V_118 ;
T_5 V_119 ;
F_88 ( & V_120 ) ;
F_89 ( V_121 , F_2 ( V_121 ) ) ;
V_119 = V_2 -> V_122 . V_123 ;
F_89 ( V_121 , V_124 ) ;
V_115 = F_2 ( V_125 ) ;
V_116 = F_2 ( V_126 ) ;
V_117 = F_2 ( V_127 ) ;
V_118 = F_2 ( V_128 ) ;
if ( V_115 > V_117 ) {
if ( V_2 -> V_122 . V_123 != V_2 -> V_122 . V_129 )
V_119 = V_2 -> V_122 . V_123 - 1 ;
if ( V_119 < V_2 -> V_122 . V_129 )
V_119 = V_2 -> V_122 . V_129 ;
} else if ( V_116 < V_118 ) {
if ( V_2 -> V_122 . V_123 != V_2 -> V_122 . V_130 )
V_119 = V_2 -> V_122 . V_123 + 1 ;
if ( V_119 > V_2 -> V_122 . V_130 )
V_119 = V_2 -> V_122 . V_130 ;
}
if ( F_90 ( V_2 , V_119 ) )
V_2 -> V_122 . V_123 = V_119 ;
F_91 ( & V_120 ) ;
return;
}
static void F_92 ( struct V_131 * V_132 )
{
F_93 ( V_132 -> V_133 . V_134 , true ) ;
if ( F_94 ( V_132 ) )
F_95 ( V_132 ) ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
V_136 -> V_137 = F_97 ( V_2 , V_138 ) ;
V_136 -> V_139 = F_2 ( V_140 ) ;
V_136 -> V_141 = F_2 ( V_142 ) ;
}
static bool F_98 ( struct V_1 * V_2 ,
const struct V_135 * V_143 ,
const struct V_135 * V_144 ,
int V_145 )
{
T_6 time , V_146 ;
unsigned int V_147 = 100 ;
if ( V_143 -> V_137 == 0 )
return false ;
if ( F_2 ( V_148 ) & V_149 )
V_147 <<= 8 ;
time = V_144 -> V_137 - V_143 -> V_137 ;
time *= V_145 * V_2 -> V_150 ;
V_146 = V_144 -> V_139 - V_143 -> V_139 ;
V_146 += V_144 -> V_141 - V_143 -> V_141 ;
V_146 *= V_147 * V_151 ;
return V_146 >= time ;
}
void F_99 ( struct V_1 * V_2 )
{
F_96 ( V_2 , & V_2 -> V_26 . V_152 ) ;
V_2 -> V_26 . V_153 = V_2 -> V_26 . V_152 ;
}
static T_2 F_100 ( struct V_1 * V_2 , T_2 V_27 )
{
struct V_135 V_144 ;
T_2 V_154 = 0 ;
if ( ( V_27 & ( V_155 | V_156 ) ) == 0 )
return 0 ;
F_96 ( V_2 , & V_144 ) ;
if ( V_144 . V_137 == 0 )
return 0 ;
if ( V_27 & V_155 ) {
if ( ! F_98 ( V_2 ,
& V_2 -> V_26 . V_152 , & V_144 ,
V_2 -> V_26 . V_157 ) )
V_154 |= V_158 ;
V_2 -> V_26 . V_152 = V_144 ;
}
if ( V_27 & V_156 ) {
if ( F_98 ( V_2 ,
& V_2 -> V_26 . V_153 , & V_144 ,
V_2 -> V_26 . V_159 ) )
V_154 |= V_160 ;
V_2 -> V_26 . V_153 = V_144 ;
}
return V_154 ;
}
static bool F_101 ( struct V_1 * V_2 )
{
struct V_131 * V_132 ;
enum V_161 V_162 ;
F_102 (engine, dev_priv, id)
if ( F_103 ( V_132 ) )
return true ;
return false ;
}
static void F_104 ( struct V_163 * V_33 )
{
struct V_1 * V_2 =
F_105 ( V_33 , struct V_1 , V_26 . V_33 ) ;
bool V_164 ;
int V_119 , V_165 , V_166 , V_167 ;
T_2 V_27 ;
F_11 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_26 . V_28 ) {
F_12 ( & V_2 -> V_7 ) ;
return;
}
V_27 = V_2 -> V_26 . V_27 ;
V_2 -> V_26 . V_27 = 0 ;
F_27 ( V_2 , V_2 -> V_25 ) ;
V_164 = V_2 -> V_26 . V_164 ;
V_2 -> V_26 . V_164 = false ;
F_12 ( & V_2 -> V_7 ) ;
F_9 ( V_27 & ~ V_2 -> V_25 ) ;
if ( ( V_27 & V_2 -> V_25 ) == 0 && ! V_164 )
return;
F_106 ( & V_2 -> V_26 . V_168 ) ;
V_27 |= F_100 ( V_2 , V_27 ) ;
V_165 = V_2 -> V_26 . V_169 ;
V_119 = V_2 -> V_26 . V_170 ;
V_166 = V_2 -> V_26 . V_171 ;
V_167 = V_2 -> V_26 . V_172 ;
if ( V_164 || F_101 ( V_2 ) )
V_167 = V_2 -> V_26 . V_173 ;
if ( V_164 && V_119 < V_2 -> V_26 . V_174 ) {
V_119 = V_2 -> V_26 . V_174 ;
V_165 = 0 ;
} else if ( V_27 & V_160 ) {
if ( V_165 > 0 )
V_165 *= 2 ;
else
V_165 = F_56 ( V_2 ) ? 2 : 1 ;
if ( V_119 < V_2 -> V_26 . V_175 - V_165 ) {
V_119 = V_2 -> V_26 . V_175 ;
V_165 = 0 ;
}
} else if ( V_164 || F_101 ( V_2 ) ) {
V_165 = 0 ;
} else if ( V_27 & V_176 ) {
if ( V_2 -> V_26 . V_170 > V_2 -> V_26 . V_175 )
V_119 = V_2 -> V_26 . V_175 ;
else
V_119 = V_2 -> V_26 . V_171 ;
V_165 = 0 ;
} else if ( V_27 & V_158 ) {
if ( V_165 < 0 )
V_165 *= 2 ;
else
V_165 = F_56 ( V_2 ) ? - 2 : - 1 ;
} else {
V_165 = 0 ;
}
V_2 -> V_26 . V_169 = V_165 ;
V_119 += V_165 ;
V_119 = F_107 ( int , V_119 , V_166 , V_167 ) ;
F_108 ( V_2 , V_119 ) ;
F_109 ( & V_2 -> V_26 . V_168 ) ;
}
static void F_110 ( struct V_163 * V_33 )
{
struct V_1 * V_2 =
F_105 ( V_33 , struct V_1 , V_177 . V_178 ) ;
T_2 V_179 , V_180 , V_181 , V_182 ;
char * V_183 [ 6 ] ;
T_3 V_184 ;
T_7 V_185 = 0 ;
F_106 ( & V_2 -> V_31 . V_186 ) ;
if ( F_9 ( ! V_2 -> V_177 . V_187 ) )
goto V_188;
V_184 = F_2 ( V_189 ) ;
F_5 ( V_189 , V_184 & ~ V_190 ) ;
F_6 ( V_189 ) ;
while ( ( V_185 = F_111 ( V_2 -> V_177 . V_187 ) ) != 0 ) {
T_1 V_3 ;
V_185 -- ;
if ( F_36 ( V_185 >= F_112 ( V_2 ) ) )
break;
V_2 -> V_177 . V_187 &= ~ ( 1 << V_185 ) ;
V_3 = F_113 ( V_185 ) ;
V_179 = F_2 ( V_3 ) ;
V_180 = F_114 ( V_179 ) ;
V_181 = F_115 ( V_179 ) ;
V_182 = F_116 ( V_179 ) ;
F_5 ( V_3 , V_191 | V_192 ) ;
F_6 ( V_3 ) ;
V_183 [ 0 ] = V_193 L_7 ;
V_183 [ 1 ] = F_117 ( V_194 , L_8 , V_180 ) ;
V_183 [ 2 ] = F_117 ( V_194 , L_9 , V_181 ) ;
V_183 [ 3 ] = F_117 ( V_194 , L_10 , V_182 ) ;
V_183 [ 4 ] = F_117 ( V_194 , L_11 , V_185 ) ;
V_183 [ 5 ] = NULL ;
F_118 ( & V_2 -> V_31 . V_195 -> V_196 -> V_197 ,
V_198 , V_183 ) ;
F_119 ( L_12 ,
V_185 , V_180 , V_181 , V_182 ) ;
F_120 ( V_183 [ 4 ] ) ;
F_120 ( V_183 [ 3 ] ) ;
F_120 ( V_183 [ 2 ] ) ;
F_120 ( V_183 [ 1 ] ) ;
}
F_5 ( V_189 , V_184 ) ;
V_188:
F_9 ( V_2 -> V_177 . V_187 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_16 ( V_2 , F_121 ( V_2 ) ) ;
F_12 ( & V_2 -> V_7 ) ;
F_109 ( & V_2 -> V_31 . V_186 ) ;
}
static void F_122 ( struct V_1 * V_2 ,
T_2 V_199 )
{
if ( ! F_123 ( V_2 ) )
return;
F_88 ( & V_2 -> V_7 ) ;
F_18 ( V_2 , F_121 ( V_2 ) ) ;
F_91 ( & V_2 -> V_7 ) ;
V_199 &= F_121 ( V_2 ) ;
if ( V_199 & V_200 )
V_2 -> V_177 . V_187 |= 1 << 1 ;
if ( V_199 & V_201 )
V_2 -> V_177 . V_187 |= 1 << 0 ;
F_124 ( V_2 -> V_202 , & V_2 -> V_177 . V_178 ) ;
}
static void F_125 ( struct V_1 * V_2 ,
T_2 V_203 )
{
if ( V_203 & V_204 )
F_92 ( V_2 -> V_132 [ V_205 ] ) ;
if ( V_203 & V_206 )
F_92 ( V_2 -> V_132 [ V_207 ] ) ;
}
static void F_126 ( struct V_1 * V_2 ,
T_2 V_203 )
{
if ( V_203 & V_204 )
F_92 ( V_2 -> V_132 [ V_205 ] ) ;
if ( V_203 & V_208 )
F_92 ( V_2 -> V_132 [ V_207 ] ) ;
if ( V_203 & V_209 )
F_92 ( V_2 -> V_132 [ V_210 ] ) ;
if ( V_203 & ( V_211 |
V_212 |
V_213 ) )
F_119 ( L_13 , V_203 ) ;
if ( V_203 & F_121 ( V_2 ) )
F_122 ( V_2 , V_203 ) ;
}
static T_8 void
F_127 ( struct V_131 * V_132 , T_2 V_199 , int V_214 )
{
if ( V_199 & ( V_204 << V_214 ) )
F_92 ( V_132 ) ;
if ( V_199 & ( V_215 << V_214 ) )
F_128 ( & V_132 -> V_216 ) ;
}
static T_9 F_129 ( struct V_1 * V_2 ,
T_2 V_217 ,
T_2 V_203 [ 4 ] )
{
T_9 V_99 = V_218 ;
if ( V_217 & ( V_219 | V_220 ) ) {
V_203 [ 0 ] = F_71 ( F_21 ( 0 ) ) ;
if ( V_203 [ 0 ] ) {
F_130 ( F_21 ( 0 ) , V_203 [ 0 ] ) ;
V_99 = V_221 ;
} else
F_84 ( L_14 ) ;
}
if ( V_217 & ( V_222 | V_223 ) ) {
V_203 [ 1 ] = F_71 ( F_21 ( 1 ) ) ;
if ( V_203 [ 1 ] ) {
F_130 ( F_21 ( 1 ) , V_203 [ 1 ] ) ;
V_99 = V_221 ;
} else
F_84 ( L_15 ) ;
}
if ( V_217 & V_224 ) {
V_203 [ 3 ] = F_71 ( F_21 ( 3 ) ) ;
if ( V_203 [ 3 ] ) {
F_130 ( F_21 ( 3 ) , V_203 [ 3 ] ) ;
V_99 = V_221 ;
} else
F_84 ( L_16 ) ;
}
if ( V_217 & ( V_225 | V_226 ) ) {
V_203 [ 2 ] = F_71 ( F_21 ( 2 ) ) ;
if ( V_203 [ 2 ] & ( V_2 -> V_25 |
V_2 -> V_34 ) ) {
F_130 ( F_21 ( 2 ) ,
V_203 [ 2 ] & ( V_2 -> V_25 |
V_2 -> V_34 ) ) ;
V_99 = V_221 ;
} else
F_84 ( L_17 ) ;
}
return V_99 ;
}
static void F_131 ( struct V_1 * V_2 ,
T_2 V_203 [ 4 ] )
{
if ( V_203 [ 0 ] ) {
F_127 ( V_2 -> V_132 [ V_205 ] ,
V_203 [ 0 ] , V_227 ) ;
F_127 ( V_2 -> V_132 [ V_210 ] ,
V_203 [ 0 ] , V_228 ) ;
}
if ( V_203 [ 1 ] ) {
F_127 ( V_2 -> V_132 [ V_207 ] ,
V_203 [ 1 ] , V_229 ) ;
F_127 ( V_2 -> V_132 [ V_230 ] ,
V_203 [ 1 ] , V_231 ) ;
}
if ( V_203 [ 3 ] )
F_127 ( V_2 -> V_132 [ V_232 ] ,
V_203 [ 3 ] , V_233 ) ;
if ( V_203 [ 2 ] & V_2 -> V_25 )
F_132 ( V_2 , V_203 [ 2 ] ) ;
if ( V_203 [ 2 ] & V_2 -> V_34 )
F_133 ( V_2 , V_203 [ 2 ] ) ;
}
static bool F_134 ( enum V_234 V_234 , T_2 V_4 )
{
switch ( V_234 ) {
case V_235 :
return V_4 & V_236 ;
case V_237 :
return V_4 & V_238 ;
case V_239 :
return V_4 & V_240 ;
default:
return false ;
}
}
static bool F_135 ( enum V_234 V_234 , T_2 V_4 )
{
switch ( V_234 ) {
case V_241 :
return V_4 & V_242 ;
default:
return false ;
}
}
static bool F_136 ( enum V_234 V_234 , T_2 V_4 )
{
switch ( V_234 ) {
case V_235 :
return V_4 & V_236 ;
case V_237 :
return V_4 & V_238 ;
case V_239 :
return V_4 & V_240 ;
case V_243 :
return V_4 & V_244 ;
default:
return false ;
}
}
static bool F_137 ( enum V_234 V_234 , T_2 V_4 )
{
switch ( V_234 ) {
case V_235 :
return V_4 & V_245 ;
default:
return false ;
}
}
static bool F_138 ( enum V_234 V_234 , T_2 V_4 )
{
switch ( V_234 ) {
case V_237 :
return V_4 & V_238 ;
case V_239 :
return V_4 & V_240 ;
case V_243 :
return V_4 & V_244 ;
default:
return false ;
}
}
static bool F_139 ( enum V_234 V_234 , T_2 V_4 )
{
switch ( V_234 ) {
case V_237 :
return V_4 & V_246 ;
case V_239 :
return V_4 & V_247 ;
case V_243 :
return V_4 & V_248 ;
default:
return false ;
}
}
static void F_140 ( T_2 * V_249 , T_2 * V_250 ,
T_2 V_251 , T_2 V_252 ,
const T_2 V_253 [ V_254 ] ,
bool F_141 ( enum V_234 V_234 , T_2 V_4 ) )
{
enum V_234 V_234 ;
int V_90 ;
F_142 (i) {
if ( ( V_253 [ V_90 ] & V_251 ) == 0 )
continue;
* V_249 |= F_143 ( V_90 ) ;
if ( ! F_144 ( V_90 , & V_234 ) )
continue;
if ( F_141 ( V_234 , V_252 ) )
* V_250 |= F_143 ( V_90 ) ;
}
F_77 ( L_18 ,
V_251 , V_252 , * V_249 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_146 ( & V_2 -> V_255 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
F_146 ( & V_2 -> V_255 ) ;
}
static void F_148 ( struct V_1 * V_2 ,
enum V_38 V_38 ,
T_3 V_256 , T_3 V_257 ,
T_3 V_258 , T_3 V_259 ,
T_3 V_260 )
{
struct V_261 * V_262 = & V_2 -> V_262 [ V_38 ] ;
struct V_263 * V_264 ;
int V_265 , V_266 ;
F_88 ( & V_262 -> V_106 ) ;
if ( ! V_262 -> V_267 ) {
F_91 ( & V_262 -> V_106 ) ;
F_85 ( L_19 ) ;
return;
}
V_265 = V_262 -> V_265 ;
V_266 = V_262 -> V_266 ;
if ( F_149 ( V_265 , V_266 , V_268 ) < 1 ) {
F_91 ( & V_262 -> V_106 ) ;
F_84 ( L_20 ) ;
return;
}
V_264 = & V_262 -> V_267 [ V_265 ] ;
V_264 -> V_269 = V_2 -> V_31 . V_270 -> V_271 ( & V_2 -> V_31 ,
V_38 ) ;
V_264 -> V_272 [ 0 ] = V_256 ;
V_264 -> V_272 [ 1 ] = V_257 ;
V_264 -> V_272 [ 2 ] = V_258 ;
V_264 -> V_272 [ 3 ] = V_259 ;
V_264 -> V_272 [ 4 ] = V_260 ;
V_265 = ( V_265 + 1 ) & ( V_268 - 1 ) ;
V_262 -> V_265 = V_265 ;
F_91 ( & V_262 -> V_106 ) ;
F_150 ( & V_262 -> V_202 ) ;
}
static inline void
F_148 ( struct V_1 * V_2 ,
enum V_38 V_38 ,
T_3 V_256 , T_3 V_257 ,
T_3 V_258 , T_3 V_259 ,
T_3 V_260 ) {}
static void F_151 ( struct V_1 * V_2 ,
enum V_38 V_38 )
{
F_148 ( V_2 , V_38 ,
F_2 ( F_152 ( V_38 ) ) ,
0 , 0 , 0 , 0 ) ;
}
static void F_153 ( struct V_1 * V_2 ,
enum V_38 V_38 )
{
F_148 ( V_2 , V_38 ,
F_2 ( F_152 ( V_38 ) ) ,
F_2 ( F_154 ( V_38 ) ) ,
F_2 ( F_155 ( V_38 ) ) ,
F_2 ( F_156 ( V_38 ) ) ,
F_2 ( F_157 ( V_38 ) ) ) ;
}
static void F_158 ( struct V_1 * V_2 ,
enum V_38 V_38 )
{
T_3 V_273 , V_274 ;
if ( F_60 ( V_2 ) >= 3 )
V_273 = F_2 ( F_159 ( V_38 ) ) ;
else
V_273 = 0 ;
if ( F_60 ( V_2 ) >= 5 || F_80 ( V_2 ) )
V_274 = F_2 ( F_160 ( V_38 ) ) ;
else
V_274 = 0 ;
F_148 ( V_2 , V_38 ,
F_2 ( F_161 ( V_38 ) ) ,
F_2 ( F_162 ( V_38 ) ) ,
F_2 ( F_163 ( V_38 ) ) ,
V_273 , V_274 ) ;
}
static void F_132 ( struct V_1 * V_2 , T_2 V_27 )
{
if ( V_27 & V_2 -> V_25 ) {
F_88 ( & V_2 -> V_7 ) ;
F_29 ( V_2 , V_27 & V_2 -> V_25 ) ;
if ( V_2 -> V_26 . V_28 ) {
V_2 -> V_26 . V_27 |= V_27 & V_2 -> V_25 ;
F_164 ( & V_2 -> V_26 . V_33 ) ;
}
F_91 ( & V_2 -> V_7 ) ;
}
if ( F_20 ( V_2 ) -> V_16 >= 8 )
return;
if ( F_165 ( V_2 ) ) {
if ( V_27 & V_275 )
F_92 ( V_2 -> V_132 [ V_232 ] ) ;
if ( V_27 & V_276 )
F_119 ( L_21 , V_27 ) ;
}
}
static void F_133 ( struct V_1 * V_2 , T_2 V_203 )
{
if ( V_203 & V_277 ) {
T_2 V_278 , V_279 ;
V_278 = F_2 ( F_166 ( 15 ) ) ;
V_279 = V_278 & ( V_280 |
V_281 ) ;
if ( V_279 ) {
F_5 ( F_166 ( 15 ) , V_278 & ~ V_279 ) ;
F_124 ( V_2 -> V_35 . log . V_282 ,
& V_2 -> V_35 . log . V_283 ) ;
V_2 -> V_35 . log . V_284 ++ ;
} else {
}
}
}
static bool F_167 ( struct V_1 * V_2 ,
enum V_38 V_38 )
{
bool V_99 ;
V_99 = F_168 ( & V_2 -> V_31 , V_38 ) ;
if ( V_99 )
F_169 ( V_2 , V_38 ) ;
return V_99 ;
}
static void F_170 ( struct V_1 * V_2 ,
T_2 V_199 , T_2 V_285 [ V_286 ] )
{
int V_38 ;
F_88 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_287 ) {
F_91 ( & V_2 -> V_7 ) ;
return;
}
F_171 (dev_priv, pipe) {
T_1 V_3 ;
T_2 V_5 , V_288 = 0 ;
V_5 = V_51 ;
switch ( V_38 ) {
case V_60 :
V_288 = V_289 ;
break;
case V_58 :
V_288 = V_290 ;
break;
case V_291 :
V_288 = V_292 ;
break;
}
if ( V_199 & V_288 )
V_5 |= V_2 -> V_46 [ V_38 ] ;
if ( ! V_5 )
continue;
V_3 = F_49 ( V_38 ) ;
V_5 |= V_44 ;
V_285 [ V_38 ] = F_2 ( V_3 ) & V_5 ;
if ( V_285 [ V_38 ] & ( V_51 |
V_45 ) )
F_5 ( V_3 , V_285 [ V_38 ] ) ;
}
F_91 ( & V_2 -> V_7 ) ;
}
static void F_172 ( struct V_1 * V_2 ,
T_2 V_285 [ V_286 ] )
{
enum V_38 V_38 ;
F_171 (dev_priv, pipe) {
if ( V_285 [ V_38 ] & V_293 &&
F_167 ( V_2 , V_38 ) )
F_173 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_294 )
F_174 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_295 )
F_158 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_51 )
F_175 ( V_2 , V_38 ) ;
}
if ( V_285 [ 0 ] & V_296 )
F_145 ( V_2 ) ;
}
static T_2 F_176 ( struct V_1 * V_2 )
{
T_2 V_297 = F_2 ( V_298 ) ;
if ( V_297 )
F_5 ( V_298 , V_297 ) ;
return V_297 ;
}
static void F_177 ( struct V_1 * V_2 ,
T_2 V_297 )
{
T_2 V_249 = 0 , V_250 = 0 ;
if ( F_80 ( V_2 ) || F_55 ( V_2 ) ||
F_56 ( V_2 ) ) {
T_2 V_251 = V_297 & V_299 ;
if ( V_251 ) {
F_140 ( & V_249 , & V_250 , V_251 ,
V_251 , V_300 ,
F_139 ) ;
F_178 ( V_2 , V_249 , V_250 ) ;
}
if ( V_297 & V_301 )
F_147 ( V_2 ) ;
} else {
T_2 V_251 = V_297 & V_302 ;
if ( V_251 ) {
F_140 ( & V_249 , & V_250 , V_251 ,
V_251 , V_303 ,
F_139 ) ;
F_178 ( V_2 , V_249 , V_250 ) ;
}
}
}
static T_9 F_179 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_9 V_99 = V_218 ;
if ( ! F_14 ( V_2 ) )
return V_218 ;
F_180 ( V_2 ) ;
do {
T_2 V_199 , V_203 , V_27 ;
T_2 V_285 [ V_286 ] = {} ;
T_2 V_297 = 0 ;
T_2 V_305 = 0 ;
V_203 = F_2 ( V_306 ) ;
V_27 = F_2 ( V_17 ) ;
V_199 = F_2 ( V_307 ) ;
if ( V_203 == 0 && V_27 == 0 && V_199 == 0 )
break;
V_99 = V_221 ;
F_5 ( V_308 , 0 ) ;
V_305 = F_2 ( V_309 ) ;
F_5 ( V_309 , 0 ) ;
if ( V_203 )
F_5 ( V_306 , V_203 ) ;
if ( V_27 )
F_5 ( V_17 , V_27 ) ;
if ( V_199 & V_310 )
V_297 = F_176 ( V_2 ) ;
F_170 ( V_2 , V_199 , V_285 ) ;
if ( V_199 )
F_5 ( V_307 , V_199 ) ;
F_5 ( V_309 , V_305 ) ;
F_5 ( V_308 , V_311 ) ;
F_6 ( V_308 ) ;
if ( V_203 )
F_126 ( V_2 , V_203 ) ;
if ( V_27 )
F_132 ( V_2 , V_27 ) ;
if ( V_297 )
F_177 ( V_2 , V_297 ) ;
F_172 ( V_2 , V_285 ) ;
} while ( 0 );
F_181 ( V_2 ) ;
return V_99 ;
}
static T_9 F_182 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_9 V_99 = V_218 ;
if ( ! F_14 ( V_2 ) )
return V_218 ;
F_180 ( V_2 ) ;
do {
T_2 V_217 , V_199 ;
T_2 V_203 [ 4 ] = {} ;
T_2 V_285 [ V_286 ] = {} ;
T_2 V_297 = 0 ;
T_2 V_305 = 0 ;
V_217 = F_2 ( V_312 ) & ~ V_313 ;
V_199 = F_2 ( V_307 ) ;
if ( V_217 == 0 && V_199 == 0 )
break;
V_99 = V_221 ;
F_5 ( V_312 , 0 ) ;
V_305 = F_2 ( V_309 ) ;
F_5 ( V_309 , 0 ) ;
F_129 ( V_2 , V_217 , V_203 ) ;
if ( V_199 & V_310 )
V_297 = F_176 ( V_2 ) ;
F_170 ( V_2 , V_199 , V_285 ) ;
if ( V_199 )
F_5 ( V_307 , V_199 ) ;
F_5 ( V_309 , V_305 ) ;
F_5 ( V_312 , V_313 ) ;
F_6 ( V_312 ) ;
F_131 ( V_2 , V_203 ) ;
if ( V_297 )
F_177 ( V_2 , V_297 ) ;
F_172 ( V_2 , V_285 ) ;
} while ( 0 );
F_181 ( V_2 ) ;
return V_99 ;
}
static void F_183 ( struct V_1 * V_2 ,
T_2 V_251 ,
const T_2 V_253 [ V_254 ] )
{
T_2 V_252 , V_249 = 0 , V_250 = 0 ;
V_252 = F_2 ( V_314 ) ;
if ( ! V_251 ) {
T_2 V_5 = V_315 |
V_316 |
V_317 |
V_318 ;
V_252 &= ~ V_5 ;
}
F_5 ( V_314 , V_252 ) ;
if ( ! V_251 )
return;
F_140 ( & V_249 , & V_250 , V_251 ,
V_252 , V_253 ,
F_138 ) ;
F_178 ( V_2 , V_249 , V_250 ) ;
}
static void F_184 ( struct V_1 * V_2 , T_2 V_319 )
{
int V_38 ;
T_2 V_251 = V_319 & V_320 ;
F_183 ( V_2 , V_251 , V_321 ) ;
if ( V_319 & V_322 ) {
int V_234 = F_111 ( ( V_319 & V_322 ) >>
V_323 ) ;
F_77 ( L_22 ,
F_185 ( V_234 ) ) ;
}
if ( V_319 & V_324 )
F_147 ( V_2 ) ;
if ( V_319 & V_325 )
F_145 ( V_2 ) ;
if ( V_319 & V_326 )
F_77 ( L_23 ) ;
if ( V_319 & V_327 )
F_77 ( L_24 ) ;
if ( V_319 & V_328 )
F_84 ( L_25 ) ;
if ( V_319 & V_329 )
F_171 (dev_priv, pipe)
F_77 ( L_26 ,
F_51 ( V_38 ) ,
F_2 ( F_186 ( V_38 ) ) ) ;
if ( V_319 & ( V_330 | V_331 ) )
F_77 ( L_27 ) ;
if ( V_319 & ( V_332 | V_333 ) )
F_77 ( L_28 ) ;
if ( V_319 & V_334 )
F_187 ( V_2 , V_335 ) ;
if ( V_319 & V_336 )
F_187 ( V_2 , V_337 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
T_2 V_338 = F_2 ( V_339 ) ;
enum V_38 V_38 ;
if ( V_338 & V_340 )
F_84 ( L_29 ) ;
F_171 (dev_priv, pipe) {
if ( V_338 & F_189 ( V_38 ) )
F_175 ( V_2 , V_38 ) ;
if ( V_338 & F_190 ( V_38 ) ) {
if ( F_191 ( V_2 ) )
F_153 ( V_2 , V_38 ) ;
else
F_151 ( V_2 , V_38 ) ;
}
}
F_5 ( V_339 , V_338 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
T_2 V_341 = F_2 ( V_342 ) ;
if ( V_341 & V_343 )
F_84 ( L_25 ) ;
if ( V_341 & V_344 )
F_187 ( V_2 , V_335 ) ;
if ( V_341 & V_345 )
F_187 ( V_2 , V_337 ) ;
if ( V_341 & V_346 )
F_187 ( V_2 , V_347 ) ;
F_5 ( V_342 , V_341 ) ;
}
static void F_193 ( struct V_1 * V_2 , T_2 V_319 )
{
int V_38 ;
T_2 V_251 = V_319 & V_348 ;
F_183 ( V_2 , V_251 , V_349 ) ;
if ( V_319 & V_350 ) {
int V_234 = F_111 ( ( V_319 & V_350 ) >>
V_351 ) ;
F_77 ( L_30 ,
F_185 ( V_234 ) ) ;
}
if ( V_319 & V_352 )
F_147 ( V_2 ) ;
if ( V_319 & V_353 )
F_145 ( V_2 ) ;
if ( V_319 & V_354 )
F_77 ( L_31 ) ;
if ( V_319 & V_355 )
F_77 ( L_32 ) ;
if ( V_319 & V_356 )
F_171 (dev_priv, pipe)
F_77 ( L_26 ,
F_51 ( V_38 ) ,
F_2 ( F_186 ( V_38 ) ) ) ;
if ( V_319 & V_357 )
F_192 ( V_2 ) ;
}
static void F_194 ( struct V_1 * V_2 , T_2 V_319 )
{
T_2 V_251 = V_319 & V_358 &
~ V_359 ;
T_2 V_360 = V_319 & V_359 ;
T_2 V_249 = 0 , V_250 = 0 ;
if ( V_251 ) {
T_2 V_252 ;
V_252 = F_2 ( V_314 ) ;
F_5 ( V_314 , V_252 ) ;
F_140 ( & V_249 , & V_250 , V_251 ,
V_252 , V_361 ,
F_136 ) ;
}
if ( V_360 ) {
T_2 V_252 ;
V_252 = F_2 ( V_362 ) ;
F_5 ( V_362 , V_252 ) ;
F_140 ( & V_249 , & V_250 , V_360 ,
V_252 , V_361 ,
F_135 ) ;
}
if ( V_249 )
F_178 ( V_2 , V_249 , V_250 ) ;
if ( V_319 & V_353 )
F_145 ( V_2 ) ;
}
static void F_195 ( struct V_1 * V_2 ,
T_2 V_251 ,
const T_2 V_253 [ V_254 ] )
{
T_2 V_252 , V_249 = 0 , V_250 = 0 ;
V_252 = F_2 ( V_363 ) ;
F_5 ( V_363 , V_252 ) ;
F_140 ( & V_249 , & V_250 , V_251 ,
V_252 , V_253 ,
F_137 ) ;
F_178 ( V_2 , V_249 , V_250 ) ;
}
static void F_196 ( struct V_1 * V_2 ,
T_2 V_364 )
{
enum V_38 V_38 ;
T_2 V_251 = V_364 & V_365 ;
if ( V_251 )
F_195 ( V_2 , V_251 , V_366 ) ;
if ( V_364 & V_367 )
F_147 ( V_2 ) ;
if ( V_364 & V_368 )
F_197 ( V_2 ) ;
if ( V_364 & V_369 )
F_84 ( L_29 ) ;
F_171 (dev_priv, pipe) {
if ( V_364 & F_198 ( V_38 ) &&
F_167 ( V_2 , V_38 ) )
F_173 ( V_2 , V_38 ) ;
if ( V_364 & F_199 ( V_38 ) )
F_175 ( V_2 , V_38 ) ;
if ( V_364 & F_200 ( V_38 ) )
F_158 ( V_2 , V_38 ) ;
if ( V_364 & F_201 ( V_38 ) )
F_174 ( V_2 , V_38 ) ;
}
if ( V_364 & V_370 ) {
T_2 V_319 = F_2 ( V_371 ) ;
if ( F_202 ( V_2 ) )
F_193 ( V_2 , V_319 ) ;
else
F_184 ( V_2 , V_319 ) ;
F_5 ( V_371 , V_319 ) ;
}
if ( F_203 ( V_2 ) && V_364 & V_372 )
F_87 ( V_2 ) ;
}
static void F_204 ( struct V_1 * V_2 ,
T_2 V_364 )
{
enum V_38 V_38 ;
T_2 V_251 = V_364 & V_373 ;
if ( V_251 )
F_195 ( V_2 , V_251 , V_374 ) ;
if ( V_364 & V_375 )
F_188 ( V_2 ) ;
if ( V_364 & V_376 )
F_147 ( V_2 ) ;
if ( V_364 & V_377 )
F_197 ( V_2 ) ;
F_171 (dev_priv, pipe) {
if ( V_364 & ( F_205 ( V_38 ) ) &&
F_167 ( V_2 , V_38 ) )
F_173 ( V_2 , V_38 ) ;
if ( V_364 & F_206 ( V_38 ) )
F_174 ( V_2 , V_38 ) ;
}
if ( ! F_207 ( V_2 ) && ( V_364 & V_378 ) ) {
T_2 V_319 = F_2 ( V_371 ) ;
F_193 ( V_2 , V_319 ) ;
F_5 ( V_371 , V_319 ) ;
}
}
static T_9 F_208 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_364 , V_203 , V_379 , V_380 = 0 ;
T_9 V_99 = V_218 ;
if ( ! F_14 ( V_2 ) )
return V_218 ;
F_180 ( V_2 ) ;
V_379 = F_2 ( V_381 ) ;
F_5 ( V_381 , V_379 & ~ V_382 ) ;
F_6 ( V_381 ) ;
if ( ! F_207 ( V_2 ) ) {
V_380 = F_2 ( V_383 ) ;
F_5 ( V_383 , 0 ) ;
F_6 ( V_383 ) ;
}
V_203 = F_2 ( V_306 ) ;
if ( V_203 ) {
F_5 ( V_306 , V_203 ) ;
V_99 = V_221 ;
if ( F_60 ( V_2 ) >= 6 )
F_126 ( V_2 , V_203 ) ;
else
F_125 ( V_2 , V_203 ) ;
}
V_364 = F_2 ( V_384 ) ;
if ( V_364 ) {
F_5 ( V_384 , V_364 ) ;
V_99 = V_221 ;
if ( F_60 ( V_2 ) >= 7 )
F_204 ( V_2 , V_364 ) ;
else
F_196 ( V_2 , V_364 ) ;
}
if ( F_60 ( V_2 ) >= 6 ) {
T_2 V_27 = F_2 ( V_17 ) ;
if ( V_27 ) {
F_5 ( V_17 , V_27 ) ;
V_99 = V_221 ;
F_132 ( V_2 , V_27 ) ;
}
}
F_5 ( V_381 , V_379 ) ;
F_6 ( V_381 ) ;
if ( ! F_207 ( V_2 ) ) {
F_5 ( V_383 , V_380 ) ;
F_6 ( V_383 ) ;
}
F_181 ( V_2 ) ;
return V_99 ;
}
static void F_209 ( struct V_1 * V_2 ,
T_2 V_251 ,
const T_2 V_253 [ V_254 ] )
{
T_2 V_252 , V_249 = 0 , V_250 = 0 ;
V_252 = F_2 ( V_314 ) ;
F_5 ( V_314 , V_252 ) ;
F_140 ( & V_249 , & V_250 , V_251 ,
V_252 , V_253 ,
F_134 ) ;
F_178 ( V_2 , V_249 , V_250 ) ;
}
static T_9
F_210 ( struct V_1 * V_2 , T_2 V_217 )
{
T_9 V_99 = V_218 ;
T_2 V_199 ;
enum V_38 V_38 ;
if ( V_217 & V_385 ) {
V_199 = F_2 ( V_386 ) ;
if ( V_199 ) {
F_5 ( V_386 , V_199 ) ;
V_99 = V_221 ;
if ( V_199 & V_387 )
F_197 ( V_2 ) ;
else
F_84 ( L_33 ) ;
}
else
F_84 ( L_34 ) ;
}
if ( V_217 & V_388 ) {
V_199 = F_2 ( V_389 ) ;
if ( V_199 ) {
T_2 V_390 ;
bool V_391 = false ;
F_5 ( V_389 , V_199 ) ;
V_99 = V_221 ;
V_390 = V_392 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_390 |= V_393 |
V_394 |
V_395 ;
if ( V_199 & V_390 ) {
F_147 ( V_2 ) ;
V_391 = true ;
}
if ( F_211 ( V_2 ) ) {
V_390 = V_199 & V_396 ;
if ( V_390 ) {
F_209 ( V_2 , V_390 ,
V_397 ) ;
V_391 = true ;
}
} else if ( F_212 ( V_2 ) ) {
V_390 = V_199 & V_398 ;
if ( V_390 ) {
F_195 ( V_2 ,
V_390 , V_399 ) ;
V_391 = true ;
}
}
if ( F_211 ( V_2 ) && ( V_199 & V_400 ) ) {
F_145 ( V_2 ) ;
V_391 = true ;
}
if ( ! V_391 )
F_84 ( L_35 ) ;
}
else
F_84 ( L_36 ) ;
}
F_171 (dev_priv, pipe) {
T_2 V_401 , V_402 ;
if ( ! ( V_217 & F_213 ( V_38 ) ) )
continue;
V_199 = F_2 ( F_214 ( V_38 ) ) ;
if ( ! V_199 ) {
F_84 ( L_37 ) ;
continue;
}
V_99 = V_221 ;
F_5 ( F_214 ( V_38 ) , V_199 ) ;
if ( V_199 & V_403 &&
F_167 ( V_2 , V_38 ) )
F_173 ( V_2 , V_38 ) ;
V_401 = V_199 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_401 &= V_404 ;
else
V_401 &= V_405 ;
if ( V_401 )
F_174 ( V_2 , V_38 ) ;
if ( V_199 & V_406 )
F_151 ( V_2 , V_38 ) ;
if ( V_199 & V_407 )
F_175 ( V_2 , V_38 ) ;
V_402 = V_199 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_402 &= V_408 ;
else
V_402 &= V_409 ;
if ( V_402 )
F_84 ( L_38 ,
F_51 ( V_38 ) ,
V_402 ) ;
}
if ( F_215 ( V_2 ) && ! F_207 ( V_2 ) &&
V_217 & V_410 ) {
V_199 = F_2 ( V_371 ) ;
if ( V_199 ) {
F_5 ( V_371 , V_199 ) ;
V_99 = V_221 ;
if ( F_216 ( V_2 ) || F_217 ( V_2 ) )
F_194 ( V_2 , V_199 ) ;
else
F_193 ( V_2 , V_199 ) ;
} else {
F_77 ( L_39 ) ;
}
}
return V_99 ;
}
static T_9 F_218 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_217 ;
T_2 V_203 [ 4 ] = {} ;
T_9 V_99 ;
if ( ! F_14 ( V_2 ) )
return V_218 ;
V_217 = F_71 ( V_312 ) ;
V_217 &= ~ V_313 ;
if ( ! V_217 )
return V_218 ;
F_130 ( V_312 , 0 ) ;
F_180 ( V_2 ) ;
V_99 = F_129 ( V_2 , V_217 , V_203 ) ;
F_131 ( V_2 , V_203 ) ;
V_99 |= F_210 ( V_2 , V_217 ) ;
F_130 ( V_312 , V_313 ) ;
F_17 ( V_312 ) ;
F_181 ( V_2 ) ;
return V_99 ;
}
static void F_219 ( struct V_1 * V_2 )
{
F_146 ( & V_2 -> V_411 . V_412 ) ;
F_146 ( & V_2 -> V_413 ) ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_414 * V_197 = & V_2 -> V_31 . V_195 -> V_196 -> V_197 ;
char * V_415 [] = { V_416 L_7 , NULL } ;
char * V_417 [] = { V_418 L_7 , NULL } ;
char * V_419 [] = { V_416 L_40 , NULL } ;
F_118 ( V_197 , V_198 , V_415 ) ;
F_77 ( L_41 ) ;
F_118 ( V_197 , V_198 , V_417 ) ;
F_221 ( V_2 ) ;
F_222 ( V_2 ) ;
do {
if ( F_223 ( & V_2 -> V_31 . V_186 ) ) {
F_224 ( V_2 ) ;
F_109 ( & V_2 -> V_31 . V_186 ) ;
}
} while ( F_225 ( & V_2 -> V_411 . V_78 ,
V_420 ,
V_421 ,
V_422 ) );
F_226 ( V_2 ) ;
F_227 ( V_2 ) ;
if ( ! F_228 ( V_423 , & V_2 -> V_411 . V_78 ) )
F_118 ( V_197 ,
V_198 , V_419 ) ;
F_146 ( & V_2 -> V_411 . V_424 ) ;
}
static inline void
F_229 ( struct V_1 * V_2 ,
struct V_425 * V_426 )
{
int V_185 ;
int V_427 ;
F_230 ( L_42 , V_426 -> V_426 ) ;
if ( F_60 ( V_2 ) <= 3 )
return;
F_230 ( L_43 , V_426 -> V_428 ) ;
if ( F_60 ( V_2 ) <= 6 )
return;
F_231 (dev_priv, slice, subslice)
F_230 ( L_44 ,
V_185 , V_427 , V_426 -> V_429 [ V_185 ] [ V_427 ] ) ;
F_231 (dev_priv, slice, subslice)
F_230 ( L_45 ,
V_185 , V_427 , V_426 -> V_180 [ V_185 ] [ V_427 ] ) ;
}
static void F_232 ( struct V_1 * V_2 )
{
T_2 V_430 ;
if ( ! F_70 ( V_2 ) )
F_5 ( V_431 , F_2 ( V_431 ) ) ;
if ( F_60 ( V_2 ) < 4 )
F_5 ( V_432 , F_2 ( V_432 ) ) ;
else
F_5 ( V_433 , F_2 ( V_433 ) ) ;
F_5 ( V_434 , F_2 ( V_434 ) ) ;
V_430 = F_2 ( V_434 ) ;
if ( V_430 ) {
F_77 ( L_46 , V_430 ) ;
F_5 ( V_435 , F_2 ( V_435 ) | V_430 ) ;
F_5 ( V_436 , V_437 ) ;
}
}
void F_233 ( struct V_1 * V_2 ,
T_2 V_438 ,
const char * V_439 , ... )
{
T_10 args ;
char V_440 [ 80 ] ;
va_start ( args , V_439 ) ;
F_234 ( V_440 , sizeof( V_440 ) , V_439 , args ) ;
va_end ( args ) ;
F_235 ( V_2 , V_438 , V_440 ) ;
F_232 ( V_2 ) ;
if ( ! V_438 )
return;
if ( F_236 ( V_420 ,
& V_2 -> V_411 . V_78 ) )
return;
F_219 ( V_2 ) ;
F_220 ( V_2 ) ;
}
static int F_237 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_54 ( V_2 , V_38 , V_441 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
return 0 ;
}
static int F_238 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_54 ( V_2 , V_38 ,
V_293 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
return 0 ;
}
static int F_239 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
T_3 V_442 = F_60 ( V_2 ) >= 7 ?
F_205 ( V_38 ) : F_198 ( V_38 ) ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_240 ( V_2 , V_442 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
return 0 ;
}
static int F_241 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_242 ( V_2 , V_38 , V_403 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
return 0 ;
}
static void F_243 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_57 ( V_2 , V_38 , V_441 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
}
static void F_244 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_57 ( V_2 , V_38 ,
V_293 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
}
static void F_245 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
T_3 V_442 = F_60 ( V_2 ) >= 7 ?
F_205 ( V_38 ) : F_198 ( V_38 ) ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_246 ( V_2 , V_442 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
}
static void F_247 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_248 ( V_2 , V_38 , V_403 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
}
static void F_249 ( struct V_1 * V_2 )
{
if ( F_207 ( V_2 ) )
return;
F_250 ( V_443 ) ;
if ( F_202 ( V_2 ) || F_251 ( V_2 ) )
F_5 ( V_342 , 0xffffffff ) ;
}
static void F_252 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( F_207 ( V_2 ) )
return;
F_9 ( F_2 ( V_383 ) != 0 ) ;
F_5 ( V_383 , 0xffffffff ) ;
F_6 ( V_383 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
F_250 ( V_444 ) ;
if ( F_60 ( V_2 ) >= 6 )
F_250 ( V_445 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
enum V_38 V_38 ;
if ( F_56 ( V_2 ) )
F_5 ( V_446 , V_447 ) ;
else
F_5 ( V_446 , V_448 ) ;
F_7 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
F_171 (dev_priv, pipe) {
F_5 ( F_49 ( V_38 ) ,
V_51 |
V_45 ) ;
V_2 -> V_46 [ V_38 ] = 0 ;
}
F_250 ( V_449 ) ;
V_2 -> V_12 = ~ 0 ;
}
static void F_255 ( struct V_1 * V_2 )
{
T_2 V_450 ;
T_2 V_22 ;
enum V_38 V_38 ;
V_450 = V_294 |
V_295 ;
F_54 ( V_2 , V_60 , V_296 ) ;
F_171 (dev_priv, pipe)
F_54 ( V_2 , V_38 , V_450 ) ;
V_22 = V_310 |
V_289 |
V_290 ;
if ( F_56 ( V_2 ) )
V_22 |= V_292 ;
F_9 ( V_2 -> V_12 != ~ 0 ) ;
V_2 -> V_12 = ~ V_22 ;
F_256 ( V_449 , V_2 -> V_12 , V_22 ) ;
}
static void F_257 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_5 ( V_451 , 0xffffffff ) ;
F_250 ( V_452 ) ;
if ( F_258 ( V_2 ) )
F_5 ( V_339 , 0xffffffff ) ;
F_253 ( V_2 ) ;
F_249 ( V_2 ) ;
}
static void F_259 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_5 ( V_308 , 0 ) ;
F_6 ( V_308 ) ;
F_253 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_254 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_260 ( struct V_1 * V_2 )
{
F_261 ( V_444 , 0 ) ;
F_261 ( V_444 , 1 ) ;
F_261 ( V_444 , 2 ) ;
F_261 ( V_444 , 3 ) ;
}
static void F_262 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
F_5 ( V_312 , 0 ) ;
F_6 ( V_312 ) ;
F_260 ( V_2 ) ;
F_171 (dev_priv, pipe)
if ( F_263 ( V_2 ,
F_264 ( V_38 ) ) )
F_261 ( V_453 , V_38 ) ;
F_250 ( V_454 ) ;
F_250 ( V_455 ) ;
F_250 ( V_456 ) ;
if ( F_215 ( V_2 ) )
F_249 ( V_2 ) ;
}
void F_265 ( struct V_1 * V_2 ,
unsigned int V_457 )
{
T_3 V_458 = V_403 | V_407 ;
enum V_38 V_38 ;
F_11 ( & V_2 -> V_7 ) ;
F_266 (dev_priv, pipe, pipe_mask)
F_267 ( V_453 , V_38 ,
V_2 -> V_39 [ V_38 ] ,
~ V_2 -> V_39 [ V_38 ] | V_458 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_268 ( struct V_1 * V_2 ,
unsigned int V_457 )
{
enum V_38 V_38 ;
F_11 ( & V_2 -> V_7 ) ;
F_266 (dev_priv, pipe, pipe_mask)
F_261 ( V_453 , V_38 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_39 ( V_2 -> V_31 . V_32 ) ;
}
static void F_269 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_5 ( V_312 , 0 ) ;
F_6 ( V_312 ) ;
F_260 ( V_2 ) ;
F_250 ( V_456 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_254 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static T_2 F_270 ( struct V_1 * V_2 ,
const T_2 V_253 [ V_254 ] )
{
struct V_459 * V_460 ;
T_2 V_461 = 0 ;
F_271 (&dev_priv->drm, encoder)
if ( V_2 -> V_462 . V_463 [ V_460 -> V_464 ] . V_465 == V_466 )
V_461 |= V_253 [ V_460 -> V_464 ] ;
return V_461 ;
}
static void F_272 ( struct V_1 * V_2 )
{
T_2 V_467 , V_462 , V_461 ;
if ( F_273 ( V_2 ) ) {
V_467 = V_320 ;
V_461 = F_270 ( V_2 , V_321 ) ;
} else {
V_467 = V_348 ;
V_461 = F_270 ( V_2 , V_349 ) ;
}
F_47 ( V_2 , V_467 , V_461 ) ;
V_462 = F_2 ( V_314 ) ;
V_462 &= ~ ( V_468 | V_469 | V_470 ) ;
V_462 |= V_471 | V_472 ;
V_462 |= V_473 | V_474 ;
V_462 |= V_475 | V_476 ;
if ( F_274 ( V_2 ) )
V_462 |= V_477 ;
F_5 ( V_314 , V_462 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
T_2 V_467 , V_462 , V_461 ;
V_467 = V_358 ;
V_461 = F_270 ( V_2 , V_361 ) ;
F_47 ( V_2 , V_467 , V_461 ) ;
V_462 = F_2 ( V_314 ) ;
V_462 |= V_471 | V_473 |
V_475 | V_477 ;
F_5 ( V_314 , V_462 ) ;
V_462 = F_2 ( V_362 ) ;
V_462 |= V_478 ;
F_5 ( V_362 , V_462 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
T_2 V_467 , V_462 , V_461 ;
if ( F_60 ( V_2 ) >= 8 ) {
V_467 = V_398 ;
V_461 = F_270 ( V_2 , V_399 ) ;
F_44 ( V_2 , V_467 , V_461 ) ;
} else if ( F_60 ( V_2 ) >= 7 ) {
V_467 = V_373 ;
V_461 = F_270 ( V_2 , V_374 ) ;
F_13 ( V_2 , V_467 , V_461 ) ;
} else {
V_467 = V_365 ;
V_461 = F_270 ( V_2 , V_366 ) ;
F_13 ( V_2 , V_467 , V_461 ) ;
}
V_462 = F_2 ( V_363 ) ;
V_462 &= ~ V_479 ;
V_462 |= V_480 | V_481 ;
F_5 ( V_363 , V_462 ) ;
F_272 ( V_2 ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
T_2 V_467 , V_462 , V_461 ;
V_461 = F_270 ( V_2 , V_397 ) ;
V_467 = V_396 ;
F_44 ( V_2 , V_467 , V_461 ) ;
V_462 = F_2 ( V_314 ) ;
V_462 |= V_473 | V_475 |
V_477 ;
F_85 ( L_47 ,
V_462 , V_461 ) ;
V_462 &= ~ V_482 ;
if ( ( V_461 & V_483 ) &&
F_278 ( V_2 , V_235 ) )
V_462 |= V_484 ;
if ( ( V_461 & V_485 ) &&
F_278 ( V_2 , V_237 ) )
V_462 |= V_486 ;
if ( ( V_461 & V_487 ) &&
F_278 ( V_2 , V_239 ) )
V_462 |= V_488 ;
F_5 ( V_314 , V_462 ) ;
}
static void F_279 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_5 ;
if ( F_207 ( V_2 ) )
return;
if ( F_273 ( V_2 ) )
V_5 = V_325 | V_324 | V_328 ;
else
V_5 = V_353 | V_352 ;
F_1 ( V_2 , V_371 ) ;
F_5 ( V_41 , ~ V_5 ) ;
}
static void F_280 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_489 , V_490 ;
V_489 = V_490 = 0 ;
V_2 -> V_14 = ~ 0 ;
if ( F_123 ( V_2 ) ) {
V_2 -> V_14 = ~ F_121 ( V_2 ) ;
V_490 |= F_121 ( V_2 ) ;
}
V_490 |= V_204 ;
if ( F_203 ( V_2 ) ) {
V_490 |= V_206 ;
} else {
V_490 |= V_209 | V_208 ;
}
F_256 ( V_444 , V_2 -> V_14 , V_490 ) ;
if ( F_60 ( V_2 ) >= 6 ) {
if ( F_165 ( V_2 ) ) {
V_489 |= V_275 ;
V_2 -> V_23 |= V_275 ;
}
V_2 -> V_20 = 0xffffffff ;
F_256 ( V_445 , V_2 -> V_20 , V_489 ) ;
}
}
static int F_281 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_491 , V_492 ;
if ( F_60 ( V_2 ) >= 7 ) {
V_491 = ( V_382 | V_377 |
V_378 | V_493 |
V_494 |
V_495 | V_376 ) ;
V_492 = ( V_496 | V_497 |
V_498 | V_375 |
V_373 ) ;
} else {
V_491 = ( V_382 | V_368 | V_370 |
V_499 | V_500 |
V_367 |
V_501 | V_502 |
V_369 ) ;
V_492 = ( V_503 | V_504 | V_372 |
V_505 | V_506 |
V_365 ) ;
}
V_2 -> V_12 = ~ V_491 ;
F_5 ( V_451 , 0xeffe ) ;
F_252 ( V_48 ) ;
F_256 ( V_452 , V_2 -> V_12 , V_491 | V_492 ) ;
F_280 ( V_48 ) ;
F_279 ( V_48 ) ;
if ( F_282 ( V_2 ) ) {
F_11 ( & V_2 -> V_7 ) ;
F_240 ( V_2 , V_372 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
return 0 ;
}
void F_283 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
return;
V_2 -> V_287 = true ;
if ( F_14 ( V_2 ) ) {
F_254 ( V_2 ) ;
F_255 ( V_2 ) ;
}
}
void F_284 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_287 )
return;
V_2 -> V_287 = false ;
if ( F_14 ( V_2 ) )
F_254 ( V_2 ) ;
}
static int F_285 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_280 ( V_48 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_255 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_5 ( V_308 , V_311 ) ;
F_6 ( V_308 ) ;
return 0 ;
}
static void F_286 ( struct V_1 * V_2 )
{
T_3 V_507 [] = {
V_204 << V_227 |
V_215 << V_227 |
V_204 << V_228 |
V_215 << V_228 ,
V_204 << V_229 |
V_215 << V_229 |
V_204 << V_231 |
V_215 << V_231 ,
0 ,
V_204 << V_233 |
V_215 << V_233
} ;
if ( F_123 ( V_2 ) )
V_507 [ 0 ] |= V_201 ;
V_2 -> V_23 = 0x0 ;
V_2 -> V_20 = ~ V_2 -> V_23 ;
F_267 ( V_444 , 0 , ~ V_507 [ 0 ] , V_507 [ 0 ] ) ;
F_267 ( V_444 , 1 , ~ V_507 [ 1 ] , V_507 [ 1 ] ) ;
F_267 ( V_444 , 2 , V_2 -> V_20 , V_2 -> V_23 ) ;
F_267 ( V_444 , 3 , ~ V_507 [ 3 ] , V_507 [ 3 ] ) ;
}
static void F_287 ( struct V_1 * V_2 )
{
T_3 V_508 = V_406 ;
T_3 V_509 ;
T_2 V_510 = V_392 ;
T_2 V_511 ;
T_2 V_512 = V_387 ;
enum V_38 V_38 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 ) {
V_508 |= V_404 |
V_408 ;
V_510 |= V_393 | V_394 |
V_395 ;
if ( F_211 ( V_2 ) )
V_510 |= V_400 ;
} else {
V_508 |= V_405 |
V_409 ;
}
V_509 = V_508 | V_403 |
V_407 ;
V_511 = V_510 ;
if ( F_211 ( V_2 ) )
V_511 |= V_396 ;
else if ( F_212 ( V_2 ) )
V_511 |= V_398 ;
V_2 -> V_39 [ V_60 ] = ~ V_508 ;
V_2 -> V_39 [ V_58 ] = ~ V_508 ;
V_2 -> V_39 [ V_291 ] = ~ V_508 ;
F_171 (dev_priv, pipe)
if ( F_263 ( V_2 ,
F_264 ( V_38 ) ) )
F_267 ( V_453 , V_38 ,
V_2 -> V_39 [ V_38 ] ,
V_509 ) ;
F_256 ( V_454 , ~ V_510 , V_511 ) ;
F_256 ( V_455 , ~ V_512 , V_512 ) ;
}
static int F_288 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( F_215 ( V_2 ) )
F_252 ( V_48 ) ;
F_286 ( V_2 ) ;
F_287 ( V_2 ) ;
if ( F_215 ( V_2 ) )
F_279 ( V_48 ) ;
F_5 ( V_312 , V_313 ) ;
F_6 ( V_312 ) ;
return 0 ;
}
static int F_289 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_286 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_255 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_5 ( V_312 , V_313 ) ;
F_6 ( V_312 ) ;
return 0 ;
}
static void F_290 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( ! V_2 )
return;
F_262 ( V_48 ) ;
}
static void F_291 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( ! V_2 )
return;
F_5 ( V_308 , 0 ) ;
F_6 ( V_308 ) ;
F_253 ( V_2 ) ;
F_5 ( V_451 , 0xffffffff ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_254 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_292 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( ! V_2 )
return;
F_5 ( V_312 , 0 ) ;
F_6 ( V_312 ) ;
F_260 ( V_2 ) ;
F_250 ( V_456 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_254 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_293 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( ! V_2 )
return;
F_257 ( V_48 ) ;
}
static void F_294 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
F_171 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_89 ( V_513 , 0xffff ) ;
F_89 ( V_514 , 0x0 ) ;
F_295 ( V_514 ) ;
}
static int F_296 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_89 ( V_435 ,
~ ( V_515 | V_516 ) ) ;
V_2 -> V_12 =
~ ( V_289 |
V_290 |
V_517 |
V_518 ) ;
F_89 ( V_513 , V_2 -> V_12 ) ;
F_89 ( V_514 ,
V_289 |
V_290 |
V_519 ) ;
F_295 ( V_514 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_54 ( V_2 , V_60 , V_295 ) ;
F_54 ( V_2 , V_58 , V_295 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_297 ( struct V_1 * V_2 ,
int V_520 , int V_38 , T_2 V_199 )
{
T_11 V_521 = F_298 ( V_520 ) ;
if ( ! F_167 ( V_2 , V_38 ) )
return false ;
if ( ( V_199 & V_521 ) == 0 )
goto V_522;
if ( F_299 ( V_523 ) & V_521 )
goto V_522;
F_174 ( V_2 , V_38 ) ;
return true ;
V_522:
F_173 ( V_2 , V_38 ) ;
return false ;
}
static T_9 F_300 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_11 V_199 , V_524 ;
T_2 V_285 [ 2 ] ;
int V_38 ;
T_11 V_525 =
V_517 |
V_518 ;
T_9 V_99 ;
if ( ! F_14 ( V_2 ) )
return V_218 ;
F_180 ( V_2 ) ;
V_99 = V_218 ;
V_199 = F_299 ( V_436 ) ;
if ( V_199 == 0 )
goto V_188;
while ( V_199 & ~ V_525 ) {
F_88 ( & V_2 -> V_7 ) ;
if ( V_199 & V_437 )
F_119 ( L_48 , V_199 ) ;
F_171 (dev_priv, pipe) {
T_1 V_3 = F_49 ( V_38 ) ;
V_285 [ V_38 ] = F_2 ( V_3 ) ;
if ( V_285 [ V_38 ] & 0x8000ffff )
F_5 ( V_3 , V_285 [ V_38 ] ) ;
}
F_91 ( & V_2 -> V_7 ) ;
F_89 ( V_436 , V_199 & ~ V_525 ) ;
V_524 = F_299 ( V_436 ) ;
if ( V_199 & V_519 )
F_92 ( V_2 -> V_132 [ V_205 ] ) ;
F_171 (dev_priv, pipe) {
int V_520 = V_38 ;
if ( F_301 ( V_2 ) )
V_520 = ! V_520 ;
if ( V_285 [ V_38 ] & V_441 &&
F_297 ( V_2 , V_520 , V_38 , V_199 ) )
V_525 &= ~ F_298 ( V_520 ) ;
if ( V_285 [ V_38 ] & V_295 )
F_158 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_51 )
F_175 ( V_2 ,
V_38 ) ;
}
V_199 = V_524 ;
}
V_99 = V_221 ;
V_188:
F_181 ( V_2 ) ;
return V_99 ;
}
static void F_302 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
F_171 (dev_priv, pipe) {
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( F_49 ( V_38 ) , F_2 ( F_49 ( V_38 ) ) ) ;
}
F_89 ( V_513 , 0xffff ) ;
F_89 ( V_514 , 0x0 ) ;
F_89 ( V_436 , F_299 ( V_436 ) ) ;
}
static void F_303 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
if ( F_304 ( V_2 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
}
F_89 ( V_451 , 0xeffe ) ;
F_171 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( V_513 , 0xffffffff ) ;
F_5 ( V_514 , 0x0 ) ;
F_6 ( V_514 ) ;
}
static int F_305 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_22 ;
F_5 ( V_435 , ~ ( V_515 | V_516 ) ) ;
V_2 -> V_12 =
~ ( V_526 |
V_289 |
V_290 |
V_517 |
V_518 ) ;
V_22 =
V_526 |
V_289 |
V_290 |
V_519 ;
if ( F_304 ( V_2 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
V_22 |= V_310 ;
V_2 -> V_12 &= ~ V_310 ;
}
F_5 ( V_513 , V_2 -> V_12 ) ;
F_5 ( V_514 , V_22 ) ;
F_6 ( V_514 ) ;
F_58 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_54 ( V_2 , V_60 , V_295 ) ;
F_54 ( V_2 , V_58 , V_295 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_306 ( struct V_1 * V_2 ,
int V_520 , int V_38 , T_2 V_199 )
{
T_2 V_521 = F_298 ( V_520 ) ;
if ( ! F_167 ( V_2 , V_38 ) )
return false ;
if ( ( V_199 & V_521 ) == 0 )
goto V_522;
if ( F_2 ( V_523 ) & V_521 )
goto V_522;
F_174 ( V_2 , V_38 ) ;
return true ;
V_522:
F_173 ( V_2 , V_38 ) ;
return false ;
}
static T_9 F_307 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_199 , V_524 , V_285 [ V_286 ] ;
T_2 V_525 =
V_517 |
V_518 ;
int V_38 , V_99 = V_218 ;
if ( ! F_14 ( V_2 ) )
return V_218 ;
F_180 ( V_2 ) ;
V_199 = F_2 ( V_436 ) ;
do {
bool V_527 = ( V_199 & ~ V_525 ) != 0 ;
bool V_528 = false ;
F_88 ( & V_2 -> V_7 ) ;
if ( V_199 & V_437 )
F_119 ( L_48 , V_199 ) ;
F_171 (dev_priv, pipe) {
T_1 V_3 = F_49 ( V_38 ) ;
V_285 [ V_38 ] = F_2 ( V_3 ) ;
if ( V_285 [ V_38 ] & 0x8000ffff ) {
F_5 ( V_3 , V_285 [ V_38 ] ) ;
V_527 = true ;
}
}
F_91 ( & V_2 -> V_7 ) ;
if ( ! V_527 )
break;
if ( F_304 ( V_2 ) &&
V_199 & V_310 ) {
T_2 V_297 = F_176 ( V_2 ) ;
if ( V_297 )
F_177 ( V_2 , V_297 ) ;
}
F_5 ( V_436 , V_199 & ~ V_525 ) ;
V_524 = F_2 ( V_436 ) ;
if ( V_199 & V_519 )
F_92 ( V_2 -> V_132 [ V_205 ] ) ;
F_171 (dev_priv, pipe) {
int V_520 = V_38 ;
if ( F_301 ( V_2 ) )
V_520 = ! V_520 ;
if ( V_285 [ V_38 ] & V_441 &&
F_306 ( V_2 , V_520 , V_38 , V_199 ) )
V_525 &= ~ F_298 ( V_520 ) ;
if ( V_285 [ V_38 ] & V_59 )
V_528 = true ;
if ( V_285 [ V_38 ] & V_295 )
F_158 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_51 )
F_175 ( V_2 ,
V_38 ) ;
}
if ( V_528 || ( V_199 & V_526 ) )
F_197 ( V_2 ) ;
V_99 = V_221 ;
V_199 = V_524 ;
} while ( V_199 & ~ V_525 );
F_181 ( V_2 ) ;
return V_99 ;
}
static void F_308 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
if ( F_304 ( V_2 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
}
F_89 ( V_451 , 0xffff ) ;
F_171 (dev_priv, pipe) {
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( F_49 ( V_38 ) , F_2 ( F_49 ( V_38 ) ) ) ;
}
F_5 ( V_513 , 0xffffffff ) ;
F_5 ( V_514 , 0x0 ) ;
F_5 ( V_436 , F_2 ( V_436 ) ) ;
}
static void F_309 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
F_5 ( V_451 , 0xeffe ) ;
F_171 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( V_513 , 0xffffffff ) ;
F_5 ( V_514 , 0x0 ) ;
F_6 ( V_514 ) ;
}
static int F_310 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_22 ;
T_2 V_529 ;
V_2 -> V_12 = ~ ( V_526 |
V_310 |
V_289 |
V_290 |
V_517 |
V_518 |
V_437 ) ;
V_22 = ~ V_2 -> V_12 ;
V_22 &= ~ ( V_517 |
V_518 ) ;
V_22 |= V_519 ;
if ( F_80 ( V_2 ) )
V_22 |= V_530 ;
F_11 ( & V_2 -> V_7 ) ;
F_54 ( V_2 , V_60 , V_296 ) ;
F_54 ( V_2 , V_60 , V_295 ) ;
F_54 ( V_2 , V_58 , V_295 ) ;
F_12 ( & V_2 -> V_7 ) ;
if ( F_80 ( V_2 ) ) {
V_529 = ~ ( V_531 |
V_532 |
V_533 |
V_516 ) ;
} else {
V_529 = ~ ( V_515 |
V_516 ) ;
}
F_5 ( V_435 , V_529 ) ;
F_5 ( V_513 , V_2 -> V_12 ) ;
F_5 ( V_514 , V_22 ) ;
F_6 ( V_514 ) ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static void F_311 ( struct V_1 * V_2 )
{
T_2 V_534 ;
F_8 ( & V_2 -> V_7 ) ;
V_534 = F_270 ( V_2 , V_535 ) ;
if ( F_80 ( V_2 ) )
V_534 |= V_536 ;
V_534 |= V_537 ;
F_7 ( V_2 ,
V_538 |
V_539 |
V_536 ,
V_534 ) ;
}
static T_9 F_312 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_199 , V_524 ;
T_2 V_285 [ V_286 ] ;
int V_99 = V_218 , V_38 ;
T_2 V_525 =
V_517 |
V_518 ;
if ( ! F_14 ( V_2 ) )
return V_218 ;
F_180 ( V_2 ) ;
V_199 = F_2 ( V_436 ) ;
for (; ; ) {
bool V_527 = ( V_199 & ~ V_525 ) != 0 ;
bool V_528 = false ;
F_88 ( & V_2 -> V_7 ) ;
if ( V_199 & V_437 )
F_119 ( L_48 , V_199 ) ;
F_171 (dev_priv, pipe) {
T_1 V_3 = F_49 ( V_38 ) ;
V_285 [ V_38 ] = F_2 ( V_3 ) ;
if ( V_285 [ V_38 ] & 0x8000ffff ) {
F_5 ( V_3 , V_285 [ V_38 ] ) ;
V_527 = true ;
}
}
F_91 ( & V_2 -> V_7 ) ;
if ( ! V_527 )
break;
V_99 = V_221 ;
if ( V_199 & V_310 ) {
T_2 V_297 = F_176 ( V_2 ) ;
if ( V_297 )
F_177 ( V_2 , V_297 ) ;
}
F_5 ( V_436 , V_199 & ~ V_525 ) ;
V_524 = F_2 ( V_436 ) ;
if ( V_199 & V_519 )
F_92 ( V_2 -> V_132 [ V_205 ] ) ;
if ( V_199 & V_530 )
F_92 ( V_2 -> V_132 [ V_207 ] ) ;
F_171 (dev_priv, pipe) {
if ( V_285 [ V_38 ] & V_293 &&
F_306 ( V_2 , V_38 , V_38 , V_199 ) )
V_525 &= ~ F_298 ( V_38 ) ;
if ( V_285 [ V_38 ] & V_59 )
V_528 = true ;
if ( V_285 [ V_38 ] & V_295 )
F_158 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_51 )
F_175 ( V_2 , V_38 ) ;
}
if ( V_528 || ( V_199 & V_526 ) )
F_197 ( V_2 ) ;
if ( V_285 [ 0 ] & V_296 )
F_145 ( V_2 ) ;
V_199 = V_524 ;
}
F_181 ( V_2 ) ;
return V_99 ;
}
static void F_313 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
if ( ! V_2 )
return;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
F_5 ( V_451 , 0xffffffff ) ;
F_171 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( V_513 , 0xffffffff ) ;
F_5 ( V_514 , 0x0 ) ;
F_171 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) ,
F_2 ( F_49 ( V_38 ) ) & 0x8000ffff ) ;
F_5 ( V_436 , F_2 ( V_436 ) ) ;
}
void F_314 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = & V_2 -> V_31 ;
F_315 ( V_2 ) ;
F_316 ( & V_2 -> V_26 . V_33 , F_104 ) ;
F_316 ( & V_2 -> V_177 . V_178 , F_110 ) ;
if ( F_317 ( V_2 ) )
V_2 -> V_34 = V_277 ;
if ( F_55 ( V_2 ) )
V_2 -> V_25 = V_155 | V_156 ;
else
V_2 -> V_25 = V_540 ;
V_2 -> V_26 . V_29 = 0 ;
if ( F_20 ( V_2 ) -> V_16 <= 7 && ! F_318 ( V_2 ) )
V_2 -> V_26 . V_29 |= V_156 ;
if ( F_20 ( V_2 ) -> V_16 >= 8 )
V_2 -> V_26 . V_29 |= V_541 ;
if ( F_70 ( V_2 ) ) {
V_48 -> V_542 = 0 ;
V_48 -> V_270 -> V_271 = V_543 ;
} else if ( F_80 ( V_2 ) || F_20 ( V_2 ) -> V_16 >= 5 ) {
V_48 -> V_542 = 0xffffffff ;
V_48 -> V_270 -> V_271 = F_67 ;
} else {
V_48 -> V_270 -> V_271 = F_61 ;
V_48 -> V_542 = 0xffffff ;
}
if ( ! F_70 ( V_2 ) )
V_48 -> V_544 = true ;
V_48 -> V_270 -> V_545 = F_83 ;
V_48 -> V_270 -> V_546 = F_76 ;
if ( F_56 ( V_2 ) ) {
V_48 -> V_270 -> V_547 = F_182 ;
V_48 -> V_270 -> V_548 = F_269 ;
V_48 -> V_270 -> V_549 = F_289 ;
V_48 -> V_270 -> V_550 = F_292 ;
V_48 -> V_270 -> V_551 = F_238 ;
V_48 -> V_270 -> V_552 = F_244 ;
V_2 -> V_553 . V_554 = F_311 ;
} else if ( F_55 ( V_2 ) ) {
V_48 -> V_270 -> V_547 = F_179 ;
V_48 -> V_270 -> V_548 = F_259 ;
V_48 -> V_270 -> V_549 = F_285 ;
V_48 -> V_270 -> V_550 = F_291 ;
V_48 -> V_270 -> V_551 = F_238 ;
V_48 -> V_270 -> V_552 = F_244 ;
V_2 -> V_553 . V_554 = F_311 ;
} else if ( F_20 ( V_2 ) -> V_16 >= 8 ) {
V_48 -> V_270 -> V_547 = F_218 ;
V_48 -> V_270 -> V_548 = F_262 ;
V_48 -> V_270 -> V_549 = F_288 ;
V_48 -> V_270 -> V_550 = F_290 ;
V_48 -> V_270 -> V_551 = F_241 ;
V_48 -> V_270 -> V_552 = F_247 ;
if ( F_211 ( V_2 ) )
V_2 -> V_553 . V_554 = F_277 ;
else if ( F_216 ( V_2 ) || F_217 ( V_2 ) )
V_2 -> V_553 . V_554 = F_275 ;
else
V_2 -> V_553 . V_554 = F_276 ;
} else if ( F_215 ( V_2 ) ) {
V_48 -> V_270 -> V_547 = F_208 ;
V_48 -> V_270 -> V_548 = F_257 ;
V_48 -> V_270 -> V_549 = F_281 ;
V_48 -> V_270 -> V_550 = F_293 ;
V_48 -> V_270 -> V_551 = F_239 ;
V_48 -> V_270 -> V_552 = F_245 ;
V_2 -> V_553 . V_554 = F_276 ;
} else {
if ( F_70 ( V_2 ) ) {
V_48 -> V_270 -> V_548 = F_294 ;
V_48 -> V_270 -> V_549 = F_296 ;
V_48 -> V_270 -> V_547 = F_300 ;
V_48 -> V_270 -> V_550 = F_302 ;
V_48 -> V_270 -> V_551 = F_237 ;
V_48 -> V_270 -> V_552 = F_243 ;
} else if ( F_319 ( V_2 ) ) {
V_48 -> V_270 -> V_548 = F_303 ;
V_48 -> V_270 -> V_549 = F_305 ;
V_48 -> V_270 -> V_550 = F_308 ;
V_48 -> V_270 -> V_547 = F_307 ;
V_48 -> V_270 -> V_551 = F_237 ;
V_48 -> V_270 -> V_552 = F_243 ;
} else {
V_48 -> V_270 -> V_548 = F_309 ;
V_48 -> V_270 -> V_549 = F_310 ;
V_48 -> V_270 -> V_550 = F_313 ;
V_48 -> V_270 -> V_547 = F_312 ;
V_48 -> V_270 -> V_551 = F_238 ;
V_48 -> V_270 -> V_552 = F_244 ;
}
if ( F_304 ( V_2 ) )
V_2 -> V_553 . V_554 = F_311 ;
}
}
int F_320 ( struct V_1 * V_2 )
{
V_2 -> V_555 . V_556 = true ;
return F_321 ( & V_2 -> V_31 , V_2 -> V_31 . V_557 -> V_32 ) ;
}
void F_322 ( struct V_1 * V_2 )
{
F_323 ( & V_2 -> V_31 ) ;
F_324 ( V_2 ) ;
V_2 -> V_555 . V_556 = false ;
}
void F_325 ( struct V_1 * V_2 )
{
V_2 -> V_31 . V_270 -> V_550 ( & V_2 -> V_31 ) ;
V_2 -> V_555 . V_556 = false ;
F_39 ( V_2 -> V_31 . V_32 ) ;
}
void F_326 ( struct V_1 * V_2 )
{
V_2 -> V_555 . V_556 = true ;
V_2 -> V_31 . V_270 -> V_548 ( & V_2 -> V_31 ) ;
V_2 -> V_31 . V_270 -> V_549 ( & V_2 -> V_31 ) ;
}
